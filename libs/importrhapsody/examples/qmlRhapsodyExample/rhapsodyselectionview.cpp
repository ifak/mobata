#include <importrhapsody/comimportrhapsodytree.hpp>
#include <importrhapsody/comimportrhapsody.hpp>
#include <importrhapsody/importrhapsodypointer.hpp>

#include <mobata/model/statemachine/statemachinemodel.hpp>

#include "rhapsodyselectionview.hpp"
#include "ui_rhapsodyselectionview.h"
#include "rhapsodymessage.hpp"

#include <QDebug>
#include <QStandardItemModel>

using namespace rhapsody;

RhapsodySelectionView::RhapsodySelectionView(QWidget *parent,
                                             const QString& projectFilePath,
                                             model::statemachine::StateMachineModel *_smModel) :
  QDialog(parent),
  _projectFilePath(projectFilePath),
  _stateMachineModel(_smModel),
  _standardItemModel(new QStandardItemModel()),
  _r(new RhapsodyPointer()),
  ui(new Ui::RhapsodySelectionView)
{
  ui->setupUi(this);
  this->setWindowModality(Qt::WindowModal);
  this->ui->importPushButton->setEnabled(false);
  this->ui->importPushButton->setToolTip(QStringLiteral("Choose a statechart to continue."));

  this->_r->_rhapsodyApplication = nullptr;
  this->_r->_rhapsodyProject = nullptr;

  QString*  errorMessage = new QString();

  delete errorMessage;

  connect(this->ui->importPushButton, SIGNAL(clicked()), this, SLOT(importRhapsodyStatechart()));
  connect(this->ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(treeViewIndexChange(const QModelIndex)));
  connect(this->ui->cancelPushButton, SIGNAL(clicked()), this, SLOT(cancelImport()));
}

RhapsodySelectionView::~RhapsodySelectionView()
{
  if(this->_r->_rhapsodyApplication != nullptr)
    this->_r->_rhapsodyApplication->quit();
  delete ui;
  delete _r;
  delete _standardItemModel;
}

bool RhapsodySelectionView::updateTreeView(QString* errorMessage)
{
  ComImportRhapsodyTree comImportRhapsodyTree(this->_r,
                                              this->_standardItemModel,
                                              this->_projectFilePath);

  if(!comImportRhapsodyTree.execute(errorMessage)){
    RhapsodyMessage(static_cast<QDialog*>(this->parent())).warningMessage(QStringLiteral("Rhapsody project could not be loaded."),
                                                                          QStringLiteral("Make sure Rhapsody is installed on your system and your selected file contains a valid project."));
    return false;
  }

  this->ui->treeView->setModel(this->_standardItemModel);
  this->ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
  this->ui->treeView->expandAll();

  return true;
}

void RhapsodySelectionView::resetTreeViewModel()
{
  delete this->_standardItemModel;
  this->_standardItemModel = new QStandardItemModel();
  return;
}

void RhapsodySelectionView::treeViewIndexChange(const QModelIndex &index)
{
  if(!index.isValid())
    return;

  this->_pathList.clear();
  QString* errorMessage = new QString();
  QModelIndexList indexList;
  indexList << index;
  indexList << index.parent();
  while ( indexList.last().isValid() ) {
      indexList << indexList.last().parent();
  }

  QString elementString;
  for(QModelIndexList::const_reverse_iterator it = indexList.crbegin(); it != indexList.crend(); it++){
    elementString = (*it).data().toString();
    if(elementString != QStringLiteral(""))
      this->_pathList << elementString;
  }
  this->ui->importPushButton->setEnabled(true);
  this->ui->importPushButton->setToolTip(QStringLiteral(""));
  delete errorMessage;

  return;
}

void RhapsodySelectionView::importRhapsodyStatechart()
{
  QString *errorMessage = new QString();
  ComImportRhapsody importRhapsody(this->_r,
                                   this->_stateMachineModel,
                                   this->_projectFilePath,
                                   this->_pathList);

  bool retVal = importRhapsody.execute(errorMessage);
  if(!retVal){
    qWarning() << errorMessage->toLatin1();
    RhapsodyMessage(this).warningMessage(QStringLiteral("Selected element is not a Rhapsody statechart."),
                                         QStringLiteral(""));
    return;
  }

  this->accept();
  this->close();
}

bool RhapsodySelectionView::initExec(QString* errorMessage)
{
  RhapsodyMessage messageBox(static_cast<QDialog*>(this->parent()));
  messageBox.loadingMessage(QStringLiteral("Loading Rhapsody..."),
                            QStringLiteral(":qmlRhapsodyExample/images/loading.gif"));
  messageBox.show();
  bool updateRet = this->updateTreeView(errorMessage);
  messageBox.close();
  if(!updateRet)
    return false;

  if(this->exec() == 0)
    return false;

  return true;
}

void RhapsodySelectionView::cancelImport()
{
  this->reject();
  this->close();
}
