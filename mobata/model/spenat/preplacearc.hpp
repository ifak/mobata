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
#ifndef MODEL_SPENAT_PREPLACEARC_HPP
#define MODEL_SPENAT_PREPLACEARC_HPP

#include "../../mobata_global.hpp"

#include "../graph/arcitem.hpp"

namespace model{
namespace spenat{

class PlaceItem;

class MOBATASHARED_EXPORT PrePlaceArc
    : public graph::ArcItem
{
public:
  PrePlaceArc(const QUuid &uuid);
  PrePlaceArc(PlaceItem *sourcePlace,
              graph::NodeItem *targetNode,
              const QUuid& uuid=QUuid::createUuid());
  virtual ~PrePlaceArc();

public:
  PlaceItem const*	place() const;
  void setPlace(PlaceItem *place);

  virtual QString toString() const;
};

}/// namespace spenat
}/// namespace model

#endif // MODEL_SPENAT_PREPLACEARC_HPP
