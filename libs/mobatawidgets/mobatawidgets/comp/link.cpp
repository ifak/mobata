#include "link.hpp"

#include "port.hpp"
#include "linkport.hpp"

#include <QGraphicsScene>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace comp{

Link::Link(Port* from, Port* to,
           const QString& notation,
           const QUuid& uuid,
           const ArcOptions &arcOptions,
           QGraphicsItem * parent)
  : Edge(from, to, notation, uuid, arcOptions, Rectilinear, parent)
{
  NodeOptions linkPortOptions;
  linkPortOptions.setSize(arcOptions.pen().width()*5, arcOptions.pen().width()*5);
  linkPortOptions.setColor(Qt::white);
  linkPortOptions.setPen(arcOptions.pen());
  this->_linkPort=new LinkPort(this,
                               QStringLiteral("port"),
                               linkPortOptions);

  QPainterPath path=this->path();
  if(path.elementCount())
  {
    QPointF start=this->mapFromScene(path.elementAt(0));
    QPointF end=this->mapFromScene(path.elementAt(path.elementCount()-1));
    this->_linkPort->setPos((end.x() + start.x())/2,
                            (end.y() + start.y())/2);
    this->_linkPort->show();
  }
  else
    this->_linkPort->hide();
}

Port* Link::sourcePort()
{
  if(this->source() != 0)
    return qgraphicsitem_cast<Port*>(this->source());
  else
    return 0;
}

Port* Link::targetPort()
{
  if(this->target() != 0)
    return qgraphicsitem_cast<Port*>(this->target());
  else
    return 0;
}

LinkPort* Link::linkPort()
{
  return this->_linkPort;
}

void Link::controlPointPressed(ControlPointType *controlPoint)
{
  if(controlPoint == this->controlPoints().begin().key()){
    controlPoint->setFlag(QGraphicsItem::ItemIsMovable, true);
  }
  if(controlPoint == (this->controlPoints().end()-1).key()){
    controlPoint->setFlag(QGraphicsItem::ItemIsMovable, true);
  }
  return;
}

void Link::controlPointReleased(ControlPointType *controlPoint)
{    
  Port* port = 0;
  if(controlPoint == this->controlPoints().begin().key()){
    foreach(QGraphicsItem* currItem, this->scene()->items(controlPoint->pos())){
      if((port = dynamic_cast<Port*>(currItem))){
        break;
      }
    }
    if(port)
    {
      if(this->sourcePort())
        this->sourcePort()->removeEdge(this);

      this->setSource(port);
      port->addLink(this);
    }
    else{
      if(this->sourcePort())
        this->sourcePort()->removeEdge(this);

      this->setSource(0);
    }
    this->updatePath(this->path());

  }
  if(controlPoint == (this->controlPoints().end()-1).key()){
    foreach(QGraphicsItem* currItem, this->scene()->items(controlPoint->pos())){
      if((port = dynamic_cast<Port*>(currItem)))
        break;
    }
    if(port)
    {
      if(this->targetPort())
        this->targetPort()->removeEdge(this);

      this->setTarget(port);
      port->addLink(this);
    }
    else{
      if(this->targetPort())
        this->targetPort()->removeEdge(this);

      this->setTarget(0);
    }
    this->updatePath(this->path());
  }
  return;
}

void Link::updatePath(const QPainterPath& newPath)
{
  Edge::updatePath(newPath);

  QPainterPath path=this->path();
  if(path.elementCount())
  {
    QPointF start=path.elementAt(0);
    QPointF end=path.elementAt(path.elementCount()-1);
    QPointF possibleMiddlePoint((end.x() + start.x())/2,
                                (end.y() + start.y())/2);
    this->_linkPort->setLayoutPosition(possibleMiddlePoint);
    this->_linkPort->show();
  }
  else
    this->_linkPort->hide();

  return;
}

}///end namespace comp
}// end namespace view
