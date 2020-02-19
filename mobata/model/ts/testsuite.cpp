#include "testsuite.hpp"

#include "testgroupitem.hpp"
#include "testcaseitem.hpp"
#include "sutitem.hpp"
#include "sutcomponentitem.hpp"
#include "testsystemitem.hpp"
#include "testcomponentitem.hpp"

#include "../base/portitem.hpp"

#include "../../utils/functors.hpp"

#include "../../memory_leak_start.hpp"

namespace model{
namespace ts{

class TestSuite::Private
{
  friend class TestSuite;

  Private()
    : _sutItem(nullptr),
      _testSystemItem(nullptr),
      _testGroupsItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  SutItem*        _sutItem;
  TestSystemItem* _testSystemItem;
  QStandardItem*  _testGroupsItem;
};

TestSuite::TestSuite(QObject *parent)
  :	base::BaseModel(parent),
    PropTestCases(this->invisibleRootItem()),
    _d(new Private)
{
  this->setDataTypesParentItem(this->invisibleRootItem());
  this->setAttributesParentItem(this->invisibleRootItem());
  this->setSignalsParentItem(this->invisibleRootItem());

  this->setName("test suite");

  this->_d->_sutItem=new SutItem("sut");
  ((QStandardItemModel*)this)->appendRow(this->_d->_sutItem);

  this->_d->_testSystemItem=new TestSystemItem(this->_d->_sutItem,
                                               QStringLiteral("test system"));
  ((QStandardItemModel*)this)->appendRow(this->_d->_testSystemItem);

  this->_d->_testGroupsItem=new QStandardItem(QIcon(":mobata/images/ts/testsuite.png"),
                                              "test groups");
  ((QStandardItemModel*)this)->appendRow(this->_d->_testGroupsItem);

  this->setHeaderData(0, Qt::Horizontal, this->name(), Qt::DisplayRole);
}

TestSuite::~TestSuite()
{
    delete this->_d;
}

void TestSuite::reset()
{
  base::BaseModel::reset();
  this->resetAttributes();
  this->resetTestCases();

  this->setName("test suite");

  if(this->_d->_sutItem)
    this->_d->_sutItem->reset();
  if(this->_d->_testSystemItem)
    this->_d->_testSystemItem->reset();
  if(this->_d->_testGroupsItem)
    this->_d->_testGroupsItem->removeRows(0, this->_d->_testGroupsItem->rowCount());

  return;
}

SutItem* TestSuite::sutItem()
{
  return this->_d->_sutItem;
}

const SutItem *TestSuite::sutItem() const
{
  return this->_d->_sutItem;
}

TestSystemItem* TestSuite::testSystemItem()
{
  return this->_d->_testSystemItem;
}

TestSystemItem const* TestSuite::testSystemItem() const
{
  return this->_d->_testSystemItem;
}

TestGroupItem *TestSuite::addTestGroup(const QString& name,
                                       QString* errorMessage)
{
  if(this->testGroup(name))
  {
    if(errorMessage)
      *errorMessage += tr("there is already a test group "
                          "with name '%1' available!")
                       .arg(name);
    return 0;
  }

  if(!this->_d->_testGroupsItem)
  {
    this->_d->_testGroupsItem=new QStandardItem(QIcon(":images/uml/manyobject.png"),
                                                "test groups");
    this->appendRow(this->_d->_testGroupsItem);
  }

  TestGroupItem* newTestGroup=new TestGroupItem(this,name);
  this->_d->_testGroupsItem->appendRow(newTestGroup);

  return newTestGroup;
}

TestGroupItem* TestSuite::testGroup(const QString& name)
{
  foreach(TestGroupItem* testGroup, this->testGroups())
    if(testGroup->name()==name)
      return testGroup;

  return 0;
}

const TestGroupItem*TestSuite::testGroup(const QString& name) const
{
  foreach(TestGroupItem const* testGroup,
          this->testGroups())
    if(testGroup->name()==name)
      return testGroup;

  return 0;
}

TestSuite::TestGroupSet TestSuite::testGroups()
{
  TestGroupSet testGroups;
  int end=this->_d->_testGroupsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_testGroupsItem->child(i);
    TestGroupItem* testGroup=utils::simple_cast<TestGroupItem*>(currChild);

    testGroups.append(testGroup);
  }

  return testGroups;
}

TestSuite::ConstTestGroupSet TestSuite::testGroups() const
{
  ConstTestGroupSet testGroups;
  int end=this->_d->_testGroupsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_testGroupsItem->child(i);
    TestGroupItem* testGroup=utils::simple_cast<TestGroupItem*>(currChild);

    testGroups.append(testGroup);
  }

  return testGroups;
}

const PortItem* TestSuite::port(const QUuid &portUuid) const
{
  using namespace base;

  PortItem const* portItem=0;
  for(ComponentItem const* sutComp : this->_d->_sutItem->components())
  {
    if((portItem=sutComp->portById(portUuid)))
      return portItem;
  }

  for(ComponentItem const* testComp : this->_d->_testSystemItem->components())
  {
    if((portItem=testComp->portById(portUuid)))
      return portItem;
  }

//  for(TestGroupItem const* testGroup : this->testGroups())
//  {
//    TestSystemItem const* testGroupTestSystem=testGroup->testSystemItem();
//    if(!testGroupTestSystem)
//      continue;

//    for(TestComponentItem const* testComp : testGroupTestSystem->components())
//    {
//      if((portItem=testComp->port(portUuid)))
//        return portItem;
//    }
//  }

  return 0;
}

}///end namespace ts
}///end namespace model
