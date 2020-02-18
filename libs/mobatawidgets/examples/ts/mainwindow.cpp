#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <mobata/model/ts/ts.hpp>

#include <QTextEdit>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;

class MainWindow::Private
{
  friend class MainWindow;

  Private():_tsModel(0)
  {}

public:
  ~Private()
  {}

private:
  TestSuite* _tsModel;
};

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _d(new Private())
{
  ui->setupUi(this);
  this->buildTestModel();

  this->ui->_tsModelView->setModel(this->_d->_tsModel);

  this->ui->_tsModelView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
  this->ui->_tsModelView->expandAll();

  connect(this->ui->_tsModelView, SIGNAL(clicked(const QModelIndex&)),
          this, SLOT(currTestCaseItem(const QModelIndex&)));
}

MainWindow::~MainWindow()
{
  delete ui;
  delete this->_d;
}

void MainWindow::buildTestModel()
{
  this->_d->_tsModel=new model::ts::TestSuite();

  QString errorString;
  model::base::DataTypeItem* enumType=this->_d->_tsModel->addDataType("MyEnumType",
                                                                      &errorString);
  Q_ASSERT(enumType);
  enumType->setTypeEnum(prop::Enum);
  enumType->addLiteral("lit1");
  enumType->addLiteral("lit2");

  model::base::DataTypeItem* stringType=this->_d->_tsModel->addDataType("string",
                                                                        &errorString);
  Q_ASSERT(stringType);
  stringType->setTypeEnum(prop::String);

  model::base::SignalItem* signal=this->_d->_tsModel->addSignal("signal",
                                                                &errorString);
  Q_ASSERT(signal);
  model::base::ParamItem* paramItem=signal->addParameter("param", enumType->name(), &errorString);
  Q_ASSERT(paramItem);

  SutItem* sutItem=this->_d->_tsModel->sutItem();

  SutComponentItem* sutComp1=sutItem->addComponent<SutComponentItem>("sutComp1", &errorString);
  Q_ASSERT(sutComp1);
  PortItem* sutPort1=sutComp1->addPort("sutPort1", &errorString);
  Q_ASSERT(sutPort1);
  PortItem* sutPort2=sutComp1->addPort("sutPort2", &errorString);
  Q_ASSERT(sutPort2);

  //error
  PortItem* errorPort=sutComp1->addPort("sutPort1", &errorString);
  Q_ASSERT(errorPort==0);
  Q_ASSERT(errorString=="There is already a port 'sutPort1' available!");
  ///////////////////////////////////

  TestSystemItem* testSystem=this->_d->_tsModel->testSystemItem();
  Q_ASSERT(testSystem);
  TestComponentItem* testComp1=testSystem->addComponent<TestComponentItem>("testComp1",
                                                                           &errorString);
  PortItem* testCompPort1=testComp1->addPort("testCompPort1",
                                             &errorString);
  TestComponentItem* testComp2=testSystem->addComponent<TestComponentItem>("testComp2",
                                                                           &errorString);
  PortItem* testCompPort2=testComp2->addPort("testCompPort2", &errorString);

  ///error/////////
  //ComponentItem* errorTestComponent=testGroup1TestSystem->addComponent("testComp1",
  //                                                                     &errorString);
  //Q_ASSERT(errorTestComponent==0);
  //Q_ASSERT(errorString=="There is already a test component 'testComp1' available!");

  //errorPort=testComp1->addPort("testCompPort1", &errorString);
  //Q_ASSERT(errorPort==0);
  //Q_ASSERT(errorString=="There is already a port 'testCompPort1' available!");
  ///////////////////////

  TestCaseItem* testCase=this->_d->_tsModel->addTestCase("testCase1");

  ///only text-message
  MessageItem* message=testCase->addMessage(sutPort1, testCompPort1, "signal_in(x=0)");

  ///typed message
  message=testCase->addMessage(testCompPort2, sutPort2);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  testCase=this->_d->_tsModel->addTestCase("testCase2");

  message=testCase->addMessage(sutPort2, testCompPort2, "signal_out(y=25)");

  FragmentItem* altFragment=testCase->addFragment(model::msc::AlternativeFragment);

  FragmentRegionItem* cond1Region=altFragment->addRegion("condition 1");
  message=cond1Region->addMessage(testCompPort1, sutPort1);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit2");

  FragmentRegionItem* cond2Region=altFragment->addRegion("condition 2");
  message=cond2Region->addMessage(sutPort1, testCompPort2);
  message->setSignal(signal);
  message->addParamValue(signal->parameter("param"), "lit1");

  FragmentItem* loopFragment=cond2Region->addFragment(model::msc::LoopFragment);
  FragmentRegionItem* loopRegion=loopFragment->addRegion();
  message=loopRegion->addMessage(testCompPort1, sutPort2, "loop message");

  FragmentItem* loop2Fragment=loopRegion->addFragment(model::msc::LoopFragment);
  FragmentRegionItem* loop2Region=loop2Fragment->addRegion("loop statement");
  message=loop2Region->addMessage(sutPort1, testCompPort1, "inner loop message");

  message=testCase->addMessage(testCompPort2, sutPort1, "signal_out(x=10)");

  return;
}

void MainWindow::currTestCaseItem(const QModelIndex &currTsModelIndex)
{
  if(!currTsModelIndex.isValid())
    return;

  QStandardItem* currItem=this->_d->_tsModel->itemFromIndex(currTsModelIndex);
  if(TestCaseItem* testCase=dynamic_cast<TestCaseItem*>(currItem))
  {
    if(!testCase->parent()->parent()->parent()->parent())
      this->ui->_testCaseTabWidget->setCurrentTestCase(testCase);
  }

  return;
}
