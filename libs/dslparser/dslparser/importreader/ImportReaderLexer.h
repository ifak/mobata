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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/ImportReader.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  ImportReaderLexer : public antlr4::Lexer {
public:
  enum {
    IGNORE_NEWLINE = 1, NameID = 2, LabelID = 3, EnabledID = 4, TypeID = 5, 
    IntID = 6, RealID = 7, BoolID = 8, StringID = 9, TriggerID = 10, MessageTrigger = 11, 
    ThisID = 12, ReturnID = 13, SignalTransitionID = 14, TimeoutTransitionID = 15, 
    EnumID = 16, DeclarationID = 17, DescriptionID = 18, AttributeID = 19, 
    SignalID = 20, PortID = 21, ImportID = 22, FromID = 23, ToID = 24, SendID = 25, 
    FunctionID = 26, SwitchID = 27, CaseID = 28, DefaultID = 29, IfID = 30, 
    ElseID = 31, AsID = 32, AtID = 33, NotIdSymbol = 34, AndIdSymbol = 35, 
    OrIdSymbol = 36, NotIdWord = 37, AndIdWord = 38, OrIdWord = 39, TrueID = 40, 
    FalseID = 41, BREAK = 42, ASSIGN = 43, DoubleArrow = 44, RightArrow = 45, 
    LeftArrow = 46, RANGE = 47, INT = 48, REAL = 49, STRING = 50, ID = 51, 
    LINE_COMMENT = 52, COMMENT = 53, LPAREN = 54, RPAREN = 55, LBRACE = 56, 
    RBRACE = 57, LBRACKET = 58, RBRACKET = 59, LESSTHAN = 60, GREATERTHAN = 61, 
    COLON = 62, SEMI = 63, COMMA = 64, UNDER = 65, DOT = 66, PLUS = 67, 
    MINUS = 68, MULT = 69, DIV = 70, PIPE = 71, REF = 72, CONST = 73, NEWLINE = 74, 
    WS = 75
  };

  ImportReaderLexer(antlr4::CharStream *input);
  ~ImportReaderLexer();

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

