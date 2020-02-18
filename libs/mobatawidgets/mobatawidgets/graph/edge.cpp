#include "edge.hpp"

#include "../base/textitem.hpp"

#include "arrow.hpp"
#include "functors.hpp"
#include "abstractnode.hpp"

#include <QGraphicsScene>
#include <QDebug>

#include <assert.h>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class Edge::Private
{
  friend class Edge;
public:
  Private(AbstractNode* from,
          AbstractNode* to,
          const ArcOptions& arcOptions,
          const LineStyle lineStyle)
    :	_source(from), _target(to),
      _notationItem(0),
      _notationAnchor(0),
      _notationAnchorPercent(0.25),
      _arcOptions(arcOptions),
      _lineStyle(lineStyle)
  {}
  ~Private()
  {}
private:
  AbstractNode*       _source;
  AbstractNode*       _target;
  AbstractNode*       _previousSourceNode;
  AbstractNode*       _previousTargetNode;
  ControlPointSet     _controlPoints;
  base::TextItem*     _notationItem;
  QGraphicsRectItem*  _notationAnchor;
  qreal               _notationAnchorPercent;
  ArcOptions          _arcOptions;
  LineStyle           _lineStyle;
};

Edge::Edge(AbstractNode* from, AbstractNode* to,
           const QString& notation,
           const QUuid &uuid,
           const ArcOptions& arcOptions,
           const LineStyle lineStyle,
           QGraphicsItem* parentItem)
  : QGraphicsPathItem(parentItem),
    prop::UuidProperty(uuid),
    _d(new Private(from, to, arcOptions, lineStyle))
{
  this->setPen(this->_d->_arcOptions.pen());
  this->_d->_notationAnchor=new QGraphicsRectItem(-0.1,-0.1,0.2,0.2,this);
  this->_d->_notationAnchor->setPen(this->pen());
  this->_d->_notationItem=new base::TextItem(notation, this->_d->_notationAnchor);
  this->_d->_notationItem->setDefaultTextColor(this->_d->_arcOptions.textColor());
  this->_d->_notationItem->setFont(this->_d->_arcOptions.textFont());
  this->_d->_notationItem->setTextInteractionFlags(Qt::TextEditable);
  this->setToolTip(notation);

  this->setAcceptHoverEvents(true);
  this->setFlag(QGraphicsItem::ItemIsSelectable, true);

  if(this->_d->_source)
    this->_d->_source->addEdge(this);
  if(this->_d->_target)
    this->_d->_target->addEdge(this);

  QPointF startPoint, endPoint;
  if(this->_d->_source)
    startPoint=this->_d->_source->scenePos();
  else
    startPoint=QPointF(0,0);

  if(this->_d->_target)
    endPoint=this->_d->_target->scenePos();
  else
    endPoint=QPointF(1,1);

  if(startPoint==endPoint)
    endPoint+=QPointF(1, 1);

  QPainterPath path(startPoint);
  path.lineTo(endPoint);
  this->updatePath(path);
}

Edge::~Edge()
{
  delete this->_d;
}

int Edge::type() const
{
  return Type;
}

void Edge::setNotation(const QString &newNotation)
{
  this->_d->_notationItem->setPlainText(newNotation);
  this->setToolTip(newNotation);

  return;
}

AbstractNode* Edge::source()
{
  if(this->_d->_source)
    return this->_d->_source;
  else
    return 0;
}

AbstractNode const* Edge::source() const
{
  if(this->_d->_source)
    return this->_d->_source;
  else
    return 0;
}

AbstractNode* Edge::target()
{
  if(this->_d->_target)
    return this->_d->_target;
  else
    return 0;
}

AbstractNode const* Edge::target() const
{
  if(this->_d->_target)
    return this->_d->_target;
  else
    return 0;
}

base::TextItem* Edge::notationItem() const
{
  return this->_d->_notationItem;
}

QString Edge::notation() const
{
  return this->_d->_notationItem->toPlainText();
}

void Edge::setSource(AbstractNode *source)
{
  this->_d->_source=source;

  return;
}

