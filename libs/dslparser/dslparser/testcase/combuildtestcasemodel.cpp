#include "combuildtestcasemodel.hpp"

#include <mobata/model/ts/ts.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "TestCaseDeclLexer.h"
#include "TestCaseDeclParser.h"

#include "testcasemodellistener.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace testcase {

class TestCaseErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  TestCaseErrorListener(DslErrorList* errors)
    : _errors(errors)
  {}

protected:
  virtual void syntaxError(Recognizer* /*recognizer*/,
                           Token* offendingSymbol,
                           size_t line,
                           size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr /*e*/) override
  {
    qDebug()<<"TestCaseErrorListener::syntaxError() executed!: "<<msg.c_str();

    if(this->_errors)
    {
      DslError testcaseError(QString::fromStdString(msg),
                           static_cast<int>(line),
                           static_cast<int>(charPositionInLine));
      if(offendingSymbol)
        testcaseError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(testcaseError);
    }

    return;
  }
};

class ComBuildTestCaseModel::Private
{
  friend class ComBuildTestCaseModel;

  QString                   _testcaseDocText;
  model::ts::TestCaseItem*  _testCaseDeclModel;
  bool                      _strictErrorHandling;
  DslErrorList              _testCaseErrors;
  TokenTextLocations        _keywordTextLocations;
  ModelTextLocations        _modelTextLocations;
  model::ts::TestSystemItem* _testSystemItem;
  TestCaseModelListener     _testCaseModelListener;

  Private(const QString& testcaseDocText,
          model::ts::TestCaseItem* testCaseDeclModel,
          model::ts::TestSystemItem* testSystemItem,
          const QString& praefix,
          bool strictErrorHandling)
    : _testcaseDocText(testcaseDocText),
      _testCaseDeclModel(testCaseDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _testSystemItem(testSystemItem),
      _testCaseModelListener(this->_testCaseDeclModel,
                             &this->_testCaseErrors,
                             this->_testSystemItem,
                             praefix,
                             &this->_keywordTextLocations,
                             &this->_modelTextLocations)
  {}
};

ComBuildTestCaseModel::ComBuildTestCaseModel(const QString& testCaseDocText,
                                             model::ts::TestCaseItem* testCaseDeclModel,
                                             model::ts::TestSystemItem* testSystemItem,
                                             const QString& praefix,
                                             bool strictErrorHandling,
                                             QObject* parent)
  : QObject(parent), _d(new Private(testCaseDocText, testCaseDeclModel, testSystemItem, praefix, strictErrorHandling))
{}

ComBuildTestCaseModel::~ComBuildTestCaseModel()
{
  delete  this->_d;
}

bool ComBuildTestCaseModel::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_testCaseDeclModel);
  this->_d->_testCaseDeclModel->reset();

  //  qDebug() << "building TestCase model for doc-text: " << this->_d->_TestCaseDocText;

  ANTLRInputStream input(this->_d->_testcaseDocText.toStdString());
  TestCaseDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  TestCaseDeclParser parser(&tokens);

  parser.setBuildParseTree(true);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);

  try
  {//dumpTokenStream
    tokens.fill();
  } catch (IllegalStateException &)
  {
    AddPtrString(errorString)<<"Error: illegal state found, probably unfinished string.";
    return false;
  }

  //  for (auto token : tokens.getTokens())
  //    qDebug() << token->toString().c_str();

  TestCaseErrorListener myErrorListener(&this->_d->_testCaseErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  TestCaseDeclParser::TestCaseDeclContext* TestCaseDeclCtx = nullptr;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    //parser.addParseListener(&this->_d->_TestCaseModelListener);
    TestCaseDeclCtx = parser.testCaseDecl();
  }
  catch (NoViableAltException& nvae)
  {
    AddPtrString(errorString)<<"NoViableAltException: "<<nvae.what();
    AddPtrString(errorString) << "expected tokens: "<<nvae.getExpectedTokens().toString().c_str();

    if(this->_d->_strictErrorHandling)
      return false;
  }
  catch (InputMismatchException& ime)
  {
    AddPtrString(errorString)<<"InputMismatchException: "<<ime.what();
    AddPtrString(errorString) << "expected tokens: "<<ime.getExpectedTokens().toString().c_str();

    if(this->_d->_strictErrorHandling)
      return false;
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
  if(TestCaseDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_testCaseModelListener, TestCaseDeclCtx);

//    qDebug()<<"Parse tree: " << TestCaseDeclCtx->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_testCaseErrors.count()){
    foreach (DslError err, this->_d->_testCaseErrors) {
      AddPtrString(errorString)<<err.message();
    }
    return false;
  }

  return true;
}

const DslErrorList& ComBuildTestCaseModel::errors() const
{
  return this->_d->_testCaseErrors;
}

const TokenTextLocations& ComBuildTestCaseModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations &ComBuildTestCaseModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

const QHash<QString, model::base::ModelItem*>& ComBuildTestCaseModel::testCaseItems()
{
  return this->_d->_testCaseModelListener.testCaseItems();
}

QPair<model::base::ModelItem*,int> ComBuildTestCaseModel::currentPathItem()
{
  return this->_d->_testCaseModelListener.currentPathItem();
}

model::base::ModelItem *ComBuildTestCaseModel::currentSignalItem()
{
  return this->_d->_testCaseModelListener.currentSignalItem();
}

const ImportModelItem& ComBuildTestCaseModel::importItems()
{
  return this->_d->_testCaseModelListener.importItems();
}

} // namespace TestCase
} // namespace dslparser
