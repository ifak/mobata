#include "comcreatecommontokens.hpp"

#include <mobata/utils/functors.hpp>

#include <QDebug>

#undef emit
#undef SIGNAL

#include <antlr4/antlr4-runtime.h>

#include "CommonLexer.h"

#include <mobata/memory_leak_start.hpp>

namespace dslparser {
namespace common {

using namespace antlr4;

class ComCreateCommonTokens::Private
{
  friend class ComCreateCommonTokens;

  QString             _text;
  TokenTextLocations  _commonTokenList;

  Private(const QString& text)
    : _text(text)
  {}
};

ComCreateCommonTokens::ComCreateCommonTokens(const QString& text,
                                             QObject* parent)
  : QObject(parent), _d(new Private(text))
{}

ComCreateCommonTokens::~ComCreateCommonTokens()
{
  delete this->_d;
}

bool ComCreateCommonTokens::execute(QString* errorString)
{
  return this->execute(false, errorString);
}

bool ComCreateCommonTokens::execute(const bool withWS,
                                    QString* errorString)
{
  Q_UNUSED(errorString);
  //  qDebug() << "creating tokens for text: " << this->_d->_text;

//  auto start = std::chrono::steady_clock::now();

  ANTLRInputStream input(this->_d->_text.toStdString());
  CommonLexer lexer(&input);

  typedef std::unique_ptr<Token>  TokenPtr;
  for(const TokenPtr& token : lexer.getAllTokens())
  {
    if(!withWS)
    {
      int tokenType = token->getType();
      if((tokenType == CommonLexer::NEWLINE)
         || (tokenType == CommonLexer::WS))
        continue;
    }

    this->_d->_commonTokenList.append(TokenTextLocation(token->getStartIndex(),
                                                        token->getStopIndex(),
                                                        commonTokenType<CommonLexer>(token->getType())));
  }

//  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
//  qDebug() << "creating tokens time: " << duration.count() / 1000.0 << " ms";

  return true;
}

const TokenTextLocations& ComCreateCommonTokens::commonTokenList() const
{
  return this->_d->_commonTokenList;
}

} // namespace common
} // namespace dslparser
