grammar Transition;

options
{
  language = Cpp;
}

@parser::includes
{
#define QT_NO_KEYWORDS
#include "TransitionLexer.hpp"
#undef QT_NO_KEYWORDS
}

@lexer::includes
{
#include <stdexcept>

#define QT_NO_KEYWORDS
#include "../decl/declarations.hpp"
#undef QT_NO_KEYWORDS
}

@lexer::namespace		{declParser}
@parser::namespace	{declParser}

@lexer::traits
{
  using namespace parser::decl;

  class TransitionLexer;
  class TransitionParser;

  template<class ImplTraits>
  class TransitionParserBaseType : public antlr3::Parser<ImplTraits>
  {
    typedef antlr3::Parser<ImplTraits>										BaseType;
    typedef typename BaseType::RecognizerSharedStateType	RecognizerSharedStateType;
    typedef typename BaseType::DebugEventListenerType			DebugEventListenerType;

  public:
    typedef typename BaseType::TokenStreamType						TokenStreamType;

  public:
    TransitionParserBaseType(ANTLR_UINT32 sizeHint, RecognizerSharedStateType* state)
      : BaseType(sizeHint, state )
    {}

    TransitionParserBaseType(ANTLR_UINT32 sizeHint, TokenStreamType* tstream, RecognizerSharedStateType* state)
      : BaseType(sizeHint, tstream, state)
    {}

    TransitionParserBaseType(ANTLR_UINT32 sizeHint,
                          TokenStreamType* tstream,
                          DebugEventListenerType* dbg,
                          RecognizerSharedStateType* state)
      : BaseType(sizeHint, tstream, dbg, state)
    {}

  public:
    const TransitionDeclaration& getTransitionDeclaration() const
    {
      return this->_transitionDeclaration;
    }

  protected:
    TransitionDeclaration	_transitionDeclaration;
    TypeDeclaration				_currentTypeDecl;
  };

  template<class ImplTraits>
  class UserTraits : public antlr3::CustomTraitsBase<ImplTraits>
  {
  public:
    typedef TransitionParserBaseType<ImplTraits> BaseParserType;
  };

  typedef antlr3::Traits< TransitionLexer, TransitionParser, UserTraits > TransitionLexerTraits;
  typedef TransitionLexerTraits TransitionParserTraits;
}

transition
  :				(tr=triggerStatementDecl {this->_transitionDeclaration.trigger=QString::fromStdString($tr.text);})?
          (
            LeftBracket
            g=guardStatementDecl
            RightBracket			{this->_transitionDeclaration.guard=QString::fromStdString($g.text);}
          )?
          (Slash actionStatements)?
  ;

triggerStatementDecl
  :			triggerSignalStatement
          {this->_transitionDeclaration.triggerType=EventTrigger;}
        |	triggerTimeoutStatement
          {this->_transitionDeclaration.triggerType=TimeoutTrigger;}
        ;

triggerSignalStatement
  :			ID(UpID (typeDecl ID (COMMA typeDecl ID)* )? DownID)?	(AtID	ID)?
  ;

triggerTimeoutStatement
  :			AfterID	INT	(MsecID	|	SecID)
  ;

guardStatementDecl
  :			orExpr
  ;

orExpr
  :			andExpr (OrID andExpr)*
  ;

andExpr
  : comparisonExpr (AndID comparisonExpr)*
  ;

comparisonExpr
  :  additiveExpr ( (EQUAL|NOT_EQUAL|LT_OP|LTE|GT_OP|GTE) additiveExpr)?
  ;

additiveExpr
  : multiplicativeExpr ( (PLUS|MINUS) multiplicativeExpr )*
  ;

multiplicativeExpr
  : unaryExpr ( (STAR) unaryExpr )*
  ;

unaryExpr
  :		MINUS? valueExpr
  ;

valueExpr
  : (NOT)? primaryExpr
  ;

primaryExpr
  : literal | parenthesizedExpr /*| functionCall*/
  ;

literal
  : intLiteral | boolLiteral | ident
  ;

ident
  :	msgIdent | thisIdent | ID
  ;

msgIdent
  :	MsgID	DOT	ID
  ;

thisIdent
  :	ThisID	DOT	ID
  ;

parenthesizedExpr
  : UpID orExpr? DownID
  ;

actionStatements
  :		(act=actionStatement {this->_transitionDeclaration.actions+=QString::fromStdString($act.text);} )*
  ;

