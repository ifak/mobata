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
#ifndef MODEL_BASE_COMLOADBASEMODEL_HPP
#define MODEL_BASE_COMLOADBASEMODEL_HPP

#include <QObject>

namespace model {
namespace base {

class BaseModel;

class ComLoadBaseModel : public QObject
{
  Q_OBJECT
public:
  explicit ComLoadBaseModel(const QString& fileName,
                            BaseModel* baseModel,
                            QObject* parent = 0);
  virtual ~ComLoadBaseModel();

public:
  virtual bool execute(QString* errorMessage=0);

private:
  Q_DISABLE_COPY(ComLoadBaseModel)
  class Private;
  Private* _d;
};

} // namespace base
} // namespace model

#endif // MODEL_BASE_COMLOADBASEMODEL_HPP
