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
#ifndef VIEW_GRAPH_ARROW_H
#define VIEW_GRAPH_ARROW_H

#include "../mobatawidgets_global.hpp"

#include <QGraphicsPathItem>

#include "types.hpp"

class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

namespace view{
namespace graph{

class DirectedEdge;

class MOBATAWIDGETSSHARED_EXPORT Arrow : public QGraphicsPathItem
{
public:
    enum {Type = ArrowType};

public:
    Arrow(QPointF startPos, QPointF endPos, DirectedEdge* parentEdge);
    Arrow(QPointF startPos, QPointF endPos, qreal arrowWidth, qreal arrowHeight, DirectedEdge* parentEdge);
    virtual ~Arrow();

public:
    int		type() const;
    void	updateArrow(QPointF startPos, QPointF endPos);

private:
    class Private;
    Private* _d;
};

}//////////end namespace graph
}//end namespace view

#endif
