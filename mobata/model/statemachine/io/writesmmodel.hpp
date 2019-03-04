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

#include "../statemachine.hpp"
#include "../propregions.hpp"

class QJsonObject;

namespace model {
namespace statemachine {

class PropEntryAction;
class PropExitAction;

namespace io {

///write objects//////////

//write state machine model
void writeStateMachineModel(StateMachineModel const* smModel,
                            QJsonObject& jsonObject);

//State differentiation
void writeState(AbstractStateItem const* abstractStateItem,
                QJsonObject& jsonObject);

//write props
void writePropStates(PropStates const* propStates,
                     QJsonObject& jsonObject);

void writePropTransitions(PropTransitions const* propTransitions,
                          QJsonObject& jsonObject);

void writePropRegions(PropRegions const* propRegions,
                    QJsonObject& jsonObject);

//write state items
void writeStateArray(PropStates::ConstStateSet const& constStateSet,
                     QJsonArray& jsonArray);

void writeAbstractStateItem(AbstractStateItem const* abstractStateItem,
                            QJsonObject& jsonObject);

void writeSimpleStateItem(SimpleStateItem const* simpleStateItem,
                          QJsonObject& jsonObject);

void writeCompositeStateItem(CompositeStateItem const* compositeStateItem,
                             QJsonObject& jsonObject);

void writeConcurrentStateItem(ConcurrentStateItem const* concurrentStateItem,
                              QJsonObject& jsonObject);

void writeFinalStateItem(FinalStateItem const* finalStateItem,
                         QJsonObject& jsonObject);

void writeJunctionStateItem(JunctionStateItem const* junctionStateItem,
                            QJsonObject& jsonObject);

void writeChoiceStateItem(ChoiceStateItem const* choiceStateItem,
                          QJsonObject& jsonObject);

void writeTransitionItem(TransitionItem const* transitionItem,
                         QJsonObject& jsonObject);

void writeRegionItem(RegionItem const* regionItem,
                     QJsonObject& jsonObject);

} // namespace io
} // namespace statemachine
} // namespace model
