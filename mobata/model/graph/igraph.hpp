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

#include <QUuid>

namespace model{
namespace graph{

class NodeItem;
class ArcItem;
  
class IGraph
{
public:
  typedef QList<NodeItem const*>  ConstNodeSet;
  typedef QList<ArcItem const*>   ConstArcSet;
  
public:
  explicit IGraph() {}
  virtual ~IGraph() {}
  
public:
  virtual NodeItem const* node(const QUuid& nodeUuid) const =0;
  virtual NodeItem*       node(const QUuid& nodeUuid) =0;
  virtual ConstNodeSet    nodes() const =0;
  
  virtual ArcItem*        arc(const QUuid& arcUuid) =0;
  virtual ConstArcSet     arcs() const =0;
};
  
} // namespace graph
} // namespace model
