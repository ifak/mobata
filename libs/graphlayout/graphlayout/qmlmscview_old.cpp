#include <QDebug>
#include "qmlmscview.hpp"
#include <mobata/memory_leak_start.hpp>
inline void initMyResource() { Q_INIT_RESOURCE(graphlayout); }
using namespace graphlayout;
using namespace model::msc;

class QmlMscView:: QmlMscViewVars{
    friend class QmlMscView;
public:
    QmlMscViewVars(){}

    QQuickItem* _rootObject;
    QQmlEngine* _engine;

    MscSequence* _mscSeq;
    QList<const model::base::ModelItem*> _CompList;
    QList<const model::base::PortItem*> _PortList;
    QList<QList<const QUuid*>> _lifeLines;
    int _columnCount;

    //! DesignSettings
    //! Component
    QColor _componentColor = QColor("yellow");
    QColor _componentTextColor = QColor("black");
    int _componentRadius = 10;
    //! Statement
    QColor _statementColor = QColor("blue");
    QColor _statementTextColor = QColor("black");
    int _statementRadius = 10;
    //! Timer
    QColor _timerColor = QColor("red");
    QColor _timerTextColor = QColor("black");
    int _timerRadius = 10;
    //! Message
    QColor _messageColor = QColor("black");
    QColor _messageTextColor = QColor("black");
    //! Lifeline
    QColor _lifelineColor = QColor("black");
};


QmlMscView::QmlMscView(QQuickView *view,
                       model::msc::MscSequence *mscSeq,
                       QObject* parent)
    :QObject(parent), _d(new QmlMscViewVars())
{
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl("qrc:/msc_main.qml"));
    this->_d->_engine=view->engine();
    this->_d->_mscSeq = mscSeq;
    this->_d->_rootObject =view->rootObject();
    initMyResource();
}
QmlMscView::QmlMscView(QQuickWidget *widget,
                       model::msc::MscSequence *mscSeq,
                       QObject* parent)
    :QObject(parent), _d(new QmlMscViewVars())
{
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    widget->setSource(QUrl("qrc:/msc_main.qml"));
    this->_d->_engine=widget->engine();
    this->_d->_mscSeq = mscSeq;
    this->_d->_rootObject =widget->rootObject();
    initMyResource();
}

