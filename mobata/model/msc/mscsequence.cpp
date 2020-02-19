#include "mscsequence.hpp"

#include "mscmessageitem.hpp"
#include "msccheckmessageitem.hpp"
#include "msctimeoutitem.hpp"
#include "msctimeritem.hpp"
#include "mscsleeptimeritem.hpp"
#include "mscfragmentitem.hpp"
#include "mscstatementitem.hpp"
#include "msccomponentitem.hpp"

#include "../base/portitem.hpp"

#include "../../utils/functors.hpp"

#include <QSet>

#include "../../memory_leak_start.hpp"

namespace model{
namespace msc{

class MscSequence::Private
{
  friend class MscSequence;

  QStandardItem* _stepsItem;

  Private() : _stepsItem(0)
  {}

  void createStepsItem(MscSequence* parentSequence);
};

void MscSequence::Private::createStepsItem(MscSequence* parentSequence)
{
  Q_ASSERT(parentSequence);

  if(this->_stepsItem)
    return;

  this->_stepsItem=new QStandardItem(QIcon(":/mobata/images/base/manysequence.png"),
                                     QLatin1String("steps"));
  this->_stepsItem->setFlags(this->_stepsItem->flags() & ~Qt::ItemIsEditable);
  parentSequence->appendRow(this->_stepsItem);

  return;
}

MscSequence::MscSequence(const QString& name)
  :	prop::NameProperty(name),
    _d(new Private)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/sequence.png")));
  this->setText(this->name());
}

MscSequence::~MscSequence()
{
  delete this->_d;
}

void MscSequence::reset()
{
  if(this->_d->_stepsItem)
    this->_d->_stepsItem->removeRows(0, this->_d->_stepsItem->rowCount());

  return;
}

MscMessageItem* MscSequence::addMessage(MscComponentItem const* sourceComponent,
                                        MscComponentItem const* targetComponent,
                                        const QString& messageText)
{
  Q_ASSERT(sourceComponent);
  Q_ASSERT(targetComponent);

  PortItem const* sourcePort = sourceComponent->defaultPort();
  PortItem const* targetPort = targetComponent->defaultPort();
  Q_ASSERT(sourcePort);
  Q_ASSERT(targetPort);

  return this->addMessage(sourcePort, targetPort, messageText);
}

MscMessageItem* MscSequence::addMessage(PortItem const* sourcePort,
                                        PortItem const* targetPort,
                                        const QString& messageText)
{
  Q_ASSERT(sourcePort);
  Q_ASSERT(targetPort);

  this->_d->createStepsItem(this);

  MscMessageItem* newMessage=new MscMessageItem(sourcePort,
                                                targetPort,
                                                messageText);
  this->_d->_stepsItem->appendRow(newMessage);

  return newMessage;
}

bool MscSequence::addMessage(MscMessageItem* newMessage)
{
  if(!newMessage)
    return false;

  this->_d->createStepsItem(this);

  this->_d->_stepsItem->appendRow(newMessage);

  return true;
}

MscCheckMessageItem *MscSequence::addCheck(const MscComponentItem *sourceComponent,
                                           const MscComponentItem *targetComponent,
                                           const QString &messageText)
{
  Q_ASSERT(sourceComponent);
  Q_ASSERT(targetComponent);

  PortItem const* sourcePort = sourceComponent->defaultPort();
  PortItem const* targetPort = targetComponent->defaultPort();
  Q_ASSERT(sourcePort);
  Q_ASSERT(targetPort);

  return this->addCheck(sourcePort, targetPort, messageText);
}

MscCheckMessageItem *MscSequence::addCheck(const base::PortItem *sourcePort,
                                           const base::PortItem *targetPort,
                                           const QString &messageText)
{
  Q_ASSERT(sourcePort);
  Q_ASSERT(targetPort);

  MscCheckMessageItem* newCheckMessage=new MscCheckMessageItem(sourcePort,
                                                               targetPort,
                                                               messageText);

  if(this->addCheck(newCheckMessage) == false)
  {
    if(newCheckMessage) delete newCheckMessage;
    return nullptr;
  }
  return newCheckMessage;
}

bool MscSequence::addCheck(MscCheckMessageItem* newCheckMessage)
{
  return this->addMessage(newCheckMessage);
}

MscTimerItem* MscSequence::addTimer(const MscComponentItem* component,
                                    const QString& timerName,
                                    QString* errorMessage)
{
  Q_ASSERT(component);

  if(this->timer(timerName))
  {
    if(errorMessage)
      *errorMessage += QObject::tr("timer with name '%1' is still available, "
                                   "timer name must be unique!")
                       .arg(timerName);
    return 0;
  }

  this->_d->createStepsItem(this);

  MscTimerItem* newTimer=new MscTimerItem(component,
                                          timerName);
  this->_d->_stepsItem->appendRow(newTimer);

  return newTimer;
}

MscSleepTimerItem* MscSequence::addSleepTimer(const MscComponentItem* component,
                                              double duration)
{
  Q_ASSERT(component);

  this->_d->createStepsItem(this);

  MscSleepTimerItem* newSleepTimer=new MscSleepTimerItem(component,
                                                         duration);
  this->_d->_stepsItem->appendRow(newSleepTimer);

  return newSleepTimer;
}

MscTimeoutItem* MscSequence::addTimeout(const MscComponentItem* component,
                                        MscTimerItem const* timer)
{
  Q_ASSERT(component);
  Q_ASSERT(timer);

  this->_d->createStepsItem(this);

  MscTimeoutItem* newTimeout=new MscTimeoutItem(component, timer);
  this->_d->_stepsItem->appendRow(newTimeout);

  return newTimeout;
}

MscFragmentItem* MscSequence::addFragment(FragmentType fragmentType)
{
  this->_d->createStepsItem(this);

  MscFragmentItem* newFragment=new MscFragmentItem(fragmentType);
  this->_d->_stepsItem->appendRow(newFragment);

  return newFragment;
}

void MscSequence::addFragment(MscFragmentItem* newFragment)
{
  Q_ASSERT(newFragment);
  if(!newFragment)
    return;

  this->_d->createStepsItem(this);

  this->_d->_stepsItem->appendRow(newFragment);

  return;
}

MscStatementItem* MscSequence::addStatement(const MscComponentItem* component,
                                            const QString& statement)
{
  Q_ASSERT(component);

  this->_d->createStepsItem(this);

  MscStatementItem* newStatement=new MscStatementItem(component, statement);
  this->_d->_stepsItem->appendRow(newStatement);

  return newStatement;
}

MscSequence::ConstSequenceItems MscSequence::sequenceItems() const
{
  ConstSequenceItems sequenceItems;

  if(!this->_d->_stepsItem)
    return sequenceItems;

  int end=this->_d->_stepsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_stepsItem->child(i);
    MscSequenceItem* sequItem=utils::simple_cast<MscSequenceItem*>(currChild);
    Q_ASSERT(sequItem);
    sequenceItems.append(sequItem);
  }

