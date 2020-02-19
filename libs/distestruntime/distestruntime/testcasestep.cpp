#include "testcasestep.hpp"

#include "testcompruntime.hpp"

#include <mobata/utils/functors.hpp>

#include <QJSEngine>
#include <QTimer>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace distestruntime;

TestCaseStep::TestCaseStep(TestCompRuntime* testCompRuntime,
                           const int timeout)
  : _testCaseRuntime(testCompRuntime),
    _timeout(timeout)
{
  this->_timer = new QTimer(this);
  this->_timer->setSingleShot(true);
  connect(this->_timer, &QTimer::timeout,this,&TestCaseStep::timeoutSlot);
}

TestCaseStep::~TestCaseStep()
{}

QJSEngine* TestCaseStep::testRuntimeEngine()
{
  Q_ASSERT(this->_testCaseRuntime);

  return this->_testCaseRuntime->testRuntimeEngine();
}

bool TestCaseStep::prepare(QString* errorMessage)
{
  Q_UNUSED(errorMessage);

  return true;
}

bool TestCaseStep::execute(QString* errorMessage)
{
  Q_UNUSED(errorMessage);

  emit this->stepFinished(this, true);

  return true;
}

void TestCaseStep::timeoutSlot()
{
  return;
}

//MessageTestCaseStep//////
MessageTestCaseStep::MessageTestCaseStep(TestCompRuntime* testCaseRuntime,
                                         const QString &signalName,
                                         const QString& portName,
                                         const QVariantMap& paramValues,
                                         const int timeout)
  : TestCaseStep(testCaseRuntime, timeout),
    _messageID(QUuid::createUuid()),_signalName(signalName),
    _portName(portName), _paramValues(paramValues)
{}

MessageTestCaseStep::~MessageTestCaseStep()
{}

bool MessageTestCaseStep::execute(QString* errorMessage)
{
  Q_ASSERT(this->_testCaseRuntime);

  if(this->_signalName.isEmpty())
  {
    utils::AddPtrString(errorMessage)<<"no signal name available, message could not be sent!";
    return false;
  }

//  qDebug()<<"MessageTestCaseStep::execute(); send message with signalName: '"<<this->_signalName<<"' "
//         <<"paramValues: '"<<this->_paramValues<<"' messagesID: '"<<this->_messageID<<"'!";
  this->_timer->start(this->_timeout);
  emit this->_testCaseRuntime->sendMessage(this->_signalName, this->_portName,
                                           this->_paramValues, this->_messageID);

  return true;
}

void MessageTestCaseStep::messageSent(const QUuid& messageID, bool result, const QString& errorMessage)
{
//  qDebug()<<"MessageTestCaseStep::messageSent() executed!";

  if(messageID!=this->_messageID)
    return;

//  qDebug()<<"messageID: "<<messageID;
//  qDebug()<<"message name:"<<this->_signalName;
//  qDebug()<<"result: "<<result;
//  qDebug()<<"errorMessage: "<<errorMessage;

  this->_timer->stop();
//  qDebug()<<"timer stopped! timer isActive: "<<this->_timer->isActive();
//  qDebug()<<"remaining time: "<<this->_timer->remainingTime();

  emit this->stepFinished(this, result,errorMessage);

  return;
}

void MessageTestCaseStep::timeoutSlot()
{
//  qDebug()<<QString("MessageTestCaseStep::timeoutSlot() of message '%1' with ID:'%2' executed!")
//            .arg(this->_signalName).arg(this->_messageID.toString());
//  qDebug()<<"timer isActive: "<<this->_timer->isActive();
//  qDebug()<<"remaining time: "<<this->_timer->remainingTime();

  QString errorMessage = tr("timeout occured! message '%1' with ID:'%2' could not be sent!")
                         .arg(this->_signalName).arg(this->_messageID.toString());

  emit this->stepFinished(this, false, errorMessage);

  return;
}

//CheckTestCaseStep////////
CheckTestCaseStep::CheckTestCaseStep(TestCompRuntime* testCaseRuntime,
                                     const QString& signalName,
                                     const QString& portName,
                                     const QStringList& paramNames,
                                     const QString& guard,
                                     const int timeout)
  : TestCaseStep(testCaseRuntime, timeout),
    _signalName(signalName), _portName(portName),
    _paramNames(paramNames), _guard(guard)
{}

CheckTestCaseStep::~CheckTestCaseStep()
{}

bool CheckTestCaseStep::execute(QString* errorMessage)
{
  Q_UNUSED(errorMessage);

//  qDebug()<<"check test case step with signal '"<<this->_signalName
//         <<"' params '"<<this->_paramNames
//        <<"' and guard '"<<this->_guard<<"' started!";

  this->_timer->start(this->_timeout);

  return true;
}

bool CheckTestCaseStep::prepare(QString* errorMessage)
{
  Q_ASSERT(this->_testCaseRuntime);

  if(this->_guard.trimmed().isEmpty())
    return true;

  QJSEngine* testRuntimeEngine = this->testRuntimeEngine();
  Q_ASSERT(testRuntimeEngine);

  QString jsGuardFuncCode = "(function(";
  int pos=0;
  for(const QString& paramName : this->_paramNames)
  {
    if(pos)
      jsGuardFuncCode+=",";
    jsGuardFuncCode+=paramName;
    ++pos;
  }
  jsGuardFuncCode+=" ) { return (";
  jsGuardFuncCode+=this->_guard;
  jsGuardFuncCode+="); })";

//  qDebug()<<"check test case step: js guard function: "<<jsGuardFuncCode;

  this->_guardFunction = testRuntimeEngine->evaluate(jsGuardFuncCode);
  if(this->_guardFunction.isError())
  {
    utils::AddPtrString(errorMessage)<<"error within guard function '"
                                    <<jsGuardFuncCode<<"' "
                                   <<"line number: "<<this->_guardFunction.property("lineNumber").toInt()
                                  <<" error message: "<<this->_guardFunction.toString();
    return false;
  }

  if(!this->_guardFunction.isCallable())
  {
    utils::AddPtrString(errorMessage)<<"guard function is not callable: '"
                                    <<jsGuardFuncCode<<"'";
    return false;
  }

  return true;
}

