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

#include "msctimeritem.hpp"

namespace model{
namespace msc{

class MscTimerItem::Private
{
  friend class MscTimerItem;

  Private(int value)
    : _value(value)
  {}

  double  _value;
};

MscTimerItem::MscTimerItem(const MscComponentItem* component,
                           const QString& name,
                           double value)
  :	MscStepItem(component),
    prop::NameProperty(name),
    _d(new Private(value))
{
  Q_ASSERT(component);
  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/timer.png")));
  this->setText(this->toString());
}

MscTimerItem::~MscTimerItem()
{
  delete this->_d;
}

void MscTimerItem::setValue(double value)
{
  this->_d->_value=value;

  this->setText(this->toString());

  return;
}

double MscTimerItem::value() const
{
  return this->_d->_value;
}

QString MscTimerItem::toString() const
{
  return QString(this->name()
                 +QLatin1String(": after ")
                 +QString::fromLatin1("%1").arg(this->_d->_value)
                 +QLatin1String("s"));
}

}/// end namespace msc
}/// end namespace model
