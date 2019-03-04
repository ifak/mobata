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

#include "portitem.hpp"

#include "componentitem.hpp"
#include "linkitem.hpp"

namespace model{
namespace base{

PortItem::PortItem(const QString& name,
                   ComponentItem const* owner,
                   const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _owner(owner),
    _ownerType(Component)
{
  this->setIcon(QIcon(QLatin1String(":/mobata/images/base/port.png")));
  this->setText(this->name());
}

PortItem::PortItem(const QString& name,
                   LinkItem const* owner,
                   const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _owner(owner),
    _ownerType(Link)
{
  this->setIcon(QIcon(QLatin1String(":/mobata/images/base/port.png")));
  this->setText(this->name());
}

PortItem::PortItem(const QString& name,
                   const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _owner(nullptr),
    _ownerType(Unknown)
{
  this->setIcon(QIcon(QLatin1String(":/mobata/images/base/port.png")));
  this->setText(this->name());
}

PortItem::~PortItem()
{}

ModelItem const* PortItem::owner() const
{
  return this->_owner;
}

void PortItem::setOwner(ComponentItem const* component)
{
  this->_owner=component;
  this->_ownerType=Component;

  return;
}

void PortItem::setOwner(LinkItem const* link)
{
  this->_owner=link;
  this->_ownerType=Link;

  return;
}

PortItem::OwnerType PortItem::ownerType() const
{
  return this->_ownerType;
}

QString PortItem::toString() const
{
  QString portString=QStringLiteral("");
  if(this->_owner)
    portString+=this->_owner->toString()+QStringLiteral(".");

  portString+=this->name();

  return portString;
}

}/// namespace base
}/// namespace model
