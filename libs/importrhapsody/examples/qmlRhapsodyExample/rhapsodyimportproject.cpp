#include <QDebug>
#include <QFileDialog>
#include <importrhapsody/comimportrhapsodyactiveinstance.hpp>

#include "rhapsodyimportproject.hpp"
#include "ui_rhapsodyimportproject.h"
#include "rhapsodymessage.hpp"

RhapsodyImportProject::RhapsodyImportProject(QWidget *parent) :
  QDialog(parent),
  _importFromActiveInstance(false),
  _importFromProjectFile(false),
  _activeInstance(false),
  ui(new Ui::RhapsodyImportProject())
{
  ui->setupUi(this);
  this->setElementStates();
  this->refreshActiveInstance();
  this->setWindowModality(Qt::WindowModal);

  connect(this->ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChange(int)));
  connect(this->ui->okPushButton, SIGNAL(clicked()), this, SLOT(importRhapsodyInstance()));
  connect(this->ui->cancelPushButton, SIGNAL(clicked()), this, SLOT(closeDialog()));
  connect(this->ui->refreshPushButton, SIGNAL(clicked()), this, SLOT(refreshActiveInstance()));
  connect(this->ui->browsePushButton, SIGNAL(clicked()), this, SLOT(browseFilesystem()));
  connect(this->ui->projectFileBrowser, SIGNAL(textChanged(QString)), this, SLOT(projectFileBrowserTextChange()));
  connect(this->ui->clearPushButton, SIGNAL(clicked()), this, SLOT(clearProjectFileTextBrowser()));
}

RhapsodyImportProject::~RhapsodyImportProject()
{
  delete ui;
}

void RhapsodyImportProject::checkBoxStateChange(int arg1)
{
  this->_importFromActiveInstance = arg1;
  this->setElementStates();
}

void RhapsodyImportProject::importRhapsodyInstance()
{
  QString errorMessage;

  if(this->_importFromActiveInstance){
    rhapsody::ComImportRhapsodyActiveInstance comActiveInstace;
    if(!comActiveInstace.execute(&errorMessage)){
      RhapsodyMessage(this).warningMessage(QStringLiteral("Rhapsody instance no longer found."),
                                           QStringLiteral("Make sure an active Rhapsody instance is running."));
      this->ui->checkBox->setChecked(false);
      qWarning() << errorMessage.toLatin1();
      return;
    }
    projectFilePath = QStringLiteral("");

  }
  else if(this->_importFromProjectFile){
    projectFilePath = this->ui->projectFileBrowser->text();
    if(projectFilePath.isEmpty() || !projectFilePath.contains(".rpy")){
      RhapsodyMessage(this).warningMessage(QStringLiteral("Rhapsody project file not found."),
                                           QStringLiteral("Make sure the file you selected is a rhapsody project file."));
      return;
    }
    else{
       QFileInfo fileCheck(projectFilePath);
       if(!fileCheck.exists() || !fileCheck.isFile()){
        RhapsodyMessage(this).warningMessage(QStringLiteral("Rhapsody project file not found."),
                                             QStringLiteral("Make sure the file you selected exists."));
         return;
       }
    }
  }

  this->accept();
  this->close();
}

void RhapsodyImportProject::closeDialog()
{
  this->reject();
  this->close();
}

void RhapsodyImportProject::refreshActiveInstance()
{
  QString errorMessage;
  rhapsody::ComImportRhapsodyActiveInstance comActiveInstace;
  if(comActiveInstace.execute(&errorMessage)){
    this->ui->checkBox->setEnabled(true);
    this->ui->checkBox->setToolTip(QStringLiteral(""));
  }
  else{
    this->ui->checkBox->setToolTip(QStringLiteral("No active instance or project found. Click to check again"));
    this->ui->checkBox->setEnabled(false);
    qWarning() << errorMessage.toLatin1();
  }
}

void RhapsodyImportProject::browseFilesystem()
{
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open Rhapsody Project"),
                                                  "",
                                                  tr("Rhapsody Project Files (*.rpy)"));
  if(fileName.isEmpty())
    return;

  if(!fileName.contains(".rpy")){
    RhapsodyMessage(this).warningMessage(QStringLiteral("Selected file is not a Rhapsody project."),
                                         QStringLiteral(""));
    return;
  }

  this->ui->projectFileBrowser->setText(fileName);
}

void RhapsodyImportProject::projectFileBrowserTextChange()
{
  QString fileName = this->ui->projectFileBrowser->text();
  if(fileName.isEmpty())
    this->_importFromProjectFile = false;
  else
    this->_importFromProjectFile = true;

  this->setElementStates();
}

void RhapsodyImportProject::setElementStates()
{
  if(this->_importFromActiveInstance || this->_importFromProjectFile){
    this->ui->okPushButton->setEnabled(true);
    this->ui->okPushButton->setToolTip(QStringLiteral(""));
  }
  else{
    this->ui->okPushButton->setEnabled(false);
    this->ui->okPushButton->setToolTip(QStringLiteral("No instance or project file found."));
  }

  if(this->_importFromActiveInstance){
    this->ui->browsePushButton->setEnabled(false);
    this->ui->browsePushButton->setToolTip(QStringLiteral("Uncheck instance loading to choose a project file."));
    this->ui->projectFileBrowser->clear();
  }
  else{
    this->ui->browsePushButton->setEnabled(true);
    this->ui->browsePushButton->setToolTip(QStringLiteral(""));
  }

  if(this->_importFromProjectFile){
    this->ui->checkBox->setEnabled(false);
    this->ui->checkBox->setToolTip(QStringLiteral("Clear project file to allow instance loading."));
  }
  else
    this->ui->checkBox->setEnabled(true);
    this->ui->checkBox->setToolTip(QStringLiteral(""));
}

void RhapsodyImportProject::clearProjectFileTextBrowser()
{
  this->ui->projectFileBrowser->clear();
}
