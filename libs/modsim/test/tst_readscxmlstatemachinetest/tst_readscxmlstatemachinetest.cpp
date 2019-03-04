#include <QString>
#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>
#include <mobata/model/base/functionitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <mobata/model/msc/mscloopfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>
#include <mobata/model/statemachine/transitionitem.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/simplestateitem.hpp>
#include <mobata/model/statemachine/compositestateitem.hpp>
#include <mobata/model/statemachine/concurrentstateitem.hpp>
#include <mobata/model/statemachine/abstractstateitem.hpp>
#include <mobata/model/statemachine/finalstateitem.hpp>
#include <mobata/model/statemachine/junctionstateitem.hpp>
#include <mobata/model/statemachine/regionitem.hpp>
#include <mobata/model/statemachine/types.hpp>
#include <mobata/model/base/propsignals.hpp>
#include <mobata/prop/nameproperty.hpp>

#include <dslparser/statement/combuildstatementmodel.hpp>
#include <dslparser/statemachine/combuildstatemachinemodel.hpp>
#include <dslparser/statemachine/combuildstatemachinefile.hpp>
#include <modsim/comscxmlwriter.hpp>

#include "scxmlsutadapter.hpp"

#include <distestruntime/distestruntime.hpp>

#include <QEventLoop>

#include <QtScxml/QScxmlStateMachine>
#include <QIODevice>

using namespace distestruntime;

class ReadScxmlStatemachineTest
    : public QObject
{
  Q_OBJECT

public:
  ReadScxmlStatemachineTest();


private:
  ScxmlSutAdapter*  _scxmlSutAdapter;
  TestCompRuntime*  _sutTestCompRuntime;
  TestCaseRuntime*  _testCaseRuntime;
  QEventLoop*       _testEventLoop;

  void initTestEnvironment(QScxmlStateMachine* machine,
                           model::statemachine::StateMachineModel* model);

private Q_SLOTS:
  void init();
  void initTestCase();
  void cleanup();
  void cleanupTestCase();
  void simpleStateMachineDeclTest_1();
  void simpleStateMachineDeclTest_2();
  void simpleStateMachineDeclTest_3();
  void simpleStateMachineDeclTest_4();
  void iOLStestcase1();
  void iOLStestcase2();
  void runtimeTest1();
  void runtimeTest2();
  void runtimeTest3();
  void runtimeTest4();

  void timeoutTrans1();
  void timeoutTrans2();
  void timeoutTrans3();
private:
  QString _eventContent = QString("");
  bool    _statereached = false;
};

void ReadScxmlStatemachineTest::initTestEnvironment(QScxmlStateMachine *machine,
                                                    model::statemachine::StateMachineModel* model)
{
  this->_scxmlSutAdapter = new ScxmlSutAdapter(machine,model);

  this->_sutTestCompRuntime = new TestCompRuntime("SUT");

  connect(this->_scxmlSutAdapter, &ScxmlSutAdapter::errors,
          this->_sutTestCompRuntime, &TestCompRuntime::addErrors);

  connect(this->_scxmlSutAdapter, &ScxmlSutAdapter::messageReceived,
          this->_sutTestCompRuntime, &TestCompRuntime::messageReceived);

  connect(this->_sutTestCompRuntime, &TestCompRuntime::sendMessage,
          this->_scxmlSutAdapter, &ScxmlSutAdapter::messageToScxml);

  connect(this->_scxmlSutAdapter, &ScxmlSutAdapter::messageSent,
          this->_sutTestCompRuntime, &TestCompRuntime::messageSent);

  QList<TestCompRuntime*> testComponents;
  testComponents<<this->_sutTestCompRuntime;
  this->_testCaseRuntime = new TestCaseRuntime(testComponents);

  this->_testEventLoop = new QEventLoop;
  connect(this->_testCaseRuntime, &TestCaseRuntime::testCaseQuitted,
          this->_testEventLoop, &QEventLoop::quit);

  return;
}

ReadScxmlStatemachineTest::ReadScxmlStatemachineTest()
{

}

