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

#include "comimportxmlspenat.hpp"

#include "../spenatdeclmodel.hpp"

#include "../../../utils/functors.hpp"
#include "../../base/datatypeitem.hpp"
#include "../../base/signalitem.hpp"
#include "../../base/attributeitem.hpp"
#include "../../base/portitem.hpp"
#include "../../base/signaltriggeritem.hpp"
#include "../../base/timeouttriggeritem.hpp"

#include "../../spenat/placeitem.hpp"
#include "../../spenat/transitionitem.hpp"

#include <QFileInfo>
#include <QDomDocument>

using namespace model;
using namespace model::spenat;
using namespace model::spenat::io;
using namespace model::base;

class ComImportXmlSpenat::Private
{
  friend class ComImportXmlSpenat;

  QString           _fileName;
  SpenatDeclModel*  _declModel;

  Private(const QString& fileName,
          SpenatDeclModel* declModel)
    : _fileName(fileName),
      _declModel(declModel)
  {}
};

ComImportXmlSpenat::ComImportXmlSpenat(const QString& fileName,
                                       SpenatDeclModel* declModel,
                                       QObject *parent)
  : QObject(parent), _d(new Private(fileName, declModel))
{}

ComImportXmlSpenat::~ComImportXmlSpenat()
{
  delete this->_d;
}

template<class AttributeType>
bool readAttribute(const QDomElement& domElement,
                   const QString& attributeName,
                   AttributeType* attribute,
                   QString* errorMessage)
{
  Q_ASSERT(attribute);

  if(!domElement.hasAttribute(attributeName))
  {
    if(errorMessage)
      *errorMessage += QObject::tr("xml-type '%1' has no attribute '%2'")
                       .arg(domElement.tagName()).arg(attributeName);
    return false;
  }

  QString attrStringValue=domElement.attribute(attributeName);
  bool result = utils::string2podvalue<AttributeType>(attrStringValue,
                                                      attribute,
                                                      errorMessage);
  if(!result)
    return false;

  return true;
}

bool readTypesElement(const QDomElement& domTypesElement,
                      SpenatDeclModel* declModel,
                      QString* errorMessage)
{
  Q_ASSERT(declModel);

  QDomNode domNode = domTypesElement.firstChild();
  while(!domNode.isNull())
  {
    QDomElement domElement = domNode.toElement(); // try to convert the node to an element.
    if(!domElement.isNull())
    {
      QString typeName;
      if(!readAttribute<QString>(domElement, QStringLiteral("name"), &typeName, errorMessage))
        return false;

      QUuid typeUuid;
      if(!readAttribute<QUuid>(domElement, QStringLiteral("uuid"), &typeUuid, errorMessage))
        return false;

      if(domElement.tagName()=="base_type")
      {
        DataTypeItem* newTypeItem=declModel->addDataType(typeName, errorMessage);
        if(!newTypeItem)
          return false;
        newTypeItem->setUuid(typeUuid);
      }
      else if(domElement.tagName()=="typedef")
      {
        DataTypeItem* newTypeItem=declModel->addDataType(typeName, errorMessage);
        if(!newTypeItem)
          return false;
        newTypeItem->setUuid(typeUuid);
      }
      else if(domElement.tagName()=="enumeration")
      {
        DataTypeItem* newTypeItem=declModel->addDataType(typeName, errorMessage);
        if(!newTypeItem)
          return false;
        newTypeItem->setUuid(typeUuid);
      }
      else
      {
        if(errorMessage)
          *errorMessage+=QObject::tr("type '%1' is currently not supported!")
                         .arg(domElement.tagName());
        return false;
      }
    }

    domNode = domNode.nextSibling();
  }

  return true;
}

