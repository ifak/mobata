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

#include "testcompruntime.hpp"

#include "testcasestep.hpp"

#include <QJSEngine>
#include <QDebug>

using namespace distestruntime;

class TestCompRuntime::Private
{
  friend class TestCompRuntime;

  QJSEngine             _testRuntimeEngine;
  QList<TestCaseStep*>  _testCaseSteps;
  bool                  _testResult;
  QStringList           _errors;
  bool                  _strictBehavior;

  ///during runtime///
  QList<TestCaseStep*>  _runningSteps;

  Private()
    : _testResult(true),
      _strictBehavior(false)
  {}
};

TestCompRuntime::TestCompRuntime(const QString& name,
                                 QObject *parent)
  : QObject(parent),
    prop::NameProperty(name),
    _d(new Private)
{}

TestCompRuntime::~TestCompRuntime()
{
  qDeleteAll(this->_d->_testCaseSteps);
  delete this->_d;
}

QJSEngine* TestCompRuntime::testRuntimeEngine()
{
  return &this->_d->_testRuntimeEngine;
}

void TestCompRuntime::addMessageStep(const QString& signalName,
                                     const QString& portName)
{
  return this->addMessageStep(signalName, portName, QVariantMap());
}

void TestCompRuntime::addMessageStep(const QString& signalName,
                                     const QString& portName,
                                     const QVariantMap& paramValues)
{
  MessageTestCaseStep* messageTestCaseStep=new MessageTestCaseStep(this, signalName,
                                                                   portName, paramValues);
  connect(messageTestCaseStep, &TestCaseStep::stepFinished,
          this, &TestCompRuntime::stepFinished, Qt::UniqueConnection);
  this->_d->_testCaseSteps.append(messageTestCaseStep);

  return;
}

void TestCompRuntime::addCheckStep(const QString& signalName,
                                   const QString& portName,
                                   int timeout)
{
  return this->addCheckStep(signalName, portName, QStringList(), QStringLiteral(""), timeout);
}

void TestCompRuntime::addCheckStep(const QString &signalName,
                                   const QString& portName,
                                   const QStringList &paramNames,
                                   const QString& guard,
                                   int timeout)
{
  CheckTestCaseStep* checkTestCaseStep=new CheckTestCaseStep(this, signalName,
                                                             portName,
                                                             paramNames,
                                                             guard, timeout);
  connect(checkTestCaseStep, &CheckTestCaseStep::stepFinished,
          this, &TestCompRuntime::stepFinished);
  this->_d->_testCaseSteps.append(checkTestCaseStep);

  return;
}

void TestCompRuntime::addStatementStep(const QString &statement)
{
  StatementTestCaseStep* statementTestCaseStep=new StatementTestCaseStep(this, statement);
  connect(statementTestCaseStep, &StatementTestCaseStep::stepFinished,
          this, &TestCompRuntime::stepFinished);
  this->_d->_testCaseSteps.append(statementTestCaseStep);

  return;
}

void TestCompRuntime::addTimeoutStep(int timeout)
{
  TimeoutTestCaseStep* timeoutTestCaseStep=new TimeoutTestCaseStep(this, timeout);
  connect(timeoutTestCaseStep, &TimeoutTestCaseStep::stepFinished,
          this, &TestCompRuntime::stepFinished);
  this->_d->_testCaseSteps.append(timeoutTestCaseStep);

  return;
}

bool TestCompRuntime::prepare(QString* errorMessage)
{
  for(TestCaseStep* testCaseStep : this->_d->_testCaseSteps)
  {
    if(!testCaseStep->prepare(errorMessage))
      return false;
  }

  return true;
}

void TestCompRuntime::start()
{
  if(this->_d->_testCaseSteps.isEmpty())
  {
    emit quit();
    return;
  }

  this->_d->_runningSteps=this->_d->_testCaseSteps;//initialization
  Q_ASSERT(this->_d->_runningSteps.size()==this->_d->_testCaseSteps.size());

  QString errorMessage;
  bool result=this->_d->_runningSteps.first()->execute(&errorMessage);
  if(!result)
  {
    this->_d->_testResult=false;
    this->_d->_errors.append(errorMessage);

    emit quit();
  }

  return;
}

void TestCompRuntime::addErrors(const QStringList& errorMessages)
{
  if(!errorMessages.size())
    return;

  this->_d->_errors.append(errorMessages);

  return;
}

bool TestCompRuntime::testResult() const
{
  return this->_d->_testResult;
}

