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
#pragma once

#include "StateMachineBaseListener.h"
#include "../common/commonmodellistener.hpp"


#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace model{
 namespace statemachine{
  class StateMachineModel;
  class ConcurrentStateItem;
  class CompositeStateItem;
  class AbstractStateItem;
  class PropStates;
 }
 namespace base{
  class SignalTriggerItem;
 }
}

namespace dslparser {
namespace statemachine {

typedef QHash<QString, model::statemachine::StateMachineModel*> ImportModelItem;

class StateMachineModelListener
    : public common::CommonModelListener<StateMachineBaseListener, StateMachineParser, model::statemachine::StateMachineModel>
{
public:
  enum StateMachineListenerState
  {
    StateMachineDeclState = UserListenerState +1,
    StateDeclState,
    SignalTransitionDeclState,
    TimeoutTransitionDeclState,
    JunctionTransitionDeclState,
    RegionDeclState
  };

  enum StateMachineState
  {
    SimpleState = 0,
    JunctionState,
    ConcurrentState,
    CompositeState,
    FinalState
  };

public:
  StateMachineModelListener(model::statemachine::StateMachineModel* statemachineDeclModel,
                            DslErrorList* dslErrors,
                            const QString &praefix = "",
                            TokenTextLocations* keywordTextLocations = nullptr,
                            ModelTextLocations* modelTextLocations = nullptr);
  virtual ~StateMachineModelListener();

  model::base::ModelItem*                         currentPathItem();
  QScopedPointer<model::base::SignalTriggerItem>  currentTriggerSignal();
  const ImportModelItem&                          importItems();

  model::statemachine::AbstractStateItem*       currentStatePathItem();
  const model::base::SignalItem*                currentSignalItem();
protected:
  void enterStateMachineDecl(StateMachineParser::StateMachineDeclContext* ctx);
  void exitStateMachineDecl(StateMachineParser::StateMachineDeclContext* ctx);

  void enterPortDecl(StateMachineParser::PortDeclContext* ctx);
  void exitPortDecl(StateMachineParser::PortDeclContext* ctx);

  void enterTransitionDecl(StateMachineParser::TransitionDeclContext* transDeclCtx);
  void exitTransitionDecl(StateMachineParser::TransitionDeclContext* transDeclCtx);

  void enterSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext * ctx);
  void exitSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext * ctx);

  void enterTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext * ctx);
  void exitTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext * ctx);

  void enterNameDecl(StateMachineParser::NameDeclContext* ctx);
  void exitNameDecl(StateMachineParser::NameDeclContext* ctx);

  void enterRefSignalDecl(StateMachineParser::RefSignalDeclContext* ctx);
  void exitRefSignalDecl(StateMachineParser::RefSignalDeclContext* ctx);

  void enterInitStateDecl(StateMachineParser::InitStateDeclContext* ctx);
  void exitInitStateDecl(StateMachineParser::InitStateDeclContext* ctx);

  void enterTimeoutDecl(StateMachineParser::TimeoutDeclContext* ctx);
  void exitTimeoutDecl(StateMachineParser::TimeoutDeclContext* ctx);

  void enterGuardDecl(StateMachineParser::GuardDeclContext* ctx);
  void exitGuardDecl(StateMachineParser::GuardDeclContext* ctx);

  void enterActionDecl(StateMachineParser::ActionDeclContext* ctx);
  void exitActionDecl(StateMachineParser::ActionDeclContext* ctx);

  void enterSimpleStateDecl(StateMachineParser::SimpleStateDeclContext* ctx);
  void exitSimpleStateDecl(StateMachineParser::SimpleStateDeclContext* ctx);

  void enterCompositeStateDecl(StateMachineParser::CompositeStateDeclContext* ctx);
  void exitCompositeStateDecl(StateMachineParser::CompositeStateDeclContext* ctx);

  void enterJunctionStateDecl(StateMachineParser::JunctionStateDeclContext* ctx);
  void exitJunctionStateDecl(StateMachineParser::JunctionStateDeclContext* ctx);

  void enterJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext* ctx);
  void exitJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext* ctx);

  void enterFinalStateDecl(StateMachineParser::FinalStateDeclContext* ctx);
  void exitFinalStateDecl(StateMachineParser::FinalStateDeclContext* ctx);

  void enterConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext* ctx);
  void exitConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext *ctx);

  void enterRegionDecl(StateMachineParser::RegionDeclContext *ctx);
  void exitRegionDecl(StateMachineParser::RegionDeclContext *ctx);

  void enterRegionBody(StateMachineParser::RegionBodyContext *ctx);
  void exitRegionBody(StateMachineParser::RegionBodyContext *ctx);

  void enterEntryActionDecl(StateMachineParser::EntryActionDeclContext *ctx);
  void exitEntryActionDecl(StateMachineParser::EntryActionDeclContext *ctx);

  void enterExitActionDecl(StateMachineParser::ExitActionDeclContext *ctx);
  void exitExitActionDecl(StateMachineParser::ExitActionDeclContext *ctx);

  void enterSourceStateDecl(StateMachineParser::SourceStateDeclContext *ctx);
  void exitSourceStateDecl(StateMachineParser::SourceStateDeclContext *ctx);

  void enterTargetStateDecl(StateMachineParser::TargetStateDeclContext *ctx);
  void exitTargetStateDecl(StateMachineParser::TargetStateDeclContext *ctx);

  void enterImportPathBody(StateMachineParser::ImportPathBodyContext *ctx);
  void exitImportPathBody(StateMachineParser::ImportPathBodyContext *ctx);

  void enterRefPortDecl(StateMachineParser::RefPortDeclContext* ctx);
  void exitRefPortDecl(StateMachineParser::RefPortDeclContext* ctx);

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node);

private:
  bool addState(StateMachineState type,antlr4::ParserRuleContext* ctx);
  bool addRegion(antlr4::ParserRuleContext* ctx);
  bool getItemFromPath(StateMachineParser::IdPathContext *path,model::base::ModelItem* item = 0);
  void setInitState(model::statemachine::PropStates* states, antlr4::Token* statesToken);

  class Private;
  Private* _d;
};

} // namespace statemachine
} // namespace dslparser
