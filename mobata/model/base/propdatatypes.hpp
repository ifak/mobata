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
#include <QUuid>

class QStandardItem;

namespace model {
namespace base {

class DataTypeItem;

class PropDataTypes
{
public:
  typedef QList<DataTypeItem*>        DataTypeSet;
  typedef QList<DataTypeItem const*>  ConstDataTypeSet;

public:
  PropDataTypes(QStandardItem* parentItem);
  virtual ~PropDataTypes();

public:
  void  initStandardDataTypes();

public:
  DataTypeItem*       addDataType(const QString& name,
                                  QString* errorString=0);
  DataTypeItem*       addDataType(const QString& name,
                                  const QUuid& uuid,
                                  QString* errorString=0);
  bool                addDataType(DataTypeItem* newType,
                                  QString* errorString=0);
  void                removeDataTypeByID(const QUuid& dataTypeUuid);
  void                removeDataType(const QString& dataTypeName);
  DataTypeItem*       dataTypeByID(const QUuid& typeUuid);
  DataTypeItem const* dataTypeByID(const QUuid& typeUuid) const;
  DataTypeItem*       dataType(const QString& typeName);
  DataTypeItem const* dataType(const QString& typeName) const;
  DataTypeSet         dataTypes();
  ConstDataTypeSet    dataTypes() const;
  void                cloneDataTypes(PropDataTypes* cloneDataTypes) const;

public:
  bool  hasEnumValue(const QString& enumValue) const;

protected:
  void  resetDataTypes();
  void  setDataTypesParentItem(QStandardItem* typesParentItem);

private:
  Q_DISABLE_COPY(PropDataTypes)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model
