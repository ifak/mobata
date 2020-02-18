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

#include "../../memory_leak_start.hpp"

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
  QString err("");
  for (auto type : model->dataTypes())
  {
    if(type->name() == QString("int") || type->name() == QString("real") || type->name() == QString("bool"))
      continue;
    base::DataTypeItem* item = new base::DataTypeItem(type->name(),type->uuid());
    for (auto literals : type->literals())
      item->addLiteral(literals);

    this->addDataType(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for (auto component : model->components())
  {
    msc::MscComponentItem* item = new msc::MscComponentItem(component->name());
    item->setUuid(component->uuid());

    for (base::AttributeItem* attr : component->attributes())
    {
      auto newAttr = new base::AttributeItem(attr->name(),
                                             attr->dataType(),
                                             attr->initValue(),
                                             attr->uuid());
      item->addAttribute(newAttr,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    for (base::PortItem* port : component->ports())
    {
      if(port->name() == QStringLiteral("_defaultPort")){
        item->port(port->name())->setUuid(port->uuid());
        if(errorString) errorString->append(err);
        err = QString("");
      }
      else {
        auto newPort = new base::PortItem(port->name(),port->uuid());
        item->addPort(newPort,&err);
        if(errorString) errorString->append(err);
        err = QString("");
      }
    }
    this->addComponent(item,&err);
    for(auto req : this->requirements()){
      if(!req->component(item->uuid())){

      }
    }
    if(errorString) errorString->append(err);
    err = QLatin1String("");
  }
  for (base::AttributeItem* attr : model->attributes())
  {
    auto newAttr = new base::AttributeItem(attr->name(),
                                           attr->dataType(),
                                           attr->initValue(),
                                           attr->uuid());
    this->addAttribute(newAttr,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for (auto signal : model->getSignals())
  {
    base::SignalItem* item = new base::SignalItem(signal->name(),signal->uuid());
    for(auto param : signal->params())
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
  for (auto req : model->requirements())
  {
    RequirementItem* item = new RequirementItem(req->name());
    item->setUuid(req->uuid());
    for (auto type : req->dataTypes())
    {
      base::DataTypeItem* dItem = new base::DataTypeItem(type->name(),type->uuid());
      for (auto literals : type->literals())
        dItem->addLiteral(literals);
      item->addDataType(dItem,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    for (base::AttributeItem* attr : req->attributes())
    {
      auto newAttr = new base::AttributeItem(attr->name(),
                                             attr->dataType(),
                                             attr->initValue(),
                                             attr->uuid());
      item->addAttribute(newAttr,&err);
      if(errorString) errorString->append(err);
      err = QString("");
    }
    for (auto signal : req->getSignals())
    {
      base::SignalItem* sItem = new base::SignalItem(signal->name(),signal->uuid());
      for(auto param : signal->params())
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
    for (auto seqItem : req->sequenceItems())
      addSequenceItem(item,const_cast<msc::MscSequenceItem*>(seqItem));

    this->addRequirement(item,&err);
    if(errorString)errorString->append(err);
    err = QString("");
  }
}

void RequirementsModel::addContent(base::BaseModel *model,QString* errorString)
{
  QString err("");
  for (auto type : model->dataTypes())
  {
    if(type->name() == QString("int") || type->name() == QString("real") || type->name() == QString("bool"))
      continue;
    base::DataTypeItem* item = new base::DataTypeItem(type->name(),type->uuid());
    for (auto literals : type->literals())
      item->addLiteral(literals);
    this->addDataType(item,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }

  for (base::AttributeItem* attr : model->attributes())
  {
    auto newAttr = new base::AttributeItem(attr->name(),
                                           attr->dataType(),
                                           attr->initValue(),
                                           attr->uuid());
    this->addAttribute(newAttr,&err);
    if(errorString) errorString->append(err);
    err = QString("");
  }
  for (auto signal : model->getSignals())
  {
    base::SignalItem* item = new base::SignalItem(signal->name(),signal->uuid());
    for(auto param : signal->params())
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

void RequirementsModel::copyRegion(msc::MscFragmentRegionItem *origReg, msc::MscFragmentRegionItem *copyReg)
{
  for (model::msc::MscSequenceItem const* seqItem : origReg->sequenceItems()) {
    addSequenceItem(copyReg,const_cast<msc::MscSequenceItem*>(seqItem));
  }
}

void RequirementsModel::addSequenceItem(msc::MscSequence *seq, msc::MscSequenceItem *seqItem)
{
  auto item = seq;
  if(auto check = dynamic_cast<msc::MscCheckMessageItem*>(seqItem)){
    if(auto source = dynamic_cast<msc::MscComponentItem*>((base::ModelItem*)check->sourcePort()->owner())){
      if(auto realSource = this->component(source->name())){
        auto realSourcePort = realSource->port(check->sourcePort()->name());
        if(auto target = dynamic_cast<msc::MscComponentItem*>((base::ModelItem*)check->targetPort()->owner())){
          if(auto realTarget = this->component(target->name())){
            auto realTargetPort = realTarget->port(check->targetPort()->name());
            msc::MscCheckMessageItem* checkItem = new msc::MscCheckMessageItem(realSourcePort,realTargetPort,check->guard(),check->timeout());
            for(QString key : check->assign().keys()){
              checkItem->appendAssign(key, check->assign().value(key));
            }
            if(check->signal())
            {
              auto signalItem = this->signal(check->signal()->name());
              if(signalItem)
              {
                checkItem->setSignal(signalItem);
                foreach(auto param, check->paramValues())
                {
                  checkItem->addParamValue(signalItem->parameter(param->param()->name()), param->value());
                }
              }
            }

            item->addCheck(checkItem);
          }
        }
      }
    }
  }
  else if(auto fragment = dynamic_cast<msc::MscFragmentItem*>(seqItem)){
    auto fragItem = new msc::MscFragmentItem(fragment->fragmentType());
    fragItem->setUuid(fragment->uuid());
    fragItem->setDuration(fragment->duration());
    fragItem->setText(fragment->text());
    foreach (auto reg, fragment->regions()) {
      auto newReg = fragItem->addRegion(reg->condition());
      newReg->setUuid(reg->uuid());
      copyRegion(reg,newReg);
    }
    item->addFragment(fragItem);
  }
  else if(auto message = dynamic_cast<msc::MscMessageItem*>(seqItem)){
    if(auto source = dynamic_cast<msc::MscComponentItem*>((base::ModelItem*)message->sourcePort()->owner())){
      if(auto realSource = this->component(source->name())){
        auto realSourcePort = realSource->port(message->sourcePort()->name());
        if(auto target = dynamic_cast<msc::MscComponentItem*>((base::ModelItem*)message->targetPort()->owner())){
          if(auto realTarget = this->component(target->name())){
            auto realTargetPort = realTarget->port(message->targetPort()->name());
            msc::MscMessageItem* messageItem = new msc::MscMessageItem(realSourcePort,realTargetPort,message->text());
            if(message->signal())
            {
              auto signalItem = this->signal(message->signal()->name());
              if(signalItem)
              {
                messageItem->setSignal(signalItem);
                foreach(auto param, message->paramValues())
                {
                  messageItem->addParamValue(signalItem->parameter(param->param()->name()), param->value());
                }
              }
            }
            item->addMessage(messageItem);

          }
        }
      }
    }
  }
  else if(auto sleeper = dynamic_cast<msc::MscSleepTimerItem*>(seqItem)){
    if(this->component(sleeper->component()->name())){
      auto sItem = item->addSleepTimer((msc::MscComponentItem*)this->component(sleeper->component()->name()),sleeper->value());
      sItem->setUuid(sleeper->uuid());
    }
  }
  else if(auto statement = dynamic_cast<msc::MscStatementItem*>(seqItem)){
    if(this->component(statement->component()->name())){
      auto sItem = item->addStatement((msc::MscComponentItem*)this->component(statement->component()->name()),statement->statement());
      sItem->setUuid(statement->uuid());
    }
  }
  else if(auto timeout = dynamic_cast<msc::MscTimeoutItem*>(seqItem)){
    if(this->component(timeout->component()->name())){
      msc::MscTimerItem* timer = 0;
      if(this->component(timeout->timer()->component()->name())){
        timer = new msc::MscTimerItem((msc::MscComponentItem*)this->component(timeout->timer()->component()->name()),timeout->timer()->name(),timeout->timer()->value());
        timer->setUuid(timeout->timer()->uuid());
      }
      if(timer){
        auto tItem = item->addTimeout((msc::MscComponentItem*)this->component(timeout->component()->name()),timer);
        tItem->setUuid(timeout->uuid());
      }
    }
  }
  else if(auto timer = dynamic_cast<msc::MscTimerItem*>(seqItem)){
    if(this->component(timer->component()->name())){
      auto tItem = item->addTimer((msc::MscComponentItem*)this->component(timer->component()->name()),timer->name());
      tItem->setUuid(timer->uuid());
      tItem->setValue(timer->value());
    }
  }
}

}///end namespace requirement
}///end namespace model
