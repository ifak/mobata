#include "writemscmodel.hpp"

#include "../msc.hpp"

#include "../../base/io/writebasemodel.hpp"

#include <QJsonObject>
#include <QJsonArray>

namespace model {
namespace msc {
namespace io {

void writeMscModel(MscModel const* mscModel,
                   QJsonObject& jsonObject)
{
  Q_ASSERT(mscModel);

  base::io::writeBaseModel(mscModel, jsonObject);

  if(mscModel->components().count())
  {
    QJsonArray mscComponentsArray;
    foreach (MscComponentItem const* mscComponent,
             mscModel->components())
    {
      QJsonObject componentObject;
      writeMscComponent(mscComponent, componentObject);
      mscComponentsArray.append(componentObject);
    }
    jsonObject["components"] = mscComponentsArray;
  }

  if(mscModel->sequences().count())
  {
    QJsonArray sequencesArray;
    foreach (MscSequence const* mscSequence,
             mscModel->sequences())
    {
      QJsonObject sequenceObject;
      writeMscSequence(mscSequence, sequenceObject);
      sequencesArray.append(sequenceObject);
    }
    jsonObject["sequences"] = sequencesArray;
  }

  return;
}

void writeMscComponent(MscComponentItem const* mscComponent,
                       QJsonObject& jsonObject)
{
  Q_ASSERT(mscComponent);

  base::io::writeComponent(mscComponent, jsonObject);

  if(mscComponent->defaultPort())
    jsonObject["defaultPort"] = mscComponent->defaultPort()->uuid().toString();

  return;
}

void writeMscSequence(MscSequence const* mscSequence,
                      QJsonObject& jsonObject)
{
  Q_ASSERT(mscSequence);

  jsonObject["uuid"] = mscSequence->uuid().toString();
  jsonObject["name"] = mscSequence->name();
  if(mscSequence->sequenceItems().count())
  {
    QJsonArray stepsArray;
    writeMscStepsArray(mscSequence, stepsArray);
    jsonObject["steps"] = stepsArray;
  }

  return;
}

void writeMscStepsArray(const MscSequence* mscSequence,
                        QJsonArray& jsonStepsArray)
{
  using namespace utils;

  Q_ASSERT(mscSequence);

  foreach (MscSequenceItem const* mscSequenceItem,
           mscSequence->sequenceItems())
  {
    QJsonObject jsonStepObject;

    jsonStepObject["stepType"] = mscSequenceItem->stepTypeString();

    if(mscSequenceItem->stepType() == MessageStep)
    {
      MscMessageItem const* mscMessageItem = simple_cast<MscMessageItem const*>(mscSequenceItem);
      writeMscMessage(mscMessageItem, jsonStepObject);
    }
    else if(mscSequenceItem->stepType() == CheckMessageStep)
    {
      MscCheckMessageItem const* mscCheckMessageItem
          = simple_cast<MscCheckMessageItem const*>(mscSequenceItem);
      writeMscCheckMessage(mscCheckMessageItem, jsonStepObject);
    }
    else if(mscSequenceItem->stepType() == StatementStep)
    {
      MscStatementItem const* mscStatementItem = simple_cast<MscStatementItem const*>(mscSequenceItem);
      writeMscStatement(mscStatementItem, jsonStepObject);
    }
    else if(mscSequenceItem->stepType() == TimeoutStep)
    {
      MscTimeoutItem const* mscTimeout = simple_cast<MscTimeoutItem const*>(mscSequenceItem);
      writeMscTimeout(mscTimeout, jsonStepObject);
    }
    else if(mscSequenceItem->stepType() == TimerStep)
    {
      MscTimerItem const* mscTimer = simple_cast<MscTimerItem const*>(mscSequenceItem);
      writeMscTimer(mscTimer, jsonStepObject);
    }
    else if(mscSequenceItem->stepType() == SleepTimerStep)
    {
      MscSleepTimerItem const* mscSleepTimer = simple_cast<MscSleepTimerItem const*>(mscSequenceItem);
      writeMscSleepTimer(mscSleepTimer, jsonStepObject);
    }
    else if(mscSequenceItem->stepType() == FragmentStep)
    {
      MscFragmentItem const* mscFrament = simple_cast<MscFragmentItem const*>(mscSequenceItem);
      writeMscFragment(mscFrament, jsonStepObject);
    }

    jsonStepsArray.append(jsonStepObject);
  }

  return;
}

void writeMscMessage(const MscMessageItem* mscMessage,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscMessage);

