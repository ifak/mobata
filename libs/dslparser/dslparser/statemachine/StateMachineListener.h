
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/StateMachine.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "StateMachineParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by StateMachineParser.
 */
class  StateMachineListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStateMachineDecl(StateMachineParser::StateMachineDeclContext *ctx) = 0;
  virtual void exitStateMachineDecl(StateMachineParser::StateMachineDeclContext *ctx) = 0;

  virtual void enterStateMachineBody(StateMachineParser::StateMachineBodyContext *ctx) = 0;
  virtual void exitStateMachineBody(StateMachineParser::StateMachineBodyContext *ctx) = 0;

  virtual void enterStateMachineBodyOptional(StateMachineParser::StateMachineBodyOptionalContext *ctx) = 0;
  virtual void exitStateMachineBodyOptional(StateMachineParser::StateMachineBodyOptionalContext *ctx) = 0;

  virtual void enterStateDecl(StateMachineParser::StateDeclContext *ctx) = 0;
  virtual void exitStateDecl(StateMachineParser::StateDeclContext *ctx) = 0;

  virtual void enterStateIdPath(StateMachineParser::StateIdPathContext *ctx) = 0;
  virtual void exitStateIdPath(StateMachineParser::StateIdPathContext *ctx) = 0;

  virtual void enterStateDecls(StateMachineParser::StateDeclsContext *ctx) = 0;
  virtual void exitStateDecls(StateMachineParser::StateDeclsContext *ctx) = 0;

  virtual void enterSimpleStateDecl(StateMachineParser::SimpleStateDeclContext *ctx) = 0;
  virtual void exitSimpleStateDecl(StateMachineParser::SimpleStateDeclContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(StateMachineParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(StateMachineParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterSimpleStateBody(StateMachineParser::SimpleStateBodyContext *ctx) = 0;
  virtual void exitSimpleStateBody(StateMachineParser::SimpleStateBodyContext *ctx) = 0;

  virtual void enterJunctionStateDecl(StateMachineParser::JunctionStateDeclContext *ctx) = 0;
  virtual void exitJunctionStateDecl(StateMachineParser::JunctionStateDeclContext *ctx) = 0;

  virtual void enterJunctionTransitionDecls(StateMachineParser::JunctionTransitionDeclsContext *ctx) = 0;
  virtual void exitJunctionTransitionDecls(StateMachineParser::JunctionTransitionDeclsContext *ctx) = 0;

  virtual void enterJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext *ctx) = 0;
  virtual void exitJunctionTransitionDecl(StateMachineParser::JunctionTransitionDeclContext *ctx) = 0;

  virtual void enterJunctionTransitionBody(StateMachineParser::JunctionTransitionBodyContext *ctx) = 0;
  virtual void exitJunctionTransitionBody(StateMachineParser::JunctionTransitionBodyContext *ctx) = 0;

  virtual void enterConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext *ctx) = 0;
  virtual void exitConcurrentStateDecl(StateMachineParser::ConcurrentStateDeclContext *ctx) = 0;

  virtual void enterConcurrentStateBody(StateMachineParser::ConcurrentStateBodyContext *ctx) = 0;
  virtual void exitConcurrentStateBody(StateMachineParser::ConcurrentStateBodyContext *ctx) = 0;

  virtual void enterRegionDecl(StateMachineParser::RegionDeclContext *ctx) = 0;
  virtual void exitRegionDecl(StateMachineParser::RegionDeclContext *ctx) = 0;

  virtual void enterRegionDecls(StateMachineParser::RegionDeclsContext *ctx) = 0;
  virtual void exitRegionDecls(StateMachineParser::RegionDeclsContext *ctx) = 0;

  virtual void enterRegionBody(StateMachineParser::RegionBodyContext *ctx) = 0;
  virtual void exitRegionBody(StateMachineParser::RegionBodyContext *ctx) = 0;

  virtual void enterCompositeStateDecl(StateMachineParser::CompositeStateDeclContext *ctx) = 0;
  virtual void exitCompositeStateDecl(StateMachineParser::CompositeStateDeclContext *ctx) = 0;

  virtual void enterCompositeStateBody(StateMachineParser::CompositeStateBodyContext *ctx) = 0;
  virtual void exitCompositeStateBody(StateMachineParser::CompositeStateBodyContext *ctx) = 0;

  virtual void enterFinalStateDecl(StateMachineParser::FinalStateDeclContext *ctx) = 0;
  virtual void exitFinalStateDecl(StateMachineParser::FinalStateDeclContext *ctx) = 0;

  virtual void enterInitStateDecl(StateMachineParser::InitStateDeclContext *ctx) = 0;
  virtual void exitInitStateDecl(StateMachineParser::InitStateDeclContext *ctx) = 0;

  virtual void enterGuardDecl(StateMachineParser::GuardDeclContext *ctx) = 0;
  virtual void exitGuardDecl(StateMachineParser::GuardDeclContext *ctx) = 0;

  virtual void enterActionDecl(StateMachineParser::ActionDeclContext *ctx) = 0;
  virtual void exitActionDecl(StateMachineParser::ActionDeclContext *ctx) = 0;

  virtual void enterActionStatementBody(StateMachineParser::ActionStatementBodyContext *ctx) = 0;
  virtual void exitActionStatementBody(StateMachineParser::ActionStatementBodyContext *ctx) = 0;

  virtual void enterContextIDStatements(StateMachineParser::ContextIDStatementsContext *ctx) = 0;
  virtual void exitContextIDStatements(StateMachineParser::ContextIDStatementsContext *ctx) = 0;

  virtual void enterActionStatementBodies(StateMachineParser::ActionStatementBodiesContext *ctx) = 0;
  virtual void exitActionStatementBodies(StateMachineParser::ActionStatementBodiesContext *ctx) = 0;

  virtual void enterActionNestedStatementBody(StateMachineParser::ActionNestedStatementBodyContext *ctx) = 0;
  virtual void exitActionNestedStatementBody(StateMachineParser::ActionNestedStatementBodyContext *ctx) = 0;

  virtual void enterTransitionDecl(StateMachineParser::TransitionDeclContext *ctx) = 0;
  virtual void exitTransitionDecl(StateMachineParser::TransitionDeclContext *ctx) = 0;

  virtual void enterSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext *ctx) = 0;
  virtual void exitSignalTransitionDecl(StateMachineParser::SignalTransitionDeclContext *ctx) = 0;

  virtual void enterSignalTransitionBody(StateMachineParser::SignalTransitionBodyContext *ctx) = 0;
  virtual void exitSignalTransitionBody(StateMachineParser::SignalTransitionBodyContext *ctx) = 0;

  virtual void enterTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext *ctx) = 0;
  virtual void exitTimeoutTransitionDecl(StateMachineParser::TimeoutTransitionDeclContext *ctx) = 0;

  virtual void enterTimeoutTransitionBody(StateMachineParser::TimeoutTransitionBodyContext *ctx) = 0;
  virtual void exitTimeoutTransitionBody(StateMachineParser::TimeoutTransitionBodyContext *ctx) = 0;

  virtual void enterRefSignalDecl(StateMachineParser::RefSignalDeclContext *ctx) = 0;
  virtual void exitRefSignalDecl(StateMachineParser::RefSignalDeclContext *ctx) = 0;

  virtual void enterRefPortDecl(StateMachineParser::RefPortDeclContext *ctx) = 0;
  virtual void exitRefPortDecl(StateMachineParser::RefPortDeclContext *ctx) = 0;

  virtual void enterEntryActionDecl(StateMachineParser::EntryActionDeclContext *ctx) = 0;
  virtual void exitEntryActionDecl(StateMachineParser::EntryActionDeclContext *ctx) = 0;

  virtual void enterExitActionDecl(StateMachineParser::ExitActionDeclContext *ctx) = 0;
  virtual void exitExitActionDecl(StateMachineParser::ExitActionDeclContext *ctx) = 0;

  virtual void enterTimeoutDecl(StateMachineParser::TimeoutDeclContext *ctx) = 0;
  virtual void exitTimeoutDecl(StateMachineParser::TimeoutDeclContext *ctx) = 0;

  virtual void enterSourceStateDecl(StateMachineParser::SourceStateDeclContext *ctx) = 0;
  virtual void exitSourceStateDecl(StateMachineParser::SourceStateDeclContext *ctx) = 0;

  virtual void enterTargetStateDecl(StateMachineParser::TargetStateDeclContext *ctx) = 0;
  virtual void exitTargetStateDecl(StateMachineParser::TargetStateDeclContext *ctx) = 0;

  virtual void enterContextID(StateMachineParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(StateMachineParser::ContextIDContext *ctx) = 0;

  virtual void enterComponentIdPath(StateMachineParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(StateMachineParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(StateMachineParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(StateMachineParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(StateMachineParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(StateMachineParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(StateMachineParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(StateMachineParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(StateMachineParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(StateMachineParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(StateMachineParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(StateMachineParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(StateMachineParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(StateMachineParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(StateMachineParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(StateMachineParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(StateMachineParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(StateMachineParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(StateMachineParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(StateMachineParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(StateMachineParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(StateMachineParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(StateMachineParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(StateMachineParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(StateMachineParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(StateMachineParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(StateMachineParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(StateMachineParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(StateMachineParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(StateMachineParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(StateMachineParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(StateMachineParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(StateMachineParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(StateMachineParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(StateMachineParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(StateMachineParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(StateMachineParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(StateMachineParser::ToPortNameContext *ctx) = 0;

  virtual void enterLocalAssignStatement(StateMachineParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(StateMachineParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(StateMachineParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(StateMachineParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(StateMachineParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(StateMachineParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(StateMachineParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(StateMachineParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(StateMachineParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(StateMachineParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(StateMachineParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(StateMachineParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(StateMachineParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(StateMachineParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(StateMachineParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(StateMachineParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(StateMachineParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(StateMachineParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(StateMachineParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(StateMachineParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(StateMachineParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(StateMachineParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(StateMachineParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(StateMachineParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(StateMachineParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(StateMachineParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(StateMachineParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(StateMachineParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(StateMachineParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(StateMachineParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(StateMachineParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(StateMachineParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(StateMachineParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(StateMachineParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(StateMachineParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(StateMachineParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(StateMachineParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(StateMachineParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(StateMachineParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(StateMachineParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(StateMachineParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(StateMachineParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(StateMachineParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(StateMachineParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(StateMachineParser::OperationContext *ctx) = 0;
  virtual void exitOperation(StateMachineParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(StateMachineParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(StateMachineParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(StateMachineParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(StateMachineParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(StateMachineParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(StateMachineParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(StateMachineParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(StateMachineParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(StateMachineParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(StateMachineParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(StateMachineParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(StateMachineParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(StateMachineParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(StateMachineParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(StateMachineParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(StateMachineParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(StateMachineParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(StateMachineParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(StateMachineParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(StateMachineParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(StateMachineParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(StateMachineParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(StateMachineParser::AtomContext *ctx) = 0;
  virtual void exitAtom(StateMachineParser::AtomContext *ctx) = 0;


};

