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

#include "combuildsutmodel.hpp"

#include <mobata/model/ts/ts.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "SutDeclLexer.h"
#include "SutDeclParser.h"

#include "sutmodellistener.hpp"

using namespace model::ts;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace sut {

class SutErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  SutErrorListener(DslErrorList* errors)
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
    qDebug()<<"SutErrorListener::syntaxError() executed!: "<<msg.c_str();

    if(this->_errors)
    {
      DslError sutError(QString::fromStdString(msg),
                        line,
                        charPositionInLine);
      if(offendingSymbol)
        sutError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(sutError);
    }

    return;
  }
};

class ComBuildSutModel::Private
{
  friend class ComBuildSutModel;

  QString             _sutDocText;
  model::ts::SutItem* _sutDeclModel;
  bool                _strictErrorHandling;
  DslErrorList        _sutErrors;
  TokenTextLocations  _keywordTextLocations;
  ModelTextLocations  _modelTextLocations;
  SutModelListener    _sutModelListener;

  Private(const QString& sutDocText,
          model::ts::SutItem* sutDeclModel,
          bool strictErrorHandling)
    : _sutDocText(sutDocText),
      _sutDeclModel(sutDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _sutModelListener(this->_sutDeclModel,
                        &this->_sutErrors,
                        &this->_keywordTextLocations,
                        &this->_modelTextLocations)
  {}
};

ComBuildSutModel::ComBuildSutModel(const QString& sutDocText,
                                   model::ts::SutItem* sutDeclModel,
                                   bool strictErrorHandling,
                                   QObject* parent)
  : QObject(parent), _d(new Private(sutDocText, sutDeclModel, strictErrorHandling))
{}

ComBuildSutModel::~ComBuildSutModel()
{
  delete  this->_d;
}

bool ComBuildSutModel::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_sutDeclModel);
  this->_d->_sutDeclModel->reset();
  this->_d->_sutDeclModel->initStandardDataTypes();

  //  qDebug() << "building sut model for doc-text: " << this->_d->_sutDocText;

  ANTLRInputStream input(this->_d->_sutDocText.toStdString());
  SutDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SutDeclParser parser(&tokens);

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

  SutErrorListener myErrorListener(&this->_d->_sutErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  SutDeclParser::SutDeclContext* sutDeclCtx = nullptr;
  //  auto start = std::chrono::steady_clock::now();
  try
  {
    //parser.addParseListener(&this->_d->_sutModelListener);
    sutDeclCtx = parser.sutDecl();
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
  if(sutDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_sutModelListener, sutDeclCtx);

    //    qDebug()<<"Parse tree: " << sutDeclCtx->toStringTree(&parser).c_str();
  }

  //  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  //  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_sutErrors.count()){
    for (DslError err: this->_d->_sutErrors) {
      AddPtrString(errorString)<<err.message();
    }
    return false;
  }

  return true;
}

const DslErrorList& ComBuildSutModel::errors() const
{
  return this->_d->_sutErrors;
}

const TokenTextLocations& ComBuildSutModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations &ComBuildSutModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

model::ts::SutItem* ComBuildSutModel::sutModel()
{
  return this->_d->_sutDeclModel;
}

} // namespace sut
} // namespace dslparser
