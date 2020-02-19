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

#include "msc_types.hpp"
#include "mscpropcoverages.hpp"
#include "mscsequenceitem.hpp"

namespace model{
namespace msc{

class MOBATASHARED_EXPORT MscStepItem
    : public MscSequenceItem,
    public MscPropCoverages
{
protected:
  MscStepItem(MscComponentItem const* component);

public:
  virtual ~MscStepItem();

public:
  MscComponentItem const* component() const;

private:
  Q_DISABLE_COPY(MscStepItem)
  class Private;
  Private* _d;
};

}/// end namespace msc
}/// end namespace model
