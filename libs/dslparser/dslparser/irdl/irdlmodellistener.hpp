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

#include "IrdlBaseListener.h"
#include "../common/commonmodellistener.hpp"


#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace model{ namespace irdl{
class RequirementsModel;
}
                 namespace msc{
                 class MscComponentItem;
                 class MscTimerItem;
                 class MscCheckMessageItem;
                 }
                                  namespace base {
                                  class PortItem;
                                  class SignalItem;
                                  }
               }

namespace dslparser {
namespace irdl {

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;
typedef QHash<QString, model::irdl::RequirementsModel*> ImportModel;

class IrdlModelListener
    : public common::CommonModelListener<IrdlBaseListener, IrdlParser, model::irdl::RequirementsModel>
{
public:
  enum RequirementsListenerState
  {
    IrdlState = UserListenerState +1,
    ActorDeclState,
    ComponentDeclState
  };

public:
  IrdlModelListener(model::irdl::RequirementsModel* irdlDeclModel,
                    DslErrorList* dslErrors,
                    const QString &prefix = QStringLiteral(""),
                    TokenTextLocations* keywordTextLocations = nullptr,
                    ModelTextLocations* modelTextLocations = nullptr);
  virtual ~IrdlModelListener();

  QPair<model::base::ModelItem*,int>                  currentPathItem();
  const model::base::SignalItem *currentSignalItem();
  const QHash<QString, const model::msc::MscComponentItem *> &requirementCompItems();
  const ImportModelItem&                              importItems();
  const ImportModel&                                  importModels();
  const QHash<QString,const model::msc::MscTimerItem *>     timerItems();


protected:
  void enterIrdlDecl(IrdlParser::IrdlDeclContext* ctx) override;
  void exitIrdlDecl(IrdlParser::IrdlDeclContext* ctx) override;

  void enterAliasDef(IrdlParser::AliasDefContext * ctx) override;
  void exitAliasDef(IrdlParser::AliasDefContext * ctx) override;

  void enterActorDecl(IrdlParser::ActorDeclContext * ctx) override;
  void exitActorDecl(IrdlParser::ActorDeclContext * ctx) override;

  void enterComponentDecl(IrdlParser::ComponentDeclContext * ctx) override;
  void exitComponentDecl(IrdlParser::ComponentDeclContext * ctx) override;

  void enterPortDecl(IrdlParser::PortDeclContext* ctx) override;
  void exitPortDecl(IrdlParser::PortDeclContext* ctx) override;

  void enterNameDecl(IrdlParser::NameDeclContext* ctx) override;
  void exitNameDecl(IrdlParser::NameDeclContext* ctx) override;

  void enterDescriptionDecl(IrdlParser::DescriptionDeclContext* ctx) override;
  void exitDescriptionDecl(IrdlParser::DescriptionDeclContext* ctx) override;

  void enterStateDecl(IrdlParser::StateDeclContext * ctx) override;
  void exitStateDecl(IrdlParser::StateDeclContext * ctx) override;

  void enterMessageDecl(IrdlParser::MessageDeclContext * ctx) override;
  void exitMessageDecl(IrdlParser::MessageDeclContext * ctx) override;

  void enterTimerDecl(IrdlParser::TimerDeclContext * ctx) override;
  void exitTimerDecl(IrdlParser::TimerDeclContext * ctx) override;

  void exitTimerNameID(IrdlParser::TimerNameIDContext * ctx) override;
  void exitAttributeAssignStatement(IrdlParser::AttributeAssignStatementContext *ctx) override;

  void enterCheckDeclBody(IrdlParser::CheckDeclBodyContext * ctx) override;
  void exitCheckDecl(IrdlParser::CheckDeclContext * ctx) override;

  void addCheckAssign(model::msc::MscCheckMessageItem* check, IrdlParser::AttributeAssignContext *ctx);

  void enterAltDecl(IrdlParser::AltDeclContext * ctx) override;
  void exitAltDecl(IrdlParser::AltDeclContext * ctx) override;

  void enterAltBody(IrdlParser::AltBodyContext * ctx) override;
  void exitAltBody(IrdlParser::AltBodyContext * ctx) override;

  void enterDurationDecl(IrdlParser::DurationDeclContext * ctx) override;
  void exitDurationDecl(IrdlParser::DurationDeclContext * ctx) override;
  //void enterDurationElseDecl(IrdlParser::DurationElseDeclContext * ctx) override;
  //void exitDurationElseDecl(IrdlParser::DurationElseDeclContext * ctx) override;

  void enterImportPathBody(IrdlParser::ImportPathBodyContext *ctx) override;
  void exitImportPathBody(IrdlParser::ImportPathBodyContext *ctx) override;

  void enterRequirementBody(IrdlParser::RequirementBodyContext *ctx) override;

  void exitFunctionCallBody(IrdlParser::FunctionCallBodyContext * ctx) override;
  void exitAtom(IrdlParser::AtomContext* ctx) override;

  void exitSignalParamName(IrdlParser::SignalParamNameContext *ctx) override;
  void exitSignalIdPath(IrdlParser::SignalIdPathContext *ctx) override;

  void exitDeclarations(IrdlParser::DeclarationsContext *ctx) override;
  //    void exitIdPath(IrdlParser::IdPathContext *ctx) override;

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

  //private:
  //  void addState(antlr4::ParserRuleContext* ctx);
  const model::msc::MscComponentItem *getSystem();
  const model::msc::MscComponentItem *getAlias(QString name);
  const model::base::PortItem *getComponentFromPath(IrdlParser::ComponentIdPathContext *compPath);
  const model::base::SignalItem *getSignalFromPath(IrdlParser::SignalIdPathContext *signalPath);
  const model::base::AttributeItem* getAttributeFromPath(IrdlParser::AttributeIdPathContext *attributePath);
private:
  class Private;
  Private* _d;
};

} // namespace irdl
} // namespace dslparser
