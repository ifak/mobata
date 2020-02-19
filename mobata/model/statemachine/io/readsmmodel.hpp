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

#include "../types.hpp"

class QJsonObject;
class QJsonArray;

namespace model {
namespace statemachine {

class StateMachineModel;

namespace io {

///read objects//////////
bool readStateMachineModel(const QJsonObject& jsonObject,
                           StateMachineModel* smModel,
                           QString* errorMessage);

template<class StatesModel>
bool readStatesModel(const QJsonObject& jsonObject,
                     StatesModel* statesModel,
                     const QString& stateArrayKey,
                     QString* errorMessage);

template<class TransitionsModel>
bool readTransitionsModel(const QJsonObject& jsonObject,
                          TransitionsModel* transitionsModel,
                          QString* errorMessage);

template<class JunctionTransitionsModel>
bool readJunctionTransitionsModel(const QJsonObject& jsonObject,
                                  JunctionTransitionsModel* transitionsModel,
                                  QString* errorMessage);

template<class RegionsModel>
bool readRegionsModel(const QJsonObject& jsonObject,
                      RegionsModel* regionsModel,
                      QString* errorMessage);

template<class StatesModel>
bool readChoiceState(const QJsonObject& jsonObject,
                     StatesModel* statesModel,
                     QString* errorMessage);

template<class StatesModel>
bool readCompositeState(const QJsonObject& jsonObject,
                        StatesModel* statesModel,
                        QString* errorMessage);

template<class StatesModel>
bool readConcurrentState(const QJsonObject& jsonObject,
                         StatesModel* statesModel,
                         QString* errorMessage);

template<class StatesModel>
bool readFinalState(const QJsonObject& jsonObject,
                    StatesModel* statesModel,
                    QString* errorMessage);

template<class StatesModel>
bool readInitState(const QJsonObject& jsonObject,
                   StatesModel* statesModel,
                   QString* errorMessage);

template<class StatesModel>
bool readJunctionState(const QJsonObject& jsonObject,
                       StatesModel* statesModel,
                       QString* errorMessage);

template<class StatesModel>
bool readSimpleState(const QJsonObject& jsonObject,
                     StatesModel* statesModel,
                     QString* errorMessage);

template<class StatesModel>
struct ReadStatesModel
{
  bool operator()(const QJsonObject& jsonObject,
                  StatesModel* statesModel,
                  QString* errorMessage);
};

template<class TransitionsModel>
struct ReadTransitionsModel
{
  bool operator()(const QJsonObject& jsonObject,
                  TransitionsModel* transitionsModel,
                  QString* errorMessage);
};

template<class TransitionsModel>
struct ReadJunctionTransitionsModel
{
  bool operator()(const QJsonObject& jsonObject,
                  TransitionsModel* transitionsModel,
                  QString* errorMessage);
};

template<class RegionsModel>
struct ReadRegionsModel
{
  bool operator()(const QJsonObject& jsonObject,
                  RegionsModel* regionsModel,
                  QString* errorMessage);
};

} // namespace io
} // namespace statemachine
} // namespace model

#include "../statemachine.hpp"
#include "readsmmodel.inl"
