#include "mscfragmentregionitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace msc{

class MscFragmentRegionItem::Private
{
  friend class MscFragmentRegionItem;
  explicit Private(const QString& condition)
    :_condition(condition)
  {}

  QString _condition;
};

MscFragmentRegionItem::MscFragmentRegionItem(const QString &condition)
  :	MscSequence(condition), _d(new Private(condition))
{
  this->setText(this->_d->_condition);
}

MscFragmentRegionItem::~MscFragmentRegionItem()
{
  delete this->_d;
}

const QString &MscFragmentRegionItem::condition() const
{
  return this->_d->_condition;
}

void MscFragmentRegionItem::setCondition(const QString &condition)
{
  this->_d->_condition=condition;
  this->setText(this->_d->_condition);

  return;
}

}/// end namespace msc
}/// end namespace model
