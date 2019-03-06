
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/CommonDecl.g4 by ANTLR 4.7.2


#include "CommonDeclListener.h"

#include "CommonDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

CommonDeclParser::CommonDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CommonDeclParser::~CommonDeclParser() {
  delete _interpreter;
}

std::string CommonDeclParser::getGrammarFileName() const {
  return "CommonDecl.g4";
}

const std::vector<std::string>& CommonDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CommonDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ComponentIdPathContext ------------------------------------------------------------------

CommonDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommonDeclParser::ContextIDContext *> CommonDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<CommonDeclParser::ContextIDContext>();
}

CommonDeclParser::ContextIDContext* CommonDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<CommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> CommonDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(CommonDeclParser::DOT);
}

tree::TerminalNode* CommonDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(CommonDeclParser::DOT, i);
}


size_t CommonDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return CommonDeclParser::RuleComponentIdPath;
}

void CommonDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void CommonDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

CommonDeclParser::ComponentIdPathContext* CommonDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 0, CommonDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    contextID();
    setState(117);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommonDeclParser::DOT) {
      setState(113);
      match(CommonDeclParser::DOT);
      setState(114);
      contextID();
      setState(119);
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

CommonDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommonDeclParser::ContextIDContext *> CommonDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<CommonDeclParser::ContextIDContext>();
}

CommonDeclParser::ContextIDContext* CommonDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<CommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> CommonDeclParser::SignalIdPathContext::DOT() {
  return getTokens(CommonDeclParser::DOT);
}

tree::TerminalNode* CommonDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(CommonDeclParser::DOT, i);
}


size_t CommonDeclParser::SignalIdPathContext::getRuleIndex() const {
  return CommonDeclParser::RuleSignalIdPath;
}

void CommonDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void CommonDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

CommonDeclParser::SignalIdPathContext* CommonDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 2, CommonDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    contextID();
    setState(125);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommonDeclParser::DOT) {
      setState(121);
      match(CommonDeclParser::DOT);
      setState(122);
      contextID();
      setState(127);
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

CommonDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::AttributeNameContext* CommonDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<CommonDeclParser::AttributeNameContext>(0);
}

std::vector<CommonDeclParser::ContextIDContext *> CommonDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<CommonDeclParser::ContextIDContext>();
}

CommonDeclParser::ContextIDContext* CommonDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<CommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> CommonDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(CommonDeclParser::DOT);
}

tree::TerminalNode* CommonDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(CommonDeclParser::DOT, i);
}


size_t CommonDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return CommonDeclParser::RuleAttributeIdPath;
}

void CommonDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void CommonDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

CommonDeclParser::AttributeIdPathContext* CommonDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 4, CommonDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(128);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(129);
      contextID();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CommonDeclParser::DOT) {
        setState(130);
        match(CommonDeclParser::DOT);
        setState(131);
        contextID();
        setState(136);
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

CommonDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::SignalIdPathContext* CommonDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<CommonDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* CommonDeclParser::SignalSendContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

CommonDeclParser::FunctionCallBodyContext* CommonDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<CommonDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* CommonDeclParser::SignalSendContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}


size_t CommonDeclParser::SignalSendContext::getRuleIndex() const {
  return CommonDeclParser::RuleSignalSend;
}

void CommonDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void CommonDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

CommonDeclParser::SignalSendContext* CommonDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 6, CommonDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    signalIdPath();
    setState(140);
    match(CommonDeclParser::LPAREN);
    setState(141);
    functionCallBody();
    setState(142);
    match(CommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

CommonDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommonDeclParser::TypeDefDeclContext *> CommonDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<CommonDeclParser::TypeDefDeclContext>();
}

CommonDeclParser::TypeDefDeclContext* CommonDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<CommonDeclParser::TypeDefDeclContext>(i);
}

std::vector<CommonDeclParser::AttributeDeclContext *> CommonDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<CommonDeclParser::AttributeDeclContext>();
}

CommonDeclParser::AttributeDeclContext* CommonDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<CommonDeclParser::AttributeDeclContext>(i);
}

std::vector<CommonDeclParser::SignalDeclContext *> CommonDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<CommonDeclParser::SignalDeclContext>();
}

CommonDeclParser::SignalDeclContext* CommonDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<CommonDeclParser::SignalDeclContext>(i);
}


size_t CommonDeclParser::CommonDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleCommonDecl;
}

void CommonDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void CommonDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

CommonDeclParser::CommonDeclContext* CommonDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, CommonDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CommonDeclParser::TypeID)
      | (1ULL << CommonDeclParser::AttributeID)
      | (1ULL << CommonDeclParser::SignalID))) != 0)) {
      setState(147);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CommonDeclParser::TypeID: {
          setState(144);
          typeDefDecl();
          break;
        }

        case CommonDeclParser::AttributeID: {
          setState(145);
          attributeDecl();
          break;
        }

        case CommonDeclParser::SignalID: {
          setState(146);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(151);
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

CommonDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::ImportPathBodyContext* CommonDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<CommonDeclParser::ImportPathBodyContext>(0);
}

CommonDeclParser::ImportPathDeclContext* CommonDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<CommonDeclParser::ImportPathDeclContext>(0);
}


size_t CommonDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleImportPathDecl;
}

void CommonDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void CommonDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

CommonDeclParser::ImportPathDeclContext* CommonDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, CommonDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(152);
      importPathBody();
      setState(153);
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

CommonDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(CommonDeclParser::ImportID, 0);
}

tree::TerminalNode* CommonDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(CommonDeclParser::LESSTHAN, 0);
}

CommonDeclParser::ImportFileBodyContext* CommonDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<CommonDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* CommonDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(CommonDeclParser::GREATERTHAN, 0);
}

CommonDeclParser::ImportAsContext* CommonDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<CommonDeclParser::ImportAsContext>(0);
}


size_t CommonDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return CommonDeclParser::RuleImportPathBody;
}

void CommonDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void CommonDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

CommonDeclParser::ImportPathBodyContext* CommonDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 12, CommonDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(CommonDeclParser::ImportID);
    setState(159);
    match(CommonDeclParser::LESSTHAN);
    setState(160);
    importFileBody();
    setState(161);
    match(CommonDeclParser::GREATERTHAN);
    setState(162);
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

CommonDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommonDeclParser::ContextIDContext *> CommonDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<CommonDeclParser::ContextIDContext>();
}

CommonDeclParser::ContextIDContext* CommonDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<CommonDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* CommonDeclParser::ImportFileBodyContext::DOT() {
  return getToken(CommonDeclParser::DOT, 0);
}

tree::TerminalNode* CommonDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(CommonDeclParser::RANGE, 0);
}

tree::TerminalNode* CommonDeclParser::ImportFileBodyContext::DIV() {
  return getToken(CommonDeclParser::DIV, 0);
}

CommonDeclParser::ImportFileBodyContext* CommonDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<CommonDeclParser::ImportFileBodyContext>(0);
}


size_t CommonDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return CommonDeclParser::RuleImportFileBody;
}

void CommonDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void CommonDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

CommonDeclParser::ImportFileBodyContext* CommonDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 14, CommonDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(175);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(164);
      contextID();
      setState(165);
      match(CommonDeclParser::DOT);
      setState(166);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      match(CommonDeclParser::RANGE);
      setState(169);
      match(CommonDeclParser::DIV);
      setState(170);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(171);
      contextID();
      setState(172);
      match(CommonDeclParser::DIV);
      setState(173);
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

CommonDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ImportAsContext::AsID() {
  return getToken(CommonDeclParser::AsID, 0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::ImportAsContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}


size_t CommonDeclParser::ImportAsContext::getRuleIndex() const {
  return CommonDeclParser::RuleImportAs;
}

void CommonDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void CommonDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

CommonDeclParser::ImportAsContext* CommonDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 16, CommonDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(177);
        match(CommonDeclParser::AsID);
        setState(178);
        contextID();
        break;
      }

      case CommonDeclParser::ImportID: {
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

CommonDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(CommonDeclParser::TypeID, 0);
}

CommonDeclParser::TypeDeclContext* CommonDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<CommonDeclParser::TypeDeclContext>(0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* CommonDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}


size_t CommonDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleTypeDefDecl;
}

void CommonDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void CommonDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

CommonDeclParser::TypeDefDeclContext* CommonDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, CommonDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(CommonDeclParser::TypeID);
    setState(183);
    typeDecl();
    setState(184);
    contextID();
    setState(185);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

CommonDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::IntTypeDeclContext* CommonDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<CommonDeclParser::IntTypeDeclContext>(0);
}

CommonDeclParser::RealTypeDeclContext* CommonDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<CommonDeclParser::RealTypeDeclContext>(0);
}

CommonDeclParser::EnumTypeDeclContext* CommonDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<CommonDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* CommonDeclParser::TypeDeclContext::BoolID() {
  return getToken(CommonDeclParser::BoolID, 0);
}

tree::TerminalNode* CommonDeclParser::TypeDeclContext::StringID() {
  return getToken(CommonDeclParser::StringID, 0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}


size_t CommonDeclParser::TypeDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleTypeDecl;
}

void CommonDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void CommonDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

CommonDeclParser::TypeDeclContext* CommonDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, CommonDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(193);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(187);
        intTypeDecl();
        break;
      }

      case CommonDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(188);
        realTypeDecl();
        break;
      }

      case CommonDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(189);
        enumTypeDecl();
        break;
      }

      case CommonDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(190);
        match(CommonDeclParser::BoolID);
        break;
      }

      case CommonDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(191);
        match(CommonDeclParser::StringID);
        break;
      }

      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(192);
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

CommonDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::IntTypeDeclContext::IntID() {
  return getToken(CommonDeclParser::IntID, 0);
}

tree::TerminalNode* CommonDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> CommonDeclParser::IntTypeDeclContext::INT() {
  return getTokens(CommonDeclParser::INT);
}

tree::TerminalNode* CommonDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(CommonDeclParser::INT, i);
}

tree::TerminalNode* CommonDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(CommonDeclParser::RANGE, 0);
}

tree::TerminalNode* CommonDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}


size_t CommonDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleIntTypeDecl;
}

void CommonDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void CommonDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

CommonDeclParser::IntTypeDeclContext* CommonDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, CommonDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(CommonDeclParser::IntID);
    setState(202);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::LPAREN: {
        setState(196);
        match(CommonDeclParser::LPAREN);
        setState(197);
        match(CommonDeclParser::INT);
        setState(198);
        match(CommonDeclParser::RANGE);
        setState(199);
        match(CommonDeclParser::INT);
        setState(200);
        match(CommonDeclParser::RPAREN);
        break;
      }

      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::ID: {
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

CommonDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::RealTypeDeclContext::RealID() {
  return getToken(CommonDeclParser::RealID, 0);
}

tree::TerminalNode* CommonDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> CommonDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(CommonDeclParser::REAL);
}

tree::TerminalNode* CommonDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(CommonDeclParser::REAL, i);
}

tree::TerminalNode* CommonDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(CommonDeclParser::RANGE, 0);
}

tree::TerminalNode* CommonDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}


