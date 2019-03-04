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

#include "../../base/io/readbasemodel.hpp"

#include "../msccomponentitem.hpp"
#include "../mscsequence.hpp"
#include "../msccheckmessageitem.hpp"
#include "../mscstatementitem.hpp"
#include "../msctimeoutitem.hpp"
#include "../msctimeritem.hpp"
#include "../mscsleeptimeritem.hpp"
#include "../mscfragmentitem.hpp"
#include "../mscfragmentregionitem.hpp"

#include <QJsonObject>
#include <QJsonArray>

#include <QObject>

namespace model {
namespace msc {
namespace io {

///read objects//////////

template<class MscComponentsModel>
bool ReadMscComponent<MscComponentsModel>::operator()(const QJsonObject& jsonObject,
                                                      MscComponentsModel* mscComponentsModel,
                                                      QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscComponentsModel);

  QUuid uuid;
  QString name;
  QUuid defaultPortUuid;
  bool result = readProperty_3<QUuid,QString, QUuid>(jsonObject,
                                              QStringLiteral("uuid"),
                                              &uuid,
                                              QStringLiteral("name"),
                                              &name,
                                              QStringLiteral("defaultPort"),
                                              &defaultPortUuid,
                                              errorMessage);
  if(!result)
    return false;

  MscComponentItem* newMscComponent = new MscComponentItem(name);
  newMscComponent->setUuid(uuid);
  PortItem* portItem = const_cast<PortItem*>(newMscComponent->defaultPort());
  portItem->setUuid(defaultPortUuid);

  result = mscComponentsModel->addComponent(newMscComponent, errorMessage);
  if(!result)
  {
    delete newMscComponent;
    return false;
  }

  return true;
}

template<class MscSequencseModel>
bool readMscSequences(const QJsonObject& jsonObject,
                      MscSequencseModel* mscSequenceModel,
                      QString* errorMessage)
{
  Q_ASSERT(mscSequenceModel);

  return readMscSequences(jsonObject,
                          mscSequenceModel,
                          ReadMscSequence<MscSequencseModel>(),
                          errorMessage);
}

template<class MscSequencseModel, class ReadMscSequenceFunctor>
bool readMscSequences(const QJsonObject& jsonObject,
                      MscSequencseModel* mscSequenceModel,
                      ReadMscSequenceFunctor readMscSequenceFunctor,
                      QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscSequenceModel);

  return readObjectArray(jsonObject, QStringLiteral("sequences"),
                         mscSequenceModel, readMscSequenceFunctor,
                         errorMessage);
}

template<class MscSequencseModel>
bool ReadMscSequence<MscSequencseModel>::operator()(const QJsonObject& jsonObject,
                                                    MscSequencseModel* sequenceModel,
                                                    QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(sequenceModel);

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

  MscSequence* newMscSequence = sequenceModel->addSequence(name);
  if(!newMscSequence)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("sequence '%1' could not be added to model '%2'!")
                       .arg(name).arg(sequenceModel->name());
    return false;
  }
  newMscSequence->setUuid(uuid);

  if(jsonObject.value(QStringLiteral("steps"))!=QJsonValue::Undefined)
  {
    result = readMscSteps(jsonObject, sequenceModel, newMscSequence, errorMessage);
    if(!result)
      return  false;
  }

  return true;
}

template<class SystemModel, class MscStepsModel>
bool readMscSteps(const QJsonObject& jsonObject,
                  SystemModel* systemModel,
                  MscStepsModel* mscStepsModel,
                  QString* errorMessage)
{
  Q_ASSERT(mscStepsModel);

  return readMscSteps(jsonObject,
                      mscStepsModel,
                      ReadMscStep<SystemModel,MscStepsModel>(systemModel),
                      errorMessage);
}

template<class MscStepsModel, class ReadMscStepFunctor>
bool readMscSteps(const QJsonObject& jsonObject,
                  MscStepsModel* mscStepsModel,
                  ReadMscStepFunctor readMscStepFunctor,
                  QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);

  return readObjectArray(jsonObject, QStringLiteral("steps"),
                         mscStepsModel, readMscStepFunctor,
                         errorMessage);
}

