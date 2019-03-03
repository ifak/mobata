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

#include "irdldeclmodellistener.hpp"
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/propattributes.hpp>
#include <dslparser/common/combuildbasemodel.hpp>
#include <dslparser/irdldecl/combuildirdldeclmodel.hpp>

#include <mobata/model/irdl/requirementsmodel.hpp>
#include <mobata/model/irdl/requirementitem.hpp>
#include <mobata/model/irdl/reqactorcomponentitem.hpp>
#include <mobata/model/irdl/reqcomponentitem.hpp>
#include <mobata/model/msc/msccomponentitem.hpp>
#include <mobata/model/msc/mscmessageitem.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>
#include <mobata/model/msc/mscsequence.hpp>
#include <mobata/model/base/propparams.hpp>
#include <mobata/model/base/modelitem.hpp>
#include <mobata/model/msc/msctimeritem.hpp>

#include "combuildirdldeclmodel.hpp"
#include "irdldeclmodellistener.hpp"

#include <QStack>
#include <QDebug>

namespace reg = model::irdl;
using namespace antlr4;

namespace dslparser {
namespace irdl {

using common::addKeywordLocation;

class IrdlDeclModelListener::Private
{
  friend class IrdlDeclModelListener;

  ///parse data////
  //QScopedPointer<reg::TransitionItem> _currentTransition;
  int                                    _errorAtPos;
  model::base::ModelItem*                _currentPathItem;
  reg::ReqActorComponentItem*            _curActor = nullptr;
  reg::ReqComponentItem*                 _curComp = nullptr;
  reg::RequirementItem*                  _regItem;
  model::base::ModelItem *               _currentSignal = nullptr;
  QStack<model::msc::MscFragmentItem*>   _curDurFrag;
  QStack<model::msc::MscSequence*>       _seqStack;
  QStack<model::msc::MscFragmentItem*>   _altStack;
  QHash<QString,model::msc::MscComponentItem*> _IrdlCompItems;
  QHash<QString,QList<model::msc::MscComponentItem*>> _importedComponents;
  ImportModelItem                        _importItems;
  ImportModel                            _importModels;
  QString                                _praefix;

  Private(const QString& prefix)
    : //_currentTransition(nullptr),
      _currentPathItem(nullptr),
      _importItems(),
      _praefix(prefix)
  {}
};

IrdlDeclModelListener::IrdlDeclModelListener(reg::RequirementsModel* irdlDeclModel,
                                             DslErrorList* irdlErrors,
                                             const QString& prefix,
                                             TokenTextLocations* keywordTextLocations,
                                             ModelTextLocations* modelTextLocations)
  : common::CommonModelListener<IrdlCommonDeclBaseListener, IrdlCommonDeclParser, reg::RequirementsModel>(irdlDeclModel,
                                                                                                          irdlErrors,
                                                                                                          keywordTextLocations,
                                                                                                          modelTextLocations),
    _d(new Private(prefix))
{
  Q_ASSERT(irdlDeclModel);
  //this->_d->_propStatesStack.push_front(irdlDeclModel);
}

IrdlDeclModelListener::~IrdlDeclModelListener()
{
  delete this->_d;
}

QPair<model::base::ModelItem *, int> IrdlDeclModelListener::currentPathItem()
{
  return QPair<model::base::ModelItem*,int>(this->_d->_currentPathItem,_d->_errorAtPos);
}

model::base::ModelItem *IrdlDeclModelListener::currentSignalItem()
{
  return this->_d->_currentSignal;
}

const QHash<QString, model::msc::MscComponentItem *> &IrdlDeclModelListener::requirementCompItems()
{
  return this->_d->_IrdlCompItems;
}

const ImportModelItem &IrdlDeclModelListener::importItems()
{
  return this->_d->_importItems;
}

const ImportModel &IrdlDeclModelListener::importModels()
{
  return this->_d->_importModels;
}

void IrdlDeclModelListener::enterIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext* ctx)
{
  this->_listenerStates.push(IrdlCommonDeclState);

  _d->_regItem = _model->addRequirement(QString(""));
  _d->_seqStack.push_front(_d->_regItem);

  typedef  tree::TerminalNode* (IrdlCommonDeclParser::IrdlDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::IrdlDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::IrdlDeclContext::RequirementID, this->_keywordTextLocations, Requirement);

}

void IrdlDeclModelListener::exitIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext* ctx)
{
  this->_listenerStates.pop();
  _d->_seqStack.pop_front();
  if(!ctx || ctx->exception) return;
  this->_modelTextLocations->insert(this->_model->invisibleRootItem()->index(),
                                    TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                      ctx->getStop()->getStopIndex(),
                                                      Requirement));
  return;
}

