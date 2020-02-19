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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/Isrdl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "IsrdlListener.h"


/**
 * This class provides an empty implementation of IsrdlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  IsrdlBaseListener : public IsrdlListener {
public:

  virtual void enterSecRequirement(IsrdlParser::SecRequirementContext * /*ctx*/) override { }
  virtual void exitSecRequirement(IsrdlParser::SecRequirementContext * /*ctx*/) override { }

  virtual void enterAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext * /*ctx*/) override { }
  virtual void exitAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext * /*ctx*/) override { }

  virtual void enterAttackImpactDecl(IsrdlParser::AttackImpactDeclContext * /*ctx*/) override { }
  virtual void exitAttackImpactDecl(IsrdlParser::AttackImpactDeclContext * /*ctx*/) override { }

  virtual void enterAttackVectorDecl(IsrdlParser::AttackVectorDeclContext * /*ctx*/) override { }
  virtual void exitAttackVectorDecl(IsrdlParser::AttackVectorDeclContext * /*ctx*/) override { }

  virtual void enterAttackVectorEnum(IsrdlParser::AttackVectorEnumContext * /*ctx*/) override { }
  virtual void exitAttackVectorEnum(IsrdlParser::AttackVectorEnumContext * /*ctx*/) override { }

  virtual void enterAttackPrivileges(IsrdlParser::AttackPrivilegesContext * /*ctx*/) override { }
  virtual void exitAttackPrivileges(IsrdlParser::AttackPrivilegesContext * /*ctx*/) override { }

  virtual void enterPrivilegesEnum(IsrdlParser::PrivilegesEnumContext * /*ctx*/) override { }
  virtual void exitPrivilegesEnum(IsrdlParser::PrivilegesEnumContext * /*ctx*/) override { }

  virtual void enterConfidentialityThreatDecl(IsrdlParser::ConfidentialityThreatDeclContext * /*ctx*/) override { }
  virtual void exitConfidentialityThreatDecl(IsrdlParser::ConfidentialityThreatDeclContext * /*ctx*/) override { }

  virtual void enterConfidentialityEnum(IsrdlParser::ConfidentialityEnumContext * /*ctx*/) override { }
  virtual void exitConfidentialityEnum(IsrdlParser::ConfidentialityEnumContext * /*ctx*/) override { }

  virtual void enterIntegrityThreatDecl(IsrdlParser::IntegrityThreatDeclContext * /*ctx*/) override { }
  virtual void exitIntegrityThreatDecl(IsrdlParser::IntegrityThreatDeclContext * /*ctx*/) override { }

  virtual void enterIntegrityEnum(IsrdlParser::IntegrityEnumContext * /*ctx*/) override { }
  virtual void exitIntegrityEnum(IsrdlParser::IntegrityEnumContext * /*ctx*/) override { }

  virtual void enterAvailabilityThreatDecl(IsrdlParser::AvailabilityThreatDeclContext * /*ctx*/) override { }
  virtual void exitAvailabilityThreatDecl(IsrdlParser::AvailabilityThreatDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(IsrdlParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(IsrdlParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(IsrdlParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(IsrdlParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(IsrdlParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(IsrdlParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(IsrdlParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(IsrdlParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(IsrdlParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(IsrdlParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(IsrdlParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(IsrdlParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(IsrdlParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(IsrdlParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(IsrdlParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(IsrdlParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(IsrdlParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(IsrdlParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(IsrdlParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(IsrdlParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(IsrdlParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(IsrdlParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(IsrdlParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(IsrdlParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(IsrdlParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(IsrdlParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(IsrdlParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(IsrdlParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(IsrdlParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(IsrdlParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(IsrdlParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(IsrdlParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(IsrdlParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(IsrdlParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(IsrdlParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(IsrdlParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(IsrdlParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(IsrdlParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(IsrdlParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(IsrdlParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(IsrdlParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(IsrdlParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(IsrdlParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(IsrdlParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(IsrdlParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(IsrdlParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(IsrdlParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(IsrdlParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(IsrdlParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(IsrdlParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(IsrdlParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(IsrdlParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(IsrdlParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(IsrdlParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(IsrdlParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(IsrdlParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(IsrdlParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(IsrdlParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(IsrdlParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(IsrdlParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(IsrdlParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(IsrdlParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(IsrdlParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(IsrdlParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterContextID(IsrdlParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(IsrdlParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(IsrdlParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(IsrdlParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(IsrdlParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(IsrdlParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(IsrdlParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(IsrdlParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(IsrdlParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(IsrdlParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(IsrdlParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(IsrdlParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(IsrdlParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(IsrdlParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(IsrdlParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(IsrdlParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(IsrdlParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(IsrdlParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(IsrdlParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(IsrdlParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(IsrdlParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(IsrdlParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(IsrdlParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(IsrdlParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(IsrdlParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(IsrdlParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(IsrdlParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(IsrdlParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(IsrdlParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(IsrdlParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(IsrdlParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(IsrdlParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(IsrdlParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(IsrdlParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(IsrdlParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(IsrdlParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(IsrdlParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(IsrdlParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(IsrdlParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(IsrdlParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(IsrdlParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(IsrdlParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(IsrdlParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(IsrdlParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(IsrdlParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(IsrdlParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(IsrdlParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(IsrdlParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

