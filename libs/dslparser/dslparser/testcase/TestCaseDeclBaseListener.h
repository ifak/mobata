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

// Generated from C:/Users/s_phs.DESKTOP-9GA53KK/Documents/mobata/libs/dslparser/dslparser/grammars/TestCaseDecl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "TestCaseDeclListener.h"


/**
 * This class provides an empty implementation of TestCaseDeclListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TestCaseDeclBaseListener : public TestCaseDeclListener {
public:

  virtual void enterTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext * /*ctx*/) override { }
  virtual void exitTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext * /*ctx*/) override { }

  virtual void enterTestCaseBody(TestCaseDeclParser::TestCaseBodyContext * /*ctx*/) override { }
  virtual void exitTestCaseBody(TestCaseDeclParser::TestCaseBodyContext * /*ctx*/) override { }

  virtual void enterDeclarations(TestCaseDeclParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(TestCaseDeclParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterAliasDef(TestCaseDeclParser::AliasDefContext * /*ctx*/) override { }
  virtual void exitAliasDef(TestCaseDeclParser::AliasDefContext * /*ctx*/) override { }

  virtual void enterSteps(TestCaseDeclParser::StepsContext * /*ctx*/) override { }
  virtual void exitSteps(TestCaseDeclParser::StepsContext * /*ctx*/) override { }

  virtual void enterIdStatement(TestCaseDeclParser::IdStatementContext * /*ctx*/) override { }
  virtual void exitIdStatement(TestCaseDeclParser::IdStatementContext * /*ctx*/) override { }

  virtual void enterAssignmentDef(TestCaseDeclParser::AssignmentDefContext * /*ctx*/) override { }
  virtual void exitAssignmentDef(TestCaseDeclParser::AssignmentDefContext * /*ctx*/) override { }

  virtual void enterMessageDecl(TestCaseDeclParser::MessageDeclContext * /*ctx*/) override { }
  virtual void exitMessageDecl(TestCaseDeclParser::MessageDeclContext * /*ctx*/) override { }

  virtual void enterCheckDecl(TestCaseDeclParser::CheckDeclContext * /*ctx*/) override { }
  virtual void exitCheckDecl(TestCaseDeclParser::CheckDeclContext * /*ctx*/) override { }

  virtual void enterTimerDecl(TestCaseDeclParser::TimerDeclContext * /*ctx*/) override { }
  virtual void exitTimerDecl(TestCaseDeclParser::TimerDeclContext * /*ctx*/) override { }

  virtual void enterTimeOutDecl(TestCaseDeclParser::TimeOutDeclContext * /*ctx*/) override { }
  virtual void exitTimeOutDecl(TestCaseDeclParser::TimeOutDeclContext * /*ctx*/) override { }

  virtual void enterAccuracyDecl(TestCaseDeclParser::AccuracyDeclContext * /*ctx*/) override { }
  virtual void exitAccuracyDecl(TestCaseDeclParser::AccuracyDeclContext * /*ctx*/) override { }

  virtual void enterAltDecl(TestCaseDeclParser::AltDeclContext * /*ctx*/) override { }
  virtual void exitAltDecl(TestCaseDeclParser::AltDeclContext * /*ctx*/) override { }

  virtual void enterAltBody(TestCaseDeclParser::AltBodyContext * /*ctx*/) override { }
  virtual void exitAltBody(TestCaseDeclParser::AltBodyContext * /*ctx*/) override { }

  virtual void enterAltBodyOptional(TestCaseDeclParser::AltBodyOptionalContext * /*ctx*/) override { }
  virtual void exitAltBodyOptional(TestCaseDeclParser::AltBodyOptionalContext * /*ctx*/) override { }

  virtual void enterUuidDecl(TestCaseDeclParser::UuidDeclContext * /*ctx*/) override { }
  virtual void exitUuidDecl(TestCaseDeclParser::UuidDeclContext * /*ctx*/) override { }

  virtual void enterEnabledDecl(TestCaseDeclParser::EnabledDeclContext * /*ctx*/) override { }
  virtual void exitEnabledDecl(TestCaseDeclParser::EnabledDeclContext * /*ctx*/) override { }

  virtual void enterContextID(TestCaseDeclParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(TestCaseDeclParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterFunctionCall(TestCaseDeclParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(TestCaseDeclParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCall2(TestCaseDeclParser::FunctionCall2Context * /*ctx*/) override { }
  virtual void exitFunctionCall2(TestCaseDeclParser::FunctionCall2Context * /*ctx*/) override { }

  virtual void enterComponentIdPath(TestCaseDeclParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(TestCaseDeclParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(TestCaseDeclParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(TestCaseDeclParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(TestCaseDeclParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(TestCaseDeclParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(TestCaseDeclParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(TestCaseDeclParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(TestCaseDeclParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(TestCaseDeclParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(TestCaseDeclParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(TestCaseDeclParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(TestCaseDeclParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(TestCaseDeclParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(TestCaseDeclParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(TestCaseDeclParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(TestCaseDeclParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(TestCaseDeclParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(TestCaseDeclParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(TestCaseDeclParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(TestCaseDeclParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(TestCaseDeclParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(TestCaseDeclParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(TestCaseDeclParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(TestCaseDeclParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(TestCaseDeclParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(TestCaseDeclParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(TestCaseDeclParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(TestCaseDeclParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(TestCaseDeclParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(TestCaseDeclParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(TestCaseDeclParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(TestCaseDeclParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(TestCaseDeclParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(TestCaseDeclParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(TestCaseDeclParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(TestCaseDeclParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(TestCaseDeclParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(TestCaseDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(TestCaseDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(TestCaseDeclParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(TestCaseDeclParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(TestCaseDeclParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(TestCaseDeclParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(TestCaseDeclParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(TestCaseDeclParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(TestCaseDeclParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(TestCaseDeclParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(TestCaseDeclParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(TestCaseDeclParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(TestCaseDeclParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(TestCaseDeclParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(TestCaseDeclParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(TestCaseDeclParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(TestCaseDeclParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(TestCaseDeclParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(TestCaseDeclParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(TestCaseDeclParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(TestCaseDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(TestCaseDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(TestCaseDeclParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(TestCaseDeclParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(TestCaseDeclParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(TestCaseDeclParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(TestCaseDeclParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(TestCaseDeclParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(TestCaseDeclParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(TestCaseDeclParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(TestCaseDeclParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(TestCaseDeclParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(TestCaseDeclParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(TestCaseDeclParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(TestCaseDeclParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(TestCaseDeclParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(TestCaseDeclParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(TestCaseDeclParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(TestCaseDeclParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(TestCaseDeclParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(TestCaseDeclParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(TestCaseDeclParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(TestCaseDeclParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(TestCaseDeclParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(TestCaseDeclParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(TestCaseDeclParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(TestCaseDeclParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(TestCaseDeclParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(TestCaseDeclParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(TestCaseDeclParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(TestCaseDeclParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(TestCaseDeclParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(TestCaseDeclParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(TestCaseDeclParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(TestCaseDeclParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(TestCaseDeclParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(TestCaseDeclParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(TestCaseDeclParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(TestCaseDeclParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(TestCaseDeclParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(TestCaseDeclParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(TestCaseDeclParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(TestCaseDeclParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(TestCaseDeclParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(TestCaseDeclParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(TestCaseDeclParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(TestCaseDeclParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(TestCaseDeclParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(TestCaseDeclParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(TestCaseDeclParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

