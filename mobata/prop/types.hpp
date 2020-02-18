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
#ifndef PROP_TYPES_HPP
#define PROP_TYPES_HPP

#include <QString>
#include "../utils/functors.hpp"

namespace prop{

enum TypeEnum
{
  Unknown,
  Bool,
  Enum,
  Int,
  Real,
  String,
  Struct
};

enum TriggerTypeEnum
{
  EventTrigger,
  TimeoutTrigger
};

static inline
QString typeEnum2string(TypeEnum typeEnum)
{
  using namespace utils;

  if(typeEnum==Bool)
      return podtype2string<bool>();
  else if(typeEnum==Enum)
    return QStringLiteral("enum");
  else if(typeEnum==Int)
    return podtype2string<int>();
  else if (typeEnum==Real)
    return podtype2string<double>();
  else if(typeEnum==String)
    return podtype2string<QString>();

  return QStringLiteral("unknown");
}

static inline
TypeEnum string2typeEnum(const QString& typeName)
{
  using namespace utils;

  if(typeName==podtype2string<bool>())
    return Bool;
  else if(typeName==podtype2string<int>())
    return Int;
  else if(typeName==podtype2string<double>())
    return Real;
  else if(typeName==podtype2string<QString>())
    return String;
  else if(typeName==QStringLiteral("enum"))
    return Enum;
  else if(typeName==QStringLiteral("unsigned char"))
    return Int;
  else if(typeName==QStringLiteral("unsigned short"))
    return Int;

  return Unknown;
}

static inline
QString triggerTypeEnum2string(TriggerTypeEnum typeEnum)
{
  if(typeEnum==EventTrigger)
      return QLatin1String("EventTrigger");
  else if(typeEnum==TimeoutTrigger)
    return QLatin1String("TimeoutTrigger");

  return QLatin1String("unknown");
}

}/// end namespace Prop

#endif // PROP_TYPES_HPP
