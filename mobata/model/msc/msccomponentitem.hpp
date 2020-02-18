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
#ifndef MODEL_MSC_MSCCOMPONENTITEM_HPP
#define MODEL_MSC_MSCCOMPONENTITEM_HPP

#include "../base/componentitem.hpp"

#include "msc_types.hpp"

namespace model {
namespace msc {

class MOBATASHARED_EXPORT MscComponentItem
    : public base::ComponentItem
{
public:
  MscComponentItem(const QString& name);
  virtual ~MscComponentItem();

public:
  base::PortItem const* defaultPort() const;

protected:
  base::PortItem* _defaultPort;
};

} // namespace msc
} // namespace model

#endif // MODEL_MSC_MSCCOMPONENTITEM_HPP
