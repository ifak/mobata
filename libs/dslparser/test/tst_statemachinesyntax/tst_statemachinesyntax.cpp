#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <dslparser/statemachine/combuildstatemachinemodel.hpp>
#include <dslparser/statemachine/combuildstatemachinefile.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>
#include <mobata/model/base/functionitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <mobata/model/msc/mscloopfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>
#include <mobata/model/statemachine/transitionitem.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/simplestateitem.hpp>
#include <mobata/model/statemachine/compositestateitem.hpp>
#include <mobata/model/statemachine/concurrentstateitem.hpp>
#include <mobata/model/statemachine/abstractstateitem.hpp>
#include <mobata/model/statemachine/finalstateitem.hpp>
#include <mobata/model/statemachine/junctionstateitem.hpp>
#include <mobata/model/statemachine/regionitem.hpp>
#include <mobata/model/statemachine/types.hpp>
#include <mobata/model/base/propsignals.hpp>
#include <mobata/model/base/atriggeritem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>
#include <mobata/model/base/timeouttriggeritem.hpp>
#include <mobata/prop/nameproperty.hpp>

class StateMachineSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  StateMachineSyntaxTest();

private Q_SLOTS:
  void initstatemachine();
  void initTest();
  void cleanupTest();
  void simpleStateMachineDeclTest_1();
  void simpleStateMachineDeclTest_2();

  void basicFunctionDeclTest();
  void functionConditionStatementTest();
  void functionFalseConditionStatementTest();

  void functionSwitchCaseStatementTest();
  void functionFalseSwitchCaseStatementTest();

  void functionAttributeReturnStatementTest();
  void functionFalseAttributeReturnStatementTest();

  void complexStateMachineDeclTest();
  void complexStateMachineDeclTest2();
  void sequentialTest();
  /*
  void simplestatemachineErrorTest_1();
  void simplestatemachineErrorTest_2();
  void simplestatemachineErrorTest_3();
  void simplestatemachineErrorTest_4();
  void simplestatemachineErrorTest_5();
  void simplestatemachineErrorTest_6();
  void simplestatemachineErrorTest_7();
  void simplestatemachineErrorTest_8();
  void simplestatemachineErrorTest_9();
  void simplestatemachineErrorTest_10();

  void simplestatemachineDeclKeywordTest_1();*/
  void simplestateMachineDeclKeywordTest_2();
};

StateMachineSyntaxTest::StateMachineSyntaxTest()
{
}

void StateMachineSyntaxTest::initstatemachine()
{
  Q_INIT_RESOURCE(complexexamples);
}

void StateMachineSyntaxTest::initTest()
{}

void StateMachineSyntaxTest::cleanupTest()
{}

void StateMachineSyntaxTest::simpleStateMachineDeclTest_1()
{
  QString docText("StateMachine {"
                  "name: statemachinemodel2;\n"
                  "Signal hallo(int param);\n"
                  "Attribute int a =0;\n"
                  "Port here;\n"
                  "initState: s1;"
                  "SimpleState s1;"
                  "SimpleState {"
                  "name: s2;"
                  "entry: a = 20;" // will be saved as just a QString
                  "exit: send hallo(1) to here;"
                  "}"
                  "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachinemodel2"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(1));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s2"));
  QCOMPARE(state->isEnabled(),true);
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));
  return;
}

void StateMachineSyntaxTest::simpleStateMachineDeclTest_2()
{
  QString docText("StateMachine {"
                  "name: statemachinemodel2;"
                  "Signal input (int something);"
                  "Signal hallo(int param);\n"
                  "Attribute int a = 0;\n"
                  "Attribute int somethingelse = 0;\n"
                  "Port defaultPort;"
                  "Port here;"
                  "initState: s1;"
                  "SimpleState s1;"
                  "SimpleState {"
                  "name: s2;"
                  "entry: a = 20;" // will be saved as just a QString
                  "exit: send hallo(1) to here;"
                  "}"
                  "SignalTransition {"
                  "name: t1;"
                  "signal: input;"
                  "port: defaultPort;"
                  "guard: msg.something > 20;"
                  "action: somethingelse = 10;"
                  "source: s1;"
                  "target: s2;"
                  "}"
                  "}");
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachinemodel2"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(1));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s2"));
  QCOMPARE(state->isEnabled(),true);

  QCOMPARE(statemachineModel.transitions().size(),1);
  model::statemachine::TransitionItem* transition1 = statemachineModel.transitions().at(0);
  model::base::ATriggerItem* trigger = transition1->trigger();
  Q_ASSERT(trigger);
  QCOMPARE(trigger->triggerType(), model::base::ATriggerItem::EventTrigger);
  model::base::SignalTriggerItem* signalTrigger = static_cast<model::base::SignalTriggerItem*>(trigger);
  Q_ASSERT(signalTrigger);
  QCOMPARE(transition1->name(),QString("t1"));
  QVERIFY(signalTrigger->triggerSignal());
  QCOMPARE(signalTrigger->triggerSignal()->name(),QString("input"));
  QCOMPARE(signalTrigger->triggerSignal()->params().size(),1);
  QCOMPARE(signalTrigger->triggerSignal()->params().at(0)->name(),QString("something"));
  QVERIFY(signalTrigger->port());
  QCOMPARE(signalTrigger->port()->name(), QStringLiteral("defaultPort"));
  QCOMPARE(transition1->guard(),QString("msg.something > 20"));
  QCOMPARE(transition1->action(),QString("somethingelse = 10;"));
  QVERIFY(transition1->source());
  QCOMPARE(transition1->source()->name(),QString("s1"));
  QVERIFY(transition1->target());
  QCOMPARE(transition1->target()->name(),QString("s2"));

  return;
}

