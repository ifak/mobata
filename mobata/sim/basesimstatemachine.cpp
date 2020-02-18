#include "basesimstatemachine.hpp"

#include "basesimstate.hpp"

#include <QVector>

#include "../utils/functors.hpp"

#include "../memory_leak_start.hpp"

using namespace sim;

class BaseSimStateMachine::Private
{
  friend class BaseSimStateMachine;

  QVector<BaseSimState*>  _simStates;

  Private()
  {}
};

BaseSimStateMachine::BaseSimStateMachine(const QString& name,
                                         QObject* parent)
  : QStateMachine(parent),
    prop::NameProperty(name),
    _d(new Private)
{}

BaseSimStateMachine::~BaseSimStateMachine()
{
  delete this->_d;
}

bool BaseSimStateMachine::addSimState(BaseSimState* baseSimState,
                                      QString* errorString)
{
  Q_ASSERT(baseSimState);

  if(this->simState(baseSimState->name()))
  {
    utils::AddPtrString(errorString)<<tr("there is already a simulation state "
                                         "with name '%1' within simulation "
                                         "state machine '%2' available!")
                                      .arg(baseSimState->name())
                                      .arg(this->name());
    return false;
  }

  this->_d->_simStates.push_back(baseSimState);

  return true;
}

BaseSimState const* BaseSimStateMachine::simState(const QString& stateName) const
{
  for(BaseSimState const* currentState:this->_d->_simStates)
  {
    if(currentState->name()==stateName)
      return currentState;
  }

  return 0;
}

QList<BaseSimState*> BaseSimStateMachine::currentStates(bool onlyLeafStates)
{
  QList<BaseSimState*> currentStatesList;
  if(!this->isRunning())
    return currentStatesList;

  for(QAbstractState* actState
      : this->configuration())
  {
    BaseSimState* actSimState = qobject_cast<BaseSimState*>(actState);
    if(!actSimState)
      continue;

    if(actSimState->children().size()//not a leaf state
       && onlyLeafStates)
      continue;

    currentStatesList.append(actSimState);
  }

  return currentStatesList;
}
