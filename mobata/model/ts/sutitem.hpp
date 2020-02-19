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
#include "../base/proplinks.hpp"
#include "../base/propcomponents.hpp"

#include "sutcomponentitem.hpp"

namespace model{
namespace ts{

class MOBATASHARED_EXPORT SutItem
    :	public base::ModelItem,
    public prop::NameProperty,
    public base::PropDataTypes,
    public base::PropAttributes,
    public base::PropSignals,
    public base::PropLinks,
    public base::PropComponents
{
public:
  SutItem(const QString& name=QLatin1String("SUT"));
  virtual ~SutItem();

public:
  virtual void  reset();

public:
  virtual QString toString() const;
};

typedef QSharedPointer<SutItem> SutItemPtr;

}///end namespace ts
}///end namespace model
