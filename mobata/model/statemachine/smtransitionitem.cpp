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

#include "transitionitem.hpp"
#include "../base/atriggeritem.hpp"
#include "../base/signaltriggeritem.hpp"
#include "../base/signalitem.hpp"

using namespace model::base;

namespace model {
namespace statemachine {

class TransitionItem::Private
{
  friend class TransitionItem;

  AbstractStateItem const*  _source;
  AbstractStateItem const*  _target;
  ATriggerItem const *       _trigger=nullptr;
  QString                   _guard;
  QString                   _action;

  Private(ATriggerItem const*       trigger,
          AbstractStateItem const* source,
          AbstractStateItem const* target,
          const QString&           guard,
          const QString&           action)
    : _source(source), _target(target), _trigger(trigger),
      _guard(guard), _action(action)
  {}

};

TransitionItem::TransitionItem(ATriggerItem const*       trigger,
                               AbstractStateItem const* source,
                               AbstractStateItem const* target,
                               const QString&           guard,
                               const QString&           action,
                               const QUuid&             id)
  : base::ModelItem(id),
    prop::NameProperty(),
    _d(new Private(trigger, source, target, guard, action))
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/transition.png")));
  if(this->name().isEmpty() && trigger)
    if(trigger->triggerType() == ATriggerItem::EventTrigger){
      const SignalTriggerItem* eventTrigger = static_cast<const SignalTriggerItem*>(trigger);
      if(eventTrigger && eventTrigger->triggerSignal())
        this->setName(eventTrigger->triggerSignal()->name());
    }
}

TransitionItem::~TransitionItem()
{
  if(this->_d->_trigger != nullptr)
    delete this->_d->_trigger;
  delete this->_d;
}

AbstractStateItem const* TransitionItem::source() const
{
  return this->_d->_source;
}

AbstractStateItem* TransitionItem::source()
{
  if(!this->_d->_source)
    return nullptr;

  return const_cast<AbstractStateItem*>(this->_d->_source);
}

AbstractStateItem const* TransitionItem::target() const
{
  return this->_d->_target;
}

AbstractStateItem* TransitionItem::target()
{
  if(!this->_d->_target)
    return nullptr;

  return const_cast<AbstractStateItem*>(this->_d->_target);
}

const QString& TransitionItem::guard() const
{
  return this->_d->_guard;
}

const QString& TransitionItem::action() const
{
  return this->_d->_action;
}

ATriggerItem const* TransitionItem::trigger() const
{
  return this->_d->_trigger;
}

ATriggerItem* TransitionItem::trigger()
{
  if(!this->_d->_trigger)
    return nullptr;

  return const_cast<ATriggerItem*>(this->_d->_trigger);
}

void TransitionItem::setSource(AbstractStateItem const* source)
{
  this->_d->_source=source;
}

void TransitionItem::setTarget(AbstractStateItem const* target)
{
  this->_d->_target=target;
}

void TransitionItem::setTrigger(ATriggerItem const* trigger)
{
  this->_d->_trigger=trigger;
}

void TransitionItem::setGuard(const QString& guard)
{
  this->_d->_guard=guard;
}

void TransitionItem::setAction(const QString& action)
{
  this->_d->_action=action;
}

void TransitionItem::removeTrigger()
{
  if(this->_d->_trigger)
    delete this->_d->_trigger;

  this->_d->_trigger=nullptr;
}

} // namespace statemachine
} // namespace model

