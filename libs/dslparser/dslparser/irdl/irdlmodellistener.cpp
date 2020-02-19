#include "irdlmodellistener.hpp"
#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/propattributes.hpp>
#include <dslparser/common/combuildbasemodel.hpp>
#include <dslparser/irdldecl/combuildirdldeclmodel.hpp>

#include <mobata/model/requirement/requirementsmodel.hpp>
#include <mobata/model/requirement/requirementitem.hpp>
#include <mobata/model/requirement/reqactorcomponentitem.hpp>
#include <mobata/model/requirement/reqcomponentitem.hpp>
#include <mobata/model/msc/msccomponentitem.hpp>
#include <mobata/model/msc/mscmessageitem.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>
#include <mobata/model/msc/mscsequence.hpp>
#include <mobata/model/base/propparams.hpp>
#include <mobata/model/base/modelitem.hpp>
#include <mobata/model/msc/msctimeritem.hpp>

#include <mobata/model/base/propdatatypes.hpp>

//#include <mobata/model/requirement/transitionitem.hpp>
//#include <mobata/model/requirement/simplestateitem.hpp>
//#include <mobata/model/requirement/compositestateitem.hpp>
//#include <mobata/model/requirement/parallelstateitem.hpp>
//#include <mobata/model/requirement/junctionstateitem.hpp>
//#include <mobata/model/requirement/finalstateitem.hpp>
//#include <mobata/model/requirement/initstateitem.hpp>

#include "combuildirdlmodel.hpp"

#include <QStack>
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

namespace reg = model::irdl;
using namespace antlr4;

namespace dslparser {
namespace irdl {

using common::addKeywordLocation;

class IrdlModelListener::Private
{
  friend class IrdlModelListener;

  ///parse data////
  //QScopedPointer<reg::TransitionItem> _currentTransition;
  int                                    _errorAtPos;
  model::base::ModelItem*                _currentPathItem;
  reg::ReqActorComponentItem*            _curActor;
  reg::ReqComponentItem*                 _curComp;
  const model::base::ComponentItem*            _curCompOfAttributeItem = nullptr;
  reg::RequirementItem*                  _regItem;
  const model::msc::SignalItem *         _currentSignal = nullptr;
  QStack<model::msc::MscFragmentItem*>   _curDurFrag;
  QStack<model::msc::MscSequence*>       _seqStack;
  QStack<model::msc::MscFragmentItem*>   _altStack;
  QHash<QString,const model::msc::MscComponentItem*> _IrdlCompItems;
  QHash<QString,QList<model::msc::MscComponentItem*>> _importedComponents;
  QHash<QString, const model::msc::MscTimerItem*> _timerItems;
  ImportModelItem                        _importItems;
  ImportModel                            _importModels;
  QString                                _praefix;

  Private(const QString& prefix)
    : //_currentTransition(0),
      _currentPathItem(nullptr),
      _importItems(),
      _praefix(prefix)
  {}
};

IrdlModelListener::IrdlModelListener(reg::RequirementsModel* irdlDeclModel,
                                     DslErrorList* irdlErrors,
                                     const QString& prefix,
                                     TokenTextLocations* keywordTextLocations,
                                     ModelTextLocations* modelTextLocations)
  : common::CommonModelListener<IrdlBaseListener, IrdlParser, reg::RequirementsModel>(irdlDeclModel,
                                                                                      irdlErrors,
                                                                                      keywordTextLocations,
                                                                                      modelTextLocations),
    _d(new Private(prefix))
{
  Q_ASSERT(irdlDeclModel);
  //this->_d->_propStatesStack.push_front(irdlDeclModel);
}

IrdlModelListener::~IrdlModelListener()
{
  delete this->_d;
}

QPair<model::base::ModelItem *, int> IrdlModelListener::currentPathItem()
{
  return QPair<model::base::ModelItem*,int>(this->_d->_currentPathItem,_d->_errorAtPos);
}

const model::base::SignalItem *IrdlModelListener::currentSignalItem()
{
  return this->_d->_currentSignal;
}

const QHash<QString,const model::msc::MscComponentItem *> &IrdlModelListener::requirementCompItems()
{
  return this->_d->_IrdlCompItems;
}

const ImportModelItem &IrdlModelListener::importItems()
{
  return this->_d->_importItems;
}

const ImportModel &IrdlModelListener::importModels()
{
  return this->_d->_importModels;
}

const QHash<QString, const model::msc::MscTimerItem *> IrdlModelListener::timerItems()
{
  return this->_d->_timerItems;
}

void IrdlModelListener::enterIrdlDecl(IrdlParser::IrdlDeclContext* ctx)
{
  this->_listenerStates.push(IrdlState);

  _d->_regItem = _model->addRequirement(QString(""));
  _d->_seqStack.push_front(_d->_regItem);

  typedef  tree::TerminalNode* (IrdlParser::IrdlDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::IrdlDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::IrdlDeclContext::RequirementID, this->_keywordTextLocations, Requirement);

}

void IrdlModelListener::exitIrdlDecl(IrdlParser::IrdlDeclContext* ctx)
{
  this->_listenerStates.pop();
  _d->_seqStack.pop_front();
  if(!ctx || ctx->exception) return;
  this->_modelTextLocations->insert(this->_model->invisibleRootItem()->index(),
                                    TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                      ctx->getStop()->getStopIndex(),
                                                      Requirement));
  return;
}

void IrdlModelListener::enterAliasDef(IrdlParser::AliasDefContext *ctx)
{
  Q_UNUSED(ctx);
}

void IrdlModelListener::exitAliasDef(IrdlParser::AliasDefContext *ctx)
{
  if(ctx->exception && ctx->componentIdPath())
    return;
  if(auto comp = getComponentFromPath(ctx->componentIdPath())){
    _d->_IrdlCompItems.insert(QString::fromStdString(ctx->contextID()->getText()),static_cast<const model::msc::MscComponentItem*>(comp->owner()));
  }

  typedef  tree::TerminalNode* (IrdlParser::AliasDefContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::AliasDefContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::AliasDefContext::UseID, this->_keywordTextLocations, Use);
}

void IrdlModelListener::enterActorDecl(IrdlParser::ActorDeclContext *ctx)
{
  if(!ctx || ctx->exception) return;

  typedef  tree::TerminalNode* (IrdlParser::ActorDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::ActorDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::ActorDeclContext::ActorID, this->_keywordTextLocations, Actor);

  QString errorString("");
  _d->_curActor = _model->addComponent<model::irdl::ReqActorComponentItem>(QString(""),&errorString);
  if(errorString != QString("")){
    appendDslError(ctx->getStart(),
                   errorString);
    return;
  }
  _listenerStates.push(ActorDeclState);
  setAttributesModel(_d->_curActor);
}

void IrdlModelListener::exitActorDecl(IrdlParser::ActorDeclContext *ctx)
{
  Q_UNUSED(ctx);
  _listenerStates.pop();
  setAttributesModel(_model);
}

void IrdlModelListener::enterComponentDecl(IrdlParser::ComponentDeclContext *ctx)
{
  if(!ctx || ctx->exception) return;

  typedef  tree::TerminalNode* (IrdlParser::ComponentDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::ComponentDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::ComponentDeclContext::ComponentID, this->_keywordTextLocations, Component);

  QString errorString("");
  _d->_curComp = _model->addComponent<model::irdl::ReqComponentItem>(QString(""),&errorString);
  if(errorString != QString("")){
    appendDslError(ctx->getStart(),
                   errorString);
    return;
  }
  _listenerStates.push(ComponentDeclState);
  setAttributesModel(_d->_curComp);
}

void IrdlModelListener::exitComponentDecl(IrdlParser::ComponentDeclContext *ctx)
{
  Q_UNUSED(ctx);
  _listenerStates.pop();
  setAttributesModel(_model);
}

void IrdlModelListener::enterPortDecl(IrdlParser::PortDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::PortDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::PortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::PortDeclContext::PortID, this->_keywordTextLocations, Port);
}

