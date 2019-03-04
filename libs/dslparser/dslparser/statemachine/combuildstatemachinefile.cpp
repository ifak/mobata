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

#include <QDebug>

#include "combuildstatemachinefile.hpp"
#include "../dslerror.hpp"

#include <dslparser/common/buildbasemodelfile.hpp>
#include <mobata/model/base/propports.hpp>
#include <mobata/model/base/basemodel.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/atriggeritem.hpp>
#include <mobata/model/base/signaltriggeritem.hpp>
#include <mobata/model/base/timeouttriggeritem.hpp>

#include <mobata/model/statemachine/types.hpp>
#include <mobata/model/statemachine/statemachine.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/model/statemachine/functors.hpp>

#include <mobata/utils/functors.hpp>

using namespace model::statemachine;
using namespace model::base;
using namespace dslparser::common;
using namespace utils;

namespace dslparser {
namespace statemachine {

class ComBuildStateMachineFile::Private
{
  friend class ComBuildStateMachineFile;

  QString                   _filePath;
  const StateMachineModel*  _statemachineDeclModel;
  DslErrorList              _statemachineErrors;

  Private(const QString& filePath,
          const StateMachineModel* statemachineDeclModel)
    : _filePath(filePath),
      _statemachineDeclModel(statemachineDeclModel)
  {}
};

ComBuildStateMachineFile::ComBuildStateMachineFile(const QString& filePath,
                                                   const StateMachineModel* statemachineDeclModel,
                                                   QObject* parent)
  : QObject(parent), _d(new Private(filePath, statemachineDeclModel))
{}

ComBuildStateMachineFile::~ComBuildStateMachineFile()
{
  delete this->_d;
}

bool ComBuildStateMachineFile::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_statemachineDeclModel);

  QString statemachineDocText;
  stateMachineDecl(&statemachineDocText);
  if(statemachineDocText.isEmpty())
    return false;

  if(!saveSpecificationModel(&statemachineDocText,
                             this->_d->_filePath,
                             errorString))
    return false;

  return true;
}

QString ComBuildStateMachineFile::toDocText()
{
  Q_ASSERT(this->_d->_statemachineDeclModel);

  QString statemachineDocText;
  stateMachineDecl(&statemachineDocText);

  return statemachineDocText;
}

const DslErrorList& ComBuildStateMachineFile::errors() const
{
  return this->_d->_statemachineErrors;
}

void ComBuildStateMachineFile::stateMachineDecl(QString* content, int tabCount)
{
  Q_ASSERT(content);

  AddPtrString(content) << QStringLiteral("StateMachine {") + nextLine(tabCount + 2);
  nameDecl(content, this->_d->_statemachineDeclModel->name());
  AddPtrString(content) << nextLine(tabCount + 2);

//  const model::base::PropPorts* propPorts = dynamic_cast<const model::base::PropPorts*>(this->_d->_statemachineDeclModel);
//  Q_ASSERT(propPorts);
  portsDecl(this->_d->_statemachineDeclModel,
            content,
            tabCount + 2);

  commonDecl(this->_d->_statemachineDeclModel,
             content,
             tabCount + 2);

  if(this->_d->_statemachineDeclModel->initState())
    initStateDecl(content,
                  this->_d->_statemachineDeclModel->initState()->name());

  if(this->_d->_statemachineDeclModel->states().size() > 1)
    AddPtrString(content) << doubleNextLine(tabCount + 2);

  for(const AbstractStateItem* state : this->_d->_statemachineDeclModel->states())
  {
    stateDecl(content, state, tabCount + 2);
    if(state != this->_d->_statemachineDeclModel->states().back())
      AddPtrString(content) << doubleNextLine(tabCount + 2);
  }

  if(!this->_d->_statemachineDeclModel->transitions().isEmpty())
    AddPtrString(content) << doubleNextLine(tabCount + 2);

  for(const TransitionItem* transition : this->_d->_statemachineDeclModel->transitions()) {
    transitionDecl(content, transition, tabCount + 2);
    if(transition != this->_d->_statemachineDeclModel->transitions().back())
      AddPtrString(content) << doubleNextLine(tabCount + 2);
  }

  AddPtrString(content) << nextLine(tabCount) + "}";

  return;
}

