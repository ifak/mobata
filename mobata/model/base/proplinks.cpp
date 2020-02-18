#include "proplinks.hpp"

#include "linkitem.hpp"
#include "portitem.hpp"

#include "../../utils/functors.hpp"

#include <QStandardItem>
#include <QUuid>

#include "../../memory_leak_start.hpp"

namespace model {
namespace base {

class PropLinks::Private
{
  friend class PropLinks;

  Private()
    : _linksItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*	_linksItem;
};

PropLinks::PropLinks(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setLinksParentItem(parentItem);
}

PropLinks::~PropLinks()
{
  delete this->_d;
}

void PropLinks::resetLinks()
{
  if(this->_d->_linksItem)
    this->_d->_linksItem->removeRows(0, this->_d->_linksItem->rowCount());

  return;
}

void PropLinks::setLinksParentItem(QStandardItem* linksParentItem)
{
  Q_ASSERT(linksParentItem);

  if(this->_d->_linksItem)
    return;

  this->_d->_linksItem=new QStandardItem(QIcon(QLatin1String(":/mobata/images/base/manylink.png")),
                                         QLatin1String("links"));
  this->_d->_linksItem->setFlags(this->_d->_linksItem->flags() & ~Qt::ItemIsEditable);
  linksParentItem->appendRow(this->_d->_linksItem);

  return;
}

LinkItem* PropLinks::addLink(PortItem const* from,
                             PortItem const* to,
                             QString* errorString)
{
  Q_ASSERT(this->_d->_linksItem);
  Q_ASSERT(from);
  Q_ASSERT(to);

  if(this->link(from, to))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a link between '%1' and '%2'!")
                                      .arg(from->toString())
                                      .arg(to->toString());
    return 0;
  }

  LinkItem* newLinkItem=new LinkItem(from, to);
  this->_d->_linksItem->appendRow(newLinkItem);

  return newLinkItem;
}

bool PropLinks::addLink(LinkItem* newLink,
                        QString* errorString)
{
  Q_ASSERT(this->_d->_linksItem);
  Q_ASSERT(newLink);

  if(this->link(newLink->from(), newLink->to()))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a link between '%1' and '%2'!")
                                      .arg(newLink->from()->toString())
                                      .arg(newLink->to()->toString());
    return false;
  }

  this->_d->_linksItem->appendRow(newLink);

  return true;
}

void PropLinks::removeLink(const QUuid& linkUuid)
{
  Q_ASSERT(this->_d->_linksItem);

  LinkItem* remLink = this->link(linkUuid);
  if(remLink)
    this->_d->_linksItem->removeRow(remLink->row());

  return;
}

LinkItem* PropLinks::link(const QUuid& linkUuid)
{
  return utils::FindByUuid<LinkSet>()(linkUuid, this->links());
}

LinkItem const* PropLinks::link(const QUuid& linkUuid) const
{
  return utils::FindByUuid<ConstLinkSet>()(linkUuid, this->links());
}

LinkItem* PropLinks::link(PortItem const* from,
                          PortItem const* to)
{
  for(LinkItem* linkItem : this->links())
  {
    if(linkItem->from() == from
       && linkItem->to() == to)
      return linkItem;
  }

  return 0;
}

LinkItem const* PropLinks::link(PortItem const* from,
                                PortItem const* to) const
{
  for(LinkItem const* linkItem : this->links())
  {
    if(linkItem->from() == from
       && linkItem->to() == to)
      return linkItem;
  }

  return 0;
}

PropLinks::LinkSet PropLinks::links()
{
  LinkSet links;
  if(!this->_d->_linksItem)
    return links;

  int end=this->_d->_linksItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    LinkItem* link=utils::simple_cast<LinkItem*>(this->_d->_linksItem->child(i));
    Q_ASSERT(link);
    links.append(link);
  }

  return links;
}

PropLinks::ConstLinkSet PropLinks::links() const
{
  ConstLinkSet links;
  if(!this->_d->_linksItem)
    return links;

  int end=this->_d->_linksItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    LinkItem* link=utils::simple_cast<LinkItem*>(this->_d->_linksItem->child(i));
    Q_ASSERT(link);
    links.append(link);
  }

  return links;
}

} // namespace base
} // namespace model

