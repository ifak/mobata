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
#ifndef VIEW_MSC_KMSCTIMEOUT_HPP
#define VIEW_MSC_KMSCTIMEOUT_HPP

#include "../mobatawidgets_global.hpp"
#include "types.hpp"

#include "mscmessage.hpp"

namespace view {
namespace msc {

class MOBATAWIDGETSSHARED_EXPORT KMscTimeout
    : public KMscMessage,
    public prop::NameProperty
{
public:
  KMscTimeout(KMscAnchor* from,
              KMscAnchor* to,
              const QString& timerName,
              KMscSequence* parent=0);

  KMscTimeout(KMscAnchor* from,
              KMscAnchor* to,
              const QString& timerName,
              const view::graph::ArcOptions& arcOptions,
              KMscSequence* parent=0);

  virtual ~KMscTimeout();

public:
  virtual qreal updateGeometry(const qreal bottomSceneY,
                               const qreal marginSpace);

private:
  Q_DISABLE_COPY(KMscTimeout)
  class Private;
  Private* _d;
};

} // namespace msc
} // namespace view

#endif // VIEW_MSC_KMSCTIMEOUT_HPP
