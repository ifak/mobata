#include "comcheckmsc.hpp"

using namespace graphlayout;

comCheckMsc::comCheckMsc(model::msc::MscSequence* mscSeq) : _mscSeq(mscSeq)
{

}

bool comCheckMsc::execute(QString *errorString)
{
  this->_errorString = errorString;
  this->_componentList.clear();

  bool ok;
  ok = this->checkComponents(this->_mscSeq->componentItems());
  if(!ok)
  {
    errorString = this->_errorString;
    return false;
  }

  ok = this->checkList(this->_mscSeq->sequenceItems());
  if(!ok)
  {
    errorString = this->_errorString;
    return false;
  }
  return true;
}

bool comCheckMsc::checkList(const model::msc::MscSequence::ConstSequenceItems list)
{
  for(const model::msc::MscSequenceItem* item : list)
  {
    if(item->stepType() == model::msc::MessageStep ||
       item->stepType() == model::msc::CheckMessageStep)
    {
      if(!this->checkMessage(item))
      {
        return false;
      }
    }
    else if(item->stepType() == model::msc::StatementStep)
    {
      if(!this->checkStatement(item))
      {
        return false;
      }
    }
    else if(item->stepType() == model::msc::TimerStep ||
            item->stepType() == model::msc::TimeoutStep ||
            item->stepType() == model::msc::SleepTimerStep)
    {
      if(!this->checkTimer(item))
      {
        return false;
      }
    }
    else if(item->stepType() == model::msc::FragmentStep)
    {
      if(!this->checkFragment(item))
      {
        return false;
      }
    }
    else
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: SequenceItem invalid";
      return false;
    }
  }
  return true;
}

bool comCheckMsc::checkComponents(const model::msc::MscSequence::ConstComponentItems list)
{
  for(const model::msc::MscComponentItem* component : list)
  {
    if(this->_componentList.contains(component))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Duplicated Component in Componentlist"<<component->toString();
      return false;
    }
    else
    {
      this->_componentList.append(component);
      if(!this->checkPorts(component->ports()))
      {
        return false;
      }
    }
  }
  return true;
}

bool comCheckMsc::checkPorts(const model::msc::MscComponentItem::ConstPortSet list)
{
  for(const model::msc::PortItem* port : list)
  {
    if(this->_portList.contains(port))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Duplicated Port in Component: "<<port->toString()<<" in "<<port->owner()->toString();
      return false;
    }
    else if(!port->owner())
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Port without owner: "<<port->toString();
      return false;
    }
    else if(!this->_componentList.contains(dynamic_cast<const model::msc::MscComponentItem*>(port->owner())))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Port with unknown owner: "<<port->toString();
      return false;
    }
    else
    {
      this->_portList.append(port);
    }
  }
  return true;
}

bool comCheckMsc::checkMessage(const model::msc::MscSequenceItem* item)
{
  if(item->stepType() == model::msc::MessageStep)
  {
    const model::msc::MscMessageItem* castItem = dynamic_cast<const model::msc::MscMessageItem*>(item);
    if(!castItem)
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Message: Cast to MscMessageItem not working";
      return false;
    }
    if(!this->_portList.contains(castItem->sourcePort()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Message: Sourceport not exist "<<castItem->sourcePort()->toString();
      return false;
    }
    else if(!this->_portList.contains(castItem->targetPort()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Message: Targetport not exist "<<castItem->sourcePort()->toString();
      return false;
    }
    else if(castItem->toString() == "")
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: Message: Message empty";
      return false;
    }
  }
  else if(item->stepType() == model::msc::CheckMessageStep)
  {
    const model::msc::MscCheckMessageItem* castItem = dynamic_cast<const model::msc::MscCheckMessageItem*>(item);
    if(!castItem)
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: CheckMessage: Cast to MscCheckMessageItem not working";
      return false;
    }
    if(!this->_portList.contains(castItem->sourcePort()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: CheckMessage: Sourceport not exist "<<castItem->sourcePort()->toString();
      return false;
    }
    else if(!this->_portList.contains(castItem->targetPort()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: CheckMessage: Targetport not exist "<<castItem->sourcePort()->toString();
      return false;
    }
    else if(castItem->toString() == "")
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: CheckMessage: CheckMessage empty";
      return false;
    }
  }
  else
  {
    return false;
  }
  return true;
}

