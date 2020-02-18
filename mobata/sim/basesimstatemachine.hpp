/*
 * This file is part of mobata.
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

#include "../mobata_global.hpp"

#include <QStateMachine>
#include "../prop/nameproperty.hpp"

namespace sim{

class BaseSimState;

class MOBATASHARED_EXPORT BaseSimStateMachine
    : public QStateMachine,
    public prop::NameProperty
{
  Q_OBJECT

public:
  BaseSimStateMachine(const QString& name,
                      QObject* parent=nullptr);
  virtual ~BaseSimStateMachine();

signals:
  void stateEntered(BaseSimState* baseSimState);
  void stateExited(BaseSimState* baseSimState);
  void configurationChanged();

public:
  bool                  addSimState(BaseSimState* baseSimState,
                                    QString* errorString = 0);
  BaseSimState const*   simState(const QString& stateName) const;
  QList<BaseSimState*>  currentStates(bool onlyLeafStates=true);

private:
  Q_DISABLE_COPY(BaseSimStateMachine)
  class Private;
  Private* _d;
};

}// namespace sim
