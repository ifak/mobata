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

#include "statemachinemodellistener.hpp"

#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/functionitem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>
#include <mobata/model/base/timeouttriggeritem.hpp>

#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/transitionitem.hpp>
#include <mobata/model/statemachine/simplestateitem.hpp>
#include <mobata/model/statemachine/compositestateitem.hpp>
#include <mobata/model/statemachine/concurrentstateitem.hpp>
#include <mobata/model/statemachine/junctionstateitem.hpp>
#include <mobata/model/statemachine/finalstateitem.hpp>
#include <mobata/model/statemachine/concurrentstateitem.hpp>
#include <mobata/model/statemachine/regionitem.hpp>
#include <mobata/model/statemachine/functors.hpp>
#include "combuildstatemachinemodel.hpp"

#include <QStack>
#include <QDebug>

using namespace model::statemachine;
using namespace model::base;

using namespace antlr4;

namespace dslparser {
namespace statemachine {

using common::addKeywordLocation;

class StateMachineModelListener::Private
{
  friend class StateMachineModelListener;

  ///parse data////
  QScopedPointer<TransitionItem>         _currentTransition;
  QScopedPointer<TransitionItem>         _currentJunctionTransition;
  ModelItem*                             _currentPathItem;
  const SignalItem*                            _proposalSignalItem;
  QStack<AbstractStateItem*>             _currentStateItem;
  QStack<StateMachineState>              _currentStateType;
  QStack<RegionItem*>                    _currentRegionItem;
  QScopedPointer<TimeoutTriggerItem>     _currentTimeoutTriggerItem;
  AbstractStateItem*                     _currentStatePathItem = nullptr;
  ImportModelItem                        _importItems;
  QString                                _praefix;
  QStack<QString>                        _currentInitState;
  QStack<Token*>                         _currentInitStateToken;
  QHash<AbstractStateItem*,int>          _stateStartPos;
  QHash<AbstractStateItem*,int>          _stateEndPos;
  
  Private(const QString& praefix)
    : _currentTransition(nullptr),
      _currentPathItem(nullptr),
      _importItems(),
      _praefix(praefix)
  {}
};

StateMachineModelListener::StateMachineModelListener(StateMachineModel* statemachineDeclModel,
                                                     DslErrorList* statemachineErrors,
                                                     const QString& praefix,
                                                     TokenTextLocations* keywordTextLocations,
                                                     ModelTextLocations* modelTextLocations)
  : common::CommonModelListener<StateMachineBaseListener, StateMachineParser, StateMachineModel>(statemachineDeclModel,
                                                                                                 statemachineErrors,
                                                                                                 keywordTextLocations,
                                                                                                 modelTextLocations),
    _d(new Private(praefix))
{}

StateMachineModelListener::~StateMachineModelListener()
{
  delete this->_d;
}

AbstractStateItem *StateMachineModelListener::currentStatePathItem()
{
  return _d->_currentStatePathItem;
}

const SignalItem *StateMachineModelListener::currentSignalItem()
{
  return _d->_proposalSignalItem;
}

void StateMachineModelListener::enterStateMachineDecl(StateMachineParser::StateMachineDeclContext* ctx)
{
  this->_listenerStates.push(StateMachineDeclState);

  typedef  tree::TerminalNode* (StateMachineParser::StateMachineDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::StateMachineDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::StateMachineDeclContext::StateMachineID, this->_keywordTextLocations, StateMachine);

}

void StateMachineModelListener::exitStateMachineDecl(StateMachineParser::StateMachineDeclContext* ctx)
{
  this->_listenerStates.pop();
  if(!ctx || ctx->exception) return;
  PropStates* states = dynamic_cast<PropStates*>(this->_model);
  this->setInitState(states, ctx->getStart());

  this->_modelTextLocations->insert(this->_model->invisibleRootItem()->index(),
                                    TokenTextLocation(int(ctx->getStart()->getStartIndex()),
                                                      int(ctx->getStop()->getStopIndex()),
                                                      StateMachine));
  return;
}

void StateMachineModelListener::enterPortDecl(StateMachineParser::PortDeclContext *ctx)
{
  typedef  tree::TerminalNode* (StateMachineParser::PortDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::PortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::PortDeclContext::PortID, this->_keywordTextLocations, Port);
}

void StateMachineModelListener::exitPortDecl(StateMachineParser::PortDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(!ctx || ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  QString errorString;
  Token* startToken = ctx->getStart();
  Token* stopToken = ctx->getStop();
  Q_ASSERT(startToken);
  Q_ASSERT(stopToken);

  const std::vector<StateMachineParser::ContextIDContext *> contextIDs = ctx->contextID();

  if(contextIDs.empty())
    return;

  for(std::vector<StateMachineParser::ContextIDContext *>::const_iterator it = contextIDs.begin();
      it != contextIDs.end();
      it++){
    PortItem* newPort = this->_model->addPort(QString::fromStdString((*it)->getText()),
                                              &errorString);
    if(!newPort)
    {
      appendDslError(ctx->getStart(),
                     errorString);
    }
    else
    {
      this->_modelTextLocations->insert(newPort->index(),
                                        TokenTextLocation(int(startToken->getStartIndex()),
                                                          int(stopToken->getStopIndex()),
                                                          Port));
    }
  }

  return;
}

void StateMachineModelListener::enterTransitionDecl(StateMachineParser::TransitionDeclContext*)
{
  this->_d->_currentTransition.reset(new model::statemachine::TransitionItem(nullptr,nullptr,nullptr));

  return;
}

void StateMachineModelListener::exitTransitionDecl(StateMachineParser::TransitionDeclContext* transDeclCtx)
{
  Q_ASSERT(transDeclCtx);

  if(transDeclCtx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!this->_d->_currentTransition)
    return;//an error occured! -> but still handled by error listener!

  Token* startToken = transDeclCtx->getStart();
  Token* stopToken = transDeclCtx->getStop();
  Q_ASSERT(startToken);
  Q_ASSERT(stopToken);

  int transitionType = SignalTransition;
  if(transDeclCtx->timeoutTransitionDecl())
    transitionType = TimeoutTransition;

  TransitionItem* takenTransition=this->_d->_currentTransition.take();
  Q_ASSERT(takenTransition);
  takenTransition->setText(takenTransition->name());
  QString errorString;
  bool result = this->_model->addTransition(takenTransition,
                                            &errorString);
  if(!result)
  {
    appendDslError(transDeclCtx->getStart(),
                   errorString);
    delete takenTransition;
  }
  else
  {
    if(this->_modelTextLocations)
    {
      this->_modelTextLocations->insert(takenTransition->index(),
                                        TokenTextLocation(int(startToken->getStartIndex()),
                                                          int(stopToken->getStopIndex()),
                                                          transitionType));
    }
  }

  this->_d->_currentTransition.reset();
  this->_listenerStates.pop();

  return;
}

void StateMachineModelListener::enterSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext* ctx)
{
  typedef  tree::TerminalNode* (StateMachineParser::SignalTransitionDeclContext::*KeywordFunction)();

  this->_listenerStates.push(SignalTransitionDeclState);

  return addKeywordLocation<StateMachineParser::SignalTransitionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::SignalTransitionDeclContext::SignalTransitionID, this->_keywordTextLocations, SignalTransition);
}

void StateMachineModelListener::exitSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext* ctx)
{
  Q_ASSERT(ctx);
  Q_ASSERT(this->_d->_currentTransition);

  this->_currentMessageSignalItem=nullptr;

  if(ctx->exception){//an error occured, handled by error listener, current transition is set to 0 for next rules!
    appendDslError(ctx->getStart(),
                   QStringLiteral("Creating SignalTransitionItem failed!"));
    if(_d->_currentTransition){
      if(auto trig = dynamic_cast<SignalTriggerItem*>(_d->_currentTransition.data()->trigger())){
        _d->_proposalSignalItem = trig->triggerSignal();
      }
    }
    this->_d->_currentTransition.reset();
    return;
  }

  this->_modelTextLocations->insert(this->_d->_currentTransition->index(),
                                    TokenTextLocation(int(ctx->getStart()->getStartIndex()),
                                                      int(ctx->getStop()->getStopIndex()),
                                                      SignalTransition));
  return;
}

