#include <QtTest>

#include <mobata/model/ts/ts.hpp>
#include <dslparser/diagnosis/combuilddiagnosismodel.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/base_types.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <mobata/model/msc/mscloopfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>
#include <mobata/model/diagnosis/diagnosisitem.hpp>
#include <mobata/model/diagnosis/diagsequenceruleitem.hpp>
#include <mobata/model/diagnosis/diagsignalitem.hpp>
#include <mobata/model/base/propsignals.hpp>
#include <mobata/prop/nameproperty.hpp>

class DiagnosisSyntaxTest
        : public QObject
{
    Q_OBJECT

public:
    DiagnosisSyntaxTest();

private Q_SLOTS:
    void initDiagnosis();
    void initTest();
    void cleanupTest();
    void simpleDiagnosisDeclTest_1();
    void simpleDiagnosisDeclTest_2();

    void complexDiagnosisDeclTest();
    void sequentialTest();
    /*
  void simpleDiagnosisErrorTest_1();
  void simpleDiagnosisErrorTest_2();
  void simpleDiagnosisErrorTest_3();
  void simpleDiagnosisErrorTest_4();
  void simpleDiagnosisErrorTest_5();
  void simpleDiagnosisErrorTest_6();
  void simpleDiagnosisErrorTest_7();
  void simpleDiagnosisErrorTest_8();
  void simpleDiagnosisErrorTest_9();
  void simpleDiagnosisErrorTest_10();

  void simpleDiagnosisDeclKeywordTest_1();*/
    void simpleDiagnosisDeclKeywordTest_2();
};

DiagnosisSyntaxTest::DiagnosisSyntaxTest()
{}

void DiagnosisSyntaxTest::initDiagnosis()
{
    Q_INIT_RESOURCE(complexexamples);
}

void DiagnosisSyntaxTest::initTest()
{}

void DiagnosisSyntaxTest::cleanupTest()
{}

void DiagnosisSyntaxTest::simpleDiagnosisDeclTest_1()
{
    QString docText("Rule{ name: myDiagnosis;description: \"Abkündigung einer DENM prüfen\"; enabled: true;Sequence{}}");
    model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
    //QVERIFY(diagnosisModel);
    dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());
    QCOMPARE(QString("test"), diagnosisModel.name());
    QCOMPARE(diagnosisModel.rules().size(),1);
    model::diagnosis::DiagnosisSequenceRuleItem* rule = 0;
    rule = dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(diagnosisModel.rules().at(0));
    QVERIFY(rule);
    QCOMPARE(rule->name(),QStringLiteral("myDiagnosis"));
    QCOMPARE(rule->description(),QStringLiteral("Abkündigung einer DENM prüfen"));
    QCOMPARE(rule->isEnabled(),true);
    return;
}

void DiagnosisSyntaxTest::simpleDiagnosisDeclTest_2()
{
    QString docText(QString("Rule{ name: myDiagnosis; ")+
                    QString("description: \"Abkündigung einer DENM prüfen\"; enabled: true; ")+
                    QString("Declaration {Attribute int internAttribute = 0;")+
                    QString("Signal {name:stimuli;}}Sequence{}}"));
    model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
    //QVERIFY(diagnosisModel);
    dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel);

    QString errorString;
    bool result = command.execute(&errorString);
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());
    QCOMPARE(QString("test"), diagnosisModel.name());
    QCOMPARE(diagnosisModel.rules().size(),1);
    model::diagnosis::DiagnosisSequenceRuleItem* rule = 0;
    rule = dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(diagnosisModel.rules().at(0));
    QVERIFY(rule);
    QCOMPARE(rule->name(),QStringLiteral("myDiagnosis"));
    QCOMPARE(rule->description(),QStringLiteral("Abkündigung einer DENM prüfen"));
    QCOMPARE(rule->isEnabled(),true);
    model::base::PropSignals::SignalSet diagsignals = rule->getSignals();
    QCOMPARE(diagsignals.size(),1);
    QCOMPARE(diagsignals.at(0)->name(),QStringLiteral("stimuli"));
    return;
}

