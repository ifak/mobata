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
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "settings.h"

#include <QTreeView>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void buildTestModel();
  void renderTestModel();

private slots:
  void currModelItem(const QModelIndex& currTsModelIndex);
  void sutOptionsChangedSignalReceiver();
  void testsystemOptionsChangedSignalReceiver();
  void activateButtons();
  void testEventHandler(const QModelIndex& index);
  void cancelHandler();
  void submitHandler();
  void configWidgetOpenerHandler();

signals:
  void sutSettingsChanged(QStandardItemModel *model);
  void testsystemSettingsChanged(QStandardItemModel *model);

private:
	Ui::MainWindow *ui;
  class Private;
  Private* _d;
  QTreeView *configView;
  QHBoxLayout *configApplicationLayout;
  QPushButton *button_cancel;
  QPushButton *button_ok;
  QSpacerItem *configSpacer;
};

#endif // MAINWINDOW_HPP
