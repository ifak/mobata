
// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/SutDecl.g4 by ANTLR 4.7.2


#include "SutDeclListener.h"

#include "SutDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

SutDeclParser::SutDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SutDeclParser::~SutDeclParser() {
  delete _interpreter;
}

std::string SutDeclParser::getGrammarFileName() const {
  return "SutDecl.g4";
}

const std::vector<std::string>& SutDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SutDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SutDeclContext ------------------------------------------------------------------

SutDeclParser::SutDeclContext::SutDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::SutDeclContext::SutID() {
  return getToken(SutDeclParser::SutID, 0);
}

tree::TerminalNode* SutDeclParser::SutDeclContext::LBRACE() {
  return getToken(SutDeclParser::LBRACE, 0);
}

SutDeclParser::SutBodyContext* SutDeclParser::SutDeclContext::sutBody() {
  return getRuleContext<SutDeclParser::SutBodyContext>(0);
}

tree::TerminalNode* SutDeclParser::SutDeclContext::RBRACE() {
  return getToken(SutDeclParser::RBRACE, 0);
}


size_t SutDeclParser::SutDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleSutDecl;
}

void SutDeclParser::SutDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSutDecl(this);
}

void SutDeclParser::SutDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSutDecl(this);
}

SutDeclParser::SutDeclContext* SutDeclParser::sutDecl() {
  SutDeclContext *_localctx = _tracker.createInstance<SutDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, SutDeclParser::RuleSutDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(SutDeclParser::SutID);
    setState(125);
    match(SutDeclParser::LBRACE);
    setState(126);
    sutBody();
    setState(127);
    match(SutDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SutBodyContext ------------------------------------------------------------------

SutDeclParser::SutBodyContext::SutBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::NameDeclContext* SutDeclParser::SutBodyContext::nameDecl() {
  return getRuleContext<SutDeclParser::NameDeclContext>(0);
}

SutDeclParser::SutBodyOptionalContext* SutDeclParser::SutBodyContext::sutBodyOptional() {
  return getRuleContext<SutDeclParser::SutBodyOptionalContext>(0);
}


size_t SutDeclParser::SutBodyContext::getRuleIndex() const {
  return SutDeclParser::RuleSutBody;
}

void SutDeclParser::SutBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSutBody(this);
}

void SutDeclParser::SutBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSutBody(this);
}

SutDeclParser::SutBodyContext* SutDeclParser::sutBody() {
  SutBodyContext *_localctx = _tracker.createInstance<SutBodyContext>(_ctx, getState());
  enterRule(_localctx, 2, SutDeclParser::RuleSutBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    nameDecl();
    setState(130);
    sutBodyOptional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SutBodyOptionalContext ------------------------------------------------------------------

SutDeclParser::SutBodyOptionalContext::SutBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::AttributeDeclContext* SutDeclParser::SutBodyOptionalContext::attributeDecl() {
  return getRuleContext<SutDeclParser::AttributeDeclContext>(0);
}

SutDeclParser::SutBodyOptionalContext* SutDeclParser::SutBodyOptionalContext::sutBodyOptional() {
  return getRuleContext<SutDeclParser::SutBodyOptionalContext>(0);
}

SutDeclParser::SutCompDeclContext* SutDeclParser::SutBodyOptionalContext::sutCompDecl() {
  return getRuleContext<SutDeclParser::SutCompDeclContext>(0);
}


size_t SutDeclParser::SutBodyOptionalContext::getRuleIndex() const {
  return SutDeclParser::RuleSutBodyOptional;
}

void SutDeclParser::SutBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSutBodyOptional(this);
}

void SutDeclParser::SutBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSutBodyOptional(this);
}

SutDeclParser::SutBodyOptionalContext* SutDeclParser::sutBodyOptional() {
  SutBodyOptionalContext *_localctx = _tracker.createInstance<SutBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 4, SutDeclParser::RuleSutBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(132);
        attributeDecl();
        setState(133);
        sutBodyOptional();
        break;
      }

      case SutDeclParser::SutComponentID: {
        enterOuterAlt(_localctx, 2);
        setState(135);
        sutCompDecl();
        setState(136);
        sutBodyOptional();
        break;
      }

      case SutDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 3);

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

//----------------- SutCompDeclContext ------------------------------------------------------------------

SutDeclParser::SutCompDeclContext::SutCompDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::SutCompDeclContext::SutComponentID() {
  return getToken(SutDeclParser::SutComponentID, 0);
}

tree::TerminalNode* SutDeclParser::SutCompDeclContext::LBRACE() {
  return getToken(SutDeclParser::LBRACE, 0);
}

SutDeclParser::SutCompBodyContext* SutDeclParser::SutCompDeclContext::sutCompBody() {
  return getRuleContext<SutDeclParser::SutCompBodyContext>(0);
}

tree::TerminalNode* SutDeclParser::SutCompDeclContext::RBRACE() {
  return getToken(SutDeclParser::RBRACE, 0);
}


size_t SutDeclParser::SutCompDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleSutCompDecl;
}

void SutDeclParser::SutCompDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSutCompDecl(this);
}

void SutDeclParser::SutCompDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSutCompDecl(this);
}

SutDeclParser::SutCompDeclContext* SutDeclParser::sutCompDecl() {
  SutCompDeclContext *_localctx = _tracker.createInstance<SutCompDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, SutDeclParser::RuleSutCompDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(SutDeclParser::SutComponentID);
    setState(142);
    match(SutDeclParser::LBRACE);
    setState(143);
    sutCompBody();
    setState(144);
    match(SutDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SutCompBodyContext ------------------------------------------------------------------

SutDeclParser::SutCompBodyContext::SutCompBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::NameDeclContext* SutDeclParser::SutCompBodyContext::nameDecl() {
  return getRuleContext<SutDeclParser::NameDeclContext>(0);
}

SutDeclParser::SutCompBodyOtionalContext* SutDeclParser::SutCompBodyContext::sutCompBodyOtional() {
  return getRuleContext<SutDeclParser::SutCompBodyOtionalContext>(0);
}


size_t SutDeclParser::SutCompBodyContext::getRuleIndex() const {
  return SutDeclParser::RuleSutCompBody;
}

void SutDeclParser::SutCompBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSutCompBody(this);
}

void SutDeclParser::SutCompBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSutCompBody(this);
}

SutDeclParser::SutCompBodyContext* SutDeclParser::sutCompBody() {
  SutCompBodyContext *_localctx = _tracker.createInstance<SutCompBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, SutDeclParser::RuleSutCompBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    nameDecl();
    setState(147);
    sutCompBodyOtional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SutCompBodyOtionalContext ------------------------------------------------------------------

SutDeclParser::SutCompBodyOtionalContext::SutCompBodyOtionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::AttributeDeclContext* SutDeclParser::SutCompBodyOtionalContext::attributeDecl() {
  return getRuleContext<SutDeclParser::AttributeDeclContext>(0);
}

SutDeclParser::SutCompBodyOtionalContext* SutDeclParser::SutCompBodyOtionalContext::sutCompBodyOtional() {
  return getRuleContext<SutDeclParser::SutCompBodyOtionalContext>(0);
}

SutDeclParser::PortDeclContext* SutDeclParser::SutCompBodyOtionalContext::portDecl() {
  return getRuleContext<SutDeclParser::PortDeclContext>(0);
}


size_t SutDeclParser::SutCompBodyOtionalContext::getRuleIndex() const {
  return SutDeclParser::RuleSutCompBodyOtional;
}

void SutDeclParser::SutCompBodyOtionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSutCompBodyOtional(this);
}

void SutDeclParser::SutCompBodyOtionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSutCompBodyOtional(this);
}

SutDeclParser::SutCompBodyOtionalContext* SutDeclParser::sutCompBodyOtional() {
  SutCompBodyOtionalContext *_localctx = _tracker.createInstance<SutCompBodyOtionalContext>(_ctx, getState());
  enterRule(_localctx, 10, SutDeclParser::RuleSutCompBodyOtional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        attributeDecl();
        setState(150);
        sutCompBodyOtional();
        break;
      }

      case SutDeclParser::PortID: {
        enterOuterAlt(_localctx, 2);
        setState(152);
        portDecl();
        setState(153);
        sutCompBodyOtional();
        break;
      }

      case SutDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 3);

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

//----------------- ContextIDContext ------------------------------------------------------------------

SutDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ContextIDContext::ID() {
  return getToken(SutDeclParser::ID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::NameID() {
  return getToken(SutDeclParser::NameID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::LabelID() {
  return getToken(SutDeclParser::LabelID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::EnabledID() {
  return getToken(SutDeclParser::EnabledID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::TypeID() {
  return getToken(SutDeclParser::TypeID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::MessageTrigger() {
  return getToken(SutDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::TriggerID() {
  return getToken(SutDeclParser::TriggerID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::AttributeID() {
  return getToken(SutDeclParser::AttributeID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::SignalID() {
  return getToken(SutDeclParser::SignalID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::PortID() {
  return getToken(SutDeclParser::PortID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::ImportID() {
  return getToken(SutDeclParser::ImportID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::FromID() {
  return getToken(SutDeclParser::FromID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::ToID() {
  return getToken(SutDeclParser::ToID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::SendID() {
  return getToken(SutDeclParser::SendID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::AsID() {
  return getToken(SutDeclParser::AsID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::SutComponentID() {
  return getToken(SutDeclParser::SutComponentID, 0);
}

tree::TerminalNode* SutDeclParser::ContextIDContext::SutID() {
  return getToken(SutDeclParser::SutID, 0);
}


size_t SutDeclParser::ContextIDContext::getRuleIndex() const {
  return SutDeclParser::RuleContextID;
}

void SutDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void SutDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

SutDeclParser::ContextIDContext* SutDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 12, SutDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(158);
        match(SutDeclParser::ID);
        break;
      }

      case SutDeclParser::NameID: {
        enterOuterAlt(_localctx, 2);
        setState(159);
        match(SutDeclParser::NameID);
        break;
      }

      case SutDeclParser::LabelID: {
        enterOuterAlt(_localctx, 3);
        setState(160);
        match(SutDeclParser::LabelID);
        break;
      }

      case SutDeclParser::EnabledID: {
        enterOuterAlt(_localctx, 4);
        setState(161);
        match(SutDeclParser::EnabledID);
        break;
      }

      case SutDeclParser::TypeID: {
        enterOuterAlt(_localctx, 5);
        setState(162);
        match(SutDeclParser::TypeID);
        break;
      }

      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger: {
        enterOuterAlt(_localctx, 6);
        setState(163);
        _la = _input->LA(1);
        if (!(_la == SutDeclParser::TriggerID

        || _la == SutDeclParser::MessageTrigger)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case SutDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 7);
        setState(164);
        match(SutDeclParser::AttributeID);
        break;
      }

      case SutDeclParser::SignalID: {
        enterOuterAlt(_localctx, 8);
        setState(165);
        match(SutDeclParser::SignalID);
        break;
      }

      case SutDeclParser::PortID: {
        enterOuterAlt(_localctx, 9);
        setState(166);
        match(SutDeclParser::PortID);
        break;
      }

      case SutDeclParser::ImportID: {
        enterOuterAlt(_localctx, 10);
        setState(167);
        match(SutDeclParser::ImportID);
        break;
      }

      case SutDeclParser::FromID: {
        enterOuterAlt(_localctx, 11);
        setState(168);
        match(SutDeclParser::FromID);
        break;
      }

      case SutDeclParser::ToID: {
        enterOuterAlt(_localctx, 12);
        setState(169);
        match(SutDeclParser::ToID);
        break;
      }

      case SutDeclParser::SendID: {
        enterOuterAlt(_localctx, 13);
        setState(170);
        match(SutDeclParser::SendID);
        break;
      }

      case SutDeclParser::AsID: {
        enterOuterAlt(_localctx, 14);
        setState(171);
        match(SutDeclParser::AsID);
        break;
      }

      case SutDeclParser::SutComponentID: {
        enterOuterAlt(_localctx, 15);
        setState(172);
        match(SutDeclParser::SutComponentID);
        break;
      }

      case SutDeclParser::SutID: {
        enterOuterAlt(_localctx, 16);
        setState(173);
        match(SutDeclParser::SutID);
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

//----------------- ComponentIdPathContext ------------------------------------------------------------------

SutDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SutDeclParser::ContextIDContext *> SutDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<SutDeclParser::ContextIDContext>();
}

SutDeclParser::ContextIDContext* SutDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<SutDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SutDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(SutDeclParser::DOT);
}

tree::TerminalNode* SutDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(SutDeclParser::DOT, i);
}


size_t SutDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return SutDeclParser::RuleComponentIdPath;
}

void SutDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void SutDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

SutDeclParser::ComponentIdPathContext* SutDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 14, SutDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    contextID();
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SutDeclParser::DOT) {
      setState(177);
      match(SutDeclParser::DOT);
      setState(178);
      contextID();
      setState(183);
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

SutDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SutDeclParser::ContextIDContext *> SutDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<SutDeclParser::ContextIDContext>();
}

SutDeclParser::ContextIDContext* SutDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<SutDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SutDeclParser::SignalIdPathContext::DOT() {
  return getTokens(SutDeclParser::DOT);
}

tree::TerminalNode* SutDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(SutDeclParser::DOT, i);
}


size_t SutDeclParser::SignalIdPathContext::getRuleIndex() const {
  return SutDeclParser::RuleSignalIdPath;
}

void SutDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void SutDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

SutDeclParser::SignalIdPathContext* SutDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 16, SutDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    contextID();
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SutDeclParser::DOT) {
      setState(185);
      match(SutDeclParser::DOT);
      setState(186);
      contextID();
      setState(191);
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

SutDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::AttributeNameContext* SutDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<SutDeclParser::AttributeNameContext>(0);
}

std::vector<SutDeclParser::ContextIDContext *> SutDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<SutDeclParser::ContextIDContext>();
}

SutDeclParser::ContextIDContext* SutDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<SutDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SutDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(SutDeclParser::DOT);
}

tree::TerminalNode* SutDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(SutDeclParser::DOT, i);
}


size_t SutDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return SutDeclParser::RuleAttributeIdPath;
}

void SutDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void SutDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

SutDeclParser::AttributeIdPathContext* SutDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 18, SutDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(193);
      contextID();
      setState(198);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SutDeclParser::DOT) {
        setState(194);
        match(SutDeclParser::DOT);
        setState(195);
        contextID();
        setState(200);
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

SutDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::SignalIdPathContext* SutDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<SutDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* SutDeclParser::SignalSendContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

SutDeclParser::FunctionCallBodyContext* SutDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<SutDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* SutDeclParser::SignalSendContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}


size_t SutDeclParser::SignalSendContext::getRuleIndex() const {
  return SutDeclParser::RuleSignalSend;
}

void SutDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void SutDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

SutDeclParser::SignalSendContext* SutDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 20, SutDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    signalIdPath();
    setState(204);
    match(SutDeclParser::LPAREN);
    setState(205);
    functionCallBody();
    setState(206);
    match(SutDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

SutDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SutDeclParser::TypeDefDeclContext *> SutDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<SutDeclParser::TypeDefDeclContext>();
}

SutDeclParser::TypeDefDeclContext* SutDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<SutDeclParser::TypeDefDeclContext>(i);
}

std::vector<SutDeclParser::AttributeDeclContext *> SutDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<SutDeclParser::AttributeDeclContext>();
}

SutDeclParser::AttributeDeclContext* SutDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<SutDeclParser::AttributeDeclContext>(i);
}

std::vector<SutDeclParser::SignalDeclContext *> SutDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<SutDeclParser::SignalDeclContext>();
}

SutDeclParser::SignalDeclContext* SutDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<SutDeclParser::SignalDeclContext>(i);
}


size_t SutDeclParser::CommonDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleCommonDecl;
}

void SutDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void SutDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

SutDeclParser::CommonDeclContext* SutDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, SutDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SutDeclParser::TypeID)
      | (1ULL << SutDeclParser::AttributeID)
      | (1ULL << SutDeclParser::SignalID))) != 0)) {
      setState(211);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SutDeclParser::TypeID: {
          setState(208);
          typeDefDecl();
          break;
        }

        case SutDeclParser::AttributeID: {
          setState(209);
          attributeDecl();
          break;
        }

        case SutDeclParser::SignalID: {
          setState(210);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(215);
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

SutDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::ImportPathBodyContext* SutDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<SutDeclParser::ImportPathBodyContext>(0);
}

SutDeclParser::ImportPathDeclContext* SutDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<SutDeclParser::ImportPathDeclContext>(0);
}


size_t SutDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleImportPathDecl;
}

void SutDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void SutDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

SutDeclParser::ImportPathDeclContext* SutDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, SutDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(216);
      importPathBody();
      setState(217);
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

SutDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(SutDeclParser::ImportID, 0);
}

tree::TerminalNode* SutDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(SutDeclParser::LESSTHAN, 0);
}

SutDeclParser::ImportFileBodyContext* SutDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<SutDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* SutDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(SutDeclParser::GREATERTHAN, 0);
}

SutDeclParser::ImportAsContext* SutDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<SutDeclParser::ImportAsContext>(0);
}


size_t SutDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return SutDeclParser::RuleImportPathBody;
}

void SutDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void SutDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

SutDeclParser::ImportPathBodyContext* SutDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, SutDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(SutDeclParser::ImportID);
    setState(223);
    match(SutDeclParser::LESSTHAN);
    setState(224);
    importFileBody();
    setState(225);
    match(SutDeclParser::GREATERTHAN);
    setState(226);
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

SutDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SutDeclParser::ContextIDContext *> SutDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<SutDeclParser::ContextIDContext>();
}

SutDeclParser::ContextIDContext* SutDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<SutDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* SutDeclParser::ImportFileBodyContext::DOT() {
  return getToken(SutDeclParser::DOT, 0);
}

tree::TerminalNode* SutDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(SutDeclParser::RANGE, 0);
}

tree::TerminalNode* SutDeclParser::ImportFileBodyContext::DIV() {
  return getToken(SutDeclParser::DIV, 0);
}

SutDeclParser::ImportFileBodyContext* SutDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<SutDeclParser::ImportFileBodyContext>(0);
}


size_t SutDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return SutDeclParser::RuleImportFileBody;
}

void SutDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void SutDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

SutDeclParser::ImportFileBodyContext* SutDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 28, SutDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      contextID();
      setState(229);
      match(SutDeclParser::DOT);
      setState(230);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      match(SutDeclParser::RANGE);
      setState(233);
      match(SutDeclParser::DIV);
      setState(234);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(235);
      contextID();
      setState(236);
      match(SutDeclParser::DIV);
      setState(237);
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

SutDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ImportAsContext::AsID() {
  return getToken(SutDeclParser::AsID, 0);
}

SutDeclParser::ContextIDContext* SutDeclParser::ImportAsContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}


size_t SutDeclParser::ImportAsContext::getRuleIndex() const {
  return SutDeclParser::RuleImportAs;
}

void SutDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void SutDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

SutDeclParser::ImportAsContext* SutDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 30, SutDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(241);
        match(SutDeclParser::AsID);
        setState(242);
        contextID();
        break;
      }

      case SutDeclParser::ImportID: {
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

SutDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(SutDeclParser::TypeID, 0);
}

SutDeclParser::TypeDeclContext* SutDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<SutDeclParser::TypeDeclContext>(0);
}

SutDeclParser::ContextIDContext* SutDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SutDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}


size_t SutDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleTypeDefDecl;
}

void SutDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void SutDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

SutDeclParser::TypeDefDeclContext* SutDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 32, SutDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(SutDeclParser::TypeID);
    setState(247);
    typeDecl();
    setState(248);
    contextID();
    setState(249);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

SutDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::IntTypeDeclContext* SutDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<SutDeclParser::IntTypeDeclContext>(0);
}

SutDeclParser::RealTypeDeclContext* SutDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<SutDeclParser::RealTypeDeclContext>(0);
}

SutDeclParser::EnumTypeDeclContext* SutDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<SutDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* SutDeclParser::TypeDeclContext::BoolID() {
  return getToken(SutDeclParser::BoolID, 0);
}

tree::TerminalNode* SutDeclParser::TypeDeclContext::StringID() {
  return getToken(SutDeclParser::StringID, 0);
}

SutDeclParser::ContextIDContext* SutDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}


size_t SutDeclParser::TypeDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleTypeDecl;
}

void SutDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void SutDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

SutDeclParser::TypeDeclContext* SutDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 34, SutDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(251);
        intTypeDecl();
        break;
      }

      case SutDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(252);
        realTypeDecl();
        break;
      }

      case SutDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(253);
        enumTypeDecl();
        break;
      }

      case SutDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(254);
        match(SutDeclParser::BoolID);
        break;
      }

      case SutDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(255);
        match(SutDeclParser::StringID);
        break;
      }

      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::AsID:
      case SutDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(256);
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

SutDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::IntTypeDeclContext::IntID() {
  return getToken(SutDeclParser::IntID, 0);
}

tree::TerminalNode* SutDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> SutDeclParser::IntTypeDeclContext::INT() {
  return getTokens(SutDeclParser::INT);
}

tree::TerminalNode* SutDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(SutDeclParser::INT, i);
}

tree::TerminalNode* SutDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(SutDeclParser::RANGE, 0);
}

tree::TerminalNode* SutDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}


size_t SutDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleIntTypeDecl;
}

void SutDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void SutDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

SutDeclParser::IntTypeDeclContext* SutDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, SutDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(SutDeclParser::IntID);
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::LPAREN: {
        setState(260);
        match(SutDeclParser::LPAREN);
        setState(261);
        match(SutDeclParser::INT);
        setState(262);
        match(SutDeclParser::RANGE);
        setState(263);
        match(SutDeclParser::INT);
        setState(264);
        match(SutDeclParser::RPAREN);
        break;
      }

      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::AsID:
      case SutDeclParser::ID: {
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

SutDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::RealTypeDeclContext::RealID() {
  return getToken(SutDeclParser::RealID, 0);
}

tree::TerminalNode* SutDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> SutDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(SutDeclParser::REAL);
}

tree::TerminalNode* SutDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(SutDeclParser::REAL, i);
}

tree::TerminalNode* SutDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(SutDeclParser::RANGE, 0);
}

tree::TerminalNode* SutDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}


size_t SutDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleRealTypeDecl;
}

void SutDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void SutDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

SutDeclParser::RealTypeDeclContext* SutDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 38, SutDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(SutDeclParser::RealID);
    setState(275);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::LPAREN: {
        setState(269);
        match(SutDeclParser::LPAREN);
        setState(270);
        match(SutDeclParser::REAL);
        setState(271);
        match(SutDeclParser::RANGE);
        setState(272);
        match(SutDeclParser::REAL);
        setState(273);
        match(SutDeclParser::RPAREN);
        break;
      }

      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::AsID:
      case SutDeclParser::ID: {
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

SutDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(SutDeclParser::EnumID, 0);
}

tree::TerminalNode* SutDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

std::vector<SutDeclParser::ContextIDContext *> SutDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<SutDeclParser::ContextIDContext>();
}

SutDeclParser::ContextIDContext* SutDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<SutDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* SutDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> SutDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(SutDeclParser::COMMA);
}

tree::TerminalNode* SutDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(SutDeclParser::COMMA, i);
}


size_t SutDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleEnumTypeDecl;
}

void SutDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void SutDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

SutDeclParser::EnumTypeDeclContext* SutDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 40, SutDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(SutDeclParser::EnumID);
    setState(278);
    match(SutDeclParser::LPAREN);
    setState(279);
    contextID();
    setState(284);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SutDeclParser::COMMA) {
      setState(280);
      match(SutDeclParser::COMMA);
      setState(281);
      contextID();
      setState(286);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(287);
    match(SutDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

SutDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(SutDeclParser::AttributeID, 0);
}

SutDeclParser::TypeDeclContext* SutDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<SutDeclParser::TypeDeclContext>(0);
}

SutDeclParser::ContextIDContext* SutDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SutDeclParser::AttributeDeclContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}

tree::TerminalNode* SutDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(SutDeclParser::ASSIGN, 0);
}

SutDeclParser::LiteralValueContext* SutDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<SutDeclParser::LiteralValueContext>(0);
}


size_t SutDeclParser::AttributeDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleAttributeDecl;
}

void SutDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void SutDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

SutDeclParser::AttributeDeclContext* SutDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 42, SutDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(SutDeclParser::AttributeID);
    setState(290);
    typeDecl();
    setState(291);
    contextID();
    setState(294);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SutDeclParser::ASSIGN) {
      setState(292);
      match(SutDeclParser::ASSIGN);
      setState(293);
      literalValue();
    }
    setState(296);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

SutDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::LiteralValueContext::INT() {
  return getToken(SutDeclParser::INT, 0);
}

tree::TerminalNode* SutDeclParser::LiteralValueContext::REAL() {
  return getToken(SutDeclParser::REAL, 0);
}

tree::TerminalNode* SutDeclParser::LiteralValueContext::STRING() {
  return getToken(SutDeclParser::STRING, 0);
}

tree::TerminalNode* SutDeclParser::LiteralValueContext::TrueID() {
  return getToken(SutDeclParser::TrueID, 0);
}

tree::TerminalNode* SutDeclParser::LiteralValueContext::FalseID() {
  return getToken(SutDeclParser::FalseID, 0);
}

SutDeclParser::ContextIDContext* SutDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}


size_t SutDeclParser::LiteralValueContext::getRuleIndex() const {
  return SutDeclParser::RuleLiteralValue;
}

void SutDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void SutDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

SutDeclParser::LiteralValueContext* SutDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 44, SutDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(298);
        match(SutDeclParser::INT);
        break;
      }

      case SutDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(299);
        match(SutDeclParser::REAL);
        break;
      }

      case SutDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(300);
        match(SutDeclParser::STRING);
        break;
      }

      case SutDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(301);
        match(SutDeclParser::TrueID);
        break;
      }

      case SutDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(302);
        match(SutDeclParser::FalseID);
        break;
      }

      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::AsID:
      case SutDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(303);
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

SutDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::TriggerDeclContext* SutDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<SutDeclParser::TriggerDeclContext>(0);
}

SutDeclParser::ContextIDContext* SutDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}


size_t SutDeclParser::SignalParamNameContext::getRuleIndex() const {
  return SutDeclParser::RuleSignalParamName;
}

void SutDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void SutDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

SutDeclParser::SignalParamNameContext* SutDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 46, SutDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    triggerDecl();
    setState(307);
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

SutDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::ContextIDContext* SutDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}

SutDeclParser::ThisDeclContext* SutDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<SutDeclParser::ThisDeclContext>(0);
}


size_t SutDeclParser::AttributeNameContext::getRuleIndex() const {
  return SutDeclParser::RuleAttributeName;
}

void SutDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void SutDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

SutDeclParser::AttributeNameContext* SutDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 48, SutDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::ThisID: {
        setState(309);
        thisDecl();
        break;
      }

      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::AsID:
      case SutDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(313);
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

SutDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ToPortNameContext::ToID() {
  return getToken(SutDeclParser::ToID, 0);
}

SutDeclParser::ContextIDContext* SutDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}


size_t SutDeclParser::ToPortNameContext::getRuleIndex() const {
  return SutDeclParser::RuleToPortName;
}

void SutDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void SutDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

SutDeclParser::ToPortNameContext* SutDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 50, SutDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(SutDeclParser::ToID);
    setState(316);
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

SutDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::AttributeNameContext* SutDeclParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<SutDeclParser::AttributeNameContext>(0);
}

tree::TerminalNode* SutDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(SutDeclParser::ASSIGN, 0);
}

SutDeclParser::ExpressionContext* SutDeclParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<SutDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SutDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}


size_t SutDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleAttributeAssignStatement;
}

void SutDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void SutDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

SutDeclParser::AttributeAssignStatementContext* SutDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, SutDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    attributeName();
    setState(319);
    match(SutDeclParser::ASSIGN);
    setState(320);
    expression();
    setState(321);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

SutDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::TypeDeclContext* SutDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<SutDeclParser::TypeDeclContext>(0);
}

SutDeclParser::ContextIDContext* SutDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SutDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}

tree::TerminalNode* SutDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(SutDeclParser::ASSIGN, 0);
}

SutDeclParser::ExpressionContext* SutDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<SutDeclParser::ExpressionContext>(0);
}


size_t SutDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleLocalAssignStatement;
}

void SutDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void SutDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

SutDeclParser::LocalAssignStatementContext* SutDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, SutDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    typeDecl();
    setState(324);
    contextID();
    setState(328);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::ASSIGN: {
        setState(325);
        match(SutDeclParser::ASSIGN);
        setState(326);
        expression();
        break;
      }

      case SutDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(330);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

SutDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::SendToStatementContext::SendID() {
  return getToken(SutDeclParser::SendID, 0);
}

SutDeclParser::SignalSendContext* SutDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<SutDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* SutDeclParser::SendToStatementContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}

SutDeclParser::ToPortNameContext* SutDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<SutDeclParser::ToPortNameContext>(0);
}


size_t SutDeclParser::SendToStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleSendToStatement;
}

void SutDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void SutDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

SutDeclParser::SendToStatementContext* SutDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, SutDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(SutDeclParser::SendID);
    setState(333);
    signalSend();
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::ToID: {
        setState(334);
        toPortName();
        break;
      }

      case SutDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(338);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

SutDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::AttributeAssignStatementContext* SutDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<SutDeclParser::AttributeAssignStatementContext>(0);
}

SutDeclParser::SendToStatementContext* SutDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<SutDeclParser::SendToStatementContext>(0);
}


size_t SutDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return SutDeclParser::RuleSingleAssignment;
}

void SutDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void SutDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

SutDeclParser::SingleAssignmentContext* SutDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 58, SutDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(342);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(340);
      attributeAssignStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(341);
      sendToStatement();
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

//----------------- MultiAssignmentContext ------------------------------------------------------------------

SutDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(SutDeclParser::LBRACE, 0);
}

tree::TerminalNode* SutDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(SutDeclParser::RBRACE, 0);
}

std::vector<SutDeclParser::SingleAssignmentContext *> SutDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<SutDeclParser::SingleAssignmentContext>();
}

SutDeclParser::SingleAssignmentContext* SutDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<SutDeclParser::SingleAssignmentContext>(i);
}


size_t SutDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return SutDeclParser::RuleMultiAssignment;
}

void SutDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void SutDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

SutDeclParser::MultiAssignmentContext* SutDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 60, SutDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(SutDeclParser::LBRACE);
    setState(348);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SutDeclParser::SutComponentID)
      | (1ULL << SutDeclParser::SutID)
      | (1ULL << SutDeclParser::NameID)
      | (1ULL << SutDeclParser::LabelID)
      | (1ULL << SutDeclParser::EnabledID)
      | (1ULL << SutDeclParser::TypeID)
      | (1ULL << SutDeclParser::TriggerID)
      | (1ULL << SutDeclParser::MessageTrigger)
      | (1ULL << SutDeclParser::ThisID)
      | (1ULL << SutDeclParser::AttributeID)
      | (1ULL << SutDeclParser::SignalID)
      | (1ULL << SutDeclParser::PortID)
      | (1ULL << SutDeclParser::ImportID)
      | (1ULL << SutDeclParser::FromID)
      | (1ULL << SutDeclParser::ToID)
      | (1ULL << SutDeclParser::SendID)
      | (1ULL << SutDeclParser::AsID)
      | (1ULL << SutDeclParser::ID))) != 0)) {
      setState(345);
      singleAssignment();
      setState(350);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(351);
    match(SutDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

SutDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::SignalDeclContext::SignalID() {
  return getToken(SutDeclParser::SignalID, 0);
}

SutDeclParser::ContextIDContext* SutDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SutDeclParser::SignalDeclContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}

tree::TerminalNode* SutDeclParser::SignalDeclContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

tree::TerminalNode* SutDeclParser::SignalDeclContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}

std::vector<SutDeclParser::ParamDeclContext *> SutDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<SutDeclParser::ParamDeclContext>();
}

SutDeclParser::ParamDeclContext* SutDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<SutDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> SutDeclParser::SignalDeclContext::COMMA() {
  return getTokens(SutDeclParser::COMMA);
}

tree::TerminalNode* SutDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(SutDeclParser::COMMA, i);
}


size_t SutDeclParser::SignalDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleSignalDecl;
}

void SutDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void SutDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

SutDeclParser::SignalDeclContext* SutDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 62, SutDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(SutDeclParser::SignalID);
    setState(354);
    contextID();
    setState(369);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::LPAREN: {
        setState(355);
        match(SutDeclParser::LPAREN);
        setState(365);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SutDeclParser::SutComponentID:
          case SutDeclParser::SutID:
          case SutDeclParser::NameID:
          case SutDeclParser::LabelID:
          case SutDeclParser::EnabledID:
          case SutDeclParser::TypeID:
          case SutDeclParser::IntID:
          case SutDeclParser::RealID:
          case SutDeclParser::BoolID:
          case SutDeclParser::StringID:
          case SutDeclParser::TriggerID:
          case SutDeclParser::MessageTrigger:
          case SutDeclParser::EnumID:
          case SutDeclParser::AttributeID:
          case SutDeclParser::SignalID:
          case SutDeclParser::PortID:
          case SutDeclParser::ImportID:
          case SutDeclParser::FromID:
          case SutDeclParser::ToID:
          case SutDeclParser::SendID:
          case SutDeclParser::AsID:
          case SutDeclParser::ID: {
            setState(356);
            paramDecl();
            setState(361);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == SutDeclParser::COMMA) {
              setState(357);
              match(SutDeclParser::COMMA);
              setState(358);
              paramDecl();
              setState(363);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case SutDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(367);
        match(SutDeclParser::RPAREN);
        break;
      }

      case SutDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(371);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

SutDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::TypeDeclContext* SutDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<SutDeclParser::TypeDeclContext>(0);
}

SutDeclParser::ContextIDContext* SutDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}


size_t SutDeclParser::ParamDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleParamDecl;
}

void SutDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void SutDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

SutDeclParser::ParamDeclContext* SutDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 64, SutDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    typeDecl();
    setState(374);
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

SutDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(SutDeclParser::FunctionID, 0);
}

SutDeclParser::TypeDeclContext* SutDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<SutDeclParser::TypeDeclContext>(0);
}

SutDeclParser::IdPathContext* SutDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<SutDeclParser::IdPathContext>(0);
}

tree::TerminalNode* SutDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

tree::TerminalNode* SutDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}

SutDeclParser::NestedStatementBodyContext* SutDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<SutDeclParser::NestedStatementBodyContext>(0);
}

SutDeclParser::FunctionParametersContext* SutDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<SutDeclParser::FunctionParametersContext>(0);
}


size_t SutDeclParser::FunctionDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleFunctionDecl;
}

void SutDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void SutDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

SutDeclParser::FunctionDeclContext* SutDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, SutDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    match(SutDeclParser::FunctionID);
    setState(377);
    typeDecl();
    setState(378);
    idPath();
    setState(379);
    match(SutDeclParser::LPAREN);
    setState(382);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::IntID:
      case SutDeclParser::RealID:
      case SutDeclParser::BoolID:
      case SutDeclParser::StringID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::EnumID:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::AsID:
      case SutDeclParser::ID: {
        setState(380);
        functionParameters();
        break;
      }

      case SutDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(384);
    match(SutDeclParser::RPAREN);
    setState(385);
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

SutDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SutDeclParser::ParamDeclContext *> SutDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<SutDeclParser::ParamDeclContext>();
}

SutDeclParser::ParamDeclContext* SutDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<SutDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> SutDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(SutDeclParser::COMMA);
}

tree::TerminalNode* SutDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(SutDeclParser::COMMA, i);
}


size_t SutDeclParser::FunctionParametersContext::getRuleIndex() const {
  return SutDeclParser::RuleFunctionParameters;
}

void SutDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void SutDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

SutDeclParser::FunctionParametersContext* SutDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 68, SutDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    paramDecl();
    setState(392);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SutDeclParser::COMMA) {
      setState(388);
      match(SutDeclParser::COMMA);
      setState(389);
      paramDecl();
      setState(394);
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

SutDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::IdPathContext* SutDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<SutDeclParser::IdPathContext>(0);
}

tree::TerminalNode* SutDeclParser::FunctionCallContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

SutDeclParser::FunctionCallBodyContext* SutDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<SutDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* SutDeclParser::FunctionCallContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}


size_t SutDeclParser::FunctionCallContext::getRuleIndex() const {
  return SutDeclParser::RuleFunctionCall;
}

void SutDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void SutDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

SutDeclParser::FunctionCallContext* SutDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 70, SutDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    idPath();
    setState(396);
    match(SutDeclParser::LPAREN);
    setState(397);
    functionCallBody();
    setState(398);
    match(SutDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

SutDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::FunctionCallBodyOptionalContext* SutDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<SutDeclParser::FunctionCallBodyOptionalContext>(0);
}

SutDeclParser::LiteralValueContext* SutDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<SutDeclParser::LiteralValueContext>(0);
}

SutDeclParser::SignalParamNameContext* SutDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<SutDeclParser::SignalParamNameContext>(0);
}

SutDeclParser::AttributeNameContext* SutDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<SutDeclParser::AttributeNameContext>(0);
}

SutDeclParser::FunctionCallContext* SutDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<SutDeclParser::FunctionCallContext>(0);
}


size_t SutDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return SutDeclParser::RuleFunctionCallBody;
}

void SutDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void SutDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

SutDeclParser::FunctionCallBodyContext* SutDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 72, SutDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(400);
      literalValue();
      break;
    }

    case 2: {
      setState(401);
      signalParamName();
      break;
    }

    case 3: {
      setState(402);
      attributeName();
      break;
    }

    case 4: {
      setState(403);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(407);
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

SutDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(SutDeclParser::COMMA, 0);
}

SutDeclParser::FunctionCallBodyContext* SutDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<SutDeclParser::FunctionCallBodyContext>(0);
}


size_t SutDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return SutDeclParser::RuleFunctionCallBodyOptional;
}

void SutDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void SutDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

