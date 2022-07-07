#include "model/statemachine/concurrentstateitem.hpp"
#include "model/statemachine/compositestateitem.hpp"
#include "model/statemachine/junctionstateitem.hpp"
#include "model/statemachine/simplestateitem.hpp"
#include "model/statemachine/finalstateitem.hpp"
#include "model/statemachine/transitionitem.hpp"
#include "model/statemachine/regionitem.hpp"
#include "model/statemachine/functors.hpp"
#include "model/statemachine/types.hpp"

#include "model/base/basemodel.hpp"
#include "model/base/portitem.hpp"
#include "model/base/signalitem.hpp"
#include "model/base/datatypeitem.hpp"
#include "model/base/attributeitem.hpp"
#include "model/base/functionitem.hpp"
#include "model/base/atriggeritem.hpp"
#include "model/base/signaltriggeritem.hpp"
#include "model/base/timeouttriggeritem.hpp"

#include "model/spenat/spenatbasemodel.hpp"
#include "model/spenat/placeitem.hpp"
#include "model/spenat/transitionitem.hpp"

#include "comstatemachinetospenat.hpp"
#include "virtualtransition.hpp"
#include "converttrace.h"

#include <QDebug>
#include <QFile>

using namespace convert::statemachine;
using namespace model::statemachine;
using namespace model::base;
using namespace model::spenat;

class ComStateMachineToSpenat::Private
{
  friend class ComStateMachineToSpenat;

  SpenatDeclModel*          _spenatDeclModel;
  const StateMachineModel*  _stateMachineModel;
  const QString             _modelFilename;
  QString             _smTracePath;
  bool                      _traceFileExists;
  QJsonDocument             _spenatJsonDocument;

  Private(SpenatDeclModel* spenatDeclModel,
          const StateMachineModel* statemachineModel,
          const QString modelFilename,
          const QString smTracePath)
    : _spenatDeclModel(spenatDeclModel),
      _stateMachineModel(statemachineModel),
      _modelFilename(modelFilename),
      _smTracePath(smTracePath),
      _traceFileExists(false)
  {}
};

ComStateMachineToSpenat::ComStateMachineToSpenat(model::spenat::SpenatDeclModel* spenatDeclModel,
                                                 const model::statemachine::StateMachineModel* statemachineModel,
                                                 const QString modelFilename,
                                                 const QString smTracePath)
  : _d(new Private(spenatDeclModel, statemachineModel, modelFilename, smTracePath))
{
  this->_d->_smTracePath.replace("\\","/");
  if(!this->_d->_smTracePath.isEmpty())
  {
    if(this->_d->_smTracePath.right(1) != QStringLiteral("/"))
      this->_d->_smTracePath.append("/");
  }
}

ComStateMachineToSpenat::~ComStateMachineToSpenat()
{
  delete this->_d;
}

bool ComStateMachineToSpenat::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_spenatDeclModel);
  Q_ASSERT(this->_d->_stateMachineModel);

  this->_d->_spenatDeclModel->reset();

  this->_d->_spenatDeclModel->setName(this->_d->_stateMachineModel->name());

  //cloning base model
  this->_d->_stateMachineModel->clonePorts(this->_d->_spenatDeclModel);
  this->_d->_stateMachineModel->cloneSignals(this->_d->_spenatDeclModel);
  this->_d->_stateMachineModel->cloneAttributes(this->_d->_spenatDeclModel);
  this->_d->_stateMachineModel->cloneDataTypes(this->_d->_spenatDeclModel);
  this->_d->_stateMachineModel->cloneFunctions(this->_d->_spenatDeclModel);

  ConvertTrace* convertTrace = new ConvertTrace(this->_d->_modelFilename, this->_d->_smTracePath);
  if(!this->_d->_modelFilename.isEmpty())
    if(convertTrace->loadStatemachineTraceFromFile(errorString))
      this->_d->_traceFileExists = true;

  for(const AbstractStateItem* state : this->_d->_stateMachineModel->states())
    if(!this->convertState(state, StateMachineRoot, convertTrace, errorString))
      return false;

  for(const model::statemachine::TransitionItem* transition : this->_d->_stateMachineModel->transitions())
    if(!this->convertTransition(transition, convertTrace, errorString))
      return false;

  if(this->_d->_traceFileExists)
  {
    this->_d->_spenatJsonDocument = convertTrace->createJsonDocument(errorString);
    if(this->_d->_spenatJsonDocument.isEmpty())
      return false;
  }

  return true;
}

bool ComStateMachineToSpenat::saveSpenatTrace(QString* errorString)
{
  QString filepath = this->_d->_smTracePath;
  filepath.append(this->_d->_modelFilename);
  filepath.append(".spenattrace");
  QFile outputFile(filepath);
  if (!outputFile.open(QIODevice::WriteOnly
                       | QIODevice::Text))
  {
    utils::AddPtrString(errorString) << "spenat model trace could not be saved to " << filepath;
    return false;
  }

  QTextStream outputStream(&outputFile);
  outputStream << this->_d->_spenatJsonDocument.toJson(QJsonDocument::Indented);

  return true;
}

