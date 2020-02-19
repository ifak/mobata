#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QToolButton>

#include <mobatawidgets/graph/graph.hpp>

using namespace view::graph;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  Q_INIT_RESOURCE(mobata);

  this->ui->setupUi(this);
  this->ui->mainToolBar->addActions(this->ui->_graphView->allZoomActions());

  this->ui->_graphViewActionWidget->setLayout(new QHBoxLayout);

  QToolButton* zoomInViewButton=new QToolButton;
  zoomInViewButton->setIconSize(QSize(32,32));
  zoomInViewButton->setAutoRaise(true);
  zoomInViewButton->setDefaultAction(this->ui->_graphView->zoomFitInViewAction());
  zoomInViewButton->setAutoRepeat(true);
  this->ui->_graphViewActionWidget->layout()->addWidget(zoomInViewButton);

  QToolButton* zoomInButton=new QToolButton;
  zoomInButton->setIconSize(QSize(32,32));
  zoomInButton->setAutoRaise(true);
  zoomInButton->setDefaultAction(this->ui->_graphView->zoomInAction());
  zoomInButton->setAutoRepeat(true);
  this->ui->_graphViewActionWidget->layout()->addWidget(zoomInButton);

  QToolButton* zoomOutButton=new QToolButton;
  zoomOutButton->setIconSize(QSize(32,32));
  zoomOutButton->setAutoRaise(true);
  zoomOutButton->setDefaultAction(this->ui->_graphView->zoomOutAction());
  zoomOutButton->setAutoRepeat(true);
  this->ui->_graphViewActionWidget->layout()->addWidget(zoomOutButton);

  QToolButton* zoomResetButton=new QToolButton;
  zoomResetButton->setIconSize(QSize(32,32));
  zoomResetButton->setAutoRaise(true);
  zoomResetButton->setDefaultAction(this->ui->_graphView->zoomResetAction());
  zoomResetButton->setAutoRepeat(true);
  this->ui->_graphViewActionWidget->layout()->addWidget(zoomResetButton);

  GraphScene* graphScene=new GraphScene(this);
  this->ui->_graphView->setScene(graphScene);

  RectNode* rectNode=new RectNode("rect_node",
                                  NodeOptions().setSize(QSizeF(50,50)));
  graphScene->addItem(rectNode);
  rectNode->setPos(200, 100);

  RoundRectNode* roundRectNode=new RoundRectNode("round rect node",
                                                 NodeOptions().setSize(QSizeF(50,50)));
  graphScene->addItem(roundRectNode);
  roundRectNode->setPos(300, 100);

  //	TextEditWidget* textEditWidget=new TextEditWidget();
  //	graphScene->addItem(textEditWidget);
  //	roundRectNode->setPos(-100, 0);

  DirectedEdge* directEdge=new DirectedEdge(rectNode,
                                            roundRectNode,
                                            "direct edge");
  graphScene->addItem(directEdge);

  //	RoundRectNode* textEditNode=new RoundRectNode("widget node", NodeOptions().setSize(100,50));
  //	textEditNode->setWidget(new QTextEdit(), 10);
  //	graphScene->addItem(textEditNode);
  //	textEditNode->setPos(0,0);

  //	Edge* edge=new Edge(roundRectNode, textEditNode, "edge");
  //	graphScene->addItem(edge);

  this->ui->_graphView->updateSceneRect();
  this->ui->_graphView->update();
}

MainWindow::~MainWindow()
{
  delete ui;
}
