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

#include "modelitem.hpp"

#include "basemodel.hpp"

#include "../../utils/functors.hpp"

#include <QDebug>

namespace model{
namespace base{

struct Property
{
  Property()
    : index(-1), item(nullptr)
  {}

  Property(const int indexParam,
           QStandardItem* valueParam)
    : index(indexParam), item(valueParam)
  {
    Q_ASSERT(item);
  }

  const Property& operator =(const Property& rhs)
  {
    if(this!=&rhs)
    {
      this->index=rhs.index;
      this->item=rhs.item;
    }

    return *this;
  }

  int             index;
  QStandardItem*  item;
};

typedef QHash<QString, Property>	PropertyMap;

class ModelItem::Private
{
  friend class ModelItem;

public:
  Private(const QUuid& uuid)
    : _uuid(uuid)
  {}

private:
  QUuid         _uuid;
};

ModelItem::ModelItem(const QUuid &uuid)
  : _d(new Private(uuid))
{
  ///insert this as declaration-property
  this->setData(QLatin1String(""), Qt::DisplayRole);
  this->setFlags(this->flags()  & ~Qt::ItemIsEditable);

  this->setText(this->toString());
}

ModelItem::~ModelItem()
{
  delete this->_d;
}

const QUuid& ModelItem::uuid() const
{
  return this->_d->_uuid;
}

void ModelItem::setUuid(const QUuid uuid)
{
  this->_d->_uuid=uuid;

  return;
}

QString ModelItem::toString() const
{
  return QStringLiteral("");
}

BaseModel const* ModelItem::getModel() const
{
  return utils::simple_cast<BaseModel const*>(this->model());
}

}///end namespace base
}///end namespace model
