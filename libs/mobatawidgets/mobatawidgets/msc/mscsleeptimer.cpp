#include "mscsleeptimer.hpp"

#include "mscanchor.hpp"
#include "mscscene.hpp"
#include "msccomponent.hpp"
#include "mscsequence.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

KMscSleepTimer::KMscSleepTimer(KMscAnchor* from,
                               KMscAnchor* to,
                               const double duration,
                               KMscSequence* parent)
  : KMscMessage(from, to,
                QString(QStringLiteral("sleeping for %1s")).arg(duration),
                parent)
{
  Q_ASSERT(from);
  Q_ASSERT(to);
  Q_ASSERT(from->parentItem() == to->parentItem());
}

KMscSleepTimer::KMscSleepTimer(KMscAnchor* from,
                               KMscAnchor* to,
                               const double duration,
                               const view::graph::ArcOptions& arcOptions,
                               KMscSequence* parent)
    : KMscMessage(from, to,
                  QString(QStringLiteral("sleeping for %1s")).arg(duration),
                  arcOptions,
                  parent)
{
  Q_ASSERT(from);
  Q_ASSERT(to);
  Q_ASSERT(from->parentItem() == to->parentItem());
}


KMscSleepTimer::~KMscSleepTimer()
{}

qreal KMscSleepTimer::updateGeometry(const qreal bottomSceneY,
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

  Q_ASSERT(fromComponent == toComponent);

  ///update anchors and lifeline height////////
  qreal currentBottomSceneY=bottomSceneY + marginSpace + messageTextRect.height();
  this->source()->moveBy(0, currentBottomSceneY);

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
  this->updatePositions();

  //move notation-item right of comp-line
  if(this->notationItem())
  {
    qreal comp_x=this->source()->scenePos().x();
    qreal notation_left=this->notationItem()->scenePos().x();

    if(comp_x < notation_left)
      this->notationItem()->moveBy(comp_x - notation_left, 0);
  }

  return currentBottomSceneY + marginSpace;
}

}//////end namespace msc
}// end namespace view
