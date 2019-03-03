/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "spenatbasemodel.hpp"

#include "placeitem.hpp"
#include "initplaceitem.hpp"
#include "transitionitem.hpp"
#include "preplacearc.hpp"
#include "postplacearc.hpp"

#include "../base/statichelpers.hpp"
#include "../base/signalitem.hpp"
#include "../base/portitem.hpp"
#include "../base/signaltriggeritem.hpp"
#include "../base/timeouttriggeritem.hpp"

#include "../../utils/functors.hpp"

#include <QJsonArray>
#include <QJsonObject>

#include <stdexcept>

using namespace utils;
using namespace model::base;

namespace model{
namespace spenat{

class SpenatBaseModel::Private
{
  friend class SpenatBaseModel;

  Private()
    :_placesItem(nullptr),
      _transitionsItem(nullptr),
      _initPlacesItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _placesItem;
  QStandardItem*  _transitionsItem;
  QStandardItem*  _initPlacesItem;
};

SpenatBaseModel::SpenatBaseModel(QObject *parent)
  :	base::BaseModel(parent),
    base::PropPorts(this->invisibleRootItem()),
    _d(new Private())
{}

SpenatBaseModel::SpenatBaseModel(const QString& modelName, QObject* parent)
  : base::BaseModel(modelName, parent),
    base::PropPorts(this->invisibleRootItem()),
    _d(new Private())
{}

SpenatBaseModel::~SpenatBaseModel()
{}

void SpenatBaseModel::reset()
{
  BaseModel::reset();
  this->resetPorts();
  this->resetPlaces();
  this->resetInitPlaces();
  this->resetTransitions();
  this->resetTextDecl();
  this->resetGraphDecl();

  return;
}

void SpenatBaseModel::resetPlaces()
{
  if(this->_d->_placesItem)
    this->_d->_placesItem->removeRows(0, this->_d->_placesItem->rowCount());

  return;
}

void SpenatBaseModel::resetInitPlaces()
{
  if(this->_d->_initPlacesItem)
    this->_d->_initPlacesItem->removeRows(0, this->_d->_initPlacesItem->rowCount());

  return;
}

void SpenatBaseModel::resetTransitions()
{
  if(this->_d->_transitionsItem)
    this->_d->_transitionsItem->removeRows(0, this->_d->_transitionsItem->rowCount());

  return;
}

void SpenatBaseModel::resetTextDecl()
{
  this->setName(QLatin1String("Spenat"));
  return base::BaseModel::reset();
}

void SpenatBaseModel::resetGraphDecl()
{
  //spenat-graph
  if(this->_d->_placesItem)
    this->_d->_placesItem->removeRows(0, this->_d->_placesItem->rowCount());

  if(this->_d->_transitionsItem)
    this->_d->_transitionsItem->removeRows(0, this->_d->_transitionsItem->rowCount());

  if(this->_d->_initPlacesItem)
    this->_d->_initPlacesItem->removeRows(0, this->_d->_initPlacesItem->rowCount());

  return;
}

void SpenatBaseModel::createPlacesParentItem()
{
  if(this->_d->_placesItem)
    return;

  this->_d->_placesItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/spenat/manyplace.png")),
                                          QLatin1String("places"));
  this->_d->_placesItem->setFlags(this->_d->_placesItem->flags() & ~Qt::ItemIsEditable);
  this->appendRow(this->_d->_placesItem);
}

void SpenatBaseModel::createTransitionsParentItem()
{
  if(this->_d->_transitionsItem)
    return;

  this->_d->_transitionsItem=new QStandardItem(QIcon(
                                                 QLatin1String(
                                                   ":mobata/images/msc/manytransition.png")),
                                               QLatin1String("transitions"));
  this->_d->_transitionsItem->setFlags(this->_d->_transitionsItem->flags() & ~Qt::ItemIsEditable);
  this->appendRow(this->_d->_transitionsItem);
}

void SpenatBaseModel::createInitPlacesParentItem()
{
  if(this->_d->_initPlacesItem)
    return;

  this->_d->_initPlacesItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/msc/manyplace.png")),
                                              QLatin1String("init-places"));
  this->_d->_initPlacesItem->setFlags(this->_d->_initPlacesItem->flags() & ~Qt::ItemIsEditable);
  this->appendRow(this->_d->_initPlacesItem);
}

