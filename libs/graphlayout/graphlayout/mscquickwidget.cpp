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

#include "mscquickwidget.hpp"

#include <mobata/utils/functors.hpp>
#include <mobata/model/msc/msc.hpp>

#include <QtQuick>
#include <QtWidgets>
#include <QtGlobal>
#include <QQuickItem>
#include <QStringList>
#include <QList>
#include <QFileDialog>

#include <QDebug>
#include <QPixmap>

using namespace graphlayout;

model::msc::MscComponentItem const* portOwnerComponent(model::msc::PortItem const* port)
{
  if(!port)
    return nullptr;

  if(!port->owner())
    return  nullptr;

  if(port->ownerType()!=model::msc::PortItem::Component)
    return nullptr;

  return static_cast<model::msc::MscComponentItem const*>(port->owner());
}

class MscQuickWidget::Private{
  friend class MscQuickWidget;

  model::msc::MscSequence* _mscSeq = nullptr;

  QQuickItem* _rootObject;
  QQmlEngine* _engine;

  QList<const model::msc::MscComponentItem*>  _fixCompList;
  QList<const model::msc::MscComponentItem*>  _compList;
  QList<const model::msc::PortItem*>          _portList;
  QList<QList<const QUuid*>>                  _lifeLines;
  int _columnCount;

  //! DesignSettings
  //! Component
  QColor _componentColor = QColor("darkblue");
  QColor _componentTextColor = QColor("white");
  int _componentRadius = 10;
  //! Statement
  QColor _statementColor = QColor("darkkhaki");
  QColor _statementTextColor = QColor("black");
  int _statementRadius = 10;
  //! Timer
  QColor _timerColor = QColor("darkgoldenrod");
  QColor _timerTextColor = QColor("black");
  int _timerRadius = 10;
  //! Timeout
  QColor _timeoutColor = QColor("darkgoldenrod");
  QColor _timeoutTextColor = QColor("black");
  int _timeoutRadius = 10;
  //! Sleeptimer
  QColor _sleeptimerColor = QColor("darkgoldenrod");
  QColor _sleeptimerTextColor = QColor("black");
  int _sleeptimerRadius = 10;
  //! Message
  QColor _messageColor = QColor("darkslateblue");
  QColor _messageTextColor = QColor("black");
  //! Message
  QColor _checkmessageColor = QColor("darkslateblue");
  QColor _checkmessageTextColor = QColor("black");
  //! Fragment
  QColor _fragmentColor = QColor("khaki");
  QColor _fragmentTextColor = QColor("black");
  //! Region
  QColor _regionColor = QColor("khaki");
  QColor _regionTextColor = QColor("black");
  //! Lifeline
  QColor _lifelineColor = QColor("black");
  //! Background
  QColor _backgroundColor = QColor("lightgrey");
  //! Highlightcolor
  QColor _highlightColor = QColor("red");

  Private(model::msc::MscSequence const* mscSequence = nullptr)
    : _mscSeq(const_cast<model::msc::MscSequence*>(mscSequence))
  {}
};

MscQuickWidget::MscQuickWidget(QWidget* parent)
  : QQuickWidget(parent), _d(new Private)
{
  this->setResizeMode(QQuickWidget::SizeRootObjectToView);
  this->setSource(QUrl("qrc:/graphlayout/qml/msc_main.qml"));
  if(this->status()==QQuickWidget::Error)
  {
    for(const QQmlError& currError : this->errors())
      qDebug()<<"msc_main.qml error: "<<currError.toString();
    Q_ASSERT(false);
  }
  this->_d->_engine=this->engine();
  Q_ASSERT(this->_d->_engine);

  this->_d->_rootObject =this->rootObject();
  Q_ASSERT(this->_d->_rootObject);
}

MscQuickWidget::MscQuickWidget(const model::msc::MscSequence *mscSequence,
                               QWidget* parent)
  :QQuickWidget(parent), _d(new Private(mscSequence))
{
  this->setResizeMode(QQuickWidget::SizeRootObjectToView);
  this->setSource(QUrl("qrc:/graphlayout/qml/msc_main.qml"));
  if(this->status()==QQuickWidget::Error)
  {
    for(const QQmlError& currError : this->errors())
      qDebug()<<"msc_main.qml error: "<<currError.toString();
    Q_ASSERT(false);
  }
  this->_d->_engine=this->engine();
  Q_ASSERT(this->_d->_engine);

  this->_d->_rootObject =this->rootObject();
  Q_ASSERT(this->_d->_rootObject);
}

MscQuickWidget::~MscQuickWidget()
{
  delete this->_d;
}

void MscQuickWidget::clickedObject(const QString &uuid){
  emit selectedItem(QUuid(uuid));
}

void MscQuickWidget::setMscSequence(model::msc::MscSequence const* mscSequence)
{
  this->_d->_mscSeq = const_cast<model::msc::MscSequence*>(mscSequence);

  return;
}

model::msc::MscSequence const* MscQuickWidget::mscSequence() const
{
  return this->_d->_mscSeq;
}

void MscQuickWidget::addFixMscComponent(model::msc::MscComponentItem const* mscComponent)
{
  if(!mscComponent)
    return;

  if(!this->_d->_fixCompList.contains(mscComponent))
    this->_d->_fixCompList.append(mscComponent);

  return;
}


void MscQuickWidget::reset()
{
  for(QQuickItem* item :
      _d->_rootObject->findChildren<QQuickItem*>(QRegExp("msc*",
                                                         Qt::CaseSensitive,
                                                         QRegExp::Wildcard))){
    delete item;
  }

  this->_d->_lifeLines.clear();
  this->_d->_compList.clear();
  this->_d->_portList.clear();

  return;
}

bool MscQuickWidget::layout(QString* errorString)
{
  if(!this->_d->_mscSeq)
    return true;

  QTime myTimer;
  myTimer.start();
  this->reset();

  this->countComponents();
  bool result = this->createComponentList(errorString);
  if(!result)
    return false;

  result = this->placeComponents(errorString);
  if(!result)
    return false;

  result = this->placeSeq(errorString);
  if(!result)
    return false;

  result = this->addFrames(errorString);
  if(!result)
    return false;

  this->updateLifeLines();
  this->updateOverlay();

  this->connectMouseAreas();

  this->_d->_rootObject->setProperty("color",this->_d->_backgroundColor);
  QObject* zoomobject = this->_d->_rootObject->findChild<QObject*>("zoomObject");
  if(zoomobject){
    QObject::connect(zoomobject, SIGNAL(contentXChanged()), this, SLOT(updateLifeLines()));
    QObject::connect(zoomobject, SIGNAL(contentYChanged()), this, SLOT(updateLifeLines()));
  }
  QObject* scaleobject = this->_d->_rootObject->findChild<QObject*>("scale");
  if(scaleobject){
    QObject::connect(scaleobject, SIGNAL(xScaleChanged()), this, SLOT(updateLifeLines()));
    QObject::connect(scaleobject, SIGNAL(yScaleChanged()), this, SLOT(updateLifeLines()));
  }

  //  qDebug()<<"Layout time: " << myTimer.elapsed()<<" ms";
  return true;
}

