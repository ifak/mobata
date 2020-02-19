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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/SimSystemDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SimSystemDeclLexer : public antlr4::Lexer {
public:
  enum {
    ActorID = 1, SimSystemID = 2, ConnectionID = 3, ConfigID = 4, StartupID = 5, 
    MessageID = 6, StartSequenceID = 7, IGNORE_NEWLINE = 8, NameID = 9, 
    LabelID = 10, EnabledID = 11, TypeID = 12, IntID = 13, RealID = 14, 
    BoolID = 15, StringID = 16, TriggerID = 17, MessageTrigger = 18, ThisID = 19, 
    ReturnID = 20, SignalTransitionID = 21, TimeoutTransitionID = 22, EnumID = 23, 
    DeclarationID = 24, DescriptionID = 25, AttributeID = 26, SignalID = 27, 
    PortID = 28, ImportID = 29, FromID = 30, ToID = 31, SendID = 32, FunctionID = 33, 
    SwitchID = 34, CaseID = 35, DefaultID = 36, IfID = 37, ElseID = 38, 
    AsID = 39, AtID = 40, NotIdSymbol = 41, AndIdSymbol = 42, OrIdSymbol = 43, 
    NotIdWord = 44, AndIdWord = 45, OrIdWord = 46, TrueID = 47, FalseID = 48, 
    BREAK = 49, ASSIGN = 50, DoubleArrow = 51, RightArrow = 52, LeftArrow = 53, 
    RANGE = 54, INT = 55, REAL = 56, STRING = 57, ID = 58, LINE_COMMENT = 59, 
    COMMENT = 60, LPAREN = 61, RPAREN = 62, LBRACE = 63, RBRACE = 64, LBRACKET = 65, 
    RBRACKET = 66, LESSTHAN = 67, GREATERTHAN = 68, COLON = 69, SEMI = 70, 
    COMMA = 71, UNDER = 72, DOT = 73, PLUS = 74, MINUS = 75, MULT = 76, 
    DIV = 77, PIPE = 78, REF = 79, CONST = 80, NEWLINE = 81, WS = 82
  };

  SimSystemDeclLexer(antlr4::CharStream *input);
  ~SimSystemDeclLexer();

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

