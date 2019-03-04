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

#pragma once

#include "modsim_global.hpp"

#include <QObject>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>

#include <dslparser/dslerror.hpp>

class QStandardItemModel;

namespace modsim {

enum SimModelType
{
  SpenatModel,
  StateMachineModel,
  UserModel
};

class MODSIMSHARED_EXPORT SimModel
    : public QObject
{
public:
  typedef dslparser::DslErrorList ErrorSet;

protected:
  explicit SimModel(const QString& modelDocText,
                    const QString& asName,
                    const QIcon& modelIcon,
                    QObject* parent = nullptr);

public:
  virtual ~SimModel();

public:
  virtual SimModelType              simModelType() const = 0;
  virtual bool                      rebuildSimModel(QString* errorMessage) =0;
  virtual QStandardItemModel const* simModel() const =0;
  virtual QStringList               portNames() const =0;
  virtual bool                      hasPort(const QString& portName) const =0;

public:
  const ErrorSet& errors() const;
  void            addError(const dslparser::DslError& error);


public:
  const QString&  modelDocText() const;
  const QString&  asName() const;
  const QIcon&    icon() const;

protected:
  void clearErrors();

private:
  Q_DISABLE_COPY(SimModel)
  class Private;
  Private*  _d;
};

class MODSIMSHARED_EXPORT SimSpenatModel
    : public SimModel
{
public:
  explicit SimSpenatModel(const QString& modelDocText,
                          const QString& spenatModelAsName,
                          QObject* parent = nullptr);
  virtual ~SimSpenatModel();

public:
  SimModelType simModelType() const override {return SpenatModel;}

public:
  bool                                  rebuildSimModel(QString* errorMessage) override;
  model::spenat::SpenatDeclModel const* simModel() const override;
  QStringList                           portNames() const override;
  bool                                  hasPort(const QString& portName) const override;

protected:
  model::spenat::SpenatDeclModel* spenatModel();

private:
  Q_DISABLE_COPY(SimSpenatModel)
  class Private;
  Private*  _d;
};

class MODSIMSHARED_EXPORT SimStateMachineModel
    : public SimModel
{
public:
  explicit SimStateMachineModel(const QString& modelDocText,
                                const QString& stateMachineModelAsName,
                                QObject* parent = nullptr);
  virtual ~SimStateMachineModel();

public:
  SimModelType simModelType() const override {return StateMachineModel;}

public:
  bool                                            rebuildSimModel(QString* errorMessage) override;
  model::statemachine::StateMachineModel  const*  simModel() const override;
  QStringList                                     portNames() const override;
  bool                                            hasPort(const QString& portName) const override;

protected:
  model::statemachine::StateMachineModel* stateMachineModel();

private:
  Q_DISABLE_COPY(SimStateMachineModel)
  class Private;
  Private*  _d;
};

} // namespace specsim
