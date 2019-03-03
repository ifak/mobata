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

#include "base_types.hpp"

#include "modelitem.hpp"
#include "propattributes.hpp"
#include "propports.hpp"
#include "../../prop/nameproperty.hpp"

namespace model{

namespace base{

class MOBATASHARED_EXPORT ComponentItem
    : public ModelItem,
    public prop::NameProperty,
    public PropAttributes,
    public PropPorts
{
public:
  ComponentItem(const QString& name);
  virtual ~ComponentItem();

public:
  virtual int     compType() const;
  virtual QString compTypeString() const;

public:
  bool            addPort(PortItem* port,
                          QString *errorString=0) override;
  PortItem*       addPort(const QString &portName,
                          QString* errorString=0) override;

public:
  virtual ComponentItem*  clone() const override;
  virtual QString         toString() const override;

private:
  Q_DISABLE_COPY(ComponentItem)
};

}/// end namespace msc
}/// end namespace model
