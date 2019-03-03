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

#pragma once

#include "../../mobata_global.hpp"

#include "../graph/nodeitem.hpp"
#include "../../prop/nameproperty.hpp"

namespace model{

namespace base{
class ATriggerItem;
}

namespace spenat{

class PlaceItem;
class PrePlaceArc;
class PostPlaceArc;

class MOBATASHARED_EXPORT TransitionItem
    :	public graph::NodeItem,
    public prop::NameProperty
{
public:
  typedef QList<PrePlaceArc const*>   ConstPrePlaceArcSet;
  typedef QList<PrePlaceArc*>         PrePlaceArcSet;
  typedef QList<PostPlaceArc const*>  ConstPostPlaceArcSet;
  typedef QList<PostPlaceArc*>        PostPlaceArcSet;

public:
  TransitionItem(const QString& name,
                 base::ATriggerItem* triggerItem = nullptr,
                 const QString& guard=QLatin1String(""),
                 const QString& actions=QLatin1String(""),
                 const QUuid& uuid=QUuid::createUuid());
  virtual ~TransitionItem();

public:
  void                      resetTransProps();
  ConstPrePlaceArcSet       prePlaceArcs() const;
  PrePlaceArcSet            prePlaceArcs();
  ConstPostPlaceArcSet      postPlaceArcs() const;
  PostPlaceArcSet           postPlaceArcs();
  base::ATriggerItem const* triggerItem() const;
  const QString&            guard() const;
  const QString&            actions() const;

  PrePlaceArc*        addPrePlaceArc(PlaceItem *prePlace,
                                     const QUuid &arcUuid=QUuid::createUuid());
  PrePlaceArc const*  prePlaceArc(PlaceItem const* prePlace) const;
  PrePlaceArc const*  prePlaceArc(const QUuid& prePlaceArcUuid) const;
  void                removePrePlace(PlaceItem const* prePlace);
  PostPlaceArc*       addPostPlaceArc(PlaceItem *postPlace,
                                      const QUuid &arcUuid=QUuid::createUuid());
  PostPlaceArc const* postPlaceArc(PlaceItem const* postPlace) const;
  PostPlaceArc const* postPlaceArc(const QUuid& postPlaceArcUuid) const;
  void                removePostPlace(PlaceItem const* postPlace);
  void                setTriggerItem(base::ATriggerItem* newTrigger);
  void                setGuard(const QString& guard);
  void                setActions(const QString& actions);

  QString getLabel() const;
  QString	toString() const;

private:
  void createPrePlacesParent();
  void createPostPlacesParent();

private:
  Q_DISABLE_COPY(TransitionItem)
  class Private;
  QScopedPointer<Private>	_d;
};

}/// namespace spenat
}/// namespace model
