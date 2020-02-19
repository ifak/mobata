#include "comrendermscsequence.hpp"

#include <mobata/model/msc/msc.hpp>

#include "mscscene.hpp"
#include "mscfragment.hpp"
#include "mscfragmentregion.hpp"
#include "msccomponent.hpp"
#include "mscmessage.hpp"
#include "mscstatement.hpp"
#include "msctimeout.hpp"
#include "msctimer.hpp"
#include "mscsleeptimer.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace msc {

/// private class of command class ComRenderMscSequence ////////////
class ComRenderMscSequence::Private
{
  friend class ComRenderMscSequence;

  KMscScene*                      _mscScene;
  model::msc::MscSequence const*  _modelSequence;
  view::graph::ArcOptions         _arcOptions;

  Private(KMscScene* mscScene,
          model::msc::MscSequence const* modelSequence,
          view::graph::ArcOptions const& arcOptions)
    : _mscScene(mscScene),
      _modelSequence(modelSequence),
      _arcOptions(arcOptions)
  {}
};

///command class ComRenderMscSequence //////////////////////////////////
ComRenderMscSequence::ComRenderMscSequence(KMscScene* mscScene,
                                           model::msc::MscSequence const* modelSequence,
                                           graph::ArcOptions const& arcOptions)
  : _d(new Private(mscScene, modelSequence, arcOptions))
{
  Q_ASSERT(this->_d->_mscScene);
  Q_ASSERT(this->_d->_modelSequence);
}

ComRenderMscSequence::~ComRenderMscSequence()
{
  delete this->_d;
}

KMscScene* ComRenderMscSequence::viewScene()
{
  return this->_d->_mscScene;
}

model::msc::MscSequence const* ComRenderMscSequence::modelSequence() const
{
  return this->_d->_modelSequence;
}

bool ComRenderMscSequence::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_mscScene);
  Q_ASSERT(this->_d->_modelSequence);

  this->_d->_mscScene->reset();

  bool result=this->addComponents(errorMessage);
  if(!result)
    return false;

  foreach(model::msc::MscSequenceItem const* mscSequItem,
          this->_d->_modelSequence->sequenceItems())
  {
    result=this->dispatchSequenceItem(mscSequItem,
                                      0,
                                      errorMessage);
    if(!result)
      return false;
  }

  this->_d->_mscScene->render();

  return result;
}

bool ComRenderMscSequence::addComponents(QString* errorMessage)
{
  Q_UNUSED(errorMessage);

  Q_ASSERT(this->_d->_mscScene);
  Q_ASSERT(this->_d->_modelSequence);

  foreach(model::msc::MscComponentItem const* componentItem,
          this->_d->_modelSequence->componentItems())
  {
    qDebug()<<"comp-name: "<<componentItem->name();

    if(componentItem->name()=="env")
      this->_d->_mscScene->addEnvMscComponent(componentItem->name(),
                                              componentItem->uuid());
    else
      this->_d->_mscScene->addMscComponent(componentItem->name(),
                                           componentItem->uuid());

  }

  return true;
}

bool ComRenderMscSequence::dispatchSequenceItem(model::msc::MscSequenceItem const* sequItem,
                                                KMscSequence* sequence,
                                                QString* errorMessage)
{
  using namespace utils;

  Q_ASSERT(sequItem);

  bool result = true;
  if (sequItem->stepType() == model::msc::MessageStep)
  {
    result = this->addMessageItem(simple_cast<model::msc::MscMessageItem const*>(sequItem),
                                  sequence, this->_d->_arcOptions, errorMessage);
    if (!result)
      return false;
  }
  else if (sequItem->stepType() == model::msc::StatementStep)
  {
    result = this->addStatementItem(simple_cast<model::msc::MscStatementItem const*>(sequItem),
                                    sequence, this->_d->_arcOptions, errorMessage);
    if (!result)
      return false;
  }
  else if (sequItem->stepType() == model::msc::TimerStep)
  {
    result = this->addTimerItem(simple_cast<model::msc::MscTimerItem const*>(sequItem),
                                sequence, this->_d->_arcOptions, errorMessage);
    if (!result)
      return false;
  }
  else if (sequItem->stepType() == model::msc::SleepTimerStep)
  {
    result = this->addSleepTimerItem(simple_cast<model::msc::MscSleepTimerItem const*>(sequItem),
                                     sequence, this->_d->_arcOptions, errorMessage);
    if (!result)
      return false;
  }
  else if (sequItem->stepType() == model::msc::TimeoutStep)
  {
    result = this->addTimeoutItem(simple_cast<model::msc::MscTimeoutItem const*>(sequItem),
                                  sequence, this->_d->_arcOptions, errorMessage);
    if (!result)
      return false;
  }
  else if (sequItem->stepType() == model::msc::FragmentStep)
  {
    result = this->addFragmentItem(simple_cast<model::msc::MscFragmentItem const*>(sequItem),
                                   sequence, errorMessage);
    if (!result)
      return false;
  }
  else
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("Unknown sequence step, should not happen!");
    return false;
  }

  return true;
}

