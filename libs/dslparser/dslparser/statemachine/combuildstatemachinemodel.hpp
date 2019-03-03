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
namespace statemachine{
class StateMachineModel;
class AbstractStateItem;
}}

namespace dslparser {
namespace statemachine{

class DSLPARSERSHARED_EXPORT ComBuildStateMachineModel
    : public QObject
{
public:
  ComBuildStateMachineModel(const QString& statemachineDocText,
                            model::statemachine::StateMachineModel* statemachineDeclModel,
                            const QString& prefix = QStringLiteral(""),
                            bool strictErrorHandling = true,
                            QObject* parent =0);
  virtual ~ComBuildStateMachineModel();

public:
  virtual bool  execute(QString* errorString = 0);

public:
  const DslErrorList&  errors() const;

public:
  const TokenTextLocations&               keywordTextLocations() const;
  const ModelTextLocations&               modelTextLocations() const;
  model::statemachine::StateMachineModel* statemachineDeclModel();

  model::statemachine::AbstractStateItem*       currentStatePathItem();
  const model::base::SignalItem*                currentSignalItem();
private:
  Q_DISABLE_COPY(ComBuildStateMachineModel)
  class Private;
  Private* _d;
};

}//namespace statemachine
} // namespace dslparser
