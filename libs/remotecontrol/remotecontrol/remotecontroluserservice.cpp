#include "remotecontroluserservice.hpp"

#include "remotecontroluser.hpp"

#include <mobata/memory_leak_start.hpp>

namespace remotecontrol {

class RemoteControlUserService::Private
{
  friend class RemoteControlUserService;

  RemoteControlUser*  _remoteControlUser;

  Private()
    : _remoteControlUser(0)
  {}
};

RemoteControlUserService::RemoteControlUserService(QObject* parent)
  : QJsonRpcService(parent),
    _d(new Private)
{}

RemoteControlUserService::~RemoteControlUserService()
{
  delete this->_d;
}

QJsonValue RemoteControlUserService::setuped(bool result, const QStringList& messages)
{
//  qDebug()<<"setuped received! result: "<<result<<" messages: "<<messages;

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("setuped() received!"));//message

  emit this->_d->_remoteControlUser->setuped(result,
                                             messages);

  return resultArray;
}

QJsonValue RemoteControlUserService::started(bool result, const QStringList& messages)
{
//  qDebug()<<"started received! result: "<<result<<" messages: "<<messages;

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("started() received!"));//message

  emit this->_d->_remoteControlUser->started(result,
                                             messages);

  return resultArray;
}

QJsonValue RemoteControlUserService::stopped(bool result, const QStringList& messages)
{
//  qDebug()<<"stopped received! result: "<<result<<" messages: "<<messages;

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("stopped() received!"));//message

  emit this->_d->_remoteControlUser->stopped(result,
                                             messages);

  return resultArray;
}

QJsonValue RemoteControlUserService::resetted(bool result, const QStringList& messages)
{
//  qDebug()<<"resetted received! result: "<<result<<" messages: "<<messages;

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("resetted() received!"));//message

  emit this->_d->_remoteControlUser->resetted(result,
                                              messages);

  return resultArray;
}

QJsonValue RemoteControlUserService::finished(bool result, const QStringList& messages)
{
//  qDebug()<<"finished received! result: "<<result<<" messages: "<<messages;

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("finished() received!"));//message

  emit this->_d->_remoteControlUser->finished(result,
                                              messages);

  return resultArray;
}

QJsonValue RemoteControlUserService::statusResponse(const QString& state,
                                                    const QStringList& messages)
{
//  qDebug()<<"statusResponse received! state: "<<state<<" messages: "<<messages;

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("statusResponse() received!"));//message

  this->_d->_remoteControlUser->setRemoteState(state);

  emit this->_d->_remoteControlUser->status(state, messages);

  return resultArray;
}

QJsonValue RemoteControlUserService::message(const QString& message)
{
//  qDebug()<<"message received! message: "<<message;

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("message() received!"));//message

  emit this->_d->_remoteControlUser->message(message);

  return resultArray;
}

void RemoteControlUserService::setRemoteControlUser(RemoteControlUser* remoteControlUser)
{
  this->_d->_remoteControlUser=remoteControlUser;

  return;
}

RemoteControlUser* RemoteControlUserService::remoteControlUser()
{
  return this->_d->_remoteControlUser;
}

} // namespace remotecontrol