void IrdlModelListener::exitPortDecl(IrdlParser::PortDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception || _errors->size())
    return;//an error occured! -> but still handled by error listener!

  for(IrdlParser::ContextIDContext* currContextID : ctx->contextID())
  {
    Token* portToken=currContextID->getStart();
    Q_ASSERT(portToken);

    QString portName=QString::fromStdString(currContextID->getText());
    QString errorString;
    reg::PortItem* newPort = nullptr;
    if(_d->_curComp)
      newPort = _d->_curComp->addPort(portName, &errorString);
    else if(_d->_curActor)
      newPort = _d->_curActor->addPort(portName, &errorString);
    if(!newPort)
    {
      if(this->_errors)
        this->_errors->append(DslError(errorString,
                                       portToken->getLine(),
                                       portToken->getCharPositionInLine()));
    }
    else
    {
      this->_modelTextLocations->insert(newPort->index(),
                                        TokenTextLocation(portToken->getStartIndex(),
                                                          portToken->getStopIndex(),
                                                          Port));
    }
  }

  return;
}

void IrdlModelListener::enterNameDecl(IrdlParser::NameDeclContext* ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::NameDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::NameDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void IrdlModelListener::exitNameDecl(IrdlParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString name=QString::fromStdString(ctx->contextID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==IrdlState)
  {
    Q_ASSERT(this->_d->_regItem);
    this->_d->_regItem->setName(name);
    this->_d->_regItem->setText(this->_d->_regItem->toString());
  }
  else if(currListenerState==ActorDeclState)
  {
    Q_ASSERT(this->_d->_curActor);
    if(_model->component(name)){
      appendDslError(ctx->getStart(),QString("There is already a component with name '%0' available!").arg(name));
      return;
    }
    this->_d->_curActor->setName(name);
    this->_d->_curActor->setText(this->_d->_curActor->toString());
  }
  else if(currListenerState==ComponentDeclState)
  {
    Q_ASSERT(this->_d->_curComp);
    if(_model->component(name)){
      appendDslError(ctx->getStart(),QString("There is already a component with name '%0' available!").arg(name));
      return;
    }
    this->_d->_curComp->setName(name);
    this->_d->_curComp->setText(this->_d->_curComp->toString());
  }

  return;
}

void IrdlModelListener::enterDescriptionDecl(IrdlParser::DescriptionDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::DescriptionDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::DescriptionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::DescriptionDeclContext::DescriptionID, this->_keywordTextLocations, Description);
}

void IrdlModelListener::exitDescriptionDecl(IrdlParser::DescriptionDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->STRING());

  QString descript=QString::fromStdString(ctx->STRING()->getText()).remove(QString("\""));

  int currListenerState = this->currentListenerState();
  if(currListenerState==IrdlState)
  {
    Q_ASSERT(this->_d->_regItem);
    this->_d->_regItem->setDescription(descript);
  }
  else if(currListenerState==ActorDeclState)
  {
    Q_ASSERT(this->_d->_curActor);
    this->_d->_curActor->setDescription(descript);
  }
  else if(currListenerState==ComponentDeclState)
  {
    Q_ASSERT(this->_d->_curComp);
    this->_d->_curComp->setDescription(descript);
  }

  return;
}

void IrdlModelListener::enterStateDecl(IrdlParser::StateDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::StateDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::StateDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::StateDeclContext::StateID, this->_keywordTextLocations, State);
}

void IrdlModelListener::exitStateDecl(IrdlParser::StateDeclContext *ctx)
{
  if(!ctx) return;
  auto lifelineList = ctx->lifelineList();
  while(lifelineList){
    if(lifelineList->componentIdPath()){
      if(const model::base::PortItem* item = getComponentFromPath(lifelineList->componentIdPath())){
        _d->_seqStack.front()->addStatement(static_cast<const model::msc::MscComponentItem*>(item->owner()),QString::fromStdString(ctx->contextID()->getText()));
      }
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("No Component with name \"")
                       + QString::fromStdString(lifelineList->componentIdPath()->getText())
                       + QStringLiteral("\" found!"));
        return;
      }
    }
    else if(lifelineList->AllID())
    {
      for(auto comp : _model->components())
      {
        _d->_seqStack.front()->addStatement(static_cast<model::msc::MscComponentItem*>(comp),QString::fromStdString(ctx->contextID()->getText()));
      }
      for (auto baseModel : this->_model->importedModels())
      {
        if(model::irdl::RequirementsModel* reqModel = dynamic_cast<model::irdl::RequirementsModel*>(baseModel))
        {
          for(auto component : reqModel->components())
          {
            if(auto modelItem = dynamic_cast<model::base::ModelItem*>(component))
            {
              this->_d->_currentPathItem = modelItem;
              break;
            }
          }
        }
      }
    }
    if(lifelineList->lifelineListOptional())
      lifelineList = lifelineList->lifelineListOptional()->lifelineList();
    else {
      break;
    }
  }
}

