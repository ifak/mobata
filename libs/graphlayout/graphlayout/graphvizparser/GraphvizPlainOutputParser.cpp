
// Generated from /mnt/diskdata/SWDevelop/mobata/libs/graphlayout/graphvizparser/grammars/GraphvizPlainOutput.g4 by ANTLR 4.7


#include "GraphvizPlainOutputListener.h"

#include "GraphvizPlainOutputParser.h"


#include <stdexcept>

#define QT_NO_KEYWORDS
#include "graphvizgraph.hpp"
#undef QT_NO_KEYWORDS


using namespace antlrcpp;
using namespace antlr4;

GraphvizPlainOutputParser::GraphvizPlainOutputParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GraphvizPlainOutputParser::~GraphvizPlainOutputParser() {
  delete _interpreter;
}

std::string GraphvizPlainOutputParser::getGrammarFileName() const {
  return "GraphvizPlainOutput.g4";
}

const std::vector<std::string>& GraphvizPlainOutputParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GraphvizPlainOutputParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- GraphvizPlainOutputContext ------------------------------------------------------------------

GraphvizPlainOutputParser::GraphvizPlainOutputContext::GraphvizPlainOutputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GraphvizPlainOutputParser::GraphContext* GraphvizPlainOutputParser::GraphvizPlainOutputContext::graph() {
  return getRuleContext<GraphvizPlainOutputParser::GraphContext>(0);
}

GraphvizPlainOutputParser::StopContext* GraphvizPlainOutputParser::GraphvizPlainOutputContext::stop() {
  return getRuleContext<GraphvizPlainOutputParser::StopContext>(0);
}

std::vector<GraphvizPlainOutputParser::NodeContext *> GraphvizPlainOutputParser::GraphvizPlainOutputContext::node() {
  return getRuleContexts<GraphvizPlainOutputParser::NodeContext>();
}

GraphvizPlainOutputParser::NodeContext* GraphvizPlainOutputParser::GraphvizPlainOutputContext::node(size_t i) {
  return getRuleContext<GraphvizPlainOutputParser::NodeContext>(i);
}

std::vector<GraphvizPlainOutputParser::EdgeContext *> GraphvizPlainOutputParser::GraphvizPlainOutputContext::edge() {
  return getRuleContexts<GraphvizPlainOutputParser::EdgeContext>();
}

GraphvizPlainOutputParser::EdgeContext* GraphvizPlainOutputParser::GraphvizPlainOutputContext::edge(size_t i) {
  return getRuleContext<GraphvizPlainOutputParser::EdgeContext>(i);
}


size_t GraphvizPlainOutputParser::GraphvizPlainOutputContext::getRuleIndex() const {
  return GraphvizPlainOutputParser::RuleGraphvizPlainOutput;
}

void GraphvizPlainOutputParser::GraphvizPlainOutputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGraphvizPlainOutput(this);
}

void GraphvizPlainOutputParser::GraphvizPlainOutputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGraphvizPlainOutput(this);
}

GraphvizPlainOutputParser::GraphvizPlainOutputContext* GraphvizPlainOutputParser::graphvizPlainOutput() {
  GraphvizPlainOutputContext *_localctx = _tracker.createInstance<GraphvizPlainOutputContext>(_ctx, getState());
  enterRule(_localctx, 0, GraphvizPlainOutputParser::RuleGraphvizPlainOutput);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    graph();
    setState(18);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GraphvizPlainOutputParser::NodeID) {
      setState(15);
      node();
      setState(20);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GraphvizPlainOutputParser::EdgeID) {
      setState(21);
      edge();
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(27);
    stop();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GraphContext ------------------------------------------------------------------

GraphvizPlainOutputParser::GraphContext::GraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GraphvizPlainOutputParser::GraphContext::NUMBER() {
  return getTokens(GraphvizPlainOutputParser::NUMBER);
}

tree::TerminalNode* GraphvizPlainOutputParser::GraphContext::NUMBER(size_t i) {
  return getToken(GraphvizPlainOutputParser::NUMBER, i);
}


size_t GraphvizPlainOutputParser::GraphContext::getRuleIndex() const {
  return GraphvizPlainOutputParser::RuleGraph;
}

void GraphvizPlainOutputParser::GraphContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGraph(this);
}

