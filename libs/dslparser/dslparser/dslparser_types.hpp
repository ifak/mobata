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
#pragma once

#include "dslparser_global.hpp"

#include <QVector>
#include <QHash>
#include <QModelIndex>

namespace dslparser
{

enum CommonTokenType
{
  UnknownTokenType,
  Keyword,
  Attribute,
  Param,
  Name,
  Enabled,
  Declaration,
  Signal,
  Port,
  Type,
  Function,
  Trigger,
  This,
  Import,
  As,
  Assign,
  LeftParen,
  RightParen,
  LeftBrace,
  RightBrace,
  LeftBracket,
  RightBracket,
  LessThan,
  GreaterThan,
  Arrow,
  Colon,
  Semi,
  Comma,
  Dot,
  Range,
  Plus,
  Minus,
  Mult,
  Div,
  Pipe,
  Not,
  And,
  Or,
  True,
  False,
  Int,
  Real,
  Void,
  String,
  Literal,
  Identifier,
  LineComment,
  MultiLineComment,
  NewLine,
  WhiteSpace,
  UserCommonTokenType
};

enum RequirmentTokenType {
  UnknownRequirmentTokenType = UserCommonTokenType +1,
  Use,
  Requirement,
  Actor,
  State,
  StateName,
  All,
  Duration,
  MSek,
  Sek
};

enum SpenatTokenType
{
  UnknownSpenatTokenType = Sek +1,
  RefSignal,
  RefPort,
  Place,
  RefPlace,
  SignalTransition,
  TimeoutTransition,
  Action,
  Guard,
  Pre,
  Post,
  Value,
  Initial,
  Spenat
};

enum StateMachineTokenType
{
  UnknownStateMachineTokenType = Spenat +1,
  EntryAction,
  ExitAction,
  SimpleState,
  CompositeState,
  JunctionState,
  JunctionTransition,
  ConcurrentState,
  FinalState,
  InitState,
  Source,
  Target,
  StateMachine,
  StateRegion
};

enum SutTokenType
{
  UnknownSutTokenType = StateMachine +1,
  Sut,
  SutComponent
};

enum SimSystemTokenType
{
  UnknownSimSystemTokenType = SutComponent +1,
  SimSystemActor,
  SimSystem,
  Connection,
  Config,
  StartSequence,
  Startup,
  DoubleArrow,
  RightArrow,
  LeftArrow
};

enum TestSystemTokenType
{
  UnknownTestSystemTokenType = DoubleArrow +1,
  TestComponent,
  TestSystem,
  Link
};

enum TestCaseTokenType
{
  UnknownTestCaseTokenType = Link +1,
  Message,
  From,
  To,
  Timeout,
  Accuracy,
  Result,
  Data,
  Check,
  Alt,
  Region,
  Statement,
  Timer,
  Component,
  At,
  TestCase
};

enum DiagnosisTokenType
{
  UnknownDiagnosisTokenType = TestCase +1,
  Components,
  Signals,
  Rule,
  BaseType,
  ParallelSequence,
  Parallel,
  Condition,
  Loop,
  Sequence,
  Description,
  Diagnosis
};

enum IsrdlTokenType
{
  UnknownIsrdlTokenType = Diagnosis +1,
  AttackVectorEnum,
  IntegrityThreat,
  IntegrityEnum,
  ConfidentialityThreat,
  ConfidentialityEnum,
  Privileges,
  PrivilegesEnum,
  Impact,
  SecurityRequirement
};

enum TrafficSimTokenType
{
  UnknownTrafficSimTokenType = SecurityRequirement +1,
  TrafficSimID,
  Sensor,
  Intersection,
  Step,
  Arm,
  HasTrafficLight,
  Accident,
  NeighboringTrafficLights,
  TrafficLight,
  Turns,
  Lanes,
  States,
  InnerConnections,
  OuterConnection,
  MinDur,
  MaxDur,
  Factor,
  Measured,
  Lane,
  VehicleMovement,
  Phase,
  Phases,
  TransitionPhases,
  Transition,
  Transitions,
  //    Trigger,
  VehiclePerHour,
  VehicleDistribution,
  LVehicleDistribution,
  Label,
  Bicycle,
  Bus,
  Moped,
  Motorcycle,
  Car,
  Emergency,
  Truck,
  Start,
  StartArm,
  End
};

DSLPARSERSHARED_EXPORT
int requirementTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int spenatTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int stateMachineTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int sutTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int simSystemTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int testSystemTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int trafficsimTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int testCaseTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int diagnosisTokenType(int antlrTokenType);

DSLPARSERSHARED_EXPORT
int isrdlTokenType(int antlrTokenType);

class DSLPARSERSHARED_EXPORT TokenTextLocation
{
  int _start, _end;
  int _tokenType;

public:
  TokenTextLocation(int start = -1, int end = -1,
                    int tokenType = -1)
    : _start(start), _end(end), _tokenType(tokenType)
  {}

public:
  bool isValid() const {return !(this->_start<0
                                 || this->_end<0
                                 || (this->_end<this->_start));}

public:
  int start() const     {return this->_start;}
  int end() const       {return this->_end;}
  int length() const    {return (this->_end - this->_start +1);}
  int tokenType() const {return this->_tokenType;}
  bool operator ==(const TokenTextLocation &a) const{
    return a.start()==_start && a.end() == _end && a.tokenType() == _tokenType;
  }
};

typedef QVector<TokenTextLocation>             TokenTextLocations;
typedef QHash<QModelIndex, TokenTextLocation>  ModelTextLocations;

template<class LexerClass>

int commonTokenType(int antlrTokenType)
{
  int tokenType = UnknownTokenType;

  switch (antlrTokenType)
  {
  case LexerClass::ImportID:
    tokenType = Import;
    break;
  case LexerClass::AsID:
    tokenType = As;
    break;
  case LexerClass::EnabledID:
    tokenType = Enabled;
    break;
  case LexerClass::NameID:
    tokenType = Name;
    break;
  case LexerClass::SignalID:
    tokenType = Signal;
    break;
  case LexerClass::PortID:
    tokenType = Port;
    break;
  case LexerClass::TypeID:
    tokenType = Type;
    break;
  case LexerClass::TriggerID:
    tokenType = Trigger;
    break;
  case LexerClass::ThisID:
    tokenType = This;
    break;
  case LexerClass::AttributeID:
    tokenType = Attribute;
    break;
  case LexerClass::FunctionID:
    tokenType = Function;
    break;
  case LexerClass::LPAREN:
    tokenType = LeftParen;
    break;
  case LexerClass::RPAREN:
    tokenType = RightParen;
    break;
  case LexerClass::LBRACE:
    tokenType = LeftBrace;
    break;
  case LexerClass::RBRACE:
    tokenType = RightBrace;
    break;
  case LexerClass::LBRACKET:
    tokenType = LeftBracket;
    break;
  case LexerClass::RBRACKET:
    tokenType = RightBracket;
    break;
  case LexerClass::ASSIGN:
    tokenType = Assign;
    break;
  case LexerClass::LESSTHAN:
    tokenType = LessThan;
    break;
  case LexerClass::GREATERTHAN:
    tokenType = GreaterThan;
    break;
  case LexerClass::RightArrow:
    tokenType = RightArrow;
    break;
  case LexerClass::LeftArrow:
    tokenType = LeftArrow;
    break;
  case LexerClass::DoubleArrow:
    tokenType = DoubleArrow;
    break;
  case LexerClass::COLON:
    tokenType = Colon;
    break;
  case LexerClass::SEMI:
    tokenType = Semi;
    break;
  case LexerClass::COMMA:
    tokenType = Comma;
    break;
  case LexerClass::DOT:
    tokenType = Dot;
    break;
  case LexerClass::RANGE:
    tokenType = Range;
    break;
  case LexerClass::PLUS:
    tokenType = Plus;
    break;
  case LexerClass::MINUS:
    tokenType = Minus;
    break;
  case LexerClass::MULT:
    tokenType = Mult;
    break;
  case LexerClass::DIV:
    tokenType = Div;
    break;
  case LexerClass::PIPE:
    tokenType = Pipe;
    break;
  case LexerClass::NotIdSymbol:
    tokenType = Not;
    break;
  case LexerClass::AndIdSymbol:
    tokenType = And;
    break;
  case LexerClass::OrIdSymbol:
    tokenType = Or;
    break;
  case LexerClass::NotIdWord:
    tokenType = Not;
    break;
  case LexerClass::AndIdWord:
    tokenType = And;
    break;
  case LexerClass::OrIdWord:
    tokenType = Or;
    break;
  case LexerClass::TrueID:
    tokenType = True;
    break;
  case LexerClass::FalseID:
    tokenType = False;
    break;
  case LexerClass::INT:
    tokenType = Int;
    break;
  case LexerClass::REAL:
    tokenType = Real;
    break;
  case LexerClass::STRING:
    tokenType = String;
    break;
  case LexerClass::ID:
    tokenType = Identifier;
    break;
  case LexerClass::LINE_COMMENT:
    tokenType = LineComment;
    break;
  case LexerClass::COMMENT:
    tokenType = MultiLineComment;
    break;
  case LexerClass::NEWLINE:
    tokenType = NewLine;
    break;
  case LexerClass::BoolID:
    tokenType = Type;
    break;
  case LexerClass::EnumID:
    tokenType = Type;
    break;
  case LexerClass::RealID:
    tokenType = Type;
    break;
  case LexerClass::StringID:
    tokenType = Type;
    break;
  case LexerClass::IntID:
    tokenType = Type;
    break;
  case LexerClass::WS:
    tokenType = WhiteSpace;
    break;
  default:
    break;
  }

  return tokenType;
}

}// namespace dslparser