  base::io::writeModelItem(mscMessage, jsonObject);

  jsonObject["sourcePort"] = mscMessage->sourcePort()->uuid().toString();
  jsonObject["targetPort"] = mscMessage->targetPort()->uuid().toString();
  jsonObject["referenceId"] = mscMessage->referenceId().toString();

  if(!mscMessage->text().isEmpty())
    jsonObject["text"] = mscMessage->text();

  if(mscMessage->signal())
  {
    jsonObject["signal"] = mscMessage->signal()->uuid().toString();

    if(mscMessage->paramValues().count())
    {
      QJsonArray jsonParamValues;
      foreach(ParamValueItem const* paramValue, mscMessage->paramValues())
      {
        QJsonObject jsonParamValue;
        base::io::writeParamValueItem(paramValue, jsonParamValue);
        jsonParamValues.append(jsonParamValue);
      }
      jsonObject["paramValues"] = jsonParamValues;
    }
  }

  return;
}

void writeMscCheckMessage(const MscCheckMessageItem* mscCheckMessage,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscCheckMessage);

  writeMscMessage(mscCheckMessage, jsonObject);

  jsonObject["guard"] = mscCheckMessage->guard();
  QJsonObject obj;
  for(const QString& key : mscCheckMessage->assign().keys()){
    obj.insert(key, mscCheckMessage->assign().value(key));
  }
  jsonObject["assign"] = obj;

  return;
}

void writeMscStatement(const MscStatementItem* mscStatement,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscStatement);
  Q_ASSERT(mscStatement->component());

  base::io::writeModelItem(mscStatement, jsonObject);
  jsonObject["component"] = mscStatement->component()->uuid().toString();

  jsonObject["statement"] = mscStatement->statement();

  return;
}

void writeMscTimeout(const MscTimeoutItem* mscTimeout,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscTimeout);
  Q_ASSERT(mscTimeout->component());

  base::io::writeModelItem(mscTimeout, jsonObject);
  jsonObject["component"] = mscTimeout->component()->uuid().toString();

  QString timerId = QStringLiteral("");
  if(mscTimeout->timer())
    timerId = mscTimeout->timer()->uuid().toString();

  jsonObject["timer"] = timerId;

  return;
}

void writeMscTimer(const MscTimerItem* mscTimer,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscTimer);
  Q_ASSERT(mscTimer->component());

  base::io::writeModelItem(mscTimer, jsonObject);
  jsonObject["component"] = mscTimer->component()->uuid().toString();
  jsonObject["name"] = mscTimer->name();
  jsonObject["value"] = mscTimer->value();

  return;
}

void writeMscSleepTimer(const MscSleepTimerItem* mscSleepTimer,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscSleepTimer);
  Q_ASSERT(mscSleepTimer->component());

  base::io::writeModelItem(mscSleepTimer, jsonObject);
  jsonObject["component"] = mscSleepTimer->component()->uuid().toString();
  jsonObject["value"] = mscSleepTimer->value();

  return;
}

void writeMscFragment(const MscFragmentItem* mscFragment,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscFragment);

  base::io::writeModelItem(mscFragment, jsonObject);
  jsonObject["fragmentType"] = fragmentType2string(mscFragment->fragmentType());
  jsonObject["duration"] = QString::number(mscFragment->duration());

  QJsonArray jsonFragmentRegions;
  foreach(MscFragmentRegionItem const* fragmentRegion,
          mscFragment->regions())
  {
    QJsonObject jsonFragmentRegion;
    writeMscFragmentRegion(fragmentRegion, jsonFragmentRegion);
    jsonFragmentRegions.append(jsonFragmentRegion);
  }
  jsonObject["regions"] = jsonFragmentRegions;

  return;
}

void writeMscFragmentRegion(const MscFragmentRegionItem* mscFragmentRegion,
                     QJsonObject& jsonObject)
{
  Q_ASSERT(mscFragmentRegion);

  writeMscSequence(mscFragmentRegion, jsonObject);
  jsonObject["condition"] = mscFragmentRegion->condition();

  return;
}

} // namespace io
} // namespace msc
} // namespace model
