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

#include "importrhapsody/importrhapsody_global.hpp"

#include <QDialog>

class QStandardItemModel;

namespace model{
namespace statemachine{
class StateMachineModel;
}
}

namespace rhapsody{
struct RhapsodyPointer;
}

namespace Ui {
class RhapsodySelectionView;
}

class RhapsodySelectionView : public QDialog
{
  Q_OBJECT

public:
  explicit RhapsodySelectionView(QWidget *parent = nullptr,
                                 const QString &projectFilePath = nullptr,
                                 model::statemachine::StateMachineModel* _smModel = nullptr);
  ~RhapsodySelectionView();

  bool initExec(QString *errorMessage);

private slots:
  void importRhapsodyStatechart();
  void treeViewIndexChange(const QModelIndex &index);
  void cancelImport();

private:
  Q_DISABLE_COPY(RhapsodySelectionView)
  bool updateTreeView(QString* errorMessage);
  void resetTreeViewModel();

  Ui::RhapsodySelectionView *ui;
  QString _projectFilePath;
  QStandardItemModel* _standardItemModel;
  model::statemachine::StateMachineModel* _stateMachineModel;
  QList<QString> _pathList;
  rhapsody::RhapsodyPointer* _r;
};
