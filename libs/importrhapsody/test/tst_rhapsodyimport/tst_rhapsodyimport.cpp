#include <QString>
#include <QtTest>
#include <QProcess>
#include <QTimer>
#include <QEventLoop>

#include <mobata/model/statemachine/statemachine.hpp>
#include <mobata/model/statemachine/io/comsavejsonsmmodel.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/functionitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>


#include <graphlayout/layoutroles.hpp>

#include <importrhapsody/importrhapsodypointer.hpp>
#include <importrhapsody/comimportrhapsody.hpp>

#include <dslparser/statemachine/combuildstatemachinefile.hpp>
#include <dslparser/statemachine/combuildstatemachinemodel.hpp>

using namespace rhapsody;
using namespace model::statemachine;
using namespace model::base;

class RhapsodyImportTest : public QObject
{
  Q_OBJECT

public:
  RhapsodyImportTest();
  RhapsodyPointer rPointer1, rPointer2, rPointer3;
  QProcess* rhapsodyProcess;

private Q_SLOTS:
  void setupTest();
  void invalidRhapsodyProjectTest();
  void importRhapsodyStateChartTest();
  void importRhapsodyLayoutTest();
  void tearDownTest();
};

RhapsodyImportTest::RhapsodyImportTest()
{}

void RhapsodyImportTest::setupTest()
{
 this->rPointer1._rhapsodyApplication = nullptr;
 this->rPointer1._rhapsodyProject = nullptr;

 this->rPointer2._rhapsodyApplication = nullptr;
 this->rPointer2._rhapsodyProject = nullptr;

 this->rPointer3._rhapsodyApplication = nullptr;
 this->rPointer3._rhapsodyProject = nullptr;

 QString program = "C:\\Program Files (x86)\\IBM\\Rational\\Rhapsody\\7.5\\rhapsody.exe";
 QString projectPath = QDir::currentPath();
 projectPath.append("/examples/Project.rpy");
 projectPath.replace("/","\\");
 QStringList arguments;
 arguments << projectPath;

 QEventLoop* loop = new QEventLoop();
 this->rhapsodyProcess = new QProcess();
 rhapsodyProcess->start(program, arguments);
 QTimer::singleShot(40000, loop, SLOT(quit()));
 loop->exec();
 delete loop;
}

//negative test loading active instance (which should not be active)
void RhapsodyImportTest::invalidRhapsodyProjectTest()
{
  QString errorMessage;
  StateMachineModel* smModel = new StateMachineModel();

  QString projectPath("");

  QList<QString> pathList;
  pathList << QStringLiteral("Design")
           << QStringLiteral("Test")
           << QStringLiteral("StatechartOfTest");

  ComImportRhapsody importRhapsodyCommand(&this->rPointer1, smModel, projectPath, pathList);
  bool result = importRhapsodyCommand.execute(&errorMessage);
  QVERIFY2(result == false, errorMessage.toLatin1());

  delete smModel;

  return;
}

