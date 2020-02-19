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
    foreach (base::ComponentItem const* component,
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
    foreach (msc::MscSequence const* mscSequence,
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