QJsonDocument ComStateMachineToSpenat::spenatJsonDocument()
{
  return this->_d->_spenatJsonDocument;
}

bool ComStateMachineToSpenat::convertState(const AbstractStateItem* state,
                                           HierarchyType hierarchy,
                                           ConvertTrace* convertTrace,
                                           QString* errorString)
{
  Q_ASSERT(state);

  PlaceItem* placeItem = nullptr;

  switch(state->stateType())
  {
  case Composite:
  {
    const CompositeStateItem* compositeState = static_cast<const CompositeStateItem*>(state);
    Q_ASSERT(compositeState);
    if(hierarchy == ConcurrentChild)
    {
      utils::AddPtrString(errorString) << "CompositeStates nested in ConcurrentState Regions are currently not supported. Aborting model conversion!";
      return false;
    }
    else
    {
      for(const AbstractStateItem* nestedState : compositeState->states())
        if(!this->convertState(nestedState, CompositeChild, convertTrace, errorString))
          return false;
      break;
    }
  }
  case Concurrent:
  {
    //#######Unfinished Code for Concurrent Conversion!########
    //    ConcurrentStateItem* concurrentState = static_cast<ConcurrentStateItem*>(state);
    //    Q_ASSERT(concurrentState);
    //    if(hierarchy == ConcurrentChild)
    //    {
    //      utils::AddPtrString(errorString) << "ConcurrentStates nested in ConcurrentState Regions are currently not supported. Aborting model conversion!";
    //      return false;
    //    }
    //    else
    //    {
    //      for(RegionItem* region : concurrentState->regions())
    //        for(AbstractStateItem* nestedState : region->states())
    //          if(!this->convertState(nestedState, ConcurrentChild, errorString))
    //            return false;
    //    }
    //    break;
    //##########################################################
    utils::AddPtrString(errorString) << "ConcurrentState is currently not supported. Aborting model conversion!";
    return false;
  }
  case Simple:
  {
    placeItem = this->_d->_spenatDeclModel->addPlace(state->name(), errorString);
    if(!placeItem)
      return false;

    const SimpleStateItem* simpleState = static_cast<const SimpleStateItem*>(state);
    Q_ASSERT(simpleState);
    if(simpleState->isInit() && hierarchy == StateMachineRoot)
    {
      bool result=this->_d->_spenatDeclModel->addInitPlace(placeItem, errorString);
      if(!result)
        return false;
    }
    break;
  }
  case Junction:
    break;
  case Final:
  {
    if(hierarchy == CompositeChild || //TODO: do we need this?
       hierarchy == ConcurrentChild)
      break;
    else
    {
      placeItem = this->_d->_spenatDeclModel->addPlace(state->name(), errorString);
      if(!placeItem)
        return false;
    }
    break;
  }
  case Choice:
  {
    placeItem = this->_d->_spenatDeclModel->addPlace(state->name(), errorString);
    if(!placeItem)
      return false;
    break;
  }
  }

  if(this->_d->_traceFileExists)
    if(placeItem != nullptr){
      if(!convertTrace->appendPlaceTrace(placeItem->name(), errorString)){
        return false;
      }
    }
  return true;
}

