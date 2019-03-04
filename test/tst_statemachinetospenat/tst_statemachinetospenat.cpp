/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QString>
#include <QtTest>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <mobata/model/base/comsavebasemodel.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/functionitem.hpp>
#include <mobata/model/base/io/readbasemodel.hpp>

#include <mobata/model/statemachine/types.hpp>
#include <mobata/convert/statemachine/comstatemachinetospenat.hpp>
#include <mobata/model/statemachine/statemachine.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/simplestateitem.hpp>
#include <mobata/model/statemachine/compositestateitem.hpp>
#include <mobata/model/statemachine/concurrentstateitem.hpp>
#include <mobata/model/statemachine/junctionstateitem.hpp>
#include <mobata/model/statemachine/choicestateitem.hpp>
#include <mobata/model/statemachine/finalstateitem.hpp>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>

#include <mobata/model/base/signaltriggeritem.hpp>
#include <mobata/model/base/timeouttriggeritem.hpp>

using namespace model::statemachine;
using namespace model::spenat;
using namespace convert::statemachine;

class StateMachineToSpenat : public QObject
{
  Q_OBJECT

public:
  StateMachineToSpenat();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void convertEmpty();
  void convertSignals();
  void convertAttributes();
  void convertFunctions();
  void convertPorts();
  void convertSimpleState();
  void convertJunctionState();
  void convertChoiceState();
  void convertFinalState();
  void convertNestedFinalState();
  void convertCompositeState();
  void convertComplexCompositeState();
  void convertConcurrentState();
  void convertSimpleTransition();
  void convertJunctionTransition();
  void convertCompositeTransition();
  //tests for special cases
  void testComposite_EntryByInitState();
  void testComposite_InvalidEntryByInitState();
  //exit tests
  void testComposite_ExitByFinalState();
  void testComposite_InvalidExitByFinalState();
  void testComposite_ExitByTriggerTransition();
  //trace convert
  void testTraceConvert();
};

StateMachineToSpenat::StateMachineToSpenat()
{}

void StateMachineToSpenat::initTest()
{}

void StateMachineToSpenat::cleanupTest()
{}

void StateMachineToSpenat::convertEmpty()
{
  StateMachineModel smModel;
  smModel.setName(QStringLiteral("testModel"));

  SpenatDeclModel spenatModel;
  spenatModel.setName(QStringLiteral("wrongName"));
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.name(), smModel.name());
}

void StateMachineToSpenat::convertSignals()
{
  StateMachineModel smModel;
  model::base::DataTypeItem* dataType = smModel.addDataType(QStringLiteral("testType"));
  QVERIFY(dataType);
  model::base::SignalItem* simpleSignal = smModel.addSignal(QStringLiteral("simpleSignal"));
  QVERIFY(simpleSignal);
  model::base::SignalItem* paramSignal = smModel.addSignal(QStringLiteral("paramSignal"));
  QVERIFY(paramSignal);
  model::base::ParamItem* param = paramSignal->addParameter(QStringLiteral("param"),
                                                            dataType->name());
  QVERIFY(param);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.getSignals().size(), 2);
  model::base::SignalItem* testSimpleSignal = spenatModel.signal(simpleSignal->name());
  QVERIFY(testSimpleSignal);
  QVERIFY(testSimpleSignal->uuid() != simpleSignal->uuid());

  model::base::SignalItem* testParamSignal = spenatModel.signal(paramSignal->name());
  QVERIFY(testParamSignal);
  QVERIFY(testParamSignal->uuid() != paramSignal->uuid());
  QCOMPARE(testParamSignal->params().size(), 1);
  model::base::ParamItem* testParam = testParamSignal->parameter(param->name());
  QCOMPARE(testParam->name(), param->name());
  QVERIFY(testParam->uuid() != param->uuid());
  QString testDataTypeName = testParam->dataType();
  QCOMPARE(testDataTypeName, dataType->name());
  model::base::DataTypeItem* testDataType = spenatModel.dataType(testDataTypeName);
  QVERIFY(testDataType);
  QVERIFY(testDataType->uuid() != dataType->uuid());
}

void StateMachineToSpenat::convertAttributes()
{
  StateMachineModel smModel;
  model::base::AttributeItem* attribute = smModel.addAttribute(QStringLiteral("testAttribute"),
                                                               QStringLiteral("testDataType"),
                                                               QStringLiteral("initValue"));
  QVERIFY(attribute);
  model::base::AttributeItem* attribute2 = smModel.addAttribute(QStringLiteral("testAttribute2"),
                                                                QStringLiteral("testDataType2"),
                                                                QStringLiteral("initValue2"));

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.attributes().size(), 2);
  model::base::AttributeItem* testAttribute = spenatModel.attribute(attribute->name());
  QVERIFY(testAttribute);
  model::base::AttributeItem* testAttribute2 = spenatModel.attribute(attribute2->name());
  QVERIFY(testAttribute2);
  QCOMPARE(testAttribute->dataType(), attribute->dataType());
  QCOMPARE(testAttribute->initValue(), attribute->initValue());
  QVERIFY(testAttribute->uuid() != attribute->uuid());
}

void StateMachineToSpenat::convertFunctions()
{
  StateMachineModel smModel;
  FunctionItem* functionItem = smModel.addFunction(QStringLiteral("function"),
                                                   QStringLiteral("returnType"),
                                                   QStringLiteral("firstLine\nsecondLine"));
  FunctionItem* functionItem2 = smModel.addFunction(QStringLiteral("function2"),
                                                    QStringLiteral("returnType2"),
                                                    QStringLiteral("firstLine2\nsecondLine2"));
  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.functions().size(), 2);
  FunctionItem* testFunction = spenatModel.function(functionItem->name());
  QVERIFY(testFunction);
  FunctionItem* testFunction2 = spenatModel.function(functionItem2->name());
  QVERIFY(testFunction2);
  QVERIFY(testFunction->uuid() != functionItem->uuid());
  QCOMPARE(testFunction->returnType(), functionItem->returnType());
  QCOMPARE(testFunction->statementBody(), functionItem->statementBody());
}

void StateMachineToSpenat::convertPorts()
{
  StateMachineModel smModel;
  model::base::PortItem* portItem1 = smModel.addPort(QStringLiteral("port1"));
  model::base::PortItem* portItem2 = smModel.addPort(QStringLiteral("port2"));

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.ports().size(), 2);
  model::base::PortItem* testPortItem1 = spenatModel.port(portItem1->name());
  QVERIFY(testPortItem1);
  model::base::PortItem* testPortItem2 = spenatModel.port(portItem2->name());
  QVERIFY(testPortItem2);
  QVERIFY(testPortItem1->uuid() != portItem1->uuid());
}

void StateMachineToSpenat::convertSimpleState()
{
  StateMachineModel smModel;
  SimpleStateItem initSimpleState(QStringLiteral("initState"));
  SimpleStateItem simpleState1(QStringLiteral("simple1"));
  SimpleStateItem simpleState2(QStringLiteral("simple2"));
  bool result = smModel.addState(&initSimpleState);
  QVERIFY(result);
  result = smModel.setInitState(&initSimpleState);
  QVERIFY(result);
  result = smModel.addState(&simpleState1);
  QVERIFY(result);
  result = smModel.addState(&simpleState2);
  QVERIFY(result);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.places().size(), 3);
  QCOMPARE(spenatModel.initPlaces().size(), 1);
  PlaceItem* testInitSimpleState = spenatModel.place(initSimpleState.name());
  QVERIFY(testInitSimpleState);
  QVERIFY(spenatModel.isInitPlace(testInitSimpleState) == true);
  PlaceItem* testSimpleState1 = spenatModel.place(simpleState1.name());
  QVERIFY(testSimpleState1);
  QVERIFY(spenatModel.isInitPlace(testSimpleState1) == false);
  PlaceItem* testSimpleState2 = spenatModel.place(simpleState2.name());
  QVERIFY(testSimpleState2);
  QVERIFY(spenatModel.isInitPlace(testSimpleState2) == false);
}

void StateMachineToSpenat::convertJunctionState()
{
  StateMachineModel smModel;
  JunctionStateItem junctionState(QStringLiteral("junction"));
  bool result = smModel.addState(&junctionState);
  QVERIFY(result);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 0);
}

void StateMachineToSpenat::convertChoiceState()
{
  StateMachineModel smModel;
  ChoiceStateItem choiceState(QStringLiteral("choice"));
  bool result = smModel.addState(&choiceState);
  QVERIFY(result);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 1);
  PlaceItem* testChoicePlace = spenatModel.place(choiceState.name());
  QVERIFY(testChoicePlace);
  QVERIFY(spenatModel.isInitPlace(testChoicePlace) == false);
}

