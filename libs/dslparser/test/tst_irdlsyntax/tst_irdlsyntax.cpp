#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <dslparser/irdl/combuildirdlmodel.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <mobata/model/requirement/req.hpp>

class IrdlSyntaxTest
    : public QObject
{
  Q_OBJECT

public:
  IrdlSyntaxTest();

private Q_SLOTS:
  void initRequirements();
  void initTest();
  void cleanupTest();
  void modSynTestcase();
  void attributeAssignment();
//  void simpleIrdlTest_1();
  //  void simpleIrdlTest_2();

  void complexIrdlTest();

  void simpleRequirementsErrorTest_1();
  void simpleRequirementsErrorTest_2();

  void importTestNoErrors();
  void importDoubleDeclError1();
  //  void simpleRequirementsErrorTest_3();
  //  void simpleRequirementsErrorTest_4();
  //  void simpleRequirementsErrorTest_5();
  //  void simpleRequirementsErrorTest_6();
  //  void simpleRequirementsErrorTest_7();
  //  void simpleRequirementsErrorTest_8();
  //  void simpleRequirementsErrorTest_9();
  //  void simpleRequirementsErrorTest_10();

  //  void simpleIrdlKeywordTest_1();
  //  void simpleIrdlKeywordTest_2();
};

IrdlSyntaxTest::IrdlSyntaxTest()
{}

void IrdlSyntaxTest::initRequirements()
{
  Q_INIT_RESOURCE(complexexamples);
}

void IrdlSyntaxTest::initTest()
{}

void IrdlSyntaxTest::cleanupTest()
{}

void IrdlSyntaxTest::modSynTestcase()
{
  QString praefix = ":/Examples/ModSyn/";
  QString filename = praefix + "ModSynExample_1.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  //  model::ts::TestSuite testSuiteModel;
  //  testSuiteModel.initStandardDataTypes();
  model::irdl::RequirementsModel requirementModel;
  //QVERIFY(irdlModel);
  dslparser::irdl::ComBuildIrdlModel command(docText, &requirementModel,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
}

void IrdlSyntaxTest::attributeAssignment()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_3.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  //  model::ts::TestSuite testSuiteModel;
  //  testSuiteModel.initStandardDataTypes();
  model::irdl::RequirementsModel requirementModel;
  //QVERIFY(irdlModel);
  dslparser::irdl::ComBuildIrdlModel command(docText, &requirementModel,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
}


//void IrdlSyntaxTest::simpleIrdlTest_2()
//{
//  QString docText(QString("Requirements{ Declaration {name: myRequirements; ")+
//                  QString("enabled: true; ")+
//                  QString("Attribute int internAttribute = 0;")+
//                  QString("Signal stimuli (int x, int y);}}"));
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel);

//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, true);
//  QCOMPARE(0, command.errors().count());
//  QCOMPARE(QString("myRequirements"), irdlModel->name());
//  QCOMPARE(true, irdlModel->isEnabled());
//  QCOMPARE(QString("internAttribute"),irdlModel->attributes().at(0)->name());
//  QCOMPARE(QString("0"),irdlModel->attributes().at(0)->initValue());
//  QCOMPARE(QString("int"),irdlModel->attributes().at(0)->dataType()->text());
//  QCOMPARE(QString("stimuli"), irdlModel->getSignals().at(0)->name());
//  QCOMPARE(QString("x"), irdlModel->getSignals().at(0)->params().at(0)->name());
//  QCOMPARE(QString("int"), irdlModel->getSignals().at(0)->params().at(0)->dataType()->text());
//  QCOMPARE(QString("y"), irdlModel->getSignals().at(0)->params().at(1)->name());
//  QCOMPARE(QString("int"), irdlModel->getSignals().at(0)->params().at(1)->dataType()->text());
//  return;
//}

