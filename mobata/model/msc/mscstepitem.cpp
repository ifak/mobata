#include "mscstepitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace msc{

class MscStepItem::Private
{
  friend class MscStepItem;

  MscComponentItem const*  _component;

  Private(MscComponentItem const* component)
    : _component(component)
  {}
};

MscStepItem::MscStepItem(const MscComponentItem* component)
  : _d(new Private(component))
{
  Q_ASSERT(this->_d->_component);
}

MscStepItem::~MscStepItem()
{
  delete this->_d;
}

MscComponentItem const* MscStepItem::component() const
{
  return this->_d->_component;
}

}/// end namespace msc
}/// end namespace model
