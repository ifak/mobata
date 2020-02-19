#include <QString>
#include <QtTest>

#include <mobata/model/base/basemodel.hpp>
#include <mobata/model/base/comloadbasemodel.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/signalitem.hpp>

#include <mobata/model/msc/msc.hpp>

#include <mobata/model/statemachine/io/comloadjsonsmmodel.hpp>
#include <mobata/model/statemachine/io/readsmmodel.hpp>
#include <mobata/model/statemachine/io/comsavejsonsmmodel.hpp>

class LoadModelTest
    : public QObject
{
  Q_OBJECT

public:
  LoadModelTest();

private Q_SLOTS:
  void initTest();
  void cleanupTest();
  void loadBaseModelTest();
  void loadMscModelTest();
  void loadStateMachineModelTest();
};

LoadModelTest::LoadModelTest()
{}

void LoadModelTest::initTest()
{}

void LoadModelTest::cleanupTest()
{}

void LoadModelTest::loadBaseModelTest()
{
  using namespace model::base;

  BaseModel testBaseModel;
  ComLoadBaseModel loadCommand(":/testdata/testbasemodel.json",
                               &testBaseModel);
  QString errorMessage;
  bool result = loadCommand.execute(&errorMessage);
  QVERIFY2(result, errorMessage.toLatin1());
  QVERIFY2(errorMessage.isEmpty(), errorMessage.toLatin1());

  QVERIFY(testBaseModel.name()=="testBaseModel");

//  model::base::BaseModel testBaseModel("testBaseModel");

//  ///types///////////
//  model::base::DataTypeItem* intTypeItem = testBaseModel.addDataType("int");
//  QVERIFY(intTypeItem);
//  model::base::DataTypeItem* realTypeItem = testBaseModel.addDataType("real");
//  QVERIFY(realTypeItem);
//  model::base::DataTypeItem* myEnumTypeItem = testBaseModel.addDataType("myEnum");
//  QVERIFY(myEnumTypeItem);

//  ///signals///////////
//  model::base::SignalItem* signalItem = testBaseModel.addSignal("emptySignal");
//  QVERIFY(signalItem);
//  signalItem = testBaseModel.addSignal("complexSignal");
//  QVERIFY(signalItem);
//  model::base::ParamItem* paramItem = signalItem->addParameter("x", intTypeItem);
//  QVERIFY(paramItem);
//  paramItem = signalItem->addParameter("y", realTypeItem);
//  QVERIFY(paramItem);
//  paramItem = signalItem->addParameter("x", myEnumTypeItem);
//  QVERIFY(paramItem == 0);

//  ///attributes/////////
//  model::base::AttributeItem* attributeItem = testBaseModel.addAttribute("intAttribute",
//                                                                         intTypeItem,
//                                                                         "10");
//  QVERIFY(attributeItem);
//  attributeItem = testBaseModel.addAttribute("y", realTypeItem, "1.2");
//  QVERIFY(attributeItem);
//  attributeItem = testBaseModel.addAttribute("y", myEnumTypeItem, "");
//  QVERIFY(attributeItem == 0);

  return;
}