bool ComStateMachineToSpenat::convertTransition(const model::statemachine::TransitionItem* smTransition,
                                                ConvertTrace* convertTrace,
                                                QString* errorString)
{
  Q_ASSERT(smTransition);

  //detect if current transition will be fused with another transition during model conversion
  //exit conversion of this transition if conditions are fullfilled
  if(smTransition->source()->stateType() == Composite &&
     smTransition->target()->stateType() == Final &&
     smTransition->trigger() == nullptr &&
     smTransition->guard().isEmpty())
    return true;

  QStringList transitionChain;
  transitionChain.append(smTransition->name());

  VirtualTransitions preVirtuals;
  if(!this->processTransitionSourceState(preVirtuals,
                                         smTransition->source(),
                                         smTransition,
                                         errorString))
    return false;

  VirtualTransitions postVirtuals;
  if(!this->processTransitionTargetState(postVirtuals,
                                         transitionChain,
                                         smTransition->target(),
                                         smTransition,
                                         errorString))
    return false;

  for(VirtualTransition* preTransition : preVirtuals)
  {
    for(VirtualTransition* postTransition: postVirtuals)
    {
      const AbstractStateItem* nestedFinal = nullptr;
      if(postTransition->fusedTransition() && smTransition->target()->stateType() == Final)
        nestedFinal = smTransition->target();

      //transition name
      QString transitionName;
      if(preVirtuals.size() == 1 &&
         postVirtuals.size() == 1 &&
         nestedFinal == nullptr)
        transitionName = smTransition->name();
      else
      {
        transitionName = preTransition->state()->name() +
                         QStringLiteral("_To_") +
                         postTransition->state()->name();
        int counter = 2;
        QString interatedName = transitionName;
        while(this->_d->_spenatDeclModel->transition(interatedName))
        {
          interatedName = transitionName + QString::number(counter);
          counter++;
        }
        transitionName = interatedName;
      }

      //combine actions
      QString combinedAction = preTransition->action();
      if(!combinedAction.isEmpty() && !postTransition->action().isEmpty())
        combinedAction.append(QStringLiteral("\n"));
      combinedAction.append(postTransition->action());
      if(combinedAction.isEmpty())
        combinedAction = smTransition->action();

      QString fullAction = collectActions(preTransition->state(),
                                          postTransition->state(),
                                          nestedFinal,
                                          combinedAction,
                                          errorString);

      //combine guards
      QString combinedGuard = preTransition->guard();
      if(!combinedGuard.isEmpty() && !postTransition->guard().isEmpty())
        combinedGuard.append(QStringLiteral(" and "));
      combinedGuard.append(postTransition->guard());
      if(combinedGuard.isEmpty())
        combinedGuard = smTransition->guard();

      const ATriggerItem* smTrigger = smTransition->trigger();
      ATriggerItem* spenatTrigger = nullptr;
      if(smTrigger)
      {
        spenatTrigger = this->cloneTrigger(smTrigger, errorString);
        if(!spenatTrigger)
          return false;
      }

      model::spenat::TransitionItem* spenatTransition = new model::spenat::TransitionItem(transitionName,
                                                                                          spenatTrigger,
                                                                                          combinedGuard,
                                                                                          fullAction);
      if(!this->_d->_spenatDeclModel->addTransition(spenatTransition, errorString))
      {
        delete spenatTransition;
        return false;
      }

      if(this->_d->_traceFileExists)
        if(!convertTrace->appendTransitionTrace(transitionName, postTransition->transitionChain()))
          return false;

      PlaceItem* prePlace = this->_d->_spenatDeclModel->place(preTransition->state()->name());
      if(!prePlace)
      {
        utils::AddPtrString(errorString) << "Place equivalent of state '" + preTransition->state()->name() + "' was not found in spenat model!";
        return false;
      }
      if(!spenatTransition->addPrePlaceArc(prePlace))
        return false;

      PlaceItem* postPlace = this->_d->_spenatDeclModel->place(postTransition->state()->name());
      if(!postPlace)
      {
        utils::AddPtrString(errorString) << "Place equivalent of state '" + postTransition->state()->name() + "' was not found in spenat model!";
        return false;
      }
      if(!spenatTransition->addPostPlaceArc(postPlace))
        return false;
    }
  }

  return true;
}

bool ComStateMachineToSpenat::processTransitionSourceState(VirtualTransitions& virtuals,
                                                           const AbstractStateItem* sourceState,
                                                           const model::statemachine::TransitionItem* smTransition,
                                                           QString* errorString)
{
  Q_ASSERT(sourceState);
  Q_ASSERT(smTransition);

  PropStates::ConstStateSet sourceStatePathSet;
  if(!statePathStates(this->_d->_stateMachineModel,
                      sourceState->uuid(),
                      &sourceStatePathSet))
  {
    utils::AddPtrString(errorString) << "SourceState was not found in statemachine model!";
    return false;
  }
  //#######Unfinished Code for Concurrent Conversion!########
  //  for(const AbstractStateItem* state : sourceStatePathSet)
  //  {
  //    if(state->stateType() == Concurrent)
  //    {
  //      const ConcurrentStateItem* concurrent = static_cast<const ConcurrentStateItem*>(state);
  //      if(processExternalRegionTransition(virtuals, sourceState, concurrent))
  //        return true;
  //      else
  //        return false;
  //    }
  //  }
  //##########################################################

  //add PrePlaceArcs
  switch(sourceState->stateType())
  {
  case Composite:
  {
    const CompositeStateItem* composite = static_cast<const CompositeStateItem*>(sourceState);
    Q_ASSERT(composite);
    if(!this->processSourceTypeComposite(virtuals,
                                         composite,
                                         smTransition,
                                         errorString))
      return false;
    break;
  }
    //#######Unfinished Code for Concurrent Conversion!########
    //  case Concurrent:
    //  {
    //    const ConcurrentStateItem* concurrent = static_cast<const ConcurrentStateItem*>(sourceState);
    //    Q_ASSERT(concurrent);
    //    if(!this->processSourceTypeConcurrent(virtuals,
    //                                          concurrent,
    //                                          smTransition,
    //                                          errorString))
    //      return false;
    //    break;
    //  }
    //##########################################################
  case Simple:
  case Choice:
    if(!this->addVirtualTransition(virtuals,
                                   sourceState))
      return false;
    break;
  default:
    break;
  }

  return true;
}

