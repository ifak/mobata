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

#include "DiagnosisDeclBaseListener.h"
#include "../common/commonmodellistener.hpp"

#include <mobata/model/diagnosis/diagnosisitem.hpp>
#include <mobata/model/ts/testcomponentitem.hpp>
#include <mobata/model/ts/testsuite.hpp>

#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace model{
namespace base {
class AttributeItem;
class ModelItem;
}
}

namespace dslparser {
namespace diagnosis {

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;

class DiagnosisModelListener
    : public common::CommonModelListener< DiagnosisDeclBaseListener, DiagnosisDeclParser, model::diagnosis::DiagnosisItem>
{
  typedef common::CommonModelListener<DiagnosisDeclBaseListener, DiagnosisDeclParser, model::diagnosis::DiagnosisItem> BaseClass;

protected:
  enum DiagnosisModelListenerState
  {
    DiagnosisDeclState = UserListenerState +1,
    TestCompDeclState
  };

public:
  DiagnosisModelListener(model::diagnosis::DiagnosisItem *diagnosisDeclModel,
                        DslErrorList* dslErrors,
                        QString* importedSutFileName,
                        QString* importedTestSystemFileName,
                        const QString& praefix = QStringLiteral(""),
                        TokenTextLocations* keywordTextLocations = 0,
                        ModelTextLocations* modelTextLocations = 0);
  virtual ~DiagnosisModelListener();

public:
  model::base::ModelItem*                       currentPathItem();
  model::base::ModelItem*                       currentSignalItem();
  const QHash<QString,model::base::ModelItem*>& diagnosisItems();
  const ImportModelItem&                        importItems();

protected:
  void enterDiagnosisDecl(DiagnosisDeclParser::DiagnosisDeclContext* ctx);
  void enterRuleBody(DiagnosisDeclParser::RuleBodyContext *ctx);
  void exitRuleDecl(DiagnosisDeclParser::RuleDeclContext *ctx);
  void exitDescriptionDecl(DiagnosisDeclParser::DescriptionDeclContext * ctx);
  void exitRuleBody(DiagnosisDeclParser::RuleBodyContext *ctx);
  void exitBasetypeDecl(DiagnosisDeclParser::BasetypeDeclContext* ctx);
  void exitCheckDecl(DiagnosisDeclParser::CheckDeclContext* ctx);
  void exitSequenceDecl(DiagnosisDeclParser::SequenceDeclContext* ctx);
  void enterDeclarations(DiagnosisDeclParser::DeclarationsContext *ctx);
  void exitDeclarations(DiagnosisDeclParser::DeclarationsContext *ctx);  
  void enterNameDecl(DiagnosisDeclParser::NameDeclContext* ctx);
  void exitNameDecl(DiagnosisDeclParser::NameDeclContext *ctx);
  void exitEnabledDecl(DiagnosisDeclParser::EnabledDeclContext *ctx);
  void exitImportPathBody(DiagnosisDeclParser::ImportPathBodyContext *ctx);
  void exitAliasDef(DiagnosisDeclParser::AliasDefContext *ctx);
  void exitParallelDecl(DiagnosisDeclParser::ParallelDeclContext *ctx);
  void enterParallelBody(DiagnosisDeclParser::ParallelBodyContext *ctx);
  void exitParallelBody(DiagnosisDeclParser::ParallelBodyContext *ctx);
  void enterParallelDecl(DiagnosisDeclParser::ParallelDeclContext *ctx);
  void enterLoopDecl(DiagnosisDeclParser::LoopDeclContext *ctx);
  void exitLoopDecl(DiagnosisDeclParser::LoopDeclContext *ctx);
  void exitMessageDecl(DiagnosisDeclParser::MessageDeclContext *ctx);
  void enterComponentDecl(DiagnosisDeclParser::ComponentDeclContext *ctx);
  void exitComponentDecl(DiagnosisDeclParser::ComponentDeclContext *ctx);
  void enterDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext *ctx);
  void exitDiagnosisSignalDecl(DiagnosisDeclParser::DiagnosisSignalDeclContext *ctx);

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node);

private:
  class Private;
  Private* _d;
  bool getItemFromPath(DiagnosisDeclParser::IdPathContext *path,model::base::ModelItem* item = 0);
  QString getExpression(DiagnosisDeclParser::ExpressionContext* ctx);
  DiagnosisDeclParser::IdPathContext *findCompareValue(DiagnosisDeclParser::ExpressionContext* ctx, uint token);
  model::msc::MscComponentItem* getOwner(model::base::AttributeItem* item);
};

} // namespace diagnosis
} // namespace dslparser
