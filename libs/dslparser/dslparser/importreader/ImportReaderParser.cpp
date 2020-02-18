
// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/ImportReader.g4 by ANTLR 4.7.2


#include "ImportReaderListener.h"

#include "ImportReaderParser.h"


using namespace antlrcpp;
using namespace antlr4;

ImportReaderParser::ImportReaderParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ImportReaderParser::~ImportReaderParser() {
  delete _interpreter;
}

std::string ImportReaderParser::getGrammarFileName() const {
  return "ImportReader.g4";
}

const std::vector<std::string>& ImportReaderParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ImportReaderParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ImportReaderContext ------------------------------------------------------------------

ImportReaderParser::ImportReaderContext::ImportReaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::ImportPathDeclContext* ImportReaderParser::ImportReaderContext::importPathDecl() {
  return getRuleContext<ImportReaderParser::ImportPathDeclContext>(0);
}


size_t ImportReaderParser::ImportReaderContext::getRuleIndex() const {
  return ImportReaderParser::RuleImportReader;
}

void ImportReaderParser::ImportReaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportReader(this);
}

void ImportReaderParser::ImportReaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportReader(this);
}

ImportReaderParser::ImportReaderContext* ImportReaderParser::importReader() {
  ImportReaderContext *_localctx = _tracker.createInstance<ImportReaderContext>(_ctx, getState());
  enterRule(_localctx, 0, ImportReaderParser::RuleImportReader);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    importPathDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentIdPathContext ------------------------------------------------------------------

ImportReaderParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ImportReaderParser::ContextIDContext *> ImportReaderParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<ImportReaderParser::ContextIDContext>();
}

ImportReaderParser::ContextIDContext* ImportReaderParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<ImportReaderParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> ImportReaderParser::ComponentIdPathContext::DOT() {
  return getTokens(ImportReaderParser::DOT);
}

tree::TerminalNode* ImportReaderParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(ImportReaderParser::DOT, i);
}


size_t ImportReaderParser::ComponentIdPathContext::getRuleIndex() const {
  return ImportReaderParser::RuleComponentIdPath;
}

void ImportReaderParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void ImportReaderParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

ImportReaderParser::ComponentIdPathContext* ImportReaderParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 2, ImportReaderParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    contextID();
    setState(121);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ImportReaderParser::DOT) {
      setState(117);
      match(ImportReaderParser::DOT);
      setState(118);
      contextID();
      setState(123);
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

ImportReaderParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ImportReaderParser::ContextIDContext *> ImportReaderParser::SignalIdPathContext::contextID() {
  return getRuleContexts<ImportReaderParser::ContextIDContext>();
}

ImportReaderParser::ContextIDContext* ImportReaderParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<ImportReaderParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> ImportReaderParser::SignalIdPathContext::DOT() {
  return getTokens(ImportReaderParser::DOT);
}

tree::TerminalNode* ImportReaderParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(ImportReaderParser::DOT, i);
}


size_t ImportReaderParser::SignalIdPathContext::getRuleIndex() const {
  return ImportReaderParser::RuleSignalIdPath;
}

void ImportReaderParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void ImportReaderParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

ImportReaderParser::SignalIdPathContext* ImportReaderParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 4, ImportReaderParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    contextID();
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ImportReaderParser::DOT) {
      setState(125);
      match(ImportReaderParser::DOT);
      setState(126);
      contextID();
      setState(131);
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

ImportReaderParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::AttributeNameContext* ImportReaderParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<ImportReaderParser::AttributeNameContext>(0);
}

std::vector<ImportReaderParser::ContextIDContext *> ImportReaderParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<ImportReaderParser::ContextIDContext>();
}

ImportReaderParser::ContextIDContext* ImportReaderParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<ImportReaderParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> ImportReaderParser::AttributeIdPathContext::DOT() {
  return getTokens(ImportReaderParser::DOT);
}

tree::TerminalNode* ImportReaderParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(ImportReaderParser::DOT, i);
}


size_t ImportReaderParser::AttributeIdPathContext::getRuleIndex() const {
  return ImportReaderParser::RuleAttributeIdPath;
}

void ImportReaderParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void ImportReaderParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

ImportReaderParser::AttributeIdPathContext* ImportReaderParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 6, ImportReaderParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(141);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(132);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(133);
      contextID();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ImportReaderParser::DOT) {
        setState(134);
        match(ImportReaderParser::DOT);
        setState(135);
        contextID();
        setState(140);
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

ImportReaderParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::SignalIdPathContext* ImportReaderParser::SignalSendContext::signalIdPath() {
  return getRuleContext<ImportReaderParser::SignalIdPathContext>(0);
}

tree::TerminalNode* ImportReaderParser::SignalSendContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

ImportReaderParser::FunctionCallBodyContext* ImportReaderParser::SignalSendContext::functionCallBody() {
  return getRuleContext<ImportReaderParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* ImportReaderParser::SignalSendContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}


size_t ImportReaderParser::SignalSendContext::getRuleIndex() const {
  return ImportReaderParser::RuleSignalSend;
}

void ImportReaderParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void ImportReaderParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

ImportReaderParser::SignalSendContext* ImportReaderParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 8, ImportReaderParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    signalIdPath();
    setState(144);
    match(ImportReaderParser::LPAREN);
    setState(145);
    functionCallBody();
    setState(146);
    match(ImportReaderParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

ImportReaderParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ImportReaderParser::TypeDefDeclContext *> ImportReaderParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<ImportReaderParser::TypeDefDeclContext>();
}

ImportReaderParser::TypeDefDeclContext* ImportReaderParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<ImportReaderParser::TypeDefDeclContext>(i);
}

std::vector<ImportReaderParser::AttributeDeclContext *> ImportReaderParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<ImportReaderParser::AttributeDeclContext>();
}

ImportReaderParser::AttributeDeclContext* ImportReaderParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<ImportReaderParser::AttributeDeclContext>(i);
}

std::vector<ImportReaderParser::SignalDeclContext *> ImportReaderParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<ImportReaderParser::SignalDeclContext>();
}

ImportReaderParser::SignalDeclContext* ImportReaderParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<ImportReaderParser::SignalDeclContext>(i);
}


size_t ImportReaderParser::CommonDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleCommonDecl;
}

void ImportReaderParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void ImportReaderParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

ImportReaderParser::CommonDeclContext* ImportReaderParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, ImportReaderParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImportReaderParser::TypeID)
      | (1ULL << ImportReaderParser::AttributeID)
      | (1ULL << ImportReaderParser::SignalID))) != 0)) {
      setState(151);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ImportReaderParser::TypeID: {
          setState(148);
          typeDefDecl();
          break;
        }

        case ImportReaderParser::AttributeID: {
          setState(149);
          attributeDecl();
          break;
        }

        case ImportReaderParser::SignalID: {
          setState(150);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(155);
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

ImportReaderParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::ImportPathBodyContext* ImportReaderParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<ImportReaderParser::ImportPathBodyContext>(0);
}

ImportReaderParser::ImportPathDeclContext* ImportReaderParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<ImportReaderParser::ImportPathDeclContext>(0);
}


size_t ImportReaderParser::ImportPathDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleImportPathDecl;
}

void ImportReaderParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void ImportReaderParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

ImportReaderParser::ImportPathDeclContext* ImportReaderParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, ImportReaderParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::ImportID: {
        enterOuterAlt(_localctx, 1);
        setState(156);
        importPathBody();
        setState(157);
        importPathDecl();
        break;
      }

      case ImportReaderParser::EOF: {
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

ImportReaderParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ImportPathBodyContext::ImportID() {
  return getToken(ImportReaderParser::ImportID, 0);
}

tree::TerminalNode* ImportReaderParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(ImportReaderParser::LESSTHAN, 0);
}

ImportReaderParser::ImportFileBodyContext* ImportReaderParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<ImportReaderParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* ImportReaderParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(ImportReaderParser::GREATERTHAN, 0);
}

ImportReaderParser::ImportAsContext* ImportReaderParser::ImportPathBodyContext::importAs() {
  return getRuleContext<ImportReaderParser::ImportAsContext>(0);
}


size_t ImportReaderParser::ImportPathBodyContext::getRuleIndex() const {
  return ImportReaderParser::RuleImportPathBody;
}

void ImportReaderParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void ImportReaderParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

ImportReaderParser::ImportPathBodyContext* ImportReaderParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 14, ImportReaderParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(ImportReaderParser::ImportID);
    setState(163);
    match(ImportReaderParser::LESSTHAN);
    setState(164);
    importFileBody();
    setState(165);
    match(ImportReaderParser::GREATERTHAN);
    setState(166);
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

ImportReaderParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ImportReaderParser::ContextIDContext *> ImportReaderParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<ImportReaderParser::ContextIDContext>();
}

ImportReaderParser::ContextIDContext* ImportReaderParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<ImportReaderParser::ContextIDContext>(i);
}

tree::TerminalNode* ImportReaderParser::ImportFileBodyContext::DOT() {
  return getToken(ImportReaderParser::DOT, 0);
}

tree::TerminalNode* ImportReaderParser::ImportFileBodyContext::RANGE() {
  return getToken(ImportReaderParser::RANGE, 0);
}

tree::TerminalNode* ImportReaderParser::ImportFileBodyContext::DIV() {
  return getToken(ImportReaderParser::DIV, 0);
}

ImportReaderParser::ImportFileBodyContext* ImportReaderParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<ImportReaderParser::ImportFileBodyContext>(0);
}


size_t ImportReaderParser::ImportFileBodyContext::getRuleIndex() const {
  return ImportReaderParser::RuleImportFileBody;
}

void ImportReaderParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void ImportReaderParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

ImportReaderParser::ImportFileBodyContext* ImportReaderParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 16, ImportReaderParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(168);
      contextID();
      setState(169);
      match(ImportReaderParser::DOT);
      setState(170);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(172);
      match(ImportReaderParser::RANGE);
      setState(173);
      match(ImportReaderParser::DIV);
      setState(174);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(175);
      contextID();
      setState(176);
      match(ImportReaderParser::DIV);
      setState(177);
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

ImportReaderParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ImportAsContext::AsID() {
  return getToken(ImportReaderParser::AsID, 0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::ImportAsContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}


size_t ImportReaderParser::ImportAsContext::getRuleIndex() const {
  return ImportReaderParser::RuleImportAs;
}

void ImportReaderParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void ImportReaderParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

ImportReaderParser::ImportAsContext* ImportReaderParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 18, ImportReaderParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(181);
        match(ImportReaderParser::AsID);
        setState(182);
        contextID();
        break;
      }

      case ImportReaderParser::EOF:
      case ImportReaderParser::ImportID: {
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

ImportReaderParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::TypeDefDeclContext::TypeID() {
  return getToken(ImportReaderParser::TypeID, 0);
}

ImportReaderParser::TypeDeclContext* ImportReaderParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<ImportReaderParser::TypeDeclContext>(0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::TypeDefDeclContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}

tree::TerminalNode* ImportReaderParser::TypeDefDeclContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}


size_t ImportReaderParser::TypeDefDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleTypeDefDecl;
}

void ImportReaderParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void ImportReaderParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

ImportReaderParser::TypeDefDeclContext* ImportReaderParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, ImportReaderParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(ImportReaderParser::TypeID);
    setState(187);
    typeDecl();
    setState(188);
    contextID();
    setState(189);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

ImportReaderParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::IntTypeDeclContext* ImportReaderParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<ImportReaderParser::IntTypeDeclContext>(0);
}

ImportReaderParser::RealTypeDeclContext* ImportReaderParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<ImportReaderParser::RealTypeDeclContext>(0);
}

ImportReaderParser::EnumTypeDeclContext* ImportReaderParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<ImportReaderParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* ImportReaderParser::TypeDeclContext::BoolID() {
  return getToken(ImportReaderParser::BoolID, 0);
}

tree::TerminalNode* ImportReaderParser::TypeDeclContext::StringID() {
  return getToken(ImportReaderParser::StringID, 0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::TypeDeclContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}


size_t ImportReaderParser::TypeDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleTypeDecl;
}

void ImportReaderParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void ImportReaderParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

