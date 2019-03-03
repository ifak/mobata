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

grammar SimSystemDecl;
import CommonDecl;

/*Responsible: mre*/

simSystemDecl
   : importPathDecl
     SimSystemID contextID LBRACE simSystemBody RBRACE
   ;

simSystemBody
   : connectionDecl
     (configDecl | )
   ;

connectionDecl
   : ConnectionID LBRACE connectionBody RBRACE
   ;

connectionBody
    : componentIdPath DoubleArrow componentIdPath SEMI
    ;

configDecl
    : ConfigID LBRACE configBody RBRACE
    ;

configBody
    : (actorDecl | ) (startSequenceDecl | ) (startupDecl | )
    ;

actorDecl
   : actorDeclBody+
   ;

actorDeclBody
   : ActorID contextID LBRACE (actorBodyContent | ) RBRACE
   ;

actorBodyContent
   : portDecl+
   ;

startupDecl
   : StartupID LBRACE startupBody RBRACE
   ;

startupBody
   : messageDeclOptional
   ;

messageDeclOptional
   : messageDecl messageDeclOptional
   |
   ;

messageDecl
   : MessageID LPAREN componentIdPath RightArrow componentIdPath RPAREN COLON messageSignal SEMI
   ;

messageSignal
    : signalIdPath LPAREN (messageParamValue (COMMA messageParamValue)* | ) RPAREN
    ;

messageParamValue
    : literalValue
    ;

startSequenceDecl
    : StartSequenceID COLON contextID (COMMA contextID)* SEMI
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
    | ActorID
    | SimSystemID
    | ConnectionID
    | ConfigID
    | StartupID
    | MessageID
    | StartSequenceID
    ;

ActorID
    : 'Actor'
    ;

SimSystemID
   : 'SimSystem'
   ;

ConnectionID
   : 'Connection'
   ;

ConfigID
   : 'Config'
   ;

StartupID
   : 'Startup'
   ;

MessageID
   : 'Message'
   ;

StartSequenceID
   : 'startSequence'
   ;
