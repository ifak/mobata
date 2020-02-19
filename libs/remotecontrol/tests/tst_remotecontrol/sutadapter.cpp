#include "sutadapter.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

SutAdapter::SutAdapter(QObject* parent) : QObject(parent)
{}

void SutAdapter::setupControlSlot(const QVariantMap& setupArgs)
{
//  qDebug()<<"SutAdapter::setupControlSlot() executed()";

  emit messageReceived("setupControl", setupArgs);

  return;
}

void SutAdapter::startControlSlot()
{
//  qDebug()<<"SutAdapter::startControlSlot() executed()";

  emit messageReceived("startControl");

  return;
}

void SutAdapter::stopControlSlot()
{
//  qDebug()<<"SutAdapter::stopControlSlot() executed()";

  emit messageReceived("stopControl");

  return;
}

void SutAdapter::resetControlSlot()
{
//  qDebug()<<"SutAdapter::resetControlSlot() executed()";

  emit messageReceived("resetControl");

  return;
}

void SutAdapter::statusRequestSlot()
{
//  qDebug()<<"SutAdapter::statusRequestSlot() executed()";

  emit messageReceived("statusRequest");

  return;
}

void SutAdapter::sendMessageSlot(const QString& messageName,
                                 const QVariantList& paramValues,
                                 const QUuid& messageID)
{
  Q_UNUSED(messageID);

  if(messageName == "controlSetuped")
  {
    Q_ASSERT(paramValues.size()==2);
    Q_ASSERT(paramValues.at(0).type()==QVariant::Bool);
    Q_ASSERT(paramValues.at(1).type()==QVariant::String);

    emit this->controlSetuped(paramValues.at(0).toBool(),
                              paramValues.at(1).toString());
    emit this->messageSent(messageID, true);

    return;
  }
  else if(messageName == "controlStarted")
  {
    Q_ASSERT(paramValues.size()==2);
    Q_ASSERT(paramValues.at(0).type()==QVariant::Bool);
    Q_ASSERT(paramValues.at(1).type()==QVariant::String);

    emit this->controlStarted(paramValues.at(0).toBool(),
                              paramValues.at(1).toString());
    emit this->messageSent(messageID, true);

    return;
  }
  else if(messageName == "controlStopped")
  {
    Q_ASSERT(paramValues.size()==2);
    Q_ASSERT(paramValues.at(0).type()==QVariant::Bool);
    Q_ASSERT(paramValues.at(1).type()==QVariant::String);

    emit this->controlStopped(paramValues.at(0).toBool(),
                              paramValues.at(1).toString());
    emit this->messageSent(messageID, true);

    return;
  }
  else if(messageName == "controlResetted")
  {
    Q_ASSERT(paramValues.size()==2);
    Q_ASSERT(paramValues.at(0).type()==QVariant::Bool);
    Q_ASSERT(paramValues.at(1).type()==QVariant::String);

    emit this->controlResetted(paramValues.at(0).toBool(),
                               paramValues.at(1).toString());
    emit this->messageSent(messageID, true);

    return;
  }
  else if(messageName == "statusResponse")
  {
    Q_ASSERT(paramValues.size()==1);
    Q_ASSERT(paramValues.at(0).type()==QVariant::StringList);

    emit this->statusResponse(paramValues.at(0).toStringList());
    emit this->messageSent(messageID, true);

    return;
  }

  this->_openMessages.insert(messageID);
  emit this->sendMessage(messageName, paramValues, messageID);

  return;
}

void SutAdapter::messageSentSlot(const QUuid& messageID, bool result, const QString& errorString)
{
  QSet<QUuid>::ConstIterator find_it=this->_openMessages.find(messageID);
  if(find_it==this->_openMessages.cend())
    return;

  emit messageSent(messageID, result, errorString);

  return;
}
