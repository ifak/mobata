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
