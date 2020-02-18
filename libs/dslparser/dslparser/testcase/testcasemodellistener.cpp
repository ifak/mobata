#include "testcasemodellistener.hpp"
#include "TestCaseDeclLexer.h"

#include <mobata/model/ts/ts.hpp>
#include <mobata/model/msc/msccheckmessageitem.hpp>
#include <dslparser/sut/combuildsutmodel.hpp>
#include <dslparser/testsystem/combuildtestsystemmodel.hpp>
#include <mobata/model/msc/msc_types.hpp>
#include <mobata/model/msc/msctimeoutitem.hpp>
#include <dslparser/common/combuildbasemodel.hpp>


#include <QStack>
#include <QDebug>
#include <QFile>
#include <QFileInfo>

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace testcase {

using common::addKeywordLocation;

class TestCaseModelListener::Private
{
  friend class TestCaseModelListener;

  model::ts::TestSystemItem* _testSystemItem;

  ///parse data////
  int                                         _errorAtPos;
  ModelItem*                                  _currentPathItem;
  ModelItem*                                  _currentItem;
  QStack<model::msc::MscFragmentRegionItem*>  _currentReg;
  QStack<model::msc::MscFragmentItem*>        _currentAlt;
  ImportModelItem                             _importItems;
  ImportModelModel                             _importModels;
  QString                                     _praefix;
  bool                                        _isInData = false;
  bool                                        _isInDecl = false;
  QHash<model::base::ModelItem*,QVector<int>> _modelPositionOfCheck;
  QHash<QString,model::base::ModelItem*>      _testCaseItems;
  SutItemPtr                                  _sutItem = nullptr;
  model::base::ModelItem*                     _currentSignal;

  Private(model::ts::TestSystemItem* testSystemItem,
          const QString& praefix)
    : _testSystemItem(testSystemItem),
      _currentPathItem(nullptr),
      _importItems(),
      _praefix(praefix),
      _sutItem(new SutItem())
  {}
};



TestCaseModelListener::TestCaseModelListener(TestCaseItem* testCaseDeclModel,
                                             DslErrorList* testcaseErrors,
                                             model::ts::TestSystemItem* testSystemItem,
                                             const QString& praefix,
                                             TokenTextLocations* keywordTextLocations,
                                             ModelTextLocations* modelTextLocations)
  : BaseClass(testCaseDeclModel, testcaseErrors, keywordTextLocations, modelTextLocations),
    _d(new Private(testSystemItem, praefix))
{}

TestCaseModelListener::~TestCaseModelListener()
{
  delete this->_d;
}

QPair<ModelItem *, int> TestCaseModelListener::currentPathItem()
{
  return QPair<ModelItem*,int>(this->_d->_currentPathItem,_d->_errorAtPos);
}

ModelItem* TestCaseModelListener::currentSignalItem()
{
  return this->_d->_currentSignal;
}

const QHash<QString, ModelItem*>& TestCaseModelListener::testCaseItems()
{
  return this->_d->_testCaseItems;
}

const ImportModelItem& TestCaseModelListener::importItems()
{
  return this->_d->_importItems;
}

void TestCaseModelListener::enterTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext* ctx)
{
  Q_UNUSED(ctx);

  this->_listenerStates.push(TestCaseDeclState);

  typedef  tree::TerminalNode* (TestCaseDeclParser::TestCaseDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestCaseDeclParser::TestCaseDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::TestCaseDeclContext::TestCaseID, this->_keywordTextLocations, TestCase);
}

void TestCaseModelListener::exitTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  this->_listenerStates.pop();

  this->_modelTextLocations->insert(this->_model->index(),
                                    TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                      static_cast<int>(ctx->getStop()->getStopIndex()),
                                                      TestCase));


  return;
}

void TestCaseModelListener::enterTestCaseBody(TestCaseDeclParser::TestCaseBodyContext *ctx)
{
  typedef  tree::TerminalNode* (TestCaseDeclParser::TestCaseBodyContext::*KeywordFunction)();

  addKeywordLocation<TestCaseDeclParser::TestCaseBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::TestCaseBodyContext::DeclarationID, this->_keywordTextLocations, Declaration);

  return;
}

void TestCaseModelListener::enterDeclarations(TestCaseDeclParser::DeclarationsContext *ctx)
{
  if(ctx->exception)
    return;
  _d->_isInDecl = true;
}

void TestCaseModelListener::exitDeclarations(TestCaseDeclParser::DeclarationsContext *ctx)
{
  if(ctx->exception)
    return;
  _d->_isInDecl = false;
}