void ComBuildStateMachineFile::stateDecl(QString* content, const AbstractStateItem* model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  if(model->stateType() == Simple){
    const SimpleStateItem* item = static_cast<const SimpleStateItem*>(model);
    Q_ASSERT(item);
    simpleStateDecl(content, item, tabCount);
  }
  else if(model->stateType() == Junction){
    const JunctionStateItem* item = static_cast<const JunctionStateItem*>(model);
    junctionStateDecl(content, item, tabCount);
  }
  else if(model->stateType() == Choice){
    const JunctionStateItem* item = static_cast<const JunctionStateItem*>(model);
    Q_ASSERT(item);
    junctionStateDecl(content, item, tabCount);
    qWarning() << "Choice State detected. The current version of this library handles choice states as junction states!";
  }
  else if(model->stateType() == Concurrent){
    const ConcurrentStateItem* item = static_cast<const ConcurrentStateItem*>(model);
    Q_ASSERT(item);
    concurrentStateDecl(content, item, tabCount);
  }
  else if(model->stateType() == Composite){
    const CompositeStateItem* item = static_cast<const CompositeStateItem*>(model);
    Q_ASSERT(item);
    compositeStateDecl(content, item, tabCount);
  }
  else if(model->stateType() == Final){
    const FinalStateItem* item = static_cast<const FinalStateItem*>(model);
    Q_ASSERT(item);
    finalStateDecl(content, item);
  }

  return;
}

void ComBuildStateMachineFile::simpleStateDecl(QString* content, const SimpleStateItem *model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("SimpleState ");

  if(model->entryAction() != QStringLiteral("") || model->exitAction() != QStringLiteral("")){
    AddPtrString(content) << QStringLiteral("{") + nextLine(tabCount + 2);
    nameDecl(content, model->name());

    writeMultiLineString(content,
                         QStringLiteral("entry"),
                         model->entryAction(),
                         tabCount + 2);

    writeMultiLineString(content,
                         QStringLiteral("exit"),
                         model->exitAction(),
                         tabCount + 2);

    AddPtrString(content) << nextLine(tabCount) + "}";
  }
  else
    AddPtrString(content) << model->name() + QStringLiteral(";");

  return;
}

void ComBuildStateMachineFile::junctionStateDecl(QString* content, const JunctionStateItem *model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("JunctionState {") + nextLine(tabCount + 2);
  nameDecl(content, model->name());

  for (const TransitionItem* transition: model->transitions()) {
    AddPtrString(content) << nextLine(tabCount + 2);
    junctionTransitionDecl(content, transition, tabCount + 2);
  }

  AddPtrString(content) << nextLine(tabCount) + QStringLiteral("}");
  return;

}

void ComBuildStateMachineFile::choiceStateDecl(QString* content, const ChoiceStateItem *model)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << "ChoiceState " + model->name() + ";";
  return;
}

void ComBuildStateMachineFile::concurrentStateDecl(QString* content, const ConcurrentStateItem *model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("ConcurrentState {") + nextLine(tabCount + 2);

  nameDecl(content, model->name());

  for (const RegionItem* region : model->regions()) {
    AddPtrString(content) << nextLine(tabCount + 2);
    regionDecl(content, region, tabCount + 2);
  }

  AddPtrString(content) << nextLine(tabCount) + QStringLiteral("}");
}

void ComBuildStateMachineFile::regionDecl(QString* content, const RegionItem* model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("Region {") + nextLine(tabCount + 2);
  nameDecl(content, model->name());

  if(model->initState()){
    AddPtrString(content) << nextLine(tabCount + 2);
    initStateDecl(content,
                  model->initState()->name());
  }

  for(const AbstractStateItem* state : model->states()) {
    AddPtrString(content) << nextLine(tabCount + 2);
    stateDecl(content, state, tabCount + 2);
  }

  AddPtrString(content) << nextLine(tabCount) + QStringLiteral("}");
}

void ComBuildStateMachineFile::compositeStateDecl(QString* content, const CompositeStateItem *model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("CompositeState {") + nextLine(tabCount + 2);
  nameDecl(content, model->name());

  writeMultiLineString(content,
                       QStringLiteral("entry"),
                       model->entryAction(),
                       tabCount + 2);

  writeMultiLineString(content,
                       QStringLiteral("exit"),
                       model->exitAction(),
                       tabCount + 2);

  if(model->initState()){
    AddPtrString(content) << nextLine(tabCount + 2);
    initStateDecl(content,
                  model->initState()->name());
  }

  for(const AbstractStateItem* state : model->states()){
    AddPtrString(content) << nextLine(tabCount + 2);
    stateDecl(content, state, tabCount + 2);
  }
  AddPtrString(content) << nextLine(tabCount) +
                           QStringLiteral("}");
}

void ComBuildStateMachineFile::finalStateDecl(QString* content, const FinalStateItem *model)
{
  Q_ASSERT(model);
  AddPtrString(content) << QStringLiteral("FinalState ") +
                           model->name() +
                           QStringLiteral(";");
}

