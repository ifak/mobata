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

#include "distestruntime_global.hpp"

#include <QObject>
#include <mobata/prop/nameproperty.hpp>

class QJSEngine;

namespace distestruntime{

class TestCaseStep;

class DISTESTRUNTIMESHARED_EXPORT TestCompRuntime
    : public QObject,
    public prop::NameProperty
{
  Q_OBJECT

  friend class TestCaseStep;

public:
  explicit TestCompRuntime(const QString& name,
                           QObject* parent = 0);
  virtual ~TestCompRuntime();

private:
  QJSEngine* testRuntimeEngine();

signals:
  void sendMessage(const QString& messageName,
                   const QString& portName,
                   const QVariantMap& paramValues,
                   const QUuid& messageID);
  void quit();

public:
  void  addMessageStep(const QString& signalName,
                       const QString& portName);
  void  addMessageStep(const QString& signalName,
                       const QString& portName,
                       const QVariantMap& paramValues);
  void  addCheckStep(const QString& signalName,
                     const QString& portName,
                     int timeout=5000);
  void  addCheckStep(const QString& signalName,
                     const QString& portName,
                     const QStringList& paramNames,
                     const QString& guard,
                     int timeout=5000);
  void  addStatementStep(const QString& statement);
  void  addTimeoutStep(int timeout);

  bool  prepare(QString* errorMessage);

public slots:
  void  start();
  void  addErrors(const QStringList& errorMessages);
  void  messageSent(const QUuid& messageID,
                    bool result,
                    const QString& errorMessage = QStringLiteral(""));
  void messageReceived(const QString& messageName,
                       const QString& portName,
                       const QVariantMap& paramValues);

public:
  bool                testResult() const;
  const QStringList&  errors() const;

private slots:
  void stepFinished(TestCaseStep* testCaseStep, bool result, const QString& message);

private:
  Q_DISABLE_COPY(TestCompRuntime)
  class Private;
  Private* _d;
};

}// namespace distestruntime