bool ComStateMachineToSpenat::processSourceTypeComposite(VirtualTransitions& virtuals,
                                                         const CompositeStateItem* composite,
                                                         const model::statemachine::TransitionItem* smTransition,
                                                         QString* errorString)
{
  Q_ASSERT(smTransition);
  Q_ASSERT(composite);

  //if transition with composite source has no trigger and guard, check if composite has final states and add them as prePlaces
  if(smTransition->trigger() == nullptr && smTransition->guard().isEmpty())
  {
    if(composite->finalStates().isEmpty())
    {
      utils::AddPtrString(errorString) << "CompositeState '" + composite->name() + "' is defined as source of a statemachine transition, but it has no FinalState!";
      return false;
    }
  }
  else if(smTransition->trigger() != nullptr)
{
    //if transition with composite source has a trigger, create transition proposals for each nested region/substatemachine and add nested states as preplaces
    const PropStates* propStates = dynamic_cast<const PropStates*>(composite);
    Q_ASSERT(propStates);
    for(const AbstractStateItem* nestedState : propStates->states())
      if(!processTransitionSourceState(virtuals,
                                       nestedState,
                                       smTransition,
                                       errorString))
        return false;
  }
  else{
    utils::AddPtrString(errorString) << "Unexpected model structure: Statemachine transition with sourceState 'composite' can not be converted!";
    return false;
  }
  return true;
}

//#######Unfinished Code for Concurrent Conversion!########
//bool ComStateMachineToSpenat::processSourceTypeConcurrent(VirtualTransitions& virtuals,
//                                                          const ConcurrentStateItem* concurrent,
//                                                          const model::statemachine::TransitionItem* smTransition,
//                                                          QString* errorString)
//{
//  Q_ASSERT(smTransition);
//  Q_ASSERT(concurrent);

//  if(smTransition->trigger() == nullptr && smTransition->guard().isEmpty())
//  {
//    VirtualTransition* virtualTransition = new VirtualTransition();
//    for(const RegionItem* region : concurrent->regions())
//    {
//      if(region->finalStates().isEmpty())
//      {
//        utils::AddPtrString(errorString) << "ConcurrentState '" + region->name() + "' is defined as source of a statemachine transition, but it has no FinalState!";
//        delete virtualTransition;
//        return false;
//      }
//      for(const FinalStateItem* nestedFinal : region->finalStates())
//      {
//        if(!virtualTransition->appendState(nestedFinal))
//        {
//          delete virtualTransition;
//          return false;
//        }
//      }
//    }
//    virtuals.append(virtualTransition);
//  }
//  else if(smTransition->trigger() != nullptr)
//  {
//    int it = 0;
//    const PropRegions::ConstRegionSet regions = concurrent->regions();
//    for(PropRegions::ConstRegionSet::const_iterator currentRegion = regions.begin(); currentRegion != regions.end() -1; currentRegion++)
//    {
//      it++;
//      for(PropRegions::ConstRegionSet::const_iterator otherRegion = regions.begin() + it; otherRegion != regions.end(); otherRegion++)
//      {
//        for(const AbstractStateItem* currentRegionState : (*currentRegion)->states())
//        {
//          for(const AbstractStateItem* otherRegionState : (*otherRegion)->states())
//          {
//            if(checkStateType(currentRegionState->stateType(), hierarchy) &&
//               checkStateType(otherRegionState->stateType(), hierarchy))
//            {
//              VirtualTransition* virtualTransition = this->addVirtualTransition(virtuals,
//                                                                                currentRegionState);
//              virtualTransition->appendState(otherRegionState);
//            }
//          }
//        }
//      }
//    }
//  }
//  else
//  {
//    utils::AddPtrString(errorString) << "Unexpected model structure: Statemachine transition with sourceState 'composite' can not be converted!";
//    return false;
//  }

//  return true;
//}
//##########################################################

