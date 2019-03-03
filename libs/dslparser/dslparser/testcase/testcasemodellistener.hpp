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

#include "TestCaseDeclBaseListener.h"
#include "../common/commonmodellistener.hpp"

#include <mobata/model/ts/testcaseitem.hpp>
#include <mobata/model/ts/testcomponentitem.hpp>
#include <mobata/model/ts/testsuite.hpp>

#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

#include <QPair>

namespace model{
namespace base {
class AttributeItem;
class ModelItem;
}
}

namespace dslparser {
namespace testcase {

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;

class TestCaseModelListener
    : public common::CommonModelListener< TestCaseDeclBaseListener, TestCaseDeclParser, model::ts::TestCaseItem>
{
  typedef common::CommonModelListener<TestCaseDeclBaseListener, TestCaseDeclParser, model::ts::TestCaseItem> BaseClass;

protected:
  enum TestCaseModelListenerState
  {
    TestCaseDeclState = UserListenerState +1,
    TestCompDeclState
  };

public:
  TestCaseModelListener(model::ts::TestCaseItem* testCaseDeclModel,
                        DslErrorList* dslErrors,
                        QString* importedSutFileName,
                        QString* importedTestSystemFileName,
                        const QString& praefix = QStringLiteral(""),
                        TokenTextLocations* keywordTextLocations = 0,
                        ModelTextLocations* modelTextLocations = 0);
  virtual ~TestCaseModelListener();

public:
  QPair<model::base::ModelItem*,int>            currentPathItem();
  model::base::ModelItem*                       currentSignalItem();
  const QHash<QString,model::base::ModelItem*>& testCaseItems();
  const ImportModelItem&                        importItems();

protected:
  void enterTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext* ctx) override;
  void exitTestCaseDecl(TestCaseDeclParser::TestCaseDeclContext *ctx) override;
  void enterTestCaseBody(TestCaseDeclParser::TestCaseBodyContext *ctx) override;
  void enterDeclarations(TestCaseDeclParser::DeclarationsContext *ctx) override;
  void exitDeclarations(TestCaseDeclParser::DeclarationsContext *ctx) override;
  void enterNameDecl(TestCaseDeclParser::NameDeclContext* ctx) override;
  void exitNameDecl(TestCaseDeclParser::NameDeclContext *ctx) override;
  void enterEnabledDecl(TestCaseDeclParser::EnabledDeclContext *ctx) override;
  void exitEnabledDecl(TestCaseDeclParser::EnabledDeclContext *ctx) override;
  void enterImportPathBody(TestCaseDeclParser::ImportPathBodyContext *ctx) override;
  void exitImportPathBody(TestCaseDeclParser::ImportPathBodyContext *ctx) override;
  void exitAliasDef(TestCaseDeclParser::AliasDefContext *ctx) override;
  void exitAltDecl(TestCaseDeclParser::AltDeclContext *ctx) override;
  void enterAltBody(TestCaseDeclParser::AltBodyContext *ctx) override;
  void exitAltBody(TestCaseDeclParser::AltBodyContext *ctx) override;
  void enterAltDecl(TestCaseDeclParser::AltDeclContext *ctx) override;
  void exitTimerDecl(TestCaseDeclParser::TimerDeclContext *ctx) override;
  void exitMessageDecl(TestCaseDeclParser::MessageDeclContext *ctx) override;
  void enterCheckDeclBody(TestCaseDeclParser::CheckDeclBodyContext *ctx) override;
  void exitCheckDecl(TestCaseDeclParser::CheckDeclContext *ctx) override;
  void exitTimeOutDecl(TestCaseDeclParser::TimeOutDeclContext *ctx) override;
  void exitIdStatement(TestCaseDeclParser::IdStatementContext *ctx) override;
  void exitIdPath(TestCaseDeclParser::IdPathContext *ctx) override;

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

private:
  bool                          getItemFromPath(TestCaseDeclParser::IdPathContext *path,
                                                model::base::ModelItem* item = 0);
  QString                       getExpression(TestCaseDeclParser::ExpressionContext* ctx);
  model::msc::MscComponentItem* getOwner(model::base::AttributeItem* item);

private:
  class Private;
  Private* _d;
};

} // namespace testcase
} // namespace dslparser
