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

#include "mscsleeptimeritem.hpp"

namespace model{
namespace msc{

class MscSleepTimerItem::Private
{
  friend class MscSleepTimerItem;

  Private(int value)
    : _value(value)

  {}

  double  _value;
};

MscSleepTimerItem::MscSleepTimerItem(const MscComponentItem* component,
                                     double value)
  :	MscStepItem(component), _d(new Private(value))
{
  Q_ASSERT(component);

  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/sleeptimer.png")));
  this->setText(this->toString());
}

MscSleepTimerItem::~MscSleepTimerItem()
{
  delete this->_d;
}

void MscSleepTimerItem::setValue(double value)
{
  this->_d->_value=value;

  this->setText(this->toString());

  return;
}

double MscSleepTimerItem::value() const
{
  return this->_d->_value;
}

QString MscSleepTimerItem::toString() const
{
  return QString(QLatin1String("sleeping for ")
                 +QString::fromLatin1("%1").arg(this->_d->_value)
                 +QLatin1String("s"));
}

} // namespace msc
} // namespace model

