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

#include "testsystemitem.hpp"

#include "testsuite.hpp"

#include <QDebug>

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
