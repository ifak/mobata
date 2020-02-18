#include "abstractnode.hpp"

#include "../base/textitem.hpp"

#include "edge.hpp"

#include <QGraphicsScene>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class AbstractNode::Private
{
  friend class AbstractNode;
private:
  Private()		{}
  ~Private()	{}

private:
  QList<Edge*>    _edges;
  base::TextItem* _notationItem;
};

AbstractNode::AbstractNode(const QString& notation,
                           const QUuid &uuid,
                           QGraphicsItem* parentItem)
  : QAbstractGraphicsShapeItem(parentItem), prop::UuidProperty(uuid), _d(new Private())
{
  this->setHandlesChildEvents(true);
  this->setAcceptHoverEvents(true);
  this->setFlag(QGraphicsItem::ItemIsMovable, true);
  this->setFlag(QGraphicsItem::ItemIsSelectable, true);
  this->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
  this->setCacheMode(ItemCoordinateCache);

  this->_d->_notationItem=new base::TextItem(notation, this);
  this->_d->_notationItem->setFont(QFont("Arial", 8));
  this->_d->_notationItem->setTextInteractionFlags(Qt::TextEditable);
  this->_d->_notationItem->setFlag(QGraphicsItem::ItemIsSelectable, true);
  this->setToolTip(notation);

  connect(this->_d->_notationItem, SIGNAL(changed(bool)),
          this, SIGNAL(changed(bool)));

}

AbstractNode::~AbstractNode()
{
  delete this->_d;
}

int AbstractNode::type() const
{
  return Type;
}

void AbstractNode::addEdge(Edge* edge)
{
  if(!edge)
    return;

  if(edge)
    this->_d->_edges.push_back(edge);

  return;
}

void AbstractNode::removeEdges(QGraphicsScene* graphicsScene)
{
  QListIterator<Edge*> e_it(this->_d->_edges);
  while(e_it.hasNext())
  {
    Edge* edge=e_it.next();

    AbstractNode* sourceNode=edge->source();
    AbstractNode* targetNode=edge->target();

    if(sourceNode==this)
      targetNode->removeEdge(edge);
    else if(targetNode==this)
      sourceNode->removeEdge(edge);

    graphicsScene->removeItem(edge);
    delete edge;
  }

  return;
}

void AbstractNode::removeEdge(Edge* edge)
{
  this->_d->_edges.removeAll(edge);

  return;
}

QList<Edge *> AbstractNode::edges()
{
  return this->_d->_edges;
}

void	AbstractNode::setNotation(const QString& newNotation)
{
  this->_d->_notationItem->setPlainText(newNotation);
  this->setToolTip(newNotation);

  return;
}

QString AbstractNode::notation() const
{
  return this->_d->_notationItem->toPlainText();
}

base::TextItem* AbstractNode::notationItem() const
{
  return this->_d->_notationItem;
}

QVariant AbstractNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value)
{
  if (change == QGraphicsItem::ItemPositionChange)
  {
    if((this->scene())){
      this->updateEdgesPosition();
      emit changed(true);
    }
  }
  else if(change == QGraphicsItem::ItemSelectedChange)
  {
    QFont notationFont=this->_d->_notationItem->font();
    if(value.toBool())
      notationFont.setBold(true);
    else
      notationFont.setBold(false);

    this->_d->_notationItem->setFont(notationFont);
  }

  return QAbstractGraphicsShapeItem::itemChange(change, value);
}

void AbstractNode::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
  QPen currentPen(this->pen());
  currentPen.setWidthF(currentPen.widthF()+2);
  this->setPen(currentPen);

  //	QFont notationFont=this->_d->_notationItem->font();
  //	notationFont.setBold(true);
  //	this->_d->_notationItem->setFont(notationFont);TODO: node-hover-enter-event, no bold font for noation-item
  this->_d->_notationItem->showAssociationLine(true);

  return QAbstractGraphicsShapeItem::hoverEnterEvent(event);
}

void AbstractNode::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
  QPen currentPen(this->pen());
  currentPen.setWidthF(currentPen.widthF()-2);
  this->setPen(currentPen);

  //	QFont notationFont=this->_d->_notationItem->font();
  //	notationFont.setBold(false);
  //	this->_d->_notationItem->setFont(notationFont);TODO: node-hover-leave-event, no bold font for noation-item
  this->_d->_notationItem->showAssociationLine(false);

  return QAbstractGraphicsShapeItem::hoverLeaveEvent(event);
}

void AbstractNode::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  return QAbstractGraphicsShapeItem::mousePressEvent(event);
}

void AbstractNode::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
  return QAbstractGraphicsShapeItem::mouseReleaseEvent(event);
}

void AbstractNode::resized()
{
  this->updateEdgesPosition();

  return;
}

void AbstractNode::updateEdgesPosition()
{
  foreach(Edge* edge, this->_d->_edges){
    edge->updatePath(edge->path());
  }

  return;
}

}////end namespace graph
}//end namespace view
