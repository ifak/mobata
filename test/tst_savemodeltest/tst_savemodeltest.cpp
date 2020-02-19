#include <QString>
#include <QtTest>

#include <mobata/model/base/basemodel.hpp>
#include <mobata/model/base/comsavebasemodel.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/signalitem.hpp>

#include <mobata/model/msc/msc.hpp>
#include <mobata/model/statemachine/statemachine.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/io/comsavejsonsmmodel.hpp>

class SaveModelTest : public QObject
{
  Q_OBJECT

public:
  SaveModelTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void saveBaseModelTest();
  void saveMscModelTest();
  void saveStateMachineModelTest();
};

SaveModelTest::SaveModelTest()
{}

void SaveModelTest::initTest()
{}

void SaveModelTest::cleanupTest()
{}

void SaveModelTest::saveBaseModelTest()
{
  model::base::BaseModel testBaseModel("testBaseModel");

  ///types///////////
  model::base::DataTypeItem* intTypeItem = testBaseModel.addDataType(QStringLiteral("int"));
  QVERIFY(intTypeItem);
  model::base::DataTypeItem* realTypeItem = testBaseModel.addDataType(QStringLiteral("real"));
  QVERIFY(realTypeItem);
  model::base::DataTypeItem* myEnumTypeItem = testBaseModel.addDataType("myEnum");
  QVERIFY(myEnumTypeItem);

  ///signals///////////
  model::base::SignalItem* signalItem = testBaseModel.addSignal("emptySignal");
  QVERIFY(signalItem);
  signalItem = testBaseModel.addSignal("complexSignal");
  QVERIFY(signalItem);
  model::base::ParamItem* paramItem = signalItem->addParameter("x", intTypeItem->name());
  QVERIFY(paramItem);
  paramItem = signalItem->addParameter("y", realTypeItem->name());
  QVERIFY(paramItem);
  paramItem = signalItem->addParameter("x", myEnumTypeItem->name());
  QVERIFY(paramItem == 0);

  ///attributes/////////
  model::base::AttributeItem* attributeItem = testBaseModel.addAttribute("intAttribute",
                                                                         intTypeItem->name(),
                                                                         "10");
  QVERIFY(attributeItem);
  attributeItem = testBaseModel.addAttribute("y", realTypeItem->name(), "1.2");
  QVERIFY(attributeItem);
  attributeItem = testBaseModel.addAttribute("y", myEnumTypeItem->name(), "");
  QVERIFY(attributeItem == 0);

  model::base::ComSaveBaseModel saveCommand(&testBaseModel,
                                            "testBaseModel.json");
  bool result = saveCommand.execute();
  QVERIFY(result);

  return;
}

void SaveModelTest::saveMscModelTest()
{
  using namespace model::msc;

  MscModel testMscModel("testMscModel");

  QString errorString;
  model::base::DataTypeItem* enumType=testMscModel.addDataType("MyEnumType",
                                                               &errorString);
  QVERIFY(enumType);
  enumType->setTypeEnum(prop::Enum);
  enumType->addLiteral("lit1");
  enumType->addLiteral("lit2");

  model::base::DataTypeItem* stringType=testMscModel.addDataType("string",
                                                                 &errorString);
  QVERIFY(stringType);
  stringType->setTypeEnum(prop::String);

  model::base::SignalItem* signal=testMscModel.addSignal("signal",
                                                         &errorString);
  QVERIFY(signal);
  model::base::ParamItem* paramItem=signal->addParameter("param", enumType->name(), &errorString);
  QVERIFY(paramItem);

  MscComponentItem* comp1=testMscModel.addComponent("comp1",
                                                    &errorString);
  QVERIFY(comp1);
  PortItem* port1=comp1->addPort("port", &errorString);
  QVERIFY(port1);

  //error
  PortItem* wrong_port=comp1->addPort("port", &errorString);
  QVERIFY(wrong_port==0);
  QVERIFY(errorString=="There is already a port "
                        "'port' available!");
  ///////////////////////////////////

  MscComponentItem* comp2=testMscModel.addComponent("comp2",
                                                    &errorString);
  QVERIFY(comp2);
  PortItem* port2=comp2->addPort("port", &errorString);
  QVERIFY(port2);

  MscSequence* sequ1=testMscModel.addSequence("sequ1");

  ///only text-message
  MscMessageItem* message=sequ1->addMessage(port1, port2, "signal_in(x=0)");

  ///typed message
  message=sequ1->addMessage(port2, port1);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  MscSequence* sequ2=testMscModel.addSequence("sequ2");
  message=sequ2->addMessage(port2, port1, "signal_out(y=25)");

  MscFragmentItem* altFragment=sequ2->addFragment(AlternativeFragment);
  MscFragmentRegionItem* cond1Region=altFragment->addRegion("condition 1");
  message=cond1Region->addMessage(port1, port2);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit2");

  MscFragmentRegionItem* cond2Region=altFragment->addRegion("condition 2");
  message=cond2Region->addMessage(port2, port1);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  message=sequ2->addMessage(port1, port2, "signal_end(here are the params ...)");

  MscSequence* sequ3=testMscModel.addSequence("sequ3");

  message=sequ3->addMessage(port2, port1, "signal_out(y=25)");

  altFragment=sequ3->addFragment(AlternativeFragment);
  cond1Region=altFragment->addRegion("condition 1");
  message=cond1Region->addMessage(port1, port2);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit2");

  cond2Region=altFragment->addRegion("condition 2");
  message=cond2Region->addMessage(port2, port1);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  MscFragmentItem* loopFragment=cond2Region->addFragment(LoopFragment);
  MscFragmentRegionItem* loopRegion=loopFragment->addRegion();
  message=loopRegion->addMessage(port1, port2, "loop message");

  MscFragmentItem* loop2Fragment=loopRegion->addFragment(LoopFragment);
  MscFragmentRegionItem* loop2Region=loop2Fragment->addRegion("loop statement");
  message=loop2Region->addMessage(port2, port1, "inner loop message");

  message=sequ3->addMessage(port1, port2, "signal_end(here are the params ...)");

  ComSaveMscModel saveCommand(&testMscModel,
                              "testMscModel.json");
  bool result = saveCommand.execute();
  QVERIFY(result);

  return;
}

