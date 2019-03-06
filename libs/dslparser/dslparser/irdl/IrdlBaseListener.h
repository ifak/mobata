
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/Irdl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "IrdlListener.h"


/**
 * This class provides an empty implementation of IrdlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  IrdlBaseListener : public IrdlListener {
public:

  virtual void enterTimerNameID(IrdlParser::TimerNameIDContext * /*ctx*/) override { }
  virtual void exitTimerNameID(IrdlParser::TimerNameIDContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(IrdlParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(IrdlParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterAtom(IrdlParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(IrdlParser::AtomContext * /*ctx*/) override { }

  virtual void enterIrdlDecl(IrdlParser::IrdlDeclContext * /*ctx*/) override { }
  virtual void exitIrdlDecl(IrdlParser::IrdlDeclContext * /*ctx*/) override { }

  virtual void enterRequirementBody(IrdlParser::RequirementBodyContext * /*ctx*/) override { }
  virtual void exitRequirementBody(IrdlParser::RequirementBodyContext * /*ctx*/) override { }

  virtual void enterAliasDef(IrdlParser::AliasDefContext * /*ctx*/) override { }
  virtual void exitAliasDef(IrdlParser::AliasDefContext * /*ctx*/) override { }

  virtual void enterDeclarations(IrdlParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(IrdlParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterComponentDecl(IrdlParser::ComponentDeclContext * /*ctx*/) override { }
  virtual void exitComponentDecl(IrdlParser::ComponentDeclContext * /*ctx*/) override { }

  virtual void enterComponentBody(IrdlParser::ComponentBodyContext * /*ctx*/) override { }
  virtual void exitComponentBody(IrdlParser::ComponentBodyContext * /*ctx*/) override { }

  virtual void enterActorDecl(IrdlParser::ActorDeclContext * /*ctx*/) override { }
  virtual void exitActorDecl(IrdlParser::ActorDeclContext * /*ctx*/) override { }

  virtual void enterActorBody(IrdlParser::ActorBodyContext * /*ctx*/) override { }
  virtual void exitActorBody(IrdlParser::ActorBodyContext * /*ctx*/) override { }

  virtual void enterDescriptionDecl(IrdlParser::DescriptionDeclContext * /*ctx*/) override { }
  virtual void exitDescriptionDecl(IrdlParser::DescriptionDeclContext * /*ctx*/) override { }

  virtual void enterSequenceDecl(IrdlParser::SequenceDeclContext * /*ctx*/) override { }
  virtual void exitSequenceDecl(IrdlParser::SequenceDeclContext * /*ctx*/) override { }

  virtual void enterStateDecl(IrdlParser::StateDeclContext * /*ctx*/) override { }
  virtual void exitStateDecl(IrdlParser::StateDeclContext * /*ctx*/) override { }

  virtual void enterLifelineList(IrdlParser::LifelineListContext * /*ctx*/) override { }
  virtual void exitLifelineList(IrdlParser::LifelineListContext * /*ctx*/) override { }

  virtual void enterLifelineListOptional(IrdlParser::LifelineListOptionalContext * /*ctx*/) override { }
  virtual void exitLifelineListOptional(IrdlParser::LifelineListOptionalContext * /*ctx*/) override { }

  virtual void enterMessageSignal(IrdlParser::MessageSignalContext * /*ctx*/) override { }
  virtual void exitMessageSignal(IrdlParser::MessageSignalContext * /*ctx*/) override { }

  virtual void enterMessageSignalBody(IrdlParser::MessageSignalBodyContext * /*ctx*/) override { }
  virtual void exitMessageSignalBody(IrdlParser::MessageSignalBodyContext * /*ctx*/) override { }

  virtual void enterMessageSignalBodyOptional(IrdlParser::MessageSignalBodyOptionalContext * /*ctx*/) override { }
  virtual void exitMessageSignalBodyOptional(IrdlParser::MessageSignalBodyOptionalContext * /*ctx*/) override { }

  virtual void enterMessageDecl(IrdlParser::MessageDeclContext * /*ctx*/) override { }
  virtual void exitMessageDecl(IrdlParser::MessageDeclContext * /*ctx*/) override { }

  virtual void enterCheckDecl(IrdlParser::CheckDeclContext * /*ctx*/) override { }
  virtual void exitCheckDecl(IrdlParser::CheckDeclContext * /*ctx*/) override { }

  virtual void enterCheckDeclBody(IrdlParser::CheckDeclBodyContext * /*ctx*/) override { }
  virtual void exitCheckDeclBody(IrdlParser::CheckDeclBodyContext * /*ctx*/) override { }

  virtual void enterTimerDecl(IrdlParser::TimerDeclContext * /*ctx*/) override { }
  virtual void exitTimerDecl(IrdlParser::TimerDeclContext * /*ctx*/) override { }

  virtual void enterTimeOutDecl(IrdlParser::TimeOutDeclContext * /*ctx*/) override { }
  virtual void exitTimeOutDecl(IrdlParser::TimeOutDeclContext * /*ctx*/) override { }

  virtual void enterAltDecl(IrdlParser::AltDeclContext * /*ctx*/) override { }
  virtual void exitAltDecl(IrdlParser::AltDeclContext * /*ctx*/) override { }

  virtual void enterAltBody(IrdlParser::AltBodyContext * /*ctx*/) override { }
  virtual void exitAltBody(IrdlParser::AltBodyContext * /*ctx*/) override { }

  virtual void enterAltBodyOptional(IrdlParser::AltBodyOptionalContext * /*ctx*/) override { }
  virtual void exitAltBodyOptional(IrdlParser::AltBodyOptionalContext * /*ctx*/) override { }

  virtual void enterDurationDecl(IrdlParser::DurationDeclContext * /*ctx*/) override { }
  virtual void exitDurationDecl(IrdlParser::DurationDeclContext * /*ctx*/) override { }

  virtual void enterContextID(IrdlParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(IrdlParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(IrdlParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(IrdlParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(IrdlParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(IrdlParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(IrdlParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(IrdlParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(IrdlParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(IrdlParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(IrdlParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(IrdlParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(IrdlParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(IrdlParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(IrdlParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(IrdlParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(IrdlParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(IrdlParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(IrdlParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(IrdlParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(IrdlParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(IrdlParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(IrdlParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(IrdlParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(IrdlParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(IrdlParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(IrdlParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(IrdlParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(IrdlParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(IrdlParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(IrdlParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(IrdlParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(IrdlParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(IrdlParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(IrdlParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(IrdlParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(IrdlParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(IrdlParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(IrdlParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(IrdlParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(IrdlParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(IrdlParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(IrdlParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(IrdlParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(IrdlParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(IrdlParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(IrdlParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(IrdlParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(IrdlParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(IrdlParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(IrdlParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(IrdlParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(IrdlParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(IrdlParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(IrdlParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(IrdlParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(IrdlParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(IrdlParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(IrdlParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(IrdlParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(IrdlParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(IrdlParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(IrdlParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(IrdlParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(IrdlParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(IrdlParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(IrdlParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(IrdlParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(IrdlParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(IrdlParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(IrdlParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(IrdlParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(IrdlParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(IrdlParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(IrdlParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(IrdlParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(IrdlParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(IrdlParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(IrdlParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(IrdlParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(IrdlParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(IrdlParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(IrdlParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(IrdlParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(IrdlParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(IrdlParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(IrdlParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(IrdlParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(IrdlParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(IrdlParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(IrdlParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(IrdlParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(IrdlParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(IrdlParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(IrdlParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(IrdlParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(IrdlParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(IrdlParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(IrdlParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(IrdlParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(IrdlParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(IrdlParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(IrdlParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(IrdlParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(IrdlParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(IrdlParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(IrdlParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(IrdlParser::DefaultStatementContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

