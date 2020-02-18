#include "remoteuserapp.hpp"

#include <QNetworkInterface>
#include <QHostAddress>

RemoteUserService::RemoteUserService(QObject* parent)
  : remotecontrol::RemoteControlUserService(parent)
{}

RemoteUserApp::RemoteUserApp(const QString& name,
                             RemoteUserService* remoteUserService,
                             QObject *parent)
  : remotecontrol::RemoteControlUser(name, remoteUserService, parent)
{}

void RemoteUserApp::open()
{
  qDebug()<<"RemoteUserApp::open() executed!";
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("open"),
                                               QVariantList()
                                               <<this->userAddressString()
                                               <<this->userPort());

  return;
}

void RemoteUserApp::setup()
{
  qDebug()<<"RemoteUserApp::setup() executed!";
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("setup"));

  return;
}

void RemoteUserApp::close()
{
  qDebug()<<"RemoteUserApp::close() executed!";
  Q_ASSERT(this->remoteConnectionManager());

  this->remoteConnectionManager()->sendMessage(QStringLiteral("close"));

  return;
}

QStringList RemoteUserApp::availableIPs()
{
  QStringList availableIPList;
  for(const QHostAddress &address : QNetworkInterface::allAddresses())
  {
    if (address.protocol() == QAbstractSocket::IPv4Protocol
        /*&& address != QHostAddress(QHostAddress::LocalHost)*/)
    {
      qDebug() << address.toString();
      availableIPList.append(address.toString());
    }
  }

  return availableIPList;
}

bool RemoteUserApp::setRemoteAddress(const QString& remoteAddressString)
{
  QHostAddress remoteAddress;
  bool result = false;
  if(remoteAddressString.trimmed().compare("localhost", Qt::CaseInsensitive)==0)
    result = remoteAddress.setAddress("127.0.0.1");
  else
    result = remoteAddress.setAddress(remoteAddressString);
  if(!result)
    return false;

  this->setRemoteControlAddress(remoteAddress);

  return true;
}

bool RemoteUserApp::setRemotePort(const QString& remotePortString)
{
  bool result;
  int remotePort = remotePortString.toInt(&result);
  if(!result)
    return false;

  this->setRemoteControlPort(remotePort);

  return true;
}

bool RemoteUserApp::setLocalAddress(const QString& localAddressString)
{
  QHostAddress localAddress;
  bool result = false;
  if(localAddressString.trimmed().compare("localhost", Qt::CaseInsensitive)==0)
    result = localAddress.setAddress("127.0.0.1");
  else
    result = localAddress.setAddress(localAddressString);
  if(!result)
    return false;

  this->setUserAddress(localAddress);

  return true;
}

bool RemoteUserApp::setLocalPort(const QString& localPortString)
{
  bool result;
  int localPort = localPortString.toInt(&result);
  if(!result)
    return false;

  this->setUserPort(localPort);

  return true;
}
