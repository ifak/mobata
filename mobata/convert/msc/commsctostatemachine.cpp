#include "model/statemachine/statemachinemodel.hpp"
#include "model/statemachine/simplestateitem.hpp"
#include "model/statemachine/transitionitem.hpp"
#include "model/statemachine/types.hpp"
#include "model/base/signalitem.hpp"
#include "model/base/datatypeitem.hpp"
#include "model/base/signaltriggeritem.hpp"

#include "commsctostatemachine.hpp"

#include <QDebug>

using namespace convert::msc;
using namespace model::statemachine;
using namespace model::msc;
using namespace model::base;

ComMscToStatemachine::ComMscToStatemachine()
  : umlStateMachine(nullptr),
    mscModel(nullptr),
    objectName(QLatin1String("")),
    stateCounter(0),
    _loopCounterNumber(0)
{}

bool ComMscToStatemachine::execute(StateMachineModel* umlStateMachine, MscModel* mscModel, const QString &objName, QString* errorString)
{
  if(errorString == nullptr)
  {
    return false;
  }
  if(umlStateMachine == nullptr)
  {
    *errorString = "Error: Pointer to UML State Machine is Zero!";
    return false;
  }
  if(mscModel == nullptr)
  {
    *errorString = "Error: Pointer to mscModel is Zero!";
    return false;
  }
  this->umlStateMachine = umlStateMachine;
  this->mscModel = mscModel;
  this->objectName = objName;
  this->stateCounter = 0;
  this->_errorString = errorString;

  this->umlStateMachine->setName(mscModel->name());

  foreach(MscSequence* sequence, mscModel->sequences())
  {
    QString guard = QStringLiteral("");
    QStringList qListActionMessages;
    QStringList qListAction;
    MscMessageItem const* previousMessage = nullptr;
    AbstractStateItem* currentState = nullptr;
    SimpleStateItem* endState = nullptr;
    if(this->processSequence(sequence, currentState, endState, previousMessage, &qListActionMessages, &qListAction, &guard) == nullptr) return false;
  }
  return true;
}

