#include "declgrapheditview.hpp"
#include "ui_declgrapheditview.h"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

class DeclGraphEditView::Private
{
	friend class DeclGraphEditView;
	
	Private()
	{}
	
public:
	~Private()
	{}
};

DeclGraphEditView::DeclGraphEditView(QWidget *parent)
	:	QWidget(parent),	_d(new Private()), _ui(new Ui::DeclGraphEditView)
{
	this->_ui->setupUi(this);
	
	this->_ui->_selectButton->setDefaultAction(this->_ui->_declGraphView->selectAction());
	this->_ui->_addPlaceButton->setDefaultAction(this->_ui->_declGraphView->addPlaceAction());
	this->_ui->_addTransButton->setDefaultAction(this->_ui->_declGraphView->addTransitionAction());
	this->_ui->_addJunctionButton->setDefaultAction(this->_ui->_declGraphView->addJunctionAction());
	this->_ui->_addArcButton->setDefaultAction(this->_ui->_declGraphView->addArcAction());
	this->_ui->_initMarkingButton->setDefaultAction(this->_ui->_declGraphView->initMarkingAction());
	
}

DeclGraphEditView::~DeclGraphEditView()
{
	delete this->_ui;
}

DeclScene* DeclGraphEditView::declGraphScene()
{
	return this->_ui->_declGraphView->declGraphScene();
}

void DeclGraphEditView::setDeclGraphScene(DeclScene *declGraphScene)
{
	this->_ui->_declGraphView->setDeclGraphScene(declGraphScene);
	
  return;
}

QAction* DeclGraphEditView::zoomInAction()
{
  return this->_ui->_declGraphView->zoomInAction();
}

QAction* DeclGraphEditView::zoomOutAction()
{
  return this->_ui->_declGraphView->zoomOutAction();
}

QAction* DeclGraphEditView::zoomFitInViewAction()
{
  return this->_ui->_declGraphView->zoomFitInViewAction();
}

QAction* DeclGraphEditView::zoomResetAction()
{
  return this->_ui->_declGraphView->zoomResetAction();
}

QList<QAction*> DeclGraphEditView::allZoomActions()
{
  return this->_ui->_declGraphView->allZoomActions();
}

void DeclGraphEditView::reset()
{
	return this->_ui->_declGraphView->reset();
}

void DeclGraphEditView::zoomIn()
{
  this->_ui->_declGraphView->zoomIn();
  
  return;
}

void DeclGraphEditView::zoomOut()
{
  this->_ui->_declGraphView->zoomOut();
  
  return;
}

void DeclGraphEditView::zoomInView()
{
  this->_ui->_declGraphView->zoomInView();
  
  return;
}

void DeclGraphEditView::zoomReset()
{
  this->_ui->_declGraphView->zoomReset();
  
  return;
}

	}///end namespace spenat
	}///end namespace view
