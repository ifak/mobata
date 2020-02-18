/*
 * This file is part of mobata.
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
#ifndef VIEW_GRAPH_DIRECTEDEDGE_HPP
#define VIEW_GRAPH_DIRECTEDEDGE_HPP

#include "../mobatawidgets_global.hpp"

#include "edge.hpp"

namespace view{
namespace graph{

class Arrow;

class MOBATAWIDGETSSHARED_EXPORT DirectedEdge
    : public Edge
{
  typedef Edge::ControlPointType  ControlPointType;

public:
  enum { Type = DirectedEdgeType};

public:
  DirectedEdge(AbstractNode* from, AbstractNode* to,
               QGraphicsItem * parent = 0);
  DirectedEdge(AbstractNode* from, AbstractNode* to,
               const QString& notation,
               QGraphicsItem * parent = 0);
  DirectedEdge(AbstractNode* from, AbstractNode* to,
               const QString& notation,
               const QUuid& uuid,
               QGraphicsItem * parent = 0);
  DirectedEdge(AbstractNode* from, AbstractNode* to,
               const QString& notation,
               const QUuid& uuid,
               const ArcOptions& arcOptions,
               QGraphicsItem * parent = 0);
  DirectedEdge(AbstractNode* from, AbstractNode* to,
               const QString& notation,
               const QUuid& uuid,
               const ArcOptions& arcOptions,
               const LineStyle lineStyle,
               QGraphicsItem * parent = 0);
  virtual ~DirectedEdge();

public:
  virtual int type() const;

public:
  void  updatePositions();
  void  updatePath(const QPainterPath& path);
  void  controlPointMove(ControlPointType* controlPoint);

public:
  virtual void setArcOptions(const ArcOptions& arcOptions);

protected:
  void ctor(bool isCustomArcOptionsUsed = false);

private:
  Q_DISABLE_COPY(DirectedEdge)
  class Private;
  Private* _d;
};

}////end namespace graph
}//end namespace view

#endif
