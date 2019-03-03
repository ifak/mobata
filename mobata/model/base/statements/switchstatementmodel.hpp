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

#pragma once

#include "statementmodel.hpp"
#include <QPair>
#include <QVector>

namespace model{
namespace base{
namespace statement {

class SwitchStatementModel : public StatementModel
{
public:
  SwitchStatementModel();
  ~SwitchStatementModel();
  SwitchStatementModel(QVector<QPair<QString,QVector<StatementModel *>*>> statements);

public:
  void addChild(const QString& condition,StatementModel* childmodel);
  void changeCondition(const QString& originalCondition, const QString& newCondition);

  QVector<QPair<QString, QVector<StatementModel *> *> > childStatements();
  QVector<StatementModel *> *childStatements(const QString& cond);

  QString getText();
  QDomElement scxmlElement(QDomDocument doc);
  StatementModel* deepCopy();

private:
  class Private;
  Private* _d;

};

}// end namespace statement
}// end namespace base
}// end namespace model
