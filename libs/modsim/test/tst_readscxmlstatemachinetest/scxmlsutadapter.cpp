#include "scxmlsutadapter.hpp"

#include "mobata/model/statemachine/statemachine.hpp"
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <QScxmlStateMachine>

#include <QDebug>

class ScxmlSutAdapter::Private
{
  friend class ScxmlSutAdapter;

  QScxmlStateMachine*                     _machine;
  model::statemachine::StateMachineModel* _model;
  const QString                           _portGuardParamName;
  QString                                 _skipEvent = QString("");

  Private(QScxmlStateMachine* machine,
          model::statemachine::StateMachineModel* model)
    : _machine(machine),_model(model),
      _portGuardParamName("P0rT_GuaRd")
  {}
};

ScxmlSutAdapter::ScxmlSutAdapter(QScxmlStateMachine* machine,
                                 model::statemachine::StateMachineModel* model,
                                 QObject* parent)
  : QObject(parent),_d(new Private(machine,model))
{
  Q_ASSERT(this->_d->_machine);
  Q_ASSERT(this->_d->_model);

  for(model::base::SignalItem* signalItem : model->getSignals()){
    machine->connectToEvent(signalItem->name(),this,&ScxmlSutAdapter::messageFromScxml);
  }

  connect(this, &ScxmlSutAdapter::submitScxmlEvent,this,
          [=](const QString& name, const QVariantMap& map){
    _d->_machine->submitEvent(name,map);
  }, Qt::QueuedConnection);
}

ScxmlSutAdapter::~ScxmlSutAdapter()
{
  delete this->_d;
}

void ScxmlSutAdapter::connectToEvent(QString eventName)
{
  _d->_machine->connectToEvent(eventName,this,&ScxmlSutAdapter::messageFromScxml);
}

void ScxmlSutAdapter::start()
{
  _d->_machine->init();
  _d->_machine->start();
}

void ScxmlSutAdapter::messageToScxml(const QString& messageName,
                                     const QString& portName,
                                     const QVariantMap& paramValues,
                                     const QUuid& messageID)
{
  qDebug()<<"ScxmlSutAdapter::messageToScxml() executed: "<<messageName;

  model::base::SignalItem* sigItem =_d->_model->signal(messageName);
  if(!sigItem)
  {
    QString errorString=QString("there is no signal with name '%1' available").arg(messageName);
    emit this->errors(QStringList()<<errorString);
    emit messageSent(messageID,false,errorString);
    return;
  }

  QVariantMap paramData=paramValues;

  int portIndex=-1;
  int pos=0;
  for(model::base::PortItem const* portItem : this->_d->_model->ports())
  {
    if(portItem->name()==portName)
    {
      portIndex=pos;
      break;
    }
    ++pos;
  }

  if(!portName.isEmpty() && portIndex==-1)
  {
    QString errorString=QString("there is no port with name '%1' within state machine model '%2' available!")
                        .arg(portName).arg(this->_d->_model->name());
    emit this->errors(QStringList()<<errorString);
    emit messageSent(messageID,false,errorString);
    return;
  }

  if(portIndex>=0)
    paramData.insert(this->_d->_portGuardParamName, portIndex);

  this->_d->_skipEvent = messageName;

//  QStringList localActiveStateNames = _d->_machine->activeStateNames();

  emit submitScxmlEvent(messageName,paramData);
  emit messageSent(messageID,true);

  return;
}

void ScxmlSutAdapter::messageFromScxml(const QScxmlEvent &event)
{
  qDebug()<<"ScxmlSutAdapter::messageFromScxml() executed: "<<event.name();

  const QString& eventName = event.name();

  if(eventName == this->_d->_skipEvent)
  {
    this->_d->_skipEvent = QString("");
    return;
  }

  QString portName("");
  QVariantMap paramData=event.data().toMap();
  if(paramData.contains(this->_d->_portGuardParamName))
  {
    bool success=false;
    int portIndex=paramData.value(_d->_portGuardParamName).toInt(&success);
    Q_ASSERT(success);
    Q_ASSERT(portIndex<this->_d->_model->ports().size());

    model::base::PortItem const* portItem=this->_d->_model->ports().at(portIndex);
    Q_ASSERT(portItem);

    portName=portItem->name();
    Q_ASSERT(!portName.isEmpty());

    paramData.remove(this->_d->_portGuardParamName);
  }
  emit messageReceived(eventName,portName, paramData);

  return;
}
