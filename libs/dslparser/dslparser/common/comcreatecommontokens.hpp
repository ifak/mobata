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

#include "../dslparser_global.hpp"
#include "../dslparser_types.hpp"

#include <QObject>

namespace dslparser {
namespace common {

class DSLPARSERSHARED_EXPORT ComCreateCommonTokens
    : public QObject
{
public:
  ComCreateCommonTokens(const QString& text,
                        QObject* parent = 0);
  virtual ~ComCreateCommonTokens();

public:
  bool execute(QString* errorString = 0);

  bool execute(const bool withWS,
               QString* errorString = 0);

public:
  const TokenTextLocations& commonTokenList() const;

private:
  Q_DISABLE_COPY(ComCreateCommonTokens)
  class Private;
  Private* _d;
};

} // namespace common
} // namespace dslparser