void StateMachineSyntaxTest::complexStateMachineDeclTest(){
  QString docText("StateMachine {"
                  "\nname: statemachinemodel2;"
                  "\nPort port01;"
                  "\nSignal input (int something);"
                  "\nAttribute int somethingelse=0;"
                  "\nAttribute int testAction=0;"
                  "\nAttribute int testAction2=0;"
                  "\nAttribute bool test=false;"
                  "\nAttribute bool test2=false;"
                  "\ninitState: s1;"
                  "\nSimpleState s1;"
                  "\nCompositeState{"
                  "\nname: s2;"
                  "\nentry: somethingelse = 10; // will be saved as just a QString"
                  "\nexit: somethingelse = 11;"
                  "\ninitState: s21;"
                  "\nSimpleState {"
                  "\nname: s21;"
                  "\nentry: somethingelse = 12;"
                  "\nexit: somethingelse = 13;"
                  "\n}"
                  "\nSimpleState {"
                  "\nname: s22;"
                  "\nentry: somethingelse = 14;"
                  "\nexit: somethingelse = 15;"
                  "\n}"
                  "\nFinalState{"
                  "\nname: s23;"
                  "\n}"
                  "\n}"

                  "\nJunctionState {"
                  "\nname: s3;"
                  "\nJunctionTransition {"
                  "\nname: jt0;"
                  "\nguard: test;"
                  "\naction: testAction=2;"
                  "\ntarget: s2;"
                  "\n}"
                  "\nJunctionTransition {"
                  "\nname: jt1;"
                  "\nguard: test2;"
                  "\naction: testAction2=3;"
                  "\ntarget: s2;"
                  "\n}"
                  "\n}"
                  "\nFinalState {"
                  "\nname: s5;"
                  "\n}"


                  "\nSignalTransition {"
                  "\nname: t1;"
                  "\nsignal: input;"
                  "\nport: port01;"
                  "\nguard: msg.something;"
                  "\naction: somethingelse=20;"
                  "\nsource: s1;"
                  "\ntarget: s2;"
                  "\n}"

                  "\nTimeoutTransition {"
                  "\nname: t2;"
                  "\nvalue: 2.2;"
                  "\nguard: test2;"
                  "\naction: somethingelse=21;"
                  "\nsource: s1;"
                  "\ntarget: s2;"
                  "\n}"
                  "\n}"
                  );
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("statemachinemodel2"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(), 4);
  model::statemachine::CompositeStateItem* state = static_cast<model::statemachine::CompositeStateItem*>(statemachineModel.states().at(1));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s2"));
  QCOMPARE(state->states().count(), 3);
  QCOMPARE(state->states().at(0)->name(),QString("s21"));
  QCOMPARE(state->states().at(1)->name(),QString("s22"));
  model::statemachine::SimpleStateItem* simState = dynamic_cast<model::statemachine::SimpleStateItem*>(state->states().at(1));
  QVERIFY(simState);

  QCOMPARE(simState->entryAction(),QString("somethingelse = 14;"));
  QCOMPARE(simState->exitAction(),QString("somethingelse = 15;"));
  QCOMPARE(state->states().at(2)->name(),QString("s23"));
  QCOMPARE(state->isEnabled(),true);

  const model::statemachine::AbstractStateItem* abstractFinal = statemachineModel.states().at(3);
  QVERIFY(abstractFinal);
  QCOMPARE(abstractFinal->stateType(), model::statemachine::Final);
  const model::statemachine::FinalStateItem* finalItem = static_cast<const model::statemachine::FinalStateItem*>(abstractFinal);
  QVERIFY(finalItem);
  QCOMPARE(finalItem->name(), QStringLiteral("s5"));

  const model::statemachine::AbstractStateItem* abstractJunction = statemachineModel.state(QStringLiteral("s3"));
  QVERIFY(abstractJunction);
  QCOMPARE(abstractJunction->stateType(), model::statemachine::Junction);
  const model::statemachine::JunctionStateItem* junctionItem = static_cast<const model::statemachine::JunctionStateItem*>(abstractJunction);
  QVERIFY(junctionItem);
  QCOMPARE(junctionItem->transitions().count(), 2);
  const model::statemachine::TransitionItem* jt0 = junctionItem->transitions().at(0);
  Q_ASSERT(jt0);
  QCOMPARE(jt0->action(), QStringLiteral("testAction=2;"));
  QCOMPARE(jt0->guard(), QStringLiteral("test"));
  QVERIFY(jt0->source());
  QVERIFY(jt0->target());
  QCOMPARE(jt0->source()->uuid(), junctionItem->uuid());
  QCOMPARE(jt0->target()->uuid(), state->uuid());
  const model::statemachine::TransitionItem* jt1 = junctionItem->transitions().at(1);
  Q_ASSERT(jt1);
  QCOMPARE(jt1->action(), QStringLiteral("testAction2=3;"));
  QCOMPARE(jt1->guard(), QStringLiteral("test2"));
  QCOMPARE(jt1->target()->uuid(), state->uuid());

  QCOMPARE(statemachineModel.transitions().size(), 2);
  const model::statemachine::TransitionItem* transition1 = statemachineModel.transitions().at(0);
  const model::base::ATriggerItem* trigger = transition1->trigger();
  Q_ASSERT(trigger);
  QCOMPARE(trigger->triggerType(), model::base::ATriggerItem::EventTrigger);
  const model::base::SignalTriggerItem* signalTrigger = static_cast<const model::base::SignalTriggerItem*>(trigger);
  Q_ASSERT(signalTrigger);
  QCOMPARE(transition1->name(),QString("t1"));
  QVERIFY(signalTrigger->triggerSignal());
  QCOMPARE(signalTrigger->triggerSignal()->name(),QString("input"));
  QCOMPARE(signalTrigger->triggerSignal()->params().size(),1);
  QCOMPARE(signalTrigger->triggerSignal()->params().at(0)->name(),QString("something"));
  QCOMPARE(signalTrigger->port()->name(), QString("port01"));
  QCOMPARE(transition1->guard(),QString("msg.something"));
  QCOMPARE(transition1->action(),QString("somethingelse=20;"));
  QVERIFY(transition1->source());
  QCOMPARE(transition1->source()->name(),QString("s1"));
  QVERIFY(transition1->target());
  QCOMPARE(transition1->target()->name(),QString("s2"));

  const model::statemachine::TransitionItem* transition2 = statemachineModel.transitions().at(1);
  const model::base::ATriggerItem* trigger2 = transition2->trigger();
  Q_ASSERT(trigger2);
  QCOMPARE(trigger2->triggerType(), model::base::ATriggerItem::TimeoutTrigger);
  const model::base::TimeoutTriggerItem* timeoutTrigger = static_cast<const model::base::TimeoutTriggerItem*>(trigger2);
  Q_ASSERT(timeoutTrigger);
  double value = timeoutTrigger->value();
  QCOMPARE(value, double(2.2));
  QCOMPARE(transition2->name(),QString("t2"));
  QCOMPARE(transition2->guard(),QString("test2"));
  QCOMPARE(transition2->action(),QString("somethingelse=21;"));
  QVERIFY(transition2->source());
  QCOMPARE(transition2->source()->name(),QString("s1"));
  QVERIFY(transition2->target());
  QCOMPARE(transition2->target()->name(),QString("s2"));

  QCOMPARE(command.keywordTextLocations().size(), 61);

  return;
}

