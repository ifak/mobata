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

#include "mscfragmentitem.hpp"

#include "mscfragmentregionitem.hpp"

#include "../../utils/functors.hpp"

namespace model{
namespace msc{

class MscFragmentItem::Private
{
  friend class MscFragmentItem;

  Private(int type) : _fragmentType(type),
    _duration(0)
  {}

public:
  ~Private()
  {}

private:
  int   _fragmentType;
  uint  _duration;
};

MscFragmentItem::MscFragmentItem(int type)
  :	MscSequenceItem(), _d(new Private(type))
{
  this->setIcon(QIcon(":mobata/images/msc/fragment.png"));
  this->setText(fragmentType2string(this->_d->_fragmentType));
}

MscFragmentItem::~MscFragmentItem()
{}

int MscFragmentItem::fragmentType() const
{
  return this->_d->_fragmentType;
}

void MscFragmentItem::setFragmentType(int fragmentType)
{
  this->_d->_fragmentType=fragmentType;

  return;
}

MscFragmentRegionItem* MscFragmentItem::addRegion(const QString& condition)
{
  MscFragmentRegionItem* newFragmentRegion = new MscFragmentRegionItem(condition);
  if(!addRegion(newFragmentRegion))
  {
    delete newFragmentRegion;
    return nullptr;
  }
  return newFragmentRegion;
}

bool MscFragmentItem::addRegion(MscFragmentRegionItem* newFragmentRegion)
{
  if(this->fragmentType() == DurationFragment && this->regions().size() > 0)
    return false;

  Q_ASSERT(newFragmentRegion);
  if(!newFragmentRegion)
    return false;

  this->appendRow(newFragmentRegion);

  return true;
}

MscFragmentItem::ConstMscRegionSet MscFragmentItem::regions() const
{
  ConstMscRegionSet regions;

  int end=this->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->child(i);
    MscFragmentRegionItem* region=utils::simple_cast<MscFragmentRegionItem*>(currChildItem);
    regions.append(region);
  }

  return regions;
}

MscFragmentItem::MscRegionSet MscFragmentItem::regions()
{
  MscRegionSet regions;

  int end=this->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->child(i);
    MscFragmentRegionItem* region=utils::simple_cast<MscFragmentRegionItem*>(currChildItem);
    regions.append(region);
  }

  return regions;
}

MscFragmentItem::ConstComponentItems MscFragmentItem::componentItems() const
{
  ConstComponentItems fragmentComponents;
  for(MscFragmentRegionItem const* regionItem : this->regions())
  {
    ConstComponentItems regionComponents=regionItem->componentItems();
    for(MscComponentItem const* regionComp : regionComponents)
    {
      if(!fragmentComponents.contains(regionComp))
        fragmentComponents.append(regionComp);
    }
  }

  return  fragmentComponents;
}

void MscFragmentItem::setDuration(uint duration)
{
  this->_d->_duration = duration;
}

uint MscFragmentItem::duration() const
{
  return this->_d->_duration;
}

}/// end namespace msc
}/// end namespace model
