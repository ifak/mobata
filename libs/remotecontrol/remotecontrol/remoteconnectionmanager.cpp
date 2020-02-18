#include "remoteconnectionmanager.hpp"

#include "remotecontrolfunctors.hpp"

#include <QTcpSocket>

#include <qjsonrpcsocket.h>
#include <qjsonrpcservicereply.h>

#include <mobata/memory_leak_start.hpp>

namespace remotecontrol {

struct OpenRequestMessage
{
  QUuid         messageID;
  QString       messageName;
  QVariantList  messageParams;

  OpenRequestMessage()  {}
  OpenRequestMessage(const QUuid& mID, const QString& mName, const QVariantList& mParams)
    : messageID(mID), messageName(mName), messageParams(mParams)
  {}
};

typedef QHash<QJsonRpcServiceReply*, QUuid> OpenReplyMap;

class RemoteConnectionManager::Private
{
  friend class RemoteConnectionManager;

  QHostAddress    _remoteAddress;
  quint16         _remotePort;
  QString         _serviceProvider;
  QTcpSocket*     _tcpSocket;
  QJsonRpcSocket* _jsonRpcSocket;

  QVector<OpenRequestMessage> _openRequests;
  OpenReplyMap                _openReplies;

  Private(const QHostAddress& remoteAddress,
          quint16 remotePort,
          const QString& serviceProvider)
    : _remoteAddress(remoteAddress),
      _remotePort(remotePort),
      _serviceProvider(serviceProvider),
      _tcpSocket(nullptr)
  {}
};

RemoteConnectionManager::RemoteConnectionManager(QObject* parent)
  : QObject(parent),
    _d(new Private(QHostAddress::LocalHost, 10000, QStringLiteral("remotecontrol")))
{
  this->_d->_tcpSocket = new QTcpSocket(this);
  this->_d->_jsonRpcSocket = new QJsonRpcSocket(this->_d->_tcpSocket, this);

  connect(this->_d->_tcpSocket, &QTcpSocket::connected,
          this, &RemoteConnectionManager::connectedSlot,
          Qt::UniqueConnection);
  connect(this->_d->_tcpSocket, static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
          this, &RemoteConnectionManager::errorSlot,
          Qt::UniqueConnection);
}

RemoteConnectionManager::RemoteConnectionManager(const QString& serviceProvider,
                                                 QObject* parent)
  : QObject(parent),
    _d(new Private(QHostAddress::LocalHost, 10000, serviceProvider))
{
  this->_d->_tcpSocket = new QTcpSocket(this);
  this->_d->_jsonRpcSocket = new QJsonRpcSocket(this->_d->_tcpSocket, this);

  connect(this->_d->_tcpSocket, &QTcpSocket::connected,
          this, &RemoteConnectionManager::connectedSlot,
          Qt::UniqueConnection);
  connect(this->_d->_tcpSocket, static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
          this, &RemoteConnectionManager::errorSlot,
          Qt::UniqueConnection);
}

RemoteConnectionManager::RemoteConnectionManager(const QString& serviceProvider, const QHostAddress& remoteAddress,
                                                 quint16 remotePort,
                                                 QObject* parent)
  : QObject(parent),
    _d(new Private(remoteAddress, remotePort, serviceProvider))
{
  this->_d->_tcpSocket = new QTcpSocket(this);
  this->_d->_jsonRpcSocket = new QJsonRpcSocket(this->_d->_tcpSocket, this);

  connect(this->_d->_tcpSocket, &QTcpSocket::connected,
          this, &RemoteConnectionManager::connectedSlot,
          Qt::UniqueConnection);
  connect(this->_d->_tcpSocket, static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
          this, &RemoteConnectionManager::errorSlot,
          Qt::UniqueConnection);
}

RemoteConnectionManager::~RemoteConnectionManager()
{
  this->_d->_tcpSocket->close();

  qDeleteAll(this->_d->_openReplies.keys());

  delete this->_d;
}

void RemoteConnectionManager::startConnection()
{
  Q_ASSERT(this->_d->_tcpSocket);
  Q_ASSERT(this->_d->_jsonRpcSocket);

  if(this->_d->_tcpSocket->state()==QTcpSocket::UnconnectedState)
    this->_d->_tcpSocket->connectToHost(this->_d->_remoteAddress,
                                        this->_d->_remotePort);
  else if(this->_d->_tcpSocket->state()==QTcpSocket::BoundState)
    qWarning()<<"The socket is bound to address '"<<this->_d->_remoteAddress
             <<"' and port '"<<this->_d->_remotePort<<"'!";
  else if(this->_d->_tcpSocket->state()==QTcpSocket::ClosingState)
    qWarning()<<"tcp socket with address '"<<this->_d->_remoteAddress
             <<"' and port '"<<this->_d->_remotePort<<"' is about to close!";

  return;
}

bool RemoteConnectionManager::isConnected() const
{
  return this->_d->_tcpSocket->state()==QAbstractSocket::ConnectedState;
}

void RemoteConnectionManager::setRemoteAddress(const QHostAddress& remoteAddress)
{
  this->_d->_remoteAddress=remoteAddress;

  return;
}

void RemoteConnectionManager::setRemotePort(quint16 remotePort)
{
  this->_d->_remotePort = remotePort;

  return;
}

void RemoteConnectionManager::setRemoteServiceProvider(const QString &serviceProvider)
{
  this->_d->_serviceProvider=serviceProvider;

  return;
}

const QHostAddress& RemoteConnectionManager::remoteAddress() const
{
  return this->_d->_remoteAddress;
}

quint16 RemoteConnectionManager::remotePort() const
{
  return this->_d->_remotePort;
}

const QString& RemoteConnectionManager::remoteServiceProvider() const
{
  return this->_d->_serviceProvider;
}

QJsonRpcSocket* RemoteConnectionManager::jsonRpcSocket()
{
  return this->_d->_jsonRpcSocket;
}

void RemoteConnectionManager::sendMessage(const QString& messageName, const QUuid& messageID)
{
  return this->sendMessage(messageName, QVariantList(), messageID);
}

void RemoteConnectionManager::sendMessage(const QString& messageName,
                                          const QVariantList& messageParams,
                                          const QUuid& messageID)
{
//  qDebug()<<"RemoteConnectionManager::sendMessage() executed! messageName: '"<<messageName
//         <<"' messageParams: '"<<messageParams<<"' messageID: '"<<messageID<<"'";

  Q_ASSERT(this->_d->_jsonRpcSocket);

  if(this->isConnected())
  {
    QString method = this->_d->_serviceProvider
                     + QStringLiteral(".")
                     + messageName;
//    qDebug()<<"method: "<<method;

    QJsonRpcMessage request =
        QJsonRpcMessage::createRequest(method, QJsonArray::fromVariantList(messageParams));
    QJsonRpcServiceReply* reply= this->_d->_jsonRpcSocket->sendMessage(request);
    connect(reply, &QJsonRpcServiceReply::finished,
            this, &RemoteConnectionManager::replyFinishedSlot);
    this->_d->_openReplies.insert(reply, messageID);
  }
  else
  {
    this->_d->_openRequests.push_back(OpenRequestMessage(messageID,messageName,messageParams));
    this->startConnection();
  }

  return;
}

void RemoteConnectionManager::connectedSlot()
{
//  qDebug()<<"RemoteConnectionManager::connectedSlot() executed!";

  Q_ASSERT(this->_d->_jsonRpcSocket);

  for(OpenRequestMessage& openRequest : this->_d->_openRequests)
  {
    QString method = this->_d->_serviceProvider
                     + QStringLiteral(".")
                     + openRequest.messageName;
//    qDebug()<<"method: "<<method;

    QJsonRpcMessage request =
        QJsonRpcMessage::createRequest(method, QJsonArray::fromVariantList(openRequest.messageParams));
    QJsonRpcServiceReply* reply= this->_d->_jsonRpcSocket->sendMessage(request);
    connect(reply, &QJsonRpcServiceReply::finished,
            this, &RemoteConnectionManager::replyFinishedSlot);
    this->_d->_openReplies.insert(reply, openRequest.messageID);
  }

  return;
}

void RemoteConnectionManager::replyFinishedSlot()
{
//  qDebug()<<"RemoteConnectionManager::replyFinishedSlot() executed!";

  QJsonRpcServiceReply* reply= qobject_cast<QJsonRpcServiceReply*>(this->sender());

  QUuid messageID=this->_d->_openReplies.value(reply, QUuid());
  if(messageID.isNull())
    return;

  this->_d->_openReplies.remove(reply);
  disconnect(reply, &QJsonRpcServiceReply::finished,
             this, &RemoteConnectionManager::replyFinishedSlot);

  bool result=true; QString errorMessage;
  ProcessRemoteReply()(reply->response(),&result,&errorMessage);
  if(!result)
    emit messageSent(messageID, false, errorMessage);
  else
    emit messageSent(messageID, true);

  reply->deleteLater();

  return;
}

void RemoteConnectionManager::errorSlot(QAbstractSocket::SocketError socketError)
{
//  qDebug()<<"RemoteConnectionManager::errorSlot() executed!";

  Q_UNUSED(socketError);

  emit this->connectionError(this->_d->_tcpSocket->errorString());

  return;
}

} // namespace remotecontrol
