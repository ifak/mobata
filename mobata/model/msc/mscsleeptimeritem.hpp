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
#ifndef MODEL_MSC_MSCSLEEPTIMERITEM_HPP
#define MODEL_MSC_MSCSLEEPTIMERITEM_HPP

#include "msc_types.hpp"

#include "mscstepitem.hpp"

namespace model{
namespace msc{

class MOBATASHARED_EXPORT MscSleepTimerItem
    : public MscStepItem
{
public:
  MscSleepTimerItem(MscComponentItem const* component,
                    double value=0);
  virtual ~MscSleepTimerItem();

public:
  virtual int     stepType() const        { return SleepTimerStep;}
  virtual QString stepTypeString() const  { return QLatin1String(constants::SleepTimerStepId);}

public:
  void    setValue(double value);
  double  value() const;
  QString toString() const;

private:
  Q_DISABLE_COPY(MscSleepTimerItem)
  class Private;
  Private* _d;
};

}/// end namespace msc
}/// end namespace model

#endif // MODEL_MSC_MSCSLEEPTIMERITEM_HPP