void SaveModelTest::saveStateMachineModelTest()
{
  using namespace model::statemachine;

  //create statemachine
  StateMachineModel testSMModel;
  testSMModel.setName("testSMModel");

  bool result;

  ///datatypes//////
  QString errorString;
  model::base::DataTypeItem* intTypeItem = testSMModel.addDataType(QStringLiteral("int"));
  QVERIFY(intTypeItem);
  model::base::DataTypeItem* realTypeItem = testSMModel.addDataType(QStringLiteral("real"));
  QVERIFY(realTypeItem);
  model::base::DataTypeItem* enumTypeItem = testSMModel.addDataType("MyEnumType", &errorString);
  QVERIFY(enumTypeItem);
  enumTypeItem->setTypeEnum(prop::Enum);
  enumTypeItem->addLiteral("lit1");
  enumTypeItem->addLiteral("lit2");

  model::base::DataTypeItem* stringTypeItem = testSMModel.addDataType("string", &errorString);
  QVERIFY(stringTypeItem);
  stringTypeItem->setTypeEnum(prop::String);

  ///signals//////
  model::base::SignalItem* signalItem = testSMModel.addSignal("signal",
                                                              &errorString);
  QVERIFY(signalItem);
  model::base::ParamItem* paramItem = signalItem->addParameter("param", enumTypeItem->name(), &errorString);
  QVERIFY(paramItem);

  ///ports//////
  PortItem* portItem = testSMModel.addPort("port", &errorString);
  QVERIFY(portItem);

  ///attributes/////////
  model::base::AttributeItem* attributeItem = testSMModel.addAttribute("intAttribute", intTypeItem->name(), "10");
  QVERIFY(attributeItem);
  attributeItem = testSMModel.addAttribute("y", realTypeItem->name(), "1.2");
  QVERIFY(attributeItem);
  attributeItem = testSMModel.addAttribute("y", enumTypeItem->name(), "");
  QVERIFY(attributeItem == 0);

  //error
  PortItem* wrong_port=testSMModel.addPort("port", &errorString);
  QVERIFY(wrong_port==0);
  QVERIFY(errorString=="There is already a port "
                        "'port' available!");

  ///States//////////

  //Create statemachine root
  SimpleStateItem* init = new SimpleStateItem("initState");
  result = testSMModel.addState(init, &errorString);
  QCOMPARE(result, true);
  result = testSMModel.setInitState(init, &errorString);
  QCOMPARE(result, true);
  QVERIFY(init);

  SimpleStateItem* state1 = new SimpleStateItem("simpleState", "entry", "exit");
  result = testSMModel.addState(state1, &errorString);
  QCOMPARE(result, true);
  QVERIFY(state1);

  ChoiceStateItem* choice = new ChoiceStateItem("choiceState");
  result = testSMModel.addState(choice, &errorString);
  QCOMPARE(result, true);
  QVERIFY(choice);

  //test junction and junction transitions
  JunctionStateItem* junction = new JunctionStateItem("junctionState");
  result = testSMModel.addState(junction, &errorString);
  QCOMPARE(result, true);
  QVERIFY(junction);

  TransitionItem* jt0 = junction->addJunctionTransition(QStringLiteral("jt0"),
                                                        state1,
                                                        QStringLiteral("testGuard"),
                                                        QStringLiteral("testAction"));
  QVERIFY(jt0);

  TransitionItem* jt1 = junction->addJunctionTransition(QStringLiteral("jt1"),
                                                        state1,
                                                        QStringLiteral("else"),
                                                        QStringLiteral("testAction2"));
  QVERIFY(jt1);

  QCOMPARE(junction->transitions().count(), 2);

  JunctionStateItem* junctionParent = static_cast<JunctionStateItem*>(jt0->source());
  QVERIFY(junctionParent);
  QCOMPARE(junctionParent->uuid(), junction->uuid());

  QCOMPARE(jt0->guard(), QStringLiteral("testGuard"));
  QCOMPARE(jt1->action(), QStringLiteral("testAction2"));

  junction->removeTransition(jt0->uuid());
  QCOMPARE(junction->transitions().count(), 1);

  FinalStateItem* final = new FinalStateItem("finalState");
  result = testSMModel.addState(final, &errorString);
  QCOMPARE(result, true);
  QVERIFY(final);

  //create root composite
  CompositeStateItem* composite = new CompositeStateItem("compositeState");
  result = testSMModel.addState(composite, &errorString);
  QCOMPARE(result, true);
  QVERIFY(composite);

  SimpleStateItem* comState1 = new SimpleStateItem("comSimpleState", "comEntry", "comExit");
  result = composite->addState(comState1, &errorString);
  QCOMPARE(result, true);
  QVERIFY(comState1);

  //create region
  ConcurrentStateItem* concurrent = new ConcurrentStateItem("concurrent");
  concurrent->initRegions(1, &errorString);
  result = testSMModel.addState(concurrent, &errorString);
  QCOMPARE(result, true);
  QVERIFY(concurrent);
  QVERIFY(concurrent->regions().count() == 2);

  ConcurrentStateItem* concurrentTest = new ConcurrentStateItem("concurrentTest");
  concurrentTest->initRegions(3, &errorString);
  QVERIFY(concurrentTest);
  QVERIFY(concurrentTest->regions().count() == 3);


  SimpleStateItem* regionInit = new SimpleStateItem("regionInitState");
  result = concurrent->regions()[0]->addState(regionInit, &errorString);
  QCOMPARE(result, true);
  result = concurrent->regions()[0]->setInitState(regionInit, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionInit);

  SimpleStateItem* regionState = new SimpleStateItem("regionSimpleState", "regionEntry", "regionExit");
  result = concurrent->regions()[0]->addState(regionState, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionState);

  CompositeStateItem* regionComposite = new CompositeStateItem("regionCompositeState");
  result = concurrent->regions()[0]->addState(regionComposite, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionComposite);

  SimpleStateItem* regionComState = new SimpleStateItem("regionComSimpleState", "regionComSimpleEntry", "regionComSimpleExit");
  result = regionComposite->addState(regionComState, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionComState);

  FinalStateItem* regionFinal= new FinalStateItem("finalState");
  result = concurrent->regions()[0]->addState(regionFinal, &errorString);
  QCOMPARE(result, true);
  QVERIFY(regionFinal);

  //add transitions

  //TransitionItem from init to state1
  TransitionItem* t1 = testSMModel.addSignalTransition(QString("initTrans"),
                                                       testSMModel.signal(QString("signal")),
                                                       testSMModel.port(QString("port")),
                                                       init,
                                                       state1);
  QVERIFY(t1);

  //TransitionItem from state1 to comState1
  TransitionItem* t2 = testSMModel.addSignalTransition(QString("simpleTrans"),
                                                       testSMModel.signal(QString("signal")),
                                                       testSMModel.port(QString("port")),
                                                       state1,
                                                       comState1);
  QVERIFY(t2);

  //TransitionItem from state1 to regionInit
  TransitionItem* t3 = testSMModel.addSignalTransition(QString("regionTrans"),
                                                       testSMModel.signal(QString("signal")),
                                                       testSMModel.port(QString("port")),
                                                       state1,
                                                       regionInit);
  QVERIFY(t3);

  //TransitionItem from regionInit to regionInit to regionComState
  TransitionItem* t4 = testSMModel.addTimeoutTransition(QString("regionComTrans"),
                                                       double(5.6),
                                                       regionInit,
                                                       regionComState);
  QVERIFY(t4);

  ComSaveJsonSMModel saveCommand(&testSMModel,
                                 "testSMModel.json");
  result = saveCommand.execute();
  QVERIFY(result);

  return;
}

QTEST_GUILESS_MAIN(SaveModelTest)

#include "tst_savemodeltest.moc"
