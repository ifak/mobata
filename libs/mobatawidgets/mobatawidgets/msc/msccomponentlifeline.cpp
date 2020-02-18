#include "msccomponentlifeline.hpp"

#include "mscanchor.hpp"
#include "msccomponent.hpp"

#include <mobata/utils/functors.hpp>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class KMscComponentLifeline::Private
{
  friend class KMscComponentLifeline;

  Private()
    : _stepSize(50)
  {}

  QVector<KMscAnchor*>  _mscAnchors;
  qreal                 _stepSize;
};

KMscComponentLifeline::KMscComponentLifeline(KMscComponent* mscComponent)
  : QGraphicsPathItem(mscComponent),
    _d(new Private())
{
  Q_ASSERT(mscComponent);

  QRectF boundingRect=mscComponent->boundingRect();

  this->updateLifeline(boundingRect.height()/2, 50);
  this->setPen(mscComponent->pen());
}

KMscComponentLifeline::KMscComponentLifeline(KMscComponent* mscComponent, const QPen &lifeLinePen)
    : QGraphicsPathItem(mscComponent),
  _d(new Private())
{
  Q_ASSERT(mscComponent);

  QRectF boundingRect=mscComponent->boundingRect();

  this->updateLifeline(boundingRect.height()/2, 50);
  this->setPen(lifeLinePen);
}

KMscComponentLifeline::~KMscComponentLifeline()
{
  delete this->_d;
}

KMscAnchor* KMscComponentLifeline::addAnchor()
{
  KMscAnchor* newMscAnchor=new KMscAnchor(this);
  this->_d->_mscAnchors.push_back(newMscAnchor);

  return newMscAnchor;
}

void KMscComponentLifeline::updateAnchors()
{
  foreach(KMscAnchor* mscAnchor, this->_d->_mscAnchors)
    mscAnchor->updateEdgesPosition();

  return;
}

KMscComponent* KMscComponentLifeline::mscComponent() const
{
  KMscComponent* mscComponent=utils::simple_cast<KMscComponent*>(this->parentItem());
  Q_ASSERT(mscComponent);

  return mscComponent;
}

void KMscComponentLifeline::updateLifeline(const qreal startY,
                                           const qreal endY)
{
  if(endY-startY <= this->boundingRect().height())
    return;

  QPainterPath newPath(QPointF(0,startY));
  newPath.lineTo(0,endY);
  newPath.lineTo(-5,endY);
  newPath.moveTo(0,endY);
  newPath.lineTo(5, endY);

  this->setPath(newPath);

  return;
}

}//////end namespace msc
}/// end namespace view
