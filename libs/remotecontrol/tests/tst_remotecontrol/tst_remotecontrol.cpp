#include <QtTest>

#include "remotecontrolsut.hpp"
#include "remotecontroltester.hpp"
#include "sutadapter.hpp"
#include "testadapter.hpp"

#include <distestruntime/testcasestep.hpp>
#include <distestruntime/testcompruntime.hpp>
#include <distestruntime/testcaseruntime.hpp>

#include <remotecontrol/controlport.hpp>
#include <remotecontrol/remoteport.hpp>

#include <QEventLoop>

#include <mobata/memory_leak_start.hpp>

using namespace distestruntime;

static unsigned short localPort = 10100;

class RemoteControlSutTest
    : public QObject
{
  Q_OBJECT

public:
  RemoteControlSutTest()      {}
  virtual ~RemoteControlSutTest() {}

private:
  RemoteControlSut*     _remoteControlSut;
  RemoteControlTester*  _remoteControlTester;
  TestCompRuntime*      _testerTestCompRuntime;
  TestCompRuntime*      _sutTestCompRuntime;
  SutAdapter*           _sutAdapter;
  TestAdapter*          _testAdapter;
  TestCaseRuntime*      _testRuntime;
  QEventLoop*           _testEventLoop;

private:
  void initTestEnvironment();

  void remoteToSetupedState();
  void remoteToRunningState();
  void remoteToStoppedState();

private Q_SLOTS:
  void initTestCase();
  void cleanupTestCase();
  void init();
  void cleanup();

  //test cases//////////
  void connectToRemoteControlTest_1();
  void connectToRemoteControlTest_2();
  void setupRemoteControlTest_1();
  void setupRemoteControlTest_2();
  void setupRemoteControlTest_3();
  void setupRemoteControlTest_4();
  void setupRemoteControlTest_5();
  void statusRemoteControlTest_1();
  void statusRemoteControlTest_2();
  void startRemoteControlTest_1();
  void startRemoteControlTest_2();
  void startRemoteControlTest_3();
  void stopRemoteControlTest_1();
  void stopRemoteControlTest_2();
  void stopRemoteControlTest_3();
  void resetRemoteControlTest_1();
  void resetRemoteControlTest_2();
  void resetRemoteControlTest_3();
  void resetRemoteControlTest_4();
  void resetRemoteControlTest_5();
  void resetRemoteControlTest_6();
  void resetRemoteControlTest_7();
  void resetRemoteControlTest_8();
  void resetRemoteControlTest_9();
};

void RemoteControlSutTest::initTestCase()
{
  Q_INIT_RESOURCE(remotecontrol);

  this->_remoteControlSut=nullptr;
  this->_remoteControlTester=nullptr;
  this->_testerTestCompRuntime=nullptr;
  this->_sutTestCompRuntime=nullptr;
  this->_sutAdapter=nullptr;
  this->_testAdapter=nullptr;
  this->_testRuntime=nullptr;
  this->_testEventLoop=nullptr;
}

void RemoteControlSutTest::cleanupTestCase()
{}

void RemoteControlSutTest::init()
{}

