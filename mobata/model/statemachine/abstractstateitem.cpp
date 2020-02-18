#include "abstractstateitem.hpp"
#include "propinit.hpp"

namespace model {
namespace statemachine {

class AbstractStateItem::Private
{
  friend class AbstractStateItem;

  Private()
  {}
};

AbstractStateItem::AbstractStateItem(const QString& name,
                                     const QUuid& id)
  : base::ModelItem(id),
    prop::NameProperty(name),
    _d(new Private())
{
  this->setText(name);
}

AbstractStateItem::~AbstractStateItem()
{
  delete this->_d;
}

bool AbstractStateItem::derivedIsInit()
{
  //checks if object of derived class is an init state
  switch(this->stateType())
  {
  case Final:
  case Junction:
  case Choice:
  case Simple:
  case Composite:
  case Concurrent:
  {
    const PropInit* propInit = dynamic_cast<const PropInit*>(this);
    return propInit->isInit();
  }
  }

  return false;
}

} // namespace statemachine
} // namespace model
