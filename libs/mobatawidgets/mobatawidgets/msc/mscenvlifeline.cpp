#include "mscenvlifeline.hpp"

#include "msccomponent.hpp"

#include <QPen>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

KMscEnvLifeline::KMscEnvLifeline(KMscComponent* mscComponent)
  : KMscComponentLifeline(mscComponent)
{
  this->setBrush(QBrush(mscComponent->pen().color(), Qt::BDiagPattern));
  this->setPen(QPen(Qt::NoPen));
}

KMscEnvLifeline::~KMscEnvLifeline()
{}

void KMscEnvLifeline::updateLifeline(const qreal startY, const qreal endY)
{
  if((endY<startY) || (endY-startY <= this->boundingRect().height()))
    return;

  QPainterPath newPath(QPointF(0,startY));
  newPath.addRect(-10, startY, 20, endY-startY);

  this->setPath(newPath);

  return;
}

}//////end namespace msc
}/// end namespace view
