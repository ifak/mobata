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