size_t CommonDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleRealTypeDecl;
}

void CommonDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void CommonDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

CommonDeclParser::RealTypeDeclContext* CommonDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, CommonDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    match(CommonDeclParser::RealID);
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::LPAREN: {
        setState(205);
        match(CommonDeclParser::LPAREN);
        setState(206);
        match(CommonDeclParser::REAL);
        setState(207);
        match(CommonDeclParser::RANGE);
        setState(208);
        match(CommonDeclParser::REAL);
        setState(209);
        match(CommonDeclParser::RPAREN);
        break;
      }

      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::ID: {
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

CommonDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(CommonDeclParser::EnumID, 0);
}

tree::TerminalNode* CommonDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

std::vector<CommonDeclParser::ContextIDContext *> CommonDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<CommonDeclParser::ContextIDContext>();
}

CommonDeclParser::ContextIDContext* CommonDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<CommonDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* CommonDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> CommonDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(CommonDeclParser::COMMA);
}

tree::TerminalNode* CommonDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(CommonDeclParser::COMMA, i);
}


size_t CommonDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleEnumTypeDecl;
}

void CommonDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void CommonDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

CommonDeclParser::EnumTypeDeclContext* CommonDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 26, CommonDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(CommonDeclParser::EnumID);
    setState(214);
    match(CommonDeclParser::LPAREN);
    setState(215);
    contextID();
    setState(220);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommonDeclParser::COMMA) {
      setState(216);
      match(CommonDeclParser::COMMA);
      setState(217);
      contextID();
      setState(222);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(223);
    match(CommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

CommonDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(CommonDeclParser::AttributeID, 0);
}

CommonDeclParser::TypeDeclContext* CommonDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<CommonDeclParser::TypeDeclContext>(0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* CommonDeclParser::AttributeDeclContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}

tree::TerminalNode* CommonDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(CommonDeclParser::ASSIGN, 0);
}

CommonDeclParser::LiteralValueContext* CommonDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<CommonDeclParser::LiteralValueContext>(0);
}


size_t CommonDeclParser::AttributeDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleAttributeDecl;
}

void CommonDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void CommonDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

CommonDeclParser::AttributeDeclContext* CommonDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, CommonDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(CommonDeclParser::AttributeID);
    setState(226);
    typeDecl();
    setState(227);
    contextID();
    setState(230);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CommonDeclParser::ASSIGN) {
      setState(228);
      match(CommonDeclParser::ASSIGN);
      setState(229);
      literalValue();
    }
    setState(232);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

CommonDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::LiteralValueContext::INT() {
  return getToken(CommonDeclParser::INT, 0);
}

tree::TerminalNode* CommonDeclParser::LiteralValueContext::REAL() {
  return getToken(CommonDeclParser::REAL, 0);
}

tree::TerminalNode* CommonDeclParser::LiteralValueContext::STRING() {
  return getToken(CommonDeclParser::STRING, 0);
}

tree::TerminalNode* CommonDeclParser::LiteralValueContext::TrueID() {
  return getToken(CommonDeclParser::TrueID, 0);
}

tree::TerminalNode* CommonDeclParser::LiteralValueContext::FalseID() {
  return getToken(CommonDeclParser::FalseID, 0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}


size_t CommonDeclParser::LiteralValueContext::getRuleIndex() const {
  return CommonDeclParser::RuleLiteralValue;
}

void CommonDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void CommonDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

CommonDeclParser::LiteralValueContext* CommonDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 30, CommonDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(240);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(234);
        match(CommonDeclParser::INT);
        break;
      }

      case CommonDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(235);
        match(CommonDeclParser::REAL);
        break;
      }

      case CommonDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(236);
        match(CommonDeclParser::STRING);
        break;
      }

      case CommonDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(237);
        match(CommonDeclParser::TrueID);
        break;
      }

      case CommonDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(238);
        match(CommonDeclParser::FalseID);
        break;
      }

      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(239);
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

CommonDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::TriggerDeclContext* CommonDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<CommonDeclParser::TriggerDeclContext>(0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}


size_t CommonDeclParser::SignalParamNameContext::getRuleIndex() const {
  return CommonDeclParser::RuleSignalParamName;
}

void CommonDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void CommonDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

CommonDeclParser::SignalParamNameContext* CommonDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 32, CommonDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    triggerDecl();
    setState(243);
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

CommonDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::ContextIDContext* CommonDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}

CommonDeclParser::ThisDeclContext* CommonDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<CommonDeclParser::ThisDeclContext>(0);
}


size_t CommonDeclParser::AttributeNameContext::getRuleIndex() const {
  return CommonDeclParser::RuleAttributeName;
}

void CommonDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void CommonDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

CommonDeclParser::AttributeNameContext* CommonDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 34, CommonDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::ThisID: {
        setState(245);
        thisDecl();
        break;
      }

      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(249);
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

CommonDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ToPortNameContext::ToID() {
  return getToken(CommonDeclParser::ToID, 0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}


size_t CommonDeclParser::ToPortNameContext::getRuleIndex() const {
  return CommonDeclParser::RuleToPortName;
}

void CommonDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void CommonDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

CommonDeclParser::ToPortNameContext* CommonDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 36, CommonDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(CommonDeclParser::ToID);
    setState(252);
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

CommonDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::AttributeNameContext* CommonDeclParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<CommonDeclParser::AttributeNameContext>(0);
}

tree::TerminalNode* CommonDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(CommonDeclParser::ASSIGN, 0);
}

CommonDeclParser::ExpressionContext* CommonDeclParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<CommonDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* CommonDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}


size_t CommonDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleAttributeAssignStatement;
}

void CommonDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void CommonDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

CommonDeclParser::AttributeAssignStatementContext* CommonDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, CommonDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    attributeName();
    setState(255);
    match(CommonDeclParser::ASSIGN);
    setState(256);
    expression();
    setState(257);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

CommonDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::TypeDeclContext* CommonDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<CommonDeclParser::TypeDeclContext>(0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* CommonDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}

tree::TerminalNode* CommonDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(CommonDeclParser::ASSIGN, 0);
}

CommonDeclParser::ExpressionContext* CommonDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<CommonDeclParser::ExpressionContext>(0);
}


size_t CommonDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleLocalAssignStatement;
}

void CommonDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void CommonDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

CommonDeclParser::LocalAssignStatementContext* CommonDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, CommonDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    typeDecl();
    setState(260);
    contextID();
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::ASSIGN: {
        setState(261);
        match(CommonDeclParser::ASSIGN);
        setState(262);
        expression();
        break;
      }

      case CommonDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(266);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

CommonDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::SendToStatementContext::SendID() {
  return getToken(CommonDeclParser::SendID, 0);
}

CommonDeclParser::SignalSendContext* CommonDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<CommonDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* CommonDeclParser::SendToStatementContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}

CommonDeclParser::ToPortNameContext* CommonDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<CommonDeclParser::ToPortNameContext>(0);
}


size_t CommonDeclParser::SendToStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleSendToStatement;
}

void CommonDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void CommonDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

CommonDeclParser::SendToStatementContext* CommonDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, CommonDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(CommonDeclParser::SendID);
    setState(269);
    signalSend();
    setState(272);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::ToID: {
        setState(270);
        toPortName();
        break;
      }

      case CommonDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(274);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

CommonDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::AttributeAssignStatementContext* CommonDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<CommonDeclParser::AttributeAssignStatementContext>(0);
}

CommonDeclParser::SendToStatementContext* CommonDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<CommonDeclParser::SendToStatementContext>(0);
}


size_t CommonDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return CommonDeclParser::RuleSingleAssignment;
}

void CommonDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void CommonDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

CommonDeclParser::SingleAssignmentContext* CommonDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 44, CommonDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::ThisID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(276);
        attributeAssignStatement();
        break;
      }

      case CommonDeclParser::SendID: {
        enterOuterAlt(_localctx, 2);
        setState(277);
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

CommonDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(CommonDeclParser::LBRACE, 0);
}

tree::TerminalNode* CommonDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(CommonDeclParser::RBRACE, 0);
}

std::vector<CommonDeclParser::SingleAssignmentContext *> CommonDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<CommonDeclParser::SingleAssignmentContext>();
}

CommonDeclParser::SingleAssignmentContext* CommonDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<CommonDeclParser::SingleAssignmentContext>(i);
}


size_t CommonDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return CommonDeclParser::RuleMultiAssignment;
}

void CommonDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void CommonDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

CommonDeclParser::MultiAssignmentContext* CommonDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 46, CommonDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(CommonDeclParser::LBRACE);
    setState(284);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CommonDeclParser::NameID)
      | (1ULL << CommonDeclParser::LabelID)
      | (1ULL << CommonDeclParser::EnabledID)
      | (1ULL << CommonDeclParser::TypeID)
      | (1ULL << CommonDeclParser::ThisID)
      | (1ULL << CommonDeclParser::AttributeID)
      | (1ULL << CommonDeclParser::SignalID)
      | (1ULL << CommonDeclParser::PortID)
      | (1ULL << CommonDeclParser::ImportID)
      | (1ULL << CommonDeclParser::FromID)
      | (1ULL << CommonDeclParser::ToID)
      | (1ULL << CommonDeclParser::SendID)
      | (1ULL << CommonDeclParser::AsID)
      | (1ULL << CommonDeclParser::ID))) != 0)) {
      setState(281);
      singleAssignment();
      setState(286);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(287);
    match(CommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

CommonDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::SignalDeclContext::SignalID() {
  return getToken(CommonDeclParser::SignalID, 0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* CommonDeclParser::SignalDeclContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}

tree::TerminalNode* CommonDeclParser::SignalDeclContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

tree::TerminalNode* CommonDeclParser::SignalDeclContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}

std::vector<CommonDeclParser::ParamDeclContext *> CommonDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<CommonDeclParser::ParamDeclContext>();
}

CommonDeclParser::ParamDeclContext* CommonDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<CommonDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> CommonDeclParser::SignalDeclContext::COMMA() {
  return getTokens(CommonDeclParser::COMMA);
}

tree::TerminalNode* CommonDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(CommonDeclParser::COMMA, i);
}


size_t CommonDeclParser::SignalDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleSignalDecl;
}

void CommonDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void CommonDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

CommonDeclParser::SignalDeclContext* CommonDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 48, CommonDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(CommonDeclParser::SignalID);
    setState(290);
    contextID();
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::LPAREN: {
        setState(291);
        match(CommonDeclParser::LPAREN);
        setState(301);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CommonDeclParser::NameID:
          case CommonDeclParser::LabelID:
          case CommonDeclParser::EnabledID:
          case CommonDeclParser::TypeID:
          case CommonDeclParser::IntID:
          case CommonDeclParser::RealID:
          case CommonDeclParser::BoolID:
          case CommonDeclParser::StringID:
          case CommonDeclParser::EnumID:
          case CommonDeclParser::AttributeID:
          case CommonDeclParser::SignalID:
          case CommonDeclParser::PortID:
          case CommonDeclParser::ImportID:
          case CommonDeclParser::FromID:
          case CommonDeclParser::ToID:
          case CommonDeclParser::AsID:
          case CommonDeclParser::ID: {
            setState(292);
            paramDecl();
            setState(297);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == CommonDeclParser::COMMA) {
              setState(293);
              match(CommonDeclParser::COMMA);
              setState(294);
              paramDecl();
              setState(299);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case CommonDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(303);
        match(CommonDeclParser::RPAREN);
        break;
      }

      case CommonDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(307);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

CommonDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::TypeDeclContext* CommonDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<CommonDeclParser::TypeDeclContext>(0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}


size_t CommonDeclParser::ParamDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleParamDecl;
}

void CommonDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void CommonDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

CommonDeclParser::ParamDeclContext* CommonDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 50, CommonDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    typeDecl();
    setState(310);
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

CommonDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(CommonDeclParser::FunctionID, 0);
}

CommonDeclParser::TypeDeclContext* CommonDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<CommonDeclParser::TypeDeclContext>(0);
}

CommonDeclParser::IdPathContext* CommonDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<CommonDeclParser::IdPathContext>(0);
}

tree::TerminalNode* CommonDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

tree::TerminalNode* CommonDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}

CommonDeclParser::NestedStatementBodyContext* CommonDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<CommonDeclParser::NestedStatementBodyContext>(0);
}

CommonDeclParser::FunctionParametersContext* CommonDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<CommonDeclParser::FunctionParametersContext>(0);
}


size_t CommonDeclParser::FunctionDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleFunctionDecl;
}

void CommonDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void CommonDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

CommonDeclParser::FunctionDeclContext* CommonDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, CommonDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(CommonDeclParser::FunctionID);
    setState(313);
    typeDecl();
    setState(314);
    idPath();
    setState(315);
    match(CommonDeclParser::LPAREN);
    setState(318);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::IntID:
      case CommonDeclParser::RealID:
      case CommonDeclParser::BoolID:
      case CommonDeclParser::StringID:
      case CommonDeclParser::EnumID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::ID: {
        setState(316);
        functionParameters();
        break;
      }

      case CommonDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(320);
    match(CommonDeclParser::RPAREN);
    setState(321);
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

CommonDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommonDeclParser::ParamDeclContext *> CommonDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<CommonDeclParser::ParamDeclContext>();
}

CommonDeclParser::ParamDeclContext* CommonDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<CommonDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> CommonDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(CommonDeclParser::COMMA);
}

tree::TerminalNode* CommonDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(CommonDeclParser::COMMA, i);
}


size_t CommonDeclParser::FunctionParametersContext::getRuleIndex() const {
  return CommonDeclParser::RuleFunctionParameters;
}

void CommonDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void CommonDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

CommonDeclParser::FunctionParametersContext* CommonDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 54, CommonDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    paramDecl();
    setState(328);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommonDeclParser::COMMA) {
      setState(324);
      match(CommonDeclParser::COMMA);
      setState(325);
      paramDecl();
      setState(330);
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

CommonDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::IdPathContext* CommonDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<CommonDeclParser::IdPathContext>(0);
}

tree::TerminalNode* CommonDeclParser::FunctionCallContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

CommonDeclParser::FunctionCallBodyContext* CommonDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<CommonDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* CommonDeclParser::FunctionCallContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}


size_t CommonDeclParser::FunctionCallContext::getRuleIndex() const {
  return CommonDeclParser::RuleFunctionCall;
}

void CommonDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void CommonDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

CommonDeclParser::FunctionCallContext* CommonDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 56, CommonDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    idPath();
    setState(332);
    match(CommonDeclParser::LPAREN);
    setState(333);
    functionCallBody();
    setState(334);
    match(CommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

CommonDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::FunctionCallBodyOptionalContext* CommonDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<CommonDeclParser::FunctionCallBodyOptionalContext>(0);
}

CommonDeclParser::LiteralValueContext* CommonDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<CommonDeclParser::LiteralValueContext>(0);
}

CommonDeclParser::SignalParamNameContext* CommonDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<CommonDeclParser::SignalParamNameContext>(0);
}

CommonDeclParser::AttributeNameContext* CommonDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<CommonDeclParser::AttributeNameContext>(0);
}

CommonDeclParser::FunctionCallContext* CommonDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<CommonDeclParser::FunctionCallContext>(0);
}


size_t CommonDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return CommonDeclParser::RuleFunctionCallBody;
}

void CommonDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void CommonDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

CommonDeclParser::FunctionCallBodyContext* CommonDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 58, CommonDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(336);
      literalValue();
      break;
    }

    case 2: {
      setState(337);
      signalParamName();
      break;
    }

    case 3: {
      setState(338);
      attributeName();
      break;
    }

    case 4: {
      setState(339);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(343);
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

CommonDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(CommonDeclParser::COMMA, 0);
}

CommonDeclParser::FunctionCallBodyContext* CommonDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<CommonDeclParser::FunctionCallBodyContext>(0);
}


size_t CommonDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return CommonDeclParser::RuleFunctionCallBodyOptional;
}

void CommonDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void CommonDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

CommonDeclParser::FunctionCallBodyOptionalContext* CommonDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 60, CommonDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(348);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(345);
        match(CommonDeclParser::COMMA);
        setState(346);
        functionCallBody();
        break;
      }

      case CommonDeclParser::RPAREN: {
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

//----------------- ContextIDContext ------------------------------------------------------------------

CommonDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::ID() {
  return getToken(CommonDeclParser::ID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::NameID() {
  return getToken(CommonDeclParser::NameID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::LabelID() {
  return getToken(CommonDeclParser::LabelID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::EnabledID() {
  return getToken(CommonDeclParser::EnabledID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::TypeID() {
  return getToken(CommonDeclParser::TypeID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::AttributeID() {
  return getToken(CommonDeclParser::AttributeID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::SignalID() {
  return getToken(CommonDeclParser::SignalID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::PortID() {
  return getToken(CommonDeclParser::PortID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::ImportID() {
  return getToken(CommonDeclParser::ImportID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::FromID() {
  return getToken(CommonDeclParser::FromID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::ToID() {
  return getToken(CommonDeclParser::ToID, 0);
}

tree::TerminalNode* CommonDeclParser::ContextIDContext::AsID() {
  return getToken(CommonDeclParser::AsID, 0);
}


size_t CommonDeclParser::ContextIDContext::getRuleIndex() const {
  return CommonDeclParser::RuleContextID;
}

void CommonDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void CommonDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 62, CommonDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CommonDeclParser::NameID)
      | (1ULL << CommonDeclParser::LabelID)
      | (1ULL << CommonDeclParser::EnabledID)
      | (1ULL << CommonDeclParser::TypeID)
      | (1ULL << CommonDeclParser::AttributeID)
      | (1ULL << CommonDeclParser::SignalID)
      | (1ULL << CommonDeclParser::PortID)
      | (1ULL << CommonDeclParser::ImportID)
      | (1ULL << CommonDeclParser::FromID)
      | (1ULL << CommonDeclParser::ToID)
      | (1ULL << CommonDeclParser::AsID)
      | (1ULL << CommonDeclParser::ID))) != 0))) {
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

//----------------- TriggerDeclContext ------------------------------------------------------------------

CommonDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::TriggerDeclContext::DOT() {
  return getToken(CommonDeclParser::DOT, 0);
}

tree::TerminalNode* CommonDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(CommonDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* CommonDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(CommonDeclParser::TriggerID, 0);
}


size_t CommonDeclParser::TriggerDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleTriggerDecl;
}

void CommonDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void CommonDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

CommonDeclParser::TriggerDeclContext* CommonDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 64, CommonDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    _la = _input->LA(1);
    if (!(_la == CommonDeclParser::TriggerID

    || _la == CommonDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(353);
    match(CommonDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

CommonDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ThisDeclContext::ThisID() {
  return getToken(CommonDeclParser::ThisID, 0);
}

tree::TerminalNode* CommonDeclParser::ThisDeclContext::DOT() {
  return getToken(CommonDeclParser::DOT, 0);
}


size_t CommonDeclParser::ThisDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleThisDecl;
}

void CommonDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void CommonDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

CommonDeclParser::ThisDeclContext* CommonDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, CommonDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    match(CommonDeclParser::ThisID);
    setState(356);
    match(CommonDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

CommonDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::PortDeclContext::PortID() {
  return getToken(CommonDeclParser::PortID, 0);
}

std::vector<CommonDeclParser::ContextIDContext *> CommonDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<CommonDeclParser::ContextIDContext>();
}

CommonDeclParser::ContextIDContext* CommonDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<CommonDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* CommonDeclParser::PortDeclContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> CommonDeclParser::PortDeclContext::COMMA() {
  return getTokens(CommonDeclParser::COMMA);
}

tree::TerminalNode* CommonDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(CommonDeclParser::COMMA, i);
}


size_t CommonDeclParser::PortDeclContext::getRuleIndex() const {
  return CommonDeclParser::RulePortDecl;
}

void CommonDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void CommonDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

CommonDeclParser::PortDeclContext* CommonDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 68, CommonDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    match(CommonDeclParser::PortID);
    setState(359);
    contextID();
    setState(364);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommonDeclParser::COMMA) {
      setState(360);
      match(CommonDeclParser::COMMA);
      setState(361);
      contextID();
      setState(366);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(367);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

CommonDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::NameDeclContext::NameID() {
  return getToken(CommonDeclParser::NameID, 0);
}

tree::TerminalNode* CommonDeclParser::NameDeclContext::COLON() {
  return getToken(CommonDeclParser::COLON, 0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::NameDeclContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* CommonDeclParser::NameDeclContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}


size_t CommonDeclParser::NameDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleNameDecl;
}

void CommonDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void CommonDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

CommonDeclParser::NameDeclContext* CommonDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 70, CommonDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(CommonDeclParser::NameID);
    setState(370);
    match(CommonDeclParser::COLON);
    setState(371);
    contextID();
    setState(372);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

CommonDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommonDeclParser::ContextIDContext *> CommonDeclParser::IdPathContext::contextID() {
  return getRuleContexts<CommonDeclParser::ContextIDContext>();
}

CommonDeclParser::ContextIDContext* CommonDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<CommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> CommonDeclParser::IdPathContext::DOT() {
  return getTokens(CommonDeclParser::DOT);
}

tree::TerminalNode* CommonDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(CommonDeclParser::DOT, i);
}


size_t CommonDeclParser::IdPathContext::getRuleIndex() const {
  return CommonDeclParser::RuleIdPath;
}

void CommonDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void CommonDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

CommonDeclParser::IdPathContext* CommonDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 72, CommonDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    contextID();
    setState(379);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommonDeclParser::DOT) {
      setState(375);
      match(CommonDeclParser::DOT);
      setState(376);
      contextID();
      setState(381);
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

CommonDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::StatementBodyContext* CommonDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<CommonDeclParser::StatementBodyContext>(0);
}

CommonDeclParser::NestedStatementBodyContext* CommonDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<CommonDeclParser::NestedStatementBodyContext>(0);
}


size_t CommonDeclParser::StatementDeclContext::getRuleIndex() const {
  return CommonDeclParser::RuleStatementDecl;
}

void CommonDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void CommonDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

CommonDeclParser::StatementDeclContext* CommonDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 74, CommonDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::IntID:
      case CommonDeclParser::RealID:
      case CommonDeclParser::BoolID:
      case CommonDeclParser::StringID:
      case CommonDeclParser::ThisID:
      case CommonDeclParser::ReturnID:
      case CommonDeclParser::EnumID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::SendID:
      case CommonDeclParser::SwitchID:
      case CommonDeclParser::IfID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::BREAK:
      case CommonDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(382);
        statementBody();
        break;
      }

      case CommonDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(383);
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

CommonDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::FunctionCallStatementContext* CommonDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<CommonDeclParser::FunctionCallStatementContext>(0);
}

CommonDeclParser::AttributeAssignStatementContext* CommonDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<CommonDeclParser::AttributeAssignStatementContext>(0);
}

CommonDeclParser::SwitchStatementContext* CommonDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<CommonDeclParser::SwitchStatementContext>(0);
}

CommonDeclParser::ConditionalStatementContext* CommonDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<CommonDeclParser::ConditionalStatementContext>(0);
}

CommonDeclParser::LocalAssignStatementContext* CommonDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<CommonDeclParser::LocalAssignStatementContext>(0);
}

CommonDeclParser::SendToStatementContext* CommonDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<CommonDeclParser::SendToStatementContext>(0);
}

CommonDeclParser::BreakStatementContext* CommonDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<CommonDeclParser::BreakStatementContext>(0);
}

CommonDeclParser::ReturnStatementContext* CommonDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<CommonDeclParser::ReturnStatementContext>(0);
}


size_t CommonDeclParser::StatementBodyContext::getRuleIndex() const {
  return CommonDeclParser::RuleStatementBody;
}

void CommonDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void CommonDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

CommonDeclParser::StatementBodyContext* CommonDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 76, CommonDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(386);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(387);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(388);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(389);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(390);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(391);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(392);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(393);
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

CommonDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::FunctionCallContext* CommonDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<CommonDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* CommonDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}


size_t CommonDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleFunctionCallStatement;
}

void CommonDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void CommonDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

CommonDeclParser::FunctionCallStatementContext* CommonDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 78, CommonDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    functionCall();
    setState(397);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

CommonDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(CommonDeclParser::LBRACE, 0);
}

tree::TerminalNode* CommonDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(CommonDeclParser::RBRACE, 0);
}