void TestCaseModelListener::enterNameDecl(TestCaseDeclParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestCaseDeclParser::NameDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestCaseDeclParser::NameDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::NameDeclContext::NameID, this->_keywordTextLocations, Attribute);
}

void TestCaseModelListener::exitNameDecl(TestCaseDeclParser::NameDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->contextID());

  QString name=QString::fromStdString(ctx->contextID()->getText());

  Q_ASSERT(this->_model);
  this->_model->setName(name);
  this->_model->setText(name);

  return;
}

void TestCaseModelListener::enterUuidDecl(TestCaseDeclParser::UuidDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  typedef  tree::TerminalNode* (TestCaseDeclParser::UuidDeclContext::*KeywordFunction)();

  return addKeywordLocation<TestCaseDeclParser::UuidDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::UuidDeclContext::UuidID, this->_keywordTextLocations, Attribute);
}

void TestCaseModelListener::exitUuidDecl(TestCaseDeclParser::UuidDeclContext* ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  Q_ASSERT(ctx->val);

  QString name=QString::fromStdString(ctx->val->getText());
  name = name.mid(1,name.length()-2);

  Q_ASSERT(this->_model);
  this->_model->setUuid(name);

  return;
}

void TestCaseModelListener::enterEnabledDecl(TestCaseDeclParser::EnabledDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!
  typedef  tree::TerminalNode* (TestCaseDeclParser::EnabledDeclContext::*KeywordFunction)();

  addKeywordLocation<TestCaseDeclParser::EnabledDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::EnabledDeclContext::EnabledID, this->_keywordTextLocations, Enabled);

  return;
}

void TestCaseModelListener::exitEnabledDecl(TestCaseDeclParser::EnabledDeclContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;//an error occured! -> but still handled by error listener!

  bool en = (!ctx->FalseID());
  this->_model->setEnabled(en);

  return;
}

void TestCaseModelListener::enterImportPathBody(TestCaseDeclParser::ImportPathBodyContext *ctx)
{
  Q_ASSERT(ctx);

  if(ctx->exception)
    return;

  typedef  tree::TerminalNode* (TestCaseDeclParser::ImportPathBodyContext::*KeywordFunction)();

  addKeywordLocation<TestCaseDeclParser::ImportPathBodyContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::ImportPathBodyContext::ImportID, this->_keywordTextLocations, Import);

  return;
}

void TestCaseModelListener::exitImportPathBody(TestCaseDeclParser::ImportPathBodyContext *ctx)
{
  if(ctx->exception || !ctx->importFileBody())
    return;

  if(this->_d->_testSystemItem == nullptr){
    QString path = QString::fromStdString(ctx->importFileBody()->getText());
    path = _d->_praefix + path;
    QFile file(path);
    if(!file.open(QFile::ReadOnly))
      qDebug()<<"file '"<<path<<"' could not be opened!";
    QString docText(file.readAll());
    file.close();

    if(path.endsWith(QLatin1String("testsystem")))
    {
      this->_d->_testSystemItem = new model::ts::TestSystemItem();
      this->_d->_testSystemItem->setSutItem(new model::ts::SutItem());
      this->_model->appendRow(this->_d->_testSystemItem);
      dslparser::testsystem::ComBuildTestSystemModel command(docText,
                                                             this->_d->_testSystemItem,
                                                             this->_d->_praefix);
      QString errorString;
      bool result = command.execute(&errorString);
      Q_UNUSED(result);
      QString name;
      if(ctx->importAs() && ctx->importAs()->contextID())
      {
        name = QString::fromStdString(ctx->importAs()->contextID()->getText());
      }
      else
      {
        name = path;
      }
      this->_d->_importItems.insert(name,this->_d->_testSystemItem);

      auto importedModelItems = command.importItems();
      for(const QString& key : importedModelItems.keys()){
        this->_d->_importItems.insert(key,importedModelItems.value(key));
      }
    }
  }else{
    this->_d->_importItems.insert("testsystem",this->_d->_testSystemItem);
    this->_d->_importItems.insert("sut",const_cast<model::ts::SutItem*>(this->_d->_testSystemItem->sutItem()));
  }
}
void TestCaseModelListener::exitAliasDef(TestCaseDeclParser::AliasDefContext *ctx)
{
  if(ctx->exception)
    return;
  if(getItemFromPath(ctx->idPath())){
    _d->_testCaseItems.insert(QString::fromStdString(ctx->contextID()->getText()),_d->_currentPathItem);
  }

  typedef  tree::TerminalNode* (TestCaseDeclParser::AliasDefContext::*KeywordFunction)();

  return addKeywordLocation<TestCaseDeclParser::AliasDefContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::AliasDefContext::ComponentID, this->_keywordTextLocations, Component);

}