bool ComStateMachineToSpenat::processTransitionTargetState(VirtualTransitions& virtuals,
                                                           QStringList transitionChain,
                                                           const AbstractStateItem* targetState,
                                                           model::statemachine::TransitionItem const* smTransition,
                                                           QString* errorString)
{
  Q_ASSERT(smTransition);
  Q_ASSERT(targetState);

  //addPostPlaceArcs
  switch(targetState->stateType())
  {
  case Composite:
  {
    const CompositeStateItem* composite = static_cast<const CompositeStateItem*>(targetState);
    Q_ASSERT(composite);
    if(!processTargetTypeComposite(virtuals,
                                   transitionChain,
                                   composite,
                                   smTransition,
                                   errorString))
      return false;
    break;
  }
    //#######Unfinished Code for Concurrent Conversion!########
    //  case Concurrent:
    //  {
    //    const ConcurrentStateItem* concurrent = static_cast<const ConcurrentStateItem*>(targetState);
    //    Q_ASSERT(concurrent);
    //    if(!processTargetTypeConcurrent(virtuals,
    //                                    concurrent,
    //                                    smTransition,
    //                                    errorString))
    //      return false;
    //    break;
    //  }
    //##########################################################
  case Junction:
  {
    const JunctionStateItem* junction = static_cast<const JunctionStateItem*>(targetState);
    Q_ASSERT(junction);
    if(!processTargetTypeJunction(virtuals,
                                  transitionChain,
                                  junction,
                                  smTransition,
                                  errorString))
      return false;
    break;
  }
  case Final: {
    PropStates::ConstStateSet targetStatePath;
    if(!statePathStates(this->_d->_stateMachineModel,
                        targetState->uuid(),
                        &targetStatePath))
      return false;
    if(targetStatePath.size() > 1)
    {
      targetStatePath.pop_back();
      if(!this->processTargetTypeNestedFinal(virtuals,
                                             transitionChain,
                                             targetState,
                                             targetStatePath,
                                             smTransition,
                                             errorString))
        return false;
    }
    break;
  }
  case Choice:
    break;
  case Simple: {
    VirtualTransition* virtualTrans = this->addVirtualTransition(virtuals,
                                                                 targetState,
                                                                 smTransition->guard(),
                                                                 smTransition->action());
    if(!virtualTrans)
      return false;
    virtualTrans->setTransitionChain(transitionChain);

    QVariant fusedTransData = smTransition->data();
    if(fusedTransData.isValid() && fusedTransData.toBool())
      virtualTrans->setFusedTransition(true);
    break;
  }
  default:
    break;
  }

  return true;
}

bool ComStateMachineToSpenat::processTargetTypeComposite(VirtualTransitions& virtuals,
                                                         QStringList transitionChain,
                                                         const CompositeStateItem* composite,
                                                         const model::statemachine::TransitionItem* smTransition,
                                                         QString* errorString)
{
  Q_ASSERT(composite);
  Q_ASSERT(smTransition);

  if(composite->initState())
  {
    if(composite->initState()->stateType() == Composite)
    {
      if(!processTransitionTargetState(virtuals,
                                       transitionChain,
                                       composite->initState(),
                                       smTransition,
                                       errorString))
        return false;
    }
    else
    {
      VirtualTransition* virtualTrans = this->addVirtualTransition(virtuals,
                                                                   composite->initState(),
                                                                   smTransition->guard(),
                                                                   smTransition->action());
      if(!virtualTrans)
        return false;
      virtualTrans->setTransitionChain(transitionChain);
    }
  }
  else
  {
    utils::AddPtrString(errorString) << "CompositeState '" + composite->name() + "' is defined as a target of a statemachine transition, but it has no state marked as an initial state!";
    return false;
  }
  return true;
}

bool ComStateMachineToSpenat::processTargetTypeNestedFinal(VirtualTransitions& virtuals,
                                                           QStringList transitionChain,
                                                           const AbstractStateItem* finalState,
                                                           PropStates::ConstStateSet& parentStatePathSet,
                                                           const model::statemachine::TransitionItem* smTransition,
                                                           QString* errorString)
{
  Q_ASSERT(finalState);
  Q_ASSERT(smTransition);

  const AbstractStateItem* parentState = parentStatePathSet.last();

  int stateType = parentState->stateType();
  if(stateType != Composite)
  {
    utils::AddPtrString(errorString) << "An error occured while converting a final state!";
    return false;
  }

  for(const model::statemachine::TransitionItem* localTrans : this->_d->_stateMachineModel->transitions())
  {
    if(localTrans->source() == parentState &&
       localTrans->guard().isEmpty() &&
       localTrans->trigger() == nullptr)
    {
      transitionChain.append(localTrans->name());
      ATriggerItem* newTempTrigger = this->cloneTrigger(smTransition->trigger(), errorString);
      if(!newTempTrigger)
        return false;

      PropStates::ConstStateSet targetStatePath;
      if(!statePathStates(this->_d->_stateMachineModel,
                          localTrans->target()->uuid(),
                          &targetStatePath))
        return false;

      this->eliminateIdenticalParentStates(&parentStatePathSet,
                                           &targetStatePath);
      QString exitActions = this->collectExitActions(parentStatePathSet);

      QString combinedAction = smTransition->action();
      if(!combinedAction.isEmpty() && !exitActions.isEmpty())
        combinedAction.append(QStringLiteral("\n"));
      combinedAction.append(exitActions);
      if(!combinedAction.isEmpty() && !localTrans->action().isEmpty())
        combinedAction.append(QStringLiteral("\n"));
      combinedAction.append(localTrans->action());

      QString combinedName = smTransition->name();
      if(!combinedName.isEmpty() && !localTrans->name().isEmpty())
        combinedName.append(QStringLiteral("_"));
      combinedName.append(localTrans->name());

      model::statemachine::TransitionItem* newTempTrans = new model::statemachine::TransitionItem(newTempTrigger,
                                                                                                  smTransition->source(),
                                                                                                  localTrans->target(),
                                                                                                  smTransition->guard(),
                                                                                                  combinedAction);
      newTempTrans->setName(combinedName);
      newTempTrans->setData(true);
      bool result = processTransitionTargetState(virtuals,
                                                 transitionChain,
                                                 localTrans->target(),
                                                 newTempTrans,
                                                 errorString);
      delete newTempTrans;
      if(!result)
        return false;
    }
  }

  return true;
}

