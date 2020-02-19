#include "combuildisrdlmodel.hpp"

#include <mobata/model/isrdl/isrdlitem.hpp>
#include <mobata/model/isrdl/isrdlmodel.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "IsrdlLexer.h"
#include "IsrdlParser.h"

#include "isrdlmodellistener.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace model::isrdl;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace isrdl {

class IsrdlErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  IsrdlErrorListener(DslErrorList* errors)
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
    qDebug()<<"IsrdlErrorListener::syntaxError() executed!: "<<msg.c_str();

    if(this->_errors)
    {
      DslError isrdlError(QString::fromStdString(msg),
                        line,
                        charPositionInLine);
      if(offendingSymbol)
        isrdlError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(isrdlError);
    }

    return;
  }
};

class ComBuildIsrdlModel::Private
{
  friend class ComBuildIsrdlModel;

  QString                   _isrdlDocText;
  model::isrdl::IsrdlModel* _isrdlDeclModel;
  bool                      _strictErrorHandling;
  DslErrorList              _isrdlErrors;
  TokenTextLocations        _keywordTextLocations;
  ModelTextLocations        _modelTextLocations;
  IsrdlModelListener        _isrdlModelListener;

  Private(const QString& isrdlDocText,
          model::isrdl::IsrdlModel* isrdlDeclModel,
          bool strictErrorHandling)
    : _isrdlDocText(isrdlDocText),
      _isrdlDeclModel(isrdlDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _isrdlModelListener(this->_isrdlDeclModel,
                        &this->_isrdlErrors,
                        &this->_keywordTextLocations,
                        &this->_modelTextLocations)
  {}
};

ComBuildIsrdlModel::ComBuildIsrdlModel(const QString& isrdlDocText,
                                   model::isrdl::IsrdlModel* isrdlDeclModel,
                                   bool strictErrorHandling,
                                   QObject* parent)
  : QObject(parent), _d(new Private(isrdlDocText, isrdlDeclModel, strictErrorHandling))
{}

ComBuildIsrdlModel::~ComBuildIsrdlModel()
{
  delete  this->_d;
}

bool ComBuildIsrdlModel::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_isrdlDeclModel);
  this->_d->_isrdlDeclModel->reset();

  //  qDebug() << "building isrdl model for doc-text: " << this->_d->_isrdlDocText;

  ANTLRInputStream input(this->_d->_isrdlDocText.toStdString());
  IsrdlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  IsrdlParser parser(&tokens);

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

  IsrdlErrorListener myErrorListener(&this->_d->_isrdlErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  IsrdlParser::SecRequirementContext* secRequirementCtx = 0;
  auto start = std::chrono::steady_clock::now();
  try
  {
    //parser.addParseListener(&this->_d->_isrdlModelListener);
    secRequirementCtx = parser.secRequirement();
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
  if(secRequirementCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_isrdlModelListener, secRequirementCtx);

//    qDebug()<<"Parse tree: " << isrdlDeclCtx->toStringTree(&parser).c_str();
  }

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_isrdlErrors.count()){
    foreach (DslError err, this->_d->_isrdlErrors) {
      AddPtrString(errorString)<<err.message();
    }
    return false;
  }

  return true;
}

const DslErrorList& ComBuildIsrdlModel::errors() const
{
  return this->_d->_isrdlErrors;
}

const TokenTextLocations& ComBuildIsrdlModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations &ComBuildIsrdlModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

model::isrdl::IsrdlModel* ComBuildIsrdlModel::isrdlModel()
{
  return this->_d->_isrdlDeclModel;
}

} // namespace isrdl
} // namespace dslparser
