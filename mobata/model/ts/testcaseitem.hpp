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
#pragma once

#include "ts_types.hpp"

#include "../msc/mscsequence.hpp"
#include "../msc/mscpropcoverages.hpp"
#include "../base/propattributes.hpp"
#include "../base/propsignals.hpp"
#include "../base/propdatatypes.hpp"

namespace model{
namespace ts{

class TestCaseItem
    : public msc::MscSequence,
    public base::PropDataTypes,
    public base::PropAttributes,
    public base::PropSignals
{
public:
  TestCaseItem(const QString& name=QStringLiteral("test case"));
  virtual ~TestCaseItem();

public:
  virtual void          reset() override;
  virtual TestCaseItem* clone() const override;
  TestSuite const*      testSuite() const;
  void                  addContent(base::BaseModel *model,QString* errorString);

public:
  QList<model::msc::MscCoverageItem>  coverageItems() const;
  int                                 calcTestStepsCount() const;

private:
  Q_DISABLE_COPY(TestCaseItem)
  class Private;
  Private*  _d;
};

typedef QSharedPointer<TestCaseItem> TestCaseItemPtr;

}///end namespace ts
}/// end namespace model