PlaceItem* SpenatBaseModel::addPlace(const QString& name, QString* errorString)
{
  QString placeName = name.trimmed();
  if(placeName.isEmpty())
  {
    AddPtrString(errorString)<<"Empty names for places are not allowed. "
                               "Every place needs an unique name!";
    return 0;
  }

  if(this->place(placeName))
  {
    AddPtrString(errorString)<<"There is already a place with name '"
                            <<name
                           <<"' available!";
    return 0;
  }

  if(!this->_d->_placesItem)
    this->createPlacesParentItem();

  PlaceItem* newPlaceItem=new PlaceItem(name);
  this->_d->_placesItem->appendRow(newPlaceItem);
  newPlaceItem->setText(newPlaceItem->toString());

  return newPlaceItem;
}

bool SpenatBaseModel::addPlace(PlaceItem* place, QString* errorString)
{
  Q_ASSERT(place);

  if(place->name().trimmed().isEmpty())
  {
    AddPtrString(errorString)<<"Empty names for places are not allowed. "
                               "Every place needs an unique name!";
    return false;
  }

  if(this->place(place->name()))
  {
    AddPtrString(errorString)<<"There is already a place with name '"
                            <<place->name()
                           <<"' available!";
    return false;
  }

  if(!this->_d->_placesItem)
    this->createPlacesParentItem();

  this->_d->_placesItem->appendRow(place);
  place->setText(place->toString());

  return true;
}

InitPlaceItem* SpenatBaseModel::addInitPlace(PlaceItem const* placeItem, QString* errorString)
{
  if(!placeItem)
    return nullptr;

  if(!utils::IsAvailable<PlaceSet>(this->places())(placeItem))
  {
    utils::AddPtrString(errorString)<<"place item '"<<placeItem->name()<<"' is not available, cannot be added as init place";
    return nullptr;
  }

  if(!this->_d->_initPlacesItem)
    this->createInitPlacesParentItem();

  for(PlaceItem const* existInitPlace : this->initPlaces())
  {
    if(existInitPlace == placeItem)
    {
      utils::AddPtrString(errorString) << "place item '" << placeItem->name() << "' is already an init place!";
      return nullptr;
    }
  }

  InitPlaceItem* newInitPlaceItem=new InitPlaceItem(placeItem);
  this->_d->_initPlacesItem->appendRow(newInitPlaceItem);

  return newInitPlaceItem;
}

bool SpenatBaseModel::isInitPlace(const PlaceItem *placeItem) const
{
  if(!placeItem)
    return false;

  return IsAvailable<ConstPlaceSet>(this->initPlaces())(placeItem);
}

void SpenatBaseModel::removeInitPlace(const PlaceItem *placeItem)
{
  if(!this->_d->_initPlacesItem)
    return;

  int end=this->_d->_initPlacesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* child=this->_d->_initPlacesItem->child(i);
    InitPlaceItem* initPlaceItem=simple_cast<InitPlaceItem*>(child);
    Q_ASSERT(initPlaceItem);
    if(initPlaceItem->getPlaceItem()==placeItem)
    {
      this->_d->_initPlacesItem->removeRow(initPlaceItem->row());
      return;
    }
  }

  return;
}

TransitionItem* SpenatBaseModel::addSignalTransition(const QString& name,
                                                     const SignalItem* signal,
                                                     const PortItem* port,
                                                     const QString &guard,
                                                     const QString &actions,
                                                     const QUuid &transUuid,
                                                     QString* errorString)
{
  TransitionItem* newTransitionItem=new TransitionItem(name,
                                                       new SignalTriggerItem(signal, port),
                                                       guard,
                                                       actions,
                                                       transUuid);
  if(!this->addTransition(newTransitionItem, errorString))
  {
    delete newTransitionItem;
    return 0;
  }

  return newTransitionItem;
}

TransitionItem* SpenatBaseModel::addTimeoutTransition(const QString& name,
                                                      const double timeout,
                                                      const QString& guard,
                                                      const QString& actions,
                                                      const QUuid& transUuid,
                                                      QString* errorString)
{
  TransitionItem* newTransitionItem=new TransitionItem(name,
                                                       new TimeoutTriggerItem(timeout),
                                                       guard,
                                                       actions,
                                                       transUuid);
  if(!this->addTransition(newTransitionItem, errorString))
  {
    delete newTransitionItem;
    return 0;
  }

  return newTransitionItem;
}

