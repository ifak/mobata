
// Generated from C:/Users/s_phs.DESKTOP-9GA53KK/Documents/mobata/libs/graphlayout/graphlayout/graphvizparser/grammars/DOT.g4 by ANTLR 4.7


#include "DOTListener.h"

#include "DOTParser.h"


using namespace antlrcpp;
using namespace antlr4;

DOTParser::DOTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DOTParser::~DOTParser() {
  delete _interpreter;
}

std::string DOTParser::getGrammarFileName() const {
  return "DOT.g4";
}

const std::vector<std::string>& DOTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DOTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- GraphContext ------------------------------------------------------------------

DOTParser::GraphContext::GraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Stmt_listContext* DOTParser::GraphContext::stmt_list() {
  return getRuleContext<DOTParser::Stmt_listContext>(0);
}

tree::TerminalNode* DOTParser::GraphContext::GRAPH() {
  return getToken(DOTParser::GRAPH, 0);
}

tree::TerminalNode* DOTParser::GraphContext::DIGRAPH() {
  return getToken(DOTParser::DIGRAPH, 0);
}

tree::TerminalNode* DOTParser::GraphContext::STRICTT() {
  return getToken(DOTParser::STRICTT, 0);
}

DOTParser::IdContext* DOTParser::GraphContext::id() {
  return getRuleContext<DOTParser::IdContext>(0);
}


size_t DOTParser::GraphContext::getRuleIndex() const {
  return DOTParser::RuleGraph;
}

void DOTParser::GraphContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGraph(this);
}

void DOTParser::GraphContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGraph(this);
}

DOTParser::GraphContext* DOTParser::graph() {
  GraphContext *_localctx = _tracker.createInstance<GraphContext>(_ctx, getState());
  enterRule(_localctx, 0, DOTParser::RuleGraph);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::STRICTT) {
      setState(30);
      match(DOTParser::STRICTT);
    }
    setState(33);
    _la = _input->LA(1);
    if (!(_la == DOTParser::GRAPH

    || _la == DOTParser::DIGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(35);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DOTParser::NUMBER)
      | (1ULL << DOTParser::STRING)
      | (1ULL << DOTParser::HTML_STRING)
      | (1ULL << DOTParser::ID))) != 0)) {
      setState(34);
      id();
    }
    setState(37);
    match(DOTParser::T__0);
    setState(38);
    stmt_list();
    setState(39);
    match(DOTParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stmt_listContext ------------------------------------------------------------------

DOTParser::Stmt_listContext::Stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::StmtContext *> DOTParser::Stmt_listContext::stmt() {
  return getRuleContexts<DOTParser::StmtContext>();
}

DOTParser::StmtContext* DOTParser::Stmt_listContext::stmt(size_t i) {
  return getRuleContext<DOTParser::StmtContext>(i);
}


size_t DOTParser::Stmt_listContext::getRuleIndex() const {
  return DOTParser::RuleStmt_list;
}

void DOTParser::Stmt_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_list(this);
}

void DOTParser::Stmt_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_list(this);
}

DOTParser::Stmt_listContext* DOTParser::stmt_list() {
  Stmt_listContext *_localctx = _tracker.createInstance<Stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 2, DOTParser::RuleStmt_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DOTParser::T__0)
      | (1ULL << DOTParser::GRAPH)
      | (1ULL << DOTParser::NODE)
      | (1ULL << DOTParser::EDGE)
      | (1ULL << DOTParser::SUBGRAPH)
      | (1ULL << DOTParser::NUMBER)
      | (1ULL << DOTParser::STRING)
      | (1ULL << DOTParser::HTML_STRING)
      | (1ULL << DOTParser::ID))) != 0)) {
      setState(41);
      stmt();
      setState(43);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DOTParser::T__2) {
        setState(42);
        match(DOTParser::T__2);
      }
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

DOTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Node_stmtContext* DOTParser::StmtContext::node_stmt() {
  return getRuleContext<DOTParser::Node_stmtContext>(0);
}

DOTParser::Edge_stmtContext* DOTParser::StmtContext::edge_stmt() {
  return getRuleContext<DOTParser::Edge_stmtContext>(0);
}

DOTParser::Attr_stmtContext* DOTParser::StmtContext::attr_stmt() {
  return getRuleContext<DOTParser::Attr_stmtContext>(0);
}

