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

#include "combuildbasemodel.hpp"

#include <mobata/model/base/basemodel.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "CommonDeclLexer.h"
#include "CommonDeclParser.h"
#include "CommonDeclBaseListener.h"

#include "commonmodellistener.hpp"

using namespace model::base;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace common {

typedef CommonModelListener<CommonDeclBaseListener, CommonDeclParser,BaseModel> MyCommonListener;

class CommonErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  CommonErrorListener(DslErrorList* errors)
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
      DslError commonError(QString::fromStdString(msg),
                           line,
                           charPositionInLine);
      if(offendingSymbol)
        commonError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(commonError);
    }

    return;
  }
};

class ComBuildBaseModel::Private
{
  friend class ComBuildBaseModel;

  QString             _declText;
  BaseModel*          _baseDeclModel;
  bool                _strictErrorHandling;
  DslErrorList        _commonErrors;
  TokenTextLocations  _keywordTextLocations;
  ModelTextLocations  _modelTextLocations;
  MyCommonListener    _myCommonListener;

  Private(const QString& declText,
          BaseModel* baseModel,
          bool strictErrorHandling)
    : _declText(declText),
      _baseDeclModel(baseModel),
      _strictErrorHandling(strictErrorHandling),
      _myCommonListener(this->_baseDeclModel,
                        &this->_commonErrors,
                        &this->_keywordTextLocations,
                        &this->_modelTextLocations)
  {}
};

ComBuildBaseModel::ComBuildBaseModel(const QString& declText,
                                     BaseModel* baseDeclModel,
                                     bool strictErrorHandling,
                                     QObject* parent)
  : QObject(parent), _d(new Private(declText, baseDeclModel, strictErrorHandling))
{}

ComBuildBaseModel::~ComBuildBaseModel()
{
  delete  this->_d;
}

bool ComBuildBaseModel::execute(QString* errorString)
{
  Q_ASSERT(this->_d->_baseDeclModel);
  this->_d->_baseDeclModel->reset();
  this->_d->_baseDeclModel->initStandardDataTypes();

  //  qDebug() << "building base model for doc-text: " << this->_d->_declText;

  ANTLRInputStream input(this->_d->_declText.toStdString());
  CommonDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  CommonDeclParser parser(&tokens);

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

  CommonErrorListener myErrorListener(&this->_d->_commonErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  CommonDeclParser::CommonDeclContext* commonDeclCtx = 0;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    commonDeclCtx = parser.commonDecl();
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

  if(commonDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_myCommonListener, commonDeclCtx);

    //    qDebug()<<"Parse tree: " << tree->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_commonErrors.count())
    return false;

  return true;
}

const DslErrorList& ComBuildBaseModel::errors() const
{
  return this->_d->_commonErrors;
}

const TokenTextLocations& ComBuildBaseModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations& ComBuildBaseModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

BaseModel* ComBuildBaseModel::baseDeclModel()
{
  return this->_d->_baseDeclModel;
}

} // namespace common
} // namespace dslparser
