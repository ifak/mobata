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

#include <mobata/model/base/modelitem.hpp>
#include <mobata/prop/nameproperty.hpp>

namespace modsim{

class SimActorItem:
    public model::base::ModelItem,
    public prop::NameProperty
{
public:
  explicit SimActorItem(const QString& name);
  ~SimActorItem();

public:
  const QStringList&  portNames() const;
  bool                addPort(const QString& portName,
                              QString* errorString);

private:
  class Private;
  Private* _d;
};

class SimMessageItem:
    public model::base::ModelItem
{
public:
  explicit SimMessageItem(const QString& signalName);
  ~SimMessageItem();

public:
  void                setSource(const QString& sourceModelName,
                                const QString& sourcePortName);
  const QString&      sourceModel() const;
  const QString&      sourcePort() const;

  void                setTarget(const QString& targetModelName,
                                const QString& targetPortName);
  const QString&      targetModel() const;
  const QString&      targetPort() const;

  const QString&      signalName() const;
  const QVariantList& messageData() const;
  void                setMessageData(const QVariantList& messageData);

private:
  class Private;
  Private* _d;
};

class SimConfigItem:
    public model::base::ModelItem
{
public:
  typedef QList<SimActorItem*>    SimActorSet;
  typedef QList<SimMessageItem*>  SimMessageSet;

public:
  SimConfigItem();
  ~SimConfigItem();

public:
  const SimActorSet&  simActors() const;
  bool                addSimActor(SimActorItem* simActor,
                                  QString* errorString);
  SimActorItem const* simActor(const QString& simActorName) const;

  const SimMessageSet&  startupMessages() const;
  void                  addStartupMessage(SimMessageItem* simMessage);

  const QStringList&  startSequence() const;
  bool                addStartSequenceModel(const QString& modelName,
                                            QString* errorString);

private:
  class Private;
  Private* _d;
};

}//namespace modsim
