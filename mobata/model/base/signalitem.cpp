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

#include "signalitem.hpp"

#include "datatypeitem.hpp"
#include "paramitem.hpp"
#include "basemodel.hpp"

#include "../../utils/functors.hpp"

using namespace utils;

namespace model{
namespace base{

SignalItem::SignalItem(const QString& name,
                       const QUuid &uuid)
  : ModelItem(uuid),
    PropParams(this),
    prop::NameProperty(name)
{
  this->setIcon(QIcon(QLatin1String(":mobata/images/base/signal.png")));
  this->setText(this->name());
}

SignalItem::~SignalItem()
{}

SignalItem* SignalItem::clone() const
{
  SignalItem* cloneSignalItem = new SignalItem(this->name());
  this->cloneParams(cloneSignalItem);

  return cloneSignalItem;
}

QString SignalItem::toString() const
{
  QString declaration=this->name();

  declaration+=QStringLiteral("(");

  ///parameters////////////////////////
  int pos=0;
  for(ParamItem const* param : this->params())
  {
    if(pos)
      declaration+=QStringLiteral(",");

    QString paramType=param->dataType();
    if(paramType.size())
      declaration+=paramType;
    else
      declaration+=QStringLiteral("unknown_type");

    declaration+=QStringLiteral(" ")+param->name();

    ++pos;
  }

  declaration+=QStringLiteral(")");

  return declaration;
}

}///end namespace base
}///end namespace model
