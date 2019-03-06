
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/SutDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SutDeclLexer : public antlr4::Lexer {
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

  SutDeclLexer(antlr4::CharStream *input);
  ~SutDeclLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

