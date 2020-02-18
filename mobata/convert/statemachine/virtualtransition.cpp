#include "virtualtransition.hpp"

#include "mobata/model/spenat/placeitem.hpp"

namespace convert{
namespace statemachine{

VirtualTransition::VirtualTransition(const model::statemachine::AbstractStateItem* stateItem,
                                     const QString& guard,
                                     const QString& action,
                                     bool isFusedTransition)
  : _state(stateItem),
    _isFusedTransition(isFusedTransition),
    _guard(guard),
    _action(action)
{
}

const model::statemachine::AbstractStateItem* VirtualTransition::state()
{
  return this->_state;
}

void VirtualTransition::setState(const model::statemachine::AbstractStateItem* state)
{
  Q_ASSERT(state);

  this->_state = state;
}

QString  VirtualTransition::guard()
{
  return this->_guard;
}

void VirtualTransition::setGuard(const QString& guard)
{
  this->_guard = guard;
}

QString VirtualTransition::action()
{
  return this->_action;
}

void VirtualTransition::setAction(const QString& action)
{
  this->_action = action;
}

bool VirtualTransition::fusedTransition()
{
  return this->_isFusedTransition;
}

void VirtualTransition::setFusedTransition(bool fusedState)
{
  this->_isFusedTransition = fusedState;
}

void VirtualTransition::setTransitionChain(const QStringList transitionChain)
{
  this->_transitionChain = transitionChain;
}

const QStringList VirtualTransition::transitionChain()
{
  return this->_transitionChain;
}

}//statemachine
}//convert
