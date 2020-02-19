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

#include "../../utils/functors.hpp"

namespace model{

namespace base{

class ModelItem;
class DataTypeItem;
class SignalItem;
class PortItem;
class AttributeItem;
class ParamItem;
class FunctionItem;
class ATriggerItem;
class SignalTriggerItem;
class TimeoutTriggerItem;
}

namespace statemachine {

using namespace base;

class StateMachineModel;
class AbstractStateItem;
class SimpleStateItem;
class ConcurrentStateItem;
class CompositeStateItem;
class FinalStateItem;
class JunctionStateItem;
class ChoiceStateItem;

enum StateType
{
  Simple,
  Concurrent,
  Composite,
  Final,
  Junction,
  Choice
};

class TransitionItem;
class RegionItem;

}/// namespace statemachine
}/// namespace model

