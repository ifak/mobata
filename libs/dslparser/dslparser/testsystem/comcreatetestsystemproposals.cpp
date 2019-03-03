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

#include "comcreatetestsystemproposals.hpp"

#include "combuildtestsystemmodel.hpp"
#include "dslproposal.hpp"

#include <mobata/model/ts/ts.hpp>

#include <mobata/utils/functors.hpp>

#include <QDebug>
#include <QDir>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>
#include "TestSystemDeclParser.h"
#include "TestSystemDeclLexer.h"
#include "TestSystemDeclBaseListener.h"
#include "testsystemmodellistener.hpp"

using namespace utils;
using namespace model::ts;
using namespace model::base;
using namespace antlr4;

namespace dslparser {
namespace testsystem {

class TestSystemProposalErrorListener
    : public BaseErrorListener
{
  std::size_t         _line;
  std::size_t         _posInLine;
  DslProposalList*    _testSystemProposals;
  TestSystemItem*     _testSystemDeclModel;
  ImportedModelItems  _importItems;
  QString             _praefix;

public:
  TestSystemProposalErrorListener(std::size_t line,
                                  int posInLine,
                                  DslProposalList* testSystemProposals,
                                  const ImportedModelItems& importItems,
                                  TestSystemItem* testSystemDeclModel = nullptr,
                                  const QString& praefix = "")
    : _line(line),
      _posInLine(std::size_t(posInLine)),
      _testSystemProposals(testSystemProposals),
      _testSystemDeclModel(testSystemDeclModel),
      _importItems(importItems),
      _praefix(praefix)
  {}


protected:
  virtual void syntaxError(Recognizer* recognizer,
                           Token* offendingSymbol,
                           size_t line,
                           std::size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    Q_ASSERT(this->_testSystemProposals);
    Q_UNUSED(offendingSymbol);
    Q_UNUSED(msg);

    if(line != this->_line)
      return;

    if(charPositionInLine != this->_posInLine)
      return;

    TestSystemDeclParser* parser = static_cast<TestSystemDeclParser*>(recognizer);
    Q_ASSERT(parser);
    ParserRuleContext* ruleCtx = parser->getRuleContext();
    Q_ASSERT(ruleCtx);
    std::size_t ruleIndex = ruleCtx->getRuleIndex();

    ////debug stuff
    //std::vector<std::string> ruleInvocationStack = parser->getRuleInvocationStack();
    //qDebug()<<"rule-invocation-stack-size: "<<ruleInvocationStack.size();
    //for(const std::string& rule : ruleInvocationStack)
    //  qDebug()<<"rule-invocation: "<<rule.c_str();
    //RuleContext* debugParentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent);
    //if(debugParentRuleCtx)
    //  qDebug()<<"parent-rule-context-string-tree: "<<QString::fromStdString(debugParentRuleCtx->toStringTree(parser));

    if(ruleIndex == TestSystemDeclParser::RuleContextID)
    {
      if(RuleContext* parentRuleCtx = dynamic_cast<RuleContext*>(ruleCtx->parent))
      {
        if(parentRuleCtx->getRuleIndex() == TestSystemDeclParser::RuleAttributeName)
          CalcRefAttributesProposals(this->_testSystemDeclModel, this->_testSystemProposals)();
        else if(parentRuleCtx->getRuleIndex() == TestSystemDeclParser::RuleIdPath)
        {
          if(RuleContext* parentParentRuleCtx = dynamic_cast<RuleContext*>(parentRuleCtx->parent))
          {
            if(parentParentRuleCtx->getRuleIndex() == TestSystemDeclParser::RuleSourceDecl
               || parentParentRuleCtx->getRuleIndex() == TestSystemDeclParser::RuleTargetDecl)
              this->portLinkingDecl(parser->getTokenStream());
          }
        }
      }
    }
    else if (ruleIndex == TestSystemDeclParser::RuleImportFileBody)
      this->getFile(parser->getTokenStream());
    else
    {//keywords
      const dfa::Vocabulary& vocabulary = parser->getVocabulary();
      misc::IntervalSet expTokens = parser->getExpectedTokens();
      for (auto token : expTokens.toList())
      {
        if((ruleIndex == TestSystemDeclParser::RuleTypeDecl
            || ruleIndex == TestSystemDeclParser::RuleSignalDecl)
           && this->isContextID(token))
          continue;
        else if(token == TestSystemDeclParser::ID)
          continue;//no contextID token as proposal

        QString displayName = QString::fromStdString(vocabulary.getDisplayName(token)).trimmed();
//        qDebug()<<"else - expected token name: "<<displayName;

        if(displayName.startsWith("'"))
          displayName.remove(0,1);
        if(displayName.endsWith("'"))
          displayName.remove(displayName.size()-1,1);

        this->_testSystemProposals->append(DslProposal(displayName,
                                                       testSystemTokenType(token)));
      }
    }

    ///sort alphabetically
    qSort(this->_testSystemProposals->begin(), this->_testSystemProposals->end());

    return;
  }

  bool isContextID(std::size_t token)
  {
    if(isCommonContextID<TestSystemDeclParser>(token))
      return true;

    return (token == TestSystemDeclParser::TestComponentID
            || token == TestSystemDeclParser::TestSystemID
            || token == TestSystemDeclParser::LinkID
            || token == TestSystemDeclParser::TargetID
            || token == TestSystemDeclParser::SourceID);
  }

  void getFile(TokenStream* tokens){
    bool end = false;
    QString curPath("");
    QStringList curList;
    int sz = tokens->size();
    int i = 0;
    while(i<sz && !end){
      for(int j=i;j<sz;i++){
        Token* token = tokens->get(i);
        if(token->getType() == TestSystemDeclParser::ImportID){
          j=sz;
        }
        if(token->getLine()>=this->_line && token->getCharPositionInLine()>this->_posInLine){
          break;
        }
        j++;
      }
      for(int j = i;j<sz;i++){
        Token* token = tokens->get(i);
        if(token->getType() == TestSystemDeclParser::GREATERTHAN){
          curPath.clear();
          curList.clear();
          j = sz;
        }
        else if(token->getType() == TestSystemDeclParser::ID ||
                token->getType() == TestSystemDeclParser::RANGE){
          if(token->getLine()>=this->_line
             && (token->getText().size()+token->getCharPositionInLine())
             >this->_posInLine){
            end = true;
            curPath = QString::fromStdString(token->getText());
          }
          else{
            QString modelname = QString::fromStdString(token->getText());
            curList.append(modelname);
          }
        }
        j++;
      }
    }

    QDir homeDir(this->_praefix);
    int sz2 = curList.size();
    i = 0;
    bool test = true;
    while (i<sz2 && test) {
      test = homeDir.cd(curList.at(i));
      if(!test) curPath = curList.at(i);
      i++;
    }

    if(i < sz2 && !test) return;
    sz = curPath.size();
    QStringList list = homeDir.entryList();
    for(QString option: list) {
      QString test = option;
      test.resize(sz);
      if(test == curPath)
        this->_testSystemProposals->append(DslProposal(option.remove(0,sz),
                                                       Identifier));
    }
  }

  void portLinkingDecl(TokenStream* tokens){
    int t_sz = tokens->size();
    int i = 0;
    bool end = false;
    if(!this->_testSystemDeclModel)
      return;
    ModelItem* model = nullptr;
    QString rest = "";
    bool failure = false;
    while(i<t_sz && !end){
      for(int j=i;j<t_sz;i++){
        Token* token = tokens->get(i);
        if(token->getType() == TestSystemDeclParser::SourceID ||
           token->getType() == TestSystemDeclParser::TargetID){
          j=t_sz;
        }
        if(token->getLine()>=this->_line && token->getCharPositionInLine()>this->_posInLine){
          break;
        }
        j++;
      }
      for(int j = i;j<t_sz;i++){
        Token* token = tokens->get(i);
        if(token->getType() == TestSystemDeclParser::SEMI){
          model = nullptr;
          j = t_sz;
        }
        else if(token->getType() == TestSystemDeclParser::ID){
          if(token->getLine()>=this->_line
             && (token->getText().size()+token->getCharPositionInLine())
             >this->_posInLine){
            end = true;
            rest = QString::fromStdString(token->getText());
          }
          else{
            QString modelname = QString::fromStdString(token->getText());
            model = getComponent(model,modelname);
            failure = !model;
          }
        }
        j++;
      }
    }
    int q_sz = rest.size();
    if(failure) return;
    QHash<QString, ModelItem*> models = getComponents(model);
    for(QString option: models.keys()) {
      QString test = option;
      test.resize(q_sz);
      if(test == rest)
        this->_testSystemProposals->append(DslProposal(option.remove(0,q_sz),
                                                       Identifier));
    }
    return;
  }

  ModelItem* getComponent(ModelItem* model,QString name){
    QHash<QString, ModelItem*> models = getComponents(model);
    return models.value(name);
  }

  QHash<QString, ModelItem*> getComponents(ModelItem* model){
    QHash<QString, ModelItem*> models;
    if(!model){
      for(QString m: this->_importItems.keys()) {
        models.insert(m,_importItems.value(m));
      }
      model = this->_testSystemDeclModel;
    }
    if(dynamic_cast<TestSystemItem*>(model)){
      auto components = dynamic_cast<TestSystemItem*>(model)->components();
      int sz = components.size();
      for(int i = 0;i<sz;i++){
        models.insert(components.at(i)->name(),components.at(i));
      }
    }
    else if(dynamic_cast<TestComponentItem*>(model)){
      auto ports = dynamic_cast<TestComponentItem*>(model)->ports();
      int sz = ports.size();
      for(int i = 0;i<sz;i++){
        models.insert(ports.at(i)->name(),ports.at(i));
      }
    }
    else if(dynamic_cast<SutItem*>(model)){
      auto components = dynamic_cast<SutItem*>(model)->components();
      int sz = components.size();
      for(int i = 0;i<sz;i++){
        models.insert(components.at(i)->name(),components.at(i));
      }
    }
    else if(dynamic_cast<SutComponentItem*>(model)){
      auto ports = dynamic_cast<SutComponentItem*>(model)->ports();
      int sz = ports.size();
      for(int i = 0;i<sz;i++){
        models.insert(ports.at(i)->name(),ports.at(i));
      }
    }
    return models;
  }
};

class ComCreateTestSystemProposals::Private
{
  friend class ComCreateTestSystemProposals;

