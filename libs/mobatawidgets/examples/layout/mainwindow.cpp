#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "extspenat.hpp"
#include "exttransition.hpp"

#include <mobata/model/spenat/signaltriggeritem.hpp>

#include <graphlayout/comlayoutspenatmodel.hpp>
#include <mobatawidgets/spenat/declscene.hpp>

#include <QTextEdit>
#include <QDir>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

class MainWindow::Private
{
  friend class MainWindow;

  Private():_extSpenat(0)
  {}

public:
  ~Private()
  {}

private:
  ExtSpenat*                  _extSpenat;
  view::spenat::SpenatScene*  _spenatScene;
};

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _d(new Private())
{
  this->ui->setupUi(this);
  this->_d->_spenatScene=new view::spenat::SpenatScene();
  this->ui->_spenatView->setScene(this->_d->_spenatScene);

  this->buildExtSpenat();

  this->ui->_spenatModelView->setModel(this->_d->_extSpenat);
  this->ui->_spenatModelView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
  this->ui->_spenatModelView->expandAll();

  this->layoutExtSpenat();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::buildExtSpenat()
{
  this->_d->_extSpenat=new ExtSpenat();
  this->_d->_extSpenat->setName("proges-spenat-example");

  foreach(const QString& placeName,
          QList<QString>()
          <<"init"<<"place_1"<<"place_2"
          <<"place_3"<<"place_4")
  {
    this->_d->_extSpenat->addPlace(placeName);
  }

  model::spenat::PlaceItem* initPlace=this->_d->_extSpenat->place(QStringLiteral("init"));
  Q_ASSERT(initPlace);
  this->_d->_extSpenat->addInitPlace(initPlace);

  model::spenat::PlaceItem* place_1=this->_d->_extSpenat->place(QStringLiteral("place_1"));
  Q_ASSERT(place_1);

  model::spenat::PlaceItem* place_2=this->_d->_extSpenat->place(QStringLiteral("place_2"));
  Q_ASSERT(place_2);

  model::spenat::PlaceItem* place_3=this->_d->_extSpenat->place(QStringLiteral("place_3"));
  Q_ASSERT(place_3);

  model::spenat::PlaceItem* place_4=this->_d->_extSpenat->place(QStringLiteral("place_4"));
  Q_ASSERT(place_4);

  ExtTransition* trans_1=new ExtTransition(QStringLiteral("start"),
                                           0,
                                           QStringLiteral("all zero"),
                                           QStringLiteral("do nothing"));
  this->_d->_extSpenat->addTransition(trans_1);

  ExtTransition* trans_2=new ExtTransition(QStringLiteral("left"), 0);
  this->_d->_extSpenat->addTransition(trans_2);

  ExtTransition* trans_3=new ExtTransition(QStringLiteral("right"), 0);
  this->_d->_extSpenat->addTransition(trans_3);

  model::spenat::TransitionItem* trans_4=this->_d->_extSpenat->addSignalTransition(QStringLiteral("reset"),
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

void MainWindow::layoutExtSpenat()
{
  if(!this->_d->_extSpenat)
    return;

  QString errorString;
  graphlayout::ComLayoutSpenatModel layoutCommand(this->_d->_extSpenat,
                                                  this->_d->_spenatScene,
                                                  QStringLiteral(""));
  bool result=layoutCommand.execute(&errorString);
  if(!result)
    qCritical()<<"error while spenat layouting:"<<errorString;

  return;
}
