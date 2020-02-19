#include "mscanchor.hpp"

#include "msccomponentlifeline.hpp"

#include <mobata/utils/functors.hpp>

#include <QEvent>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

KMscAnchor::KMscAnchor(KMscComponentLifeline* lifelineParent)
  : graph::RectNode(lifelineParent)
{
  this->setAcceptHoverEvents(true);
  this->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->setFlag(QGraphicsItem::ItemIsSelectable, false);

  base::TextItem* notationItem=this->notationItem();
  Q_ASSERT(notationItem);

  notationItem->setFlag(QGraphicsItem::ItemIsMovable, false);
  notationItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
  notationItem->setFlag(QGraphicsItem::ItemIsFocusable, false);
  notationItem->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
  notationItem->setTextInteractionFlags(Qt::NoTextInteraction);

  notationItem->installSceneEventFilter(this);
}

KMscAnchor::~KMscAnchor()
{}

KMscComponent* KMscAnchor::mscComponent() const
{
  KMscComponentLifeline* lifeline=utils::simple_cast<KMscComponentLifeline*>(this->parentItem());
  Q_ASSERT(lifeline);

  return lifeline->mscComponent();
}

QVariant KMscAnchor::itemChange(GraphicsItemChange change, const QVariant &value)
{
  if (change == ItemPositionHasChanged && scene())
    this->updateEdgesPosition();

  return QGraphicsItem::itemChange(change, value);
}

bool KMscAnchor::sceneEventFilter(QGraphicsItem* watched, QEvent* event)
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
