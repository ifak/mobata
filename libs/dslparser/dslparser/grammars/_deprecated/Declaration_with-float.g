grammar Declaration;

options
{
	language = Cpp;
}

@parser::includes
{
#include "DeclarationLexer.hpp"
}

@lexer::includes
{
#include <stdexcept>
#include "declaration.hpp"
}

@lexer::namespace		{declParser}
@parser::namespace	{declParser}

@lexer::traits 
{
	class DeclarationLexer; 
	class DeclarationParser;
	
	template<class ImplTraits>
	class DeclParserBaseType : public antlr3::Parser<ImplTraits>
	{
		typedef antlr3::Parser<ImplTraits>										BaseType;
		typedef typename BaseType::RecognizerSharedStateType	RecognizerSharedStateType;
		typedef typename BaseType::DebugEventListenerType			DebugEventListenerType;
		
	public:
		typedef typename BaseType::TokenStreamType						TokenStreamType;
		
	public:
		DeclParserBaseType(ANTLR_UINT32 sizeHint, RecognizerSharedStateType* state)
			: BaseType(sizeHint, state )
		{}
		
		DeclParserBaseType(ANTLR_UINT32 sizeHint, TokenStreamType* tstream, RecognizerSharedStateType* state)
			: BaseType(sizeHint, tstream, state)
		{}
		
		DeclParserBaseType(ANTLR_UINT32 sizeHint, TokenStreamType* tstream, DebugEventListenerType* dbg, RecognizerSharedStateType* state)
			: BaseType(sizeHint, tstream, dbg, state)
		{}
			
	public:
		const Declaration& getDeclaration() const
		{
			return this->_declaration;
		}
			
	protected:
		Declaration			_declaration;
		TypeDeclaration	_currentTypeDecl;
	};

	template<class ImplTraits>
	class UserTraits : public antlr3::CustomTraitsBase<ImplTraits>
	{
	public:
		typedef DeclParserBaseType<ImplTraits> BaseParserType;
	};

	typedef antlr3::Traits< DeclarationLexer, DeclarationParser, UserTraits > DeclarationLexerTraits;
	typedef DeclarationLexerTraits DeclarationParserTraits;
}

declarations
	:	declStatement*
	;

declStatement
	:	typeDefDecl	SEMI
	|	signalDecl	SEMI
	|	portDecl	SEMI
	|	attributeDecl	SEMI
	;

typeDefDecl:	TypeID typeDecl ID 
							{
								this->_currentTypeDecl.name=$ID.text;
								this->_declaration.addTypeDeclaration(this->_currentTypeDecl);
							}
							;
	
typeDecl
@init
{
	this->_currentTypeDecl.reset();
}
	:				(
						intTypeDecl
						|	realTypeDecl
						|	EnumID
						|	BoolID
						|	StringID
						|	ID
					)
					;

intTypeDecl:	IntID	{this->_currentTypeDecl.type=Int;}
							(
								UpID 
								low=intExpr {this->_currentTypeDecl.lowest=$low.text;}
								COMMA 
								high=intExpr {this->_currentTypeDecl.highest=$high.text;}
								DownID
							)?
	;
	
realTypeDecl:	RealID {this->_currentTypeDecl.type=Real;}
							(
								UpID 
								low=realExpr {this->_currentTypeDecl.lowest=$low.text;}
								COMMA 
								high=realExpr {this->_currentTypeDecl.highest=$high.text;}
								DownID
							)?
	;

intExpr:		(MINUS)? INT
						;

realExpr:		(MINUS)? FLOAT
						;
	
signalDecl
scope
{
SignalDeclaration newSignalDecl;
}
	:	SignalID 
		id1=ID	{$signalDecl::newSignalDecl.signalName=$id1.text;} 
		(
			UpID 
			(
				typeDecl 
				id2=ID 
				(
					COMMA 
					typeDecl 
					id3=ID
				)*
			)?
			DownID
		)?
	;
	
portDecl:	PortID id1=ID	{this->_declaration.addPortDeclaration($id1.text);}
					(
						COMMA id2=ID	{this->_declaration.addPortDeclaration($id2.text);}
					)*
					;
	
attributeDecl:	AttributeID typeDecl ID
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
	
COMMA	:	','
	;	
	
SEMI	:	';'
	;
	
UpID	:	'('
	;
	
DownID	:	')'
	;

MINUS:	'-'
	;

FLOAT
	:	Digits '.' Digits EXPONENT?
  |   '.'	Digits EXPONENT?
  |   Digits EXPONENT
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
EXPONENT 	: ('e'|'E') ('+'|'-')? Digits 
					;

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
