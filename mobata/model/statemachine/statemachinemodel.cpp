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

#include "statemachinemodel.hpp"
#include "abstractstateitem.hpp"
#include "transitionitem.hpp"

#include "../base/signaltriggeritem.hpp"
#include "../base/timeouttriggeritem.hpp"
#include "../base/atriggeritem.hpp"
#include "../base/signalitem.hpp"
#include "../base/portitem.hpp"
#include "../base/basemodel.hpp"

#include "../../mobata_global.hpp"


namespace model{
namespace statemachine{

class StateMachineModel::Private
{
  friend class StateMachineModel;

  Private():_statesItem(nullptr), _transitionsItem(nullptr), _initStateParentItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _statesItem;
  QStandardItem*  _transitionsItem;
  QStandardItem*  _initStateParentItem;
};

StateMachineModel::StateMachineModel(QObject *parent)
  :	base::BaseModel(parent),
    base::PropPorts(this->invisibleRootItem()),
    PropStates(this->invisibleRootItem()),
    PropTransitions(this->invisibleRootItem()),
    _d(new Private())
{
}

StateMachineModel::~StateMachineModel()
{
  delete this->_d;
}

void StateMachineModel::reset()
{
  base::BaseModel::reset();

  this->resetPorts();

  if(this->_d->_statesItem)
    this->_d->_statesItem->removeRows(0, this->_d->_statesItem->rowCount());

  if(!this->states().empty())
    this->resetStates();

  if(this->_d->_transitionsItem)
    this->_d->_transitionsItem->removeRows(0, this->_d->_transitionsItem->rowCount());

  if(!this->transitions().empty())
    this->resetTransitions();

  if(this->_d->_initStateParentItem)
    this->_d->_initStateParentItem->removeRows(0, this->_d->_initStateParentItem->rowCount());

  this->setName(QLatin1String("StateMachine"));

  return;
}

void StateMachineModel::createStatesParentItem()
{
  if(this->_d->_statesItem)
    return;

  this->_d->_statesItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/statemachine/manystate.png")),
                                          QLatin1String("states"));
  this->_d->_statesItem->setFlags(this->_d->_statesItem->flags() & ~Qt::ItemIsEditable);
  this->appendRow(this->_d->_statesItem);

  return;
}

void StateMachineModel::createTransitionsParentItem()
{
  if(this->_d->_transitionsItem)
    return;

  this->_d->_transitionsItem=new QStandardItem(QIcon(
                                                 QLatin1String(
                                                   ":mobata/images/statemachine/manytransition.png")),
                                               QLatin1String("transitions"));
  this->_d->_transitionsItem->setFlags(this->_d->_transitionsItem->flags() & ~Qt::ItemIsEditable);
  this->appendRow(this->_d->_transitionsItem);

  return;
}

bool StateMachineModel::addState(AbstractStateItem* stateItem,
                                 QString* errorString)
{
  if(!stateItem)
    return false;

  return PropStates::addState(stateItem, errorString);
}

TransitionItem* StateMachineModel::addSignalTransition(const QString& name,
                                                       const SignalItem* signal,
                                                       const PortItem* port,
                                                       const AbstractStateItem* source,
                                                       const AbstractStateItem* target,
                                                       const QString& guard,
                                                       const QString& action,
                                                       const QUuid& transUuid,
                                                       QString* errorString)
{
  Q_ASSERT(signal);
  Q_ASSERT(port);
  Q_ASSERT(source);
  Q_ASSERT(target);

  model::base::SignalTriggerItem* trigger = new model::base::SignalTriggerItem(signal, port);
  TransitionItem* transition = this->addTransition(name, trigger, source, target, guard, action, transUuid, errorString);
  if(!transition)
  {
    delete trigger;
    return nullptr;
  }

  return transition;

}

TransitionItem* StateMachineModel::addTimeoutTransition(const QString& name,
                                                        const double timeout,
                                                        const AbstractStateItem* source,
                                                        const AbstractStateItem* target,
                                                        const QString& guard,
                                                        const QString& action,
                                                        const QUuid& transUuid,
                                                        QString* errorString)
{
  Q_ASSERT(source);
  Q_ASSERT(target);

  model::base::TimeoutTriggerItem* trigger = new model::base::TimeoutTriggerItem(timeout);
  TransitionItem* transition = this->addTransition(name, trigger, source, target, guard, action, transUuid, errorString);
  if(!transition)
  {
    delete trigger;
    return nullptr;
  }

  return transition;
}

}///end namespace model
}///end namespace spenat
