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

#include "requirementitem.hpp"

#include "../msc/mscfragmentitem.hpp"

namespace model{
namespace irdl{

class RequirementItem::Private
{
  friend class RequirementItem;

  Private()
  {}

  ~Private()
  {}
};

RequirementItem::RequirementItem(const QString& name)
  : msc::MscSequence(name),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    _d(new Private())
{
    this->setText(this->toString());
}

RequirementItem::~RequirementItem()
{
  delete this->_d;
}

void RequirementItem::reset()
{
  this->resetAttributes();
  this->resetSignals();

  msc::MscSequence::reset();

  return;
}

msc::MscFragmentItem *RequirementItem::addDurationFragment(uint duration)
{
  msc::MscFragmentItem* newDurationFragment =  this->addFragment(msc::DurationFragment);
  Q_ASSERT(newDurationFragment);
  newDurationFragment->setDuration(duration);
  newDurationFragment->addRegion(QString("Duration = %1ms").arg(duration));
  newDurationFragment->setText("Duration");

  return newDurationFragment;
}

}/// end namespace requirement
}/// end namespace model
