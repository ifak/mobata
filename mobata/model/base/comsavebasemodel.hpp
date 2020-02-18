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

#include <QObject>

namespace model {
namespace base {

class BaseModel;

class ComSaveBaseModel : public QObject
{
  Q_OBJECT
public:
  explicit ComSaveBaseModel(BaseModel const* baseModel,
                            const QString& fileName,
                            QObject* parent = 0);
  virtual ~ComSaveBaseModel();

public:
  virtual bool execute(QString* errorMessage=0);

private:
  Q_DISABLE_COPY(ComSaveBaseModel)
  class Private;
  Private* _d;
};

} // namespace base
} // namespace model
