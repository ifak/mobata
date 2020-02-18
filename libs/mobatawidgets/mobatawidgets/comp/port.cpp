#include "port.hpp"

#include "link.hpp"
#include "component.hpp"
#include "systemscene.hpp"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace comp{

int Port::type() const
{
  return Type;
}

void Port::addLink(Link* link)
{
  if(!link)
    return;

  this->addEdge(link);
  return;
}

void Port::mouseMoveEvent(QGraphicsSceneMouseEvent* ev)
{
  this->setPos(this->calcPosition(this->mapToParent(ev->pos())));

  return;
}

void Port::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  return QGraphicsItem::mousePressEvent(event);
}

QPointF Port::calcPosition(QPointF possPosition)
{
  Component* portComponent=dynamic_cast<Component*>(this->parentItem());
  Q_ASSERT(portComponent);

  qreal   parentHeight=0.0;
  qreal   parentWidth=0.0;
  if(portComponent)
  {
    parentHeight=portComponent->rect().height();
    parentWidth=portComponent->rect().width();
  }
  else
  {
    parentHeight=this->parentItem()->boundingRect().height();
    parentWidth=this->parentItem()->boundingRect().width();
  }

  qreal currParentTop=-parentHeight/2;
  qreal currParentBottom=currParentTop+parentHeight;

  qreal currParentLeft=-parentWidth/2;
  qreal currParentRight=currParentLeft + parentWidth;

  qreal currX=possPosition.x();
  qreal currY=possPosition.y();

  if(currX<currParentLeft)
    currX=currParentLeft;
  else if(currX>currParentRight)
    currX=currParentRight;

  if(currY<currParentTop)
    currY=currParentTop;
  else if(currY>currParentBottom)
    currY=currParentBottom;

  qreal distX=qAbs(qAbs(currX)-currParentRight);
  qreal distY=qAbs(qAbs(currY)-currParentBottom);

  if(distX<distY)
  {
    if(currX<0)
      currX=currParentLeft;
    else
      currX=currParentRight;
  }
  else
  {
    if(currY<0)
      currY=currParentTop;
    else
      currY=currParentBottom;
  }

  return QPointF(currX, currY);
}


void Port::setLayoutPosition(QPointF possPosPoint)
{
  QPointF newPosition(this->calcPosition(possPosPoint));
  this->setPos(newPosition);

  return;
}

void Port::updatePosition()
{
  this->setLayoutPosition(this->pos());
  this->updateEdgesPosition();

  emit changed(true);

  return;
}

}///end namespace comp
}// end namespace view
