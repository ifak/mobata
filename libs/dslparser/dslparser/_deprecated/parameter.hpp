#ifndef PARSER_DECL_PARAMETER_HPP
#define PARSER_DECL_PARAMETER_HPP

#include "../../modeling_global.hpp"

namespace parser{ namespace decl{

class MODELINGSHARED_EXPORT Parameter
{
public:
  Parameter()
    :	typeUuid(UuidType::createUuid()),
      name(QLatin1String(""))
	{}
  
	Parameter(const UuidType paramType,
            const QString& paramName)
		:	typeUuid(paramType),
      name(paramName)
	{}
	
	UuidType  typeUuid;
	QString   name;
};

}//end namespace decl


}//end namespace parser

#endif // PARSER_DECL_PARAMETER_HPP
