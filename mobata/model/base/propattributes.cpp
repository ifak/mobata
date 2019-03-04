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

#include "propattributes.hpp"

#include "attributeitem.hpp"

#include "../../utils/functors.hpp"

namespace model {
namespace base {

class PropAttributes::Private
{
  friend class PropAttributes;

  Private()
    : _attributesItem(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*	_attributesItem;
};

PropAttributes::PropAttributes(QStandardItem* parentItem)
  : _d(new Private())
{
  Q_ASSERT(parentItem);
  this->setAttributesParentItem(parentItem);
}

PropAttributes::~PropAttributes()
{
  delete this->_d;
}

void PropAttributes::resetAttributes()
{
  if(this->_d->_attributesItem)
    this->_d->_attributesItem->removeRows(0, this->_d->_attributesItem->rowCount());

  return;
}

void PropAttributes::cloneAttributes(PropAttributes* cloneAttributes) const
{
  Q_ASSERT(cloneAttributes);

  bool result = false;
  for(AttributeItem const* attribute : this->attributes())
  {
    AttributeItem* cloneAttribute = new AttributeItem(attribute->name(),
                                                      attribute->dataType(),
                                                      attribute->initValue());
    result = cloneAttributes->addAttribute(cloneAttribute);
    Q_ASSERT(result);
  }

  return;
}

void PropAttributes::setAttributesParentItem(QStandardItem* parent)
{
  Q_ASSERT(parent);

  if(this->_d->_attributesItem)
    return;

  this->_d->_attributesItem=new QStandardItem(QIcon(":/mobata/images/base/manyattribute.png"),
                                              QLatin1String("attributes"));
  this->_d->_attributesItem->setFlags(this->_d->_attributesItem->flags() & ~Qt::ItemIsEditable);
  parent->appendRow(this->_d->_attributesItem);

  return;
}

bool PropAttributes::addAttribute(AttributeItem *attribute,
                                  QString* errorString)
{
  Q_ASSERT(this->_d->_attributesItem);

  if(!attribute)
    return false;

  if(this->attribute(attribute->name()))
  {
    utils::AddPtrString(errorString)<<QObject::tr((QLatin1String("There is already an attribute '")
                                                   +attribute->name().toLatin1()
                                                   +QLatin1String("' available!")).toLatin1());
    return false;
  }

  this->_d->_attributesItem->appendRow(attribute);

  return true;
}

AttributeItem* PropAttributes::addAttribute(const QString& name,
                                            const QString& dataType,
                                            const QString& initValue,
                                            QString *errorString)
{
  Q_ASSERT(this->_d->_attributesItem);

  if(this->attribute(name))
  {
    utils::AddPtrString(errorString)<<QObject::tr((QLatin1String("There is already an attribute with name '")
                                                   +name
                                                   +QLatin1String("' available!")).toLatin1());
    return 0;
  }

  AttributeItem* newAttributeItem=new AttributeItem(name,
                                                    dataType,
                                                    initValue);
  this->_d->_attributesItem->appendRow(newAttributeItem);
  newAttributeItem->setText(newAttributeItem->toString());

  return newAttributeItem;
}

void PropAttributes::removeAttributeByID(const QUuid& attributeUuid)
{
  Q_ASSERT(this->_d->_attributesItem);

  AttributeItem* remAttribute = this->attribute(attributeUuid);
  if(remAttribute)
    this->_d->_attributesItem->removeRow(remAttribute->row());

  return;
}

void PropAttributes::removeAttribute(const QString& attributeName)
{
  Q_ASSERT(this->_d->_attributesItem);

  AttributeItem* remAttribute = this->attribute(attributeName);
  if(remAttribute)
    this->_d->_attributesItem->removeRow(remAttribute->row());

  return;
}

AttributeItem* PropAttributes::attribute(const QString &attrName) const
{
  for(AttributeItem* attrItem : this->attributes())
    if(attrItem->name().compare(attrName, Qt::CaseInsensitive)==0)
      return attrItem;

  return 0;
}

AttributeItem* PropAttributes::attribute(const QUuid& attrUuid) const
{
  for(AttributeItem* attrItem : this->attributes())
    if(attrItem->uuid()==attrUuid)
      return attrItem;

  return 0;
}

PropAttributes::AttributeSet PropAttributes::attributes() const
{
  AttributeSet attributes;
  if(!this->_d->_attributesItem)
    return attributes;

  int end=this->_d->_attributesItem->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChildItem=this->_d->_attributesItem->child(i);
    AttributeItem* attribute=utils::simple_cast<AttributeItem*>(currChildItem);
    Q_ASSERT(attribute);
    attributes.append(attribute);
  }

  return attributes;
}

QString PropAttributes::attributesDeclString() const
{
  QString declString=QStringLiteral("");

  for(AttributeItem const* attribute :this->attributes())
  {
    declString+=attribute->toString()
                +QStringLiteral(";");
    declString+=QStringLiteral("\n");
  }
  if(!declString.isEmpty())
    declString.remove(declString.size(),1);//last "\n"

  return declString;
}

} // namespace base
} // namespace model