ImportReaderParser::TypeDeclContext* ImportReaderParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, ImportReaderParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(191);
        intTypeDecl();
        break;
      }

      case ImportReaderParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(192);
        realTypeDecl();
        break;
      }

      case ImportReaderParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(193);
        enumTypeDecl();
        break;
      }

      case ImportReaderParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(194);
        match(ImportReaderParser::BoolID);
        break;
      }

      case ImportReaderParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(195);
        match(ImportReaderParser::StringID);
        break;
      }

      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(196);
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

ImportReaderParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::IntTypeDeclContext::IntID() {
  return getToken(ImportReaderParser::IntID, 0);
}

tree::TerminalNode* ImportReaderParser::IntTypeDeclContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> ImportReaderParser::IntTypeDeclContext::INT() {
  return getTokens(ImportReaderParser::INT);
}

tree::TerminalNode* ImportReaderParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(ImportReaderParser::INT, i);
}

tree::TerminalNode* ImportReaderParser::IntTypeDeclContext::RANGE() {
  return getToken(ImportReaderParser::RANGE, 0);
}

tree::TerminalNode* ImportReaderParser::IntTypeDeclContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}


size_t ImportReaderParser::IntTypeDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleIntTypeDecl;
}

void ImportReaderParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void ImportReaderParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

ImportReaderParser::IntTypeDeclContext* ImportReaderParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, ImportReaderParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(ImportReaderParser::IntID);
    setState(206);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::LPAREN: {
        setState(200);
        match(ImportReaderParser::LPAREN);
        setState(201);
        match(ImportReaderParser::INT);
        setState(202);
        match(ImportReaderParser::RANGE);
        setState(203);
        match(ImportReaderParser::INT);
        setState(204);
        match(ImportReaderParser::RPAREN);
        break;
      }

      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::ID: {
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

ImportReaderParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::RealTypeDeclContext::RealID() {
  return getToken(ImportReaderParser::RealID, 0);
}

tree::TerminalNode* ImportReaderParser::RealTypeDeclContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> ImportReaderParser::RealTypeDeclContext::REAL() {
  return getTokens(ImportReaderParser::REAL);
}

tree::TerminalNode* ImportReaderParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(ImportReaderParser::REAL, i);
}

tree::TerminalNode* ImportReaderParser::RealTypeDeclContext::RANGE() {
  return getToken(ImportReaderParser::RANGE, 0);
}

tree::TerminalNode* ImportReaderParser::RealTypeDeclContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}


size_t ImportReaderParser::RealTypeDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleRealTypeDecl;
}

void ImportReaderParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void ImportReaderParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

ImportReaderParser::RealTypeDeclContext* ImportReaderParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 26, ImportReaderParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    match(ImportReaderParser::RealID);
    setState(215);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::LPAREN: {
        setState(209);
        match(ImportReaderParser::LPAREN);
        setState(210);
        match(ImportReaderParser::REAL);
        setState(211);
        match(ImportReaderParser::RANGE);
        setState(212);
        match(ImportReaderParser::REAL);
        setState(213);
        match(ImportReaderParser::RPAREN);
        break;
      }

      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::ID: {
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

ImportReaderParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::EnumTypeDeclContext::EnumID() {
  return getToken(ImportReaderParser::EnumID, 0);
}

tree::TerminalNode* ImportReaderParser::EnumTypeDeclContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

std::vector<ImportReaderParser::ContextIDContext *> ImportReaderParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<ImportReaderParser::ContextIDContext>();
}

ImportReaderParser::ContextIDContext* ImportReaderParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<ImportReaderParser::ContextIDContext>(i);
}

tree::TerminalNode* ImportReaderParser::EnumTypeDeclContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> ImportReaderParser::EnumTypeDeclContext::COMMA() {
  return getTokens(ImportReaderParser::COMMA);
}

tree::TerminalNode* ImportReaderParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(ImportReaderParser::COMMA, i);
}


size_t ImportReaderParser::EnumTypeDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleEnumTypeDecl;
}

void ImportReaderParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void ImportReaderParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

ImportReaderParser::EnumTypeDeclContext* ImportReaderParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, ImportReaderParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(ImportReaderParser::EnumID);
    setState(218);
    match(ImportReaderParser::LPAREN);
    setState(219);
    contextID();
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ImportReaderParser::COMMA) {
      setState(220);
      match(ImportReaderParser::COMMA);
      setState(221);
      contextID();
      setState(226);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(227);
    match(ImportReaderParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

ImportReaderParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::AttributeDeclContext::AttributeID() {
  return getToken(ImportReaderParser::AttributeID, 0);
}

ImportReaderParser::TypeDeclContext* ImportReaderParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<ImportReaderParser::TypeDeclContext>(0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::AttributeDeclContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}

tree::TerminalNode* ImportReaderParser::AttributeDeclContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}

tree::TerminalNode* ImportReaderParser::AttributeDeclContext::ASSIGN() {
  return getToken(ImportReaderParser::ASSIGN, 0);
}

ImportReaderParser::LiteralValueContext* ImportReaderParser::AttributeDeclContext::literalValue() {
  return getRuleContext<ImportReaderParser::LiteralValueContext>(0);
}


size_t ImportReaderParser::AttributeDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleAttributeDecl;
}

void ImportReaderParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void ImportReaderParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

ImportReaderParser::AttributeDeclContext* ImportReaderParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, ImportReaderParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(ImportReaderParser::AttributeID);
    setState(230);
    typeDecl();
    setState(231);
    contextID();
    setState(234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ImportReaderParser::ASSIGN) {
      setState(232);
      match(ImportReaderParser::ASSIGN);
      setState(233);
      literalValue();
    }
    setState(236);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

ImportReaderParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::LiteralValueContext::INT() {
  return getToken(ImportReaderParser::INT, 0);
}

tree::TerminalNode* ImportReaderParser::LiteralValueContext::REAL() {
  return getToken(ImportReaderParser::REAL, 0);
}

tree::TerminalNode* ImportReaderParser::LiteralValueContext::STRING() {
  return getToken(ImportReaderParser::STRING, 0);
}

tree::TerminalNode* ImportReaderParser::LiteralValueContext::TrueID() {
  return getToken(ImportReaderParser::TrueID, 0);
}

tree::TerminalNode* ImportReaderParser::LiteralValueContext::FalseID() {
  return getToken(ImportReaderParser::FalseID, 0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::LiteralValueContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}


size_t ImportReaderParser::LiteralValueContext::getRuleIndex() const {
  return ImportReaderParser::RuleLiteralValue;
}

void ImportReaderParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void ImportReaderParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

ImportReaderParser::LiteralValueContext* ImportReaderParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 32, ImportReaderParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(238);
        match(ImportReaderParser::INT);
        break;
      }

      case ImportReaderParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(239);
        match(ImportReaderParser::REAL);
        break;
      }

      case ImportReaderParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(240);
        match(ImportReaderParser::STRING);
        break;
      }

      case ImportReaderParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(241);
        match(ImportReaderParser::TrueID);
        break;
      }

      case ImportReaderParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(242);
        match(ImportReaderParser::FalseID);
        break;
      }

      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(243);
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

ImportReaderParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::TriggerDeclContext* ImportReaderParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<ImportReaderParser::TriggerDeclContext>(0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::SignalParamNameContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}


size_t ImportReaderParser::SignalParamNameContext::getRuleIndex() const {
  return ImportReaderParser::RuleSignalParamName;
}

void ImportReaderParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void ImportReaderParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

ImportReaderParser::SignalParamNameContext* ImportReaderParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 34, ImportReaderParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    triggerDecl();
    setState(247);
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

ImportReaderParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::ContextIDContext* ImportReaderParser::AttributeNameContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}

ImportReaderParser::ThisDeclContext* ImportReaderParser::AttributeNameContext::thisDecl() {
  return getRuleContext<ImportReaderParser::ThisDeclContext>(0);
}


size_t ImportReaderParser::AttributeNameContext::getRuleIndex() const {
  return ImportReaderParser::RuleAttributeName;
}

void ImportReaderParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void ImportReaderParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

ImportReaderParser::AttributeNameContext* ImportReaderParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 36, ImportReaderParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::ThisID: {
        setState(249);
        thisDecl();
        break;
      }

      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(253);
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

ImportReaderParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ToPortNameContext::ToID() {
  return getToken(ImportReaderParser::ToID, 0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::ToPortNameContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}


size_t ImportReaderParser::ToPortNameContext::getRuleIndex() const {
  return ImportReaderParser::RuleToPortName;
}

void ImportReaderParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void ImportReaderParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

ImportReaderParser::ToPortNameContext* ImportReaderParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 38, ImportReaderParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(ImportReaderParser::ToID);
    setState(256);
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

ImportReaderParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::AttributeNameContext* ImportReaderParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<ImportReaderParser::AttributeNameContext>(0);
}

tree::TerminalNode* ImportReaderParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(ImportReaderParser::ASSIGN, 0);
}

ImportReaderParser::ExpressionContext* ImportReaderParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<ImportReaderParser::ExpressionContext>(0);
}

tree::TerminalNode* ImportReaderParser::AttributeAssignStatementContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}


size_t ImportReaderParser::AttributeAssignStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleAttributeAssignStatement;
}

void ImportReaderParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void ImportReaderParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

ImportReaderParser::AttributeAssignStatementContext* ImportReaderParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, ImportReaderParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    attributeName();
    setState(259);
    match(ImportReaderParser::ASSIGN);
    setState(260);
    expression();
    setState(261);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

ImportReaderParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::TypeDeclContext* ImportReaderParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<ImportReaderParser::TypeDeclContext>(0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}

tree::TerminalNode* ImportReaderParser::LocalAssignStatementContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}

tree::TerminalNode* ImportReaderParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(ImportReaderParser::ASSIGN, 0);
}

ImportReaderParser::ExpressionContext* ImportReaderParser::LocalAssignStatementContext::expression() {
  return getRuleContext<ImportReaderParser::ExpressionContext>(0);
}


size_t ImportReaderParser::LocalAssignStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleLocalAssignStatement;
}

void ImportReaderParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void ImportReaderParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

ImportReaderParser::LocalAssignStatementContext* ImportReaderParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, ImportReaderParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    typeDecl();
    setState(264);
    contextID();
    setState(268);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::ASSIGN: {
        setState(265);
        match(ImportReaderParser::ASSIGN);
        setState(266);
        expression();
        break;
      }

      case ImportReaderParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(270);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

ImportReaderParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::SendToStatementContext::SendID() {
  return getToken(ImportReaderParser::SendID, 0);
}

ImportReaderParser::SignalSendContext* ImportReaderParser::SendToStatementContext::signalSend() {
  return getRuleContext<ImportReaderParser::SignalSendContext>(0);
}

tree::TerminalNode* ImportReaderParser::SendToStatementContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}

ImportReaderParser::ToPortNameContext* ImportReaderParser::SendToStatementContext::toPortName() {
  return getRuleContext<ImportReaderParser::ToPortNameContext>(0);
}


size_t ImportReaderParser::SendToStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleSendToStatement;
}

void ImportReaderParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void ImportReaderParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

ImportReaderParser::SendToStatementContext* ImportReaderParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, ImportReaderParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(ImportReaderParser::SendID);
    setState(273);
    signalSend();
    setState(276);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::ToID: {
        setState(274);
        toPortName();
        break;
      }

      case ImportReaderParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(278);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

ImportReaderParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::AttributeAssignStatementContext* ImportReaderParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<ImportReaderParser::AttributeAssignStatementContext>(0);
}

ImportReaderParser::SendToStatementContext* ImportReaderParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<ImportReaderParser::SendToStatementContext>(0);
}


size_t ImportReaderParser::SingleAssignmentContext::getRuleIndex() const {
  return ImportReaderParser::RuleSingleAssignment;
}

void ImportReaderParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void ImportReaderParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

