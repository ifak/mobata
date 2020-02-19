#include "simruntime.hpp"

#include "simruntimeport.hpp"
#include "comscxmlwriter.hpp"

#include <mobata/model/base/signalitem.hpp>

#include <QScxmlStateMachine>
#include <QBuffer>
#include <QDebug>

namespace modsim {

SimRuntime::SimRuntime(const SimModel* simModel, QObject* parent)
  : QObject(parent), _simModel(simModel)
{
  Q_ASSERT(this->_simModel);
}

SimRuntime::~SimRuntime()
{
  qDeleteAll(this->_simRuntimePorts);
  delete this->_simModel;
}

const QString& SimRuntime::simModelAsName() const
{
  return this->_simModel->asName();
}

SimModel const* SimRuntime::simModel() const
{
  return this->_simModel;
}

const SimRuntime::SimRuntimePorts& SimRuntime::simRuntimePorts() const
{
  return this->_simRuntimePorts;
}

SimRuntimePort const* SimRuntime::simRuntimePort(const QString& portName) const
{
  for(SimRuntimePort const* simRuntimePort : this->_simRuntimePorts)
  {
    if(simRuntimePort->name()==portName)
      return simRuntimePort;
  }

  return nullptr;
}

SimRuntimePort const* SimRuntime::simRuntimePort(const quint32 portId) const
{
  for(SimRuntimePort const* simRuntimePort : this->_simRuntimePorts)
  {
    if(simRuntimePort->id()==portId)
      return simRuntimePort;
  }

  return nullptr;
}

////////SimScxmlRuntime/////////////////////////////
class SimScxmlRuntime::Private
{
  friend class SimScxmlRuntime;

  QScxmlStateMachine* _scxmlStateMachine = nullptr;
  QString             _skipEvent;

