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

#include "abstractstateitem.hpp"
#include "propinit.hpp"

namespace model {
namespace statemachine {

class AbstractStateItem::Private
{
  friend class AbstractStateItem;

  Private()
  {}
};

AbstractStateItem::AbstractStateItem(const QString& name,
                                     const QUuid& id)
  : base::ModelItem(id),
    prop::NameProperty(name),
    _d(new Private())
{
  this->setText(name);
}

AbstractStateItem::~AbstractStateItem()
{
  delete this->_d;
}

bool AbstractStateItem::derivedIsInit()
{
  //checks if object of derived class is an init state
  switch(this->stateType())
  {
  case Final:
  case Junction:
  case Choice:
  case Simple:
  case Composite:
  case Concurrent:
  {
    const PropInit* propInit = dynamic_cast<const PropInit*>(this);
    return propInit->isInit();
  }
  }

  return false;
}

} // namespace statemachine
} // namespace model
