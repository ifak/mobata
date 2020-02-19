#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "configdelegate.h"

#include <mobata/model/ts/ts.hpp>
#include <mobatawidgets/ts/sutscene.hpp>

#include <QColorDialog>

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace view::ts;

class MainWindow::Private
{
  friend class MainWindow;

  Private():_tsModel(0), _isConfigWidgetOpen(false)
  {}

public:
  ~Private()
  {}

private:
  TestSuite*          _tsModel;
  SutScene*           _sutScene;
  QModelIndex         _currentTsModelIndex;
  QStandardItemModel* _configModel;
  ConfigDelegate*     _configDelegate;
  Settings*           _settings;
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

  this->_d->_settings = new Settings(this, QString(""), QString("sutrenderexample"));
  view::ts::NodeOptions defaultCompOptions = view::ts::ComRenderSut::defaultComponentOptions();
  defaultCompOptions.setTextFont(QFont("Sans Serif", 8)).setColor(Qt::darkGreen).setPen(QPen(Qt::darkBlue, 3)).setSize(QSizeF(100,75));
  this->_d->_settings->addNodeTypeSettings(QString("Components"), defaultCompOptions);
  view::ts::NodeOptions defaultPortOptions = view::ts::ComRenderSut::defaultPortOptions();
  this->_d->_settings->addNodeTypeSettings(QString("Ports"), defaultPortOptions);
  view::ts::ArcOptions defaultLinkOptions = view::ts::ComRenderSut::defaultLinkOptions();
  this->_d->_settings->addArcTypeSettings(QString("Links"), defaultLinkOptions);
  QVariant defaultSutBoxColor = view::ts::ComRenderSut::defaultSutBoxBrushOption().color().name();
  this->_d->_settings->addMiscSettings(QString("SUT Box Color"), defaultSutBoxColor, QString("BRUSHCOLOR"));
  this->_d->_settings->addMiscSettings(QString("Component Margin"), view::ts::ComRenderSut::defaultCompMarginSpace(), QString("LENGTH"));
  this->_d->_settings->addMiscSettings(QString("SUT Box Margin"), view::ts::ComRenderSut::defaultSutBoxMarginSpace(), QString("LENGTH"));
  this->_d->_settings->addMiscSettings(QString("SUT Box Radius"), view::ts::ComRenderSut::defaultSutBoxRadius(), QString("LENGTH"));
  this->_d->_settings->readAllSettingsFromConfigFile();

  this->_d->_sutScene=new SutScene(this);
  this->_d->_sutScene->setSutBoxBrush(QBrush(QColor(this->_d->_settings->findMiscOptions(QString("SUT Box Color"))->toString())));
  this->ui->_sutRenderView->setScene(this->_d->_sutScene);

  connect(this->ui->_tsModelView, &QTreeView::clicked,
          this, &MainWindow::currSutItem);

  configView = new QTreeView(this);
  configView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
  ui->verticalLayout_4->addWidget(configView);
  configView->setMinimumWidth(250);
  configView->setMaximumWidth(500);
  configView->hide();
  configApplicationLayout = new QHBoxLayout(this);
  ui->verticalLayout_4->addLayout(configApplicationLayout);
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

  this->_d->_configModel = this->_d->_settings->exportAllPropertiesToQStandardItemModel(this);
  configView->setModel(this->_d->_configModel);

  this->_d->_configDelegate = new ConfigDelegate(this);
  configView->setItemDelegateForColumn(1, this->_d->_configDelegate);
  configView->expandAll();
  configView->resizeColumnToContents(0);
  int maxWidthColumn1 = configView->width() - configView->columnWidth(0);
  configView->setColumnWidth(1, (75 > maxWidthColumn1)?(75-25):(maxWidthColumn1-25));

  connect(this->_d->_configDelegate, SIGNAL(commitData(QWidget*)), this, SLOT(activateButtons()));

  connect(configView, SIGNAL(clicked(QModelIndex)), this, SLOT(testEventHandler(QModelIndex)));
  connect(this, SIGNAL(settingsChanged(QStandardItemModel*)), this->_d->_settings, SLOT(synchronizeOptions(QStandardItemModel*)));
  connect(this->_d->_settings, SIGNAL(optionsChanged()), this, SLOT(renderAction()));
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

  SutItem* sutItem=this->_d->_tsModel->sutItem();