  QString         _testSystemDocText;
  QString         _praefix;
  bool            _strictErrorHandling;
  DslProposalList _testsystemProposals;

  Private(const QString& testSystemDocText,
          QString praefix,
          bool strictErrorHandling)
    : _testSystemDocText(testSystemDocText),
      _praefix(praefix),
      _strictErrorHandling(strictErrorHandling)
  {}
};

ComCreateTestSystemProposals::ComCreateTestSystemProposals(const QString& testSystemDocText,
                                                           QString praefix,
                                                           bool strictErrorHandling,
                                                           QObject *parent)
  : QObject(parent), _d(new Private(testSystemDocText,
                                    praefix,
                                    strictErrorHandling))
{

}

ComCreateTestSystemProposals::~ComCreateTestSystemProposals()
{
  delete this->_d;
}

bool ComCreateTestSystemProposals::execute(QString* errorString)
{
  //  qDebug() << "calculating proposals for: " << this->_d->_TestSystemDocText;

  TestSuite testSuiteModel;
  TestSystemItem* testSystemModel=testSuiteModel.testSystemItem();


  Q_ASSERT(testSystemModel);
  ComBuildTestSystemModel buildCommand(this->_d->_testSystemDocText,
                                       testSystemModel,
                                       this->_d->_praefix);
  buildCommand.execute();

  ANTLRInputStream input(this->_d->_testSystemDocText.toStdString());
  TestSystemDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  TestSystemDeclParser parser(&tokens);

  if(isWithinComment<TestSystemDeclLexer>(this->_d->_testSystemDocText, tokens, errorString))
    return true; //is within comment -> no proposals

  parser.setBuildParseTree(false);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);


