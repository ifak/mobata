#include "testgroupitem.hpp"

#include "testcaseitem.hpp"
#include "testsystemitem.hpp"
#include "testsuite.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

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
