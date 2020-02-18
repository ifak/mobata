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

#include <QHostAddress>

namespace remotecontrol {

class RemoteControl;

class REMOTECONTROLSHARED_EXPORT RemoteControlService
    : public QJsonRpcService
{
  Q_OBJECT
  Q_CLASSINFO("serviceName", "remotecontrol")

  friend class RemoteControl;

protected:
  RemoteControlService(QObject* parent = 0);

public:
  virtual ~RemoteControlService();

signals:
  void statusRequest();

public slots:
  QJsonValue open(QString userAddressString,
                  quint16 userPort);
  QJsonValue close();
  QJsonValue setup(const QVariantMap& setupArgs);
  QJsonValue status();
  QJsonValue start();
  QJsonValue stop();
  QJsonValue reset(bool force = false);

protected:
  void            setRemoteControl(RemoteControl* remoteControl);
  RemoteControl*  remoteControl();

private:
  Q_DISABLE_COPY(RemoteControlService)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