void MscQuickWidget::connectMouseAreas()
{
  for(QObject* object : this->_d->_rootObject->findChildren<QObject*>(QRegExp("msc__*",
                                                                              Qt::CaseSensitive,
                                                                              QRegExp::Wildcard))){
    QObject::connect(object, SIGNAL(clickedObject(QString)), this, SLOT(clickedObject(QString)));
  }
}

bool MscQuickWidget::createComponentList(QString *errorString)
{
  Q_UNUSED(errorString);

  QList<const QUuid*> Row_1;
  QList<const QUuid*> Row_2;
  for(const model::base::ModelItem*  mscComp : this->_d->_compList){
    bool hasPorts = false;
    for(const model::base::PortItem* mscPort : this->_d->_portList){
      if(mscPort->owner()->uuid()==mscComp->uuid()){

        hasPorts = true;
      }
    }
    if(hasPorts==false){
      Row_1.append(nullptr);
      Row_2.append(&mscComp->uuid());
    }else{
      for(const model::base::PortItem* mscPort : this->_d->_portList){
        if(Row_2.contains(&mscPort->uuid())==false && mscPort->owner()->uuid()==mscComp->uuid()){
          Row_1.append(&mscComp->uuid());
          Row_2.append(&mscPort->uuid());
        }
      }
    }
  }
  this->_d->_lifeLines.append(Row_1);
  this->_d->_lifeLines.append(Row_2);

  return true;
}

QString MscQuickWidget::nameFromComponent(const QUuid uuid){
  for(const model::base::ModelItem*  mscComp : this->_d->_compList){
    if(mscComp->uuid()==uuid){
      return mscComp->toString();
    }
  }
  for(const model::base::PortItem* mscPort : this->_d->_portList){
    if(mscPort->uuid()==uuid){
      return mscPort->name();
    }
  }
  return QLatin1String("");
}

bool MscQuickWidget::placeComponents(QString *errorString){
  QObject* drawArea = this->_d->_rootObject->findChild<QObject*>("drawArea");
  if(drawArea==nullptr){
    utils::AddPtrString(errorString)<<"drawArea not found";
    qDebug()<<"drawArea not found";
    return false;
  }
  QObject* lifeLinesArea = this->_d->_rootObject->findChild<QObject*>("zoomObject");

  QList<const QUuid*> row = this->_d->_lifeLines.first();
  int counter=row.length();
  counter = (counter*2)+1;
  this->_d->_columnCount = counter;
  drawArea->setProperty("columns",counter);
  counter = 0;
  const QUuid* lastuuid = nullptr;
  for(const QUuid* uuid: row){
    if(lastuuid == uuid){
      continue;
    }
    QVariant checkVariant;
    bool ok = QMetaObject::invokeMethod(drawArea,"createComponentSpacer",Q_RETURN_ARG(QVariant, checkVariant));
    QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
    Q_ASSERT(ok);
    Q_ASSERT(checkObject);
    counter++;
    if(uuid==nullptr){
      QVariant checkVariant;
      bool ok = QMetaObject::invokeMethod(drawArea,"createComponentSpacer",Q_RETURN_ARG(QVariant, checkVariant));
      QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
      Q_ASSERT(ok);
      Q_ASSERT(checkObject);
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
      QVariant checkVariant;
      bool ok = QMetaObject::invokeMethod(drawArea,"createComponent",
                                Q_RETURN_ARG(QVariant, checkVariant),
                                Q_ARG(QVariant,name),
                                Q_ARG(QVariant,*uuid),
                                Q_ARG(QVariant,spanCounter),
                                Q_ARG(QVariant,counter),
                                Q_ARG(QVariant,this->_d->_componentColor),
                                Q_ARG(QVariant,this->_d->_componentRadius),
                                Q_ARG(QVariant,this->_d->_componentTextColor));
      QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
      Q_ASSERT(ok);
      Q_ASSERT(checkObject);

      counter = counter + spanCounter;
    }
  }
  QVariant checkVariant;
  bool ok = QMetaObject::invokeMethod(drawArea,"createComponentSpacer", Q_RETURN_ARG(QVariant, checkVariant));
  QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
  Q_ASSERT(ok);
  Q_ASSERT(checkObject);


  row = this->_d->_lifeLines.last();
  counter = 0;
  for(const QUuid* uuid: row){
    QVariant checkVariant;
    bool ok = QMetaObject::invokeMethod(drawArea,"createComponentSpacer", Q_RETURN_ARG(QVariant, checkVariant));
    QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
    Q_ASSERT(ok);
    Q_ASSERT(checkObject);
    counter++;
    if(uuid==nullptr){
      QVariant checkVariant;
      bool ok = QMetaObject::invokeMethod(drawArea,"createComponentSpacer", Q_RETURN_ARG(QVariant, checkVariant));
      QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
      Q_ASSERT(ok);
      Q_ASSERT(checkObject);
    }else{
      const QString name = nameFromComponent(*uuid);
      QVariant checkVariant;
      QMetaObject::invokeMethod(drawArea,"createComponent",
                                Q_RETURN_ARG(QVariant, checkVariant),
                                Q_ARG(QVariant,name),
                                Q_ARG(QVariant,*uuid),
                                Q_ARG(QVariant,1),
                                Q_ARG(QVariant,counter),
                                Q_ARG(QVariant,this->_d->_componentColor),
                                Q_ARG(QVariant,this->_d->_componentRadius),
                                Q_ARG(QVariant,this->_d->_componentTextColor));
      QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
      Q_ASSERT(ok);
      Q_ASSERT(checkObject);
      QQuickItem* source = component(*uuid);
      if(source != nullptr){
        QQmlComponent dyn(_d->_engine,
                          QUrl::fromLocalFile(":/graphlayout/qml/msc_lifeline.qml"),
                          lifeLinesArea);
        QObject *dynObject = dyn.create();
        Q_ASSERT(dynObject);
        QQuickItem* item = qobject_cast<QQuickItem*>(dynObject);
        Q_ASSERT(item);
        item->setProperty("compUuid",uuid->toString());
        item->setParent(lifeLinesArea);
        item->setProperty("color",this->_d->_lifelineColor);
        item->setParentItem(qobject_cast<QQuickItem*>(lifeLinesArea));
        QObject::connect(source,&QQuickItem::widthChanged,this,&MscQuickWidget::updateLifeLines);
        QObject::connect(source,&QQuickItem::heightChanged, this,&MscQuickWidget::updateLifeLines);
        QObject::connect(source,&QQuickItem::xChanged,this,&MscQuickWidget::updateLifeLines);
        QObject::connect(source,&QQuickItem::yChanged, this,&MscQuickWidget::updateLifeLines);
      }
    }
    counter++;
  }
  if(1==1){
    QVariant checkVariant;
    bool ok = QMetaObject::invokeMethod(drawArea,"createComponentSpacer", Q_RETURN_ARG(QVariant, checkVariant));
    QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
    Q_ASSERT(ok);
    Q_ASSERT(checkObject);
  }
  for(QQuickItem* compItem : drawArea->findChildren<QQuickItem*>("msc__component")){
    QObject::connect(compItem,&QQuickItem::widthChanged,this,&MscQuickWidget::updateOverlay);
    QObject::connect(compItem,&QQuickItem::heightChanged, this,&MscQuickWidget::updateOverlay);
  }
  for(QQuickItem* spacerCompItem : drawArea->findChildren<QQuickItem*>("msc_compspacer")){
    QObject::connect(spacerCompItem,&QQuickItem::widthChanged,this,&MscQuickWidget::updateOverlay);
    QObject::connect(spacerCompItem,&QQuickItem::heightChanged, this,&MscQuickWidget::updateOverlay);
  }

  for(int i=0;i<this->_d->_columnCount;i++){
    QVariant checkVariant;
    bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
    QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
    Q_ASSERT(ok);
    Q_ASSERT(checkObject);
  }

  return true;
}

