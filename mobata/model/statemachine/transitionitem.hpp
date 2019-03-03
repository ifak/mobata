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

#include "../../mobata_global.hpp"

#include "types.hpp"

#include "../base/modelitem.hpp"
#include "../../prop/nameproperty.hpp"

namespace model {
namespace statemachine {

class MOBATASHARED_EXPORT TransitionItem
    : public base::ModelItem,
    public prop::NameProperty
{
public:
  TransitionItem(const model::base::ATriggerItem* triggerItem,
                 const AbstractStateItem* source,
                 const AbstractStateItem* target,
                 const QString& guard = QLatin1String(""),
                 const QString& action = QLatin1String(""),
                 const QUuid& id=QUuid::createUuid());

  virtual ~TransitionItem();

public:
  AbstractStateItem const*          source() const;
  AbstractStateItem*                source();
  AbstractStateItem const*          target() const;
  AbstractStateItem*                target();
  const QString&                    guard() const;
  const QString&                    action() const;
  model::base::ATriggerItem const*  trigger() const;
  model::base::ATriggerItem*        trigger();

  void setSource(AbstractStateItem const* source);
  void setTarget(AbstractStateItem const* target);
  void setTrigger(model::base::ATriggerItem const* trigger);
  void setGuard(const QString& guard);
  void setAction(const QString& action);

  void removeTrigger();

private:
  Q_DISABLE_COPY(TransitionItem)
  class Private;
  Private*  _d;
};

} // namespace statemachine
} // namespace model
