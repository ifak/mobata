#include "writebasemodel.hpp"

#include "../basemodel.hpp"
#include "../attributeitem.hpp"
#include "../componentitem.hpp"
#include "../linkitem.hpp"
#include "../paramitem.hpp"
#include "../paramvalueitem.hpp"
#include "../portitem.hpp"
#include "../signalitem.hpp"
#include "../datatypeitem.hpp"

#include "../propcomponents.hpp"
#include "../proplinks.hpp"
#include "../propports.hpp"

#include <QJsonObject>
#include <QJsonArray>

namespace model {
namespace base {
namespace io {

void writeModelItem(ModelItem const* modelItem,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(modelItem);

  jsonObject["uuid"] = modelItem->uuid().toString();

  return;
}

void writeBaseModel(BaseModel const* baseModel,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(baseModel);

  jsonObject["name"] = baseModel->name();
  writePropDataTypes(baseModel, jsonObject);
  writePropSignals(baseModel, jsonObject);
  writePropAttributes(baseModel, jsonObject);

  return;
}

void writeAttribute(AttributeItem const* attributeItem,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(attributeItem);

  writeModelItem(attributeItem, jsonObject);

  jsonObject["name"] = attributeItem->name();
  jsonObject["dataType"] = attributeItem->dataType();
  jsonObject["initValue"] = attributeItem->initValue();

  return;
}

void writeComponent(ComponentItem const* componentItem,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(componentItem);

  writeModelItem(componentItem, jsonObject);

  jsonObject["name"] = componentItem->name();
  jsonObject["compType"] = componentItem->compTypeString();
  writePropAttributes(componentItem, jsonObject);
  writePropPorts(componentItem, jsonObject);

  return;
}

void writeLink(LinkItem const* linkItem,
               QJsonObject& jsonObject)
{
  Q_ASSERT(linkItem);

  writeModelItem(linkItem, jsonObject);

  jsonObject["from"] = linkItem->from()->uuid().toString();
  jsonObject["to"] = linkItem->to()->uuid().toString();
  jsonObject["notation"] = linkItem->notation();
  if(linkItem->port())
  {
    QJsonObject portObject;
    writePort(linkItem->port(), portObject);
    jsonObject["port"] = portObject;
  }

  return;
}

void writeParamItem(ParamItem const* paramItem,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(paramItem);
  
  writeModelItem(paramItem, jsonObject);

  jsonObject["name"] = paramItem->name();
  jsonObject["dataType"] = paramItem->dataType();
  
  return;
}

void writeParamValueItem(ParamValueItem const* paramValueItem,
                         QJsonObject& jsonObject)
{
  Q_ASSERT(paramValueItem);

  writeModelItem(paramValueItem, jsonObject);

  jsonObject["param"] = paramValueItem->param()->name();
  jsonObject["value"] = paramValueItem->value().toString();

  return;
}

void writePort(PortItem const* portItem,
               QJsonObject& jsonObject)
{
  Q_ASSERT(portItem);

  writeModelItem(portItem, jsonObject);
  jsonObject["name"] = portItem->name();

  return;
}

void writeSignal(SignalItem const* signalItem,
                 QJsonObject& jsonObject)
{
  Q_ASSERT(signalItem);

  writeModelItem(signalItem, jsonObject);

  jsonObject["name"] = signalItem->name();
  if(signalItem->params().count())
  {
    QJsonArray paramsArray;
    foreach(ParamItem const* paramItem,
            signalItem->params())
    {
      QJsonObject paramObject;
      writeParamItem(paramItem, paramObject);
      paramsArray.append(paramObject);
    }
    jsonObject["params"] = paramsArray;
  }

  return;
}

void writeDataType(DataTypeItem const* typeItem,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(typeItem);

  writeModelItem(typeItem, jsonObject);

  jsonObject["name"] = typeItem->name();

  return;
}

void writePropAttributes(PropAttributes const* propAttributes,
                         QJsonObject& jsonObject)
{
  Q_ASSERT(propAttributes);
  QJsonArray attributesArray;

  if(!propAttributes->attributes().count())
  {
    jsonObject["attributes"] = attributesArray;
    return;
  }

  foreach (AttributeItem const* attributeItem,
           propAttributes->attributes())
  {
    QJsonObject attributeObject;
    writeAttribute(attributeItem, attributeObject);
    attributesArray.append(attributeObject);
  }
  jsonObject["attributes"] = attributesArray;

  return;
}

void writePropComponents(PropComponents const* propComponents,
                         QJsonObject& jsonObject)
{
  Q_ASSERT(propComponents);

  if(!propComponents->components().count())
    return;

  QJsonArray componentsArray;
  foreach (ComponentItem const* componentItem,
           propComponents->components())
  {
    QJsonObject componentObject;
    writeComponent(componentItem, componentObject);
    componentsArray.append(componentObject);
  }
  jsonObject["components"] = componentsArray;

  return;
}

void writePropLinks(PropLinks const* propLinks,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(propLinks);

  if(!propLinks->links().count())
    return;

  QJsonArray linksArray;
  foreach (LinkItem const* linkItem,
           propLinks->links())
  {
    QJsonObject linkObject;
    writeLink(linkItem, linkObject);
    linksArray.append(linkObject);
  }
  jsonObject["links"] = linksArray;

  return;
}

void writePropPorts(PropPorts const* propPorts,
                    QJsonObject& jsonObject)
{
  Q_ASSERT(propPorts);

  if(!propPorts->ports().count())
    return;

  QJsonArray portsArray;
  foreach (PortItem const* portItem,
           propPorts->ports())
  {
    QJsonObject portObject;
    writePort(portItem, portObject);
    portsArray.append(portObject);
  }
  jsonObject["ports"] = portsArray;

  return;
}

void writePropSignals(PropSignals const* propSignals,
                      QJsonObject& jsonObject)
{
  Q_ASSERT(propSignals);

  if(!propSignals->getSignals().count())
    return;

  QJsonArray signalsArray;
  foreach (SignalItem const* signalItem,
           propSignals->getSignals())
  {
    QJsonObject signalObject;
    writeSignal(signalItem, signalObject);
    signalsArray.append(signalObject);
  }
  jsonObject["signals"] = signalsArray;

  return;
}

void writePropDataTypes(PropDataTypes const* propDataTypes,
                        QJsonObject& jsonObject)
{
  Q_ASSERT(propDataTypes);

  QJsonArray typesArray;
  if(!propDataTypes->dataTypes().count())
  {
    jsonObject["dataTypes"] = typesArray;
    return;
  }

  foreach (DataTypeItem const* typeItem,
           propDataTypes->dataTypes())
  {
    QJsonObject typeObject;
    writeDataType(typeItem, typeObject);
    typesArray.append(typeObject);
  }
  jsonObject["dataTypes"] = typesArray;

  return;
}

} // namespace io
} // namespace base
} // namespace model
