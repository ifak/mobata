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

#include "atriggeritem.hpp"

namespace model {

namespace base{
class SignalItem;
class PortItem;

class MOBATASHARED_EXPORT SignalTriggerItem
    : public ATriggerItem
{
public:
  SignalTriggerItem(base::SignalItem const* triggerSignal);
  SignalTriggerItem(base::SignalItem const* triggerSignal,
                    base::PortItem const* port);

  virtual ~SignalTriggerItem();

public:
  virtual TriggerType triggerType() const {return EventTrigger;}
  virtual QString     declaration() const;

public:
  void                    setTriggerSignal(base::SignalItem const* triggerSignal);
  base::SignalItem const* triggerSignal() const;

  void                  setPort(base::PortItem const* port);
  base::PortItem const* port() const;

private:
  Q_DISABLE_COPY(SignalTriggerItem)
  class Private;
  Private* _d;
};

} // namespace base
} // namespace model
