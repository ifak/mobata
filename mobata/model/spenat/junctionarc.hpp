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

#include "../graph/arcitem.hpp"

namespace model{
namespace spenat{

class MOBATASHARED_EXPORT JunctionArc
    : public graph::ArcItem
{
public:
  JunctionArc(graph::NodeItem* source,
              graph::NodeItem* target,
              const QUuid& uuid=QUuid::createUuid());
  virtual ~JunctionArc();

public:
  const QString&  trigger() const;
  const QString&  guard() const;
  const QString&  actions() const;

  void setTrigger(const QString& trigger);
  void setGuard(const QString& guard);
  void setActions(const QString& actions);

  QString label() const;
  QString	toString() const;

private:
  Q_DISABLE_COPY(JunctionArc)
  class Private;
  Private* _d;
};

}//////end namespace spenat
}///end namespace model
