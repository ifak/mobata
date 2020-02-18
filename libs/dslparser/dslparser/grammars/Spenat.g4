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
