#include "statichelpers.hpp"

#include "basemodel.hpp"
#include "signalitem.hpp"
#include "paramitem.hpp"
#include "datatypeitem.hpp"
#include "attributeitem.hpp"
#include "propattributes.hpp"

#include "../../parser/decl/triggerdeclaration.hpp"
#include "../../parser/decl/transitiondeclaration.hpp"

#include <QSet>
#include <QString>
#include <QHostAddress>

#include <stdexcept>

#include "../../memory_leak_start.hpp"

namespace model{
namespace base{

using namespace ::parser;
using namespace prop;

SignalItem const* StaticHelpers::detectSignal(BaseModel const* baseModel,
                                              const decl::TriggerDeclaration &triggerDecl)
{
  if(!baseModel)
    return 0;

  foreach(SignalItem const* signalItem, baseModel->getSignals())
  {
    if(signalItem->name()!=triggerDecl.signalName)
      continue;

    if(signalItem->params().size()!=triggerDecl.parameters.size())
      continue;

    if(signalItem->params().size()==0
       &&triggerDecl.parameters.size()==0)
      return signalItem;

    int pos=0;
    bool success=true;
    foreach(ParamItem const* signalParam, signalItem->params())
    {
      const decl::TriggerDeclaration::Param& triggerParam=triggerDecl.parameters.at(pos);
      DataTypeItem const* triggerParamType=detectTypeDeclaration(baseModel, triggerParam.type);
      if(!triggerParamType)
        throw std::runtime_error(QObject::tr("type for param '%1' "
                                             "of trigger '%2' not found!")
                                 .arg(triggerParam.name)
                                 .arg(triggerDecl.toString())
                                 .toStdString());
      if(signalParam->dataType()!=triggerParamType)
      {
        success=false;
        break;
      }

      ++pos;
    }

    if(success)
      return signalItem;
  }

  return 0;
}

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

TypeEnum StaticHelpers::parserTypeEnum2modelTypeEnum(parser::decl::TypeEnum parserTypeEnum)
{
  if(parserTypeEnum==parser::decl::Bool)
    return Bool;

  if(parserTypeEnum==parser::decl::Enum)
    return Enum;

  if(parserTypeEnum==parser::decl::Int)
    return Int;

  if(parserTypeEnum==parser::decl::Real)
    return Real;

  if(parserTypeEnum==parser::decl::String)
    return String;

  return Int;
}

bool StaticHelpers::isSemanticallyEqual(DataTypeItem const* typeItem,
                                        const decl::TypeDeclaration& typeDecl)
{
  if(typeItem->typeEnum() != StaticHelpers::parserTypeEnum2modelTypeEnum(typeDecl.typeEnum))
    return false;

  if(typeItem->getLowest() != typeDecl.lowest)
    return false;

  if(typeItem->getHighest() != typeDecl.highest)
    return false;

  if(typeItem->getLiterals().size() != typeDecl.literals.size())
    return false;

  foreach(const QString& literal, typeItem->getLiterals())
  {
    if(std::find(typeDecl.literals.begin(),
                 typeDecl.literals.end(),
                 literal) == typeDecl.literals.end())
      return false;
  }

  return true;
}

DataTypeItem const* StaticHelpers::detectTypeDeclaration(BaseModel const* baseModel,
                                                     const decl::TypeDeclaration& typeDecl)
{
  foreach(DataTypeItem const* typeItem, baseModel->dataTypes())
  {
    if(!typeDecl.name.isEmpty()
       && typeItem->name()==typeDecl.name)
      return typeItem;

    if(isSemanticallyEqual(typeItem, typeDecl))
      return typeItem;
  }

  return 0;
}

const SignalItem *StaticHelpers::detectSignal(const QString &triggerDeclString,
                                              const BaseModel *baseModel)
{
  typedef parser::decl::TriggerDeclaration	TriggerDeclaration;

  TriggerDeclaration triggerDecl=TriggerDeclaration::parse(triggerDeclString);
  return detectSignal(baseModel, triggerDecl);
}

}///end namespace base
}///end namespace model
