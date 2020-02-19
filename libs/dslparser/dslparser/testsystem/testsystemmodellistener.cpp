#include "testsystemmodellistener.hpp"
#include "TestSystemDeclLexer.h"

#include <mobata/model/base/portitem.hpp>
#include <mobata/model/ts/ts.hpp>
#include <dslparser/sut/combuildsutmodel.hpp>

#include <QStack>
#include <QDebug>
#include <QFile>
#include <QFileInfo>

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace testsystem {

using common::addKeywordLocation;

class TestSystemModelListener::Private
{
  friend class TestSystemModelListener;

  ///parse data////
  QString*                          _importedSutFile;
  QString                           _praefix;
  QScopedPointer<TestComponentItem> _currentComponentItem;
  ImportedModelItems                _importedModelItems;

  //link parse data///
  PortItem const*                   _linkSourcePort;
  PortItem const*                   _linkTargetPort;
  QString                           _linkLabel;

  Private(QString* importedSutFile,
          const QString& praefix)
    : _importedSutFile(importedSutFile),
      _praefix(praefix),
      _currentComponentItem(nullptr),
      _importedModelItems(),
      _linkSourcePort(nullptr),
      _linkTargetPort(nullptr)
  {}
};

template<class ParserClass>
PortItem const* portItemFromIdPath(typename ParserClass::IdPathContext* idPathCtx,
                                   PropComponents const* basePropComponents,
                                   const ImportedModelItems& importedModelItems,
                                   DslErrorList* dslErrors)
{
  Q_ASSERT(idPathCtx);
  Q_ASSERT(basePropComponents);

  model::base::PropComponents const* propComponents=nullptr;
  model::base::ComponentItem const* componentItem = nullptr;

  for(TestSystemDeclParser::ContextIDContext* currPathItemCtx
      : idPathCtx->contextID())
  {
    QString currPathItemName = QString::fromStdString(currPathItemCtx->getText());

    //first looking for propComponents
    if(!propComponents)
    {
      model::base::ModelItem* importedModelItem=importedModelItems.value(currPathItemName,
                                                                         nullptr);
      if(model::base::PropComponents const* importedPropComponents = dynamic_cast<model::base::PropComponents const*>(importedModelItem))
      {
        propComponents=importedPropComponents;
        continue;
      }
      else
      {
        propComponents=basePropComponents;
      }
    }

    Q_ASSERT(propComponents);

    //second looking for component
    if(!componentItem)
    {
      componentItem = propComponents->component(currPathItemName);
      if(!componentItem)
      {
        Token* startToken = currPathItemCtx->getStart();
        Q_ASSERT(startToken);
        if(dslErrors)
          dslErrors->append(DslError(QString(QLatin1String("Component '%1' is not available!")).arg(currPathItemName),
                                     static_cast<int>(startToken->getLine()),
                                     static_cast<int>(startToken->getCharPositionInLine())));
        return nullptr;
      }

      continue;
    }
    Q_ASSERT(componentItem);

    //third: finally looking for port
    PortItem const* portItem = componentItem->port(currPathItemName);
    if(!portItem)
    {
      Token* startToken = currPathItemCtx->getStart();
      Q_ASSERT(startToken);
      if(dslErrors)
        dslErrors->append(DslError(QString(QLatin1String("Port '%1' is not available!")).arg(currPathItemName),
                                   static_cast<int>(startToken->getLine()),
                                   static_cast<int>(startToken->getCharPositionInLine())));
      return nullptr;
    }

    return portItem;
  }

  return nullptr;
}

TestSystemModelListener::TestSystemModelListener(TestSystemItem* testsystemDeclModel,
                                                 DslErrorList* testsystemErrors,
                                                 QString* importedSutFile,
                                                 const QString& praefix,
                                                 TokenTextLocations* keywordTextLocations,
                                                 ModelTextLocations* modelTextLocations)
  : BaseClass(testsystemDeclModel, testsystemErrors, keywordTextLocations, modelTextLocations),
    _d(new Private(importedSutFile, praefix))
{
  Q_ASSERT(this->_model);
}

TestSystemModelListener::~TestSystemModelListener()
{
  delete this->_d;
}

const ImportedModelItems& TestSystemModelListener::importedModelItems() const
{
  return this->_d->_importedModelItems;
}

void TestSystemModelListener::enterTestSystemDecl(TestSystemDeclParser::TestSystemDeclContext* ctx)
{
  Q_UNUSED(ctx);

  this->_listenerStates.push(TestSystemDeclState);

  return;
}

void TestSystemModelListener::exitTestSystemDecl(TestSystemDeclParser::TestSystemDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_listenerStates.pop();

  typedef  tree::TerminalNode* (TestSystemDeclParser::TestSystemDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestSystemDeclParser::TestSystemDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::TestSystemDeclContext::TestSystemID, this->_keywordTextLocations, TestSystem);
}

void TestSystemModelListener::enterNameDecl(TestSystemDeclParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestSystemDeclParser::NameDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestSystemDeclParser::NameDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void TestSystemModelListener::exitNameDecl(TestSystemDeclParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString name=QString::fromStdString(ctx->contextID()->getText());

  int currListenerState = this->currentListenerState();
  if(currListenerState==TestSystemDeclState)
  {
    Q_ASSERT(this->_model);
    this->_model->setName(name);
    this->_model->setText(name);
  }
  else if(currListenerState==TestCompDeclState)
  {
    Q_ASSERT(this->_d->_currentComponentItem);
    this->_d->_currentComponentItem->setName(name);
    this->_d->_currentComponentItem->setText(name);

    QString errorString;
    bool result = this->_model->addComponent(this->_d->_currentComponentItem.data(),
                                             &errorString);
    if(!result)
    {
      appendDslError(ctx->getStart(),
                     errorString);
    }
  }

  return;
}

void TestSystemModelListener::exitEnabledDecl(TestSystemDeclParser::EnabledDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!
  if(!this->_d->_currentComponentItem)
    return;//TODO: how is this possible?

  bool en = (!ctx->FalseID());
  this->_d->_currentComponentItem->setEnabled(en);

  typedef  tree::TerminalNode* (TestSystemDeclParser::EnabledDeclContext::*KeywordFunction)();

  addKeywordLocation<TestSystemDeclParser::EnabledDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::EnabledDeclContext::EnabledID, this->_keywordTextLocations, Enabled);

}

void TestSystemModelListener::enterPortDecl(TestSystemDeclParser::PortDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestSystemDeclParser::PortDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestSystemDeclParser::PortDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::PortDeclContext::PortID, this->_keywordTextLocations, Keyword);
}