void IrdlSyntaxTest::complexIrdlTest(){
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_irdl_4.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  //  model::ts::TestSuite testSuiteModel;
  //  testSuiteModel.initStandardDataTypes();
  model::irdl::RequirementsModel requirementModel;
  //QVERIFY(irdlModel);
  dslparser::irdl::ComBuildIrdlModel command(docText, &requirementModel,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());


  //signals
  model::irdl::SignalItem* signal_setButtonFM = requirementModel.importedModels().value(QString("decl"))->signal(QString("setButtonFM"));
  QVERIFY(signal_setButtonFM);
  model::irdl::ParamItem* paramItem =  signal_setButtonFM->parameter(QString("Gesamtanlage_Start"));
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_setButton = requirementModel.importedModels().value(QString("decl"))->signal(QString("setButton"));
  QVERIFY(signal_setButton);
  paramItem =  signal_setButton->parameter(QString("name"));
  QVERIFY(paramItem);
  paramItem =  signal_setButton->parameter(QString("bValue"));
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_setStop = requirementModel.importedModels().value(QString("decl"))->signal(QString("setStop"));
  QVERIFY(signal_setStop);
  paramItem =  signal_setStop->parameter(QString("bValue"));
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_confirmation = requirementModel.importedModels().value(QString("decl"))->signal(QString("confirmation"));
  QVERIFY(signal_confirmation);
  paramItem =  signal_confirmation->parameter(QString("bValue"));
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_setStart = requirementModel.importedModels().value(QString("decl"))->signal(QString("setStart"));
  QVERIFY(signal_setStart);
  paramItem =  signal_setStart->parameter(QString("bValue"));
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_checkByteValue_ActiveStep = requirementModel.importedModels().value(QString("decl"))->signal(QString("checkByteValue_ActiveStep"));
  QVERIFY(signal_checkByteValue_ActiveStep);
  paramItem =  signal_checkByteValue_ActiveStep->parameter(QString("_Active"));
  QVERIFY(paramItem);
  paramItem =  signal_checkByteValue_ActiveStep->parameter(QString("timer"));
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_sendResponse = requirementModel.importedModels().value(QString("decl"))->signal(QString("sendResponse"));
  QVERIFY(signal_sendResponse);
  paramItem =  signal_sendResponse->parameter(QString("retValue"));
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_sendResponseBool = requirementModel.importedModels().value(QString("decl"))->signal(QString("sendResponseBool"));
  QVERIFY(signal_sendResponseBool);
  paramItem =  signal_sendResponseBool->parameter(QString("name"));
  QVERIFY(paramItem);
  paramItem =  signal_sendResponseBool->parameter(QString("bValue"));
  QVERIFY(paramItem);

  //attributes
  model::irdl::AttributeItem* attribute_globalAttribute = requirementModel.importedModels().value(QString("decl"))->attribute(QString("globalAttribute"));
  QVERIFY(attribute_globalAttribute);
  QCOMPARE(attribute_globalAttribute->initValue(),QString("0"));

  //components
  model::irdl::ReqActorComponentItem* actorComp = static_cast<model::irdl::ReqActorComponentItem*>(requirementModel.component(QString("user")));
  QVERIFY(actorComp);
  QCOMPARE(actorComp->description(),QString("Nutzer der Anlage"));

  model::irdl::ReqComponentItem* anlageComp = static_cast<model::irdl::ReqComponentItem*>(requirementModel.component(QString("system1")));
  QVERIFY(anlageComp);
  QCOMPARE(anlageComp->description(),QString("Produktionsanlage"));
  model::irdl::AttributeItem* attribute = anlageComp->attribute(QString("initialized"));
  QVERIFY(attribute);
  QCOMPARE(attribute_globalAttribute->initValue(),QString("0"));

  //****************requirement Gutverhalten*************************************************************
  //declaration
  model::irdl::RequirementItem* reqGutverhalten = requirementModel.requirements().at(0);//QString("Gutverhalten"));
  QVERIFY(reqGutverhalten);
  QCOMPARE(reqGutverhalten->name(),QString("Gutverhalten"));
  QCOMPARE(reqGutverhalten->description(),QString("Beschreibung des Gutverhaltens"));
  attribute = requirementModel.attribute(QString("retValue"));
  QVERIFY(attribute);
  QCOMPARE(attribute->initValue(),QString("0"));

  //statement
  model::irdl::StatementItem* statement = static_cast<model::irdl::StatementItem*>((model::msc::MscStatementItem*)reqGutverhalten->sequenceItems().at(0));//anlageComp, "Init"));
  QVERIFY(statement);
  QCOMPARE(statement->component(),anlageComp);
  QCOMPARE(statement->statement(),QString("Init"));

  //message
  model::irdl::MessageItem* message = static_cast<model::irdl::MessageItem*>((model::msc::MscMessageItem*)reqGutverhalten->sequenceItems().at(1));//(actorComp, anlageComp, "sendButtonFM"));
  QVERIFY(message);
  model::irdl::SignalItem* signal = requirementModel.importedModels().value(QString("decl"))->signal(QString("setButtonFM"));
  QVERIFY(signal);
  QCOMPARE(message->signal(),signal);
  model::irdl::ParamItem* parameter = signal->parameter(QString("Gesamtanlage_Start"));
  QVERIFY(parameter);
  model::irdl::ParamValueItem* paramValue = message->paramValue(parameter->name());
  QVERIFY(paramValue);
  QCOMPARE(paramValue->value(),QVariant(true));

  //check
  model::irdl::CheckMessageItem* check = static_cast<model::irdl::CheckMessageItem*>((model::msc::MscCheckMessageItem*)reqGutverhalten->sequenceItems().at(2));//anlageComp, actorComp, "sendResponse"));
  QVERIFY(check);
  QCOMPARE(check->sourcePort(),anlageComp->defaultPort());
  QCOMPARE(check->targetPort(),actorComp->defaultPort());
  signal = requirementModel.importedModels().value(QString("decl"))->signal(QString("sendResponse"));
  QVERIFY(signal);
  QCOMPARE(check->signal(),signal);
  QCOMPARE(check->guard(),QString("retValue==true"));
  QCOMPARE(check->timeout(),3000);

  //statement
  statement = static_cast<model::irdl::StatementItem*>((model::msc::MscStatementItem*)reqGutverhalten->sequenceItems().at(3));//anlageComp, "Auto"));
  QVERIFY(statement);

  //duration
  model::msc::MscFragmentItem* durationItem = static_cast<model::msc::MscFragmentItem*>((model::msc::MscFragmentItem*)reqGutverhalten->sequenceItems().at(4));//3000);
  QVERIFY(durationItem);
  QCOMPARE(durationItem->duration(),(uint)3000);
  model::irdl::FragmentRegionItem* durationRegionItem = durationItem->regions().front();
  QVERIFY(durationRegionItem);

  QVERIFY(durationRegionItem->sequenceItems().size());
  message = static_cast<model::irdl::MessageItem*>((model::msc::MscMessageItem*)durationRegionItem->sequenceItems().at(0));//actorComp, anlageComp, "setButtonFM"));
  QVERIFY(message);
  signal = requirementModel.importedModels().value(QString("decl"))->signal(QString("setButtonFM"));
  QVERIFY(signal);
  QCOMPARE(message->signal(),signal);
  parameter = signal->parameter(QString("Gesamtanlage_Start"));
  QVERIFY(parameter);
  paramValue = message->paramValue(parameter->name());
  QVERIFY(paramValue);
  QCOMPARE(paramValue->value(),QVariant(true));

  check = static_cast<model::irdl::CheckMessageItem*>((model::msc::MscCheckMessageItem*)durationRegionItem->sequenceItems().at(1));//anlageComp, actorComp, "sendResponse"));
  QVERIFY(check);
  QCOMPARE(check->sourcePort(),anlageComp->defaultPort());
  QCOMPARE(check->targetPort(),actorComp->defaultPort());
  signal = requirementModel.importedModels().value(QString("decl"))->signal(QString("sendResponse"));
  QVERIFY(signal);
  QCOMPARE(check->signal(),signal);
  QCOMPARE(check->guard(),QString("retValue==true"));

  //statement
  statement = static_cast<model::irdl::StatementItem*>((model::msc::MscStatementItem*)reqGutverhalten->sequenceItems().at(1));//anlageComp, "Init"));
  QVERIFY(statement);

  //  QCOMPARE(47, command.keywordTextLocations().size());

  //  QCOMPARE(26, command.modelTextLocations().size());

  //  typedef model::msc::MscTimerItem* TimerItem;
  //  typedef model::msc::MscSequenceItem* SeqItem;
  //  typedef model::base::AttributeItem* AttItem;
  //  typedef model::base::SignalItem* SigItem;
  //  typedef model::msc::MscMessageItem* MesItem;
  //  typedef model::msc::MscFragmentItem* AltItem;
  //  typedef model::msc::MscFragmentRegionItem* RegItem;
  //  typedef model::msc::MscCheckMessageItem* CheckItem;
  //  typedef model::msc::MscStatementItem* StateItem;

  //  AttItem attribute_1 = irdlModel->attributes().at(0);
  //  AttItem attribute_2 = irdlModel->attributes().at(1);
  //  AttItem attribute_3 = irdlModel->attributes().at(2);
  //  AttItem attribute_4 = irdlModel->attributes().at(3);

  //  SigItem signal1 = irdlModel->getSignals().at(0);
  //  SigItem signal2 = irdlModel->getSignals().at(1);
  //  SigItem signal3 = irdlModel->getSignals().at(2);

  //  QVERIFY(dynamic_cast<TimerItem>((SeqItem)irdlModel->sequenceItems().at(0)));
  //  TimerItem timer1 = dynamic_cast<TimerItem>((SeqItem)irdlModel->sequenceItems().at(0));
  //  QVERIFY(dynamic_cast<StateItem>((SeqItem)irdlModel->sequenceItems().at(1)));
  //  StateItem state1 = dynamic_cast<StateItem>((SeqItem)irdlModel->sequenceItems().at(1));
  //  QVERIFY(dynamic_cast<MesItem>((SeqItem)irdlModel->sequenceItems().at(2)));
  //  MesItem message1 = dynamic_cast<MesItem>((SeqItem)irdlModel->sequenceItems().at(2));
  //  QVERIFY(dynamic_cast<CheckItem>((SeqItem)irdlModel->sequenceItems().at(3)));
  //  CheckItem check1 = dynamic_cast<CheckItem>((SeqItem)irdlModel->sequenceItems().at(3));

  //  QCOMPARE(message1->targetPort()->name(),QString("pTestSystem"));
  //  QCOMPARE(message1->sourcePort()->name(),QString("pRseApp"));
  //  QCOMPARE(message1->paramValues().size(),2);
  //  QCOMPARE(message1->paramValues().at(0)->param()->name(),QString("x"));
  //  QCOMPARE(message1->paramValues().at(0)->value(),QVariant(10));
  //  QCOMPARE(message1->paramValues().at(1)->param()->name(),QString("y"));
  //  QCOMPARE(message1->paramValues().at(1)->value(),QVariant(20));

  //  QCOMPARE(check1->targetPort()->name(),QString("pRseApp"));
  //  QCOMPARE(check1->sourcePort()->name(),QString("pEvaluation"));
  //  QCOMPARE(check1->guard(),QString("response(res==true and\n                    (value >=10)\n                    and value<=20\n                    and (value<=15\n                          or value>=12) and (internAttribute < 10))"));
  //  QCOMPARE(check1->timeout(), 300);

  //  QVERIFY(dynamic_cast<AltItem>((SeqItem)irdlModel->sequenceItems().at(4)));
  //  AltItem alt1 = dynamic_cast<AltItem>((SeqItem)irdlModel->sequenceItems().at(4));
  //  RegItem reg1 = alt1->regions().at(0);
  //  QVERIFY(dynamic_cast<CheckItem>((SeqItem)reg1->sequenceItems().at(0)));
  //  CheckItem check2 = dynamic_cast<CheckItem>((SeqItem)reg1->sequenceItems().at(0));
  //  QVERIFY(dynamic_cast<StateItem>((SeqItem)reg1->sequenceItems().at(1)));
  //  StateItem state2 = dynamic_cast<StateItem>((SeqItem)reg1->sequenceItems().at(1));

  //  RegItem reg2 = alt1->regions().at(1);
  //  QVERIFY(dynamic_cast<CheckItem>((SeqItem)reg2->sequenceItems().at(0)));
  //  CheckItem check3 = dynamic_cast<CheckItem>((SeqItem)reg2->sequenceItems().at(0));
  //  QVERIFY(dynamic_cast<StateItem>((SeqItem)reg2->sequenceItems().at(1)));
  //  StateItem state3 = dynamic_cast<StateItem>((SeqItem)reg2->sequenceItems().at(1));

  //  RegItem reg3 = alt1->regions().at(2);
  //  QVERIFY(dynamic_cast<StateItem>((SeqItem)reg3->sequenceItems().at(0)));
  //  StateItem state4 = dynamic_cast<StateItem>((SeqItem)reg3->sequenceItems().at(0));



  //  dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(irdlModel->index());
  //  QCOMPARE(0, modelTextLocation.start());
  //  QCOMPARE(1668, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Requirements, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(attribute_1->index());
  //  QCOMPARE(217, modelTextLocation.start());
  //  QCOMPARE(250, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(attribute_2->index());
  //  QCOMPARE(256, modelTextLocation.start());
  //  QCOMPARE(294, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(attribute_3->index());
  //  QCOMPARE(300, modelTextLocation.start());
  //  QCOMPARE(338, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(attribute_4->index());
  //  QCOMPARE(344, modelTextLocation.start());
  //  QCOMPARE(376, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Attribute, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(signal1->index());
  //  QCOMPARE(383, modelTextLocation.start());
  //  QCOMPARE(412, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Signal, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(signal2->index());
  //  QCOMPARE(418, modelTextLocation.start());
  //  QCOMPARE(448, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Signal, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(signal3->index());
  //  QCOMPARE(454, modelTextLocation.start());
  //  QCOMPARE(491, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Signal, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(timer1->index());
  //  QCOMPARE(500, modelTextLocation.start());
  //  QCOMPARE(541, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Timer, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(state1->index());
  //  QCOMPARE(545, modelTextLocation.start());
  //  QCOMPARE(569, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(message1->index());
  //  QCOMPARE(575, modelTextLocation.start());
  //  QCOMPARE(691, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Message, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(check1->index());
  //  QCOMPARE(696, modelTextLocation.start());
  //  QCOMPARE(994, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Check, modelTextLocation.tokenType());

  ////  modelTextLocation = command.modelTextLocations().value(tOut1->index());
  ////  QCOMPARE(968, modelTextLocation.start());
  ////  QCOMPARE(980, modelTextLocation.end());
  ////  QCOMPARE((int)dslparser::Timeout, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(alt1->index());
  //  QCOMPARE(1001, modelTextLocation.start());
  //  QCOMPARE(1666, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Alt, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(reg1->index());
  //  QCOMPARE(1010, modelTextLocation.start());
  //  QCOMPARE(1400, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Region, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(check2->index());
  //  QCOMPARE(1043, modelTextLocation.start());
  //  QCOMPARE(1361, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Check, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(state2->index());
  //  QCOMPARE(1370, modelTextLocation.start());
  //  QCOMPARE(1393, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(reg2->index());
  //  QCOMPARE(1406, modelTextLocation.start());
  //  QCOMPARE(1594, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Region, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(check3->index());
  //  QCOMPARE(1416, modelTextLocation.start());
  //  QCOMPARE(1556, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Check, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(state3->index());
  //  QCOMPARE(1564, modelTextLocation.start());
  //  QCOMPARE(1587, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(reg3->index());
  //  QCOMPARE(1600, modelTextLocation.start());
  //  QCOMPARE(1662, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Region, modelTextLocation.tokenType());

  //  modelTextLocation = command.modelTextLocations().value(state4->index());
  //  QCOMPARE(1632, modelTextLocation.start());
  //  QCOMPARE(1655, modelTextLocation.end());
  //  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

}

