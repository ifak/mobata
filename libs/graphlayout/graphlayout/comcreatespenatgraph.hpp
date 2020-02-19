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

#include <graphlayout/layoutgraph.hpp>

#include <mobata/model/base/signaltriggeritem.hpp>

#include <mobata/model/spenat/spenatmodel.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/spenat/junctionitem.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/postplacearc.hpp>
#include <mobata/model/spenat/preplacearc.hpp>

#include <QDebug>

namespace graphlayout {

class ComCreateSpenatGraph
{
public:
    ComCreateSpenatGraph(LayoutGraph* graph, model::spenat::SpenatBaseModel const* spenat);
    ~ComCreateSpenatGraph(){}

public:
    bool execute(QString* errorString);

public:
    ShapeEnum initPlaceShape()                  {return _initPlaceShape;}
    void setInitPlaceShape(ShapeEnum shape)     {_initPlaceShape=shape;}
    QColor initPlaceColor()                     {return _initPlaceColor;}
    void setInitPlaceColor(QColor color)        {_initPlaceColor=color;}
    ShapeEnum placeShape()                      {return _placeShape;}
    void setPlaceShape(ShapeEnum shape)         {_placeShape=shape;}
    QColor placeColor()                         {return _placeColor;}
    void setPlaceColor(QColor color)            {_placeColor=color;}
    ShapeEnum transitionShape()                 {return _transitionShape;}
    void setTransitionShape(ShapeEnum shape)    {_transitionShape=shape;}
    QColor transitionColor()                    {return _transitionColor;}
    void setTransitionColor(QColor color)       {_transitionColor=color;}
    QColor arcWithTransitionColor()             {return _arcWithTransitionColor;}
    void setArcWithTransitionColor(QColor color){_arcWithTransitionColor=color;}
    QColor arcColor()                           {return _arcColor;}
    void setArcColor(QColor color)              {_arcColor=color;}

private:
    LayoutGraph* _graph;
    model::spenat::SpenatBaseModel const* _spenat;

    OverlapEnum _overlap = default0;
    SplineEnum _splines = polyline;

    ShapeEnum _initPlaceShape = Diamond;
    QColor _initPlaceColor = QColor("white");
    ShapeEnum _placeShape = RoundedRect;
    QColor _placeColor = QColor("white");
    ShapeEnum _transitionShape = Rect;
    QColor _transitionColor = QColor("white");
    QColor _arcWithTransitionColor = QColor("blue");
    QColor _arcColor = QColor("black");
};
}
