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

#include "../base/basemodel.hpp"
#include "../base/propports.hpp"
#include "propstates.hpp"
#include "proptransitions.hpp"

namespace model{

namespace statemachine {

class MOBATASHARED_EXPORT StateMachineModel
    : public base::BaseModel,
    public base::PropPorts,
    public PropStates,
    public PropTransitions
{
  Q_OBJECT

public:
  StateMachineModel(QObject *parent = 0);
  virtual ~StateMachineModel();

public:
  bool addState(AbstractStateItem* stateItem,
                QString* errorString=nullptr);
  TransitionItem* addSignalTransition(const QString& name,
                                      const SignalItem* signal,
                                      const PortItem* port,
                                      const AbstractStateItem* source,
                                      const AbstractStateItem* target,
                                      const QString& guard=QLatin1String(""),
                                      const QString& action=QLatin1String(""),
                                      const QUuid& transUuid=QUuid::createUuid(),
                                      QString* errorString=nullptr);

  TransitionItem* addTimeoutTransition(const QString& name,
                                       const double timeout,
                                       const AbstractStateItem* source,
                                       const AbstractStateItem* target,
                                       const QString& guard=QLatin1String(""),
                                       const QString& action=QLatin1String(""),
                                       const QUuid& transUuid=QUuid::createUuid(),
                                       QString* errorString=nullptr);

public:///virtual methods
  virtual void  reset();

private:
  void createTransitionsParentItem();
  void createStatesParentItem();

private:
  Q_DISABLE_COPY(StateMachineModel)
  class Private;
  Private*  _d;
};

typedef QSharedPointer<StateMachineModel> StateMachineModelPtr;

}/// namespace statemachine
}/// namespace model
