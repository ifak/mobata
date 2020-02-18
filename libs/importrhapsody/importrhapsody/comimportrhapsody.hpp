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

#include <mobata/model/statemachine/types.hpp>
#include "importrhapsody_global.hpp"
#include "importrhapsodyprop.hpp"

namespace rhapsody {

struct RhapsodyPointer;

class ImportRhapsodyElements;

class ComImportRhapsody
    : private ImportRhapsodyProp
{
public:
  ComImportRhapsody(RhapsodyPointer* rhapsodyPointer,
                    model::statemachine::StateMachineModel* stateMachineModel,
                    const QString& rhapsodyProjectName,
                    const QList<QString>& rhapsodyImportPath,
                    QMap<QString, QString>* rules=nullptr);

  virtual ~ComImportRhapsody();

public:
  bool execute(QString* errorMessage = 0);

private:
  Q_DISABLE_COPY(ComImportRhapsody)
  class Private;
  Private* _d;
};

} // namespace rhapsody