template<class SystemModel, class MscStepsModel>
bool ReadMscStep<SystemModel,MscStepsModel>::operator()(const QJsonObject& jsonObject,
                                                        MscStepsModel* mscStepsModel,
                                                        QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);

  QString stepType;
  bool result = readProperty<QString>(jsonObject,
                                      QStringLiteral("stepType"),
                                      &stepType,
                                      errorMessage);
  if(!result)
    return false;

  if(stepType==constants::MessageStepId)
  {
    result = ReadMessageStep<SystemModel, MscStepsModel>(this->_systemModel)(jsonObject,
                                                                             mscStepsModel,
                                                                             errorMessage);
    if(!result)
      return false;
  }
  else if(stepType==constants::CheckMessageStepId)
  {
    result = ReadCheckMessageStep<SystemModel, MscStepsModel>(this->_systemModel)(jsonObject,
                                                                                  mscStepsModel,
                                                                                  errorMessage);
    if(!result)
      return false;
  }
  else if(stepType==constants::StatementStepId)
  {
    result = ReadStatementStep<SystemModel, MscStepsModel>(this->_systemModel)(jsonObject,
                                                                               mscStepsModel,
                                                                               errorMessage);
    if(!result)
      return false;
  }
  else if(stepType==constants::TimeoutStepId)
  {
    result = ReadTimeoutStep<SystemModel, MscStepsModel>(this->_systemModel)(jsonObject,
                                                                             mscStepsModel,
                                                                             errorMessage);
    if(!result)
      return false;
  }
  else if(stepType==constants::TimerStepId)
  {
    result = ReadTimerStep<SystemModel, MscStepsModel>(this->_systemModel)(jsonObject,
                                                                           mscStepsModel,
                                                                           errorMessage);
    if(!result)
      return false;
  }
  else if(stepType==constants::FragmentStepId)
  {
    result = ReadFragmentStep<SystemModel, MscStepsModel>(this->_systemModel)(jsonObject,
                                                                           mscStepsModel,
                                                                           errorMessage);
    if(!result)
      return false;
  }

  return true;
}

template<class SystemModel, class MscStepsModel>
bool ReadMessageStep<SystemModel, MscStepsModel>::operator()(const QJsonObject& jsonObject,
                                                             MscStepsModel* mscStepsModel,
                                                             QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);
  Q_ASSERT(this->_systemModel);

  QUuid uuid;
  QUuid sourcePortUuid;
  QUuid targetPortUuid;
  bool result = readProperty_3<QUuid,QUuid,QUuid>(jsonObject,
                                                  QStringLiteral("uuid"),
                                                  &uuid,
                                                  QStringLiteral("sourcePort"),
                                                  &sourcePortUuid,
                                                  QStringLiteral("targetPort"),
                                                  &targetPortUuid,
                                                  errorMessage);
  if(!result)
    return false;

  PortItem const* sourcePort = this->_systemModel->port(sourcePortUuid);
  if(!sourcePort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("source port with id '%1' for message with id '%2' not found!")
                       .arg(sourcePortUuid.toString()).arg(uuid.toString());
    return false;
  }

  PortItem const* targetPort = this->_systemModel->port(targetPortUuid);
  if(!targetPort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("target port with id '%1' for message with id '%2' not found!")
                       .arg(targetPortUuid.toString()).arg(uuid.toString());
    return false;
  }

  QString messageText(QStringLiteral(""));
  readProperty<QString>(jsonObject, QStringLiteral("text"),&messageText);///optional

  MscMessageItem* newMessage = new MscMessageItem(sourcePort, targetPort, messageText);
  newMessage->setUuid(uuid);

  ///optional referenceId///////
  QUuid referenceId;
  result=readProperty<QUuid>(jsonObject, QStringLiteral("referenceId"), &referenceId);
  if(result)
    newMessage->setReferenceId(referenceId);

  ///optional signal + param values///////
  QUuid signalId;
  result=readProperty<QUuid>(jsonObject, QStringLiteral("signal"), &signalId);
  if(result)
  {
    SignalItem const* messageSignal=this->_systemModel->signal(signalId);
    if(!messageSignal)
    {
      if(errorMessage)
        *errorMessage += QObject::tr("signal with id '%1' for message with id '%2' not found!")
                         .arg(signalId.toString()).arg(uuid.toString());
      return false;
    }
    newMessage->setSignal(messageSignal);

    ///optional param values///////
    if(jsonObject.value(QStringLiteral("paramValues"))!=QJsonValue::Undefined)
    {//available
      result=readParamValues(jsonObject,
                             newMessage,
                             ReadParamValue<SignalItem,MscMessageItem>(messageSignal),
                             errorMessage);
      if(!result)
        return false;
    }
  }

  mscStepsModel->addMessage(newMessage);

  return true;
}

