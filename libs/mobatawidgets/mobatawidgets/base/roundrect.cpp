#include "roundrect.hpp"

#include <QPainter>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace base {

RoundRect::RoundRect(QGraphicsItem* parent)
  : QAbstractGraphicsShapeItem(parent),
    _radius(10),
    _rect(-25, -25, 25, 25)
{}

RoundRect::RoundRect(qreal radius,
                     QGraphicsItem* parent)
  : QAbstractGraphicsShapeItem(parent),
    _radius(radius),
    _rect(-25, -25, 25, 25)
{}

RoundRect::RoundRect(const QRectF& rect,
                     QGraphicsItem* parent)
  : QAbstractGraphicsShapeItem(parent),
    _radius(10),
    _rect(rect)
{}

RoundRect::RoundRect(const QRectF& rect,
                     qreal radius,
                     QGraphicsItem* parent)
  : QAbstractGraphicsShapeItem(parent),
    _radius(radius),
    _rect(rect)
{}

RoundRect::~RoundRect()
{}

void RoundRect::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
  Q_ASSERT(painter);
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->setBrush(this->brush());
  painter->setPen(this->pen());
  painter->drawRoundedRect(this->rect(),
                           this->_radius,
                           this->_radius);

  return;
}

QRectF	RoundRect::boundingRect() const
{
  return this->rect();
}

QRectF RoundRect::rect() const
{
  return this->_rect;
}

void RoundRect::setRect(const QRectF &rect)
{
  this->_rect=rect;

  return;
}

qreal RoundRect::radius() const
{
  return this->_radius;
}

void RoundRect::setRadius(qreal radius)
{
  this->_radius=radius;

  return;
}

} // namespace base
} // namespace view

