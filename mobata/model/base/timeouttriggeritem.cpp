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

#include "timeouttriggeritem.hpp"

namespace model {
namespace base {

TimeoutTriggerItem::TimeoutTriggerItem(const double value)
  : _value(value)
{}

TimeoutTriggerItem::~TimeoutTriggerItem()
{}

ATriggerItem::TriggerType TimeoutTriggerItem::triggerType() const
{
  return TimeoutTrigger;
}

QString TimeoutTriggerItem::declaration() const
{
  return QString(QStringLiteral("after ")
                 + QString(QStringLiteral("%1")).arg(this->_value)
                 + QStringLiteral("ms"));

}

void  TimeoutTriggerItem::setValue(const double value)
{
  this->_value=value;

  return;
}

double TimeoutTriggerItem::value() const
{
  return this->_value;
}

} // namespace base
} // namespace model