void StateMachineSyntaxTest::complexStateMachineDeclTest2(){
  QString docText("StateMachine {"
                  "\nname: statemachinemodel2;"
                  "\nPort port01;"
                  "\nSignal input (int something);"
                  "\nAttribute int somethingelse=0;"
                  "\ninitState: s1;"
                  "\nSimpleState s1;"
                  "\nConcurrentState{"
                  "\nname: s2;"
                  "\nRegion {"
                  "\nname: state_19;"
                  "\ninitState: init_r1;"
                  "\nSimpleState init_r1;"
                  "\nFinalState terminationstate_7;"
                  "\nSimpleState state_r1;"
                  "\n}"
                  "\nRegion {"
                  "\nname: state_20;"
                  "\ninitState: init_r2;"
                  "\nSimpleState init_r2;"
                  "\nSimpleState state_r2;"
                  "\nFinalState terminationstate_9;"
                  "\n}"
                  "\n}"
                  "\nJunctionState {"
                  "\n name: s3;"
                  "\n}"
                  "\nFinalState {"
                  "\nname: s5;"
                  "\n}"


                  "\nSignalTransition {"
                  "\nname: t1;"
                  "\nsignal: input;"
                  "\nport: port01;"
                  "\nguard: msg.something;"
                  "\naction: somethingelse=20;"
                  "\nsource: s1;"
                  "\ntarget: s2;"
                  "\n}"
                  "\n}"
                  );
  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());

  QCOMPARE(QString("statemachinemodel2"), statemachineModel.name());
  QCOMPARE(statemachineModel.states().size(),4);
  model::statemachine::ConcurrentStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::ConcurrentStateItem*>(statemachineModel.states().at(1));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s2"));
  model::statemachine::RegionItem* region1 = nullptr;
  region1 = dynamic_cast<model::statemachine::RegionItem*>(state->regions().at(0));
  QCOMPARE(region1->states().count(),3);
  QCOMPARE(region1->states().at(0)->name(), QStringLiteral("init_r1"));
  QCOMPARE(region1->states().at(1)->name(), QStringLiteral("terminationstate_7"));
  QCOMPARE(region1->states().at(2)->name(), QStringLiteral("state_r1"));
  model::statemachine::RegionItem* region2 = nullptr;
  region2 = dynamic_cast<model::statemachine::RegionItem*>(state->regions().at(1));
  QCOMPARE(region2->states().count(),3);
  QCOMPARE(region2->states().at(0)->name(), QStringLiteral("init_r2"));
  QCOMPARE(region2->states().at(1)->name(), QStringLiteral("state_r2"));
  QCOMPARE(region2->states().at(2)->name(), QStringLiteral("terminationstate_9"));

  QCOMPARE(statemachineModel.transitions().size(),1);
  model::statemachine::TransitionItem* transition1 = statemachineModel.transitions().at(0);
  model::base::ATriggerItem* trigger = transition1->trigger();
  Q_ASSERT(trigger);
  QCOMPARE(trigger->triggerType(), model::base::ATriggerItem::EventTrigger);
  model::base::SignalTriggerItem* signalTrigger = static_cast<model::base::SignalTriggerItem*>(trigger);
  Q_ASSERT(signalTrigger);
  QCOMPARE(transition1->name(),QString("t1"));
  QVERIFY(signalTrigger->triggerSignal());
  QCOMPARE(signalTrigger->triggerSignal()->name(),QString("input"));
  QCOMPARE(signalTrigger->triggerSignal()->params().size(),1);
  QCOMPARE(signalTrigger->triggerSignal()->params().at(0)->name(),QString("something"));
  QCOMPARE(transition1->guard(),QString("msg.something"));
  QCOMPARE(transition1->action(),QString("somethingelse=20;"));
  QVERIFY(transition1->source());
  QCOMPARE(transition1->source()->name(),QString("s1"));
  QVERIFY(transition1->target());
  QCOMPARE(transition1->target()->name(),QString("s2"));

  QCOMPARE(command.keywordTextLocations().size(), 35);
}

