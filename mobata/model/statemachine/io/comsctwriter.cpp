/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "comsctwriter.hpp"

#include "model/statemachine/simplestateitem.hpp"
#include "model/statemachine/transitionitem.hpp"

#include "model/base/atriggeritem.hpp"
#include "model/base/signaltriggeritem.hpp"
#include "model/base/timeouttriggeritem.hpp"
#include "model/base/signalitem.hpp"

#include <QDomDocument>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

using namespace io::statemachine;
using namespace model::statemachine;
using namespace model::base;


class ComSctWriter::Private
{
  friend class ComSctWriter;

  Private(StateMachineModel* stateMachine);

  bool writeStatemachine(QIODevice* device);
  bool generateDomDocument();
  bool processState(AbstractStateItem *stateItem, QDomElement* regionsElement);
  bool processTransition(TransitionItem *transitionItem);

  QDomElement getStateElement(const QString& stateName);
  QString stateNameCorrection(const QString& stateName);
  QString getTransitionSpecification(TransitionItem *transitionItem);

  bool generateDiagram(QDomElement xmiElement, QUuid statemachineUuid, QUuid regionUuid);
  QDomElement createElement_Type_ID(QDomElement parent, const QString& elementName, const QString& id, const QString& type);

  QDomDocument _doc;
  QString _errorString;
  StateMachineModel* _stateMachine;
  QStringList _specificationList;
};


ComSctWriter::ComSctWriter(StateMachineModel *stateMachine)
  : _d(new Private(stateMachine))
{}

ComSctWriter::~ComSctWriter()
{}

bool ComSctWriter::writeSctXml(QIODevice* device, QString* errorString)
{
  this->_d->_errorString = QStringLiteral("");

  bool ret = this->_d->writeStatemachine(device);

  if(errorString)
    *errorString = this->_d->_errorString;

  return ret;
}

ComSctWriter::Private::Private(StateMachineModel *stateMachine)
  : _stateMachine(stateMachine)
{}

bool ComSctWriter::Private::writeStatemachine(QIODevice *device)
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
  return true;
}

bool ComSctWriter::Private::generateDomDocument()
{
  _doc.clear();
  _specificationList.clear();
  if(!_stateMachine)
  {
    _errorString = "Error: Pointer to State Machine is zero!";
    return false;
  }

  QString xmiURI = "http://www.omg.org/XMI";
  QString xsiURI = "http://www.w3.org/2001/XMLSchema-instance";
  QString notationURI = "http://www.eclipse.org/gmf/runtime/1.0.2/notation";
  QString sgraphURI = "http://www.yakindu.org/sct/sgraph/2.0.0";

  _doc.appendChild(_doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\""));
  QDomElement root = _doc.createElementNS(xmiURI, "xmi:XMI");
  _doc.appendChild(root);

  root.setAttribute("xmi:version", "2.0");
  root.setAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
  root.setAttribute("xmlns:notation", "http://www.eclipse.org/gmf/runtime/1.0.2/notation");
  root.setAttribute("xmlns:sgraph", "http://www.yakindu.org/sct/sgraph/2.0.0");

  QUuid stateChartUuid = QUuid::createUuid();
  QDomElement statechartElement = _doc.createElement("sgraph:Statechart");
  root.appendChild(statechartElement);

  statechartElement.setAttribute("xmi:id", stateChartUuid.toString());
  statechartElement.setAttribute("name", this->_stateMachine->name());

  QDomElement regionsElement = _doc.createElement("regions");
  statechartElement.appendChild(regionsElement);

  QUuid regionsUuid = QUuid::createUuid();
  regionsElement.setAttribute("xmi:id", regionsUuid.toString());
  regionsElement.setAttribute("name", "main region");

  //states
  for(AbstractStateItem* state : this->_stateMachine->states())
  {
    if(!processState(state, &regionsElement)) return false;
  }

  //transitions
  for (TransitionItem* transition : this->_stateMachine->transitions())
  {
    if(!processTransition(transition)) return false;
  }

  QString specification = "internal:\n\n";
  for(QString str : _specificationList)
  {
    specification += "event " + str + "\n";
  }
  statechartElement.setAttribute("specification", specification);

  generateDiagram(root, stateChartUuid, regionsUuid);

  return true;
}

