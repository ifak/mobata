/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/Spenat.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SpenatLexer : public antlr4::Lexer {
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

  SpenatLexer(antlr4::CharStream *input);
  ~SpenatLexer();

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

