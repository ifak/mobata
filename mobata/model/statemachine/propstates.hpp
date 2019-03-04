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

#include "../base/childrenproperty.hpp"

namespace model {
namespace statemachine {

class PropStates : protected base::ChildrenProperty<AbstractStateItem>
{
  typedef base::ChildrenProperty<AbstractStateItem> BaseClass;

public:
  typedef BaseClass::ChildSet           StateSet;
  typedef BaseClass::ConstChildSet      ConstStateSet;
  typedef QList<FinalStateItem const*>  ConstFinalStateSet;

public:
  PropStates(QStandardItem* ownerItem);
  virtual ~PropStates();

public:
  bool                      addState(AbstractStateItem* stateItem,
                                     QString* errorString=nullptr);
  bool                      setInitState(AbstractStateItem* stateItem,
                                         QString* errorMessage=nullptr);
  AbstractStateItem const*  initState() const;
  FinalStateItem*           finalState(const QUuid& finalStateId) const;
  const ConstFinalStateSet& finalStates() const;

public:
  AbstractStateItem*        state(const QUuid& stateId);
  AbstractStateItem const*  state(const QUuid& stateId) const;
  AbstractStateItem*        state(const QString& stateName);
  AbstractStateItem const*  state(const QString& stateName) const;
  StateSet                  states();
  ConstStateSet             states() const;

public:
  void removeState(const QUuid& stateUuid);
  void removeState(AbstractStateItem* stateItem);

protected:
  void  resetStates();

private:
  Q_DISABLE_COPY(PropStates)
  class Private;
  Private*  _d;
};

} // namespace statemachine
} // namespace model