void IrdlModelListener::enterMessageDecl(IrdlParser::MessageDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::MessageDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::MessageDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::MessageDeclContext::MessageID, this->_keywordTextLocations, Message);
}

void IrdlModelListener::exitMessageDecl(IrdlParser::MessageDeclContext *ctx)
{
  if(!ctx || ctx->componentIdPath().size() != 2 || !(ctx->messageSignal())) return;
  if(auto source = getComponentFromPath(ctx->componentIdPath().at(0))){
    if(auto target = getComponentFromPath(ctx->componentIdPath().at(1))){
      if(auto signal = getSignalFromPath(ctx->messageSignal()->signalIdPath())){
        auto msg = _d->_seqStack.front()->addMessage(source,target,QString::fromStdString(ctx->messageSignal()->signalIdPath()->contextID().back()->getText()));
        msg->setSignal(signal);
        int sz = signal->params().size();
        int counter = 0;
        QListIterator<const model::msc::ParamItem*> paramIt(signal->params());
        auto bdy = ctx->messageSignal()->messageSignalBody();
        while(bdy){
          if(!(counter<sz)){
            appendDslError(ctx->getStart(),
                           QString("Signal \"%1\" has only %2 arguments!").arg(signal->name(),QString::number(sz)));
            return;
          }
          counter++;
          auto param = paramIt.next();
          QVariant val;
          if(auto asCtx = bdy->literalValue()){
            if(asCtx->TrueID() || asCtx->FalseID()){
              val = (asCtx->FalseID() == nullptr);
            }
            else if(asCtx->REAL()){
              val = (QString::fromStdString(asCtx->REAL()->getText()).toDouble());
            }
            else if(asCtx->INT()){
              val = (QString::fromStdString(asCtx->INT()->getText()).toInt());
            }
            else if(asCtx->STRING()){
              val = (QString::fromStdString(asCtx->STRING()->getText()));
            }
            else if(asCtx->contextID()){
              QString valStr(QString::fromStdString(asCtx->contextID()->getText()));
              auto importModel = _model->importedModels().value(QString("this"));
              auto datatypes = _model->dataTypes();
              if(_model->attribute(valStr) || (importModel && importModel->attribute(valStr)))
                val = /*QString("__IFAK_ATTRIBUTE__") +*/ QString::fromStdString(asCtx->contextID()->getText());
              else if(datatypes.size()){
                bool foundEnum = false;
                for(model::base::DataTypeItem* datatype : datatypes){
                  for(auto ident : datatype->literals()){
                    if(ident == QString::fromStdString(asCtx->contextID()->getText())){
                      foundEnum = true;
                      break;
                    }
                  }
                  if(foundEnum) break;
                }
                if(foundEnum){
                  val = /*QString("__IFAK_ATTRIBUTE__") +*/ QString::fromStdString(asCtx->contextID()->getText());
                }
                else{
                  appendDslError(ctx->getStart(),
                                 QString("No attribute or enum with the name \"%1\"!").arg(QString::fromStdString(asCtx->contextID()->getText())));
                }
                val = valStr;
              }
              else{
                appendDslError(ctx->getStart(),
                               QStringLiteral("Literal value was not readable!"));
                return;
              }
            }
          }
          else if (bdy->signalParamName()) {
            //                        val = QString("__IFAK_SIGNALPARAM__") + QString::fromStdString(bdy->attributeName()->getText());
            val = QString::fromStdString(bdy->signalParamName()->contextID()->getText());
          }
          else if (bdy->attributeIdPath()) {
            if(auto attrItem = getAttributeFromPath(bdy->attributeIdPath())){
              //                        val = QString("__IFAK_ATTRIBUTE__") + QString::fromStdString(bdy->attributeName()->getText());
              val = attrItem->name();
            }
          }
          if(param) msg->addParamValue(param,val);
          if(bdy->messageSignalBodyOptional()
             && bdy->messageSignalBodyOptional()->messageSignalBody())
            bdy = bdy->messageSignalBodyOptional()->messageSignalBody();
          else break;
        }
        this->_modelTextLocations->insert(msg->index(),
                                          TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                            ctx->getStop()->getStopIndex(),
                                                            Message));
      }
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("No Signal with name \"")
                       + QString::fromStdString(ctx->messageSignal()->signalIdPath()->getText())
                       + QStringLiteral("\" found!"));
        return;
      }
    }
    else if(ctx->componentIdPath().size() >1){
      appendDslError(ctx->getStart(),
                     QStringLiteral("No Component with name \"")
                     + QString::fromStdString(ctx->componentIdPath().at(1)->getText())
                     + QStringLiteral("\" found!"));
      return;
    }
    else{
      if(this->_errors){
        this->_errors->append(DslError(QString("Wrong Syntax!")));
      }
      return;
    }
  }
  else{
    appendDslError(ctx->getStart(),
                   QString("No Component with name \"")
                   + QString::fromStdString(ctx->componentIdPath().at(0)->getText())
                   + QString("\" found!"));
    return;
  }
}

void IrdlModelListener::enterTimerDecl(IrdlParser::TimerDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::TimerDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::TimerDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::TimerDeclContext::TimerID, this->_keywordTextLocations, Timer);
}

