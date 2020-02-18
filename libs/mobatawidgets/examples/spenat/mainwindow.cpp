#include "mainwindow.hpp"

#include <mobatawidgets/spenat/declgrapheditview.hpp>
#include <mobatawidgets/spenat/declscene.hpp>

#include <QLayout>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace view::spenat;

class MainWindow::Private
{
  friend class MainWindow;
  
  Private()
    : _declScene(0)
  {}
  
  DeclScene* _declScene;
};

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), _d(new Private())
{
  this->_d->_declScene=new DeclScene();
  
  DeclGraphEditView* declGraphEditView=new DeclGraphEditView(this);
  declGraphEditView->setDeclGraphScene(this->_d->_declScene);
  this->setCentralWidget(declGraphEditView);
}

MainWindow::~MainWindow()
{
  delete this->_d->_declScene;
  delete this->_d;
}
