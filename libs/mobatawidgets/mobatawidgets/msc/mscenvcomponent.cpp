#include "mscenvcomponent.hpp"

#include "mscenvlifeline.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace msc {

KMscEnvComponent::KMscEnvComponent(const QString& compName,
                                   const QUuid& referenceId,
                                   QGraphicsItem * parent)
  : KMscComponent(compName, referenceId, parent)
{
  this->setLifeline(new KMscEnvLifeline(this));
}

KMscEnvComponent::~KMscEnvComponent()
{}

} // namespace msc
} // namespace view