void IrdlModelListener::exitTimerDecl(IrdlParser::TimerDeclContext *ctx)
{
  if(!ctx) return;
  if(auto lifeLine = getComponentFromPath(ctx->componentIdPath())){
    QString errorString("");
    QString timerName = QString::fromStdString(ctx->contextID()->getText());
    auto timer = _d->_seqStack.front()->addTimer(static_cast<const model::msc::MscComponentItem*>(lifeLine->owner()),timerName,&errorString);
    _d->_timerItems.insert(timerName,timer);
    if(errorString != QString("")){
      appendDslError(ctx->getStart(),
                     errorString);
      return;
    }
    else{
      QString value = "";
      if(ctx->REAL()) value = QString::fromStdString(ctx->REAL()->getText());
      else if(ctx->INT()) value = QString::fromStdString(ctx->INT()->getText());
      double val = value.toDouble();
      if(ctx->SekID()) val *= 1000;
      timer->setValue(val);

      this->_modelTextLocations->insert(timer->index(),
                                        TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                          ctx->getStop()->getStopIndex(),
                                                          Timer));
    }
  }
}

void IrdlModelListener::exitTimerNameID(IrdlParser::TimerNameIDContext *ctx)
{
  if(!ctx) return;
  QString name = QString::fromStdString(ctx->getText());
  if(!_d->_timerItems.contains(name)){
    appendDslError(ctx->getStart(),
                   QString("No Timer with name \"")
                   + QString::fromStdString(ctx->getText())
                   + QString("\" found!"));
    return;
  }
}

void IrdlModelListener::exitAttributeAssignStatement(IrdlParser::AttributeAssignStatementContext *ctx)
{
  if(!ctx || !ctx->attributeIdPath().size()) return;
  const model::base::AttributeItem* attributeItem = getAttributeFromPath(ctx->attributeIdPath(0));
  QString errorString("");
  QVariant val;
  if(auto asCtx = ctx->literalValue()){
    if(asCtx->TrueID() || asCtx->FalseID()){
      val = (asCtx->FalseID() == nullptr);
    }
    else if(asCtx->REAL()){
      val = (QString::fromStdString(asCtx->REAL()->getText()).toDouble());
    }
    else if(asCtx->INT()){
      val = (QString::fromStdString(asCtx->INT()->getText()).toInt());
    }
    else if(asCtx->STRING()){
      val = (QString::fromStdString(asCtx->STRING()->getText()));
    }
    else if(asCtx->contextID()){
      QString valStr(QString::fromStdString(asCtx->contextID()->getText()));
      auto importModel = _model->importedModels().value(QString("this"));
      auto datatypes = _model->dataTypes();
      if(_model->attribute(valStr) || (importModel && importModel->attribute(valStr)))
        val = /*QString("__IFAK_ATTRIBUTE__") +*/ QString::fromStdString(asCtx->contextID()->getText());
      else if(datatypes.size()){
        bool foundEnum = false;
        for(model::base::DataTypeItem* datatype : datatypes){
          for(auto ident : datatype->literals()){
            if(ident == QString::fromStdString(asCtx->contextID()->getText())){
              foundEnum = true;
              break;
            }
          }
          if(foundEnum) break;
        }
        if(foundEnum){
          val = /*QString("__IFAK_ATTRIBUTE__") +*/ QString::fromStdString(asCtx->contextID()->getText());
        }
        else{
          appendDslError(ctx->getStart(),
                         QString("No attribute or enum with the name \"%1\"!").arg(QString::fromStdString(asCtx->contextID()->getText())));
        }
        val = valStr;
      }
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("Literal value was not readable!"));
        return;
      }
    }
  }
  else if (ctx->signalParamName()) {
    //                            val = QString("__IFAK_SIGNALPARAM__") + QString::fromStdString(ctx->attributeIdPath()[ctx->attributeIdPath().size()]->getText());
    val = QString::fromStdString(ctx->signalParamName()->contextID()->getText());
  }
  else if (ctx->attributeIdPath().size() == 2 && getAttributeFromPath(ctx->attributeIdPath(1)) && !ctx->attributeIdPath(1)->contextID().empty()) {
    //                            val = QString("__IFAK_ATTRIBUTE__") + QString::fromStdString(ctx->attributeIdPath()[ctx->attributeIdPath().size()]->getText());
    val = QString::fromStdString(ctx->attributeIdPath(1)->contextID().back()->getText());
  }

  if(attributeItem)
  {
    if(auto item = dynamic_cast<const model::msc::MscComponentItem*>(_d->_curCompOfAttributeItem))
        _d->_seqStack.first()->addStatement(item, QString("%0 = %1").arg(attributeItem->name(), val.toString()));
    else
    {
      auto component = getSystem();
      if(component){
        _d->_seqStack.first()->addStatement(component, QString("%0 = %1").arg(attributeItem->name(), val.toString()));
      }
    }
  }
  if(errorString != QString("")){
    appendDslError(ctx->getStart(),
                   errorString);
    return;
  }
}

void IrdlModelListener::enterCheckDeclBody(IrdlParser::CheckDeclBodyContext *ctx)
{
  IrdlParser::CheckDeclContext* parentCtx = (IrdlParser::CheckDeclContext*)ctx->parent;
  const model::msc::SignalItem* signal = getSignalFromPath(parentCtx->signalIdPath());
  if(parentCtx && signal){
    _d->_currentSignal = signal;
  }
}

void IrdlModelListener::addCheckAssign(model::msc::MscCheckMessageItem* check, IrdlParser::AttributeAssignContext* ctx)
{
  if(!ctx->attributeIdPath())
    return;
  if(!ctx->attributeIdPath()->attributeName())
    return;
  if(!ctx->signalParamName())
    return;
  check->appendAssign(QString::fromStdString(ctx->attributeIdPath()->attributeName()->getText()),
                      QString::fromStdString(ctx->signalParamName()->getText()));

  if(auto assignCtx = ctx->attributeAssign()){
    this->addCheckAssign(check, assignCtx);
  }
}

