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

#undef emit
#include <antlr4-runtime.h>

namespace dslparser {
namespace common {

template<class CtxType, typename KWFuntion, class KWLocations>
void addKeywordLocation(CtxType* ctx,
                        KWFuntion kwFunction,
                        KWLocations* keywordTextLocations,
                        int keywordType)
{
  Q_ASSERT(ctx);

  if(!keywordTextLocations)
    return;

  antlr4::tree::TerminalNode* keywordNode = (ctx->*kwFunction)();
  if(!keywordNode)
    return;
  antlr4::Token* keywordToken = keywordNode->getSymbol();
  Q_ASSERT(keywordToken);

  keywordTextLocations->append(TokenTextLocation(keywordToken->getStartIndex(),
                                                 keywordToken->getStopIndex(),
                                                 keywordType));

  return;
}

template<class KWLocations>
void addSimpleKeywordLocation(antlr4::tree::TerminalNode* keywordNode,
                        KWLocations* keywordTextLocations,
                        int keywordType)
{
  if(!keywordTextLocations)
    return;
  if(!keywordNode)
    return;
  antlr4::Token* keywordToken = keywordNode->getSymbol();
  Q_ASSERT(keywordToken);

  keywordTextLocations->append(TokenTextLocation(keywordToken->getStartIndex(),
                                                 keywordToken->getStopIndex(),
                                                 keywordType));

  return;
}

} // namespace common
} // namespace dslparser

#define emit Q_EMIT