void IrdlSyntaxTest::simpleRequirementsErrorTest_1()
{
  QString docText("Requirement{"
                  "Declaration {"
                  "name: Gutverhalten;"
                  "description: \"Beschreibung des Gutverhaltens\";"
                  "Attribute int retValue = 0;"

                  "Actor{"
                  "name: user;"
                  "description: \"Nutzer der Anlage\";"
                  "}"

                  "Component{"
                  "name: system1;"
                  "description: \"Produktionsanlage\";"
                  "Attribute bool initialized = false;"
                  "}"
                  "Signal sendMsg(bool retValue);"
                  "use system1 as system;"
                  "}"
                  "Check(system->user): sendMsg[msg.retValue==true];"
                  "Check(system->user): sendMsg[msg.ret1Value==true];}");
  model::irdl::RequirementsModel requirementModel;
  //QVERIFY(irdlModel);
  dslparser::irdl::ComBuildIrdlModel command(docText, &requirementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  //IMPORTANT ONLY ONE ERROR!!!!

  return;
}

void IrdlSyntaxTest::simpleRequirementsErrorTest_2()
{

  QString docText("Requirement{\n"
                  "Declaration {\n"
                  "name: Gutverhalten;\n"
                  "description: \"Beschreibung des Gutverhaltens\";\n"
                  "Type enum (one, two, three) MyEnum;\n"
                  "Attribute int retValue = 0;\n"

                  "Actor{\n"
                  "name: user;\n"
                  "description: \"Nutzer der Anlage\";\n"
                  "}\n"

                  "Component{\n"
                  "name: system1;\n"
                  "description: \"Produktionsanlage\";\n"
                  "Attribute bool initialized = false;\n"
                  "}\n"
                  "Signal sendMsg(bool retValue2);\n"
                  "use system1 as system;\n"
                  "}\n"
                  "Check(system->user): sendMsg[retValue==true];\n"
                  "Check(system->user): sendMsg[retValue2==true];\n"
                  "Check(system->user): sendMsg[msg.retValue2==true];\n"
                  "Check(system->user): sendMsg[msg.retValue==true];\n"
                  "Check(system->user): sendMsg[this.retValue==true];\n"
                  "Check(system->user): sendMsg[this.retValue2==true];\n"
                  "Check(system->user): sendMsg[retValue3==true];\n"
                  "Check(system->user): sendMsg[one==1];\n"
                  "Message(system->user): sendMsg(retValue);\n"
                  "Message(system->user): sendMsg(retValue2);\n"
                  "Message(system->user): sendMsg(msg.retValue2);\n"
                  "Message(system->user): sendMsg(msg.retValue);\n"
                  "Message(system->user): sendMsg(this.retValue);\n"
                  "Message(system->user): sendMsg(this.retValue2);\n"
                  "Message(system->user): sendMsg(retValue3);\n"
                  "Message(system->user): sendMsg(one);\n}\n");
  model::irdl::RequirementsModel requirementModel;
  //QVERIFY(irdlModel);
  dslparser::irdl::ComBuildIrdlModel command(docText, &requirementModel);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(12, command.errors().count());
}

void IrdlSyntaxTest::importTestNoErrors()
{
  QString praefix = ":/Examples/ModSyn/";
  QString filename = praefix + "ModSynExample_1_2.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  //  model::ts::TestSuite testSuiteModel;
  //  testSuiteModel.initStandardDataTypes();
  model::irdl::RequirementsModel requirementModel;
  //QVERIFY(irdlModel);
  dslparser::irdl::ComBuildIrdlModel command(docText, &requirementModel,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
}

void IrdlSyntaxTest::importDoubleDeclError1()
{
  QString praefix = ":/Examples/ModSyn/";
  QString filename = praefix + "ModSynExample_1_3.irdl";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  //  model::ts::TestSuite testSuiteModel;
  //  testSuiteModel.initStandardDataTypes();
  model::irdl::RequirementsModel requirementModel;
  //QVERIFY(irdlModel);
  dslparser::irdl::ComBuildIrdlModel command(docText, &requirementModel,praefix);

  QString errorString;
  bool result = command.execute(&errorString);
  for(const dslparser::DslError& error : command.errors())
    qDebug()<<"error: "<<error.message()<<"; at line: "<<error.line()<<"; at pos: "<<error.charPositionInLine();

  QCOMPARE(result, false);
  QCOMPARE(12, command.errors().count());
}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_3()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_6.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(command.errors().count(), 2);
//  return;
//}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_4()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_7.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(3, command.errors().count());
//  return;
//}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_5()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_8.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(3, command.errors().count());
//  return;
//}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_6()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_9.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(2, command.errors().count());
//  return;
//}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_7()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_10.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(2, command.errors().count());
//  return;
//}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_8()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_11.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(1, command.errors().count());
//  return;
//}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_9()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_12.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(1, command.errors().count());
//  return;
//}

//void IrdlSyntaxTest::simpleRequirementsErrorTest_10()
//{
//  QString praefix = ":/Examples/";
//  QString filename = praefix + "example_irdl_13.irdl";
//  QFile file(filename);
//  if(!file.open(QFile::ReadOnly))
//    qDebug()<<"file '"<<filename<<"' could not be opended!";
//  QString docText(file.readAll());
//  file.close();
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,praefix);
//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, false);
//  QCOMPARE(5, command.errors().count());
//  return;
//}

//void IrdlSyntaxTest::simpleIrdlKeywordTest_1()
//{
//  QString docText("Requirements{ Declaration {name: myRequirements;}}"));
//  model::ts::TestSuite testSuiteModel;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"));
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel);

