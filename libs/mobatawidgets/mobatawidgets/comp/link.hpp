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
#ifndef VIEW_COMP_LINK_HPP
#define VIEW_COMP_LINK_HPP

#include "../mobatawidgets_global.hpp"

#include "../graph/edge.hpp"

#include "types.hpp"

namespace view{
namespace comp{

class Port;
class LinkPort;

class MOBATAWIDGETSSHARED_EXPORT Link
    : public graph::Edge
{
  typedef graph::Edge	SuperClass;

  enum {Type = UserType + LinkItem};

public:
  Link(Port* from, Port* to,
       const QString& notation=QString(),
       const QUuid& uuid=QUuid::createUuid(),
       const ArcOptions& arcOptions=ArcOptions(),
       QGraphicsItem * parent = 0 );

public:
  Port*     sourcePort();
  Port*     targetPort();
  LinkPort* linkPort();

  void controlPointPressed(ControlPointType *controlPoint);
  void controlPointReleased(ControlPointType *controlPoint);

public:
  virtual void  updatePath(const QPainterPath& newPath);

private:
  LinkPort* _linkPort;
};

}////end namespace comp

}// end namespace graph

#endif