void IrdlDeclModelListener::enterAliasDef(IrdlCommonDeclParser::AliasDefContext *ctx)
{
  Q_UNUSED(ctx);
}

void IrdlDeclModelListener::exitAliasDef(IrdlCommonDeclParser::AliasDefContext *ctx)
{
  if(ctx->exception && ctx->componentIdPath())
    return;
  if(auto comp = getComponentFromPath(ctx->componentIdPath())){
    _d->_IrdlCompItems.insert(QString::fromStdString(ctx->contextID()->getText()),static_cast<model::msc::MscComponentItem*>(comp->parent()));
  }

  typedef  tree::TerminalNode* (IrdlCommonDeclParser::AliasDefContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::AliasDefContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::AliasDefContext::UseID, this->_keywordTextLocations, Use);
}

void IrdlDeclModelListener::enterActorDecl(IrdlCommonDeclParser::ActorDeclContext *ctx)
{
  if(!ctx || ctx->exception) return;

  typedef  tree::TerminalNode* (IrdlCommonDeclParser::ActorDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::ActorDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::ActorDeclContext::ActorID, this->_keywordTextLocations, Actor);

  QString errorString("");
  _d->_curActor = _model->addComponent<model::irdl::ReqActorComponentItem>(QString(""),&errorString);
  if(errorString != QString("")){
    appendDslError(ctx->getStart(),
                   errorString);
    return;
  }
  _listenerStates.push(ActorDeclState);
  setAttributesModel(_d->_curActor);
}

void IrdlDeclModelListener::exitActorDecl(IrdlCommonDeclParser::ActorDeclContext *ctx)
{
  Q_UNUSED(ctx);
  _listenerStates.pop();
  setAttributesModel(_model);
  _d->_curActor = nullptr;
}

void IrdlDeclModelListener::enterComponentDecl(IrdlCommonDeclParser::ComponentDeclContext *ctx)
{
  if(!ctx || ctx->exception) return;

  typedef  tree::TerminalNode* (IrdlCommonDeclParser::ComponentDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::ComponentDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::ComponentDeclContext::ComponentID, this->_keywordTextLocations, Component);

  QString errorString("");
  _d->_curComp = _model->addComponent<model::irdl::ReqComponentItem>(QString(""),&errorString);
  if(errorString != QString("")){
    appendDslError(ctx->getStart(),
                   errorString);
    return;
  }
  _listenerStates.push(ComponentDeclState);
  setAttributesModel(_d->_curComp);
}

void IrdlDeclModelListener::exitComponentDecl(IrdlCommonDeclParser::ComponentDeclContext *ctx)
{
  Q_UNUSED(ctx);
  _listenerStates.pop();
  setAttributesModel(_model);
  _d->_curComp = nullptr;
}

void IrdlDeclModelListener::enterPortDecl(IrdlCommonDeclParser::PortDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::PortDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::PortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::PortDeclContext::PortID, this->_keywordTextLocations, Port);
}

void IrdlDeclModelListener::exitPortDecl(IrdlCommonDeclParser::PortDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  for(IrdlCommonDeclParser::ContextIDContext* currContextID : ctx->contextID())
  {
    Token* portToken=currContextID->getStart();
    Q_ASSERT(portToken);

    QString portName=QString::fromStdString(currContextID->getText());
    QString errorString;
    reg::PortItem* newPort = nullptr;
    if(_d->_curComp)
      newPort = _d->_curComp->addPort(portName, &errorString);
   else if(_d->_curActor)
      newPort = _d->_curActor->addPort(portName, &errorString);
    if(!newPort)
    {
      if(this->_errors)
        this->_errors->append(DslError(errorString,
                                       portToken->getLine(),
                                       portToken->getCharPositionInLine()));
    }
    else
    {
      this->_modelTextLocations->insert(newPort->index(),
                                        TokenTextLocation(portToken->getStartIndex(),
                                                          portToken->getStopIndex(),
                                                          Port));
    }
  }

  return;
}