void StateMachineModelListener::enterTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext* ctx)
{
  typedef  tree::TerminalNode* (StateMachineParser::TimeoutTransitionDeclContext::*KeywordFunction)();

  this->_d->_currentTimeoutTriggerItem.reset(new TimeoutTriggerItem(0));
  this->_listenerStates.push(TimeoutTransitionDeclState);

  return addKeywordLocation<StateMachineParser::TimeoutTransitionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::TimeoutTransitionDeclContext::TimeoutTransitionID, this->_keywordTextLocations, TimeoutTransition);
}

void StateMachineModelListener::exitTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext* ctx)
{
  Q_ASSERT(ctx);
  this->_listenerStates.pop();
  TimeoutTriggerItem* timeoutTriggerItem = this->_d->_currentTimeoutTriggerItem.take();
  if(!timeoutTriggerItem) return;
  this->_d->_currentTransition->setTrigger(timeoutTriggerItem);

  if(ctx->exception)//an error occured, handled by error listener, current transition is set to 0 for next rules!
    this->_d->_currentTransition.reset();

  return;
}

void StateMachineModelListener::enterNameDecl(StateMachineParser::NameDeclContext* ctx)
{
  typedef  tree::TerminalNode* (StateMachineParser::NameDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::NameDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void StateMachineModelListener::exitNameDecl(StateMachineParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString name=QString::fromStdString(ctx->contextID()->getText());

  switch(this->currentListenerState()){
  case StateMachineDeclState:
    Q_ASSERT(this->_model);
    this->_model->setName(name);
    break;
  case StateDeclState:
    Q_ASSERT(this->_d->_currentStateItem.top());
    if(this->_d->_currentStateItem.count()>0)
      this->_d->_currentStateItem.top()->setName(name);
    break;
  case TimeoutTransitionDeclState:
  case SignalTransitionDeclState:
    Q_ASSERT(this->_d->_currentTransition);
    this->_d->_currentTransition->setName(name);
    break;
  case JunctionTransitionDeclState:
    Q_ASSERT(this->_d->_currentJunctionTransition);
    this->_d->_currentJunctionTransition->setName(name);
    this->_d->_currentJunctionTransition->setText(name);
    break;
  case RegionDeclState:
    Q_ASSERT(this->_d->_currentRegionItem.top());
    if(this->_d->_currentRegionItem.count()>0)
      this->_d->_currentRegionItem.top()->setName(name);
    break;
  }

  return;
}

void StateMachineModelListener::enterRefSignalDecl(StateMachineParser::RefSignalDeclContext* ctx)
{
  typedef  tree::TerminalNode* (StateMachineParser::RefSignalDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::RefSignalDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::RefSignalDeclContext::RefSignalID, this->_keywordTextLocations, Attribute);
}

void StateMachineModelListener::exitRefSignalDecl(StateMachineParser::RefSignalDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(this->currentListenerState() == SignalTransitionDeclState)
  {
    QString signalName=QString::fromStdString(ctx->ID()->getText());

    model::base::SignalItem* signal = this->_model->signal(signalName);
    if(!signal)
    {
      appendDslError(ctx->ID()->getSymbol(),
                     QObject::tr("there is no signal '%1' available!"));
      return;
    }

    this->_currentMessageSignalItem=signal;
    Q_ASSERT(this->_d->_currentTransition);
    SignalTriggerItem* trigger = new SignalTriggerItem(signal);
    this->_d->_currentTransition.data()->setTrigger(trigger);
  }

  return;
}

void StateMachineModelListener::enterRefPortDecl(StateMachineParser::RefPortDeclContext* ctx)
{
  typedef  tree::TerminalNode* (StateMachineParser::RefPortDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::RefPortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::RefPortDeclContext::RefPortID, this->_keywordTextLocations, Attribute);
}

void StateMachineModelListener::exitRefPortDecl(StateMachineParser::RefPortDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(this->currentListenerState() == SignalTransitionDeclState)
  {

    QString portName=QString::fromStdString(ctx->ID()->getText());

    model::statemachine::PortItem* portItem = this->_model->port(portName);
    if(!portItem)
    {
      appendDslError(ctx->ID()->getSymbol(),
                     QObject::tr("there is no port '%1' available!"));
      return;
    }

    Q_ASSERT(this->_d->_currentTransition);
    if(auto trigTrans =  dynamic_cast<SignalTriggerItem *>(this->_d->_currentTransition->trigger()))
      trigTrans->setPort(portItem);
  }

  return;
}

void StateMachineModelListener::enterTimeoutDecl(StateMachineParser::TimeoutDeclContext* ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::TimeoutDeclContext::*KeywordFunction)();

  this->_listenerStates.push(TimeoutTransitionDeclState);

  return addKeywordLocation<StateMachineParser::TimeoutDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::TimeoutDeclContext::ValueID, this->_keywordTextLocations, Attribute);
}

