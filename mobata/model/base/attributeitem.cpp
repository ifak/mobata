/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "attributeitem.hpp"

#include "basemodel.hpp"
#include "datatypeitem.hpp"

namespace model{
namespace base{

class AttributeItem::Private
{
  friend class AttributeItem;

public:
  Private(const QString& initValue)
    : _initValue(initValue)
  {}

  ~Private()
  {}

private:
  QString	_initValue;
};

AttributeItem::AttributeItem(const QString& name,
                             const QString& dataType,
                             const QString& initValue,
                             const QUuid& uuid)
  : ParamItem(name, dataType, uuid), _d(new Private(initValue))
{}

AttributeItem::~AttributeItem()
{}

const QString& AttributeItem::initValue() const
{
  return this->_d->_initValue;
}

void AttributeItem::setInitValue(const QString &initValue)
{
  this->_d->_initValue=initValue;

  return;
}

QString AttributeItem::toString() const
{
  QString typeName=QStringLiteral("!unknown type!");
  if(this->dataType().size())
    typeName=this->dataType();

  QString declString=typeName+QStringLiteral(" ");
  declString+=this->name();
  if(!this->_d->_initValue.isEmpty())
    declString+=QStringLiteral("=")+this->_d->_initValue;

  return declString;
}

}///end namespace base
}///end namespace model