template<class SystemModel, class MscStepsModel>
bool ReadCheckMessageStep<SystemModel, MscStepsModel>::operator()(const QJsonObject& jsonObject,
                                                                  MscStepsModel* mscStepsModel,
                                                                  QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);
  Q_ASSERT(this->_systemModel);

  QUuid uuid;
  QUuid sourcePortUuid;
  QUuid targetPortUuid;
  QString guard;
  bool result = readProperty_4<QUuid,QUuid,QUuid,QString>(jsonObject,
                                                          QStringLiteral("uuid"),
                                                          &uuid,
                                                          QStringLiteral("sourcePort"),
                                                          &sourcePortUuid,
                                                          QStringLiteral("targetPort"),
                                                          &targetPortUuid,
                                                          QStringLiteral("guard"),
                                                          &guard,
                                                          errorMessage);
  if(!result)
    return false;

  PortItem const* sourcePort = this->_systemModel->port(sourcePortUuid);
  if(!sourcePort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("source port with id '%1' for message with id '%2' not found!")
                       .arg(sourcePortUuid.toString()).arg(uuid.toString());
    return false;
  }

  PortItem const* targetPort = this->_systemModel->port(targetPortUuid);
  if(!targetPort)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("target port with id '%1' for message with id '%2' not found!")
                       .arg(targetPortUuid.toString()).arg(uuid.toString());
    return false;
  }

  MscCheckMessageItem* newCheckMessage = new MscCheckMessageItem(sourcePort,
                                                                 targetPort,
                                                                 guard);
  newCheckMessage->setUuid(uuid);

  ///optional text///////////
  QString messageText(QStringLiteral(""));
  result=readProperty<QString>(jsonObject, QStringLiteral("text"),&messageText);
  if(result)
    newCheckMessage->setText(messageText);

  ///optional referenceId///////
  QUuid referenceId;
  result=readProperty<QUuid>(jsonObject, QStringLiteral("referenceId"), &referenceId);
  if(result)
    newCheckMessage->setReferenceId(referenceId);

  ///optional signal + param values///////
  QUuid signalId;
  result=readProperty<QUuid>(jsonObject, QStringLiteral("signal"), &signalId);
  if(result)
  {
    SignalItem const* messageSignal=this->_systemModel->signal(signalId);
    if(!messageSignal)
    {
      if(errorMessage)
        *errorMessage += QObject::tr("signal with id '%1' for message with id '%2' not found!")
                         .arg(signalId.toString()).arg(uuid.toString());
      return false;
    }
    newCheckMessage->setSignal(messageSignal);

    ///optional param values///////
    if(jsonObject.value(QStringLiteral("paramValues"))!=QJsonValue::Undefined)
    {//available
      result=readParamValues(jsonObject,
                             newCheckMessage,
                             ReadParamValue<SignalItem,MscMessageItem>(messageSignal),
                             errorMessage);
      if(!result)
        return false;
    }
  }

  mscStepsModel->addMessage(newCheckMessage);

  return true;
}