ImportReaderParser::SingleAssignmentContext* ImportReaderParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 46, ImportReaderParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::ThisID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(280);
        attributeAssignStatement();
        break;
      }

      case ImportReaderParser::SendID: {
        enterOuterAlt(_localctx, 2);
        setState(281);
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

ImportReaderParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::MultiAssignmentContext::LBRACE() {
  return getToken(ImportReaderParser::LBRACE, 0);
}

tree::TerminalNode* ImportReaderParser::MultiAssignmentContext::RBRACE() {
  return getToken(ImportReaderParser::RBRACE, 0);
}

std::vector<ImportReaderParser::SingleAssignmentContext *> ImportReaderParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<ImportReaderParser::SingleAssignmentContext>();
}

ImportReaderParser::SingleAssignmentContext* ImportReaderParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<ImportReaderParser::SingleAssignmentContext>(i);
}


size_t ImportReaderParser::MultiAssignmentContext::getRuleIndex() const {
  return ImportReaderParser::RuleMultiAssignment;
}

void ImportReaderParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void ImportReaderParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

ImportReaderParser::MultiAssignmentContext* ImportReaderParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 48, ImportReaderParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(ImportReaderParser::LBRACE);
    setState(288);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImportReaderParser::NameID)
      | (1ULL << ImportReaderParser::LabelID)
      | (1ULL << ImportReaderParser::EnabledID)
      | (1ULL << ImportReaderParser::TypeID)
      | (1ULL << ImportReaderParser::ThisID)
      | (1ULL << ImportReaderParser::AttributeID)
      | (1ULL << ImportReaderParser::SignalID)
      | (1ULL << ImportReaderParser::PortID)
      | (1ULL << ImportReaderParser::ImportID)
      | (1ULL << ImportReaderParser::FromID)
      | (1ULL << ImportReaderParser::ToID)
      | (1ULL << ImportReaderParser::SendID)
      | (1ULL << ImportReaderParser::AsID)
      | (1ULL << ImportReaderParser::ID))) != 0)) {
      setState(285);
      singleAssignment();
      setState(290);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(291);
    match(ImportReaderParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

ImportReaderParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::SignalDeclContext::SignalID() {
  return getToken(ImportReaderParser::SignalID, 0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::SignalDeclContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}

tree::TerminalNode* ImportReaderParser::SignalDeclContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}

tree::TerminalNode* ImportReaderParser::SignalDeclContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

tree::TerminalNode* ImportReaderParser::SignalDeclContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}

std::vector<ImportReaderParser::ParamDeclContext *> ImportReaderParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<ImportReaderParser::ParamDeclContext>();
}

ImportReaderParser::ParamDeclContext* ImportReaderParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<ImportReaderParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> ImportReaderParser::SignalDeclContext::COMMA() {
  return getTokens(ImportReaderParser::COMMA);
}

tree::TerminalNode* ImportReaderParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(ImportReaderParser::COMMA, i);
}


size_t ImportReaderParser::SignalDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleSignalDecl;
}

void ImportReaderParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void ImportReaderParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

ImportReaderParser::SignalDeclContext* ImportReaderParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 50, ImportReaderParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    match(ImportReaderParser::SignalID);
    setState(294);
    contextID();
    setState(309);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::LPAREN: {
        setState(295);
        match(ImportReaderParser::LPAREN);
        setState(305);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ImportReaderParser::NameID:
          case ImportReaderParser::LabelID:
          case ImportReaderParser::EnabledID:
          case ImportReaderParser::TypeID:
          case ImportReaderParser::IntID:
          case ImportReaderParser::RealID:
          case ImportReaderParser::BoolID:
          case ImportReaderParser::StringID:
          case ImportReaderParser::EnumID:
          case ImportReaderParser::AttributeID:
          case ImportReaderParser::SignalID:
          case ImportReaderParser::PortID:
          case ImportReaderParser::ImportID:
          case ImportReaderParser::FromID:
          case ImportReaderParser::ToID:
          case ImportReaderParser::AsID:
          case ImportReaderParser::ID: {
            setState(296);
            paramDecl();
            setState(301);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == ImportReaderParser::COMMA) {
              setState(297);
              match(ImportReaderParser::COMMA);
              setState(298);
              paramDecl();
              setState(303);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case ImportReaderParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(307);
        match(ImportReaderParser::RPAREN);
        break;
      }

      case ImportReaderParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(311);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

ImportReaderParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::TypeDeclContext* ImportReaderParser::ParamDeclContext::typeDecl() {
  return getRuleContext<ImportReaderParser::TypeDeclContext>(0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::ParamDeclContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}


size_t ImportReaderParser::ParamDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleParamDecl;
}

void ImportReaderParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void ImportReaderParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

ImportReaderParser::ParamDeclContext* ImportReaderParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, ImportReaderParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    typeDecl();
    setState(314);
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

ImportReaderParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::FunctionDeclContext::FunctionID() {
  return getToken(ImportReaderParser::FunctionID, 0);
}

ImportReaderParser::TypeDeclContext* ImportReaderParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<ImportReaderParser::TypeDeclContext>(0);
}

ImportReaderParser::IdPathContext* ImportReaderParser::FunctionDeclContext::idPath() {
  return getRuleContext<ImportReaderParser::IdPathContext>(0);
}

tree::TerminalNode* ImportReaderParser::FunctionDeclContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

tree::TerminalNode* ImportReaderParser::FunctionDeclContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}

ImportReaderParser::NestedStatementBodyContext* ImportReaderParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<ImportReaderParser::NestedStatementBodyContext>(0);
}

ImportReaderParser::FunctionParametersContext* ImportReaderParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<ImportReaderParser::FunctionParametersContext>(0);
}


size_t ImportReaderParser::FunctionDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleFunctionDecl;
}

void ImportReaderParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void ImportReaderParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

ImportReaderParser::FunctionDeclContext* ImportReaderParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 54, ImportReaderParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(ImportReaderParser::FunctionID);
    setState(317);
    typeDecl();
    setState(318);
    idPath();
    setState(319);
    match(ImportReaderParser::LPAREN);
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::IntID:
      case ImportReaderParser::RealID:
      case ImportReaderParser::BoolID:
      case ImportReaderParser::StringID:
      case ImportReaderParser::EnumID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::ID: {
        setState(320);
        functionParameters();
        break;
      }

      case ImportReaderParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(324);
    match(ImportReaderParser::RPAREN);
    setState(325);
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

ImportReaderParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ImportReaderParser::ParamDeclContext *> ImportReaderParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<ImportReaderParser::ParamDeclContext>();
}

ImportReaderParser::ParamDeclContext* ImportReaderParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<ImportReaderParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> ImportReaderParser::FunctionParametersContext::COMMA() {
  return getTokens(ImportReaderParser::COMMA);
}

tree::TerminalNode* ImportReaderParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(ImportReaderParser::COMMA, i);
}


size_t ImportReaderParser::FunctionParametersContext::getRuleIndex() const {
  return ImportReaderParser::RuleFunctionParameters;
}

void ImportReaderParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void ImportReaderParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

ImportReaderParser::FunctionParametersContext* ImportReaderParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 56, ImportReaderParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    paramDecl();
    setState(332);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ImportReaderParser::COMMA) {
      setState(328);
      match(ImportReaderParser::COMMA);
      setState(329);
      paramDecl();
      setState(334);
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

ImportReaderParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::IdPathContext* ImportReaderParser::FunctionCallContext::idPath() {
  return getRuleContext<ImportReaderParser::IdPathContext>(0);
}

tree::TerminalNode* ImportReaderParser::FunctionCallContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

ImportReaderParser::FunctionCallBodyContext* ImportReaderParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<ImportReaderParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* ImportReaderParser::FunctionCallContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}


size_t ImportReaderParser::FunctionCallContext::getRuleIndex() const {
  return ImportReaderParser::RuleFunctionCall;
}

void ImportReaderParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void ImportReaderParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

ImportReaderParser::FunctionCallContext* ImportReaderParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 58, ImportReaderParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    idPath();
    setState(336);
    match(ImportReaderParser::LPAREN);
    setState(337);
    functionCallBody();
    setState(338);
    match(ImportReaderParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

ImportReaderParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::FunctionCallBodyOptionalContext* ImportReaderParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<ImportReaderParser::FunctionCallBodyOptionalContext>(0);
}

ImportReaderParser::LiteralValueContext* ImportReaderParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<ImportReaderParser::LiteralValueContext>(0);
}

ImportReaderParser::SignalParamNameContext* ImportReaderParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<ImportReaderParser::SignalParamNameContext>(0);
}

ImportReaderParser::AttributeNameContext* ImportReaderParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<ImportReaderParser::AttributeNameContext>(0);
}

ImportReaderParser::FunctionCallContext* ImportReaderParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<ImportReaderParser::FunctionCallContext>(0);
}


size_t ImportReaderParser::FunctionCallBodyContext::getRuleIndex() const {
  return ImportReaderParser::RuleFunctionCallBody;
}

void ImportReaderParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void ImportReaderParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

ImportReaderParser::FunctionCallBodyContext* ImportReaderParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 60, ImportReaderParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(340);
      literalValue();
      break;
    }

    case 2: {
      setState(341);
      signalParamName();
      break;
    }

    case 3: {
      setState(342);
      attributeName();
      break;
    }

    case 4: {
      setState(343);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(347);
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

ImportReaderParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(ImportReaderParser::COMMA, 0);
}

ImportReaderParser::FunctionCallBodyContext* ImportReaderParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<ImportReaderParser::FunctionCallBodyContext>(0);
}


size_t ImportReaderParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return ImportReaderParser::RuleFunctionCallBodyOptional;
}

void ImportReaderParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void ImportReaderParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