std::vector<CommonDeclParser::StatementBodyContext *> CommonDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<CommonDeclParser::StatementBodyContext>();
}

CommonDeclParser::StatementBodyContext* CommonDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<CommonDeclParser::StatementBodyContext>(i);
}


size_t CommonDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return CommonDeclParser::RuleNestedStatementBody;
}

void CommonDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void CommonDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

CommonDeclParser::NestedStatementBodyContext* CommonDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 80, CommonDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(CommonDeclParser::LBRACE);
    setState(403);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CommonDeclParser::NameID)
      | (1ULL << CommonDeclParser::LabelID)
      | (1ULL << CommonDeclParser::EnabledID)
      | (1ULL << CommonDeclParser::TypeID)
      | (1ULL << CommonDeclParser::IntID)
      | (1ULL << CommonDeclParser::RealID)
      | (1ULL << CommonDeclParser::BoolID)
      | (1ULL << CommonDeclParser::StringID)
      | (1ULL << CommonDeclParser::ThisID)
      | (1ULL << CommonDeclParser::ReturnID)
      | (1ULL << CommonDeclParser::EnumID)
      | (1ULL << CommonDeclParser::AttributeID)
      | (1ULL << CommonDeclParser::SignalID)
      | (1ULL << CommonDeclParser::PortID)
      | (1ULL << CommonDeclParser::ImportID)
      | (1ULL << CommonDeclParser::FromID)
      | (1ULL << CommonDeclParser::ToID)
      | (1ULL << CommonDeclParser::SendID)
      | (1ULL << CommonDeclParser::SwitchID)
      | (1ULL << CommonDeclParser::IfID)
      | (1ULL << CommonDeclParser::AsID)
      | (1ULL << CommonDeclParser::BREAK)
      | (1ULL << CommonDeclParser::ID))) != 0)) {
      setState(400);
      statementBody();
      setState(405);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(406);
    match(CommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

CommonDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(CommonDeclParser::ReturnID, 0);
}

CommonDeclParser::OperationContext* CommonDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<CommonDeclParser::OperationContext>(0);
}

tree::TerminalNode* CommonDeclParser::ReturnStatementContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}


size_t CommonDeclParser::ReturnStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleReturnStatement;
}

void CommonDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void CommonDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

CommonDeclParser::ReturnStatementContext* CommonDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, CommonDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(CommonDeclParser::ReturnID);
    setState(409);
    operation();
    setState(410);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

CommonDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::BreakStatementContext::BREAK() {
  return getToken(CommonDeclParser::BREAK, 0);
}

tree::TerminalNode* CommonDeclParser::BreakStatementContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}


size_t CommonDeclParser::BreakStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleBreakStatement;
}

void CommonDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void CommonDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

CommonDeclParser::BreakStatementContext* CommonDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, CommonDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(CommonDeclParser::BREAK);
    setState(413);
    match(CommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

CommonDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::AtomContext* CommonDeclParser::OperationContext::atom() {
  return getRuleContext<CommonDeclParser::AtomContext>(0);
}

CommonDeclParser::OperationOptionalContext* CommonDeclParser::OperationContext::operationOptional() {
  return getRuleContext<CommonDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* CommonDeclParser::OperationContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

CommonDeclParser::OperationContext* CommonDeclParser::OperationContext::operation() {
  return getRuleContext<CommonDeclParser::OperationContext>(0);
}

tree::TerminalNode* CommonDeclParser::OperationContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}

tree::TerminalNode* CommonDeclParser::OperationContext::MINUS() {
  return getToken(CommonDeclParser::MINUS, 0);
}

tree::TerminalNode* CommonDeclParser::OperationContext::NotIdSymbol() {
  return getToken(CommonDeclParser::NotIdSymbol, 0);
}


size_t CommonDeclParser::OperationContext::getRuleIndex() const {
  return CommonDeclParser::RuleOperation;
}

void CommonDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void CommonDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

CommonDeclParser::OperationContext* CommonDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 86, CommonDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(426);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::TriggerID:
      case CommonDeclParser::MessageTrigger:
      case CommonDeclParser::ThisID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::TrueID:
      case CommonDeclParser::FalseID:
      case CommonDeclParser::INT:
      case CommonDeclParser::REAL:
      case CommonDeclParser::STRING:
      case CommonDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(415);
        atom();
        setState(416);
        operationOptional();
        break;
      }

      case CommonDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(418);
        match(CommonDeclParser::LPAREN);
        setState(419);
        operation();
        setState(420);
        match(CommonDeclParser::RPAREN);
        break;
      }

      case CommonDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(422);
        match(CommonDeclParser::MINUS);
        setState(423);
        operation();
        break;
      }

      case CommonDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(424);
        match(CommonDeclParser::NotIdSymbol);
        setState(425);
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

CommonDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::OperationContext* CommonDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<CommonDeclParser::OperationContext>(0);
}

tree::TerminalNode* CommonDeclParser::OperationOptionalContext::MULT() {
  return getToken(CommonDeclParser::MULT, 0);
}

tree::TerminalNode* CommonDeclParser::OperationOptionalContext::DIV() {
  return getToken(CommonDeclParser::DIV, 0);
}

tree::TerminalNode* CommonDeclParser::OperationOptionalContext::PLUS() {
  return getToken(CommonDeclParser::PLUS, 0);
}

tree::TerminalNode* CommonDeclParser::OperationOptionalContext::MINUS() {
  return getToken(CommonDeclParser::MINUS, 0);
}


size_t CommonDeclParser::OperationOptionalContext::getRuleIndex() const {
  return CommonDeclParser::RuleOperationOptional;
}

void CommonDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void CommonDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

