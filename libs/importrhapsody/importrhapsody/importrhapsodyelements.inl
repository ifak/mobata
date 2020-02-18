#include "importrhapsodyelements.hpp"
#include "importrhapsodyutils.hpp"

#include <mobata/model/statemachine/statemachine.hpp>
#include <QStringList>

using namespace model::statemachine;

namespace rhapsody {

//create mobata statemachine states from all substates nested in a rhapsody state
template<class StatesModel>
bool ImportRhapsodyElements::createSubStates(StatesModel* smModel,
                                             const IRPStatechartPtr parentStatechart,
                                             const IRPStatePtr& state,
                                             QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(parentStatechart);
  Q_ASSERT(state);


  HRESULT hr;
  IRPCollectionPtr collection;
  IRPStatechartPtr statechart;
  long collectionCount;

  hr = state->get_nestedStatechart(&statechart);
  if(statechart != nullptr){
    //state has nested statechart, get state "ROOT" of statechart and then the actual nested state that contains the SubStates
    //Note: this code may look strange because the rhapsody api is even more strange
    IRPStatePtr rootState, rootSubState;
    VARIANT variant;
    hr = statechart->get_rootState(&rootState);
    if(hresultFailed2(rootState, hr, errorMessage, "Could not get rootstate of nested statechart item."))
      return false;
    hr = rootState->getSubStates(&collection);
    if(hresultFailed2(collection, hr, errorMessage, "Could not get nested state of root state."))
      return false;
    hr = collection->get_Item(1, &variant);
    if(hresultFailed(hr, errorMessage, "Could not get element of state collection."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPState, (void**)&rootSubState);

    hr = rootSubState->get_subStateVertices(&collection);
    if(hresultFailed2(collection, hr, errorMessage, "Could not get substate vertices of rhapsody root state."))
      return false;

    if(!createSubStates(smModel, statechart, rootSubState, errorMessage))
      return false;
  }
  else{

    IRPTransitionPtr defaultTransition = nullptr;
    state->get_defaultTransition(&defaultTransition);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody default transition."))
      return false;

    //checks if default transition exists and has valid action
    //if true, initial SimpleStateItem is created as source of the default transition
    if(defaultTransition != nullptr){
      this->_nextStateInitItem = true;
      if(hasAction(defaultTransition, errorMessage)){
        if(!createDefaultInitStateItem(smModel,
                                       state,
                                       defaultTransition,
                                       errorMessage))
          return false;
      }
    }

    hr = state->get_subStateVertices(&collection);
    if(hresultFailed2(collection, hr, errorMessage, "Could not get substate vertices of rhapsody root state."))
      return false;

    hr = collection->get_Count(&collectionCount);
    if(hresultFailed(hr, errorMessage, "Could not get total number of items in model item: \"collection\"."))
      return false;

    for(int i = 1; i <= collectionCount; i++){
      VARIANT variant;
      IRPModelElementPtr element;
      hr = collection->get_Item(i, &variant);
      if(hresultFailed(hr, errorMessage, "Failed to get rhapsody item."))
        return false;

      variant.pdispVal->QueryInterface(IID_IRPModelElement, (void**)&element);

      if(!rhapsodyItemCreation(smModel,
                               element,
                               errorMessage))
        return false;
    }
  }

  return true;
}

//checks if given rhapsody state is of type IRPState or IRPConnector
template<class StatesModel>
bool ImportRhapsodyElements::rhapsodyItemCreation(StatesModel* smModel,
                                                  const IRPModelElementPtr& rhapsodyElement,
                                                  QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(rhapsodyElement);

  QString type = elementInterface(rhapsodyElement, errorMessage);
  if(type == "IRPState"){
    return createStateItem(smModel,
                           rhapsodyElement,
                           errorMessage);
  }
  else if(type == "IRPConnector"){
    return createConnectorItem(smModel,
                               rhapsodyElement,
                               errorMessage);
  }
  return false;
}

//checks type of rhapsody state and converts it to a mobata state of corresponding type
template<class StatesModel>
bool ImportRhapsodyElements::createStateItem(StatesModel* smModel,
                                             const IRPStatePtr& rhapsodyState,
                                             QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(rhapsodyState);

  HRESULT hr;
  long result;
  hr = rhapsodyState->isLeaf(&result);
  if(result && !FAILED(hr)){
    QString typeName = stateType(rhapsodyState, errorMessage);

    if(typeName == "LocalTermination")
      return createFinalStateItem(smModel,
                                  rhapsodyState,
                                  errorMessage);
    else if(typeName == "EventState")
      utils::AddPtrString(errorMessage) << "EventState items are currently not supported.";
    else if(typeName == "Block")
      utils::AddPtrString(errorMessage) << "Block items are currently not supported.";
    else if(typeName == "Action")
      utils::AddPtrString(errorMessage) << "Action items are currently not supported.";
    else if(typeName == "Or"){
      if(this->_nextStateInitItem == true)
        return createInitStateItem(smModel,
                                   rhapsodyState,
                                   errorMessage);
      else
        return createSimpleStateItem(smModel,
                                     rhapsodyState,
                                     errorMessage);
    }
  }

  hr = rhapsodyState->isAnd(&result);
  IRPGraphNodePtr ptr;
  if(result && !FAILED(hr))
    return createConcurrentStateItem(smModel,
                                     rhapsodyState,
                                     errorMessage);

  hr = rhapsodyState->isCompound(&result);
  if(result && !FAILED(hr))
    return createCompositeStateItem(smModel,
                                    rhapsodyState,
                                    errorMessage);

  return false;
}

//checks type of rhapsody connector and converts it to a mobata state of corresponding type
template<class StatesModel>
bool ImportRhapsodyElements::createConnectorItem(StatesModel* smModel,
                                                 const IRPConnectorPtr& rhapsodyConnector,
                                                 QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(rhapsodyConnector);

  HRESULT hr;
  long result;
  hr = rhapsodyConnector->isJunctionConnector(&result);
  if(result && !FAILED(hr))
    return createJunctionStateItem(smModel,
                                   rhapsodyConnector,
                                   errorMessage);

  hr = rhapsodyConnector->isConditionConnector(&result);
  if(result && !FAILED(hr)){
    qWarning() << "Choice state detected! In the current version of this library, these are converted to junction states.";
    return createJunctionStateItem(smModel,
                                   rhapsodyConnector,
                                   errorMessage);
//    return createChoiceStateItem(smModel,
//                                 rhapsodyConnector,
//                                 errorMessage);

  }

  hr = rhapsodyConnector->isTerminationConnector(&result);
  if(result && !FAILED(hr))
    return createFinalStateItem(smModel,
                                rhapsodyConnector,
                                errorMessage);

  hr = rhapsodyConnector->isJoinConnector(&result);
  if(result)
    utils::AddPtrString(errorMessage) << "Join Connector items are currently not supported.";

  hr = rhapsodyConnector->isForkConnector(&result);
  if(result)
    utils::AddPtrString(errorMessage) << "Fork Connector items are currently not supported.";

  hr = rhapsodyConnector->isStubConnector(&result);
  if(result)
    utils::AddPtrString(errorMessage) << "Stub Connector items are currently not supported.";

  hr = rhapsodyConnector->isHistoryConnector(&result);
  if(result)
    utils::AddPtrString(errorMessage) << "History Connector items are currently not supported.";

  return true;
}

//creates a mobata state item of type simple from a given rhapsody state
template<class StatesModel>
bool ImportRhapsodyElements::createSimpleStateItem(StatesModel* smModel,
                                                   const IRPStatePtr& state,
                                                   QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  QString entryAction, exitAction;
  HRESULT hr;
  BSTR value;

  hr = state->get_entryAction(&value);
  if(hresultFailed(hr, errorMessage, "Failed to get entry action of a rhapsody state item."))
    return false;
  entryAction = bstrConvert(value);

  hr = state->get_exitAction(&value);
  if(hresultFailed(hr, errorMessage, "Failed to get exit action of a rhapsody state item."))
    return false;
  exitAction = bstrConvert(value);

  SimpleStateItem* simpleStateItem = new SimpleStateItem(elementName(state, errorMessage),
                                                         mobataStringFormat(entryAction),
                                                         mobataStringFormat(exitAction));
  smModel->addState(simpleStateItem, errorMessage);

  if(!this->updateTransitionList(simpleStateItem, state, errorMessage))
    return false;

  importStateLayout(simpleStateItem, state, false, errorMessage);

  return true;
}

//creates a mobata state item of type composite from a given rhapsody state
template<class StatesModel>
bool ImportRhapsodyElements::createCompositeStateItem(StatesModel* smModel,
                                                      const IRPStatePtr& state,
                                                      QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  QString entryAction, exitAction;
  HRESULT hr;
  BSTR value;

  hr = state->get_entryAction(&value);
  if(hresultFailed(hr, errorMessage, "Failed to get entry action of a rhapsody state item."))
    return false;
  entryAction = bstrConvert(value);

  hr = state->get_exitAction(&value);
  if(hresultFailed(hr, errorMessage, "Failed to get exit action of a rhapsody state item."))
    return false;
  exitAction = bstrConvert(value);

  CompositeStateItem* compositeStateItem = new CompositeStateItem(elementName(state, errorMessage));
  compositeStateItem->setEntryAction(mobataStringFormat(entryAction));
  compositeStateItem->setExitAction(mobataStringFormat(exitAction));

  smModel->addState(compositeStateItem, errorMessage);

  IRPStatechartPtr parentStatechart;
  state->get_itsStatechart(&parentStatechart);

  if(!createSubStates(compositeStateItem,
                      parentStatechart,
                      state,
                      errorMessage))
    return false;

  if(!updateTransitionList(compositeStateItem, state, errorMessage))
    return false;

  importStateLayout(compositeStateItem, state, false, errorMessage);

  if(compositeStateItem->initState() == nullptr)
    qWarning() << "The imported composite state has no initial state!";

  return true;
}

//creates a mobata state item of type concurrent from a given rhapsody state
template<class StatesModel>
bool ImportRhapsodyElements::createConcurrentStateItem(StatesModel* smModel,
                                                       const IRPStatePtr& state,
                                                       QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  ConcurrentStateItem* concurrentStateItem = new ConcurrentStateItem(elementName(state, errorMessage));
  smModel->addState(concurrentStateItem, errorMessage);

  importStateLayout(concurrentStateItem, state, false, errorMessage);

  if(!createRegionItem(concurrentStateItem,
                       state,
                       errorMessage))
    return false;

  if(!updateTransitionList(concurrentStateItem, state, errorMessage))
    return false;

  return true;
}

//creates mobata region items from a given rhapsody concurrent state
template<class StatesModel>
bool ImportRhapsodyElements::createRegionItem(StatesModel* smModel,
                                              const IRPStatePtr& state,
                                              QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  IRPStatechartPtr parentStatechart;
  state->get_itsStatechart(&parentStatechart);

  IRPCollectionPtr collection;
  HRESULT hr = state->getSubStates(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Failed to get substates of rhapsody concurrent item."))
    return false;

  long count;
  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of regions of concurrent item."))
    return false;

  bool result = true;
  for(int i = 1; i <= count; i++){
    bool localResult;
    VARIANT variant;
    IRPStatePtr element;
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPState, (void**)&element);
    RegionItem* region = new RegionItem(elementName(element, errorMessage));
    smModel->addRegion(region, errorMessage);

    ConcurrentStateItem* concurrent = static_cast<ConcurrentStateItem*>(smModel);
    if(concurrent != nullptr)
      importRegionLayout(region,
                         state,
                         concurrent,
                         count,
                         (i - 1),         //importRegionLayout needs region iterator starting from zero
                         errorMessage);

    localResult = createSubStates(region,
                                  parentStatechart,
                                  element,
                                  errorMessage);
    if(!localResult)
      result = false;

  }

  return result;
}

//creates a mobata state item of type init from a given rhapsody state
//creates a transition item from rhapsody default transition
template<class StatesModel>
bool ImportRhapsodyElements::createInitStateItem(StatesModel* smModel,
                                                 const IRPStatePtr& state,
                                                 QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  SimpleStateItem* initStateItem = new SimpleStateItem("");
  QString stateName = elementName(state, errorMessage);

  initStateItem->setName(stateName);

  if(!smModel->addState(initStateItem, errorMessage))
     return false;

  if(!smModel->setInitState(initStateItem, errorMessage))
     return false;

  if(!updateTransitionList(initStateItem, state, errorMessage))
    return false;

  importStateLayout(initStateItem, state, false, errorMessage);

  this->_nextStateInitItem = false;

  return true;
}

//creates a mobata state item of type init from a given rhapsody state
//creates a transition item from rhapsody default transition
template<class StatesModel>
bool ImportRhapsodyElements::createDefaultInitStateItem(StatesModel* smModel,
                                                        const IRPStatePtr& rootState,
                                                        const IRPTransitionPtr& defaultTransition,
                                                        QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(rootState);

  TransitionElements element;

  SimpleStateItem* initStateItem = new SimpleStateItem("");
  initStateItem->setName(QStringLiteral("defaultInit"));

  if(!createTransitionElement(element, defaultTransition, errorMessage))
    return false;

  element.source = initStateItem;
  this->_transitionList.append(element);

  if(!smModel->addState(initStateItem, errorMessage))
     return false;

  if(!smModel->setInitState(initStateItem, errorMessage))
     return false;

  importStateLayout(initStateItem, rootState, true, errorMessage);

  this->_nextStateInitItem = false;

  return true;
}

//creates a mobata state item of type final from a given rhapsody state
template<class StatesModel, class RhapsodyPtr>
bool ImportRhapsodyElements::createFinalStateItem(StatesModel* smModel,
                                                  const RhapsodyPtr& state,
                                                  QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  FinalStateItem* finalStateItem = new FinalStateItem(elementName(state, errorMessage));
  smModel->addState(finalStateItem, errorMessage);

  if(!updateTransitionList(finalStateItem, state, errorMessage))
    return false;

  importStateLayout(finalStateItem, state, false, errorMessage);

  return true;
}

//creates a mobata state item of type junction from a given rhapsody connector
template<class StatesModel>
bool ImportRhapsodyElements::createJunctionStateItem(StatesModel* smModel,
                                                     const IRPConnectorPtr& state,
                                                     QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  JunctionStateItem* junctionStateItem = new JunctionStateItem(elementName(state, errorMessage));
  smModel->addState(junctionStateItem, errorMessage);

  if(!updateTransitionList(junctionStateItem, state, errorMessage))
    return false;

  importStateLayout(junctionStateItem, state, false, errorMessage);

  return true;
}

//creates a mobata state item of type choice from a given rhapsody connector
template<class StatesModel>
bool ImportRhapsodyElements::createChoiceStateItem(StatesModel* smModel,
                                                   const IRPConnectorPtr& state,
                                                   QString* errorMessage)
{
  Q_ASSERT(smModel);
  Q_ASSERT(state);

  ChoiceStateItem* choiceStateItem = new ChoiceStateItem(elementName(state, errorMessage));
  smModel->addState(choiceStateItem, errorMessage);

  if(!updateTransitionList(choiceStateItem, state, errorMessage))
    return false;

  importStateLayout(choiceStateItem, state, false, errorMessage);

  return true;
}

//adds new transitions to list of transitions if they are new
//updates source and target attributes of existing transition elements in transition list
template<class ElementModelPtr>
bool ImportRhapsodyElements::updateTransitionList(AbstractStateItem* stateItem,
                                                  const ElementModelPtr& elementModel,
                                                  QString* errorMessage)
{
  Q_ASSERT(stateItem);
  Q_ASSERT(elementModel);

  if(!conditionalTransitionUpdate(stateItem, elementModel, true, errorMessage))
    return false;

  if(!conditionalTransitionUpdate(stateItem, elementModel, false, errorMessage))
    return false;

  return true;
}

//updates source or target attributes in existing transitions elements
template<class ElementModelPtr>
bool ImportRhapsodyElements::conditionalTransitionUpdate(AbstractStateItem* stateItem,
                                                         const ElementModelPtr& elementModel,
                                                         const bool isTransitionSource,
                                                         QString* errorMessage)
{
  Q_ASSERT(stateItem);
  Q_ASSERT(elementModel);

  HRESULT hr;
  IRPCollectionPtr collection;

  if(isTransitionSource)
    hr = elementModel->getOutTransitions(&collection);
  else
    hr = elementModel->getInTransitions(&collection);

  if(hresultFailed2(collection, hr, errorMessage, "Failed to get transitions of rhapsody element."))
    return false;

  long count;
  collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of transitions of a rhapsody element."))
    return false;

  for(int i = 1; i <= count; i++){
    VARIANT variant;
    IRPTransitionPtr transition;

    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody transition item."))
      return false;
    variant.pdispVal->QueryInterface(IID_IRPTransition, (void**)&transition);

    long defaultCheck;

    hr = transition->isDefaultTransition(&defaultCheck);
    if(hresultFailed(hr, errorMessage, "Could not check if transition is default transition."))
      return false;

    //default transitions behave strange for getOutTransitions() and getInTransitions() methods in rhapsody.
    //Since they are only important for the creation of init states, they are created there separately and updateded here only for target states
    if(defaultCheck == 1 && isTransitionSource)
      continue;
    else{
      if(!updateTransitionElement(stateItem, transition, isTransitionSource)){
        TransitionElements element;
        if(!createTransitionElement(element, transition, errorMessage))
          return false;

        if(isTransitionSource)
          element.source = stateItem;
        else
          element.target = stateItem;

        this->_transitionList.append(element);
      }
    }
  }

  return true;
}

//helper function for reading rhapsody attribute values
template<class AttributeElement>
QString ImportRhapsodyElements::attributeBody(const AttributeElement& attribute,
                                              QString* errorMessage)
{
  Q_ASSERT(attribute);

  HRESULT hr;
  BSTR body;
  hr = attribute->get_body(&body);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody element name."))
    return "error";

  return bstrConvert(body);
}

} //rhapsody