void StateMachineToSpenat::convertFinalState()
{
  StateMachineModel smModel;
  bool result = smModel.addState(new FinalStateItem(QLatin1String("final")));
  QVERIFY(result);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 1);
  PlaceItem* testFinalPlace = spenatModel.place(QLatin1String("final"));
  QVERIFY(testFinalPlace);
  QVERIFY(spenatModel.isInitPlace(testFinalPlace) == false);
}

void StateMachineToSpenat::convertNestedFinalState()
{
  StateMachineModel smModel;
  FinalStateItem finalState(QStringLiteral("final"));
  bool result = smModel.addState(&finalState);
  QVERIFY(result);
  CompositeStateItem compositeState(QStringLiteral("composite"));
  result = smModel.addState(&compositeState);
  QVERIFY(result);
  FinalStateItem nestedFinalState(QStringLiteral("nestedFinal"));
  result = compositeState.addState(&nestedFinalState);
  QVERIFY(result);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 1);
  PlaceItem* testFinalPlace = spenatModel.place(finalState.name());
  QVERIFY(testFinalPlace);
  QVERIFY(spenatModel.isInitPlace(testFinalPlace) == false);
}

void StateMachineToSpenat::convertCompositeState()
{
  StateMachineModel smModel;
  CompositeStateItem initComposite(QStringLiteral("InitComposite"));
  bool result = smModel.addState(&initComposite);
  QVERIFY(result);
  result = smModel.setInitState(&initComposite);
  QVERIFY(result);
  SimpleStateItem initSimpleState1(QStringLiteral("initSimple"));
  result = initComposite.addState(&initSimpleState1);
  QVERIFY(result);
  result = initComposite.setInitState(&initSimpleState1);
  QVERIFY(result);
  SimpleStateItem simpleState1(QStringLiteral("simple"));
  result = initComposite.addState(&simpleState1);
  QVERIFY(result);

  CompositeStateItem emptyComposite(QStringLiteral("InitComposite"));
  result = smModel.addState(&emptyComposite);
  QVERIFY(result);

  CompositeStateItem composite(QStringLiteral("composite"));
  result = smModel.addState(&composite);
  QVERIFY(result);
  SimpleStateItem initSimpleState2(QStringLiteral("initSimple2"));
  result = composite.addState(&initSimpleState2);
  QVERIFY(result);
  result = composite.setInitState(&initSimpleState2);
  QVERIFY(result);
  SimpleStateItem simpleState2(QStringLiteral("simple2"));
  result = composite.addState(&simpleState2);
  QVERIFY(result);
  SimpleStateItem simpleState3(QStringLiteral("simple3"));
  result = composite.addState(&simpleState3);
  QVERIFY(result);
  FinalStateItem finalState(QStringLiteral("final"));
  result = composite.addState(&finalState);
  QVERIFY(result);

  SpenatDeclModel spenatModel;

  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.places().size(), 5);
  QCOMPARE(spenatModel.initPlaces().size(), 2);
  PlaceItem* initPlace1 = spenatModel.place(initSimpleState1.name());
  QVERIFY(initPlace1);
  QVERIFY(spenatModel.isInitPlace(initPlace1) == true);
  PlaceItem* initPlace2 = spenatModel.place(initSimpleState2.name());
  QVERIFY(initPlace2);
  QVERIFY(spenatModel.isInitPlace(initPlace2) == true);
  PlaceItem* place1 = spenatModel.place(simpleState1.name());
  QVERIFY(place1);
  QVERIFY(spenatModel.isInitPlace(place1) == false);
  PlaceItem* place2 = spenatModel.place(simpleState2.name());
  QVERIFY(place2);
  QVERIFY(spenatModel.isInitPlace(place1) == false);
  PlaceItem* place3 = spenatModel.place(simpleState3.name());
  QVERIFY(place3);
  QVERIFY(spenatModel.isInitPlace(place1) == false);
}

void StateMachineToSpenat::convertComplexCompositeState()
{
  StateMachineModel smModel;
  CompositeStateItem initComposite(QStringLiteral("InitComposite"));
  bool result = smModel.addState(&initComposite);
  QVERIFY(result);
  result = smModel.setInitState(&initComposite);
  QVERIFY(result);
  SimpleStateItem initSimpleState1(QStringLiteral("initSimple"));
  result = initComposite.addState(&initSimpleState1);
  QVERIFY(result);
  result = initComposite.setInitState(&initSimpleState1);
  QVERIFY(result);
  SimpleStateItem simpleState1(QStringLiteral("simple"));
  result = initComposite.addState(&simpleState1);
  QVERIFY(result);
  FinalStateItem finalState1(QStringLiteral("final"));
  result = initComposite.addState(&finalState1);
  QVERIFY(result);

  CompositeStateItem composite1(QStringLiteral("InitComposite"));
  result = initComposite.addState(&composite1);
  QVERIFY(result);
  SimpleStateItem initSimpleState2(QStringLiteral("initSimple2"));
  result = composite1.addState(&initSimpleState2);
  QVERIFY(result);
  result = composite1.setInitState(&initSimpleState2);
  QVERIFY(result);
  SimpleStateItem simpleState2(QStringLiteral("simple2"));
  result = composite1.addState(&simpleState2);
  QVERIFY(result);
  SimpleStateItem simpleState3(QStringLiteral("simple3"));
  result = composite1.addState(&simpleState3);
  QVERIFY(result);
  FinalStateItem finalState2(QStringLiteral("final2"));
  result = composite1.addState(&finalState2);
  QVERIFY(result);

  CompositeStateItem composite2(QStringLiteral("composite"));
  result = initComposite.addState(&composite2);
  QVERIFY(result);
  SimpleStateItem initSimpleState3(QStringLiteral("initSimple3"));
  result = composite2.addState(&initSimpleState3);
  QVERIFY(result);
  result = composite2.setInitState(&initSimpleState3);
  QVERIFY(result);
  SimpleStateItem simpleState4(QStringLiteral("simple4"));
  result = composite2.addState(&simpleState4);
  QVERIFY(result);
  SimpleStateItem simpleState5(QStringLiteral("simple5"));
  result = composite2.addState(&simpleState5);
  QVERIFY(result);
  FinalStateItem finalState3(QStringLiteral("final3"));
  result = composite2.addState(&finalState3);
  QVERIFY(result);

  SpenatDeclModel spenatModel;

  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 8);
  QCOMPARE(spenatModel.initPlaces().size(), 3);
}

void StateMachineToSpenat::convertSimpleTransition()
{
  StateMachineModel smModel;

  SimpleStateItem initState(QStringLiteral("initState"),
                            QStringLiteral("test_initEntryAction"),
                            QStringLiteral("test_initExitAction"));
  bool result = smModel.addState(&initState);
  QVERIFY(result);
  SimpleStateItem simpleState(QStringLiteral("simpleState"),
                              QStringLiteral("test_simpleEntryAction"),
                              QStringLiteral("test_simpleExitAction"));
  result = smModel.addState(&simpleState);
  QVERIFY(result);

  model::base::SignalItem* signalItem = smModel.addSignal(QStringLiteral("signal"));
  QVERIFY(signalItem);
  model::base::PortItem* portItem = smModel.addPort(QStringLiteral("port"));
  QVERIFY(portItem);

  model::statemachine::TransitionItem* smSignalTransition = smModel.addSignalTransition("signalTransition",
                                                                                        signalItem,
                                                                                        portItem,
                                                                                        &initState,
                                                                                        &simpleState,
                                                                                        QStringLiteral("test_guard"),
                                                                                        QStringLiteral("test_action"));
  QVERIFY(smSignalTransition);


  model::statemachine::TransitionItem* smTimeoutTransition = smModel.addTimeoutTransition(QStringLiteral("timeoutTransition"),
                                                                                          double(25.5),
                                                                                          &initState,
                                                                                          &simpleState,
                                                                                          QStringLiteral("test_guard"),
                                                                                          QStringLiteral("test_action"));
  QVERIFY(smTimeoutTransition);

  SpenatDeclModel spenatModel;

  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QString combinedAction = initState.exitAction() +
                           QStringLiteral("\n") +
                           smSignalTransition->action() +
                           QStringLiteral("\n") +
                           simpleState.entryAction();

  QCOMPARE(spenatModel.places().size(), 2);
  QCOMPARE(spenatModel.transitions().size(), 2);
  model::spenat::TransitionItem* spenatSignalTransition = spenatModel.transition(smSignalTransition->name());
  QVERIFY(spenatSignalTransition);
  QCOMPARE(spenatSignalTransition->actions(), combinedAction);
  QCOMPARE(spenatSignalTransition->guard(), smSignalTransition->guard());
  const PlaceItem* prePlace = spenatModel.place(initState.name());
  QVERIFY(prePlace);
  const PrePlaceArc* prePlaceArc = spenatSignalTransition->prePlaceArc(prePlace);
  QVERIFY(prePlaceArc);
  const PlaceItem* postPlace = spenatModel.place(simpleState.name());
  QVERIFY(postPlace);
  const PostPlaceArc* postPlaceArc = spenatSignalTransition->postPlaceArc(postPlace);
  QVERIFY(postPlaceArc);
  model::spenat::TransitionItem* spenatTimeoutTransition = spenatModel.transition(smTimeoutTransition->name());
  QVERIFY(spenatTimeoutTransition);
  QCOMPARE(spenatTimeoutTransition->actions(), combinedAction);
  QCOMPARE(spenatTimeoutTransition->guard(), smTimeoutTransition->guard());
  const PrePlaceArc* prePlaceArc2 = spenatTimeoutTransition->prePlaceArc(prePlace);
  QVERIFY(prePlaceArc2);
  const PostPlaceArc* postPlaceArc2 = spenatTimeoutTransition->postPlaceArc(postPlace);
  QVERIFY(postPlaceArc2);
}

