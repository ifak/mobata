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

#include "comsavemscmodel.hpp"

#include "mscmodel.hpp"
#include "io/writemscmodel.hpp"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>

namespace model {
namespace msc {

class ComSaveMscModel::Private
{
  friend class ComSaveMscModel;

  MscModel const*  _mscModel;
  QString           _fileName;

  Private(MscModel const* mscModel,
          const QString& fileName)
    : _mscModel(mscModel),
      _fileName(fileName)
  {}
};

ComSaveMscModel::ComSaveMscModel(MscModel const* mscModel,
                                 const QString& fileName,
                                 QObject *parent)
  : QObject(parent),
    _d(new Private(mscModel, fileName))
{}

ComSaveMscModel::~ComSaveMscModel()
{
  delete this->_d;
}

bool ComSaveMscModel::execute(QString* errorMessage)
{
  QFile outputFile(this->_d->_fileName);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    if(errorMessage)
      *errorMessage += tr("msc model '%1' could not be saved to '%2'!")
                       .arg(this->_d->_mscModel->name())
                       .arg(this->_d->_fileName);
    return false;
  }

  QJsonObject json_mscModelObject;
  io::writeMscModel(this->_d->_mscModel, json_mscModelObject);
  QJsonDocument jsonDocument(json_mscModelObject);

  QTextStream outputStream(&outputFile);
  outputStream << jsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

} // namespace msc
} // namespace model
