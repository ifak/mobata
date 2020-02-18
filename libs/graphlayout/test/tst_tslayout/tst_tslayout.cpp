#include <QtTest/QTest>

#include <graphlayout/layoutgraph.hpp>
#include <graphlayout/layoutnode.hpp>
#include <graphlayout/layoutedge.hpp>
#include <graphlayout/graphquickwidget.hpp>
#include <graphlayout/comgraphts.hpp>
#include <mobata/model/ts/sutitem.hpp>
#include <mobata/model/ts/ts.hpp>

#include <QQuickWidget>
#include <QQuickItem>

class TsLayoutTest
    : public QObject
{
  Q_OBJECT

public:
  TsLayoutTest();

private Q_SLOTS:
  void initTestCase();
  void LayoutGraphCreationTest();
};

TsLayoutTest::TsLayoutTest()
{}

void TsLayoutTest::initTestCase()
{
  Q_INIT_RESOURCE(graphlayout);
}

void TsLayoutTest::LayoutGraphCreationTest()
{
  using namespace model::ts;
  using namespace model::base;

  SutItem* myItem = new SutItem();

  QString errorString;

  SutComponentItem* mySUTComponent1 = myItem->addComponent<SutComponentItem>(("t1"), &errorString);
  QVERIFY(mySUTComponent1);
  QVERIFY(errorString == "");
  mySUTComponent1->removePortById(mySUTComponent1->ports().first()->uuid());
  mySUTComponent1->addPort("P1_1");
  mySUTComponent1->addPort("P1_2");
  mySUTComponent1->addPort("P1_3");
  SutComponentItem* mySUTComponent2 = myItem->addComponent<SutComponentItem>(("t2"), &errorString);
  QVERIFY(mySUTComponent2);
  QVERIFY(errorString == "");
  mySUTComponent2->removePortById(mySUTComponent2->ports().first()->uuid());
  mySUTComponent2->addPort("P2_1");
  mySUTComponent2->addPort("P2_2");
  mySUTComponent2->addPort("P2_3");
  SutComponentItem* mySUTComponent3 = myItem->addComponent<SutComponentItem>(("t3"), &errorString);
  QVERIFY(mySUTComponent3);
  QVERIFY(errorString == "");
  mySUTComponent3->removePortById(mySUTComponent3->ports().first()->uuid());
  mySUTComponent3->addPort("P3_1");
  mySUTComponent3->addPort("P3_2");
  mySUTComponent3->addPort("P3_3");

  myItem->addLink(mySUTComponent1->ports()[0],mySUTComponent2->ports()[0]);
  myItem->addLink(mySUTComponent2->ports()[1],mySUTComponent3->ports()[0]);
  myItem->addLink(mySUTComponent3->ports()[1],mySUTComponent1->ports()[1]);



  TestSystemItem* myMainItem = new TestSystemItem(myItem);
  myMainItem->removeComponentByID(myMainItem->components().first()->uuid());

  TestComponentItem* myTSComponent1 = myMainItem->addComponent<TestComponentItem>(("o1"), &errorString);
  QVERIFY(errorString == "");
  QVERIFY(myTSComponent1);
  TestComponentItem* myTSComponent2 = myMainItem->addComponent<TestComponentItem>(("o2"), &errorString);
  QVERIFY(errorString == "");
  QVERIFY(myTSComponent2);
  TestComponentItem* myTSComponent3 = myMainItem->addComponent<TestComponentItem>(("o3"), &errorString);
  QVERIFY(errorString == "");
  QVERIFY(myTSComponent3);

  myMainItem->addLink(myTSComponent1->ports().first(),mySUTComponent1->ports()[2]);
  myMainItem->addLink(myTSComponent2->ports().first(),mySUTComponent2->ports()[2]);
  myMainItem->addLink(myTSComponent3->ports().first(),mySUTComponent3->ports()[2]);


  graphlayout::LayoutGraph* graph = new graphlayout::LayoutGraph("graph1");
  graphlayout::ComGraphTS comGraph(graph,myMainItem);
  comGraph.execute();

  //!--------------------------------------------------------------------------
  //! TS -> Graph test
  //!--------------------------------------------------------------------------

  QCOMPARE(graph->allNodes().length()+graph->allPorts().length(),19);
  QCOMPARE(graph->edges().length(),6);


  //!--------------------------------------------------------------------------

  graphlayout::GraphQuickWidget* widget = new graphlayout::GraphQuickWidget(graph,graphlayout::Fdp);
  widget->resize(QSize(500,500));
  QString error;
  widget->layout(&error);

  //!--------------------------------------------------------------------------
  //! SUT -> Graph test
  //!--------------------------------------------------------------------------

  foreach (graphlayout::LayoutNode* node, graph->allNodes()) {
    QVERIFY(node->pos().x() != 0 && node->pos().y() != 0);
  }

  foreach (graphlayout::LayoutEdge* edge, graph->edges()) {
    QVERIFY(edge->points().length()>=2);
  }

  foreach (graphlayout::LayoutNode* node, graph->allNodes()) {
    int exist = 0;
    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>(QRegExp("node*",Qt::CaseSensitive,QRegExp::Wildcard))) {
      if(item->property("uuid")==node->externUuid().toString()){
        exist=1;
        break;
      }
    }
    QCOMPARE(exist,1);
  }

  foreach (graphlayout::LayoutEdge* edge, graph->edges()) {
    int exist = 0;
    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("edge")) {
      if(item->property("uuid")==edge->externUuid().toString()){
        exist=1;
        break;
      }
    }
    QCOMPARE(exist,1);
  }


  delete widget;
  delete graph;
  delete myItem;
  return;
}


QTEST_MAIN(TsLayoutTest)

#include "tst_tslayout.moc"
