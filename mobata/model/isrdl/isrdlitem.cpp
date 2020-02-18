#include "isrdlitem.hpp"

#include "../../memory_leak_start.hpp"
#include "isrdlattackdescription.h"
#include "isrdlattackimpact.h"

namespace model{
namespace isrdl{

class IsrdlItem::Private
{
  friend class IsrdlItem;

  IsrdlAttackDescription* _attackDescription;
  IsrdlAttackImpact*      _attackImpact;
  Private():
    _attackDescription(new IsrdlAttackDescription),
    _attackImpact(new IsrdlAttackImpact)
  {}

  ~Private()
  {}
};

IsrdlItem::IsrdlItem(const QString& name)
  : PropAttributes(this),
    _d(new Private())
{
  setName(name);
  this->setText(this->toString());
  this->appendRow(_d->_attackDescription);
  this->appendRow(_d->_attackImpact);
}

IsrdlItem::~IsrdlItem()
{
  removeRows(0,rowCount());
  delete this->_d;
}

void IsrdlItem::reset()
{
  this->resetAttributes();
  _d->_attackDescription->update();
  _d->_attackImpact->update();
  return;
}

IsrdlAttackDescription *IsrdlItem::attackDescription()
{
  return _d->_attackDescription;
}

IsrdlAttackImpact *IsrdlItem::attackImpact()
{
  return _d->_attackImpact;
}
}/// end namespace isrdl
}/// end namespace model
