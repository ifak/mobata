#include "commonmodellistener.hpp"

#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/functionitem.hpp>

#include "commonfunctors.hpp"

#include <type_traits>

#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace dslparser {
namespace common {

template<class PropertyType, class ValueType, bool cond> struct SetProperty{};
template<class PropertyType, class ValueType> struct SetProperty<PropertyType,ValueType,true>
{
  static PropertyType* set(ValueType* value) {return value;}
};
template<class PropertyType, class ValueType> struct SetProperty<PropertyType,ValueType,false>
{
  static PropertyType* set(ValueType*) {return 0;}
};

template<class BaseListener, class Parser, class ModelType>
CommonModelListener<BaseListener,Parser,ModelType>::CommonModelListener(ModelType* baseModel,
                                                                        DslErrorList* errors,
                                                                        TokenTextLocations* keywordTextLocations,
                                                                        ModelTextLocations* modelTextLocations)
  : _model(baseModel),
    _dataTypesModel(SetProperty<DataTypesModel,ModelType,std::is_base_of<DataTypesModel,ModelType>::value>::set(baseModel)),
    _attributesModel(SetProperty<AttributesModel,ModelType,std::is_base_of<AttributesModel,ModelType>::value>::set(baseModel)),
    _signalsModel(SetProperty<SignalsModel,ModelType,std::is_base_of<SignalsModel,ModelType>::value>::set(baseModel)),
    _functionsModel(SetProperty<FunctionsModel,ModelType,std::is_base_of<FunctionsModel,ModelType>::value>::set(baseModel)),
    _portsModel(SetProperty<PortsModel,ModelType,std::is_base_of<PortsModel,ModelType>::value>::set(baseModel)),
    _errors(errors),
    _keywordTextLocations(keywordTextLocations),
    _modelTextLocations(modelTextLocations),
    _currentMessageSignalItem(nullptr)
{
  this->_listenerStates.push(InitState);
  this->_tempTypeCounter=1;
}

template<class BaseListener, class Parser, class ModelType>
CommonModelListener<BaseListener,Parser,ModelType>::~CommonModelListener()
{}

template<class BaseListener, class Parser, class ModelType>
int CommonModelListener<BaseListener,Parser,ModelType>::currentListenerState() const
{
  return this->_listenerStates.top();
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterTypeDefDecl(typename Parser::TypeDefDeclContext* ctx)
{
  using namespace antlr4;

  this->_listenerStates.push(TypeDefDeclState);

  typedef  tree::TerminalNode* (Parser::TypeDefDeclContext::*KeywordFunction)();

  return addKeywordLocation<typename Parser::TypeDefDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::TypeDefDeclContext::TypeID, this->_keywordTextLocations, Type);
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitTypeDefDecl(typename Parser::TypeDefDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  this->_listenerStates.pop();

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  Token* idToken = ctx->contextID()->getStart();
  Q_ASSERT(idToken);

  QString typeName=QString::fromStdString(ctx->contextID()->getText());
  if(typeName == QStringLiteral("int")
     || typeName == QStringLiteral("real")
     || typeName == QStringLiteral("bool")
     || typeName == QStringLiteral("string")
     || typeName == QStringLiteral("enum"))
  {
    if(this->_errors)
    {
      QString errorString(QString(QLatin1String("type def '%1' is not allowed "
                                                "with a standard type name!")).arg(typeName));
      this->_errors->append(DslError(errorString,
                                     idToken->getLine(),
                                     idToken->getCharPositionInLine()));
    }
    return;
  }

  QString errorString;
  model::base::DataTypeItem* newDataType = this->_dataTypesModel->addDataType(typeName, &errorString);
  if(!newDataType)
  {
    if(this->_errors)
      this->_errors->append(DslError(errorString,
                                     idToken->getLine(),
                                     idToken->getCharPositionInLine()));
  }
  else
  {
    newDataType->setTypeProperties(this->_tempTypeProperty.second);

    if(this->_modelTextLocations)
      this->_modelTextLocations->insert(newDataType->index(),
                                        TokenTextLocation(idToken->getStartIndex(),
                                                          idToken->getStopIndex(),
                                                          Type));
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterTypeDecl(typename Parser::TypeDeclContext* ctx)
{
  Q_UNUSED(ctx);

  this->_tempTypeProperty.first.clear();
  this->_tempTypeProperty.second.reset();

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitTypeDecl(typename Parser::TypeDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  //setting typeEnums (and type names)
  if(ctx->intTypeDecl())
    this->_tempTypeProperty.second.setTypeEnum(prop::Int);
  else if(ctx->realTypeDecl())
    this->_tempTypeProperty.second.setTypeEnum(prop::Real);
  else if(ctx->enumTypeDecl())
    this->_tempTypeProperty.second.setTypeEnum(prop::Enum);
  else if(ctx->BoolID())
  {
    this->_tempTypeProperty.first=QStringLiteral("bool");//normal bool declaration
    this->_tempTypeProperty.second.setTypeEnum(prop::Bool);
    //add 'bool' to keywords//
    typedef  tree::TerminalNode* (Parser::TypeDeclContext::*KeywordFunction)();
    addKeywordLocation<typename Parser::TypeDeclContext, KeywordFunction, TokenTextLocations>
        (ctx, &Parser::TypeDeclContext::BoolID, this->_keywordTextLocations, Type);
  }
  else if(ctx->StringID())
  {
    this->_tempTypeProperty.first=QStringLiteral("string");//normal string declaration
    this->_tempTypeProperty.second.setTypeEnum(prop::String);
    //add 'string' to keywords//
    typedef  tree::TerminalNode* (Parser::TypeDeclContext::*KeywordFunction)();
    addKeywordLocation<typename Parser::TypeDeclContext, KeywordFunction, TokenTextLocations>
        (ctx, &Parser::TypeDeclContext::StringID, this->_keywordTextLocations, Type);
  }
  else if(ctx->contextID())
  {
    Token* idToken = ctx->contextID()->getStart();
    Q_ASSERT(idToken);
    QString typeName=QString::fromStdString(ctx->contextID()->getText());

    if(this->currentListenerState() == FunctionDeclState){
      if(this->_currentFunctionItem != nullptr
         && !this->_currentFunctionItem->returnType().isEmpty())
        return;

      Q_ASSERT(this->_currentFunctionItem);
      _currentFunctionItem->setReturnType(typeName);
    }
    else{
      //data type must be available!!!
      model::base::DataTypeItem* existDataType = this->_dataTypesModel->dataType(typeName);
      if(!existDataType)
      {
        if(this->_errors)
        {
          QString errorString=QObject::tr("data type '%1' is not available!").arg(typeName);
          this->_errors->append(DslError(errorString,
                                         idToken->getLine(),
                                         idToken->getCharPositionInLine()));
        }
      }
      else
      {
        this->_tempTypeProperty.first=existDataType->name();
        this->_tempTypeProperty.second.setLowest(existDataType->lowest());
        this->_tempTypeProperty.second.setHighest(existDataType->highest());
        this->_tempTypeProperty.second.setLiterals(existDataType->literals());
        this->_tempTypeProperty.second.setTypeEnum(existDataType->typeEnum());
        this->_tempTypeProperty.second.setCustomType(existDataType->name());
      }
    }
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitNestedStatementBody(typename Parser::NestedStatementBodyContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(this->currentListenerState() == FunctionDeclState){
    Q_ASSERT(_currentFunctionItem);
    misc::Interval interval = misc::Interval(ctx->LBRACE()->getSymbol()->getStartIndex()+1,ctx->getStop()->getStopIndex()-1);
    this->_currentFunctionItem->setStatementBody(QString::fromStdString(ctx->getStart()->getInputStream()->getText(interval)));
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitIntTypeDecl(typename Parser::IntTypeDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  //add 'int' to keywords//
  typedef  tree::TerminalNode* (Parser::IntTypeDeclContext::*KeywordFunction)();
  addKeywordLocation<typename Parser::IntTypeDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::IntTypeDeclContext::IntID, this->_keywordTextLocations, Type);

  if(ctx->INT().size())
  {
    Q_ASSERT(ctx->INT().size()==2);
    QString lowest = QString::fromStdString(ctx->INT().at(0)->getText());
    QString highest = QString::fromStdString(ctx->INT().at(1)->getText());

    QString typeName = QStringLiteral("int_")
                       +QString(QStringLiteral("%1")).arg(this->_tempTypeCounter++)
                       +QStringLiteral("_")
                       +QStringLiteral("type");

    this->_tempTypeProperty.second.setLowest(lowest);
    this->_tempTypeProperty.second.setHighest(highest);
    this->_tempTypeProperty.first=typeName;
  }
  else
    this->_tempTypeProperty.first=QStringLiteral("int");//normal int declaration

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitRealTypeDecl(typename Parser::RealTypeDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  //add 'real' to keywords//
  typedef  tree::TerminalNode* (Parser::RealTypeDeclContext::*KeywordFunction)();
  addKeywordLocation<typename Parser::RealTypeDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::RealTypeDeclContext::RealID, this->_keywordTextLocations, Type);

  if(ctx->REAL().size())
  {
    Q_ASSERT(ctx->REAL().size()==2);
    QString lowest = QString::fromStdString(ctx->REAL().at(0)->getText());
    QString highest = QString::fromStdString(ctx->REAL().at(1)->getText());

    QString typeName = QStringLiteral("real_")
                       +QString(QStringLiteral("%1")).arg(this->_tempTypeCounter++)
                       +QStringLiteral("_")
                       +QStringLiteral("type");

    this->_tempTypeProperty.second.setLowest(lowest);
    this->_tempTypeProperty.second.setHighest(highest);
    this->_tempTypeProperty.first=typeName;
  }
  else
    this->_tempTypeProperty.first=QStringLiteral("real");//normal real declaration

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitEnumTypeDecl(typename Parser::EnumTypeDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  //add 'enum' to keywords//
  typedef  tree::TerminalNode* (Parser::EnumTypeDeclContext::*KeywordFunction)();
  addKeywordLocation<typename Parser::EnumTypeDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::EnumTypeDeclContext::EnumID, this->_keywordTextLocations, Type);

  Q_ASSERT(ctx->contextID().size()>=1);
  for(auto ident : ctx->contextID())
    this->_tempTypeProperty.second.addLiteral(QString::fromStdString(ident->getText()));

  QString typeName = QStringLiteral("enum_")
                     +QString(QStringLiteral("%1")).arg(this->_tempTypeCounter++)
                     +QStringLiteral("_")
                     +QStringLiteral("type");
  this->_tempTypeProperty.first=typeName;

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterAttributeDecl(typename Parser::AttributeDeclContext* ctx)
{
  using namespace antlr4;

  this->_listenerStates.push(AttributeDeclState);

  this->_tempTypeProperty.first.clear();
  this->_tempTypeProperty.second.reset();

  typedef  tree::TerminalNode* (Parser::AttributeDeclContext::*KeywordFunction)();

  return addKeywordLocation<typename Parser::AttributeDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::AttributeDeclContext::AttributeID, this->_keywordTextLocations, Attribute);
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitAttributeDecl(typename Parser::AttributeDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  this->_listenerStates.pop();

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->typeDecl());

  typename Parser::ContextIDContext* nameContextID = ctx->contextID();
  Q_ASSERT(nameContextID);

  model::base::AttributeItem* attributeItem=this->createAndAddAttribute(ctx->typeDecl(),
                                                                        nameContextID,
                                                                        this->_attributesModel);
  if(!attributeItem)
    return;

  Q_ASSERT(ctx->AttributeID());
  Q_ASSERT(ctx->AttributeID()->getSymbol());
  Q_ASSERT(ctx->SEMI());
  Q_ASSERT(ctx->SEMI()->getSymbol());
  if(this->_modelTextLocations)
    this->_modelTextLocations->insert(attributeItem->index(),
                                      TokenTextLocation(ctx->AttributeID()->getSymbol()->getStartIndex(),
                                                        ctx->SEMI()->getSymbol()->getStopIndex(),
                                                        Attribute));
  if(ctx->literalValue())//find init value and make some checks!
    this->processInitValueCtx(ctx->literalValue(), attributeItem);

  return;
}

template<class BaseListener, class Parser, class ModelType>
model::base::AttributeItem*
CommonModelListener<BaseListener,Parser,ModelType>::createAndAddAttribute(typename Parser::TypeDeclContext* typeDeclCtx,
                                                                          typename Parser::ContextIDContext* idCtx,
                                                                          model::base::PropAttributes* propAttributes)
{
  using namespace antlr4;

  if(!typeDeclCtx)
    return nullptr;
  if(!idCtx)
    return nullptr;
  if(!propAttributes)
    return nullptr;

  Token* nameToken = idCtx->getStart();
  Q_ASSERT(nameToken);

  QString attributeName=QString::fromStdString(idCtx->getText());
  if(attributeName == QStringLiteral("int")
     || attributeName == QStringLiteral("real")
     || attributeName == QStringLiteral("bool")
     || attributeName == QStringLiteral("string")
     || attributeName == QStringLiteral("enum"))
  {
    if(this->_errors)
    {
      QString errorString(QString(QLatin1String("attribute name '%1' is not allowed "
                                                "with a standard type name!")).arg(attributeName));
      this->_errors->append(DslError(errorString,
                                     nameToken->getLine(),
                                     nameToken->getCharPositionInLine()));
    }

    return nullptr;
  }

  //find or add attribute data type
  model::base::DataTypeItem const* attributeDataType = this->findOrAddBuiltInDataType(typeDeclCtx);
  if(!attributeDataType)
    return nullptr;

  //add new attribute item with empty init value
  QString errorString;
  model::base::AttributeItem* attributeItem = this->_attributesModel->addAttribute(attributeName,
                                                                                   attributeDataType->name(),
                                                                                   QStringLiteral(""),
                                                                                   &errorString);
  if(!attributeItem)
  {
    if(this->_errors)
      this->_errors->append(DslError(errorString,
                                     nameToken->getLine(),
                                     nameToken->getCharPositionInLine()));
    return nullptr;
  }

  return attributeItem;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::processInitValueCtx(typename Parser::LiteralValueContext* ctx,
                                                                             model::base::AttributeItem* attributeItem)
{
  Q_ASSERT(ctx);
  Q_ASSERT(attributeItem);

  using namespace antlr4;

  Token* initValueToken = 0;
  if(ctx->INT())
    initValueToken = ctx->INT()->getSymbol();
  else if(ctx->REAL())
    initValueToken = ctx->REAL()->getSymbol();
  else if(ctx->TrueID())
    initValueToken = ctx->TrueID()->getSymbol();
  else if(ctx->FalseID())
    initValueToken = ctx->FalseID()->getSymbol();
  else if(ctx->STRING())
    initValueToken = ctx->STRING()->getSymbol();
  else if(ctx->contextID())
    initValueToken = ctx->contextID()->getStart();
  if(!initValueToken)
    return; //on irdl if attribute assign is empty... why not on spenat??

  QString initValue = QString::fromStdString(initValueToken->getText());
  if(attributeItem->dataType() == QLatin1String("string"))
  {//remove first and last '"'
    initValue.remove(0,1);
    initValue.remove(initValue.size()-1,1);
  }
  attributeItem->setInitValue(initValue);

  //make some checks and create error messages//
  if(!this->_dataTypesModel)
    return;//no checks possible
  model::base::DataTypeItem const* attributeDataType=this->_dataTypesModel->dataType(attributeItem->dataType());
  if(!attributeDataType)
    return;//no checkes possible

  if(attributeDataType->typeEnum() == prop::Int
     && !ctx->INT())
  {
    if(this->_errors)
    {
      QString errorString(QString(QStringLiteral("init value '%1' of attribute '%2' is not an integer!"))
                          .arg(initValue).arg(attributeItem->name()).arg(initValue));
      this->_errors->append(DslError(errorString,
                                     initValueToken->getLine(),
                                     initValueToken->getCharPositionInLine()));
    }
  }
  else if(attributeDataType->typeEnum() == prop::Real
          && !ctx->REAL())
  {
    if(this->_errors)
    {
      QString errorString(QString(QStringLiteral("init value '%1' of attribute '%2' is not a real!"))
                          .arg(initValue).arg(attributeItem->name()).arg(initValue));
      this->_errors->append(DslError(errorString,
                                     initValueToken->getLine(),
                                     initValueToken->getCharPositionInLine()));
    }
  }
  else if(attributeDataType->typeEnum() == prop::Bool
          && !(ctx->TrueID()
               || ctx->FalseID()))
  {
    if(this->_errors)
    {
      QString errorString(QString(QStringLiteral("init value '%1' of attribute '%2' is not a boolean value!"))
                          .arg(initValue).arg(attributeItem->name()).arg(initValue));
      this->_errors->append(DslError(errorString,
                                     initValueToken->getLine(),
                                     initValueToken->getCharPositionInLine()));
    }
  }
  else if(attributeDataType->typeEnum() == prop::String
          && !ctx->STRING())
  {
    if(this->_errors)
    {
      QString errorString(QString(QStringLiteral("init value '%1' of attribute '%2' is not a string!"))
                          .arg(initValue).arg(attributeItem->name()).arg(initValue));
      this->_errors->append(DslError(errorString,
                                     initValueToken->getLine(),
                                     initValueToken->getCharPositionInLine()));
    }
  }
  else if(attributeDataType->typeEnum() == prop::Enum)
  {
    if(!ctx->contextID())
    {
      if(this->_errors)
      {
        QString errorString(QString(QStringLiteral("init value '%1' of attribute '%2' is not a enum value!"))
                            .arg(initValue).arg(attributeItem->name()).arg(initValue));
        this->_errors->append(DslError(errorString,
                                       initValueToken->getLine(),
                                       initValueToken->getCharPositionInLine()));
      }
    }
    else if(!attributeDataType->hasLiteral(initValue))
    {
      if(this->_errors)
      {
        QString errorString(QString(QStringLiteral("enum type of attriubte '%1' has no literal '%2'!"))
                            .arg(attributeItem->name()).arg(initValue));
        this->_errors->append(DslError(errorString,
                                       initValueToken->getLine(),
                                       initValueToken->getCharPositionInLine()));
      }
    }
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterLocalAssignStatement(typename Parser::LocalAssignStatementContext* ctx)
{
  Q_UNUSED(ctx);

  this->_listenerStates.push(LocalAttributeDeclState);

  this->_tempTypeProperty.first.clear();
  this->_tempTypeProperty.second.reset();

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitLocalAssignStatement(typename Parser::LocalAssignStatementContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_listenerStates.pop();

  Q_ASSERT(ctx->typeDecl());
  Q_ASSERT(ctx->contextID());

  model::base::PropAttributes* currentPropAttributes=this->_attributesModel;
  if(this->_listenerStates.first()==FunctionDeclState)
    currentPropAttributes=this->_currentFunctionItem.data();

  typename Parser::ContextIDContext* nameContextID = ctx->contextID();
  Q_ASSERT(nameContextID);

  model::base::AttributeItem* attributeItem=this->createAndAddAttribute(ctx->typeDecl(),
                                                                        nameContextID,
                                                                        currentPropAttributes);
  if(!attributeItem)
    return;

  Q_ASSERT(ctx->getStart());
  Q_ASSERT(ctx->SEMI());
  Q_ASSERT(ctx->SEMI()->getSymbol());
  if(this->_modelTextLocations)
    this->_modelTextLocations->insert(attributeItem->index(),
                                      TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                        ctx->SEMI()->getSymbol()->getStopIndex(),
                                                        Attribute));
  if(ctx->expression()
     && ctx->expression()->operation()
     && ctx->expression()->operation()->atom()
     && ctx->expression()->operation()->atom()->literalValue())//find init value and make some checks!
    this->processInitValueCtx(ctx->expression()->operation()->atom()->literalValue(),
                              attributeItem);

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterSignalDecl(typename Parser::SignalDeclContext * ctx)
{
  using namespace antlr4;

  this->_listenerStates.push(SignalDeclState);

  if(!this->_keywordTextLocations)
    return;

  this->_currentSignalItem.reset(new model::base::SignalItem);

  typedef  tree::TerminalNode* (Parser::SignalDeclContext::*KeywordFunction)();

  return addKeywordLocation<typename Parser::SignalDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::SignalDeclContext::SignalID, this->_keywordTextLocations, Signal);
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitSignalDecl(typename Parser::SignalDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);
  Q_ASSERT(this->_currentSignalItem);

  this->_listenerStates.pop();

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!ctx->contextID())
    return;

  this->_currentSignalItem->setName(QString::fromStdString(ctx->contextID()->getText()));
  this->_currentSignalItem->setText(this->_currentSignalItem->toString());

  model::base::SignalItem* newSignalItem=this->_currentSignalItem.take();
  QString errorString;
  bool result = this->_signalsModel->addSignal(newSignalItem, &errorString);
  if(!result)
  {
    Token* signalNameToken = ctx->contextID()->getStart();
    Q_ASSERT(signalNameToken);

    if(this->_errors)
      this->_errors->append(DslError(errorString,
                                     signalNameToken->getLine(),
                                     signalNameToken->getCharPositionInLine()));
    delete newSignalItem;
    newSignalItem = 0;
  }
  else
  {
    Q_ASSERT(ctx->SignalID());
    Q_ASSERT(ctx->SignalID()->getSymbol());
    Q_ASSERT(ctx->SEMI());
    Q_ASSERT(ctx->SEMI()->getSymbol());
    if(this->_modelTextLocations)
      this->_modelTextLocations->insert(newSignalItem->index(),
                                        TokenTextLocation(ctx->SignalID()->getSymbol()->getStartIndex(),
                                                          ctx->SEMI()->getSymbol()->getStopIndex(),
                                                          Signal));
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterSendToStatement(typename Parser::SendToStatementContext *ctx)
{
  using namespace antlr4;

  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (Parser::SendToStatementContext::*KeywordFunction)();

  addKeywordLocation<typename Parser::SendToStatementContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::SendToStatementContext::SendID, this->_keywordTextLocations, Keyword);

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterToPortName(typename Parser::ToPortNameContext *ctx)
{
  using namespace antlr4;

  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (Parser::ToPortNameContext::*KeywordFunction)();

  addKeywordLocation<typename Parser::ToPortNameContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::ToPortNameContext::ToID, this->_keywordTextLocations, Keyword);

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitSendToStatement(typename Parser::SendToStatementContext *ctx)
{
  if(!ctx || ctx->exception)
    return;

  Q_ASSERT(ctx->signalSend());
  Q_ASSERT(ctx->signalSend()->signalIdPath());

  auto signalIdCtx = ctx->signalSend()->signalIdPath();
  auto sendSignal = this->_signalsModel->signal(QString::fromStdString(signalIdCtx->getText()));
  if(!sendSignal)
  {
    QString errorString = QObject::tr("Signal '%1' does not exist!")
                          .arg(QString::fromStdString(signalIdCtx->getText()));
    appendDslError(signalIdCtx->getStart(),
                   errorString);
    return;
  }

  auto bdyCtx = ctx->signalSend()->functionCallBody();
  int counter = 0;
  while(bdyCtx)
  {
    if (auto attrCtx = bdyCtx->attributeName())
    {
      ++counter;

      Q_ASSERT(this->_attributesModel);
      Q_ASSERT(attrCtx->contextID());
      QString attrName = QString::fromStdString(attrCtx->contextID()->getText());
      if(!_attributesModel->attribute(attrName))
      {
        QString errorString = QObject::tr("Attribute '%1' does not exist!")
                              .arg(attrName);
        appendDslError(attrCtx->contextID()->getStart(),
                       errorString);
        return;
      }
    }
    else if(auto signalNameCtx = bdyCtx->signalParamName())
    {
      ++counter;

      Q_ASSERT(signalNameCtx->contextID());
      QString signalParamText = QString::fromStdString(signalNameCtx->contextID()->getText());
      if(!this->_currentMessageSignalItem)
      {
        QString errorString = QObject::tr("no message signal available!");
        appendDslError(signalNameCtx->contextID()->getStart(),
                       errorString);
        return;
      }

      if(!this->_currentMessageSignalItem->parameter(signalParamText))
      {
        QString errorString = QObject::tr("Signal '%1' has no parameter '%2' available!")
                              .arg(this->_currentMessageSignalItem->name()).arg(signalParamText);
        appendDslError(signalNameCtx->contextID()->getStart(),
                       errorString);
        return;
      }
    }
    else if(bdyCtx->literalValue())
      ++counter;
    else if(bdyCtx->functionCall())
      ++counter;
//    else if(bdyCtx->expression())
//      ++counter;

    bdyCtx = bdyCtx->functionCallBodyOptional()
             ? bdyCtx->functionCallBodyOptional()->functionCallBody()
             : nullptr;
  }

  if(sendSignal->params().count() != counter)
  {
    QString errorString = QObject::tr("Tried to send %1 parameters. Signal '%2' has actually %3 parameters!")
                          .arg(QString::number(counter),
                               sendSignal->name(),
                               QString::number(sendSignal->params().count()));
    appendDslError(signalIdCtx->getStart(),
                   errorString);
    return;
  }

  if(ctx->toPortName())
  {
    Q_ASSERT(ctx->toPortName()->contextID());
    if(!this->_portsModel)
    {
      QString errorString = QObject::tr("Ports are not allowed here!");
      appendDslError(ctx->toPortName()->contextID()->getStart(),
                     errorString);
      return;
    }

    QString portname = QString::fromStdString(ctx->toPortName()->contextID()->getText());
    if(!this->_portsModel->port(portname))
    {
      QString errorString = QObject::tr("Port '%1' does not exist!")
                            .arg(portname);
      appendDslError(ctx->toPortName()->contextID()->getStart(),
                     errorString);
      return;
    }
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitAttributeName(typename Parser::AttributeNameContext *ctx)
{
  using namespace antlr4;

  if(!ctx || ctx->exception) return;
  auto attrCtx = ctx;
  auto parentCtx = dynamic_cast<RuleContext*>(ctx->parent);
  if((parentCtx->getRuleIndex() == Parser::RuleAttributeAssignStatement)
     || (attrCtx->thisDecl()))
  {
    Q_ASSERT(attrCtx->contextID());

    QString attrName = QString::fromStdString(attrCtx->contextID()->getText());
    if(!this->_attributesModel)
    {
      QString errorString = QObject::tr("Attributes are not allowed here!");
      appendDslError(attrCtx->contextID()->getStart(),
                     errorString);
      return;
    }

    if(!this->_attributesModel->attribute(attrName))
    {
      QString errorString = QObject::tr("Attribute '%1' does not exist!")
                            .arg(attrName);
      appendDslError(attrCtx->contextID()->getStart(),
                     errorString);
      return;
    }
  }
  else
  {
    Q_ASSERT(attrCtx->contextID());

    QString contextIdString = QString::fromStdString(attrCtx->contextID()->getText());
    bool found=this->isAttributeOrEnumValueAvailable(contextIdString);
    if(!found)
    {
      QString errorString = QObject::tr("attribute or enum value '%1' does not exist!")
                            .arg(contextIdString);
      appendDslError(attrCtx->contextID()->getStart(),
                     errorString);
      return;
    }
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
bool CommonModelListener<BaseListener,Parser,ModelType>::isAttributeOrEnumValueAvailable(const QString& name) const
{
  if(this->_attributesModel)
  {
    if(this->_attributesModel->attribute(name))
      return true;
  }

  if(this->_currentFunctionItem)
  {
    if(this->_currentFunctionItem->parameter(name))
      return true;
  }

  if(this->_dataTypesModel)
  {
    if(this->_dataTypesModel->hasEnumValue(name))
      return true;
  }

  return false;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterParamDecl(typename Parser::ParamDeclContext* ctx)
{
  Q_UNUSED(ctx);

  this->_listenerStates.push(ParamDeclState);

  this->_tempTypeProperty.first.clear();
  this->_tempTypeProperty.second.reset();

}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitParamDecl(typename Parser::ParamDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  this->_listenerStates.pop();

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!ctx->typeDecl() || !ctx->contextID())
  {
    appendDslError(ctx->getStart(), QStringLiteral("error prone param declaration!"));
    return;
  }

  model::base::DataTypeItem const* paramDataType = this->findOrAddBuiltInDataType(ctx->typeDecl());
  if(paramDataType == nullptr){
    appendDslError(ctx->contextID()->getStart(), QStringLiteral("Param data type was not found!"));
    return;
  }

  Q_ASSERT(paramDataType);
  QString paramName = QString::fromStdString(ctx->contextID()->getText());

  if(this->currentListenerState() == SignalDeclState){

    if(!this->_currentSignalItem)
      return;

    QString errorString;
    if(!this->_currentSignalItem->addParameter(paramName, paramDataType->name(), &errorString))
    {
      appendDslError(ctx->contextID()->getStart(), errorString);
    }
  }
  else if(this->currentListenerState() == FunctionDeclState){

    if(!this->_currentFunctionItem)
      return;

    QString errorString;
    if(!this->_currentFunctionItem->addParameter(paramName, paramDataType->name(), &errorString))
    {
      appendDslError(ctx->contextID()->getStart(), errorString);
    }
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterTriggerDecl(typename Parser::TriggerDeclContext *ctx)
{
  using namespace antlr4;

  if(!this->_keywordTextLocations)
    return;

  typedef  tree::TerminalNode* (Parser::TriggerDeclContext::*KeywordFunction)();

  return addKeywordLocation<typename Parser::TriggerDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::TriggerDeclContext::TriggerID, this->_keywordTextLocations, Trigger);
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterThisDecl(typename Parser::ThisDeclContext *ctx)
{
  using namespace antlr4;

  if(!this->_keywordTextLocations)
    return;

  typedef  tree::TerminalNode* (Parser::ThisDeclContext::*KeywordFunction)();

  return addKeywordLocation<typename Parser::ThisDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::ThisDeclContext::ThisID, this->_keywordTextLocations, This);
}

template<class BaseListener, class Parser, class ModelType>
model::base::DataTypeItem const*
CommonModelListener<BaseListener,Parser,ModelType>::findOrAddBuiltInDataType(typename Parser::TypeDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);

  if(!this->_dataTypesModel)
  {
    QString errorString = QObject::tr("no data types available!");
    appendDslError(ctx->getStart(),
                   errorString);
    return nullptr;
  }

  model::base::DataTypeItem* dataType = this->_dataTypesModel->dataType(this->_tempTypeProperty.first);
  if(!dataType)
  {
    //find equal data-type
    for(model::base::DataTypeItem const* existDataType : this->_dataTypesModel->dataTypes())
    {
      if(existDataType->isEqual(this->_tempTypeProperty.second))
        return existDataType;
    }

    if(!dataType)
    {//add new data type
      QString errorString;
      dataType = this->_dataTypesModel->addDataType(this->_tempTypeProperty.first, &errorString);
      if(!dataType)
      {
        if(this->_errors)
          this->_errors->append(DslError(errorString,
                                         ctx->getStart()->getLine(),
                                         ctx->getStart()->getCharPositionInLine()));
        return 0;
      }
      dataType->setTypeProperties(this->_tempTypeProperty.second);

      Q_ASSERT(ctx->getStart());
      Q_ASSERT(ctx->getStop());
      if(this->_modelTextLocations)
        this->_modelTextLocations->insert(dataType->index(),
                                          TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                            ctx->getStop()->getStopIndex(),
                                                            Type));
    }
  }

  return dataType;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::enterFunctionDecl(typename Parser::FunctionDeclContext * ctx)
{
  using namespace antlr4;

  this->_listenerStates.push(FunctionDeclState);
  this->_currentFunctionItem.reset(new model::base::FunctionItem);
  this->_currentFunctionItem->setReturnType(QStringLiteral(""));
  this->_tempTypeProperty.first.clear();
  this->_tempTypeProperty.second.reset();

  if(!this->_keywordTextLocations)
    return;

  typedef  tree::TerminalNode* (Parser::FunctionDeclContext::*KeywordFunction)();

  return addKeywordLocation<typename Parser::FunctionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &Parser::FunctionDeclContext::FunctionID, this->_keywordTextLocations, Function);
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitFunctionDecl(typename Parser::FunctionDeclContext* ctx)
{
  using namespace antlr4;
  using namespace model::base;
  Q_ASSERT(ctx);
  Q_ASSERT(this->_currentFunctionItem);

  this->_listenerStates.pop();

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!ctx->idPath())
    return;

  QString functionName = QString::fromStdString(ctx->idPath()->contextID().back()->getText());
  this->_currentFunctionItem->setName(functionName);
  this->_currentFunctionItem->setText(functionName);

  model::base::FunctionItem* newFunctionItem=this->_currentFunctionItem.take();
  QString errorString;
  bool result = this->_functionsModel->addFunction(newFunctionItem, &errorString);
  if(!result)
  {
    Token* functionNameToken = ctx->idPath()->getStart();
    Q_ASSERT(functionNameToken);

    if(this->_errors)
      this->_errors->append(DslError(errorString,
                                     functionNameToken->getLine(),
                                     functionNameToken->getCharPositionInLine()));
    delete newFunctionItem;
    newFunctionItem = 0;
  }
  else
  {
    Q_ASSERT(ctx->FunctionID());
    Q_ASSERT(ctx->FunctionID()->getSymbol());
    Q_ASSERT(ctx->getStop());
    if(this->_modelTextLocations)
      this->_modelTextLocations->insert(newFunctionItem->index(),
                                        TokenTextLocation(ctx->FunctionID()->getSymbol()->getStartIndex(),
                                                          ctx->getStop()->getStopIndex(),
                                                          Function));
  }

  this->_currentFunctionItem.reset();

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitLiteralValue(typename Parser::LiteralValueContext *ctx)
{
  if(!ctx || ctx->exception) return;

  if(auto literalValueIdCtx = ctx->contextID())
  {
    QString literalValueId = QString::fromStdString(literalValueIdCtx->getText());
    bool found=this->isAttributeOrEnumValueAvailable(literalValueId);
    if(!found)
    {
      QString errorString = QObject::tr("attribute or enum value '%1' does not exist!")
                            .arg(literalValueId);
      appendDslError(literalValueIdCtx->getStart(),
                     errorString);
      return;
    }
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::exitSignalParamName(typename Parser::SignalParamNameContext *ctx)
{
  if(!ctx || ctx->exception) return;

  auto signalNameCtx = ctx;
  Q_ASSERT(signalNameCtx->contextID());
  QString attrName = QString::fromStdString(signalNameCtx->contextID()->getText());
  if(!this->_currentMessageSignalItem)
  {
    QString errorString = QObject::tr("no message signal available!");
    appendDslError(signalNameCtx->contextID()->getStart(),
                   errorString);
    return;
  }

  if(!this->_currentMessageSignalItem->parameter(attrName))
  {
    QString errorString = QObject::tr("Signal '%1' has no parameter '%2' available!")
                          .arg(this->_currentMessageSignalItem->name()).arg(attrName);
    appendDslError(signalNameCtx->getStart(),
                   errorString);
    return;
  }

  return;
}

template<class BaseListener, class Parser, class ModelType>
void CommonModelListener<BaseListener,Parser,ModelType>::appendDslError(const antlr4::Token* token,
                                                                        const QString& errorString)
{
  Q_ASSERT(token);
  if(this->_errors){
    this->_errors->append(DslError(errorString,
                                   token->getLine(),
                                   token->getCharPositionInLine()));
  }
}

} // namespace common
} // namespace dslparser

#include <mobata/memory_leak_end.hpp>
