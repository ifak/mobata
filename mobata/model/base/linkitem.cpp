#include "linkitem.hpp"

#include "portitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace base {

class LinkItem::Private
{
  friend class LinkItem;

  Private(const PortItem* from,
          const PortItem* to,
          const QString& notation)
    : _from(from), _to(to), _notation(notation)
  {}

  PortItem const* _from;
  PortItem const* _to;
  PortItem*       _port;
  QString         _notation;
};

LinkItem::LinkItem(const PortItem* from,
                   const PortItem* to,
                   const QString& notation)
  : ModelItem(), _d(new Private(from, to, notation))
{
  this->_d->_port=new PortItem(QStringLiteral("port"),
                               this);
  this->setIcon(QIcon(QStringLiteral(":/mobata/images/base/link.png")));
  this->setText(this->toString());
}

LinkItem::~LinkItem()
{
  delete this->_d->_port;
  delete this->_d;
}

PortItem const* LinkItem::from() const
{
  return this->_d->_from;
}

PortItem const* LinkItem::to() const
{
  return this->_d->_to;
}

const PortItem*LinkItem::port() const
{
  return this->_d->_port;
}

void LinkItem::setNotation(const QString &notation)
{
  this->_d->_notation=notation;
  this->setText(this->toString());

  return;
}

const QString& LinkItem::notation() const
{
  return this->_d->_notation;
}

QString LinkItem::toString() const
{
  if(!this->_d->_notation.trimmed().isEmpty())
    return this->_d->_notation.trimmed();

  QString linkString(QStringLiteral(""));

  if(this->_d->_from)
    linkString+=this->_d->_from->toString();
  else
    linkString+=QStringLiteral("???");

  linkString+=QStringLiteral(" -> ");

  if(this->_d->_to)
    linkString+=this->_d->_to->toString();
  else
    linkString+=QStringLiteral("???");

  return linkString;
}

} // namespace base
} // namespace model
