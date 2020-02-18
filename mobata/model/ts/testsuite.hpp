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

#include "../../mobata_global.hpp"

#include "ts_types.hpp"

#include "../base/basemodel.hpp"
#include "../base/propattributes.hpp"
#include "propttestcases.hpp"

namespace model{
namespace ts{

class MOBATASHARED_EXPORT TestSuite
    : public base::BaseModel,
    public PropTestCases
{
public:
  typedef QList<TestGroupItem*>       TestGroupSet;
  typedef QList<TestGroupItem const*> ConstTestGroupSet;

public:
  explicit TestSuite(QObject *parent = 0);
  virtual ~TestSuite();

public:
  virtual void reset();

public:
  SutItem*              sutItem();
  SutItem const*        sutItem() const;
  TestSystemItem*       testSystemItem();
  TestSystemItem const* testSystemItem() const;
  TestGroupItem*        addTestGroup(const QString& name,
                                     QString* errorMessage);
  TestGroupItem*        testGroup(const QString& name);
  TestGroupItem const*  testGroup(const QString& name) const;
  TestGroupSet          testGroups();
  ConstTestGroupSet     testGroups() const;
  
  PortItem const*       port(const QUuid& portUuid) const;

private:
  Q_DISABLE_COPY(TestSuite)
  class Private;
  Private*	_d;
};

typedef QSharedPointer<TestSuite> TsModelPtr;

}///end namespace ts
}///end namespace model
