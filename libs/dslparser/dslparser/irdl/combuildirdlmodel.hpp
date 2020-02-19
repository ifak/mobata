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

namespace model{
namespace base {
    class ModelItem;
    class SignalItem;
}
namespace irdl{
class RequirementsModel;
}
namespace msc{
class MscComponentItem;
class MscTimerItem;
}
}

namespace dslparser {
namespace irdl{

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;
typedef QHash<QString, model::irdl::RequirementsModel*> ImportModel;

class DSLPARSERSHARED_EXPORT ComBuildIrdlModel
    : public QObject
{
public:
  ComBuildIrdlModel(const QString& irdlDocText,
                            model::irdl::RequirementsModel* irdlDeclModel,
                            const QString& prefix = QStringLiteral(""),
                            bool strictErrorHandling = true,
                            QObject* parent =0);
  virtual ~ComBuildIrdlModel();

public:
  virtual bool  execute(QString* errorString = 0, bool deleteOldModel = true);

public:
  const DslErrorList&  errors() const;

public:
  const TokenTextLocations&               keywordTextLocations() const;
  const ModelTextLocations&               modelTextLocations() const;
  model::irdl::RequirementsModel* irdlDeclModel();

  QPair<model::base::ModelItem*,int>            currentPathItem();
  const model::base::SignalItem*                currentSignalItem();
  const QHash<QString, const model::msc::MscComponentItem *> &requirementCompItems();
  const ImportModelItem&                        importItems();
  const ImportModel&                            importModels();
  const QHash<QString,const model::msc::MscTimerItem *>     timerItems();



private:
  Q_DISABLE_COPY(ComBuildIrdlModel)
  class Private;
  Private* _d;
};

}//namespace irdl
} // namespace dslparser
