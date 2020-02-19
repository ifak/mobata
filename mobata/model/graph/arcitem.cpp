#include "arcitem.hpp"

#include "nodeitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace graph{

class ArcItem::Private
{
  friend class ArcItem;

  Private(NodeItem *source,
          NodeItem *target)
    :	_source(source), _target(target)
  {}

public:
  ~Private()
  {}

private:
  NodeItem* _source;
  NodeItem* _target;
};

ArcItem::ArcItem(NodeItem *source,
                 NodeItem *target,
                 const QUuid arcUuid)
  :	ModelItem(arcUuid),
    _d(new Private(source, target))
{
  this->setText(this->toString());
  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/edge.png")));
}

ArcItem::~ArcItem()
{}

NodeItem* ArcItem::source() const
{
  return this->_d->_source;
}

NodeItem* ArcItem::target() const
{
  return this->_d->_target;
}

void ArcItem::setSource(NodeItem* source)
{
  this->_d->_source=source;

  this->setText(this->toString());

  return;
}

void ArcItem::setTarget(NodeItem* target)
{
  this->_d->_target=target;

  this->setText(this->toString());

  return;
}

QString ArcItem::toString() const
{
  QString arcString=QStringLiteral("");

  if(this->_d->_source)
    arcString+=this->_d->_source->toString();
  else
    arcString+=QObject::tr("###");

  arcString+=QStringLiteral("->");

  if(this->_d->_target)
    arcString+=this->_d->_target->toString();
  else
    arcString+=QObject::tr("###");

  return arcString;
}

}///end namespace graph
}///end namespace model
