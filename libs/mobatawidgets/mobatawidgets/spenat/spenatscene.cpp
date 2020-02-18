#include "spenatscene.hpp"

#include "declplace.hpp"
#include "decltransition.hpp"
#include "declarc.hpp"

#include "../base/textitem.hpp"
#include "../graph/functors.hpp"

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace view{
namespace spenat{

class SpenatScene::Private
{
  friend class SpenatScene;

  Private()
    :	 _currentPlaceID(0), _currentTransID(0)
  {}

  quint32	_currentPlaceID;
  quint32	_currentTransID;
};

SpenatScene::SpenatScene(QObject *parent)
  : GraphScene(parent), _d(new Private())
{
  this->setName(QStringLiteral("spenat"));
}

SpenatScene::~SpenatScene()
{}

void SpenatScene::reset()
{
  this->clear();
  this->_d->_currentPlaceID=0;
  this->_d->_currentTransID=0;
  this->setName(QStringLiteral(""));

  return;
}

DeclPlace *SpenatScene::place(QUuid placeUuid)
{
  return graph::graphSceneItem<DeclPlace>(placeUuid, this);
}

const DeclPlace *SpenatScene::place(QUuid placeUuid) const
{
  return graph::graphSceneItem<DeclPlace const>(placeUuid, this);
}

DeclTransition *SpenatScene::transition(QUuid transitionUuid)
{
  return graph::graphSceneItem<DeclTransition>(transitionUuid, this);
}

const DeclTransition *SpenatScene::transition(QUuid transitionUuid) const
{
  return graph::graphSceneItem<DeclTransition const>(transitionUuid, this);
}

QList<DeclPlace const*> SpenatScene::places() const
{
  return graph::graphSceneItems<DeclPlace const>(this);
}

QList<DeclPlace *> SpenatScene::places()
{
  return graph::graphSceneItems<DeclPlace>(this);
}

QList<DeclTransition const*> SpenatScene::transitions() const
{
  return graph::graphSceneItems<DeclTransition const>(this);
}

QList<DeclTransition *> SpenatScene::transitions()
{
  return graph::graphSceneItems<DeclTransition>(this);
}

const graph::AbstractNode *SpenatScene::node(const QUuid &nodeUuid) const
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
  }

  return 0;
}

graph::AbstractNode *SpenatScene::node(const QUuid &nodeUuid)
{
  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
    {
      if(currNode->uuid()==nodeUuid)
        return currNode;
    }
  }

  return 0;
}

SpenatScene::ConstNodeSet SpenatScene::nodes() const
{
  ConstNodeSet nodes;

  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
      nodes.append(currNode);
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
      nodes.append(currNode);
  }

  return nodes;
}

SpenatScene::NodeSet SpenatScene::nodes()
{
  NodeSet nodes;

  foreach(QGraphicsItem* currItem, this->items())
  {
    if(DeclPlace* currNode=qgraphicsitem_cast<DeclPlace*>(currItem))
      nodes.append(currNode);
    else if(DeclTransition* currNode=qgraphicsitem_cast<DeclTransition*>(currItem))
      nodes.append(currNode);
  }

  return nodes;
}

graph::Edge const* SpenatScene::edge(const QUuid &edgeUuid) const
{
  return this->arc(edgeUuid);
}

graph::Edge* SpenatScene::edge(const QUuid &edgeUuid)
{
  return this->arc(edgeUuid);
}

SpenatScene::ConstEdgeSet SpenatScene::edges() const
{
  return graph::graphSceneItems<DeclArc const, ConstEdgeSet>(this);
}

SpenatScene::EdgeSet SpenatScene::edges()
{
  return graph::graphSceneItems<DeclArc, EdgeSet>(this);
}

void SpenatScene::removeGraphItem(QGraphicsItem* graphItem)
{
  if(!graphItem)
    return;

  if(DeclPlace* selectedPlace=dynamic_cast<DeclPlace*>(graphItem))
    this->removePlace(selectedPlace);
  else if(DeclTransition* selectedTransition=dynamic_cast<DeclTransition*>(graphItem))
    this->removeTransition(selectedTransition);
  else if(DeclArc* selectedArc=dynamic_cast<DeclArc*>(graphItem))
    this->removeArc(selectedArc);

  return;
}

const DeclArc *SpenatScene::arc(const graph::AbstractNode *source,
                                const graph::AbstractNode *target) const
{
  foreach(DeclArc const* arc, this->arcs())
    if(arc->source()==source && arc->target()==target)
      return arc;

  return 0;
}

DeclArc const*  SpenatScene::arc(const QUuid& arcUuid) const
{
  foreach(DeclArc const* arc, this->arcs())
    if(arc->uuid()==arcUuid)
      return arc;

  return 0;
}

DeclArc*  SpenatScene::arc(const QUuid& arcUuid)
{
  foreach(DeclArc* arc, this->arcs())
    if(arc->uuid()==arcUuid)
      return arc;

  return 0;
}

