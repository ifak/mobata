
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/StateMachine.g4 by ANTLR 4.7.2


#include "StateMachineListener.h"

#include "StateMachineParser.h"


using namespace antlrcpp;
using namespace antlr4;

StateMachineParser::StateMachineParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

StateMachineParser::~StateMachineParser() {
  delete _interpreter;
}

std::string StateMachineParser::getGrammarFileName() const {
  return "StateMachine.g4";
}

const std::vector<std::string>& StateMachineParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& StateMachineParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StateMachineDeclContext ------------------------------------------------------------------

StateMachineParser::StateMachineDeclContext::StateMachineDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::StateMachineDeclContext::StateMachineID() {
  return getToken(StateMachineParser::StateMachineID, 0);
}

tree::TerminalNode* StateMachineParser::StateMachineDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::StateMachineBodyContext* StateMachineParser::StateMachineDeclContext::stateMachineBody() {
  return getRuleContext<StateMachineParser::StateMachineBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::StateMachineDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::StateMachineDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleStateMachineDecl;
}

void StateMachineParser::StateMachineDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStateMachineDecl(this);
}

void StateMachineParser::StateMachineDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStateMachineDecl(this);
}

StateMachineParser::StateMachineDeclContext* StateMachineParser::stateMachineDecl() {
  StateMachineDeclContext *_localctx = _tracker.createInstance<StateMachineDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, StateMachineParser::RuleStateMachineDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(StateMachineParser::StateMachineID);
    setState(191);
    match(StateMachineParser::LBRACE);
    setState(192);
    stateMachineBody();
    setState(193);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateMachineBodyContext ------------------------------------------------------------------

StateMachineParser::StateMachineBodyContext::StateMachineBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::NameDeclContext* StateMachineParser::StateMachineBodyContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

StateMachineParser::StateMachineBodyOptionalContext* StateMachineParser::StateMachineBodyContext::stateMachineBodyOptional() {
  return getRuleContext<StateMachineParser::StateMachineBodyOptionalContext>(0);
}


size_t StateMachineParser::StateMachineBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleStateMachineBody;
}

void StateMachineParser::StateMachineBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStateMachineBody(this);
}

void StateMachineParser::StateMachineBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStateMachineBody(this);
}

StateMachineParser::StateMachineBodyContext* StateMachineParser::stateMachineBody() {
  StateMachineBodyContext *_localctx = _tracker.createInstance<StateMachineBodyContext>(_ctx, getState());
  enterRule(_localctx, 2, StateMachineParser::RuleStateMachineBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    nameDecl();
    setState(196);
    stateMachineBodyOptional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateMachineBodyOptionalContext ------------------------------------------------------------------

StateMachineParser::StateMachineBodyOptionalContext::StateMachineBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::StateMachineBodyOptionalContext* StateMachineParser::StateMachineBodyOptionalContext::stateMachineBodyOptional() {
  return getRuleContext<StateMachineParser::StateMachineBodyOptionalContext>(0);
}

StateMachineParser::FunctionDeclContext* StateMachineParser::StateMachineBodyOptionalContext::functionDecl() {
  return getRuleContext<StateMachineParser::FunctionDeclContext>(0);
}

StateMachineParser::TypeDefDeclContext* StateMachineParser::StateMachineBodyOptionalContext::typeDefDecl() {
  return getRuleContext<StateMachineParser::TypeDefDeclContext>(0);
}

StateMachineParser::AttributeDeclContext* StateMachineParser::StateMachineBodyOptionalContext::attributeDecl() {
  return getRuleContext<StateMachineParser::AttributeDeclContext>(0);
}

StateMachineParser::SignalDeclContext* StateMachineParser::StateMachineBodyOptionalContext::signalDecl() {
  return getRuleContext<StateMachineParser::SignalDeclContext>(0);
}

StateMachineParser::PortDeclContext* StateMachineParser::StateMachineBodyOptionalContext::portDecl() {
  return getRuleContext<StateMachineParser::PortDeclContext>(0);
}

StateMachineParser::InitStateDeclContext* StateMachineParser::StateMachineBodyOptionalContext::initStateDecl() {
  return getRuleContext<StateMachineParser::InitStateDeclContext>(0);
}

StateMachineParser::SimpleStateDeclContext* StateMachineParser::StateMachineBodyOptionalContext::simpleStateDecl() {
  return getRuleContext<StateMachineParser::SimpleStateDeclContext>(0);
}

StateMachineParser::JunctionStateDeclContext* StateMachineParser::StateMachineBodyOptionalContext::junctionStateDecl() {
  return getRuleContext<StateMachineParser::JunctionStateDeclContext>(0);
}

StateMachineParser::ConcurrentStateDeclContext* StateMachineParser::StateMachineBodyOptionalContext::concurrentStateDecl() {
  return getRuleContext<StateMachineParser::ConcurrentStateDeclContext>(0);
}

StateMachineParser::CompositeStateDeclContext* StateMachineParser::StateMachineBodyOptionalContext::compositeStateDecl() {
  return getRuleContext<StateMachineParser::CompositeStateDeclContext>(0);
}

StateMachineParser::FinalStateDeclContext* StateMachineParser::StateMachineBodyOptionalContext::finalStateDecl() {
  return getRuleContext<StateMachineParser::FinalStateDeclContext>(0);
}

StateMachineParser::TransitionDeclContext* StateMachineParser::StateMachineBodyOptionalContext::transitionDecl() {
  return getRuleContext<StateMachineParser::TransitionDeclContext>(0);
}


size_t StateMachineParser::StateMachineBodyOptionalContext::getRuleIndex() const {
  return StateMachineParser::RuleStateMachineBodyOptional;
}

void StateMachineParser::StateMachineBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStateMachineBodyOptional(this);
}

void StateMachineParser::StateMachineBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStateMachineBodyOptional(this);
}

StateMachineParser::StateMachineBodyOptionalContext* StateMachineParser::stateMachineBodyOptional() {
  StateMachineBodyOptionalContext *_localctx = _tracker.createInstance<StateMachineBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 4, StateMachineParser::RuleStateMachineBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(215);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::SimpleStateID:
      case StateMachineParser::SignalTransitionID:
      case StateMachineParser::CompositeStateID:
      case StateMachineParser::JunctionStateID:
      case StateMachineParser::ConcurrentStateID:
      case StateMachineParser::FinalStateID:
      case StateMachineParser::InitStateID:
      case StateMachineParser::TypeID:
      case StateMachineParser::TimeoutTransitionID:
      case StateMachineParser::AttributeID:
      case StateMachineParser::SignalID:
      case StateMachineParser::PortID:
      case StateMachineParser::FunctionID: {
        enterOuterAlt(_localctx, 1);
        setState(210);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case StateMachineParser::FunctionID: {
            setState(198);
            functionDecl();
            break;
          }

          case StateMachineParser::TypeID: {
            setState(199);
            typeDefDecl();
            break;
          }

          case StateMachineParser::AttributeID: {
            setState(200);
            attributeDecl();
            break;
          }

          case StateMachineParser::SignalID: {
            setState(201);
            signalDecl();
            break;
          }

          case StateMachineParser::PortID: {
            setState(202);
            portDecl();
            break;
          }

          case StateMachineParser::InitStateID: {
            setState(203);
            initStateDecl();
            break;
          }

          case StateMachineParser::SimpleStateID: {
            setState(204);
            simpleStateDecl();
            break;
          }

          case StateMachineParser::JunctionStateID: {
            setState(205);
            junctionStateDecl();
            break;
          }

          case StateMachineParser::ConcurrentStateID: {
            setState(206);
            concurrentStateDecl();
            break;
          }

          case StateMachineParser::CompositeStateID: {
            setState(207);
            compositeStateDecl();
            break;
          }

          case StateMachineParser::FinalStateID: {
            setState(208);
            finalStateDecl();
            break;
          }

          case StateMachineParser::SignalTransitionID:
          case StateMachineParser::TimeoutTransitionID: {
            setState(209);
            transitionDecl();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(212);
        stateMachineBodyOptional();
        break;
      }

      case StateMachineParser::RBRACE: {
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

//----------------- StateDeclContext ------------------------------------------------------------------

StateMachineParser::StateDeclContext::StateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::InitStateDeclContext* StateMachineParser::StateDeclContext::initStateDecl() {
  return getRuleContext<StateMachineParser::InitStateDeclContext>(0);
}

StateMachineParser::SimpleStateDeclContext* StateMachineParser::StateDeclContext::simpleStateDecl() {
  return getRuleContext<StateMachineParser::SimpleStateDeclContext>(0);
}

StateMachineParser::JunctionStateDeclContext* StateMachineParser::StateDeclContext::junctionStateDecl() {
  return getRuleContext<StateMachineParser::JunctionStateDeclContext>(0);
}

StateMachineParser::ConcurrentStateDeclContext* StateMachineParser::StateDeclContext::concurrentStateDecl() {
  return getRuleContext<StateMachineParser::ConcurrentStateDeclContext>(0);
}

StateMachineParser::CompositeStateDeclContext* StateMachineParser::StateDeclContext::compositeStateDecl() {
  return getRuleContext<StateMachineParser::CompositeStateDeclContext>(0);
}

StateMachineParser::FinalStateDeclContext* StateMachineParser::StateDeclContext::finalStateDecl() {
  return getRuleContext<StateMachineParser::FinalStateDeclContext>(0);
}


size_t StateMachineParser::StateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleStateDecl;
}

void StateMachineParser::StateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStateDecl(this);
}

void StateMachineParser::StateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStateDecl(this);
}

StateMachineParser::StateDeclContext* StateMachineParser::stateDecl() {
  StateDeclContext *_localctx = _tracker.createInstance<StateDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, StateMachineParser::RuleStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::InitStateID: {
        enterOuterAlt(_localctx, 1);
        setState(217);
        initStateDecl();
        break;
      }

      case StateMachineParser::SimpleStateID: {
        enterOuterAlt(_localctx, 2);
        setState(218);
        simpleStateDecl();
        break;
      }

      case StateMachineParser::JunctionStateID: {
        enterOuterAlt(_localctx, 3);
        setState(219);
        junctionStateDecl();
        break;
      }

      case StateMachineParser::ConcurrentStateID: {
        enterOuterAlt(_localctx, 4);
        setState(220);
        concurrentStateDecl();
        break;
      }

      case StateMachineParser::CompositeStateID: {
        enterOuterAlt(_localctx, 5);
        setState(221);
        compositeStateDecl();
        break;
      }

      case StateMachineParser::FinalStateID: {
        enterOuterAlt(_localctx, 6);
        setState(222);
        finalStateDecl();
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

//----------------- StateIdPathContext ------------------------------------------------------------------

StateMachineParser::StateIdPathContext::StateIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::StateIdPathContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::StateIdPathContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> StateMachineParser::StateIdPathContext::DOT() {
  return getTokens(StateMachineParser::DOT);
}

tree::TerminalNode* StateMachineParser::StateIdPathContext::DOT(size_t i) {
  return getToken(StateMachineParser::DOT, i);
}


size_t StateMachineParser::StateIdPathContext::getRuleIndex() const {
  return StateMachineParser::RuleStateIdPath;
}

void StateMachineParser::StateIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStateIdPath(this);
}

void StateMachineParser::StateIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStateIdPath(this);
}

StateMachineParser::StateIdPathContext* StateMachineParser::stateIdPath() {
  StateIdPathContext *_localctx = _tracker.createInstance<StateIdPathContext>(_ctx, getState());
  enterRule(_localctx, 8, StateMachineParser::RuleStateIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    contextID();
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::DOT) {
      setState(226);
      match(StateMachineParser::DOT);
      setState(227);
      contextID();
      setState(232);
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

//----------------- StateDeclsContext ------------------------------------------------------------------

StateMachineParser::StateDeclsContext::StateDeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::StateDeclContext* StateMachineParser::StateDeclsContext::stateDecl() {
  return getRuleContext<StateMachineParser::StateDeclContext>(0);
}

StateMachineParser::StateDeclsContext* StateMachineParser::StateDeclsContext::stateDecls() {
  return getRuleContext<StateMachineParser::StateDeclsContext>(0);
}


size_t StateMachineParser::StateDeclsContext::getRuleIndex() const {
  return StateMachineParser::RuleStateDecls;
}

void StateMachineParser::StateDeclsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStateDecls(this);
}

void StateMachineParser::StateDeclsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStateDecls(this);
}

StateMachineParser::StateDeclsContext* StateMachineParser::stateDecls() {
  StateDeclsContext *_localctx = _tracker.createInstance<StateDeclsContext>(_ctx, getState());
  enterRule(_localctx, 10, StateMachineParser::RuleStateDecls);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(237);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::SimpleStateID:
      case StateMachineParser::CompositeStateID:
      case StateMachineParser::JunctionStateID:
      case StateMachineParser::ConcurrentStateID:
      case StateMachineParser::FinalStateID:
      case StateMachineParser::InitStateID: {
        enterOuterAlt(_localctx, 1);
        setState(233);
        stateDecl();
        setState(234);
        stateDecls();
        break;
      }

      case StateMachineParser::RBRACE: {
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

//----------------- SimpleStateDeclContext ------------------------------------------------------------------

StateMachineParser::SimpleStateDeclContext::SimpleStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::SimpleStateDeclContext::SimpleStateID() {
  return getToken(StateMachineParser::SimpleStateID, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::SimpleStateDeclContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

tree::TerminalNode* StateMachineParser::SimpleStateDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

tree::TerminalNode* StateMachineParser::SimpleStateDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::SimpleStateBodyContext* StateMachineParser::SimpleStateDeclContext::simpleStateBody() {
  return getRuleContext<StateMachineParser::SimpleStateBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::SimpleStateDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::SimpleStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleSimpleStateDecl;
}

void StateMachineParser::SimpleStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleStateDecl(this);
}

void StateMachineParser::SimpleStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleStateDecl(this);
}

StateMachineParser::SimpleStateDeclContext* StateMachineParser::simpleStateDecl() {
  SimpleStateDeclContext *_localctx = _tracker.createInstance<SimpleStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, StateMachineParser::RuleSimpleStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(StateMachineParser::SimpleStateID);
    setState(247);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ID: {
        setState(240);
        contextID();
        setState(241);
        match(StateMachineParser::SEMI);
        break;
      }

      case StateMachineParser::LBRACE: {
        setState(243);
        match(StateMachineParser::LBRACE);
        setState(244);
        simpleStateBody();
        setState(245);
        match(StateMachineParser::RBRACE);
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

//----------------- AttributeAssignStatementContext ------------------------------------------------------------------

StateMachineParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::AttributeNameContext* StateMachineParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<StateMachineParser::AttributeNameContext>(0);
}

tree::TerminalNode* StateMachineParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(StateMachineParser::ASSIGN, 0);
}

StateMachineParser::OperationContext* StateMachineParser::AttributeAssignStatementContext::operation() {
  return getRuleContext<StateMachineParser::OperationContext>(0);
}

tree::TerminalNode* StateMachineParser::AttributeAssignStatementContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::AttributeAssignStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleAttributeAssignStatement;
}

void StateMachineParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void StateMachineParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

StateMachineParser::AttributeAssignStatementContext* StateMachineParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, StateMachineParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    attributeName();
    setState(250);
    match(StateMachineParser::ASSIGN);
    setState(251);
    operation();
    setState(252);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStateBodyContext ------------------------------------------------------------------

StateMachineParser::SimpleStateBodyContext::SimpleStateBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::NameDeclContext* StateMachineParser::SimpleStateBodyContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

StateMachineParser::EntryActionDeclContext* StateMachineParser::SimpleStateBodyContext::entryActionDecl() {
  return getRuleContext<StateMachineParser::EntryActionDeclContext>(0);
}

StateMachineParser::ExitActionDeclContext* StateMachineParser::SimpleStateBodyContext::exitActionDecl() {
  return getRuleContext<StateMachineParser::ExitActionDeclContext>(0);
}


size_t StateMachineParser::SimpleStateBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleSimpleStateBody;
}

void StateMachineParser::SimpleStateBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleStateBody(this);
}

void StateMachineParser::SimpleStateBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleStateBody(this);
}

StateMachineParser::SimpleStateBodyContext* StateMachineParser::simpleStateBody() {
  SimpleStateBodyContext *_localctx = _tracker.createInstance<SimpleStateBodyContext>(_ctx, getState());
  enterRule(_localctx, 16, StateMachineParser::RuleSimpleStateBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    nameDecl();
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::EntryActionID: {
        setState(255);
        entryActionDecl();
        break;
      }

      case StateMachineParser::SimpleStateID:
      case StateMachineParser::CompositeStateID:
      case StateMachineParser::JunctionStateID:
      case StateMachineParser::ConcurrentStateID:
      case StateMachineParser::FinalStateID:
      case StateMachineParser::RegionID:
      case StateMachineParser::InitStateID:
      case StateMachineParser::ExitActionID:
      case StateMachineParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ExitActionID: {
        setState(259);
        exitActionDecl();
        break;
      }

      case StateMachineParser::SimpleStateID:
      case StateMachineParser::CompositeStateID:
      case StateMachineParser::JunctionStateID:
      case StateMachineParser::ConcurrentStateID:
      case StateMachineParser::FinalStateID:
      case StateMachineParser::RegionID:
      case StateMachineParser::InitStateID:
      case StateMachineParser::RBRACE: {
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

//----------------- JunctionStateDeclContext ------------------------------------------------------------------

StateMachineParser::JunctionStateDeclContext::JunctionStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::JunctionStateDeclContext::JunctionStateID() {
  return getToken(StateMachineParser::JunctionStateID, 0);
}

tree::TerminalNode* StateMachineParser::JunctionStateDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::NameDeclContext* StateMachineParser::JunctionStateDeclContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

StateMachineParser::JunctionTransitionDeclsContext* StateMachineParser::JunctionStateDeclContext::junctionTransitionDecls() {
  return getRuleContext<StateMachineParser::JunctionTransitionDeclsContext>(0);
}

tree::TerminalNode* StateMachineParser::JunctionStateDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::JunctionStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleJunctionStateDecl;
}

void StateMachineParser::JunctionStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJunctionStateDecl(this);
}

void StateMachineParser::JunctionStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJunctionStateDecl(this);
}

StateMachineParser::JunctionStateDeclContext* StateMachineParser::junctionStateDecl() {
  JunctionStateDeclContext *_localctx = _tracker.createInstance<JunctionStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, StateMachineParser::RuleJunctionStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(StateMachineParser::JunctionStateID);
    setState(264);
    match(StateMachineParser::LBRACE);
    setState(265);
    nameDecl();
    setState(266);
    junctionTransitionDecls();
    setState(267);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JunctionTransitionDeclsContext ------------------------------------------------------------------

StateMachineParser::JunctionTransitionDeclsContext::JunctionTransitionDeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::JunctionTransitionDeclContext* StateMachineParser::JunctionTransitionDeclsContext::junctionTransitionDecl() {
  return getRuleContext<StateMachineParser::JunctionTransitionDeclContext>(0);
}

StateMachineParser::JunctionTransitionDeclsContext* StateMachineParser::JunctionTransitionDeclsContext::junctionTransitionDecls() {
  return getRuleContext<StateMachineParser::JunctionTransitionDeclsContext>(0);
}


size_t StateMachineParser::JunctionTransitionDeclsContext::getRuleIndex() const {
  return StateMachineParser::RuleJunctionTransitionDecls;
}

void StateMachineParser::JunctionTransitionDeclsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJunctionTransitionDecls(this);
}

void StateMachineParser::JunctionTransitionDeclsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJunctionTransitionDecls(this);
}

StateMachineParser::JunctionTransitionDeclsContext* StateMachineParser::junctionTransitionDecls() {
  JunctionTransitionDeclsContext *_localctx = _tracker.createInstance<JunctionTransitionDeclsContext>(_ctx, getState());
  enterRule(_localctx, 20, StateMachineParser::RuleJunctionTransitionDecls);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::JunctionTransitionID: {
        enterOuterAlt(_localctx, 1);
        setState(269);
        junctionTransitionDecl();
        setState(270);
        junctionTransitionDecls();
        break;
      }

      case StateMachineParser::RBRACE: {
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

//----------------- JunctionTransitionDeclContext ------------------------------------------------------------------

StateMachineParser::JunctionTransitionDeclContext::JunctionTransitionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::JunctionTransitionDeclContext::JunctionTransitionID() {
  return getToken(StateMachineParser::JunctionTransitionID, 0);
}

tree::TerminalNode* StateMachineParser::JunctionTransitionDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::JunctionTransitionBodyContext* StateMachineParser::JunctionTransitionDeclContext::junctionTransitionBody() {
  return getRuleContext<StateMachineParser::JunctionTransitionBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::JunctionTransitionDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::JunctionTransitionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleJunctionTransitionDecl;
}

void StateMachineParser::JunctionTransitionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJunctionTransitionDecl(this);
}

void StateMachineParser::JunctionTransitionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJunctionTransitionDecl(this);
}

StateMachineParser::JunctionTransitionDeclContext* StateMachineParser::junctionTransitionDecl() {
  JunctionTransitionDeclContext *_localctx = _tracker.createInstance<JunctionTransitionDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, StateMachineParser::RuleJunctionTransitionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    match(StateMachineParser::JunctionTransitionID);
    setState(276);
    match(StateMachineParser::LBRACE);
    setState(277);
    junctionTransitionBody();
    setState(278);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JunctionTransitionBodyContext ------------------------------------------------------------------

StateMachineParser::JunctionTransitionBodyContext::JunctionTransitionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::NameDeclContext* StateMachineParser::JunctionTransitionBodyContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

StateMachineParser::TargetStateDeclContext* StateMachineParser::JunctionTransitionBodyContext::targetStateDecl() {
  return getRuleContext<StateMachineParser::TargetStateDeclContext>(0);
}

StateMachineParser::GuardDeclContext* StateMachineParser::JunctionTransitionBodyContext::guardDecl() {
  return getRuleContext<StateMachineParser::GuardDeclContext>(0);
}

StateMachineParser::ActionDeclContext* StateMachineParser::JunctionTransitionBodyContext::actionDecl() {
  return getRuleContext<StateMachineParser::ActionDeclContext>(0);
}


size_t StateMachineParser::JunctionTransitionBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleJunctionTransitionBody;
}

