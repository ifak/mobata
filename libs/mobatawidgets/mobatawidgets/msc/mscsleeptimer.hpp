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
#ifndef VIEW_MSC_MSCSLEEPTIMER_HPP
#define VIEW_MSC_MSCSLEEPTIMER_HPP

#include "../mobatawidgets_global.hpp"
#include "types.hpp"

#include "mscmessage.hpp"

namespace view{
namespace msc{

class MOBATAWIDGETSSHARED_EXPORT KMscSleepTimer
    : public KMscMessage
{
public:
  KMscSleepTimer(KMscAnchor* from,
                 KMscAnchor* to,
                 const double duration,
                 KMscSequence* parent=0);

  KMscSleepTimer(KMscAnchor* from,
                 KMscAnchor* to,
                 const double duration,
                 const view::graph::ArcOptions& arcOptions,
                 KMscSequence* parent=0);

  virtual ~KMscSleepTimer();

public:
  virtual qreal updateGeometry(const qreal bottomSceneY,
                               const qreal marginSpace);
};

}//////end namespace msc
}// end namespace view

#endif // VIEW_MSC_MSCSLEEPTIMER_HPP
