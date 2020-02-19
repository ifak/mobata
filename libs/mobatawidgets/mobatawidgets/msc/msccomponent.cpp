#include "msccomponent.hpp"

#include "msccomponentlifeline.hpp"
#include "mscenvlifeline.hpp"

#include <QBrush>
#include <QPen>
#include <QEvent>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class KMscComponent::Private
{
  friend class KMscComponent;

  KMscComponentLifeline*  _lifeline;
  QGraphicsTextItem*      _nameItem;
};

KMscComponent::KMscComponent(const QString& compName,
                             const QUuid& referenceId,
                             QGraphicsItem * parent)
  : QGraphicsRectItem(parent),
    prop::ReferenceIdProperty(referenceId),
    prop::NameProperty(compName),
    _d(new Private())
{
  this->setRect(QRectF(-50, -25, 100, 50));

  this->setBrush(QBrush(QColor(225, 225, 175)));
  this->setPen(QPen(Qt::darkRed, 3));

  this->setAcceptDrops(false);
  this->setAcceptHoverEvents(false);
  this->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->setFlag(QGraphicsItem::ItemIsSelectable, true);
  this->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

  if(!compName.isEmpty())
    this->_d->_nameItem=new QGraphicsTextItem(compName, this);
  else
    this->_d->_nameItem=new QGraphicsTextItem("ENV", this);

  QRectF nameItemRect=this->_d->_nameItem->boundingRect();
  if(nameItemRect.width()>=this->rect().width())
    this->setRect(QRectF(-nameItemRect.width()/2-10, -25, nameItemRect.width()/2+10, 50));
  this->_d->_nameItem->setPos(-nameItemRect.width()/2, -nameItemRect.height()/2);

  this->_d->_nameItem->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->_d->_nameItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
  this->_d->_nameItem->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
  this->_d->_nameItem->setTextInteractionFlags(Qt::NoTextInteraction);

  this->setLifeline(new KMscComponentLifeline(this));
}

KMscComponent::KMscComponent(const QString& compName,
                             const QUuid& referenceId,
                             const QFont& compNameFont,
                             const QColor& compNameColor,
                             const QSizeF& compBoxSize,
                             const QColor& compBoxColor,
                             const QPen& compBorderPen,
                             const QPen &lifeLinePen,
                             QGraphicsItem* parent)
    : QGraphicsRectItem(parent),
      prop::ReferenceIdProperty(referenceId),
      prop::NameProperty(compName),
      _d(new Private())
{
  this->setRect(QRectF(-compBoxSize.width()/2, -compBoxSize.height()/2, compBoxSize.width(), compBoxSize.height()));

  this->setBrush(QBrush(compBoxColor));
  this->setPen(compBorderPen);

  this->setAcceptDrops(false);
  this->setAcceptHoverEvents(false);
  this->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->setFlag(QGraphicsItem::ItemIsSelectable, true);
  this->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

  if(!compName.isEmpty())
    this->_d->_nameItem=new QGraphicsTextItem(compName, this);
  else
    this->_d->_nameItem=new QGraphicsTextItem("ENV", this);

  this->_d->_nameItem->setFont(compNameFont);
  this->_d->_nameItem->setDefaultTextColor(compNameColor);

  QRectF nameItemRect=this->_d->_nameItem->boundingRect();
  if(nameItemRect.width()>=this->rect().width())
    this->setRect(QRectF(-nameItemRect.width()/2-10, -nameItemRect.height()/2-10, nameItemRect.width()+20, nameItemRect.height()+20));
  this->_d->_nameItem->setPos(-nameItemRect.width()/2, -nameItemRect.height()/2);

  this->_d->_nameItem->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->_d->_nameItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
  this->_d->_nameItem->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
  this->_d->_nameItem->setTextInteractionFlags(Qt::NoTextInteraction);

  this->setLifeline(new KMscComponentLifeline(this, lifeLinePen));
}

KMscComponent::~KMscComponent()
{
  delete this->_d;
}

KMscComponentLifeline const* KMscComponent::lifeline() const
{
  return this->_d->_lifeline;
}

KMscComponentLifeline* KMscComponent::lifeline()
{
  return this->_d->_lifeline;
}

void KMscComponent::setLifeline(KMscComponentLifeline* lifeline)
{
  if(this->_d->_lifeline)
  {
    this->_d->_lifeline->setParentItem(0);
    delete this->_d->_lifeline;
  }

  this->_d->_lifeline=lifeline;
  this->_d->_lifeline->setParentItem(this);

  return;
}

qreal KMscComponent::lifelineEndSceneY() const
{
  return this->mapToScene(0,
                          this->boundingRect().height()/2
                          +this->_d->_lifeline->boundingRect().height()).y();
}

void KMscComponent::setLifelineEndSceneY(const qreal endLifelineSceneY)
{
  this->_d->_lifeline->updateLifeline(this->boundingRect().height()/2,
                                      endLifelineSceneY);

  return;
}

KMscAnchor* KMscComponent::addAnchor()
{
  return this->_d->_lifeline->addAnchor();
}

QPointF KMscComponent::scenePos() const
{
  return this->mapToScene(this->pos());
}

QVariant KMscComponent::itemChange(GraphicsItemChange change, const QVariant &value)
{
  if (change == ItemPositionHasChanged && scene())
    this->_d->_lifeline->updateAnchors();

  return QGraphicsItem::itemChange(change, value);
}

}//////end namespace msc
}/// end namespace view
