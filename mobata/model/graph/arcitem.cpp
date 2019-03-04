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

#include "arcitem.hpp"

#include "nodeitem.hpp"

namespace model{
namespace graph{

class ArcItem::Private
{
  friend class ArcItem;

  Private(NodeItem *source,
          NodeItem *target)
    :	_source(source), _target(target)
  {}

public:
  ~Private()
  {}

private:
  NodeItem* _source;
  NodeItem* _target;
};

ArcItem::ArcItem(NodeItem *source,
                 NodeItem *target,
                 const QUuid arcUuid)
  :	ModelItem(arcUuid),
    _d(new Private(source, target))
{
  this->setText(this->toString());
  this->setIcon(QIcon(QLatin1String(":mobata/images/msc/edge.png")));
}

ArcItem::~ArcItem()
{}

NodeItem* ArcItem::source() const
{
  return this->_d->_source;
}

NodeItem* ArcItem::target() const
{
  return this->_d->_target;
}

void ArcItem::setSource(NodeItem* source)
{
  this->_d->_source=source;

  this->setText(this->toString());

  return;
}

void ArcItem::setTarget(NodeItem* target)
{
  this->_d->_target=target;

  this->setText(this->toString());

  return;
}

QString ArcItem::toString() const
{
  QString arcString=QStringLiteral("");

  if(this->_d->_source)
    arcString+=this->_d->_source->toString();
  else
    arcString+=QObject::tr("###");

  arcString+=QStringLiteral("->");

  if(this->_d->_target)
    arcString+=this->_d->_target->toString();
  else
    arcString+=QObject::tr("###");

  return arcString;
}

}///end namespace graph
}///end namespace model