actionStatement
  :			signalStatement SEMI
      |	assignStatement SEMI
      /*|	functionCall SEMI*/
      ;

signalStatement
  :	SendID ID (UpID (additiveExpr (COMMA additiveExpr)*)? DownID)? (ToID ID)?
  ;

assignStatement
  :	(ID|thisIdent) ASSIGN additiveExpr
  ;

typeDecl
@init
{
  this->_currentTypeDecl.reset();
}
  :				(
            intTypeDecl
            | enumTypeDecl
            |	BoolID		{this->_currentTypeDecl.typeEnum=Bool;}
            |	StringID	{this->_currentTypeDecl.typeEnum=String;}
            |	ID				{this->_currentTypeDecl.name=QString::fromStdString($ID.text);}
          )
          ;

intTypeDecl:	IntID	{this->_currentTypeDecl.typeEnum=Int;}
              (
                UpID
                low=intTypeLiteral {this->_currentTypeDecl.lowest=QString::fromStdString($low.text);}
                RangeID
                high=intTypeLiteral {this->_currentTypeDecl.highest=QString::fromStdString($high.text);}
                DownID
              )?
  ;

intTypeLiteral:	MINUS?	(intLiteral|InfID)
                ;

intLiteral:	INT
            ;

boolLiteral:	TrueID | FalseID
  ;

enumTypeDecl
  :				EnumID	UpID	lit1=ID	{this->_currentTypeDecl.typeEnum=Enum;
                                 this->_currentTypeDecl.literals.push_back(QString::fromStdString($lit1.text));}
          (
            COMMA	lit2=ID				{this->_currentTypeDecl.literals.push_back(QString::fromStdString($lit2.text));}
          )*
          DownID
  ;

AtID:	'at'
  ;

AfterID	:	'after'
  ;

MsecID	:	'ms'
  ;

SecID	:	's'
  ;

AttributeID:	'attribute'
  ;

PortID:		'port'
  ;

SignalID:	'signal'
  ;

TypeID	:	'type'
  ;

IntID	:	'int'
  ;

RealID	:	'real'
  ;

BoolID	:	'bool'
  ;

StringID:	'string'
  ;

EnumID	:	'enum'
  ;

InfID	:	'inf'
  ;

PlaceID:	'place'
  ;

TransitionID:	'transition'
  ;

JunctionID:	'junction'
  ;

FromID:	'from'
  ;

ToID:	'to'
  ;

WithID:	'with'
  ;

SendID:	'send'
  ;

AndID:	'and'
      |	'&&'
  ;

OrID:		'or'
      | '||'
  ;

NOT:		'not'
      |	'!'
  ;

MsgID:	'msg'
  ;

ThisID: 'this'
  ;

TrueID:	'true'
  ;

FalseID:	'false'
  ;

ASSIGN:	'='
  ;

COMMA	:	','
  ;

SEMI	:	';'
  ;

UpID	:	'('
  ;

DownID	:	')'
  ;

LeftBrace	:	'{'
  ;

RightBrace	:	'}'
  ;

LeftBracket	:	'['
  ;

RightBracket	:	']'
  ;

Slash:	'/'
  ;

MINUS:	'-'
  ;

PLUS:	'+'
  ;

STAR:	'*'
  ;

COLON:	':'
  ;

EQUAL:	'=='
  ;

NOT_EQUAL:	'!='
  ;

LTE:	'<='
  ;

LT_OP:	'<'
  ;

GTE:	'>='
  ;

GT_OP:	'>'
  ;

INT
  :	'1'..'9' Digit*
  | '0'
  ;

RangeID:	'..' ;

DOT: '.'	;

ARROW: '->'	;

ID:	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
      {if(Declarations::isKeyWord(QString::fromStdString(getText())))
        throw std::runtime_error("Keyword '"
                                 +getText()
                                 +"' is not allowed as idenitifier!");}
  ;

COMMENT
    :   '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    |   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;

STRING
    :  '"' ( ESC_SEQ | ~('\\'|'"') )* '"'
    ;

CHAR:  '\'' ( ESC_SEQ | ~('\''|'\\') ) '\''
    ;

fragment Digits:	Digit+ ;

fragment Digit:	('0'..'9') ;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
ESC_SEQ
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UNICODE_ESC
    |   OCTAL_ESC
    ;

fragment
OCTAL_ESC
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UNICODE_ESC
    :   '\\' 'u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
    ;