//#######Unfinished Code for Concurrent Conversion!########
//bool ComStateMachineToSpenat::processTargetTypeConcurrent(VirtualTransitions& virtuals,
//                                                          const ConcurrentStateItem* concurrent,
//                                                          const model::statemachine::TransitionItem* smTransition,
//                                                          QString* errorString)
//{
//  Q_ASSERT(concurrent);
//  Q_ASSERT(smTransition);

//  if(hierarchy == ConcurrentChild)
//  {
//    //already inside a concurrent state, adding new concurrent state as a single place
//    if(this->addVirtualTransition(virtuals,
//                                  concurrent,
//                                  smTransition->name(),
//                                  smTransition->guard(),
//                                  smTransition->action()))
//      return false;
//  }
//  else
//  {
//    //first time inside a concurrent, check for every region if initState is a composite or concurrent and add virtual transitions including their entry actions
//    PropStates::ConstStateSet stateSet;
//    for(const RegionItem* regionItem : concurrent->regions())
//    {
//      if(regionItem->initState())
//      {
//        if(regionItem->initState()->stateType() == Composite || regionItem->initState()->stateType() == Concurrent)
//        {
//          const PropStates* propStates  = dynamic_cast<const PropStates*>(regionItem->initState());
//          for(const AbstractStateItem* nestedState : propStates->states())
//            if(!processTransitionTargetState(virtuals,
//                                             nestedState,
//                                             smTransition,
//                                             hierarchy,
//                                             errorString))
//              return false;
//        }
//        else
//          stateSet.append(regionItem->initState());
//      }
//      else{
//        utils::AddPtrString(errorString) << "ConcurrentState '" + concurrent->name() + "' is defined as a target of a statemachine transition, but at least one of its regions as no state marked as an initial state!";
//        return false;
//      }
//    }
//    if(!stateSet.isEmpty()){
//      VirtualTransition* virtualTransition = new VirtualTransition();
//      virtualTransition->setStates(stateSet);
//      virtualTransition->setName(smTransition->name());
//      virtualTransition->setAction(smTransition->action());
//      virtualTransition->setGuard(smTransition->guard());
//      virtuals.append(virtualTransition);
//    }
//  }

//  return true;
//}
//##########################################################

bool ComStateMachineToSpenat::processTargetTypeJunction(VirtualTransitions& virtuals,
                                                        QStringList transitionChain,
                                                        const JunctionStateItem* junction,
                                                        const model::statemachine::TransitionItem* smTransition,
                                                        QString* errorString)
{
  Q_ASSERT(junction);
  Q_ASSERT(smTransition);

  for(const model::statemachine::TransitionItem* junctionTransition : junction->transitions())
  {
    transitionChain.append(junctionTransition->name());
    QString name = smTransition->name() + QStringLiteral("_") + junctionTransition->name();
    QString action = smTransition->action() + QStringLiteral("\n") + junctionTransition->action();
    QString guard = smTransition->guard();
    PropTransitions::ConstTransitionSet transitions = junction->transitions();
    if(junction->transitions().size() > 1 && junctionTransition->guard() == QStringLiteral("else"))
      for(const model::statemachine::TransitionItem* jt : junction->transitions())
      {
        if(jt->guard() != QStringLiteral("else"))
          guard.append(QStringLiteral(" and not ") + jt->guard());
      }
    else
      guard.append(QStringLiteral(" and ") + junctionTransition->guard());
    ATriggerItem* trigger = cloneTrigger(smTransition->trigger(), errorString);
    Q_ASSERT(trigger);
    model::statemachine::TransitionItem* temporaryTransition = new model::statemachine::TransitionItem(trigger,
                                                                                                       junctionTransition->source(),
                                                                                                       junctionTransition->target(),
                                                                                                       guard,
                                                                                                       action);
    temporaryTransition->setName(name);
    bool result = this->processTransitionTargetState(virtuals,
                                                     transitionChain,
                                                     temporaryTransition->target(),
                                                     temporaryTransition,
                                                     errorString);
    delete temporaryTransition;

    if(!result)
      return false;
  }

  return true;
}