  // calculating line and pos in line...
  QPair<std::size_t, int> linePos = utils::CalcPosInLine()(this->_d->_testSystemDocText);
  TestSystemProposalErrorListener testSystemProposalErrorListener(linePos.first,
                                                                  linePos.second,
                                                                  &this->_d->_testsystemProposals,
                                                                  buildCommand.importItems(),
                                                                  testSystemModel,
                                                                  this->_d->_praefix);
  parser.removeErrorListeners();
  parser.addErrorListener(&testSystemProposalErrorListener);
  auto start = std::chrono::steady_clock::now();
  try
  {
    parser.testSystemDecl();
  }
  catch (RecognitionException& re)
  {
    AddPtrString(errorString)<<"RecognitionException: "<<re.what();
    AddPtrString(errorString) << "expected tokens: "<<re.getExpectedTokens().toString().c_str();

    if(this->_d->_strictErrorHandling)
      return false;
  }
  catch (ParseCancellationException &pce)
  {
    AddPtrString(errorString)<<"ParseCancellationException: "<<pce.what();

    if(this->_d->_strictErrorHandling)
      return false;
  }
  catch (std::exception& exc)
  {
    AddPtrString(errorString)<<"std::exception: "<<exc.what();

    if(this->_d->_strictErrorHandling)
      return false;
  }

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  qDebug() << "Proposal time: " << duration.count() / 1000.0 << " ms";

  return true;
}

const DslProposalList& ComCreateTestSystemProposals::testSystemProposals() const
{
  return this->_d->_testsystemProposals;
}

} // namespace common
} // namespace dslparser