ImportReaderParser::FunctionCallBodyOptionalContext* ImportReaderParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 62, ImportReaderParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(349);
        match(ImportReaderParser::COMMA);
        setState(350);
        functionCallBody();
        break;
      }

      case ImportReaderParser::RPAREN: {
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

ImportReaderParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::ID() {
  return getToken(ImportReaderParser::ID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::NameID() {
  return getToken(ImportReaderParser::NameID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::LabelID() {
  return getToken(ImportReaderParser::LabelID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::EnabledID() {
  return getToken(ImportReaderParser::EnabledID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::TypeID() {
  return getToken(ImportReaderParser::TypeID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::AttributeID() {
  return getToken(ImportReaderParser::AttributeID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::SignalID() {
  return getToken(ImportReaderParser::SignalID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::PortID() {
  return getToken(ImportReaderParser::PortID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::ImportID() {
  return getToken(ImportReaderParser::ImportID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::FromID() {
  return getToken(ImportReaderParser::FromID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::ToID() {
  return getToken(ImportReaderParser::ToID, 0);
}

tree::TerminalNode* ImportReaderParser::ContextIDContext::AsID() {
  return getToken(ImportReaderParser::AsID, 0);
}


size_t ImportReaderParser::ContextIDContext::getRuleIndex() const {
  return ImportReaderParser::RuleContextID;
}

void ImportReaderParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void ImportReaderParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 64, ImportReaderParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(354);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImportReaderParser::NameID)
      | (1ULL << ImportReaderParser::LabelID)
      | (1ULL << ImportReaderParser::EnabledID)
      | (1ULL << ImportReaderParser::TypeID)
      | (1ULL << ImportReaderParser::AttributeID)
      | (1ULL << ImportReaderParser::SignalID)
      | (1ULL << ImportReaderParser::PortID)
      | (1ULL << ImportReaderParser::ImportID)
      | (1ULL << ImportReaderParser::FromID)
      | (1ULL << ImportReaderParser::ToID)
      | (1ULL << ImportReaderParser::AsID)
      | (1ULL << ImportReaderParser::ID))) != 0))) {
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

ImportReaderParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::TriggerDeclContext::DOT() {
  return getToken(ImportReaderParser::DOT, 0);
}

tree::TerminalNode* ImportReaderParser::TriggerDeclContext::MessageTrigger() {
  return getToken(ImportReaderParser::MessageTrigger, 0);
}

tree::TerminalNode* ImportReaderParser::TriggerDeclContext::TriggerID() {
  return getToken(ImportReaderParser::TriggerID, 0);
}


size_t ImportReaderParser::TriggerDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleTriggerDecl;
}

void ImportReaderParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void ImportReaderParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

ImportReaderParser::TriggerDeclContext* ImportReaderParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, ImportReaderParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    _la = _input->LA(1);
    if (!(_la == ImportReaderParser::TriggerID

    || _la == ImportReaderParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(357);
    match(ImportReaderParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

ImportReaderParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ThisDeclContext::ThisID() {
  return getToken(ImportReaderParser::ThisID, 0);
}

tree::TerminalNode* ImportReaderParser::ThisDeclContext::DOT() {
  return getToken(ImportReaderParser::DOT, 0);
}


size_t ImportReaderParser::ThisDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleThisDecl;
}

void ImportReaderParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void ImportReaderParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

ImportReaderParser::ThisDeclContext* ImportReaderParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 68, ImportReaderParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(ImportReaderParser::ThisID);
    setState(360);
    match(ImportReaderParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

ImportReaderParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::PortDeclContext::PortID() {
  return getToken(ImportReaderParser::PortID, 0);
}

std::vector<ImportReaderParser::ContextIDContext *> ImportReaderParser::PortDeclContext::contextID() {
  return getRuleContexts<ImportReaderParser::ContextIDContext>();
}

ImportReaderParser::ContextIDContext* ImportReaderParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<ImportReaderParser::ContextIDContext>(i);
}

tree::TerminalNode* ImportReaderParser::PortDeclContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> ImportReaderParser::PortDeclContext::COMMA() {
  return getTokens(ImportReaderParser::COMMA);
}

tree::TerminalNode* ImportReaderParser::PortDeclContext::COMMA(size_t i) {
  return getToken(ImportReaderParser::COMMA, i);
}


size_t ImportReaderParser::PortDeclContext::getRuleIndex() const {
  return ImportReaderParser::RulePortDecl;
}

void ImportReaderParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void ImportReaderParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

ImportReaderParser::PortDeclContext* ImportReaderParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 70, ImportReaderParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    match(ImportReaderParser::PortID);
    setState(363);
    contextID();
    setState(368);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ImportReaderParser::COMMA) {
      setState(364);
      match(ImportReaderParser::COMMA);
      setState(365);
      contextID();
      setState(370);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(371);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

ImportReaderParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::NameDeclContext::NameID() {
  return getToken(ImportReaderParser::NameID, 0);
}

tree::TerminalNode* ImportReaderParser::NameDeclContext::COLON() {
  return getToken(ImportReaderParser::COLON, 0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::NameDeclContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}

tree::TerminalNode* ImportReaderParser::NameDeclContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}


size_t ImportReaderParser::NameDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleNameDecl;
}

void ImportReaderParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void ImportReaderParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

ImportReaderParser::NameDeclContext* ImportReaderParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 72, ImportReaderParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(ImportReaderParser::NameID);
    setState(374);
    match(ImportReaderParser::COLON);
    setState(375);
    contextID();
    setState(376);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

ImportReaderParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ImportReaderParser::ContextIDContext *> ImportReaderParser::IdPathContext::contextID() {
  return getRuleContexts<ImportReaderParser::ContextIDContext>();
}

ImportReaderParser::ContextIDContext* ImportReaderParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<ImportReaderParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> ImportReaderParser::IdPathContext::DOT() {
  return getTokens(ImportReaderParser::DOT);
}

tree::TerminalNode* ImportReaderParser::IdPathContext::DOT(size_t i) {
  return getToken(ImportReaderParser::DOT, i);
}


size_t ImportReaderParser::IdPathContext::getRuleIndex() const {
  return ImportReaderParser::RuleIdPath;
}

void ImportReaderParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void ImportReaderParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

ImportReaderParser::IdPathContext* ImportReaderParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 74, ImportReaderParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    contextID();
    setState(383);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ImportReaderParser::DOT) {
      setState(379);
      match(ImportReaderParser::DOT);
      setState(380);
      contextID();
      setState(385);
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

ImportReaderParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::StatementBodyContext* ImportReaderParser::StatementDeclContext::statementBody() {
  return getRuleContext<ImportReaderParser::StatementBodyContext>(0);
}

ImportReaderParser::NestedStatementBodyContext* ImportReaderParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<ImportReaderParser::NestedStatementBodyContext>(0);
}


size_t ImportReaderParser::StatementDeclContext::getRuleIndex() const {
  return ImportReaderParser::RuleStatementDecl;
}

void ImportReaderParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void ImportReaderParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

ImportReaderParser::StatementDeclContext* ImportReaderParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 76, ImportReaderParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::IntID:
      case ImportReaderParser::RealID:
      case ImportReaderParser::BoolID:
      case ImportReaderParser::StringID:
      case ImportReaderParser::ThisID:
      case ImportReaderParser::ReturnID:
      case ImportReaderParser::EnumID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::SendID:
      case ImportReaderParser::SwitchID:
      case ImportReaderParser::IfID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::BREAK:
      case ImportReaderParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(386);
        statementBody();
        break;
      }

      case ImportReaderParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(387);
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

ImportReaderParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::FunctionCallStatementContext* ImportReaderParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<ImportReaderParser::FunctionCallStatementContext>(0);
}

ImportReaderParser::AttributeAssignStatementContext* ImportReaderParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<ImportReaderParser::AttributeAssignStatementContext>(0);
}

ImportReaderParser::SwitchStatementContext* ImportReaderParser::StatementBodyContext::switchStatement() {
  return getRuleContext<ImportReaderParser::SwitchStatementContext>(0);
}

ImportReaderParser::ConditionalStatementContext* ImportReaderParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<ImportReaderParser::ConditionalStatementContext>(0);
}

ImportReaderParser::LocalAssignStatementContext* ImportReaderParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<ImportReaderParser::LocalAssignStatementContext>(0);
}

ImportReaderParser::SendToStatementContext* ImportReaderParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<ImportReaderParser::SendToStatementContext>(0);
}

ImportReaderParser::BreakStatementContext* ImportReaderParser::StatementBodyContext::breakStatement() {
  return getRuleContext<ImportReaderParser::BreakStatementContext>(0);
}

ImportReaderParser::ReturnStatementContext* ImportReaderParser::StatementBodyContext::returnStatement() {
  return getRuleContext<ImportReaderParser::ReturnStatementContext>(0);
}


size_t ImportReaderParser::StatementBodyContext::getRuleIndex() const {
  return ImportReaderParser::RuleStatementBody;
}

void ImportReaderParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void ImportReaderParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

ImportReaderParser::StatementBodyContext* ImportReaderParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 78, ImportReaderParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(390);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(391);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(392);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(393);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(394);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(395);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(396);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(397);
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

ImportReaderParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::FunctionCallContext* ImportReaderParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<ImportReaderParser::FunctionCallContext>(0);
}

tree::TerminalNode* ImportReaderParser::FunctionCallStatementContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}


size_t ImportReaderParser::FunctionCallStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleFunctionCallStatement;
}

void ImportReaderParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void ImportReaderParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

ImportReaderParser::FunctionCallStatementContext* ImportReaderParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, ImportReaderParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    functionCall();
    setState(401);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

ImportReaderParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::NestedStatementBodyContext::LBRACE() {
  return getToken(ImportReaderParser::LBRACE, 0);
}

tree::TerminalNode* ImportReaderParser::NestedStatementBodyContext::RBRACE() {
  return getToken(ImportReaderParser::RBRACE, 0);
}

std::vector<ImportReaderParser::StatementBodyContext *> ImportReaderParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<ImportReaderParser::StatementBodyContext>();
}

ImportReaderParser::StatementBodyContext* ImportReaderParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<ImportReaderParser::StatementBodyContext>(i);
}


size_t ImportReaderParser::NestedStatementBodyContext::getRuleIndex() const {
  return ImportReaderParser::RuleNestedStatementBody;
}

void ImportReaderParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void ImportReaderParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

ImportReaderParser::NestedStatementBodyContext* ImportReaderParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 82, ImportReaderParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    match(ImportReaderParser::LBRACE);
    setState(407);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImportReaderParser::NameID)
      | (1ULL << ImportReaderParser::LabelID)
      | (1ULL << ImportReaderParser::EnabledID)
      | (1ULL << ImportReaderParser::TypeID)
      | (1ULL << ImportReaderParser::IntID)
      | (1ULL << ImportReaderParser::RealID)
      | (1ULL << ImportReaderParser::BoolID)
      | (1ULL << ImportReaderParser::StringID)
      | (1ULL << ImportReaderParser::ThisID)
      | (1ULL << ImportReaderParser::ReturnID)
      | (1ULL << ImportReaderParser::EnumID)
      | (1ULL << ImportReaderParser::AttributeID)
      | (1ULL << ImportReaderParser::SignalID)
      | (1ULL << ImportReaderParser::PortID)
      | (1ULL << ImportReaderParser::ImportID)
      | (1ULL << ImportReaderParser::FromID)
      | (1ULL << ImportReaderParser::ToID)
      | (1ULL << ImportReaderParser::SendID)
      | (1ULL << ImportReaderParser::SwitchID)
      | (1ULL << ImportReaderParser::IfID)
      | (1ULL << ImportReaderParser::AsID)
      | (1ULL << ImportReaderParser::BREAK)
      | (1ULL << ImportReaderParser::ID))) != 0)) {
      setState(404);
      statementBody();
      setState(409);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(410);
    match(ImportReaderParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

ImportReaderParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ReturnStatementContext::ReturnID() {
  return getToken(ImportReaderParser::ReturnID, 0);
}

ImportReaderParser::OperationContext* ImportReaderParser::ReturnStatementContext::operation() {
  return getRuleContext<ImportReaderParser::OperationContext>(0);
}

tree::TerminalNode* ImportReaderParser::ReturnStatementContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}


size_t ImportReaderParser::ReturnStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleReturnStatement;
}

void ImportReaderParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void ImportReaderParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

ImportReaderParser::ReturnStatementContext* ImportReaderParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, ImportReaderParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(ImportReaderParser::ReturnID);
    setState(413);
    operation();
    setState(414);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

ImportReaderParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::BreakStatementContext::BREAK() {
  return getToken(ImportReaderParser::BREAK, 0);
}

tree::TerminalNode* ImportReaderParser::BreakStatementContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}


size_t ImportReaderParser::BreakStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleBreakStatement;
}

void ImportReaderParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void ImportReaderParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

ImportReaderParser::BreakStatementContext* ImportReaderParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 86, ImportReaderParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(ImportReaderParser::BREAK);
    setState(417);
    match(ImportReaderParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

ImportReaderParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::AtomContext* ImportReaderParser::OperationContext::atom() {
  return getRuleContext<ImportReaderParser::AtomContext>(0);
}

ImportReaderParser::OperationOptionalContext* ImportReaderParser::OperationContext::operationOptional() {
  return getRuleContext<ImportReaderParser::OperationOptionalContext>(0);
}

tree::TerminalNode* ImportReaderParser::OperationContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

ImportReaderParser::OperationContext* ImportReaderParser::OperationContext::operation() {
  return getRuleContext<ImportReaderParser::OperationContext>(0);
}

tree::TerminalNode* ImportReaderParser::OperationContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}

tree::TerminalNode* ImportReaderParser::OperationContext::MINUS() {
  return getToken(ImportReaderParser::MINUS, 0);
}

tree::TerminalNode* ImportReaderParser::OperationContext::NotIdSymbol() {
  return getToken(ImportReaderParser::NotIdSymbol, 0);
}


size_t ImportReaderParser::OperationContext::getRuleIndex() const {
  return ImportReaderParser::RuleOperation;
}

void ImportReaderParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void ImportReaderParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

ImportReaderParser::OperationContext* ImportReaderParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 88, ImportReaderParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(430);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::TriggerID:
      case ImportReaderParser::MessageTrigger:
      case ImportReaderParser::ThisID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::TrueID:
      case ImportReaderParser::FalseID:
      case ImportReaderParser::INT:
      case ImportReaderParser::REAL:
      case ImportReaderParser::STRING:
      case ImportReaderParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(419);
        atom();
        setState(420);
        operationOptional();
        break;
      }

      case ImportReaderParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(422);
        match(ImportReaderParser::LPAREN);
        setState(423);
        operation();
        setState(424);
        match(ImportReaderParser::RPAREN);
        break;
      }

      case ImportReaderParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(426);
        match(ImportReaderParser::MINUS);
        setState(427);
        operation();
        break;
      }

      case ImportReaderParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(428);
        match(ImportReaderParser::NotIdSymbol);
        setState(429);
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

ImportReaderParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::OperationContext* ImportReaderParser::OperationOptionalContext::operation() {
  return getRuleContext<ImportReaderParser::OperationContext>(0);
}

tree::TerminalNode* ImportReaderParser::OperationOptionalContext::MULT() {
  return getToken(ImportReaderParser::MULT, 0);
}

tree::TerminalNode* ImportReaderParser::OperationOptionalContext::DIV() {
  return getToken(ImportReaderParser::DIV, 0);
}

tree::TerminalNode* ImportReaderParser::OperationOptionalContext::PLUS() {
  return getToken(ImportReaderParser::PLUS, 0);
}

tree::TerminalNode* ImportReaderParser::OperationOptionalContext::MINUS() {
  return getToken(ImportReaderParser::MINUS, 0);
}


size_t ImportReaderParser::OperationOptionalContext::getRuleIndex() const {
  return ImportReaderParser::RuleOperationOptional;
}

void ImportReaderParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void ImportReaderParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

ImportReaderParser::OperationOptionalContext* ImportReaderParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 90, ImportReaderParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(435);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::PLUS:
      case ImportReaderParser::MINUS:
      case ImportReaderParser::MULT:
      case ImportReaderParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(432);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & ((1ULL << (ImportReaderParser::PLUS - 67))
          | (1ULL << (ImportReaderParser::MINUS - 67))
          | (1ULL << (ImportReaderParser::MULT - 67))
          | (1ULL << (ImportReaderParser::DIV - 67)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(433);
        operation();
        break;
      }

      case ImportReaderParser::NotIdSymbol:
      case ImportReaderParser::AndIdSymbol:
      case ImportReaderParser::OrIdSymbol:
      case ImportReaderParser::NotIdWord:
      case ImportReaderParser::AndIdWord:
      case ImportReaderParser::OrIdWord:
      case ImportReaderParser::ASSIGN:
      case ImportReaderParser::RPAREN:
      case ImportReaderParser::LESSTHAN:
      case ImportReaderParser::GREATERTHAN:
      case ImportReaderParser::SEMI: {
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

ImportReaderParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ExpressionContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

ImportReaderParser::ExpressionContext* ImportReaderParser::ExpressionContext::expression() {
  return getRuleContext<ImportReaderParser::ExpressionContext>(0);
}

tree::TerminalNode* ImportReaderParser::ExpressionContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}

ImportReaderParser::ExpressionOptionalContext* ImportReaderParser::ExpressionContext::expressionOptional() {
  return getRuleContext<ImportReaderParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* ImportReaderParser::ExpressionContext::NotIdSymbol() {
  return getToken(ImportReaderParser::NotIdSymbol, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionContext::NotIdWord() {
  return getToken(ImportReaderParser::NotIdWord, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionContext::MINUS() {
  return getToken(ImportReaderParser::MINUS, 0);
}

ImportReaderParser::OperationContext* ImportReaderParser::ExpressionContext::operation() {
  return getRuleContext<ImportReaderParser::OperationContext>(0);
}


size_t ImportReaderParser::ExpressionContext::getRuleIndex() const {
  return ImportReaderParser::RuleExpression;
}

void ImportReaderParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void ImportReaderParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

ImportReaderParser::ExpressionContext* ImportReaderParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 92, ImportReaderParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(451);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(437);
      match(ImportReaderParser::LPAREN);
      setState(438);
      expression();
      setState(439);
      match(ImportReaderParser::RPAREN);
      setState(440);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(442);
      match(ImportReaderParser::NotIdSymbol);
      setState(443);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(444);
      match(ImportReaderParser::NotIdWord);
      setState(445);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(446);
      match(ImportReaderParser::MINUS);
      setState(447);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(448);
      operation();
      setState(449);
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

ImportReaderParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::ExpressionContext* ImportReaderParser::ExpressionOptionalContext::expression() {
  return getRuleContext<ImportReaderParser::ExpressionContext>(0);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(ImportReaderParser::OrIdSymbol, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(ImportReaderParser::OrIdWord, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(ImportReaderParser::AndIdSymbol, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(ImportReaderParser::AndIdWord, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(ImportReaderParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> ImportReaderParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(ImportReaderParser::ASSIGN);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(ImportReaderParser::ASSIGN, i);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(ImportReaderParser::NotIdSymbol, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(ImportReaderParser::LESSTHAN, 0);
}

tree::TerminalNode* ImportReaderParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(ImportReaderParser::GREATERTHAN, 0);
}


size_t ImportReaderParser::ExpressionOptionalContext::getRuleIndex() const {
  return ImportReaderParser::RuleExpressionOptional;
}

void ImportReaderParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void ImportReaderParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

ImportReaderParser::ExpressionOptionalContext* ImportReaderParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 94, ImportReaderParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(476);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::NotIdSymbol:
      case ImportReaderParser::AndIdSymbol:
      case ImportReaderParser::OrIdSymbol:
      case ImportReaderParser::NotIdWord:
      case ImportReaderParser::AndIdWord:
      case ImportReaderParser::OrIdWord:
      case ImportReaderParser::ASSIGN:
      case ImportReaderParser::LESSTHAN:
      case ImportReaderParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(472);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ImportReaderParser::OrIdSymbol: {
            setState(453);
            match(ImportReaderParser::OrIdSymbol);
            break;
          }

          case ImportReaderParser::OrIdWord: {
            setState(454);
            match(ImportReaderParser::OrIdWord);
            break;
          }

          case ImportReaderParser::AndIdSymbol: {
            setState(455);
            match(ImportReaderParser::AndIdSymbol);
            break;
          }

          case ImportReaderParser::AndIdWord: {
            setState(456);
            match(ImportReaderParser::AndIdWord);
            break;
          }

          case ImportReaderParser::ASSIGN: {
            setState(457);
            match(ImportReaderParser::ASSIGN);
            setState(458);
            match(ImportReaderParser::ASSIGN);
            break;
          }

          case ImportReaderParser::NotIdSymbol: {
            setState(459);
            match(ImportReaderParser::NotIdSymbol);
            setState(460);
            match(ImportReaderParser::ASSIGN);
            break;
          }

          case ImportReaderParser::NotIdWord: {
            setState(461);
            match(ImportReaderParser::NotIdWord);
            break;
          }

          case ImportReaderParser::LESSTHAN: {
            setState(462);
            match(ImportReaderParser::LESSTHAN);
            setState(465);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case ImportReaderParser::ASSIGN: {
                setState(463);
                match(ImportReaderParser::ASSIGN);
                break;
              }

              case ImportReaderParser::NameID:
              case ImportReaderParser::LabelID:
              case ImportReaderParser::EnabledID:
              case ImportReaderParser::TypeID:
              case ImportReaderParser::TriggerID:
              case ImportReaderParser::MessageTrigger:
              case ImportReaderParser::ThisID:
              case ImportReaderParser::AttributeID:
              case ImportReaderParser::SignalID:
              case ImportReaderParser::PortID:
              case ImportReaderParser::ImportID:
              case ImportReaderParser::FromID:
              case ImportReaderParser::ToID:
              case ImportReaderParser::AsID:
              case ImportReaderParser::NotIdSymbol:
              case ImportReaderParser::NotIdWord:
              case ImportReaderParser::TrueID:
              case ImportReaderParser::FalseID:
              case ImportReaderParser::INT:
              case ImportReaderParser::REAL:
              case ImportReaderParser::STRING:
              case ImportReaderParser::ID:
              case ImportReaderParser::LPAREN:
              case ImportReaderParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case ImportReaderParser::GREATERTHAN: {
            setState(467);
            match(ImportReaderParser::GREATERTHAN);
            setState(470);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case ImportReaderParser::ASSIGN: {
                setState(468);
                match(ImportReaderParser::ASSIGN);
                break;
              }

              case ImportReaderParser::NameID:
              case ImportReaderParser::LabelID:
              case ImportReaderParser::EnabledID:
              case ImportReaderParser::TypeID:
              case ImportReaderParser::TriggerID:
              case ImportReaderParser::MessageTrigger:
              case ImportReaderParser::ThisID:
              case ImportReaderParser::AttributeID:
              case ImportReaderParser::SignalID:
              case ImportReaderParser::PortID:
              case ImportReaderParser::ImportID:
              case ImportReaderParser::FromID:
              case ImportReaderParser::ToID:
              case ImportReaderParser::AsID:
              case ImportReaderParser::NotIdSymbol:
              case ImportReaderParser::NotIdWord:
              case ImportReaderParser::TrueID:
              case ImportReaderParser::FalseID:
              case ImportReaderParser::INT:
              case ImportReaderParser::REAL:
              case ImportReaderParser::STRING:
              case ImportReaderParser::ID:
              case ImportReaderParser::LPAREN:
              case ImportReaderParser::MINUS: {
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
        setState(474);
        expression();
        break;
      }

      case ImportReaderParser::RPAREN:
      case ImportReaderParser::SEMI: {
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

ImportReaderParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::IfStatementContext* ImportReaderParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<ImportReaderParser::IfStatementContext>(0);
}

ImportReaderParser::ElseStatementContext* ImportReaderParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<ImportReaderParser::ElseStatementContext>(0);
}


size_t ImportReaderParser::ConditionalStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleConditionalStatement;
}

void ImportReaderParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void ImportReaderParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

ImportReaderParser::ConditionalStatementContext* ImportReaderParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, ImportReaderParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(478);
    ifStatement();
    setState(481);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(479);
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

ImportReaderParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::IfStatementContext::IfID() {
  return getToken(ImportReaderParser::IfID, 0);
}

ImportReaderParser::IfEuTContext* ImportReaderParser::IfStatementContext::ifEuT() {
  return getRuleContext<ImportReaderParser::IfEuTContext>(0);
}

ImportReaderParser::StatementDeclContext* ImportReaderParser::IfStatementContext::statementDecl() {
  return getRuleContext<ImportReaderParser::StatementDeclContext>(0);
}

tree::TerminalNode* ImportReaderParser::IfStatementContext::SEMI() {
  return getToken(ImportReaderParser::SEMI, 0);
}


size_t ImportReaderParser::IfStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleIfStatement;
}

void ImportReaderParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void ImportReaderParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

ImportReaderParser::IfStatementContext* ImportReaderParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, ImportReaderParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(483);
    match(ImportReaderParser::IfID);
    setState(484);
    ifEuT();
    setState(487);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::IntID:
      case ImportReaderParser::RealID:
      case ImportReaderParser::BoolID:
      case ImportReaderParser::StringID:
      case ImportReaderParser::ThisID:
      case ImportReaderParser::ReturnID:
      case ImportReaderParser::EnumID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::SendID:
      case ImportReaderParser::SwitchID:
      case ImportReaderParser::IfID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::BREAK:
      case ImportReaderParser::ID:
      case ImportReaderParser::LBRACE: {
        setState(485);
        statementDecl();
        break;
      }

      case ImportReaderParser::SEMI: {
        setState(486);
        match(ImportReaderParser::SEMI);
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

ImportReaderParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::IfEuTContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

ImportReaderParser::ExpressionContext* ImportReaderParser::IfEuTContext::expression() {
  return getRuleContext<ImportReaderParser::ExpressionContext>(0);
}

tree::TerminalNode* ImportReaderParser::IfEuTContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}


size_t ImportReaderParser::IfEuTContext::getRuleIndex() const {
  return ImportReaderParser::RuleIfEuT;
}

void ImportReaderParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void ImportReaderParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

ImportReaderParser::IfEuTContext* ImportReaderParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 100, ImportReaderParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
    match(ImportReaderParser::LPAREN);
    setState(490);
    expression();
    setState(491);
    match(ImportReaderParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

ImportReaderParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::ElseStatementContext::ElseID() {
  return getToken(ImportReaderParser::ElseID, 0);
}

ImportReaderParser::StatementDeclContext* ImportReaderParser::ElseStatementContext::statementDecl() {
  return getRuleContext<ImportReaderParser::StatementDeclContext>(0);
}


size_t ImportReaderParser::ElseStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleElseStatement;
}

void ImportReaderParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void ImportReaderParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

ImportReaderParser::ElseStatementContext* ImportReaderParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 102, ImportReaderParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    match(ImportReaderParser::ElseID);
    setState(494);
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

ImportReaderParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::SwitchStatementContext::SwitchID() {
  return getToken(ImportReaderParser::SwitchID, 0);
}

ImportReaderParser::SwitchPuTContext* ImportReaderParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<ImportReaderParser::SwitchPuTContext>(0);
}

tree::TerminalNode* ImportReaderParser::SwitchStatementContext::LBRACE() {
  return getToken(ImportReaderParser::LBRACE, 0);
}

tree::TerminalNode* ImportReaderParser::SwitchStatementContext::RBRACE() {
  return getToken(ImportReaderParser::RBRACE, 0);
}

ImportReaderParser::DefaultStatementContext* ImportReaderParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<ImportReaderParser::DefaultStatementContext>(0);
}

std::vector<ImportReaderParser::CaseStatementContext *> ImportReaderParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<ImportReaderParser::CaseStatementContext>();
}

ImportReaderParser::CaseStatementContext* ImportReaderParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<ImportReaderParser::CaseStatementContext>(i);
}


size_t ImportReaderParser::SwitchStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleSwitchStatement;
}

void ImportReaderParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void ImportReaderParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

ImportReaderParser::SwitchStatementContext* ImportReaderParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 104, ImportReaderParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    match(ImportReaderParser::SwitchID);
    setState(497);
    switchPuT();
    setState(498);
    match(ImportReaderParser::LBRACE);
    setState(502);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ImportReaderParser::CaseID) {
      setState(499);
      caseStatement();
      setState(504);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(507);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::DefaultID: {
        setState(505);
        defaultStatement();
        break;
      }

      case ImportReaderParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(509);
    match(ImportReaderParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

ImportReaderParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::SwitchPuTContext::LPAREN() {
  return getToken(ImportReaderParser::LPAREN, 0);
}

ImportReaderParser::ContextIDContext* ImportReaderParser::SwitchPuTContext::contextID() {
  return getRuleContext<ImportReaderParser::ContextIDContext>(0);
}

tree::TerminalNode* ImportReaderParser::SwitchPuTContext::RPAREN() {
  return getToken(ImportReaderParser::RPAREN, 0);
}


size_t ImportReaderParser::SwitchPuTContext::getRuleIndex() const {
  return ImportReaderParser::RuleSwitchPuT;
}

void ImportReaderParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void ImportReaderParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

ImportReaderParser::SwitchPuTContext* ImportReaderParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 106, ImportReaderParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    match(ImportReaderParser::LPAREN);
    setState(512);
    contextID();
    setState(513);
    match(ImportReaderParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

ImportReaderParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::CaseStatementContext::CaseID() {
  return getToken(ImportReaderParser::CaseID, 0);
}

ImportReaderParser::LiteralValueContext* ImportReaderParser::CaseStatementContext::literalValue() {
  return getRuleContext<ImportReaderParser::LiteralValueContext>(0);
}

tree::TerminalNode* ImportReaderParser::CaseStatementContext::COLON() {
  return getToken(ImportReaderParser::COLON, 0);
}

ImportReaderParser::NestedStatementBodyContext* ImportReaderParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<ImportReaderParser::NestedStatementBodyContext>(0);
}

std::vector<ImportReaderParser::StatementBodyContext *> ImportReaderParser::CaseStatementContext::statementBody() {
  return getRuleContexts<ImportReaderParser::StatementBodyContext>();
}

ImportReaderParser::StatementBodyContext* ImportReaderParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<ImportReaderParser::StatementBodyContext>(i);
}


size_t ImportReaderParser::CaseStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleCaseStatement;
}

void ImportReaderParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void ImportReaderParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

ImportReaderParser::CaseStatementContext* ImportReaderParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 108, ImportReaderParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    match(ImportReaderParser::CaseID);
    setState(516);
    literalValue();
    setState(517);
    match(ImportReaderParser::COLON);
    setState(525);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::LBRACE: {
        setState(518);
        nestedStatementBody();
        break;
      }

      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::IntID:
      case ImportReaderParser::RealID:
      case ImportReaderParser::BoolID:
      case ImportReaderParser::StringID:
      case ImportReaderParser::ThisID:
      case ImportReaderParser::ReturnID:
      case ImportReaderParser::EnumID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::SendID:
      case ImportReaderParser::SwitchID:
      case ImportReaderParser::CaseID:
      case ImportReaderParser::DefaultID:
      case ImportReaderParser::IfID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::BREAK:
      case ImportReaderParser::ID:
      case ImportReaderParser::RBRACE: {
        setState(522);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ImportReaderParser::NameID)
          | (1ULL << ImportReaderParser::LabelID)
          | (1ULL << ImportReaderParser::EnabledID)
          | (1ULL << ImportReaderParser::TypeID)
          | (1ULL << ImportReaderParser::IntID)
          | (1ULL << ImportReaderParser::RealID)
          | (1ULL << ImportReaderParser::BoolID)
          | (1ULL << ImportReaderParser::StringID)
          | (1ULL << ImportReaderParser::ThisID)
          | (1ULL << ImportReaderParser::ReturnID)
          | (1ULL << ImportReaderParser::EnumID)
          | (1ULL << ImportReaderParser::AttributeID)
          | (1ULL << ImportReaderParser::SignalID)
          | (1ULL << ImportReaderParser::PortID)
          | (1ULL << ImportReaderParser::ImportID)
          | (1ULL << ImportReaderParser::FromID)
          | (1ULL << ImportReaderParser::ToID)
          | (1ULL << ImportReaderParser::SendID)
          | (1ULL << ImportReaderParser::SwitchID)
          | (1ULL << ImportReaderParser::IfID)
          | (1ULL << ImportReaderParser::AsID)
          | (1ULL << ImportReaderParser::BREAK)
          | (1ULL << ImportReaderParser::ID))) != 0)) {
          setState(519);
          statementBody();
          setState(524);
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

ImportReaderParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImportReaderParser::DefaultStatementContext::DefaultID() {
  return getToken(ImportReaderParser::DefaultID, 0);
}

tree::TerminalNode* ImportReaderParser::DefaultStatementContext::COLON() {
  return getToken(ImportReaderParser::COLON, 0);
}

ImportReaderParser::NestedStatementBodyContext* ImportReaderParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<ImportReaderParser::NestedStatementBodyContext>(0);
}

