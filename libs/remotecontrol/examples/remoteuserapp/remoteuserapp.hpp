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

#include <remotecontrol/remotecontroluser.hpp>
#include <remotecontrol/remotecontroluserservice.hpp>

class RemoteUserService
    : public remotecontrol::RemoteControlUserService
{
public:
  RemoteUserService(QObject* parent = 0);
};

class RemoteUserApp
    : public remotecontrol::RemoteControlUser
{
  Q_OBJECT
public:
  explicit RemoteUserApp(const QString& name,
                         RemoteUserService* remoteUserService,
                         QObject* parent = 0);

public slots:
  void open();
  void setup();
  void close();

  QStringList availableIPs();

  bool setRemoteAddress(const QString& remoteAddressString);
  bool setRemotePort(const QString& remotePortString);
  bool setLocalAddress(const QString& localAddressString);
  bool setLocalPort(const QString& localPortString);
};