void StateMachineModelListener::exitTimeoutDecl(StateMachineParser::TimeoutDeclContext *ctx)
{
  Q_ASSERT(ctx);
  Q_ASSERT(this->_d->_currentTransition);
  Q_ASSERT(this->_d->_currentTimeoutTriggerItem);

  if(ctx->exception){//an error occured, handled by error listener, current transition is set to 0 for next rules!
    appendDslError(ctx->getStart(),
                   QStringLiteral("Creating TimeoutTransitionItem failed!"));
    this->_d->_currentTransition.reset();
    this->_d->_currentTimeoutTriggerItem.reset();
    return;
  }

  double timeout = QString::fromStdString(ctx->val->getText()).toDouble();
  this->_d->_currentTimeoutTriggerItem->setValue(timeout);

  return;
}

void StateMachineModelListener::enterGuardDecl(StateMachineParser::GuardDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::GuardDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::GuardDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::GuardDeclContext::GuardID, this->_keywordTextLocations, Guard);
}

void StateMachineModelListener::exitGuardDecl(StateMachineParser::GuardDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!
  QString guardStr;
  if(ctx->expression()){
    const misc::Interval interval(ctx->expression()->getStart()->getStartIndex(),ctx->expression()->getStop()->getStopIndex());
    guardStr = QString::fromStdString(ctx->expression()->getStart()->
                                      getInputStream()->
                                      getText(interval));
    //remove whitespaces at the start & end of string;
    guardStr = guardStr.trimmed();
  }
  else if(ctx->ElseID()){
    guardStr = QString::fromStdString(ctx->ElseID()->getText());
    //remove whitespaces at the start & end of string;
    guardStr = guardStr.trimmed();
  }
  switch(this->currentListenerState()){
  case SignalTransitionDeclState:
  case TimeoutTransitionDeclState:
    if(!this->_d->_currentTransition) return;
    this->_d->_currentTransition->setGuard(guardStr);
    break;
  case JunctionTransitionDeclState:
    Q_ASSERT(this->_d->_currentJunctionTransition);
    this->_d->_currentJunctionTransition->setGuard(guardStr);
    break;
  }
}

void StateMachineModelListener::enterInitStateDecl(StateMachineParser::InitStateDeclContext* ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::InitStateDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::InitStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::InitStateDeclContext::InitStateID, this->_keywordTextLocations, Attribute);
}

void StateMachineModelListener::exitInitStateDecl(StateMachineParser::InitStateDeclContext* ctx)
{
  if(!ctx || ctx->exception || !ctx->idPath()) return;

  this->_d->_currentInitState.push(QString::fromStdString(ctx->idPath()->getText()));
  Token* startToken = ctx->getStart();
  Q_ASSERT(startToken);
  this->_d->_currentInitStateToken.push(startToken);
  return;
}

void StateMachineModelListener::enterActionDecl(StateMachineParser::ActionDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::ActionDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::ActionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::ActionDeclContext::ActionID, this->_keywordTextLocations, Action);
}

void StateMachineModelListener::exitActionDecl(StateMachineParser::ActionDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  misc::Interval interval;
  if(ctx->actionNestedStatementBody())
  {
    Q_ASSERT(ctx->actionNestedStatementBody()->LBRACE());
    Q_ASSERT(ctx->actionNestedStatementBody()->LBRACE()->getSymbol());

    if(!ctx->actionNestedStatementBody()->RBRACE())
    {
      appendDslError(ctx->getStart(),
                     "Action was not defined correctly!");
      return;
    }

    Q_ASSERT(ctx->actionNestedStatementBody()->RBRACE());
    Q_ASSERT(ctx->actionNestedStatementBody()->RBRACE()->getSymbol());
    interval = misc::Interval(ctx->actionNestedStatementBody()->LBRACE()->getSymbol()->getStartIndex()+1,
                              ctx->actionNestedStatementBody()->RBRACE()->getSymbol()->getStartIndex()-1);
  }
  else if(ctx->actionStatementBody())
    interval = misc::Interval(ctx->COLON()->getSymbol()->getStartIndex()+1,ctx->getStop()->getStopIndex()/*-1*/);
  else{
    appendDslError(ctx->getStart(),
                   "Action was not defined correctly!");
  }

  //remove whitespaces at the start & end of string;
  QString actionStr = QString::fromStdString(ctx->getStart()->getInputStream()->getText(interval));
  actionStr = actionStr.trimmed();
  switch(this->currentListenerState()){
  case SignalTransitionDeclState:
  case TimeoutTransitionDeclState:
    if(!this->_d->_currentTransition) return;
    this->_d->_currentTransition->setAction(actionStr);
    break;
  case JunctionTransitionDeclState:
    Q_ASSERT(this->_d->_currentJunctionTransition);
    this->_d->_currentJunctionTransition->setAction(actionStr);
    break;
  }

}

void StateMachineModelListener::enterSimpleStateDecl(StateMachineParser::SimpleStateDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::SimpleStateDeclContext::*KeywordFunction)();

  addKeywordLocation<StateMachineParser::SimpleStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::SimpleStateDeclContext::SimpleStateID, this->_keywordTextLocations, StateMachineTokenType::SimpleState);

  SimpleStateItem* newsimpleStateItem = new SimpleStateItem("");
  this->_d->_currentStateItem.push(newsimpleStateItem);
  this->_d->_currentStateType.push(SimpleState);
  this->_listenerStates.push(StateDeclState);
}

