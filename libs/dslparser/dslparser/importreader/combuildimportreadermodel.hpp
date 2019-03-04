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

#include <QObject>

#include "../dslerror.hpp"

namespace dslparser {
namespace importreader{


class ComBuildImportReaderModel
    : public QObject
{
public:
  ComBuildImportReaderModel(const QString& importDocText,
                            const QString& prefix);
  virtual ~ComBuildImportReaderModel();

public:
  bool                          execute(QString* errorMessage);
  const QHash<QString,QString>& importedFiles();
  const DslErrorList&           errors() const;

private:
  Q_DISABLE_COPY(ComBuildImportReaderModel)
  class Private;
  Private* _d;
};

}
}
