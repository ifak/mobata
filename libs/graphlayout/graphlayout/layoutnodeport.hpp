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
#include <QObject>
#include <QPointF>
#include <QColor>
#include <QSizeF>
#include "types.hpp"
#include <mobata/prop/nameproperty.hpp>
#include <mobata/prop/uuidproperty.hpp>

namespace graphlayout{

class GRAPHLAYOUTSHARED_EXPORT LayoutNodePort
    : public QObject,
    public prop::NameProperty,
    public prop::UuidProperty
{
public:
    LayoutNodePort(QObject *parent = 0);
    virtual ~LayoutNodePort();

public:
    void setExternUuid(const QUuid &newExternUuid);
    const QUuid& externUuid() const;
    void setPos(const QPointF& newPos);
    const QPointF& pos() const;
    void setSize(const QSizeF& newSize);
    const QSizeF& size() const;
    void setLabel(const QString& label);
    const QString& label() const;
    void setLabelPos(const QPointF& newPos);
    const QPointF& labelPos() const;
    void setLabelSize(const float& size);
    const float& labelSize() const;
    void setType(const QString& type);
    const QString& type() const;
    void setColor(const QColor& color);
    const QColor& color() const;
    void setShape(const ShapeEnum& shape);
    const ShapeEnum& shape() const;

protected:
    class Private;
    Private* _d;
};

}/////////end namespace graphlayout