AbstractStateItem* ComMscToStatemachine::processSequence(MscSequence const* sequenceList,
                                                AbstractStateItem* currentState,
                                                AbstractStateItem* endState,
                                                MscMessageItem const* previousMessage,
                                                QStringList* qListActionMessages,
                                                QStringList* qListAction,
                                                QString* guard,
                                                bool* bRet)
{
  if(bRet) *bRet = false;
  if(!guard)
  {
    *this->_errorString = "Error: in process squence pointer of 'guard' is zero!";
    return nullptr;
  }
  if(!qListActionMessages)
  {
    *this->_errorString = "Error: in process squence pointer of 'qListActionMessages' is zero!";
    return nullptr;
  }
  if(!qListAction)
  {
    *this->_errorString = "Error: in process squence pointer of 'qListAction' is zero!";
    return nullptr;
  }

  AbstractStateItem* _locEndState = nullptr;
  foreach(MscSequenceItem const* sequenceElement, sequenceList->sequenceItems())
  {
    if(sequenceList->sequenceItems().back() == sequenceElement)
    {
      _locEndState = endState;
    }
    if(MscMessageItem const* messageItem = dynamic_cast<model::msc::MscMessageItem const*>(sequenceElement))
    {
      model::base::ComponentItem const* targetComponent = dynamic_cast<model::base::ComponentItem const*>(messageItem->targetPort()->owner());
      model::base::ComponentItem const* sourceComponent = dynamic_cast<model::base::ComponentItem const*>(messageItem->sourcePort()->owner());

      if(targetComponent == nullptr && sourceComponent == nullptr)
      {
        *this->_errorString = "Error: Unkown source or target component for " + messageItem->toString();
        return nullptr;
      }
      if(targetComponent->name() == this->objectName)
      {
        if(previousMessage == nullptr)
        {
          if(!qListActionMessages->isEmpty())
          {
            currentState = checkCreateState_AddTransition(nullptr, currentState, QString::number(++this->stateCounter), qListActionMessages, qListAction, guard);
            if(!currentState) return nullptr;
          }
          previousMessage = messageItem;
        }
        else
        {
          currentState = checkCreateState_AddTransition(previousMessage, currentState, QString::number(++this->stateCounter), qListActionMessages, qListAction, guard);
          if(!currentState) return nullptr;
          previousMessage = messageItem;
        }
      }
      else if (sourceComponent->name() == this->objectName)
      {
        QStringList stringList;
        stringList << "test";
        *qListActionMessages << messageItem->toString() + ";";
      }
      else
      {
        qDebug()<< "Message '" << messageItem->toString() <<"' not for object"<< this->objectName;
      }
    }
    else if(MscStatementItem const* statementItem = dynamic_cast<model::msc::MscStatementItem const*>(sequenceElement))
    {
      if(statementItem->component() != nullptr && statementItem->component()->name() == this->objectName)
      {
        if(previousMessage == nullptr && currentState == nullptr) //init
        {
          AbstractStateItem* newState = this->getOrCreateState(statementItem->statement());
          if(!newState)
          {
            *this->_errorString = "Error: can not create new State '" + statementItem->statement() + "'!";
            return nullptr;
          }
          currentState = newState;
        }
        else if (previousMessage == nullptr && currentState != nullptr) //doppelte State Invariant
        {
          qDebug()<< "Double State Invariant";
        }
        else if (previousMessage != nullptr && currentState != nullptr)
        {
          currentState = checkCreateState_AddTransition(previousMessage, currentState, statementItem->statement(), qListActionMessages, qListAction, guard);
          if(!currentState) return nullptr;
          previousMessage = nullptr;
        }
        else
        {
          qDebug()<< "Invariant undefined";
        }
      }
      else
      {
        qDebug()<< "Invariant '" << statementItem->statement() << "' not for component '" << this->objectName << "'!";
      }
    }
    else if(MscTimerItem const* timerItem = dynamic_cast<model::msc::MscTimerItem const*>(sequenceElement))
    {
      Q_UNUSED(timerItem);
      //mag todo
      *this->_errorString = "Error: Timer element not supported '" + sequenceElement->text() + "'!";
      return nullptr;
    }
    else if(MscFragmentItem const* fragmentItem = dynamic_cast<model::msc::MscFragmentItem const*>(sequenceElement))
    {
      if(fragmentItem->fragmentType() == AlternativeFragment)
      {
        if(previousMessage != nullptr || !qListActionMessages->isEmpty())
        {
          currentState = checkCreateState_AddTransition(previousMessage, currentState, QString::number(++this->stateCounter), qListActionMessages, qListAction, guard);
          if(!currentState) return nullptr;
          previousMessage = nullptr;
        }
        qDebug()<< "AlternativeFragment";
        AbstractStateItem* altStartState = currentState;
        AbstractStateItem* altEndState = _locEndState;
        AbstractStateItem* tempState = nullptr;
        foreach( MscFragmentRegionItem const* altOperand, fragmentItem->regions())
        {
          QString tempGuard = altOperand->condition();
          if(altOperand == fragmentItem->regions().first())
          {
            QStringList qEmptyListActionMessages;
            bool retValue = false;
            tempState = processSequence(altOperand, altStartState, altEndState, previousMessage, &qEmptyListActionMessages, qListAction, &tempGuard, &retValue);
            qDebug()<< "retValue = " << retValue;
            if(!retValue) return nullptr;
          }
          else
          {
            QStringList qEmptyListActionMessages;
            bool retValue = false;
            processSequence(altOperand, altStartState, tempState, previousMessage, &qEmptyListActionMessages, qListAction, &tempGuard, &retValue);
            qDebug()<< "retValue = " << retValue;
            if(!retValue) return nullptr;
          }
        }
        previousMessage = nullptr;
        currentState = tempState;
      }
      else if(fragmentItem->fragmentType() == ParallelFragment)
      {
        //mag todo
        *this->_errorString = "Error: parallel fragment not supported '" + sequenceElement->text() + "'!";
        return nullptr;
      }
      else if(fragmentItem->fragmentType() == OptionalFragment)
      {
        if(previousMessage != nullptr || !qListActionMessages->isEmpty())
        {
          currentState = checkCreateState_AddTransition(previousMessage, currentState, QString::number(++this->stateCounter), qListActionMessages, qListAction, guard);
          if(!currentState) return nullptr;
          previousMessage = nullptr;
        }
        bool retValue = false;
        currentState = processSequence(fragmentItem->regions().first(), currentState, _locEndState, previousMessage, qListActionMessages, qListAction, guard, &retValue);
        if(!retValue) return nullptr;
      }
      else if(fragmentItem->fragmentType() == LoopFragment)
      {
        if(previousMessage != nullptr || !qListActionMessages->isEmpty())
        {
          currentState = checkCreateState_AddTransition(previousMessage, currentState, QString::number(++this->stateCounter), qListActionMessages, qListAction, guard);
          if(!currentState) return nullptr;
          previousMessage = nullptr;
        }
        QString loopGuard;
        if(!guard->isEmpty()) loopGuard = *guard + QStringLiteral(" && ");
        QString guardValue = fragmentItem->regions().first()->condition();
        QStringList list = guardValue.split(",");
        QString minint = list.first();
        QString maxint = list.last();
        QString counter = "counter" + QString::number(++this->_loopCounterNumber);
        loopGuard += counter +"<"+ maxint;
        bool retValue = false;
        _locEndState = currentState;
        *qListAction << counter + "=" + counter + "+1;";

        currentState = processSequence(fragmentItem->regions().first(), currentState, _locEndState, previousMessage, qListActionMessages, qListAction, &loopGuard, &retValue);
        if(!retValue) return nullptr;
        if(currentState)
        {
          guard->clear();
          *guard = counter + ">=" + minint;
        }
        else
        {
          qListAction->erase(qListActionMessages->end());
        }
      }
      else
      {
        *this->_errorString = "Error: Unknown fragment type'" + sequenceElement->text() + "'!";
        return nullptr;
      }
    }
    else
    {
      *this->_errorString = "Error: Unknown SequenceElement '" + sequenceElement->text() + "'!";
      return nullptr;
    }
  }
  if(previousMessage != nullptr || !qListActionMessages->isEmpty())
  {
    if(_locEndState)
    {
      currentState = checkCreateState_AddTransition(previousMessage, currentState, _locEndState->name(), qListActionMessages, qListAction, guard);
      if(!currentState) return nullptr;
    }
    else
    {
      currentState = checkCreateState_AddTransition(previousMessage, currentState, QString::number(++this->stateCounter), qListActionMessages, qListAction, guard);
      //currentState = checkCreateState_AddTransition(previousMessage, currentState, "end", qListActionMessages, guard);
      if(!currentState) return nullptr;
    }
  }
  if(bRet) *bRet = true;
  return currentState;
}