void MscQuickWidget::updateLifeLines(){
  QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
  QQuickItem* lifeLinesArea = this->_d->_rootObject->findChild<QQuickItem*>("zoomObject");
  for(QQuickItem* comp: drawArea->findChildren<QQuickItem*>("msc__component")){
    for(QQuickItem* lifeline: lifeLinesArea->findChildren<QQuickItem*>("msc_lifeline")){
      if(comp->property("uuid") == lifeline->property("compUuid")){
        QPointF newPos = comp->mapToItem(lifeLinesArea,QPointF(comp->width()/2,0));
        newPos = newPos - QPointF(qvariant_cast<qreal>(drawArea->property("contentX")),0);
        if(newPos.x()!=0.0){
          bool ok = QMetaObject::invokeMethod(lifeline,"updateX", Q_ARG(QVariant,newPos.x()));
          Q_ASSERT(ok);
        }
      }
    }
  }
}

void MscQuickWidget::updateOverlay(){
  QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
  QQuickItem* compArea = this->_d->_rootObject->findChild<QQuickItem*>("compArea");

  int compAreaChildSize = compArea->children().size();
  for(int i = 2; i<compAreaChildSize; ++i)
  {
    QObject* comp = drawArea->children()[i];
    bool ok = QMetaObject::invokeMethod(compArea,"setSize",
                              Q_ARG(QVariant,i-2),
                              Q_ARG(QVariant,comp->property("height")),
                              Q_ARG(QVariant,comp->property("width")));
    Q_ASSERT(ok);
  }

  return;
}

