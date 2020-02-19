#include "junctionstateitem.hpp"
#include "transitionitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace statemachine {

JunctionStateItem::JunctionStateItem(const QString& name,
                                     const QUuid& id)
  : AbstractStateItem(name.isEmpty()?QStringLiteral("junction"):name, id),
    PropTransitions(this)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/junctionstate.png")));
}

JunctionStateItem::~JunctionStateItem()
{}

TransitionItem* JunctionStateItem::addJunctionTransition(const QString& name,
                                                         AbstractStateItem const* target,
                                                         const QString& guard,
                                                         const QString& action,
                                                         const QUuid& transUuid,
                                                         QString* errorMessage)
{
  Q_ASSERT(target);

  TransitionItem* transition = this->addTransition(name, nullptr, this, target, guard, action, transUuid, errorMessage);

  return transition;
}

bool JunctionStateItem::addJunctionTransition(TransitionItem* transitionItem,
                                              QString* errorString)
{
  if(!this->addTransition(transitionItem,
                          errorString))
    return false;

  transitionItem->setSource(this);

  return true;
}

StateType JunctionStateItem::stateType() const
{
  return Junction;
}

} // namespace statemachine
} // namespace model

