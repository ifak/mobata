#include <QtTest>

#include <trafficsim/trafficsimmodel.hpp>
#include <trafficsim/combuildtrafficsimmodel.hpp>

#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>

using namespace trafficsim;
using namespace dslparser;

class TrafficSimSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  TrafficSimSyntaxTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void simpleTrafficSimDeclTest_1();
  void simpleTrafficSimDeclTest_2();
  void simpleTrafficSimDeclTest_3();

  void complexTrafficSimDeclTest();

  void simpleCompAttributeDeclTest_1();
  void simpleCompAttributeDeclTest_2();

  void simpleTrafficSimErrorTest_1();
  void simpleTrafficSimErrorTest_2();
  void simpleTrafficSimErrorTest_3();
  void simpleTrafficSimErrorTest_4();
  void simpleTrafficSimErrorTest_5();

  void simpleTrafficSimDeclKeywordTest_1();
  void simpleTrafficSimDeclKeywordTest_2();
};

TrafficSimSyntaxTest::TrafficSimSyntaxTest()
{}
void initResource() {Q_INIT_RESOURCE(complexexamples);}

void TrafficSimSyntaxTest::initTest()
{
    initResource();
}

void TrafficSimSyntaxTest::cleanupTest()
{}

void TrafficSimSyntaxTest::simpleTrafficSimDeclTest_1()
{
  QString docText("TrafficSim{ name: myTrafficSim;}");

  TrafficSimModel trafficsimModel;
  ComBuildTrafficSimModel command(docText, &trafficsimModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTrafficSim"), trafficsimModel.name());
  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimDeclTest_2()
{
  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent { name: Comp1; enabled: false; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");
  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTrafficSim"), trafficsimModel->name());
  QCOMPARE(QString("Comp1"), trafficsimModel->components().at(1)->name());
  QCOMPARE(false,trafficsimModel->components().at(1)->isEnabled());
  QCOMPARE(QString("p1"), trafficsimModel->components().at(1)->ports().at(1)->name());
  QCOMPARE(QString("p2"), trafficsimModel->components().at(1)->ports().at(2)->name());
  QCOMPARE(QString("Comp2"), trafficsimModel->components().at(2)->name());
  QCOMPARE(true,trafficsimModel->components().at(2)->isEnabled());
  QCOMPARE(QString("p3"), trafficsimModel->components().at(2)->ports().at(1)->name());
  QCOMPARE(QString("p4"), trafficsimModel->components().at(2)->ports().at(2)->name());
  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimDeclTest_3()
{
  QString docText("TrafficSim{ name: myTrafficSim; \n Attribute int myAttribute = 10;}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTrafficSim"), trafficsimModel->name());
  QCOMPARE(trafficsimModel->attributes().size(), 1);
  QCOMPARE(QString("myAttribute"), trafficsimModel->attributes().at(0)->name());
  QVERIFY(trafficsimModel->attributes().at(0)->dataType());
  QCOMPARE(QString("int"), trafficsimModel->attributes().at(0)->dataType()->name());
  QCOMPARE(prop::Int, trafficsimModel->attributes().at(0)->dataType()->typeEnum());
  QCOMPARE(QString("10"), trafficsimModel->attributes().at(0)->initValue());

  return;
}

void TrafficSimSyntaxTest::complexTrafficSimDeclTest(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example1.trafficsim";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());

    testSuiteModel.initStandardDataTypes();
    TrafficSimModel trafficsimModel;
    model::ts::SutItem* sutModel=testSuiteModel.sutItem();
    QVERIFY(trafficsimModel);
    ComBuildTrafficSimModel command(docText, trafficsimModel,sutModel,praefix);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());

    QCOMPARE(QString("rse_trafficsim"), trafficsimModel->name());
    QCOMPARE(QString("TrafficSim"), trafficsimModel->components().at(1)->name());
    QCOMPARE(QString("car2X"), trafficsimModel->components().at(2)->name());
    QCOMPARE(QString("monitoring"), trafficsimModel->components().at(3)->name());
    QCOMPARE(QString("pRseApp"), trafficsimModel->components().at(2)->ports().at(1)->name());
    QCOMPARE(QString("pRseApp"), trafficsimModel->components().at(3)->ports().at(1)->name());
    QCOMPARE(QString("test data stimulation and results"), trafficsimModel->links().at(0)->notation());
    QCOMPARE(QString("observe and evaluate"), trafficsimModel->links().at(1)->notation());
    QCOMPARE(QString("pRseApp"), trafficsimModel->links().at(0)->from()->name());
    QCOMPARE(QString("ptrafficsim"), trafficsimModel->links().at(0)->to()->name());
    QCOMPARE(QString("pRseApp"), trafficsimModel->links().at(1)->from()->name());
    QCOMPARE(QString("pEvaluation"), trafficsimModel->links().at(1)->to()->name());

    QCOMPARE(35, command.keywordTextLocations().size());

    QCOMPARE(command.keywordTextLocations().at(0).start(), 0); //import
    QCOMPARE(command.keywordTextLocations().at(0).length(), 6);

    QCOMPARE(command.keywordTextLocations().at(34).start(), 31); //TrafficSim
    QCOMPARE(command.keywordTextLocations().at(34).length(), 10);
    QCOMPARE(command.keywordTextLocations().at(1).start(), 46); //name
    QCOMPARE(command.keywordTextLocations().at(1).length(), 4);
    QCOMPARE(command.keywordTextLocations().at(2).start(), 70); //Attribute
    QCOMPARE(command.keywordTextLocations().at(2).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(3).start(), 80); //string
    QCOMPARE(command.keywordTextLocations().at(3).length(), 6);

    QCOMPARE(command.keywordTextLocations().at(4).start(), 118); //TestComponent
    QCOMPARE(command.keywordTextLocations().at(4).length(), 13);
    QCOMPARE(command.keywordTextLocations().at(5).start(), 139); //name
    QCOMPARE(command.keywordTextLocations().at(5).length(), 4);
    QCOMPARE(command.keywordTextLocations().at(6).start(), 163); //Attribute
    QCOMPARE(command.keywordTextLocations().at(6).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(7).start(), 173); //string
    QCOMPARE(command.keywordTextLocations().at(7).length(), 6);
    QCOMPARE(command.keywordTextLocations().at(8).start(), 214); //Attribute
    QCOMPARE(command.keywordTextLocations().at(8).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(9).start(), 224); //int
    QCOMPARE(command.keywordTextLocations().at(9).length(), 3);
    QCOMPARE(command.keywordTextLocations().at(9).tokenType(), 4);

    QCOMPARE(command.keywordTextLocations().at(10).start(), 251); //TestComponent
    QCOMPARE(command.keywordTextLocations().at(10).length(), 13);
    QCOMPARE(command.keywordTextLocations().at(11).start(), 272); //name
    QCOMPARE(command.keywordTextLocations().at(11).length(), 4);
    QCOMPARE(command.keywordTextLocations().at(12).start(), 291); //enabled
    QCOMPARE(command.keywordTextLocations().at(12).length(), 7);
    QCOMPARE(command.keywordTextLocations().at(13).start(), 313); //Attribute
    QCOMPARE(command.keywordTextLocations().at(13).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(14).start(), 323); //string
    QCOMPARE(command.keywordTextLocations().at(14).length(), 6);
    QCOMPARE(command.keywordTextLocations().at(15).start(), 372); //Attribute
    QCOMPARE(command.keywordTextLocations().at(15).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(16).start(), 382); //int
    QCOMPARE(command.keywordTextLocations().at(16).length(), 3);
    QCOMPARE(command.keywordTextLocations().at(17).start(), 414); //Attribute
    QCOMPARE(command.keywordTextLocations().at(17).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(18).start(), 424); //string
    QCOMPARE(command.keywordTextLocations().at(18).length(), 6);
    QCOMPARE(command.keywordTextLocations().at(19).start(), 475); //Attribute
    QCOMPARE(command.keywordTextLocations().at(19).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(20).start(), 485); //int
    QCOMPARE(command.keywordTextLocations().at(20).length(), 3);
    QCOMPARE(command.keywordTextLocations().at(21).start(), 520); //Port
    QCOMPARE(command.keywordTextLocations().at(21).length(), 4);

    QCOMPARE(command.keywordTextLocations().at(22).start(), 544); //TestComponent
    QCOMPARE(command.keywordTextLocations().at(22).length(), 13);
    QCOMPARE(command.keywordTextLocations().at(23).start(), 565); //name
    QCOMPARE(command.keywordTextLocations().at(23).length(), 4);
    QCOMPARE(command.keywordTextLocations().at(24).start(), 590); //enabled
    QCOMPARE(command.keywordTextLocations().at(24).length(), 7);
    QCOMPARE(command.keywordTextLocations().at(25).start(), 612); //Attribute
    QCOMPARE(command.keywordTextLocations().at(25).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(26).start(), 622); //string
    QCOMPARE(command.keywordTextLocations().at(26).length(), 6);
    QCOMPARE(command.keywordTextLocations().at(27).start(), 663); //Attribute
    QCOMPARE(command.keywordTextLocations().at(27).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(28).start(), 673); //int
    QCOMPARE(command.keywordTextLocations().at(28).length(), 3);
    QCOMPARE(command.keywordTextLocations().at(29).start(), 696); //Attribute
    QCOMPARE(command.keywordTextLocations().at(29).length(), 9);
    QCOMPARE(command.keywordTextLocations().at(30).start(), 706); //int
    QCOMPARE(command.keywordTextLocations().at(30).length(), 3);
    QCOMPARE(command.keywordTextLocations().at(31).start(), 739); //Port
    QCOMPARE(command.keywordTextLocations().at(31).length(), 4);

    QCOMPARE(command.keywordTextLocations().at(32).start(), 762); //Link
    QCOMPARE(command.keywordTextLocations().at(32).length(), 4);
    QCOMPARE(command.keywordTextLocations().at(33).start(), 895); //Link
    QCOMPARE(command.keywordTextLocations().at(33).length(), 4);

    QCOMPARE(17, command.modelTextLocations().size());

    model::base::AttributeItem* attribute_1 = trafficsimModel->attributes().at(0);

    model::base::ComponentItem* component_1 = trafficsimModel->components().at(1);
    model::base::AttributeItem* attribute_2 = component_1->attributes().at(0);
    model::base::AttributeItem* attribute_3 = component_1->attributes().at(1);

    model::base::ComponentItem* component_2 = trafficsimModel->components().at(2);
    model::base::AttributeItem* attribute_4 = component_2->attributes().at(0);
    model::base::AttributeItem* attribute_5 = component_2->attributes().at(1);
    model::base::AttributeItem* attribute_6 = component_2->attributes().at(2);
    model::base::AttributeItem* attribute_7 = component_2->attributes().at(3);
    model::base::PortItem* port1 = component_2->ports().at(1);

    model::base::ComponentItem* component_3 = trafficsimModel->components().at(3);
    model::base::AttributeItem* attribute_8 = component_3->attributes().at(0);
    model::base::AttributeItem* attribute_9 = component_3->attributes().at(1);
    model::base::AttributeItem* attribute_10 = component_3->attributes().at(2);
    model::base::PortItem* port2 = component_3->ports().at(1);

    model::base::LinkItem* link1 = trafficsimModel->links().at(0);
    model::base::LinkItem* link2 = trafficsimModel->links().at(1);

    dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(attribute_1->index());
    QCOMPARE(70, modelTextLocation.start());
    QCOMPARE(113, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());



    modelTextLocation = command.modelTextLocations().value(component_1->index());
    QCOMPARE(118, modelTextLocation.start());
    QCOMPARE(245, modelTextLocation.end());
    QCOMPARE((int)dslparser::TestComponent, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_2->index());
    QCOMPARE(163, modelTextLocation.start());
    QCOMPARE(206, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_3->index());
    QCOMPARE(214, modelTextLocation.start());
    QCOMPARE(239, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());



    modelTextLocation = command.modelTextLocations().value(component_2->index());
    QCOMPARE(251, modelTextLocation.start());
    QCOMPARE(538, modelTextLocation.end());
    QCOMPARE((int)dslparser::TestComponent, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_4->index());
    QCOMPARE(313, modelTextLocation.start());
    QCOMPARE(364, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_5->index());
    QCOMPARE(372, modelTextLocation.start());
    QCOMPARE(406, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_6->index());
    QCOMPARE(414, modelTextLocation.start());
    QCOMPARE(467, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_7->index());
    QCOMPARE(475, modelTextLocation.start());
    QCOMPARE(510, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(port1->index());
    QCOMPARE(525, modelTextLocation.start());
    QCOMPARE(531, modelTextLocation.end());
    QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());



    modelTextLocation = command.modelTextLocations().value(component_3->index());
    QCOMPARE(544, modelTextLocation.start());
    QCOMPARE(757, modelTextLocation.end());
    QCOMPARE((int)dslparser::TestComponent, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_8->index());
    QCOMPARE(612, modelTextLocation.start());
    QCOMPARE(655, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_9->index());
    QCOMPARE(663, modelTextLocation.start());
    QCOMPARE(688, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(attribute_10->index());
    QCOMPARE(696, modelTextLocation.start());
    QCOMPARE(730, modelTextLocation.end());
    QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(port2->index());
    QCOMPARE(744, modelTextLocation.start());
    QCOMPARE(750, modelTextLocation.end());
    QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());



    modelTextLocation = command.modelTextLocations().value(link1->index());
    QCOMPARE(762, modelTextLocation.start());
    QCOMPARE(890, modelTextLocation.end());
    QCOMPARE((int)dslparser::Link, modelTextLocation.tokenType());

    modelTextLocation = command.modelTextLocations().value(link2->index());
    QCOMPARE(895, modelTextLocation.start());
    QCOMPARE(1011, modelTextLocation.end());
    QCOMPARE((int)dslparser::Link, modelTextLocation.tokenType());
}

void TrafficSimSyntaxTest::simpleCompAttributeDeclTest_1()
{
  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2; Attribute int test = 0;}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);

  QString errorString;
  bool result = command.execute(&errorString);
  qDebug()<<"error-string: "<<errorString;
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("myTrafficSim"), trafficsimModel->name());
  QCOMPARE(QString("Comp1"), trafficsimModel->components().at(1)->name());
  QCOMPARE(QString("p1"), trafficsimModel->components().at(1)->ports().at(1)->name());
  QCOMPARE(QString("p2"), trafficsimModel->components().at(1)->ports().at(2)->name());

  QCOMPARE(trafficsimModel->components().at(1)->attributes().size(), 1);
  QCOMPARE(QString("test"), trafficsimModel->components().at(1)->attributes().at(0)->name());
  QVERIFY(trafficsimModel->components().at(1)->attributes().at(0)->dataType());
  QCOMPARE(QString("int"), trafficsimModel->components().at(1)->attributes().at(0)->dataType()->name());
  QCOMPARE(prop::Int, trafficsimModel->components().at(1)->attributes().at(0)->dataType()->typeEnum());
  QCOMPARE(QString("0"), trafficsimModel->components().at(1)->attributes().at(0)->initValue());

  return;
}

