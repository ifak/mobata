grammar TestSystemDecl;

import CommonDecl;

testSystemDecl
   : importPathDecl TestSystemID LBRACE testSystemBody RBRACE
   ;

testSystemBody
   : nameDecl testSystemBodyOptional linkDecls
   ;

testSystemBodyOptional
   : attributeDecl testSystemBodyOptional
   | testCompDecl testSystemBodyOptional
   |
   ;

testCompDecl
   : TestComponentID LBRACE testCompBody RBRACE
   ;

testCompBody
    : nameDecl testCompBodyOtional
    ;

enabledDecl
    : EnabledID COLON (TrueID | FalseID) SEMI
    ;

testCompBodyOtional
    : attributeDecl testCompBodyOtional
    | portDecl testCompBodyOtional
    | enabledDecl testCompBodyOtional
    |
    ;

linkDecls
    : linkDecl linkDecls |
    ;

linkDecl
    : LinkID LBRACE linkBody RBRACE
    ;

linkBody
    : labelDecl linkBody |
      targetDecl linkBody |
      sourceDecl linkBody |
    ;

labelDecl
    : LabelID COLON label=STRING SEMI
    ;

targetDecl
    : TargetID COLON target=idPath SEMI
    ;

sourceDecl
    : SourceID COLON source=idPath SEMI
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
    | TestComponentID
    | TestSystemID
    | LinkID
    | TargetID
    | SourceID
    ;

TestComponentID
    : 'TestComponent'
    ;

TestSystemID
   : 'TestSystem'
   ;

LinkID
    : 'Link'
    ;

TargetID
    : 'target'
    ;

SourceID
    : 'source'
    ;

