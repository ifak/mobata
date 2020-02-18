#include "rhapsodymessage.hpp"

#include <QWidget>
#include <QMovie>
#include <QIcon>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsProxyWidget>
#include <QPalette>


RhapsodyMessage::RhapsodyMessage(QWidget* parent)
  : QDialog(parent),
    _animation(nullptr)
{
}

RhapsodyMessage::~RhapsodyMessage()
{
  if(this->_animation != nullptr){
    this->_animation->stop();
    delete this->_animation;
  }
}

void RhapsodyMessage::warningMessage(const QString& messageWarning,
                                     const QString& messageInformative)
{

  QMessageBox warningMessageBox(static_cast<QWidget*>(this->parent()));
  warningMessageBox.setText(messageWarning);
  warningMessageBox.setInformativeText(messageInformative);
  warningMessageBox.setWindowModality(Qt::WindowModal);
  warningMessageBox.setStandardButtons(QMessageBox::Ok);
  warningMessageBox.setIcon(QMessageBox::Warning);
  warningMessageBox.exec();
}

void RhapsodyMessage::loadingMessage(const QString& messageLoading,
                                     const QString& animationPath)
{
  QHBoxLayout* layout = new QHBoxLayout(this);
  QLabel* loadingLabel = new QLabel(this);
  QLabel* animationLabel = new QLabel(this);
  QPalette palette;
  palette.setColor(QPalette::Background, Qt::white);
  this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

  this->_animation = new QMovie(animationPath);

  loadingLabel->setText(messageLoading);
  animationLabel->setMovie(this->_animation);

  layout->addWidget(loadingLabel);
  layout->addWidget(animationLabel);

  this->setLayout(layout);
  this->setWindowTitle("Loading");
  this->setFixedHeight(150);
  this->setFixedWidth(200);
  this->setWindowModality(Qt::WindowModal);
  this->setPalette(palette);
  this->_animation->start();
}

