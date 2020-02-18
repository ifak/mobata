#include <QApplication>
#include <QQmlApplicationEngine>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(mobata);
  Q_INIT_RESOURCE(importrhapsody);

  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication a(argc, argv);
  MainWindow w;
  w.resize(1200,600);
  w.show();

  return a.exec();
}
