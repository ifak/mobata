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

#include "simmodelworker.hpp"

#include "simmodel.hpp"
#include "simruntime.hpp"
#include "simruntimeport.hpp"

#include <QDebug>

namespace modsim {

class SimModelWorker::Private
{
  friend class SimModelWorker;

  SimModel*   _simModel = nullptr;
  SimRuntime* _simRuntime = nullptr;

  Private(SimModel* simModel)
    : _simModel(simModel)
  {}

  QString workerDeclString() const;
};

QString SimModelWorker::Private::workerDeclString() const
{
  return QString(QLatin1String("Sim Model Worker '%1': ")).arg(this->_simModel->asName());
}

SimModelWorker::SimModelWorker(SimModel* simModel,
                               QObject* parent)
  : QObject(parent), _d(new Private(simModel))
{
  Q_ASSERT(this->_d->_simModel);
}

SimModelWorker::~SimModelWorker()
{
  delete this->_d->_simRuntime;
  delete this->_d;
}

const QString& SimModelWorker::simModelAsName() const
{
  return this->_d->_simModel->asName();
}

SimRuntimePort const* SimModelWorker::simRuntimePort(const QString &portName) const
{
  if(!this->_d->_simRuntime)
    return nullptr;

  return this->_d->_simRuntime->simRuntimePort(portName);
}

const SimModelWorker::SimRuntimePorts& SimModelWorker::simRuntimePorts() const
{
  return this->_d->_simRuntime->simRuntimePorts();
}

void SimModelWorker::prepare()
{
  qDebug()<<this->_d->workerDeclString()<<"prepare() executed!";

  delete this->_d->_simRuntime;
  this->_d->_simRuntime=nullptr;

  QString errorString;
  bool result = this->_d->_simModel->rebuildSimModel(&errorString);
  if(!result)
  {
    QStringList errors;
    if(!errorString.isEmpty())
      errors<<errorString;

    for(const dslparser::DslError& dslError : this->_d->_simModel->errors())
      errors<<dslError.message();

    emit this->prepared(false, errors);
    return;
  }

  if(this->_d->_simModel->simModelType()==StateMachineModel)
  {
    SimStateMachineModel const* simStateMachineModel = static_cast<SimStateMachineModel const*>(this->_d->_simModel);
    Q_ASSERT(simStateMachineModel);
    this->_d->_simRuntime=new SimScxmlRuntime(simStateMachineModel);
  }
  else
  {
    QString errorString = tr("only state machine models are currently supported for model simulation!");
    emit this->prepared(false, QStringList()<<errorString);
    return;
  }
  Q_ASSERT(this->_d->_simRuntime);

  result = this->_d->_simRuntime->prepare(&errorString);
  if(!result)
  {
    QStringList errors;
    if(!errorString.isEmpty())
      errors<<errorString;

    emit this->prepared(false, errors);
    return;
  }

  emit this->prepared(true);

  return;
}

void SimModelWorker::start()
{
  qDebug()<<this->_d->workerDeclString()<<"start() executed!";

  if(!this->_d->_simRuntime)
  {
    QString errorMessage(this->_d->workerDeclString());
    errorMessage+="no simulation runtime for starting available, before you 'start()', "
                  "you have to 'prepare()' this simulation model worker!";
    emit this->started(false, QStringList()<<errorMessage);
    return;
  }

  QString errorString;
  bool result = this->_d->_simRuntime->start(&errorString);
  if(!result)
  {
    emit this->started(false, QStringList()<<errorString);
    return;
  }

  emit this->started(true);

  return;
}

void SimModelWorker::stop()
{
  qDebug()<<this->_d->workerDeclString()<<"stop() executed!";

  if(!this->_d->_simRuntime)
  {
    QString errorMessage(this->_d->workerDeclString());
    errorMessage+="no simulation runtime for stopping available. Before you 'stop()' and 'start()', "
                  "you have to 'prepare()' this simulation model worker!";
    emit this->stopped(false, QStringList()<<errorMessage);
    return;
  }

  QString errorString;
  bool result = this->_d->_simRuntime->stop(&errorString);
  if(!result)
  {
    emit this->stopped(false, QStringList()<<errorString);
    return;
  }

  emit this->stopped(true);

  return;
}

} // namespace modsim
