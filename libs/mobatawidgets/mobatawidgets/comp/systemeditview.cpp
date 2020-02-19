#include "systemeditview.hpp"

#include "systemview.hpp"

#include <QLayout>
#include <QToolBar>
#include <QActionGroup>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace view::comp;

class SystemEditView::Private
{

};

SystemEditView::SystemEditView(SystemScene* systemScene,
                               QWidget *parent) :
  QWidget(parent), _d(new Private())
{
  SystemView* systemView=new SystemView(systemScene,
                                                                this);

  QToolBar* editToolBar=new QToolBar(this);
  editToolBar->setOrientation(Qt::Vertical);
  editToolBar->addActions(systemView->systemViewActions());

  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(systemView);
  layout->addWidget(editToolBar);

  this->setLayout(layout);
}

SystemEditView::~SystemEditView()
{
  delete this->_d;
}
