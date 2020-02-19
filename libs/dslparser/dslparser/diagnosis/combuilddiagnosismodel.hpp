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
namespace diagnosis{class DiagnosisItem;}
namespace base{class BaseModel;class ModelItem;}
}

namespace dslparser {
namespace diagnosis{

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;

class DSLPARSERSHARED_EXPORT ComBuildDiagnosisModel
    : public QObject
{
public:
  ComBuildDiagnosisModel(const QString& diagnosisDocText,
                        model::diagnosis::DiagnosisItem* diagnosisDeclModel,
                        const QString& praefix = QStringLiteral(""),
                        bool strictErrorHandling = true,
                        QObject* parent = 0);
  virtual ~ComBuildDiagnosisModel();

public:
  enum FileType{
    Complete,
    Signals,
    Components
};

  virtual bool  execute(QString* errorString = 0,FileType type = Complete);

public:
  const DslErrorList&       errors() const;
  const TokenTextLocations& keywordTextLocations() const;
  const ModelTextLocations& modelTextLocations() const;
  const QString&            importedSutFile() const;
  const QString&            importedTestSystemFile() const;

public:
  const QHash<QString, model::base::ModelItem*>&  diagnosisItems();
  model::base::ModelItem*                         currentPathItem();
  model::base::ModelItem*                         currentSignalItem();
  const ImportModelItem&                          importItems();

private:
  Q_DISABLE_COPY(ComBuildDiagnosisModel)
  class Private;
  Private* _d;
};

}//namespace diagnosis
} // namespace dslparser
