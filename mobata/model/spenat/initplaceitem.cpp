#include "initplaceitem.hpp"

#include "placeitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace spenat{

InitPlaceItem::InitPlaceItem(PlaceItem const* placeItem)
  :	_placeItem(placeItem)
{
  if(this->_placeItem)
    this->setText(this->_placeItem->toString());
}

InitPlaceItem::InitPlaceItem(const QUuid &uuid,
                             const PlaceItem *placeItem)
  : ModelItem(uuid), _placeItem(placeItem)
{
}

InitPlaceItem::~InitPlaceItem()
{}

PlaceItem const*	InitPlaceItem::getPlaceItem() const
{
  return this->_placeItem;
}

void InitPlaceItem::setPlaceItem(PlaceItem const* placeItem)
{
  this->_placeItem=placeItem;
}

}///end namespace model
}///end namespace spenat
