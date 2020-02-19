/*
 * This file is part of mobata.
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

#include <QString>
#include <QDomDocument>


namespace model{
namespace base{
namespace statement {

enum StatementType{
  baseStatement,
  functionCall,
  attributeAssignment,
  messageSend,
  switchStatement,
  conditionStatement
};

class StatementModel
{
public:
  StatementModel();
  StatementModel(StatementType type,
                 const QString& content = QString(""));
  virtual ~StatementModel();
  void setContent(const QString& content);
  void setType(StatementType type);

  const QString& content();
  StatementType type();
  virtual QString getText() = 0;
  virtual QDomElement scxmlElement(QDomDocument doc) = 0;
  virtual StatementModel* deepCopy() = 0;

private:
  class Private;
  Private* _d;
};

}// end namespace statement
}// end namespace base
}// end namespace model
