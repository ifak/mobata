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