const QStringList& TestCompRuntime::errors() const
{
  return this->_d->_errors;
}

void TestCompRuntime::messageSent(const QUuid& messageID,
                                  bool result,
                                  const QString& errorMessage)
{
  //  qDebug()<<this->name()<<"-TestCompRuntime::messageSent() executed!";
  //  qDebug()<<"messageID: "<<messageID;
  //  qDebug()<<"result: "<<result;
  //  qDebug()<<"errorMessage: "<<errorMessage;

  Q_ASSERT(this->_d->_runningSteps.size());

  TestCaseStep* currentTestCaseStep = this->_d->_runningSteps.first();
  if(!currentTestCaseStep)
  {
    QString errorMessage = "no active test case step! "
                           "signal 'messageSent' could not be processed!";
    this->_d->_testResult=false;
    this->_d->_errors.append(errorMessage);

    emit quit();
    return;
  }

  if(currentTestCaseStep->testCaseStepType()!=TestCaseStep::MessageStep)
  {
    QString errorMessage = "current test case step is not a message test case step! "
                           "signal 'messageSent' could not be processed!";
    this->_d->_testResult=false;
    this->_d->_errors.append(errorMessage);

    emit quit();
    return;
  }

  MessageTestCaseStep* currMessageStep=static_cast<MessageTestCaseStep*>(currentTestCaseStep);
  Q_ASSERT(currMessageStep);

  currMessageStep->messageSent(messageID, result, errorMessage);

  return;
}

void TestCompRuntime::stepFinished(TestCaseStep* testCaseStep,
                                   bool result,
                                   const QString& message)
{
  //  qDebug()<<this->name()<<"-TestCompRuntime::stepFinished() executed! result: "<<result
  //         <<"message: "<<message;

  Q_ASSERT(this->_d->_runningSteps.size());

  TestCaseStep* currentTestCaseStep = this->_d->_runningSteps.first();
  if(currentTestCaseStep!=testCaseStep)
  {
    QString errorMessage = "error during test case steps execution! "
                           "finished test case step is not current test case step!";
    this->_d->_testResult=false;
    this->_d->_errors.append(errorMessage);

    emit quit();
    return;
  }

  this->_d->_runningSteps.removeFirst();//remove current test case step

  if(!result)
  {
    this->_d->_testResult=false;
    this->_d->_errors.append(message);

    emit quit();
    return;
  }

  if(this->_d->_runningSteps.isEmpty())
  {
    emit quit();//ready
    return;
  }

  QString errorMessage;//next step
  if(!this->_d->_runningSteps.first()->execute(&errorMessage))
  {
    this->_d->_testResult=false;
    this->_d->_errors.append(errorMessage);

    emit quit();
    return;
  }

  return;
}

void TestCompRuntime::messageReceived(const QString& messageName,
                                      const QString& portName,
                                      const QVariantMap& paramValues)
{
  qDebug()<<this->name()<<"-TestCompRuntime::messageReceived() executed! messageName: "<<messageName
         <<"paramValues: "<<paramValues;

  Q_UNUSED(messageName);
  Q_UNUSED(paramValues);

  if(!this->_d->_runningSteps.size())
  {
    if(this->_d->_strictBehavior)
    {
      QString errorMessage(QString("no active test case step! "
                                   "signal 'messageReceived' with messageName: '%1' "
                                   "and portName: '%2' and message-data: '%3' could not be processed!")
                           .arg(messageName).arg(portName).arg(QVariant(paramValues).toString()));
      this->_d->_testResult=false;
      this->_d->_errors.append(errorMessage);
    }

    emit quit();
    return;
  }

  TestCaseStep* currentTestCaseStep = this->_d->_runningSteps.first();
  Q_ASSERT(currentTestCaseStep);

  if(currentTestCaseStep->testCaseStepType()!=TestCaseStep::CheckStep)
  {
    QString errorMessage(QString("current test case step is not a check test case step! "
                                 "signal 'messageReceived' with messageName: '%1' "
                                 "and portName: '%2' and message-data: '%3' could not be processed!")
                         .arg(messageName).arg(portName).arg(QVariant(paramValues).toString()));
    this->_d->_testResult=false;
    this->_d->_errors.append(errorMessage);

    emit quit();
    return;
  }

  CheckTestCaseStep* currCheckStep=static_cast<CheckTestCaseStep*>(currentTestCaseStep);
  Q_ASSERT(currCheckStep);

  currCheckStep->messageReceived(messageName,portName, paramValues);

  return;
}

