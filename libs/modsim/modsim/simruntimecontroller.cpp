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

#include "simruntimecontroller.hpp"

#include "simmodel.hpp"
#include "simmodelworker.hpp"
#include "simruntimeport.hpp"

#include <QList>
#include <QThread>
#include <QDebug>

namespace modsim {

struct ModelWorkerThread
{
  SimModelWorker* modelWorker;

  ModelWorkerThread(SimModelWorker* mWorker)
    : modelWorker(mWorker)
  {
    Q_ASSERT(this->modelWorker);
  }
};

struct Link
{
  SimModel const* sourceModel;
  QString         sourceModelPort;
  SimModel const* targetModel;
  QString         targetModelPort;

  Link()
    : sourceModel(nullptr), sourceModelPort(QLatin1String("")),
      targetModel(nullptr), targetModelPort(QLatin1String(""))
  {}

  Link(SimModel const* sourceSimModel,
       const QString& sourceSimModelPort,
       SimModel const* targetSimModel,
       const QString& targetSimModelPort)
    : sourceModel(sourceSimModel), sourceModelPort(sourceSimModelPort),
      targetModel(targetSimModel), targetModelPort(targetSimModelPort)
  {
    Q_ASSERT(this->sourceModel);
    Q_ASSERT(this->targetModel);
  }
};

typedef QVector<SimModel*>      SimModelSet;
typedef QVector<Link>           LinkSet;
typedef dslparser::DslErrorList ErrorSet;

enum ControllerState
{
  Init,
  Prepared,
  Started,
  Stopped,
  Finished,
  Error
};

class SimRuntimeController::Private
{
  friend class SimRuntimeController;

  //for declaration
  SimModelSet _simModels;
  LinkSet     _links;
  QStringList _startModelSequence;

  //for runtime
  QList<ModelWorkerThread>  _workerThreads;
  ControllerState           _controllerState;
  QStringList               _errorMessages;
  QList<ModelWorkerThread>  _openWorkerThreads;

  Private()
    : _controllerState(Init)
  {}

  SimModel const*       simModel(const QString& asName);
  SimRuntimePort const* simRuntimePort(const QString& simModelAsName,
                                       const QString& portName);
  Link const*           link(const QString& simModelAsName,
                             const QString& portName);

