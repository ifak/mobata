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

grammar Spenat;
import CommonDecl;

/*Responsible: mre*/

spenatDecl
   : SpenatID LBRACE spenatBody RBRACE
   ;

spenatBody
   : nameDecl spenatBodyOptional
   ;

spenatBodyOptional
   : typeDefDecl spenatBodyOptional
   | attributeDecl spenatBodyOptional
   | signalDecl spenatBodyOptional
   | functionDecl spenatBodyOptional
   | portDecl spenatBodyOptional
   | placeDecl spenatBodyOptional
   | transitionDecl spenatBodyOptional
   |
   ;

placeDecl
   : PlaceID LBRACE placeBody RBRACE
   ;

placeBody
    : nameDecl (initialDecl | )
    ;

guardDecl
   : GuardID COLON ( expression SEMI | multiExpression)
   ;

multiExpression
   : LBRACE expression RBRACE
   ;

multiExpressionOptional
   : expression
   |
   ;

actionDecl
   : ActionID COLON (singleAssignment
                    | multiAssignment)
   ;

transitionDecl
    : signalTransitionDecl
    | timeoutTransitionDecl
    ;

signalTransitionDecl
    : SignalTransitionID LBRACE signalTransitionBody RBRACE
    ;

signalTransitionBody
    : nameDecl (refSignalDecl refPortDecl | ) (guardDecl | ) (actionDecl | ) (preDecl | ) (postDecl | )
    ;

timeoutTransitionDecl
    : TimeoutTransitionID LBRACE timeoutTransitionBody RBRACE
    ;

timeoutTransitionBody
    : nameDecl (timeoutDecl | ) (guardDecl | ) (actionDecl | ) (preDecl | ) (postDecl | )
    ;

refSignalDecl
    : RefSignalID COLON contextID SEMI
    ;

refPortDecl
    : RefPortID COLON contextID SEMI
    ;

preDecl
    : PreID COLON contextID (COMMA contextID)* SEMI
    ;

postDecl
    : PostID COLON contextID (COMMA contextID)* SEMI
    ;

timeoutDecl
    : ValueID COLON REAL SEMI
    ;

initialDecl
    : InitialID COLON (TrueID|FalseID) SEMI
    ;

functionCall
   : contextID LPAREN functionCallBody RPAREN
   ;

contextID
    : ID
    | NameID
    | LabelID
    | EnabledID
    | TypeID
    | (MessageTrigger | TriggerID)
    | AttributeID
    | FunctionID
    | SignalID
    | PortID
    | ImportID
    | FromID
    | ToID
    | SendID
    | AsID
    | ActionID
    | SpenatID
    | PlaceID
    | SignalTransitionID
    | TimeoutTransitionID
    | RefSignalID
    | RefPortID
    | ValueID
    | GuardID
    | InitialID
    | PreID
    | PostID
    ;

ActionID
   : 'action'
   ;

SpenatID
   : 'Spenat'
   ;

PlaceID
   : 'Place'
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

InitialID
    : 'initial'
    ;

PreID
    : 'pre'
    ;

PostID
    : 'post'
    ;
