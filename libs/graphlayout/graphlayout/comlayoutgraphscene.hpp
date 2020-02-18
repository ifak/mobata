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

#include <QObject>

class QDir;

namespace model{ namespace graph{ class IGraph;}}

namespace view {namespace graph { class GraphScene;}}

namespace graphlayout
{

class GRAPHLAYOUTSHARED_EXPORT ComLayoutGraphScene
        : public QObject
{
    Q_OBJECT

public:
    explicit ComLayoutGraphScene(view::graph::GraphScene* graphScene,
                                 const QDir &graphvizBinDir,
                                 QObject* parent = 0);
    virtual ~ComLayoutGraphScene();

public:
    bool execute(QString* errorString);

private:
    Q_DISABLE_COPY(ComLayoutGraphScene)
    class Private;
    Private* _d;
};

} // namespace graphlayout
