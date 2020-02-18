#include "simsystemmodellistener.hpp"

#include "simsystemitem.hpp"
#include "simsystemmodel.hpp"
#include "simconnectionitem.hpp"
#include "simconfigitem.hpp"
#include "simmodelitem.hpp"

#include <QStack>
#include <QDebug>
#include <QDir>

#include <exception>

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/statemachine/statemachine.hpp>

#include <dslparser/statemachine/combuildstatemachinemodel.hpp>
#include <dslparser/spenat/combuildspenatmodel.hpp>

using namespace model::base;
using namespace antlr4;
using namespace dslparser;

namespace modsim {

using dslparser::common::addKeywordLocation;
using dslparser::common::addSimpleKeywordLocation;

class SimSystemModelListener::Private
{
  friend class SimSystemModelListener;

  ImportSpenatModelList       _importedSpenatModels;
  ImportStatemachineModelList _importedStatemachineModels;

  QString                     _prefix;

  tree::ErrorNode*            _errorNode = nullptr;

  explicit Private(const QString& prefix)
    : _prefix(prefix)
  {}

  bool fillMessageData(model::base::PropDataTypes const* dataTypes,
                       SignalItem const* signalItem,
                       const QStringList& paramValueStrings,
                       QVariantList* messageData,
                       QString* errorString) const;
};

bool SimSystemModelListener::Private::fillMessageData(PropDataTypes const* dataTypes,
                                                      const SignalItem* signalItem,
                                                      const QStringList& paramValueStrings,
                                                      QVariantList* messageData,
                                                      QString* errorString) const
{
  Q_ASSERT(signalItem);
  if(paramValueStrings.empty())
    return true;
  Q_ASSERT(messageData);

  auto signalParams = signalItem->params();
  if(signalParams.size()!=paramValueStrings.size())
  {
    utils::AddPtrString(errorString)<<"no valid parameter count, signal '"<<signalItem->name()<<"' expect "
                                   <<signalParams.size()<<" parameter!";
    return false;
  }

  int pos=0;
  for(auto signalParam : signalParams)
  {
    const QString& paramStringValue=paramValueStrings.at(pos);
    DataTypeItem const* paramDataType=dataTypes->dataType(signalParam->dataType());
    if(!paramDataType)
    {
      utils::AddPtrString(errorString)<<"data type '"<<signalParam->dataType()<<"' of "
                                     <<pos<<"th parameter is not available!";
      return false;
    }

    QVariant paramVariantValue=paramDataType->stringValueToVariant(paramStringValue);
    if(paramVariantValue.isNull())
    {
      utils::AddPtrString(errorString)<<"values of data type '"
                                     <<signalParam->dataType()
                                    <<"' are not supported!";
      return false;
    }

    messageData->append(paramVariantValue);
  }

  return  true;
}

SimSystemModelListener::SimSystemModelListener(SimSystemItem* simsystemDeclModel,
                                               DslErrorList* simsystemErrors,
                                               const QString& prefix,
                                               TokenTextLocations* keywordTextLocations,
                                               ModelTextLocations* modelTextLocations)
  : BaseClass(simsystemDeclModel, simsystemErrors, keywordTextLocations, modelTextLocations),
    _d(new Private(prefix))
{
  Q_ASSERT(simsystemDeclModel);
}

SimSystemModelListener::~SimSystemModelListener()
{
  delete this->_d;
}

const ImportSpenatModelList& SimSystemModelListener::importedSpenatModels() const
{
  return _d->_importedSpenatModels;
}

const ImportStatemachineModelList& SimSystemModelListener::importedStatemachineModels() const
{
  return _d->_importedStatemachineModels;
}

void SimSystemModelListener::enterSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext* ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  this->_listenerStates.push(SimSystemDeclState);

  typedef  tree::TerminalNode* (SimSystemDeclParser::SimSystemDeclContext::*KeywordFunction)();
  addKeywordLocation<SimSystemDeclParser::SimSystemDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::SimSystemDeclContext::SimSystemID, this->_keywordTextLocations, SimSystem);

  return;
}

void SimSystemModelListener::exitSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  this->_listenerStates.pop();

  Q_ASSERT(ctx->contextID());
  QString name=QString::fromStdString(ctx->contextID()->getText());
  this->_model->setName(name);
  this->_model->setText(name);

  return;
}

