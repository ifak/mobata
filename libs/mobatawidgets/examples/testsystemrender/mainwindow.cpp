#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "configdelegate.h"

#include <mobata/model/ts/ts.hpp>
#include <mobatawidgets/ts/testsystemscene.hpp>
#include <mobatawidgets/ts/comrendersut.hpp>
#include <mobatawidgets/ts/comrendertestsystem.hpp>

#include <QColorDialog>

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace view::ts;

class MainWindow::Private
{
  friend class MainWindow;

  Private():_tsModel(0), _isReadyToRenderSut(true), _isReadyToRenderTestsystem(true), _isConfigWidgetOpen(false)
  {}

public:
  ~Private()
  {}

private:
  TestSuite*          _tsModel;
  TestSystemScene*    _testSystemScene;
  QModelIndex         _currentTsModelIndex;
  QStandardItemModel* _configModel;
  ConfigDelegate*     _configDelegate;
  Settings*           _sutSettings;
  Settings*           _testsystemSettings;
  bool                _isReadyToRenderSut;
  bool                _isReadyToRenderTestsystem;
  bool                _isConfigWidgetOpen;
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

  connect(this->ui->_tsModelView, &QTreeView::clicked,
          this, &MainWindow::currModelItem);

  this->_d->_sutSettings = new Settings(this, QString("SUT"), QString("testsystemrenderexample"));
  view::ts::NodeOptions defaultSutCompOptions = view::ts::ComRenderSut::defaultComponentOptions();
  defaultSutCompOptions.setTextFont(QFont("Sans Serif", 8)).setColor(Qt::darkGreen).setPen(QPen(Qt::darkBlue, 3)).setSize(QSizeF(100,75));
  this->_d->_sutSettings->addNodeTypeSettings(QString("Components"), defaultSutCompOptions);
  view::ts::NodeOptions defaultSutPortOptions = view::ts::ComRenderSut::defaultPortOptions();
  this->_d->_sutSettings->addNodeTypeSettings(QString("Ports"), defaultSutPortOptions);
  view::ts::ArcOptions defaultSutLinkOptions = view::ts::ComRenderSut::defaultLinkOptions();
  this->_d->_sutSettings->addArcTypeSettings(QString("Links"), defaultSutLinkOptions);
  QVariant defaultSutBoxColor = view::ts::ComRenderSut::defaultSutBoxBrushOption().color().name();
  this->_d->_sutSettings->addMiscSettings(QString("SUT Box Color"), defaultSutBoxColor, QString("BRUSHCOLOR"));
  this->_d->_sutSettings->addMiscSettings(QString("Component Margin"), view::ts::ComRenderSut::defaultCompMarginSpace(), QString("LENGTH"));
  this->_d->_sutSettings->addMiscSettings(QString("SUT Box Margin"), view::ts::ComRenderSut::defaultSutBoxMarginSpace(), QString("LENGTH"));
  this->_d->_sutSettings->addMiscSettings(QString("SUT Box Radius"), view::ts::ComRenderSut::defaultSutBoxRadius(), QString("LENGTH"));
  this->_d->_sutSettings->readAllSettingsFromConfigFile();

