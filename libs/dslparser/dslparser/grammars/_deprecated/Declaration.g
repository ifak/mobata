grammar Declaration;

options
{
	language = Cpp;
}

@parser::includes
{
#define QT_NO_KEYWORDS
#include "DeclarationLexer.hpp"
#undef QT_NO_KEYWORDS
}

@lexer::includes
{
#include <stdexcept>

#define QT_NO_KEYWORDS
#include "declarations.hpp"
#undef QT_NO_KEYWORDS
}

@lexer::namespace		{declParser}
@parser::namespace	{declParser}

@lexer::traits 
{
	using namespace parser::decl;
	
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
		const Declarations& getDeclarations() const
		{
			return this->_declarations;
		}
		
		const TransitionDeclaration& getCurrentTransitionDeclaration() const
		{
			return this->_currTransDecl;
		}
			
	protected:
		Declarations					_declarations;
		TypeDeclaration				_currentTypeDecl;
		UuidType							_currentTypeUuid;
		TransitionDeclaration	_currTransDecl;
		JunctionDeclaration		_currJunctionDecl;
		JunctionTarget				_currJunctionTarget;
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
	|	placeDecl	SEMI
	|	transitionDecl
	|	junctionDecl
	;

typeDefDecl:	TypeID 
							(
								typeDecl ID			{this->_currentTypeDecl.name=QString::fromStdString($ID.text);
																this->_currentTypeUuid=this->_declarations.addTypeDeclaration(this->_currentTypeDecl);}
								|	enumTypeDecl
							)
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
						|	ID				{TypeDeclaration const* baseType=this->_declarations.getTypeDeclaration(QString::fromStdString($ID.text));
												 if(baseType)
												 {
													 this->_currentTypeDecl.typeEnum=baseType->typeEnum;
													 this->_currentTypeDecl.lowest=baseType->lowest;
													 this->_currentTypeDecl.highest=baseType->highest;
													 this->_currentTypeDecl.name=baseType->name;
													 this->_currentTypeDecl.literals=baseType->literals;
												 }
												 else
													 throw std::runtime_error("No existing type '"
                                                    +$ID.text+
                                                    "' available!");}
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

signalDecl:	SignalID 
						signalBodyDecl
						(
							COMMA
							signalBodyDecl
						)*
						;
			
signalBodyDecl
scope
{
SignalDeclaration newSignalDecl;
}
:					id1=ID	{$signalBodyDecl::newSignalDecl.signalName=QString::fromStdString($id1.text);} 
					(
						UpID 
						(
							typeDecl 
							id2=ID			{if(TypeDeclaration const* type=this->_declarations.getTypeDeclaration(this->_currentTypeDecl.name))
														this->_currentTypeUuid=type->uuid();
													else
														this->_currentTypeUuid=this->_declarations.addTypeDeclaration(this->_currentTypeDecl);
													$signalBodyDecl::newSignalDecl.parameters.push_back(Parameter(this->_currentTypeUuid, QString::fromStdString($id2.text)));}
							(
								COMMA 
								typeDecl 
								id3=ID		{if(TypeDeclaration const* type=this->_declarations.getTypeDeclaration(this->_currentTypeDecl.name))
														this->_currentTypeUuid=type->uuid();
													else
														this->_currentTypeUuid=this->_declarations.addTypeDeclaration(this->_currentTypeDecl);
													$signalBodyDecl::newSignalDecl.parameters.push_back(Parameter(this->_currentTypeUuid, QString::fromStdString($id3.text)));}
							)*
						)?
						DownID
					)?							{this->_declarations.addSignalDeclaration($signalBodyDecl::newSignalDecl);}
					;
	
portDecl:	PortID id1=ID	{this->_declarations.addPortDeclaration(QString::fromStdString($id1.text));}
					(
						COMMA id2=ID	{this->_declarations.addPortDeclaration(QString::fromStdString($id2.text));}
					)*
					;
	
attributeDecl:	AttributeID 
								typeDecl
								id1=ID	(ASSIGN lit1=literal)?	{if(TypeDeclaration const* type=this->_declarations.getTypeDeclaration(this->_currentTypeDecl.name))
																									this->_currentTypeUuid=type->uuid();
																								else
																									this->_currentTypeUuid=this->_declarations.addTypeDeclaration(this->_currentTypeDecl);
																								AttributeDeclaration newAttribute(this->_currentTypeUuid, QString::fromStdString($id1.text), QString::fromStdString($lit1.text));
																								this->_declarations.addAttributeDeclaration(newAttribute);}
								(
									COMMA
									(
										typeDecl 
										id2=ID	(ASSIGN lit2=literal)?		{if(TypeDeclaration const* type=this->_declarations.getTypeDeclaration(this->_currentTypeDecl.name))
																												this->_currentTypeUuid=type->uuid();
																											else
																												this->_currentTypeUuid=this->_declarations.addTypeDeclaration(this->_currentTypeDecl);
																											AttributeDeclaration newAttribute(this->_currentTypeUuid, QString::fromStdString($id2.text), QString::fromStdString($lit2.text));
																											this->_declarations.addAttributeDeclaration(newAttribute);}
									|
										id3=ID	(ASSIGN lit3=literal)?		{AttributeDeclaration newAttribute(this->_currentTypeUuid, QString::fromStdString($id3.text), QString::fromStdString($lit3.text));
																											this->_declarations.addAttributeDeclaration(newAttribute);}
									)
								)*
								;
								
placeDecl
	:				PlaceID 
					( 
						ARROW id1=ID		{this->_declarations.addPlaceDeclaration(QString::fromStdString($id1.text), true);}
						|	id2=ID				{this->_declarations.addPlaceDeclaration(QString::fromStdString($id2.text), false);}
					)
					(
						COMMA 
						(
							ARROW id3=ID	{this->_declarations.addPlaceDeclaration(QString::fromStdString($id3.text), true);}
							|	id4=ID			{this->_declarations.addPlaceDeclaration(QString::fromStdString($id4.text), false);}
						)
					)*
					;

transitionDecl
	:				TransitionID LeftBrace transitionBodyDecl RightBrace
								{this->_declarations.addTransitionDeclaration(this->_currTransDecl);}
	;
	
transitionBodyDecl
@init
{
	this->_currTransDecl.reset();
}
	:			transitionFromDecl?
				transitionToDecl?
				transitionWithDecl?
	;

transitionFromDecl
	:			FromID	
				id1=ID					{this->_currTransDecl.addSourcePlace(QString::fromStdString($id1.text));}
				(
					COMMA id2=ID	{this->_currTransDecl.addSourcePlace(QString::fromStdString($id2.text));}
				)*
	;

transitionToDecl
	:			ToID		
				id1=ID					{this->_currTransDecl.addTargetPlace(QString::fromStdString($id1.text));}
				(
					COMMA id2=ID	{this->_currTransDecl.addTargetPlace(QString::fromStdString($id2.text));}
				)*
	;

transitionWithDecl
	:				WithID	transitionStatementDecl
	;

transitionStatementDecl
	:				(tr=triggerStatementDecl)?
																{this->_currTransDecl.trigger=QString::fromStdString($tr.text);}
					(LeftBracket g=guardStatementDecl RightBracket)?
																{this->_currTransDecl.guard=QString::fromStdString($g.text);}
					(Slash act=actionStatements)?
																{this->_currTransDecl.actions=QString::fromStdString($act.text);}
	;
	
junctionDecl
	:				JunctionID LeftBrace junctionBodyDecl RightBrace
						{this->_declarations.addJunctionDeclaration(this->_currJunctionDecl);}
	;
	
junctionBodyDecl
@init
{
	this->_currJunctionDecl.reset();
}
	:			junctionFromDecl
				junctionToDecl+
	;

junctionFromDecl
	:			FromID	
				id=ID									{this->_currJunctionDecl.setSource(QString::fromStdString($id.text));}
				junctionFromWithDecl?
	;
	
junctionFromWithDecl
	:			WithID	
				tr=triggerStatementDecl	{this->_currJunctionDecl.setTrigger(QString::fromStdString($tr.text));}
	;

junctionToDecl
@init
{
	this->_currJunctionTarget.reset();
}
	:			ToID		
				id=ID								{this->_currJunctionTarget.targetPlace=QString::fromStdString($id.text);}
				junctionToWithDecl?	
														{this->_currJunctionDecl.addTarget(this->_currJunctionTarget);}
	;

junctionToWithDecl
	:				WithID	
					(LeftBracket g=guardStatementDecl RightBracket)?	{this->_currJunctionTarget.guard=QString::fromStdString($g.text);}
					(Slash act=actionStatements)?											{this->_currJunctionTarget.actions=QString::fromStdString($act.text);}
	;

triggerStatementDecl
	:			triggerSignalStatement	
						{this->_currTransDecl.triggerType=EventTrigger;}
				|	triggerTimeoutStatement	
						{this->_currTransDecl.triggerType=TimeoutTrigger;}
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
	:		actionStatement* /*(options { greedy = false; }: .)**/
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
