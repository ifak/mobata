#include "propstates.hpp"

#include "abstractstateitem.hpp"
#include "simplestateitem.hpp"
#include "compositestateitem.hpp"
#include "concurrentstateitem.hpp"
#include "finalstateitem.hpp"
#include "functors.hpp"

#include <QString>
#include <QIcon>

#include "../../memory_leak_start.hpp"

namespace model {
namespace statemachine {

class PropStates::Private
{
  friend class PropStates;

  AbstractStateItem const*  _initState = nullptr;
  ConstFinalStateSet        _finalStates;

  Private()
    :_initState(nullptr)
  {}
};

PropStates::PropStates(QStandardItem* ownerItem)
  : BaseClass(ownerItem,
              QLatin1String("states"),
              QIcon(QLatin1String(":/mobata/images/statemachine/manystate.png"))),
    _d(new Private)

{}

PropStates::~PropStates()
{
  delete this->_d;
}

void PropStates::resetStates()
{
  this->_d->_initState=nullptr;
  this->_d->_finalStates.clear();
  return BaseClass::resetChildren();
}

bool PropStates::addState(AbstractStateItem* stateItem,
                          QString* errorString)
{
  Q_ASSERT(this->_ownerItem);
  Q_ASSERT(stateItem);

  if(this->state(stateItem->uuid()))
  {
    utils::AddPtrString(errorString) << QObject::tr("there is already a state with this id; "
                                                    "state '%1' is not added!").arg(stateItem->name());
    return false;
  }

  BaseClass::addChild(stateItem);

  if(stateItem->stateType()==Final)
  {
    FinalStateItem* finalState=utils::simple_cast<FinalStateItem*>(stateItem);
    Q_ASSERT(finalState);
    this->_d->_finalStates.append(finalState);
  }

  return true;
}

bool PropStates::setInitState(AbstractStateItem* stateItem, QString* errorMessage)
{
  Q_ASSERT(this->_ownerItem);
  Q_ASSERT(stateItem);

  if(!utils::IsAvailable<StateSet>(this->states())(stateItem))
  {
    utils::AddPtrString(errorMessage)<<"state item '"<<stateItem->name()<<"' is not available, cannot be set as init state!";
    return false;
  }

  switch(stateItem->stateType()){
  case Simple: {
    SimpleStateItem* item = static_cast<SimpleStateItem*>(stateItem);
    Q_ASSERT(item);
    item->setInit(true);
    break;
  }
  case Composite: {
    CompositeStateItem* item = static_cast<CompositeStateItem*>(stateItem);
    Q_ASSERT(item);
    item->setInit(true);
    break;
  }
  case Concurrent: {
    ConcurrentStateItem* item = static_cast<ConcurrentStateItem*>(stateItem);
    Q_ASSERT(item);
    item->setInit(true);
    break;
  }
  default:
    utils::AddPtrString(errorMessage) << QStringLiteral("Can't set init state because given item has no property 'init'");
    return false;
  }

  this->_d->_initState=stateItem;

  return true;
}

AbstractStateItem const* PropStates::initState() const
{
  return this->_d->_initState;
}

const PropStates::ConstFinalStateSet& PropStates::finalStates() const
{
  return this->_d->_finalStates;
}

AbstractStateItem*  PropStates::state(const QUuid& stateId)
{
  return statesRecursiveByUuid(this, stateId);
}

AbstractStateItem const*  PropStates::state(const QUuid& stateId) const
{
  return constStatesRecursiveByUuid(this, stateId);
}

AbstractStateItem* PropStates::state(const QString& stateName)
{
  return statesRecursiveByName(this, stateName);
}

AbstractStateItem const*  PropStates::state(const QString& stateName) const
{
  return constStatesRecursiveByName(this, stateName);
}

PropStates::StateSet PropStates::states()
{
  return BaseClass::children();
}

PropStates::ConstStateSet PropStates::states() const
{
  return BaseClass::children();
}

void PropStates::removeState(const QUuid& stateUuid)
{
  return BaseClass::removeChild(stateUuid);
}

void PropStates::removeState(AbstractStateItem* stateItem)
{
  return BaseClass::removeChild(stateItem);
}

} // namespace statemachine
} // namespace model