void TestSystemModelListener::exitPortDecl(TestSystemDeclParser::PortDeclContext *ctx)
{
  Q_ASSERT(ctx);
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!this->_d->_currentComponentItem)
    return;//FIXME: this is not good

  Q_ASSERT(this->_d->_currentComponentItem);

  for(TestSystemDeclParser::ContextIDContext* currContextID : ctx->contextID())
  {
    Token* portToken=currContextID->getStart();
    Q_ASSERT(portToken);

    QString portName=QString::fromStdString(currContextID->getText());
    QString errorString;
    PortItem* newPort = this->_d->_currentComponentItem->addPort(portName, &errorString);
    if(!newPort)
    {
      if(this->_errors)
        this->_errors->append(DslError(errorString,
                                       static_cast<int>(portToken->getLine()),
                                       static_cast<int>(portToken->getCharPositionInLine())));
    }
    else
    {
      this->_modelTextLocations->insert(newPort->index(),
                                        TokenTextLocation(static_cast<int>(portToken->getStartIndex()),
                                                          static_cast<int>(portToken->getStopIndex()),
                                                          Port));
    }
  }

  return;
}

void TestSystemModelListener::exitImportPathBody(TestSystemDeclParser::ImportPathBodyContext *ctx)
{
  if(ctx->exception || !ctx->importFileBody())
    return;
  typedef  tree::TerminalNode* (TestSystemDeclParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<TestSystemDeclParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);

  QString path = QString::fromStdString(ctx->importFileBody()->getText());
  path = _d->_praefix + path;
  qDebug()<<"TS-Listener"<<path;
  QFile file(path);
  if(!file.open(QFile::ReadOnly))
    qDebug()<<"imported file '"<<path<<"' could not be opened!";
  QString docText(file.readAll());
  file.close();

  if(path.endsWith(QString("sut")))
  {
    if(this->_d->_importedSutFile)
      *this->_d->_importedSutFile=QFileInfo(path).canonicalFilePath();

    model::ts::SutItem* sutModel = const_cast<model::ts::SutItem*>(this->_model->sutItem());
    Q_ASSERT(sutModel);
    dslparser::sut::ComBuildSutModel command(docText, sutModel);
    QString errorString;
    bool result = command.execute(&errorString);
    if(result){
      QString name;
      if(ctx->importAs() && ctx->importAs()->contextID()){
        name = QString::fromStdString(ctx->importAs()->contextID()->getText());
      }
      else{
        name = path;
      }
      this->_d->_importedModelItems.insert(name,sutModel);
    }
    else
    {
      appendDslError(ctx->getStart(),
                     QStringLiteral("Imported sut file contains errors..."));
    }
  }
  else
    appendDslError(ctx->getStart(),
                   QStringLiteral("only sut files are currently supported for importing!"));

  return;
}