  this->_d->_testsystemSettings = new Settings(this, QString("Testsystem"), QString("testsystemrenderexample"));
  view::ts::NodeOptions defaultTestSystemCompOptions = view::ts::ComRenderTestSystem::defaultTestSystemCompOptions();
  defaultTestSystemCompOptions.setTextFont(QFont("Sans Serif", 8));
  this->_d->_testsystemSettings->addNodeTypeSettings(QString("Components"), defaultTestSystemCompOptions);
  view::ts::NodeOptions defaultTestSystemPortOptions = view::ts::ComRenderTestSystem::defaultTestSystemPortOptions();
  this->_d->_testsystemSettings->addNodeTypeSettings(QString("Ports"), defaultTestSystemPortOptions);
  view::ts::ArcOptions defaultTestSystemLinkOptions = view::ts::ComRenderTestSystem::defaultTestSystemLinkOptions();
  this->_d->_testsystemSettings->addArcTypeSettings(QString("Links"), defaultTestSystemLinkOptions);
  this->_d->_testsystemSettings->addMiscSettings(QString("Space to SUT Box"), view::ts::ComRenderTestSystem::defaultSpaceToSutBox(), QString("LENGTH"));
  view::ts::NodeOptions defaultTestSystemBoxOptions = view::ts::ComRenderTestSystem::defaultTestSystemBoxOptions();
  defaultTestSystemBoxOptions.setTextFont(QFont("Serif", 12, QFont::Bold));
  this->_d->_testsystemSettings->addNodeTypeSettings(QString("Testsystem Box"), defaultTestSystemBoxOptions);
  this->_d->_testsystemSettings->addMiscSettings(QString("Testsystem Box Margin"), view::ts::ComRenderTestSystem::defaultTestSystemBoxMarginSpace(), QString("LENGTH"));
  this->_d->_testsystemSettings->addMiscSettings(QString("Testsystem Box Radius"), view::ts::ComRenderTestSystem::defaultTestSystemBoxRadius(), QString("LENGTH"));
  this->_d->_testsystemSettings->readAllSettingsFromConfigFile();

  this->_d->_testSystemScene=new TestSystemScene(this);
  this->_d->_testSystemScene->setTestSystemNotation(this->_d->_tsModel->testSystemItem()->name());
  this->ui->_testSystemRenderView->setScene(this->_d->_testSystemScene);

  configView = new QTreeView(this);
  configView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
  ui->verticalLayout_2->addWidget(configView);
  configView->setMinimumWidth(275);
  configView->setMaximumWidth(525);
  configView->hide();
  configApplicationLayout = new QHBoxLayout(this);
  ui->verticalLayout_2->addLayout(configApplicationLayout);
  configSpacer = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
  configApplicationLayout->addSpacerItem(configSpacer);
  button_cancel = new QPushButton(this);
  button_cancel->setText("Cancel");
  button_cancel->setEnabled(false);
  configApplicationLayout->addWidget(button_cancel);
  button_cancel->hide();
  button_ok = new QPushButton(this);
  button_ok->setText("Apply");
  button_ok->setEnabled(false);
  configApplicationLayout->addWidget(button_ok);
  button_ok->hide();

  ui->verticalLayoutWidget->setMaximumWidth(0);

  this->_d->_configModel = new QStandardItemModel(this);
  this->_d->_configModel->setColumnCount(2);
  this->_d->_configModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Characteristic")));
  this->_d->_configModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Value")));
  this->_d->_configModel->appendRow(this->_d->_sutSettings->exportAllPropertiesToQStandardItem());
  this->_d->_configModel->appendRow(this->_d->_testsystemSettings->exportAllPropertiesToQStandardItem());
  configView->setModel(this->_d->_configModel);

  this->_d->_configDelegate = new ConfigDelegate(this);
  configView->setItemDelegateForColumn(1, this->_d->_configDelegate);
  configView->expandAll();
  configView->resizeColumnToContents(0);
  int maxWidthColumn1 = configView->width() - configView->columnWidth(0);
  configView->setColumnWidth(1, (75 > maxWidthColumn1)?(75-25):(maxWidthColumn1-25));

  connect(this->_d->_configDelegate, SIGNAL(commitData(QWidget*)), this, SLOT(activateButtons()));

  connect(configView, SIGNAL(clicked(QModelIndex)), this, SLOT(testEventHandler(QModelIndex)));
  connect(this, SIGNAL(sutSettingsChanged(QStandardItemModel*)), this->_d->_sutSettings, SLOT(synchronizeOptions(QStandardItemModel*)));
  connect(this, SIGNAL(testsystemSettingsChanged(QStandardItemModel*)), this->_d->_testsystemSettings, SLOT(synchronizeOptions(QStandardItemModel*)));
  connect(this->_d->_sutSettings, SIGNAL(optionsChanged()), this, SLOT(sutOptionsChangedSignalReceiver()));
  connect(this->_d->_testsystemSettings, SIGNAL(optionsChanged()), this, SLOT(testsystemOptionsChangedSignalReceiver()));
  connect(button_cancel, SIGNAL(clicked()), this, SLOT(cancelHandler()));
  connect(button_ok, SIGNAL(clicked()), this, SLOT(submitHandler()));

