#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <dslparser/testcase/combuildtestcasemodel.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>

class TestCaseSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  TestCaseSyntaxTest();

private Q_SLOTS:
  void initTestCase();
  void initTest();
  void cleanupTest();
  void simpleTestCaseDeclTest_1();
  void simpleTestCaseDeclTest_2();

  void checkTest();

  void complexTestCaseDeclTest();

  void simpleTestCaseErrorTest_1();
  void simpleTestCaseErrorTest_2();
  void simpleTestCaseErrorTest_3();
  void simpleTestCaseErrorTest_4();
  void simpleTestCaseErrorTest_5();
  void simpleTestCaseErrorTest_6();
  void simpleTestCaseErrorTest_7();
  void simpleTestCaseErrorTest_8();
  void simpleTestCaseErrorTest_9();
  void simpleTestCaseErrorTest_10();

  void simpleTestCaseDeclKeywordTest_1();
  void simpleTestCaseDeclKeywordTest_2();
};

TestCaseSyntaxTest::TestCaseSyntaxTest()
{}

void TestCaseSyntaxTest::initTestCase()
{
  Q_INIT_RESOURCE(complexexamples);
}

void TestCaseSyntaxTest::initTest()
{}

void TestCaseSyntaxTest::cleanupTest()
{}

void TestCaseSyntaxTest::simpleTestCaseDeclTest_1()
{
  QString docText("TestCase{ Declaration {name: myTestCase;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestCase"), testcaseModel->name());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseDeclTest_2()
{
  QString docText(QString("TestCase{ Declaration {name: myTestCase; ")+
                  QString("enabled: true; ")+
                  QString("Attribute int internAttribute = 0;")+
                  QString("Signal stimuli (int x, int y);}}"));
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestCase"), testcaseModel->name());
  QCOMPARE(true, testcaseModel->isEnabled());
  QCOMPARE(QString("internAttribute"),testcaseModel->attributes().at(0)->name());
  QCOMPARE(QString("0"),testcaseModel->attributes().at(0)->initValue());
  QCOMPARE(QString("int"),testcaseModel->attributes().at(0)->dataType());
  QCOMPARE(QString("stimuli"), testcaseModel->getSignals().at(0)->name());
  QCOMPARE(QString("x"), testcaseModel->getSignals().at(0)->params().at(0)->name());
  QCOMPARE(QString("int"), testcaseModel->getSignals().at(0)->params().at(0)->dataType());
  QCOMPARE(QString("y"), testcaseModel->getSignals().at(0)->params().at(1)->name());
  QCOMPARE(QString("int"), testcaseModel->getSignals().at(0)->params().at(1)->dataType());
  return;
}