  SutComponentItem* sutComp1=sutItem->addComponent<SutComponentItem>("sutComp1", &errorString);
  Q_ASSERT(sutComp1);
  PortItem* sutComp1Port1=sutComp1->addPort("sutPort1", &errorString);
  Q_ASSERT(sutComp1Port1);
  PortItem* sutComp1Port2=sutComp1->addPort("sutPort2", &errorString);
  Q_ASSERT(sutComp1Port2);
  PortItem* sutComp1Port3=sutComp1->addPort("sutPort3", &errorString);
  Q_ASSERT(sutComp1Port3);
  PortItem* sutComp1Port4=sutComp1->addPort("sutPort4", &errorString);
  Q_ASSERT(sutComp1Port4);

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

  LinkItem* link1=sutItem->addLink(sutComp1Port1, sutComp3Port1, &errorString);
  Q_ASSERT(link1);
  LinkItem* link2=sutItem->addLink(sutComp3Port2, sutComp2Port1, &errorString);
  Q_ASSERT(link2);

  ///////////////////////////////////
  TestSystemItem* testSystem=this->_d->_tsModel->testSystemItem();
  Q_ASSERT(testSystem);
  TestComponentItem* testComp1=testSystem->addComponent<TestComponentItem>("testComp1",
                                                                           &errorString);
  PortItem* testCompPort1=testComp1->addPort("testCompPort1",
                                             &errorString);
  Q_ASSERT(testCompPort1);
  TestComponentItem* testComp2=testSystem->addComponent<TestComponentItem>("testComp2",
                                                                           &errorString);
  PortItem* testCompPort2=testComp2->addPort("testCompPort2", &errorString);
  Q_ASSERT(testCompPort2);

  ///error/////////
  errorString=QStringLiteral("");
  TestComponentItem* errorTestComponent=testSystem->addComponent<TestComponentItem>("testComp1",
                                                                                    &errorString);
  Q_ASSERT(errorTestComponent==0);
  Q_ASSERT(errorString=="There is already a component with name 'testComp1' available!");

  errorString=QStringLiteral("");
  errorPort=testComp1->addPort("testCompPort1", &errorString);
  Q_ASSERT(errorPort==0);
  Q_ASSERT(errorString=="There is already a port 'testCompPort1' available!");
  ///////////////////////

  return;
}

void MainWindow::currSutItem(const QModelIndex& currTsModelIndex)
{
  this->_d->_currentTsModelIndex = currTsModelIndex;
  renderSut();
}

void MainWindow::renderAction()
{
  renderSut();
}

void MainWindow::renderSut()
{
  if(!this->_d->_currentTsModelIndex.isValid())
    return;

  QBrush brushOption(QColor(this->_d->_settings->findMiscOptions(QString("SUT Box Color"))->toString()));
  QStandardItem* currItem=this->_d->_tsModel->itemFromIndex(this->_d->_currentTsModelIndex);
  if(SutItem* sutItem=dynamic_cast<SutItem*>(currItem))
  {
    QString errorString=QStringLiteral("");
    ComRenderSut renderCommand(this->_d->_sutScene,
                               sutItem,
                               *(this->_d->_settings->findNodeOptions(QString("Components"))),
                               *(this->_d->_settings->findNodeOptions(QString("Ports"))),
                               *(this->_d->_settings->findArcOptions(QString("Links"))),
                               brushOption,
                               this->_d->_settings->findMiscOptions(QString("Component Margin"))->toDouble(),
                               this->_d->_settings->findMiscOptions(QString("SUT Box Margin"))->toDouble(),
                               this->_d->_settings->findMiscOptions(QString("SUT Box Radius"))->toDouble());
    bool result=renderCommand.execute(&errorString);
    Q_ASSERT(result);
    Q_ASSERT(errorString.isEmpty());
  }
  else
    this->_d->_sutScene->reset();
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
  this->_d->_configModel = this->_d->_settings->exportAllPropertiesToQStandardItemModel(this);
  configView->setModel(this->_d->_configModel);
  delete dirtyModel;
  configView->expandAll();
  configView->resizeColumnToContents(0);

  button_cancel->setEnabled(false);
  button_ok->setEnabled(false);
}

void MainWindow::submitHandler()
{
  emit settingsChanged(this->_d->_configModel);

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
