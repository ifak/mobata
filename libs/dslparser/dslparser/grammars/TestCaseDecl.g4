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
   | uuidDecl declarations
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
   : CheckID LPAREN idPath RightArrow idPath RPAREN COLON
     functionCall2
     (  COMMA timeOutDecl  (COMMA accuracyDecl| )
     | COMMA accuracyDecl (COMMA timeOutDecl | )
     |
     ) SEMI
   ;

timerDecl
   : TimerID AtID idPath contextID ASSIGN ( REAL | INT) (MilliSekID | SekID) SEMI
   ;

timeOutDecl
   : TimeOutID COLON ( REAL | INT) (MilliSekID | SekID)
   ;

accuracyDecl
   : AccuracyID COLON (REAL | INT)
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

uuidDecl
    : UuidID COLON val = STRING SEMI
    ;

enabledDecl
    : EnabledID COLON (TrueID | FalseID) SEMI
    ;

contextID
    : ID
    | NameID
    | UuidID
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

functionCall2
   : idPath LBRACKET functionCallBody RBRACKET
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

UuidID
   : 'uuid'
   ;

AltID
   : 'Alt'
   ;

TimerID
   : 'Timer'
   ;

AccuracyID
   : 'accuracy'
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