void StateMachineParser::JunctionTransitionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJunctionTransitionBody(this);
}

void StateMachineParser::JunctionTransitionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJunctionTransitionBody(this);
}

StateMachineParser::JunctionTransitionBodyContext* StateMachineParser::junctionTransitionBody() {
  JunctionTransitionBodyContext *_localctx = _tracker.createInstance<JunctionTransitionBodyContext>(_ctx, getState());
  enterRule(_localctx, 24, StateMachineParser::RuleJunctionTransitionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    nameDecl();
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::GuardID: {
        setState(281);
        guardDecl();
        break;
      }

      case StateMachineParser::ActionID:
      case StateMachineParser::TargetStateID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ActionID: {
        setState(285);
        actionDecl();
        break;
      }

      case StateMachineParser::TargetStateID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(289);
    targetStateDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConcurrentStateDeclContext ------------------------------------------------------------------

StateMachineParser::ConcurrentStateDeclContext::ConcurrentStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ConcurrentStateDeclContext::ConcurrentStateID() {
  return getToken(StateMachineParser::ConcurrentStateID, 0);
}

tree::TerminalNode* StateMachineParser::ConcurrentStateDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::ConcurrentStateBodyContext* StateMachineParser::ConcurrentStateDeclContext::concurrentStateBody() {
  return getRuleContext<StateMachineParser::ConcurrentStateBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::ConcurrentStateDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::ConcurrentStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleConcurrentStateDecl;
}

void StateMachineParser::ConcurrentStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrentStateDecl(this);
}

void StateMachineParser::ConcurrentStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrentStateDecl(this);
}

StateMachineParser::ConcurrentStateDeclContext* StateMachineParser::concurrentStateDecl() {
  ConcurrentStateDeclContext *_localctx = _tracker.createInstance<ConcurrentStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 26, StateMachineParser::RuleConcurrentStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    match(StateMachineParser::ConcurrentStateID);
    setState(292);
    match(StateMachineParser::LBRACE);
    setState(293);
    concurrentStateBody();
    setState(294);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConcurrentStateBodyContext ------------------------------------------------------------------

StateMachineParser::ConcurrentStateBodyContext::ConcurrentStateBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::SimpleStateBodyContext* StateMachineParser::ConcurrentStateBodyContext::simpleStateBody() {
  return getRuleContext<StateMachineParser::SimpleStateBodyContext>(0);
}

StateMachineParser::RegionDeclsContext* StateMachineParser::ConcurrentStateBodyContext::regionDecls() {
  return getRuleContext<StateMachineParser::RegionDeclsContext>(0);
}


size_t StateMachineParser::ConcurrentStateBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleConcurrentStateBody;
}

void StateMachineParser::ConcurrentStateBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcurrentStateBody(this);
}

void StateMachineParser::ConcurrentStateBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcurrentStateBody(this);
}

StateMachineParser::ConcurrentStateBodyContext* StateMachineParser::concurrentStateBody() {
  ConcurrentStateBodyContext *_localctx = _tracker.createInstance<ConcurrentStateBodyContext>(_ctx, getState());
  enterRule(_localctx, 28, StateMachineParser::RuleConcurrentStateBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    simpleStateBody();
    setState(297);
    regionDecls();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegionDeclContext ------------------------------------------------------------------

StateMachineParser::RegionDeclContext::RegionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::RegionDeclContext::RegionID() {
  return getToken(StateMachineParser::RegionID, 0);
}

tree::TerminalNode* StateMachineParser::RegionDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::RegionBodyContext* StateMachineParser::RegionDeclContext::regionBody() {
  return getRuleContext<StateMachineParser::RegionBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::RegionDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::RegionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleRegionDecl;
}

void StateMachineParser::RegionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegionDecl(this);
}

void StateMachineParser::RegionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegionDecl(this);
}

StateMachineParser::RegionDeclContext* StateMachineParser::regionDecl() {
  RegionDeclContext *_localctx = _tracker.createInstance<RegionDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, StateMachineParser::RuleRegionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    match(StateMachineParser::RegionID);
    setState(300);
    match(StateMachineParser::LBRACE);
    setState(301);
    regionBody();
    setState(302);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegionDeclsContext ------------------------------------------------------------------

StateMachineParser::RegionDeclsContext::RegionDeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::RegionDeclContext* StateMachineParser::RegionDeclsContext::regionDecl() {
  return getRuleContext<StateMachineParser::RegionDeclContext>(0);
}

StateMachineParser::RegionDeclsContext* StateMachineParser::RegionDeclsContext::regionDecls() {
  return getRuleContext<StateMachineParser::RegionDeclsContext>(0);
}


size_t StateMachineParser::RegionDeclsContext::getRuleIndex() const {
  return StateMachineParser::RuleRegionDecls;
}

void StateMachineParser::RegionDeclsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegionDecls(this);
}

void StateMachineParser::RegionDeclsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegionDecls(this);
}

StateMachineParser::RegionDeclsContext* StateMachineParser::regionDecls() {
  RegionDeclsContext *_localctx = _tracker.createInstance<RegionDeclsContext>(_ctx, getState());
  enterRule(_localctx, 32, StateMachineParser::RuleRegionDecls);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::RegionID: {
        enterOuterAlt(_localctx, 1);
        setState(304);
        regionDecl();
        setState(305);
        regionDecls();
        break;
      }

      case StateMachineParser::RBRACE: {
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

//----------------- RegionBodyContext ------------------------------------------------------------------

StateMachineParser::RegionBodyContext::RegionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::NameDeclContext* StateMachineParser::RegionBodyContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

StateMachineParser::StateDeclsContext* StateMachineParser::RegionBodyContext::stateDecls() {
  return getRuleContext<StateMachineParser::StateDeclsContext>(0);
}


size_t StateMachineParser::RegionBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleRegionBody;
}

void StateMachineParser::RegionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegionBody(this);
}

void StateMachineParser::RegionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegionBody(this);
}

StateMachineParser::RegionBodyContext* StateMachineParser::regionBody() {
  RegionBodyContext *_localctx = _tracker.createInstance<RegionBodyContext>(_ctx, getState());
  enterRule(_localctx, 34, StateMachineParser::RuleRegionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    nameDecl();
    setState(311);
    stateDecls();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositeStateDeclContext ------------------------------------------------------------------

StateMachineParser::CompositeStateDeclContext::CompositeStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::CompositeStateDeclContext::CompositeStateID() {
  return getToken(StateMachineParser::CompositeStateID, 0);
}

tree::TerminalNode* StateMachineParser::CompositeStateDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::CompositeStateBodyContext* StateMachineParser::CompositeStateDeclContext::compositeStateBody() {
  return getRuleContext<StateMachineParser::CompositeStateBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::CompositeStateDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::CompositeStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleCompositeStateDecl;
}

void StateMachineParser::CompositeStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompositeStateDecl(this);
}

void StateMachineParser::CompositeStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompositeStateDecl(this);
}

StateMachineParser::CompositeStateDeclContext* StateMachineParser::compositeStateDecl() {
  CompositeStateDeclContext *_localctx = _tracker.createInstance<CompositeStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, StateMachineParser::RuleCompositeStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    match(StateMachineParser::CompositeStateID);
    setState(314);
    match(StateMachineParser::LBRACE);
    setState(315);
    compositeStateBody();
    setState(316);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositeStateBodyContext ------------------------------------------------------------------

StateMachineParser::CompositeStateBodyContext::CompositeStateBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::SimpleStateBodyContext* StateMachineParser::CompositeStateBodyContext::simpleStateBody() {
  return getRuleContext<StateMachineParser::SimpleStateBodyContext>(0);
}

StateMachineParser::StateDeclsContext* StateMachineParser::CompositeStateBodyContext::stateDecls() {
  return getRuleContext<StateMachineParser::StateDeclsContext>(0);
}


size_t StateMachineParser::CompositeStateBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleCompositeStateBody;
}

void StateMachineParser::CompositeStateBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompositeStateBody(this);
}

void StateMachineParser::CompositeStateBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompositeStateBody(this);
}

StateMachineParser::CompositeStateBodyContext* StateMachineParser::compositeStateBody() {
  CompositeStateBodyContext *_localctx = _tracker.createInstance<CompositeStateBodyContext>(_ctx, getState());
  enterRule(_localctx, 38, StateMachineParser::RuleCompositeStateBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    simpleStateBody();
    setState(319);
    stateDecls();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FinalStateDeclContext ------------------------------------------------------------------

StateMachineParser::FinalStateDeclContext::FinalStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::FinalStateDeclContext::FinalStateID() {
  return getToken(StateMachineParser::FinalStateID, 0);
}

tree::TerminalNode* StateMachineParser::FinalStateDeclContext::ID() {
  return getToken(StateMachineParser::ID, 0);
}

tree::TerminalNode* StateMachineParser::FinalStateDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

tree::TerminalNode* StateMachineParser::FinalStateDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::NameDeclContext* StateMachineParser::FinalStateDeclContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

tree::TerminalNode* StateMachineParser::FinalStateDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::FinalStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleFinalStateDecl;
}

void StateMachineParser::FinalStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFinalStateDecl(this);
}

void StateMachineParser::FinalStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFinalStateDecl(this);
}

StateMachineParser::FinalStateDeclContext* StateMachineParser::finalStateDecl() {
  FinalStateDeclContext *_localctx = _tracker.createInstance<FinalStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 40, StateMachineParser::RuleFinalStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(StateMachineParser::FinalStateID);
    setState(328);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ID: {
        setState(322);
        match(StateMachineParser::ID);
        setState(323);
        match(StateMachineParser::SEMI);
        break;
      }

      case StateMachineParser::LBRACE: {
        setState(324);
        match(StateMachineParser::LBRACE);
        setState(325);
        nameDecl();
        setState(326);
        match(StateMachineParser::RBRACE);
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

//----------------- InitStateDeclContext ------------------------------------------------------------------

StateMachineParser::InitStateDeclContext::InitStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::InitStateDeclContext::InitStateID() {
  return getToken(StateMachineParser::InitStateID, 0);
}

tree::TerminalNode* StateMachineParser::InitStateDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::IdPathContext* StateMachineParser::InitStateDeclContext::idPath() {
  return getRuleContext<StateMachineParser::IdPathContext>(0);
}

tree::TerminalNode* StateMachineParser::InitStateDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::InitStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleInitStateDecl;
}

void StateMachineParser::InitStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitStateDecl(this);
}

void StateMachineParser::InitStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitStateDecl(this);
}

StateMachineParser::InitStateDeclContext* StateMachineParser::initStateDecl() {
  InitStateDeclContext *_localctx = _tracker.createInstance<InitStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 42, StateMachineParser::RuleInitStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(StateMachineParser::InitStateID);
    setState(331);
    match(StateMachineParser::COLON);
    setState(332);
    idPath();
    setState(333);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GuardDeclContext ------------------------------------------------------------------

StateMachineParser::GuardDeclContext::GuardDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::GuardDeclContext::GuardID() {
  return getToken(StateMachineParser::GuardID, 0);
}

tree::TerminalNode* StateMachineParser::GuardDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::ExpressionContext* StateMachineParser::GuardDeclContext::expression() {
  return getRuleContext<StateMachineParser::ExpressionContext>(0);
}

tree::TerminalNode* StateMachineParser::GuardDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

tree::TerminalNode* StateMachineParser::GuardDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

tree::TerminalNode* StateMachineParser::GuardDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}

tree::TerminalNode* StateMachineParser::GuardDeclContext::ElseID() {
  return getToken(StateMachineParser::ElseID, 0);
}


size_t StateMachineParser::GuardDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleGuardDecl;
}

void StateMachineParser::GuardDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGuardDecl(this);
}

void StateMachineParser::GuardDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGuardDecl(this);
}

StateMachineParser::GuardDeclContext* StateMachineParser::guardDecl() {
  GuardDeclContext *_localctx = _tracker.createInstance<GuardDeclContext>(_ctx, getState());
  enterRule(_localctx, 44, StateMachineParser::RuleGuardDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(StateMachineParser::GuardID);
    setState(336);
    match(StateMachineParser::COLON);
    setState(346);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::TriggerID:
      case StateMachineParser::MessageTrigger:
      case StateMachineParser::ThisID:
      case StateMachineParser::NotIdSymbol:
      case StateMachineParser::NotIdWord:
      case StateMachineParser::TrueID:
      case StateMachineParser::FalseID:
      case StateMachineParser::INT:
      case StateMachineParser::REAL:
      case StateMachineParser::STRING:
      case StateMachineParser::ID:
      case StateMachineParser::LPAREN:
      case StateMachineParser::MINUS: {
        setState(337);
        expression();
        setState(338);
        match(StateMachineParser::SEMI);
        break;
      }

      case StateMachineParser::LBRACE: {
        setState(340);
        match(StateMachineParser::LBRACE);
        setState(341);
        expression();
        setState(342);
        match(StateMachineParser::RBRACE);
        break;
      }

      case StateMachineParser::ElseID: {
        setState(344);
        match(StateMachineParser::ElseID);
        setState(345);
        match(StateMachineParser::SEMI);
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

//----------------- ActionDeclContext ------------------------------------------------------------------

StateMachineParser::ActionDeclContext::ActionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ActionDeclContext::ActionID() {
  return getToken(StateMachineParser::ActionID, 0);
}

tree::TerminalNode* StateMachineParser::ActionDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::ActionStatementBodyContext* StateMachineParser::ActionDeclContext::actionStatementBody() {
  return getRuleContext<StateMachineParser::ActionStatementBodyContext>(0);
}

StateMachineParser::ActionNestedStatementBodyContext* StateMachineParser::ActionDeclContext::actionNestedStatementBody() {
  return getRuleContext<StateMachineParser::ActionNestedStatementBodyContext>(0);
}


size_t StateMachineParser::ActionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleActionDecl;
}

void StateMachineParser::ActionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActionDecl(this);
}

void StateMachineParser::ActionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActionDecl(this);
}

StateMachineParser::ActionDeclContext* StateMachineParser::actionDecl() {
  ActionDeclContext *_localctx = _tracker.createInstance<ActionDeclContext>(_ctx, getState());
  enterRule(_localctx, 46, StateMachineParser::RuleActionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(StateMachineParser::ActionID);
    setState(349);
    match(StateMachineParser::COLON);
    setState(352);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ThisID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID: {
        setState(350);
        actionStatementBody();
        break;
      }

      case StateMachineParser::LBRACE: {
        setState(351);
        actionNestedStatementBody();
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

//----------------- ActionStatementBodyContext ------------------------------------------------------------------

StateMachineParser::ActionStatementBodyContext::ActionStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::SendToStatementContext* StateMachineParser::ActionStatementBodyContext::sendToStatement() {
  return getRuleContext<StateMachineParser::SendToStatementContext>(0);
}

StateMachineParser::SwitchStatementContext* StateMachineParser::ActionStatementBodyContext::switchStatement() {
  return getRuleContext<StateMachineParser::SwitchStatementContext>(0);
}

StateMachineParser::ConditionalStatementContext* StateMachineParser::ActionStatementBodyContext::conditionalStatement() {
  return getRuleContext<StateMachineParser::ConditionalStatementContext>(0);
}

StateMachineParser::BreakStatementContext* StateMachineParser::ActionStatementBodyContext::breakStatement() {
  return getRuleContext<StateMachineParser::BreakStatementContext>(0);
}

StateMachineParser::ContextIDStatementsContext* StateMachineParser::ActionStatementBodyContext::contextIDStatements() {
  return getRuleContext<StateMachineParser::ContextIDStatementsContext>(0);
}


size_t StateMachineParser::ActionStatementBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleActionStatementBody;
}

void StateMachineParser::ActionStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActionStatementBody(this);
}

void StateMachineParser::ActionStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActionStatementBody(this);
}

StateMachineParser::ActionStatementBodyContext* StateMachineParser::actionStatementBody() {
  ActionStatementBodyContext *_localctx = _tracker.createInstance<ActionStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 48, StateMachineParser::RuleActionStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(359);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::SendID: {
        enterOuterAlt(_localctx, 1);
        setState(354);
        sendToStatement();
        break;
      }

      case StateMachineParser::SwitchID: {
        enterOuterAlt(_localctx, 2);
        setState(355);
        switchStatement();
        break;
      }

      case StateMachineParser::IfID: {
        enterOuterAlt(_localctx, 3);
        setState(356);
        conditionalStatement();
        break;
      }

      case StateMachineParser::BREAK: {
        enterOuterAlt(_localctx, 4);
        setState(357);
        breakStatement();
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ThisID:
      case StateMachineParser::ID: {
        enterOuterAlt(_localctx, 5);
        setState(358);
        contextIDStatements();
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

//----------------- ContextIDStatementsContext ------------------------------------------------------------------

StateMachineParser::ContextIDStatementsContext::ContextIDStatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::FunctionCallStatementContext* StateMachineParser::ContextIDStatementsContext::functionCallStatement() {
  return getRuleContext<StateMachineParser::FunctionCallStatementContext>(0);
}

StateMachineParser::AttributeAssignStatementContext* StateMachineParser::ContextIDStatementsContext::attributeAssignStatement() {
  return getRuleContext<StateMachineParser::AttributeAssignStatementContext>(0);
}


size_t StateMachineParser::ContextIDStatementsContext::getRuleIndex() const {
  return StateMachineParser::RuleContextIDStatements;
}

void StateMachineParser::ContextIDStatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextIDStatements(this);
}

void StateMachineParser::ContextIDStatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextIDStatements(this);
}

StateMachineParser::ContextIDStatementsContext* StateMachineParser::contextIDStatements() {
  ContextIDStatementsContext *_localctx = _tracker.createInstance<ContextIDStatementsContext>(_ctx, getState());
  enterRule(_localctx, 50, StateMachineParser::RuleContextIDStatements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(361);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(362);
      attributeAssignStatement();
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

//----------------- ActionStatementBodiesContext ------------------------------------------------------------------

StateMachineParser::ActionStatementBodiesContext::ActionStatementBodiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::ActionStatementBodyContext* StateMachineParser::ActionStatementBodiesContext::actionStatementBody() {
  return getRuleContext<StateMachineParser::ActionStatementBodyContext>(0);
}

StateMachineParser::ActionStatementBodiesContext* StateMachineParser::ActionStatementBodiesContext::actionStatementBodies() {
  return getRuleContext<StateMachineParser::ActionStatementBodiesContext>(0);
}


size_t StateMachineParser::ActionStatementBodiesContext::getRuleIndex() const {
  return StateMachineParser::RuleActionStatementBodies;
}

void StateMachineParser::ActionStatementBodiesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActionStatementBodies(this);
}

void StateMachineParser::ActionStatementBodiesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActionStatementBodies(this);
}

StateMachineParser::ActionStatementBodiesContext* StateMachineParser::actionStatementBodies() {
  ActionStatementBodiesContext *_localctx = _tracker.createInstance<ActionStatementBodiesContext>(_ctx, getState());
  enterRule(_localctx, 52, StateMachineParser::RuleActionStatementBodies);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(369);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ThisID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(365);
        actionStatementBody();
        setState(366);
        actionStatementBodies();
        break;
      }

      case StateMachineParser::RBRACE: {
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

//----------------- ActionNestedStatementBodyContext ------------------------------------------------------------------

StateMachineParser::ActionNestedStatementBodyContext::ActionNestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ActionNestedStatementBodyContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::ActionStatementBodiesContext* StateMachineParser::ActionNestedStatementBodyContext::actionStatementBodies() {
  return getRuleContext<StateMachineParser::ActionStatementBodiesContext>(0);
}

tree::TerminalNode* StateMachineParser::ActionNestedStatementBodyContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::ActionNestedStatementBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleActionNestedStatementBody;
}

void StateMachineParser::ActionNestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActionNestedStatementBody(this);
}

void StateMachineParser::ActionNestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActionNestedStatementBody(this);
}

StateMachineParser::ActionNestedStatementBodyContext* StateMachineParser::actionNestedStatementBody() {
  ActionNestedStatementBodyContext *_localctx = _tracker.createInstance<ActionNestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 54, StateMachineParser::RuleActionNestedStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    match(StateMachineParser::LBRACE);
    setState(372);
    actionStatementBodies();
    setState(373);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransitionDeclContext ------------------------------------------------------------------

StateMachineParser::TransitionDeclContext::TransitionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::SignalTransitionDeclContext* StateMachineParser::TransitionDeclContext::signalTransitionDecl() {
  return getRuleContext<StateMachineParser::SignalTransitionDeclContext>(0);
}

StateMachineParser::TimeoutTransitionDeclContext* StateMachineParser::TransitionDeclContext::timeoutTransitionDecl() {
  return getRuleContext<StateMachineParser::TimeoutTransitionDeclContext>(0);
}


size_t StateMachineParser::TransitionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleTransitionDecl;
}

void StateMachineParser::TransitionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransitionDecl(this);
}

void StateMachineParser::TransitionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransitionDecl(this);
}

