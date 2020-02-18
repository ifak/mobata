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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/SimSystemDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SimSystemDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SimSystemDeclParser.
 */
class  SimSystemDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext *ctx) = 0;
  virtual void exitSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext *ctx) = 0;

  virtual void enterSimSystemBody(SimSystemDeclParser::SimSystemBodyContext *ctx) = 0;
  virtual void exitSimSystemBody(SimSystemDeclParser::SimSystemBodyContext *ctx) = 0;

  virtual void enterConnectionDecl(SimSystemDeclParser::ConnectionDeclContext *ctx) = 0;
  virtual void exitConnectionDecl(SimSystemDeclParser::ConnectionDeclContext *ctx) = 0;

  virtual void enterConnectionBody(SimSystemDeclParser::ConnectionBodyContext *ctx) = 0;
  virtual void exitConnectionBody(SimSystemDeclParser::ConnectionBodyContext *ctx) = 0;

  virtual void enterConfigDecl(SimSystemDeclParser::ConfigDeclContext *ctx) = 0;
  virtual void exitConfigDecl(SimSystemDeclParser::ConfigDeclContext *ctx) = 0;

  virtual void enterConfigBody(SimSystemDeclParser::ConfigBodyContext *ctx) = 0;
  virtual void exitConfigBody(SimSystemDeclParser::ConfigBodyContext *ctx) = 0;

  virtual void enterActorDecl(SimSystemDeclParser::ActorDeclContext *ctx) = 0;
  virtual void exitActorDecl(SimSystemDeclParser::ActorDeclContext *ctx) = 0;

  virtual void enterActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext *ctx) = 0;
  virtual void exitActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext *ctx) = 0;

  virtual void enterActorBodyContent(SimSystemDeclParser::ActorBodyContentContext *ctx) = 0;
  virtual void exitActorBodyContent(SimSystemDeclParser::ActorBodyContentContext *ctx) = 0;

  virtual void enterStartupDecl(SimSystemDeclParser::StartupDeclContext *ctx) = 0;
  virtual void exitStartupDecl(SimSystemDeclParser::StartupDeclContext *ctx) = 0;

  virtual void enterStartupBody(SimSystemDeclParser::StartupBodyContext *ctx) = 0;
  virtual void exitStartupBody(SimSystemDeclParser::StartupBodyContext *ctx) = 0;

  virtual void enterMessageDeclOptional(SimSystemDeclParser::MessageDeclOptionalContext *ctx) = 0;
  virtual void exitMessageDeclOptional(SimSystemDeclParser::MessageDeclOptionalContext *ctx) = 0;

  virtual void enterMessageDecl(SimSystemDeclParser::MessageDeclContext *ctx) = 0;
  virtual void exitMessageDecl(SimSystemDeclParser::MessageDeclContext *ctx) = 0;

  virtual void enterMessageSignal(SimSystemDeclParser::MessageSignalContext *ctx) = 0;
  virtual void exitMessageSignal(SimSystemDeclParser::MessageSignalContext *ctx) = 0;

  virtual void enterMessageParamValue(SimSystemDeclParser::MessageParamValueContext *ctx) = 0;
  virtual void exitMessageParamValue(SimSystemDeclParser::MessageParamValueContext *ctx) = 0;

  virtual void enterStartSequenceDecl(SimSystemDeclParser::StartSequenceDeclContext *ctx) = 0;
  virtual void exitStartSequenceDecl(SimSystemDeclParser::StartSequenceDeclContext *ctx) = 0;

  virtual void enterContextID(SimSystemDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(SimSystemDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterComponentIdPath(SimSystemDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(SimSystemDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(SimSystemDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(SimSystemDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(SimSystemDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(SimSystemDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(SimSystemDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(SimSystemDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(SimSystemDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(SimSystemDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(SimSystemDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(SimSystemDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(SimSystemDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(SimSystemDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(SimSystemDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(SimSystemDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(SimSystemDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(SimSystemDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(SimSystemDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(SimSystemDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(SimSystemDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(SimSystemDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(SimSystemDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(SimSystemDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(SimSystemDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(SimSystemDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(SimSystemDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(SimSystemDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(SimSystemDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(SimSystemDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(SimSystemDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(SimSystemDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(SimSystemDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(SimSystemDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(SimSystemDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(SimSystemDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(SimSystemDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(SimSystemDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(SimSystemDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(SimSystemDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(SimSystemDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(SimSystemDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(SimSystemDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(SimSystemDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(SimSystemDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(SimSystemDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(SimSystemDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(SimSystemDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(SimSystemDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(SimSystemDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(SimSystemDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(SimSystemDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(SimSystemDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(SimSystemDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(SimSystemDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(SimSystemDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(SimSystemDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(SimSystemDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(SimSystemDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(SimSystemDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(SimSystemDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(SimSystemDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(SimSystemDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(SimSystemDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(SimSystemDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(SimSystemDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(SimSystemDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(SimSystemDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(SimSystemDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(SimSystemDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(SimSystemDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(SimSystemDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(SimSystemDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(SimSystemDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(SimSystemDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(SimSystemDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(SimSystemDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(SimSystemDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(SimSystemDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(SimSystemDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(SimSystemDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(SimSystemDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(SimSystemDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(SimSystemDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(SimSystemDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(SimSystemDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(SimSystemDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(SimSystemDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(SimSystemDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SimSystemDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(SimSystemDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(SimSystemDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(SimSystemDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(SimSystemDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(SimSystemDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(SimSystemDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(SimSystemDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(SimSystemDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(SimSystemDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(SimSystemDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(SimSystemDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(SimSystemDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(SimSystemDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(SimSystemDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(SimSystemDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(SimSystemDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(SimSystemDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(SimSystemDeclParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(SimSystemDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(SimSystemDeclParser::AtomContext *ctx) = 0;


};