void SimSystemModelListener::enterActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext* ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  typedef  tree::TerminalNode* (SimSystemDeclParser::ActorDeclBodyContext::*KeywordFunction)();

  return addKeywordLocation<SimSystemDeclParser::ActorDeclBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::ActorDeclBodyContext::ActorID, this->_keywordTextLocations, SimSystemActor);
}

void SimSystemModelListener::exitPortDecl(SimSystemDeclParser::PortDeclContext* ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  typedef  tree::TerminalNode* (SimSystemDeclParser::PortDeclContext::*KeywordFunction)();

  return addKeywordLocation<SimSystemDeclParser::PortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::PortDeclContext::PortID, this->_keywordTextLocations, Port);
}

void SimSystemModelListener::exitActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  Q_ASSERT(ctx->contextID());

  QString actorName=QString::fromStdString(ctx->contextID()->getText());
  QScopedPointer<SimActorItem> simActor(new SimActorItem(actorName));

  if(ctx->actorBodyContent())
  {
    for(SimSystemDeclParser::PortDeclContext* portDeclCtx : ctx->actorBodyContent()->portDecl())
    {
      for(auto contextIdCtx : portDeclCtx->contextID())
      {
        QString portName = QString::fromStdString(contextIdCtx->getText());
        QString errorString;
        bool result=simActor->addPort(portName, &errorString);
        if(!result)
        {
          appendDslError(contextIdCtx->getStart(), errorString);
          return;
        }
      }
    }
  }

  QString errorString;
  bool result = this->_model->simConfigItem()->addSimActor(simActor.take(), &errorString);
  if(!result)
    appendDslError(ctx->contextID()->getStart(), errorString);

  return;
}

void SimSystemModelListener::exitConnectionDecl(SimSystemDeclParser::ConnectionDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  typedef  tree::TerminalNode* (SimSystemDeclParser::ConnectionDeclContext::*KeywordFunction)();

  return addKeywordLocation<SimSystemDeclParser::ConnectionDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::ConnectionDeclContext::ConnectionID, this->_keywordTextLocations, Connection);

}

void SimSystemModelListener::exitConfigDecl(SimSystemDeclParser::ConfigDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  typedef  tree::TerminalNode* (SimSystemDeclParser::ConfigDeclContext::*KeywordFunction)();

  return addKeywordLocation<SimSystemDeclParser::ConfigDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::ConfigDeclContext::ConfigID, this->_keywordTextLocations, Config);
}

void SimSystemModelListener::exitStartSequenceDecl(SimSystemDeclParser::StartSequenceDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  typedef  tree::TerminalNode* (SimSystemDeclParser::StartSequenceDeclContext::*KeywordFunction)();

  return addKeywordLocation<SimSystemDeclParser::StartSequenceDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::StartSequenceDeclContext::StartSequenceID, this->_keywordTextLocations, StartSequence);
}

void SimSystemModelListener::exitMessageDecl(SimSystemDeclParser::MessageDeclContext* ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (SimSystemDeclParser::MessageDeclContext::*KeywordFunction)();

  return addKeywordLocation<SimSystemDeclParser::MessageDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::MessageDeclContext::MessageID, this->_keywordTextLocations, Message);
}

