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
#ifndef VIEW_COMP_SYSTEMSCENE_HPP
#define VIEW_COMP_SYSTEMSCENE_HPP

#include "../graph/graphscene.hpp"
#include "types.hpp"

namespace view{
namespace comp{

class Component;
class Port;
class Link;
class SutComponent;
class TestComponent;

class SystemScene : public graph::GraphScene
{
  Q_OBJECT

public:
  SystemScene(QObject *parent = 0);
  virtual ~SystemScene();

signals:
  void componentAdded(const QUuid& compUuid);
  void portAdded(const QUuid& portUuid);
  void linkAdded(const QUuid& linkUuid);
  void componentRemoved(const QUuid& compUuid);
  void portRemoved(const QUuid& portUuid);
  void linkRemoved(const QUuid& linkUuid);

public:
  virtual void      addComponent(Component* newComponent,
                                 QPointF pos);
  virtual void      removeComponent(Component* component);
  Component*        component(const QUuid &compUuid);
  QList<Component*> components();

  Port*         addPort(Component* component,
                        QPointF portPos,
                        NodeOptions options = NodeOptions()
                                              .setSize(15,15)
                                              .setColor(Qt::white)
                                              .setPen(QPen(Qt::black, 3)));
  Port*         addPort(Component* component,
                        QPointF portPos,
                        QUuid uuid);
  void          removePort(Port* port);
  QList<Port*>  ports(const QUuid& compUuid);
  Port*         port(const QUuid& portUuid);

  Link*         addLink(Port* from,
                        Port* to,
                        const QPainterPath& path,
                        ArcOptions options = ArcOptions());
  void          removeLink(Link* link);
  QList<Link*>  links();
  QList<Link*>  links(Port* port);
  Link*         link(const QUuid& linkUuid);

public:
  void setSelected(Component* comp);
  void setSelected(Port* port);
};

}/////end namespace comp
}/// end namespace view

#endif
