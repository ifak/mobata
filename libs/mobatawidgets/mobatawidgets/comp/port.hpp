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
#ifndef VIEW_COMP_PORT_HPP
#define VIEW_COMP_PORT_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../graph/rectnode.hpp"
#include "../base/textitem.hpp"

namespace view{
namespace comp{

class Link;

class MOBATAWIDGETSSHARED_EXPORT Port
    : public graph::RectNode
{
public:
  enum {Type = UserType + PortItem};

public:
  template<class ParentType>
  Port(ParentType* parent,
       const QString& notation="newPort",
       const NodeOptions& portOptions=NodeOptions()
                                      .setSize(15,15)
                                      .setColor(Qt::white)
                                      .setPen(QPen(Qt::black, 3)),
       const QUuid& uuid=QUuid::createUuid())
    : graph::RectNode(notation, portOptions, uuid, parent)
  {
    this->setBrush(portOptions.getColor());

    this->setAcceptHoverEvents(true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->setFlag(QGraphicsItem::ItemIsSelectable, false);

    this->notationItem()->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->notationItem()->setFlag(QGraphicsItem::ItemIsSelectable, false);
  }

public:
  int type() const;

public:
  void  addLink(Link* link);
  void  updatePosition();
  void  setLayoutPosition(QPointF possPosPoint);

protected:
  void  mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void  mousePressEvent(QGraphicsSceneMouseEvent* event);

protected:
  virtual QPointF calcPosition(QPointF possPosition);
};

}////end namespace comp

}// end namespace view

#endif