//test of importing a rhapsody statechart to a mobata statemachine
void RhapsodyImportTest::importRhapsodyStateChartTest()
{
  QString errorMessage;
  StateMachineModel *smModel = new StateMachineModel();

  QList<QString> pathList;
  pathList << QStringLiteral("Design")
           << QStringLiteral("SubPackage")
           << QStringLiteral("Test")
           << QStringLiteral("StatechartOfTest");

  ComImportRhapsody importRhapsodyCommand(&this->rPointer2, smModel, QStringLiteral(""), pathList);
  bool result = importRhapsodyCommand.execute(&errorMessage);
  QVERIFY2(result, errorMessage.toLatin1());
  //Verify item count
  QCOMPARE(smModel->transitions().size(), 22);
  QCOMPARE(smModel->states().size(), 8);
  QCOMPARE(smModel->attributes().size(), 5);
  QCOMPARE(smModel->getSignals().size(), 9);
  QCOMPARE(smModel->dataTypes().size(), 14);
  QCOMPARE(smModel->ports().size(), 6);

  //verify composite state and substates of type Init
  const AbstractStateItem* asi_compositeItem = smModel->state(QStringLiteral("CompositeState_Test"));
  QVERIFY(asi_compositeItem);
  QCOMPARE(asi_compositeItem->stateType(), Composite);
  const CompositeStateItem* compositeItem = utils::simple_cast<const CompositeStateItem*>(asi_compositeItem);
  QCOMPARE(compositeItem->states().size(), 6);

  const AbstractStateItem* initState1 = compositeItem->state(QStringLiteral("initState_test"));
  QVERIFY(initState1);
  QCOMPARE(initState1->stateType(), Simple);
  const SimpleStateItem* simpleInit1 = static_cast<const SimpleStateItem*>(initState1);
  QVERIFY(simpleInit1);
  QCOMPARE(simpleInit1->isInit(), true);
  const AbstractStateItem* initState2 = compositeItem->state(QStringLiteral("defaultInit"));
  QCOMPARE(initState2, nullptr);
  const AbstractStateItem* initState3 = compositeItem->state(QStringLiteral("defaultInit"));
  QCOMPARE(initState3, nullptr);
  const AbstractStateItem* finalState1 = compositeItem->state(QStringLiteral("terminationstate_41"));
  QVERIFY(finalState1);
  QCOMPARE(finalState1->stateType(), Final);

  //verify concurrent state and it's regions
  const AbstractStateItem* asi_concurrentItem = compositeItem->state(QStringLiteral("ConcurrentState_Test"));
  QVERIFY(asi_concurrentItem);
  QCOMPARE(asi_concurrentItem->stateType(), Concurrent);
  const ConcurrentStateItem* concurrentItem = utils::simple_cast<const ConcurrentStateItem*>(asi_concurrentItem);
  QCOMPARE(concurrentItem->regions().size(), 2);

  const RegionItem* regionItem1 = concurrentItem->regions().first();
  QVERIFY(regionItem1);
  QCOMPARE(regionItem1->states().size(), 9);
  const AbstractStateItem* region_initState1 = regionItem1->state(QStringLiteral("defaultInit"));
  QVERIFY(region_initState1);
  QCOMPARE(region_initState1->stateType(), Simple);
  const SimpleStateItem* region_simpleInit1 = static_cast<const SimpleStateItem*>(region_initState1);
  QVERIFY(region_simpleInit1);
  QCOMPARE(region_simpleInit1->isInit(), true);

  const AbstractStateItem* region_initState3 = regionItem1->state(QStringLiteral("regionSubstate_source"));
  QVERIFY(region_initState3);
  QCOMPARE(region_initState3->stateType(), Simple);
  const SimpleStateItem* region_simpleInit3 = static_cast<const SimpleStateItem*>(region_initState3);
  QVERIFY(region_simpleInit3);
  QCOMPARE(region_simpleInit3->isInit(), false);

  const AbstractStateItem* asi_simpleItem = regionItem1->state(QStringLiteral("state_entryExit_Test"));
  QVERIFY(asi_simpleItem);
  QCOMPARE(asi_simpleItem->stateType(), Simple);
  const SimpleStateItem* simpleItem = utils::simple_cast<const SimpleStateItem*>(asi_simpleItem);
  QCOMPARE(simpleItem->entryAction(), QStringLiteral("TestMe();"));
  QCOMPARE(simpleItem->exitAction(), QStringLiteral("TestMeAgain();"));

  const RegionItem* regionItem2 = concurrentItem->regions().at(1);
  QVERIFY(regionItem2);
  QCOMPARE(regionItem2->states().size(), 5);

  //test transitions and entry/ exit action of source and target states
  const AbstractStateItem* asi_stateSource = smModel->state(QStringLiteral("substate_source"));
  QVERIFY(asi_stateSource);
  QCOMPARE(asi_stateSource->stateType(), Simple);
  const SimpleStateItem* stateSource = utils::simple_cast<const SimpleStateItem*>(asi_stateSource);
  QCOMPARE(stateSource->entryAction(), QStringLiteral("titanic.collision(\"iceberg\");"));
  QCOMPARE(stateSource->exitAction(), QStringLiteral("titanic.sink(true);"));

  const AbstractStateItem* asi_stateTarget = smModel->state(QStringLiteral("substate_target"));
  QVERIFY(asi_stateTarget);
  QCOMPARE(asi_stateTarget->stateType(), Simple);
  const SimpleStateItem* stateTarget = utils::simple_cast<const SimpleStateItem*>(asi_stateTarget);
  QCOMPARE(stateTarget->entryAction(), QStringLiteral("iceberg.collision(\"titanic\");"));
  QCOMPARE(stateTarget->exitAction(), QStringLiteral("iceberg.sink(false);"));

  bool transitionTestresult = false;
  for(TransitionItem const* transition : smModel->transitions())
  {
    if(transition->source()->uuid() == stateSource->uuid() && transition->target()->uuid() == stateTarget->uuid()){
      //check action string which is defined in rhapsody is defined as: "xyzparams->params = ParamsExample(\"someparams->\"); params->params=params.params"
      if(transition->action() == QStringLiteral("xyzparams->params = ParamsExample(\"someparams->\"); msg.params=params.params"))
       if(transition->guard() == QStringLiteral("(test_attribute2 EQ 12) AND (test_attribute3 EQ \"Release\")")){
         const ATriggerItem* trigger = transition->trigger();
         QVERIFY(trigger);
         QCOMPARE(trigger->triggerType(), ATriggerItem::EventTrigger);
         const SignalTriggerItem* signalTrigger = static_cast<const SignalTriggerItem*>(trigger);
        if(signalTrigger->triggerSignal()->uuid() == smModel->signal(QStringLiteral("test_event4"))->uuid())
        {
          transitionTestresult = true;
          break;
        }
       }
    }
  }
  QVERIFY(transitionTestresult);

  const AbstractStateItem* asi_regionSubstateSource = regionItem1->state(QStringLiteral("regionSubstate_source"));
  QVERIFY(asi_regionSubstateSource);
  QCOMPARE(asi_regionSubstateSource->stateType(), Simple);
  const SimpleStateItem* regionSubstateSource = utils::simple_cast<const SimpleStateItem*>(asi_regionSubstateSource);
  QCOMPARE(regionSubstateSource->entryAction(), QStringLiteral("SourceEntry();"));
  QCOMPARE(regionSubstateSource->exitAction(), QStringLiteral("SourceExit();"));

  const AbstractStateItem* asi_regionSubstateTarget = regionItem1->state(QStringLiteral("regionSubstate_target"));
  QVERIFY(asi_regionSubstateTarget);
  QCOMPARE(asi_regionSubstateTarget->stateType(), Simple);
  const SimpleStateItem* regionSubstateTarget = utils::simple_cast<const SimpleStateItem*>(asi_regionSubstateTarget);
  QCOMPARE(regionSubstateTarget->entryAction(), QStringLiteral("TargetEntry();"));
  QCOMPARE(regionSubstateTarget->exitAction(), QStringLiteral("TargetExit();"));

  transitionTestresult = false;
  for(TransitionItem const* transition : smModel->transitions())
  {
    if(transition->source()->uuid() == regionSubstateSource->uuid() && transition->target()->uuid() == regionSubstateTarget->uuid())
      if(transition->action() == QStringLiteral("MoonLanding(true);") && transition->guard() == QStringLiteral("(test_attribute2 EQ 42) AND (test_attribute3 EQ \"Debug\")")){
        if(transition->trigger()->triggerType() == ATriggerItem::EventTrigger){
          const SignalTriggerItem* trigger = static_cast<const SignalTriggerItem*>(transition->trigger());
          QVERIFY(trigger);
          if(trigger->triggerSignal()->uuid() == smModel->signal(QStringLiteral("test_event8"))->uuid())
          {
            transitionTestresult = true;
            break;
          }
        }
      }
  }
  QVERIFY(transitionTestresult);

  const AbstractStateItem* asi_compositeItem2 = smModel->state(QStringLiteral("CompositeState_TransitionTest"));
  QVERIFY(asi_compositeItem2);
  QCOMPARE(asi_compositeItem2->stateType(), Composite);
  const CompositeStateItem* compositeItem2 = utils::simple_cast<const CompositeStateItem*>(asi_compositeItem2);
  QCOMPARE(compositeItem2->states().size(), 3);

  const AbstractStateItem* stateSource2 = compositeItem2->state(QStringLiteral("state_transitionTest_source"));
  QVERIFY(stateSource2);
  QCOMPARE(stateSource2->stateType(), Simple);
  const AbstractStateItem* stateTarget2 = compositeItem2->state(QStringLiteral("state_transitionTest_target"));
  QVERIFY(stateTarget2);
  QCOMPARE(stateTarget2->stateType(), Simple);

  transitionTestresult = false;
  for(TransitionItem const* transition : smModel->transitions())
  {
    if(transition->source()->uuid() == stateSource2->uuid() && transition->target()->uuid() == stateTarget2->uuid())
      if(transition->action() == QStringLiteral("TestAction(42);") && transition->guard() == QStringLiteral("test_attribute4 EQ false"))
        if(transition->trigger()->triggerType() == ATriggerItem::EventTrigger){
          const SignalTriggerItem* trigger = static_cast<const SignalTriggerItem*>(transition->trigger());
          QVERIFY(trigger);
          if(trigger->triggerSignal()->uuid() == smModel->signal(QStringLiteral("test_event6"))->uuid())
            if(trigger->port()->uuid() == smModel->port(QStringLiteral("defaultPort"))->uuid())
              transitionTestresult = true;
        }
  }
  QVERIFY(transitionTestresult);

  transitionTestresult = false;
  for(TransitionItem const* transition : smModel->transitions())
  {
    if(transition->source()->uuid() == stateSource2->uuid() && transition->target()->uuid() == stateTarget2->uuid())
      if(transition->action() == QStringLiteral("TestAction(43);") && transition->guard() == QStringLiteral("test_attribute4 EQ true"))
        if(transition->trigger()->triggerType() == ATriggerItem::EventTrigger){
          const SignalTriggerItem* trigger = static_cast<const SignalTriggerItem*>(transition->trigger());
          QVERIFY(trigger);
          if(trigger->triggerSignal()->uuid() == smModel->signal(QStringLiteral("test_event7"))->uuid())
            if(trigger->port()->uuid() == smModel->port(QStringLiteral("defaultPort"))->uuid())
              transitionTestresult = true;
        }
  }
  QVERIFY(!transitionTestresult);

   const AbstractStateItem* choiceItem = smModel->state(QStringLiteral("condition_3"));
   QVERIFY(choiceItem);
   QCOMPARE(choiceItem->stateType(), Junction);
   const JunctionStateItem* jItem = static_cast<const JunctionStateItem*>(choiceItem);
   QVERIFY(jItem);
   QCOMPARE(jItem->transitions().size(), 2);
   const TransitionItem* jt0 = jItem->transitions().at(0);
   QVERIFY(jt0);
   QCOMPARE(jt0->guard(), QStringLiteral("( test_attribute4 EQ false ) and ( test_attribute2 EQ 42 )"));
   QCOMPARE(jt0->action(), QStringLiteral("nonsense()"));
   QCOMPARE(jt0->source()->uuid(), jItem->uuid());
   QCOMPARE(jt0->target()->uuid(), compositeItem->uuid());
   const TransitionItem* jt1 = jItem->transitions().at(1);
   QVERIFY(jt1);
   QCOMPARE(jt1->guard(), QStringLiteral("( test_attribute2 EQ 42 )"));
   QCOMPARE(jt1->action(), QStringLiteral(""));
   QCOMPARE(jt1->source()->uuid(), jItem->uuid());
   QCOMPARE(jt1->target()->uuid(), compositeItem2->uuid());

   const AbstractStateItem* junctionItem = regionItem1->state(QStringLiteral("junctionconnector_1"));
   QVERIFY(junctionItem);
   QCOMPARE(junctionItem->stateType(), Junction);

   const AbstractStateItem* initItem = smModel->state(QStringLiteral("defaultInit"));
   QVERIFY(initItem);
   QCOMPARE(initItem->stateType(), Simple);
   const SimpleStateItem* simpleInit = static_cast<const SimpleStateItem*>(initItem);
   QVERIFY(simpleInit);
   QCOMPARE(simpleInit->isInit(), true);

   const AbstractStateItem* finalitem = smModel->state(QStringLiteral("terminationstate_28"));
   QVERIFY(finalitem);
   QCOMPARE(finalitem->stateType(), Final);

  //verify signals & included parameters & types
  SignalItem* signal1 = smModel->signal(QStringLiteral("test_event9"));
  QVERIFY(signal1);
  QCOMPARE(signal1->params().size(), 2);
  const ParamItem* param1 = signal1->parameter(QStringLiteral("a"));
  Q_ASSERT(param1);
  const QString dataTypeItem1 = param1->dataType();
  QVERIFY(!dataTypeItem1.isEmpty());
  QCOMPARE(dataTypeItem1, QStringLiteral("test_type8"));
  const ParamItem* param2 = signal1->parameter(QStringLiteral("b"));
  Q_ASSERT(param2);
  const QString dataTypeItem2 = param2->dataType();
  QVERIFY(!dataTypeItem2.isEmpty());
  QCOMPARE(dataTypeItem2, QStringLiteral("long"));

  const SignalItem* signal2 = smModel->signal(QStringLiteral("test_event10"));
  QVERIFY(signal2);
  QCOMPARE(signal2->params().size(), 3);
  const ParamItem* param3 = signal2->parameter(QStringLiteral("first"));
  Q_ASSERT(param3);
  const QString dataTypeItem3 = param3->dataType();
  QVERIFY(!dataTypeItem3.isEmpty());
  QVERIFY(dataTypeItem3 != QStringLiteral("test_type8"));

  QCOMPARE(dataTypeItem1, QStringLiteral("test_type8"));
  QCOMPARE(dataTypeItem2, QStringLiteral("long"));
  QVERIFY(dataTypeItem3 != QStringLiteral("test_type14"));

  const SignalItem* signal3 = smModel->signal(QStringLiteral("test_event1"));
  QVERIFY(signal3);
  QCOMPARE(signal3->params().size(), 0);

  //verify attributes
  const AttributeItem* attributeItem = smModel->attribute(QStringLiteral("test_attribute5"));
  QVERIFY(attributeItem);
  QCOMPARE(attributeItem->initValue(), QStringLiteral("9999"));
  attributeItem = smModel->attribute(QStringLiteral("test_attribute4"));
  QVERIFY(attributeItem);
  QVERIFY(attributeItem->initValue() != QStringLiteral("true"));

  //verify that types from wrong subpackages were not included
  const DataTypeItem* wrongItem1 = smModel->dataType(QStringLiteral("wrong_type1"));
  QCOMPARE(wrongItem1, nullptr);
  const DataTypeItem* wrongItem2 = smModel->dataType(QStringLiteral("wrong_type6"));
  QCOMPARE(wrongItem2, nullptr);

  //verify that attributes from wrong subpackages were not included
  const AttributeItem* wrongAttribute1 = smModel->attribute(QStringLiteral("wrong_attribute1"));
  QCOMPARE(wrongAttribute1, nullptr);
  const AttributeItem* wrongAttribute2 = smModel->attribute(QStringLiteral("wrong_attribute4"));
  QCOMPARE(wrongAttribute2, nullptr);

  //verify function elements and its parameters
  DataTypeItem* tesType11 = smModel->dataType("test_type11");
  QVERIFY(tesType11);
  DataTypeItem* tesType12 = smModel->dataType("test_type12");
  QVERIFY(tesType12);
  DataTypeItem* tesType13 = smModel->dataType("test_type13");
  QVERIFY(tesType13);

  model::base::FunctionItem* functionItem1 = smModel->functions().at(0);
  QVERIFY(functionItem1);
  QCOMPARE(functionItem1->returnType(), tesType13->name());
  QCOMPARE(functionItem1->name(), QStringLiteral("testFunction"));
  QCOMPARE(functionItem1->statementBody(), QStringLiteral("if(firstParam == secondParam){ return firstParam + secondParam - 5); }"));
  QCOMPARE(functionItem1->params().count(), 2);
  model::base::ParamItem* inputParam1 = functionItem1->params().at(0);

  QVERIFY(inputParam1);
  QCOMPARE(inputParam1->name(), QStringLiteral("firstParam"));
  QCOMPARE(inputParam1->dataType(), tesType11->name());

  model::base::ParamItem* inputParam2 = functionItem1->params().at(1);
  QVERIFY(inputParam2);
  QCOMPARE(inputParam2->name(), QStringLiteral("secondParam"));
  QCOMPARE(inputParam2->dataType(), tesType12->name());

  QString emptyPath;
  dslparser::statemachine::ComBuildStateMachineFile comBuildSmFile(emptyPath, smModel);

  QString docText = comBuildSmFile.toDocText();
  if(docText.isEmpty()){
    qWarning() << "Imported doctext of statemachine model is empty!";
    return;
  }

  StateMachineModel* testModel = new StateMachineModel();
  dslparser::statemachine::ComBuildStateMachineModel comBuildStateMachineModel(docText, testModel);
  if(!comBuildStateMachineModel.execute(&errorMessage))
  {
    qWarning() << errorMessage;
    return;
  }

  delete smModel;
  delete testModel;

  return;
}

