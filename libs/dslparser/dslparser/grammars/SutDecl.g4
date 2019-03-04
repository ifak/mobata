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

grammar SutDecl;
import CommonDecl;

/*Responsible: mre*/

sutDecl
   : SutID LBRACE sutBody RBRACE
   ;

sutBody
   : nameDecl sutBodyOptional
   ;

sutBodyOptional
   : attributeDecl sutBodyOptional
   | sutCompDecl sutBodyOptional
   |
   ;

sutCompDecl
   : SutComponentID LBRACE sutCompBody RBRACE
   ;

sutCompBody
    : nameDecl sutCompBodyOtional
    ;

sutCompBodyOtional
    : attributeDecl sutCompBodyOtional
    | portDecl sutCompBodyOtional
    |
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
    | SutComponentID
    | SutID
    ;

SutComponentID
    : 'SutComponent'
    ;

SutID
   : 'Sut'
   ;
