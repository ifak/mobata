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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <graphlayout/mscquickwidget.hpp>
#include <mobata/model/msc/msc.hpp>
#include <QtWidgets>

class MainWindow: public QObject
{
    Q_OBJECT
public:
    MainWindow();
public slots:
    void refreshView();
private:
    graphlayout::MscQuickWidget* _widget;
    QTimer* _timer;

    int _counter = 0;

    QUuid _uuid1;
    QUuid _uuid2;
    QUuid _uuid3;
};

#endif // MAINWINDOW_H
