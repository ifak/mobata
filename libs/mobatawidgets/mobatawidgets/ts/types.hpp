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
#ifndef VIEW_TS_TYPES_HPP
#define VIEW_TS_TYPES_HPP

#include <mobata/model/ts/ts_types.hpp>

#include "../comp/comp.hpp"
#include "../msc/types.hpp"

namespace view{

namespace msc {
class MscPixWidget;
}

namespace ts{

using model::ts::TestResultValue;

typedef msc::MscPixWidget  TsTestCasePixWidget;

using graph::NodeOptions;
using graph::ArcOptions;

using comp::Port;
using comp::Link;
using comp::Component;

class SutComponent;
class TestComponent;

enum TsGraphicType
{
  TsSutComponentType=msc::MscUserType+1,
  TsTestComponentType,
  TsUserType
};

}///end namespace ts
}///end namespace view

#endif // VIEW_TS_TYPES_HPP
