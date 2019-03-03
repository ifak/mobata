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

#include <QObject>

namespace model {
namespace irdl {

class RequirementsModel;

class ComSaveReqModel : public QObject
{
  Q_OBJECT
public:
  explicit ComSaveReqModel(RequirementsModel const* reqModel,
                           const QString& fileName,
                           QObject* parent = nullptr);
  virtual ~ComSaveReqModel();

public:
  bool execute(QString* errorMessage=nullptr);

private:
  Q_DISABLE_COPY(ComSaveReqModel)
  class Private;
  Private* _d;
};

} // namespace requirement
} // namespace model
