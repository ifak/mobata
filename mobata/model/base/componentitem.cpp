#include "componentitem.hpp"

#include "portitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{

ComponentItem::ComponentItem(const QString &name)
  : prop::NameProperty(name),
    PropAttributes(this),
    PropPorts(this)
{
  this->setIcon(QIcon(":mobata/images/msc/component.png"));
  this->setText(this->toString());
}

ComponentItem::~ComponentItem()
{}

int ComponentItem::compType() const
{
  return ComponentType;
}

QString ComponentItem::compTypeString() const
{
  return QStringLiteral("ComponentType");
}

bool ComponentItem::addPort(PortItem *port, QString *errorString)
{
  if(!port)
    return false;

  port->setOwner(this);
  return PropPorts::addPort(port, errorString);
}

PortItem* ComponentItem::addPort(const QString &portName,
                                 QString *errorString)
{
  PortItem* newPort=PropPorts::addPort(portName, errorString);
  if(!newPort)
    return nullptr;

  newPort->setOwner(this);

  return newPort;
}

ComponentItem*ComponentItem::clone() const
{
  ComponentItem* cloneComponent = new ComponentItem(this->name());
  this->cloneAttributes(cloneComponent);
  this->clonePorts(cloneComponent);

  return cloneComponent;
}

QString ComponentItem::toString() const
{
  return this->name();
}

}/// end namespace base
}/// end namespace model
