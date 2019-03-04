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

#include <QList>

class QStandardItem;

namespace model {
namespace base {

class ParamItem;
class DataTypeItem;

class PropParams
{
public:
  typedef QList<ParamItem const*> ConstParameterSet;
  typedef QList<ParamItem*>       ParameterSet;

public:
  PropParams(QStandardItem* parentItem);
  virtual ~PropParams();

public:
  ParamItem*        addParameter(const QString& name,
                                 const QString &dataType,
                                 QString* errorString=0);
  bool              addParameter(ParamItem* newParam,
                                 QString* errorString=0);

  ParamItem*        parameter(const QString &name);
  ParamItem const*  parameter(const QString &name) const;
  ConstParameterSet params() const;
  ParameterSet      params();

protected:
  void  resetParams();
  void  cloneParams(PropParams* cloneParams) const;
  void  setParamsParentItem(QStandardItem* paramsParentItem);

private:
  Q_DISABLE_COPY(PropParams)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model
