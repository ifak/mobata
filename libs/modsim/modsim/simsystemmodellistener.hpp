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

#include <dslparser/simsystem/SimSystemDeclBaseListener.h>
#include <dslparser/common/commonmodellistener.hpp>

#include "simsystem_types.hpp"
#include "simsystemitem.hpp"

#include <dslparser/dslerror.hpp>
#include <dslparser/dslparser_types.hpp>

namespace modsim {

class SimSystemModelListener
    : public dslparser::common::CommonModelListener< SimSystemDeclBaseListener, SimSystemDeclParser, SimSystemItem>
{
  typedef dslparser::common::CommonModelListener<SimSystemDeclBaseListener, SimSystemDeclParser, SimSystemItem> BaseClass;

protected:
  enum SimSystemModelListenerState
  {
    SimSystemDeclState = UserListenerState +1,
    SimSystemCompDeclState
  };

public:
  SimSystemModelListener(SimSystemItem* simsystemDeclModel,
                         dslparser::DslErrorList* dslErrors,
                         const QString &prefix = QString(""),
                         dslparser::TokenTextLocations* keywordTextLocations = nullptr,
                         dslparser::ModelTextLocations* modelTextLocations = nullptr);
  virtual ~SimSystemModelListener() override;

public:
  const ImportSpenatModelList&        importedSpenatModels() const;
  const ImportStatemachineModelList&  importedStatemachineModels() const;

protected:
  void enterSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext* ctx) override;
  void exitSimSystemDecl(SimSystemDeclParser::SimSystemDeclContext *ctx) override;

  void enterActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext* ctx) override;
  void exitPortDecl(SimSystemDeclParser::PortDeclContext * ctx) override;
  void exitActorDeclBody(SimSystemDeclParser::ActorDeclBodyContext *ctx) override;

  void exitConnectionDecl(SimSystemDeclParser::ConnectionDeclContext *ctx) override;
  void exitConfigDecl(SimSystemDeclParser::ConfigDeclContext *ctx) override;
  void exitStartSequenceDecl(SimSystemDeclParser::StartSequenceDeclContext *ctx) override;

  void exitMessageDecl(SimSystemDeclParser::MessageDeclContext * ctx) override;
  void exitStartupDecl(SimSystemDeclParser::StartupDeclContext * ctx) override;

  void exitConnectionBody(SimSystemDeclParser::ConnectionBodyContext *ctx) override;
  void exitConfigBody(SimSystemDeclParser::ConfigBodyContext *ctx) override;

  void enterImportPathBody(SimSystemDeclParser::ImportPathBodyContext *ctx) override;
  void exitImportPathBody(SimSystemDeclParser::ImportPathBodyContext *ctx) override;

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

private:
  bool validModelPort(const QString& modelName,
                      const QString& portName,
                      QString* errorString) const;
  model::base::SignalItem const* findMessageSignal(const QString& modelName,
                                                   const QString& signalName,
                                                   QString* errorString) const;
private:
  class Private;
  Private* _d;
};

} // namespace modsim