void MscQuickWidget::updateRegionLines(){
  QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
  QQuickItem* lifeLinesArea = this->_d->_rootObject->findChild<QQuickItem*>("zoomObject");
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

bool MscQuickWidget::addFrames(QString* errorString)
{
  QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
  QQuickItem* lifeLinesArea = this->_d->_rootObject->findChild<QQuickItem*>("zoomObject");
  int fullwidth=0;
  for(QQuickItem* node: drawArea->findChildren<QQuickItem*>("msc_frame")){
    if(qvariant_cast<bool>(node->property("finished"))==true){
      continue;
    }
    if(qvariant_cast<int>(node->property("num"))==2 || qvariant_cast<int>(node->property("num"))==4){
      qDebug()<<"error to much frames";
      return false;
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
    if(endnode==nullptr)
    {
      utils::AddPtrString(errorString)<<"Frameteil fehlt";
      return false;
    }
    QPointF startPos = node->mapToItem(lifeLinesArea, QPointF(node->height(),node->height()));
    QPointF endPos = endnode->mapToItem(lifeLinesArea, QPointF(0,0));
    QQmlComponent dyn(_d->_engine,
                      QUrl::fromLocalFile(":/graphlayout/qml/msc_regionline.qml"),
                      lifeLinesArea);
    QObject *dynObject = dyn.create();
    Q_ASSERT(dynObject);
    QQuickItem* item = qobject_cast<QQuickItem*>(dynObject);
    Q_ASSERT(item);

    item->setParent(lifeLinesArea);
    item->setParentItem(qobject_cast<QQuickItem*>(lifeLinesArea));
    item->setProperty("startPos",startPos);
    item->setProperty("endPos",endPos);
    item->setProperty("intend",maxcounter*3);
    item->setProperty("uuid",node->property("uuid"));
    item->setProperty("type",type);
    item->setProperty("label",node->property("label"));
    if(type == 0){
      item->setProperty("linecolor",this->_d->_fragmentColor);
      item->setProperty("textcolor",this->_d->_fragmentTextColor);
    }else if(type == 1){
      item->setProperty("linecolor",this->_d->_regionColor);
      item->setProperty("textcolor",this->_d->_regionTextColor);
    }
    endnode->setProperty("finished",true);
    node->setProperty("finished",true);
    QObject::connect(endnode,&QQuickItem::widthChanged,this,&MscQuickWidget::updateRegionLines);
    QObject::connect(node,&QQuickItem::widthChanged,this,&MscQuickWidget::updateRegionLines);
    QObject::connect(endnode,&QQuickItem::heightChanged,this,&MscQuickWidget::updateRegionLines);
    QObject::connect(node,&QQuickItem::heightChanged,this,&MscQuickWidget::updateRegionLines);
    if(maxcounter>fullwidth)
      fullwidth=maxcounter;
  }
  QVariant checkVariant;
  bool ok = QMetaObject::invokeMethod(drawArea,"setMinimumWidth", Q_RETURN_ARG(QVariant, checkVariant), Q_ARG(QVariant,fullwidth*3+10));
  QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
  Q_ASSERT(ok);
  Q_ASSERT(checkObject);

  return true;
}

bool MscQuickWidget::placeSeq(QString *errorString)
{
  for(const model::msc::MscSequenceItem* seqItem: this->_d->_mscSeq->sequenceItems()){
    bool result = placeItem(seqItem,errorString);
    if(!result)
      return false;
  }
  QObject* drawArea = this->_d->_rootObject->findChild<QObject*>("drawArea");
  if(drawArea==nullptr){
    utils::AddPtrString(errorString)<<"drawArea not found";
    qDebug()<<"drawArea not found";
    return false;
  }
  for(int i=0; i<this->_d->_columnCount; i++){
    QVariant checkVariant;
    bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
    QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
    Q_ASSERT(ok);
    Q_ASSERT(checkObject);
  }
  return true;
}

int MscQuickWidget::columnFromComponent(const QUuid uuid){
  for(QQuickItem* object: this->_d->_rootObject->findChildren<QQuickItem*>("msc__component")){
    if(qvariant_cast<QString>(object->property("uuid"))==uuid.toString()){
      return qvariant_cast<int>(object->property("column"));
    }
  }
  return -1;
}

QQuickItem* MscQuickWidget::component(const QUuid uuid){
  for(QQuickItem* object: this->_d->_rootObject->findChildren<QQuickItem*>("msc__component")){
    if(qvariant_cast<QString>(object->property("uuid"))==uuid.toString()){
      return object;
    }
  }
  return nullptr;
}

int MscQuickWidget::spanFromComponent(const QUuid uuid){
  for(QQuickItem* object: this->_d->_rootObject->findChildren<QQuickItem*>("msc__component")){
    if(qvariant_cast<QString>(object->property("uuid"))==uuid.toString()){
      return qvariant_cast<int>(object->property("span"));
    }
  }
  return -1;
}

bool MscQuickWidget::placeItem(const model::msc::MscSequenceItem *seqItem, QString *errorString){
  if(seqItem==nullptr){
    utils::AddPtrString(errorString)<<"SeqItem not found";
    qDebug()<<"SeqItem not found";
    return false;
  }
  QObject* drawArea = this->_d->_rootObject->findChild<QObject*>("drawArea");
  if(drawArea==nullptr){
    utils::AddPtrString(errorString)<<"drawArea not found";
    qDebug()<<"drawArea not found";
    return false;
  }
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // StatementStep
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if(seqItem->stepType()==model::msc::StatementStep){
    const model::msc::MscStatementItem* statementItem = static_cast<const model::msc::MscStatementItem*>(seqItem);
    const QUuid statementComp = statementItem->component()->uuid();
    int place = columnFromComponent(statementComp);
    int span = spanFromComponent(statementComp);
    for(int i = 0; i < this->_d->_columnCount; i++){
      if(i==place){
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createStatement",
                                            Q_RETURN_ARG(QVariant, checkVariant),
                                  Q_ARG(QVariant,statementItem->statement()),
                                  Q_ARG(QVariant,span),
                                  Q_ARG(QVariant,this->_d->_statementColor),
                                  Q_ARG(QVariant,this->_d->_statementRadius),
                                  Q_ARG(QVariant,this->_d->_statementTextColor),
                                  Q_ARG(QVariant,statementItem->uuid().toString()));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
        i = i + span - 1;
      }else{
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }
    }
  }
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // TimerStep
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if(seqItem->stepType()==model::msc::TimerStep){
    const model::msc::MscTimerItem* timerItem = static_cast<const model::msc::MscTimerItem*>(seqItem);
    const QUuid timerComp = timerItem->component()->uuid();
    int place = columnFromComponent(timerComp);
    int span = spanFromComponent(timerComp);
    for(int i = 0; i < this->_d->_columnCount; i++){
      if(i==place){
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createTimer",
                                            Q_RETURN_ARG(QVariant, checkVariant),
                                  Q_ARG(QVariant,timerItem->toString()),
                                  Q_ARG(QVariant,span),
                                  Q_ARG(QVariant,this->_d->_timerColor),
                                  Q_ARG(QVariant,this->_d->_timerRadius),
                                  Q_ARG(QVariant,this->_d->_timerTextColor),
                                  Q_ARG(QVariant,timerItem->uuid().toString()));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
        i = i + span - 1;
      }else{
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }
    }
  }
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // TimeoutStep
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if(seqItem->stepType()==model::msc::TimeoutStep){
    const model::msc::MscTimeoutItem* timeoutItem = static_cast<const model::msc::MscTimeoutItem*>(seqItem);
    const QUuid timeoutComp = timeoutItem->component()->uuid();
    int place = columnFromComponent(timeoutComp);
    int span = spanFromComponent(timeoutComp);
    for(int i = 0; i < this->_d->_columnCount; i++){
      if(i==place){
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createTimer",
                                            Q_RETURN_ARG(QVariant, checkVariant),
                                  Q_ARG(QVariant,timeoutItem->toString()),
                                  Q_ARG(QVariant,span),
                                  Q_ARG(QVariant,this->_d->_timeoutColor),
                                  Q_ARG(QVariant,this->_d->_timeoutRadius),
                                  Q_ARG(QVariant,this->_d->_timeoutTextColor),
                                  Q_ARG(QVariant,timeoutItem->uuid().toString()));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
        i = i + span - 1;
      }else{
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }
    }
  }
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // SleepTimer
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if(seqItem->stepType()==model::msc::SleepTimerStep){
    const model::msc::MscSleepTimerItem* sleeptimerItem = static_cast<const model::msc::MscSleepTimerItem*>(seqItem);
    const QUuid sleeptimerComp = sleeptimerItem->component()->uuid();
    int place = columnFromComponent(sleeptimerComp);
    int span = spanFromComponent(sleeptimerComp);
    for(int i = 0; i < this->_d->_columnCount; i++){
      if(i==place){
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createTimer",
                                            Q_RETURN_ARG(QVariant, checkVariant),
                                  Q_ARG(QVariant,sleeptimerItem->toString()),
                                  Q_ARG(QVariant,span),
                                  Q_ARG(QVariant,this->_d->_sleeptimerColor),
                                  Q_ARG(QVariant,this->_d->_sleeptimerRadius),
                                  Q_ARG(QVariant,this->_d->_sleeptimerTextColor),
                                  Q_ARG(QVariant,sleeptimerItem->uuid().toString()));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
        i = i + span - 1;
      }else{
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }
    }
  }
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // Message
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if(seqItem->stepType()==model::msc::MessageStep){
    const model::msc::MscMessageItem* messageItem = static_cast<const model::msc::MscMessageItem*>(seqItem);
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
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageStart",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_messageColor));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }else{
          finished = true;
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,messageItem->toString(true)),
                                    Q_ARG(QVariant,spanCount),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_messageColor),
                                    Q_ARG(QVariant,this->_d->_messageTextColor),
                                    Q_ARG(QVariant,messageItem->uuid().toString()));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
          ok = QMetaObject::invokeMethod(drawArea,"createMessageStart",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_messageColor));
          checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }
      }else if(i==targetPlace){
        if(rightArrow == 2){
          rightArrow = 0;
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageEnd",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_messageColor));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }else{
          finished = true;
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,messageItem->toString(true)),
                                    Q_ARG(QVariant,spanCount),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_messageColor),
                                    Q_ARG(QVariant,this->_d->_messageTextColor),
                                    Q_ARG(QVariant,messageItem->uuid().toString()));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
          ok = QMetaObject::invokeMethod(drawArea,"createMessageEnd",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_messageColor));
          checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }
      }else{
        if(rightArrow == 2 || finished == true){
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }else{
          spanCount++;
        }
      }
    }
    if(finished==false){
      utils::AddPtrString(errorString)<<"message not found";
      qDebug()<<"message not found";
      return false;
    }
  }
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // CheckMessage
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if(seqItem->stepType()==model::msc::CheckMessageStep){
    const model::msc::MscCheckMessageItem* checkmessageItem = static_cast<const model::msc::MscCheckMessageItem*>(seqItem);
    const QUuid messageSource = checkmessageItem->sourcePort()->uuid();
    const QUuid messageTarget = checkmessageItem->targetPort()->uuid();
    int sourcePlace = columnFromComponent(messageSource);
    int targetPlace = columnFromComponent(messageTarget);
    int spanCount = 0;
    int rightArrow = 2;
    bool finished = false;
    for(int i = 0; i < this->_d->_columnCount; i++){
      if(i==sourcePlace){
        if(rightArrow == 2){
          rightArrow = 1;
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageStart",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_checkmessageColor));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }else{
          finished = true;
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,checkmessageItem->toString()),
                                    Q_ARG(QVariant,spanCount),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_checkmessageColor),
                                    Q_ARG(QVariant,this->_d->_checkmessageTextColor),
                                    Q_ARG(QVariant,checkmessageItem->uuid().toString()));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
          ok = QMetaObject::invokeMethod(drawArea,"createMessageStart",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_checkmessageColor));
          checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }
      }else if(i==targetPlace){
        if(rightArrow == 2){
          rightArrow = 0;
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageEnd",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_checkmessageColor));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }else{
          finished = true;
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createMessageArrow",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,checkmessageItem->toString()),
                                    Q_ARG(QVariant,spanCount),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_checkmessageColor),
                                    Q_ARG(QVariant,this->_d->_checkmessageTextColor),
                                    Q_ARG(QVariant,checkmessageItem->uuid().toString()));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
          ok = QMetaObject::invokeMethod(drawArea,"createMessageEnd",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,rightArrow),
                                    Q_ARG(QVariant,this->_d->_checkmessageColor));
          checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }
      }else{
        if(rightArrow == 2 || finished == true){
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }else{
          spanCount++;
        }
      }
    }
    if(finished==false){
      utils::AddPtrString(errorString)<<"message not found";
      qDebug()<<"message not found";
      return false;
    }
  }
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // Fragment
  //!xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if(seqItem->stepType()==model::msc::FragmentStep){
    const model::msc::MscFragmentItem* fragmentItem = static_cast<const model::msc::MscFragmentItem*>(seqItem);
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


    for(int i = 0; i < this->_d->_columnCount; i++){
      if(i==0){
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createFragmentStart",
                                            Q_RETURN_ARG(QVariant, checkVariant),
                                  Q_ARG(QVariant,
                                        fragmentItem->uuid().toString()),
                                  Q_ARG(QVariant,FragmentLabel));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }else if(i==this->_d->_columnCount - 1){
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }else{
        if(fragmentItem->regions().length()==1 && fragmentItem->fragmentType()==model::msc::FragmentType::DurationFragment){
          uint duration = fragmentItem->duration();
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createFragment",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,"[" + QString::number(duration) + " ms]"),
                                    Q_ARG(QVariant,this->_d->_columnCount-2),
                                    Q_ARG(QVariant,this->_d->_regionTextColor));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
          i = this->_d->_columnCount-2;
        }else if(fragmentItem->regions().length()==1){
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createFragment",
                                              Q_RETURN_ARG(QVariant, checkVariant),
                                    Q_ARG(QVariant,"[" + fragmentItem->regions().first()->name() + "]"),
                                    Q_ARG(QVariant,this->_d->_columnCount-2),
                                    Q_ARG(QVariant,this->_d->_regionTextColor));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
          i = this->_d->_columnCount-2;
        }else{
          QVariant checkVariant;
          bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
          QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
          Q_ASSERT(ok);
          Q_ASSERT(checkObject);
        }
      }
    }
    if(fragmentItem->regions().length()>1){
      for(const model::msc::MscFragmentRegionItem* region: fragmentItem->regions()){
        for(int i = 0; i < this->_d->_columnCount; i++){
          if(i==0){
            QVariant checkVariant;
            bool ok = QMetaObject::invokeMethod(drawArea,"createRegionStart", Q_RETURN_ARG(QVariant, checkVariant), Q_ARG(QVariant,region->uuid().toString()));
            QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
            Q_ASSERT(ok);
            Q_ASSERT(checkObject);
          }else if(i==this->_d->_columnCount - 1){
            QVariant checkVariant;
            bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
            QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
            Q_ASSERT(ok);
            Q_ASSERT(checkObject);
          }else{
            QVariant checkVariant;
            bool ok = QMetaObject::invokeMethod(drawArea,"createRegion",
                                                Q_RETURN_ARG(QVariant, checkVariant),
                                      Q_ARG(QVariant,"[" + region->name() + "]"),
                                      Q_ARG(QVariant,this->_d->_columnCount-2),
                                      Q_ARG(QVariant,this->_d->_regionTextColor));
            QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
            Q_ASSERT(ok);
            Q_ASSERT(checkObject);
            i = this->_d->_columnCount-2;
          }
        }
        for(const model::msc::MscSequenceItem* item: region->sequenceItems()){
          bool result = placeItem(item,errorString);
          if(!result)
            return false;
        }
        for(int i = 0; i < this->_d->_columnCount; i++){
          if(i==this->_d->_columnCount-1){
            QVariant checkVariant;
            bool ok = QMetaObject::invokeMethod(drawArea,"createRegionEnd", Q_RETURN_ARG(QVariant, checkVariant), Q_ARG(QVariant,region->uuid().toString()));
            QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
            Q_ASSERT(ok);
            Q_ASSERT(checkObject);
          }else{
            QVariant checkVariant;
            bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
            QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
            Q_ASSERT(ok);
            Q_ASSERT(checkObject);
          }
        }
      }
    }else{
      for(const model::msc::MscSequenceItem* item: fragmentItem->regions().first()->sequenceItems()){
        bool result = placeItem(item,errorString);
        if(!result)
          return false;
      }
    }

    for(int i = 0; i < this->_d->_columnCount; i++){
      if(i==this->_d->_columnCount-1){
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createFragmentEnd", Q_RETURN_ARG(QVariant, checkVariant), Q_ARG(QVariant,fragmentItem->uuid().toString()));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }else{
        QVariant checkVariant;
        bool ok = QMetaObject::invokeMethod(drawArea,"createSpacer", Q_RETURN_ARG(QVariant, checkVariant));
        QObject* checkObject = qvariant_cast<QObject*>(checkVariant);
        Q_ASSERT(ok);
        Q_ASSERT(checkObject);
      }
    }
  }
  return true;
}