void StateMachineSyntaxTest::sequentialTest(){
  //Needs only to run once

  QString docText("StateMachine {"
                  "\nname: statemachinemodel2;"
                  "\nSignal input (int something, int somethingelse);"
                  "\nPort port01;"
                  "\nCompositeState{   //ich rate mal das so ein CompositeState funktioniert... sehe allerdings noch nicht wie man diese states dem compositestateitem hinzufügt..."
                  "\nname: s2;"
                  "\nentry: somethingelse = 10; // will be saved as just a QString"
                  "\nexit: somethingelse = 11;"
                  "\nSimpleState {"
                  "\nname: s21;"
                  "\nentry: somethingelse = 12;"
                  "\nexit: somethingelse = 13;"
                  "\n}"
                  "\nSimpleState {"
                  "\nname: s22;"
                  "\nentry: somethingelse = 14;"
                  "\nexit: somethingelse = 15;"
                  "\n}"
                  "\nFinalState{"
                  "\nname: s23;"
                  "\n}"

                  "\ninitState: s20;"
                  "\nSimpleState s20;"

                  "\n}"

                  "\nJunctionState {"
                  "\n name: s3;"
                  "\n}"
                  "\nFinalState {"
                  "\nname: s5;"
                  "\n}"

                  "\ninitState: s1;"
                  "\nSimpleState s1;"

                  "\nSignalTransition {"
                  "\nname: t1;"
                  "\nsignal: input;"
                  "\nport: port01;"
                  "\nguard: something==2;"
                  "\naction: somethingelse=20;"
                  "\nsource: s1;"
                  "\ntarget: s2;"
                  "\n}"
                  "\n}"
                  );
  for(int i = docText.size();i>=0;i--){
    QString newText = docText;
    newText.chop(i);
    model::statemachine::StateMachineModel statemachineModel;
    dslparser::statemachine::ComBuildStateMachineModel command(newText, &statemachineModel);

    QString errorString;
    command.execute(&errorString);
  }

  return;
}

void StateMachineSyntaxTest::basicFunctionDeclTest()
{
  QString docText("StateMachine {"
                  "name: statemachinemodel2;"
                  "Type int(0..8) someType;"
                  "Attribute int a =0;"
                  "Function someType someFunction(someType inputVal, someType secondInputVal) {"
                  "return inputVal + secondInputVal;"
                  "}"
                  "initState: s1;"
                  "SimpleState s1;"
                  "SimpleState {"
                  "name: s2;"
                  "entry: a = someFunction(5, 6);" // will be saved as just a QString
                  "exit: someFunction(3, 4);"
                  "}"
                  "}");

  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachinemodel2"), statemachineModel.name());

  QCOMPARE(statemachineModel.dataTypes().size(), 4);
  model::base::DataTypeItem* typeItem = statemachineModel.dataTypes().at(3);
  QVERIFY(typeItem);
  QCOMPARE(typeItem->name(), QStringLiteral("someType"));
  QCOMPARE(typeItem->typeBaseString(), QStringLiteral("int"));
  QCOMPARE(typeItem->lowest(), QStringLiteral("0"));
  QCOMPARE(typeItem->highest(), QStringLiteral("8"));

  QCOMPARE(statemachineModel.functions().size(), 1);
  model::base::FunctionItem *functionItem = statemachineModel.functions().at(0);
  QVERIFY(functionItem);
  QCOMPARE(functionItem->name(), QStringLiteral("someFunction"));
  QCOMPARE(functionItem->statementBody(), QStringLiteral("return inputVal + secondInputVal;"));
  QCOMPARE(functionItem->params().size(), 2);
  model::base::ParamItem* paramItem1 = functionItem->params().at(0);
  QVERIFY(paramItem1);
  QCOMPARE(paramItem1->dataType(), typeItem->name());
  QCOMPARE(paramItem1->name(), QStringLiteral("inputVal"));

  model::base::ParamItem* paramItem2 = functionItem->params().at(1);
  QVERIFY(paramItem2);
  QCOMPARE(paramItem2->dataType(), typeItem->name());
  QCOMPARE(paramItem2->name(), QStringLiteral("secondInputVal"));

  QCOMPARE(statemachineModel.states().size(),2);
  model::statemachine::SimpleStateItem* state = nullptr;
  state = dynamic_cast<model::statemachine::SimpleStateItem*>(statemachineModel.states().at(1));
  QVERIFY(state);
  QCOMPARE(state->name(),QStringLiteral("s2"));
  QCOMPARE(state->isEnabled(),true);
  QCOMPARE(state->entryAction(), QString("a = someFunction(5, 6);"));
  QCOMPARE(state->exitAction(), QString("someFunction(3, 4);"));
  const model::statemachine::AbstractStateItem* initState = nullptr;
  initState = statemachineModel.initState();
  QVERIFY(initState);
  QCOMPARE(initState->name(),QString("s1"));
  return;
}

