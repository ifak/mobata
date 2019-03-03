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

#include "junctionstateitem.hpp"
#include "transitionitem.hpp"

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

