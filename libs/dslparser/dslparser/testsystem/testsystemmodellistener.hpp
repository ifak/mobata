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

#include "TestSystemDeclBaseListener.h"
#include "../common/commonmodellistener.hpp"

#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace model{
namespace base {
class ModelItem;
}
}

namespace model{
namespace ts{
class TestSystemItem;
}}

namespace dslparser {
namespace testsystem {

typedef QHash<QString, model::base::ModelItem*> ImportedModelItems;

class TestSystemModelListener
    : public common::CommonModelListener< TestSystemDeclBaseListener, TestSystemDeclParser, model::ts::TestSystemItem>
{
  typedef common::CommonModelListener<TestSystemDeclBaseListener, TestSystemDeclParser, model::ts::TestSystemItem> BaseClass;

protected:
  enum TestSystemModelListenerState
  {
    TestSystemDeclState = UserListenerState +1,
    TestCompDeclState
  };

public:
  TestSystemModelListener(model::ts::TestSystemItem* testsystemDeclModel,
                          DslErrorList* dslErrors,
                          QString* importedSutFile,
                          const QString& praefix = QStringLiteral(""),
                          TokenTextLocations* keywordTextLocations = 0,
                          ModelTextLocations* modelTextLocations = 0);
  virtual ~TestSystemModelListener();

public:
  const ImportedModelItems&  importedModelItems() const;

protected:
  void enterTestSystemDecl(TestSystemDeclParser::TestSystemDeclContext* ctx) override;
  void exitTestSystemDecl(TestSystemDeclParser::TestSystemDeclContext *ctx) override;

  void enterNameDecl(TestSystemDeclParser::NameDeclContext* ctx) override;
  void exitNameDecl(TestSystemDeclParser::NameDeclContext *ctx) override;

  void exitEnabledDecl(TestSystemDeclParser::EnabledDeclContext *ctx) override;

  void enterPortDecl(TestSystemDeclParser::PortDeclContext *ctx) override;
  void exitPortDecl(TestSystemDeclParser::PortDeclContext *ctx) override;

  void exitImportPathBody(TestSystemDeclParser::ImportPathBodyContext *ctx) override;

  void enterTestCompDecl(TestSystemDeclParser::TestCompDeclContext* ctx) override;
  void exitTestCompDecl(TestSystemDeclParser::TestCompDeclContext* ctx) override;

  void enterLinkDecl(TestSystemDeclParser::LinkDeclContext* ctx) override;
  void exitLinkDecl(TestSystemDeclParser::LinkDeclContext* ctx) override;

  void enterSourceDecl(TestSystemDeclParser::SourceDeclContext* ctx) override;
  void exitSourceDecl(TestSystemDeclParser::SourceDeclContext* ctx) override;

  void enterTargetDecl(TestSystemDeclParser::TargetDeclContext* ctx) override;
  void exitTargetDecl(TestSystemDeclParser::TargetDeclContext* ctx) override;

  void enterLabelDecl(TestSystemDeclParser::LabelDeclContext* ctx) override;
  void exitLabelDecl(TestSystemDeclParser::LabelDeclContext* ctx) override;

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

private:
  class Private;
  Private* _d;
};

} // namespace testsystem
} // namespace dslparser
