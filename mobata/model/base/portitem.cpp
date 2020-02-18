#include "portitem.hpp"

#include "componentitem.hpp"
#include "linkitem.hpp"

#include <QDebug>

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{

PortItem::PortItem(const QString& name,
                   ComponentItem const* owner,
                   const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _owner(owner),
    _ownerType(Component)
{
  this->setIcon(QIcon(QLatin1String(":/mobata/images/base/port.png")));
  this->setText(this->name());
}

PortItem::PortItem(const QString& name,
                   LinkItem const* owner,
                   const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _owner(owner),
    _ownerType(Link)
{
  this->setIcon(QIcon(QLatin1String(":/mobata/images/base/port.png")));
  this->setText(this->name());
}

PortItem::PortItem(const QString& name,
                   const QUuid& uuid)
  : ModelItem(uuid),
    prop::NameProperty(name),
    _owner(nullptr),
    _ownerType(Unknown)
{
  this->setIcon(QIcon(QLatin1String(":/mobata/images/base/port.png")));
  this->setText(this->name());
}

PortItem::~PortItem()
{
  qDebug()<<this<<"Port deleted"<<this->name();
}

ModelItem const* PortItem::owner() const
{
  return this->_owner;
}

void PortItem::setOwner(ComponentItem const* component)
{
  this->_owner=component;
  this->_ownerType=Component;

  return;
}

void PortItem::setOwner(LinkItem const* link)
{
  this->_owner=link;
  this->_ownerType=Link;

  return;
}

PortItem::OwnerType PortItem::ownerType() const
{
  return this->_ownerType;
}

QString PortItem::toString() const
{
  QString portString=QStringLiteral("");
  if(this->_owner)
    portString+=this->_owner->toString()+QStringLiteral(".");

  portString+=this->name();

  return portString;
}

}/// namespace base
}/// namespace model
