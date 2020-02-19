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

#include <qjsonrpcservice.h>

namespace remotecontrol {

class RemoteControlUser;

class REMOTECONTROLSHARED_EXPORT RemoteControlUserService
    : public QJsonRpcService
{
  Q_OBJECT
  Q_CLASSINFO("serviceName", "remotecontroluser")

  friend class RemoteControlUser;

public:
  RemoteControlUserService(QObject* parent = 0);
  virtual ~RemoteControlUserService();

public Q_SLOTS:
  QJsonValue  setuped(bool result, const QStringList& messages);
  QJsonValue  started(bool result, const QStringList& messages);
  QJsonValue  stopped(bool result, const QStringList& messages);
  QJsonValue  resetted(bool result, const QStringList& messages);
  QJsonValue  finished(bool result, const QStringList& messages);

  QJsonValue  statusResponse(const QString& state, const QStringList& messages);
  QJsonValue  message(const QString& message);

protected:
  void                setRemoteControlUser(RemoteControlUser* remoteControlUser);
  RemoteControlUser*  remoteControlUser();

private:
  Q_DISABLE_COPY(RemoteControlUserService)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
