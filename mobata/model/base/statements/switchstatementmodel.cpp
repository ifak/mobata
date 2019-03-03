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

#include "switchstatementmodel.hpp"

namespace model{
namespace base{
namespace statement{

class SwitchStatementModel::Private
{
  friend class SwitchStatementModel;

  QVector<QPair<QString,QVector<StatementModel*>*>>  _childStatements;

  Private()
  {}
  Private(QVector<QPair<QString, QVector<StatementModel *> *> > childStatements):
    _childStatements(childStatements){

  }
  ~Private(){
    for(QPair<QString, QVector<StatementModel *> *> vec : _childStatements){
      for(StatementModel * exp : *vec.second){
        delete exp;
      }
      delete vec.second;
    }
  }
};

SwitchStatementModel::SwitchStatementModel()
  :StatementModel(StatementType::conditionStatement), _d(new Private())
{}

SwitchStatementModel::~SwitchStatementModel()
{
  delete this->_d;
}

SwitchStatementModel::SwitchStatementModel(QVector<QPair<QString, QVector<StatementModel *> *> > statements)
  :StatementModel(StatementType::conditionStatement), _d(new Private(statements))
{

}

void SwitchStatementModel::addChild(const QString& condition,
                                    StatementModel *childmodel)
{
  for(QPair<QString, QVector<StatementModel *> *> pair : _d->_childStatements){
    if(pair.first == condition){
      pair.second->append(childmodel);
      return;
    }
  }
  _d->_childStatements.append(QPair<QString,QVector<StatementModel*>*>(condition,new QVector<StatementModel*>({childmodel})));
}

void SwitchStatementModel::changeCondition(const QString& originalCondition,
                                           const QString& newCondition)
{

  for(QPair<QString, QVector<StatementModel *> *> pair : _d->_childStatements){
    if(pair.first == originalCondition){
      pair.first = newCondition;
      return;
    }
  }
}

QVector<QPair<QString, QVector<StatementModel *> *> > SwitchStatementModel::childStatements()
{
  return _d->_childStatements;
}

QVector<StatementModel *>* SwitchStatementModel::childStatements(const QString& cond)
{
  for(QPair<QString, QVector<StatementModel *> *> pair : _d->_childStatements){
    if(pair.first == cond) return pair.second;
  }
  return {};
}

QString SwitchStatementModel::getText()
{
  QString res = QString("switch(%0){\n").arg(content());
  for(QPair<QString, QVector<StatementModel *> *> pair : _d->_childStatements){
    QString key = pair.first;
    if(key != QString("")){
      res += QString("case %0:{\n").arg(key);
      auto statements = pair.second;
      for(StatementModel* statement : *statements){
        res += statement->getText();
      }
      res += QString("}\n");
    }
  }
  if(childStatements(QString(""))->size()){
    auto statements = childStatements(QString(""));
    res += QString("default{\n");
    for(StatementModel* statement : *statements){
      res += statement->getText();
    }
    res += QString("}");
  }
  res += QString("}");
  return res;
}

QDomElement SwitchStatementModel::scxmlElement(QDomDocument doc)
{
  QDomElement element = doc.createElement(QString("script"));
  QString content = this->content();
  QDomText scriptText = doc.createTextNode(content.replace(QString("=="),QString("===")));
  element.appendChild(scriptText);
  return element;
//  QVectorIterator<QPair<QString,QVector<StatementModel*>*>> pairIt =
//      QVectorIterator<QPair<QString,QVector<StatementModel*>*>>(_d->_childStatements);
//  if(_d->_childStatements.size()){
//    QPair<QString,QVector<StatementModel*>*> pair = pairIt.next();
//    element.setAttribute(QString("cond"), pair.first);
//    for(StatementModel* statement : *pair.second){
//      element.appendChild(statement->scxmlElement(doc));
//    }
//  }
//  while (pairIt.hasNext()) {
//    QPair<QString,QVector<StatementModel*>> pair = pairIt.next();
//    QDomElement elseElement;
//    elseElement.setTagName(QString("elseif"));
//    elseElement.setAttribute(QString("cond"), pair.first);
//    element.appendChild(elseElement);
//    for(StatementModel* statement : pair.second){
//      element.appendChild(statement->scxmlElement(doc));
//    }
//  }
//  if(_d->_childStatements.size()>1){            //last else/elseif (if more than one case)
//    QPair<QString,QVector<StatementModel*>> pair = pairIt.next();
//    QDomElement elseElement;
//    elseElement.setTagName(pair.first == QString("") ? QString("else") : QString("elseif"));
//    elseElement.setAttribute(QString("cond"), pair.first);
//    element.appendChild(elseElement);
//    for(StatementModel* statement : pair.second){
//      element.appendChild(statement->scxmlElement(doc));
//    }
//  }
//  return element;
}

StatementModel *SwitchStatementModel::deepCopy()
{
  auto newStatement = new SwitchStatementModel();
  for(QPair<QString,QVector<StatementModel*>*> childBranch : _d->_childStatements){
    for(StatementModel* childStatement : *childBranch.second){
      newStatement->addChild(childBranch.first,childStatement->deepCopy());
    }
  }
  newStatement->setContent(content());
  newStatement->setType(type());
  return newStatement;
}

}// end namespace statement
}// end namespace base
}// end namespace model
