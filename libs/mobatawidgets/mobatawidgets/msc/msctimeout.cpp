#include "msctimeout.hpp"

#include "mscanchor.hpp"
#include "msccomponent.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace msc {

class KMscTimeout::Private
{
  friend class KMscTimeout;

  QString _timerName;

  Private(const QString& timerName)
    : _timerName(timerName)
  {}
};

KMscTimeout::KMscTimeout(KMscAnchor* from, KMscAnchor* to,
                         const QString& timerName,
                         KMscSequence* parent)
  : KMscMessage(from, to,
                QString(QStringLiteral("timeout of timer '%1'")).arg(timerName),
                parent),
    _d(new Private(timerName))
{}

KMscTimeout::KMscTimeout(KMscAnchor* from, KMscAnchor* to,
                         const QString& timerName,
                         const view::graph::ArcOptions& arcOptions,
                         KMscSequence* parent)
  : KMscMessage(from, to,
                QString(QStringLiteral("timeout of timer '%1'")).arg(timerName),
                arcOptions,
                parent),
    _d(new Private(timerName))
{}

KMscTimeout::~KMscTimeout()
{
  delete this->_d;
}

qreal KMscTimeout::updateGeometry(const qreal bottomSceneY,
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
  this->source()->moveBy(-25, currentBottomSceneY);
  this->target()->moveBy(0, currentBottomSceneY);
  toComponent->setLifelineEndSceneY(currentBottomSceneY+25);

  QPointF sourcePoint=this->source()->scenePos();
  QPointF targetPoint=this->target()->scenePos();

  QPainterPath path(sourcePoint);
  path.lineTo(targetPoint);
  this->setPath(path);
  this->updatePositions();

  //move notation-item left of comp-line
  if(this->notationItem())
  {
    qreal comp_x=this->source()->scenePos().x()-10;
    qreal notation_right=this->notationItem()->scenePos().x()
                         + this->messageTextRect().width()/2;

    if(notation_right > comp_x)
      this->notationItem()->moveBy(-(notation_right-comp_x),0);
  }

  return currentBottomSceneY + marginSpace;
}

} // namespace msc
} // namespace view

