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
#include <QList>

class QUuid;
class QStandardItem;

namespace model {
namespace base {

class FunctionItem;
class DataTypeItem;

class PropFunctions
{
public:
  typedef QList<FunctionItem*>       FunctionSet;
  typedef QList<FunctionItem const*> ConstFunctionSet;

public:
  PropFunctions(QStandardItem* parentItem);
  virtual ~PropFunctions();

public:
  bool           addFunction(FunctionItem* function,
                              QString *errorString=0);
  FunctionItem*  addFunction(const QString& name,
                             const QString& returnType,
                             const QString &statementBody,
                             QString* errorString=0);
  void           removeFunctionByID(const QUuid& functionUuid);
  void           removeFunction(const QString& functionName);
  FunctionItem*  function(const QString& functionName) const;
  FunctionItem*  function(const QUuid &functionUuid) const;
  FunctionSet    functions() const;
  void           cloneFunctions(PropFunctions* cloneFunctions) const;

public:
  QString functionsDeclString() const;

protected:
  void  resetFunctions();
  void  setFunctionsParentItem(QStandardItem* parent);

private:
  Q_DISABLE_COPY(PropFunctions)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model
