#include "readbasemodel.hpp"

#include "../basemodel.hpp"

#include <QJsonObject>
#include <QJsonArray>

namespace model {
namespace base {
namespace io {

bool readBaseModel(const QJsonObject& jsonObject,
                   BaseModel* baseModel,
                   QString* errorMessage)
{
  Q_ASSERT(baseModel);

  QString name;
  bool result = readProperty<QString>(jsonObject,
                                      QStringLiteral("name"),
                                      &name,
                                      errorMessage);
  if(!result)
    return false;
  baseModel->setName(name);

  result = readDataTypes(jsonObject, baseModel, errorMessage);
  if(!result)
    return false;

  result = readSignals(jsonObject, baseModel, errorMessage);
  if(!result)
    return false;

  result = readAttributes(jsonObject, baseModel, errorMessage);
  if(!result)
    return  false;

  return true;
}


} // namespace io
} // namespace base
} // namespace model
