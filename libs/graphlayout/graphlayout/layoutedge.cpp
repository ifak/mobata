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

#include "layoutedge.hpp"
#include <QUuid>

using namespace graphlayout;

class LayoutEdge::Private
{
  friend class LayoutEdge;

public:
  Private(LayoutNode const* source, LayoutNode const* target)
    : _source(source), _target(target),_externUuid(QUuid::createUuid())
  {}

  ~Private()
  {
    qDeleteAll(_points);
  }

private:
  // edge
  LayoutNode const*	_source;
  LayoutNode const*	_target;
  LayoutNodePort*	_sourcePort = nullptr;
  LayoutNodePort*	_targetPort = nullptr;
  // edge properties
  QUuid	_externUuid;
  QColor _color = QColor("black");
  ArrowEnum _type = Arrow;
  QList<QPointF*> _points;
  double _lineWidth = 2;
  int _arrowSize = 15;
  // label properties
  QString _label;
  QPointF _labelPos;
  int _labelSize = 12;
  QColor _labelColor = QColor("black");
  //infobox
  bool _showInfobox = false;
  QString _infoBoxStrings;
  //Highlight
  bool _highlight = false;
  QColor _highlightColor = QColor("green");
  // graphviz parameter
  bool _constraint = true;
  int _weight = -1;
  double _minlen = -1;
  QString _rank = "";
  bool _staticLabel = false;
};

LayoutEdge::LayoutEdge(LayoutNode const* source,
                       LayoutNode const* target,
                       QObject *parent)
  : QObject(parent), _d(new Private(source,target))
{
}

LayoutEdge::LayoutEdge(const QString& name,
                       LayoutNode const* source,
                       LayoutNode const* target,
                       QObject* parent)
  : QObject(parent), prop::NameProperty(name), _d(new Private(source,target))
{
}

LayoutEdge::~LayoutEdge()
{
  delete this->_d;
}

LayoutNode const* LayoutEdge::source() const
{
  return this->_d->_source;
}

void LayoutEdge::setSourcePort(LayoutNodePort* port)
{
  this->_d->_sourcePort = port;
}

LayoutNodePort const* LayoutEdge::sourcePort() const
{
  return this->_d->_sourcePort;
}

LayoutNode const* LayoutEdge::target() const
{
  return this->_d->_target;
}

void LayoutEdge::setTargetPort(LayoutNodePort* port)
{
  this->_d->_targetPort = port;
}

const LayoutNodePort* LayoutEdge::targetPort() const
{
  return this->_d->_targetPort;
}

void LayoutEdge::setExternUuid(const QUuid& newExternUuid)
{
  this->_d->_externUuid=newExternUuid;

  return;
}

const QUuid& LayoutEdge::externUuid() const
{
  return this->_d->_externUuid;
}

void LayoutEdge::setColor(const QColor& color)
{
  this->_d->_color = color;
}

const QColor& LayoutEdge::color() const
{
  return this->_d->_color;
}
void LayoutEdge::setLabel(const QString& label)
{
  this->_d->_label=label;

  return;
}

//lineWidth
void LayoutEdge::setLineWidth(const double& width)
{
  this->_d->_lineWidth = width;
}
const double& LayoutEdge::lineWidth() const
{
  return this->_d->_lineWidth;
}
//arrowSize
void LayoutEdge::setArrowsize(const int& size)
{
  this->_d->_arrowSize=size;
}
const int& LayoutEdge::Arrowsize() const
{
  return this->_d->_arrowSize;
}

const QString& LayoutEdge::label() const
{
  return this->_d->_label;
}

void LayoutEdge::setLabelPos(const QPointF& labelPos)
{
  this->_d->_labelPos=labelPos;

  return;
}

const QPointF& LayoutEdge::labelPos() const
{
  return this->_d->_labelPos;
}

void LayoutEdge::setLabelColor(const QColor& color)
{
  this->_d->_labelColor=color;

  return;
}

const QColor& LayoutEdge::labelColor() const
{
  return this->_d->_labelColor;
}

void LayoutEdge::setLabelTextSize(const int& labelSize)
{
  this->_d->_labelSize=labelSize;
}

const int& LayoutEdge::labelTextSize() const
{
  return this->_d->_labelSize;
}

void LayoutEdge::setType(const ArrowEnum &type)
{
  this->_d->_type=type;

  return;
}

const ArrowEnum &LayoutEdge::type() const
{
  return this->_d->_type;
}

const QList<QPointF*>& LayoutEdge::points() const
{
  return this->_d->_points;
}
void LayoutEdge::addPoint(QPointF point)
{
  this->_d->_points.append(new QPointF(point));
}
void LayoutEdge::clearPoints()
{
  qDeleteAll(this->_d->_points);
  this->_d->_points.clear();
}
//! Infobox
void LayoutEdge::setShowInfobox(bool wert)
{
  this->_d->_showInfobox = wert;
}
bool LayoutEdge::showInfobox() const
{
  return this->_d->_showInfobox;
}
void LayoutEdge::setInfoBoxStrings(QString list)
{
  this->_d->_infoBoxStrings = list;
}
QString LayoutEdge::infoBoxStrings() const
{
  return this->_d->_infoBoxStrings;
}
//! Highlight
void LayoutEdge::setHighlight(bool wert)
{
  this->_d->_highlight = wert;
}
bool LayoutEdge::highlight() const
{
  return this->_d->_highlight;
}
void LayoutEdge::setHighlightColor(QColor color)
{
  this->_d->_highlightColor = color;
}
QColor LayoutEdge::highlightColor() const
{
  return this->_d->_highlightColor;
}
//! GraphvizSettings
void LayoutEdge::setConstraint(bool constraint)
{
  this->_d->_constraint = constraint;
}

bool LayoutEdge::constraint() const
{
  return this->_d->_constraint;
}

void LayoutEdge::setWeight(int weight)
{
  this->_d->_weight = weight;
}

int LayoutEdge::weight() const
{
  return this->_d->_weight;
}

void LayoutEdge::setMinLen(double minLen)
{
  this->_d->_minlen = minLen;
}

double LayoutEdge::minLen() const
{
  return this->_d->_minlen;
}

void LayoutEdge::setRank(QString rank)
{
  this->_d->_rank = rank;
}

QString LayoutEdge::rank() const
{
  return this->_d->_rank;
}
// staticLabel
void LayoutEdge::setStaticLabel(bool wert)
{
  this->_d->_staticLabel = wert;
}
bool LayoutEdge::staticLabel() const
{
  return this->_d->_staticLabel;
}
