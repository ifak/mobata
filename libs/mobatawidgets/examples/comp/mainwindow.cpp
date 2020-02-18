#include "mainwindow.hpp"

#include <mobatawidgets/comp/systemscene.hpp>

#include <QLayout>
#include <QDebug>

#include "systemeditview.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace view::comp;

class MainWindow::Private
{
  friend class MainWindow;
  
  Private()
    : _systemScene(0)
  {}
  
  SystemScene* _systemScene;
};

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), _d(new Private())
{
  this->_d->_systemScene=new SystemScene();
  
  SystemEditView* systemEditView=new SystemEditView(this->_d->_systemScene,
                                                    this);
  this->setCentralWidget(systemEditView);
}

MainWindow::~MainWindow()
{
  delete this->_d->_systemScene;
  delete this->_d;
}
