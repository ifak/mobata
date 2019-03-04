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

#include "spenatdeclmodel.hpp"

#include "junctionitem.hpp"
#include "junctionarc.hpp"
#include "placeitem.hpp"
#include "transitionitem.hpp"
#include "preplacearc.hpp"
#include "postplacearc.hpp"

#include "../base/statichelpers.hpp"
#include "../base/signalitem.hpp"
#include "../base/portitem.hpp"

#include "../../utils/functors.hpp"

#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

using namespace utils;

namespace model{
namespace spenat{

class SpenatDeclModel::Private
{
  friend class SpenatDeclModel;

  Private()	:	_junctionsParentItem(nullptr)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*	_junctionsParentItem;
  std::size_t     _transitionCounter;
};


SpenatDeclModel::SpenatDeclModel(QObject *parent)
  : BaseClass(parent),
    _d(new Private())
{}

SpenatDeclModel::SpenatDeclModel(const QString& name, QObject* parent)
  : BaseClass(name, parent),
    _d(new Private())
{}

SpenatDeclModel::~SpenatDeclModel()
{
  delete this->_d;
}

void SpenatDeclModel::reset()
{
  BaseClass::reset();

  if(this->_d->_junctionsParentItem)
    this->_d->_junctionsParentItem->removeRows(0, this->_d->_junctionsParentItem->rowCount());

  return;
}

void SpenatDeclModel::resetGraphDecl()
{
  BaseClass::resetGraphDecl();

  if(this->_d->_junctionsParentItem)
    this->_d->_junctionsParentItem->removeRows(0, this->_d->_junctionsParentItem->rowCount());

  return;
}

NodeItem* SpenatDeclModel::node(const QUuid &nodeId)
{
  NodeItem* node=SpenatBaseModel::node(nodeId);
  if(!node)
    node=this->junction(nodeId);

  return node;
}

NodeItem const* SpenatDeclModel::node(const QUuid& nodeId) const
{
  NodeItem const* node=SpenatBaseModel::node(nodeId);
  if(!node)
    node=this->junction(nodeId);

  return node;
}

graph::IGraph::ConstNodeSet SpenatDeclModel::nodes() const
{
  ConstNodeSet nodes;

  for(PlaceItem const* place: this->places())
    nodes.append(place);

  for(TransitionItem const* transition: this->transitions())
    nodes.append(transition);

  for(JunctionItem const* junction: this->junctions())
    nodes.append(junction);

  return nodes;
}

ArcItem *SpenatDeclModel::arc(const QUuid &arcUuid)
{
  if(ArcItem* spenatBaseArc=SpenatBaseModel::arc(arcUuid))
    return spenatBaseArc;

  for (JunctionItem const* junction: this->junctions())
  {
    if(JunctionArc const* junctionSource=junction->sourceArc(arcUuid))
      return const_cast<JunctionArc*>(junctionSource);

    if(JunctionArc const* junctionTarget=junction->targetArc(arcUuid))
      return const_cast<JunctionArc*>(junctionTarget);
  }

  return nullptr;
}

graph::IGraph::ConstArcSet SpenatDeclModel::arcs() const
{
  ConstArcSet arcs;

  for(TransitionItem const* transitionItem: this->transitions())
  {
    for(PrePlaceArc const* prePlaceArc: transitionItem->prePlaceArcs())
      arcs.append(prePlaceArc);

    for(PostPlaceArc const* postPlaceArc: transitionItem->postPlaceArcs())
      arcs.append(postPlaceArc);
  }

  for (JunctionItem const* junction: this->junctions())
  {
    for(JunctionArc const* junctionSource: junction->sources())
      arcs.append(junctionSource);

    for(JunctionArc const* junctionTarget: junction->targets())
      arcs.append(junctionTarget);
  }

  return arcs;
}

JunctionItem *SpenatDeclModel::addJunction(const QUuid &uuid)
{
  if(!this->_d->_junctionsParentItem)
  {
    this->_d->_junctionsParentItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/msc/junctionstate.png")),
                                                     QLatin1String("junctions"));
    this->_d->_junctionsParentItem->setFlags(this->_d->_junctionsParentItem->flags() & ~Qt::ItemIsEditable);
    this->appendRow(this->_d->_junctionsParentItem);
  }

  JunctionItem* newJunctionItem=new JunctionItem(uuid);
  this->_d->_junctionsParentItem->appendRow(newJunctionItem);

  return newJunctionItem;
}

JunctionItem const* SpenatDeclModel::junction(const QUuid &uuid) const
{
  return FindByUuid<JunctionSet>()(uuid, this->junctions());
}

JunctionItem *SpenatDeclModel::junction(const QUuid& uuid)
{
  return FindByUuid<JunctionSet>()(uuid, this->junctions());
}

SpenatDeclModel::JunctionSet SpenatDeclModel::junctions() const
{
  JunctionSet junctions;
  if(!this->_d->_junctionsParentItem)
    return junctions;

  int end=this->_d->_junctionsParentItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_junctionsParentItem->child(i);
    JunctionItem* junction=simple_cast<JunctionItem*>(currChild);
    Q_ASSERT(junction);
    junctions.append(junction);
  }

