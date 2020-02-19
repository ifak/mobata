#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(mobata);
  
  QApplication a(argc, argv);
	MainWindow w;
    //w.resize(800,600);
	w.show();
	
	return a.exec();
}
