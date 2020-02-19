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

namespace model{ namespace spenat{ class SpenatModel;}}

namespace view {namespace spenat {class SpenatScene;}}

class QDir;

namespace graphlayout
{

class GRAPHLAYOUTSHARED_EXPORT ComLayoutSpenatModel
        : public QObject
{
    Q_OBJECT

public:
    explicit ComLayoutSpenatModel(model::spenat::SpenatModel const*spenatModel,
                                  view::spenat::SpenatScene* spenatScene,
                                  const QDir &graphvizBinDir);
    virtual ~ComLayoutSpenatModel();

public:
    bool execute(QString* errorString);

private:
    Q_DISABLE_COPY(ComLayoutSpenatModel)
    class Private;
    Private* _d;
};

} // namespace graphlayout