void StateMachineModelListener::exitSimpleStateDecl(StateMachineParser::SimpleStateDeclContext *ctx)
{
  this->_listenerStates.pop();
  if(!ctx || ctx->exception)
    return;

  AbstractStateItem* item = nullptr;
  if(this->_d->_currentStateItem.size()>0 && (this->_d->_currentStateItem.top())){
    item = this->_d->_currentStateItem.top();
  }
  Q_ASSERT(item);

  if (ctx->contextID())
    this->_d->_currentStateItem.top()->setName(QString::fromStdString(ctx->contextID()->getText()));

  if(!addState(SimpleState,ctx))
    return;

  return;
}

void StateMachineModelListener::enterCompositeStateDecl(StateMachineParser::CompositeStateDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::CompositeStateDeclContext::*KeywordFunction)();

  addKeywordLocation<StateMachineParser::CompositeStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::CompositeStateDeclContext::CompositeStateID,
       this->_keywordTextLocations, StateMachineTokenType::CompositeState);

  CompositeStateItem* newCompositeStateItem = new CompositeStateItem("");
  this->_d->_currentStateItem.push(newCompositeStateItem);
  this->_d->_currentStateType.push(CompositeState);
  this->_listenerStates.push(StateDeclState);

  return;
}

void StateMachineModelListener::exitCompositeStateDecl(StateMachineParser::CompositeStateDeclContext *ctx)
{
  this->_listenerStates.pop();
  if(!ctx || ctx->exception)
    return;

  if(this->_d->_currentStateItem.size()
     && this->_d->_currentStateItem.top())
  {
    this->_modelTextLocations->insert(this->_d->_currentStateItem.top()->index(),
                                      TokenTextLocation(int(ctx->getStart()->getStartIndex()),
                                                        int(ctx->getStop()->getStopIndex()),
                                                        CompositeState));

    AbstractStateItem* state = this->_d->_currentStateItem.top();
    if(!addState(CompositeState,ctx))
      return;

    CompositeStateItem* composite = static_cast<CompositeStateItem*>(state);
    Q_ASSERT(composite);
    PropStates* states = dynamic_cast<PropStates*>(composite);
    this->setInitState(states, ctx->getStart());
  }

  return;
}

void StateMachineModelListener::enterJunctionStateDecl(StateMachineParser::JunctionStateDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::JunctionStateDeclContext::*KeywordFunction)();

  addKeywordLocation<StateMachineParser::JunctionStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::JunctionStateDeclContext::JunctionStateID, this->_keywordTextLocations, StateMachineTokenType::JunctionState);

  this->_d->_currentStateItem.push((AbstractStateItem*)new JunctionStateItem());
  this->_d->_currentStateType.push(JunctionState);
  this->_listenerStates.push(StateDeclState);
}

void StateMachineModelListener::exitJunctionStateDecl(StateMachineParser::JunctionStateDeclContext *ctx)
{
  this->_listenerStates.pop();
  if(!ctx || ctx->exception)
    return;

  if(this->_d->_currentStateItem.size()
     && this->_d->_currentStateItem.top())
  {
    this->_modelTextLocations->insert(this->_d->_currentStateItem.top()->index(),
                                      TokenTextLocation(int(ctx->getStart()->getStartIndex()),
                                                        int(ctx->getStop()->getStopIndex()),
                                                        JunctionState));
    if(!addState(JunctionState,ctx))
      return;
  }

  return;
}

void StateMachineModelListener::enterJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext* ctx)
{
  typedef  tree::TerminalNode* (StateMachineParser::JunctionTransitionDeclContext::*KeywordFunction)();

  this->_listenerStates.push(JunctionTransitionDeclState);
  this->_d->_currentJunctionTransition.reset(new model::statemachine::TransitionItem(nullptr, nullptr, nullptr));

  return addKeywordLocation<StateMachineParser::JunctionTransitionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::JunctionTransitionDeclContext::JunctionTransitionID, this->_keywordTextLocations, JunctionTransition);
}

void StateMachineModelListener::exitJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext* ctx)
{
  Q_ASSERT(ctx);

  this->_listenerStates.pop();
  if(ctx->exception
     || !this->_d->_currentJunctionTransition
     || this->_d->_currentStateItem.isEmpty()
     || this->_d->_currentStateItem.top()->stateType() != Junction){
    this->_d->_currentJunctionTransition.reset();
    return;//an error occured! -> but still handled by error listener!
  }

  Token* startToken = ctx->getStart();
  Token* stopToken = ctx->getStop();
  Q_ASSERT(startToken);
  Q_ASSERT(stopToken);

  Q_ASSERT(this->_d->_currentJunctionTransition);
  TransitionItem* takenTransition=this->_d->_currentJunctionTransition.take();
  Q_ASSERT(takenTransition);
  QString errorString;

  AbstractStateItem* abstractItem = this->_d->_currentStateItem.top();
  Q_ASSERT(abstractItem);
  JunctionStateItem* junctionItem = static_cast<JunctionStateItem*>(abstractItem);
  Q_ASSERT(junctionItem);

  bool result = junctionItem->addJunctionTransition(takenTransition,
                                                    &errorString);
  if(!result)
  {
    if(this->_errors)
      this->_errors->append(DslError(errorString,
                                     int(startToken->getLine()),
                                     int(startToken->getCharPositionInLine())));
    delete takenTransition;
  }
  else
  {
    if(this->_modelTextLocations)
    {
      this->_modelTextLocations->insert(takenTransition->index(),
                                        TokenTextLocation(int(startToken->getStartIndex()),
                                                          int(stopToken->getStopIndex()),
                                                          JunctionTransition));
    }
  }

  this->_d->_currentJunctionTransition.reset();

  return;
}

void StateMachineModelListener::enterFinalStateDecl(StateMachineParser::FinalStateDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::FinalStateDeclContext::*KeywordFunction)();

  addKeywordLocation<StateMachineParser::FinalStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::FinalStateDeclContext::FinalStateID, this->_keywordTextLocations, StateMachineTokenType::FinalState);

  this->_d->_currentStateItem.push((AbstractStateItem*)new FinalStateItem());
  this->_d->_currentStateType.push(FinalState);
  this->_listenerStates.push(StateDeclState);
}

