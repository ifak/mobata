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

#include "graphvizgraph.hpp"

namespace graphvizparser
{

const double pixperinch=96;

Point::Point()	:	_x(0),_y(0)
{}

Point::Point(const double x, const double y)
  :	_x(pixperinch*x), _y(pixperinch*y)
{}

Point& Point::operator=(const Point& other)
{
  this->_x=other._x; this->_y=other._y;
  return *this;
}

double Point::getX() const
{
  return this->_x;
}

double Point::getY() const
{
  return this->_y;
}

void GraphvizNode::setName(const QString &name)
{
  this->_name=name;

  return;
}

void GraphvizNode::setLabel(const QString &label)
{
  this->_label=label;

  return;
}

void GraphvizNode::setPos(const double x, const double y)
{
  this->_pos=Point(x, y);

  return;
}

void GraphvizNode::setWidth(const double width)
{
  this->_width=pixperinch*width;

  return;
}

void GraphvizNode::setHeight(const double height)
{
  this->_height=pixperinch*height;

  return;
}

QString GraphvizNode::getName() const
{
  return this->_name;
}

QString GraphvizNode::getLabel() const
{
  return this->_label;
}

Point GraphvizNode::getPos() const
{
  return this->_pos;
}

double GraphvizNode::getWidth() const
{
  return this->_width;
}

double GraphvizNode::getHeight() const
{
  return this->_height;
}

void GraphvizEdge::setFrom(const QString &from)
{
  this->_from=from;

  return;
}

void GraphvizEdge::setTo(const QString &to)
{
  this->_to=to;

  return;
}

void GraphvizEdge::addPoint(const double x, const double y)
{
  this->_points.push_back(Point(x,y));

  return;
}

void GraphvizEdge::setLabel(const QString &label)
{
  this->_label=label;

  return;
}

void GraphvizEdge::setLabelPos(const double x, const double y)
{
  this->_labelPos=Point(x,y);
}

QString GraphvizEdge::getFrom() const
{
  return this->_from;
}

QString GraphvizEdge::getTo() const
{
  return this->_to;
}

GraphvizEdge::PointSet GraphvizEdge::getPoints() const
{
  return this->_points;
}

QString GraphvizEdge::getLabel() const
{
  return this->_label;
}

Point GraphvizEdge::getLabelPos() const
{
  return this->_labelPos;
}

GraphvizGraph::GraphvizGraph()
{
}

const GraphvizGraph::GraphvizNodeSet &GraphvizGraph::getNodes() const
{
  return this->_nodes;
}

const GraphvizGraph::GraphvizEdgeSet &GraphvizGraph::getEdges() const
{
  return this->_edges;
}

GraphvizNode const* GraphvizGraph::getNode(const QString &nodeName) const
{
  for(const GraphvizNode& node: this->_nodes)
    if(node.getName()==nodeName)
      return &node;

  return 0;
}

void GraphvizGraph::addNode(const GraphvizNode &node)
{
  if(this->getNode(node.getName()))
    return;

  this->_nodes.push_back(node);

  return;
}

void GraphvizGraph::addEdge(const GraphvizEdge &edge)
{
  this->_edges.push_back(edge);

  return;
}

}// end namespace graphvizparser
