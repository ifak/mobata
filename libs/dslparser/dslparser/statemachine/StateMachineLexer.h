
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/StateMachine.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  StateMachineLexer : public antlr4::Lexer {
public:
  enum {
    ActionID = 1, StateMachineID = 2, SimpleStateID = 3, SignalTransitionID = 4, 
    JunctionTransitionID = 5, CompositeStateID = 6, JunctionStateID = 7, 
    ConcurrentStateID = 8, FinalStateID = 9, RefSignalID = 10, RefPortID = 11, 
    ValueID = 12, GuardID = 13, RegionID = 14, SourceStateID = 15, TargetStateID = 16, 
    InitStateID = 17, EntryActionID = 18, ExitActionID = 19, IGNORE_NEWLINE = 20, 
    NameID = 21, LabelID = 22, EnabledID = 23, TypeID = 24, IntID = 25, 
    RealID = 26, BoolID = 27, StringID = 28, TriggerID = 29, MessageTrigger = 30, 
    ThisID = 31, ReturnID = 32, TimeoutTransitionID = 33, EnumID = 34, DeclarationID = 35, 
    DescriptionID = 36, AttributeID = 37, SignalID = 38, PortID = 39, ImportID = 40, 
    FromID = 41, ToID = 42, SendID = 43, FunctionID = 44, SwitchID = 45, 
    CaseID = 46, DefaultID = 47, IfID = 48, ElseID = 49, AsID = 50, AtID = 51, 
    NotIdSymbol = 52, AndIdSymbol = 53, OrIdSymbol = 54, NotIdWord = 55, 
    AndIdWord = 56, OrIdWord = 57, TrueID = 58, FalseID = 59, BREAK = 60, 
    ASSIGN = 61, DoubleArrow = 62, RightArrow = 63, LeftArrow = 64, RANGE = 65, 
    INT = 66, REAL = 67, STRING = 68, ID = 69, LINE_COMMENT = 70, COMMENT = 71, 
    LPAREN = 72, RPAREN = 73, LBRACE = 74, RBRACE = 75, LBRACKET = 76, RBRACKET = 77, 
    LESSTHAN = 78, GREATERTHAN = 79, COLON = 80, SEMI = 81, COMMA = 82, 
    UNDER = 83, DOT = 84, PLUS = 85, MINUS = 86, MULT = 87, DIV = 88, PIPE = 89, 
    REF = 90, CONST = 91, NEWLINE = 92, WS = 93
  };

  StateMachineLexer(antlr4::CharStream *input);
  ~StateMachineLexer();

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