void StateMachineModelListener::exitFinalStateDecl(StateMachineParser::FinalStateDeclContext *ctx)
{
  this->_listenerStates.pop();
  if(!ctx || ctx->exception)
    return;

  if(this->_d->_currentStateItem.size()
     && this->_d->_currentStateItem.top())
  {
    if (ctx->ID())
      this->_d->_currentStateItem.top()->setName(QString::fromStdString(ctx->ID()->getText()));

    this->_modelTextLocations->insert(this->_d->_currentStateItem.top()->index(),
                                      TokenTextLocation(int(ctx->getStart()->getStartIndex()),
                                                        int(ctx->getStop()->getStopIndex()),
                                                        FinalState));
    if(!addState(FinalState,ctx))
      return;
  }

  return;
}

void StateMachineModelListener::enterConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext *ctx)
{
  if(!ctx || ctx->exception)
    return;
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::ConcurrentStateDeclContext::*KeywordFunction)();

  addKeywordLocation<StateMachineParser::ConcurrentStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::ConcurrentStateDeclContext::ConcurrentStateID, this->_keywordTextLocations, StateMachineTokenType::ConcurrentState);
  this->_d->_currentStateItem.push((AbstractStateItem*)new ConcurrentStateItem(QString("concurrent")));
  this->_d->_currentStateType.push(ConcurrentState);
  this->_listenerStates.push(StateDeclState);
}

void StateMachineModelListener::exitConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext *ctx)
{
  this->_listenerStates.pop();
  if(!ctx || ctx->exception)
    return;

  if(this->_d->_currentStateItem.size() && this->_d->_currentStateItem.top()){
    AbstractStateItem* item = this->_d->_currentStateItem.top();
    Q_ASSERT(item);
    if(!addState(ConcurrentState,ctx))
      return;

    this->_modelTextLocations->insert(item->index(),
                                      TokenTextLocation(int(ctx->getStart()->getStartIndex()),
                                                        int(ctx->getStop()->getStopIndex()),
                                                        ConcurrentState));
  }
  return;
}

void StateMachineModelListener::enterRegionDecl(StateMachineParser::RegionDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(!ctx || ctx->exception)
    return;

  typedef  tree::TerminalNode* (StateMachineParser::RegionDeclContext::*KeywordFunction)();

  addKeywordLocation<StateMachineParser::RegionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::RegionDeclContext::RegionID, this->_keywordTextLocations, Region);
  this->_d->_currentRegionItem.push((RegionItem*)new RegionItem(QString("region")));
  this->_listenerStates.push(RegionDeclState);
}

void StateMachineModelListener::exitRegionDecl(StateMachineParser::RegionDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(!ctx || ctx->exception)
    return;

  this->_listenerStates.pop();
  if(this->_d->_currentRegionItem.size() && this->_d->_currentRegionItem.top()){
    RegionItem* item = this->_d->_currentRegionItem.top();
    Q_ASSERT(item);
    if(!addRegion(ctx))
      return;

    PropStates* states = dynamic_cast<PropStates*>(item);
    this->setInitState(states, ctx->getStart());
    this->_modelTextLocations->insert(item->index(),
                                      TokenTextLocation(int(ctx->getStart()->getStartIndex()),
                                                        int(ctx->getStop()->getStopIndex()),
                                                        Region));
  }
  return;
}

void StateMachineModelListener::enterRegionBody(StateMachineParser::RegionBodyContext *ctx)
{
  Q_ASSERT(ctx);
  if(!ctx || ctx->exception)
    return;
}

void StateMachineModelListener::exitRegionBody(StateMachineParser::RegionBodyContext *ctx)
{
  Q_ASSERT(ctx);
  if(!ctx || ctx->exception)
    return;

  if(this->_d->_currentStateType.size() == 0){
    appendDslError(ctx->getStart(),
                   QStringLiteral("There is no current state!"));
    return;
  }
}

void StateMachineModelListener::enterEntryActionDecl(StateMachineParser::EntryActionDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::EntryActionDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::EntryActionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::EntryActionDeclContext::EntryActionID, this->_keywordTextLocations, EntryAction);
}

void StateMachineModelListener::exitEntryActionDecl(StateMachineParser::EntryActionDeclContext *ctx)
{
  if(!ctx || ctx->exception)
    return;
  if(this->_d->_currentStateItem.count() == 0
     || this->_d->_currentStateType.count() != this->_d->_currentStateItem.count()
     || this->_d->_currentStateType.count() == 0
     || this->_d->_currentStateType.top() == FinalState
     || this->_d->_currentStateType.top() == JunctionState){
    appendDslError(ctx->getStart(),
                   QStringLiteral("Something went wrong in State creation!"));
    return;
  }
  misc::Interval interval;
  if(ctx->actionNestedStatementBody())
  {
    Q_ASSERT(ctx->actionNestedStatementBody()->LBRACE());
    Q_ASSERT(ctx->actionNestedStatementBody()->LBRACE()->getSymbol());
    if(!ctx->actionNestedStatementBody()->RBRACE())
    {
      appendDslError(ctx->getStart(),
                     "Action was not defined correctly!");
      return;
    }
    Q_ASSERT(ctx->actionNestedStatementBody()->RBRACE());
    Q_ASSERT(ctx->actionNestedStatementBody()->RBRACE()->getSymbol());
    interval = misc::Interval(ctx->actionNestedStatementBody()->LBRACE()->getSymbol()->getStartIndex()+1,
                              ctx->actionNestedStatementBody()->RBRACE()->getSymbol()->getStartIndex()-1);
  }
  else if(ctx->actionStatementBody())
    interval = misc::Interval(ctx->COLON()->getSymbol()->getStartIndex()+1,ctx->getStop()->getStopIndex()/*-1*/);
  else{
    appendDslError(ctx->getStart(),
                   "Action was not defined correctly!");
  }

  //remove whitespaces at the start & end of string;
  QString actionStr = QString::fromStdString(ctx->getStart()->
                                             getInputStream()->
                                             getText(interval));
  actionStr = actionStr.trimmed();

  switch (this->_d->_currentStateType.top())
  {
  case SimpleState:
  {
    SimpleStateItem* simpleState = static_cast<SimpleStateItem*>(this->_d->_currentStateItem.top());
    Q_ASSERT(simpleState);
    simpleState->setEntryAction(actionStr);
    break;
  }
  case CompositeState:
  {
    CompositeStateItem* compositeState = static_cast<CompositeStateItem*>(this->_d->_currentStateItem.top());
    Q_ASSERT(compositeState);
    compositeState->setEntryAction(actionStr);
    break;
  }
  case ConcurrentState:
  {
    ConcurrentStateItem* concurrentState = static_cast<ConcurrentStateItem*>(this->_d->_currentStateItem.top());
    Q_ASSERT(concurrentState);
    concurrentState->setEntryAction(actionStr);
    break;
  }
  default:
    break;
  }

  return;
}

