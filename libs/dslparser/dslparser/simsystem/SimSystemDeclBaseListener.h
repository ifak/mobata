
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/SimSystemDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SimSystemDeclListener.h"


/**
 * This class provides an empty implementation of SimSystemDeclListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SimSystemDeclBaseListener : public SimSystemDeclListener {
public:

  virtual void enterSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext * /*ctx*/) override { }
  virtual void exitSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext * /*ctx*/) override { }

  virtual void enterSimSystemBody(SimSystemDeclParser::SimSystemBodyContext * /*ctx*/) override { }
  virtual void exitSimSystemBody(SimSystemDeclParser::SimSystemBodyContext * /*ctx*/) override { }

  virtual void enterConnectionDecl(SimSystemDeclParser::ConnectionDeclContext * /*ctx*/) override { }
  virtual void exitConnectionDecl(SimSystemDeclParser::ConnectionDeclContext * /*ctx*/) override { }

  virtual void enterConnectionBody(SimSystemDeclParser::ConnectionBodyContext * /*ctx*/) override { }
  virtual void exitConnectionBody(SimSystemDeclParser::ConnectionBodyContext * /*ctx*/) override { }

  virtual void enterConfigDecl(SimSystemDeclParser::ConfigDeclContext * /*ctx*/) override { }
  virtual void exitConfigDecl(SimSystemDeclParser::ConfigDeclContext * /*ctx*/) override { }

  virtual void enterConfigBody(SimSystemDeclParser::ConfigBodyContext * /*ctx*/) override { }
  virtual void exitConfigBody(SimSystemDeclParser::ConfigBodyContext * /*ctx*/) override { }

  virtual void enterActorDecl(SimSystemDeclParser::ActorDeclContext * /*ctx*/) override { }
  virtual void exitActorDecl(SimSystemDeclParser::ActorDeclContext * /*ctx*/) override { }

  virtual void enterActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext * /*ctx*/) override { }
  virtual void exitActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext * /*ctx*/) override { }

  virtual void enterActorBodyContent(SimSystemDeclParser::ActorBodyContentContext * /*ctx*/) override { }
  virtual void exitActorBodyContent(SimSystemDeclParser::ActorBodyContentContext * /*ctx*/) override { }

  virtual void enterStartupDecl(SimSystemDeclParser::StartupDeclContext * /*ctx*/) override { }
  virtual void exitStartupDecl(SimSystemDeclParser::StartupDeclContext * /*ctx*/) override { }

  virtual void enterStartupBody(SimSystemDeclParser::StartupBodyContext * /*ctx*/) override { }
  virtual void exitStartupBody(SimSystemDeclParser::StartupBodyContext * /*ctx*/) override { }

  virtual void enterMessageDeclOptional(SimSystemDeclParser::MessageDeclOptionalContext * /*ctx*/) override { }
  virtual void exitMessageDeclOptional(SimSystemDeclParser::MessageDeclOptionalContext * /*ctx*/) override { }

  virtual void enterMessageDecl(SimSystemDeclParser::MessageDeclContext * /*ctx*/) override { }
  virtual void exitMessageDecl(SimSystemDeclParser::MessageDeclContext * /*ctx*/) override { }

  virtual void enterMessageSignal(SimSystemDeclParser::MessageSignalContext * /*ctx*/) override { }
  virtual void exitMessageSignal(SimSystemDeclParser::MessageSignalContext * /*ctx*/) override { }

  virtual void enterMessageParamValue(SimSystemDeclParser::MessageParamValueContext * /*ctx*/) override { }
  virtual void exitMessageParamValue(SimSystemDeclParser::MessageParamValueContext * /*ctx*/) override { }

  virtual void enterStartSequenceDecl(SimSystemDeclParser::StartSequenceDeclContext * /*ctx*/) override { }
  virtual void exitStartSequenceDecl(SimSystemDeclParser::StartSequenceDeclContext * /*ctx*/) override { }

  virtual void enterContextID(SimSystemDeclParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(SimSystemDeclParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(SimSystemDeclParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(SimSystemDeclParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(SimSystemDeclParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(SimSystemDeclParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(SimSystemDeclParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(SimSystemDeclParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(SimSystemDeclParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(SimSystemDeclParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(SimSystemDeclParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(SimSystemDeclParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(SimSystemDeclParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(SimSystemDeclParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(SimSystemDeclParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(SimSystemDeclParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(SimSystemDeclParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(SimSystemDeclParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(SimSystemDeclParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(SimSystemDeclParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(SimSystemDeclParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(SimSystemDeclParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(SimSystemDeclParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(SimSystemDeclParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(SimSystemDeclParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(SimSystemDeclParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(SimSystemDeclParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(SimSystemDeclParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(SimSystemDeclParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(SimSystemDeclParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(SimSystemDeclParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(SimSystemDeclParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(SimSystemDeclParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(SimSystemDeclParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(SimSystemDeclParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(SimSystemDeclParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(SimSystemDeclParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(SimSystemDeclParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(SimSystemDeclParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(SimSystemDeclParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(SimSystemDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(SimSystemDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(SimSystemDeclParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(SimSystemDeclParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(SimSystemDeclParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(SimSystemDeclParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(SimSystemDeclParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(SimSystemDeclParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(SimSystemDeclParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(SimSystemDeclParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(SimSystemDeclParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(SimSystemDeclParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(SimSystemDeclParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(SimSystemDeclParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(SimSystemDeclParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(SimSystemDeclParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(SimSystemDeclParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(SimSystemDeclParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(SimSystemDeclParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(SimSystemDeclParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(SimSystemDeclParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(SimSystemDeclParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(SimSystemDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(SimSystemDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(SimSystemDeclParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(SimSystemDeclParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(SimSystemDeclParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(SimSystemDeclParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(SimSystemDeclParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(SimSystemDeclParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(SimSystemDeclParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(SimSystemDeclParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(SimSystemDeclParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(SimSystemDeclParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(SimSystemDeclParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(SimSystemDeclParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(SimSystemDeclParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(SimSystemDeclParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(SimSystemDeclParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(SimSystemDeclParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(SimSystemDeclParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(SimSystemDeclParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(SimSystemDeclParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(SimSystemDeclParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(SimSystemDeclParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(SimSystemDeclParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(SimSystemDeclParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(SimSystemDeclParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(SimSystemDeclParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(SimSystemDeclParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(SimSystemDeclParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SimSystemDeclParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(SimSystemDeclParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(SimSystemDeclParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(SimSystemDeclParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(SimSystemDeclParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(SimSystemDeclParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(SimSystemDeclParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(SimSystemDeclParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(SimSystemDeclParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(SimSystemDeclParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(SimSystemDeclParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(SimSystemDeclParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(SimSystemDeclParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(SimSystemDeclParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(SimSystemDeclParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(SimSystemDeclParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(SimSystemDeclParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(SimSystemDeclParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(SimSystemDeclParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(SimSystemDeclParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(SimSystemDeclParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