void TestCaseModelListener::exitAltDecl(TestCaseDeclParser::AltDeclContext *ctx)
{
  if(!ctx)
    return;
  this->_modelTextLocations->insert(this->_d->_currentAlt.at(0)->index(),
                                    TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                      static_cast<int>(ctx->getStop()->getStopIndex()),
                                                      Alt));
  _d->_currentAlt.pop_front();


  typedef  tree::TerminalNode* (TestCaseDeclParser::AltDeclContext::*KeywordFunction)();

  addKeywordLocation<TestCaseDeclParser::AltDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::AltDeclContext::AltID, this->_keywordTextLocations, Alt);

}

void TestCaseModelListener::enterAltBody(TestCaseDeclParser::AltBodyContext *ctx)
{
  if(!ctx)
    return;
  _d->_currentReg.push_front(new model::msc::MscFragmentRegionItem(""));
  _d->_currentAlt.at(0)->addRegion(_d->_currentReg.at(0));
}

void TestCaseModelListener::exitAltBody(TestCaseDeclParser::AltBodyContext *ctx)
{
  if(ctx->exception)
    return;
  _d->_currentReg.at(0)->setCondition(getExpression(ctx->expression()));
  this->_modelTextLocations->insert(_d->_currentReg.at(0)->index(),
                                    TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                      static_cast<int>(ctx->getStop()->getStopIndex()),
                                                      Region));

  _d->_currentReg.pop_front();
}

void TestCaseModelListener::enterAltDecl(TestCaseDeclParser::AltDeclContext *ctx)
{
  if(!ctx)
    return;
  _d->_currentAlt.push_front(new model::msc::MscFragmentItem(model::msc::FragmentType::AlternativeFragment));
  this->_model->addFragment(_d->_currentAlt.at(0));
}

void TestCaseModelListener::exitTimerDecl(TestCaseDeclParser::TimerDeclContext *ctx)
{
  if(ctx->exception)
    return;
  model::msc::MscComponentItem* item = nullptr;
  TimerItem* timer = nullptr;
  if(getItemFromPath(ctx->idPath())){
    if(dynamic_cast<BaseComponentItem*>(this->_d->_currentPathItem)){
      item = dynamic_cast<BaseComponentItem*>(this->_d->_currentPathItem);
      if(item){
        QString value = "";
        if(ctx->REAL()) value = QString::fromStdString(ctx->REAL()->getText());
        else if(ctx->INT()) value = QString::fromStdString(ctx->INT()->getText());
        else{
          appendDslError(ctx->getStart(),
                         QStringLiteral("Timer assignment has to be of type \'Int\' oder \'Double\'!"));
          return;
        }
        QString name = QString::fromStdString(ctx->contextID()->getText());
        QString errorString;
        timer = _model->addTimer(item,name,&errorString);
        if(!timer){
          appendDslError(ctx->getStart(),
                         errorString);
          return;
        }
        timer->setValue(value.toDouble());
        _d->_testCaseItems.insert(name, dynamic_cast<ModelItem*>(timer));

      }
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("Incorrect Attribute type!"));
        return;
      }
    }
    else{
      appendDslError(ctx->getStart(),
                     QStringLiteral("ModelItem is not MscComponentItem!"));
      return;
    }
  }
  else  return;
  typedef  tree::TerminalNode* (TestCaseDeclParser::TimerDeclContext::*KeywordFunction)();

  this->_modelTextLocations->insert(timer->index(),
                                    TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                      static_cast<int>(ctx->getStop()->getStopIndex()),
                                                      Timer));

  return addKeywordLocation<TestCaseDeclParser::TimerDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::TimerDeclContext::TimerID, this->_keywordTextLocations, Timer);

}

