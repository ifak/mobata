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

#include "combuildirdldeclmodel.hpp"

#include <mobata/model/irdl/requirementsmodel.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "IrdlCommonDeclLexer.h"
#include "IrdlCommonDeclParser.h"

#include "irdldeclmodellistener.hpp"

using namespace model::irdl;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace irdl {

class RequirementsErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  RequirementsErrorListener(DslErrorList* errors)
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
    qDebug()<<"RequirementsErrorListener::syntaxError() executed!";

    if(this->_errors)
    {
      DslError irdldeclError(QString::fromStdString(msg),
                                 line,
                                 charPositionInLine);
      if(offendingSymbol)
        irdldeclError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(irdldeclError);
    }

    return;
  }
};

class ComBuildIrdlDeclModel::Private
{
  friend class ComBuildIrdlDeclModel;

  QString                   _irdldeclDocText;
  RequirementsModel*        _IrdlCommonDeclModel;
  bool                      _strictErrorHandling;
  DslErrorList              _irdldeclErrors;
  TokenTextLocations        _keywordTextLocations;
  ModelTextLocations        _modelTextLocations;
  IrdlDeclModelListener _IrdlDeclModelListener;

  Private(const QString& irdldeclDocText,
          RequirementsModel* IrdlCommonDeclModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _irdldeclDocText(irdldeclDocText),
      _IrdlCommonDeclModel(IrdlCommonDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _IrdlDeclModelListener(this->_IrdlCommonDeclModel,
                                 &this->_irdldeclErrors,
                                 prefix,
                                 &this->_keywordTextLocations,
                                 &this->_modelTextLocations)
  {}
};

ComBuildIrdlDeclModel::ComBuildIrdlDeclModel(const QString& irdldeclDocText,
                                                     RequirementsModel* IrdlCommonDeclModel,
                                                     const QString& prefix,
                                                     bool strictErrorHandling,
                                                     QObject* parent)
  : QObject(parent), _d(new Private(irdldeclDocText, IrdlCommonDeclModel, prefix, strictErrorHandling))
{}

ComBuildIrdlDeclModel::~ComBuildIrdlDeclModel()
{
  delete  this->_d;
}

bool ComBuildIrdlDeclModel::execute(QString* errorString)
{
  //  qDebug()<<"ComBuildIrdlDeclModel::execute()!";

  Q_ASSERT(this->_d->_IrdlCommonDeclModel);
  this->_d->_IrdlCommonDeclModel->reset();
  this->_d->_IrdlCommonDeclModel->initStandardDataTypes();
  this->_d->_IrdlCommonDeclModel->removeDataType(QStringLiteral("string"));

  ANTLRInputStream input(this->_d->_irdldeclDocText.toStdString());
  IrdlCommonDeclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  IrdlCommonDeclParser parser(&tokens);

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

  RequirementsErrorListener myErrorListener(&this->_d->_irdldeclErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  IrdlCommonDeclParser::IrdlCommonDeclContext* IrdlCommonDeclCtx = 0;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    IrdlCommonDeclCtx = parser.irdlCommonDecl();
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

  if(IrdlCommonDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_IrdlDeclModelListener, IrdlCommonDeclCtx);

    //    qDebug()<<"Parse tree: " << tree->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_irdldeclErrors.count())
    return false;

  return true;
}

const DslErrorList& ComBuildIrdlDeclModel::errors() const
{
  return this->_d->_irdldeclErrors;
}

const TokenTextLocations& ComBuildIrdlDeclModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations& ComBuildIrdlDeclModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

RequirementsModel* ComBuildIrdlDeclModel::IrdlCommonDeclModel()
{
    return this->_d->_IrdlCommonDeclModel;
}

QPair<model::base::ModelItem *, int> ComBuildIrdlDeclModel::currentPathItem()
{
    return this->_d->_IrdlDeclModelListener.currentPathItem();
}

model::base::ModelItem *ComBuildIrdlDeclModel::currentSignalItem()
{
    return this->_d->_IrdlDeclModelListener.currentSignalItem();
}

const QHash<QString, model::msc::MscComponentItem *> &ComBuildIrdlDeclModel::requirementCompItems()
{
    return this->_d->_IrdlDeclModelListener.requirementCompItems();
}

const ImportModelItem &ComBuildIrdlDeclModel::importItems()
{
    return this->_d->_IrdlDeclModelListener.importItems();
}

const ImportModel &ComBuildIrdlDeclModel::importModels()
{
    return this->_d->_IrdlDeclModelListener.importModels();
}

} // namespace irdldecl
} // namespace dslparser
