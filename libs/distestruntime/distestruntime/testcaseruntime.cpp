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

#include "testcaseruntime.hpp"

#include "testcompruntime.hpp"

#include <QDebug>

using namespace distestruntime;

class TestCaseRuntime::Private
{
  friend class TestCaseRuntime;

  QList<TestCompRuntime*> _activeTestCompRuntimes;

  Private(const QList<TestCompRuntime*>& activeTestCaseRuntimes)
    : _activeTestCompRuntimes(activeTestCaseRuntimes)
  {}
};

TestCaseRuntime::TestCaseRuntime(const QList<TestCompRuntime*>& activeTestCompRuntimes,
                         QObject* parent)
  : QObject(parent), _d(new Private(activeTestCompRuntimes))
{
  for(TestCompRuntime const* tcRuntime : this->_d->_activeTestCompRuntimes)
    connect(tcRuntime, &TestCompRuntime::quit, this, &TestCaseRuntime::testCompQuitted);
}

TestCaseRuntime::~TestCaseRuntime()
{
  delete this->_d;
}

void TestCaseRuntime::start()
{
  for(TestCompRuntime* testCaseRuntime : this->_d->_activeTestCompRuntimes)
    testCaseRuntime->start();

  return;
}

void TestCaseRuntime::testCompQuitted()
{
//  qDebug()<<"TestCaseRuntime::testCompQuitted() executed!";

  TestCompRuntime* quittedTestCompRuntime = qobject_cast<TestCompRuntime*>(this->sender());
  if(!quittedTestCompRuntime)
    return;

  this->_d->_activeTestCompRuntimes.removeAll(quittedTestCompRuntime);

  if(this->_d->_activeTestCompRuntimes.isEmpty())
  {
    emit this->testCaseQuitted();
//    qDebug()<<"testCaseQuitted sent!";
  }

  return;
}
