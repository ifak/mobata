/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "../msc/msc_types.hpp"

namespace model{

namespace base{
class DataTypeItem;
class SignalItem;
class ParamItem;
class ParamValueItem;
class AttributeItem;
class PortItem;
class LinkItem;
}

namespace irdl{

using model::base::DataTypeItem;
using model::base::SignalItem;
using model::base::ParamItem;
using model::base::ParamValueItem;
using model::base::AttributeItem;
using model::base::PortItem;
using model::base::LinkItem;

using msc::FragmentType;

using base::EnumComponentType;
enum TsComponentType
{
  ReqComponentType = msc::MscUserComponentType +1,
  ReqActorComponentType
};

typedef msc::MscMessageItem         MessageItem;
typedef msc::MscCheckMessageItem    CheckMessageItem;
typedef msc::MscFragmentItem        FragmentItem;
typedef msc::MscFragmentRegionItem  FragmentRegionItem;
typedef msc::MscStatementItem       StatementItem;
typedef msc::MscTimerItem           TimerItem;
typedef msc::MscComponentItem       BaseComponentItem;

class RequirementsModel;
class RequirementItem;
class ReqComponentItem;
class ReqActorComponentItem;

using model::msc::FragmentType;

}///end namespace requirement
}///end namespace model
