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
#pragma once

#include "../mobata_global.hpp"

#include "types.hpp"
#include <QString>
#include <QSet>

namespace prop{

class MOBATASHARED_EXPORT TypeProperty
{
  typedef QSet<QString> StringSet;

public:
  TypeProperty()
    : _typeEnum(Unknown)
  {}
  virtual ~TypeProperty()
  {}

public:
  virtual void reset()
  {
    this->_typeEnum = Unknown;
    this->_customType.clear();
    this->_lowest.clear();
    this->_highest.clear();
    this->_literals.clear();

    return;
  }

  void setTypeProperties(const TypeProperty& other)
  {
    this->_typeEnum=other._typeEnum;
    if(!other._customType.isEmpty())
      this->_customType = other._customType;
    this->_lowest=other._lowest;
    this->_highest=other._highest;
    this->_literals=other._literals;

    return;
  }

  bool isEqual(const TypeProperty& other) const
  {
    return (this->_lowest == other._lowest
            && this->_highest == other._highest
            && this->_typeEnum == other._typeEnum
            && this->_literals == other._literals);
  }

public:
  TypeEnum	typeEnum() const
  {
    return this->_typeEnum;
  }

  const QString&	customType() const
  {
    return this->_customType;
  }

  const QString&  lowest() const
  {
    return this->_lowest;
  }

  const QString&  highest() const
  {
    return this->_highest;
  }

  const StringSet&  literals() const
  {
    return this->_literals;
  }

  bool hasLiteral(const QString& literalString) const
  {
    for (const QString& literal : this->_literals)
    {
      if(literal==literalString)
        return true;
    }

    return false;
  }

  void setTypeEnum(const TypeEnum& typeEnum)
  {
    this->_typeEnum=typeEnum;

    return;
  }

  void setCustomType(const QString& customTypeName)
  {
    this->_customType=customTypeName;

    return;
  }

  void setLowest(const QString& lowest)
  {
    this->_lowest=lowest;

    return;
  }

  void setHighest(const QString& highest)
  {
    this->_highest=highest;

    return;
  }

  void addLiteral(const QString& literal)
  {
    this->_literals.insert(literal);

    return;
  }

  void setLiterals(const StringSet& literals)
  {
    this->_literals=literals;

    return;
  }

  virtual QString	typeBaseString() const
  {
    if(this->_typeEnum == prop::Unknown && !this->_customType.isEmpty())
      return this->_customType;
    else
      return typeEnum2string(this->_typeEnum);
  }

  virtual QString	typeDeclString() const
  {
    QString declaration=typeBaseString();

    ///number types////////////////
    if(!this->_lowest.isEmpty())
      declaration+=QLatin1String("(")
                   +QString(this->_lowest);
    if(!this->_highest.isEmpty())
      declaration+=QLatin1String("..")
                   +QString(this->_highest)
                   +QLatin1String(")");

    ///enum types////////////////////////
    if(this->_literals.size())
    {
      declaration+=QLatin1String("(");
      int pos=0;
      for(const QString& literal : this->_literals)
      {
        if(pos)
          declaration+=QLatin1String(",");
        declaration+=literal;

        ++pos;
      }
      declaration+=QLatin1String(")");
    }

    return declaration;
  }

  QVariant stringValueToVariant(const QString& stringValue) const
  {
    if(this->_typeEnum==Unknown
       || this->_typeEnum==Struct)
      return QVariant();

    if(this->_typeEnum==Bool)
    {
      if(stringValue.compare(QStringLiteral("true"), Qt::CaseInsensitive)==0)
        return QVariant(true);
      else if(stringValue.compare(QStringLiteral("false"), Qt::CaseInsensitive)==0)
        return QVariant(false);
      else
      {
        bool result;
        int value=stringValue.toInt(&result);
        if(!result)
          return QVariant();
        if(value)
          return QVariant(true);
        else
          return QVariant(false);
      }
    }
    else if(this->_typeEnum==Int)
    {
      bool result;
      int value=stringValue.toInt(&result);
      if(!result)
        return QVariant();
      else
        return QVariant(value);
    }
    else if(this->_typeEnum==Real)
    {
      bool result;
      double value=stringValue.toDouble(&result);
      if(!result)
        return QVariant();
      else
        return QVariant(value);
    }
    else if(this->_typeEnum==Enum)
    {
      if(!this->_literals.contains(stringValue))
        return QVariant();
      else
        return QVariant(stringValue);
    }
    else if(this->_typeEnum==String)
      return QVariant(stringValue);

    return  QVariant();
  }

protected:
  TypeEnum      _typeEnum;
  QString       _customType;
  QString       _lowest;
  QString       _highest;
  QSet<QString> _literals;
};
 }// namespace prop