void ReadScxmlStatemachineTest::init()
{
  Q_INIT_RESOURCE(testdata);

  this->_scxmlSutAdapter=nullptr;
  this->_sutTestCompRuntime=nullptr;
  this->_testCaseRuntime=nullptr;
  this->_testEventLoop=nullptr;
}

void ReadScxmlStatemachineTest::initTestCase()
{}

void ReadScxmlStatemachineTest::cleanup()
{
  delete this->_scxmlSutAdapter;
  this->_scxmlSutAdapter=nullptr;

  delete this->_sutTestCompRuntime;
  this->_sutTestCompRuntime=nullptr;

  delete this->_testCaseRuntime;
  this->_testCaseRuntime=nullptr;

  delete this->_testEventLoop;
  this->_testEventLoop=nullptr;
}

void ReadScxmlStatemachineTest::cleanupTestCase()
{}

void ReadScxmlStatemachineTest::simpleStateMachineDeclTest_1()
{
  QString docText(
        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;"
        "Attribute int test = 0;\n"
        "Signal hallo (int x);\n"
        "Signal tschuess ();\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "entry: test = 20;"
        "exit: send hallo(test);\n"
        "}\n"
        "FinalState s2;\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  auto scxmlStateMachine = QScxmlStateMachine::fromData(&buffer);
  scxmlStateMachine->connectToEvent(QString("hallo"),[this](const QScxmlEvent &event){
    QVariantMap map = event.data().toMap();
    for(auto vari : map.keys()) _eventContent += QString("%0 = %1\n").arg(vari,QString::number(map.value(vari).toInt()));
  });
  scxmlStateMachine->init();
  scxmlStateMachine->start();
  QEventLoop loop;

  QTimer timer;

  timer.setSingleShot(true);
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

  timer.start(500);
  loop.exec();
  QCOMPARE(_eventContent,QString(""));
  connect(scxmlStateMachine, &QScxmlStateMachine::finished,&loop,&QEventLoop::quit);
  scxmlStateMachine->submitEvent(QString("tschuess"));
  loop.exec();
  QCOMPARE(_eventContent,QString("x = 20\n"));
  _eventContent = QString("");
  return;
}

void ReadScxmlStatemachineTest::simpleStateMachineDeclTest_2()
{
  QString docText(

        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;"
        "Attribute int test = 0;\n"
        "Signal hallo (int x);\n"
        "Signal tschuess ();\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "entry: test = 20;"
        "exit: send hallo(test);\n"
        "}\n"
        "FinalState s2;\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "guard: test == 20;"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  auto scxmlStateMachine = QScxmlStateMachine::fromData(&buffer);
  scxmlStateMachine->connectToEvent(QString("hallo"),[this](const QScxmlEvent &event){
    QVariantMap map = event.data().toMap();
    for(auto vari : map.keys()) _eventContent += QString("%0 = %1\n").arg(vari,QString::number(map.value(vari).toInt()));
  });
  scxmlStateMachine->init();
  scxmlStateMachine->start();
  QEventLoop loop;

  QTimer timer;

  timer.setSingleShot(true);
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

  timer.start(500);
  loop.exec();
  QCOMPARE(_eventContent,QString(""));
  connect(scxmlStateMachine, &QScxmlStateMachine::finished,&loop,&QEventLoop::quit);

  QVariantMap m2;
  m2.insert(QString("P0rT_GuaRd"),0);
  scxmlStateMachine->submitEvent(QString("tschuess"),m2);

  timer.setSingleShot(true);
  timer.start(500);
  loop.exec();
  QCOMPARE(_eventContent,QString("x = 20\n"));
  _eventContent = QString("");
  return;
}

void ReadScxmlStatemachineTest::simpleStateMachineDeclTest_3()
{
  QString docText(

        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;"
        "Attribute int test = 0;\n"
        "Signal hallo (int x);\n"
        "Signal tschuess (int y);\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "entry: test = 20;"
        "exit: send hallo(test);\n"
        "}\n"
        "FinalState s2;\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "guard: test == 20 && msg.y == 10;"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  auto scxmlStateMachine = QScxmlStateMachine::fromData(&buffer);
  scxmlStateMachine->connectToEvent(QString("hallo"),[this](const QScxmlEvent &event){
    QVariantMap map = event.data().toMap();
    for(auto vari : map.keys()) _eventContent += QString("%0 = %1\n").arg(vari,QString::number(map.value(vari).toInt()));
  });
  scxmlStateMachine->init();
  scxmlStateMachine->start();
  QEventLoop loop;

  QTimer timer;

  timer.setSingleShot(true);
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  connect(scxmlStateMachine, &QScxmlStateMachine::finished,&loop,&QEventLoop::quit);
  timer.start(500);
  loop.exec();

  QCOMPARE(_eventContent,QString(""));
  QVariantMap m1;
  m1.insert(QString("y"),1);
  m1.insert(QString("P0rT_GuaRd"),0);
  scxmlStateMachine->submitEvent(QString("tschuess"),m1);
  timer.start(500);
  loop.exec();

  QCOMPARE(_eventContent,QString(""));
  QVariantMap m2;
  m2.insert(QString("y"),10);
  m2.insert(QString("P0rT_GuaRd"),0);
  scxmlStateMachine->submitEvent(QString("tschuess"),m2);
  timer.start(500);
  loop.exec();
  QCOMPARE(_eventContent,QString("x = 20\n"));
  _eventContent = QString("");
  return;
}

void ReadScxmlStatemachineTest::simpleStateMachineDeclTest_4()
{
  QString docText(

        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;"
        "Attribute int test = 0;\n"
        "Signal hallo (int x);\n"
        "Signal tschuess (int y);\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "entry: test = 20;"
        "}\n"
        "FinalState s2;\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "guard: test == 20 && msg.y == 10;"
        "action: send hallo(msg.y);"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);

  //QCOMPARE(result, true);
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  auto scxmlStateMachine = QScxmlStateMachine::fromData(&buffer);
  scxmlStateMachine->connectToEvent(QString("hallo"),[this](const QScxmlEvent &event){
    QVariantMap map = event.data().toMap();
    for(auto vari : map.keys()) _eventContent += QString("%0 = %1\n").arg(vari,QString::number(map.value(vari).toInt()));
  });
  scxmlStateMachine->init();
  scxmlStateMachine->start();
  QEventLoop loop;

  QTimer timer;

  timer.setSingleShot(true);
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  connect(scxmlStateMachine, &QScxmlStateMachine::finished,&loop,&QEventLoop::quit);
  timer.start(500);
  loop.exec();

  QCOMPARE(_eventContent,QString(""));
  QVariantMap m1;
  m1.insert(QString("y"),1);
  m1.insert(QString("P0rT_GuaRd"),0);
  scxmlStateMachine->submitEvent(QString("tschuess"),m1);
  timer.start(500);
  loop.exec();

  QCOMPARE(_eventContent,QString(""));
  QVariantMap m2;
  m2.insert(QString("y"),10);
  m2.insert(QString("P0rT_GuaRd"),0);
  scxmlStateMachine->submitEvent(QString("tschuess"),m2);
  timer.start(500);
  loop.exec();
  QCOMPARE(_eventContent,QString("x = 10\n"));
  _eventContent = QString("");
  return;
}

void ReadScxmlStatemachineTest::iOLStestcase1()
{
  QString praefix = ":/testdata/";
  QString filename = praefix + "FSDeviceDriver.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  auto scxmlStateMachine = QScxmlStateMachine::fromData(&buffer);
  scxmlStateMachine->start();
  QVERIFY(scxmlStateMachine->isRunning());


  scxmlStateMachine->connectToState(QString("WaitOnSPDU_24"),[this](bool activated){
    _statereached = activated;
  });
  QEventLoop loop;

  QTimer timer;

  timer.setSingleShot(true);
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  connect(scxmlStateMachine, &QScxmlStateMachine::finished,&loop,&QEventLoop::quit);
  timer.start(500);
  loop.exec();

  QCOMPARE(_eventContent,QString(""));
  QVariantMap m1;
  m1.insert(QString("evFsPdOut"),100);
  m1.insert(QString("evPortNum"),10);
  m1.insert(QString("evMCount"),7);
  m1.insert(QString("evSetSD"),true);
  m1.insert(QString("evChFAckReq"),true);
  m1.insert(QString("evCrc"),1);
  scxmlStateMachine->submitEvent(QString("evSPDUReceived"),m1);
  timer.start(500);
  loop.exec();

  QVERIFY(_statereached);
  _statereached = false;

  //  QScxmlDataModel datamodel;
  //  datamodel.
  //  scxmlStateMachine.setDataModel();
  return;
}

void ReadScxmlStatemachineTest::iOLStestcase2()
{
  QString praefix = ":/testdata/";
  QString filename = praefix + "FSMasterDriver.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();

  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  return;
}

void ReadScxmlStatemachineTest::runtimeTest1()
{
  QString docText(

        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;"
        "Attribute int test = 0;\n"
        "Signal hallo (int x);\n"
        "Signal tschuess ();\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "entry: test = 20;"
        "exit: send hallo(test) to defaultPort;\n"
        "}\n"
        "FinalState s2;\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);

  //QCOMPARE(result, true);
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  QScxmlStateMachine* machine = QScxmlStateMachine::fromData(&buffer);
  this->initTestEnvironment(machine,&statemachineModel);

  //tester test case
  this->_sutTestCompRuntime->addMessageStep(QLatin1String("tschuess"),
                                            QLatin1String("defaultPort"));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===20",
                                          5000);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer startTimer;
  QObject::connect(&startTimer, &QTimer::timeout,
                   [&machine, this]()
  {
    qDebug()<<"start timeout received!";
    machine->start();
    this->_testCaseRuntime->start();
  });
  startTimer.start(100);//should start after this->_testEventLoop->exec()

  this->_testEventLoop->exec();

  bool testResult=this->_sutTestCompRuntime->testResult();
  if(!testResult)
  {
    for(auto error : this->_sutTestCompRuntime->errors())
      qDebug()<<"error: "<<error;
  }

  QCOMPARE(testResult, true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  machine->stop();

  delete machine;
  return;
}

void ReadScxmlStatemachineTest::runtimeTest2()
{
  QString docText(
        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;"
        "Attribute int cond = 20;\n"
        "Signal hallo (int x);\n"
        "Signal tschuess (int y);\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        //        "entry: cond = 20;"
        "exit: send hallo(cond) to defaultPort;\n"
        "}\n"
        "FinalState s2;\n"
        "JunctionState {\n"
        "  name: condition_1;\n"
        "  JunctionTransition {\n"
        "    name: transition_1;\n"
        "    guard: cond == 10;\n"
        "    action: {\n"
        "      send hallo(1) to defaultPort;\n"
        "    }\n"
        "    target: s2;\n"
        "  }\n"
        "  JunctionTransition {\n"
        "    name: transition_2;\n"
        "    guard: else;\n"
        "    action: {\n"
        "      send hallo(0) to defaultPort;\n"
        "    }\n"
        "    target: s1;\n"
        "  }\n"
        "}\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "action: {"
        "  cond = msg.y;"
        "}"
        "source: s1;\n"
        "target: condition_1;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);

  //QCOMPARE(result, true);
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),3);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  QScxmlStateMachine* machine = QScxmlStateMachine::fromData(&buffer);
  this->initTestEnvironment(machine,&statemachineModel);

  //tester test case
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"),
                                            QVariantMap({{"y",5}}));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===20",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===0",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"),
                                            QVariantMap({{"y",10}}));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===5",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===0",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"),
                                            QVariantMap({{"y",5}}));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===10",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===1",
                                          5000);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer startTimer;
  QObject::connect(&startTimer, &QTimer::timeout,
                   [&machine, this]()
  {
    qDebug()<<"start timeout received!";
    machine->start();
    this->_testCaseRuntime->start();
  });
  startTimer.start(100);//should start after this->_testEventLoop->exec()

  this->_testEventLoop->exec();

  bool testResult=this->_sutTestCompRuntime->testResult();
  if(!testResult)
  {
    for(auto error : this->_sutTestCompRuntime->errors())
      qDebug()<<"error: "<<error;
  }

  QCOMPARE(testResult, true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  machine->stop();

  delete machine;
  return;
}

void ReadScxmlStatemachineTest::runtimeTest3()
{
  QString docText(
        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;"
        "Attribute int inputCond = 0;\n"
        "Attribute int cond = 20;\n"
        "Attribute bool takenLoop = false;\n"
        "Signal hallo (int x);\n"
        "Signal tschuess (int y);\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        //        "entry: cond = 20;"
        "exit: send hallo(cond) to defaultPort;\n"
        "}\n"
        "FinalState s2;\n"
        "JunctionState {\n"
        "  name: condition_2;\n"
        "  JunctionTransition {\n"
        "    name: transition_1;\n"
        "    guard: cond == 5;\n"
        "    action: {\n"
        "      cond = inputCond;"
        "      takenLoop = true;"
        "      send hallo(2) to defaultPort;\n"
        "    }\n"
        "    target: s1;\n"
        "  }\n"
        "  JunctionTransition {\n"
        "    name: transition_2;\n"
        "    guard: else;\n"
        "    action: {\n"
        "      cond = inputCond;\n"
        "      send hallo(3) to defaultPort;\n"
        "    }\n"
        "    target: s1;\n"
        "  }\n"
        "}\n"
        "JunctionState {\n"
        "  name: condition_1;\n"
        "  JunctionTransition {\n"
        "    name: transition_1;\n"
        "    guard: takenLoop && cond == 10;\n"
        "    action: {\n"
        "      send hallo(1) to defaultPort;\n"
        "    }\n"
        "    target: s2;\n"
        "  }\n"
        "  JunctionTransition {\n"
        "    name: transition_2;\n"
        "    guard: else;\n"
        "    action: {\n"
        "      send hallo(0) to defaultPort;\n"
        "    }\n"
        "    target: condition_2;\n"
        "  }\n"
        "}\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "action: {"
        "  inputCond = msg.y;"
        "}"
        "source: s1;\n"
        "target: condition_1;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);

  //QCOMPARE(result, true);
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),4);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  QScxmlStateMachine* machine = QScxmlStateMachine::fromData(&buffer);
  this->initTestEnvironment(machine,&statemachineModel);

  //tester test case
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"),
                                            QVariantMap({{"y",10}}));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===20",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===0",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===3",
                                          5000);

  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"),
                                            QVariantMap({{"y",5}}));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===10",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===0",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===3",
                                          5000);

  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"),
                                            QVariantMap({{"y",10}}));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===5",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===0",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===2",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"),
                                            QVariantMap({{"y",5}}));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===10",
                                          5000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===1",
                                          5000);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer startTimer;
  QObject::connect(&startTimer, &QTimer::timeout,
                   [&machine, this]()
  {
    qDebug()<<"start timeout received!";
    machine->start();
    this->_testCaseRuntime->start();
  });
  startTimer.start(100);//should start after this->_testEventLoop->exec()

  this->_testEventLoop->exec();

  bool testResult=this->_sutTestCompRuntime->testResult();
  if(!testResult)
  {
    for(auto error : this->_sutTestCompRuntime->errors())
      qDebug()<<"error: "<<error;
  }

  QCOMPARE(testResult, true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  machine->stop();

  delete machine;
  return;
}

