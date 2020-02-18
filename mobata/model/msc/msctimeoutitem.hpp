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
#ifndef MODEL_MSC_MSCTIMEOUTITEM_HPP
#define MODEL_MSC_MSCTIMEOUTITEM_HPP

#include "../../mobata_global.hpp"

#include "msc_types.hpp"

#include "mscstepitem.hpp"

namespace model {
namespace msc {

class MscTimerItem;

class MOBATASHARED_EXPORT MscTimeoutItem
    : public MscStepItem
{
public:
  MscTimeoutItem(MscComponentItem const* component,
                 MscTimerItem const* timer=0);
  virtual ~MscTimeoutItem();

public:
  virtual int     stepType() const { return TimeoutStep;}
  virtual QString stepTypeString() const { return constants::TimeoutStepId;}

public:
  MscTimerItem const* timer() const;
  void                setTimer(MscTimerItem const* timer);

  QString             toString() const;

private:
  Q_DISABLE_COPY(MscTimeoutItem)
  class Private;
  Private* _d;
};

} // namespace msc
} // namespace model

#endif // MODEL_MSC_MSCTIMEOUTITEM_HPP
