#include <QtTest>

#include <graphlayout/comcreatestatemachinegraph.hpp>
#include <graphlayout/graphquickwidget.hpp>

#include <mobata/model/statemachine/statemachine.hpp>
#include <mobata/model/base/atriggeritem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>

#include <QQuickWidget>
#include <QQuickItem>

class StatemachineLayoutTest
    : public QObject
{
  Q_OBJECT

public:
  StatemachineLayoutTest();
private:
  model::statemachine::StateMachineModel* _model;
  graphlayout::LayoutGraph* _graph;
  void initModel();
private Q_SLOTS:
  void initTestCase();
  void Seq1Test();
  void Seq2Test();
  void cleanupTestCase();
};

StatemachineLayoutTest::StatemachineLayoutTest()
{}

void StatemachineLayoutTest::initTestCase()
{
  Q_INIT_RESOURCE(graphlayout);
  this->initModel();
}

void StatemachineLayoutTest::initModel(){
  QString errorString;

  this->_model = new model::statemachine::StateMachineModel();

  bool result;

  model::statemachine::SimpleStateItem* init = new model::statemachine::SimpleStateItem("initState");
  result = this->_model->addState(init, &errorString);
  QCOMPARE(result, true);
  result = this->_model->setInitState(init, &errorString);
  QCOMPARE(result, true);
  QVERIFY(init);

  model::statemachine::SimpleStateItem* state1 = new model::statemachine::SimpleStateItem("simpleState", "entry", "exit");
  result = this->_model->addState(state1, &errorString);
  QCOMPARE(result, true);
  QVERIFY(state1);

  model::statemachine::ChoiceStateItem* choice = new model::statemachine::ChoiceStateItem("choiceState");
  result = this->_model->addState(choice, &errorString);
  QCOMPARE(result, true);
  QVERIFY(choice);

  model::statemachine::JunctionStateItem* junction = new model::statemachine::JunctionStateItem("junctionState");
  result = this->_model->addState(junction, &errorString);
  QCOMPARE(result, true);
  QVERIFY(junction);

  model::statemachine::FinalStateItem* final = new model::statemachine::FinalStateItem("finalState");
  result = this->_model->addState(final, &errorString);
  QCOMPARE(result, true);
  QVERIFY(final);

  //create root composite
  model::statemachine::CompositeStateItem* composite = new model::statemachine::CompositeStateItem("compositeState");
  result = this->_model->addState(composite, &errorString);
  QCOMPARE(result, true);
  QVERIFY(composite);

  model::statemachine::SimpleStateItem* comState1 = new model::statemachine::SimpleStateItem("comSimpleState", "comEntry", "comExit");
  result = composite->addState(comState1, &errorString);
  QCOMPARE(result, true);
  QVERIFY(comState1);

  //create region
  model::statemachine::ConcurrentStateItem* concurrent = new model::statemachine::ConcurrentStateItem("concurrent");
  concurrent->initRegions(1, &errorString);
  result = this->_model->addState(concurrent, &errorString);
  QCOMPARE(result, true);
  QVERIFY(concurrent);
  QVERIFY(concurrent->regions().count() == 2);

  model::statemachine::ConcurrentStateItem* concurrentTest = new model::statemachine::ConcurrentStateItem("concurrentTest");
  concurrentTest->initRegions(3, &errorString);
  QVERIFY(concurrentTest);
  QVERIFY(concurrentTest->regions().count() == 3);


  model::statemachine::SimpleStateItem* regionInit = new model::statemachine::SimpleStateItem("regionInitState");
  result = concurrent->regions()[0]->addState(regionInit, &errorString);
  QCOMPARE(result, true);
  result = concurrent->regions()[0]->setInitState(regionInit, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionInit);

  model::statemachine::SimpleStateItem* regionState = new model::statemachine::SimpleStateItem("regionSimpleState", "regionEntry", "regionExit");
  concurrent->regions()[0]->addState(regionState, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionState);

  model::statemachine::CompositeStateItem* regionComposite = new model::statemachine::CompositeStateItem("regionCompositeState");
  concurrent->regions()[0]->addState(regionComposite, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionComposite);

  model::statemachine::SimpleStateItem* regionComState = new model::statemachine::SimpleStateItem("regionComSimpleState", "regionComSimpleEntry", "regionComSimpleExit");
  result = regionComposite->addState(regionComState, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionComState);

  model::statemachine::FinalStateItem* regionFinal= new model::statemachine::FinalStateItem("finalState");
  concurrent->regions()[0]->addState(regionFinal, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionFinal);

  //add transitions

  //TransitionItem from init to state1
  model::base::SignalItem* signal = this->_model->signal(QStringLiteral("signal"));
  model::base::PortItem* port = this->_model->port(QStringLiteral("port"));
  model::base::SignalTriggerItem* trigger1 = new model::base::SignalTriggerItem(signal,
                                                                                      port);
  model::statemachine::TransitionItem* t1 = new model::statemachine::TransitionItem(trigger1,
                                                                                    this->_model->states()[0],
                                                                                    this->_model->states()[1],
                                                                                    "",
                                                                                    "initTrans");
  result = this->_model->addTransition(t1, &errorString);
  QCOMPARE(result, true);
  QVERIFY(t1);


  //TransitionItem from state1 to comState1
  model::base::SignalTriggerItem* trigger2 = new model::base::SignalTriggerItem(signal,
                                                                                      port);
  model::statemachine::TransitionItem* t2 = new model::statemachine::TransitionItem(trigger2,
                                                                                    this->_model->states()[1],
      utils::simple_cast<model::statemachine::CompositeStateItem*>(this->_model->states()[5])->states()[0],
      "",
      "simpleTrans");
  result = this->_model->addTransition(t2, &errorString);
  QCOMPARE(result, true);
  QVERIFY(t2);

  //TransitionItem from state1 to regionInit
  model::base::SignalTriggerItem* trigger3 = new model::base::SignalTriggerItem(signal,
                                                                                      port);
  model::statemachine::TransitionItem* t3 = new model::statemachine::TransitionItem(trigger3,
                                                                                    this->_model->states()[1],
      utils::simple_cast<model::statemachine::ConcurrentStateItem*>(this->_model->states()[6])->regions()[0]->states()[0],
      "",
      "regionTrans");
  result = this->_model->addTransition(t3, &errorString);
  QCOMPARE(result, true);
  QVERIFY(t3);

  //TransitionItem from regionInit to regionInit to regionComState
  model::base::SignalTriggerItem* trigger4 = new model::base::SignalTriggerItem(signal,
                                                                                      port);
  model::statemachine::TransitionItem* t4 = new model::statemachine::TransitionItem(trigger4,
                                                                                    utils::simple_cast<model::statemachine::ConcurrentStateItem*>(this->_model->states()[6])->regions()[0]->states()[0],
      utils::simple_cast<model::statemachine::CompositeStateItem*>(utils::simple_cast<model::statemachine::ConcurrentStateItem*>(this->_model->states()[6])->regions()[0]->states()[2])->states()[0],
      "",
      "regionComTrans");
  result = this->_model->addTransition(t4, &errorString);
  QCOMPARE(result, true);
  QVERIFY(t4);

  QVERIFY(this->_model);
  QCOMPARE(errorString,QString(""));
}