StateMachineParser::TransitionDeclContext* StateMachineParser::transitionDecl() {
  TransitionDeclContext *_localctx = _tracker.createInstance<TransitionDeclContext>(_ctx, getState());
  enterRule(_localctx, 56, StateMachineParser::RuleTransitionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::SignalTransitionID: {
        enterOuterAlt(_localctx, 1);
        setState(375);
        signalTransitionDecl();
        break;
      }

      case StateMachineParser::TimeoutTransitionID: {
        enterOuterAlt(_localctx, 2);
        setState(376);
        timeoutTransitionDecl();
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

//----------------- SignalTransitionDeclContext ------------------------------------------------------------------

StateMachineParser::SignalTransitionDeclContext::SignalTransitionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::SignalTransitionDeclContext::SignalTransitionID() {
  return getToken(StateMachineParser::SignalTransitionID, 0);
}

tree::TerminalNode* StateMachineParser::SignalTransitionDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::SignalTransitionBodyContext* StateMachineParser::SignalTransitionDeclContext::signalTransitionBody() {
  return getRuleContext<StateMachineParser::SignalTransitionBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::SignalTransitionDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::SignalTransitionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleSignalTransitionDecl;
}

void StateMachineParser::SignalTransitionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalTransitionDecl(this);
}

void StateMachineParser::SignalTransitionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalTransitionDecl(this);
}

StateMachineParser::SignalTransitionDeclContext* StateMachineParser::signalTransitionDecl() {
  SignalTransitionDeclContext *_localctx = _tracker.createInstance<SignalTransitionDeclContext>(_ctx, getState());
  enterRule(_localctx, 58, StateMachineParser::RuleSignalTransitionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    match(StateMachineParser::SignalTransitionID);
    setState(380);
    match(StateMachineParser::LBRACE);
    setState(381);
    signalTransitionBody();
    setState(382);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalTransitionBodyContext ------------------------------------------------------------------

StateMachineParser::SignalTransitionBodyContext::SignalTransitionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::NameDeclContext* StateMachineParser::SignalTransitionBodyContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

StateMachineParser::SourceStateDeclContext* StateMachineParser::SignalTransitionBodyContext::sourceStateDecl() {
  return getRuleContext<StateMachineParser::SourceStateDeclContext>(0);
}

StateMachineParser::TargetStateDeclContext* StateMachineParser::SignalTransitionBodyContext::targetStateDecl() {
  return getRuleContext<StateMachineParser::TargetStateDeclContext>(0);
}

StateMachineParser::RefSignalDeclContext* StateMachineParser::SignalTransitionBodyContext::refSignalDecl() {
  return getRuleContext<StateMachineParser::RefSignalDeclContext>(0);
}

StateMachineParser::RefPortDeclContext* StateMachineParser::SignalTransitionBodyContext::refPortDecl() {
  return getRuleContext<StateMachineParser::RefPortDeclContext>(0);
}

StateMachineParser::GuardDeclContext* StateMachineParser::SignalTransitionBodyContext::guardDecl() {
  return getRuleContext<StateMachineParser::GuardDeclContext>(0);
}

StateMachineParser::ActionDeclContext* StateMachineParser::SignalTransitionBodyContext::actionDecl() {
  return getRuleContext<StateMachineParser::ActionDeclContext>(0);
}


size_t StateMachineParser::SignalTransitionBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleSignalTransitionBody;
}

void StateMachineParser::SignalTransitionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalTransitionBody(this);
}

void StateMachineParser::SignalTransitionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalTransitionBody(this);
}

StateMachineParser::SignalTransitionBodyContext* StateMachineParser::signalTransitionBody() {
  SignalTransitionBodyContext *_localctx = _tracker.createInstance<SignalTransitionBodyContext>(_ctx, getState());
  enterRule(_localctx, 60, StateMachineParser::RuleSignalTransitionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    nameDecl();
    setState(389);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::RefSignalID: {
        setState(385);
        refSignalDecl();
        setState(386);
        refPortDecl();
        break;
      }

      case StateMachineParser::ActionID:
      case StateMachineParser::GuardID:
      case StateMachineParser::SourceStateID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(393);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::GuardID: {
        setState(391);
        guardDecl();
        break;
      }

      case StateMachineParser::ActionID:
      case StateMachineParser::SourceStateID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(397);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ActionID: {
        setState(395);
        actionDecl();
        break;
      }

      case StateMachineParser::SourceStateID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(399);
    sourceStateDecl();
    setState(400);
    targetStateDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeoutTransitionDeclContext ------------------------------------------------------------------

StateMachineParser::TimeoutTransitionDeclContext::TimeoutTransitionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::TimeoutTransitionDeclContext::TimeoutTransitionID() {
  return getToken(StateMachineParser::TimeoutTransitionID, 0);
}

tree::TerminalNode* StateMachineParser::TimeoutTransitionDeclContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

StateMachineParser::TimeoutTransitionBodyContext* StateMachineParser::TimeoutTransitionDeclContext::timeoutTransitionBody() {
  return getRuleContext<StateMachineParser::TimeoutTransitionBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::TimeoutTransitionDeclContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}


size_t StateMachineParser::TimeoutTransitionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleTimeoutTransitionDecl;
}

void StateMachineParser::TimeoutTransitionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeoutTransitionDecl(this);
}

void StateMachineParser::TimeoutTransitionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeoutTransitionDecl(this);
}

StateMachineParser::TimeoutTransitionDeclContext* StateMachineParser::timeoutTransitionDecl() {
  TimeoutTransitionDeclContext *_localctx = _tracker.createInstance<TimeoutTransitionDeclContext>(_ctx, getState());
  enterRule(_localctx, 62, StateMachineParser::RuleTimeoutTransitionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    match(StateMachineParser::TimeoutTransitionID);
    setState(403);
    match(StateMachineParser::LBRACE);
    setState(404);
    timeoutTransitionBody();
    setState(405);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeoutTransitionBodyContext ------------------------------------------------------------------

StateMachineParser::TimeoutTransitionBodyContext::TimeoutTransitionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::NameDeclContext* StateMachineParser::TimeoutTransitionBodyContext::nameDecl() {
  return getRuleContext<StateMachineParser::NameDeclContext>(0);
}

StateMachineParser::TimeoutDeclContext* StateMachineParser::TimeoutTransitionBodyContext::timeoutDecl() {
  return getRuleContext<StateMachineParser::TimeoutDeclContext>(0);
}

StateMachineParser::SourceStateDeclContext* StateMachineParser::TimeoutTransitionBodyContext::sourceStateDecl() {
  return getRuleContext<StateMachineParser::SourceStateDeclContext>(0);
}

StateMachineParser::TargetStateDeclContext* StateMachineParser::TimeoutTransitionBodyContext::targetStateDecl() {
  return getRuleContext<StateMachineParser::TargetStateDeclContext>(0);
}

StateMachineParser::GuardDeclContext* StateMachineParser::TimeoutTransitionBodyContext::guardDecl() {
  return getRuleContext<StateMachineParser::GuardDeclContext>(0);
}

StateMachineParser::ActionDeclContext* StateMachineParser::TimeoutTransitionBodyContext::actionDecl() {
  return getRuleContext<StateMachineParser::ActionDeclContext>(0);
}


size_t StateMachineParser::TimeoutTransitionBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleTimeoutTransitionBody;
}

void StateMachineParser::TimeoutTransitionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeoutTransitionBody(this);
}

void StateMachineParser::TimeoutTransitionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeoutTransitionBody(this);
}

StateMachineParser::TimeoutTransitionBodyContext* StateMachineParser::timeoutTransitionBody() {
  TimeoutTransitionBodyContext *_localctx = _tracker.createInstance<TimeoutTransitionBodyContext>(_ctx, getState());
  enterRule(_localctx, 64, StateMachineParser::RuleTimeoutTransitionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    nameDecl();
    setState(408);
    timeoutDecl();
    setState(411);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::GuardID: {
        setState(409);
        guardDecl();
        break;
      }

      case StateMachineParser::ActionID:
      case StateMachineParser::SourceStateID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(415);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ActionID: {
        setState(413);
        actionDecl();
        break;
      }

      case StateMachineParser::SourceStateID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(417);
    sourceStateDecl();
    setState(418);
    targetStateDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RefSignalDeclContext ------------------------------------------------------------------

StateMachineParser::RefSignalDeclContext::RefSignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::RefSignalDeclContext::RefSignalID() {
  return getToken(StateMachineParser::RefSignalID, 0);
}

tree::TerminalNode* StateMachineParser::RefSignalDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

tree::TerminalNode* StateMachineParser::RefSignalDeclContext::ID() {
  return getToken(StateMachineParser::ID, 0);
}

tree::TerminalNode* StateMachineParser::RefSignalDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::RefSignalDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleRefSignalDecl;
}

void StateMachineParser::RefSignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRefSignalDecl(this);
}

void StateMachineParser::RefSignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRefSignalDecl(this);
}

StateMachineParser::RefSignalDeclContext* StateMachineParser::refSignalDecl() {
  RefSignalDeclContext *_localctx = _tracker.createInstance<RefSignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, StateMachineParser::RuleRefSignalDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    match(StateMachineParser::RefSignalID);
    setState(421);
    match(StateMachineParser::COLON);
    setState(422);
    match(StateMachineParser::ID);
    setState(423);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RefPortDeclContext ------------------------------------------------------------------

StateMachineParser::RefPortDeclContext::RefPortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::RefPortDeclContext::RefPortID() {
  return getToken(StateMachineParser::RefPortID, 0);
}

tree::TerminalNode* StateMachineParser::RefPortDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

tree::TerminalNode* StateMachineParser::RefPortDeclContext::ID() {
  return getToken(StateMachineParser::ID, 0);
}

tree::TerminalNode* StateMachineParser::RefPortDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::RefPortDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleRefPortDecl;
}

void StateMachineParser::RefPortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRefPortDecl(this);
}

void StateMachineParser::RefPortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRefPortDecl(this);
}

StateMachineParser::RefPortDeclContext* StateMachineParser::refPortDecl() {
  RefPortDeclContext *_localctx = _tracker.createInstance<RefPortDeclContext>(_ctx, getState());
  enterRule(_localctx, 68, StateMachineParser::RuleRefPortDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    match(StateMachineParser::RefPortID);
    setState(426);
    match(StateMachineParser::COLON);
    setState(427);
    match(StateMachineParser::ID);
    setState(428);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntryActionDeclContext ------------------------------------------------------------------

StateMachineParser::EntryActionDeclContext::EntryActionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::EntryActionDeclContext::EntryActionID() {
  return getToken(StateMachineParser::EntryActionID, 0);
}

tree::TerminalNode* StateMachineParser::EntryActionDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::ActionStatementBodyContext* StateMachineParser::EntryActionDeclContext::actionStatementBody() {
  return getRuleContext<StateMachineParser::ActionStatementBodyContext>(0);
}

StateMachineParser::ActionNestedStatementBodyContext* StateMachineParser::EntryActionDeclContext::actionNestedStatementBody() {
  return getRuleContext<StateMachineParser::ActionNestedStatementBodyContext>(0);
}


size_t StateMachineParser::EntryActionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleEntryActionDecl;
}

void StateMachineParser::EntryActionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntryActionDecl(this);
}

void StateMachineParser::EntryActionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntryActionDecl(this);
}

StateMachineParser::EntryActionDeclContext* StateMachineParser::entryActionDecl() {
  EntryActionDeclContext *_localctx = _tracker.createInstance<EntryActionDeclContext>(_ctx, getState());
  enterRule(_localctx, 70, StateMachineParser::RuleEntryActionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(StateMachineParser::EntryActionID);
    setState(431);
    match(StateMachineParser::COLON);
    setState(434);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ThisID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID: {
        setState(432);
        actionStatementBody();
        break;
      }

      case StateMachineParser::LBRACE: {
        setState(433);
        actionNestedStatementBody();
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

//----------------- ExitActionDeclContext ------------------------------------------------------------------

StateMachineParser::ExitActionDeclContext::ExitActionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ExitActionDeclContext::ExitActionID() {
  return getToken(StateMachineParser::ExitActionID, 0);
}

tree::TerminalNode* StateMachineParser::ExitActionDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::ActionStatementBodyContext* StateMachineParser::ExitActionDeclContext::actionStatementBody() {
  return getRuleContext<StateMachineParser::ActionStatementBodyContext>(0);
}

StateMachineParser::ActionNestedStatementBodyContext* StateMachineParser::ExitActionDeclContext::actionNestedStatementBody() {
  return getRuleContext<StateMachineParser::ActionNestedStatementBodyContext>(0);
}


size_t StateMachineParser::ExitActionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleExitActionDecl;
}

void StateMachineParser::ExitActionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExitActionDecl(this);
}

void StateMachineParser::ExitActionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExitActionDecl(this);
}

StateMachineParser::ExitActionDeclContext* StateMachineParser::exitActionDecl() {
  ExitActionDeclContext *_localctx = _tracker.createInstance<ExitActionDeclContext>(_ctx, getState());
  enterRule(_localctx, 72, StateMachineParser::RuleExitActionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    match(StateMachineParser::ExitActionID);
    setState(437);
    match(StateMachineParser::COLON);
    setState(440);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ThisID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID: {
        setState(438);
        actionStatementBody();
        break;
      }

      case StateMachineParser::LBRACE: {
        setState(439);
        actionNestedStatementBody();
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

//----------------- TimeoutDeclContext ------------------------------------------------------------------

StateMachineParser::TimeoutDeclContext::TimeoutDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::TimeoutDeclContext::ValueID() {
  return getToken(StateMachineParser::ValueID, 0);
}

tree::TerminalNode* StateMachineParser::TimeoutDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

tree::TerminalNode* StateMachineParser::TimeoutDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

tree::TerminalNode* StateMachineParser::TimeoutDeclContext::REAL() {
  return getToken(StateMachineParser::REAL, 0);
}

tree::TerminalNode* StateMachineParser::TimeoutDeclContext::INT() {
  return getToken(StateMachineParser::INT, 0);
}


size_t StateMachineParser::TimeoutDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleTimeoutDecl;
}

void StateMachineParser::TimeoutDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeoutDecl(this);
}

void StateMachineParser::TimeoutDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeoutDecl(this);
}

StateMachineParser::TimeoutDeclContext* StateMachineParser::timeoutDecl() {
  TimeoutDeclContext *_localctx = _tracker.createInstance<TimeoutDeclContext>(_ctx, getState());
  enterRule(_localctx, 74, StateMachineParser::RuleTimeoutDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(442);
    match(StateMachineParser::ValueID);
    setState(443);
    match(StateMachineParser::COLON);
    setState(444);
    dynamic_cast<TimeoutDeclContext *>(_localctx)->val = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == StateMachineParser::INT

    || _la == StateMachineParser::REAL)) {
      dynamic_cast<TimeoutDeclContext *>(_localctx)->val = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(445);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceStateDeclContext ------------------------------------------------------------------

StateMachineParser::SourceStateDeclContext::SourceStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::SourceStateDeclContext::SourceStateID() {
  return getToken(StateMachineParser::SourceStateID, 0);
}

tree::TerminalNode* StateMachineParser::SourceStateDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::StateIdPathContext* StateMachineParser::SourceStateDeclContext::stateIdPath() {
  return getRuleContext<StateMachineParser::StateIdPathContext>(0);
}

tree::TerminalNode* StateMachineParser::SourceStateDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::SourceStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleSourceStateDecl;
}

void StateMachineParser::SourceStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourceStateDecl(this);
}

void StateMachineParser::SourceStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourceStateDecl(this);
}

StateMachineParser::SourceStateDeclContext* StateMachineParser::sourceStateDecl() {
  SourceStateDeclContext *_localctx = _tracker.createInstance<SourceStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 76, StateMachineParser::RuleSourceStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(447);
    match(StateMachineParser::SourceStateID);
    setState(448);
    match(StateMachineParser::COLON);
    setState(449);
    stateIdPath();
    setState(450);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetStateDeclContext ------------------------------------------------------------------

StateMachineParser::TargetStateDeclContext::TargetStateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::TargetStateDeclContext::TargetStateID() {
  return getToken(StateMachineParser::TargetStateID, 0);
}

tree::TerminalNode* StateMachineParser::TargetStateDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::StateIdPathContext* StateMachineParser::TargetStateDeclContext::stateIdPath() {
  return getRuleContext<StateMachineParser::StateIdPathContext>(0);
}

tree::TerminalNode* StateMachineParser::TargetStateDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::TargetStateDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleTargetStateDecl;
}

void StateMachineParser::TargetStateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTargetStateDecl(this);
}

void StateMachineParser::TargetStateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTargetStateDecl(this);
}

StateMachineParser::TargetStateDeclContext* StateMachineParser::targetStateDecl() {
  TargetStateDeclContext *_localctx = _tracker.createInstance<TargetStateDeclContext>(_ctx, getState());
  enterRule(_localctx, 78, StateMachineParser::RuleTargetStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    match(StateMachineParser::TargetStateID);
    setState(453);
    match(StateMachineParser::COLON);
    setState(454);
    stateIdPath();
    setState(455);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextIDContext ------------------------------------------------------------------

StateMachineParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ContextIDContext::ID() {
  return getToken(StateMachineParser::ID, 0);
}

tree::TerminalNode* StateMachineParser::ContextIDContext::NameID() {
  return getToken(StateMachineParser::NameID, 0);
}

tree::TerminalNode* StateMachineParser::ContextIDContext::LabelID() {
  return getToken(StateMachineParser::LabelID, 0);
}

tree::TerminalNode* StateMachineParser::ContextIDContext::GuardID() {
  return getToken(StateMachineParser::GuardID, 0);
}

tree::TerminalNode* StateMachineParser::ContextIDContext::RegionID() {
  return getToken(StateMachineParser::RegionID, 0);
}

tree::TerminalNode* StateMachineParser::ContextIDContext::ValueID() {
  return getToken(StateMachineParser::ValueID, 0);
}

tree::TerminalNode* StateMachineParser::ContextIDContext::SourceStateID() {
  return getToken(StateMachineParser::SourceStateID, 0);
}

tree::TerminalNode* StateMachineParser::ContextIDContext::TargetStateID() {
  return getToken(StateMachineParser::TargetStateID, 0);
}


size_t StateMachineParser::ContextIDContext::getRuleIndex() const {
  return StateMachineParser::RuleContextID;
}

void StateMachineParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void StateMachineParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

StateMachineParser::ContextIDContext* StateMachineParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 80, StateMachineParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    _la = _input->LA(1);
    if (!(((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & ((1ULL << (StateMachineParser::ValueID - 12))
      | (1ULL << (StateMachineParser::GuardID - 12))
      | (1ULL << (StateMachineParser::RegionID - 12))
      | (1ULL << (StateMachineParser::SourceStateID - 12))
      | (1ULL << (StateMachineParser::TargetStateID - 12))
      | (1ULL << (StateMachineParser::NameID - 12))
      | (1ULL << (StateMachineParser::LabelID - 12))
      | (1ULL << (StateMachineParser::ID - 12)))) != 0))) {
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

StateMachineParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> StateMachineParser::ComponentIdPathContext::DOT() {
  return getTokens(StateMachineParser::DOT);
}

tree::TerminalNode* StateMachineParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(StateMachineParser::DOT, i);
}


size_t StateMachineParser::ComponentIdPathContext::getRuleIndex() const {
  return StateMachineParser::RuleComponentIdPath;
}

void StateMachineParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void StateMachineParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

StateMachineParser::ComponentIdPathContext* StateMachineParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 82, StateMachineParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(459);
    contextID();
    setState(464);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::DOT) {
      setState(460);
      match(StateMachineParser::DOT);
      setState(461);
      contextID();
      setState(466);
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

StateMachineParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::SignalIdPathContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> StateMachineParser::SignalIdPathContext::DOT() {
  return getTokens(StateMachineParser::DOT);
}

tree::TerminalNode* StateMachineParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(StateMachineParser::DOT, i);
}


size_t StateMachineParser::SignalIdPathContext::getRuleIndex() const {
  return StateMachineParser::RuleSignalIdPath;
}

void StateMachineParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void StateMachineParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

StateMachineParser::SignalIdPathContext* StateMachineParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 84, StateMachineParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    contextID();
    setState(472);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::DOT) {
      setState(468);
      match(StateMachineParser::DOT);
      setState(469);
      contextID();
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

//----------------- AttributeIdPathContext ------------------------------------------------------------------

StateMachineParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::AttributeNameContext* StateMachineParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<StateMachineParser::AttributeNameContext>(0);
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> StateMachineParser::AttributeIdPathContext::DOT() {
  return getTokens(StateMachineParser::DOT);
}

tree::TerminalNode* StateMachineParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(StateMachineParser::DOT, i);
}


size_t StateMachineParser::AttributeIdPathContext::getRuleIndex() const {
  return StateMachineParser::RuleAttributeIdPath;
}

void StateMachineParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void StateMachineParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

StateMachineParser::AttributeIdPathContext* StateMachineParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 86, StateMachineParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(484);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(475);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(476);
      contextID();
      setState(481);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == StateMachineParser::DOT) {
        setState(477);
        match(StateMachineParser::DOT);
        setState(478);
        contextID();
        setState(483);
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

StateMachineParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::SignalIdPathContext* StateMachineParser::SignalSendContext::signalIdPath() {
  return getRuleContext<StateMachineParser::SignalIdPathContext>(0);
}

tree::TerminalNode* StateMachineParser::SignalSendContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

StateMachineParser::FunctionCallBodyContext* StateMachineParser::SignalSendContext::functionCallBody() {
  return getRuleContext<StateMachineParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::SignalSendContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}


size_t StateMachineParser::SignalSendContext::getRuleIndex() const {
  return StateMachineParser::RuleSignalSend;
}

void StateMachineParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void StateMachineParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

StateMachineParser::SignalSendContext* StateMachineParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 88, StateMachineParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    signalIdPath();
    setState(487);
    match(StateMachineParser::LPAREN);
    setState(488);
    functionCallBody();
    setState(489);
    match(StateMachineParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

StateMachineParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StateMachineParser::TypeDefDeclContext *> StateMachineParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<StateMachineParser::TypeDefDeclContext>();
}

StateMachineParser::TypeDefDeclContext* StateMachineParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<StateMachineParser::TypeDefDeclContext>(i);
}

std::vector<StateMachineParser::AttributeDeclContext *> StateMachineParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<StateMachineParser::AttributeDeclContext>();
}

StateMachineParser::AttributeDeclContext* StateMachineParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<StateMachineParser::AttributeDeclContext>(i);
}

std::vector<StateMachineParser::SignalDeclContext *> StateMachineParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<StateMachineParser::SignalDeclContext>();
}

StateMachineParser::SignalDeclContext* StateMachineParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<StateMachineParser::SignalDeclContext>(i);
}


size_t StateMachineParser::CommonDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleCommonDecl;
}

void StateMachineParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void StateMachineParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

