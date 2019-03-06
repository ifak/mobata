
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/IrdlCommonDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "IrdlCommonDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by IrdlCommonDeclParser.
 */
class  IrdlCommonDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterIrdlCommonDecl(IrdlCommonDeclParser::IrdlCommonDeclContext *ctx) = 0;
  virtual void exitIrdlCommonDecl(IrdlCommonDeclParser::IrdlCommonDeclContext *ctx) = 0;

  virtual void enterTimerNameID(IrdlCommonDeclParser::TimerNameIDContext *ctx) = 0;
  virtual void exitTimerNameID(IrdlCommonDeclParser::TimerNameIDContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(IrdlCommonDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(IrdlCommonDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterAtom(IrdlCommonDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(IrdlCommonDeclParser::AtomContext *ctx) = 0;

  virtual void enterIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext *ctx) = 0;
  virtual void exitIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext *ctx) = 0;

  virtual void enterRequirementBody(IrdlCommonDeclParser::RequirementBodyContext *ctx) = 0;
  virtual void exitRequirementBody(IrdlCommonDeclParser::RequirementBodyContext *ctx) = 0;

  virtual void enterAliasDef(IrdlCommonDeclParser::AliasDefContext *ctx) = 0;
  virtual void exitAliasDef(IrdlCommonDeclParser::AliasDefContext *ctx) = 0;

  virtual void enterDeclarations(IrdlCommonDeclParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(IrdlCommonDeclParser::DeclarationsContext *ctx) = 0;

  virtual void enterComponentDecl(IrdlCommonDeclParser::ComponentDeclContext *ctx) = 0;
  virtual void exitComponentDecl(IrdlCommonDeclParser::ComponentDeclContext *ctx) = 0;

  virtual void enterComponentBody(IrdlCommonDeclParser::ComponentBodyContext *ctx) = 0;
  virtual void exitComponentBody(IrdlCommonDeclParser::ComponentBodyContext *ctx) = 0;

  virtual void enterActorDecl(IrdlCommonDeclParser::ActorDeclContext *ctx) = 0;
  virtual void exitActorDecl(IrdlCommonDeclParser::ActorDeclContext *ctx) = 0;

  virtual void enterActorBody(IrdlCommonDeclParser::ActorBodyContext *ctx) = 0;
  virtual void exitActorBody(IrdlCommonDeclParser::ActorBodyContext *ctx) = 0;

  virtual void enterDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext *ctx) = 0;
  virtual void exitDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext *ctx) = 0;

  virtual void enterSequenceDecl(IrdlCommonDeclParser::SequenceDeclContext *ctx) = 0;
  virtual void exitSequenceDecl(IrdlCommonDeclParser::SequenceDeclContext *ctx) = 0;

  virtual void enterStateDecl(IrdlCommonDeclParser::StateDeclContext *ctx) = 0;
  virtual void exitStateDecl(IrdlCommonDeclParser::StateDeclContext *ctx) = 0;

  virtual void enterLifelineList(IrdlCommonDeclParser::LifelineListContext *ctx) = 0;
  virtual void exitLifelineList(IrdlCommonDeclParser::LifelineListContext *ctx) = 0;

  virtual void enterLifelineListOptional(IrdlCommonDeclParser::LifelineListOptionalContext *ctx) = 0;
  virtual void exitLifelineListOptional(IrdlCommonDeclParser::LifelineListOptionalContext *ctx) = 0;

  virtual void enterMessageSignal(IrdlCommonDeclParser::MessageSignalContext *ctx) = 0;
  virtual void exitMessageSignal(IrdlCommonDeclParser::MessageSignalContext *ctx) = 0;

  virtual void enterMessageSignalBody(IrdlCommonDeclParser::MessageSignalBodyContext *ctx) = 0;
  virtual void exitMessageSignalBody(IrdlCommonDeclParser::MessageSignalBodyContext *ctx) = 0;

  virtual void enterMessageSignalBodyOptional(IrdlCommonDeclParser::MessageSignalBodyOptionalContext *ctx) = 0;
  virtual void exitMessageSignalBodyOptional(IrdlCommonDeclParser::MessageSignalBodyOptionalContext *ctx) = 0;

  virtual void enterMessageDecl(IrdlCommonDeclParser::MessageDeclContext *ctx) = 0;
  virtual void exitMessageDecl(IrdlCommonDeclParser::MessageDeclContext *ctx) = 0;

  virtual void enterCheckDecl(IrdlCommonDeclParser::CheckDeclContext *ctx) = 0;
  virtual void exitCheckDecl(IrdlCommonDeclParser::CheckDeclContext *ctx) = 0;

  virtual void enterCheckDeclBody(IrdlCommonDeclParser::CheckDeclBodyContext *ctx) = 0;
  virtual void exitCheckDeclBody(IrdlCommonDeclParser::CheckDeclBodyContext *ctx) = 0;

  virtual void enterTimerDecl(IrdlCommonDeclParser::TimerDeclContext *ctx) = 0;
  virtual void exitTimerDecl(IrdlCommonDeclParser::TimerDeclContext *ctx) = 0;

  virtual void enterTimeOutDecl(IrdlCommonDeclParser::TimeOutDeclContext *ctx) = 0;
  virtual void exitTimeOutDecl(IrdlCommonDeclParser::TimeOutDeclContext *ctx) = 0;

  virtual void enterAltDecl(IrdlCommonDeclParser::AltDeclContext *ctx) = 0;
  virtual void exitAltDecl(IrdlCommonDeclParser::AltDeclContext *ctx) = 0;

  virtual void enterAltBody(IrdlCommonDeclParser::AltBodyContext *ctx) = 0;
  virtual void exitAltBody(IrdlCommonDeclParser::AltBodyContext *ctx) = 0;

  virtual void enterAltBodyOptional(IrdlCommonDeclParser::AltBodyOptionalContext *ctx) = 0;
  virtual void exitAltBodyOptional(IrdlCommonDeclParser::AltBodyOptionalContext *ctx) = 0;

  virtual void enterDurationDecl(IrdlCommonDeclParser::DurationDeclContext *ctx) = 0;
  virtual void exitDurationDecl(IrdlCommonDeclParser::DurationDeclContext *ctx) = 0;

  virtual void enterContextID(IrdlCommonDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(IrdlCommonDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterComponentIdPath(IrdlCommonDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(IrdlCommonDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(IrdlCommonDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(IrdlCommonDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(IrdlCommonDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(IrdlCommonDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(IrdlCommonDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(IrdlCommonDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(IrdlCommonDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(IrdlCommonDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(IrdlCommonDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(IrdlCommonDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(IrdlCommonDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(IrdlCommonDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(IrdlCommonDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(IrdlCommonDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(IrdlCommonDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(IrdlCommonDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(IrdlCommonDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(IrdlCommonDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(IrdlCommonDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(IrdlCommonDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(IrdlCommonDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(IrdlCommonDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(IrdlCommonDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(IrdlCommonDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(IrdlCommonDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(IrdlCommonDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(IrdlCommonDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(IrdlCommonDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(IrdlCommonDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(IrdlCommonDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(IrdlCommonDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(IrdlCommonDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(IrdlCommonDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(IrdlCommonDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterLocalAssignStatement(IrdlCommonDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(IrdlCommonDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(IrdlCommonDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(IrdlCommonDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(IrdlCommonDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(IrdlCommonDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(IrdlCommonDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(IrdlCommonDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(IrdlCommonDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(IrdlCommonDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(IrdlCommonDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(IrdlCommonDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(IrdlCommonDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(IrdlCommonDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(IrdlCommonDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(IrdlCommonDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(IrdlCommonDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(IrdlCommonDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(IrdlCommonDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(IrdlCommonDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(IrdlCommonDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(IrdlCommonDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterTriggerDecl(IrdlCommonDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(IrdlCommonDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(IrdlCommonDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(IrdlCommonDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(IrdlCommonDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(IrdlCommonDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(IrdlCommonDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(IrdlCommonDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(IrdlCommonDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(IrdlCommonDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(IrdlCommonDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(IrdlCommonDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(IrdlCommonDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(IrdlCommonDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(IrdlCommonDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(IrdlCommonDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(IrdlCommonDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(IrdlCommonDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(IrdlCommonDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(IrdlCommonDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(IrdlCommonDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(IrdlCommonDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(IrdlCommonDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(IrdlCommonDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(IrdlCommonDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(IrdlCommonDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(IrdlCommonDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(IrdlCommonDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(IrdlCommonDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(IrdlCommonDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(IrdlCommonDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(IrdlCommonDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(IrdlCommonDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(IrdlCommonDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(IrdlCommonDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(IrdlCommonDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(IrdlCommonDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(IrdlCommonDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(IrdlCommonDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(IrdlCommonDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(IrdlCommonDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(IrdlCommonDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(IrdlCommonDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(IrdlCommonDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(IrdlCommonDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(IrdlCommonDeclParser::DefaultStatementContext *ctx) = 0;


};