void TestCaseModelListener::exitMessageDecl(TestCaseDeclParser::MessageDeclContext *ctx)
{
  if(!ctx || !ctx->idPath().size()) return;
  if(getItemFromPath(ctx->idPath().at(0))){
    const PortItem* source;
    if((source = dynamic_cast<PortItem*>(_d->_currentPathItem)));
    else if( auto sourceComp = dynamic_cast<model::msc::MscComponentItem*>(_d->_currentPathItem)){
      source = sourceComp->defaultPort();
    }
    else {
      appendDslError(ctx->getStart(),
                     QStringLiteral("Unknown error in Message declaration!"));
      return;
    }
    if((ctx->idPath().size() >1) && getItemFromPath(ctx->idPath().at(1))){
      const PortItem* target;
      if((target = dynamic_cast<PortItem*>(_d->_currentPathItem)));
      else if( auto targetComp = dynamic_cast<model::msc::MscComponentItem*>(_d->_currentPathItem)){
        target = targetComp->defaultPort();
      }
      else {
        appendDslError(ctx->getStart(),
                       QStringLiteral("Unknown error in Message declaration!"));
        return;
      }
      if(!ctx->functionCall() || ctx->functionCall()->exception){
        appendDslError(ctx->getStart(),
                       QStringLiteral("No Signal for message given!"));
        return;
      }
      auto test = testCaseItems().value(QString::fromStdString(ctx->functionCall()->idPath()->contextID().back()->getText()));
      model::base::SignalItem* signal = test ?
            static_cast<model::base::SignalItem*>(test)
          : _model->signal(QString::fromStdString(ctx->functionCall()->idPath()->contextID().back()->getText()));
      if(signal){
        MessageItem* msg;
        if(_d->_currentReg.size())
          msg = _d->_currentReg.at(0)->addMessage(source,target,QString::fromStdString(ctx->functionCall()->idPath()->contextID().back()->getText()));
        else
          msg = _model->addMessage(source,target,QString::fromStdString(ctx->functionCall()->idPath()->contextID().back()->getText()));
        msg->setSignal(signal);
        QListIterator<model::base::ParamItem*> paramIt(signal->params());
        auto bdy = ctx->functionCall()->functionCallBody();
        while(bdy){
          auto param = paramIt.next();
          QVariant val;
          bool test = false;
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
            else{
              test = true;
            }
          }
          else if (bdy->signalParamName()) {
            //TODO: no idea
          }
          else if (bdy->attributeName()) {
            //TODO: no idea
          }
          if(!test && param) msg->addParamValue(param,val);
          if(bdy->functionCallBodyOptional()) bdy = bdy->functionCallBodyOptional()->functionCallBody();
          else break;
        }

        this->_modelTextLocations->insert(msg->index(),
                                          TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                            static_cast<int>(ctx->getStop()->getStopIndex()),
                                                            Message));


        typedef  tree::TerminalNode* (TestCaseDeclParser::MessageDeclContext::*KeywordFunction)();

        return addKeywordLocation<TestCaseDeclParser::MessageDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &TestCaseDeclParser::MessageDeclContext::MessageID, this->_keywordTextLocations, Message);
      }
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("No Signal with name \"")
                       + QString::fromStdString(ctx->functionCall()->idPath()->getText())
                       + QStringLiteral("\" found!"));
        return;
      }
    }
    else if(ctx->idPath().size() >1){
      appendDslError(ctx->getStart(),
                     QStringLiteral("No Component with name \"")
                     + QString::fromStdString(ctx->idPath().at(1)->getText())
                     + QStringLiteral("\" found!"));
      return;
    }
    else{
      if(this->_errors)
        this->_errors->append(DslError(QString("Wrong Syntax!")));
      return;
    }
  }
  else{

    Token* startToken = ctx->getStart();
    Token* stopToken = ctx->getStop();
    Q_ASSERT(startToken);
    Q_ASSERT(stopToken);
    appendDslError(ctx->getStart(),
                   QStringLiteral("No Component with name \"")
                   + QString::fromStdString(ctx->idPath().at(0)->getText())
                   + QStringLiteral("\" found!"));
    return;
  }
}

