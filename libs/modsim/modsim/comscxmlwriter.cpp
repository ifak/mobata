/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "comscxmlwriter.hpp"

#include "mobata/model/statemachine/statemachinemodel.hpp"
#include "mobata/model/statemachine/simplestateitem.hpp"
#include "mobata/model/statemachine/compositestateitem.hpp"
#include "mobata/model/statemachine/concurrentstateitem.hpp"
#include "mobata/model/statemachine/junctionstateitem.hpp"
#include "mobata/model/statemachine/transitionitem.hpp"

#include "mobata/model/base/statements/rootstatementmodel.hpp"
#include "mobata/model/base/functionitem.hpp"
#include "mobata/model/base/attributeitem.hpp"
#include "mobata/model/base/signalitem.hpp"
#include "mobata/model/base/timeouttriggeritem.hpp"
#include "mobata/model/base/signaltriggeritem.hpp"
#include "mobata/model/base/portitem.hpp"

#include "mobata/model/statemachine/regionitem.hpp"
#include "mobata/model/statemachine/abstractstateitem.hpp"


#include <QDomDocument>
#include <QIODevice>
#include <QTextStream>
#include <QDir>
#include <QDebug>

using namespace modsim;
using namespace model::statemachine;
using namespace model::base;
using namespace model::base::statement;
using namespace model::base;
using namespace dslparser::base;

class ComScxmlWriter::Private
{
  friend class ComScxmlWriter;

  Private(const StateMachineModel* stateMachine);

  bool writeStatemachine(QIODevice* device);
  bool generateDomDocument();
  bool processState(const AbstractStateItem *stateItem, QDomElement* scxml);
  bool processTransition(const TransitionItem *transitionItem);
  bool processJunction(const JunctionStateItem *junctionItem, QSharedPointer<QDomElement> root, QList<QSharedPointer<QDomElement> > *list);
  bool processFunction(const FunctionItem *functionItem);
  bool processAttribute(const model::base::AttributeItem* attributeItem, QDomElement *scxml);

  QDomElement getStateElement(const QString& stateName);
  QString stateNameCorrection(const QString& stateName);

  QDomDocument _doc;
  QString _jsBaseText = QString("");
  QString _errorString;
  const StateMachineModel* _stateMachine;
};


ComScxmlWriter::ComScxmlWriter(const StateMachineModel *stateMachine)
  : _d(new Private(stateMachine))
{}

ComScxmlWriter::~ComScxmlWriter()
{
  delete this->_d;
}

bool ComScxmlWriter::generateDomDocument()
{
  return _d->generateDomDocument();
}

bool ComScxmlWriter::writeScxml(QIODevice* device, QString* errorString)
{
  this->_d->_errorString = QStringLiteral("");

  bool ret = this->_d->writeStatemachine(device);

  if(errorString)
    *errorString = this->_d->_errorString;

  return ret;
}

ComScxmlWriter::Private::Private(const StateMachineModel *stateMachine)
  : _stateMachine(stateMachine)
{}

bool ComScxmlWriter::Private::writeStatemachine(QIODevice *device)
{
  if(!device)
  {
    _errorString = "Error QIODevice null pointer!";
    return false;
  }

  bool closeDevice = false;
  const int IndentSize = 2;
  bool ret = this->generateDomDocument();
  if(ret)
  {
    if(!device->isOpen())
    {
      if (!device->open(QIODevice::WriteOnly | QIODevice::Text))
      {
        _errorString = "Error: Can not open QIODevice!";
        return false;
      }
      closeDevice = true;
    }
    QTextStream out(device);
    _doc.save(out, IndentSize);
    if(closeDevice) device->close();
  }
  return ret;
}

