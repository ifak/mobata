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

#include "modsim_global.hpp"

#include <dslparser/statement/combuildstatementmodel.hpp>

#include <QDomDocument>

namespace model {
namespace statemachine {
class StateMachineModel;
}
}

namespace modsim{

class MODSIMSHARED_EXPORT ComScxmlWriter
{
public:
  explicit ComScxmlWriter(const model::statemachine::StateMachineModel* stateMachine);
  ~ComScxmlWriter();

  bool generateDomDocument();
  bool writeScxml(QIODevice *device, QString *errorString);

private:
  bool addJs(QString filename,QString *errorString);
//  const QDomDocument& getDocument();
//  QString scxmlBaseDocument();
//  QString scxmlStatemachine();
//  QString errors();

private:
  class Private;
  Private* _d;

};

} //end namespace modsim