  return junctions;
}

bool SpenatDeclModel::isValidArc(const NodeItem *sourceNode,
                           const NodeItem *targetNode,
                           QString* errorMessage)
{
  Q_ASSERT(errorMessage);

  if(TransitionItem const* sourceTrans=dynamic_cast<TransitionItem const*>(sourceNode))
  {
    if(TransitionItem const* targetTrans=dynamic_cast<TransitionItem const*>(targetNode))
    {///error-arc
      *errorMessage=QLatin1String("arc between 2 transtions is not allowed! ")
                    +QLatin1String("source-transition:'")
                    +sourceTrans->toString()
                    +QLatin1String("' ")
                    +QLatin1String("target-transition:'")
                    +targetTrans->toString()
                    +QLatin1String("'");
      return false;
    }
    else if(JunctionItem const* targetJunct=dynamic_cast<JunctionItem const*>(targetNode))
    {///error-arc
      Q_UNUSED(targetJunct);
      *errorMessage=QLatin1String("arc between transition and "
                                  "junction is not allowed!"
                                  "source-transition:'")
                    +sourceTrans->toString()
                    +QLatin1String("'");
      return false;
    }
    else if(PlaceItem const* targetPlace=dynamic_cast<PlaceItem const*>(targetNode))
    {
      typedef TransitionItem::ConstPostPlaceArcSet	PlaceArcSet;
      if(IsPlaceAvailable<PlaceArcSet>(sourceTrans->postPlaceArcs())(targetPlace))
      {
        *errorMessage=QLatin1String("only one arc between source-transition "
                                    "and target-place is allowed!");
        return false;
      }
    }
  }
  ///source junction
  else if(JunctionItem const* sourceJunction=dynamic_cast<JunctionItem const*>(sourceNode))
  {
    Q_UNUSED(sourceJunction);

    if(TransitionItem const* targetTrans=dynamic_cast<TransitionItem const*>(targetNode))
    {///error-arc
      *errorMessage=QLatin1String("arc between junction and "
                                  "transtion is not allowed!"
                                  "target-transition:'")
                    +targetTrans->toString()
                    +QLatin1String("'");
      return false;
    }
    else if(JunctionItem const* targetJunct=dynamic_cast<JunctionItem const*>(targetNode))
    {///error-arc TODO: in future...;)
      Q_UNUSED(targetJunct);
      *errorMessage=QLatin1String("arc between 2 junctions "
                                  "is currently not allowed!");
      return false;
    }
  }
  ///source place
  else if(PlaceItem const* sourcePlace=dynamic_cast<PlaceItem const*>(sourceNode))
  {
    if(TransitionItem const* targetTrans=dynamic_cast<TransitionItem const*>(targetNode))
    {
      typedef TransitionItem::ConstPrePlaceArcSet	PlaceArcSet;
      if(IsPlaceAvailable<PlaceArcSet>(targetTrans->prePlaceArcs())(sourcePlace))
      {
        *errorMessage=QLatin1String("only one arc between source-place "
                                    "and target-transition is allowed!");
        return false;
      }
    }
  }

  return true;
}

void serializeJunctions(SpenatDeclModel const* declModel,
                        QJsonObject* json_baseModel)
{
  QJsonArray json_junctions;
  for(JunctionItem const* junctionItem: declModel->junctions())
  {
    QJsonObject json_junction;
    QJsonArray json_junctionSources;
    for(JunctionArc const* juncSourceArc : junctionItem->sources())
    {
      QJsonObject json_junctionSource;
      json_junctionSource["uuid"]=juncSourceArc->uuid().toString();
      json_junctionSource["sourceUuid"]=juncSourceArc->source()->uuid().toString();

      json_junctionSource["trigger"]=juncSourceArc->trigger();
      json_junctionSource["guard"]=juncSourceArc->guard();
      json_junctionSource["actions"]=juncSourceArc->actions();

      json_junctionSources.push_back(json_junctionSource);
    }
    json_junction["sources"]=json_junctionSources;

    QJsonArray json_junctionTargets;
    for(JunctionArc const* juncTargetArc: junctionItem->targets())
    {
      QJsonObject json_junctionTarget;

      Q_ASSERT(juncTargetArc->trigger().isEmpty());
      ////////trigger+guard+actions////////////
      json_junctionTarget["trigger"]=juncTargetArc->trigger();
      json_junctionTarget["guard"]=juncTargetArc->guard();
      json_junctionTarget["actions"]=juncTargetArc->actions();

      json_junctionTarget["targetUuid"]=juncTargetArc->target()->uuid().toString();

      json_junctionTargets.push_back(json_junctionTarget);
    }
    json_junction["targets"]=json_junctionTargets;

    json_junctions.push_back(json_junction);
  }
  json_baseModel->insert("junctions", json_junctions);

  return;
}

JsonObjectPtr SpenatDeclModel::createJson() const
{
  JsonObjectPtr json_baseModelPtr=BaseClass::createJson();
  serializeJunctions(this, json_baseModelPtr.data());

  return json_baseModelPtr;
}

}///end namespace model
}///end namespace spenat
