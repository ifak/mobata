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
#pragma once

#include <QString>

namespace model {
namespace statemachine {

class PropEntryAction
{
public:
  PropEntryAction(const QString& entryAction=QStringLiteral(""))
    : _entryAction(entryAction)
  {}

  virtual ~PropEntryAction()
  {}

public:
  const QString&  entryAction() const
  {
    return this->_entryAction;
  }

  void setEntryAction(const QString& entryAction)
  {
    this->_entryAction=entryAction;

    return;
  }

protected:
  QString _entryAction;
};

} // namespace statemachine
} // namespace model