bool ComScxmlWriter::Private::generateDomDocument()
{
  _doc.clear();
  if(!_stateMachine)
  {
    _errorString = "Error: Pointer to State Machine is zero!";
    return false;
  }
  _jsBaseText = "";

  QDomElement scxml = _doc.createElement("scxml");
  if(_stateMachine->initState()){
    scxml.setAttribute("initial", _stateMachine->initState()->name());
  }
  scxml.setAttribute("xmlns", "http://www.w3.org/2005/07/scxml");
  scxml.setAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
  scxml.setAttribute("xsi:schemaLocation", "http://www.w3.org/2005/07/scxml https://www.w3.org/2011/04/SCXML/scxml.xsd");
  scxml.setAttribute("datamodel","ecmascript");

  scxml.setAttribute("version", "1.0");
  _doc.appendChild(scxml);

  if(_stateMachine->attributes().size()){
    QDomElement datamodel = _doc.createElement(QString("datamodel"));
    for(auto attributeDecl : _stateMachine->attributes()){
      if(!processAttribute(attributeDecl, & datamodel)) return false;
    }
    scxml.appendChild(datamodel);
  }

  for(auto functionDecl : _stateMachine->functions()){
    if(!processFunction(functionDecl)) return false;
  }

  if(_jsBaseText != QString("")){
    QString dirname("JsFiles");
    QString filename = QString("%0/%1.js").arg(dirname,_stateMachine->name());
    if(!QDir(dirname).exists())
      QDir().mkdir(dirname);
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text) )
    {
      QTextStream stream( &file );
      stream << _jsBaseText;
    }
    file.close();
    QDomElement scriptNode = _doc.createElement(QString("script"));
    scriptNode.setAttribute(QString("src"),filename);
    scxml.appendChild(scriptNode);
  }

  for(const AbstractStateItem* state : this->_stateMachine->states())
  {
    if(!processState(state, &scxml)) return false;
  }

  for (const TransitionItem* transition : this->_stateMachine->transitions())
  {
    if(!processTransition(transition)) return false;
  }

  return true;
}

bool ComScxmlWriter::Private::processState(const AbstractStateItem *stateItem, QDomElement *scxml)
{
  if(stateItem->stateType() == StateType::Simple)
  {
    QDomElement stateElement = _doc.createElement("state");
    stateElement.setAttribute("id", stateNameCorrection(stateItem->name()));

    QString entryActions = QString("{%0}").arg(static_cast<const SimpleStateItem*>(stateItem)->entryAction());
    RootStatementModel entryModel;
    ComBuildStatementModel entryCommand(entryActions,_stateMachine,&entryModel);
    QString errorString("");
    bool result=entryCommand.execute(&errorString);
    if(!result){
      _errorString += errorString;
      return false;
    }
    QDomElement entryElement = entryModel.scxmlElement(_doc);
    entryElement.setTagName(QString("onentry"));
    stateElement.appendChild(entryElement);

    QString exitActions = QString("{%0}").arg(static_cast<const SimpleStateItem*>(stateItem)->exitAction());
    RootStatementModel exitModel;
    ComBuildStatementModel exitCommand(exitActions,_stateMachine,&exitModel);
    errorString = QString("");
    result=exitCommand.execute(&errorString);
    if(!result){
      _errorString += errorString;
      return false;
    }
    QDomElement exitElement = exitModel.scxmlElement(_doc);
    exitElement.setTagName(QString("onexit"));
    stateElement.appendChild(exitElement);

    scxml->appendChild(stateElement);
  }
  else if(stateItem->stateType() == StateType::Junction);
  else if(stateItem->stateType() == StateType::Composite){
    QDomElement stateElement = _doc.createElement("state");
    stateElement.setAttribute("id", stateNameCorrection(stateItem->name()));

    const CompositeStateItem* item = static_cast<const CompositeStateItem*>(stateItem);
    QString entryActions = QString("{%0}").arg(item->entryAction());
    RootStatementModel entryModel;
    ComBuildStatementModel entryCommand(entryActions,_stateMachine,&entryModel);
    QString errorString("");
    bool result=entryCommand.execute(&errorString);
    if(!result){
      _errorString += errorString;
      return false;
    }
    QDomElement entryElement = entryModel.scxmlElement(_doc);
    entryElement.setTagName(QString("onentry"));
    stateElement.appendChild(entryElement);

    QString exitActions = QString("{%0}").arg(item->exitAction());
    RootStatementModel exitModel;
    ComBuildStatementModel exitCommand(exitActions,_stateMachine,&exitModel);
    errorString = QString("");
    result=exitCommand.execute(&errorString);
    if(!result){
      _errorString += errorString;
      return false;
    }
    QDomElement exitElement = exitModel.scxmlElement(_doc);
    exitElement.setTagName(QString("onexit"));
    stateElement.appendChild(exitElement);

    for (auto child : item->states()) {
      if(!processState(child,&stateElement)) return false;
    }

    scxml->appendChild(stateElement);
  }
  else if(stateItem->stateType() == StateType::Concurrent){
    QDomElement stateElement = _doc.createElement("parallel");
    stateElement.setAttribute("id", stateNameCorrection(stateItem->name()));

    const ConcurrentStateItem* item = static_cast<const ConcurrentStateItem*>(stateItem);
    QString entryActions = QString("{%0}").arg(item->entryAction());
    RootStatementModel entryModel;
    ComBuildStatementModel entryCommand(entryActions,_stateMachine,&entryModel);
    QString errorString("");
    bool result=entryCommand.execute(&errorString);
    if(!result){
      _errorString += errorString;
      return false;
    }
    QDomElement entryElement = entryModel.scxmlElement(_doc);
    entryElement.setTagName(QString("onentry"));
    stateElement.appendChild(entryElement);

    QString exitActions = QString("{%0}").arg(item->exitAction());
    RootStatementModel exitModel;
    ComBuildStatementModel exitCommand(exitActions,_stateMachine,&exitModel);
    errorString = QString("");
    result=exitCommand.execute(&errorString);
    if(!result){
      _errorString += errorString;
      return false;
    }
    QDomElement exitElement = exitModel.scxmlElement(_doc);
    exitElement.setTagName(QString("onexit"));
    stateElement.appendChild(exitElement);

    for (const RegionItem* childReg: item->regions()) {
      QDomElement regionElement = _doc.createElement("state");
      stateElement.setAttribute("id", stateNameCorrection(childReg->name()));
      for (auto regionState : childReg->states()){
        if(!processState(regionState,&regionElement)) return false;
      }
      stateElement.appendChild(regionElement);
    }
    scxml->appendChild(stateElement);
  }
  else if(stateItem->stateType() == StateType::Final){
    QDomElement element = _doc.createElement(QString("final"));
    element.setAttribute(QString("id"),stateItem->name());
    scxml->appendChild(element);
  }
  else
  {
    _errorString = "Error: not supported StateType : stateType = " + QString::number(stateItem->stateType());
    return false;
  }
  return true;
}

