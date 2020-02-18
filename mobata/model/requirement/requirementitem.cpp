#include "requirementitem.hpp"

#include "../msc/mscfragmentitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace irdl{

class RequirementItem::Private
{
  friend class RequirementItem;

  Private()
  {}

  ~Private()
  {}
};

RequirementItem::RequirementItem(const QString& name)
  : msc::MscSequence(name),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    _d(new Private())
{
    this->setText(this->toString());
}

RequirementItem::~RequirementItem()
{
  delete this->_d;
}

void RequirementItem::reset()
{
  this->resetAttributes();
  this->resetSignals();

  msc::MscSequence::reset();

  return;
}

msc::MscFragmentItem *RequirementItem::addDurationFragment(uint duration)
{
  msc::MscFragmentItem* newDurationFragment =  this->addFragment(msc::DurationFragment);
  Q_ASSERT(newDurationFragment);
  newDurationFragment->setDuration(duration);
  newDurationFragment->addRegion(QString("Duration = %1ms").arg(duration));
  newDurationFragment->setText("Duration");

  return newDurationFragment;
}

}/// end namespace requirement
}/// end namespace model