void StateMachineToSpenat::convertJunctionTransition()
{
  StateMachineModel smModel;
  SimpleStateItem preSimpleState1(QStringLiteral("preSimpleState1"),
                                  QStringLiteral("test_preSimple1EntryAction"),
                                  QStringLiteral("test_preSimple1ExitAction"));
  bool result = smModel.addState(&preSimpleState1);
  QVERIFY(result);
  SimpleStateItem preSimpleState2(QStringLiteral("preSimpleState2"),
                                  QStringLiteral("test_preSimple2EntryAction"),
                                  QStringLiteral("test_preSimple2ExitAction"));
  result = smModel.addState(&preSimpleState2);
  QVERIFY(result);

  SimpleStateItem preSimpleState3(QStringLiteral("preSimpleState3"),
                                  QStringLiteral("test_preSimple3EntryAction"),
                                  QStringLiteral("test_preSimple3ExitAction"));
  result = smModel.addState(&preSimpleState3);
  QVERIFY(result);

  SimpleStateItem postSimpleState1(QStringLiteral("postSimpleState1"),
                                   QStringLiteral("test_postSimple1EntryAction"),
                                   QStringLiteral("test_postSimple1ExitAction"));
  result = smModel.addState(&postSimpleState1);
  QVERIFY(result);
  SimpleStateItem postSimpleState2(QStringLiteral("postSimpleState2"),
                                   QStringLiteral("test_postSimple2EntryAction"),
                                   QStringLiteral("test_postSimple2ExitAction"));
  result = smModel.addState(&postSimpleState2);
  QVERIFY(result);

  SimpleStateItem postSimpleState3(QStringLiteral("postSimpleState3"),
                                   QStringLiteral("test_postSimple3EntryAction"),
                                   QStringLiteral("test_postSimple3ExitAction"));
  result = smModel.addState(&postSimpleState3);
  QVERIFY(result);

  JunctionStateItem junctionState(QStringLiteral("junctionState"));
  result = smModel.addState(&junctionState);
  QVERIFY(result);

  model::base::SignalItem* signalItem = smModel.addSignal(QStringLiteral("signal"));
  QVERIFY(signalItem);
  model::base::PortItem* portItem = smModel.addPort(QStringLiteral("port"));
  QVERIFY(portItem);

  model::statemachine::TransitionItem* smPreTransition1 = smModel.addSignalTransition("signalTransition1",
                                                                                      signalItem,
                                                                                      portItem,
                                                                                      &preSimpleState1,
                                                                                      &junctionState,
                                                                                      QStringLiteral("preGuard1"),
                                                                                      QStringLiteral("preTransitionAction1"));
  QVERIFY(smPreTransition1);

  model::statemachine::TransitionItem* smPreTransition2 = smModel.addSignalTransition("signalTransition2",
                                                                                      signalItem,
                                                                                      portItem,
                                                                                      &preSimpleState2,
                                                                                      &junctionState,
                                                                                      QStringLiteral("preGuard2"),
                                                                                      QStringLiteral("preTransitionAction2"));
  QVERIFY(smPreTransition2);

  model::statemachine::TransitionItem* smPreTransition3 = smModel.addSignalTransition("signalTransition3",
                                                                                      signalItem,
                                                                                      portItem,
                                                                                      &preSimpleState3,
                                                                                      &junctionState,
                                                                                      QStringLiteral("preGuard3"),
                                                                                      QStringLiteral("preTransitionAction3"));
  QVERIFY(smPreTransition3);


  model::statemachine::TransitionItem* smPostTransition1 = junctionState.addJunctionTransition("junctionTransition1",
                                                                                               &postSimpleState1,
                                                                                               QStringLiteral("postGuard1"),
                                                                                               QStringLiteral("postTransitionAction1"));
  QVERIFY(smPostTransition1);

  model::statemachine::TransitionItem* smPostTransition2 = junctionState.addJunctionTransition("junctionTransition2",
                                                                                               &postSimpleState2,
                                                                                               QStringLiteral("postGuard2"),
                                                                                               QStringLiteral("postTransitionAction2"));
  QVERIFY(smPostTransition2);

  model::statemachine::TransitionItem* smPostTransition3 = junctionState.addJunctionTransition("junctionTransition3",
                                                                                               &postSimpleState3,
                                                                                               QStringLiteral("else"),
                                                                                               QStringLiteral("postTransitionAction13"));
  QVERIFY(smPostTransition3);

  SpenatDeclModel spenatModel;

  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 6);
  QCOMPARE(spenatModel.transitions().size(), 9);

  //test transition1
  QString action1 = preSimpleState1.exitAction() +
                    QStringLiteral("\n") +
                    smPreTransition1->action() +
                    QStringLiteral("\n") +
                    smPostTransition1->action() +
                    QStringLiteral("\n") +
                    postSimpleState1.entryAction();
  QString guard1 = smPreTransition1->guard() +
                   QStringLiteral(" and ") +
                   smPostTransition1->guard();

  QString name1 = smPreTransition1->source()->name() +
                  QStringLiteral("_To_") +
                  smPostTransition1->target()->name();

  model::spenat::TransitionItem* spenatTransition1 = spenatModel.transition(name1);
  QVERIFY(spenatTransition1);
  QCOMPARE(spenatTransition1->actions(), action1);
  QCOMPARE(spenatTransition1->guard(), guard1);
  const PlaceItem* prePlace1 = spenatModel.place(preSimpleState1.name());
  QVERIFY(prePlace1);
  const PrePlaceArc* prePlaceArc1_1 = spenatTransition1->prePlaceArc(prePlace1);
  QVERIFY(prePlaceArc1_1);
  const PlaceItem* postPlace1 = spenatModel.place(postSimpleState1.name());
  QVERIFY(postPlace1);
  const PostPlaceArc* postPlaceArc1 = spenatTransition1->postPlaceArc(postPlace1);
  QVERIFY(postPlaceArc1);

  //test transition2
  QString action2 = preSimpleState1.exitAction() +
                    QStringLiteral("\n") +
                    smPreTransition1->action() +
                    QStringLiteral("\n") +
                    smPostTransition2->action() +
                    QStringLiteral("\n") +
                    postSimpleState2.entryAction();
  QString guard2 = smPreTransition1->guard() +
                   QStringLiteral(" and ") +
                   smPostTransition2->guard();

  QString name2 = smPreTransition1->source()->name() +
                  QStringLiteral("_To_") +
                  smPostTransition2->target()->name();

  model::spenat::TransitionItem* spenatTransition2 = spenatModel.transition(name2);
  QVERIFY(spenatTransition2);
  QCOMPARE(spenatTransition2->actions(), action2);
  QCOMPARE(spenatTransition2->guard(), guard2);
  const PrePlaceArc* prePlaceArc1_2 = spenatTransition2->prePlaceArc(prePlace1);
  QVERIFY(prePlaceArc1_2);
  const PlaceItem* postPlace2 = spenatModel.place(postSimpleState2.name());
  QVERIFY(postPlace1);
  const PostPlaceArc* postPlaceArc2_1 = spenatTransition2->postPlaceArc(postPlace2);
  QVERIFY(postPlaceArc2_1);

  //test transition3
  QString action3 = preSimpleState1.exitAction() +
                    QStringLiteral("\n") +
                    smPreTransition1->action() +
                    QStringLiteral("\n") +
                    smPostTransition3->action() +
                    QStringLiteral("\n") +
                    postSimpleState3.entryAction();
  QString guard3 = smPreTransition1->guard() +
                   QStringLiteral(" and not ") +
                   smPostTransition1->guard() +
                   QStringLiteral(" and not ") +
                   smPostTransition2->guard();

  QString name3 = smPreTransition1->source()->name() +
                  QStringLiteral("_To_") +
                  smPostTransition3->target()->name();

  model::spenat::TransitionItem* spenatTransition3 = spenatModel.transition(name3);
  QVERIFY(spenatTransition3);
  QCOMPARE(spenatTransition3->actions(), action3);
  QCOMPARE(spenatTransition3->guard(), guard3);
  const PrePlaceArc* prePlaceArc1_3 = spenatTransition3->prePlaceArc(prePlace1);
  QVERIFY(prePlaceArc1_3);
  const PlaceItem* postPlace3 = spenatModel.place(postSimpleState3.name());
  QVERIFY(postPlace3);
  const PostPlaceArc* postPlaceArc3_1 = spenatTransition3->postPlaceArc(postPlace3);
  QVERIFY(postPlaceArc3_1);

  //test transition5
  QString action5 = preSimpleState2.exitAction() +
                    QStringLiteral("\n") +
                    smPreTransition2->action() +
                    QStringLiteral("\n") +
                    smPostTransition2->action() +
                    QStringLiteral("\n") +
                    postSimpleState2.entryAction();
  QString guard5 = smPreTransition2->guard() +
                   QStringLiteral(" and ") +
                   smPostTransition2->guard();

  QString name5 = smPreTransition2->source()->name() +
                  QStringLiteral("_To_") +
                  smPostTransition2->target()->name();

  model::spenat::TransitionItem* spenatTransition5 = spenatModel.transition(name5);
  QVERIFY(spenatTransition5);
  QCOMPARE(spenatTransition5->actions(), action5);
  QCOMPARE(spenatTransition5->guard(), guard5);
  const PlaceItem* prePlace2 = spenatModel.place(preSimpleState2.name());
  QVERIFY(prePlace2);
  const PrePlaceArc* prePlaceArc2 = spenatTransition5->prePlaceArc(prePlace2);
  QVERIFY(prePlaceArc2);
  const PostPlaceArc* postPlaceArc2_2 = spenatTransition5->postPlaceArc(postPlace2);
  QVERIFY(postPlaceArc2_2);

  //test transition9
  QString action9 = preSimpleState3.exitAction() +
                    QStringLiteral("\n") +
                    smPreTransition3->action() +
                    QStringLiteral("\n") +
                    smPostTransition3->action() +
                    QStringLiteral("\n") +
                    postSimpleState3.entryAction();

  QString guard9 = smPreTransition3->guard() +
                   QStringLiteral(" and not ") +
                   smPostTransition1->guard() +
                   QStringLiteral(" and not ") +
                   smPostTransition2->guard();

  QString name9 = smPreTransition3->source()->name() +
                  QStringLiteral("_To_") +
                  smPostTransition3->target()->name();

  model::spenat::TransitionItem* spenatTransition9 = spenatModel.transition(name9);
  QVERIFY(spenatTransition9);
  QCOMPARE(spenatTransition9->actions(), action9);
  QCOMPARE(spenatTransition9->guard(), guard9);
  const PlaceItem* prePlace3 = spenatModel.place(preSimpleState3.name());
  QVERIFY(prePlace3);
  const PrePlaceArc* prePlaceArc3 = spenatTransition9->prePlaceArc(prePlace3);
  QVERIFY(prePlaceArc3);
  const PostPlaceArc* postPlaceArc3_2 = spenatTransition9->postPlaceArc(postPlace3);
  QVERIFY(postPlaceArc3_2);
}

