#include "component.hpp"

#include "port.hpp"

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace comp{

class Component::Private
{
  friend class Component;

  Private()   {}
  ~Private()  {}

  QList<Port*>  _ports;
};

Component::Component(const QString& notation,
                     const NodeOptions &nodeOptions)
  : ResizingRectNode(notation, nodeOptions),
    _d(new Private())
{
}

Component::~Component()
{
  delete this->_d;
}

int Component::type() const
{
  return Type;
}

Port const* Component::port(const QString& portName) const
{
  foreach(Port const* port, this->_d->_ports)
    if(port->notation() == portName)
      return port;

  return 0;
}

Port* Component::port(const QString& portName)
{
  foreach(Port* port, this->_d->_ports)
    if(port->notation() == portName)
      return port;

  return 0;
}

Port const* Component::port(const QUuid& portUuid) const
{
  foreach(Port* port, this->_d->_ports)
    if(port->uuid() == portUuid)
      return port;

  return 0;
}

Port* Component::port(const QUuid& portUuid)
{
  foreach(Port* port, this->_d->_ports)
    if(port->uuid() == portUuid)
      return port;

  return 0;
}

const QList<Port*>& Component::ports() const
{
  return this->_d->_ports;
}

Port* Component::addPort(QPointF scenePoint,
                         const QString& portName,
                         const NodeOptions &nodeOptions)
{
  Port* newPortItem  = new Port(this,
                                portName,
                                nodeOptions);
  newPortItem->setLayoutPosition(this->mapFromScene(scenePoint));
  this->_d->_ports.push_back(newPortItem);

  return newPortItem;
}

void Component::removePort(Port* port)
{
  this->_d->_ports.removeAll(port);

  return;
}

QVariant Component::itemChange(GraphicsItemChange change,
                               const QVariant &value)
{
  if (change == ItemPositionChange && scene())
  {
    foreach(Port* port, this->_d->_ports)
      port->updatePosition();
  }

  return ResizingRectNode::itemChange(change, value);
}

void Component::resized()
{
  foreach(Port* port, this->_d->_ports)
    port->updatePosition();

  return;
}

void Component::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
  return graph::AbstractNode::hoverEnterEvent(event);
}

void Component::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
  return graph::AbstractNode::hoverLeaveEvent(event);
}


}///end namespace comp

}//end namespace view
