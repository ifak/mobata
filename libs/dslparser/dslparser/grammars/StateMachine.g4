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

grammar StateMachine;
import CommonDecl;

/*Responsible: mre*/

stateMachineDecl
   : StateMachineID LBRACE stateMachineBody RBRACE
   ;

stateMachineBody
   : nameDecl stateMachineBodyOptional
   ;

stateMachineBodyOptional
   : (functionDecl        |
      typeDefDecl         |
      attributeDecl       |
      signalDecl          |
      portDecl            |
      initStateDecl       |
      simpleStateDecl     |
      junctionStateDecl   |
      concurrentStateDecl |
      compositeStateDecl  |
      finalStateDecl      |
      transitionDecl) stateMachineBodyOptional |
   ;

stateDecl
    : initStateDecl | simpleStateDecl | junctionStateDecl | concurrentStateDecl | compositeStateDecl | finalStateDecl
    ;

stateIdPath:
  contextID (DOT contextID)*
  ;

stateDecls
    : stateDecl stateDecls |
    ;

simpleStateDecl
   : SimpleStateID (contextID SEMI| LBRACE simpleStateBody RBRACE)
   ;

attributeAssignStatement
    : attributeName ASSIGN operation SEMI
    ;

simpleStateBody
   : nameDecl (entryActionDecl |) (exitActionDecl |)
   ;

junctionStateDecl
   : JunctionStateID LBRACE nameDecl junctionTransitionDecls RBRACE
   ;

junctionTransitionDecls
   : junctionTransitionDecl junctionTransitionDecls |
   ;

junctionTransitionDecl
    : JunctionTransitionID LBRACE junctionTransitionBody RBRACE
    ;

junctionTransitionBody
    : nameDecl (guardDecl | ) (actionDecl | ) targetStateDecl
    ;

concurrentStateDecl
   : ConcurrentStateID LBRACE concurrentStateBody RBRACE
   ;

concurrentStateBody
   : simpleStateBody regionDecls
   ;

regionDecl
   : RegionID LBRACE regionBody RBRACE
   ;

regionDecls
   : regionDecl regionDecls |
   ;

regionBody
   : nameDecl stateDecls
   ;

compositeStateDecl
   : CompositeStateID LBRACE compositeStateBody RBRACE
   ;

compositeStateBody
   : simpleStateBody stateDecls
   ;

finalStateDecl
   : FinalStateID (ID SEMI| LBRACE nameDecl RBRACE)
   ;

initStateDecl
   : InitStateID COLON idPath SEMI
   ;

guardDecl
   : GuardID COLON ( expression SEMI | LBRACE expression RBRACE | ElseID SEMI)
   ;

actionDecl
   : ActionID COLON (actionStatementBody | actionNestedStatementBody)
   ;

actionStatementBody
   : sendToStatement
   | switchStatement
   | conditionalStatement
   | breakStatement
   | contextIDStatements
   ;

contextIDStatements
   : functionCallStatement
   | attributeAssignStatement
   ;

actionStatementBodies
   : actionStatementBody actionStatementBodies |
   ;

actionNestedStatementBody
   : LBRACE actionStatementBodies RBRACE
   ;

transitionDecl
    : signalTransitionDecl
    | timeoutTransitionDecl
    ;

signalTransitionDecl
    : SignalTransitionID LBRACE signalTransitionBody RBRACE
    ;

signalTransitionBody
    : nameDecl (refSignalDecl refPortDecl|) (guardDecl | ) (actionDecl | ) sourceStateDecl targetStateDecl
    ;

timeoutTransitionDecl
    : TimeoutTransitionID LBRACE timeoutTransitionBody RBRACE
    ;

timeoutTransitionBody
    : nameDecl timeoutDecl (guardDecl|) (actionDecl | ) sourceStateDecl targetStateDecl
    ;

refSignalDecl
    : RefSignalID COLON ID SEMI
    ;

refPortDecl
    : RefPortID COLON ID SEMI
    ;

entryActionDecl
    : EntryActionID COLON (actionStatementBody | actionNestedStatementBody)
    ;

exitActionDecl
    : ExitActionID COLON (actionStatementBody | actionNestedStatementBody)
    ;

timeoutDecl
    : ValueID COLON val = (REAL | INT) SEMI
    ;

sourceStateDecl
   : SourceStateID COLON stateIdPath SEMI
   ;

targetStateDecl
   : TargetStateID COLON stateIdPath SEMI
   ;

contextID
    : ID
    | NameID
    | LabelID
    | GuardID
    | RegionID
    | ValueID
    | SourceStateID
    | TargetStateID
    ;

ActionID
   : 'action'
   ;

StateMachineID
   : 'StateMachine'
   ;

SimpleStateID
   : 'SimpleState'
   ;

SignalTransitionID
   : 'SignalTransition'
   ;

JunctionTransitionID
   : 'JunctionTransition'
   ;

CompositeStateID
   : 'CompositeState'
   ;

JunctionStateID
   : 'JunctionState'
   ;

ConcurrentStateID
   : 'ConcurrentState'
   ;

FinalStateID
   : 'FinalState'
   ;

RefSignalID
   : 'signal'
   ;

RefPortID
   : 'port'
   ;

ValueID
   : 'value'
   ;

GuardID
   : 'guard'
   ;

RegionID
   : 'Region'
   ;

SourceStateID
   : 'source'
   ;

TargetStateID
   : 'target'
   ;

InitStateID
   : 'initState'
   ;

EntryActionID
   : 'entry'
   ;

ExitActionID
   : 'exit'
   ;
