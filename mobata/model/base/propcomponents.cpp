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

#include "propcomponents.hpp"

#include "componentitem.hpp"
#include "portitem.hpp"

#include "../../utils/functors.hpp"

namespace model {
namespace base {

class PropComponents::Private
{
  friend class PropComponents;

  Private()
    : _componentsItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _componentsItem;
};

PropComponents::PropComponents(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setComponentsParentItem(parentItem);
}

PropComponents::~PropComponents()
{
  delete this->_d;
}

void PropComponents::resetComponents()
{
  if(this->_d->_componentsItem)
    this->_d->_componentsItem->removeRows(0,
                                          this->_d->_componentsItem->rowCount());

  return;
}

void PropComponents::cloneComponents(PropComponents* cloneComponents) const
{
  Q_ASSERT(cloneComponents);

  bool result = false;
  for(ComponentItem const* componentItem : this->components())
  {
    ComponentItem* cloneComponentItem = componentItem->clone();
    result = cloneComponents->addComponent(cloneComponentItem);
    Q_ASSERT(result);
  }

  return;
}

void PropComponents::setComponentsParentItem(QStandardItem* componentsParentItem)
{
  Q_ASSERT(componentsParentItem);

  if(this->_d->_componentsItem)
    return;

  this->_d->_componentsItem=new QStandardItem(QIcon(":/mobata/images/comp/manycomponent.png"),
                                              QLatin1String("components"));
  this->_d->_componentsItem->setFlags(this->_d->_componentsItem->flags() & ~Qt::ItemIsEditable);
  componentsParentItem->appendRow(this->_d->_componentsItem);

  return;
}

QStandardItem* PropComponents::componentsItem()
{
  return this->_d->_componentsItem;
}

bool PropComponents::addComponent(ComponentItem* component,
                                  QString* errorString)
{
  Q_ASSERT(this->_d->_componentsItem);

  if(!component)
    return false;

  if(this->component(component->name()))
  {
    utils::AddPtrString(errorString)<<QObject::tr((QLatin1String("There is already a component '")
                                                   +component->name().toLatin1()
                                                   +QLatin1String("' available!")).toLatin1());
    return false;
  }

  this->_d->_componentsItem->appendRow(component);

  return true;
}

bool PropComponents::removeComponent(const QString& compName)
{
  ComponentItem* component = this->component(compName);
  if(!component)
    return false;

  this->_d->_componentsItem->removeRow(component->row());

  return true;
}

bool PropComponents::removeComponentByID(const QUuid &compUuid)
{
  ComponentItem* component = this->componentByID(compUuid);
  if(!component)
    return false;

  this->_d->_componentsItem->removeRow(component->row());

  return true;
}

ComponentItem* PropComponents::component(const QString &compName)
{
  for(ComponentItem* compItem : this->components())
    if(compItem->name()==compName)
      return compItem;

  return 0;
}

ComponentItem const* PropComponents::component(const QString &compName) const
{
  for(ComponentItem const* compItem : this->components())
    if(compItem->name()==compName)
      return compItem;

  return 0;
}

ComponentItem* PropComponents::componentByID(const QUuid& compUuid)
{
  for(ComponentItem* compItem : this->components())
    if(compItem->uuid()==compUuid)
      return compItem;

  return 0;
}

ComponentItem const* PropComponents::componentByID(const QUuid& compUuid) const
{
  for(ComponentItem const* compItem : this->components())
    if(compItem->uuid()==compUuid)
      return compItem;

  return 0;
}

PropComponents::ConstComponentSet PropComponents::components() const
{
  ConstComponentSet components;
  if(!this->_d->_componentsItem)
    return components;

  int end=this->_d->_componentsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->_d->_componentsItem->child(i);
    ComponentItem* component=utils::simple_cast<ComponentItem*>(currChildItem);
    Q_ASSERT(component);
    components.append(component);
  }

  return components;
}

PropComponents::ComponentSet PropComponents::components()
{
  ComponentSet components;
  if(!this->_d->_componentsItem)
    return components;

  int end=this->_d->_componentsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->_d->_componentsItem->child(i);
    ComponentItem* component=utils::simple_cast<ComponentItem*>(currChildItem);
    Q_ASSERT(component);
    components.append(component);
  }

  return components;
}

ComponentItem* PropComponents::componentFromPort(const QUuid& portUuid)
{
  for(ComponentItem* component : this->components())
  {
    for (PortItem* port : component->ports())
    {
      if(port->uuid() == portUuid)
        return component;
    }
  }
  return 0;
}

} // namespace base
} // namespace model
