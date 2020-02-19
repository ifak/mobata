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

#include "../../memory_leak_start.hpp"

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