void TestSystemModelListener::enterTestCompDecl(TestSystemDeclParser::TestCompDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_listenerStates.push(TestCompDeclState);

  this->_d->_currentComponentItem.reset(new TestComponentItem(QStringLiteral("")));
  this->setAttributesModel(this->_d->_currentComponentItem.data());

  typedef  tree::TerminalNode* (TestSystemDeclParser::TestCompDeclContext::*KeywordFunction)();

  addKeywordLocation<TestSystemDeclParser::TestCompDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::TestCompDeclContext::TestComponentID, this->_keywordTextLocations, TestComponent);

  return;
}

void TestSystemModelListener::exitTestCompDecl(TestSystemDeclParser::TestCompDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  if(!this->_d->_currentComponentItem)
    return;//FIXME: this is not good
  Q_ASSERT(this->_d->_currentComponentItem);

  this->_modelTextLocations->insert(this->_d->_currentComponentItem->index(),
                                    TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                      static_cast<int>(ctx->getStop()->getStopIndex()),
                                                      TestComponent));

  this->_d->_currentComponentItem.take();
  this->_listenerStates.pop();
  this->setAttributesModel(this->_model);

  return;
}

void TestSystemModelListener::enterSourceDecl(TestSystemDeclParser::SourceDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestSystemDeclParser::SourceDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestSystemDeclParser::SourceDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::SourceDeclContext::SourceID, this->_keywordTextLocations, Attribute);
}

void TestSystemModelListener::exitSourceDecl(TestSystemDeclParser::SourceDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_d->_linkSourcePort = portItemFromIdPath<TestSystemDeclParser>(ctx->idPath(),
                                                                       this->_model,
                                                                       this->_d->_importedModelItems,
                                                                       this->_errors);

  return;
}

void TestSystemModelListener::enterTargetDecl(TestSystemDeclParser::TargetDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestSystemDeclParser::TargetDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestSystemDeclParser::TargetDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::TargetDeclContext::TargetID, this->_keywordTextLocations, Attribute);
}

void TestSystemModelListener::exitTargetDecl(TestSystemDeclParser::TargetDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_d->_linkTargetPort = portItemFromIdPath<TestSystemDeclParser>(ctx->idPath(),
                                                                       this->_model,
                                                                       this->_d->_importedModelItems,
                                                                       this->_errors);

  return;
}

void TestSystemModelListener::enterLabelDecl(TestSystemDeclParser::LabelDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestSystemDeclParser::LabelDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestSystemDeclParser::LabelDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::LabelDeclContext::LabelID, this->_keywordTextLocations, Attribute);
}

void TestSystemModelListener::exitLabelDecl(TestSystemDeclParser::LabelDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->STRING());
  this->_d->_linkLabel=QString::fromStdString(ctx->STRING()->getText());
  this->_d->_linkLabel.remove("\"");

  return;
}

void TestSystemModelListener::enterLinkDecl(TestSystemDeclParser::LinkDeclContext *ctx)
{
  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestSystemDeclParser::LinkDeclContext::*KeywordFunction)();

  addKeywordLocation<TestSystemDeclParser::LinkDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestSystemDeclParser::LinkDeclContext::LinkID, this->_keywordTextLocations, Link);

  return;
}

void TestSystemModelListener::exitLinkDecl(TestSystemDeclParser::LinkDeclContext *ctx)
{
  if(!ctx || !ctx->linkBody() || ctx->exception)
    return;

  if(this->_d->_linkSourcePort
     && this->_d->_linkTargetPort)
  {
    QString errorString;
    LinkItem* newLinkItem = _model->addLink(this->_d->_linkSourcePort,
                                            this->_d->_linkTargetPort,
                                            &errorString);
    if(!newLinkItem)
    {
      appendDslError(ctx->getStart(),
                     errorString);
    }
    else
    {
      newLinkItem->setNotation(this->_d->_linkLabel);
      this->_modelTextLocations->insert(newLinkItem->index(),
                                        TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                          static_cast<int>(ctx->getStop()->getStopIndex()),
                                                          Link));
    }
  }
  else
    appendDslError(ctx->getStart(),
                   QStringLiteral("Target, Source of this link is not defined!"));

  //reset link data
  this->_d->_linkSourcePort=nullptr;
  this->_d->_linkTargetPort=nullptr;
  this->_d->_linkLabel.clear();

  return;
}

