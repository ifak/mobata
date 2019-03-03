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

#include "sendtostatementmodel.hpp"
#include "statementmodel.hpp"
#include <QVector>
#include <QVectorIterator>
#include <QHash>

namespace model{
namespace base{
namespace statement{

class SendToStatementModel::Private
{
  friend class SendToStatementModel;

  QVector<QString>  _paramNames;
  QString           _messageName;
  int               _target = -1;

  Private()
  {}
  ~Private(){
  }
};

SendToStatementModel::SendToStatementModel():
  StatementModel(StatementType::messageSend),_d(new Private())
{}

SendToStatementModel::~SendToStatementModel()
{
  delete this->_d;
}

void SendToStatementModel::setParamNames(QVector<QString> params)
{
  _d->_paramNames = params;
}

void SendToStatementModel::setMessageName(const QString& name)
{
  _d->_messageName = name;
}

void SendToStatementModel::setTarget(int targetID)
{
  _d->_target = targetID;
}

QVector<QString> SendToStatementModel::paramNames()
{
  return _d->_paramNames;
}

const QString& SendToStatementModel::messageName()
{
  return _d->_messageName;
}

int SendToStatementModel::target()
{
  return _d->_target;
}

QString SendToStatementModel::getText()
{
  QString res = QString("%0(%1);\n").arg(_d->_messageName,content());
  return res;
}

QDomElement SendToStatementModel::scxmlElement(QDomDocument doc)
{
  QDomElement element = doc.createElement(QString("send"));
  if(_d->_messageName != QString("")) element.setAttribute(QString("event"),_d->_messageName);
  if(_d->_target > -1){
    QDomElement param = doc.createElement(QString("param"));
    param.setAttribute(QString("name"),QString("P0rT_GuaRd"));
    param.setAttribute(QString("expr"),QString::number(_d->_target));
    element.appendChild(param);
  }

  QString parenContent = content();
  QStringList paramStrs = parenContent.split(QChar(','),QString::SkipEmptyParts);
  if(paramStrs.size() <= _d->_paramNames.size()){
    QVectorIterator<QString> nameIt = QVectorIterator<QString>(_d->_paramNames);
    for(auto paramStr : paramStrs){
      QDomElement param = doc.createElement(QString("param"));
      param.setAttribute(QString("name"),nameIt.next());
      param.setAttribute(QString("expr"),paramStr);
      element.appendChild(param);
    }
  }
  else{
    //error!
  }
  return element;
}

StatementModel *SendToStatementModel::deepCopy()
{
  auto newStatement = new SendToStatementModel();
  newStatement->setParamNames(_d->_paramNames);
  newStatement->setMessageName(_d->_messageName);
  newStatement->setTarget(_d->_target);
  newStatement->setContent(content());
  newStatement->setType(type());
  return newStatement;
}

}// end namespace statement
}// end namespace base
}// end namespace model