void StateMachineSyntaxTest::functionConditionStatementTest()
{
  QString docText("StateMachine {"
                  "name: statemachinemodel;"
                  "Type real realType;"
                  "Type bool boolType;"
                  "Function boolType checkFunction(realType var) {"
                  "if ( var <= 0 )"
                  "{"
                  "return false;"
                  "}"
                  "else"
                  "{"
                  "return true;"
                  "}"
                  "}"
                  "Function realType someFunction(realType inputVal, boolType secondInputVal) {"
                  "if ( ( inputVal == 0 ) &&"
                  "( inputVal == secondInputVal ) &&"
                  "( checkFunction(inputVal) ) )"
                  "{"
                  "return 0;"
                  "}"
                  "else if ( inputVal >= 0 )"
                  "{"
                  "return 1;"
                  "}"
                  "else"
                  "{"
                  "return 2;"
                  "}"
                  "}"
                  "}");

  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachinemodel"), statemachineModel.name());

  QCOMPARE(statemachineModel.dataTypes().size(), 5);
  model::base::DataTypeItem* typeItem = statemachineModel.dataTypes().at(3);
  QVERIFY(typeItem);
  QCOMPARE(typeItem->name(), QStringLiteral("realType"));
  QCOMPARE(typeItem->typeBaseString(), QStringLiteral("real"));

  model::base::DataTypeItem* typeItem2 = statemachineModel.dataTypes().at(4);
  QVERIFY(typeItem2);
  QCOMPARE(typeItem2->name(), QStringLiteral("boolType"));
  QCOMPARE(typeItem2->typeBaseString(), QStringLiteral("bool"));

  QCOMPARE(statemachineModel.functions().size(), 2);
  model::base::FunctionItem *functionItem = statemachineModel.functions().at(0);
  QVERIFY(functionItem);
  QCOMPARE(functionItem->name(), QStringLiteral("checkFunction"));
  QCOMPARE(functionItem->params().size(), 1);
  const QString returnType = functionItem->returnType();
  QVERIFY(!returnType.isEmpty());
  QCOMPARE(returnType, typeItem2->name());
  model::base::ParamItem* paramItem1 = functionItem->params().at(0);
  QVERIFY(paramItem1);
  QCOMPARE(paramItem1->dataType(), typeItem->name());
  QCOMPARE(paramItem1->name(), QStringLiteral("var"));

  model::base::FunctionItem *functionItem2 = statemachineModel.functions().at(1);
  QVERIFY(functionItem2);
  QCOMPARE(functionItem2->name(), QStringLiteral("someFunction"));
  //QCOMPARE(functionItem2->statementBody(), statementBodyText);
  QCOMPARE(functionItem2->params().size(), 2);
  model::base::ParamItem* paramItem2 = functionItem2->params().at(0);
  QVERIFY(paramItem2);
  QCOMPARE(paramItem2->dataType(), typeItem->name());
  QCOMPARE(paramItem2->name(), QStringLiteral("inputVal"));
  model::base::ParamItem* paramItem3 = functionItem2->params().at(1);
  QVERIFY(paramItem3);
  QCOMPARE(paramItem3->dataType(), typeItem2->name());
  QCOMPARE(paramItem3->name(), QStringLiteral("secondInputVal"));
  const QString returnType2 = functionItem2->returnType();
  QVERIFY(!returnType2.isEmpty());
  QCOMPARE(returnType2, typeItem->name());

  return;
}

