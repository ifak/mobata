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

#include "transitionitem.hpp"

#include "placeitem.hpp"
#include "preplacearc.hpp"
#include "postplacearc.hpp"

#include "../base/atriggeritem.hpp"
#include "../base/signaltriggeritem.hpp"
#include "../base/timeouttriggeritem.hpp"

#include "../base/signalitem.hpp"

#include "../../utils/functors.hpp"

using namespace utils;

namespace model{

using namespace base;

namespace spenat{

template<class PlaceArcSet>
QString placesString(const PlaceArcSet& placeArcs)
{
  QString placesString=QLatin1String("");

  int pos=0;
  for(const typename PlaceArcSet::value_type& placeArc : placeArcs)
  {
    if(!placeArc->place())
      continue;

    if(pos)
      placesString+=QLatin1String(",");
    placesString+=placeArc->place()->name();

    ++pos;
  }

  return placesString;
}

class TransitionItem::Private
{
  friend class TransitionItem;

public:
  Private(ATriggerItem* triggerItem,
          const QString &guard,
          const QString &actions)
    :	_prePlacesItem(nullptr),
      _postPlacesItem(nullptr),
      _triggerItem(triggerItem),
      _guard(guard),
      _actions(actions)
  {}
  ~Private()
  {}

private:
  QStandardItem*  _prePlacesItem;
  QStandardItem*  _postPlacesItem;
  ATriggerItem*   _triggerItem;
  QString         _guard;
  QString         _actions;
};

TransitionItem::TransitionItem(const QString& name,
                               ATriggerItem* triggerItem,
                               const QString &guard,
                               const QString &actions,
                               const QUuid &uuid)
  : NodeItem(uuid), prop::NameProperty(name),
    _d(new Private(triggerItem, guard, actions))
{
  this->setText(this->name());
  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/transition.png")));
}

TransitionItem::~TransitionItem()
{
  if(this->_d->_triggerItem)
    delete this->_d->_triggerItem;
}

void TransitionItem::resetTransProps()
{
  this->setTriggerItem(nullptr);
  this->setGuard(QLatin1String(""));
  this->setActions(QLatin1String(""));

  return;
}

TransitionItem::ConstPrePlaceArcSet	TransitionItem::prePlaceArcs() const
{
  ConstPrePlaceArcSet prePlaceArcs;
  if(!this->_d->_prePlacesItem)
    return prePlaceArcs;

  int end=this->_d->_prePlacesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_prePlacesItem->child(i);
    PrePlaceArc* prePlaceArc=simple_cast<PrePlaceArc*>(currChild);
    Q_ASSERT(prePlaceArc);
    prePlaceArcs.append(prePlaceArc);
  }

  return prePlaceArcs;
}

TransitionItem::PrePlaceArcSet TransitionItem::prePlaceArcs()
{
  PrePlaceArcSet prePlaceArcs;
  if(!this->_d->_prePlacesItem)
    return prePlaceArcs;

  int end=this->_d->_prePlacesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_prePlacesItem->child(i);
    PrePlaceArc* prePlaceArc=simple_cast<PrePlaceArc*>(currChild);
    Q_ASSERT(prePlaceArc);
    prePlaceArcs.append(prePlaceArc);
  }

  return prePlaceArcs;
}

TransitionItem::ConstPostPlaceArcSet TransitionItem::postPlaceArcs() const
{
  ConstPostPlaceArcSet postPlaceArcs;
  if(!this->_d->_postPlacesItem)
    return postPlaceArcs;

  int end=this->_d->_postPlacesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_postPlacesItem->child(i);
    PostPlaceArc* postPlaceArc=simple_cast<PostPlaceArc*>(currChild);
    Q_ASSERT(postPlaceArc);
    postPlaceArcs.append(postPlaceArc);
  }

  return postPlaceArcs;
}

TransitionItem::PostPlaceArcSet TransitionItem::postPlaceArcs()
{
  PostPlaceArcSet postPlaceArcs;
  if(!this->_d->_postPlacesItem)
    return postPlaceArcs;

  int end=this->_d->_postPlacesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_postPlacesItem->child(i);
    PostPlaceArc* postPlaceArc=simple_cast<PostPlaceArc*>(currChild);
    Q_ASSERT(postPlaceArc);
    postPlaceArcs.append(postPlaceArc);
  }

  return postPlaceArcs;
}

ATriggerItem const* TransitionItem::triggerItem() const
{
  return this->_d->_triggerItem;
}

const QString& TransitionItem::guard() const
{
  return this->_d->_guard;
}

const QString&	TransitionItem::actions() const
{
  return this->_d->_actions;
}

void TransitionItem::createPrePlacesParent()
{
  if(this->_d->_prePlacesItem)
    return;

  this->_d->_prePlacesItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/spenat/manyplace.png")),
                                             QLatin1String("pre-places"));
  this->_d->_prePlacesItem->setFlags(this->_d->_prePlacesItem->flags() & ~Qt::ItemIsEditable);
  this->appendRow(this->_d->_prePlacesItem);
}

