#include "systemeditview.hpp"

#include <mobatawidgets/comp/systemview.hpp>

#include <QLayout>
#include <QToolBar>
#include <QActionGroup>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

class SystemEditView::Private
{

};

SystemEditView::SystemEditView(view::comp::SystemScene* systemScene,
                               QWidget *parent) :
  QWidget(parent), _d(new Private())
{
  view::comp::SystemView* systemView=new view::comp::SystemView(systemScene,
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