  connect(this->ui->pushButton_opener, SIGNAL(clicked()), this, SLOT(configWidgetOpenerHandler()));
}

MainWindow::~MainWindow()
{
  delete ui;
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

  //sut
  SutItem* sutItem=this->_d->_tsModel->sutItem();
  sutItem->setName("Stupid SUT Example");

  SutComponentItem* sutComp1=sutItem->addComponent<SutComponentItem>("sutComp1", &errorString);
  Q_ASSERT(sutComp1);
  PortItem* sutComp1Port1=sutComp1->addPort("sutPort1", &errorString);
  Q_ASSERT(sutComp1Port1);
  PortItem* sutComp1Port2=sutComp1->addPort("sutPort2", &errorString);
  Q_ASSERT(sutComp1Port2);
  //  PortItem* sutComp1Port3=sutComp1->addPort("sutPort3", &errorString);
  //  Q_ASSERT(sutComp1Port3);
  //  PortItem* sutComp1Port4=sutComp1->addPort("sutPort4", &errorString);
  //  Q_ASSERT(sutComp1Port4);

  ///error
  PortItem* errorPort=sutComp1->addPort("sutPort1", &errorString);
  Q_ASSERT(errorPort==0);
  Q_ASSERT(errorString=="There is already a port 'sutPort1' available!");

  SutComponentItem* sutComp2=sutItem->addComponent<SutComponentItem>("sutComp2", &errorString);
  Q_ASSERT(sutComp2);
  PortItem* sutComp2Port1=sutComp2->addPort("sutPort1", &errorString);
  Q_ASSERT(sutComp2Port1);
  PortItem* sutComp2Port2=sutComp2->addPort("sutPort2", &errorString);
  Q_ASSERT(sutComp2Port2);

  SutComponentItem* sutComp3=sutItem->addComponent<SutComponentItem>("sutComp3", &errorString);
  Q_ASSERT(sutComp3);
  PortItem* sutComp3Port1=sutComp3->addPort("sutPort1", &errorString);
  Q_ASSERT(sutComp3Port1);
  PortItem* sutComp3Port2=sutComp3->addPort("sutPort2", &errorString);
  Q_ASSERT(sutComp3Port2);

  LinkItem* sutLink1=sutItem->addLink(sutComp1Port2, sutComp3Port1, &errorString);
  Q_ASSERT(sutLink1);
  LinkItem* sutLink2=sutItem->addLink(sutComp3Port2, sutComp2Port1, &errorString);
  Q_ASSERT(sutLink2);

  ///test-system///////////////
  TestSystemItem* testSystemItem=this->_d->_tsModel->testSystemItem();
  testSystemItem->setName("Stupid Test System Example");
  TestComponentItem* testComp1=testSystemItem->addComponent<TestComponentItem>("testComp1",
                                                                               &errorString);
  ///error/////////
  errorString=QStringLiteral("");
  TestComponentItem* errorTestComponent=testSystemItem->addComponent<TestComponentItem>("testComp1",
                                                                                        &errorString);
  Q_ASSERT(errorTestComponent==0);
  Q_ASSERT(errorString=="There is already a component 'testComp1' available!");

  PortItem* testComp1Port=testComp1->addPort("port",
                                             &errorString);
  Q_ASSERT(testComp1Port);

  ///port error///////////
  errorString=QStringLiteral("");
  errorPort=testComp1->addPort("port", &errorString);
  Q_ASSERT(errorPort==0);
  Q_ASSERT(errorString=="There is already a port 'port' available!");

  ///component 2//////////////////////
  TestComponentItem* testComp2=testSystemItem->addComponent<TestComponentItem>("testComp2",
                                                                               &errorString);
  PortItem* testComp2Port=testComp2->addPort("port", &errorString);
  Q_ASSERT(testComp2Port);

  ///component 3//////////////////////
  TestComponentItem* testComp3=testSystemItem->addComponent<TestComponentItem>("testComp3",
                                                                               &errorString);
  PortItem* testComp3Port=testComp3->addPort("port", &errorString);
  Q_ASSERT(testComp3Port);

  ///component 4//////////////////////
  TestComponentItem* testComp4=testSystemItem->addComponent<TestComponentItem>("testComp4",
                                                                               &errorString);
  PortItem* testComp4Port=testComp4->addPort("port", &errorString);
  Q_ASSERT(testComp4Port);

  /////// test - system - links ////////////////
  errorString=QStringLiteral("");
  LinkItem* testLink1=testSystemItem->addLink(testComp1Port, sutComp1Port1, &errorString);
  Q_ASSERT(testLink1);

  LinkItem* testLink2=testSystemItem->addLink(testComp2Port, sutLink1->port(), &errorString);
  Q_ASSERT(testLink2);

  LinkItem* testLink3=testSystemItem->addLink(testComp3Port, sutLink2->port(), &errorString);
  Q_ASSERT(testLink3);

  LinkItem* testLink4=testSystemItem->addLink(testComp4Port, sutComp2Port2, &errorString);
  Q_ASSERT(testLink4);

  return;
}

