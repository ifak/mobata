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
#include "layoutgraph.hpp"
#include <QTextStream>
#include <QString>

namespace graphlayout{

class LayoutGraph;
class LayoutNode;

class GRAPHLAYOUTSHARED_EXPORT ComCreateGraphvizFile
{
public:
    ComCreateGraphvizFile(LayoutGraph const* layoutGraph);
    ~ComCreateGraphvizFile();

public:
    void            execute(QTextStream &graphvizFileStream);
    LayoutNode*     layoutNode(const QString& graphvizNodeName) const;
    QString const*  graphvizNodeName(LayoutNode* layoutNode) const;
    void setAlgorithm(GraphvizAlgorithm algorithm);
    void nodes(QList<LayoutNode*> list, QTextStream &graphvizFileStream);
    void setFixed(bool wert);
private:
    class Private;
    Private* _d;
};

}//end namespace graphlayout
