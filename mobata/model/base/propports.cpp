#include "propports.hpp"

#include "portitem.hpp"
#include "../../utils/functors.hpp"

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

#include "../../memory_leak_start.hpp"

namespace model {
namespace base {

class PropPorts::Private
{
  friend class PropPorts;

  Private(QStandardItem* parent)
    : _parentItem(parent),
      _portsItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _parentItem;
  QStandardItem*  _portsItem;
};

PropPorts::PropPorts(QStandardItem* parentItem)
  : _d(new Private(parentItem))
{
  Q_ASSERT(parentItem);
}

PropPorts::~PropPorts()
{
  delete this->_d;
}

void PropPorts::resetPorts()
{
  if(this->_d->_portsItem)
    this->_d->_portsItem->removeRows(0, this->_d->_portsItem->rowCount());

  return;
}

void PropPorts::clonePorts(PropPorts* clonePorts) const
{
  Q_ASSERT(clonePorts);

  bool result = false;
  for(PortItem const* port : this->ports())
  {
    PortItem* clonePort = new PortItem(port->name());
    result = clonePorts->addPort(clonePort);
    Q_ASSERT(result);
  }

  return;
}

PropPorts::ConstPortSet PropPorts::ports() const
{
  ConstPortSet portSet;
  if(!this->_d->_portsItem)
    return portSet;

  int portsCount=this->_d->_portsItem->rowCount();

  for(int i =0; i < portsCount; ++i)
  {
    QStandardItem*  currChild=this->_d->_portsItem->child(i);
    PortItem* currentPort=utils::simple_cast<PortItem*>(currChild);
    Q_ASSERT(currentPort);
    portSet.append(currentPort);
  }

  return portSet;
}

PropPorts::PortSet PropPorts::ports()
{
  PortSet portSet;
  if(!this->_d->_portsItem)
    return portSet;

  int portsCount=this->_d->_portsItem->rowCount();
  for(int i =0; i < portsCount; ++i)
  {
    QStandardItem*  currChild=this->_d->_portsItem->child(i);
    PortItem* currentPort=utils::simple_cast<PortItem*>(currChild);
    Q_ASSERT(currentPort);
    portSet.append(currentPort);
  }

  return portSet;
}

PortItem* PropPorts::portById(const QUuid &portUuid)
{
  for(PortItem* portItem : this->ports())
    if(portItem->uuid()==portUuid)
      return portItem;

  return 0;
}

PortItem* PropPorts::port(const QString& portName)
{
  for(PortItem* port :  this->ports())
    if(port->name()==portName)
      return port;

  return 0;
}

PortItem const* PropPorts::portById(const QUuid &portUuid) const
{
  for(PortItem const* portItem : this->ports())
    if(portItem->uuid()==portUuid)
      return portItem;

  return 0;
}

PortItem const* PropPorts::port(const QString &portName) const
{
  for(PortItem const* portItem : this->ports())
    if(portItem->name()==portName)
      return portItem;

  return 0;
}

bool PropPorts::addPort(PortItem *port,
                        QString* errorString)
{
  Q_ASSERT(this->_d->_parentItem);

  if(!port)
    return false;

  if(!this->_d->_portsItem)
  {
    this->_d->_portsItem=new QStandardItem(QIcon(":/mobata/images/base/manyport.png"),
                                           "ports");
    this->_d->_portsItem->setFlags(this->_d->_portsItem->flags()  & ~Qt::ItemIsEditable);
    this->_d->_parentItem->appendRow(this->_d->_portsItem);
  }

  if(this->port(port->name()))
  {
    if(port->name() == QStringLiteral("_defaultPort")){
      this->port(port->name())->setUuid(port->uuid());
      return true;
    }
    if(errorString)
      *errorString+=QObject::tr((QLatin1String("There is already a port '")
                                 +port->name()
                                 +QLatin1String("' available!")).toLatin1());
    return false;
  }

  this->_d->_portsItem->appendRow(port);

  return true;
}

PortItem* PropPorts::addPort(const QString& portName,
                             QString* errorString)
{
  Q_ASSERT(this->_d->_parentItem);

  if(!this->_d->_portsItem)
  {
    this->_d->_portsItem=new QStandardItem(QIcon(":/mobata/images/base/manyport.png"),
                                           "ports");
    this->_d->_portsItem->setFlags(this->_d->_portsItem->flags()  & ~Qt::ItemIsEditable);
    this->_d->_parentItem->appendRow(this->_d->_portsItem);
  }

  if(this->port(portName))
  {
    if(portName == QStringLiteral("_defaultPort")){
      return this->port(portName);
    }
    if(errorString)
      *errorString+=QObject::tr((QLatin1String("There is already a port '")
                                 +portName
                                 +QLatin1String("' available!")).toLatin1());
    return 0;
  }

  PortItem* newPort=new PortItem(portName);
  this->_d->_portsItem->appendRow(newPort);

  return newPort;
}

void PropPorts::removePortById(const QUuid& portUuid)
{
  for(PortItem* currPort : this->ports()){
    if(currPort->uuid() == portUuid)
      this->_d->_portsItem->removeRow(currPort->row());
  }

  if(this->_d->_portsItem->rowCount() == 0)
  {
    this->_d->_parentItem->removeRow(this->_d->_portsItem->row());
    this->_d->_portsItem = 0;
  }

  return;
}

void PropPorts::removePort(const QString& portName)
{
  PortItem const* portItem=this->port(portName);
  if(portItem)
    this->_d->_portsItem->removeRow(portItem->row());

  if(this->_d->_portsItem->rowCount() == 0)
  {
    this->_d->_parentItem->removeRow(this->_d->_portsItem->row());
    this->_d->_portsItem = 0;
  }

  return;
}

void writePorts(PropPorts const* propPorts,
                QJsonObject* json_propPortsObject)
{
  Q_ASSERT(propPorts);
  Q_ASSERT(json_propPortsObject);

  QJsonArray json_ports;
  for(PortItem const* portItem : propPorts->ports())
  {
    QJsonObject json_port;
    json_port["name"]=portItem->name();
    json_ports.push_back(json_port);
  }
  json_propPortsObject->insert("ports", json_ports);

  return;
}

bool readPorts(const QJsonObject* json_propPortsObject,
               PropPorts* propPorts,
               QString* errorString)
{
  Q_ASSERT(json_propPortsObject);
  Q_ASSERT(propPorts);

  QJsonArray portsArray = (*json_propPortsObject)["ports"].toArray();
  for (int portIndex = 0; portIndex < portsArray.size(); ++portIndex)
  {
    QJsonObject portObject = portsArray[portIndex].toObject();
    QString portName = portObject["name"].toString();
    PortItem* newPort = new PortItem(portName);
    propPorts->addPort(newPort, errorString);
  }

  return true;
}


} // namespace base
} // namespace model