void StateMachineModelListener::enterExitActionDecl(StateMachineParser::ExitActionDeclContext *ctx)
{

  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::ExitActionDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::ExitActionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::ExitActionDeclContext::ExitActionID, this->_keywordTextLocations, ExitAction);
}

void StateMachineModelListener::exitExitActionDecl(StateMachineParser::ExitActionDeclContext *ctx)
{

  if(!ctx || ctx->exception)
    return;
  if(this->_d->_currentStateItem.count() == 0
     || this->_d->_currentStateType.count() != this->_d->_currentStateItem.count()
     || this->_d->_currentStateType.count() == 0
     || this->_d->_currentStateType.top() == FinalState
     || this->_d->_currentStateType.top() == JunctionState){
    appendDslError(ctx->getStart(),
                   QStringLiteral("Something went wrong in State creation!"));
    return;
  }

  misc::Interval interval;
  if(ctx->actionNestedStatementBody())
  {
    Q_ASSERT(ctx->actionNestedStatementBody()->LBRACE());
    Q_ASSERT(ctx->actionNestedStatementBody()->LBRACE()->getSymbol());
    if(!ctx->actionNestedStatementBody()->RBRACE())
    {
      appendDslError(ctx->getStart(),
                     "Action was not defined correctly!");
      return;
    }
    Q_ASSERT(ctx->actionNestedStatementBody()->RBRACE());
    Q_ASSERT(ctx->actionNestedStatementBody()->RBRACE()->getSymbol());
    interval = misc::Interval(ctx->actionNestedStatementBody()->LBRACE()->getSymbol()->getStartIndex()+1,
                              ctx->actionNestedStatementBody()->RBRACE()->getSymbol()->getStartIndex()-1);
  }
  else if(ctx->actionStatementBody())
    interval = misc::Interval(ctx->COLON()->getSymbol()->getStartIndex()+1,ctx->getStop()->getStopIndex()/*-1*/);
  else{
    appendDslError(ctx->getStart(),
                   "Action was not defined correctly!");
  }

  //remove whitespaces at the start & end of string;
  QString actionStr = QString::fromStdString(ctx->getStart()->
                                             getInputStream()->
                                             getText(interval));
  actionStr = actionStr.trimmed();

  switch (this->_d->_currentStateType.top())
  {
  case SimpleState:
  {
    SimpleStateItem* simpleState = static_cast<SimpleStateItem*>(this->_d->_currentStateItem.top());
    Q_ASSERT(simpleState);
    simpleState->setExitAction(actionStr);
    break;
  }
  case CompositeState:
  {
    CompositeStateItem* compositeState = static_cast<CompositeStateItem*>(this->_d->_currentStateItem.top());
    Q_ASSERT(compositeState);
    compositeState->setExitAction(actionStr);
    break;
  }
  case ConcurrentState:
  {
    ConcurrentStateItem* concurrentState = static_cast<ConcurrentStateItem*>(this->_d->_currentStateItem.top());
    Q_ASSERT(concurrentState);
    concurrentState->setExitAction(actionStr);
    break;
  }
  default:
    break;
  }
}

void StateMachineModelListener::enterSourceStateDecl(StateMachineParser::SourceStateDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::SourceStateDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::SourceStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::SourceStateDeclContext::SourceStateID, this->_keywordTextLocations, Source);
}

void StateMachineModelListener::exitSourceStateDecl(StateMachineParser::SourceStateDeclContext *ctx)
{
  if(!ctx || ctx->exception || !ctx->stateIdPath())
    return;

  QString statePath;
  const std::vector<StateMachineParser::ContextIDContext *> contextIDs = ctx->stateIdPath()->contextID();

  if(contextIDs.empty())
    return;

  std::size_t pos=0;
  for(std::vector<StateMachineParser::ContextIDContext *>::const_iterator it = contextIDs.begin();
      it != contextIDs.end();
      ++it, ++pos)
  {
    if(pos)
      statePath.append(".");
    statePath.append(QString::fromStdString((*it)->getText()));
  }

  AbstractStateItem const* state = statesRecursiveByName(this->_model,
                                                         statePath,_d->_currentStatePathItem);
  if(state) _d->_currentStatePathItem = nullptr;

  if(ctx && state)
  {
    this->_d->_currentPathItem = const_cast<AbstractStateItem*>(state);
    Q_ASSERT(this->_d->_currentPathItem);
    if(!this->_d->_currentTransition) return;
    this->_d->_currentTransition->setSource(state);
  }
  else
  {
    appendDslError(ctx->getStart(),
                   QStringLiteral("Source state was not found!"));
  }
}

void StateMachineModelListener::enterTargetStateDecl(StateMachineParser::TargetStateDeclContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::TargetStateDeclContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::TargetStateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::TargetStateDeclContext::TargetStateID, this->_keywordTextLocations, Target);
}

