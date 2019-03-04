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
}
namespace irdl{
class RequirementsModel;
}
namespace msc{
class MscComponentItem;
}
}

namespace dslparser {
namespace irdl{

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;
typedef QHash<QString, model::irdl::RequirementsModel*> ImportModel;

class DSLPARSERSHARED_EXPORT ComBuildIrdlDeclModel
    : public QObject
{
public:
  ComBuildIrdlDeclModel(const QString& irdldeclDocText,
                            model::irdl::RequirementsModel* IrdlCommonDeclModel,
                            const QString& prefix = QStringLiteral(""),
                            bool strictErrorHandling = true,
                            QObject* parent =0);
  virtual ~ComBuildIrdlDeclModel();

public:
  virtual bool  execute(QString* errorString = 0);

public:
  const DslErrorList&  errors() const;

public:
  const TokenTextLocations&               keywordTextLocations() const;
  const ModelTextLocations&               modelTextLocations() const;
  model::irdl::RequirementsModel* IrdlCommonDeclModel();

  QPair<model::base::ModelItem*,int>            currentPathItem();
  model::base::ModelItem*                       currentSignalItem();
  const QHash<QString, model::msc::MscComponentItem *> &requirementCompItems();
  const ImportModelItem&                        importItems();
  const ImportModel&                            importModels();



private:
  Q_DISABLE_COPY(ComBuildIrdlDeclModel)
  class Private;
  Private* _d;
};

}//namespace irdldecl
} // namespace dslparser
