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

#include "msccheckmessageitem.hpp"
#include "../msc/msctimeoutitem.hpp"

namespace model {
namespace msc {

class MscCheckMessageItem::Private
{
  friend class MscCheckMessageItem;

  QString _guard;
  int     _timeout;

  Private(const QString& guard,
          const int timeout)
    : _guard(guard),
      _timeout(timeout)
  {}
};

MscCheckMessageItem::MscCheckMessageItem(const PortItem* sourcePort,
                                         const PortItem* targetPort,
                                         const QString& guard,
                                         const int timeout)
  : MscMessageItem(sourcePort, targetPort),
    _d(new Private(guard, timeout))
{
  this->setText(this->toString());
}

MscCheckMessageItem::~MscCheckMessageItem()
{  
  delete this->_d;
}

const QString& MscCheckMessageItem::guard() const
{
  return this->_d->_guard;
}

void MscCheckMessageItem::setGuard(const QString &guard)
{
  this->_d->_guard=guard;

  return;
}

int MscCheckMessageItem::timeout() const
{
  return this->_d->_timeout;
}

void MscCheckMessageItem::setTimeout(const int timeOut)
{
  this->_d->_timeout = timeOut;

  return;
}

QString MscCheckMessageItem::toString() const
{
  QString messageString;
  if (MscMessageItem::toString(true) == QLatin1Char('[') + this->_d->_guard + QLatin1Char(']')){
    messageString = MscMessageItem::toString(true);
  }else{
    messageString = MscMessageItem::toString(true);
    if(!this->_d->_guard.isEmpty())
      messageString+=QLatin1Char('[')
                     + this->_d->_guard
                     +QLatin1Char(']');

    if(this->_d->_timeout > 0)
      messageString +=QLatin1String(" after ")
                      + QString::number(this->_d->_timeout)
                      + QLatin1String(" ms");
  }
  return messageString;
}

} // namespace msc
} // namespace model