void TestCaseModelListener::exitCheckDecl(TestCaseDeclParser::CheckDeclContext *ctx)
{
  if(!ctx || !ctx->idPath().size()) return;
  if(getItemFromPath(ctx->idPath().at(0))){
    const PortItem* source;
    if((source = dynamic_cast<PortItem*>(_d->_currentPathItem)));
    else if( auto sourceComp = dynamic_cast<model::msc::MscComponentItem*>(_d->_currentPathItem)){
      source = sourceComp->defaultPort();
    }
    else {
      appendDslError(ctx->getStart(),
                     QStringLiteral("Unknown error in Message declaration!"));
      return;
    }
    if((ctx->idPath().size() >1) && getItemFromPath(ctx->idPath().at(1))){
      const PortItem* target;
      if((target = dynamic_cast<PortItem*>(_d->_currentPathItem)));
      else if( auto targetComp = dynamic_cast<model::msc::MscComponentItem*>(_d->_currentPathItem)){
        target = targetComp->defaultPort();
      }
      else {
        appendDslError(ctx->getStart(),
                       QStringLiteral("Unknown error in Message declaration!"));
        return;
      }
      if(!ctx->functionCall2() || ctx->functionCall2()->exception){
        appendDslError(ctx->getStart(),
                       QStringLiteral("No Signal for message given!"));
        return;
      }
      auto test = testCaseItems().value(QString::fromStdString(ctx->functionCall2()->idPath()->contextID().back()->getText()));
      model::base::SignalItem* signal = test ?
            static_cast<model::base::SignalItem*>(test)
          : _model->signal(QString::fromStdString(ctx->functionCall2()->idPath()->contextID().back()->getText()));
      if(signal){
        CheckMessageItem* msg;
        if(_d->_currentReg.size())
          msg = _d->_currentReg.at(0)->addCheck(source,target,"");
        else
          msg = _model->addCheck(source,target,"");
        msg->setSignal(signal);
        QListIterator<model::base::ParamItem*> paramIt(signal->params());
        auto bdy = ctx->functionCall2()->functionCallBody();
        while(bdy){
          auto param = paramIt.next();
          QVariant val;
          bool test = false;
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
            else{
              test = true;
            }
          }
          else if (bdy->signalParamName()) {
            //TODO: no idea
          }
          else if (bdy->attributeName()) {
            //TODO: no idea
          }
          if(!test && param) msg->addParamValue(param,val);
          if(bdy->functionCallBodyOptional()) bdy = bdy->functionCallBodyOptional()->functionCallBody();
          else break;
        }

        if(auto timeCtx = ctx->timeOutDecl()){
          QString value = "";
          if(timeCtx->REAL()){
            value = QString::fromStdString(timeCtx->REAL()->getText());
          }else if(timeCtx->INT()){
            value = QString::fromStdString(timeCtx->INT()->getText());
          }
          int val = value.toInt();
          if(timeCtx->SekID()){
            val *= 1000;
          }
          msg->setTimeout(val);
        }
        if(auto accCtx = ctx->accuracyDecl()){
          QString value = "";
          double val = 0.0;
          if(accCtx->REAL()){
            value = QString::fromStdString(accCtx->REAL()->getText());
            val = value.toDouble();
          }else if(accCtx->INT()){
            value = QString::fromStdString(accCtx->INT()->getText());
            val = static_cast<double>(value.toInt());
          }
          msg->setAccuracy(val);
        }

        this->_modelTextLocations->insert(msg->index(),
                                          TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                            static_cast<int>(ctx->getStop()->getStopIndex()),
                                                            Check));


        typedef  tree::TerminalNode* (TestCaseDeclParser::CheckDeclContext::*KeywordFunction)();

        return addKeywordLocation<TestCaseDeclParser::CheckDeclContext, KeywordFunction, TokenTextLocations>
            (ctx, &TestCaseDeclParser::CheckDeclContext::CheckID, this->_keywordTextLocations, Check);
      }
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("No Signal with name \"")
                       + QString::fromStdString(ctx->functionCall2()->idPath()->getText())
                       + QStringLiteral("\" found!"));
        return;
      }
    }
    else if(ctx->idPath().size() >1){
      appendDslError(ctx->getStart(),
                     QStringLiteral("No Component with name \"")
                     + QString::fromStdString(ctx->idPath().at(1)->getText())
                     + QStringLiteral("\" found!"));
      return;
    }
    else{
      if(this->_errors)
        this->_errors->append(DslError(QString("Wrong Syntax!")));
      return;
    }
  }
  else{

    Token* startToken = ctx->getStart();
    Token* stopToken = ctx->getStop();
    Q_ASSERT(startToken);
    Q_ASSERT(stopToken);
    appendDslError(ctx->getStart(),
                   QStringLiteral("No Component with name \"")
                   + QString::fromStdString(ctx->idPath().at(0)->getText())
                   + QStringLiteral("\" found!"));
    return;
  }
}

void TestCaseModelListener::exitTimeOutDecl(TestCaseDeclParser::TimeOutDeclContext *ctx)
{
  typedef  tree::TerminalNode* (TestCaseDeclParser::TimeOutDeclContext::*KeywordFunction)();

  addKeywordLocation<TestCaseDeclParser::TimeOutDeclContext, KeywordFunction, TokenTextLocations>
      (ctx, &TestCaseDeclParser::TimeOutDeclContext::TimeOutID, this->_keywordTextLocations, Timeout);
}

