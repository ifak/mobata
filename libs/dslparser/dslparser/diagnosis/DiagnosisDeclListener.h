
// Generated from /home/kra/SWDevelop/mobata/libs/dslparser/dslparser/grammars/DiagnosisDecl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "DiagnosisDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DiagnosisDeclParser.
 */
class  DiagnosisDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterDiagnosisDecl(DiagnosisDeclParser::DiagnosisDeclContext *ctx) = 0;
  virtual void exitDiagnosisDecl(DiagnosisDeclParser::DiagnosisDeclContext *ctx) = 0;

  virtual void enterRulesDecl(DiagnosisDeclParser::RulesDeclContext *ctx) = 0;
  virtual void exitRulesDecl(DiagnosisDeclParser::RulesDeclContext *ctx) = 0;

  virtual void enterRuleDecl(DiagnosisDeclParser::RuleDeclContext *ctx) = 0;
  virtual void exitRuleDecl(DiagnosisDeclParser::RuleDeclContext *ctx) = 0;

  virtual void enterRuleBody(DiagnosisDeclParser::RuleBodyContext *ctx) = 0;
  virtual void exitRuleBody(DiagnosisDeclParser::RuleBodyContext *ctx) = 0;

  virtual void enterDescriptionDecl(DiagnosisDeclParser::DescriptionDeclContext *ctx) = 0;
  virtual void exitDescriptionDecl(DiagnosisDeclParser::DescriptionDeclContext *ctx) = 0;

  virtual void enterDeclarations(DiagnosisDeclParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(DiagnosisDeclParser::DeclarationsContext *ctx) = 0;

  virtual void enterComponentsDecl(DiagnosisDeclParser::ComponentsDeclContext *ctx) = 0;
  virtual void exitComponentsDecl(DiagnosisDeclParser::ComponentsDeclContext *ctx) = 0;

  virtual void enterComponentsBody(DiagnosisDeclParser::ComponentsBodyContext *ctx) = 0;
  virtual void exitComponentsBody(DiagnosisDeclParser::ComponentsBodyContext *ctx) = 0;

  virtual void enterComponentDecl(DiagnosisDeclParser::ComponentDeclContext *ctx) = 0;
  virtual void exitComponentDecl(DiagnosisDeclParser::ComponentDeclContext *ctx) = 0;

  virtual void enterComponentBody(DiagnosisDeclParser::ComponentBodyContext *ctx) = 0;
  virtual void exitComponentBody(DiagnosisDeclParser::ComponentBodyContext *ctx) = 0;

  virtual void enterDiagnosisSignalsDecl(DiagnosisDeclParser::DiagnosisSignalsDeclContext *ctx) = 0;
  virtual void exitDiagnosisSignalsDecl(DiagnosisDeclParser::DiagnosisSignalsDeclContext *ctx) = 0;

  virtual void enterDiagnosisSignalsBody(DiagnosisDeclParser::DiagnosisSignalsBodyContext *ctx) = 0;
  virtual void exitDiagnosisSignalsBody(DiagnosisDeclParser::DiagnosisSignalsBodyContext *ctx) = 0;

  virtual void enterDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext *ctx) = 0;
  virtual void exitDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext *ctx) = 0;

  virtual void enterDiagnosisSignalBody(DiagnosisDeclParser::DiagnosisSignalBodyContext *ctx) = 0;
  virtual void exitDiagnosisSignalBody(DiagnosisDeclParser::DiagnosisSignalBodyContext *ctx) = 0;

  virtual void enterBaseTypeDecl(DiagnosisDeclParser::BaseTypeDeclContext *ctx) = 0;
  virtual void exitBaseTypeDecl(DiagnosisDeclParser::BaseTypeDeclContext *ctx) = 0;

  virtual void enterCheckDecl(DiagnosisDeclParser::CheckDeclContext *ctx) = 0;
  virtual void exitCheckDecl(DiagnosisDeclParser::CheckDeclContext *ctx) = 0;

  virtual void enterAliasDef(DiagnosisDeclParser::AliasDefContext *ctx) = 0;
  virtual void exitAliasDef(DiagnosisDeclParser::AliasDefContext *ctx) = 0;

  virtual void enterSequenceDecl(DiagnosisDeclParser::SequenceDeclContext *ctx) = 0;
  virtual void exitSequenceDecl(DiagnosisDeclParser::SequenceDeclContext *ctx) = 0;

  virtual void enterSequenceBody(DiagnosisDeclParser::SequenceBodyContext *ctx) = 0;
  virtual void exitSequenceBody(DiagnosisDeclParser::SequenceBodyContext *ctx) = 0;

  virtual void enterMessageDecl(DiagnosisDeclParser::MessageDeclContext *ctx) = 0;
  virtual void exitMessageDecl(DiagnosisDeclParser::MessageDeclContext *ctx) = 0;

  virtual void enterExpression(DiagnosisDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(DiagnosisDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(DiagnosisDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(DiagnosisDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterAtom(DiagnosisDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(DiagnosisDeclParser::AtomContext *ctx) = 0;

  virtual void enterLoopDecl(DiagnosisDeclParser::LoopDeclContext *ctx) = 0;
  virtual void exitLoopDecl(DiagnosisDeclParser::LoopDeclContext *ctx) = 0;

  virtual void enterParallelDecl(DiagnosisDeclParser::ParallelDeclContext *ctx) = 0;
  virtual void exitParallelDecl(DiagnosisDeclParser::ParallelDeclContext *ctx) = 0;

  virtual void enterParallelBodys(DiagnosisDeclParser::ParallelBodysContext *ctx) = 0;
  virtual void exitParallelBodys(DiagnosisDeclParser::ParallelBodysContext *ctx) = 0;

  virtual void enterParallelBody(DiagnosisDeclParser::ParallelBodyContext *ctx) = 0;
  virtual void exitParallelBody(DiagnosisDeclParser::ParallelBodyContext *ctx) = 0;

  virtual void enterEnabledDecl(DiagnosisDeclParser::EnabledDeclContext *ctx) = 0;
  virtual void exitEnabledDecl(DiagnosisDeclParser::EnabledDeclContext *ctx) = 0;

  virtual void enterComponentIdPath(DiagnosisDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(DiagnosisDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(DiagnosisDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(DiagnosisDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(DiagnosisDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(DiagnosisDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(DiagnosisDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(DiagnosisDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(DiagnosisDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(DiagnosisDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(DiagnosisDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(DiagnosisDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(DiagnosisDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(DiagnosisDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(DiagnosisDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(DiagnosisDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(DiagnosisDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(DiagnosisDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(DiagnosisDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(DiagnosisDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(DiagnosisDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(DiagnosisDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(DiagnosisDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(DiagnosisDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(DiagnosisDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(DiagnosisDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(DiagnosisDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(DiagnosisDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(DiagnosisDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(DiagnosisDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(DiagnosisDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(DiagnosisDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(DiagnosisDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(DiagnosisDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(DiagnosisDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(DiagnosisDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(DiagnosisDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(DiagnosisDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(DiagnosisDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(DiagnosisDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(DiagnosisDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(DiagnosisDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(DiagnosisDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(DiagnosisDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(DiagnosisDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(DiagnosisDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(DiagnosisDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(DiagnosisDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(DiagnosisDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(DiagnosisDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(DiagnosisDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(DiagnosisDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(DiagnosisDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(DiagnosisDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(DiagnosisDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(DiagnosisDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(DiagnosisDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(DiagnosisDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(DiagnosisDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(DiagnosisDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(DiagnosisDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(DiagnosisDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterContextID(DiagnosisDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(DiagnosisDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterTriggerDecl(DiagnosisDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(DiagnosisDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(DiagnosisDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(DiagnosisDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(DiagnosisDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(DiagnosisDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(DiagnosisDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(DiagnosisDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(DiagnosisDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(DiagnosisDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(DiagnosisDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(DiagnosisDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(DiagnosisDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(DiagnosisDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(DiagnosisDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(DiagnosisDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(DiagnosisDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(DiagnosisDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(DiagnosisDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(DiagnosisDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(DiagnosisDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(DiagnosisDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(DiagnosisDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(DiagnosisDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(DiagnosisDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(DiagnosisDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(DiagnosisDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(DiagnosisDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(DiagnosisDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(DiagnosisDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(DiagnosisDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(DiagnosisDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(DiagnosisDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(DiagnosisDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(DiagnosisDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(DiagnosisDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(DiagnosisDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(DiagnosisDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(DiagnosisDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(DiagnosisDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(DiagnosisDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(DiagnosisDeclParser::DefaultStatementContext *ctx) = 0;


};

