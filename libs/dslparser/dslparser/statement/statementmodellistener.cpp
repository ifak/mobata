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

#include "statementmodellistener.hpp"

#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/paramitem.hpp>
#include <mobata/model/base/functionitem.hpp>

#include <mobata/model/base/statements/rootstatementmodel.hpp>
#include <mobata/model/base/statements/attributeassignstatementmodel.hpp>
#include <mobata/model/base/statements/conditionstatementmodel.hpp>
#include <mobata/model/base/statements/functioncallstatementmodel.hpp>
#include <mobata/model/base/statements/sendtostatementmodel.hpp>
#include <mobata/model/base/statements/statementmodel.hpp>
#include <mobata/model/base/statements/switchstatementmodel.hpp>
#include <mobata/model/statemachine/statemachinemodel.hpp>

#include <QStack>
#include <QDebug>

#include "combuildstatementmodel.hpp"

using namespace model::base::statement;
using namespace antlr4;

namespace dslparser {
namespace base {

using common::addKeywordLocation;

class StatementModelListener::Private
{
  friend class StatementModelListener;

  model::statemachine::StateMachineModel const* _wholeModel;
  QStack<uint>                                  _depthOfLastSwitchStatement;
  QStack<StatementModel*>                       _currentStatement;
  QStack<QString>                               _currentCondition;
  QStack<QString>                               _currentPuT;
  CommonTokenStream*                            _stream;
  bool                                          _inSwitch = false;
  bool                                          _noReach = false;
  
  Private(const model::statemachine::StateMachineModel *wholeModel,
          const QString& )
    : _wholeModel(wholeModel)
    //      _currentPathItem(0),
    //      _importItems(),
    //      _praefix(praefix)
  {}
};

StatementModelListener::StatementModelListener(RootStatementModel* statementDeclModel,
                                               DslErrorList* statementErrors,
                                               model::statemachine::StateMachineModel const* wholeModel,
                                               const QString& praefix)
  : common::CommonModelListener<CommonDeclBaseListener, CommonDeclParser, RootStatementModel>(statementDeclModel,
                                                                                              statementErrors),
    _d(new Private(wholeModel,praefix))
{
  Q_ASSERT(this->_d->_wholeModel);
  this->setAttributesModel(const_cast<model::statemachine::StateMachineModel*>(this->_d->_wholeModel));
  this->setDataTypesModel(const_cast<model::statemachine::StateMachineModel*>(this->_d->_wholeModel));

  _d->_currentStatement.push(statementDeclModel);
}

StatementModelListener::~StatementModelListener()
{
  delete this->_d;
}

void StatementModelListener::setTokenStream(CommonTokenStream* stream)
{
  _d->_stream = stream;
}

void StatementModelListener::exitAttributeAssignStatement(CommonDeclParser::AttributeAssignStatementContext *ctx)
{
  if(ctx && ctx->attributeName() && ctx->expression() && !_d->_noReach && !_d->_inSwitch){
    AttributeAssignStatementModel* attrAss = new AttributeAssignStatementModel();
    attrAss->setAttributeName(QString::fromStdString(ctx->attributeName()->getText()));
    attrAss->setAttributeValue(QString::fromStdString(ctx->expression()->getText()).replace(QString("msg."),QString("_event.data.")));
    Q_ASSERT(_d->_currentStatement.size());
    if(_d->_currentStatement.top()->type() == StatementType::baseStatement){
      static_cast<RootStatementModel*>(_d->_currentStatement.top())->addChild(attrAss);
    }
    else if(_d->_currentStatement.top()->type() == StatementType::conditionStatement){
      static_cast<ConditionStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),attrAss);
    }
    else if(_d->_currentStatement.top()->type() == StatementType::switchStatement){
      static_cast<SwitchStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),attrAss);
    }
  }
}

void StatementModelListener::exitFunctionCallStatement(CommonDeclParser::FunctionCallStatementContext *ctx)
{
  if(!_d->_inSwitch && ctx && !_d->_noReach){
    FunctionCallStatementModel* newStatement = new FunctionCallStatementModel();
    newStatement->setContent(QString::fromStdString(ctx->functionCall()->getText()).replace(QString("msg."),QString("_event.data.")) + QString(";"));//Quick fix
    Q_ASSERT(_d->_currentStatement.size());
    if(_d->_currentStatement.top()->type() == StatementType::baseStatement){
      static_cast<RootStatementModel*>(_d->_currentStatement.top())->addChild(newStatement);
    }
    else if(_d->_currentStatement.top()->type() == StatementType::conditionStatement){
      static_cast<ConditionStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),newStatement);
    }
    else if(_d->_currentStatement.top()->type() == StatementType::switchStatement){
      static_cast<SwitchStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),newStatement);
    }
  }
}

void StatementModelListener::exitBreakStatement(CommonDeclParser::BreakStatementContext *ctx)
{
  Q_UNUSED(ctx);
  if(_d->_noReach) return;
  _d->_currentCondition.pop();
  _d->_currentCondition.push(QString(""));
}

void StatementModelListener::enterConditionalStatement(CommonDeclParser::ConditionalStatementContext *ctx)
{
  Q_UNUSED(ctx);
  if(_d->_noReach || _d->_inSwitch) return;
  ConditionStatementModel* condModel = new ConditionStatementModel();
  Q_ASSERT(_d->_currentStatement.size());
  if(_d->_currentStatement.top()->type() == StatementType::baseStatement){
    static_cast<RootStatementModel*>(_d->_currentStatement.top())->addChild(condModel);
  }
  else if(_d->_currentStatement.top()->type() == StatementType::conditionStatement){
    static_cast<ConditionStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),condModel);
  }
  else if(_d->_currentStatement.top()->type() == StatementType::switchStatement){
    static_cast<SwitchStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),condModel);
  }
  _d->_currentStatement.push(condModel);
}

