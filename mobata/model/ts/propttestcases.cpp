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

#include "propttestcases.hpp"

#include "testcaseitem.hpp"

#include "../../utils/functors.hpp"

namespace model {
namespace ts {

class PropTestCases::Private
{
  friend class PropTestCases;

  Private()
    : _testCasesItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _testCasesItem;
};

PropTestCases::PropTestCases(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setTestCasesParentItem(parentItem);
}

PropTestCases::~PropTestCases()
{
  delete this->_d;
}

void PropTestCases::setTestCasesParentItem(QStandardItem* parent)
{
  Q_ASSERT(parent);

  if(this->_d->_testCasesItem)
    return;

  this->_d->_testCasesItem=new QStandardItem(QIcon(":mobata/images/ts/manytestcase.png"),
                                             QLatin1String("test cases"));
  this->_d->_testCasesItem->setFlags(this->_d->_testCasesItem->flags() & ~Qt::ItemIsEditable);
  parent->appendRow(this->_d->_testCasesItem);

  return;
}

void PropTestCases::resetTestCases()
{
  if(this->_d->_testCasesItem)
    this->_d->_testCasesItem->removeRows(0,
                                         this->_d->_testCasesItem->rowCount());
  this->_d->_testCasesItem->setText(QLatin1String("test cases"));

  return;
}

bool PropTestCases::addTestCase(TestCaseItem* testCase,
                                QString* errorString)
{
  if(!testCase)
    return false;

  if(this->testCase(testCase->uuid()))
  {
    utils::AddPtrString(errorString)<<QObject::tr("There is already a test case "
                                                  "with uuid'%1' available!")
                                      .arg(testCase->uuid().toString());
    return false;
  }

  this->_d->_testCasesItem->appendRow(testCase);
  this->_d->_testCasesItem->setText(QString(QLatin1String("%1")).arg(this->_d->_testCasesItem->rowCount())
                                    +QLatin1String(" test cases"));
  testCase->setText(testCase->name());

  return true;
}

TestCaseItem* PropTestCases::addTestCase(const QString& name)
{
  TestCaseItem* newTestCase=new TestCaseItem(name);
  this->_d->_testCasesItem->appendRow(newTestCase);
  this->_d->_testCasesItem->setText(QString(QLatin1String("%1")).arg(this->_d->_testCasesItem->rowCount())
                                    +QLatin1String(" test cases"));
  newTestCase->setText(newTestCase->name());

  return newTestCase;
}

void PropTestCases::removeTestCase(TestCaseItem* testCase)
{
  if(!testCase)
    return;
  Q_ASSERT(this->_d->_testCasesItem->model()==testCase->model());

  this->_d->_testCasesItem->removeRow(testCase->row());
  this->_d->_testCasesItem->setText(QString(QLatin1String("%1")).arg(this->_d->_testCasesItem->rowCount())
                                    +QLatin1String(" test cases"));

  return;
}

void PropTestCases::removeTestCase(const QUuid& testCaseId)
{
  TestCaseItem* testCase=this->testCase(testCaseId);
  if(!testCase)
    return;

  this->_d->_testCasesItem->removeRow(testCase->row());
  this->_d->_testCasesItem->setText(QString(QLatin1String("%1")).arg(this->_d->_testCasesItem->rowCount())
                                    +QLatin1String(" test cases"));

  return;
}

TestCaseItem* PropTestCases::testCase(const QUuid& testCaseUuid) const
{
  for(TestCaseItem* testCaseItem : this->testCases())
    if(testCaseItem->uuid()==testCaseUuid)
      return testCaseItem;

  return 0;
}

PropTestCases::TestCaseSet PropTestCases::testCases() const
{
  TestCaseSet testCases;
  if(!this->_d->_testCasesItem)
    return testCases;

  int end=this->_d->_testCasesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->_d->_testCasesItem->child(i);
    TestCaseItem* testCase=utils::simple_cast<TestCaseItem*>(currChildItem);
    Q_ASSERT(testCase);
    testCases.append(testCase);
  }

  return testCases;
}

} // namespace ts
} // namespace model