  return sequenceItems;
}

MscSequenceItem const* MscSequence::sequenceItem(const QUuid& sequItemID) const
{
  for(MscSequenceItem const* sequItem : this->sequenceItems())
    if(sequItem->uuid()==sequItemID)
      return sequItem;

  return nullptr;
}

template<class SequType>
void sequTypeItems(MscSequence const* sequence,
                   QList<SequType>& sequTypeList)
{
  if(!sequence)
    return;

  foreach(MscSequenceItem const* sequItem,
          sequence->sequenceItems())
  {
    if(MscSequence const* innerSequence=dynamic_cast<MscSequence const*>(sequItem))
      sequTypeItems<SequType>(innerSequence, sequTypeList);
    else if(SequType sequTypeItem=dynamic_cast<SequType>(sequItem))
      sequTypeList.append(sequTypeItem);
  }

  return;
}

MscTimerItem const* MscSequence::timer(const QString& timerName)
{
  foreach(MscTimerItem const* timer,
          this->timers())
  {
    if(timer->name()==timerName)
      return timer;
  }

  return nullptr;
}

const MscTimerItem*MscSequence::timer(const QUuid& timerUuid)
{
  foreach(MscTimerItem const* timer,
          this->timers())
  {
    if(timer->uuid()==timerUuid)
      return timer;
  }

  return nullptr;
}

QList<MscTimerItem const*> MscSequence::timers() const
{
  QList<MscTimerItem const*> timerList;
  sequTypeItems<MscTimerItem const*>(this, timerList);

  return timerList;
}

MscSequence::ConstComponentItems MscSequence::componentItems() const
{
  using namespace utils;

  ConstComponentItems components;
  for(MscSequenceItem const* sequItem : this->sequenceItems())
  {
    if(sequItem->stepType()==MessageStep || sequItem->stepType()==CheckMessageStep)
    {
      MscMessageItem const* messageItem=dynamic_cast<MscMessageItem const*>(sequItem);
      Q_ASSERT(messageItem);

      ///component for source port
      PortItem const* portItem=messageItem->sourcePort();
      Q_ASSERT(portItem->ownerType()==PortItem::Component);
      MscComponentItem const* ownerComponent=dynamic_cast<MscComponentItem const*>(portItem->owner());
      Q_ASSERT(ownerComponent);
      if(!components.contains(ownerComponent))
        components.append(ownerComponent);

      ///component for target port
      portItem=messageItem->targetPort();
      Q_ASSERT(portItem->ownerType()==PortItem::Component);
      ownerComponent=dynamic_cast<MscComponentItem const*>(portItem->owner());
      Q_ASSERT(ownerComponent);
      if(!components.contains(ownerComponent))
        components.append(ownerComponent);
    }
    else if(sequItem->stepType()==StatementStep)
    {
      MscStatementItem const* statementItem=dynamic_cast<MscStatementItem const*>(sequItem);
      Q_ASSERT(statementItem);

      ///component
      MscComponentItem const* component=statementItem->component();
      Q_ASSERT(component);
      if(!components.contains(component))
        components.append(component);
    }
    else if(sequItem->stepType()==TimerStep)
    {
      MscTimerItem const* timerItem=dynamic_cast<MscTimerItem const*>(sequItem);
      Q_ASSERT(timerItem);

      ///component
      MscComponentItem const* component=timerItem->component();
      Q_ASSERT(component);
      if(!components.contains(component))
        components.append(component);
    }
    else if(sequItem->stepType()==FragmentStep)
    {
      MscFragmentItem const* fragmentItem=dynamic_cast<MscFragmentItem const*>(sequItem);
      Q_ASSERT(fragmentItem);

      ConstComponentItems fragmentComponents=fragmentItem->componentItems();
      for(model::msc::MscComponentItem const* fragmentComp : fragmentComponents)
      {
        if(!components.contains(fragmentComp))
          components.append(fragmentComp);
      }
    }
  }

  return components;
}

MscComponentItem const* MscSequence::component(const QUuid& uuid) const
{
  for(MscComponentItem const* comp : this->componentItems())
  {
    if(comp->uuid()==uuid)
      return comp;
  }
  return nullptr;
}

}/// end namespace msc
}/// end namespace model
