#include "testresultitem.hpp"

#include "testcomponentitem.hpp"

#include "../../memory_leak_start.hpp"

namespace model {
namespace ts {

class TestResultItem::Private
{
  friend class TestResultItem;

  Private(const TestResultValue value)
    : _value(value)
  {}

  TestResultValue _value;
};

TestResultItem::TestResultItem(const TestComponentItem* component,
                               const TestResultValue value)
  : msc::MscStepItem(component),
    _d(new Private(value))
{}

TestResultItem::~TestResultItem()
{
  delete this->_d;
}

TestResultValue TestResultItem::value() const
{
  return this->_d->_value;
}

void TestResultItem::setValue(const TestResultValue value)
{
  this->_d->_value=value;

  return;
}

} // namespace ts
} // namespace model