void SimSystemModelListener::exitStartupDecl(SimSystemDeclParser::StartupDeclContext* ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  typedef  tree::TerminalNode* (SimSystemDeclParser::StartupDeclContext::*KeywordFunction)();

  addKeywordLocation<SimSystemDeclParser::StartupDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::StartupDeclContext::StartupID, this->_keywordTextLocations, Startup);

  if(!ctx->startupBody())
    return;
  if(!ctx->startupBody()->messageDeclOptional())
    return;

  auto messageDeclOptCtx = ctx->startupBody()->messageDeclOptional();
  while(messageDeclOptCtx)
  {
    auto messageDeclCtx=messageDeclOptCtx->messageDecl();
    messageDeclOptCtx=messageDeclOptCtx->messageDeclOptional();

    if(!messageDeclCtx)
      continue;

    addSimpleKeywordLocation<TokenTextLocations>(messageDeclCtx->RightArrow(),
                                                 this->_keywordTextLocations,
                                                 RightArrow);
    //component-ports
    auto componentPorts = messageDeclCtx->componentIdPath();
    if(componentPorts.size()!=2)
    {
      appendDslError(messageDeclCtx->getStart(),
                     QLatin1String("no valid representation for source and target of this message"));
      return;
    }

    auto sourcePort=componentPorts.at(0);
    auto sourceContextIds = sourcePort->contextID();
    if(sourceContextIds.size()!=2)
    {
      appendDslError(sourcePort->getStart(),
                     QLatin1String("no valid representation for source port of this message"));
      return;
    }

    QString sourceCompName=QString::fromStdString(sourceContextIds.at(0)->getText());
    QString sourcePortName=QString::fromStdString(sourceContextIds.at(1)->getText());
    QString errorString;
    bool result=this->validModelPort(sourceCompName, sourcePortName, &errorString);
    if(!result)
    {
      appendDslError(sourcePort->getStart(), errorString);
      return;
    }

    auto targetPort=componentPorts.at(1);
    auto targetContextIds = targetPort->contextID();
    if(targetContextIds.size()!=2)
    {
      appendDslError(sourcePort->getStart(),
                     QLatin1String("no valid representation for target port of this message"));
      return;
    }

    QString targetCompName=QString::fromStdString(targetContextIds.at(0)->getText());
    QString targetPortName=QString::fromStdString(targetContextIds.at(1)->getText());
    result=this->validModelPort(targetCompName, targetPortName, &errorString);
    if(!result)
    {
      appendDslError(targetPort->getStart(), errorString);
      return;
    }

    //message signal
    if(!messageDeclCtx->messageSignal())
      continue;
    if(!messageDeclCtx->messageSignal()->signalIdPath())
      continue;

    auto signalIds=messageDeclCtx->messageSignal()->signalIdPath()->contextID();
    if(signalIds.size()!=1)
    {
      appendDslError(messageDeclCtx->messageSignal()->signalIdPath()->getStart(),
                     QLatin1String("no valid representation for the message name!"));
      return;
    }

    QString signalName=QString::fromStdString(signalIds.at(0)->getText());
    SignalItem const* messageSignal=this->findMessageSignal(targetCompName,
                                                            signalName,
                                                            &errorString);
    if(!messageSignal)
    {
      appendDslError(messageDeclCtx->messageSignal()->signalIdPath()->getStart(),
                     errorString);
      return;
    }

    //message data
    QStringList messageParamStrings;
    for(auto messageParamValue : messageDeclCtx->messageSignal()->messageParamValue())
      messageParamStrings.append(QString::fromStdString(messageParamValue->getText()));

    BaseModel const* dataTypesModel=this->_d->_importedStatemachineModels.value(targetCompName);
    if(!dataTypesModel)
      dataTypesModel=this->_d->_importedSpenatModels.value(targetCompName);
    Q_ASSERT(dataTypesModel);//it has to be available -> see above!

    QVariantList messageData;
    result = this->_d->fillMessageData(dataTypesModel,
                                       messageSignal,
                                       messageParamStrings,
                                       &messageData,
                                       &errorString);
    if(!result)
    {
      appendDslError(messageDeclCtx->messageSignal()->signalIdPath()->getStop(), errorString);
      return;
    }

    SimMessageItem* newStartupMessage=new SimMessageItem(signalName);
    newStartupMessage->setSource(sourceCompName, sourcePortName);
    newStartupMessage->setTarget(targetCompName, targetPortName);
    newStartupMessage->setMessageData(messageData);

    Q_ASSERT(this->_model->simConfigItem());
    this->_model->simConfigItem()->addStartupMessage(newStartupMessage);
  }

  return;
}