bool ComSctWriter::Private::processState(AbstractStateItem *stateItem, QDomElement *regionsElement)
{
  QDomElement stateElement;
  if(stateItem->stateType() == StateType::Simple)
  {
    stateElement = _doc.createElement("vertices");
    stateElement.setAttribute("xsi:type", "sgraph:State");
    stateElement.setAttribute("xmi:id", stateItem->uuid().toString());
    stateElement.setAttribute("name", stateNameCorrection(stateItem->name()));
    stateElement.setAttribute("incomingTransitions", "");
    regionsElement->appendChild(stateElement);
  }
  else
  {
    _errorString = "Error: not supported StateType : sateType = " + QString::number(stateItem->stateType());
    return false;
  }

  //entry state
  if(stateItem->stateType() == StateType::Simple && stateItem->name()== "init")
  {
    QDomElement entryStateElement = _doc.createElement("vertices");
    entryStateElement.setAttribute("xsi:type", "sgraph:Entry");
    entryStateElement.setAttribute("xmi:id", QUuid::createUuid().toString());
    regionsElement->appendChild(entryStateElement);

    QUuid entryTransitionUuid = QUuid::createUuid();
    QDomElement transitionElement = _doc.createElement("outgoingTransitions");
    entryStateElement.appendChild(transitionElement);
    transitionElement.setAttribute("xmi:id", entryTransitionUuid.toString());
    transitionElement.setAttribute("target", stateItem->uuid().toString());

    stateElement.setAttribute("incomingTransitions", entryTransitionUuid.toString());
  }

  return true;
}

bool ComSctWriter::Private::processTransition(TransitionItem *transitionItem)
{
  QDomElement transitionElement = _doc.createElement("outgoingTransitions");
  transitionElement.setAttribute("xmi:id", transitionItem->uuid().toString());

  QString specification = getTransitionSpecification(transitionItem);
  if(!_specificationList.contains(specification))
  {
    _specificationList << specification;
  }
  transitionElement.setAttribute("specification", specification);

  if(transitionItem->target())
  {
    transitionElement.setAttribute("target", transitionItem->target()->uuid().toString());
    QDomElement targetState = getStateElement(stateNameCorrection(transitionItem->target()->name()));
    if(!targetState.isNull())
    {
      QString inTransition = targetState.attribute("incomingTransitions");
      if(!inTransition.isEmpty()) inTransition += " ";
      inTransition += transitionItem->uuid().toString();
      targetState.setAttribute("incomingTransitions", inTransition);
    }
    else
    {
      _errorString = "Error: no target element for transition : '" + specification + "'";
      return false;
    }
  }
  else
  {
    _errorString = "Error: transition has no target state. transition name : '" + specification + "'";
    return false;
  }

  if(transitionItem->source())
  {
    QDomElement sourceState = getStateElement(stateNameCorrection(transitionItem->source()->name()));
    if(!sourceState.isNull())
    {
      sourceState.appendChild(transitionElement);
    }
    else
    {
      _errorString = "Error: no source element for transition : '" + specification + "'";
      return false;
    }
  }
  else
  {
    _errorString = "Error: transition has no source state. transition name : '" + specification + "'";
    return false;
  }
  return true;
}

QDomElement ComSctWriter::Private::getStateElement(const QString& stateName)
{
  QDomNodeList list = _doc.elementsByTagName("vertices");
  for (int x = 0; x < list.count(); x++)
  {
    QDomElement element = list.at(x).toElement();
    if(!element.isNull() && element.attribute("name") == stateName)
    {
      return element;
    }
  }
  return QDomElement();
}

QString ComSctWriter::Private::stateNameCorrection(const QString &stateName)
{
  bool isNumber;
  stateName.toInt(&isNumber);
  return isNumber ? "s_" + stateName : stateName;
}

QString ComSctWriter::Private::getTransitionSpecification(TransitionItem *transitionItem)
{
  //  QString signalName = QStringLiteral("");
  //  if(SignalItem* signalItem = transitionItem->signal())
  //  {
  //    signalName = signalItem->name();
  //    transitionElement.setAttribute("event", signalName);
  //  }
  //  if(!transitionItem->guard().isEmpty())
  //  {
  //    transitionElement.setAttribute("cond", transitionItem->guard());
  //  }
  //  if(!transitionItem->action().isEmpty())
  //  {
  //    QDomElement sendElement = _doc.createElement("send");
  //    sendElement.setAttribute("event", transitionItem->action());
  //    transitionElement.appendChild(sendElement);
  //  }
  QString specification;

  const ATriggerItem* trigger = transitionItem->trigger();
  if(trigger->triggerType() == ATriggerItem::EventTrigger){
    const SignalTriggerItem* signalTrigger = static_cast<const SignalTriggerItem*>(trigger);
    if(signalTrigger->triggerSignal())
      specification = signalTrigger->triggerSignal()->name();
  }
  else if(trigger->triggerType() == ATriggerItem::TimeoutTrigger){
    const TimeoutTriggerItem* timeoutTrigger = static_cast<const TimeoutTriggerItem*>(trigger);
    specification = QString::number(timeoutTrigger->value(), 'f', 2);
  }

  return specification;
}

