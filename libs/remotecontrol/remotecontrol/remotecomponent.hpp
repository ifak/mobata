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
#include <QHostAddress>
#include <mobata/prop/nameproperty.hpp>

#include "remoteconnectionmanager.hpp"

namespace remotecontrol {

class RemoteComponent
    : public QObject,
    public prop::NameProperty
{
  Q_OBJECT
protected:
  explicit RemoteComponent(const QString& name,
                           QObject *parent = 0,
                           QHostAddress address = QHostAddress::LocalHost,
                           quint16 port = 10000);
  virtual ~RemoteComponent();

protected:
  RemoteConnectionManager*        remoteConnectionManager();
  RemoteConnectionManager const*  remoteConnectionManager() const;

signals:
  void error(const QString& errorMessage);
  void messageSent(const QUuid& messageID,
                   bool result,
                   const QString& errorString = QStringLiteral(""));

  void message(const QString& message);

public slots:
  void sendMessageSlot(const QString& messageName,
                       const QVariantList& paramValues,
                       const QUuid& messageID);

private:
  Q_DISABLE_COPY(RemoteComponent)
  class Private;
  Private*  _d;
};

} // namespace remotecontrol
