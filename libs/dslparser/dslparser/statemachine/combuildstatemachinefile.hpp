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
#pragma once

#include "../dslparser_global.hpp"
#include "../dslparser_types.hpp"
#include "../dslerror.hpp"
#include <mobata/model/statemachine/types.hpp>

#include <QObject>

namespace dslparser {
namespace statemachine{

class DSLPARSERSHARED_EXPORT ComBuildStateMachineFile
        : public QObject
{
public:
    ComBuildStateMachineFile(const QString& filePath,
                             const model::statemachine::StateMachineModel* statemachineDeclModel,
                             QObject* parent = nullptr);
    virtual ~ComBuildStateMachineFile();

    //converts model to a text declaration and saves it to a file
    virtual bool  execute(QString* errorString = 0);
    //converts model to a text declaration only
    QString toDocText();

    const DslErrorList&  errors() const;

private:
    void stateMachineDecl(QString* content, int tabCount = 0);
    void stateDecl(QString* content, const model::statemachine::AbstractStateItem* model, int tabCount);
    void simpleStateDecl(QString* content, const model::statemachine::SimpleStateItem* model, int tabCount);
    void junctionStateDecl(QString* content, const model::statemachine::JunctionStateItem* model, int tabCount);
    void junctionTransitionDecl(QString* content, const model::statemachine::TransitionItem *model, int tabCount);
    void choiceStateDecl(QString* content, const model::statemachine::ChoiceStateItem *model);
    void concurrentStateDecl(QString* content, const model::statemachine::ConcurrentStateItem* model, int tabCount);
    void regionDecl(QString* content, const model::statemachine::RegionItem* model, int tabCount);
    void compositeStateDecl(QString* content, const model::statemachine::CompositeStateItem* model, int tabCount);
    void finalStateDecl(QString* content, const model::statemachine::FinalStateItem* model);
    void initStateDecl(QString* content, const QString& name);
    void transitionDecl(QString* content, const model::statemachine::TransitionItem* model, int tabCount);
    void refSignalDecl(QString* content, const model::base::SignalItem* model);
    void refPortDecl(QString* content, const model::base::PortItem *model);
    void sourceStateDecl(QString* content, const QString& source);
    void targetStateDecl(QString* content, const QString& target);
    void refTimeoutDecl(QString* content, double value, int tabCount);

    Q_DISABLE_COPY(ComBuildStateMachineFile)
    class Private;
    Private* _d;
};

}//namespace statemachine
} // namespace dslparser
