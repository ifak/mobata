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

#include "simmodel.hpp"

namespace modsim {

class SimRuntimeController
    : public QObject
{
  Q_OBJECT

public:
  explicit SimRuntimeController(QObject* parent = nullptr);
  virtual ~SimRuntimeController();

public slots://for declaration//
  bool  addSimModel(const QString& simModelText,
                    const QString& simModelAsName,
                    const SimModelType simModelType,
                    QString* errorString);
  bool  addLink(const QString& sourceModelAsName, const QString& sourcePort,
                const QString& targetModelAsName, const QString& targetPort,
                QString* errorString);
  void setStartModelSequence(const QStringList& startModelSequence);

public slots://for running
  void prepare();
  void start();
  void stop();

public slots:
  //for receiving extern messages
  void receiveExternMessageSlot(const QString& modelAsName, const QString& portName,
                            const QString& messageName, const QVariantMap& messageData=QVariantMap());

signals://for intern communication with worker
  void prepareWorker(QPrivateSignal);
  void startWorker(QPrivateSignal);
  void stopWorker(QPrivateSignal);

signals://for extern communication
  void prepared(bool result, const QStringList& messages = QStringList());
  void started(bool result, const QStringList& messages = QStringList());
  void stopped(bool result, const QStringList& messages = QStringList());

  //sending message to extern communication partner
  void sendExternMessage(const QString& modelAsName, const QString& portName,
                         const QString& messageName, const QVariantMap& messageData=QVariantMap());
  //received extern message .. signal is for extern logging purposes...
  void receivedExternMessage(const QString& modelAsName, const QString& portName,
                             const QString& messageName, const QVariantMap& messageData=QVariantMap());
  //observed message between runtime models
  void observedMessage(const QString& sourceModelAsName, const QString& sourcePortName,
                       const QString& targetModelAsName, const QString& targetPortName,
                       const QString& messageName, const QVariantMap& messageData=QVariantMap());

  //error during runtime execution
  void errors(const QStringList& errorMessages);

private slots:
  void preparedWorker(bool result, const QStringList& messages = QStringList());
  void startedWorker(bool result, const QStringList& messages = QStringList());
  void stoppedWorker(bool result, const QStringList& messages = QStringList());

  //receive message from sim model
  void receiveModelMessage(const QString& messageName, const QVariantMap& messageData=QVariantMap());

private:
  Q_DISABLE_COPY(SimRuntimeController)
  class Private;
  Private* _d;
};

} // namespace modsim
