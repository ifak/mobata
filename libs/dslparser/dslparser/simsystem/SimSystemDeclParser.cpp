
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/SimSystemDecl.g4 by ANTLR 4.7.2


#include "SimSystemDeclListener.h"

#include "SimSystemDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

SimSystemDeclParser::SimSystemDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SimSystemDeclParser::~SimSystemDeclParser() {
  delete _interpreter;
}

std::string SimSystemDeclParser::getGrammarFileName() const {
  return "SimSystemDecl.g4";
}

const std::vector<std::string>& SimSystemDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SimSystemDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SimSystemDeclContext ------------------------------------------------------------------

SimSystemDeclParser::SimSystemDeclContext::SimSystemDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::ImportPathDeclContext* SimSystemDeclParser::SimSystemDeclContext::importPathDecl() {
  return getRuleContext<SimSystemDeclParser::ImportPathDeclContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SimSystemDeclContext::SimSystemID() {
  return getToken(SimSystemDeclParser::SimSystemID, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::SimSystemDeclContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SimSystemDeclContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

SimSystemDeclParser::SimSystemBodyContext* SimSystemDeclParser::SimSystemDeclContext::simSystemBody() {
  return getRuleContext<SimSystemDeclParser::SimSystemBodyContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SimSystemDeclContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}


size_t SimSystemDeclParser::SimSystemDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSimSystemDecl;
}

void SimSystemDeclParser::SimSystemDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimSystemDecl(this);
}

void SimSystemDeclParser::SimSystemDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimSystemDecl(this);
}

SimSystemDeclParser::SimSystemDeclContext* SimSystemDeclParser::simSystemDecl() {
  SimSystemDeclContext *_localctx = _tracker.createInstance<SimSystemDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, SimSystemDeclParser::RuleSimSystemDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    importPathDecl();
    setState(145);
    match(SimSystemDeclParser::SimSystemID);
    setState(146);
    contextID();
    setState(147);
    match(SimSystemDeclParser::LBRACE);
    setState(148);
    simSystemBody();
    setState(149);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimSystemBodyContext ------------------------------------------------------------------

SimSystemDeclParser::SimSystemBodyContext::SimSystemBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::ConnectionDeclContext* SimSystemDeclParser::SimSystemBodyContext::connectionDecl() {
  return getRuleContext<SimSystemDeclParser::ConnectionDeclContext>(0);
}

SimSystemDeclParser::ConfigDeclContext* SimSystemDeclParser::SimSystemBodyContext::configDecl() {
  return getRuleContext<SimSystemDeclParser::ConfigDeclContext>(0);
}


size_t SimSystemDeclParser::SimSystemBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSimSystemBody;
}

void SimSystemDeclParser::SimSystemBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimSystemBody(this);
}

void SimSystemDeclParser::SimSystemBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimSystemBody(this);
}

SimSystemDeclParser::SimSystemBodyContext* SimSystemDeclParser::simSystemBody() {
  SimSystemBodyContext *_localctx = _tracker.createInstance<SimSystemBodyContext>(_ctx, getState());
  enterRule(_localctx, 2, SimSystemDeclParser::RuleSimSystemBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    connectionDecl();
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ConfigID: {
        setState(152);
        configDecl();
        break;
      }

      case SimSystemDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConnectionDeclContext ------------------------------------------------------------------

SimSystemDeclParser::ConnectionDeclContext::ConnectionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ConnectionDeclContext::ConnectionID() {
  return getToken(SimSystemDeclParser::ConnectionID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ConnectionDeclContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

SimSystemDeclParser::ConnectionBodyContext* SimSystemDeclParser::ConnectionDeclContext::connectionBody() {
  return getRuleContext<SimSystemDeclParser::ConnectionBodyContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ConnectionDeclContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}


size_t SimSystemDeclParser::ConnectionDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleConnectionDecl;
}

void SimSystemDeclParser::ConnectionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConnectionDecl(this);
}

void SimSystemDeclParser::ConnectionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConnectionDecl(this);
}

SimSystemDeclParser::ConnectionDeclContext* SimSystemDeclParser::connectionDecl() {
  ConnectionDeclContext *_localctx = _tracker.createInstance<ConnectionDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SimSystemDeclParser::RuleConnectionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(SimSystemDeclParser::ConnectionID);
    setState(157);
    match(SimSystemDeclParser::LBRACE);
    setState(158);
    connectionBody();
    setState(159);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConnectionBodyContext ------------------------------------------------------------------

SimSystemDeclParser::ConnectionBodyContext::ConnectionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::ComponentIdPathContext *> SimSystemDeclParser::ConnectionBodyContext::componentIdPath() {
  return getRuleContexts<SimSystemDeclParser::ComponentIdPathContext>();
}

SimSystemDeclParser::ComponentIdPathContext* SimSystemDeclParser::ConnectionBodyContext::componentIdPath(size_t i) {
  return getRuleContext<SimSystemDeclParser::ComponentIdPathContext>(i);
}

tree::TerminalNode* SimSystemDeclParser::ConnectionBodyContext::DoubleArrow() {
  return getToken(SimSystemDeclParser::DoubleArrow, 0);
}

tree::TerminalNode* SimSystemDeclParser::ConnectionBodyContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::ConnectionBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleConnectionBody;
}

void SimSystemDeclParser::ConnectionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConnectionBody(this);
}

void SimSystemDeclParser::ConnectionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConnectionBody(this);
}

SimSystemDeclParser::ConnectionBodyContext* SimSystemDeclParser::connectionBody() {
  ConnectionBodyContext *_localctx = _tracker.createInstance<ConnectionBodyContext>(_ctx, getState());
  enterRule(_localctx, 6, SimSystemDeclParser::RuleConnectionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    componentIdPath();
    setState(162);
    match(SimSystemDeclParser::DoubleArrow);
    setState(163);
    componentIdPath();
    setState(164);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigDeclContext ------------------------------------------------------------------

SimSystemDeclParser::ConfigDeclContext::ConfigDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ConfigDeclContext::ConfigID() {
  return getToken(SimSystemDeclParser::ConfigID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ConfigDeclContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

SimSystemDeclParser::ConfigBodyContext* SimSystemDeclParser::ConfigDeclContext::configBody() {
  return getRuleContext<SimSystemDeclParser::ConfigBodyContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ConfigDeclContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}


size_t SimSystemDeclParser::ConfigDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleConfigDecl;
}

void SimSystemDeclParser::ConfigDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigDecl(this);
}

void SimSystemDeclParser::ConfigDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigDecl(this);
}

SimSystemDeclParser::ConfigDeclContext* SimSystemDeclParser::configDecl() {
  ConfigDeclContext *_localctx = _tracker.createInstance<ConfigDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, SimSystemDeclParser::RuleConfigDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(SimSystemDeclParser::ConfigID);
    setState(167);
    match(SimSystemDeclParser::LBRACE);
    setState(168);
    configBody();
    setState(169);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigBodyContext ------------------------------------------------------------------

SimSystemDeclParser::ConfigBodyContext::ConfigBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::ActorDeclContext* SimSystemDeclParser::ConfigBodyContext::actorDecl() {
  return getRuleContext<SimSystemDeclParser::ActorDeclContext>(0);
}

SimSystemDeclParser::StartSequenceDeclContext* SimSystemDeclParser::ConfigBodyContext::startSequenceDecl() {
  return getRuleContext<SimSystemDeclParser::StartSequenceDeclContext>(0);
}

SimSystemDeclParser::StartupDeclContext* SimSystemDeclParser::ConfigBodyContext::startupDecl() {
  return getRuleContext<SimSystemDeclParser::StartupDeclContext>(0);
}


size_t SimSystemDeclParser::ConfigBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleConfigBody;
}

void SimSystemDeclParser::ConfigBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigBody(this);
}

void SimSystemDeclParser::ConfigBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigBody(this);
}

SimSystemDeclParser::ConfigBodyContext* SimSystemDeclParser::configBody() {
  ConfigBodyContext *_localctx = _tracker.createInstance<ConfigBodyContext>(_ctx, getState());
  enterRule(_localctx, 10, SimSystemDeclParser::RuleConfigBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ActorID: {
        setState(171);
        actorDecl();
        break;
      }

      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::StartSequenceID: {
        setState(175);
        startSequenceDecl();
        break;
      }

      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::StartupID: {
        setState(179);
        startupDecl();
        break;
      }

      case SimSystemDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActorDeclContext ------------------------------------------------------------------

SimSystemDeclParser::ActorDeclContext::ActorDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::ActorDeclBodyContext *> SimSystemDeclParser::ActorDeclContext::actorDeclBody() {
  return getRuleContexts<SimSystemDeclParser::ActorDeclBodyContext>();
}

SimSystemDeclParser::ActorDeclBodyContext* SimSystemDeclParser::ActorDeclContext::actorDeclBody(size_t i) {
  return getRuleContext<SimSystemDeclParser::ActorDeclBodyContext>(i);
}


size_t SimSystemDeclParser::ActorDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleActorDecl;
}

void SimSystemDeclParser::ActorDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActorDecl(this);
}

void SimSystemDeclParser::ActorDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActorDecl(this);
}

SimSystemDeclParser::ActorDeclContext* SimSystemDeclParser::actorDecl() {
  ActorDeclContext *_localctx = _tracker.createInstance<ActorDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, SimSystemDeclParser::RuleActorDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(183);
      actorDeclBody();
      setState(186); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SimSystemDeclParser::ActorID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActorDeclBodyContext ------------------------------------------------------------------

SimSystemDeclParser::ActorDeclBodyContext::ActorDeclBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ActorDeclBodyContext::ActorID() {
  return getToken(SimSystemDeclParser::ActorID, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::ActorDeclBodyContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ActorDeclBodyContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

tree::TerminalNode* SimSystemDeclParser::ActorDeclBodyContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}

SimSystemDeclParser::ActorBodyContentContext* SimSystemDeclParser::ActorDeclBodyContext::actorBodyContent() {
  return getRuleContext<SimSystemDeclParser::ActorBodyContentContext>(0);
}


size_t SimSystemDeclParser::ActorDeclBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleActorDeclBody;
}

void SimSystemDeclParser::ActorDeclBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActorDeclBody(this);
}

void SimSystemDeclParser::ActorDeclBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActorDeclBody(this);
}

SimSystemDeclParser::ActorDeclBodyContext* SimSystemDeclParser::actorDeclBody() {
  ActorDeclBodyContext *_localctx = _tracker.createInstance<ActorDeclBodyContext>(_ctx, getState());
  enterRule(_localctx, 14, SimSystemDeclParser::RuleActorDeclBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(SimSystemDeclParser::ActorID);
    setState(189);
    contextID();
    setState(190);
    match(SimSystemDeclParser::LBRACE);
    setState(193);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::PortID: {
        setState(191);
        actorBodyContent();
        break;
      }

      case SimSystemDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(195);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActorBodyContentContext ------------------------------------------------------------------

SimSystemDeclParser::ActorBodyContentContext::ActorBodyContentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::PortDeclContext *> SimSystemDeclParser::ActorBodyContentContext::portDecl() {
  return getRuleContexts<SimSystemDeclParser::PortDeclContext>();
}

SimSystemDeclParser::PortDeclContext* SimSystemDeclParser::ActorBodyContentContext::portDecl(size_t i) {
  return getRuleContext<SimSystemDeclParser::PortDeclContext>(i);
}


size_t SimSystemDeclParser::ActorBodyContentContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleActorBodyContent;
}

void SimSystemDeclParser::ActorBodyContentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActorBodyContent(this);
}

void SimSystemDeclParser::ActorBodyContentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActorBodyContent(this);
}

SimSystemDeclParser::ActorBodyContentContext* SimSystemDeclParser::actorBodyContent() {
  ActorBodyContentContext *_localctx = _tracker.createInstance<ActorBodyContentContext>(_ctx, getState());
  enterRule(_localctx, 16, SimSystemDeclParser::RuleActorBodyContent);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(197);
      portDecl();
      setState(200); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SimSystemDeclParser::PortID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartupDeclContext ------------------------------------------------------------------

SimSystemDeclParser::StartupDeclContext::StartupDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::StartupDeclContext::StartupID() {
  return getToken(SimSystemDeclParser::StartupID, 0);
}

tree::TerminalNode* SimSystemDeclParser::StartupDeclContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

SimSystemDeclParser::StartupBodyContext* SimSystemDeclParser::StartupDeclContext::startupBody() {
  return getRuleContext<SimSystemDeclParser::StartupBodyContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::StartupDeclContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}


size_t SimSystemDeclParser::StartupDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleStartupDecl;
}

void SimSystemDeclParser::StartupDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartupDecl(this);
}

void SimSystemDeclParser::StartupDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartupDecl(this);
}

SimSystemDeclParser::StartupDeclContext* SimSystemDeclParser::startupDecl() {
  StartupDeclContext *_localctx = _tracker.createInstance<StartupDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, SimSystemDeclParser::RuleStartupDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(SimSystemDeclParser::StartupID);
    setState(203);
    match(SimSystemDeclParser::LBRACE);
    setState(204);
    startupBody();
    setState(205);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartupBodyContext ------------------------------------------------------------------

SimSystemDeclParser::StartupBodyContext::StartupBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::MessageDeclOptionalContext* SimSystemDeclParser::StartupBodyContext::messageDeclOptional() {
  return getRuleContext<SimSystemDeclParser::MessageDeclOptionalContext>(0);
}


size_t SimSystemDeclParser::StartupBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleStartupBody;
}

void SimSystemDeclParser::StartupBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartupBody(this);
}

void SimSystemDeclParser::StartupBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartupBody(this);
}

SimSystemDeclParser::StartupBodyContext* SimSystemDeclParser::startupBody() {
  StartupBodyContext *_localctx = _tracker.createInstance<StartupBodyContext>(_ctx, getState());
  enterRule(_localctx, 20, SimSystemDeclParser::RuleStartupBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    messageDeclOptional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MessageDeclOptionalContext ------------------------------------------------------------------

SimSystemDeclParser::MessageDeclOptionalContext::MessageDeclOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::MessageDeclContext* SimSystemDeclParser::MessageDeclOptionalContext::messageDecl() {
  return getRuleContext<SimSystemDeclParser::MessageDeclContext>(0);
}

SimSystemDeclParser::MessageDeclOptionalContext* SimSystemDeclParser::MessageDeclOptionalContext::messageDeclOptional() {
  return getRuleContext<SimSystemDeclParser::MessageDeclOptionalContext>(0);
}


size_t SimSystemDeclParser::MessageDeclOptionalContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleMessageDeclOptional;
}

void SimSystemDeclParser::MessageDeclOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageDeclOptional(this);
}

void SimSystemDeclParser::MessageDeclOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageDeclOptional(this);
}

SimSystemDeclParser::MessageDeclOptionalContext* SimSystemDeclParser::messageDeclOptional() {
  MessageDeclOptionalContext *_localctx = _tracker.createInstance<MessageDeclOptionalContext>(_ctx, getState());
  enterRule(_localctx, 22, SimSystemDeclParser::RuleMessageDeclOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::MessageID: {
        enterOuterAlt(_localctx, 1);
        setState(209);
        messageDecl();
        setState(210);
        messageDeclOptional();
        break;
      }

      case SimSystemDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MessageDeclContext ------------------------------------------------------------------

SimSystemDeclParser::MessageDeclContext::MessageDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::MessageDeclContext::MessageID() {
  return getToken(SimSystemDeclParser::MessageID, 0);
}

tree::TerminalNode* SimSystemDeclParser::MessageDeclContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

std::vector<SimSystemDeclParser::ComponentIdPathContext *> SimSystemDeclParser::MessageDeclContext::componentIdPath() {
  return getRuleContexts<SimSystemDeclParser::ComponentIdPathContext>();
}

SimSystemDeclParser::ComponentIdPathContext* SimSystemDeclParser::MessageDeclContext::componentIdPath(size_t i) {
  return getRuleContext<SimSystemDeclParser::ComponentIdPathContext>(i);
}

tree::TerminalNode* SimSystemDeclParser::MessageDeclContext::RightArrow() {
  return getToken(SimSystemDeclParser::RightArrow, 0);
}

tree::TerminalNode* SimSystemDeclParser::MessageDeclContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}

tree::TerminalNode* SimSystemDeclParser::MessageDeclContext::COLON() {
  return getToken(SimSystemDeclParser::COLON, 0);
}

SimSystemDeclParser::MessageSignalContext* SimSystemDeclParser::MessageDeclContext::messageSignal() {
  return getRuleContext<SimSystemDeclParser::MessageSignalContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::MessageDeclContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::MessageDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleMessageDecl;
}

void SimSystemDeclParser::MessageDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageDecl(this);
}

