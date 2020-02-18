#include "mscmessage.hpp"

#include "mscanchor.hpp"
#include "mscsequence.hpp"
#include "mscscene.hpp"
#include "msccomponent.hpp"

#include "../base/textitem.hpp"

#include <QEvent>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace msc{

class KMscMessage::Private
{
  friend class KMscMessage;

  Private() {}
};

KMscMessage::KMscMessage(KMscAnchor* from,
                         KMscAnchor* to,
                         const QString& messageText,
                         KMscSequence* parent)
  : graph::DirectedEdge(from, to, messageText, QUuid::createUuid(), parent),
    MscSequenceStep(this),
    _d(new Private())
{
  this->setPen(QPen(Qt::darkBlue, 3));

  this->setAcceptDrops(false);
  this->setAcceptHoverEvents(false);
  this->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->setFlag(QGraphicsItem::ItemIsSelectable, true);

  base::TextItem* notationItem=this->notationItem();
  Q_ASSERT(notationItem);

  notationItem->setFlag(QGraphicsItem::ItemIsMovable, false);
  notationItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
  notationItem->setFlag(QGraphicsItem::ItemIsFocusable, false);
  notationItem->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
  notationItem->setTextInteractionFlags(Qt::NoTextInteraction);

  notationItem->installSceneEventFilter(this);

  this->updatePath(this->path());

}

KMscMessage::KMscMessage(KMscAnchor* from,
                         KMscAnchor* to,
                         const QString& messageText,
                         const view::graph::ArcOptions& arcOptions,
                         KMscSequence* parent)
  : graph::DirectedEdge(from, to, messageText, QUuid::createUuid(), arcOptions, parent),
    MscSequenceStep(this),
    _d(new Private())
{
    this->setPen(arcOptions.pen());

    this->setAcceptDrops(false);
    this->setAcceptHoverEvents(false);
    this->setFlag(QGraphicsItem::ItemIsMovable, false);
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);

    base::TextItem* notationItem=this->notationItem();
    Q_ASSERT(notationItem);

    notationItem->setFlag(QGraphicsItem::ItemIsMovable, false);
    notationItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
    notationItem->setFlag(QGraphicsItem::ItemIsFocusable, false);
    notationItem->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    notationItem->setTextInteractionFlags(Qt::NoTextInteraction);

    notationItem->installSceneEventFilter(this);

    this->updatePath(this->path());
}

KMscMessage::~KMscMessage()
{
  delete this->_d;
}

qreal KMscMessage::updateGeometry(const qreal bottomSceneY,
                                  const qreal marginSpace)
{
  QRectF messageTextRect=this->messageTextRect();

  Q_ASSERT(this->source());
  KMscAnchor* anchor=utils::simple_cast<KMscAnchor*>(this->source());
  Q_ASSERT(anchor);
  KMscComponent* fromComponent=anchor->mscComponent();
  Q_ASSERT(fromComponent);

  Q_ASSERT(this->target());
  anchor=utils::simple_cast<KMscAnchor*>(this->target());
  Q_ASSERT(anchor);
  KMscComponent* toComponent=anchor->mscComponent();
  Q_ASSERT(toComponent);

  ///update anchors and lifeline height////////
  qreal currentBottomSceneY=bottomSceneY + marginSpace + messageTextRect.height();
  this->source()->moveBy(0, currentBottomSceneY);
  fromComponent->setLifelineEndSceneY(currentBottomSceneY+25);

  if(fromComponent == toComponent)
  {
    currentBottomSceneY=currentBottomSceneY+25;
    this->target()->moveBy(0, currentBottomSceneY);
    toComponent->setLifelineEndSceneY(currentBottomSceneY+25);

    QPointF sourcePoint=this->source()->scenePos();
    QPointF targetPoint=this->target()->scenePos();

    QPainterPath path(sourcePoint);
    path.lineTo(sourcePoint.x()+25, sourcePoint.y());
    path.lineTo(targetPoint.x()+25, targetPoint.y());
    path.lineTo(targetPoint);
    this->setPath(path);
  }
  else
  {
    this->target()->moveBy(0, currentBottomSceneY);
    toComponent->setLifelineEndSceneY(currentBottomSceneY+25);

    QPointF sourcePoint=this->source()->scenePos();
    QPointF targetPoint=this->target()->scenePos();

    QPainterPath path(sourcePoint);
    path.lineTo(targetPoint);
    this->setPath(path);
  }

  this->updatePositions();

  return currentBottomSceneY + marginSpace;
}


QRectF KMscMessage::messageTextRect() const
{
  if(!this->notationItem())
    return QRectF();

  return this->notationItem()->boundingRect();

}

void KMscMessage::updateEndPositions()
{
  QPainterPath edgePath=this->path();
  if(edgePath.elementCount()==4)///same msc-object
  {
    QPointF sourcePoint=edgePath.elementAt(0);
    QPointF targetPoint=edgePath.elementAt(3);
    Q_ASSERT(sourcePoint.x()==targetPoint.x());

    QPainterPath newPath(sourcePoint);
    newPath.lineTo(sourcePoint.x()+25, sourcePoint.y());
    newPath.lineTo(targetPoint.x()+25, targetPoint.y());
    newPath.lineTo(targetPoint);

    this->setPath(newPath);
  }
  graph::DirectedEdge::updatePositions();

  /////update text-item-pos/////////
  this->updateNotationPosition();

  return;
}

void KMscMessage::updatePath(const QPainterPath& path)
{
  if(path.elementCount()==4)///same msc-object
  {
    QPointF sourcePoint=path.elementAt(0);
    QPointF targetPoint=path.elementAt(3);
    Q_ASSERT(sourcePoint.x()==targetPoint.x());

    QPainterPath newPath(sourcePoint);
    newPath.lineTo(sourcePoint.x()+25, sourcePoint.y());
    newPath.lineTo(targetPoint.x()+25, targetPoint.y());
    newPath.lineTo(targetPoint);

    graph::DirectedEdge::updatePath(newPath);
  }
  else
    graph::DirectedEdge::updatePath(path);

  /////update text-item-pos/////////
  this->updateNotationPosition();

  return;
}

void KMscMessage::updateNotationPosition()
{
  base::TextItem* notationItem=this->notationItem();
  if(!notationItem)
    return;

  QRectF textBoundingRect=notationItem->boundingRect();

  QPointF textPoint=this->path().elementAt(0);
  textPoint.setY(textPoint.y()-textBoundingRect.height());
  if(this->source()->scenePos().x() > this->target()->scenePos().x())
    textPoint.setX(textPoint.x() - textBoundingRect.width());

  this->notationItem()->setPos(this->mapToItem(notationItem, textPoint));

  return;
}

bool KMscMessage::sceneEventFilter(QGraphicsItem* watched, QEvent* event)
{
  if(watched==this->notationItem())
  {
    event->accept();
    return true;
  }

  return false;
}

}//////end namespace msc
}/// end namespace view