void CheckTestCaseStep::messageReceived(const QString& messageName,
                                        const QString& portName,
                                        const QVariantMap& paramValues)
{
//  qDebug()<<"CheckTestCaseStep::messageReceived() executed! messageName: "<<messageName
//         <<"portName: "<<portName
//         <<"paramValues: "<<paramValues;

  this->_timer->stop();

  QString errorMessage;
  if(messageName!=this->_signalName)
  {
    errorMessage = tr("message name '%1' is not the expected signal name '%2'")
                   .arg(messageName).arg(this->_signalName);
    emit this->stepFinished(this, false,errorMessage);
    return;
  }

  if(portName!=this->_portName)
  {
    errorMessage = tr("port name '%1' of message with signal name '%2' is not expected!")
                   .arg(portName).arg(this->_signalName);
    emit this->stepFinished(this, false,errorMessage);
    return;
  }

  bool result=true;
  if(!this->_guard.trimmed().isEmpty())
    result = this->evaluateGuard(paramValues, &errorMessage);

  emit this->stepFinished(this, result, errorMessage);

  return;
}

void CheckTestCaseStep::timeoutSlot()
{
  QString errorMessage = tr("timeout occured! no message with signal name '%1' received!").arg(this->_signalName);
  emit this->stepFinished(this, false, errorMessage);

  return;
}

bool CheckTestCaseStep::evaluateGuard(const QVariantMap& paramValues, QString* errorString)
{
//  qDebug()<<"CheckTestCaseStep::evaluateGuard() executed!";

  if(this->_guard.isEmpty())
    return true;

  if(this->_paramNames.size()!=paramValues.size())
  {
    utils::AddPtrString(errorString)<<"error during evaluation of guard '"<<this->_guard<<"' "
                                   <<"param values are not suitable for this guard!";
    return false;
  }

  QJSValueList args;
  for(const QString& paramName : this->_paramNames)
  {
    QVariantMap::const_iterator find_it=paramValues.constFind(paramName);
    if(find_it==paramValues.cend())
    {
      utils::AddPtrString(errorString)<<"value of param '"<<paramName<<"' could not be found "
                                     <<"within param values!";
      return false;
    }
    args<<this->testRuntimeEngine()->toScriptValue(find_it.value());
  }

  QJSValue result = this->_guardFunction.call(args);
  if(result.isError())
  {
    utils::AddPtrString(errorString)<<"error during evaluation of guard '"<<this->_guard<<"' "
                                   <<"line number: "<<result.property("lineNumber").toInt()
                                  <<" error message: "<<result.toString();
    return false;
  }

  if(!result.isBool())
  {
    utils::AddPtrString(errorString)<<"result of evaluation of guard '"<<this->_guard
                                   <<"' is not a boolean value!";
    return false;
  }

  bool evalResult = result.toBool();
  if(!evalResult)
  {
    QString paramValuesString; int pos=0;
    for(QVariantMap::ConstIterator pv_it = paramValues.cbegin(); pv_it!=paramValues.cend(); ++pv_it)
    {
      if(pos)
        paramValuesString+=", ";
      ++pos;

      paramValuesString+=pv_it.key();
      paramValuesString+=QStringLiteral("=");
      paramValuesString+=pv_it.value().toString();
    }

    utils::AddPtrString(errorString)<<"result of evaluation of guard '"<<this->_guard
                                   <<"' with param-values '"<<paramValuesString
                                   <<"' is FALSE!";
  }

  return evalResult;
}

//StatementTestCaseStep
StatementTestCaseStep::StatementTestCaseStep(TestCompRuntime* testCaseRuntime,
                                             const QString &statement)
  : TestCaseStep(testCaseRuntime),
    _statement(statement)
{}

StatementTestCaseStep::~StatementTestCaseStep()
{}

//TimeoutTestCaseStep
TimeoutTestCaseStep::TimeoutTestCaseStep(TestCompRuntime* testCaseRuntime,
                                         const int timeout)
  : TestCaseStep(testCaseRuntime, timeout)
{}

TimeoutTestCaseStep::~TimeoutTestCaseStep()
{}

bool TimeoutTestCaseStep::execute(QString* errorMessage)
{
  Q_UNUSED(errorMessage);

  this->_timer->start(this->_timeout);

//  qDebug()<<QString("TimeoutTestCaseStep::execute() executed!");
//  qDebug()<<"timer isActive: "<<this->_timer->isActive();
//  qDebug()<<"remaining time: "<<this->_timer->remainingTime();

  return true;
}

void TimeoutTestCaseStep::timeoutSlot()
{
//  qDebug()<<QString("TimeoutTestCaseStep::timeoutSlot() executed!");
//  qDebug()<<"timer isActive: "<<this->_timer->isActive();
//  qDebug()<<"remaining time: "<<this->_timer->remainingTime();

  emit this->stepFinished(this, true);

  return;
}
