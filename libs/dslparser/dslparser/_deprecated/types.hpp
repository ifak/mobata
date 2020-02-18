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
#ifndef PARSER_DECL_TYPES_HPP
#define PARSER_DECL_TYPES_HPP

#include <string>
#include <vector>
#include <set>

#include <QUuid>

namespace parser
{

namespace decl
{
	typedef QUuid UuidType;
	static inline UuidType createUuid() {return QUuid::createUuid();}
	
enum TypeEnum
{
	Bool,
	Enum,
	Int,
	Real,
	String
};

enum TriggerTypeEnum
{
	EventTrigger,
	TimeoutTrigger
};


inline
QString typeEnum2String(TypeEnum typeEnum)
{
	if(typeEnum==Bool)
			return QLatin1String("bool");
	else if(typeEnum==Enum)
		return QLatin1String("enum");
	else if(typeEnum==Int)
		return QLatin1String("int");
	else if (typeEnum==Real)
		return QLatin1String("real");
	else if(typeEnum==String)
		return QLatin1String("string");
	
	return QLatin1String("unknown");
}

inline
QString triggerTypeEnum2String(TriggerTypeEnum typeEnum)
{
	if(typeEnum==EventTrigger)
			return QLatin1String("EventTrigger");
	else if(typeEnum==TimeoutTrigger)
		return QLatin1String("TimeoutTrigger");
	
	return QLatin1String("unknown");
}

}//end namespace decl

}//end namespace parser

#endif // TYPES_HPP
