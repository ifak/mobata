#include "simconfigitem.hpp"

#include <mobata/utils/functors.hpp>

namespace modsim{

class SimActorItem::Private
{
  friend class SimActorItem;

  QStringList _portNames;

  Private()
  {}
};

SimActorItem::SimActorItem(const QString &name)
  : prop::NameProperty(name), _d(new Private)
{}

SimActorItem::~SimActorItem()
{
  delete  this->_d;
}

const QStringList& SimActorItem::portNames() const
{
  return  this->_d->_portNames;
}

bool SimActorItem::addPort(const QString &portName, QString *errorString)
{
  if(this->_d->_portNames.contains(portName))
  {
    utils::AddPtrString(errorString)<<"port with name '"<<portName<<"' is still available for this actor!";
    return  false;
  }

  this->_d->_portNames.append(portName);

  return  true;
}

class SimMessageItem::Private{
  friend class SimMessageItem;

  QString       _signalName;

  QString       _sourceModel;
  QString       _sourcePort;
  QString       _targetModel;
  QString       _targetPort;
  QVariantList  _messageData;

  explicit Private(const QString& signalName)
    : _signalName(signalName)
  {}
};

SimMessageItem::SimMessageItem(const QString& signalName)
  : _d(new Private(signalName))
{}

SimMessageItem::~SimMessageItem()
{
  delete this->_d;
}

void SimMessageItem::setSource(const QString& sourceModelName,
                               const QString& sourcePortName)
{
  this->_d->_sourceModel=sourceModelName;
  this->_d->_sourcePort=sourcePortName;

  return;
}

const QString& SimMessageItem::sourceModel() const
{
  return  this->_d->_sourceModel;
}

const QString& SimMessageItem::sourcePort() const
{
  return  this->_d->_sourcePort;
}

void SimMessageItem::setTarget(const QString& targetModelName,
                               const QString& targetPortName)
{
  this->_d->_targetModel=targetModelName;
  this->_d->_targetPort=targetPortName;

  return;
}

const QString& SimMessageItem::targetModel() const
{
  return  this->_d->_targetModel;
}

const QString& SimMessageItem::targetPort() const
{
  return  this->_d->_targetPort;
}

const QString& SimMessageItem::signalName() const
{
  return  this->_d->_signalName;
}

const QVariantList& SimMessageItem::messageData() const
{
  return  this->_d->_messageData;
}

void SimMessageItem::setMessageData(const QVariantList &messageData)
{
  this->_d->_messageData=messageData;

  return;
}

class SimConfigItem::Private{
  friend class SimConfigItem;

  QStringList     _startModelSequence;
  QStandardItem*  _startSequenceItem;

  SimActorSet     _actors;
  SimMessageSet   _startupMessages;

  Private()
    : _startSequenceItem(new QStandardItem)
  {}
};

SimConfigItem::SimConfigItem():
  model::base::ModelItem(),
  _d(new Private)
{
  setText(QString("Configurations"));
  appendRow(_d->_startSequenceItem);
}

SimConfigItem::~SimConfigItem()
{
  qDeleteAll(this->_d->_actors);
  qDeleteAll(this->_d->_startupMessages);
  delete _d;
}

const SimConfigItem::SimActorSet& SimConfigItem::simActors() const
{
  return  this->_d->_actors;
}

bool SimConfigItem::addSimActor(SimActorItem* simActor,
                                QString *errorString)
{
  if(!simActor)
    return  false;

  if(this->simActor(simActor->name()))
  {
    utils::AddPtrString(errorString)<<"actor with name '"<<simActor->name()
                                   <<"' still available!";
    return  false;
  }

  this->_d->_actors.append(simActor);

  return true;
}

SimActorItem const* SimConfigItem::simActor(const QString& simActorName) const
{
  for(SimActorItem const* currActor : this->_d->_actors)
  {
    if(currActor->name()==simActorName)
      return  currActor;
  }

  return  nullptr;
}

const SimConfigItem::SimMessageSet& SimConfigItem::startupMessages() const
{
  return  this->_d->_startupMessages;
}

void SimConfigItem::addStartupMessage(SimMessageItem *simMessage)
{
  if(!simMessage)
    return;

  this->_d->_startupMessages.append(simMessage);

  return;
}

const QStringList& SimConfigItem::startSequence() const
{
  return _d->_startModelSequence;
}

/*!
 * \brief SimConfigItem::addStartSequenceModel for adding model to the start sequence.
 * here it is assumed, that \a modelName is available!
 * \param modelName name of the start sequence model
 * \param errorString error description
 * \return succesful or not
 */
bool SimConfigItem::addStartSequenceModel(const QString& modelName,
                                          QString* errorString)
{
  if(this->_d->_startModelSequence.contains(modelName))
  {
    utils::AddPtrString(errorString)<<"model '"
                                   <<modelName
                                  <<"' is already available in start sequence!";
    return false;
  }

  this->_d->_startModelSequence.append(modelName);

  QString res = _d->_startModelSequence[0];
  for(int i(1); i<_d->_startModelSequence.size(); ++i){
    res += QString(", %0").arg(_d->_startModelSequence[i]);
  }
  _d->_startSequenceItem->setText(QString("startSequence: %0").arg(res));

  return true;
}

}//namespace modsim
