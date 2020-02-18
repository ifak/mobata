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
#ifndef CONVERT_MSC_COMMSCTOSTATEMACHINE_HPP
#define CONVERT_MSC_COMMSCTOSTATEMACHINE_HPP

#include "model/statemachine/types.hpp"
#include "model/statemachine/statemachinemodel.hpp"
#include "model/msc/msc.hpp"

#include <QString>
#include <QMap>

namespace convert{
namespace msc{

class ComMscToStatemachine
{
public:
    ComMscToStatemachine();

    bool execute(model::statemachine::StateMachineModel* umlStateMachine,
                 model::msc::MscModel* mscModel,
                 const QString &objName,
                 QString* errorString);

private:
    model::statemachine::AbstractStateItem *processSequence(model::msc::MscSequence const* sequenceList,
                                                              model::statemachine::AbstractStateItem *currentState,
                                                              model::statemachine::AbstractStateItem *endState,
                                                              model::msc::MscMessageItem const* previousMessage,
                                                              QStringList *qListActionMessages, QStringList *qListAction,
                                                              QString* guard,
                                                              bool *bRet = 0);

    model::statemachine::AbstractStateItem *checkCreateState_AddTransition(model::msc::MscMessageItem const* message,
                                                                             model::statemachine::AbstractStateItem* currentState,
                                                                             QString newState,
                                                                             QStringList* qListActionMessages,
                                                                             QStringList *qListAction,
                                                                             QString* guard);

    model::statemachine::AbstractStateItem* getOrCreateState(const QString& name);
    model::base::SignalItem* getOrCreateSignal(model::msc::SignalItem const* mscSignal);
    model::base::SignalItem* getOrCreateSignal(const QString& name);
    model::base::DataTypeItem* getOrCreateType(model::msc::ParamItem const* para);
    model::base::PortItem* getOrCreatePort(model::msc::PortItem const* mscPort);
    model::base::PortItem* getOrCreatePort(const QString& name);
    QString valueTransform(model::msc::ParamValueItem const* paraValue);

private:
    model::statemachine::StateMachineModel*  umlStateMachine;
    model::msc::MscModel* mscModel;
    QString objectName;
    int stateCounter;
    QString* _errorString;
    quint16 _loopCounterNumber;
};

} //end namespace msc
} //end namespace convert

#endif // CONVERT_MSC_COMMSCTOSTATEMACHINE_HPP