void MainWindow::currModelItem(const QModelIndex& currTsModelIndex)
{
  this->_d->_currentTsModelIndex = currTsModelIndex;
  renderTestModel();
}

void MainWindow::sutOptionsChangedSignalReceiver()
{
  this->_d->_isReadyToRenderSut = true;
}

void MainWindow::testsystemOptionsChangedSignalReceiver()
{
  while (!this->_d->_isReadyToRenderSut);

  this->_d->_isReadyToRenderTestsystem = true;

  renderTestModel();
}

void MainWindow::renderTestModel()
{
  if(!this->_d->_currentTsModelIndex.isValid())
    return;

  if ((!this->_d->_isReadyToRenderSut) || (!this->_d->_isReadyToRenderTestsystem))
  {
    qDebug() << "The flag \'__isReadyToRenderSut\' and the flag \'_isReadyToRenderTestsystem\' have to be set. Debug!!";
    return;
  }

  QBrush sutBoxBrushOption(QColor(this->_d->_sutSettings->findMiscOptions(QString("SUT Box Color"))->toString()));
  QStandardItem* currItem=this->_d->_tsModel->itemFromIndex(this->_d->_currentTsModelIndex);
  if(SutItem* sutItem=dynamic_cast<SutItem*>(currItem))
  {
    QString errorString=QStringLiteral("");
    ComRenderSut renderCommand(this->_d->_testSystemScene,
                               sutItem,
                               *(this->_d->_sutSettings->findNodeOptions(QString("Components"))),
                               *(this->_d->_sutSettings->findNodeOptions(QString("Ports"))),
                               *(this->_d->_sutSettings->findArcOptions(QString("Links"))),
                               sutBoxBrushOption,
                               this->_d->_sutSettings->findMiscOptions(QString("Component Margin"))->toDouble(),
                               this->_d->_sutSettings->findMiscOptions(QString("SUT Box Margin"))->toDouble(),
                               this->_d->_sutSettings->findMiscOptions(QString("SUT Box Radius"))->toDouble());
    bool result=renderCommand.execute(&errorString);
    Q_ASSERT(result);
    Q_ASSERT(errorString.isEmpty());
  }
  else if(TestSystemItem* testSystemItem=dynamic_cast<TestSystemItem*>(currItem))
  {
    QString errorString=QStringLiteral("");
    ComRenderTestSystem renderCommand(this->_d->_testSystemScene,
                                      testSystemItem,
                                      *(this->_d->_sutSettings->findNodeOptions(QString("Components"))),
                                      *(this->_d->_sutSettings->findNodeOptions(QString("Ports"))),
                                      *(this->_d->_sutSettings->findArcOptions(QString("Links"))),
                                      sutBoxBrushOption,
                                      this->_d->_sutSettings->findMiscOptions(QString("Component Margin"))->toDouble(),
                                      this->_d->_sutSettings->findMiscOptions(QString("SUT Box Margin"))->toDouble(),
                                      this->_d->_sutSettings->findMiscOptions(QString("SUT Box Radius"))->toDouble(),
                                      *(this->_d->_testsystemSettings->findNodeOptions(QString("Components"))),
                                      *(this->_d->_testsystemSettings->findNodeOptions(QString("Ports"))),
                                      *(this->_d->_testsystemSettings->findArcOptions(QString("Links"))),
                                      this->_d->_testsystemSettings->findMiscOptions(QString("Space to SUT Box"))->toDouble(),
                                      *(this->_d->_testsystemSettings->findNodeOptions(QString("Testsystem Box"))),
                                      this->_d->_testsystemSettings->findMiscOptions(QString("Testsystem Box Margin"))->toDouble(),
                                      this->_d->_testsystemSettings->findMiscOptions(QString("Testsystem Box Radius"))->toDouble());
    bool result=renderCommand.execute(&errorString);

    Q_ASSERT(result);
    Q_ASSERT(errorString.isEmpty());
  }
  else
    this->_d->_testSystemScene->reset();
}

