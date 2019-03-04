#ifndef PARSER_DECL_DECLARATION_HPP
#define PARSER_DECL_DECLARATION_HPP

#include "../../modeling_global.hpp"

#include "types.hpp"
#include "typedeclaration.hpp"
#include "signaldeclaration.hpp"
#include "attributedeclaration.hpp"
#include "transitiondeclaration.hpp"
#include "triggerdeclaration.hpp"
#include "junctiondeclaration.hpp"

namespace parser
{

namespace decl
{

class MODELINGSHARED_EXPORT PortDeclaration
{
public:
  PortDeclaration():name(QLatin1String(""))
	{}
	PortDeclaration(const QString& portName):name(portName)
	{}
	
	QString	name;
};

class MODELINGSHARED_EXPORT PlaceDeclaration : public PortDeclaration
{
public:
  PlaceDeclaration()
		: PortDeclaration(), isInitMarking(false)
	{}
  
	PlaceDeclaration(const QString& name, bool initMarking)
		:PortDeclaration(name), isInitMarking(initMarking)
	{}
	
	bool isInitMarking;
};

class MODELINGSHARED_EXPORT Declarations
{
public:	
	typedef QVector<TypeDeclaration>				TypeDeclarationSet;
	typedef QVector<SignalDeclaration>			SignalDeclarationSet;
	typedef QVector<PortDeclaration>				PortDeclarationSet;
	typedef QVector<AttributeDeclaration>		AttributeDeclarationSet;
	typedef QVector<PlaceDeclaration>				PlaceDeclarationSet;
	typedef QVector<TransitionDeclaration>	TransitionDeclarationSet;
	typedef QVector<JunctionDeclaration>		JunctionDeclarationSet;
	typedef std::set<QString>								StringSet;
	
public:
	Declarations();
	
public:
	static bool isKeyWord(const QString& text);
	static Declarations parse(const QString& declString);
	
public:
	const TypeDeclarationSet&				getTypeDeclarations() const;
	TypeDeclaration const*					getTypeDeclaration(const QString& typeName);
	TypeDeclaration const*					getTypeDeclaration(const UuidType& typeUuid);
	const SignalDeclarationSet&			getSignalDeclarations() const;
	SignalDeclaration const* 				getSignalDeclaration(const TriggerDeclaration& triggerDecl);
	const PortDeclarationSet&				getPortDeclarations() const;
	const AttributeDeclarationSet&	getAttributeDeclarations() const;
	const PlaceDeclarationSet&			getPlaceDeclarations() const;
	const TransitionDeclarationSet&	getTransitionDeclarations() const;
	const JunctionDeclarationSet&		getJunctionDeclarations() const;
//	const StringSet&								getInitPlaces() const;
	
	UuidType	addTypeDeclaration(const TypeDeclaration& typeDeclaration);
	void			addSignalDeclaration(const SignalDeclaration& signalDeclaration);
	void			addPortDeclaration(const QString& portName);
	void			addAttributeDeclaration(const AttributeDeclaration& attributeDeclaration);
	void			addPlaceDeclaration(const QString& placeName, bool initMarking);
	void			addTransitionDeclaration(const TransitionDeclaration& transitionDeclaration);
	void			addJunctionDeclaration(const JunctionDeclaration& junctionDeclaration);

private:
	TypeDeclarationSet				_typeDeclarations;
	SignalDeclarationSet			_signalDeclarations;
	PortDeclarationSet				_portDeclarations;
	AttributeDeclarationSet		_attributeDeclarations;
	PlaceDeclarationSet				_placeDeclarations;
	TransitionDeclarationSet	_transitionDeclarations;
	JunctionDeclarationSet		_junctionDeclarations;
};

}///end namespace decl

}//end namespace parser

#endif // PARSER_DECL_DECLARATION_HPP