StateMachineParser::CommonDeclContext* StateMachineParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 90, StateMachineParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << StateMachineParser::TypeID)
      | (1ULL << StateMachineParser::AttributeID)
      | (1ULL << StateMachineParser::SignalID))) != 0)) {
      setState(494);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case StateMachineParser::TypeID: {
          setState(491);
          typeDefDecl();
          break;
        }

        case StateMachineParser::AttributeID: {
          setState(492);
          attributeDecl();
          break;
        }

        case StateMachineParser::SignalID: {
          setState(493);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(498);
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

StateMachineParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::ImportPathBodyContext* StateMachineParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<StateMachineParser::ImportPathBodyContext>(0);
}

StateMachineParser::ImportPathDeclContext* StateMachineParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<StateMachineParser::ImportPathDeclContext>(0);
}


size_t StateMachineParser::ImportPathDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleImportPathDecl;
}

void StateMachineParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void StateMachineParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

StateMachineParser::ImportPathDeclContext* StateMachineParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 92, StateMachineParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(503);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(499);
      importPathBody();
      setState(500);
      importPathDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

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

//----------------- ImportPathBodyContext ------------------------------------------------------------------

StateMachineParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ImportPathBodyContext::ImportID() {
  return getToken(StateMachineParser::ImportID, 0);
}

tree::TerminalNode* StateMachineParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(StateMachineParser::LESSTHAN, 0);
}

StateMachineParser::ImportFileBodyContext* StateMachineParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<StateMachineParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(StateMachineParser::GREATERTHAN, 0);
}

StateMachineParser::ImportAsContext* StateMachineParser::ImportPathBodyContext::importAs() {
  return getRuleContext<StateMachineParser::ImportAsContext>(0);
}


size_t StateMachineParser::ImportPathBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleImportPathBody;
}

void StateMachineParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void StateMachineParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

StateMachineParser::ImportPathBodyContext* StateMachineParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 94, StateMachineParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
    match(StateMachineParser::ImportID);
    setState(506);
    match(StateMachineParser::LESSTHAN);
    setState(507);
    importFileBody();
    setState(508);
    match(StateMachineParser::GREATERTHAN);
    setState(509);
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

StateMachineParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

tree::TerminalNode* StateMachineParser::ImportFileBodyContext::DOT() {
  return getToken(StateMachineParser::DOT, 0);
}

tree::TerminalNode* StateMachineParser::ImportFileBodyContext::RANGE() {
  return getToken(StateMachineParser::RANGE, 0);
}

tree::TerminalNode* StateMachineParser::ImportFileBodyContext::DIV() {
  return getToken(StateMachineParser::DIV, 0);
}

StateMachineParser::ImportFileBodyContext* StateMachineParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<StateMachineParser::ImportFileBodyContext>(0);
}


size_t StateMachineParser::ImportFileBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleImportFileBody;
}

void StateMachineParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void StateMachineParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

StateMachineParser::ImportFileBodyContext* StateMachineParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 96, StateMachineParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(522);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(511);
      contextID();
      setState(512);
      match(StateMachineParser::DOT);
      setState(513);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(515);
      match(StateMachineParser::RANGE);
      setState(516);
      match(StateMachineParser::DIV);
      setState(517);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(518);
      contextID();
      setState(519);
      match(StateMachineParser::DIV);
      setState(520);
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

StateMachineParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ImportAsContext::AsID() {
  return getToken(StateMachineParser::AsID, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::ImportAsContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}


size_t StateMachineParser::ImportAsContext::getRuleIndex() const {
  return StateMachineParser::RuleImportAs;
}

void StateMachineParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void StateMachineParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

StateMachineParser::ImportAsContext* StateMachineParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 98, StateMachineParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(527);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(524);
        match(StateMachineParser::AsID);
        setState(525);
        contextID();
        break;
      }

      case StateMachineParser::ImportID: {
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

StateMachineParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::TypeDefDeclContext::TypeID() {
  return getToken(StateMachineParser::TypeID, 0);
}

StateMachineParser::TypeDeclContext* StateMachineParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<StateMachineParser::TypeDeclContext>(0);
}

StateMachineParser::ContextIDContext* StateMachineParser::TypeDefDeclContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

tree::TerminalNode* StateMachineParser::TypeDefDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::TypeDefDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleTypeDefDecl;
}

void StateMachineParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void StateMachineParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

StateMachineParser::TypeDefDeclContext* StateMachineParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 100, StateMachineParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    match(StateMachineParser::TypeID);
    setState(530);
    typeDecl();
    setState(531);
    contextID();
    setState(532);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

StateMachineParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::IntTypeDeclContext* StateMachineParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<StateMachineParser::IntTypeDeclContext>(0);
}

StateMachineParser::RealTypeDeclContext* StateMachineParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<StateMachineParser::RealTypeDeclContext>(0);
}

StateMachineParser::EnumTypeDeclContext* StateMachineParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<StateMachineParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* StateMachineParser::TypeDeclContext::BoolID() {
  return getToken(StateMachineParser::BoolID, 0);
}

tree::TerminalNode* StateMachineParser::TypeDeclContext::StringID() {
  return getToken(StateMachineParser::StringID, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::TypeDeclContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}


size_t StateMachineParser::TypeDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleTypeDecl;
}

void StateMachineParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void StateMachineParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

StateMachineParser::TypeDeclContext* StateMachineParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 102, StateMachineParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(540);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(534);
        intTypeDecl();
        break;
      }

      case StateMachineParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(535);
        realTypeDecl();
        break;
      }

      case StateMachineParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(536);
        enumTypeDecl();
        break;
      }

      case StateMachineParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(537);
        match(StateMachineParser::BoolID);
        break;
      }

      case StateMachineParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(538);
        match(StateMachineParser::StringID);
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(539);
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

StateMachineParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::IntTypeDeclContext::IntID() {
  return getToken(StateMachineParser::IntID, 0);
}

tree::TerminalNode* StateMachineParser::IntTypeDeclContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> StateMachineParser::IntTypeDeclContext::INT() {
  return getTokens(StateMachineParser::INT);
}

tree::TerminalNode* StateMachineParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(StateMachineParser::INT, i);
}

tree::TerminalNode* StateMachineParser::IntTypeDeclContext::RANGE() {
  return getToken(StateMachineParser::RANGE, 0);
}

tree::TerminalNode* StateMachineParser::IntTypeDeclContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}


size_t StateMachineParser::IntTypeDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleIntTypeDecl;
}

void StateMachineParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void StateMachineParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

StateMachineParser::IntTypeDeclContext* StateMachineParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 104, StateMachineParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    match(StateMachineParser::IntID);
    setState(549);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::LPAREN: {
        setState(543);
        match(StateMachineParser::LPAREN);
        setState(544);
        match(StateMachineParser::INT);
        setState(545);
        match(StateMachineParser::RANGE);
        setState(546);
        match(StateMachineParser::INT);
        setState(547);
        match(StateMachineParser::RPAREN);
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ID: {
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

StateMachineParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::RealTypeDeclContext::RealID() {
  return getToken(StateMachineParser::RealID, 0);
}

tree::TerminalNode* StateMachineParser::RealTypeDeclContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> StateMachineParser::RealTypeDeclContext::REAL() {
  return getTokens(StateMachineParser::REAL);
}

tree::TerminalNode* StateMachineParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(StateMachineParser::REAL, i);
}

tree::TerminalNode* StateMachineParser::RealTypeDeclContext::RANGE() {
  return getToken(StateMachineParser::RANGE, 0);
}

tree::TerminalNode* StateMachineParser::RealTypeDeclContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}


size_t StateMachineParser::RealTypeDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleRealTypeDecl;
}

void StateMachineParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void StateMachineParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

StateMachineParser::RealTypeDeclContext* StateMachineParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 106, StateMachineParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(551);
    match(StateMachineParser::RealID);
    setState(558);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::LPAREN: {
        setState(552);
        match(StateMachineParser::LPAREN);
        setState(553);
        match(StateMachineParser::REAL);
        setState(554);
        match(StateMachineParser::RANGE);
        setState(555);
        match(StateMachineParser::REAL);
        setState(556);
        match(StateMachineParser::RPAREN);
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ID: {
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

StateMachineParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::EnumTypeDeclContext::EnumID() {
  return getToken(StateMachineParser::EnumID, 0);
}

tree::TerminalNode* StateMachineParser::EnumTypeDeclContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

tree::TerminalNode* StateMachineParser::EnumTypeDeclContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> StateMachineParser::EnumTypeDeclContext::COMMA() {
  return getTokens(StateMachineParser::COMMA);
}

tree::TerminalNode* StateMachineParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(StateMachineParser::COMMA, i);
}


size_t StateMachineParser::EnumTypeDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleEnumTypeDecl;
}

void StateMachineParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void StateMachineParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

StateMachineParser::EnumTypeDeclContext* StateMachineParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 108, StateMachineParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(560);
    match(StateMachineParser::EnumID);
    setState(561);
    match(StateMachineParser::LPAREN);
    setState(562);
    contextID();
    setState(567);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::COMMA) {
      setState(563);
      match(StateMachineParser::COMMA);
      setState(564);
      contextID();
      setState(569);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(570);
    match(StateMachineParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

StateMachineParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::AttributeDeclContext::AttributeID() {
  return getToken(StateMachineParser::AttributeID, 0);
}

StateMachineParser::TypeDeclContext* StateMachineParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<StateMachineParser::TypeDeclContext>(0);
}

StateMachineParser::ContextIDContext* StateMachineParser::AttributeDeclContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

tree::TerminalNode* StateMachineParser::AttributeDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

tree::TerminalNode* StateMachineParser::AttributeDeclContext::ASSIGN() {
  return getToken(StateMachineParser::ASSIGN, 0);
}

StateMachineParser::LiteralValueContext* StateMachineParser::AttributeDeclContext::literalValue() {
  return getRuleContext<StateMachineParser::LiteralValueContext>(0);
}


size_t StateMachineParser::AttributeDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleAttributeDecl;
}

void StateMachineParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void StateMachineParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

StateMachineParser::AttributeDeclContext* StateMachineParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 110, StateMachineParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(572);
    match(StateMachineParser::AttributeID);
    setState(573);
    typeDecl();
    setState(574);
    contextID();
    setState(577);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StateMachineParser::ASSIGN) {
      setState(575);
      match(StateMachineParser::ASSIGN);
      setState(576);
      literalValue();
    }
    setState(579);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

StateMachineParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::LiteralValueContext::INT() {
  return getToken(StateMachineParser::INT, 0);
}

tree::TerminalNode* StateMachineParser::LiteralValueContext::REAL() {
  return getToken(StateMachineParser::REAL, 0);
}

tree::TerminalNode* StateMachineParser::LiteralValueContext::STRING() {
  return getToken(StateMachineParser::STRING, 0);
}

tree::TerminalNode* StateMachineParser::LiteralValueContext::TrueID() {
  return getToken(StateMachineParser::TrueID, 0);
}

tree::TerminalNode* StateMachineParser::LiteralValueContext::FalseID() {
  return getToken(StateMachineParser::FalseID, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::LiteralValueContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}


size_t StateMachineParser::LiteralValueContext::getRuleIndex() const {
  return StateMachineParser::RuleLiteralValue;
}

void StateMachineParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void StateMachineParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

StateMachineParser::LiteralValueContext* StateMachineParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 112, StateMachineParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(587);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(581);
        match(StateMachineParser::INT);
        break;
      }

      case StateMachineParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(582);
        match(StateMachineParser::REAL);
        break;
      }

      case StateMachineParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(583);
        match(StateMachineParser::STRING);
        break;
      }

      case StateMachineParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(584);
        match(StateMachineParser::TrueID);
        break;
      }

      case StateMachineParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(585);
        match(StateMachineParser::FalseID);
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(586);
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

StateMachineParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::TriggerDeclContext* StateMachineParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<StateMachineParser::TriggerDeclContext>(0);
}

StateMachineParser::ContextIDContext* StateMachineParser::SignalParamNameContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}


size_t StateMachineParser::SignalParamNameContext::getRuleIndex() const {
  return StateMachineParser::RuleSignalParamName;
}

void StateMachineParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void StateMachineParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

StateMachineParser::SignalParamNameContext* StateMachineParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 114, StateMachineParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    triggerDecl();
    setState(590);
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

StateMachineParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::ContextIDContext* StateMachineParser::AttributeNameContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

StateMachineParser::ThisDeclContext* StateMachineParser::AttributeNameContext::thisDecl() {
  return getRuleContext<StateMachineParser::ThisDeclContext>(0);
}


size_t StateMachineParser::AttributeNameContext::getRuleIndex() const {
  return StateMachineParser::RuleAttributeName;
}

void StateMachineParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void StateMachineParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

StateMachineParser::AttributeNameContext* StateMachineParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 116, StateMachineParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(594);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ThisID: {
        setState(592);
        thisDecl();
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(596);
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

StateMachineParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ToPortNameContext::ToID() {
  return getToken(StateMachineParser::ToID, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::ToPortNameContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}


size_t StateMachineParser::ToPortNameContext::getRuleIndex() const {
  return StateMachineParser::RuleToPortName;
}

void StateMachineParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void StateMachineParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

StateMachineParser::ToPortNameContext* StateMachineParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 118, StateMachineParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(598);
    match(StateMachineParser::ToID);
    setState(599);
    contextID();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

StateMachineParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::TypeDeclContext* StateMachineParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<StateMachineParser::TypeDeclContext>(0);
}

StateMachineParser::ContextIDContext* StateMachineParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

tree::TerminalNode* StateMachineParser::LocalAssignStatementContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

tree::TerminalNode* StateMachineParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(StateMachineParser::ASSIGN, 0);
}

StateMachineParser::ExpressionContext* StateMachineParser::LocalAssignStatementContext::expression() {
  return getRuleContext<StateMachineParser::ExpressionContext>(0);
}


size_t StateMachineParser::LocalAssignStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleLocalAssignStatement;
}

void StateMachineParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void StateMachineParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

StateMachineParser::LocalAssignStatementContext* StateMachineParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 120, StateMachineParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    typeDecl();
    setState(602);
    contextID();
    setState(606);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ASSIGN: {
        setState(603);
        match(StateMachineParser::ASSIGN);
        setState(604);
        expression();
        break;
      }

      case StateMachineParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(608);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

StateMachineParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::SendToStatementContext::SendID() {
  return getToken(StateMachineParser::SendID, 0);
}

StateMachineParser::SignalSendContext* StateMachineParser::SendToStatementContext::signalSend() {
  return getRuleContext<StateMachineParser::SignalSendContext>(0);
}

tree::TerminalNode* StateMachineParser::SendToStatementContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

StateMachineParser::ToPortNameContext* StateMachineParser::SendToStatementContext::toPortName() {
  return getRuleContext<StateMachineParser::ToPortNameContext>(0);
}


size_t StateMachineParser::SendToStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleSendToStatement;
}

void StateMachineParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void StateMachineParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

StateMachineParser::SendToStatementContext* StateMachineParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 122, StateMachineParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    match(StateMachineParser::SendID);
    setState(611);
    signalSend();
    setState(614);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ToID: {
        setState(612);
        toPortName();
        break;
      }

      case StateMachineParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(616);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

StateMachineParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::AttributeAssignStatementContext* StateMachineParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<StateMachineParser::AttributeAssignStatementContext>(0);
}

StateMachineParser::SendToStatementContext* StateMachineParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<StateMachineParser::SendToStatementContext>(0);
}


size_t StateMachineParser::SingleAssignmentContext::getRuleIndex() const {
  return StateMachineParser::RuleSingleAssignment;
}

void StateMachineParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void StateMachineParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

StateMachineParser::SingleAssignmentContext* StateMachineParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 124, StateMachineParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(620);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::ThisID:
      case StateMachineParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(618);
        attributeAssignStatement();
        break;
      }

      case StateMachineParser::SendID: {
        enterOuterAlt(_localctx, 2);
        setState(619);
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

StateMachineParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::MultiAssignmentContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

tree::TerminalNode* StateMachineParser::MultiAssignmentContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}

std::vector<StateMachineParser::SingleAssignmentContext *> StateMachineParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<StateMachineParser::SingleAssignmentContext>();
}

StateMachineParser::SingleAssignmentContext* StateMachineParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<StateMachineParser::SingleAssignmentContext>(i);
}


size_t StateMachineParser::MultiAssignmentContext::getRuleIndex() const {
  return StateMachineParser::RuleMultiAssignment;
}

void StateMachineParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void StateMachineParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

StateMachineParser::MultiAssignmentContext* StateMachineParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 126, StateMachineParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(622);
    match(StateMachineParser::LBRACE);
    setState(626);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & ((1ULL << (StateMachineParser::ValueID - 12))
      | (1ULL << (StateMachineParser::GuardID - 12))
      | (1ULL << (StateMachineParser::RegionID - 12))
      | (1ULL << (StateMachineParser::SourceStateID - 12))
      | (1ULL << (StateMachineParser::TargetStateID - 12))
      | (1ULL << (StateMachineParser::NameID - 12))
      | (1ULL << (StateMachineParser::LabelID - 12))
      | (1ULL << (StateMachineParser::ThisID - 12))
      | (1ULL << (StateMachineParser::SendID - 12))
      | (1ULL << (StateMachineParser::ID - 12)))) != 0)) {
      setState(623);
      singleAssignment();
      setState(628);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(629);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

StateMachineParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::SignalDeclContext::SignalID() {
  return getToken(StateMachineParser::SignalID, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::SignalDeclContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

tree::TerminalNode* StateMachineParser::SignalDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

tree::TerminalNode* StateMachineParser::SignalDeclContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

tree::TerminalNode* StateMachineParser::SignalDeclContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}

std::vector<StateMachineParser::ParamDeclContext *> StateMachineParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<StateMachineParser::ParamDeclContext>();
}

StateMachineParser::ParamDeclContext* StateMachineParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<StateMachineParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> StateMachineParser::SignalDeclContext::COMMA() {
  return getTokens(StateMachineParser::COMMA);
}

tree::TerminalNode* StateMachineParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(StateMachineParser::COMMA, i);
}


size_t StateMachineParser::SignalDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleSignalDecl;
}

void StateMachineParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void StateMachineParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

StateMachineParser::SignalDeclContext* StateMachineParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 128, StateMachineParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    match(StateMachineParser::SignalID);
    setState(632);
    contextID();
    setState(647);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::LPAREN: {
        setState(633);
        match(StateMachineParser::LPAREN);
        setState(643);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case StateMachineParser::ValueID:
          case StateMachineParser::GuardID:
          case StateMachineParser::RegionID:
          case StateMachineParser::SourceStateID:
          case StateMachineParser::TargetStateID:
          case StateMachineParser::NameID:
          case StateMachineParser::LabelID:
          case StateMachineParser::IntID:
          case StateMachineParser::RealID:
          case StateMachineParser::BoolID:
          case StateMachineParser::StringID:
          case StateMachineParser::EnumID:
          case StateMachineParser::ID: {
            setState(634);
            paramDecl();
            setState(639);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == StateMachineParser::COMMA) {
              setState(635);
              match(StateMachineParser::COMMA);
              setState(636);
              paramDecl();
              setState(641);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case StateMachineParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(645);
        match(StateMachineParser::RPAREN);
        break;
      }

      case StateMachineParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(649);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

StateMachineParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::TypeDeclContext* StateMachineParser::ParamDeclContext::typeDecl() {
  return getRuleContext<StateMachineParser::TypeDeclContext>(0);
}

StateMachineParser::ContextIDContext* StateMachineParser::ParamDeclContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}


size_t StateMachineParser::ParamDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleParamDecl;
}

void StateMachineParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void StateMachineParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

StateMachineParser::ParamDeclContext* StateMachineParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 130, StateMachineParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(651);
    typeDecl();
    setState(652);
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

StateMachineParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::FunctionDeclContext::FunctionID() {
  return getToken(StateMachineParser::FunctionID, 0);
}

StateMachineParser::TypeDeclContext* StateMachineParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<StateMachineParser::TypeDeclContext>(0);
}

StateMachineParser::IdPathContext* StateMachineParser::FunctionDeclContext::idPath() {
  return getRuleContext<StateMachineParser::IdPathContext>(0);
}

tree::TerminalNode* StateMachineParser::FunctionDeclContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

tree::TerminalNode* StateMachineParser::FunctionDeclContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}

StateMachineParser::NestedStatementBodyContext* StateMachineParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<StateMachineParser::NestedStatementBodyContext>(0);
}

StateMachineParser::FunctionParametersContext* StateMachineParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<StateMachineParser::FunctionParametersContext>(0);
}


size_t StateMachineParser::FunctionDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleFunctionDecl;
}

void StateMachineParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void StateMachineParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

StateMachineParser::FunctionDeclContext* StateMachineParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 132, StateMachineParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(654);
    match(StateMachineParser::FunctionID);
    setState(655);
    typeDecl();
    setState(656);
    idPath();
    setState(657);
    match(StateMachineParser::LPAREN);
    setState(660);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::IntID:
      case StateMachineParser::RealID:
      case StateMachineParser::BoolID:
      case StateMachineParser::StringID:
      case StateMachineParser::EnumID:
      case StateMachineParser::ID: {
        setState(658);
        functionParameters();
        break;
      }

      case StateMachineParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(662);
    match(StateMachineParser::RPAREN);
    setState(663);
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

StateMachineParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StateMachineParser::ParamDeclContext *> StateMachineParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<StateMachineParser::ParamDeclContext>();
}

StateMachineParser::ParamDeclContext* StateMachineParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<StateMachineParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> StateMachineParser::FunctionParametersContext::COMMA() {
  return getTokens(StateMachineParser::COMMA);
}

tree::TerminalNode* StateMachineParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(StateMachineParser::COMMA, i);
}


size_t StateMachineParser::FunctionParametersContext::getRuleIndex() const {
  return StateMachineParser::RuleFunctionParameters;
}

void StateMachineParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void StateMachineParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

StateMachineParser::FunctionParametersContext* StateMachineParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 134, StateMachineParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(665);
    paramDecl();
    setState(670);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::COMMA) {
      setState(666);
      match(StateMachineParser::COMMA);
      setState(667);
      paramDecl();
      setState(672);
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

StateMachineParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::IdPathContext* StateMachineParser::FunctionCallContext::idPath() {
  return getRuleContext<StateMachineParser::IdPathContext>(0);
}

tree::TerminalNode* StateMachineParser::FunctionCallContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

StateMachineParser::FunctionCallBodyContext* StateMachineParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<StateMachineParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* StateMachineParser::FunctionCallContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}


size_t StateMachineParser::FunctionCallContext::getRuleIndex() const {
  return StateMachineParser::RuleFunctionCall;
}

void StateMachineParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void StateMachineParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

StateMachineParser::FunctionCallContext* StateMachineParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 136, StateMachineParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(673);
    idPath();
    setState(674);
    match(StateMachineParser::LPAREN);
    setState(675);
    functionCallBody();
    setState(676);
    match(StateMachineParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

StateMachineParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::FunctionCallBodyOptionalContext* StateMachineParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<StateMachineParser::FunctionCallBodyOptionalContext>(0);
}

StateMachineParser::LiteralValueContext* StateMachineParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<StateMachineParser::LiteralValueContext>(0);
}

StateMachineParser::SignalParamNameContext* StateMachineParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<StateMachineParser::SignalParamNameContext>(0);
}

StateMachineParser::AttributeNameContext* StateMachineParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<StateMachineParser::AttributeNameContext>(0);
}

StateMachineParser::FunctionCallContext* StateMachineParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<StateMachineParser::FunctionCallContext>(0);
}


size_t StateMachineParser::FunctionCallBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleFunctionCallBody;
}

void StateMachineParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void StateMachineParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

StateMachineParser::FunctionCallBodyContext* StateMachineParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 138, StateMachineParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(683);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(678);
      literalValue();
      break;
    }

    case 2: {
      setState(679);
      signalParamName();
      break;
    }

    case 3: {
      setState(680);
      attributeName();
      break;
    }

    case 4: {
      setState(681);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(685);
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

StateMachineParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(StateMachineParser::COMMA, 0);
}

StateMachineParser::FunctionCallBodyContext* StateMachineParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<StateMachineParser::FunctionCallBodyContext>(0);
}


size_t StateMachineParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return StateMachineParser::RuleFunctionCallBodyOptional;
}

void StateMachineParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void StateMachineParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

StateMachineParser::FunctionCallBodyOptionalContext* StateMachineParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 140, StateMachineParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(690);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(687);
        match(StateMachineParser::COMMA);
        setState(688);
        functionCallBody();
        break;
      }

      case StateMachineParser::RPAREN: {
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

StateMachineParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::TriggerDeclContext::DOT() {
  return getToken(StateMachineParser::DOT, 0);
}

tree::TerminalNode* StateMachineParser::TriggerDeclContext::MessageTrigger() {
  return getToken(StateMachineParser::MessageTrigger, 0);
}

tree::TerminalNode* StateMachineParser::TriggerDeclContext::TriggerID() {
  return getToken(StateMachineParser::TriggerID, 0);
}


size_t StateMachineParser::TriggerDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleTriggerDecl;
}

void StateMachineParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void StateMachineParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

StateMachineParser::TriggerDeclContext* StateMachineParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 142, StateMachineParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(692);
    _la = _input->LA(1);
    if (!(_la == StateMachineParser::TriggerID

    || _la == StateMachineParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(693);
    match(StateMachineParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

StateMachineParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ThisDeclContext::ThisID() {
  return getToken(StateMachineParser::ThisID, 0);
}

tree::TerminalNode* StateMachineParser::ThisDeclContext::DOT() {
  return getToken(StateMachineParser::DOT, 0);
}


size_t StateMachineParser::ThisDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleThisDecl;
}

void StateMachineParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void StateMachineParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

StateMachineParser::ThisDeclContext* StateMachineParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 144, StateMachineParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(695);
    match(StateMachineParser::ThisID);
    setState(696);
    match(StateMachineParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

StateMachineParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::PortDeclContext::PortID() {
  return getToken(StateMachineParser::PortID, 0);
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::PortDeclContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

tree::TerminalNode* StateMachineParser::PortDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> StateMachineParser::PortDeclContext::COMMA() {
  return getTokens(StateMachineParser::COMMA);
}

tree::TerminalNode* StateMachineParser::PortDeclContext::COMMA(size_t i) {
  return getToken(StateMachineParser::COMMA, i);
}


size_t StateMachineParser::PortDeclContext::getRuleIndex() const {
  return StateMachineParser::RulePortDecl;
}

void StateMachineParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void StateMachineParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

StateMachineParser::PortDeclContext* StateMachineParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 146, StateMachineParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(698);
    match(StateMachineParser::PortID);
    setState(699);
    contextID();
    setState(704);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::COMMA) {
      setState(700);
      match(StateMachineParser::COMMA);
      setState(701);
      contextID();
      setState(706);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(707);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

StateMachineParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::NameDeclContext::NameID() {
  return getToken(StateMachineParser::NameID, 0);
}

tree::TerminalNode* StateMachineParser::NameDeclContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::NameDeclContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

tree::TerminalNode* StateMachineParser::NameDeclContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::NameDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleNameDecl;
}

void StateMachineParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void StateMachineParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

StateMachineParser::NameDeclContext* StateMachineParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 148, StateMachineParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(709);
    match(StateMachineParser::NameID);
    setState(710);
    match(StateMachineParser::COLON);
    setState(711);
    contextID();
    setState(712);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

StateMachineParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StateMachineParser::ContextIDContext *> StateMachineParser::IdPathContext::contextID() {
  return getRuleContexts<StateMachineParser::ContextIDContext>();
}

StateMachineParser::ContextIDContext* StateMachineParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<StateMachineParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> StateMachineParser::IdPathContext::DOT() {
  return getTokens(StateMachineParser::DOT);
}

tree::TerminalNode* StateMachineParser::IdPathContext::DOT(size_t i) {
  return getToken(StateMachineParser::DOT, i);
}


size_t StateMachineParser::IdPathContext::getRuleIndex() const {
  return StateMachineParser::RuleIdPath;
}

void StateMachineParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void StateMachineParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

StateMachineParser::IdPathContext* StateMachineParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 150, StateMachineParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(714);
    contextID();
    setState(719);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::DOT) {
      setState(715);
      match(StateMachineParser::DOT);
      setState(716);
      contextID();
      setState(721);
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

StateMachineParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::StatementBodyContext* StateMachineParser::StatementDeclContext::statementBody() {
  return getRuleContext<StateMachineParser::StatementBodyContext>(0);
}

StateMachineParser::NestedStatementBodyContext* StateMachineParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<StateMachineParser::NestedStatementBodyContext>(0);
}


size_t StateMachineParser::StatementDeclContext::getRuleIndex() const {
  return StateMachineParser::RuleStatementDecl;
}

void StateMachineParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void StateMachineParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

StateMachineParser::StatementDeclContext* StateMachineParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 152, StateMachineParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(724);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::IntID:
      case StateMachineParser::RealID:
      case StateMachineParser::BoolID:
      case StateMachineParser::StringID:
      case StateMachineParser::ThisID:
      case StateMachineParser::ReturnID:
      case StateMachineParser::EnumID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(722);
        statementBody();
        break;
      }

      case StateMachineParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(723);
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

StateMachineParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::FunctionCallStatementContext* StateMachineParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<StateMachineParser::FunctionCallStatementContext>(0);
}

StateMachineParser::AttributeAssignStatementContext* StateMachineParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<StateMachineParser::AttributeAssignStatementContext>(0);
}

StateMachineParser::SwitchStatementContext* StateMachineParser::StatementBodyContext::switchStatement() {
  return getRuleContext<StateMachineParser::SwitchStatementContext>(0);
}

StateMachineParser::ConditionalStatementContext* StateMachineParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<StateMachineParser::ConditionalStatementContext>(0);
}

StateMachineParser::LocalAssignStatementContext* StateMachineParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<StateMachineParser::LocalAssignStatementContext>(0);
}

StateMachineParser::SendToStatementContext* StateMachineParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<StateMachineParser::SendToStatementContext>(0);
}

StateMachineParser::BreakStatementContext* StateMachineParser::StatementBodyContext::breakStatement() {
  return getRuleContext<StateMachineParser::BreakStatementContext>(0);
}

StateMachineParser::ReturnStatementContext* StateMachineParser::StatementBodyContext::returnStatement() {
  return getRuleContext<StateMachineParser::ReturnStatementContext>(0);
}


size_t StateMachineParser::StatementBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleStatementBody;
}

void StateMachineParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void StateMachineParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

StateMachineParser::StatementBodyContext* StateMachineParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 154, StateMachineParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(734);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(726);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(727);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(728);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(729);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(730);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(731);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(732);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(733);
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

StateMachineParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::FunctionCallContext* StateMachineParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<StateMachineParser::FunctionCallContext>(0);
}

tree::TerminalNode* StateMachineParser::FunctionCallStatementContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::FunctionCallStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleFunctionCallStatement;
}

void StateMachineParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void StateMachineParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

StateMachineParser::FunctionCallStatementContext* StateMachineParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 156, StateMachineParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(736);
    functionCall();
    setState(737);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

StateMachineParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::NestedStatementBodyContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

tree::TerminalNode* StateMachineParser::NestedStatementBodyContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}

std::vector<StateMachineParser::StatementBodyContext *> StateMachineParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<StateMachineParser::StatementBodyContext>();
}

StateMachineParser::StatementBodyContext* StateMachineParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<StateMachineParser::StatementBodyContext>(i);
}


size_t StateMachineParser::NestedStatementBodyContext::getRuleIndex() const {
  return StateMachineParser::RuleNestedStatementBody;
}

void StateMachineParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void StateMachineParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

StateMachineParser::NestedStatementBodyContext* StateMachineParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 158, StateMachineParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(739);
    match(StateMachineParser::LBRACE);
    setState(743);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & ((1ULL << (StateMachineParser::ValueID - 12))
      | (1ULL << (StateMachineParser::GuardID - 12))
      | (1ULL << (StateMachineParser::RegionID - 12))
      | (1ULL << (StateMachineParser::SourceStateID - 12))
      | (1ULL << (StateMachineParser::TargetStateID - 12))
      | (1ULL << (StateMachineParser::NameID - 12))
      | (1ULL << (StateMachineParser::LabelID - 12))
      | (1ULL << (StateMachineParser::IntID - 12))
      | (1ULL << (StateMachineParser::RealID - 12))
      | (1ULL << (StateMachineParser::BoolID - 12))
      | (1ULL << (StateMachineParser::StringID - 12))
      | (1ULL << (StateMachineParser::ThisID - 12))
      | (1ULL << (StateMachineParser::ReturnID - 12))
      | (1ULL << (StateMachineParser::EnumID - 12))
      | (1ULL << (StateMachineParser::SendID - 12))
      | (1ULL << (StateMachineParser::SwitchID - 12))
      | (1ULL << (StateMachineParser::IfID - 12))
      | (1ULL << (StateMachineParser::BREAK - 12))
      | (1ULL << (StateMachineParser::ID - 12)))) != 0)) {
      setState(740);
      statementBody();
      setState(745);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(746);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

StateMachineParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ReturnStatementContext::ReturnID() {
  return getToken(StateMachineParser::ReturnID, 0);
}

StateMachineParser::OperationContext* StateMachineParser::ReturnStatementContext::operation() {
  return getRuleContext<StateMachineParser::OperationContext>(0);
}

tree::TerminalNode* StateMachineParser::ReturnStatementContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::ReturnStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleReturnStatement;
}

void StateMachineParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void StateMachineParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

StateMachineParser::ReturnStatementContext* StateMachineParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 160, StateMachineParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(748);
    match(StateMachineParser::ReturnID);
    setState(749);
    operation();
    setState(750);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

StateMachineParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::BreakStatementContext::BREAK() {
  return getToken(StateMachineParser::BREAK, 0);
}

tree::TerminalNode* StateMachineParser::BreakStatementContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::BreakStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleBreakStatement;
}

void StateMachineParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void StateMachineParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

StateMachineParser::BreakStatementContext* StateMachineParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 162, StateMachineParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(752);
    match(StateMachineParser::BREAK);
    setState(753);
    match(StateMachineParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

StateMachineParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::AtomContext* StateMachineParser::OperationContext::atom() {
  return getRuleContext<StateMachineParser::AtomContext>(0);
}

StateMachineParser::OperationOptionalContext* StateMachineParser::OperationContext::operationOptional() {
  return getRuleContext<StateMachineParser::OperationOptionalContext>(0);
}

tree::TerminalNode* StateMachineParser::OperationContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

StateMachineParser::OperationContext* StateMachineParser::OperationContext::operation() {
  return getRuleContext<StateMachineParser::OperationContext>(0);
}

tree::TerminalNode* StateMachineParser::OperationContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}

tree::TerminalNode* StateMachineParser::OperationContext::MINUS() {
  return getToken(StateMachineParser::MINUS, 0);
}

tree::TerminalNode* StateMachineParser::OperationContext::NotIdSymbol() {
  return getToken(StateMachineParser::NotIdSymbol, 0);
}


size_t StateMachineParser::OperationContext::getRuleIndex() const {
  return StateMachineParser::RuleOperation;
}

void StateMachineParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void StateMachineParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

StateMachineParser::OperationContext* StateMachineParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 164, StateMachineParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(766);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::TriggerID:
      case StateMachineParser::MessageTrigger:
      case StateMachineParser::ThisID:
      case StateMachineParser::TrueID:
      case StateMachineParser::FalseID:
      case StateMachineParser::INT:
      case StateMachineParser::REAL:
      case StateMachineParser::STRING:
      case StateMachineParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(755);
        atom();
        setState(756);
        operationOptional();
        break;
      }

      case StateMachineParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(758);
        match(StateMachineParser::LPAREN);
        setState(759);
        operation();
        setState(760);
        match(StateMachineParser::RPAREN);
        break;
      }

      case StateMachineParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(762);
        match(StateMachineParser::MINUS);
        setState(763);
        operation();
        break;
      }

      case StateMachineParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(764);
        match(StateMachineParser::NotIdSymbol);
        setState(765);
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

StateMachineParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::OperationContext* StateMachineParser::OperationOptionalContext::operation() {
  return getRuleContext<StateMachineParser::OperationContext>(0);
}

tree::TerminalNode* StateMachineParser::OperationOptionalContext::MULT() {
  return getToken(StateMachineParser::MULT, 0);
}

tree::TerminalNode* StateMachineParser::OperationOptionalContext::DIV() {
  return getToken(StateMachineParser::DIV, 0);
}

tree::TerminalNode* StateMachineParser::OperationOptionalContext::PLUS() {
  return getToken(StateMachineParser::PLUS, 0);
}

tree::TerminalNode* StateMachineParser::OperationOptionalContext::MINUS() {
  return getToken(StateMachineParser::MINUS, 0);
}


size_t StateMachineParser::OperationOptionalContext::getRuleIndex() const {
  return StateMachineParser::RuleOperationOptional;
}

void StateMachineParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void StateMachineParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

