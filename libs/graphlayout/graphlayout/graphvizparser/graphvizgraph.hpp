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

#include <QString>
#include <QVector>

namespace graphvizparser
{

class Point
{
public:
  Point();
  Point(const double x, const double y);
  Point& operator=(const Point& other);

  double getX() const;
  double getY() const;

private:
  double _x,_y;
};

class GraphvizNode
{
public:
  void setName(const QString& name);
  void setLabel(const QString& label);
  void setPos(const double x, const double y);
  void setWidth(const double width);
  void setHeight(const double height);

  QString getName() const;
  QString getLabel() const;
  Point   getPos() const;
  double  getWidth() const;
  double  getHeight() const;

private:
  QString _name, _label;
  Point   _pos;
  double  _width, _height;
};

struct GraphvizEdge
{
public:
  typedef	QVector<Point>	PointSet;
public:
  void	setFrom(const QString& from);
  void	setTo(const QString& to);
  void	addPoint(const double x, const double y);
  void	setLabel(const QString& label);
  void	setLabelPos(const double x, const double y);

  QString   getFrom() const;
  QString   getTo() const;
  PointSet  getPoints() const;
  QString   getLabel() const;
  Point     getLabelPos() const;

private:
  QString   _from, _to;
  PointSet  _points;
  QString   _label;
  Point     _labelPos;
};

class GraphvizGraph
{
public:
  typedef QVector<GraphvizNode>	GraphvizNodeSet;
  typedef QVector<GraphvizEdge>	GraphvizEdgeSet;

public:
  GraphvizGraph();

public:
  const GraphvizNodeSet&	getNodes() const;
  const GraphvizEdgeSet&	getEdges() const;

  GraphvizNode const*			getNode(const QString &nodeName) const;
  void										addNode(const GraphvizNode& node);
  void										addEdge(const GraphvizEdge& edge);

private:
  GraphvizNodeSet	_nodes;
  GraphvizEdgeSet	_edges;
};

}///end namespace graphvizparser
