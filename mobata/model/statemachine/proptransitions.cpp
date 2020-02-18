#include "proptransitions.hpp"

#include "transitionitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace statemachine {

PropTransitions::PropTransitions(QStandardItem* ownerItem)
  : BaseClass(ownerItem,
              QLatin1String("transitions"),
              QIcon(QLatin1String(":/mobata/images/statemachine/manytransition.png")))
{}

PropTransitions:: ~PropTransitions()
{}

void PropTransitions::resetTransitions()
{
  return BaseClass::resetChildren();
}

TransitionItem* PropTransitions::addTransition(const QString& name,
                                               const model::base::ATriggerItem* trigger,
                                               const AbstractStateItem* source,
                                               const AbstractStateItem* target,
                                               const QString& guard,
                                               const QString& action,
                                               const QUuid& transUuid,
                                               QString* errorString)
{
  Q_ASSERT(this->_ownerItem);
  Q_ASSERT(source);
  Q_ASSERT(target);
  //No assert for trigger because it can be nullptr

  TransitionItem* transitionItem = new TransitionItem(trigger, source, target, guard, action, transUuid);
  transitionItem->setName(name);
  transitionItem->setText(name);

  if(this->transition(transitionItem->name()))
  {
    utils::AddPtrString(errorString) << QObject::tr("there is already a transition with this name; "
                                                    "transition '%1' is not added!").arg(transitionItem->name());
    delete transitionItem;
    return nullptr;
  }

  BaseClass::addChild(transitionItem);

  return transitionItem;
}

bool PropTransitions::addTransition(TransitionItem* transitionItem,
                                    QString* errorString)
{
  Q_ASSERT(this->_ownerItem);
  Q_ASSERT(transitionItem);

  if(this->transition(transitionItem->uuid()))
  {
    utils::AddPtrString(errorString) << QObject::tr("there is already a transition with this id; "
                                                    "transition '%1' is not added!").arg(transitionItem->name());
    return false;
  }

  BaseClass::addChild(transitionItem);

  return true;
}

TransitionItem const* PropTransitions::transition(const QUuid& transitionId) const
{
  return BaseClass::childByUuid(transitionId);
}

PropTransitions::TransitionSet PropTransitions::transitions()
{
  return BaseClass::children();
}

PropTransitions::ConstTransitionSet PropTransitions::transitions() const
{
  return BaseClass::children();
}

void PropTransitions::removeTransition(const QUuid& transUuid)
{
  return BaseClass::removeChild(transUuid);
}

void PropTransitions::removeTransition(TransitionItem* transition)
{
  return BaseClass::removeChild(transition);
}

} // namespace statemachine
} // namespace model

