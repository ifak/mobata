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

#include <QObject>
#include <mobata/prop/nameproperty.hpp>

namespace remotecontrol {

class RemotePort;
class ControlPort;

class RemoteControlStateMachineScxml
    : public QObject,
    public prop::NameProperty
{
  Q_OBJECT

public:
  RemoteControlStateMachineScxml(const QString& name,
                                 RemotePort* remotePort,
                                 ControlPort* controlPort,
                                 QObject* parent = nullptr);
  virtual ~RemoteControlStateMachineScxml();

public:
  RemotePort*   remotePort();
  ControlPort*  controlPort();

  QString       currentState();

public:
  void setControlSetupedTimeout(int controlSetupedTimeout);
  void setControlStartedTimeout(int controlStartedTimeout);
  void setControlStoppedTimeout(int controlStoppedTimeout);
  void setControlResettedTimeout(int controlResettedTimeout);

private:
  void createSetupConnections();
  void createStartConnections();
  void createStopConnections();
  void createResetConnections();

private:
  Q_DISABLE_COPY(RemoteControlStateMachineScxml)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