void SimSystemDeclParser::MessageDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageDecl(this);
}

SimSystemDeclParser::MessageDeclContext* SimSystemDeclParser::messageDecl() {
  MessageDeclContext *_localctx = _tracker.createInstance<MessageDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, SimSystemDeclParser::RuleMessageDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(SimSystemDeclParser::MessageID);
    setState(216);
    match(SimSystemDeclParser::LPAREN);
    setState(217);
    componentIdPath();
    setState(218);
    match(SimSystemDeclParser::RightArrow);
    setState(219);
    componentIdPath();
    setState(220);
    match(SimSystemDeclParser::RPAREN);
    setState(221);
    match(SimSystemDeclParser::COLON);
    setState(222);
    messageSignal();
    setState(223);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MessageSignalContext ------------------------------------------------------------------

SimSystemDeclParser::MessageSignalContext::MessageSignalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::SignalIdPathContext* SimSystemDeclParser::MessageSignalContext::signalIdPath() {
  return getRuleContext<SimSystemDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::MessageSignalContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

tree::TerminalNode* SimSystemDeclParser::MessageSignalContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}

std::vector<SimSystemDeclParser::MessageParamValueContext *> SimSystemDeclParser::MessageSignalContext::messageParamValue() {
  return getRuleContexts<SimSystemDeclParser::MessageParamValueContext>();
}

SimSystemDeclParser::MessageParamValueContext* SimSystemDeclParser::MessageSignalContext::messageParamValue(size_t i) {
  return getRuleContext<SimSystemDeclParser::MessageParamValueContext>(i);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::MessageSignalContext::COMMA() {
  return getTokens(SimSystemDeclParser::COMMA);
}

tree::TerminalNode* SimSystemDeclParser::MessageSignalContext::COMMA(size_t i) {
  return getToken(SimSystemDeclParser::COMMA, i);
}


size_t SimSystemDeclParser::MessageSignalContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleMessageSignal;
}

void SimSystemDeclParser::MessageSignalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageSignal(this);
}

void SimSystemDeclParser::MessageSignalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageSignal(this);
}

SimSystemDeclParser::MessageSignalContext* SimSystemDeclParser::messageSignal() {
  MessageSignalContext *_localctx = _tracker.createInstance<MessageSignalContext>(_ctx, getState());
  enterRule(_localctx, 26, SimSystemDeclParser::RuleMessageSignal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    signalIdPath();
    setState(226);
    match(SimSystemDeclParser::LPAREN);
    setState(236);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::TrueID:
      case SimSystemDeclParser::FalseID:
      case SimSystemDeclParser::INT:
      case SimSystemDeclParser::REAL:
      case SimSystemDeclParser::STRING:
      case SimSystemDeclParser::ID: {
        setState(227);
        messageParamValue();
        setState(232);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimSystemDeclParser::COMMA) {
          setState(228);
          match(SimSystemDeclParser::COMMA);
          setState(229);
          messageParamValue();
          setState(234);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SimSystemDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(238);
    match(SimSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MessageParamValueContext ------------------------------------------------------------------

SimSystemDeclParser::MessageParamValueContext::MessageParamValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::LiteralValueContext* SimSystemDeclParser::MessageParamValueContext::literalValue() {
  return getRuleContext<SimSystemDeclParser::LiteralValueContext>(0);
}


size_t SimSystemDeclParser::MessageParamValueContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleMessageParamValue;
}

void SimSystemDeclParser::MessageParamValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageParamValue(this);
}

void SimSystemDeclParser::MessageParamValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageParamValue(this);
}

SimSystemDeclParser::MessageParamValueContext* SimSystemDeclParser::messageParamValue() {
  MessageParamValueContext *_localctx = _tracker.createInstance<MessageParamValueContext>(_ctx, getState());
  enterRule(_localctx, 28, SimSystemDeclParser::RuleMessageParamValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    literalValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartSequenceDeclContext ------------------------------------------------------------------

SimSystemDeclParser::StartSequenceDeclContext::StartSequenceDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::StartSequenceDeclContext::StartSequenceID() {
  return getToken(SimSystemDeclParser::StartSequenceID, 0);
}

tree::TerminalNode* SimSystemDeclParser::StartSequenceDeclContext::COLON() {
  return getToken(SimSystemDeclParser::COLON, 0);
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::StartSequenceDeclContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::StartSequenceDeclContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* SimSystemDeclParser::StartSequenceDeclContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::StartSequenceDeclContext::COMMA() {
  return getTokens(SimSystemDeclParser::COMMA);
}

tree::TerminalNode* SimSystemDeclParser::StartSequenceDeclContext::COMMA(size_t i) {
  return getToken(SimSystemDeclParser::COMMA, i);
}


size_t SimSystemDeclParser::StartSequenceDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleStartSequenceDecl;
}

void SimSystemDeclParser::StartSequenceDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartSequenceDecl(this);
}

void SimSystemDeclParser::StartSequenceDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartSequenceDecl(this);
}

SimSystemDeclParser::StartSequenceDeclContext* SimSystemDeclParser::startSequenceDecl() {
  StartSequenceDeclContext *_localctx = _tracker.createInstance<StartSequenceDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, SimSystemDeclParser::RuleStartSequenceDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    match(SimSystemDeclParser::StartSequenceID);
    setState(243);
    match(SimSystemDeclParser::COLON);
    setState(244);
    contextID();
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::COMMA) {
      setState(245);
      match(SimSystemDeclParser::COMMA);
      setState(246);
      contextID();
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(252);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextIDContext ------------------------------------------------------------------

SimSystemDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::ID() {
  return getToken(SimSystemDeclParser::ID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::NameID() {
  return getToken(SimSystemDeclParser::NameID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::LabelID() {
  return getToken(SimSystemDeclParser::LabelID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::EnabledID() {
  return getToken(SimSystemDeclParser::EnabledID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::TypeID() {
  return getToken(SimSystemDeclParser::TypeID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::AttributeID() {
  return getToken(SimSystemDeclParser::AttributeID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::SignalID() {
  return getToken(SimSystemDeclParser::SignalID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::PortID() {
  return getToken(SimSystemDeclParser::PortID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::ImportID() {
  return getToken(SimSystemDeclParser::ImportID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::FromID() {
  return getToken(SimSystemDeclParser::FromID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::ToID() {
  return getToken(SimSystemDeclParser::ToID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::AsID() {
  return getToken(SimSystemDeclParser::AsID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::ActorID() {
  return getToken(SimSystemDeclParser::ActorID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::SimSystemID() {
  return getToken(SimSystemDeclParser::SimSystemID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::ConnectionID() {
  return getToken(SimSystemDeclParser::ConnectionID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::ConfigID() {
  return getToken(SimSystemDeclParser::ConfigID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::StartupID() {
  return getToken(SimSystemDeclParser::StartupID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::MessageID() {
  return getToken(SimSystemDeclParser::MessageID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ContextIDContext::StartSequenceID() {
  return getToken(SimSystemDeclParser::StartSequenceID, 0);
}


size_t SimSystemDeclParser::ContextIDContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleContextID;
}

void SimSystemDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void SimSystemDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 32, SimSystemDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimSystemDeclParser::ActorID)
      | (1ULL << SimSystemDeclParser::SimSystemID)
      | (1ULL << SimSystemDeclParser::ConnectionID)
      | (1ULL << SimSystemDeclParser::ConfigID)
      | (1ULL << SimSystemDeclParser::StartupID)
      | (1ULL << SimSystemDeclParser::MessageID)
      | (1ULL << SimSystemDeclParser::StartSequenceID)
      | (1ULL << SimSystemDeclParser::NameID)
      | (1ULL << SimSystemDeclParser::LabelID)
      | (1ULL << SimSystemDeclParser::EnabledID)
      | (1ULL << SimSystemDeclParser::TypeID)
      | (1ULL << SimSystemDeclParser::AttributeID)
      | (1ULL << SimSystemDeclParser::SignalID)
      | (1ULL << SimSystemDeclParser::PortID)
      | (1ULL << SimSystemDeclParser::ImportID)
      | (1ULL << SimSystemDeclParser::FromID)
      | (1ULL << SimSystemDeclParser::ToID)
      | (1ULL << SimSystemDeclParser::AsID)
      | (1ULL << SimSystemDeclParser::ID))) != 0))) {
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

//----------------- ComponentIdPathContext ------------------------------------------------------------------

SimSystemDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(SimSystemDeclParser::DOT);
}

tree::TerminalNode* SimSystemDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(SimSystemDeclParser::DOT, i);
}


size_t SimSystemDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleComponentIdPath;
}

void SimSystemDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void SimSystemDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

SimSystemDeclParser::ComponentIdPathContext* SimSystemDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 34, SimSystemDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    contextID();
    setState(261);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::DOT) {
      setState(257);
      match(SimSystemDeclParser::DOT);
      setState(258);
      contextID();
      setState(263);
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

//----------------- SignalIdPathContext ------------------------------------------------------------------

SimSystemDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::SignalIdPathContext::DOT() {
  return getTokens(SimSystemDeclParser::DOT);
}

tree::TerminalNode* SimSystemDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(SimSystemDeclParser::DOT, i);
}


size_t SimSystemDeclParser::SignalIdPathContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSignalIdPath;
}

void SimSystemDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void SimSystemDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

SimSystemDeclParser::SignalIdPathContext* SimSystemDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 36, SimSystemDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    contextID();
    setState(269);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::DOT) {
      setState(265);
      match(SimSystemDeclParser::DOT);
      setState(266);
      contextID();
      setState(271);
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

//----------------- AttributeIdPathContext ------------------------------------------------------------------

SimSystemDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::AttributeNameContext* SimSystemDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<SimSystemDeclParser::AttributeNameContext>(0);
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(SimSystemDeclParser::DOT);
}

tree::TerminalNode* SimSystemDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(SimSystemDeclParser::DOT, i);
}


size_t SimSystemDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleAttributeIdPath;
}

void SimSystemDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void SimSystemDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

SimSystemDeclParser::AttributeIdPathContext* SimSystemDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 38, SimSystemDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(272);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(273);
      contextID();
      setState(278);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SimSystemDeclParser::DOT) {
        setState(274);
        match(SimSystemDeclParser::DOT);
        setState(275);
        contextID();
        setState(280);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
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

//----------------- SignalSendContext ------------------------------------------------------------------

SimSystemDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::SignalIdPathContext* SimSystemDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<SimSystemDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SignalSendContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

SimSystemDeclParser::FunctionCallBodyContext* SimSystemDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<SimSystemDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SignalSendContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}


size_t SimSystemDeclParser::SignalSendContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSignalSend;
}

void SimSystemDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void SimSystemDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

SimSystemDeclParser::SignalSendContext* SimSystemDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 40, SimSystemDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    signalIdPath();
    setState(284);
    match(SimSystemDeclParser::LPAREN);
    setState(285);
    functionCallBody();
    setState(286);
    match(SimSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

SimSystemDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::TypeDefDeclContext *> SimSystemDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<SimSystemDeclParser::TypeDefDeclContext>();
}

SimSystemDeclParser::TypeDefDeclContext* SimSystemDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<SimSystemDeclParser::TypeDefDeclContext>(i);
}

std::vector<SimSystemDeclParser::AttributeDeclContext *> SimSystemDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<SimSystemDeclParser::AttributeDeclContext>();
}

SimSystemDeclParser::AttributeDeclContext* SimSystemDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<SimSystemDeclParser::AttributeDeclContext>(i);
}

std::vector<SimSystemDeclParser::SignalDeclContext *> SimSystemDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<SimSystemDeclParser::SignalDeclContext>();
}

SimSystemDeclParser::SignalDeclContext* SimSystemDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<SimSystemDeclParser::SignalDeclContext>(i);
}


size_t SimSystemDeclParser::CommonDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleCommonDecl;
}

void SimSystemDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void SimSystemDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

SimSystemDeclParser::CommonDeclContext* SimSystemDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 42, SimSystemDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimSystemDeclParser::TypeID)
      | (1ULL << SimSystemDeclParser::AttributeID)
      | (1ULL << SimSystemDeclParser::SignalID))) != 0)) {
      setState(291);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SimSystemDeclParser::TypeID: {
          setState(288);
          typeDefDecl();
          break;
        }

        case SimSystemDeclParser::AttributeID: {
          setState(289);
          attributeDecl();
          break;
        }

        case SimSystemDeclParser::SignalID: {
          setState(290);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(295);
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

//----------------- ImportPathDeclContext ------------------------------------------------------------------

SimSystemDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::ImportPathBodyContext* SimSystemDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<SimSystemDeclParser::ImportPathBodyContext>(0);
}

SimSystemDeclParser::ImportPathDeclContext* SimSystemDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<SimSystemDeclParser::ImportPathDeclContext>(0);
}


size_t SimSystemDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleImportPathDecl;
}

void SimSystemDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void SimSystemDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

SimSystemDeclParser::ImportPathDeclContext* SimSystemDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 44, SimSystemDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ImportID: {
        enterOuterAlt(_localctx, 1);
        setState(296);
        importPathBody();
        setState(297);
        importPathDecl();
        break;
      }

      case SimSystemDeclParser::SimSystemID: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportPathBodyContext ------------------------------------------------------------------

SimSystemDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(SimSystemDeclParser::ImportID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(SimSystemDeclParser::LESSTHAN, 0);
}

SimSystemDeclParser::ImportFileBodyContext* SimSystemDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<SimSystemDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(SimSystemDeclParser::GREATERTHAN, 0);
}

SimSystemDeclParser::ImportAsContext* SimSystemDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<SimSystemDeclParser::ImportAsContext>(0);
}


size_t SimSystemDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleImportPathBody;
}

void SimSystemDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void SimSystemDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

SimSystemDeclParser::ImportPathBodyContext* SimSystemDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 46, SimSystemDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(SimSystemDeclParser::ImportID);
    setState(303);
    match(SimSystemDeclParser::LESSTHAN);
    setState(304);
    importFileBody();
    setState(305);
    match(SimSystemDeclParser::GREATERTHAN);
    setState(306);
    importAs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportFileBodyContext ------------------------------------------------------------------

SimSystemDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* SimSystemDeclParser::ImportFileBodyContext::DOT() {
  return getToken(SimSystemDeclParser::DOT, 0);
}

tree::TerminalNode* SimSystemDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(SimSystemDeclParser::RANGE, 0);
}

tree::TerminalNode* SimSystemDeclParser::ImportFileBodyContext::DIV() {
  return getToken(SimSystemDeclParser::DIV, 0);
}

SimSystemDeclParser::ImportFileBodyContext* SimSystemDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<SimSystemDeclParser::ImportFileBodyContext>(0);
}


size_t SimSystemDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleImportFileBody;
}

void SimSystemDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void SimSystemDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

SimSystemDeclParser::ImportFileBodyContext* SimSystemDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 48, SimSystemDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(308);
      contextID();
      setState(309);
      match(SimSystemDeclParser::DOT);
      setState(310);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(312);
      match(SimSystemDeclParser::RANGE);
      setState(313);
      match(SimSystemDeclParser::DIV);
      setState(314);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(315);
      contextID();
      setState(316);
      match(SimSystemDeclParser::DIV);
      setState(317);
      importFileBody();
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

//----------------- ImportAsContext ------------------------------------------------------------------

SimSystemDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ImportAsContext::AsID() {
  return getToken(SimSystemDeclParser::AsID, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::ImportAsContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}


size_t SimSystemDeclParser::ImportAsContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleImportAs;
}

void SimSystemDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void SimSystemDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

SimSystemDeclParser::ImportAsContext* SimSystemDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 50, SimSystemDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(324);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(321);
        match(SimSystemDeclParser::AsID);
        setState(322);
        contextID();
        break;
      }

      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ImportID: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefDeclContext ------------------------------------------------------------------

SimSystemDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(SimSystemDeclParser::TypeID, 0);
}

SimSystemDeclParser::TypeDeclContext* SimSystemDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<SimSystemDeclParser::TypeDeclContext>(0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleTypeDefDecl;
}

void SimSystemDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void SimSystemDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

SimSystemDeclParser::TypeDefDeclContext* SimSystemDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, SimSystemDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    match(SimSystemDeclParser::TypeID);
    setState(327);
    typeDecl();
    setState(328);
    contextID();
    setState(329);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

SimSystemDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::IntTypeDeclContext* SimSystemDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<SimSystemDeclParser::IntTypeDeclContext>(0);
}

SimSystemDeclParser::RealTypeDeclContext* SimSystemDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<SimSystemDeclParser::RealTypeDeclContext>(0);
}