void MainWindow::activateButtons()
{
  button_cancel->setEnabled(true);
  button_ok->setEnabled(true);
}

void MainWindow::testEventHandler(const QModelIndex &index)
{
  if (1 == index.column())
  {
    QString typeStr = index.model()->data(index.sibling(index.row(), 2)).toString();
    if (typeStr.isEmpty())
    {
      return;
    }

    QStandardItem *testItem = this->_d->_configModel->itemFromIndex(index);
    if ((!typeStr.compare(QString("COLOR"))) || (!typeStr.compare(QString("BRUSHCOLOR"))))
    {
      QColor testColor = QColorDialog::getColor();

      if (testColor.isValid())
      {
        testItem->setText(testColor.name());

        button_cancel->setEnabled(true);
        button_ok->setEnabled(true);
      }
    }
    else if (!typeStr.compare(QString("BOOLEANOPTION")))
    {
      bool testval = index.data().toBool();
      testItem->setText((testval)?(QString("false")):(QString("true")));

      button_cancel->setEnabled(true);
      button_ok->setEnabled(true);
    }
  }
}

void MainWindow::cancelHandler()
{
  QStandardItemModel *dirtyModel = this->_d->_configModel;
  this->_d->_configModel = new QStandardItemModel(this);
  this->_d->_configModel->setColumnCount(2);
  this->_d->_configModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Characteristic")));
  this->_d->_configModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Value")));
  this->_d->_configModel->appendRow(this->_d->_sutSettings->exportAllPropertiesToQStandardItem());
  this->_d->_configModel->appendRow(this->_d->_testsystemSettings->exportAllPropertiesToQStandardItem());
  configView->setModel(this->_d->_configModel);
  delete dirtyModel;
  configView->expandAll();
  configView->resizeColumnToContents(0);

  button_cancel->setEnabled(false);
  button_ok->setEnabled(false);
}

void MainWindow::submitHandler()
{
  this->_d->_isReadyToRenderSut = false;
  emit sutSettingsChanged(this->_d->_configModel);
  this->_d->_isReadyToRenderTestsystem = false;
  emit testsystemSettingsChanged(this->_d->_configModel);

  button_cancel->setEnabled(false);
  button_ok->setEnabled(false);
}

void MainWindow::configWidgetOpenerHandler()
{
  if (!this->_d->_isConfigWidgetOpen)
  {
    this->_d->_isConfigWidgetOpen = true;
    ui->pushButton_opener->setText(">>");

    ui->verticalLayoutWidget->setMaximumWidth(configView->maximumWidth());

    configView->show();
    button_cancel->show();
    button_ok->show();
  }
  else
  {
    this->_d->_isConfigWidgetOpen = false;
    ui->pushButton_opener->setText("<<");

    configView->hide();
    button_cancel->hide();
    button_ok->hide();

    ui->verticalLayoutWidget->setMaximumWidth(0);
  }
}
