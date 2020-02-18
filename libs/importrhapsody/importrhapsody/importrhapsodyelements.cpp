#include "importrhapsodyelements.hpp"

#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/functionitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/prop/types.hpp>

namespace rhapsody {

ImportRhapsodyElements::ImportRhapsodyElements(QMap<QString, QString> *rules):
  _nextStateInitItem(false),
  _rules(rules)
{

}

ImportRhapsodyElements::~ImportRhapsodyElements()
{

}

//public method to initialize import of selected rhapsody events to a mobata statemachine
bool ImportRhapsodyElements::importEvent(model::statemachine::StateMachineModel* smModel,
                                         const IRPPackagePtr& package,
                                         QString* errorMessage)
{
  Q_ASSERT(package);
  Q_ASSERT(smModel);

  IRPCollectionPtr collection;
  IRPEventPtr event;
  VARIANT variant;
  HRESULT hr;
  long count;

  hr = package->get_events(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Failed to get list of all events in rhapsody project."))
    return false;

  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of events of the current rhapsody project."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody event item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPEvent, (void**)&event);
    if(!createEvent(smModel, event, errorMessage))
      return false;
  }

  return true;
}

//creates a mobata statemachine signal item from a rhapsody event
bool ImportRhapsodyElements::createEvent(model::statemachine::StateMachineModel* smModel,
                                         const IRPEventPtr& event,
                                         QString* errorMessage)
{
  Q_ASSERT(event);
  Q_ASSERT(smModel);

  HRESULT hr;
  IRPCollectionPtr collection;
  IRPArgumentPtr argument;
  IRPClassifierPtr classifier;
  VARIANT variant;
  BSTR signalName, dataTypeName, argumentName;
  long count;

  //get event name and create signal item
  hr = event->get_name(&signalName);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody event name."))
    return false;

  SignalItem* signal = smModel->signal(bstrConvert(signalName));
  if(!signal)
  {
    signal = new SignalItem(bstrConvert(signalName));
    if(!signal)
      return false;
  }

  hr = event->get_arguments(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Failed to get attribute collection of rhapsody event."))
    return false;

  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of attributes in rhapsody event."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPArgument, (void**)&argument);

    hr = argument->get_name(&argumentName);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute name."))
      return false;

    hr = argument->get_type(&classifier);
    if(hresultFailed2(classifier, hr, errorMessage, "Failed to get rhapsody attribute classifier."))
      return false;

    classifier->get_name(&dataTypeName);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody classifier name."))
      return false;

    DataTypeItem* dataTypeItem = smModel->dataType(bstrConvert(dataTypeName));
    if(!dataTypeItem)
    {
      dataTypeItem = new DataTypeItem(bstrConvert(dataTypeName));
      if(!dataTypeItem)
        return false;
      else
        smModel->addDataType(dataTypeItem, errorMessage);
    }

    signal->addParameter(bstrConvert(argumentName),
                         dataTypeItem->name(),
                         errorMessage);
  }

  smModel->addSignal(signal);

  return true;
}

//public method to initialize import of selected rhapsody datatypes to a mobata statemachine
bool ImportRhapsodyElements::importDataType(model::statemachine::StateMachineModel* smModel,
                                            const IRPCollectionPtr& collection,
                                            QString* errorMessage)
{
  Q_ASSERT(collection);
  Q_ASSERT(smModel);

  IRPModelElementPtr element;
  VARIANT variant;
  HRESULT hr;
  long count;

  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of dataTypes of the current rhapsody project."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody dataType item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPModelElement, (void**)&element);

    if(elementInterface(element, errorMessage) == QStringLiteral("IRPType"))
      if(!createDataType(smModel, element, errorMessage))
         return false;
  }

  return true;
}

