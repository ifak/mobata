#include "basesimstate.hpp"

#include "basesimstatemachine.hpp"

#include "../memory_leak_start.hpp"

using namespace sim;

BaseSimState::BaseSimState(const QString& name,
                           BaseSimStateMachine* baseSimStateMachine,
                           QState* parent)
  : QState(parent),
    _name(name),
    _baseSimStateMachine(baseSimStateMachine)
{
  Q_ASSERT(this->_baseSimStateMachine);
}

BaseSimState::~BaseSimState()
{}

const QString& BaseSimState::name() const
{
  return this->_name;
}

void BaseSimState::onEntry(QEvent* entryEvent)
{
  Q_UNUSED(entryEvent);

  emit this->_baseSimStateMachine->stateEntered(this);
  emit this->_baseSimStateMachine->configurationChanged();

  return;
}

void BaseSimState::onExit(QEvent* exitEvent)
{
  Q_UNUSED(exitEvent);

  emit this->_baseSimStateMachine->stateExited(this);
  emit this->_baseSimStateMachine->configurationChanged();

  return;
}