void IrdlDeclModelListener::enterNameDecl(IrdlCommonDeclParser::NameDeclContext* ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::NameDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::NameDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void IrdlDeclModelListener::exitNameDecl(IrdlCommonDeclParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString name=QString::fromStdString(ctx->contextID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==IrdlCommonDeclState)
  {
    Q_ASSERT(this->_d->_regItem);
    this->_d->_regItem->setName(name);
    this->_d->_regItem->setText(this->_d->_regItem->toString());
  }
  else if(currListenerState==ActorDeclState)
  {
    Q_ASSERT(this->_d->_curActor);
    this->_d->_curActor->setName(name);
    this->_d->_curActor->setText(this->_d->_curActor->toString());
  }
  else if(currListenerState==ComponentDeclState)
  {
    Q_ASSERT(this->_d->_curComp);
    this->_d->_curComp->setName(name);
    this->_d->_curComp->setText(this->_d->_curComp->toString());
  }

  return;
}

void IrdlDeclModelListener::enterDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::DescriptionDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::DescriptionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::DescriptionDeclContext::DescriptionID, this->_keywordTextLocations, Description);
}

void IrdlDeclModelListener::exitDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->STRING());

  QString descript=QString::fromStdString(ctx->STRING()->getText()).remove(QString("\""));

  int currListenerState = this->currentListenerState();
  if(currListenerState==IrdlCommonDeclState)
  {
    Q_ASSERT(this->_d->_regItem);
    this->_d->_regItem->setDescription(descript);
  }
  else if(currListenerState==ActorDeclState)
  {
    Q_ASSERT(this->_d->_curActor);
    this->_d->_curActor->setDescription(descript);
  }
  else if(currListenerState==ComponentDeclState)
  {
    Q_ASSERT(this->_d->_curComp);
    this->_d->_curComp->setDescription(descript);
  }

  return;
}

void IrdlDeclModelListener::enterStateDecl(IrdlCommonDeclParser::StateDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::StateDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::StateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::StateDeclContext::StateID, this->_keywordTextLocations, State);
}

void IrdlDeclModelListener::exitStateDecl(IrdlCommonDeclParser::StateDeclContext *ctx)
{
  if(!ctx) return;
  auto lifelineList = ctx->lifelineList();
  while(lifelineList){
    if(lifelineList->componentIdPath()){
      if(const model::base::PortItem* item = getComponentFromPath(lifelineList->componentIdPath())){
        _d->_seqStack.front()->addStatement(static_cast<const model::msc::MscComponentItem*>(item->owner()),QString::fromStdString(ctx->contextID()->getText()));
      }
      else{
        appendDslError(ctx->getStart(),
                       QString("No Component with name \"")
                       + QString::fromStdString(lifelineList->componentIdPath()->getText())
                       + QString("\" found!"));
        return;
      }
    }
    else if(lifelineList->AllID())
    {
      for(auto comp : _model->components())
      {
        _d->_seqStack.front()->addStatement(static_cast<model::msc::MscComponentItem*>(comp),QString::fromStdString(ctx->contextID()->getText()));
      }
      for (auto baseModel : this->_model->importedModels())
      {
        if(model::irdl::RequirementsModel* reqModel = dynamic_cast<model::irdl::RequirementsModel*>(baseModel))
        {
          for(auto component : reqModel->components())
          {
            if(auto modelItem = dynamic_cast<model::base::ModelItem*>(component))
            {
              this->_d->_currentPathItem = modelItem;
              break;
            }
          }
        }
      }
    }
    if(lifelineList->lifelineListOptional())
      lifelineList = lifelineList->lifelineListOptional()->lifelineList();
    else {
      break;
    }
  }
}

