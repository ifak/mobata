#include "directededge.hpp"

#include "arrow.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace graph{

class DirectedEdge::Private
{
  friend class DirectedEdge;
public:
  Private():_arrow(0)
  {}
  ~Private()
  {}
private:
  Arrow*	_arrow;
};

DirectedEdge::DirectedEdge(AbstractNode* from, AbstractNode* to,
                           QGraphicsItem* parent)
  :	Edge(from, to, QString(), QUuid::createUuid(), ArcOptions(), Custom, parent)
{
  this->ctor();
}

DirectedEdge::DirectedEdge(AbstractNode* from, AbstractNode* to,
                           const QString& notation,
                           QGraphicsItem* parent)
  :	Edge(from, to, notation, QUuid::createUuid(), ArcOptions(), Custom, parent)
{
  this->ctor();
}

DirectedEdge::DirectedEdge(AbstractNode* from, AbstractNode* to,
                           const QString& notation,
                           const QUuid &uuid,
                           QGraphicsItem * parent)
  :	Edge(from, to, notation, uuid, ArcOptions(), Custom, parent)
{
  this->ctor();
}

DirectedEdge::DirectedEdge(AbstractNode* from, AbstractNode* to,
                           const QString& notation,
                           const QUuid &uuid,
                           const ArcOptions& arcOptions,
                           QGraphicsItem * parent)
  :	Edge(from, to, notation, uuid, arcOptions, Custom, parent)
{
  this->ctor(true);
}

DirectedEdge::DirectedEdge(AbstractNode* from, AbstractNode* to,
                           const QString& notation,
                           const QUuid &uuid,
                           const ArcOptions& arcOptions,
                           const LineStyle lineStyle,
                           QGraphicsItem * parent)
  :	Edge(from, to, notation, uuid, arcOptions, lineStyle, parent)
{
  this->ctor(true);
}

void DirectedEdge::ctor(bool isCustomArcOptionsUsed)
{
  this->_d=new Private();
  if (isCustomArcOptionsUsed)
  {
    this->_d->_arrow=new Arrow(QPointF(0,0),
                               QPointF(0,0),
                               3*this->pen().width(),
                               3*this->pen().width(),
                               this);
  }
  else
  {
    this->_d->_arrow=new Arrow(QPointF(0,0),
                               QPointF(0,0),
                               this);
  }
  this->_d->_arrow->setBrush(this->pen().color());

  QPainterPath edgePath=this->path();
  this->_d->_arrow->updateArrow(edgePath.elementAt(edgePath.elementCount()-2),
                                edgePath.elementAt(edgePath.elementCount()-1));
}

DirectedEdge::~DirectedEdge()
{
  delete this->_d;
}

int DirectedEdge::type() const
{
  return Type;
}

void DirectedEdge::updatePositions()
{
  Edge::updatePositions();

  QPainterPath edgePath=this->path();
  this->_d->_arrow->updateArrow(edgePath.elementAt(edgePath.elementCount()-2),
                                edgePath.elementAt(edgePath.elementCount()-1));

  return;
}

void DirectedEdge::updatePath(const QPainterPath& path)
{
  Edge::updatePath(path);

  QPainterPath edgePath=this->path();
  this->_d->_arrow->updateArrow(edgePath.elementAt(edgePath.elementCount()-2),
                                edgePath.elementAt(edgePath.elementCount()-1));

  return;
}

void DirectedEdge::controlPointMove(ControlPointType* controlPoint)
{
  Edge::controlPointMove(controlPoint);

  QPainterPath edgePath=this->path();
  this->_d->_arrow->updateArrow(edgePath.elementAt(edgePath.elementCount()-2),
                                edgePath.elementAt(edgePath.elementCount()-1));

  return;
}

void DirectedEdge::setArcOptions(const ArcOptions& arcOptions)
{
  Edge::setArcOptions(arcOptions);

  this->_d->_arrow->setBrush(this->pen().color());

  return;
}

}///end namespace graph
}//end namespace view