QList<DeclArc const*> SpenatScene::arcs() const
{
  return graph::graphSceneItems<DeclArc const>(this);
}

QList<DeclArc*> SpenatScene::arcs()
{
  return graph::graphSceneItems<DeclArc>(this);
}

DeclPlace* SpenatScene::addPlace(QPointF pos, QUuid placeUuid)
{
  return this->addPlace(pos, QString(QLatin1String("p%1")).arg(this->_d->_currentPlaceID),
                        placeUuid);
}

DeclPlace* SpenatScene::addPlace(QPointF pos,
                                 const QString& placeNotation,
                                 QUuid placeUuid)
{
  DeclPlace* newDeclPlace=new DeclPlace(placeNotation, PlaceOptions());
  ++this->_d->_currentPlaceID;
  newDeclPlace->setUuid(placeUuid);
  this->addItem(newDeclPlace);
  newDeclPlace->setPos(this->onGrid(pos));//TODO: onGrid(pos)

  emit placeAdded(newDeclPlace->uuid(),
                  newDeclPlace->notation());
  emit graphModified(true);

  return newDeclPlace;
}

DeclPlace* SpenatScene::addPlace(QPointF pos,
                                 const QString& placeName,
                                 const PlaceOptions& placeOptions,
                                 QUuid placeUuid)
{
  DeclPlace* newDeclPlace=new DeclPlace(placeName, placeOptions);
  ++this->_d->_currentPlaceID;
  newDeclPlace->setUuid(placeUuid);
  this->addItem(newDeclPlace);
  newDeclPlace->setPos(this->onGrid(pos));//TODO: onGrid(pos)

  connect(newDeclPlace, SIGNAL(textChanged(graph::AbstractNode const*)),
          this, SLOT(nodeTextChangedSlot(graph::AbstractNode const*)));

  emit placeAdded(newDeclPlace->uuid(), newDeclPlace->notation());
  emit graphModified(true);

  return newDeclPlace;
}

DeclTransition* SpenatScene::addTransition(QPointF pos,
                                           QUuid transUuid)
{
  return this->addTransition(pos,
                             QString(QLatin1String("t%1")).arg(this->_d->_currentTransID),
                             transUuid);
}

DeclTransition* SpenatScene::addTransition(QPointF pos,
                                           const QString& transNotation,
                                           QUuid transUuid)
{
  DeclTransition* newDeclTransition=new DeclTransition(transNotation,
                                                       TransitionOptions());
  ++this->_d->_currentTransID;
  newDeclTransition->setUuid(transUuid);
  this->addItem(newDeclTransition);
  newDeclTransition->setPos(this->onGrid(pos));//TODO: onGrid(pos)

  emit transitionAdded(newDeclTransition->uuid(), newDeclTransition->notation());
  emit graphModified(true);

  return newDeclTransition;
}

DeclTransition* SpenatScene::addTransition(QPointF pos,
                                           const QString& transDecl,
                                           QPointF transDeclPos,
                                           const TransitionOptions &transitionOptions,
                                           QUuid transitionID)
{
  DeclTransition* newDeclTransition=new DeclTransition(transDecl,
                                                       transitionOptions);
  ++this->_d->_currentTransID;
  newDeclTransition->setUuid(transitionID);
  this->addItem(newDeclTransition);
  newDeclTransition->setPos(this->onGrid(pos));//TODO: onGrid(pos)
  newDeclTransition->notationItem()->setPos(transDeclPos);

  connect(newDeclTransition, SIGNAL(textChanged(graph::AbstractNode const*)),
          this, SLOT(nodeTextChangedSlot(graph::AbstractNode const*)));

  emit transitionAdded(newDeclTransition->uuid(), newDeclTransition->notation());
  emit graphModified(true);

  return newDeclTransition;
}

DeclArc *SpenatScene::addArc(graph::AbstractNode *from,
                             graph::AbstractNode *to,
                             const QString &arcLabel,
                             QUuid arcID)
{
  QPainterPath path(from->mapToScene(from->pos()));
  path.lineTo(to->mapToScene(to->pos()));

  return this->addArc(from,to,path,arcLabel,arcID);
}

DeclArc *SpenatScene::addArc(graph::AbstractNode *from,
                             graph::AbstractNode *to,
                             QPainterPath path,
                             const QString &arcLabel,
                             QUuid arcID)
{
  DeclArc* newArc=new DeclArc(from, to, arcLabel, arcID,ArcOptions());
  this->addItem(newArc);
  newArc->updatePath(path);

  emit arcAdded(newArc->uuid(),
                newArc->source()->uuid(),
                newArc->target()->uuid(),
                newArc->notation());

  emit graphModified(true);

  return newArc;
}

