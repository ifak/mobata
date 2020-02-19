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

#include "../base/base_types.hpp"
#include "../base/modelitem.hpp"
#include "../base/propattributes.hpp"
#include "../../prop/nameproperty.hpp"

namespace model{
namespace isrdl{

class IsrdlAttackImpact:
    public base::ModelItem
{
public:
  IsrdlAttackImpact();
  virtual ~IsrdlAttackImpact();

public:
  void update();
  bool confidentiality();
  void setConfidentiality(bool conf);

  bool integrity();
  void setIntegrity(bool integ);

  int  timeout();
  void setTimeout(int timeout);
private:
  Q_DISABLE_COPY(IsrdlAttackImpact)
  class Private;
  Private*  _d;
};

}/// end namespace isrdl
}/// end namespace model
