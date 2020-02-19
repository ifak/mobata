#include "mscsequence.hpp"

#include "mscmessage.hpp"
#include "mscfragment.hpp"
#include "mscfragmentregion.hpp"
#include "msccomponent.hpp"
#include "msccomponentlifeline.hpp"
#include "mscsequencestep.hpp"
#include "mscstatement.hpp"
#include "mscsleeptimer.hpp"
#include "msctimer.hpp"
#include "msctimeout.hpp"
#include "mscanchor.hpp"
#include "mscscene.hpp"

#include <QPen>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace msc{

class KMscSequence::Private
{
  friend class KMscSequence;

  QVector<MscSequenceStep*>     _sequSteps;
  KMscSequence::ComponentLines  _componentLines;
};

KMscSequence::KMscSequence(KMscFragment * parent)
  : QGraphicsRectItem(parent),
    _d(new Private)
{
  this->setPen(QPen(Qt::NoPen));
}

KMscSequence::~KMscSequence()
{
  delete this->_d;
}

const SequenceSteps& KMscSequence::sequenceSteps() const
{
  return this->_d->_sequSteps;
}

KMscScene*KMscSequence::mscScene()
{
  KMscScene* mscScene=utils::simple_cast<KMscScene*>(this->scene());
  Q_ASSERT(mscScene);

  return mscScene;
}

qreal KMscSequence::updateGeometry(const qreal bottomSceneY,
                                   const qreal marginSpace)
{
  qreal currentBottomSceneY=bottomSceneY;

  foreach (MscSequenceStep* sequStep, this->_d->_sequSteps)
    currentBottomSceneY=sequStep->updateGeometry(currentBottomSceneY,
                                                 marginSpace);
  QRectF childrenRect=this->childrenBoundingRect();
  childrenRect.setTop(bottomSceneY);
  this->setRect(childrenRect);

  return currentBottomSceneY;
}

const KMscSequence::ComponentLines& KMscSequence::componentLines() const
{
  return this->_d->_componentLines;
}

KMscMessage* KMscSequence::addMessageStep(KMscComponent *from,
                                          KMscComponent *to,
                                          const QString &messageText,
                                          const view::graph::ArcOptions &arcOptions)
{
  Q_ASSERT(from);
  Q_ASSERT(to);

  KMscAnchor* sourceMessageAnchor=from->addAnchor();
  Q_ASSERT(sourceMessageAnchor);
  Q_ASSERT(sourceMessageAnchor->mscComponent());

  ///source - component-lifeline-redraw///////
  if(!this->_d->_componentLines.contains(sourceMessageAnchor->mscComponent()))
  {
    QGraphicsPathItem* sourceCompLifeline=new QGraphicsPathItem(this);
    this->_d->_componentLines.insert(sourceMessageAnchor->mscComponent(),
                                     sourceCompLifeline);
  }

  KMscAnchor* targetMessageAnchor=to->addAnchor();
  Q_ASSERT(targetMessageAnchor);
  Q_ASSERT(targetMessageAnchor->mscComponent());

  ///target - component-lifeline-redraw///////
  if(!this->_d->_componentLines.contains(targetMessageAnchor->mscComponent()))
  {
    QGraphicsPathItem* targetCompLifeline=new QGraphicsPathItem(this);
    this->_d->_componentLines.insert(targetMessageAnchor->mscComponent(),
                                     targetCompLifeline);
  }

  KMscMessage* newMscMessage=new KMscMessage(sourceMessageAnchor,
                                             targetMessageAnchor,
                                             messageText,
                                             arcOptions,
                                             this);
  this->_d->_sequSteps.append(newMscMessage);

  return newMscMessage;
}

KMscStatement* KMscSequence::addStatementStep(const QString& statement,
                                              KMscComponent* component,
                                              const view::graph::ArcOptions& arcOptions,
                                              QString* errorMessage)
{
  Q_UNUSED(statement);
  Q_ASSERT(component);
  Q_UNUSED(errorMessage);

  ///component-lifeline-redraw///////
  if(!this->_d->_componentLines.contains(component))
  {
    QGraphicsPathItem* compLifeline=new QGraphicsPathItem(this);
    this->_d->_componentLines.insert(component,
                                     compLifeline);
  }

  KMscStatement* newMscStatement=new KMscStatement(statement,
                                                   component,
                                                   arcOptions,
                                                   this);
  this->_d->_sequSteps.append(newMscStatement);

  return newMscStatement;
}