void StatementModelListener::exitConditionalStatement(CommonDeclParser::ConditionalStatementContext *ctx)
{
  if(!ctx) return;
  Q_ASSERT(_d->_currentStatement.size());
  _d->_currentStatement.top()->setContent(QString::fromStdString(ctx->getText()).replace(QString("msg."),QString("_event.data.")));
  _d->_currentStatement.pop();
  _d->_currentCondition.pop();
}

void StatementModelListener::exitSwitchPuT(CommonDeclParser::SwitchPuTContext *ctx)
{
  if(!ctx || !ctx->contextID()) return;
  _d->_currentPuT.append(QString::fromStdString(ctx->contextID()->getText()));
}

void StatementModelListener::exitIfEuT(CommonDeclParser::IfEuTContext *ctx)
{
  if(!ctx || !ctx->expression()) return;
  _d->_currentCondition.push(QString::fromStdString(ctx->expression()->getText()).replace(QString("msg."),QString("_event.data.")));
  if(_d->_currentStatement.top()->type() == StatementType::conditionStatement)
    static_cast<ConditionStatementModel*>(_d->_currentStatement.top())->addChild(QString::fromStdString(ctx->expression()->getText()).replace(QString("msg."),QString("_event.data.")),nullptr);
}

void StatementModelListener::enterElseStatement(CommonDeclParser::ElseStatementContext *ctx)
{
  Q_UNUSED(ctx);
  if(_d->_noReach || _d->_inSwitch) return;
  _d->_currentCondition.pop();
  _d->_currentCondition.push(QString(""));
}

void StatementModelListener::enterSwitchStatement(CommonDeclParser::SwitchStatementContext *ctx)
{
  Q_UNUSED(ctx);
  _d->_inSwitch = true;
  SwitchStatementModel* statement = new SwitchStatementModel();
  Q_ASSERT(_d->_currentStatement.size());
  if(_d->_currentStatement.top()->type() == StatementType::baseStatement){
    static_cast<RootStatementModel*>(_d->_currentStatement.top())->addChild(statement);
  }
  else if(_d->_currentStatement.top()->type() == StatementType::conditionStatement){
    static_cast<ConditionStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),statement);
  }
  else if(_d->_currentStatement.top()->type() == StatementType::switchStatement){
    static_cast<SwitchStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),statement);
  }
  _d->_currentStatement.append(statement);
}

void StatementModelListener::exitSwitchStatement(CommonDeclParser::SwitchStatementContext *ctx)
{
  _d->_currentPuT.pop();
  _d->_inSwitch = _d->_currentPuT.size();
  QString sourceInterval = QString::fromStdString(_d->_stream->getText(ctx->getSourceInterval())).replace(QString("msg."),QString("_event.data."));
  _d->_currentStatement.top()->setContent(sourceInterval);
}

void StatementModelListener::exitSendToStatement(CommonDeclParser::SendToStatementContext *ctx)
{
  if(!ctx || !ctx->signalSend() || !ctx->signalSend()->signalIdPath() || !ctx->signalSend()->functionCallBody()) return;
  if(_d->_inSwitch){
    appendDslError(ctx->start,QString("You are not allowed to send Signals in a SWITCH-Statement;"));
    return;
  }
  if(const model::base::SignalItem* signal = _d->_wholeModel->signal(QString::fromStdString(ctx->signalSend()->signalIdPath()->getText()))){
    SendToStatementModel* statement = new SendToStatementModel();
    QVector<QString> paramNames;
    for(auto param: signal->params()){
      paramNames.append(param->name());
    }
    statement->setParamNames(paramNames);
    statement->setMessageName(QString::fromStdString(ctx->signalSend()->signalIdPath()->getText()));
    statement->setContent(QString::fromStdString(ctx->signalSend()->functionCallBody()->getText()).replace(QString("msg."),QString("_event.data.")));
    if(ctx->toPortName()
       &&ctx->toPortName()->contextID()){
      int portID = -1;
      if(auto sendPort = _d->_wholeModel->port(QString::fromStdString(ctx->toPortName()->contextID()->getText()))){
        portID = _d->_wholeModel->ports().indexOf(sendPort);
      }
      statement->setTarget(portID);
    }
    Q_ASSERT(_d->_currentStatement.size());
    if(_d->_currentStatement.top()->type() == StatementType::baseStatement){
      static_cast<RootStatementModel*>(_d->_currentStatement.top())->addChild(statement);
    }
    else if(_d->_currentStatement.top()->type() == StatementType::conditionStatement){
      static_cast<ConditionStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),statement);
    }
    else if(_d->_currentStatement.top()->type() == StatementType::switchStatement){
      static_cast<SwitchStatementModel*>(_d->_currentStatement.top())->addChild(_d->_currentCondition.top(),statement);
    }
  }
}

void StatementModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);

  //  qDebug()<<"StatementModelListener::visitErrorNode() "
  //            "state: "<<this->_d->_listenerStates.top()
  //         <<"error node: "<<node->toString().c_str();

  return;
}

} // namespace base
} // namespace dslparser
