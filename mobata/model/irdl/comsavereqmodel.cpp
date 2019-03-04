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

#include "comsavereqmodel.hpp"

#include "requirementsmodel.hpp"
#include "io/writereqmodel.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace irdl {

class ComSaveReqModel::Private
{
  friend class ComSaveReqModel;

  RequirementsModel const*  _reqModel;
  QString           _fileName;

  Private(RequirementsModel const* reqModel,
          const QString& fileName)
    : _reqModel(reqModel),
      _fileName(fileName)
  {}
};

ComSaveReqModel::ComSaveReqModel(const RequirementsModel *reqModel,
                                 const QString& fileName,
                                 QObject *parent)
  : QObject(parent),
    _d(new Private(reqModel, fileName))
{}

ComSaveReqModel::~ComSaveReqModel()
{
  delete this->_d;
}

bool ComSaveReqModel::execute(QString* errorMessage)
{
  QFile outputFile(this->_d->_fileName);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("msc model '%1' could not be saved to '%2'!")
                       .arg(this->_d->_reqModel->name())
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonObject json_reqModelObject;
  io::writeReqModel(this->_d->_reqModel, json_reqModelObject);
  QJsonDocument jsonDocument(json_reqModelObject);

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

} // namespace requirement
} // namespace model