void GraphvizPlainOutputParser::GraphContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGraph(this);
}

GraphvizPlainOutputParser::GraphContext* GraphvizPlainOutputParser::graph() {
  GraphContext *_localctx = _tracker.createInstance<GraphContext>(_ctx, getState());
  enterRule(_localctx, 2, GraphvizPlainOutputParser::RuleGraph);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(GraphvizPlainOutputParser::GraphID);
    setState(30);
    match(GraphvizPlainOutputParser::NUMBER);
    setState(31);
    match(GraphvizPlainOutputParser::NUMBER);
    setState(32);
    match(GraphvizPlainOutputParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeContext ------------------------------------------------------------------

GraphvizPlainOutputParser::NodeContext::NodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GraphvizPlainOutputParser::NodeContext::ID() {
  return getTokens(GraphvizPlainOutputParser::ID);
}

tree::TerminalNode* GraphvizPlainOutputParser::NodeContext::ID(size_t i) {
  return getToken(GraphvizPlainOutputParser::ID, i);
}

std::vector<tree::TerminalNode *> GraphvizPlainOutputParser::NodeContext::NUMBER() {
  return getTokens(GraphvizPlainOutputParser::NUMBER);
}

tree::TerminalNode* GraphvizPlainOutputParser::NodeContext::NUMBER(size_t i) {
  return getToken(GraphvizPlainOutputParser::NUMBER, i);
}

GraphvizPlainOutputParser::TextRuleContext* GraphvizPlainOutputParser::NodeContext::textRule() {
  return getRuleContext<GraphvizPlainOutputParser::TextRuleContext>(0);
}


size_t GraphvizPlainOutputParser::NodeContext::getRuleIndex() const {
  return GraphvizPlainOutputParser::RuleNode;
}

void GraphvizPlainOutputParser::NodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode(this);
}

void GraphvizPlainOutputParser::NodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode(this);
}