void IrdlDeclModelListener::enterMessageDecl(IrdlCommonDeclParser::MessageDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::MessageDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::MessageDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::MessageDeclContext::MessageID, this->_keywordTextLocations, Message);
}

void IrdlDeclModelListener::exitMessageDecl(IrdlCommonDeclParser::MessageDeclContext *ctx)
{
  if(!ctx || ctx->componentIdPath().size() != 2 || ctx->messageSignal()) return;
  if(auto source = getComponentFromPath(ctx->componentIdPath().at(0))){
    if(auto target = getComponentFromPath(ctx->componentIdPath().at(1))){
      if(auto signal = getSignalFromPath(ctx->messageSignal()->signalIdPath())){
        auto msg = _d->_seqStack.front()->addMessage(source,target,
                                                     QString::fromStdString(ctx->messageSignal()->signalIdPath()->contextID().back()->getText()));
        msg->setSignal(signal);
        QListIterator<const model::msc::ParamItem*> paramIt(signal->params());
        auto bdy = ctx->messageSignal()->messageSignalBody();
        while(bdy){
          auto param = paramIt.next();
          QVariant val;
          bool test = false;
          if(auto asCtx = bdy->literalValue()){
            if(asCtx->TrueID() || asCtx->FalseID()){
              val = (asCtx->FalseID() == nullptr);
            }
            else if(asCtx->REAL()){
              val = (QString::fromStdString(asCtx->REAL()->getText()).toDouble());
            }
            else if(asCtx->INT()){
              val = (QString::fromStdString(asCtx->INT()->getText()).toInt());
            }
            else if(asCtx->STRING()){
              val = (QString::fromStdString(asCtx->STRING()->getText()));
            }
            else{
              test = true;
            }
          }
          else if (bdy->signalParamName()) {
            //TODO: no idea
          }
          else if (bdy->attributeIdPath()) {
            //TODO: no idea
          }
          if(!test && param) msg->addParamValue(param,val);
          if(bdy->messageSignalBodyOptional())
            bdy = bdy->messageSignalBodyOptional()->messageSignalBody();
          else break;
        }
      }
      else{
        appendDslError(ctx->getStart(),
                       QString("No Signal with name \"")
                       + QString::fromStdString(ctx->messageSignal()->signalIdPath()->getText())
                       + QString("\" found!"));
        return;
      }
    }
    else if(ctx->componentIdPath().size() >1){
      appendDslError(ctx->getStart(),
                     QString("No Component with name \"")
                     + QString::fromStdString(ctx->componentIdPath().at(1)->getText())
                     + QString("\" found!"));
      return;
    }
    else{
      appendDslError(ctx->getStart(),
                     QString("Wrong Syntax!"));
      return;
    }
  }
  else{
    appendDslError(ctx->getStart(),
                   QString("No Component with name \"")
                   + QString::fromStdString(ctx->componentIdPath().at(0)->getText())
                   + QString("\" found!"));
    return;
  }
}

void IrdlDeclModelListener::enterTimerDecl(IrdlCommonDeclParser::TimerDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::TimerDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::TimerDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::TimerDeclContext::TimerID, this->_keywordTextLocations, Timer);
}

void IrdlDeclModelListener::exitTimerDecl(IrdlCommonDeclParser::TimerDeclContext *ctx)
{
  if(!ctx) return;
  if(auto lifeLine = getComponentFromPath(ctx->componentIdPath())){
    QString errorString("");
    auto timer = _d->_seqStack.front()->addTimer(static_cast<const model::msc::MscComponentItem*>(lifeLine->owner()),QString::fromStdString(ctx->contextID()->getText()),&errorString);
    if(errorString != QString("")){
      appendDslError(ctx->getStart(),
                     errorString);
      return;
    }
    else{
      QString value = "";
      if(ctx->REAL()) value = QString::fromStdString(ctx->REAL()->getText());
      else if(ctx->INT()) value = QString::fromStdString(ctx->INT()->getText());
      double val = value.toDouble();
      if(ctx->SekID()) val *= 1000;
      timer->setValue(val);
    }
  }
}

