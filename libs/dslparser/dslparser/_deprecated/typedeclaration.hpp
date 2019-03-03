#ifndef PARSER_DECL_TYPEDECLARATION_HPP
#define PARSER_DECL_TYPEDECLARATION_HPP

#include "../../modeling_global.hpp"

#include "types.hpp"

#define QT_NO_KEYWORDS
#include <QStringList>
#undef QT_NO_KEYWORDS

namespace parser
{ 

namespace decl
{

class MODELINGSHARED_EXPORT TypeDeclaration
{
public:
	TypeDeclaration();
	TypeDeclaration(const TypeDeclaration& other);
	virtual ~TypeDeclaration();
	
public:
	TypeDeclaration& operator=(const TypeDeclaration &other);
	
public:
	bool isSemanticallyEqual(const TypeDeclaration& other) const;
	void reset();
	UuidType uuid() const;
	
public:	
	TypeEnum    typeEnum;
	QString     name;
	QString     lowest;
	QString     highest;
	QStringList literals;
	
private:
	UuidType	_uuid;
};

}//end namespace decl

}//end namespace parser

#endif // PARSER_DECL_TYPEDECLARATION_HPP
