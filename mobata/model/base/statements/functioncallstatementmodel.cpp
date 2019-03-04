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