void TestCaseModelListener::exitIdStatement(TestCaseDeclParser::IdStatementContext *ctx)
{

  if(ctx->exception||!ctx->idPath())
    return;
  AttributeItem* item = nullptr;
  if(!_d->_isInData){
    if(getItemFromPath(ctx->idPath())){
      if(!ctx->assignmentDef()){
        if(CheckMessageItem* item = dynamic_cast<CheckMessageItem*>(this->_d->_currentPathItem)){
          if(_d->_currentAlt.size()==0){
            this->_model->addMessage(dynamic_cast<MessageItem*>(item));
            item = dynamic_cast<CheckMessageItem*>(const_cast<model::msc::MscSequenceItem*>(this->_model->sequenceItem(item->uuid())));
            int start,end;
            if(this->_d->_modelPositionOfCheck.contains(item)){
              QVector<int> vals = this->_d->_modelPositionOfCheck.value(item);
              start = vals.at(0);
              end = vals.at(1);
              if(!this->_modelTextLocations->contains(item->index()))
                this->_modelTextLocations->insert(item->index(),
                                                  TokenTextLocation(start,
                                                                    end,
                                                                    Check));
            }
            else{
              appendDslError(ctx->getStart(),
                             QStringLiteral("No Model Locations available!"));
              return;
            }
          }
          else{
            if(_d->_currentReg.size()){
              _d->_currentReg.at(0)->addMessage(dynamic_cast<MessageItem*>(item));
              item = dynamic_cast<CheckMessageItem*>(const_cast<model::msc::MscSequenceItem*>(this->_d->_currentReg.at(0)->sequenceItem(item->uuid())));
            }
            else{
              appendDslError(ctx->getStart(),
                             QStringLiteral("Current Region doesn't exist!"));
              return;
            }
          }
          return;
        }
        else{
          appendDslError(ctx->getStart(),
                         QStringLiteral("Item isn't a Step Item"));
          return;
        }
      }
      if((item = dynamic_cast<AttributeItem*>(this->_d->_currentPathItem)));
      else{
        appendDslError(ctx->getStart(),
                       QStringLiteral("Item isn't ParamItem"));
        return;
      }
    }
    else{
      appendDslError(ctx->getStart(),
                     QStringLiteral("Couldn't find attribute at Path!'"));
      return;
    }
  }
  if(_d->_isInDecl){
    if(item){
      if(ctx->assignmentDef()->TrueID() || ctx->assignmentDef()->FalseID()){
        if(item->dataType() == "bool"){
          item->setInitValue(QString::fromStdString(ctx->assignmentDef()->TrueID()->getText()));
        }
        else{
          appendDslError(ctx->getStart(),
                         QStringLiteral("Attribute is not of Type \'Bool\'"));
          return;
        }
      }
      else if(ctx->assignmentDef()->REAL()){
        if(item->dataType() == "real"){
          item->setInitValue(QString::fromStdString(ctx->assignmentDef()->REAL()->getText()));
        }
        else{
          appendDslError(ctx->getStart(),
                         QString("Attribute is not of Type \'Real\'"));
          return;
        }
      }
      else if(ctx->assignmentDef()->INT()){
        if(item->dataType() == "int"){
          item->setInitValue(QString::fromStdString(ctx->assignmentDef()->INT()->getText()));
        }
        else{
          appendDslError(ctx->getStart(),
                         QStringLiteral("Attribute is not of Type \'Int\'"));
          return;
        }
      }
      else if(ctx->assignmentDef()->STRING()){
        if(item->dataType() == "string"){
          item->setInitValue(QString::fromStdString(ctx->assignmentDef()->STRING()->getText()));
        }
        else{
          appendDslError(ctx->getStart(),
                         QStringLiteral("Attribute is not of Type \'String\'"));
          return;
        }
      }
    }
  }
  else if(!_d->_isInData){
    BaseComponentItem* comp = getOwner(item);
    model::msc::MscStatementItem* statItem = nullptr;
    if(_d->_currentReg.size())
      statItem = _d->_currentReg.at(0)->addStatement(comp,QString::fromStdString(ctx->getText()));
    else
      statItem = _model->addStatement(comp,QString::fromStdString(ctx->getText()));

    this->_modelTextLocations->insert(statItem->index(),
                                      TokenTextLocation(static_cast<int>(ctx->getStart()->getStartIndex()),
                                                        static_cast<int>(ctx->getStop()->getStopIndex()),
                                                        Statement));
  }
}

