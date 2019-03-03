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

#include "combuildirdlmodel.hpp"

#include <mobata/model/irdl/requirementsmodel.hpp>
#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "IrdlLexer.h"
#include "IrdlParser.h"

#include "irdlmodellistener.hpp"

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
      DslError irdlError(QString::fromStdString(msg),
                                 line,
                                 charPositionInLine);
      if(offendingSymbol)
        irdlError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(irdlError);
    }

    return;
  }
};

class ComBuildIrdlModel::Private
{
  friend class ComBuildIrdlModel;

  QString                   _irdlDocText;
  RequirementsModel*        _irdlDeclModel;
  bool                      _strictErrorHandling;
  DslErrorList              _irdlErrors;
  TokenTextLocations        _keywordTextLocations;
  ModelTextLocations        _modelTextLocations;
  IrdlModelListener _irdlModelListener;

  Private(const QString& irdlDocText,
          RequirementsModel* irdlDeclModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _irdlDocText(irdlDocText),
      _irdlDeclModel(irdlDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _irdlModelListener(this->_irdlDeclModel,
                                 &this->_irdlErrors,
                                 prefix,
                                 &this->_keywordTextLocations,
                                 &this->_modelTextLocations)
  {}
};

ComBuildIrdlModel::ComBuildIrdlModel(const QString& irdlDocText,
                                                     RequirementsModel* irdlDeclModel,
                                                     const QString& prefix,
                                                     bool strictErrorHandling,
                                                     QObject* parent)
  : QObject(parent), _d(new Private(irdlDocText, irdlDeclModel, prefix, strictErrorHandling))
{}

ComBuildIrdlModel::~ComBuildIrdlModel()
{
  delete  this->_d;
}

bool ComBuildIrdlModel::execute(QString* errorString, bool deleteOldModel)
{
  //  qDebug()<<"ComBuildIrdlModel::execute()!";

  Q_ASSERT(this->_d->_irdlDeclModel);
  if(deleteOldModel)
  {
    this->_d->_irdlDeclModel->reset();
    this->_d->_irdlDeclModel->initStandardDataTypes();
    this->_d->_irdlDeclModel->removeDataType(QStringLiteral("string"));
  }
  ANTLRInputStream input(this->_d->_irdlDocText.toStdString());
  IrdlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  IrdlParser parser(&tokens);

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

  RequirementsErrorListener myErrorListener(&this->_d->_irdlErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  IrdlParser::IrdlDeclContext* irdlDeclCtx = 0;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    irdlDeclCtx = parser.irdlDecl();
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

  if(irdlDeclCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_irdlModelListener, irdlDeclCtx);

    //    qDebug()<<"Parse tree: " << tree->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_irdlErrors.count())
    return false;

  return true;
}

const DslErrorList& ComBuildIrdlModel::errors() const
{
  return this->_d->_irdlErrors;
}

const TokenTextLocations& ComBuildIrdlModel::keywordTextLocations() const
{
  return this->_d->_keywordTextLocations;
}

const ModelTextLocations& ComBuildIrdlModel::modelTextLocations() const
{
  return this->_d->_modelTextLocations;
}

RequirementsModel* ComBuildIrdlModel::irdlDeclModel()
{
    return this->_d->_irdlDeclModel;
}

QPair<model::base::ModelItem *, int> ComBuildIrdlModel::currentPathItem()
{
    return this->_d->_irdlModelListener.currentPathItem();
}

const model::base::SignalItem *ComBuildIrdlModel::currentSignalItem()
{
    return this->_d->_irdlModelListener.currentSignalItem();
}

const QHash<QString,const  model::msc::MscComponentItem *> &ComBuildIrdlModel::requirementCompItems()
{
    return this->_d->_irdlModelListener.requirementCompItems();
}

const ImportModelItem &ComBuildIrdlModel::importItems()
{
    return this->_d->_irdlModelListener.importItems();
}

const ImportModel &ComBuildIrdlModel::importModels()
{
  return this->_d->_irdlModelListener.importModels();
}

const QHash<QString, const model::msc::MscTimerItem *> ComBuildIrdlModel::timerItems()
{
  return this->_d->_irdlModelListener.timerItems();
}

} // namespace irdl
} // namespace dslparser
