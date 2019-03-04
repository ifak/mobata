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

#include "msc_constants.hpp"

#include "../base/base_types.hpp"

#include "../base/datatypeitem.hpp"
#include "../base/signalitem.hpp"
#include "../base/paramitem.hpp"
#include "../base/paramvalueitem.hpp"
#include "../base/portitem.hpp"

#include <QString>

namespace model{
namespace msc {

//using namespace base;

using base::DataTypeItem;
using base::SignalItem;
using base::ParamItem;
using base::ParamValueItem;
using base::PortItem;

class MscModel;
class MscSequence;
class MscSequenceItem;
class MscComponentItem;
class MscWebSequChartClient;
class MscFragmentRegionItem;
class MscStepItem;
class MscMessageItem;
class MscCheckMessageItem;
class MscTimeoutItem;
class MscTimerItem;
class MscSleepTimerItem;
class MscFragmentItem;
class MscLoopFragmentItem;
class MscStatementItem;
class MscDurationFragmentItem;

enum MscStepType
{
  UnknownStep,
  EmptyMessageStep,
  MessageStep,
  CheckMessageStep,
  StatementStep,
  TimeoutStep,
  TimerStep,
  SleepTimerStep,
  FragmentStep,
  UserStep
};

enum FragmentType
{
  SequenceFragment,
  AlternativeFragment,
  OptionalFragment,
  ParallelFragment,
  LoopFragment,
  DurationFragment,
  IgnoreFragment,
  ConsiderFragment,
  AssertFragment,
  UserFragmentType
};

static inline
QString fragmentType2string(int fragmentType)
{
  if(fragmentType==SequenceFragment)
    return QStringLiteral("sequ");
  else if(fragmentType==AlternativeFragment)
    return QStringLiteral("alt");
  else if(fragmentType==OptionalFragment)
    return QStringLiteral("opt");
  else if(fragmentType==ParallelFragment)
    return QStringLiteral("par");
  else if(fragmentType==LoopFragment)
    return QStringLiteral("loop");
  else if(fragmentType==DurationFragment)
    return QStringLiteral("dur");
  else if(fragmentType==IgnoreFragment)
    return QStringLiteral("ignore");
  else if(fragmentType==ConsiderFragment)
    return QStringLiteral("consider");
  else if(fragmentType==AssertFragment)
    return QStringLiteral("assert");

  return QStringLiteral("!unknown!");///should not be reachable
}

static inline
int string2fragmentType(const QString& fragmentTypeString)
{
  if(fragmentTypeString.compare(QStringLiteral("sequ"),
                                Qt::CaseInsensitive)==0)
    return SequenceFragment;
  else if(fragmentTypeString.compare(QStringLiteral("alt"),
                                     Qt::CaseInsensitive)==0)
    return AlternativeFragment;
  else if(fragmentTypeString.compare(QStringLiteral("par"),
                                     Qt::CaseInsensitive)==0)
    return ParallelFragment;
  else if(fragmentTypeString.compare(QStringLiteral("loop"),
                                     Qt::CaseInsensitive)==0)
    return LoopFragment;
  else if(fragmentTypeString.compare(QStringLiteral("dur"),
                                     Qt::CaseInsensitive)==0)
    return DurationFragment;
  return SequenceFragment;//default value...
}

using base::EnumComponentType;

enum MscComponentType
{
  EnvComponentType = base::UserComponentType +1,
  MscUserComponentType
};

}///end namespace msc
}///end namespace model
