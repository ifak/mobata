#include "remotecontrolservice.hpp"

#include "remotecontrol.hpp"
#include "remoteport.hpp"

#include <QJsonValue>

#include <QHostAddress>
#include <QUuid>

namespace remotecontrol {

class RemoteControlService::Private
{
  friend class RemoteControlService;

  RemoteControl*  _remoteControl;

  Private()
    : _remoteControl(0)
  {}
};

RemoteControlService::RemoteControlService(QObject* parent)
  : QJsonRpcService(parent),
    _d(new Private)
{}

RemoteControlService::~RemoteControlService()
{
  delete this->_d;
}

QJsonValue RemoteControlService::open(QString userAddressString,
                                      quint16 userPort)
{
//  qDebug()<<"RemoteControlService::open() executed!";
//  qDebug()<<"user-address: "<<userAddressString;
//  qDebug()<<"user-port: "<<userPort;

  QJsonArray response;

  QHostAddress userAddress;
  bool result = userAddress.setAddress(userAddressString);
  if(!result)
  {
    response.append(false);
    response.append(tr("open() received!, "
                       "'%1' is not a valid address for a user")
                    .arg(userAddressString));

    return response;
  }

  if(!this->_d->_remoteControl)
  {
    response.append(false);
    response.append(tr("open() received!, "
                       "no remote control for this service available!"));

    return response;
  }

  this->_d->_remoteControl->setUserAddress(userAddress);
  this->_d->_remoteControl->setUserPort(userPort);

  emit this->_d->_remoteControl->remotePort()->remoteControlOpen();

//  qDebug()<<"remote port: sent signal remoteControlOpen()!";

  response.append(true);
  response.append(QStringLiteral("open() received!"));

  return response;
}

QJsonValue RemoteControlService::close()
{
//  qDebug()<<"RemoteControlService::close() executed!";

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("close() received!"));//message

  emit this->_d->_remoteControl->remotePort()->remoteControlClose();
//  qDebug()<<"remote port: sent signal remoteControlClose()!";

  return resultArray;///will be send back
}

QJsonValue RemoteControlService::setup(const QVariantMap& setupArgs)
{
//  qDebug()<<"RemoteControlService::setup() executed!";

  Q_ASSERT(this->_d->_remoteControl);
  Q_ASSERT(this->_d->_remoteControl->remotePort());

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("setup() received!"));//message

  emit this->_d->_remoteControl->remotePort()->setup(setupArgs);

  return resultArray;///will be send back
}

QJsonValue RemoteControlService::status()
{
//  qDebug()<<"RemoteControlService::status() executed!";

  Q_ASSERT(this->_d->_remoteControl);
  Q_ASSERT(this->_d->_remoteControl->remotePort());

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("status() received!"));//message

  emit this->statusRequest();

  return resultArray;///will be send back
}

QJsonValue RemoteControlService::start()
{
//  qDebug()<<"RemoteControlService::start() executed!";

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("start() received!"));//message

  emit this->_d->_remoteControl->remotePort()->start();

  return resultArray;///will be send back
}

QJsonValue RemoteControlService::stop()
{
//  qDebug()<<"RemoteControlService::stop() executed!";

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("stop() received!"));//message

  emit this->_d->_remoteControl->remotePort()->stop();

  return resultArray;///will be send back
}

QJsonValue RemoteControlService::reset(bool force)
{
  qDebug()<<"RemoteControlService::reset() executed!";

  QJsonArray resultArray;
  resultArray.append(true);//result
  resultArray.append(QStringLiteral("reset() received!"));//message

  emit this->_d->_remoteControl->remotePort()->reset(force);

  return resultArray;///will be send back
}

void RemoteControlService::setRemoteControl(RemoteControl* remoteControl)
{
  this->_d->_remoteControl=remoteControl;

  return;
}

RemoteControl* RemoteControlService::remoteControl()
{
  return this->_d->_remoteControl;
}

} // namespace remotecontrol

