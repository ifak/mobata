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

