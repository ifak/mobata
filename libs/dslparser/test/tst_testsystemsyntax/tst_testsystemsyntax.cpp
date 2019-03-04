#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <dslparser/testsystem/combuildtestsystemmodel.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>

class TestSystemSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  TestSystemSyntaxTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void simpleTestSystemDeclTest_1();
  void simpleTestSystemDeclTest_2();
  void simpleTestSystemDeclTest_3();

  void complexTestSystemDeclTest();

  void simpleCompAttributeDeclTest_1();
  void simpleCompAttributeDeclTest_2();

  void simpleTestSystemErrorTest_1();
  void simpleTestSystemErrorTest_2();
  void simpleTestSystemErrorTest_3();
  void simpleTestSystemErrorTest_4();
  void simpleTestSystemErrorTest_5();

  void simpleTestSystemDeclKeywordTest_1();
  void simpleTestSystemDeclKeywordTest_2();
};

TestSystemSyntaxTest::TestSystemSyntaxTest()
{}
void initResource() {Q_INIT_RESOURCE(complexexamples);}

void TestSystemSyntaxTest::initTest()
{
    initResource();
}

void TestSystemSyntaxTest::cleanupTest()
{}

void TestSystemSyntaxTest::simpleTestSystemDeclTest_1()
{
  QString docText("TestSystem{ name: myTestSystem;}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(command.errors().count(), 0);
  QCOMPARE(testsystemModel->name(), QString("myTestSystem"));
  return;
}

void TestSystemSyntaxTest::simpleTestSystemDeclTest_2()
{
  QString docText("TestSystem{ name: myTestSystem; \n TestComponent { name: Comp1; enabled: false; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestSystem"), testsystemModel->name());
  QCOMPARE(QString("Comp1"), testsystemModel->components().at(1)->name());
  QCOMPARE(false,testsystemModel->components().at(1)->isEnabled());
  QCOMPARE(QString("p1"), testsystemModel->components().at(1)->ports().at(1)->name());
  QCOMPARE(QString("p2"), testsystemModel->components().at(1)->ports().at(2)->name());
  QCOMPARE(QString("Comp2"), testsystemModel->components().at(2)->name());
  QCOMPARE(true,testsystemModel->components().at(2)->isEnabled());
  QCOMPARE(QString("p3"), testsystemModel->components().at(2)->ports().at(1)->name());
  QCOMPARE(QString("p4"), testsystemModel->components().at(2)->ports().at(2)->name());
  return;
}

void TestSystemSyntaxTest::simpleTestSystemDeclTest_3()
{
  QString docText("TestSystem{ name: myTestSystem; \n Attribute int myAttribute = 10;}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestSystem"), testsystemModel->name());
  QCOMPARE(testsystemModel->attributes().size(), 1);
  QCOMPARE(QString("myAttribute"), testsystemModel->attributes().at(0)->name());
  QCOMPARE(QString("int"), testsystemModel->attributes().at(0)->dataType());
  QCOMPARE(QString("10"), testsystemModel->attributes().at(0)->initValue());

  return;
}

void TestSystemSyntaxTest::complexTestSystemDeclTest(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1.testsystem";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    model::ts::TestSuite testSuiteModel;
    testSuiteModel.initStandardDataTypes();
    model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
    QVERIFY(testsystemModel);
    dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel,praefix);

    QString errorString;
    bool result = command.execute(&errorString);
    if(!result)
      qDebug()<<errorString;
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());

    QCOMPARE(QString("rse_testsystem"), testsystemModel->name());
    QCOMPARE(QString("trafficSim"), testsystemModel->components().at(1)->name());
    QCOMPARE(QString("car2X"), testsystemModel->components().at(2)->name());
    QCOMPARE(QString("monitoring"), testsystemModel->components().at(3)->name());
    QCOMPARE(QString("pRseApp"), testsystemModel->components().at(2)->ports().at(1)->name());
    QCOMPARE(QString("pRseApp"), testsystemModel->components().at(3)->ports().at(1)->name());
    QCOMPARE(QString("test data stimulation and results"), testsystemModel->links().at(0)->notation());
    QCOMPARE(QString("observe and evaluate"), testsystemModel->links().at(1)->notation());
    QCOMPARE(QString("pRseApp"), testsystemModel->links().at(0)->from()->name());
    QCOMPARE(QString("pTestSystem"), testsystemModel->links().at(0)->to()->name());
    QCOMPARE(QString("pRseApp"), testsystemModel->links().at(1)->from()->name());
    QCOMPARE(QString("pEvaluation"), testsystemModel->links().at(1)->to()->name());

    QCOMPARE(41, command.keywordTextLocations().size());
    QCOMPARE(19, command.modelTextLocations().size());

    return;
}

void TestSystemSyntaxTest::simpleCompAttributeDeclTest_1()
{
  QString docText("TestSystem{ name: myTestSystem; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2; Attribute int test = 0;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  qDebug()<<"error-string: "<<errorString;
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("myTestSystem"), testsystemModel->name());
  QCOMPARE(QString("Comp1"), testsystemModel->components().at(1)->name());
  QCOMPARE(QString("p1"), testsystemModel->components().at(1)->ports().at(1)->name());
  QCOMPARE(QString("p2"), testsystemModel->components().at(1)->ports().at(2)->name());

  QCOMPARE(testsystemModel->components().at(1)->attributes().size(), 1);
  QCOMPARE(QString("test"), testsystemModel->components().at(1)->attributes().at(0)->name());
  QCOMPARE(QString("int"), testsystemModel->components().at(1)->attributes().at(0)->dataType());
  QCOMPARE(QString("0"), testsystemModel->components().at(1)->attributes().at(0)->initValue());

  return;
}

