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

#pragma once

#include "../datatypeitem.hpp"
#include "../attributeitem.hpp"
#include "../signalitem.hpp"
#include "../paramitem.hpp"
#include "../paramvalueitem.hpp"
#include "../componentitem.hpp"
#include "../linkitem.hpp"
#include "../portitem.hpp"

#include <QJsonObject>
#include <QJsonArray>

#include <QObject>

namespace model {
namespace base {
namespace io {

///read objects//////////

template<class DataTypeModel>
bool readDataTypes(const QJsonObject& jsonObject,
                   DataTypeModel* dataTypeModel,
                   QString* errorMessage)
{
  Q_ASSERT(dataTypeModel);

  return readObjectArray(jsonObject, QStringLiteral("dataTypes"),
                         dataTypeModel, ReadDataType<DataTypeModel>(),
                         errorMessage);
}

template<class DataTypeModel>
bool ReadDataType<DataTypeModel>::operator()(const QJsonObject& jsonObject,
                                             DataTypeModel* dataTypeModel,
                                             QString* errorMessage)
{
  Q_ASSERT(dataTypeModel);

  QUuid uuid;
  bool result = readProperty<QUuid>(jsonObject,
                                    QStringLiteral("uuid"),
                                    &uuid,
                                    errorMessage);
  if(!result)
    return false;

  QString name;
  result = readProperty<QString>(jsonObject,
                                 QStringLiteral("name"),
                                 &name,
                                 errorMessage);
  if(!result)
    return false;

  if(!dataTypeModel->addDataType(name, uuid, errorMessage))
    return false;

  return true;
}

template<class SignalsModel>
bool readSignals(const QJsonObject& jsonObject,
                 SignalsModel* signalsModel,
                 QString* errorMessage)
{
  Q_ASSERT(signalsModel);

  return readObjectArray(jsonObject, QStringLiteral("signals"),
                         signalsModel, ReadSignal<SignalsModel>(),
                         errorMessage);
}

template<class SignalsModel>
bool ReadSignal<SignalsModel>::operator()(const QJsonObject& jsonObject,
                                          SignalsModel* signalsModel,
                                          QString* errorMessage)
{
  Q_ASSERT(signalsModel);

  QUuid uuid;
  QString name;
  bool result = readProperty_2<QUuid,QString>(jsonObject,
                                              QStringLiteral("uuid"),
                                              &uuid,
                                              QStringLiteral("name"),
                                              &name,
                                              errorMessage);
  if(!result)
    return false;

  SignalItem* newSignal=signalsModel->addSignal(name,
                                                errorMessage);
  if(!newSignal)
    return false;

  newSignal->setUuid(uuid);

  //has params?///
  if(jsonObject.value(QStringLiteral("params")) != QJsonValue::Undefined)
  {
    result = readParams(jsonObject, newSignal, signalsModel, errorMessage);
    if(!result)
      return false;
  }

  return true;
}

template<class AttributesModel>
bool readAttributes(const QJsonObject& jsonObject,
                    AttributesModel* attributesModel,
                    QString* errorMessage)
{
  Q_ASSERT(attributesModel);

  return readObjectArray(jsonObject, QStringLiteral("attributes"),
                         attributesModel, ReadAttribute<AttributesModel>(),
                         errorMessage);
}

template<class AttributesModel>
bool ReadAttribute<AttributesModel>::operator()(const QJsonObject& jsonObject,
                                                AttributesModel* attributesModel,
                                                QString* errorMessage)
{
  Q_ASSERT(attributesModel);

  QUuid uuid;
  QString name;
  QString dataTypeName;
  QString initValue;
  bool result = readProperty_4<QUuid,QString,QString,QString>(jsonObject,
                                                              QStringLiteral("uuid"),
                                                              &uuid,
                                                              QStringLiteral("name"),
                                                              &name,
                                                              QStringLiteral("dataType"),
                                                              &dataTypeName,
                                                              QStringLiteral("initValue"),
                                                              &initValue,
                                                              errorMessage);
  if(!result)
    return false;

  DataTypeItem const* dataTypeItem=attributesModel->dataType(dataTypeName);
  if(!dataTypeItem)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("data type '%1' for "
                                 "attribute '%2' could not be found!")
                     .arg(dataTypeName).arg(name);
    return false;
  }

  AttributeItem* newAttribute=attributesModel->addAttribute(name,
                                                            dataTypeItem->name(),
                                                            initValue,
                                                            errorMessage);
  if(!newAttribute)
    return false;

