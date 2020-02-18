#include "decljunction.hpp"

#include "../base/textitem.hpp"

#include "types.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

struct JunctionOptions : public graph::NodeOptions
{
  JunctionOptions()
  {
    this->setSize(QSizeF(25,25));
    this->setColor(Qt::black);
  }
};

DeclJunction::DeclJunction() : graph::EllipseNode(QLatin1String(""),JunctionOptions())
{
  this->notationItem()->setFlag(QGraphicsItem::ItemIsMovable, false);
  this->notationItem()->setFlag(QGraphicsItem::ItemIsSelectable, false);
  this->notationItem()->setFlag(QGraphicsItem::ItemIsFocusable, false);
}

DeclJunction::~DeclJunction()
{}

int DeclJunction::type() const
{
  return Type;
}

}///end namespace spenat
}///end namespace view