template<class SystemModel, class MscStepsModel>
bool ReadStatementStep<SystemModel, MscStepsModel>::operator()(const QJsonObject& jsonObject,
                                                               MscStepsModel* mscStepsModel,
                                                               QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);
  Q_ASSERT(this->_systemModel);

  QUuid uuid;
  QUuid componentUuid;
  QString statement;
  bool result = readProperty_3<QUuid,QUuid,QString>(jsonObject,
                                                    QStringLiteral("uuid"),
                                                    &uuid,
                                                    QStringLiteral("component"),
                                                    &componentUuid,
                                                    QStringLiteral("statement"),
                                                    &statement,
                                                    errorMessage);
  if(!result)
    return false;

  MscComponentItem const* componentItem = this->_systemModel->component(componentUuid);
  if(!componentItem)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("component with id '%1' for statement step with id '%2' not found!")
                       .arg(componentUuid.toString()).arg(uuid.toString());
    return false;
  }

  MscStatementItem* newStatement = mscStepsModel->addStatement(componentItem, statement);
  Q_ASSERT(newStatement);
  newStatement->setUuid(uuid);

  return true;
}

template<class SystemModel, class MscStepsModel>
bool ReadTimeoutStep<SystemModel, MscStepsModel>::operator()(const QJsonObject& jsonObject,
                                                             MscStepsModel* mscStepsModel,
                                                             QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);
  Q_ASSERT(this->_systemModel);

  QUuid uuid;
  QUuid componentUuid;
  QUuid timerUuid;
  bool result = readProperty_3<QUuid,QUuid,QUuid>(jsonObject,
                                                  QStringLiteral("uuid"),
                                                  &uuid,
                                                  QStringLiteral("component"),
                                                  &componentUuid,
                                                  QStringLiteral("timer"),
                                                  &timerUuid,
                                                  errorMessage);
  if(!result)
    return false;

  MscComponentItem const* componentItem = this->_systemModel->component(componentUuid);
  if(!componentItem)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("component with id '%1' for timeout step with id '%2' not found!")
                       .arg(componentUuid.toString()).arg(uuid.toString());
    return false;
  }

  MscTimerItem const* timerItem = mscStepsModel->timer(timerUuid);
  if(!timerItem)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("timer with id '%1' for timeout step with id '%2' not found!")
                       .arg(timerUuid.toString()).arg(uuid.toString());
    return false;
  }

  MscTimeoutItem* newTimeout = mscStepsModel->addTimeout(componentItem,
                                                         timerItem);
  Q_ASSERT(newTimeout);
  newTimeout->setUuid(uuid);

  return true;
}

template<class SystemModel, class MscStepsModel>
bool ReadTimerStep<SystemModel, MscStepsModel>::operator()(const QJsonObject& jsonObject,
                                                           MscStepsModel* mscStepsModel,
                                                           QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);
  Q_ASSERT(this->_systemModel);

  QUuid uuid;
  QUuid componentUuid;
  QString name;
  double value = 0.0;
  bool result = readProperty_4<QUuid,QUuid,QString,double>(jsonObject,
                                                           QStringLiteral("uuid"),
                                                           &uuid,
                                                           QStringLiteral("component"),
                                                           &componentUuid,
                                                           QStringLiteral("name"),
                                                           &name,
                                                           QStringLiteral("value"),
                                                           &value,
                                                           errorMessage);
  if(!result)
    return false;

  MscComponentItem const* componentItem = this->_systemModel->component(componentUuid);
  if(!componentItem)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("component with id '%1' for timer step with id '%2' not found!")
                       .arg(componentUuid.toString()).arg(uuid.toString());
    return false;
  }

  MscTimerItem* newTimer = mscStepsModel->addTimer(componentItem, name, errorMessage);
  if(!newTimer)
    return false;

  newTimer->setUuid(uuid);
  newTimer->setValue(value);

  return true;
}