void TestSystemSyntaxTest::simpleCompAttributeDeclTest_2()
{
  QString docText("TestSystem{ name: myTestSystem; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2; Attribute string test = \"testattr\";}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("myTestSystem"), testsystemModel->name());
  QCOMPARE(QString("Comp1"), testsystemModel->components().at(1)->name());
  QCOMPARE(QString("p1"), testsystemModel->components().at(1)->ports().at(1)->name());
  QCOMPARE(QString("p2"), testsystemModel->components().at(1)->ports().at(2)->name());

  QCOMPARE(testsystemModel->components().at(1)->attributes().size(), 1);
  QCOMPARE(QString("test"), testsystemModel->components().at(1)->attributes().at(0)->name());
  QCOMPARE(QString("string"), testsystemModel->components().at(1)->attributes().at(0)->dataType());
  QCOMPARE(QString("testattr"), testsystemModel->components().at(1)->attributes().at(0)->initValue());

  return;
}

void TestSystemSyntaxTest::simpleTestSystemErrorTest_1()
{
  QString docText("TestSystem{ name: myTestSystem; \n TestComponent { name: Comp1;  enabled: true; Port p1,p1;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("There is already a port 'p1' available!"), errorString);
  return;
}

void TestSystemSyntaxTest::simpleTestSystemErrorTest_2()
{

  QString docText("TestSystem{ name: myTestSystem; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp1;  enabled: true; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("There is already a component 'Comp1' available!"), errorString);

  return;
}

void TestSystemSyntaxTest::simpleTestSystemErrorTest_3()
{

  QString docText("TestSystem{ name: myTestSystem; \n TestComponent name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p1; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("missing '{' at 'name'"), errorString);

  return;
}

void TestSystemSyntaxTest::simpleTestSystemErrorTest_4()
{

  QString docText("TestSystem{ name: myTestSystem; name: myTestSystem1; \n TestComponent{ name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p1; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(command.errors().count(), 1);
  //QCOMPARE(QString("no viable alternative at input 'name'mismatches input 'TestComponent' expecting <EOF>"), errorString);

  return;
}

void TestSystemSyntaxTest::simpleTestSystemErrorTest_5()
{

  QString docText("TestSystem{\n"
                  " name: myTestSystem; \n"
                  " TestComponent{ name:;  enabled: true; Port p1,p2;} \n"
                  " TestComponent { name: Comp2;  enabled: true; \n"
                  "                  Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"dsl-error at line: "<<error.line()<<" and pos: "<<error.charPositionInLine()<<" with message: "<<error.message();
  QCOMPARE(command.errors().count(), 2);

  return;
}

void TestSystemSyntaxTest::simpleTestSystemDeclKeywordTest_1()
{
  QString docText("TestSystem{ name: myTestSystem;}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestSystem"), testsystemModel->name());

  QCOMPARE(command.keywordTextLocations().size(), 2);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 0);
  QCOMPARE(command.keywordTextLocations().at(1).length(), 10);
  QCOMPARE(command.keywordTextLocations().at(0).start(), 12);
  QCOMPARE(command.keywordTextLocations().at(0).length(), 4);

  QCOMPARE(0, command.modelTextLocations().size());
  return;
}

void TestSystemSyntaxTest::simpleTestSystemDeclKeywordTest_2()
{
  QString docText("TestSystem{ name: myTestSystem; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::TestSystemItem* testsystemModel=testSuiteModel.testSystemItem();
  QVERIFY(testsystemModel);
  dslparser::testsystem::ComBuildTestSystemModel command(docText, testsystemModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTestSystem"), testsystemModel->name());

  model::base::ComponentItem* component_1 = testsystemModel->components().at(1);
  QVERIFY(component_1);
  QCOMPARE(QString("Comp1"), component_1->name());
  QCOMPARE(component_1->ports().size(), 3);//with default port
  model::base::PortItem* port1 = component_1->ports().at(1);
  QCOMPARE(QString("p1"), port1->name());
  model::base::PortItem* port2 = component_1->ports().at(2);
  QCOMPARE(QString("p2"), port2->name());

  model::base::ComponentItem* component_2 = testsystemModel->components().at(2);
  QVERIFY(component_2);
  QCOMPARE(QString("Comp2"), component_2->name());
  QCOMPARE(component_2->ports().size(), 3);//with default port
  model::base::PortItem* port3 = component_2->ports().at(1);
  QCOMPARE(QString("p3"), port3->name());
  model::base::PortItem* port4 = component_2->ports().at(2);
  QCOMPARE(QString("p4"), port4->name());

  QCOMPARE(11, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(10).start(), 0); //TestSystem
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
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());
  return;
}

QTEST_GUILESS_MAIN(TestSystemSyntaxTest)

#include "tst_testsystemsyntax.moc"
