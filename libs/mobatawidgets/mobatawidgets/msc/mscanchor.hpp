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
#ifndef VIEW_MSC_MSCANCHOR_HPP
#define VIEW_MSC_MSCANCHOR_HPP

#include "../mobatawidgets_global.hpp"

#include "../graph/rectnode.hpp"
#include "../base/textitem.hpp"

namespace view{
namespace msc{

class KMscComponent;
class KMscComponentLifeline;

class MOBATAWIDGETSSHARED_EXPORT KMscAnchor
    : public graph::RectNode
{
public:
  KMscAnchor(KMscComponentLifeline* lifelineParent);
  virtual ~KMscAnchor();

public:
  KMscComponent* mscComponent() const;

protected:
  virtual bool sceneEventFilter(QGraphicsItem* watched,
                                QEvent* event);
  virtual QVariant  itemChange(GraphicsItemChange change,
                               const QVariant &value);
};

}////end namespace msc
}/// end namespace view

#endif ///VIEW_MSC_MSCANCHOR_HPP