void StateMachineSyntaxTest::functionFalseConditionStatementTest()
{
  //Test1: No if before else statement
  QString docText("StateMachine {"
                  "name: statemachinemodel;"
                  "Type int(0..8) intType;"
                  "Type bool boolType;"
                  "Function boolType checkFunction(intType var) {"
                  "else"
                  "{"
                  "return true;"
                  "}"
                  "}"
                  "Function intType someFunction(intType inputVal, boolType secondInputVal) {"
                  "if ( ( inputVal == 0 ) &&"
                  "( inputVal == secondInputVal ) &&"
                  "( checkFunction(inputVal) ) )"
                  "{"
                  "return 0;"
                  "}"
                  "else if ( inputVal >= 0 )"
                  "{"
                  "return 1;"
                  "}"
                  "else"
                  "{"
                  "return 2;"
                  "}"
                  "}"
                  "}");

  model::statemachine::StateMachineModel statemachineModel;
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result == false, errorString.toLatin1());
  QVERIFY(command.errors().count() > 0);

  //test2: no if before if else statement
  QString docText2("StateMachine {"
                   "name: statemachinemodel;"
                   "Type int(0..8) intType;"
                   "Type bool boolType;"
                   "Function boolType checkFunction(intType var) {"
                   "if else ( var <= 0 )"
                   "{"
                   "return false;"
                   "}"

                   "}"
                   "Function intType someFunction(intType inputVal, boolType secondInputVal) {"
                   "if ( ( inputVal == 0 ) &&"
                   "( inputVal == secondInputVal ) &&"
                   "( checkFunction(inputVal) ) )"
                   "{"
                   "return 0;"
                   "}"
                   "else if ( inputVal >= 0 )"
                   "{"
                   "return 1;"
                   "}"
                   "else"
                   "{"
                   "return 2;"
                   "}"
                   "}"
                   "}");

  statemachineModel.reset();
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildStateMachineModel command2(docText2, &statemachineModel);

  errorString.clear();
  result = command2.execute(&errorString);
  QVERIFY2(result == false, errorString.toLatin1());
  QVERIFY(command2.errors().count() > 0);

  //test3: no expression in if condition
  QString docText3("StateMachine {"
                   "name: statemachinemodel;"
                   "Type int(0..8) intType;"
                   "Type bool boolType;"
                   "Function boolType checkFunction(intType var) {"
                   "if()"
                   "{"
                   "return false;"
                   "}"

                   "}"
                   "Function intType someFunction(intType inputVal, boolType secondInputVal) {"
                   "if ( ( inputVal == 0 ) &&"
                   "( inputVal == secondInputVal ) &&"
                   "( checkFunction(inputVal) ) )"
                   "{"
                   "return 0;"
                   "}"
                   "else if ( inputVal >= 0 )"
                   "{"
                   "return 1;"
                   "}"
                   "else"
                   "{"
                   "return 2;"
                   "}"
                   "}"
                   "}");

  statemachineModel.reset();
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildStateMachineModel command3(docText3, &statemachineModel);

  errorString.clear();
  result = command3.execute(&errorString);
  QVERIFY2(result == false, errorString.toLatin1());
  QVERIFY(command3.errors().count() > 0);

  //test4: missing left bracket in if expression
  QString docText4("StateMachine {"
                   "name: statemachinemodel;"
                   "Type int(0..8) intType;"
                   "Type bool boolType;"
                   "Function boolType checkFunction(intType var) {"
                   "if()"
                   "{"
                   "return false;"
                   "}"

                   "}"
                   "Function intType someFunction(intType inputVal, boolType secondInputVal) {"
                   "if ( ( inputVal == 0  &&"
                   "( inputVal == secondInputVal ) &&"
                   "( checkFunction(inputVal) ) )"
                   "{"
                   "return 0;"
                   "}"
                   "else if ( inputVal >= 0 )"
                   "{"
                   "return 1;"
                   "}"
                   "else"
                   "{"
                   "return 2;"
                   "}"
                   "}"
                   "}");

  statemachineModel.reset();
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildStateMachineModel command4(docText4, &statemachineModel);

  errorString.clear();
  result = command4.execute(&errorString);
  QVERIFY2(result == false, errorString.toLatin1());
  QVERIFY(command4.errors().count() > 0);

  return;
}

void StateMachineSyntaxTest::functionSwitchCaseStatementTest()
{
  QString docText("StateMachine {\n"
                  "name: statemachinemodel;\n"
                  "Type int(0..8) intType;\n"
                  "Type bool boolType;\n"
                  "Type real realType;\n"
                  "Function boolType inverseFunction(intType var) {\n"
                  "intType inverseVar;\n"
                  "switch (var)\n"
                  "{\n"
                  "case 0:{ inverseVar = 7; break;}\n"
                  "case 1:{ inverseVar = 6; break;}\n"
                  "case 2:{ inverseVar = 5; break;}\n"
                  "case 3:{ inverseVar = 4; break;}\n"
                  "case 4:{ inverseVar = 3; break;}\n"
                  "case 5:{ inverseVar = 2; break;}\n"
                  "case 6:{ inverseVar = 1; break;}\n"
                  "case 7:{ inverseVar = 0; break;}\n"
                  "default:{ inverseVar = 7; break;}\n"
                  "}\n"
                  "return inverseVar;\n"
                  "}\n"
                  "}");

  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachinemodel"), statemachineModel.name());

  QCOMPARE(statemachineModel.dataTypes().size(), 6);
  model::base::DataTypeItem* typeItem = statemachineModel.dataTypes().at(3);
  QVERIFY(typeItem);
  QCOMPARE(typeItem->name(), QStringLiteral("intType"));
  QCOMPARE(typeItem->typeBaseString(), QStringLiteral("int"));
  QCOMPARE(typeItem->lowest(), QStringLiteral("0"));
  QCOMPARE(typeItem->highest(), QStringLiteral("8"));

  model::base::DataTypeItem* typeItem2 = statemachineModel.dataTypes().at(4);
  QVERIFY(typeItem2);
  QCOMPARE(typeItem2->name(), QStringLiteral("boolType"));
  QCOMPARE(typeItem2->typeBaseString(), QStringLiteral("bool"));

  QCOMPARE(statemachineModel.functions().size(), 1);
  model::base::FunctionItem *functionItem = statemachineModel.functions().at(0);
  QVERIFY(functionItem);
  QCOMPARE(functionItem->name(), QStringLiteral("inverseFunction"));
  QCOMPARE(functionItem->params().size(), 1);
  const QString returnType = functionItem->returnType();
  QVERIFY(!returnType.isEmpty());
  QCOMPARE(returnType, typeItem2->name());
  model::base::ParamItem* paramItem1 = functionItem->params().at(0);
  QVERIFY(paramItem1);
  QCOMPARE(paramItem1->dataType(), typeItem->name());
  QCOMPARE(paramItem1->name(), QStringLiteral("var"));

  return;
}