template<class SystemModel, class MscStepsModel>
bool ReadFragmentStep<SystemModel, MscStepsModel>::operator()(const QJsonObject& jsonObject,
                                                           MscStepsModel* mscStepsModel,
                                                           QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscStepsModel);
  Q_ASSERT(this->_systemModel);

  QUuid uuid;
  QString fragmentType;
  QString duration;
  bool result = readProperty_3<QUuid,QString,QString>(jsonObject,
                                                           QStringLiteral("uuid"),
                                                           &uuid,
                                                           QStringLiteral("fragmentType"),
                                                           &fragmentType,
                                                           QStringLiteral("duration"),
                                                           &duration,
                                                           errorMessage);
  if(!result)
    return false;

  int intFragmentType = string2fragmentType(fragmentType);
  MscFragmentItem* newFragment = nullptr;
  if(intFragmentType==FragmentType::AlternativeFragment)
  {
      newFragment = mscStepsModel->addFragment(FragmentType::AlternativeFragment);
      if(!newFragment)
        return false;
  }
  else if(intFragmentType==FragmentType::DurationFragment)
  {
      newFragment = mscStepsModel->addFragment(FragmentType::DurationFragment);
      if(!newFragment)
        return false;
  }
  else
  {
    if(errorMessage)
      *errorMessage += QObject::tr("fragment '%1' not supported!")
                       .arg(fragmentType);
    return false;
  }

  newFragment->setUuid(uuid);
  newFragment->setDuration(duration.toUInt());

  if(jsonObject.value(QStringLiteral("regions"))!=QJsonValue::Undefined)
  {
    result = readMscRegions(jsonObject, this->_systemModel, newFragment, errorMessage);
    if(!result)
      return  false;
  }

  return true;
}

template<class SystemModel, class MscFragmentModel>
bool readMscRegions(const QJsonObject& jsonObject,
                  SystemModel* systemModel,
                  MscFragmentModel* mscFragmentModel,
                  QString* errorMessage)
{
  Q_ASSERT(mscFragmentModel);

  return readMscRegions(jsonObject,
                      mscFragmentModel,
                      ReadFragmentRegion<SystemModel, MscFragmentModel>(systemModel),
                      errorMessage);
}

template<class MscRegionsModel, class ReadMscRegionFunctor>
bool readMscRegions(const QJsonObject& jsonObject,
                      MscRegionsModel* mscRegionsModel,
                      ReadMscRegionFunctor readMscRegionFunctor,
                      QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscRegionsModel);

  return readObjectArray(jsonObject, QStringLiteral("regions"),
                         mscRegionsModel, readMscRegionFunctor,
                         errorMessage);
}


template<class SystemModel, class MscFragmentModel>
bool ReadFragmentRegion<SystemModel, MscFragmentModel>::operator()(const QJsonObject& jsonObject,
                                                    MscFragmentModel* mscFragmentModel,
                                                    QString* errorMessage)
{
  using namespace base::io;

  Q_ASSERT(mscFragmentModel);
  Q_ASSERT(this->_systemModel);

  QUuid uuid;
  QString name;
  QString condition;
  bool result = readProperty_3<QUuid,QString, QString>(jsonObject,
                                              QStringLiteral("uuid"),
                                              &uuid,
                                              QStringLiteral("name"),
                                              &name,
                                              QStringLiteral("condition"),
                                              &condition,
                                              errorMessage);
  if(!result)
    return false;

  MscFragmentRegionItem* newMscFragmentRegion = mscFragmentModel->addRegion(name);
  if(!newMscFragmentRegion)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("fragment region '%1' could not be added to fragment '%2'!")
                       .arg(name).arg(fragmentType2string(mscFragmentModel->fragmentType()));
    return false;
  }
  newMscFragmentRegion->setUuid(uuid);
  newMscFragmentRegion->setCondition(condition);

  if(jsonObject.value(QStringLiteral("steps"))!=QJsonValue::Undefined)
  {
    result = readMscSteps(jsonObject, this->_systemModel, newMscFragmentRegion, errorMessage);
    if(!result)
      return  false;
  }

  return true;
}

} // namespace io
} // namespace msc
} // namespace model
