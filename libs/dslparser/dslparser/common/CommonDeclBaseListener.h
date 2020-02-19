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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/CommonDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CommonDeclListener.h"


/**
 * This class provides an empty implementation of CommonDeclListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CommonDeclBaseListener : public CommonDeclListener {
public:

  virtual void enterComponentIdPath(CommonDeclParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(CommonDeclParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(CommonDeclParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(CommonDeclParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(CommonDeclParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(CommonDeclParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(CommonDeclParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(CommonDeclParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(CommonDeclParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(CommonDeclParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(CommonDeclParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(CommonDeclParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(CommonDeclParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(CommonDeclParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(CommonDeclParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(CommonDeclParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(CommonDeclParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(CommonDeclParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(CommonDeclParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(CommonDeclParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(CommonDeclParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(CommonDeclParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(CommonDeclParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(CommonDeclParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(CommonDeclParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(CommonDeclParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(CommonDeclParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(CommonDeclParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(CommonDeclParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(CommonDeclParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(CommonDeclParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(CommonDeclParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(CommonDeclParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(CommonDeclParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(CommonDeclParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(CommonDeclParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(CommonDeclParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(CommonDeclParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(CommonDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(CommonDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(CommonDeclParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(CommonDeclParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(CommonDeclParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(CommonDeclParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(CommonDeclParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(CommonDeclParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(CommonDeclParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(CommonDeclParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(CommonDeclParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(CommonDeclParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(CommonDeclParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(CommonDeclParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(CommonDeclParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(CommonDeclParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(CommonDeclParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(CommonDeclParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(CommonDeclParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(CommonDeclParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(CommonDeclParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(CommonDeclParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(CommonDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(CommonDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterContextID(CommonDeclParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(CommonDeclParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(CommonDeclParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(CommonDeclParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(CommonDeclParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(CommonDeclParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(CommonDeclParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(CommonDeclParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(CommonDeclParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(CommonDeclParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(CommonDeclParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(CommonDeclParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(CommonDeclParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(CommonDeclParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(CommonDeclParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(CommonDeclParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(CommonDeclParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(CommonDeclParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(CommonDeclParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(CommonDeclParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(CommonDeclParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(CommonDeclParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(CommonDeclParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(CommonDeclParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(CommonDeclParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(CommonDeclParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(CommonDeclParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(CommonDeclParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(CommonDeclParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(CommonDeclParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(CommonDeclParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(CommonDeclParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(CommonDeclParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(CommonDeclParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(CommonDeclParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(CommonDeclParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(CommonDeclParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(CommonDeclParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(CommonDeclParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(CommonDeclParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(CommonDeclParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(CommonDeclParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(CommonDeclParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(CommonDeclParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(CommonDeclParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(CommonDeclParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(CommonDeclParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(CommonDeclParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(CommonDeclParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(CommonDeclParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