//creates a mobata statemachine dataType from a rhapsody dataType
bool ImportRhapsodyElements::createDataType(model::statemachine::StateMachineModel* smModel,
                                            const IRPTypePtr& dataType,
                                            QString* errorMessage)
{
  Q_ASSERT(dataType);
  Q_ASSERT(smModel);

  HRESULT hr;
  BSTR dataTypeName;

  //get dataType name and create new dataType item if it was not created yet
  hr = dataType->get_name(&dataTypeName);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody dataType name."))
    return false;

  QString dataTypeNameStr = bstrConvert(dataTypeName);
  if(ruleKeyExists(dataTypeNameStr))
    return true;

  DataTypeItem* dataTypeItem = smModel->dataType(dataTypeNameStr);
  if(!dataTypeItem)
  {
    dataTypeItem = new DataTypeItem(dataTypeNameStr);
    if(!dataTypeItem)
      return false;
    else{
      BSTR baseTypeName, description;
      IRPClassifierPtr baseType;
      hr = dataType->get_typedefBaseType(&baseType);
      if(hresultFailed(hr, errorMessage, "Failed to get rhapsody base type of data type."))
        return false;

      if(!baseType){
        smModel->addDataType(dataTypeItem, errorMessage);
        return true;
      }

      hr = baseType->get_name(&baseTypeName);
      QString baseTypeNameString = bstrConvert(baseTypeName);
      if(hresultFailed(hr, errorMessage, "Failed to get rhapsody base type name."))
        return false;
      if(!baseTypeNameString.isEmpty()){
        dataTypeItem->setTypeEnum(prop::string2typeEnum(baseTypeNameString));
        if(dataTypeItem->typeEnum() == prop::Unknown)
          dataTypeItem->setCustomType(bstrConvert(baseTypeName));
      }

      hr = dataType->get_description(&description);
      if(hresultFailed(hr, errorMessage, "Failed to get description of rhapsody base type."))
        return false;

      QString descriptionStr = bstrConvert(description);

      if(baseTypeNameString != QStringLiteral("bool") && !descriptionStr.isEmpty() && descriptionStr.contains(QStringLiteral("Allowed Values:"))){
        QStringList descriptionList= descriptionStr.split(QRegExp("\\b"), QString::SkipEmptyParts);
        bool keywordFound = false;

        for(QStringList::iterator it = descriptionList.begin(); it != descriptionList.end(); it++){
          bool reachedEnd = false;
          QString temp;
          if(it >= descriptionList.end()-2)
            reachedEnd = true;

           if(!reachedEnd && !keywordFound){
            if((*it) == QStringLiteral("Allowed") && *(it+2) == QStringLiteral("Values")){
              keywordFound = true;
              it+3;
            }
           }

          if(keywordFound){
            bool conversionCheck = false;
            (*it).toUInt(&conversionCheck);
            if(conversionCheck){
              temp.append(*it);
              conversionCheck = false;
              if(!reachedEnd){
                if(*(it+1) == QStringLiteral(".") || *(it+1) == QStringLiteral(",")){
                  (*(it+2)).toUInt(&conversionCheck);
                  if(conversionCheck){
                    temp.append(QStringLiteral(".") + *(it+2));
                    it = it+2;
                  }
                }
              }
              if(dataTypeItem->lowest().isEmpty())
                dataTypeItem->setLowest(temp);
              else if(dataTypeItem->highest().isEmpty())
                dataTypeItem->setHighest(temp);
            }
          }
        }
      }
      smModel->addDataType(dataTypeItem, errorMessage);
    }
  }

  return true;
}

//public method to initialize import of selected rhapsody attributes to a mobata statemachine
bool ImportRhapsodyElements::importAttribute(model::statemachine::StateMachineModel* smModel,
                                             const IRPClassPtr& rhapsodyClass,
                                             QString* errorMessage)
{
  Q_ASSERT(rhapsodyClass);
  Q_ASSERT(smModel);

  IRPCollectionPtr collection;
  IRPAttributePtr attribute;
  VARIANT variant;
  HRESULT hr;
  long count;

  hr = rhapsodyClass->get_attributes(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Failed to get list of all attributes in rhapsody class."))
    return false;

  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of attributes of the current rhapsody class."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPAttribute, (void**)&attribute);
    if(!this->createAttribute(smModel, attribute, errorMessage))
      return false;
  }

  return true;
}

//public method to initialize import of selected rhapsody attributes to a mobata statemachine
bool ImportRhapsodyElements::importOperation(model::statemachine::StateMachineModel* smModel,
                                             const IRPClassPtr& rhapsodyClass,
                                             QString* errorMessage)
{
  Q_ASSERT(rhapsodyClass);
  Q_ASSERT(smModel);

  IRPCollectionPtr collection;
  IRPOperationPtr operation;
  VARIANT variant;
  HRESULT hr;
  long count;

  hr = rhapsodyClass->get_operations(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Failed to get list of all operations in rhapsody class."))
    return false;

  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of operations of the current rhapsody class."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody operation item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPOperation, (void**)&operation);
    if(!this->createOperation(smModel, operation, errorMessage))
      return false;
  }

  return true;
}

