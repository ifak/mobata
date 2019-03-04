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

#include "testresultitem.hpp"

#include "testcomponentitem.hpp"

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