void ReadScxmlStatemachineTest::runtimeTest4()
{
  QString docText(
        "StateMachine {\n"
        "name: statemachine1;\n"
        "Port defaultPort;\n"
        "Attribute int test = 10;\n"
        "Attribute bool endLoop = false;\n"
        "Function void endLoopFunction()\n"
        "{\n"
        " if(test == 0){\n"
        "  endLoop = true;\n"
        " }\n"
        "}\n"
        "Function void lastCondition()\n"
        "{\n"
        " if(test == 1){\n"
        "  return true;\n"
        " }\n"
        " else{\n"
        "  return false;\n"
        " }\n"
        "}\n"
        "Signal hallo (int x);\n"
        "Signal tschuess ();\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "}\n"
        "FinalState s2;\n"
        "SignalTransition {\n"
        "name: t1;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "guard: !endLoop;\n"
        "action: {\n"
        "  endLoopFunction();\n"
        "  test = 0;\n"
        "  send hallo(0) to defaultPort;\n"
        "}\n"
        "source: s1;\n"
        "target: s1;\n"
        "}\n"
        "SignalTransition {\n"
        "name: t2;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "guard: endLoop && !lastCondition();\n"
        "action: {\n"
        "  test = 1;\n"
        "  send hallo(1) to defaultPort;\n"
        "}\n"
        "source: s1;\n"
        "target: s1;\n"
        "}\n"
        "SignalTransition {\n"
        "name: t3;\n"
        "signal: tschuess;\n"
        "port: defaultPort;\n"
        "guard: lastCondition() && endLoop;\n"
        "action: {\n"
        "  send hallo(2) to defaultPort;\n"
        "}\n"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);

  //QCOMPARE(result, true);
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachine1"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(0));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s1"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  QScxmlStateMachine* machine = QScxmlStateMachine::fromData(&buffer);
  this->initTestEnvironment(machine,&statemachineModel);

  //tester test case
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===0",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===0",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===1",
                                          5000);
  this->_sutTestCompRuntime->addMessageStep(QString("tschuess"),
                                            QLatin1String("defaultPort"));
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          QLatin1String("defaultPort"),
                                          QStringList()<<"x",
                                          "x===2",
                                          5000);

  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer startTimer;
  QObject::connect(&startTimer, &QTimer::timeout,
                   [&machine, this]()
  {
    qDebug()<<"start timeout received!";
    machine->start();
    this->_testCaseRuntime->start();
  });
  startTimer.start(100);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  bool testResult=this->_sutTestCompRuntime->testResult();
  if(!testResult)
  {
    for(auto error : this->_sutTestCompRuntime->errors())
      qDebug()<<"error: "<<error;
  }

  QCOMPARE(testResult, true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  machine->stop();

  delete machine;
  return;
}

