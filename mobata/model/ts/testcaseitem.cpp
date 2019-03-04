/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "testcaseitem.hpp"
#include "testsystemitem.hpp"
#include "sutitem.hpp"

#include "testgroupitem.hpp"
#include "testsuite.hpp"

#include "../msc/mscstepitem.hpp"

namespace model{
namespace ts{

class TestCaseItem::Private
{
  friend class TestCaseItem;
};

TestCaseItem::TestCaseItem(const QString& name)
  : msc::MscSequence(name),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    _d(new Private())
{
  this->setText(this->toString());
}

TestCaseItem::~TestCaseItem()
{
  delete this->_d;
}

void TestCaseItem::reset()
{
  this->resetAttributes();
  this->resetSignals();

  msc::MscSequence::reset();

  return;
}

TestCaseItem* TestCaseItem::clone() const
{
  TestCaseItem* cloneTestCaseItem = new TestCaseItem();

  this->cloneDataTypes(cloneTestCaseItem);
  this->cloneAttributes(cloneTestCaseItem);
  this->cloneSignals(cloneTestCaseItem);
//  this->cloneMscSequence(cloneTestCaseItem);

  return cloneTestCaseItem;
}

TestSuite const* TestCaseItem::testSuite() const
{
  return utils::simple_cast<TestSuite const*>(this->model());
}

QList<msc::MscCoverageItem> TestCaseItem::coverageItems() const
{
  QList<msc::MscCoverageItem> coverageItems;

  for(msc::MscSequenceItem const* sequenceItem
      : this->sequenceItems())
  {
    if(msc::MscStepItem const* stepItem=dynamic_cast<msc::MscStepItem const*>(sequenceItem))
    {
      for(const msc::MscCoverageItem& stepCoverageItem : stepItem->coverageItems())
        coverageItems.append(stepCoverageItem);
    }
  }

  return coverageItems;
}

int TestCaseItem::calcTestStepsCount() const
{
  int testStepsCount=0;

  for(msc::MscSequenceItem const* sequenceItem
      : this->sequenceItems())
  {
    int stepType = sequenceItem->stepType();

    if(stepType==msc::MessageStep
       || stepType==msc::CheckMessageStep
       || stepType==msc::TimeoutStep)
      ++testStepsCount;
  }

  return testStepsCount;
}

}/// end namespace ts
}/// end namespace model
