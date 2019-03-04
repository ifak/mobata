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

#include "mscloopfragmentitem.hpp"

namespace model {
namespace msc {

class MscLoopFragmentItem::Private
{
  friend class MscLoopFragmentItem;

  Private(const QString cond)
    : _cond(cond)
  {}
  const QString _cond;
public:
  ~Private(){

  }
};

MscLoopFragmentItem::MscLoopFragmentItem(const QString cond)
  :MscFragmentItem(LoopFragment),_d(new Private(cond)){
  this->addRegion(cond);
}

MscLoopFragmentItem::~MscLoopFragmentItem()
{}

const QString& MscLoopFragmentItem::condition() const{
  return _d->_cond;
}

MscFragmentRegionItem* MscLoopFragmentItem::region()
{
  Q_ASSERT(regions().size());
  return regions().at(0);
}

}
}