bool ComScxmlWriter::Private::processTransition(const TransitionItem *transitionItem)
{
  QSharedPointer<QDomElement> transitionElement;
//  QDomElement* transitionElement;
  QDomElement sourceState = getStateElement(stateNameCorrection(transitionItem->source()->name()));

  if(!transitionItem->action().isEmpty())
  {
    QString actions = QString("{%0}").arg(transitionItem->action());
    RootStatementModel statementModel;
    ComBuildStatementModel entryCommand(actions,_stateMachine,&statementModel);
    QString errorString("");
    entryCommand.execute(&errorString);
    if(errorString != QString("")){
      _errorString += errorString;
      return false;
    }
    transitionElement = QSharedPointer<QDomElement>(new QDomElement(statementModel.scxmlElement(_doc)));
//    transitionElement = new QDomElement(statementModel.scxmlElement(_doc));
    transitionElement->setTagName(QString("transition"));
  }
  else{
    transitionElement = QSharedPointer<QDomElement>(new QDomElement(_doc.createElement("transition")));
  }
  QString signalName;
  int portID = -1;
  const ATriggerItem* trigger = transitionItem->trigger();
  if(trigger && trigger->triggerType() == ATriggerItem::EventTrigger)
  {
    const SignalTriggerItem* signalTrigger = static_cast<const SignalTriggerItem*>(trigger);
    if(signalTrigger){
      if(const SignalItem* signalItem = signalTrigger->triggerSignal())
      {
        signalName = signalItem->name();
        transitionElement->setAttribute("event", signalName);
      }
      if(const PortItem* portItem = signalTrigger->port())
      {
        portID = _stateMachine->ports().indexOf(portItem);
      }
      if(signalTrigger->triggerSignal()->parameter("P0rT_GuaRd")){
        _errorString += QString("P0rT_GuaRd is not an allowed name!");
      }
    }
  }
  else if(trigger && trigger->triggerType() == ATriggerItem::TimeoutTrigger)
  {
    const TimeoutTriggerItem* timeoutTrigger = static_cast<const TimeoutTriggerItem*>(trigger);
    Q_ASSERT(timeoutTrigger);

    if(!sourceState.isNull())
    {
      QDomNodeList entryElements = sourceState.elementsByTagName("onentry");
      Q_ASSERT(entryElements.count() == 1);
      QDomNode entryElement = entryElements.at(0);
      //"<send event=\"timesUp\" delay=\"3s\"/>"
      QDomElement sendElement = _doc.createElement(QString("send"));
      QString eventName = QString("eventHa5F1nished%0").arg(transitionItem->name());
      QString idName = QString("delayHa5F1nished%0").arg(transitionItem->name());
      if(_stateMachine->signal(eventName)){
        _errorString += QString("%0 is not an allowed name!").arg(eventName);
      }
      sendElement.setAttribute(QString("event"),eventName);
      sendElement.setAttribute(QString("id"),idName);
      sendElement.setAttribute(QString("delay"),QString("%0ms").arg(QString::number(timeoutTrigger->value())));
      entryElement.appendChild(sendElement);

      //<cancel sendid="timesUp"/>
      QDomNodeList exitElements = sourceState.elementsByTagName("onexit");
      Q_ASSERT(exitElements.count() == 1);
      QDomNode exitElement = exitElements.at(0);
      QDomElement cancelElement = _doc.createElement(QString("cancel"));
      cancelElement.setAttribute(QString("sendid"),idName);
      exitElement.appendChild(cancelElement);

      //      <log label="log1" expr="exec"/>
//      QDomElement logElement = _doc.createElement(QString("log"));
//      logElement.setAttribute(QString("label"),QString("log_%0").arg(transitionItem->name()));
//      logElement.setAttribute(QString("expr"),QString("'Logged %0 expression'").arg(eventName));
//      exitElement.appendChild(logElement);

      transitionElement->setAttribute("event", eventName);
    }
  }

  QString guard("");
  if(!transitionItem->guard().isEmpty())
  {
    guard = transitionItem->guard();
    guard.replace(QString("msg."),QString("_event.data."));
    if(portID>-1){
      guard = ((guard == QString("")) ? QString("") : QString("%0 && ").arg(guard)) +
          QString("_event.data.P0rT_GuaRd === %0").arg(portID);
    }
    transitionElement->setAttribute("cond", guard);
  }

  QList<QSharedPointer<QDomElement>> transitionList;
  if(transitionItem->target())
  {
    if(transitionItem->target()->stateType() == StateType::Junction){
      if(!processJunction(static_cast<const JunctionStateItem*>(transitionItem->target())
                          ,transitionElement,&transitionList)){
        return false;
      }
    }
    else{
      transitionElement->setAttribute("target", stateNameCorrection(transitionItem->target()->name()));
      transitionList.append(transitionElement);
    }
  }
  else
  {
    _errorString = "Error: transition has no target state. transition name : '" + signalName + "'";
//    for(auto item : transitionList){
//      if(item != transitionElement) delete item;
//    }
//    delete transitionElement;
    return false;
  }

  if(!sourceState.isNull())
  {
    for(QSharedPointer<QDomElement> altTransitionItem : transitionList){
      sourceState.appendChild(*altTransitionItem);
    }
  }
  else
  {
//    for(auto item : transitionList){
//      if(item != transitionElement) delete item;
//    }
//    delete transitionElement;
    _errorString = "Error: transition has no source state. transition name : '" + signalName + "'";
    return false;
  }

  return true;
}

