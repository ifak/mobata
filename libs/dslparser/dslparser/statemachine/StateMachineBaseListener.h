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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/StateMachine.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "StateMachineListener.h"


/**
 * This class provides an empty implementation of StateMachineListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  StateMachineBaseListener : public StateMachineListener {
public:

  virtual void enterStateMachineDecl(StateMachineParser::StateMachineDeclContext * /*ctx*/) override { }
  virtual void exitStateMachineDecl(StateMachineParser::StateMachineDeclContext * /*ctx*/) override { }

  virtual void enterStateMachineBody(StateMachineParser::StateMachineBodyContext * /*ctx*/) override { }
  virtual void exitStateMachineBody(StateMachineParser::StateMachineBodyContext * /*ctx*/) override { }

  virtual void enterStateMachineBodyOptional(StateMachineParser::StateMachineBodyOptionalContext * /*ctx*/) override { }
  virtual void exitStateMachineBodyOptional(StateMachineParser::StateMachineBodyOptionalContext * /*ctx*/) override { }

  virtual void enterStateDecl(StateMachineParser::StateDeclContext * /*ctx*/) override { }
  virtual void exitStateDecl(StateMachineParser::StateDeclContext * /*ctx*/) override { }

  virtual void enterStateIdPath(StateMachineParser::StateIdPathContext * /*ctx*/) override { }
  virtual void exitStateIdPath(StateMachineParser::StateIdPathContext * /*ctx*/) override { }

  virtual void enterStateDecls(StateMachineParser::StateDeclsContext * /*ctx*/) override { }
  virtual void exitStateDecls(StateMachineParser::StateDeclsContext * /*ctx*/) override { }

  virtual void enterSimpleStateDecl(StateMachineParser::SimpleStateDeclContext * /*ctx*/) override { }
  virtual void exitSimpleStateDecl(StateMachineParser::SimpleStateDeclContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(StateMachineParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(StateMachineParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterSimpleStateBody(StateMachineParser::SimpleStateBodyContext * /*ctx*/) override { }
  virtual void exitSimpleStateBody(StateMachineParser::SimpleStateBodyContext * /*ctx*/) override { }

  virtual void enterJunctionStateDecl(StateMachineParser::JunctionStateDeclContext * /*ctx*/) override { }
  virtual void exitJunctionStateDecl(StateMachineParser::JunctionStateDeclContext * /*ctx*/) override { }

  virtual void enterJunctionTransitionDecls(StateMachineParser::JunctionTransitionDeclsContext * /*ctx*/) override { }
  virtual void exitJunctionTransitionDecls(StateMachineParser::JunctionTransitionDeclsContext * /*ctx*/) override { }

  virtual void enterJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext * /*ctx*/) override { }
  virtual void exitJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext * /*ctx*/) override { }

  virtual void enterJunctionTransitionBody(StateMachineParser::JunctionTransitionBodyContext * /*ctx*/) override { }
  virtual void exitJunctionTransitionBody(StateMachineParser::JunctionTransitionBodyContext * /*ctx*/) override { }

  virtual void enterConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext * /*ctx*/) override { }
  virtual void exitConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext * /*ctx*/) override { }

  virtual void enterConcurrentStateBody(StateMachineParser::ConcurrentStateBodyContext * /*ctx*/) override { }
  virtual void exitConcurrentStateBody(StateMachineParser::ConcurrentStateBodyContext * /*ctx*/) override { }

  virtual void enterRegionDecl(StateMachineParser::RegionDeclContext * /*ctx*/) override { }
  virtual void exitRegionDecl(StateMachineParser::RegionDeclContext * /*ctx*/) override { }

  virtual void enterRegionDecls(StateMachineParser::RegionDeclsContext * /*ctx*/) override { }
  virtual void exitRegionDecls(StateMachineParser::RegionDeclsContext * /*ctx*/) override { }

  virtual void enterRegionBody(StateMachineParser::RegionBodyContext * /*ctx*/) override { }
  virtual void exitRegionBody(StateMachineParser::RegionBodyContext * /*ctx*/) override { }

  virtual void enterCompositeStateDecl(StateMachineParser::CompositeStateDeclContext * /*ctx*/) override { }
  virtual void exitCompositeStateDecl(StateMachineParser::CompositeStateDeclContext * /*ctx*/) override { }

  virtual void enterCompositeStateBody(StateMachineParser::CompositeStateBodyContext * /*ctx*/) override { }
  virtual void exitCompositeStateBody(StateMachineParser::CompositeStateBodyContext * /*ctx*/) override { }

  virtual void enterFinalStateDecl(StateMachineParser::FinalStateDeclContext * /*ctx*/) override { }
  virtual void exitFinalStateDecl(StateMachineParser::FinalStateDeclContext * /*ctx*/) override { }

  virtual void enterInitStateDecl(StateMachineParser::InitStateDeclContext * /*ctx*/) override { }
  virtual void exitInitStateDecl(StateMachineParser::InitStateDeclContext * /*ctx*/) override { }

  virtual void enterGuardDecl(StateMachineParser::GuardDeclContext * /*ctx*/) override { }
  virtual void exitGuardDecl(StateMachineParser::GuardDeclContext * /*ctx*/) override { }

  virtual void enterActionDecl(StateMachineParser::ActionDeclContext * /*ctx*/) override { }
  virtual void exitActionDecl(StateMachineParser::ActionDeclContext * /*ctx*/) override { }

  virtual void enterActionStatementBody(StateMachineParser::ActionStatementBodyContext * /*ctx*/) override { }
  virtual void exitActionStatementBody(StateMachineParser::ActionStatementBodyContext * /*ctx*/) override { }

  virtual void enterContextIDStatements(StateMachineParser::ContextIDStatementsContext * /*ctx*/) override { }
  virtual void exitContextIDStatements(StateMachineParser::ContextIDStatementsContext * /*ctx*/) override { }

  virtual void enterActionStatementBodies(StateMachineParser::ActionStatementBodiesContext * /*ctx*/) override { }
  virtual void exitActionStatementBodies(StateMachineParser::ActionStatementBodiesContext * /*ctx*/) override { }

  virtual void enterActionNestedStatementBody(StateMachineParser::ActionNestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitActionNestedStatementBody(StateMachineParser::ActionNestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterTransitionDecl(StateMachineParser::TransitionDeclContext * /*ctx*/) override { }
  virtual void exitTransitionDecl(StateMachineParser::TransitionDeclContext * /*ctx*/) override { }

  virtual void enterSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext * /*ctx*/) override { }
  virtual void exitSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext * /*ctx*/) override { }

  virtual void enterSignalTransitionBody(StateMachineParser::SignalTransitionBodyContext * /*ctx*/) override { }
  virtual void exitSignalTransitionBody(StateMachineParser::SignalTransitionBodyContext * /*ctx*/) override { }

  virtual void enterTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext * /*ctx*/) override { }
  virtual void exitTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext * /*ctx*/) override { }

  virtual void enterTimeoutTransitionBody(StateMachineParser::TimeoutTransitionBodyContext * /*ctx*/) override { }
  virtual void exitTimeoutTransitionBody(StateMachineParser::TimeoutTransitionBodyContext * /*ctx*/) override { }

  virtual void enterRefSignalDecl(StateMachineParser::RefSignalDeclContext * /*ctx*/) override { }
  virtual void exitRefSignalDecl(StateMachineParser::RefSignalDeclContext * /*ctx*/) override { }

  virtual void enterRefPortDecl(StateMachineParser::RefPortDeclContext * /*ctx*/) override { }
  virtual void exitRefPortDecl(StateMachineParser::RefPortDeclContext * /*ctx*/) override { }

  virtual void enterEntryActionDecl(StateMachineParser::EntryActionDeclContext * /*ctx*/) override { }
  virtual void exitEntryActionDecl(StateMachineParser::EntryActionDeclContext * /*ctx*/) override { }

  virtual void enterExitActionDecl(StateMachineParser::ExitActionDeclContext * /*ctx*/) override { }
  virtual void exitExitActionDecl(StateMachineParser::ExitActionDeclContext * /*ctx*/) override { }

  virtual void enterTimeoutDecl(StateMachineParser::TimeoutDeclContext * /*ctx*/) override { }
  virtual void exitTimeoutDecl(StateMachineParser::TimeoutDeclContext * /*ctx*/) override { }

  virtual void enterSourceStateDecl(StateMachineParser::SourceStateDeclContext * /*ctx*/) override { }
  virtual void exitSourceStateDecl(StateMachineParser::SourceStateDeclContext * /*ctx*/) override { }

  virtual void enterTargetStateDecl(StateMachineParser::TargetStateDeclContext * /*ctx*/) override { }
  virtual void exitTargetStateDecl(StateMachineParser::TargetStateDeclContext * /*ctx*/) override { }

  virtual void enterContextID(StateMachineParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(StateMachineParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(StateMachineParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(StateMachineParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(StateMachineParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(StateMachineParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(StateMachineParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(StateMachineParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(StateMachineParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(StateMachineParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(StateMachineParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(StateMachineParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(StateMachineParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(StateMachineParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(StateMachineParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(StateMachineParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(StateMachineParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(StateMachineParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(StateMachineParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(StateMachineParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(StateMachineParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(StateMachineParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(StateMachineParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(StateMachineParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(StateMachineParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(StateMachineParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(StateMachineParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(StateMachineParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(StateMachineParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(StateMachineParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(StateMachineParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(StateMachineParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(StateMachineParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(StateMachineParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(StateMachineParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(StateMachineParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(StateMachineParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(StateMachineParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(StateMachineParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(StateMachineParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(StateMachineParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(StateMachineParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(StateMachineParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(StateMachineParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(StateMachineParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(StateMachineParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(StateMachineParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(StateMachineParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(StateMachineParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(StateMachineParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(StateMachineParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(StateMachineParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(StateMachineParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(StateMachineParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(StateMachineParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(StateMachineParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(StateMachineParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(StateMachineParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(StateMachineParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(StateMachineParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(StateMachineParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(StateMachineParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(StateMachineParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(StateMachineParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(StateMachineParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(StateMachineParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(StateMachineParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(StateMachineParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(StateMachineParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(StateMachineParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(StateMachineParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(StateMachineParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(StateMachineParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(StateMachineParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(StateMachineParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(StateMachineParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(StateMachineParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(StateMachineParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(StateMachineParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(StateMachineParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(StateMachineParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(StateMachineParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(StateMachineParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(StateMachineParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(StateMachineParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(StateMachineParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(StateMachineParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(StateMachineParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(StateMachineParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(StateMachineParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(StateMachineParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(StateMachineParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(StateMachineParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(StateMachineParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(StateMachineParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(StateMachineParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(StateMachineParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(StateMachineParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(StateMachineParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(StateMachineParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(StateMachineParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(StateMachineParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(StateMachineParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(StateMachineParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(StateMachineParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(StateMachineParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(StateMachineParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(StateMachineParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(StateMachineParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(StateMachineParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