KMscTimeout* KMscSequence::addTimeoutStep(const QString& timerName,
                                          KMscComponent* component,
                                          const view::graph::ArcOptions& arcOptions,
                                          QString* errorMessage)
{
  Q_UNUSED(timerName);
  Q_ASSERT(component);
  Q_UNUSED(errorMessage);

  ///component-lifeline-redraw///////
  if(!this->_d->_componentLines.contains(component))
  {
    QGraphicsPathItem* compLifeline=new QGraphicsPathItem(this);
    this->_d->_componentLines.insert(component,
                                     compLifeline);
  }

  KMscAnchor* sourceMessageAnchor=component->addAnchor();
  Q_ASSERT(sourceMessageAnchor);

  KMscAnchor* targetMessageAnchor=component->addAnchor();
  Q_ASSERT(targetMessageAnchor);

  KMscTimeout* newTimeout=new KMscTimeout(sourceMessageAnchor,
                                          targetMessageAnchor,
                                          timerName,
                                          arcOptions,
                                          this);
  this->_d->_sequSteps.append(newTimeout);

  return newTimeout;
}

KMscTimer*   KMscSequence::addTimerStep(const QString& timerName,
                                        const double duration,
                                        KMscComponent* component,
                                        const view::graph::ArcOptions& arcOptions,
                                        QString* errorMessage)
{
  Q_UNUSED(timerName);
  Q_ASSERT(component);
  Q_UNUSED(errorMessage);

  ///component-lifeline-redraw///////
  if(!this->_d->_componentLines.contains(component))
  {
    QGraphicsPathItem* compLifeline=new QGraphicsPathItem(this);
    this->_d->_componentLines.insert(component,
                                     compLifeline);
  }

  KMscAnchor* sourceMessageAnchor=component->addAnchor();
  Q_ASSERT(sourceMessageAnchor);

  KMscAnchor* targetMessageAnchor=component->addAnchor();
  Q_ASSERT(targetMessageAnchor);

  KMscTimer* newTimer=new KMscTimer(sourceMessageAnchor,
                                    targetMessageAnchor,
                                    timerName,
                                    duration,
                                    arcOptions,
                                    this);
  this->_d->_sequSteps.append(newTimer);

  return newTimer;
}

KMscSleepTimer* KMscSequence::addSleepTimerStep(double duration,
                                                KMscComponent* component,
                                                const view::graph::ArcOptions& arcOptions,
                                                QString* errorMessage)
{
  Q_UNUSED(duration);
  Q_ASSERT(component);
  Q_UNUSED(errorMessage);

  ///component-lifeline-redraw///////
  if(!this->_d->_componentLines.contains(component))
  {
    QGraphicsPathItem* compLifeline=new QGraphicsPathItem(this);
    this->_d->_componentLines.insert(component,
                                     compLifeline);
  }

  KMscAnchor* sourceMessageAnchor=component->addAnchor();
  Q_ASSERT(sourceMessageAnchor);

  KMscAnchor* targetMessageAnchor=component->addAnchor();
  Q_ASSERT(targetMessageAnchor);

  KMscSleepTimer* newSleepTimer=new KMscSleepTimer(sourceMessageAnchor,
                                                   targetMessageAnchor,
                                                   duration,
                                                   arcOptions,
                                                   this);
  this->_d->_sequSteps.append(newSleepTimer);

  return newSleepTimer;
}

KMscFragment* KMscSequence::addFragmentStep(const int fragmentType,
                                            QString* errorMessage)
{
  Q_UNUSED(errorMessage);

  KMscFragment* newMscFragment=new KMscFragment(fragmentType, this);
  this->_d->_sequSteps.append(newMscFragment);

  return newMscFragment;
}

void KMscSequence::addStatementStep(KMscStatement* statement)
{
  Q_ASSERT(statement);

  ///component-lifeline-redraw///////
  if(!this->_d->_componentLines.contains(statement->mscComponent()))
  {
    QGraphicsPathItem* compLifeline=new QGraphicsPathItem(this);
    this->_d->_componentLines.insert(statement->mscComponent(),
                                     compLifeline);
  }

  this->_d->_sequSteps.append(statement);

  return;
}

}//////end namespace msc
}//////end namespace view
