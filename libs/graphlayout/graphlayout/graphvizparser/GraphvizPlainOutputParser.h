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


#include <stdexcept>

#define QT_NO_KEYWORDS
#include "graphvizgraph.hpp"
#undef QT_NO_KEYWORDS




class  GraphvizPlainOutputParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, GraphID = 7, 
    NodeID = 8, EdgeID = 9, StopID = 10, ID = 11, WS = 12, NUMBER = 13
  };

  enum {
    RuleGraphvizPlainOutput = 0, RuleGraph = 1, RuleNode = 2, RuleEdge = 3, 
    RuleString = 4, RuleTextRule = 5, RuleStop = 6
  };

  GraphvizPlainOutputParser(antlr4::TokenStream *input);
  ~GraphvizPlainOutputParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


    void setGraphvizGraph(graphvizparser::GraphvizGraph* graphvizGraph)
    {
      assert(graphvizGraph);
      this->_graphvizGraph = graphvizGraph;

      return;
    }

    graphvizparser::GraphvizGraph*	_graphvizGraph = nullptr;


  class GraphvizPlainOutputContext;
  class GraphContext;
  class NodeContext;
  class EdgeContext;
  class StringContext;
  class TextRuleContext;
  class StopContext; 

  class  GraphvizPlainOutputContext : public antlr4::ParserRuleContext {
  public:
    GraphvizPlainOutputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GraphContext *graph();
    StopContext *stop();
    std::vector<NodeContext *> node();
    NodeContext* node(size_t i);
    std::vector<EdgeContext *> edge();
    EdgeContext* edge(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GraphvizPlainOutputContext* graphvizPlainOutput();

  class  GraphContext : public antlr4::ParserRuleContext {
  public:
    GraphContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GraphContext* graph();

  class  NodeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;;
    antlr4::Token *x = nullptr;;
    antlr4::Token *y = nullptr;;
    antlr4::Token *w = nullptr;;
    antlr4::Token *h = nullptr;;
    GraphvizPlainOutputParser::TextRuleContext *labelString = nullptr;;
    antlr4::Token *labelID = nullptr;;
    antlr4::Token *style = nullptr;;
    antlr4::Token *shape = nullptr;;
    antlr4::Token *color = nullptr;;
    antlr4::Token *fillcolor = nullptr;;
    NodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    TextRuleContext *textRule();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NodeContext* node();

  class  EdgeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *from = nullptr;;
    antlr4::Token *to = nullptr;;
    antlr4::Token *points_count = nullptr;;
    antlr4::Token *x = nullptr;;
    antlr4::Token *y = nullptr;;
    GraphvizPlainOutputParser::TextRuleContext *labelString = nullptr;;
    antlr4::Token *labelID = nullptr;;
    antlr4::Token *x_label = nullptr;;
    antlr4::Token *y_label = nullptr;;
    antlr4::Token *style = nullptr;;
    antlr4::Token *color = nullptr;;
    EdgeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    TextRuleContext *textRule();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EdgeContext* edge();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TextRuleContext *textRule();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StringContext* string();

  class  TextRuleContext : public antlr4::ParserRuleContext {
  public:
    TextRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TextRuleContext* textRule();

  class  StopContext : public antlr4::ParserRuleContext {
  public:
    StopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StopContext* stop();


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