void LoadModelTest::loadMscModelTest()
{
  using namespace model::msc;

//  MscModel testMscModel;

//  ComLoadMscModel loadCommand(&testMscModel,
//                              ":/testdata/testmscmodel.json");
//  QString errorMessage;
//  bool result = loadCommand.execute(&errorMessage);
//  QVERIFY(result);
//  QVERIFY(errorMessage.isEmpty());

//  QString errorString;
//  model::base::DataTypeItem* enumType=testMscModel.addDataType("MyEnumType",
//                                                       &errorString);
//  QVERIFY(enumType);
//  enumType->setTypeEnum(prop::Enum);
//  enumType->addLiteral("lit1");
//  enumType->addLiteral("lit2");

//  model::base::DataTypeItem* stringType=testMscModel.addDataType("string",
//                                                         &errorString);
//  QVERIFY(stringType);
//  stringType->setTypeEnum(prop::String);

//  model::base::SignalItem* signal=testMscModel.addSignal("signal",
//                                                         &errorString);
//  QVERIFY(signal);
//  model::base::ParamItem* paramItem=signal->addParameter("param", enumType, &errorString);
//  QVERIFY(paramItem);

//  MscComponentItem* comp1=testMscModel.addComponent("comp1",
//                                                    &errorString);
//  QVERIFY(comp1);
//  PortItem* port1=comp1->addPort("port", &errorString);
//  QVERIFY(port1);

//  //error
//  PortItem* wrong_port=comp1->addPort("port", &errorString);
//  QVERIFY(wrong_port==0);
//  QVERIFY(errorString=="There is already a port "
//                        "'port' available!");
//  ///////////////////////////////////

//  MscComponentItem* comp2=testMscModel.addComponent("comp2",
//                                                    &errorString);
//  QVERIFY(comp2);
//  PortItem* port2=comp2->addPort("port", &errorString);
//  QVERIFY(port2);

//  MscSequence* sequ1=testMscModel.addSequence("sequ1");

//  ///only text-message
//  MscMessageItem* message=sequ1->addMessage(port1, port2, "signal_in(x=0)");

//  ///typed message
//  message=sequ1->addMessage(port2, port1);
//  message->setSignal(signal);
//  message->addParamValue(signal->parameter("param"), "lit1");

//  MscSequence* sequ2=testMscModel.addSequence("sequ2");
//  message=sequ2->addMessage(port2, port1, "signal_out(y=25)");

//  MscFragmentItem* altFragment=sequ2->addFragment(AlternativeFragment);
//  MscFragmentRegionItem* cond1Region=altFragment->addRegion("condition 1");
//  message=cond1Region->addMessage(port1, port2);
//  message->setSignal(signal);
//  message->addParamValue(signal->parameter("param"), "lit2");

//  MscFragmentRegionItem* cond2Region=altFragment->addRegion("condition 2");
//  message=cond2Region->addMessage(port2, port1);
//  message->setSignal(signal);
//  message->addParamValue(signal->parameter("param"), "lit1");

//  message=sequ2->addMessage(port1, port2, "signal_end(here are the params ...)");

//  MscSequence* sequ3=testMscModel.addSequence("sequ3");

//  message=sequ3->addMessage(port2, port1, "signal_out(y=25)");

//  altFragment=sequ3->addFragment(AlternativeFragment);
//  cond1Region=altFragment->addRegion("condition 1");
//  message=cond1Region->addMessage(port1, port2);
//  message->setSignal(signal);
//  message->addParamValue(signal->parameter("param"), "lit2");

//  cond2Region=altFragment->addRegion("condition 2");
//  message=cond2Region->addMessage(port2, port1);
//  message->setSignal(signal);
//  message->addParamValue(signal->parameter("param"), "lit1");

//  MscFragmentItem* loopFragment=cond2Region->addFragment(LoopFragment);
//  MscFragmentRegionItem* loopRegion=loopFragment->addRegion();
//  message=loopRegion->addMessage(port1, port2, "loop message");

//  MscFragmentItem* loop2Fragment=loopRegion->addFragment(LoopFragment);
//  MscFragmentRegionItem* loop2Region=loop2Fragment->addRegion("loop statement");
//  message=loop2Region->addMessage(port2, port1, "inner loop message");

//  message=sequ3->addMessage(port1, port2, "signal_end(here are the params ...)");

  return;
}

void LoadModelTest::loadStateMachineModelTest()
{
  using namespace model::statemachine;

  StateMachineModel smModel;
  ComLoadJsonSMModel loadCommand(":/testdata/testsmmodel.json",
                               &smModel);
  QString errorMessage;
  bool result = loadCommand.execute(&errorMessage);
  QVERIFY2(result, errorMessage.toLatin1());
  QVERIFY2(errorMessage.isEmpty(), errorMessage.toLatin1());

  QVERIFY(smModel.name()=="testSMModel");

  ComSaveJsonSMModel saveCommand(&smModel,
                              "testSMModel2.json");
  result = saveCommand.execute();
  QVERIFY(result);

  return;
}

QTEST_GUILESS_MAIN(LoadModelTest)

#include "tst_loadmodeltest.moc"
