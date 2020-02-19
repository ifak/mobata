#include "exttransition.hpp"

ExtTransition::ExtTransition(const QString& name,
                             model::spenat::ATriggerItem* triggerItem,
                             const QString &guard,
                             const QString &actions,
                             const QUuid &uuid)
  : model::spenat::TransitionItem(name,triggerItem, guard, actions, uuid)
{

}

ExtTransition::~ExtTransition()
{}
