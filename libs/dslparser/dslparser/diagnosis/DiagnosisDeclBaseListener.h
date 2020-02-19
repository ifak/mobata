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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/DiagnosisDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "DiagnosisDeclListener.h"


/**
 * This class provides an empty implementation of DiagnosisDeclListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DiagnosisDeclBaseListener : public DiagnosisDeclListener {
public:

  virtual void enterDiagnosisDecl(DiagnosisDeclParser::DiagnosisDeclContext * /*ctx*/) override { }
  virtual void exitDiagnosisDecl(DiagnosisDeclParser::DiagnosisDeclContext * /*ctx*/) override { }

  virtual void enterRulesDecl(DiagnosisDeclParser::RulesDeclContext * /*ctx*/) override { }
  virtual void exitRulesDecl(DiagnosisDeclParser::RulesDeclContext * /*ctx*/) override { }

  virtual void enterRuleDecl(DiagnosisDeclParser::RuleDeclContext * /*ctx*/) override { }
  virtual void exitRuleDecl(DiagnosisDeclParser::RuleDeclContext * /*ctx*/) override { }

  virtual void enterRuleBody(DiagnosisDeclParser::RuleBodyContext * /*ctx*/) override { }
  virtual void exitRuleBody(DiagnosisDeclParser::RuleBodyContext * /*ctx*/) override { }

  virtual void enterDescriptionDecl(DiagnosisDeclParser::DescriptionDeclContext * /*ctx*/) override { }
  virtual void exitDescriptionDecl(DiagnosisDeclParser::DescriptionDeclContext * /*ctx*/) override { }

  virtual void enterDeclarations(DiagnosisDeclParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(DiagnosisDeclParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterComponentsDecl(DiagnosisDeclParser::ComponentsDeclContext * /*ctx*/) override { }
  virtual void exitComponentsDecl(DiagnosisDeclParser::ComponentsDeclContext * /*ctx*/) override { }

  virtual void enterComponentsBody(DiagnosisDeclParser::ComponentsBodyContext * /*ctx*/) override { }
  virtual void exitComponentsBody(DiagnosisDeclParser::ComponentsBodyContext * /*ctx*/) override { }

  virtual void enterComponentDecl(DiagnosisDeclParser::ComponentDeclContext * /*ctx*/) override { }
  virtual void exitComponentDecl(DiagnosisDeclParser::ComponentDeclContext * /*ctx*/) override { }

  virtual void enterComponentBody(DiagnosisDeclParser::ComponentBodyContext * /*ctx*/) override { }
  virtual void exitComponentBody(DiagnosisDeclParser::ComponentBodyContext * /*ctx*/) override { }

  virtual void enterDiagnosisSignalsDecl(DiagnosisDeclParser::DiagnosisSignalsDeclContext * /*ctx*/) override { }
  virtual void exitDiagnosisSignalsDecl(DiagnosisDeclParser::DiagnosisSignalsDeclContext * /*ctx*/) override { }

  virtual void enterDiagnosisSignalsBody(DiagnosisDeclParser::DiagnosisSignalsBodyContext * /*ctx*/) override { }
  virtual void exitDiagnosisSignalsBody(DiagnosisDeclParser::DiagnosisSignalsBodyContext * /*ctx*/) override { }

  virtual void enterDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext * /*ctx*/) override { }
  virtual void exitDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext * /*ctx*/) override { }

  virtual void enterDiagnosisSignalBody(DiagnosisDeclParser::DiagnosisSignalBodyContext * /*ctx*/) override { }
  virtual void exitDiagnosisSignalBody(DiagnosisDeclParser::DiagnosisSignalBodyContext * /*ctx*/) override { }

  virtual void enterBaseTypeDecl(DiagnosisDeclParser::BaseTypeDeclContext * /*ctx*/) override { }
  virtual void exitBaseTypeDecl(DiagnosisDeclParser::BaseTypeDeclContext * /*ctx*/) override { }

  virtual void enterCheckDecl(DiagnosisDeclParser::CheckDeclContext * /*ctx*/) override { }
  virtual void exitCheckDecl(DiagnosisDeclParser::CheckDeclContext * /*ctx*/) override { }

  virtual void enterAliasDef(DiagnosisDeclParser::AliasDefContext * /*ctx*/) override { }
  virtual void exitAliasDef(DiagnosisDeclParser::AliasDefContext * /*ctx*/) override { }

  virtual void enterSequenceDecl(DiagnosisDeclParser::SequenceDeclContext * /*ctx*/) override { }
  virtual void exitSequenceDecl(DiagnosisDeclParser::SequenceDeclContext * /*ctx*/) override { }

  virtual void enterSequenceBody(DiagnosisDeclParser::SequenceBodyContext * /*ctx*/) override { }
  virtual void exitSequenceBody(DiagnosisDeclParser::SequenceBodyContext * /*ctx*/) override { }

  virtual void enterMessageDecl(DiagnosisDeclParser::MessageDeclContext * /*ctx*/) override { }
  virtual void exitMessageDecl(DiagnosisDeclParser::MessageDeclContext * /*ctx*/) override { }

  virtual void enterExpression(DiagnosisDeclParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(DiagnosisDeclParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(DiagnosisDeclParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(DiagnosisDeclParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterAtom(DiagnosisDeclParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(DiagnosisDeclParser::AtomContext * /*ctx*/) override { }

  virtual void enterLoopDecl(DiagnosisDeclParser::LoopDeclContext * /*ctx*/) override { }
  virtual void exitLoopDecl(DiagnosisDeclParser::LoopDeclContext * /*ctx*/) override { }

  virtual void enterParallelDecl(DiagnosisDeclParser::ParallelDeclContext * /*ctx*/) override { }
  virtual void exitParallelDecl(DiagnosisDeclParser::ParallelDeclContext * /*ctx*/) override { }

  virtual void enterParallelBodys(DiagnosisDeclParser::ParallelBodysContext * /*ctx*/) override { }
  virtual void exitParallelBodys(DiagnosisDeclParser::ParallelBodysContext * /*ctx*/) override { }

  virtual void enterParallelBody(DiagnosisDeclParser::ParallelBodyContext * /*ctx*/) override { }
  virtual void exitParallelBody(DiagnosisDeclParser::ParallelBodyContext * /*ctx*/) override { }

  virtual void enterEnabledDecl(DiagnosisDeclParser::EnabledDeclContext * /*ctx*/) override { }
  virtual void exitEnabledDecl(DiagnosisDeclParser::EnabledDeclContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(DiagnosisDeclParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(DiagnosisDeclParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(DiagnosisDeclParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(DiagnosisDeclParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(DiagnosisDeclParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(DiagnosisDeclParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(DiagnosisDeclParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(DiagnosisDeclParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(DiagnosisDeclParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(DiagnosisDeclParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(DiagnosisDeclParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(DiagnosisDeclParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(DiagnosisDeclParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(DiagnosisDeclParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(DiagnosisDeclParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(DiagnosisDeclParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(DiagnosisDeclParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(DiagnosisDeclParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(DiagnosisDeclParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(DiagnosisDeclParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(DiagnosisDeclParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(DiagnosisDeclParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(DiagnosisDeclParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(DiagnosisDeclParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(DiagnosisDeclParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(DiagnosisDeclParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(DiagnosisDeclParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(DiagnosisDeclParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(DiagnosisDeclParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(DiagnosisDeclParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(DiagnosisDeclParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(DiagnosisDeclParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(DiagnosisDeclParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(DiagnosisDeclParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(DiagnosisDeclParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(DiagnosisDeclParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(DiagnosisDeclParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(DiagnosisDeclParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(DiagnosisDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(DiagnosisDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(DiagnosisDeclParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(DiagnosisDeclParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(DiagnosisDeclParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(DiagnosisDeclParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(DiagnosisDeclParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(DiagnosisDeclParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(DiagnosisDeclParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(DiagnosisDeclParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(DiagnosisDeclParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(DiagnosisDeclParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(DiagnosisDeclParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(DiagnosisDeclParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(DiagnosisDeclParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(DiagnosisDeclParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(DiagnosisDeclParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(DiagnosisDeclParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(DiagnosisDeclParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(DiagnosisDeclParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(DiagnosisDeclParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(DiagnosisDeclParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(DiagnosisDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(DiagnosisDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterContextID(DiagnosisDeclParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(DiagnosisDeclParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(DiagnosisDeclParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(DiagnosisDeclParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(DiagnosisDeclParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(DiagnosisDeclParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(DiagnosisDeclParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(DiagnosisDeclParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(DiagnosisDeclParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(DiagnosisDeclParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(DiagnosisDeclParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(DiagnosisDeclParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(DiagnosisDeclParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(DiagnosisDeclParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(DiagnosisDeclParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(DiagnosisDeclParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(DiagnosisDeclParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(DiagnosisDeclParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(DiagnosisDeclParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(DiagnosisDeclParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(DiagnosisDeclParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(DiagnosisDeclParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(DiagnosisDeclParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(DiagnosisDeclParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(DiagnosisDeclParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(DiagnosisDeclParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(DiagnosisDeclParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(DiagnosisDeclParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(DiagnosisDeclParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(DiagnosisDeclParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(DiagnosisDeclParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(DiagnosisDeclParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(DiagnosisDeclParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(DiagnosisDeclParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(DiagnosisDeclParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(DiagnosisDeclParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(DiagnosisDeclParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(DiagnosisDeclParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(DiagnosisDeclParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(DiagnosisDeclParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(DiagnosisDeclParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(DiagnosisDeclParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(DiagnosisDeclParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(DiagnosisDeclParser::DefaultStatementContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

