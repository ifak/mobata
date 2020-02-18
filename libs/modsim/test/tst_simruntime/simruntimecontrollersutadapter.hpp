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
#include <QSet>
#include <QVariantMap>
#include <QUuid>

class SimRuntimeControllerSutAdapter : public QObject
{
  Q_OBJECT

public:
  explicit SimRuntimeControllerSutAdapter(QObject *parent = nullptr);

signals:
  void messageReceived(const QString& messageName,
                       const QString& portName,
                       const QVariantMap& paramValues = QVariantMap());
  void errors(const QStringList& errorMessages);
  void messageSent(const QUuid &messageID,
                   bool result,
                   const QString& errorMessage=QStringLiteral(""));

  //to controller
  void prepareController();
  void startController();
  void stopController();
  void sendMessage(const QString& modelAsName,
                   const QString& messageName,
                   const QString& portName,
                   const QVariantMap& paramValues = QVariantMap());

public slots:
  void controllerPreparedSlot(bool result, const QStringList& messages = QStringList());
  void controllerStartedSlot(bool result, const QStringList& messages = QStringList());
  void controllerStoppedSlot(bool result, const QStringList& messages = QStringList());
  void receiveRuntimeMessageSlot(const QString& modelAsName,
                                 const QString& portName,
                                 const QString& messageName,
                                 const QVariantMap& paramValues = QVariantMap());
  void observedRuntimeMessageSlot(const QString& sourceModelAsName,
                                  const QString& sourcePortName,
                                  const QString& targetModelAsName,
                                  const QString& targetPortName,
                                  const QString& messageName,
                                  const QVariantMap& paramValues = QVariantMap());

  void sendMessageSlot(const QString& messageName,
                       const QString& portName,
                       const QVariantMap& paramValues,
                       const QUuid& messageID);
private:
  QSet<QUuid> _openMessages;
};