void IrdlModelListener::exitCheckDecl(IrdlParser::CheckDeclContext *ctx)
{
  if(!ctx                  || ctx->exception //||
     /*!ctx->checkDeclBody() || ctx->checkDeclBody()->exception*/) return;
  if(const model::base::PortItem* source = getComponentFromPath(ctx->componentIdPath().at(0))){
    if(const model::base::PortItem*  target = getComponentFromPath(ctx->componentIdPath().at(1))){
      if(const model::base::SignalItem* signal = getSignalFromPath(ctx->signalIdPath())){
        model::msc::MscCheckMessageItem* check = new model::msc::MscCheckMessageItem(source,target);
        check->setSignal(signal);
        if(ctx->checkDeclBody() && !ctx->checkDeclBody()->exception){
          check->setGuard(QString::fromStdString(
                            ctx->getStart()->getInputStream()->getText(
                              misc::Interval(ctx->checkDeclBody()->LBRACKET()->getSymbol()->getStartIndex()+1,ctx->checkDeclBody()->RBRACKET()->getSymbol()->getStopIndex()-1))));
          if(auto timeCtx = ctx->checkDeclBody()->timeOutDecl()){
            QString value = "";
            if(timeCtx->REAL()) value = QString::fromStdString(timeCtx->REAL()->getText());
            else if(timeCtx->INT()) value = QString::fromStdString(timeCtx->INT()->getText());
            else{
              appendDslError(timeCtx->getStart(),
                             QString("Timeout declaration has no value!"));
              return;
            }
            int val = value.toInt();
            if(timeCtx->SekID()) val *= 1000;
            check->setTimeout(val);
          }

          if (auto assignCtx = ctx->checkDeclBody()->attributeAssign()){
            this->addCheckAssign(check, assignCtx);
          }
        }
        _d->_seqStack.front()->addMessage(check);
        this->_modelTextLocations->insert(check->index(),
                                          TokenTextLocation(ctx->getStart()->getStartIndex(),
                                                            ctx->getStop()->getStopIndex(),
                                                            Check));

        _d->_currentSignal = nullptr;


        typedef  tree::TerminalNode* (IrdlParser::CheckDeclContext::*KeywordFunction)();

        addKeywordLocation<IrdlParser::CheckDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &IrdlParser::CheckDeclContext::CheckID, this->_keywordTextLocations, Check);
      }
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("No Signal with name \"")
                       + QString::fromStdString(ctx->signalIdPath()->getText())
                       + QStringLiteral("\" found!"));
        return;
      }
    }
    else{
      appendDslError(ctx->getStart(),
                     QString("No Component with name \"")
                     + QString::fromStdString(ctx->componentIdPath().at(1)->getText())
                     + QString("\" found!"));
      return;
    }
  }
  else{
    appendDslError(ctx->getStart(),
                   QString("No Component with name \"")
                   + QString::fromStdString(ctx->componentIdPath().at(0)->getText())
                   + QString("\" found!"));
    return;
  }
}

void IrdlModelListener::enterAltDecl(IrdlParser::AltDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::AltDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::AltDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::AltDeclContext::AltID, this->_keywordTextLocations, Alt);

  model::msc::MscFragmentItem * fragItem =
      new model::msc::MscFragmentItem(model::msc::FragmentType::AlternativeFragment);
  _d->_altStack.push_front(fragItem);
  _d->_seqStack.front()->addFragment(fragItem);
}

void IrdlModelListener::exitAltDecl(IrdlParser::AltDeclContext *ctx)
{
  Q_UNUSED(ctx);
  _d->_altStack.pop_front();
}

void IrdlModelListener::enterAltBody(IrdlParser::AltBodyContext *ctx)
{
  Q_UNUSED(ctx);
  auto fragItem = _d->_altStack.front();
  _d->_seqStack.push_front(fragItem->addRegion(QString("")));
}

void IrdlModelListener::exitAltBody(IrdlParser::AltBodyContext *ctx)
{
  if(!ctx)return;
  auto fragItem = static_cast<model::msc::MscFragmentRegionItem*>(_d->_seqStack.front());
  QString cond;
  if(!ctx->expression()) cond = QString("true");
  else cond = QString::fromStdString(ctx->expression()->getText());
  fragItem->setCondition(cond);
  _d->_seqStack.pop_front();
}

void IrdlModelListener::enterDurationDecl(IrdlParser::DurationDeclContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::DurationDeclContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::DurationDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::DurationDeclContext::DurationID, this->_keywordTextLocations, Duration);

  model::msc::MscFragmentItem * fragItem = new model::msc::MscFragmentItem(model::msc::DurationFragment);
  _d->_seqStack.front()->addFragment(fragItem);
  model::msc::MscFragmentRegionItem* reg = fragItem->addRegion(QString("DurationRegion"));
  fragItem->setText("Duration");
  _d->_seqStack.push_front(reg);
  _d->_curDurFrag.push_front(fragItem);
}
/*
void IrdlModelListener::enterDurationElseDecl(IrdlParser::DurationElseDeclContext *ctx)
{
  if(!ctx || ctx->exception) return;
  QString value = "";
  IrdlParser::DurationDeclContext *durCtx = dynamic_cast<IrdlParser::DurationDeclContext *>(ctx->parent);
  if(durCtx->REAL()) value = QString::fromStdString(durCtx->REAL()->getText());
  else if(durCtx->INT()) value = QString::fromStdString(durCtx->INT()->getText());
  uint val = value.toUInt();
  if(durCtx->SekID()) val *= 1000;
  model::msc::MscFragmentItem * fragItem = static_cast<model::msc::MscFragmentItem *>(_d->_curDurFrag.front());
  _d->_seqStack.pop_front();
  fragItem->setDuration(val);
  fragItem->regions().front()->setCondition(QString("Duration = %1ms").arg(val));

  model::msc::MscFragmentRegionItem* reg = fragItem->addRegion(QString("DurationElseRegion"));
  fragItem->setText("DurationElse");
  _d->_seqStack.push_front(reg);
}
*/

void IrdlModelListener::exitDurationDecl(IrdlParser::DurationDeclContext *ctx)
{
  if(!ctx || ctx->exception) return;
  QString value = "";
  //IrdlParser::DurationDeclContext *durCtx = dynamic_cast<IrdlParser::DurationDeclContext *>(ctx->parent);
  if(ctx->REAL()) value = QString::fromStdString(ctx->REAL()->getText());
  else if(ctx->INT()) value = QString::fromStdString(ctx->INT()->getText());
  uint val = value.toUInt();
  if(ctx->SekID()) val *= 1000;
  model::msc::MscFragmentItem * fragitem = static_cast<model::msc::MscFragmentItem *>(_d->_curDurFrag.front());
  _d->_seqStack.pop_front();
  _d->_curDurFrag.pop_front();
  fragitem->setDuration(val);
  fragitem->regions().front()->setCondition(QString(""));
}