void RemoteControlSutTest::initTestEnvironment()
{
  QString errorString;
  bool result = true;

  RemoteControlSutService* remoteControlSutService = new RemoteControlSutService();
  this->_remoteControlSut = new RemoteControlSut("RemoteControlSut", remoteControlSutService);
  this->_remoteControlSut->setLocalPort(localPort++);

  RemoteControlTesterService* remoteControlTesterService = new RemoteControlTesterService();
  this->_remoteControlTester = new RemoteControlTester("RemoteControlTester", remoteControlTesterService);
  this->_remoteControlTester->setUserPort(localPort++);
  this->_remoteControlTester->setRemoteControlPort(this->_remoteControlSut->localPort());

  result = this->_remoteControlSut->run(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(true, errorString.isEmpty());

  errorString.clear();
  result = this->_remoteControlTester->run(&errorString);
  if(!errorString.isEmpty())
    qDebug()<<"errorString: "<<errorString;
  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  this->_testerTestCompRuntime = new TestCompRuntime("Tester");
  connect(this->_testerTestCompRuntime, &TestCompRuntime::sendMessage,
          this->_remoteControlTester, &RemoteControlTester::sendMessageSlot);
  connect(this->_remoteControlTester, &RemoteControlTester::messageSent,
          this->_testerTestCompRuntime, &TestCompRuntime::messageSent);
  connect(this->_remoteControlTester, &RemoteControlTester::error,
          this->_testerTestCompRuntime, &TestCompRuntime::addError);

  this->_testAdapter = new TestAdapter;
  connect(this->_remoteControlTester, &RemoteControlTester::setuped,
          this->_testAdapter, &TestAdapter::setupedSlot);
  connect(this->_remoteControlTester, &RemoteControlTester::started,
          this->_testAdapter, &TestAdapter::startedSlot);
  connect(this->_remoteControlTester, &RemoteControlTester::stopped,
          this->_testAdapter, &TestAdapter::stoppedSlot);
  connect(this->_remoteControlTester, &RemoteControlTester::resetted,
          this->_testAdapter, &TestAdapter::resettedSlot);
  connect(this->_remoteControlTester, &RemoteControlTester::status,
          this->_testAdapter, &TestAdapter::statusSlot);
  connect(this->_testAdapter, &TestAdapter::messageReceived,
          this->_testerTestCompRuntime, &TestCompRuntime::messageReceived);

  this->_sutTestCompRuntime = new TestCompRuntime("SUT");
  connect(this->_remoteControlSut, &RemoteControlSut::error,
          this->_sutTestCompRuntime, &TestCompRuntime::addError);

  this->_sutAdapter = new SutAdapter;
  connect(this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::setupControl,
          this->_sutAdapter, &SutAdapter::setupControlSlot);
  connect(this->_sutAdapter, &SutAdapter::controlSetuped,
          this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::controlSetupped);
  connect(this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::startControl,
          this->_sutAdapter, &SutAdapter::startControlSlot);
  connect(this->_sutAdapter, &SutAdapter::controlStarted,
          this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::controlStarted);
  connect(this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::stopControl,
          this->_sutAdapter, &SutAdapter::stopControlSlot);
  connect(this->_sutAdapter, &SutAdapter::controlStopped,
          this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::controlStopped);
  connect(this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::resetControl,
          this->_sutAdapter, &SutAdapter::resetControlSlot);
  connect(this->_sutAdapter, &SutAdapter::controlResetted,
          this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::controlResetted);
  connect(this->_remoteControlSut->controlPort(), &remotecontrol::ControlPort::statusRequest,
          this->_sutAdapter, &SutAdapter::statusRequestSlot);
  connect(this->_sutAdapter, &SutAdapter::statusResponse,
          this->_remoteControlSut->remotePort(), &remotecontrol::RemotePort::statusResponse);

  connect(this->_sutAdapter, &SutAdapter::messageReceived,
          this->_sutTestCompRuntime, &TestCompRuntime::messageReceived);
  connect(this->_sutTestCompRuntime, &TestCompRuntime::sendMessage,
          this->_sutAdapter, &SutAdapter::sendMessageSlot);
  connect(this->_sutAdapter, &SutAdapter::sendMessage,
          this->_remoteControlSut, &RemoteControlSut::sendMessageSlot);
  connect(this->_remoteControlSut, &RemoteControlSut::messageSent,
          this->_sutAdapter, &SutAdapter::messageSentSlot);
  connect(this->_sutAdapter, &SutAdapter::messageSent,
          this->_sutTestCompRuntime, &TestCompRuntime::messageSent);

  QList<TestCompRuntime*> testComponents;
  testComponents<<this->_sutTestCompRuntime<<this->_testerTestCompRuntime;
  this->_testRuntime = new TestCaseRuntime(testComponents);

  this->_testEventLoop = new QEventLoop;
  connect(this->_testRuntime, &TestCaseRuntime::testCaseQuitted,
          this->_testEventLoop, &QEventLoop::quit);

  return;
}

/*!
* @brief preparation of remote control sut object to setuped state
*
* @startuml{remoteToSetupedState.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> RemoteTester: status[state==SetupedState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::remoteToSetupedState()
{
  Q_ASSERT(this->_testerTestCompRuntime);
  Q_ASSERT(this->_sutTestCompRuntime);

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  QVariantMap setupArgs;
  setupArgs.insert("param", "hello setup");
  this->_testerTestCompRuntime->addMessageStep("setup", QVariantList()<<setupArgs);
  this->_testerTestCompRuntime->addCheckStep("setuped",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"SetupedState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("setupControl",
                                          QStringList()<<"param",
                                          "param==\"hello setup\"",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep("controlSetuped",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  return;
}

/*!
* @brief preparation of remote control sut object to running state
*
* @startuml{remoteToRunningState.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::remoteToRunningState()
{
  Q_ASSERT(this->_testerTestCompRuntime);
  Q_ASSERT(this->_sutTestCompRuntime);

  this->remoteToSetupedState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("start");
  this->_testerTestCompRuntime->addCheckStep("started",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"RunningState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("startControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlStarted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  return;
}

/*!
* @brief preparation of remote control sut object to stopped state
*
* @startuml{remoteToStoppedState.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: stop()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StoppedState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::remoteToStoppedState()
{
  Q_ASSERT(this->_testerTestCompRuntime);
  Q_ASSERT(this->_sutTestCompRuntime);

  this->remoteToRunningState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("stop");
  this->_testerTestCompRuntime->addCheckStep("stopped",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"StoppedState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("stopControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlStopped",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  return;
}

void RemoteControlSutTest::cleanup()
{
  delete this->_remoteControlSut;
  this->_remoteControlSut=nullptr;

  delete this->_remoteControlTester;
  this->_remoteControlTester=nullptr;

  delete this->_sutTestCompRuntime;
  this->_sutTestCompRuntime=nullptr;

  delete this->_sutAdapter;
  this->_sutAdapter=nullptr;

  delete this->_testerTestCompRuntime;
  this->_testerTestCompRuntime=nullptr;

  delete this->_testAdapter;
  this->_testAdapter=nullptr;

  delete this->_testRuntime;
  this->_testRuntime=nullptr;

  delete this->_testEventLoop;
  this->_testEventLoop=nullptr;

  return;
}

void RemoteControlSutTest::connectToRemoteControlTest_1()
{
  this->initTestEnvironment();

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

void RemoteControlSutTest::connectToRemoteControlTest_2()
{
  this->initTestEnvironment();

  QString errorString;
  bool result = true;

  QVariantList args;
  args<<this->_remoteControlTester->userAddressString()
     <<this->_remoteControlTester->userPort();
  this->_testerTestCompRuntime->addMessageStep("open",args);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the first steps for setupping remote control
*
* @startuml{setupRemoteControlTest_1.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::setupRemoteControlTest_1()
{
  this->initTestEnvironment();

  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  QVariantMap setupArgs;
  setupArgs.insert("param", "hello setup");
  this->_testerTestCompRuntime->addMessageStep("setup", QVariantList()<<setupArgs);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("setupControl",
                                          QStringList()<<"param",
                                          "param==\"hello setup\"",
                                          5000);
  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the first steps for setupping remote control
*
* @startuml{setupRemoteControlTest_2.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::setupRemoteControlTest_2()
{
  this->initTestEnvironment();



  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  QVariantMap setupArgs;
  setupArgs.insert("param", "hello setup");
  this->_testerTestCompRuntime->addMessageStep("setup", QVariantList()<<setupArgs);
  this->_testerTestCompRuntime->addCheckStep("setuped",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("setupControl",
                                          QStringList()<<"param",
                                          "param==\"hello setup\"",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep("controlSetuped",
                                            QVariantList()<<true<<"");
  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the first steps for setupping remote control
*
* @startuml{setupRemoteControlTest_3.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> RemoteTester: status[state==SetupedState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::setupRemoteControlTest_3()
{
  this->initTestEnvironment();

  this->remoteToSetupedState();

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;
  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the first steps for setupping remote control
*
* @startuml{setupRemoteControlTest_4.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(false)
* RemoteControl -> RemoteTester: setuped(false)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> RemoteTester: status[state==SetupErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::setupRemoteControlTest_4()
{
  this->initTestEnvironment();

  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  QVariantMap setupArgs;
  setupArgs.insert("param", "hello setup");
  this->_testerTestCompRuntime->addMessageStep("setup", QVariantList()<<setupArgs);
  this->_testerTestCompRuntime->addCheckStep("setuped",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"SetupErrorState\"",
                                             5000);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("setupControl",
                                          QStringList()<<"param",
                                          "param==\"hello setup\"",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep("controlSetuped",
                                            QVariantList()<<false<<"error during control setup!");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());
  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the first steps for setupping remote control
*
* @startuml{setupRemoteControlTest_5.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> ControlTester: controlSetuped.timeout
* RemoteControl -> RemoteTester: setuped(false)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> RemoteTester: status[state==SetupErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::setupRemoteControlTest_5()
{
  this->initTestEnvironment();

  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  QVariantMap setupArgs;
  setupArgs.insert("param", "hello setup");
  this->_testerTestCompRuntime->addMessageStep("setup", QVariantList()<<setupArgs);
  this->_testerTestCompRuntime->addCheckStep("setuped",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"SetupErrorState\"",
                                             5000);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("setupControl",
                                          QStringList()<<"param",
                                          "param==\"hello setup\"",
                                          5000);
  this->_sutTestCompRuntime->addTimeoutStep(3000);
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the first steps for getting status of remote control
*
* @startuml{statusRemoteControlTest_1.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::statusRemoteControlTest_1()
{
  this->initTestEnvironment();

  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());
  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the first steps for getting status of remote control
*
* @startuml{statusRemoteControlTest_2.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> ControlTester: statusResponse.timeout()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::statusRemoteControlTest_2()
{
  this->initTestEnvironment();

  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addTimeoutStep(3000);
  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the starting of the remote control
*
* @startuml{startRemoteControlTest_1.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::startRemoteControlTest_1()
{
  this->initTestEnvironment();

  this->remoteToRunningState();

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the starting of the remote control
*
* @startuml{startRemoteControlTest_2.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(false)
* RemoteControl -> RemoteTester: started[value==false]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StartErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::startRemoteControlTest_2()
{
  this->initTestEnvironment();

  this->remoteToSetupedState();

  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("start");
  this->_testerTestCompRuntime->addCheckStep("started",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"StartErrorState\"",
                                             5000);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("startControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlStarted",
                                            QVariantList()<<false<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the starting of the remote control
*
* @startuml{startRemoteControlTest_3.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> ControlTester: controlStarted.timeout()
* RemoteControl -> RemoteTester: started[value==false]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StartErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::startRemoteControlTest_3()
{
  this->initTestEnvironment();

  this->remoteToSetupedState();

  QString errorString;
  bool result = true;

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("start");
  this->_testerTestCompRuntime->addCheckStep("started",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"StartErrorState\"",
                                             5000);

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("startControl", 5000);
  this->_sutTestCompRuntime->addTimeoutStep(3000);
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the stopping of the remote control
*
* @startuml{stopRemoteControlTest_1.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: stop()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StoppedState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::stopRemoteControlTest_1()
{
  this->initTestEnvironment();

  this->remoteToStoppedState();

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the stopping of the remote control
*
* @startuml{stopRemoteControlTest_2.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: stop()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(false)
* RemoteControl -> RemoteTester: stopped[value==false]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StopErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::stopRemoteControlTest_2()
{
  this->initTestEnvironment();

  this->remoteToRunningState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("stop");
  this->_testerTestCompRuntime->addCheckStep("stopped",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"StopErrorState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("stopControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlStopped",
                                            QVariantList()<<false<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the stopping of the remote control
*
* @startuml{stopRemoteControlTest_3.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: stop()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> ControlTester: controlStopped.timeout()
* RemoteControl -> RemoteTester: stopped[value==false]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StopErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::stopRemoteControlTest_3()
{
  this->initTestEnvironment();

  this->remoteToRunningState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("stop");
  this->_testerTestCompRuntime->addCheckStep("stopped",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"StopErrorState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("stopControl", 5000);
  this->_sutTestCompRuntime->addTimeoutStep(3000);
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_1.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: stop()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StoppedState]
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(true)
* RemoteControl -> RemoteTester: resetted[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_1()
{
  this->initTestEnvironment();

  this->remoteToStoppedState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_2.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: stop()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StoppedState]
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(false)
* RemoteControl -> RemoteTester: resetted[value==false]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==ResetErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_2()
{
  this->initTestEnvironment();

  this->remoteToStoppedState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"ResetErrorState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<false<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_3.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: stop()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==StoppedState]
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> ControlTester: controlResetted.timeout()
* RemoteControl -> RemoteTester: resetted[value==false]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==ResetErrorState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_3()
{
  this->initTestEnvironment();

  this->remoteToStoppedState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"ResetErrorState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addTimeoutStep(3000);
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_4.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> RemoteControl: controlStarted(true)
* RemoteControl -> RemoteTester: started[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==RunningState]
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(true)
* RemoteControl -> RemoteTester: resetted[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_4()
{
  this->initTestEnvironment();

  this->remoteToRunningState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("stopped",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("stopControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlStopped",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_5.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(true)
* RemoteControl -> RemoteTester: resetted[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_5()
{
  this->initTestEnvironment();

  this->remoteToSetupedState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("start");
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("stopped",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("startControl", 5000);
  this->_sutTestCompRuntime->addCheckStep("stopControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlStopped",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_6.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: start()
* RemoteControl -> ControlTester: startControl()
* ControlTester -> ControlTester: controlStarted.timeout()
* RemoteControl -> RemoteTester: started[value==false]
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: stopControl()
* ControlTester -> RemoteControl: controlStopped(true)
* RemoteControl -> RemoteTester: stopped[value==true]
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(true)
* RemoteControl -> RemoteTester: resetted[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_6()
{
  this->initTestEnvironment();

  this->remoteToSetupedState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("start");
  this->_testerTestCompRuntime->addCheckStep("started",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("stopped",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("startControl", 5000);
  this->_sutTestCompRuntime->addTimeoutStep(3000);
  this->_sutTestCompRuntime->addCheckStep("stopControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlStopped",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_7.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> RemoteControl: controlSetuped(true)
* RemoteControl -> RemoteTester: setuped(true)
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==SetupedState]
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(true)
* RemoteControl -> RemoteTester: resetted[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_7()
{
  this->initTestEnvironment();

  this->remoteToSetupedState();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_8.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(true)
* RemoteControl -> RemoteTester: resetted[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_8()
{
  this->initTestEnvironment();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  QVariantMap setupArgs;
  setupArgs.insert("param", "hello setup");
  this->_testerTestCompRuntime->addMessageStep("setup", QVariantList()<<setupArgs);
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("setupControl",
                                          QStringList()<<"param",
                                          "param==\"hello setup\"",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

/*!
* @brief This test case tests the resetting of the remote control
*
* @startuml{resetRemoteControlTest_9.png}
*
* RemoteTester -> RemoteControl: open(Address, Port)
* RemoteTester -> RemoteControl: setup(param = "hello setup")
* RemoteControl -> ControlTester: setupControl[param == "hello setup"]
* ControlTester -> ControlTester: controlSetuped.timeout()
* RemoteControl -> RemoteTester: setuped(false)
* RemoteTester -> RemoteControl: reset()
* RemoteControl -> ControlTester: resetControl()
* ControlTester -> RemoteControl: controlResetted(true)
* RemoteControl -> RemoteTester: resetted[value==true]
* RemoteTester -> RemoteControl: status()
* RemoteControl -> ControlTester: statusRequest()
* ControlTester -> RemoteControl: statusResponse()
* RemoteControl -> RemoteTester: status[state==IdleState]
*
* @enduml
*
* @return.
*/
void RemoteControlSutTest::resetRemoteControlTest_9()
{
  this->initTestEnvironment();

  //tester test case
  this->_testerTestCompRuntime->addMessageStep("open",
                                               QVariantList()
                                               <<this->_remoteControlTester->userAddressString()
                                               <<this->_remoteControlTester->userPort());
  QVariantMap setupArgs;
  setupArgs.insert("param", "hello setup");
  this->_testerTestCompRuntime->addMessageStep("setup", QVariantList()<<setupArgs);
  this->_testerTestCompRuntime->addCheckStep("setuped",
                                             QStringList()<<"value"<<"messages",
                                             "value===false",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("reset");
  this->_testerTestCompRuntime->addCheckStep("resetted",
                                             QStringList()<<"value"<<"messages",
                                             "value===true",
                                             5000);
  this->_testerTestCompRuntime->addMessageStep("status");
  this->_testerTestCompRuntime->addCheckStep("status",
                                             QStringList()<<"state"<<"messages",
                                             "state==\"IdleState\"",
                                             5000);

  //sut test case
  this->_sutTestCompRuntime->addCheckStep("setupControl",
                                          QStringList()<<"param",
                                          "param==\"hello setup\"",
                                          5000);
  this->_sutTestCompRuntime->addTimeoutStep(3000);
  this->_sutTestCompRuntime->addCheckStep("resetControl", 5000);
  this->_sutTestCompRuntime->addMessageStep("controlResetted",
                                            QVariantList()<<true<<"");
  this->_sutTestCompRuntime->addCheckStep("statusRequest", 5000);
  this->_sutTestCompRuntime->addMessageStep("statusResponse",
                                            QVariantList()<<QStringList());

  QString errorString;
  bool result = true;

  result=this->_testerTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QCOMPARE(result, true);
  QCOMPARE(errorString.isEmpty(), true);

  QTimer::singleShot(100, this->_testRuntime, &TestRuntime::start);//should start after his->_testEventLoop->exec()
  this->_testEventLoop->exec();

  if(!this->_testerTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_testerTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_testerTestCompRuntime->testResult(), true);
  QCOMPARE(this->_testerTestCompRuntime->errors().size(), 0);

  if(!this->_sutTestCompRuntime->testResult())
  {
    for(const QString& errorString : this->_sutTestCompRuntime->errors())
      qDebug()<<errorString;
  }
  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  return;
}

QTEST_GUILESS_MAIN(RemoteControlSutTest)

#include "tst_remotecontrol.moc"
