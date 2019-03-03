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

#pragma once

#include <QList>

#include "model/statemachine/abstractstateitem.hpp"

namespace convert{
namespace statemachine{

class VirtualTransition
{
public:
  VirtualTransition(const model::statemachine::AbstractStateItem* stateItem,
                    const QString& guard=QString(),
                    const QString& action=QString(),
                    bool isFusedTransition=false);

  const model::statemachine::AbstractStateItem* state();
  void              setState(const model::statemachine::AbstractStateItem* state);
  QString           guard();
  void              setGuard(const QString& guard);
  QString           action();
  void              setAction(const QString& action);
  bool              fusedTransition();
  void              setFusedTransition(bool fusedState);
  void              setTransitionChain(const QStringList transitionChain);
  QStringList const transitionChain();
private:
  QStringList _transitionChain;
  const model::statemachine::AbstractStateItem* _state;
  bool _isFusedTransition;
  QString  _guard;
  QString  _action;
};

}//statemachine
}//convert
