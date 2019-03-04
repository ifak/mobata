/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "proptransitions.hpp"

#include "transitionitem.hpp"

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