QString ComStateMachineToSpenat::collectActions(const AbstractStateItem* sourceState,
                                                const AbstractStateItem* targetState,
                                                const AbstractStateItem* nestedFinal,
                                                const QString& transitionAction,
                                                QString* errorString)
{
  PropStates::ConstStateSet sourceStatePathSet;
  if(!statePathStates(this->_d->_stateMachineModel,
                      sourceState->uuid(),
                      &sourceStatePathSet))
  {
    utils::AddPtrString(errorString) << "SourceState was not found in statemachine model!";
    return QStringLiteral("");
  }

  PropStates::ConstStateSet targetStatePathSet;
  if(!statePathStates(this->_d->_stateMachineModel,
                      targetState->uuid(),
                      &targetStatePathSet))
  {
    utils::AddPtrString(errorString) << "TargetState was not found in statemachine model!";
    return QStringLiteral("");
  }

  Q_ASSERT(!sourceStatePathSet.isEmpty());
  Q_ASSERT(!targetStatePathSet.isEmpty());

  this->eliminateIdenticalParentStates(&sourceStatePathSet,
                                       &targetStatePathSet);
  //Create Action String
  QString action;

  //append exitActions
  if(nestedFinal)
  {
    PropStates::ConstStateSet finalStatePathSet;
    if(!statePathStates(this->_d->_stateMachineModel,
                        nestedFinal->uuid(),
                        &finalStatePathSet))
    {
      utils::AddPtrString(errorString) << "FinalState was not found in statemachine model!";
      return QStringLiteral("");
    }
    this->eliminateIdenticalParentStates(&sourceStatePathSet,
                                         &finalStatePathSet);
  }

  action.append(this->collectExitActions(sourceStatePathSet));

  //append transition action
  if(!action.isEmpty() && !transitionAction.isEmpty())
    action.append(QStringLiteral("\n"));
  action.append(transitionAction);

  //append entryActions
  QString entryActions = this->collectEntryActions(targetStatePathSet);
  if(!action.isEmpty() && !entryActions.isEmpty())
    action.append(QStringLiteral("\n"));
  action.append(entryActions);

  return action;
}

QString ComStateMachineToSpenat::collectExitActions(const PropStates::ConstStateSet& stateSet)
{
  QString action;
  for(PropStates::ConstStateSet::const_reverse_iterator it = stateSet.crbegin(); it != stateSet.crend(); it++)
  {
    switch((*it)->stateType())
    {
    case Simple:
    {
      const SimpleStateItem* simple = static_cast<const SimpleStateItem*>((*it));
      Q_ASSERT(simple);
      if(!action.isEmpty() && !simple->exitAction().isEmpty())
        action.append(QStringLiteral("\n"));
      action.append(simple->exitAction());
      break;
    }
    case Composite:
    {
      const CompositeStateItem* composite = static_cast<const CompositeStateItem*>((*it));
      Q_ASSERT(composite);
      if(!action.isEmpty() && !composite->exitAction().isEmpty())
        action.append(QStringLiteral("\n"));
      action.append(composite->exitAction());
      break;
    }
      //#######Unfinished Code for Concurrent Conversion!########
      //    case Concurrent:
      //    {
      //      const ConcurrentStateItem* concurrent = static_cast<const ConcurrentStateItem*>((*it));
      //      Q_ASSERT(concurrent);
      //      if(!action.isEmpty())
      //        action.append(QStringLiteral("\n"));
      //      action.append(concurrent->exitAction() + QStringLiteral("\n"));
      //      break;
      //    }
      //##########################################################
    default:
      break;
    }
  }

  return action;
}

QString ComStateMachineToSpenat::collectEntryActions(const PropStates::ConstStateSet& stateSet)
{
  QString action;
  for(PropStates::ConstStateSet::const_iterator it = stateSet.cbegin(); it != stateSet.cend(); it++)
  {
    switch((*it)->stateType())
    {
    case Simple:
    {
      const SimpleStateItem* simple = static_cast<const SimpleStateItem*>((*it));
      Q_ASSERT(simple);
      if(!action.isEmpty() && !simple->entryAction().isEmpty())
        action.append(QStringLiteral("\n"));
      action.append(simple->entryAction());
      break;
    }
    case Composite:
    {
      const CompositeStateItem* composite = static_cast<const CompositeStateItem*>((*it));
      Q_ASSERT(composite);
      if(!action.isEmpty() && !composite->entryAction().isEmpty())
        action.append(QStringLiteral("\n"));
      action.append(composite->entryAction());
      break;
    }
      //#######Unfinished Code for Concurrent Conversion!########
      //    case Concurrent:
      //    {
      //      const ConcurrentStateItem* concurrent = static_cast<const ConcurrentStateItem*>((*it));
      //      Q_ASSERT(concurrent);
      //      if(!action.isEmpty())
      //        action.append(QStringLiteral("\n"));
      //      action.append(concurrent->entryAction() + QStringLiteral("\n"));
      //      break;
      //    }
      //##########################################################
    default:
      break;
    }
  }

  return action;
}

