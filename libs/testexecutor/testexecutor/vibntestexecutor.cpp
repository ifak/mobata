#include "vibntestexecutor.hpp"

#include <QFuture>
#include <QtConcurrent>
#include <QVariant>

namespace testexecutor {

class VibnTestExecutor::Private
{
  friend class VibnTestExecutor;

  TestexecutorModel* _testSuiteModel;
  QString _mappingFile;
  VibnAdapter* _adapter = nullptr;
  QString _modus = "opcua";

  TestexecutorTestCase* _currentTestcase = nullptr;

  bool _result = true;
  bool _finished = false;

  QString _errorString = "";

  QList<const model::msc::MscMessageItem*> _expectedSteps;
  QList<const model::msc::MscMessageItem*> _stepsToSend;
  int _currentTestcaseIndex = 0;
  int _totalTestCases = 0;
  int _currentStepIndex = 0;

  bool _lastSendReturn;

  QString _ip = "127.0.0.1";
  int _port = 1883;

  bool _stopped = false;

};

VibnTestExecutor::VibnTestExecutor(TestexecutorModel *testSuiteModel,
                                   const QString &ip, int port, const QString &modus)
  : _d(new Private)
{
  this->_d->_testSuiteModel = testSuiteModel;
  this->_d->_ip = ip;
  this->_d->_port = port;
  this->_d->_modus = modus;
}

bool VibnTestExecutor::finishedState()
{
  return this->_d->_finished;
}

void VibnTestExecutor::stop()
{
  this->_d->_stopped = true;
  this->_d->_finished=true;
  this->stopAllTimers();
  emit finished(false, this->_d->_errorString);
}

bool VibnTestExecutor::setup()
{
  qDebug()<<"VibnTestExecutor::setup()";
  //todo
  //start vibn adapter.exe

  this->_d->_errorString = "";
  if(this->_d->_adapter){
    delete  this->_d->_adapter;
  }
  this->_d->_adapter = new VibnTestAdapter(this->_d->_ip, this->_d->_port, this->_d->_modus);

  if(!this->_d->_adapter->isInit()){
    return false;
  }

  const VibnTestAdapter* adapter = dynamic_cast<const VibnTestAdapter*>(this->_d->_adapter);

  QObject::connect(adapter, &VibnAdapter::signalReceived,
                   this, &VibnTestExecutor::receivedSignal);
  QObject::connect(adapter, &VibnAdapter::sendSignalDone,
                   this, &VibnTestExecutor::sendSignalResult);
  QObject::connect(this, &VibnTestExecutor::sendSignal,
                   adapter, &VibnAdapter::sendSignal);
  QObject::connect(this, &VibnTestExecutor::requestValue,
                   adapter, &VibnAdapter::sendReadValue);
  QObject::connect(this, &VibnTestExecutor::destroyed,
                   adapter, &VibnAdapter::deleteLater);

  return true;
}

bool VibnTestExecutor::setupFake(QList<QPair<QString, QVariant> > list)
{
  qDebug()<<"VibnTestExecutor::setupFake()";

  this->_d->_errorString = "";
  if(this->_d->_adapter){
    delete  this->_d->_adapter;
  }
  this->_d->_adapter = new VibnFakeAdapter();

  if(!this->_d->_adapter->isInit()){
    return false;
  }

  VibnFakeAdapter* adapter = dynamic_cast<VibnFakeAdapter*>(this->_d->_adapter);

  adapter->setAnswerList(list);

  QObject::connect(adapter, &VibnAdapter::signalReceived,
                   this, &VibnTestExecutor::receivedSignal);
  QObject::connect(adapter, &VibnAdapter::sendSignalDone,
                   this, &VibnTestExecutor::sendSignalResult);
  QObject::connect(this, &VibnTestExecutor::sendSignal,
                   adapter, &VibnAdapter::sendSignal);
  QObject::connect(this, &VibnTestExecutor::requestValue,
                   adapter, &VibnAdapter::sendReadValue);
  QObject::connect(this, &VibnTestExecutor::destroyed,
                   adapter, &VibnAdapter::deleteLater);

  return true;
}

bool VibnTestExecutor::start()
{
  qDebug()<<"VibnTestExecutor::start()";
  this->_d->_stopped = false;
  this->_d->_currentTestcaseIndex = 0;
  this->_d->_totalTestCases = this->_d->_testSuiteModel->testSuite()->testCases().size();

  this->startTestcase(this->_d->_currentTestcaseIndex);

  return true;
}

void VibnTestExecutor::startTestcase(int index)
{
  qDebug()<<"VibnTestExecutor::startTestcase()";
  if(index >= this->_d->_testSuiteModel->testSuite()->testCases().length()){
    emit this->finished(false, "No Testcases in this Testsuite");
    this->_d->_finished=true;
    return;
  }
  this->_d->_currentTestcase = dynamic_cast<TestexecutorTestCase*>(this->_d->_testSuiteModel->testSuite()->testCases().at(index));
  if(this->_d->_currentTestcase == nullptr){
    this->finishedTestcase(false, "cast to TestexecutorTestCase failed\n");
    return;
  }
  if(!this->_d->_currentTestcase->isEnabled()){
    this->finishedTestcase(true, "");
    return;
  }

  if(this->_d->_stopped){
    this->finishedTestcase(false, "stopped by user");
    return;
  }

  bool ok = this->checkAdapter();
  if(!ok){
    this->_d->_currentTestcase->setResult(TestexecutorTestCase::NOT_EXECUTED);
    this->finishedTestcase(false, "Adapter error, no response\n");
    return;
  }

  qDebug()<<"Start Testcase:"<<this->_d->_currentTestcase->name();
  QString counterString = QStringLiteral(" [") + QString::number(this->_d->_currentTestcaseIndex + 1)
      + QStringLiteral("/") + QString::number(this->_d->_totalTestCases)
      + QStringLiteral("]");
  emit this->runTimeMessage(true, "Starting Testcase: " + this->_d->_currentTestcase->name() + counterString);
  this->_d->_currentStepIndex = 0;
  startStep(this->_d->_currentStepIndex);
}

void VibnTestExecutor::startStep(int index)
{
  if(this->_d->_currentTestcase == nullptr){
    return;
  }

  if(this->_d->_stopped){
    this->finishedTestcase(false, "stopped by user");
    return;
  }

  if(this->_d->_currentTestcase->sequenceItems().length() <= index){
    finishedTestcase(true,"");
    return;
  }

  qDebug()<<"VibnTestExecutor::startStep()"<<index+1<<"from"<<this->_d->_currentTestcase->sequenceItems().length();

  this->_d->_stepsToSend.clear();
  this->_d->_expectedSteps.clear();
  int currentType = 0;

  for(int i = index ; i< this->_d->_currentTestcase->sequenceItems().length() ; i++){
    const model::msc::MscSequenceItem* currentItem = this->_d->_currentTestcase->sequenceItems().at(i);
    const model::msc::MscMessageItem* message = dynamic_cast<const model::msc::MscMessageItem*>(currentItem);
    const model::msc::MscCheckMessageItem* check = dynamic_cast<const model::msc::MscCheckMessageItem*>(currentItem);
    if(message == nullptr){
      const model::msc::MscTimerItem* timerItem = dynamic_cast<const model::msc::MscTimerItem*>(currentItem);
      if(!timerItem){
        continue;
      }
      if(this->_d->_currentStepIndex == i){
        TestexecutorTestCase* curTC = this->_d->_currentTestcase;
        QTimer timer;
        timer.setSingleShot(true);
        timer.setInterval(static_cast<int>(timerItem->value()*1000));
        timer.setTimerType(Qt::PreciseTimer);
        QEventLoop loop;
        QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
        QObject::connect(this, &VibnTestExecutor::stopAllTimers, &loop, &QEventLoop::quit);

        emit this->runTimeMessage(true, QStringLiteral("  Timer started with ") + QString::number(static_cast<int>(timerItem->value()*1000)) + QStringLiteral("ms"));
        qDebug()<<QStringLiteral("Timer started with ") + QString::number(static_cast<int>(timerItem->value()*1000)) + QStringLiteral("ms");

        timer.start();
        loop.exec();
        if(this->_d->_currentTestcase != curTC){
          return;
        }
        break;
      }else{
        this->_d->_currentStepIndex = i-1;
        break;
      }
    }else{
      const model::msc::MscComponentItem* comp = message->component();
      if(!comp){
        continue;
      }

      if(check == nullptr && currentType >= 0){
        currentType = 1;
        const model::base::SignalItem* sig = message->signal();
        if(!sig){
          continue;
        }
        this->_d->_stepsToSend.append(message);
        this->_d->_currentStepIndex = i;
      }else if(check != nullptr && currentType <= 0){
        currentType = -1;
        const model::base::SignalItem* sig = check->signal();
        if(!sig){
          continue;
        }
        if(check->paramValues().isEmpty()){
          continue;
        }
        this->_d->_expectedSteps.append(check);
        this->_d->_currentStepIndex = i;
      }else{
        this->_d->_currentStepIndex = i-1;
        break;
      }
    }
  }

  qDebug()<<"Send Signals:"<<this->_d->_stepsToSend.length();
  qDebug()<<"Expected Signals:"<<this->_d->_expectedSteps.length();

  for(const model::msc::MscMessageItem* sendMessage : this->_d->_stepsToSend){
    if(sendMessage == nullptr){
      continue;
    }
    if(this->_d->_currentTestcase == nullptr){
      return;
    }
    QString sendError;
    bool ok = this->sendMySignal(sendMessage, &sendError);
    if(!ok){
      qDebug()<<"VibnTestExecutor::startStep()"<<"Signal could not be send " + sendMessage->signal()->name() + " -> " + sendError;
      this->finishedTestcase(false, "Signal could not be send " + sendMessage->signal()->name() + " -> " + sendError + "\n");
      return;
    }
  }

  for(const model::msc::MscMessageItem* itm : this->_d->_expectedSteps){
    if(this->_d->_stepsToSend.contains(itm)){

    }else{
      const model::msc::MscCheckMessageItem* checkItm = dynamic_cast<const model::msc::MscCheckMessageItem*>(itm);
      if(checkItm == nullptr){
        continue;
      }
      emit this->requestValue(itm->signal()->name(), itm->paramValues().first()->value(),
                              checkItm->timeout(),
                              this->_d->_testSuiteModel->_interval_length,
                              checkItm->accuracy());
    }
  }

  this->_d->_stepsToSend.clear();
  if(this->_d->_expectedSteps.isEmpty()){
    this->_d->_currentStepIndex++;
    this->startStep(this->_d->_currentStepIndex);
  }
}

void VibnTestExecutor::finishedTestcase(bool result, QString message)
{
  qDebug()<<"VibnTestExecutor::finishedTestcase()";
  if(this->_d->_finished){
    return;
  }
  QString resu = QStringLiteral("");
  if(!result){
    resu = QStringLiteral(" (Failed)");
    this->_d->_currentTestcase->setResult(TestexecutorTestCase::FAIL);
    this->_d->_currentTestcase->setErrorMessage(message);
    this->_d->_result = result;
    //this->_d->_errorString += message;
  }else{
    if(this->_d->_currentTestcase->isEnabled()){
      resu = QStringLiteral(" (Success)");
      this->_d->_currentTestcase->setResult(TestexecutorTestCase::SUCCESS);
    }else{
      resu = QStringLiteral(" (Excluded)");
      this->_d->_currentTestcase->setResult(TestexecutorTestCase::EXCLUDE);
    }
  }

  emit this->runTimeMessage(true, QStringLiteral("Finished Testcase: ") + this->_d->_currentTestcase->name() + resu);

  this->_d->_currentTestcaseIndex++;
  if(this->_d->_currentTestcaseIndex >= this->_d->_testSuiteModel->testSuite()->testCases().length()){
    this->_d->_currentTestcase = nullptr;
    emit finished(this->_d->_result, this->_d->_errorString);
    this->_d->_finished=true;
    qDebug()<<"VibnTestExecutor::finished() emited";
  }else{

    TestexecutorTestCase::Result res = this->_d->_currentTestcase->testResult();
    this->_d->_currentTestcase = nullptr;
    this->stopAllTimers();

    if(!this->_d->_stopped && res != TestexecutorTestCase::EXCLUDE){
      QTimer timer;
      timer.setSingleShot(true);
      timer.setInterval(5000);
      QEventLoop loop;
      QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
      QObject::connect(this, &VibnTestExecutor::stopAllTimers, &loop, &QEventLoop::quit);
      timer.start();
      loop.exec();
    }
    startTestcase(this->_d->_currentTestcaseIndex);
  }
}

bool VibnTestExecutor::result()
{
  return this->_d->_result;
}

void VibnTestExecutor::receivedSignal(const QString& signalName, const QList<QVariant>& values)
{
  //! errors:
  //received not expected signal
  //received signal with not expected params
  //received signal with wrong param count

  if(this->_d->_currentTestcase == nullptr){
    return;
  }

  qDebug()<<"VibnTestExecutor::receivedSignal()"<<signalName<<values;

  QString mes = "";
  if(values.length() >= 1){
    mes = values.at(0).toString();
  }

  emit this->runTimeMessage(true, QStringLiteral("  Message received: ") + signalName + QStringLiteral(" [ ") + mes + QStringLiteral(" ]"));

  if(this->_d->_stopped){
    this->finishedTestcase(false, "stopped by user");
    return;
  }
  if(!this->_randomReceiveOrder){
    if(this->_d->_expectedSteps.isEmpty()){
      QString error = "Error: " + signalName +
          QStringLiteral(" actual ( ") +
          QStringLiteral("received signal") +
          QStringLiteral(" ) , expected ( ") +
          QStringLiteral("no signal") +
          QStringLiteral(" )");

      qDebug()<<error;
      emit this->runTimeMessage(false, QStringLiteral("  ") + error);
      this->finishedTestcase(false, error + QStringLiteral("\n"));
      return;
    }else if(this->_d->_expectedSteps.first()->signal()->name() == signalName){
      if(this->_d->_expectedSteps.first()->paramValues().length() != values.length()){
        QString error = "Error: " + signalName +
            QStringLiteral(" actual ( ") +
            QString::number(values.length()) +
            QStringLiteral(" ) , expected ( ") +
            QString::number(this->_d->_expectedSteps.first()->paramValues().count()) +
            QStringLiteral(" ) parameter count");

        qDebug()<<error;
        emit this->runTimeMessage(false, QStringLiteral("  ") + error);
        this->finishedTestcase(false, error + QStringLiteral("\n"));
        return;
      }
      for(const model::base::ParamValueItem* item : this->_d->_expectedSteps.first()->paramValues()){
        qDebug()<<"Compare expected"<<item->value()<<"with"<<values.at(this->_d->_expectedSteps.first()->paramValues().indexOf(item));
        if(this->_d->_expectedSteps.first()->paramValues().indexOf(item))
        if(
           !
           (item->value() == values.at(this->_d->_expectedSteps.first()->paramValues().indexOf(item)))
           &&
           (item->value() == values.at(this->_d->_expectedSteps.first()->paramValues().indexOf(item)))
           )
        {
          QString error = "Error: " + signalName +
              QStringLiteral(" actual ( ") +
              values.at(this->_d->_expectedSteps.first()->paramValues().indexOf(item)).toString() +
              QStringLiteral(" ) , expected ( ") +
              item->value().toString() +
              QStringLiteral(" )");

          qDebug()<<error;
          emit this->runTimeMessage(false, QStringLiteral("  ") + error);
          this->finishedTestcase(false, error + QStringLiteral("\n"));
          return;
        }
      }
      this->_d->_expectedSteps.removeAt(0);
      if(this->_d->_expectedSteps.isEmpty()){
        qDebug()<<"Go to next Step"<<"New Index"<<this->_d->_currentStepIndex+1;
        this->_d->_currentStepIndex++;
        this->startStep(this->_d->_currentStepIndex);
      }
      return;
    }else{
      QString error = "Error: " + signalName +
          QStringLiteral(" actual ( ") +
          QStringLiteral("received signal") +
          QStringLiteral(" ) , expected ( ") +
          this->_d->_expectedSteps.first()->signal()->name() +
          QStringLiteral(" )");

      qDebug()<<error;
      emit this->runTimeMessage(false, QStringLiteral("  ") + error);
      this->finishedTestcase(false, error + QStringLiteral("\n"));
      return;
    }
  }else{
    bool found = false;
    for(const model::msc::MscMessageItem* msg : this->_d->_expectedSteps){
      if(msg->signal()->name() == signalName){
        if(this->_d->_expectedSteps.first()->paramValues().length() != values.length()){
          QString error = "Error: " + signalName +
              QStringLiteral(" actual ( ") +
              QString::number(values.length()) +
              QStringLiteral(" ) , expected ( ") +
              QString::number(this->_d->_expectedSteps.first()->paramValues().count()) +
              QStringLiteral(" ) parameter count");

          qDebug()<<error;
          emit this->runTimeMessage(false, QStringLiteral("  ") + error);
          this->finishedTestcase(false, error + QStringLiteral("\n"));
          return;
        }
        for(const model::base::ParamValueItem* item : this->_d->_expectedSteps.first()->paramValues()){
          qDebug()<<"Compare expected"<<item->value()<<"with"<<values.at(this->_d->_expectedSteps.first()->paramValues().indexOf(item));
          if(!(item->value() == values.at(this->_d->_expectedSteps.first()->paramValues().indexOf(item)))){
            QString error = "Error: " + signalName +
                QStringLiteral(" actual ( ") +
                values.at(msg->paramValues().indexOf(item)).toString() +
                QStringLiteral(" ) , expected ( ") +
                item->value().toString() +
                QStringLiteral(" )");

            qDebug()<<error;
            emit this->runTimeMessage(false, QStringLiteral("  ") + error);
            this->finishedTestcase(false, error + QStringLiteral("\n"));
            return;
          }
        }
        this->_d->_expectedSteps.removeAt(0);
        if(this->_d->_expectedSteps.isEmpty()){
          qDebug()<<"Go to next Step"<<"New Index"<<this->_d->_currentStepIndex+1;
          this->_d->_currentStepIndex++;
          this->startStep(this->_d->_currentStepIndex);
        }
        return;
      }
    }
    if(!found){
      QString error = "Error: " + signalName +
          QStringLiteral(" actual ( ") +
          QStringLiteral("received signal") +
          QStringLiteral(" ) , expected ( ") +
          this->_d->_expectedSteps.first()->signal()->name() +
          QStringLiteral(" )");

      qDebug()<<error;
      emit this->runTimeMessage(false, QStringLiteral("  ") + error);
      this->finishedTestcase(false, error + QStringLiteral("\n"));
      return;
    }
  }
  return;
}

bool VibnTestExecutor::sendMySignal(const model::msc::MscMessageItem* step, QString* errorString)
{
  qDebug()<<"VibnTestExecutor::sendMySignal()";
  QList<QVariant> list;
  for(auto value : step->paramValues()){
    qDebug()<<"add Value"<<value->value();
    list.append(value->value());
  }

  QEventLoop loop;
  QTimer timer;
  timer.setSingleShot(true);
  timer.setInterval(10000);
  QObject::connect(this, &VibnTestExecutor::sendSignalDone,
                   &loop, &QEventLoop::quit);
  QObject::connect(&timer, &QTimer::timeout,
                   &loop, &QEventLoop::quit);


  QString mes = "";
  if(list.length() >= 1){
    mes = list.first().toString();
  }
  emit this->runTimeMessage(true, QStringLiteral("  Message sended: ") + step->signal()->name() + QStringLiteral(" ( ") + mes + QStringLiteral(" )"));
  qDebug()<<QStringLiteral("Message sended: ") + step->signal()->name() + QStringLiteral(" ( ") + mes + QStringLiteral(" )");

  timer.start();
  if(this->_autoCheckAfterWrite){
    this->_d->_expectedSteps.append(step);
  }
  QtConcurrent::run(this, &VibnTestExecutor::sendSignal, step->signal()->name(), list);

  loop.exec();
  if(!timer.isActive()){
    if(!this->_d->_lastSendReturn){
      utils::AddPtrString(errorString)<<"Writing Signal "<<step->signal()->name()<<" not successfull";
    }else{
      utils::AddPtrString(errorString)<<"Timeout!";
    }
    return false;
  }else{
    return true;
  }
}

void VibnTestExecutor::sendSignalResult(bool result)
{
  qDebug()<<"VibnTestExecutor::sendSignalSuccessfull()";
  this->_d->_lastSendReturn = result;
  emit this->sendSignalDone();
}

bool VibnTestExecutor::checkAdapter()
{
  return true;
}

}
