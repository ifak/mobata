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

#include <QString>
#include <QScopedPointer>

namespace view{namespace spenat{class DeclScene;}}

namespace graphlayout
{

class GRAPHLAYOUTSHARED_EXPORT ComLayoutDeclScene
{
public:
    ComLayoutDeclScene(view::spenat::DeclScene *declScene,
                       const QString &graphvizPath);
    ~ComLayoutDeclScene();

public:
    bool execute(QString* errorString);

private:
    Q_DISABLE_COPY(ComLayoutDeclScene)
    class Private;
    Private*  _d;
};

}/// end namespace graphlayout