void DiagnosisSyntaxTest::complexDiagnosisDeclTest(){
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
    dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);

    QString errorString;
    bool result = command.execute(&errorString);
    if(!result)
      qDebug()<<errorString;
    QCOMPARE(result, true);
    QCOMPARE(0, command.errors().count());

    QCOMPARE(QString("test"), diagnosisModel.name());
    QCOMPARE(diagnosisModel.rules().size(),1);
    model::diagnosis::DiagnosisSequenceRuleItem* rule = 0;
    rule =dynamic_cast<model::diagnosis::DiagnosisSequenceRuleItem*>(diagnosisModel.rules().at(0));
    QVERIFY(rule);
    QCOMPARE(rule->name(),QStringLiteral("DENM_Cancelation"));
    QCOMPARE(rule->description(),QStringLiteral("Abkündigung einer DENM prüfen"));
    QCOMPARE(rule->isEnabled(),true);
    model::base::PropSignals::SignalSet diagsignals = rule->getSignals();
    QCOMPARE(diagsignals.size(),1);
    QCOMPARE(diagsignals.at(0)->name(),QStringLiteral("CyclistWarning"));
    model::diagnosis::DiagSignalItem* signal = dynamic_cast<model::diagnosis::DiagSignalItem*>(diagsignals.at(0));
    QCOMPARE(signal->condition(),QString("DENM.causeCode == 30 and DENM.cancelationFlag == false"));
    QVERIFY(signal);
    model::diagnosis::DiagSignalItem* baseSignal = signal->BaseSignal();
    QVERIFY(baseSignal);
    QCOMPARE(baseSignal->name(),QStringLiteral("V2X_DENM"));
    QCOMPARE(rule->components().size(),1);
    model::diagnosis::DiagComponentItem* comp = rule->components().at(0);
    QVERIFY(comp);
    QCOMPARE(comp->name(),QStringLiteral("RSU_456"));
    model::diagnosis::DiagComponentItem* baseComp = comp->baseComponent();
    QVERIFY(baseComp);
    QCOMPARE(baseComp->name(),QStringLiteral("RoadSideUnit"));
    QCOMPARE(baseComp->condition(),QStringLiteral("CAM.mobile == false and CAM.private == false"));
    //QEXPECT_FAIL("correct","Dont understand why 3 not 2!",Abort);
    QCOMPARE(rule->sequenceItems().size(),2);
    model::msc::MscLoopFragmentItem* loop = dynamic_cast<model::msc::MscLoopFragmentItem*>((model::msc::MscSequenceItem*)rule->sequenceItems().at(0));
    QCOMPARE(loop->Condition(),QStringLiteral("3"));
    QCOMPARE(loop->regions().at(0)->sequenceItems().size(),3);
    model::msc::MscCheckMessageItem* check1 = dynamic_cast<model::msc::MscCheckMessageItem*>((model::msc::MscSequenceItem*)loop->regions().at(0)->sequenceItems().at(0));
    QCOMPARE(check1->guard(),QStringLiteral("from == rsu1 and to == stations.car1"));
    QVERIFY(check1->signal());
    QCOMPARE(check1->signal()->name(),QStringLiteral("CyclistWarning"));
    QVERIFY(check1->sourcePort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check1->sourcePort()->owner())->name(),QStringLiteral("RSU_123"));
    QVERIFY(check1->targetPort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check1->targetPort()->owner())->name(),QStringLiteral("car1"));
    model::msc::MscCheckMessageItem* check2 = dynamic_cast<model::msc::MscCheckMessageItem*>((model::msc::MscSequenceItem*)loop->regions().at(0)->sequenceItems().at(1));
    QCOMPARE(check2->guard(),QStringLiteral("from == rsu1 and to == Any"));
    QVERIFY(check2->signal());
    QCOMPARE(check2->signal()->name(),QStringLiteral("CyclistWarning"));
    QVERIFY(check2->sourcePort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check2->sourcePort()->owner())->name(),QStringLiteral("RSU_123"));
    QVERIFY(check2->targetPort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check2->targetPort()->owner())->name(),QStringLiteral("Any"));
    model::msc::MscFragmentItem* parallel = dynamic_cast<model::msc::MscFragmentItem*>((model::msc::MscSequenceItem*)loop->regions().at(0)->sequenceItems().at(2));
    QCOMPARE(parallel->fragmentType(),model::msc::ParallelFragment);
    QCOMPARE(parallel->regions().size(),2);

    model::msc::MscFragmentRegionItem* reg1 = parallel->regions().at(0);
    QCOMPARE(reg1->sequenceItems().size(),1);
    model::msc::MscCheckMessageItem* check3 = dynamic_cast<model::msc::MscCheckMessageItem*>((model::msc::MscSequenceItem*)reg1->sequenceItems().at(0));
    QCOMPARE(check3->guard(),QStringLiteral("from == rsu2 and to == stations.car1"));
    QVERIFY(check3->sourcePort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check3->sourcePort()->owner())->name(),QStringLiteral("RSU_456"));
    QVERIFY(check3->targetPort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check3->targetPort()->owner())->name(),QStringLiteral("car1"));
    QVERIFY(check3->signal());
    QCOMPARE(check3->signal()->name(),QStringLiteral("CyclistWarning"));

    model::msc::MscFragmentRegionItem* reg2 = parallel->regions().at(1);
    QCOMPARE(reg2->sequenceItems().size(),1);
    model::msc::MscCheckMessageItem* check4 = dynamic_cast<model::msc::MscCheckMessageItem*>((model::msc::MscSequenceItem*)reg2->sequenceItems().at(0));
    QCOMPARE(check4->guard(),QStringLiteral("from == rsu2 and to == Any"));
    QVERIFY(check4->signal());
    QVERIFY(check4->sourcePort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check4->sourcePort()->owner())->name(),QStringLiteral("RSU_456"));
    QVERIFY(check4->targetPort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check4->targetPort()->owner())->name(),QStringLiteral("Any"));
    QVERIFY(check4->signal());
    QCOMPARE(check4->signal()->name(),QStringLiteral("CyclistWarning"));

    model::msc::MscCheckMessageItem* check5 = dynamic_cast<model::msc::MscCheckMessageItem*>((model::msc::MscSequenceItem*)rule->sequenceItems().at(1));
    QCOMPARE(check5->guard(),QStringLiteral("from == rsu1 and to == Any and canceled == true"));
    QVERIFY(check5->signal());
    QVERIFY(check5->sourcePort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check5->sourcePort()->owner())->name(),QStringLiteral("RSU_123"));
    QVERIFY(check5->targetPort()->owner());
    QCOMPARE(((model::msc::MscComponentItem*)check5->targetPort()->owner())->name(),QStringLiteral("Any"));
    QCOMPARE(check5->signal()->name(),QStringLiteral("CyclistWarning"));

    /*
  QCOMPARE(42, command.keywordTextLocations().size());

  QCOMPARE(command.keywordTextLocations().at(0).start(), 0); //import
  QCOMPARE(command.keywordTextLocations().at(0).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(1).start(), 34); //import
  QCOMPARE(command.keywordTextLocations().at(1).length(), 6);

  QCOMPARE(command.keywordTextLocations().at(41).start(), 78); //Diagnosis
  QCOMPARE(command.keywordTextLocations().at(41).length(), 8);
  QCOMPARE(command.keywordTextLocations().at(40).start(), 90); //Declaration
  QCOMPARE(command.keywordTextLocations().at(40).length(), 11);
  QCOMPARE(command.keywordTextLocations().at(2).start(), 108); //name
  QCOMPARE(command.keywordTextLocations().at(2).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(3).start(), 134); //enabled
  QCOMPARE(command.keywordTextLocations().at(3).length(), 7);
  QCOMPARE(command.keywordTextLocations().at(4).start(), 160); //Component
  QCOMPARE(command.keywordTextLocations().at(4).length(), 9);
  QCOMPARE(command.keywordTextLocations().at(5).start(), 217); //Attribute
  QCOMPARE(command.keywordTextLocations().at(5).length(), 9);
  QCOMPARE(command.keywordTextLocations().at(6).start(), 227); //int
  QCOMPARE(command.keywordTextLocations().at(6).length(), 3);
  QCOMPARE(command.keywordTextLocations().at(7).start(), 256); //Attribute
  QCOMPARE(command.keywordTextLocations().at(7).length(), 9);
  QCOMPARE(command.keywordTextLocations().at(8).start(), 266); //real
  QCOMPARE(command.keywordTextLocations().at(8).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(9).start(), 300); //Attribute
  QCOMPARE(command.keywordTextLocations().at(9).length(), 9);
  QCOMPARE(command.keywordTextLocations().at(10).start(), 310); //bool
  QCOMPARE(command.keywordTextLocations().at(10).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(11).start(), 344); //Attribute
  QCOMPARE(command.keywordTextLocations().at(11).length(), 9);
  QCOMPARE(command.keywordTextLocations().at(12).start(), 354); //string
  QCOMPARE(command.keywordTextLocations().at(12).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(13).start(), 383); //Signal
  QCOMPARE(command.keywordTextLocations().at(13).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(14).start(), 399); //int
  QCOMPARE(command.keywordTextLocations().at(14).length(), 3);
  QCOMPARE(command.keywordTextLocations().at(15).start(), 406); //int
  QCOMPARE(command.keywordTextLocations().at(15).length(), 3);
  QCOMPARE(command.keywordTextLocations().at(16).start(), 418); //Signal
  QCOMPARE(command.keywordTextLocations().at(16).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(17).start(), 435); //string
  QCOMPARE(command.keywordTextLocations().at(17).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(18).start(), 454); //Signal
  QCOMPARE(command.keywordTextLocations().at(18).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(19).start(), 471); //bool
  QCOMPARE(command.keywordTextLocations().at(19).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(20).start(), 481); //int
  QCOMPARE(command.keywordTextLocations().at(20).length(), 3);

  QCOMPARE(command.keywordTextLocations().at(21).start(), 506); //Timer
  QCOMPARE(command.keywordTextLocations().at(21).length(), 5);
  QCOMPARE(command.keywordTextLocations().at(25).start(), 583); //Message
  QCOMPARE(command.keywordTextLocations().at(25).length(), 7);
  QCOMPARE(command.keywordTextLocations().at(22).start(), 596); //from
  QCOMPARE(command.keywordTextLocations().at(22).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(23).start(), 637); //to
  QCOMPARE(command.keywordTextLocations().at(23).length(), 2);
  QCOMPARE(command.keywordTextLocations().at(24).start(), 670); //data
  QCOMPARE(command.keywordTextLocations().at(24).length(), 4);

  QCOMPARE(command.keywordTextLocations().at(30).start(), 706); //Check
  QCOMPARE(command.keywordTextLocations().at(30).length(), 5);
  QCOMPARE(command.keywordTextLocations().at(26).start(), 717); //from
  QCOMPARE(command.keywordTextLocations().at(26).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(27).start(), 752); //to
  QCOMPARE(command.keywordTextLocations().at(27).length(), 2);
  QCOMPARE(command.keywordTextLocations().at(28).start(), 772); //result
  QCOMPARE(command.keywordTextLocations().at(28).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(29).start(), 978); //timeout
  QCOMPARE(command.keywordTextLocations().at(29).length(), 7);

  QCOMPARE(command.keywordTextLocations().at(39).start(), 1011); //Alt
  QCOMPARE(command.keywordTextLocations().at(39).length(), 3);
  QCOMPARE(command.keywordTextLocations().at(34).start(), 1053); //Check
  QCOMPARE(command.keywordTextLocations().at(34).length(), 5);
  QCOMPARE(command.keywordTextLocations().at(31).start(), 1068); //from
  QCOMPARE(command.keywordTextLocations().at(31).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(32).start(), 1107); //to
  QCOMPARE(command.keywordTextLocations().at(32).length(), 2);
  QCOMPARE(command.keywordTextLocations().at(33).start(), 1152); //result
  QCOMPARE(command.keywordTextLocations().at(33).length(), 6);
  QCOMPARE(command.keywordTextLocations().at(38).start(), 1426); //Check
  QCOMPARE(command.keywordTextLocations().at(38).length(), 5);
  QCOMPARE(command.keywordTextLocations().at(35).start(), 1441); //from
  QCOMPARE(command.keywordTextLocations().at(35).length(), 4);
  QCOMPARE(command.keywordTextLocations().at(36).start(), 1480); //to
  QCOMPARE(command.keywordTextLocations().at(36).length(), 2);
  QCOMPARE(command.keywordTextLocations().at(37).start(), 1520); //result
  QCOMPARE(command.keywordTextLocations().at(37).length(), 6);

  QCOMPARE(26, command.modelTextLocations().size());

  typedef model::msc::MscTimerItem* TimerItem;
  typedef model::msc::MscSequenceItem* SeqItem;
  typedef model::base::AttributeItem* AttItem;
  typedef model::base::SignalItem* SigItem;
  typedef model::msc::MscMessageItem* MesItem;
  typedef model::msc::MscFragmentItem* AltItem;
  typedef model::msc::MscFragmentRegionItem* RegItem;
  typedef model::msc::MscCheckMessageItem* CheckItem;
  typedef model::msc::MscStatementItem* StateItem;
  typedef model::msc::MscTimeoutItem* T_outItem;
  AttItem attribute_1 = diagnosisModel.attributes().at(0);
  AttItem attribute_2 = diagnosisModel.attributes().at(1);
  AttItem attribute_3 = diagnosisModel.attributes().at(2);
  AttItem attribute_4 = diagnosisModel.attributes().at(3);

  SigItem signal1 = diagnosisModel.getSignals().at(0);
  SigItem signal2 = diagnosisModel.getSignals().at(1);
  SigItem signal3 = diagnosisModel.getSignals().at(2);

//  QVERIFY(dynamic_cast<TimerItem>((SeqItem)diagnosisModel.sequenceItems().at(0)));
//  TimerItem timer1 = dynamic_cast<TimerItem>((SeqItem)diagnosisModel.sequenceItems().at(0));
//  QVERIFY(dynamic_cast<StateItem>((SeqItem)diagnosisModel.sequenceItems().at(1)));
//  StateItem state1 = dynamic_cast<StateItem>((SeqItem)diagnosisModel.sequenceItems().at(1));
//  QVERIFY(dynamic_cast<MesItem>((SeqItem)diagnosisModel.sequenceItems().at(2)));
//  MesItem message1 = dynamic_cast<MesItem>((SeqItem)diagnosisModel.sequenceItems().at(2));
//  QVERIFY(dynamic_cast<CheckItem>((SeqItem)diagnosisModel.sequenceItems().at(3)));
//  CheckItem check1 = dynamic_cast<CheckItem>((SeqItem)diagnosisModel.sequenceItems().at(3));
//  T_outItem tOut1 = check1->timeOut();
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
//  QCOMPARE(check1->timeOut()->timer()->value(),300.0);

//  QVERIFY(dynamic_cast<AltItem>((SeqItem)diagnosisModel.sequenceItems().at(4)));
//  AltItem alt1 = dynamic_cast<AltItem>((SeqItem)diagnosisModel.sequenceItems().at(4));
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



//  dslparser::TokenTextLocation modelTextLocation = command.modelTextLocations().value(diagnosisModel.index());
//  QCOMPARE(0, modelTextLocation.start());
//  QCOMPARE(1678, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Diagnosis, modelTextLocation.tokenType());

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
//  QCOMPARE(506, modelTextLocation.start());
//  QCOMPARE(547, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Timer, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(state1->index());
//  QCOMPARE(551, modelTextLocation.start());
//  QCOMPARE(575, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(message1->index());
//  QCOMPARE(583, modelTextLocation.start());
//  QCOMPARE(699, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Message, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(check1->index());
//  QCOMPARE(706, modelTextLocation.start());
//  QCOMPARE(1004, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Check, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(tOut1->index());
//  QCOMPARE(978, modelTextLocation.start());
//  QCOMPARE(990, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Timeout, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(alt1->index());
//  QCOMPARE(1011, modelTextLocation.start());
//  QCOMPARE(1676, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Alt, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(reg1->index());
//  QCOMPARE(1020, modelTextLocation.start());
//  QCOMPARE(1410, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Region, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(check2->index());
//  QCOMPARE(1053, modelTextLocation.start());
//  QCOMPARE(1371, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Check, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(state2->index());
//  QCOMPARE(1380, modelTextLocation.start());
//  QCOMPARE(1403, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(reg2->index());
//  QCOMPARE(1416, modelTextLocation.start());
//  QCOMPARE(1604, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Region, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(check3->index());
//  QCOMPARE(1426, modelTextLocation.start());
//  QCOMPARE(1566, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Check, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(state3->index());
//  QCOMPARE(1574, modelTextLocation.start());
//  QCOMPARE(1597, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(reg3->index());
//  QCOMPARE(1610, modelTextLocation.start());
//  QCOMPARE(1672, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Region, modelTextLocation.tokenType());

//  modelTextLocation = command.modelTextLocations().value(state4->index());
//  QCOMPARE(1642, modelTextLocation.start());
//  QCOMPARE(1665, modelTextLocation.end());
//  QCOMPARE((int)dslparser::Statement, modelTextLocation.tokenType());
*/
}

