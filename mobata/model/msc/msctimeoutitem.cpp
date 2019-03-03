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

#include "msctimeoutitem.hpp"

#include "msctimeritem.hpp"

namespace model {
namespace msc {

class MscTimeoutItem::Private
{
  friend class MscTimeoutItem;

  Private(MscTimerItem const* timer)
    : _timer(timer)
  {}

  MscTimerItem const* _timer;
};
MscTimeoutItem::MscTimeoutItem(const MscComponentItem* component,
                               MscTimerItem const* timer)
  : MscStepItem(component),
    _d(new Private(timer))
{
  Q_ASSERT(component);
  Q_ASSERT(this->_d->_timer);
  Q_ASSERT(component==this->_d->_timer->component());

  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/timeout.png")));
  this->setText(this->toString());
}

MscTimeoutItem::~MscTimeoutItem()
{
  delete this->_d;
}

MscTimerItem const* MscTimeoutItem::timer() const
{
  return this->_d->_timer;
}

void MscTimeoutItem::setTimer(MscTimerItem const* timer)
{
  this->_d->_timer=timer;

  this->setText(this->toString());

  return;
}

QString MscTimeoutItem::toString() const
{
  QString timeoutString=QStringLiteral("timeout: ");
  if(this->_d->_timer)
    timeoutString+=QStringLiteral("of timer '")
                   +this->_d->_timer->name()
                   +QStringLiteral("'");

  return timeoutString;
}

} // namespace msc
} // namespace model