void StateMachineToSpenat::convertCompositeTransition()
{
  StateMachineModel smModel;
  //hierarchy: root
  CompositeStateItem compositeRoot(QStringLiteral("compositeRoot"));
  compositeRoot.setEntryAction(QStringLiteral("entryRoot"));
  compositeRoot.setExitAction(QStringLiteral("exitRoot"));
  bool result = smModel.addState(&compositeRoot);
  QVERIFY(result);

  SimpleStateItem simpleRoot(QStringLiteral("simpleRoot"),
                             QStringLiteral("entrySimpleRoot"),
                             QStringLiteral("exitSimpleRoot"));
  result = compositeRoot.addState(&simpleRoot);
  QVERIFY(result);

  //hierarchy: root2
  CompositeStateItem compositeRoot2(QStringLiteral("compositeRoot2"));
  compositeRoot2.setEntryAction(QStringLiteral("entryRoot2"));
  compositeRoot2.setExitAction(QStringLiteral("exitRoot2"));
  result = smModel.addState(&compositeRoot2);
  QVERIFY(result);

  SimpleStateItem simpleRoot2(QStringLiteral("simpleRoot2"),
                              QStringLiteral("entrySimpleRoot2"),
                              QStringLiteral("exitSimpleRoot2"));
  result = compositeRoot2.addState(&simpleRoot2);
  QVERIFY(result);

  //hierarchy: level 1
  CompositeStateItem compositeLevel1(QStringLiteral("compositeLevel1"));
  compositeLevel1.setEntryAction(QStringLiteral("entryLevel1"));
  compositeLevel1.setExitAction(QStringLiteral("exitLevel1"));
  result = compositeRoot.addState(&compositeLevel1);
  QVERIFY(result);
  SimpleStateItem simpleLevel1(QStringLiteral("simpleLevel1"),
                               QStringLiteral("entrySimpleLevel1"),
                               QStringLiteral("exitSimpleLevel1"));
  result = compositeLevel1.addState(&simpleLevel1);
  QVERIFY(result);

  //hierarchy: level 2
  CompositeStateItem compositeLevel2(QStringLiteral("compositeLevel2"));
  compositeLevel2.setEntryAction(QStringLiteral("entryLevel2"));
  compositeLevel2.setExitAction(QStringLiteral("exitLevel2"));
  result = compositeLevel1.addState(&compositeLevel2);
  QVERIFY(result);
  SimpleStateItem simpleLevel2_1(QStringLiteral("simpleLevel2_1"),
                                 QStringLiteral("entrySimpleLevel2_1"),
                                 QStringLiteral("exitSimpleLevel2_1"));
  result = compositeLevel2.addState(&simpleLevel2_1);
  QVERIFY(result);
  SimpleStateItem simpleLevel2_2(QStringLiteral("simpleLevel2_2"),
                                 QStringLiteral("entrySimpleLevel2_2"),
                                 QStringLiteral("exitSimpleLevel2_2"));
  result = compositeLevel2.addState(&simpleLevel2_2);
  QVERIFY(result);

  JunctionStateItem junctionLevel2(QStringLiteral("junctionLevel2"));
  result = compositeLevel2.addState(&junctionLevel2);
  QVERIFY(result);

  //hierarchy: level 3
  CompositeStateItem compositeLevel3(QStringLiteral("compositeLevel3"));
  compositeLevel3.setEntryAction(QStringLiteral("entryLevel3"));
  compositeLevel3.setExitAction(QStringLiteral("exitLevel3"));
  result = compositeLevel2.addState(&compositeLevel3);
  QVERIFY(result);
  SimpleStateItem simpleLevel3(QStringLiteral("simpleLevel3"),
                               QStringLiteral("entrySimpleLevel3"),
                               QStringLiteral("exitSimpleLevel3"));
  result = compositeLevel3.addState(&simpleLevel3);
  QVERIFY(result);

  //Transition root to level 1
  model::statemachine::TransitionItem* tr_root_lvl1 = smModel.addTimeoutTransition(QStringLiteral("tr_root_lvl1"),
                                                                                   1.0,
                                                                                   &simpleRoot,
                                                                                   &simpleLevel1,
                                                                                   QStringLiteral("guard_root_lvl1"),
                                                                                   QStringLiteral("action_root_lvl1"));
  QVERIFY(tr_root_lvl1);

  //Transition root to root2
  model::statemachine::TransitionItem* tr_root_root2 = smModel.addTimeoutTransition(QStringLiteral("tr_root_root2"),
                                                                                    1.0,
                                                                                    &simpleRoot,
                                                                                    &simpleRoot2,
                                                                                    QStringLiteral("guard_root_root2"),
                                                                                    QStringLiteral("action_root_root2"));
  QVERIFY(tr_root_root2);

  //Transition level 1 to level 3
  model::statemachine::TransitionItem* tr_lvl1_lvl3 = smModel.addTimeoutTransition(QStringLiteral("tr_lvl1_lvl3"),
                                                                                   1.0,
                                                                                   &simpleLevel1,
                                                                                   &simpleLevel3,
                                                                                   QStringLiteral("guard_lvl1_lvl3"),
                                                                                   QStringLiteral("action_lvl1_lvl3"));
  QVERIFY(tr_lvl1_lvl3);

  //Transition level 2_1 to level 2_2
  model::statemachine::TransitionItem* tr_lvl2_lvl2 = smModel.addTimeoutTransition(QStringLiteral("tr_lvl2_lvl2"),
                                                                                   1.0,
                                                                                   &simpleLevel2_1,
                                                                                   &simpleLevel2_2,
                                                                                   QStringLiteral("guard_lvl2_lvl2"),
                                                                                   QStringLiteral("action_lvl2_lvl2"));
  QVERIFY(tr_lvl2_lvl2);

  //Transition level 3 to level 2_1
  model::statemachine::TransitionItem* tr_lvl3_lvl2 = smModel.addTimeoutTransition(QStringLiteral("tr_lvl3_lvl2"),
                                                                                   1.0,
                                                                                   &simpleLevel3,
                                                                                   &simpleLevel2_1,
                                                                                   QStringLiteral("guard_lvl3_lvl2"),
                                                                                   QStringLiteral("action_lvl3_lvl2"));
  QVERIFY(tr_lvl3_lvl2);

  //Transition level 3 to root
  model::statemachine::TransitionItem* tr_lvl3_root = smModel.addTimeoutTransition(QStringLiteral("tr_lvl3_root"),
                                                                                   1.0,
                                                                                   &simpleLevel3,
                                                                                   &simpleRoot,
                                                                                   QStringLiteral("guard_lvl3_root"),
                                                                                   QStringLiteral("action_lvl3_root"));
  QVERIFY(tr_lvl3_root);

  //Transition level 2_2 to level 2 junction
  model::statemachine::TransitionItem* tr_lvl2_junction = smModel.addTimeoutTransition(QStringLiteral("tr_lvl2_junction"),
                                                                                       1.0,
                                                                                       &simpleLevel2_2,
                                                                                       &junctionLevel2,
                                                                                       QStringLiteral("guard_lvl2_junction"),
                                                                                       QStringLiteral("action_lvl2_junction"));
  QVERIFY(tr_lvl2_junction);

  //junction transitions
  //Junction Transition junction to root
  model::statemachine::TransitionItem* tr_junction_root = junctionLevel2.addJunctionTransition(QStringLiteral("tr_junction_root"),
                                                                                               &simpleRoot,
                                                                                               QStringLiteral("guard_junction_root"),
                                                                                               QStringLiteral("action_junction_root"));
  QVERIFY(tr_junction_root);

  //Junction Transition junction to level 3
  model::statemachine::TransitionItem* tr_junction_lvl3 = junctionLevel2.addJunctionTransition(QStringLiteral("tr_junction_lvl3"),
                                                                                               &simpleLevel3,
                                                                                               QStringLiteral("guard_junction_lvl3"),
                                                                                               QStringLiteral("action_junction_lvl3"));
  QVERIFY(tr_junction_lvl3);

  SpenatDeclModel spenatModel;

  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.places().size(), 6);
  QCOMPARE(spenatModel.transitions().size(), 8);

  //Testing action of transition root to level 1
  model::spenat::TransitionItem* spenat_tr_root_lvl1 = spenatModel.transition(tr_root_lvl1->name());
  QVERIFY(spenat_tr_root_lvl1);
  QString action_tr_root_lvl1 = simpleRoot.exitAction() +
                                QStringLiteral("\n") +
                                tr_root_lvl1->action() +
                                QStringLiteral("\n") +
                                compositeLevel1.entryAction() +
                                QStringLiteral("\n") +
                                simpleLevel1.entryAction();
  QCOMPARE(spenat_tr_root_lvl1->actions(), action_tr_root_lvl1);

  //Testing action of transition root to root 2
  model::spenat::TransitionItem* spenat_tr_root_root2 = spenatModel.transition(tr_root_root2->name());
  QVERIFY(spenat_tr_root_root2);
  QString action_tr_root_root2 = simpleRoot.exitAction() +
                                 QStringLiteral("\n") +
                                 compositeRoot.exitAction() +
                                 QStringLiteral("\n") +
                                 tr_root_root2->action() +
                                 QStringLiteral("\n") +
                                 compositeRoot2.entryAction() +
                                 QStringLiteral("\n") +
                                 simpleRoot2.entryAction();
  QCOMPARE(spenat_tr_root_root2->actions(), action_tr_root_root2);

  //Testing action of transition level 1 to level 3
  model::spenat::TransitionItem* spenat_tr_lvl1_lvl3 = spenatModel.transition(tr_lvl1_lvl3->name());
  QVERIFY(spenat_tr_lvl1_lvl3);
  QString action_tr_lvl1_lvl3 = simpleLevel1.exitAction() +
                                QStringLiteral("\n") +
                                tr_lvl1_lvl3->action() +
                                QStringLiteral("\n") +
                                compositeLevel2.entryAction() +
                                QStringLiteral("\n") +
                                compositeLevel3.entryAction() +
                                QStringLiteral("\n") +
                                simpleLevel3.entryAction();
  QCOMPARE(spenat_tr_lvl1_lvl3->actions(), action_tr_lvl1_lvl3);

  //Testing action of transition level 2_1 to level 2_2
  model::spenat::TransitionItem* spenat_tr_lvl2_lvl2 = spenatModel.transition(tr_lvl2_lvl2->name());
  QVERIFY(spenat_tr_lvl2_lvl2);
  QString action_tr_lvl2_lvl2 = simpleLevel2_1.exitAction() +
                                QStringLiteral("\n") +
                                tr_lvl2_lvl2->action() +
                                QStringLiteral("\n") +
                                simpleLevel2_2.entryAction();
  QCOMPARE(spenat_tr_lvl2_lvl2->actions(), action_tr_lvl2_lvl2);

  //Testing action of transition level 3 to level 2
  model::spenat::TransitionItem* spenat_tr_lvl3_lvl2 = spenatModel.transition(tr_lvl3_lvl2->name());
  QVERIFY(spenat_tr_lvl3_lvl2);
  QString action_tr_lvl3_lvl2 = simpleLevel3.exitAction() +
                                QStringLiteral("\n") +
                                compositeLevel3.exitAction() +
                                QStringLiteral("\n") +
                                tr_lvl3_lvl2->action() +
                                QStringLiteral("\n") +
                                simpleLevel2_1.entryAction();
  QCOMPARE(spenat_tr_lvl3_lvl2->actions(), action_tr_lvl3_lvl2);

  //Testing action of transition level 3 to level root
  model::spenat::TransitionItem* spenat_tr_lvl3_root = spenatModel.transition(tr_lvl3_root->name());
  QVERIFY(spenat_tr_lvl3_root);
  QString action_tr_lvl3_root = simpleLevel3.exitAction() +
                                QStringLiteral("\n") +
                                compositeLevel3.exitAction() +
                                QStringLiteral("\n") +
                                compositeLevel2.exitAction() +
                                QStringLiteral("\n") +
                                compositeLevel1.exitAction() +
                                QStringLiteral("\n") +
                                tr_lvl3_root->action() +
                                QStringLiteral("\n") +
                                simpleRoot.entryAction();
  QCOMPARE(spenat_tr_lvl3_root->actions(), action_tr_lvl3_root);

  //Testing action of junction transition level 2 junction to root
  QString name_junction_root = tr_lvl2_junction->name() +
                               QStringLiteral("_") +
                               tr_junction_root->name();

  QString action_junction_root = simpleLevel2_2.exitAction() +
                                 QStringLiteral("\n") +
                                 compositeLevel2.exitAction() +
                                 QStringLiteral("\n") +
                                 compositeLevel1.exitAction() +
                                 QStringLiteral("\n") +
                                 tr_lvl2_junction->action() +
                                 QStringLiteral("\n") +
                                 tr_junction_root->action() +
                                 QStringLiteral("\n") +
                                 simpleRoot.entryAction();
  model::spenat::TransitionItem* spenat_tr_junction_root = spenatModel.transition(QStringLiteral("simpleLevel2_2_To_simpleRoot"));
  QVERIFY(spenat_tr_junction_root);
  QCOMPARE(spenat_tr_junction_root->actions(), action_junction_root);

  //Testing action of junction transition level 2 junction to level 3
  QString name_junction_lvl3 = tr_lvl2_junction->name() +
                               QStringLiteral("_") +
                               tr_junction_lvl3->name();

  QString action_junction_lvl3 = simpleLevel2_2.exitAction() +
                                 QStringLiteral("\n") +
                                 tr_lvl2_junction->action() +
                                 QStringLiteral("\n") +
                                 tr_junction_lvl3->action() +
                                 QStringLiteral("\n") +
                                 compositeLevel3.entryAction() +
                                 QStringLiteral("\n") +
                                 simpleLevel3.entryAction();
  model::spenat::TransitionItem* spenat_tr_junction_lvl3 = spenatModel.transition(QStringLiteral("simpleLevel2_2_To_simpleLevel3"));
  QVERIFY(spenat_tr_junction_lvl3);
  QCOMPARE(spenat_tr_junction_lvl3->actions(), action_junction_lvl3);
}

