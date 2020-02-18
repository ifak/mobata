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

#include <QDir>

namespace model{ namespace spenat{ class SpenatDeclModel;}}

namespace view {namespace spenat{ class DeclScene;}}

namespace graphlayout
{

class GRAPHLAYOUTSHARED_EXPORT ComLayoutDeclModel
        : public QObject
{
    Q_OBJECT

public:
    explicit ComLayoutDeclModel(model::spenat::SpenatDeclModel const* declModel,
                                view::spenat::DeclScene* declScene,
                                const QDir& graphvizBinDir=QDir());
    virtual ~ComLayoutDeclModel();

public:
    bool execute(QString* errorString);

private:
    Q_DISABLE_COPY(ComLayoutDeclModel)
    class Private;
    Private* _d;
};

} // namespace graphlayout
