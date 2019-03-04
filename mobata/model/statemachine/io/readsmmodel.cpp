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

#include "readsmmodel.hpp"

#include "../../base/io/readbasemodel.hpp"

#include <QJsonObject>
#include <QJsonArray>

namespace model {
namespace statemachine {
namespace io {

bool readStateMachineModel(const QJsonObject& jsonObject,
                           StateMachineModel* smModel,
                           QString* errorMessage)
{
  Q_ASSERT(smModel);

  bool result = base::io::readBaseModel(jsonObject, smModel, errorMessage);
  if(!result)
    return false;

  if(jsonObject.value(QStringLiteral("ports"))!=QJsonValue::Undefined)
  {
    result = base::io::readPorts(jsonObject, smModel, errorMessage);
    if(!result)
      return false;
  }

  if(jsonObject.value(QStringLiteral("states"))!=QJsonValue::Undefined)
  {
    result = readStatesModel(jsonObject, smModel, QStringLiteral("states"), errorMessage);
    if(!result)
      return false;
  }

  if(jsonObject.value(QStringLiteral("transitions"))!=QJsonValue::Undefined)
  {
    result = readTransitionsModel(jsonObject, smModel, errorMessage);
    if(!result)
      return  false;
  }

  return true;
}


} // namespace io
} // namespace msc
} // namespace model
