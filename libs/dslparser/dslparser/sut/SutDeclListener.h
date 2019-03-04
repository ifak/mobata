
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/SutDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SutDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SutDeclParser.
 */
class  SutDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSutDecl(SutDeclParser::SutDeclContext *ctx) = 0;
  virtual void exitSutDecl(SutDeclParser::SutDeclContext *ctx) = 0;

  virtual void enterSutBody(SutDeclParser::SutBodyContext *ctx) = 0;
  virtual void exitSutBody(SutDeclParser::SutBodyContext *ctx) = 0;

  virtual void enterSutBodyOptional(SutDeclParser::SutBodyOptionalContext *ctx) = 0;
  virtual void exitSutBodyOptional(SutDeclParser::SutBodyOptionalContext *ctx) = 0;

  virtual void enterSutCompDecl(SutDeclParser::SutCompDeclContext *ctx) = 0;
  virtual void exitSutCompDecl(SutDeclParser::SutCompDeclContext *ctx) = 0;

  virtual void enterSutCompBody(SutDeclParser::SutCompBodyContext *ctx) = 0;
  virtual void exitSutCompBody(SutDeclParser::SutCompBodyContext *ctx) = 0;

  virtual void enterSutCompBodyOtional(SutDeclParser::SutCompBodyOtionalContext *ctx) = 0;
  virtual void exitSutCompBodyOtional(SutDeclParser::SutCompBodyOtionalContext *ctx) = 0;

  virtual void enterContextID(SutDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(SutDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterComponentIdPath(SutDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(SutDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(SutDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(SutDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(SutDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(SutDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(SutDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(SutDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(SutDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(SutDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(SutDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(SutDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(SutDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(SutDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(SutDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(SutDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(SutDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(SutDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(SutDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(SutDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(SutDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(SutDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(SutDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(SutDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(SutDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(SutDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(SutDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(SutDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(SutDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(SutDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(SutDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(SutDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(SutDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(SutDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(SutDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(SutDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(SutDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(SutDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(SutDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(SutDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(SutDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(SutDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(SutDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(SutDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(SutDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(SutDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(SutDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(SutDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(SutDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(SutDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(SutDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(SutDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(SutDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(SutDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(SutDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(SutDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(SutDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(SutDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(SutDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(SutDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(SutDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(SutDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(SutDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(SutDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(SutDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(SutDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(SutDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(SutDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(SutDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(SutDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(SutDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(SutDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(SutDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(SutDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(SutDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(SutDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(SutDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(SutDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(SutDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(SutDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(SutDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(SutDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(SutDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(SutDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(SutDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(SutDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(SutDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(SutDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(SutDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SutDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(SutDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(SutDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(SutDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(SutDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(SutDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(SutDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(SutDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(SutDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(SutDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(SutDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(SutDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(SutDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(SutDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(SutDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(SutDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(SutDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(SutDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(SutDeclParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(SutDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(SutDeclParser::AtomContext *ctx) = 0;


};