SimSystemDeclParser::EnumTypeDeclContext* SimSystemDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<SimSystemDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::TypeDeclContext::BoolID() {
  return getToken(SimSystemDeclParser::BoolID, 0);
}

tree::TerminalNode* SimSystemDeclParser::TypeDeclContext::StringID() {
  return getToken(SimSystemDeclParser::StringID, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}


size_t SimSystemDeclParser::TypeDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleTypeDecl;
}

void SimSystemDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void SimSystemDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

SimSystemDeclParser::TypeDeclContext* SimSystemDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 54, SimSystemDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(337);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(331);
        intTypeDecl();
        break;
      }

      case SimSystemDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(332);
        realTypeDecl();
        break;
      }

      case SimSystemDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(333);
        enumTypeDecl();
        break;
      }

      case SimSystemDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(334);
        match(SimSystemDeclParser::BoolID);
        break;
      }

      case SimSystemDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(335);
        match(SimSystemDeclParser::StringID);
        break;
      }

      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(336);
        contextID();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntTypeDeclContext ------------------------------------------------------------------

SimSystemDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::IntTypeDeclContext::IntID() {
  return getToken(SimSystemDeclParser::IntID, 0);
}

tree::TerminalNode* SimSystemDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::IntTypeDeclContext::INT() {
  return getTokens(SimSystemDeclParser::INT);
}

tree::TerminalNode* SimSystemDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(SimSystemDeclParser::INT, i);
}

tree::TerminalNode* SimSystemDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(SimSystemDeclParser::RANGE, 0);
}

tree::TerminalNode* SimSystemDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}


size_t SimSystemDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleIntTypeDecl;
}

void SimSystemDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void SimSystemDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

SimSystemDeclParser::IntTypeDeclContext* SimSystemDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 56, SimSystemDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    match(SimSystemDeclParser::IntID);
    setState(346);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::LPAREN: {
        setState(340);
        match(SimSystemDeclParser::LPAREN);
        setState(341);
        match(SimSystemDeclParser::INT);
        setState(342);
        match(SimSystemDeclParser::RANGE);
        setState(343);
        match(SimSystemDeclParser::INT);
        setState(344);
        match(SimSystemDeclParser::RPAREN);
        break;
      }

      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealTypeDeclContext ------------------------------------------------------------------

SimSystemDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::RealTypeDeclContext::RealID() {
  return getToken(SimSystemDeclParser::RealID, 0);
}

tree::TerminalNode* SimSystemDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(SimSystemDeclParser::REAL);
}

tree::TerminalNode* SimSystemDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(SimSystemDeclParser::REAL, i);
}

tree::TerminalNode* SimSystemDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(SimSystemDeclParser::RANGE, 0);
}

tree::TerminalNode* SimSystemDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}


size_t SimSystemDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleRealTypeDecl;
}

void SimSystemDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void SimSystemDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

SimSystemDeclParser::RealTypeDeclContext* SimSystemDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 58, SimSystemDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(SimSystemDeclParser::RealID);
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::LPAREN: {
        setState(349);
        match(SimSystemDeclParser::LPAREN);
        setState(350);
        match(SimSystemDeclParser::REAL);
        setState(351);
        match(SimSystemDeclParser::RANGE);
        setState(352);
        match(SimSystemDeclParser::REAL);
        setState(353);
        match(SimSystemDeclParser::RPAREN);
        break;
      }

      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumTypeDeclContext ------------------------------------------------------------------

SimSystemDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(SimSystemDeclParser::EnumID, 0);
}

tree::TerminalNode* SimSystemDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* SimSystemDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(SimSystemDeclParser::COMMA);
}

tree::TerminalNode* SimSystemDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(SimSystemDeclParser::COMMA, i);
}


size_t SimSystemDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleEnumTypeDecl;
}

void SimSystemDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void SimSystemDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

SimSystemDeclParser::EnumTypeDeclContext* SimSystemDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 60, SimSystemDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(SimSystemDeclParser::EnumID);
    setState(358);
    match(SimSystemDeclParser::LPAREN);
    setState(359);
    contextID();
    setState(364);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::COMMA) {
      setState(360);
      match(SimSystemDeclParser::COMMA);
      setState(361);
      contextID();
      setState(366);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(367);
    match(SimSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

SimSystemDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(SimSystemDeclParser::AttributeID, 0);
}

SimSystemDeclParser::TypeDeclContext* SimSystemDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<SimSystemDeclParser::TypeDeclContext>(0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::AttributeDeclContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* SimSystemDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(SimSystemDeclParser::ASSIGN, 0);
}

SimSystemDeclParser::LiteralValueContext* SimSystemDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<SimSystemDeclParser::LiteralValueContext>(0);
}


size_t SimSystemDeclParser::AttributeDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleAttributeDecl;
}

void SimSystemDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void SimSystemDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

SimSystemDeclParser::AttributeDeclContext* SimSystemDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 62, SimSystemDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(SimSystemDeclParser::AttributeID);
    setState(370);
    typeDecl();
    setState(371);
    contextID();
    setState(374);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimSystemDeclParser::ASSIGN) {
      setState(372);
      match(SimSystemDeclParser::ASSIGN);
      setState(373);
      literalValue();
    }
    setState(376);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

SimSystemDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::LiteralValueContext::INT() {
  return getToken(SimSystemDeclParser::INT, 0);
}

tree::TerminalNode* SimSystemDeclParser::LiteralValueContext::REAL() {
  return getToken(SimSystemDeclParser::REAL, 0);
}

tree::TerminalNode* SimSystemDeclParser::LiteralValueContext::STRING() {
  return getToken(SimSystemDeclParser::STRING, 0);
}

tree::TerminalNode* SimSystemDeclParser::LiteralValueContext::TrueID() {
  return getToken(SimSystemDeclParser::TrueID, 0);
}

tree::TerminalNode* SimSystemDeclParser::LiteralValueContext::FalseID() {
  return getToken(SimSystemDeclParser::FalseID, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}


size_t SimSystemDeclParser::LiteralValueContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleLiteralValue;
}

void SimSystemDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void SimSystemDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

SimSystemDeclParser::LiteralValueContext* SimSystemDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 64, SimSystemDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(378);
        match(SimSystemDeclParser::INT);
        break;
      }

      case SimSystemDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(379);
        match(SimSystemDeclParser::REAL);
        break;
      }

      case SimSystemDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(380);
        match(SimSystemDeclParser::STRING);
        break;
      }

      case SimSystemDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(381);
        match(SimSystemDeclParser::TrueID);
        break;
      }

      case SimSystemDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(382);
        match(SimSystemDeclParser::FalseID);
        break;
      }

      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(383);
        contextID();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalParamNameContext ------------------------------------------------------------------

SimSystemDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::TriggerDeclContext* SimSystemDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<SimSystemDeclParser::TriggerDeclContext>(0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}


size_t SimSystemDeclParser::SignalParamNameContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSignalParamName;
}

void SimSystemDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void SimSystemDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

SimSystemDeclParser::SignalParamNameContext* SimSystemDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 66, SimSystemDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    triggerDecl();
    setState(387);
    contextID();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeNameContext ------------------------------------------------------------------

SimSystemDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

SimSystemDeclParser::ThisDeclContext* SimSystemDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<SimSystemDeclParser::ThisDeclContext>(0);
}


size_t SimSystemDeclParser::AttributeNameContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleAttributeName;
}

void SimSystemDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void SimSystemDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

SimSystemDeclParser::AttributeNameContext* SimSystemDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 68, SimSystemDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ThisID: {
        setState(389);
        thisDecl();
        break;
      }

      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(393);
    contextID();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToPortNameContext ------------------------------------------------------------------

SimSystemDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ToPortNameContext::ToID() {
  return getToken(SimSystemDeclParser::ToID, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}


size_t SimSystemDeclParser::ToPortNameContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleToPortName;
}

void SimSystemDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void SimSystemDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

SimSystemDeclParser::ToPortNameContext* SimSystemDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 70, SimSystemDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(SimSystemDeclParser::ToID);
    setState(396);
    contextID();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeAssignStatementContext ------------------------------------------------------------------

SimSystemDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::AttributeNameContext* SimSystemDeclParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<SimSystemDeclParser::AttributeNameContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(SimSystemDeclParser::ASSIGN, 0);
}

SimSystemDeclParser::ExpressionContext* SimSystemDeclParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<SimSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleAttributeAssignStatement;
}

void SimSystemDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void SimSystemDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

SimSystemDeclParser::AttributeAssignStatementContext* SimSystemDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 72, SimSystemDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    attributeName();
    setState(399);
    match(SimSystemDeclParser::ASSIGN);
    setState(400);
    expression();
    setState(401);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

SimSystemDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::TypeDeclContext* SimSystemDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<SimSystemDeclParser::TypeDeclContext>(0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* SimSystemDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(SimSystemDeclParser::ASSIGN, 0);
}

SimSystemDeclParser::ExpressionContext* SimSystemDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<SimSystemDeclParser::ExpressionContext>(0);
}


size_t SimSystemDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleLocalAssignStatement;
}

void SimSystemDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void SimSystemDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

SimSystemDeclParser::LocalAssignStatementContext* SimSystemDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 74, SimSystemDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    typeDecl();
    setState(404);
    contextID();
    setState(408);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ASSIGN: {
        setState(405);
        match(SimSystemDeclParser::ASSIGN);
        setState(406);
        expression();
        break;
      }

      case SimSystemDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(410);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

SimSystemDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::SendToStatementContext::SendID() {
  return getToken(SimSystemDeclParser::SendID, 0);
}

SimSystemDeclParser::SignalSendContext* SimSystemDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<SimSystemDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SendToStatementContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}

SimSystemDeclParser::ToPortNameContext* SimSystemDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<SimSystemDeclParser::ToPortNameContext>(0);
}


size_t SimSystemDeclParser::SendToStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSendToStatement;
}

void SimSystemDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void SimSystemDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

SimSystemDeclParser::SendToStatementContext* SimSystemDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 76, SimSystemDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(SimSystemDeclParser::SendID);
    setState(413);
    signalSend();
    setState(416);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ToID: {
        setState(414);
        toPortName();
        break;
      }

      case SimSystemDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(418);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

SimSystemDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::AttributeAssignStatementContext* SimSystemDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<SimSystemDeclParser::AttributeAssignStatementContext>(0);
}

SimSystemDeclParser::SendToStatementContext* SimSystemDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<SimSystemDeclParser::SendToStatementContext>(0);
}


size_t SimSystemDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSingleAssignment;
}

void SimSystemDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void SimSystemDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

SimSystemDeclParser::SingleAssignmentContext* SimSystemDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 78, SimSystemDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(422);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::ThisID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(420);
        attributeAssignStatement();
        break;
      }

      case SimSystemDeclParser::SendID: {
        enterOuterAlt(_localctx, 2);
        setState(421);
        sendToStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiAssignmentContext ------------------------------------------------------------------

SimSystemDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

tree::TerminalNode* SimSystemDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}

std::vector<SimSystemDeclParser::SingleAssignmentContext *> SimSystemDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<SimSystemDeclParser::SingleAssignmentContext>();
}

SimSystemDeclParser::SingleAssignmentContext* SimSystemDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<SimSystemDeclParser::SingleAssignmentContext>(i);
}


size_t SimSystemDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleMultiAssignment;
}

void SimSystemDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void SimSystemDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

SimSystemDeclParser::MultiAssignmentContext* SimSystemDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 80, SimSystemDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(SimSystemDeclParser::LBRACE);
    setState(428);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimSystemDeclParser::ActorID)
      | (1ULL << SimSystemDeclParser::SimSystemID)
      | (1ULL << SimSystemDeclParser::ConnectionID)
      | (1ULL << SimSystemDeclParser::ConfigID)
      | (1ULL << SimSystemDeclParser::StartupID)
      | (1ULL << SimSystemDeclParser::MessageID)
      | (1ULL << SimSystemDeclParser::StartSequenceID)
      | (1ULL << SimSystemDeclParser::NameID)
      | (1ULL << SimSystemDeclParser::LabelID)
      | (1ULL << SimSystemDeclParser::EnabledID)
      | (1ULL << SimSystemDeclParser::TypeID)
      | (1ULL << SimSystemDeclParser::ThisID)
      | (1ULL << SimSystemDeclParser::AttributeID)
      | (1ULL << SimSystemDeclParser::SignalID)
      | (1ULL << SimSystemDeclParser::PortID)
      | (1ULL << SimSystemDeclParser::ImportID)
      | (1ULL << SimSystemDeclParser::FromID)
      | (1ULL << SimSystemDeclParser::ToID)
      | (1ULL << SimSystemDeclParser::SendID)
      | (1ULL << SimSystemDeclParser::AsID)
      | (1ULL << SimSystemDeclParser::ID))) != 0)) {
      setState(425);
      singleAssignment();
      setState(430);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(431);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

SimSystemDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::SignalDeclContext::SignalID() {
  return getToken(SimSystemDeclParser::SignalID, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SignalDeclContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* SimSystemDeclParser::SignalDeclContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

tree::TerminalNode* SimSystemDeclParser::SignalDeclContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}

std::vector<SimSystemDeclParser::ParamDeclContext *> SimSystemDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<SimSystemDeclParser::ParamDeclContext>();
}

SimSystemDeclParser::ParamDeclContext* SimSystemDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<SimSystemDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::SignalDeclContext::COMMA() {
  return getTokens(SimSystemDeclParser::COMMA);
}

tree::TerminalNode* SimSystemDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(SimSystemDeclParser::COMMA, i);
}


size_t SimSystemDeclParser::SignalDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSignalDecl;
}

void SimSystemDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void SimSystemDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

