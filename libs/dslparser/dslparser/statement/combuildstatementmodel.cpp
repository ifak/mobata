#include "combuildstatementmodel.hpp"

#include <mobata/model/base/statements/statementmodel.hpp>
#include <mobata/model/base/statements/rootstatementmodel.hpp>
#include <mobata/model/base/statements/attributeassignstatementmodel.hpp>
#include <mobata/model/base/statements/conditionstatementmodel.hpp>
#include <mobata/model/base/statements/functioncallstatementmodel.hpp>
#include <mobata/model/base/statements/sendtostatementmodel.hpp>
#include <mobata/model/base/statements/statementmodel.hpp>
#include <mobata/model/base/statements/switchstatementmodel.hpp>

#include <mobata/utils/functors.hpp>

#include "../dslerror.hpp"

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "dslparser/common/CommonDeclLexer.h"
#include "dslparser/common/CommonDeclParser.h"

#include "statementmodellistener.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace model::base::statement;
using namespace utils;
using namespace antlr4;

namespace dslparser {
namespace base {

class StatementErrorListener : public BaseErrorListener
{
  DslErrorList*  _errors;

public:
  StatementErrorListener(DslErrorList* errors)
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
    qDebug()<<"StatementErrorListener::syntaxError() executed!";

    if(this->_errors)
    {
      DslError statementError(QString::fromStdString(msg),
                              line,
                              charPositionInLine);
      if(offendingSymbol)
        statementError.setOffendingText(offendingSymbol->getText().c_str());
      this->_errors->append(statementError);
    }

    return;
  }
};

class ComBuildStatementModel::Private
{
  friend class ComBuildStatementModel;

  QString                 _statementDocText;
  RootStatementModel*     _statementDeclModel;
  bool                    _strictErrorHandling;
  DslErrorList            _statementErrors;
  StatementModelListener  _statementModelListener;

  Private(const QString& statementDocText,
          const model::statemachine::StateMachineModel *wholeModel,
          RootStatementModel* statementDeclModel,
          const QString& prefix,
          bool strictErrorHandling)
    : _statementDocText(statementDocText),
      _statementDeclModel(statementDeclModel),
      _strictErrorHandling(strictErrorHandling),
      _statementModelListener(this->_statementDeclModel,
                              &this->_statementErrors,
                              wholeModel,
                              prefix)
  {}
}; 

ComBuildStatementModel::ComBuildStatementModel(const QString& statementDocText,
                                               const model::statemachine::StateMachineModel *wholeModel,
                                               RootStatementModel* statementDeclModel,
                                               const QString& prefix,
                                               bool strictErrorHandling,
                                               QObject* parent)
  : QObject(parent), _d(new Private(statementDocText, wholeModel, statementDeclModel, prefix, strictErrorHandling))
{}

ComBuildStatementModel::~ComBuildStatementModel()
{
  delete  this->_d;
}

bool ComBuildStatementModel::execute(QString* errorString)
{
  //  qDebug()<<"ComBuildStatementModel::execute()!";

  Q_ASSERT(this->_d->_statementDeclModel);

  ANTLRInputStream input(this->_d->_statementDocText.toStdString());
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

  StatementErrorListener myErrorListener(&this->_d->_statementErrors);
  parser.removeErrorListeners();
  parser.addErrorListener(&myErrorListener);

  CommonDeclParser::StatementDeclContext* statementDeclCtx = nullptr;
  //  auto start = std::chrono::steady_clock::now();
  try
  {
    statementDeclCtx = parser.statementDecl();
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

  if(statementDeclCtx)
  {
    _d->_statementModelListener.setTokenStream(&tokens);
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_statementModelListener, statementDeclCtx);

    //    qDebug()<<"Parse tree: " << tree->toStringTree(&parser).c_str();
  }

  //  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
  //  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_strictErrorHandling
     && this->_d->_statementErrors.count())
    return false;

  return true;
}

const DslErrorList& ComBuildStatementModel::errors() const
{
  return this->_d->_statementErrors;
}

StatementModel* ComBuildStatementModel::statementDeclModel()
{
  return this->_d->_statementDeclModel;
}

} // namespace base
} // namespace dslparser
