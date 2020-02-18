/*
 * This file is part of mobata.
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
#ifndef VIEW_MSC_MSCSCENE_HPP
#define VIEW_MSC_MSCSCENE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../graph/graphscene.hpp"

#include "../graph/types.hpp"

namespace view{
namespace msc{

class MOBATAWIDGETSSHARED_EXPORT KMscScene
    : public graph::GraphScene
{
  Q_OBJECT

public:
  typedef QVector<KMscComponent*> MscComponents;

public:
  KMscScene(QObject *parent = 0);
  virtual ~KMscScene();

private:
  void addRootSequence();

public:
  virtual void reset();

public:
  KMscComponent*  addEnvMscComponent(const QString& name,
                                     const QUuid& referenceId);
  KMscComponent*  addMscComponent(const QString& name,
                                  const QUuid& referenceId);
  KMscMessage*    addMessageStep(KMscComponent *from,
                                 KMscComponent *to,
                                 const QString &messageText,
                                 const view::graph::ArcOptions &arcOptions,
                                 KMscSequence* parentSequence=0);
  KMscStatement*  addStatementStep(const QString& statement,
                                   KMscComponent* component,
                                   KMscSequence* parentSequence,
                                   const view::graph::ArcOptions &arcOptions,
                                   QString* errorMessage);
  KMscTimeout*    addTimeoutStep(const QString& timerName,
                                 KMscComponent* component,
                                 KMscSequence* parentSequence,
                                 const view::graph::ArcOptions &arcOptions,
                                 QString* errorMessage);
  KMscTimer*      addTimerStep(const QString& timerName,
                               const double duration,
                               KMscComponent* component,
                               KMscSequence* parentSequence,
                               const view::graph::ArcOptions &arcOptions,
                               QString* errorMessage);
  KMscSleepTimer* addSleepTimerStep(double duration,
                                    KMscComponent* component,
                                    KMscSequence* parentSequence,
                                    const view::graph::ArcOptions& arcOptions,
                                    QString* errorMessage);
  KMscFragment*   addFragmentStep(const int fragmentType,
                                  KMscSequence* parentSequence,
                                  QString* errorMessage);

public:
  const SequenceSteps&  sequenceSteps() const;
  const MscComponents&  mscComponents() const;
  KMscComponent*        mscComponent(const QUuid& referenceId);

public:
  virtual void render();

protected:
  void          addMscComponent(KMscComponent* mscComponent);
  KMscSequence* rootSequence();

private:
  void  syncComponentHeights();

private:
  Q_DISABLE_COPY(KMscScene)
  class Private;
  Private*  _d;
};

}//////end namespace msc
}/// end namespace view

#endif
