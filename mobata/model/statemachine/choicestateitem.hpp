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

#include "../../mobata_global.hpp"

#include "types.hpp"
#include "abstractstateitem.hpp"

namespace model {
namespace statemachine {

class MOBATASHARED_EXPORT ChoiceStateItem
    : public AbstractStateItem
{
public:
  ChoiceStateItem(const QString& name=QLatin1String(""),
                  const QUuid& id=QUuid::createUuid());
  virtual ~ChoiceStateItem();

public:
  virtual StateType stateType() const;
};

} // namespace statemachine
} // namespace model

