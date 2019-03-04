grammar Trigger;

options
{
	language = Cpp;
}

@parser::includes
{
#define QT_NO_KEYWORDS
#include "TriggerLexer.hpp"
#undef QT_NO_KEYWORDS
}

@lexer::includes
{
#include <stdexcept>

#define QT_NO_KEYWORDS
#include "typedeclaration.hpp"
#include "triggerdeclaration.hpp"
#undef QT_NO_KEYWORDS
}

@lexer::namespace		{declParser}
@parser::namespace	{declParser}

@lexer::traits 
{
	using namespace parser::decl;
	
	class TriggerLexer; 
	class TriggerParser;
	
	template<class ImplTraits>
	class TriggerParserBaseType : public antlr3::Parser<ImplTraits>
	{
		typedef antlr3::Parser<ImplTraits>										BaseType;
		typedef typename BaseType::RecognizerSharedStateType	RecognizerSharedStateType;
		typedef typename BaseType::DebugEventListenerType			DebugEventListenerType;
		
	public:
		typedef typename BaseType::TokenStreamType						TokenStreamType;
		
	public:
		TriggerParserBaseType(ANTLR_UINT32 sizeHint, RecognizerSharedStateType* state)
			: BaseType(sizeHint, state )
		{}
		
		TriggerParserBaseType(ANTLR_UINT32 sizeHint, TokenStreamType* tstream, RecognizerSharedStateType* state)
			: BaseType(sizeHint, tstream, state)
		{}
		
		TriggerParserBaseType(ANTLR_UINT32 sizeHint, 
													TokenStreamType* tstream, 
													DebugEventListenerType* dbg, 
													RecognizerSharedStateType* state)
			: BaseType(sizeHint, tstream, dbg, state)
		{}
		
	public:
		const TriggerDeclaration& getTriggerDeclaration() const
		{
			return this->_triggerDeclaration;
		}
			
	protected:
		TriggerDeclaration	_triggerDeclaration;
		TypeDeclaration			_currentTypeDecl;
	};

	template<class ImplTraits>
	class UserTraits : public antlr3::CustomTraitsBase<ImplTraits>
	{
	public:
		typedef TriggerParserBaseType<ImplTraits> BaseParserType;
	};

	typedef antlr3::Traits< TriggerLexer, TriggerParser, UserTraits > TriggerLexerTraits;
	typedef TriggerLexerTraits TriggerParserTraits;
}

trigger
			:	triggerSignalStatement
			|	triggerTimeoutStatement
	;

triggerTimeoutStatement
	:	AfterID				{this->_triggerDeclaration.type=TimeoutTrigger;}
		i=INT					{this->_triggerDeclaration.timeout=QString::fromStdString($i.text);} 
		(
			MsecID			{this->_triggerDeclaration.timeoutUnit="ms";}
			|	SecID			{this->_triggerDeclaration.timeoutUnit="s";}
		)
	;

triggerSignalStatement
			:	triggerSignal	{this->_triggerDeclaration.type=EventTrigger;}
				(
					AtID 
					port=ID	{this->_triggerDeclaration.portName=QString::fromStdString($port.text);}
				)?
	;

triggerSignal
	:			evId=ID					{this->_triggerDeclaration.signalName=QString::fromStdString($evId.text);} 
				(
					UpID 
					(
						typeDecl 
						param1=ID		{this->_triggerDeclaration.addParam(this->_currentTypeDecl, 
                                                            QString::fromStdString($param1.text));}
						(
							COMMA 
							typeDecl 
							param2=ID	{this->_triggerDeclaration.addParam(this->_currentTypeDecl,
                                                            QString::fromStdString($param2.text));}
						)*
					)?
					DownID
				)?
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

intTypeLiteral:	MINUS?	(INT|InfID)
								;

enumTypeDecl
	:				EnumID	UpID	lit1=ID	{this->_currentTypeDecl.typeEnum=Enum;
																 this->_currentTypeDecl.literals.push_back(QString::fromStdString($lit1.text));}
					(
						COMMA	lit2=ID				{this->_currentTypeDecl.literals.push_back(QString::fromStdString($lit2.text));}
					)* 
					DownID
	;

	
AtID	:	'at'
	;
	
AfterID	:	'after'
	;
	
MsecID	:	'ms'
	;
	
SecID	:	's'
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
	
COMMA	:	','
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

ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
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
