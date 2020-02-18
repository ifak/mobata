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




class  DOTParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, STRICTT = 12, GRAPH = 13, 
    DIGRAPH = 14, NODE = 15, EDGE = 16, SUBGRAPH = 17, NUMBER = 18, STRING = 19, 
    HTML_STRING = 20, TAG = 21, EntityRef = 22, ID = 23, COMMENT = 24, LINE_COMMENT = 25, 
    PREPROC = 26, WS = 27
  };

  enum {
    RuleGraph = 0, RuleStmt_list = 1, RuleStmt = 2, RuleAttr_stmt = 3, RuleAttr_list = 4, 
    RuleA_list = 5, RuleEdge_stmt = 6, RuleEdgeRHS = 7, RuleEdgeop = 8, 
    RuleNode_stmt = 9, RuleNode_id = 10, RulePort = 11, RuleSubgraph = 12, 
    RuleCompass_pt = 13, RuleId = 14
  };

  DOTParser(antlr4::TokenStream *input);
  ~DOTParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class GraphContext;
  class Stmt_listContext;
  class StmtContext;
  class Attr_stmtContext;
  class Attr_listContext;
  class A_listContext;
  class Edge_stmtContext;
  class EdgeRHSContext;
  class EdgeopContext;
  class Node_stmtContext;
  class Node_idContext;
  class PortContext;
  class SubgraphContext;
  class Compass_ptContext;
  class IdContext; 

  class  GraphContext : public antlr4::ParserRuleContext {
  public:
    GraphContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stmt_listContext *stmt_list();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *DIGRAPH();
    antlr4::tree::TerminalNode *STRICTT();
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GraphContext* graph();

  class  Stmt_listContext : public antlr4::ParserRuleContext {
  public:
    Stmt_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Stmt_listContext* stmt_list();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Node_stmtContext *node_stmt();
    Edge_stmtContext *edge_stmt();
    Attr_stmtContext *attr_stmt();
    std::vector<IdContext *> id();
    IdContext* id(size_t i);
    SubgraphContext *subgraph();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StmtContext* stmt();

  class  Attr_stmtContext : public antlr4::ParserRuleContext {
  public:
    Attr_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attr_listContext *attr_list();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *NODE();
    antlr4::tree::TerminalNode *EDGE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Attr_stmtContext* attr_stmt();

  class  Attr_listContext : public antlr4::ParserRuleContext {
  public:
    Attr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<A_listContext *> a_list();
    A_listContext* a_list(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Attr_listContext* attr_list();

  class  A_listContext : public antlr4::ParserRuleContext {
  public:
    A_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdContext *> id();
    IdContext* id(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  A_listContext* a_list();

  class  Edge_stmtContext : public antlr4::ParserRuleContext {
  public:
    Edge_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EdgeRHSContext *edgeRHS();
    Node_idContext *node_id();
    SubgraphContext *subgraph();
    Attr_listContext *attr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Edge_stmtContext* edge_stmt();

  class  EdgeRHSContext : public antlr4::ParserRuleContext {
  public:
    EdgeRHSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EdgeopContext *> edgeop();
    EdgeopContext* edgeop(size_t i);
    std::vector<Node_idContext *> node_id();
    Node_idContext* node_id(size_t i);
    std::vector<SubgraphContext *> subgraph();
    SubgraphContext* subgraph(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EdgeRHSContext* edgeRHS();

  class  EdgeopContext : public antlr4::ParserRuleContext {
  public:
    EdgeopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EdgeopContext* edgeop();

  class  Node_stmtContext : public antlr4::ParserRuleContext {
  public:
    Node_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Node_idContext *node_id();
    Attr_listContext *attr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Node_stmtContext* node_stmt();

  class  Node_idContext : public antlr4::ParserRuleContext {
  public:
    Node_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    PortContext *port();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Node_idContext* node_id();

  class  PortContext : public antlr4::ParserRuleContext {
  public:
    PortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    Compass_ptContext *compass_pt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortContext* port();

  class  SubgraphContext : public antlr4::ParserRuleContext {
  public:
    SubgraphContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stmt_listContext *stmt_list();
    antlr4::tree::TerminalNode *SUBGRAPH();
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubgraphContext* subgraph();

  class  Compass_ptContext : public antlr4::ParserRuleContext {
  public:
    Compass_ptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compass_ptContext* compass_pt();

  class  IdContext : public antlr4::ParserRuleContext {
  public:
    IdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *HTML_STRING();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdContext* id();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

