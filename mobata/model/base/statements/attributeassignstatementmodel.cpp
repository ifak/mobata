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

#include "attributeassignstatementmodel.hpp"

namespace model{
namespace base{
namespace statement{

class AttributeAssignStatementModel::Private
{
  friend class AttributeAssignStatementModel;

  QString       _attributeName;
  QString       _attributeValue;

  Private(const QString& attributeName = QLatin1String(""),
          const QString& attributeValue = QLatin1String("")):
    _attributeName(attributeName),_attributeValue(attributeValue)
  {}
};

AttributeAssignStatementModel::AttributeAssignStatementModel():
  StatementModel(StatementType::attributeAssignment),_d(new Private())
{}

AttributeAssignStatementModel::~AttributeAssignStatementModel()
{
  delete this->_d;
}

QString AttributeAssignStatementModel::attributeName() const
{
  return _d->_attributeName;
}

QString AttributeAssignStatementModel::attributeValue() const
{
  return _d->_attributeValue;
}

void AttributeAssignStatementModel::setAttributeName(const QString& attributeName) const
{
  _d->_attributeName = attributeName;
}

void AttributeAssignStatementModel::setAttributeValue(const QString& attributeValue) const
{
  _d->_attributeValue = attributeValue;
}

StatementModel *AttributeAssignStatementModel::deepCopy()
{
  auto newStatement = new AttributeAssignStatementModel();
  newStatement->setAttributeName(_d->_attributeName);
  newStatement->setAttributeValue(_d->_attributeValue);
  newStatement->setContent(content());
  newStatement->setType(type());
  return newStatement;
}

QString AttributeAssignStatementModel::getText()
{
  return content() + QString("\n");
}

///<assign location="initState" expr="_event.data.initState"/>
QDomElement AttributeAssignStatementModel::scxmlElement(QDomDocument doc)
{
  QDomElement element = doc.createElement(QString("assign"));
  element.setAttribute(QString("location"),_d->_attributeName);
  element.setAttribute(QString("expr"),_d->_attributeValue);
  return element;
}

}// end namespace statement
}// end namespace base
}// end namespace model
