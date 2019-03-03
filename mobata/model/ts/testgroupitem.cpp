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

#include "testgroupitem.hpp"

#include "testcaseitem.hpp"
#include "testsystemitem.hpp"
#include "testsuite.hpp"

#include "../../utils/functors.hpp"

namespace model{
namespace ts{

class TestGroupItem::Private
{
  friend class TestGroupItem;

  Private(TestSuite const* testSuite)
    : _testSuite(testSuite),
      _testSystem(0)
  {}

public:
  ~Private()
  {}

private:
  TestSuite const*  _testSuite;
  TestSystemItem*   _testSystem;
};

TestGroupItem::TestGroupItem(TestSuite const* testSuite,
                             const QString& name)
  :	PropTestCases(this),
    prop::NameProperty(name),
    _d(new Private(testSuite))
{
  Q_ASSERT(testSuite);

  this->setIcon(QIcon(":images/sut/testsuite.png"));

  this->_d->_testSystem=new TestSystemItem(testSuite->sutItem(),
                                           name+QLatin1String("_testsystem"));
  this->appendRow(this->_d->_testSystem);
}

TestGroupItem::~TestGroupItem()
{
  delete this->_d;
}

void TestGroupItem::reset()
{
  PropTestCases::resetTestCases();

  if(this->_d->_testSystem)
    this->_d->_testSystem->reset();

  return;
}

TestSuite const* TestGroupItem::testSuite() const
{
  return this->_d->_testSuite;
}

QString TestGroupItem::toString() const
{
  return this->name();
}

}///end namespace ts
}///end namespace model
