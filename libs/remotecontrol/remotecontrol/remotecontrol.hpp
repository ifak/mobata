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

#include "remotecontrol_global.hpp"

#include "remotecomponent.hpp"

class QHostAddress;

namespace remotecontrol {

class RemoteControlService;
class RemotePort;
class ControlPort;

class REMOTECONTROLSHARED_EXPORT RemoteControl
    : public RemoteComponent
{
  Q_OBJECT

  friend class RemoteControlService;

public:
  explicit RemoteControl(const QString& name,
                         RemoteControlService* remoteControlService,
                         QObject* parent = 0,
                         QHostAddress remoteAddress = QHostAddress::LocalHost,
                         quint16 remotePort = 10001,
                         QHostAddress userAddress = QHostAddress::LocalHost,
                         quint16 userPort = 10000);
  virtual ~RemoteControl();

public:
  bool  run(QString* errorString = 0);
  bool  run(const QHostAddress& localAddress,
            const quint16 localPort,
            QString* errorString = 0);
  bool  isRunning() const;

public:
  RemotePort*   remotePort();
  ControlPort*  controlPort();

public:
  void                setLocalAddress(const QHostAddress& localAddress);
  void                setLocalPort(const quint16 localPort);
  void                setUserAddress(const QHostAddress& userAddress);
  void                setUserPort(const quint16 userPort);
  void                setUserServiceProvider(const QString& userServiceProvider);

  const QHostAddress& localAddress() const;
  quint16             localPort() const;
  const QHostAddress& userAddress() const;
  quint16             userPort() const;
  const QString&      userServiceProvider() const;

public:
  bool                isError() const;
  const QStringList&  errors() const;
  void                addError(const QString& error);

protected:
  void  sendMessage(const QString& message);

private:
  Q_DISABLE_COPY(RemoteControl)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