void ComBuildStateMachineFile::initStateDecl(QString* content, const QString& name)
{
  Q_ASSERT(content);
   AddPtrString(content) << QStringLiteral("initState: ") +
                            name +
                            QStringLiteral(";");
}

void ComBuildStateMachineFile::transitionDecl(QString* content, const TransitionItem* model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  const ATriggerItem* trigger = model->trigger();
  if(trigger && trigger->triggerType() == ATriggerItem::EventTrigger){
    AddPtrString(content) << QStringLiteral("SignalTransition {") + nextLine(tabCount + 2);
    nameDecl(content, model->name());
    const SignalTriggerItem* signalTrigger = static_cast<const SignalTriggerItem*>(trigger);
    Q_ASSERT(signalTrigger);

    if(signalTrigger->triggerSignal()){
      AddPtrString(content) << nextLine(tabCount + 2);
      refSignalDecl(content, signalTrigger->triggerSignal());
    }

    if(signalTrigger->port()){
      AddPtrString(content) << nextLine(tabCount + 2);
      refPortDecl(content, signalTrigger->port());
    }

  }
  else if(trigger && trigger->triggerType() == ATriggerItem::TimeoutTrigger){
    AddPtrString(content) << QStringLiteral("TimeoutTransition {") + nextLine(tabCount + 2);
    nameDecl(content, model->name());

    const TimeoutTriggerItem* timeoutTrigger = static_cast<const TimeoutTriggerItem*>(trigger);
    Q_ASSERT(timeoutTrigger);

    refTimeoutDecl(content, timeoutTrigger->value(), tabCount );
  }
  else if(trigger==nullptr)
  {
    AddPtrString(content) << QStringLiteral("SignalTransition {") + nextLine(tabCount + 2);
    nameDecl(content, model->name());
  }

  writeMultiLineString(content,
                       QStringLiteral("guard"),
                       model->guard(),
                       tabCount + 2);

  writeMultiLineString(content,
                       QStringLiteral("action"),
                       model->action(),
                       tabCount + 2);

  if(model->source()){
    AddPtrString(content) << nextLine(tabCount + 2);
    sourceStateDecl(content,
                    statePathRecursive(this->_d->_statemachineDeclModel, model->source()->uuid(), QStringList()));
  }

  if(model->target()){
    AddPtrString(content) << nextLine(tabCount + 2);
    targetStateDecl(content,
                    statePathRecursive(this->_d->_statemachineDeclModel, model->target()->uuid(), QStringList()));
  }

  AddPtrString(content) << nextLine(tabCount) + QStringLiteral("}");
}

void ComBuildStateMachineFile::junctionTransitionDecl(QString* content, const TransitionItem *model, int tabCount)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("JunctionTransition {") + nextLine(tabCount + 2);
  nameDecl(content, model->name());

  writeMultiLineString(content,
                       QStringLiteral("guard"),
                       model->guard(),
                       tabCount + 2);

  writeMultiLineString(content,
                       QStringLiteral("action"),
                       model->action(),
                       tabCount + 2);

  if(model->target()){
    AddPtrString(content) << nextLine(tabCount + 2);
    targetStateDecl(content,
                    statePathRecursive(this->_d->_statemachineDeclModel, model->target()->uuid(), QStringList()));
  }

  AddPtrString(content) << nextLine(tabCount) + QStringLiteral("}");

  return;
}

void ComBuildStateMachineFile::sourceStateDecl(QString* content, const QString& source)
{
  AddPtrString(content) << QStringLiteral("source: ") +
                           source +
                           QStringLiteral(";");
}

void ComBuildStateMachineFile::targetStateDecl(QString* content, const QString& target)
{
  AddPtrString(content) << QStringLiteral("target: ") +
                           target +
                           QStringLiteral(";");
}

void ComBuildStateMachineFile::refSignalDecl(QString* content, const model::base::SignalItem* model)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("signal: ") +
                           model->name() +
                           QStringLiteral(";");
  return;
}

void ComBuildStateMachineFile::refPortDecl(QString* content, const model::base::PortItem* model)
{
  Q_ASSERT(content);
  Q_ASSERT(model);

  AddPtrString(content) << QStringLiteral("port: ") +
                           model->name() +
                           QStringLiteral(";");
  return;
}

void ComBuildStateMachineFile::refTimeoutDecl(QString* content, double value, int tabCount)
{
  Q_ASSERT(content);

  QString valueString = QString::number(value, 'f', 2);
  if(!valueString.isEmpty())
    AddPtrString(content) << nextLine(tabCount + 2) +
                             QStringLiteral("value: ") +
                             valueString +
                             QStringLiteral(";");
  return;
}

} // namespace statemachine
} // namespace dslparser
