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
#ifndef VIEW_MSC_MSCMESSAGE_HPP
#define VIEW_MSC_MSCMESSAGE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../graph/directededge.hpp"
#include "mscsequencestep.hpp"

namespace view{
namespace msc{

///forward declaration
class KMscSequence;
class KMscAnchor;

class MOBATAWIDGETSSHARED_EXPORT KMscMessage
    : public graph::DirectedEdge,
    public MscSequenceStep
{
public:
  KMscMessage(KMscAnchor* from,
              KMscAnchor* to,
              const QString& messageText,
              KMscSequence* parent=0);

  KMscMessage(KMscAnchor* from,
              KMscAnchor* to,
              const QString& messageText,
              const view::graph::ArcOptions& arcOptions,
              KMscSequence* parent=0);

  virtual ~KMscMessage();

public:
  virtual qreal updateGeometry(const qreal bottomSceneY,
                               const qreal marginSpace) override;

public:
  QRectF messageTextRect() const;

public:
  virtual void updatePath(const QPainterPath& path) override;
  virtual void updateEndPositions();

protected:
  virtual void updateNotationPosition();
  virtual bool sceneEventFilter(QGraphicsItem* watched, QEvent* event) override;

private:
  Q_DISABLE_COPY(KMscMessage)
  class Private;
  Private* _d;
};

}//////end namespace msc
}/// end namespace view

#endif
