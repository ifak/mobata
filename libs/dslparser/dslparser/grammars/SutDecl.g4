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
