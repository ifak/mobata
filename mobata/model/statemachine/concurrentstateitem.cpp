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

#include "concurrentstateitem.hpp"
#include "regionitem.hpp"

#include <QString>

namespace model {
namespace statemachine {

ConcurrentStateItem::ConcurrentStateItem(const QString& name,
                                         const QUuid& id)
  : AbstractStateItem(name, id),
    PropRegions(this)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/statemachine/concurrentstate.png")));
}

ConcurrentStateItem::~ConcurrentStateItem()
{}

StateType ConcurrentStateItem::stateType() const
{
  return Concurrent;
}

bool ConcurrentStateItem::initRegions(int numRegions,
                                      QString* errorString)
{
  if(this->regions().count())
    return false;

  while(this->regions().count() < 2 || this->regions().count() < numRegions){
    RegionItem* region = new RegionItem(QString("region") + QString::number(this->regions().count()));
    this->addRegion(region, errorString);

    Q_ASSERT(region);
  }

  return true;
}

} // namespace statemachine
} // namespace model
