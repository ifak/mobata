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

#include "../../utils/functors.hpp"

#include <QStandardItem>
#include <QList>

class QUuid;
class QStandardItem;

namespace model {
namespace base {

class ComponentItem;

class PropComponents
{
public:
  typedef QList<ComponentItem*>       ComponentSet;
  typedef QList<ComponentItem const*> ConstComponentSet;

public:
  PropComponents(QStandardItem* parentItem);
  virtual ~PropComponents();

public:
  bool                  addComponent(ComponentItem* component,
                                     QString* errorString=0);
  bool                  removeComponentByID(const QUuid& compUuid);
  bool                  removeComponent(const QString& compName);
  ComponentItem*        component(const QString& compName);
  ComponentItem const*  component(const QString& compName) const;
  ComponentItem*        componentByID(const QUuid& compUuid);
  ComponentItem const*  componentByID(const QUuid& compUuid) const;
  ComponentSet          components();
  ConstComponentSet     components() const;
  ComponentItem*        componentFromPort(const QUuid& portUuid);

public:
  template<class ComponentType>
  ComponentType*  addComponent(const QString& name, QString* errorString)
  {
    Q_ASSERT(this->componentsItem());

    if(this->component(name))
    {
      utils::AddPtrString(errorString)<<QObject::tr((QLatin1String("There is already a component with name '")
                                                     +name
                                                     +QLatin1String("' available!")).toLatin1());
      return 0;
    }

    ComponentType* newCompItem=new ComponentType(name);
    this->componentsItem()->appendRow(newCompItem);
    newCompItem->setText(newCompItem->name());

    return newCompItem;
  }


protected:
  void            resetComponents();
  void            cloneComponents(PropComponents* cloneComponents) const;
  void            setComponentsParentItem(QStandardItem* componentsParentItem);
  QStandardItem*  componentsItem();

private:
  Q_DISABLE_COPY(PropComponents)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model
