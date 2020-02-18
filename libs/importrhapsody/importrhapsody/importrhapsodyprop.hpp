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

#include <mobata/model/statemachine/types.hpp>
#include "importrhapsody_global.hpp"

namespace rhapsody {

struct RhapsodyPointer;

class ImportRhapsodyElements;

class ImportRhapsodyProp : private QObject
{
  Q_OBJECT
public:
  explicit ImportRhapsodyProp();

  virtual ~ImportRhapsodyProp();

public slots:
  void receiveResultData(IStream* appStream, IStream* projectStream, bool error);

signals:
  void startWorker(QString* errorMessage);
  void stopWorker();
  void release();

protected:
  bool initCom(QString* errorMessage);

  bool loadRhapsodyProjectMain(RhapsodyPointer* rhapsodyPointer,
                               const QString &projectFilePath,
                               QString* errorMessage);

  bool loadRhapsodyProjectInstance(IRPProjectPtr &rhapsodyProject,
                                   QString* errorMessage);

  bool loadRhapsodyProjectFile(RhapsodyPointer *rhapsodyPointer,
                               const QString& projectFilePath, QString* errorMessage);

  bool loadRhapsodyStatechart(IRPProjectPtr& rhapsodyproject,
                              model::statemachine::StateMachineModel *smModel,
                              const QList<QString> &importPath,
                              QString* errorMessage);

  bool importRhapsodyEvents(IRPProjectPtr& rhapsodyProject,
                            model::statemachine::StateMachineModel *smModel,
                            ImportRhapsodyElements *importElements,
                            QString* errorMessage);

  bool importRhapsodyStates(model::statemachine::StateMachineModel *smModel,
                            ImportRhapsodyElements *importElements,
                            QString* errorMessage);

  bool importRhapsodyTransitions(model::statemachine::StateMachineModel *smModel,
                                 ImportRhapsodyElements *importElements,
                                 QString* errorMessage);

  bool importRhapsodyDataTypes(IRPProjectPtr& rhapsodyProject,
                               model::statemachine::StateMachineModel *smModel,
                               ImportRhapsodyElements *importElements,
                               QString* errorMessage);

  bool importRhapsodyAttributes(model::statemachine::StateMachineModel *smModel,
                                ImportRhapsodyElements *importElements,
                                QString* errorMessage);

  bool importRhapsodyOperations(model::statemachine::StateMachineModel* smModel,
                                ImportRhapsodyElements* importElements,
                                QString* errorMessage);

  bool importRhapsodyPorts(model::statemachine::StateMachineModel *smModel,
                           ImportRhapsodyElements *importElements,
                           QString* errorMessage);

  IStream* _projectStream;
  IStream* _applicationStream;

  Q_DISABLE_COPY(ImportRhapsodyProp)
  class Private;
  Private* _d;
};

} // namespace rhapsody
