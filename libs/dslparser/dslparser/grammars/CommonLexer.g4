lexer grammar CommonLexer;

/*Responsible: mre*/

NameID
   : 'name'
   ;

LabelID
    : 'label'
    ;

EnabledID
   : 'enabled'
   ;

TypeID
    : 'Type'
    ;

IntID
    : 'int'
    ;

RealID
    : 'real'
    ;

BoolID
    : 'bool'
    ;

StringID
    : 'string'
    ;

TriggerID
    : 'trigger'
    ;

MessageTrigger
    : 'msg'
    ;

ThisID
    : 'this'
    ;

ReturnID
    : 'return'
    ;
SignalTransitionID
   : 'SignalTransition'
   ;

TimeoutTransitionID
   : 'TimeoutTransition'
   ;

EnumID
    : 'enum'
    ;

DeclarationID
   : 'Declaration'
   ;

DescriptionID
   : 'description'
   ;

AttributeID
    : 'Attribute'
    ;

SignalID
   : 'Signal'
   ;

PortID
   : 'Port'
   ;

ImportID
    : 'import'
    ;

FromID
   : 'from'
   ;

ToID
   : 'to'
   ;

SendID
   : 'send'
   ;

FunctionID
   : 'Function'
   ;

SwitchID
   : 'switch'
   ;

CaseID
   : 'case'
   ;

DefaultID
   : 'default'
   ;

IfID
   : 'if'
   ;

ElseID
   : 'else'
   ;
AsID
    : 'as'
    ;

AtID
    : '@'
    ;

NotIdSymbol
    : '!'
    ;

AndIdSymbol
    : '&&'
    ;

OrIdSymbol
    : '||'
    ;

NotIdWord
    : 'not'
    ;

AndIdWord
    : 'and'
    ;

OrIdWord
    : 'or'
    ;


TrueID
    : 'true'
    ;

FalseID
    : 'false'
    ;

BREAK
    : 'break'
    ;

ASSIGN
    : '='
    ;

DoubleArrow
    : '<->'
    ;

RightArrow
    : '->'
    ;

LeftArrow
    : '<-'
    ;

RANGE
    : '..'
    ;

INT
    : MINUS? (ZERO|DIGIT) ALL_DIGIT*
    ;

REAL
    : INT DOT INT
    | DOT INT
    //| INT antlr doesn't allow that!
    ;

STRING
    : '"' (ESC | .)*? '"'
    ;

ID
    : UNDER (UNDER | LETTER | ALL_DIGIT)*
    | LETTER (UNDER | LETTER | ALL_DIGIT)*
    ;

LINE_COMMENT
    : '//' .*? (NEWLINE | EOF)-> channel(HIDDEN)
    ;

COMMENT
    : '/*' .*? ('*/' | EOF) -> channel(HIDDEN)
    ;

LPAREN
   : '('
   ;

RPAREN
   : ')'
   ;

LBRACE
   : '{'
   ;

RBRACE
   : '}'
   ;

LBRACKET
   : '['
   ;

RBRACKET
   : ']'
   ;

LESSTHAN
   : '<'
   ;

GREATERTHAN
   : '>'
   ;

COLON
    : ':'
    ;

SEMI
    : ';'
    ;

COMMA
    : ','
    ;

UNDER
    : '_'
    ;

DOT
    : '.'
    ;

PLUS
    : '+'
    ;

MINUS
    : '-'
    ;

MULT
    : '*'
    ;

DIV
    : '/'
    ;

PIPE
    : '|'
    ;

REF
    : '&'
    ;

CONST
    : 'const'
    ;

NEWLINE
    : ('\n' | 'r''\n' | '\u2029' | '\u000C' | '\u0085' | '\u2028')
    ;

WS
    : [ \t] + -> channel(HIDDEN)
    ;

fragment ESC
    : '\\' [btnr"\\]
    ;

fragment LETTER
    : ('a' .. 'z') | ('A' .. 'Z')
    ;

fragment ALL_DIGIT
    : ('0' .. '9')
    ;

fragment DIGIT
    : ('1' .. '9')
    ;

fragment ZERO
    : '0'
    ;
