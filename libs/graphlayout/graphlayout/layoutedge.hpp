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
#include "layoutnode.hpp"
#include "layoutnodeport.hpp"
#include <QObject>
#include <QDebug>
#include <QPointF>
#include "types.hpp"

#include <mobata/prop/uuidproperty.hpp>
#include <mobata/prop/nameproperty.hpp>

namespace graphlayout{

class GRAPHLAYOUTSHARED_EXPORT LayoutNode;

class LayoutEdge
    : public QObject,
    public PropPointsD,
    public prop::NameProperty,
    public prop::UuidProperty
{
public:
    LayoutEdge(LayoutNode const* source,
               LayoutNode const* target,
               QObject* parent = nullptr);

    LayoutEdge(const QString& name,
               LayoutNode const* source,
               LayoutNode const* target,
               QObject* parent = nullptr);

    virtual ~LayoutEdge();
public:
    // edge
    LayoutNode const* source() const;
    void setSourcePort(LayoutNodePort *port);
    const LayoutNodePort* sourcePort() const;
    LayoutNode const* target() const;
    void setTargetPort(LayoutNodePort *port);
    LayoutNodePort const* targetPort() const;
    // ExternUuid
    void setExternUuid(const QUuid& newExternUuid);
    const QUuid& externUuid() const;
    // Color
    void setColor(const QColor& color);
    const QColor& color() const;
    // Type
    void setType(const ArrowEnum& type);
    const ArrowEnum& type() const;
    // ControlPoints
    const QList<QPointF*>& points() const;
    void addPoint(QPointF point);
    void clearPoints();
    //lineWidth
    void setLineWidth(const double& width);
    const double& lineWidth() const;
    //arrowSize
    void setArrowsize(const int& size);
    const int& Arrowsize() const;
    //! Label
    // Label
    void setLabel(const QString& label);
    const QString& label() const;
    // LabelPos
    void setLabelPos(const QPointF& labelPos);
    const QPointF& labelPos() const;
    // LabelColor
    void setLabelColor(const QColor& color);
    const QColor& labelColor() const;
    //LabelTextSize
    void setLabelTextSize(const int& labelTextSize);
    const int& labelTextSize() const;
    //! InfoBox
    void setShowInfobox(bool wert);
    bool showInfobox() const;
    void setInfoBoxStrings(QString list);
    QString infoBoxStrings() const;
    //! Highlight
    void setHighlight(bool wert);
    bool highlight() const;
    void setHighlightColor(QColor color);
    QColor highlightColor() const;
    //! Graphviz parameter
    // Constraint
    void setConstraint(bool constraint);
    bool constraint() const;
    // Weight
    void setWeight(int weight);
    int weight() const;
    // MinLen
    void setMinLen(double minLen);
    double minLen() const;
    // Rank
    void setRank(QString rank);
    QString rank() const;
    // staticLabel
    void setStaticLabel(bool wert);
    bool staticLabel() const;
protected:
    class Private;
    Private* _d;
};

}/////////end namespace graphlayout
