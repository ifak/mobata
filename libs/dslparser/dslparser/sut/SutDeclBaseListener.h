
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/SutDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SutDeclListener.h"


/**
 * This class provides an empty implementation of SutDeclListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SutDeclBaseListener : public SutDeclListener {
public:

  virtual void enterSutDecl(SutDeclParser::SutDeclContext * /*ctx*/) override { }
  virtual void exitSutDecl(SutDeclParser::SutDeclContext * /*ctx*/) override { }

  virtual void enterSutBody(SutDeclParser::SutBodyContext * /*ctx*/) override { }
  virtual void exitSutBody(SutDeclParser::SutBodyContext * /*ctx*/) override { }

  virtual void enterSutBodyOptional(SutDeclParser::SutBodyOptionalContext * /*ctx*/) override { }
  virtual void exitSutBodyOptional(SutDeclParser::SutBodyOptionalContext * /*ctx*/) override { }

  virtual void enterSutCompDecl(SutDeclParser::SutCompDeclContext * /*ctx*/) override { }
  virtual void exitSutCompDecl(SutDeclParser::SutCompDeclContext * /*ctx*/) override { }

  virtual void enterSutCompBody(SutDeclParser::SutCompBodyContext * /*ctx*/) override { }
  virtual void exitSutCompBody(SutDeclParser::SutCompBodyContext * /*ctx*/) override { }

  virtual void enterSutCompBodyOtional(SutDeclParser::SutCompBodyOtionalContext * /*ctx*/) override { }
  virtual void exitSutCompBodyOtional(SutDeclParser::SutCompBodyOtionalContext * /*ctx*/) override { }

  virtual void enterContextID(SutDeclParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(SutDeclParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(SutDeclParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(SutDeclParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(SutDeclParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(SutDeclParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(SutDeclParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(SutDeclParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(SutDeclParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(SutDeclParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(SutDeclParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(SutDeclParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(SutDeclParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(SutDeclParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(SutDeclParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(SutDeclParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(SutDeclParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(SutDeclParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(SutDeclParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(SutDeclParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(SutDeclParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(SutDeclParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(SutDeclParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(SutDeclParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(SutDeclParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(SutDeclParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(SutDeclParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(SutDeclParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(SutDeclParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(SutDeclParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(SutDeclParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(SutDeclParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(SutDeclParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(SutDeclParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(SutDeclParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(SutDeclParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(SutDeclParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(SutDeclParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(SutDeclParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(SutDeclParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(SutDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(SutDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(SutDeclParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(SutDeclParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(SutDeclParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(SutDeclParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(SutDeclParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(SutDeclParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(SutDeclParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(SutDeclParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(SutDeclParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(SutDeclParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(SutDeclParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(SutDeclParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(SutDeclParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(SutDeclParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(SutDeclParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(SutDeclParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(SutDeclParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(SutDeclParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(SutDeclParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(SutDeclParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(SutDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(SutDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(SutDeclParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(SutDeclParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(SutDeclParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(SutDeclParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(SutDeclParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(SutDeclParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(SutDeclParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(SutDeclParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(SutDeclParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(SutDeclParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(SutDeclParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(SutDeclParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(SutDeclParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(SutDeclParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(SutDeclParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(SutDeclParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(SutDeclParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(SutDeclParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(SutDeclParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(SutDeclParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(SutDeclParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(SutDeclParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(SutDeclParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(SutDeclParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(SutDeclParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(SutDeclParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(SutDeclParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SutDeclParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(SutDeclParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(SutDeclParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(SutDeclParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(SutDeclParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(SutDeclParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(SutDeclParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(SutDeclParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(SutDeclParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(SutDeclParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(SutDeclParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(SutDeclParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(SutDeclParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(SutDeclParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(SutDeclParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(SutDeclParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(SutDeclParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(SutDeclParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(SutDeclParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(SutDeclParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(SutDeclParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

