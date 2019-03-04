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

#include "SutDeclBaseListener.h"
#include "../common/commonmodellistener.hpp"

#include <mobata/model/ts/sutitem.hpp>

#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace dslparser {
namespace sut {

class SutModelListener
    : public common::CommonModelListener< SutDeclBaseListener, SutDeclParser, model::ts::SutItem>
{
  typedef common::CommonModelListener<SutDeclBaseListener, SutDeclParser, model::ts::SutItem> BaseClass;

protected:
  enum SutModelListenerState
  {
    SutDeclState = UserListenerState +1,
    SutCompDeclState
  };

public:
  SutModelListener(model::ts::SutItem* sutDeclModel,
                   DslErrorList* dslErrors,
                   TokenTextLocations* keywordTextLocations = 0,
                   ModelTextLocations* modelTextLocations = 0);
  virtual ~SutModelListener();

protected:
  void enterSutDecl(SutDeclParser::SutDeclContext* ctx) override;
  void exitSutDecl(SutDeclParser::SutDeclContext *ctx) override;
  void enterNameDecl(SutDeclParser::NameDeclContext* ctx) override;
  void exitNameDecl(SutDeclParser::NameDeclContext *ctx) override;

  void enterPortDecl(SutDeclParser::PortDeclContext *ctx) override;
  void exitPortDecl(SutDeclParser::PortDeclContext *ctx) override;

  void enterSutCompDecl(SutDeclParser::SutCompDeclContext* ctx) override;
  void exitSutCompDecl(SutDeclParser::SutCompDeclContext* ctx) override;

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

private:
  class Private;
  Private* _d;
};

} // namespace sut
} // namespace dslparser