void IrdlModelListener::enterImportPathBody(IrdlParser::ImportPathBodyContext *ctx)
{
  Q_ASSERT(ctx);

  typedef  tree::TerminalNode* (IrdlParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);
}

void IrdlModelListener::exitImportPathBody(IrdlParser::ImportPathBodyContext *ctx)
{
  if(ctx->exception || !ctx->importFileBody())
    return;
  typedef  tree::TerminalNode* (IrdlParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);

  QString path = QString::fromStdString(ctx->importFileBody()->getText());
  path = _d->_praefix + path;
  QFile file(path);
  if(!file.open(QFile::ReadOnly)){
    appendDslError(ctx->getStart(),
                   QString("Import File couldn't be opened"));
    return;
  }
  QString docText(file.readAll());
  file.close();

  if(path.endsWith(QString(".requirement")))
  {
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QString("this");
      //            name = path;
    }

    model::irdl::RequirementsModel* irdlModel = new model::irdl::RequirementsModel(/*,_model*/);
    dslparser::irdl::ComBuildIrdlModel command(docText, irdlModel,_d->_praefix);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      if(name == QString("this")){
        QString err("");
        _model->addContent(irdlModel,&err);
        if(err != QString("")){
          appendDslError(ctx->getStart(),err);
        }
        return;
      }
      this->_d->_importModels.insert(name,irdlModel);
      this->_model->removeImportedModel(name);
      if(!this->_model->addImportedModel(name,irdlModel,&errorString))
      {
        appendDslError(ctx->getStart(),
                       errorString);
        return;
      }
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QString("Import File contains errors!"));
      if(this->_errors)
        this->_errors->append(command.errors());
      return;
    }
  }
  else if(path.endsWith(QString(".decl"))){
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QString("this");
      //            name = path;
    }

    model::base::BaseModel* baseModel = new model::base::BaseModel(/*,_model*/);
    dslparser::common::ComBuildBaseModel command(docText, baseModel);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      if(name == QString("this")){
        QString err("");
        _model->addContent(baseModel,&err);
        if(err != QString("")){
          appendDslError(ctx->getStart(),err);
        }
        return;
      }
      this->_model->removeImportedModel(name);
      if(!this->_model->addImportedModel(name,baseModel,&errorString))
      {
        Token* startToken = ctx->getStart();
        Token* stopToken = ctx->getStop();
        Q_ASSERT(startToken);
        Q_ASSERT(stopToken);
        if(this->_errors){
          this->_errors->append(command.errors());
        }
        return;
      }
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QString("Import File contains errors!"));
      if(this->_errors)
        this->_errors->append(command.errors());
      return;
    }
  }
  else if(path.endsWith(QString(".irdldecl"))){
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QString("this");
      //            name = path;
    }

    model::irdl::RequirementsModel* baseModel = new model::irdl::RequirementsModel(/*,_model*/);
    dslparser::irdl::ComBuildIrdlDeclModel command(docText, baseModel);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      if(name == QString("this")){
        QString err("");
        _model->addContent(baseModel,&err);
        if(err != QString("")){
          appendDslError(ctx->getStart(),err);
        }
        return;
      }
      this->_d->_importModels.insert(name,baseModel);
      this->_model->removeImportedModel(name);
      if(!this->_model->addImportedModel(name,baseModel,&errorString))
      {
        appendDslError(ctx->getStart(),
                       errorString);
        return;
      }
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QString("Import File contains errors!"));
      if(this->_errors)
        this->_errors->append(command.errors());
      return;
    }
  }
}

void IrdlModelListener::enterRequirementBody(IrdlParser::RequirementBodyContext *ctx)
{
  typedef  tree::TerminalNode* (IrdlParser::RequirementBodyContext::*KeywordFunction)();

  addKeywordLocation<IrdlParser::RequirementBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &IrdlParser::RequirementBodyContext::DeclarationID, this->_keywordTextLocations, Declaration);
}

void IrdlModelListener::exitFunctionCallBody(IrdlParser::FunctionCallBodyContext *ctx)
{
  Q_UNUSED(ctx);
  _d->_currentSignal = nullptr;
}

void IrdlModelListener::exitAtom(IrdlParser::AtomContext *ctx)
{
  if(auto asCtx = ctx->literalValue()){
    if(asCtx->TrueID() || asCtx->FalseID());
    else if(asCtx->REAL());
    else if(asCtx->INT());
    else if(asCtx->STRING());
    else if(asCtx->contextID()){
      QString valStr(QString::fromStdString(asCtx->contextID()->getText()));
      auto importModel = _model->importedModels().value(QString("this"));
      auto datatypes = _model->dataTypes();
      if(_model->attribute(valStr) || (importModel && importModel->attribute(valStr)));
      else if(_d->_timerItems.contains(valStr)); // if atom is Timer break;
      else if(datatypes.size()){
        bool foundEnum = false;
        for(model::base::DataTypeItem* datatype : datatypes){
          for(auto ident : datatype->literals()){
            if(ident == QString::fromStdString(asCtx->contextID()->getText())){
              foundEnum = true;
              break;
            }
          }
          if(foundEnum) break;
        }
        if(!foundEnum){
          appendDslError(ctx->getStart(),
                         QString("No attribute or enum with the name '%1'!").arg(QString::fromStdString(asCtx->contextID()->getText())));
        }
      }
      else{
        appendDslError(ctx->getStart(),
                       QString("Literal value was not readable!"));
        return;
      }
    }
  }
  else if (ctx->signalParamName());
  else if (ctx->attributeIdPath() && ctx->attributeIdPath()->contextID().size()){
    getAttributeFromPath(ctx->attributeIdPath());
  }
  else if (ctx->contextID());
  else if (ctx->timerNameID()){
    QString timerName = QString::fromStdString(ctx->timerNameID()->getText());
    if(!_d->_timerItems.contains(timerName))
      appendDslError(ctx->getStart(),
                     QString("Timer doesn't exist!"));
  }
  else{
    appendDslError(ctx->getStart(),
                   QString("Atom '%1' doesn't conform to any standard").arg(QString::fromStdString(ctx->getText())));
    return;
  }
}

