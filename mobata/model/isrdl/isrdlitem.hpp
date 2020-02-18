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

#include "../base/base_types.hpp"
#include "../base/modelitem.hpp"
#include "../base/propattributes.hpp"
#include "../../prop/nameproperty.hpp"

namespace model{
namespace isrdl{
class IsrdlAttackDescription;
class IsrdlAttackImpact;

class IsrdlItem:
    public base::ModelItem,
    public base::PropAttributes,
    public prop::NameProperty
{
public:
  IsrdlItem(const QString& name=QStringLiteral("isrdl_1"));
  virtual ~IsrdlItem();

public:
  virtual void reset();

public:
  IsrdlAttackDescription* attackDescription();
  void                    setAttackDescription(IsrdlAttackDescription* descrip);

  IsrdlAttackImpact*      attackImpact();
  void                    setAttackImpact(IsrdlAttackImpact* impact);

private:
  Q_DISABLE_COPY(IsrdlItem)
  class Private;
  Private*  _d;
};

}/// end namespace isrdl
}/// end namespace model

#endif // MODEL_REQUIREMENT_REQUIREMENTITEM_HPP
