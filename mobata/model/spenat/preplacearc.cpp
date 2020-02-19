#include "preplacearc.hpp"

#include "placeitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace spenat{

PrePlaceArc::PrePlaceArc(const QUuid &uuid)
  :	graph::ArcItem(0,0,uuid)
{}

PrePlaceArc::PrePlaceArc(PlaceItem *sourcePlace,
                         graph::NodeItem* targetNode,
                         const QUuid &uuid)
  : graph::ArcItem(sourcePlace, targetNode, uuid)
{
  this->setText(this->toString());
}

PrePlaceArc::~PrePlaceArc()
{}

PlaceItem const* PrePlaceArc::place() const
{
  return utils::simple_cast<PlaceItem const*>(this->source());
}

void PrePlaceArc::setPlace(PlaceItem* place)
{
  this->setSource(place);
  this->setText(this->toString());

  return;
}

QString PrePlaceArc::toString() const
{
  if(this->place())
    return this->place()->toString();

  return QStringLiteral("");
}

} // namespace model
} // namespace spenat
