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
#ifndef MODEL_REQUIREMENT_REQUIREMENTITEM_HPP
#define MODEL_REQUIREMENT_REQUIREMENTITEM_HPP

#include "requirement_types.hpp"

#include "descriptionproperty.hpp"

#include "../msc/mscsequence.hpp"
#include "../base/propattributes.hpp"
#include "../base/propsignals.hpp"
#include "../base/propdatatypes.hpp"

namespace model{
namespace irdl{

class RequirementItem
    : public msc::MscSequence,
    public base::PropDataTypes,
    public base::PropAttributes,
    public base::PropSignals,
    public prop::DescriptionProperty
{
public:
  RequirementItem(const QString& name=QStringLiteral("requirement_1"));
  virtual ~RequirementItem();

public:
  virtual void reset();

public:
  msc::MscFragmentItem *addDurationFragment(uint duration);

private:
  Q_DISABLE_COPY(RequirementItem)
  class Private;
  Private*  _d;
};

}/// end namespace requirement
}/// end namespace model

#endif // MODEL_REQUIREMENT_REQUIREMENTITEM_HPP