GraphvizPlainOutputParser::NodeContext* GraphvizPlainOutputParser::node() {
  NodeContext *_localctx = _tracker.createInstance<NodeContext>(_ctx, getState());
  enterRule(_localctx, 4, GraphvizPlainOutputParser::RuleNode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    graphvizparser::GraphvizNode newNode;
    setState(35);
    match(GraphvizPlainOutputParser::NodeID);
    setState(36);
    dynamic_cast<NodeContext *>(_localctx)->name = match(GraphvizPlainOutputParser::ID);
    setState(37);
    dynamic_cast<NodeContext *>(_localctx)->x = match(GraphvizPlainOutputParser::NUMBER);
    setState(38);
    dynamic_cast<NodeContext *>(_localctx)->y = match(GraphvizPlainOutputParser::NUMBER);
    setState(39);
    dynamic_cast<NodeContext *>(_localctx)->w = match(GraphvizPlainOutputParser::NUMBER);
    setState(40);
    dynamic_cast<NodeContext *>(_localctx)->h = match(GraphvizPlainOutputParser::NUMBER);

             newNode.setName(QString::fromStdString((dynamic_cast<NodeContext *>(_localctx)->name != nullptr ? dynamic_cast<NodeContext *>(_localctx)->name->getText() : "")));
             newNode.setPos(QString::fromStdString((dynamic_cast<NodeContext *>(_localctx)->x != nullptr ? dynamic_cast<NodeContext *>(_localctx)->x->getText() : "")).toDouble(),
                                   QString::fromStdString((dynamic_cast<NodeContext *>(_localctx)->y != nullptr ? dynamic_cast<NodeContext *>(_localctx)->y->getText() : "")).toDouble());
             newNode.setWidth(QString::fromStdString((dynamic_cast<NodeContext *>(_localctx)->w != nullptr ? dynamic_cast<NodeContext *>(_localctx)->w->getText() : "")).toDouble());
             newNode.setHeight(QString::fromStdString((dynamic_cast<NodeContext *>(_localctx)->h != nullptr ? dynamic_cast<NodeContext *>(_localctx)->h->getText() : "")).toDouble());
           
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GraphvizPlainOutputParser::T__0: {
        setState(42);
        match(GraphvizPlainOutputParser::T__0);
        setState(43);
        dynamic_cast<NodeContext *>(_localctx)->labelString = textRule();
        setState(44);
        match(GraphvizPlainOutputParser::T__0);
        newNode.setLabel(QString::fromStdString((dynamic_cast<NodeContext *>(_localctx)->labelString != nullptr ? _input->getText(dynamic_cast<NodeContext *>(_localctx)->labelString->start, dynamic_cast<NodeContext *>(_localctx)->labelString->stop) : nullptr)));
        break;
      }

      case GraphvizPlainOutputParser::ID: {
        setState(47);
        dynamic_cast<NodeContext *>(_localctx)->labelID = match(GraphvizPlainOutputParser::ID);
        newNode.setLabel(QString::fromStdString((dynamic_cast<NodeContext *>(_localctx)->labelID != nullptr ? dynamic_cast<NodeContext *>(_localctx)->labelID->getText() : "")));
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(51);
    dynamic_cast<NodeContext *>(_localctx)->style = match(GraphvizPlainOutputParser::ID);
    setState(52);
    dynamic_cast<NodeContext *>(_localctx)->shape = match(GraphvizPlainOutputParser::ID);
    setState(53);
    dynamic_cast<NodeContext *>(_localctx)->color = match(GraphvizPlainOutputParser::ID);
    setState(54);
    dynamic_cast<NodeContext *>(_localctx)->fillcolor = match(GraphvizPlainOutputParser::ID);
    this->_graphvizGraph->addNode(newNode);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeContext ------------------------------------------------------------------

GraphvizPlainOutputParser::EdgeContext::EdgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GraphvizPlainOutputParser::EdgeContext::ID() {
  return getTokens(GraphvizPlainOutputParser::ID);
}

tree::TerminalNode* GraphvizPlainOutputParser::EdgeContext::ID(size_t i) {
  return getToken(GraphvizPlainOutputParser::ID, i);
}

std::vector<tree::TerminalNode *> GraphvizPlainOutputParser::EdgeContext::NUMBER() {
  return getTokens(GraphvizPlainOutputParser::NUMBER);
}

tree::TerminalNode* GraphvizPlainOutputParser::EdgeContext::NUMBER(size_t i) {
  return getToken(GraphvizPlainOutputParser::NUMBER, i);
}

GraphvizPlainOutputParser::TextRuleContext* GraphvizPlainOutputParser::EdgeContext::textRule() {
  return getRuleContext<GraphvizPlainOutputParser::TextRuleContext>(0);
}


size_t GraphvizPlainOutputParser::EdgeContext::getRuleIndex() const {
  return GraphvizPlainOutputParser::RuleEdge;
}

void GraphvizPlainOutputParser::EdgeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge(this);
}

void GraphvizPlainOutputParser::EdgeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge(this);
}

GraphvizPlainOutputParser::EdgeContext* GraphvizPlainOutputParser::edge() {
  EdgeContext *_localctx = _tracker.createInstance<EdgeContext>(_ctx, getState());
  enterRule(_localctx, 6, GraphvizPlainOutputParser::RuleEdge);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    graphvizparser::GraphvizEdge newEdge;
    setState(58);
    match(GraphvizPlainOutputParser::EdgeID);
    setState(59);
    dynamic_cast<EdgeContext *>(_localctx)->from = match(GraphvizPlainOutputParser::ID);
    setState(60);
    dynamic_cast<EdgeContext *>(_localctx)->to = match(GraphvizPlainOutputParser::ID);
    newEdge.setFrom(QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->from != nullptr ? dynamic_cast<EdgeContext *>(_localctx)->from->getText() : "")));
            newEdge.setTo(QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->to != nullptr ? dynamic_cast<EdgeContext *>(_localctx)->to->getText() : "")));
    setState(62);
    dynamic_cast<EdgeContext *>(_localctx)->points_count = match(GraphvizPlainOutputParser::NUMBER);
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GraphvizPlainOutputParser::NUMBER) {
      setState(63);
      dynamic_cast<EdgeContext *>(_localctx)->x = match(GraphvizPlainOutputParser::NUMBER);
      setState(64);
      dynamic_cast<EdgeContext *>(_localctx)->y = match(GraphvizPlainOutputParser::NUMBER);
      newEdge.addPoint(QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->x != nullptr ? dynamic_cast<EdgeContext *>(_localctx)->x->getText() : "")).toDouble(),
                                  QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->y != nullptr ? dynamic_cast<EdgeContext *>(_localctx)->y->getText() : "")).toDouble());
                
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(83);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(78);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case GraphvizPlainOutputParser::T__0: {
          setState(71);
          match(GraphvizPlainOutputParser::T__0);
          setState(72);
          dynamic_cast<EdgeContext *>(_localctx)->labelString = textRule();
          setState(73);
          match(GraphvizPlainOutputParser::T__0);
          newEdge.setLabel(QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->labelString != nullptr ? _input->getText(dynamic_cast<EdgeContext *>(_localctx)->labelString->start, dynamic_cast<EdgeContext *>(_localctx)->labelString->stop) : nullptr)));
          break;
        }

        case GraphvizPlainOutputParser::ID: {
          setState(76);
          dynamic_cast<EdgeContext *>(_localctx)->labelID = match(GraphvizPlainOutputParser::ID);
          newEdge.setLabel(QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->labelID != nullptr ? dynamic_cast<EdgeContext *>(_localctx)->labelID->getText() : "")));
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(80);
      dynamic_cast<EdgeContext *>(_localctx)->x_label = match(GraphvizPlainOutputParser::NUMBER);
      setState(81);
      dynamic_cast<EdgeContext *>(_localctx)->y_label = match(GraphvizPlainOutputParser::NUMBER);

                   newEdge.setLabelPos(QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->x_label != nullptr ? dynamic_cast<EdgeContext *>(_localctx)->x_label->getText() : "")).toDouble(),
                                       QString::fromStdString((dynamic_cast<EdgeContext *>(_localctx)->y_label != nullptr ? dynamic_cast<EdgeContext *>(_localctx)->y_label->getText() : "")).toDouble());
                
      break;
    }

    }
    setState(85);
    dynamic_cast<EdgeContext *>(_localctx)->style = match(GraphvizPlainOutputParser::ID);
    setState(86);
    dynamic_cast<EdgeContext *>(_localctx)->color = match(GraphvizPlainOutputParser::ID);
    this->_graphvizGraph->addEdge(newEdge);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

GraphvizPlainOutputParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GraphvizPlainOutputParser::TextRuleContext* GraphvizPlainOutputParser::StringContext::textRule() {
  return getRuleContext<GraphvizPlainOutputParser::TextRuleContext>(0);
}


size_t GraphvizPlainOutputParser::StringContext::getRuleIndex() const {
  return GraphvizPlainOutputParser::RuleString;
}

void GraphvizPlainOutputParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void GraphvizPlainOutputParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

GraphvizPlainOutputParser::StringContext* GraphvizPlainOutputParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 8, GraphvizPlainOutputParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(GraphvizPlainOutputParser::T__0);
    setState(90);
    textRule();
    setState(91);
    match(GraphvizPlainOutputParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TextRuleContext ------------------------------------------------------------------

GraphvizPlainOutputParser::TextRuleContext::TextRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GraphvizPlainOutputParser::TextRuleContext::getRuleIndex() const {
  return GraphvizPlainOutputParser::RuleTextRule;
}

void GraphvizPlainOutputParser::TextRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTextRule(this);
}

void GraphvizPlainOutputParser::TextRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTextRule(this);
}

GraphvizPlainOutputParser::TextRuleContext* GraphvizPlainOutputParser::textRule() {
  TextRuleContext *_localctx = _tracker.createInstance<TextRuleContext>(_ctx, getState());
  enterRule(_localctx, 10, GraphvizPlainOutputParser::RuleTextRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(101);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(99);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(93);
          matchWildcard();
          break;
        }

        case 2: {
          setState(94);
          match(GraphvizPlainOutputParser::T__1);
          break;
        }

        case 3: {
          setState(95);
          match(GraphvizPlainOutputParser::T__2);
          break;
        }

        case 4: {
          setState(96);
          match(GraphvizPlainOutputParser::T__3);
          break;
        }

        case 5: {
          setState(97);
          match(GraphvizPlainOutputParser::T__4);
          break;
        }

        case 6: {
          setState(98);
          match(GraphvizPlainOutputParser::T__5);
          break;
        }

        } 
      }
      setState(103);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StopContext ------------------------------------------------------------------

