#include "simruntimeport.hpp"

#include "simruntime.hpp"

namespace modsim {

class SimRuntimePort::Private
{
  friend class SimRuntimePort;

  SimRuntime const* _simRuntime;

  Private(SimRuntime const* simRuntime)
    : _simRuntime(simRuntime)
  {}
};

SimRuntimePort::SimRuntimePort(const SimRuntime* simRuntime,
                               const QString& name,
                               const quint32 id,
                               QObject* parent)
  : QObject(parent), prop::NameProperty(name), prop::IdProperty(id), _d(new Private(simRuntime))
{
  Q_ASSERT(this->_d->_simRuntime);
}

SimRuntimePort::~SimRuntimePort()
{
  delete this->_d;
}

SimRuntime const* SimRuntimePort::simRuntime() const
{
  return this->_d->_simRuntime;
}

} // namespace modsim
