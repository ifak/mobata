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

#include "simmodel.hpp"

#include <mobata/utils/functors.hpp>

#include <mobata/model/base/portitem.hpp>
#include <mobata/model/spenat/spenatmodel.hpp>
#include <mobata/model/spenat/comcreatespenatmodel.hpp>

#include <dslparser/spenat/combuildspenatmodel.hpp>
#include <dslparser/statemachine/combuildstatemachinemodel.hpp>

#include <QFileInfo>
#include <QIcon>
#include <QJsonDocument>

namespace modsim {

class SimModel::Private
{
  friend class SimModel;

  QString   _modelDocText;
  QString   _asName;
  QIcon     _modelIcon;
  ErrorSet  _errors;

  Private(const QString& modelDocText,
          const QString& simModelAsName,
          const QIcon& simModelIcon)
    : _modelDocText(modelDocText),
      _asName(simModelAsName),
      _modelIcon(simModelIcon)
  {}
};

SimModel::SimModel(const QString& modelDocText,
                   const QString& simModelAsName,
                   const QIcon& simModelIcon,
                   QObject *parent)
  : QObject(parent),
    _d(new Private(modelDocText, simModelAsName, simModelIcon))
{}

SimModel::~SimModel()
{
  delete this->_d;
}

const SimModel::ErrorSet& SimModel::errors() const
{
  return this->_d->_errors;
}

void SimModel::addError(const dslparser::DslError& error)
{
  this->_d->_errors.append(error);

  return;
}

const QString& SimModel::modelDocText() const
{
  return this->_d->_modelDocText;
}

const QString& SimModel::asName() const
{
  return this->_d->_asName;
}

const QIcon& SimModel::icon() const
{
  return this->_d->_modelIcon;
}

void SimModel::clearErrors()
{
  this->_d->_errors.clear();

  return;
}

///SimSpenatModel////////////////////////////
class SimSpenatModel::Private
{
  friend class SimSpenatModel;

  model::spenat::SpenatDeclModel* _spenatDeclModel;

  Private()
    : _spenatDeclModel(0)
  {}
};

SimSpenatModel::SimSpenatModel(const QString& modelDocText,
                               const QString& spenatModelAsName,
                               QObject* parent)
  : SimModel(modelDocText,
             spenatModelAsName,
             QIcon(QStringLiteral(":/mobata/images/spenat/transition.png")),
             parent),
    _d(new Private)
{
  this->_d->_spenatDeclModel = new model::spenat::SpenatDeclModel(this);
}

SimSpenatModel::~SimSpenatModel()
{
  delete this->_d;
}

model::spenat::SpenatDeclModel const* SimSpenatModel::simModel() const
{
  return this->_d->_spenatDeclModel;
}

bool SimSpenatModel::rebuildSimModel(QString* errorMessage)
{
  Q_ASSERT(this->_d->_spenatDeclModel);

  this->clearErrors();
  this->_d->_spenatDeclModel->reset();

  dslparser::spenat::ComBuildSpenatModel buildCommand(this->modelDocText(),
                                                      this->_d->_spenatDeclModel);
  bool result = buildCommand.execute(errorMessage);
  for(const dslparser::DslError& dslError : buildCommand.errors())
    this->addError(dslError);

  if(result)
  {
    model::spenat::ComCreateSpenatModel command(this->_d->_spenatDeclModel);
    result = command.execute(errorMessage);
  }

  return result;
}

QStringList SimSpenatModel::portNames() const
{
  QStringList portNames;
  if(!this->_d->_spenatDeclModel)
    return portNames;

  for(auto currPort : this->_d->_spenatDeclModel->ports())
    portNames.append(currPort->name());

  return portNames;
}

bool SimSpenatModel::hasPort(const QString& portName) const
{
  if(!this->_d->_spenatDeclModel)
    return false;

  if(!this->_d->_spenatDeclModel->port(portName))
    return false;

  return true;
}

///SimStateMachineModel////////////////////////////////
class SimStateMachineModel::Private
{
  friend class SimStateMachineModel;

  model::statemachine::StateMachineModel* _stateMachineModel;

  Private()
    : _stateMachineModel(nullptr)
  {}
};

SimStateMachineModel::SimStateMachineModel(const QString& modelDocText,
                                           const QString& stateMachineModelAsName,
                                           QObject* parent)
  : SimModel(modelDocText,
             stateMachineModelAsName,
             QIcon(QStringLiteral(":/mobata/images/base/model.png")),
             parent),
    _d(new Private)
{
  this->_d->_stateMachineModel = new model::statemachine::StateMachineModel(this);
}

SimStateMachineModel::~SimStateMachineModel()
{
  delete this->_d;
}

model::statemachine::StateMachineModel const* SimStateMachineModel::simModel() const
{
  return this->_d->_stateMachineModel;
}

bool SimStateMachineModel::rebuildSimModel(QString* errorMessage)
{
  Q_ASSERT(this->_d->_stateMachineModel);

  this->clearErrors();
  this->_d->_stateMachineModel->reset();

  dslparser::statemachine::ComBuildStateMachineModel buildCommand(this->modelDocText(),
                                                                  this->_d->_stateMachineModel);
  bool result = buildCommand.execute(errorMessage);
  for(const dslparser::DslError& dslError : buildCommand.errors())
    this->addError(dslError);

  return result;
}

QStringList SimStateMachineModel::portNames() const
{
  QStringList portNames;
  if(!this->_d->_stateMachineModel)
    return portNames;

  for(auto currPort : this->_d->_stateMachineModel->ports())
    portNames.append(currPort->name());

  return portNames;
}

bool SimStateMachineModel::hasPort(const QString& portName) const
{
  if(!this->_d->_stateMachineModel)
    return false;

  if(!this->_d->_stateMachineModel->port(portName))
    return false;

  return true;
}

} // namespace modsim
