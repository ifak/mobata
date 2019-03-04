
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/TestSystemDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "TestSystemDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TestSystemDeclParser.
 */
class  TestSystemDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTestSystemDecl(TestSystemDeclParser::TestSystemDeclContext *ctx) = 0;
  virtual void exitTestSystemDecl(TestSystemDeclParser::TestSystemDeclContext *ctx) = 0;

  virtual void enterTestSystemBody(TestSystemDeclParser::TestSystemBodyContext *ctx) = 0;
  virtual void exitTestSystemBody(TestSystemDeclParser::TestSystemBodyContext *ctx) = 0;

  virtual void enterTestSystemBodyOptional(TestSystemDeclParser::TestSystemBodyOptionalContext *ctx) = 0;
  virtual void exitTestSystemBodyOptional(TestSystemDeclParser::TestSystemBodyOptionalContext *ctx) = 0;

  virtual void enterTestCompDecl(TestSystemDeclParser::TestCompDeclContext *ctx) = 0;
  virtual void exitTestCompDecl(TestSystemDeclParser::TestCompDeclContext *ctx) = 0;

  virtual void enterTestCompBody(TestSystemDeclParser::TestCompBodyContext *ctx) = 0;
  virtual void exitTestCompBody(TestSystemDeclParser::TestCompBodyContext *ctx) = 0;

  virtual void enterEnabledDecl(TestSystemDeclParser::EnabledDeclContext *ctx) = 0;
  virtual void exitEnabledDecl(TestSystemDeclParser::EnabledDeclContext *ctx) = 0;

  virtual void enterTestCompBodyOtional(TestSystemDeclParser::TestCompBodyOtionalContext *ctx) = 0;
  virtual void exitTestCompBodyOtional(TestSystemDeclParser::TestCompBodyOtionalContext *ctx) = 0;

  virtual void enterLinkDecls(TestSystemDeclParser::LinkDeclsContext *ctx) = 0;
  virtual void exitLinkDecls(TestSystemDeclParser::LinkDeclsContext *ctx) = 0;

  virtual void enterLinkDecl(TestSystemDeclParser::LinkDeclContext *ctx) = 0;
  virtual void exitLinkDecl(TestSystemDeclParser::LinkDeclContext *ctx) = 0;

  virtual void enterLinkBody(TestSystemDeclParser::LinkBodyContext *ctx) = 0;
  virtual void exitLinkBody(TestSystemDeclParser::LinkBodyContext *ctx) = 0;

  virtual void enterLabelDecl(TestSystemDeclParser::LabelDeclContext *ctx) = 0;
  virtual void exitLabelDecl(TestSystemDeclParser::LabelDeclContext *ctx) = 0;

  virtual void enterTargetDecl(TestSystemDeclParser::TargetDeclContext *ctx) = 0;
  virtual void exitTargetDecl(TestSystemDeclParser::TargetDeclContext *ctx) = 0;

  virtual void enterSourceDecl(TestSystemDeclParser::SourceDeclContext *ctx) = 0;
  virtual void exitSourceDecl(TestSystemDeclParser::SourceDeclContext *ctx) = 0;

  virtual void enterContextID(TestSystemDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(TestSystemDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterComponentIdPath(TestSystemDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(TestSystemDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(TestSystemDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(TestSystemDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(TestSystemDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(TestSystemDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(TestSystemDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(TestSystemDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(TestSystemDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(TestSystemDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(TestSystemDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(TestSystemDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(TestSystemDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(TestSystemDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(TestSystemDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(TestSystemDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(TestSystemDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(TestSystemDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(TestSystemDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(TestSystemDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(TestSystemDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(TestSystemDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(TestSystemDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(TestSystemDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(TestSystemDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(TestSystemDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(TestSystemDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(TestSystemDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(TestSystemDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(TestSystemDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(TestSystemDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(TestSystemDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(TestSystemDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(TestSystemDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(TestSystemDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(TestSystemDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(TestSystemDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(TestSystemDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(TestSystemDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(TestSystemDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(TestSystemDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(TestSystemDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(TestSystemDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(TestSystemDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(TestSystemDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(TestSystemDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(TestSystemDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(TestSystemDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(TestSystemDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(TestSystemDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(TestSystemDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(TestSystemDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(TestSystemDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(TestSystemDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(TestSystemDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(TestSystemDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(TestSystemDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(TestSystemDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(TestSystemDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(TestSystemDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(TestSystemDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(TestSystemDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(TestSystemDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(TestSystemDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(TestSystemDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(TestSystemDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(TestSystemDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(TestSystemDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(TestSystemDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(TestSystemDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(TestSystemDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(TestSystemDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(TestSystemDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(TestSystemDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(TestSystemDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(TestSystemDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(TestSystemDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(TestSystemDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(TestSystemDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(TestSystemDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(TestSystemDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(TestSystemDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(TestSystemDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(TestSystemDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(TestSystemDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(TestSystemDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(TestSystemDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(TestSystemDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(TestSystemDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(TestSystemDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(TestSystemDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(TestSystemDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(TestSystemDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(TestSystemDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(TestSystemDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(TestSystemDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(TestSystemDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(TestSystemDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(TestSystemDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(TestSystemDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(TestSystemDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(TestSystemDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(TestSystemDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(TestSystemDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(TestSystemDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(TestSystemDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(TestSystemDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(TestSystemDeclParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(TestSystemDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(TestSystemDeclParser::AtomContext *ctx) = 0;


};