//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, true);
//  QCOMPARE(0, command.errors().count());
//  QCOMPARE(QString("myRequirements"), irdlModel->name());

//  QCOMPARE(command.keywordTextLocations().size(), 3);
//  QCOMPARE(command.keywordTextLocations().at(0).start(), 0); //Requirements
//  QCOMPARE(command.keywordTextLocations().at(0).length(), 8);
//  QCOMPARE(command.keywordTextLocations().at(1).start(), 10); //Declaration
//  QCOMPARE(command.keywordTextLocations().at(1).length(), 11);
//  QCOMPARE(command.keywordTextLocations().at(2).start(), 23); //name
//  QCOMPARE(command.keywordTextLocations().at(2).length(), 4);

//  QCOMPARE(1, command.modelTextLocations().size());
//  return;
//}

//void IrdlSyntaxTest::simpleIrdlKeywordTest_2()
//{
//  /*
//  QString docText("Requirements{ name: myRequirements; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}"));
//  model::ts::TestSuite testSuiteModel;
//  QString errorString1;
//  model::ts::RequirementsItem* irdlModel=testSuiteModel.addRequirements(QString("test"),&errorString1);
//  QVERIFY(irdlModel);
//  dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel);

//  QString errorString;
//  bool result = command.execute(&errorString);
//  QCOMPARE(result, true);
//  QCOMPARE(0, command.errors().count());
//  QCOMPARE(QString("myRequirements"), irdlModel->name());

