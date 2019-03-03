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

#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

#include <mobata/model/base/datatypeitem.hpp>
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/basemodel.hpp>
#include <mobata/model/base/propports.hpp>

#include <QStack>

namespace dslparser {
namespace common {

template<class BaseListener, class Parser, class ModelType>
class CommonModelListener : public BaseListener
{
  typedef model::base::PropDataTypes  DataTypesModel;
  typedef model::base::PropAttributes AttributesModel;
  typedef model::base::PropSignals    SignalsModel;
  typedef model::base::PropFunctions  FunctionsModel;
  typedef model::base::PropPorts      PortsModel;

protected:
  enum CommonListenerState
  {
    InitState,
    TypeDefDeclState,
    AttributeDeclState,
    LocalAttributeDeclState,
    SignalDeclState,
    FunctionDeclState,
    ParamDeclState,
    UserListenerState
  };

public:
  CommonModelListener(ModelType* baseModel,
                      DslErrorList* errors,
                      TokenTextLocations* keywordTextLocations = 0,
                      ModelTextLocations* modelTextLocations = 0);

public:
  virtual ~CommonModelListener();

protected:
  virtual int currentListenerState() const;

protected:
  virtual void enterTypeDefDecl(typename Parser::TypeDefDeclContext* ctx) override;
  virtual void exitTypeDefDecl(typename Parser::TypeDefDeclContext* ctx) override;

  virtual void enterTypeDecl(typename Parser::TypeDeclContext* ctx) override;
  virtual void exitTypeDecl(typename Parser::TypeDeclContext* ctx) override;
  virtual void exitIntTypeDecl(typename Parser::IntTypeDeclContext* ctx) override;
  virtual void exitRealTypeDecl(typename Parser::RealTypeDeclContext* ctx) override;
  virtual void exitEnumTypeDecl(typename Parser::EnumTypeDeclContext* ctx) override;

  virtual void enterAttributeDecl(typename Parser::AttributeDeclContext* ctx) override;
  virtual void exitAttributeDecl(typename Parser::AttributeDeclContext* ctx) override;

  virtual void enterLocalAssignStatement(typename Parser::LocalAssignStatementContext * ctx) override;
  virtual void exitLocalAssignStatement(typename Parser::LocalAssignStatementContext * ctx) override;

  virtual void enterSignalDecl(typename Parser::SignalDeclContext* ctx) override;
  virtual void exitSignalDecl(typename Parser::SignalDeclContext* ctx) override;

  virtual void enterFunctionDecl(typename Parser::FunctionDeclContext* ctx) override;
  virtual void exitFunctionDecl(typename Parser::FunctionDeclContext* ctx) override;

  virtual void enterParamDecl(typename Parser::ParamDeclContext* ctx) override;
  virtual void exitParamDecl(typename Parser::ParamDeclContext * ctx) override;

  virtual void enterTriggerDecl(typename Parser::TriggerDeclContext* ctx) override;
  virtual void enterThisDecl(typename Parser::ThisDeclContext* ctx) override;

  virtual void enterSendToStatement(typename Parser::SendToStatementContext* ctx) override;
  virtual void exitSendToStatement(typename Parser::SendToStatementContext * ctx) override;
  virtual void enterToPortName(typename Parser::ToPortNameContext *ctx) override;

  virtual void exitNestedStatementBody(typename Parser::NestedStatementBodyContext* ctx) override;

protected://quality control
  virtual void exitLiteralValue(typename Parser::LiteralValueContext * ctx) override;
  virtual void exitSignalParamName(typename Parser::SignalParamNameContext * ctx) override;
  virtual void exitAttributeName(typename Parser::AttributeNameContext * ctx) override;

protected://helper functions
  bool isAttributeOrEnumValueAvailable(const QString& name) const;
  void appendDslError(const antlr4::Token* token,
                      const QString& errorString);

protected:
  void setDataTypesModel(DataTypesModel* dataTypesModel) {this->_dataTypesModel=dataTypesModel;}
  void setAttributesModel(AttributesModel* attributesModel) {this->_attributesModel=attributesModel;}
  void setSignalsModel(SignalsModel* signalsModel) {this->_signalsModel=signalsModel;}

protected:
  model::base::AttributeItem* createAndAddAttribute(typename Parser::TypeDeclContext* typeDeclCtx,
                                                    typename Parser::ContextIDContext* idCtx,
                                                    model::base::PropAttributes* propAttributes);
  model::base::DataTypeItem const*  findOrAddBuiltInDataType(typename Parser::TypeDeclContext* ctx);
  void                              processInitValueCtx(typename Parser::LiteralValueContext * ctx,
                                                        model::base::AttributeItem* attributeItem);

protected:
  ModelType*          _model;
  DataTypesModel*     _dataTypesModel;
  AttributesModel*    _attributesModel;
  SignalsModel*       _signalsModel;
  FunctionsModel*     _functionsModel;
  PortsModel*         _portsModel;
  DslErrorList*       _errors;
  TokenTextLocations* _keywordTextLocations;
  ModelTextLocations* _modelTextLocations;

  QStack<int>         _listenerStates;

  // temporary data
  quint16                                   _tempTypeCounter;//type counter for realizing unique type names
  std::pair<QString, prop::TypeProperty>    _tempTypeProperty; //type-name, type-property
  QScopedPointer<model::base::SignalItem>   _currentSignalItem;//current signal item
  QScopedPointer<model::base::FunctionItem> _currentFunctionItem;//current function item
  model::base::SignalItem const*            _currentMessageSignalItem;//current message signal item
};

} // namespace common
} // namespace dslparser

#include "commonmodellistener.ipp"
