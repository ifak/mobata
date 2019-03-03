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

#include "SpenatBaseListener.h"
#include "../common/commonmodellistener.hpp"


#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace model{ namespace spenat{
class SpenatDeclModel;
}}

namespace dslparser {
namespace spenat {

class SpenatModelListener
    : public common::CommonModelListener<SpenatBaseListener, SpenatParser, model::spenat::SpenatDeclModel>
{
public:
  enum SpenatListenerState
  {
    SpenatDeclState = UserListenerState +1,
    PlaceDeclState,
    TransitionDeclState
  };

public:
  SpenatModelListener(model::spenat::SpenatDeclModel* spenatDeclModel,
                      DslErrorList* dslErrors,
                      TokenTextLocations* keywordTextLocations = 0,
                      ModelTextLocations* modelTextLocations = 0);
  virtual ~SpenatModelListener();

protected:
  void enterSpenatDecl(SpenatParser::SpenatDeclContext* ctx) override;
  void exitSpenatDecl(SpenatParser::SpenatDeclContext* ctx) override;

  void enterPortDecl(SpenatParser::PortDeclContext* ctx) override;
  void exitPortDecl(SpenatParser::PortDeclContext* ctx) override;

  void enterPlaceDecl(SpenatParser::PlaceDeclContext* placeDeclCtx) override;
  void exitPlaceDecl(SpenatParser::PlaceDeclContext* placeDeclCtx) override;

  void enterTransitionDecl(SpenatParser::TransitionDeclContext* transDeclCtx) override;
  void exitTransitionDecl(SpenatParser::TransitionDeclContext* transDeclCtx) override;

  void enterSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext * ctx) override;
  void exitSignalTransitionDecl(SpenatParser::SignalTransitionDeclContext * ctx) override;

  void enterTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext * ctx) override;
  void exitTimeoutTransitionDecl(SpenatParser::TimeoutTransitionDeclContext * ctx) override;

  void enterNameDecl(SpenatParser::NameDeclContext* ctx) override;
  void exitNameDecl(SpenatParser::NameDeclContext* ctx) override;

  void enterRefSignalDecl(SpenatParser::RefSignalDeclContext* ctx) override;
  void exitRefSignalDecl(SpenatParser::RefSignalDeclContext* ctx) override;

  void enterRefPortDecl(SpenatParser::RefPortDeclContext* ctx) override;
  void exitRefPortDecl(SpenatParser::RefPortDeclContext* ctx) override;

  void enterTimeoutDecl(SpenatParser::TimeoutDeclContext* ctx) override;
  void exitTimeoutDecl(SpenatParser::TimeoutDeclContext* ctx) override;

  void enterInitialDecl(SpenatParser::InitialDeclContext* ctx) override;
  void exitInitialDecl(SpenatParser::InitialDeclContext* ctx) override;

  void enterGuardDecl(SpenatParser::GuardDeclContext * ctx) override;
  void exitGuardDecl(SpenatParser::GuardDeclContext* ctx) override;

  void exitAtom(SpenatParser::AtomContext* ctx) override;

  void enterActionDecl(SpenatParser::ActionDeclContext* ctx) override;
  void exitActionDecl(SpenatParser::ActionDeclContext* ctx) override;

  void enterPreDecl(SpenatParser::PreDeclContext* ctx) override;
  void exitPreDecl(SpenatParser::PreDeclContext* ctx) override;

  void enterPostDecl(SpenatParser::PostDeclContext* ctx) override;
  void exitPostDecl(SpenatParser::PostDeclContext* ctx) override;

protected:
  void visitErrorNode(antlr4::tree::ErrorNode* node) override;

private:
  class Private;
  Private* _d;
};

} // namespace spenat
} // namespace dslparser
