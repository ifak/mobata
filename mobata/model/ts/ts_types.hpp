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
#ifndef MODEL_TS_TYPES_HPP
#define MODEL_TS_TYPES_HPP

#include "ts_constants.hpp"

#include "../msc/msc_types.hpp"

namespace model{

namespace base{
class DataTypeItem;
class SignalItem;
class AttributeItem;
class PortItem;
class LinkItem;
}

namespace ts{

using model::base::DataTypeItem;
using model::base::SignalItem;
using model::base::AttributeItem;
using model::base::PortItem;
using model::base::LinkItem;

using msc::FragmentType;

using base::EnumComponentType;
enum TsComponentType
{
  SutComponentType = msc::MscUserComponentType +1,
  TestComponentType,
  TsUserComponentType
};

typedef msc::MscMessageItem         MessageItem;
typedef msc::MscCheckMessageItem    CheckMessageItem;
typedef msc::MscFragmentItem        FragmentItem;
typedef msc::MscFragmentRegionItem  FragmentRegionItem;
typedef msc::MscStatementItem       StatementItem;
typedef msc::MscTimerItem           TimerItem;
typedef msc::MscComponentItem       BaseComponentItem;

class TestCaseItem;
class SutItem;
class SutComponentItem;
class TestSystemItem;
class TestComponentItem;
class TestGroupItem;
class TestSuite;
class TestResultItem;

using model::msc::MscStepType;

enum TsStepType
{
  TestResultStep = msc::UserStep + 1,
  TsUserStep
};

enum TestResultValue
{
  Fail,
  Pass,
  Inconc,
  Unknown
};

inline
QString testResult2String(const TestResultValue testResultValue)
{
  if(testResultValue==Fail)
    return QStringLiteral("Fail");
  else if(testResultValue==Pass)
    return QStringLiteral("Pass");
  else if(testResultValue==Inconc)
    return QStringLiteral("Inconc");

  return QStringLiteral("Unknown");
}

class ComCreateTestCasePix;

}///end namespace ts
}///end namespace model

#endif // MODEL_TS_TYPES_HPP