void SimSystemModelListener::exitConnectionBody(SimSystemDeclParser::ConnectionBodyContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  if(ctx->componentIdPath().size() == 2)
  {
    addSimpleKeywordLocation<TokenTextLocations>(ctx->DoubleArrow(),
                                                 this->_keywordTextLocations,
                                                 DoubleArrow);

    QScopedPointer<SimConnectionItem> item(new SimConnectionItem);
    SimSystemDeclParser::ComponentIdPathContext* compCtx = ctx->componentIdPath()[0];
    if(compCtx->contextID().size() > 0){
      QString modelName = QString::fromStdString(compCtx->contextID()[0]->getText());
      if(_d->_importedSpenatModels.contains(modelName)){
        item->setSourceModel(modelName);
        const model::spenat::SpenatDeclModel* spenatModel = _d->_importedSpenatModels.value(modelName);
        QString portName = QString::fromStdString(compCtx->contextID()[1]->getText());
        if(spenatModel->port(portName)){
          item->setSourcePort(portName);
        }
        else{
          appendDslError(compCtx->contextID()[1]->getStart(),
              QString("Connection model has no port with name '%0'!").arg(portName));
        }
      }
      else if(_d->_importedStatemachineModels.contains(modelName)){
        item->setSourceModel(modelName);
        const model::statemachine::StateMachineModel* statemachineModel = _d->_importedStatemachineModels.value(modelName);
        QString portName = QString::fromStdString(compCtx->contextID()[1]->getText());
        if(statemachineModel->port(portName)){
          item->setSourcePort(portName);
        }
        else{
          appendDslError(compCtx->contextID()[1]->getStart(),
              QString("Connection model has no port with name '%0'!").arg(portName));
        }
      }
    }
    else{
      appendDslError(ctx->getStart(),
                     QString("Connection has no source!"));
    }
    compCtx = ctx->componentIdPath()[1];
    if(compCtx->contextID().size() > 0){
      QString modelName = QString::fromStdString(compCtx->contextID()[0]->getText());
      if(_d->_importedSpenatModels.contains(modelName)){
        item->setTargetModel(modelName);
        const model::spenat::SpenatDeclModel* spenatModel = _d->_importedSpenatModels.value(modelName);
        QString portName = QString::fromStdString(compCtx->contextID()[1]->getText());
        if(spenatModel->port(portName)){
          item->setTargetPort(portName);
        }
        else{
          appendDslError(compCtx->contextID()[1]->getStart(),
              QString("Connection model has no port with name '%0'!").arg(portName));
        }
      }
      else if(_d->_importedStatemachineModels.contains(modelName)){
        item->setTargetModel(modelName);
        const model::statemachine::StateMachineModel* statemachineModel = _d->_importedStatemachineModels.value(modelName);
        QString portName = QString::fromStdString(compCtx->contextID()[1]->getText());
        if(statemachineModel->port(portName)){
          item->setTargetPort(portName);
        }
        else{
          appendDslError(compCtx->contextID()[1]->getStart(),
              QString("Connection model has no port with name '%0'!").arg(portName));
        }
      }
    }
    else{
      appendDslError(ctx->getStart(),
                     QString("Connection has no target!"));
    }
    this->_model->addSimConnnetionItem(item.take());
  }
  else{
    appendDslError(ctx->getStart(),
                   QString("Connection Declaration contains errors!"));
  }
}

void SimSystemModelListener::exitConfigBody(SimSystemDeclParser::ConfigBodyContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  if(!ctx->startSequenceDecl())
    return;

  SimConfigItem* configItem = _model->simConfigItem();
  Q_ASSERT(configItem);
  for(auto ctxID : ctx->startSequenceDecl()->contextID())
  {
    QString modelString = QString::fromStdString(ctxID->getText());
    if(!(_d->_importedSpenatModels.value(modelString)
         || _d->_importedStatemachineModels.value(modelString)))
    {
      appendDslError(ctxID->getStart(),
                     QString("Model with name '%0' does not exist!").arg(modelString));
      return;
    }

    QString errorString;
    bool result = configItem->addStartSequenceModel(modelString, &errorString);
    if(!result)
    {
      appendDslError(ctxID->getStart(), errorString);
      return;
    }
  }

  return;
}

void SimSystemModelListener::enterImportPathBody(SimSystemDeclParser::ImportPathBodyContext *ctx)
{
  Q_ASSERT(ctx);
  if(this->_d->_errorNode
     || ctx->exception)
    return;

  typedef  tree::TerminalNode* (SimSystemDeclParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<SimSystemDeclParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &SimSystemDeclParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);
}

