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
#include "IsrdlParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by IsrdlParser.
 */
class  IsrdlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSecRequirement(IsrdlParser::SecRequirementContext *ctx) = 0;
  virtual void exitSecRequirement(IsrdlParser::SecRequirementContext *ctx) = 0;

  virtual void enterAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext *ctx) = 0;
  virtual void exitAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext *ctx) = 0;

  virtual void enterAttackImpactDecl(IsrdlParser::AttackImpactDeclContext *ctx) = 0;
  virtual void exitAttackImpactDecl(IsrdlParser::AttackImpactDeclContext *ctx) = 0;

  virtual void enterAttackVectorDecl(IsrdlParser::AttackVectorDeclContext *ctx) = 0;
  virtual void exitAttackVectorDecl(IsrdlParser::AttackVectorDeclContext *ctx) = 0;

  virtual void enterAttackVectorEnum(IsrdlParser::AttackVectorEnumContext *ctx) = 0;
  virtual void exitAttackVectorEnum(IsrdlParser::AttackVectorEnumContext *ctx) = 0;

  virtual void enterAttackPrivileges(IsrdlParser::AttackPrivilegesContext *ctx) = 0;
  virtual void exitAttackPrivileges(IsrdlParser::AttackPrivilegesContext *ctx) = 0;

  virtual void enterPrivilegesEnum(IsrdlParser::PrivilegesEnumContext *ctx) = 0;
  virtual void exitPrivilegesEnum(IsrdlParser::PrivilegesEnumContext *ctx) = 0;

  virtual void enterConfidentialityThreatDecl(IsrdlParser::ConfidentialityThreatDeclContext *ctx) = 0;
  virtual void exitConfidentialityThreatDecl(IsrdlParser::ConfidentialityThreatDeclContext *ctx) = 0;

  virtual void enterConfidentialityEnum(IsrdlParser::ConfidentialityEnumContext *ctx) = 0;
  virtual void exitConfidentialityEnum(IsrdlParser::ConfidentialityEnumContext *ctx) = 0;

  virtual void enterIntegrityThreatDecl(IsrdlParser::IntegrityThreatDeclContext *ctx) = 0;
  virtual void exitIntegrityThreatDecl(IsrdlParser::IntegrityThreatDeclContext *ctx) = 0;

  virtual void enterIntegrityEnum(IsrdlParser::IntegrityEnumContext *ctx) = 0;
  virtual void exitIntegrityEnum(IsrdlParser::IntegrityEnumContext *ctx) = 0;

  virtual void enterAvailabilityThreatDecl(IsrdlParser::AvailabilityThreatDeclContext *ctx) = 0;
  virtual void exitAvailabilityThreatDecl(IsrdlParser::AvailabilityThreatDeclContext *ctx) = 0;

  virtual void enterNameDecl(IsrdlParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(IsrdlParser::NameDeclContext *ctx) = 0;

  virtual void enterComponentIdPath(IsrdlParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(IsrdlParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(IsrdlParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(IsrdlParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(IsrdlParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(IsrdlParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(IsrdlParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(IsrdlParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(IsrdlParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(IsrdlParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(IsrdlParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(IsrdlParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(IsrdlParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(IsrdlParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(IsrdlParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(IsrdlParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(IsrdlParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(IsrdlParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(IsrdlParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(IsrdlParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(IsrdlParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(IsrdlParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(IsrdlParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(IsrdlParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(IsrdlParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(IsrdlParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(IsrdlParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(IsrdlParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(IsrdlParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(IsrdlParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(IsrdlParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(IsrdlParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(IsrdlParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(IsrdlParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(IsrdlParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(IsrdlParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(IsrdlParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(IsrdlParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(IsrdlParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(IsrdlParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(IsrdlParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(IsrdlParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(IsrdlParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(IsrdlParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(IsrdlParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(IsrdlParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(IsrdlParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(IsrdlParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(IsrdlParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(IsrdlParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(IsrdlParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(IsrdlParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(IsrdlParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(IsrdlParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(IsrdlParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(IsrdlParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(IsrdlParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(IsrdlParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(IsrdlParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(IsrdlParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(IsrdlParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(IsrdlParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterContextID(IsrdlParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(IsrdlParser::ContextIDContext *ctx) = 0;

  virtual void enterTriggerDecl(IsrdlParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(IsrdlParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(IsrdlParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(IsrdlParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(IsrdlParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(IsrdlParser::PortDeclContext *ctx) = 0;

  virtual void enterIdPath(IsrdlParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(IsrdlParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(IsrdlParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(IsrdlParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(IsrdlParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(IsrdlParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(IsrdlParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(IsrdlParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(IsrdlParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(IsrdlParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(IsrdlParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(IsrdlParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(IsrdlParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(IsrdlParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(IsrdlParser::OperationContext *ctx) = 0;
  virtual void exitOperation(IsrdlParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(IsrdlParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(IsrdlParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(IsrdlParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(IsrdlParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(IsrdlParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(IsrdlParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(IsrdlParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(IsrdlParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(IsrdlParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(IsrdlParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(IsrdlParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(IsrdlParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(IsrdlParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(IsrdlParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(IsrdlParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(IsrdlParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(IsrdlParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(IsrdlParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(IsrdlParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(IsrdlParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(IsrdlParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(IsrdlParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(IsrdlParser::AtomContext *ctx) = 0;
  virtual void exitAtom(IsrdlParser::AtomContext *ctx) = 0;


};

