#include "importrhapsodyelementtree.hpp"
#include "importrhapsodyutils.hpp"

#include <QFileInfo>

using namespace rhapsody;

ImportRhapsodyElementTree::ImportRhapsodyElementTree()
{

}

ImportRhapsodyElementTree::~ImportRhapsodyElementTree()
{

}

bool ImportRhapsodyElementTree::loadRhapsodyElementTree(const IRPProjectPtr &rhapsodyProject,
                                                        QStandardItemModel* siModel,
                                                        QString* errorMessage)
{
  Q_ASSERT(siModel);
  Q_ASSERT(rhapsodyProject);
  IRPModelElementPtr rootElement = rhapsodyProject;

  QList<QStandardItem*> rootList = recursiveRhapsodyElement(rootElement,
                                                            errorMessage);
  if(rootList.count() == 0)
    return false;

  siModel->setColumnCount(1);
  siModel->setHeaderData(0, Qt::Horizontal,
                         QLatin1String("Rhapsody Project:"),
                         Qt::DisplayRole);

  QStandardItem * rootNode = siModel->invisibleRootItem();

  for(QList<QStandardItem*>::const_iterator it = rootList.constBegin(); it != rootList.constEnd(); it++)
    rootNode->appendRow((*it));

  return true;

}
//iterates trough whole rhapsody element hierarchy of packages, classes and statecharts
//adds only those "hierarchy paths" to QStandardItemModel, that have a nested statechart
QList<QStandardItem*> ImportRhapsodyElementTree::recursiveRhapsodyElement(const IRPModelElementPtr& lastRhapsodyElement,
                                                                          QString *errorMessage)
{
  Q_ASSERT(lastRhapsodyElement);

  HRESULT hr;
  IRPCollectionPtr collection;
  IRPModelElementPtr rhapsodyElement;
  VARIANT variant;
  long elementCount;
  QList<QStandardItem*> rootElementList;
  bool errorVar = false;

  hr = lastRhapsodyElement->getNestedElements(&collection);
  if(hresultFailed2(collection, hr, errorMessage, "Could not get element collection of rhapsody project."))
    errorVar = true;

  hr = collection->get_Count(&elementCount);
  if(hresultFailed(hr, errorMessage, "Failed to get rhapsody element count."))
    errorVar = true;

  if(!errorVar){
    for(int i = 1; i <= elementCount; i++)
    {
      hr = collection->get_Item(i, &variant);
      hresultFailed(hr, errorMessage, "Failed to get rhapsody item.");

      variant.pdispVal->QueryInterface(IID_IRPModelElement, (void**)&rhapsodyElement);

      QString interfaceName = elementInterface(rhapsodyElement, errorMessage);
      if(interfaceName == "IRPStatechart"){
        rootElementList.append(this->createElementItem(rhapsodyElement,
                                                       interfaceName,
                                                       errorMessage));
      }
      else if(interfaceName == "IRPPackage" || interfaceName == "IRPClass"){
        QList<QStandardItem*> subElementList = recursiveRhapsodyElement(rhapsodyElement,
                                                                        errorMessage);
        if(subElementList.count() != 0){
          QStandardItem* elementItem = this->createElementItem(rhapsodyElement,
                                                               interfaceName,
                                                               errorMessage);
          for(QList<QStandardItem*>::const_iterator it = subElementList.constBegin(); it != subElementList.constEnd(); it++)
            elementItem->appendRow((*it));

          rootElementList.append(elementItem);
        }
      }
    }
  }
  return rootElementList;
}

QStandardItem* ImportRhapsodyElementTree::createElementItem(const IRPModelElementPtr& rhapsodyElement,
                                                            const QString& interfaceName,
                                                            QString* errorMessage)
{
  Q_ASSERT(rhapsodyElement);

  QString nameString = elementName(rhapsodyElement, errorMessage);
  QStandardItem* elementItem;

  if(interfaceName == "IRPPackage")
    elementItem = new QStandardItem(QIcon(QStringLiteral(":/importrhapsody/images/package.png")), nameString);
  else if(interfaceName == "IRPClass")
    elementItem = new QStandardItem(QIcon(QStringLiteral(":/importrhapsody/images/class.png")), nameString);
  else if(interfaceName == "IRPStatechart")
      elementItem = new QStandardItem(QIcon(QStringLiteral(":/importrhapsody/images/statechart.png")), nameString);

  elementItem->setFlags(elementItem->flags()  & ~Qt::ItemIsEditable);

  return elementItem;
}
