#include "importrhapsodylayout.hpp"
#include "importrhapsodyutils.hpp"

#include <mobata/model/statemachine/concurrentstateitem.hpp>
#include <mobata/model/base/modelitem.hpp>
#include <graphlayout/layoutroles.hpp>

#include <QString>

namespace rhapsody {

ImportRhapsodyLayout::ImportRhapsodyLayout()
{
}

ImportRhapsodyLayout::~ImportRhapsodyLayout()
{
}

bool ImportRhapsodyLayout::importTransitionLayout(model::base::ModelItem* transitionItem,
                                                  const IRPTransitionPtr rhapsodyTransition,
                                                  QString* errorMessage)
{
  Q_ASSERT(transitionItem);
  Q_ASSERT(rhapsodyTransition);

  IRPGraphElementPtr graphElementPtr = transitionGraphElement(rhapsodyTransition,
                                                              errorMessage);
  if(!graphElementPtr)
    return false;


  importPolygon(transitionItem,
                graphElementPtr,
                errorMessage);

  importGenericProperty(transitionItem,
                        graphElementPtr,
                        QStringLiteral("LineStyle"),
                        LineStyleRole,
                        QStringLiteral(""),
                        errorMessage);
// does not seem to work under current rhapsody version
//  importPosition(transitionItem,
//                 graphElementPtr,
//                 QStringLiteral("TextPosition"),
//                 TextPositionRole,
//                 errorMessage);

  importGenericProperty(transitionItem,
                        graphElementPtr,
                        QStringLiteral("LineWidth"),
                        LineWidthRole,
                        QStringLiteral("double"),
                        errorMessage);

  importGenericProperty(transitionItem,
                        graphElementPtr,
                        QStringLiteral("TextFontSize"),
                        TextFontSizeRole,
                        QStringLiteral("int"),
                        errorMessage);

  importColor(transitionItem,
              graphElementPtr,
              QStringLiteral("ForegroundColor"),
              ForegroundColorRole,
              errorMessage);

  importColor(transitionItem,
              graphElementPtr,
              QStringLiteral("TextColor"),
              TextColorRole,
              errorMessage);

  return true;
}

void ImportRhapsodyLayout::importRegionLayout(model::statemachine::RegionItem* regionItem,
                                              const IRPStatePtr rhapsodyState,
                                              const model::statemachine::ConcurrentStateItem *concurrent,
                                              int totalRegions,
                                              int currentRegion,
                                              QString* errorMessage)
{
  Q_ASSERT(regionItem);
  Q_ASSERT(rhapsodyState);
  Q_ASSERT(concurrent);

  IRPGraphElementPtr graphElementPtr = stateGraphElement(rhapsodyState,
                                                         false,
                                                         errorMessage);
  if(!graphElementPtr)
    return;

  //absolute position
  QVariant concurrentPositionData = concurrent->data(AbsPositionRole);
  QPointF concurrentPosition(0,0);
  if(concurrentPositionData.isValid())
    concurrentPosition = concurrentPositionData.value<QPointF>();

  //size
  QVariant widthData = concurrent->data(WidthRole);
  QVariant heightData = concurrent->data(HeightRole);
  QSizeF concurrentSize(0,0);
  if(widthData.isValid() && heightData.isValid())
    concurrentSize = QSizeF(widthData.toDouble(),
                            heightData.toDouble());

  importGenericProperty(regionItem,
                        graphElementPtr,
                        QStringLiteral("LineWidth"),
                        LineWidthRole,
                        QStringLiteral("int"),
                        errorMessage);

  //set region size
  double regionWidth = concurrentSize.width();
  regionWidth /= totalRegions;
  regionItem->setData(regionWidth, WidthRole);
  regionItem->setData(concurrentSize.height(), HeightRole);

  //set region position
  QPointF regionPosition(concurrentPosition.x() + regionWidth * currentRegion,
                         concurrentPosition.y());
  QVariant regionPositionData;
  regionPositionData.setValue(regionPosition);
  regionItem->setData(regionPositionData, AbsPositionRole);

  //QString polygonString = graphPropertyValue(graphElementPtr, QStringLiteral("Polygon"), errorMessage);

  return;
}

IRPGraphElementPtr ImportRhapsodyLayout::transitionGraphElement(const IRPTransitionPtr transition,
                                                                QString* errorMessage)
{
  Q_ASSERT(transition);

  HRESULT hr;

  IRPGraphElementPtr graphElement = nullptr;
  IRPModelElementPtr graphModel = nullptr;
  IRPStatechartPtr statechart;
  VARIANT variant;
  BSTR sourceGUID, targetGUID;
  long count;
  IRPModelElementPtr owner;

  hr = transition->get_owner(&owner);
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


  hr = transition->get_GUID(&sourceGUID);
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

QString ImportRhapsodyLayout::graphPropertyValue(const IRPGraphElementPtr &graphElement,
                                                 const QString& propertyKey,
                                                 QString* errorMessage)
{
  Q_ASSERT(graphElement);

  HRESULT hr;
  BSTR key = SysAllocString(propertyKey.toStdWString().c_str());

  Q_ASSERT(key);

  BSTR value;
  IRPGraphicalPropertyPtr property;

  //get property from rhapsody
  hr = graphElement->getGraphicalProperty(key, &property);
  SysFreeString(key);
  if(hresultFailed2(property, hr, errorMessage, QStringLiteral("Could not get proporty of rhapsody graphical element.")))
    return 0;

  hr = property->get_value(&value);
  if(hresultFailed(hr, errorMessage, "Could not get value of rhapsody property."))
    return 0;

  return bstrConvert(value);
}

void ImportRhapsodyLayout::importPolygon(model::base::ModelItem* item,
                                         const IRPGraphElementPtr& graphElement,
                                         QString* errorMessage)
{
  Q_ASSERT(item);
  Q_ASSERT(graphElement);

  QString polygonString;

  polygonString = graphPropertyValue(graphElement, QStringLiteral("Polygon"), errorMessage);

  if(polygonString.isEmpty()){
    utils::AddPtrString(errorMessage) << "Could not retrieve edge polygon from rhapsody!";
    return;
  }

  const QStringList coordinateList = polygonString.split(',');

  QVector<QPointF> coordinates;
  //read polygon string, first element of string is number of coordinate pairs
  for(int i = 1; i < coordinateList.size()-1; i+=2){
    bool resultX(true), resultY(true);
    QPointF position(coordinateList.at(i).toDouble(&resultX),
                     coordinateList.at(i+1).toDouble(&resultY));
    coordinates.append(position);
    if(!resultX || !resultY){
      utils::AddPtrString(errorMessage) << "Conversion of coordinates retrived from rhapsody failed!";
      return;
    }
  }

  //setting coordinates
  QVariant polygonData;
  polygonData.setValue(coordinates);
  item->setData(polygonData, PolygonRole);

  //since Property "TextPosition" seems to retrieve no useful data, the label position is calculated from the edge position
  //calculate midpoint between start and end of edge
  double midpointX, midpointY;
  midpointX= (coordinates.begin()->x() + coordinates.last().x())/double(2);
  midpointY= (coordinates.begin()->y() + coordinates.last().y())/double(2);
  //create QPoint with offset
  QPointF textPosition = QPointF(midpointX + 20, midpointY + 20);
  QVariant textPositionData;
  textPositionData.setValue(textPosition);
  item->setData(textPositionData, TextPositionRole);

  return;
}

void ImportRhapsodyLayout::importGenericProperty(model::base::ModelItem* item,
                                                 const IRPGraphElementPtr &graphElement,
                                                 QString propertyKey,
                                                 int role,
                                                 QString type,
                                                 QString* errorMessage)
{
  Q_ASSERT(item);
  Q_ASSERT(graphElement);

  QString value;

  value = graphPropertyValue(graphElement, propertyKey, errorMessage);

  if(value.isEmpty()){
    utils::AddPtrString(errorMessage) << "Could not retrieve \"" << propertyKey << "\" property from rhapsody!";
    return;
  }

  //save property
  if(type == QStringLiteral("int")){
    bool result;
    int valueInt = value.toInt(&result, 10);
    if(!result){
      utils::AddPtrString(errorMessage) << "Conversion of \"" << propertyKey << "\" property to type integer failed!";
      return;
    }
    item->setData(valueInt, role);
  }
  else if(type == QStringLiteral("double")){
    bool result;
    double valueDouble = value.toDouble(&result);
    if(!result){
      utils::AddPtrString(errorMessage) << "Conversion of \"" << propertyKey << "\" property to type double failed!";
      return;
    }
    item->setData(valueDouble, role);
  }
  else{
    item->setData(value, role);
  }

  return;
}

void ImportRhapsodyLayout::importPosition(model::base::ModelItem* item,
                                          const IRPGraphElementPtr &graphElement,
                                          QString propertyKey,
                                          int positionRole,
                                          QString* errorMessage)
{
  Q_ASSERT(item);
  Q_ASSERT(graphElement);

  QString positionString;

  positionString = graphPropertyValue(graphElement, propertyKey, errorMessage);

  if(positionString.isEmpty()){
    utils::AddPtrString(errorMessage) << "Could not retrieve any coordinates from rhapsody!";
    return;
  }

  const QStringList coordinateList = positionString.split(',');
  if(coordinateList.empty() || coordinateList.size() != 2){
    utils::AddPtrString(errorMessage) << "Coordinates retrived from rhapsody can not be parsed!";
    return;
  }

  qreal posX, posY;
  bool resultX(true), resultY(true);

  posX = coordinateList.at(0).toDouble(&resultX);
  posY = coordinateList.at(1).toDouble(&resultY);
  if(!resultX || !resultY){
    utils::AddPtrString(errorMessage) << "Conversion of coordinates retrived from rhapsody failed!";
    return;
  }

  if(propertyKey == QStringLiteral("SourcePosition")){
    if(item->data(HeightRole).isValid() && item->data(WidthRole).isValid()){
      bool widthResult(false), heightResult(false);
      qreal width = item->data(WidthRole).toDouble(&widthResult);
      qreal height = item->data(HeightRole).toDouble(&heightResult);
      if(widthResult && heightResult){
        posX -= width/double(2);
        posY -= height/double(2);
      }
    }
  }

  //setting coordinates
  QVariant positionData;
  QPointF position(posX, posY);
  positionData.setValue(position);
  item->setData(positionData, positionRole);

  //since Property "TextPosition" seems to retrieve no useful data, the label position is calculated from the item position
  bool heightResult(true);
  double height = item->data(HeightRole).toDouble(&heightResult);
  if(heightResult){
    QPointF textPosition = QPointF(position.x(), position.y() - (height/double(8)));
    QVariant textPositionData;
    textPositionData.setValue(textPosition);
    item->setData(textPositionData, TextPositionRole);
  }

  return;
}

void ImportRhapsodyLayout::importSize(model::base::ModelItem* item,
                                      const IRPGraphElementPtr &graphElement,
                                      bool isNewInit,
                                      QString* errorMessage)
{
  Q_ASSERT(item);
  Q_ASSERT(graphElement);

  QString heightString, widthString, startPosString, endPosString;
  double height, width;

  if(!isNewInit){
    heightString = graphPropertyValue(graphElement, QStringLiteral("Height"), errorMessage);
    widthString = graphPropertyValue(graphElement, QStringLiteral("Width"), errorMessage);

    if(heightString.isEmpty() || widthString.isEmpty()){
      utils::AddPtrString(errorMessage) << "Could not retrieve element size from rhapsody!";
      return;
    }
    bool resultWidth(true), resultHight(true);
    height = heightString.toDouble(&resultHight);
    width = widthString.toDouble(&resultWidth);
    if(!resultHight || ! resultWidth){
      utils::AddPtrString(errorMessage) << "Could not convert element size value to type interger!";
      return;
    }
  }
  else{
    startPosString = graphPropertyValue(graphElement, QStringLiteral("SourcePosition"), errorMessage);
    endPosString = graphPropertyValue(graphElement, QStringLiteral("TargetPosition"), errorMessage);
    const QStringList startCoordinates = startPosString.split(',');
    const QStringList endCoordinates = endPosString.split(',');
    if(startCoordinates.empty()
       || endCoordinates.empty()
       || startCoordinates.size() != 2
       || endCoordinates.size() != 2){
      utils::AddPtrString(errorMessage) << "Size of a default initial simple state could not be parsed!";
      return;
    }

    //height of non-existant init item is calculated as quarter of the length of the default transition vector
    //sqrt((x1-x2)^2+(y1-y2)^2))/2
    double startX = startCoordinates.at(0).toDouble();
    double startY = startCoordinates.at(1).toDouble();
    double endX = endCoordinates.at(0).toDouble();
    double endY = endCoordinates.at(1).toDouble();
    width = sqrt(pow(startX - endX,2) + pow(startY - endY,2))/double(2);
    height = width*0.67;
  }

  item->setData(height, HeightRole);
  item->setData(width, WidthRole);
  return;
}

void ImportRhapsodyLayout::importColor(model::base::ModelItem* item,
                                       const IRPGraphElementPtr &graphElement,
                                       QString propertyKey,
                                       int role,
                                       QString* errorMessage)
{
  Q_ASSERT(item);
  Q_ASSERT(graphElement);

  QString value;

  value = graphPropertyValue(graphElement, propertyKey, errorMessage);
  if(value.isEmpty())
    return;

  QStringList valueList = value.split(",");

  if(valueList.count() != 3){
    utils::AddPtrString(errorMessage) << "Could not parse rgb values of property \"" << propertyKey << "\" from rhapsody!";
    return;
  }

//  QString valueHex("#");
//  valueHex.append(QString::number(valueList.at(0).toInt(), 16));
//  valueHex.append(QString::number(valueList.at(1).toInt(), 16));
//  valueHex.append(QString::number(valueList.at(2).toInt(), 16));
  bool resultRed(true), resultGreen(true), resultBlue(true);

  int red = valueList.at(0).toInt(&resultRed, 10);
  int green = valueList.at(1).toInt(&resultGreen, 10);
  int blue = valueList.at(2).toInt(&resultBlue, 10);

  if(!resultRed || !resultGreen || !resultBlue){
    utils::AddPtrString(errorMessage) << "Could not convert rgb values of property \"" << propertyKey << "\" to type integer!";
    return;
  }

  QColor color(red, green, blue);

  //save property
  item->setData(color, role);

  return;
}

} //rhapsody

