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
#ifndef VIEW_GRAPH_RECTNODE_HPP
#define VIEW_GRAPH_RECTNODE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"
#include "abstractnode.hpp"

namespace view{
namespace graph{

class MOBATAWIDGETSSHARED_EXPORT RectNode
    : public AbstractNode
{
public:
  enum { Type = RectType};

public:
  RectNode(const QString& notation=QString(),
           const NodeOptions& nodeOptions=NodeOptions(),
           const QUuid& uuid=QUuid::createUuid(),
           QGraphicsItem * parent = 0);
  RectNode(QGraphicsItem * parent);
  virtual ~RectNode();

public:
  virtual int type() const;

public:
  QSizeF  size() const;
  void    setSize(QSizeF size);
  QRectF  boundingRect() const;
  QRectF  rect() const;
  void    paint(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget = 0);

private:
  class Private;
  Private* _d;
};

}////end namespace graph
}//end namespace view

#endif // VIEW_GRAPH_RECTNODE_HPP
