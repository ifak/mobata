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

#include "../../mobata_global.hpp"

#include "modelitem.hpp"
#include "../../prop/typeproperty.hpp"
#include "../../prop/nameproperty.hpp"

namespace model{
namespace base{

class MOBATASHARED_EXPORT DataTypeItem
    : public ModelItem,
    public prop::TypeProperty,
    public prop::NameProperty
{
public:
  DataTypeItem(const QString &name=QLatin1String(""),
               const QUuid& uuid=QUuid::createUuid());
  virtual ~DataTypeItem();

public:
  virtual QString toString() const;

private:
  Q_DISABLE_COPY(DataTypeItem)
};

}//////end namespace base
}///end namespace model
