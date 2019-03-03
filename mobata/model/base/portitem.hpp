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

#include "../../mobata_global.hpp"

#include "modelitem.hpp"
#include "../../prop/nameproperty.hpp"

namespace model{
namespace base{

class ComponentItem;
class LinkItem;

class MOBATASHARED_EXPORT PortItem
    : public ModelItem, public prop::NameProperty
{
public:
  enum OwnerType
  {
    Component,
    Link,
    Unknown
  };

public:
  PortItem(const QString& name,
           ComponentItem const* owner,
           const QUuid& uuid=QUuid::createUuid());

  PortItem(const QString& name,
           LinkItem const* owner,
           const QUuid& uuid=QUuid::createUuid());

  PortItem(const QString& name,
           const QUuid& uuid=QUuid::createUuid());

  virtual ~PortItem();

public:
  ModelItem const*  owner() const;
  void              setOwner(ComponentItem const* component);
  void              setOwner(LinkItem const* link);
  OwnerType         ownerType() const;
  QString           toString() const;

//public: TODO: template based owner setting and getting
//  template<class OwnerType> inline
//  OwnerType const*  owner() const;

//  template<class OwnerType> inline
//  void              setOwner(OwnerType const* component);

protected:
  ModelItem const*  _owner;
  OwnerType         _ownerType;
};

}/// namespace base
}/// namespace model