bool QmlMscView::layout(QString* errorString){
    if(this->_d->_rootObject==nullptr){
        return false;
    }
    QTime myTimer;
    myTimer.start();
    foreach(QQuickItem* item, _d->_rootObject->findChildren<QQuickItem*>(QRegExp("msc*",Qt::CaseSensitive,QRegExp::Wildcard))){
        item->deleteLater();
    }

    countComponents(nullptr);
    createComponentList();
    placeComponents();
    placeSeq();
    addFrames();

    if(*errorString!="")
        qDebug()<<*errorString;
    qDebug()<<"Layout time: " << myTimer.elapsed()<<" ms";
    return true;
}
void QmlMscView::createComponentList(){
    QList<const QUuid*> Row_1;
    QList<const QUuid*> Row_2;
    for(const model::base::ModelItem*  mscComp : this->_d->_CompList){
        bool hasPorts = false;
        for(const model::base::PortItem* mscPort : this->_d->_PortList){
            if(mscPort->owner()->uuid()==mscComp->uuid()){

                hasPorts = true;
            }
        }
        if(hasPorts==false){
            Row_1.append(nullptr);
            Row_2.append(&mscComp->uuid());
        }else{
            for(const model::base::PortItem* mscPort : this->_d->_PortList){
                if(Row_2.contains(&mscPort->uuid())==false && mscPort->owner()->uuid()==mscComp->uuid()){
                    Row_1.append(&mscComp->uuid());
                    Row_2.append(&mscPort->uuid());
                }
            }
        }
    }
    this->_d->_lifeLines.append(Row_1);
    this->_d->_lifeLines.append(Row_2);
}
const QString& QmlMscView::nameFromComponent(const QUuid uuid){
    for(const model::base::ModelItem*  mscComp : this->_d->_CompList){
        if(mscComp->uuid()==uuid){
            return mscComp->toString();
        }
    }
    for(const model::base::PortItem* mscPort : this->_d->_PortList){
        if(mscPort->uuid()==uuid){
            return mscPort->name();
        }
    }
    return nullptr;
}
void QmlMscView::placeComponents(){
    QObject* drawArea = this->_d->_rootObject->findChild<QObject*>("drawArea");
    if(drawArea==nullptr){
        qDebug()<<"drawArea nicht gefunden";
        return;
    }
    QObject* compArea = this->_d->_rootObject->findChild<QObject*>("compArea");
    QObject* lifeLinesArea = this->_d->_rootObject->findChild<QObject*>("lifeLinesArea");
    QList<const QUuid*> row = this->_d->_lifeLines.first();
    int counter=row.length();
    counter = (counter*2)+1;
    this->_d->_columnCount = counter;
    drawArea->setProperty("columns",counter);
    counter = 0;
    const QUuid* lastuuid = &QUuid();
    for(const QUuid* uuid: row){
        if(lastuuid == uuid){
            continue;
        }
        QMetaObject::invokeMethod(drawArea,"createComponentSpacer");
        counter++;
        if(uuid==nullptr){
            QMetaObject::invokeMethod(drawArea,"createComponentSpacer");
            counter++;
        }else{
            int spanCounter = -1;
            for(const QUuid* intuuid: row){
                if(intuuid==uuid){
                    spanCounter=spanCounter+2;
                }
            }
            lastuuid = uuid;
            const QString name = nameFromComponent(*uuid);
            QMetaObject::invokeMethod(drawArea,"createComponent",
                                      Q_ARG(QVariant,name),
                                      Q_ARG(QVariant,*uuid),
                                      Q_ARG(QVariant,spanCounter),
                                      Q_ARG(QVariant,counter),
                                      Q_ARG(QVariant,this->_d->_componentColor),
                                      Q_ARG(QVariant,this->_d->_componentRadius),
                                      Q_ARG(QVariant,this->_d->_componentTextColor));
            counter = counter + spanCounter;
        }
    }
    QMetaObject::invokeMethod(drawArea,"createComponentSpacer");



    row = this->_d->_lifeLines.last();
    counter = 0;
    for(const QUuid* uuid: row){
        QMetaObject::invokeMethod(drawArea,"createComponentSpacer");
        counter++;
        if(uuid==nullptr){
            QMetaObject::invokeMethod(drawArea,"createComponentSpacer");
        }else{
            const QString name = nameFromComponent(*uuid);
            QMetaObject::invokeMethod(drawArea,"createComponent",
                                      Q_ARG(QVariant,name),
                                      Q_ARG(QVariant,*uuid),
                                      Q_ARG(QVariant,1),
                                      Q_ARG(QVariant,counter),
                                      Q_ARG(QVariant,this->_d->_componentColor),
                                      Q_ARG(QVariant,this->_d->_componentRadius),
                                      Q_ARG(QVariant,this->_d->_componentTextColor));
            QQuickItem* source = component(*uuid);
            if(source != nullptr){
                QQmlComponent dyn(_d->_engine,
                                  QUrl("qrc:/msc_lifeline.qml"),
                                  lifeLinesArea);
                QObject *dynObject = dyn.create();
                QQuickItem* item = qobject_cast<QQuickItem*>(dynObject);
                item->setProperty("compUuid",uuid->toString());
                item->setParent(lifeLinesArea);
                item->setProperty("color",this->_d->_lifelineColor);
                item->setParentItem(qobject_cast<QQuickItem*>(lifeLinesArea));
                QObject::connect(source,&QQuickItem::widthChanged,this,&QmlMscView::updateLifeLines);
                QObject::connect(source,&QQuickItem::heightChanged, this,&QmlMscView::updateLifeLines);
            }
        }
        counter++;
    }
    QMetaObject::invokeMethod(drawArea,"createComponentSpacer");

    for(QQuickItem* compItem : drawArea->findChildren<QQuickItem*>("msc_component")){
        QObject::connect(compItem,&QQuickItem::widthChanged,this,&QmlMscView::updateOverlay);
        QObject::connect(compItem,&QQuickItem::heightChanged, this,&QmlMscView::updateOverlay);
    }

}
void QmlMscView::updateLifeLines(){
    QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
    QQuickItem* lifeLinesArea = this->_d->_rootObject->findChild<QQuickItem*>("lifeLinesArea");
    for(QQuickItem* comp: drawArea->findChildren<QQuickItem*>("msc_component")){
        for(QQuickItem* lifeline: lifeLinesArea->findChildren<QQuickItem*>("msc_lifeline")){
            if(comp->property("uuid") == lifeline->property("compUuid")){
                QPointF newPos = comp->mapToItem(lifeLinesArea,QPointF(comp->width()/2,0));
                QMetaObject::invokeMethod(lifeline,"updateX",Q_ARG(QVariant,newPos.x()));
                break;
            }
        }
    }
}
void QmlMscView::updateOverlay(){
    QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
    QQuickItem* compArea = this->_d->_rootObject->findChild<QQuickItem*>("compArea");
    for(QQuickItem* comp: drawArea->findChildren<QQuickItem*>("msc_component")){
        for(QQuickItem* ovComp: compArea->findChildren<QQuickItem*>("msc_component")){
            if(comp->property("uuid") == ovComp->property("uuid")){
                QMetaObject::invokeMethod(compArea,"setSize",Q_ARG(QVariant,comp->property("column")),Q_ARG(QVariant,comp->height()),Q_ARG(QVariant,comp->width()));
                break;
            }
        }
    }
    /*
    for(QQuickItem* comp: drawArea->findChildren<QQuickItem*>("CompSpacer")){
        for(QQuickItem* ovComp: compArea->findChildren<QQuickItem*>("CompSpacer")){
            if(comp->property("uuid") == ovComp->property("uuid")){
                QMetaObject::invokeMethod(compArea,"setSize",Q_ARG(QVariant,comp->property("column")),Q_ARG(QVariant,comp->height()),Q_ARG(QVariant,comp->width()));
                break;
            }
        }
    }
    */
}
void QmlMscView::updateRegionLines(){
    QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
    QQuickItem* lifeLinesArea = this->_d->_rootObject->findChild<QQuickItem*>("lifeLinesArea");
    for(QQuickItem* corner: drawArea->findChildren<QQuickItem*>("msc_frame")){
        bool found = false;
        for(QQuickItem* frame: lifeLinesArea->findChildren<QQuickItem*>("msc_regionline")){
            if(qvariant_cast<QString>(corner->property("uuid"))==qvariant_cast<QString>(frame->property("uuid"))){
                found = true;
                if(qvariant_cast<int>(corner->property("num")) == 1 || qvariant_cast<int>(corner->property("num")) == 3){
                    frame->setProperty("startPos",QPointF(corner->mapToItem(lifeLinesArea,QPointF(corner->width(),0))));
                }else if(qvariant_cast<int>(corner->property("num")) == 2 || qvariant_cast<int>(corner->property("num")) == 4){
                    frame->setProperty("endPos",QPointF(corner->mapToItem(lifeLinesArea,QPointF(0,0))));
                }
                break;
            }
        }
        if(found == false)
            qDebug()<<corner->property("uuid")<<" nicht gefunden";
    }
}
void QmlMscView::addFrames(){
    QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
    QQuickItem* lifeLinesArea = this->_d->_rootObject->findChild<QQuickItem*>("lifeLinesArea");
    int fullwidth=0;
    for(QQuickItem* node: drawArea->findChildren<QQuickItem*>("msc_frame")){
        if(qvariant_cast<bool>(node->property("finished"))==true){
            continue;
        }
        if(qvariant_cast<int>(node->property("num"))==2 || qvariant_cast<int>(node->property("num"))==4){
            qDebug()<<"error to much frames";
            return;
        }
        bool start = false;
        int counter = 0;
        int maxcounter = 1;
        int type = 0;
        if(qvariant_cast<int>(node->property("num")) == 3){
            type = 1;
        }
        QQuickItem* endnode = nullptr;
        for(QQuickItem* end: drawArea->findChildren<QQuickItem*>("msc_frame")){
            if(end == node){
                start = true;
                continue;
            }
            if(start == true){
                if((qvariant_cast<int>(end->property("num"))==2 || qvariant_cast<int>(end->property("num"))==4) && counter == 0){
                    endnode = end;
                    break;
                }else if(qvariant_cast<int>(end->property("num"))==1 || qvariant_cast<int>(end->property("num"))==3){
                    counter++;
                    maxcounter++;
                }else if(qvariant_cast<int>(end->property("num"))==2 || qvariant_cast<int>(end->property("num"))==4){
                    counter--;
                }
            }
        }
        if(endnode==nullptr){
            qDebug()<<"Frameteil fehlt";
            return;
        }
        QPointF startPos = node->mapToItem(lifeLinesArea, QPointF(node->height(),node->height()));
        QPointF endPos = endnode->mapToItem(lifeLinesArea, QPointF(0,0));
        QQmlComponent dyn(_d->_engine,
                          QUrl("qrc:/msc_regionline.qml"),
                          lifeLinesArea);
        QObject *dynObject = dyn.create();
        QQuickItem* item = qobject_cast<QQuickItem*>(dynObject);
        item->setParent(lifeLinesArea);
        item->setParentItem(qobject_cast<QQuickItem*>(lifeLinesArea));
        item->setProperty("startPos",startPos);
        item->setProperty("endPos",endPos);
        item->setProperty("intend",maxcounter*3);
        item->setProperty("uuid",node->property("uuid"));
        item->setProperty("type",type);
        item->setProperty("label",node->property("label"));
        endnode->setProperty("finished",true);
        node->setProperty("finished",true);
        QObject::connect(endnode,&QQuickItem::widthChanged,this,&QmlMscView::updateRegionLines);
        QObject::connect(node,&QQuickItem::widthChanged,this,&QmlMscView::updateRegionLines);
        QObject::connect(endnode,&QQuickItem::heightChanged,this,&QmlMscView::updateRegionLines);
        QObject::connect(node,&QQuickItem::heightChanged,this,&QmlMscView::updateRegionLines);
        if(maxcounter>fullwidth)
            fullwidth=maxcounter;
    }
    QMetaObject::invokeMethod(drawArea,"setMinimumWidth",Q_ARG(QVariant,fullwidth*3+10));
}
void QmlMscView::placeSeq(){
    for(const MscSequenceItem* seqItem: this->_d->_mscSeq->sequenceItems()){
        placeItem(seqItem);
    }
    QObject* drawArea = this->_d->_rootObject->findChild<QObject*>("drawArea");
    if(drawArea==nullptr){
        qDebug()<<"drawArea nicht gefunden";
        return;
    }
    for(int i=0; i<this->_d->_columnCount; i++){
        QMetaObject::invokeMethod(drawArea,"createSpacer");
    }
}
int QmlMscView::columnFromComponent(const QUuid uuid){
    for(QQuickItem* object: this->_d->_rootObject->findChildren<QQuickItem*>("msc_component")){
        if(qvariant_cast<QString>(object->property("uuid"))==uuid.toString()){
            return qvariant_cast<int>(object->property("column"));
        }
    }
    return -1;
}
QQuickItem* QmlMscView::component(const QUuid uuid){
    for(QQuickItem* object: this->_d->_rootObject->findChildren<QQuickItem*>("msc_component")){
        if(qvariant_cast<QString>(object->property("uuid"))==uuid.toString()){
            return object;
        }
    }
    return nullptr;
}
int QmlMscView::spanFromComponent(const QUuid uuid){
    for(QQuickItem* object: this->_d->_rootObject->findChildren<QQuickItem*>("msc_component")){
        if(qvariant_cast<QString>(object->property("uuid"))==uuid.toString()){
            return qvariant_cast<int>(object->property("span"));
        }
    }
    return -1;
}
void QmlMscView::placeItem(const model::msc::MscSequenceItem *seqItem){
    if(seqItem==nullptr){
        qDebug()<<"SeqItem existiert nicht";
        return;
    }
    QObject* drawArea = this->_d->_rootObject->findChild<QObject*>("drawArea");
    if(drawArea==nullptr){
        qDebug()<<"drawArea nicht gefunden";
        return;
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // StatementStep
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==StatementStep){
        const MscStatementItem* statementItem = dynamic_cast<const MscStatementItem*>(seqItem);
        const QUuid statementComp = statementItem->component()->uuid();
        int place = columnFromComponent(statementComp);
        int span = spanFromComponent(statementComp);
        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==place){
                QMetaObject::invokeMethod(drawArea,"createStatement",
                                          Q_ARG(QVariant,statementItem->statement()),
                                          Q_ARG(QVariant,span),
                                          Q_ARG(QVariant,this->_d->_statementColor),
                                          Q_ARG(QVariant,this->_d->_statementRadius),
                                          Q_ARG(QVariant,this->_d->_statementTextColor));
                i = i + span - 1;
            }else{
                QMetaObject::invokeMethod(drawArea,"createSpacer");
            }
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // TimerStep
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==TimerStep){
        const MscTimerItem* timerItem = dynamic_cast<const MscTimerItem*>(seqItem);
        const QUuid timerComp = timerItem->component()->uuid();
        int place = columnFromComponent(timerComp);
        int span = spanFromComponent(timerComp);
        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==place){
                QMetaObject::invokeMethod(drawArea,"createTimer",
                                          Q_ARG(QVariant,timerItem->toString()),
                                          Q_ARG(QVariant,span),
                                          Q_ARG(QVariant,this->_d->_timerColor),
                                          Q_ARG(QVariant,this->_d->_timerRadius),
                                          Q_ARG(QVariant,this->_d->_timerTextColor));
                i = i + span - 1;
            }else{
                QMetaObject::invokeMethod(drawArea,"createSpacer");
            }
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // TimeoutStep
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==TimeoutStep){
        const MscTimeoutItem* timeoutItem = dynamic_cast<const MscTimeoutItem*>(seqItem);
        const QUuid timeoutComp = timeoutItem->component()->uuid();
        int place = columnFromComponent(timeoutComp);
        int span = spanFromComponent(timeoutComp);
        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==place){
                QMetaObject::invokeMethod(drawArea,"createTimer",
                                          Q_ARG(QVariant,timeoutItem->toString()),
                                          Q_ARG(QVariant,span),
                                          Q_ARG(QVariant,this->_d->_timerColor),
                                          Q_ARG(QVariant,this->_d->_timerRadius),
                                          Q_ARG(QVariant,this->_d->_timerTextColor));
                i = i + span - 1;
            }else{
                QMetaObject::invokeMethod(drawArea,"createSpacer");
            }
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // SleepTimer
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==SleepTimerStep){
        const MscSleepTimerItem* sleeptimerItem = dynamic_cast<const MscSleepTimerItem*>(seqItem);
        const QUuid sleeptimerComp = sleeptimerItem->component()->uuid();
        int place = columnFromComponent(sleeptimerComp);
        int span = spanFromComponent(sleeptimerComp);
        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==place){
                QMetaObject::invokeMethod(drawArea,"createTimer",
                                          Q_ARG(QVariant,sleeptimerItem->toString()),
                                          Q_ARG(QVariant,span),
                                          Q_ARG(QVariant,this->_d->_timerColor),
                                          Q_ARG(QVariant,this->_d->_timerRadius),
                                          Q_ARG(QVariant,this->_d->_timerTextColor));
                i = i + span - 1;
            }else{
                QMetaObject::invokeMethod(drawArea,"createSpacer");
            }
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Message
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==MessageStep){
        const MscMessageItem* messageItem = dynamic_cast<const MscMessageItem*>(seqItem);
        const QUuid messageSource = messageItem->sourcePort()->uuid();
        const QUuid messageTarget = messageItem->targetPort()->uuid();
        int sourcePlace = columnFromComponent(messageSource);
        int targetPlace = columnFromComponent(messageTarget);
        int spanCount = 0;
        int rightArrow = 2;
        bool finished = false;
        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==sourcePlace){
                if(rightArrow == 2){
                    rightArrow = 1;
                    QMetaObject::invokeMethod(drawArea,"createMessageStart",Q_ARG(QVariant,rightArrow));
                }else{
                    finished = true;
                    QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_ARG(QVariant,messageItem->text()),
                                              Q_ARG(QVariant,spanCount),
                                              Q_ARG(QVariant,rightArrow),
                                              Q_ARG(QVariant,this->_d->_messageColor),
                                              Q_ARG(QVariant,this->_d->_messageTextColor));
                    QMetaObject::invokeMethod(drawArea,"createMessageStart",Q_ARG(QVariant,rightArrow));
                }
            }else if(i==targetPlace){
                if(rightArrow == 2){
                    rightArrow = 0;
                    QMetaObject::invokeMethod(drawArea,"createMessageEnd",Q_ARG(QVariant,rightArrow));
                }else{
                    finished = true;
                    QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_ARG(QVariant,messageItem->text()),
                                              Q_ARG(QVariant,spanCount),
                                              Q_ARG(QVariant,rightArrow),
                                              Q_ARG(QVariant,this->_d->_messageColor),
                                              Q_ARG(QVariant,this->_d->_messageTextColor));
                    QMetaObject::invokeMethod(drawArea,"createMessageEnd",Q_ARG(QVariant,rightArrow));
                }
            }else{
                if(rightArrow == 2 || finished == true){
                    QMetaObject::invokeMethod(drawArea,"createSpacer");
                }else{
                    spanCount++;
                }
            }
        }
        if(finished==false){
            qDebug()<<"message fehlt";
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // CheckMessage
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==model::msc::CheckMessageStep){
        const model::msc::MscCheckMessageItem* checkmessageItem = dynamic_cast<const model::msc::MscCheckMessageItem*>(seqItem);
        const QUuid checkmessageSource = checkmessageItem->sourcePort()->uuid();
        const QUuid checkmessageTarget = checkmessageItem->targetPort()->uuid();
        int sourcePlace = columnFromComponent(checkmessageSource);
        int targetPlace = columnFromComponent(checkmessageTarget);
        int spanCount = 0;
        int rightArrow = 2;
        bool finished = false;
        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==sourcePlace){
                if(rightArrow == 2){
                    rightArrow = 1;
                    QMetaObject::invokeMethod(drawArea,"createMessageStart",Q_ARG(QVariant,rightArrow));
                }else{
                    finished = true;
                    QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_ARG(QVariant,checkmessageItem->text()),
                                              Q_ARG(QVariant,spanCount),
                                              Q_ARG(QVariant,rightArrow),
                                              Q_ARG(QVariant,this->_d->_messageColor),
                                              Q_ARG(QVariant,this->_d->_messageTextColor));
                    QMetaObject::invokeMethod(drawArea,"createMessageStart",Q_ARG(QVariant,rightArrow));
                }
            }else if(i==targetPlace){
                if(rightArrow == 2){
                    rightArrow = 0;
                    QMetaObject::invokeMethod(drawArea,"createMessageEnd",Q_ARG(QVariant,rightArrow));
                }else{
                    finished = true;
                    QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_ARG(QVariant,checkmessageItem->text()),
                                              Q_ARG(QVariant,spanCount),
                                              Q_ARG(QVariant,rightArrow),
                                              Q_ARG(QVariant,this->_d->_messageColor),
                                              Q_ARG(QVariant,this->_d->_messageTextColor));
                    QMetaObject::invokeMethod(drawArea,"createMessageEnd",Q_ARG(QVariant,rightArrow));
                }
            }else{
                if(rightArrow == 2 || finished == true){
                    QMetaObject::invokeMethod(drawArea,"createSpacer");
                }else{
                    spanCount++;
                }
            }
        }
        if(finished==false){
            qDebug()<<"message fehlt";
        }
    }
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Fragment
    //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if(seqItem->stepType()==FragmentStep){
        const MscFragmentItem* fragmentItem = dynamic_cast<const MscFragmentItem*>(seqItem);
        QString FragmentLabel = "";
        if(fragmentItem->fragmentType()==FragmentType::AlternativeFragment){
            FragmentLabel = "alt";
        }else if(fragmentItem->fragmentType()==FragmentType::ParallelFragment){
            FragmentLabel = "par";
        }else if(fragmentItem->fragmentType()==FragmentType::SequenceFragment){
            FragmentLabel = "seq";
        }else if(fragmentItem->fragmentType()==FragmentType::OptionalFragment){
            FragmentLabel = "opt";
        }else if(fragmentItem->fragmentType()==FragmentType::LoopFragment){
            FragmentLabel = "loop";
        }else if(fragmentItem->fragmentType()==FragmentType::IgnoreFragment){
            FragmentLabel = "ign";
        }else if(fragmentItem->fragmentType()==FragmentType::ConsiderFragment){
            FragmentLabel = "con";
        }else if(fragmentItem->fragmentType()==FragmentType::AssertFragment){
            FragmentLabel = "ass";
        }else if(fragmentItem->fragmentType()==FragmentType::UserFragmentType){
            FragmentLabel = "user";
        }


        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==0){
                QMetaObject::invokeMethod(drawArea,"createFragmentStart",Q_ARG(QVariant,fragmentItem->uuid().toString()),Q_ARG(QVariant,FragmentLabel));
            }else if(i==this->_d->_columnCount - 1){
                QMetaObject::invokeMethod(drawArea,"createSpacer");
            }else{
                if(fragmentItem->regions().length()==1){
                    QMetaObject::invokeMethod(drawArea,"createFragment",Q_ARG(QVariant,"[" + fragmentItem->regions().first()->name() + "]"),Q_ARG(QVariant,this->_d->_columnCount-2));
                    i = this->_d->_columnCount-2;
                }else{
                    QMetaObject::invokeMethod(drawArea,"createSpacer");
                }
            }
        }
        if(fragmentItem->regions().length()>1){
            for(const MscFragmentRegionItem* region: fragmentItem->regions()){
                for(int i = 0; i < this->_d->_columnCount; i++){
                    if(i==0){
                        QMetaObject::invokeMethod(drawArea,"createRegionStart",Q_ARG(QVariant,region->uuid().toString()));
                    }else if(i==this->_d->_columnCount - 1){
                        QMetaObject::invokeMethod(drawArea,"createSpacer");
                    }else{
                        QMetaObject::invokeMethod(drawArea,"createRegion",Q_ARG(QVariant,"[" + region->name() + "]"),Q_ARG(QVariant,this->_d->_columnCount-2));
                        i = this->_d->_columnCount-2;
                    }
                }
                for(const MscSequenceItem* item: region->sequenceItems()){
                    placeItem(item);
                }
                for(int i = 0; i < this->_d->_columnCount; i++){
                    if(i==this->_d->_columnCount-1){
                        QMetaObject::invokeMethod(drawArea,"createRegionEnd",Q_ARG(QVariant,region->uuid().toString()));
                    }else{
                        QMetaObject::invokeMethod(drawArea,"createSpacer");
                    }
                }
            }
        }else{
            for(const MscSequenceItem* item: fragmentItem->regions().first()->sequenceItems()){
                placeItem(item);
            }
        }

        for(int i = 0; i < this->_d->_columnCount; i++){
            if(i==this->_d->_columnCount-1){
                QMetaObject::invokeMethod(drawArea,"createFragmentEnd",Q_ARG(QVariant,fragmentItem->uuid().toString()));
            }else{
                QMetaObject::invokeMethod(drawArea,"createSpacer");
            }
        }
    }
}
void QmlMscView::countComponents(const MscSequenceItem* seq){
    if(seq == nullptr){
        for(const model::base::ModelItem* compItem : this->_d->_mscSeq->componentItems()){
            if(compItem){
                if(this->_d->_CompList.contains(compItem)==false){
                    this->_d->_CompList.append(compItem);
                }
            }
        }
        for(const MscSequenceItem* seqItem : this->_d->_mscSeq->sequenceItems()){
            countComponents(seqItem);
        }
    }else{
        if(seq->stepType() == MessageStep){
            const MscMessageItem* MessageItem = dynamic_cast<const MscMessageItem*>(seq);
            if(MessageItem){
                if(MessageItem->sourcePort()){
                    if(MessageItem->sourcePort()->owner()){
                        if(this->_d->_CompList.contains(MessageItem->sourcePort()->owner())==false){
                            this->_d->_CompList.append(MessageItem->sourcePort()->owner());
                        }
                        if(this->_d->_PortList.contains(MessageItem->sourcePort())==false){
                            this->_d->_PortList.append(MessageItem->sourcePort());
                        }
                    }
                }
                if(MessageItem->targetPort()){
                    if(MessageItem->targetPort()->owner()){
                        if(this->_d->_CompList.contains(MessageItem->targetPort()->owner())==false){
                            this->_d->_CompList.append(MessageItem->targetPort()->owner());
                        }
                        if(this->_d->_PortList.contains(MessageItem->targetPort())==false){
                            this->_d->_PortList.append(MessageItem->targetPort());
                        }
                    }
                }
            }
        }
        if(seq->stepType() == CheckMessageStep){
            const MscCheckMessageItem* CheckMessageItem = dynamic_cast<const MscCheckMessageItem*>(seq);
            if(CheckMessageItem){
                if(CheckMessageItem->sourcePort()){
                    if(CheckMessageItem->sourcePort()->owner()){
                        if(this->_d->_CompList.contains(CheckMessageItem->sourcePort()->owner())==false){
                            this->_d->_CompList.append(CheckMessageItem->sourcePort()->owner());
                            this->_d->_PortList.append(CheckMessageItem->sourcePort());
                        }
                    }
                }
                if(CheckMessageItem->targetPort()){
                    if(CheckMessageItem->targetPort()->owner()){
                        if(this->_d->_CompList.contains(CheckMessageItem->targetPort()->owner())==false){
                            this->_d->_CompList.append(CheckMessageItem->targetPort()->owner());
                            this->_d->_PortList.append(CheckMessageItem->targetPort());
                        }
                    }
                }
            }
        }
        if(seq->stepType() == StatementStep){
            const MscStatementItem* StatementItem = dynamic_cast<const MscStatementItem*>(seq);
            if(StatementItem){
                if(StatementItem->component()){
                    if(this->_d->_CompList.contains(StatementItem->component())==false){
                        this->_d->_CompList.append(StatementItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == TimeoutStep){
            const MscTimeoutItem* TimeoutItem = dynamic_cast<const MscTimeoutItem*>(seq);
            if(TimeoutItem){
                if(TimeoutItem->component()){
                    if(this->_d->_CompList.contains(TimeoutItem->component())==false){
                        this->_d->_CompList.append(TimeoutItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == TimerStep){
            const MscTimerItem* TimerItem = dynamic_cast<const MscTimerItem*>(seq);
            if(TimerItem){
                if(TimerItem->component()){
                    if(this->_d->_CompList.contains(TimerItem->component())==false){
                        this->_d->_CompList.append(TimerItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == SleepTimerStep){
            const MscSleepTimerItem* SleepTimerItem = dynamic_cast<const MscSleepTimerItem*>(seq);
            if(SleepTimerItem){
                if(SleepTimerItem->component()){
                    if(this->_d->_CompList.contains(SleepTimerItem->component())==false){
                        this->_d->_CompList.append(SleepTimerItem->component());
                    }
                }
            }
        }
        if(seq->stepType() == FragmentStep){
            const MscFragmentItem* item = dynamic_cast<const MscFragmentItem*>(seq);
            if(item){
                for(const MscFragmentRegionItem* region : item->regions()){
                    if(region){
                        for(const model::base::ModelItem* compItem : region->componentItems()){
                            if(compItem){
                                if(this->_d->_CompList.contains(compItem)==false){
                                    this->_d->_CompList.append(compItem);
                                }
                            }
                        }
                        for(const MscSequenceItem* newSeq : region->sequenceItems()){
                            countComponents(newSeq);
                        }
                    }
                }
            }
        }
    }
}

//Design
void QmlMscView::setComponentColor(const QColor& color){
    this->_d->_componentColor=color;
}
void QmlMscView::setComponentTextColor(const QColor& color){
    this->_d->_componentTextColor=color;
}
void QmlMscView::setComponentRadius(const int& radius){
    this->_d->_componentRadius=radius;
}
void QmlMscView::setStatementColor(const QColor& color){
    this->_d->_statementColor=color;
}
void QmlMscView::setStatementTextColor(const QColor& color){
    this->_d->_componentTextColor=color;
}
void QmlMscView::setStatementRadius(const int& radius){
    this->_d->_componentRadius=radius;
}
void QmlMscView::setTimerColor(const QColor& color){
    this->_d->_timerColor=color;
}
void QmlMscView::setTimerTextColor(const QColor& color){
    this->_d->_timerTextColor=color;
}
void QmlMscView::setTimerRadius(const int& radius){
    this->_d->_timerRadius=radius;
}
void QmlMscView::setMessageColor(const QColor& color){
    this->_d->_messageColor=color;
}
void QmlMscView::setMessageTextColor(const QColor& color){
    this->_d->_messageTextColor=color;
}
void QmlMscView::setLifelineColor(const QColor& color){
    this->_d->_lifelineColor=color;
}