bool readSignalParameterElement(const QDomElement& domSignalParameterElement,
                                SignalItem* signalItem,
                                SpenatDeclModel* declModel,
                                QString* errorMessage)
{
  Q_ASSERT(signalItem);
  Q_ASSERT(declModel);

  QDomNode domNode = domSignalParameterElement.firstChild();
  while(!domNode.isNull())
  {
    QDomElement domElement = domNode.toElement(); // try to convert the node to an element.
    if(!domElement.isNull())
    {
      if(domElement.tagName()=="parameter")
      {
        QString paramName;
        if(!readAttribute<QString>(domElement, QStringLiteral("name"), &paramName, errorMessage))
          return false;

        QString typeName;
        if(!readAttribute<QString>(domElement, QStringLiteral("type"), &typeName, errorMessage))
          return false;

        DataTypeItem* paramDataType=declModel->dataType(typeName);
        if(!paramDataType)
        {
          if(errorMessage)
            *errorMessage+=QObject::tr("data type '%1' for param '%2' of signal '%3' could not be found!")
                           .arg(typeName).arg(paramName).arg(signalItem->name());
          return false;
        }

        ParamItem* newParam=signalItem->addParameter(paramName,
                                                         paramDataType->name(),
                                                         errorMessage);
        if(!newParam)
          return false;
      }
    }

    domNode = domNode.nextSibling();
  }

  return true;
}

bool readSignalsElement(const QDomElement& domSignalsElement,
                        SpenatDeclModel* declModel,
                        QString* errorMessage)
{
  Q_ASSERT(declModel);

  QDomNode domNode = domSignalsElement.firstChild();
  while(!domNode.isNull())
  {
    QDomElement domElement = domNode.toElement(); // try to convert the node to an element.
    if(!domElement.isNull())
    {
      if(domElement.tagName()=="signal")
      {
        QString signalName;
        if(!readAttribute<QString>(domElement, QStringLiteral("name"), &signalName, errorMessage))
          return false;

        QUuid signalUuid;
        if(!readAttribute<QUuid>(domElement, QStringLiteral("uuid"), &signalUuid, errorMessage))
          return false;

        SignalItem* newSignalItem=declModel->addSignal(signalName, errorMessage);
        if(!newSignalItem)
          return false;
        newSignalItem->setUuid(signalUuid);

        ///read signal parameter/////////
        if(!readSignalParameterElement(domElement,newSignalItem,declModel,errorMessage))
          return false;
      }
    }

    domNode = domNode.nextSibling();
  }

  return true;
}

bool readTransitionElement(const QDomElement& domTransitionElement,
                           SpenatDeclModel* declModel,
                           QString* errorMessage)
{
  Q_ASSERT(declModel);

  QUuid transitionId;
  if(!readAttribute<QUuid>(domTransitionElement, QStringLiteral("id"), &transitionId, errorMessage))
    return false;

  QScopedPointer<ATriggerItem> triggerItem;
  QString guardString=QStringLiteral("");
  QString effectString=QStringLiteral("");

  QDomNode domNode = domTransitionElement.firstChild();
  while(!domNode.isNull())
  {
    QDomElement domElement = domNode.toElement(); // try to convert the node to an element.
    if(!domElement.isNull())
    {
      if(domElement.tagName()=="trigger")
      {
        QDomNode triggerChildNode = domElement.firstChild();
        while(!triggerChildNode.isNull())
        {
          QDomElement triggerChildElement = triggerChildNode.toElement();
          if(!triggerChildElement.isNull())
          {
            if(triggerChildElement.tagName()=="signal")
            {
              QUuid signalUuid;
              if(!readAttribute<QUuid>(triggerChildElement, QStringLiteral("signal_id"),
                                       &signalUuid, errorMessage))
                return false;
              QUuid portUuid;
              if(!readAttribute<QUuid>(triggerChildElement, QStringLiteral("port_id"),
                                       &portUuid, errorMessage))
                return false;

              SignalItem const* triggerSignal=declModel->signal(signalUuid);
              if(!triggerSignal)
              {
                if(errorMessage)
                  *errorMessage+=QObject::tr("trigger signal '%1' for tranisition '%2' could not be found!")
                                 .arg(signalUuid.toString()).arg(transitionId.toString());
                return false;
              }

              PortItem const* triggerPort=declModel->portById(portUuid);
              if(!triggerPort)
              {
                if(errorMessage)
                  *errorMessage+=QObject::tr("trigger port '%1' for tranisition '%2' could not be found!")
                                 .arg(portUuid.toString()).arg(transitionId.toString());
                return false;
              }
              triggerItem.reset(new SignalTriggerItem(triggerSignal, triggerPort));
            }
            else if(triggerChildElement.tagName()=="timeout")
            {
              double timeoutValue;
              if(!readAttribute<double>(triggerChildElement, QStringLiteral("value"),
                                        &timeoutValue, errorMessage))
                return false;

              triggerItem.reset(new TimeoutTriggerItem(timeoutValue));
            }
          }
          triggerChildNode=triggerChildNode.nextSibling();
        }
      }
      else if(domElement.tagName()=="guard")
      {
        if(!readAttribute<QString>(domElement, QStringLiteral("value"), &guardString, errorMessage))
          return false;
      }

      else if(domElement.tagName()=="effect")
      {
        if(!readAttribute<QString>(domElement, QStringLiteral("value"), &effectString, errorMessage))
          return false;
      }
    }

    domNode = domNode.nextSibling();
  }

  TransitionItem* newTransition= new TransitionItem(QString(QStringLiteral("t_%1")).arg(QUuid::createUuid().toString()),
                                                    triggerItem.take(),
                                                    guardString,
                                                    effectString,
                                                    transitionId);
  bool result = declModel->addTransition(newTransition);
  Q_ASSERT(result);

  return true;
}