void TestCaseSyntaxTest::checkTest()
{
  QString docText(
  "import <example1.testsystem> as testsystem\n"
  "TestCase{\n"
  "  Declaration {\n"
  "    name: Gutverhalten;\n"
  "    enabled:  false;\n"
  "    Attribute int retValue = 0;\n"
  "    Signal sendResponse(int retValue);\n"
  "  }\n"
  "  Check(testsystem.monitoring.pRseApp -> sut.RSE_App.pTestSystem): 	sendResponse[true],\n"
  "                                                        timeout: 3s,\n"
  "                                                        accuracy: 0.5;\n"
  "  Check(testsystem.monitoring.pRseApp -> sut.RSE_App.pTestSystem): 	sendResponse[true],\n"
  "                                                        accuracy: 0.5,\n"
  "                                                        timeout: 3s;\n"
  "  Check(testsystem.monitoring.pRseApp -> sut.RSE_App.pTestSystem): 	sendResponse[true],\n"
  "                                                        accuracy: 0.5;\n"
  "  Check(testsystem.monitoring.pRseApp -> sut.RSE_App.pTestSystem): 	sendResponse[true],\n"
  "                                                        timeout: 3s;\n"
  "}");

  QString praefix = ":/Examples/";
  //  model::ts::TestSuite testSuiteModel;
  //  testSuiteModel.initStandardDataTypes();
  model::ts::TestSuite testSuiteModel;
  testSuiteModel.initStandardDataTypes();
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  //signals
  model::base::SignalItem* signal_sendResponseBool = testcaseModel->signal(QString("sendResponse"));
  QVERIFY(signal_sendResponseBool);
  model::base::ParamItem* paramItem =  signal_sendResponseBool->parameter(QString("retValue"));
  QVERIFY(paramItem);

  QCOMPARE(testcaseModel->sequenceItems().size(),4);
  //check1
  model::msc::MscCheckMessageItem* check = (model::msc::MscCheckMessageItem*)testcaseModel->sequenceItems().at(0);//anlageComp, actorComp, "sendResponse"));
  QVERIFY(check);
  QCOMPARE(check->signal(),signal_sendResponseBool);
  QVERIFY(check->paramValues().first());
  QCOMPARE(check->paramValues().first()->value().toBool(),true);
  QCOMPARE(check->timeout(),3000);
  QCOMPARE(check->accuracy(),0.5);

  //check2
  check = (model::msc::MscCheckMessageItem*)testcaseModel->sequenceItems().at(1);//anlageComp, actorComp, "sendResponse"));QVERIFY(check);
  QCOMPARE(check->signal(),signal_sendResponseBool);
  QVERIFY(check->paramValues().first());
  QCOMPARE(check->paramValues().first()->value().toBool(),true);
  QCOMPARE(check->timeout(),3000);
  QCOMPARE(check->accuracy(),0.5);

  //check3
  check = (model::msc::MscCheckMessageItem*)testcaseModel->sequenceItems().at(2);//anlageComp, actorComp, "sendResponse"));QVERIFY(check);
  QCOMPARE(check->signal(),signal_sendResponseBool);
  QVERIFY(check->paramValues().first());
  QCOMPARE(check->paramValues().first()->value().toBool(),true);
  QCOMPARE(check->timeout(),-1);
  QCOMPARE(check->accuracy(),0.5);

  //check4
  check = (model::msc::MscCheckMessageItem*)testcaseModel->sequenceItems().at(3);//anlageComp, actorComp, "sendResponse"));QVERIFY(check);
  QCOMPARE(check->signal(),signal_sendResponseBool);
  QVERIFY(check->paramValues().first());
  QCOMPARE(check->paramValues().first()->value().toBool(),true);
  QCOMPARE(check->timeout(),3000);
  QCOMPARE(check->accuracy(),0.0);

}

