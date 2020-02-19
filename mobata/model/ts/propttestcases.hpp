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

#include <QList>

class QUuid;
class QStandardItem;


namespace model {
namespace ts {

class PropTestCases
{
public:
  typedef QList<TestCaseItem*>       TestCaseSet;
  typedef QList<TestCaseItem const*> ConstTestCaseSet;

public:
  PropTestCases(QStandardItem* parentItem);
  virtual ~PropTestCases();

public:
  TestCaseItem* testCase(const QUuid& testCaseUuid) const;
  TestCaseSet   testCases() const;

public:
  bool          addTestCase(TestCaseItem* testCase,
                            QString* errorString=0);
  TestCaseItem* addTestCase(const QString& name);

  void removeTestCase(TestCaseItem* testCase);
  void removeTestCase(const QUuid& testCaseId);

protected:
  void  resetTestCases();
  void  setTestCasesParentItem(QStandardItem* parent);

private:
  Q_DISABLE_COPY(PropTestCases)
  class Private;
  Private*  _d;
};

} // namespace ts
} // namespace model
