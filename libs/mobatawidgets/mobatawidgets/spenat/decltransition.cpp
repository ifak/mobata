#include "decltransition.hpp"

#include "../base/textitem.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

DeclTransition::DeclTransition(const QString& notation, 
                               const TransitionOptions& transitionOptions)
  : graph::RectNode(notation, transitionOptions)
{
  this->notationItem()->setFlags(QGraphicsItem::ItemIsMovable
                                 | QGraphicsItem::ItemIsSelectable
                                 | QGraphicsItem::ItemIsFocusable);
}

DeclTransition::DeclTransition(const TransitionOptions& transitionOptions)
  : graph::RectNode(QLatin1String("ev[guard]/send ev() to env;"), transitionOptions)
{
  this->notationItem()->setFlags(QGraphicsItem::ItemIsMovable
                                 | QGraphicsItem::ItemIsSelectable
                                 | QGraphicsItem::ItemIsFocusable);
}

DeclTransition::DeclTransition(const QString& notation)
  : graph::RectNode(notation, TransitionOptions())
{
  this->notationItem()->setFlags(QGraphicsItem::ItemIsMovable
                                 | QGraphicsItem::ItemIsSelectable
                                 | QGraphicsItem::ItemIsFocusable);
}

DeclTransition::~DeclTransition()
{}

int DeclTransition::type() const
{
  return Type;
}

}///end namespace spenat
}///end namespace view
