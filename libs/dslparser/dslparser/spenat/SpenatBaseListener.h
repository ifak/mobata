
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/Spenat.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SpenatListener.h"


/**
 * This class provides an empty implementation of SpenatListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SpenatBaseListener : public SpenatListener {
public:

  virtual void enterSpenatDecl(SpenatParser::SpenatDeclContext * /*ctx*/) override { }
  virtual void exitSpenatDecl(SpenatParser::SpenatDeclContext * /*ctx*/) override { }

  virtual void enterSpenatBody(SpenatParser::SpenatBodyContext * /*ctx*/) override { }
  virtual void exitSpenatBody(SpenatParser::SpenatBodyContext * /*ctx*/) override { }

  virtual void enterSpenatBodyOptional(SpenatParser::SpenatBodyOptionalContext * /*ctx*/) override { }
  virtual void exitSpenatBodyOptional(SpenatParser::SpenatBodyOptionalContext * /*ctx*/) override { }

  virtual void enterPlaceDecl(SpenatParser::PlaceDeclContext * /*ctx*/) override { }
  virtual void exitPlaceDecl(SpenatParser::PlaceDeclContext * /*ctx*/) override { }

  virtual void enterPlaceBody(SpenatParser::PlaceBodyContext * /*ctx*/) override { }
  virtual void exitPlaceBody(SpenatParser::PlaceBodyContext * /*ctx*/) override { }

  virtual void enterGuardDecl(SpenatParser::GuardDeclContext * /*ctx*/) override { }
  virtual void exitGuardDecl(SpenatParser::GuardDeclContext * /*ctx*/) override { }

  virtual void enterMultiExpression(SpenatParser::MultiExpressionContext * /*ctx*/) override { }
  virtual void exitMultiExpression(SpenatParser::MultiExpressionContext * /*ctx*/) override { }

  virtual void enterMultiExpressionOptional(SpenatParser::MultiExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitMultiExpressionOptional(SpenatParser::MultiExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterActionDecl(SpenatParser::ActionDeclContext * /*ctx*/) override { }
  virtual void exitActionDecl(SpenatParser::ActionDeclContext * /*ctx*/) override { }

  virtual void enterTransitionDecl(SpenatParser::TransitionDeclContext * /*ctx*/) override { }
  virtual void exitTransitionDecl(SpenatParser::TransitionDeclContext * /*ctx*/) override { }

  virtual void enterSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext * /*ctx*/) override { }
  virtual void exitSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext * /*ctx*/) override { }

  virtual void enterSignalTransitionBody(SpenatParser::SignalTransitionBodyContext * /*ctx*/) override { }
  virtual void exitSignalTransitionBody(SpenatParser::SignalTransitionBodyContext * /*ctx*/) override { }

  virtual void enterTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext * /*ctx*/) override { }
  virtual void exitTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext * /*ctx*/) override { }

  virtual void enterTimeoutTransitionBody(SpenatParser::TimeoutTransitionBodyContext * /*ctx*/) override { }
  virtual void exitTimeoutTransitionBody(SpenatParser::TimeoutTransitionBodyContext * /*ctx*/) override { }

  virtual void enterRefSignalDecl(SpenatParser::RefSignalDeclContext * /*ctx*/) override { }
  virtual void exitRefSignalDecl(SpenatParser::RefSignalDeclContext * /*ctx*/) override { }

  virtual void enterRefPortDecl(SpenatParser::RefPortDeclContext * /*ctx*/) override { }
  virtual void exitRefPortDecl(SpenatParser::RefPortDeclContext * /*ctx*/) override { }

  virtual void enterPreDecl(SpenatParser::PreDeclContext * /*ctx*/) override { }
  virtual void exitPreDecl(SpenatParser::PreDeclContext * /*ctx*/) override { }

  virtual void enterPostDecl(SpenatParser::PostDeclContext * /*ctx*/) override { }
  virtual void exitPostDecl(SpenatParser::PostDeclContext * /*ctx*/) override { }

  virtual void enterTimeoutDecl(SpenatParser::TimeoutDeclContext * /*ctx*/) override { }
  virtual void exitTimeoutDecl(SpenatParser::TimeoutDeclContext * /*ctx*/) override { }

  virtual void enterInitialDecl(SpenatParser::InitialDeclContext * /*ctx*/) override { }
  virtual void exitInitialDecl(SpenatParser::InitialDeclContext * /*ctx*/) override { }

  virtual void enterFunctionCall(SpenatParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(SpenatParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterContextID(SpenatParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(SpenatParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(SpenatParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(SpenatParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(SpenatParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(SpenatParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(SpenatParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(SpenatParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(SpenatParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(SpenatParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(SpenatParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(SpenatParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(SpenatParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(SpenatParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(SpenatParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(SpenatParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(SpenatParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(SpenatParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(SpenatParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(SpenatParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(SpenatParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(SpenatParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(SpenatParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(SpenatParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(SpenatParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(SpenatParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(SpenatParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(SpenatParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(SpenatParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(SpenatParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(SpenatParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(SpenatParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(SpenatParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(SpenatParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(SpenatParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(SpenatParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(SpenatParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(SpenatParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(SpenatParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(SpenatParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(SpenatParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(SpenatParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(SpenatParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(SpenatParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(SpenatParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(SpenatParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(SpenatParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(SpenatParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(SpenatParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(SpenatParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(SpenatParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(SpenatParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(SpenatParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(SpenatParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(SpenatParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(SpenatParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(SpenatParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(SpenatParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(SpenatParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(SpenatParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(SpenatParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(SpenatParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(SpenatParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(SpenatParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(SpenatParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(SpenatParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(SpenatParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(SpenatParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(SpenatParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(SpenatParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(SpenatParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(SpenatParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(SpenatParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(SpenatParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(SpenatParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(SpenatParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(SpenatParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(SpenatParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(SpenatParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(SpenatParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(SpenatParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(SpenatParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(SpenatParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(SpenatParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(SpenatParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(SpenatParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(SpenatParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(SpenatParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(SpenatParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SpenatParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(SpenatParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(SpenatParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(SpenatParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(SpenatParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(SpenatParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(SpenatParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(SpenatParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(SpenatParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(SpenatParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(SpenatParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(SpenatParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(SpenatParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(SpenatParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(SpenatParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(SpenatParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(SpenatParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(SpenatParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(SpenatParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(SpenatParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(SpenatParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

