#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <mobata/model/spenat/declmodel.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/spenat/signaltriggeritem.hpp>
#include <mobatawidgets/spenat/declscene.hpp>

#include <graphlayout/comlayoutdeclmodel.hpp>

#include <QTextEdit>
#include <QDir>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace model::spenat;

class MainWindow::Private
{
  friend class MainWindow;

  Private():_declModel(0)
  {}

public:
  ~Private()
  {}

private:
  DeclModel*                _declModel;
  view::spenat::DeclScene*  _declScene;
};

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _d(new Private())
{
  this->ui->setupUi(this);
  this->_d->_declScene=new view::spenat::DeclScene();
  this->ui->_spenatView->setScene(this->_d->_declScene);

  this->buildDeclModel();

  this->ui->_spenatModelView->setModel(this->_d->_declModel);
  this->ui->_spenatModelView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
  this->ui->_spenatModelView->expandAll();

  this->layoutDeclModel();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::buildDeclModel()
{
  this->_d->_declModel=new DeclModel("decl model example");

  foreach(const QString& placeName,
          QList<QString>()
          <<"init"<<"place_1"<<"place_2"
          <<"place_3"<<"place_4")
  {
    this->_d->_declModel->addPlace(placeName);
  }

  PlaceItem* initPlace=this->_d->_declModel->place(QStringLiteral("init"));
  Q_ASSERT(initPlace);
  this->_d->_declModel->addInitPlace(initPlace);

  PlaceItem* place_1=this->_d->_declModel->place(QStringLiteral("place_1"));
  Q_ASSERT(place_1);

  PlaceItem* place_2=this->_d->_declModel->place(QStringLiteral("place_2"));
  Q_ASSERT(place_2);

  PlaceItem* place_3=this->_d->_declModel->place(QStringLiteral("place_3"));
  Q_ASSERT(place_3);

  PlaceItem* place_4=this->_d->_declModel->place(QStringLiteral("place_4"));
  Q_ASSERT(place_4);

  TransitionItem* trans_1=new TransitionItem(QStringLiteral("start"),
                                             0,
                                             QStringLiteral("all zero"),
                                             QStringLiteral("do nothing"));
  this->_d->_declModel->addTransition(trans_1);

  TransitionItem* trans_2=new TransitionItem(QStringLiteral("left"), 0);
  this->_d->_declModel->addTransition(trans_2);

  TransitionItem* trans_3=new TransitionItem(QStringLiteral("right"), 0);
  this->_d->_declModel->addTransition(trans_3);

  TransitionItem* trans_4=this->_d->_declModel->addSignalTransition(QStringLiteral("reset"),
                                                                    0, 0,
                                                                    QStringLiteral(""),
                                                                    QStringLiteral(""));

  trans_1->addPrePlaceArc(initPlace);
  trans_1->addPostPlaceArc(place_1);
  trans_1->addPostPlaceArc(place_2);

  trans_2->addPrePlaceArc(place_1);
  trans_2->addPostPlaceArc(place_3);

  trans_3->addPrePlaceArc(place_2);
  trans_3->addPostPlaceArc(place_4);

  trans_4->addPrePlaceArc(place_3);
  trans_4->addPrePlaceArc(place_4);
  trans_4->addPostPlaceArc(initPlace);

  return;
}

void MainWindow::layoutDeclModel()
{
  if(!this->_d->_declModel)
    return;

  QString errorString;
  graphlayout::ComLayoutDeclModel layoutCommand(this->_d->_declModel,
                                                this->_d->_declScene,
                                                QStringLiteral(""));
  bool result=layoutCommand.execute(&errorString);
  if(!result)
    qCritical()<<"error while spenat layouting:"<<errorString;

  return;
}
