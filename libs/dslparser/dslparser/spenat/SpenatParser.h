
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/Spenat.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SpenatParser : public antlr4::Parser {
public:
  enum {
    ActionID = 1, SpenatID = 2, PlaceID = 3, RefSignalID = 4, RefPortID = 5, 
    ValueID = 6, GuardID = 7, InitialID = 8, PreID = 9, PostID = 10, IGNORE_NEWLINE = 11, 
    NameID = 12, LabelID = 13, EnabledID = 14, TypeID = 15, IntID = 16, 
    RealID = 17, BoolID = 18, StringID = 19, TriggerID = 20, MessageTrigger = 21, 
    ThisID = 22, ReturnID = 23, SignalTransitionID = 24, TimeoutTransitionID = 25, 
    EnumID = 26, DeclarationID = 27, DescriptionID = 28, AttributeID = 29, 
    SignalID = 30, PortID = 31, ImportID = 32, FromID = 33, ToID = 34, SendID = 35, 
    FunctionID = 36, SwitchID = 37, CaseID = 38, DefaultID = 39, IfID = 40, 
    ElseID = 41, AsID = 42, AtID = 43, NotIdSymbol = 44, AndIdSymbol = 45, 
    OrIdSymbol = 46, NotIdWord = 47, AndIdWord = 48, OrIdWord = 49, TrueID = 50, 
    FalseID = 51, BREAK = 52, ASSIGN = 53, DoubleArrow = 54, RightArrow = 55, 
    LeftArrow = 56, RANGE = 57, INT = 58, REAL = 59, STRING = 60, ID = 61, 
    LINE_COMMENT = 62, COMMENT = 63, LPAREN = 64, RPAREN = 65, LBRACE = 66, 
    RBRACE = 67, LBRACKET = 68, RBRACKET = 69, LESSTHAN = 70, GREATERTHAN = 71, 
    COLON = 72, SEMI = 73, COMMA = 74, UNDER = 75, DOT = 76, PLUS = 77, 
    MINUS = 78, MULT = 79, DIV = 80, PIPE = 81, REF = 82, CONST = 83, NEWLINE = 84, 
    WS = 85
  };

  enum {
    RuleSpenatDecl = 0, RuleSpenatBody = 1, RuleSpenatBodyOptional = 2, 
    RulePlaceDecl = 3, RulePlaceBody = 4, RuleGuardDecl = 5, RuleMultiExpression = 6, 
    RuleMultiExpressionOptional = 7, RuleActionDecl = 8, RuleTransitionDecl = 9, 
    RuleSignalTransitionDecl = 10, RuleSignalTransitionBody = 11, RuleTimeoutTransitionDecl = 12, 
    RuleTimeoutTransitionBody = 13, RuleRefSignalDecl = 14, RuleRefPortDecl = 15, 
    RulePreDecl = 16, RulePostDecl = 17, RuleTimeoutDecl = 18, RuleInitialDecl = 19, 
    RuleFunctionCall = 20, RuleContextID = 21, RuleComponentIdPath = 22, 
    RuleSignalIdPath = 23, RuleAttributeIdPath = 24, RuleSignalSend = 25, 
    RuleCommonDecl = 26, RuleImportPathDecl = 27, RuleImportPathBody = 28, 
    RuleImportFileBody = 29, RuleImportAs = 30, RuleTypeDefDecl = 31, RuleTypeDecl = 32, 
    RuleIntTypeDecl = 33, RuleRealTypeDecl = 34, RuleEnumTypeDecl = 35, 
    RuleAttributeDecl = 36, RuleLiteralValue = 37, RuleSignalParamName = 38, 
    RuleAttributeName = 39, RuleToPortName = 40, RuleAttributeAssignStatement = 41, 
    RuleLocalAssignStatement = 42, RuleSendToStatement = 43, RuleSingleAssignment = 44, 
    RuleMultiAssignment = 45, RuleSignalDecl = 46, RuleParamDecl = 47, RuleFunctionDecl = 48, 
    RuleFunctionParameters = 49, RuleFunctionCallBody = 50, RuleFunctionCallBodyOptional = 51, 
    RuleTriggerDecl = 52, RuleThisDecl = 53, RulePortDecl = 54, RuleNameDecl = 55, 
    RuleIdPath = 56, RuleStatementDecl = 57, RuleStatementBody = 58, RuleFunctionCallStatement = 59, 
    RuleNestedStatementBody = 60, RuleReturnStatement = 61, RuleBreakStatement = 62, 
    RuleOperation = 63, RuleOperationOptional = 64, RuleExpression = 65, 
    RuleExpressionOptional = 66, RuleConditionalStatement = 67, RuleIfStatement = 68, 
    RuleIfEuT = 69, RuleElseStatement = 70, RuleSwitchStatement = 71, RuleSwitchPuT = 72, 
    RuleCaseStatement = 73, RuleDefaultStatement = 74, RuleAtom = 75
  };

  SpenatParser(antlr4::TokenStream *input);
  ~SpenatParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class SpenatDeclContext;
  class SpenatBodyContext;
  class SpenatBodyOptionalContext;
  class PlaceDeclContext;
  class PlaceBodyContext;
  class GuardDeclContext;
  class MultiExpressionContext;
  class MultiExpressionOptionalContext;
  class ActionDeclContext;
  class TransitionDeclContext;
  class SignalTransitionDeclContext;
  class SignalTransitionBodyContext;
  class TimeoutTransitionDeclContext;
  class TimeoutTransitionBodyContext;
  class RefSignalDeclContext;
  class RefPortDeclContext;
  class PreDeclContext;
  class PostDeclContext;
  class TimeoutDeclContext;
  class InitialDeclContext;
  class FunctionCallContext;
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
  class AttributeAssignStatementContext;
  class LocalAssignStatementContext;
  class SendToStatementContext;
  class SingleAssignmentContext;
  class MultiAssignmentContext;
  class SignalDeclContext;
  class ParamDeclContext;
  class FunctionDeclContext;
  class FunctionParametersContext;
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
  class AtomContext; 

  class  SpenatDeclContext : public antlr4::ParserRuleContext {
  public:
    SpenatDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SpenatID();
    antlr4::tree::TerminalNode *LBRACE();
    SpenatBodyContext *spenatBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SpenatDeclContext* spenatDecl();

  class  SpenatBodyContext : public antlr4::ParserRuleContext {
  public:
    SpenatBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    SpenatBodyOptionalContext *spenatBodyOptional();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SpenatBodyContext* spenatBody();

  class  SpenatBodyOptionalContext : public antlr4::ParserRuleContext {
  public:
    SpenatBodyOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeDefDeclContext *typeDefDecl();
    SpenatBodyOptionalContext *spenatBodyOptional();
    AttributeDeclContext *attributeDecl();
    SignalDeclContext *signalDecl();
    FunctionDeclContext *functionDecl();
    PortDeclContext *portDecl();
    PlaceDeclContext *placeDecl();
    TransitionDeclContext *transitionDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SpenatBodyOptionalContext* spenatBodyOptional();

  class  PlaceDeclContext : public antlr4::ParserRuleContext {
  public:
    PlaceDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PlaceID();
    antlr4::tree::TerminalNode *LBRACE();
    PlaceBodyContext *placeBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PlaceDeclContext* placeDecl();

  class  PlaceBodyContext : public antlr4::ParserRuleContext {
  public:
    PlaceBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    InitialDeclContext *initialDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PlaceBodyContext* placeBody();

  class  GuardDeclContext : public antlr4::ParserRuleContext {
  public:
    GuardDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GuardID();
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();
    MultiExpressionContext *multiExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GuardDeclContext* guardDecl();

  class  MultiExpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiExpressionContext* multiExpression();

  class  MultiExpressionOptionalContext : public antlr4::ParserRuleContext {
  public:
    MultiExpressionOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiExpressionOptionalContext* multiExpressionOptional();

  class  ActionDeclContext : public antlr4::ParserRuleContext {
  public:
    ActionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ActionID();
    antlr4::tree::TerminalNode *COLON();
    SingleAssignmentContext *singleAssignment();
    MultiAssignmentContext *multiAssignment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ActionDeclContext* actionDecl();

  class  TransitionDeclContext : public antlr4::ParserRuleContext {
  public:
    TransitionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalTransitionDeclContext *signalTransitionDecl();
    TimeoutTransitionDeclContext *timeoutTransitionDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TransitionDeclContext* transitionDecl();

  class  SignalTransitionDeclContext : public antlr4::ParserRuleContext {
  public:
    SignalTransitionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SignalTransitionID();
    antlr4::tree::TerminalNode *LBRACE();
    SignalTransitionBodyContext *signalTransitionBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SignalTransitionDeclContext* signalTransitionDecl();

  class  SignalTransitionBodyContext : public antlr4::ParserRuleContext {
  public:
    SignalTransitionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    RefSignalDeclContext *refSignalDecl();
    RefPortDeclContext *refPortDecl();
    GuardDeclContext *guardDecl();
    ActionDeclContext *actionDecl();
    PreDeclContext *preDecl();
    PostDeclContext *postDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SignalTransitionBodyContext* signalTransitionBody();

  class  TimeoutTransitionDeclContext : public antlr4::ParserRuleContext {
  public:
    TimeoutTransitionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TimeoutTransitionID();
    antlr4::tree::TerminalNode *LBRACE();
    TimeoutTransitionBodyContext *timeoutTransitionBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TimeoutTransitionDeclContext* timeoutTransitionDecl();

  class  TimeoutTransitionBodyContext : public antlr4::ParserRuleContext {
  public:
    TimeoutTransitionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    TimeoutDeclContext *timeoutDecl();
    GuardDeclContext *guardDecl();
    ActionDeclContext *actionDecl();
    PreDeclContext *preDecl();
    PostDeclContext *postDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TimeoutTransitionBodyContext* timeoutTransitionBody();

  class  RefSignalDeclContext : public antlr4::ParserRuleContext {
  public:
    RefSignalDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RefSignalID();
    antlr4::tree::TerminalNode *COLON();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RefSignalDeclContext* refSignalDecl();

  class  RefPortDeclContext : public antlr4::ParserRuleContext {
  public:
    RefPortDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RefPortID();
    antlr4::tree::TerminalNode *COLON();
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RefPortDeclContext* refPortDecl();

  class  PreDeclContext : public antlr4::ParserRuleContext {
  public:
    PreDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PreID();
    antlr4::tree::TerminalNode *COLON();
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PreDeclContext* preDecl();

  class  PostDeclContext : public antlr4::ParserRuleContext {
  public:
    PostDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PostID();
    antlr4::tree::TerminalNode *COLON();
    std::vector<ContextIDContext *> contextID();
    ContextIDContext* contextID(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PostDeclContext* postDecl();

  class  TimeoutDeclContext : public antlr4::ParserRuleContext {
  public:
    TimeoutDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ValueID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TimeoutDeclContext* timeoutDecl();

  class  InitialDeclContext : public antlr4::ParserRuleContext {
  public:
    InitialDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *InitialID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *TrueID();
    antlr4::tree::TerminalNode *FalseID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InitialDeclContext* initialDecl();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ContextIDContext *contextID();
    antlr4::tree::TerminalNode *LPAREN();
    FunctionCallBodyContext *functionCallBody();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallContext* functionCall();

  class  ContextIDContext : public antlr4::ParserRuleContext {
  public:
    ContextIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NameID();
    antlr4::tree::TerminalNode *LabelID();
    antlr4::tree::TerminalNode *EnabledID();
    antlr4::tree::TerminalNode *TypeID();
    antlr4::tree::TerminalNode *MessageTrigger();
    antlr4::tree::TerminalNode *TriggerID();
    antlr4::tree::TerminalNode *AttributeID();
    antlr4::tree::TerminalNode *FunctionID();
    antlr4::tree::TerminalNode *SignalID();
    antlr4::tree::TerminalNode *PortID();
    antlr4::tree::TerminalNode *ImportID();
    antlr4::tree::TerminalNode *FromID();
    antlr4::tree::TerminalNode *ToID();
    antlr4::tree::TerminalNode *SendID();
    antlr4::tree::TerminalNode *AsID();
    antlr4::tree::TerminalNode *ActionID();
    antlr4::tree::TerminalNode *SpenatID();
    antlr4::tree::TerminalNode *PlaceID();
    antlr4::tree::TerminalNode *SignalTransitionID();
    antlr4::tree::TerminalNode *TimeoutTransitionID();
    antlr4::tree::TerminalNode *RefSignalID();
    antlr4::tree::TerminalNode *RefPortID();
    antlr4::tree::TerminalNode *ValueID();
    antlr4::tree::TerminalNode *GuardID();
    antlr4::tree::TerminalNode *InitialID();
    antlr4::tree::TerminalNode *PreID();
    antlr4::tree::TerminalNode *PostID();

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

  class  AttributeAssignStatementContext : public antlr4::ParserRuleContext {
  public:
    AttributeAssignStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeNameContext *attributeName();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttributeAssignStatementContext* attributeAssignStatement();

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

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalParamNameContext *signalParamName();
    AttributeNameContext *attributeName();
    FunctionCallContext *functionCall();
    LiteralValueContext *literalValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomContext* atom();


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

