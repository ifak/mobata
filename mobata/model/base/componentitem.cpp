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

#include "componentitem.hpp"

#include "portitem.hpp"

#include "../../utils/functors.hpp"

namespace model{
namespace base{

ComponentItem::ComponentItem(const QString &name)
  : prop::NameProperty(name),
    PropAttributes(this),
    PropPorts(this)
{
  this->setIcon(QIcon(":mobata/images/msc/component.png"));
  this->setText(this->toString());
}

ComponentItem::~ComponentItem()
{}

int ComponentItem::compType() const
{
  return ComponentType;
}

QString ComponentItem::compTypeString() const
{
  return QStringLiteral("ComponentType");
}

bool ComponentItem::addPort(PortItem *port, QString *errorString)
{
  if(!port)
    return false;

  port->setOwner(this);
  return PropPorts::addPort(port, errorString);
}

PortItem* ComponentItem::addPort(const QString &portName,
                                 QString *errorString)
{
  PortItem* newPort=PropPorts::addPort(portName, errorString);
  if(!newPort)
    return 0;

  newPort->setOwner(this);

  return newPort;
}

ComponentItem*ComponentItem::clone() const
{
  ComponentItem* cloneComponent = new ComponentItem(this->name());
  this->cloneAttributes(cloneComponent);
  this->clonePorts(cloneComponent);

  return cloneComponent;
}

QString ComponentItem::toString() const
{
  return this->name();
}

}/// end namespace base
}/// end namespace model
