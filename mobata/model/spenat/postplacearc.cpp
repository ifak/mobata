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

#include "postplacearc.hpp"

#include "placeitem.hpp"

#include "../../utils/functors.hpp"

namespace model{
namespace spenat{

PostPlaceArc::PostPlaceArc(const QUuid &uuid)
  :	graph::ArcItem(nullptr,nullptr,uuid)
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
