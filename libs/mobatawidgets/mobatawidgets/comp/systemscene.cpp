#include "systemscene.hpp"

#include "component.hpp"
#include "link.hpp"
#include "port.hpp"

#include "../graph/functors.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace  view{
namespace comp{

SystemScene::SystemScene(QObject *parent)
  : graph::GraphScene(parent)
{
}

SystemScene::~SystemScene()
{}

void SystemScene::addComponent(Component* newComponent,
                               QPointF componentPos)
{
  Q_ASSERT(newComponent);

  this->addItem(newComponent);
  newComponent->setPos(componentPos);

  emit componentAdded(newComponent->uuid());
  emit graphModified(true);

  return;
}

Port* SystemScene::addPort(Component* component,
                           QPointF portPos,
                           NodeOptions options)
{
    if(!component)
        return 0;

    Port* newPort=component->addPort(portPos,
                                     QStringLiteral("newPort"),
                                     options);
    emit portAdded(newPort->uuid());
    emit graphModified(true);
    connect(newPort,SIGNAL(changed(bool)),
            this, SIGNAL(graphModified(bool)));

    return newPort;
}

Port* SystemScene::addPort(Component* component,
                           QPointF portPos,
                           QUuid uuid)
{
    if(!component)
        return 0;

    Port* newPort=component->addPort(portPos);
    newPort->setUuid(uuid);

    emit portAdded(newPort->uuid());
    emit graphModified(true);

    return newPort;
}

Link* SystemScene::addLink(Port* from,
                           Port* to,
                           const QPainterPath& path,
                           ArcOptions options)
{
    if(!(from && to))
        return 0;

    Link* newLink=new Link(from, to, QString(), QUuid::createUuid(), options);
    this->addItem(newLink);
    QPainterPath newPath = view::graph::makeRectPath(path);
    newLink->updatePath(newPath);

    emit linkAdded(newLink->uuid());
    emit graphModified(true);

    connect(newLink, SIGNAL(changed(bool)),
            this, SIGNAL(graphModified(bool)));
    return newLink;
}

void SystemScene::removeComponent(Component* component)
{
    if(!component)
        return;

    QUuid componentUuid = component->uuid();

    foreach(Port* port, component->ports()){
        this->removePort(port);
    }
    this->removeNode(component);
    emit componentRemoved(componentUuid);
    emit graphModified(true);

    return;
}

void SystemScene::removePort(Port* port)
{
    if(!port)
        return;

    QUuid portUuid = port->uuid();

    foreach(Link* currLink,this->links(port)){
        if(currLink->sourcePort() == port)
        {
            currLink->setSource(0);
        }
        if(currLink->targetPort() == port)
        {
            currLink->setTarget(0);
        }
    }

    foreach(Component* comp, this->components()){
        foreach(Port* currPort, comp->ports()){
            if(currPort == port)
                comp->removePort(port);
        }
    }
    this->removeNode(port);

    emit portRemoved(portUuid);
    emit graphModified(true);
    return;
}

void SystemScene::removeLink(Link* link)
{
    if(!link)
        return;

    QUuid linkUuid = link->uuid();
    this->removeEdge(link);
    emit linkRemoved(linkUuid);
    emit graphModified(true);

    return;
}

Component* SystemScene::component(const QUuid &compUuid)
{
    foreach (QGraphicsItem* currItem, this->items()) {
        if(Component* currComp = qgraphicsitem_cast<Component*>(currItem)){
            if(currComp->uuid() == compUuid)
                return currComp;
        }
    }

    return 0;
}

QList<Port*> SystemScene::ports(const QUuid &compUuid)
{
    Component* currComp = this->component(compUuid);
    QList<Port*> portList = currComp->ports();

    return portList;
}

Port* SystemScene::port(const QUuid &portUuid)
{
    foreach (QGraphicsItem* currItem, this->items()) {
        if(Port* currPort = qgraphicsitem_cast<Port*>(currItem)){
            if(currPort->uuid() == portUuid)
                return currPort;
        }
    }
    return 0;
}

QList<Component*> SystemScene::components()
{
    QList<Component*> compList;

    foreach (QGraphicsItem* currItem, this->items()) {
        if(Component* currComp = qgraphicsitem_cast<Component*>(currItem))
            compList.append(currComp);
    }

    return compList;
}

QList<Link*> SystemScene::links()
{
    QList<Link*> linkList;

    foreach(QGraphicsItem* currItem, this->items()){
        if(Link* currLink = dynamic_cast<Link*>(currItem)){
                linkList.append(currLink);
        }
    }

    return linkList;
}

QList<Link*> SystemScene::links(Port* port)
{
    QList<Link*> linkList;

    foreach(QGraphicsItem* currItem, this->items()){
        if(Link* currLink = dynamic_cast<Link*>(currItem)){
            if(currLink->sourcePort() == port || currLink->targetPort() == port)
                linkList.append(currLink);
        }
    }

    return linkList;
}

Link* SystemScene::link(const QUuid &linkUuid)
{
    foreach(QGraphicsItem* currItem, this->items()){
        if(Link* currLink = dynamic_cast<Link*>(currItem)){
            if(currLink->uuid()==linkUuid)
                return currLink;
        }
    }
    return 0;
}

void SystemScene::setSelected(Component *comp)
{
    foreach (QGraphicsItem* currItem, this->items()) {
        if(comp == qgraphicsitem_cast<Component*>(currItem)){
            currItem->setSelected(true);
        } else{
            currItem->setSelected(false);
        }
    }
    return;
}

void SystemScene::setSelected(Port *port)
{
    foreach (QGraphicsItem* currItem, this->items()) {
        if(port == qgraphicsitem_cast<Port*>(currItem)){
            currItem->setSelected(true);
        } else{
            currItem->setSelected(false);
        }
    }

    return;
}

}///end namespace comp
}///end namespace view