CommonDeclParser::OperationOptionalContext* CommonDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 88, CommonDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(431);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::PLUS:
      case CommonDeclParser::MINUS:
      case CommonDeclParser::MULT:
      case CommonDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(428);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & ((1ULL << (CommonDeclParser::PLUS - 67))
          | (1ULL << (CommonDeclParser::MINUS - 67))
          | (1ULL << (CommonDeclParser::MULT - 67))
          | (1ULL << (CommonDeclParser::DIV - 67)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(429);
        operation();
        break;
      }

      case CommonDeclParser::NotIdSymbol:
      case CommonDeclParser::AndIdSymbol:
      case CommonDeclParser::OrIdSymbol:
      case CommonDeclParser::NotIdWord:
      case CommonDeclParser::AndIdWord:
      case CommonDeclParser::OrIdWord:
      case CommonDeclParser::ASSIGN:
      case CommonDeclParser::RPAREN:
      case CommonDeclParser::LESSTHAN:
      case CommonDeclParser::GREATERTHAN:
      case CommonDeclParser::SEMI: {
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

CommonDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ExpressionContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

CommonDeclParser::ExpressionContext* CommonDeclParser::ExpressionContext::expression() {
  return getRuleContext<CommonDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* CommonDeclParser::ExpressionContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}

CommonDeclParser::ExpressionOptionalContext* CommonDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<CommonDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* CommonDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(CommonDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionContext::NotIdWord() {
  return getToken(CommonDeclParser::NotIdWord, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionContext::MINUS() {
  return getToken(CommonDeclParser::MINUS, 0);
}

CommonDeclParser::OperationContext* CommonDeclParser::ExpressionContext::operation() {
  return getRuleContext<CommonDeclParser::OperationContext>(0);
}


size_t CommonDeclParser::ExpressionContext::getRuleIndex() const {
  return CommonDeclParser::RuleExpression;
}

void CommonDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CommonDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

CommonDeclParser::ExpressionContext* CommonDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 90, CommonDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(447);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(433);
      match(CommonDeclParser::LPAREN);
      setState(434);
      expression();
      setState(435);
      match(CommonDeclParser::RPAREN);
      setState(436);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(438);
      match(CommonDeclParser::NotIdSymbol);
      setState(439);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(440);
      match(CommonDeclParser::NotIdWord);
      setState(441);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(442);
      match(CommonDeclParser::MINUS);
      setState(443);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(444);
      operation();
      setState(445);
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

CommonDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::ExpressionContext* CommonDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<CommonDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(CommonDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(CommonDeclParser::OrIdWord, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(CommonDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(CommonDeclParser::AndIdWord, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(CommonDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> CommonDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(CommonDeclParser::ASSIGN);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(CommonDeclParser::ASSIGN, i);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(CommonDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(CommonDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* CommonDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(CommonDeclParser::GREATERTHAN, 0);
}


size_t CommonDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return CommonDeclParser::RuleExpressionOptional;
}

void CommonDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void CommonDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

CommonDeclParser::ExpressionOptionalContext* CommonDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 92, CommonDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(472);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::NotIdSymbol:
      case CommonDeclParser::AndIdSymbol:
      case CommonDeclParser::OrIdSymbol:
      case CommonDeclParser::NotIdWord:
      case CommonDeclParser::AndIdWord:
      case CommonDeclParser::OrIdWord:
      case CommonDeclParser::ASSIGN:
      case CommonDeclParser::LESSTHAN:
      case CommonDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(468);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CommonDeclParser::OrIdSymbol: {
            setState(449);
            match(CommonDeclParser::OrIdSymbol);
            break;
          }

          case CommonDeclParser::OrIdWord: {
            setState(450);
            match(CommonDeclParser::OrIdWord);
            break;
          }

          case CommonDeclParser::AndIdSymbol: {
            setState(451);
            match(CommonDeclParser::AndIdSymbol);
            break;
          }

          case CommonDeclParser::AndIdWord: {
            setState(452);
            match(CommonDeclParser::AndIdWord);
            break;
          }

          case CommonDeclParser::ASSIGN: {
            setState(453);
            match(CommonDeclParser::ASSIGN);
            setState(454);
            match(CommonDeclParser::ASSIGN);
            break;
          }

          case CommonDeclParser::NotIdSymbol: {
            setState(455);
            match(CommonDeclParser::NotIdSymbol);
            setState(456);
            match(CommonDeclParser::ASSIGN);
            break;
          }

          case CommonDeclParser::NotIdWord: {
            setState(457);
            match(CommonDeclParser::NotIdWord);
            break;
          }

          case CommonDeclParser::LESSTHAN: {
            setState(458);
            match(CommonDeclParser::LESSTHAN);
            setState(461);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case CommonDeclParser::ASSIGN: {
                setState(459);
                match(CommonDeclParser::ASSIGN);
                break;
              }

              case CommonDeclParser::NameID:
              case CommonDeclParser::LabelID:
              case CommonDeclParser::EnabledID:
              case CommonDeclParser::TypeID:
              case CommonDeclParser::TriggerID:
              case CommonDeclParser::MessageTrigger:
              case CommonDeclParser::ThisID:
              case CommonDeclParser::AttributeID:
              case CommonDeclParser::SignalID:
              case CommonDeclParser::PortID:
              case CommonDeclParser::ImportID:
              case CommonDeclParser::FromID:
              case CommonDeclParser::ToID:
              case CommonDeclParser::AsID:
              case CommonDeclParser::NotIdSymbol:
              case CommonDeclParser::NotIdWord:
              case CommonDeclParser::TrueID:
              case CommonDeclParser::FalseID:
              case CommonDeclParser::INT:
              case CommonDeclParser::REAL:
              case CommonDeclParser::STRING:
              case CommonDeclParser::ID:
              case CommonDeclParser::LPAREN:
              case CommonDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case CommonDeclParser::GREATERTHAN: {
            setState(463);
            match(CommonDeclParser::GREATERTHAN);
            setState(466);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case CommonDeclParser::ASSIGN: {
                setState(464);
                match(CommonDeclParser::ASSIGN);
                break;
              }

              case CommonDeclParser::NameID:
              case CommonDeclParser::LabelID:
              case CommonDeclParser::EnabledID:
              case CommonDeclParser::TypeID:
              case CommonDeclParser::TriggerID:
              case CommonDeclParser::MessageTrigger:
              case CommonDeclParser::ThisID:
              case CommonDeclParser::AttributeID:
              case CommonDeclParser::SignalID:
              case CommonDeclParser::PortID:
              case CommonDeclParser::ImportID:
              case CommonDeclParser::FromID:
              case CommonDeclParser::ToID:
              case CommonDeclParser::AsID:
              case CommonDeclParser::NotIdSymbol:
              case CommonDeclParser::NotIdWord:
              case CommonDeclParser::TrueID:
              case CommonDeclParser::FalseID:
              case CommonDeclParser::INT:
              case CommonDeclParser::REAL:
              case CommonDeclParser::STRING:
              case CommonDeclParser::ID:
              case CommonDeclParser::LPAREN:
              case CommonDeclParser::MINUS: {
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
        setState(470);
        expression();
        break;
      }

      case CommonDeclParser::RPAREN:
      case CommonDeclParser::SEMI: {
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

CommonDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::IfStatementContext* CommonDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<CommonDeclParser::IfStatementContext>(0);
}

CommonDeclParser::ElseStatementContext* CommonDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<CommonDeclParser::ElseStatementContext>(0);
}


size_t CommonDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleConditionalStatement;
}

void CommonDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void CommonDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

CommonDeclParser::ConditionalStatementContext* CommonDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, CommonDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(474);
    ifStatement();
    setState(477);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(475);
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

CommonDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::IfStatementContext::IfID() {
  return getToken(CommonDeclParser::IfID, 0);
}

CommonDeclParser::IfEuTContext* CommonDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<CommonDeclParser::IfEuTContext>(0);
}

CommonDeclParser::StatementDeclContext* CommonDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<CommonDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* CommonDeclParser::IfStatementContext::SEMI() {
  return getToken(CommonDeclParser::SEMI, 0);
}


size_t CommonDeclParser::IfStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleIfStatement;
}

void CommonDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void CommonDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

CommonDeclParser::IfStatementContext* CommonDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, CommonDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(CommonDeclParser::IfID);
    setState(480);
    ifEuT();
    setState(483);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::IntID:
      case CommonDeclParser::RealID:
      case CommonDeclParser::BoolID:
      case CommonDeclParser::StringID:
      case CommonDeclParser::ThisID:
      case CommonDeclParser::ReturnID:
      case CommonDeclParser::EnumID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::SendID:
      case CommonDeclParser::SwitchID:
      case CommonDeclParser::IfID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::BREAK:
      case CommonDeclParser::ID:
      case CommonDeclParser::LBRACE: {
        setState(481);
        statementDecl();
        break;
      }

      case CommonDeclParser::SEMI: {
        setState(482);
        match(CommonDeclParser::SEMI);
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

CommonDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::IfEuTContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

CommonDeclParser::ExpressionContext* CommonDeclParser::IfEuTContext::expression() {
  return getRuleContext<CommonDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* CommonDeclParser::IfEuTContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}


size_t CommonDeclParser::IfEuTContext::getRuleIndex() const {
  return CommonDeclParser::RuleIfEuT;
}

void CommonDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void CommonDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

CommonDeclParser::IfEuTContext* CommonDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 98, CommonDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    match(CommonDeclParser::LPAREN);
    setState(486);
    expression();
    setState(487);
    match(CommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

CommonDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::ElseStatementContext::ElseID() {
  return getToken(CommonDeclParser::ElseID, 0);
}

CommonDeclParser::StatementDeclContext* CommonDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<CommonDeclParser::StatementDeclContext>(0);
}


size_t CommonDeclParser::ElseStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleElseStatement;
}

void CommonDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void CommonDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

CommonDeclParser::ElseStatementContext* CommonDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 100, CommonDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
    match(CommonDeclParser::ElseID);
    setState(490);
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

CommonDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(CommonDeclParser::SwitchID, 0);
}

CommonDeclParser::SwitchPuTContext* CommonDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<CommonDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* CommonDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(CommonDeclParser::LBRACE, 0);
}

tree::TerminalNode* CommonDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(CommonDeclParser::RBRACE, 0);
}

CommonDeclParser::DefaultStatementContext* CommonDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<CommonDeclParser::DefaultStatementContext>(0);
}

std::vector<CommonDeclParser::CaseStatementContext *> CommonDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<CommonDeclParser::CaseStatementContext>();
}

CommonDeclParser::CaseStatementContext* CommonDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<CommonDeclParser::CaseStatementContext>(i);
}


size_t CommonDeclParser::SwitchStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleSwitchStatement;
}

void CommonDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void CommonDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

CommonDeclParser::SwitchStatementContext* CommonDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 102, CommonDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(492);
    match(CommonDeclParser::SwitchID);
    setState(493);
    switchPuT();
    setState(494);
    match(CommonDeclParser::LBRACE);
    setState(498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommonDeclParser::CaseID) {
      setState(495);
      caseStatement();
      setState(500);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(503);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::DefaultID: {
        setState(501);
        defaultStatement();
        break;
      }

      case CommonDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(505);
    match(CommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

CommonDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(CommonDeclParser::LPAREN, 0);
}

CommonDeclParser::ContextIDContext* CommonDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<CommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* CommonDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(CommonDeclParser::RPAREN, 0);
}


size_t CommonDeclParser::SwitchPuTContext::getRuleIndex() const {
  return CommonDeclParser::RuleSwitchPuT;
}

void CommonDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void CommonDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

CommonDeclParser::SwitchPuTContext* CommonDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 104, CommonDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    match(CommonDeclParser::LPAREN);
    setState(508);
    contextID();
    setState(509);
    match(CommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

CommonDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::CaseStatementContext::CaseID() {
  return getToken(CommonDeclParser::CaseID, 0);
}

CommonDeclParser::LiteralValueContext* CommonDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<CommonDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* CommonDeclParser::CaseStatementContext::COLON() {
  return getToken(CommonDeclParser::COLON, 0);
}

CommonDeclParser::NestedStatementBodyContext* CommonDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<CommonDeclParser::NestedStatementBodyContext>(0);
}

std::vector<CommonDeclParser::StatementBodyContext *> CommonDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<CommonDeclParser::StatementBodyContext>();
}

CommonDeclParser::StatementBodyContext* CommonDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<CommonDeclParser::StatementBodyContext>(i);
}


size_t CommonDeclParser::CaseStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleCaseStatement;
}

void CommonDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void CommonDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

CommonDeclParser::CaseStatementContext* CommonDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 106, CommonDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    match(CommonDeclParser::CaseID);
    setState(512);
    literalValue();
    setState(513);
    match(CommonDeclParser::COLON);
    setState(521);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::LBRACE: {
        setState(514);
        nestedStatementBody();
        break;
      }

      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::IntID:
      case CommonDeclParser::RealID:
      case CommonDeclParser::BoolID:
      case CommonDeclParser::StringID:
      case CommonDeclParser::ThisID:
      case CommonDeclParser::ReturnID:
      case CommonDeclParser::EnumID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::SendID:
      case CommonDeclParser::SwitchID:
      case CommonDeclParser::CaseID:
      case CommonDeclParser::DefaultID:
      case CommonDeclParser::IfID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::BREAK:
      case CommonDeclParser::ID:
      case CommonDeclParser::RBRACE: {
        setState(518);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CommonDeclParser::NameID)
          | (1ULL << CommonDeclParser::LabelID)
          | (1ULL << CommonDeclParser::EnabledID)
          | (1ULL << CommonDeclParser::TypeID)
          | (1ULL << CommonDeclParser::IntID)
          | (1ULL << CommonDeclParser::RealID)
          | (1ULL << CommonDeclParser::BoolID)
          | (1ULL << CommonDeclParser::StringID)
          | (1ULL << CommonDeclParser::ThisID)
          | (1ULL << CommonDeclParser::ReturnID)
          | (1ULL << CommonDeclParser::EnumID)
          | (1ULL << CommonDeclParser::AttributeID)
          | (1ULL << CommonDeclParser::SignalID)
          | (1ULL << CommonDeclParser::PortID)
          | (1ULL << CommonDeclParser::ImportID)
          | (1ULL << CommonDeclParser::FromID)
          | (1ULL << CommonDeclParser::ToID)
          | (1ULL << CommonDeclParser::SendID)
          | (1ULL << CommonDeclParser::SwitchID)
          | (1ULL << CommonDeclParser::IfID)
          | (1ULL << CommonDeclParser::AsID)
          | (1ULL << CommonDeclParser::BREAK)
          | (1ULL << CommonDeclParser::ID))) != 0)) {
          setState(515);
          statementBody();
          setState(520);
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

CommonDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommonDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(CommonDeclParser::DefaultID, 0);
}