  //for running////
  void resetRuntime();
};

SimModel const* SimRuntimeController::Private::simModel(const QString& asName)
{
  for(SimModel const* simModel : this->_simModels)
  {
    if(simModel->asName() == asName)
      return simModel;
  }

  return nullptr;
}

SimRuntimePort const* SimRuntimeController::Private::simRuntimePort(const QString& simModelAsName,
                                                                    const QString& portName)
{
  for(ModelWorkerThread& workerThread : this->_workerThreads)
  {
    SimModelWorker* simModelWorker = workerThread.modelWorker;
    Q_ASSERT(simModelWorker);
    if(simModelWorker->simModelAsName()!=simModelAsName)
      continue;

    return (simModelWorker->simRuntimePort(portName));//only simModels with unique as-names
  }

  return nullptr;
}

Link const* SimRuntimeController::Private::link(const QString& simModelAsName,
                                                const QString& portName)
{
  for(const Link& currentLink : this->_links)
  {
    if(currentLink.sourceModel->asName()==simModelAsName
       && currentLink.sourceModelPort==portName)
      return &currentLink;

    if(currentLink.targetModel->asName()==simModelAsName
       && currentLink.targetModelPort==portName)
      return &currentLink;
  }

  return nullptr;
}

void SimRuntimeController::Private::resetRuntime()
{
  qDebug()<<"SimRuntimeController::Private::resetRuntime() executed!";

  for(ModelWorkerThread& modelWorkerThread : this->_workerThreads)
  {
    modelWorkerThread.modelWorker->disconnect();

    delete modelWorkerThread.modelWorker;
    modelWorkerThread.modelWorker=nullptr;
  }
  this->_workerThreads.clear();

  this->_errorMessages.clear();

  return;
}

///SimRuntimeController////////////
SimRuntimeController::SimRuntimeController(QObject* parent)
  : QObject(parent), _d(new Private)
{}

SimRuntimeController::~SimRuntimeController()
{
  this->_d->resetRuntime();
  delete this->_d;
}

bool SimRuntimeController::addSimModel(const QString& simModelText,
                                       const QString& simModelAsName,
                                       const SimModelType simModelType,
                                       QString* errorString)
{
  if(this->_d->simModel(simModelAsName))
  {
    utils::AddPtrString(errorString)<<"simulation model with as-model-name: '"
                                   <<simModelAsName
                                  <<"' already available!";
    return false;
  }

  //building sim model
  SimModel* newSimModel=nullptr;
  if(simModelType==SpenatModel)
  {
    newSimModel=new SimSpenatModel(simModelText, simModelAsName);
    bool result=newSimModel->rebuildSimModel(errorString);
    if(!result)
    {
      for(const dslparser::DslError& dslError : newSimModel->errors())
      {
        QString errorMessage(tr("%1:%2:%3")
                             .arg(dslError.line())
                             .arg(dslError.charPositionInLine())
                             .arg(dslError.message()));
        this->_d->_errorMessages.append(errorMessage);
      }

      delete newSimModel;
      newSimModel=nullptr;
      return false;
    }
  }
  else if(simModelType==StateMachineModel)
  {
    newSimModel=new SimStateMachineModel(simModelText, simModelAsName);
    bool result=newSimModel->rebuildSimModel(errorString);
    if(!result)
    {
      for(const dslparser::DslError& dslError : newSimModel->errors())
      {
        QString errorMessage(tr("%1:%2:%3")
                             .arg(dslError.line())
                             .arg(dslError.charPositionInLine())
                             .arg(dslError.message()));
        this->_d->_errorMessages.append(errorMessage);
      }

      delete newSimModel;
      newSimModel=nullptr;
      return false;
    }
  }
  else
  {
    utils::AddPtrString(errorString)<< tr("only state machine models are currently supported for model simulation!");
    return false;
  }

  Q_ASSERT(newSimModel);
  this->_d->_simModels.append(newSimModel);

  return true;
}

bool SimRuntimeController::addLink(const QString& sourceModelAsName, const QString& sourcePort,
                                   const QString& targetModelAsName, const QString& targetPort,
                                   QString* errorString)
{
  SimModel const* sourceSimModel=this->_d->simModel(sourceModelAsName);
  if(!sourceSimModel)
  {
    utils::AddPtrString(errorString)<<"no simulation model with as-name '"
                                   <<sourceModelAsName<<"' available!";
    return false;
  }

  SimModel const* targetSimModel=this->_d->simModel(targetModelAsName);
  if(!targetSimModel)
  {
    utils::AddPtrString(errorString)<<"no simulation model with as-name '"
                                   <<targetModelAsName<<"' available!";
    return false;
  }

  this->_d->_links.append(Link(sourceSimModel, sourcePort,
                               targetSimModel, targetPort));

  return true;
}

void SimRuntimeController::setStartModelSequence(const QStringList& startModelSequence)
{
  this->_d->_startModelSequence=startModelSequence;

  return;
}

void SimRuntimeController::prepare()
{
  qDebug()<<"SimRuntimeController::prepare() executed!";

  this->_d->resetRuntime();

  for(SimModel* simModel : this->_d->_simModels)
  {
    SimModelWorker* newModelWorker=new SimModelWorker(simModel);

    this->_d->_workerThreads.append(ModelWorkerThread(newModelWorker));

    connect(this, &SimRuntimeController::prepareWorker,
            newModelWorker, &SimModelWorker::prepare,
            Qt::QueuedConnection);
    connect(newModelWorker, &SimModelWorker::prepared,
            this, &SimRuntimeController::preparedWorker,
            Qt::QueuedConnection);

    connect(this, &SimRuntimeController::startWorker,
            newModelWorker, &SimModelWorker::start,
            Qt::QueuedConnection);
    connect(newModelWorker, &SimModelWorker::started,
            this, &SimRuntimeController::startedWorker,
            Qt::QueuedConnection);

    connect(this, &SimRuntimeController::stopWorker,
            newModelWorker, &SimModelWorker::stop,
            Qt::QueuedConnection);
    connect(newModelWorker, &SimModelWorker::stopped,
            this, &SimRuntimeController::stoppedWorker,
            Qt::QueuedConnection);
  }

  for(ModelWorkerThread& modelWorkerThread : this->_d->_workerThreads)
    this->_d->_openWorkerThreads.append(modelWorkerThread);
  emit this->prepareWorker(QPrivateSignal());

  return;
}

void SimRuntimeController::start()
{
  //  qDebug()<<"SimRuntimeController::start() executed!";

  if(this->_d->_controllerState == Started)
  {
    emit started(false,
                 QStringList()<<tr("simulation controller is already started!"));
    return;
  }
  else if(this->_d->_controllerState != Prepared)
  {
    emit started(false,
                 QStringList()<<tr("simulation controller is not prepared, cannot be started!"));
    return;
  }

  Q_ASSERT(this->_d->_openWorkerThreads.isEmpty());

  for(ModelWorkerThread& modelWorkerThread : this->_d->_workerThreads)
    this->_d->_openWorkerThreads.append(modelWorkerThread);
  emit this->startWorker(QPrivateSignal());

  return;
}

void SimRuntimeController::stop()
{
  qDebug()<<"SimRuntimeController::stop() executed!";

  if(this->_d->_controllerState != Started)
  {
    emit stopped(false,
                 QStringList()<<tr("simulation controller is not started yet!"));
    return;
  }

  Q_ASSERT(this->_d->_openWorkerThreads.isEmpty());

  for(ModelWorkerThread& modelWorkerThread : this->_d->_workerThreads)
    this->_d->_openWorkerThreads.append(modelWorkerThread);
  emit this->stopWorker(QPrivateSignal());

  return;
}

void SimRuntimeController::preparedWorker(bool result, const QStringList& messages)
{
  qDebug()<<"SimRuntimeController::preparedWorker() executed!"
         <<"result: '"<<result<<"' messages: '"<<messages<<"'";

  SimModelWorker* preparedSimModelWorker = qobject_cast<SimModelWorker*>(this->sender());
  if(!preparedSimModelWorker)
    return;

  if(!result)
  {
    this->_d->_errorMessages.append(messages);
    emit this->prepared(false, this->_d->_errorMessages);

    this->_d->resetRuntime();
    return;
  }

  //connect sim model ports to this runtime controller
  for(SimRuntimePort const* simRuntimePort : preparedSimModelWorker->simRuntimePorts())
    connect(simRuntimePort, &SimRuntimePort::sendMessage,
            this, &SimRuntimeController::receiveModelMessage,
            Qt::QueuedConnection);

  int pos=0;
  for(ModelWorkerThread& openWorkerThread : this->_d->_openWorkerThreads)
  {
    if(openWorkerThread.modelWorker == preparedSimModelWorker)
    {
      this->_d->_openWorkerThreads.removeAt(pos);
      break;
    }
    ++pos;
  }

  if(!this->_d->_openWorkerThreads.isEmpty())
    return;

  //connect links between ports...
  for(const Link& link : this->_d->_links)
  {
    SimRuntimePort const* sourceRuntimePort = this->_d->simRuntimePort(link.sourceModel->asName(),
                                                                       link.sourceModelPort);
    if(!sourceRuntimePort)
    {
      QString errorString = tr("source model '%1' has no runtime port '%2'!")
                            .arg(link.sourceModel->asName(), link.sourceModelPort);
      this->_d->_errorMessages.append(errorString);
      emit this->prepared(false, this->_d->_errorMessages);

      this->_d->resetRuntime();
      return;
    }

    SimRuntimePort const* targetRuntimePort = this->_d->simRuntimePort(link.targetModel->asName(),
                                                                       link.targetModelPort);
    if(!targetRuntimePort)
    {
      QString errorString = tr("target model '%1' has no runtime port '%2'!")
                            .arg(link.targetModel->asName(), link.targetModelPort);
      this->_d->_errorMessages.append(errorString);
      emit this->prepared(false, this->_d->_errorMessages);

      this->_d->resetRuntime();
      return;
    }

    connect(sourceRuntimePort, &SimRuntimePort::sendMessage,
            targetRuntimePort, &SimRuntimePort::receiveMessage,
            Qt::QueuedConnection);
    connect(targetRuntimePort, &SimRuntimePort::sendMessage,
            sourceRuntimePort, &SimRuntimePort::receiveMessage,
            Qt::QueuedConnection);
  }

  this->_d->_controllerState = Prepared;
  emit this->prepared(true, QStringList()<<tr("simulation controller was successfully prepared!"));

  return;
}

void SimRuntimeController::startedWorker(bool result, const QStringList& messages)
{
  qDebug()<<"SimRuntimeController::startedWorker() executed!"
         <<"result: '"<<result<<"' messages: '"<<messages<<"'";

  SimModelWorker* startedSimModelWorker = qobject_cast<SimModelWorker*>(this->sender());
  if(!startedSimModelWorker)
    return;

  if(!result)
  {
    this->_d->_errorMessages.append(messages);
    emit this->started(false, this->_d->_errorMessages);

    this->_d->resetRuntime();

    return;
  }

  int pos=0;
  for(ModelWorkerThread& openWorkerThread : this->_d->_openWorkerThreads)
  {
    if(openWorkerThread.modelWorker == startedSimModelWorker)
    {
      this->_d->_openWorkerThreads.removeAt(pos);
      break;
    }
    ++pos;
  }

  if(!this->_d->_openWorkerThreads.isEmpty())
    return;

  this->_d->_controllerState = Started;
  emit this->started(true, QStringList()<<tr("simulation controller was successfully started!"));

  return;
}

void SimRuntimeController::stoppedWorker(bool result, const QStringList& messages)
{
  qDebug()<<"SimRuntimeController::stoppedWorker() executed!"
         <<"result: '"<<result<<"' messages: '"<<messages<<"'";

  SimModelWorker* stoppedSimModelWorker = qobject_cast<SimModelWorker*>(this->sender());
  if(!stoppedSimModelWorker)
    return;

  if(!result)
  {
    this->_d->_errorMessages.append(messages);
    emit this->stopped(false, this->_d->_errorMessages);

    this->_d->resetRuntime();

    return;
  }

  int pos=0;
  for(ModelWorkerThread& openWorkerThread : this->_d->_openWorkerThreads)
  {
    if(openWorkerThread.modelWorker == stoppedSimModelWorker)
    {
      this->_d->_openWorkerThreads.removeAt(pos);
      break;
    }
    ++pos;
  }

  if(!this->_d->_openWorkerThreads.isEmpty())
    return;

  this->_d->_controllerState = Stopped;
  emit this->stopped(true, QStringList()<<tr("simulation controller was successfully stopped!"));

  return;
}

void SimRuntimeController::receiveModelMessage(const QString& messageName,
                                               const QVariantMap& messageData)
{
  qDebug()<<"SimRuntimeController::receiveModelMessage() executed!"
         <<"messageName: '"<<messageName<<"' messageData: '"<<messageData<<"'";

  SimRuntimePort* sendingRuntimePort = qobject_cast<SimRuntimePort*>(this->sender());
  if(!sendingRuntimePort)
    return;

  SimRuntime const* portRuntime=sendingRuntimePort->simRuntime();
  Q_ASSERT(portRuntime);

  Link const* link=this->_d->link(portRuntime->simModel()->asName(),
                                  sendingRuntimePort->name());
  if(link)
  {//internal message between runtime models
    if(link->sourceModel==portRuntime->simModel())
      emit this->observedMessage(portRuntime->simModelAsName(),sendingRuntimePort->name(),
                                 link->targetModel->asName(), link->targetModelPort,
                                 messageName, messageData);
    else
      emit this->observedMessage(portRuntime->simModelAsName(),sendingRuntimePort->name(),
                                 link->sourceModel->asName(), link->sourceModelPort,
                                 messageName, messageData);
  }
  else
  {//send extern message
    emit this->sendExternMessage(portRuntime->simModelAsName(),sendingRuntimePort->name(),
                                 messageName, messageData);
  }

  return;
}

void SimRuntimeController::receiveExternMessageSlot(const QString &modelAsName, const QString &portName,
                                                    const QString &messageName, const QVariantMap &messageData)
{
  qDebug()<<"SimRuntimeController::receiveExternMessageSlot() executed!"
         <<"modelAsName: '"<<modelAsName<<"' portName: '"<<portName<<"'"
        <<"messageName: '"<<messageName<<"' messageData: '"<<messageData<<"'";

  SimRuntimePort const* simRuntimePort = this->_d->simRuntimePort(modelAsName, portName);
  if(!simRuntimePort)
  {
    emit this->errors(QStringList()<<tr("no port '%1' for model '%2' found! message '%3'"
                                        " cannot be sent to model!")
                      .arg(portName).arg(modelAsName).arg(messageName));
    return;
  }

  emit const_cast<SimRuntimePort*>(simRuntimePort)->receiveMessage(messageName, messageData);
  emit this->receivedExternMessage(modelAsName, portName, messageName, messageData);//for extern logging purposes

  return;
}

} // namespace modsim
