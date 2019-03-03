
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/CommonLexer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  CommonLexer : public antlr4::Lexer {
public:
  enum {
    NameID = 1, LabelID = 2, EnabledID = 3, TypeID = 4, IntID = 5, RealID = 6, 
    BoolID = 7, StringID = 8, TriggerID = 9, MessageTrigger = 10, ThisID = 11, 
    ReturnID = 12, SignalTransitionID = 13, TimeoutTransitionID = 14, EnumID = 15, 
    DeclarationID = 16, DescriptionID = 17, AttributeID = 18, SignalID = 19, 
    PortID = 20, ImportID = 21, FromID = 22, ToID = 23, SendID = 24, FunctionID = 25, 
    SwitchID = 26, CaseID = 27, DefaultID = 28, IfID = 29, ElseID = 30, 
    AsID = 31, AtID = 32, NotIdSymbol = 33, AndIdSymbol = 34, OrIdSymbol = 35, 
    NotIdWord = 36, AndIdWord = 37, OrIdWord = 38, TrueID = 39, FalseID = 40, 
    BREAK = 41, ASSIGN = 42, DoubleArrow = 43, RightArrow = 44, LeftArrow = 45, 
    RANGE = 46, INT = 47, REAL = 48, STRING = 49, ID = 50, LINE_COMMENT = 51, 
    COMMENT = 52, LPAREN = 53, RPAREN = 54, LBRACE = 55, RBRACE = 56, LBRACKET = 57, 
    RBRACKET = 58, LESSTHAN = 59, GREATERTHAN = 60, COLON = 61, SEMI = 62, 
    COMMA = 63, UNDER = 64, DOT = 65, PLUS = 66, MINUS = 67, MULT = 68, 
    DIV = 69, PIPE = 70, REF = 71, CONST = 72, NEWLINE = 73, WS = 74
  };

  CommonLexer(antlr4::CharStream *input);
  ~CommonLexer();

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

