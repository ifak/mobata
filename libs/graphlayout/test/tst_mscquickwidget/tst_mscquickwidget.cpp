#include <QtTest>

#include <graphlayout/mscquickwidget.hpp>

#include <mobata/model/msc/msc.hpp>

#include <QQuickItem>

class MscQuickWidgetTest
        : public QObject
{
    Q_OBJECT

public:
    MscQuickWidgetTest();
private:
    model::msc::MscModel* _model;
    void initModel();
private Q_SLOTS:
    void initTestCase();
    void Seq1Test();
    void Seq2Test();
    void Seq3Test();
    void cleanupTestCase();
};

MscQuickWidgetTest::MscQuickWidgetTest()
{}

void MscQuickWidgetTest::initTestCase()
{
  Q_INIT_RESOURCE(graphlayout);
    this->initModel();
}

void MscQuickWidgetTest::initModel(){
    this->_model = new model::msc::MscModel();

    QString errorString;
    model::base::DataTypeItem* enumType=this->_model->addDataType("MyEnumType",
                                                         QUuid::createUuid(),
                                                         &errorString);
    enumType->setTypeEnum(prop::Enum);
    enumType->addLiteral("lit1");
    enumType->addLiteral("lit2");

    model::base::DataTypeItem* stringType=this->_model->addDataType("string",
                                                           QUuid::createUuid(),
                                                           &errorString);
    stringType->setTypeEnum(prop::String);

    model::base::SignalItem* signal=this->_model->addSignal("signal",
                                                   &errorString);
    /*model::base::ParamItem* paramItem=*/signal->addParameter("param", enumType->name(), &errorString);

    model::msc::MscComponentItem* comp1=this->_model->addComponent("comp1",
                                              &errorString);
    model::msc::PortItem* port1=comp1->addPort("port1", &errorString);

    model::msc::MscComponentItem* comp2=this->_model->addComponent("comp2",
                                              &errorString);
    model::msc::PortItem* port2=comp2->addPort("port2", &errorString);
    model::msc::PortItem* port4=comp2->addPort("port4", &errorString);

    model::msc::MscComponentItem* comp3=this->_model->addComponent("comp3",
                                              &errorString);
    model::msc::PortItem* port3=comp3->addPort("port3", &errorString);

    model::msc::MscSequence* sequ1=this->_model->addSequence("sequ1");

    ///only text-message
    model::msc::MscMessageItem* message=sequ1->addMessage(port1, port2, "signal_in(x=0)");

    ///long message
    message=sequ1->addMessage(port3,
                              port1,
                              "this is a very, very, very, "
                              "very, very long message");

    ///timer///
    model::msc::MscTimerItem* timerItem=sequ1->addTimer((model::msc::MscComponentItem const*) (port1->owner()),
                                            "timer1", &errorString);

    timerItem->setValue(5.4);

    ///statement///
    /*MscStatementItem* statementItem=*/sequ1->addStatement((model::msc::MscComponentItem const*)(port2->owner()),
                                                            "this.attribute=false;\n"
                                                            "this.state=Connected;");

    ///sleeping timer///
    /*MscSleepTimerItem* sleepTimerItem=*/sequ1->addSleepTimer((model::msc::MscComponentItem const*)(port2->owner()),
                                                               2.3);

    ///timeout///
    /*MscTimeoutItem* timeoutItem=*/sequ1->addTimeout((model::msc::MscComponentItem const*)(port1->owner()),
                                                      timerItem);

    ///typed message
    message=sequ1->addMessage(port4, port3);
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit1");

    model::msc::MscSequence* sequ2=this->_model->addSequence("sequ2");
    message=sequ2->addMessage(port2, port1, "signal_out(y=25)");

    timerItem=sequ2->addTimer((model::msc::MscComponentItem const*)(port1->owner()),
                              "timer1", &errorString);
    timerItem->setValue(5.4);

    model::msc::MscFragmentItem* altFragment=sequ2->addFragment(model::msc::AlternativeFragment);
    model::msc::MscFragmentRegionItem* cond1Region=altFragment->addRegion("condition 1");
    message=cond1Region->addMessage(port1, port2);
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit2");

    /*statementItem=*/cond1Region->addStatement((model::msc::MscComponentItem const*)(port1->owner()),
                                                "this.attribute=false;\n"
                                                "this.state=Connected;");

    model::msc::MscFragmentRegionItem* cond2Region=altFragment->addRegion("condition 2");

    /*timeoutItem=*/cond2Region->addTimeout((model::msc::MscComponentItem const*)(port1->owner()),
                                            timerItem);

    message=cond2Region->addMessage(port2, port1);
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit1");

    message=sequ2->addMessage(port1, port2, "signal_end(here are the params ...)");

    model::msc::MscSequence* sequ3=this->_model->addSequence("sequ3");
    message=sequ3->addMessage(port2, port1, "signal_out(y=25)");

    altFragment=sequ3->addFragment(model::msc::AlternativeFragment);
    cond1Region=altFragment->addRegion("condition 1");
    message=cond1Region->addMessage(port1, port2, "message()");
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit2");

    cond2Region=altFragment->addRegion("condition 2");
    message=cond2Region->addMessage(port2, port1, "message()");
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit1");

    model::msc::MscFragmentItem* loopFragment=cond2Region->addFragment(model::msc::LoopFragment);
    model::msc::MscFragmentRegionItem* loopRegion=loopFragment->addRegion();
    message=loopRegion->addMessage(port1, port2, "loop message");

    model::msc::MscFragmentItem* loop2Fragment=loopRegion->addFragment(model::msc::LoopFragment);
    model::msc::MscFragmentRegionItem* loop2Region=loop2Fragment->addRegion("loop statement");
    /*statementItem=*/loop2Region->addStatement((model::msc::MscComponentItem const*)(port1->owner()),
                                                "this.attribute=false;\n"
                                                "this.state=Connected;");
    message=loop2Region->addMessage(port2, port1, "inner loop message");

    message=sequ3->addMessage(port1, port2, "signal_end(here are the params ...)");


    QVERIFY(this->_model);
    QCOMPARE(errorString,QString(""));
}