//creates a mobata statemachine attribute item from a rhapsody attribute
bool ImportRhapsodyElements::createAttribute(model::statemachine::StateMachineModel* smModel,
                                             const IRPAttributePtr& attribute,
                                             QString* errorMessage)
{
  Q_ASSERT(attribute);
  Q_ASSERT(smModel);

  HRESULT hr;
  IRPArgumentPtr argument;
  IRPClassifierPtr classifier;
  BSTR attributeName, dataTypeName, initValue;

  //get attribute name and create new attribute item if it was not created yet
  hr = attribute->get_name(&attributeName);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute name."))
    return false;

  hr = attribute->get_type(&classifier);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute classifier."))
    return false;

  hr = attribute->get_defaultValue(&initValue);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute init value."))
    return false;

  classifier->get_name(&dataTypeName);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody classifier name."))
    return false;

  QString qdataTypeName = bstrConvert(dataTypeName);
  DataTypeItem* dataTypeItem = smModel->dataType(qdataTypeName);
  if(!dataTypeItem)
  {
    dataTypeItem = new DataTypeItem(qdataTypeName);
    if(!dataTypeItem)
      return false;
    else
      smModel->addDataType(dataTypeItem, errorMessage);
  }

  QString qattributeName = bstrConvert(attributeName);
  AttributeItem* newAttribute = smModel->attribute(qattributeName);
  if(!newAttribute){
    newAttribute = new AttributeItem(qattributeName,
                                     dataTypeItem->name(),
                                     bstrConvert(initValue));
    if(!newAttribute)
      return false;
    else
      smModel->addAttribute(newAttribute, errorMessage);
  }

  return true;
}

//creates a mobata statemachine attribute item from a rhapsody attribute
bool ImportRhapsodyElements::createOperation(model::statemachine::StateMachineModel* smModel,
                                             const IRPOperationPtr& operation,
                                             QString* errorMessage)
{
  Q_ASSERT(operation);
  Q_ASSERT(smModel);

  HRESULT hr;
  IRPClassifierPtr classifier;
  IRPCollectionPtr arguments;
  BSTR operationName, returnTypeName, body;
  VARIANT variant;
  long count;

  //get attribute name and create new attribute item if it was not created yet
  hr = operation->get_name(&operationName);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute name."))
    return false;

  hr = operation->get_body(&body);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody operation body value."))
    return false;


  hr = operation->get_returns(&classifier);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody operation return type."))
    return false;

  classifier->get_name(&returnTypeName);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody classifier name."))
    return false;

  hr = operation->get_arguments(&arguments);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody operation parameters."))
    return false;

  hr = arguments->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of attributes of the current rhapsody operation."))
    return false;

  QString functionName = bstrConvert(operationName);
  model::base::FunctionItem* functionItem = smModel->function(functionName);
  if(!functionItem){
    functionItem = new model::base::FunctionItem(functionName,
                                                 bstrConvert(returnTypeName),
                                                 bstrConvert(body));
    if(!functionItem)
      return false;
    else
      smModel->addFunction(functionItem, errorMessage);
  }

  QString statementString=bstrConvert(body);
  functionItem->setStatementBody(mobataStringFormat(statementString));

  for(int i = 1; i <= count; i++){
    IRPArgumentPtr argument;
    BSTR argumentName, argumentTypeName;
    IRPClassifierPtr argumentType;
    hr = arguments->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute item."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPArgument, (void**)&argument);

    //get attribute name and create new attribute item if it was not created yet
    hr = argument->get_name(&argumentName);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute name."))
      return false;

    hr = argument->get_type(&argumentType);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody attribute classifier."))
      return false;

    argumentType->get_name(&argumentTypeName);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody classifier name."))
      return false;

    QString qargumentTypeName = bstrConvert(argumentTypeName);
    DataTypeItem* argumentTypeItem = smModel->dataType(qargumentTypeName);
    if(!argumentTypeItem)
    {
      argumentTypeItem = new DataTypeItem(qargumentTypeName);
      if(!argumentTypeItem)
        return false;
      else
        smModel->addDataType(argumentTypeItem, errorMessage);
    }

    model::base::ParamItem* paramItem = new model::base::ParamItem(bstrConvert(argumentName),
                                                                   argumentTypeItem->name());
    if(paramItem != nullptr)
      functionItem->addParameter(paramItem);
  }

  return true;
}

