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

class RemoteControlStateMachineQml
    : public QObject,
    public prop::NameProperty
{
  Q_OBJECT

  Q_PROPERTY(QString currentState READ currentState WRITE setCurrentState)

public:
  RemoteControlStateMachineQml(const QString& name,
                               RemotePort* remotePort,
                               ControlPort* controlPort,
                               QObject* parent = nullptr);
  virtual ~RemoteControlStateMachineQml();

protected:
  void createSetuppingConnections();
  void createStartingConnections();
  void createStoppingConnections();
  void createResettingConnections();
  void createFinishingConnections();

public:
  RemotePort*     remotePort();
  ControlPort*    controlPort();
  const QString&  currentState();

signals:
  void remoteRemoteControlOpen();
  void controlRemoteControlOpen();
  void remoteRemoteControlClose();
  void controlRemoteControlClose();

  void remoteSetup(const QVariantMap& setupArgs);
  void setupedRemote(bool value, const QString& message);
  void setupControl(const QVariantMap& setupArgs);
  void controlSetuped(bool value, const QString& message);
  void controlSetupedTimeout();

  void remoteStart();
  void startedRemote(bool value, const QString& message);
  void startControl();
  void controlStarted(bool value, const QString& message);
  void controlStartedTimeout();

  void remoteStop();
  void stoppedRemote(bool value, const QString& message);
  void stopControl();
  void controlStopped(bool value, const QString& message);
  void controlStoppedTimeout();

  void remoteReset(bool force = false);
  void resettedRemote(bool value, const QString& message);
  void resetControl();
  void controlResetted(bool value, const QString& message);
  void controlResettedTimeout();

  void controlFinished(bool value, const QString& message);
  void finishedRemote(bool value, const QString& message);

public slots:
  void  setCurrentState(const QString& currentState);
  void  startControlSetupedTimer();
  void  startControlStartedTimer();
  void  startControlStoppedTimer();
  void  startControlResettedTimer();

public:
  void setControlSetupedTimeout(int controlSetupedTimeout);
  void setControlStartedTimeout(int controlStartedTimeout);
  void setControlStoppedTimeout(int controlStoppedTimeout);
  void setControlResettedTimeout(int controlResettedTimeout);

private:
  Q_DISABLE_COPY(RemoteControlStateMachineQml)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
