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