bool ComRenderMscSequence::addMessageItem(const model::msc::MscMessageItem* messageItem,
                                          KMscSequence* sequence,
                                          graph::ArcOptions const& arcOptions,
                                          QString* errorMessage)
{
  Q_ASSERT(messageItem);
  Q_ASSERT(this->_d->_mscScene);

  model::msc::MscComponentItem const* fromComponent=0;
  if(messageItem->sourcePort()
     && messageItem->sourcePort()->ownerType()==model::msc::PortItem::Component)
    fromComponent=utils::simple_cast<model::msc::MscComponentItem const*>(messageItem->sourcePort()->owner());
  if(!fromComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("source model-component of message '%1' "
                                 "not found!").arg(messageItem->toString());
    return false;
  }

  model::msc::MscComponentItem const* toComponent=0;
  if(messageItem->targetPort()
     && messageItem->targetPort()->ownerType()==model::msc::PortItem::Component)
    toComponent=utils::simple_cast<model::msc::MscComponentItem const*>(messageItem->targetPort()->owner());
  if(!toComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("target model-component of message '%1' "
                                 "not found!").arg(messageItem->toString());
    return false;
  }

  KMscComponent* fromViewComponent=this->_d->_mscScene->mscComponent(fromComponent->uuid());
  if(!fromViewComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("source view-component of message '%1' "
                                 "not found!").arg(messageItem->toString());
    return false;
  }

  KMscComponent* toViewComponent=this->_d->_mscScene->mscComponent(toComponent->uuid());
  if(!toViewComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("target view-component of message '%1' "
                                 "not found!").arg(messageItem->toString());
    return false;
  }

  KMscMessage* viewMessage=this->_d->_mscScene->addMessageStep(fromViewComponent,
                                                               toViewComponent,
                                                               messageItem->toString(true),
                                                               arcOptions,
                                                               sequence);
  if(!viewMessage)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("message '%1' could not be created!").arg(messageItem->toString());
    return false;
  }

  viewMessage->setReferenceId(messageItem->uuid());

  return true;
}

bool ComRenderMscSequence::addStatementItem(model::msc::MscStatementItem const* statementItem,
                                            KMscSequence* sequence,
                                            view::graph::ArcOptions const& arcOptions,
                                            QString* errorMessage)
{
  Q_ASSERT(statementItem);
  Q_ASSERT(this->_d->_mscScene);

  model::msc::MscComponentItem const* component=statementItem->component();
  if(!component)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("component of statement '%1' "
                                 "not found!").arg(statementItem->toString());
    return false;
  }

  KMscComponent* viewComponent=this->_d->_mscScene->mscComponent(component->uuid());
  if(!viewComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("view-component of statement '%1' "
                                 "not found!").arg(statementItem->toString());
    return false;
  }

  KMscStatement* viewStatement=this->_d->_mscScene->addStatementStep(statementItem->statement(),
                                                                     viewComponent,
                                                                     sequence,
                                                                     arcOptions,
                                                                     errorMessage);
  if(!viewStatement)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("statement '%1' could not be created!").arg(statementItem->toString());
    return false;
  }

  viewStatement->setReferenceId(statementItem->uuid());

  return true;
}

