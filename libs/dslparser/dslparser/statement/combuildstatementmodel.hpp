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

namespace model{ namespace base{ namespace statement{
class StatementModel;
class RootStatementModel;
class AttributeAssignStatementmodel;
class ConditionStatementModel;
class FunctioncallStatementmodel;
class SendToStatementmodel;
class SwitchStatementModel;
}}
namespace statemachine {
class StateMachineModel;
}
}

namespace dslparser {
namespace base{

class DSLPARSERSHARED_EXPORT ComBuildStatementModel
    : public QObject
{
public:
  ComBuildStatementModel(const QString& statementDocText,
                            const model::statemachine::StateMachineModel* wholeModel,
                            model::base::statement::RootStatementModel* statementDeclModel,
                            const QString& prefix = QStringLiteral(""),
                            bool strictErrorHandling = true,
                            QObject* parent = nullptr);
  virtual ~ComBuildStatementModel();

public:
  virtual bool  execute(QString* errorString = nullptr);

public:
  const DslErrorList&  errors() const;

public:
  model::base::statement::StatementModel* statementDeclModel();

private:
  Q_DISABLE_COPY(ComBuildStatementModel)
  class Private;
  Private* _d;
};

}//namespace base
} // namespace dslparser
