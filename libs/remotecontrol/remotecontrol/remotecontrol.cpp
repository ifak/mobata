#include "remotecontrol.hpp"

#include "remoteconnectionmanager.hpp"
#include "remotecontrolservice.hpp"
#include "remotecontrolstatemachineqml.hpp"
#include "remotecontrolfunctors.hpp"
#include "remoteport.hpp"
#include "controlport.hpp"

#include <qjsonrpctcpserver.h>
#include <qjsonrpcsocket.h>
#include <qjsonrpcservicereply.h>

#include <mobata/utils/functors.hpp>

#include <QTimer>
#include <QUuid>

namespace remotecontrol {

class RemoteControl::Private
{
  friend class RemoteControl;

  RemoteControlService* _remoteControlService;
  QHostAddress          _localAddress;
  quint16               _localPort;
  QJsonRpcTcpServer*    _jsonRpcServer;
  QStringList           _errors;

  RemotePort                    _remotePort;
  ControlPort                   _controlPort;
  RemoteControlStateMachineQml* _remoteControlStateMachine;

  QTimer* _statusRequestTimer;

  Private(RemoteControlService* remoteControlService, QHostAddress userAddress, quint16 userPort)
    : _remoteControlService(remoteControlService),
      _localAddress(userAddress),
      _localPort(userPort),
      _jsonRpcServer(0)
  {}
};

RemoteControl::RemoteControl(const QString& name,
                             RemoteControlService* remoteControlService,
                             QObject* parent, QHostAddress remoteAddress, quint16 remotePort, QHostAddress userAddress, quint16 userPort)
  : RemoteComponent(name, parent, userAddress, userPort),
    _d(new Private(remoteControlService, userAddress, userPort))
{
  Q_ASSERT(this->_d->_remoteControlService);
  this->_d->_remoteControlService->setRemoteControl(this);

  this->remoteConnectionManager()->setRemoteAddress(remoteAddress);
  this->remoteConnectionManager()->setRemotePort(remotePort);
  this->remoteConnectionManager()->setRemoteServiceProvider(QStringLiteral("remotecontroluser"));

  this->_d->_jsonRpcServer = new QJsonRpcTcpServer(this);
  this->_d->_jsonRpcServer->addService(this->_d->_remoteControlService);

  //remote control state machine
  this->_d->_remoteControlStateMachine = new RemoteControlStateMachineQml(QStringLiteral("remote control state machine"),
                                                                          &this->_d->_remotePort,
                                                                          &this->_d->_controlPort,
                                                                          this);

  this->_d->_statusRequestTimer=new QTimer(this);
  this->_d->_statusRequestTimer->setInterval(3000);

  connect(&this->_d->_remotePort, &RemotePort::setuped, this,
          [=](bool value, const QString& message)
  {
    Q_ASSERT(this->remoteConnectionManager());

    QVariantList args;
    args.append(value);
    args.append(QStringList()<<message);
    this->remoteConnectionManager()->sendMessage(QStringLiteral("setuped"), args);
  }, Qt::QueuedConnection);

  connect(&this->_d->_remotePort, &RemotePort::started, this,
          [=](bool value, const QString& message)
  {
    Q_ASSERT(this->remoteConnectionManager());

    QVariantList args;
    args.append(value);
    args.append(QStringList()<<message);
    this->remoteConnectionManager()->sendMessage(QStringLiteral("started"), args);
  }, Qt::QueuedConnection);

  connect(&this->_d->_remotePort, &RemotePort::stopped, this,
          [=](bool value, const QString& message)
  {
    Q_ASSERT(this->remoteConnectionManager());

    QVariantList args;
    args.append(value);
    args.append(QStringList()<<message);
    this->remoteConnectionManager()->sendMessage(QStringLiteral("stopped"), args);
  }, Qt::QueuedConnection);

  connect(&this->_d->_remotePort, &RemotePort::resetted, this,
          [=](bool value, const QString& message)
  {
    Q_ASSERT(this->remoteConnectionManager());

    QVariantList args;
    args.append(value);
    args.append(QStringList()<<message);
    this->remoteConnectionManager()->sendMessage(QStringLiteral("resetted"), args);
  }, Qt::QueuedConnection);

  connect(&this->_d->_remotePort, &RemotePort::finished, this,
          [=](bool value, const QString& message)
  {
//    qDebug()<<"RemotePort::finished received!";
    Q_ASSERT(this->remoteConnectionManager());

    QVariantList args;
    args.append(value);
    args.append(QStringList()<<message);
    this->remoteConnectionManager()->sendMessage(QStringLiteral("finished"), args);
  }, Qt::QueuedConnection);

  connect(this->_d->_remoteControlService, &RemoteControlService::statusRequest, this,
          [=]()
  {
    emit this->_d->_controlPort.statusRequest();
    this->_d->_statusRequestTimer->start();
  });

  connect(this->_d->_statusRequestTimer, &QTimer::timeout,
          this, [=]()
  {
    this->_d->_statusRequestTimer->stop();

    QString currentState=this->_d->_remoteControlStateMachine->currentState();

    Q_ASSERT(this->remoteConnectionManager());

    QVariantList args;
    args.append(currentState);
    args.append(QStringList()
                <<tr("timeout for status request! no status message available!")
                <<this->_d->_errors);
    this->remoteConnectionManager()->sendMessage(QStringLiteral("statusResponse"), args);
  });

  connect(&this->_d->_remotePort, &RemotePort::statusResponse,
          this,[=](const QStringList& messages)
  {
    this->_d->_statusRequestTimer->stop();

    QString currentState=this->_d->_remoteControlStateMachine->currentState();

    Q_ASSERT(this->remoteConnectionManager());

    QVariantList args;
    args.append(currentState);
    args.append(QStringList()<<messages);
    this->remoteConnectionManager()->sendMessage(QStringLiteral("statusResponse"), args);
  }, Qt::QueuedConnection);

//  qDebug() << "Remote Control initialized!";
}

RemoteControl::~RemoteControl()
{
  this->_d->_jsonRpcServer->close();

  delete this->_d;
}

bool RemoteControl::run(const QHostAddress& localAddress,
                        const quint16 localPort,
                        QString* errorString)
{
  this->_d->_localAddress=localAddress;
  this->_d->_localPort=localPort;

  return this->run(errorString);
}

bool RemoteControl::run(QString* errorString)
{
  Q_ASSERT(this->_d->_jsonRpcServer);

  if(!this->_d->_jsonRpcServer->isListening())
  {
    if(!this->_d->_jsonRpcServer->listen(this->_d->_localAddress,
                                         this->_d->_localPort))
    {
      QString errorMessage = this->_d->_jsonRpcServer->errorString();
      if(errorString)
        *errorString += errorMessage;
      return false;
    }
  }
  else
  {
    this->_d->_jsonRpcServer->close();
    Q_ASSERT(!this->_d->_jsonRpcServer->isListening());
    if(!this->_d->_jsonRpcServer->listen(this->_d->_localAddress,
                                         this->_d->_localPort))
    {
      QString errorMessage = this->_d->_jsonRpcServer->errorString();
      if(errorString)
        *errorString += errorMessage;
      return false;
    }
  }

  return true;
}

bool RemoteControl::isRunning() const
{
  Q_ASSERT(this->_d->_jsonRpcServer);

  return this->_d->_jsonRpcServer->isListening();
}

RemotePort* RemoteControl::remotePort()
{
  return &this->_d->_remotePort;
}

ControlPort* RemoteControl::controlPort()
{
  return &this->_d->_controlPort;
}

void RemoteControl::sendMessage(const QString& message)
{
//  qDebug()<<"DisTestComponentRemote::sendMessage() executed!";

  this->remoteConnectionManager()->sendMessage(QStringLiteral("message"),
                                               QVariantList()<<message);

  return;
}

const QStringList& RemoteControl::errors() const
{
  return this->_d->_errors;
}

void RemoteControl::addError(const QString& error)
{
  this->_d->_errors.append(error);

  return;
}

void RemoteControl::setLocalAddress(const QHostAddress& localAddress)
{
  this->_d->_localAddress = localAddress;

  return;
}

void RemoteControl::setLocalPort(const quint16 localPort)
{
  this->_d->_localPort = localPort;

  return;
}

void RemoteControl::setUserAddress(const QHostAddress& userAddress)
{
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->setRemoteAddress(userAddress);

  return;
}

void RemoteControl::setUserPort(const quint16 userPort)
{
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->setRemotePort(userPort);

  return;
}

void RemoteControl::setUserServiceProvider(const QString& userServiceProvider)
{
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->setRemoteServiceProvider(userServiceProvider);

  return;
}

const QHostAddress& RemoteControl::localAddress() const
{
  return this->_d->_localAddress;
}

quint16 RemoteControl::localPort() const
{
  return this->_d->_localPort;
}

const QHostAddress& RemoteControl::userAddress() const
{
  Q_ASSERT(this->remoteConnectionManager());

  return this->remoteConnectionManager()->remoteAddress();
}

quint16 RemoteControl::userPort() const
{
  Q_ASSERT(this->remoteConnectionManager());

  return this->remoteConnectionManager()->remotePort();
}

const QString&RemoteControl::userServiceProvider() const
{
  Q_ASSERT(this->remoteConnectionManager());

  return this->remoteConnectionManager()->remoteServiceProvider();
}

} // namespace remotecontrol

