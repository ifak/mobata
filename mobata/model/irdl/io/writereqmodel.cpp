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

#include "writereqmodel.hpp"

#include "../req.hpp"
#include "../../msc/msc.hpp"

#include "../../msc/io/writemscmodel.hpp"

#include "../../base/io/writebasemodel.hpp"

#include <QJsonObject>
#include <QJsonArray>

namespace model {
namespace irdl {
namespace io {

void writeReqModel(RequirementsModel const* reqModel,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(reqModel);

  base::io::writeBaseModel(reqModel, jsonObject);

  if(reqModel->components().count())
  {
    QJsonArray mscComponentsArray;
    for (base::ComponentItem const* component:
         reqModel->components())
    {
      if(msc::MscComponentItem const* mscComponent = dynamic_cast<msc::MscComponentItem const*>(component))
      {
        QJsonObject componentObject;
        msc::io::writeMscComponent(mscComponent, componentObject);
        mscComponentsArray.append(componentObject);
      }
    }
    jsonObject["components"] = mscComponentsArray;
  }

  if(reqModel->requirements().count())
  {
    QJsonArray sequencesArray;
    for (msc::MscSequence const* mscSequence:
         reqModel->requirements())
    {
      QJsonObject sequenceObject;
      msc::io::writeMscSequence(mscSequence, sequenceObject);
      sequencesArray.append(sequenceObject);
    }
    jsonObject["sequences"] = sequencesArray;
  }

  return;
}

} // namespace io
} // namespace requirement
} // namespace model