void StateMachineToSpenat::convertConcurrentState()
{
  StateMachineModel smModel;
  ConcurrentStateItem concurrent(QStringLiteral("concurrentName"));
  smModel.addState(&concurrent);

  SpenatDeclModel spenatModel;

  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));

  QString errorString;
  bool result = command.execute(&errorString);
  QVERIFY(result == false);
}

void StateMachineToSpenat::testComposite_EntryByInitState()
{
  StateMachineModel smModel;
  SimpleStateItem rootSimple(QStringLiteral("rootSimple"),
                             QStringLiteral("enterRootSimple"),
                             QStringLiteral("exitRootSimple"));
  bool result = smModel.addState(&rootSimple);
  QVERIFY(result);
  result = smModel.setInitState(&rootSimple);
  QVERIFY(result);

  CompositeStateItem composite(QStringLiteral("composite"));
  composite.setEntryAction(QStringLiteral("enterComposite"));
  composite.setExitAction(QStringLiteral("exitComposite"));
  result = smModel.addState(&composite);
  QVERIFY(result);

  CompositeStateItem composite2(QStringLiteral("composite2"));
  composite2.setEntryAction(QStringLiteral("enterComposite2"));
  composite2.setExitAction(QStringLiteral("exitComposit2e"));
  result = smModel.addState(&composite2);
  QVERIFY(result);

  CompositeStateItem nestedComposite(QStringLiteral("nestedComposite"));
  nestedComposite.setEntryAction(QStringLiteral("enterNestedComposite"));
  nestedComposite.setExitAction(QStringLiteral("exitnestedComposit2e"));
  result = composite2.addState(&nestedComposite);
  QVERIFY(result);
  result = composite2.setInitState(&nestedComposite);
  QVERIFY(result);

  SimpleStateItem deeplyNestedSimple(QStringLiteral("deeplyNestedSimple"),
                                     QStringLiteral("enterDeeplyNestedSimple"),
                                     QStringLiteral("exitDeeplyNestedSimple"));
  result = nestedComposite.addState(&deeplyNestedSimple);
  QVERIFY(result);
  result = nestedComposite.setInitState(&deeplyNestedSimple);
  QVERIFY(result);

  SimpleStateItem nestedSimple1(QStringLiteral("nestedSimple1"),
                                QStringLiteral("enterNestedSimple1"),
                                QStringLiteral("exitNestedSimple1"));
  result = composite.addState(&nestedSimple1);
  QVERIFY(result);
  result = composite.setInitState(&nestedSimple1);
  QVERIFY(result);

  SimpleStateItem nestedSimple2(QStringLiteral("nestedSimple2"),
                                QStringLiteral("enterNestedSimple2"),
                                QStringLiteral("exitNestedSimple2"));
  result = composite.addState(&nestedSimple2);
  QVERIFY(result);

  //Transition simpleRoot to composite
  model::statemachine::TransitionItem* tr_smplRoot_composite = smModel.addTimeoutTransition(QStringLiteral("tr_smplRoot_composite"),
                                                                                            1.0,
                                                                                            &rootSimple,
                                                                                            &composite,
                                                                                            QStringLiteral("guard_smplRoot_composite"),
                                                                                            QStringLiteral("action_smplRoot_composite"));
  QVERIFY(tr_smplRoot_composite);

  //Transition simpleRoot to composite2
  model::statemachine::TransitionItem* tr_smplRoot_composite2 = smModel.addTimeoutTransition(QStringLiteral("tr_smplRoot_dplNstdSmpl"),
                                                                                             1.0,
                                                                                             &rootSimple,
                                                                                             &composite2,
                                                                                             QStringLiteral("guard_smplRoot_dplNstdSmpl"),
                                                                                             QStringLiteral("action_smplRoot_dplNstdSmpl"));
  QVERIFY(tr_smplRoot_composite2);

  //Transition nestedSimple2 to composite
  model::statemachine::TransitionItem* tr_nstdSmpl2_composite = smModel.addTimeoutTransition(QStringLiteral("tr_nstdSmpl2_composite"),
                                                                                             1.0,
                                                                                             &nestedSimple2,
                                                                                             &composite,
                                                                                             QStringLiteral("guard_nstdSmpl2_composite"),
                                                                                             QStringLiteral("action_nstdSmpl2_composite"));
  QVERIFY(tr_nstdSmpl2_composite);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));
  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 4);
  QCOMPARE(spenatModel.transitions().size(), 3);

  PlaceItem* spenat_nestedSimple1 = spenatModel.place(nestedSimple1.name());
  QVERIFY(spenat_nestedSimple1);
  QVERIFY(spenatModel.isInitPlace(spenat_nestedSimple1));

  PlaceItem* spenat_deeplyNestedSimple = spenatModel.place(deeplyNestedSimple.name());
  QVERIFY(spenat_deeplyNestedSimple);
  QVERIFY(spenatModel.isInitPlace(spenat_deeplyNestedSimple));

  model::spenat::TransitionItem* spenat_tr_smplRoot_composite = spenatModel.transition(tr_smplRoot_composite->name());
  QVERIFY(spenat_tr_smplRoot_composite);
  QString action_tr_smplRoot_composite = rootSimple.exitAction() +
                                         QStringLiteral("\n") +
                                         tr_smplRoot_composite->action() +
                                         QStringLiteral("\n") +
                                         composite.entryAction() +
                                         QStringLiteral("\n") +
                                         nestedSimple1.entryAction();
  QCOMPARE(spenat_tr_smplRoot_composite->actions(), action_tr_smplRoot_composite);

  const PostPlaceArc* postPlaceArc = spenat_tr_smplRoot_composite->postPlaceArc(spenat_nestedSimple1);
  QVERIFY(postPlaceArc);

  model::spenat::TransitionItem* spenat_tr_nstdSmpl2_composite = spenatModel.transition(tr_nstdSmpl2_composite->name());
  QVERIFY(spenat_tr_nstdSmpl2_composite);
  QString action_tr_nstdSmpl2_composite = nestedSimple2.exitAction() +
                                          QStringLiteral("\n") +
                                          tr_nstdSmpl2_composite->action() +
                                          QStringLiteral("\n") +
                                          nestedSimple1.entryAction();
  QCOMPARE(spenat_tr_nstdSmpl2_composite->actions(), action_tr_nstdSmpl2_composite);
  const PostPlaceArc* postPlaceArc2 = spenat_tr_nstdSmpl2_composite->postPlaceArc(spenat_nestedSimple1);
  QVERIFY(postPlaceArc2);

  model::spenat::TransitionItem* spenat_tr_smplRoot_composite2 = spenatModel.transition(tr_smplRoot_composite2->name());
  QVERIFY(spenat_tr_smplRoot_composite2);
  QString action_smplRoot_composite2 = rootSimple.exitAction() +
                                       QStringLiteral("\n") +
                                       tr_smplRoot_composite2->action() +
                                       QStringLiteral("\n") +
                                       composite2.entryAction() +
                                       QStringLiteral("\n") +
                                       nestedComposite.entryAction() +
                                       QStringLiteral("\n") +
                                       deeplyNestedSimple.entryAction();
  QCOMPARE(spenat_tr_nstdSmpl2_composite->actions(), action_tr_nstdSmpl2_composite);
  const PostPlaceArc* postPlaceArc3 = spenat_tr_smplRoot_composite2->postPlaceArc(spenat_deeplyNestedSimple);
  QVERIFY(postPlaceArc3);
}

