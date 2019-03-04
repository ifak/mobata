/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

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