bool readNetElement(const QDomElement& domNetElement,
                    SpenatDeclModel* declModel,
                    QString* errorMessage)
{
  Q_ASSERT(declModel);

  QDomNode domNode = domNetElement.firstChild();
  while(!domNode.isNull())
  {
    QDomElement domElement = domNode.toElement(); // try to convert the node to an element.
    if(!domElement.isNull())
    {
      if(domElement.tagName()=="place")
      {
        QString placeName;
        if(!readAttribute<QString>(domElement, QStringLiteral("name"), &placeName, errorMessage))
          return false;

        QUuid placeUuid;
        if(!readAttribute<QUuid>(domElement, QStringLiteral("id"), &placeUuid, errorMessage))
          return false;

        bool initialMarking;
        if(!readAttribute<bool>(domElement, QStringLiteral("initialMarking"), &initialMarking, errorMessage))
          return false;

        PlaceItem* newPlace = declModel->addPlace(placeName);
        Q_ASSERT(newPlace);
        newPlace->setUuid(placeUuid);

        if(initialMarking)
          declModel->addInitPlace(newPlace);
      }
      else if(domElement.tagName()=="transition")
      {
        if(!readTransitionElement(domElement, declModel, errorMessage))
          return false;
      }
      else if(domElement.tagName()=="arc")
      {
        QUuid sourceUuid;
        if(!readAttribute<QUuid>(domElement, QStringLiteral("source_id"), &sourceUuid, errorMessage))
          return false;

        QUuid targetUuid;
        if(!readAttribute<QUuid>(domElement, QStringLiteral("target_id"), &targetUuid, errorMessage))
          return false;

        if(PlaceItem* sourcePlace=declModel->place(sourceUuid))
        {
          TransitionItem* targetTransition=declModel->transition(targetUuid);
          Q_ASSERT(targetTransition);
          targetTransition->addPrePlaceArc(sourcePlace);
        }
        else
        {
          TransitionItem* sourceTranstion=declModel->transition(sourceUuid);
          Q_ASSERT(sourceTranstion);

          PlaceItem* targetPlace=declModel->place(targetUuid);
          Q_ASSERT(targetPlace);

          sourceTranstion->addPostPlaceArc(targetPlace);
        }
      }
    }

    domNode = domNode.nextSibling();
  }

  return true;
}