void StateMachineSyntaxTest::functionFalseSwitchCaseStatementTest()
{
  //this IS an allowed syntax!!!!
    //Test1: No brackets for each case statement except the first
  QString docText("StateMachine {"
                  "name: statemachinemodel;"
                  "Type int(0..8) intType;"
                  "Type bool boolType;"
                  "Type real realType;"
                  "Function boolType inverseFunction(intType var) {"
                  "intType inverseVar;"
                  "switch (var)"
                  "{"
                  "case 0:{ inverseVar = 7; break;}"
                  "case 1: inverseVar = 6; break;"
                  "case 2: inverseVar = 5; break;"
                  "case 3: inverseVar = 4; break;"
                  "case 4: inverseVar = 3; break;"
                  "case 5: inverseVar = 2; break;"
                  "case 6: inverseVar = 1; break;"
                  "case 7: inverseVar = 0; break;"
                  "default: inverseVar = 7; break;"
                  "}"
                  "return inverseVar;"
                  "}"
                  "}");

    model::statemachine::StateMachineModel statemachineModel;
    dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

    QString errorString;
    bool result = command.execute(&errorString);
    for(const dslparser::DslError& error : command.errors())
      qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
    QVERIFY2(result == true, errorString.toLatin1());
    QVERIFY(command.errors().count() == 0);

    //test2: switch token is missing
    QString docText2("StateMachine {"
                    "name: statemachinemodel;"
                    "Type int(0..8) intType;"
                    "Type bool boolType;"
                    "Type real realType;"
                    "Function boolType inverseFunction(intType var) {"
                    "intType inverseVar;"
                    "case 0:{ inverseVar = 7; break;}"
                    "case 1:{ inverseVar = 6; break;}"
                    "case 2:{ inverseVar = 5; break;}"
                    "case 3:{ inverseVar = 4; break;}"
                    "case 4:{ inverseVar = 3; break;}"
                    "case 5:{ inverseVar = 2; break;}"
                    "case 6:{ inverseVar = 1; break;}"
                    "case 7:{ inverseVar = 0; break;}"
                    "default:{ inverseVar = 7; break;}"
                    "return inverseVar;"
                    "}"
                    "}");

    statemachineModel.reset();
    //QVERIFY(statemachineModel);
    dslparser::statemachine::ComBuildStateMachineModel command2(docText2, &statemachineModel);

    errorString.clear();
    result = command2.execute(&errorString);
    QVERIFY2(result == false, errorString.toLatin1());
    QVERIFY(command2.errors().count() > 0);

    //test3: no expression for switch statement
    QString docText3("StateMachine {"
                    "name: statemachinemodel;"
                    "Type int(0..8) intType;"
                    "Type bool boolType;"
                    "Type real realType;"
                    "Function boolType inverseFunction(intType var) {"
                    "intType inverseVar;"
                    "switch ()"
                    "{"
                    "case 0:{ inverseVar = 7; break;}"
                    "case 1:{ inverseVar = 6; break;}"
                    "case 2:{ inverseVar = 5; break;}"
                    "case 3:{ inverseVar = 4; break;}"
                    "case 4:{ inverseVar = 3; break;}"
                    "case 5:{ inverseVar = 2; break;}"
                    "case 6:{ inverseVar = 1; break;}"
                    "case 7:{ inverseVar = 0; break;}"
                    "default:{ inverseVar = 7; break;}"
                    "}"
                    "return inverseVar;"
                    "}"
                    "}");

    statemachineModel.reset();
    //QVERIFY(statemachineModel);
    dslparser::statemachine::ComBuildStateMachineModel command3(docText3, &statemachineModel);

    errorString.clear();
    result = command3.execute(&errorString);
    QVERIFY2(result == false, errorString.toLatin1());
    QVERIFY(command3.errors().count() > 0);

    //test4: missing colon on all cases except the first
    QString docText4("StateMachine {"
                    "name: statemachinemodel;"
                    "Type int(0..8) intType;"
                    "Type bool boolType;"
                    "Type real realType;"
                    "Function boolType inverseFunction(intType var) {"
                    "intType inverseVar;"
                    "switch (var)"
                    "{"
                    "case 0 { inverseVar = 7; break;}"
                    "case 1 { inverseVar = 6; break;}"
                    "case 2: { inverseVar = 5; break;}"
                    "case 3 { inverseVar = 4; break;}"
                    "case 4 { inverseVar = 3; break;}"
                    "case 5: { inverseVar = 2; break;}"
                    "case 6 { inverseVar = 1; break;}"
                    "case 7 { inverseVar = 0; break;}"
                    "default { inverseVar = 7; break;}"
                    "}"
                    "return inverseVar;"
                    "}"
                    "}");

    statemachineModel.reset();
    //QVERIFY(statemachineModel);
    dslparser::statemachine::ComBuildStateMachineModel command4(docText4, &statemachineModel);

  errorString.clear();
  result = command4.execute(&errorString);
  QVERIFY2(result == false, errorString.toLatin1());
  QVERIFY(command4.errors().count() > 0);

  return;
}

