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
#ifndef MODEL_TS_TESTCOMPONENTITEM_HPP
#define MODEL_TS_TESTCOMPONENTITEM_HPP

#include "../../mobata_global.hpp"

#include "../msc/msccomponentitem.hpp"

#include "ts_types.hpp"

namespace model {
namespace ts {

class MOBATASHARED_EXPORT TestComponentItem
    : public msc::MscComponentItem
{
public:
  TestComponentItem(const QString& name)
    : msc::MscComponentItem(name)
  {}

  virtual ~TestComponentItem()
  {}

public:
  virtual int     compType() const { return  TestComponentType;}
  virtual QString compTypeString() const {return QStringLiteral("TestComponentType");}
};

} // namespace ts
} // namespace model

#endif // MODEL_TS_TESTCOMPONENTITEM_HPP
