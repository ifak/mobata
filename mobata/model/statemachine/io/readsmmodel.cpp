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
