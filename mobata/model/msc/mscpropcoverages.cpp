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

#include "mscpropcoverages.hpp"

namespace model {
namespace msc {

MscPropCoverages::MscPropCoverages()
{}

MscPropCoverages::MscPropCoverages(const MscPropCoverages& orig)
  : _coverageItems(orig._coverageItems)
{}

MscPropCoverages::~MscPropCoverages()
{}

void  MscPropCoverages::addCoverageItem(const MscCoverageItem& coverageItem)
{
  this->_coverageItems.push_back(coverageItem);

  return;
}

void  MscPropCoverages::addCoverageItem(const QString& name,
                                        const QUuid& uuid,
                                        const MscCoverageType coverageType)
{
  this->_coverageItems.push_back(MscCoverageItem(name, uuid, coverageType));

  return;
}

const MscPropCoverages::CoverageItemSet&  MscPropCoverages::coverageItems() const
{
  return this->_coverageItems;
}

void  MscPropCoverages::resetCoverageItems()
{
  this->_coverageItems.clear();

  return;
}

} // namespace msc
} // namespace model
