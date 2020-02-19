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

#include "paramitem.hpp"

namespace model{
namespace base{

class MOBATASHARED_EXPORT AttributeItem
    : public ParamItem
{
public:
  AttributeItem(const QString& name,
                const QString& dataType,
                const QString& initValue,
                const QUuid& uuid=QUuid::createUuid());
  virtual ~AttributeItem();

public:
  const	QString&	initValue() const;
  void setInitValue(const QString& initValue);

  virtual	QString	toString() const;

private:
  Q_DISABLE_COPY(AttributeItem)
  class Private;
  QScopedPointer<Private> _d;
};

}///end namespace base
}///end namespace model