PrePlaceArc *TransitionItem::addPrePlaceArc(PlaceItem* prePlace,
                                            const QUuid& arcUuid)
{
  if(!prePlace)
    return nullptr;

  if(!this->_d->_prePlacesItem)
    this->createPrePlacesParent();

  if(this->prePlaceArc(prePlace))
    return nullptr;

  PrePlaceArc* newPlaceArc=new PrePlaceArc(prePlace, this, arcUuid);
  this->_d->_prePlacesItem->appendRow(newPlaceArc);

  return newPlaceArc;
}

PrePlaceArc const* TransitionItem::prePlaceArc(const PlaceItem *prePlace) const
{
  if(!prePlace)
    return nullptr;

  return FindByPlace<ConstPrePlaceArcSet>()(prePlace, this->prePlaceArcs());
}

PrePlaceArc const* TransitionItem::prePlaceArc(const QUuid& arcUuid) const
{
  if(arcUuid.isNull())
    return nullptr;

  return FindByUuid<ConstPrePlaceArcSet>()(arcUuid, this->prePlaceArcs());
}

void TransitionItem::removePrePlace(const PlaceItem *prePlace)
{
  if(!prePlace)
    return;

  for(PrePlaceArc const* prePlaceArc : this->prePlaceArcs())
  {
    if(prePlaceArc->place()==prePlace)
      this->_d->_prePlacesItem->removeRow(prePlaceArc->row());
  }

  return;
}

void TransitionItem::createPostPlacesParent()
{
  if(this->_d->_postPlacesItem)
    return;

  this->_d->_postPlacesItem=new QStandardItem(QIcon(QLatin1String(":mobata/images/spenat/manyplace.png")),
                                              QLatin1String("post-places"));
  this->_d->_postPlacesItem->setFlags(this->_d->_postPlacesItem->flags() & ~Qt::ItemIsEditable);
  this->appendRow(this->_d->_postPlacesItem);

  return;
}

PostPlaceArc* TransitionItem::addPostPlaceArc(PlaceItem* postPlace,
                                              const QUuid &arcUuid)
{
  if(!postPlace)
    return nullptr;

  if(!this->_d->_postPlacesItem)
    this->createPostPlacesParent();

  if(this->postPlaceArc(postPlace))
    return nullptr;

  PostPlaceArc* newPlaceArc=new PostPlaceArc(this, postPlace, arcUuid);
  this->_d->_postPlacesItem->appendRow(newPlaceArc);

  return newPlaceArc;
}

PostPlaceArc const* TransitionItem::postPlaceArc(const PlaceItem *postPlace) const
{
  if(!postPlace)
    return nullptr;

  return FindByPlace<ConstPostPlaceArcSet>()(postPlace, this->postPlaceArcs());
}

PostPlaceArc const* TransitionItem::postPlaceArc(const QUuid& arcUuid) const
{
  if(arcUuid.isNull())
    return nullptr;

  return FindByUuid<ConstPostPlaceArcSet>()(arcUuid, this->postPlaceArcs());
}

void TransitionItem::removePostPlace(const PlaceItem *postPlace)
{
  if(!postPlace)
    return;

  for(PostPlaceArc const* postPlaceArc : this->postPlaceArcs())
  {
    if(postPlaceArc->place()==postPlace)
      this->_d->_postPlacesItem->removeRow(postPlaceArc->row());
  }

  return;
}

void TransitionItem::setTriggerItem(ATriggerItem* newTriggerItem)
{
  delete this->_d->_triggerItem;
  this->_d->_triggerItem = newTriggerItem;

  return;
}

void TransitionItem::setGuard(const QString& guard)
{
  this->_d->_guard = guard.trimmed();

  return;
}

void TransitionItem::setActions(const QString& actions)
{
  this->_d->_actions = actions.trimmed();

  return;
}

QString TransitionItem::getLabel() const
{
  QString declaration = this->name()+QStringLiteral(":");

  if(this->_d->_triggerItem)
    declaration+=this->_d->_triggerItem->declaration();

  if(!this->_d->_guard.isEmpty())
  {
    declaration+=QLatin1String("[");
    declaration+=this->_d->_guard;
    declaration+=QLatin1String("]");
  }

  if(!this->_d->_actions.isEmpty())
  {
    declaration+=QLatin1String("/");
    declaration+=this->_d->_actions;
  }

  if(declaration.at(declaration.size()-1) == QStringLiteral(":"))
    declaration.remove(declaration.size()-1, 1);///remove last ':'

  return declaration;
}

QString TransitionItem::toString() const
{
  return this->getLabel();
}

}///end namespace model
}///end namespace spenat
