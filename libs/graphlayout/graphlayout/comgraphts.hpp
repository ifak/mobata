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

#ifndef COMGRAPHTS
#define COMGRAPHTS

#include <graphlayout/layoutgraph.hpp>
#include <mobata/model/ts/ts.hpp>
#include "comcreatesutgraph.hpp"
#include <QDebug>

namespace graphlayout {

class ComGraphTS
{
public:
    ComGraphTS(LayoutGraph* graph, model::ts::TestSystemItem* tsItem);
    ~ComGraphTS(){}

    void setSutItemColor(const QColor& color);
    void setSutComponentColor(const QColor& color);
    void setSutPortColor(const QColor& color);
    void setTsComponentColor(const QColor& color);
    void setTsPortColor(const QColor& color);
    const QColor& sutItemColor();
    const QColor& sutComponentColor();
    const QColor& sutPortColor();
    const QColor& tsComponentColor();
    const QColor& tsPortColor();

    void execute();
private:
    LayoutGraph* _graph;
    model::ts::TestSystemItem* _tsItem;
    QColor _SutItemColor=QColor("lime");
    QColor _SutComponentColor=QColor("cyan");
    QColor _SutPortColor=QColor("red");
    QColor _TsComponentColor=QColor("lightblue");
    QColor _TsPortColor=QColor("white");
};
}
#endif
