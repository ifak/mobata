#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <dslparser/sut/combuildsutmodel.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>

class SutSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  SutSyntaxTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void simpleSutDeclTest_1();
  void simpleSutDeclTest_2();
  void simpleSutDeclTest_3();

  void simpleCompAttributeDeclTest_1();
  void simpleCompAttributeDeclTest_2();

  void simpleSutErrorTest_1();
  void simpleSutErrorTest_2();
  void simpleSutErrorTest_3();
  void simpleSutErrorTest_4();
  void simpleSutErrorTest_5();

  void simpleSutDeclKeywordTest_1();
  void simpleSutDeclKeywordTest_2();
};

SutSyntaxTest::SutSyntaxTest()
{}

void SutSyntaxTest::initTest()
{}

void SutSyntaxTest::cleanupTest()
{}

void SutSyntaxTest::simpleSutDeclTest_1()
{
  QString docText("Sut{ name: mySut;}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mySut"), sutModel->name());
  return;
}

void SutSyntaxTest::simpleSutDeclTest_2()
{
  QString docText("Sut{ name: mySut; \n SutComponent { name: Comp1; Port p1,p2;} \n SutComponent { name: Comp2; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mySut"), sutModel->name());
  QCOMPARE(QString("Comp1"), sutModel->components().at(0)->name());
  QCOMPARE(QString("p1"), sutModel->components().at(0)->ports().at(1)->name());
  QCOMPARE(QString("p2"), sutModel->components().at(0)->ports().at(2)->name());
  QCOMPARE(QString("Comp2"), sutModel->components().at(1)->name());
  QCOMPARE(QString("p3"), sutModel->components().at(1)->ports().at(1)->name());
  QCOMPARE(QString("p4"), sutModel->components().at(1)->ports().at(2)->name());
  return;
}

void SutSyntaxTest::simpleSutDeclTest_3()
{
  QString docText("Sut{ name: mySut; \n Attribute int myAttribute = 10;}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mySut"), sutModel->name());
  QCOMPARE(sutModel->attributes().size(), 1);
  QCOMPARE(QString("myAttribute"), sutModel->attributes().at(0)->name());
  QCOMPARE(QString("int"), sutModel->attributes().at(0)->dataType());
  QCOMPARE(QString("10"), sutModel->attributes().at(0)->initValue());

  return;
}

void SutSyntaxTest::simpleCompAttributeDeclTest_1()
{
  QString docText("Sut{ name: mySut; \n SutComponent { name: Comp1; Port p1,p2; Attribute int test = 0;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);

  QString errorString;
  bool result = command.execute(&errorString);
  qDebug()<<"error-string: "<<errorString;
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("mySut"), sutModel->name());
  QCOMPARE(QString("Comp1"), sutModel->components().at(0)->name());
  QCOMPARE(QString("p1"), sutModel->components().at(0)->ports().at(1)->name());
  QCOMPARE(QString("p2"), sutModel->components().at(0)->ports().at(2)->name());

  QCOMPARE(sutModel->components().at(0)->attributes().size(), 1);
  QCOMPARE(QString("test"), sutModel->components().at(0)->attributes().at(0)->name());
  QCOMPARE(QString("int"), sutModel->components().at(0)->attributes().at(0)->dataType());
  QCOMPARE(QString("0"), sutModel->components().at(0)->attributes().at(0)->initValue());

  return;
}

