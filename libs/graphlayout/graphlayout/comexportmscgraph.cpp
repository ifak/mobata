#include "comexportmscgraph.hpp"

using namespace graphlayout;

class ComExportMscGraph::Private{
    friend class ComExportMscGraph;
    //! Generate Settings
    const model::msc::MscSequence* _mscSequence = nullptr;
    QString* _graphString = nullptr;
    QSettings* _settings = nullptr;
    //! Lists
    QList<const model::base::ModelItem*> _compList;
    QList<const model::base::PortItem*> _portList;
    //! Design Settings
    //! Component
    QColor _componentColor = QColor("white");
    QColor _componentTextColor = QColor("black");
    //! Statement
    QColor _statementColor = QColor("white");
    QColor _statementTextColor = QColor("black");
    //! Timer
    QColor _timerColor = QColor("white");
    QColor _timerTextColor = QColor("black");
    //! Timeout
    QColor _timeoutColor = QColor("white");
    QColor _timeoutTextColor = QColor("black");
    //! Sleeptimer
    QColor _sleeptimerColor = QColor("white");
    QColor _sleeptimerTextColor = QColor("black");
    //! Message
    QColor _messageColor = QColor("black");
    QColor _messageTextColor = QColor("black");
    //! Message
    QColor _checkmessageColor = QColor("black");
    QColor _checkmessageTextColor = QColor("black");
    //! Fragment
    QColor _fragmentColor = QColor("black");
    QColor _fragmentTextColor = QColor("black");
    //! Region
    QColor _regionColor = QColor("black");
    QColor _regionTextColor = QColor("black");
    //! Lifeline
    QColor _lifelineColor = QColor("black");
    //! Background
    QColor _backgroundColor = QColor("white");

    Private()
    {}
};

ComExportMscGraph::ComExportMscGraph(const model::msc::MscSequence *mscSequence,
                                     QString *graphString)
    :_d(new Private)
{
    this->_d->_mscSequence = mscSequence;
    this->_d->_graphString = graphString;
}
ComExportMscGraph::~ComExportMscGraph(){
    delete this->_d;
}
bool ComExportMscGraph::execute(QString* errorString){
    if (this->_d->_mscSequence == nullptr){
        utils::AddPtrString(errorString)<<"MscSequence not set";
        return false;
    }
    if (this->_d->_graphString == nullptr){
        utils::AddPtrString(errorString)<<"GraphString not set";
        return false;
    }
    this->loadSettings();
    this->countComponents(nullptr);
    utils::AddPtrString(this->_d->_graphString)<<"@startuml\n";
    utils::AddPtrString(this->_d->_graphString)<<"hide footbox\n";
    utils::AddPtrString(this->_d->_graphString)<<"skinparam backgroundColor " <<
                                                 this->colorToHtml(this->_d->_backgroundColor) <<
                                                 "\n";

    utils::AddPtrString(this->_d->_graphString)<<"skinparam sequence {\n";

    utils::AddPtrString(this->_d->_graphString)<<"LifeLineBorderColor " <<
                                                 this->colorToHtml(this->_d->_lifelineColor) <<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"LifeLineBorderThickness " <<
                                                 "3" <<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"MessageAlign center\n";
    utils::AddPtrString(this->_d->_graphString)<<"NodeBorderColor "<<
                                                 this->colorToHtml(QColor("black"))<<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"ParticipantBorderColor "<<
                                                 this->colorToHtml(QColor("black"))<<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"ParticipantBackgroundColor "<<
                                                 this->colorToHtml(this->_d->_componentColor)<<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"ParticipantFontColor "<<
                                                 this->colorToHtml(this->_d->_componentTextColor)<<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"GroupBorderColor "<<
                                                 this->colorToHtml(this->_d->_fragmentColor)<<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"GroupFontColor "<<
                                                 this->colorToHtml(this->_d->_regionTextColor)<<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"GroupHeaderFontColor "<<
                                                 this->colorToHtml(this->_d->_fragmentTextColor)<<
                                                 "\n";
    utils::AddPtrString(this->_d->_graphString)<<"}\n";

    for(const model::base::ModelItem* component : this->_d->_compList){
      utils::AddPtrString(this->_d->_graphString)<<"participant " << component->toString() <<
                                                   " order " << this->_d->_compList.indexOf(component) << "\n";
    }

    for(const model::msc::MscSequenceItem* seqItem: this->_d->_mscSequence->sequenceItems()){
        bool result = this->addItem(seqItem,errorString);
        if(!result)
            return false;
    }
    utils::AddPtrString(this->_d->_graphString)<<"@enduml";
    return true;
}

