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

#include "ts_types.hpp"

#include "../../prop/nameproperty.hpp"

#include "../base/modelitem.hpp"
#include "../base/propdatatypes.hpp"
#include "../base/propattributes.hpp"
#include "../base/propsignals.hpp"
#include "../base/propcomponents.hpp"
#include "../base/proplinks.hpp"

#include "testcomponentitem.hpp"

namespace model{
namespace ts{

class MOBATASHARED_EXPORT TestSystemItem
    : public base::ModelItem,
    public prop::NameProperty,
    public base::PropDataTypes,
    public base::PropAttributes,
    public base::PropSignals,
    public base::PropLinks,
    public base::PropComponents
{
public:
  TestSystemItem(SutItem const* sutItem = nullptr,
                 const QString& name=QStringLiteral("test system"));
  virtual ~TestSystemItem();

public:
  void            setSutItem(SutItem const* sutItem);
  SutItem const*  sutItem() const;

public:
  virtual void  reset();

public:
  TestComponentItem const*  testManagerComponent() const;

public:
  virtual QString toString() const;

protected:
  Q_DISABLE_COPY(TestSystemItem)
  class Private;
  Private*	_d;
};

typedef QSharedPointer<TestSystemItem> TestSystemItemPtr;

} // namespace ts
} // namespace model
