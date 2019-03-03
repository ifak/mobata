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

#include "paramitem.hpp"

#include "datatypeitem.hpp"
#include "basemodel.hpp"

namespace model{
namespace base{

class ParamItem::Private
{
  friend class ParamItem;

  QString _dataType;

  explicit Private(const QString& dataType)
    :	_dataType(dataType)
  {}
};

ParamItem::ParamItem(const QString& name,
                     const QString& dataType,
                     const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _d(new Private(dataType))
{
  this->setIcon(QIcon(":/mobata/images/base/attribute.png"));
  this->setText(this->name());
}

ParamItem::~ParamItem()
{
  delete this->_d;
}

const QString& ParamItem::dataType() const
{
  return this->_d->_dataType;
}

void ParamItem::setDataType(const QString& dataType)
{
  this->_d->_dataType=dataType;

  return;
}

QString ParamItem::toString() const
{
  QString typeName=QLatin1String("!unknown type!");
  if(this->_d->_dataType.size())
    typeName=this->_d->_dataType;

  QString declString=typeName+QLatin1String(" ");
  declString+=this->name();

  return declString;
}

}///end namespace base
}///end namespace model