  newAttribute->setUuid(uuid);

  return true;
}

template<class ComponentsModel>
bool readComponents(const QJsonObject& jsonObject,
                    ComponentsModel* componentsModel,
                    QString* errorMessage)
{
  Q_ASSERT(componentsModel);

  return readComponents(jsonObject, componentsModel,
                        ReadComponent<ComponentsModel>(), errorMessage);
}

template<class ComponentsModel, class ReadComponentFunctor>
bool readComponents(const QJsonObject& jsonObject,
                    ComponentsModel* componentsModel,
                    ReadComponentFunctor readComponentFunctor,
                    QString* errorMessage)
{
  Q_ASSERT(componentsModel);

  return readObjectArray(jsonObject, QStringLiteral("components"),
                         componentsModel, readComponentFunctor,
                         errorMessage);
}

template<class ComponentsModel>
bool ReadComponent<ComponentsModel>::operator()(const QJsonObject& jsonObject,
                                                ComponentsModel* componentsModel,
                                                QString* errorMessage)
{
  Q_ASSERT(componentsModel);

  QUuid uuid;
  QString name;
  bool result = readProperty_2<QUuid,QString>(jsonObject,
                                              QStringLiteral("uuid"),
                                              &uuid,
                                              QStringLiteral("name"),
                                              &name,
                                              errorMessage);
  if(!result)
    return false;

  ComponentItem* newComponent = new ComponentItem(name);
  newComponent->setUuid(uuid);

  result = componentsModel->addComponent(newComponent,errorMessage);
  if(!result)
  {
    delete newComponent;
    return false;
  }

  return true;
}

template<class LinksModel>
bool readLinks(const QJsonObject& jsonObject,
               LinksModel* linksModel,
               QString* errorMessage)
{
  Q_ASSERT(linksModel);

  return readObjectArray(jsonObject, QStringLiteral("links"),
                         linksModel, ReadLink<LinksModel>(),
                         errorMessage);
}

template<class LinksModel>
bool ReadLink<LinksModel>::operator()(const QJsonObject& jsonObject,
                                      LinksModel* linksModel,
                                      QString* errorMessage)
{
  Q_ASSERT(linksModel);

  QUuid uuid;
  QUuid fromUuid;
  QUuid toUuid;
  QString notation;
  bool result = readProperty_4<QUuid,QUuid,QUuid,QString>(jsonObject,
                                                          QStringLiteral("uuid"),
                                                          &uuid,
                                                          QStringLiteral("from"),
                                                          &fromUuid,
                                                          QStringLiteral("to"),
                                                          &toUuid,
                                                          QStringLiteral("notation"),
                                                          &notation,
                                                          errorMessage);
  if(!result)
    return false;

  PortItem const* fromPort = linksModel->port(fromUuid);
  if(!fromPort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("source port with uuid '%1' of link with uuid '%2' could not be found!")
                       .arg(fromUuid.toString()).arg(uuid.toString());
    return false;
  }

  PortItem const* toPort = linksModel->port(toUuid);
  if(!toPort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("target port with uuid '%1' of link with uuid '%2' could not be found!")
                       .arg(toUuid.toString()).arg(uuid.toString());
    return false;
  }

  LinkItem* newLinkItem = new LinkItem(fromPort, toPort, notation);
  newLinkItem->setUuid(uuid);
  result = linksModel->addLink(newLinkItem, errorMessage);
  if(!result)
  {
    delete newLinkItem;
    return false;
  }

  ///has port-id?//////////////
  if(jsonObject.value(QStringLiteral("port")) != QJsonValue::Undefined)
  {
    QUuid linkPortId;
    result = readProperty<QUuid>(jsonObject,
                                 QStringLiteral("port"),
                                 &linkPortId,
                                 errorMessage);
    if(!result)
      return false;

    const_cast<PortItem*>(newLinkItem->port())->setUuid(linkPortId);
  }

  return true;
}

template<class ParamsModel, class DataTypeModel>
bool readParams(const QJsonObject& jsonObject,
                ParamsModel* paramsModel,
                DataTypeModel* dataTypeModel,
                QString* errorMessage)
{
  Q_ASSERT(paramsModel);
  Q_ASSERT(dataTypeModel);

  return readObjectArray(jsonObject,
                         QStringLiteral("params"),
                         paramsModel,
                         ReadParam<ParamsModel, DataTypeModel>(dataTypeModel),
                         errorMessage);
}

template<class ParamsModel, class DataTypeModel>
bool ReadParam<ParamsModel, DataTypeModel>::operator()(const QJsonObject& jsonObject,
                                                       ParamsModel* paramsModel,
                                                       QString* errorMessage)
{
  Q_ASSERT(paramsModel);
  Q_ASSERT(this->_dataTypeModel);

  QUuid uuid;
  QString name;
  QString dataTypeName;
  bool result = readProperty_3<QUuid,QString,QString>(jsonObject,
                                                      QStringLiteral("uuid"),
                                                      &uuid,
                                                      QStringLiteral("name"),
                                                      &name,
                                                      QStringLiteral("dataType"),
                                                      &dataTypeName,
                                                      errorMessage);
  if(!result)
    return false;

  DataTypeItem const* dataTypeItem=this->_dataTypeModel->dataType(dataTypeName);
  if(!dataTypeItem)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("data type '%1' for "
                                 "param '%2' could not be found!")
                     .arg(dataTypeName).arg(name);
    return false;
  }

