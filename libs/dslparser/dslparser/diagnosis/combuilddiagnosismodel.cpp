#include "combuilddiagnosismodel.hpp"

#include <mobata/model/ts/ts.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "DiagnosisDeclLexer.h"
#include "DiagnosisDeclParser.h"

#include "diagnosismodellistener.hpp"
#include "mobata/model/diagnosis/diagnosisitem.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace model::ts;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace diagnosis {

class DiagnosisErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  DiagnosisErrorListener(DslErrorList* errors)
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
    if(this->_errors)
    {
      DslError diagnosisError(QString::fromStdString(msg),
                           line,
                           charPositionInLine);
      if(offendingSymbol)
        diagnosisError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(diagnosisError);
    }

    return;
  }
};

class ComBuildDiagnosisModel::Private
{
  friend class ComBuildDiagnosisModel;

  QString             _diagnosisDocText;
  model::diagnosis::DiagnosisItem*  _diagnosisDeclModel;
  bool                _strictErrorHandling;
  DslErrorList        _diagnosisErrors;
  TokenTextLocations  _keywordTextLocations;
  ModelTextLocations  _modelTextLocations;
  QString                   _importedSutFile;
  QString                   _importedTestSystemFile;
  DiagnosisModelListener     _diagnosisModelListener;

  Private(const QString& diagnosisDocText,
          model::diagnosis::DiagnosisItem* diagnosisDeclModel,
          const QString& praefix,
          bool strictErrorHandling)
    : _diagnosisDocText(diagnosisDocText),
      _diagnosisDeclModel(diagnosisDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _diagnosisModelListener(this->_diagnosisDeclModel,
                             &this->_diagnosisErrors,
                             &this->_importedSutFile,
                             &this->_importedTestSystemFile,
                             praefix,
                             &this->_keywordTextLocations,
                             &this->_modelTextLocations)
  {}
};

ComBuildDiagnosisModel::ComBuildDiagnosisModel(const QString& diagnosisDocText,
                                             model::diagnosis::DiagnosisItem* diagnosisDeclModel,
                                             const QString& praefix,
                                             bool strictErrorHandling,
                                             QObject* parent)
  : QObject(parent), _d(new Private(diagnosisDocText, diagnosisDeclModel, praefix, strictErrorHandling))
{}

ComBuildDiagnosisModel::~ComBuildDiagnosisModel()
{
  delete  this->_d;
}

bool ComBuildDiagnosisModel::execute(QString* errorString, FileType type)
{
  Q_ASSERT(this->_d->_diagnosisDeclModel);
  this->_d->_diagnosisDeclModel->reset();

  //  qDebug() << "building Diagnosis model for doc-text: " << this->_d->_DiagnosisDocText;

  ANTLRInputStream input(this->_d->_diagnosisDocText.toStdString());
  DiagnosisDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  DiagnosisDeclParser parser(&tokens);


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

  DiagnosisErrorListener myErrorListener(&this->_d->_diagnosisErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  antlr4::ParserRuleContext* DiagnosisDeclCtx = 0;
  auto start = std::chrono::steady_clock::now();
  try
  {
    //parser.addParseListener(&this->_d->_DiagnosisModelListener);
    if(type == Complete) DiagnosisDeclCtx = (antlr4::ParserRuleContext*)parser.diagnosisDecl();
    else if(type == Signals) DiagnosisDeclCtx = (antlr4::ParserRuleContext*)parser.diagnosisSignalsDecl();
    else if(type == Components) DiagnosisDeclCtx = (antlr4::ParserRuleContext*)parser.componentsDecl();
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
  if(DiagnosisDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_diagnosisModelListener, DiagnosisDeclCtx);

//    qDebug()<<"Parse tree: " << DiagnosisDeclCtx->toStringTree(&parser).c_str();
  }

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_diagnosisErrors.count()){
    foreach (DslError err, this->_d->_diagnosisErrors) {
      AddPtrString(errorString)<<err.message();
    }
    return false;
  }

  return true;
}

const DslErrorList& ComBuildDiagnosisModel::errors() const
{
  return this->_d->_diagnosisErrors;
}

const TokenTextLocations& ComBuildDiagnosisModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations &ComBuildDiagnosisModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

const QString& ComBuildDiagnosisModel::importedSutFile() const
{
  return this->_d->_importedSutFile;
}

const QString& ComBuildDiagnosisModel::importedTestSystemFile() const
{
  return this->_d->_importedTestSystemFile;
}

const QHash<QString, model::base::ModelItem*>& ComBuildDiagnosisModel::diagnosisItems()
{
  return this->_d->_diagnosisModelListener.diagnosisItems();
}

model::base::ModelItem *ComBuildDiagnosisModel::currentPathItem()
{
  return this->_d->_diagnosisModelListener.currentPathItem();
}

model::base::ModelItem *ComBuildDiagnosisModel::currentSignalItem()
{
  return this->_d->_diagnosisModelListener.currentSignalItem();
}

const ImportModelItem& ComBuildDiagnosisModel::importItems()
{
  return this->_d->_diagnosisModelListener.importItems();
}

} // namespace Diagnosis
} // namespace dslparser
