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
