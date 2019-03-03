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

#include "mscstatementitem.hpp"

namespace model{
namespace msc{

class MscStatementItem::Private
{
  friend class MscStatementItem;

  Private(const QString& statement)
    : _statement(statement)
  {}

public:
  ~Private()  {}

private:
  QString _statement;
};

MscStatementItem::MscStatementItem(const MscComponentItem* component,
                                   const QString& statement)
  :	MscStepItem(component),
    _d(new Private(statement))
{
  Q_ASSERT(component);

  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/statement.png")));
  this->setText(this->toString());

}

MscStatementItem::~MscStatementItem()
{
  delete this->_d;
}

const QString& MscStatementItem::statement() const
{
  return this->_d->_statement;
}

void MscStatementItem::setStatement(const QString& statement)
{
  this->_d->_statement=statement;

  return;
}

QString MscStatementItem::toString() const
{
  return _d->_statement;
}

}/// end namespace msc
}/// end namespace model
