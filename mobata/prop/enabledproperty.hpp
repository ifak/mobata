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
#ifndef PROP_ENABLEDPROPERTY_HPP
#define PROP_ENABLEDPROPERTY_HPP

#include "../mobata_global.hpp"

#include <QString>

namespace prop{

class MOBATASHARED_EXPORT EnabledProperty
{
public:
  EnabledProperty(const bool enabled = true)
    :	_enabled(enabled)
  {}
  virtual ~EnabledProperty()
  {}

public:
  bool enabled() const
  {
    return this->_enabled;
  }

  void setEnabled(const bool enabled)
  {
    this->_enabled=enabled;

    return;
  }

protected:
  bool _enabled;
};

}/// namespace prop

#endif // PROP_ENABLEDPROPERTY_HPP
