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

#include "combuildspenatmodel.hpp"

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "SpenatLexer.h"
#include "SpenatParser.h"

#include "spenatmodellistener.hpp"

using namespace model::spenat;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace spenat {

class SpenatErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  SpenatErrorListener(DslErrorList* errors)
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
//    qDebug()<<"SpenatErrorListener::syntaxError() executed!: "<<msg.c_str();

    if(this->_errors)
    {
      DslError spenatError(QString::fromStdString(msg),
                           line,
                           charPositionInLine);
      if(offendingSymbol)
        spenatError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(spenatError);
    }

    return;
  }
};

class ComBuildSpenatModel::Private
{
  friend class ComBuildSpenatModel;

  QString             _spenatDocText;
  SpenatDeclModel*          _spenatDeclModel;
  bool                _strictErrorHandling;
  DslErrorList        _spenatErrors;
  TokenTextLocations  _keywordTextLocations;
  ModelTextLocations  _modelTextLocations;
  SpenatModelListener _spenatModelListener;

  Private(const QString& spenatDocText,
          SpenatDeclModel* spenatDeclModel,
          bool strictErrorHandling)
    : _spenatDocText(spenatDocText),
      _spenatDeclModel(spenatDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _spenatModelListener(this->_spenatDeclModel,
                           &this->_spenatErrors,
                           &this->_keywordTextLocations,
                           &this->_modelTextLocations)
  {}
};

ComBuildSpenatModel::ComBuildSpenatModel(const QString& spenatDocText,
                                         SpenatDeclModel* spenatDeclModel,
                                         bool strictErrorHandling,
                                         QObject* parent)
  : QObject(parent), _d(new Private(spenatDocText, spenatDeclModel, strictErrorHandling))
{}

ComBuildSpenatModel::~ComBuildSpenatModel()
{
  delete  this->_d;
}

bool ComBuildSpenatModel::execute(QString* errorString)
{
//  qDebug()<<"ComBuildSpenatModel::execute()!";

  Q_ASSERT(this->_d->_spenatDeclModel);
  this->_d->_spenatDeclModel->reset();
  this->_d->_spenatDeclModel->initStandardDataTypes();
  this->_d->_spenatDeclModel->removeDataType(QStringLiteral("string"));

  ANTLRInputStream input(this->_d->_spenatDocText.toStdString());
  SpenatLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SpenatParser parser(&tokens);

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

  SpenatErrorListener myErrorListener(&this->_d->_spenatErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  SpenatParser::SpenatDeclContext* spenatDeclCtx = 0;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    spenatDeclCtx = parser.spenatDecl();
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

  if(spenatDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_spenatModelListener, spenatDeclCtx);

    //    qDebug()<<"Parse tree: " << tree->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_spenatErrors.count())
    return false;

  return true;
}

const DslErrorList& ComBuildSpenatModel::errors() const
{
  return this->_d->_spenatErrors;
}

const TokenTextLocations& ComBuildSpenatModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations& ComBuildSpenatModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

SpenatDeclModel* ComBuildSpenatModel::spenatDeclModel()
{
  return this->_d->_spenatDeclModel;
}

} // namespace spenat
} // namespace dslparser
