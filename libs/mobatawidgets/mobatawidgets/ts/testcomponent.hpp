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
#ifndef VIEW_TS_TESTCOMPONENT_HPP
#define VIEW_TS_TESTCOMPONENT_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../comp/component.hpp"

namespace view{
namespace ts{

class MOBATAWIDGETSSHARED_EXPORT TestComponent
    : public comp::Component
{
public:
  enum{Type = UserType + TsTestComponentType};

public:
  TestComponent(const QString& notation = QLatin1String("newTestComponent"),
                const comp::NodeOptions& nodeOptions=comp::NodeOptions().setSize(100,100));
  virtual ~TestComponent();

public:
  virtual int type() const {return Type;}

private:
  class Private;
  Private* _d;
};

} //end namespace ts
} //end namespace view

#endif // VIEW_TS_TESTCOMPONENT_HPP
