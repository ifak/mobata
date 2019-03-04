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

class QUuid;
class QStandardItem;

namespace model {
namespace base {

class AttributeItem;
class DataTypeItem;

class PropAttributes
{
public:
  typedef QList<AttributeItem*>       AttributeSet;
  typedef QList<AttributeItem const*> ConstAttributeSet;

public:
  PropAttributes(QStandardItem* parentItem);
  virtual ~PropAttributes();

public:
  bool            addAttribute(AttributeItem* attribute,
                               QString *errorString=0);
  AttributeItem*  addAttribute(const QString& name,
                               const QString& dataType,
                               const QString& initValue,
                               QString* errorString=0);
  void            removeAttributeByID(const QUuid& attributeUuid);
  void            removeAttribute(const QString& attributeName);
  AttributeItem*  attribute(const QString& attrName) const;
  AttributeItem*  attribute(const QUuid &attrUuid) const;
  AttributeSet    attributes() const;
  void            cloneAttributes(PropAttributes* cloneAttributes) const;

public:
  QString attributesDeclString() const;

protected:
  void  resetAttributes();
  void  setAttributesParentItem(QStandardItem* parent);

private:
  Q_DISABLE_COPY(PropAttributes)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model
