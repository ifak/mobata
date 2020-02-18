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

#include "importrhapsody_global.hpp"
#include "importrhapsodylayout.hpp"
#include <mobata/model/statemachine/types.hpp>

namespace rhapsody {

struct TransitionElements
{
  IRPTransitionPtr transition;
  model::statemachine::AbstractStateItem* source=nullptr;
  model::statemachine::AbstractStateItem* target=nullptr;
  QString guard;
  QString signal;
  QString action;
};

typedef QList<TransitionElements> TransitionList;

class ImportRhapsodyElements
    : public ImportRhapsodyLayout
{

public:
  ImportRhapsodyElements(QMap<QString, QString> *rules);
  virtual ~ImportRhapsodyElements();

  template<class StatesModel>
  bool createSubStates(StatesModel* smModel,
                       const IRPStatechartPtr parentStatechart,
                       const IRPStatePtr& state,
                       QString* errorMessage);

  bool importEvent(model::statemachine::StateMachineModel* smModel,
                   const IRPPackagePtr& package,
                   QString* errorMessage);

  bool importDataType(model::statemachine::StateMachineModel* smModel,
                      const IRPCollectionPtr& collection,
                      QString* errorMessage);

  bool importAttribute(model::statemachine::StateMachineModel* smModel,
                       const IRPClassPtr& rhapsodyClass,
                       QString* errorMessage);

  bool importOperation(model::statemachine::StateMachineModel* smModel,
                       const IRPClassPtr& rhapsodyClass,
                       QString* errorMessage);

  bool importPort(model::statemachine::StateMachineModel* smModel,
                  const IRPClassPtr& rhapsodyClass,
                  QString* errorMessage);

  //struct
  TransitionList  _transitionList;


private:

  //bool
  bool _nextStateInitItem;

  //non-template methods


  bool createEvent(model::statemachine::StateMachineModel* smModel,
                   const IRPEventPtr& event,
                   QString* errorMessage);

  bool createDataType(model::statemachine::StateMachineModel* smModel,
                      const IRPTypePtr& dataType,
                      QString* errorMessage);

  bool createAttribute(model::statemachine::StateMachineModel* smModel,
                       const IRPAttributePtr& attribute,
                       QString* errorMessage);

  bool createOperation(model::statemachine::StateMachineModel* smModel,
                       const IRPOperationPtr& operation,
                       QString* errorMessage);

  bool createPort(model::statemachine::StateMachineModel* smModel,
                  const IRPPortPtr& port,
                  QString* errorMessage);

  bool createTransitionElement(TransitionElements& element,
                               const IRPTransitionPtr& transition,
                               QString* errorMessage);

  bool updateTransitionElement(model::statemachine::AbstractStateItem* stateItem,
                               const IRPTransitionPtr& transition,
                               const bool isTransitionSource);

  QString mobataStringFormat(QString &input);

  void replaceByRule(QString& input);

  bool ruleKeyExists(QString key);


  //template methods

  template<class StatesModel>
  bool rhapsodyItemCreation(StatesModel* smModel,
                            const IRPModelElementPtr& rhapsodyElement,
                            QString* errorMessage);

  template<class StatesModel>
  bool createStateItem(StatesModel* smModel,
                       const IRPStatePtr& rhapsodyState,
                       QString* errorMessage);

  template<class StatesModel>
  bool createSimpleStateItem(StatesModel* smModel,
                             const IRPStatePtr& state,
                             QString* errorMessage);

  template<class StatesModel>
  bool createCompositeStateItem(StatesModel* smModel,
                                const IRPStatePtr& state,
                                QString* errorMessage);

  template<class StatesModel>
  bool createConcurrentStateItem(StatesModel* smModel,
                                 const IRPStatePtr& state,
                                 QString* errorMessage);

  template<class StatesModel>
  bool createRegionItem(StatesModel* smModel,
                        const IRPStatePtr& state,
                        QString* errorMessage);

  template<class StatesModel>
  bool createDefaultInitStateItem(StatesModel* smModel,
                                  const IRPStatePtr& state,
                                  const IRPTransitionPtr& defaultTransition,
                                  QString* errorMessage);

  template<class StatesModel>
  bool createInitStateItem(StatesModel* smModel,
                           const IRPStatePtr& rootState,
                           QString* errorMessage);

  template<class StatesModel, class RhapsodyPtr>
  bool createFinalStateItem(StatesModel* smModel,
                            const RhapsodyPtr& state,
                            QString* errorMessage);

  template<class StatesModel>
  bool createConnectorItem(StatesModel* smModel,
                           const IRPConnectorPtr& state,
                           QString* errorMessage);

  template<class StatesModel>
  bool createJunctionStateItem(StatesModel* smModel,
                               const IRPConnectorPtr& connector,
                               QString* errorMessage);

  template<class StatesModel>
  bool createChoiceStateItem(StatesModel* smModel,
                             const IRPConnectorPtr& state,
                             QString* errorMessage);

  template<class ElementModelPtr>
  bool updateTransitionList(model::statemachine::AbstractStateItem* stateItem,
                            const ElementModelPtr& elementModel,
                            QString* errorMessage);

  template<class ElementModelPtr>
  bool conditionalTransitionUpdate(model::statemachine::AbstractStateItem* stateItem,
                                   const ElementModelPtr& elementModel,
                                   const bool isTransitionSource,
                                   QString* errorMessage);

  template<class AttributeElement>
  QString attributeBody(const AttributeElement& attribute,
                        QString* errorMessage);

  //variables
  QMap<QString, QString>* _rules;

};

} //rhapsody

#include "importrhapsodyelements.inl"
