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

#include "layoutnode.hpp"

using namespace graphlayout;

class LayoutNode::Private
{
  friend class LayoutNode;

public:
  Private(){}

  ~Private(){}

private:
  ShapeEnum _shape = RoundedRect;
  QUuid _externUuid = QUuid::createUuid();
  QSizeF _size = QSizeF(100,50);
  QPointF _pos = QPointF(0,0);
  QColor _color = QColor("white");
  double _borderWidth = 2;
  QColor _borderColor = QColor("black");

  bool _fixedPos = false;
  QPointF _absolutePos = QPointF(0,0);

  bool _token = false;
  QColor _tokenColor = QColor("black");

  QString _label = "";
  QPointF _labelPos = QPointF(0,0);
  int _labelTextSize=12;
  QColor _labelColor = QColor("black");
  QFont _labelFont = QFont("Calibre");

  QString _xlabel = "";
  int _xLabelTextSize=12;
  QColor _xLabelColor = QColor("black");
  QFont _xLabelFont = QFont("Calibre");

  QList<LayoutNode*> _nodes;
  QList<LayoutNodePort*> _ports;
  LayoutNode* _parentNode = nullptr;

  bool _staticLabels = false;

  bool _showInfobox = false;
  QString _infoBoxStrings;
  bool _labelhide = true;

  bool _highlight = false;
  QColor _highlightColor = QColor("green");
  QColor _highlightBoderColor = QColor("green");
  double _highlightBorderWidth = 2;
};

LayoutNode::LayoutNode(QObject* parent)
  : QObject(parent), _d(new Private)
{
  this->setObjectName("node");
}

LayoutNode::LayoutNode(const QString& name,
                       QObject *parent)
  : QObject(parent), prop::NameProperty(name), _d(new Private())
{
  this->setObjectName("node");
}

LayoutNode::~LayoutNode()
{
  delete this->_d;
}
//! NodeShape
void LayoutNode::setShape(const ShapeEnum& shape)
{
  this->_d->_shape=shape;
}
const ShapeEnum& LayoutNode::shape() const
{
  return this->_d->_shape;
}
//! ExternUuid
void LayoutNode::setExternUuid(const QUuid& newExternUuid)
{
  this->_d->_externUuid=newExternUuid;
}
const QUuid& LayoutNode::externUuid() const
{
  return this->_d->_externUuid;
}

//! NodeSize
void LayoutNode::setSize(const QSizeF& newSize)
{
  this->_d->_size=newSize;
}
const QSizeF& LayoutNode::size() const
{
  return this->_d->_size;
}
//! NodePos
void LayoutNode::setPos(const QPointF& newPos)
{
  this->_d->_pos=newPos;
}
const QPointF& LayoutNode::pos() const
{
  return this->_d->_pos;
}
//! NodeColor
void LayoutNode::setColor(const QColor& color)
{
  this->_d->_color=color;
}
const QColor& LayoutNode::color() const
{
  return this->_d->_color;
}
//! NodeBorderWidth
void LayoutNode::setBorderWidth(const double& width
                                )
{
  this->_d->_borderWidth=width;
}
const double& LayoutNode::borderWidth() const
{
  return this->_d->_borderWidth;
}
//! NodeBorderColor
void LayoutNode::setBorderColor(const QColor& color)
{
  this->_d->_borderColor=color;
}
const QColor& LayoutNode::borderColor() const
{
  return this->_d->_borderColor;
}

//! Label
void LayoutNode::setLabel(const QString& label)
{
  this->_d->_label=label;
}
const QString& LayoutNode::label() const
{
  return this->_d->_label;
}
//! LabelPos
void LayoutNode::setLabelPos(const QPointF& newPos)
{
  this->_d->_labelPos=newPos;
}
const QPointF& LayoutNode::labelPos() const
{
  return this->_d->_labelPos;
}
//! LabelTextSize
void LayoutNode::setLabelTextSize(const int& size)
{
  this->_d->_labelTextSize=size;
}
const int& LayoutNode::labelTextSize() const
{
  return this->_d->_labelTextSize;
}
//! LabelColor
void LayoutNode::setLabelColor(const QColor& color)
{
  this->_d->_labelColor=color;
}
const QColor& LayoutNode::labelColor() const
{
  return this->_d->_labelColor;
}

//! XLabel
void LayoutNode::setXLabel(const QString& xlabel)
{
  this->_d->_xlabel=xlabel;
}
const QString& LayoutNode::xLabel() const
{
  return this->_d->_xlabel;
}
//! XLabelColor
void LayoutNode::setXLabelColor(const QColor& color)
{
  this->_d->_xLabelColor=color;
}
const QColor& LayoutNode::xLabelColor() const
{
  return this->_d->_xLabelColor;
}
//! XLabelTextSize
void LayoutNode::setXLabelTextSize(const int& size)
{
  this->_d->_xLabelTextSize=size;
}
const int& LayoutNode::xLabelTextSize() const
{
  return this->_d->_xLabelTextSize;
}

