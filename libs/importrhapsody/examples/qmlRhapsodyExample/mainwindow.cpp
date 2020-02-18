#include <graphlayout/qmlgraphview.hpp>
#include <graphlayout/comcreatestatemachinegraph.hpp>
#include <graphlayout/graphquickwidget.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>

#include <QQuickWidget>
#include <QHBoxLayout>
#include <QQuickItem>
#include <QPushButton>
#include <QQmlEngine>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "rhapsodyimportproject.hpp"
#include "rhapsodyselectionview.hpp"

using namespace rhapsody;

MainWindow::MainWindow(QWidget *parent) :
  QWidget(parent),
  _graphwidget(nullptr),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->_smModel = new model::statemachine::StateMachineModel();

  connect(this->ui->importPushButton, SIGNAL(clicked()), this, SLOT(importFromRhapsody()));
  connect(this->ui->zoomInPushButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
  connect(this->ui->zoomOutPushButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
}

MainWindow::~MainWindow()
{
  delete ui;
  delete _smModel;
}

void MainWindow::importFromRhapsody()
{ 
  if(this->_smModel != nullptr){
    delete this->_smModel;
    this->_smModel = new model::statemachine::StateMachineModel();
  }
  if(this->_graphwidget != nullptr)
    delete this->_graphwidget;

  RhapsodyImportProject importProject(this);
  if(importProject.exec() == 0)
    return;

  QString errorMessage;
  RhapsodySelectionView selectionView(this,
                                      importProject.projectFilePath,
                                      this->_smModel);
  if(!selectionView.initExec(&errorMessage)){
    qWarning() << errorMessage.toLatin1();
    return;
  }

  this->ui->treeView->reset();
  this->ui->treeView->setModel(this->_smModel);

  graphlayout::LayoutGraph* graph = new graphlayout::LayoutGraph("StateMachine Chart");
  graphlayout::ComCreateStateMachineGraph comGraph(graph,this->_smModel);
  QString error;
  if(!comGraph.execute(&error)){
    qDebug() << error.toLatin1();
    return;
  }

  Q_INIT_RESOURCE(graphlayout);

  this->_graphwidget = new graphlayout::GraphQuickWidget(graph,graphlayout::NoGraphviz);
  this->_graphwidget->resize(QSize(500,500));
  this->_graphwidget->show();
  this->ui->verticalLayout->addWidget(this->_graphwidget);
  if(!this->_graphwidget->layout(&error)){
    qDebug() << error.toLatin1();
    return;
  }

}

void MainWindow::zoomIn()
{
  QQuickItem* root = this->_graphwidget->rootObject();
  QQuickItem* item = root->findChild<QQuickItem*>("zoomObject");
  item->setScale(item->scale()*1.1);
}

void MainWindow::zoomOut()
{
  QQuickItem* root = this->_graphwidget->rootObject();
  QQuickItem* item = root->findChild<QQuickItem*>("zoomObject");
  item->setScale(item->scale()*0.90909090909);
}
