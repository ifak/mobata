#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/paramvalueitem.hpp>
#include <mobata/model/base/componentitem.hpp>
#include <mobata/model/base/portitem.hpp>

#include <mobata/model/msc/mscmodel.hpp>
#include <mobata/model/msc/mscsequence.hpp>
#include <mobata/model/msc/mscmessageitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>

#include <QTextEdit>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace model::msc;

class MainWindow::Private
{
  friend class MainWindow;

  Private():_mscModel(0)
  {}

public:
  ~Private()
  {}

private:
  MscModel* _mscModel;
};

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _d(new Private())
{
  ui->setupUi(this);
  this->buildMscModel();

  this->ui->_mscModelView->setModel(this->_d->_mscModel);

  this->ui->_mscModelView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
  this->ui->_mscModelView->expandAll();

  connect(this->ui->_mscModelView, SIGNAL(clicked(const QModelIndex&)),
          this, SLOT(currMscSequItem(const QModelIndex&)));
}

MainWindow::~MainWindow()
{
  delete ui;
  delete this->_d->_mscModel;
}

void MainWindow::buildMscModel()
{
  delete this->_d->_mscModel;
  this->_d->_mscModel=new model::msc::MscModel();

  QString errorString;
  model::base::DataTypeItem* enumType=this->_d->_mscModel->addDataType("MyEnumType",
                                                                       QUuid::createUuid(),
                                                                       &errorString);
  Q_ASSERT(enumType);
  enumType->setTypeEnum(prop::Enum);
  enumType->addLiteral("lit1");
  enumType->addLiteral("lit2");

  model::base::DataTypeItem* stringType=this->_d->_mscModel->addDataType("string",
                                                                         QUuid::createUuid(),
                                                                         &errorString);
  Q_ASSERT(stringType);
  stringType->setTypeEnum(prop::String);

  model::base::SignalItem* signal=this->_d->_mscModel->addSignal("signal",
                                                                 &errorString);
  Q_ASSERT(signal);
  model::base::ParamItem* paramItem=signal->addParameter("param", enumType->name(), &errorString);
  Q_ASSERT(paramItem);

  MscComponentItem* comp1=this->_d->_mscModel->addComponent("comp1",
                                                            &errorString);
  Q_ASSERT(comp1);
  PortItem* port1=comp1->addPort("port", &errorString);
  Q_ASSERT(port1);

  //error
  PortItem* wrong_port=comp1->addPort("port", &errorString);
  Q_ASSERT(wrong_port==0);
  Q_ASSERT(errorString=="There is already a port "
                        "'port' available!");
  ///////////////////////////////////

  MscComponentItem* comp2=this->_d->_mscModel->addComponent("comp2",
                                                            &errorString);
  Q_ASSERT(comp2);
  PortItem* port2=comp2->addPort("port", &errorString);
  Q_ASSERT(port2);

  MscSequence* sequ1=this->_d->_mscModel->addSequence("sequ1");

  ///only text-message
  MscMessageItem* message=sequ1->addMessage(port1, port2, "signal_in(x=0)");

  ///typed message
  message=sequ1->addMessage(port2, port1);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  MscSequence* sequ2=this->_d->_mscModel->addSequence("sequ2");
  message=sequ2->addMessage(port2, port1, "signal_out(y=25)");

  MscFragmentItem* altFragment=sequ2->addFragment(AlternativeFragment);
  MscFragmentRegionItem* cond1Region=altFragment->addRegion("condition 1");
  message=cond1Region->addMessage(port1, port2);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit2");

  MscFragmentRegionItem* cond2Region=altFragment->addRegion("condition 2");
  message=cond2Region->addMessage(port2, port1);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  message=sequ2->addMessage(port1, port2, "signal_end(here are the params ...)");

  MscSequence* sequ3=this->_d->_mscModel->addSequence("sequ3");

  message=sequ3->addMessage(port2, port1, "signal_out(y=25)");

  altFragment=sequ3->addFragment(AlternativeFragment);
  cond1Region=altFragment->addRegion("condition 1");
  message=cond1Region->addMessage(port1, port2);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit2");

  cond2Region=altFragment->addRegion("condition 2");
  message=cond2Region->addMessage(port2, port1);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  MscFragmentItem* loopFragment=cond2Region->addFragment(LoopFragment);
  MscFragmentRegionItem* loopRegion=loopFragment->addRegion();
  message=loopRegion->addMessage(port1, port2, "loop message");

  MscFragmentItem* loop2Fragment=loopRegion->addFragment(LoopFragment);
  MscFragmentRegionItem* loop2Region=loop2Fragment->addRegion("loop statement");
  message=loop2Region->addMessage(port2, port1, "inner loop message");

  message=sequ3->addMessage(port1, port2, "signal_end(here are the params ...)");

  return;
}

void MainWindow::currMscSequItem(const QModelIndex &currMscModelIndex)
{
  if(!currMscModelIndex.isValid())
    return;

  QStandardItem* currItem=this->_d->_mscModel->itemFromIndex(currMscModelIndex);
  if(MscSequence* mscSequence=dynamic_cast<MscSequence*>(currItem))
  {
    if(!mscSequence->parent()->parent())
      this->ui->_mscTabWidget->currentMscSequenceSlot(mscSequence);
  }

  return;
}
