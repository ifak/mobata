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

grammar Irdl;
import CommonDecl;

/*Responsible: mag*/

timerNameID
  : contextID
  ;

attributeAssignStatement
    : attributeIdPath ASSIGN (literalValue | signalParamName | attributeIdPath) SEMI
    ;

atom
   : literalValue
   | signalParamName
   | ThisID DOT contextID
   | attributeIdPath
   | timerNameID DOT TimeOutID LPAREN RPAREN
   ;

irdlDecl
   : importPathDecl
     RequirementID LBRACE requirementBody RBRACE
   ;

requirementBody
   : (DeclarationID LBRACE nameDecl declarations RBRACE)
     sequenceDecl
   ;

aliasDef
   : UseID (componentIdPath) AsID contextID SEMI
   ;

declarations
   : attributeDecl declarations
   | typeDefDecl declarations
   | signalDecl declarations
   | aliasDef declarations
   | componentDecl declarations
   | actorDecl declarations
   | descriptionDecl declarations
   |
   ;

componentDecl
   : ComponentID LBRACE componentBody RBRACE
   ;

componentBody
   : nameDecl (descriptionDecl|) commonDecl portDecl*
   ;

actorDecl
   : ActorID LBRACE actorBody RBRACE
   ;

actorBody
   : nameDecl (descriptionDecl|) commonDecl portDecl*
   ;

descriptionDecl
   : DescriptionID COLON STRING SEMI
   ;

sequenceDecl
   : stateDecl sequenceDecl
   | messageDecl sequenceDecl
   | checkDecl sequenceDecl
   | altDecl sequenceDecl
   | timerDecl sequenceDecl
   | durationDecl sequenceDecl
   | attributeAssignStatement sequenceDecl
   |
   ;

stateDecl
   : StateID contextID AtID lifelineList SEMI
   ;

lifelineList
   : AllID | (componentIdPath lifelineListOptional)
   ;

lifelineListOptional
   : COMMA lifelineList
   |
   ;

messageSignal
    : signalIdPath LPAREN (messageSignalBody|) RPAREN
    ;

messageSignalBody
    : (literalValue | signalParamName | attributeIdPath | MULT ) messageSignalBodyOptional
    ;

messageSignalBodyOptional
    : COMMA messageSignalBody |
    ;

messageDecl
   : MessageID LPAREN componentIdPath RightArrow componentIdPath RPAREN COLON messageSignal SEMI
   ;

checkDecl
   : CheckID LPAREN componentIdPath RightArrow componentIdPath RPAREN COLON (signalIdPath) checkDeclBody
   ;

checkDeclBody
   : LBRACKET expression RBRACKET (COMMA timeOutDecl| SEMI)
   ;

timerDecl
   : TimerID AtID (componentIdPath) contextID ASSIGN ( REAL | INT) (MilliSekID | SekID) SEMI
   ;

timeOutDecl
   : TimeOutID COLON ( REAL | INT) (MilliSekID | SekID) SEMI
   ;

altDecl
   : AltID  LBRACE altBodyOptional RBRACE
   ;

altBody
   : LBRACKET (expression|) RBRACKET LBRACE sequenceDecl RBRACE
   ;

altBodyOptional
   : altBody altBodyOptional
   |
   ;

durationDecl
   : DurationID LPAREN ( REAL | INT)  (MilliSekID | SekID)  RPAREN
         LBRACE sequenceDecl RBRACE
   ;

contextID
    : ID
    | NameID
    | LabelID
    | EnabledID
    | TypeID
    | AttributeID
    | SignalID
    | ImportID
    | FromID
    | ToID
    | SendID
    | DescriptionID
    | ComponentID
    | AtID
    | TimeOutID
    | MilliSekID
    | SekID
    ;

UseID
   : 'use'
   ;

RequirementID
   : 'Requirement'
   ;

DescriptionID
   : 'description'
   ;

ComponentID
   : 'Component'
   ;

ActorID
   : 'Actor'
   ;

StateID
   : 'State'
   ;

AtID
   : 'at'
   ;

AllID
   : 'all'
   ;

MessageID
   : 'Message'
   ;

CheckID
   : 'Check'
   ;

TimerID
   : 'Timer'
   ;

TimeOutID
   : 'timeout'
   ;

AltID
   : 'Alt'
   ;

DurationID
   : 'Duration'
   ;

MilliSekID
   : 'ms'
   ;

SekID
   : 's'
   ;