void MscQuickWidget::countComponents()
{
  Q_ASSERT(this->_d->_mscSeq);

  this->_d->_compList=this->_d->_fixCompList;
  for(model::msc::MscComponentItem const* compItem : this->_d->_compList)
  {
    const model::msc::MscComponentItem::ConstPortSet& compPorts=compItem->ports();
    int portsCount=compPorts.size();

    for(model::msc::PortItem const* portItem : compItem->ports())
    {
      if(portItem == compItem->defaultPort()
         && portsCount>1)
        continue;

      if(!this->_d->_portList.contains(portItem))
        this->_d->_portList.append(portItem);
    }
  }

  for(model::msc::MscComponentItem const* compItem : this->_d->_mscSeq->componentItems())
  {
    this->_d->_compList.append(compItem);

    const model::msc::MscComponentItem::ConstPortSet& compPorts=compItem->ports();
    int portsCount=compPorts.size();
    for(model::msc::PortItem const* portItem : compItem->ports())
    {
      if(portItem == compItem->defaultPort()
         && portsCount>1)
        continue;
      if(!this->_d->_portList.contains(portItem))
        this->_d->_portList.append(portItem);
    }
  }

  return;

//  if(seq == nullptr){
//    for(const model::msc::MscComponentItem* compItem : this->_d->_mscSeq->componentItems()){
//      if(compItem){
//        if(this->_d->_compList.contains(compItem)==false){
//          this->_d->_compList.append(compItem);
//        }
//        for(model::msc::PortItem const* portItem : compItem->ports())
//        {
//          if(!this->_d->_portList.contains(portItem))
//            this->_d->_portList.append(portItem);
//        }
//      }
//    }
//    for(const model::msc::MscSequenceItem* seqItem : this->_d->_mscSeq->sequenceItems()){
//      countComponents(seqItem);
//    }
//  }else{
//    if(seq->stepType() == model::msc::MessageStep){
//      const model::msc::MscMessageItem* messageItem = static_cast<const model::msc::MscMessageItem*>(seq);
//      if(messageItem){
//        if(messageItem->sourcePort()){
//          if(model::msc::MscComponentItem const* compOwner=portOwnerComponent(messageItem->sourcePort())){
//            if(this->_d->_compList.contains(compOwner)==false){
//              this->_d->_compList.append(compOwner);
//            }
//            if(this->_d->_portList.contains(messageItem->sourcePort())==false){
//              this->_d->_portList.append(messageItem->sourcePort());
//            }
//          }
//        }
//        if(messageItem->targetPort()){
//          if(model::msc::MscComponentItem const* compOwner=portOwnerComponent(messageItem->targetPort())){
//            if(this->_d->_compList.contains(compOwner)==false){
//              this->_d->_compList.append(compOwner);
//            }
//            if(this->_d->_portList.contains(messageItem->targetPort())==false){
//              this->_d->_portList.append(messageItem->targetPort());
//            }
//          }
//        }
//      }
//    }
//    if(seq->stepType() == model::msc::CheckMessageStep){
//      const model::msc::MscCheckMessageItem* checkMessageItem = static_cast<const model::msc::MscCheckMessageItem*>(seq);
//      if(checkMessageItem){
//        if(checkMessageItem->sourcePort()){
//          if(model::msc::MscComponentItem const* compOwner=portOwnerComponent(checkMessageItem->sourcePort())){
//            if(this->_d->_compList.contains(compOwner)==false)
//              this->_d->_compList.append(compOwner);
//          }
//          this->_d->_portList.append(checkMessageItem->sourcePort());
//        }
//        if(checkMessageItem->targetPort()){
//          if(model::msc::MscComponentItem const* compOwner=portOwnerComponent(checkMessageItem->targetPort())){
//            if(this->_d->_compList.contains(compOwner)==false)
//              this->_d->_compList.append(compOwner);
//          }
//          this->_d->_portList.append(checkMessageItem->targetPort());
//        }
//      }
//    }
//    if(seq->stepType() == model::msc::StatementStep){
//      const model::msc::MscStatementItem* statementItem = static_cast<const model::msc::MscStatementItem*>(seq);
//      if(statementItem){
//        if(statementItem->component()){
//          if(this->_d->_compList.contains(statementItem->component())==false){
//            this->_d->_compList.append(statementItem->component());
//          }
//        }
//      }
//    }
//    if(seq->stepType() == model::msc::TimeoutStep){
//      const model::msc::MscTimeoutItem* TimeoutItem = static_cast<const model::msc::MscTimeoutItem*>(seq);
//      if(TimeoutItem){
//        if(TimeoutItem->component()){
//          if(this->_d->_compList.contains(TimeoutItem->component())==false){
//            this->_d->_compList.append(TimeoutItem->component());
//          }
//        }
//      }
//    }
//    if(seq->stepType() == model::msc::TimerStep){
//      const model::msc::MscTimerItem* TimerItem = static_cast<const model::msc::MscTimerItem*>(seq);
//      if(TimerItem){
//        if(TimerItem->component()){
//          if(this->_d->_compList.contains(TimerItem->component())==false){
//            this->_d->_compList.append(TimerItem->component());
//          }
//        }
//      }
//    }
//    if(seq->stepType() == model::msc::SleepTimerStep){
//      const model::msc::MscSleepTimerItem* SleepTimerItem = static_cast<const model::msc::MscSleepTimerItem*>(seq);
//      if(SleepTimerItem){
//        if(SleepTimerItem->component()){
//          if(this->_d->_compList.contains(SleepTimerItem->component())==false){
//            this->_d->_compList.append(SleepTimerItem->component());
//          }
//        }
//      }
//    }
//    if(seq->stepType() == model::msc::FragmentStep){
//      const model::msc::MscFragmentItem* item = static_cast<const model::msc::MscFragmentItem*>(seq);
//      if(item){
//        for(const model::msc::MscFragmentRegionItem* region : item->regions()){
//          if(region){
//            for(const model::msc::MscComponentItem* compItem : region->componentItems()){
//              if(compItem){
//                if(this->_d->_compList.contains(compItem)==false){
//                  this->_d->_compList.append(compItem);
//                }
//              }
//            }
//            for(const model::msc::MscSequenceItem* newSeq : region->sequenceItems()){
//              countComponents(newSeq);
//            }
//          }
//        }
//      }
//    }
//  }
}
//Zoom
void MscQuickWidget::zoomIn(){
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom){
    zoom->setProperty("xScale",qvariant_cast<double>(zoom->property("xScale"))+0.1);
    zoom->setProperty("yScale",qvariant_cast<double>(zoom->property("yScale"))+0.1);
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomOut(){
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom){
    zoom->setProperty("xScale",qvariant_cast<double>(zoom->property("xScale"))-0.1);
    zoom->setProperty("yScale",qvariant_cast<double>(zoom->property("yScale"))-0.1);
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomFitAll(){
  QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom && drawArea){
    zoom->setProperty("xScale",(1/drawArea->width())*this->_d->_rootObject->width());
    zoom->setProperty("yScale",(1/drawArea->width())*this->_d->_rootObject->width());
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomFitWidth(){
  QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom && drawArea){
    zoom->setProperty("xScale",(1/drawArea->width())*this->_d->_rootObject->width());
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomFitHeight(){
  QQuickItem* drawArea = this->_d->_rootObject->findChild<QQuickItem*>("drawArea");
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom && drawArea){
    zoom->setProperty("yScale",(1/drawArea->height())*this->_d->_rootObject->height());
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomYIn(){
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom){
    zoom->setProperty("yScale",qvariant_cast<double>(zoom->property("yScale"))+0.1);
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomYOut(){
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom){
    zoom->setProperty("yScale",qvariant_cast<double>(zoom->property("yScale"))-0.1);
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomXIn(){
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom){
    zoom->setProperty("xScale",qvariant_cast<double>(zoom->property("xScale"))+0.1);
  }else{
    qDebug()<<"nothing to zoom";
  }
}
void MscQuickWidget::zoomXOut(){
  QObject* zoom = this->_d->_rootObject->findChild<QObject*>("scale");
  if(zoom){
    zoom->setProperty("xScale",qvariant_cast<double>(zoom->property("xScale"))-0.1);
  }else{
    qDebug()<<"nothing to zoom";
  }
}

void MscQuickWidget::unhighlightAllGraphicItems()
{
  for(QObject* message : this->_d->_rootObject->findChildren<QObject*>("msc__arrow"))
    this->highlight(message,false);

  for(QObject* timer : this->_d->_rootObject->findChildren<QObject*>("msc__timer"))
    this->highlight(timer, false);

  for(QObject* statement : this->_d->_rootObject->findChildren<QObject*>("msc__statement"))
    this->highlight(statement, false);

  for(QObject* component : this->_d->_rootObject->findChildren<QObject*>("msc__component"))
    this->highlight(component, false);

  return;
}
//Highlight
void MscQuickWidget::highlightItemByUuid(const QUuid& uuid, const bool highlight)
{
  qDebug()<<uuid.toString();
  for(QObject* message : this->_d->_rootObject->findChildren<QObject*>("msc__arrow")){
    if(message->property("uuid")==uuid.toString()){
      this->highlight(message,highlight);
      return;
    }
  }
  for(QObject* timer : this->_d->_rootObject->findChildren<QObject*>("msc__timer")){
    if(timer->property("uuid")==uuid.toString()){
      this->highlight(timer,highlight);
      return;
    }
  }
  for(QObject* statement : this->_d->_rootObject->findChildren<QObject*>("msc__statement")){
    if(statement->property("uuid")==uuid.toString()){
      this->highlight(statement,highlight);
      return;
    }
  }
  for(QObject* component : this->_d->_rootObject->findChildren<QObject*>("msc__component")){
    if(component->property("uuid")==uuid.toString()){
      this->highlight(component,highlight);
      return;
    }
  }
}

void MscQuickWidget::highlightItemByName(const QString& name, const bool highlight)
{
  qDebug()<<name;
  for(QObject* message : this->_d->_rootObject->findChildren<QObject*>("msc__arrow")){
    if(message->property("label")==name){
      this->highlight(message,highlight);
      return;
    }
  }
  for(QObject* timer : this->_d->_rootObject->findChildren<QObject*>("msc__timer")){
    if(timer->property("label")==name){
      this->highlight(timer,highlight);
      return;
    }
  }
  for(QObject* statement : this->_d->_rootObject->findChildren<QObject*>("msc__statement")){
    if(statement->property("label")==name){
      this->highlight(statement,highlight);
      return;
    }
  }
  for(QObject* component : this->_d->_rootObject->findChildren<QObject*>("msc__component")){
    if(component->property("label")==name){
      this->highlight(component,highlight);
      return;
    }
  }
}

void MscQuickWidget::highlight(QObject* object, const bool highlight){
  if(object->objectName()=="msc__arrow"){
    if(highlight==true){
      object->setProperty("linecolor",this->_d->_highlightColor);
      return;
    }else{
      object->setProperty("linecolor",this->_d->_messageColor);
      return;
    }
  }else if(object->objectName()=="msc__timer"){
    if(highlight==true){
      object->setProperty("borderColor",this->_d->_highlightColor);
      return;
    }else{
      object->setProperty("borderColor",QColor("transparent"));
      return;
    }
  }else if(object->objectName()=="msc__statement"){
    if(highlight==true){
      object->setProperty("borderColor",this->_d->_highlightColor);
      return;
    }else{
      object->setProperty("borderColor",QColor("transparent"));
      return;
    }
  }else if(object->objectName()=="msc__component"){
    if(highlight==true){
      object->setProperty("borderColor",this->_d->_highlightColor);
      return;
    }else{
      object->setProperty("borderColor",QColor("transparent"));
      return;
    }
  }
}

//live create
bool MscQuickWidget::addMessage(const model::msc::PortItem* fromPort,
                const model::msc::PortItem* toPort,
                const QString& message,
                QString* errorString)
{
  if(!this->_d->_portList.contains(fromPort)){
    utils::AddPtrString(errorString)<<"SourcePort of message '"<<message<<"' not found";
    return false;
  }
  if(!this->_d->_portList.contains(toPort)){
    utils::AddPtrString(errorString)<<"TargetPort of message '"<<message<<"' not found";
    return false;
  }
  model::msc::MscMessageItem* newMessage = new model::msc::MscMessageItem(fromPort,toPort,message);
  if(!newMessage){
    utils::AddPtrString(errorString)<<"unable to create message '"<<message<<"'!";
    return false;
  }
  bool result = this->_d->_mscSeq->addMessage(newMessage);
  if(!result){
    utils::AddPtrString(errorString)<<"unable to add message '"<<message<<"'!";
    delete newMessage;
    return false;
  }
  result = this->placeItem(newMessage,errorString);
  if(!result){
    utils::AddPtrString(errorString)<<"unable to draw message '"<<message<<"'!";
    return false;
  }

  this->updateLifeLines();

  QObject* scrollbar = this->_d->_rootObject->findChild<QObject*>("zoomObject");
  if(scrollbar){
    int csize = qvariant_cast<int>(scrollbar->property("contentHeight"));
    int size = qvariant_cast<int>(scrollbar->property("height"));
    if(csize > size){
      scrollbar->setProperty("contentY", csize - size);
    }
  }

  return true;
}
bool MscQuickWidget::addMessage(const QUuid& fromPort,
                                const QUuid& toPort,
                                const QString& message,
                                QString* errorString)
{
  const model::base::PortItem* sourcePort = nullptr;
  const model::base::PortItem* targetPort = nullptr;
  for(const model::base::PortItem* port : this->_d->_portList){
    if(port->uuid()==fromPort)
      sourcePort = port;
    if(port->uuid()==toPort)
      targetPort = port;
  }
  return this->addMessage(sourcePort,targetPort,message,errorString);
}

bool MscQuickWidget::addStatement(const QUuid& component,
                                  const QString& statement,
                                  QString* errorString)
{
  const model::base::ModelItem* Source = nullptr;
  for(const model::base::ModelItem* comp : this->_d->_compList){
    if(comp->uuid()==component)
      Source = comp;
  }
  if(Source==nullptr){
    utils::AddPtrString(errorString)<<"Component not found";
    return false;
  }
  const model::msc::MscComponentItem* SourceComponent = dynamic_cast<const model::msc::MscComponentItem*>(Source);

  model::msc::MscStatementItem* newStatement = this->_d->_mscSeq->addStatement(SourceComponent,statement);
  if(!newStatement){
    utils::AddPtrString(errorString)<<"unable to add statement";
    return false;
  }
  bool result = this->placeItem(newStatement,errorString);
  if(!result){
    utils::AddPtrString(errorString)<<"unable to draw statement";
    return false;
  }
  QObject* scrollbar = this->_d->_rootObject->findChild<QObject*>("zoomObject");
  if(scrollbar){
    int csize = qvariant_cast<int>(scrollbar->property("contentHeight"));
    int size = qvariant_cast<int>(scrollbar->property("height"));
    if(csize > size){
      scrollbar->setProperty("contentY", csize - size);
    }
  }

  return true;
}
//Design
void MscQuickWidget::setComponentColor(const QColor& color){
  this->_d->_componentColor=color;
}
void MscQuickWidget::setComponentTextColor(const QColor& color){
  this->_d->_componentTextColor=color;
}
void MscQuickWidget::setComponentRadius(const int& radius){
  this->_d->_componentRadius=radius;
}
void MscQuickWidget::setStatementColor(const QColor& color){
  this->_d->_statementColor=color;
}
void MscQuickWidget::setStatementTextColor(const QColor& color){
  this->_d->_statementTextColor=color;
}
void MscQuickWidget::setStatementRadius(const int& radius){
  this->_d->_statementRadius=radius;
}
void MscQuickWidget::setTimerColor(const QColor& color){
  this->_d->_timerColor=color;
}
void MscQuickWidget::setTimerTextColor(const QColor& color){
  this->_d->_timerTextColor=color;
}
void MscQuickWidget::setTimerRadius(const int& radius){
  this->_d->_timerRadius=radius;
}
void MscQuickWidget::setTimeoutColor(const QColor& color){
  this->_d->_timeoutColor=color;
}
void MscQuickWidget::setTimeoutTextColor(const QColor& color){
  this->_d->_timeoutTextColor=color;
}
void MscQuickWidget::setTimeoutRadius(const int& radius){
  this->_d->_timeoutRadius=radius;
}
void MscQuickWidget::setSleeptimerColor(const QColor& color){
  this->_d->_sleeptimerColor=color;
}
void MscQuickWidget::setSleeptimerTextColor(const QColor& color){
  this->_d->_sleeptimerTextColor=color;
}
void MscQuickWidget::setSleeptimerRadius(const int& radius){
  this->_d->_sleeptimerRadius=radius;
}
void MscQuickWidget::setMessageColor(const QColor& color){
  this->_d->_messageColor=color;
}
void MscQuickWidget::setMessageTextColor(const QColor& color){
  this->_d->_messageTextColor=color;
}
void MscQuickWidget::setCheckmessageColor(const QColor& color){
  this->_d->_checkmessageColor=color;
}
void MscQuickWidget::setCheckmessageTextColor(const QColor& color){
  this->_d->_checkmessageTextColor=color;
}
void MscQuickWidget::setFragmentColor(const QColor& color){
  this->_d->_fragmentColor=color;
}
void MscQuickWidget::setFragmentTextColor(const QColor& color){
  this->_d->_fragmentTextColor=color;
}
void MscQuickWidget::setRegionColor(const QColor& color){
  this->_d->_regionColor=color;
}
void MscQuickWidget::setRegionTextColor(const QColor& color){
  this->_d->_regionTextColor=color;
}
void MscQuickWidget::setLifelineColor(const QColor& color){
  this->_d->_lifelineColor=color;
}
void MscQuickWidget::setBackgroundColor(const QColor& color){
  this->_d->_backgroundColor=color;
}
void MscQuickWidget::setHighlightColor(const QColor& color){
  this->_d->_highlightColor=color;
}
bool MscQuickWidget::savePicture(const QString& path){
  QPixmap pixmap(this->size());
  this->render(&pixmap);
  if (path == ""){
    QString location = QFileDialog::getSaveFileName(this,"Save Graphic","","Images(*.png)");
    bool success =  pixmap.save(location,nullptr,100);
    if (success == true)
      qDebug()<<"Image saved"<<location;
    else
      qDebug()<<"Error while image saving";
    return success;
  }else{
    bool success =  pixmap.save(path,nullptr,100);
    if (success == true)
      qDebug()<<"Image saved"<<path;
    else
      qDebug()<<"Error while image saving";
    return success;
  }
}
void MscQuickWidget::saveAsPicture(){
  this->savePicture("");
}

void MscQuickWidget::highlightGraphicItemByUuid(const QUuid& itemUuid,
                                                bool highlight,
                                                bool unhighlightOtherItems)
{
  if(unhighlightOtherItems){
    this->unhighlightAllGraphicItems();
  }
  this->highlightItemByUuid(itemUuid, highlight);
  return;
}

void MscQuickWidget::highlightGraphicItemsByUuids(const QList<QUuid>& itemUuids,
                                                  bool highlight,
                                                  bool unhighlightOtherItems)
{
  if(unhighlightOtherItems){
    this->unhighlightAllGraphicItems();
  }
  for(const QUuid& currItemUuid : itemUuids){
    this->highlightItemByUuid(currItemUuid, highlight);
  }
  return;
}

void MscQuickWidget::highlightGraphicItemByName(const QString& itemName,
                                                bool highlight,
                                                bool unhighlightOtherItems)
{
  if(unhighlightOtherItems)
    this->unhighlightAllGraphicItems();

  this->highlightItemByName(itemName, highlight);
  return;
}

void MscQuickWidget::highlightGraphicItemsByNames(const QList<QString> &itemNames,
                                                  bool highlight,
                                                  bool unhighlightOtherItems)
{
  if(unhighlightOtherItems){
    this->unhighlightAllGraphicItems();
  }
  for(const QString& currItemName : itemNames){
    this->highlightItemByName(currItemName, highlight);
  }
  return;
}

void MscQuickWidget::exportPlantUml(QSettings* settings)
{
  QString location = QFileDialog::getSaveFileName(this,"Save File","","Text(*.puml)");
  if(location == ""){
    return;
  }

  if(!location.endsWith(QLatin1String(".dot")))
    location.append(QLatin1String(".dot"));

  QString error = "";
  QString graphString = "";
  ComExportMscGraph exportGraph(this->_d->_mscSeq, &graphString);
  if(settings != nullptr)
    exportGraph.useSettings(settings);
  exportGraph.execute(&error);
  QFile file(location);
  if(file.open(QIODevice::ReadWrite)){
    QTextStream stream(&file);
    stream<<graphString;
  }else{
    qDebug()<<"could not write file";
    return;
  }
}

void MscQuickWidget::exportPlantUml()
{
  return this->exportPlantUml(nullptr);
}

void MscQuickWidget::contextMenuEvent(QContextMenuEvent* event){
  QMenu menu(this);
  QMenu* zoomMenu = menu.addMenu(QIcon(QLatin1String(":/mobata/images/zoomin_dark.png")),"zoom");
  QAction* zoomFullAction = zoomMenu->addAction(QIcon(QLatin1String(":/mobata/images/zoominview_dark.png")),"fit in view");
  QAction* zoomWidthAction = zoomMenu->addAction(QIcon(QLatin1String(":/mobata/images/zoomwidth_dark.png")),"fit to width");
  QAction* zoomHeightAction = zoomMenu->addAction(QIcon(QLatin1String(":/mobata/images/zoomheight_dark.png")),"fit to height");
  QObject::connect(zoomFullAction, &QAction::triggered,
                   this, &MscQuickWidget::zoomFitAll);
  QObject::connect(zoomWidthAction, &QAction::triggered,
                   this, &MscQuickWidget::zoomFitWidth);
  QObject::connect(zoomHeightAction, &QAction::triggered,
                   this, &MscQuickWidget::zoomFitHeight);
  QMenu* saveMenu = menu.addMenu(QIcon(QLatin1String(":/mobata/images/save_picture.png")),"save as image");
  //QAction* saveFull = saveMenu->addAction("save full graph");
  QAction* saveView = saveMenu->addAction(QIcon(QLatin1String(":/mobata/images/save_picture.png")),"save current view");
  QObject::connect(saveView, &QAction::triggered,
                   this, &MscQuickWidget::saveAsPicture);
  QAction* plantUmlAction = menu.addAction(QIcon(QLatin1String(":/mobata/images/export.png")),"export as plantuml");
  QObject::connect(plantUmlAction, &QAction::triggered,
                   this, QOverload<>::of(&MscQuickWidget::exportPlantUml));

  menu.exec(event->globalPos());
}
