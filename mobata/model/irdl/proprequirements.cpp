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

#include "proprequirements.hpp"

#include "requirementitem.hpp"

#include "../../utils/functors.hpp"

namespace model {
namespace irdl {

class PropRequirements::Private
{
  friend class PropRequirements;

  Private()
    : _requirementsItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _requirementsItem;
};

PropRequirements::PropRequirements(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setRequirementsParentItem(parentItem);
}

PropRequirements::~PropRequirements()
{
  delete this->_d;
}

void PropRequirements::setRequirementsParentItem(QStandardItem* parent)
{
  Q_ASSERT(parent);

  if(this->_d->_requirementsItem)
    return;

  this->_d->_requirementsItem = new QStandardItem(QIcon(":mobata/images/requirement/requirementpic.png"),
                                                  QLatin1String("requirement"));
  this->_d->_requirementsItem->setFlags(this->_d->_requirementsItem->flags() & ~Qt::ItemIsEditable);
  parent->appendRow(this->_d->_requirementsItem);

  return;
}

void PropRequirements::resetRequirements()
{
  if(this->_d->_requirementsItem)
    this->_d->_requirementsItem->removeRows(0,
                                            this->_d->_requirementsItem->rowCount());

  return;
}

bool PropRequirements::addRequirement(RequirementItem* requirement,
                                      QString* errorString)
{
  if(!requirement)
    return false;

  if(this->requirement(requirement->uuid()))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a requirement "
                                                  "with uuid'%1' available!")
                                      .arg(requirement->uuid().toString());
    return false;
  }

  this->_d->_requirementsItem->appendRow(requirement);
  requirement->setText(requirement->name());

  return true;
}

RequirementItem* PropRequirements::addRequirement(const QString& name)
{
  RequirementItem* newRequirement=new RequirementItem(name);
  this->_d->_requirementsItem->appendRow(newRequirement);
  newRequirement->setText(newRequirement->name());

  return newRequirement;
}

void PropRequirements::removeRequirement(RequirementItem* requirement)
{
  if(!requirement)
    return;
  Q_ASSERT(this->_d->_requirementsItem->model()==requirement->model());

  this->_d->_requirementsItem->removeRow(requirement->row());

  return;
}

void PropRequirements::removeRequirement(const QUuid& requirementId)
{
  RequirementItem* requirement=this->requirement(requirementId);
  if(!requirement)
    return;

  this->_d->_requirementsItem->removeRow(requirement->row());

  return;
}

RequirementItem* PropRequirements::requirement(const QUuid& requirementUuid) const
{
  for(RequirementItem* requirementItem: this->requirements())
    if(requirementItem->uuid()==requirementUuid)
      return requirementItem;

  return nullptr;
}

PropRequirements::RequirementsSet PropRequirements::requirements() const
{
  RequirementsSet requirements;
  if(!this->_d->_requirementsItem)
    return requirements;

  int end=this->_d->_requirementsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->_d->_requirementsItem->child(i);
    RequirementItem* requirement=utils::simple_cast<RequirementItem*>(currChildItem);
    Q_ASSERT(requirement);
    requirements.append(requirement);
  }

  return requirements;
}

} // namespace requirement
} // namespace model