std::vector<DOTParser::IdContext *> DOTParser::StmtContext::id() {
  return getRuleContexts<DOTParser::IdContext>();
}

DOTParser::IdContext* DOTParser::StmtContext::id(size_t i) {
  return getRuleContext<DOTParser::IdContext>(i);
}

DOTParser::SubgraphContext* DOTParser::StmtContext::subgraph() {
  return getRuleContext<DOTParser::SubgraphContext>(0);
}


size_t DOTParser::StmtContext::getRuleIndex() const {
  return DOTParser::RuleStmt;
}

void DOTParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void DOTParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

DOTParser::StmtContext* DOTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 4, DOTParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(58);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(50);
      node_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(51);
      edge_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(52);
      attr_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(53);
      id();
      setState(54);
      match(DOTParser::T__3);
      setState(55);
      id();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(57);
      subgraph();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_stmtContext ------------------------------------------------------------------

DOTParser::Attr_stmtContext::Attr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Attr_listContext* DOTParser::Attr_stmtContext::attr_list() {
  return getRuleContext<DOTParser::Attr_listContext>(0);
}

tree::TerminalNode* DOTParser::Attr_stmtContext::GRAPH() {
  return getToken(DOTParser::GRAPH, 0);
}

tree::TerminalNode* DOTParser::Attr_stmtContext::NODE() {
  return getToken(DOTParser::NODE, 0);
}

tree::TerminalNode* DOTParser::Attr_stmtContext::EDGE() {
  return getToken(DOTParser::EDGE, 0);
}


size_t DOTParser::Attr_stmtContext::getRuleIndex() const {
  return DOTParser::RuleAttr_stmt;
}

void DOTParser::Attr_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_stmt(this);
}

void DOTParser::Attr_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_stmt(this);
}

DOTParser::Attr_stmtContext* DOTParser::attr_stmt() {
  Attr_stmtContext *_localctx = _tracker.createInstance<Attr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, DOTParser::RuleAttr_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DOTParser::GRAPH)
      | (1ULL << DOTParser::NODE)
      | (1ULL << DOTParser::EDGE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(61);
    attr_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_listContext ------------------------------------------------------------------

DOTParser::Attr_listContext::Attr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::A_listContext *> DOTParser::Attr_listContext::a_list() {
  return getRuleContexts<DOTParser::A_listContext>();
}

DOTParser::A_listContext* DOTParser::Attr_listContext::a_list(size_t i) {
  return getRuleContext<DOTParser::A_listContext>(i);
}


size_t DOTParser::Attr_listContext::getRuleIndex() const {
  return DOTParser::RuleAttr_list;
}

void DOTParser::Attr_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_list(this);
}

void DOTParser::Attr_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_list(this);
}

DOTParser::Attr_listContext* DOTParser::attr_list() {
  Attr_listContext *_localctx = _tracker.createInstance<Attr_listContext>(_ctx, getState());
  enterRule(_localctx, 8, DOTParser::RuleAttr_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(63);
      match(DOTParser::T__4);
      setState(65);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DOTParser::NUMBER)
        | (1ULL << DOTParser::STRING)
        | (1ULL << DOTParser::HTML_STRING)
        | (1ULL << DOTParser::ID))) != 0)) {
        setState(64);
        a_list();
      }
      setState(67);
      match(DOTParser::T__5);
      setState(70); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- A_listContext ------------------------------------------------------------------

DOTParser::A_listContext::A_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::IdContext *> DOTParser::A_listContext::id() {
  return getRuleContexts<DOTParser::IdContext>();
}

DOTParser::IdContext* DOTParser::A_listContext::id(size_t i) {
  return getRuleContext<DOTParser::IdContext>(i);
}


size_t DOTParser::A_listContext::getRuleIndex() const {
  return DOTParser::RuleA_list;
}

void DOTParser::A_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterA_list(this);
}

void DOTParser::A_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitA_list(this);
}