void ComExportMscGraph::useSettings(QSettings* settings ){
    this->_d->_settings = settings;
}

bool ComExportMscGraph::addItem(const model::msc::MscSequenceItem *seqItem, QString* errorString){

    if(seqItem==nullptr){
        utils::AddPtrString(errorString)<<"SeqItem not found";
        return false;
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // StatementStep
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::StatementStep){
        const model::msc::MscStatementItem* statementItem = dynamic_cast<const model::msc::MscStatementItem*>(seqItem);
        QString colorString = "";
        colorString = colorString + "#" +
                QString("%1").arg(this->_d->_statementColor.red(), 2, 16, QLatin1Char('0')) +
                QString("%1").arg(this->_d->_statementColor.green(), 2, 16, QLatin1Char('0')) +
                QString("%1").arg(this->_d->_statementColor.blue(), 2, 16, QLatin1Char('0'));
        QString position = "";
        for(const model::base::PortItem* ports : this->_d->_portList){
            if(statementItem->component()->ports().contains(ports)){
                if(position != ""){
                    position = position + ",";
                }
                position = position + "\"" + statementItem->component()->name() + "\\n" + ports->name() + "\"";
            }
        }
        QString statementString = "rnote over " + position + " " +
                this->colorToHtml(this->_d->_statementColor) + "\n" +
                this->colorToHtml2(this->_d->_statementTextColor) +
                statementItem->toString().replace("\n","\\n" + this->colorToHtml2(this->_d->_statementTextColor)) +
                "\n" + "end rnote\n";
        utils::AddPtrString(this->_d->_graphString)<<statementString;
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // TimerStep
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::TimerStep){
        const model::msc::MscTimerItem* timerItem = dynamic_cast<const model::msc::MscTimerItem*>(seqItem);
        QString statementString = "rnote over " + timerItem->component()->name() + " " +
                this->colorToHtml(this->_d->_timerColor) + "\n" +
                this->colorToHtml2(this->_d->_timerTextColor) +
                timerItem->toString().replace("\n","\\n" + this->colorToHtml2(this->_d->_timerTextColor)) +
                "\n" + "end rnote\n";
        utils::AddPtrString(this->_d->_graphString)<<statementString;
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // TimeoutStep
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::TimeoutStep){
        const model::msc::MscTimeoutItem* timeoutItem = dynamic_cast<const model::msc::MscTimeoutItem*>(seqItem);
        QString statementString = "rnote over " + timeoutItem->component()->name() + " " +
                this->colorToHtml(this->_d->_timeoutColor) + "\n" +
                this->colorToHtml2(this->_d->_timeoutTextColor) +
                timeoutItem->toString().replace("\n","\\n" + this->colorToHtml2(this->_d->_timeoutTextColor)) +
                "\n" + "end rnote\n";
        utils::AddPtrString(this->_d->_graphString)<<statementString;
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // SleepTimer
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::SleepTimerStep){
        const model::msc::MscSleepTimerItem* sleeptimerItem = dynamic_cast<const model::msc::MscSleepTimerItem*>(seqItem);
        QString statementString = "rnote over " + sleeptimerItem->component()->name() + " " +
                this->colorToHtml(this->_d->_sleeptimerColor) + "\n" +
                this->colorToHtml2(this->_d->_sleeptimerTextColor) +
                sleeptimerItem->toString().replace("\n","\\n" + this->colorToHtml2(this->_d->_sleeptimerTextColor)) +
                "\n" + "end rnote\n";
        utils::AddPtrString(this->_d->_graphString)<<statementString;
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Message
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::MessageStep){
        const model::msc::MscMessageItem* messageItem = dynamic_cast<const model::msc::MscMessageItem*>(seqItem);
        bool leftToRight = true;
        if(this->_d->_compList.indexOf(messageItem->sourcePort()->owner()) <=
           this->_d->_compList.indexOf(messageItem->targetPort()->owner())){
          leftToRight = true;
        }else{
          leftToRight = false;
        }

        QString statementString = "\"" + messageItem->sourcePort()->owner()->toString() + "\"" +
                " -[" + this->colorToHtml(this->_d->_messageColor) + "]-> " +
                "\"" + messageItem->targetPort()->owner()->toString() + "\"" + ":" +
                this->colorToHtml2(this->_d->_messageTextColor) +
                messageItem->toString().replace("\n","\\n" + this->colorToHtml2(this->_d->_messageTextColor)) + "\n";
        utils::AddPtrString(this->_d->_graphString)<<statementString;
        if(leftToRight == true){
          utils::AddPtrString(this->_d->_graphString)<<"note left: @" << messageItem->sourcePort()->name() << "\n";
          utils::AddPtrString(this->_d->_graphString)<<"note right: @" << messageItem->targetPort()->name() << "\n";
        }else{
          utils::AddPtrString(this->_d->_graphString)<<"note right: @" << messageItem->sourcePort()->name() << "\n";
          utils::AddPtrString(this->_d->_graphString)<<"note left: @" << messageItem->targetPort()->name() << "\n";
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // CheckMessage
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::CheckMessageStep){
        const model::msc::MscCheckMessageItem* checkmessageItem = dynamic_cast<const model::msc::MscCheckMessageItem*>(seqItem);
        bool leftToRight = true;
        if(this->_d->_compList.indexOf(checkmessageItem->sourcePort()->owner()) <=
           this->_d->_compList.indexOf(checkmessageItem->targetPort()->owner())){
          leftToRight = true;
        }else{
          leftToRight = false;
        }
        QString statementString = "\"" + checkmessageItem->sourcePort()->owner()->toString() + "\"" +
                " -[" + this->colorToHtml(this->_d->_checkmessageColor) + "]-> " +
                "\"" + checkmessageItem->targetPort()->owner()->toString() + "\"" + ":" +
                this->colorToHtml2(this->_d->_checkmessageTextColor) +
                checkmessageItem->toString().replace("\n","\\n" + this->colorToHtml2(this->_d->_checkmessageTextColor)) + "\n";
        utils::AddPtrString(this->_d->_graphString)<<statementString;
        if(leftToRight == true){
          utils::AddPtrString(this->_d->_graphString)<<"note left: @"
                                                    << checkmessageItem->sourcePort()->name()
                                                    << "\n";
          utils::AddPtrString(this->_d->_graphString)<<"note right: @"
                                                    << checkmessageItem->targetPort()->name()
                                                    << "\n";
        }else{
          utils::AddPtrString(this->_d->_graphString)<<"note right: @"
                                                    << checkmessageItem->sourcePort()->name()
                                                    << "\n";
          utils::AddPtrString(this->_d->_graphString)<<"note left: @" << checkmessageItem->targetPort()->name() << "\n";
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Fragment
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::FragmentStep){
        const model::msc::MscFragmentItem* fragmentItem = dynamic_cast<const model::msc::MscFragmentItem*>(seqItem);
        QString FragmentLabel = "";
        if(fragmentItem->fragmentType()==model::msc::FragmentType::AlternativeFragment){
            FragmentLabel = "alt";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::ParallelFragment){
            FragmentLabel = "par";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::SequenceFragment){
            FragmentLabel = "seq";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::OptionalFragment){
            FragmentLabel = "opt";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::LoopFragment){
            FragmentLabel = "loop";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::IgnoreFragment){
            FragmentLabel = "ign";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::ConsiderFragment){
            FragmentLabel = "con";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::AssertFragment){
            FragmentLabel = "ass";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::UserFragmentType){
            FragmentLabel = "user";
        }else if(fragmentItem->fragmentType()==model::msc::FragmentType::DurationFragment){
            FragmentLabel = "dur";
        }else{
            FragmentLabel = "!UNKNOWN!";
        }

        QString statementString = "";
        statementString = statementString + "group " + FragmentLabel;
        utils::AddPtrString(this->_d->_graphString)<<statementString;

        for(const model::msc::MscFragmentRegionItem* region: fragmentItem->regions()){
            QString statementString = "";
            if(region == fragmentItem->regions().first() && fragmentItem->fragmentType()==model::msc::FragmentType::DurationFragment){

                uint duration = fragmentItem->duration();

                statementString = statementString + "[" + QString::number(duration) + " ms]" + "\n";
            }else if(region == fragmentItem->regions().first()){
                if(region->name() != ""){
                    statementString = statementString + "[" + region->name() + "]" + "\n";
                }else{
                    statementString = statementString + "\n";
                }
            }else{
                statementString = statementString + "else " + region->name() + "\n";
            }
            utils::AddPtrString(this->_d->_graphString)<<statementString;
            for(const model::msc::MscSequenceItem* item: region->sequenceItems()){
                bool result = addItem(item,errorString);
                if(!result)
                    return false;
            }
        }
        utils::AddPtrString(this->_d->_graphString)<<"end\n";
    }
    return true;
}

void ComExportMscGraph::countComponents(const model::msc::MscSequenceItem* seq){
    if(seq == nullptr){
        for(const model::base::ModelItem* compItem : this->_d->_mscSequence->componentItems()){
            if(compItem){
                if(this->_d->_compList.contains(compItem)==false){
                    this->_d->_compList.append(compItem);
                }
            }
        }
        for(const model::msc::MscSequenceItem* seqItem : this->_d->_mscSequence->sequenceItems()){
            countComponents(seqItem);
        }
    }else{
        if(seq->stepType() == model::msc::MessageStep){
            const model::msc::MscMessageItem* MessageItem = dynamic_cast<const model::msc::MscMessageItem*>(seq);
            if(MessageItem){
                if(MessageItem->sourcePort()){
                    if(MessageItem->sourcePort()->owner()){
                        if(this->_d->_compList.contains(MessageItem->sourcePort()->owner())==false){
                            this->_d->_compList.append(MessageItem->sourcePort()->owner());
                        }
                        if(this->_d->_portList.contains(MessageItem->sourcePort())==false){
                            this->_d->_portList.append(MessageItem->sourcePort());
                        }
                    }
                }
                if(MessageItem->targetPort()){
                    if(MessageItem->targetPort()->owner()){
                        if(this->_d->_compList.contains(MessageItem->targetPort()->owner())==false){
                            this->_d->_compList.append(MessageItem->targetPort()->owner());
                        }
                        if(this->_d->_portList.contains(MessageItem->targetPort())==false){
                            this->_d->_portList.append(MessageItem->targetPort());
                        }
                    }
                }
            }
        }
        if(seq->stepType() == model::msc::CheckMessageStep){
            const model::msc::MscCheckMessageItem* CheckMessageItem = dynamic_cast<const model::msc::MscCheckMessageItem*>(seq);
            if(CheckMessageItem){
                if(CheckMessageItem->sourcePort()){
                    if(CheckMessageItem->sourcePort()->owner()){
                        if(this->_d->_compList.contains(CheckMessageItem->sourcePort()->owner())==false){
                            this->_d->_compList.append(CheckMessageItem->sourcePort()->owner());
                            this->_d->_portList.append(CheckMessageItem->sourcePort());
                        }
                    }
                }
                if(CheckMessageItem->targetPort()){
                    if(CheckMessageItem->targetPort()->owner()){
                        if(this->_d->_compList.contains(CheckMessageItem->targetPort()->owner())==false){
                            this->_d->_compList.append(CheckMessageItem->targetPort()->owner());
                            this->_d->_portList.append(CheckMessageItem->targetPort());
                        }
                    }
                }
            }
        }
        if(seq->stepType() == model::msc::StatementStep){
            const model::msc::MscStatementItem* StatementItem = dynamic_cast<const model::msc::MscStatementItem*>(seq);
            if(StatementItem){
                if(StatementItem->component()){
                    if(this->_d->_compList.contains(StatementItem->component())==false){
                        this->_d->_compList.append(StatementItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == model::msc::TimeoutStep){
            const model::msc::MscTimeoutItem* TimeoutItem = dynamic_cast<const model::msc::MscTimeoutItem*>(seq);
            if(TimeoutItem){
                if(TimeoutItem->component()){
                    if(this->_d->_compList.contains(TimeoutItem->component())==false){
                        this->_d->_compList.append(TimeoutItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == model::msc::TimerStep){
            const model::msc::MscTimerItem* TimerItem = dynamic_cast<const model::msc::MscTimerItem*>(seq);
            if(TimerItem){
                if(TimerItem->component()){
                    if(this->_d->_compList.contains(TimerItem->component())==false){
                        this->_d->_compList.append(TimerItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == model::msc::SleepTimerStep){
            const model::msc::MscSleepTimerItem* SleepTimerItem = dynamic_cast<const model::msc::MscSleepTimerItem*>(seq);
            if(SleepTimerItem){
                if(SleepTimerItem->component()){
                    if(this->_d->_compList.contains(SleepTimerItem->component())==false){
                        this->_d->_compList.append(SleepTimerItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == model::msc::FragmentStep){
            const model::msc::MscFragmentItem* item = dynamic_cast<const model::msc::MscFragmentItem*>(seq);
            if(item){
                for(const model::msc::MscFragmentRegionItem* region : item->regions()){
                    if(region){
                        for(const model::base::ModelItem* compItem : region->componentItems()){
                            if(compItem){
                                if(this->_d->_compList.contains(compItem)==false){
                                    this->_d->_compList.append(compItem);
                                }
                            }
                        }
                        for(const model::msc::MscSequenceItem* newSeq : region->sequenceItems()){
                            countComponents(newSeq);
                        }
                    }
                }
            }
        }
    }
}


void ComExportMscGraph::loadSettings(){
    if(this->_d->_settings == nullptr){
        return;
    }
    this->_d->_settings->beginGroup(QLatin1String("IrdlEditor"));
    this->_d->_settings->beginGroup(QLatin1String("Background"));
    this->_d->_componentColor       = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("ComponentColor")));
    this->_d->_componentTextColor   = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("ComponentTextcolor")));
    this->_d->_lifelineColor        = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("LifelineColor")));
    this->_d->_backgroundColor      = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("BackgroundColor")));
    this->_d->_settings->endGroup();
    this->_d->_settings->beginGroup(QLatin1String("Steps"));
    this->_d->_statementColor       = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("StatementColor")));
    this->_d->_statementTextColor   = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("StatementTextcolor")));
    this->_d->_timerColor           = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("TimerColor")));
    this->_d->_timerTextColor       = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("TimerTextcolor")));
    this->_d->_timeoutColor         = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("TimeoutColor")));
    this->_d->_timeoutTextColor     = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("TimeoutTextcolor")));
    this->_d->_sleeptimerColor      = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("SleeptimerColor")));
    this->_d->_sleeptimerTextColor  = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("SleeptimerTextcolor")));
    this->_d->_messageColor         = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("MessageColor")));
    this->_d->_messageTextColor     = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("MessageTextcolor")));
    this->_d->_checkmessageColor    = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("CheckmessageColor")));
    this->_d->_checkmessageTextColor= qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("CheckmessageTextcolor")));
    this->_d->_fragmentColor        = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("FragmentColor")));
    this->_d->_fragmentTextColor    = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("FragmentTextcolor")));
    this->_d->_regionColor          = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("RegionColor")));
    this->_d->_regionTextColor      = qvariant_cast<QColor>(this->_d->_settings->value(QLatin1String("RegionTextcolor")));
    this->_d->_settings->endGroup();
    this->_d->_settings->endGroup();
}

QString ComExportMscGraph::colorToHtml(const QColor& color){
    QString colorString = "#" +
            QString("%1").arg(color.red(), 2, 16, QLatin1Char('0')) +
            QString("%1").arg(color.green(), 2, 16, QLatin1Char('0')) +
            QString("%1").arg(color.blue(), 2, 16, QLatin1Char('0'));
    return colorString;
}

QString ComExportMscGraph::colorToHtml2(const QColor& color){
    QString textcolorString = "<font color=" + this->colorToHtml(color) + ">";
    return textcolorString;
}
