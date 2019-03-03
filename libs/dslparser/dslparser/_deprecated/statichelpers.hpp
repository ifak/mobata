#ifndef MODEL_BASE_STATICHELPERS_HPP
#define MODEL_BASE_STATICHELPERS_HPP

#include "../../modeling_global.hpp"
#include "../../parser/decl/types.hpp"
#include "../../prop/types.hpp"

class QHostAddress;

namespace parser{ namespace decl{
class TriggerDeclaration;
class TypeDeclaration;
class TransitionDeclaration;}}

namespace model{
namespace base{

using prop::TypeEnum;

class DataTypeItem;
class SignalItem;
class BaseModel;
class PropAttributes;

class MODELINGSHARED_EXPORT StaticHelpers
{
public:
  static
  TypeEnum parserTypeEnum2modelTypeEnum(parser::decl::TypeEnum parserTypeEnum);

  static
  bool isSemanticallyEqual(DataTypeItem const* typeItem,
                           const parser::decl::TypeDeclaration& typeDecl);

  static
  DataTypeItem const* detectTypeDeclaration(BaseModel const* baseModel,
                                        const parser::decl::TypeDeclaration& typeDecl);

  static
  SignalItem const* detectSignal(const QString& triggerDeclString,
                                 const BaseModel *baseModel);

  static
  SignalItem const* detectSignal(const BaseModel *baseModel,
                                 const parser::decl::TriggerDeclaration &triggerDecl);

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

#endif // SPENAT_STATICHELPERS_HPP
