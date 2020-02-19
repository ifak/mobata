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
#ifndef VIEW_COMP_COMPONENT_HPP
#define VIEW_COMP_COMPONENT_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../graph/resizingrectnode.hpp"

#include <QSizeF>

namespace view{
namespace comp{

class Port;

class MOBATAWIDGETSSHARED_EXPORT Component
    : public graph::ResizingRectNode
{

public:
  enum{Type = UserType + ComponentItem};

public:
  Component(const QString& notation = QLatin1String("newComponent"),
            const NodeOptions& nodeOptions=NodeOptions());
  virtual ~Component();

public:
  virtual int       type() const;
  virtual QVariant  itemChange(GraphicsItemChange change, const QVariant &value);
  virtual void      resized();

protected:
  virtual void      hoverEnterEvent(QGraphicsSceneHoverEvent* event);
  virtual void      hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

public:
  Port*               addPort(QPointF scenePoint,
                              const QString& portName = QLatin1String("newPort"),
                              const NodeOptions& nodeOptions=NodeOptions()
                                                             .setSize(15,15)
                                                             .setColor(Qt::white)
                                                             .setPen(QPen(Qt::black, 3)));
  Port const*         port(const QString& portName) const;
  Port*               port(const QString& portName);
  Port const*         port(const QUuid& portUuid) const;
  Port*               port(const QUuid& portUuid);
  const QList<Port*>& ports() const;

  void removePort(Port *port);

private:
  class Private;
  Private*  _d;
};

}////end namespace comp

}//end namespace view

#endif