void IrdlDeclModelListener::enterCheckDeclBody(IrdlCommonDeclParser::CheckDeclBodyContext *ctx)
{
  IrdlCommonDeclParser::CheckDeclContext* parentCtx = (IrdlCommonDeclParser::CheckDeclContext*)ctx->parent;
  if(parentCtx && getSignalFromPath(parentCtx->signalIdPath())){
    if(model::msc::SignalItem* signal = dynamic_cast<model::msc::SignalItem*>(_d->_currentPathItem)){
      _d->_currentSignal = signal;
    }
  }
}

void IrdlDeclModelListener::exitCheckDecl(IrdlCommonDeclParser::CheckDeclContext *ctx)
{
  if(!ctx                  || ctx->exception ||
     !ctx->checkDeclBody() || ctx->checkDeclBody()->exception) return;
  if(const model::base::PortItem* source = getComponentFromPath(ctx->componentIdPath().at(0))){
    if(const model::base::PortItem*  target = getComponentFromPath(ctx->componentIdPath().at(1))){
      if(const model::base::SignalItem* signal = getSignalFromPath(ctx->signalIdPath())){
        model::msc::MscCheckMessageItem* check = new model::msc::MscCheckMessageItem(source,target);
        check->setSignal(signal);
        check->setGuard(QString::fromStdString(
                          ctx->getStart()->getInputStream()->getText(
                            misc::Interval(ctx->checkDeclBody()->LBRACKET()->getSymbol()->getStartIndex()+1,ctx->checkDeclBody()->RBRACKET()->getSymbol()->getStopIndex()-1))));
        if(auto timeCtx = ctx->checkDeclBody()->timeOutDecl()){
          QString value = "";
          if(timeCtx->REAL()) value = QString::fromStdString(timeCtx->REAL()->getText());
          else if(timeCtx->INT()) value = QString::fromStdString(timeCtx->INT()->getText());
          int val = value.toInt();
          if(timeCtx->SekID()) val *= 1000;
          check->setTimeout(val);
        }
        _d->_seqStack.front()->addMessage(check);
        this->_modelTextLocations->insert(check->index(),
                                          TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                            ctx->getStop()->getStopIndex(),
                                                            Check));

        _d->_currentSignal = nullptr;


        typedef  tree::TerminalNode* (IrdlCommonDeclParser::CheckDeclContext::*KeywordFunction)();

        addKeywordLocation<IrdlCommonDeclParser::CheckDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &IrdlCommonDeclParser::CheckDeclContext::CheckID, this->_keywordTextLocations, Check);
      }
      else{
        appendDslError(ctx->getStart(),
                       QString("No Signal with name \"")
                       + QString::fromStdString(ctx->signalIdPath()->getText())
                       + QString("\" found!"));

        return;
      }
    }
    else{
      appendDslError(ctx->getStart(),
                     QString("No Component with name \"")
                     + QString::fromStdString(ctx->componentIdPath().at(1)->getText())
                     + QString("\" found!"));
      return;
    }
  }
  else{
    appendDslError(ctx->getStart(),
                   QString("No Component with name \"")
                   + QString::fromStdString(ctx->componentIdPath().at(0)->getText())
                   + QString("\" found!"));
    return;
  }
}

void IrdlDeclModelListener::enterAltDecl(IrdlCommonDeclParser::AltDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::AltDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::AltDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::AltDeclContext::AltID, this->_keywordTextLocations, Alt);

  model::msc::MscFragmentItem * fragItem =
      new model::msc::MscFragmentItem(model::msc::FragmentType::AlternativeFragment);
  _d->_altStack.push_front(fragItem);
  _d->_seqStack.front()->addFragment(fragItem);
}

void IrdlDeclModelListener::exitAltDecl(IrdlCommonDeclParser::AltDeclContext *ctx)
{
  Q_UNUSED(ctx);
  _d->_altStack.pop_front();
}

void IrdlDeclModelListener::enterAltBody(IrdlCommonDeclParser::AltBodyContext *ctx)
{
  Q_UNUSED(ctx);
  auto fragItem = _d->_altStack.front();
  _d->_seqStack.push_front(fragItem->addRegion(QString("")));
}

