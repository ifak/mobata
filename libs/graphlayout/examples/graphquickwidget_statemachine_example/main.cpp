#include <QApplication>
#include <QQmlApplicationEngine>

#include <graphlayout/graphquickwidget.hpp>
#include <graphlayout/comcreatestatemachinegraph.hpp>
#include <mobata/model/statemachine/statemachine.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/simplestateitem.hpp>
#include <mobata/model/statemachine/abstractstateitem.hpp>
#include <mobata/model/statemachine/transitionitem.hpp>
#include <mobata/model/statemachine/finalstateitem.hpp>
#include <mobata/model/statemachine/regionitem.hpp>
#include <mobata/model/statemachine/compositestateitem.hpp>
#include <mobata/model/statemachine/concurrentstateitem.hpp>

#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <QQuickWidget>

using namespace model::statemachine;

int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(graphlayout);

  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication app(argc, argv);

  QString errorString;
  model::statemachine::StateMachineModel* smModel=new model::statemachine::StateMachineModel();

  SimpleStateItem* init = new SimpleStateItem("initState");
  smModel->setInitState(init, &errorString);
  Q_ASSERT(init);

  ChoiceStateItem* choice = new ChoiceStateItem("choiceState");
  smModel->addState(choice, &errorString);
  Q_ASSERT(choice);

  JunctionStateItem* junction = new JunctionStateItem("junctionState");
  smModel->addState(junction, &errorString);
  Q_ASSERT(junction);

  //create root composite
  CompositeStateItem* composite = new CompositeStateItem("compositeState");
  smModel->addState(composite, &errorString);
  Q_ASSERT(composite);

  SimpleStateItem* comState1 = new SimpleStateItem("comSimpleState1", "comEntry", "comExit");
  composite->addState(comState1, &errorString);
  Q_ASSERT(comState1);

  SimpleStateItem* comState2 = new SimpleStateItem("comSimpleState2", "comEntry", "comExit");
  composite->addState(comState2, &errorString);
  Q_ASSERT(comState2);

  //create region
  ConcurrentStateItem* concurrent = new ConcurrentStateItem("concurrent");
  concurrent->initRegions(1, &errorString);
  smModel->addState(concurrent, &errorString);
  Q_ASSERT(concurrent);
  Q_ASSERT(concurrent->regions().count() == 2);

  ConcurrentStateItem* concurrentTest = new ConcurrentStateItem("concurrentTest");
  concurrentTest->initRegions(3, &errorString);
  Q_ASSERT(concurrentTest);
  Q_ASSERT(concurrentTest->regions().count() == 3);


  SimpleStateItem* regionInit = new SimpleStateItem("regionInitState");
  concurrent->regions()[0]->setInitState(regionInit, &errorString);
  Q_ASSERT(regionInit);

  CompositeStateItem* regionComposite = new CompositeStateItem("regionCompositeState");
  concurrent->regions()[0]->addState(regionComposite, &errorString);
  Q_ASSERT(regionComposite);

  SimpleStateItem* regionComState1 = new SimpleStateItem("regionComSimpleState1", "regionComSimpleEntry", "regionComSimpleExit");
  regionComposite->addState(regionComState1, &errorString);
  Q_ASSERT(regionComState1);

  SimpleStateItem* regionComState2 = new SimpleStateItem("regionComSimpleState2", "regionComSimpleEntry", "regionComSimpleExit");
  regionComposite->addState(regionComState2, &errorString);
  Q_ASSERT(regionComState2);

  FinalStateItem* regionFinal= new FinalStateItem("finalState");
  concurrent->regions()[0]->addState(regionFinal, &errorString);
  Q_ASSERT(regionFinal);

  SimpleStateItem* conState1 = new SimpleStateItem("conInitState1");
  concurrent->regions()[1]->setInitState(conState1, &errorString);
  Q_ASSERT(conState1);

  SimpleStateItem* conState2 = new SimpleStateItem("conSimpleState2", "conEntry", "conExit");
  concurrent->regions()[1]->addState(conState2, &errorString);
  Q_ASSERT(conState2);

  //add transitions

  SignalItem* signal = new SignalItem("signal");
  smModel->addSignal(signal);
  PortItem* port = new PortItem("port");
  smModel->addPort(port);

  TransitionItem* t0 = smModel->addSignalTransition(QString("t0"),
                                                    signal,
                                                    port,
                                                    regionComState1,
                                                    regionComState2);
  Q_ASSERT(t0);

  TransitionItem* t01 = smModel->addSignalTransition(QString("t01"),
                                                     signal,
                                                     port,
                                                     comState1,
                                                     comState2);
  Q_ASSERT(t01);

  TransitionItem* t02 = smModel->addSignalTransition(QString("t02"),
                                                     signal,
                                                     port,
                                                     regionComState2,
                                                     regionFinal);
  Q_ASSERT(t02);

  TransitionItem* t03 = smModel->addSignalTransition(QString("t03"),
                                                     signal,
                                                     port,
                                                     conState1,
                                                     conState2);
  Q_ASSERT(t03);

  TransitionItem* t04 = smModel->addSignalTransition(QString("t04"),
                                                     signal,
                                                     port,
                                                     choice,
                                                     junction);
  Q_ASSERT(t04);

  TransitionItem* t05 = junction->addJunctionTransition(QString("t05"),
                                                        conState1);
  Q_ASSERT(t05);

  TransitionItem* t06 = junction->addJunctionTransition(QString("t06"),
                                                        regionInit);
  Q_ASSERT(t06);

  //TransitionItem from init to state1
  TransitionItem* t1 = smModel->addSignalTransition(QString("t1"),
                                                    signal,
                                                    port,
                                                    init,
                                                    choice);
  Q_ASSERT(t1);

  //TransitionItem from state1 to comState1
  TransitionItem* t2 = smModel->addSignalTransition(QString("t2"),
                                                    signal,
                                                    port,
                                                    choice,
                                                    composite->states().first());
  Q_ASSERT(t2);

  AbstractStateItem* someState = concurrent->regions()[0]->states()[0];

  TransitionItem* t4 = smModel->addSignalTransition(QString("t4"),
                                                    signal,
                                                    port,
                                                    someState,
                                                    regionComState1);
  Q_ASSERT(t4);

  graphlayout::LayoutGraph* graph = new graphlayout::LayoutGraph("graph1");
  graphlayout::ComCreateStateMachineGraph comGraph(graph,smModel);
  comGraph.execute(&errorString);
  if(errorString.size())
    qDebug()<<"error: "<<errorString;

  graphlayout::GraphQuickWidget* graphwidget = new graphlayout::GraphQuickWidget(graph,graphlayout::Dot);
  graphwidget->resize(QSize(500,500));
  graphwidget->show();
  graphwidget->layout(&errorString);
  if(errorString.size())
    qDebug()<<"error: "<<errorString;

  return app.exec();
}