DOTParser::A_listContext* DOTParser::a_list() {
  A_listContext *_localctx = _tracker.createInstance<A_listContext>(_ctx, getState());
  enterRule(_localctx, 10, DOTParser::RuleA_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(72);
      id();
      setState(75);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DOTParser::T__3) {
        setState(73);
        match(DOTParser::T__3);
        setState(74);
        id();
      }
      setState(78);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DOTParser::T__6) {
        setState(77);
        match(DOTParser::T__6);
      }
      setState(82); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DOTParser::NUMBER)
      | (1ULL << DOTParser::STRING)
      | (1ULL << DOTParser::HTML_STRING)
      | (1ULL << DOTParser::ID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Edge_stmtContext ------------------------------------------------------------------

DOTParser::Edge_stmtContext::Edge_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::EdgeRHSContext* DOTParser::Edge_stmtContext::edgeRHS() {
  return getRuleContext<DOTParser::EdgeRHSContext>(0);
}

DOTParser::Node_idContext* DOTParser::Edge_stmtContext::node_id() {
  return getRuleContext<DOTParser::Node_idContext>(0);
}

DOTParser::SubgraphContext* DOTParser::Edge_stmtContext::subgraph() {
  return getRuleContext<DOTParser::SubgraphContext>(0);
}

DOTParser::Attr_listContext* DOTParser::Edge_stmtContext::attr_list() {
  return getRuleContext<DOTParser::Attr_listContext>(0);
}


size_t DOTParser::Edge_stmtContext::getRuleIndex() const {
  return DOTParser::RuleEdge_stmt;
}

void DOTParser::Edge_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge_stmt(this);
}

void DOTParser::Edge_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge_stmt(this);
}

DOTParser::Edge_stmtContext* DOTParser::edge_stmt() {
  Edge_stmtContext *_localctx = _tracker.createInstance<Edge_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, DOTParser::RuleEdge_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DOTParser::NUMBER:
      case DOTParser::STRING:
      case DOTParser::HTML_STRING:
      case DOTParser::ID: {
        setState(84);
        node_id();
        break;
      }

      case DOTParser::T__0:
      case DOTParser::SUBGRAPH: {
        setState(85);
        subgraph();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(88);
    edgeRHS();
    setState(90);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__4) {
      setState(89);
      attr_list();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeRHSContext ------------------------------------------------------------------

DOTParser::EdgeRHSContext::EdgeRHSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::EdgeopContext *> DOTParser::EdgeRHSContext::edgeop() {
  return getRuleContexts<DOTParser::EdgeopContext>();
}

DOTParser::EdgeopContext* DOTParser::EdgeRHSContext::edgeop(size_t i) {
  return getRuleContext<DOTParser::EdgeopContext>(i);
}

std::vector<DOTParser::Node_idContext *> DOTParser::EdgeRHSContext::node_id() {
  return getRuleContexts<DOTParser::Node_idContext>();
}

DOTParser::Node_idContext* DOTParser::EdgeRHSContext::node_id(size_t i) {
  return getRuleContext<DOTParser::Node_idContext>(i);
}

std::vector<DOTParser::SubgraphContext *> DOTParser::EdgeRHSContext::subgraph() {
  return getRuleContexts<DOTParser::SubgraphContext>();
}

DOTParser::SubgraphContext* DOTParser::EdgeRHSContext::subgraph(size_t i) {
  return getRuleContext<DOTParser::SubgraphContext>(i);
}


size_t DOTParser::EdgeRHSContext::getRuleIndex() const {
  return DOTParser::RuleEdgeRHS;
}

void DOTParser::EdgeRHSContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdgeRHS(this);
}

void DOTParser::EdgeRHSContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdgeRHS(this);
}

DOTParser::EdgeRHSContext* DOTParser::edgeRHS() {
  EdgeRHSContext *_localctx = _tracker.createInstance<EdgeRHSContext>(_ctx, getState());
  enterRule(_localctx, 14, DOTParser::RuleEdgeRHS);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(92);
      edgeop();
      setState(95);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DOTParser::NUMBER:
        case DOTParser::STRING:
        case DOTParser::HTML_STRING:
        case DOTParser::ID: {
          setState(93);
          node_id();
          break;
        }

        case DOTParser::T__0:
        case DOTParser::SUBGRAPH: {
          setState(94);
          subgraph();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(99); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__7

    || _la == DOTParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeopContext ------------------------------------------------------------------

DOTParser::EdgeopContext::EdgeopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DOTParser::EdgeopContext::getRuleIndex() const {
  return DOTParser::RuleEdgeop;
}

void DOTParser::EdgeopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdgeop(this);
}

void DOTParser::EdgeopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdgeop(this);
}