void StateMachineToSpenat::testComposite_InvalidEntryByInitState()
{
  StateMachineModel smModel;
  SimpleStateItem rootSimple(QStringLiteral("rootSimple"),
                             QStringLiteral("enterRootSimple"),
                             QStringLiteral("exitRootSimple"));
  bool result = smModel.addState(&rootSimple);
  QVERIFY(result);
  result = smModel.setInitState(&rootSimple);
  QVERIFY(result);

  CompositeStateItem composite(QStringLiteral("composite"));
  composite.setEntryAction(QStringLiteral("enterComposite"));
  composite.setExitAction(QStringLiteral("exitComposite"));
  result = smModel.addState(&composite);
  QVERIFY(result);

  SimpleStateItem nestedSimple(QStringLiteral("nestedSimple"),
                               QStringLiteral("enterNestedSimple"),
                               QStringLiteral("exitNestedSimple"));
  result = composite.addState(&nestedSimple);
  QVERIFY(result);

  //Transition simpleRoot to composite
  model::statemachine::TransitionItem* tr_smplRoot_composite = smModel.addTimeoutTransition(QStringLiteral("tr_smplRoot_composite"),
                                                                                            1.0,
                                                                                            &rootSimple,
                                                                                            &composite,
                                                                                            QStringLiteral("guard_smplRoot_composite"),
                                                                                            QStringLiteral("action_smplRoot_composite"));
  QVERIFY(tr_smplRoot_composite);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));
  QString errorString;
  result = command.execute(&errorString);
  QVERIFY(result == false);
}

