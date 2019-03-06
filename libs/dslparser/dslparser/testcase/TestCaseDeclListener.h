
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/TestCaseDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "TestCaseDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TestCaseDeclParser.
 */
class  TestCaseDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext *ctx) = 0;
  virtual void exitTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext *ctx) = 0;

  virtual void enterTestCaseBody(TestCaseDeclParser::TestCaseBodyContext *ctx) = 0;
  virtual void exitTestCaseBody(TestCaseDeclParser::TestCaseBodyContext *ctx) = 0;

  virtual void enterDeclarations(TestCaseDeclParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(TestCaseDeclParser::DeclarationsContext *ctx) = 0;

  virtual void enterAliasDef(TestCaseDeclParser::AliasDefContext *ctx) = 0;
  virtual void exitAliasDef(TestCaseDeclParser::AliasDefContext *ctx) = 0;

  virtual void enterSteps(TestCaseDeclParser::StepsContext *ctx) = 0;
  virtual void exitSteps(TestCaseDeclParser::StepsContext *ctx) = 0;

  virtual void enterIdStatement(TestCaseDeclParser::IdStatementContext *ctx) = 0;
  virtual void exitIdStatement(TestCaseDeclParser::IdStatementContext *ctx) = 0;

  virtual void enterAssignmentDef(TestCaseDeclParser::AssignmentDefContext *ctx) = 0;
  virtual void exitAssignmentDef(TestCaseDeclParser::AssignmentDefContext *ctx) = 0;

  virtual void enterMessageDecl(TestCaseDeclParser::MessageDeclContext *ctx) = 0;
  virtual void exitMessageDecl(TestCaseDeclParser::MessageDeclContext *ctx) = 0;

  virtual void enterCheckDecl(TestCaseDeclParser::CheckDeclContext *ctx) = 0;
  virtual void exitCheckDecl(TestCaseDeclParser::CheckDeclContext *ctx) = 0;

  virtual void enterCheckDeclBody(TestCaseDeclParser::CheckDeclBodyContext *ctx) = 0;
  virtual void exitCheckDeclBody(TestCaseDeclParser::CheckDeclBodyContext *ctx) = 0;

  virtual void enterTimerDecl(TestCaseDeclParser::TimerDeclContext *ctx) = 0;
  virtual void exitTimerDecl(TestCaseDeclParser::TimerDeclContext *ctx) = 0;

  virtual void enterTimeOutDecl(TestCaseDeclParser::TimeOutDeclContext *ctx) = 0;
  virtual void exitTimeOutDecl(TestCaseDeclParser::TimeOutDeclContext *ctx) = 0;

  virtual void enterAltDecl(TestCaseDeclParser::AltDeclContext *ctx) = 0;
  virtual void exitAltDecl(TestCaseDeclParser::AltDeclContext *ctx) = 0;

  virtual void enterAltBody(TestCaseDeclParser::AltBodyContext *ctx) = 0;
  virtual void exitAltBody(TestCaseDeclParser::AltBodyContext *ctx) = 0;

  virtual void enterAltBodyOptional(TestCaseDeclParser::AltBodyOptionalContext *ctx) = 0;
  virtual void exitAltBodyOptional(TestCaseDeclParser::AltBodyOptionalContext *ctx) = 0;

  virtual void enterEnabledDecl(TestCaseDeclParser::EnabledDeclContext *ctx) = 0;
  virtual void exitEnabledDecl(TestCaseDeclParser::EnabledDeclContext *ctx) = 0;

  virtual void enterContextID(TestCaseDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(TestCaseDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterFunctionCall(TestCaseDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(TestCaseDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterComponentIdPath(TestCaseDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(TestCaseDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(TestCaseDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(TestCaseDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(TestCaseDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(TestCaseDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(TestCaseDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(TestCaseDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(TestCaseDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(TestCaseDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(TestCaseDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(TestCaseDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(TestCaseDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(TestCaseDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(TestCaseDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(TestCaseDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(TestCaseDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(TestCaseDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(TestCaseDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(TestCaseDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(TestCaseDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(TestCaseDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(TestCaseDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(TestCaseDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(TestCaseDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(TestCaseDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(TestCaseDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(TestCaseDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(TestCaseDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(TestCaseDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(TestCaseDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(TestCaseDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(TestCaseDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(TestCaseDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(TestCaseDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(TestCaseDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(TestCaseDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(TestCaseDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(TestCaseDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(TestCaseDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(TestCaseDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(TestCaseDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(TestCaseDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(TestCaseDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(TestCaseDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(TestCaseDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(TestCaseDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(TestCaseDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(TestCaseDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(TestCaseDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(TestCaseDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(TestCaseDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(TestCaseDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(TestCaseDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(TestCaseDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(TestCaseDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCallBody(TestCaseDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(TestCaseDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(TestCaseDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(TestCaseDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(TestCaseDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(TestCaseDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(TestCaseDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(TestCaseDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(TestCaseDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(TestCaseDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(TestCaseDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(TestCaseDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(TestCaseDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(TestCaseDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(TestCaseDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(TestCaseDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(TestCaseDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(TestCaseDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(TestCaseDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(TestCaseDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(TestCaseDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(TestCaseDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(TestCaseDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(TestCaseDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(TestCaseDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(TestCaseDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(TestCaseDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(TestCaseDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(TestCaseDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(TestCaseDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(TestCaseDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(TestCaseDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(TestCaseDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(TestCaseDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(TestCaseDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(TestCaseDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(TestCaseDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(TestCaseDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(TestCaseDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(TestCaseDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(TestCaseDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(TestCaseDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(TestCaseDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(TestCaseDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(TestCaseDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(TestCaseDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(TestCaseDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(TestCaseDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(TestCaseDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(TestCaseDeclParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(TestCaseDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(TestCaseDeclParser::AtomContext *ctx) = 0;


};