void ComStateMachineToSpenat::eliminateIdenticalParentStates(PropStates::ConstStateSet* sourceStatePathSet,
                                                             PropStates::ConstStateSet* targetStatePathSet)
{
  //eliminate all identical parent states of both source and target state
  //reason: a transition between to deeply nested states may not leave beyond a certain parent,
  //        so these identical parents have to be removed when collection entry/exit actions
  //###########################
  //example:
  //transition from
  //composite.subComposite.subSubComposite1.simpleState
  //to
  //composite.subComposite.subSubComposite2.simpleState
  //does not leave beyond state subComposite

  int minSize = sourceStatePathSet->size();
  if(minSize > targetStatePathSet->size())
    minSize = targetStatePathSet->size();

  int identicalStates = 0;

  for(int i = 0; i < minSize; i++)
  {
    if(sourceStatePathSet->at(i)->uuid() == targetStatePathSet->at(i)->uuid())
    {
      identicalStates++;
    }
  }

  for(int i = 0; i < identicalStates; i++)
  {
    sourceStatePathSet->pop_front();
    targetStatePathSet->pop_front();
  }
}

ATriggerItem* ComStateMachineToSpenat::cloneTrigger(const ATriggerItem* inputTrigger,
                                                    QString* errorString)
{
  Q_ASSERT(inputTrigger);

  if(inputTrigger->triggerType() == ATriggerItem::EventTrigger)
  {
    const model::base::SignalTriggerItem* smSignalTrigger = static_cast<const model::base::SignalTriggerItem*>(inputTrigger);
    Q_ASSERT(smSignalTrigger);
    model::base::SignalItem* signal = this->_d->_spenatDeclModel->signal(smSignalTrigger->triggerSignal()->name());
    if(!signal)
    {
      utils::AddPtrString(errorString) << "Signal of statemachine SignalTriggerItem is not defined in spenat model!";
      return nullptr;
    }
    model::base::PortItem* port = this->_d->_spenatDeclModel->port(smSignalTrigger->port()->name());
    if(!port)
    {
      utils::AddPtrString(errorString) << "Port of statemachine SignalTriggerItem is not defined in spenat model!";
      return nullptr;
    }
    model::base::SignalTriggerItem* spSignalTrigger = new model::base::SignalTriggerItem(signal, port);
    return spSignalTrigger;
  }
  else if(inputTrigger->triggerType() == ATriggerItem::TimeoutTrigger)
  {
    const model::base::TimeoutTriggerItem* smTimeoutTrigger = static_cast<const model::base::TimeoutTriggerItem*>(inputTrigger);
    Q_ASSERT(smTimeoutTrigger);
    model::base::TimeoutTriggerItem* spTimeoutTrigger = new model::base::TimeoutTriggerItem(smTimeoutTrigger->value());
    return spTimeoutTrigger;
  }

  utils::AddPtrString(errorString) << "Trigger of statemachine transition has undefined type! Aborting!";
  return nullptr;
}

VirtualTransition* ComStateMachineToSpenat::addVirtualTransition(VirtualTransitions& virtuals,
                                                                 const AbstractStateItem* state,
                                                                 const QString& guard,
                                                                 const QString& action)
{
  Q_ASSERT(state);

  VirtualTransition* virtualTransition = new VirtualTransition(state,
                                                               guard,
                                                               action);
  virtuals.append(virtualTransition);
  return virtualTransition;
}

bool ComStateMachineToSpenat::checkStateType(int stateType, HierarchyType hierarchy)
{
  if(stateType == Composite ||
     //stateType == Concurrent ||
     stateType == Simple ||
     stateType == Choice ||
     stateType == Final)
    return true;
  else if (stateType == Final &&
           hierarchy == StateMachineRoot)
    return true;

  return false;
}

bool ComStateMachineToSpenat::hasTrace()
{
  return this->_d->_traceFileExists;
}

//#######Unfinished Code for Concurrent Conversion!########
//bool ComStateMachineToSpenat::processExternalRegionTransition(VirtualTransitions& virtuals,
//                                                              const AbstractStateItem* nestedState,
//                                                              const ConcurrentStateItem* concurrent)
//{
//  Q_ASSERT(nestedState);
//  Q_ASSERT(concurrent);

//  for(const RegionItem* region : concurrent->regions())
//  {
//    if(region->state(nestedState->uuid()))
//      continue;

//    for(const AbstractStateItem* state : region->states())
//    {
//      if(checkStateType(state->stateType()))
//      {
//        VirtualTransition* virtualTransition = new VirtualTransition(nestedState);
//        if(!virtualTransition->appendState(state))
//        {
//          delete virtualTransition;
//          return false;
//        }
//        virtuals.append(virtualTransition);
//      }
//    }
//  }
//  return true;
//}
//##########################################################