void MscQuickWidgetTest::Seq1Test(){
    graphlayout::MscQuickWidget* mscwidget = new graphlayout::MscQuickWidget(this->_model->sequences()[0]);
    QString errorString;
    mscwidget->layout(&errorString);
    QCOMPARE(errorString,QString(""));
    QVERIFY(mscwidget->rootObject()->findChild<QObject*>("drawArea"));
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__component").length(),7);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_compspacer").length(),9);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__timer").length(),3);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__statement").length(),1);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__arrow").length(),3);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_messagestart").length(),3);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_messageend").length(),3);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_spacer").length(),60);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_lifeline").length(),4);
    delete mscwidget;
}

void MscQuickWidgetTest::Seq2Test(){
    graphlayout::MscQuickWidget* mscwidget = new graphlayout::MscQuickWidget(this->_model->sequences()[1]);
    QString errorString;
    mscwidget->layout(&errorString);
    QCOMPARE(errorString,QString(""));
    QVERIFY(mscwidget->rootObject()->findChild<QObject*>("drawArea"));
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__component").length(),5);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_compspacer").length(),7);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__timer").length(),2);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__statement").length(),1);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__arrow").length(),4);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_messagestart").length(),4);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_messageend").length(),4);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_spacer").length(),66);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_lifeline").length(),3);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_frame").length(),6);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_regionline").length(),3);
    delete mscwidget;
}

void MscQuickWidgetTest::Seq3Test(){
    graphlayout::MscQuickWidget* mscwidget = new graphlayout::MscQuickWidget(this->_model->sequences()[2]);
    QString errorString;
    mscwidget->layout(&errorString);
    QCOMPARE(errorString,QString(""));
    QVERIFY(mscwidget->rootObject()->findChild<QObject*>("drawArea"));
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__component").length(),5);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_compspacer").length(),7);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__timer").length(),0);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__statement").length(),1);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc__arrow").length(),6);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_messagestart").length(),6);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_messageend").length(),6);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_spacer").length(),72);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_lifeline").length(),3);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_frame").length(),10);
    QCOMPARE(mscwidget->rootObject()->findChildren<QObject*>("msc_regionline").length(),5);
    delete mscwidget;
}

void MscQuickWidgetTest::cleanupTestCase(){
    delete this->_model;
}


QTEST_MAIN(MscQuickWidgetTest)

#include "tst_mscquickwidget.moc"
