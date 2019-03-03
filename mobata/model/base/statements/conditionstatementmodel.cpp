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

#include "conditionstatementmodel.hpp"

namespace model{
namespace base{
namespace statement{

class ConditionStatementModel::Private
{
  friend class ConditionStatementModel;

  QVector<QPair<QString,QVector<StatementModel*>*>>  _childStatements;

  Private()
  {}
  Private(QVector<QPair<QString, QVector<StatementModel *> *> > childStatements):
    _childStatements(childStatements){

  }
  ~Private(){
    for(QPair<QString, QVector<StatementModel *> *> vec : _childStatements){
      for(auto exp : *vec.second){
        delete exp;
      }
      delete vec.second;
    }
  }
};

ConditionStatementModel::ConditionStatementModel()
  :StatementModel(StatementType::conditionStatement), _d(new Private())
{

}

ConditionStatementModel::~ConditionStatementModel()
{
  delete this->_d;
}

ConditionStatementModel::ConditionStatementModel(QVector<QPair<QString, QVector<StatementModel *> *> > statements)
  :StatementModel(StatementType::conditionStatement), _d(new Private(statements))
{

}

void ConditionStatementModel::addChild(const QString& condition,
                                       StatementModel *childmodel)
{
  for(QPair<QString, QVector<StatementModel *> *> pair : _d->_childStatements){
    if(pair.first == condition){
      if(childmodel)
        pair.second->append(childmodel);
      return;
    }
  }
  if(childmodel)
    _d->_childStatements.append(QPair<QString,QVector<StatementModel*>*>(condition,new QVector<StatementModel*>({childmodel})));
  else
    _d->_childStatements.append(QPair<QString,QVector<StatementModel*>*>(condition,new QVector<StatementModel*>({})));
}

QVector<QPair<QString, QVector<StatementModel *> *> > ConditionStatementModel::childStatements()
{
  return _d->_childStatements;
}

QVector<StatementModel *>* ConditionStatementModel::childStatements(const QString& cond)
{
  for(QPair<QString, QVector<StatementModel *> *> pair : _d->_childStatements){
    if(pair.first == cond) return pair.second;
  }
  return {};
}

QString ConditionStatementModel::getText()
{
  QString res = QString("");  //if(%0){\n").arg(_d->_childStatements.first().first);
  bool first = true;
  for(QPair<QString, QVector<StatementModel *> *> pair : _d->_childStatements){
    QString key = pair.first;
    if(key != QString("")){
      res +=  QString("%0if(%1){\n").arg(first?QString(""):QString("else "),key);
      first = false;
      auto statements = pair.second;
      for(StatementModel* statement : *statements){
        res += statement->getText();
      }
      res += QString("}\n");
    }
  }
  if(childStatements(QString("")) && childStatements(QString(""))->size()){
    auto statements = childStatements(QString(""));
    res += QString("else{\n");
    for(StatementModel* statement : *statements){
      res += statement->getText();
    }
    res += QString("}");
  }
  res += QString("}");

  int wrongElse = res.indexOf(QString("else "));
  res.remove(wrongElse,5);
  return res;
}

QDomElement ConditionStatementModel::scxmlElement(QDomDocument doc)
{
  QDomElement element = doc.createElement(QString("if"));
  QVectorIterator<QPair<QString,QVector<StatementModel*>*>> pairIt =
      QVectorIterator<QPair<QString,QVector<StatementModel*>*>>(_d->_childStatements);
  if(_d->_childStatements.size()){
    QPair<QString,QVector<StatementModel*>*> pair = pairIt.next();
    element.setAttribute(QString("cond"), pair.first);
    for(StatementModel* statement : *pair.second){
      element.appendChild(statement->scxmlElement(doc));
    }
  }
  while (pairIt.hasNext()) {
    QPair<QString,QVector<StatementModel*>*> pair = pairIt.next();
    QString elementName;
    bool isElse;
    if((isElse = (!pairIt.hasNext() && pair.first == QString("")))){
      elementName = QString("else");
    }
    else elementName = QString("elseif");
    QDomElement elseElement = doc.createElement(elementName);
    if(!isElse)
      elseElement.setAttribute(QString("cond"), pair.first);
    for(StatementModel* statement : *pair.second){
      elseElement.appendChild(statement->scxmlElement(doc));
    }
    element.appendChild(elseElement);
  }
  return element;
}

StatementModel *ConditionStatementModel::deepCopy()
{
  auto newStatement = new ConditionStatementModel();
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
