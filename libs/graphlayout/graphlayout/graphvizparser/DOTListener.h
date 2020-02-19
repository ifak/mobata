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

// Generated from C:/Users/s_phs.DESKTOP-9GA53KK/Documents/mobata/libs/graphlayout/graphlayout/graphvizparser/grammars/DOT.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "DOTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DOTParser.
 */
class  DOTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterGraph(DOTParser::GraphContext *ctx) = 0;
  virtual void exitGraph(DOTParser::GraphContext *ctx) = 0;

  virtual void enterStmt_list(DOTParser::Stmt_listContext *ctx) = 0;
  virtual void exitStmt_list(DOTParser::Stmt_listContext *ctx) = 0;

  virtual void enterStmt(DOTParser::StmtContext *ctx) = 0;
  virtual void exitStmt(DOTParser::StmtContext *ctx) = 0;

  virtual void enterAttr_stmt(DOTParser::Attr_stmtContext *ctx) = 0;
  virtual void exitAttr_stmt(DOTParser::Attr_stmtContext *ctx) = 0;

  virtual void enterAttr_list(DOTParser::Attr_listContext *ctx) = 0;
  virtual void exitAttr_list(DOTParser::Attr_listContext *ctx) = 0;

  virtual void enterA_list(DOTParser::A_listContext *ctx) = 0;
  virtual void exitA_list(DOTParser::A_listContext *ctx) = 0;

  virtual void enterEdge_stmt(DOTParser::Edge_stmtContext *ctx) = 0;
  virtual void exitEdge_stmt(DOTParser::Edge_stmtContext *ctx) = 0;

  virtual void enterEdgeRHS(DOTParser::EdgeRHSContext *ctx) = 0;
  virtual void exitEdgeRHS(DOTParser::EdgeRHSContext *ctx) = 0;

  virtual void enterEdgeop(DOTParser::EdgeopContext *ctx) = 0;
  virtual void exitEdgeop(DOTParser::EdgeopContext *ctx) = 0;

  virtual void enterNode_stmt(DOTParser::Node_stmtContext *ctx) = 0;
  virtual void exitNode_stmt(DOTParser::Node_stmtContext *ctx) = 0;

  virtual void enterNode_id(DOTParser::Node_idContext *ctx) = 0;
  virtual void exitNode_id(DOTParser::Node_idContext *ctx) = 0;

  virtual void enterPort(DOTParser::PortContext *ctx) = 0;
  virtual void exitPort(DOTParser::PortContext *ctx) = 0;

  virtual void enterSubgraph(DOTParser::SubgraphContext *ctx) = 0;
  virtual void exitSubgraph(DOTParser::SubgraphContext *ctx) = 0;

  virtual void enterCompass_pt(DOTParser::Compass_ptContext *ctx) = 0;
  virtual void exitCompass_pt(DOTParser::Compass_ptContext *ctx) = 0;

  virtual void enterId(DOTParser::IdContext *ctx) = 0;
  virtual void exitId(DOTParser::IdContext *ctx) = 0;


};

