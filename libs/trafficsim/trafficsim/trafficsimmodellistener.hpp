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

#include <dslparser/trafficsim/TrafficSimDeclBaseListener.h>
#include <dslparser/common//commonmodellistener.hpp>


#include <dslparser/dslerror.hpp>
#include <dslparser/dslparser_types.hpp>

namespace trafficsim {

class TrafficSimModel;

class TrafficSimModelListener
    : public TrafficSimDeclBaseListener
{
public:
  TrafficSimModelListener(TrafficSimModel* sutDeclModel,
                          dslparser::DslErrorList* dslErrors,
                          dslparser::TokenTextLocations* keywordTextLocations = nullptr,
                          dslparser::ModelTextLocations* modelTextLocations = nullptr);
  virtual ~TrafficSimModelListener();

protected:
  /*
  void exitSutDecl(SutDeclParser::SutDeclContext *ctx);
  void exitNameDecl(SutDeclParser::NameDeclContext *ctx);
  void exitPortDecl(SutDeclParser::PortDeclContext *ctx);
  void exitSutCompDecl(SutDeclParser::SutCompDeclContext *ctx);

  void exitSutBody(SutDeclParser::SutBodyContext *ctx);
  void exitSutCompBody(SutDeclParser::SutCompBodyContext *ctx);
    */
protected:
  //virtual void visitErrorNode(antlr4::tree::ErrorNode* node);

private:
  //void makePorts(SutDeclParser::PortDeclContext* ctx,model::ts::SutComponentItem* model);
  //void sortKeyWordLocations(); unnötig!
  class Private;
  Private* _d;
};

} // namespace trafficsim
