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
#pragma once

#include "../../mobata_global.hpp"

#include "../../prop/nameproperty.hpp"

#include "../base/modelitem.hpp"
#include "../base/propdatatypes.hpp"
#include "../base/propattributes.hpp"
#include "../base/propsignals.hpp"

#include "propttestcases.hpp"

namespace model {
namespace ts {

class MOBATASHARED_EXPORT TestSuiteItem
    : public prop::NameProperty,
    public base::ModelItem,
    public base::PropDataTypes,
    public base::PropAttributes,
    public base::PropSignals,
    public PropTestCases
{
public:
  TestSuiteItem(const QString& name=QStringLiteral("test suite"),
                const QUuid& uuid=QUuid::createUuid());
  virtual ~TestSuiteItem();

public:
  virtual void    reset();
  virtual QString toString() const override;

public:
  SutItem*              sutItem();
  SutItem const*        sutItem() const;
  TestSystemItem*       testSystemItem();
  TestSystemItem const* testSystemItem() const;

public:
  PortItem const*       port(const QUuid& portUuid) const;
  int                   calcTestStepsCount() const;

private:
  Q_DISABLE_COPY(TestSuiteItem)
  class Private;
  Private*	_d;
};

} // namespace ts
} // namespace model
