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

#include <QXmlStreamReader>
#include <QString>

#include "../../../utils/functors.hpp"
#include "../datatypeitem.hpp"
#include "../signalitem.hpp"
#include "../attributeitem.hpp"
#include "../portitem.hpp"

namespace model{
namespace base{
namespace io{

template<class AttributeType>
bool readXmlStreamReaderAttribute(const QXmlStreamReader& xmlStreamReader,
                                  const QString& attributeName,
                                  AttributeType* attribute,
                                  QString* errorMessage)
{
  Q_ASSERT(attribute);

  if(!xmlStreamReader.attributes().hasAttribute(attributeName))
  {
    if(errorMessage)
      *errorMessage += QObject::tr("xml-type '%1' has no attribute '%2'")
                       .arg(QString(xmlStreamReader.name().toString()))
                       .arg(attributeName);
    return false;
  }

  QString attrStringValue=xmlStreamReader.attributes().value(attributeName).toString();
  bool result = utils::string2podvalue<AttributeType>(attrStringValue,
                                                      attribute,
                                                      errorMessage);
  if(!result)
    return false;

  return true;
}

template<class SystemModel>
bool readXmlDataTypes(QXmlStreamReader* xmlStreamReader,
                      SystemModel* systemModel,
                      QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name() == "types");

  while (xmlStreamReader->readNextStartElement())
  {
    QString typeName;
    if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader, QStringLiteral("name"),
                                              &typeName, errorMessage))
      return false;

    QUuid typeUuid;
    if(!readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader, QStringLiteral("uuid"),
                                            &typeUuid, errorMessage))
      return false;

    if(xmlStreamReader->name() == QStringLiteral("base_type"))
    {
      DataTypeItem* newTypeItem=systemModel->addDataType(typeName, errorMessage);
      if(!newTypeItem)
        return false;
      newTypeItem->setUuid(typeUuid);
      xmlStreamReader->skipCurrentElement();
    }
    else if(xmlStreamReader->name() == QStringLiteral("typedef"))
    {
      DataTypeItem* newTypeItem=systemModel->addDataType(typeName, errorMessage);
      if(!newTypeItem)
        return false;
      newTypeItem->setUuid(typeUuid);
      xmlStreamReader->skipCurrentElement();
    }
    else if(xmlStreamReader->name() == QStringLiteral("enumeration"))
    {
      DataTypeItem* newTypeItem=systemModel->addDataType(typeName, errorMessage);
      if(!newTypeItem)
        return false;
      newTypeItem->setUuid(typeUuid);
      xmlStreamReader->skipCurrentElement();
    }
    else
    {
      if(errorMessage)
        *errorMessage+=QObject::tr("data type '%1' is currently not supported!")
                       .arg(xmlStreamReader->name().toString());
      return false;
    }
  }

  return true;
}

template<class SystemModel>
bool readXmlSignalParameter(QXmlStreamReader* xmlStreamReader,
                            SignalItem* signalItem,
                            SystemModel* systemModel,
                            QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(signalItem);
  Q_ASSERT(systemModel);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name() == "parameter");

  QString paramName;
  if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                            QStringLiteral("name"),
                                            &paramName,
                                            errorMessage))
    return false;

  QString typeName;
  if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                            QStringLiteral("type"),
                                            &typeName,
                                            errorMessage))
    return false;

  DataTypeItem* paramDataType=systemModel->dataType(typeName);
  if(!paramDataType)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("data type '%1' for "
                                 "param '%2' of signal '%3' "
                                 "could not be found!")
                     .arg(typeName).arg(paramName)
                     .arg(signalItem->name());
    return false;
  }

  ParamItem* newParam=signalItem->addParameter(paramName,
                                               paramDataType->name(),
                                               errorMessage);
  if(!newParam)
    return false;

  xmlStreamReader->skipCurrentElement();

  return true;
}

template<class SystemModel>
bool readXmlSignals(QXmlStreamReader* xmlStreamReader,
                    SystemModel* systemModel,
                    QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name() == QStringLiteral("signals"));

  while (xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("signal"))
    {
      QString signalName;
      if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader, QStringLiteral("name"),
                                                &signalName, errorMessage))
        return false;

      QUuid signalUuid;
      if(!readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader, QStringLiteral("uuid"),
                                              &signalUuid, errorMessage))
        return false;

      SignalItem* newSignalItem=systemModel->addSignal(signalName, errorMessage);
      if(!newSignalItem)
        return false;
      newSignalItem->setUuid(signalUuid);

      ///read signal parameter/////////
      while (xmlStreamReader->readNextStartElement())
      {
        if(xmlStreamReader->name() == QStringLiteral("parameter"))
        {
          bool result = readXmlSignalParameter(xmlStreamReader,
                                               newSignalItem,
                                               systemModel,
                                               errorMessage);
          if(!result)
            return false;
        }
      }
    }
  }

  return true;
}

template<class SystemModel>
bool readXmlAttributes(QXmlStreamReader* xmlStreamReader,
                       SystemModel* systemModel,
                       QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name() == QStringLiteral("attributes"));

  while (xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("attribute"))
    {
      QString attributeName;
      if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader, QStringLiteral("name"),
                                                &attributeName, errorMessage))
        return false;

      QString typeName;
      if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader, QStringLiteral("type"),
                                                &typeName, errorMessage))
        return false;

      QString initValue;
      if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader, QStringLiteral("initValue"),
                                                &initValue, errorMessage))
        return false;

      DataTypeItem* paramDataType=systemModel->dataType(typeName);
      if(!paramDataType)
      {
        if(errorMessage)
          *errorMessage+=QObject::tr("data type '%1' for attribute '%2' could not be found!")
                         .arg(typeName).arg(attributeName);
        return false;
      }

      AttributeItem* newAttribute=systemModel->addAttribute(attributeName,paramDataType->name(),
                                                            initValue,errorMessage);
      if(!newAttribute)
        return false;
      xmlStreamReader->skipCurrentElement();
    }
  }

  return true;
}

template<class SystemModel>
bool readXmlPorts(QXmlStreamReader* xmlStreamReader,
                  SystemModel* systemModel,
                  QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name() == QStringLiteral("ports"));

  while (xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("port"))
    {
      QString portName;
      if(!readXmlStreamReaderAttribute<QString>(*xmlStreamReader, QStringLiteral("name"),
                                                &portName, errorMessage))
        return false;

      QUuid portUuid;
      if(!readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader, QStringLiteral("uuid"),
                                              &portUuid, errorMessage))
        return false;

      PortItem* newPortItem=systemModel->addPort(portName,errorMessage);
      if(!newPortItem)
        return false;
      newPortItem->setUuid(portUuid);
      xmlStreamReader->skipCurrentElement();
    }
  }

  return true;
}

} // namespace io
} // namespace base
} // namespace model
