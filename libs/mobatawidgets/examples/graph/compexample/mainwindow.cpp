#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <view/graph/comp/comp.hpp>

using namespace graph;


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	QGraphicsScene* compScene=new QGraphicsScene(this);
	this->ui->_compView->setScene(compScene);
	
	comp::KComponent* comp_1=new comp::KComponent("comp_1",
																								NodeOptions().setSize(QSizeF(100,100)));
	compScene->addItem(comp_1);
	comp_1->setPos(-200, 0);
	comp::KPort* p_1=comp_1->addPort(QPointF(-175,0), "p_1");
	
	comp::KComponent* comp_2=new comp::KComponent("comp_2",
																								NodeOptions().setSize(QSizeF(100,100)));
	compScene->addItem(comp_2);
	comp_2->setPos(200, 0);
	comp::KPort* p_2=comp_2->addPort(QPointF(175,0), "p_2");
	
	comp::KLink* link_1=new comp::KLink(p_1, p_2, "link from p_1 to p_2");
	compScene->addItem(link_1);
}

MainWindow::~MainWindow()
{
	delete ui;
}