void Edge::setTarget(AbstractNode *target)
{
  this->_d->_target=target;

  return;
}

void Edge::setNotationAnchorPercent(qreal notationAnchorPercent)
{
  if(notationAnchorPercent<0 || notationAnchorPercent>1)
    return;

  this->_d->_notationAnchorPercent=notationAnchorPercent;

  return;
}

void Edge::setControlPointsMovable(bool value)
{
  for(ControlPointSet::iterator it=this->_d->_controlPoints.begin(); it!=this->_d->_controlPoints.end(); ++it)
    it.key()->setFlag(QGraphicsItem::ItemIsMovable, value);

  return;
}

void Edge::setControlPointsSelectable(bool value)
{
  for(ControlPointSet::iterator it=this->_d->_controlPoints.begin(); it!=this->_d->_controlPoints.end(); ++it)
    it.key()->setFlag(QGraphicsItem::ItemIsSelectable, value);

  return;
}

QList<QPointF> Edge::controlPointFs() const
{
  QList<QPointF> controlPoints;

  foreach (ControlPointType const* controlPoint, this->_d->_controlPoints.keys())
    controlPoints.push_back(controlPoint->pos());

  return controlPoints;
}

QMap<ControlPoint<Edge> *, ushort> Edge::controlPoints() const
{
  return this->_d->_controlPoints;
}

Edge::LineStyle Edge::lineStyle() const
{
  return this->_d->_lineStyle;
}

void Edge::setLineStyle(const LineStyle lineStyle)
{
  this->_d->_lineStyle=lineStyle;

  return;
}

void Edge::updatePositions()
{
  if(!this->_d->_source || !this->_d->_target)
    return;

  QPainterPath newPath=this->path();
  ushort elementCount=newPath.elementCount();

  QPointF sourcePoint=this->mapFromScene(this->_d->_source->scenePos());
  QPointF targetPoint=this->mapFromScene(this->_d->_target->scenePos());

  QRectF sourceRect=this->_d->_source->boundingRect();
  sourceRect.translate(sourcePoint);

  QRectF targetRect=this->_d->_target->boundingRect();
  targetRect.translate(targetPoint);

  QLineF sourceLine(sourcePoint, targetPoint), targetLine(sourcePoint, targetPoint);
  if(elementCount>2)
  {
    sourceLine=QLineF(sourcePoint, newPath.elementAt(1));
    targetLine=QLineF(newPath.elementAt(elementCount-2), targetPoint);
  }
  QPointF sourceIntersectPoint=calcIntercectPoint(sourceLine, sourceRect);
  if(sourceIntersectPoint!=QPointF())
    sourcePoint=sourceIntersectPoint;

  QPointF targetIntersectPoint=calcIntercectPoint(targetLine, targetRect);
  if(targetIntersectPoint!=QPointF())
    targetPoint=targetIntersectPoint;

  newPath.setElementPositionAt(0, sourcePoint.x(), sourcePoint.y());
  newPath.setElementPositionAt(elementCount-1, targetPoint.x(), targetPoint.y());

  if(this->_d->_lineStyle==Rectilinear)
    this->setPath(makeRectPath(newPath));
  else
    this->setPath(newPath);

  this->_d->_notationAnchor->setPos(this->path().pointAtPercent(this->_d->_notationAnchorPercent));

  emit changed(true);
  return;
}

void Edge::updatePath(const QPainterPath& p)
{
  this->setPath(p);
  this->updatePositions();

  QPainterPath path = this->path();

  int diff = path.elementCount() - this->_d->_controlPoints.size();

  if(diff>0)
  {
    for(int i=0; i<diff; ++i){
      this->_d->_controlPoints.insert(new ControlPointType(this),
                                      this->_d->_controlPoints.size());

    }
  }
  else if(diff<0)
  {
    for(int i=0; i>diff; --i)
    {
      ControlPointType* firstPoint=this->_d->_controlPoints.begin().key();
      this->_d->_controlPoints.erase(this->_d->_controlPoints.begin());
      delete firstPoint;
    }
  }

  ControlPointSet::iterator c_it;
  ushort index=0;
  for(c_it=this->_d->_controlPoints.begin(); c_it!=this->_d->_controlPoints.end(); c_it++, index++)
  {
    ControlPointType* currControlPoint=c_it.key();
    currControlPoint->setPos(path.elementAt(index));
    c_it.value()=index;
  }
  this->setControlPointsMovable(false);

  return;
}