bool ComRenderMscSequence::addTimeoutItem(model::msc::MscTimeoutItem const* timeoutItem,
                                          KMscSequence* sequence,
                                          view::graph::ArcOptions const& arcOptions,
                                          QString* errorMessage)
{
  Q_ASSERT(timeoutItem);
  Q_ASSERT(this->_d->_mscScene);

  model::msc::MscComponentItem const* component=timeoutItem->component();
  if(!component)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("component of timeout '%1' "
                                 "not found!").arg(timeoutItem->toString());
    return false;
  }

  KMscComponent* viewComponent=this->_d->_mscScene->mscComponent(component->uuid());
  if(!viewComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("view-component of timeout '%1' "
                                 "not found!").arg(timeoutItem->toString());
    return false;
  }

  KMscTimeout* viewTimeout=this->_d->_mscScene->addTimeoutStep(timeoutItem->timer()->name(),
                                                               viewComponent,
                                                               sequence,
                                                               arcOptions,
                                                               errorMessage);
  if(!viewTimeout)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("timeout '%1' could not be created!").arg(timeoutItem->toString());
    return false;
  }

  viewTimeout->setReferenceId(timeoutItem->uuid());

  return true;
}

bool ComRenderMscSequence::addTimerItem(model::msc::MscTimerItem const* timerItem,
                                        KMscSequence* sequence,
                                        view::graph::ArcOptions const& arcOptions,
                                        QString* errorMessage)
{
  Q_ASSERT(timerItem);
  Q_ASSERT(this->_d->_mscScene);

  model::msc::MscComponentItem const* component=timerItem->component();
  if(!component)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("component of timer '%1' "
                                 "not found!").arg(timerItem->toString());
    return false;
  }

  KMscComponent* viewComponent=this->_d->_mscScene->mscComponent(component->uuid());
  if(!viewComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("view-component of timer '%1' "
                                 "not found!").arg(timerItem->toString());
    return false;
  }

  KMscTimer* viewTimer=this->_d->_mscScene->addTimerStep(timerItem->name(),
                                                         timerItem->value(),
                                                         viewComponent,
                                                         sequence,
                                                         arcOptions,
                                                         errorMessage);
  if(!viewTimer)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("timer '%1' could not be created!").arg(timerItem->toString());
    return false;
  }

  viewTimer->setReferenceId(timerItem->uuid());

  return true;
}

bool ComRenderMscSequence::addSleepTimerItem(model::msc::MscSleepTimerItem const* sleepTimerItem,
                                             KMscSequence* sequence,
                                             view::graph::ArcOptions const& arcOptions,
                                             QString* errorMessage)
{
  Q_ASSERT(sleepTimerItem);
  Q_ASSERT(this->_d->_mscScene);

  model::msc::MscComponentItem const* component=sleepTimerItem->component();
  if(!component)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("component of sleep timer '%1' "
                                 "not found!").arg(sleepTimerItem->toString());
    return false;
  }

  KMscComponent* viewComponent=this->_d->_mscScene->mscComponent(component->uuid());
  if(!viewComponent)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("view-component of sleep timer '%1' "
                                 "not found!").arg(sleepTimerItem->toString());
    return false;
  }

  KMscSleepTimer* viewSleepTimer=this->_d->_mscScene->addSleepTimerStep(sleepTimerItem->value(),
                                                                        viewComponent,
                                                                        sequence,
                                                                        arcOptions,
                                                                        errorMessage);
  if(!viewSleepTimer)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("sleep timer '%1' could not be created!").arg(sleepTimerItem->toString());
    return false;
  }

  viewSleepTimer->setReferenceId(sleepTimerItem->uuid());

  return true;
}

bool ComRenderMscSequence::addFragmentItem(model::msc::MscFragmentItem const* fragmentItem,
                                           KMscSequence* sequence,
                                           QString* errorMessage)
{
  Q_ASSERT(fragmentItem);
  Q_ASSERT(this->_d->_mscScene);

  KMscFragment* viewFragment=this->_d->_mscScene->addFragmentStep(fragmentItem->fragmentType(),
                                                                  sequence,
                                                                  errorMessage);
  if(!viewFragment)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("fragment '%1' could not be created!").arg(fragmentItem->toString());
    return false;
  }

  foreach(model::msc::MscFragmentRegionItem const* fragmentRegion, fragmentItem->regions())
  {
    KMscFragmentRegion* newFragmentRegion=viewFragment->addRegion(fragmentRegion->condition());
    if(!newFragmentRegion)
    {
      if(errorMessage)
        *errorMessage+=QObject::tr("fragment region '%1' could not be created!").arg(fragmentRegion->toString());
      return false;
    }

    foreach(model::msc::MscSequenceItem const* sequItem, fragmentRegion->sequenceItems())
    {
      if(!this->dispatchSequenceItem(sequItem, newFragmentRegion, errorMessage))
        return false;
    }
  }

  return true;
}

} // namespace msc
} // namespace view

