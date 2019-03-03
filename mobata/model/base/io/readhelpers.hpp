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

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <QObject>

namespace model {
namespace base {
namespace io {

//helper/////
template <class PropertyType> inline
void jsonValue2propertyType(const QJsonValue& jsonValue,
                            PropertyType* property)
{
  Q_ASSERT(property);

  *property = PropertyType(jsonValue.toString());

  return;
}

template <> inline
void jsonValue2propertyType<bool>(const QJsonValue& jsonValue,
                                  bool* property)
{
  Q_ASSERT(property);

  *property = bool(jsonValue.toBool());

  return;
}

template <> inline
void jsonValue2propertyType<int>(const QJsonValue& jsonValue,
                                 int* property)
{
  Q_ASSERT(property);

  *property = int(jsonValue.toInt());;

  return;
}

template <> inline
void jsonValue2propertyType<double>(const QJsonValue& jsonValue,
                                    double* property)
{
  Q_ASSERT(property);

  *property = double(jsonValue.toDouble());

  return;
}

template <class PropertyType> inline
bool readProperty(const QJsonObject& jsonObject,
                  const QString& propertyKey,
                  PropertyType* property,
                  QString* errorMessage=nullptr)
{
  Q_ASSERT(property);

  QJsonValue value = jsonObject.value(propertyKey);
  if(value == QJsonValue::Undefined)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("property '%1' is not available!")
                       .arg(propertyKey);
    return  false;
  }

  jsonValue2propertyType<PropertyType>(value, property);

  return true;
}

template <class PropertyType_1,
          class PropertyType_2> inline
bool readProperty_2(const QJsonObject& jsonObject,
                    const QString& propertyKey_1,
                    PropertyType_1* property_1,
                    const QString& propertyKey_2,
                    PropertyType_2* property_2,
                    QString* errorMessage=nullptr)
{
  Q_ASSERT(property_1);
  Q_ASSERT(property_2);

  bool result = readProperty<PropertyType_1>(jsonObject,
                                             propertyKey_1,
                                             property_1,
                                             errorMessage);
  if(!result)
    return false;

  result = readProperty<PropertyType_2>(jsonObject,
                                        propertyKey_2,
                                        property_2,
                                        errorMessage);
  if(!result)
    return false;

  return true;
}

template <class PropertyType_1,
          class PropertyType_2,
          class PropertyType_3> inline
bool readProperty_3(const QJsonObject& jsonObject,
                    const QString& propertyKey_1,
                    PropertyType_1* property_1,
                    const QString& propertyKey_2,
                    PropertyType_2* property_2,
                    const QString& propertyKey_3,
                    PropertyType_3* property_3,
                    QString* errorMessage=nullptr)
{
  Q_ASSERT(property_1);
  Q_ASSERT(property_2);
  Q_ASSERT(property_3);

  bool result = readProperty_2<PropertyType_1, PropertyType_2>(jsonObject,
                                                               propertyKey_1,
                                                               property_1,
                                                               propertyKey_2,
                                                               property_2,
                                                               errorMessage);
  if(!result)
    return false;

  result = readProperty<PropertyType_3>(jsonObject,
                                        propertyKey_3,
                                        property_3,
                                        errorMessage);
  if(!result)
    return false;

  return true;
}

template <class PropertyType_1,
          class PropertyType_2,
          class PropertyType_3,
          class PropertyType_4> inline
bool readProperty_4(const QJsonObject& jsonObject,
                    const QString& propertyKey_1,
                    PropertyType_1* property_1,
                    const QString& propertyKey_2,
                    PropertyType_2* property_2,
                    const QString& propertyKey_3,
                    PropertyType_3* property_3,
                    const QString& propertyKey_4,
                    PropertyType_4* property_4,
                    QString* errorMessage=nullptr)
{
  Q_ASSERT(property_1);
  Q_ASSERT(property_2);
  Q_ASSERT(property_3);
  Q_ASSERT(property_4);

  bool result = readProperty_2<PropertyType_1, PropertyType_2>(jsonObject,
                                                               propertyKey_1,
                                                               property_1,
                                                               propertyKey_2,
                                                               property_2,
                                                               errorMessage);
  if(!result)
    return false;

  result = readProperty_2<PropertyType_3, PropertyType_4>(jsonObject,
                                                          propertyKey_3,
                                                          property_3,
                                                          propertyKey_4,
                                                          property_4,
                                                          errorMessage);
  if(!result)
    return false;

  return true;
}

inline
bool readJsonArray(const QJsonObject& jsonObject,
                   const QString& arrayKey,
                   QJsonArray* jsonArray,
                   QString* errorMessage=nullptr)
{
  Q_ASSERT(jsonArray);

  QJsonValue value = jsonObject.value(arrayKey);
  if(value == QJsonValue::Undefined)
  {
    if(errorMessage)
      *errorMessage += QObject::tr("json-array '%1' is not available!")
                       .arg(arrayKey);
    return  false;
  }
  else if(!value.isArray())
  {
    if(errorMessage)
      *errorMessage += QObject::tr("json value of '%1' is not a json-array!")
                       .arg(arrayKey);
    return  false;
  }

  *jsonArray = value.toArray();

  return true;
}

template<class PropertyModel, class ReadPropertyFunctor> inline
bool readObjectArray(const QJsonObject& jsonObject,
                     const QString& arrayKey,
                     PropertyModel* propertyModel,
                     ReadPropertyFunctor propertyFunction,
                     QString* errorMessage)
{
  Q_ASSERT(propertyModel);

  QJsonArray jsonArray;
  bool result = readJsonArray(jsonObject, arrayKey,
                              &jsonArray, errorMessage);
  if(!result)
    return false;

  for(const QJsonValue& jsonValue: jsonArray)
  {
    if(!jsonValue.isObject())
    {
      if(errorMessage)
        *errorMessage += QObject::tr("json value of array '%1' "
                                     "is not a json-object")
                         .arg(arrayKey);
      return false;
    }
    QJsonObject jsonObject=jsonValue.toObject();

    result = propertyFunction(jsonObject, propertyModel, errorMessage);
    if(!result)
      return false;
  }

  return true;
}

} // namespace io
} // namespace base
} // namespace model