bool SpenatBaseModel::addTransition(TransitionItem* transition, QString* errorString)
{
  Q_ASSERT(transition);

  if(this->transition(transition->name()))
  {
    AddPtrString(errorString)<<"There is already a transition with name '"
                            <<transition->name()
                           <<"' available!";
    return false;
  }

  if(this->transition(transition->uuid()))
  {
    AddPtrString(errorString) << "transition with uuid '"
                              << transition->uuid().toString()
                              <<"' is still available!";
    return false;
  }

  if(!this->_d->_transitionsItem)
    this->createTransitionsParentItem();

  Q_ASSERT(!this->transition(transition->uuid()));

  this->_d->_transitionsItem->appendRow(transition);
  transition->setText(transition->toString());

  return true;
}

PlaceItem* SpenatBaseModel::place(const QString &placeName) const
{
  for(PlaceItem* placeItem: this->places())
    if(placeItem->name()==placeName)
      return placeItem;

  return 0;
}

PlaceItem* SpenatBaseModel::place(const QUuid& placeUuid) const
{
  for(PlaceItem* placeItem: this->places())
    if(placeItem->uuid()==placeUuid)
      return placeItem;

  return 0;
}

SpenatBaseModel::PlaceSet SpenatBaseModel::places() const
{
  PlaceSet places;
  if(!this->_d->_placesItem)
    return places;

  int end=this->_d->_placesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    PlaceItem* place=simple_cast<PlaceItem*>(this->_d->_placesItem->child(i));
    Q_ASSERT(place);
    places.append(place);
  }

  return places;
}

SpenatBaseModel::TransitionSet SpenatBaseModel::transitions() const
{
  TransitionSet transitions;
  if(!this->_d->_transitionsItem)
    return transitions;

  int end=this->_d->_transitionsItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    TransitionItem* transition=simple_cast<TransitionItem*>(this->_d->_transitionsItem->child(i));
    Q_ASSERT(transition);
    transitions.append(transition);
  }

  return transitions;
}

SpenatBaseModel::ConstPlaceSet SpenatBaseModel::initPlaces() const
{
  ConstPlaceSet initPlaces;
  if(!this->_d->_initPlacesItem)
    return initPlaces;

  int end=this->_d->_initPlacesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* child=this->_d->_initPlacesItem->child(i);
    InitPlaceItem* initPlaceItem=simple_cast<InitPlaceItem*>(child);
    Q_ASSERT(initPlaceItem);
    if(initPlaceItem->getPlaceItem())
      initPlaces.append(initPlaceItem->getPlaceItem());
  }

  return initPlaces;
}


NodeItem* SpenatBaseModel::node(const QUuid &nodeId)
{
  NodeItem* node=this->place(nodeId);
  if(!node)
    node=this->transition(nodeId);

  return node;
}

NodeItem const* SpenatBaseModel::node(const QUuid& nodeId) const
{
  NodeItem const* node=this->place(nodeId);
  if(!node)
    node=this->transition(nodeId);

  return node;
}

graph::IGraph::ConstNodeSet SpenatBaseModel::nodes() const
{
  ConstNodeSet nodes;

  for(PlaceItem const* place: this->places())
    nodes.append(place);

  for(TransitionItem const* transition: this->transitions())
    nodes.append(transition);

  return nodes;
}

ArcItem* SpenatBaseModel::arc(const QUuid &arcUuid)
{
  for(TransitionItem const* transitionItem: this->transitions())
  {
    if(PrePlaceArc const* prePlaceArc=transitionItem->prePlaceArc(arcUuid))
      return const_cast<PrePlaceArc*>(prePlaceArc);
    if(PostPlaceArc const* postPlaceArc=transitionItem->postPlaceArc(arcUuid))
      return const_cast<PostPlaceArc*>(postPlaceArc);
  }

  return 0;
}

graph::IGraph::ConstArcSet SpenatBaseModel::arcs() const
{
  ConstArcSet arcs;

  for(TransitionItem const* transitionItem: this->transitions())
  {
    for(PrePlaceArc const* prePlaceArc: transitionItem->prePlaceArcs())
      arcs.append(prePlaceArc);

    for(PostPlaceArc const* postPlaceArc:transitionItem->postPlaceArcs())
      arcs.append(postPlaceArc);
  }

  return arcs;
}

TransitionItem* SpenatBaseModel::transition(const QUuid &transitionId) const
{
  if(!this->_d->_transitionsItem)
    return 0;

  for(TransitionItem* transition : this->transitions())
  {
    if(transition->uuid()==transitionId)
      return transition;
  }

  return 0;
}