void SutSyntaxTest::simpleCompAttributeDeclTest_2()
{
  QString docText("Sut{ name: mySut; \n SutComponent { name: Comp1; Port p1,p2; Attribute string test = \"testattr\";}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("mySut"), sutModel->name());
  QCOMPARE(QString("Comp1"), sutModel->components().at(0)->name());
  QCOMPARE(QString("p1"), sutModel->components().at(0)->ports().at(1)->name());
  QCOMPARE(QString("p2"), sutModel->components().at(0)->ports().at(2)->name());

  QCOMPARE(sutModel->components().at(0)->attributes().size(), 1);
  QCOMPARE(QString("test"), sutModel->components().at(0)->attributes().at(0)->name());
  QCOMPARE(QString("string"), sutModel->components().at(0)->attributes().at(0)->dataType());
  QCOMPARE(QString("testattr"), sutModel->components().at(0)->attributes().at(0)->initValue());

  return;
}

void SutSyntaxTest::simpleSutErrorTest_1()
{
  QString docText("Sut{ name: mySut; \n SutComponent { name: Comp1; Port p1,p1;} \n SutComponent { name: Comp2; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("There is already a port 'p1' available!"), errorString);
  return;
}

void SutSyntaxTest::simpleSutErrorTest_2()
{

  QString docText("Sut{ name: mySut; \n SutComponent { name: Comp1; Port p1,p2;} \n SutComponent { name: Comp1; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("There is already a component 'Comp1' available!"), errorString);

  return;
}

void SutSyntaxTest::simpleSutErrorTest_3()
{

  QString docText("Sut{ name: mySut; \n SutComponent name: Comp1; Port p1,p2;} \n SutComponent { name: Comp2; \n Port p1; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("missing '{' at 'name'"), errorString);

  return;
}

void SutSyntaxTest::simpleSutErrorTest_4()
{

  QString docText("Sut{ name: mySut; name: mySut1; \n SutComponent{ name: Comp1; Port p1,p2;} \n SutComponent { name: Comp2; \n Port p1; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("no viable alternative at input 'name'"), errorString);

  return;
}

void SutSyntaxTest::simpleSutErrorTest_5()
{

  QString docText("Sut{ name: mySut; \n"
                  " SutComponent{\n"
                  "   name:;\n"
                  "   Port p1,p2;\n"
                  " } \n"
                  " SutComponent { \n"
                  "   name: Comp2; \n "
                  "   Port p3; Port p4;\n"
                  " }\n"
                  "}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());

  return;
}

void SutSyntaxTest::simpleSutDeclKeywordTest_1()
{
  QString docText("Sut{ name: mySut;}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mySut"), sutModel->name());

  QCOMPARE(command.keywordTextLocations().size(), 2);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 0);
  QCOMPARE(command.keywordTextLocations().at(1).length(), 3);
  QCOMPARE(command.keywordTextLocations().at(0).start(), 5);
  QCOMPARE(command.keywordTextLocations().at(0).length(), 4);

  QCOMPARE(0, command.modelTextLocations().size());
  return;
}

void SutSyntaxTest::simpleSutDeclKeywordTest_2()
{
  QString docText("Sut{ name: mySut; \n SutComponent { name: Comp1; Port p1,p2;} \n SutComponent { name: Comp2; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  model::ts::SutItem* sutModel=testSuiteModel.sutItem();
  QVERIFY(sutModel);
  dslparser::sut::ComBuildSutModel command(docText, sutModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mySut"), sutModel->name());

  model::base::ComponentItem* component_1 = sutModel->components().at(0);
  QVERIFY(component_1);
  QCOMPARE(QString("Comp1"), component_1->name());
  QCOMPARE(component_1->ports().size(), 3);//with default port
  model::base::PortItem* port1 = component_1->ports().at(1);
  QCOMPARE(QString("p1"), port1->name());
  model::base::PortItem* port2 = component_1->ports().at(2);
  QCOMPARE(QString("p2"), port2->name());

  model::base::ComponentItem* component_2 = sutModel->components().at(1);
  QVERIFY(component_2);
  QCOMPARE(QString("Comp2"), component_2->name());
  QCOMPARE(component_2->ports().size(), 3);//with default port
  model::base::PortItem* port3 = component_2->ports().at(1);
  QCOMPARE(QString("p3"), port3->name());
  model::base::PortItem* port4 = component_2->ports().at(2);
  QCOMPARE(QString("p4"), port4->name());

  QCOMPARE(9, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(8).start(), 0); //Sut
  QCOMPARE(command.keywordTextLocations().at(8).length(), 3);
  QCOMPARE(command.keywordTextLocations().at(0).start(), 5); //name
  QCOMPARE(command.keywordTextLocations().at(0).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 20); //SutComp
  QCOMPARE(command.keywordTextLocations().at(1).length(), 12);
  QCOMPARE(command.keywordTextLocations().at(2).start(), 35); //name
  QCOMPARE(command.keywordTextLocations().at(2).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(3).start(), 48); //Port
  QCOMPARE(command.keywordTextLocations().at(3).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(4).start(), 63); //SutComp
  QCOMPARE(command.keywordTextLocations().at(4).length(), 12);
  QCOMPARE(command.keywordTextLocations().at(5).start(), 78); //name
  QCOMPARE(command.keywordTextLocations().at(5).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(6).start(), 93); //Port
  QCOMPARE(command.keywordTextLocations().at(6).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(7).start(), 102); //Port
  QCOMPARE(command.keywordTextLocations().at(7).length(), 4);

  QCOMPARE(6, command.modelTextLocations().size());

  dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(component_1->index());
  QCOMPARE(20, modelTextLocation.start());
  QCOMPARE(59, modelTextLocation.end());
  QCOMPARE((int)dslparser::SutComponent, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port1->index());
  QCOMPARE(53, modelTextLocation.start());
  QCOMPARE(54, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port2->index());
  QCOMPARE(56, modelTextLocation.start());
  QCOMPARE(57, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(component_2->index());
  QCOMPARE(63, modelTextLocation.start());
  QCOMPARE(110, modelTextLocation.end());
  QCOMPARE((int)dslparser::SutComponent, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port3->index());
  QCOMPARE(98, modelTextLocation.start());
  QCOMPARE(99, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

  modelTextLocation = command.modelTextLocations().value(port4->index());
  QCOMPARE(107, modelTextLocation.start());
  QCOMPARE(108, modelTextLocation.end());
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());
  return;
}

QTEST_GUILESS_MAIN(SutSyntaxTest)

#include "tst_sutsyntax.moc"
