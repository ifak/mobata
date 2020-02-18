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
#ifndef VIEW_BASE_ROUNDRECT_HPP
#define VIEW_BASE_ROUNDRECT_HPP

#include "../mobatawidgets_global.hpp"

#include <QAbstractGraphicsShapeItem>

namespace view {
namespace base {

class MOBATAWIDGETSSHARED_EXPORT RoundRect
    : public QAbstractGraphicsShapeItem
{
public:
  RoundRect(QGraphicsItem* parent = 0);
  RoundRect(qreal radius,
            QGraphicsItem* parent = 0);
  RoundRect(const QRectF& rect,
            QGraphicsItem* parent = 0);
  RoundRect(const QRectF& rect,
            qreal radius,
            QGraphicsItem* parent = 0);
  virtual ~RoundRect();

public:
  virtual void paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget = 0);
  virtual QRectF boundingRect() const;

public:
  QRectF  rect() const;
  void    setRect(const QRectF& rect);
  qreal   radius() const;
  void    setRadius(qreal radius);

protected:
  qreal   _radius;
  QRectF  _rect;
};

} // namespace base
} // namespace view

#endif // VIEW_BASE_ROUNDRECT_HPP
