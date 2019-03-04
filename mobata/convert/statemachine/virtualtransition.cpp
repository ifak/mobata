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

#include "virtualtransition.hpp"

#include "mobata/model/spenat/placeitem.hpp"

namespace convert{
namespace statemachine{

VirtualTransition::VirtualTransition(const model::statemachine::AbstractStateItem* stateItem,
                                     const QString& guard,
                                     const QString& action,
                                     bool isFusedTransition)
  : _state(stateItem),
    _isFusedTransition(isFusedTransition),
    _guard(guard),
    _action(action)
{
}

const model::statemachine::AbstractStateItem* VirtualTransition::state()
{
  return this->_state;
}

void VirtualTransition::setState(const model::statemachine::AbstractStateItem* state)
{
  Q_ASSERT(state);

  this->_state = state;
}

QString  VirtualTransition::guard()
{
  return this->_guard;
}

void VirtualTransition::setGuard(const QString& guard)
{
  this->_guard = guard;
}

QString VirtualTransition::action()
{
  return this->_action;
}

void VirtualTransition::setAction(const QString& action)
{
  this->_action = action;
}

bool VirtualTransition::fusedTransition()
{
  return this->_isFusedTransition;
}

void VirtualTransition::setFusedTransition(bool fusedState)
{
  this->_isFusedTransition = fusedState;
}

void VirtualTransition::setTransitionChain(const QStringList transitionChain)
{
  this->_transitionChain = transitionChain;
}

const QStringList VirtualTransition::transitionChain()
{
  return this->_transitionChain;
}

}//statemachine
}//convert