void IrdlDeclModelListener::exitAltBody(IrdlCommonDeclParser::AltBodyContext *ctx)
{
  if(!ctx)return;
  auto fragItem = static_cast<model::msc::MscFragmentRegionItem*>(_d->_seqStack.front());
  fragItem->setCondition(QString::fromStdString(ctx->expression()->getText()));
  _d->_seqStack.pop_front();
}

void IrdlDeclModelListener::enterDurationDecl(IrdlCommonDeclParser::DurationDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::DurationDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::DurationDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::DurationDeclContext::DurationID, this->_keywordTextLocations, Duration);

  model::msc::MscFragmentItem * fragItem = new model::msc::MscFragmentItem(model::msc::DurationFragment);
  _d->_seqStack.front()->addFragment(fragItem);
  model::msc::MscFragmentRegionItem* reg = fragItem->addRegion(QString("DurationRegion"));
  fragItem->setText("Duration");
  _d->_seqStack.push_front(reg);
  _d->_curDurFrag.push_front(fragItem);
}

void IrdlDeclModelListener::exitDurationDecl(IrdlCommonDeclParser::DurationDeclContext *ctx)
{
  if(!ctx || ctx->exception) return;
  QString value = "";
  if(ctx->REAL()) value = QString::fromStdString(ctx->REAL()->getText());
  else if(ctx->INT()) value = QString::fromStdString(ctx->INT()->getText());
  int val = value.toInt();
  if(ctx->SekID()) val *= 1000;
  model::msc::MscFragmentItem * fragitem = static_cast<model::msc::MscFragmentItem *>(_d->_curDurFrag.front());
  _d->_seqStack.pop_front();
  _d->_curDurFrag.pop_front();
  fragitem->setDuration(val);
  fragitem->regions().front()->setCondition(QString("Duration = %1ms").arg(val));
}

void IrdlDeclModelListener::enterImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (IrdlCommonDeclParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);
}

void IrdlDeclModelListener::exitImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext *ctx)
{
  if(ctx->exception || !ctx->importFileBody())
    return;
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);

  QString path = QString::fromStdString(ctx->importFileBody()->getText());
  path = _d->_praefix + path;
  QFile file(path);
  if(!file.open(QFile::ReadOnly)){
    appendDslError(ctx->getStart(),
                   QString("Import File couldn't be opened"));
    return;
  }
  QString docText(file.readAll());
  file.close();

  if(path.endsWith(QString(".requirement")))
  {
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QString("this");
      //            name = path;
    }

    model::irdl::RequirementsModel* irdlModel = new model::irdl::RequirementsModel(/*,_model*/);
    dslparser::irdl::ComBuildIrdlDeclModel command(docText, irdlModel,_d->_praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      this->_d->_importModels.insert(name,irdlModel);
      //this->_model->addImportItem(irdlModel);
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QString("Import File contains errors..."));
      return;
    }
  }
  else if(path.endsWith(QString(".decl"))){
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QString("this");
      //            name = path;
    }

    model::base::BaseModel* baseModel = new model::base::BaseModel(/*,_model*/);
    dslparser::common::ComBuildBaseModel command(docText, baseModel);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      this->_model->removeImportedModel(name);
      if(!this->_model->addImportedModel(name,baseModel,&errorString))
      {
        if(this->_errors){
          this->_errors->append(command.errors());
        }
        return;
      }
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QString("Import File contains errors..."));
      return;
    }
  }
  else if(path.endsWith(QString(".irdldecl"))){
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QString("this");
      //            name = path;
    }

    model::irdl::RequirementsModel* baseModel = new model::irdl::RequirementsModel(/*,_model*/);
    dslparser::irdl::ComBuildIrdlDeclModel command(docText, baseModel);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      this->_d->_importModels.insert(name,baseModel);
      this->_model->removeImportedModel(name);
      if(!this->_model->addImportedModel(name,baseModel,&errorString))
      {
        appendDslError(ctx->getStart(),
                       errorString);
        return;
      }
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QString("Import File contains errors..."));
      return;
    }
  }
}

