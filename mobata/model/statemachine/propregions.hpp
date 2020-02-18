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
#pragma once

#include "types.hpp"

#include "../base/childrenproperty.hpp"

namespace model {
namespace statemachine {

class PropRegions : protected base::ChildrenProperty<RegionItem>
{
  typedef base::ChildrenProperty<RegionItem> BaseClass;

public:
  typedef BaseClass::ChildSet             RegionSet;
  typedef BaseClass::ConstChildSet        ConstRegionSet;

public:
  PropRegions(QStandardItem* ownerItem);
  virtual ~PropRegions();

public:
  bool                      addRegion(RegionItem* regionItem,
                                     QString* errorString);

public:
  RegionItem const*  region(const QUuid& regionId) const;
  RegionSet                  regions();
  ConstRegionSet             regions() const;

public:
  void removeRegion(const QUuid& regionId);
  void removeRegion(RegionItem* regionId);

protected:
  void  resetRegions();

private:
  Q_DISABLE_COPY(PropRegions)
  class Private;
  Private*  _d;
};

} // namespace statemachine
} // namespace model

