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

grammar TestCaseDecl;
import CommonDecl;

/*Responsible: mre*/

testCaseDecl
   : importPathDecl TestCaseID LBRACE testCaseBody RBRACE
   ;

testCaseBody
   : DeclarationID LBRACE declarations RBRACE steps
   ;

declarations
   : attributeDecl declarations
   | nameDecl declarations
   | enabledDecl declarations
   | signalDecl declarations
   | checkDecl declarations
   | aliasDef declarations
   |
   ;

aliasDef
   : ComponentID idPath AsID contextID SEMI
   ;


steps
   : timerDecl steps
   | messageDecl steps
   | checkDecl steps
   | altDecl steps
   | idStatement SEMI steps
   |
   ;

idStatement
   : thisDecl idPath (assignmentDef |)
   | idPath (assignmentDef |)
   ;

assignmentDef
   : ASSIGN ( REAL | STRING | INT | TrueID | FalseID)
   ;

messageDecl
   : MessageID LPAREN idPath RightArrow idPath RPAREN COLON functionCall SEMI
   ;

checkDecl
   : CheckID LPAREN idPath RightArrow idPath RPAREN COLON contextID checkDeclBody
   ;

checkDeclBody
   : LBRACKET expression RBRACKET (COMMA timeOutDecl| SEMI)
   ;

timerDecl
   : TimerID AtID idPath contextID ASSIGN ( REAL | INT) (MilliSekID | SekID) SEMI
   ;

timeOutDecl
   : TimeOutID COLON ( REAL | INT) (MilliSekID | SekID) SEMI
   ;

altDecl
   : AltID  LBRACE altBodyOptional RBRACE
   ;

altBody
   : LBRACKET (expression|) RBRACKET LBRACE (checkDecl|) steps RBRACE
   ;

altBodyOptional
   : altBody altBodyOptional
   |
   ;

enabledDecl
    : EnabledID COLON (TrueID | FalseID) SEMI
    ;

contextID
    : ID
    | NameID
    | LabelID
    | EnabledID
    | TypeID
    | (MessageTrigger | TriggerID)
    | AttributeID
    | SignalID
    | PortID
    | ImportID
    | FromID
    | ToID
    | SendID
    | AsID
    | TimeOutID
    | ComponentID
    | DeclarationID
    ;

functionCall
   : idPath LPAREN functionCallBody RPAREN
   ;

MessageID
   : 'Message'
   ;

TimeOutID
   : 'timeout'
   ;

CheckID
   : 'Check'
   ;

AltID
   : 'Alt'
   ;

TimerID
   : 'Timer'
   ;

ComponentID
   : 'Component'
   ;

DeclarationID
   : 'Declaration'
   ;

TestCaseID
   : 'TestCase'
   ;

MilliSekID
   : 'ms'
   ;

SekID
   : 's'
   ;
