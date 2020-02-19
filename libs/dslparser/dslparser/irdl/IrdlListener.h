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

// Generated from /home/sebastian/Documents/Git/MbtCreator/3rd/mobata/libs/dslparser/dslparser/grammars/Irdl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "IrdlParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by IrdlParser.
 */
class  IrdlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTimerNameID(IrdlParser::TimerNameIDContext *ctx) = 0;
  virtual void exitTimerNameID(IrdlParser::TimerNameIDContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(IrdlParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(IrdlParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterAtom(IrdlParser::AtomContext *ctx) = 0;
  virtual void exitAtom(IrdlParser::AtomContext *ctx) = 0;

  virtual void enterIrdlDecl(IrdlParser::IrdlDeclContext *ctx) = 0;
  virtual void exitIrdlDecl(IrdlParser::IrdlDeclContext *ctx) = 0;

  virtual void enterRequirementBody(IrdlParser::RequirementBodyContext *ctx) = 0;
  virtual void exitRequirementBody(IrdlParser::RequirementBodyContext *ctx) = 0;

  virtual void enterAliasDef(IrdlParser::AliasDefContext *ctx) = 0;
  virtual void exitAliasDef(IrdlParser::AliasDefContext *ctx) = 0;

  virtual void enterDeclarations(IrdlParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(IrdlParser::DeclarationsContext *ctx) = 0;

  virtual void enterComponentDecl(IrdlParser::ComponentDeclContext *ctx) = 0;
  virtual void exitComponentDecl(IrdlParser::ComponentDeclContext *ctx) = 0;

  virtual void enterComponentBody(IrdlParser::ComponentBodyContext *ctx) = 0;
  virtual void exitComponentBody(IrdlParser::ComponentBodyContext *ctx) = 0;

  virtual void enterActorDecl(IrdlParser::ActorDeclContext *ctx) = 0;
  virtual void exitActorDecl(IrdlParser::ActorDeclContext *ctx) = 0;

  virtual void enterActorBody(IrdlParser::ActorBodyContext *ctx) = 0;
  virtual void exitActorBody(IrdlParser::ActorBodyContext *ctx) = 0;

  virtual void enterDescriptionDecl(IrdlParser::DescriptionDeclContext *ctx) = 0;
  virtual void exitDescriptionDecl(IrdlParser::DescriptionDeclContext *ctx) = 0;

  virtual void enterSequenceDecl(IrdlParser::SequenceDeclContext *ctx) = 0;
  virtual void exitSequenceDecl(IrdlParser::SequenceDeclContext *ctx) = 0;

  virtual void enterStateDecl(IrdlParser::StateDeclContext *ctx) = 0;
  virtual void exitStateDecl(IrdlParser::StateDeclContext *ctx) = 0;

  virtual void enterLifelineList(IrdlParser::LifelineListContext *ctx) = 0;
  virtual void exitLifelineList(IrdlParser::LifelineListContext *ctx) = 0;

  virtual void enterLifelineListOptional(IrdlParser::LifelineListOptionalContext *ctx) = 0;
  virtual void exitLifelineListOptional(IrdlParser::LifelineListOptionalContext *ctx) = 0;

  virtual void enterMessageSignal(IrdlParser::MessageSignalContext *ctx) = 0;
  virtual void exitMessageSignal(IrdlParser::MessageSignalContext *ctx) = 0;

  virtual void enterMessageSignalBody(IrdlParser::MessageSignalBodyContext *ctx) = 0;
  virtual void exitMessageSignalBody(IrdlParser::MessageSignalBodyContext *ctx) = 0;

  virtual void enterMessageSignalBodyOptional(IrdlParser::MessageSignalBodyOptionalContext *ctx) = 0;
  virtual void exitMessageSignalBodyOptional(IrdlParser::MessageSignalBodyOptionalContext *ctx) = 0;

  virtual void enterMessageDecl(IrdlParser::MessageDeclContext *ctx) = 0;
  virtual void exitMessageDecl(IrdlParser::MessageDeclContext *ctx) = 0;

  virtual void enterCheckDecl(IrdlParser::CheckDeclContext *ctx) = 0;
  virtual void exitCheckDecl(IrdlParser::CheckDeclContext *ctx) = 0;

  virtual void enterCheckDeclBody(IrdlParser::CheckDeclBodyContext *ctx) = 0;
  virtual void exitCheckDeclBody(IrdlParser::CheckDeclBodyContext *ctx) = 0;

  virtual void enterTimerDecl(IrdlParser::TimerDeclContext *ctx) = 0;
  virtual void exitTimerDecl(IrdlParser::TimerDeclContext *ctx) = 0;

  virtual void enterAttributeAssign(IrdlParser::AttributeAssignContext *ctx) = 0;
  virtual void exitAttributeAssign(IrdlParser::AttributeAssignContext *ctx) = 0;

  virtual void enterTimeOutDecl(IrdlParser::TimeOutDeclContext *ctx) = 0;
  virtual void exitTimeOutDecl(IrdlParser::TimeOutDeclContext *ctx) = 0;

  virtual void enterAltDecl(IrdlParser::AltDeclContext *ctx) = 0;
  virtual void exitAltDecl(IrdlParser::AltDeclContext *ctx) = 0;

  virtual void enterAltBody(IrdlParser::AltBodyContext *ctx) = 0;
  virtual void exitAltBody(IrdlParser::AltBodyContext *ctx) = 0;

  virtual void enterAltBodyOptional(IrdlParser::AltBodyOptionalContext *ctx) = 0;
  virtual void exitAltBodyOptional(IrdlParser::AltBodyOptionalContext *ctx) = 0;

  virtual void enterDurationDecl(IrdlParser::DurationDeclContext *ctx) = 0;
  virtual void exitDurationDecl(IrdlParser::DurationDeclContext *ctx) = 0;

  virtual void enterContextID(IrdlParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(IrdlParser::ContextIDContext *ctx) = 0;

  virtual void enterComponentIdPath(IrdlParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(IrdlParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(IrdlParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(IrdlParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(IrdlParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(IrdlParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(IrdlParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(IrdlParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(IrdlParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(IrdlParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(IrdlParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(IrdlParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(IrdlParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(IrdlParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(IrdlParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(IrdlParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(IrdlParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(IrdlParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(IrdlParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(IrdlParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(IrdlParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(IrdlParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(IrdlParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(IrdlParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(IrdlParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(IrdlParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(IrdlParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(IrdlParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(IrdlParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(IrdlParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(IrdlParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(IrdlParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(IrdlParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(IrdlParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(IrdlParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(IrdlParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(IrdlParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(IrdlParser::ToPortNameContext *ctx) = 0;

  virtual void enterLocalAssignStatement(IrdlParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(IrdlParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(IrdlParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(IrdlParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(IrdlParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(IrdlParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(IrdlParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(IrdlParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(IrdlParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(IrdlParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(IrdlParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(IrdlParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(IrdlParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(IrdlParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(IrdlParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(IrdlParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(IrdlParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(IrdlParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(IrdlParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(IrdlParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(IrdlParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(IrdlParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(IrdlParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(IrdlParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(IrdlParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(IrdlParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(IrdlParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(IrdlParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(IrdlParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(IrdlParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(IrdlParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(IrdlParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(IrdlParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(IrdlParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(IrdlParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(IrdlParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(IrdlParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(IrdlParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(IrdlParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(IrdlParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(IrdlParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(IrdlParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(IrdlParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(IrdlParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(IrdlParser::OperationContext *ctx) = 0;
  virtual void exitOperation(IrdlParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(IrdlParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(IrdlParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(IrdlParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(IrdlParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(IrdlParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(IrdlParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(IrdlParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(IrdlParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(IrdlParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(IrdlParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(IrdlParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(IrdlParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(IrdlParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(IrdlParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(IrdlParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(IrdlParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(IrdlParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(IrdlParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(IrdlParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(IrdlParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(IrdlParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(IrdlParser::DefaultStatementContext *ctx) = 0;


};

