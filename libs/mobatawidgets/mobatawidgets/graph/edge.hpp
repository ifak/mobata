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
#ifndef VIEW_GRAPH_EDGE_HPP
#define VIEW_GRAPH_EDGE_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsPathItem>

#include <mobata/prop/uuidproperty.hpp>

#include "controlpoint.hpp"

namespace view{

namespace base{
class TextItem;
}

namespace graph{

class AbstractNode;

class MOBATAWIDGETSSHARED_EXPORT Edge
    : public QObject,
    public QGraphicsPathItem,
    public prop::UuidProperty
{
  Q_OBJECT

public:
  enum { Type = EdgeType};

  enum LineStyle
  {
    Custom,
    Spline,
    Rectilinear
  };

protected:
  typedef ControlPoint<Edge>              ControlPointType;
  typedef QMap<ControlPointType*, ushort> ControlPointSet;

public:
  Edge(AbstractNode* from, AbstractNode* to,
       const QString& notation=QString(),
       const QUuid& uuid=QUuid::createUuid(),
       const ArcOptions& arcOptions=ArcOptions(),
       const LineStyle lineStyle = Custom,
       QGraphicsItem * parentItem = 0);

  virtual	~Edge();

signals:
  void changed(bool);

public:
  AbstractNode*       source();
  AbstractNode*       target();
  AbstractNode const* source() const;
  AbstractNode const* target() const;
  base::TextItem*     notationItem() const;
  QString             notation() const;
  void                setSource(AbstractNode* source);
  void                setTarget(AbstractNode* target);
  void                setNotationAnchorPercent(qreal notationAnchorPercent);
  void                setControlPointsMovable(bool value);
  void                setControlPointsSelectable(bool value);

  QList<QPointF>      controlPointFs() const;
  QMap<ControlPoint<Edge>*, ushort>     controlPoints() const;

  LineStyle           lineStyle() const;
  void                setLineStyle(const LineStyle lineStyle);

public:
  virtual int           type() const;
  virtual void          setNotation(const QString& newNotation);
  virtual void          updatePath(const QPainterPath& path);
  virtual void          updatePositions();
  virtual void          controlPointMove(ControlPointType* controlPoint);
  virtual void          controlPointPressed(ControlPointType* controlPoint);
  virtual void          controlPointReleased(ControlPointType* controlPoint);
  virtual void          setInteractable(bool interactableValue);
  virtual QPainterPath  shape() const;

  const ArcOptions&     arcOptions() const;
  virtual void          setArcOptions(const ArcOptions& arcOptions);

protected:
  virtual QVariant  itemChange(GraphicsItemChange change, const QVariant &value);
  virtual void      hoverEnterEvent (QGraphicsSceneHoverEvent * event);
  virtual void      hoverLeaveEvent (QGraphicsSceneHoverEvent * event);

private:
  class Private;
  Private*	_d;
};

}////end namespace graph
}//end namespace view

#endif
