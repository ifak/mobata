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

#include "../mobata_global.hpp"

#include <QState>

namespace sim{

class BaseSimStateMachine;

class MOBATASHARED_EXPORT BaseSimState
    : public QState
{
  Q_OBJECT

  Q_PROPERTY(const QString& name READ name CONSTANT)

public:
  BaseSimState(const QString& name,
               BaseSimStateMachine* baseSimStateMachine,
               QState* parent = nullptr);
  virtual ~BaseSimState();

public:
  const QString& name() const;

protected:
  virtual void onEntry(QEvent* entryEvent);
  virtual void onExit(QEvent* exitEvent);

private:
  QString               _name;
  BaseSimStateMachine*  _baseSimStateMachine;
};

}// namespace sim
