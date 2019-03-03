#include <QApplication>
#include <QQmlApplicationEngine>

#include <graphlayout/qmlgraphview.hpp>
#include <graphlayout/comcreatesutgraph.hpp>
#include <mobata/model/ts/ts.hpp>
#include <mobata/model/ts/sutitem.hpp>

#include <QQuickWidget>

using namespace model::ts;
using namespace model::base;

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    SutItem* myItem = new SutItem();

    SutComponentItem* myComponent1 = new SutComponentItem("t1");
    SutComponentItem* myComponent2 = new SutComponentItem("t2");
    SutComponentItem* myComponent3 = new SutComponentItem("t3");

    myItem->addComponent(myComponent1);
    myItem->addComponent(myComponent2);
    myItem->addComponent(myComponent3);

    myItem->addLink(myComponent1->ports().first(),myComponent2->ports().first());
    myItem->addLink(myComponent2->ports().first(),myComponent3->ports().first());
    myItem->addLink(myComponent3->ports().first(),myComponent1->ports().first());

    graphlayout::LayoutGraph* graph = new graphlayout::LayoutGraph("graph1");
    graphlayout::ComCreateSutGraph comGraph(graph,myItem);
    comGraph.execute();


    QQuickWidget* widget = new QQuickWidget();
    widget->resize(QSize(500,500));
    widget->show();
    QString* error = new QString();
    graphlayout::QmlGraphView comQML(widget,graph,graphlayout::Fdp);
    comQML.layout(error);

    return app.exec();
}

