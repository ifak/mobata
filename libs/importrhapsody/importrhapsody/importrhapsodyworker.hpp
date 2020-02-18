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
#include "importrhapsody_global.hpp"

namespace rhapsody{

struct RhapsodyWorkerData
{
  IRPApplicationPtr appPtr;
  IRPProjectPtr projectPtr;
};

class ImportRhapsodyWorker: public QObject
{
  Q_OBJECT
public:
  explicit ImportRhapsodyWorker(const QString& projectFilePath);
  virtual ~ImportRhapsodyWorker();

public slots:
  bool process(QString *errorMessage);
  void startRhapsody(QString* errorMessage);

signals:
  void sendResultData(IStream* appStream, IStream* projectStream, bool error);

private:
  QString _projectFilePath;
  class Private;
  Private* _d;
};

} //end of namespace rhapsody

Q_DECLARE_METATYPE(rhapsody::RhapsodyWorkerData*)