void StateMachineModelListener::exitTargetStateDecl(StateMachineParser::TargetStateDeclContext *ctx)
{
  if(!ctx || ctx->exception || !ctx->stateIdPath())
    return;

  QString statePath;
  const std::vector<StateMachineParser::ContextIDContext *> contextIDs = ctx->stateIdPath()->contextID();

  if(contextIDs.empty())
    return;

  std::size_t pos=0;
  for(std::vector<StateMachineParser::ContextIDContext *>::const_iterator it = contextIDs.begin();
      it != contextIDs.end();
      ++it, ++pos)
  {
    if(pos)
      statePath.append(".");
    statePath.append(QString::fromStdString((*it)->getText()));
  }

  AbstractStateItem const* state = statesRecursiveByName(this->_model,
                                                         statePath,_d->_currentStatePathItem);
  if(state) _d->_currentStatePathItem = nullptr;

  if(ctx && state)
  {
    this->_d->_currentPathItem = const_cast<AbstractStateItem*>(state);
    Q_ASSERT(this->_d->_currentPathItem);

    switch(this->currentListenerState())
    {
    case SignalTransitionDeclState:
    case TimeoutTransitionDeclState:
      if(!this->_d->_currentTransition) return;
      this->_d->_currentTransition->setTarget(state);
      break;
    case JunctionTransitionDeclState:
      Q_ASSERT(this->_d->_currentJunctionTransition);
      this->_d->_currentJunctionTransition->setTarget(state);
      break;
    }
  }
  else
  {
    appendDslError(ctx->getStart(),
                   QStringLiteral("Something went wrong in State creation!"));
  }
}

void StateMachineModelListener::enterImportPathBody(StateMachineParser::ImportPathBodyContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (StateMachineParser::ImportPathBodyContext::*KeywordFunction)();

  return addKeywordLocation<StateMachineParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);
}

void StateMachineModelListener::exitImportPathBody(StateMachineParser::ImportPathBodyContext *ctx)
{
  if(ctx->exception || !ctx->importFileBody())
    return;
  typedef  tree::TerminalNode* (StateMachineParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<StateMachineParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &StateMachineParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);

  QString path = QString::fromStdString(ctx->importFileBody()->getText());
  path = this->_d->_praefix + path;
  QFile file(path);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<path<<"' could not be opened!";
  QString docText(file.readAll());
  file.close();

  if(path.endsWith(QString("statemachine")))
  {
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = path;
    }
    model::statemachine::StateMachineModel* statemachineModel = new model::statemachine::StateMachineModel(/*,_model*/);
    dslparser::statemachine::ComBuildStateMachineModel command(docText, statemachineModel,_d->_praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      this->_d->_importItems.insert(name,statemachineModel);
      //this->_model->addImportItem(statemachineModel);
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QStringLiteral("Import File contains errors..."));
      if(this->_errors){
        this->_errors->append(command.errors());
      }
      return;
    }
  }
  else if(path.endsWith(QString("decl"))){

  }
}

void StateMachineModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);

  //  qDebug()<<"StateMachineModelListener::visitErrorNode() "
  //            "state: "<<this->_d->_listenerStates.top()
  //         <<"error node: "<<node->toString().c_str();

  return;
}

bool StateMachineModelListener::addState(StateMachineState type, ParserRuleContext *ctx)
{
  if(!ctx || ctx->exception)
    return false;

  Q_ASSERT(this->_d->_currentStateItem.count() > 0);
  Q_ASSERT(this->_d->_currentStateType.count() == this->_d->_currentStateItem.count());
  Q_ASSERT(this->_d->_currentStateType.count() > 0);

  if(this->_d->_currentStateItem.count() == 0
     || this->_d->_currentStateType.count() != this->_d->_currentStateItem.count()
     || this->_d->_currentStateType.count() == 0
     || this->_d->_currentStateItem.top()->uuid().isNull()
     || this->_d->_currentStateType.top() != type){
    appendDslError(ctx->getStart(),
                   QStringLiteral("Something went wrong in State creation!"));
    this->_d->_currentStateItem.pop();
    this->_d->_currentStateType.pop();
    return false;
  }

  AbstractStateItem* item = this->_d->_currentStateItem.top();
  _d->_stateStartPos.insert(item,int(ctx->getStart()->getStartIndex()));
  _d->_stateEndPos.insert(item,int(ctx->getStop()->getStopIndex()));
  item->setText(item->name());
  this->_d->_currentStateItem.pop();
  this->_d->_currentStateType.pop();
  QString errorString = "";
  if(this->_d->_currentStateItem.count()>0 && !_d->_currentStateItem.top()->uuid().isNull()){
    switch (this->_d->_currentStateType.top()) {
    case CompositeState:
    {
      CompositeStateItem* item2 = static_cast<CompositeStateItem*>(this->_d->_currentStateItem.top());
      if(!item2->addState(item,&errorString)){
        appendDslError(ctx->getStart(),
                       errorString);
        return false;
      }
      break;
    }
    case ConcurrentState:{
      if(this->_d->_currentRegionItem.isEmpty() && !_d->_currentRegionItem.top()->uuid().isNull())
      {
        appendDslError(ctx->getStart(),
                       QStringLiteral("Something went wrong in State creation!"));
        return false;
      }
      RegionItem* regionItem = this->_d->_currentRegionItem.top();
      Q_ASSERT(regionItem);
      if(!regionItem->addState(item,&errorString))
        appendDslError(ctx->getStart(),
                       errorString);
      return false;
    }
    default:
      appendDslError(ctx->getStart(),
                     QStringLiteral("Something went wrong in State creation!"));
      return false;
    }
  }
  else {
    if(!this->_model->addState(item,&errorString))
    {
      appendDslError(ctx->getStart(),
                     errorString);
      return false;
    }

    QList<AbstractStateItem*> stateList;
    stateList.append(item);
    while(stateList.size()){
      AbstractStateItem* curItem = stateList.front();
      stateList.pop_front();
      if(curItem->stateType()==Composite){
        CompositeStateItem* compItem = static_cast<CompositeStateItem*>(curItem);
        Q_ASSERT(compItem);
        this->_modelTextLocations->insert(curItem->index(),
                                          TokenTextLocation(_d->_stateStartPos.value(curItem),
                                                            _d->_stateEndPos.value(curItem),
                                                            StateMachineTokenType::CompositeState));
        stateList.append(compItem->states());
      }
      if(curItem->stateType()==Junction){
        this->_modelTextLocations->insert(curItem->index(),
                                          TokenTextLocation(_d->_stateStartPos.value(curItem),
                                                            _d->_stateEndPos.value(curItem),
                                                            StateMachineTokenType::JunctionState));
      }
      if(curItem->stateType()==Concurrent){
        ConcurrentStateItem* concItem = static_cast<ConcurrentStateItem*>(curItem);
        Q_ASSERT(concItem);
        this->_modelTextLocations->insert(curItem->index(),
                                          TokenTextLocation(_d->_stateStartPos.value(curItem),
                                                            _d->_stateEndPos.value(curItem),
                                                            StateMachineTokenType::ConcurrentState));
        for(auto reg : concItem->regions()){
          stateList.append(reg->states());
        }
      }
      if(curItem->stateType()==Final){
        this->_modelTextLocations->insert(curItem->index(),
                                          TokenTextLocation(_d->_stateStartPos.value(curItem),
                                                            _d->_stateEndPos.value(curItem),
                                                            StateMachineTokenType::FinalState));
      }
      if(curItem->stateType()==Simple){
        this->_modelTextLocations->insert(curItem->index(),
                                          TokenTextLocation(_d->_stateStartPos.value(curItem),
                                                            _d->_stateEndPos.value(curItem),
                                                            StateMachineTokenType::SimpleState));
      }
    }
  }

  return true;
}

