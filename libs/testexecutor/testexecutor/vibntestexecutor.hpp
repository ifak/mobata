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

#include "testexecutor_global.h"

#include <QObject>

#include "testexecutormodel.hpp"
#include "testexecutortestcase.hpp"
#include "vibntestadapter.hpp"
#include "vibnfakeadapter.hpp"

#include "mobata/model/ts/testsuite.hpp"
#include "mobata/model/msc/msc.hpp"

namespace testexecutor {

class TESTEXECUTORSHARED_EXPORT VibnTestExecutor : public QObject
{
  Q_OBJECT
public:
  VibnTestExecutor(TestexecutorModel* testSuiteModel, const QString& ip = "127.0.0.1", int port = 1883, const QString& modus = "opcua");

  bool setup();
  bool setupFake(QList<QPair<QString, QVariant>> list);

  bool start();

  bool result();

  void receivedSignal(const QString& signalName, const QList<QVariant>& values);

  bool finishedState();

private:
  void startTestcase(int index);
  void startStep(int index);

  bool sendMySignal(const model::msc::MscMessageItem* step, QString *errorString);
  bool checkAdapter();

public slots:
  void sendSignalResult(bool result);
  void stop();

private slots:
  void finishedTestcase(bool result, QString message);

signals:
  void stopAllTimers();
  void sendSignal(const QString& signalName, const QList<QVariant>& value);
  void sendSignalDone();

  void requestValue(const QString& signalName, const QVariant& expectedValue, int timeout = 0, int pollingrate = 0, double accuracy = 0);

  void setuped(bool result,
               const QString& message);
  void started(bool result,
               const QString& message);
  void stopped(bool result,
               const QString& message);
  void finished(bool result,
                const QString& message);
  void runTimeMessage(bool result,
                      const QString& message);

private:
  Q_DISABLE_COPY(VibnTestExecutor)
  class Private;
  Private* _d;
public:
  bool _autoCheckAfterWrite = true;
  bool _randomReceiveOrder = true;
};
}