void IrdlDeclModelListener::enterRequirementBody(IrdlCommonDeclParser::RequirementBodyContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlCommonDeclParser::RequirementBodyContext::*KeywordFunction)();

  addKeywordLocation<IrdlCommonDeclParser::RequirementBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlCommonDeclParser::RequirementBodyContext::DeclarationID, this->_keywordTextLocations, Declaration);
}

void IrdlDeclModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);

  //  qDebug()<<"IrdlDeclModelListener::visitErrorNode() "
  //            "state: "<<this->_d->_listenerStates.top()
  //         <<"error node: "<<node->toString().c_str();

  return;
}

model::msc::MscComponentItem *IrdlDeclModelListener::getAlias(QString name)
{
  if(this->_d->_IrdlCompItems.contains(name)){
    return this->_d->_IrdlCompItems.value(name);
  }
  return nullptr;
}

const model::base::PortItem* IrdlDeclModelListener::getComponentFromPath(IrdlCommonDeclParser::ComponentIdPathContext* compPath)
{
  if(!compPath || compPath->exception)
    return nullptr;
  auto path = compPath->contextID();
  uint8_t sz = path.size();
  QString importModelStr;
  QString compStr;
  const model::base::PortItem* res = nullptr;

  switch (sz) {
  case 3:
    importModelStr = QString::fromStdString(path.at(0)->getText());
    if(const model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      compStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::ComponentItem* comp = reqModel->component(compStr)){
        auto portStr = QString::fromStdString(path.at(2)->getText());
        if(const model::base::PortItem* port = comp->port(portStr)){
          return port;
        }
        appendDslError(path.at(2)->getStart(),
                       QString("\"%1\" is not a valid Port of Component \"%2\".").arg(portStr,compStr));
        return nullptr;
      }
      appendDslError(path.at(1)->getStart(),
                     QString("\"%1\" is not a valid Component of imported Model \"%2\".").arg(compStr,importModelStr));
      return nullptr;
    }
    appendDslError(path.at(0)->getStart(),
                   QString("\"%1\" is not a valid imported Model.").arg(importModelStr));
    return nullptr;
    break;
  case 2:
    compStr = QString::fromStdString(path.at(0)->getText());
    if(const model::base::ComponentItem* comp = _model->component(compStr)){
      auto portStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::PortItem* port = comp->port(portStr)){
        res = port;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid Port of Component \"%2\".").arg(portStr,compStr));
        return nullptr;
      }
    }
    if(model::msc::MscComponentItem* comp = getAlias(compStr)){
      auto portStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::PortItem* port = comp->port(portStr)){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else res = port;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid Port of Component \"%2\".").arg(portStr,compStr));
        return nullptr;
      }
    }
    importModelStr = compStr;
    if(const model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      compStr = QString::fromStdString(path.at(1)->getText());
      if(const model::msc::MscComponentItem* comp = static_cast<const model::msc::MscComponentItem*>(reqModel->component(compStr))){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else res = static_cast<const model::base::PortItem*>(comp->defaultPort());
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid Component of imported model \"%2\".").arg(compStr,importModelStr));
        return nullptr;
      }
    }
    if(res) return res;
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  case 1:
    if(model::msc::MscComponentItem* comp = static_cast<model::msc::MscComponentItem*>(_model->component(QString::fromStdString(path.at(0)->getText())))){
      if(res){
        appendDslError(path.at(0)->getStart(),
                       QString("Path is ambiguous!"));
        return nullptr;
      }
      else res = static_cast<const model::base::PortItem*>(comp->defaultPort());
    }
    if(model::msc::MscComponentItem* comp = getAlias(QString::fromStdString(path.at(0)->getText()))){
      if(res){
        appendDslError(path.at(0)->getStart(),
                       QString("Path is ambiguous!"));
        return nullptr;
      }
      else res = static_cast<const model::base::PortItem*>(comp->defaultPort());
    }
    if(res) return res;
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  case 0:
    appendDslError(compPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  default:
    appendDslError(compPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  }
}