void ReadScxmlStatemachineTest::timeoutTrans1()
{
  QString scxmlSource("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                      "<scxml xmlns=\"http://www.w3.org/2005/07/scxml\" version=\"1.0\" binding=\"early\" xmlns:qt=\"http://www.qt.io/2015/02/scxml-ext\" "
                      "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://www.w3.org/2005/07/scxml "
                      "https://www.w3.org/2011/04/SCXML/scxml.xsd\" datamodel=\"ecmascript\" qt:editorversion=\"4.7.0\" initial=\"s1\">"
                      "<state id=\"s1\">"
                      "<onentry>"
                      "<send event=\"timesUp\" delay=\"3s\"/>"
                      "</onentry>"
                      "<transition type=\"internal\" event=\"timesUp\" target=\"s2\">"
                      "</transition>"
                      "</state>"
                      "<final id=\"s2\">"
                      "</final>"
                      "</scxml>");
  QBuffer buffer;

  buffer.setData(scxmlSource.toLatin1());
  buffer.open(QBuffer::ReadWrite);
  buffer.seek(0);

  QScxmlStateMachine* machine = QScxmlStateMachine::fromData(&buffer);

  buffer.close();

  machine->init();
  machine->start();

  QEventLoop loop;
  QTimer timer;
  timer.setSingleShot(true);
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  timer.start(100);
  loop.exec();

  QCOMPARE(machine->activeStateNames(),QStringList({QString("s1")}));

  QEventLoop loop2;
  QTimer timer2;
  timer2.setSingleShot(true);
  connect(&timer2, &QTimer::timeout, &loop2, &QEventLoop::quit);
  timer2.start(5000);
  loop2.exec();

  QCOMPARE(machine->activeStateNames(),QStringList({QString("s2")}));
}