DOTParser::EdgeopContext* DOTParser::edgeop() {
  EdgeopContext *_localctx = _tracker.createInstance<EdgeopContext>(_ctx, getState());
  enterRule(_localctx, 16, DOTParser::RuleEdgeop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    _la = _input->LA(1);
    if (!(_la == DOTParser::T__7

    || _la == DOTParser::T__8)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_stmtContext ------------------------------------------------------------------

DOTParser::Node_stmtContext::Node_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Node_idContext* DOTParser::Node_stmtContext::node_id() {
  return getRuleContext<DOTParser::Node_idContext>(0);
}

DOTParser::Attr_listContext* DOTParser::Node_stmtContext::attr_list() {
  return getRuleContext<DOTParser::Attr_listContext>(0);
}


size_t DOTParser::Node_stmtContext::getRuleIndex() const {
  return DOTParser::RuleNode_stmt;
}

void DOTParser::Node_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_stmt(this);
}

void DOTParser::Node_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_stmt(this);
}

DOTParser::Node_stmtContext* DOTParser::node_stmt() {
  Node_stmtContext *_localctx = _tracker.createInstance<Node_stmtContext>(_ctx, getState());
  enterRule(_localctx, 18, DOTParser::RuleNode_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    node_id();
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__4) {
      setState(104);
      attr_list();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_idContext ------------------------------------------------------------------

DOTParser::Node_idContext::Node_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::IdContext* DOTParser::Node_idContext::id() {
  return getRuleContext<DOTParser::IdContext>(0);
}

DOTParser::PortContext* DOTParser::Node_idContext::port() {
  return getRuleContext<DOTParser::PortContext>(0);
}


size_t DOTParser::Node_idContext::getRuleIndex() const {
  return DOTParser::RuleNode_id;
}

void DOTParser::Node_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_id(this);
}

void DOTParser::Node_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_id(this);
}

DOTParser::Node_idContext* DOTParser::node_id() {
  Node_idContext *_localctx = _tracker.createInstance<Node_idContext>(_ctx, getState());
  enterRule(_localctx, 20, DOTParser::RuleNode_id);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    id();
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__9) {
      setState(108);
      port();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortContext ------------------------------------------------------------------

DOTParser::PortContext::PortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::IdContext* DOTParser::PortContext::id() {
  return getRuleContext<DOTParser::IdContext>(0);
}

DOTParser::Compass_ptContext* DOTParser::PortContext::compass_pt() {
  return getRuleContext<DOTParser::Compass_ptContext>(0);
}


size_t DOTParser::PortContext::getRuleIndex() const {
  return DOTParser::RulePort;
}

void DOTParser::PortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPort(this);
}

void DOTParser::PortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPort(this);
}

DOTParser::PortContext* DOTParser::port() {
  PortContext *_localctx = _tracker.createInstance<PortContext>(_ctx, getState());
  enterRule(_localctx, 22, DOTParser::RulePort);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      match(DOTParser::T__9);
      setState(112);
      id();
      setState(115);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DOTParser::T__9) {
        setState(113);
        match(DOTParser::T__9);
        setState(114);
        compass_pt();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(117);
      match(DOTParser::T__9);
      setState(118);
      compass_pt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubgraphContext ------------------------------------------------------------------

DOTParser::SubgraphContext::SubgraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Stmt_listContext* DOTParser::SubgraphContext::stmt_list() {
  return getRuleContext<DOTParser::Stmt_listContext>(0);
}

tree::TerminalNode* DOTParser::SubgraphContext::SUBGRAPH() {
  return getToken(DOTParser::SUBGRAPH, 0);
}

DOTParser::IdContext* DOTParser::SubgraphContext::id() {
  return getRuleContext<DOTParser::IdContext>(0);
}


size_t DOTParser::SubgraphContext::getRuleIndex() const {
  return DOTParser::RuleSubgraph;
}

void DOTParser::SubgraphContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubgraph(this);
}

void DOTParser::SubgraphContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubgraph(this);
}

