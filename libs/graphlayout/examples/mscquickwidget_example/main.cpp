#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainwindow.hpp"

using namespace model::msc;

int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(graphlayout);

  QApplication app(argc, argv);

  MainWindow w;

  return app.exec();
}