void ReadScxmlStatemachineTest::timeoutTrans2()
{
  QString docText(
        "StateMachine {\n"
        "name: timeout2;\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "}\n"
        "FinalState s2;\n"
        "TimeoutTransition {\n"
        "name: t1;\n"
        "value: 3000.0;"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);

  //QCOMPARE(result, true);
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  QScxmlStateMachine* machine = QScxmlStateMachine::fromData(&buffer);

  buffer.close();

  machine->init();
  machine->start();

  QEventLoop loop;
  QTimer timer;
  timer.setSingleShot(true);
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  timer.start(100);
  loop.exec();

  QCOMPARE(machine->activeStateNames(),QStringList({QString("s1")}));

  QEventLoop loop2;
  QTimer timer2;
  timer2.setSingleShot(true);
  connect(&timer2, &QTimer::timeout, &loop2, &QEventLoop::quit);
  timer2.start(5000);
  loop2.exec();

  QCOMPARE(machine->activeStateNames(),QStringList({QString("s2")}));
}

void ReadScxmlStatemachineTest::timeoutTrans3()
{
  QString docText(
        "StateMachine {\n"
        "name: timeout2;\n"
        //        "Signal hallo();\n"
        "Port defaultPort;\n"
        "Attribute bool endLoop = false;\n"
        //        "Attribute bool tester = false;\n"
        "Signal hallo();\n"
        "initState: s1;\n"
        "SimpleState {\n"
        "name: s1;\n"
        "exit: {"
        "  send hallo();\n"
        "}"
        "}\n"
        "SimpleState {\n"
        "name: s2;\n"
        "entry: endLoop = true;"
        "}\n"
        "FinalState s3;\n"
        "FinalState s4;\n"
        //        "SignalTransition {\n"
        //        "name: t133;\n"
        //        "signal: hallo;\n"
        //        "port: defaultPort;\n"
        //        "source: s1;\n"
        //        "target: s3;\n"
        //        "}\n"
        "TimeoutTransition {\n"
        "name: t14;\n"
        "value: 2000;"
        "guard: endLoop == true;"
        "source: s1;\n"
        "target: s4;\n"
        "}\n"
        "TimeoutTransition {\n"
        "name: t13;\n"
        "value: 4000;"
        "source: s1;\n"
        "target: s3;\n"
        "}\n"
        "TimeoutTransition {\n"
        "name: t12;\n"
        "value: 3000.0;"
        "source: s1;\n"
        "target: s2;\n"
        "}\n"
        "TimeoutTransition {\n"
        "name: t21;\n"
        "value: 1200.0;"
        "source: s2;\n"
        "target: s1;\n"
        "}\n"
        "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;

  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());

  modsim::ComScxmlWriter writer(&statemachineModel);
  QVERIFY(writer.generateDomDocument());
  QBuffer buffer;

  buffer.open(QBuffer::ReadWrite);
  writer.writeScxml(&buffer,&errorString);
  buffer.seek(0);

  QScxmlStateMachine* machine = QScxmlStateMachine::fromData(&buffer);

  this->initTestEnvironment(machine,&statemachineModel);

  _scxmlSutAdapter->connectToEvent(QString("eventHa5F1nishedt14"));//TODO: ??? see runtimeTest for correct using...
  _scxmlSutAdapter->connectToEvent(QString("eventHa5F1nishedt12"));
  _scxmlSutAdapter->connectToEvent(QString("eventHa5F1nishedt21"));
  _scxmlSutAdapter->connectToEvent(QString("eventHa5F1nishedt13"));

  //tester test case
  this->_sutTestCompRuntime->addCheckStep("eventHa5F1nishedt14",
                                          "",
                                          10000);
  this->_sutTestCompRuntime->addCheckStep("eventHa5F1nishedt12",
                                          "",
                                          10000);
  this->_sutTestCompRuntime->addCheckStep("hallo",
                                          "",
                                          10000);
  this->_sutTestCompRuntime->addCheckStep("eventHa5F1nishedt21",
                                          "",
                                          10000);
  this->_sutTestCompRuntime->addCheckStep("eventHa5F1nishedt14",
                                          "",
                                          10000);

  _scxmlSutAdapter->start();


  result=this->_sutTestCompRuntime->prepare(&errorString);
  if(!result)
    qDebug()<<errorString;

  QTimer::singleShot(100, this->_testCaseRuntime,
                     &TestCaseRuntime::start);//should start after this->_testEventLoop->exec()
  this->_testEventLoop->exec();

  QCOMPARE(this->_sutTestCompRuntime->testResult(), true);
  QCOMPARE(this->_sutTestCompRuntime->errors().size(), 0);

  delete machine;
}

QTEST_GUILESS_MAIN(ReadScxmlStatemachineTest)

#include "tst_readscxmlstatemachinetest.moc"
