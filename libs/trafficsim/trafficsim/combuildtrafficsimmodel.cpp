#include "combuildtrafficsimmodel.hpp"

#include "trafficsimmodel.hpp"
#include <mobata/utils/functors.hpp>

#include <dslparser/dslerror.hpp>

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include <dslparser/trafficsim/TrafficSimDeclLexer.h>
#include <dslparser/trafficsim/TrafficSimDeclParser.h>

#include "trafficsimmodellistener.hpp"

using namespace trafficsim;
using namespace dslparser;
using namespace utils;
using namespace antlr4;

class TrafficSimErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  TrafficSimErrorListener(DslErrorList* errors)
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
      DslError trafficsimError(QString::fromStdString(msg),
                               line,
                               charPositionInLine);
      if(offendingSymbol)
        trafficsimError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(trafficsimError);
    }

    return;
  }
};

class ComBuildTrafficSimModel::Private
{
  friend class ComBuildTrafficSimModel;

  QString             _trafficSimDocText;
  TrafficSimModel*  _TrafficSimDeclModel;
  bool                _strictErrorHandling;
  DslErrorList        _trafficsimErrors;
  TokenTextLocations  _keywordTextLocations;
  ModelTextLocations  _modelTextLocations;
  TrafficSimModelListener _trafficSimModelListener;

  Private(const QString& trafficSimDocText,
          TrafficSimModel* TrafficSimDeclModel,
          bool strictErrorHandling)
    : _trafficSimDocText(trafficSimDocText),
      _TrafficSimDeclModel(TrafficSimDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _trafficSimModelListener(this->_TrafficSimDeclModel,
                               &this->_trafficsimErrors,
                               &this->_keywordTextLocations,
                               &this->_modelTextLocations)
  {}
};

ComBuildTrafficSimModel::ComBuildTrafficSimModel(const QString& trafficSimDocText,
                                                 TrafficSimModel* TrafficSimDeclModel,
                                                 bool strictErrorHandling,
                                                 QObject* parent)
  : QObject(parent), _d(new Private(trafficSimDocText, TrafficSimDeclModel, strictErrorHandling))
{}

ComBuildTrafficSimModel::~ComBuildTrafficSimModel()
{
  delete  this->_d;
}

bool ComBuildTrafficSimModel::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_TrafficSimDeclModel);
  this->_d->_TrafficSimDeclModel->reset();

  //  qDebug() << "building sut model for doc-text: " << this->_d->_trafficSimDocText;

  ANTLRInputStream input(this->_d->_trafficSimDocText.toStdString());
  TrafficSimDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  TrafficSimDeclParser parser(&tokens);

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

  TrafficSimErrorListener myErrorListener(&this->_d->_trafficsimErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  TrafficSimDeclParser::TrafficSimulationContext* TrafficSimDeclCtx = nullptr;
  auto start = std::chrono::steady_clock::now();
  try
  {
    //parser.addParseListener(&this->_d->_trafficSimModelListener);
    TrafficSimDeclCtx = parser.trafficSimulation();
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

  if(TrafficSimDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_trafficSimModelListener, TrafficSimDeclCtx);

    //    qDebug()<<"Parse tree: " << tree->toStringTree(&parser).c_str();
  }

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_trafficsimErrors.count()){
    foreach (dslparser::DslError err, this->_d->_trafficsimErrors) {
      AddPtrString(errorString)<<err.message();
    }
    return false;
  }

  return true;
}

const dslparser::DslErrorList& ComBuildTrafficSimModel::errors() const
{
  return this->_d->_trafficsimErrors;
}

const dslparser::TokenTextLocations& ComBuildTrafficSimModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const dslparser::ModelTextLocations &ComBuildTrafficSimModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

TrafficSimModel* ComBuildTrafficSimModel::trafficsimDeclModel()
{
  return this->_d->_TrafficSimDeclModel;
}
