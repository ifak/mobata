#ifndef PARSER_DECL_ATTRIBUTEDECLARATION_HPP
#define PARSER_DECL_ATTRIBUTEDECLARATION_HPP

#include "../../modeling_global.hpp"

#include "parameter.hpp"

namespace parser{ namespace decl{

class MODELINGSHARED_EXPORT AttributeDeclaration : public Parameter
{
public:
  AttributeDeclaration()
    :	Parameter(QUuid::createUuid(), QLatin1String("")),
      initValue(QLatin1String(""))
	{}
  
	AttributeDeclaration(const UuidType type, 
											 const QString& name, 
											 const QString& init)
		:	Parameter(type, name), initValue(init)
	{}

	QString	initValue;
};

}//end namespace decl

}//end namespace parser

#endif // PARSER_DECL_ATTRIBUTEDECLARATION_HPP