void IrdlModelListener::exitSignalParamName(IrdlParser::SignalParamNameContext *ctx)
{
  if(!ctx || ctx->exception) return;
  if(!_d->_currentSignal || !ctx->contextID() || !_d->_currentSignal->parameter(QString::fromStdString(ctx->contextID()->getText()))){
    appendDslError(ctx->getStart(),
                   QString("Either you are using \"msg\" in the wrong context or the current message doen't have a parameter named \"%0\".").arg(QString::fromStdString(ctx->contextID()->getText())));
    return;
  }
}

void IrdlModelListener::exitSignalIdPath(IrdlParser::SignalIdPathContext *ctx)
{
  if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ctx->parent))
  {
    if(parentRuleCtx->getRuleIndex() == IrdlParser::RuleCheckDecl
       || parentRuleCtx->getRuleIndex() == IrdlParser::RuleFunctionCall
       || parentRuleCtx->getRuleIndex() == IrdlParser::RuleMessageSignal){
      _d->_currentSignal = getSignalFromPath(ctx);
    }
  }
}

void IrdlModelListener::exitDeclarations(IrdlParser::DeclarationsContext *ctx)
{
  if(!getSystem()){
    appendDslError(ctx->stop,
                 QString("Every Requirementsmodel needs to define a 'system' component!"));
  }
}

void IrdlModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);

  //  qDebug()<<"IrdlModelListener::visitErrorNode() "
  //            "state: "<<this->_d->_listenerStates.top()
  //         <<"error node: "<<node->toString().c_str();

  return;
}

const model::msc::MscComponentItem *IrdlModelListener::getSystem()
{
  auto component = _model->component("system");
  if(!component){
    model::irdl::RequirementsModel* importModel = dynamic_cast<model::irdl::RequirementsModel*>(_model->importedModels().value(QString("this")));
    if(importModel)
      component = importModel->component("system");
  }
  if(!component){
    return getAlias("system");
  }
  return dynamic_cast<const model::msc::MscComponentItem *>(component);
}

const model::msc::MscComponentItem *IrdlModelListener::getAlias(QString name)
{
  if(this->_d->_IrdlCompItems.contains(name)){
    return this->_d->_IrdlCompItems.value(name);
  }
  return 0;
}

const model::base::PortItem* IrdlModelListener::getComponentFromPath(IrdlParser::ComponentIdPathContext* compPath)
{
  if(!compPath || compPath->exception)
    return nullptr;
  auto path = compPath->contextID();
  uint8_t sz = path.size();
  QString importModelStr;
  QString compStr;
  const model::base::PortItem* res = nullptr;

  switch (sz) {
  case 3:
    importModelStr = QString::fromStdString(path.at(0)->getText());
    if(const model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      compStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::ComponentItem* comp = reqModel->component(compStr)){
        auto portStr = QString::fromStdString(path.at(2)->getText());
        if(const model::base::PortItem* port = comp->port(portStr)){
          return port;
        }
        appendDslError(path.at(2)->getStart(),
                       QString("\"%1\" is not a valid Port of Component \"%2\".").arg(portStr,compStr));
        return nullptr;
      }
      appendDslError(path.at(1)->getStart(),
                     QString("\"%1\" is not a valid Component of imported Model \"%2\".").arg(compStr,importModelStr));
      return nullptr;
    }
    appendDslError(path.at(0)->getStart(),
                   QString("\"%1\" is not a valid imported Model.").arg(importModelStr));
    return nullptr;
    break;
  case 2:
    compStr = QString::fromStdString(path.at(0)->getText());
    if(const model::base::ComponentItem* comp = _model->component(compStr)){
      auto portStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::PortItem* port = comp->port(portStr)){
        res = port;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid Port of Component \"%2\".").arg(portStr,compStr));
        return nullptr;
      }
    }
    if(const model::msc::MscComponentItem* comp = getAlias(compStr)){
      auto portStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::PortItem* port = comp->port(portStr)){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else res = port;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid Port of Component \"%2\".").arg(portStr,compStr));
        return nullptr;
      }
    }
    importModelStr = compStr;
    if(const model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      compStr = QString::fromStdString(path.at(1)->getText());
      if(const model::msc::MscComponentItem* comp = static_cast<const model::msc::MscComponentItem*>(reqModel->component(compStr))){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else res = static_cast<const model::base::PortItem*>(comp->defaultPort());
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid Component of imported model \"%2\".").arg(compStr,importModelStr));
        return nullptr;
      }
    }
    if(res) return res;
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  case 1:
    if(model::msc::MscComponentItem* comp = static_cast<model::msc::MscComponentItem*>(_model->component(QString::fromStdString(path.at(0)->getText())))){
      if(res){
        appendDslError(path.at(0)->getStart(),
                       QString("Path is ambiguous!"));
        return nullptr;
      }
      else res = static_cast<const model::base::PortItem*>(comp->defaultPort());
    }
    if(const model::msc::MscComponentItem* comp = getAlias(QString::fromStdString(path.at(0)->getText()))){
      if(res){
        appendDslError(path.at(0)->getStart(),
                       QString("Path is ambiguous!"));
        return nullptr;
      }
      else res = comp->defaultPort();
    }
    if(res) return res;
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  case 0:
    appendDslError(compPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  default:
    appendDslError(compPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  }
}

