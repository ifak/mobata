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

#include "rootstatementmodel.hpp"
#include <QVector>

namespace model{
namespace base{
namespace statement{

class RootStatementModel::Private
{
  friend class RootStatementModel;

  QVector<StatementModel*>  _childStatements;

  Private()
  {}
  Private(QVector<StatementModel*> childStatements):
    _childStatements(childStatements){

  }
  ~Private(){
    for(auto exp : _childStatements){
      delete exp;
    }
  }
};


RootStatementModel::RootStatementModel():
  _d(new Private())
{

}

RootStatementModel::~RootStatementModel()
{
 delete this->_d;
}

RootStatementModel::RootStatementModel(QVector<StatementModel*> statements):
  StatementModel(),_d(new Private(statements))
{

}

void RootStatementModel::addChild(StatementModel *childmodel)
{
  _d->_childStatements.append(childmodel);
}

QVector<StatementModel *> RootStatementModel::childStatements()
{
  return _d->_childStatements;
}

QString RootStatementModel::getText()
{
  QString res("");
  for(StatementModel* statement : _d->_childStatements){
    res+=statement->getText();
  }
  return res;
}

QDomElement RootStatementModel::scxmlElement(QDomDocument doc)
{
  QDomElement element = doc.createElement(QString("root"));
  for(StatementModel* child : _d->_childStatements){
    element.appendChild(child->scxmlElement(doc));
  }
  return element;
}

StatementModel *RootStatementModel::deepCopy()
{
  auto newStatement = new RootStatementModel();
  for(StatementModel* childStatement : _d->_childStatements){
      newStatement->addChild(childStatement->deepCopy());
  }
  newStatement->setContent(content());
  newStatement->setType(type());
  return newStatement;
}

}// end namespace statement
}// end namespace base
}// end namespace model
