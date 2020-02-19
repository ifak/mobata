#include "remotecontroluser.hpp"

#include "remoteconnectionmanager.hpp"
#include "remotecontroluserservice.hpp"

#include <qjsonrpctcpserver.h>
#include <qjsonrpcservicereply.h>

#include <QTimer>

#include <mobata/memory_leak_start.hpp>

namespace remotecontrol{

class RemoteControlUser::Private
{
  friend class RemoteControlUser;

  RemoteControlUserService* _remoteControlUserService;
  QHostAddress              _userAddress;
  quint16                   _userPort;
  QJsonRpcTcpServer*        _jsonRpcServer;
  QString                   _remoteState;

  Private(RemoteControlUserService* remoteControlUserService,
          QHostAddress hostAddress,
          quint16 hostPort)
    : _remoteControlUserService(remoteControlUserService),
      _userAddress(hostAddress),
      _userPort(hostPort)
  {}
};

RemoteControlUser::RemoteControlUser(const QString& name,
                                     RemoteControlUserService* remoteControlUserService,
                                     QObject* parent,
                                     QHostAddress remoteAddress,
                                     quint16 remotePort,
                                     QHostAddress hostAddress,
                                     quint16 hostPort)
  : RemoteComponent(name, parent,remoteAddress,remotePort),
    _d(new Private(remoteControlUserService,hostAddress,hostPort))
{
  Q_ASSERT(this->_d->_remoteControlUserService);
  this->_d->_remoteControlUserService->setRemoteControlUser(this);

  this->remoteConnectionManager()->setRemoteAddress(remoteAddress);
  this->remoteConnectionManager()->setRemotePort(remotePort);
  this->remoteConnectionManager()->setRemoteServiceProvider(QStringLiteral("remotecontrol"));

  this->_d->_jsonRpcServer = new QJsonRpcTcpServer(this);
  this->_d->_jsonRpcServer->addService(this->_d->_remoteControlUserService);

//  qDebug() << "Remote Control User initialized!";
}

RemoteControlUser::~RemoteControlUser()
{
  this->_d->_jsonRpcServer->close();
//  qDebug()<<"service is closed with address: "
//         <<this->userAddressString()
//        <<" and port: "<<this->userPort();

  delete this->_d;
}

const QString& RemoteControlUser::remoteState() const
{
  return this->_d->_remoteState;
}

bool RemoteControlUser::run(QString* errorString)
{
  Q_ASSERT(this->_d->_jsonRpcServer);

  if(!this->_d->_jsonRpcServer->isListening())
  {
    if(!this->_d->_jsonRpcServer->listen(QHostAddress::Any,
                                         this->_d->_userPort))
    {
      QString errorMessage = this->_d->_jsonRpcServer->errorString();
      if(errorString)
        *errorString += errorMessage;
      return false;
    }
  }

  return true;
}

bool RemoteControlUser::isRunning() const
{
  Q_ASSERT(this->_d->_jsonRpcServer);

  return this->_d->_jsonRpcServer->isListening();
}

void RemoteControlUser::start()
{
//  qDebug()<<"RemoteControlUser::start() executed!";
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("start"));

  return;
}

void RemoteControlUser::statusRequest()
{
//  qDebug()<<"RemoteControlUser::statusRequest() executed!";
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("status"));

  return;
}

void RemoteControlUser::stop()
{
//  qDebug()<<"RemoteControlUser::stop() executed!";
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("stop"));

  return;
}

void RemoteControlUser::reset()
{
//  qDebug()<<"RemoteControlUser::reset() executed!";
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("reset"));

  return;
}

void RemoteControlUser::setUserAddress(const QHostAddress& userAddress)
{
  this->_d->_userAddress = userAddress;

  return;
}

void RemoteControlUser::setUserPort(const quint16 userPort)
{
  this->_d->_userPort = userPort;

  return;
}

void RemoteControlUser::setRemoteControlAddress(const QHostAddress& rcAddress)
{
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->setRemoteAddress(rcAddress);

  return;
}

void RemoteControlUser::setRemoteControlPort(const quint16 rcPort)
{
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->setRemotePort(rcPort);

  return;
}

void RemoteControlUser::setRemoteControlServiceProvider(const QString& rcServiceProvider)
{
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->setRemoteServiceProvider(rcServiceProvider);

  return;
}

const QHostAddress&RemoteControlUser::userAddress() const
{
  return this->_d->_userAddress;
}

QString RemoteControlUser::userAddressString() const
{
  return this->_d->_userAddress.toString();
}

quint16 RemoteControlUser::userPort() const
{
  return this->_d->_userPort;
}

const QHostAddress& RemoteControlUser::remoteControlAddress() const
{
  Q_ASSERT(this->remoteConnectionManager());

  return this->remoteConnectionManager()->remoteAddress();
}

quint16 RemoteControlUser::remoteControlPort() const
{
  Q_ASSERT(this->remoteConnectionManager());

  return this->remoteConnectionManager()->remotePort();
}

const QString& RemoteControlUser::remoteControlServiceProvider() const
{
  Q_ASSERT(this->remoteConnectionManager());

  return this->remoteConnectionManager()->remoteServiceProvider();
}

void RemoteControlUser::setRemoteState(const QString& remoteState)
{
  this->_d->_remoteState=remoteState;

  return;
}

} // namespace remotecontrol
