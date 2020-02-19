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

#include <QDomNode>
#include <QJsonObject>
#include "modtrace_global.h"

namespace modtrace{

class MODTRACESHARED_EXPORT ComCreateModeTrace
{
public:
  ComCreateModeTrace(const QString& spenatTraceFilePath,
                     const QString& atsFilePath,
                     const QString& targetPath,
                     const QString& filename=QString());
  bool execute(QString* errorString);

private:
  bool saveToJsonFile(QString* errorString);
  bool readAttribute(const QDomNode& node, const QString& attribute, QString* property, QString* errorString);
  bool readRequirements(const QString& arrayKey, const QJsonObject& jsonObject, QString* errorString);
  void mergeRequirementsLists(const QStringList& reqList, const QString& jsonTestcaseName);

  Q_DISABLE_COPY(ComCreateModeTrace)
  class Private;
  Private* _d;
};

}//end of namespace modtrace
