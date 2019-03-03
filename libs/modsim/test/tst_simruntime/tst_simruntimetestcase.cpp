#include <QtTest>

#include "simruntimecontrollersutadapter.hpp"

// add necessary includes here
#include <modsim/modsim.hpp>
#include <distestruntime/distestruntime.hpp>
#include <mobata/utils/fileutils.hpp>

using namespace distestruntime;

class SimRuntimeTestCase : public QObject
{
  Q_OBJECT

public:
  SimRuntimeTestCase();
  ~SimRuntimeTestCase();

private slots:
  void init();
  void cleanup();

private:
  modsim::SimRuntimeController*   _runtimeController=nullptr;
  SimRuntimeControllerSutAdapter* _sutAdapter=nullptr;
  TestCompRuntime*                _testCompRuntime=nullptr;
  TestCaseRuntime*                _testCaseRuntime=nullptr;
  QEventLoop*                     _testEventLoop=nullptr;

private slots:
  void prepareSimRuntime_1();
  void startSimRuntime_1();
  void startSimRuntime_2();
  void stopSimRuntime_1();
  void stopSimRuntime_2();
  void runSingleSimRuntime_1();
  void runSingleSimRuntime_2();
  void runSingleSimRuntime_3();
  void simSystemRuntime_1();
};

SimRuntimeTestCase::SimRuntimeTestCase()
{}

SimRuntimeTestCase::~SimRuntimeTestCase()
{}

void SimRuntimeTestCase::init()
{
  this->_runtimeController = new modsim::SimRuntimeController();
  this->_sutAdapter = new SimRuntimeControllerSutAdapter;
  this->_testCompRuntime = new TestCompRuntime("SUT");
  this->_testCaseRuntime = new TestCaseRuntime(QList<TestCompRuntime*>()
                                               <<this->_testCompRuntime);

  connect(this->_runtimeController, &modsim::SimRuntimeController::prepared,
          this->_sutAdapter, &SimRuntimeControllerSutAdapter::controllerPreparedSlot,
          Qt::QueuedConnection);
  connect(this->_runtimeController, &modsim::SimRuntimeController::started,
          this->_sutAdapter, &SimRuntimeControllerSutAdapter::controllerStartedSlot,
          Qt::QueuedConnection);
  connect(this->_runtimeController, &modsim::SimRuntimeController::stopped,
          this->_sutAdapter, &SimRuntimeControllerSutAdapter::controllerStoppedSlot,
          Qt::QueuedConnection);
  connect(this->_runtimeController, &modsim::SimRuntimeController::errors,
          this->_sutAdapter, &SimRuntimeControllerSutAdapter::errors,
          Qt::QueuedConnection);
  connect(this->_runtimeController, &modsim::SimRuntimeController::sendExternMessage,
          this->_sutAdapter, &SimRuntimeControllerSutAdapter::receiveRuntimeMessageSlot,
          Qt::QueuedConnection);
  connect(this->_runtimeController, &modsim::SimRuntimeController::observedMessage,
          this->_sutAdapter, &SimRuntimeControllerSutAdapter::observedRuntimeMessageSlot,
          Qt::QueuedConnection);

  connect(this->_sutAdapter, &SimRuntimeControllerSutAdapter::prepareController,
          this->_runtimeController, &modsim::SimRuntimeController::prepare,
          Qt::QueuedConnection);
  connect(this->_sutAdapter, &SimRuntimeControllerSutAdapter::startController,
          this->_runtimeController, &modsim::SimRuntimeController::start,
          Qt::QueuedConnection);
  connect(this->_sutAdapter, &SimRuntimeControllerSutAdapter::stopController,
          this->_runtimeController, &modsim::SimRuntimeController::stop,
          Qt::QueuedConnection);
  connect(this->_sutAdapter, &SimRuntimeControllerSutAdapter::sendMessage,
          this->_runtimeController, &modsim::SimRuntimeController::receiveExternMessageSlot,
          Qt::QueuedConnection);
  connect(this->_sutAdapter, &SimRuntimeControllerSutAdapter::errors,
          this->_testCompRuntime, &TestCompRuntime::addErrors,
          Qt::QueuedConnection);
  connect(this->_sutAdapter, &SimRuntimeControllerSutAdapter::messageReceived,
          this->_testCompRuntime, &TestCompRuntime::messageReceived,
          Qt::QueuedConnection);
  connect(this->_sutAdapter, &SimRuntimeControllerSutAdapter::messageSent,
          this->_testCompRuntime, &TestCompRuntime::messageSent,
          Qt::QueuedConnection);


  connect(this->_testCompRuntime, &TestCompRuntime::sendMessage,
          this->_sutAdapter, &SimRuntimeControllerSutAdapter::sendMessageSlot,
          Qt::QueuedConnection);

  this->_testEventLoop = new QEventLoop;
  connect(this->_testCaseRuntime, &TestCaseRuntime::testCaseQuitted,
          this->_testEventLoop, &QEventLoop::quit);

  return;
}

