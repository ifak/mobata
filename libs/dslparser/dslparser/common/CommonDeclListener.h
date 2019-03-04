
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/CommonDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CommonDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CommonDeclParser.
 */
class  CommonDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterComponentIdPath(CommonDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(CommonDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(CommonDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(CommonDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(CommonDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(CommonDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(CommonDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(CommonDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(CommonDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(CommonDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(CommonDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(CommonDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(CommonDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(CommonDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(CommonDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(CommonDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(CommonDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(CommonDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(CommonDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(CommonDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(CommonDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(CommonDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(CommonDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(CommonDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(CommonDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(CommonDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(CommonDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(CommonDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(CommonDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(CommonDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(CommonDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(CommonDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(CommonDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(CommonDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(CommonDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(CommonDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(CommonDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(CommonDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(CommonDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(CommonDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(CommonDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(CommonDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(CommonDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(CommonDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(CommonDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(CommonDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(CommonDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(CommonDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(CommonDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(CommonDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(CommonDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(CommonDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(CommonDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(CommonDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(CommonDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(CommonDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(CommonDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(CommonDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(CommonDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(CommonDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(CommonDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(CommonDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterContextID(CommonDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(CommonDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterTriggerDecl(CommonDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(CommonDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(CommonDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(CommonDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(CommonDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(CommonDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(CommonDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(CommonDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(CommonDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(CommonDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(CommonDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(CommonDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(CommonDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(CommonDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(CommonDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(CommonDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(CommonDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(CommonDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(CommonDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(CommonDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(CommonDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(CommonDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(CommonDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(CommonDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(CommonDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(CommonDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(CommonDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(CommonDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(CommonDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(CommonDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(CommonDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(CommonDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(CommonDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(CommonDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(CommonDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(CommonDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(CommonDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(CommonDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(CommonDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(CommonDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(CommonDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(CommonDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(CommonDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(CommonDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(CommonDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(CommonDeclParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(CommonDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(CommonDeclParser::AtomContext *ctx) = 0;


};