bool StateMachineModelListener::addRegion(ParserRuleContext *ctx)
{
  Q_ASSERT(ctx);
  if(!ctx || ctx->exception)
    return false;

  if(this->_d->_currentRegionItem.count() == 0
     || this->_d->_currentStateItem.count() == 0
     || this->_d->_currentStateType.count() != this->_d->_currentStateItem.count()
     || this->_d->_currentStateType.count() == 0
     || this->_d->_currentStateType.top() != ConcurrentState){
    appendDslError(ctx->getStart(),
                   QStringLiteral("Something went wrong in Region creation!"));
    return false;
  }
  RegionItem* regionItem = this->_d->_currentRegionItem.top();
  this->_d->_currentRegionItem.pop_front();
  QString errorString = "";
  ConcurrentStateItem* item = static_cast<ConcurrentStateItem*>(_d->_currentStateItem.top());
  Q_ASSERT(item);

  if(!item->addRegion(regionItem,&errorString))
  {
    appendDslError(ctx->getStart(),
                   errorString);
    return false;
  }

  return true;
}

bool StateMachineModelListener::getItemFromPath(StateMachineParser::IdPathContext* path, ModelItem* mItem){
  this->_d->_currentPathItem = mItem;
  if(!path) return false;

  for (StateMachineParser::ContextIDContext* currContextID :
       path->contextID())
  {
    QString name = QString::fromStdString(currContextID->getText());
    if(name == "this" || name == "timeout"){
      continue;
    }
    bool isBaseModel = false;
    if(!this->_d->_currentPathItem){
      isBaseModel = !this->_d->_importItems.contains(name);
      if(!isBaseModel){
        this->_d->_currentPathItem = (ModelItem*)this->_d->_importItems.value(name);
        continue;
      }
    }
    if(isBaseModel){
      model::statemachine::StateMachineModel* item = this->_model;
      auto states = item->states();
      int sz = states.size();
      bool test = false;
      for(int i = 0;i<sz;i++){
        if(static_cast<AbstractStateItem*>(states.at(i))->name() == name){
          this->_d->_currentPathItem = static_cast<ModelItem*>(states.at(i));
          i = sz;
          test = true;
        }
      }
      auto attributes = item->attributes();
      int sz2 = attributes.size();
      for(int i = 0;i<sz2 && !test;i++){
        if(attributes.at(i)->name() == name){
          this->_d->_currentPathItem = static_cast<ModelItem*>(attributes.at(i));
          test = true;
          i = sz2;
        }
      }
      auto transitions = item->transitions();
      int sz3 = transitions.size();
      for(int i = 0;i<sz3;i++){
        if(transitions.at(i)->name() == name){
          this->_d->_currentPathItem = static_cast<ModelItem*>(transitions.at(i));
          i = sz3;
          test = true;
        }
      }
      auto compSignals = item->getSignals();
      int sz4 = compSignals.size();
      for(int i = 0;i<sz4;i++){
        if(compSignals.at(i)->name() == name){
          this->_d->_currentPathItem = static_cast<ModelItem*>(compSignals.at(i));
          i = sz4;
          test = true;
        }
      }
      if(test) {
        continue;
      }
    }
    if(SignalItem* item = dynamic_cast<SignalItem*>(this->_d->_currentPathItem)){
      auto attributes = item->params();
      int sz2 = attributes.size();
      bool test = false;
      for(int i = 0;i<sz2 && !test;i++){
        if(attributes.at(i)->name() == name){
          this->_d->_currentPathItem = static_cast<ModelItem*>(attributes.at(i));
          test = true;
        }
      }
      //If Attributes wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("No Attribute with this name!"));
        return false;
      }
    }
    else if(CompositeStateItem* item = dynamic_cast<CompositeStateItem*>(this->_d->_currentPathItem)){
      auto states = item->states();
      int sz = states.size();
      bool test = false;
      for(int i = 0;i<sz;i++){
        if(static_cast<AbstractStateItem*>(states.at(i))->name() == name){
          this->_d->_currentPathItem = static_cast<ModelItem*>(states.at(i));
          i = sz;
          test = true;
        }
      }
      //If State wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("Incorrect Path to State!"));
        return false;
      }
    }
    else{
      return false;
    }
  }
  return true;
}

void StateMachineModelListener::setInitState(PropStates* states, Token* statesToken)
{
  Q_ASSERT(states);
  Q_ASSERT(statesToken);

  if(this->_d->_currentInitState.isEmpty() || this->_d->_currentInitStateToken.isEmpty()){
    return;
  }

  Q_ASSERT(this->_d->_currentInitStateToken.top());
  Token* initToken = this->_d->_currentInitStateToken.top();
  const QString initStateName = this->_d->_currentInitState.top();
  this->_d->_currentInitStateToken.pop();
  this->_d->_currentInitState.pop();

  model::statemachine::AbstractStateItem* initItem = states->state(initStateName);
  if(initItem){
    QString errorMesage;
    if(!states->setInitState(initItem, &errorMesage)){
      appendDslError(initToken,
                     errorMesage);
      return;
    }
  }
  else{
    appendDslError(initToken,
                   QStringLiteral("Init state not found!"));
    return;
  }

  return;
}

} // namespace statemachine
} // namespace dslparser