void SimRuntimeTestCase::cleanup()
{
  delete this->_runtimeController;
  this->_runtimeController=nullptr;

  delete this->_sutAdapter;
  this->_sutAdapter=nullptr;

  delete this->_testCompRuntime;
  this->_testCompRuntime=nullptr;

  delete this->_testCaseRuntime;
  this->_testCaseRuntime=nullptr;

  delete this->_testEventLoop;
  this->_testEventLoop=nullptr;

  return;
}

void SimRuntimeTestCase::prepareSimRuntime_1()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_ping.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pingSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pongSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = this->_runtimeController->addLink("pingSM", "p_pong",
                                             "pongSM", "p_ping",
                                             &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");

  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::startSimRuntime_1()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_ping.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pingSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pongSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = this->_runtimeController->addLink("pingSM", "p_pong",
                                             "pongSM", "p_ping",
                                             &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::startSimRuntime_2()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_ping.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pingSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pongSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = this->_runtimeController->addLink("pingSM", "p_pong",
                                             "pongSM", "p_ping",
                                             &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==false && messages.length==1 "
                                       "&& messages[0]==\"simulation controller is already started!\"",
                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::stopSimRuntime_1()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_ping.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pingSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pongSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = this->_runtimeController->addLink("pingSM", "p_pong",
                                             "pongSM", "p_ping",
                                             &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__stopController", "");
  this->_testCompRuntime->addCheckStep("__controllerStopped", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::stopSimRuntime_2()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_ping.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pingSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pongSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = this->_runtimeController->addLink("pingSM", "p_pong",
                                             "pongSM", "p_ping",
                                             &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__stopController", "");
  this->_testCompRuntime->addCheckStep("__controllerStopped", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==false && messages.length==1 "
                                       "&& messages[0]==\"simulation controller is not prepared, cannot be started!\"",
                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::runSingleSimRuntime_1()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_ping.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  QString modelAsName("pingSM");
  result = this->_runtimeController->addSimModel(modelText, modelAsName,
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("start", "p_ext",
                                         QVariantMap({{"__modelAsName__", modelAsName}}));
  this->_testCompRuntime->addCheckStep("ping", "p_pong",
                                       QStringList()<<"__modelAsName__",
                                       "__modelAsName__==\"pingSM\"",
                                       5000);

  this->_testCompRuntime->addMessageStep("pong", "p_pong",
                                         QVariantMap({{"__modelAsName__", modelAsName}}));
  this->_testCompRuntime->addCheckStep("ping", "p_pong",
                                       QStringList()<<"__modelAsName__",
                                       "__modelAsName__==\"pingSM\"",
                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::runSingleSimRuntime_2()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  QString modelAsName("pongSM");
  result = this->_runtimeController->addSimModel(modelText, modelAsName,
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("start", "p_ext",
                                         QVariantMap({{"__modelAsName__", modelAsName}}));
  this->_testCompRuntime->addMessageStep("ping", "p_ping",
                                         QVariantMap({{"__modelAsName__", modelAsName}}));
  this->_testCompRuntime->addCheckStep("pong", "p_ping",
                                       QStringList()<<"__modelAsName__",
                                       "__modelAsName__==\""+modelAsName+"\"",
                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::runSingleSimRuntime_3()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  QString modelAsName("pongSM");
  result = this->_runtimeController->addSimModel(modelText, modelAsName,
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("start", "p_ext",
                                         QVariantMap({{"__modelAsName__", modelAsName}}));
  this->_testCompRuntime->addMessageStep("ping", "p_ping",
                                         QVariantMap({{"__modelAsName__", modelAsName}}));
  this->_testCompRuntime->addCheckStep("pong", "p_ping",
                                       QStringList()<<"__modelAsName__",
                                       "__modelAsName__==\""+modelAsName+"\"",
                                       5000);
  this->_testCompRuntime->addMessageStep("end", "p_ext",
                                         QVariantMap({{"__modelAsName__", modelAsName}}));

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

void SimRuntimeTestCase::simSystemRuntime_1()
{
  QString errorString;
  bool result = false;

  QString modelText;
  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_ping.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pingSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = utils::FileUtils::textFileContent(":/tst_simruntime/tst_pong.statemachine",
                                             &modelText, &errorString);
  QCOMPARE(result, true);
  result = this->_runtimeController->addSimModel(modelText, "pongSM",
                                                 modsim::StateMachineModel, &errorString);
  QCOMPARE(result, true);

  result = this->_runtimeController->addLink("pingSM", "p_pong",
                                             "pongSM", "p_ping",
                                             &errorString);
  QCOMPARE(result, true);

  this->_testCompRuntime->addMessageStep("__prepareController", "");
  this->_testCompRuntime->addCheckStep("__controllerPrepared", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("__startController", "");
  this->_testCompRuntime->addCheckStep("__controllerStarted", "",
                                       QStringList()<<"result"<<"messages",
                                       "result==true && messages.length==1",
                                       5000);

  this->_testCompRuntime->addMessageStep("start", "p_ext",
                                         QVariantMap({{"__modelAsName__", "pongSM"}}));
  this->_testCompRuntime->addMessageStep("start", "p_ext",
                                         QVariantMap({{"__modelAsName__", "pingSM"}}));

  this->_testCompRuntime->addCheckStep("ping", "",
                                       QStringList()
                                       <<"__sourceModelAsName__"
                                       <<"__sourcePortName__"
                                       <<"__targetModelAsName__"
                                       <<"__targetPortName__",
                                       "__sourceModelAsName__==\"pingSM\" && __sourcePortName__==\"p_pong\""
                                       "&& __targetModelAsName__==\"pongSM\" && __targetPortName__==\"p_ping\"",
                                       5000);

  this->_testCompRuntime->addCheckStep("pong", "",
                                       QStringList()
                                       <<"__sourceModelAsName__"
                                       <<"__sourcePortName__"
                                       <<"__targetModelAsName__"
                                       <<"__targetPortName__",
                                       "__sourceModelAsName__==\"pongSM\" && __sourcePortName__==\"p_ping\""
                                       "&& __targetModelAsName__==\"pingSM\" && __targetPortName__==\"p_pong\"",
                                       5000);

  this->_testCompRuntime->addCheckStep("ping", "",
                                       QStringList()
                                       <<"__sourceModelAsName__"
                                       <<"__sourcePortName__"
                                       <<"__targetModelAsName__"
                                       <<"__targetPortName__",
                                       "__sourceModelAsName__==\"pingSM\" && __sourcePortName__==\"p_pong\""
                                       "&& __targetModelAsName__==\"pongSM\" && __targetPortName__==\"p_ping\"",
                                       5000);

  this->_testCompRuntime->addCheckStep("pong", "",
                                       QStringList()
                                       <<"__sourceModelAsName__"
                                       <<"__sourcePortName__"
                                       <<"__targetModelAsName__"
                                       <<"__targetPortName__",
                                       "__sourceModelAsName__==\"pongSM\" && __sourcePortName__==\"p_ping\""
                                       "&& __targetModelAsName__==\"pingSM\" && __targetPortName__==\"p_pong\"",
                                       5000);

  this->_testCompRuntime->addMessageStep("__stopController", "");
  //  this->_testCompRuntime->addCheckStep("__controllerStopped", "",
  //                                       QStringList()<<"result"<<"messages",
  //                                       "result==true && messages.length==1",
  //                                       5000);

  result=this->_testCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  for(const QString& error : this->_testCompRuntime->errors())
    qDebug()<<"error: "<<error;
  QCOMPARE(this->_testCompRuntime->errors().size(), 0);
  QCOMPARE(this->_testCompRuntime->testResult(), true);

  return;
}

QTEST_MAIN(SimRuntimeTestCase)

#include "tst_simruntimetestcase.moc"
