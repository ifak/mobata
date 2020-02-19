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
#ifndef VIEW_MSC_COMRENDERMSCSEQUENCE_HPP
#define VIEW_MSC_COMRENDERMSCSEQUENCE_HPP

#include "../mobatawidgets_global.hpp"

#include <QString>

#include <mobata/model/msc/msc_types.hpp>

#include "../graph/types.hpp"

namespace view {
namespace msc {

class KMscScene;
class KMscSequence;

class MOBATAWIDGETSSHARED_EXPORT ComRenderMscSequence
{
public:
  ComRenderMscSequence(KMscScene* mscScene,
                       model::msc::MscSequence const* modelSequence,
                       view::graph::ArcOptions const& arcOptions = defaultArcOptions());
  virtual ~ComRenderMscSequence();

protected:
  virtual KMscScene*                      viewScene();
  virtual model::msc::MscSequence const*  modelSequence() const;

public:
  virtual bool execute(QString* errorMessage);

protected:
  virtual bool addComponents(QString* errorMessage);
  virtual bool dispatchSequenceItem(model::msc::MscSequenceItem const* sequItem,
                                    KMscSequence* sequence,
                                    QString* errorMessage);

private:
  bool addMessageItem(model::msc::MscMessageItem const* message,
                      KMscSequence* sequence,
                      view::graph::ArcOptions const& arcOptions,
                      QString* errorMessage);
  bool addStatementItem(model::msc::MscStatementItem const* statementItem,
                        KMscSequence* sequence,
                        view::graph::ArcOptions const& arcOptions,
                        QString* errorMessage);
  bool addTimeoutItem(model::msc::MscTimeoutItem const* timeoutItem,
                      KMscSequence* sequence,
                      view::graph::ArcOptions const& arcOptions,
                      QString* errorMessage);
  bool addTimerItem(model::msc::MscTimerItem const* timerItem,
                    KMscSequence* sequence,
                    view::graph::ArcOptions const& arcOptions,
                    QString* errorMessage);
  bool addSleepTimerItem(model::msc::MscSleepTimerItem const* sleepTimerItem,
                         KMscSequence* sequence,
                         view::graph::ArcOptions const& arcOptions,
                         QString* errorMessage);
  bool addFragmentItem(model::msc::MscFragmentItem const* fragmentItem,
                       KMscSequence* sequence,
                       QString* errorMessage);

public:
  static view::graph::ArcOptions defaultArcOptions()
  {
      return view::graph::ArcOptions().setPen(QPen(Qt::darkBlue, 3));
  }

private:
  Q_DISABLE_COPY(ComRenderMscSequence)
  class Private;
  Private* _d;
};

} // namespace msc
} // namespace view

#endif // VIEW_MSC_COMRENDERMSCSEQUENCE_HPP
