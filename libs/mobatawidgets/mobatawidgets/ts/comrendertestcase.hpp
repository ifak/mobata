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
#ifndef VIEW_TS_COMRENDERTESTCASE_HPP
#define VIEW_TS_COMRENDERTESTCASE_HPP

#include "../mobatawidgets_global.hpp"

#include "../msc/comrendermscsequence.hpp"

#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/ts/testcaseitem.hpp>

#include "testcasescene.hpp"

namespace view {

namespace msc{class KMscSequence;}

namespace ts {

class MOBATAWIDGETSSHARED_EXPORT ComRenderTestCase
    : public msc::ComRenderMscSequence
{
public:
  ComRenderTestCase(TestCaseScene* testCaseScene,
                    model::ts::TestCaseItem const* modelTestCase,
                    const view::graph::NodeOptions& sutCompOptions = defaultSutCompOptions(),
                    const QColor& sutLifeLineColor = defaultSutLifeLineColor(),
                    const qreal sutLifeLineWidth = defaultSutLifeLineWidth(),
                    const view::graph::NodeOptions& testCompOptions = defaultTestCompOptions(),
                    const QColor& testLifeLineColor = defaultTestLifeLineColor(),
                    const qreal testLifeLineWidth = defaultTestLifeLineWidth(),
                    const view::graph::ArcOptions arcOptions = defaultArcOptions());
  virtual ~ComRenderTestCase();

protected:
  virtual TestCaseScene*                  viewScene();
  virtual model::ts::TestCaseItem const*  modelSequence() const;

public:
  virtual bool execute(QString* errorMessage);

protected:
  virtual bool addComponents(QString* errorMessage);
  virtual bool dispatchSequenceItem(model::msc::MscSequenceItem const* sequItem,
                                    msc::KMscSequence* sequence,
                                    QString* errorMessage);

public:
  static view::graph::NodeOptions defaultSutCompOptions()
  {
    return view::graph::NodeOptions()
        .setSize(QSizeF(100,50))
        .setColor(Qt::white)
        .setPen(QPen(Qt::black, 3));
  }

  static QColor defaultSutLifeLineColor()
  {
    return QColor(Qt::black);
  }

  static qreal defaultSutLifeLineWidth()
  {
    return 3;
  }

  static view::graph::NodeOptions defaultTestCompOptions()
  {
    return view::graph::NodeOptions()
        .setSize(QSizeF(100,50))
        .setColor(Qt::white)
        .setPen(QPen(Qt::darkRed, 3));
  }

  static QColor defaultTestLifeLineColor()
  {
    return QColor(Qt::darkRed);
  }

  static qreal defaultTestLifeLineWidth()
  {
    return 3;
  }

  static view::graph::ArcOptions defaultArcOptions()
  {
    return view::graph::ArcOptions().setPen(QPen(Qt::darkBlue, 3));
  }

private:
  bool addTestResultItem(model::ts::TestResultItem const* testResult,
                         msc::KMscSequence* sequence,
                         QString* errorMessage);

private:
  Q_DISABLE_COPY(ComRenderTestCase)
  class Private;
  Private* _d;
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_COMRENDERTESTCASE_HPP
