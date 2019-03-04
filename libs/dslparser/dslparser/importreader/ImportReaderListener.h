
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/ImportReader.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ImportReaderParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ImportReaderParser.
 */
class  ImportReaderListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterImportReader(ImportReaderParser::ImportReaderContext *ctx) = 0;
  virtual void exitImportReader(ImportReaderParser::ImportReaderContext *ctx) = 0;

  virtual void enterComponentIdPath(ImportReaderParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(ImportReaderParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(ImportReaderParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(ImportReaderParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(ImportReaderParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(ImportReaderParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(ImportReaderParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(ImportReaderParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(ImportReaderParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(ImportReaderParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(ImportReaderParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(ImportReaderParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(ImportReaderParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(ImportReaderParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(ImportReaderParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(ImportReaderParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(ImportReaderParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(ImportReaderParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(ImportReaderParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(ImportReaderParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(ImportReaderParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(ImportReaderParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(ImportReaderParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(ImportReaderParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(ImportReaderParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(ImportReaderParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(ImportReaderParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(ImportReaderParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(ImportReaderParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(ImportReaderParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(ImportReaderParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(ImportReaderParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(ImportReaderParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(ImportReaderParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(ImportReaderParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(ImportReaderParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(ImportReaderParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(ImportReaderParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(ImportReaderParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(ImportReaderParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(ImportReaderParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(ImportReaderParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(ImportReaderParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(ImportReaderParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(ImportReaderParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(ImportReaderParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(ImportReaderParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(ImportReaderParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(ImportReaderParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(ImportReaderParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(ImportReaderParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(ImportReaderParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(ImportReaderParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(ImportReaderParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(ImportReaderParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(ImportReaderParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(ImportReaderParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(ImportReaderParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(ImportReaderParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(ImportReaderParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(ImportReaderParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(ImportReaderParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterContextID(ImportReaderParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(ImportReaderParser::ContextIDContext *ctx) = 0;

  virtual void enterTriggerDecl(ImportReaderParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(ImportReaderParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(ImportReaderParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(ImportReaderParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(ImportReaderParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(ImportReaderParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(ImportReaderParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(ImportReaderParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(ImportReaderParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(ImportReaderParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(ImportReaderParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(ImportReaderParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(ImportReaderParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(ImportReaderParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(ImportReaderParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(ImportReaderParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(ImportReaderParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(ImportReaderParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(ImportReaderParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(ImportReaderParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(ImportReaderParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(ImportReaderParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(ImportReaderParser::OperationContext *ctx) = 0;
  virtual void exitOperation(ImportReaderParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(ImportReaderParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(ImportReaderParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(ImportReaderParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(ImportReaderParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(ImportReaderParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(ImportReaderParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(ImportReaderParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(ImportReaderParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(ImportReaderParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(ImportReaderParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(ImportReaderParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(ImportReaderParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(ImportReaderParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(ImportReaderParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(ImportReaderParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(ImportReaderParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(ImportReaderParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(ImportReaderParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(ImportReaderParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(ImportReaderParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(ImportReaderParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(ImportReaderParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(ImportReaderParser::AtomContext *ctx) = 0;
  virtual void exitAtom(ImportReaderParser::AtomContext *ctx) = 0;


};

