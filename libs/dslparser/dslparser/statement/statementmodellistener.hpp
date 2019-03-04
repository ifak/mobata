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

#include "common/CommonDeclBaseListener.h"
#include "../common/commonmodellistener.hpp"

#undef emit
#include <antlr4-runtime.h>

#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

using namespace antlr4;

namespace model{ namespace base{ namespace statement{
class StatementModel;
class RootStatementModel;
class ConcurrentStateItem;
class CompositeStateItem;
class AbstractStateItem;
}}

namespace statemachine {
class StateMachineModel;
}
}

namespace dslparser {
namespace base {

typedef QHash<QString, model::base::statement::StatementModel*> ImportModelItem;

class StatementModelListener
    : public common::CommonModelListener<CommonDeclBaseListener, CommonDeclParser, model::base::statement::RootStatementModel>
{
public:
  enum StatementListenerState
  {
    StatementDeclState = UserListenerState +1,
    StateDeclState,
    TransitionDeclState,
    JunctionTransitionDeclState,
    RegionDeclState
  };

  enum StatementState
  {
    SimpleState = 0,
    JunctionState,
    ConcurrentState,
    CompositeState,
    FinalState
  };

public:
  StatementModelListener(model::base::statement::RootStatementModel *statementDeclModel,
                            DslErrorList* dslErrors,
                            model::statemachine::StateMachineModel const* wholeModel,
                            const QString &praefix = "");
  virtual ~StatementModelListener();

  void                                          setTokenStream(CommonTokenStream* stream);
  model::base::ModelItem*                       currentPathItem();
  const ImportModelItem&                        importItems();

protected:
  void exitAttributeAssignStatement(CommonDeclParser::AttributeAssignStatementContext * ctx) override;
  void exitFunctionCallStatement(CommonDeclParser::FunctionCallStatementContext * ctx) override;
  void exitBreakStatement(CommonDeclParser::BreakStatementContext * ctx) override;
  void enterConditionalStatement(CommonDeclParser::ConditionalStatementContext * ctx) override;
  void exitConditionalStatement(CommonDeclParser::ConditionalStatementContext * ctx) override;
  void exitSwitchPuT(CommonDeclParser::SwitchPuTContext * ctx) override;

  void exitIfEuT(CommonDeclParser::IfEuTContext * ctx) override;
  void enterElseStatement(CommonDeclParser::ElseStatementContext * ctx) override;
  void enterSwitchStatement(CommonDeclParser::SwitchStatementContext *ctx) override;
  void exitSwitchStatement(CommonDeclParser::SwitchStatementContext *ctx) override;

  void exitSendToStatement(CommonDeclParser::SendToStatementContext *ctx) override;
protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node);

private:

  class Private;
  Private* _d;
};

} // namespace base
} // namespace dslparser
