/*
 * This file is part of mobata.
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
#ifndef MODEL_MSC_IO_READXMLMSCMODEL_HPP
#define MODEL_MSC_IO_READXMLMSCMODEL_HPP

#include <QXmlStreamReader>
#include <QString>

#include "../../base/io/readxmlbasemodel.hpp"

#include "../msccheckmessageitem.hpp"
#include "../mscfragmentitem.hpp"
#include "../mscfragmentregionitem.hpp"

#include <QDebug>

namespace model{
namespace msc{
namespace io{

template<class CompItemType, class ComponentsItem>
bool readXmlComponents(QXmlStreamReader* xmlStreamReader,
                       ComponentsItem* componentsItem,
                       QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(componentsItem);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name() == QStringLiteral("components"));

  while (xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("component"))
    {
      QString compName;
      if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                          QStringLiteral("name"),
                                                          &compName,
                                                          errorMessage))
        return false;

      QUuid compUuid;
      if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                        QStringLiteral("uuid"),
                                                        &compUuid,
                                                        errorMessage))
        return false;

      CompItemType* newComponent = new CompItemType(compName);
      bool result = componentsItem->addComponent(newComponent, errorMessage);
      if(!result)
      {
        qWarning()<<"error during component creation: "<<errorMessage;
        delete newComponent;
        newComponent=nullptr;
        return false;
      }

      newComponent->setUuid(compUuid);

      while (xmlStreamReader->readNextStartElement())
      {
        if(xmlStreamReader->name() == QStringLiteral("ports"))
        {
          bool result = base::io::readXmlPorts(xmlStreamReader, newComponent, errorMessage);
          if(!result)
            return false;
        }
      }
    }
  }

  return true;
}

template<class MessageType>
bool readXmlMessageParameter(QXmlStreamReader* xmlStreamReader,
                             MessageType* messageItem,
                             QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(messageItem);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name()==QStringLiteral("parameter"));

  while(xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("param"))
    {
      QString paramName;
      if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                          QStringLiteral("name"),
                                                          &paramName, errorMessage))
        return false;

      QString paramValue;
      if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                          QStringLiteral("value"),
                                                          &paramValue, errorMessage))
        return false;

      SignalItem const* messageSignal = messageItem->signal();
      if(!messageSignal)
      {
        if(errorMessage)
          *errorMessage += QObject::tr("message signal for message '%1' not found!")
                           .arg(messageItem->toString());
        return false;
      }

      ParamItem const* paramItem = messageSignal->parameter(paramName);
      if(!paramItem)
      {
        if(errorMessage)
          *errorMessage+=QObject::tr("parameter '%1' of param-owner '%2' "
                                     "of param-value '%3' not found!")
                         .arg(paramName)
                         .arg(messageSignal->toString())
                         .arg(paramValue);
        return false;
      }

      ParamValueItem* newParamValue=messageItem->addParamValue(paramItem,
                                                               paramValue);
      Q_ASSERT(newParamValue);
      xmlStreamReader->skipCurrentElement();
    }
    else
      xmlStreamReader->skipCurrentElement();
  }

  return true;
}

template<class MessageType>
bool readXmlMessageCoverages(QXmlStreamReader* xmlStreamReader,
                             MessageType* messageItem,
                             QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(messageItem);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name()==QStringLiteral("coverages"));

  while(xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("coverageItem"))
    {
      QString coverageName;
      if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                          QStringLiteral("name"),
                                                          &coverageName, errorMessage))
        return false;

      QUuid coverageItemUuid;
      if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                        QStringLiteral("uuid"),
                                                        &coverageItemUuid, errorMessage))
        return false;

      QString coverageItemType;
      if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                          QStringLiteral("type"),
                                                          &coverageItemType, errorMessage))
        return false;

      MscCoverageType mscCoverageType = string2coverageType(coverageItemType);
      messageItem->addCoverageItem(coverageName, coverageItemUuid, mscCoverageType);
      xmlStreamReader->skipCurrentElement();
    }
    else
      xmlStreamReader->skipCurrentElement();
  }

  return true;
}

template<class SystemModel, class SequenceType>
bool readXmlMessage(QXmlStreamReader* xmlStreamReader,
                    SystemModel* systemModel,
                    SequenceType* sequence,
                    QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(sequence);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name()==QStringLiteral("message"));

  QUuid signalUuid;
  if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                    QStringLiteral("signal_ID"),
                                                    &signalUuid, errorMessage))
    return false;

  QUuid sourcePortUuid;
  if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                    QStringLiteral("from_port_ID"),
                                                    &sourcePortUuid, errorMessage))
    return false;

  QUuid targetPortUuid;
  if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                    QStringLiteral("to_port_ID"),
                                                    &targetPortUuid, errorMessage))
    return false;

  PortItem const* sourcePort = systemModel->port(sourcePortUuid);
  if(!sourcePort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("source port with id '%1' of model '%2' not found!")
                       .arg(sourcePortUuid.toString()).arg(systemModel->name());
    return false;
  }

  PortItem const* targetPort = systemModel->port(targetPortUuid);
  if(!targetPort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("target port with id '%1' of model '%2' not found!")
                       .arg(targetPortUuid.toString()).arg(systemModel->name());
    return false;
  }

  MscMessageItem* messageItem=sequence->addMessage(sourcePort, targetPort);
  Q_ASSERT(messageItem);

  if(!signalUuid.isNull())
  {
    SignalItem* messageSignal=systemModel->signal(signalUuid);
    if(!messageSignal)
    {
      if(errorMessage)
        *errorMessage += QObject::tr("signal with id '%1' not found!")
                         .arg(signalUuid.toString());
      return false;
    }
    messageItem->setSignal(messageSignal);
  }

  QUuid referenceUuid;
  if(base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                   QStringLiteral("reference"),
                                                   &referenceUuid, errorMessage))
    messageItem->setReferenceId(referenceUuid);///optional

  while(xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("parameter"))
    {
      bool result = readXmlMessageParameter(xmlStreamReader,
                                            messageItem,
                                            errorMessage);
      if(!result)
        return false;
    }
    else if(xmlStreamReader->name() == QStringLiteral("coverages"))
    {
      bool result = readXmlMessageCoverages(xmlStreamReader,
                                            messageItem,
                                            errorMessage);
      if(!result)
        return false;
    }
    else
      xmlStreamReader->skipCurrentElement();
  }

  messageItem->setText(messageItem->toString(true));

  return true;
}

template<class SystemModel, class SequenceType>
bool readXmlTimer(QXmlStreamReader* xmlStreamReader,
                  SystemModel* systemModel,
                  SequenceType* sequence,
                  QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(sequence);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name()==QStringLiteral("timer"));

  double timerValue;
  if(!base::io::readXmlStreamReaderAttribute<double>(*xmlStreamReader,
                                                     QStringLiteral("value"),
                                                     &timerValue, errorMessage))
    return false;

  QUuid portUuid;
  if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                    QStringLiteral("port_ID"),
                                                    &portUuid, errorMessage))
    return false;

  PortItem const* timerPort = systemModel->port(portUuid);
  if(!timerPort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("port with id '%1' of timer 'after %2ms' not found!")
                       .arg(portUuid.toString()).arg(timerValue);
    return false;
  }

  if(timerPort->ownerType()!=PortItem::Component)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("owner of port '%1' is not a component!")
                       .arg(timerPort->name());
    return false;
  }

  MscComponentItem const* portComponent=utils::simple_cast<MscComponentItem const*>(timerPort->owner());
  Q_ASSERT(portComponent);
  MscSleepTimerItem* timerItem = sequence->addSleepTimer(portComponent, timerValue);
  Q_ASSERT(timerItem);

  xmlStreamReader->skipCurrentElement();

  return true;
}

template<class SystemModel, class SequenceType>
bool readXmlStatement(QXmlStreamReader* xmlStreamReader,
                      SystemModel* systemModel,
                      SequenceType* sequence,
                      QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(sequence);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name()==QStringLiteral("statement"));

  QString statementValue;
  if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                      QStringLiteral("value"),
                                                      &statementValue, errorMessage))
    return false;

  QUuid portUuid;
  if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                    QStringLiteral("port_ID"),
                                                    &portUuid, errorMessage))
    return false;

  PortItem const* statementPort = systemModel->port(portUuid);
  if(!statementPort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("port with id '%1' of statement '%2' not found!")
                       .arg(portUuid.toString()).arg(statementValue);
    return false;
  }

  if(statementPort->ownerType()!=PortItem::Component)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("owner of port '%1' is not a component!")
                       .arg(statementPort->name());
    return false;
  }

  MscComponentItem const* portComponent=utils::simple_cast<MscComponentItem const*>(statementPort->owner());
  Q_ASSERT(portComponent);
  MscStatementItem* statementItem = sequence->addStatement(portComponent,
                                                           statementValue);
  Q_ASSERT(statementItem);

  xmlStreamReader->skipCurrentElement();

  return true;
}

template<class SystemModel, class SequenceType>
bool readXmlSequence(QXmlStreamReader* xmlStreamReader,
                     SystemModel* systemModel,
                     SequenceType* sequence,
                     QString* errorMessage);

template<class SystemModel, class SequenceType>
bool readXmlFragment(QXmlStreamReader* xmlStreamReader,
                     SystemModel* systemModel,
                     SequenceType* sequence,
                     QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(sequence);
  Q_ASSERT(xmlStreamReader->isStartElement()
           && xmlStreamReader->name()==QStringLiteral("fragment"));

  QString fragmentType;
  if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                      QStringLiteral("operator"),
                                                      &fragmentType, errorMessage))
    return false;

  MscFragmentItem* newFragmentItem = 0;
  if(fragmentType == QStringLiteral("loop"))
    newFragmentItem = sequence->addFragment(LoopFragment);
  else if(fragmentType == QStringLiteral("alt"))
    newFragmentItem = sequence->addFragment(AlternativeFragment);
  else if(fragmentType == QStringLiteral("par"))
    newFragmentItem = sequence->addFragment(ParallelFragment);
  else
  {
    if(errorMessage)
      *errorMessage += QObject::tr("fragment type '%1' is currently not supported!")
                       .arg(fragmentType);
    return false;
  }
  Q_ASSERT(newFragmentItem);

  while(xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("region"))
    {
      QString conditionString(QStringLiteral(""));
      base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                      QStringLiteral("condition"),
                                                      &conditionString, errorMessage);
      MscFragmentRegionItem* newRegionItem = newFragmentItem->addRegion(conditionString);
      Q_ASSERT(newRegionItem);
      if(!readXmlSequence(xmlStreamReader, systemModel, newRegionItem, errorMessage))
        return false;
    }
    else
      xmlStreamReader->skipCurrentElement();
  }

  return true;
}

template<class SystemModel, class SequenceType>
bool readXmlSequence(QXmlStreamReader* xmlStreamReader,
                     SystemModel* systemModel,
                     SequenceType* sequence,
                     QString* errorMessage)
{
  Q_ASSERT(xmlStreamReader);
  Q_ASSERT(systemModel);
  Q_ASSERT(sequence);

  QString sequName;
  if(!base::io::readXmlStreamReaderAttribute<QString>(*xmlStreamReader,
                                                      QStringLiteral("name"),
                                                      &sequName,
                                                      errorMessage))
    return false;
  sequence->setName(sequName);

  QUuid sequUuid;
  if(!base::io::readXmlStreamReaderAttribute<QUuid>(*xmlStreamReader,
                                                    QStringLiteral("uuid"),
                                                    &sequUuid,
                                                    errorMessage))
    return false;
  sequence->setUuid(sequUuid);

  while (xmlStreamReader->readNextStartElement())
  {
    if(xmlStreamReader->name() == QStringLiteral("message"))
    {
      if(!readXmlMessage(xmlStreamReader, systemModel, sequence, errorMessage))
        return false;
    }
    else if(xmlStreamReader->name() == QStringLiteral("timer"))
    {
      if(!readXmlTimer(xmlStreamReader, systemModel, sequence, errorMessage))
        return false;
    }
    else if(xmlStreamReader->name() == QStringLiteral("statement"))
    {
      if(!readXmlStatement(xmlStreamReader, systemModel, sequence, errorMessage))
        return false;
    }
    else if(xmlStreamReader->name() == QStringLiteral("fragment"))
    {
      if(!readXmlFragment(xmlStreamReader, systemModel, sequence, errorMessage))
        return false;
    }
    else
      xmlStreamReader->skipCurrentElement();
  }

  return true;
}

} /// namespace io
} /// namespace msc
} /// namespace model

#endif // MODEL_MSC_IO_READXMLMSCMODEL_HPP