StateMachineParser::OperationOptionalContext* StateMachineParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 166, StateMachineParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(771);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::PLUS:
      case StateMachineParser::MINUS:
      case StateMachineParser::MULT:
      case StateMachineParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(768);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 85) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 85)) & ((1ULL << (StateMachineParser::PLUS - 85))
          | (1ULL << (StateMachineParser::MINUS - 85))
          | (1ULL << (StateMachineParser::MULT - 85))
          | (1ULL << (StateMachineParser::DIV - 85)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(769);
        operation();
        break;
      }

      case StateMachineParser::NotIdSymbol:
      case StateMachineParser::AndIdSymbol:
      case StateMachineParser::OrIdSymbol:
      case StateMachineParser::NotIdWord:
      case StateMachineParser::AndIdWord:
      case StateMachineParser::OrIdWord:
      case StateMachineParser::ASSIGN:
      case StateMachineParser::RPAREN:
      case StateMachineParser::RBRACE:
      case StateMachineParser::LESSTHAN:
      case StateMachineParser::GREATERTHAN:
      case StateMachineParser::SEMI: {
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

StateMachineParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ExpressionContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

StateMachineParser::ExpressionContext* StateMachineParser::ExpressionContext::expression() {
  return getRuleContext<StateMachineParser::ExpressionContext>(0);
}

tree::TerminalNode* StateMachineParser::ExpressionContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}

StateMachineParser::ExpressionOptionalContext* StateMachineParser::ExpressionContext::expressionOptional() {
  return getRuleContext<StateMachineParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* StateMachineParser::ExpressionContext::NotIdSymbol() {
  return getToken(StateMachineParser::NotIdSymbol, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionContext::NotIdWord() {
  return getToken(StateMachineParser::NotIdWord, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionContext::MINUS() {
  return getToken(StateMachineParser::MINUS, 0);
}

StateMachineParser::OperationContext* StateMachineParser::ExpressionContext::operation() {
  return getRuleContext<StateMachineParser::OperationContext>(0);
}


size_t StateMachineParser::ExpressionContext::getRuleIndex() const {
  return StateMachineParser::RuleExpression;
}

void StateMachineParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void StateMachineParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

StateMachineParser::ExpressionContext* StateMachineParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 168, StateMachineParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(787);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(773);
      match(StateMachineParser::LPAREN);
      setState(774);
      expression();
      setState(775);
      match(StateMachineParser::RPAREN);
      setState(776);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(778);
      match(StateMachineParser::NotIdSymbol);
      setState(779);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(780);
      match(StateMachineParser::NotIdWord);
      setState(781);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(782);
      match(StateMachineParser::MINUS);
      setState(783);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(784);
      operation();
      setState(785);
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

StateMachineParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::ExpressionContext* StateMachineParser::ExpressionOptionalContext::expression() {
  return getRuleContext<StateMachineParser::ExpressionContext>(0);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(StateMachineParser::OrIdSymbol, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(StateMachineParser::OrIdWord, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(StateMachineParser::AndIdSymbol, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(StateMachineParser::AndIdWord, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(StateMachineParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> StateMachineParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(StateMachineParser::ASSIGN);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(StateMachineParser::ASSIGN, i);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(StateMachineParser::NotIdSymbol, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(StateMachineParser::LESSTHAN, 0);
}

tree::TerminalNode* StateMachineParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(StateMachineParser::GREATERTHAN, 0);
}


size_t StateMachineParser::ExpressionOptionalContext::getRuleIndex() const {
  return StateMachineParser::RuleExpressionOptional;
}

void StateMachineParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void StateMachineParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

StateMachineParser::ExpressionOptionalContext* StateMachineParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 170, StateMachineParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(812);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::NotIdSymbol:
      case StateMachineParser::AndIdSymbol:
      case StateMachineParser::OrIdSymbol:
      case StateMachineParser::NotIdWord:
      case StateMachineParser::AndIdWord:
      case StateMachineParser::OrIdWord:
      case StateMachineParser::ASSIGN:
      case StateMachineParser::LESSTHAN:
      case StateMachineParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(808);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case StateMachineParser::OrIdSymbol: {
            setState(789);
            match(StateMachineParser::OrIdSymbol);
            break;
          }

          case StateMachineParser::OrIdWord: {
            setState(790);
            match(StateMachineParser::OrIdWord);
            break;
          }

          case StateMachineParser::AndIdSymbol: {
            setState(791);
            match(StateMachineParser::AndIdSymbol);
            break;
          }

          case StateMachineParser::AndIdWord: {
            setState(792);
            match(StateMachineParser::AndIdWord);
            break;
          }

          case StateMachineParser::ASSIGN: {
            setState(793);
            match(StateMachineParser::ASSIGN);
            setState(794);
            match(StateMachineParser::ASSIGN);
            break;
          }

          case StateMachineParser::NotIdSymbol: {
            setState(795);
            match(StateMachineParser::NotIdSymbol);
            setState(796);
            match(StateMachineParser::ASSIGN);
            break;
          }

          case StateMachineParser::NotIdWord: {
            setState(797);
            match(StateMachineParser::NotIdWord);
            break;
          }

          case StateMachineParser::LESSTHAN: {
            setState(798);
            match(StateMachineParser::LESSTHAN);
            setState(801);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case StateMachineParser::ASSIGN: {
                setState(799);
                match(StateMachineParser::ASSIGN);
                break;
              }

              case StateMachineParser::ValueID:
              case StateMachineParser::GuardID:
              case StateMachineParser::RegionID:
              case StateMachineParser::SourceStateID:
              case StateMachineParser::TargetStateID:
              case StateMachineParser::NameID:
              case StateMachineParser::LabelID:
              case StateMachineParser::TriggerID:
              case StateMachineParser::MessageTrigger:
              case StateMachineParser::ThisID:
              case StateMachineParser::NotIdSymbol:
              case StateMachineParser::NotIdWord:
              case StateMachineParser::TrueID:
              case StateMachineParser::FalseID:
              case StateMachineParser::INT:
              case StateMachineParser::REAL:
              case StateMachineParser::STRING:
              case StateMachineParser::ID:
              case StateMachineParser::LPAREN:
              case StateMachineParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case StateMachineParser::GREATERTHAN: {
            setState(803);
            match(StateMachineParser::GREATERTHAN);
            setState(806);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case StateMachineParser::ASSIGN: {
                setState(804);
                match(StateMachineParser::ASSIGN);
                break;
              }

              case StateMachineParser::ValueID:
              case StateMachineParser::GuardID:
              case StateMachineParser::RegionID:
              case StateMachineParser::SourceStateID:
              case StateMachineParser::TargetStateID:
              case StateMachineParser::NameID:
              case StateMachineParser::LabelID:
              case StateMachineParser::TriggerID:
              case StateMachineParser::MessageTrigger:
              case StateMachineParser::ThisID:
              case StateMachineParser::NotIdSymbol:
              case StateMachineParser::NotIdWord:
              case StateMachineParser::TrueID:
              case StateMachineParser::FalseID:
              case StateMachineParser::INT:
              case StateMachineParser::REAL:
              case StateMachineParser::STRING:
              case StateMachineParser::ID:
              case StateMachineParser::LPAREN:
              case StateMachineParser::MINUS: {
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
        setState(810);
        expression();
        break;
      }

      case StateMachineParser::RPAREN:
      case StateMachineParser::RBRACE:
      case StateMachineParser::SEMI: {
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

StateMachineParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::IfStatementContext* StateMachineParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<StateMachineParser::IfStatementContext>(0);
}

StateMachineParser::ElseStatementContext* StateMachineParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<StateMachineParser::ElseStatementContext>(0);
}


size_t StateMachineParser::ConditionalStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleConditionalStatement;
}

void StateMachineParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void StateMachineParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

StateMachineParser::ConditionalStatementContext* StateMachineParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 172, StateMachineParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(814);
    ifStatement();
    setState(817);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      setState(815);
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

StateMachineParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::IfStatementContext::IfID() {
  return getToken(StateMachineParser::IfID, 0);
}

StateMachineParser::IfEuTContext* StateMachineParser::IfStatementContext::ifEuT() {
  return getRuleContext<StateMachineParser::IfEuTContext>(0);
}

StateMachineParser::StatementDeclContext* StateMachineParser::IfStatementContext::statementDecl() {
  return getRuleContext<StateMachineParser::StatementDeclContext>(0);
}

tree::TerminalNode* StateMachineParser::IfStatementContext::SEMI() {
  return getToken(StateMachineParser::SEMI, 0);
}


size_t StateMachineParser::IfStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleIfStatement;
}

void StateMachineParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void StateMachineParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

StateMachineParser::IfStatementContext* StateMachineParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 174, StateMachineParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(819);
    match(StateMachineParser::IfID);
    setState(820);
    ifEuT();
    setState(823);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::IntID:
      case StateMachineParser::RealID:
      case StateMachineParser::BoolID:
      case StateMachineParser::StringID:
      case StateMachineParser::ThisID:
      case StateMachineParser::ReturnID:
      case StateMachineParser::EnumID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID:
      case StateMachineParser::LBRACE: {
        setState(821);
        statementDecl();
        break;
      }

      case StateMachineParser::SEMI: {
        setState(822);
        match(StateMachineParser::SEMI);
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

StateMachineParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::IfEuTContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

StateMachineParser::ExpressionContext* StateMachineParser::IfEuTContext::expression() {
  return getRuleContext<StateMachineParser::ExpressionContext>(0);
}

tree::TerminalNode* StateMachineParser::IfEuTContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}


size_t StateMachineParser::IfEuTContext::getRuleIndex() const {
  return StateMachineParser::RuleIfEuT;
}

void StateMachineParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void StateMachineParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

StateMachineParser::IfEuTContext* StateMachineParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 176, StateMachineParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(825);
    match(StateMachineParser::LPAREN);
    setState(826);
    expression();
    setState(827);
    match(StateMachineParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

StateMachineParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::ElseStatementContext::ElseID() {
  return getToken(StateMachineParser::ElseID, 0);
}

StateMachineParser::StatementDeclContext* StateMachineParser::ElseStatementContext::statementDecl() {
  return getRuleContext<StateMachineParser::StatementDeclContext>(0);
}


size_t StateMachineParser::ElseStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleElseStatement;
}

void StateMachineParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void StateMachineParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

StateMachineParser::ElseStatementContext* StateMachineParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 178, StateMachineParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(829);
    match(StateMachineParser::ElseID);
    setState(830);
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

StateMachineParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::SwitchStatementContext::SwitchID() {
  return getToken(StateMachineParser::SwitchID, 0);
}

StateMachineParser::SwitchPuTContext* StateMachineParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<StateMachineParser::SwitchPuTContext>(0);
}

tree::TerminalNode* StateMachineParser::SwitchStatementContext::LBRACE() {
  return getToken(StateMachineParser::LBRACE, 0);
}

tree::TerminalNode* StateMachineParser::SwitchStatementContext::RBRACE() {
  return getToken(StateMachineParser::RBRACE, 0);
}

StateMachineParser::DefaultStatementContext* StateMachineParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<StateMachineParser::DefaultStatementContext>(0);
}

std::vector<StateMachineParser::CaseStatementContext *> StateMachineParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<StateMachineParser::CaseStatementContext>();
}

StateMachineParser::CaseStatementContext* StateMachineParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<StateMachineParser::CaseStatementContext>(i);
}


size_t StateMachineParser::SwitchStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleSwitchStatement;
}

void StateMachineParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void StateMachineParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

StateMachineParser::SwitchStatementContext* StateMachineParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 180, StateMachineParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(832);
    match(StateMachineParser::SwitchID);
    setState(833);
    switchPuT();
    setState(834);
    match(StateMachineParser::LBRACE);
    setState(838);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StateMachineParser::CaseID) {
      setState(835);
      caseStatement();
      setState(840);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(843);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::DefaultID: {
        setState(841);
        defaultStatement();
        break;
      }

      case StateMachineParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(845);
    match(StateMachineParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

StateMachineParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::SwitchPuTContext::LPAREN() {
  return getToken(StateMachineParser::LPAREN, 0);
}

StateMachineParser::ContextIDContext* StateMachineParser::SwitchPuTContext::contextID() {
  return getRuleContext<StateMachineParser::ContextIDContext>(0);
}

tree::TerminalNode* StateMachineParser::SwitchPuTContext::RPAREN() {
  return getToken(StateMachineParser::RPAREN, 0);
}


size_t StateMachineParser::SwitchPuTContext::getRuleIndex() const {
  return StateMachineParser::RuleSwitchPuT;
}

void StateMachineParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void StateMachineParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

StateMachineParser::SwitchPuTContext* StateMachineParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 182, StateMachineParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(847);
    match(StateMachineParser::LPAREN);
    setState(848);
    contextID();
    setState(849);
    match(StateMachineParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

StateMachineParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::CaseStatementContext::CaseID() {
  return getToken(StateMachineParser::CaseID, 0);
}

StateMachineParser::LiteralValueContext* StateMachineParser::CaseStatementContext::literalValue() {
  return getRuleContext<StateMachineParser::LiteralValueContext>(0);
}

tree::TerminalNode* StateMachineParser::CaseStatementContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::NestedStatementBodyContext* StateMachineParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<StateMachineParser::NestedStatementBodyContext>(0);
}

std::vector<StateMachineParser::StatementBodyContext *> StateMachineParser::CaseStatementContext::statementBody() {
  return getRuleContexts<StateMachineParser::StatementBodyContext>();
}

StateMachineParser::StatementBodyContext* StateMachineParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<StateMachineParser::StatementBodyContext>(i);
}


size_t StateMachineParser::CaseStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleCaseStatement;
}

void StateMachineParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void StateMachineParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

StateMachineParser::CaseStatementContext* StateMachineParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 184, StateMachineParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(851);
    match(StateMachineParser::CaseID);
    setState(852);
    literalValue();
    setState(853);
    match(StateMachineParser::COLON);
    setState(861);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::LBRACE: {
        setState(854);
        nestedStatementBody();
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::IntID:
      case StateMachineParser::RealID:
      case StateMachineParser::BoolID:
      case StateMachineParser::StringID:
      case StateMachineParser::ThisID:
      case StateMachineParser::ReturnID:
      case StateMachineParser::EnumID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::CaseID:
      case StateMachineParser::DefaultID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID:
      case StateMachineParser::RBRACE: {
        setState(858);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 12) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 12)) & ((1ULL << (StateMachineParser::ValueID - 12))
          | (1ULL << (StateMachineParser::GuardID - 12))
          | (1ULL << (StateMachineParser::RegionID - 12))
          | (1ULL << (StateMachineParser::SourceStateID - 12))
          | (1ULL << (StateMachineParser::TargetStateID - 12))
          | (1ULL << (StateMachineParser::NameID - 12))
          | (1ULL << (StateMachineParser::LabelID - 12))
          | (1ULL << (StateMachineParser::IntID - 12))
          | (1ULL << (StateMachineParser::RealID - 12))
          | (1ULL << (StateMachineParser::BoolID - 12))
          | (1ULL << (StateMachineParser::StringID - 12))
          | (1ULL << (StateMachineParser::ThisID - 12))
          | (1ULL << (StateMachineParser::ReturnID - 12))
          | (1ULL << (StateMachineParser::EnumID - 12))
          | (1ULL << (StateMachineParser::SendID - 12))
          | (1ULL << (StateMachineParser::SwitchID - 12))
          | (1ULL << (StateMachineParser::IfID - 12))
          | (1ULL << (StateMachineParser::BREAK - 12))
          | (1ULL << (StateMachineParser::ID - 12)))) != 0)) {
          setState(855);
          statementBody();
          setState(860);
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

StateMachineParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StateMachineParser::DefaultStatementContext::DefaultID() {
  return getToken(StateMachineParser::DefaultID, 0);
}

tree::TerminalNode* StateMachineParser::DefaultStatementContext::COLON() {
  return getToken(StateMachineParser::COLON, 0);
}

StateMachineParser::NestedStatementBodyContext* StateMachineParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<StateMachineParser::NestedStatementBodyContext>(0);
}

std::vector<StateMachineParser::StatementBodyContext *> StateMachineParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<StateMachineParser::StatementBodyContext>();
}

StateMachineParser::StatementBodyContext* StateMachineParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<StateMachineParser::StatementBodyContext>(i);
}


size_t StateMachineParser::DefaultStatementContext::getRuleIndex() const {
  return StateMachineParser::RuleDefaultStatement;
}

void StateMachineParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void StateMachineParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

