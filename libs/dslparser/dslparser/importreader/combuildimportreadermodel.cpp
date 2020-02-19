#include "combuildimportreadermodel.hpp"

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#include <antlr4-runtime.h>

#include "ImportReaderLexer.h"
#include "ImportReaderParser.h"

#include "importreadermodellistener.hpp"

#include <mobata/memory_leak_start.hpp>

using namespace antlr4;

namespace dslparser {
namespace importreader{

class ComBuildImportReaderModel::Private
{
  friend class ComBuildImportReaderModel;

  QString                   _importreaderDocText;
  QHash<QString,QString>    _importedFiles;
  ImportReaderModelListener _importReaderModelListener;
  DslErrorList              _importErrors;

  Private(const QString& importreaderDocText,
          const QString& prefix)
    : _importreaderDocText(importreaderDocText),
      _importedFiles(),
      _importReaderModelListener(&_importedFiles,
                                 prefix,
                                 &_importErrors)
  {}
};

ComBuildImportReaderModel::ComBuildImportReaderModel(const QString& importreaderDocText,
                                                     const QString& prefix)
  : _d(new Private(importreaderDocText, prefix))
{}

ComBuildImportReaderModel::~ComBuildImportReaderModel()
{
  delete  this->_d;
}

bool ComBuildImportReaderModel::execute(QString* errorMessage)
{
  ANTLRInputStream input(this->_d->_importreaderDocText.toStdString());
  ImportReaderLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  ImportReaderParser parser(&tokens);

  parser.setBuildParseTree(true);
  parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);

  try
  {//dumpTokenStream
    tokens.fill();
  } catch (IllegalStateException &)
  {
    utils::AddPtrString(errorMessage)<<tr("Error: illegal parser state for import reader found! "
                                          "probably unfinished string?");
    return false;
  }


  ImportReaderParser::ImportReaderContext* importReaderCtx = 0;
//  auto start = std::chrono::steady_clock::now();
  try
  {
    importReaderCtx = parser.importReader();
  }
  catch (RecognitionException& re)
  {
    utils::AddPtrString(errorMessage)<<"Import Reader RecognitionException: "<<re.what()
                                       << "expected tokens: "
                                       <<re.getExpectedTokens().toString().c_str();
    return false;
  }
  catch (ParseCancellationException &pce)
  {
    utils::AddPtrString(errorMessage)<<"Import Reader ParseCancellationException: "<<pce.what();
    return false;
  }
  catch (std::exception& exc)
  {
    utils::AddPtrString(errorMessage)<<"Import Reader Exception: "<<exc.what();
    return false;
  }

  if(importReaderCtx)
  {
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&this->_d->_importReaderModelListener, importReaderCtx);

//    qDebug()<<"Parse tree: " << importReaderCtx->toStringTree(&parser).c_str();
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "Parse time: " << duration.count() / 1000.0 << " ms";

  if(this->_d->_importErrors.size())
    return false;

  return true;
}

const QHash<QString, QString>& ComBuildImportReaderModel::importedFiles()
{
  return this->_d->_importedFiles;
}

const DslErrorList& ComBuildImportReaderModel::errors() const
{
  return this->_d->_importErrors;
}
}
}
