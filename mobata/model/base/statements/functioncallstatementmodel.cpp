#include "functioncallstatementmodel.hpp"

namespace model{
namespace base{
namespace statement{

FunctionCallStatementModel::FunctionCallStatementModel():
  StatementModel(StatementType::functionCall)
{

}

QString FunctionCallStatementModel::getText()
{
  return content() + QString("\n");
}

QDomElement FunctionCallStatementModel::scxmlElement(QDomDocument doc)
{
  QDomElement element = doc.createElement(QString("script"));
  QString content = this->content();
  QDomText scriptText = doc.createTextNode(content.replace(QString("=="),QString("===")));
  element.appendChild(scriptText);
  return element;
}

StatementModel *FunctionCallStatementModel::deepCopy()
{
  auto newStatement = new FunctionCallStatementModel();
  newStatement->setContent(content());
  newStatement->setType(type());
  return newStatement;
}

}// end namespace statement
}// end namespace base
}// end namespace model
