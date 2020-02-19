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

class RemoteControlUserService;

class REMOTECONTROLSHARED_EXPORT RemoteControlUser
    : public RemoteComponent
{
  Q_OBJECT

  friend class RemoteControlUserService;

public:
  explicit RemoteControlUser(const QString& name,
                             RemoteControlUserService* remoteControlUserService,
                             QObject* parent = 0,
                             QHostAddress remoteAddress = QHostAddress::LocalHost,
                             quint16 remotePort = 10000,
                             QHostAddress hostAddress = QHostAddress::LocalHost,
                             quint16 hostPort = 10001);
  virtual ~RemoteControlUser();

public slots:
  virtual void setup() = 0;
  virtual void start();
  virtual void stop();
  virtual void reset();

  virtual void statusRequest();

public:
  bool            run(QString* errorString);
  bool            isRunning() const;
  const QString&  remoteState() const;

signals:
  void setuped(bool value,
               const QStringList& messages);
  void started(bool value,
               const QStringList& messages);
  void stopped(bool value,
               const QStringList& messages);
  void resetted(bool value,
                const QStringList& messages);
  void finished(bool value,
                const QStringList& messages);

  void status(const QString& state,
              const QStringList& messages);

public:
  void                setUserAddress(const QHostAddress& userAddress);
  void                setUserPort(const quint16 userPort);

  void                setRemoteControlAddress(const QHostAddress& rcAddress);
  void                setRemoteControlPort(const quint16 rcPort);
  void                setRemoteControlServiceProvider(const QString& rcServiceProvider);

  const QHostAddress& userAddress() const;
  QString             userAddressString() const;
  quint16             userPort() const;
  const QHostAddress& remoteControlAddress() const;
  quint16             remoteControlPort() const;
  const QString&      remoteControlServiceProvider() const;

private:
  void  setRemoteState(const QString& remoteState);

private:
  Q_DISABLE_COPY(RemoteControlUser)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
