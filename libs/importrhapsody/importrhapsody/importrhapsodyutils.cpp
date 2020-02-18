#include "importrhapsodyutils.hpp"

#include <QList>
#include <QString>
#include <QObject>

using namespace utils;

namespace rhapsody {

//return model name of given element
QString elementName(const IRPModelElementPtr& element,
                    QString* errorMessage)
{
  Q_ASSERT(element);

  HRESULT hr;
  BSTR elementName;
  hr = element->get_name(&elementName);
  if (FAILED(hr))
  {
    AddPtrString(errorMessage) << "Failed to get rhapsody element name.";
    return false;
  }

  return bstrConvert(elementName);
}

//return rhapsody class interface name of given element
QString elementInterface(const IRPModelElementPtr& element,
                         QString *errorMessage)
{
  Q_ASSERT(element);

  HRESULT hr;
  BSTR interfaceName;
  hr = element->get_interfaceName(&interfaceName);
  if(FAILED(hr))
  {
    AddPtrString(errorMessage) << "Could not get interface name of element: "
                               << elementName(element, errorMessage);
    return "INVALID_INTERFACE";
  }

  return bstrConvert(interfaceName);
}

//return rhapsody class interface name of given element
QString stateType(const IRPStatePtr& state,
                  QString *errorMessage)
{
  Q_ASSERT(state);

  HRESULT hr;
  BSTR typeName;
  hr = state->get_stateType(&typeName);
  if(FAILED(hr))
  {
    AddPtrString(errorMessage) << "Could not get type name of state: "
                               << elementName(state, errorMessage);
    return "INVALID_TYPE";
  }

  return bstrConvert(typeName);
}

//return model type name of given element
QString elementType(const IRPModelElementPtr& element,
                    QString *errorMessage)
{
  Q_ASSERT(element);

  HRESULT hr;
  BSTR interfaceName;
  hr = element->get_interfaceName(&interfaceName);
  if(FAILED(hr))
  {
    AddPtrString(errorMessage) << "Could not get interface name of element: "
                               << elementName(element, errorMessage);
    return "INVALID_INTERFACE";
  }

  return bstrConvert(interfaceName);
}

//return model element by given name
IRPModelElementPtr findModelElement(const QString& name,
                                    const IRPCollectionPtr& elementCollection,
                                    QString* errorMessage)
{
  Q_ASSERT(elementCollection);

  HRESULT hr;
  IRPModelElementPtr element;
  VARIANT variant;
  long elementCount;
  hr = elementCollection->get_Count(&elementCount);
  if (FAILED(hr))
  {
    AddPtrString(errorMessage) << "Failed to get rhapsody element count.";
    return false;
  }

  for(int i = 1; i <= elementCount; i++)
  {
    hr = elementCollection->get_Item(i, &variant);
    if (FAILED(hr))
    {
      AddPtrString(errorMessage) << "Failed to get rhapsody item.";
      return false;
    }
    variant.pdispVal->QueryInterface(IID_IRPModelElement, (void**)&element);
    QString nameString = elementName(element, errorMessage);
    if(nameString == name)
      return element;
  }

  AddPtrString(errorMessage) << "Failed to get rhapsody element: " ;
  //AddPtrString(errorMessage) << "Failed to get rhapsody element: "<< elementName.toLatin1();
  return false;
}

//Check if path elements are included in current rhapsody element
//method is not used currently because rhapsody enforces unique names on each hierarchy level.
bool containsPathElements(const QList<QString>& pathList,
                          int currentPathPos,
                          const IRPModelElementPtr& element,
                          QString *errorMessage)
{
  Q_ASSERT(element);

  if(pathList.count() == currentPathPos + 1)
     return false;

  HRESULT hr;
  IRPCollectionPtr collection;
  hr = element->getNestedElementsRecursive(&collection);
  if (FAILED(hr))
  {
    AddPtrString(errorMessage) << "Failed to get nested elements of rhapsody parent element.";
    return false;
  }

  long elementsCollectionCount;
  hr = collection->get_Count(&elementsCollectionCount);
  VARIANT variant;
  for ( int i = 1; i <= elementsCollectionCount; i++)
  {
    IRPModelElementPtr nestedElement;
    hr = collection->get_Item(i, &variant);
    hr = variant.pdispVal->QueryInterface(IID_IRPModelElement, (void**)&nestedElement);
    for(QList<QString>::const_iterator it = pathList.constBegin(); it != pathList.constEnd(); it++)
    {
      if(elementName(nestedElement, errorMessage) == *it)
      {
        currentPathPos++;
        break;
      }
    }

    if(pathList.count() == currentPathPos + 1)
       return true;
  }

  return false;
}

//helper function for converting string of type BSTR to QString
QString bstrConvert(const BSTR& string)
{
  LPCWSTR tmpName = string;
  return QString::fromWCharArray(tmpName);
}

bool hasAction(const IRPTransitionPtr& transition, QString *errorMessage)
{
  Q_ASSERT(transition);

  HRESULT hr;
  IRPActionPtr action = nullptr;
  hr = transition->getItsAction(&action);
  if(hresultFailed2(transition, hr, errorMessage, "Failed to get action of rhapsody default transition."))
    return false;
  if(action == nullptr)
    return false;

  return true;
}

void replaceParams(QString& string){
  if(string.contains("params->")){
    QStringList stringList = string.split(QRegExp("\\b"));
    for(int in = 0; in < stringList.count(); in++){
      if((in = stringList.indexOf("params", in)) != -1 && (in+1 < stringList.count())){
        if(stringList.at(in+1) == "->"){
          stringList.replace(in, "msg.");
          stringList.removeAt(in+1);
          string = stringList.join("");
        }
      }
      else
        break;
    }
  }
}

} //rhapsody
