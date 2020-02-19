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

#include "IrdlCommonDeclBaseListener.h"
#include "../common/commonmodellistener.hpp"


#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace model{
  namespace irdl{
    class RequirementsModel;
  }
  namespace msc {
    class MscComponentItem;
  }
  namespace base {
    class PortItem;
  }
}

namespace dslparser {
namespace irdl {

typedef QHash<QString, model::base::ModelItem*> ImportModelItem;
typedef QHash<QString, model::irdl::RequirementsModel*> ImportModel;

class IrdlDeclModelListener
    : public common::CommonModelListener<IrdlCommonDeclBaseListener, IrdlCommonDeclParser, model::irdl::RequirementsModel>
{
public:
  enum RequirementsListenerState
  {
    IrdlCommonDeclState = UserListenerState +1,
    ActorDeclState,
    ComponentDeclState
  };

public:
  IrdlDeclModelListener(model::irdl::RequirementsModel* IrdlCommonDeclModel,
                        DslErrorList* dslErrors,
                        const QString &prefix = QStringLiteral(""),
                        TokenTextLocations* keywordTextLocations = nullptr,
                        ModelTextLocations* modelTextLocations = nullptr);
  virtual ~IrdlDeclModelListener();

  QPair<model::base::ModelItem*,int>                  currentPathItem();
  model::base::ModelItem*                             currentSignalItem();
  const QHash<QString,model::msc::MscComponentItem*>& requirementCompItems();
  const ImportModelItem&                              importItems();
  const ImportModel&                                  importModels();


protected:
  void enterIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext *ctx) override;
  void exitIrdlDecl(IrdlCommonDeclParser::IrdlDeclContext *ctx) override;

  void enterAliasDef(IrdlCommonDeclParser::AliasDefContext * ctx) override;
  void exitAliasDef(IrdlCommonDeclParser::AliasDefContext * ctx) override;

  void enterActorDecl(IrdlCommonDeclParser::ActorDeclContext * ctx) override;
  void exitActorDecl(IrdlCommonDeclParser::ActorDeclContext * ctx) override;

  void enterComponentDecl(IrdlCommonDeclParser::ComponentDeclContext * ctx) override;
  void exitComponentDecl(IrdlCommonDeclParser::ComponentDeclContext * ctx) override;

  void enterPortDecl(IrdlCommonDeclParser::PortDeclContext* ctx) override;
  void exitPortDecl(IrdlCommonDeclParser::PortDeclContext* ctx) override;

  void enterNameDecl(IrdlCommonDeclParser::NameDeclContext* ctx) override;
  void exitNameDecl(IrdlCommonDeclParser::NameDeclContext* ctx) override;

  void enterDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext* ctx) override;
  void exitDescriptionDecl(IrdlCommonDeclParser::DescriptionDeclContext* ctx) override;

  void enterStateDecl(IrdlCommonDeclParser::StateDeclContext * ctx) override;
  void exitStateDecl(IrdlCommonDeclParser::StateDeclContext * ctx) override;

  void enterMessageDecl(IrdlCommonDeclParser::MessageDeclContext * ctx) override;
  void exitMessageDecl(IrdlCommonDeclParser::MessageDeclContext * ctx) override;

  void enterTimerDecl(IrdlCommonDeclParser::TimerDeclContext * ctx) override;
  void exitTimerDecl(IrdlCommonDeclParser::TimerDeclContext * ctx) override;

  void enterCheckDeclBody(IrdlCommonDeclParser::CheckDeclBodyContext * ctx) override;
  void exitCheckDecl(IrdlCommonDeclParser::CheckDeclContext * ctx) override;

  void enterAltDecl(IrdlCommonDeclParser::AltDeclContext * ctx) override;
  void exitAltDecl(IrdlCommonDeclParser::AltDeclContext * ctx) override;

  void enterAltBody(IrdlCommonDeclParser::AltBodyContext * ctx) override;
  void exitAltBody(IrdlCommonDeclParser::AltBodyContext * ctx) override;

  void enterDurationDecl(IrdlCommonDeclParser::DurationDeclContext * ctx) override;
  void exitDurationDecl(IrdlCommonDeclParser::DurationDeclContext * ctx) override;

  void enterImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext *ctx) override;
  void exitImportPathBody(IrdlCommonDeclParser::ImportPathBodyContext *ctx) override;

  void enterRequirementBody(IrdlCommonDeclParser::RequirementBodyContext *ctx) override;

  //  void exitIdPath(IrdlCommonDeclParser::IdPathContext *ctx) override;

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

private:
  model::msc::MscComponentItem* getAlias(QString name);
  const model::base::PortItem *getComponentFromPath(IrdlCommonDeclParser::ComponentIdPathContext *compPath);
  const model::base::SignalItem *getSignalFromPath(IrdlCommonDeclParser::SignalIdPathContext *signalPath);
  const model::base::AttributeItem* getAttributeFromPath(IrdlCommonDeclParser::AttributeIdPathContext *attributePath);

private:
  class Private;
  Private* _d;
};

} // namespace irdldecl
} // namespace dslparser
