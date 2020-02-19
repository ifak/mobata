#include "mainwindow.hpp"

using namespace model::msc;

MainWindow::MainWindow(){
    MscModel* msc=new model::msc::MscModel();

    QString errorString;
    model::base::DataTypeItem* enumType=msc->addDataType("MyEnumType",
                                                         QUuid::createUuid(),
                                                         &errorString);
    enumType->setTypeEnum(prop::Enum);
    enumType->addLiteral("lit1");
    enumType->addLiteral("lit2");

    model::base::DataTypeItem* stringType=msc->addDataType("string",
                                                           QUuid::createUuid(),
                                                           &errorString);
    stringType->setTypeEnum(prop::String);

    model::base::SignalItem* signal=msc->addSignal("signal",
                                                   &errorString);
    /*model::base::ParamItem* paramItem=*/signal->addParameter("param", enumType->name(), &errorString);
    signal->addParameter("para", enumType->name(), &errorString);

    MscComponentItem* comp1=msc->addComponent("comp1",
                                              &errorString);
    PortItem* port1=comp1->addPort("port1", &errorString);

    //error
    /*PortItem* wrong_port=*/comp1->addPort("port1", &errorString);


    MscComponentItem* comp2=msc->addComponent("comp2",
                                              &errorString);
    PortItem* port2=comp2->addPort("port2", &errorString);
    PortItem* port4=comp2->addPort("port4", &errorString);

    MscComponentItem* comp3=msc->addComponent("comp3",
                                              &errorString);
    PortItem* port3=comp3->addPort("port3", &errorString);

    MscSequence* sequ1=msc->addSequence("sequ1");

    ///only text-message
    MscMessageItem* message=sequ1->addMessage(port1, port2, "signal_in(x=0)");

    ///long message
    message=sequ1->addMessage(port3,
                              port1,
                              "this is a very, very, very, "
                              "very, very long message");

    ///timer///
    MscTimerItem* timerItem=sequ1->addTimer((MscComponentItem const*) (port1->owner()),
                                            "timer1", &errorString);

    timerItem->setValue(5.4);

    ///statement///
    /*MscStatementItem* statementItem=*/sequ1->addStatement((MscComponentItem const*)(port2->owner()),
                                                            "this.attribute=false;\n"
                                                            "this.state=Connected;");

    ///sleeping timer///
    /*MscSleepTimerItem* sleepTimerItem=*/sequ1->addSleepTimer((MscComponentItem const*)(port2->owner()),
                                                               2.3);

    ///timeout///
    /*MscTimeoutItem* timeoutItem=*/sequ1->addTimeout((MscComponentItem const*)(port1->owner()),
                                                      timerItem);

    ///typed message
    message=sequ1->addMessage(port4, port3);
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit1");

    MscSequence* sequ2=msc->addSequence("sequ2");
    message=sequ2->addMessage(port2, port1, "signal_out(y=25)");
    /*bool checkmessage = */sequ2->addCheck(port2, port1,"Checkmessage");
    this->_uuid1 = port1->uuid();
    this->_uuid2 = port2->uuid();
    this->_uuid3 = comp1->uuid();

    timerItem=sequ2->addTimer((MscComponentItem const*)(port1->owner()),
                              "timer1", &errorString);
    timerItem->setValue(5.4);

    MscFragmentItem* altFragment=sequ2->addFragment(AlternativeFragment);
    MscFragmentRegionItem* cond1Region=altFragment->addRegion("condition 1");
    message=cond1Region->addMessage(port1, port2);
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit2");

    /*statementItem=*/cond1Region->addStatement((MscComponentItem const*)(port1->owner()),
                                                "this.attribute=false;\n"
                                                "this.state=Connected;");

    MscFragmentRegionItem* cond2Region=altFragment->addRegion("condition 2");

    /*timeoutItem=*/cond2Region->addTimeout((MscComponentItem const*)(port1->owner()),
                                            timerItem);

    message=cond2Region->addMessage(port2, port1);
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit1");
    message->addParamValue(signal->parameter("para"), "lit3");

    message=sequ2->addMessage(port1, port2, "signal_end(here are the params ...\nparam1 ... \nparam2 ... \nparam3 ...)");

    MscSequence* sequ3=msc->addSequence("sequ3");
    message=sequ3->addMessage(port2, port1, "signal_out(y=25)");

    altFragment=sequ3->addFragment(AlternativeFragment);
    cond1Region=altFragment->addRegion("condition 1");
    message=cond1Region->addMessage(port1, port2, "message()");
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit2");

    cond2Region=altFragment->addRegion("condition 2");
    message=cond2Region->addMessage(port2, port1, "message()");
    message->setSignal(signal);
    message->addParamValue(signal->parameter("param"), "lit1");

    MscFragmentItem* loopFragment=cond2Region->addFragment(LoopFragment);
    MscFragmentRegionItem* loopRegion=loopFragment->addRegion();
    message=loopRegion->addMessage(port1, port2, "loop message");

    MscFragmentItem* loop2Fragment=loopRegion->addFragment(LoopFragment);
    MscFragmentRegionItem* loop2Region=loop2Fragment->addRegion("loop statement");
    /*statementItem=*/loop2Region->addStatement((MscComponentItem const*)(port1->owner()),
                                                "this.attribute=false;\n"
                                                "this.state=Connected;");
    message=loop2Region->addMessage(port2, port1, "inner loop message");

    message=sequ3->addMessage(port1, port2, "signal_end(here are the params... param1 ... param2 ... param3 ...)");

    QString error = "";

    QWidget* contr = new QWidget();
    QPushButton* button1 = new QPushButton(contr);
    button1->setText("In");
    button1->move(QPoint(10,10));
    button1->show();
    QPushButton* button2 = new QPushButton(contr);
    button2->setText("Out");
    button2->move(QPoint(10,30));
    button2->show();
    QPushButton* button3 = new QPushButton(contr);
    button3->setText("Fit");
    button3->move(QPoint(10,50));
    button3->show();
    QPushButton* button4 = new QPushButton(contr);
    button4->setText("FitH");
    button4->move(QPoint(10,70));
    button4->show();
    QPushButton* button5 = new QPushButton(contr);
    button5->setText("FitW");
    button5->move(QPoint(10,90));
    button5->show();

    QPushButton* button6 = new QPushButton(contr);
    button6->setText("VD+");
    button6->move(QPoint(10,110));
    button6->show();
    QPushButton* button7 = new QPushButton(contr);
    button7->setText("VD-");
    button7->move(QPoint(10,130));
    button7->show();

    QPushButton* button8 = new QPushButton(contr);
    button8->setText("HD+");
    button8->move(QPoint(10,150));
    button8->show();
    QPushButton* button9 = new QPushButton(contr);
    button9->setText("HD-");
    button9->move(QPoint(10,170));
    button9->show();

    contr->resize(QSize(200,200));
    contr->show();
  /*
    graphlayout::MscQuickWidget* widget0 = new graphlayout::MscQuickWidget(msc->sequences()[0]);
    widget0->resize(QSize(500,500));
    widget0->show();
    widget0->layout(&error);
  */
    this->_widget = new graphlayout::MscQuickWidget(msc->sequences()[0]);
    this->_widget->resize(QSize(500,500));
    this->_widget->show();
    this->_widget->layout(&error);
    QObject::connect(button1, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomIn);
    QObject::connect(button2, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomOut);
    QObject::connect(button3, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomFitAll);
    QObject::connect(button4, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomFitHeight);
    QObject::connect(button5, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomFitWidth);
    QObject::connect(button6, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomYIn);
    QObject::connect(button7, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomYOut);
    QObject::connect(button8, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomXIn);
    QObject::connect(button9, &QPushButton::clicked, this->_widget,&graphlayout::MscQuickWidget::zoomXOut);

//    this->_timer = new QTimer(nullptr);
//    this->_timer->setInterval(2000);
//    QObject::connect(this->_timer, &QTimer::timeout, this, &MainWindow::refreshView);
//    this->_timer->start();


  /*
    graphlayout::MscQuickWidget* widget2 = new graphlayout::MscQuickWidget(msc->sequences()[2]);
    widget2->resize(QSize(500,500));
    widget2->show();
    widget2->layout(&error);
    */
}

void MainWindow::refreshView(){
    if(this->_widget){
        QString errorString;
        this->_counter++;
//        this->_widget->layout(&errorString);

        if(this->_counter%4==0){
            this->_widget->addStatement(this->_uuid3,QString::number(this->_counter),&errorString);
        }else{
            this->_widget->addMessage(this->_uuid1,this->_uuid2,QString::number(this->_counter),&errorString);
        }
    }
}
