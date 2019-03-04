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

#include "statementmodel.hpp"
#include <QVector>
#include <QHash>

namespace model{
namespace base{
namespace statement{

class StatementModel::Private
{
  friend class StatementModel;

  StatementType _type;
  QString       _content;
  QString       _collectionNormalStatements;

  Private(StatementType type,
          const QString& content)
    : _type(type),
      _content(content)
  {}
  ~Private(){
  }
};

StatementModel::StatementModel():
  _d(new Private(baseStatement,
                 QString("")))
{

}

StatementModel::StatementModel(StatementType type, const QString& content):
  _d(new Private(type,content))
{

}

StatementModel::~StatementModel()
{
  delete this->_d;
}

void StatementModel::setContent(const QString& content)
{
  _d->_content = content;
}

void StatementModel::setType(StatementType type)
{
  _d->_type = type;
}

const QString& StatementModel::content()
{
  return _d->_content;
}

StatementType StatementModel::type()
{
  return _d->_type;
}

}// end namespace statement
}// end namespace base
}// end namespace model
