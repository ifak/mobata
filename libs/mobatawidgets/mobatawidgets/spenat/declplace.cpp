#include "declplace.hpp"

#include "../base/textitem.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

class DeclPlace::Private
{
  friend class DeclPlace;

  Private() : _marking(false), _initMarking(false), _markingPoint(0)
  {}

  bool _marking, _initMarking;
  QGraphicsEllipseItem* _markingPoint;
};

DeclPlace::DeclPlace(const QString& notation,
                     const PlaceOptions& placeOptions)
  : graph::RoundRectNode(notation, placeOptions)
{
  this->_d=new Private();
  this->createMarkingPoint();
  this->notationItem()->setPos(this->boundingRect().width()/2,
                               -this->notationItem()->boundingRect().height()/2);
}

DeclPlace::DeclPlace(const PlaceOptions& placeOptions)
  : graph::RoundRectNode(QLatin1String("newPlace"), placeOptions)
{
  this->_d=new Private();
  this->createMarkingPoint();
  this->notationItem()->setPos(this->boundingRect().width()/2,
                               -this->notationItem()->boundingRect().height()/2);
  this->notationItem()->setFlags(QGraphicsItem::ItemIsMovable
                                 | QGraphicsItem::ItemIsSelectable
                                 | QGraphicsItem::ItemIsFocusable);
}

DeclPlace::DeclPlace(const QString& notation)
  : graph::RoundRectNode(notation, PlaceOptions()/*DisplaySettings::instance()->getPlaceOptions()*/)
{
  this->_d=new Private();
  this->createMarkingPoint();
  this->notationItem()->setPos(this->boundingRect().width()/2,
                               -this->notationItem()->boundingRect().height()/2);
}

DeclPlace::~DeclPlace()
{
  delete this->_d;
}

int DeclPlace::type() const
{
  return Type;
}

void DeclPlace::createMarkingPoint()
{
  this->_d->_markingPoint=new QGraphicsEllipseItem(-5,-5,10,10,this);
  this->_d->_markingPoint->setBrush(Qt::darkRed);
  this->_d->_markingPoint->hide();

  return;
}

void DeclPlace::centerNotationItem()
{
  QRectF notationItemRect=this->notationItem()->boundingRect();
  this->notationItem()->setPos(-notationItemRect.width()/2,
                               -notationItemRect.height()/2);

  return;
}

void DeclPlace::setMarking(const bool marking)
{
  this->_d->_marking=marking;
  this->_d->_markingPoint->setVisible(marking);

  return;
}

bool DeclPlace::getMarking() const
{
  return this->_d->_marking;
}

void DeclPlace::setInitMarking(const bool initMarking)
{
  this->_d->_initMarking=initMarking;

  return;
}

bool DeclPlace::getInitMarking() const
{
  return this->_d->_initMarking;
}

}///end namespace spenat
}///end namespace view
