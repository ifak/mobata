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

#include <QObject>
#include <QUuid>
#include <QAbstractSocket>

#include <QHostAddress>

class QJsonRpcSocket;

namespace remotecontrol {

class REMOTECONTROLSHARED_EXPORT RemoteConnectionManager
    : public QObject
{
  Q_OBJECT

public:
  RemoteConnectionManager(QObject* parent = nullptr);
  RemoteConnectionManager(const QString& remoteServiceProvider,
                          QObject* parent = nullptr);
  RemoteConnectionManager(const QString& remoteServiceProvider,
                          const QHostAddress& remoteAddress = QHostAddress::LocalHost,
                          quint16 remotePort = 10000,

                          QObject* parent = nullptr);
  virtual ~RemoteConnectionManager();

public:
  void startConnection();
  bool isConnected() const;

signals:
  void connectionError(const QString& errorMessage);
  void messageSent(const QUuid& messageID, bool result, const QString& errorString = QStringLiteral(""));

public:
  void                setRemoteAddress(const QHostAddress& remoteAddress);
  void                setRemotePort(quint16 remotePort);
  void                setRemoteServiceProvider(const QString& remoteServiceProvider);

  const QHostAddress& remoteAddress() const;
  quint16             remotePort() const;
  const QString&      remoteServiceProvider() const;
  QJsonRpcSocket*     jsonRpcSocket();
  void                sendMessage(const QString& messageName,
                                  const QUuid& messageID=QUuid::createUuid());
  void                sendMessage(const QString& messageName,
                                  const QVariantList& messageParams,
                                  const QUuid& messageID=QUuid::createUuid());

private slots:
  void connectedSlot();
  void replyFinishedSlot();
  void errorSlot(QAbstractSocket::SocketError socketError);

private:
  Q_DISABLE_COPY(RemoteConnectionManager)
  class Private;
  Private* _d;
};

} // namespace remotecontrol