DeclArc *SpenatScene::addArc(graph::AbstractNode *from,
                             graph::AbstractNode *to,
                             QPainterPath path,
                             const QString &arcLabel,
                             QPointF arcLabelPos,
                             const ArcOptions &arcOptions,
                             QUuid arcID)
{
  DeclArc* newArc=new DeclArc(from, to, arcLabel, arcID, arcOptions);
  this->addItem(newArc);
  newArc->updatePath(path);
  newArc->notationItem()->setPos(arcLabelPos);

  emit arcAdded(newArc->uuid(),
                newArc->source()->uuid(),
                newArc->target()->uuid(),
                newArc->notation());

  emit graphModified(true);

  return newArc;
}

void SpenatScene::removePlace(const QUuid &placeUuid)
{
  DeclPlace* place=graph::graphSceneItem<DeclPlace>(placeUuid, this);
  if(place)
    return this->removePlace(place);

  return;
}

void SpenatScene::removePlace(DeclPlace* place)
{
  if(!place)
    return;

  QUuid placeUuid=place->uuid();
  this->removeNode(place);
  emit placeRemoved(placeUuid);

  return;
}

void SpenatScene::removeTransition(const QUuid &transitionUuid)
{
  DeclTransition* transition=graph::graphSceneItem<DeclTransition>(transitionUuid, this);
  if(transition)
    return this->removeTransition(transition);

  return;
}

void SpenatScene::removeTransition(DeclTransition* transition)
{
  if(!transition)
    return;

  QUuid transUuid=transition->uuid();
  this->removeNode(transition);
  emit transitionRemoved(transUuid);

  return;
}

void SpenatScene::removeArc(const QUuid &arcUuid)
{
  DeclArc* arc=graph::graphSceneItem<DeclArc>(arcUuid, this);
  if(arc)
    return this->removeArc(arc);

  return;
}

void SpenatScene::removeArc(DeclArc* arc)
{
  if(!arc)
    return;

  QUuid arcUuid, sourceUuid, targetUuid;

  arcUuid=arc->uuid();
  if(arc->source())
    sourceUuid=arc->source()->uuid();
  if(arc->target())
    targetUuid=arc->target()->uuid();

  this->removeEdge(arc);
  emit arcRemoved(arcUuid, sourceUuid, targetUuid);

  return;
}

void SpenatScene::nodeTextChangedSlot(graph::AbstractNode const* node)
{
  emit graphModified(true);

  if(DeclPlace const* declPlace=dynamic_cast<DeclPlace const*>(node))
    emit placeChanged(declPlace->uuid(),
                      declPlace->notation(),
                      declPlace->getInitMarking());
  else if(DeclTransition const* declTransition=dynamic_cast<DeclTransition const*>(node))
    emit transitionChanged(declTransition->uuid(), declTransition->notation());
  return;
}

void SpenatScene::arcTextChangedSlot(graph::Edge const* edge)
{
  emit graphModified(true);

  emit arcChanged(edge->uuid(), edge->source()->uuid(),
                  edge->target()->uuid(), edge->notation());

  return;
}

void SpenatScene::changeInitMarking(DeclPlace* declPlace)
{
  if(!declPlace)
    return;

  declPlace->setInitMarking(!declPlace->getInitMarking());
  declPlace->setMarking(declPlace->getInitMarking());

  emit placeChanged(declPlace->uuid(),
                    declPlace->notation(),
                    declPlace->getInitMarking());

  return;
}

bool SpenatScene::isValidArc(const graph::AbstractNode *sourceNode,
                             const graph::AbstractNode *targetNode,
                             QString* errorMessage) const
{
  Q_ASSERT(errorMessage);

  using namespace spenat;

  if(DeclTransition const* sourceTrans=dynamic_cast<DeclTransition const*>(sourceNode))
  {
    if(DeclTransition const* targetTrans=dynamic_cast<DeclTransition const*>(targetNode))
    {///error-arc
      *errorMessage=tr("arc between 2 transtions is not allowed! "
                       "source-transition:'%1' target-transition:'%2'")
                    .arg(sourceTrans->notation())
                    .arg(targetTrans->notation());
      return false;
    }
    else if(DeclPlace const* targetPlace=dynamic_cast<DeclPlace const*>(targetNode))
    {
      if(this->arc(sourceTrans, targetPlace))
      {
        *errorMessage=QLatin1String("only one arc between source-transition "
                                    "and target-place is allowed!");
        return false;
      }
    }
  }
  ///source place
  else if(DeclPlace const* sourcePlace=dynamic_cast<DeclPlace const*>(sourceNode))
  {
    if(DeclTransition const* targetTrans=dynamic_cast<DeclTransition const*>(targetNode))
    {
      if(this->arc(sourcePlace, targetTrans))
      {
        *errorMessage=QLatin1String("only one arc between source-place "
                                    "and target-transition is allowed!");
        return false;
      }
    }
  }

  return true;
}

}///end namespace spenat
}///end namespace view