SimSystemDeclParser::SignalDeclContext* SimSystemDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 82, SimSystemDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(SimSystemDeclParser::SignalID);
    setState(434);
    contextID();
    setState(449);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::LPAREN: {
        setState(435);
        match(SimSystemDeclParser::LPAREN);
        setState(445);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SimSystemDeclParser::ActorID:
          case SimSystemDeclParser::SimSystemID:
          case SimSystemDeclParser::ConnectionID:
          case SimSystemDeclParser::ConfigID:
          case SimSystemDeclParser::StartupID:
          case SimSystemDeclParser::MessageID:
          case SimSystemDeclParser::StartSequenceID:
          case SimSystemDeclParser::NameID:
          case SimSystemDeclParser::LabelID:
          case SimSystemDeclParser::EnabledID:
          case SimSystemDeclParser::TypeID:
          case SimSystemDeclParser::IntID:
          case SimSystemDeclParser::RealID:
          case SimSystemDeclParser::BoolID:
          case SimSystemDeclParser::StringID:
          case SimSystemDeclParser::EnumID:
          case SimSystemDeclParser::AttributeID:
          case SimSystemDeclParser::SignalID:
          case SimSystemDeclParser::PortID:
          case SimSystemDeclParser::ImportID:
          case SimSystemDeclParser::FromID:
          case SimSystemDeclParser::ToID:
          case SimSystemDeclParser::AsID:
          case SimSystemDeclParser::ID: {
            setState(436);
            paramDecl();
            setState(441);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == SimSystemDeclParser::COMMA) {
              setState(437);
              match(SimSystemDeclParser::COMMA);
              setState(438);
              paramDecl();
              setState(443);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case SimSystemDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(447);
        match(SimSystemDeclParser::RPAREN);
        break;
      }

      case SimSystemDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(451);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

SimSystemDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::TypeDeclContext* SimSystemDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<SimSystemDeclParser::TypeDeclContext>(0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}


size_t SimSystemDeclParser::ParamDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleParamDecl;
}

void SimSystemDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void SimSystemDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

SimSystemDeclParser::ParamDeclContext* SimSystemDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 84, SimSystemDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(453);
    typeDecl();
    setState(454);
    contextID();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

SimSystemDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(SimSystemDeclParser::FunctionID, 0);
}

SimSystemDeclParser::TypeDeclContext* SimSystemDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<SimSystemDeclParser::TypeDeclContext>(0);
}

SimSystemDeclParser::IdPathContext* SimSystemDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<SimSystemDeclParser::IdPathContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

tree::TerminalNode* SimSystemDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}

SimSystemDeclParser::NestedStatementBodyContext* SimSystemDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<SimSystemDeclParser::NestedStatementBodyContext>(0);
}

SimSystemDeclParser::FunctionParametersContext* SimSystemDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<SimSystemDeclParser::FunctionParametersContext>(0);
}


size_t SimSystemDeclParser::FunctionDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleFunctionDecl;
}

void SimSystemDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void SimSystemDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

SimSystemDeclParser::FunctionDeclContext* SimSystemDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 86, SimSystemDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(456);
    match(SimSystemDeclParser::FunctionID);
    setState(457);
    typeDecl();
    setState(458);
    idPath();
    setState(459);
    match(SimSystemDeclParser::LPAREN);
    setState(462);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::IntID:
      case SimSystemDeclParser::RealID:
      case SimSystemDeclParser::BoolID:
      case SimSystemDeclParser::StringID:
      case SimSystemDeclParser::EnumID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::ID: {
        setState(460);
        functionParameters();
        break;
      }

      case SimSystemDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(464);
    match(SimSystemDeclParser::RPAREN);
    setState(465);
    nestedStatementBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParametersContext ------------------------------------------------------------------

SimSystemDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::ParamDeclContext *> SimSystemDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<SimSystemDeclParser::ParamDeclContext>();
}

SimSystemDeclParser::ParamDeclContext* SimSystemDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<SimSystemDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(SimSystemDeclParser::COMMA);
}

tree::TerminalNode* SimSystemDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(SimSystemDeclParser::COMMA, i);
}


size_t SimSystemDeclParser::FunctionParametersContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleFunctionParameters;
}

void SimSystemDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void SimSystemDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

SimSystemDeclParser::FunctionParametersContext* SimSystemDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 88, SimSystemDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    paramDecl();
    setState(472);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::COMMA) {
      setState(468);
      match(SimSystemDeclParser::COMMA);
      setState(469);
      paramDecl();
      setState(474);
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

//----------------- FunctionCallContext ------------------------------------------------------------------

SimSystemDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::IdPathContext* SimSystemDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<SimSystemDeclParser::IdPathContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::FunctionCallContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

SimSystemDeclParser::FunctionCallBodyContext* SimSystemDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<SimSystemDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::FunctionCallContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}


size_t SimSystemDeclParser::FunctionCallContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleFunctionCall;
}

void SimSystemDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void SimSystemDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

SimSystemDeclParser::FunctionCallContext* SimSystemDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 90, SimSystemDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    idPath();
    setState(476);
    match(SimSystemDeclParser::LPAREN);
    setState(477);
    functionCallBody();
    setState(478);
    match(SimSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

SimSystemDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::FunctionCallBodyOptionalContext* SimSystemDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<SimSystemDeclParser::FunctionCallBodyOptionalContext>(0);
}

SimSystemDeclParser::LiteralValueContext* SimSystemDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<SimSystemDeclParser::LiteralValueContext>(0);
}

SimSystemDeclParser::SignalParamNameContext* SimSystemDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<SimSystemDeclParser::SignalParamNameContext>(0);
}

SimSystemDeclParser::AttributeNameContext* SimSystemDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<SimSystemDeclParser::AttributeNameContext>(0);
}

SimSystemDeclParser::FunctionCallContext* SimSystemDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<SimSystemDeclParser::FunctionCallContext>(0);
}


size_t SimSystemDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleFunctionCallBody;
}

void SimSystemDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void SimSystemDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

SimSystemDeclParser::FunctionCallBodyContext* SimSystemDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 92, SimSystemDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(480);
      literalValue();
      break;
    }

    case 2: {
      setState(481);
      signalParamName();
      break;
    }

    case 3: {
      setState(482);
      attributeName();
      break;
    }

    case 4: {
      setState(483);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(487);
    functionCallBodyOptional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyOptionalContext ------------------------------------------------------------------

SimSystemDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(SimSystemDeclParser::COMMA, 0);
}

SimSystemDeclParser::FunctionCallBodyContext* SimSystemDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<SimSystemDeclParser::FunctionCallBodyContext>(0);
}


size_t SimSystemDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleFunctionCallBodyOptional;
}

void SimSystemDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void SimSystemDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

SimSystemDeclParser::FunctionCallBodyOptionalContext* SimSystemDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 94, SimSystemDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(492);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(489);
        match(SimSystemDeclParser::COMMA);
        setState(490);
        functionCallBody();
        break;
      }

      case SimSystemDeclParser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TriggerDeclContext ------------------------------------------------------------------

SimSystemDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::TriggerDeclContext::DOT() {
  return getToken(SimSystemDeclParser::DOT, 0);
}

tree::TerminalNode* SimSystemDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(SimSystemDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* SimSystemDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(SimSystemDeclParser::TriggerID, 0);
}


size_t SimSystemDeclParser::TriggerDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleTriggerDecl;
}

void SimSystemDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void SimSystemDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

SimSystemDeclParser::TriggerDeclContext* SimSystemDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 96, SimSystemDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(494);
    _la = _input->LA(1);
    if (!(_la == SimSystemDeclParser::TriggerID

    || _la == SimSystemDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(495);
    match(SimSystemDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

SimSystemDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ThisDeclContext::ThisID() {
  return getToken(SimSystemDeclParser::ThisID, 0);
}

tree::TerminalNode* SimSystemDeclParser::ThisDeclContext::DOT() {
  return getToken(SimSystemDeclParser::DOT, 0);
}


size_t SimSystemDeclParser::ThisDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleThisDecl;
}

void SimSystemDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void SimSystemDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

SimSystemDeclParser::ThisDeclContext* SimSystemDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 98, SimSystemDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
    match(SimSystemDeclParser::ThisID);
    setState(498);
    match(SimSystemDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

SimSystemDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::PortDeclContext::PortID() {
  return getToken(SimSystemDeclParser::PortID, 0);
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* SimSystemDeclParser::PortDeclContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::PortDeclContext::COMMA() {
  return getTokens(SimSystemDeclParser::COMMA);
}

tree::TerminalNode* SimSystemDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(SimSystemDeclParser::COMMA, i);
}


size_t SimSystemDeclParser::PortDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RulePortDecl;
}

void SimSystemDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void SimSystemDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

SimSystemDeclParser::PortDeclContext* SimSystemDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 100, SimSystemDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(500);
    match(SimSystemDeclParser::PortID);
    setState(501);
    contextID();
    setState(506);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::COMMA) {
      setState(502);
      match(SimSystemDeclParser::COMMA);
      setState(503);
      contextID();
      setState(508);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(509);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

SimSystemDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::NameDeclContext::NameID() {
  return getToken(SimSystemDeclParser::NameID, 0);
}

tree::TerminalNode* SimSystemDeclParser::NameDeclContext::COLON() {
  return getToken(SimSystemDeclParser::COLON, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::NameDeclContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::NameDeclContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::NameDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleNameDecl;
}

void SimSystemDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void SimSystemDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

SimSystemDeclParser::NameDeclContext* SimSystemDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 102, SimSystemDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    match(SimSystemDeclParser::NameID);
    setState(512);
    match(SimSystemDeclParser::COLON);
    setState(513);
    contextID();
    setState(514);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

SimSystemDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimSystemDeclParser::ContextIDContext *> SimSystemDeclParser::IdPathContext::contextID() {
  return getRuleContexts<SimSystemDeclParser::ContextIDContext>();
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::IdPathContext::DOT() {
  return getTokens(SimSystemDeclParser::DOT);
}

tree::TerminalNode* SimSystemDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(SimSystemDeclParser::DOT, i);
}


size_t SimSystemDeclParser::IdPathContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleIdPath;
}

void SimSystemDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void SimSystemDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

SimSystemDeclParser::IdPathContext* SimSystemDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 104, SimSystemDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(516);
    contextID();
    setState(521);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::DOT) {
      setState(517);
      match(SimSystemDeclParser::DOT);
      setState(518);
      contextID();
      setState(523);
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

//----------------- StatementDeclContext ------------------------------------------------------------------

SimSystemDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::StatementBodyContext* SimSystemDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<SimSystemDeclParser::StatementBodyContext>(0);
}

SimSystemDeclParser::NestedStatementBodyContext* SimSystemDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<SimSystemDeclParser::NestedStatementBodyContext>(0);
}


size_t SimSystemDeclParser::StatementDeclContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleStatementDecl;
}

void SimSystemDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void SimSystemDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

SimSystemDeclParser::StatementDeclContext* SimSystemDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 106, SimSystemDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(526);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::IntID:
      case SimSystemDeclParser::RealID:
      case SimSystemDeclParser::BoolID:
      case SimSystemDeclParser::StringID:
      case SimSystemDeclParser::ThisID:
      case SimSystemDeclParser::ReturnID:
      case SimSystemDeclParser::EnumID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::SendID:
      case SimSystemDeclParser::SwitchID:
      case SimSystemDeclParser::IfID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::BREAK:
      case SimSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(524);
        statementBody();
        break;
      }

      case SimSystemDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(525);
        nestedStatementBody();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementBodyContext ------------------------------------------------------------------

SimSystemDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::FunctionCallStatementContext* SimSystemDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<SimSystemDeclParser::FunctionCallStatementContext>(0);
}

SimSystemDeclParser::AttributeAssignStatementContext* SimSystemDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<SimSystemDeclParser::AttributeAssignStatementContext>(0);
}

SimSystemDeclParser::SwitchStatementContext* SimSystemDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<SimSystemDeclParser::SwitchStatementContext>(0);
}

SimSystemDeclParser::ConditionalStatementContext* SimSystemDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<SimSystemDeclParser::ConditionalStatementContext>(0);
}

SimSystemDeclParser::LocalAssignStatementContext* SimSystemDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<SimSystemDeclParser::LocalAssignStatementContext>(0);
}

SimSystemDeclParser::SendToStatementContext* SimSystemDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<SimSystemDeclParser::SendToStatementContext>(0);
}

SimSystemDeclParser::BreakStatementContext* SimSystemDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<SimSystemDeclParser::BreakStatementContext>(0);
}

SimSystemDeclParser::ReturnStatementContext* SimSystemDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<SimSystemDeclParser::ReturnStatementContext>(0);
}


size_t SimSystemDeclParser::StatementBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleStatementBody;
}

void SimSystemDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void SimSystemDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

SimSystemDeclParser::StatementBodyContext* SimSystemDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 108, SimSystemDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(536);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(528);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(529);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(530);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(531);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(532);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(533);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(534);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(535);
      returnStatement();
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

//----------------- FunctionCallStatementContext ------------------------------------------------------------------

SimSystemDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::FunctionCallContext* SimSystemDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<SimSystemDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleFunctionCallStatement;
}

void SimSystemDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void SimSystemDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

SimSystemDeclParser::FunctionCallStatementContext* SimSystemDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, SimSystemDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    functionCall();
    setState(539);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

SimSystemDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

tree::TerminalNode* SimSystemDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}

std::vector<SimSystemDeclParser::StatementBodyContext *> SimSystemDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<SimSystemDeclParser::StatementBodyContext>();
}

SimSystemDeclParser::StatementBodyContext* SimSystemDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<SimSystemDeclParser::StatementBodyContext>(i);
}


size_t SimSystemDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleNestedStatementBody;
}

void SimSystemDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void SimSystemDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

SimSystemDeclParser::NestedStatementBodyContext* SimSystemDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 112, SimSystemDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(541);
    match(SimSystemDeclParser::LBRACE);
    setState(545);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimSystemDeclParser::ActorID)
      | (1ULL << SimSystemDeclParser::SimSystemID)
      | (1ULL << SimSystemDeclParser::ConnectionID)
      | (1ULL << SimSystemDeclParser::ConfigID)
      | (1ULL << SimSystemDeclParser::StartupID)
      | (1ULL << SimSystemDeclParser::MessageID)
      | (1ULL << SimSystemDeclParser::StartSequenceID)
      | (1ULL << SimSystemDeclParser::NameID)
      | (1ULL << SimSystemDeclParser::LabelID)
      | (1ULL << SimSystemDeclParser::EnabledID)
      | (1ULL << SimSystemDeclParser::TypeID)
      | (1ULL << SimSystemDeclParser::IntID)
      | (1ULL << SimSystemDeclParser::RealID)
      | (1ULL << SimSystemDeclParser::BoolID)
      | (1ULL << SimSystemDeclParser::StringID)
      | (1ULL << SimSystemDeclParser::ThisID)
      | (1ULL << SimSystemDeclParser::ReturnID)
      | (1ULL << SimSystemDeclParser::EnumID)
      | (1ULL << SimSystemDeclParser::AttributeID)
      | (1ULL << SimSystemDeclParser::SignalID)
      | (1ULL << SimSystemDeclParser::PortID)
      | (1ULL << SimSystemDeclParser::ImportID)
      | (1ULL << SimSystemDeclParser::FromID)
      | (1ULL << SimSystemDeclParser::ToID)
      | (1ULL << SimSystemDeclParser::SendID)
      | (1ULL << SimSystemDeclParser::SwitchID)
      | (1ULL << SimSystemDeclParser::IfID)
      | (1ULL << SimSystemDeclParser::AsID)
      | (1ULL << SimSystemDeclParser::BREAK)
      | (1ULL << SimSystemDeclParser::ID))) != 0)) {
      setState(542);
      statementBody();
      setState(547);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(548);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

SimSystemDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(SimSystemDeclParser::ReturnID, 0);
}

SimSystemDeclParser::OperationContext* SimSystemDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<SimSystemDeclParser::OperationContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ReturnStatementContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::ReturnStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleReturnStatement;
}

void SimSystemDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void SimSystemDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

SimSystemDeclParser::ReturnStatementContext* SimSystemDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, SimSystemDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(550);
    match(SimSystemDeclParser::ReturnID);
    setState(551);
    operation();
    setState(552);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

SimSystemDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::BreakStatementContext::BREAK() {
  return getToken(SimSystemDeclParser::BREAK, 0);
}

tree::TerminalNode* SimSystemDeclParser::BreakStatementContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::BreakStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleBreakStatement;
}

void SimSystemDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void SimSystemDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

SimSystemDeclParser::BreakStatementContext* SimSystemDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 116, SimSystemDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    match(SimSystemDeclParser::BREAK);
    setState(555);
    match(SimSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

SimSystemDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::AtomContext* SimSystemDeclParser::OperationContext::atom() {
  return getRuleContext<SimSystemDeclParser::AtomContext>(0);
}

SimSystemDeclParser::OperationOptionalContext* SimSystemDeclParser::OperationContext::operationOptional() {
  return getRuleContext<SimSystemDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::OperationContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

SimSystemDeclParser::OperationContext* SimSystemDeclParser::OperationContext::operation() {
  return getRuleContext<SimSystemDeclParser::OperationContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::OperationContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}

tree::TerminalNode* SimSystemDeclParser::OperationContext::MINUS() {
  return getToken(SimSystemDeclParser::MINUS, 0);
}

tree::TerminalNode* SimSystemDeclParser::OperationContext::NotIdSymbol() {
  return getToken(SimSystemDeclParser::NotIdSymbol, 0);
}


size_t SimSystemDeclParser::OperationContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleOperation;
}

void SimSystemDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void SimSystemDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

SimSystemDeclParser::OperationContext* SimSystemDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 118, SimSystemDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(568);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::TriggerID:
      case SimSystemDeclParser::MessageTrigger:
      case SimSystemDeclParser::ThisID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::TrueID:
      case SimSystemDeclParser::FalseID:
      case SimSystemDeclParser::INT:
      case SimSystemDeclParser::REAL:
      case SimSystemDeclParser::STRING:
      case SimSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(557);
        atom();
        setState(558);
        operationOptional();
        break;
      }

      case SimSystemDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(560);
        match(SimSystemDeclParser::LPAREN);
        setState(561);
        operation();
        setState(562);
        match(SimSystemDeclParser::RPAREN);
        break;
      }

      case SimSystemDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(564);
        match(SimSystemDeclParser::MINUS);
        setState(565);
        operation();
        break;
      }

      case SimSystemDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(566);
        match(SimSystemDeclParser::NotIdSymbol);
        setState(567);
        operation();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationOptionalContext ------------------------------------------------------------------

SimSystemDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::OperationContext* SimSystemDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<SimSystemDeclParser::OperationContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::OperationOptionalContext::MULT() {
  return getToken(SimSystemDeclParser::MULT, 0);
}

tree::TerminalNode* SimSystemDeclParser::OperationOptionalContext::DIV() {
  return getToken(SimSystemDeclParser::DIV, 0);
}

tree::TerminalNode* SimSystemDeclParser::OperationOptionalContext::PLUS() {
  return getToken(SimSystemDeclParser::PLUS, 0);
}

tree::TerminalNode* SimSystemDeclParser::OperationOptionalContext::MINUS() {
  return getToken(SimSystemDeclParser::MINUS, 0);
}


size_t SimSystemDeclParser::OperationOptionalContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleOperationOptional;
}

void SimSystemDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void SimSystemDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

SimSystemDeclParser::OperationOptionalContext* SimSystemDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 120, SimSystemDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(573);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::PLUS:
      case SimSystemDeclParser::MINUS:
      case SimSystemDeclParser::MULT:
      case SimSystemDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(570);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 74) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 74)) & ((1ULL << (SimSystemDeclParser::PLUS - 74))
          | (1ULL << (SimSystemDeclParser::MINUS - 74))
          | (1ULL << (SimSystemDeclParser::MULT - 74))
          | (1ULL << (SimSystemDeclParser::DIV - 74)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(571);
        operation();
        break;
      }

      case SimSystemDeclParser::NotIdSymbol:
      case SimSystemDeclParser::AndIdSymbol:
      case SimSystemDeclParser::OrIdSymbol:
      case SimSystemDeclParser::NotIdWord:
      case SimSystemDeclParser::AndIdWord:
      case SimSystemDeclParser::OrIdWord:
      case SimSystemDeclParser::ASSIGN:
      case SimSystemDeclParser::RPAREN:
      case SimSystemDeclParser::LESSTHAN:
      case SimSystemDeclParser::GREATERTHAN:
      case SimSystemDeclParser::SEMI: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SimSystemDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ExpressionContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

SimSystemDeclParser::ExpressionContext* SimSystemDeclParser::ExpressionContext::expression() {
  return getRuleContext<SimSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}

SimSystemDeclParser::ExpressionOptionalContext* SimSystemDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<SimSystemDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(SimSystemDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionContext::NotIdWord() {
  return getToken(SimSystemDeclParser::NotIdWord, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionContext::MINUS() {
  return getToken(SimSystemDeclParser::MINUS, 0);
}

SimSystemDeclParser::OperationContext* SimSystemDeclParser::ExpressionContext::operation() {
  return getRuleContext<SimSystemDeclParser::OperationContext>(0);
}


size_t SimSystemDeclParser::ExpressionContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleExpression;
}

void SimSystemDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SimSystemDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

SimSystemDeclParser::ExpressionContext* SimSystemDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 122, SimSystemDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(589);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(575);
      match(SimSystemDeclParser::LPAREN);
      setState(576);
      expression();
      setState(577);
      match(SimSystemDeclParser::RPAREN);
      setState(578);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(580);
      match(SimSystemDeclParser::NotIdSymbol);
      setState(581);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(582);
      match(SimSystemDeclParser::NotIdWord);
      setState(583);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(584);
      match(SimSystemDeclParser::MINUS);
      setState(585);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(586);
      operation();
      setState(587);
      expressionOptional();
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

//----------------- ExpressionOptionalContext ------------------------------------------------------------------

SimSystemDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::ExpressionContext* SimSystemDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<SimSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(SimSystemDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(SimSystemDeclParser::OrIdWord, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(SimSystemDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(SimSystemDeclParser::AndIdWord, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(SimSystemDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> SimSystemDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(SimSystemDeclParser::ASSIGN);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(SimSystemDeclParser::ASSIGN, i);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(SimSystemDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(SimSystemDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* SimSystemDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(SimSystemDeclParser::GREATERTHAN, 0);
}


size_t SimSystemDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleExpressionOptional;
}

void SimSystemDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void SimSystemDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

SimSystemDeclParser::ExpressionOptionalContext* SimSystemDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 124, SimSystemDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(614);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::NotIdSymbol:
      case SimSystemDeclParser::AndIdSymbol:
      case SimSystemDeclParser::OrIdSymbol:
      case SimSystemDeclParser::NotIdWord:
      case SimSystemDeclParser::AndIdWord:
      case SimSystemDeclParser::OrIdWord:
      case SimSystemDeclParser::ASSIGN:
      case SimSystemDeclParser::LESSTHAN:
      case SimSystemDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(610);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SimSystemDeclParser::OrIdSymbol: {
            setState(591);
            match(SimSystemDeclParser::OrIdSymbol);
            break;
          }

          case SimSystemDeclParser::OrIdWord: {
            setState(592);
            match(SimSystemDeclParser::OrIdWord);
            break;
          }

          case SimSystemDeclParser::AndIdSymbol: {
            setState(593);
            match(SimSystemDeclParser::AndIdSymbol);
            break;
          }

          case SimSystemDeclParser::AndIdWord: {
            setState(594);
            match(SimSystemDeclParser::AndIdWord);
            break;
          }

          case SimSystemDeclParser::ASSIGN: {
            setState(595);
            match(SimSystemDeclParser::ASSIGN);
            setState(596);
            match(SimSystemDeclParser::ASSIGN);
            break;
          }

          case SimSystemDeclParser::NotIdSymbol: {
            setState(597);
            match(SimSystemDeclParser::NotIdSymbol);
            setState(598);
            match(SimSystemDeclParser::ASSIGN);
            break;
          }

          case SimSystemDeclParser::NotIdWord: {
            setState(599);
            match(SimSystemDeclParser::NotIdWord);
            break;
          }

          case SimSystemDeclParser::LESSTHAN: {
            setState(600);
            match(SimSystemDeclParser::LESSTHAN);
            setState(603);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case SimSystemDeclParser::ASSIGN: {
                setState(601);
                match(SimSystemDeclParser::ASSIGN);
                break;
              }

              case SimSystemDeclParser::ActorID:
              case SimSystemDeclParser::SimSystemID:
              case SimSystemDeclParser::ConnectionID:
              case SimSystemDeclParser::ConfigID:
              case SimSystemDeclParser::StartupID:
              case SimSystemDeclParser::MessageID:
              case SimSystemDeclParser::StartSequenceID:
              case SimSystemDeclParser::NameID:
              case SimSystemDeclParser::LabelID:
              case SimSystemDeclParser::EnabledID:
              case SimSystemDeclParser::TypeID:
              case SimSystemDeclParser::TriggerID:
              case SimSystemDeclParser::MessageTrigger:
              case SimSystemDeclParser::ThisID:
              case SimSystemDeclParser::AttributeID:
              case SimSystemDeclParser::SignalID:
              case SimSystemDeclParser::PortID:
              case SimSystemDeclParser::ImportID:
              case SimSystemDeclParser::FromID:
              case SimSystemDeclParser::ToID:
              case SimSystemDeclParser::AsID:
              case SimSystemDeclParser::NotIdSymbol:
              case SimSystemDeclParser::NotIdWord:
              case SimSystemDeclParser::TrueID:
              case SimSystemDeclParser::FalseID:
              case SimSystemDeclParser::INT:
              case SimSystemDeclParser::REAL:
              case SimSystemDeclParser::STRING:
              case SimSystemDeclParser::ID:
              case SimSystemDeclParser::LPAREN:
              case SimSystemDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case SimSystemDeclParser::GREATERTHAN: {
            setState(605);
            match(SimSystemDeclParser::GREATERTHAN);
            setState(608);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case SimSystemDeclParser::ASSIGN: {
                setState(606);
                match(SimSystemDeclParser::ASSIGN);
                break;
              }

              case SimSystemDeclParser::ActorID:
              case SimSystemDeclParser::SimSystemID:
              case SimSystemDeclParser::ConnectionID:
              case SimSystemDeclParser::ConfigID:
              case SimSystemDeclParser::StartupID:
              case SimSystemDeclParser::MessageID:
              case SimSystemDeclParser::StartSequenceID:
              case SimSystemDeclParser::NameID:
              case SimSystemDeclParser::LabelID:
              case SimSystemDeclParser::EnabledID:
              case SimSystemDeclParser::TypeID:
              case SimSystemDeclParser::TriggerID:
              case SimSystemDeclParser::MessageTrigger:
              case SimSystemDeclParser::ThisID:
              case SimSystemDeclParser::AttributeID:
              case SimSystemDeclParser::SignalID:
              case SimSystemDeclParser::PortID:
              case SimSystemDeclParser::ImportID:
              case SimSystemDeclParser::FromID:
              case SimSystemDeclParser::ToID:
              case SimSystemDeclParser::AsID:
              case SimSystemDeclParser::NotIdSymbol:
              case SimSystemDeclParser::NotIdWord:
              case SimSystemDeclParser::TrueID:
              case SimSystemDeclParser::FalseID:
              case SimSystemDeclParser::INT:
              case SimSystemDeclParser::REAL:
              case SimSystemDeclParser::STRING:
              case SimSystemDeclParser::ID:
              case SimSystemDeclParser::LPAREN:
              case SimSystemDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(612);
        expression();
        break;
      }

      case SimSystemDeclParser::RPAREN:
      case SimSystemDeclParser::SEMI: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalStatementContext ------------------------------------------------------------------

SimSystemDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::IfStatementContext* SimSystemDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<SimSystemDeclParser::IfStatementContext>(0);
}

SimSystemDeclParser::ElseStatementContext* SimSystemDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<SimSystemDeclParser::ElseStatementContext>(0);
}


size_t SimSystemDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleConditionalStatement;
}

void SimSystemDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void SimSystemDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

SimSystemDeclParser::ConditionalStatementContext* SimSystemDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, SimSystemDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(616);
    ifStatement();
    setState(619);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      setState(617);
      elseStatement();
      break;
    }

    case 2: {
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

//----------------- IfStatementContext ------------------------------------------------------------------

SimSystemDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::IfStatementContext::IfID() {
  return getToken(SimSystemDeclParser::IfID, 0);
}

SimSystemDeclParser::IfEuTContext* SimSystemDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<SimSystemDeclParser::IfEuTContext>(0);
}

SimSystemDeclParser::StatementDeclContext* SimSystemDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<SimSystemDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::IfStatementContext::SEMI() {
  return getToken(SimSystemDeclParser::SEMI, 0);
}


size_t SimSystemDeclParser::IfStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleIfStatement;
}

void SimSystemDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void SimSystemDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

SimSystemDeclParser::IfStatementContext* SimSystemDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 128, SimSystemDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    match(SimSystemDeclParser::IfID);
    setState(622);
    ifEuT();
    setState(625);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::IntID:
      case SimSystemDeclParser::RealID:
      case SimSystemDeclParser::BoolID:
      case SimSystemDeclParser::StringID:
      case SimSystemDeclParser::ThisID:
      case SimSystemDeclParser::ReturnID:
      case SimSystemDeclParser::EnumID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::SendID:
      case SimSystemDeclParser::SwitchID:
      case SimSystemDeclParser::IfID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::BREAK:
      case SimSystemDeclParser::ID:
      case SimSystemDeclParser::LBRACE: {
        setState(623);
        statementDecl();
        break;
      }

      case SimSystemDeclParser::SEMI: {
        setState(624);
        match(SimSystemDeclParser::SEMI);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfEuTContext ------------------------------------------------------------------

SimSystemDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::IfEuTContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

SimSystemDeclParser::ExpressionContext* SimSystemDeclParser::IfEuTContext::expression() {
  return getRuleContext<SimSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::IfEuTContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}


size_t SimSystemDeclParser::IfEuTContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleIfEuT;
}

void SimSystemDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void SimSystemDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

SimSystemDeclParser::IfEuTContext* SimSystemDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 130, SimSystemDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(627);
    match(SimSystemDeclParser::LPAREN);
    setState(628);
    expression();
    setState(629);
    match(SimSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

SimSystemDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::ElseStatementContext::ElseID() {
  return getToken(SimSystemDeclParser::ElseID, 0);
}

SimSystemDeclParser::StatementDeclContext* SimSystemDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<SimSystemDeclParser::StatementDeclContext>(0);
}


size_t SimSystemDeclParser::ElseStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleElseStatement;
}

void SimSystemDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void SimSystemDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

SimSystemDeclParser::ElseStatementContext* SimSystemDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 132, SimSystemDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    match(SimSystemDeclParser::ElseID);
    setState(632);
    statementDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStatementContext ------------------------------------------------------------------

SimSystemDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(SimSystemDeclParser::SwitchID, 0);
}

SimSystemDeclParser::SwitchPuTContext* SimSystemDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<SimSystemDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(SimSystemDeclParser::LBRACE, 0);
}

tree::TerminalNode* SimSystemDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(SimSystemDeclParser::RBRACE, 0);
}

SimSystemDeclParser::DefaultStatementContext* SimSystemDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<SimSystemDeclParser::DefaultStatementContext>(0);
}

std::vector<SimSystemDeclParser::CaseStatementContext *> SimSystemDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<SimSystemDeclParser::CaseStatementContext>();
}

SimSystemDeclParser::CaseStatementContext* SimSystemDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<SimSystemDeclParser::CaseStatementContext>(i);
}


size_t SimSystemDeclParser::SwitchStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSwitchStatement;
}

void SimSystemDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void SimSystemDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