void TrafficSimSyntaxTest::simpleCompAttributeDeclTest_2()
{
  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2; Attribute string test = \"testattr\";}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("myTrafficSim"), trafficsimModel->name());
  QCOMPARE(QString("Comp1"), trafficsimModel->components().at(1)->name());
  QCOMPARE(QString("p1"), trafficsimModel->components().at(1)->ports().at(1)->name());
  QCOMPARE(QString("p2"), trafficsimModel->components().at(1)->ports().at(2)->name());

  QCOMPARE(trafficsimModel->components().at(1)->attributes().size(), 1);
  QCOMPARE(QString("test"), trafficsimModel->components().at(1)->attributes().at(0)->name());
  QVERIFY(trafficsimModel->components().at(1)->attributes().at(0)->dataType());
  QCOMPARE(QString("string"), trafficsimModel->components().at(1)->attributes().at(0)->dataType()->name());
  QCOMPARE(prop::String, trafficsimModel->components().at(1)->attributes().at(0)->dataType()->typeEnum());
  QCOMPARE(QString("testattr"), trafficsimModel->components().at(1)->attributes().at(0)->initValue());

  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimErrorTest_1()
{
  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent { name: Comp1;  enabled: true; Port p1,p1;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("There is already a port 'p1' available!"), errorString);
  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimErrorTest_2()
{

  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp1;  enabled: true; \n Port p3; Port p4;}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("There is already a component 'Comp1' available!"), errorString);

  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimErrorTest_3()
{

  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p1; Port p4;}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("missing '{' at 'name'"), errorString);

  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimErrorTest_4()
{

  QString docText("TrafficSim{ name: myTrafficSim; name: myTrafficSim1; \n TestComponent{ name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p1; Port p4;}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("mismatched input 'name' expecting {'TestComponent', 'Link', 'Attribute', '}'}"), errorString);

  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimErrorTest_5()
{

  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent{ name:;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("missing ID at ';'"), errorString);

  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimDeclKeywordTest_1()
{
  QString docText("TrafficSim{ name: myTrafficSim;}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTrafficSim"), trafficsimModel->name());

  QCOMPARE(command.keywordTextLocations().size(), 2);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 0);
  QCOMPARE(command.keywordTextLocations().at(1).length(), 10);
  QCOMPARE(command.keywordTextLocations().at(0).start(), 12);
  QCOMPARE(command.keywordTextLocations().at(0).length(), 4);

  QCOMPARE(0, command.modelTextLocations().size());
  return;
}

void TrafficSimSyntaxTest::simpleTrafficSimDeclKeywordTest_2()
{
  QString docText("TrafficSim{ name: myTrafficSim; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");

  TrafficSimModel trafficsimModel;
  QVERIFY(trafficsimModel);
  ComBuildTrafficSimModel command(docText, &trafficsimModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myTrafficSim"), trafficsimModel->name());

  model::base::ComponentItem* component_1 = trafficsimModel->components().at(1);
  QVERIFY(component_1);
  QCOMPARE(QString("Comp1"), component_1->name());
  QCOMPARE(component_1->ports().size(), 3);//with default port
  model::base::PortItem* port1 = component_1->ports().at(1);
  QCOMPARE(QString("p1"), port1->name());
  model::base::PortItem* port2 = component_1->ports().at(2);
  QCOMPARE(QString("p2"), port2->name());

  model::base::ComponentItem* component_2 = trafficsimModel->components().at(2);
  QVERIFY(component_2);
  QCOMPARE(QString("Comp2"), component_2->name());
  QCOMPARE(component_2->ports().size(), 3);//with default port
  model::base::PortItem* port3 = component_2->ports().at(1);
  QCOMPARE(QString("p3"), port3->name());
  model::base::PortItem* port4 = component_2->ports().at(2);
  QCOMPARE(QString("p4"), port4->name());

  QCOMPARE(11, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(10).start(), 0); //TrafficSim
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

QTEST_APPLESS_MAIN(TrafficSimSyntaxTest)

#include "tst_trafficsimsyntax.moc"
