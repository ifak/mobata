#include "testsystemitem.hpp"

#include "testsuite.hpp"

#include <QDebug>

#include "../../memory_leak_start.hpp"

namespace model {
namespace ts {

class TestSystemItem::Private
{
  friend class TestSystemItem;

  SutItem const*      _sutItem;
  TestComponentItem*  _testManagerComponent;

  Private(SutItem const* sutItem)
    : _sutItem(sutItem)
  {}

  void createTestManagerComponent(TestSystemItem* testSystemItem);
};

void TestSystemItem::Private::createTestManagerComponent(TestSystemItem* testSystemItem)
{
  Q_ASSERT(testSystemItem);

  this->_testManagerComponent = new TestComponentItem(QStringLiteral("MTC"));
  QString errorString;
  bool result = testSystemItem->addComponent(this->_testManagerComponent, &errorString);
  if(!result)
    qCritical()<<"error during test manager component creation: "<<errorString;
  Q_ASSERT(result);

  return;
}

TestSystemItem::TestSystemItem(SutItem const* sutItem,
                               const QString& name)
  :	prop::NameProperty(name),
    PropDataTypes(this),
    PropAttributes(this),
    PropSignals(this),
    PropLinks(this),
    PropComponents(this),
    _d(new Private(sutItem))
{
  this->setIcon(QIcon(":mobata/images/ts/testsystem.png"));
  this->setText(this->toString());

  this->_d->createTestManagerComponent(this);
}

TestSystemItem::~TestSystemItem()
{
  delete this->_d;
}

void TestSystemItem::setSutItem(SutItem const* sutItem)
{
  this->_d->_sutItem = sutItem;
}

const SutItem*TestSystemItem::sutItem() const
{
  return this->_d->_sutItem;
}

void TestSystemItem::reset()
{
  this->resetAttributes();
  this->resetSignals();
  this->resetComponents();
  this->resetLinks();

  this->_d->createTestManagerComponent(this);

  return;
}

TestComponentItem const* TestSystemItem::testManagerComponent() const
{
  return this->_d->_testManagerComponent;
}

QString TestSystemItem::toString() const
{
  return this->name();
}

} // namespace ts
} // namespace model
