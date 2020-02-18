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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/ImportReader.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ImportReaderListener.h"


/**
 * This class provides an empty implementation of ImportReaderListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ImportReaderBaseListener : public ImportReaderListener {
public:

  virtual void enterImportReader(ImportReaderParser::ImportReaderContext * /*ctx*/) override { }
  virtual void exitImportReader(ImportReaderParser::ImportReaderContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(ImportReaderParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(ImportReaderParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(ImportReaderParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(ImportReaderParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(ImportReaderParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(ImportReaderParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(ImportReaderParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(ImportReaderParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(ImportReaderParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(ImportReaderParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(ImportReaderParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(ImportReaderParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(ImportReaderParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(ImportReaderParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(ImportReaderParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(ImportReaderParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(ImportReaderParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(ImportReaderParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(ImportReaderParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(ImportReaderParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(ImportReaderParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(ImportReaderParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(ImportReaderParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(ImportReaderParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(ImportReaderParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(ImportReaderParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(ImportReaderParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(ImportReaderParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(ImportReaderParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(ImportReaderParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(ImportReaderParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(ImportReaderParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(ImportReaderParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(ImportReaderParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(ImportReaderParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(ImportReaderParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(ImportReaderParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(ImportReaderParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(ImportReaderParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(ImportReaderParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(ImportReaderParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(ImportReaderParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(ImportReaderParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(ImportReaderParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(ImportReaderParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(ImportReaderParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(ImportReaderParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(ImportReaderParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(ImportReaderParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(ImportReaderParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(ImportReaderParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(ImportReaderParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(ImportReaderParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(ImportReaderParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(ImportReaderParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(ImportReaderParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(ImportReaderParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(ImportReaderParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(ImportReaderParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(ImportReaderParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(ImportReaderParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(ImportReaderParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterContextID(ImportReaderParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(ImportReaderParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(ImportReaderParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(ImportReaderParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(ImportReaderParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(ImportReaderParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(ImportReaderParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(ImportReaderParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(ImportReaderParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(ImportReaderParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(ImportReaderParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(ImportReaderParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(ImportReaderParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(ImportReaderParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(ImportReaderParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(ImportReaderParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(ImportReaderParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(ImportReaderParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(ImportReaderParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(ImportReaderParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(ImportReaderParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(ImportReaderParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(ImportReaderParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(ImportReaderParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(ImportReaderParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(ImportReaderParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(ImportReaderParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(ImportReaderParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(ImportReaderParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ImportReaderParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(ImportReaderParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(ImportReaderParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(ImportReaderParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(ImportReaderParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(ImportReaderParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(ImportReaderParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(ImportReaderParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(ImportReaderParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(ImportReaderParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(ImportReaderParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(ImportReaderParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(ImportReaderParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(ImportReaderParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(ImportReaderParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(ImportReaderParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(ImportReaderParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(ImportReaderParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(ImportReaderParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(ImportReaderParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(ImportReaderParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

