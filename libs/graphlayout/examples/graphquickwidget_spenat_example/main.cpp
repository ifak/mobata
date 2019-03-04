#include <QApplication>
#include <QQmlApplicationEngine>

#include <graphlayout/graphquickwidget.hpp>

#include <graphlayout/comcreatedeclgraph.hpp>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>

#include <QTimer>

#include <QMainWindow>

using namespace model::spenat;
using namespace model::base;

int main(int argc, char *argv[])
{
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication app(argc, argv);

  SpenatDeclModel decl("exampleModel");

  PlaceItem* initPlace=decl.addPlace(QStringLiteral("init"));
  Q_ASSERT(initPlace);
  decl.addInitPlace(initPlace);

  PlaceItem* place_1=decl.addPlace(QStringLiteral("place_1"));
  Q_ASSERT(place_1);

  PlaceItem* place_2=decl.addPlace(QStringLiteral("place_2"));
  Q_ASSERT(place_2);

  PlaceItem* place_3=decl.addPlace(QStringLiteral("place_3"));
  Q_ASSERT(place_3);

  PlaceItem* place_4=decl.addPlace(QStringLiteral("place_4"));
  Q_ASSERT(place_4);

  TransitionItem* trans_1=new TransitionItem(QStringLiteral("start"),
                                             nullptr,
                                             QStringLiteral("all zero"),
                                             QStringLiteral("do nothing"));
  decl.addTransition(trans_1);

  TransitionItem* trans_2=new TransitionItem(QStringLiteral("left"), nullptr);
  decl.addTransition(trans_2);

  TransitionItem* trans_3=new TransitionItem(QStringLiteral("right"), nullptr);
  decl.addTransition(trans_3);

  TransitionItem* trans_4=decl.addSignalTransition(QStringLiteral("reset"),
                                                   nullptr, nullptr,
                                                   QStringLiteral(""),
                                                   QStringLiteral(""));

  trans_1->addPrePlaceArc(initPlace);
  trans_1->addPostPlaceArc(place_1);
  trans_1->addPostPlaceArc(place_2);

  trans_2->addPrePlaceArc(place_1);
  trans_2->addPostPlaceArc(place_3);

  trans_3->addPrePlaceArc(place_2);
  trans_3->addPostPlaceArc(place_4);

  trans_4->addPrePlaceArc(place_3);
  trans_4->addPrePlaceArc(place_4);
  trans_4->addPostPlaceArc(initPlace);


  graphlayout::LayoutGraph* graph = new graphlayout::LayoutGraph("graph1");
  graphlayout::ComCreateDeclGraph comGraph(graph,&decl);
  comGraph.setSplines(graphlayout::SplineEnum::spline);
  QString errorString;
  bool result = comGraph.execute(&errorString);
  if(!result)
  {
    qCritical()<<errorString;
    return -1;
  }

  Q_INIT_RESOURCE(graphlayout);

  QMainWindow mainWindow;

  graphlayout::GraphQuickWidget* graphwidget = new graphlayout::GraphQuickWidget(graph,
                                                                                 graphlayout::Dot,
                                                                                 &mainWindow);
  mainWindow.setCentralWidget(graphwidget);
  result = graphwidget->layout(&errorString);
  if(!result)
  {
    qCritical()<<errorString;
    return -1;
  }

  mainWindow.resize(QSize(500,500));
  mainWindow.show();

//  QTimer* timer = new QTimer();
//  QObject::connect(timer, &QTimer::timeout, graphwidget, &graphlayout::GraphQuickWidget::layoutNoChecks);
//  timer->start(300);


  return app.exec();
}

