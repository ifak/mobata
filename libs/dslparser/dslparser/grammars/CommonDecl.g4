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

grammar CommonDecl;
import CommonLexer;

/*Responsible: mre*/

componentIdPath:
    contextID (DOT contextID)*
    ;

signalIdPath:
    contextID (DOT contextID)*
    ;

attributeIdPath:
  attributeName
  | contextID (DOT contextID)*
  ;

signalSend
  :signalIdPath LPAREN functionCallBody RPAREN
  ;

commonDecl
    : (typeDefDecl | attributeDecl | signalDecl)*
    ;

importPathDecl
    :  importPathBody importPathDecl
    |
    ;

importPathBody
    : ImportID LESSTHAN importFileBody GREATERTHAN importAs
    ;

importFileBody
    : contextID DOT contextID
    | RANGE DIV importFileBody
    | contextID DIV importFileBody
    ;

importAs
    : AsID contextID |
    ;

typeDefDecl
    : TypeID typeDecl contextID SEMI
    ;

typeDecl
    : intTypeDecl
    | realTypeDecl
    | enumTypeDecl
    | BoolID
    | StringID
    | contextID
    ;

intTypeDecl
    :	IntID (LPAREN INT RANGE INT RPAREN | ) //int(-4 ... 20)
    ;

realTypeDecl
    :	RealID (LPAREN REAL RANGE REAL RPAREN | ) //real(-2.0 ... 5.4)
    ;

enumTypeDecl
    : EnumID  LPAREN  contextID  (COMMA  contextID)*  RPAREN //enum(One, Two, Three)
    ;

attributeDecl
    : AttributeID typeDecl contextID (ASSIGN literalValue)? SEMI
    ;

literalValue
    : INT
    | REAL
    | STRING
    | TrueID
    | FalseID
    | contextID
    ;

signalParamName
    : triggerDecl contextID
    ;

attributeName
    : (thisDecl|) contextID
    ;

toPortName
    : ToID contextID
    ;

attributeAssignStatement
    : attributeName ASSIGN expression SEMI
    ;

localAssignStatement
    : typeDecl contextID (ASSIGN expression | ) SEMI
    ;

sendToStatement
    : SendID signalSend (toPortName|) SEMI
    ;

singleAssignment
    : attributeAssignStatement
    | sendToStatement
    ;

multiAssignment
    : LBRACE singleAssignment* RBRACE
    ;

signalDecl
    :	SignalID  contextID (LPAREN (paramDecl (COMMA  paramDecl)*  | )  RPAREN | ) SEMI
    ;

paramDecl
    : typeDecl  contextID
    ;

functionDecl
    : FunctionID typeDecl idPath LPAREN (functionParameters|) RPAREN nestedStatementBody
    ;

functionParameters
    : paramDecl (COMMA paramDecl)*
    ;

functionCall
    : idPath LPAREN functionCallBody RPAREN
    ;

functionCallBody
    : (literalValue | signalParamName | attributeName | functionCall /*| expression*/ |) functionCallBodyOptional
    ;

functionCallBodyOptional
    : COMMA functionCallBody |
    ;

contextID
    : ID
    | NameID
    | LabelID
    | EnabledID
    | TypeID
    | AttributeID
    | SignalID
    | PortID
    | ImportID
    | FromID
    | ToID
    | AsID
    ;

triggerDecl
    : (MessageTrigger | TriggerID) DOT
    ;

thisDecl
    : ThisID DOT
    ;

portDecl
    : PortID contextID (COMMA contextID)* SEMI
    ;

nameDecl
    : NameID COLON contextID SEMI
    ;

idPath
    : contextID (DOT contextID)*
    ;

statementDecl
   : statementBody
   | nestedStatementBody
   ;

statementBody
   : functionCallStatement
   | attributeAssignStatement        // no <send> in <script> possible!!!
   | switchStatement
   | conditionalStatement
   | localAssignStatement
   | sendToStatement
   | breakStatement
   | returnStatement
   ;

functionCallStatement
   : functionCall SEMI
   ;

nestedStatementBody
   : LBRACE statementBody* RBRACE
   ;

returnStatement
   : ReturnID operation SEMI
   ;

breakStatement
   : BREAK SEMI
   ;

operation
   : atom operationOptional
   | LPAREN operation RPAREN
   | MINUS operation
   | NotIdSymbol operation
   ;

operationOptional
   : op=(MULT | DIV | PLUS | MINUS) operation
   |
   ;


expression
   : LPAREN expression RPAREN expressionOptional
   | NotIdSymbol expression
   | NotIdWord expression
   | MINUS expression
   | operation expressionOptional
   ;

expressionOptional
   : (OrIdSymbol
      | OrIdWord
      | AndIdSymbol
      | AndIdWord
      | (ASSIGN ASSIGN)
      | (NotIdSymbol ASSIGN)
      | NotIdWord
      | (LESSTHAN (ASSIGN|))
      | (GREATERTHAN (ASSIGN|))
      ) expression
   |
   ;

conditionalStatement
    : ifStatement (elseStatement | )
    ;

ifStatement
    : IfID ifEuT (statementDecl | SEMI)
    ;

ifEuT       //expression under Test
    : LPAREN expression RPAREN
    ;

elseStatement
    : ElseID statementDecl
    ;

switchStatement
    : SwitchID switchPuT LBRACE (caseStatement)* (defaultStatement | ) RBRACE
    ;

switchPuT   //parameter under test
    : LPAREN contextID RPAREN
    ;

caseStatement
    : CaseID literalValue COLON (nestedStatementBody | statementBody*)
    ;

defaultStatement
    : DefaultID COLON (nestedStatementBody | statementBody*)
    ;

atom
   : signalParamName
   | attributeName
   | functionCall
   | literalValue
   ;

IGNORE_NEWLINE
    : NEWLINE -> channel(HIDDEN)
    ;
