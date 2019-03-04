
// Generated from /home/kra/SWDevelop/mobata/libs/dslparser/dslparser/grammars/TrafficSimDecl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  TrafficSimDeclLexer : public antlr4::Lexer {
public:
  enum {
    TRAFFICSIMULATION = 1, Sensor = 2, Intersection = 3, Step = 4, Arm = 5, 
    HasTrafficLight = 6, Accident = 7, NeighboringTrafficLights = 8, TrafficLight = 9, 
    Turns = 10, Lanes = 11, States = 12, InnerConnections = 13, OuterConnection = 14, 
    Duration = 15, MinDur = 16, MaxDur = 17, Factor = 18, Measured = 19, 
    Lane = 20, Message = 21, VehicleMovement = 22, Phase = 23, Phases = 24, 
    TransitionPhases = 25, Transition = 26, Transitions = 27, Trigger = 28, 
    VehiclePerHour = 29, VehicleDistribution = 30, LVehicleDistribution = 31, 
    Label = 32, Bicycle = 33, Bus = 34, Moped = 35, Motorcycle = 36, Car = 37, 
    Emergency = 38, Truck = 39, Start = 40, StartArm = 41, End = 42, IGNORE_NEWLINE = 43, 
    NameID = 44, LabelID = 45, EnabledID = 46, TypeID = 47, IntID = 48, 
    RealID = 49, BoolID = 50, StringID = 51, TriggerID = 52, MessageTrigger = 53, 
    ThisID = 54, ReturnID = 55, SignalTransitionID = 56, TimeoutTransitionID = 57, 
    EnumID = 58, DeclarationID = 59, DescriptionID = 60, AttributeID = 61, 
    SignalID = 62, PortID = 63, ImportID = 64, FromID = 65, ToID = 66, SendID = 67, 
    FunctionID = 68, SwitchID = 69, CaseID = 70, DefaultID = 71, IfID = 72, 
    ElseID = 73, AsID = 74, AtID = 75, NotIdSymbol = 76, AndIdSymbol = 77, 
    OrIdSymbol = 78, NotIdWord = 79, AndIdWord = 80, OrIdWord = 81, TrueID = 82, 
    FalseID = 83, BREAK = 84, ASSIGN = 85, DoubleArrow = 86, RightArrow = 87, 
    LeftArrow = 88, RANGE = 89, INT = 90, REAL = 91, STRING = 92, ID = 93, 
    LINE_COMMENT = 94, COMMENT = 95, LPAREN = 96, RPAREN = 97, LBRACE = 98, 
    RBRACE = 99, LBRACKET = 100, RBRACKET = 101, LESSTHAN = 102, GREATERTHAN = 103, 
    COLON = 104, SEMI = 105, COMMA = 106, UNDER = 107, DOT = 108, PLUS = 109, 
    MINUS = 110, MULT = 111, DIV = 112, PIPE = 113, REF = 114, CONST = 115, 
    NEWLINE = 116, WS = 117
  };

  TrafficSimDeclLexer(antlr4::CharStream *input);
  ~TrafficSimDeclLexer();

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

