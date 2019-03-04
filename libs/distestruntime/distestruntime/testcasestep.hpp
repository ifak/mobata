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

#include <QUuid>
#include <QString>
#include <QVariantList>
#include <QJSValue>

class QJSEngine;
class QTimer;

namespace distestruntime{

class TestCompRuntime;

class DISTESTRUNTIMESHARED_EXPORT TestCaseStep : public QObject
{
  Q_OBJECT

public:
  enum TestCaseStepType
  {
    MessageStep,
    CheckStep,
    StatementStep,
    TimeoutStep,
    OtherStep
  };

public:
  explicit TestCaseStep(TestCompRuntime* testCompRuntime,
                        const int timeout=0);
  virtual ~TestCaseStep();

signals:
  void stepFinished(TestCaseStep* testCaseStep,
                    bool result,
                    const QString& message=QStringLiteral(""));

public:
  virtual int   testCaseStepType() const = 0;

protected:
  QJSEngine* testRuntimeEngine();

protected slots:
  virtual void timeoutSlot();

public:
  virtual bool  prepare(QString* errorMessage);
  virtual bool  execute(QString* errorMessage);

protected:
  TestCompRuntime*  _testCaseRuntime;
  QTimer*           _timer;
  int               _timeout;
};

class DISTESTRUNTIMESHARED_EXPORT MessageTestCaseStep
    : public TestCaseStep
{
  Q_OBJECT

public:
  explicit MessageTestCaseStep(TestCompRuntime* testCaseRuntime,
                               const QString& signalName,
                               const QString& portName,
                               const QVariantMap& paramValues,
                               const int timeout = 3000);
  virtual ~MessageTestCaseStep();

public:
  virtual int testCaseStepType() const override { return MessageStep;}

public:
  bool  execute(QString* errorMessage) override;
  void messageSent(const QUuid& messageID,
                   bool result,
                   const QString& errorMessage=QStringLiteral(""));

protected slots:
  void timeoutSlot() override;

protected:
  QUuid       _messageID;
  QString     _signalName;
  QString     _portName;
  QVariantMap _paramValues;
};

class DISTESTRUNTIMESHARED_EXPORT CheckTestCaseStep
    : public TestCaseStep
{
  Q_OBJECT

public:
  explicit CheckTestCaseStep(TestCompRuntime* testCaseRuntime,
                             const QString& signalName,
                             const QString& portName,
                             const QStringList& paramNames,
                             const QString& guard,
                             const int timeout = 3000);
  virtual ~CheckTestCaseStep();

public:
  virtual int testCaseStepType() const override { return CheckStep;}

public:
  bool execute(QString* errorMessage) override;
  bool  prepare(QString* errorMessage) override;

public:
  void messageReceived(const QString& messageName,
                       const QString& portName,
                       const QVariantMap& paramValues);

protected slots:
  void timeoutSlot() override;

private:
  bool evaluateGuard(const QVariantMap& paramValues, QString* errorString);

protected:
  QString     _signalName;
  QString     _portName;
  QStringList _paramNames;
  QString     _guard;
  QJSValue    _guardFunction;
};

class DISTESTRUNTIMESHARED_EXPORT StatementTestCaseStep
    : public TestCaseStep
{
public:
  explicit StatementTestCaseStep(TestCompRuntime* testCaseRuntime,
                                 const QString& statement);
  virtual ~StatementTestCaseStep();

public:
  virtual int testCaseStepType() const { return StatementStep;}

protected:
  QString _statement;
};

class DISTESTRUNTIMESHARED_EXPORT TimeoutTestCaseStep
    : public TestCaseStep
{
  Q_OBJECT

public:
  explicit TimeoutTestCaseStep(TestCompRuntime* testCaseRuntime,
                               const int timeout);
  virtual ~TimeoutTestCaseStep();

public:
  virtual int testCaseStepType() const override { return TimeoutStep;}

public:
  bool execute(QString* errorMessage) override;

protected slots:
  void timeoutSlot() override;
};

}//namespace distestruntime