const model::base::SignalItem *IrdlDeclModelListener::getSignalFromPath(IrdlCommonDeclParser::SignalIdPathContext* signalPath)
{
  if(!signalPath || signalPath->exception)
    return nullptr;
  auto path = signalPath->contextID();
  uint8_t sz = path.size();
  QString importModelStr;
  QString signalStr;

  switch (sz) {
  case 2:
    importModelStr = QString::fromStdString(path.at(0)->getText());
    if(model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      signalStr = QString::fromStdString(path.at(1)->getText());
      if(model::base::SignalItem* sig = reqModel->signal(signalStr)){
        return sig;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid signal of imported model \"%2\".").arg(signalStr,importModelStr));
        return nullptr;
      }
    }
    appendDslError(signalPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  case 1:
    signalStr = QString::fromStdString(path.at(0)->getText());
    if(model::base::SignalItem* sig = _model->signal(signalStr)){
      return sig;
    }
    else{
      appendDslError(path.at(0)->getStart(),
                     QString("\"%1\" is not a valid signal.").arg(signalStr,importModelStr));
      return nullptr;
    }
    break;
  case 0:
    appendDslError(signalPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  default:
    appendDslError(signalPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  }
  return nullptr;
}

const model::base::AttributeItem *IrdlDeclModelListener::getAttributeFromPath(IrdlCommonDeclParser::AttributeIdPathContext *attributePath)
{
  if(!attributePath || attributePath->exception)
    return nullptr;
  auto path = attributePath->contextID();
  uint8_t sz = path.size();
  QString importModelStr;
  QString compStr;
  const model::base::AttributeItem* res = nullptr;

  switch (sz) {
  case 3:
    importModelStr = QString::fromStdString(path.at(0)->getText());
    if(const model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      compStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::ComponentItem* comp = reqModel->component(compStr)){
        auto attributeStr = QString::fromStdString(path.at(2)->getText());
        if(model::base::AttributeItem* attribute = comp->attribute(attributeStr)){
          return attribute;
        }
        appendDslError(path.at(2)->getStart(),
                       QString("\"%1\" is not a valid attribute of Component \"%2\".").arg(attributeStr,compStr));
        return nullptr;
      }
      appendDslError(path.at(1)->getStart(),
                     QString("\"%1\" is not a valid Component of imported Model \"%2\".").arg(compStr,importModelStr));
      return nullptr;
    }
    appendDslError(path.at(0)->getStart(),
                   QString("\"%1\" is not a valid imported Model.").arg(importModelStr));
    return nullptr;
    break;
  case 2:
    compStr = QString::fromStdString(path.at(0)->getText());
    if(const model::base::ComponentItem* comp = _model->component(compStr)){
      auto attributeStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::AttributeItem* attribute = comp->attribute(attributeStr)){
        res = attribute;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid attribute of Component \"%2\".").arg(attributeStr,compStr));
        return nullptr;
      }
    }
    if(model::msc::MscComponentItem* comp = getAlias(compStr)){
      auto attributeStr = QString::fromStdString(path.at(1)->getText());
      if(model::base::AttributeItem* attribute = comp->attribute(attributeStr)){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else res = attribute;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid attribute of Component \"%2\".").arg(attributeStr,compStr));
        return nullptr;
      }
    }
    importModelStr = compStr;
    if(model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      auto attributeStr = QString::fromStdString(path.at(1)->getText());
      if(model::base::AttributeItem* attr = (reqModel->attribute(attributeStr))){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else res = attr;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid attribute of imported model \"%2\".").arg(attributeStr,importModelStr));
        return nullptr;
      }
    }
    if(res) return res;
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not an allowed format!"));
    return nullptr;
    break;
  case 1:
    if(model::base::AttributeItem* attr = _model->attribute(QString::fromStdString(path.at(0)->getText()))){
      if(res){
        appendDslError(path.at(0)->getStart(),
                       QString("Path is ambiguous!"));
        return nullptr;
      }
      return attr;
    }
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not an allowed format!"));
    return nullptr;
    break;
  case 0:
    appendDslError(attributePath->getStart(),
                   QString("Path is not an allowed format!"));
    return nullptr;
    break;
  default:
    appendDslError(attributePath->getStart(),
                   QString("Path is not an allowed format!"));
    return nullptr;
    break;
  }
}

} // namespace irdl
} // namespace dslparser