//  model::base::ComponentItem* component_1 = irdlModel->components().at(1);
//  QVERIFY(component_1);
//  QCOMPARE(QString("Comp1"), component_1->name());
//  QCOMPARE(component_1->ports().size(), 3);//with default port
//  model::base::PortItem* port1 = component_1->ports().at(1);
//  QCOMPARE(QString("p1"), port1->name());
//  model::base::PortItem* port2 = component_1->ports().at(2);
//  QCOMPARE(QString("p2"), port2->name());

//  model::base::ComponentItem* component_2 = irdlModel->components().at(2);
//  QVERIFY(component_2);
//  QCOMPARE(QString("Comp2"), component_2->name());
//  QCOMPARE(component_2->ports().size(), 3);//with default port
//  model::base::PortItem* port3 = component_2->ports().at(1);
//  QCOMPARE(QString("p3"), port3->name());
//  model::base::PortItem* port4 = component_2->ports().at(2);
//  QCOMPARE(QString("p4"), port4->name());

//  QCOMPARE(11, command.keywordTextLocations().size());
//  QCOMPARE(command.keywordTextLocations().at(10).start(), 0); //Requirements
//  QCOMPARE(command.keywordTextLocations().at(10).length(), 10);
//  QCOMPARE(command.keywordTextLocations().at(0).start(), 12); //name
//  QCOMPARE(command.keywordTextLocations().at(0).length(), 4);
//  QCOMPARE(command.keywordTextLocations().at(1).start(), 34); //TestComp
//  QCOMPARE(command.keywordTextLocations().at(1).length(), 13);
//  QCOMPARE(command.keywordTextLocations().at(2).start(), 50); //name
//  QCOMPARE(command.keywordTextLocations().at(2).length(), 4);
//  QCOMPARE(command.keywordTextLocations().at(3).start(), 64); //enabled
//  QCOMPARE(command.keywordTextLocations().at(3).length(), 7);
//  QCOMPARE(command.keywordTextLocations().at(4).start(), 79); //Port
//  QCOMPARE(command.keywordTextLocations().at(4).length(), 4);
//  QCOMPARE(command.keywordTextLocations().at(5).start(), 94); //TestComp
//  QCOMPARE(command.keywordTextLocations().at(5).length(), 13);
//  QCOMPARE(command.keywordTextLocations().at(6).start(), 110); //name
//  QCOMPARE(command.keywordTextLocations().at(6).length(), 4);
//  QCOMPARE(command.keywordTextLocations().at(7).start(), 124); //enabled
//  QCOMPARE(command.keywordTextLocations().at(7).length(), 7);
//  QCOMPARE(command.keywordTextLocations().at(8).start(), 141); //Port
//  QCOMPARE(command.keywordTextLocations().at(8).length(), 4);
//  QCOMPARE(command.keywordTextLocations().at(9).start(), 150); //Port
//  QCOMPARE(command.keywordTextLocations().at(9).length(), 4);

//  QCOMPARE(6, command.modelTextLocations().size());

//  dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(component_1->index());
//  QCOMPARE(34, modelTextLocation.start());
//  QCOMPARE(90, modelTextLocation.end());
//  QCOMPARE((int)dslparser::TestComponent, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(port1->index());
//  QCOMPARE(84, modelTextLocation.start());
//  QCOMPARE(85, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(port2->index());
//  QCOMPARE(87, modelTextLocation.start());
//  QCOMPARE(88, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(component_2->index());
//  QCOMPARE(94, modelTextLocation.start());
//  QCOMPARE(158, modelTextLocation.end());
//  QCOMPARE((int)dslparser::TestComponent, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(port3->index());
//  QCOMPARE(146, modelTextLocation.start());
//  QCOMPARE(147, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(port4->index());
//  QCOMPARE(155, modelTextLocation.start());
//  QCOMPARE(156, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Port, modelTextLocation.tokenType());*/
//  return;
//}

QTEST_GUILESS_MAIN(IrdlSyntaxTest)

#include "tst_irdlsyntax.moc"