StateMachineParser::DefaultStatementContext* StateMachineParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 186, StateMachineParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(863);
    match(StateMachineParser::DefaultID);
    setState(864);
    match(StateMachineParser::COLON);
    setState(872);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StateMachineParser::LBRACE: {
        setState(865);
        nestedStatementBody();
        break;
      }

      case StateMachineParser::ValueID:
      case StateMachineParser::GuardID:
      case StateMachineParser::RegionID:
      case StateMachineParser::SourceStateID:
      case StateMachineParser::TargetStateID:
      case StateMachineParser::NameID:
      case StateMachineParser::LabelID:
      case StateMachineParser::IntID:
      case StateMachineParser::RealID:
      case StateMachineParser::BoolID:
      case StateMachineParser::StringID:
      case StateMachineParser::ThisID:
      case StateMachineParser::ReturnID:
      case StateMachineParser::EnumID:
      case StateMachineParser::SendID:
      case StateMachineParser::SwitchID:
      case StateMachineParser::IfID:
      case StateMachineParser::BREAK:
      case StateMachineParser::ID:
      case StateMachineParser::RBRACE: {
        setState(869);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 12) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 12)) & ((1ULL << (StateMachineParser::ValueID - 12))
          | (1ULL << (StateMachineParser::GuardID - 12))
          | (1ULL << (StateMachineParser::RegionID - 12))
          | (1ULL << (StateMachineParser::SourceStateID - 12))
          | (1ULL << (StateMachineParser::TargetStateID - 12))
          | (1ULL << (StateMachineParser::NameID - 12))
          | (1ULL << (StateMachineParser::LabelID - 12))
          | (1ULL << (StateMachineParser::IntID - 12))
          | (1ULL << (StateMachineParser::RealID - 12))
          | (1ULL << (StateMachineParser::BoolID - 12))
          | (1ULL << (StateMachineParser::StringID - 12))
          | (1ULL << (StateMachineParser::ThisID - 12))
          | (1ULL << (StateMachineParser::ReturnID - 12))
          | (1ULL << (StateMachineParser::EnumID - 12))
          | (1ULL << (StateMachineParser::SendID - 12))
          | (1ULL << (StateMachineParser::SwitchID - 12))
          | (1ULL << (StateMachineParser::IfID - 12))
          | (1ULL << (StateMachineParser::BREAK - 12))
          | (1ULL << (StateMachineParser::ID - 12)))) != 0)) {
          setState(866);
          statementBody();
          setState(871);
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

StateMachineParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StateMachineParser::SignalParamNameContext* StateMachineParser::AtomContext::signalParamName() {
  return getRuleContext<StateMachineParser::SignalParamNameContext>(0);
}

StateMachineParser::AttributeNameContext* StateMachineParser::AtomContext::attributeName() {
  return getRuleContext<StateMachineParser::AttributeNameContext>(0);
}

StateMachineParser::FunctionCallContext* StateMachineParser::AtomContext::functionCall() {
  return getRuleContext<StateMachineParser::FunctionCallContext>(0);
}

StateMachineParser::LiteralValueContext* StateMachineParser::AtomContext::literalValue() {
  return getRuleContext<StateMachineParser::LiteralValueContext>(0);
}


size_t StateMachineParser::AtomContext::getRuleIndex() const {
  return StateMachineParser::RuleAtom;
}

void StateMachineParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void StateMachineParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StateMachineListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

StateMachineParser::AtomContext* StateMachineParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 188, StateMachineParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(878);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(874);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(875);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(876);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(877);
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
std::vector<dfa::DFA> StateMachineParser::_decisionToDFA;
atn::PredictionContextCache StateMachineParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN StateMachineParser::_atn;
std::vector<uint16_t> StateMachineParser::_serializedATN;

std::vector<std::string> StateMachineParser::_ruleNames = {
  "stateMachineDecl", "stateMachineBody", "stateMachineBodyOptional", "stateDecl", 
  "stateIdPath", "stateDecls", "simpleStateDecl", "attributeAssignStatement", 
  "simpleStateBody", "junctionStateDecl", "junctionTransitionDecls", "junctionTransitionDecl", 
  "junctionTransitionBody", "concurrentStateDecl", "concurrentStateBody", 
  "regionDecl", "regionDecls", "regionBody", "compositeStateDecl", "compositeStateBody", 
  "finalStateDecl", "initStateDecl", "guardDecl", "actionDecl", "actionStatementBody", 
  "contextIDStatements", "actionStatementBodies", "actionNestedStatementBody", 
  "transitionDecl", "signalTransitionDecl", "signalTransitionBody", "timeoutTransitionDecl", 
  "timeoutTransitionBody", "refSignalDecl", "refPortDecl", "entryActionDecl", 
  "exitActionDecl", "timeoutDecl", "sourceStateDecl", "targetStateDecl", 
  "contextID", "componentIdPath", "signalIdPath", "attributeIdPath", "signalSend", 
  "commonDecl", "importPathDecl", "importPathBody", "importFileBody", "importAs", 
  "typeDefDecl", "typeDecl", "intTypeDecl", "realTypeDecl", "enumTypeDecl", 
  "attributeDecl", "literalValue", "signalParamName", "attributeName", "toPortName", 
  "localAssignStatement", "sendToStatement", "singleAssignment", "multiAssignment", 
  "signalDecl", "paramDecl", "functionDecl", "functionParameters", "functionCall", 
  "functionCallBody", "functionCallBodyOptional", "triggerDecl", "thisDecl", 
  "portDecl", "nameDecl", "idPath", "statementDecl", "statementBody", "functionCallStatement", 
  "nestedStatementBody", "returnStatement", "breakStatement", "operation", 
  "operationOptional", "expression", "expressionOptional", "conditionalStatement", 
  "ifStatement", "ifEuT", "elseStatement", "switchStatement", "switchPuT", 
  "caseStatement", "defaultStatement", "atom"
};

std::vector<std::string> StateMachineParser::_literalNames = {
  "", "'action'", "'StateMachine'", "'SimpleState'", "'SignalTransition'", 
  "'JunctionTransition'", "'CompositeState'", "'JunctionState'", "'ConcurrentState'", 
  "'FinalState'", "'signal'", "'port'", "'value'", "'guard'", "'Region'", 
  "'source'", "'target'", "'initState'", "'entry'", "'exit'", "", "'name'", 
  "'label'", "'enabled'", "'Type'", "'int'", "'real'", "'bool'", "'string'", 
  "'trigger'", "'msg'", "'this'", "'return'", "'TimeoutTransition'", "'enum'", 
  "'Declaration'", "'description'", "'Attribute'", "'Signal'", "'Port'", 
  "'import'", "'from'", "'to'", "'send'", "'Function'", "'switch'", "'case'", 
  "'default'", "'if'", "'else'", "'as'", "'@'", "'!'", "'&&'", "'||'", "'not'", 
  "'and'", "'or'", "'true'", "'false'", "'break'", "'='", "'<->'", "'->'", 
  "'<-'", "'..'", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", 
  "']'", "'<'", "'>'", "':'", "';'", "','", "'_'", "'.'", "'+'", "'-'", 
  "'*'", "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> StateMachineParser::_symbolicNames = {
  "", "ActionID", "StateMachineID", "SimpleStateID", "SignalTransitionID", 
  "JunctionTransitionID", "CompositeStateID", "JunctionStateID", "ConcurrentStateID", 
  "FinalStateID", "RefSignalID", "RefPortID", "ValueID", "GuardID", "RegionID", 
  "SourceStateID", "TargetStateID", "InitStateID", "EntryActionID", "ExitActionID", 
  "IGNORE_NEWLINE", "NameID", "LabelID", "EnabledID", "TypeID", "IntID", 
  "RealID", "BoolID", "StringID", "TriggerID", "MessageTrigger", "ThisID", 
  "ReturnID", "TimeoutTransitionID", "EnumID", "DeclarationID", "DescriptionID", 
  "AttributeID", "SignalID", "PortID", "ImportID", "FromID", "ToID", "SendID", 
  "FunctionID", "SwitchID", "CaseID", "DefaultID", "IfID", "ElseID", "AsID", 
  "AtID", "NotIdSymbol", "AndIdSymbol", "OrIdSymbol", "NotIdWord", "AndIdWord", 
  "OrIdWord", "TrueID", "FalseID", "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", 
  "LeftArrow", "RANGE", "INT", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", 
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LESSTHAN", 
  "GREATERTHAN", "COLON", "SEMI", "COMMA", "UNDER", "DOT", "PLUS", "MINUS", 
  "MULT", "DIV", "PIPE", "REF", "CONST", "NEWLINE", "WS"
};

dfa::Vocabulary StateMachineParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> StateMachineParser::_tokenNames;

StateMachineParser::Initializer::Initializer() {
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
    0x3, 0x5f, 0x373, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0xd5, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0xda, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0xe2, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 
    0xe7, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xea, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xf0, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xfa, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x104, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x108, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x114, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0x11e, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0x122, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x5, 0x12, 0x137, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x14b, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0x15d, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x163, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x16a, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x16e, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x5, 0x1c, 0x174, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x17c, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x5, 0x20, 0x188, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x5, 0x20, 0x18c, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x190, 
    0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x19e, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x1a2, 
    0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1b5, 
    0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1bb, 
    0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x1d1, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
    0x1d4, 0xb, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x1d9, 
    0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x1dc, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1e2, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x1e5, 0xb, 0x2d, 0x5, 0x2d, 0x1e7, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 
    0x2f, 0x1f1, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x1f4, 0xb, 0x2f, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1fa, 0xa, 0x30, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x20d, 0xa, 0x32, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x212, 0xa, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x21f, 0xa, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x36, 0x5, 0x36, 0x228, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x231, 0xa, 0x37, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x238, 
    0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x23b, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x244, 
    0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x24e, 0xa, 0x3a, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x255, 0xa, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 
    0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x261, 0xa, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 
    0x3f, 0x269, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x26f, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x273, 
    0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x276, 0xb, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 
    0x42, 0x280, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x283, 0xb, 0x42, 0x3, 
    0x42, 0x5, 0x42, 0x286, 0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 
    0x28a, 0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 
    0x44, 0x297, 0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x29f, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 
    0x2a2, 0xb, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x2ae, 
    0xa, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 
    0x48, 0x2b5, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 
    0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 
    0x4b, 0x2c1, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x2c4, 0xb, 0x4b, 0x3, 
    0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x2d0, 0xa, 0x4d, 0xc, 0x4d, 
    0xe, 0x4d, 0x2d3, 0xb, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x2d7, 
    0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x2e1, 0xa, 0x4f, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x2e8, 0xa, 0x51, 
    0xc, 0x51, 0xe, 0x51, 0x2eb, 0xb, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 
    0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x301, 0xa, 0x54, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x306, 0xa, 0x55, 0x3, 0x56, 
    0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 
    0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 
    0x5, 0x56, 0x316, 0xa, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 
    0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 
    0x57, 0x3, 0x57, 0x5, 0x57, 0x324, 0xa, 0x57, 0x3, 0x57, 0x3, 0x57, 
    0x3, 0x57, 0x5, 0x57, 0x329, 0xa, 0x57, 0x5, 0x57, 0x32b, 0xa, 0x57, 
    0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x32f, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 
    0x3, 0x58, 0x5, 0x58, 0x334, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x5, 0x59, 0x33a, 0xa, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 
    0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 
    0x5c, 0x3, 0x5c, 0x7, 0x5c, 0x347, 0xa, 0x5c, 0xc, 0x5c, 0xe, 0x5c, 
    0x34a, 0xb, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x34e, 0xa, 0x5c, 
    0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 
    0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x35b, 
    0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x35e, 0xb, 0x5e, 0x5, 0x5e, 0x360, 
    0xa, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x7, 0x5f, 0x366, 
    0xa, 0x5f, 0xc, 0x5f, 0xe, 0x5f, 0x369, 0xb, 0x5f, 0x5, 0x5f, 0x36b, 
    0xa, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x371, 
    0xa, 0x60, 0x3, 0x60, 0x2, 0x2, 0x61, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 
    0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
    0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
    0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 
    0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 
    0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0x2, 0x6, 0x3, 0x2, 0x44, 0x45, 0x5, 0x2, 
    0xe, 0x12, 0x17, 0x18, 0x47, 0x47, 0x3, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x57, 
    0x5a, 0x2, 0x390, 0x2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x4, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x8, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xc, 0xef, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x12, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x109, 0x3, 0x2, 0x2, 0x2, 0x16, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x115, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x125, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x12a, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x22, 0x136, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x138, 0x3, 0x2, 0x2, 0x2, 0x26, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x28, 0x140, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x143, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x14c, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x30, 0x15e, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x169, 0x3, 0x2, 0x2, 0x2, 0x34, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x173, 0x3, 0x2, 0x2, 0x2, 0x38, 0x175, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x182, 0x3, 0x2, 0x2, 0x2, 0x40, 0x194, 0x3, 0x2, 0x2, 0x2, 0x42, 0x199, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1ab, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1b6, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1c1, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1cb, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x1e6, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1f2, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1fb, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x64, 0x211, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x213, 0x3, 0x2, 0x2, 0x2, 0x68, 0x21e, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x220, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x229, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x232, 0x3, 0x2, 0x2, 0x2, 0x70, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x24d, 0x3, 0x2, 0x2, 0x2, 0x74, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x76, 0x254, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x258, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x25b, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x264, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x26e, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x270, 0x3, 0x2, 0x2, 0x2, 0x82, 0x279, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x86, 0x290, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x2ad, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2b6, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2bc, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x98, 0x2cc, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x2e0, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x2e5, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x300, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x305, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x315, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0x32e, 0x3, 0x2, 0x2, 0x2, 0xae, 0x330, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0x335, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x33b, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0x33f, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x342, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0x351, 0x3, 0x2, 0x2, 0x2, 0xba, 0x355, 0x3, 0x2, 0x2, 0x2, 
    0xbc, 0x361, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x370, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xc1, 0x7, 0x4, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x4c, 0x2, 0x2, 0xc2, 0xc3, 
    0x5, 0x4, 0x3, 0x2, 0xc3, 0xc4, 0x7, 0x4d, 0x2, 0x2, 0xc4, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x96, 0x4c, 0x2, 0xc6, 0xc7, 0x5, 0x6, 
    0x4, 0x2, 0xc7, 0x5, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xd5, 0x5, 0x86, 0x44, 
    0x2, 0xc9, 0xd5, 0x5, 0x66, 0x34, 0x2, 0xca, 0xd5, 0x5, 0x70, 0x39, 
    0x2, 0xcb, 0xd5, 0x5, 0x82, 0x42, 0x2, 0xcc, 0xd5, 0x5, 0x94, 0x4b, 
    0x2, 0xcd, 0xd5, 0x5, 0x2c, 0x17, 0x2, 0xce, 0xd5, 0x5, 0xe, 0x8, 0x2, 
    0xcf, 0xd5, 0x5, 0x14, 0xb, 0x2, 0xd0, 0xd5, 0x5, 0x1c, 0xf, 0x2, 0xd1, 
    0xd5, 0x5, 0x26, 0x14, 0x2, 0xd2, 0xd5, 0x5, 0x2a, 0x16, 0x2, 0xd3, 
    0xd5, 0x5, 0x3a, 0x1e, 0x2, 0xd4, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xcb, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xcf, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x6, 0x4, 0x2, 0xd7, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xe2, 0x5, 0x2c, 0x17, 0x2, 0xdc, 0xe2, 0x5, 0xe, 0x8, 
    0x2, 0xdd, 0xe2, 0x5, 0x14, 0xb, 0x2, 0xde, 0xe2, 0x5, 0x1c, 0xf, 0x2, 
    0xdf, 0xe2, 0x5, 0x26, 0x14, 0x2, 0xe0, 0xe2, 0x5, 0x2a, 0x16, 0x2, 
    0xe1, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xe8, 0x5, 0x52, 0x2a, 0x2, 0xe4, 0xe5, 0x7, 0x56, 
    0x2, 0x2, 0xe5, 0xe7, 0x5, 0x52, 0x2a, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xb, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x8, 0x5, 0x2, 0xec, 0xed, 
    0x5, 0xc, 0x7, 0x2, 0xed, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xef, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf9, 0x7, 0x5, 0x2, 
    0x2, 0xf2, 0xf3, 0x5, 0x52, 0x2a, 0x2, 0xf3, 0xf4, 0x7, 0x53, 0x2, 0x2, 
    0xf4, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x4c, 0x2, 0x2, 0xf6, 
    0xf7, 0x5, 0x12, 0xa, 0x2, 0xf7, 0xf8, 0x7, 0x4d, 0x2, 0x2, 0xf8, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xf5, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xf, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x76, 
    0x3c, 0x2, 0xfc, 0xfd, 0x7, 0x3f, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0xa6, 0x54, 
    0x2, 0xfe, 0xff, 0x7, 0x53, 0x2, 0x2, 0xff, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x100, 0x103, 0x5, 0x96, 0x4c, 0x2, 0x101, 0x104, 0x5, 0x48, 0x25, 0x2, 
    0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x103, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 0x107, 0x3, 0x2, 0x2, 0x2, 
    0x105, 0x108, 0x5, 0x4a, 0x26, 0x2, 0x106, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x106, 0x3, 0x2, 0x2, 0x2, 
    0x108, 0x13, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x9, 0x2, 0x2, 0x10a, 
    0x10b, 0x7, 0x4c, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x96, 0x4c, 0x2, 0x10c, 
    0x10d, 0x5, 0x16, 0xc, 0x2, 0x10d, 0x10e, 0x7, 0x4d, 0x2, 0x2, 0x10e, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x5, 0x18, 0xd, 0x2, 0x110, 
    0x111, 0x5, 0x16, 0xc, 0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 
    0x114, 0x3, 0x2, 0x2, 0x2, 0x113, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 0x17, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 
    0x7, 0x7, 0x2, 0x2, 0x116, 0x117, 0x7, 0x4c, 0x2, 0x2, 0x117, 0x118, 
    0x5, 0x1a, 0xe, 0x2, 0x118, 0x119, 0x7, 0x4d, 0x2, 0x2, 0x119, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x5, 0x96, 0x4c, 0x2, 0x11b, 0x11e, 
    0x5, 0x2e, 0x18, 0x2, 0x11c, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 
    0x3, 0x2, 0x2, 0x2, 0x11d, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x5, 0x30, 0x19, 0x2, 0x120, 0x122, 
    0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x120, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 
    0x5, 0x50, 0x29, 0x2, 0x124, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 
    0x7, 0xa, 0x2, 0x2, 0x126, 0x127, 0x7, 0x4c, 0x2, 0x2, 0x127, 0x128, 
    0x5, 0x1e, 0x10, 0x2, 0x128, 0x129, 0x7, 0x4d, 0x2, 0x2, 0x129, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x5, 0x12, 0xa, 0x2, 0x12b, 0x12c, 
    0x5, 0x22, 0x12, 0x2, 0x12c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 
    0x7, 0x10, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x4c, 0x2, 0x2, 0x12f, 0x130, 
    0x5, 0x24, 0x13, 0x2, 0x130, 0x131, 0x7, 0x4d, 0x2, 0x2, 0x131, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x5, 0x20, 0x11, 0x2, 0x133, 0x134, 
    0x5, 0x22, 0x12, 0x2, 0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 
    0x3, 0x2, 0x2, 0x2, 0x136, 0x132, 0x3, 0x2, 0x2, 0x2, 0x136, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x137, 0x23, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x5, 
    0x96, 0x4c, 0x2, 0x139, 0x13a, 0x5, 0xc, 0x7, 0x2, 0x13a, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x8, 0x2, 0x2, 0x13c, 0x13d, 0x7, 
    0x4c, 0x2, 0x2, 0x13d, 0x13e, 0x5, 0x28, 0x15, 0x2, 0x13e, 0x13f, 0x7, 
    0x4d, 0x2, 0x2, 0x13f, 0x27, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x5, 
    0x12, 0xa, 0x2, 0x141, 0x142, 0x5, 0xc, 0x7, 0x2, 0x142, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x14a, 0x7, 0xb, 0x2, 0x2, 0x144, 0x145, 0x7, 
    0x47, 0x2, 0x2, 0x145, 0x14b, 0x7, 0x53, 0x2, 0x2, 0x146, 0x147, 0x7, 
    0x4c, 0x2, 0x2, 0x147, 0x148, 0x5, 0x96, 0x4c, 0x2, 0x148, 0x149, 0x7, 
    0x4d, 0x2, 0x2, 0x149, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x144, 0x3, 
    0x2, 0x2, 0x2, 0x14a, 0x146, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14d, 0x7, 0x13, 0x2, 0x2, 0x14d, 0x14e, 0x7, 0x52, 
    0x2, 0x2, 0x14e, 0x14f, 0x5, 0x98, 0x4d, 0x2, 0x14f, 0x150, 0x7, 0x53, 
    0x2, 0x2, 0x150, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0xf, 0x2, 
    0x2, 0x152, 0x15c, 0x7, 0x52, 0x2, 0x2, 0x153, 0x154, 0x5, 0xaa, 0x56, 
    0x2, 0x154, 0x155, 0x7, 0x53, 0x2, 0x2, 0x155, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x156, 0x157, 0x7, 0x4c, 0x2, 0x2, 0x157, 0x158, 0x5, 0xaa, 0x56, 
    0x2, 0x158, 0x159, 0x7, 0x4d, 0x2, 0x2, 0x159, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x15b, 0x7, 0x33, 0x2, 0x2, 0x15b, 0x15d, 0x7, 0x53, 0x2, 
    0x2, 0x15c, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x15e, 0x15f, 0x7, 0x3, 0x2, 0x2, 0x15f, 0x162, 0x7, 0x52, 0x2, 0x2, 
    0x160, 0x163, 0x5, 0x32, 0x1a, 0x2, 0x161, 0x163, 0x5, 0x38, 0x1d, 0x2, 
    0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x161, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x31, 0x3, 0x2, 0x2, 0x2, 0x164, 0x16a, 0x5, 0x7c, 0x3f, 0x2, 
    0x165, 0x16a, 0x5, 0xb6, 0x5c, 0x2, 0x166, 0x16a, 0x5, 0xae, 0x58, 0x2, 
    0x167, 0x16a, 0x5, 0xa4, 0x53, 0x2, 0x168, 0x16a, 0x5, 0x34, 0x1b, 0x2, 
    0x169, 0x164, 0x3, 0x2, 0x2, 0x2, 0x169, 0x165, 0x3, 0x2, 0x2, 0x2, 
    0x169, 0x166, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 
    0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x33, 0x3, 0x2, 0x2, 0x2, 0x16b, 
    0x16e, 0x5, 0x9e, 0x50, 0x2, 0x16c, 0x16e, 0x5, 0x10, 0x9, 0x2, 0x16d, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x5, 0x32, 0x1a, 0x2, 0x170, 
    0x171, 0x5, 0x36, 0x1c, 0x2, 0x171, 0x174, 0x3, 0x2, 0x2, 0x2, 0x172, 
    0x174, 0x3, 0x2, 0x2, 0x2, 0x173, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x173, 
    0x172, 0x3, 0x2, 0x2, 0x2, 0x174, 0x37, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 
    0x7, 0x4c, 0x2, 0x2, 0x176, 0x177, 0x5, 0x36, 0x1c, 0x2, 0x177, 0x178, 
    0x7, 0x4d, 0x2, 0x2, 0x178, 0x39, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17c, 
    0x5, 0x3c, 0x1f, 0x2, 0x17a, 0x17c, 0x5, 0x40, 0x21, 0x2, 0x17b, 0x179, 
    0x3, 0x2, 0x2, 0x2, 0x17b, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x17d, 0x17e, 0x7, 0x6, 0x2, 0x2, 0x17e, 0x17f, 0x7, 
    0x4c, 0x2, 0x2, 0x17f, 0x180, 0x5, 0x3e, 0x20, 0x2, 0x180, 0x181, 0x7, 
    0x4d, 0x2, 0x2, 0x181, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x182, 0x187, 0x5, 
    0x96, 0x4c, 0x2, 0x183, 0x184, 0x5, 0x44, 0x23, 0x2, 0x184, 0x185, 0x5, 
    0x46, 0x24, 0x2, 0x185, 0x188, 0x3, 0x2, 0x2, 0x2, 0x186, 0x188, 0x3, 
    0x2, 0x2, 0x2, 0x187, 0x183, 0x3, 0x2, 0x2, 0x2, 0x187, 0x186, 0x3, 
    0x2, 0x2, 0x2, 0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x5, 
    0x2e, 0x18, 0x2, 0x18a, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 
    0x2, 0x2, 0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18f, 0x3, 
    0x2, 0x2, 0x2, 0x18d, 0x190, 0x5, 0x30, 0x19, 0x2, 0x18e, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x18f, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x18e, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x5, 
    0x4e, 0x28, 0x2, 0x192, 0x193, 0x5, 0x50, 0x29, 0x2, 0x193, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x194, 0x195, 0x7, 0x23, 0x2, 0x2, 0x195, 0x196, 0x7, 
    0x4c, 0x2, 0x2, 0x196, 0x197, 0x5, 0x42, 0x22, 0x2, 0x197, 0x198, 0x7, 
    0x4d, 0x2, 0x2, 0x198, 0x41, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x5, 
    0x96, 0x4c, 0x2, 0x19a, 0x19d, 0x5, 0x4c, 0x27, 0x2, 0x19b, 0x19e, 0x5, 
    0x2e, 0x18, 0x2, 0x19c, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a1, 0x3, 
    0x2, 0x2, 0x2, 0x19f, 0x1a2, 0x5, 0x30, 0x19, 0x2, 0x1a0, 0x1a2, 0x3, 
    0x2, 0x2, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a0, 0x3, 
    0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x5, 
    0x4e, 0x28, 0x2, 0x1a4, 0x1a5, 0x5, 0x50, 0x29, 0x2, 0x1a5, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0xc, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 
    0x52, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x47, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 
    0x53, 0x2, 0x2, 0x1aa, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 0x7, 
    0xd, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x52, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 
    0x47, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x53, 0x2, 0x2, 0x1af, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x7, 0x14, 0x2, 0x2, 0x1b1, 0x1b4, 0x7, 
    0x52, 0x2, 0x2, 0x1b2, 0x1b5, 0x5, 0x32, 0x1a, 0x2, 0x1b3, 0x1b5, 0x5, 
    0x38, 0x1d, 0x2, 0x1b4, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b3, 0x3, 
    0x2, 0x2, 0x2, 0x1b5, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x7, 0x15, 
    0x2, 0x2, 0x1b7, 0x1ba, 0x7, 0x52, 0x2, 0x2, 0x1b8, 0x1bb, 0x5, 0x32, 
    0x1a, 0x2, 0x1b9, 0x1bb, 0x5, 0x38, 0x1d, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 
    0x2, 0x2, 0x1ba, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x1bc, 0x1bd, 0x7, 0xe, 0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x52, 0x2, 
    0x2, 0x1be, 0x1bf, 0x9, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x53, 0x2, 
    0x2, 0x1c0, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x7, 0x11, 0x2, 
    0x2, 0x1c2, 0x1c3, 0x7, 0x52, 0x2, 0x2, 0x1c3, 0x1c4, 0x5, 0xa, 0x6, 
    0x2, 0x1c4, 0x1c5, 0x7, 0x53, 0x2, 0x2, 0x1c5, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x1c6, 0x1c7, 0x7, 0x12, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x52, 0x2, 
    0x2, 0x1c8, 0x1c9, 0x5, 0xa, 0x6, 0x2, 0x1c9, 0x1ca, 0x7, 0x53, 0x2, 
    0x2, 0x1ca, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x9, 0x3, 0x2, 0x2, 
    0x1cc, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1d2, 0x5, 0x52, 0x2a, 0x2, 
    0x1ce, 0x1cf, 0x7, 0x56, 0x2, 0x2, 0x1cf, 0x1d1, 0x5, 0x52, 0x2a, 0x2, 
    0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
    0x1d2, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
    0x1da, 0x5, 0x52, 0x2a, 0x2, 0x1d6, 0x1d7, 0x7, 0x56, 0x2, 0x2, 0x1d7, 
    0x1d9, 0x5, 0x52, 0x2a, 0x2, 0x1d8, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
    0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 
    0x1db, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1da, 
    0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1e7, 0x5, 0x76, 0x3c, 0x2, 0x1de, 0x1e3, 
    0x5, 0x52, 0x2a, 0x2, 0x1df, 0x1e0, 0x7, 0x56, 0x2, 0x2, 0x1e0, 0x1e2, 
    0x5, 0x52, 0x2a, 0x2, 0x1e1, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e5, 
    0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 
    0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e3, 
    0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1de, 
    0x3, 0x2, 0x2, 0x2, 0x1e7, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x5, 
    0x56, 0x2c, 0x2, 0x1e9, 0x1ea, 0x7, 0x4a, 0x2, 0x2, 0x1ea, 0x1eb, 0x5, 
    0x8c, 0x47, 0x2, 0x1eb, 0x1ec, 0x7, 0x4b, 0x2, 0x2, 0x1ec, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x1ed, 0x1f1, 0x5, 0x66, 0x34, 0x2, 0x1ee, 0x1f1, 0x5, 
    0x70, 0x39, 0x2, 0x1ef, 0x1f1, 0x5, 0x82, 0x42, 0x2, 0x1f0, 0x1ed, 0x3, 
    0x2, 0x2, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ef, 0x3, 
    0x2, 0x2, 0x2, 0x1f1, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f0, 0x3, 
    0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x60, 
    0x31, 0x2, 0x1f6, 0x1f7, 0x5, 0x5e, 0x30, 0x2, 0x1f7, 0x1fa, 0x3, 0x2, 
    0x2, 0x2, 0x1f8, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f5, 0x3, 0x2, 
    0x2, 0x2, 0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x1fb, 0x1fc, 0x7, 0x2a, 0x2, 0x2, 0x1fc, 0x1fd, 0x7, 0x50, 0x2, 
    0x2, 0x1fd, 0x1fe, 0x5, 0x62, 0x32, 0x2, 0x1fe, 0x1ff, 0x7, 0x51, 0x2, 
    0x2, 0x1ff, 0x200, 0x5, 0x64, 0x33, 0x2, 0x200, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x202, 0x5, 0x52, 0x2a, 0x2, 0x202, 0x203, 0x7, 0x56, 0x2, 
    0x2, 0x203, 0x204, 0x5, 0x52, 0x2a, 0x2, 0x204, 0x20d, 0x3, 0x2, 0x2, 
    0x2, 0x205, 0x206, 0x7, 0x43, 0x2, 0x2, 0x206, 0x207, 0x7, 0x5a, 0x2, 
    0x2, 0x207, 0x20d, 0x5, 0x62, 0x32, 0x2, 0x208, 0x209, 0x5, 0x52, 0x2a, 
    0x2, 0x209, 0x20a, 0x7, 0x5a, 0x2, 0x2, 0x20a, 0x20b, 0x5, 0x62, 0x32, 
    0x2, 0x20b, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x201, 0x3, 0x2, 0x2, 
    0x2, 0x20c, 0x205, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x208, 0x3, 0x2, 0x2, 
    0x2, 0x20d, 0x63, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20f, 0x7, 0x34, 0x2, 
    0x2, 0x20f, 0x212, 0x5, 0x52, 0x2a, 0x2, 0x210, 0x212, 0x3, 0x2, 0x2, 
    0x2, 0x211, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 
    0x2, 0x212, 0x65, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x7, 0x1a, 0x2, 
    0x2, 0x214, 0x215, 0x5, 0x68, 0x35, 0x2, 0x215, 0x216, 0x5, 0x52, 0x2a, 
    0x2, 0x216, 0x217, 0x7, 0x53, 0x2, 0x2, 0x217, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x218, 0x21f, 0x5, 0x6a, 0x36, 0x2, 0x219, 0x21f, 0x5, 0x6c, 0x37, 
    0x2, 0x21a, 0x21f, 0x5, 0x6e, 0x38, 0x2, 0x21b, 0x21f, 0x7, 0x1d, 0x2, 
    0x2, 0x21c, 0x21f, 0x7, 0x1e, 0x2, 0x2, 0x21d, 0x21f, 0x5, 0x52, 0x2a, 
    0x2, 0x21e, 0x218, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x219, 0x3, 0x2, 0x2, 
    0x2, 0x21e, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21b, 0x3, 0x2, 0x2, 
    0x2, 0x21e, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21d, 0x3, 0x2, 0x2, 
    0x2, 0x21f, 0x69, 0x3, 0x2, 0x2, 0x2, 0x220, 0x227, 0x7, 0x1b, 0x2, 
    0x2, 0x221, 0x222, 0x7, 0x4a, 0x2, 0x2, 0x222, 0x223, 0x7, 0x44, 0x2, 
    0x2, 0x223, 0x224, 0x7, 0x43, 0x2, 0x2, 0x224, 0x225, 0x7, 0x44, 0x2, 
    0x2, 0x225, 0x228, 0x7, 0x4b, 0x2, 0x2, 0x226, 0x228, 0x3, 0x2, 0x2, 
    0x2, 0x227, 0x221, 0x3, 0x2, 0x2, 0x2, 0x227, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x228, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x229, 0x230, 0x7, 0x1c, 0x2, 
    0x2, 0x22a, 0x22b, 0x7, 0x4a, 0x2, 0x2, 0x22b, 0x22c, 0x7, 0x45, 0x2, 
    0x2, 0x22c, 0x22d, 0x7, 0x43, 0x2, 0x2, 0x22d, 0x22e, 0x7, 0x45, 0x2, 
    0x2, 0x22e, 0x231, 0x7, 0x4b, 0x2, 0x2, 0x22f, 0x231, 0x3, 0x2, 0x2, 
    0x2, 0x230, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22f, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x7, 0x24, 0x2, 
    0x2, 0x233, 0x234, 0x7, 0x4a, 0x2, 0x2, 0x234, 0x239, 0x5, 0x52, 0x2a, 
    0x2, 0x235, 0x236, 0x7, 0x54, 0x2, 0x2, 0x236, 0x238, 0x5, 0x52, 0x2a, 
    0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x238, 0x23b, 0x3, 0x2, 0x2, 
    0x2, 0x239, 0x237, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x3, 0x2, 0x2, 
    0x2, 0x23a, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x239, 0x3, 0x2, 0x2, 
    0x2, 0x23c, 0x23d, 0x7, 0x4b, 0x2, 0x2, 0x23d, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x23e, 0x23f, 0x7, 0x27, 0x2, 0x2, 0x23f, 0x240, 0x5, 0x68, 0x35, 
    0x2, 0x240, 0x243, 0x5, 0x52, 0x2a, 0x2, 0x241, 0x242, 0x7, 0x3f, 0x2, 
    0x2, 0x242, 0x244, 0x5, 0x72, 0x3a, 0x2, 0x243, 0x241, 0x3, 0x2, 0x2, 
    0x2, 0x243, 0x244, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x3, 0x2, 0x2, 
    0x2, 0x245, 0x246, 0x7, 0x53, 0x2, 0x2, 0x246, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x247, 0x24e, 0x7, 0x44, 0x2, 0x2, 0x248, 0x24e, 0x7, 0x45, 0x2, 
    0x2, 0x249, 0x24e, 0x7, 0x46, 0x2, 0x2, 0x24a, 0x24e, 0x7, 0x3c, 0x2, 
    0x2, 0x24b, 0x24e, 0x7, 0x3d, 0x2, 0x2, 0x24c, 0x24e, 0x5, 0x52, 0x2a, 
    0x2, 0x24d, 0x247, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x248, 0x3, 0x2, 0x2, 
    0x2, 0x24d, 0x249, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24a, 0x3, 0x2, 0x2, 
    0x2, 0x24d, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24c, 0x3, 0x2, 0x2, 
    0x2, 0x24e, 0x73, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x5, 0x90, 0x49, 
    0x2, 0x250, 0x251, 0x5, 0x52, 0x2a, 0x2, 0x251, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x255, 0x5, 0x92, 0x4a, 0x2, 0x253, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x254, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x253, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x5, 0x52, 0x2a, 
    0x2, 0x257, 0x77, 0x3, 0x2, 0x2, 0x2, 0x258, 0x259, 0x7, 0x2c, 0x2, 
    0x2, 0x259, 0x25a, 0x5, 0x52, 0x2a, 0x2, 0x25a, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x25b, 0x25c, 0x5, 0x68, 0x35, 0x2, 0x25c, 0x260, 0x5, 0x52, 0x2a, 
    0x2, 0x25d, 0x25e, 0x7, 0x3f, 0x2, 0x2, 0x25e, 0x261, 0x5, 0xaa, 0x56, 
    0x2, 0x25f, 0x261, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25d, 0x3, 0x2, 0x2, 
    0x2, 0x260, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x261, 0x262, 0x3, 0x2, 0x2, 
    0x2, 0x262, 0x263, 0x7, 0x53, 0x2, 0x2, 0x263, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x264, 0x265, 0x7, 0x2d, 0x2, 0x2, 0x265, 0x268, 0x5, 0x5a, 0x2e, 
    0x2, 0x266, 0x269, 0x5, 0x78, 0x3d, 0x2, 0x267, 0x269, 0x3, 0x2, 0x2, 
    0x2, 0x268, 0x266, 0x3, 0x2, 0x2, 0x2, 0x268, 0x267, 0x3, 0x2, 0x2, 
    0x2, 0x269, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 0x7, 0x53, 0x2, 
    0x2, 0x26b, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26f, 0x5, 0x10, 0x9, 
    0x2, 0x26d, 0x26f, 0x5, 0x7c, 0x3f, 0x2, 0x26e, 0x26c, 0x3, 0x2, 0x2, 
    0x2, 0x26e, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x270, 0x274, 0x7, 0x4c, 0x2, 0x2, 0x271, 0x273, 0x5, 0x7e, 0x40, 0x2, 
    0x272, 0x271, 0x3, 0x2, 0x2, 0x2, 0x273, 0x276, 0x3, 0x2, 0x2, 0x2, 
    0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x275, 0x277, 0x3, 0x2, 0x2, 0x2, 0x276, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x278, 0x7, 0x4d, 0x2, 0x2, 0x278, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x279, 0x27a, 0x7, 0x28, 0x2, 0x2, 0x27a, 0x289, 0x5, 0x52, 0x2a, 0x2, 
    0x27b, 0x285, 0x7, 0x4a, 0x2, 0x2, 0x27c, 0x281, 0x5, 0x84, 0x43, 0x2, 
    0x27d, 0x27e, 0x7, 0x54, 0x2, 0x2, 0x27e, 0x280, 0x5, 0x84, 0x43, 0x2, 
    0x27f, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x280, 0x283, 0x3, 0x2, 0x2, 0x2, 
    0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 0x2, 0x2, 0x2, 
    0x282, 0x286, 0x3, 0x2, 0x2, 0x2, 0x283, 0x281, 0x3, 0x2, 0x2, 0x2, 
    0x284, 0x286, 0x3, 0x2, 0x2, 0x2, 0x285, 0x27c, 0x3, 0x2, 0x2, 0x2, 
    0x285, 0x284, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x3, 0x2, 0x2, 0x2, 
    0x287, 0x28a, 0x7, 0x4b, 0x2, 0x2, 0x288, 0x28a, 0x3, 0x2, 0x2, 0x2, 
    0x289, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x289, 0x288, 0x3, 0x2, 0x2, 0x2, 
    0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x7, 0x53, 0x2, 0x2, 
    0x28c, 0x83, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x5, 0x68, 0x35, 0x2, 
    0x28e, 0x28f, 0x5, 0x52, 0x2a, 0x2, 0x28f, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x290, 0x291, 0x7, 0x2e, 0x2, 0x2, 0x291, 0x292, 0x5, 0x68, 0x35, 0x2, 
    0x292, 0x293, 0x5, 0x98, 0x4d, 0x2, 0x293, 0x296, 0x7, 0x4a, 0x2, 0x2, 
    0x294, 0x297, 0x5, 0x88, 0x45, 0x2, 0x295, 0x297, 0x3, 0x2, 0x2, 0x2, 
    0x296, 0x294, 0x3, 0x2, 0x2, 0x2, 0x296, 0x295, 0x3, 0x2, 0x2, 0x2, 
    0x297, 0x298, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x7, 0x4b, 0x2, 0x2, 
    0x299, 0x29a, 0x5, 0xa0, 0x51, 0x2, 0x29a, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x29b, 0x2a0, 0x5, 0x84, 0x43, 0x2, 0x29c, 0x29d, 0x7, 0x54, 0x2, 0x2, 
    0x29d, 0x29f, 0x5, 0x84, 0x43, 0x2, 0x29e, 0x29c, 0x3, 0x2, 0x2, 0x2, 
    0x29f, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 
    0x2a0, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x89, 0x3, 0x2, 0x2, 0x2, 0x2a2, 
    0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 0x5, 0x98, 0x4d, 0x2, 0x2a4, 
    0x2a5, 0x7, 0x4a, 0x2, 0x2, 0x2a5, 0x2a6, 0x5, 0x8c, 0x47, 0x2, 0x2a6, 
    0x2a7, 0x7, 0x4b, 0x2, 0x2, 0x2a7, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x2a8, 
    0x2ae, 0x5, 0x72, 0x3a, 0x2, 0x2a9, 0x2ae, 0x5, 0x74, 0x3b, 0x2, 0x2aa, 
    0x2ae, 0x5, 0x76, 0x3c, 0x2, 0x2ab, 0x2ae, 0x5, 0x8a, 0x46, 0x2, 0x2ac, 
    0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ae, 
    0x2af, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x5, 0x8e, 0x48, 0x2, 0x2b0, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x7, 0x54, 0x2, 0x2, 0x2b2, 
    0x2b5, 0x5, 0x8c, 0x47, 0x2, 0x2b3, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b4, 
    0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b5, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x9, 0x4, 0x2, 0x2, 0x2b7, 0x2b8, 
    0x7, 0x56, 0x2, 0x2, 0x2b8, 0x91, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 
    0x7, 0x21, 0x2, 0x2, 0x2ba, 0x2bb, 0x7, 0x56, 0x2, 0x2, 0x2bb, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x29, 0x2, 0x2, 0x2bd, 0x2c2, 
    0x5, 0x52, 0x2a, 0x2, 0x2be, 0x2bf, 0x7, 0x54, 0x2, 0x2, 0x2bf, 0x2c1, 
    0x5, 0x52, 0x2a, 0x2, 0x2c0, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c4, 
    0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 
    0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c2, 
    0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x53, 0x2, 0x2, 0x2c6, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c8, 0x7, 0x17, 0x2, 0x2, 0x2c8, 0x2c9, 
    0x7, 0x52, 0x2, 0x2, 0x2c9, 0x2ca, 0x5, 0x52, 0x2a, 0x2, 0x2ca, 0x2cb, 
    0x7, 0x53, 0x2, 0x2, 0x2cb, 0x97, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2d1, 
    0x5, 0x52, 0x2a, 0x2, 0x2cd, 0x2ce, 0x7, 0x56, 0x2, 0x2, 0x2ce, 0x2d0, 
    0x5, 0x52, 0x2a, 0x2, 0x2cf, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d3, 
    0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 
    0x3, 0x2, 0x2, 0x2, 0x2d2, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d1, 0x3, 
    0x2, 0x2, 0x2, 0x2d4, 0x2d7, 0x5, 0x9c, 0x4f, 0x2, 0x2d5, 0x2d7, 0x5, 
    0xa0, 0x51, 0x2, 0x2d6, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d5, 0x3, 
    0x2, 0x2, 0x2, 0x2d7, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2e1, 0x5, 0x9e, 
    0x50, 0x2, 0x2d9, 0x2e1, 0x5, 0x10, 0x9, 0x2, 0x2da, 0x2e1, 0x5, 0xb6, 
    0x5c, 0x2, 0x2db, 0x2e1, 0x5, 0xae, 0x58, 0x2, 0x2dc, 0x2e1, 0x5, 0x7a, 
    0x3e, 0x2, 0x2dd, 0x2e1, 0x5, 0x7c, 0x3f, 0x2, 0x2de, 0x2e1, 0x5, 0xa4, 
    0x53, 0x2, 0x2df, 0x2e1, 0x5, 0xa2, 0x52, 0x2, 0x2e0, 0x2d8, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2da, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2dc, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x2e2, 0x2e3, 0x5, 0x8a, 0x46, 0x2, 0x2e3, 0x2e4, 0x7, 0x53, 0x2, 
    0x2, 0x2e4, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e9, 0x7, 0x4c, 0x2, 
    0x2, 0x2e6, 0x2e8, 0x5, 0x9c, 0x4f, 0x2, 0x2e7, 0x2e6, 0x3, 0x2, 0x2, 
    0x2, 0x2e8, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e7, 0x3, 0x2, 0x2, 
    0x2, 0x2e9, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2ec, 0x3, 0x2, 0x2, 
    0x2, 0x2eb, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x7, 0x4d, 0x2, 
    0x2, 0x2ed, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x7, 0x22, 0x2, 
    0x2, 0x2ef, 0x2f0, 0x5, 0xa6, 0x54, 0x2, 0x2f0, 0x2f1, 0x7, 0x53, 0x2, 
    0x2, 0x2f1, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x7, 0x3e, 0x2, 
    0x2, 0x2f3, 0x2f4, 0x7, 0x53, 0x2, 0x2, 0x2f4, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x2f5, 0x2f6, 0x5, 0xbe, 0x60, 0x2, 0x2f6, 0x2f7, 0x5, 0xa8, 0x55, 
    0x2, 0x2f7, 0x301, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x7, 0x4a, 0x2, 
    0x2, 0x2f9, 0x2fa, 0x5, 0xa6, 0x54, 0x2, 0x2fa, 0x2fb, 0x7, 0x4b, 0x2, 
    0x2, 0x2fb, 0x301, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x7, 0x58, 0x2, 
    0x2, 0x2fd, 0x301, 0x5, 0xa6, 0x54, 0x2, 0x2fe, 0x2ff, 0x7, 0x36, 0x2, 
    0x2, 0x2ff, 0x301, 0x5, 0xa6, 0x54, 0x2, 0x300, 0x2f5, 0x3, 0x2, 0x2, 
    0x2, 0x300, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x300, 0x2fc, 0x3, 0x2, 0x2, 
    0x2, 0x300, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x301, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x302, 0x303, 0x9, 0x5, 0x2, 0x2, 0x303, 0x306, 0x5, 0xa6, 0x54, 0x2, 
    0x304, 0x306, 0x3, 0x2, 0x2, 0x2, 0x305, 0x302, 0x3, 0x2, 0x2, 0x2, 
    0x305, 0x304, 0x3, 0x2, 0x2, 0x2, 0x306, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x307, 
    0x308, 0x7, 0x4a, 0x2, 0x2, 0x308, 0x309, 0x5, 0xaa, 0x56, 0x2, 0x309, 
    0x30a, 0x7, 0x4b, 0x2, 0x2, 0x30a, 0x30b, 0x5, 0xac, 0x57, 0x2, 0x30b, 
    0x316, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x7, 0x36, 0x2, 0x2, 0x30d, 
    0x316, 0x5, 0xaa, 0x56, 0x2, 0x30e, 0x30f, 0x7, 0x39, 0x2, 0x2, 0x30f, 
    0x316, 0x5, 0xaa, 0x56, 0x2, 0x310, 0x311, 0x7, 0x58, 0x2, 0x2, 0x311, 
    0x316, 0x5, 0xaa, 0x56, 0x2, 0x312, 0x313, 0x5, 0xa6, 0x54, 0x2, 0x313, 
    0x314, 0x5, 0xac, 0x57, 0x2, 0x314, 0x316, 0x3, 0x2, 0x2, 0x2, 0x315, 
    0x307, 0x3, 0x2, 0x2, 0x2, 0x315, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x315, 
    0x30e, 0x3, 0x2, 0x2, 0x2, 0x315, 0x310, 0x3, 0x2, 0x2, 0x2, 0x315, 
    0x312, 0x3, 0x2, 0x2, 0x2, 0x316, 0xab, 0x3, 0x2, 0x2, 0x2, 0x317, 0x32b, 
    0x7, 0x38, 0x2, 0x2, 0x318, 0x32b, 0x7, 0x3b, 0x2, 0x2, 0x319, 0x32b, 
    0x7, 0x37, 0x2, 0x2, 0x31a, 0x32b, 0x7, 0x3a, 0x2, 0x2, 0x31b, 0x31c, 
    0x7, 0x3f, 0x2, 0x2, 0x31c, 0x32b, 0x7, 0x3f, 0x2, 0x2, 0x31d, 0x31e, 
    0x7, 0x36, 0x2, 0x2, 0x31e, 0x32b, 0x7, 0x3f, 0x2, 0x2, 0x31f, 0x32b, 
    0x7, 0x39, 0x2, 0x2, 0x320, 0x323, 0x7, 0x50, 0x2, 0x2, 0x321, 0x324, 
    0x7, 0x3f, 0x2, 0x2, 0x322, 0x324, 0x3, 0x2, 0x2, 0x2, 0x323, 0x321, 
    0x3, 0x2, 0x2, 0x2, 0x323, 0x322, 0x3, 0x2, 0x2, 0x2, 0x324, 0x32b, 
    0x3, 0x2, 0x2, 0x2, 0x325, 0x328, 0x7, 0x51, 0x2, 0x2, 0x326, 0x329, 
    0x7, 0x3f, 0x2, 0x2, 0x327, 0x329, 0x3, 0x2, 0x2, 0x2, 0x328, 0x326, 
    0x3, 0x2, 0x2, 0x2, 0x328, 0x327, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32b, 
    0x3, 0x2, 0x2, 0x2, 0x32a, 0x317, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x318, 
    0x3, 0x2, 0x2, 0x2, 0x32a, 0x319, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x31a, 
    0x3, 0x2, 0x2, 0x2, 0x32a, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x31d, 
    0x3, 0x2, 0x2, 0x2, 0x32a, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x320, 
    0x3, 0x2, 0x2, 0x2, 0x32a, 0x325, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32c, 
    0x3, 0x2, 0x2, 0x2, 0x32c, 0x32f, 0x5, 0xaa, 0x56, 0x2, 0x32d, 0x32f, 
    0x3, 0x2, 0x2, 0x2, 0x32e, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32d, 
    0x3, 0x2, 0x2, 0x2, 0x32f, 0xad, 0x3, 0x2, 0x2, 0x2, 0x330, 0x333, 0x5, 
    0xb0, 0x59, 0x2, 0x331, 0x334, 0x5, 0xb4, 0x5b, 0x2, 0x332, 0x334, 0x3, 
    0x2, 0x2, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 0x2, 0x333, 0x332, 0x3, 
    0x2, 0x2, 0x2, 0x334, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x7, 0x32, 
    0x2, 0x2, 0x336, 0x339, 0x5, 0xb2, 0x5a, 0x2, 0x337, 0x33a, 0x5, 0x9a, 
    0x4e, 0x2, 0x338, 0x33a, 0x7, 0x53, 0x2, 0x2, 0x339, 0x337, 0x3, 0x2, 
    0x2, 0x2, 0x339, 0x338, 0x3, 0x2, 0x2, 0x2, 0x33a, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0x33b, 0x33c, 0x7, 0x4a, 0x2, 0x2, 0x33c, 0x33d, 0x5, 0xaa, 0x56, 
    0x2, 0x33d, 0x33e, 0x7, 0x4b, 0x2, 0x2, 0x33e, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0x33f, 0x340, 0x7, 0x33, 0x2, 0x2, 0x340, 0x341, 0x5, 0x9a, 0x4e, 
    0x2, 0x341, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 0x7, 0x2f, 0x2, 
    0x2, 0x343, 0x344, 0x5, 0xb8, 0x5d, 0x2, 0x344, 0x348, 0x7, 0x4c, 0x2, 
    0x2, 0x345, 0x347, 0x5, 0xba, 0x5e, 0x2, 0x346, 0x345, 0x3, 0x2, 0x2, 
    0x2, 0x347, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x348, 0x346, 0x3, 0x2, 0x2, 
    0x2, 0x348, 0x349, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34d, 0x3, 0x2, 0x2, 
    0x2, 0x34a, 0x348, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34e, 0x5, 0xbc, 0x5f, 
    0x2, 0x34c, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34b, 0x3, 0x2, 0x2, 
    0x2, 0x34d, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34f, 0x3, 0x2, 0x2, 
    0x2, 0x34f, 0x350, 0x7, 0x4d, 0x2, 0x2, 0x350, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0x351, 0x352, 0x7, 0x4a, 0x2, 0x2, 0x352, 0x353, 0x5, 0x52, 0x2a, 
    0x2, 0x353, 0x354, 0x7, 0x4b, 0x2, 0x2, 0x354, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0x355, 0x356, 0x7, 0x30, 0x2, 0x2, 0x356, 0x357, 0x5, 0x72, 0x3a, 
    0x2, 0x357, 0x35f, 0x7, 0x52, 0x2, 0x2, 0x358, 0x360, 0x5, 0xa0, 0x51, 
    0x2, 0x359, 0x35b, 0x5, 0x9c, 0x4f, 0x2, 0x35a, 0x359, 0x3, 0x2, 0x2, 
    0x2, 0x35b, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35a, 0x3, 0x2, 0x2, 
    0x2, 0x35c, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x360, 0x3, 0x2, 0x2, 
    0x2, 0x35e, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x358, 0x3, 0x2, 0x2, 
    0x2, 0x35f, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x360, 0xbb, 0x3, 0x2, 0x2, 0x2, 
    0x361, 0x362, 0x7, 0x31, 0x2, 0x2, 0x362, 0x36a, 0x7, 0x52, 0x2, 0x2, 
    0x363, 0x36b, 0x5, 0xa0, 0x51, 0x2, 0x364, 0x366, 0x5, 0x9c, 0x4f, 0x2, 
    0x365, 0x364, 0x3, 0x2, 0x2, 0x2, 0x366, 0x369, 0x3, 0x2, 0x2, 0x2, 
    0x367, 0x365, 0x3, 0x2, 0x2, 0x2, 0x367, 0x368, 0x3, 0x2, 0x2, 0x2, 
    0x368, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x369, 0x367, 0x3, 0x2, 0x2, 0x2, 
    0x36a, 0x363, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x367, 0x3, 0x2, 0x2, 0x2, 
    0x36b, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x371, 0x5, 0x74, 0x3b, 0x2, 
    0x36d, 0x371, 0x5, 0x76, 0x3c, 0x2, 0x36e, 0x371, 0x5, 0x8a, 0x46, 0x2, 
    0x36f, 0x371, 0x5, 0x72, 0x3a, 0x2, 0x370, 0x36c, 0x3, 0x2, 0x2, 0x2, 
    0x370, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x370, 0x36e, 0x3, 0x2, 0x2, 0x2, 
    0x370, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x371, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0xd4, 0xd9, 0xe1, 0xe8, 0xef, 0xf9, 0x103, 0x107, 0x113, 0x11d, 0x121, 
    0x136, 0x14a, 0x15c, 0x162, 0x169, 0x16d, 0x173, 0x17b, 0x187, 0x18b, 
    0x18f, 0x19d, 0x1a1, 0x1b4, 0x1ba, 0x1d2, 0x1da, 0x1e3, 0x1e6, 0x1f0, 
    0x1f2, 0x1f9, 0x20c, 0x211, 0x21e, 0x227, 0x230, 0x239, 0x243, 0x24d, 
    0x254, 0x260, 0x268, 0x26e, 0x274, 0x281, 0x285, 0x289, 0x296, 0x2a0, 
    0x2ad, 0x2b4, 0x2c2, 0x2d1, 0x2d6, 0x2e0, 0x2e9, 0x300, 0x305, 0x315, 
    0x323, 0x328, 0x32a, 0x32e, 0x333, 0x339, 0x348, 0x34d, 0x35c, 0x35f, 
    0x367, 0x36a, 0x370, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

StateMachineParser::Initializer StateMachineParser::_init;