SutDeclParser::FunctionCallBodyOptionalContext* SutDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 74, SutDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(412);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(409);
        match(SutDeclParser::COMMA);
        setState(410);
        functionCallBody();
        break;
      }

      case SutDeclParser::RPAREN: {
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

SutDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::TriggerDeclContext::DOT() {
  return getToken(SutDeclParser::DOT, 0);
}

tree::TerminalNode* SutDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(SutDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* SutDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(SutDeclParser::TriggerID, 0);
}


size_t SutDeclParser::TriggerDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleTriggerDecl;
}

void SutDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void SutDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

SutDeclParser::TriggerDeclContext* SutDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 76, SutDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    _la = _input->LA(1);
    if (!(_la == SutDeclParser::TriggerID

    || _la == SutDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(415);
    match(SutDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

SutDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ThisDeclContext::ThisID() {
  return getToken(SutDeclParser::ThisID, 0);
}

tree::TerminalNode* SutDeclParser::ThisDeclContext::DOT() {
  return getToken(SutDeclParser::DOT, 0);
}


size_t SutDeclParser::ThisDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleThisDecl;
}

void SutDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void SutDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

SutDeclParser::ThisDeclContext* SutDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 78, SutDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(417);
    match(SutDeclParser::ThisID);
    setState(418);
    match(SutDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

SutDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::PortDeclContext::PortID() {
  return getToken(SutDeclParser::PortID, 0);
}

std::vector<SutDeclParser::ContextIDContext *> SutDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<SutDeclParser::ContextIDContext>();
}

SutDeclParser::ContextIDContext* SutDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<SutDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* SutDeclParser::PortDeclContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> SutDeclParser::PortDeclContext::COMMA() {
  return getTokens(SutDeclParser::COMMA);
}

tree::TerminalNode* SutDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(SutDeclParser::COMMA, i);
}


size_t SutDeclParser::PortDeclContext::getRuleIndex() const {
  return SutDeclParser::RulePortDecl;
}

void SutDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void SutDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

SutDeclParser::PortDeclContext* SutDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 80, SutDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    match(SutDeclParser::PortID);
    setState(421);
    contextID();
    setState(426);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SutDeclParser::COMMA) {
      setState(422);
      match(SutDeclParser::COMMA);
      setState(423);
      contextID();
      setState(428);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(429);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

SutDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::NameDeclContext::NameID() {
  return getToken(SutDeclParser::NameID, 0);
}

tree::TerminalNode* SutDeclParser::NameDeclContext::COLON() {
  return getToken(SutDeclParser::COLON, 0);
}

SutDeclParser::ContextIDContext* SutDeclParser::NameDeclContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SutDeclParser::NameDeclContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}


size_t SutDeclParser::NameDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleNameDecl;
}

void SutDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void SutDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

SutDeclParser::NameDeclContext* SutDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 82, SutDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    match(SutDeclParser::NameID);
    setState(432);
    match(SutDeclParser::COLON);
    setState(433);
    contextID();
    setState(434);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

SutDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SutDeclParser::ContextIDContext *> SutDeclParser::IdPathContext::contextID() {
  return getRuleContexts<SutDeclParser::ContextIDContext>();
}

SutDeclParser::ContextIDContext* SutDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<SutDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SutDeclParser::IdPathContext::DOT() {
  return getTokens(SutDeclParser::DOT);
}

tree::TerminalNode* SutDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(SutDeclParser::DOT, i);
}


size_t SutDeclParser::IdPathContext::getRuleIndex() const {
  return SutDeclParser::RuleIdPath;
}

void SutDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void SutDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

SutDeclParser::IdPathContext* SutDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 84, SutDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    contextID();
    setState(441);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SutDeclParser::DOT) {
      setState(437);
      match(SutDeclParser::DOT);
      setState(438);
      contextID();
      setState(443);
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

SutDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::StatementBodyContext* SutDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<SutDeclParser::StatementBodyContext>(0);
}

SutDeclParser::NestedStatementBodyContext* SutDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<SutDeclParser::NestedStatementBodyContext>(0);
}


size_t SutDeclParser::StatementDeclContext::getRuleIndex() const {
  return SutDeclParser::RuleStatementDecl;
}

void SutDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void SutDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

SutDeclParser::StatementDeclContext* SutDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 86, SutDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(446);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::IntID:
      case SutDeclParser::RealID:
      case SutDeclParser::BoolID:
      case SutDeclParser::StringID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::ThisID:
      case SutDeclParser::ReturnID:
      case SutDeclParser::EnumID:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::SwitchID:
      case SutDeclParser::IfID:
      case SutDeclParser::AsID:
      case SutDeclParser::BREAK:
      case SutDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(444);
        statementBody();
        break;
      }

      case SutDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(445);
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

SutDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::FunctionCallStatementContext* SutDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<SutDeclParser::FunctionCallStatementContext>(0);
}

SutDeclParser::AttributeAssignStatementContext* SutDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<SutDeclParser::AttributeAssignStatementContext>(0);
}

SutDeclParser::SwitchStatementContext* SutDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<SutDeclParser::SwitchStatementContext>(0);
}

SutDeclParser::ConditionalStatementContext* SutDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<SutDeclParser::ConditionalStatementContext>(0);
}

SutDeclParser::LocalAssignStatementContext* SutDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<SutDeclParser::LocalAssignStatementContext>(0);
}

SutDeclParser::SendToStatementContext* SutDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<SutDeclParser::SendToStatementContext>(0);
}

SutDeclParser::BreakStatementContext* SutDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<SutDeclParser::BreakStatementContext>(0);
}

SutDeclParser::ReturnStatementContext* SutDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<SutDeclParser::ReturnStatementContext>(0);
}


size_t SutDeclParser::StatementBodyContext::getRuleIndex() const {
  return SutDeclParser::RuleStatementBody;
}

void SutDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void SutDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

SutDeclParser::StatementBodyContext* SutDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 88, SutDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(456);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(448);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(449);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(450);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(451);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(452);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(453);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(454);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(455);
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

SutDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::FunctionCallContext* SutDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<SutDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* SutDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}


size_t SutDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleFunctionCallStatement;
}

void SutDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void SutDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

SutDeclParser::FunctionCallStatementContext* SutDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 90, SutDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    functionCall();
    setState(459);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

SutDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(SutDeclParser::LBRACE, 0);
}

tree::TerminalNode* SutDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(SutDeclParser::RBRACE, 0);
}

std::vector<SutDeclParser::StatementBodyContext *> SutDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<SutDeclParser::StatementBodyContext>();
}

SutDeclParser::StatementBodyContext* SutDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<SutDeclParser::StatementBodyContext>(i);
}


size_t SutDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return SutDeclParser::RuleNestedStatementBody;
}

void SutDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void SutDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

SutDeclParser::NestedStatementBodyContext* SutDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 92, SutDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(461);
    match(SutDeclParser::LBRACE);
    setState(465);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SutDeclParser::SutComponentID)
      | (1ULL << SutDeclParser::SutID)
      | (1ULL << SutDeclParser::NameID)
      | (1ULL << SutDeclParser::LabelID)
      | (1ULL << SutDeclParser::EnabledID)
      | (1ULL << SutDeclParser::TypeID)
      | (1ULL << SutDeclParser::IntID)
      | (1ULL << SutDeclParser::RealID)
      | (1ULL << SutDeclParser::BoolID)
      | (1ULL << SutDeclParser::StringID)
      | (1ULL << SutDeclParser::TriggerID)
      | (1ULL << SutDeclParser::MessageTrigger)
      | (1ULL << SutDeclParser::ThisID)
      | (1ULL << SutDeclParser::ReturnID)
      | (1ULL << SutDeclParser::EnumID)
      | (1ULL << SutDeclParser::AttributeID)
      | (1ULL << SutDeclParser::SignalID)
      | (1ULL << SutDeclParser::PortID)
      | (1ULL << SutDeclParser::ImportID)
      | (1ULL << SutDeclParser::FromID)
      | (1ULL << SutDeclParser::ToID)
      | (1ULL << SutDeclParser::SendID)
      | (1ULL << SutDeclParser::SwitchID)
      | (1ULL << SutDeclParser::IfID)
      | (1ULL << SutDeclParser::AsID)
      | (1ULL << SutDeclParser::BREAK)
      | (1ULL << SutDeclParser::ID))) != 0)) {
      setState(462);
      statementBody();
      setState(467);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(468);
    match(SutDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

SutDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(SutDeclParser::ReturnID, 0);
}

SutDeclParser::OperationContext* SutDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<SutDeclParser::OperationContext>(0);
}

tree::TerminalNode* SutDeclParser::ReturnStatementContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}


size_t SutDeclParser::ReturnStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleReturnStatement;
}

void SutDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void SutDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

SutDeclParser::ReturnStatementContext* SutDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, SutDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(470);
    match(SutDeclParser::ReturnID);
    setState(471);
    operation();
    setState(472);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

SutDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::BreakStatementContext::BREAK() {
  return getToken(SutDeclParser::BREAK, 0);
}

tree::TerminalNode* SutDeclParser::BreakStatementContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}


size_t SutDeclParser::BreakStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleBreakStatement;
}

void SutDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void SutDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

SutDeclParser::BreakStatementContext* SutDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, SutDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(474);
    match(SutDeclParser::BREAK);
    setState(475);
    match(SutDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

SutDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::AtomContext* SutDeclParser::OperationContext::atom() {
  return getRuleContext<SutDeclParser::AtomContext>(0);
}

SutDeclParser::OperationOptionalContext* SutDeclParser::OperationContext::operationOptional() {
  return getRuleContext<SutDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* SutDeclParser::OperationContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

SutDeclParser::OperationContext* SutDeclParser::OperationContext::operation() {
  return getRuleContext<SutDeclParser::OperationContext>(0);
}

tree::TerminalNode* SutDeclParser::OperationContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}

tree::TerminalNode* SutDeclParser::OperationContext::MINUS() {
  return getToken(SutDeclParser::MINUS, 0);
}

tree::TerminalNode* SutDeclParser::OperationContext::NotIdSymbol() {
  return getToken(SutDeclParser::NotIdSymbol, 0);
}


size_t SutDeclParser::OperationContext::getRuleIndex() const {
  return SutDeclParser::RuleOperation;
}

void SutDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void SutDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

SutDeclParser::OperationContext* SutDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 98, SutDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(488);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::ThisID:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::AsID:
      case SutDeclParser::TrueID:
      case SutDeclParser::FalseID:
      case SutDeclParser::INT:
      case SutDeclParser::REAL:
      case SutDeclParser::STRING:
      case SutDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(477);
        atom();
        setState(478);
        operationOptional();
        break;
      }

      case SutDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(480);
        match(SutDeclParser::LPAREN);
        setState(481);
        operation();
        setState(482);
        match(SutDeclParser::RPAREN);
        break;
      }

      case SutDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(484);
        match(SutDeclParser::MINUS);
        setState(485);
        operation();
        break;
      }

      case SutDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(486);
        match(SutDeclParser::NotIdSymbol);
        setState(487);
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

SutDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::OperationContext* SutDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<SutDeclParser::OperationContext>(0);
}

tree::TerminalNode* SutDeclParser::OperationOptionalContext::MULT() {
  return getToken(SutDeclParser::MULT, 0);
}

tree::TerminalNode* SutDeclParser::OperationOptionalContext::DIV() {
  return getToken(SutDeclParser::DIV, 0);
}

tree::TerminalNode* SutDeclParser::OperationOptionalContext::PLUS() {
  return getToken(SutDeclParser::PLUS, 0);
}

tree::TerminalNode* SutDeclParser::OperationOptionalContext::MINUS() {
  return getToken(SutDeclParser::MINUS, 0);
}


size_t SutDeclParser::OperationOptionalContext::getRuleIndex() const {
  return SutDeclParser::RuleOperationOptional;
}

void SutDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void SutDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

