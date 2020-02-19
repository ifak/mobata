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
#include "../../prop/types.hpp"

class QHostAddress;

namespace model{
namespace base{

using prop::TypeEnum;

class DataTypeItem;
class SignalItem;
class BaseModel;
class PropAttributes;

class MOBATASHARED_EXPORT StaticHelpers
{
public:
  static
  bool readAddressAttribute(PropAttributes const* propAttributes,
                            const QString& attributeName,
                            QHostAddress* attributeValue,
                            QString* errorString);

  static
  bool readIntAttribute(PropAttributes const* propAttributes,
                        const QString& attributeName,
                        int* attributeValue,
                        QString* errorString);
};

}//////end namespace base
}///end namespace model
