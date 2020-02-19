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

// Generated from /home/sebastian/Documents/Git/MbtCreator/3rd/mobata/libs/dslparser/dslparser/grammars/IrdlCommonDecl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "IrdlCommonDeclListener.h"


/**
 * This class provides an empty implementation of IrdlCommonDeclListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  IrdlCommonDeclBaseListener : public IrdlCommonDeclListener {
public:

  virtual void enterIrdlCommonDecl(IrdlCommonDeclParser::IrdlCommonDeclContext * /*ctx*/) override { }
  virtual void exitIrdlCommonDecl(IrdlCommonDeclParser::IrdlCommonDeclContext * /*ctx*/) override { }

  virtual void enterTimerNameID(IrdlCommonDeclParser::TimerNameIDContext * /*ctx*/) override { }
  virtual void exitTimerNameID(IrdlCommonDeclParser::TimerNameIDContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(IrdlCommonDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(IrdlCommonDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterAtom(IrdlCommonDeclParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(IrdlCommonDeclParser::AtomContext * /*ctx*/) override { }

  virtual void enterIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext * /*ctx*/) override { }
  virtual void exitIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext * /*ctx*/) override { }

  virtual void enterRequirementBody(IrdlCommonDeclParser::RequirementBodyContext * /*ctx*/) override { }
  virtual void exitRequirementBody(IrdlCommonDeclParser::RequirementBodyContext * /*ctx*/) override { }

  virtual void enterAliasDef(IrdlCommonDeclParser::AliasDefContext * /*ctx*/) override { }
  virtual void exitAliasDef(IrdlCommonDeclParser::AliasDefContext * /*ctx*/) override { }

  virtual void enterDeclarations(IrdlCommonDeclParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(IrdlCommonDeclParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterComponentDecl(IrdlCommonDeclParser::ComponentDeclContext * /*ctx*/) override { }
  virtual void exitComponentDecl(IrdlCommonDeclParser::ComponentDeclContext * /*ctx*/) override { }

  virtual void enterComponentBody(IrdlCommonDeclParser::ComponentBodyContext * /*ctx*/) override { }
  virtual void exitComponentBody(IrdlCommonDeclParser::ComponentBodyContext * /*ctx*/) override { }

  virtual void enterActorDecl(IrdlCommonDeclParser::ActorDeclContext * /*ctx*/) override { }
  virtual void exitActorDecl(IrdlCommonDeclParser::ActorDeclContext * /*ctx*/) override { }

  virtual void enterActorBody(IrdlCommonDeclParser::ActorBodyContext * /*ctx*/) override { }
  virtual void exitActorBody(IrdlCommonDeclParser::ActorBodyContext * /*ctx*/) override { }

  virtual void enterDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext * /*ctx*/) override { }
  virtual void exitDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext * /*ctx*/) override { }

  virtual void enterSequenceDecl(IrdlCommonDeclParser::SequenceDeclContext * /*ctx*/) override { }
  virtual void exitSequenceDecl(IrdlCommonDeclParser::SequenceDeclContext * /*ctx*/) override { }

  virtual void enterStateDecl(IrdlCommonDeclParser::StateDeclContext * /*ctx*/) override { }
  virtual void exitStateDecl(IrdlCommonDeclParser::StateDeclContext * /*ctx*/) override { }

  virtual void enterLifelineList(IrdlCommonDeclParser::LifelineListContext * /*ctx*/) override { }
  virtual void exitLifelineList(IrdlCommonDeclParser::LifelineListContext * /*ctx*/) override { }

  virtual void enterLifelineListOptional(IrdlCommonDeclParser::LifelineListOptionalContext * /*ctx*/) override { }
  virtual void exitLifelineListOptional(IrdlCommonDeclParser::LifelineListOptionalContext * /*ctx*/) override { }

  virtual void enterMessageSignal(IrdlCommonDeclParser::MessageSignalContext * /*ctx*/) override { }
  virtual void exitMessageSignal(IrdlCommonDeclParser::MessageSignalContext * /*ctx*/) override { }

  virtual void enterMessageSignalBody(IrdlCommonDeclParser::MessageSignalBodyContext * /*ctx*/) override { }
  virtual void exitMessageSignalBody(IrdlCommonDeclParser::MessageSignalBodyContext * /*ctx*/) override { }

  virtual void enterMessageSignalBodyOptional(IrdlCommonDeclParser::MessageSignalBodyOptionalContext * /*ctx*/) override { }
  virtual void exitMessageSignalBodyOptional(IrdlCommonDeclParser::MessageSignalBodyOptionalContext * /*ctx*/) override { }

  virtual void enterMessageDecl(IrdlCommonDeclParser::MessageDeclContext * /*ctx*/) override { }
  virtual void exitMessageDecl(IrdlCommonDeclParser::MessageDeclContext * /*ctx*/) override { }

  virtual void enterCheckDecl(IrdlCommonDeclParser::CheckDeclContext * /*ctx*/) override { }
  virtual void exitCheckDecl(IrdlCommonDeclParser::CheckDeclContext * /*ctx*/) override { }

  virtual void enterCheckDeclBody(IrdlCommonDeclParser::CheckDeclBodyContext * /*ctx*/) override { }
  virtual void exitCheckDeclBody(IrdlCommonDeclParser::CheckDeclBodyContext * /*ctx*/) override { }

  virtual void enterTimerDecl(IrdlCommonDeclParser::TimerDeclContext * /*ctx*/) override { }
  virtual void exitTimerDecl(IrdlCommonDeclParser::TimerDeclContext * /*ctx*/) override { }

  virtual void enterAttributeAssign(IrdlCommonDeclParser::AttributeAssignContext * /*ctx*/) override { }
  virtual void exitAttributeAssign(IrdlCommonDeclParser::AttributeAssignContext * /*ctx*/) override { }

  virtual void enterTimeOutDecl(IrdlCommonDeclParser::TimeOutDeclContext * /*ctx*/) override { }
  virtual void exitTimeOutDecl(IrdlCommonDeclParser::TimeOutDeclContext * /*ctx*/) override { }

  virtual void enterAltDecl(IrdlCommonDeclParser::AltDeclContext * /*ctx*/) override { }
  virtual void exitAltDecl(IrdlCommonDeclParser::AltDeclContext * /*ctx*/) override { }

  virtual void enterAltBody(IrdlCommonDeclParser::AltBodyContext * /*ctx*/) override { }
  virtual void exitAltBody(IrdlCommonDeclParser::AltBodyContext * /*ctx*/) override { }

  virtual void enterAltBodyOptional(IrdlCommonDeclParser::AltBodyOptionalContext * /*ctx*/) override { }
  virtual void exitAltBodyOptional(IrdlCommonDeclParser::AltBodyOptionalContext * /*ctx*/) override { }

  virtual void enterDurationDecl(IrdlCommonDeclParser::DurationDeclContext * /*ctx*/) override { }
  virtual void exitDurationDecl(IrdlCommonDeclParser::DurationDeclContext * /*ctx*/) override { }

  virtual void enterContextID(IrdlCommonDeclParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(IrdlCommonDeclParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(IrdlCommonDeclParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(IrdlCommonDeclParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(IrdlCommonDeclParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(IrdlCommonDeclParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(IrdlCommonDeclParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(IrdlCommonDeclParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(IrdlCommonDeclParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(IrdlCommonDeclParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(IrdlCommonDeclParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(IrdlCommonDeclParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(IrdlCommonDeclParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(IrdlCommonDeclParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(IrdlCommonDeclParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(IrdlCommonDeclParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(IrdlCommonDeclParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(IrdlCommonDeclParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(IrdlCommonDeclParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(IrdlCommonDeclParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(IrdlCommonDeclParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(IrdlCommonDeclParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(IrdlCommonDeclParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(IrdlCommonDeclParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(IrdlCommonDeclParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(IrdlCommonDeclParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(IrdlCommonDeclParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(IrdlCommonDeclParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(IrdlCommonDeclParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(IrdlCommonDeclParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(IrdlCommonDeclParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(IrdlCommonDeclParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(IrdlCommonDeclParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(IrdlCommonDeclParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(IrdlCommonDeclParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(IrdlCommonDeclParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(IrdlCommonDeclParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(IrdlCommonDeclParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(IrdlCommonDeclParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(IrdlCommonDeclParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(IrdlCommonDeclParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(IrdlCommonDeclParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(IrdlCommonDeclParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(IrdlCommonDeclParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(IrdlCommonDeclParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(IrdlCommonDeclParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(IrdlCommonDeclParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(IrdlCommonDeclParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(IrdlCommonDeclParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(IrdlCommonDeclParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(IrdlCommonDeclParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(IrdlCommonDeclParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(IrdlCommonDeclParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(IrdlCommonDeclParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(IrdlCommonDeclParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(IrdlCommonDeclParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(IrdlCommonDeclParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(IrdlCommonDeclParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(IrdlCommonDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(IrdlCommonDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(IrdlCommonDeclParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(IrdlCommonDeclParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(IrdlCommonDeclParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(IrdlCommonDeclParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(IrdlCommonDeclParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(IrdlCommonDeclParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(IrdlCommonDeclParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(IrdlCommonDeclParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(IrdlCommonDeclParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(IrdlCommonDeclParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(IrdlCommonDeclParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(IrdlCommonDeclParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(IrdlCommonDeclParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(IrdlCommonDeclParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(IrdlCommonDeclParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(IrdlCommonDeclParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(IrdlCommonDeclParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(IrdlCommonDeclParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(IrdlCommonDeclParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(IrdlCommonDeclParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(IrdlCommonDeclParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(IrdlCommonDeclParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(IrdlCommonDeclParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(IrdlCommonDeclParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(IrdlCommonDeclParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(IrdlCommonDeclParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(IrdlCommonDeclParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(IrdlCommonDeclParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(IrdlCommonDeclParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(IrdlCommonDeclParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(IrdlCommonDeclParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(IrdlCommonDeclParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(IrdlCommonDeclParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(IrdlCommonDeclParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(IrdlCommonDeclParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(IrdlCommonDeclParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(IrdlCommonDeclParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(IrdlCommonDeclParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(IrdlCommonDeclParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(IrdlCommonDeclParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(IrdlCommonDeclParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(IrdlCommonDeclParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(IrdlCommonDeclParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(IrdlCommonDeclParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(IrdlCommonDeclParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(IrdlCommonDeclParser::DefaultStatementContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