  Private()
    : _scxmlStateMachine(nullptr),
      _skipEvent(QLatin1String(""))
  {}
};

SimScxmlRuntime::SimScxmlRuntime(SimStateMachineModel const* simStateMachineModel,
                                 QObject* parent)
  : SimRuntime(simStateMachineModel, parent), _d(new Private)
{}

SimScxmlRuntime::~SimScxmlRuntime()
{
  delete this->_d->_scxmlStateMachine;
  delete this->_d;
}

SimStateMachineModel const* SimScxmlRuntime::simStateMachineModel() const
{
  return static_cast<SimStateMachineModel const*>(this->_simModel);
}

QString SimScxmlRuntime::runtimeDeclString() const
{
  return QString(QLatin1String("SCXML Runtime '%1': ")).arg(this->_simModel->asName());
}

bool SimScxmlRuntime::prepare(QString* errorString)
{
  SimStateMachineModel const* simStateMachineModel=this->simStateMachineModel();
  Q_ASSERT(simStateMachineModel);
  if(!simStateMachineModel->simModel())
  {
    utils::AddPtrString(errorString)<<"no state machine model available!";
    return false;
  }

  quint32 portId=0;
  for(const QString& portName : this->_simModel->portNames())
    this->_simRuntimePorts.append(new SimRuntimePort(this, portName, portId++));

  ComScxmlWriter writer(simStateMachineModel->simModel());
  bool result=writer.generateDomDocument();
  if(!result)
  {
    utils::AddPtrString(errorString)<<tr("error during creation of scxml state machine!");
    return false;
  }

  QBuffer buffer;
  buffer.open(QBuffer::ReadWrite);
  result = writer.writeScxml(&buffer,errorString);
  buffer.seek(0);
  if(!result)
    return false;

  this->_d->_scxmlStateMachine = QScxmlStateMachine::fromData(&buffer);
  if(!this->_d->_scxmlStateMachine)
  {
    utils::AddPtrString(errorString)<<tr("scxml state machine could not be created!");
    return false;
  }

  if(this->_d->_scxmlStateMachine->parseErrors().size())
  {
    utils::AddPtrString(errorString)<<tr("error during parsing of scxml state machine:");
    for(const QScxmlError& scxmlError : this->_d->_scxmlStateMachine->parseErrors())
      utils::AddPtrString(errorString)<<scxmlError.line()<<":"
                                     <<scxmlError.column()<<" "
                                    <<scxmlError.description();
    return false;
  }

  //receiving messages
  for(SimRuntimePort const* port : this->_simRuntimePorts)
    connect(port, &SimRuntimePort::receiveMessage,
            this, &SimScxmlRuntime::receiveMessage);

  //sending messages
  for(model::base::SignalItem const* signalItem
      : simStateMachineModel->simModel()->getSignals())
  {
    this->_d->_scxmlStateMachine->connectToEvent(signalItem->name(),
                                                 this,
                                                 &SimScxmlRuntime::sendMessage);
  }

  return true;
}

bool SimScxmlRuntime::start(QString* errorString)
{
  qDebug()<<this->runtimeDeclString()<<"start() executed!";

  if(!this->_d->_scxmlStateMachine)
  {
    utils::AddPtrString(errorString)<<this->runtimeDeclString()
                                   <<"no scxml state machine available, starting not possible!";
    return false;
  }

  this->_d->_scxmlStateMachine->start();

  return true;
}

bool SimScxmlRuntime::stop(QString* errorString)
{
  qDebug()<<this->runtimeDeclString()<<"stop() executed!";

  if(!this->_d->_scxmlStateMachine)
  {
    utils::AddPtrString(errorString)<<this->runtimeDeclString()
                                   <<"no scxml state machine available, stopping not possible!";
    return false;
  }

  this->_d->_scxmlStateMachine->stop();

  return true;
}

void SimScxmlRuntime::sendMessage(const QScxmlEvent& scxmlEvent)
{
  qDebug()<< this->runtimeDeclString()<<"sendMessage() executed!"
          <<" scxmlEvent name: "<<scxmlEvent.name()
         <<" scxmlEvent data: "<<scxmlEvent.data();

  if(scxmlEvent.name()==this->_d->_skipEvent)
  {
    this->_d->_skipEvent.clear();
    return;
  }
  Q_ASSERT(this->_d->_skipEvent.isEmpty());

  QString portIdParam(QLatin1String("P0rT_GuaRd"));
  QVariantMap eventData=scxmlEvent.data().toMap();
  if(!eventData.contains(portIdParam))
  {
    emit this->error(QStringList()<<this->runtimeDeclString()
                     <<tr("event data contains parameter value for '%1'!")
                     .arg(portIdParam));
    return;
  }

  bool result;
  quint32 portId=eventData.value(portIdParam).toInt(&result);
  if(!result)
  {
    emit this->error(QStringList()<<this->runtimeDeclString()
                     <<tr("param value of '%1' is not an integer value!")
                     .arg(portIdParam));
    return;
  }

  SimRuntimePort const* sendRuntimePort=this->simRuntimePort(portId);
  if(!sendRuntimePort)
  {
    emit this->error(QStringList()<<this->runtimeDeclString()
                     <<tr("no port for port id '%1' available!")
                     .arg(portId));
    return;
  }

  eventData.remove(portIdParam);
  emit const_cast<SimRuntimePort*>(sendRuntimePort)->sendMessage(scxmlEvent.name(), eventData);

  return;
}

void SimScxmlRuntime::receiveMessage(const QString& messageName, const QVariantMap& messageData)
{
  qDebug()<< this->runtimeDeclString()<<"receiveMessage() executed!"
          <<" messageName: "<<messageName
         <<" messageData: "<<messageData;

  if(!this->_d->_scxmlStateMachine)
    return;

  SimRuntimePort const* receivedPort=qobject_cast<SimRuntimePort const*>(this->sender());
  if(!receivedPort)
    return;

  this->_d->_skipEvent=messageName;

  QVariantMap portMessageData=messageData;
  portMessageData.insert(QLatin1String("P0rT_GuaRd"), receivedPort->id());
  this->_d->_scxmlStateMachine->submitEvent(messageName, portMessageData);

  return;
}

} // namespace modsim
