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

#include "combuildstatemachinemodel.hpp"

#include <mobata/model/statemachine/statemachinemodel.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "StateMachineLexer.h"
#include "StateMachineParser.h"

#include "statemachinemodellistener.hpp"

using namespace model::statemachine;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace statemachine {

class StateMachineErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  StateMachineErrorListener(DslErrorList* errors)
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
//    qDebug()<<"StateMachineErrorListener::syntaxError() executed!";

    if(this->_errors)
    {
      DslError statemachineError(QString::fromStdString(msg),
                                 line,
                                 charPositionInLine);
      if(offendingSymbol)
        statemachineError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(statemachineError);
    }

    return;
  }
};

class ComBuildStateMachineModel::Private
{
  friend class ComBuildStateMachineModel;

  QString                   _statemachineDocText;
  StateMachineModel*        _statemachineDeclModel;
  bool                      _strictErrorHandling;
  DslErrorList              _statemachineErrors;
  TokenTextLocations        _keywordTextLocations;
  ModelTextLocations        _modelTextLocations;
  StateMachineModelListener _statemachineModelListener;

  Private(const QString& statemachineDocText,
          StateMachineModel* statemachineDeclModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _statemachineDocText(statemachineDocText),
      _statemachineDeclModel(statemachineDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _statemachineModelListener(this->_statemachineDeclModel,
                                 &this->_statemachineErrors,
                                 prefix,
                                 &this->_keywordTextLocations,
                                 &this->_modelTextLocations)
  {}
};

ComBuildStateMachineModel::ComBuildStateMachineModel(const QString& statemachineDocText,
                                                     StateMachineModel* statemachineDeclModel,
                                                     const QString& prefix,
                                                     bool strictErrorHandling,
                                                     QObject* parent)
  : QObject(parent), _d(new Private(statemachineDocText, statemachineDeclModel, prefix, strictErrorHandling))
{}

ComBuildStateMachineModel::~ComBuildStateMachineModel()
{
  delete  this->_d;
}

bool ComBuildStateMachineModel::execute(QString* errorString)
{
  //  qDebug()<<"ComBuildStateMachineModel::execute()!";

  Q_ASSERT(this->_d->_statemachineDeclModel);
  this->_d->_statemachineDeclModel->reset();
  this->_d->_statemachineDeclModel->initStandardDataTypes();
  this->_d->_statemachineDeclModel->removeDataType(QStringLiteral("string"));

  ANTLRInputStream input(this->_d->_statemachineDocText.toStdString());
  StateMachineLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  StateMachineParser parser(&tokens);

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

  StateMachineErrorListener myErrorListener(&this->_d->_statemachineErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  StateMachineParser::StateMachineDeclContext* statemachineDeclCtx = 0;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    statemachineDeclCtx = parser.stateMachineDecl();
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

  if(statemachineDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_statemachineModelListener, statemachineDeclCtx);

    //    qDebug()<<"Parse tree: " << tree->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_statemachineErrors.count())
    return false;

  return true;
}

const DslErrorList& ComBuildStateMachineModel::errors() const
{
  return this->_d->_statemachineErrors;
}

const TokenTextLocations& ComBuildStateMachineModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations& ComBuildStateMachineModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

StateMachineModel* ComBuildStateMachineModel::statemachineDeclModel()
{
  return this->_d->_statemachineDeclModel;
}

AbstractStateItem *ComBuildStateMachineModel::currentStatePathItem()
{
  return  _d->_statemachineModelListener.currentStatePathItem();
}

const SignalItem *ComBuildStateMachineModel::currentSignalItem()
{
  return  _d->_statemachineModelListener.currentSignalItem();
}

} // namespace statemachine
} // namespace dslparser
