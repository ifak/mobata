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

#include <mobata/sim/basesimstatemachine.hpp>

namespace remotecontrol {

class RemotePort;
class ControlPort;

class RemoteControlStateMachine
    : public sim::BaseSimStateMachine
{
  Q_OBJECT

public:
  RemoteControlStateMachine(const QString& name,
                            RemotePort* remotePort,
                            ControlPort* controlPort,
                            QObject* parent = nullptr);
  virtual ~RemoteControlStateMachine();

public:
  RemotePort*   remotePort();
  ControlPort*  controlPort();

  QString       currentStatesString();

public:
  void setControlSetupedTimeout(int controlSetupedTimeout);
  void setControlStartedTimeout(int controlStartedTimeout);
  void setControlStoppedTimeout(int controlStoppedTimeout);
  void setControlResettedTimeout(int controlResettedTimeout);

private:
  void createStatesAndTransitions();
  void createSetupping();
  void createStarting();
  void createStopping();
  void createResetting();

private:
  Q_DISABLE_COPY(RemoteControlStateMachine)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