//public method to initialize import of selected rhapsody ports to a mobata statemachine
bool ImportRhapsodyElements::importPort(model::statemachine::StateMachineModel* smModel,
                                        const IRPClassPtr& rhapsodyClass,
                                        QString* errorMessage)
{
  Q_ASSERT(rhapsodyClass);
  Q_ASSERT(smModel);

  IRPCollectionPtr collection;;
  IRPModelElementPtr element;
  VARIANT variant;
  HRESULT hr;
  long count;


  //easier why to get all ports, since ports could also be nested in subclasses if they were added in an object model diagram
  hr = rhapsodyClass->getNestedElementsRecursive(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Failed to get list of all ports in rhapsody class."))
    return false;

  hr = collection->get_Count(&count);
  if(hresultFailed(hr, errorMessage, "Failed to get number of a rhapsody item collection."))
    return false;

  for(int i = 1; i <= count; i++){
    hr = collection->get_Item(i, &variant);
    if(hresultFailed(hr, errorMessage, "Failed to get rhapsody port item."))
      return false;

    hr = collection->get_Count(&count);
    if(hresultFailed(hr, errorMessage, "Failed to get number of attributes of the current rhapsody class."))
      return false;

    variant.pdispVal->QueryInterface(IID_IRPModelElement, (void**)&element);

    if(elementInterface(element, errorMessage) == QStringLiteral("IRPPort"))
      if(!this->createPort(smModel, element, errorMessage))
        return false;
  }

  PortItem* defaultPort = new PortItem(QStringLiteral("defaultPort"));
  smModel->addPort(defaultPort, errorMessage);

  return true;
}

//creates a mobata statemachine port item from a rhapsody port
bool ImportRhapsodyElements::createPort(model::statemachine::StateMachineModel* smModel,
                                        const IRPPortPtr& port,
                                        QString* errorMessage)
{
  Q_ASSERT(port);
  Q_ASSERT(smModel);

  HRESULT hr;
  BSTR name;

  //get port name and create new port item if it was not created yet
  hr = port->get_name(&name);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody port name."))
    return false;

  const model::base::PortItem* portItem = smModel->port(bstrConvert(name));
  if(!portItem)
  {
    model::base::PortItem* newPortItem = new model::base::PortItem(bstrConvert(name));
    if(!newPortItem)
      return false;
    else
      smModel->addPort(newPortItem, errorMessage);
  }

  return true;
}

//creates new transitions element from a given rhapsody transition
bool ImportRhapsodyElements::createTransitionElement(TransitionElements& element,
                                                     const IRPTransitionPtr& transition,
                                                     QString* errorMessage)
{
  Q_ASSERT(transition);

  IRPActionPtr action;
  IRPGuardPtr guard;
  IRPTriggerPtr trigger;

  //replace substring "params->" by ".msg"
  transition->getItsAction(&action);
  if(action != nullptr)
  {
    QString attributeBodyString=attributeBody(action, errorMessage);
    element.action = mobataStringFormat(attributeBodyString);
  }
  else
    element.action = QStringLiteral("");

  transition->getItsTrigger(&trigger);
  if(trigger != nullptr)
    element.signal = attributeBody(trigger, errorMessage);
  else
    element.signal = QStringLiteral("");

  transition->getItsGuard(&guard);
  if(guard != nullptr){
    QString guardString=attributeBody(guard, errorMessage);
    element.guard = mobataStringFormat(guardString);
  }
  else
    element.guard = QStringLiteral("");

  element.transition = transition;

  return true;
}

//updates source or target attribute of mobata transitions
bool ImportRhapsodyElements::updateTransitionElement(AbstractStateItem* stateItem,
                                                     const IRPTransitionPtr& transition,
                                                     const bool isTransitionSource)
{
  for(TransitionList::iterator it = this->_transitionList.begin(); it != this->_transitionList.end(); it++)
  {
    if(transition == it->transition){
      if(isTransitionSource)
        it->source = stateItem;
      else
        it->target = stateItem;
      return true;
    }
  }

  return false;
}

QString ImportRhapsodyElements::mobataStringFormat(QString &input)
{
  replaceParams(input);
  replaceByRule(input);
  return input;
}

void ImportRhapsodyElements::replaceByRule(QString& input)
{
  if(this->_rules == nullptr)
    return;

  if(this->_rules->isEmpty() || input.isEmpty())
    return;

  QStringList inputList = input.split(QRegExp("\\b"));
  foreach(QString key, this->_rules->keys()){
    for(QStringList::iterator it = inputList.begin(); it != inputList.end(); it++)
      if((*it) == key)
        (*it) = this->_rules->value(key);
  }

  input = inputList.join("");
}

bool ImportRhapsodyElements::ruleKeyExists(QString key)
{
  if(this->_rules != nullptr){
    foreach(QString ruleKey, this->_rules->keys())
      if(ruleKey == key)
        return true;
  }
  return false;
}

} //rhapsody
