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
