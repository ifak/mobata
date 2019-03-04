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

#include "writesmmodel.hpp"

#include "../../base/io/writebasemodel.hpp"
#include "../../base/signalitem.hpp"
#include "../../base/portitem.hpp"
#include "../../base/atriggeritem.hpp"
#include "../../base/signaltriggeritem.hpp"
#include "../../base/timeouttriggeritem.hpp"

#include "../../../utils/functors.hpp"

#include "../statemachine.hpp"

#include <QJsonObject>
#include <QJsonArray>

using namespace model::base;

namespace model {
namespace statemachine {
namespace io {

void writeStateMachineModel(StateMachineModel const* smModel,
                            QJsonObject& jsonObject)
{
  Q_ASSERT(smModel);

  base::io::writeBaseModel(smModel, jsonObject);
  base::io::writePropPorts(smModel, jsonObject);
  writePropStates(smModel, jsonObject);
  writePropTransitions(smModel, jsonObject);

  return;
}

void writePropTransitions(PropTransitions const* propTransitions,
                          QJsonObject& jsonObject)
{
  Q_ASSERT(propTransitions);

  if(!propTransitions->transitions().count())
    return;

  QJsonArray transitionsArray;
  for(TransitionItem const* transitionItem : propTransitions->transitions())
  {
    QJsonObject transitionObject;
    writeTransitionItem(transitionItem, transitionObject);
    transitionsArray.append(transitionObject);
  }
  jsonObject["transitions"] = transitionsArray;

  return;
}

void writeTransitionItem(TransitionItem const* transitionItem,
                         QJsonObject& jsonObject)
{
  Q_ASSERT(transitionItem);
  Q_ASSERT(transitionItem->source());
  Q_ASSERT(transitionItem->target());

  const ATriggerItem* trigger = transitionItem->trigger();
  if(trigger != nullptr)
  {
    if(trigger->triggerType() == ATriggerItem::EventTrigger){
      const SignalTriggerItem* signalTrigger = static_cast<const SignalTriggerItem*>(trigger);
      Q_ASSERT(signalTrigger);
      jsonObject["signal"] = signalTrigger->triggerSignal()->uuid().toString();
      jsonObject["port"] = signalTrigger->port()->uuid().toString();
    }
    else if(trigger->triggerType() == ATriggerItem::TimeoutTrigger){
      const TimeoutTriggerItem* timeoutTrigger = static_cast<const TimeoutTriggerItem*>(trigger);
      Q_ASSERT(timeoutTrigger);
      jsonObject["value"] = QString::number(timeoutTrigger->value(), 'f', 2);
    }
  }

  base::io::writeModelItem(transitionItem, jsonObject);
  jsonObject["sourceState"] = transitionItem->source()->uuid().toString();
  jsonObject["targetState"] = transitionItem->target()->uuid().toString();
  jsonObject["guard"] = transitionItem->guard();
  jsonObject["action"] = transitionItem->action();
  jsonObject["name"] = transitionItem->name();

  return;
}

void writePropRegions(PropRegions const* propRegions,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(propRegions);

  if(!propRegions->regions().count())
    return;

  QJsonArray regionArray;
  for(RegionItem const* regionItem : propRegions->regions())
  {
    QJsonObject regionObject;
    writeRegionItem(regionItem, regionObject);
    regionArray.append(regionObject);
  }
  jsonObject["regions"] = regionArray;

  return;
}

void writeRegionItem(RegionItem const* regionItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(regionItem);

  base::io::writeModelItem(regionItem, jsonObject);
  jsonObject["name"] = regionItem->name();

  if(!regionItem->states().count())
    return;

  QJsonArray statesArray;
  writeStateArray(regionItem->states(), statesArray);
  jsonObject["regionStates"] = statesArray;

  return;
}

void writePropStates(PropStates const* propStates,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(propStates);

  if(!propStates->states().count())
    return;

  QJsonArray statesArray;
  writeStateArray(propStates->states(), statesArray);
  jsonObject["states"] = statesArray;

  return;
}

void writeStateArray(PropStates::ConstStateSet const& constStateSet,
                     QJsonArray& jsonArray)
{
  for(AbstractStateItem const* abstractStateItem : constStateSet)
  {
    QJsonObject stateObject;
    writeState(abstractStateItem, stateObject);
    jsonArray.append(stateObject);
  }

  return;
}

void writeState(AbstractStateItem const* abstractStateItem,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(abstractStateItem);

  if(abstractStateItem->stateType() == Choice)
  {
    ChoiceStateItem const* choicestateItem = utils::simple_cast<ChoiceStateItem const*>(abstractStateItem);
    writeChoiceStateItem(choicestateItem, jsonObject);
  }
  else if(abstractStateItem->stateType() == Composite)
  {
    CompositeStateItem const* compositeStateItem = utils::simple_cast<CompositeStateItem const*>(abstractStateItem);
    writeCompositeStateItem(compositeStateItem, jsonObject);
  }
  else if(abstractStateItem->stateType() == Concurrent)
  {
   ConcurrentStateItem const* concurrentStateItem = utils::simple_cast<ConcurrentStateItem const*>(abstractStateItem);
    writeConcurrentStateItem(concurrentStateItem, jsonObject);
  }
  else if(abstractStateItem->stateType() == Final)
  {
    FinalStateItem const* finalStateItem = utils::simple_cast<FinalStateItem const*>(abstractStateItem);
    writeFinalStateItem(finalStateItem, jsonObject);
  }
  else if(abstractStateItem->stateType() == Junction)
  {
    JunctionStateItem const* junctionStateItem = utils::simple_cast<JunctionStateItem const*>(abstractStateItem);
    writeJunctionStateItem(junctionStateItem, jsonObject);
  }
  else if(abstractStateItem->stateType() == Simple)
  {
    SimpleStateItem const* simpleStateItem = utils::simple_cast<SimpleStateItem const*>(abstractStateItem);
    writeSimpleStateItem(simpleStateItem, jsonObject);
  }

  return;
}

void writeAbstractStateItem(AbstractStateItem const* abstractStateItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(abstractStateItem);

  base::io::writeModelItem(abstractStateItem, jsonObject);
  jsonObject["name"] = abstractStateItem->name();

  return;
}

void writeChoiceStateItem(ChoiceStateItem const* choiceStateItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(choiceStateItem);

  writeAbstractStateItem(choiceStateItem, jsonObject);
  jsonObject["type"] = "Choice";

  return;
}

void writeCompositeStateItem(CompositeStateItem const* compositeStateItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(compositeStateItem);

  writeAbstractStateItem(compositeStateItem, jsonObject);
  jsonObject["type"] = "Composite";
  jsonObject["entryAction"] = compositeStateItem->entryAction();
  jsonObject["exitAction"] = compositeStateItem->exitAction();
  jsonObject["initState"] = compositeStateItem->isInit();

  if(!compositeStateItem->states().count())
    return;

  QJsonArray statesArray;
  for(AbstractStateItem const* abstractStateItem : compositeStateItem->states())
  {
    QJsonObject stateObject;
    writeState(abstractStateItem, stateObject);
    statesArray.append(stateObject);
  }
  jsonObject["subStates"] = statesArray;

  return;
}

void writeConcurrentStateItem(ConcurrentStateItem const* concurrentStateItem,
                              QJsonObject& jsonObject)
{
  Q_ASSERT(concurrentStateItem);

  writeAbstractStateItem(concurrentStateItem, jsonObject);
  jsonObject["type"] = "Concurrent";
  jsonObject["entryAction"] = concurrentStateItem->entryAction();
  jsonObject["exitAction"] = concurrentStateItem->exitAction();
  jsonObject["initState"] = concurrentStateItem->isInit();

  if(!concurrentStateItem->regions().count())
    return;

  writePropRegions(concurrentStateItem, jsonObject);

  return;
}

void writeFinalStateItem(FinalStateItem const* finalStateItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(finalStateItem);

  writeAbstractStateItem(finalStateItem, jsonObject);
  jsonObject["type"] = "Final";

  return;
}

void writeJunctionStateItem(JunctionStateItem const* junctionStateItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(junctionStateItem);

  writeAbstractStateItem(junctionStateItem, jsonObject);
  if(junctionStateItem->transitions().count()){
    QJsonArray transitionsArray;
    for(TransitionItem const* transitionItem : junctionStateItem->transitions())
    {
      QJsonObject transitionObject;
      writeTransitionItem(transitionItem, transitionObject);
      transitionsArray.append(transitionObject);
    }
    jsonObject["transitions"] = transitionsArray;
  }
  jsonObject["type"] = "Junction";

  return;
}

void writeSimpleStateItem(SimpleStateItem const* simpleStateItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(simpleStateItem);

  writeAbstractStateItem(simpleStateItem, jsonObject);
  jsonObject["type"] = "Simple";
  jsonObject["entryAction"] = simpleStateItem->entryAction();
  jsonObject["exitAction"] = simpleStateItem->exitAction();
  jsonObject["initState"] = simpleStateItem->isInit();

  return;
}

} // namespace io
} // namespace msc
} // namespace model
