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

#include "IsrdlBaseListener.h"
#include "../common/commonmodellistener.hpp"

//#include <mobata/model/isrdl/isrdlitem.hpp>
#include <mobata/model/isrdl/isrdlmodel.hpp>

#include "../dslerror.hpp"
#include "../dslparser_types.hpp"

namespace dslparser {
namespace isrdl {

class IsrdlModelListener
    : public common::CommonModelListener< IsrdlBaseListener, IsrdlParser, model::isrdl::IsrdlModel>
{
  typedef common::CommonModelListener<IsrdlBaseListener, IsrdlParser, model::isrdl::IsrdlModel> BaseClass;

protected:
  enum IsrdlModelListenerState
  {
    IsrdlState = UserListenerState +1,
    IsrdlCompDeclState
  };

public:
  IsrdlModelListener(model::isrdl::IsrdlModel* isrdlDeclModel,
                   DslErrorList* dslErrors,
                   TokenTextLocations* keywordTextLocations = nullptr,
                   ModelTextLocations* modelTextLocations = nullptr);
  virtual ~IsrdlModelListener() override;

protected:
  void enterSecRequirement(IsrdlParser::SecRequirementContext* ctx) override;
  void exitSecRequirement(IsrdlParser::SecRequirementContext *ctx) override;

  virtual void enterAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext *ctx) override;
  virtual void exitAttackDescriptionDecl(IsrdlParser::AttackDescriptionDeclContext *ctx) override;

  virtual void enterAttackImpactDecl(IsrdlParser::AttackImpactDeclContext *ctx) override;
  virtual void exitAttackImpactDecl(IsrdlParser::AttackImpactDeclContext *ctx) override;

  virtual void exitAttackVectorDecl(IsrdlParser::AttackVectorDeclContext *ctx) override;

  virtual void exitAttackPrivileges(IsrdlParser::AttackPrivilegesContext *ctx) override;

  virtual void exitPrivilegesEnum(IsrdlParser::PrivilegesEnumContext *ctx) override;

  virtual void exitConfidentialityThreatDecl(IsrdlParser::ConfidentialityThreatDeclContext *ctx) override;

  virtual void exitIntegrityThreatDecl(IsrdlParser::IntegrityThreatDeclContext *ctx) override;

  virtual void exitAvailabilityThreatDecl(IsrdlParser::AvailabilityThreatDeclContext *ctx) override;

  void enterNameDecl(IsrdlParser::NameDeclContext* ctx) override;
  void exitNameDecl(IsrdlParser::NameDeclContext *ctx) override;

protected:
  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

private:
  class Private;
  Private* _d;
};

} // namespace isrdl
} // namespace dslparser
