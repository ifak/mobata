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

#include "../base/modelitem.hpp"

#include <QUuid>

namespace model{
namespace graph{

class NodeItem;

class MOBATASHARED_EXPORT ArcItem : public base::ModelItem
{
public:
  explicit ArcItem(NodeItem* source,
                   NodeItem* target,
                   const QUuid arcUuid=QUuid::createUuid());
  virtual ~ArcItem();

public:
  NodeItem* source() const;
  NodeItem* target() const;
  void	setSource(NodeItem* source);
  void	setTarget(NodeItem* target);

public:
  virtual QString toString() const;

private:
  Q_DISABLE_COPY(ArcItem)
  class Private;
  QScopedPointer<Private> _d;
};

}//////end namespace graph
}///end namespace model