void SimSystemModelListener::exitImportPathBody(SimSystemDeclParser::ImportPathBodyContext *ctx)
{
  if(this->_d->_errorNode
     || ctx->exception
     || !ctx->importFileBody())
    return;

  QString path = QString::fromStdString(ctx->importFileBody()->getText());
  path = _d->_prefix + path;
  QFile file(path);
  if(!file.open(QFile::ReadOnly)){
    appendDslError(ctx->getStart(),
                   QLatin1String("Import File couldn't be opened"));
    return;
  }
  QString docText(file.readAll());
  QString absolutePathStr = QFileInfo(path).canonicalFilePath();
  file.close();

  if(path.endsWith(QString(".statemachine")))
  {
    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID())
    {
      addSimpleKeywordLocation<TokenTextLocations>(ctx->importAs()->AsID(),
                                                   this->_keywordTextLocations,
                                                   Keyword);
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QLatin1String("this");
    }

    model::statemachine::StateMachineModel* statemachineModel = new model::statemachine::StateMachineModel;
    dslparser::statemachine::ComBuildStateMachineModel command(docText, statemachineModel,_d->_prefix);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      this->_d->_importedStatemachineModels.insert(name,statemachineModel);
      SimModelItem* item = new SimModelItem(name, absolutePathStr);
      item->setText(statemachineModel->name());
      _model->addSimModelItem(item);
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
  else if(path.endsWith(QString(".spenat"))){

    QString name;
    if(ctx->importAs() && ctx->importAs()->contextID()){
      name = QString::fromStdString(ctx->importAs()->contextID()->getText());
    }
    else{
      name = QLatin1String("this");
    }

    model::spenat::SpenatDeclModel* spenatModel = new model::spenat::SpenatDeclModel;
    dslparser::spenat::ComBuildSpenatModel command(docText, spenatModel);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      SimModelItem* item = new SimModelItem(name, absolutePathStr);
      item->setText(spenatModel->name());
      _model->addSimModelItem(item);
      this->_d->_importedSpenatModels.insert(name,spenatModel);
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QLatin1String("Import File contains errors!"));
      if(this->_errors)
        this->_errors->append(command.errors());
      return;
    }
  }
}

void SimSystemModelListener::visitErrorNode(tree::ErrorNode* node)
{
  this->_d->_errorNode=node;

  return;
}

bool SimSystemModelListener::validModelPort(const QString &modelName,
                                            const QString &portName,
                                            QString *errorString) const
{
  ImportStatemachineModelList::const_iterator find_sm_it=this->_d->_importedStatemachineModels.find(modelName);
  if(find_sm_it==this->_d->_importedStatemachineModels.end())
  {
    ImportSpenatModelList::const_iterator find_spenat_it=this->_d->_importedSpenatModels.find(modelName);
    if(find_spenat_it==this->_d->_importedSpenatModels.end())
    {
      Q_ASSERT(this->_model->simConfigItem());

      SimActorItem const* simActor=this->_model->simConfigItem()->simActor(modelName);
      if(!simActor)
      {
        utils::AddPtrString(errorString)<<"model or actor with name '"<<modelName<<"' is not available!";
        return  false;
      }

      if(!simActor->portNames().contains(portName))
      {
        utils::AddPtrString(errorString)<<"port with name '"<<portName
                                       <<"' is not available for model or actor '"
                                      <<modelName<<"'!";
        return  false;
      }

      return true;
    }

    if(!find_spenat_it.value()->port(portName))
    {
      utils::AddPtrString(errorString)<<"port with name '"<<portName
                                     <<"' is not available for model '"
                                    <<modelName<<"'!";
      return  false;
    }

    return true;
  }

  if(!find_sm_it.value()->port(portName))
  {
    utils::AddPtrString(errorString)<<"port with name '"<<portName
                                   <<"' is not available for model '"
                                  <<modelName<<"'!";
    return  false;
  }

  return  true;
}

SignalItem const* SimSystemModelListener::findMessageSignal(const QString &modelName,
                                                            const QString &signalName,
                                                            QString *errorString) const
{
  SignalItem const* messageSignal=nullptr;

  ImportStatemachineModelList::const_iterator find_sm_it=this->_d->_importedStatemachineModels.find(modelName);
  if(find_sm_it==this->_d->_importedStatemachineModels.end())
  {//must be a spenat signal
    ImportSpenatModelList::const_iterator find_spenat_it=this->_d->_importedSpenatModels.find(modelName);
    if(find_spenat_it==this->_d->_importedSpenatModels.end())
    {
      utils::AddPtrString(errorString)<<"model with name '"<<modelName<<"' is not available!";
      return  nullptr;
    }

    messageSignal = find_spenat_it.value()->signal(signalName);
    if(!messageSignal)
      utils::AddPtrString(errorString)<<"message signal with name '"<<signalName
                                     <<"' is not available for model '"
                                    <<modelName<<"'!";
    return messageSignal;
  }

  //must be a state machine signal
  messageSignal = find_sm_it.value()->signal(signalName);
  if(!messageSignal)
    utils::AddPtrString(errorString)<<"port with name '"<<signalName
                                   <<"' is not available for model '"
                                  <<modelName<<"'!";
  return messageSignal;
}

} // namespace modsim