GraphvizPlainOutputParser::StopContext::StopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GraphvizPlainOutputParser::StopContext::getRuleIndex() const {
  return GraphvizPlainOutputParser::RuleStop;
}

void GraphvizPlainOutputParser::StopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStop(this);
}

void GraphvizPlainOutputParser::StopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphvizPlainOutputListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStop(this);
}

GraphvizPlainOutputParser::StopContext* GraphvizPlainOutputParser::stop() {
  StopContext *_localctx = _tracker.createInstance<StopContext>(_ctx, getState());
  enterRule(_localctx, 12, GraphvizPlainOutputParser::RuleStop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(GraphvizPlainOutputParser::StopID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> GraphvizPlainOutputParser::_decisionToDFA;
atn::PredictionContextCache GraphvizPlainOutputParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GraphvizPlainOutputParser::_atn;
std::vector<uint16_t> GraphvizPlainOutputParser::_serializedATN;

std::vector<std::string> GraphvizPlainOutputParser::_ruleNames = {
  "graphvizPlainOutput", "graph", "node", "edge", "string", "textRule", 
  "stop"
};

std::vector<std::string> GraphvizPlainOutputParser::_literalNames = {
  "", "'\"'", "':'", "'['", "']'", "'/'", "';'", "'graph'", "'node'", "'edge'", 
  "'stop'"
};

std::vector<std::string> GraphvizPlainOutputParser::_symbolicNames = {
  "", "", "", "", "", "", "", "GraphID", "NodeID", "EdgeID", "StopID", "ID", 
  "WS", "NUMBER"
};

dfa::Vocabulary GraphvizPlainOutputParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GraphvizPlainOutputParser::_tokenNames;

GraphvizPlainOutputParser::Initializer::Initializer() {
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
    0x3, 0xf, 0x6d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x13, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x16, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x19, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x1c, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x34, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x45, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x48, 0xb, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x51, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x56, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x66, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x69, 0xb, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x67, 0x2, 0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x2, 0x2, 0x2, 0x71, 0x2, 0x10, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x24, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x5b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x14, 0x5, 0x4, 0x3, 0x2, 0x11, 
    0x13, 0x5, 0x6, 0x4, 0x2, 0x12, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x16, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x15, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x16, 0x14, 0x3, 0x2, 
    0x2, 0x2, 0x17, 0x19, 0x5, 0x8, 0x5, 0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x5, 0xe, 0x8, 0x2, 0x1e, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x9, 0x2, 0x2, 0x20, 0x21, 0x7, 
    0xf, 0x2, 0x2, 0x21, 0x22, 0x7, 0xf, 0x2, 0x2, 0x22, 0x23, 0x7, 0xf, 
    0x2, 0x2, 0x23, 0x5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x8, 0x4, 0x1, 
    0x2, 0x25, 0x26, 0x7, 0xa, 0x2, 0x2, 0x26, 0x27, 0x7, 0xd, 0x2, 0x2, 
    0x27, 0x28, 0x7, 0xf, 0x2, 0x2, 0x28, 0x29, 0x7, 0xf, 0x2, 0x2, 0x29, 
    0x2a, 0x7, 0xf, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0xf, 0x2, 0x2, 0x2b, 0x33, 
    0x8, 0x4, 0x1, 0x2, 0x2c, 0x2d, 0x7, 0x3, 0x2, 0x2, 0x2d, 0x2e, 0x5, 
    0xc, 0x7, 0x2, 0x2e, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2f, 0x30, 0x8, 0x4, 
    0x1, 0x2, 0x30, 0x34, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0xd, 0x2, 
    0x2, 0x32, 0x34, 0x8, 0x4, 0x1, 0x2, 0x33, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x36, 0x7, 0xd, 0x2, 0x2, 0x36, 0x37, 0x7, 0xd, 0x2, 0x2, 0x37, 0x38, 
    0x7, 0xd, 0x2, 0x2, 0x38, 0x39, 0x7, 0xd, 0x2, 0x2, 0x39, 0x3a, 0x8, 
    0x4, 0x1, 0x2, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x8, 0x5, 
    0x1, 0x2, 0x3c, 0x3d, 0x7, 0xb, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0xd, 0x2, 
    0x2, 0x3e, 0x3f, 0x7, 0xd, 0x2, 0x2, 0x3f, 0x40, 0x8, 0x5, 0x1, 0x2, 
    0x40, 0x46, 0x7, 0xf, 0x2, 0x2, 0x41, 0x42, 0x7, 0xf, 0x2, 0x2, 0x42, 
    0x43, 0x7, 0xf, 0x2, 0x2, 0x43, 0x45, 0x8, 0x5, 0x1, 0x2, 0x44, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x3, 0x2, 
    0x2, 0x4a, 0x4b, 0x5, 0xc, 0x7, 0x2, 0x4b, 0x4c, 0x7, 0x3, 0x2, 0x2, 
    0x4c, 0x4d, 0x8, 0x5, 0x1, 0x2, 0x4d, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x4f, 0x7, 0xd, 0x2, 0x2, 0x4f, 0x51, 0x8, 0x5, 0x1, 0x2, 0x50, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0xf, 0x2, 0x2, 0x53, 0x54, 0x7, 0xf, 
    0x2, 0x2, 0x54, 0x56, 0x8, 0x5, 0x1, 0x2, 0x55, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x7, 0xd, 0x2, 0x2, 0x58, 0x59, 0x7, 0xd, 0x2, 0x2, 0x59, 
    0x5a, 0x8, 0x5, 0x1, 0x2, 0x5a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 
    0x7, 0x3, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0xc, 0x7, 0x2, 0x5d, 0x5e, 0x7, 
    0x3, 0x2, 0x2, 0x5e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x66, 0xb, 0x2, 
    0x2, 0x2, 0x60, 0x66, 0x7, 0x4, 0x2, 0x2, 0x61, 0x66, 0x7, 0x5, 0x2, 
    0x2, 0x62, 0x66, 0x7, 0x6, 0x2, 0x2, 0x63, 0x66, 0x7, 0x7, 0x2, 0x2, 
    0x64, 0x66, 0x7, 0x8, 0x2, 0x2, 0x65, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x65, 0x61, 0x3, 0x2, 0x2, 0x2, 0x65, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0xc, 0x2, 0x2, 
    0x6b, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa, 0x14, 0x1a, 0x33, 0x46, 0x50, 0x55, 
    0x65, 0x67, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GraphvizPlainOutputParser::Initializer GraphvizPlainOutputParser::_init;
