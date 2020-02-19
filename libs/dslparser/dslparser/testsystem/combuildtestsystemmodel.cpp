#include "combuildtestsystemmodel.hpp"

#include <mobata/model/ts/ts.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "TestSystemDeclLexer.h"
#include "TestSystemDeclParser.h"

#include "testsystemmodellistener.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace testsystem {

class TestSystemErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  TestSystemErrorListener(DslErrorList* errors)
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
    qDebug()<<"TestSystemErrorListener::syntaxError() executed!: "<<msg.c_str();

    if(this->_errors)
    {
      DslError testsystemError(QString::fromStdString(msg),
                               static_cast<int>(line),
                               static_cast<int>(charPositionInLine));
      if(offendingSymbol)
        testsystemError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(testsystemError);
    }

    return;
  }
};

class ComBuildTestSystemModel::Private
{
  friend class ComBuildTestSystemModel;

  QString                 _testSystemDocText;
  TestSystemItem*         _testSystemDeclModel;
  QString                 _importedSutFile;
  bool                    _strictErrorHandling;
  DslErrorList            _testSystemErrors;
  TokenTextLocations      _keywordTextLocations;
  ModelTextLocations      _modelTextLocations;
  TestSystemModelListener _testSystemModelListener;

  Private(const QString& testsystemDocText,
          TestSystemItem* testsystemDeclModel,
          const QString& praefix,
          bool strictErrorHandling)
    : _testSystemDocText(testsystemDocText),
      _testSystemDeclModel(testsystemDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _testSystemModelListener(this->_testSystemDeclModel,
                               &this->_testSystemErrors,
                               &this->_importedSutFile,
                               praefix,
                               &this->_keywordTextLocations,
                               &this->_modelTextLocations)
  {}
};

ComBuildTestSystemModel::ComBuildTestSystemModel(const QString& testSystemDocText,
                                                 TestSystemItem* testSystemModel,
                                                 const QString& praefix,
                                                 bool strictErrorHandling,
                                                 QObject* parent)
  : QObject(parent), _d(new Private(testSystemDocText,
                                    testSystemModel,
                                    praefix,
                                    strictErrorHandling))
{}

ComBuildTestSystemModel::~ComBuildTestSystemModel()
{
  delete  this->_d;
}

bool ComBuildTestSystemModel::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_testSystemDeclModel);
  this->_d->_testSystemDeclModel->reset();

//  qDebug() << "building TestSystem model for doc-text: " << this->_d->_TestSystemDocText;

  ANTLRInputStream input(this->_d->_testSystemDocText.toStdString());
  TestSystemDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  TestSystemDeclParser parser(&tokens);

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

  TestSystemErrorListener myErrorListener(&this->_d->_testSystemErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  TestSystemDeclParser::TestSystemDeclContext* testsystemDeclCtx = nullptr;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    //parser.addParseListener(&this->_d->_TestSystemModelListener);
    testsystemDeclCtx = parser.testSystemDecl();
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
  if(testsystemDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_testSystemModelListener, testsystemDeclCtx);

//    qDebug()<<"Parse tree: " << testsystemDeclCtx->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_testSystemErrors.count()){
    foreach (DslError err, this->_d->_testSystemErrors) {
      AddPtrString(errorString)<<err.message();
    }
    return false;
  }
  return true;
}

const DslErrorList& ComBuildTestSystemModel::errors() const
{
  return this->_d->_testSystemErrors;
}

const TokenTextLocations& ComBuildTestSystemModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations &ComBuildTestSystemModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

const QString& ComBuildTestSystemModel::importedSutFile() const
{
  return this->_d->_importedSutFile;
}

const ImportedModelItems& ComBuildTestSystemModel::importItems()
{
  return this->_d->_testSystemModelListener.importedModelItems();
}

} // namespace TestSystem
} // namespace dslparser
