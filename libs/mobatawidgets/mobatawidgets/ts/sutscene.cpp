#include "sutscene.hpp"

#include "../graph/functors.hpp"

#include "../comp/link.hpp"
#include "../comp/linkport.hpp"

#include "sutcomponent.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view {
namespace ts {

////////SutBox::Private
class SutBox::Private
{
  friend class SutBox;

  SutComponents _sutComponents;
  SutLinks      _sutLinks;

  Private()
  {}
};

///SutBox///////////
SutBox::SutBox(QGraphicsItem *parent)
  : base::RoundRect(parent),
    _d(new Private)
{}

SutBox::~SutBox()
{
  delete this->_d;
}

void SutBox::addSutComponent(SutComponent* newSutComponent)
{
  if(!newSutComponent)
    return;

  newSutComponent->setParentItem(this);

  this->_d->_sutComponents.append(newSutComponent);

  return;
}

void SutBox::addSutLink(Link* link)
{
  if(!link)
    return;

  link->setParentItem(this);

  this->_d->_sutLinks.append(link);

  return;
}

const SutComponents& SutBox::sutComponents() const
{
  return this->_d->_sutComponents;
}

const SutLinks& SutBox::sutLinks() const
{
  return this->_d->_sutLinks;
}

///SutScene::Private
class SutScene::Private
{
  friend class SutScene;

  SutBox*       _sutBox;
  QBrush        _sutBoxBrush;

  Private()
    : _sutBox(0), _sutBoxBrush(QBrush(Qt::white))
  {}
  ~Private()
  {}
};

////////SutScene
SutScene::SutScene(QObject *parent)
  : graph::GraphScene(parent),
    _d(new Private)
{
  this->addSutBox();
}

SutScene::~SutScene()
{
  delete this->_d;
}

void SutScene::addSutBox()
{
  this->_d->_sutBox=new SutBox();
  this->_d->_sutBox->setBrush(this->_d->_sutBoxBrush);
  this->addItem(this->_d->_sutBox);
  this->_d->_sutBox->hide();

  return;
}

SutBox const* SutScene::sutBox() const
{
  return this->_d->_sutBox;
}

void SutScene::reset()
{
  this->clear();
  this->addSutBox();

  return;
}

void SutScene::addSutComponent(SutComponent* newSutComponent)
{
  if(!newSutComponent)
    return;

  this->_d->_sutBox->addSutComponent(newSutComponent);
  newSutComponent->setPos(this->_d->_sutBox->mapFromScene(newSutComponent->pos()));

  return;
}

void SutScene::addSutLink(Link* link)
{
  if(!link)
    return;

  QPainterPath newPath = view::graph::makeRectPath(link->path());
  link->updatePath(newPath);

  this->_d->_sutBox->addSutLink(link);

  return;
}

const SutComponents& SutScene::sutComponents() const
{
  return this->_d->_sutBox->sutComponents();
}

const SutLinks& SutScene::sutLinks() const
{
  return this->_d->_sutBox->sutLinks();
}

void SutScene::setSutBoxBrush(const QBrush& sutBoxBrush)
{
    this->_d->_sutBoxBrush = sutBoxBrush;
}

QBrush SutScene::sutBoxBrush() const
{
    return this->_d->_sutBoxBrush;
}

Port* SutScene::port(const QUuid& portUuid) const
{
  foreach(Component* component,
           this->_d->_sutBox->sutComponents())
  {
    if(Port* port=component->port(portUuid))
      return port;
  }

  foreach(Link* link,
           this->_d->_sutBox->sutLinks())
  {
    if(link->linkPort()
       && link->linkPort()->uuid() == portUuid)
      return link->linkPort();
  }

  return 0;
}

} // namespace ts
} // namespace view
