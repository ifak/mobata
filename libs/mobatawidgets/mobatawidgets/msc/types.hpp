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
#ifndef VIEW_MSC_TYPES_HPP
#define VIEW_MSC_TYPES_HPP

#include <mobata/model/msc/msc_types.hpp>

#include "../spenat/types.hpp"

namespace view{
namespace msc{

using model::msc::FragmentType;
using model::msc::SequenceFragment;
using model::msc::AlternativeFragment;
using model::msc::OptionalFragment;
using model::msc::ParallelFragment;
using model::msc::LoopFragment;
using model::msc::IgnoreFragment;
using model::msc::ConsiderFragment;
using model::msc::AssertFragment;

class MscSequenceStep;
typedef QVector<MscSequenceStep*> SequenceSteps;

class KMscComponent;
class KMscFragment;
class KMscMessage;
class KMscSequence;
class KMscStatement;
class KMscTimeout;
class KMscTimer;
class KMscSleepTimer;
class KMscAnchor;

enum MessageType
{
  Message,
  Check,
  SleepTimer,
  Timer,
  Timeout
};

enum MscGraphicType
{
  MscComponentType=spenat::SpenatUserType+1,
  MscLifelineType,
  MscAnchorType,
  MscMessageType,
  MscFragmentType,
  MscUserType
};

}
}

#endif // VIEW_MSC_TYPES_HPP

