#include "postplacearc.hpp"

#include "placeitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace spenat{

PostPlaceArc::PostPlaceArc(const QUuid &uuid)
  :	graph::ArcItem(0,0,uuid)
{}

PostPlaceArc::PostPlaceArc(graph::NodeItem *sourceNode,
                           PlaceItem *targetPlace,
                           const QUuid &uuid)
  : graph::ArcItem(sourceNode, targetPlace, uuid)
{
  this->setText(this->toString());
}

PostPlaceArc::~PostPlaceArc()
{}

PlaceItem const* PostPlaceArc::place() const
{
  return utils::simple_cast<PlaceItem const*>(this->target());
}

void PostPlaceArc::setPlace(PlaceItem* place)
{
  this->setTarget(place);
  this->setText(this->toString());

  return;
}

QString PostPlaceArc::toString() const
{
  if(this->target())
    return this->target()->toString();

  return QStringLiteral("");
}

} // namespace model
} // namespace spenat
