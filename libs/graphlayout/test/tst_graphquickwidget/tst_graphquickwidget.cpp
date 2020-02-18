#include <QtTest>

#include <graphlayout/layoutgraph.hpp>
#include <graphlayout/layoutnode.hpp>
#include <graphlayout/layoutedge.hpp>
#include <graphlayout/graphquickwidget.hpp>

#include <QQuickWidget>
#include <QQuickItem>

class GraphQuickWidgetTest
        : public QObject
{
    Q_OBJECT

public:
    GraphQuickWidgetTest();

private Q_SLOTS:
    void initTestCase();
    void GraphTest();
    void SubgraphTest();
};

GraphQuickWidgetTest::GraphQuickWidgetTest()
{}

void GraphQuickWidgetTest::initTestCase()
{
  Q_INIT_RESOURCE(graphlayout);
}

void GraphQuickWidgetTest::GraphTest()
{
    graphlayout::LayoutGraph *graph1 = new graphlayout::LayoutGraph("graph1");
    graphlayout::LayoutNode* node1 = graph1->addNode();
    node1->setXLabel("T1");
    graphlayout::LayoutNode* node2 = graph1->addNode();
    node2->setXLabel("T2");
    graphlayout::LayoutNode* node3 = graph1->addNode();
    node3->setXLabel("T3");
    graphlayout::LayoutNode* node4 = graph1->addNode();
    node4->setXLabel("T4");
    graphlayout::LayoutNode* node5 = graph1->addNode();
    node5->setXLabel("T5");
    graphlayout::LayoutNode* node6 = graph1->addNode();
    node6->setXLabel("T6");
    graphlayout::LayoutNode* node7 = graph1->addNode();
    node7->setXLabel("T7");
    graphlayout::LayoutNode* node8 = graph1->addNode();
    node8->setXLabel("T8");
    graph1->addEdge(node1,node2);
    graph1->addEdge(node1,node3);
    graph1->addEdge(node3,node4);
    graph1->addEdge(node2,node5);
    graph1->addEdge(node4,node5);
    graph1->addEdge(node5,node6);
    graph1->addEdge(node6,node8);
    graph1->addEdge(node6,node7);
    graph1->addEdge(node7,node8);

    QVERIFY(graph1);

    graphlayout::GraphQuickWidget* widget = new graphlayout::GraphQuickWidget(graph1,
                                                                              graphlayout::Dot);
    widget->resize(QSize(500,500));
    QString error;
    widget->layout(&error);

    foreach (graphlayout::LayoutNode* node, graph1->allNodes()) {
        QVERIFY(node->pos().x() != 0 && node->pos().y() != 0);
    }

    foreach (graphlayout::LayoutEdge* edge, graph1->edges()) {
        QVERIFY(edge->points().length()>=2);
    }

    foreach (graphlayout::LayoutNode* node, graph1->allNodes()) {
        int exist = 0;
        foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
            if(item->property("uuid")==node->externUuid().toString()){
                exist=1;
                break;
            }
        }
        QCOMPARE(exist,1);
    }

    foreach (graphlayout::LayoutEdge* edge, graph1->edges()) {
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

    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
        QCOMPARE(item->x(),graph1->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))->pos().x());
    }

    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
        QCOMPARE(item->y(),graph1->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))->pos().y());
    }

    delete widget;
    delete graph1;
    return;
}

void GraphQuickWidgetTest::SubgraphTest()
{
    graphlayout::LayoutGraph *graph1 = new graphlayout::LayoutGraph("graph1");

    graphlayout::LayoutNode* node1 = graph1->addNode();
    node1->setXLabel("Hello");
    node1->setColor(QColor("lightgreen"));
    node1->setShape(graphlayout::Rect);
    graphlayout::LayoutNode* node2 = graph1->addNode();
    node2->setLabel("Start");
    node2->setShape(graphlayout::Ellipse);
    graphlayout::LayoutNode* node3 = graph1->addNode();
    node3->setLabel("World");
    node3->setShape(graphlayout::RoundedRect);
    graphlayout::LayoutNode* node4 = graph1->addNode();
    node4->setXLabel("H");
    node4->setShape(graphlayout::Ellipse);
    graphlayout::LayoutNode* node5 = graph1->addNode();
    node5->setXLabel("H");
    node5->setShape(graphlayout::Ellipse);
    graphlayout::LayoutNode* node6 = graph1->addNode();
    node6->setXLabel("O");
    node6->setShape(graphlayout::Ellipse);
    graphlayout::LayoutNode* node7 = graph1->addNode();
    node7->setShape(graphlayout::Rect);
    node7->setColor(QColor("blue"));
    node7->setLabel("subgraph");
    graphlayout::LayoutNode* node8 = node7->addNode();
    node8->setColor(QColor("red"));
    node8->setXLabel("red");
    graphlayout::LayoutNode* node9 = node7->addNode();
    node9->setColor(QColor("green"));
    node9->setXLabel("green");
    graphlayout::LayoutEdge* edge1 = graph1->addEdge(node1,node3);
    edge1->setLabel("edge");
    graphlayout::LayoutEdge* edge2 = graph1->addEdge(node2,node3);
    edge2->setType(graphlayout::DoubleArrow);
    graphlayout::LayoutEdge* edge3 = graph1->addEdge(node8,node9);
    edge3->setType(graphlayout::Line);
    graph1->addEdge(node6,node4);
    graph1->addEdge(node6,node5);
    graph1->addEdge(node2,node6);
    graph1->addEdge(node9,node5);
    graph1->addEdge(node1,node8);
    graph1->setSplines(graphlayout::ortho);
    graph1->setName("Example Graph");

    graphlayout::GraphQuickWidget* widget = new graphlayout::GraphQuickWidget(graph1,
                                                                              graphlayout::Dot);
    widget->resize(QSize(500,500));
    QString errorString;
    widget->layout(&errorString);

    foreach (graphlayout::LayoutNode* node, graph1->allNodes()) {
        QVERIFY(node->pos().x() != 0 && node->pos().y() != 0);
    }

    foreach (graphlayout::LayoutEdge* edge, graph1->edges()) {
        QVERIFY(edge->points().length()>=2);
    }

    foreach (graphlayout::LayoutNode* node, graph1->allNodes()) {
        int exist = 0;
        foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
            if(item->property("uuid")==node->externUuid().toString()){
                exist=1;
                break;
            }
        }
        QCOMPARE(exist,1);
    }

    foreach (graphlayout::LayoutEdge* edge, graph1->edges()) {
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

    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
        QCOMPARE(item->x(),graph1->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))->pos().x());
    }

    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
        QCOMPARE(item->y(),graph1->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))->pos().y());
    }

    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
        QCOMPARE(item->width(),graph1->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))->size().width());
    }

    foreach (QQuickItem* item, widget->rootObject()->findChildren<QQuickItem*>("node")) {
        QCOMPARE(item->height(),graph1->nodeByExternUuid(QUuid(qvariant_cast<QString>(item->property("uuid"))))->size().height());
    }

    delete widget;
    delete graph1;
    return;
}


QTEST_MAIN(GraphQuickWidgetTest)

#include "tst_graphquickwidget.moc"