bool comCheckMsc::checkStatement(const model::msc::MscSequenceItem* item)
{
  if(item->stepType() == model::msc::StatementStep)
  {
    const model::msc::MscStatementItem* castItem = dynamic_cast<const model::msc::MscStatementItem*>(item);
    if(!castItem)
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Statement: Cast to MscStatementItem not working";
      return false;
    }
    if(!this->_componentList.contains(castItem->component()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Statement: Component not exist: "<<castItem->component()->toString();
      return false;
    }
    else if(castItem->toString() == "")
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: Statement: Statement empty";
      return false;
    }
  }
  else
  {
    return false;
  }
  return true;
}

bool comCheckMsc::checkTimer(const model::msc::MscSequenceItem* item)
{
  if(item->stepType() == model::msc::TimerStep)
  {
    const model::msc::MscTimerItem* castItem = dynamic_cast<const model::msc::MscTimerItem*>(item);
    if(!castItem)
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Timer: Cast to MscTimerItem not working";
      return false;
    }
    if(!this->_componentList.contains(castItem->component()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Timer: Component not exist: "<<castItem->component()->toString();
      return false;
    }
    else if(castItem->toString() == "")
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: Timer: Timer string empty";
      return false;
    }
    else if(castItem->value() == 0)
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: Timer: Timer value zero";
      return false;
    }
  }
  else if(item->stepType() == model::msc::TimeoutStep)
  {
    const model::msc::MscTimeoutItem* castItem = dynamic_cast<const model::msc::MscTimeoutItem*>(item);
    if(!castItem)
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Timeout: Cast to MscTimeoutItem not working";
      return false;
    }
    if(!this->_componentList.contains(castItem->component()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Timeout: Component not exist: "<<castItem->component()->toString();
      return false;
    }
    else if(castItem->toString() == "")
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: Timeout: Timeout string empty";
      return false;
    }
    else if(!castItem->timer())
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Timeout: TimerItem not exist: ";
      return false;
    }
    else if(castItem->timer()->value() == 0)
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: Timeout: Timeout value zero";
      return false;
    }
  }
  else if(item->stepType() == model::msc::SleepTimerStep)
  {
    const model::msc::MscSleepTimerItem* castItem = dynamic_cast<const model::msc::MscSleepTimerItem*>(item);
    if(!castItem)
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: SleepTimer: Cast to MscSleepTimerItem not working";
      return false;
    }
    if(!this->_componentList.contains(castItem->component()))
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: SleepTimer: Component not exist: "<<castItem->component()->toString();
      return false;
    }
    else if(castItem->toString() == "")
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: SleepTimer: SleepTimer string empty";
      return false;
    }
    else if(castItem->value() == 0)
    {
      utils::AddPtrString(this->_errorString)<<"Minor Bug: SleepTimer: SleepTimer value zero";
      return false;
    }
  }
  else
  {
    return false;
  }
  return true;
}

bool comCheckMsc::checkFragment(const model::msc::MscSequenceItem* item)
{
  if(item->stepType() == model::msc::FragmentStep)
  {
    const model::msc::MscFragmentItem* castItem = dynamic_cast<const model::msc::MscFragmentItem*>(item);
    if(!castItem)
    {
      utils::AddPtrString(this->_errorString)<<"Major Bug: Fragment: Cast to MscFragmentItem not working";
      return false;
    }
    for(const model::msc::MscComponentItem* comp : castItem->componentItems())
    {
      if(!this->_componentList.contains(comp))
      {
        utils::AddPtrString(this->_errorString)<<"Major Bug: Fragment: Component not exist: "<<comp->toString();
        return false;
      }
      else if(castItem->regions().isEmpty())
      {
        utils::AddPtrString(this->_errorString)<<"Minor Bug: Fragment: No Regions in Fragment";
        return false;
      }
      for(const model::msc::MscFragmentRegionItem* fragregion : castItem->regions())
      {
        for(const model::msc::MscComponentItem* comp : fragregion->componentItems())
        {
          if(!this->_componentList.contains(comp))
          {
            utils::AddPtrString(this->_errorString)<<"Major Bug: FragmentRegion: Component not exist: "<<comp->toString();
            return false;
          }
        }
        if(!this->checkList(fragregion->sequenceItems()))
        {
          return false;
        }
      }
    }
  }
  else
  {
    return false;
  }
  return true;
}
