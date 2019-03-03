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

#include "requirementsmodel.hpp"

#include "requirementitem.hpp"

#include <model/base/attributeitem.hpp>
#include <model/base/datatypeitem.hpp>

#include <model/msc/msccheckmessageitem.hpp>
#include <model/msc/mscfragmentitem.hpp>
#include <model/msc/mscmessageitem.hpp>
#include <model/msc/mscsleeptimeritem.hpp>
#include <model/msc/mscstatementitem.hpp>
#include <model/msc/msctimeoutitem.hpp>
#include <model/msc/msctimeritem.hpp>
#include <model/msc/mscfragmentregionitem.hpp>

#include "../../utils/functors.hpp"

namespace model{
namespace irdl{

class RequirementsModel::Private
{
  friend class RequirementsModel;

  Private()
  {}

public:
  ~Private()
  {}

private:
};

RequirementsModel::RequirementsModel(QObject *parent)
  :	base::BaseModel(parent),
    PropComponents(this->invisibleRootItem()),
    PropRequirements(this->invisibleRootItem()),
    _d(new Private)
{
  this->setDataTypesParentItem(this->invisibleRootItem());
  this->setAttributesParentItem(this->invisibleRootItem());
  this->setSignalsParentItem(this->invisibleRootItem());

  this->setName("requirements_model");

  this->setHeaderData(0, Qt::Horizontal, this->name(), Qt::DisplayRole);
}

RequirementsModel::~RequirementsModel()
{
  delete this->_d;
}

void RequirementsModel::reset()
{
  base::BaseModel::reset();
  this->resetRequirements();
  this->resetSignals();
  this->resetAttributes();
  this->resetComponents();


  this->setName("requirements_model");

  return;
}

void RequirementsModel::addContent(RequirementsModel *model, QString *errorString)
{
  Q_ASSERT(model);

  QString err("");
  for(const base::DataTypeItem* type : model->dataTypes())
  {
    if(type->name() == QString("int") || type->name() == QString("real") || type->name() == QString("bool"))
      continue;
    base::DataTypeItem* item = new base::DataTypeItem(type->name(), type->uuid());
    for (const QString literals : type->literals())
      item->addLiteral(literals);

    this->addDataType(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for(const base::ComponentItem* component : model->components())
  {
    msc::MscComponentItem* item = new msc::MscComponentItem(component->name());
    item->setUuid(component->uuid());

    for(const base::AttributeItem* attr : component->attributes())
    {
      base::AttributeItem* newAttr = new base::AttributeItem(attr->name(),
                                                             attr->dataType(),
                                                             attr->initValue(),
                                                             attr->uuid());
      item->addAttribute(newAttr,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    this->addComponent(item,&err);
    if(errorString) errorString->append(err);
    err = QLatin1String("");
  }
  for(const base::AttributeItem* attr : model->attributes())
  {
    base::AttributeItem* newAttr = new base::AttributeItem(attr->name(),
                                                           attr->dataType(),
                                                           attr->initValue(),
                                                           attr->uuid());
    this->addAttribute(newAttr,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for(const base::SignalItem* signal : model->getSignals())
  {
    base::SignalItem* item = new base::SignalItem(signal->name(),signal->uuid());
    for(const base::ParamItem* param : signal->params())
    {
      base::ParamItem* pItem = new base::ParamItem(param->name(),
                                                   param->dataType(),
                                                   param->uuid());
      item->addParameter(pItem,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    this->addSignal(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for(const RequirementItem* req : model->requirements())
  {
    RequirementItem* item = new RequirementItem(req->name());
    item->setUuid(req->uuid());
    for (const base::DataTypeItem* type : req->dataTypes())
    {
      base::DataTypeItem* dItem = new base::DataTypeItem(type->name(),type->uuid());
      for (const QString literals : type->literals())
        dItem->addLiteral(literals);
      item->addDataType(dItem,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    for(const base::AttributeItem* attr : req->attributes())
    {
      base::AttributeItem* newAttr = new base::AttributeItem(attr->name(),
                                                             attr->dataType(),
                                                             attr->initValue(),
                                                             attr->uuid());
      item->addAttribute(newAttr,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    for(const base::SignalItem* signal : req->getSignals())
    {
      base::SignalItem* sItem = new base::SignalItem(signal->name(),signal->uuid());
      for(const base::ParamItem* param : signal->params())
      {
        base::ParamItem* pItem = new base::ParamItem(param->name(),
                                                     param->dataType(),
                                                     param->uuid());
        sItem->addParameter(pItem,&err);
        if(errorString) errorString->append(err);
        err = QString("");
      }
      item->addSignal(sItem,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    for(const msc::MscSequenceItem* seqItem : req->sequenceItems())
      if(!addSequenceItem(item,const_cast<msc::MscSequenceItem*>(seqItem)))
        err += "Error: Adding Sequence Item to Requirement Item failed!\n";

    this->addRequirement(item,&err);
    if(errorString)errorString->append(err);
    err = QString("");
  }
}

void RequirementsModel::addContent(base::BaseModel *model,QString* errorString)
{
  Q_ASSERT(model);

  QString err("");
  for(const base::DataTypeItem* type : model->dataTypes())
  {
    if(type->name() == QString("int") || type->name() == QString("real") || type->name() == QString("bool"))
      continue;
    base::DataTypeItem* item = new base::DataTypeItem(type->name(),type->uuid());
    for (const QString literals : type->literals())
      item->addLiteral(literals);
    this->addDataType(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }

  for(const base::AttributeItem* attr : model->attributes())
  {
    base::AttributeItem* newAttr = new base::AttributeItem(attr->name(),
                                                           attr->dataType(),
                                                           attr->initValue(),
                                                           attr->uuid());
    this->addAttribute(newAttr,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for(const base::SignalItem* signal : model->getSignals())
  {
    base::SignalItem* item = new base::SignalItem(signal->name(),signal->uuid());
    for(const base::ParamItem* param : signal->params())
    {
      base::ParamItem* pItem = new base::ParamItem(param->name(),
                                                   param->dataType(),
                                                   param->uuid());
      item->addParameter(pItem,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    this->addSignal(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }

}

bool RequirementsModel::copyRegion(const msc::MscFragmentRegionItem *origReg, msc::MscFragmentRegionItem *copyReg)
{
  Q_ASSERT(origReg);
  Q_ASSERT(copyReg);

  for(model::msc::MscSequenceItem const* seqItem : origReg->sequenceItems())
    if(!addSequenceItem(copyReg, seqItem))
      return false;

  return true;
}

bool RequirementsModel::addSequenceItem(msc::MscSequence *seq, const msc::MscSequenceItem *seqItem)
{
  Q_ASSERT(seq);
  Q_ASSERT(seqItem);

  msc::MscSequence* item = seq;

  if(const msc::MscCheckMessageItem* check = static_cast<const msc::MscCheckMessageItem*>(seqItem))
  {
    const base::ModelItem* owner = check->sourcePort()->owner();
    Q_ASSERT(owner);

    const msc::MscComponentItem* source = static_cast<const msc::MscComponentItem*>(owner);
    Q_ASSERT(source);
    if(!source)
      return false;

    const base::ComponentItem* realSource = this->component(source->name());
    Q_ASSERT(realSource);
    if(!realSource)
      return false;

    const base::PortItem* realSourcePort = realSource->port(check->sourcePort()->name());
    Q_ASSERT(realSourcePort);
    const base::ModelItem* portOwner = check->targetPort()->owner();
    Q_ASSERT(portOwner);
    const msc::MscComponentItem* target = static_cast<const msc::MscComponentItem*>(portOwner);
    Q_ASSERT(target);
    if(!target)
      return false;

    const base::ComponentItem* realTarget = this->component(target->name());
    Q_ASSERT(realTarget);
    if(!realTarget)
      return false;

    const base::PortItem* realTargetPort = realTarget->port(check->targetPort()->name());
    Q_ASSERT(realTargetPort);
    msc::MscCheckMessageItem* checkItem = new msc::MscCheckMessageItem(realSourcePort,
                                                                       realTargetPort,
                                                                       check->guard(),
                                                                       check->timeout());
    if(check->signal())
    {
      const base::SignalItem* signalItem = this->signal(check->signal()->name());
      Q_ASSERT(signalItem);
      if(!signalItem)
        return false;

      checkItem->setSignal(signalItem);
      for(const base::ParamValueItem* param : check->paramValues())
      {
        const base::ParamItem* paramItem = signalItem->parameter(param->param()->name());
        Q_ASSERT(paramItem);
        checkItem->addParamValue(paramItem, param->value());
      }
    }

    item->addCheck(checkItem);
  }
  else if(const msc::MscFragmentItem* fragment = static_cast<const msc::MscFragmentItem*>(seqItem))
  {
    msc::MscFragmentItem* fragItem = new msc::MscFragmentItem(fragment->fragmentType());
    fragItem->setUuid(fragment->uuid());
    fragItem->setDuration(fragment->duration());
    fragItem->setText(fragment->text());
    for(const msc::MscFragmentRegionItem* reg : fragment->regions())
    {
      msc::MscFragmentRegionItem* newReg = fragItem->addRegion(reg->condition());
      newReg->setUuid(reg->uuid());
      copyRegion(reg, newReg);
    }
    item->addFragment(fragItem);
  }
  else if(const msc::MscMessageItem* message = static_cast<const msc::MscMessageItem*>(seqItem))
  {
    const base::ModelItem* portOwner = message->sourcePort()->owner();
    Q_ASSERT(portOwner);
    const msc::MscComponentItem* source = static_cast<const msc::MscComponentItem*>(portOwner);
    Q_ASSERT(source);
    if(!source)
      return false;
    const base::ComponentItem* realSource = this->component(source->name());
    Q_ASSERT(realSource);
    if(!realSource)
      return false;
    const model::base::PortItem* realSourcePort = realSource->port(message->sourcePort()->name());
    Q_ASSERT(realSourcePort);

    const base::ModelItem* targetPortOwner = message->targetPort()->owner();
    Q_ASSERT(targetPortOwner);
    const msc::MscComponentItem* target = static_cast<const msc::MscComponentItem*>(targetPortOwner);
    Q_ASSERT(target);
    if(target)
      return false;
    const base::ComponentItem* realTarget = this->component(target->name());
    Q_ASSERT(realTarget);
    if(!realTarget)
      return false;
    const base::PortItem* realTargetPort = realTarget->port(message->targetPort()->name());
    Q_ASSERT(realTargetPort);
    msc::MscMessageItem* messageItem = new msc::MscMessageItem(realSourcePort,
                                                               realTargetPort,
                                                               message->text());
    if(message->signal())
    {
      const base::SignalItem* signalItem = this->signal(message->signal()->name());
      if(signalItem)
      {
        messageItem->setSignal(signalItem);
        for(const base::ParamValueItem* param : message->paramValues())
          messageItem->addParamValue(signalItem->parameter(param->param()->name()), param->value());
      }
    }
    item->addMessage(messageItem);
  }
  else if(const msc::MscSleepTimerItem* sleeper = static_cast<const msc::MscSleepTimerItem*>(seqItem))
  {
    if(this->component(sleeper->component()->name()))
    {
      const msc::MscComponentItem* component = static_cast<const msc::MscComponentItem*>(this->component(sleeper->component()->name()));
      Q_ASSERT(component);
      msc::MscSleepTimerItem* sItem = item->addSleepTimer(component, sleeper->value());
      sItem->setUuid(sleeper->uuid());
    }
  }
  else if(const msc::MscStatementItem* statement = static_cast<const msc::MscStatementItem*>(seqItem))
  {
    if(this->component(statement->component()->name()))
    {
      const msc::MscComponentItem* component = static_cast<const msc::MscComponentItem*>(this->component(statement->component()->name()));
      Q_ASSERT(component);
      msc::MscStatementItem* sItem = item->addStatement(component, statement->statement());
      sItem->setUuid(statement->uuid());
    }
  }
  else if(const msc::MscTimeoutItem* timeout = static_cast<const msc::MscTimeoutItem*>(seqItem))
  {
    if(this->component(timeout->component()->name()))
    {
      msc::MscTimerItem* timer = 0;
      if(this->component(timeout->timer()->component()->name()))
      {
        const msc::MscComponentItem* component = static_cast<const msc::MscComponentItem*>(this->component(timeout->timer()->component()->name()));
        Q_ASSERT(component);
        timer = new msc::MscTimerItem(component, timeout->timer()->name(), timeout->timer()->value());
        timer->setUuid(timeout->timer()->uuid());
      }
      if(timer)
      {
        const msc::MscComponentItem* component = static_cast<const msc::MscComponentItem*>(this->component(timeout->component()->name()));
        Q_ASSERT(component);
        msc::MscTimeoutItem* tItem = item->addTimeout(component, timer);
        tItem->setUuid(timeout->uuid());
      }
    }
  }
  else if(const msc::MscTimerItem* timer = static_cast<const msc::MscTimerItem*>(seqItem))
  {
    if(this->component(timer->component()->name()))
    {
      const msc::MscComponentItem* component = static_cast<const msc::MscComponentItem*>(this->component(timer->component()->name()));
      Q_ASSERT(component);
      msc::MscTimerItem* tItem = item->addTimer(component, timer->name());
      tItem->setUuid(timer->uuid());
      tItem->setValue(timer->value());
    }
  }

  return true;
}

}///end namespace requirement
}///end namespace model
