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

#ifndef LAYOUTGLOBAL_HPP
#define LAYOUTGLOBAL_HPP

#include <QString>
#include <QMetaObject>

namespace graphlayout {
enum GraphvizAlgorithm
{
    Circo,
    Dot,
    Fdp,
    Neato,
    Osage,
    Sfdp,
    Twopi,
    NoGraphviz
};
inline QString GraphvizAlgorithmToString(GraphvizAlgorithm algorithm){
    switch(algorithm){
    case Dot:
        return "dot";
    case Circo:
        return "circo";
    case Fdp:
        return "fdp";
    case Neato:
        return "neato";
    case Osage:
        return "osage";
    case Sfdp:
        return "sfdp";
    case Twopi:
        return "twopi";
    default:
        return "dot";
    }
}
inline GraphvizAlgorithm GraphvizAlgorithmFromString(QString algorithm){
    if(algorithm.contains("Dot",Qt::CaseInsensitive))
        return Dot;
    if(algorithm.contains("Circo",Qt::CaseInsensitive))
        return Circo;
    if(algorithm.contains("Sfdp",Qt::CaseInsensitive))
        return Sfdp;
    if(algorithm.contains("Fdp",Qt::CaseInsensitive))
        return Fdp;
    if(algorithm.contains("Neato",Qt::CaseInsensitive))
        return Neato;
    if(algorithm.contains("Osage",Qt::CaseInsensitive))
        return Osage;
    if(algorithm.contains("Twopi",Qt::CaseInsensitive))
        return Twopi;
    return Dot;
}
enum ShapeEnum
{
    Rect,
    RoundedRect,
    Ellipse,
    Point,
    Circle,
    Diamond,
    Parallelogram,
    Triangle,
    InvTriangle,
    Trapezium,
    InvTrapezium,
    Octagon,
    Hexagon,
    Square,
    Box3d,
    Plaintext
};
inline QString ShapeEnumToString(ShapeEnum shape){
    switch(shape){
    case Rect:
        return "rect";
    case RoundedRect:
        return "roundedRect";
    case Ellipse:
        return "ellipse";
    case Point:
        return "point";
    case Circle:
        return "circle";
    case Diamond:
        return "diamond";
    case Parallelogram:
        return "parallelogram";
    case Triangle:
        return "triangle";
    case InvTriangle:
        return "invtriangle";
    case Trapezium:
        return "trapezium";
    case InvTrapezium:
        return "invtrapezium";
    case Octagon:
        return "octagon";
    case Hexagon:
        return "hexagon";
    case Square:
        return "square";
    case Box3d:
        return "box3d";
    case Plaintext:
        return "plaintext";
    default:
        return "rect";
    }
}
inline ShapeEnum ShapeEnumFromString(QString shape){
    if(shape.contains("RoundedRect",Qt::CaseInsensitive))
        return RoundedRect;
    if(shape.contains("Rect",Qt::CaseInsensitive))
        return Rect;
    if(shape.contains("Ellipse",Qt::CaseInsensitive))
        return Ellipse;
    if(shape.contains("Point",Qt::CaseInsensitive))
        return Point;
    if(shape.contains("Circle",Qt::CaseInsensitive))
        return Circle;
    if(shape.contains("Diamond",Qt::CaseInsensitive))
        return Diamond;
    if(shape.contains("Parallelogram",Qt::CaseInsensitive))
        return Parallelogram;
    if(shape.contains("InvTriangle",Qt::CaseInsensitive))
        return InvTriangle;
    if(shape.contains("Triangle",Qt::CaseInsensitive))
        return Triangle;
    if(shape.contains("InvTrapezium",Qt::CaseInsensitive))
        return InvTrapezium;
    if(shape.contains("Trapezium",Qt::CaseInsensitive))
        return Trapezium;
    if(shape.contains("Octagon",Qt::CaseInsensitive))
        return Octagon;
    if(shape.contains("Hexagon",Qt::CaseInsensitive))
        return Hexagon;
    if(shape.contains("Square",Qt::CaseInsensitive))
        return Square;
    if(shape.contains("Box3d",Qt::CaseInsensitive))
        return Box3d;
    if(shape.contains("Plaintext",Qt::CaseInsensitive))
        return Plaintext;
    return Rect;
}
enum ArrowEnum
{
    Arrow,
    Line,
    DoubleArrow,
    BackArrow,
    Box,
    Invisible
};
inline QString ArrowEnumToString(ArrowEnum arrow){
    switch(arrow){
    case Arrow:
        return "Arrow";
    case Line:
        return "Line";
    case DoubleArrow:
        return "DoubleArrow";
    case BackArrow:
        return "BackArrow";
    case Box:
        return "Box";
    case Invisible:
        return "Invisible";
    default:
        return "Arrow";
    }
}
inline ArrowEnum ArrowEnumFromString(QString arrow){
    if(arrow.contains("DoubleArrow",Qt::CaseInsensitive))
        return DoubleArrow;
    if(arrow.contains("BackArrow",Qt::CaseInsensitive))
        return BackArrow;
    if(arrow.contains("Arrow",Qt::CaseInsensitive))
        return Arrow;
    if(arrow.contains("Line",Qt::CaseInsensitive))
        return Line;
    if(arrow.contains("Box",Qt::CaseInsensitive))
        return Box;
    if(arrow.contains("Invisible",Qt::CaseInsensitive))
        return Invisible;
    return Arrow;
}
enum SplineEnum
{
    none,
    line,
    spline,
    ortho,
    polyline,
    curved,
    straight
};
inline QString SplineEnumToString(SplineEnum splines){
    switch(splines){
    case none:
        return "none";
    case line:
        return "line";
    case spline:
        return "spline";
    case ortho:
        return "ortho";
    case polyline:
        return "polyline";
    case curved:
        return "curved";
    case straight:
        return "straight";
    default:
        return "line";
    }
}
inline SplineEnum SplineEnumFromString(QString splines){
    if(splines.contains("none",Qt::CaseInsensitive))
        return none;
    if(splines.contains("spline",Qt::CaseInsensitive))
        return spline;
    if(splines.contains("polyline",Qt::CaseInsensitive))
        return polyline;
    if(splines.contains("line",Qt::CaseInsensitive))
        return line;
    if(splines.contains("ortho",Qt::CaseInsensitive))
        return ortho;
    if(splines.contains("curved",Qt::CaseInsensitive))
        return curved;
    if(splines.contains("straight",Qt::CaseInsensitive))
        return straight;
    return line;
}
enum OverlapEnum
{
    default0,
    scale,
    prism,
    prism0,
    voronoi,
    vpsc,
    orthoxy,
    allowed
};
inline QString OverlapEnumToString(OverlapEnum overlap){
    switch(overlap){
    case default0:
        return "default";
    case scale:
        return "scale";
    case prism:
        return "prism";
    case prism0:
        return "prism0";
    case voronoi:
        return "voronoi";
    case vpsc:
        return "vpsc";
    case orthoxy:
        return "ortho";
    case allowed:
        return "true";
    default:
        return "default";
    }
}
inline OverlapEnum OverlapEnumFromString(QString overlap){
    if(overlap.contains("default",Qt::CaseInsensitive))
        return default0;
    if(overlap.contains("scale",Qt::CaseInsensitive))
        return scale;
    if(overlap.contains("prism0",Qt::CaseInsensitive))
        return prism0;
    if(overlap.contains("prism",Qt::CaseInsensitive))
        return prism;
    if(overlap.contains("voronoi",Qt::CaseInsensitive))
        return voronoi;
    if(overlap.contains("vpsc",Qt::CaseInsensitive))
        return vpsc;
    if(overlap.contains("ortho",Qt::CaseInsensitive))
        return orthoxy;
    if(overlap.contains("true",Qt::CaseInsensitive))
        return allowed;
    return default0;
}
}
#endif
