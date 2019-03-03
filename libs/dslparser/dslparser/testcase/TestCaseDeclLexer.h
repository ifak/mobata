
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/TestCaseDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  TestCaseDeclLexer : public antlr4::Lexer {
public:
  enum {
    MessageID = 1, TimeOutID = 2, CheckID = 3, AltID = 4, TimerID = 5, ComponentID = 6, 
    DeclarationID = 7, TestCaseID = 8, MilliSekID = 9, SekID = 10, IGNORE_NEWLINE = 11, 
    NameID = 12, LabelID = 13, EnabledID = 14, TypeID = 15, IntID = 16, 
    RealID = 17, BoolID = 18, StringID = 19, TriggerID = 20, MessageTrigger = 21, 
    ThisID = 22, ReturnID = 23, SignalTransitionID = 24, TimeoutTransitionID = 25, 
    EnumID = 26, DescriptionID = 27, AttributeID = 28, SignalID = 29, PortID = 30, 
    ImportID = 31, FromID = 32, ToID = 33, SendID = 34, FunctionID = 35, 
    SwitchID = 36, CaseID = 37, DefaultID = 38, IfID = 39, ElseID = 40, 
    AsID = 41, AtID = 42, NotIdSymbol = 43, AndIdSymbol = 44, OrIdSymbol = 45, 
    NotIdWord = 46, AndIdWord = 47, OrIdWord = 48, TrueID = 49, FalseID = 50, 
    BREAK = 51, ASSIGN = 52, DoubleArrow = 53, RightArrow = 54, LeftArrow = 55, 
    RANGE = 56, INT = 57, REAL = 58, STRING = 59, ID = 60, LINE_COMMENT = 61, 
    COMMENT = 62, LPAREN = 63, RPAREN = 64, LBRACE = 65, RBRACE = 66, LBRACKET = 67, 
    RBRACKET = 68, LESSTHAN = 69, GREATERTHAN = 70, COLON = 71, SEMI = 72, 
    COMMA = 73, UNDER = 74, DOT = 75, PLUS = 76, MINUS = 77, MULT = 78, 
    DIV = 79, PIPE = 80, REF = 81, CONST = 82, NEWLINE = 83, WS = 84
  };

  TestCaseDeclLexer(antlr4::CharStream *input);
  ~TestCaseDeclLexer();

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