DOTParser::SubgraphContext* DOTParser::subgraph() {
  SubgraphContext *_localctx = _tracker.createInstance<SubgraphContext>(_ctx, getState());
  enterRule(_localctx, 24, DOTParser::RuleSubgraph);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::SUBGRAPH) {
      setState(121);
      match(DOTParser::SUBGRAPH);
      setState(123);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DOTParser::NUMBER)
        | (1ULL << DOTParser::STRING)
        | (1ULL << DOTParser::HTML_STRING)
        | (1ULL << DOTParser::ID))) != 0)) {
        setState(122);
        id();
      }
    }
    setState(127);
    match(DOTParser::T__0);
    setState(128);
    stmt_list();
    setState(129);
    match(DOTParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compass_ptContext ------------------------------------------------------------------

DOTParser::Compass_ptContext::Compass_ptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Compass_ptContext::ID() {
  return getToken(DOTParser::ID, 0);
}


size_t DOTParser::Compass_ptContext::getRuleIndex() const {
  return DOTParser::RuleCompass_pt;
}

void DOTParser::Compass_ptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompass_pt(this);
}

void DOTParser::Compass_ptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompass_pt(this);
}

DOTParser::Compass_ptContext* DOTParser::compass_pt() {
  Compass_ptContext *_localctx = _tracker.createInstance<Compass_ptContext>(_ctx, getState());
  enterRule(_localctx, 26, DOTParser::RuleCompass_pt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    _la = _input->LA(1);
    if (!(_la == DOTParser::T__10

    || _la == DOTParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdContext ------------------------------------------------------------------

DOTParser::IdContext::IdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::IdContext::ID() {
  return getToken(DOTParser::ID, 0);
}

tree::TerminalNode* DOTParser::IdContext::STRING() {
  return getToken(DOTParser::STRING, 0);
}

tree::TerminalNode* DOTParser::IdContext::HTML_STRING() {
  return getToken(DOTParser::HTML_STRING, 0);
}

tree::TerminalNode* DOTParser::IdContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::IdContext::getRuleIndex() const {
  return DOTParser::RuleId;
}

void DOTParser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}

void DOTParser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}

DOTParser::IdContext* DOTParser::id() {
  IdContext *_localctx = _tracker.createInstance<IdContext>(_ctx, getState());
  enterRule(_localctx, 28, DOTParser::RuleId);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DOTParser::NUMBER)
      | (1ULL << DOTParser::STRING)
      | (1ULL << DOTParser::HTML_STRING)
      | (1ULL << DOTParser::ID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> DOTParser::_decisionToDFA;
atn::PredictionContextCache DOTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DOTParser::_atn;
std::vector<uint16_t> DOTParser::_serializedATN;

std::vector<std::string> DOTParser::_ruleNames = {
  "graph", "stmt_list", "stmt", "attr_stmt", "attr_list", "a_list", "edge_stmt", 
  "edgeRHS", "edgeop", "node_stmt", "node_id", "port", "subgraph", "compass_pt", 
  "id"
};

std::vector<std::string> DOTParser::_literalNames = {
  "", "'{'", "'}'", "';'", "'='", "'['", "']'", "','", "'->'", "'--'", "':'", 
  "'_'"
};

std::vector<std::string> DOTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "STRICTT", "GRAPH", "DIGRAPH", 
  "NODE", "EDGE", "SUBGRAPH", "NUMBER", "STRING", "HTML_STRING", "TAG", 
  "EntityRef", "ID", "COMMENT", "LINE_COMMENT", "PREPROC", "WS"
};

dfa::Vocabulary DOTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DOTParser::_tokenNames;

DOTParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1d, 0x8a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x5, 0x2, 0x22, 0xa, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x26, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2e, 0xa, 0x3, 0x7, 
    0x3, 0x30, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x33, 0xb, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x3d, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x44, 0xa, 0x6, 0x3, 0x6, 0x6, 0x6, 0x47, 0xa, 0x6, 0xd, 0x6, 
    0xe, 0x6, 0x48, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x4e, 0xa, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x51, 0xa, 0x7, 0x6, 0x7, 0x53, 0xa, 0x7, 0xd, 0x7, 
    0xe, 0x7, 0x54, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x59, 0xa, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x5d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x62, 0xa, 0x9, 0x6, 0x9, 0x64, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x65, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x6c, 0xa, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0x70, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0x76, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x7a, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x7e, 0xa, 0xe, 0x5, 0xe, 0x80, 
    0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x2, 0x11, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 
    0x7, 0x3, 0x2, 0xf, 0x10, 0x4, 0x2, 0xf, 0xf, 0x11, 0x12, 0x3, 0x2, 
    0xa, 0xb, 0x4, 0x2, 0xd, 0xd, 0x19, 0x19, 0x4, 0x2, 0x14, 0x16, 0x19, 
    0x19, 0x2, 0x91, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x46, 0x3, 0x2, 0x2, 0x2, 0xc, 0x52, 0x3, 0x2, 0x2, 0x2, 0xe, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x63, 0x3, 0x2, 0x2, 0x2, 0x12, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x69, 0x3, 0x2, 0x2, 0x2, 0x16, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x85, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x22, 0x7, 0xe, 0x2, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x25, 
    0x9, 0x2, 0x2, 0x2, 0x24, 0x26, 0x5, 0x1e, 0x10, 0x2, 0x25, 0x24, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x28, 0x7, 0x3, 0x2, 0x2, 0x28, 0x29, 0x5, 0x4, 0x3, 
    0x2, 0x29, 0x2a, 0x7, 0x4, 0x2, 0x2, 0x2a, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x2b, 0x2d, 0x5, 0x6, 0x4, 0x2, 0x2c, 0x2e, 0x7, 0x5, 0x2, 0x2, 0x2d, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x5, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x3d, 0x5, 0x14, 0xb, 0x2, 0x35, 0x3d, 0x5, 0xe, 0x8, 0x2, 
    0x36, 0x3d, 0x5, 0x8, 0x5, 0x2, 0x37, 0x38, 0x5, 0x1e, 0x10, 0x2, 0x38, 
    0x39, 0x7, 0x6, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x1e, 0x10, 0x2, 0x3a, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x1a, 0xe, 0x2, 0x3c, 0x34, 0x3, 
    0x2, 0x2, 0x2, 0x3c, 0x35, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x9, 0x3, 0x2, 0x2, 
    0x3f, 0x40, 0x5, 0xa, 0x6, 0x2, 0x40, 0x9, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x43, 0x7, 0x7, 0x2, 0x2, 0x42, 0x44, 0x5, 0xc, 0x7, 0x2, 0x43, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x47, 0x7, 0x8, 0x2, 0x2, 0x46, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4d, 0x5, 0x1e, 0x10, 0x2, 0x4b, 0x4c, 0x7, 0x6, 0x2, 0x2, 0x4c, 
    0x4e, 0x5, 0x1e, 0x10, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x7, 
    0x9, 0x2, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 0x52, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0xd, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x59, 0x5, 0x16, 0xc, 0x2, 0x57, 0x59, 0x5, 0x1a, 0xe, 0x2, 0x58, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x10, 0x9, 0x2, 0x5b, 0x5d, 0x5, 0xa, 
    0x6, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x5, 0x12, 0xa, 0x2, 
    0x5f, 0x62, 0x5, 0x16, 0xc, 0x2, 0x60, 0x62, 0x5, 0x1a, 0xe, 0x2, 0x61, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x63, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x11, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x9, 0x4, 0x2, 
    0x2, 0x68, 0x13, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x16, 0xc, 0x2, 
    0x6a, 0x6c, 0x5, 0xa, 0x6, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x15, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 
    0x5, 0x1e, 0x10, 0x2, 0x6e, 0x70, 0x5, 0x18, 0xd, 0x2, 0x6f, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x72, 0x7, 0xc, 0x2, 0x2, 0x72, 0x75, 0x5, 0x1e, 0x10, 
    0x2, 0x73, 0x74, 0x7, 0xc, 0x2, 0x2, 0x74, 0x76, 0x5, 0x1c, 0xf, 0x2, 
    0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0xc, 0x2, 0x2, 0x78, 0x7a, 
    0x5, 0x1c, 0xf, 0x2, 0x79, 0x71, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0x7, 0x13, 
    0x2, 0x2, 0x7c, 0x7e, 0x5, 0x1e, 0x10, 0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0x3, 0x2, 0x2, 0x82, 0x83, 
    0x5, 0x4, 0x3, 0x2, 0x83, 0x84, 0x7, 0x4, 0x2, 0x2, 0x84, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x85, 0x86, 0x9, 0x5, 0x2, 0x2, 0x86, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x87, 0x88, 0x9, 0x6, 0x2, 0x2, 0x88, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x21, 0x25, 0x2d, 0x31, 0x3c, 0x43, 0x48, 0x4d, 0x50, 0x54, 
    0x58, 0x5c, 0x61, 0x65, 0x6b, 0x6f, 0x75, 0x79, 0x7d, 0x7f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DOTParser::Initializer DOTParser::_init;