SimSystemDeclParser::SwitchStatementContext* SimSystemDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 134, SimSystemDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    match(SimSystemDeclParser::SwitchID);
    setState(635);
    switchPuT();
    setState(636);
    match(SimSystemDeclParser::LBRACE);
    setState(640);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimSystemDeclParser::CaseID) {
      setState(637);
      caseStatement();
      setState(642);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(645);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::DefaultID: {
        setState(643);
        defaultStatement();
        break;
      }

      case SimSystemDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(647);
    match(SimSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

SimSystemDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(SimSystemDeclParser::LPAREN, 0);
}

SimSystemDeclParser::ContextIDContext* SimSystemDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<SimSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(SimSystemDeclParser::RPAREN, 0);
}


size_t SimSystemDeclParser::SwitchPuTContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleSwitchPuT;
}

void SimSystemDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void SimSystemDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

SimSystemDeclParser::SwitchPuTContext* SimSystemDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 136, SimSystemDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(649);
    match(SimSystemDeclParser::LPAREN);
    setState(650);
    contextID();
    setState(651);
    match(SimSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

SimSystemDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::CaseStatementContext::CaseID() {
  return getToken(SimSystemDeclParser::CaseID, 0);
}

SimSystemDeclParser::LiteralValueContext* SimSystemDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<SimSystemDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* SimSystemDeclParser::CaseStatementContext::COLON() {
  return getToken(SimSystemDeclParser::COLON, 0);
}

SimSystemDeclParser::NestedStatementBodyContext* SimSystemDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<SimSystemDeclParser::NestedStatementBodyContext>(0);
}

std::vector<SimSystemDeclParser::StatementBodyContext *> SimSystemDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<SimSystemDeclParser::StatementBodyContext>();
}

SimSystemDeclParser::StatementBodyContext* SimSystemDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<SimSystemDeclParser::StatementBodyContext>(i);
}


size_t SimSystemDeclParser::CaseStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleCaseStatement;
}

void SimSystemDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void SimSystemDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

SimSystemDeclParser::CaseStatementContext* SimSystemDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, SimSystemDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    match(SimSystemDeclParser::CaseID);
    setState(654);
    literalValue();
    setState(655);
    match(SimSystemDeclParser::COLON);
    setState(663);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::LBRACE: {
        setState(656);
        nestedStatementBody();
        break;
      }

      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::IntID:
      case SimSystemDeclParser::RealID:
      case SimSystemDeclParser::BoolID:
      case SimSystemDeclParser::StringID:
      case SimSystemDeclParser::ThisID:
      case SimSystemDeclParser::ReturnID:
      case SimSystemDeclParser::EnumID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::SendID:
      case SimSystemDeclParser::SwitchID:
      case SimSystemDeclParser::CaseID:
      case SimSystemDeclParser::DefaultID:
      case SimSystemDeclParser::IfID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::BREAK:
      case SimSystemDeclParser::ID:
      case SimSystemDeclParser::RBRACE: {
        setState(660);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SimSystemDeclParser::ActorID)
          | (1ULL << SimSystemDeclParser::SimSystemID)
          | (1ULL << SimSystemDeclParser::ConnectionID)
          | (1ULL << SimSystemDeclParser::ConfigID)
          | (1ULL << SimSystemDeclParser::StartupID)
          | (1ULL << SimSystemDeclParser::MessageID)
          | (1ULL << SimSystemDeclParser::StartSequenceID)
          | (1ULL << SimSystemDeclParser::NameID)
          | (1ULL << SimSystemDeclParser::LabelID)
          | (1ULL << SimSystemDeclParser::EnabledID)
          | (1ULL << SimSystemDeclParser::TypeID)
          | (1ULL << SimSystemDeclParser::IntID)
          | (1ULL << SimSystemDeclParser::RealID)
          | (1ULL << SimSystemDeclParser::BoolID)
          | (1ULL << SimSystemDeclParser::StringID)
          | (1ULL << SimSystemDeclParser::ThisID)
          | (1ULL << SimSystemDeclParser::ReturnID)
          | (1ULL << SimSystemDeclParser::EnumID)
          | (1ULL << SimSystemDeclParser::AttributeID)
          | (1ULL << SimSystemDeclParser::SignalID)
          | (1ULL << SimSystemDeclParser::PortID)
          | (1ULL << SimSystemDeclParser::ImportID)
          | (1ULL << SimSystemDeclParser::FromID)
          | (1ULL << SimSystemDeclParser::ToID)
          | (1ULL << SimSystemDeclParser::SendID)
          | (1ULL << SimSystemDeclParser::SwitchID)
          | (1ULL << SimSystemDeclParser::IfID)
          | (1ULL << SimSystemDeclParser::AsID)
          | (1ULL << SimSystemDeclParser::BREAK)
          | (1ULL << SimSystemDeclParser::ID))) != 0)) {
          setState(657);
          statementBody();
          setState(662);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefaultStatementContext ------------------------------------------------------------------

SimSystemDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimSystemDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(SimSystemDeclParser::DefaultID, 0);
}

tree::TerminalNode* SimSystemDeclParser::DefaultStatementContext::COLON() {
  return getToken(SimSystemDeclParser::COLON, 0);
}

SimSystemDeclParser::NestedStatementBodyContext* SimSystemDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<SimSystemDeclParser::NestedStatementBodyContext>(0);
}

std::vector<SimSystemDeclParser::StatementBodyContext *> SimSystemDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<SimSystemDeclParser::StatementBodyContext>();
}

SimSystemDeclParser::StatementBodyContext* SimSystemDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<SimSystemDeclParser::StatementBodyContext>(i);
}


size_t SimSystemDeclParser::DefaultStatementContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleDefaultStatement;
}

void SimSystemDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void SimSystemDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

