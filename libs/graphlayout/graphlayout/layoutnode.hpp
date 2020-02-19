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

#include "graphlayout_global.hpp"
#include "layoutglobal.hpp"
#include "layoutnodeport.hpp"
#include <QObject>
#include <QFont>
#include <QPointF>
#include <QColor>
#include <QSizeF>
#include "types.hpp"

#include <mobata/prop/nameproperty.hpp>
#include <mobata/prop/uuidproperty.hpp>

namespace graphlayout{

class GRAPHLAYOUTSHARED_EXPORT LayoutNode
    : public QObject,
    public prop::NameProperty,
    public prop::UuidProperty
{
public:
  LayoutNode(QObject *parent = 0);
  LayoutNode(const QString& name,
             QObject *parent = 0);
  virtual ~LayoutNode();

public:
  // NodeShape
  void setShape(const ShapeEnum& shape);
  const ShapeEnum& shape() const;
  // ExternUuid
  void setExternUuid(const QUuid &newExternUuid);
  const QUuid& externUuid() const;

  // NodeSize
  void setSize(const QSizeF& newSize);
  const QSizeF& size() const;
  // NodePos
  void setPos(const QPointF& newPos);
  const QPointF& pos() const;
  // NodeColor
  void setColor(const QColor& color);
  const QColor& color() const;
  // NodeBorderWidth
  void setBorderWidth(const double& width);
  const double& borderWidth() const;
  // NodeBorderColor
  void setBorderColor(const QColor& color);
  const QColor& borderColor() const;

  // Label
  void setLabel(const QString& label);
  const QString& label() const;
  // LabelPos
  void setLabelPos(const QPointF& newPos);
  const QPointF& labelPos() const;
  // LabelTextSize
  void setLabelTextSize(const int& size);
  const int& labelTextSize() const;
  // LabelColor
  void setLabelColor(const QColor& color);
  const QColor& labelColor() const;

  // XLabel
  void setXLabel(const QString& xlabel);
  const QString& xLabel() const;
  // XLabelColor
  void setXLabelColor(const QColor& color);
  const QColor& xLabelColor() const;
  // XLabelTextSize
  void setXLabelTextSize(const int& size);
  const int& xLabelTextSize() const;

  // SubNodes
  LayoutNode* addNode();
  const QList<LayoutNode*>& nodes() const;
  LayoutNode* firstSimpleNode(const bool& needtoken=false);
  // Ports
  LayoutNodePort* addPort();
  const QList<LayoutNodePort*>& ports() const;
  LayoutNodePort* portByName(const QString& portName);
  LayoutNodePort* portByNameImpl(const QString& portName,
                                 const QList<LayoutNodePort*>& portList);
  // parentNode
  void setParentNode(LayoutNode* node);
  LayoutNode* parentNode() const;
  // staticLabel
  void setStaticLabels(bool wert);
  bool staticLabels() const;
  // InfoBox
  void setShowInfobox(bool wert);
  bool showInfobox() const;
  void setInfoBoxStrings(QString list);
  QString infoBoxStrings() const;
  //token
  void setToken(bool wert);
  bool token() const;
  void setTokenColor(QColor color);
  QColor tokenColor() const;
  //LabelHide
  void setHideLabel(bool wert);
  bool hideLabel() const;
  //Highlight
  void setHighlight(bool wert);
  bool highlight() const;
  void setHighlightColor(QColor color);
  QColor highlightColor() const;
  void setHighlightBorderColor(QColor color);
  QColor highlightBorderColor() const;
  void setHighlightBorderWidth(double width);
  double highlightBorderWidth() const;
  //fixed Position
  void setFixedPos(bool wert);
  bool fixedPos() const;
  //absolute or relative Position
  void setAbsolutePos(const QPointF &value);
  const QPointF& absolutePos() const;


protected:
  class Private;
  Private* _d;
};

}/////////end namespace graphlayout
