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

#include "combuildsimsystemmodel.hpp"

#include "simsystemitem.hpp"
#include <mobata/utils/functors.hpp>

#include <dslparser/dslerror.hpp>

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include <dslparser/simsystem/SimSystemDeclLexer.h>
#include <dslparser/simsystem/SimSystemDeclParser.h>

#include "simsystemitem.hpp"
#include "simsystemmodel.hpp"
#include "simsystemmodellistener.hpp"

using namespace utils;
using namespace antlr4;
using namespace dslparser;

namespace modsim {

class SimSystemErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  SimSystemErrorListener(DslErrorList* errors)
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
    qDebug()<<"SimSystemErrorListener::syntaxError() executed!: "<<msg.c_str();

    if(this->_errors)
    {
      DslError simsystemError(QString::fromStdString(msg),
                              line,
                              charPositionInLine);
      if(offendingSymbol)
        simsystemError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(simsystemError);
    }

    return;
  }
};

class ComBuildSimSystemModel::Private
{
  friend class ComBuildSimSystemModel;

  QString                 _simsystemDocText;
  SimSystemItem*          _simsystemDeclModel;
  bool                    _strictErrorHandling;
  DslErrorList            _simsystemErrors;
  TokenTextLocations      _keywordTextLocations;
  ModelTextLocations      _modelTextLocations;
  SimSystemModelListener  _simsystemModelListener;

  Private(const QString& simsystemDocText,
          SimSystemItem* simsystemDeclModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _simsystemDocText(simsystemDocText),
      _simsystemDeclModel(simsystemDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _simsystemModelListener(this->_simsystemDeclModel,
                              &this->_simsystemErrors,
                              prefix,
                              &this->_keywordTextLocations,
                              &this->_modelTextLocations)
  {}
};

ComBuildSimSystemModel::ComBuildSimSystemModel(const QString& simsystemDocText,
                                               SimSystemItem* simsystemDeclModel,
                                               const QString& prefix,
                                               bool strictErrorHandling,
                                               QObject* parent)
  : QObject(parent), _d(new Private(simsystemDocText, simsystemDeclModel,
                                    prefix, strictErrorHandling))
{}

ComBuildSimSystemModel::~ComBuildSimSystemModel()
{
  delete  this->_d;
}

bool ComBuildSimSystemModel::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_simsystemDeclModel);

  //  qDebug() << "building simsystem model for doc-text: " << this->_d->_simsystemDocText;

  ANTLRInputStream input(this->_d->_simsystemDocText.toStdString());
  SimSystemDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SimSystemDeclParser parser(&tokens);

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

  SimSystemErrorListener myErrorListener(&this->_d->_simsystemErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  SimSystemDeclParser::SimSystemDeclContext* simsystemDeclCtx = 0;
  //  auto start = std::chrono::steady_clock::now();
  try
  {
    //parser.addParseListener(&this->_d->_simsystemModelListener);
    simsystemDeclCtx = parser.simSystemDecl();
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
  if(simsystemDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_simsystemModelListener, simsystemDeclCtx);

    //    qDebug()<<"Parse tree: " << simsystemDeclCtx->toStringTree(&parser).c_str();
  }

  //  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  //  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_simsystemErrors.count()){
    for (DslError err: this->_d->_simsystemErrors) {
      AddPtrString(errorString)<<err.message();
    }
    return false;
  }

  return true;
}

const DslErrorList& ComBuildSimSystemModel::errors() const
{
  return this->_d->_simsystemErrors;
}

const TokenTextLocations& ComBuildSimSystemModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations &ComBuildSimSystemModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

const ImportSpenatModelList& ComBuildSimSystemModel::importedSpenatModels() const
{
  return _d->_simsystemModelListener.importedSpenatModels();
}

const ImportStatemachineModelList& ComBuildSimSystemModel::importedStatemachineModels() const
{
  return _d->_simsystemModelListener.importedStatemachineModels();
}

} // namespace modsim