void DiagnosisSyntaxTest::sequentialTest(){
    //Needs only to run once
    /*
    QString praefix = ":/Examples/";
    QString filename = praefix + "example_diagnosis.diagnosis";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        qDebug()<<"file '"<<filename<<"' could not be opended!";
    QString docText(file.readAll());
    file.close();
    for(int i = docText.size();i>=0;i--){
        QString newText = docText;
        newText.chop(i);
        model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
        //QVERIFY(diagnosisModel);
        dslparser::diagnosis::ComBuildDiagnosisModel command(newText, &diagnosisModel,praefix);

        QString errorString;
        command.execute(&errorString);
    }*/
}

/*
void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_1()
{
  QString docText("Diagnosis{ Declaration {name: diagnosis_4; enabled:  false;} Timer@testsystem.car2X defaultTimer = 500;}");
  model::ts::TestSuite testSuiteModel;
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  QCOMPARE(QString("Incorrect Path to Component!"), errorString);
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_2()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_5.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::ts::TestSuite testSuiteModel;
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_3()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_6.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(3, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_4()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_7.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(3, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_5()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_8.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(3, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_6()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_9.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(4, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_7()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_10.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(2, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_8()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_11.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_9()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_12.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(1, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisErrorTest_10()
{
  QString praefix = ":/Examples/";
  QString filename = praefix + "example_diagnosis_13.diagnosis";
  QFile file(filename);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"file '"<<filename<<"' could not be opended!";
  QString docText(file.readAll());
  file.close();
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel,praefix);
  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, false);
  QCOMPARE(5, command.errors().count());
  return;
}

void DiagnosisSyntaxTest::simpleDiagnosisDeclKeywordTest_1()
{
  QString docText("Diagnosis{ Declaration {name: myDiagnosis;}}");
  model::diagnosis::DiagnosisItem diagnosisModel(QString("test"));
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, &diagnosisModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myDiagnosis"), diagnosisModel.name());

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
void DiagnosisSyntaxTest::simpleDiagnosisDeclKeywordTest_2()
{
    /*
  QString docText("Diagnosis{ name: myDiagnosis; \n TestComponent { name: Comp1;  enabled: true; Port p1,p2;} \n TestComponent { name: Comp2;  enabled: true; \n Port p3; Port p4;}}");
  model::ts::TestSuite testSuiteModel;
  QString errorString1;
  model::diagnosis::DiagnosisItem* diagnosisModel(QString("test"),&errorString1);
  //QVERIFY(diagnosisModel);
  dslparser::diagnosis::ComBuildDiagnosisModel command(docText, diagnosisModel);

  QString errorString;
  bool result = command.execute(&errorString);
  QCOMPARE(result, true);
  QCOMPARE(0, command.errors().count());
  QCOMPARE(QString("myDiagnosis"), diagnosisModel.name());

  model::base::ComponentItem* component_1 = diagnosisModel.components().at(1);
  QVERIFY(component_1);
  QCOMPARE(QString("Comp1"), component_1->name());
  QCOMPARE(component_1->ports().size(), 3);//with default port
  model::base::PortItem* port1 = component_1->ports().at(1);
  QCOMPARE(QString("p1"), port1->name());
  model::base::PortItem* port2 = component_1->ports().at(2);
  QCOMPARE(QString("p2"), port2->name());

  model::base::ComponentItem* component_2 = diagnosisModel.components().at(2);
  QVERIFY(component_2);
  QCOMPARE(QString("Comp2"), component_2->name());
  QCOMPARE(component_2->ports().size(), 3);//with default port
  model::base::PortItem* port3 = component_2->ports().at(1);
  QCOMPARE(QString("p3"), port3->name());
  model::base::PortItem* port4 = component_2->ports().at(2);
  QCOMPARE(QString("p4"), port4->name());

  QCOMPARE(11, command.keywordTextLocations().size());
  QCOMPARE(command.keywordTextLocations().at(10).start(), 0); //Diagnosis
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

QTEST_APPLESS_MAIN(DiagnosisSyntaxTest)

#include "tst_diagnosissyntax.moc"
