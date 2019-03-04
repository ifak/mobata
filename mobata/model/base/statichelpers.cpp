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

#include "statichelpers.hpp"

#include "basemodel.hpp"
#include "signalitem.hpp"
#include "paramitem.hpp"
#include "datatypeitem.hpp"
#include "attributeitem.hpp"
#include "propattributes.hpp"

#include <QSet>
#include <QString>
#include <QHostAddress>

#include <stdexcept>

namespace model{
namespace base{

using namespace prop;

bool StaticHelpers::readAddressAttribute(const PropAttributes* propAttributes,
                                         const QString& attributeName,
                                         QHostAddress* attributeValue,
                                         QString* errorString)
{
  Q_ASSERT(propAttributes);
  Q_ASSERT(attributeValue);

  AttributeItem const* addressAttribute=propAttributes->attribute(attributeName);
  if(!addressAttribute)
  {
    QString errorMessage = QObject::tr("no '%1' property defined!")
                           .arg(attributeName);
    if(errorString)
      *errorString += errorMessage;
    return false;
  }

  QString addressString = addressAttribute->initValue();
  if(addressString == QStringLiteral("localhost")
     || addressString==QStringLiteral("LocalHost"))
    *attributeValue = QHostAddress::LocalHost;
  else if(!(*attributeValue).setAddress(addressString))
  {
    QString errorMessage = QObject::tr("'%1' is no valid ip address "
                                       "for attribute '%2'!")
                           .arg(addressString)
                           .arg(attributeName);
    if(errorString)
      *errorString += errorMessage;

    return false;
  }

  return true;
}

bool StaticHelpers::readIntAttribute(const PropAttributes* propAttributes,
                                     const QString& attributeName,
                                     int* attributeValue,
                                     QString* errorString)
{
  Q_ASSERT(propAttributes);
  Q_ASSERT(attributeValue);

  AttributeItem const* intAttribute=propAttributes->attribute(attributeName);
  if(!intAttribute)
  {
    QString errorMessage = QObject::tr("no '%1' property defined!")
                           .arg(attributeName);
    if(errorString)
      *errorString += errorMessage;
    return false;
  }

  bool success = true;
  (*attributeValue) = intAttribute->initValue().toInt(&success);
  if(!success)
  {
    QString errorMessage = QObject::tr("'%1' is no valid int value "
                              "for attribute '%2'!")
                           .arg(intAttribute->initValue())
                           .arg(attributeName);
    if(errorString)
      *errorString += errorMessage;

    return false;
  }

  return true;
}


}///end namespace base
}///end namespace model
