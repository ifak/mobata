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

#include "../dslparser_global.hpp"
#include "../dslparser_types.hpp"
#include "../dslerror.hpp"

namespace model{
namespace spenat{
  class SpenatDeclModel;
  class PlaceItem;
  class TransitionItem;
}
}

#include <QObject>

namespace dslparser {
namespace spenat{

class DSLPARSERSHARED_EXPORT ComBuildSpenatFile
        : public QObject
{
public:
    ComBuildSpenatFile(const QString& filePath,
                       const model::spenat::SpenatDeclModel* spenatDeclModel,
                       QObject* parent = nullptr);

    virtual ~ComBuildSpenatFile();

    //converts model to a text declaration and saves it to a file
    virtual bool  execute(QString* errorString = 0);
    //converts model to a text declaration only
    QString  toDocText();

    const DslErrorList&  errors() const;

private:
    void spenatDecl(QString* content, int tabCount = 0);
    void placeDecl(QString* content, const model::spenat::PlaceItem* model, int tabCount);
    void transitionDecl(QString* content, const model::spenat::TransitionItem* model, int tabCount);

    Q_DISABLE_COPY(ComBuildSpenatFile)
    class Private;
    Private* _d;
};

}//namespace statemachine
} // namespace dslparser
