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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/TestSystemDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  TestSystemDeclLexer : public antlr4::Lexer {
public:
  enum {
    TestComponentID = 1, TestSystemID = 2, LinkID = 3, TargetID = 4, SourceID = 5, 
    IGNORE_NEWLINE = 6, NameID = 7, LabelID = 8, EnabledID = 9, TypeID = 10, 
    IntID = 11, RealID = 12, BoolID = 13, StringID = 14, TriggerID = 15, 
    MessageTrigger = 16, ThisID = 17, ReturnID = 18, SignalTransitionID = 19, 
    TimeoutTransitionID = 20, EnumID = 21, DeclarationID = 22, DescriptionID = 23, 
    AttributeID = 24, SignalID = 25, PortID = 26, ImportID = 27, FromID = 28, 
    ToID = 29, SendID = 30, FunctionID = 31, SwitchID = 32, CaseID = 33, 
    DefaultID = 34, IfID = 35, ElseID = 36, AsID = 37, AtID = 38, NotIdSymbol = 39, 
    AndIdSymbol = 40, OrIdSymbol = 41, NotIdWord = 42, AndIdWord = 43, OrIdWord = 44, 
    TrueID = 45, FalseID = 46, BREAK = 47, ASSIGN = 48, DoubleArrow = 49, 
    RightArrow = 50, LeftArrow = 51, RANGE = 52, INT = 53, REAL = 54, STRING = 55, 
    ID = 56, LINE_COMMENT = 57, COMMENT = 58, LPAREN = 59, RPAREN = 60, 
    LBRACE = 61, RBRACE = 62, LBRACKET = 63, RBRACKET = 64, LESSTHAN = 65, 
    GREATERTHAN = 66, COLON = 67, SEMI = 68, COMMA = 69, UNDER = 70, DOT = 71, 
    PLUS = 72, MINUS = 73, MULT = 74, DIV = 75, PIPE = 76, REF = 77, CONST = 78, 
    NEWLINE = 79, WS = 80
  };

  TestSystemDeclLexer(antlr4::CharStream *input);
  ~TestSystemDeclLexer();

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