bool ComScxmlWriter::Private::processJunction(const JunctionStateItem *junctionItem, QSharedPointer<QDomElement> root, QList<QSharedPointer<QDomElement> >* list)
{
  QList<const TransitionItem*> transitions = junctionItem->transitions();
  QString elseGuard("");
  QString formerCond = root->attribute(QString("cond"));

  // first go through all branches other than <else> and collect the negated conditions (to create else condition)
  QList<QSharedPointer<QDomElement>> transList;
  int elsePos = -1;
  for(const TransitionItem* transition : transitions){
    QSharedPointer<QDomElement> altTrans = QSharedPointer<QDomElement>(new QDomElement(root->cloneNode().toElement()));
    if(transition->guard() == QString("else")){
      elsePos = transList.size();
      altTrans.clear();
    }
    else{
      if(elseGuard == QString("") && transition->guard() != QString("")){
        elseGuard = QString("!(%0)").arg(transition->guard());
      }
      else if(transition->guard() != QString("")){
        elseGuard = QString("%0 && !(%1)").arg(elseGuard,transition->guard());
      }
      altTrans->setAttribute("cond", transition->guard());
      transList.append(altTrans);
    }
  }

  //clone root node and add else condition!
  auto altTrans = QSharedPointer<QDomElement>(new QDomElement(root->cloneNode().toElement()));
  altTrans->setAttribute("cond", QString("%0").arg(elseGuard));
  if(elsePos>-1) transList.insert(elsePos,altTrans);

  int counter = 0;
  for(const TransitionItem* transition : transitions){
    auto curTrans = transList.at(counter);
    QString curCond = curTrans->attribute(QString("cond"));
    //add condition of rootnode to branch
    if(formerCond != QString(""))
      curTrans->setAttribute("cond", QString("(%0) && (%1)").arg(formerCond,curCond));

    //add actions
    if(!transition->action().isEmpty())
    {
      QString entryActions = QString("{%0}").arg(transition->action());
      RootStatementModel entryModel;
      ComBuildStatementModel entryCommand(entryActions,_stateMachine,&entryModel);
      QString errorString("");
      entryCommand.execute(&errorString);
      if(errorString != QString("")){
//        for(auto item : transList){
//          if(item != altTrans) delete item;
//        }
//        delete  altTrans;
        _errorString += errorString;
        return false;
      }
      QDomElement entryElement = entryModel.scxmlElement(_doc);
      uint sz = uint(entryElement.childNodes().count());
      for(uint i(0); i < sz;++i){
        auto child = entryElement.childNodes().at(0); //den parent eines Kindes wechseln (was appendChild tut) löscht ihn aus der childNode Liste des vorherigen parents, desshalb immer 0 nich i)
        curTrans->appendChild(child);
      }
    }

    //handle target of transition
    QList<QSharedPointer<QDomElement>> transitionList;
    if(transition->target())
    {
      //call recursivly if target is junction again
      if(transition->target()->stateType() == StateType::Junction){
        if(!processJunction(static_cast<const JunctionStateItem*>(transition->target()),curTrans,&transitionList)){
//          for(auto item : transList){
//            if(item != altTrans) delete item;
//          }
//          delete  altTrans;
          return false;
        }
        for(auto transitionbranch : transitionList){
          list->append(transitionbranch);
        }
      }
      //set target and exit recursion!
      else{
        curTrans->setAttribute("target", stateNameCorrection(transition->target()->name()));
        list->append(curTrans);
      }
    }
    else
    {
      _errorString = "Error: transition has no target state. transition name : '" + root->attribute(QString("event")) + "'";
//      for(auto item : transList){
//        if(item != altTrans) delete item;
//      }
//      delete  altTrans;
      return false;
    }
    ++counter;
  }
  return true;
}

