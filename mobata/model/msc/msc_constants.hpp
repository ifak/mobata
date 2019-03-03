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

namespace model{
namespace msc {
namespace constants{

///constant sequence-step ids

const char* const EmptyMessageStepId  = "EmptyMessageStep";
const char* const MessageStepId       = "MessageStep";
const char* const CheckMessageStepId  = "CheckMessageStep";
const char* const StatementStepId     = "StatementStep";
const char* const TimeoutStepId       = "TimeoutStep";
const char* const TimerStepId         = "TimerStep";
const char* const SleepTimerStepId    = "SleepTimerStep";
const char* const FragmentStepId      = "FragmentStep";

}///end namespace constants
}///end namespace msc
}///end namespace model
