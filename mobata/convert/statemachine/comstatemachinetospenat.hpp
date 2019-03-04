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

//##Library for conversion of statemachine to spenat

//TODO:
//#######Concurrent State: Possible Bugs and Missing Features########
// - Parallelization of actions by adding additional places in case of all valid entry/exit situations
// - Valid handling of concurrent states and composites states nested in concurrent regions
// - Implementation of various entry and exit situations for concurrent states is not tested/validated yet
//###################################################################

#pragma once

#include "../../model/statemachine/statemachinemodel.hpp"
#include "../../model/spenat/spenatdeclmodel.hpp"

#include <QString>
#include <QMap>
#include <QJsonDocument>

namespace model{
namespace base{
class ATriggerItem;
}
namespace statemachine{
class PropStates;
class PropTransitions;
class ConcurrentStateItem;
class JunctionStateitem;
class CompositeStateItem;
}
}

namespace convert{
namespace statemachine{

class VirtualTransition;
class ConvertTrace;

typedef QList<VirtualTransition*> VirtualTransitions;


class ComStateMachineToSpenat
{
public:

  enum HierarchyType
  {
    StateMachineRoot,
    CompositeChild,
    ConcurrentChild
  };

  ComStateMachineToSpenat(model::spenat::SpenatDeclModel* spenatDeclModel,
                          const model::statemachine::StateMachineModel* statemachineModel,
                          const QString modelFilename,
                          const QString smTracePath=QString());

  virtual ~ComStateMachineToSpenat();

  bool execute(QString* errorString);
  bool saveSpenatTrace(QString* errorString);
  bool hasTrace();
  QJsonDocument spenatJsonDocument();

private:
  Q_DISABLE_COPY(ComStateMachineToSpenat)

  bool  convertState(const model::statemachine::AbstractStateItem* state,
                     HierarchyType hierarchy,
                     ConvertTrace* convertTrace,
                     QString* errorString);

  bool  convertTransition(const model::statemachine::TransitionItem* transition,
                          ConvertTrace* convertTrace,
                          QString* errorString);

  //processing methods
  bool  processTransitionSourceState(VirtualTransitions& virtuals,
                                     const model::statemachine::AbstractStateItem* sourceState,
                                     const model::statemachine::TransitionItem* smTransition,
                                     QString* errorString);

  bool  processSourceTypeComposite(VirtualTransitions& virtuals,
                                   const model::statemachine::CompositeStateItem* composite,
                                   const model::statemachine::TransitionItem* smTransition,
                                   QString* errorString);

  //  bool  processSourceTypeConcurrent(VirtualTransitions& virtuals,
  //                                    const model::statemachine::ConcurrentStateItem* concurrent,
  //                                    const model::statemachine::TransitionItem* smTransition,
  //                                    QString* errorString);

  bool  processTransitionTargetState(VirtualTransitions& virtuals,
                                     QStringList transitionChain,
                                     const model::statemachine::AbstractStateItem* targetState,
                                     const model::statemachine::TransitionItem* smTransition,
                                     QString* errorString);

  bool  processTargetTypeComposite(VirtualTransitions& virtuals,
                                   QStringList transitionChain,
                                   const model::statemachine::CompositeStateItem* composite,
                                   const model::statemachine::TransitionItem* smTransition,
                                   QString* errorString);

  bool processTargetTypeNestedFinal(VirtualTransitions& virtuals,
                                    QStringList transitionChain,
                                    const model::statemachine::AbstractStateItem* finalState,
                                    model::statemachine::PropStates::ConstStateSet& parentStatePathSet,
                                    const model::statemachine::TransitionItem* smTransition,
                                    QString* errorString);

  //  bool  processTargetTypeConcurrent(VirtualTransitions& virtuals,
  //                                    const model::statemachine::ConcurrentStateItem* concurrent,
  //                                    const model::statemachine::TransitionItem* smTransition,
  //                                    QString* errorString);

  bool  processTargetTypeJunction(VirtualTransitions& virtuals,
                                  QStringList transitionChain,
                                  const model::statemachine::JunctionStateItem* junction,
                                  const model::statemachine::TransitionItem* smTransition,
                                  QString* errorString);

  bool  processExternalRegionTransition(VirtualTransitions& virtuals,
                                        const model::statemachine::AbstractStateItem* nestedState,
                                        const model::statemachine::ConcurrentStateItem* concurrent);

  //helper functions
  VirtualTransition* addVirtualTransition(VirtualTransitions& virtuals,
                                          const model::statemachine::AbstractStateItem* state,
                                          const QString& guard=QString(),
                                          const QString& action=QString());

  QString collectActions(const model::statemachine::AbstractStateItem* sourceState,
                         const model::statemachine::AbstractStateItem* targetState,
                         const model::statemachine::AbstractStateItem* nestedFinal,
                         const QString& transitionAction,
                         QString* errorString);

  bool checkStateType(int stateType, HierarchyType hierarchy);

  model::base::ATriggerItem* cloneTrigger(const model::base::ATriggerItem* inputTrigger,
                                          QString* errorString);

  void eliminateIdenticalParentStates(model::statemachine::PropStates::ConstStateSet* sourceStatePathSet,
                                      model::statemachine::PropStates::ConstStateSet* targetStatePathSet);
  QString collectEntryActions(const model::statemachine::PropStates::ConstStateSet& stateSet);
  QString collectExitActions(const model::statemachine::PropStates::ConstStateSet& stateSet);

  class Private;
  Private* _d;
};

} //end namespace statemachine
} //end namespace convert
