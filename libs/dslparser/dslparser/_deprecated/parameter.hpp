/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/
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