void TestCaseSyntaxTest::complexTestCaseDeclTest(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_4.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  testSuiteModel.initStandardDataTypes();
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(28, command.keywordTextLocations().size());
  QCOMPARE(16, command.modelTextLocations().size());

  typedef model::msc::MscTimerItem* TimerItem;
  typedef model::msc::MscSequenceItem* SeqItem;
  typedef model::base::AttributeItem* AttItem;
  typedef model::base::SignalItem* SigItem;
  typedef model::msc::MscMessageItem* MesItem;
  typedef model::msc::MscFragmentItem* AltItem;
  typedef model::msc::MscFragmentRegionItem* RegItem;
  typedef model::msc::MscCheckMessageItem* CheckItem;
  typedef model::msc::MscStatementItem* StateItem;

  AttItem attribute_1 = testcaseModel->attributes().at(0);
  AttItem attribute_2 = testcaseModel->attributes().at(1);
  AttItem attribute_3 = testcaseModel->attributes().at(2);
  AttItem attribute_4 = testcaseModel->attributes().at(3);

  SigItem signal1 = testcaseModel->getSignals().at(0);
  SigItem signal2 = testcaseModel->getSignals().at(1);
  SigItem signal3 = testcaseModel->getSignals().at(2);

  QVERIFY(dynamic_cast<TimerItem>((SeqItem)testcaseModel->sequenceItems().at(0)));
  TimerItem timer1 = dynamic_cast<TimerItem>((SeqItem)testcaseModel->sequenceItems().at(0));
  QVERIFY(dynamic_cast<StateItem>((SeqItem)testcaseModel->sequenceItems().at(1)));
  StateItem state1 = dynamic_cast<StateItem>((SeqItem)testcaseModel->sequenceItems().at(1));
  QVERIFY(dynamic_cast<MesItem>((SeqItem)testcaseModel->sequenceItems().at(2)));
  MesItem message1 = dynamic_cast<MesItem>((SeqItem)testcaseModel->sequenceItems().at(2));
  QVERIFY(dynamic_cast<CheckItem>((SeqItem)testcaseModel->sequenceItems().at(3)));
  CheckItem check1 = dynamic_cast<CheckItem>((SeqItem)testcaseModel->sequenceItems().at(3));

  QCOMPARE(message1->targetPort()->name(),QString("pTestSystem"));
  QCOMPARE(message1->sourcePort()->name(),QString("pRseApp"));
  QCOMPARE(message1->paramValues().size(),2);
  QCOMPARE(message1->paramValues().at(0)->param()->name(),QString("x"));
  QCOMPARE(message1->paramValues().at(0)->value(),QVariant(10));
  QCOMPARE(message1->paramValues().at(1)->param()->name(),QString("y"));
  QCOMPARE(message1->paramValues().at(1)->value(),QVariant(20));

  QCOMPARE(check1->targetPort()->name(),QString("pRseApp"));
  QCOMPARE(check1->sourcePort()->name(),QString("pEvaluation"));

  QCOMPARE(check1->paramValues().isEmpty(), false);
  QCOMPARE(check1->paramValues().first()->value(),true);
  QCOMPARE(check1->timeout(), 300);



  dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(testcaseModel->index());
  QCOMPARE((int)dslparser::TestCase, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(attribute_1->index());
  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(attribute_2->index());
  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(attribute_3->index());
  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(attribute_4->index());
  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(signal1->index());
  QCOMPARE((int)dslparser::Signal, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(signal2->index());
  QCOMPARE((int)dslparser::Signal, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(signal3->index());
  QCOMPARE((int)dslparser::Signal, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(timer1->index());
  QCOMPARE((int)dslparser::Timer, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(state1->index());
  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(message1->index());
  QCOMPARE((int)dslparser::Message, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(check1->index());
  QCOMPARE((int)dslparser::Check, modelTextLocation.tokenType());

  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_1()
{
  QString docText("TestCase{ Declaration {name: testcase_4; enabled:  false;} Timer@testsystem.car2X defaultTimer = 500 ms;}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());
  QCOMPARE(QString("Incorrect Path to Component!Incorrect Path to Component!"), errorString);
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_2()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_5.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(11, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_3()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_6.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(command.errors().count(), 12);
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_4()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_7.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(12, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_5()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_8.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(14, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_6()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_9.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(12, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_7()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_10.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(12, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_8()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_11.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(11, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_9()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_12.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(11, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseErrorTest_10()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_testcase_13.testcase";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QCOMPARE(result, false);
  QCOMPARE(12, command.errors().count());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseDeclKeywordTest_1()
{
  QString docText("TestCase{ Declaration {name: myTestCase;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"));
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestCase"), testcaseModel->name());

  QCOMPARE(command.keywordTextLocations().size(), 3);
  QCOMPARE(command.keywordTextLocations().at(0).start(), 0); //Testcase
  QCOMPARE(command.keywordTextLocations().at(0).length(), 8);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 10); //Declaration
  QCOMPARE(command.keywordTextLocations().at(1).length(), 11);
  QCOMPARE(command.keywordTextLocations().at(2).start(), 23); //name
  QCOMPARE(command.keywordTextLocations().at(2).length(), 4);

  QCOMPARE(1, command.modelTextLocations().size());
  return;
}

void TestCaseSyntaxTest::simpleTestCaseDeclKeywordTest_2()
{
  /*
  QString docText("TestCase{ name: myTestCase; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  QString errorString1;
  model::ts::TestCaseItem* testcaseModel=testSuiteModel.addTestCase(QString("test"),&errorString1);
  QVERIFY(testcaseModel);
  dslparser::testcase::ComBuildTestCaseModel command(docText, testcaseModel, nullptr);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestCase"), testcaseModel->name());

  model::base::ComponentItem* component_1 = testcaseModel->components().at(1);
  QVERIFY(component_1);
  QCOMPARE(QString("Comp1"), component_1->name());
  QCOMPARE(component_1->ports().size(), 3);//with default port
  model::base::PortItem* port1 = component_1->ports().at(1);
  QCOMPARE(QString("p1"), port1->name());
  model::base::PortItem* port2 = component_1->ports().at(2);
  QCOMPARE(QString("p2"), port2->name());

  model::base::ComponentItem* component_2 = testcaseModel->components().at(2);
  QVERIFY(component_2);
  QCOMPARE(QString("Comp2"), component_2->name());
  QCOMPARE(component_2->ports().size(), 3);//with default port
  model::base::PortItem* port3 = component_2->ports().at(1);
  QCOMPARE(QString("p3"), port3->name());
  model::base::PortItem* port4 = component_2->ports().at(2);
  QCOMPARE(QString("p4"), port4->name());

  QCOMPARE(11, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(10).start(), 0); //TestCase
  QCOMPARE(command.keywordTextLocations().at(10).length(), 10);
  QCOMPARE(command.keywordTextLocations().at(0).start(), 12); //name
  QCOMPARE(command.keywordTextLocations().at(0).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 34); //TestComp
  QCOMPARE(command.keywordTextLocations().at(1).length(), 13);
  QCOMPARE(command.keywordTextLocations().at(2).start(), 50); //name
  QCOMPARE(command.keywordTextLocations().at(2).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(3).start(), 64); //enabled
  QCOMPARE(command.keywordTextLocations().at(3).length(), 7);
  QCOMPARE(command.keywordTextLocations().at(4).start(), 79); //Port
  QCOMPARE(command.keywordTextLocations().at(4).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(5).start(), 94); //TestComp
  QCOMPARE(command.keywordTextLocations().at(5).length(), 13);
  QCOMPARE(command.keywordTextLocations().at(6).start(), 110); //name
  QCOMPARE(command.keywordTextLocations().at(6).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(7).start(), 124); //enabled
  QCOMPARE(command.keywordTextLocations().at(7).length(), 7);
  QCOMPARE(command.keywordTextLocations().at(8).start(), 141); //Port
  QCOMPARE(command.keywordTextLocations().at(8).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(9).start(), 150); //Port
  QCOMPARE(command.keywordTextLocations().at(9).length(), 4);

  QCOMPARE(6, command.modelTextLocations().size());

  dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(component_1->index());
  QCOMPARE(34, modelTextLocation.start());
  QCOMPARE(90, modelTextLocation.end());
  QCOMPARE((int)dslparser::TestComponent, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port1->index());
  QCOMPARE(84, modelTextLocation.start());
  QCOMPARE(85, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port2->index());
  QCOMPARE(87, modelTextLocation.start());
  QCOMPARE(88, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(component_2->index());
  QCOMPARE(94, modelTextLocation.start());
  QCOMPARE(158, modelTextLocation.end());
  QCOMPARE((int)dslparser::TestComponent, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port3->index());
  QCOMPARE(146, modelTextLocation.start());
  QCOMPARE(147, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port4->index());
  QCOMPARE(155, modelTextLocation.start());
  QCOMPARE(156, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());*/
  return;
}

QTEST_GUILESS_MAIN(TestCaseSyntaxTest)

#include "tst_testcasesyntax.moc"
