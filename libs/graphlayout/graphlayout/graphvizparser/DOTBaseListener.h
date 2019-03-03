
// Generated from C:/Users/s_phs.DESKTOP-9GA53KK/Documents/mobata/libs/graphlayout/graphlayout/graphvizparser/grammars/DOT.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "DOTListener.h"


/**
 * This class provides an empty implementation of DOTListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DOTBaseListener : public DOTListener {
public:

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

  virtual void enterEdge_stmt(DOTParser::Edge_stmtContext * /*ctx*/) override { }
  virtual void exitEdge_stmt(DOTParser::Edge_stmtContext * /*ctx*/) override { }

  virtual void enterEdgeRHS(DOTParser::EdgeRHSContext * /*ctx*/) override { }
  virtual void exitEdgeRHS(DOTParser::EdgeRHSContext * /*ctx*/) override { }

  virtual void enterEdgeop(DOTParser::EdgeopContext * /*ctx*/) override { }
  virtual void exitEdgeop(DOTParser::EdgeopContext * /*ctx*/) override { }

  virtual void enterNode_stmt(DOTParser::Node_stmtContext * /*ctx*/) override { }
  virtual void exitNode_stmt(DOTParser::Node_stmtContext * /*ctx*/) override { }

  virtual void enterNode_id(DOTParser::Node_idContext * /*ctx*/) override { }
  virtual void exitNode_id(DOTParser::Node_idContext * /*ctx*/) override { }

  virtual void enterPort(DOTParser::PortContext * /*ctx*/) override { }
  virtual void exitPort(DOTParser::PortContext * /*ctx*/) override { }

  virtual void enterSubgraph(DOTParser::SubgraphContext * /*ctx*/) override { }
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

