#include <QApplication>
#include <QQmlApplicationEngine>

#include <graphlayout/qmlgraphview.hpp>
#include <graphlayout/comgraphts.hpp>
#include <mobata/model/ts/ts.hpp>
#include <mobata/model/ts/sutitem.hpp>

#include <QFileDialog>
#include <QQuickWidget>


using namespace model::ts;
using namespace model::base;

int main(int argc, char *argv[])
{
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication app(argc, argv);

  QString dir = "";
  //#ifdef WIN32
  dir = QFileDialog::getExistingDirectory(new QWidget(),"select graphviz bin dir","/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
  //#endif

  SutItem* myItem = new SutItem();

  SutComponentItem* mySUTComponent1 = myItem->addComponent<SutComponentItem>("t1");
  mySUTComponent1->removePort(mySUTComponent1->ports().first()->uuid());
  mySUTComponent1->addPort("P1_1");
  mySUTComponent1->addPort("P1_2");
  mySUTComponent1->addPort("P1_3");
  mySUTComponent1->addPort("P1_4");
  SutComponentItem* mySUTComponent2 = myItem->addComponent<SutComponentItem>("t2");
  mySUTComponent2->removePort(mySUTComponent2->ports().first()->uuid());
  mySUTComponent2->addPort("P2_1");
  mySUTComponent2->addPort("P2_2");
  mySUTComponent2->addPort("P2_3");
  SutComponentItem* mySUTComponent3 = myItem->addComponent<SutComponentItem>("t3");
  mySUTComponent3->removePort(mySUTComponent3->ports().first()->uuid());
  mySUTComponent3->addPort("P3_1");
  mySUTComponent3->addPort("P3_2");
  mySUTComponent3->addPort("P3_3");
  mySUTComponent3->addPort("P3_4");
  SutComponentItem* mySUTComponent4 = myItem->addComponent<SutComponentItem>("t4");
  mySUTComponent4->removePort(mySUTComponent4->ports().first()->uuid());
  mySUTComponent4->addPort("P4_1");
  mySUTComponent4->addPort("P4_2");
  SutComponentItem* mySUTComponent5 = myItem->addComponent<SutComponentItem>("t5");
  mySUTComponent5->removePort(mySUTComponent5->ports().first()->uuid());
  mySUTComponent5->addPort("P5_1");
  mySUTComponent5->addPort("P5_2");

  myItem->addLink(mySUTComponent1->ports()[2],mySUTComponent2->ports()[0]);
  myItem->addLink(mySUTComponent2->ports()[1],mySUTComponent3->ports()[0]);
  myItem->addLink(mySUTComponent3->ports()[2],mySUTComponent1->ports()[1]);
  myItem->addLink(mySUTComponent4->ports()[0],mySUTComponent3->ports()[1]);
  myItem->addLink(mySUTComponent4->ports()[1],mySUTComponent5->ports()[0]);
  myItem->addLink(mySUTComponent5->ports()[1],mySUTComponent1->ports()[0]);

  myItem->addLink(mySUTComponent3->ports()[2],mySUTComponent1->ports()[0]);


  TestSystemItem* myMainItem = new TestSystemItem(myItem);
  myMainItem->removeComponentByID(myMainItem->components().first()->uuid());

  TestComponentItem* myTSComponent1 = myMainItem->addComponent<TestComponentItem>("o1");
  myTSComponent1->addPort("test1");

  TestComponentItem* myTSComponent2 = myMainItem->addComponent<TestComponentItem>("o2");
  myTSComponent2->addPort("test2");
  TestComponentItem* myTSComponent3 = myMainItem->addComponent<TestComponentItem>("o3");

  myMainItem->addLink(myTSComponent1->ports()[1],myTSComponent2->ports()[1]);

  myMainItem->addLink(myTSComponent1->ports()[0],mySUTComponent1->ports()[3]);
  myMainItem->addLink(myTSComponent2->ports()[0],mySUTComponent2->ports()[2]);
  myMainItem->addLink(myTSComponent3->ports()[0],mySUTComponent3->ports()[3]);



  graphlayout::LayoutGraph* graph = new graphlayout::LayoutGraph("graph1");
  graphlayout::ComGraphTS comGraph(graph,myMainItem);
  comGraph.execute();


  QQuickWidget* widget = new QQuickWidget();
  widget->resize(QSize(500,500));
  widget->show();
  QString* error = new QString();
  graphlayout::QmlGraphView comQML(widget,graph,graphlayout::Fdp);
  comQML.setGraphvizPath(dir);
  comQML.layout(error);

  return app.exec();
}

