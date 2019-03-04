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

#include "signaltriggeritem.hpp"

#include "signalitem.hpp"
#include "portitem.hpp"

namespace model {
namespace base {

class SignalTriggerItem::Private
{
  friend class SignalTriggerItem;

  base::SignalItem const* _triggerSignal;
  base::PortItem const*   _port;

  Private(base::SignalItem const* triggerSignal =nullptr,
          base::PortItem const* port =nullptr)
    : _triggerSignal(triggerSignal), _port(port)
  {}
};

SignalTriggerItem::SignalTriggerItem(base::SignalItem const* triggerSignal)
  : _d(new Private(triggerSignal))
{}

SignalTriggerItem::SignalTriggerItem(base::SignalItem const* triggerSignal,
                                     base::PortItem const* port)
  : _d(new Private(triggerSignal, port))
{}

SignalTriggerItem::~SignalTriggerItem()
{
  delete this->_d;
}

QString SignalTriggerItem::declaration() const
{
  QString declaration(QStringLiteral(""));

  if(this->_d->_triggerSignal)
  {
    declaration = this->_d->_triggerSignal->name();
    if(this->_d->_port)
      declaration += QStringLiteral(" at ")
                     +this->_d->_port->name();
  }

  return declaration;
}

void SignalTriggerItem::setTriggerSignal(const base::SignalItem *triggerSignal)
{
  this->_d->_triggerSignal=triggerSignal;

  return;
}

base::SignalItem const* SignalTriggerItem::triggerSignal() const
{
  return this->_d->_triggerSignal;
}

void SignalTriggerItem::setPort(const base::PortItem *port)
{
  this->_d->_port=port;

  return;
}

base::PortItem const* SignalTriggerItem::port() const
{
  return this->_d->_port;
}

} // namespace base
} // namespace model