TransitionItem* SpenatBaseModel::transition(const QString& name) const
{
  if(!this->_d->_transitionsItem)
    return 0;

  for(TransitionItem* transition : this->transitions())
  {
    if(transition->name()==name)
      return transition;
  }

  return 0;
}

void serializePlaces(SpenatBaseModel const* baseModel, QJsonObject* json_baseModel)
{
  QJsonArray json_places;
  for(PlaceItem const* placeItem: baseModel->places())
  {
    QJsonObject json_place;
    json_place["uuid"]=placeItem->uuid().toString();
    json_place["name"]=placeItem->name();

    json_places.push_back(json_place);
  }
  json_baseModel->insert("places", json_places);

  return;
}

void serializeTransitions(SpenatBaseModel const* baseModel, QJsonObject* json_baseModel)
{
  QJsonArray json_transitions;
  for(TransitionItem const* transItem: baseModel->transitions())
  {
    QJsonObject json_transition;
    json_transition["name"]=transItem->name();
    json_transition["uuid"]=transItem->uuid().toString();

    QJsonObject json_trigger;
    ATriggerItem const* trigger = transItem->triggerItem();
    if(trigger)
    {
      if(trigger->triggerType() == ATriggerItem::EventTrigger)
      {
        SignalTriggerItem const* signalTrigger = static_cast<SignalTriggerItem const*>(trigger);
        Q_ASSERT(signalTrigger);
        json_trigger["type"]=QLatin1String("EventTrigger");
        if(signalTrigger->triggerSignal())
          json_trigger["signalUuid"]=signalTrigger->triggerSignal()->uuid().toString();
        if(signalTrigger->port())
          json_trigger["port"]=signalTrigger->port()->name();
      }
      else if(trigger->triggerType() == ATriggerItem::TimeoutTrigger)
      {
        TimeoutTriggerItem const* timeoutTrigger = static_cast<TimeoutTriggerItem const*>(trigger);
        Q_ASSERT(timeoutTrigger);

        json_trigger["type"]=QLatin1String("TimeoutTrigger");
        json_trigger["timeout"]=timeoutTrigger->value();
      }
      json_transition["trigger"]=json_trigger;
    }

    ////////guard+actions////////////
    json_transition["guard"]=transItem->guard();
    json_transition["actions"]=transItem->actions();

    json_transitions.push_back(json_transition);
  }
  json_baseModel->insert("transitions", json_transitions);

  return;
}

void serializeInitPlaces(SpenatBaseModel const* baseModel,
                         QJsonObject* json_baseModel)
{
  QJsonArray json_initPlacesArray;
  for(PlaceItem const* initPlaceItem: baseModel->initPlaces())
    json_initPlacesArray.push_back(initPlaceItem->uuid().toString());
  json_baseModel->insert("initPlaces", json_initPlacesArray);

  return;
}

JsonObjectPtr SpenatBaseModel::createJson() const
{
  JsonObjectPtr json_baseModelPtr=base::BaseModel::createJson();

  base::writePorts(this, json_baseModelPtr.data());
  serializePlaces(this, json_baseModelPtr.data());
  serializeTransitions(this, json_baseModelPtr.data());
  serializeInitPlaces(this, json_baseModelPtr.data());

  return json_baseModelPtr;
}

void SpenatBaseModel::removePlace(const QUuid &placeUuid)
{
  for(PlaceItem* place: this->places())
  {
    if(place->uuid()==placeUuid)
      this->_d->_placesItem->removeRow(place->row());
  }

  return;
}

void SpenatBaseModel::removePlace(PlaceItem *place)
{
  if(!place)
    return;

  Q_ASSERT(place->model()==this);

  if(this->_d->_placesItem)
    this->_d->_placesItem->removeRow(place->row());

  return;
}

void SpenatBaseModel::removeTransition(const QUuid &transUuid)
{
  for(TransitionItem* transition: this->transitions())
  {
    if(transition->uuid()==transUuid)
      this->_d->_transitionsItem->removeRow(transition->row());
  }

  return;
}

void SpenatBaseModel::removeTransition(TransitionItem *transition)
{
  if(!transition)
    return;

  Q_ASSERT(transition->model()==this);

  if(this->_d->_transitionsItem)
    this->_d->_transitionsItem->removeRow(transition->row());

  return;
}

}///end namespace model
}///end namespace spenat
