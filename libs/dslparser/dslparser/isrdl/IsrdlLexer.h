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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/Isrdl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  IsrdlLexer : public antlr4::Lexer {
public:
  enum {
    NoDamageID = 1, AffectedID = 2, IntegrityThreatID = 3, BrokenID = 4, 
    IntactID = 5, ConfidentialityThreatID = 6, AdministratorID = 7, InstallAllowedID = 8, 
    UnInstallAllowedID = 9, SaveAllowedID = 10, EditAllowedID = 11, NoneID = 12, 
    PrivilegesID = 13, ImpactID = 14, AttackDescriptionID = 15, SecurityRequirementID = 16, 
    SourceID = 17, PhysicalID = 18, LocalID = 19, InternetID = 20, TimeoutID = 21, 
    MSekID = 22, SekID = 23, INT = 24, LBRACE = 25, RBRACE = 26, COLON = 27, 
    SEMI = 28, COMMA = 29, UNDER = 30, MINUS = 31, IGNORE_NEWLINE = 32, 
    NameID = 33, LabelID = 34, EnabledID = 35, TypeID = 36, IntID = 37, 
    RealID = 38, BoolID = 39, StringID = 40, TriggerID = 41, MessageTrigger = 42, 
    ThisID = 43, ReturnID = 44, SignalTransitionID = 45, TimeoutTransitionID = 46, 
    EnumID = 47, DeclarationID = 48, DescriptionID = 49, AttributeID = 50, 
    SignalID = 51, PortID = 52, ImportID = 53, FromID = 54, ToID = 55, SendID = 56, 
    FunctionID = 57, SwitchID = 58, CaseID = 59, DefaultID = 60, IfID = 61, 
    ElseID = 62, AsID = 63, AtID = 64, NotIdSymbol = 65, AndIdSymbol = 66, 
    OrIdSymbol = 67, NotIdWord = 68, AndIdWord = 69, OrIdWord = 70, TrueID = 71, 
    FalseID = 72, BREAK = 73, ASSIGN = 74, DoubleArrow = 75, RightArrow = 76, 
    LeftArrow = 77, RANGE = 78, REAL = 79, STRING = 80, ID = 81, LINE_COMMENT = 82, 
    COMMENT = 83, LPAREN = 84, RPAREN = 85, LBRACKET = 86, RBRACKET = 87, 
    LESSTHAN = 88, GREATERTHAN = 89, DOT = 90, PLUS = 91, MULT = 92, DIV = 93, 
    PIPE = 94, REF = 95, CONST = 96, NEWLINE = 97, WS = 98
  };

  IsrdlLexer(antlr4::CharStream *input);
  ~IsrdlLexer();

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

