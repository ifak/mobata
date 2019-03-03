
// Generated from /mnt/diskdata/SWDevelop/mobata/libs/graphlayout/graphvizparser/grammars/GraphvizPlainOutput.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "GraphvizPlainOutputListener.h"


/**
 * This class provides an empty implementation of GraphvizPlainOutputListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GraphvizPlainOutputBaseListener : public GraphvizPlainOutputListener {
public:

  virtual void enterGraphvizPlainOutput(GraphvizPlainOutputParser::GraphvizPlainOutputContext * /*ctx*/) override { }
  virtual void exitGraphvizPlainOutput(GraphvizPlainOutputParser::GraphvizPlainOutputContext * /*ctx*/) override { }

  virtual void enterGraph(GraphvizPlainOutputParser::GraphContext * /*ctx*/) override { }
  virtual void exitGraph(GraphvizPlainOutputParser::GraphContext * /*ctx*/) override { }

  virtual void enterNode(GraphvizPlainOutputParser::NodeContext * /*ctx*/) override { }
  virtual void exitNode(GraphvizPlainOutputParser::NodeContext * /*ctx*/) override { }

  virtual void enterEdge(GraphvizPlainOutputParser::EdgeContext * /*ctx*/) override { }
  virtual void exitEdge(GraphvizPlainOutputParser::EdgeContext * /*ctx*/) override { }

  virtual void enterString(GraphvizPlainOutputParser::StringContext * /*ctx*/) override { }
  virtual void exitString(GraphvizPlainOutputParser::StringContext * /*ctx*/) override { }

  virtual void enterTextRule(GraphvizPlainOutputParser::TextRuleContext * /*ctx*/) override { }
  virtual void exitTextRule(GraphvizPlainOutputParser::TextRuleContext * /*ctx*/) override { }

  virtual void enterStop(GraphvizPlainOutputParser::StopContext * /*ctx*/) override { }
  virtual void exitStop(GraphvizPlainOutputParser::StopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

