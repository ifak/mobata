
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/Spenat.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SpenatParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SpenatParser.
 */
class  SpenatListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSpenatDecl(SpenatParser::SpenatDeclContext *ctx) = 0;
  virtual void exitSpenatDecl(SpenatParser::SpenatDeclContext *ctx) = 0;

  virtual void enterSpenatBody(SpenatParser::SpenatBodyContext *ctx) = 0;
  virtual void exitSpenatBody(SpenatParser::SpenatBodyContext *ctx) = 0;

  virtual void enterSpenatBodyOptional(SpenatParser::SpenatBodyOptionalContext *ctx) = 0;
  virtual void exitSpenatBodyOptional(SpenatParser::SpenatBodyOptionalContext *ctx) = 0;

  virtual void enterPlaceDecl(SpenatParser::PlaceDeclContext *ctx) = 0;
  virtual void exitPlaceDecl(SpenatParser::PlaceDeclContext *ctx) = 0;

  virtual void enterPlaceBody(SpenatParser::PlaceBodyContext *ctx) = 0;
  virtual void exitPlaceBody(SpenatParser::PlaceBodyContext *ctx) = 0;

  virtual void enterGuardDecl(SpenatParser::GuardDeclContext *ctx) = 0;
  virtual void exitGuardDecl(SpenatParser::GuardDeclContext *ctx) = 0;

  virtual void enterMultiExpression(SpenatParser::MultiExpressionContext *ctx) = 0;
  virtual void exitMultiExpression(SpenatParser::MultiExpressionContext *ctx) = 0;

  virtual void enterMultiExpressionOptional(SpenatParser::MultiExpressionOptionalContext *ctx) = 0;
  virtual void exitMultiExpressionOptional(SpenatParser::MultiExpressionOptionalContext *ctx) = 0;

  virtual void enterActionDecl(SpenatParser::ActionDeclContext *ctx) = 0;
  virtual void exitActionDecl(SpenatParser::ActionDeclContext *ctx) = 0;

  virtual void enterTransitionDecl(SpenatParser::TransitionDeclContext *ctx) = 0;
  virtual void exitTransitionDecl(SpenatParser::TransitionDeclContext *ctx) = 0;

  virtual void enterSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext *ctx) = 0;
  virtual void exitSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext *ctx) = 0;

  virtual void enterSignalTransitionBody(SpenatParser::SignalTransitionBodyContext *ctx) = 0;
  virtual void exitSignalTransitionBody(SpenatParser::SignalTransitionBodyContext *ctx) = 0;

  virtual void enterTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext *ctx) = 0;
  virtual void exitTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext *ctx) = 0;

  virtual void enterTimeoutTransitionBody(SpenatParser::TimeoutTransitionBodyContext *ctx) = 0;
  virtual void exitTimeoutTransitionBody(SpenatParser::TimeoutTransitionBodyContext *ctx) = 0;

  virtual void enterRefSignalDecl(SpenatParser::RefSignalDeclContext *ctx) = 0;
  virtual void exitRefSignalDecl(SpenatParser::RefSignalDeclContext *ctx) = 0;

  virtual void enterRefPortDecl(SpenatParser::RefPortDeclContext *ctx) = 0;
  virtual void exitRefPortDecl(SpenatParser::RefPortDeclContext *ctx) = 0;

  virtual void enterPreDecl(SpenatParser::PreDeclContext *ctx) = 0;
  virtual void exitPreDecl(SpenatParser::PreDeclContext *ctx) = 0;

  virtual void enterPostDecl(SpenatParser::PostDeclContext *ctx) = 0;
  virtual void exitPostDecl(SpenatParser::PostDeclContext *ctx) = 0;

  virtual void enterTimeoutDecl(SpenatParser::TimeoutDeclContext *ctx) = 0;
  virtual void exitTimeoutDecl(SpenatParser::TimeoutDeclContext *ctx) = 0;

  virtual void enterInitialDecl(SpenatParser::InitialDeclContext *ctx) = 0;
  virtual void exitInitialDecl(SpenatParser::InitialDeclContext *ctx) = 0;

  virtual void enterFunctionCall(SpenatParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(SpenatParser::FunctionCallContext *ctx) = 0;

  virtual void enterContextID(SpenatParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(SpenatParser::ContextIDContext *ctx) = 0;

  virtual void enterComponentIdPath(SpenatParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(SpenatParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(SpenatParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(SpenatParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(SpenatParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(SpenatParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(SpenatParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(SpenatParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(SpenatParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(SpenatParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(SpenatParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(SpenatParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(SpenatParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(SpenatParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(SpenatParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(SpenatParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(SpenatParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(SpenatParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(SpenatParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(SpenatParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(SpenatParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(SpenatParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(SpenatParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(SpenatParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(SpenatParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(SpenatParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(SpenatParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(SpenatParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(SpenatParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(SpenatParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(SpenatParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(SpenatParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(SpenatParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(SpenatParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(SpenatParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(SpenatParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(SpenatParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(SpenatParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(SpenatParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(SpenatParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(SpenatParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(SpenatParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(SpenatParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(SpenatParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(SpenatParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(SpenatParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(SpenatParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(SpenatParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(SpenatParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(SpenatParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(SpenatParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(SpenatParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(SpenatParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(SpenatParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(SpenatParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(SpenatParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCallBody(SpenatParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(SpenatParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(SpenatParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(SpenatParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(SpenatParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(SpenatParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(SpenatParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(SpenatParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(SpenatParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(SpenatParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(SpenatParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(SpenatParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(SpenatParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(SpenatParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(SpenatParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(SpenatParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(SpenatParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(SpenatParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(SpenatParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(SpenatParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(SpenatParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(SpenatParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(SpenatParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(SpenatParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(SpenatParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(SpenatParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(SpenatParser::OperationContext *ctx) = 0;
  virtual void exitOperation(SpenatParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(SpenatParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(SpenatParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(SpenatParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SpenatParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(SpenatParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(SpenatParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(SpenatParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(SpenatParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(SpenatParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(SpenatParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(SpenatParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(SpenatParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(SpenatParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(SpenatParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(SpenatParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(SpenatParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(SpenatParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(SpenatParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(SpenatParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(SpenatParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(SpenatParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(SpenatParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(SpenatParser::AtomContext *ctx) = 0;
  virtual void exitAtom(SpenatParser::AtomContext *ctx) = 0;


};