void TestCaseModelListener::exitIdPath(TestCaseDeclParser::IdPathContext *ctx)
{
  getItemFromPath(ctx);
}

bool TestCaseModelListener::getItemFromPath(TestCaseDeclParser::IdPathContext* path, ModelItem* mItem){
  this->_d->_currentPathItem = mItem;
  int curPos = -1;
  //    if(path->exception) return false;

  //  return false;//FIXME: next lines are temporarely comment out
  //  if(!path){
  //      Token* startToken = contId->getStart();
  //      Token* stopToken = contId->getStop();
  //      Q_ASSERT(startToken);
  //      Q_ASSERT(stopToken);
  //      if(this->_errors)
  //        this->_errors->append(DslError(QString("No Path There!"),
  //                                       startToken->getLine(),
  //                                       startToken->getCharPositionInLine()));
  //      return 0;
  //  }
  model::base::BaseModel* baseModel = nullptr;
  foreach (auto contId, path->contextID()) {
    curPos++;
    QString name = QString::fromStdString(contId->getText());
    if(name == "this" || name == "timeout"){
      //      path = path->idPath();
      continue;
    }
    if(baseModel){
      bool test = false;
      auto attributes = baseModel->attributes();
      int sz3 = attributes.size();
      for(int i = 0;i<sz3 && !test;i++){
        if(attributes.at(i)->name() == name){
          this->_d->_currentPathItem = dynamic_cast<ModelItem*>(attributes.at(i));
          test = true;
        }
      }
      auto compSignals = baseModel->getSignals();
      int sz2 = compSignals.size();
      for(int i = 0;i<sz2;i++){
        if(compSignals.at(i)->name() == name){
          this->_d->_currentPathItem = dynamic_cast<ModelItem*>(compSignals.at(i));
          i = sz2;
          test = true;
        }
      }
      //If Component wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("Incorrect Path to Component!"));
        _d->_errorAtPos = curPos;
        return false;
      }
      baseModel = nullptr;
      continue;
    }
    if(!this->_d->_currentPathItem){
      if(this->_d->_importItems.contains(name)){
        this->_d->_currentPathItem = this->_d->_importItems.value(name);
        //        path = path->idPath();
        continue;
      }
      else if(this->_d->_importModels.contains(name)){
        baseModel = this->_d->_importModels.value(name);
        //        path = path->idPath();
        continue;
      }
      else if(this->_d->_testCaseItems.contains(name)){
        this->_d->_currentPathItem = this->_d->_testCaseItems.value(name);
        //        path = path->idPath();
        continue;
      }
      else{
        this->_d->_currentPathItem = this->_model;
      }
    }
    if(TestCaseItem* item = dynamic_cast<TestCaseItem*>(this->_d->_currentPathItem)){
      auto components = item->componentItems();
      int sz = components.size();
      bool test = false;
      for(int i = 0;i<sz;i++){
        if(components.at(i)->name() == name){
          this->_d->_currentPathItem = dynamic_cast<ModelItem*>(const_cast<model::msc::MscComponentItem*>(components.at(i)));
          i = sz;
          test = true;
        }
      }
      auto attributes = item->attributes();
      int sz3 = attributes.size();
      for(int i = 0;i<sz3 && !test;i++){
        if(attributes.at(i)->name() == name){
          this->_d->_currentPathItem = dynamic_cast<ModelItem*>(attributes.at(i));
          test = true;
        }
      }
      auto compSignals = item->getSignals();
      int sz2 = compSignals.size();
      for(int i = 0;i<sz2;i++){
        if(compSignals.at(i)->name() == name){
          this->_d->_currentPathItem = dynamic_cast<ModelItem*>(compSignals.at(i));
          i = sz2;
          test = true;
        }
      }
      //If Component wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("Incorrect Path to Component!"));
        _d->_errorAtPos = curPos;
        return false;
      }
    }
    else if(SignalItem* item = dynamic_cast<SignalItem*>(this->_d->_currentPathItem)){
      auto attributes = item->params();
      int sz2 = attributes.size();
      bool test = false;
      for(int i = 0;i<sz2 && !test;i++){
        if(attributes.at(i)->name() == name){
          this->_d->_currentPathItem = dynamic_cast<ModelItem*>(attributes.at(i));
          test = true;
        }
      }
      //If Attributes wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("No Attribute with this name!"));
        _d->_errorAtPos = curPos;
        return 0;
      }
    }
    else if(TestSystemItem* item = dynamic_cast<TestSystemItem*>(this->_d->_currentPathItem)){
      auto components = item->components();
      int sz = components.size();
      bool test = false;
      for(int i = 0;i<sz;i++){
        if(components.at(i)->name() == name){
          this->_d->_currentPathItem = components.at(i);
          i = sz;
          test = true;
        }
      }
      //If Component wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("Incorrect Path to Component!"));
        _d->_errorAtPos = curPos;
        return false;
      }
    }
    else if(TestComponentItem* item = dynamic_cast<TestComponentItem*>(this->_d->_currentPathItem)){
      auto ports = item->ports();
      int sz = ports.size();
      bool test = false;
      for(int i = 0;i<sz;i++){
        if(ports.at(i)->name() == name){
          this->_d->_currentPathItem = ports.at(i);
          i = sz;
          test = true;
        }
      }
      //If Port wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("Incorrect Path to Port!"));
        _d->_errorAtPos = curPos;
        return false;
      }
    }
    else if(SutItem* item = dynamic_cast<SutItem*>(this->_d->_currentPathItem)){
      auto components = item->components();
      int sz = components.size();
      bool test = false;
      for(int i = 0;i<sz;i++){
        if(components.at(i)->name() == name){
          this->_d->_currentPathItem = components.at(i);
          i = sz;
          test = true;
        }
      }
      //If Component wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("Incorrect Path to Port!"));
        _d->_errorAtPos = curPos;
        return false;
      }
    }
    else if(SutComponentItem* item = dynamic_cast<SutComponentItem*>(this->_d->_currentPathItem)){
      auto ports = item->ports();
      int sz = ports.size();
      bool test = false;
      for(int i = 0;i<sz;i++){
        if(ports.at(i)->name() == name){
          this->_d->_currentPathItem = ports.at(i);
          i = sz;
          test = true;
        }
      }
      //If Port wasn't found!!
      if(!test){
        appendDslError(path->getStart(),
                       QStringLiteral("Incorrect Path to Port!"));
        _d->_errorAtPos = curPos;
        return false;
      }
    }
    else{
      _d->_errorAtPos = curPos;
      return false;
    }
    //    path = path->idPath();
  }
  curPos++;
  _d->_errorAtPos = curPos;
  return true;
}

