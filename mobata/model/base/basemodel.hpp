/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "../../mobata_global.hpp"

#include "../../prop/nameproperty.hpp"
#include "propdatatypes.hpp"
#include "propattributes.hpp"
#include "propsignals.hpp"
#include "propfunctions.hpp"

#include <QUuid>
#include <QStandardItemModel>

namespace model{
namespace base{

typedef QSharedPointer<QJsonObject>   JsonObjectPtr;
typedef QSharedPointer<QJsonDocument> JsonDocPtr;

class DataTypeItem;
class SignalItem;

class MOBATASHARED_EXPORT BaseModel
    : public QStandardItemModel,
    public prop::NameProperty,
    public PropDataTypes,
    public PropAttributes,
    public PropSignals,
    public PropFunctions
{
  Q_OBJECT


public:
  typedef QHash<QString, BaseModel*> ImportedBaseModels;
  explicit BaseModel(QObject *parent = 0);
  explicit BaseModel(const QString& modelName,
                     QObject *parent = 0);
  virtual	~BaseModel();

signals:
  void error(const QString& errorText);

public://virtual methods
  virtual void          reset();
  virtual JsonObjectPtr createJson() const;
  const ImportedBaseModels& importedModels() const;
  bool addImportedModel(const QString & name, BaseModel* model, QString* errorMessage=0) const;
  void removeImportedModel(const QString & name) const;

private:
  Q_DISABLE_COPY(BaseModel)
  class Private;
  Private*	_d;
};

}///end namespace base
}///end namespace model
