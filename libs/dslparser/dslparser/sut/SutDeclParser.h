
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/SutDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SutDeclParser : public antlr4::Parser {
public:
  enum {
    SutComponentID = 1, SutID = 2, IGNORE_NEWLINE = 3, NameID = 4, LabelID = 5, 
    EnabledID = 6, TypeID = 7, IntID = 8, RealID = 9, BoolID = 10, StringID = 11, 
    TriggerID = 12, MessageTrigger = 13, ThisID = 14, ReturnID = 15, SignalTransitionID = 16, 
    TimeoutTransitionID = 17, EnumID = 18, DeclarationID = 19, DescriptionID = 20, 
    AttributeID = 21, SignalID = 22, PortID = 23, ImportID = 24, FromID = 25, 
    ToID = 26, SendID = 27, FunctionID = 28, SwitchID = 29, CaseID = 30, 
    DefaultID = 31, IfID = 32, ElseID = 33, AsID = 34, AtID = 35, NotIdSymbol = 36, 
    AndIdSymbol = 37, OrIdSymbol = 38, NotIdWord = 39, AndIdWord = 40, OrIdWord = 41, 
    TrueID = 42, FalseID = 43, BREAK = 44, ASSIGN = 45, DoubleArrow = 46, 
    RightArrow = 47, LeftArrow = 48, RANGE = 49, INT = 50, REAL = 51, STRING = 52, 
    ID = 53, LINE_COMMENT = 54, COMMENT = 55, LPAREN = 56, RPAREN = 57, 
    LBRACE = 58, RBRACE = 59, LBRACKET = 60, RBRACKET = 61, LESSTHAN = 62, 
    GREATERTHAN = 63, COLON = 64, SEMI = 65, COMMA = 66, UNDER = 67, DOT = 68, 
    PLUS = 69, MINUS = 70, MULT = 71, DIV = 72, PIPE = 73, REF = 74, CONST = 75, 
    NEWLINE = 76, WS = 77
  };

  enum {
    RuleSutDecl = 0, RuleSutBody = 1, RuleSutBodyOptional = 2, RuleSutCompDecl = 3, 
    RuleSutCompBody = 4, RuleSutCompBodyOtional = 5, RuleContextID = 6, 
    RuleComponentIdPath = 7, RuleSignalIdPath = 8, RuleAttributeIdPath = 9, 
    RuleSignalSend = 10, RuleCommonDecl = 11, RuleImportPathDecl = 12, RuleImportPathBody = 13, 
    RuleImportFileBody = 14, RuleImportAs = 15, RuleTypeDefDecl = 16, RuleTypeDecl = 17, 
    RuleIntTypeDecl = 18, RuleRealTypeDecl = 19, RuleEnumTypeDecl = 20, 
    RuleAttributeDecl = 21, RuleLiteralValue = 22, RuleSignalParamName = 23, 
    RuleAttributeName = 24, RuleToPortName = 25, RuleAttributeAssignStatement = 26, 
    RuleLocalAssignStatement = 27, RuleSendToStatement = 28, RuleSingleAssignment = 29, 
    RuleMultiAssignment = 30, RuleSignalDecl = 31, RuleParamDecl = 32, RuleFunctionDecl = 33, 
    RuleFunctionParameters = 34, RuleFunctionCall = 35, RuleFunctionCallBody = 36, 
    RuleFunctionCallBodyOptional = 37, RuleTriggerDecl = 38, RuleThisDecl = 39, 
    RulePortDecl = 40, RuleNameDecl = 41, RuleIdPath = 42, RuleStatementDecl = 43, 
    RuleStatementBody = 44, RuleFunctionCallStatement = 45, RuleNestedStatementBody = 46, 
    RuleReturnStatement = 47, RuleBreakStatement = 48, RuleOperation = 49, 
    RuleOperationOptional = 50, RuleExpression = 51, RuleExpressionOptional = 52, 
    RuleConditionalStatement = 53, RuleIfStatement = 54, RuleIfEuT = 55, 
    RuleElseStatement = 56, RuleSwitchStatement = 57, RuleSwitchPuT = 58, 
    RuleCaseStatement = 59, RuleDefaultStatement = 60, RuleAtom = 61
  };

  SutDeclParser(antlr4::TokenStream *input);
  ~SutDeclParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class SutDeclContext;
  class SutBodyContext;
  class SutBodyOptionalContext;
  class SutCompDeclContext;
  class SutCompBodyContext;
  class SutCompBodyOtionalContext;
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
  class AtomContext; 

  class  SutDeclContext : public antlr4::ParserRuleContext {
  public:
    SutDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SutID();
    antlr4::tree::TerminalNode *LBRACE();
    SutBodyContext *sutBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SutDeclContext* sutDecl();

  class  SutBodyContext : public antlr4::ParserRuleContext {
  public:
    SutBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    SutBodyOptionalContext *sutBodyOptional();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SutBodyContext* sutBody();

  class  SutBodyOptionalContext : public antlr4::ParserRuleContext {
  public:
    SutBodyOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeDeclContext *attributeDecl();
    SutBodyOptionalContext *sutBodyOptional();
    SutCompDeclContext *sutCompDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SutBodyOptionalContext* sutBodyOptional();

  class  SutCompDeclContext : public antlr4::ParserRuleContext {
  public:
    SutCompDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SutComponentID();
    antlr4::tree::TerminalNode *LBRACE();
    SutCompBodyContext *sutCompBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SutCompDeclContext* sutCompDecl();

  class  SutCompBodyContext : public antlr4::ParserRuleContext {
  public:
    SutCompBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameDeclContext *nameDecl();
    SutCompBodyOtionalContext *sutCompBodyOtional();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SutCompBodyContext* sutCompBody();

  class  SutCompBodyOtionalContext : public antlr4::ParserRuleContext {
  public:
    SutCompBodyOtionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeDeclContext *attributeDecl();
    SutCompBodyOtionalContext *sutCompBodyOtional();
    PortDeclContext *portDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SutCompBodyOtionalContext* sutCompBodyOtional();

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
    antlr4::tree::TerminalNode *SignalID();
    antlr4::tree::TerminalNode *PortID();
    antlr4::tree::TerminalNode *ImportID();
    antlr4::tree::TerminalNode *FromID();
    antlr4::tree::TerminalNode *ToID();
    antlr4::tree::TerminalNode *SendID();
    antlr4::tree::TerminalNode *AsID();
    antlr4::tree::TerminalNode *SutComponentID();
    antlr4::tree::TerminalNode *SutID();

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

