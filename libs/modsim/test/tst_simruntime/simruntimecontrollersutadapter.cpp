#include "simruntimecontrollersutadapter.hpp"

#include <QDebug>

SimRuntimeControllerSutAdapter::SimRuntimeControllerSutAdapter(QObject* parent)
  : QObject(parent)
{}

void SimRuntimeControllerSutAdapter::controllerPreparedSlot(bool result,
                                                            const QStringList& messages)
{
  qDebug()<<"SimRuntimeControllerSutAdapter::controllerPreparedSlot() executed()";

  QVariantMap params;
  params.insert("result", result);
  params.insert("messages", messages);
  emit messageReceived("__controllerPrepared", "", params);

  return;
}

void SimRuntimeControllerSutAdapter::controllerStartedSlot(bool result,
                                                           const QStringList& messages)
{
  qDebug()<<"SimRuntimeControllerSutAdapter::controllerStartedSlot() executed()";

  QVariantMap params;
  params.insert("result", result);
  params.insert("messages", messages);
  emit messageReceived("__controllerStarted", "", params);

  return;
}

void SimRuntimeControllerSutAdapter::controllerStoppedSlot(bool result,
                                                           const QStringList& messages)
{
  qDebug()<<"SimRuntimeControllerSutAdapter::controllerStoppedSlot() executed()";

  QVariantMap params;
  params.insert("result", result);
  params.insert("messages", messages);
  emit messageReceived("__controllerStopped", "", params);

  return;
}

void SimRuntimeControllerSutAdapter::receiveRuntimeMessageSlot(const QString& modelAsName,
                                                               const QString& portName,
                                                               const QString& messageName,
                                                               const QVariantMap& paramValues)
{
  qDebug()<<"SimRuntimeControllerSutAdapter::receiveRuntimeMessageSlot() executed()";

  QVariantMap params = paramValues;
  params.insert("__modelAsName__", modelAsName);
  emit messageReceived(messageName, portName, params);

  return;
}

void SimRuntimeControllerSutAdapter::observedRuntimeMessageSlot(const QString& sourceModelAsName,
                                                                const QString& sourcePortName,
                                                                const QString& targetModelAsName,
                                                                const QString& targetPortName,
                                                                const QString& messageName,
                                                                const QVariantMap& paramValues)
{
  qDebug()<<"SimRuntimeControllerSutAdapter::observedRuntimeMessageSlot() executed()";

  QVariantMap params = paramValues;
  params.insert("__sourceModelAsName__", sourceModelAsName);
  params.insert("__sourcePortName__", sourcePortName);
  params.insert("__targetModelAsName__", targetModelAsName);
  params.insert("__targetPortName__", targetPortName);
  emit messageReceived(messageName, "", params);

  return;
}

void SimRuntimeControllerSutAdapter::sendMessageSlot(const QString& messageName,
                                                     const QString& portName,
                                                     const QVariantMap& paramValues,
                                                     const QUuid& messageID)
{
  Q_UNUSED(messageID);

  if(messageName == "__prepareController")
  {
    emit this->prepareController();
    emit this->messageSent(messageID, true);
    return;
  }
  else if(messageName == "__startController")
  {
    emit this->startController();
    emit this->messageSent(messageID, true);
    return;
  }
  else if(messageName == "__stopController")
  {
    emit this->stopController();
    emit this->messageSent(messageID, true);
    return;
  }

  if(!paramValues.contains("__modelAsName__"))
  {
    emit this->errors(QStringList()<<tr("message parameters for message '%1' and port '%2'"
                                        " have no value for '%3!")
                      .arg(messageName).arg(portName).arg("__modeAsName__"));
    return;
  }

  QString modelAsName=paramValues.value("__modelAsName__").toString();
  emit this->sendMessage(modelAsName, portName, messageName, paramValues);
  emit this->messageSent(messageID, true);

  return;
}