//test cases evaluates a "final state chain"
//Two subsequent exits of 2 nested composites by guardless transitions
void StateMachineToSpenat::testComposite_ExitByFinalState()
{
  StateMachineModel smModel;

  SimpleStateItem simpleState(QStringLiteral("simpleState"),
                              QStringLiteral("enterSimple"),
                              QStringLiteral("exitSimple"));
  bool result = smModel.addState(&simpleState);
  QVERIFY(result);

  CompositeStateItem composite(QStringLiteral("composite"));
  composite.setEntryAction(QStringLiteral("enterComposite"));
  composite.setExitAction(QStringLiteral("exitComposite"));
  result = smModel.addState(&composite);
  QVERIFY(result);

  FinalStateItem compositeFinal(QStringLiteral("compositeFinal"));
  result = composite.addState(&compositeFinal);
  QVERIFY(result);

  CompositeStateItem nestedComposite(QStringLiteral("nestedComposite"));
  nestedComposite.setEntryAction(QStringLiteral("enterNestedComposite"));
  nestedComposite.setExitAction(QStringLiteral("exitNestedComposite"));
  result = composite.addState(&nestedComposite);
  QVERIFY(result);

  FinalStateItem nestedCompositeFinal(QStringLiteral("nestedCompositeFinal"));
  result = nestedComposite.addState(&nestedCompositeFinal);
  QVERIFY(result);

  SimpleStateItem nestedCompositeSimple(QStringLiteral("nestedCompositeSimple"),
                                        QStringLiteral("enterNestedCompositeSimple"),
                                        QStringLiteral("exitNestedCompositeSimple"));
  result = nestedComposite.addState(&nestedCompositeSimple);
  QVERIFY(result);

  //Transition nestedSimple to nestedFinal
  model::statemachine::TransitionItem* tr_ncsimple_ncfinal = smModel.addTimeoutTransition(QStringLiteral("tr_ncsimple_ncfinal"),
                                                                                          1.0,
                                                                                          &nestedCompositeSimple,
                                                                                          &nestedCompositeFinal,
                                                                                          QStringLiteral("guard_ncsimple_ncfinal"),
                                                                                          QStringLiteral("action_ncsimple_ncfinal"));
  QVERIFY(tr_ncsimple_ncfinal);

  model::statemachine::TransitionItem* tr_ncomposite_cfinal = smModel.addTransition(QStringLiteral("tr_ncomposite_cfinal"),
                                                                                    nullptr,
                                                                                    &nestedComposite,
                                                                                    &compositeFinal,
                                                                                    QStringLiteral(""),
                                                                                    QStringLiteral("action_ncomposite_cfinal"));
  QVERIFY(tr_ncomposite_cfinal);

  //Transition composite to to simpleState
  model::statemachine::TransitionItem* tr_composite_simple = smModel.addTransition(QStringLiteral("tr_composite_simple"),
                                                                                   nullptr,
                                                                                   &composite,
                                                                                   &simpleState,
                                                                                   QStringLiteral(""),
                                                                                   QStringLiteral("action_composite_simple"));
  QVERIFY(tr_composite_simple);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));
  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 2);
  QCOMPARE(spenatModel.transitions().size(), 1);

  PlaceItem* spenat_nestedCompositeSimple = spenatModel.place(nestedCompositeSimple.name());
  QVERIFY(spenat_nestedCompositeSimple);

  PlaceItem* spenat_simpleState = spenatModel.place(simpleState.name());
  QVERIFY(spenat_simpleState);

  QString combinedName = tr_ncsimple_ncfinal->name() +
                         QStringLiteral("_") +
                         tr_ncomposite_cfinal->name() +
                         QStringLiteral("_") +
                         tr_composite_simple->name();

  QString name = spenat_nestedCompositeSimple->name() +
                 QStringLiteral("_To_") +
                 spenat_simpleState->name();
  model::spenat::TransitionItem* fusedTransition = spenatModel.transition(name);
  QVERIFY(fusedTransition);

  QString combinedAction = nestedCompositeSimple.exitAction() +
                           QStringLiteral("\n") +
                           tr_ncsimple_ncfinal->action() +
                           QStringLiteral("\n") +
                           nestedComposite.exitAction() +
                           QStringLiteral("\n") +
                           tr_ncomposite_cfinal->action() +
                           QStringLiteral("\n") +
                           composite.exitAction() +
                           QStringLiteral("\n") +
                           tr_composite_simple->action() +
                           QStringLiteral("\n") +
                           simpleState.entryAction();
  QCOMPARE(fusedTransition->actions(), combinedAction);
  const PrePlaceArc* prePlace = fusedTransition->prePlaceArc(spenat_nestedCompositeSimple);
  QVERIFY(prePlace);
  const PostPlaceArc* postPlace = fusedTransition->postPlaceArc(spenat_simpleState);
  QVERIFY(postPlace);
}

void StateMachineToSpenat::testComposite_InvalidExitByFinalState()
{
  StateMachineModel smModel;

  SimpleStateItem simpleState(QStringLiteral("simpleState"),
                              QStringLiteral("enterSimple"),
                              QStringLiteral("exitSimple"));
  bool result = smModel.addState(&simpleState);
  QVERIFY(result);

  CompositeStateItem composite(QStringLiteral("composite"));
  composite.setEntryAction(QStringLiteral("enterComposite"));
  composite.setExitAction(QStringLiteral("exitComposite"));
  result = smModel.addState(&composite);
  QVERIFY(result);

  SimpleStateItem compositeSimple(QStringLiteral("compositeSimple"),
                                  QStringLiteral("enterCompositeSimple"),
                                  QStringLiteral("exitCompositeSimple"));
  result = composite.addState(&compositeSimple);
  QVERIFY(result);

  //Transition composite to to simpleState
  model::statemachine::TransitionItem* tr_composite_simple = smModel.addTransition(QStringLiteral("tr_composite_simple"),
                                                                                   nullptr,
                                                                                   &composite,
                                                                                   &simpleState,
                                                                                   QStringLiteral(""),
                                                                                   QStringLiteral("action_composite_simple"));
  QVERIFY(tr_composite_simple);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));
  QString errorString;
  result = command.execute(&errorString);
  QVERIFY(result == false);
}

