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
#ifndef VIEW_MSC_MSCCOMPONENTLIFELINE_HPP
#define VIEW_MSC_MSCCOMPONENTLIFELINE_HPP

#include "../mobatawidgets_global.hpp"

#include <QGraphicsPathItem>

namespace view{
namespace msc{

class KMscAnchor;
class KMscComponent;

class MOBATAWIDGETSSHARED_EXPORT KMscComponentLifeline : public QGraphicsPathItem
{
public:
  KMscComponentLifeline(KMscComponent* mscComponent);
  KMscComponentLifeline(KMscComponent* mscComponent, const QPen &lifeLinePen);
  virtual ~KMscComponentLifeline();

public:
  QPointF         nextValidScenePos(const qreal startY) const;
  KMscAnchor*     addAnchor();
  void            updateAnchors();
  KMscComponent*  mscComponent() const;

public:
  virtual void  updateLifeline(const qreal startY, const qreal height);

protected:
  void setNextValidAchorPos(const QPointF& newAnchorPos);

private:
  Q_DISABLE_COPY(KMscComponentLifeline)
  class Private;
  Private* _d;
};

}//////end namespace msc
}/// end namespace view

#endif /// VIEW_MSC_MSCCOMPONENTLIFELINE_HPP