SimSystemDeclParser::DefaultStatementContext* SimSystemDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 140, SimSystemDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(665);
    match(SimSystemDeclParser::DefaultID);
    setState(666);
    match(SimSystemDeclParser::COLON);
    setState(674);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimSystemDeclParser::LBRACE: {
        setState(667);
        nestedStatementBody();
        break;
      }

      case SimSystemDeclParser::ActorID:
      case SimSystemDeclParser::SimSystemID:
      case SimSystemDeclParser::ConnectionID:
      case SimSystemDeclParser::ConfigID:
      case SimSystemDeclParser::StartupID:
      case SimSystemDeclParser::MessageID:
      case SimSystemDeclParser::StartSequenceID:
      case SimSystemDeclParser::NameID:
      case SimSystemDeclParser::LabelID:
      case SimSystemDeclParser::EnabledID:
      case SimSystemDeclParser::TypeID:
      case SimSystemDeclParser::IntID:
      case SimSystemDeclParser::RealID:
      case SimSystemDeclParser::BoolID:
      case SimSystemDeclParser::StringID:
      case SimSystemDeclParser::ThisID:
      case SimSystemDeclParser::ReturnID:
      case SimSystemDeclParser::EnumID:
      case SimSystemDeclParser::AttributeID:
      case SimSystemDeclParser::SignalID:
      case SimSystemDeclParser::PortID:
      case SimSystemDeclParser::ImportID:
      case SimSystemDeclParser::FromID:
      case SimSystemDeclParser::ToID:
      case SimSystemDeclParser::SendID:
      case SimSystemDeclParser::SwitchID:
      case SimSystemDeclParser::IfID:
      case SimSystemDeclParser::AsID:
      case SimSystemDeclParser::BREAK:
      case SimSystemDeclParser::ID:
      case SimSystemDeclParser::RBRACE: {
        setState(671);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SimSystemDeclParser::ActorID)
          | (1ULL << SimSystemDeclParser::SimSystemID)
          | (1ULL << SimSystemDeclParser::ConnectionID)
          | (1ULL << SimSystemDeclParser::ConfigID)
          | (1ULL << SimSystemDeclParser::StartupID)
          | (1ULL << SimSystemDeclParser::MessageID)
          | (1ULL << SimSystemDeclParser::StartSequenceID)
          | (1ULL << SimSystemDeclParser::NameID)
          | (1ULL << SimSystemDeclParser::LabelID)
          | (1ULL << SimSystemDeclParser::EnabledID)
          | (1ULL << SimSystemDeclParser::TypeID)
          | (1ULL << SimSystemDeclParser::IntID)
          | (1ULL << SimSystemDeclParser::RealID)
          | (1ULL << SimSystemDeclParser::BoolID)
          | (1ULL << SimSystemDeclParser::StringID)
          | (1ULL << SimSystemDeclParser::ThisID)
          | (1ULL << SimSystemDeclParser::ReturnID)
          | (1ULL << SimSystemDeclParser::EnumID)
          | (1ULL << SimSystemDeclParser::AttributeID)
          | (1ULL << SimSystemDeclParser::SignalID)
          | (1ULL << SimSystemDeclParser::PortID)
          | (1ULL << SimSystemDeclParser::ImportID)
          | (1ULL << SimSystemDeclParser::FromID)
          | (1ULL << SimSystemDeclParser::ToID)
          | (1ULL << SimSystemDeclParser::SendID)
          | (1ULL << SimSystemDeclParser::SwitchID)
          | (1ULL << SimSystemDeclParser::IfID)
          | (1ULL << SimSystemDeclParser::AsID)
          | (1ULL << SimSystemDeclParser::BREAK)
          | (1ULL << SimSystemDeclParser::ID))) != 0)) {
          setState(668);
          statementBody();
          setState(673);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

SimSystemDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimSystemDeclParser::SignalParamNameContext* SimSystemDeclParser::AtomContext::signalParamName() {
  return getRuleContext<SimSystemDeclParser::SignalParamNameContext>(0);
}

SimSystemDeclParser::AttributeNameContext* SimSystemDeclParser::AtomContext::attributeName() {
  return getRuleContext<SimSystemDeclParser::AttributeNameContext>(0);
}

SimSystemDeclParser::FunctionCallContext* SimSystemDeclParser::AtomContext::functionCall() {
  return getRuleContext<SimSystemDeclParser::FunctionCallContext>(0);
}

SimSystemDeclParser::LiteralValueContext* SimSystemDeclParser::AtomContext::literalValue() {
  return getRuleContext<SimSystemDeclParser::LiteralValueContext>(0);
}


size_t SimSystemDeclParser::AtomContext::getRuleIndex() const {
  return SimSystemDeclParser::RuleAtom;
}

void SimSystemDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void SimSystemDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

SimSystemDeclParser::AtomContext* SimSystemDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 142, SimSystemDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(680);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(676);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(677);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(678);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(679);
      literalValue();
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

// Static vars and initialization.
std::vector<dfa::DFA> SimSystemDeclParser::_decisionToDFA;
atn::PredictionContextCache SimSystemDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SimSystemDeclParser::_atn;
std::vector<uint16_t> SimSystemDeclParser::_serializedATN;

std::vector<std::string> SimSystemDeclParser::_ruleNames = {
  "simSystemDecl", "simSystemBody", "connectionDecl", "connectionBody", 
  "configDecl", "configBody", "actorDecl", "actorDeclBody", "actorBodyContent", 
  "startupDecl", "startupBody", "messageDeclOptional", "messageDecl", "messageSignal", 
  "messageParamValue", "startSequenceDecl", "contextID", "componentIdPath", 
  "signalIdPath", "attributeIdPath", "signalSend", "commonDecl", "importPathDecl", 
  "importPathBody", "importFileBody", "importAs", "typeDefDecl", "typeDecl", 
  "intTypeDecl", "realTypeDecl", "enumTypeDecl", "attributeDecl", "literalValue", 
  "signalParamName", "attributeName", "toPortName", "attributeAssignStatement", 
  "localAssignStatement", "sendToStatement", "singleAssignment", "multiAssignment", 
  "signalDecl", "paramDecl", "functionDecl", "functionParameters", "functionCall", 
  "functionCallBody", "functionCallBodyOptional", "triggerDecl", "thisDecl", 
  "portDecl", "nameDecl", "idPath", "statementDecl", "statementBody", "functionCallStatement", 
  "nestedStatementBody", "returnStatement", "breakStatement", "operation", 
  "operationOptional", "expression", "expressionOptional", "conditionalStatement", 
  "ifStatement", "ifEuT", "elseStatement", "switchStatement", "switchPuT", 
  "caseStatement", "defaultStatement", "atom"
};

std::vector<std::string> SimSystemDeclParser::_literalNames = {
  "", "'Actor'", "'SimSystem'", "'Connection'", "'Config'", "'Startup'", 
  "'Message'", "'startSequence'", "", "'name'", "'label'", "'enabled'", 
  "'Type'", "'int'", "'real'", "'bool'", "'string'", "'trigger'", "'msg'", 
  "'this'", "'return'", "'SignalTransition'", "'TimeoutTransition'", "'enum'", 
  "'Declaration'", "'description'", "'Attribute'", "'Signal'", "'Port'", 
  "'import'", "'from'", "'to'", "'send'", "'Function'", "'switch'", "'case'", 
  "'default'", "'if'", "'else'", "'as'", "'@'", "'!'", "'&&'", "'||'", "'not'", 
  "'and'", "'or'", "'true'", "'false'", "'break'", "'='", "'<->'", "'->'", 
  "'<-'", "'..'", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", 
  "']'", "'<'", "'>'", "':'", "';'", "','", "'_'", "'.'", "'+'", "'-'", 
  "'*'", "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> SimSystemDeclParser::_symbolicNames = {
  "", "ActorID", "SimSystemID", "ConnectionID", "ConfigID", "StartupID", 
  "MessageID", "StartSequenceID", "IGNORE_NEWLINE", "NameID", "LabelID", 
  "EnabledID", "TypeID", "IntID", "RealID", "BoolID", "StringID", "TriggerID", 
  "MessageTrigger", "ThisID", "ReturnID", "SignalTransitionID", "TimeoutTransitionID", 
  "EnumID", "DeclarationID", "DescriptionID", "AttributeID", "SignalID", 
  "PortID", "ImportID", "FromID", "ToID", "SendID", "FunctionID", "SwitchID", 
  "CaseID", "DefaultID", "IfID", "ElseID", "AsID", "AtID", "NotIdSymbol", 
  "AndIdSymbol", "OrIdSymbol", "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", 
  "FalseID", "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", "LeftArrow", 
  "RANGE", "INT", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", "LPAREN", 
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", 
  "COLON", "SEMI", "COMMA", "UNDER", "DOT", "PLUS", "MINUS", "MULT", "DIV", 
  "PIPE", "REF", "CONST", "NEWLINE", "WS"
};

dfa::Vocabulary SimSystemDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SimSystemDeclParser::_tokenNames;

SimSystemDeclParser::Initializer::Initializer() {
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
    0x3, 0x54, 0x2ad, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x9d, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xb0, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0xb4, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xb8, 0xa, 0x7, 
    0x3, 0x8, 0x6, 0x8, 0xbb, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0xbc, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xc4, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x6, 0xa, 0xc9, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 
    0xca, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xd8, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x7, 0xf, 0xe9, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xec, 0xb, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0xef, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 
    0xfa, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xfd, 0xb, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
    0x106, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x109, 0xb, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x10e, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0x111, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
    0x117, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x11a, 0xb, 0x15, 0x5, 0x15, 
    0x11c, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x126, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x129, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x5, 0x18, 0x12f, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x142, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 
    0x147, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 
    0x1d, 0x154, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x15d, 0xa, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 
    0x1f, 0x166, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x7, 0x20, 0x16d, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x170, 
    0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x5, 0x21, 0x179, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
    0x22, 0x183, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x18a, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x19b, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x5, 0x28, 0x1a3, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 
    0x3, 0x29, 0x5, 0x29, 0x1a9, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 
    0x1ad, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x1b0, 0xb, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x7, 0x2b, 0x1ba, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x1bd, 0xb, 
    0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x1c0, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x5, 0x2b, 0x1c4, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x5, 0x2d, 0x1d1, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x1d9, 0xa, 0x2e, 0xc, 0x2e, 
    0xe, 0x2e, 0x1dc, 0xb, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 
    0x30, 0x1e8, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x5, 0x31, 0x1ef, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x34, 0x7, 0x34, 0x1fb, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x1fe, 0xb, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x20a, 0xa, 0x36, 
    0xc, 0x36, 0xe, 0x36, 0x20d, 0xb, 0x36, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 
    0x211, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x21b, 0xa, 0x38, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x222, 0xa, 0x3a, 
    0xc, 0x3a, 0xe, 0x3a, 0x225, 0xb, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x23b, 0xa, 0x3d, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x240, 0xa, 0x3e, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
    0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x5, 0x3f, 0x250, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x5, 0x40, 0x25e, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x5, 0x40, 0x263, 0xa, 0x40, 0x5, 0x40, 0x265, 0xa, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x269, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x5, 0x41, 0x26e, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x5, 0x42, 0x274, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 
    0x45, 0x3, 0x45, 0x7, 0x45, 0x281, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 
    0x284, 0xb, 0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x288, 0xa, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x295, 
    0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x298, 0xb, 0x47, 0x5, 0x47, 0x29a, 
    0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 0x2a0, 
    0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x2a3, 0xb, 0x48, 0x5, 0x48, 0x2a5, 
    0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x2ab, 
    0xa, 0x49, 0x3, 0x49, 0x2, 0x2, 0x4a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 
    0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
    0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
    0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x2, 0x5, 0x7, 0x2, 0x3, 0x9, 0xb, 
    0xe, 0x1c, 0x21, 0x29, 0x29, 0x3c, 0x3c, 0x3, 0x2, 0x13, 0x14, 0x3, 
    0x2, 0x4c, 0x4f, 0x2, 0x2c0, 0x2, 0x92, 0x3, 0x2, 0x2, 0x2, 0x4, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xc, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0xba, 0x3, 0x2, 0x2, 0x2, 0x10, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0x14, 0xcc, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x22, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x102, 0x3, 0x2, 0x2, 0x2, 0x26, 0x10a, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x127, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x141, 0x3, 0x2, 0x2, 0x2, 0x34, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x148, 0x3, 0x2, 0x2, 0x2, 0x38, 0x153, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x155, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x15e, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x167, 0x3, 0x2, 0x2, 0x2, 0x40, 0x173, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x182, 0x3, 0x2, 0x2, 0x2, 0x44, 0x184, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x189, 0x3, 0x2, 0x2, 0x2, 0x48, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x190, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x195, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x19e, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1aa, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1c7, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x1ee, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1f3, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x68, 0x201, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x206, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x210, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x70, 0x21c, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x74, 0x228, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x78, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x23f, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x268, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x82, 0x26f, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x275, 0x3, 0x2, 0x2, 0x2, 0x86, 0x279, 0x3, 0x2, 
    0x2, 0x2, 0x88, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x28b, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x29b, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x5, 0x2e, 0x18, 0x2, 0x93, 
    0x94, 0x7, 0x4, 0x2, 0x2, 0x94, 0x95, 0x5, 0x22, 0x12, 0x2, 0x95, 0x96, 
    0x7, 0x41, 0x2, 0x2, 0x96, 0x97, 0x5, 0x4, 0x3, 0x2, 0x97, 0x98, 0x7, 
    0x42, 0x2, 0x2, 0x98, 0x3, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9c, 0x5, 0x6, 
    0x4, 0x2, 0x9a, 0x9d, 0x5, 0xa, 0x6, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x5, 0x2, 0x2, 0x9f, 
    0xa0, 0x7, 0x41, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x8, 0x5, 0x2, 0xa1, 0xa2, 
    0x7, 0x42, 0x2, 0x2, 0xa2, 0x7, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x5, 
    0x24, 0x13, 0x2, 0xa4, 0xa5, 0x7, 0x35, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x24, 
    0x13, 0x2, 0xa6, 0xa7, 0x7, 0x48, 0x2, 0x2, 0xa7, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xa9, 0x7, 0x6, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x41, 0x2, 0x2, 
    0xaa, 0xab, 0x5, 0xc, 0x7, 0x2, 0xab, 0xac, 0x7, 0x42, 0x2, 0x2, 0xac, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb0, 0x5, 0xe, 0x8, 0x2, 0xae, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb4, 0x5, 0x20, 
    0x11, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb8, 0x5, 0x14, 0xb, 0x2, 0xb6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xbb, 0x5, 0x10, 0x9, 0x2, 0xba, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbf, 0x7, 0x3, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x22, 0x12, 0x2, 
    0xc0, 0xc3, 0x7, 0x41, 0x2, 0x2, 0xc1, 0xc4, 0x5, 0x12, 0xa, 0x2, 0xc2, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 
    0x42, 0x2, 0x2, 0xc6, 0x11, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc9, 0x5, 0x66, 
    0x34, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0x13, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x7, 0x2, 0x2, 0xcd, 
    0xce, 0x7, 0x41, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x16, 0xc, 0x2, 0xcf, 0xd0, 
    0x7, 0x42, 0x2, 0x2, 0xd0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x5, 
    0x18, 0xd, 0x2, 0xd2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x1a, 
    0xe, 0x2, 0xd4, 0xd5, 0x5, 0x18, 0xd, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xda, 0x7, 0x8, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x3f, 0x2, 0x2, 0xdb, 0xdc, 
    0x5, 0x24, 0x13, 0x2, 0xdc, 0xdd, 0x7, 0x36, 0x2, 0x2, 0xdd, 0xde, 0x5, 
    0x24, 0x13, 0x2, 0xde, 0xdf, 0x7, 0x40, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x47, 
    0x2, 0x2, 0xe0, 0xe1, 0x5, 0x1c, 0xf, 0x2, 0xe1, 0xe2, 0x7, 0x48, 0x2, 
    0x2, 0xe2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x26, 0x14, 0x2, 
    0xe4, 0xee, 0x7, 0x3f, 0x2, 0x2, 0xe5, 0xea, 0x5, 0x1e, 0x10, 0x2, 0xe6, 
    0xe7, 0x7, 0x49, 0x2, 0x2, 0xe7, 0xe9, 0x5, 0x1e, 0x10, 0x2, 0xe8, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xec, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xee, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x40, 0x2, 0x2, 0xf1, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x42, 0x22, 0x2, 0xf3, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x9, 0x2, 0x2, 0xf5, 0xf6, 0x7, 
    0x47, 0x2, 0x2, 0xf6, 0xfb, 0x5, 0x22, 0x12, 0x2, 0xf7, 0xf8, 0x7, 0x49, 
    0x2, 0x2, 0xf8, 0xfa, 0x5, 0x22, 0x12, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfd, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x48, 0x2, 0x2, 0xff, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x9, 0x2, 0x2, 0x2, 0x101, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x107, 0x5, 0x22, 0x12, 0x2, 0x103, 0x104, 0x7, 
    0x4b, 0x2, 0x2, 0x104, 0x106, 0x5, 0x22, 0x12, 0x2, 0x105, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x109, 0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10f, 0x5, 0x22, 
    0x12, 0x2, 0x10b, 0x10c, 0x7, 0x4b, 0x2, 0x2, 0x10c, 0x10e, 0x5, 0x22, 
    0x12, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x27, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x11c, 0x5, 0x46, 0x24, 0x2, 0x113, 0x118, 0x5, 0x22, 0x12, 
    0x2, 0x114, 0x115, 0x7, 0x4b, 0x2, 0x2, 0x115, 0x117, 0x5, 0x22, 0x12, 
    0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x117, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x112, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x5, 0x26, 0x14, 
    0x2, 0x11e, 0x11f, 0x7, 0x3f, 0x2, 0x2, 0x11f, 0x120, 0x5, 0x5e, 0x30, 
    0x2, 0x120, 0x121, 0x7, 0x40, 0x2, 0x2, 0x121, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x126, 0x5, 0x36, 0x1c, 0x2, 0x123, 0x126, 0x5, 0x40, 0x21, 
    0x2, 0x124, 0x126, 0x5, 0x54, 0x2b, 0x2, 0x125, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x129, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x5, 0x30, 0x19, 0x2, 
    0x12b, 0x12c, 0x5, 0x2e, 0x18, 0x2, 0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12a, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x130, 
    0x131, 0x7, 0x1f, 0x2, 0x2, 0x131, 0x132, 0x7, 0x45, 0x2, 0x2, 0x132, 
    0x133, 0x5, 0x32, 0x1a, 0x2, 0x133, 0x134, 0x7, 0x46, 0x2, 0x2, 0x134, 
    0x135, 0x5, 0x34, 0x1b, 0x2, 0x135, 0x31, 0x3, 0x2, 0x2, 0x2, 0x136, 
    0x137, 0x5, 0x22, 0x12, 0x2, 0x137, 0x138, 0x7, 0x4b, 0x2, 0x2, 0x138, 
    0x139, 0x5, 0x22, 0x12, 0x2, 0x139, 0x142, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x13b, 0x7, 0x38, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x4f, 0x2, 0x2, 0x13c, 
    0x142, 0x5, 0x32, 0x1a, 0x2, 0x13d, 0x13e, 0x5, 0x22, 0x12, 0x2, 0x13e, 
    0x13f, 0x7, 0x4f, 0x2, 0x2, 0x13f, 0x140, 0x5, 0x32, 0x1a, 0x2, 0x140, 
    0x142, 0x3, 0x2, 0x2, 0x2, 0x141, 0x136, 0x3, 0x2, 0x2, 0x2, 0x141, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x142, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x29, 0x2, 0x2, 0x144, 
    0x147, 0x5, 0x22, 0x12, 0x2, 0x145, 0x147, 0x3, 0x2, 0x2, 0x2, 0x146, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x146, 0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x7, 0xe, 0x2, 0x2, 0x149, 0x14a, 
    0x5, 0x38, 0x1d, 0x2, 0x14a, 0x14b, 0x5, 0x22, 0x12, 0x2, 0x14b, 0x14c, 
    0x7, 0x48, 0x2, 0x2, 0x14c, 0x37, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x154, 
    0x5, 0x3a, 0x1e, 0x2, 0x14e, 0x154, 0x5, 0x3c, 0x1f, 0x2, 0x14f, 0x154, 
    0x5, 0x3e, 0x20, 0x2, 0x150, 0x154, 0x7, 0x11, 0x2, 0x2, 0x151, 0x154, 
    0x7, 0x12, 0x2, 0x2, 0x152, 0x154, 0x5, 0x22, 0x12, 0x2, 0x153, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x153, 0x14f, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x150, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x15c, 0x7, 0xf, 0x2, 0x2, 0x156, 0x157, 0x7, 
    0x3f, 0x2, 0x2, 0x157, 0x158, 0x7, 0x39, 0x2, 0x2, 0x158, 0x159, 0x7, 
    0x38, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x39, 0x2, 0x2, 0x15a, 0x15d, 0x7, 
    0x40, 0x2, 0x2, 0x15b, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x156, 0x3, 
    0x2, 0x2, 0x2, 0x15c, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x165, 0x7, 0x10, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x3f, 
    0x2, 0x2, 0x160, 0x161, 0x7, 0x3a, 0x2, 0x2, 0x161, 0x162, 0x7, 0x38, 
    0x2, 0x2, 0x162, 0x163, 0x7, 0x3a, 0x2, 0x2, 0x163, 0x166, 0x7, 0x40, 
    0x2, 0x2, 0x164, 0x166, 0x3, 0x2, 0x2, 0x2, 0x165, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x165, 0x164, 0x3, 0x2, 0x2, 0x2, 0x166, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x168, 0x7, 0x19, 0x2, 0x2, 0x168, 0x169, 0x7, 0x3f, 0x2, 
    0x2, 0x169, 0x16e, 0x5, 0x22, 0x12, 0x2, 0x16a, 0x16b, 0x7, 0x49, 0x2, 
    0x2, 0x16b, 0x16d, 0x5, 0x22, 0x12, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 
    0x2, 0x16d, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 
    0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x7, 0x40, 0x2, 
    0x2, 0x172, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x7, 0x1c, 0x2, 
    0x2, 0x174, 0x175, 0x5, 0x38, 0x1d, 0x2, 0x175, 0x178, 0x5, 0x22, 0x12, 
    0x2, 0x176, 0x177, 0x7, 0x34, 0x2, 0x2, 0x177, 0x179, 0x5, 0x42, 0x22, 
    0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 0x2, 
    0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0x48, 0x2, 
    0x2, 0x17b, 0x41, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x183, 0x7, 0x39, 0x2, 
    0x2, 0x17d, 0x183, 0x7, 0x3a, 0x2, 0x2, 0x17e, 0x183, 0x7, 0x3b, 0x2, 
    0x2, 0x17f, 0x183, 0x7, 0x31, 0x2, 0x2, 0x180, 0x183, 0x7, 0x32, 0x2, 
    0x2, 0x181, 0x183, 0x5, 0x22, 0x12, 0x2, 0x182, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x182, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x182, 0x17e, 0x3, 0x2, 0x2, 
    0x2, 0x182, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 
    0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x183, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x185, 0x5, 0x62, 0x32, 0x2, 0x185, 0x186, 0x5, 0x22, 0x12, 0x2, 
    0x186, 0x45, 0x3, 0x2, 0x2, 0x2, 0x187, 0x18a, 0x5, 0x64, 0x33, 0x2, 
    0x188, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 
    0x189, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x18c, 0x5, 0x22, 0x12, 0x2, 0x18c, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x18d, 0x18e, 0x7, 0x21, 0x2, 0x2, 0x18e, 0x18f, 0x5, 0x22, 0x12, 0x2, 
    0x18f, 0x49, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x5, 0x46, 0x24, 0x2, 
    0x191, 0x192, 0x7, 0x34, 0x2, 0x2, 0x192, 0x193, 0x5, 0x7c, 0x3f, 0x2, 
    0x193, 0x194, 0x7, 0x48, 0x2, 0x2, 0x194, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x195, 0x196, 0x5, 0x38, 0x1d, 0x2, 0x196, 0x19a, 0x5, 0x22, 0x12, 0x2, 
    0x197, 0x198, 0x7, 0x34, 0x2, 0x2, 0x198, 0x19b, 0x5, 0x7c, 0x3f, 0x2, 
    0x199, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x197, 0x3, 0x2, 0x2, 0x2, 
    0x19a, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x19c, 0x19d, 0x7, 0x48, 0x2, 0x2, 0x19d, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x19e, 0x19f, 0x7, 0x22, 0x2, 0x2, 0x19f, 0x1a2, 0x5, 0x2a, 0x16, 0x2, 
    0x1a0, 0x1a3, 0x5, 0x48, 0x25, 0x2, 0x1a1, 0x1a3, 0x3, 0x2, 0x2, 0x2, 
    0x1a2, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a1, 0x3, 0x2, 0x2, 0x2, 
    0x1a3, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x48, 0x2, 0x2, 
    0x1a5, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x5, 0x4a, 0x26, 0x2, 
    0x1a7, 0x1a9, 0x5, 0x4e, 0x28, 0x2, 0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 
    0x1a8, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
    0x1ae, 0x7, 0x41, 0x2, 0x2, 0x1ab, 0x1ad, 0x5, 0x50, 0x29, 0x2, 0x1ac, 
    0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1b2, 0x7, 0x42, 0x2, 0x2, 0x1b2, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
    0x1b4, 0x7, 0x1d, 0x2, 0x2, 0x1b4, 0x1c3, 0x5, 0x22, 0x12, 0x2, 0x1b5, 
    0x1bf, 0x7, 0x3f, 0x2, 0x2, 0x1b6, 0x1bb, 0x5, 0x56, 0x2c, 0x2, 0x1b7, 
    0x1b8, 0x7, 0x49, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 0x56, 0x2c, 0x2, 0x1b9, 
    0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bb, 
    0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1be, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1bf, 
    0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
    0x1c4, 0x7, 0x40, 0x2, 0x2, 0x1c2, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
    0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
    0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x48, 0x2, 0x2, 0x1c6, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x5, 0x38, 0x1d, 0x2, 0x1c8, 
    0x1c9, 0x5, 0x22, 0x12, 0x2, 0x1c9, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1ca, 
    0x1cb, 0x7, 0x23, 0x2, 0x2, 0x1cb, 0x1cc, 0x5, 0x38, 0x1d, 0x2, 0x1cc, 
    0x1cd, 0x5, 0x6a, 0x36, 0x2, 0x1cd, 0x1d0, 0x7, 0x3f, 0x2, 0x2, 0x1ce, 
    0x1d1, 0x5, 0x5a, 0x2e, 0x2, 0x1cf, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d0, 
    0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
    0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x7, 0x40, 0x2, 0x2, 0x1d3, 
    0x1d4, 0x5, 0x72, 0x3a, 0x2, 0x1d4, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
    0x1da, 0x5, 0x56, 0x2c, 0x2, 0x1d6, 0x1d7, 0x7, 0x49, 0x2, 0x2, 0x1d7, 
    0x1d9, 0x5, 0x56, 0x2c, 0x2, 0x1d8, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
    0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 
    0x1db, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1da, 
    0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x5, 0x6a, 0x36, 0x2, 0x1de, 0x1df, 
    0x7, 0x3f, 0x2, 0x2, 0x1df, 0x1e0, 0x5, 0x5e, 0x30, 0x2, 0x1e0, 0x1e1, 
    0x7, 0x40, 0x2, 0x2, 0x1e1, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e8, 
    0x5, 0x42, 0x22, 0x2, 0x1e3, 0x1e8, 0x5, 0x44, 0x23, 0x2, 0x1e4, 0x1e8, 
    0x5, 0x46, 0x24, 0x2, 0x1e5, 0x1e8, 0x5, 0x5c, 0x2f, 0x2, 0x1e6, 0x1e8, 
    0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e3, 
    0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e5, 
    0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 
    0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x5, 0x60, 0x31, 0x2, 0x1ea, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x49, 0x2, 0x2, 0x1ec, 0x1ef, 
    0x5, 0x5e, 0x30, 0x2, 0x1ed, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1eb, 
    0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x9, 0x3, 0x2, 0x2, 0x1f1, 0x1f2, 0x7, 
    0x4b, 0x2, 0x2, 0x1f2, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x7, 
    0x15, 0x2, 0x2, 0x1f4, 0x1f5, 0x7, 0x4b, 0x2, 0x2, 0x1f5, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x7, 0x1e, 0x2, 0x2, 0x1f7, 0x1fc, 0x5, 
    0x22, 0x12, 0x2, 0x1f8, 0x1f9, 0x7, 0x49, 0x2, 0x2, 0x1f9, 0x1fb, 0x5, 
    0x22, 0x12, 0x2, 0x1fa, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fe, 0x3, 
    0x2, 0x2, 0x2, 0x1fc, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x3, 
    0x2, 0x2, 0x2, 0x1fd, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1fc, 0x3, 
    0x2, 0x2, 0x2, 0x1ff, 0x200, 0x7, 0x48, 0x2, 0x2, 0x200, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x201, 0x202, 0x7, 0xb, 0x2, 0x2, 0x202, 0x203, 0x7, 
    0x47, 0x2, 0x2, 0x203, 0x204, 0x5, 0x22, 0x12, 0x2, 0x204, 0x205, 0x7, 
    0x48, 0x2, 0x2, 0x205, 0x69, 0x3, 0x2, 0x2, 0x2, 0x206, 0x20b, 0x5, 
    0x22, 0x12, 0x2, 0x207, 0x208, 0x7, 0x4b, 0x2, 0x2, 0x208, 0x20a, 0x5, 
    0x22, 0x12, 0x2, 0x209, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20d, 0x3, 
    0x2, 0x2, 0x2, 0x20b, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 0x3, 
    0x2, 0x2, 0x2, 0x20c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20b, 0x3, 0x2, 
    0x2, 0x2, 0x20e, 0x211, 0x5, 0x6e, 0x38, 0x2, 0x20f, 0x211, 0x5, 0x72, 
    0x3a, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20f, 0x3, 0x2, 
    0x2, 0x2, 0x211, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x212, 0x21b, 0x5, 0x70, 
    0x39, 0x2, 0x213, 0x21b, 0x5, 0x4a, 0x26, 0x2, 0x214, 0x21b, 0x5, 0x88, 
    0x45, 0x2, 0x215, 0x21b, 0x5, 0x80, 0x41, 0x2, 0x216, 0x21b, 0x5, 0x4c, 
    0x27, 0x2, 0x217, 0x21b, 0x5, 0x4e, 0x28, 0x2, 0x218, 0x21b, 0x5, 0x76, 
    0x3c, 0x2, 0x219, 0x21b, 0x5, 0x74, 0x3b, 0x2, 0x21a, 0x212, 0x3, 0x2, 
    0x2, 0x2, 0x21a, 0x213, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x214, 0x3, 0x2, 
    0x2, 0x2, 0x21a, 0x215, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x216, 0x3, 0x2, 
    0x2, 0x2, 0x21a, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x218, 0x3, 0x2, 
    0x2, 0x2, 0x21a, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x21c, 0x21d, 0x5, 0x5c, 0x2f, 0x2, 0x21d, 0x21e, 0x7, 0x48, 0x2, 
    0x2, 0x21e, 0x71, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x223, 0x7, 0x41, 0x2, 
    0x2, 0x220, 0x222, 0x5, 0x6e, 0x38, 0x2, 0x221, 0x220, 0x3, 0x2, 0x2, 
    0x2, 0x222, 0x225, 0x3, 0x2, 0x2, 0x2, 0x223, 0x221, 0x3, 0x2, 0x2, 
    0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x225, 0x223, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x7, 0x42, 0x2, 
    0x2, 0x227, 0x73, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x7, 0x16, 0x2, 
    0x2, 0x229, 0x22a, 0x5, 0x78, 0x3d, 0x2, 0x22a, 0x22b, 0x7, 0x48, 0x2, 
    0x2, 0x22b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x7, 0x33, 0x2, 
    0x2, 0x22d, 0x22e, 0x7, 0x48, 0x2, 0x2, 0x22e, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x22f, 0x230, 0x5, 0x90, 0x49, 0x2, 0x230, 0x231, 0x5, 0x7a, 0x3e, 
    0x2, 0x231, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x7, 0x3f, 0x2, 
    0x2, 0x233, 0x234, 0x5, 0x78, 0x3d, 0x2, 0x234, 0x235, 0x7, 0x40, 0x2, 
    0x2, 0x235, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x236, 0x237, 0x7, 0x4d, 0x2, 
    0x2, 0x237, 0x23b, 0x5, 0x78, 0x3d, 0x2, 0x238, 0x239, 0x7, 0x2b, 0x2, 
    0x2, 0x239, 0x23b, 0x5, 0x78, 0x3d, 0x2, 0x23a, 0x22f, 0x3, 0x2, 0x2, 
    0x2, 0x23a, 0x232, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x236, 0x3, 0x2, 0x2, 
    0x2, 0x23a, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x23c, 0x23d, 0x9, 0x4, 0x2, 0x2, 0x23d, 0x240, 0x5, 0x78, 0x3d, 0x2, 
    0x23e, 0x240, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x23c, 0x3, 0x2, 0x2, 0x2, 
    0x23f, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x240, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x241, 
    0x242, 0x7, 0x3f, 0x2, 0x2, 0x242, 0x243, 0x5, 0x7c, 0x3f, 0x2, 0x243, 
    0x244, 0x7, 0x40, 0x2, 0x2, 0x244, 0x245, 0x5, 0x7e, 0x40, 0x2, 0x245, 
    0x250, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 0x7, 0x2b, 0x2, 0x2, 0x247, 
    0x250, 0x5, 0x7c, 0x3f, 0x2, 0x248, 0x249, 0x7, 0x2e, 0x2, 0x2, 0x249, 
    0x250, 0x5, 0x7c, 0x3f, 0x2, 0x24a, 0x24b, 0x7, 0x4d, 0x2, 0x2, 0x24b, 
    0x250, 0x5, 0x7c, 0x3f, 0x2, 0x24c, 0x24d, 0x5, 0x78, 0x3d, 0x2, 0x24d, 
    0x24e, 0x5, 0x7e, 0x40, 0x2, 0x24e, 0x250, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x241, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x246, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x248, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x24c, 0x3, 0x2, 0x2, 0x2, 0x250, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x251, 0x265, 
    0x7, 0x2d, 0x2, 0x2, 0x252, 0x265, 0x7, 0x30, 0x2, 0x2, 0x253, 0x265, 
    0x7, 0x2c, 0x2, 0x2, 0x254, 0x265, 0x7, 0x2f, 0x2, 0x2, 0x255, 0x256, 
    0x7, 0x34, 0x2, 0x2, 0x256, 0x265, 0x7, 0x34, 0x2, 0x2, 0x257, 0x258, 
    0x7, 0x2b, 0x2, 0x2, 0x258, 0x265, 0x7, 0x34, 0x2, 0x2, 0x259, 0x265, 
    0x7, 0x2e, 0x2, 0x2, 0x25a, 0x25d, 0x7, 0x45, 0x2, 0x2, 0x25b, 0x25e, 
    0x7, 0x34, 0x2, 0x2, 0x25c, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25b, 
    0x3, 0x2, 0x2, 0x2, 0x25d, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x265, 
    0x3, 0x2, 0x2, 0x2, 0x25f, 0x262, 0x7, 0x46, 0x2, 0x2, 0x260, 0x263, 
    0x7, 0x34, 0x2, 0x2, 0x261, 0x263, 0x3, 0x2, 0x2, 0x2, 0x262, 0x260, 
    0x3, 0x2, 0x2, 0x2, 0x262, 0x261, 0x3, 0x2, 0x2, 0x2, 0x263, 0x265, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x251, 0x3, 0x2, 0x2, 0x2, 0x264, 0x252, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x253, 0x3, 0x2, 0x2, 0x2, 0x264, 0x254, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x255, 0x3, 0x2, 0x2, 0x2, 0x264, 0x257, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x259, 0x3, 0x2, 0x2, 0x2, 0x264, 0x25a, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 
    0x3, 0x2, 0x2, 0x2, 0x266, 0x269, 0x5, 0x7c, 0x3f, 0x2, 0x267, 0x269, 
    0x3, 0x2, 0x2, 0x2, 0x268, 0x264, 0x3, 0x2, 0x2, 0x2, 0x268, 0x267, 
    0x3, 0x2, 0x2, 0x2, 0x269, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26d, 0x5, 
    0x82, 0x42, 0x2, 0x26b, 0x26e, 0x5, 0x86, 0x44, 0x2, 0x26c, 0x26e, 0x3, 
    0x2, 0x2, 0x2, 0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26c, 0x3, 
    0x2, 0x2, 0x2, 0x26e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x7, 0x27, 
    0x2, 0x2, 0x270, 0x273, 0x5, 0x84, 0x43, 0x2, 0x271, 0x274, 0x5, 0x6c, 
    0x37, 0x2, 0x272, 0x274, 0x7, 0x48, 0x2, 0x2, 0x273, 0x271, 0x3, 0x2, 
    0x2, 0x2, 0x273, 0x272, 0x3, 0x2, 0x2, 0x2, 0x274, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x275, 0x276, 0x7, 0x3f, 0x2, 0x2, 0x276, 0x277, 0x5, 0x7c, 0x3f, 
    0x2, 0x277, 0x278, 0x7, 0x40, 0x2, 0x2, 0x278, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x279, 0x27a, 0x7, 0x28, 0x2, 0x2, 0x27a, 0x27b, 0x5, 0x6c, 0x37, 
    0x2, 0x27b, 0x87, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x7, 0x24, 0x2, 
    0x2, 0x27d, 0x27e, 0x5, 0x8a, 0x46, 0x2, 0x27e, 0x282, 0x7, 0x41, 0x2, 
    0x2, 0x27f, 0x281, 0x5, 0x8c, 0x47, 0x2, 0x280, 0x27f, 0x3, 0x2, 0x2, 
    0x2, 0x281, 0x284, 0x3, 0x2, 0x2, 0x2, 0x282, 0x280, 0x3, 0x2, 0x2, 
    0x2, 0x282, 0x283, 0x3, 0x2, 0x2, 0x2, 0x283, 0x287, 0x3, 0x2, 0x2, 
    0x2, 0x284, 0x282, 0x3, 0x2, 0x2, 0x2, 0x285, 0x288, 0x5, 0x8e, 0x48, 
    0x2, 0x286, 0x288, 0x3, 0x2, 0x2, 0x2, 0x287, 0x285, 0x3, 0x2, 0x2, 
    0x2, 0x287, 0x286, 0x3, 0x2, 0x2, 0x2, 0x288, 0x289, 0x3, 0x2, 0x2, 
    0x2, 0x289, 0x28a, 0x7, 0x42, 0x2, 0x2, 0x28a, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x28b, 0x28c, 0x7, 0x3f, 0x2, 0x2, 0x28c, 0x28d, 0x5, 0x22, 0x12, 
    0x2, 0x28d, 0x28e, 0x7, 0x40, 0x2, 0x2, 0x28e, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x28f, 0x290, 0x7, 0x25, 0x2, 0x2, 0x290, 0x291, 0x5, 0x42, 0x22, 
    0x2, 0x291, 0x299, 0x7, 0x47, 0x2, 0x2, 0x292, 0x29a, 0x5, 0x72, 0x3a, 
    0x2, 0x293, 0x295, 0x5, 0x6e, 0x38, 0x2, 0x294, 0x293, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x298, 0x3, 0x2, 0x2, 0x2, 0x296, 0x294, 0x3, 0x2, 0x2, 
    0x2, 0x296, 0x297, 0x3, 0x2, 0x2, 0x2, 0x297, 0x29a, 0x3, 0x2, 0x2, 
    0x2, 0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 0x299, 0x292, 0x3, 0x2, 0x2, 
    0x2, 0x299, 0x296, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x29b, 0x29c, 0x7, 0x26, 0x2, 0x2, 0x29c, 0x2a4, 0x7, 0x47, 0x2, 0x2, 
    0x29d, 0x2a5, 0x5, 0x72, 0x3a, 0x2, 0x29e, 0x2a0, 0x5, 0x6e, 0x38, 0x2, 
    0x29f, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a3, 0x3, 0x2, 0x2, 0x2, 
    0x2a1, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x3, 0x2, 0x2, 0x2, 
    0x2a2, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a1, 0x3, 0x2, 0x2, 0x2, 
    0x2a4, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a1, 0x3, 0x2, 0x2, 0x2, 
    0x2a5, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2ab, 0x5, 0x44, 0x23, 0x2, 
    0x2a7, 0x2ab, 0x5, 0x46, 0x24, 0x2, 0x2a8, 0x2ab, 0x5, 0x5c, 0x2f, 0x2, 
    0x2a9, 0x2ab, 0x5, 0x42, 0x22, 0x2, 0x2aa, 0x2a6, 0x3, 0x2, 0x2, 0x2, 
    0x2aa, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a8, 0x3, 0x2, 0x2, 0x2, 
    0x2aa, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x91, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x9c, 0xaf, 0xb3, 0xb7, 0xbc, 0xc3, 0xca, 0xd7, 0xea, 0xee, 0xfb, 0x107, 
    0x10f, 0x118, 0x11b, 0x125, 0x127, 0x12e, 0x141, 0x146, 0x153, 0x15c, 
    0x165, 0x16e, 0x178, 0x182, 0x189, 0x19a, 0x1a2, 0x1a8, 0x1ae, 0x1bb, 
    0x1bf, 0x1c3, 0x1d0, 0x1da, 0x1e7, 0x1ee, 0x1fc, 0x20b, 0x210, 0x21a, 
    0x223, 0x23a, 0x23f, 0x24f, 0x25d, 0x262, 0x264, 0x268, 0x26d, 0x273, 
    0x282, 0x287, 0x296, 0x299, 0x2a1, 0x2a4, 0x2aa, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SimSystemDeclParser::Initializer SimSystemDeclParser::_init;
