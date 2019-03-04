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

#include "paramvalueitem.hpp"

#include "paramitem.hpp"
#include "datatypeitem.hpp"

namespace model {
namespace base {

class ParamValueItem::Private
{
  friend class ParamValueItem;

  Private(ParamItem const* param)
  : _param(param)
  { }

  ParamItem const* _param;
};

ParamValueItem::ParamValueItem(ParamItem const* param,
                               const QVariant& value)
  : _d(new Private(param))
{
  Q_ASSERT(param);

  this->setData(value);
  this->setText(this->toString());
}

ParamValueItem::~ParamValueItem()
{
  delete this->_d;
}

void  ParamValueItem::setParam(ParamItem const* param)
{
  this->_d->_param=param;
  this->setText(this->toString());

  return;
}

ParamItem const*  ParamValueItem::param() const
{
  return this->_d->_param;
}

void  ParamValueItem::setValue(const QVariant& value)
{
  this->setData(value);
  this->setText(this->toString());

  return;
}

QVariant ParamValueItem::value() const
{
  return this->data();
}


QString ParamValueItem::toString() const
{
  QString paramValueString="";
  if(this->_d->_param)
    paramValueString+=this->_d->_param->name();

  paramValueString+="="+this->data().toString();

  return paramValueString;
}

} // namespace base
} // namespace model
