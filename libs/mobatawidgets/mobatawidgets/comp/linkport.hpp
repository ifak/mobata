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
#ifndef VIEW_COMP_LINKPORT_HPP
#define VIEW_COMP_LINKPORT_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "port.hpp"

namespace view {
namespace comp {

class Link;

class MOBATAWIDGETSSHARED_EXPORT LinkPort
    : public Port
{
public:
  enum {Type = UserType + LinkPortItem};

public:
  LinkPort(Link* link,
           const QString& notation="port",
           const NodeOptions& portOptions=NodeOptions()
                                          .setSize(15,15)
                                          .setColor(Qt::white)
                                          .setPen(QPen(Qt::black, 3)),
           const QUuid& uuid=QUuid::createUuid());
  virtual ~LinkPort();

protected:
  virtual QPointF calcPosition(QPointF possPosition);
};

} // namespace comp
} // namespace view

#endif // VIEW_COMP_LINKPORT_HPP
