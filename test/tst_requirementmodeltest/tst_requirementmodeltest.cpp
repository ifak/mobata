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

#include <mobata/model/irdl/req.hpp>

class RequirementModelTest : public QObject
{
  Q_OBJECT

public:
  RequirementModelTest();

private Q_SLOTS:
  void buildRequirementModelTest();

};

RequirementModelTest::RequirementModelTest()
{}

void RequirementModelTest::buildRequirementModelTest()
{
  //model
  model::irdl::RequirementsModel requirementModel;

  //types
  model::irdl::DataTypeItem* intTypeItem = requirementModel.addDataType(QStringLiteral("int"));
  QVERIFY(intTypeItem);
  model::irdl::DataTypeItem* realTypeItem = requirementModel.addDataType(QStringLiteral("real"));
  QVERIFY(realTypeItem);
  model::irdl::DataTypeItem* boolTypeItem = requirementModel.addDataType(QStringLiteral("bool"));
  QVERIFY(boolTypeItem);
  model::irdl::DataTypeItem* stringTypeItem = requirementModel.addDataType(QStringLiteral("string"));
  QVERIFY(stringTypeItem);

  //signals
  model::irdl::SignalItem* signal_setButtonFM = requirementModel.addSignal("setButtonFM");
  QVERIFY(signal_setButtonFM);
  model::irdl::DataTypeItem* showHowToGetDataTypeItem = requirementModel.dataType("bool");
  QVERIFY(showHowToGetDataTypeItem);
  model::irdl::ParamItem* paramItem =  signal_setButtonFM->addParameter("Gesamtanlage_Start",
                                                                               showHowToGetDataTypeItem->name() /*boolTypeItem*/);
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_setButton = requirementModel.addSignal("setButton");
  QVERIFY(signal_setButton);
  paramItem =  signal_setButton->addParameter("name", stringTypeItem->name());
  QVERIFY(paramItem);
  paramItem =  signal_setButton->addParameter("bValue", boolTypeItem->name());
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_setStop = requirementModel.addSignal("setStop");
  QVERIFY(signal_setStop);
  paramItem =  signal_setStop->addParameter("bValue", boolTypeItem->name());
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_confirmation = requirementModel.addSignal("confirmation");
  QVERIFY(signal_confirmation);
  paramItem =  signal_confirmation->addParameter("bValue", boolTypeItem->name());
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_setStart = requirementModel.addSignal("setStart");
  QVERIFY(signal_setStart);
  paramItem =  signal_setStart->addParameter("bValue", boolTypeItem->name());
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_checkByteValue_ActiveStep = requirementModel.addSignal("checkByteValue_ActiveStep");
  QVERIFY(signal_checkByteValue_ActiveStep);
  paramItem =  signal_checkByteValue_ActiveStep->addParameter("_Active", intTypeItem->name());
  QVERIFY(paramItem);
  paramItem =  signal_checkByteValue_ActiveStep->addParameter("timer", intTypeItem->name());
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_sendResponse = requirementModel.addSignal("sendResponse");
  QVERIFY(signal_sendResponse);
  paramItem =  signal_sendResponse->addParameter("retValue", intTypeItem->name());
  QVERIFY(paramItem);

  model::irdl::SignalItem* signal_sendResponseBool = requirementModel.addSignal("sendResponseBool");
  QVERIFY(signal_sendResponseBool);
  paramItem =  signal_sendResponseBool->addParameter("name", stringTypeItem->name());
  QVERIFY(paramItem);
  paramItem =  signal_sendResponseBool->addParameter("bValue", boolTypeItem->name());
  QVERIFY(paramItem);

  //attributes
  model::irdl::AttributeItem* attribute_globalAttribute = requirementModel.addAttribute("globalAttribute",
                                                                                               intTypeItem->name(),
                                                                                               "0");
  QVERIFY(attribute_globalAttribute);

  //components
  QString errorString;
  model::irdl::ReqActorComponentItem* actorComp = requirementModel.addComponent<model::irdl::ReqActorComponentItem>(("user"), &errorString);
  QVERIFY(actorComp);
  QVERIFY(errorString == "");
  actorComp->setDescription("Nutzer der Anlage");

  model::irdl::ReqComponentItem* anlageComp = requirementModel.addComponent<model::irdl::ReqComponentItem>(("Anlage"), &errorString);
  QVERIFY(anlageComp);
  QVERIFY(errorString == "");
  anlageComp->setDescription("Produktionsanlage");
  model::irdl::AttributeItem* attribute = anlageComp->addAttribute("initialized", boolTypeItem->name(), "false");
  QVERIFY(attribute);

  //****************requirement Gutverhalten*************************************************************
  //declaration
  model::irdl::RequirementItem* reqGutverhalten = requirementModel.addRequirement("Gutverhalten");
  QVERIFY(reqGutverhalten);
  reqGutverhalten->setDescription("Beschreibung des Gutverhaltens");
  attribute = reqGutverhalten->addAttribute("retValue", intTypeItem->name(), "0");
  QVERIFY(attribute);

  //statement
  model::irdl::StatementItem* statement = reqGutverhalten->addStatement(anlageComp, "Init");
  QVERIFY(statement);

  //message
  model::irdl::MessageItem* message = reqGutverhalten->addMessage(actorComp, anlageComp, "sendButtonFM");
  QVERIFY(message);
  model::irdl::SignalItem* signal = requirementModel.signal(QString("setButtonFM"));
  QVERIFY(signal);
  message->setSignal(signal);
  model::irdl::ParamItem* parameter = signal->parameter("Gesamtanlage_Start");
  QVERIFY(parameter);
  model::irdl::ParamValueItem* paramValue = message->addParamValue(parameter, true);
  QVERIFY(paramValue);

  //check
  model::irdl::CheckMessageItem* check = reqGutverhalten->addCheck(anlageComp, actorComp, "sendResponse");
  QVERIFY(check);
  signal = requirementModel.signal(QString("sendResponse"));
  QVERIFY(signal);
  check->setSignal(signal);
  check->setGuard("retValue==true");
  check->setTimeout(3000);

  //statement
  statement = reqGutverhalten->addStatement(anlageComp, "Auto");
  QVERIFY(statement);

  //duration
  model::msc::MscFragmentItem* durationItem = reqGutverhalten->addDurationFragment(3000);
  QVERIFY(durationItem);
  model::msc::MscFragmentRegionItem* durationRegionItem = durationItem->regions().front();
  QVERIFY(durationRegionItem);

  message = durationRegionItem->addMessage(actorComp, anlageComp, "setButtonFM");
  QVERIFY(message);
  signal = requirementModel.signal(QString("setButtonFM"));
  QVERIFY(signal);
  message->setSignal(signal);
  parameter = signal->parameter("Gesamtanlage_Start");
  QVERIFY(parameter);
  paramValue = message->addParamValue(parameter, true );
  QVERIFY(paramValue);

  check = durationRegionItem->addCheck(anlageComp, actorComp, "sendResponse");
  QVERIFY(check);
  signal = requirementModel.signal(QString("sendResponse"));
  QVERIFY(signal);
  check->setSignal(signal);
  check->setGuard("retValue==true");

  //statement
  statement = durationRegionItem->addStatement(anlageComp, "Init");
  QVERIFY(statement);

  //****************requirement Anlage Stopp*************************************************************
  //declaration
  model::irdl::RequirementItem* reqAnlageStopp = requirementModel.addRequirement("Anlage Stopp");
  QVERIFY(reqAnlageStopp);
  reqAnlageStopp->setDescription("Beschreibung Anlage Stopp");
  attribute = reqAnlageStopp->addAttribute("retValue", intTypeItem->name(), "0");
  QVERIFY(attribute);

  //statement
  statement = reqAnlageStopp->addStatement(anlageComp, "Auto");
  QVERIFY(statement);

  //message
  message = reqAnlageStopp->addMessage(actorComp, anlageComp, "setStop");
  QVERIFY(message);
  message->setSignal(signal_setStop);
  parameter = signal_setStop->parameter("bValue");
  QVERIFY(parameter);
  paramValue = message->addParamValue(parameter, true);
  QVERIFY(paramValue);

  //check
  check = reqAnlageStopp->addCheck(anlageComp, actorComp, "sendResponseBool");
  QVERIFY(check);
  check->setSignal(signal_sendResponseBool);
  check->setGuard("{name == \"Freeze\" and bValue == true}");
  check->setTimeout(5000);

  //statement
  statement = reqAnlageStopp->addStatement(anlageComp, "Stop");
  QVERIFY(statement);

  //message
  message = reqAnlageStopp->addMessage(actorComp, anlageComp, "setStop");
  QVERIFY(message);
  message->setSignal(signal_setStop);
  parameter = signal_setStop->parameter("bValue");
  QVERIFY(parameter);
  paramValue = message->addParamValue(parameter, false);
  QVERIFY(paramValue);

  //*********************alt*********************************************************
  model::irdl::FragmentItem* altFragment = reqAnlageStopp->addFragment(model::irdl::FragmentType::AlternativeFragment);
  QVERIFY(altFragment);
  altFragment->setDuration(3000);

  //region 1
  model::irdl::FragmentRegionItem* firstRegion=altFragment->addRegion("condition 1");
  QVERIFY(firstRegion);

  //message
  message = firstRegion->addMessage(actorComp, anlageComp);
  QVERIFY(message);
  message->setSignal(signal_confirmation);
  message->addParamValue(signal_confirmation->parameter("bValue"), "true");

  //check
  check = firstRegion->addCheck(anlageComp, actorComp);
  QVERIFY(check);
  check->setSignal(signal_sendResponseBool);
  check->setGuard("{name == \"Freeze\" and bValue == false}");

  //statement
  statement = firstRegion->addStatement(anlageComp, "Stop");
  QVERIFY(statement);

  //region 2
  model::irdl::FragmentRegionItem* secondRegion=altFragment->addRegion("condition 2");
  QVERIFY(secondRegion);

  //message
  message = secondRegion->addMessage(actorComp, anlageComp);
  QVERIFY(message);
  message->setSignal(signal_setStart);
  message->addParamValue(signal_setStart->parameter("bValue"), "true");

  //check
  check = firstRegion->addCheck(anlageComp, actorComp);
  QVERIFY(check);
  check->setSignal(signal_sendResponseBool);
  check->setGuard("{name == \"Start\" and bValue == true}");

  //statement
  statement = secondRegion->addStatement(anlageComp, "Stop");
  QVERIFY(statement);

  return;
}

QTEST_GUILESS_MAIN(RequirementModelTest)

#include "tst_requirementmodeltest.moc"