bool readSpenatElement(const QDomElement& domSpenatElement,
                       SpenatDeclModel* declModel,
                       QString* errorMessage)
{
  Q_ASSERT(declModel);

  QString spenatName;
  if(!readAttribute<QString>(domSpenatElement, QStringLiteral("name"), &spenatName, errorMessage))
    return false;
  declModel->setName(spenatName);

  QDomNode domNode = domSpenatElement.firstChild();
  while(!domNode.isNull())
  {
    QDomElement domElement = domNode.toElement(); // try to convert the node to an element.
    if(!domElement.isNull())
    {
      if(domElement.tagName()=="attribute")
      {
        QString attrName;
        if(!readAttribute<QString>(domElement, QStringLiteral("name"), &attrName, errorMessage))
          return false;

        QString typeName;
        if(!readAttribute<QString>(domElement, QStringLiteral("type"), &typeName, errorMessage))
          return false;

        DataTypeItem* attrDataType=declModel->dataType(typeName);
        if(!attrDataType)
        {
          if(errorMessage)
            *errorMessage+=QObject::tr("data type '%1' for attribute '%2' of spenat '%3' could not be found!")
                           .arg(typeName).arg(attrName).arg(declModel->name());
          return false;
        }

        QString initValueString;
        if(!readAttribute<QString>(domElement, QStringLiteral("initValue"), &initValueString, errorMessage))
          return false;

        AttributeItem* newAttribute=declModel->addAttribute(attrName,attrDataType->name(),
                                                            initValueString,errorMessage);
        if(!newAttribute)
          return false;
      }
      else if(domElement.tagName()=="port")
      {
        QString portName;
        if(!readAttribute<QString>(domElement, QStringLiteral("name"), &portName, errorMessage))
          return false;

        QUuid portUuid;
        if(!readAttribute<QUuid>(domElement, QStringLiteral("uuid"), &portUuid, errorMessage))
          return false;

        PortItem* newPort=declModel->addPort(portName, errorMessage);
        if(!newPort)
          return false;
        newPort->setUuid(portUuid);
      }
      else if(domElement.tagName()=="net")
      {
        bool result=readNetElement(domElement, declModel, errorMessage);
        if(!result)
          return false;
      }
    }

    domNode = domNode.nextSibling();
  }

  return true;
}

bool ComImportXmlSpenat::execute(QString* errorMessage)
{
  Q_ASSERT(this->_d->_declModel);

  if(!QFileInfo(this->_d->_fileName).exists())
  {
    if(errorMessage)
      *errorMessage += tr("File '%1' for xml-spenat does not exist!")
                       .arg(this->_d->_fileName);
    return false;
  }

  ///reset spenat model
  this->_d->_declModel->reset();
  this->_d->_declModel->addDataType(QStringLiteral("int"));
  this->_d->_declModel->addDataType((QStringLiteral("real")));
  this->_d->_declModel->addDataType(QStringLiteral("bool"));

  QDomDocument doc("xml-spenat");
  QFile file(this->_d->_fileName);
  if (!file.open(QIODevice::ReadOnly))
  {
    if(errorMessage)
      *errorMessage += tr("file '%1' could not be opened!")
                       .arg(this->_d->_fileName);
    return false;
  }
  if (!doc.setContent(&file))
  {
    if(errorMessage)
      *errorMessage += tr("error during xml parsing for file '%1'!")
                       .arg(this->_d->_fileName);
    file.close();
    return false;
  }
  file.close();

  QDomElement docElem = doc.documentElement();
  if(docElem.tagName()!="spenat-system")
  {
    if(errorMessage)
      *errorMessage += tr("xml file is not supported, document element must have tag name '%1'")
                       .arg("spenat-system");
    return false;
  }

  this->_d->_declModel->setName(docElem.attribute(QStringLiteral("name")));

  int spenatCount=0;
  QDomNode domNode = docElem.firstChild();
  while(!domNode.isNull())
  {
    QDomElement domElement = domNode.toElement();
    if(!domElement.isNull())
    {
      if(domElement.tagName()=="types")
      {
        bool result=readTypesElement(domElement, this->_d->_declModel,errorMessage);
        if(!result)
          return false;
      }
      else if(domElement.tagName()=="signals")
      {
        bool result = readSignalsElement(domElement, this->_d->_declModel,errorMessage);
        if(!result)
          return false;
      }
      else if(domElement.tagName()=="spenat")
      {
        if(spenatCount)
        {
          if(errorMessage)
            *errorMessage += tr("only one spenat can be imported!");
          return false;
        }

        bool result = readSpenatElement(domElement, this->_d->_declModel,errorMessage);
        if(!result)
          return false;

        ++spenatCount;
      }
      else
      {
        if(errorMessage)
          *errorMessage += tr("xml tag name '%1' is not supported!")
                           .arg(domElement.tagName());
        return false;
      }
    }

    domNode = domNode.nextSibling();
  }

  return true;
}
