#include "mscsequencestep.hpp"

#include "mscscene.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace msc {

class MscSequenceStep::Private
{
  friend class MscSequenceStep;

  QGraphicsItem* _parentItem;

  Private(QGraphicsItem* parentItem)
    : _parentItem(parentItem)
  {}
};

MscSequenceStep::MscSequenceStep(QGraphicsItem* parentItem)
  : _d(new Private(parentItem))
{
  Q_ASSERT(parentItem);
}

MscSequenceStep::~MscSequenceStep()
{
  delete this->_d;
}

QRectF MscSequenceStep::boundingRect() const
{
  return this->_d->_parentItem->boundingRect();
}

KMscScene*MscSequenceStep::mscScene()
{
  KMscScene* mscScene=utils::simple_cast<KMscScene*>(this->_d->_parentItem->scene());
  Q_ASSERT(mscScene);

  return mscScene;
}

} // namespace msc
} // namespace view

