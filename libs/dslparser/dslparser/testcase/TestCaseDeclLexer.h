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

// Generated from C:/Users/s_phs.DESKTOP-9GA53KK/Documents/mobata/libs/dslparser/dslparser/grammars/TestCaseDecl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  TestCaseDeclLexer : public antlr4::Lexer {
public:
  enum {
    MessageID = 1, TimeOutID = 2, CheckID = 3, UuidID = 4, AltID = 5, TimerID = 6, 
    AccuracyID = 7, ComponentID = 8, DeclarationID = 9, TestCaseID = 10, 
    MilliSekID = 11, SekID = 12, IGNORE_NEWLINE = 13, NameID = 14, LabelID = 15, 
    EnabledID = 16, TypeID = 17, IntID = 18, RealID = 19, BoolID = 20, StringID = 21, 
    TriggerID = 22, MessageTrigger = 23, ThisID = 24, ReturnID = 25, SignalTransitionID = 26, 
    TimeoutTransitionID = 27, EnumID = 28, DescriptionID = 29, AttributeID = 30, 
    SignalID = 31, PortID = 32, ImportID = 33, FromID = 34, ToID = 35, SendID = 36, 
    FunctionID = 37, SwitchID = 38, CaseID = 39, DefaultID = 40, IfID = 41, 
    ElseID = 42, AsID = 43, AtID = 44, NotIdSymbol = 45, AndIdSymbol = 46, 
    OrIdSymbol = 47, NotIdWord = 48, AndIdWord = 49, OrIdWord = 50, TrueID = 51, 
    FalseID = 52, BREAK = 53, ASSIGN = 54, DoubleArrow = 55, RightArrow = 56, 
    LeftArrow = 57, RANGE = 58, INT = 59, REAL = 60, STRING = 61, ID = 62, 
    LINE_COMMENT = 63, COMMENT = 64, LPAREN = 65, RPAREN = 66, LBRACE = 67, 
    RBRACE = 68, LBRACKET = 69, RBRACKET = 70, LESSTHAN = 71, GREATERTHAN = 72, 
    COLON = 73, SEMI = 74, COMMA = 75, UNDER = 76, DOT = 77, PLUS = 78, 
    MINUS = 79, MULT = 80, DIV = 81, PIPE = 82, REF = 83, CONST = 84, NEWLINE = 85, 
    WS = 86
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