//! SubNodes
LayoutNode* LayoutNode::addNode()
{
  LayoutNode* newLayoutNode = new LayoutNode(this);
  newLayoutNode->setParentNode(this);
  this->_d->_nodes.append(newLayoutNode);
  return newLayoutNode;
}
const QList<LayoutNode*>& LayoutNode::nodes() const
{
  return _d->_nodes;
}
LayoutNode* LayoutNode::firstSimpleNode(const bool& needtoken)
{
  for(LayoutNode* node : this->_d->_nodes){
    if(node->nodes().isEmpty()==false){
      continue;
    }else if(needtoken==true && node->token()==true){
      return node;
    }else if(needtoken==false){
      return node;
    }
  }
  for(LayoutNode* node : this->_d->_nodes){
    if(node->nodes().isEmpty()==false){
      LayoutNode* intnode = node->firstSimpleNode(needtoken);
      if(intnode!=nullptr){
        return intnode;
      }
    }
  }
  return nullptr;
}
//! Ports
LayoutNodePort* LayoutNode::addPort()
{
  LayoutNodePort* newLayoutNodePort=new LayoutNodePort();
  this->_d->_ports.append(newLayoutNodePort);
  return newLayoutNodePort;
}
const QList<LayoutNodePort*>& LayoutNode::ports() const
{
  return _d->_ports;
}
LayoutNodePort* LayoutNode::portByName(const QString& portName)
{
  return portByNameImpl(portName, this->_d->_ports);
}
LayoutNodePort* LayoutNode::portByNameImpl(const QString& portName, const QList<LayoutNodePort*>& portList)
{
  for(LayoutNodePort* currPort : portList)
  {
    if(currPort->name() == portName)
      return currPort;
  }

  return nullptr;
}
//! parentNode
void LayoutNode::setParentNode(LayoutNode* node)
{
  this->_d->_parentNode = node;
}
LayoutNode* LayoutNode::parentNode() const
{
  return this->_d->_parentNode;
}
//! staticLabel
void LayoutNode::setStaticLabels(bool wert)
{
  this->_d->_staticLabels = wert;
}
bool LayoutNode::staticLabels() const
{
  return this->_d->_staticLabels;
}
//! InfoBox
void LayoutNode::setShowInfobox(bool wert)
{
  this->_d->_showInfobox = wert;
}
bool LayoutNode::showInfobox() const
{
  return this->_d->_showInfobox;
}
void LayoutNode::setInfoBoxStrings(QString list)
{
  this->_d->_infoBoxStrings = list;
}
QString LayoutNode::infoBoxStrings() const
{
  return this->_d->_infoBoxStrings;
}
//! Token
void LayoutNode::setToken(bool wert)
{
  this->_d->_token = wert;
}
bool LayoutNode::token() const
{
  return this->_d->_token;
}
void LayoutNode::setTokenColor(QColor color)
{
  this->_d->_tokenColor = color;
}
QColor LayoutNode::tokenColor() const
{
  return this->_d->_tokenColor;
}
//!LabelHide
void LayoutNode::setHideLabel(bool wert)
{
  this->_d->_labelhide = wert;
}
bool LayoutNode::hideLabel() const
{
  return this->_d->_labelhide;
}
//!Highlighter
void LayoutNode::setHighlight(bool wert)
{
  this->_d->_highlight = wert;
}
bool LayoutNode::highlight() const
{
  return this->_d->_highlight;
}
void LayoutNode::setHighlightColor(QColor color)
{
  this->_d->_highlightColor = color;
}
QColor LayoutNode::highlightColor() const
{
  return this->_d->_highlightColor;
}
void LayoutNode::setHighlightBorderColor(QColor color)
{
  this->_d->_highlightBoderColor = color;
}
QColor LayoutNode::highlightBorderColor() const
{
  return this->_d->_highlightBoderColor;
}
void LayoutNode::setHighlightBorderWidth(double width)
{
  this->_d->_highlightBorderWidth = width;
}
double LayoutNode::highlightBorderWidth() const
{
  return this->_d->_highlightBorderWidth;
}
void LayoutNode::setFixedPos(bool wert)
{
  this->_d->_fixedPos=wert;
}
bool LayoutNode::fixedPos() const
{
  return this->_d->_fixedPos;
}
void LayoutNode::setAbsolutePos(const QPointF& value)
{
  this->_d->_absolutePos = value;
}
const QPointF& LayoutNode::absolutePos() const
{
  return this->_d->_absolutePos;
}


