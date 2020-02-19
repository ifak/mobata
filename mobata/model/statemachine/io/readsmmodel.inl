#pragma once

#include "../../base/io/readbasemodel.hpp"
#include "../../base/signalitem.hpp"
#include "../../base/portitem.hpp"
#include "../statemachinemodel.hpp"
#include "../abstractstateitem.hpp"
#include "../concurrentstateitem.hpp"
#include "../compositestateitem.hpp"
#include "../junctionstateitem.hpp"
#include "../functors.hpp"

#include <QJsonObject>
#include <QJsonArray>

#include <QObject>

namespace model {
namespace statemachine {
namespace io {

///read objects//////////

template<class StatesModel>
bool readStatesModel(const QJsonObject& jsonObject,
                     StatesModel* statesModel,
                     const QString& arrayKey,
                     QString* errorMessage)
{
  Q_ASSERT(statesModel);

  return readStateMachineArray(jsonObject,
                               statesModel,
                               ReadStatesModel<StatesModel>(),
                               arrayKey,
                               errorMessage);
}

template<class TransitionsModel>
bool readTransitionsModel(const QJsonObject& jsonObject,
                          TransitionsModel* transitionsModel,
                          QString* errorMessage)
{
  Q_ASSERT(transitionsModel);

  return readStateMachineArray(jsonObject,
                               transitionsModel,
                               ReadTransitionsModel<TransitionsModel>(),
                               QStringLiteral("transitions"),
                               errorMessage);
}

template<class JunctionTransitionsModel>
bool readJunctionTransitionsModel(const QJsonObject& jsonObject,
                                  JunctionTransitionsModel* transitionsModel,
                                  QString* errorMessage)
{
  Q_ASSERT(transitionsModel);

  return readStateMachineArray(jsonObject,
                               transitionsModel,
                               ReadJunctionTransitionsModel<JunctionTransitionsModel>(),
                               QStringLiteral("transitions"),
                               errorMessage);
}

template<class RegionsModel>
bool readRegionsModel(const QJsonObject& jsonObject,
                      RegionsModel* regionsModel,
                      QString* errorMessage)
{
  Q_ASSERT(regionsModel);

  return readStateMachineArray(jsonObject,
                               regionsModel,
                               ReadRegionsModel<RegionsModel>(),
                               QStringLiteral("regions"),
                               errorMessage);
}

template<class SmDefaultModel, class ReadSmDefaultFunctor>
bool readStateMachineArray(const QJsonObject& jsonObject,
                           SmDefaultModel* smDefaultModel,
                           ReadSmDefaultFunctor readSmDefaultFunction,
                           const QString& arrayKey,
                           QString* errorMessage)
{
  Q_ASSERT(smDefaultModel);

  QJsonArray jsonArray;
  bool result = base::io::readJsonArray(jsonObject, arrayKey,
                                        &jsonArray, errorMessage);
  if(!result)
    return false;

  foreach(const QJsonValue& jsonValue, jsonArray)
  {
    if(!jsonValue.isObject())
    {
      if(errorMessage)
        *errorMessage += QObject::tr("json value of array '%1' "
                                     "is not a json-object")
                         .arg(arrayKey);
      return false;
    }
    QJsonObject jsonObject=jsonValue.toObject();

    result = readSmDefaultFunction(jsonObject, smDefaultModel, errorMessage);
    if(!result)
      return false;
  }

  return true;
}

template<class StatesModel>
bool readChoiceState(const QJsonObject& jsonObject,
                     StatesModel* statesModel,
                     QString* errorMessage)
{
  Q_ASSERT(statesModel);

  QUuid uuid;
  QString name;
  bool result = base::io::readProperty_2<QUuid,QString>(jsonObject,
                                                        QStringLiteral("uuid"),
                                                        &uuid,
                                                        QStringLiteral("name"),
                                                        &name,
                                                        errorMessage);
  if(!result)
    return false;

  ChoiceStateItem* choiceStateItem = new ChoiceStateItem(name);
  choiceStateItem->setUuid(uuid);
  statesModel->addState(choiceStateItem, errorMessage);

  return true;
}

template<class StatesModel>
bool readCompositeState(const QJsonObject& jsonObject,
                        StatesModel* statesModel,
                        QString* errorMessage)
{
  Q_ASSERT(statesModel);

  QUuid uuid;
  QString name, entryAction, exitAction;
  bool isInit=false;
  bool resultProps = base::io::readProperty_4<QUuid,QString>(jsonObject,
                                                             QStringLiteral("uuid"),
                                                             &uuid,
                                                             QStringLiteral("name"),
                                                             &name,
                                                             QStringLiteral("entryAction"),
                                                             &entryAction,
                                                             QStringLiteral("exitAction"),
                                                             &exitAction,
                                                             errorMessage);

  bool resultInit = base::io::readProperty<bool>(jsonObject,
                                                 QStringLiteral("initState"),
                                                 &isInit,
                                                 errorMessage);
  if(!resultProps || !resultInit)
    return false;




  CompositeStateItem* compositeStateItem = new CompositeStateItem(name);
  compositeStateItem->setUuid(uuid);
  compositeStateItem->setEntryAction(entryAction);
  compositeStateItem->setExitAction(exitAction);
  statesModel->addState(compositeStateItem, errorMessage);
  if(isInit)
    statesModel->setInitState(compositeStateItem, errorMessage);

  readStatesModel(jsonObject,
                  compositeStateItem,
                  QStringLiteral("subStates"),
                  errorMessage);

  return true;
}

template<class StatesModel>
bool readConcurrentState(const QJsonObject& jsonObject,
                         StatesModel* statesModel,
                         QString* errorMessage)
{
  Q_ASSERT(statesModel);

  QUuid uuid;
  QString name, entryAction, exitAction;
  bool isInit=false;
  bool resultProps = base::io::readProperty_4<QUuid,QString, QString, QString>(jsonObject,
                                                                               QStringLiteral("uuid"),
                                                                               &uuid,
                                                                               QStringLiteral("name"),
                                                                               &name,
                                                                               QStringLiteral("entryAction"),
                                                                               &entryAction,
                                                                               QStringLiteral("exitAction"),
                                                                               &exitAction,
                                                                               errorMessage);
  bool resultInit = base::io::readProperty<bool>(jsonObject,
                                                 QStringLiteral("initState"),
                                                 &isInit,
                                                 errorMessage);
  if(!resultProps || !resultInit)
    return false;

  ConcurrentStateItem* concurrentStateItem = new ConcurrentStateItem(name);
  concurrentStateItem->setUuid(uuid);
  concurrentStateItem->setEntryAction(entryAction);
  concurrentStateItem->setExitAction(exitAction);
  statesModel->addState(concurrentStateItem, errorMessage);
  if(isInit)
    statesModel->setInitState(concurrentStateItem, errorMessage);

  readRegionsModel(jsonObject,
                   concurrentStateItem,
                   errorMessage);

  return true;
}

template<class StatesModel>
bool readFinalState(const QJsonObject& jsonObject,
                    StatesModel* statesModel,
                    QString* errorMessage)
{
  Q_ASSERT(statesModel);

  QUuid uuid;
  QString name;
  bool resultProps = base::io::readProperty_2<QUuid,QString>(jsonObject,
                                                             QStringLiteral("uuid"),
                                                             &uuid,
                                                             QStringLiteral("name"),
                                                             &name,
                                                             errorMessage);
  if(!resultProps)
    return false;

  FinalStateItem* finalStateItem = new FinalStateItem(name);
  finalStateItem->setUuid(uuid);
  statesModel->addState(finalStateItem, errorMessage);

  return true;
}

template<class StatesModel>
bool readJunctionState(const QJsonObject& jsonObject,
                       StatesModel* statesModel,
                       QString* errorMessage)
{
  Q_ASSERT(statesModel);

  QUuid uuid;
  QString name;
  bool result = base::io::readProperty_2<QUuid,QString>(jsonObject,
                                                        QStringLiteral("uuid"),
                                                        &uuid,
                                                        QStringLiteral("name"),
                                                        &name,
                                                        errorMessage);
  if(!result)
    return false;

  JunctionStateItem* junctionStateItem = new JunctionStateItem(name);
  junctionStateItem->setUuid(uuid);
  if(jsonObject.value(QStringLiteral("transitions"))!=QJsonValue::Undefined)
  {
    result = readJunctionTransitionsModel(jsonObject, statesModel, errorMessage);
    if(!result)
      return  false;
  }
  statesModel->addState(junctionStateItem, errorMessage);

  return true;
}

template<class StatesModel>
bool readSimpleState(const QJsonObject& jsonObject,
                     StatesModel* statesModel,
                     QString* errorMessage)
{
  Q_ASSERT(statesModel);

  QUuid uuid;
  QString name, entryAction, exitAction;
  bool isInit=false;
  bool resultProps = base::io::readProperty_4<QUuid,QString,QString,QString>(jsonObject,
                                                                             QStringLiteral("uuid"),
                                                                             &uuid,
                                                                             QStringLiteral("name"),
                                                                             &name,
                                                                             QStringLiteral("entryAction"),
                                                                             &entryAction,
                                                                             QStringLiteral("exitAction"),
                                                                             &exitAction,
                                                                             errorMessage);
  bool resultInit = base::io::readProperty<bool>(jsonObject,
                                                 QStringLiteral("initState"),
                                                 &isInit,
                                                 errorMessage);
  if(!resultProps || !resultInit)
    return false;

  SimpleStateItem* simpleStateItem = new SimpleStateItem(name);
  simpleStateItem->setUuid(uuid);
  simpleStateItem->setEntryAction(entryAction);
  simpleStateItem->setExitAction(exitAction);
  statesModel->addState(simpleStateItem, errorMessage);
  if(isInit)
    statesModel->setInitState(simpleStateItem, errorMessage);

  return true;
}

template<class StatesModel>
bool ReadStatesModel<StatesModel>::operator()(const QJsonObject& jsonObject,
                                              StatesModel* statesModel,
                                              QString* errorMessage)
{
  Q_ASSERT(statesModel);

  QString stateType;
  bool result = base::io::readProperty<QString>(jsonObject,
                                                QStringLiteral("type"),
                                                &stateType,
                                                errorMessage);
  if(!result)
    return false;

  if(stateType == "Choice")
  {
    result = readChoiceState<StatesModel>(jsonObject,
                                          statesModel,
                                          errorMessage);
    if(!result)
      return false;
  }
  else if(stateType == "Composite")
  {
    result = readCompositeState<StatesModel>(jsonObject,
                                             statesModel,
                                             errorMessage);
    if(!result)
      return false;
  }
  else if(stateType == "Concurrent")
  {
    result = readConcurrentState<StatesModel>(jsonObject,
                                              statesModel,
                                              errorMessage);
    if(!result)
      return false;
  }
  else if(stateType == "Final")
  {
    result = readFinalState<StatesModel>(jsonObject,
                                         statesModel,
                                         errorMessage);
    if(!result)
      return false;
  }
  else if(stateType == "Junction")
  {
    result = readJunctionState<StatesModel>(jsonObject,
                                            statesModel,
                                            errorMessage);
    if(!result)
      return false;
  }
  else if(stateType == "Simple")
  {
    result = readSimpleState<StatesModel>(jsonObject,
                                          statesModel,
                                          errorMessage);
    if(!result)
      return false;
  }

  return true;
}

template<class TransitionsModel>
bool ReadTransitionsModel<TransitionsModel>::operator()(const QJsonObject& jsonObject,
                                                        TransitionsModel* transitionsModel,
                                                        QString* errorMessage)
{
  Q_ASSERT(transitionsModel);

  QUuid uuid, sourceStateUuid, targetStateUuid, signalUuid, portUuid;
  QString action, guard, name;
  double value = 0.0;

  bool signalResult = base::io::readProperty_2<QUuid, QUuid>(jsonObject,
                                                             QStringLiteral("signal"),
                                                             &signalUuid,
                                                             QStringLiteral("port"),
                                                             &portUuid);

  bool timeoutResult = base::io::readProperty<double>(jsonObject,
                                                      QStringLiteral("value"),
                                                      &value);

  if(signalResult && timeoutResult){
    utils::AddPtrString(errorMessage) << "Transition has elements of type SignalTransitionItem and TimeoutTransitionItem and is therefore invalid!";
    return false;
  }

  if(!signalResult && !timeoutResult){
    utils::AddPtrString(errorMessage) << "Transition has neither elements of type SignalTransitionItem or TimeoutTransitionItem and is therefore invalid!";
    return false;
  }

  bool result = base::io::readProperty_3<QString, QString, QString>(jsonObject,
                                                                    QStringLiteral("name"),
                                                                    &name,
                                                                    QStringLiteral("action"),
                                                                    &action,
                                                                    QStringLiteral("guard"),
                                                                    &guard,
                                                                    errorMessage);
  if(!result)
    return false;

  result = base::io::readProperty_3<QUuid, QUuid, QUuid>(jsonObject,
                                                         QStringLiteral("uuid"),
                                                         &uuid,
                                                         QStringLiteral("sourceState"),
                                                         &sourceStateUuid,
                                                         QStringLiteral("targetState"),
                                                         &targetStateUuid,
                                                         errorMessage);
  if(!result)
    return false;

  AbstractStateItem const* sourceState = statesRecursiveByUuid(transitionsModel, sourceStateUuid);
  AbstractStateItem const* targetState = statesRecursiveByUuid(transitionsModel, targetStateUuid);

  if(sourceState == nullptr || targetState == nullptr){
    utils::AddPtrString(errorMessage) << "Transition has invalid SourceState or TargetState!";
    return false;
  }

  TransitionItem* transitionItem;

  if(signalResult){
    SignalItem* signalItem = transitionsModel->signal(signalUuid);
    PortItem* portItem = transitionsModel->portById(portUuid);
    if(!signalItem || !portItem)
      return false;

    transitionItem = transitionsModel->addSignalTransition(name,
                                                           signalItem,
                                                           portItem,
                                                           sourceState,
                                                           targetState,
                                                           guard,
                                                           action,
                                                           uuid,
                                                           errorMessage);
  }
  else if(timeoutResult){
    transitionItem = transitionsModel->addTimeoutTransition(name,
                                                            value,
                                                            sourceState,
                                                            targetState,
                                                            guard,
                                                            action,
                                                            uuid,
                                                            errorMessage);
  }
  else{
    utils::AddPtrString(errorMessage) << "Transition has no trigger!";
    return false;
  }

  Q_ASSERT(transitionItem);

  return true;
}

template<class TransitionsModel>
bool ReadJunctionTransitionsModel<TransitionsModel>::operator()(const QJsonObject& jsonObject,
                                                                TransitionsModel* transitionsModel,
                                                                QString* errorMessage)
{
  Q_ASSERT(transitionsModel);

  QUuid uuid, sourceStateUuid, targetStateUuid;
  QString action, guard, name;

  bool result = base::io::readProperty_3<QString, QString, QString>(jsonObject,
                                                                    QStringLiteral("action"),
                                                                    &action,
                                                                    QStringLiteral("guard"),
                                                                    &guard,
                                                                    QStringLiteral("name"),
                                                                    &name,
                                                                    errorMessage);
  if(!result)
    return false;

  result = base::io::readProperty_3<QUuid, QUuid, QUuid>(jsonObject,
                                                         QStringLiteral("uuid"),
                                                         &uuid,
                                                         QStringLiteral("sourceState"),
                                                         &sourceStateUuid,
                                                         QStringLiteral("targetState"),
                                                         &targetStateUuid,
                                                         errorMessage);
  if(!result)
    return false;

  AbstractStateItem* sourceState = statesRecursiveByUuid(transitionsModel, sourceStateUuid);
  AbstractStateItem const* targetState = statesRecursiveByUuid(transitionsModel, targetStateUuid);

  if(sourceState == nullptr || targetState == nullptr || sourceState->stateType() != Junction){
    utils::AddPtrString(errorMessage) << "Transition has invalid SourceState or TargetState!";
    return false;
  }

  JunctionStateItem* junction = static_cast<JunctionStateItem*>(sourceState);
  Q_ASSERT(junction);

  TransitionItem* transitionItem = junction->addJunctionTransition(name,
                                                                   targetState,
                                                                   guard,
                                                                   action,
                                                                   uuid,
                                                                   errorMessage);
  Q_ASSERT(transitionItem);

  return true;
}

template<class RegionsModel>
bool ReadRegionsModel<RegionsModel>::operator()(const QJsonObject& jsonObject,
                                                RegionsModel* regionsModel,
                                                QString* errorMessage)
{
  Q_ASSERT(regionsModel);

  QUuid uuid;
  QString name;
  bool result = base::io::readProperty_2<QUuid,QString>(jsonObject,
                                                        QStringLiteral("uuid"),
                                                        &uuid,
                                                        QStringLiteral("name"),
                                                        &name,
                                                        errorMessage);
  if(!result)
    return false;

  RegionItem* regionItem = new RegionItem(name);
  regionItem->setUuid(uuid);

  //has params?///
  if(jsonObject.value(QStringLiteral("regionStates")) != QJsonValue::Undefined)
  {
    result = readStatesModel(jsonObject,
                             regionItem,
                             QStringLiteral("regionStates"),
                             errorMessage);
    if(!result)
      return false;
  }

  regionsModel->addRegion(regionItem, errorMessage);

  return true;
}

} // namespace io
} // namespace base
} // namespace model
