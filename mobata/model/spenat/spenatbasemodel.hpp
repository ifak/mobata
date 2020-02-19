/*
 * This file is part of mobata.
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

#include "../base/basemodel.hpp"
#include "../base/portitem.hpp"
#include "../base/propports.hpp"
#include "../base/signalitem.hpp"
#include "../base/datatypeitem.hpp"
#include "../base/paramitem.hpp"
#include "../base/paramvalueitem.hpp"

#include "../graph/igraph.hpp"
#include "../graph/nodeitem.hpp"

namespace model{
namespace spenat {

using namespace base;
using namespace graph;

class PlaceItem;
class InitPlaceItem;
class TransitionItem;

typedef base::JsonObjectPtr JsonObjectPtr;
typedef base::JsonDocPtr    JsonDocPtr;

class MOBATASHARED_EXPORT SpenatBaseModel
    : public base::BaseModel,
    public base::PropPorts,
    public graph::IGraph
{
  Q_OBJECT

public:
  typedef QList<PlaceItem*>             PlaceSet;
  typedef QList<TransitionItem*>        TransitionSet;
  typedef QList<PlaceItem const*>       ConstPlaceSet;
  typedef QList<TransitionItem const*>  ConstTransitionSet;


public:
  explicit SpenatBaseModel(QObject* parent = nullptr);
  SpenatBaseModel(const QString& modelName, QObject* parent = nullptr);
  virtual ~SpenatBaseModel() override;

public:
  TransitionItem* addSignalTransition(const QString& name,
                                      const SignalItem* signal = nullptr,
                                      const PortItem* port = nullptr,
                                      const QString &guard=QLatin1String(""),
                                      const QString &actions=QLatin1String(""),
                                      const QUuid& transUuid=QUuid::createUuid(),
                                      QString* errorString = nullptr);
  TransitionItem* addTimeoutTransition(const QString& name,
                                       const double timeout = 0.0,
                                       const QString &guard=QLatin1String(""),
                                       const QString &actions=QLatin1String(""),
                                       const QUuid& transUuid=QUuid::createUuid(),
                                       QString* errorString = nullptr);
  bool             addTransition(TransitionItem* transition, QString* errorString = nullptr);
  void             removeTransition(const QUuid& transUuid);
  PlaceItem*       addPlace(const QString& name, QString* errorString = nullptr);
  bool             addPlace(PlaceItem* place, QString* errorString = nullptr);
  InitPlaceItem*   addInitPlace(PlaceItem const* placeItem, QString* errorString = nullptr);
  void             removePlace(const QUuid& placeUuid);
  bool             isInitPlace(PlaceItem const* placeItem) const;
  void             removeInitPlace(PlaceItem const* placeItem);
  PlaceItem*       place(const QUuid& placeId) const;
  PlaceItem*       place(const QString& placeName) const;
  PlaceSet         places() const;
  TransitionItem*  transition(const QUuid& transitionId) const;
  TransitionItem*  transition(const QString& name) const;
  TransitionSet    transitions() const;
  ConstPlaceSet    initPlaces() const;

public:///virtual methods
  virtual void            reset() override;
  virtual void            resetPlaces();
  virtual void            resetInitPlaces();
  virtual void            resetTransitions();
  virtual void            resetTextDecl();
  virtual void            resetGraphDecl();
  virtual NodeItem*       node(const QUuid& nodeId) override;
  virtual NodeItem const* node(const QUuid& nodeId) const override;
  virtual ConstNodeSet    nodes() const override;

  virtual ArcItem*      arc(const QUuid& arcUuid) override;
  virtual ConstArcSet   arcs() const override;
  virtual JsonObjectPtr createJson() const override;

protected:
  void removePlace(PlaceItem* place);
  void removeTransition(TransitionItem* transition);

private:
  void             createTransitionsParentItem();
  void             createPlacesParentItem();
  void             createInitPlacesParentItem();

private:
  Q_DISABLE_COPY(SpenatBaseModel)
  class Private;
  QScopedPointer<Private>	_d;
};

}/// namespace spenat
}/// namespace model