QString TestCaseModelListener::getExpression(TestCaseDeclParser::ExpressionContext *ctx)
{
  if(!ctx || ctx->exception)
    return "";
  const misc::Interval interval(ctx->getStart()->getStartIndex(),ctx->getStop()->getStopIndex());
  return QString::fromStdString(ctx->getStart()->
                                getInputStream()->
                                getText(interval));
}

model::msc::MscComponentItem *TestCaseModelListener::getOwner(AttributeItem *item)
{
  for(model::base::ComponentItem* comp : this->_d->_testSystemItem->components()){
    model::msc::MscComponentItem* m_comp = dynamic_cast<model::msc::MscComponentItem*>(comp);
    for(AttributeItem* att : m_comp->attributes()){
      if(item->index() == att->index()){
        return m_comp;
      }
    }
  }

  for(const model::base::ComponentItem* comp : this->_d->_testSystemItem->sutItem()->components()){
    model::msc::MscComponentItem* m_comp = const_cast<model::msc::MscComponentItem*>(dynamic_cast<const model::msc::MscComponentItem*>(comp));
    for(AttributeItem* att : m_comp->attributes()){
      if(item->index() == att->index()){
        return m_comp;
      }
    }
  }
  model::base::ComponentItem* comp = this->_d->_testSystemItem->components().first();
  model::msc::MscComponentItem* m_comp = dynamic_cast<model::msc::MscComponentItem*>(comp);
  if(m_comp){
    return m_comp;
  }else{
    return nullptr;
  }
}

void TestCaseModelListener::visitErrorNode(tree::ErrorNode* node)
{
  Q_UNUSED(node);
  return;
}
/*
bool TestCaseModelListener::addImportedModel(const QString &name, base::BaseModel *model, QString *errorMessage) const
{
    if(_d->_importModels.contains(name)){
        if(errorMessage)  errorMessage->append(QString("The BaseModel with the name \"%1\" already exists!").arg(name));
        return false;
    }
    _d->_importModels.insert(name,model);
    return true;
}

void TestCaseModelListener::removeImportedModel(const QString &name) const
{
    if(_d->_importModels.contains(name)){
        delete _d->_importModels.value(name);
        _d->_importModels.remove(name);
    }
}*/

} // namespace testcase
} // namespace dslparser
