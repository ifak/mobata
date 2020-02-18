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
#ifndef VIEW_MSC_MSCSEQUENCE_HPP
#define VIEW_MSC_MSCSEQUENCE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include <QGraphicsRectItem>

#include "../graph/types.hpp"

namespace view{
namespace msc{

class KMscMessage;
class KMscFragment;
class KMscScene;
class MscSequenceStep;

class MOBATAWIDGETSSHARED_EXPORT KMscSequence
    : public QGraphicsRectItem
{
public:
  typedef QMap< KMscComponent const*,
  QGraphicsPathItem*> ComponentLines;

public:
  KMscSequence(KMscFragment* parent=0);
  virtual ~KMscSequence();

public:
  const SequenceSteps&  sequenceSteps() const;
  KMscMessage*    addMessageStep(KMscComponent *from,
                                 KMscComponent *to,
                                 const QString &messageText,
                                 const view::graph::ArcOptions &arcOptions);
  KMscStatement*  addStatementStep(const QString& statement,
                                   KMscComponent* component,
                                   const view::graph::ArcOptions& arcOptions,
                                   QString* errorMessage);
  void            addStatementStep(KMscStatement* statement);
  KMscTimeout*    addTimeoutStep(const QString& timerName,
                                 KMscComponent* component,
                                 const view::graph::ArcOptions& arcOptions,
                                 QString* errorMessage);
  KMscTimer*      addTimerStep(const QString& timerName,
                               const double duration,
                               KMscComponent* component,
                               const view::graph::ArcOptions& arcOptions,
                               QString* errorMessage);
  KMscSleepTimer* addSleepTimerStep(double duration,
                                    KMscComponent* component,
                                    const view::graph::ArcOptions& arcOptions,
                                    QString* errorMessage);
  KMscFragment*   addFragmentStep(const int fragmentType,
                                  QString* errorMessage);

public:
  virtual qreal         updateGeometry(const qreal bottomSceneY,
                                       const qreal marginSpace);

protected:
  const ComponentLines& componentLines() const;

private:
  KMscScene*  mscScene();

private:
  Q_DISABLE_COPY(KMscSequence)
  class Private;
  Private* _d;
};

}//////end namespace msc
}/// end namespace view

#endif // VIEW_MSC_MSCSEQUENCE_HPP
