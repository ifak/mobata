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