bool ComScxmlWriter::Private::processFunction(const FunctionItem *functionItem)
{
  QString params("");
  if(functionItem->params().size()>0) params.append(functionItem->params().first()->name());
  for(int i(1); i<functionItem->params().size(); i++){
    const model::base::ParamItem* item = functionItem->params().at(i);
    params.append(QString(", %0").arg(item->name()));
  }
  QString body = functionItem->statementBody();
  _jsBaseText += QString("function %0(%1){\n%2\n}\n").arg(functionItem->name(),params,body.replace(QString("=="),QString("===")));
  return true;
}

bool ComScxmlWriter::Private::processAttribute(const model::base::AttributeItem *attributeItem, QDomElement *scxml)
{
  QDomElement attrNode = _doc.createElement(QString("data"));
  attrNode.setAttribute(QString("id"),attributeItem->name());
  attrNode.setAttribute(QString("expr"),attributeItem->initValue());
  scxml->appendChild(attrNode);
  return true;
}

QDomElement ComScxmlWriter::Private::getStateElement(const QString& stateName)
{
  QDomNodeList list = _doc.elementsByTagName("state");
  for (auto x = 0; x < list.count(); x++)
  {
    QDomElement element = list.at(x).toElement();
    if(!element.isNull() && element.attribute("id") == stateName)
    {
      return element;
    }
  }
  list = _doc.elementsByTagName("parallel");
  for (int x = 0; x < list.count(); x++)
  {
    QDomElement element = list.at(x).toElement();
    if(!element.isNull() && element.attribute("id") == stateName)
    {
      return element;
    }
  }
  return QDomElement();
}

QString ComScxmlWriter::Private::stateNameCorrection(const QString &stateName)
{
  bool isNumber;
  QString realStateName = stateName.split(QString(".")).last();
  realStateName.toInt(&isNumber);
  return isNumber ? "s_" + realStateName : realStateName;
}
