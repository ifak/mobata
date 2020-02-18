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
    | FromID
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
