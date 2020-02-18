#include "importrhapsodylayout.hpp"
#include "importrhapsodyutils.hpp"
#include <mobata/model/statemachine/statemachine.hpp>
#include <graphlayout/layoutroles.hpp>

#include <QString>
#include <QStringList>

namespace rhapsody {

template<class RhapsodyPtr>
void ImportRhapsodyLayout::importStateLayout(model::base::ModelItem* item,
                                             const RhapsodyPtr& state,
                                             bool isNewInit,
                                             QString* errorMessage)
{
  Q_ASSERT(item);
  Q_ASSERT(state);

  IRPGraphElementPtr graphElementPtr = stateGraphElement(state,
                                                         isNewInit,
                                                         errorMessage);
  if(!graphElementPtr)
    return;

  QString positionKey;
  if(isNewInit)
    positionKey = QStringLiteral("SourcePosition");
  else
    positionKey = QStringLiteral("Position");

  importSize(item,
             graphElementPtr,
             isNewInit,
             errorMessage);

  importPosition(item,
                 graphElementPtr,
                 positionKey,
                 AbsPositionRole,
                 errorMessage);

  importGenericProperty(item,
                        graphElementPtr,
                        QStringLiteral("LineWidth"),
                        LineWidthRole,
                        QStringLiteral("int"),
                        errorMessage);

  importColor(item,
              graphElementPtr,
              QStringLiteral("BackgroundColor"),
              BackgroundColorRole,
              errorMessage);

  //does not seem to work under current rhapsody version
//  importPosition(item,
//                 graphElementPtr,
//                 QStringLiteral("TextPosition"),
//                 TextPositionRole,
//                 errorMessage);

  importColor(item,
              graphElementPtr,
              QStringLiteral("TextColor"),
              TextColorRole,
              errorMessage);

  importGenericProperty(item,
                        graphElementPtr,
                        QStringLiteral("TextFontSize"),
                        TextFontSizeRole,
                        "int",
                        errorMessage);

  //QString polygonString = graphPropertyValue(graphElementPtr, QStringLiteral("Polygon"), errorMessage);

  return;
}

template<class RhapsodyPtr>
IRPGraphElementPtr ImportRhapsodyLayout::stateGraphElement(const RhapsodyPtr& state,
                                                           bool isNewInit,
                                                           QString* errorMessage)
{
  Q_ASSERT(state);

  HRESULT hr;

  IRPGraphElementPtr graphElement = nullptr;
  IRPModelElementPtr graphModel = nullptr;
  IRPStatechartPtr statechart;
  VARIANT variant;
  BSTR sourceGUID, targetGUID;
  long count;
  IRPModelElementPtr owner;

  hr = state->get_owner(&owner);
  if(hresultFailed2(owner, hr, errorMessage, "Failed to get rhapsody owner item."))
    return nullptr;

  if(elementInterface(owner, errorMessage) == "IRPStatechart")
    statechart = owner;
  else
    return nullptr;

  Q_ASSERT(statechart);

  IRPCollectionPtr graphCollection;
  hr = statechart->get_graphicalElements(&graphCollection);
  if(hresultFailed2(graphCollection, hr, errorMessage, "Could not get graphical elements of rhapsody statechart."))
    return nullptr;

  hr = graphCollection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Could not get number of rhapsody project's graphical elements."))
    return nullptr;

  if(!count){
    utils::AddPtrString(errorMessage) << "Selected statechart contains no graphical elements.";
    return nullptr;
  }

  //Rhapsody connector types have no method "get_defaultTransition". A bad placement of a rhapsody default transition(infront of choice/junction item) may cause an error here!
  //->to prevent this, we check for rhapsodys IRPConnector type here (which includes choice and junction items)
  QString type = elementInterface(state, errorMessage);

  if(!isNewInit || type == "IRPConnector")
    hr = state->get_GUID(&sourceGUID);
  else{
    IRPTransitionPtr transition;

    hr = static_cast<const IRPStatePtr>(state)->get_defaultTransition(&transition);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody default transition."))
      return false;
    hr = transition->get_GUID(&sourceGUID);
  }
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody element GUID."))
    return nullptr;

  for(int i = 1; i <= count; i++){
    hr = graphCollection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody item."))
      return nullptr;

    variant.pdispVal->QueryInterface(IID_IRPGraphElement, (void**)&graphElement);
    hr = graphElement->get_modelObject(&graphModel);
    if(hresultFailed2(graphModel, hr, errorMessage, "Failed to get rhapsody model of graph element."))
      return nullptr;
    hr = graphModel->get_GUID(&targetGUID);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody element GUID."))
      return nullptr;

    if(bstrConvert(sourceGUID) == bstrConvert(targetGUID)){
      return graphElement;
    }
  }

  return nullptr;
}

} //rhapsody