std::vector<ImportReaderParser::StatementBodyContext *> ImportReaderParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<ImportReaderParser::StatementBodyContext>();
}

ImportReaderParser::StatementBodyContext* ImportReaderParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<ImportReaderParser::StatementBodyContext>(i);
}


size_t ImportReaderParser::DefaultStatementContext::getRuleIndex() const {
  return ImportReaderParser::RuleDefaultStatement;
}

void ImportReaderParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void ImportReaderParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

ImportReaderParser::DefaultStatementContext* ImportReaderParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, ImportReaderParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    match(ImportReaderParser::DefaultID);
    setState(528);
    match(ImportReaderParser::COLON);
    setState(536);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImportReaderParser::LBRACE: {
        setState(529);
        nestedStatementBody();
        break;
      }

      case ImportReaderParser::NameID:
      case ImportReaderParser::LabelID:
      case ImportReaderParser::EnabledID:
      case ImportReaderParser::TypeID:
      case ImportReaderParser::IntID:
      case ImportReaderParser::RealID:
      case ImportReaderParser::BoolID:
      case ImportReaderParser::StringID:
      case ImportReaderParser::ThisID:
      case ImportReaderParser::ReturnID:
      case ImportReaderParser::EnumID:
      case ImportReaderParser::AttributeID:
      case ImportReaderParser::SignalID:
      case ImportReaderParser::PortID:
      case ImportReaderParser::ImportID:
      case ImportReaderParser::FromID:
      case ImportReaderParser::ToID:
      case ImportReaderParser::SendID:
      case ImportReaderParser::SwitchID:
      case ImportReaderParser::IfID:
      case ImportReaderParser::AsID:
      case ImportReaderParser::BREAK:
      case ImportReaderParser::ID:
      case ImportReaderParser::RBRACE: {
        setState(533);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ImportReaderParser::NameID)
          | (1ULL << ImportReaderParser::LabelID)
          | (1ULL << ImportReaderParser::EnabledID)
          | (1ULL << ImportReaderParser::TypeID)
          | (1ULL << ImportReaderParser::IntID)
          | (1ULL << ImportReaderParser::RealID)
          | (1ULL << ImportReaderParser::BoolID)
          | (1ULL << ImportReaderParser::StringID)
          | (1ULL << ImportReaderParser::ThisID)
          | (1ULL << ImportReaderParser::ReturnID)
          | (1ULL << ImportReaderParser::EnumID)
          | (1ULL << ImportReaderParser::AttributeID)
          | (1ULL << ImportReaderParser::SignalID)
          | (1ULL << ImportReaderParser::PortID)
          | (1ULL << ImportReaderParser::ImportID)
          | (1ULL << ImportReaderParser::FromID)
          | (1ULL << ImportReaderParser::ToID)
          | (1ULL << ImportReaderParser::SendID)
          | (1ULL << ImportReaderParser::SwitchID)
          | (1ULL << ImportReaderParser::IfID)
          | (1ULL << ImportReaderParser::AsID)
          | (1ULL << ImportReaderParser::BREAK)
          | (1ULL << ImportReaderParser::ID))) != 0)) {
          setState(530);
          statementBody();
          setState(535);
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

ImportReaderParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ImportReaderParser::SignalParamNameContext* ImportReaderParser::AtomContext::signalParamName() {
  return getRuleContext<ImportReaderParser::SignalParamNameContext>(0);
}

ImportReaderParser::AttributeNameContext* ImportReaderParser::AtomContext::attributeName() {
  return getRuleContext<ImportReaderParser::AttributeNameContext>(0);
}

ImportReaderParser::FunctionCallContext* ImportReaderParser::AtomContext::functionCall() {
  return getRuleContext<ImportReaderParser::FunctionCallContext>(0);
}

ImportReaderParser::LiteralValueContext* ImportReaderParser::AtomContext::literalValue() {
  return getRuleContext<ImportReaderParser::LiteralValueContext>(0);
}


size_t ImportReaderParser::AtomContext::getRuleIndex() const {
  return ImportReaderParser::RuleAtom;
}

void ImportReaderParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void ImportReaderParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImportReaderListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

ImportReaderParser::AtomContext* ImportReaderParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 112, ImportReaderParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(542);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(538);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(539);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(540);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(541);
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
std::vector<dfa::DFA> ImportReaderParser::_decisionToDFA;
atn::PredictionContextCache ImportReaderParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ImportReaderParser::_atn;
std::vector<uint16_t> ImportReaderParser::_serializedATN;

std::vector<std::string> ImportReaderParser::_ruleNames = {
  "importReader", "componentIdPath", "signalIdPath", "attributeIdPath", 
  "signalSend", "commonDecl", "importPathDecl", "importPathBody", "importFileBody", 
  "importAs", "typeDefDecl", "typeDecl", "intTypeDecl", "realTypeDecl", 
  "enumTypeDecl", "attributeDecl", "literalValue", "signalParamName", "attributeName", 
  "toPortName", "attributeAssignStatement", "localAssignStatement", "sendToStatement", 
  "singleAssignment", "multiAssignment", "signalDecl", "paramDecl", "functionDecl", 
  "functionParameters", "functionCall", "functionCallBody", "functionCallBodyOptional", 
  "contextID", "triggerDecl", "thisDecl", "portDecl", "nameDecl", "idPath", 
  "statementDecl", "statementBody", "functionCallStatement", "nestedStatementBody", 
  "returnStatement", "breakStatement", "operation", "operationOptional", 
  "expression", "expressionOptional", "conditionalStatement", "ifStatement", 
  "ifEuT", "elseStatement", "switchStatement", "switchPuT", "caseStatement", 
  "defaultStatement", "atom"
};

std::vector<std::string> ImportReaderParser::_literalNames = {
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

std::vector<std::string> ImportReaderParser::_symbolicNames = {
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

dfa::Vocabulary ImportReaderParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ImportReaderParser::_tokenNames;

ImportReaderParser::Initializer::Initializer() {
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
    0x3, 0x4d, 0x223, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x7a, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x7d, 
    0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x82, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x85, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x8b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x8e, 0xb, 0x5, 0x5, 0x5, 
    0x90, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x9a, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0x9d, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xa3, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xb6, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xbb, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xc8, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xd1, 0xa, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0xda, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x7, 0x10, 0xe1, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xe4, 0xb, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0xed, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xf7, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0xfe, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x10f, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 
    0x18, 0x117, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x5, 0x19, 0x11d, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x121, 
    0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x124, 0xb, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 
    0x1b, 0x12e, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x131, 0xb, 0x1b, 0x3, 
    0x1b, 0x5, 0x1b, 0x134, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 
    0x138, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 
    0x1d, 0x145, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x14d, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 
    0x150, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x15c, 
    0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 
    0x21, 0x163, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x7, 0x25, 0x171, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x174, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x180, 
    0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x183, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 
    0x5, 0x28, 0x187, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x191, 0xa, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x198, 
    0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x19b, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1b1, 
    0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x1b6, 0xa, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x5, 0x30, 0x1c6, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1d4, 0xa, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1d9, 0xa, 0x31, 0x5, 0x31, 0x1db, 
    0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1df, 0xa, 0x31, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x1e4, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x1ea, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 
    0x36, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x1f7, 0xa, 0x36, 0xc, 0x36, 
    0xe, 0x36, 0x1fa, 0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x1fe, 
    0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 
    0x20b, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x20e, 0xb, 0x38, 0x5, 0x38, 
    0x210, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 
    0x216, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x219, 0xb, 0x39, 0x5, 0x39, 
    0x21b, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 
    0x221, 0xa, 0x3a, 0x3, 0x3a, 0x2, 0x2, 0x3b, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
    0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 
    0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 
    0x6c, 0x6e, 0x70, 0x72, 0x2, 0x5, 0x6, 0x2, 0x4, 0x7, 0x15, 0x1a, 0x22, 
    0x22, 0x35, 0x35, 0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 0x45, 0x48, 0x2, 0x23a, 
    0x2, 0x74, 0x3, 0x2, 0x2, 0x2, 0x4, 0x76, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x8f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x12, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0x16, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x20, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x24, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x28, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x104, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x109, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x30, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x32, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x127, 0x3, 0x2, 0x2, 0x2, 0x36, 0x13b, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x151, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x15b, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x162, 0x3, 0x2, 0x2, 0x2, 0x42, 0x164, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x166, 0x3, 0x2, 0x2, 0x2, 0x46, 0x169, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x16c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x177, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x17c, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x186, 0x3, 0x2, 0x2, 0x2, 0x50, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x192, 0x3, 0x2, 0x2, 0x2, 0x54, 0x195, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1a2, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1b5, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x1e0, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1eb, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1f2, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x201, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x205, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x211, 0x3, 0x2, 0x2, 0x2, 0x72, 0x220, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x75, 0x5, 0xe, 0x8, 0x2, 0x75, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x7b, 0x5, 0x42, 0x22, 0x2, 0x77, 0x78, 0x7, 0x44, 0x2, 0x2, 0x78, 
    0x7a, 0x5, 0x42, 0x22, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x83, 0x5, 0x42, 0x22, 0x2, 0x7f, 0x80, 0x7, 0x44, 0x2, 
    0x2, 0x80, 0x82, 0x5, 0x42, 0x22, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x85, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x90, 0x5, 0x26, 0x14, 0x2, 0x87, 0x8c, 0x5, 
    0x42, 0x22, 0x2, 0x88, 0x89, 0x7, 0x44, 0x2, 0x2, 0x89, 0x8b, 0x5, 0x42, 
    0x22, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x87, 0x3, 0x2, 0x2, 0x2, 0x90, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x6, 0x4, 0x2, 0x92, 0x93, 0x7, 
    0x38, 0x2, 0x2, 0x93, 0x94, 0x5, 0x3e, 0x20, 0x2, 0x94, 0x95, 0x7, 0x39, 
    0x2, 0x2, 0x95, 0xb, 0x3, 0x2, 0x2, 0x2, 0x96, 0x9a, 0x5, 0x16, 0xc, 
    0x2, 0x97, 0x9a, 0x5, 0x20, 0x11, 0x2, 0x98, 0x9a, 0x5, 0x34, 0x1b, 
    0x2, 0x99, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x5, 
    0x10, 0x9, 0x2, 0x9f, 0xa0, 0x5, 0xe, 0x8, 0x2, 0xa0, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0xa5, 0x7, 0x18, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x3e, 0x2, 0x2, 0xa6, 
    0xa7, 0x5, 0x12, 0xa, 0x2, 0xa7, 0xa8, 0x7, 0x3f, 0x2, 0x2, 0xa8, 0xa9, 
    0x5, 0x14, 0xb, 0x2, 0xa9, 0x11, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x5, 
    0x42, 0x22, 0x2, 0xab, 0xac, 0x7, 0x44, 0x2, 0x2, 0xac, 0xad, 0x5, 0x42, 
    0x22, 0x2, 0xad, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x31, 0x2, 
    0x2, 0xaf, 0xb0, 0x7, 0x48, 0x2, 0x2, 0xb0, 0xb6, 0x5, 0x12, 0xa, 0x2, 
    0xb1, 0xb2, 0x5, 0x42, 0x22, 0x2, 0xb2, 0xb3, 0x7, 0x48, 0x2, 0x2, 0xb3, 
    0xb4, 0x5, 0x12, 0xa, 0x2, 0xb4, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x22, 
    0x2, 0x2, 0xb8, 0xbb, 0x5, 0x42, 0x22, 0x2, 0xb9, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0x15, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x7, 0x2, 0x2, 0xbd, 
    0xbe, 0x5, 0x18, 0xd, 0x2, 0xbe, 0xbf, 0x5, 0x42, 0x22, 0x2, 0xbf, 0xc0, 
    0x7, 0x41, 0x2, 0x2, 0xc0, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc8, 0x5, 
    0x1a, 0xe, 0x2, 0xc2, 0xc8, 0x5, 0x1c, 0xf, 0x2, 0xc3, 0xc8, 0x5, 0x1e, 
    0x10, 0x2, 0xc4, 0xc8, 0x7, 0xa, 0x2, 0x2, 0xc5, 0xc8, 0x7, 0xb, 0x2, 
    0x2, 0xc6, 0xc8, 0x5, 0x42, 0x22, 0x2, 0xc7, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xd0, 0x7, 
    0x8, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x38, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x32, 
    0x2, 0x2, 0xcc, 0xcd, 0x7, 0x31, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x32, 0x2, 
    0x2, 0xce, 0xd1, 0x7, 0x39, 0x2, 0x2, 0xcf, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd9, 0x7, 0x9, 0x2, 0x2, 0xd3, 0xd4, 
    0x7, 0x38, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x33, 0x2, 0x2, 0xd5, 0xd6, 0x7, 
    0x31, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x33, 0x2, 0x2, 0xd7, 0xda, 0x7, 0x39, 
    0x2, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0xdb, 0xdc, 0x7, 0x12, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x38, 0x2, 0x2, 0xdd, 
    0xe2, 0x5, 0x42, 0x22, 0x2, 0xde, 0xdf, 0x7, 0x42, 0x2, 0x2, 0xdf, 0xe1, 
    0x5, 0x42, 0x22, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xe6, 0x7, 0x39, 0x2, 0x2, 0xe6, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xe8, 0x7, 0x15, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x18, 0xd, 0x2, 0xe9, 
    0xec, 0x5, 0x42, 0x22, 0x2, 0xea, 0xeb, 0x7, 0x2d, 0x2, 0x2, 0xeb, 0xed, 
    0x5, 0x22, 0x12, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x41, 
    0x2, 0x2, 0xef, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf7, 0x7, 0x32, 0x2, 
    0x2, 0xf1, 0xf7, 0x7, 0x33, 0x2, 0x2, 0xf2, 0xf7, 0x7, 0x34, 0x2, 0x2, 
    0xf3, 0xf7, 0x7, 0x2a, 0x2, 0x2, 0xf4, 0xf7, 0x7, 0x2b, 0x2, 0x2, 0xf5, 
    0xf7, 0x5, 0x42, 0x22, 0x2, 0xf6, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x44, 0x23, 
    0x2, 0xf9, 0xfa, 0x5, 0x42, 0x22, 0x2, 0xfa, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xfe, 0x5, 0x46, 0x24, 0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfd, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x5, 0x42, 0x22, 0x2, 0x100, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0x1a, 0x2, 0x2, 0x102, 0x103, 
    0x5, 0x42, 0x22, 0x2, 0x103, 0x29, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 
    0x5, 0x26, 0x14, 0x2, 0x105, 0x106, 0x7, 0x2d, 0x2, 0x2, 0x106, 0x107, 
    0x5, 0x5e, 0x30, 0x2, 0x107, 0x108, 0x7, 0x41, 0x2, 0x2, 0x108, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x18, 0xd, 0x2, 0x10a, 0x10e, 
    0x5, 0x42, 0x22, 0x2, 0x10b, 0x10c, 0x7, 0x2d, 0x2, 0x2, 0x10c, 0x10f, 
    0x5, 0x5e, 0x30, 0x2, 0x10d, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x7, 0x41, 0x2, 0x2, 0x111, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x1b, 0x2, 0x2, 0x113, 0x116, 
    0x5, 0xa, 0x6, 0x2, 0x114, 0x117, 0x5, 0x28, 0x15, 0x2, 0x115, 0x117, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 0x115, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
    0x7, 0x41, 0x2, 0x2, 0x119, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 
    0x5, 0x2a, 0x16, 0x2, 0x11b, 0x11d, 0x5, 0x2e, 0x18, 0x2, 0x11c, 0x11a, 
    0x3, 0x2, 0x2, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x11e, 0x122, 0x7, 0x3a, 0x2, 0x2, 0x11f, 0x121, 0x5, 
    0x30, 0x19, 0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x124, 0x3, 
    0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x123, 0x125, 0x3, 0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 
    0x2, 0x2, 0x2, 0x125, 0x126, 0x7, 0x3b, 0x2, 0x2, 0x126, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x128, 0x7, 0x16, 0x2, 0x2, 0x128, 0x137, 0x5, 
    0x42, 0x22, 0x2, 0x129, 0x133, 0x7, 0x38, 0x2, 0x2, 0x12a, 0x12f, 0x5, 
    0x36, 0x1c, 0x2, 0x12b, 0x12c, 0x7, 0x42, 0x2, 0x2, 0x12c, 0x12e, 0x5, 
    0x36, 0x1c, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x130, 0x134, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x132, 0x134, 0x3, 0x2, 0x2, 0x2, 0x133, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x138, 0x7, 0x39, 0x2, 0x2, 0x136, 0x138, 0x3, 
    0x2, 0x2, 0x2, 0x137, 0x129, 0x3, 0x2, 0x2, 0x2, 0x137, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x7, 
    0x41, 0x2, 0x2, 0x13a, 0x35, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x5, 
    0x18, 0xd, 0x2, 0x13c, 0x13d, 0x5, 0x42, 0x22, 0x2, 0x13d, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x1c, 0x2, 0x2, 0x13f, 0x140, 0x5, 
    0x18, 0xd, 0x2, 0x140, 0x141, 0x5, 0x4c, 0x27, 0x2, 0x141, 0x144, 0x7, 
    0x38, 0x2, 0x2, 0x142, 0x145, 0x5, 0x3a, 0x1e, 0x2, 0x143, 0x145, 0x3, 
    0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 
    0x39, 0x2, 0x2, 0x147, 0x148, 0x5, 0x54, 0x2b, 0x2, 0x148, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x149, 0x14e, 0x5, 0x36, 0x1c, 0x2, 0x14a, 0x14b, 0x7, 
    0x42, 0x2, 0x2, 0x14b, 0x14d, 0x5, 0x36, 0x1c, 0x2, 0x14c, 0x14a, 0x3, 
    0x2, 0x2, 0x2, 0x14d, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14c, 0x3, 
    0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x5, 0x4c, 
    0x27, 0x2, 0x152, 0x153, 0x7, 0x38, 0x2, 0x2, 0x153, 0x154, 0x5, 0x3e, 
    0x20, 0x2, 0x154, 0x155, 0x7, 0x39, 0x2, 0x2, 0x155, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x156, 0x15c, 0x5, 0x22, 0x12, 0x2, 0x157, 0x15c, 0x5, 0x24, 
    0x13, 0x2, 0x158, 0x15c, 0x5, 0x26, 0x14, 0x2, 0x159, 0x15c, 0x5, 0x3c, 
    0x1f, 0x2, 0x15a, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x15c, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x40, 
    0x21, 0x2, 0x15e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x42, 
    0x2, 0x2, 0x160, 0x163, 0x5, 0x3e, 0x20, 0x2, 0x161, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x162, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x162, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x41, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x9, 0x2, 0x2, 
    0x2, 0x165, 0x43, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x9, 0x3, 0x2, 0x2, 
    0x167, 0x168, 0x7, 0x44, 0x2, 0x2, 0x168, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x169, 0x16a, 0x7, 0xe, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x44, 0x2, 0x2, 
    0x16b, 0x47, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x17, 0x2, 0x2, 
    0x16d, 0x172, 0x5, 0x42, 0x22, 0x2, 0x16e, 0x16f, 0x7, 0x42, 0x2, 0x2, 
    0x16f, 0x171, 0x5, 0x42, 0x22, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x174, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 
    0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x175, 0x3, 0x2, 0x2, 0x2, 
    0x174, 0x172, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x7, 0x41, 0x2, 0x2, 
    0x176, 0x49, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x7, 0x4, 0x2, 0x2, 0x178, 
    0x179, 0x7, 0x40, 0x2, 0x2, 0x179, 0x17a, 0x5, 0x42, 0x22, 0x2, 0x17a, 
    0x17b, 0x7, 0x41, 0x2, 0x2, 0x17b, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x181, 0x5, 0x42, 0x22, 0x2, 0x17d, 0x17e, 0x7, 0x44, 0x2, 0x2, 0x17e, 
    0x180, 0x5, 0x42, 0x22, 0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x180, 
    0x183, 0x3, 0x2, 0x2, 0x2, 0x181, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x181, 
    0x182, 0x3, 0x2, 0x2, 0x2, 0x182, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x183, 0x181, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x187, 0x5, 0x50, 0x29, 0x2, 0x185, 0x187, 
    0x5, 0x54, 0x2b, 0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 0x2, 0x186, 0x185, 
    0x3, 0x2, 0x2, 0x2, 0x187, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x188, 0x191, 0x5, 
    0x52, 0x2a, 0x2, 0x189, 0x191, 0x5, 0x2a, 0x16, 0x2, 0x18a, 0x191, 0x5, 
    0x6a, 0x36, 0x2, 0x18b, 0x191, 0x5, 0x62, 0x32, 0x2, 0x18c, 0x191, 0x5, 
    0x2c, 0x17, 0x2, 0x18d, 0x191, 0x5, 0x2e, 0x18, 0x2, 0x18e, 0x191, 0x5, 
    0x58, 0x2d, 0x2, 0x18f, 0x191, 0x5, 0x56, 0x2c, 0x2, 0x190, 0x188, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x189, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18a, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18c, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18e, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x192, 0x193, 0x5, 0x3c, 0x1f, 0x2, 0x193, 0x194, 0x7, 0x41, 
    0x2, 0x2, 0x194, 0x53, 0x3, 0x2, 0x2, 0x2, 0x195, 0x199, 0x7, 0x3a, 
    0x2, 0x2, 0x196, 0x198, 0x5, 0x50, 0x29, 0x2, 0x197, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x198, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x199, 0x197, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19c, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 0x7, 0x3b, 
    0x2, 0x2, 0x19d, 0x55, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0xf, 0x2, 
    0x2, 0x19f, 0x1a0, 0x5, 0x5a, 0x2e, 0x2, 0x1a0, 0x1a1, 0x7, 0x41, 0x2, 
    0x2, 0x1a1, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x2c, 0x2, 
    0x2, 0x1a3, 0x1a4, 0x7, 0x41, 0x2, 0x2, 0x1a4, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x1a5, 0x1a6, 0x5, 0x72, 0x3a, 0x2, 0x1a6, 0x1a7, 0x5, 0x5c, 0x2f, 
    0x2, 0x1a7, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x38, 0x2, 
    0x2, 0x1a9, 0x1aa, 0x5, 0x5a, 0x2e, 0x2, 0x1aa, 0x1ab, 0x7, 0x39, 0x2, 
    0x2, 0x1ab, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x46, 0x2, 
    0x2, 0x1ad, 0x1b1, 0x5, 0x5a, 0x2e, 0x2, 0x1ae, 0x1af, 0x7, 0x24, 0x2, 
    0x2, 0x1af, 0x1b1, 0x5, 0x5a, 0x2e, 0x2, 0x1b0, 0x1a5, 0x3, 0x2, 0x2, 
    0x2, 0x1b0, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ac, 0x3, 0x2, 0x2, 
    0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x1b2, 0x1b3, 0x9, 0x4, 0x2, 0x2, 0x1b3, 0x1b6, 0x5, 0x5a, 0x2e, 0x2, 
    0x1b4, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b2, 0x3, 0x2, 0x2, 0x2, 
    0x1b5, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1b7, 
    0x1b8, 0x7, 0x38, 0x2, 0x2, 0x1b8, 0x1b9, 0x5, 0x5e, 0x30, 0x2, 0x1b9, 
    0x1ba, 0x7, 0x39, 0x2, 0x2, 0x1ba, 0x1bb, 0x5, 0x60, 0x31, 0x2, 0x1bb, 
    0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x24, 0x2, 0x2, 0x1bd, 
    0x1c6, 0x5, 0x5e, 0x30, 0x2, 0x1be, 0x1bf, 0x7, 0x27, 0x2, 0x2, 0x1bf, 
    0x1c6, 0x5, 0x5e, 0x30, 0x2, 0x1c0, 0x1c1, 0x7, 0x46, 0x2, 0x2, 0x1c1, 
    0x1c6, 0x5, 0x5e, 0x30, 0x2, 0x1c2, 0x1c3, 0x5, 0x5a, 0x2e, 0x2, 0x1c3, 
    0x1c4, 0x5, 0x60, 0x31, 0x2, 0x1c4, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1db, 
    0x7, 0x26, 0x2, 0x2, 0x1c8, 0x1db, 0x7, 0x29, 0x2, 0x2, 0x1c9, 0x1db, 
    0x7, 0x25, 0x2, 0x2, 0x1ca, 0x1db, 0x7, 0x28, 0x2, 0x2, 0x1cb, 0x1cc, 
    0x7, 0x2d, 0x2, 0x2, 0x1cc, 0x1db, 0x7, 0x2d, 0x2, 0x2, 0x1cd, 0x1ce, 
    0x7, 0x24, 0x2, 0x2, 0x1ce, 0x1db, 0x7, 0x2d, 0x2, 0x2, 0x1cf, 0x1db, 
    0x7, 0x27, 0x2, 0x2, 0x1d0, 0x1d3, 0x7, 0x3e, 0x2, 0x2, 0x1d1, 0x1d4, 
    0x7, 0x2d, 0x2, 0x2, 0x1d2, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d1, 
    0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1db, 
    0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d8, 0x7, 0x3f, 0x2, 0x2, 0x1d6, 0x1d9, 
    0x7, 0x2d, 0x2, 0x2, 0x1d7, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d6, 
    0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1db, 
    0x3, 0x2, 0x2, 0x2, 0x1da, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1c8, 
    0x3, 0x2, 0x2, 0x2, 0x1da, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1ca, 
    0x3, 0x2, 0x2, 0x2, 0x1da, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1cd, 
    0x3, 0x2, 0x2, 0x2, 0x1da, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d0, 
    0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 
    0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1df, 0x5, 0x5e, 0x30, 0x2, 0x1dd, 0x1df, 
    0x3, 0x2, 0x2, 0x2, 0x1de, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1dd, 
    0x3, 0x2, 0x2, 0x2, 0x1df, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e3, 0x5, 
    0x64, 0x33, 0x2, 0x1e1, 0x1e4, 0x5, 0x68, 0x35, 0x2, 0x1e2, 0x1e4, 0x3, 
    0x2, 0x2, 0x2, 0x1e3, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e2, 0x3, 
    0x2, 0x2, 0x2, 0x1e4, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0x20, 
    0x2, 0x2, 0x1e6, 0x1e9, 0x5, 0x66, 0x34, 0x2, 0x1e7, 0x1ea, 0x5, 0x4e, 
    0x28, 0x2, 0x1e8, 0x1ea, 0x7, 0x41, 0x2, 0x2, 0x1e9, 0x1e7, 0x3, 0x2, 
    0x2, 0x2, 0x1e9, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x1eb, 0x1ec, 0x7, 0x38, 0x2, 0x2, 0x1ec, 0x1ed, 0x5, 0x5e, 0x30, 
    0x2, 0x1ed, 0x1ee, 0x7, 0x39, 0x2, 0x2, 0x1ee, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1f0, 0x7, 0x21, 0x2, 0x2, 0x1f0, 0x1f1, 0x5, 0x4e, 0x28, 
    0x2, 0x1f1, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x7, 0x1d, 0x2, 
    0x2, 0x1f3, 0x1f4, 0x5, 0x6c, 0x37, 0x2, 0x1f4, 0x1f8, 0x7, 0x3a, 0x2, 
    0x2, 0x1f5, 0x1f7, 0x5, 0x6e, 0x38, 0x2, 0x1f6, 0x1f5, 0x3, 0x2, 0x2, 
    0x2, 0x1f7, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f6, 0x3, 0x2, 0x2, 
    0x2, 0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fd, 0x3, 0x2, 0x2, 
    0x2, 0x1fa, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fe, 0x5, 0x70, 0x39, 
    0x2, 0x1fc, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 0x2, 
    0x2, 0x1fd, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 
    0x2, 0x1ff, 0x200, 0x7, 0x3b, 0x2, 0x2, 0x200, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x202, 0x7, 0x38, 0x2, 0x2, 0x202, 0x203, 0x5, 0x42, 0x22, 
    0x2, 0x203, 0x204, 0x7, 0x39, 0x2, 0x2, 0x204, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x205, 0x206, 0x7, 0x1e, 0x2, 0x2, 0x206, 0x207, 0x5, 0x22, 0x12, 
    0x2, 0x207, 0x20f, 0x7, 0x40, 0x2, 0x2, 0x208, 0x210, 0x5, 0x54, 0x2b, 
    0x2, 0x209, 0x20b, 0x5, 0x50, 0x29, 0x2, 0x20a, 0x209, 0x3, 0x2, 0x2, 
    0x2, 0x20b, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x210, 0x3, 0x2, 0x2, 
    0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x208, 0x3, 0x2, 0x2, 
    0x2, 0x20f, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x210, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x211, 0x212, 0x7, 0x1f, 0x2, 0x2, 0x212, 0x21a, 0x7, 0x40, 0x2, 0x2, 
    0x213, 0x21b, 0x5, 0x54, 0x2b, 0x2, 0x214, 0x216, 0x5, 0x50, 0x29, 0x2, 
    0x215, 0x214, 0x3, 0x2, 0x2, 0x2, 0x216, 0x219, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 
    0x218, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x213, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x21b, 0x71, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x221, 0x5, 0x24, 0x13, 0x2, 
    0x21d, 0x221, 0x5, 0x26, 0x14, 0x2, 0x21e, 0x221, 0x5, 0x3c, 0x1f, 0x2, 
    0x21f, 0x221, 0x5, 0x22, 0x12, 0x2, 0x220, 0x21c, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x220, 0x21e, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x221, 0x73, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x7b, 0x83, 0x8c, 0x8f, 0x99, 0x9b, 0xa2, 0xb5, 0xba, 0xc7, 0xd0, 0xd9, 
    0xe2, 0xec, 0xf6, 0xfd, 0x10e, 0x116, 0x11c, 0x122, 0x12f, 0x133, 0x137, 
    0x144, 0x14e, 0x15b, 0x162, 0x172, 0x181, 0x186, 0x190, 0x199, 0x1b0, 
    0x1b5, 0x1c5, 0x1d3, 0x1d8, 0x1da, 0x1de, 0x1e3, 0x1e9, 0x1f8, 0x1fd, 
    0x20c, 0x20f, 0x217, 0x21a, 0x220, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ImportReaderParser::Initializer ImportReaderParser::_init;
