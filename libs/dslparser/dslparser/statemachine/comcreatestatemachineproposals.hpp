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
#include "../dslproposal.hpp"

#include <QObject>

namespace model{ namespace statemachine{
class StateMachineModel;
class AbstractStateItem;
}}

namespace dslparser {
namespace statemachine{

class DSLPARSERSHARED_EXPORT ComCreateStateMachineProposals
    : public QObject
{
public:
  explicit ComCreateStateMachineProposals(const QString& statemachineDocText,
                                    model::statemachine::StateMachineModel* statemachineModel = 0,
                                    bool strictErrorHandling = true,
                                    QObject* parent = 0);
  virtual ~ComCreateStateMachineProposals();

public:
  bool                    execute(QString* errorString);
  const DslProposalList&  statemachineProposals() const;

private:
  Q_DISABLE_COPY(ComCreateStateMachineProposals)
  class Private;
  Private* _d;
};

}// namespace statemachine
} // namespace dslparser
