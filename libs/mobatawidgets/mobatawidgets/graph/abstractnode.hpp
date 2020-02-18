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
#ifndef VIEW_GRAPH_ABSTRACTNODE_HPP
#define VIEW_GRAPH_ABSTRACTNODE_HPP

#include "../mobatawidgets_global.hpp"

#include <mobata/prop/uuidproperty.hpp>

#include <QAbstractGraphicsShapeItem>

#include "types.hpp"

namespace view{

namespace base{
class TextItem;
}

namespace graph{

class Edge;

class MOBATAWIDGETSSHARED_EXPORT AbstractNode
    : public QObject,
    public QAbstractGraphicsShapeItem,
    public prop::UuidProperty
{
  Q_OBJECT

public:
  enum { Type = NodeType};

public:
  AbstractNode(const QString& notation=QString(),
               const QUuid& uuid=QUuid::createUuid(),
               QGraphicsItem* parentItem = 0);
  virtual ~AbstractNode();

public:
  virtual QSizeF	size() const =0;
  virtual void		setSize(QSizeF size) =0;

public:
  virtual int   type() const;

public:
  void            addEdge(Edge* edge);
  void            removeEdges(QGraphicsScene* graphicsScene);
  void            removeEdge(Edge* edge);
  QList<Edge*>    edges();
  virtual void    setNotation(const QString& newNotation);
  QString         notation() const;
  base::TextItem* notationItem() const;
  virtual void    resized();
  void            updateEdgesPosition();

signals:
  void changed(bool);

protected:
  virtual QVariant  itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value);
  virtual void      hoverEnterEvent(QGraphicsSceneHoverEvent* event);
  virtual void      hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
  virtual void      mousePressEvent(QGraphicsSceneMouseEvent* event);
  virtual void      mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
  Q_DISABLE_COPY(AbstractNode)

  class Private;
  Private* _d;
};

}////end namespace graph
}//end namespace view

#endif // VIEW_GRAPH_ABSTRACTNODE_HPP