void StatemachineLayoutTest::Seq1Test(){
  this->_graph = new graphlayout::LayoutGraph("");
  graphlayout::ComCreateStateMachineGraph comGraph(this->_graph,this->_model);
  QString errorString;
  comGraph.execute(&errorString);
  QCOMPARE(errorString,QString(""));
  QCOMPARE(this->_graph->allNodes().length(),15);
  QCOMPARE(this->_graph->edges().length(),4);
}

void StatemachineLayoutTest::Seq2Test(){
  graphlayout::GraphQuickWidget* graphwidget = new graphlayout::GraphQuickWidget(this->_graph,graphlayout::Fdp);
  QString errorString;
#if (defined (_WIN32) || defined (_WIN64))
  widget->setGraphvizPath("C:\\Program Files (x86)\\Graphviz2.38\\bin");
#endif
  graphwidget->layout(&errorString);
  QCOMPARE(errorString,QString(""));
  QVERIFY(graphwidget->rootObject()->findChild<QObject*>("drawArea"));
  QCOMPARE(graphwidget->rootObject()->findChildren<QObject*>("node").length(),15);
  QCOMPARE(graphwidget->rootObject()->findChildren<QObject*>("edge").length(),4);

  delete graphwidget;
}

void StatemachineLayoutTest::cleanupTestCase(){
  delete this->_model;
  delete this->_graph;
}


QTEST_MAIN(StatemachineLayoutTest)

#include "tst_statemachinelayout.moc"
