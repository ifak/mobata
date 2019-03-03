/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "initplaceitem.hpp"

#include "placeitem.hpp"

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