AbstractStateItem* ComMscToStatemachine::checkCreateState_AddTransition(MscMessageItem const* message,
                                                               AbstractStateItem* currentState,
                                                               QString newState,
                                                               QStringList *qListActionMessages,
                                                               QStringList *qListAction,
                                                               QString* guard)
{
  //trigger
  QString triggerName = QLatin1String("");
  model::base::SignalItem* signal = nullptr;
  model::base::PortItem* port = nullptr;
  if(message)
  {
    signal = this->getOrCreateSignal(message->signal());
    port = this->getOrCreatePort((message->targetPort()));
  }
  else
  {
    signal = this->getOrCreateSignal("");
    port = this->getOrCreatePort("defaultPort");
  }
  if(!signal)
  {
    utils::AddPtrString(this->_errorString) << "Error: unable to get/create signal '" + signal->name() + "'!";
    return nullptr;
  }
  if(!port)
  {
    utils::AddPtrString(this->_errorString) << "Error: unable to get/create port '" + port->name() + "'!";
  }

  //start state
  if(currentState == nullptr)
  {
    AbstractStateItem* tempState = this->getOrCreateState(QStringLiteral("init"));
    if(!tempState)
    {
      *this->_errorString = "Error: unable to create state 'init'!";
      return nullptr;
    }
    else
    {
      currentState = tempState;
    }
  }

  //end State
  AbstractStateItem* endState = this->getOrCreateState(newState);
  if(!endState)
  {
    *this->_errorString = "Error: unable to create state '" + newState + "'!";
    return nullptr;
  }
  //newTransition
  SignalTriggerItem* trigger = new SignalTriggerItem(signal, port);
  if(!trigger)
    return nullptr;

  TransitionItem*  transItem = new TransitionItem(trigger, currentState, endState);
  if(!this->umlStateMachine->addTransition(transItem, this->_errorString))
  {
    *this->_errorString = "Error: unable to create transition '"+ signal->name() +"'!";
    return nullptr;
  }

  //add Parameter
  //mag todo

  //add Guard
  if(guard && !guard->isEmpty())
  {
    //QStringList qList = guard->split(QStringLiteral("="));
    transItem->setGuard(*guard); //guard aufteilen -> addGuard(qList.first().toStdString(),qList.last().toStdString());
    guard->clear();
  }

  if(message)
  {
    QString newGuard = transItem->guard();
    foreach(ParamValueItem const* para, message->paramValues())
    {
      if(!newGuard.isEmpty()) newGuard += QStringLiteral(" && ");
      QString value = this->valueTransform(para);
      newGuard += para->param()->name() + QStringLiteral("==") + value;
      transItem->setGuard(newGuard);
    }
  }

  //add Actions
  QString action;
  bool first = true;

  foreach (QString str, *qListAction)
  {
    if(first)
    {
      first = false;
    }
    else
    {
      action += "\n";
    }
    action += str;
  }
  qListAction->clear();

  foreach(QString str, *qListActionMessages)
  {
    if(first)
    {
      first = false;
    }
    else
    {
      action += "\n";
    }
    action += str;
  }
  qListActionMessages->clear();

//  foreach(MscMessageItem const* actionMessage, *qListActionMessages)
//  {
//    if(qListActionMessages->first() != actionMessage) action += "\n";
//    action += actionMessage->toString() + QStringLiteral(";");
//  }
  if(!action.isEmpty()) transItem->setAction(action);

  return endState;
}

