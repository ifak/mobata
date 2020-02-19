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
#ifndef PROP_REFERENCEIDPROPERTY_HPP
#define PROP_REFERENCEIDPROPERTY_HPP

#include "../mobata_global.hpp"

#include <QUuid>

namespace prop{

class MOBATASHARED_EXPORT ReferenceIdProperty
{
public:
  ReferenceIdProperty(const QUuid& uuid=QUuid::createUuid())
    :	_referenceId(uuid)
  {}
  virtual ~ReferenceIdProperty()
  {}

public:
  const QUuid& referenceId() const
  {
    return this->_referenceId;
  }

  void setReferenceId(const QUuid& referenceId)
  {
    this->_referenceId=referenceId;

    return;
  }

protected:
  QUuid _referenceId;
};

}/// namespace prop

#endif // PROP_REFERENCEIDPROPERTY_HPP

