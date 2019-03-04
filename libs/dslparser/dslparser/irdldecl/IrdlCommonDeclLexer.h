
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/IrdlCommonDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  IrdlCommonDeclLexer : public antlr4::Lexer {
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

  IrdlCommonDeclLexer(antlr4::CharStream *input);
  ~IrdlCommonDeclLexer();

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

