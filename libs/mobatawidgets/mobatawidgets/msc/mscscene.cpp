#include "mscscene.hpp"

#include "msccomponent.hpp"
#include "mscenvcomponent.hpp"
#include "mscsequence.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class KMscScene::Private
{
  friend class KMscScene;

  KMscSequence* _rootSequence;
  qreal         _stepMarginSpace;
  qreal         _compMarginSpace;
  MscComponents _mscComponents;

  Private()
    : _rootSequence(0),
      _stepMarginSpace(5),
      _compMarginSpace(50)
  {}
  ~Private()
  {}
};

KMscScene::KMscScene(QObject *parent)
  : graph::GraphScene(parent),
    _d(new Private)
{
  this->addRootSequence();
}

KMscScene::~KMscScene()
{
  delete this->_d;
}

void KMscScene::addRootSequence()
{
  this->_d->_rootSequence=new KMscSequence();
  this->_d->_rootSequence->setPen(QPen(Qt::NoPen));
  this->_d->_rootSequence->setZValue(100);
  this->addItem(this->_d->_rootSequence);
}

void KMscScene::reset()
{
  this->_d->_mscComponents.clear();
  this->clear();

  this->addRootSequence();
}

const KMscScene::MscComponents& KMscScene::mscComponents() const
{
  return this->_d->_mscComponents;
}

KMscSequence* KMscScene::rootSequence()
{
  return this->_d->_rootSequence;
}

void KMscScene::syncComponentHeights()
{
  ////sync heights of the lifeline of all msc-objects
  qreal syncHeight=0;
  foreach(KMscComponent const* component, this->_d->_mscComponents)
    syncHeight=std::max(syncHeight, component->lifelineEndSceneY());

  foreach(KMscComponent* component, this->_d->_mscComponents)
    component->setLifelineEndSceneY(syncHeight);

  return;
}

KMscComponent* KMscScene::addEnvMscComponent(const QString& name,
                                             const QUuid& referenceId)
{
  KMscComponent* mscComponent=this->mscComponent(referenceId);
  if(!mscComponent)
  {
    mscComponent=new KMscEnvComponent(name, referenceId);
    this->addMscComponent(mscComponent);
  }

  return mscComponent;
}

KMscComponent* KMscScene::addMscComponent(const QString& name,
                                          const QUuid& referenceId)
{
  KMscComponent* mscComponent=this->mscComponent(referenceId);
  if(!mscComponent)
  {
    mscComponent=new KMscComponent(name, referenceId);
    this->addMscComponent(mscComponent);
  }

  return mscComponent;
}

void KMscScene::addMscComponent(KMscComponent* mscComponent)
{
  if(!mscComponent)
    return;

  this->addItem(mscComponent);

  qreal lastCompMarginX=0;
  if(this->_d->_mscComponents.size())
  {
    KMscComponent* lastAddedComponent=this->_d->_mscComponents.last();
    Q_ASSERT(lastAddedComponent);
    QRectF lastAddedComponentRect=lastAddedComponent->rect();
    lastCompMarginX=lastAddedComponent->pos().x()
                    + std::abs(lastAddedComponentRect.width())/2;
    QRectF mscCompRect=mscComponent->rect();
    mscComponent->setPos(lastCompMarginX
                         + this->_d->_compMarginSpace
                         + std::abs(mscCompRect.width())/2,
                         std::abs(mscCompRect.height())/2);
  }
  else
  {
    QRectF mscCompRect=mscComponent->rect();
    mscComponent->setPos(std::abs(mscCompRect.width())/2,
                         std::abs(mscCompRect.height())/2);
  }

  this->_d->_mscComponents.append(mscComponent);

  return;
}

KMscComponent* KMscScene::mscComponent(const QUuid& referenceId)
{
  foreach(KMscComponent* mscComponent, this->_d->_mscComponents)
  {
    if(mscComponent->referenceId()==referenceId)
      return mscComponent;
  }

  return 0;
}

void KMscScene::render()
{
  qreal bottomSceneY=0;
  foreach(KMscComponent const* component, this->_d->_mscComponents)
    bottomSceneY=std::max(bottomSceneY, component->rect().height());

  bottomSceneY=this->_d->_rootSequence->updateGeometry(bottomSceneY,
                                                       this->_d->_stepMarginSpace);
  this->syncComponentHeights();

  return;
}

KMscMessage* KMscScene::addMessageStep(KMscComponent *from,
                                       KMscComponent *to,
                                       const QString &messageText,
                                       const graph::ArcOptions &arcOptions,
                                       KMscSequence* parentSequence)
{
  Q_ASSERT(from);
  Q_ASSERT(to);

  KMscSequence* messageParent=parentSequence;
  if(!messageParent)
    messageParent=this->_d->_rootSequence;
  Q_ASSERT(messageParent);

  return messageParent->addMessageStep(from, to, messageText, arcOptions);
}

KMscStatement* KMscScene::addStatementStep(const QString& statement,
                                           KMscComponent* component,
                                           KMscSequence* parentSequence,
                                           const view::graph::ArcOptions &arcOptions,
                                           QString* errorMessage)
{
  KMscSequence* messageParent=parentSequence;
  if(!messageParent)
    messageParent=this->_d->_rootSequence;
  Q_ASSERT(messageParent);

  return messageParent->addStatementStep(statement, component, arcOptions, errorMessage);
}

KMscTimeout* KMscScene::addTimeoutStep(const QString& timerName,
                                       KMscComponent* component,
                                       KMscSequence* parentSequence,
                                       const view::graph::ArcOptions &arcOptions,
                                       QString* errorMessage)
{
  KMscSequence* messageParent=parentSequence;
  if(!messageParent)
    messageParent=this->_d->_rootSequence;
  Q_ASSERT(messageParent);

  return messageParent->addTimeoutStep(timerName, component, arcOptions, errorMessage);
}

KMscTimer*   KMscScene::addTimerStep(const QString& timerName,
                                     const double duration,
                                     KMscComponent* component,
                                     KMscSequence* parentSequence,
                                     const view::graph::ArcOptions &arcOptions,
                                     QString* errorMessage)
{
  KMscSequence* messageParent=parentSequence;
  if(!messageParent)
    messageParent=this->_d->_rootSequence;
  Q_ASSERT(messageParent);

  return messageParent->addTimerStep(timerName, duration, component, arcOptions, errorMessage);
}

KMscSleepTimer* KMscScene::addSleepTimerStep(double duration,
                                             KMscComponent* component,
                                             KMscSequence* parentSequence,
                                             const view::graph::ArcOptions &arcOptions,
                                             QString* errorMessage)
{
  KMscSequence* messageParent=parentSequence;
  if(!messageParent)
    messageParent=this->_d->_rootSequence;
  Q_ASSERT(messageParent);

  return messageParent->addSleepTimerStep(duration, component, arcOptions, errorMessage);
}

KMscFragment* KMscScene::addFragmentStep(const int fragmentType,
                                         KMscSequence* parentSequence,
                                         QString* errorMessage)
{
  KMscSequence* messageParent=parentSequence;
  if(!messageParent)
    messageParent=this->_d->_rootSequence;

  return messageParent->addFragmentStep(fragmentType, errorMessage);
}

const SequenceSteps& KMscScene::sequenceSteps() const
{
  Q_ASSERT(this->_d->_rootSequence);

  return this->_d->_rootSequence->sequenceSteps();
}

}//////end namespace msc
}/////end namespace view
