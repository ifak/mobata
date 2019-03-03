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

#pragma once

#include "dslparser_global.hpp"

#include <QString>

namespace dslparser {

class DSLPARSERSHARED_EXPORT DslError
{
public:
  enum ParserErrorType
  {
    SyntaxError,
    AmbiguityError,
    ContextError,
    SensitivityError,
    FileError,
    UnknownError
  };

public:
  DslError(const QString& message,
           const int line = 0,
           const int charPositionInLine = 0,
           const QString& offendingText = QStringLiteral(""),
           ParserErrorType errorType = SyntaxError)
    : _message(message),
      _line(line),
      _charPositionInLine(charPositionInLine),
      _offendingText(offendingText),
      _errorType(errorType)
  {}

public:
  const QString& message() const
  {
    return this->_message;
  }
  void setMessage(const QString& message)
  {
    this->_message=message;

    return;
  }

  int line() const
  {
    return this->_line;
  }
  void setLine(const int line)
  {
    this->_line=line;

    return;
  }

  int charPositionInLine() const
  {
    return this->_charPositionInLine;
  }
  void setCharPositionInLine(const int charPositionInLine)
  {
    this->_charPositionInLine=charPositionInLine;

    return;
  }

  const QString& offendingText() const
  {
    return this->_offendingText;
  }
  void setOffendingText(const QString& offendingText)
  {
    this->_offendingText=offendingText;

    return;
  }

  ParserErrorType errorType() const
  {
    return this->_errorType;
  }
  void setErrorType(const ParserErrorType errorType)
  {
    this->_errorType = errorType;

    return;
  }

private:
  QString         _message;
  int             _line;
  int             _charPositionInLine;
  QString         _offendingText;
  ParserErrorType _errorType;
};

typedef QList<DslError>  DslErrorList;
} // namespace dslparser
