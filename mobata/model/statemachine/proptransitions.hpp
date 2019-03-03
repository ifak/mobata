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

#include "types.hpp"
#include <QUuid>

#include "../base/childrenproperty.hpp"

namespace model {
namespace statemachine {

class PropTransitions : protected base::ChildrenProperty<TransitionItem>
{
  typedef base::ChildrenProperty<TransitionItem> BaseClass;
public:
  typedef BaseClass::ChildSet       TransitionSet;
  typedef BaseClass::ConstChildSet  ConstTransitionSet;

public:
  PropTransitions(QStandardItem* ownerItem);
  virtual ~PropTransitions();

public:
  TransitionItem*         addTransition(const QString& name,
                                        const model::base::ATriggerItem* trigger,
                                        const AbstractStateItem* source,
                                        const AbstractStateItem* target,
                                        const QString& guard=QString(),
                                        const QString& action=QString(),
                                        const QUuid& transUuid=QUuid::createUuid(),
                                        QString* errorString=nullptr);
  bool                    addTransition(TransitionItem* transitionItem, QString* errorString);
  void                    removeTransition(const QUuid& transUuid);
  void                    removeTransition(TransitionItem* transition);
  TransitionItem const*   transition(const QUuid& transitionId) const;
  TransitionSet           transitions();
  ConstTransitionSet      transitions() const;

protected:
  void  resetTransitions();

private:
  Q_DISABLE_COPY(PropTransitions)
  class Private;
  Private*  _d;
};

} // namespace statemachine
} // namespace model