void StateMachineToSpenat::testComposite_ExitByTriggerTransition()
{
  StateMachineModel smModel;

  SimpleStateItem simpleState(QStringLiteral("simpleState"),
                              QStringLiteral("enterSimple"),
                              QStringLiteral("exitSimple"));
  bool result = smModel.addState(&simpleState);
  QVERIFY(result);

  CompositeStateItem composite(QStringLiteral("composite"));
  composite.setEntryAction(QStringLiteral("enterComposite"));
  composite.setExitAction(QStringLiteral("exitComposite"));
  result = smModel.addState(&composite);
  QVERIFY(result);

  FinalStateItem compositeFinal(QStringLiteral("compositeFinal"));
  result = composite.addState(&compositeFinal);
  QVERIFY(result);

  SimpleStateItem compositeSimple(QStringLiteral("compositeSimple"),
                                  QStringLiteral("enterCompositeSimple"),
                                  QStringLiteral("exitCompositeSimple"));
  result = composite.addState(&compositeSimple);
  QVERIFY(result);

  SimpleStateItem compositeSimple2(QStringLiteral("compositeSimple2"),
                                   QStringLiteral("enterCompositeSimple2"),
                                   QStringLiteral("exitCompositeSimple2"));
  result = composite.addState(&compositeSimple2);
  QVERIFY(result);

  ChoiceStateItem compositeChoice(QStringLiteral("compositeChoice"));
  result = composite.addState(&compositeChoice);
  QVERIFY(result);

  JunctionStateItem compositeJunction(QStringLiteral("compositeJunction"));
  result = composite.addState(&compositeJunction);
  QVERIFY(result);

  CompositeStateItem nestedComposite(QStringLiteral("nestedComposite"));
  nestedComposite.setEntryAction(QStringLiteral("enterNestedComposite"));
  nestedComposite.setExitAction(QStringLiteral("exitNestedComposite"));
  result = composite.addState(&nestedComposite);
  QVERIFY(result);

  SimpleStateItem nestedCompositeSimple(QStringLiteral("nestedCompositeSimple"),
                                        QStringLiteral("enterNestedCompositeSimple"),
                                        QStringLiteral("exitNestedCompositeSimple"));
  result = nestedComposite.addState(&nestedCompositeSimple);
  QVERIFY(result);

  //Transition composite to to simpleState
  model::statemachine::TransitionItem* tr_composite_simple = smModel.addTimeoutTransition(QStringLiteral("tr_composite_simple"),
                                                                                          1.0,
                                                                                          &composite,
                                                                                          &simpleState,
                                                                                          QStringLiteral("guard_composite_simple"),
                                                                                          QStringLiteral("action_composite_simple"));
  QVERIFY(tr_composite_simple);

  SpenatDeclModel spenatModel;
  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString("defaultString"));
  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());
  QCOMPARE(spenatModel.places().size(), 5);
  QCOMPARE(spenatModel.transitions().size(), 4);

  model::spenat::TransitionItem* spenat_tr_ncsimple_simple = spenatModel.transition(QStringLiteral("nestedCompositeSimple_To_simpleState"));
  QVERIFY(spenat_tr_ncsimple_simple);
  QString action = nestedCompositeSimple.exitAction() +
                   QStringLiteral("\n") +
                   nestedComposite.exitAction() +
                   QStringLiteral("\n") +
                   composite.exitAction() +
                   QStringLiteral("\n") +
                   tr_composite_simple->action() +
                   QStringLiteral("\n") +
                   simpleState.entryAction();
  QCOMPARE(spenat_tr_ncsimple_simple->actions(), action);
  PlaceItem* place = spenatModel.place(nestedCompositeSimple.name());
  QVERIFY(place);
  const PrePlaceArc* prePlaceArc = spenat_tr_ncsimple_simple->prePlaceArc(place);
  QVERIFY(prePlaceArc);
}

void StateMachineToSpenat::testTraceConvert()
{
  StateMachineModel smModel;

  SimpleStateItem initState(QStringLiteral("s1"),
                            QStringLiteral(""),
                            QStringLiteral(""));
  bool result = smModel.addState(&initState);
  QVERIFY(result);
  SimpleStateItem simpleState(QStringLiteral("s2"),
                              QStringLiteral(""),
                              QStringLiteral(""));
  result = smModel.addState(&simpleState);
  QVERIFY(result);

  model::base::SignalItem* signalItem = smModel.addSignal(QStringLiteral("signal"));
  QVERIFY(signalItem);
  model::base::PortItem* portItem = smModel.addPort(QStringLiteral("port"));
  QVERIFY(portItem);

  model::statemachine::TransitionItem* smSignalTransition = smModel.addSignalTransition("t1",
                                                                                        signalItem,
                                                                                        portItem,
                                                                                        &initState,
                                                                                        &simpleState,
                                                                                        QStringLiteral(""),
                                                                                        QStringLiteral(""));
  QVERIFY(smSignalTransition);

  SpenatDeclModel spenatModel;

  ComStateMachineToSpenat command(&spenatModel,
                                  &smModel,
                                  QString(":/test"));

  QString errorString;
  result = command.execute(&errorString);
  QVERIFY2(result, errorString.toLatin1());

  QCOMPARE(spenatModel.places().size(), 2);
  QCOMPARE(spenatModel.transitions().size(), 1);

  QJsonDocument spenatTrace = command.spenatJsonDocument();
  QJsonObject spenatTraceObject = spenatTrace.object();

  QJsonArray placeArray, transitionArray, placeReqArray1, placeReqArray2, transTraceReqArray;
  result = model::base::io::readJsonArray(spenatTraceObject, QString("places"),
                                          &placeArray, &errorString);
  QVERIFY(result);
  QCOMPARE(placeArray.size(), 2);

  int iteration;
  result = model::base::io::readProperty<int>(spenatTraceObject,
                                              QStringLiteral("iteration"),
                                              &iteration,
                                              &errorString);
  QCOMPARE(iteration, 1);

  //check trace for first place
  QJsonObject placeTrace1 = placeArray.at(0).toObject();
  QVERIFY(!placeTrace1.isEmpty());

  QString name1;
  result = model::base::io::readProperty<QString>(placeTrace1,
                                                  QStringLiteral("name"),
                                                  &name1,
                                                  &errorString);
  QVERIFY(result);
  QCOMPARE(name1, QStringLiteral("s1"));

  bool placeReqChanged1;
  result = model::base::io::readProperty<bool>(placeTrace1,
                                               QStringLiteral("req_changed"),
                                               &placeReqChanged1,
                                               &errorString);
  QVERIFY(result);
  QVERIFY(placeReqChanged1);

  result = model::base::io::readJsonArray(placeTrace1, QString("requirements"),
                                          &placeReqArray1, &errorString);
  QVERIFY(result);
  QCOMPARE(placeReqArray1.size(), 1);
  QCOMPARE(placeReqArray1.at(0).toString(), QStringLiteral("Req_Test1"));

  //check trace for second place
  QJsonObject placeTrace2 = placeArray.at(1).toObject();
  QVERIFY(!placeTrace2.isEmpty());
  QString name2;
  result = model::base::io::readProperty<QString>(placeTrace2,
                                                  QStringLiteral("name"),
                                                  &name2,
                                                  &errorString);
  QVERIFY(result);
  QCOMPARE(name2, QStringLiteral("s2"));

  bool placeReqChanged2;
  result = model::base::io::readProperty<bool>(placeTrace2,
                                               QStringLiteral("req_changed"),
                                               &placeReqChanged2,
                                               &errorString);
  QVERIFY(result);
  QVERIFY(placeReqChanged2);

  result = model::base::io::readJsonArray(placeTrace2, QString("requirements"),
                                          &placeReqArray2, &errorString);
  QVERIFY(result);
  QCOMPARE(placeReqArray2.size(), 1);
  QCOMPARE(placeReqArray2.at(0).toString(), QStringLiteral("Req_Test2"));


  //check trace for transition
  result = model::base::io::readJsonArray(spenatTraceObject, QString("transitions"),
                                          &transitionArray, &errorString);
  QVERIFY(result);
  QCOMPARE(transitionArray.size(), 1);
  QJsonObject transTrace = transitionArray.at(0).toObject();
  QVERIFY(!transTrace.isEmpty());
  QString transName;
  result = model::base::io::readProperty<QString>(transTrace,
                                                  QStringLiteral("name"),
                                                  &transName,
                                                  &errorString);
  QVERIFY(result);
  QCOMPARE(transName, QStringLiteral("t1"));

  bool transReqChanged;
  result = model::base::io::readProperty<bool>(transTrace,
                                               QStringLiteral("req_changed"),
                                               &transReqChanged,
                                               &errorString);
  QVERIFY(result);
  QVERIFY(transReqChanged);

  result = model::base::io::readJsonArray(transTrace, QString("requirements"),
                                          &transTraceReqArray, &errorString);
  QVERIFY(result);
  QCOMPARE(transTraceReqArray.size(), 2);
  QCOMPARE(transTraceReqArray.at(0).toString(), QStringLiteral("Req_Test1"));
  QCOMPARE(transTraceReqArray.at(1).toString(), QStringLiteral("Req_Test2"));
}


QTEST_GUILESS_MAIN(StateMachineToSpenat)

#include "tst_statemachinetospenat.moc"