//model::base::ModelItem* TestSystemModelListener::getItemFromPath(TestSystemDeclParser::IdPathContext* path)
//{
//  Q_ASSERT(path);
//  if(path->exception)
//    return false;

//  QList<QString> pathStringItems;
//  model::base::ModelItem* currentPathItem=nullptr;

//  return false;//FIXME: next lines are temporarely comment out

//  while(path){
//    QString name = QString::fromStdString(path->ID()->getText());
//    if(!this->_d->_currentPathItem){
//      if(this->_d->_importItem.contains(name)){
//        this->_d->_currentPathItem = this->_d->_importItem.value(name);
//        path = path->contextIdPath();
//        continue;
//      }
//      else{
//        this->_d->_currentPathItem = this->_model;
//      }
//    }
//    if(dynamic_cast<TestSystemItem*>(this->_d->_currentPathItem)){
//      auto components = dynamic_cast<TestSystemItem*>(this->_d->_currentPathItem)->components();
//      int sz = components.size();
//      bool test = false;
//      for(int i = 0;i<sz;i++){
//        if(components.at(i)->name() == name){
//          this->_d->_currentPathItem = components.at(i);
//          i = sz;
//          test = true;
//        }
//      }
//      //If Component wasn't found!!
//      if(!test){
//        Token* startToken = path->getStart();
//        Token* stopToken = path->getStop();
//        Q_ASSERT(startToken);
//        Q_ASSERT(stopToken);
//        if(this->_errors)
//          this->_errors->append(DslError(QString("Incorrect Path to Port!"),
//                                         startToken->getLine(),
//                                         startToken->getCharPositionInLine()));
//        return false;
//      }
//    }
//    else if(dynamic_cast<TestComponentItem*>(this->_d->_currentPathItem)){
//      auto ports = dynamic_cast<TestComponentItem*>(this->_d->_currentPathItem)->ports();
//      int sz = ports.size();
//      bool test = false;
//      for(int i = 0;i<sz;i++){
//        if(ports.at(i)->name() == name){
//          this->_d->_currentPathItem = ports.at(i);
//          i = sz;
//          test = true;
//        }
//      }
//      //If Port wasn't found!!
//      if(!test){
//        Token* startToken = path->getStart();
//        Token* stopToken = path->getStop();
//        Q_ASSERT(startToken);
//        Q_ASSERT(stopToken);
//        if(this->_errors)
//          this->_errors->append(DslError(QString("Incorrect Path to Port!"),
//                                         startToken->getLine(),
//                                         startToken->getCharPositionInLine()));
//        return false;
//      }
//    }
//    else if(dynamic_cast<SutItem*>(this->_d->_currentPathItem)){
//      auto components = dynamic_cast<SutItem*>(this->_d->_currentPathItem)->components();
//      int sz = components.size();
//      bool test = false;
//      for(int i = 0;i<sz;i++){
//        if(components.at(i)->name() == name){
//          this->_d->_currentPathItem = components.at(i);
//          i = sz;
//          test = true;
//        }
//      }
//      //If Component wasn't found!!
//      if(!test){
//        Token* startToken = path->getStart();
//        Token* stopToken = path->getStop();
//        Q_ASSERT(startToken);
//        Q_ASSERT(stopToken);
//        if(this->_errors)
//          this->_errors->append(DslError(QString("Incorrect Path to Port!"),
//                                         startToken->getLine(),
//                                         startToken->getCharPositionInLine()));
//        return false;
//      }
//    }
//    else if(dynamic_cast<SutComponentItem*>(this->_d->_currentPathItem)){
//      auto ports = dynamic_cast<SutComponentItem*>(this->_d->_currentPathItem)->ports();
//      int sz = ports.size();
//      bool test = false;
//      for(int i = 0;i<sz;i++){
//        if(ports.at(i)->name() == name){
//          this->_d->_currentPathItem = ports.at(i);
//          i = sz;
//          test = true;
//        }
//      }
//      //If Port wasn't found!!
//      if(!test){
//        Token* startToken = path->getStart();
//        Token* stopToken = path->getStop();
//        Q_ASSERT(startToken);
//        Q_ASSERT(stopToken);
//        if(this->_errors)
//          this->_errors->append(DslError(QString("Incorrect Path to Port!"),
//                                         startToken->getLine(),
//                                         startToken->getCharPositionInLine()));
//        return false;
//      }
//    }
//    path = path->contextIdPath();
//  }
//  return true;
//}

void TestSystemModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);
  return;
}

} // namespace testsystem
} // namespace dslparser
