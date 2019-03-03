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

#include "finalstateitem.hpp"

namespace model {
namespace statemachine {

FinalStateItem::FinalStateItem(const QString& name,
                               const QUuid& id)
  : AbstractStateItem(name.isEmpty()?QStringLiteral("final"):name,
                      id)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/finalstate.png")));
}

FinalStateItem::~FinalStateItem()
{}

StateType FinalStateItem::stateType() const
{
  return Final;
}

} // namespace statemachine
} // namespace model