//test of importing a rhapsody statechart to a mobata statemachine
void RhapsodyImportTest::importRhapsodyLayoutTest()
{
  QString errorMessage;
  StateMachineModel *smModel = new StateMachineModel();

  QList<QString> pathList;
  pathList << QStringLiteral("Design")
           << QStringLiteral("SubPackage")
           << QStringLiteral("Test")
           << QStringLiteral("StatechartOfTest");

//  ComImportRhapsody importRhapsodyCommand(&this->rPointer3, smModel, projectPath, pathList);
  ComImportRhapsody importRhapsodyCommand(&this->rPointer3, smModel, QStringLiteral(""), pathList);
  bool result = importRhapsodyCommand.execute(&errorMessage);
  QVERIFY2(result, errorMessage.toLatin1());

  //Verify project
  QCOMPARE(smModel->transitions().size(), 22);
  QCOMPARE(smModel->states().size(), 8);
  QCOMPARE(smModel->attributes().size(), 5);
  QCOMPARE(smModel->getSignals().size(), 9);
  QCOMPARE(smModel->dataTypes().size(), 14);
  QCOMPARE(smModel->ports().size(), 6);

  //layout tests

  //CompositeStateItem
  const AbstractStateItem* compositeItem = smModel->state(QStringLiteral("CompositeState_Test"));
  QVERIFY(compositeItem);
  //absolute Position
  QVariant composite_absPos = compositeItem->data(AbsPositionRole);
  QVERIFY(composite_absPos.isValid());
  QCOMPARE(int(composite_absPos.value<QPointF>().x()), 657);
  QCOMPARE(int(composite_absPos.value<QPointF>().y()), 436);
  //Width
  QVariant composite_width = compositeItem->data(WidthRole);
  QVERIFY(composite_width.isValid());
  QCOMPARE(composite_width.toInt(), int(245));
  //Height
  QVariant composite_height = compositeItem->data(HeightRole);
  QVERIFY(composite_height.isValid());
  QCOMPARE(composite_height.toInt(), 227);
  //Line size
  QVariant composite_lineWidth = compositeItem->data(LineWidthRole);
  QVERIFY(composite_lineWidth.isValid());
  QCOMPARE(composite_lineWidth.toInt(), 7);
  //background color
  QVariant composite_backgroundColor = compositeItem->data(BackgroundColorRole);
  QVERIFY(composite_backgroundColor.isValid());
  QCOMPARE(composite_backgroundColor.value<QColor>().name(), QStringLiteral("#a6caf0"));
  //Text color
  QVariant composite_textColor = compositeItem->data(TextColorRole);
  QVERIFY(composite_textColor.isValid());
  QCOMPARE(composite_textColor.value<QColor>().name(), QStringLiteral("#ff00ff"));
  //Text position
  QVariant composite_textPos = compositeItem->data(TextPositionRole);
  QVERIFY(composite_textPos.isValid());
  QCOMPARE(int(composite_textPos.value<QPointF>().x()), 657);
  QCOMPARE(composite_textPos.value<QPointF>().y(), double(407.625));
  //Text font size
  QVariant composite_textFontSize = compositeItem->data(TextFontSizeRole);
  QVERIFY(composite_textFontSize.isValid());
  QCOMPARE(composite_textFontSize.toInt(), 14);

  //get casted compositeItem to retrieve nested states
  QCOMPARE(compositeItem->stateType(), Composite);
  const CompositeStateItem* compositeCastItem = utils::simple_cast<const CompositeStateItem*>(compositeItem);
  QVERIFY(compositeCastItem);

  //Nested CompositeStateItem
  const AbstractStateItem* nestedCompositeItem = compositeCastItem->state(QStringLiteral("state_9"));
  QVERIFY(nestedCompositeItem);
  //absolute Position
  QVariant nestedComposite_absPos = nestedCompositeItem->data(AbsPositionRole);
  QVERIFY(nestedComposite_absPos.isValid());
  QCOMPARE(int(nestedComposite_absPos.value<QPointF>().x()), 1244);
  QCOMPARE(int(nestedComposite_absPos.value<QPointF>().y()), 105);
  //Width
  QVariant nestedComposite_width = nestedCompositeItem->data(WidthRole);
  QVERIFY(nestedComposite_width.isValid());
  QCOMPARE(nestedComposite_width.toInt(), 418);
  //Height
  QVariant nestedComposite_height = nestedCompositeItem->data(HeightRole);
  QVERIFY(nestedComposite_height.isValid());
  QCOMPARE(nestedComposite_height.toInt(), 323);
  //Line size
  QVariant nestedComposite_lineWidth = nestedCompositeItem->data(LineWidthRole);
  QVERIFY(nestedComposite_lineWidth.isValid());
  QCOMPARE(nestedComposite_lineWidth.toInt(), 1);
  //background color
  QVariant nestedComposite_backgroundColor = nestedCompositeItem->data(BackgroundColorRole);
  QVERIFY(nestedComposite_backgroundColor.isValid());
  QCOMPARE(nestedComposite_backgroundColor.value<QColor>().name(), QStringLiteral("#00ffff"));
  //Text color
  QVariant nestedComposite_textColor = nestedCompositeItem->data(TextColorRole);
  QVERIFY(nestedComposite_textColor.isValid());
  QCOMPARE(nestedComposite_textColor.value<QColor>().name(), QStringLiteral("#000000"));
  //Text position
  QVariant nestedComposite_textPos = nestedCompositeItem->data(TextPositionRole);
  QVERIFY(nestedComposite_textPos.isValid());
  QCOMPARE(int(nestedComposite_textPos.value<QPointF>().x()), 1244);
  QCOMPARE(nestedComposite_textPos.value<QPointF>().y(), double(64.625));
  //Text font size
  QVariant nestedComposite_textFontSize = nestedCompositeItem->data(TextFontSizeRole);
  QVERIFY(nestedComposite_textFontSize.isValid());
  QCOMPARE(nestedComposite_textFontSize.toInt(), 20);

  //get casted nested compositeItem to retrieve nested states
  QCOMPARE(nestedCompositeItem->stateType(), Composite);
  const CompositeStateItem* nestedCompositeCastItem = utils::simple_cast<const CompositeStateItem*>(nestedCompositeItem);
  QVERIFY(nestedCompositeCastItem);

  //Nested SimpleStateItem
  const AbstractStateItem* compositeSimpleItem = nestedCompositeCastItem->state(QStringLiteral("state_22"));
  QVERIFY(compositeSimpleItem);
  //absolute Position
  QVariant compositeSimple_absPos = compositeSimpleItem->data(AbsPositionRole);
  QVERIFY(compositeSimple_absPos.isValid());
  QCOMPARE(int(compositeSimple_absPos.value<QPointF>().x()), 445);
  QCOMPARE(int(compositeSimple_absPos.value<QPointF>().y()), 384);
  //Width
  QVariant compositeSimple_width = compositeSimpleItem->data(WidthRole);
  QVERIFY(compositeSimple_width.isValid());
  QCOMPARE(compositeSimple_width.toInt(), 206);
  //Height
  QVariant compositeSimple_height = compositeSimpleItem->data(HeightRole);
  QVERIFY(compositeSimple_height.isValid());
  QCOMPARE(compositeSimple_height.toInt(), 212);
  //Line size
  QVariant compositeSimple_lineWidth = compositeSimpleItem->data(LineWidthRole);
  QVERIFY(compositeSimple_lineWidth.isValid());
  QCOMPARE(compositeSimple_lineWidth.toInt(), 7);
  //background color
  QVariant compositeSimple_backgroundColor = compositeSimpleItem->data(BackgroundColorRole);
  QVERIFY(compositeSimple_backgroundColor.isValid());
  QCOMPARE(compositeSimple_backgroundColor.value<QColor>().name(), QStringLiteral("#a6caf0"));
  //Text color
  QVariant compositeSimple_textColor = compositeSimpleItem->data(TextColorRole);
  QVERIFY(compositeSimple_textColor.isValid());
  QCOMPARE(compositeSimple_textColor.value<QColor>().name(), QStringLiteral("#000000"));
  //Text position
  QVariant compositeSimple_textPos = compositeSimpleItem->data(TextPositionRole);
  QVERIFY(compositeSimple_textPos.isValid());
  QCOMPARE(int(compositeSimple_textPos.value<QPointF>().x()), 445);
  QCOMPARE(compositeSimple_textPos.value<QPointF>().y(), double(357.5));
  //Text font size
  QVariant compositeSimple_textFontSize = compositeSimpleItem->data(TextFontSizeRole);
  QVERIFY(compositeSimple_textFontSize.isValid());
  QCOMPARE(compositeSimple_textFontSize.toInt(), 22);

  //ConcurrentStateItem
  const AbstractStateItem* concurrentItem = compositeCastItem->state(QStringLiteral("ConcurrentState_Test"));
  QVERIFY(concurrentItem);
  //absolute Position
  QVariant concurrent_absPos = concurrentItem->data(AbsPositionRole);
  QVERIFY(concurrent_absPos.isValid());
  QCOMPARE(int(concurrent_absPos.value<QPointF>().x()), 83);
  QCOMPARE(int(concurrent_absPos.value<QPointF>().y()), 467);
  //Width
  QVariant concurrent_width = concurrentItem->data(WidthRole);
  QVERIFY(concurrent_width.isValid());
  QCOMPARE(concurrent_width.toInt(), 1424);
  //Height
  QVariant concurrent_height = concurrentItem->data(HeightRole);
  QVERIFY(concurrent_height.isValid());
  QCOMPARE(concurrent_height.toInt(), 564);
  //Line size
  QVariant concurrent_lineWidth = concurrentItem->data(LineWidthRole);
  QVERIFY(concurrent_lineWidth.isValid());
  QCOMPARE(concurrent_lineWidth.toInt(), 5);
  //background color
  QVariant concurrent_backgroundColor = concurrentItem->data(BackgroundColorRole);
  QVERIFY(concurrent_backgroundColor.isValid());
  QCOMPARE(concurrent_backgroundColor.value<QColor>().name(), QStringLiteral("#808080"));
  //Text color
  QVariant concurrent_textColor = concurrentItem->data(TextColorRole);
  QVERIFY(concurrent_textColor.isValid());
  QCOMPARE(concurrent_textColor.value<QColor>().name(), QStringLiteral("#ff0000"));
  //Text position
  QVariant concurrent_textPos = concurrentItem->data(TextPositionRole);
  QVERIFY(concurrent_textPos.isValid());
  QCOMPARE(int(concurrent_textPos.value<QPointF>().x()), 83);
  QCOMPARE(concurrent_textPos.value<QPointF>().y(), double(396.5));
  //Text font size
  QVariant concurrent_textFontSize = concurrentItem->data(TextFontSizeRole);
  QVERIFY(concurrent_textFontSize.isValid());
  QCOMPARE(concurrent_textFontSize.toInt(), 16);

  //get casted concurrentItem to retrieve nested regions
  QCOMPARE(concurrentItem->stateType(), Concurrent);
  const ConcurrentStateItem* concurrentCastItem = utils::simple_cast<const ConcurrentStateItem*>(concurrentItem);
  QVERIFY(concurrentCastItem);

  //RegionItem
  const RegionItem* regionItem = concurrentCastItem->regions().first();
  QVERIFY(regionItem);
  //absolute Position
  QVariant region_absPos = regionItem->data(AbsPositionRole);
  QVERIFY(region_absPos.isValid());
  QCOMPARE(int(region_absPos.value<QPointF>().x()), 83);
  QCOMPARE(int(region_absPos.value<QPointF>().y()), 467);
  //Width
  QVariant region_width = regionItem->data(WidthRole);
  QVERIFY(region_width.isValid());
  QCOMPARE(region_width.toInt(), 712);
  //Height
  QVariant region_height = regionItem->data(HeightRole);
  QVERIFY(region_height.isValid());
  QCOMPARE(region_height.toInt(), 564);
  //Line size
  QVariant region_lineWidth = regionItem->data(LineWidthRole);
  QVERIFY(region_lineWidth.isValid());
  QCOMPARE(region_lineWidth.toInt(), 5);

  //real initStateItem
  const AbstractStateItem* realInitItem = compositeCastItem->state(QStringLiteral("initState_test"));
  QVERIFY(realInitItem);
  //absolute Position
  QVariant realInit_absPos = realInitItem->data(AbsPositionRole);
  QVERIFY(realInit_absPos.isValid());
  QCOMPARE(int(realInit_absPos.value<QPointF>().x()), 295);
  QCOMPARE(int(realInit_absPos.value<QPointF>().y()), 159);
  //Width
  QVariant realInit_width = realInitItem->data(WidthRole);
  QVERIFY(realInit_width.isValid());
  QCOMPARE(realInit_width.toInt(), 301);
  //Height
  QVariant realInit_height = realInitItem->data(HeightRole);
  QVERIFY(realInit_height.isValid());
  QCOMPARE(realInit_height.toInt(), 151);
  //Line size
  QVariant realInit_lineWidth = realInitItem->data(LineWidthRole);
  QVERIFY(realInit_lineWidth.isValid());
  QCOMPARE(realInit_lineWidth.toInt(), 1);
  //background color
  QVariant realInit_backgroundColor = realInitItem->data(BackgroundColorRole);
  QVERIFY(realInit_backgroundColor.isValid());
  QCOMPARE(realInit_backgroundColor.value<QColor>().name(), QStringLiteral("#ffffff"));
  //Text color
  QVariant realInit_textColor = realInitItem->data(TextColorRole);
  QVERIFY(realInit_textColor.isValid());
  QCOMPARE(realInit_textColor.value<QColor>().name(), QStringLiteral("#000000"));
  //Text position
  QVariant realInit_textPos = realInitItem->data(TextPositionRole);
  QVERIFY(realInit_textPos.isValid());
  QCOMPARE(int(realInit_textPos.value<QPointF>().x()), 295);
  QCOMPARE(realInit_textPos.value<QPointF>().y(), double(140.125));
  //Text font size
  QVariant realInit_textFontSize = realInitItem->data(TextFontSizeRole);
  QVERIFY(realInit_textFontSize.isValid());
  QCOMPARE(realInit_textFontSize.toInt(), 10);

  //generated initStateItem
  const AbstractStateItem* generatedInitItem = smModel->state(QStringLiteral("defaultInit"));
  //calculate output
  double width = sqrt(pow(184 - 307, 2) + pow(73 - 79, 2))/double(2);
  double height = width*0.67;
  double posX = 184 - (width/double(2));
  double posY = 73 - (height/double(2));
  double textPosX = posX;
  double textPosY = posY - (height/double(8));
  QVERIFY(generatedInitItem);
  //absolute Position
  QVariant generatedInit_absPos = generatedInitItem->data(AbsPositionRole);
  QVERIFY(generatedInit_absPos.isValid());
  QCOMPARE(generatedInit_absPos.value<QPointF>().x(), posX);
  QCOMPARE(generatedInit_absPos.value<QPointF>().y(), posY);
  //Width
  QVariant generatedInit_width = generatedInitItem->data(WidthRole);
  QVERIFY(generatedInit_width.isValid());
  QCOMPARE(generatedInit_width.toDouble(), width);
  //Height
  QVariant generatedInit_height = generatedInitItem->data(HeightRole);
  QVERIFY(generatedInit_height.isValid());
  QCOMPARE(generatedInit_height.toDouble(), height);
  //Line size
  QVariant generatedInit_lineWidth = generatedInitItem->data(LineWidthRole);
  QVERIFY(generatedInit_lineWidth.isValid());
  QCOMPARE(generatedInit_lineWidth.toInt(), 6);
  //Text color
  QVariant generatedInit_textColor = generatedInitItem->data(TextColorRole);
  QVERIFY(generatedInit_textColor.isValid());
  QCOMPARE(generatedInit_textColor.value<QColor>().name(), QStringLiteral("#00ff00"));
  //Text position
  QVariant generatedInit_textPos = generatedInitItem->data(TextPositionRole);
  QVERIFY(generatedInit_textPos.isValid());
  QCOMPARE(generatedInit_textPos.value<QPointF>().x(), textPosX);
  QCOMPARE(generatedInit_textPos.value<QPointF>().y(), textPosY);
  //Text font size
  QVariant generatedInit_textFontSize = generatedInitItem->data(TextFontSizeRole);
  QVERIFY(generatedInit_textFontSize.isValid());
  QCOMPARE(generatedInit_textFontSize.toInt(), 14);


  //finalStateItem
  const AbstractStateItem* finalitem = smModel->state(QStringLiteral("terminationstate_28"));
  QVERIFY(finalitem);
  //absolute Position
  QVariant final_absPos = finalitem->data(AbsPositionRole);
  QVERIFY(final_absPos.isValid());
  QCOMPARE(int(final_absPos.value<QPointF>().x()), 1544);
  QCOMPARE(int(final_absPos.value<QPointF>().y()), 425);
  //Width
  QVariant final_width = finalitem->data(WidthRole);
  QVERIFY(final_width.isValid());
  QCOMPARE(final_width.toInt(), 25);
  //Height
  QVariant final_height = finalitem->data(HeightRole);
  QVERIFY(final_height.isValid());
  QCOMPARE(final_height.toInt(), 26);
  //Text position
  QVariant final_textPos = finalitem->data(TextPositionRole);
  QVERIFY(final_textPos.isValid());
  QCOMPARE(int(final_textPos.value<QPointF>().x()), 1544);
  QCOMPARE(final_textPos.value<QPointF>().y(), double(421.75));


  //choiceStateItem
  const AbstractStateItem* choiceItem = smModel->state(QStringLiteral("condition_3"));
  QVERIFY(choiceItem);
  //absolute Position
  QVariant choice_absPos = choiceItem->data(AbsPositionRole);
  QVERIFY(choice_absPos.isValid());
  QCOMPARE(int(choice_absPos.value<QPointF>().x()), 647);
  QCOMPARE(int(choice_absPos.value<QPointF>().y()), 294);
  //Width
  QVariant choice_width = choiceItem->data(WidthRole);
  QVERIFY(choice_width.isValid());
  QCOMPARE(choice_width.toInt(), 25);
  //Height
  QVariant choice_height = choiceItem->data(HeightRole);
  QVERIFY(choice_height.isValid());
  QCOMPARE(choice_height.toInt(), 23);
  //background color
  QVariant choice_backgroundColor = choiceItem->data(BackgroundColorRole);
  QVERIFY(choice_backgroundColor.isValid());
  QCOMPARE(choice_backgroundColor.value<QColor>().name(), QStringLiteral("#989ee7"));
  //Text color
  QVariant choice_textColor = choiceItem->data(TextColorRole);
  QVERIFY(choice_textColor.isValid());
  QCOMPARE(choice_textColor.value<QColor>().name(), QStringLiteral("#000000"));
  //Text position
  QVariant choice_textPos = choiceItem->data(TextPositionRole);
  QVERIFY(choice_textPos.isValid());
  QCOMPARE(int(choice_textPos.value<QPointF>().x()), 647);
  QCOMPARE(choice_textPos.value<QPointF>().y(), double(291.125));
  //Text font size
  QVariant choice_textFontSize = choiceItem->data(TextFontSizeRole);
  QVERIFY(choice_textFontSize.isValid());
  QCOMPARE(choice_textFontSize.toInt(), 10);


  //junctionStateItem
  const AbstractStateItem* junctionItem = regionItem->state(QStringLiteral("junctionconnector_1"));
  QVERIFY(junctionItem);
  //absolute Position
  QVariant junction_absPos = junctionItem->data(AbsPositionRole);
  QVERIFY(junction_absPos.isValid());
  QCOMPARE(int(junction_absPos.value<QPointF>().x()), 714);
  QCOMPARE(int(junction_absPos.value<QPointF>().y()), 893);
  //Width
  QVariant junction_width = junctionItem->data(WidthRole);
  QVERIFY(junction_width.isValid());
  QCOMPARE(junction_width.toInt(), 12);
  //Height
  QVariant junction_height = junctionItem->data(HeightRole);
  QVERIFY(junction_height.isValid());
  QCOMPARE(junction_height.toInt(), 12);
  //background color
  QVariant junction_backgroundColor = junctionItem->data(BackgroundColorRole);
  QVERIFY(junction_backgroundColor.isValid());
  QCOMPARE(junction_backgroundColor.value<QColor>().name(), QStringLiteral("#989ee7"));
  //Text position
  QVariant junction_textPos = junctionItem->data(TextPositionRole);
  QVERIFY(junction_textPos.isValid());
  QCOMPARE(int(junction_textPos.value<QPointF>().x()), 714);
  QCOMPARE(junction_textPos.value<QPointF>().y(), double(891.5));


  //DefaultTransition
  const TransitionItem* defaultTransition = smModel->transitions().at(0);
  QVERIFY(defaultTransition);
  QCOMPARE(defaultTransition->name(), QStringLiteral("transition_defaultInit_to_state_0"));
  //Polygon (data points)
  QVariant defaultTransition_polygon = defaultTransition->data(PolygonRole);
  QVERIFY(defaultTransition_polygon.isValid());
  QVector<QPointF> defaultTransition_points = defaultTransition_polygon.value<QVector<QPointF>>();
  QCOMPARE(defaultTransition_points.size(), 2);
  QCOMPARE(int(defaultTransition_points.at(0).x()), 184);
  QCOMPARE(int(defaultTransition_points.at(0).y()), 73);
  QCOMPARE(int(defaultTransition_points.at(1).x()), 307);
  QCOMPARE(int(defaultTransition_points.at(1).y()), 79);
  //Line Width
  QVariant defaultTransition_lineWidth = defaultTransition->data(LineWidthRole);
  QVERIFY(defaultTransition_lineWidth.isValid());
  QCOMPARE(defaultTransition_lineWidth.toInt(), 6);
  //Line Color
  QVariant defaultTransition_lineColor = defaultTransition->data(ForegroundColorRole);
  QVERIFY(defaultTransition_lineColor.isValid());
  QCOMPARE(defaultTransition_lineColor.value<QColor>().name(), QStringLiteral("#ff8000"));
  //Text Color
  QVariant defaultTransition_textColor = defaultTransition->data(TextColorRole);
  QVERIFY(defaultTransition_textColor.isValid());
  QCOMPARE(defaultTransition_textColor.value<QColor>().name(), QStringLiteral("#00ff00"));
  //Text Position
  QVariant defaultTransition_textPos = defaultTransition->data(TextPositionRole);
  QVERIFY(defaultTransition_textPos.isValid());
  QCOMPARE(defaultTransition_textPos.value<QPointF>().x(), double(265.5));
  QCOMPARE(int(defaultTransition_textPos.value<QPointF>().y()), 96);
  //Text font size
  QVariant defaultTransition_textFontSize = defaultTransition->data(TextFontSizeRole);
  QVERIFY(defaultTransition_textFontSize.isValid());
  QCOMPARE(defaultTransition_textFontSize.toInt(), 14);

  //Straight Transition (two data points)
  const TransitionItem* straightTransition = smModel->transitions().at(1);
  QVERIFY(straightTransition);
  QCOMPARE(straightTransition->name(), QStringLiteral("transition_state_0_to_substate_source"));
  //Polygon (data points)
  QVariant straightTransition_polygon = straightTransition->data(PolygonRole);
  QVERIFY(straightTransition_polygon.isValid());
  QVector<QPointF> straightTransition_points = straightTransition_polygon.value<QVector<QPointF>>();
  QCOMPARE(straightTransition_points.size(), 2);
  QCOMPARE(int(straightTransition_points.at(0).x()), 320);
  QCOMPARE(int(straightTransition_points.at(0).y()), 137);
  QCOMPARE(int(straightTransition_points.at(1).x()), 333);
  QCOMPARE(int(straightTransition_points.at(1).y()), 206);
  //Line Width
  QVariant straightTransition_lineWidth = straightTransition->data(LineWidthRole);
  QVERIFY(straightTransition_lineWidth.isValid());
  QCOMPARE(straightTransition_lineWidth.toInt(), 3);
  //Line Color
  QVariant straightTransition_lineColor = straightTransition->data(ForegroundColorRole);
  QVERIFY(straightTransition_lineColor.isValid());
  QCOMPARE(straightTransition_lineColor.value<QColor>().name(), QStringLiteral("#ff00ff"));
  //Text Color
  QVariant straightTransition_textColor = straightTransition->data(TextColorRole);
  QVERIFY(straightTransition_textColor.isValid());
  QCOMPARE(straightTransition_textColor.value<QColor>().name(), QStringLiteral("#ffff00"));
  //Text Position
  QVariant straightTransition_textPos = straightTransition->data(TextPositionRole);
  QVERIFY(straightTransition_textPos.isValid());
  QCOMPARE(straightTransition_textPos.value<QPointF>().x(), double(346.5));
  QCOMPARE(straightTransition_textPos.value<QPointF>().y(), double(191.5));
  //Text font size
  QVariant straightTransition_textFontSize = straightTransition->data(TextFontSizeRole);
  QVERIFY(straightTransition_textFontSize.isValid());
  QCOMPARE(straightTransition_textFontSize.toInt(), 8);

  //Poly Transition (several data points)
  const TransitionItem* polyTransition = smModel->transitions().at(20);
  QVERIFY(polyTransition);
  QCOMPARE(polyTransition->name(), QStringLiteral("transition_substate_source_to_substate_target"));
  //Polygon (data points)
  QVariant polyTransition_polygon = polyTransition->data(PolygonRole);
  QVERIFY(polyTransition_polygon.isValid());
  QVector<QPointF> polyTransition_points = polyTransition_polygon.value<QVector<QPointF>>();
  QCOMPARE(polyTransition_points.size(), 4);
  QCOMPARE(int(polyTransition_points.at(0).x()), 386);
  QCOMPARE(int(polyTransition_points.at(0).y()), 246);
  QCOMPARE(int(polyTransition_points.at(1).x()), 439);
  QCOMPARE(int(polyTransition_points.at(1).y()), 246);
  QCOMPARE(int(polyTransition_points.at(2).x()), 439);
  QCOMPARE(int(polyTransition_points.at(2).y()), 284);
  QCOMPARE(int(polyTransition_points.at(3).x()), 493);
  QCOMPARE(int(polyTransition_points.at(3).y()), 284);
  //Line Width
  QVariant polyTransition_lineWidth = polyTransition->data(LineWidthRole);
  QVERIFY(polyTransition_lineWidth.isValid());
  QCOMPARE(polyTransition_lineWidth.toInt(), 2);
  //Line Color
  QVariant polyTransition_lineColor = polyTransition->data(ForegroundColorRole);
  QVERIFY(polyTransition_lineColor.isValid());
  QCOMPARE(polyTransition_lineColor.value<QColor>().name(), QStringLiteral("#00ff00"));
  //Text Color
  QVariant polyTransition_textColor = polyTransition->data(TextColorRole);
  QVERIFY(polyTransition_textColor.isValid());
  QCOMPARE(polyTransition_textColor.value<QColor>().name(), QStringLiteral("#000080"));
  //Text Position
  QVariant polyTransition_textPos = polyTransition->data(TextPositionRole);
  QVERIFY(polyTransition_textPos.isValid());
  QCOMPARE(polyTransition_textPos.value<QPointF>().x(), double(459.5));
  QCOMPARE(int(polyTransition_textPos.value<QPointF>().y()), 285);
  //Text font size
  QVariant polyTransition_textFontSize = polyTransition->data(TextFontSizeRole);
  QVERIFY(polyTransition_textFontSize.isValid());
  QCOMPARE(polyTransition_textFontSize.toInt(), 12);

  delete smModel;

  return;
}

void RhapsodyImportTest::tearDownTest()
{
 delete this->rhapsodyProcess;
}

QTEST_GUILESS_MAIN(RhapsodyImportTest)

#include "tst_rhapsodyimport.moc"
