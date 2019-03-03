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

#include "comloadbasemodel.hpp"

#include "basemodel.hpp"
#include "io/readbasemodel.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace base {

class ComLoadBaseModel::Private
{
  friend class ComLoadBaseModel;

  const QString _fileName;
  BaseModel*    _baseModel;

  Private(const QString& fileName,
          BaseModel* baseModel)
    : _fileName(fileName),
      _baseModel(baseModel)
  {}
};

ComLoadBaseModel::ComLoadBaseModel(const QString& fileName,
                                   BaseModel* baseModel,
                                   QObject *parent)
  : QObject(parent),
    _d(new Private(fileName, baseModel))
{}

ComLoadBaseModel::~ComLoadBaseModel()
{
  delete this->_d;
}

bool ComLoadBaseModel::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_baseModel);

  QFile inputFile(this->_d->_fileName);
  if (!inputFile.open(QIODevice::ReadOnly
                      | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("base model file '%1' could not be loaded!")
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonParseError jsonError;
  QJsonDocument json_baseModelDoc=QJsonDocument::fromJson(inputFile.readAll(),
                                                          &jsonError);
  if(jsonError.error != QJsonParseError::NoError)
  {
    if(errorMessage)
      *errorMessage += jsonError.errorString();
    return  false;
  }

  this->_d->_baseModel->reset();

  bool result = io::readBaseModel(json_baseModelDoc.object(),
                                  this->_d->_baseModel,
                                  errorMessage);
  if(!result)
    return  false;

  return true;
}

} // namespace base
} // namespace model
