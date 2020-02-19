#include "remotecomponent.hpp"

#include "remoteconnectionmanager.hpp"

#include <QSignalMapper>

#include <mobata/memory_leak_start.hpp>

namespace remotecontrol {

class RemoteComponent::Private
{
  friend class RemoteComponent;

  RemoteConnectionManager*  _connectionManager;

  Private()
    : _connectionManager(0)
  {}
};

RemoteComponent::RemoteComponent(const QString& name,
                                 QObject *parent,
                                 QHostAddress address,
                                 quint16 port)
  : QObject(parent), prop::NameProperty(name), _d(new Private)
{
  this->_d->_connectionManager=new RemoteConnectionManager(QStringLiteral("remotecomponent"),
                                                           address,
                                                           port,
                                                           this);
  connect(this->_d->_connectionManager, &RemoteConnectionManager::connectionError,
          this, &RemoteComponent::error);
  connect(this->_d->_connectionManager, &RemoteConnectionManager::messageSent,
          this, &RemoteComponent::messageSent);
}

RemoteComponent::~RemoteComponent()
{
  delete this->_d;
}

RemoteConnectionManager* RemoteComponent::remoteConnectionManager()
{
  return this->_d->_connectionManager;
}

RemoteConnectionManager const* RemoteComponent::remoteConnectionManager() const
{
  return this->_d->_connectionManager;
}

void RemoteComponent::sendMessageSlot(const QString& messageName,
                                      const QVariantList& paramValues,
                                      const QUuid& messageID)
{
  Q_ASSERT(this->_d->_connectionManager);

  this->_d->_connectionManager->sendMessage(messageName, paramValues, messageID);

  return;
}

} // namespace remotecontrol
