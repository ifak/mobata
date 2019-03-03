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

#include <QObject>

namespace model {
namespace ts{class TestCaseItem;
             class SutItem;
                          class TestSystemItem;}
namespace base{class ModelItem;}
}

namespace dslparser {
namespace testcase{

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;

class DSLPARSERSHARED_EXPORT ComBuildTestCaseModel
    : public QObject
{
public:
  ComBuildTestCaseModel(const QString& testCaseDocText,
                        model::ts::TestCaseItem* testCaseDeclModel,
                        const QString& praefix = QStringLiteral(""),
                        bool strictErrorHandling = true,
                        QObject* parent = 0);
  virtual ~ComBuildTestCaseModel();

public:
  virtual bool  execute(QString* errorString = 0);

public:
  const DslErrorList&       errors() const;
  const TokenTextLocations& keywordTextLocations() const;
  const ModelTextLocations& modelTextLocations() const;
  const QString&            importedSutFile() const;
  const QString&            importedTestSystemFile() const;

public:
  const QHash<QString, model::base::ModelItem*>&  testCaseItems();
  QPair<model::base::ModelItem *, int>            currentPathItem();
  model::base::ModelItem*                         currentSignalItem();
  const ImportModelItem&                          importItems();

private:
  Q_DISABLE_COPY(ComBuildTestCaseModel)
  class Private;
  Private* _d;
};

}//namespace testcase
} // namespace dslparser
