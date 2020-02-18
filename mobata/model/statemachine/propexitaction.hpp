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

class PropExitAction
{
public:
  PropExitAction(const QString& exitAction=QStringLiteral(""))
    : _exitAction(exitAction)
  {}

  virtual ~PropExitAction()
  {}

public:
  const QString&  exitAction() const
  {
    return this->_exitAction;
  }

  void setExitAction(const QString& exitAction)
  {
    this->_exitAction=exitAction;

    return;
  }

protected:
  QString _exitAction;
};

} // namespace statemachine
} // namespace model