void StateMachineSyntaxTest::functionAttributeReturnStatementTest()
{
  QString docText("StateMachine {\n"
                  "name: statemachinemodel;\n"
                  "Type int(0..8) intType;\n"
                  "Type bool boolType;\n"
                  "Type real realType;\n"
                  "Attribute realType balance;\n"
                  "Attribute boolType alive;\n"
                  "Attribute intType warnings;\n"
                  "Function boolType testFunction(intType intVar, realType realVar, boolType boolVar) {\n"
                  "alive = false;\n"
                  "alive = true;\n"
                  "balance = 9001;\n"
                  "warnings = 42;\n"
                  "warnings = 42 + 1 - 1 / 2 * 3 - -1;\n"
                  "balance = balance + realVar;\n"
                  "warnings= warnings + intVar;\n"
                  "alive = boolVar;\n"
                  "return intVar + 5 - balance * warnings /29;\n"
                  "}\n"
                  "}");

  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();
  QVERIFY2(result == true, errorString.toLatin1());
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("statemachinemodel"), statemachineModel.name());

  QCOMPARE(statemachineModel.dataTypes().size(), 6);
  QCOMPARE(statemachineModel.attributes().size(), 3);

  return;
}

void StateMachineSyntaxTest::functionFalseAttributeReturnStatementTest()
{
  //test1: invalid use of equation symbol
  QString docText("StateMachine {\n"
                  "name: statemachinemodel;\n"
                  "Type int(0..8) intType;\n"
                  "Type bool boolType;\n"
                  "Type real realType;\n"
                  "Attribute realType balance;\n"
                  "Attribute boolType alive;\n"
                  "Attribute intType warnings;\n"
                  "Function boolType testFunction(intType intVar, realType realVar, boolType boolVar) {\n"
                  "alive = false;\n"
                  "alive = true;\n"
                  "balance = 9001;\n"
                  "warnings == 42;\n"
                  "warnings = 42 + 1 - 1 / 2 * 3 = -1;\n"
                  "balance = balance + realVar;\n"
                  "alive = boolVar;\n"
                  "return intVar + 5 - balance * warnings /29;\n"
                  "}\n"
                  "}");

  model::statemachine::StateMachineModel statemachineModel;
  dslparser::statemachine::ComBuildStateMachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result == false, errorString.toLatin1());
  QVERIFY(command.errors().count() > 0);

  return;
}

/*
void StateMachineSyntaxTest::simplestatemachineErrorTest_1()
{
  QString docText("statemachine{ Declaration {name: statemachine_4; enabled:  false;} Timer@testsystem.car2X defaultTimer = 500;}");
  model::ts::TestSuite testSuiteModel;
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("Incorrect Path to Component!"), errorString);
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_2()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_5.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_3()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_6.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(3, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_4()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_7.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(3, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_5()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_8.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(3, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_6()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_9.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(4, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_7()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_10.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_8()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_11.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_9()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_12.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineErrorTest_10()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_statemachine_13.statemachine";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(5, command.errors().count());
  return;
}

void StateMachineSyntaxTest::simplestatemachineDeclKeywordTest_1()
{
  QString docText("statemachine{ Declaration {name: mystatemachine;}}");
  model::statemachine::statemachineItem statemachineModel(QString("test"));
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, &statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mystatemachine"), statemachineModel.name());

  QCOMPARE(command.keywordTextLocations().size(), 3);
  QCOMPARE(command.keywordTextLocations().at(2).start(), 0); //Testcase
  QCOMPARE(command.keywordTextLocations().at(2).length(), 8);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 10); //Declaration
  QCOMPARE(command.keywordTextLocations().at(1).length(), 11);
  QCOMPARE(command.keywordTextLocations().at(0).start(), 23); //name
  QCOMPARE(command.keywordTextLocations().at(0).length(), 4);

  QCOMPARE(1, command.modelTextLocations().size());
  return;
}
*/
void StateMachineSyntaxTest::simplestateMachineDeclKeywordTest_2()
{
  /*
  QString docText("statemachine{ name: mystatemachine; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  QString errorString1;
  model::statemachine::statemachineItem* statemachineModel(QString("test"),&errorString1);
  //QVERIFY(statemachineModel);
  dslparser::statemachine::ComBuildstatemachineModel command(docText, statemachineModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("mystatemachine"), statemachineModel.name());

  model::base::ComponentItem* component_1 = statemachineModel.components().at(1);
  QVERIFY(component_1);
  QCOMPARE(QString("Comp1"), component_1->name());
  QCOMPARE(component_1->ports().size(), 3);//with default port
  model::base::PortItem* port1 = component_1->ports().at(1);
  QCOMPARE(QString("p1"), port1->name());
  model::base::PortItem* port2 = component_1->ports().at(2);
  QCOMPARE(QString("p2"), port2->name());

  model::base::ComponentItem* component_2 = statemachineModel.components().at(2);
  QVERIFY(component_2);
  QCOMPARE(QString("Comp2"), component_2->name());
  QCOMPARE(component_2->ports().size(), 3);//with default port
  model::base::PortItem* port3 = component_2->ports().at(1);
  QCOMPARE(QString("p3"), port3->name());
  model::base::PortItem* port4 = component_2->ports().at(2);
  QCOMPARE(QString("p4"), port4->name());

  QCOMPARE(11, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(10).start(), 0); //statemachine
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
  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());*/
  return;
}

QTEST_GUILESS_MAIN(StateMachineSyntaxTest)

#include "tst_statemachinesyntax.moc"