  ParamItem* newParameter=paramsModel->addParameter(name,
                                                    dataTypeItem->name(),
                                                    errorMessage);
  if(!newParameter)
    return false;

  newParameter->setUuid(uuid);

  return true;
}

template<class ParamsModel, class ParamValuesModel>
bool readParamValues(const QJsonObject& jsonObject,
                     ParamsModel* paramsModel,
                     ParamValuesModel* paramValuesModel,
                     QString* errorMessage)
{
  Q_ASSERT(paramsModel);
  Q_ASSERT(paramValuesModel);

  return readParamValues(jsonObject,
                         paramValuesModel,
                         ReadParamValue<ParamsModel, ParamValuesModel>(paramsModel),
                         errorMessage);
}

template<class ParamValuesModel, class ReadParamValueFunctor>
bool readParamValues(const QJsonObject& jsonObject,
                     ParamValuesModel* paramValuesModel,
                     ReadParamValueFunctor readParamValueFunctor,
                     QString* errorMessage)
{
  Q_ASSERT(paramValuesModel);

  return readObjectArray(jsonObject,
                         QStringLiteral("paramValues"),
                         paramValuesModel,
                         readParamValueFunctor,
                         errorMessage);
}

template<class ParamsModel, class ParamValuesModel>
bool ReadParamValue<ParamsModel, ParamValuesModel>::operator()(const QJsonObject& jsonObject,
                                                               ParamValuesModel* paramValuesModel,
                                                               QString* errorMessage)
{
  Q_ASSERT(paramValuesModel);
  Q_ASSERT(this->_paramsModel);

  QUuid uuid;
  QString param;
  QString value;
  bool result = readProperty_3<QUuid,QString,QString>(jsonObject,
                                                      QStringLiteral("uuid"),
                                                      &uuid,
                                                      QStringLiteral("param"),
                                                      &param,
                                                      QStringLiteral("value"),
                                                      &value,
                                                      errorMessage);
  if(!result)
    return false;

  ParamItem const* paramItem=this->_paramsModel->parameter(param);
  if(!paramItem)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("parameter '%1' of param-owner '%2' "
                                 "of param-value '%3' not found!")
                     .arg(param).arg(this->_paramsModel->toString()).arg(value);
    return false;
  }

  ParamValueItem* newParamValue=paramValuesModel->addParamValue(paramItem,
                                                                value);
  newParamValue->setUuid(uuid);

  return true;
}

template<class PortsModel>
bool readPorts(const QJsonObject& jsonObject,
               PortsModel* portsModel,
               QString* errorMessage)
{
  Q_ASSERT(portsModel);

  return readObjectArray(jsonObject, QStringLiteral("ports"),
                         portsModel, ReadPort<PortsModel>(),
                         errorMessage);
}

template<class PortsModel>
bool ReadPort<PortsModel>::operator()(const QJsonObject& jsonObject,
                                      PortsModel* portsModel,
                                      QString* errorMessage)
{
  Q_ASSERT(portsModel);

  QUuid uuid;
  QString name;
  bool result = readProperty_2<QUuid,QString>(jsonObject,
                                              QStringLiteral("uuid"),
                                              &uuid,
                                              QStringLiteral("name"),
                                              &name,
                                              errorMessage);
  if(!result)
    return false;

  PortItem* newPort = portsModel->addPort(name, errorMessage);
  if(!newPort)
    return false;
  newPort->setUuid(uuid);

  return true;
}

} // namespace io
} // namespace base
} // namespace model

#include "readhelpers.hpp"
