
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/Irdl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  IrdlParser : public antlr4::Parser {
public:
  enum {
    UseID = 1, RequirementID = 2, DescriptionID = 3, ComponentID = 4, ActorID = 5, 
    StateID = 6, AtID = 7, AllID = 8, MessageID = 9, CheckID = 10, TimerID = 11, 
    TimeOutID = 12, AltID = 13, DurationID = 14, MilliSekID = 15, SekID = 16, 
    IGNORE_NEWLINE = 17, NameID = 18, LabelID = 19, EnabledID = 20, TypeID = 21, 
    IntID = 22, RealID = 23, BoolID = 24, StringID = 25, TriggerID = 26, 
    MessageTrigger = 27, ThisID = 28, ReturnID = 29, SignalTransitionID = 30, 
    TimeoutTransitionID = 31, EnumID = 32, DeclarationID = 33, AttributeID = 34, 
    SignalID = 35, PortID = 36, ImportID = 37, FromID = 38, ToID = 39, SendID = 40, 
    FunctionID = 41, SwitchID = 42, CaseID = 43, DefaultID = 44, IfID = 45, 
    ElseID = 46, AsID = 47, NotIdSymbol = 48, AndIdSymbol = 49, OrIdSymbol = 50, 
    NotIdWord = 51, AndIdWord = 52, OrIdWord = 53, TrueID = 54, FalseID = 55, 
    BREAK = 56, ASSIGN = 57, DoubleArrow = 58, RightArrow = 59, LeftArrow = 60, 
    RANGE = 61, INT = 62, REAL = 63, STRING = 64, ID = 65, LINE_COMMENT = 66, 
    COMMENT = 67, LPAREN = 68, RPAREN = 69, LBRACE = 70, RBRACE = 71, LBRACKET = 72, 
    RBRACKET = 73, LESSTHAN = 74, GREATERTHAN = 75, COLON = 76, SEMI = 77, 
    COMMA = 78, UNDER = 79, DOT = 80, PLUS = 81, MINUS = 82, MULT = 83, 
    DIV = 84, PIPE = 85, REF = 86, CONST = 87, NEWLINE = 88, WS = 89
  };

  enum {
    RuleTimerNameID = 0, RuleAttributeAssignStatement = 1, RuleAtom = 2, 
    RuleIrdlDecl = 3, RuleRequirementBody = 4, RuleAliasDef = 5, RuleDeclarations = 6, 
    RuleComponentDecl = 7, RuleComponentBody = 8, RuleActorDecl = 9, RuleActorBody = 10, 
    RuleDescriptionDecl = 11, RuleSequenceDecl = 12, RuleStateDecl = 13, 
    RuleLifelineList = 14, RuleLifelineListOptional = 15, RuleMessageSignal = 16, 
    RuleMessageSignalBody = 17, RuleMessageSignalBodyOptional = 18, RuleMessageDecl = 19, 
    RuleCheckDecl = 20, RuleCheckDeclBody = 21, RuleTimerDecl = 22, RuleTimeOutDecl = 23, 
    RuleAltDecl = 24, RuleAltBody = 25, RuleAltBodyOptional = 26, RuleDurationDecl = 27, 
    RuleContextID = 28, RuleComponentIdPath = 29, RuleSignalIdPath = 30, 
    RuleAttributeIdPath = 31, RuleSignalSend = 32, RuleCommonDecl = 33, 
    RuleImportPathDecl = 34, RuleImportPathBody = 35, RuleImportFileBody = 36, 
    RuleImportAs = 37, RuleTypeDefDecl = 38, RuleTypeDecl = 39, RuleIntTypeDecl = 40, 
    RuleRealTypeDecl = 41, RuleEnumTypeDecl = 42, RuleAttributeDecl = 43, 
    RuleLiteralValue = 44, RuleSignalParamName = 45, RuleAttributeName = 46, 
    RuleToPortName = 47, RuleLocalAssignStatement = 48, RuleSendToStatement = 49, 
    RuleSingleAssignment = 50, RuleMultiAssignment = 51, RuleSignalDecl = 52, 
    RuleParamDecl = 53, RuleFunctionDecl = 54, RuleFunctionParameters = 55, 
    RuleFunctionCall = 56, RuleFunctionCallBody = 57, RuleFunctionCallBodyOptional = 58, 
    RuleTriggerDecl = 59, RuleThisDecl = 60, RulePortDecl = 61, RuleNameDecl = 62, 
    RuleIdPath = 63, RuleStatementDecl = 64, RuleStatementBody = 65, RuleFunctionCallStatement = 66, 
    RuleNestedStatementBody = 67, RuleReturnStatement = 68, RuleBreakStatement = 69, 
    RuleOperation = 70, RuleOperationOptional = 71, RuleExpression = 72, 
    RuleExpressionOptional = 73, RuleConditionalStatement = 74, RuleIfStatement = 75, 
    RuleIfEuT = 76, RuleElseStatement = 77, RuleSwitchStatement = 78, RuleSwitchPuT = 79, 
    RuleCaseStatement = 80, RuleDefaultStatement = 81
  };

  IrdlParser(antlr4::TokenStream *input);
  ~IrdlParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class TimerNameIDContext;
  class AttributeAssignStatementContext;
  class AtomContext;
  class IrdlDeclContext;
  class RequirementBodyContext;
  class AliasDefContext;
  class DeclarationsContext;
  class ComponentDeclContext;
  class ComponentBodyContext;
  class ActorDeclContext;
  class ActorBodyContext;
  class DescriptionDeclContext;
  class SequenceDeclContext;
  class StateDeclContext;
  class LifelineListContext;
  class LifelineListOptionalContext;
  class MessageSignalContext;
  class MessageSignalBodyContext;
  class MessageSignalBodyOptionalContext;
  class MessageDeclContext;
  class CheckDeclContext;
  class CheckDeclBodyContext;
  class TimerDeclContext;
  class TimeOutDeclContext;
  class AltDeclContext;
  class AltBodyContext;
  class AltBodyOptionalContext;
  class DurationDeclContext;
  class ContextIDContext;
  class ComponentIdPathContext;
  class SignalIdPathContext;
  class AttributeIdPathContext;
  class SignalSendContext;
  class CommonDeclContext;
  class ImportPathDeclContext;
  class ImportPathBodyContext;
  class ImportFileBodyContext;
  class ImportAsContext;
  class TypeDefDeclContext;
  class TypeDeclContext;
  class IntTypeDeclContext;
  class RealTypeDeclContext;
  class EnumTypeDeclContext;
  class AttributeDeclContext;
  class LiteralValueContext;
  class SignalParamNameContext;
  class AttributeNameContext;
  class ToPortNameContext;
  class LocalAssignStatementContext;
  class SendToStatementContext;
  class SingleAssignmentContext;
  class MultiAssignmentContext;
  class SignalDeclContext;
  class ParamDeclContext;
  class FunctionDeclContext;
  class FunctionParametersContext;
  class FunctionCallContext;
  class FunctionCallBodyContext;
  class FunctionCallBodyOptionalContext;
  class TriggerDeclContext;
  class ThisDeclContext;
  class PortDeclContext;
  class NameDeclContext;
  class IdPathContext;
  class StatementDeclContext;
  class StatementBodyContext;
  class FunctionCallStatementContext;
  class NestedStatementBodyContext;
  class ReturnStatementContext;
  class BreakStatementContext;
  class OperationContext;
  class OperationOptionalContext;
  class ExpressionContext;
  class ExpressionOptionalContext;
  class ConditionalStatementContext;
  class IfStatementContext;
  class IfEuTContext;
  class ElseStatementContext;
  class SwitchStatementContext;
  class SwitchPuTContext;
  class CaseStatementContext;
  class DefaultStatementContext; 

  class  TimerNameIDContext : public antlr4::ParserRuleContext {
  public:
    TimerNameIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ContextIDContext *contextID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TimerNameIDContext* timerNameID();

  class  AttributeAssignStatementContext : public antlr4::ParserRuleContext {
  public:
    AttributeAssignStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AttributeIdPathContext *> attributeIdPath();
    AttributeIdPathContext* attributeIdPath(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *SEMI();
    LiteralValueContext *literalValue();
    SignalParamNameContext *signalParamName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttributeAssignStatementContext* attributeAssignStatement();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralValueContext *literalValue();
    SignalParamNameContext *signalParamName();
    antlr4::tree::TerminalNode *ThisID();
    antlr4::tree::TerminalNode *DOT();
    ContextIDContext *contextID();
    AttributeIdPathContext *attributeIdPath();
    TimerNameIDContext *timerNameID();
    antlr4::tree::TerminalNode *TimeOutID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomContext* atom();

  class  IrdlDeclContext : public antlr4::ParserRuleContext {
  public:
    IrdlDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ImportPathDeclContext *importPathDecl();
    antlr4::tree::TerminalNode *RequirementID();
    antlr4::tree::TerminalNode *LBRACE();
    RequirementBodyContext *requirementBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IrdlDeclContext* irdlDecl();

  class  RequirementBodyContext : public antlr4::ParserRuleContext {
  public:
    RequirementBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SequenceDeclContext *sequenceDecl();
    antlr4::tree::TerminalNode *DeclarationID();
    antlr4::tree::TerminalNode *LBRACE();
    NameDeclContext *nameDecl();
    DeclarationsContext *declarations();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RequirementBodyContext* requirementBody();

  class  AliasDefContext : public antlr4::ParserRuleContext {
  public:
    AliasDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UseID();
    antlr4::tree::TerminalNode *AsID();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();
    ComponentIdPathContext *componentIdPath();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AliasDefContext* aliasDef();

  class  DeclarationsContext : public antlr4::ParserRuleContext {
  public:
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeDeclContext *attributeDecl();
    DeclarationsContext *declarations();
    TypeDefDeclContext *typeDefDecl();
    SignalDeclContext *signalDecl();
    AliasDefContext *aliasDef();
    ComponentDeclContext *componentDecl();
    ActorDeclContext *actorDecl();
    DescriptionDeclContext *descriptionDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarationsContext* declarations();

  class  ComponentDeclContext : public antlr4::ParserRuleContext {
  public:
    ComponentDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ComponentID();
    antlr4::tree::TerminalNode *LBRACE();
    ComponentBodyContext *componentBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComponentDeclContext* componentDecl();

  class  ComponentBodyContext : public antlr4::ParserRuleContext {
  public:
    ComponentBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    CommonDeclContext *commonDecl();
    DescriptionDeclContext *descriptionDecl();
    std::vector<PortDeclContext *> portDecl();
    PortDeclContext* portDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComponentBodyContext* componentBody();

  class  ActorDeclContext : public antlr4::ParserRuleContext {
  public:
    ActorDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ActorID();
    antlr4::tree::TerminalNode *LBRACE();
    ActorBodyContext *actorBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ActorDeclContext* actorDecl();

  class  ActorBodyContext : public antlr4::ParserRuleContext {
  public:
    ActorBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    CommonDeclContext *commonDecl();
    DescriptionDeclContext *descriptionDecl();
    std::vector<PortDeclContext *> portDecl();
    PortDeclContext* portDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ActorBodyContext* actorBody();

  class  DescriptionDeclContext : public antlr4::ParserRuleContext {
  public:
    DescriptionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DescriptionID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescriptionDeclContext* descriptionDecl();

  class  SequenceDeclContext : public antlr4::ParserRuleContext {
  public:
    SequenceDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StateDeclContext *stateDecl();
    SequenceDeclContext *sequenceDecl();
    MessageDeclContext *messageDecl();
    CheckDeclContext *checkDecl();
    AltDeclContext *altDecl();
    TimerDeclContext *timerDecl();
    DurationDeclContext *durationDecl();
    AttributeAssignStatementContext *attributeAssignStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SequenceDeclContext* sequenceDecl();

  class  StateDeclContext : public antlr4::ParserRuleContext {
  public:
    StateDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StateID();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *AtID();
    LifelineListContext *lifelineList();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StateDeclContext* stateDecl();

  class  LifelineListContext : public antlr4::ParserRuleContext {
  public:
    LifelineListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AllID();
    ComponentIdPathContext *componentIdPath();
    LifelineListOptionalContext *lifelineListOptional();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LifelineListContext* lifelineList();

  class  LifelineListOptionalContext : public antlr4::ParserRuleContext {
  public:
    LifelineListOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    LifelineListContext *lifelineList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LifelineListOptionalContext* lifelineListOptional();

  class  MessageSignalContext : public antlr4::ParserRuleContext {
  public:
    MessageSignalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalIdPathContext *signalIdPath();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    MessageSignalBodyContext *messageSignalBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MessageSignalContext* messageSignal();

  class  MessageSignalBodyContext : public antlr4::ParserRuleContext {
  public:
    MessageSignalBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MessageSignalBodyOptionalContext *messageSignalBodyOptional();
    LiteralValueContext *literalValue();
    SignalParamNameContext *signalParamName();
    AttributeIdPathContext *attributeIdPath();
    antlr4::tree::TerminalNode *MULT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MessageSignalBodyContext* messageSignalBody();

  class  MessageSignalBodyOptionalContext : public antlr4::ParserRuleContext {
  public:
    MessageSignalBodyOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    MessageSignalBodyContext *messageSignalBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MessageSignalBodyOptionalContext* messageSignalBodyOptional();

  class  MessageDeclContext : public antlr4::ParserRuleContext {
  public:
    MessageDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MessageID();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ComponentIdPathContext *> componentIdPath();
    ComponentIdPathContext* componentIdPath(size_t i);
    antlr4::tree::TerminalNode *RightArrow();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *COLON();
    MessageSignalContext *messageSignal();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MessageDeclContext* messageDecl();

  class  CheckDeclContext : public antlr4::ParserRuleContext {
  public:
    CheckDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CheckID();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ComponentIdPathContext *> componentIdPath();
    ComponentIdPathContext* componentIdPath(size_t i);
    antlr4::tree::TerminalNode *RightArrow();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *COLON();
    CheckDeclBodyContext *checkDeclBody();
    SignalIdPathContext *signalIdPath();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CheckDeclContext* checkDecl();

  class  CheckDeclBodyContext : public antlr4::ParserRuleContext {
  public:
    CheckDeclBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *COMMA();
    TimeOutDeclContext *timeOutDecl();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CheckDeclBodyContext* checkDeclBody();

  class  TimerDeclContext : public antlr4::ParserRuleContext {
  public:
    TimerDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TimerID();
    antlr4::tree::TerminalNode *AtID();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MilliSekID();
    antlr4::tree::TerminalNode *SekID();
    ComponentIdPathContext *componentIdPath();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TimerDeclContext* timerDecl();

  class  TimeOutDeclContext : public antlr4::ParserRuleContext {
  public:
    TimeOutDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TimeOutID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MilliSekID();
    antlr4::tree::TerminalNode *SekID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TimeOutDeclContext* timeOutDecl();

  class  AltDeclContext : public antlr4::ParserRuleContext {
  public:
    AltDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AltID();
    antlr4::tree::TerminalNode *LBRACE();
    AltBodyOptionalContext *altBodyOptional();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AltDeclContext* altDecl();

  class  AltBodyContext : public antlr4::ParserRuleContext {
  public:
    AltBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *LBRACE();
    SequenceDeclContext *sequenceDecl();
    antlr4::tree::TerminalNode *RBRACE();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AltBodyContext* altBody();

  class  AltBodyOptionalContext : public antlr4::ParserRuleContext {
  public:
    AltBodyOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AltBodyContext *altBody();
    AltBodyOptionalContext *altBodyOptional();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AltBodyOptionalContext* altBodyOptional();

  class  DurationDeclContext : public antlr4::ParserRuleContext {
  public:
    DurationDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DurationID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LBRACE();
    SequenceDeclContext *sequenceDecl();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MilliSekID();
    antlr4::tree::TerminalNode *SekID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DurationDeclContext* durationDecl();

  class  ContextIDContext : public antlr4::ParserRuleContext {
  public:
    ContextIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NameID();
    antlr4::tree::TerminalNode *LabelID();
    antlr4::tree::TerminalNode *EnabledID();
    antlr4::tree::TerminalNode *TypeID();
    antlr4::tree::TerminalNode *AttributeID();
    antlr4::tree::TerminalNode *SignalID();
    antlr4::tree::TerminalNode *ImportID();
    antlr4::tree::TerminalNode *FromID();
    antlr4::tree::TerminalNode *ToID();
    antlr4::tree::TerminalNode *SendID();
    antlr4::tree::TerminalNode *DescriptionID();
    antlr4::tree::TerminalNode *ComponentID();
    antlr4::tree::TerminalNode *AtID();
    antlr4::tree::TerminalNode *TimeOutID();
    antlr4::tree::TerminalNode *MilliSekID();
    antlr4::tree::TerminalNode *SekID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ContextIDContext* contextID();

  class  ComponentIdPathContext : public antlr4::ParserRuleContext {
  public:
    ComponentIdPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComponentIdPathContext* componentIdPath();

  class  SignalIdPathContext : public antlr4::ParserRuleContext {
  public:
    SignalIdPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SignalIdPathContext* signalIdPath();

  class  AttributeIdPathContext : public antlr4::ParserRuleContext {
  public:
    AttributeIdPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeNameContext *attributeName();
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttributeIdPathContext* attributeIdPath();

  class  SignalSendContext : public antlr4::ParserRuleContext {
  public:
    SignalSendContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalIdPathContext *signalIdPath();
    antlr4::tree::TerminalNode *LPAREN();
    FunctionCallBodyContext *functionCallBody();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SignalSendContext* signalSend();

  class  CommonDeclContext : public antlr4::ParserRuleContext {
  public:
    CommonDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeDefDeclContext *> typeDefDecl();
    TypeDefDeclContext* typeDefDecl(size_t i);
    std::vector<AttributeDeclContext *> attributeDecl();
    AttributeDeclContext* attributeDecl(size_t i);
    std::vector<SignalDeclContext *> signalDecl();
    SignalDeclContext* signalDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CommonDeclContext* commonDecl();

  class  ImportPathDeclContext : public antlr4::ParserRuleContext {
  public:
    ImportPathDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ImportPathBodyContext *importPathBody();
    ImportPathDeclContext *importPathDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImportPathDeclContext* importPathDecl();

  class  ImportPathBodyContext : public antlr4::ParserRuleContext {
  public:
    ImportPathBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ImportID();
    antlr4::tree::TerminalNode *LESSTHAN();
    ImportFileBodyContext *importFileBody();
    antlr4::tree::TerminalNode *GREATERTHAN();
    ImportAsContext *importAs();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImportPathBodyContext* importPathBody();

  class  ImportFileBodyContext : public antlr4::ParserRuleContext {
  public:
    ImportFileBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *DIV();
    ImportFileBodyContext *importFileBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImportFileBodyContext* importFileBody();

  class  ImportAsContext : public antlr4::ParserRuleContext {
  public:
    ImportAsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AsID();
    ContextIDContext *contextID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImportAsContext* importAs();

  class  TypeDefDeclContext : public antlr4::ParserRuleContext {
  public:
    TypeDefDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TypeID();
    TypeDeclContext *typeDecl();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeDefDeclContext* typeDefDecl();

  class  TypeDeclContext : public antlr4::ParserRuleContext {
  public:
    TypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntTypeDeclContext *intTypeDecl();
    RealTypeDeclContext *realTypeDecl();
    EnumTypeDeclContext *enumTypeDecl();
    antlr4::tree::TerminalNode *BoolID();
    antlr4::tree::TerminalNode *StringID();
    ContextIDContext *contextID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeDeclContext* typeDecl();

  class  IntTypeDeclContext : public antlr4::ParserRuleContext {
  public:
    IntTypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntID();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntTypeDeclContext* intTypeDecl();

  class  RealTypeDeclContext : public antlr4::ParserRuleContext {
  public:
    RealTypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RealID();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<antlr4::tree::TerminalNode *> REAL();
    antlr4::tree::TerminalNode* REAL(size_t i);
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RealTypeDeclContext* realTypeDecl();

  class  EnumTypeDeclContext : public antlr4::ParserRuleContext {
  public:
    EnumTypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EnumID();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EnumTypeDeclContext* enumTypeDecl();

  class  AttributeDeclContext : public antlr4::ParserRuleContext {
  public:
    AttributeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AttributeID();
    TypeDeclContext *typeDecl();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *ASSIGN();
    LiteralValueContext *literalValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttributeDeclContext* attributeDecl();

  class  LiteralValueContext : public antlr4::ParserRuleContext {
  public:
    LiteralValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *TrueID();
    antlr4::tree::TerminalNode *FalseID();
    ContextIDContext *contextID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralValueContext* literalValue();

  class  SignalParamNameContext : public antlr4::ParserRuleContext {
  public:
    SignalParamNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TriggerDeclContext *triggerDecl();
    ContextIDContext *contextID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SignalParamNameContext* signalParamName();

  class  AttributeNameContext : public antlr4::ParserRuleContext {
  public:
    AttributeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ContextIDContext *contextID();
    ThisDeclContext *thisDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttributeNameContext* attributeName();

  class  ToPortNameContext : public antlr4::ParserRuleContext {
  public:
    ToPortNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ToID();
    ContextIDContext *contextID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ToPortNameContext* toPortName();

  class  LocalAssignStatementContext : public antlr4::ParserRuleContext {
  public:
    LocalAssignStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeDeclContext *typeDecl();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LocalAssignStatementContext* localAssignStatement();

  class  SendToStatementContext : public antlr4::ParserRuleContext {
  public:
    SendToStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SendID();
    SignalSendContext *signalSend();
    antlr4::tree::TerminalNode *SEMI();
    ToPortNameContext *toPortName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SendToStatementContext* sendToStatement();

  class  SingleAssignmentContext : public antlr4::ParserRuleContext {
  public:
    SingleAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeAssignStatementContext *attributeAssignStatement();
    SendToStatementContext *sendToStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SingleAssignmentContext* singleAssignment();

  class  MultiAssignmentContext : public antlr4::ParserRuleContext {
  public:
    MultiAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<SingleAssignmentContext *> singleAssignment();
    SingleAssignmentContext* singleAssignment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiAssignmentContext* multiAssignment();

  class  SignalDeclContext : public antlr4::ParserRuleContext {
  public:
    SignalDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SignalID();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ParamDeclContext *> paramDecl();
    ParamDeclContext* paramDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SignalDeclContext* signalDecl();

  class  ParamDeclContext : public antlr4::ParserRuleContext {
  public:
    ParamDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeDeclContext *typeDecl();
    ContextIDContext *contextID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamDeclContext* paramDecl();

  class  FunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FunctionID();
    TypeDeclContext *typeDecl();
    IdPathContext *idPath();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    NestedStatementBodyContext *nestedStatementBody();
    FunctionParametersContext *functionParameters();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionDeclContext* functionDecl();

  class  FunctionParametersContext : public antlr4::ParserRuleContext {
  public:
    FunctionParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamDeclContext *> paramDecl();
    ParamDeclContext* paramDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionParametersContext* functionParameters();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdPathContext *idPath();
    antlr4::tree::TerminalNode *LPAREN();
    FunctionCallBodyContext *functionCallBody();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallContext* functionCall();

  class  FunctionCallBodyContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionCallBodyOptionalContext *functionCallBodyOptional();
    LiteralValueContext *literalValue();
    SignalParamNameContext *signalParamName();
    AttributeNameContext *attributeName();
    FunctionCallContext *functionCall();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallBodyContext* functionCallBody();

  class  FunctionCallBodyOptionalContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallBodyOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    FunctionCallBodyContext *functionCallBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallBodyOptionalContext* functionCallBodyOptional();

  class  TriggerDeclContext : public antlr4::ParserRuleContext {
  public:
    TriggerDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *MessageTrigger();
    antlr4::tree::TerminalNode *TriggerID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TriggerDeclContext* triggerDecl();

  class  ThisDeclContext : public antlr4::ParserRuleContext {
  public:
    ThisDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ThisID();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ThisDeclContext* thisDecl();

  class  PortDeclContext : public antlr4::ParserRuleContext {
  public:
    PortDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PortID();
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortDeclContext* portDecl();

  class  NameDeclContext : public antlr4::ParserRuleContext {
  public:
    NameDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NameID();
    antlr4::tree::TerminalNode *COLON();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NameDeclContext* nameDecl();

  class  IdPathContext : public antlr4::ParserRuleContext {
  public:
    IdPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdPathContext* idPath();

  class  StatementDeclContext : public antlr4::ParserRuleContext {
  public:
    StatementDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementBodyContext *statementBody();
    NestedStatementBodyContext *nestedStatementBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementDeclContext* statementDecl();

  class  StatementBodyContext : public antlr4::ParserRuleContext {
  public:
    StatementBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionCallStatementContext *functionCallStatement();
    AttributeAssignStatementContext *attributeAssignStatement();
    SwitchStatementContext *switchStatement();
    ConditionalStatementContext *conditionalStatement();
    LocalAssignStatementContext *localAssignStatement();
    SendToStatementContext *sendToStatement();
    BreakStatementContext *breakStatement();
    ReturnStatementContext *returnStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementBodyContext* statementBody();

  class  FunctionCallStatementContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionCallContext *functionCall();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallStatementContext* functionCallStatement();

  class  NestedStatementBodyContext : public antlr4::ParserRuleContext {
  public:
    NestedStatementBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StatementBodyContext *> statementBody();
    StatementBodyContext* statementBody(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NestedStatementBodyContext* nestedStatementBody();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ReturnID();
    OperationContext *operation();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  BreakStatementContext : public antlr4::ParserRuleContext {
  public:
    BreakStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BreakStatementContext* breakStatement();

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    OperationOptionalContext *operationOptional();
    antlr4::tree::TerminalNode *LPAREN();
    OperationContext *operation();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *NotIdSymbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OperationContext* operation();

  class  OperationOptionalContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *op = nullptr;;
    OperationOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OperationContext *operation();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OperationOptionalContext* operationOptional();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionOptionalContext *expressionOptional();
    antlr4::tree::TerminalNode *NotIdSymbol();
    antlr4::tree::TerminalNode *NotIdWord();
    antlr4::tree::TerminalNode *MINUS();
    OperationContext *operation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  ExpressionOptionalContext : public antlr4::ParserRuleContext {
  public:
    ExpressionOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OrIdSymbol();
    antlr4::tree::TerminalNode *OrIdWord();
    antlr4::tree::TerminalNode *AndIdSymbol();
    antlr4::tree::TerminalNode *AndIdWord();
    antlr4::tree::TerminalNode *NotIdWord();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    antlr4::tree::TerminalNode *NotIdSymbol();
    antlr4::tree::TerminalNode *LESSTHAN();
    antlr4::tree::TerminalNode *GREATERTHAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionOptionalContext* expressionOptional();

  class  ConditionalStatementContext : public antlr4::ParserRuleContext {
  public:
    ConditionalStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStatementContext *ifStatement();
    ElseStatementContext *elseStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConditionalStatementContext* conditionalStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IfID();
    IfEuTContext *ifEuT();
    StatementDeclContext *statementDecl();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStatementContext* ifStatement();

  class  IfEuTContext : public antlr4::ParserRuleContext {
  public:
    IfEuTContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfEuTContext* ifEuT();

  class  ElseStatementContext : public antlr4::ParserRuleContext {
  public:
    ElseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ElseID();
    StatementDeclContext *statementDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseStatementContext* elseStatement();

  class  SwitchStatementContext : public antlr4::ParserRuleContext {
  public:
    SwitchStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SwitchID();
    SwitchPuTContext *switchPuT();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    DefaultStatementContext *defaultStatement();
    std::vector<CaseStatementContext *> caseStatement();
    CaseStatementContext* caseStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SwitchStatementContext* switchStatement();

  class  SwitchPuTContext : public antlr4::ParserRuleContext {
  public:
    SwitchPuTContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SwitchPuTContext* switchPuT();

  class  CaseStatementContext : public antlr4::ParserRuleContext {
  public:
    CaseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CaseID();
    LiteralValueContext *literalValue();
    antlr4::tree::TerminalNode *COLON();
    NestedStatementBodyContext *nestedStatementBody();
    std::vector<StatementBodyContext *> statementBody();
    StatementBodyContext* statementBody(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CaseStatementContext* caseStatement();

  class  DefaultStatementContext : public antlr4::ParserRuleContext {
  public:
    DefaultStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DefaultID();
    antlr4::tree::TerminalNode *COLON();
    NestedStatementBodyContext *nestedStatementBody();
    std::vector<StatementBodyContext *> statementBody();
    StatementBodyContext* statementBody(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DefaultStatementContext* defaultStatement();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

