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
#ifndef VIEW_TS_SUTCOMPONENT_HPP
#define VIEW_TS_SUTCOMPONENT_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../msc/msccomponent.hpp"


namespace view {
namespace ts {

class MOBATAWIDGETSSHARED_EXPORT SutComponent
    : public comp::Component
{
public:
  enum{Type = UserType + TsSutComponentType};

public:
  SutComponent(const QString& name,
               const NodeOptions& sutCompOptions=NodeOptions()
                                                 .setSize(QSizeF(100, 75))
                                                 .setPen(QPen(Qt::black, 3))
                                                 .setColor(Qt::darkBlue)
                                                 .setTextColor(Qt::white)
                                                 .setTextFont(QFont("Times", 10, QFont::Bold)));
  virtual ~SutComponent();

public:
  virtual int type() const {return Type;}
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_SUTCOMPONENT_HPP
