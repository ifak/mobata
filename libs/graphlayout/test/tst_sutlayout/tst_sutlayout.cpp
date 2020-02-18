#include <QtTest/QTest>

#include <graphlayout/layoutgraph.hpp>
#include <graphlayout/layoutnode.hpp>
#include <graphlayout/layoutedge.hpp>
#include <graphlayout/graphquickwidget.hpp>
#include <graphlayout/comcreatesutgraph.hpp>
#include <mobata/model/ts/sutitem.hpp>

#include <QQuickWidget>
#include <QQuickItem>

class SutLayoutTest
    : public QObject
{
  Q_OBJECT

public:
  SutLayoutTest();

private Q_SLOTS:
  void initTestCase();
  void LayoutGraphCreationTest();
};

SutLayoutTest::SutLayoutTest()
{}

void SutLayoutTest::initTestCase()
{
  Q_INIT_RESOURCE(graphlayout);
}

void SutLayoutTest::LayoutGraphCreationTest()
{
  using namespace model::ts;
  using namespace model::base;

  SutItem* myItem = new SutItem();

  SutComponentItem* myComponent1 = new SutComponentItem("t1");
  SutComponentItem* myComponent2 = new SutComponentItem("t2");
  SutComponentItem* myComponent3 = new SutComponentItem("t3");

  myItem->addComponent(myComponent1);
  myItem->addComponent(myComponent2);
  myItem->addComponent(myComponent3);

  myComponent1->addPort("p1");
  myComponent1->addPort("p2");
  myComponent1->addPort("p3");
  myComponent1->addPort("p4");

  myComponent2->addPort("p1");
  myComponent2->addPort("p2");
  myComponent2->addPort("p3");
  myComponent2->addPort("p4");

  myComponent3->addPort("p1");
  myComponent3->addPort("p2");
  myComponent3->addPort("p3");
  myComponent3->addPort("p4");

  myItem->addLink(myComponent1->ports().first(),myComponent2->ports().first());
  myItem->addLink(myComponent2->ports().first(),myComponent3->ports().first());
  myItem->addLink(myComponent3->ports().first(),myComponent1->ports().first());

  graphlayout::LayoutGraph* graph = new graphlayout::LayoutGraph("graph");
  graphlayout::ComCreateSutGraph comGraph(graph,myItem);
  comGraph.execute();

  //!--------------------------------------------------------------------------
  //! SUT -> Graph test
  //!--------------------------------------------------------------------------

  QCOMPARE(graph->allNodes().length()+graph->allPorts().length(),18);
  QCOMPARE(graph->edges().length(),3);

  for(graphlayout::LayoutNode* node : graph->allNodes()) {
    int f = 0;
    for(ComponentItem* comp : myItem->components()) {
      if (comp->uuid()==node->externUuid())
        f=1;
    }
    QCOMPARE(f,1);
  }
  for(graphlayout::LayoutNodePort* portNode : graph->allPorts()) {
    int f = 0;
    for(ComponentItem* comp : myItem->components()) {
      for(PortItem* port : comp->ports()){
        if(port->uuid()==portNode->externUuid())
          f=1;
      }
    }
    QCOMPARE(f,1);
  }


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
    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
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


  foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
    QVERIFY(item->x()!=0);
    QVERIFY(item->y()!=0);
  }

  delete widget;
  delete graph;
  delete myItem;
  return;
}


QTEST_MAIN(SutLayoutTest)

#include "tst_sutlayout.moc"
