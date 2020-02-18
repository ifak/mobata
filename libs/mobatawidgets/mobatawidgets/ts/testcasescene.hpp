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
#ifndef VIEW_TS_TESTCASESCENE_HPP
#define VIEW_TS_TESTCASESCENE_HPP

#include "../mobatawidgets_global.hpp"

#include "../msc/mscscene.hpp"

#include "types.hpp"

namespace view {
namespace ts {

class MscSutComponent;
class MscTestComponent;
class MscTestResult;

class MOBATAWIDGETSSHARED_EXPORT TestCaseScene
    : public msc::KMscScene
{
  Q_OBJECT

public:
  TestCaseScene(QObject *parent = 0);
  virtual ~TestCaseScene();

public:
  MscSutComponent*   addSutComponent(const QString& name,
                                     const QUuid& referenceId,
                                     const view::graph::NodeOptions& compOptions,
                                     const QColor& lifeLineColor,
                                     const qreal lifeLineWidth);
  MscTestComponent*  addTestComponent(const QString& name,
                                      const QUuid& referenceId,
                                      const view::graph::NodeOptions& compOptions,
                                      const QColor& lifeLineColor,
                                      const qreal lifeLineWidth);

public:
  QList<MscSutComponent*>   sutComponents() const;
  MscSutComponent*          sutComponent(const QUuid& referenceId);
  QList<MscTestComponent*>  testComponents() const;
  MscTestComponent*         testComponent(const QUuid& referenceId);

public:
  MscTestResult*  addTestResultStep(const TestResultValue testResultValue,
                                    MscTestComponent* mscTestcomponent,
                                    msc::KMscSequence* parentSequence,
                                    QString* errorMessage);

private:
  Q_DISABLE_COPY(TestCaseScene)
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_TESTCASESCENE_HPP