void Edge::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
  this->setPen(QPen(this->pen().color(), this->pen().width()+3));
  //	QFont notationFont=this->_d->_notationItem->font();
  //	notationFont.setBold(true);
  //	this->_d->_notationItem->setFont(notationFont); TODO: edge-hover-enter-event, no bold font for noation-item
  this->_d->_notationItem->showAssociationLine(true);

  return QGraphicsItem::hoverEnterEvent(event);
}

void Edge::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
  this->setPen(QPen(this->pen().color(), this->pen().width()-3));
  //	QFont notationFont=this->_d->_notationItem->font();
  //	notationFont.setBold(false);
  //	this->_d->_notationItem->setFont(notationFont);TODO: edge-hover-leave-event, no bold font for noation-item
  this->_d->_notationItem->showAssociationLine(false);

  return QGraphicsItem::hoverEnterEvent(event);
}

void Edge::controlPointMove(ControlPointType* controlPoint)
{
  if(!controlPoint)
    return;

  assert(this->_d->_controlPoints.find(controlPoint)!=this->_d->_controlPoints.end());

  QPointF newPosition=controlPoint->pos();

  QPainterPath newPath=this->path();
  newPath.setElementPositionAt(this->_d->_controlPoints.value(controlPoint),
                               newPosition.x(),
                               newPosition.y());
  this->setPath(newPath);
  this->updatePositions();

  QPainterPath path = this->path();
  ushort n_index = 0;
  ControlPointSet::iterator end = this->_d->_controlPoints.end();
  for(ControlPointSet::iterator c_it = this->_d->_controlPoints.begin(); c_it!=end; c_it++, n_index++)
  {
    if(c_it.key()==controlPoint)
      continue;
    c_it.key()->setPos(path.elementAt(n_index));
  }

  return;
}

void Edge::controlPointPressed(ControlPointType* controlPoint)
{
  Q_UNUSED(controlPoint);
  return;
}

void Edge::controlPointReleased(ControlPointType* controlPoint)
{
  Q_UNUSED(controlPoint);
  return;
}

void Edge::setInteractable(bool interactableValue)
{
  this->setFlag(QGraphicsItem::ItemIsSelectable, interactableValue);
  this->setControlPointsMovable(interactableValue);

  return;
}

QPainterPath Edge::shape() const
{
  QPainterPath path(this->path());
  QPainterPathStroker pathStroke;
  pathStroke.setWidth(15);

  return pathStroke.createStroke(path);
}

const ArcOptions& Edge::arcOptions() const
{
  return this->_d->_arcOptions;
}

void Edge::setArcOptions(const ArcOptions &arcOptions)
{
  this->_d->_arcOptions = arcOptions;

  this->setPen(this->_d->_arcOptions.pen());
  this->_d->_notationAnchor->setPen(this->pen());
  this->_d->_notationItem->setDefaultTextColor(this->_d->_arcOptions.textColor());
  this->_d->_notationItem->setFont(this->_d->_arcOptions.textFont());

  return;
}

QVariant Edge::itemChange(GraphicsItemChange change, const QVariant &value)
{
  if (change == ItemPositionChange && scene())
    this->updatePositions();
  else if(change == ItemSelectedChange)
  {
    if(value.toBool())
    {
      foreach(ControlPointType* controlPoint, this->_d->_controlPoints.keys())
        controlPoint->show();
    }
    else
    {
      foreach(ControlPointType* controlPoint, this->_d->_controlPoints.keys())
        if(!controlPoint->isSelected())
          controlPoint->hide();
    }
  }
  return QGraphicsItem::itemChange(change, value);
}

}///end namespace graph
}//end namespace view