SutDeclParser::OperationOptionalContext* SutDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 100, SutDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(493);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::PLUS:
      case SutDeclParser::MINUS:
      case SutDeclParser::MULT:
      case SutDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(490);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 69) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 69)) & ((1ULL << (SutDeclParser::PLUS - 69))
          | (1ULL << (SutDeclParser::MINUS - 69))
          | (1ULL << (SutDeclParser::MULT - 69))
          | (1ULL << (SutDeclParser::DIV - 69)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(491);
        operation();
        break;
      }

      case SutDeclParser::NotIdSymbol:
      case SutDeclParser::AndIdSymbol:
      case SutDeclParser::OrIdSymbol:
      case SutDeclParser::NotIdWord:
      case SutDeclParser::AndIdWord:
      case SutDeclParser::OrIdWord:
      case SutDeclParser::ASSIGN:
      case SutDeclParser::RPAREN:
      case SutDeclParser::LESSTHAN:
      case SutDeclParser::GREATERTHAN:
      case SutDeclParser::SEMI: {
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

SutDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ExpressionContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

SutDeclParser::ExpressionContext* SutDeclParser::ExpressionContext::expression() {
  return getRuleContext<SutDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SutDeclParser::ExpressionContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}

SutDeclParser::ExpressionOptionalContext* SutDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<SutDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* SutDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(SutDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionContext::NotIdWord() {
  return getToken(SutDeclParser::NotIdWord, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionContext::MINUS() {
  return getToken(SutDeclParser::MINUS, 0);
}

SutDeclParser::OperationContext* SutDeclParser::ExpressionContext::operation() {
  return getRuleContext<SutDeclParser::OperationContext>(0);
}


size_t SutDeclParser::ExpressionContext::getRuleIndex() const {
  return SutDeclParser::RuleExpression;
}

void SutDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SutDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

SutDeclParser::ExpressionContext* SutDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 102, SutDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(509);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(495);
      match(SutDeclParser::LPAREN);
      setState(496);
      expression();
      setState(497);
      match(SutDeclParser::RPAREN);
      setState(498);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(500);
      match(SutDeclParser::NotIdSymbol);
      setState(501);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(502);
      match(SutDeclParser::NotIdWord);
      setState(503);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(504);
      match(SutDeclParser::MINUS);
      setState(505);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(506);
      operation();
      setState(507);
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

SutDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::ExpressionContext* SutDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<SutDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(SutDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(SutDeclParser::OrIdWord, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(SutDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(SutDeclParser::AndIdWord, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(SutDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> SutDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(SutDeclParser::ASSIGN);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(SutDeclParser::ASSIGN, i);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(SutDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(SutDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* SutDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(SutDeclParser::GREATERTHAN, 0);
}


size_t SutDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return SutDeclParser::RuleExpressionOptional;
}

void SutDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void SutDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

SutDeclParser::ExpressionOptionalContext* SutDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 104, SutDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(534);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::NotIdSymbol:
      case SutDeclParser::AndIdSymbol:
      case SutDeclParser::OrIdSymbol:
      case SutDeclParser::NotIdWord:
      case SutDeclParser::AndIdWord:
      case SutDeclParser::OrIdWord:
      case SutDeclParser::ASSIGN:
      case SutDeclParser::LESSTHAN:
      case SutDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(530);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SutDeclParser::OrIdSymbol: {
            setState(511);
            match(SutDeclParser::OrIdSymbol);
            break;
          }

          case SutDeclParser::OrIdWord: {
            setState(512);
            match(SutDeclParser::OrIdWord);
            break;
          }

          case SutDeclParser::AndIdSymbol: {
            setState(513);
            match(SutDeclParser::AndIdSymbol);
            break;
          }

          case SutDeclParser::AndIdWord: {
            setState(514);
            match(SutDeclParser::AndIdWord);
            break;
          }

          case SutDeclParser::ASSIGN: {
            setState(515);
            match(SutDeclParser::ASSIGN);
            setState(516);
            match(SutDeclParser::ASSIGN);
            break;
          }

          case SutDeclParser::NotIdSymbol: {
            setState(517);
            match(SutDeclParser::NotIdSymbol);
            setState(518);
            match(SutDeclParser::ASSIGN);
            break;
          }

          case SutDeclParser::NotIdWord: {
            setState(519);
            match(SutDeclParser::NotIdWord);
            break;
          }

          case SutDeclParser::LESSTHAN: {
            setState(520);
            match(SutDeclParser::LESSTHAN);
            setState(523);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case SutDeclParser::ASSIGN: {
                setState(521);
                match(SutDeclParser::ASSIGN);
                break;
              }

              case SutDeclParser::SutComponentID:
              case SutDeclParser::SutID:
              case SutDeclParser::NameID:
              case SutDeclParser::LabelID:
              case SutDeclParser::EnabledID:
              case SutDeclParser::TypeID:
              case SutDeclParser::TriggerID:
              case SutDeclParser::MessageTrigger:
              case SutDeclParser::ThisID:
              case SutDeclParser::AttributeID:
              case SutDeclParser::SignalID:
              case SutDeclParser::PortID:
              case SutDeclParser::ImportID:
              case SutDeclParser::FromID:
              case SutDeclParser::ToID:
              case SutDeclParser::SendID:
              case SutDeclParser::AsID:
              case SutDeclParser::NotIdSymbol:
              case SutDeclParser::NotIdWord:
              case SutDeclParser::TrueID:
              case SutDeclParser::FalseID:
              case SutDeclParser::INT:
              case SutDeclParser::REAL:
              case SutDeclParser::STRING:
              case SutDeclParser::ID:
              case SutDeclParser::LPAREN:
              case SutDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case SutDeclParser::GREATERTHAN: {
            setState(525);
            match(SutDeclParser::GREATERTHAN);
            setState(528);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case SutDeclParser::ASSIGN: {
                setState(526);
                match(SutDeclParser::ASSIGN);
                break;
              }

              case SutDeclParser::SutComponentID:
              case SutDeclParser::SutID:
              case SutDeclParser::NameID:
              case SutDeclParser::LabelID:
              case SutDeclParser::EnabledID:
              case SutDeclParser::TypeID:
              case SutDeclParser::TriggerID:
              case SutDeclParser::MessageTrigger:
              case SutDeclParser::ThisID:
              case SutDeclParser::AttributeID:
              case SutDeclParser::SignalID:
              case SutDeclParser::PortID:
              case SutDeclParser::ImportID:
              case SutDeclParser::FromID:
              case SutDeclParser::ToID:
              case SutDeclParser::SendID:
              case SutDeclParser::AsID:
              case SutDeclParser::NotIdSymbol:
              case SutDeclParser::NotIdWord:
              case SutDeclParser::TrueID:
              case SutDeclParser::FalseID:
              case SutDeclParser::INT:
              case SutDeclParser::REAL:
              case SutDeclParser::STRING:
              case SutDeclParser::ID:
              case SutDeclParser::LPAREN:
              case SutDeclParser::MINUS: {
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
        setState(532);
        expression();
        break;
      }

      case SutDeclParser::RPAREN:
      case SutDeclParser::SEMI: {
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

SutDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::IfStatementContext* SutDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<SutDeclParser::IfStatementContext>(0);
}

SutDeclParser::ElseStatementContext* SutDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<SutDeclParser::ElseStatementContext>(0);
}


size_t SutDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleConditionalStatement;
}

void SutDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void SutDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

SutDeclParser::ConditionalStatementContext* SutDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 106, SutDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(536);
    ifStatement();
    setState(539);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      setState(537);
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

SutDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::IfStatementContext::IfID() {
  return getToken(SutDeclParser::IfID, 0);
}

SutDeclParser::IfEuTContext* SutDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<SutDeclParser::IfEuTContext>(0);
}

SutDeclParser::StatementDeclContext* SutDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<SutDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* SutDeclParser::IfStatementContext::SEMI() {
  return getToken(SutDeclParser::SEMI, 0);
}


size_t SutDeclParser::IfStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleIfStatement;
}

void SutDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void SutDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

SutDeclParser::IfStatementContext* SutDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 108, SutDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(541);
    match(SutDeclParser::IfID);
    setState(542);
    ifEuT();
    setState(545);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::IntID:
      case SutDeclParser::RealID:
      case SutDeclParser::BoolID:
      case SutDeclParser::StringID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::ThisID:
      case SutDeclParser::ReturnID:
      case SutDeclParser::EnumID:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::SwitchID:
      case SutDeclParser::IfID:
      case SutDeclParser::AsID:
      case SutDeclParser::BREAK:
      case SutDeclParser::ID:
      case SutDeclParser::LBRACE: {
        setState(543);
        statementDecl();
        break;
      }

      case SutDeclParser::SEMI: {
        setState(544);
        match(SutDeclParser::SEMI);
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

SutDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::IfEuTContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

SutDeclParser::ExpressionContext* SutDeclParser::IfEuTContext::expression() {
  return getRuleContext<SutDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* SutDeclParser::IfEuTContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}


size_t SutDeclParser::IfEuTContext::getRuleIndex() const {
  return SutDeclParser::RuleIfEuT;
}

void SutDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void SutDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

SutDeclParser::IfEuTContext* SutDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 110, SutDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    match(SutDeclParser::LPAREN);
    setState(548);
    expression();
    setState(549);
    match(SutDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

SutDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::ElseStatementContext::ElseID() {
  return getToken(SutDeclParser::ElseID, 0);
}

SutDeclParser::StatementDeclContext* SutDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<SutDeclParser::StatementDeclContext>(0);
}


size_t SutDeclParser::ElseStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleElseStatement;
}

void SutDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void SutDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

SutDeclParser::ElseStatementContext* SutDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 112, SutDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(551);
    match(SutDeclParser::ElseID);
    setState(552);
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

SutDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(SutDeclParser::SwitchID, 0);
}

SutDeclParser::SwitchPuTContext* SutDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<SutDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* SutDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(SutDeclParser::LBRACE, 0);
}

tree::TerminalNode* SutDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(SutDeclParser::RBRACE, 0);
}

SutDeclParser::DefaultStatementContext* SutDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<SutDeclParser::DefaultStatementContext>(0);
}

std::vector<SutDeclParser::CaseStatementContext *> SutDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<SutDeclParser::CaseStatementContext>();
}

SutDeclParser::CaseStatementContext* SutDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<SutDeclParser::CaseStatementContext>(i);
}


size_t SutDeclParser::SwitchStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleSwitchStatement;
}

void SutDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void SutDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

SutDeclParser::SwitchStatementContext* SutDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, SutDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    match(SutDeclParser::SwitchID);
    setState(555);
    switchPuT();
    setState(556);
    match(SutDeclParser::LBRACE);
    setState(560);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SutDeclParser::CaseID) {
      setState(557);
      caseStatement();
      setState(562);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(565);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::DefaultID: {
        setState(563);
        defaultStatement();
        break;
      }

      case SutDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(567);
    match(SutDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

SutDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(SutDeclParser::LPAREN, 0);
}

SutDeclParser::ContextIDContext* SutDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<SutDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* SutDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(SutDeclParser::RPAREN, 0);
}


size_t SutDeclParser::SwitchPuTContext::getRuleIndex() const {
  return SutDeclParser::RuleSwitchPuT;
}

void SutDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void SutDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

SutDeclParser::SwitchPuTContext* SutDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 116, SutDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    match(SutDeclParser::LPAREN);
    setState(570);
    contextID();
    setState(571);
    match(SutDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

SutDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::CaseStatementContext::CaseID() {
  return getToken(SutDeclParser::CaseID, 0);
}

SutDeclParser::LiteralValueContext* SutDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<SutDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* SutDeclParser::CaseStatementContext::COLON() {
  return getToken(SutDeclParser::COLON, 0);
}

SutDeclParser::NestedStatementBodyContext* SutDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<SutDeclParser::NestedStatementBodyContext>(0);
}

std::vector<SutDeclParser::StatementBodyContext *> SutDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<SutDeclParser::StatementBodyContext>();
}

SutDeclParser::StatementBodyContext* SutDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<SutDeclParser::StatementBodyContext>(i);
}


size_t SutDeclParser::CaseStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleCaseStatement;
}

void SutDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void SutDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

SutDeclParser::CaseStatementContext* SutDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, SutDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    match(SutDeclParser::CaseID);
    setState(574);
    literalValue();
    setState(575);
    match(SutDeclParser::COLON);
    setState(583);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::LBRACE: {
        setState(576);
        nestedStatementBody();
        break;
      }

      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::IntID:
      case SutDeclParser::RealID:
      case SutDeclParser::BoolID:
      case SutDeclParser::StringID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::ThisID:
      case SutDeclParser::ReturnID:
      case SutDeclParser::EnumID:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::SwitchID:
      case SutDeclParser::CaseID:
      case SutDeclParser::DefaultID:
      case SutDeclParser::IfID:
      case SutDeclParser::AsID:
      case SutDeclParser::BREAK:
      case SutDeclParser::ID:
      case SutDeclParser::RBRACE: {
        setState(580);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SutDeclParser::SutComponentID)
          | (1ULL << SutDeclParser::SutID)
          | (1ULL << SutDeclParser::NameID)
          | (1ULL << SutDeclParser::LabelID)
          | (1ULL << SutDeclParser::EnabledID)
          | (1ULL << SutDeclParser::TypeID)
          | (1ULL << SutDeclParser::IntID)
          | (1ULL << SutDeclParser::RealID)
          | (1ULL << SutDeclParser::BoolID)
          | (1ULL << SutDeclParser::StringID)
          | (1ULL << SutDeclParser::TriggerID)
          | (1ULL << SutDeclParser::MessageTrigger)
          | (1ULL << SutDeclParser::ThisID)
          | (1ULL << SutDeclParser::ReturnID)
          | (1ULL << SutDeclParser::EnumID)
          | (1ULL << SutDeclParser::AttributeID)
          | (1ULL << SutDeclParser::SignalID)
          | (1ULL << SutDeclParser::PortID)
          | (1ULL << SutDeclParser::ImportID)
          | (1ULL << SutDeclParser::FromID)
          | (1ULL << SutDeclParser::ToID)
          | (1ULL << SutDeclParser::SendID)
          | (1ULL << SutDeclParser::SwitchID)
          | (1ULL << SutDeclParser::IfID)
          | (1ULL << SutDeclParser::AsID)
          | (1ULL << SutDeclParser::BREAK)
          | (1ULL << SutDeclParser::ID))) != 0)) {
          setState(577);
          statementBody();
          setState(582);
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

SutDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SutDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(SutDeclParser::DefaultID, 0);
}

