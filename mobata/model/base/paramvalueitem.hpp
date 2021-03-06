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

#include "base_types.hpp"

#include "modelitem.hpp"

namespace model {
namespace base {

class ParamItem;

class MOBATASHARED_EXPORT ParamValueItem
    : public ModelItem
{
public:
  ParamValueItem(ParamItem const* param,
                 const QVariant& value);
  virtual ~ParamValueItem();
  
public:
  ParamItem const*  param() const;
  void              setValue(const QVariant& value);
  QVariant          value() const;
  QString           toString() const;

protected:
  void  setParam(ParamItem const* param);
  
private:
  Q_DISABLE_COPY(ParamValueItem)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model
