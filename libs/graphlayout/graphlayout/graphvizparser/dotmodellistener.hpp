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


#include "antlr4-runtime.h"
#include "DOTListener.h"
#include <layoutgraph.hpp>


class  DotModelListener : public DOTListener {
public:
    DotModelListener();
    void setGraph(graphlayout::LayoutGraph* graph);
    graphlayout::LayoutGraph* _graph=nullptr;
    const double _pixperinch=72;

  virtual void enterGraph(DOTParser::GraphContext * /*ctx*/) override { }
  virtual void exitGraph(DOTParser::GraphContext * /*ctx*/) override { }

  virtual void enterStmt_list(DOTParser::Stmt_listContext * /*ctx*/) override { }
  virtual void exitStmt_list(DOTParser::Stmt_listContext * /*ctx*/) override { }

  virtual void enterStmt(DOTParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(DOTParser::StmtContext * /*ctx*/) override { }

  virtual void enterAttr_stmt(DOTParser::Attr_stmtContext * /*ctx*/) override { }
  virtual void exitAttr_stmt(DOTParser::Attr_stmtContext * /*ctx*/) override { }

  virtual void enterAttr_list(DOTParser::Attr_listContext * /*ctx*/) override { }
  virtual void exitAttr_list(DOTParser::Attr_listContext * /*ctx*/) override { }

  virtual void enterA_list(DOTParser::A_listContext * /*ctx*/) override { }
  virtual void exitA_list(DOTParser::A_listContext * /*ctx*/) override { }

  virtual void enterEdge_stmt(DOTParser::Edge_stmtContext * ctx) override;
  virtual void exitEdge_stmt(DOTParser::Edge_stmtContext * /*ctx*/) override { }

  virtual void enterEdgeRHS(DOTParser::EdgeRHSContext * /*ctx*/) override { }
  virtual void exitEdgeRHS(DOTParser::EdgeRHSContext * /*ctx*/) override { }

  virtual void enterEdgeop(DOTParser::EdgeopContext * /*ctx*/) override { }
  virtual void exitEdgeop(DOTParser::EdgeopContext * /*ctx*/) override { }

  virtual void enterNode_stmt(DOTParser::Node_stmtContext * ctx) override;
  virtual void exitNode_stmt(DOTParser::Node_stmtContext * /*ctx*/) override { }

  virtual void enterNode_id(DOTParser::Node_idContext * /*ctx*/) override { }
  virtual void exitNode_id(DOTParser::Node_idContext * /*ctx*/) override { }

  virtual void enterPort(DOTParser::PortContext * /*ctx*/) override { }
  virtual void exitPort(DOTParser::PortContext * /*ctx*/) override { }

  virtual void enterSubgraph(DOTParser::SubgraphContext * ctx) override;
  virtual void exitSubgraph(DOTParser::SubgraphContext * /*ctx*/) override { }

  virtual void enterCompass_pt(DOTParser::Compass_ptContext * /*ctx*/) override { }
  virtual void exitCompass_pt(DOTParser::Compass_ptContext * /*ctx*/) override { }

  virtual void enterId(DOTParser::IdContext * /*ctx*/) override { }
  virtual void exitId(DOTParser::IdContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

