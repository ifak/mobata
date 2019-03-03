
// Generated from /home/kra/SWDevelop/mobata/libs/dslparser/dslparser/grammars/DiagnosisDecl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  DiagnosisDeclLexer : public antlr4::Lexer {
public:
  enum {
    ComponentsID = 1, RuleID = 2, ComponentID = 3, BaseTypeID = 4, ParallelSequenceID = 5, 
    SignalsID = 6, ParallelID = 7, LoopID = 8, SequenceID = 9, DescriptionID = 10, 
    MessageID = 11, UseID = 12, ConditionID = 13, CheckID = 14, DiagnosisID = 15, 
    IGNORE_NEWLINE = 16, NameID = 17, LabelID = 18, EnabledID = 19, TypeID = 20, 
    IntID = 21, RealID = 22, BoolID = 23, StringID = 24, TriggerID = 25, 
    MessageTrigger = 26, ThisID = 27, ReturnID = 28, SignalTransitionID = 29, 
    TimeoutTransitionID = 30, EnumID = 31, DeclarationID = 32, AttributeID = 33, 
    SignalID = 34, PortID = 35, ImportID = 36, FromID = 37, ToID = 38, SendID = 39, 
    FunctionID = 40, SwitchID = 41, CaseID = 42, DefaultID = 43, IfID = 44, 
    ElseID = 45, AsID = 46, AtID = 47, NotIdSymbol = 48, AndIdSymbol = 49, 
    OrIdSymbol = 50, NotIdWord = 51, AndIdWord = 52, OrIdWord = 53, TrueID = 54, 
    FalseID = 55, BREAK = 56, ASSIGN = 57, DoubleArrow = 58, RightArrow = 59, 
    LeftArrow = 60, RANGE = 61, INT = 62, REAL = 63, STRING = 64, ID = 65, 
    LINE_COMMENT = 66, COMMENT = 67, LPAREN = 68, RPAREN = 69, LBRACE = 70, 
    RBRACE = 71, LBRACKET = 72, RBRACKET = 73, LESSTHAN = 74, GREATERTHAN = 75, 
    COLON = 76, SEMI = 77, COMMA = 78, UNDER = 79, DOT = 80, PLUS = 81, 
    MINUS = 82, MULT = 83, DIV = 84, PIPE = 85, REF = 86, CONST = 87, NEWLINE = 88, 
    WS = 89
  };

  DiagnosisDeclLexer(antlr4::CharStream *input);
  ~DiagnosisDeclLexer();

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

