
// Generated from /mnt/diskdata/SWDevelop/mobata/libs/graphlayout/graphvizparser/grammars/GraphvizPlainOutput.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "GraphvizPlainOutputParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GraphvizPlainOutputParser.
 */
class  GraphvizPlainOutputListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterGraphvizPlainOutput(GraphvizPlainOutputParser::GraphvizPlainOutputContext *ctx) = 0;
  virtual void exitGraphvizPlainOutput(GraphvizPlainOutputParser::GraphvizPlainOutputContext *ctx) = 0;

  virtual void enterGraph(GraphvizPlainOutputParser::GraphContext *ctx) = 0;
  virtual void exitGraph(GraphvizPlainOutputParser::GraphContext *ctx) = 0;

  virtual void enterNode(GraphvizPlainOutputParser::NodeContext *ctx) = 0;
  virtual void exitNode(GraphvizPlainOutputParser::NodeContext *ctx) = 0;

  virtual void enterEdge(GraphvizPlainOutputParser::EdgeContext *ctx) = 0;
  virtual void exitEdge(GraphvizPlainOutputParser::EdgeContext *ctx) = 0;

  virtual void enterString(GraphvizPlainOutputParser::StringContext *ctx) = 0;
  virtual void exitString(GraphvizPlainOutputParser::StringContext *ctx) = 0;

  virtual void enterTextRule(GraphvizPlainOutputParser::TextRuleContext *ctx) = 0;
  virtual void exitTextRule(GraphvizPlainOutputParser::TextRuleContext *ctx) = 0;

  virtual void enterStop(GraphvizPlainOutputParser::StopContext *ctx) = 0;
  virtual void exitStop(GraphvizPlainOutputParser::StopContext *ctx) = 0;


};

