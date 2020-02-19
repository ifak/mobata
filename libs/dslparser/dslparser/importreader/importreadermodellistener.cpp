#include "importreadermodellistener.hpp"
#include "ImportReaderLexer.h"

#include <QStack>
#include <QDebug>
#include <QFileInfo>

#include <mobata/memory_leak_start.hpp>

using namespace antlr4;

namespace dslparser {
namespace importreader {

class ImportReaderModelListener::Private
{
  friend class ImportReaderModelListener;

  ///parse data////
  QString                   _praefix;
  QHash<QString, QString>*  _importMap;
  DslErrorList*             _importErrors;

  Private(const QString& prefix,
          QHash<QString, QString>* importMap,
          DslErrorList* importErrors)
    : _praefix(prefix),
      _importMap(importMap),
      _importErrors(importErrors)
  {}
};

ImportReaderModelListener::ImportReaderModelListener(QHash<QString, QString> *importMap,
                                                     const QString& prefix,
                                                     DslErrorList* importErrors)
  : _d(new Private(prefix.trimmed(),importMap, importErrors))
{
  if(!this->_d->_praefix.isEmpty()
     && this->_d->_praefix.at(this->_d->_praefix.size()-1)!=QStringLiteral("/"))
    this->_d->_praefix.append(QStringLiteral("/"));
}

ImportReaderModelListener::ImportReaderModelListener(QHash<QString, QString>* importMap,
                                                     DslErrorList* importErrors)
  : _d(new Private(QStringLiteral(""),importMap, importErrors))
{}

ImportReaderModelListener::~ImportReaderModelListener()
{
  delete this->_d;
}

void ImportReaderModelListener::exitImportPathBody(ImportReaderParser::ImportPathBodyContext *ctx)
{
  Q_ASSERT(ctx);
  if(ctx->exception || !ctx->importFileBody())
    return;

  qDebug()<<"ImportReaderModelListener::exitImportPathDecl with importPathBody: "
         <<ctx->importFileBody()->getText().c_str();
  qDebug()<<"line: "<<ctx->start->getLine();

  QString importFilePath = QString::fromStdString(ctx->importFileBody()->getText());
  importFilePath = _d->_praefix + importFilePath;
  importFilePath = QFileInfo(importFilePath).canonicalFilePath();
  if(importFilePath.isEmpty())
  {
    if(this->_d->_importErrors)
    {
      DslError importError(QObject::tr("import file '%1' is not available!").arg(importFilePath));
      importError.setLine(ctx->importFileBody()->start->getLine());
      importError.setCharPositionInLine(ctx->importFileBody()->start->getCharPositionInLine());
      importError.setErrorType(DslError::FileError);

      this->_d->_importErrors->append(importError);
    }
    else
      qWarning()<<"import file '"<<importFilePath<<"' is not available!";

    return;
  }

  QString importAsKey;

  if(ctx->importAs() && ctx->importAs()->contextID())
  {
    importAsKey = QString::fromStdString(ctx->importAs()->contextID()->getText());
    if(this->_d->_importMap->contains(importAsKey))
    {
      Token* contextIdToken = ctx->importAs()->contextID()->getStart();
      Q_ASSERT(contextIdToken);

      if(this->_d->_importErrors)
      {
        DslError importError(QObject::tr("there is already a file imported for namespace '%1'! "
                                         "only one import file for a namespace is allowed!").arg(importAsKey));
        importError.setLine(ctx->importAs()->start->getLine());
        importError.setCharPositionInLine(contextIdToken->getCharPositionInLine());
        importError.setErrorType(DslError::SyntaxError);

        this->_d->_importErrors->append(importError);
      }
      else
        qWarning()<<"no namespace for imported file '"<<importFilePath<<"' available!";

      return;
    }
    else
      this->_d->_importMap->insert(importAsKey, importFilePath);
  }
  else
  {
    if(this->_d->_importErrors)
    {
      DslError importError(QObject::tr("no namespace for imported file '%1' available!").arg(importFilePath));
      importError.setLine(ctx->start->getLine());
      importError.setCharPositionInLine(ctx->start->getCharPositionInLine());
      importError.setErrorType(DslError::SyntaxError);

      this->_d->_importErrors->append(importError);
    }
    else
      qWarning()<<"no namespace for imported file '"<<importFilePath<<"' available!";
  }

  return;
}

} // namespace importreader
} // namespace dslparser
