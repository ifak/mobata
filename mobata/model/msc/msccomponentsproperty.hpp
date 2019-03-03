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

#pragma once

#include "../base/childrenproperty.hpp"
#include "msccomponentitem.hpp"

namespace model {
namespace msc {

template<class ComponentType>
class MscComponentsProperty
    : base::ChildrenProperty<ComponentType>
{
  typedef base::ChildrenProperty<ComponentType> BaseClass;
public:
  typedef typename BaseClass::ChildSet       ComponentSet;
  typedef typename BaseClass::ConstChildSet  ConstComponentSet;

public:
  explicit MscComponentsProperty(QStandardItem* ownerItem)
    : BaseClass(ownerItem,
                QStringLiteral("components"),
                QIcon(QStringLiteral(":/mobata/images/comp/manycomponent.png")))
  {}
  virtual ~MscComponentsProperty()
  {}

protected:
  void  resetComponents() {return BaseClass::resetChildren();}

public:
  bool  addComponent(ComponentType* component,
                     QString* errorString=nullptr)
  {
    Q_ASSERT(this->_ownerItem);

    if(!component)
      return false;

    if(this->component(component->name()))
    {
      if(errorString)
        *errorString+=QObject::tr((QLatin1String("There is already a component '")
                                   +component->name().toLatin1()
                                   +QLatin1String("' available!")).toLatin1());
      return false;
    }

    return BaseClass::addChild(component);
  }

  ComponentType*  addComponent(const QString& name,
                               QString* errorString=nullptr)
  {
    Q_ASSERT(this->_ownerItem);

    if(this->component(name))
    {
      if(errorString)
        *errorString+=QObject::tr((QLatin1String("There is already a component '")
                                   +name
                                   +QLatin1String("' available!")).toLatin1());
      return 0;
    }

    ComponentType* newComponent = new ComponentType(name);
    bool result = BaseClass::addChild(newComponent);
    if(!result)
    {
      delete newComponent;
      newComponent = 0;
    }

    return newComponent;
  }

public:
  ComponentType*  component(const QString& compName)
  {
    return BaseClass::childByName(compName);
  }

  ComponentType const*  component(const QString& compName) const
  {
    return BaseClass::childByName(compName);
  }

public:
  ComponentType*  component(const QUuid& compUuid)
  {
    return BaseClass::childByUuid(compUuid);
  }

  ComponentType const*  component(const QUuid& compUuid) const
  {
    return BaseClass::childByUuid(compUuid);
  }

  ComponentSet  components()
  {
    return BaseClass::children();
  }

  ConstComponentSet components() const
  {
    return BaseClass::children();
  }

  void  removeComponent(const QUuid& compUuid)
  {
    return BaseClass::removeChild(compUuid);
  }

  bool  removeComponent(const QString& compName)
  {
    Q_ASSERT(this->_ownerItem);

    ComponentType* foundComponent = this->component(compName);
    if(foundComponent)
      return this->removeComponent(foundComponent);

    return false;
  }

public:
  ComponentType*  componentFromPort(const QUuid& portUuid)
  {
    for(ComponentType* component: this->components()){
      for (PortItem* port: component->ports()) {
        if(port->uuid() == portUuid)
          return component;
      }
    }

    return 0;
  }

  ComponentType const*  componentFromPort(const QUuid& portUuid) const
  {
    for(ComponentType* component: this->components()){
      for (PortItem* port: component->ports()) {
        if(port->uuid() == portUuid)
          return component;
      }
    }

    return 0;
  }

  PortItem*  port(const QUuid& portUuid)
  {
    for(ComponentType* component: this->components())
    {
      for (PortItem* port: component->ports())
      {
        if(port->uuid() == portUuid)
          return port;
      }
    }

    return 0;
  }

  PortItem const*  port(const QUuid& portUuid) const
  {
    for(ComponentType const* component: this->components())
    {
      for (PortItem const* port: component->ports())
      {
        if(port->uuid() == portUuid)
          return port;
      }
    }

    return 0;
  }
};

} // namespace msc
} // namespace model
