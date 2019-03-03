grammar GrammarReader;

import CommonLexer;

ruleDecl
    : RuleID COLON ruleBody SEMI
    ;

ruleBody
    : (TokenID
    | RuleID
    | contextID ASSIGN ruleBody
    | LPAREN ruleBody LPAREN)

    (PLUS | QUESTION | MULT |)

    ruleBodyOptional
    ;

ruleBodyOptional
    : ruleBody
    | PIPE (ruleBody|)
    |
    ;

tokenDecl
    : TokenID COLON tokenBody SEMI
    ;

tokenBody
    : (TokenID
    | contextID ASSIGN ruleBody
    | LPAREN ruleBody LPAREN)

    (PLUS | QUESTION | MULT |)

    ruleBodyOptional
    ;

tokenBodyOptional
    : ruleBody
    | PIPE (ruleBody|)
    |
    ;

contextID
    : RuleID
    | TokenID
    | UnderID
    ;

arguments
    : LBRACKET .* RBRACKET
    ;

IGNORE_NEWLINE
    : NEWLINE -> channel(HIDDEN)
    ;

QUESTION
    : '?'
    ;

STRING
    : ''' (ESC | .)*? '''
    ;

ChannelID
    : 'channel'
    ;

HIDDENID
    : 'HIDDEN'
    ;

RuleID
    : SMALLLETTER (UNDER | BIGLETTER | SMALLLETTER | ALL_DIGIT)*
    ;

TokenID
    : BIGLETTER (UNDER | BIGLETTER | SMALLLETTER | ALL_DIGIT)*
    ;

UnderID
    : UNDER (UNDER | BIGLETTER | SMALLLETTER | ALL_DIGIT)*
    ;

FRAGMENTID
    : 'fragment'
    ;

fragment SMALLLETTER
    : ('a' .. 'z')
    ;

fragment BIGLETTER
    : ('A' .. 'Z')
    ;

fragment ALL_DIGIT
    : ('0' .. '9')
    ;