tree::TerminalNode* CommonDeclParser::DefaultStatementContext::COLON() {
  return getToken(CommonDeclParser::COLON, 0);
}

CommonDeclParser::NestedStatementBodyContext* CommonDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<CommonDeclParser::NestedStatementBodyContext>(0);
}

std::vector<CommonDeclParser::StatementBodyContext *> CommonDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<CommonDeclParser::StatementBodyContext>();
}

CommonDeclParser::StatementBodyContext* CommonDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<CommonDeclParser::StatementBodyContext>(i);
}


size_t CommonDeclParser::DefaultStatementContext::getRuleIndex() const {
  return CommonDeclParser::RuleDefaultStatement;
}

void CommonDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void CommonDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

CommonDeclParser::DefaultStatementContext* CommonDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 108, CommonDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(523);
    match(CommonDeclParser::DefaultID);
    setState(524);
    match(CommonDeclParser::COLON);
    setState(532);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommonDeclParser::LBRACE: {
        setState(525);
        nestedStatementBody();
        break;
      }

      case CommonDeclParser::NameID:
      case CommonDeclParser::LabelID:
      case CommonDeclParser::EnabledID:
      case CommonDeclParser::TypeID:
      case CommonDeclParser::IntID:
      case CommonDeclParser::RealID:
      case CommonDeclParser::BoolID:
      case CommonDeclParser::StringID:
      case CommonDeclParser::ThisID:
      case CommonDeclParser::ReturnID:
      case CommonDeclParser::EnumID:
      case CommonDeclParser::AttributeID:
      case CommonDeclParser::SignalID:
      case CommonDeclParser::PortID:
      case CommonDeclParser::ImportID:
      case CommonDeclParser::FromID:
      case CommonDeclParser::ToID:
      case CommonDeclParser::SendID:
      case CommonDeclParser::SwitchID:
      case CommonDeclParser::IfID:
      case CommonDeclParser::AsID:
      case CommonDeclParser::BREAK:
      case CommonDeclParser::ID:
      case CommonDeclParser::RBRACE: {
        setState(529);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CommonDeclParser::NameID)
          | (1ULL << CommonDeclParser::LabelID)
          | (1ULL << CommonDeclParser::EnabledID)
          | (1ULL << CommonDeclParser::TypeID)
          | (1ULL << CommonDeclParser::IntID)
          | (1ULL << CommonDeclParser::RealID)
          | (1ULL << CommonDeclParser::BoolID)
          | (1ULL << CommonDeclParser::StringID)
          | (1ULL << CommonDeclParser::ThisID)
          | (1ULL << CommonDeclParser::ReturnID)
          | (1ULL << CommonDeclParser::EnumID)
          | (1ULL << CommonDeclParser::AttributeID)
          | (1ULL << CommonDeclParser::SignalID)
          | (1ULL << CommonDeclParser::PortID)
          | (1ULL << CommonDeclParser::ImportID)
          | (1ULL << CommonDeclParser::FromID)
          | (1ULL << CommonDeclParser::ToID)
          | (1ULL << CommonDeclParser::SendID)
          | (1ULL << CommonDeclParser::SwitchID)
          | (1ULL << CommonDeclParser::IfID)
          | (1ULL << CommonDeclParser::AsID)
          | (1ULL << CommonDeclParser::BREAK)
          | (1ULL << CommonDeclParser::ID))) != 0)) {
          setState(526);
          statementBody();
          setState(531);
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

CommonDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommonDeclParser::SignalParamNameContext* CommonDeclParser::AtomContext::signalParamName() {
  return getRuleContext<CommonDeclParser::SignalParamNameContext>(0);
}

CommonDeclParser::AttributeNameContext* CommonDeclParser::AtomContext::attributeName() {
  return getRuleContext<CommonDeclParser::AttributeNameContext>(0);
}

CommonDeclParser::FunctionCallContext* CommonDeclParser::AtomContext::functionCall() {
  return getRuleContext<CommonDeclParser::FunctionCallContext>(0);
}

CommonDeclParser::LiteralValueContext* CommonDeclParser::AtomContext::literalValue() {
  return getRuleContext<CommonDeclParser::LiteralValueContext>(0);
}


size_t CommonDeclParser::AtomContext::getRuleIndex() const {
  return CommonDeclParser::RuleAtom;
}

void CommonDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void CommonDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

CommonDeclParser::AtomContext* CommonDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 110, CommonDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(538);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(534);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(535);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(536);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(537);
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
std::vector<dfa::DFA> CommonDeclParser::_decisionToDFA;
atn::PredictionContextCache CommonDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CommonDeclParser::_atn;
std::vector<uint16_t> CommonDeclParser::_serializedATN;

std::vector<std::string> CommonDeclParser::_ruleNames = {
  "componentIdPath", "signalIdPath", "attributeIdPath", "signalSend", "commonDecl", 
  "importPathDecl", "importPathBody", "importFileBody", "importAs", "typeDefDecl", 
  "typeDecl", "intTypeDecl", "realTypeDecl", "enumTypeDecl", "attributeDecl", 
  "literalValue", "signalParamName", "attributeName", "toPortName", "attributeAssignStatement", 
  "localAssignStatement", "sendToStatement", "singleAssignment", "multiAssignment", 
  "signalDecl", "paramDecl", "functionDecl", "functionParameters", "functionCall", 
  "functionCallBody", "functionCallBodyOptional", "contextID", "triggerDecl", 
  "thisDecl", "portDecl", "nameDecl", "idPath", "statementDecl", "statementBody", 
  "functionCallStatement", "nestedStatementBody", "returnStatement", "breakStatement", 
  "operation", "operationOptional", "expression", "expressionOptional", 
  "conditionalStatement", "ifStatement", "ifEuT", "elseStatement", "switchStatement", 
  "switchPuT", "caseStatement", "defaultStatement", "atom"
};

std::vector<std::string> CommonDeclParser::_literalNames = {
  "", "", "'name'", "'label'", "'enabled'", "'Type'", "'int'", "'real'", 
  "'bool'", "'string'", "'trigger'", "'msg'", "'this'", "'return'", "'SignalTransition'", 
  "'TimeoutTransition'", "'enum'", "'Declaration'", "'description'", "'Attribute'", 
  "'Signal'", "'Port'", "'import'", "'from'", "'to'", "'send'", "'Function'", 
  "'switch'", "'case'", "'default'", "'if'", "'else'", "'as'", "'@'", "'!'", 
  "'&&'", "'||'", "'not'", "'and'", "'or'", "'true'", "'false'", "'break'", 
  "'='", "'<->'", "'->'", "'<-'", "'..'", "", "", "", "", "", "", "'('", 
  "')'", "'{'", "'}'", "'['", "']'", "'<'", "'>'", "':'", "';'", "','", 
  "'_'", "'.'", "'+'", "'-'", "'*'", "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> CommonDeclParser::_symbolicNames = {
  "", "IGNORE_NEWLINE", "NameID", "LabelID", "EnabledID", "TypeID", "IntID", 
  "RealID", "BoolID", "StringID", "TriggerID", "MessageTrigger", "ThisID", 
  "ReturnID", "SignalTransitionID", "TimeoutTransitionID", "EnumID", "DeclarationID", 
  "DescriptionID", "AttributeID", "SignalID", "PortID", "ImportID", "FromID", 
  "ToID", "SendID", "FunctionID", "SwitchID", "CaseID", "DefaultID", "IfID", 
  "ElseID", "AsID", "AtID", "NotIdSymbol", "AndIdSymbol", "OrIdSymbol", 
  "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", "FalseID", "BREAK", "ASSIGN", 
  "DoubleArrow", "RightArrow", "LeftArrow", "RANGE", "INT", "REAL", "STRING", 
  "ID", "LINE_COMMENT", "COMMENT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
  "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", "COLON", "SEMI", "COMMA", 
  "UNDER", "DOT", "PLUS", "MINUS", "MULT", "DIV", "PIPE", "REF", "CONST", 
  "NEWLINE", "WS"
};

dfa::Vocabulary CommonDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CommonDeclParser::_tokenNames;

CommonDeclParser::Initializer::Initializer() {
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
    0x3, 0x4d, 0x21f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x39, 0x9, 0x39, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x76, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x79, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x7e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x81, 0xb, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x87, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x8a, 0xb, 0x4, 0x5, 0x4, 0x8c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x96, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x99, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x9f, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0xb2, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xb7, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xc4, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x5, 0xd, 0xcd, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xd6, 0xa, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xdd, 0xa, 0xf, 0xc, 0xf, 
    0xe, 0xf, 0xe0, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xe9, 0xa, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0xf3, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x5, 0x13, 0xfa, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 
    0x16, 0x10b, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x113, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x119, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x7, 0x19, 0x11d, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x120, 0xb, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x12a, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 
    0x12d, 0xb, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x130, 0xa, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x5, 0x1a, 0x134, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x141, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x149, 0xa, 0x1d, 
    0xc, 0x1d, 0xe, 0x1d, 0x14c, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x5, 0x1f, 0x158, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x15f, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x16d, 0xa, 0x24, 
    0xc, 0x24, 0xe, 0x24, 0x170, 0xb, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x7, 0x26, 0x17c, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x17f, 0xb, 
    0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x183, 0xa, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x5, 0x28, 0x18d, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x194, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 
    0x197, 0xb, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x1ad, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x1b2, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x1c2, 
    0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x5, 0x30, 0x1d0, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 
    0x1d5, 0xa, 0x30, 0x5, 0x30, 0x1d7, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x5, 0x30, 0x1db, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 
    0x1e0, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 
    0x1e6, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 
    0x35, 0x1f3, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x1f6, 0xb, 0x35, 0x3, 
    0x35, 0x3, 0x35, 0x5, 0x35, 0x1fa, 0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x207, 0xa, 0x37, 0xc, 0x37, 
    0xe, 0x37, 0x20a, 0xb, 0x37, 0x5, 0x37, 0x20c, 0xa, 0x37, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x212, 0xa, 0x38, 0xc, 0x38, 
    0xe, 0x38, 0x215, 0xb, 0x38, 0x5, 0x38, 0x217, 0xa, 0x38, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x21d, 0xa, 0x39, 0x3, 0x39, 
    0x2, 0x2, 0x3a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
    0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x2, 0x5, 
    0x6, 0x2, 0x4, 0x7, 0x15, 0x1a, 0x22, 0x22, 0x35, 0x35, 0x3, 0x2, 0xc, 
    0xd, 0x3, 0x2, 0x45, 0x48, 0x2, 0x237, 0x2, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x97, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9e, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x10, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb8, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x22, 0xf4, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x26, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x100, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x118, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x32, 0x123, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x36, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x157, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x162, 0x3, 0x2, 0x2, 0x2, 0x44, 0x165, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x168, 0x3, 0x2, 0x2, 0x2, 0x48, 0x173, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x182, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x18c, 0x3, 0x2, 0x2, 0x2, 0x50, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x52, 0x191, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x56, 0x19e, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1b1, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1da, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x1ee, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x201, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x21c, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x77, 0x5, 0x40, 0x21, 0x2, 0x73, 0x74, 0x7, 0x44, 
    0x2, 0x2, 0x74, 0x76, 0x5, 0x40, 0x21, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x79, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x3, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7f, 0x5, 0x40, 0x21, 0x2, 0x7b, 0x7c, 
    0x7, 0x44, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x40, 0x21, 0x2, 0x7d, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x8c, 0x5, 0x24, 0x13, 0x2, 
    0x83, 0x88, 0x5, 0x40, 0x21, 0x2, 0x84, 0x85, 0x7, 0x44, 0x2, 0x2, 0x85, 
    0x87, 0x5, 0x40, 0x21, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x82, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x4, 0x3, 0x2, 
    0x8e, 0x8f, 0x7, 0x38, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x3c, 0x1f, 0x2, 0x90, 
    0x91, 0x7, 0x39, 0x2, 0x2, 0x91, 0x9, 0x3, 0x2, 0x2, 0x2, 0x92, 0x96, 
    0x5, 0x14, 0xb, 0x2, 0x93, 0x96, 0x5, 0x1e, 0x10, 0x2, 0x94, 0x96, 0x5, 
    0x32, 0x1a, 0x2, 0x95, 0x92, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0xb, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9a, 
    0x9b, 0x5, 0xe, 0x8, 0x2, 0x9b, 0x9c, 0x5, 0xc, 0x7, 0x2, 0x9c, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0xa1, 0x7, 0x18, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x3e, 0x2, 
    0x2, 0xa2, 0xa3, 0x5, 0x10, 0x9, 0x2, 0xa3, 0xa4, 0x7, 0x3f, 0x2, 0x2, 
    0xa4, 0xa5, 0x5, 0x12, 0xa, 0x2, 0xa5, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0xa7, 0x5, 0x40, 0x21, 0x2, 0xa7, 0xa8, 0x7, 0x44, 0x2, 0x2, 0xa8, 0xa9, 
    0x5, 0x40, 0x21, 0x2, 0xa9, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 
    0x31, 0x2, 0x2, 0xab, 0xac, 0x7, 0x48, 0x2, 0x2, 0xac, 0xb2, 0x5, 0x10, 
    0x9, 0x2, 0xad, 0xae, 0x5, 0x40, 0x21, 0x2, 0xae, 0xaf, 0x7, 0x48, 0x2, 
    0x2, 0xaf, 0xb0, 0x5, 0x10, 0x9, 0x2, 0xb0, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb1, 
    0xad, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x11, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 
    0x7, 0x22, 0x2, 0x2, 0xb4, 0xb7, 0x5, 0x40, 0x21, 0x2, 0xb5, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x7, 0x2, 
    0x2, 0xb9, 0xba, 0x5, 0x16, 0xc, 0x2, 0xba, 0xbb, 0x5, 0x40, 0x21, 0x2, 
    0xbb, 0xbc, 0x7, 0x41, 0x2, 0x2, 0xbc, 0x15, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xc4, 0x5, 0x18, 0xd, 0x2, 0xbe, 0xc4, 0x5, 0x1a, 0xe, 0x2, 0xbf, 0xc4, 
    0x5, 0x1c, 0xf, 0x2, 0xc0, 0xc4, 0x7, 0xa, 0x2, 0x2, 0xc1, 0xc4, 0x7, 
    0xb, 0x2, 0x2, 0xc2, 0xc4, 0x5, 0x40, 0x21, 0x2, 0xc3, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xc3, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xcc, 0x7, 0x8, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x38, 0x2, 0x2, 0xc7, 0xc8, 
    0x7, 0x32, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x31, 0x2, 0x2, 0xc9, 0xca, 0x7, 
    0x32, 0x2, 0x2, 0xca, 0xcd, 0x7, 0x39, 0x2, 0x2, 0xcb, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0x19, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd5, 0x7, 0x9, 0x2, 0x2, 
    0xcf, 0xd0, 0x7, 0x38, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x33, 0x2, 0x2, 0xd1, 
    0xd2, 0x7, 0x31, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x33, 0x2, 0x2, 0xd3, 0xd6, 
    0x7, 0x39, 0x2, 0x2, 0xd4, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd8, 0x7, 0x12, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x38, 0x2, 
    0x2, 0xd9, 0xde, 0x5, 0x40, 0x21, 0x2, 0xda, 0xdb, 0x7, 0x42, 0x2, 0x2, 
    0xdb, 0xdd, 0x5, 0x40, 0x21, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x39, 0x2, 0x2, 0xe2, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe4, 0x7, 0x15, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x16, 0xc, 
    0x2, 0xe5, 0xe8, 0x5, 0x40, 0x21, 0x2, 0xe6, 0xe7, 0x7, 0x2d, 0x2, 0x2, 
    0xe7, 0xe9, 0x5, 0x20, 0x11, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 
    0x7, 0x41, 0x2, 0x2, 0xeb, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xec, 0xf3, 0x7, 
    0x32, 0x2, 0x2, 0xed, 0xf3, 0x7, 0x33, 0x2, 0x2, 0xee, 0xf3, 0x7, 0x34, 
    0x2, 0x2, 0xef, 0xf3, 0x7, 0x2a, 0x2, 0x2, 0xf0, 0xf3, 0x7, 0x2b, 0x2, 
    0x2, 0xf1, 0xf3, 0x5, 0x40, 0x21, 0x2, 0xf2, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x5, 
    0x42, 0x22, 0x2, 0xf5, 0xf6, 0x5, 0x40, 0x21, 0x2, 0xf6, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xf7, 0xfa, 0x5, 0x44, 0x23, 0x2, 0xf8, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x40, 0x21, 0x2, 
    0xfc, 0x25, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x1a, 0x2, 0x2, 0xfe, 
    0xff, 0x5, 0x40, 0x21, 0x2, 0xff, 0x27, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
    0x5, 0x24, 0x13, 0x2, 0x101, 0x102, 0x7, 0x2d, 0x2, 0x2, 0x102, 0x103, 
    0x5, 0x5c, 0x2f, 0x2, 0x103, 0x104, 0x7, 0x41, 0x2, 0x2, 0x104, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x5, 0x16, 0xc, 0x2, 0x106, 0x10a, 
    0x5, 0x40, 0x21, 0x2, 0x107, 0x108, 0x7, 0x2d, 0x2, 0x2, 0x108, 0x10b, 
    0x5, 0x5c, 0x2f, 0x2, 0x109, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x10a, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x41, 0x2, 0x2, 0x10d, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x1b, 0x2, 0x2, 0x10f, 0x112, 
    0x5, 0x8, 0x5, 0x2, 0x110, 0x113, 0x5, 0x26, 0x14, 0x2, 0x111, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 
    0x7, 0x41, 0x2, 0x2, 0x115, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 
    0x5, 0x28, 0x15, 0x2, 0x117, 0x119, 0x5, 0x2c, 0x17, 0x2, 0x118, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x11a, 0x11e, 0x7, 0x3a, 0x2, 0x2, 0x11b, 0x11d, 0x5, 
    0x2e, 0x18, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 
    0x2, 0x2, 0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x121, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0x3b, 0x2, 0x2, 0x122, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x16, 0x2, 0x2, 0x124, 0x133, 0x5, 
    0x40, 0x21, 0x2, 0x125, 0x12f, 0x7, 0x38, 0x2, 0x2, 0x126, 0x12b, 0x5, 
    0x34, 0x1b, 0x2, 0x127, 0x128, 0x7, 0x42, 0x2, 0x2, 0x128, 0x12a, 0x5, 
    0x34, 0x1b, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x12c, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x12e, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x131, 0x134, 0x7, 0x39, 0x2, 0x2, 0x132, 0x134, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x125, 0x3, 0x2, 0x2, 0x2, 0x133, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x7, 
    0x41, 0x2, 0x2, 0x136, 0x33, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x5, 
    0x16, 0xc, 0x2, 0x138, 0x139, 0x5, 0x40, 0x21, 0x2, 0x139, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x13b, 0x7, 0x1c, 0x2, 0x2, 0x13b, 0x13c, 0x5, 
    0x16, 0xc, 0x2, 0x13c, 0x13d, 0x5, 0x4a, 0x26, 0x2, 0x13d, 0x140, 0x7, 
    0x38, 0x2, 0x2, 0x13e, 0x141, 0x5, 0x38, 0x1d, 0x2, 0x13f, 0x141, 0x3, 
    0x2, 0x2, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x7, 
    0x39, 0x2, 0x2, 0x143, 0x144, 0x5, 0x52, 0x2a, 0x2, 0x144, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x14a, 0x5, 0x34, 0x1b, 0x2, 0x146, 0x147, 0x7, 
    0x42, 0x2, 0x2, 0x147, 0x149, 0x5, 0x34, 0x1b, 0x2, 0x148, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 
    0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x5, 0x4a, 
    0x26, 0x2, 0x14e, 0x14f, 0x7, 0x38, 0x2, 0x2, 0x14f, 0x150, 0x5, 0x3c, 
    0x1f, 0x2, 0x150, 0x151, 0x7, 0x39, 0x2, 0x2, 0x151, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x158, 0x5, 0x20, 0x11, 0x2, 0x153, 0x158, 0x5, 0x22, 
    0x12, 0x2, 0x154, 0x158, 0x5, 0x24, 0x13, 0x2, 0x155, 0x158, 0x5, 0x3a, 
    0x1e, 0x2, 0x156, 0x158, 0x3, 0x2, 0x2, 0x2, 0x157, 0x152, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x153, 0x3, 0x2, 0x2, 0x2, 0x157, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x5, 0x3e, 
    0x20, 0x2, 0x15a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x42, 
    0x2, 0x2, 0x15c, 0x15f, 0x5, 0x3c, 0x1f, 0x2, 0x15d, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15d, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x9, 0x2, 0x2, 
    0x2, 0x161, 0x41, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x9, 0x3, 0x2, 0x2, 
    0x163, 0x164, 0x7, 0x44, 0x2, 0x2, 0x164, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x165, 0x166, 0x7, 0xe, 0x2, 0x2, 0x166, 0x167, 0x7, 0x44, 0x2, 0x2, 
    0x167, 0x45, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x7, 0x17, 0x2, 0x2, 
    0x169, 0x16e, 0x5, 0x40, 0x21, 0x2, 0x16a, 0x16b, 0x7, 0x42, 0x2, 0x2, 
    0x16b, 0x16d, 0x5, 0x40, 0x21, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 
    0x16d, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x7, 0x41, 0x2, 0x2, 
    0x172, 0x47, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x7, 0x4, 0x2, 0x2, 0x174, 
    0x175, 0x7, 0x40, 0x2, 0x2, 0x175, 0x176, 0x5, 0x40, 0x21, 0x2, 0x176, 
    0x177, 0x7, 0x41, 0x2, 0x2, 0x177, 0x49, 0x3, 0x2, 0x2, 0x2, 0x178, 
    0x17d, 0x5, 0x40, 0x21, 0x2, 0x179, 0x17a, 0x7, 0x44, 0x2, 0x2, 0x17a, 
    0x17c, 0x5, 0x40, 0x21, 0x2, 0x17b, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x17f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 
    0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17d, 
    0x3, 0x2, 0x2, 0x2, 0x180, 0x183, 0x5, 0x4e, 0x28, 0x2, 0x181, 0x183, 
    0x5, 0x52, 0x2a, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 0x182, 0x181, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x184, 0x18d, 0x5, 
    0x50, 0x29, 0x2, 0x185, 0x18d, 0x5, 0x28, 0x15, 0x2, 0x186, 0x18d, 0x5, 
    0x68, 0x35, 0x2, 0x187, 0x18d, 0x5, 0x60, 0x31, 0x2, 0x188, 0x18d, 0x5, 
    0x2a, 0x16, 0x2, 0x189, 0x18d, 0x5, 0x2c, 0x17, 0x2, 0x18a, 0x18d, 0x5, 
    0x56, 0x2c, 0x2, 0x18b, 0x18d, 0x5, 0x54, 0x2b, 0x2, 0x18c, 0x184, 0x3, 
    0x2, 0x2, 0x2, 0x18c, 0x185, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x186, 0x3, 
    0x2, 0x2, 0x2, 0x18c, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x188, 0x3, 
    0x2, 0x2, 0x2, 0x18c, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 
    0x2, 0x2, 0x2, 0x18c, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x18e, 0x18f, 0x5, 0x3a, 0x1e, 0x2, 0x18f, 0x190, 0x7, 0x41, 
    0x2, 0x2, 0x190, 0x51, 0x3, 0x2, 0x2, 0x2, 0x191, 0x195, 0x7, 0x3a, 
    0x2, 0x2, 0x192, 0x194, 0x5, 0x4e, 0x28, 0x2, 0x193, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x194, 0x197, 0x3, 0x2, 0x2, 0x2, 0x195, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x195, 0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 0x198, 0x3, 0x2, 
    0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x7, 0x3b, 
    0x2, 0x2, 0x199, 0x53, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0xf, 0x2, 
    0x2, 0x19b, 0x19c, 0x5, 0x58, 0x2d, 0x2, 0x19c, 0x19d, 0x7, 0x41, 0x2, 
    0x2, 0x19d, 0x55, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x2c, 0x2, 
    0x2, 0x19f, 0x1a0, 0x7, 0x41, 0x2, 0x2, 0x1a0, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x1a2, 0x5, 0x70, 0x39, 0x2, 0x1a2, 0x1a3, 0x5, 0x5a, 0x2e, 
    0x2, 0x1a3, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x38, 0x2, 
    0x2, 0x1a5, 0x1a6, 0x5, 0x58, 0x2d, 0x2, 0x1a6, 0x1a7, 0x7, 0x39, 0x2, 
    0x2, 0x1a7, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x46, 0x2, 
    0x2, 0x1a9, 0x1ad, 0x5, 0x58, 0x2d, 0x2, 0x1aa, 0x1ab, 0x7, 0x24, 0x2, 
    0x2, 0x1ab, 0x1ad, 0x5, 0x58, 0x2d, 0x2, 0x1ac, 0x1a1, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1a8, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x1ae, 0x1af, 0x9, 0x4, 0x2, 0x2, 0x1af, 0x1b2, 0x5, 0x58, 0x2d, 0x2, 
    0x1b0, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
    0x1b1, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
    0x1b4, 0x7, 0x38, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x5c, 0x2f, 0x2, 0x1b5, 
    0x1b6, 0x7, 0x39, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x5e, 0x30, 0x2, 0x1b7, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x24, 0x2, 0x2, 0x1b9, 
    0x1c2, 0x5, 0x5c, 0x2f, 0x2, 0x1ba, 0x1bb, 0x7, 0x27, 0x2, 0x2, 0x1bb, 
    0x1c2, 0x5, 0x5c, 0x2f, 0x2, 0x1bc, 0x1bd, 0x7, 0x46, 0x2, 0x2, 0x1bd, 
    0x1c2, 0x5, 0x5c, 0x2f, 0x2, 0x1be, 0x1bf, 0x5, 0x58, 0x2d, 0x2, 0x1bf, 
    0x1c0, 0x5, 0x5e, 0x30, 0x2, 0x1c0, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
    0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
    0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
    0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1d7, 
    0x7, 0x26, 0x2, 0x2, 0x1c4, 0x1d7, 0x7, 0x29, 0x2, 0x2, 0x1c5, 0x1d7, 
    0x7, 0x25, 0x2, 0x2, 0x1c6, 0x1d7, 0x7, 0x28, 0x2, 0x2, 0x1c7, 0x1c8, 
    0x7, 0x2d, 0x2, 0x2, 0x1c8, 0x1d7, 0x7, 0x2d, 0x2, 0x2, 0x1c9, 0x1ca, 
    0x7, 0x24, 0x2, 0x2, 0x1ca, 0x1d7, 0x7, 0x2d, 0x2, 0x2, 0x1cb, 0x1d7, 
    0x7, 0x27, 0x2, 0x2, 0x1cc, 0x1cf, 0x7, 0x3e, 0x2, 0x2, 0x1cd, 0x1d0, 
    0x7, 0x2d, 0x2, 0x2, 0x1ce, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cd, 
    0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d7, 
    0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d4, 0x7, 0x3f, 0x2, 0x2, 0x1d2, 0x1d5, 
    0x7, 0x2d, 0x2, 0x2, 0x1d3, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d2, 
    0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d7, 
    0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1c4, 
    0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1c6, 
    0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1c9, 
    0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1cc, 
    0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 
    0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1db, 0x5, 0x5c, 0x2f, 0x2, 0x1d9, 0x1db, 
    0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d9, 
    0x3, 0x2, 0x2, 0x2, 0x1db, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1df, 0x5, 
    0x62, 0x32, 0x2, 0x1dd, 0x1e0, 0x5, 0x66, 0x34, 0x2, 0x1de, 0x1e0, 0x3, 
    0x2, 0x2, 0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1de, 0x3, 
    0x2, 0x2, 0x2, 0x1e0, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x7, 0x20, 
    0x2, 0x2, 0x1e2, 0x1e5, 0x5, 0x64, 0x33, 0x2, 0x1e3, 0x1e6, 0x5, 0x4c, 
    0x27, 0x2, 0x1e4, 0x1e6, 0x7, 0x41, 0x2, 0x2, 0x1e5, 0x1e3, 0x3, 0x2, 
    0x2, 0x2, 0x1e5, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x1e7, 0x1e8, 0x7, 0x38, 0x2, 0x2, 0x1e8, 0x1e9, 0x5, 0x5c, 0x2f, 
    0x2, 0x1e9, 0x1ea, 0x7, 0x39, 0x2, 0x2, 0x1ea, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x1eb, 0x1ec, 0x7, 0x21, 0x2, 0x2, 0x1ec, 0x1ed, 0x5, 0x4c, 0x27, 
    0x2, 0x1ed, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x7, 0x1d, 0x2, 
    0x2, 0x1ef, 0x1f0, 0x5, 0x6a, 0x36, 0x2, 0x1f0, 0x1f4, 0x7, 0x3a, 0x2, 
    0x2, 0x1f1, 0x1f3, 0x5, 0x6c, 0x37, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 
    0x2, 0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 
    0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f9, 0x3, 0x2, 0x2, 
    0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1fa, 0x5, 0x6e, 0x38, 
    0x2, 0x1f8, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f7, 0x3, 0x2, 0x2, 
    0x2, 0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 
    0x2, 0x1fb, 0x1fc, 0x7, 0x3b, 0x2, 0x2, 0x1fc, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x1fd, 0x1fe, 0x7, 0x38, 0x2, 0x2, 0x1fe, 0x1ff, 0x5, 0x40, 0x21, 
    0x2, 0x1ff, 0x200, 0x7, 0x39, 0x2, 0x2, 0x200, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x202, 0x7, 0x1e, 0x2, 0x2, 0x202, 0x203, 0x5, 0x20, 0x11, 
    0x2, 0x203, 0x20b, 0x7, 0x40, 0x2, 0x2, 0x204, 0x20c, 0x5, 0x52, 0x2a, 
    0x2, 0x205, 0x207, 0x5, 0x4e, 0x28, 0x2, 0x206, 0x205, 0x3, 0x2, 0x2, 
    0x2, 0x207, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x208, 0x206, 0x3, 0x2, 0x2, 
    0x2, 0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20c, 0x3, 0x2, 0x2, 
    0x2, 0x20a, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x204, 0x3, 0x2, 0x2, 
    0x2, 0x20b, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x20d, 0x20e, 0x7, 0x1f, 0x2, 0x2, 0x20e, 0x216, 0x7, 0x40, 0x2, 0x2, 
    0x20f, 0x217, 0x5, 0x52, 0x2a, 0x2, 0x210, 0x212, 0x5, 0x4e, 0x28, 0x2, 
    0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x215, 0x3, 0x2, 0x2, 0x2, 
    0x213, 0x211, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x3, 0x2, 0x2, 0x2, 
    0x214, 0x217, 0x3, 0x2, 0x2, 0x2, 0x215, 0x213, 0x3, 0x2, 0x2, 0x2, 
    0x216, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x216, 0x213, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21d, 0x5, 0x22, 0x12, 0x2, 
    0x219, 0x21d, 0x5, 0x24, 0x13, 0x2, 0x21a, 0x21d, 0x5, 0x3a, 0x1e, 0x2, 
    0x21b, 0x21d, 0x5, 0x20, 0x11, 0x2, 0x21c, 0x218, 0x3, 0x2, 0x2, 0x2, 
    0x21c, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x21c, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x77, 0x7f, 0x88, 0x8b, 0x95, 0x97, 0x9e, 0xb1, 0xb6, 0xc3, 0xcc, 0xd5, 
    0xde, 0xe8, 0xf2, 0xf9, 0x10a, 0x112, 0x118, 0x11e, 0x12b, 0x12f, 0x133, 
    0x140, 0x14a, 0x157, 0x15e, 0x16e, 0x17d, 0x182, 0x18c, 0x195, 0x1ac, 
    0x1b1, 0x1c1, 0x1cf, 0x1d4, 0x1d6, 0x1da, 0x1df, 0x1e5, 0x1f4, 0x1f9, 
    0x208, 0x20b, 0x213, 0x216, 0x21c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CommonDeclParser::Initializer CommonDeclParser::_init;
