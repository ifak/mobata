#include "remotecontrolfunctors.hpp"

#include <qjsonrpcmessage.h>

#include <mobata/memory_leak_start.hpp>

namespace remotecontrol{

void ProcessRemoteReply::operator ()(const QJsonRpcMessage& responseMessage,
                                     bool* result,
                                     QString* message)
{
  Q_ASSERT(result);
  Q_ASSERT(message);

  *result = true;
  *message = QStringLiteral("");

  if(responseMessage.result().isArray())
  {
    QJsonArray resultArray = responseMessage.result().toArray();
    *result = resultArray.at(0).toBool();
    *message = resultArray.at(1).toString();

    return;
  }
  else if(responseMessage.result().isBool())
  {
    *result = responseMessage.result().toBool();
    *message = responseMessage.errorMessage();

    return;
  }

  *result=false;
  *message=responseMessage.errorMessage();

  return;
}

}// namespace remotecontrol
