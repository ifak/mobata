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

class SutAdapter : public QObject
{
  Q_OBJECT

public:
  explicit SutAdapter(QObject *parent = nullptr);

signals:
  void controlSetuped(bool value, const QString& message);
  void controlStarted(bool value, const QString& message);
  void controlStopped(bool value, const QString& message);
  void controlResetted(bool value, const QString& message);
  void statusResponse(const QStringList& messages);

  void sendMessage(const QString& messageName,
                   const QVariantList& paramValues,
                   const QUuid& messageID);
  void messageReceived(const QString& messageName,
                       const QVariantMap& paramValues = QVariantMap());
  void messageSent(const QUuid& messageID,
                   bool result,
                   const QString& errorString = QStringLiteral(""));

public slots:
  void setupControlSlot(const QVariantMap& setupArgs);
  void startControlSlot();
  void stopControlSlot();
  void resetControlSlot();
  void statusRequestSlot();

  void sendMessageSlot(const QString& messageName,
                       const QVariantList& paramValues,
                       const QUuid& messageID);
  void messageSentSlot(const QUuid& messageID,
                       bool result,
                       const QString& errorString = QStringLiteral(""));
private:
  QSet<QUuid> _openMessages;
};
