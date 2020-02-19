#include "combuilddeclmodel.hpp"

#include "../base/datatypeitem.hpp"
#include "../base/signalitem.hpp"
#include "../base/portitem.hpp"
#include "../base/attributeitem.hpp"
#include "../base/statichelpers.hpp"

#include "functors.hpp"
#include "declmodel.hpp"
#include "transitionitem.hpp"
#include "placeitem.hpp"
#include "junctionitem.hpp"
#include "junctionarc.hpp"
#include "junctionarc.hpp"

#include "../../parser/decl/declarations.hpp"

#include <QDebug>

#include "../../memory_leak_start.hpp"

namespace model{
namespace spenat{

ComBuildDeclModel::ComBuildDeclModel(DeclModel* declModel,
                                     const parser::decl::Declarations& declText)
  :	_declModel(declModel), _declText(declText)
{}

bool ComBuildDeclModel::execute(QString* errorString)
{
  Q_ASSERT(this->_declModel);

  this->_declModel->resetTextDecl();

  return this->processText(errorString);
}

bool ComBuildDeclModel::processText(QString* errorString)
{
  using namespace parser::decl;
  using namespace base;

  foreach(const parser::decl::TypeDeclaration& typeDeclaration,
          this->_declText.getTypeDeclarations())
  {
    DataTypeItem* newTypeItem=this->_declModel->addDataType(typeDeclaration.name,
                                                            typeDeclaration.uuid(),
                                                            errorString);
    if(!newTypeItem)
      return false;

    newTypeItem->setTypeEnum(StaticHelpers::parserTypeEnum2modelTypeEnum(typeDeclaration.typeEnum));
    newTypeItem->setLowest(typeDeclaration.lowest);
    newTypeItem->setHighest(typeDeclaration.highest);
    foreach(const QString& literal, typeDeclaration.literals)
      newTypeItem->addLiteral(literal);
    newTypeItem->setText(newTypeItem->typeDeclString());
  }

  foreach(const parser::decl::SignalDeclaration& signalDecl,
          this->_declText.getSignalDeclarations())
  {
    base::SignalItem* newSignal=this->_declModel->addSignal(signalDecl.signalName,
                                                            errorString);
    if(!newSignal)
      return false;

    foreach(const parser::decl::Parameter& declParam, signalDecl.parameters)
    {
      DataTypeItem const* paramType=this->_declModel->dataType(declParam.typeUuid);
      Q_ASSERT(paramType);
      base::ParamItem* param=newSignal->addParameter(declParam.name,
                                                     paramType,
                                                     errorString);
      Q_ASSERT(param);
      param->setText(param->toString());
    }
  }

  foreach(const parser::decl::PortDeclaration& portDeclaration,
          this->_declText.getPortDeclarations())
  {
    bool result = this->_declModel->addPort(portDeclaration.name, errorString);
    if(!result)
      return false;
  }

  foreach(const parser::decl::AttributeDeclaration& attrDecl,
          this->_declText.getAttributeDeclarations())
  {
    DataTypeItem const* paramType=this->_declModel->dataType(attrDecl.typeUuid);
    Q_ASSERT(paramType);
    bool result = this->_declModel->addAttribute(attrDecl.name,
                                                 paramType,
                                                 attrDecl.initValue,
                                                 errorString);
    if(!result)
      return false;
  }

  return true;
}

}///end namespace model
}///end namespace spenat
