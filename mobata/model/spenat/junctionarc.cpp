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

#include "junctionarc.hpp"

#include "junctionitem.hpp"

namespace model{
namespace spenat{

class JunctionArc::Private
{
  friend class JunctionArc;

public:
  Private()
  {}
  ~Private()
  {}

private:
  QString _trigger;
  QString _guard;
  QString _actions;
};

JunctionArc::JunctionArc(graph::NodeItem* source,
                         graph::NodeItem* target,
                         const QUuid &uuid)
  : graph::ArcItem(source, target, uuid),
    _d(new Private())
{
  this->setText(this->toString());
}

JunctionArc::~JunctionArc()
{
  delete this->_d;
}

const QString& JunctionArc::trigger() const
{
  return this->_d->_trigger;
}

const QString& JunctionArc::guard() const
{
  return this->_d->_guard;
}

const QString &JunctionArc::actions() const
{
  return this->_d->_actions;
}

void JunctionArc::setTrigger(const QString& trigger)
{
  this->_d->_trigger=trigger;

  return;
}

void JunctionArc::setGuard(const QString &guard)
{
  this->_d->_guard=guard;

  return;
}

void JunctionArc::setActions(const QString &actions)
{
  this->_d->_actions=actions;

  return;
}

QString JunctionArc::label() const
{
  QString declaration=QLatin1String("");

  if(!this->_d->_trigger.isEmpty())
    declaration+=this->_d->_trigger;

  if(!this->_d->_guard.isEmpty())
  {
    declaration+=QLatin1String("[");
    declaration+=this->_d->_guard;
    declaration+=QLatin1String("]");
  }

  if(!this->_d->_actions.isEmpty())
  {
    declaration+=QLatin1String("/");
    declaration+=this->_d->_actions;
  }

  return declaration;
}

QString JunctionArc::toString() const
{
  return this->label();
}

}///end namespace model
}///end namespace spenat
