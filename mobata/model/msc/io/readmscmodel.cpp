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

#include "readmscmodel.hpp"

#include "../mscmodel.hpp"

#include "../../base/io/readbasemodel.hpp"

#include <QJsonObject>
#include <QJsonArray>

namespace model {
namespace msc {
namespace io {

bool readMscModel(const QJsonObject& jsonObject,
                   MscModel* mscModel,
                   QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscModel);

  bool result = base::io::readBaseModel(jsonObject, mscModel, errorMessage);
  if(!result)
    return false;

  if(jsonObject.value(QStringLiteral("components"))!=QJsonValue::Undefined)
  {
    result = readComponents(jsonObject, mscModel,
                            ReadMscComponent<MscModel>(), errorMessage);
    if(!result)
      return false;
  }

  if(jsonObject.value(QStringLiteral("sequences"))!=QJsonValue::Undefined)
  {
    result = readMscSequences(jsonObject, mscModel, errorMessage);
    if(!result)
      return  false;
  }

  return true;
}


} // namespace io
} // namespace msc
} // namespace model
