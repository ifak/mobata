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
