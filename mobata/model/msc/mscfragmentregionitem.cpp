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

#include "mscfragmentregionitem.hpp"

namespace model{
namespace msc{

class MscFragmentRegionItem::Private
{
  friend class MscFragmentRegionItem;
  explicit Private(const QString& condition)
    :_condition(condition)
  {}

  QString _condition;
};

MscFragmentRegionItem::MscFragmentRegionItem(const QString &condition)
  :	MscSequence(condition), _d(new Private(condition))
{
  this->setText(this->_d->_condition);
}

MscFragmentRegionItem::~MscFragmentRegionItem()
{
  delete this->_d;
}

const QString &MscFragmentRegionItem::condition() const
{
  return this->_d->_condition;
}

void MscFragmentRegionItem::setCondition(const QString &condition)
{
  this->_d->_condition=condition;
  this->setText(this->_d->_condition);

  return;
}

}/// end namespace msc
}/// end namespace model
