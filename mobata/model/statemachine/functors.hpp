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
#include "abstractstateitem.hpp"
#include "compositestateitem.hpp"
#include "concurrentstateitem.hpp"
#include "propstates.hpp"
#include "regionitem.hpp"

namespace model{
namespace statemachine {

template<class StatesModel>
AbstractStateItem* statesRecursiveByName(StatesModel* statesModel,
                                         const QString& name, AbstractStateItem* resParent = nullptr);

template<class StatesModel>
AbstractStateItem* statesRecursiveByUuid(StatesModel* statesModel,
                                         const QUuid& stateId)
{
  Q_ASSERT(statesModel);

  for(AbstractStateItem* stateItem : statesModel->states())
  {
    if(stateItem->stateType() == Concurrent)
    {
      ConcurrentStateItem* concurrent = utils::simple_cast<ConcurrentStateItem*>(stateItem);
      Q_ASSERT(concurrent);
      for(auto region : concurrent->regions())
      {
        if(AbstractStateItem* targetItem = statesRecursiveByUuid(region, stateId))
          return targetItem;
      }
    }
    else if(stateItem->stateType() == Composite)
    {
      CompositeStateItem* composite = utils::simple_cast<CompositeStateItem*>(stateItem);
      Q_ASSERT(composite);
      if(AbstractStateItem* targetItem = statesRecursiveByUuid(composite, stateId))
        return targetItem;
    }
    else if(stateItem->uuid()==stateId)
      return stateItem;
  }

  return nullptr;
}

template<class StatesModel>
AbstractStateItem const* constStatesRecursiveByUuid(const StatesModel* statesModel,
                                                    const QUuid& stateId)
{
  Q_ASSERT(statesModel);

  for(AbstractStateItem const* stateItem : statesModel->states())
  {
    if(stateItem->stateType() == Concurrent)
    {
      ConcurrentStateItem const* concurrent = utils::simple_cast<ConcurrentStateItem const*>(stateItem);
      Q_ASSERT(concurrent);
      for(auto region : concurrent->regions())
      {
        if(AbstractStateItem const* targetItem = constStatesRecursiveByUuid(region, stateId))
          return targetItem;
      }
    }
    else if(stateItem->stateType() == Composite)
    {
      CompositeStateItem const* composite = utils::simple_cast<CompositeStateItem const*>(stateItem);
      Q_ASSERT(composite);
      if(AbstractStateItem const* targetItem = constStatesRecursiveByUuid(composite, stateId))
        return targetItem;
    }
    else if(stateItem->uuid()==stateId)
      return stateItem;
  }

  return nullptr;
}

template<class StatesModel>
AbstractStateItem* statesRecursiveByName(StatesModel* statesModel,
                                         const QString& name, AbstractStateItem *resParent)
{
  Q_ASSERT(statesModel);

  if(name.isEmpty())
    return nullptr;

  QStringList nameList = name.split('.', QString::SkipEmptyParts);

  for(AbstractStateItem* stateItem : statesModel->states()){
    if(stateItem->name() == nameList.first()){
      if(nameList.count() == 1)
        return stateItem;

      resParent = stateItem;
      if(stateItem->stateType() == Composite)
      {
        CompositeStateItem* composite = utils::simple_cast<CompositeStateItem*>(stateItem);
        Q_ASSERT(composite);
        QStringList localNameList = nameList;
        localNameList.pop_front();
        AbstractStateItem* targetState = statesRecursiveByName(composite, localNameList.join('.'),resParent);
        if(targetState != nullptr)
          return targetState;
      }
      else if(stateItem->stateType() == Concurrent)
      {
        ConcurrentStateItem* concurrent = utils::simple_cast<ConcurrentStateItem*>(stateItem);
        Q_ASSERT(concurrent);
        QStringList localConcurrentNameList = nameList;
        localConcurrentNameList.pop_front();
        for(RegionItem* region : concurrent->regions())
        {
          if(region->name() == localConcurrentNameList.first())
          {
            QStringList localRegionNameList = localConcurrentNameList;
            localRegionNameList.pop_front();
            AbstractStateItem* targetState = statesRecursiveByName(region, localRegionNameList.join('.'),resParent);
            if(targetState != nullptr)
              return targetState;
          }
        }
      }
    }
  }

  return nullptr;
}

template<class StatesModel>
AbstractStateItem const* constStatesRecursiveByName(const StatesModel* statesModel,
                                                    const QString& name)
{
  Q_ASSERT(statesModel);

  if(name.isEmpty())
    return nullptr;

  QStringList nameList = name.split('.', QString::SkipEmptyParts);

  for(const AbstractStateItem* stateItem : statesModel->states()){
    if(stateItem->name() == nameList.first()){
      if(nameList.count() == 1)
        return stateItem;

      if(stateItem->stateType() == Composite)
      {
        CompositeStateItem const* composite = utils::simple_cast<const CompositeStateItem*>(stateItem);
        Q_ASSERT(composite);
        QStringList localNameList = nameList;
        localNameList.pop_front();
        AbstractStateItem const* targetState = constStatesRecursiveByName(composite, localNameList.join('.'));
        if(targetState != nullptr)
          return targetState;
      }
      else if(stateItem->stateType() == Concurrent)
      {
        ConcurrentStateItem const* concurrent = utils::simple_cast<const ConcurrentStateItem*>(stateItem);
        Q_ASSERT(concurrent);
        QStringList localConcurrentNameList = nameList;
        localConcurrentNameList.pop_front();
        for(const RegionItem* region : concurrent->regions())
        {
          if(region->name() == localConcurrentNameList.first())
          {
            QStringList localRegionNameList = localConcurrentNameList;
            localRegionNameList.pop_front();
            AbstractStateItem const* targetState = constStatesRecursiveByName(region, localRegionNameList.join('.'));
            if(targetState != nullptr)
              return targetState;
          }
        }
      }
    }
  }

  return nullptr;
}

template<class StatesModel>
QString statePathRecursive(StatesModel* statesModel,
                           const QUuid& stateId,
                           QStringList statePath)
{
  Q_ASSERT(statesModel);

  QString pathString = "";

  for(const AbstractStateItem* stateItem : statesModel->states()){
    if(stateItem->uuid() == stateId){
      statePath.append(stateItem->name());
      return statePath.join('.');
    }

    if(stateItem->stateType() == Concurrent){
      const ConcurrentStateItem* concurrent = utils::simple_cast<const ConcurrentStateItem*>(stateItem);
      Q_ASSERT(concurrent);
      for(const RegionItem* region : concurrent->regions())
        if(!(pathString = statePathRecursive(region, stateId, statePath + QStringList(stateItem->name()) + QStringList(region->name()))).isEmpty())
          return pathString;
    }
    else if(stateItem->stateType() == Composite){
      const CompositeStateItem* compositeStateItem = utils::simple_cast<const CompositeStateItem*>(stateItem);
      Q_ASSERT(compositeStateItem);
      if(!(pathString = statePathRecursive(compositeStateItem, stateId, statePath + QStringList(stateItem->name()))).isEmpty())
        return pathString;
    }
  }

  return QStringLiteral("");
}

template<class StatesModel>
bool statePathStates(StatesModel* statesModel,
                     const QUuid& stateId,
                     PropStates::ConstStateSet* stateSet)
{
  Q_ASSERT(statesModel);

  for(const AbstractStateItem* stateItem : statesModel->states()){
    if(stateItem->uuid() == stateId){
      stateSet->append(stateItem);
      return true;
    }

    if(stateItem->stateType() == Concurrent){
      const ConcurrentStateItem* concurrent = utils::simple_cast<const ConcurrentStateItem*>(stateItem);
      Q_ASSERT(concurrent);
      for(const RegionItem* region : concurrent->regions()){
        if(statePathStates(region, stateId, stateSet))
        {
          stateSet->prepend(concurrent);
          return true;
        }
      }
    }
    else if(stateItem->stateType() == Composite){
      const CompositeStateItem* compositeStateItem = utils::simple_cast<const CompositeStateItem*>(stateItem);
      Q_ASSERT(compositeStateItem);
      if(statePathStates(compositeStateItem, stateId, stateSet))
      {
        stateSet->prepend(compositeStateItem);
        return true;
      }
    }
  }

  return false;
}

} //namespace statemachine
} //namespace model
