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

#include <QString>
#include <QJsonArray>
#include <QJsonDocument>

namespace convert{
namespace statemachine{

class ConvertTrace
{
public:

  enum HierarchyType
  {
    StateMachineRoot,
    CompositeChild,
    ConcurrentChild
  };

  ConvertTrace(const QString modelName, const QString tracePath);

  virtual ~ConvertTrace();

  QJsonDocument createJsonDocument(QString* errorString);
  bool loadStatemachineTrace(QString smTraceDoc, QString* errorString);
  bool loadStatemachineTraceFromFile(QString* errorString);
  bool appendPlaceTrace(const QString placeName, QString* errorString);
  bool appendTransitionTrace(QString spenatTransName, const QStringList smTransitionNameList);
  void copyRequirements(const QJsonArray smRequirements, QJsonArray& spenatRequirements);

private:

  class Private;
  Private* _d;
};

} //end namespace statemachine
} //end namespace convert
