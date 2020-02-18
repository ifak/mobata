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
#ifndef MODEL_REQUIREMENT_REQUIREMENTSMODEL_HPP
#define MODEL_REQUIREMENT_REQUIREMENTSMODEL_HPP

#include "../base/base_types.hpp"
#include "../base/modelitem.hpp"
#include "../base/basemodel.hpp"
#include "propisrdl.hpp"

namespace model{
namespace msc {
    class MscFragmentRegionItem;
}
namespace isrdl{

class MOBATASHARED_EXPORT IsrdlModel
    : public base::BaseModel,
    public PropIsrdl
{

public:
  explicit IsrdlModel(QObject *parent = 0);
  virtual ~IsrdlModel();

public:
  virtual void reset();

private:
  Q_DISABLE_COPY(IsrdlModel)
  class Private;
  Private*	_d;
};

typedef QSharedPointer<IsrdlModel> IsrdlModelPtr;

}///end namespace isrdl
}///end namespace model

#endif // MODEL_REQUIREMENT_REQUIREMENTSMODEL_HPP