AbstractStateItem* ComMscToStatemachine::getOrCreateState(const QString& name)
{
  foreach(AbstractStateItem* state, this->umlStateMachine->states())
  {
    if(state->name() == name) return state;
  }
  AbstractStateItem* newState = new SimpleStateItem(name);
  if(!umlStateMachine->addState(newState, this->_errorString)) return nullptr;
  return newState;
}

model::base::SignalItem* ComMscToStatemachine::getOrCreateSignal(model::msc::SignalItem const* mscSignal)
{
  if(!mscSignal)
  {
    return this->umlStateMachine->addSignal("", this->_errorString);
  }

  model::base::SignalItem* sig = this->umlStateMachine->signal(mscSignal->name());
  if(sig == nullptr)
  {
    sig = this->umlStateMachine->addSignal(mscSignal->name(), this->_errorString);

    for(ParamItem const* para : mscSignal->params())
    {
      DataTypeItem* type = getOrCreateType(para);
      Q_ASSERT(type);
      sig->addParameter(para->name(),
                        type->name(),
                        this->_errorString);
    }
  }
  return sig;
}

model::base::SignalItem* ComMscToStatemachine::getOrCreateSignal(const QString& name)
{
  model::base::SignalItem* sig = this->umlStateMachine->signal(name);
  if(sig == nullptr)
  {
    sig = this->umlStateMachine->addSignal(name, this->_errorString);
  }
  return sig;
}

model::base::PortItem* ComMscToStatemachine::getOrCreatePort(model::msc::PortItem const* mscPort)
{
  if(!mscPort)
  {
    return this->umlStateMachine->addPort("", this->_errorString);
  }

  model::base::PortItem* port = this->umlStateMachine->port(mscPort->name());
  if(port == nullptr)
  {
    port = this->umlStateMachine->addPort(mscPort->name(), this->_errorString);
  }
  return port;
}

model::base::PortItem* ComMscToStatemachine::getOrCreatePort(const QString& name)
{
  model::base::PortItem* port = this->umlStateMachine->port(name);
  if(port == nullptr)
  {
    port = this->umlStateMachine->addPort(name, this->_errorString);
  }
  return port;
}

DataTypeItem *ComMscToStatemachine::getOrCreateType(ParamItem const* para)
{
  QString typeName = para->dataType();
  DataTypeItem* type = this->umlStateMachine->dataType(typeName);
  if(type == nullptr)
  {
    type = this->umlStateMachine->addDataType(typeName, this->_errorString);
  }
  return type;
}

QString ComMscToStatemachine::valueTransform(ParamValueItem const* paraValue)
{
  QString paramValueString = paraValue->data().toString();
  if(paramValueString == "true" || paramValueString == "True")
  {
    return "true";
  }
  else if(paramValueString == "false" || paramValueString == "False")
  {
    return "false";
  }
  return paramValueString;
}