const model::base::SignalItem *IrdlModelListener::getSignalFromPath(IrdlParser::SignalIdPathContext* signalPath)
{
  if(!signalPath || signalPath->exception)
    return nullptr;
  auto path = signalPath->contextID();
  uint8_t sz = path.size();
  QString importModelStr;
  QString signalStr;

  switch (sz) {
  case 2:
    importModelStr = QString::fromStdString(path.at(0)->getText());
    if(model::base::BaseModel* reqModel = _model->importedModels().value(importModelStr)){
      signalStr = QString::fromStdString(path.at(1)->getText());
      if(model::base::SignalItem* sig = reqModel->signal(signalStr)){
        return sig;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid signal of imported model \"%2\".").arg(signalStr,importModelStr));
        return nullptr;
      }
    }
    appendDslError(signalPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  case 1:
    signalStr = QString::fromStdString(path.at(0)->getText());
    if(model::base::SignalItem* sig = _model->signal(signalStr)){
      return sig;
    }
    else{
      appendDslError(path.at(0)->getStart(),
                     QString("\"%1\" is not a valid signal.").arg(signalStr,importModelStr));
      return nullptr;
    }
    break;
  case 0:
    appendDslError(signalPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  default:
    appendDslError(signalPath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  }
  return nullptr;
}

const model::base::AttributeItem *IrdlModelListener::getAttributeFromPath(IrdlParser::AttributeIdPathContext *attributePath)
{
  if(!attributePath || attributePath->exception)
    return nullptr;
  auto path = attributePath->contextID();
  model::base::BaseModel* importModel = _model->importedModels().value(QString("this"));
  uint8_t sz = path.size();
  QString attrName("");
  if(!sz){
    if(attributePath->attributeName() && attributePath->attributeName()->contextID()){
      attrName = QString::fromStdString(attributePath->attributeName()->contextID()->getText());
    }
  }
  QString importModelStr;
  QString compStr;
  const model::base::AttributeItem* res = nullptr;

  switch (sz) {
  case 3:
    importModelStr = QString::fromStdString(path.at(0)->getText());
    if(const model::irdl::RequirementsModel* reqModel = _d->_importModels.value(importModelStr)){
      compStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::ComponentItem* comp = reqModel->component(compStr)){
        auto attributeStr = QString::fromStdString(path.at(2)->getText());
        if(model::base::AttributeItem* attribute = comp->attribute(attributeStr)){
          _d->_curCompOfAttributeItem = comp;
          return attribute;
        }
        appendDslError(path.at(2)->getStart(),
                       QString("\"%1\" is not a valid attribute of Component \"%2\".").arg(attributeStr,compStr));
        return nullptr;
      }
      appendDslError(path.at(1)->getStart(),
                     QString("\"%1\" is not a valid Component of imported Model \"%2\".").arg(compStr,importModelStr));
      return nullptr;
    }
    appendDslError(path.at(0)->getStart(),
                   QString("\"%1\" is not a valid imported Model.").arg(importModelStr));
    return nullptr;
    break;
  case 2:
    compStr = QString::fromStdString(path.at(0)->getText());
    if(const model::base::ComponentItem* comp = _model->component(compStr)){
      auto attributeStr = QString::fromStdString(path.at(1)->getText());
      if(const model::base::AttributeItem* attribute = comp->attribute(attributeStr)){
        _d->_curCompOfAttributeItem = comp;
        res = attribute;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid attribute of Component \"%2\".").arg(attributeStr,compStr));
        return nullptr;
      }
    }
    if(const model::msc::MscComponentItem* comp = getAlias(compStr)){
      auto attributeStr = QString::fromStdString(path.at(1)->getText());
      if(model::base::AttributeItem* attribute = comp->attribute(attributeStr)){
        if(res){
          _d->_curCompOfAttributeItem = nullptr;
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else{
          res = attribute;
        }
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid attribute of Component \"%2\".").arg(attributeStr,compStr));
        return nullptr;
      }
    }
    importModelStr = compStr;
    if(model::base::BaseModel* reqModel = _model->importedModels().value(importModelStr)){
      auto attributeStr = QString::fromStdString(path.at(1)->getText());
      if(model::base::AttributeItem* attr = (reqModel->attribute(attributeStr))){
        if(res){
          res = nullptr;
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!"));
          return nullptr;
        }
        else res = attr;
      }
      else{
        appendDslError(path.at(1)->getStart(),
                       QString("\"%1\" is not a valid attribute of imported model \"%2\".").arg(attributeStr,importModelStr));
        return nullptr;
      }
    }
    if(auto reqModel = dynamic_cast<model::irdl::RequirementsModel*>(importModel))
      if(model::base::ComponentItem* comp = (reqModel->component(compStr))){
        auto attributeStr = QString::fromStdString(path.at(1)->getText());
        if(model::base::AttributeItem* attr = (comp->attribute(attributeStr))){
          if(res){
            res = nullptr;
            appendDslError(path.at(0)->getStart(),
                           QString("Path is ambiguous!"));
            return nullptr;
          }
          else res = attr;
        }
        else{
          appendDslError(path.at(1)->getStart(),
                         QString("\"%1\" is not a valid attribute of imported model \"%2\".").arg(attributeStr,importModelStr));
          return nullptr;
        }
      }

    if(res) return res;
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
  case 1:
    if(model::base::AttributeItem* attr = _model->attribute(QString::fromStdString(path.at(0)->getText()))){
      if(res){
        appendDslError(path.at(0)->getStart(),
                       QString("Path is ambiguous!") );
        return nullptr;
      }
      res = attr;
    }
    if(importModel){
      if(model::base::AttributeItem* attr = importModel->attribute(QString::fromStdString(path.at(0)->getText()))){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!") );
          return nullptr;
        }
        res = attr;
      }
    }
    if(res) return res;
    appendDslError(path.at(0)->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  case 0:
    if(model::base::AttributeItem* attr = _model->attribute(attrName)){
      if(res){
        appendDslError(path.at(0)->getStart(),
                       QString("Path is ambiguous!") );
        return nullptr;
      }
      res = attr;
    }
    if(importModel){
      if(model::base::AttributeItem* attr = importModel->attribute(attrName)){
        if(res){
          appendDslError(path.at(0)->getStart(),
                         QString("Path is ambiguous!") );
          return nullptr;
        }
        res = attr;
      }
    }
    if(res) return res;
    appendDslError(attributePath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  default:
    appendDslError(attributePath->getStart(),
                   QString("Path is not a allowed format!"));
    return nullptr;
    break;
  }
}

} // namespace irdl
} // namespace dslparser
