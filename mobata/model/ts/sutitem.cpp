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

#include "sutitem.hpp"

#include "testsuite.hpp"
#include "../msc/msccomponentitem.hpp"

namespace model{
namespace ts{

SutItem::SutItem(const QString &name)
  :	prop::NameProperty(name),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    PropLinks(this),
    PropComponents(this)
{
  this->setIcon(QIcon(":mobata/images/ts/sut.png"));
  this->setText(this->name());
}

SutItem::~SutItem()
{}

void SutItem::reset()
{
  this->resetAttributes();
  this->resetSignals();
  this->resetComponents();
  this->resetLinks();

  return;
}

QString SutItem::toString() const
{
  return this->name();
}

}///end namespace ts
}///end namespace model
