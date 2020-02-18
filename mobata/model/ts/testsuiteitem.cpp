#include "testsuiteitem.hpp"

#include "sutitem.hpp"
#include "sutcomponentitem.hpp"
#include "testsystemitem.hpp"
#include "testcomponentitem.hpp"
#include "testcaseitem.hpp"

namespace model {
namespace ts {

class TestSuiteItem::Private
{
  friend class TestSuiteItem;

  Private()
    : _sutItem(0),
      _testSystemItem(0)
  {}

  SutItem*        _sutItem;
  TestSystemItem* _testSystemItem;
};

TestSuiteItem::TestSuiteItem(const QString& name,
                             const QUuid& uuid)
  : prop::NameProperty(name),
    base::ModelItem(uuid),
    base::PropDataTypes(this),
    base::PropAttributes(this),
    base::PropSignals(this),
    PropTestCases(this),
    _d(new Private)
{
  this->setIcon(QIcon(":mobata/images/ts/testsuite.png"));
  this->setText(this->toString());

  this->_d->_sutItem=new SutItem("sut");
  this->appendRow(this->_d->_sutItem);

  this->_d->_testSystemItem=new TestSystemItem(this->_d->_sutItem,
                                               QStringLiteral("test system"));
  this->appendRow(this->_d->_testSystemItem);
}

TestSuiteItem::~TestSuiteItem()
{
  delete this->_d;
}

void TestSuiteItem::reset()
{
  this->resetDataTypes();
  this->resetAttributes();
  this->resetSignals();
  this->resetTestCases();

  if(this->_d->_sutItem)
    this->_d->_sutItem->reset();
  if(this->_d->_testSystemItem)
    this->_d->_testSystemItem->reset();

  return;
}

QString TestSuiteItem::toString() const
{
  return this->name();
}

SutItem* TestSuiteItem::sutItem()
{
  return this->_d->_sutItem;
}

SutItem const* TestSuiteItem::sutItem() const
{
  return this->_d->_sutItem;
}

TestSystemItem* TestSuiteItem::testSystemItem()
{
  return this->_d->_testSystemItem;
}

TestSystemItem const* TestSuiteItem::testSystemItem() const
{
  return this->_d->_testSystemItem;
}

PortItem const* TestSuiteItem::port(const QUuid &portUuid) const
{
  PortItem const* portItem=0;
  for(base::ComponentItem const* sutComp : this->_d->_sutItem->components())
  {
    if((portItem=sutComp->portById(portUuid)))
      return portItem;
  }

  for(base::ComponentItem const* testComp : this->_d->_testSystemItem->components())
  {
    if((portItem=testComp->portById(portUuid)))
      return portItem;
  }

  return 0;
}

int TestSuiteItem::calcTestStepsCount() const
{
  int testStepsCount=0;

  for(TestCaseItem const* testCase : this->testCases())
    testStepsCount+=testCase->calcTestStepsCount();

  return testStepsCount;
}

} // namespace ts
} // namespace model