tree::TerminalNode* SutDeclParser::DefaultStatementContext::COLON() {
  return getToken(SutDeclParser::COLON, 0);
}

SutDeclParser::NestedStatementBodyContext* SutDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<SutDeclParser::NestedStatementBodyContext>(0);
}

std::vector<SutDeclParser::StatementBodyContext *> SutDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<SutDeclParser::StatementBodyContext>();
}

SutDeclParser::StatementBodyContext* SutDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<SutDeclParser::StatementBodyContext>(i);
}


size_t SutDeclParser::DefaultStatementContext::getRuleIndex() const {
  return SutDeclParser::RuleDefaultStatement;
}

void SutDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void SutDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

SutDeclParser::DefaultStatementContext* SutDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 120, SutDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    match(SutDeclParser::DefaultID);
    setState(586);
    match(SutDeclParser::COLON);
    setState(594);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SutDeclParser::LBRACE: {
        setState(587);
        nestedStatementBody();
        break;
      }

      case SutDeclParser::SutComponentID:
      case SutDeclParser::SutID:
      case SutDeclParser::NameID:
      case SutDeclParser::LabelID:
      case SutDeclParser::EnabledID:
      case SutDeclParser::TypeID:
      case SutDeclParser::IntID:
      case SutDeclParser::RealID:
      case SutDeclParser::BoolID:
      case SutDeclParser::StringID:
      case SutDeclParser::TriggerID:
      case SutDeclParser::MessageTrigger:
      case SutDeclParser::ThisID:
      case SutDeclParser::ReturnID:
      case SutDeclParser::EnumID:
      case SutDeclParser::AttributeID:
      case SutDeclParser::SignalID:
      case SutDeclParser::PortID:
      case SutDeclParser::ImportID:
      case SutDeclParser::FromID:
      case SutDeclParser::ToID:
      case SutDeclParser::SendID:
      case SutDeclParser::SwitchID:
      case SutDeclParser::IfID:
      case SutDeclParser::AsID:
      case SutDeclParser::BREAK:
      case SutDeclParser::ID:
      case SutDeclParser::RBRACE: {
        setState(591);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SutDeclParser::SutComponentID)
          | (1ULL << SutDeclParser::SutID)
          | (1ULL << SutDeclParser::NameID)
          | (1ULL << SutDeclParser::LabelID)
          | (1ULL << SutDeclParser::EnabledID)
          | (1ULL << SutDeclParser::TypeID)
          | (1ULL << SutDeclParser::IntID)
          | (1ULL << SutDeclParser::RealID)
          | (1ULL << SutDeclParser::BoolID)
          | (1ULL << SutDeclParser::StringID)
          | (1ULL << SutDeclParser::TriggerID)
          | (1ULL << SutDeclParser::MessageTrigger)
          | (1ULL << SutDeclParser::ThisID)
          | (1ULL << SutDeclParser::ReturnID)
          | (1ULL << SutDeclParser::EnumID)
          | (1ULL << SutDeclParser::AttributeID)
          | (1ULL << SutDeclParser::SignalID)
          | (1ULL << SutDeclParser::PortID)
          | (1ULL << SutDeclParser::ImportID)
          | (1ULL << SutDeclParser::FromID)
          | (1ULL << SutDeclParser::ToID)
          | (1ULL << SutDeclParser::SendID)
          | (1ULL << SutDeclParser::SwitchID)
          | (1ULL << SutDeclParser::IfID)
          | (1ULL << SutDeclParser::AsID)
          | (1ULL << SutDeclParser::BREAK)
          | (1ULL << SutDeclParser::ID))) != 0)) {
          setState(588);
          statementBody();
          setState(593);
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

SutDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SutDeclParser::SignalParamNameContext* SutDeclParser::AtomContext::signalParamName() {
  return getRuleContext<SutDeclParser::SignalParamNameContext>(0);
}

SutDeclParser::AttributeNameContext* SutDeclParser::AtomContext::attributeName() {
  return getRuleContext<SutDeclParser::AttributeNameContext>(0);
}

SutDeclParser::FunctionCallContext* SutDeclParser::AtomContext::functionCall() {
  return getRuleContext<SutDeclParser::FunctionCallContext>(0);
}

SutDeclParser::LiteralValueContext* SutDeclParser::AtomContext::literalValue() {
  return getRuleContext<SutDeclParser::LiteralValueContext>(0);
}


size_t SutDeclParser::AtomContext::getRuleIndex() const {
  return SutDeclParser::RuleAtom;
}

void SutDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void SutDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SutDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

SutDeclParser::AtomContext* SutDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 122, SutDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(600);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(596);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(597);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(598);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(599);
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
std::vector<dfa::DFA> SutDeclParser::_decisionToDFA;
atn::PredictionContextCache SutDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SutDeclParser::_atn;
std::vector<uint16_t> SutDeclParser::_serializedATN;

std::vector<std::string> SutDeclParser::_ruleNames = {
  "sutDecl", "sutBody", "sutBodyOptional", "sutCompDecl", "sutCompBody", 
  "sutCompBodyOtional", "contextID", "componentIdPath", "signalIdPath", 
  "attributeIdPath", "signalSend", "commonDecl", "importPathDecl", "importPathBody", 
  "importFileBody", "importAs", "typeDefDecl", "typeDecl", "intTypeDecl", 
  "realTypeDecl", "enumTypeDecl", "attributeDecl", "literalValue", "signalParamName", 
  "attributeName", "toPortName", "attributeAssignStatement", "localAssignStatement", 
  "sendToStatement", "singleAssignment", "multiAssignment", "signalDecl", 
  "paramDecl", "functionDecl", "functionParameters", "functionCall", "functionCallBody", 
  "functionCallBodyOptional", "triggerDecl", "thisDecl", "portDecl", "nameDecl", 
  "idPath", "statementDecl", "statementBody", "functionCallStatement", "nestedStatementBody", 
  "returnStatement", "breakStatement", "operation", "operationOptional", 
  "expression", "expressionOptional", "conditionalStatement", "ifStatement", 
  "ifEuT", "elseStatement", "switchStatement", "switchPuT", "caseStatement", 
  "defaultStatement", "atom"
};

std::vector<std::string> SutDeclParser::_literalNames = {
  "", "'SutComponent'", "'Sut'", "", "'name'", "'label'", "'enabled'", "'Type'", 
  "'int'", "'real'", "'bool'", "'string'", "'trigger'", "'msg'", "'this'", 
  "'return'", "'SignalTransition'", "'TimeoutTransition'", "'enum'", "'Declaration'", 
  "'description'", "'Attribute'", "'Signal'", "'Port'", "'import'", "'from'", 
  "'to'", "'send'", "'Function'", "'switch'", "'case'", "'default'", "'if'", 
  "'else'", "'as'", "'@'", "'!'", "'&&'", "'||'", "'not'", "'and'", "'or'", 
  "'true'", "'false'", "'break'", "'='", "'<->'", "'->'", "'<-'", "'..'", 
  "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", "'<'", 
  "'>'", "':'", "';'", "','", "'_'", "'.'", "'+'", "'-'", "'*'", "'/'", 
  "'|'", "'&'", "'const'"
};

std::vector<std::string> SutDeclParser::_symbolicNames = {
  "", "SutComponentID", "SutID", "IGNORE_NEWLINE", "NameID", "LabelID", 
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

dfa::Vocabulary SutDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SutDeclParser::_tokenNames;

SutDeclParser::Initializer::Initializer() {
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
    0x3, 0x4f, 0x25d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x3f, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x8e, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x9f, 0xa, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xb1, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x7, 0x9, 0xb6, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb9, 0xb, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xbe, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0xc1, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0xc7, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xca, 0xb, 0xb, 0x5, 0xb, 0xcc, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xd6, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xd9, 
    0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xdf, 0xa, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xf2, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xf7, 0xa, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x104, 0xa, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0x10d, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x116, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x11d, 
    0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x120, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x129, 
    0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x133, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x13a, 0xa, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x14b, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x153, 0xa, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x159, 0xa, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x15d, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 
    0x160, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x16a, 0xa, 0x21, 0xc, 0x21, 
    0xe, 0x21, 0x16d, 0xb, 0x21, 0x3, 0x21, 0x5, 0x21, 0x170, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x174, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x181, 0xa, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x189, 
    0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x18c, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x5, 0x26, 0x198, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x19f, 0xa, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x1ab, 0xa, 0x2a, 0xc, 0x2a, 
    0xe, 0x2a, 0x1ae, 0xb, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 
    0x2c, 0x1ba, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x1bd, 0xb, 0x2c, 0x3, 
    0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x1c1, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 
    0x2e, 0x1cb, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 
    0x3, 0x30, 0x7, 0x30, 0x1d2, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x1d5, 
    0xb, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x5, 0x33, 0x1eb, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x5, 0x34, 0x1f0, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x200, 
    0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x20e, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 
    0x213, 0xa, 0x36, 0x5, 0x36, 0x215, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x219, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 
    0x21e, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 
    0x224, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 
    0x3b, 0x231, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x234, 0xb, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x238, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x245, 0xa, 0x3d, 0xc, 0x3d, 
    0xe, 0x3d, 0x248, 0xb, 0x3d, 0x5, 0x3d, 0x24a, 0xa, 0x3d, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x250, 0xa, 0x3e, 0xc, 0x3e, 
    0xe, 0x3e, 0x253, 0xb, 0x3e, 0x5, 0x3e, 0x255, 0xa, 0x3e, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x25b, 0xa, 0x3f, 0x3, 0x3f, 
    0x2, 0x2, 0x40, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
    0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
    0x76, 0x78, 0x7a, 0x7c, 0x2, 0x4, 0x3, 0x2, 0xe, 0xf, 0x3, 0x2, 0x47, 
    0x4a, 0x2, 0x282, 0x2, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x94, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xe, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x12, 0xba, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x16, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x22, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x103, 0x3, 0x2, 0x2, 0x2, 0x26, 0x105, 0x3, 0x2, 0x2, 0x2, 0x28, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x117, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x132, 0x3, 0x2, 0x2, 0x2, 0x30, 0x134, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x139, 0x3, 0x2, 0x2, 0x2, 0x34, 0x13d, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x140, 0x3, 0x2, 0x2, 0x2, 0x38, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x158, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x15a, 0x3, 0x2, 0x2, 0x2, 0x40, 0x163, 0x3, 0x2, 0x2, 0x2, 0x42, 0x177, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x46, 0x185, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x197, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1a6, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1cc, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1d8, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1ea, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1ff, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x218, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x70, 0x225, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x74, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x76, 0x23b, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x24b, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x4, 
    0x2, 0x2, 0x7f, 0x80, 0x7, 0x3c, 0x2, 0x2, 0x80, 0x81, 0x5, 0x4, 0x3, 
    0x2, 0x81, 0x82, 0x7, 0x3d, 0x2, 0x2, 0x82, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x83, 0x84, 0x5, 0x54, 0x2b, 0x2, 0x84, 0x85, 0x5, 0x6, 0x4, 0x2, 0x85, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x5, 0x2c, 0x17, 0x2, 0x87, 0x88, 
    0x5, 0x6, 0x4, 0x2, 0x88, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x5, 
    0x8, 0x5, 0x2, 0x8a, 0x8b, 0x5, 0x6, 0x4, 0x2, 0x8b, 0x8e, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x86, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x3, 0x2, 0x2, 0x90, 
    0x91, 0x7, 0x3c, 0x2, 0x2, 0x91, 0x92, 0x5, 0xa, 0x6, 0x2, 0x92, 0x93, 
    0x7, 0x3d, 0x2, 0x2, 0x93, 0x9, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 
    0x54, 0x2b, 0x2, 0x95, 0x96, 0x5, 0xc, 0x7, 0x2, 0x96, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x98, 0x5, 0x2c, 0x17, 0x2, 0x98, 0x99, 0x5, 0xc, 0x7, 
    0x2, 0x99, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x52, 0x2a, 0x2, 
    0x9b, 0x9c, 0x5, 0xc, 0x7, 0x2, 0x9c, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0xb1, 0x7, 0x37, 0x2, 0x2, 0xa1, 0xb1, 0x7, 0x6, 
    0x2, 0x2, 0xa2, 0xb1, 0x7, 0x7, 0x2, 0x2, 0xa3, 0xb1, 0x7, 0x8, 0x2, 
    0x2, 0xa4, 0xb1, 0x7, 0x9, 0x2, 0x2, 0xa5, 0xb1, 0x9, 0x2, 0x2, 0x2, 
    0xa6, 0xb1, 0x7, 0x17, 0x2, 0x2, 0xa7, 0xb1, 0x7, 0x18, 0x2, 0x2, 0xa8, 
    0xb1, 0x7, 0x19, 0x2, 0x2, 0xa9, 0xb1, 0x7, 0x1a, 0x2, 0x2, 0xaa, 0xb1, 
    0x7, 0x1b, 0x2, 0x2, 0xab, 0xb1, 0x7, 0x1c, 0x2, 0x2, 0xac, 0xb1, 0x7, 
    0x1d, 0x2, 0x2, 0xad, 0xb1, 0x7, 0x24, 0x2, 0x2, 0xae, 0xb1, 0x7, 0x3, 
    0x2, 0x2, 0xaf, 0xb1, 0x7, 0x4, 0x2, 0x2, 0xb0, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xad, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb7, 0x5, 0xe, 0x8, 0x2, 0xb3, 
    0xb4, 0x7, 0x46, 0x2, 0x2, 0xb4, 0xb6, 0x5, 0xe, 0x8, 0x2, 0xb5, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbf, 0x5, 0xe, 0x8, 
    0x2, 0xbb, 0xbc, 0x7, 0x46, 0x2, 0x2, 0xbc, 0xbe, 0x5, 0xe, 0x8, 0x2, 
    0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xcc, 0x5, 
    0x32, 0x1a, 0x2, 0xc3, 0xc8, 0x5, 0xe, 0x8, 0x2, 0xc4, 0xc5, 0x7, 0x46, 
    0x2, 0x2, 0xc5, 0xc7, 0x5, 0xe, 0x8, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc3, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0x15, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 
    0x12, 0xa, 0x2, 0xce, 0xcf, 0x7, 0x3a, 0x2, 0x2, 0xcf, 0xd0, 0x5, 0x4a, 
    0x26, 0x2, 0xd0, 0xd1, 0x7, 0x3b, 0x2, 0x2, 0xd1, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xd6, 0x5, 0x22, 0x12, 0x2, 0xd3, 0xd6, 0x5, 0x2c, 0x17, 
    0x2, 0xd4, 0xd6, 0x5, 0x40, 0x21, 0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x1c, 0xf, 0x2, 0xdb, 0xdc, 0x5, 0x1a, 
    0xe, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xda, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x1a, 0x2, 0x2, 0xe1, 
    0xe2, 0x7, 0x40, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x1e, 0x10, 0x2, 0xe3, 0xe4, 
    0x7, 0x41, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x20, 0x11, 0x2, 0xe5, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0xe, 0x8, 0x2, 0xe7, 0xe8, 0x7, 0x46, 
    0x2, 0x2, 0xe8, 0xe9, 0x5, 0xe, 0x8, 0x2, 0xe9, 0xf2, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xeb, 0x7, 0x33, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x4a, 0x2, 0x2, 
    0xec, 0xf2, 0x5, 0x1e, 0x10, 0x2, 0xed, 0xee, 0x5, 0xe, 0x8, 0x2, 0xee, 
    0xef, 0x7, 0x4a, 0x2, 0x2, 0xef, 0xf0, 0x5, 0x1e, 0x10, 0x2, 0xf0, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xf3, 0xf4, 0x7, 0x24, 0x2, 0x2, 0xf4, 0xf7, 0x5, 0xe, 0x8, 
    0x2, 0xf5, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0xf9, 0x7, 0x9, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x24, 0x13, 0x2, 0xfa, 0xfb, 
    0x5, 0xe, 0x8, 0x2, 0xfb, 0xfc, 0x7, 0x43, 0x2, 0x2, 0xfc, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0x104, 0x5, 0x26, 0x14, 0x2, 0xfe, 0x104, 0x5, 
    0x28, 0x15, 0x2, 0xff, 0x104, 0x5, 0x2a, 0x16, 0x2, 0x100, 0x104, 0x7, 
    0xc, 0x2, 0x2, 0x101, 0x104, 0x7, 0xd, 0x2, 0x2, 0x102, 0x104, 0x5, 
    0xe, 0x8, 0x2, 0x103, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x103, 0xfe, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0xff, 0x3, 0x2, 0x2, 0x2, 0x103, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x25, 0x3, 0x2, 0x2, 0x2, 0x105, 0x10c, 0x7, 0xa, 0x2, 0x2, 
    0x106, 0x107, 0x7, 0x3a, 0x2, 0x2, 0x107, 0x108, 0x7, 0x34, 0x2, 0x2, 
    0x108, 0x109, 0x7, 0x33, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x34, 0x2, 0x2, 
    0x10a, 0x10d, 0x7, 0x3b, 0x2, 0x2, 0x10b, 0x10d, 0x3, 0x2, 0x2, 0x2, 
    0x10c, 0x106, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x10d, 0x27, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x115, 0x7, 0xb, 0x2, 0x2, 0x10f, 
    0x110, 0x7, 0x3a, 0x2, 0x2, 0x110, 0x111, 0x7, 0x35, 0x2, 0x2, 0x111, 
    0x112, 0x7, 0x33, 0x2, 0x2, 0x112, 0x113, 0x7, 0x35, 0x2, 0x2, 0x113, 
    0x116, 0x7, 0x3b, 0x2, 0x2, 0x114, 0x116, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0x115, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0x14, 0x2, 0x2, 0x118, 
    0x119, 0x7, 0x3a, 0x2, 0x2, 0x119, 0x11e, 0x5, 0xe, 0x8, 0x2, 0x11a, 
    0x11b, 0x7, 0x44, 0x2, 0x2, 0x11b, 0x11d, 0x5, 0xe, 0x8, 0x2, 0x11c, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11e, 
    0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x121, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x122, 0x7, 0x3b, 0x2, 0x2, 0x122, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x123, 
    0x124, 0x7, 0x17, 0x2, 0x2, 0x124, 0x125, 0x5, 0x24, 0x13, 0x2, 0x125, 
    0x128, 0x5, 0xe, 0x8, 0x2, 0x126, 0x127, 0x7, 0x2f, 0x2, 0x2, 0x127, 
    0x129, 0x5, 0x2e, 0x18, 0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 
    0x12b, 0x7, 0x43, 0x2, 0x2, 0x12b, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x12c, 
    0x133, 0x7, 0x34, 0x2, 0x2, 0x12d, 0x133, 0x7, 0x35, 0x2, 0x2, 0x12e, 
    0x133, 0x7, 0x36, 0x2, 0x2, 0x12f, 0x133, 0x7, 0x2c, 0x2, 0x2, 0x130, 
    0x133, 0x7, 0x2d, 0x2, 0x2, 0x131, 0x133, 0x5, 0xe, 0x8, 0x2, 0x132, 
    0x12c, 0x3, 0x2, 0x2, 0x2, 0x132, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x12e, 0x3, 0x2, 0x2, 0x2, 0x132, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x5, 0x4e, 0x28, 0x2, 0x135, 
    0x136, 0x5, 0xe, 0x8, 0x2, 0x136, 0x31, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 
    0x5, 0x50, 0x29, 0x2, 0x138, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0xe, 0x8, 0x2, 0x13c, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x1c, 0x2, 0x2, 0x13e, 0x13f, 0x5, 
    0xe, 0x8, 0x2, 0x13f, 0x35, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x5, 0x32, 
    0x1a, 0x2, 0x141, 0x142, 0x7, 0x2f, 0x2, 0x2, 0x142, 0x143, 0x5, 0x68, 
    0x35, 0x2, 0x143, 0x144, 0x7, 0x43, 0x2, 0x2, 0x144, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x145, 0x146, 0x5, 0x24, 0x13, 0x2, 0x146, 0x14a, 0x5, 0xe, 
    0x8, 0x2, 0x147, 0x148, 0x7, 0x2f, 0x2, 0x2, 0x148, 0x14b, 0x5, 0x68, 
    0x35, 0x2, 0x149, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14d, 0x7, 0x43, 0x2, 0x2, 0x14d, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x14f, 0x7, 0x1d, 0x2, 0x2, 0x14f, 0x152, 0x5, 0x16, 
    0xc, 0x2, 0x150, 0x153, 0x5, 0x34, 0x1b, 0x2, 0x151, 0x153, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x151, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x7, 0x43, 
    0x2, 0x2, 0x155, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x156, 0x159, 0x5, 0x36, 
    0x1c, 0x2, 0x157, 0x159, 0x5, 0x3a, 0x1e, 0x2, 0x158, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x158, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x15e, 0x7, 0x3c, 0x2, 0x2, 0x15b, 0x15d, 0x5, 0x3c, 0x1f, 
    0x2, 0x15c, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 
    0x2, 0x15f, 0x161, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x162, 0x7, 0x3d, 0x2, 0x2, 0x162, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x163, 0x164, 0x7, 0x18, 0x2, 0x2, 0x164, 0x173, 0x5, 0xe, 0x8, 
    0x2, 0x165, 0x16f, 0x7, 0x3a, 0x2, 0x2, 0x166, 0x16b, 0x5, 0x42, 0x22, 
    0x2, 0x167, 0x168, 0x7, 0x44, 0x2, 0x2, 0x168, 0x16a, 0x5, 0x42, 0x22, 
    0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 
    0x2, 0x16e, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x166, 0x3, 0x2, 0x2, 
    0x2, 0x16f, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x174, 0x7, 0x3b, 0x2, 0x2, 0x172, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x173, 0x165, 0x3, 0x2, 0x2, 0x2, 0x173, 0x172, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x7, 0x43, 0x2, 
    0x2, 0x176, 0x41, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x5, 0x24, 0x13, 
    0x2, 0x178, 0x179, 0x5, 0xe, 0x8, 0x2, 0x179, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x17b, 0x7, 0x1e, 0x2, 0x2, 0x17b, 0x17c, 0x5, 0x24, 0x13, 0x2, 
    0x17c, 0x17d, 0x5, 0x56, 0x2c, 0x2, 0x17d, 0x180, 0x7, 0x3a, 0x2, 0x2, 
    0x17e, 0x181, 0x5, 0x46, 0x24, 0x2, 0x17f, 0x181, 0x3, 0x2, 0x2, 0x2, 
    0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17f, 0x3, 0x2, 0x2, 0x2, 
    0x181, 0x182, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x7, 0x3b, 0x2, 0x2, 
    0x183, 0x184, 0x5, 0x5e, 0x30, 0x2, 0x184, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x185, 0x18a, 0x5, 0x42, 0x22, 0x2, 0x186, 0x187, 0x7, 0x44, 0x2, 0x2, 
    0x187, 0x189, 0x5, 0x42, 0x22, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 
    0x189, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 
    0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x47, 0x3, 0x2, 0x2, 0x2, 0x18c, 
    0x18a, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x5, 0x56, 0x2c, 0x2, 0x18e, 
    0x18f, 0x7, 0x3a, 0x2, 0x2, 0x18f, 0x190, 0x5, 0x4a, 0x26, 0x2, 0x190, 
    0x191, 0x7, 0x3b, 0x2, 0x2, 0x191, 0x49, 0x3, 0x2, 0x2, 0x2, 0x192, 
    0x198, 0x5, 0x2e, 0x18, 0x2, 0x193, 0x198, 0x5, 0x30, 0x19, 0x2, 0x194, 
    0x198, 0x5, 0x32, 0x1a, 0x2, 0x195, 0x198, 0x5, 0x48, 0x25, 0x2, 0x196, 
    0x198, 0x3, 0x2, 0x2, 0x2, 0x197, 0x192, 0x3, 0x2, 0x2, 0x2, 0x197, 
    0x193, 0x3, 0x2, 0x2, 0x2, 0x197, 0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 
    0x195, 0x3, 0x2, 0x2, 0x2, 0x197, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 
    0x199, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x5, 0x4c, 0x27, 0x2, 0x19a, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x44, 0x2, 0x2, 0x19c, 
    0x19f, 0x5, 0x4a, 0x26, 0x2, 0x19d, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19e, 
    0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x9, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 
    0x7, 0x46, 0x2, 0x2, 0x1a2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 
    0x7, 0x10, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x46, 0x2, 0x2, 0x1a5, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x19, 0x2, 0x2, 0x1a7, 0x1ac, 
    0x5, 0xe, 0x8, 0x2, 0x1a8, 0x1a9, 0x7, 0x44, 0x2, 0x2, 0x1a9, 0x1ab, 
    0x5, 0xe, 0x8, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ae, 
    0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 
    0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1ac, 
    0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x43, 0x2, 0x2, 0x1b0, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x6, 0x2, 0x2, 0x1b2, 0x1b3, 
    0x7, 0x42, 0x2, 0x2, 0x1b3, 0x1b4, 0x5, 0xe, 0x8, 0x2, 0x1b4, 0x1b5, 
    0x7, 0x43, 0x2, 0x2, 0x1b5, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1bb, 
    0x5, 0xe, 0x8, 0x2, 0x1b7, 0x1b8, 0x7, 0x46, 0x2, 0x2, 0x1b8, 0x1ba, 
    0x5, 0xe, 0x8, 0x2, 0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bd, 
    0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 
    0x3, 0x2, 0x2, 0x2, 0x1bc, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bb, 0x3, 
    0x2, 0x2, 0x2, 0x1be, 0x1c1, 0x5, 0x5a, 0x2e, 0x2, 0x1bf, 0x1c1, 0x5, 
    0x5e, 0x30, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1bf, 0x3, 
    0x2, 0x2, 0x2, 0x1c1, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1cb, 0x5, 0x5c, 
    0x2f, 0x2, 0x1c3, 0x1cb, 0x5, 0x36, 0x1c, 0x2, 0x1c4, 0x1cb, 0x5, 0x74, 
    0x3b, 0x2, 0x1c5, 0x1cb, 0x5, 0x6c, 0x37, 0x2, 0x1c6, 0x1cb, 0x5, 0x38, 
    0x1d, 0x2, 0x1c7, 0x1cb, 0x5, 0x3a, 0x1e, 0x2, 0x1c8, 0x1cb, 0x5, 0x62, 
    0x32, 0x2, 0x1c9, 0x1cb, 0x5, 0x60, 0x31, 0x2, 0x1ca, 0x1c2, 0x3, 0x2, 
    0x2, 0x2, 0x1ca, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c4, 0x3, 0x2, 
    0x2, 0x2, 0x1ca, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1ca, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c8, 0x3, 0x2, 
    0x2, 0x2, 0x1ca, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x1cc, 0x1cd, 0x5, 0x48, 0x25, 0x2, 0x1cd, 0x1ce, 0x7, 0x43, 0x2, 
    0x2, 0x1ce, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d3, 0x7, 0x3c, 0x2, 
    0x2, 0x1d0, 0x1d2, 0x5, 0x5a, 0x2e, 0x2, 0x1d1, 0x1d0, 0x3, 0x2, 0x2, 
    0x2, 0x1d2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d1, 0x3, 0x2, 0x2, 
    0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d6, 0x3, 0x2, 0x2, 
    0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 0x7, 0x3d, 0x2, 
    0x2, 0x1d7, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x7, 0x11, 0x2, 
    0x2, 0x1d9, 0x1da, 0x5, 0x64, 0x33, 0x2, 0x1da, 0x1db, 0x7, 0x43, 0x2, 
    0x2, 0x1db, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x7, 0x2e, 0x2, 
    0x2, 0x1dd, 0x1de, 0x7, 0x43, 0x2, 0x2, 0x1de, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x1df, 0x1e0, 0x5, 0x7c, 0x3f, 0x2, 0x1e0, 0x1e1, 0x5, 0x66, 0x34, 
    0x2, 0x1e1, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x7, 0x3a, 0x2, 
    0x2, 0x1e3, 0x1e4, 0x5, 0x64, 0x33, 0x2, 0x1e4, 0x1e5, 0x7, 0x3b, 0x2, 
    0x2, 0x1e5, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x7, 0x48, 0x2, 
    0x2, 0x1e7, 0x1eb, 0x5, 0x64, 0x33, 0x2, 0x1e8, 0x1e9, 0x7, 0x26, 0x2, 
    0x2, 0x1e9, 0x1eb, 0x5, 0x64, 0x33, 0x2, 0x1ea, 0x1df, 0x3, 0x2, 0x2, 
    0x2, 0x1ea, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1e6, 0x3, 0x2, 0x2, 
    0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x9, 0x3, 0x2, 0x2, 0x1ed, 0x1f0, 0x5, 0x64, 0x33, 0x2, 
    0x1ee, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1ec, 0x3, 0x2, 0x2, 0x2, 
    0x1ef, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
    0x1f2, 0x7, 0x3a, 0x2, 0x2, 0x1f2, 0x1f3, 0x5, 0x68, 0x35, 0x2, 0x1f3, 
    0x1f4, 0x7, 0x3b, 0x2, 0x2, 0x1f4, 0x1f5, 0x5, 0x6a, 0x36, 0x2, 0x1f5, 
    0x200, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x7, 0x26, 0x2, 0x2, 0x1f7, 
    0x200, 0x5, 0x68, 0x35, 0x2, 0x1f8, 0x1f9, 0x7, 0x29, 0x2, 0x2, 0x1f9, 
    0x200, 0x5, 0x68, 0x35, 0x2, 0x1fa, 0x1fb, 0x7, 0x48, 0x2, 0x2, 0x1fb, 
    0x200, 0x5, 0x68, 0x35, 0x2, 0x1fc, 0x1fd, 0x5, 0x64, 0x33, 0x2, 0x1fd, 
    0x1fe, 0x5, 0x6a, 0x36, 0x2, 0x1fe, 0x200, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
    0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
    0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
    0x1fc, 0x3, 0x2, 0x2, 0x2, 0x200, 0x69, 0x3, 0x2, 0x2, 0x2, 0x201, 0x215, 
    0x7, 0x28, 0x2, 0x2, 0x202, 0x215, 0x7, 0x2b, 0x2, 0x2, 0x203, 0x215, 
    0x7, 0x27, 0x2, 0x2, 0x204, 0x215, 0x7, 0x2a, 0x2, 0x2, 0x205, 0x206, 
    0x7, 0x2f, 0x2, 0x2, 0x206, 0x215, 0x7, 0x2f, 0x2, 0x2, 0x207, 0x208, 
    0x7, 0x26, 0x2, 0x2, 0x208, 0x215, 0x7, 0x2f, 0x2, 0x2, 0x209, 0x215, 
    0x7, 0x29, 0x2, 0x2, 0x20a, 0x20d, 0x7, 0x40, 0x2, 0x2, 0x20b, 0x20e, 
    0x7, 0x2f, 0x2, 0x2, 0x20c, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20b, 
    0x3, 0x2, 0x2, 0x2, 0x20d, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x215, 
    0x3, 0x2, 0x2, 0x2, 0x20f, 0x212, 0x7, 0x41, 0x2, 0x2, 0x210, 0x213, 
    0x7, 0x2f, 0x2, 0x2, 0x211, 0x213, 0x3, 0x2, 0x2, 0x2, 0x212, 0x210, 
    0x3, 0x2, 0x2, 0x2, 0x212, 0x211, 0x3, 0x2, 0x2, 0x2, 0x213, 0x215, 
    0x3, 0x2, 0x2, 0x2, 0x214, 0x201, 0x3, 0x2, 0x2, 0x2, 0x214, 0x202, 
    0x3, 0x2, 0x2, 0x2, 0x214, 0x203, 0x3, 0x2, 0x2, 0x2, 0x214, 0x204, 
    0x3, 0x2, 0x2, 0x2, 0x214, 0x205, 0x3, 0x2, 0x2, 0x2, 0x214, 0x207, 
    0x3, 0x2, 0x2, 0x2, 0x214, 0x209, 0x3, 0x2, 0x2, 0x2, 0x214, 0x20a, 
    0x3, 0x2, 0x2, 0x2, 0x214, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 
    0x3, 0x2, 0x2, 0x2, 0x216, 0x219, 0x5, 0x68, 0x35, 0x2, 0x217, 0x219, 
    0x3, 0x2, 0x2, 0x2, 0x218, 0x214, 0x3, 0x2, 0x2, 0x2, 0x218, 0x217, 
    0x3, 0x2, 0x2, 0x2, 0x219, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21d, 0x5, 
    0x6e, 0x38, 0x2, 0x21b, 0x21e, 0x5, 0x72, 0x3a, 0x2, 0x21c, 0x21e, 0x3, 
    0x2, 0x2, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21c, 0x3, 
    0x2, 0x2, 0x2, 0x21e, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 0x7, 0x22, 
    0x2, 0x2, 0x220, 0x223, 0x5, 0x70, 0x39, 0x2, 0x221, 0x224, 0x5, 0x58, 
    0x2d, 0x2, 0x222, 0x224, 0x7, 0x43, 0x2, 0x2, 0x223, 0x221, 0x3, 0x2, 
    0x2, 0x2, 0x223, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x225, 0x226, 0x7, 0x3a, 0x2, 0x2, 0x226, 0x227, 0x5, 0x68, 0x35, 
    0x2, 0x227, 0x228, 0x7, 0x3b, 0x2, 0x2, 0x228, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x229, 0x22a, 0x7, 0x23, 0x2, 0x2, 0x22a, 0x22b, 0x5, 0x58, 0x2d, 
    0x2, 0x22b, 0x73, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x7, 0x1f, 0x2, 
    0x2, 0x22d, 0x22e, 0x5, 0x76, 0x3c, 0x2, 0x22e, 0x232, 0x7, 0x3c, 0x2, 
    0x2, 0x22f, 0x231, 0x5, 0x78, 0x3d, 0x2, 0x230, 0x22f, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x234, 0x3, 0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 0x2, 0x2, 
    0x2, 0x232, 0x233, 0x3, 0x2, 0x2, 0x2, 0x233, 0x237, 0x3, 0x2, 0x2, 
    0x2, 0x234, 0x232, 0x3, 0x2, 0x2, 0x2, 0x235, 0x238, 0x5, 0x7a, 0x3e, 
    0x2, 0x236, 0x238, 0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 
    0x2, 0x237, 0x236, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x3, 0x2, 0x2, 
    0x2, 0x239, 0x23a, 0x7, 0x3d, 0x2, 0x2, 0x23a, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x23b, 0x23c, 0x7, 0x3a, 0x2, 0x2, 0x23c, 0x23d, 0x5, 0xe, 0x8, 
    0x2, 0x23d, 0x23e, 0x7, 0x3b, 0x2, 0x2, 0x23e, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x23f, 0x240, 0x7, 0x20, 0x2, 0x2, 0x240, 0x241, 0x5, 0x2e, 0x18, 
    0x2, 0x241, 0x249, 0x7, 0x42, 0x2, 0x2, 0x242, 0x24a, 0x5, 0x5e, 0x30, 
    0x2, 0x243, 0x245, 0x5, 0x5a, 0x2e, 0x2, 0x244, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x245, 0x248, 0x3, 0x2, 0x2, 0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 
    0x2, 0x246, 0x247, 0x3, 0x2, 0x2, 0x2, 0x247, 0x24a, 0x3, 0x2, 0x2, 
    0x2, 0x248, 0x246, 0x3, 0x2, 0x2, 0x2, 0x249, 0x242, 0x3, 0x2, 0x2, 
    0x2, 0x249, 0x246, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x24b, 0x24c, 0x7, 0x21, 0x2, 0x2, 0x24c, 0x254, 0x7, 0x42, 0x2, 0x2, 
    0x24d, 0x255, 0x5, 0x5e, 0x30, 0x2, 0x24e, 0x250, 0x5, 0x5a, 0x2e, 0x2, 
    0x24f, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x250, 0x253, 0x3, 0x2, 0x2, 0x2, 
    0x251, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x3, 0x2, 0x2, 0x2, 
    0x252, 0x255, 0x3, 0x2, 0x2, 0x2, 0x253, 0x251, 0x3, 0x2, 0x2, 0x2, 
    0x254, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x254, 0x251, 0x3, 0x2, 0x2, 0x2, 
    0x255, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x256, 0x25b, 0x5, 0x30, 0x19, 0x2, 
    0x257, 0x25b, 0x5, 0x32, 0x1a, 0x2, 0x258, 0x25b, 0x5, 0x48, 0x25, 0x2, 
    0x259, 0x25b, 0x5, 0x2e, 0x18, 0x2, 0x25a, 0x256, 0x3, 0x2, 0x2, 0x2, 
    0x25a, 0x257, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x258, 0x3, 0x2, 0x2, 0x2, 
    0x25a, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x8d, 0x9e, 0xb0, 0xb7, 0xbf, 0xc8, 0xcb, 0xd5, 0xd7, 0xde, 0xf1, 0xf6, 
    0x103, 0x10c, 0x115, 0x11e, 0x128, 0x132, 0x139, 0x14a, 0x152, 0x158, 
    0x15e, 0x16b, 0x16f, 0x173, 0x180, 0x18a, 0x197, 0x19e, 0x1ac, 0x1bb, 
    0x1c0, 0x1ca, 0x1d3, 0x1ea, 0x1ef, 0x1ff, 0x20d, 0x212, 0x214, 0x218, 
    0x21d, 0x223, 0x232, 0x237, 0x246, 0x249, 0x251, 0x254, 0x25a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SutDeclParser::Initializer SutDeclParser::_init;
