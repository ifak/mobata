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
#ifndef MODEL_TS_TESTRESULTITEM_HPP
#define MODEL_TS_TESTRESULTITEM_HPP

#include "../../mobata_global.hpp"

#include "../msc/mscstepitem.hpp"

#include "ts_types.hpp"

namespace model {
namespace ts {

class MOBATASHARED_EXPORT TestResultItem
    : public msc::MscStepItem
{
public:
  TestResultItem(TestComponentItem const* component,
                 const TestResultValue value);
  virtual ~TestResultItem();

public:
  virtual int     stepType() const        { return TestResultStep;}
  virtual QString stepTypeString() const  { return QLatin1String(constants::TestResultStepId);}

public:
  TestResultValue value() const;
  void setValue(const TestResultValue value);

private:
  Q_DISABLE_COPY(TestResultItem)
  class Private;
  Private* _d;
};

} // namespace ts
} // namespace model

#endif // MODEL_TS_TESTRESULTITEM_HPP