bool ComSctWriter::Private::generateDiagram(QDomElement xmiElement, QUuid statemachineUuid, QUuid regionUuid)
{

  QDomElement diagramElement = _doc.createElement("notation:Diagram");
  xmiElement.appendChild(diagramElement);
  diagramElement.setAttribute("type", "org.yakindu.sct.ui.editor.editor.StatechartDiagramEditor");
  diagramElement.setAttribute("xmi:id", QUuid::createUuid().toString());
  diagramElement.setAttribute("element", statemachineUuid.toString());
  diagramElement.setAttribute("measurementUnit", "Pixel");

  //children
  QDomElement childrenShape = createElement_Type_ID(diagramElement, "children", QUuid::createUuid().toString(), "notation:Shape");
  childrenShape.setAttribute("type", "StatechartText");
  childrenShape.setAttribute("fontName", "Verdana");
  childrenShape.setAttribute("lineColor", "16711935");

  QDomElement childrenChildrenDecoration = createElement_Type_ID(childrenShape, "children", QUuid::createUuid().toString(), "notation:DecorationNode");
  childrenChildrenDecoration.setAttribute("type", "StatechartName");
  createElement_Type_ID(childrenChildrenDecoration, "styles", QUuid::createUuid().toString(), "notation:ShapeStyle");
  createElement_Type_ID(childrenChildrenDecoration, "layoutConstraint", QUuid::createUuid().toString(), "notation:Location");

  QDomElement childrenChildrenShape = createElement_Type_ID(childrenShape, "children", QUuid::createUuid().toString(), "notation:Shape");
  childrenChildrenShape.setAttribute("type", "StatechartTextExpression");
  childrenChildrenShape.setAttribute("fontName", "Verdana");
  childrenChildrenShape.setAttribute("lineColor", "16711935");
  createElement_Type_ID(childrenChildrenShape, "layoutConstraint", QUuid::createUuid().toString(), "notation:Bounds");

  QDomElement childrenlayout = createElement_Type_ID(childrenShape, "layoutConstraint", QUuid::createUuid().toString(), "notation:Bounds");
  childrenlayout.setAttribute("x", "10");
  childrenlayout.setAttribute("y", "10");
  childrenlayout.setAttribute("width", "200");
  childrenlayout.setAttribute("height", "400");

  //children
  QDomElement childrenRegion = _doc.createElement("children");
  diagramElement.appendChild(childrenRegion);
  childrenRegion.setAttribute("type", "Region");
  childrenRegion.setAttribute("xmi:id", QUuid::createUuid().toString());
  childrenRegion.setAttribute("element", regionUuid.toString());

  QDomElement childrenRigionChildrenDecoration = createElement_Type_ID(childrenRegion, "children", QUuid::createUuid().toString(), "notation:DecorationNode");
  childrenRigionChildrenDecoration.setAttribute("type", "RegionName");
  createElement_Type_ID(childrenRigionChildrenDecoration, "styles", QUuid::createUuid().toString(), "notation:ShapeStyle");
  createElement_Type_ID(childrenRigionChildrenDecoration, "layoutConstraint", QUuid::createUuid().toString(), "notation:Location");

  QDomElement childrenRigionChildrenShape = createElement_Type_ID(childrenRegion, "children", QUuid::createUuid().toString(), "notation:Shape");
  childrenRigionChildrenShape.setAttribute("type", "RegionCompartment");
  childrenRigionChildrenShape.setAttribute("fontName", "Verdana");
  childrenRigionChildrenShape.setAttribute("lineColor", "4210752");
  createElement_Type_ID(childrenRigionChildrenShape, "layoutConstraint", QUuid::createUuid().toString(), "notation:Bounds");

  QDomElement childrenRigionChildrenStyles = createElement_Type_ID(childrenRegion, "styles", QUuid::createUuid().toString(), "notation:ShapeStyle");
  childrenRigionChildrenStyles.setAttribute("fillColor", "15790320");
  childrenRigionChildrenStyles.setAttribute("fontName", "Verdana");
  childrenRigionChildrenStyles.setAttribute("lineColor", "12632256");

  QDomElement childrenRigionChildrenLayout = createElement_Type_ID(childrenRegion, "layoutConstraint", QUuid::createUuid().toString(), "notation:Bounds");
  childrenRigionChildrenLayout.setAttribute("x", "220");
  childrenRigionChildrenLayout.setAttribute("y", "10");
  childrenRigionChildrenLayout.setAttribute("width", "400");
  childrenRigionChildrenLayout.setAttribute("height", "400");

  return true;
}

QDomElement ComSctWriter::Private::createElement_Type_ID(QDomElement parent, const QString &elementName, const QString &id, const QString &type)
{
  QDomElement newElement = _doc.createElement(elementName);
  parent.appendChild(newElement);
  newElement.setAttribute("xsi:type", type);
  newElement.setAttribute("xmi:id", id);
  return newElement;
}
