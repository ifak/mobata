
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/TestSystemDecl.g4 by ANTLR 4.7.2


#include "TestSystemDeclListener.h"

#include "TestSystemDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

TestSystemDeclParser::TestSystemDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TestSystemDeclParser::~TestSystemDeclParser() {
  delete _interpreter;
}

std::string TestSystemDeclParser::getGrammarFileName() const {
  return "TestSystemDecl.g4";
}

const std::vector<std::string>& TestSystemDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TestSystemDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- TestSystemDeclContext ------------------------------------------------------------------

TestSystemDeclParser::TestSystemDeclContext::TestSystemDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::ImportPathDeclContext* TestSystemDeclParser::TestSystemDeclContext::importPathDecl() {
  return getRuleContext<TestSystemDeclParser::ImportPathDeclContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::TestSystemDeclContext::TestSystemID() {
  return getToken(TestSystemDeclParser::TestSystemID, 0);
}

tree::TerminalNode* TestSystemDeclParser::TestSystemDeclContext::LBRACE() {
  return getToken(TestSystemDeclParser::LBRACE, 0);
}

TestSystemDeclParser::TestSystemBodyContext* TestSystemDeclParser::TestSystemDeclContext::testSystemBody() {
  return getRuleContext<TestSystemDeclParser::TestSystemBodyContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::TestSystemDeclContext::RBRACE() {
  return getToken(TestSystemDeclParser::RBRACE, 0);
}


size_t TestSystemDeclParser::TestSystemDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTestSystemDecl;
}

void TestSystemDeclParser::TestSystemDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestSystemDecl(this);
}

void TestSystemDeclParser::TestSystemDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestSystemDecl(this);
}

TestSystemDeclParser::TestSystemDeclContext* TestSystemDeclParser::testSystemDecl() {
  TestSystemDeclContext *_localctx = _tracker.createInstance<TestSystemDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, TestSystemDeclParser::RuleTestSystemDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    importPathDecl();
    setState(139);
    match(TestSystemDeclParser::TestSystemID);
    setState(140);
    match(TestSystemDeclParser::LBRACE);
    setState(141);
    testSystemBody();
    setState(142);
    match(TestSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TestSystemBodyContext ------------------------------------------------------------------

TestSystemDeclParser::TestSystemBodyContext::TestSystemBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::NameDeclContext* TestSystemDeclParser::TestSystemBodyContext::nameDecl() {
  return getRuleContext<TestSystemDeclParser::NameDeclContext>(0);
}

TestSystemDeclParser::TestSystemBodyOptionalContext* TestSystemDeclParser::TestSystemBodyContext::testSystemBodyOptional() {
  return getRuleContext<TestSystemDeclParser::TestSystemBodyOptionalContext>(0);
}

TestSystemDeclParser::LinkDeclsContext* TestSystemDeclParser::TestSystemBodyContext::linkDecls() {
  return getRuleContext<TestSystemDeclParser::LinkDeclsContext>(0);
}


size_t TestSystemDeclParser::TestSystemBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTestSystemBody;
}

void TestSystemDeclParser::TestSystemBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestSystemBody(this);
}

void TestSystemDeclParser::TestSystemBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestSystemBody(this);
}

TestSystemDeclParser::TestSystemBodyContext* TestSystemDeclParser::testSystemBody() {
  TestSystemBodyContext *_localctx = _tracker.createInstance<TestSystemBodyContext>(_ctx, getState());
  enterRule(_localctx, 2, TestSystemDeclParser::RuleTestSystemBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    nameDecl();
    setState(145);
    testSystemBodyOptional();
    setState(146);
    linkDecls();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TestSystemBodyOptionalContext ------------------------------------------------------------------

TestSystemDeclParser::TestSystemBodyOptionalContext::TestSystemBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::AttributeDeclContext* TestSystemDeclParser::TestSystemBodyOptionalContext::attributeDecl() {
  return getRuleContext<TestSystemDeclParser::AttributeDeclContext>(0);
}

TestSystemDeclParser::TestSystemBodyOptionalContext* TestSystemDeclParser::TestSystemBodyOptionalContext::testSystemBodyOptional() {
  return getRuleContext<TestSystemDeclParser::TestSystemBodyOptionalContext>(0);
}

TestSystemDeclParser::TestCompDeclContext* TestSystemDeclParser::TestSystemBodyOptionalContext::testCompDecl() {
  return getRuleContext<TestSystemDeclParser::TestCompDeclContext>(0);
}


size_t TestSystemDeclParser::TestSystemBodyOptionalContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTestSystemBodyOptional;
}

void TestSystemDeclParser::TestSystemBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestSystemBodyOptional(this);
}

void TestSystemDeclParser::TestSystemBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestSystemBodyOptional(this);
}

TestSystemDeclParser::TestSystemBodyOptionalContext* TestSystemDeclParser::testSystemBodyOptional() {
  TestSystemBodyOptionalContext *_localctx = _tracker.createInstance<TestSystemBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 4, TestSystemDeclParser::RuleTestSystemBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(148);
        attributeDecl();
        setState(149);
        testSystemBodyOptional();
        break;
      }

      case TestSystemDeclParser::TestComponentID: {
        enterOuterAlt(_localctx, 2);
        setState(151);
        testCompDecl();
        setState(152);
        testSystemBodyOptional();
        break;
      }

      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::RBRACE: {
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

//----------------- TestCompDeclContext ------------------------------------------------------------------

TestSystemDeclParser::TestCompDeclContext::TestCompDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::TestCompDeclContext::TestComponentID() {
  return getToken(TestSystemDeclParser::TestComponentID, 0);
}

tree::TerminalNode* TestSystemDeclParser::TestCompDeclContext::LBRACE() {
  return getToken(TestSystemDeclParser::LBRACE, 0);
}

TestSystemDeclParser::TestCompBodyContext* TestSystemDeclParser::TestCompDeclContext::testCompBody() {
  return getRuleContext<TestSystemDeclParser::TestCompBodyContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::TestCompDeclContext::RBRACE() {
  return getToken(TestSystemDeclParser::RBRACE, 0);
}


size_t TestSystemDeclParser::TestCompDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTestCompDecl;
}

void TestSystemDeclParser::TestCompDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestCompDecl(this);
}

void TestSystemDeclParser::TestCompDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestCompDecl(this);
}

TestSystemDeclParser::TestCompDeclContext* TestSystemDeclParser::testCompDecl() {
  TestCompDeclContext *_localctx = _tracker.createInstance<TestCompDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, TestSystemDeclParser::RuleTestCompDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(TestSystemDeclParser::TestComponentID);
    setState(158);
    match(TestSystemDeclParser::LBRACE);
    setState(159);
    testCompBody();
    setState(160);
    match(TestSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TestCompBodyContext ------------------------------------------------------------------

TestSystemDeclParser::TestCompBodyContext::TestCompBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::NameDeclContext* TestSystemDeclParser::TestCompBodyContext::nameDecl() {
  return getRuleContext<TestSystemDeclParser::NameDeclContext>(0);
}

TestSystemDeclParser::TestCompBodyOtionalContext* TestSystemDeclParser::TestCompBodyContext::testCompBodyOtional() {
  return getRuleContext<TestSystemDeclParser::TestCompBodyOtionalContext>(0);
}


size_t TestSystemDeclParser::TestCompBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTestCompBody;
}

void TestSystemDeclParser::TestCompBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestCompBody(this);
}

void TestSystemDeclParser::TestCompBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestCompBody(this);
}

TestSystemDeclParser::TestCompBodyContext* TestSystemDeclParser::testCompBody() {
  TestCompBodyContext *_localctx = _tracker.createInstance<TestCompBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, TestSystemDeclParser::RuleTestCompBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    nameDecl();
    setState(163);
    testCompBodyOtional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnabledDeclContext ------------------------------------------------------------------

TestSystemDeclParser::EnabledDeclContext::EnabledDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::EnabledDeclContext::EnabledID() {
  return getToken(TestSystemDeclParser::EnabledID, 0);
}

tree::TerminalNode* TestSystemDeclParser::EnabledDeclContext::COLON() {
  return getToken(TestSystemDeclParser::COLON, 0);
}

tree::TerminalNode* TestSystemDeclParser::EnabledDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* TestSystemDeclParser::EnabledDeclContext::TrueID() {
  return getToken(TestSystemDeclParser::TrueID, 0);
}

tree::TerminalNode* TestSystemDeclParser::EnabledDeclContext::FalseID() {
  return getToken(TestSystemDeclParser::FalseID, 0);
}


size_t TestSystemDeclParser::EnabledDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleEnabledDecl;
}

void TestSystemDeclParser::EnabledDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnabledDecl(this);
}

void TestSystemDeclParser::EnabledDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnabledDecl(this);
}

TestSystemDeclParser::EnabledDeclContext* TestSystemDeclParser::enabledDecl() {
  EnabledDeclContext *_localctx = _tracker.createInstance<EnabledDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, TestSystemDeclParser::RuleEnabledDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(TestSystemDeclParser::EnabledID);
    setState(166);
    match(TestSystemDeclParser::COLON);
    setState(167);
    _la = _input->LA(1);
    if (!(_la == TestSystemDeclParser::TrueID

    || _la == TestSystemDeclParser::FalseID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(168);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TestCompBodyOtionalContext ------------------------------------------------------------------

TestSystemDeclParser::TestCompBodyOtionalContext::TestCompBodyOtionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::AttributeDeclContext* TestSystemDeclParser::TestCompBodyOtionalContext::attributeDecl() {
  return getRuleContext<TestSystemDeclParser::AttributeDeclContext>(0);
}

TestSystemDeclParser::TestCompBodyOtionalContext* TestSystemDeclParser::TestCompBodyOtionalContext::testCompBodyOtional() {
  return getRuleContext<TestSystemDeclParser::TestCompBodyOtionalContext>(0);
}

TestSystemDeclParser::PortDeclContext* TestSystemDeclParser::TestCompBodyOtionalContext::portDecl() {
  return getRuleContext<TestSystemDeclParser::PortDeclContext>(0);
}

TestSystemDeclParser::EnabledDeclContext* TestSystemDeclParser::TestCompBodyOtionalContext::enabledDecl() {
  return getRuleContext<TestSystemDeclParser::EnabledDeclContext>(0);
}


size_t TestSystemDeclParser::TestCompBodyOtionalContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTestCompBodyOtional;
}

void TestSystemDeclParser::TestCompBodyOtionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestCompBodyOtional(this);
}

void TestSystemDeclParser::TestCompBodyOtionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestCompBodyOtional(this);
}

TestSystemDeclParser::TestCompBodyOtionalContext* TestSystemDeclParser::testCompBodyOtional() {
  TestCompBodyOtionalContext *_localctx = _tracker.createInstance<TestCompBodyOtionalContext>(_ctx, getState());
  enterRule(_localctx, 12, TestSystemDeclParser::RuleTestCompBodyOtional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(170);
        attributeDecl();
        setState(171);
        testCompBodyOtional();
        break;
      }

      case TestSystemDeclParser::PortID: {
        enterOuterAlt(_localctx, 2);
        setState(173);
        portDecl();
        setState(174);
        testCompBodyOtional();
        break;
      }

      case TestSystemDeclParser::EnabledID: {
        enterOuterAlt(_localctx, 3);
        setState(176);
        enabledDecl();
        setState(177);
        testCompBodyOtional();
        break;
      }

      case TestSystemDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 4);

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

//----------------- LinkDeclsContext ------------------------------------------------------------------

TestSystemDeclParser::LinkDeclsContext::LinkDeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::LinkDeclContext* TestSystemDeclParser::LinkDeclsContext::linkDecl() {
  return getRuleContext<TestSystemDeclParser::LinkDeclContext>(0);
}

TestSystemDeclParser::LinkDeclsContext* TestSystemDeclParser::LinkDeclsContext::linkDecls() {
  return getRuleContext<TestSystemDeclParser::LinkDeclsContext>(0);
}


size_t TestSystemDeclParser::LinkDeclsContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleLinkDecls;
}

void TestSystemDeclParser::LinkDeclsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLinkDecls(this);
}

void TestSystemDeclParser::LinkDeclsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLinkDecls(this);
}

TestSystemDeclParser::LinkDeclsContext* TestSystemDeclParser::linkDecls() {
  LinkDeclsContext *_localctx = _tracker.createInstance<LinkDeclsContext>(_ctx, getState());
  enterRule(_localctx, 14, TestSystemDeclParser::RuleLinkDecls);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(186);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::LinkID: {
        enterOuterAlt(_localctx, 1);
        setState(182);
        linkDecl();
        setState(183);
        linkDecls();
        break;
      }

      case TestSystemDeclParser::RBRACE: {
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

//----------------- LinkDeclContext ------------------------------------------------------------------

TestSystemDeclParser::LinkDeclContext::LinkDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::LinkDeclContext::LinkID() {
  return getToken(TestSystemDeclParser::LinkID, 0);
}

tree::TerminalNode* TestSystemDeclParser::LinkDeclContext::LBRACE() {
  return getToken(TestSystemDeclParser::LBRACE, 0);
}

TestSystemDeclParser::LinkBodyContext* TestSystemDeclParser::LinkDeclContext::linkBody() {
  return getRuleContext<TestSystemDeclParser::LinkBodyContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::LinkDeclContext::RBRACE() {
  return getToken(TestSystemDeclParser::RBRACE, 0);
}


size_t TestSystemDeclParser::LinkDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleLinkDecl;
}

void TestSystemDeclParser::LinkDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLinkDecl(this);
}

void TestSystemDeclParser::LinkDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLinkDecl(this);
}

TestSystemDeclParser::LinkDeclContext* TestSystemDeclParser::linkDecl() {
  LinkDeclContext *_localctx = _tracker.createInstance<LinkDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, TestSystemDeclParser::RuleLinkDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(TestSystemDeclParser::LinkID);
    setState(189);
    match(TestSystemDeclParser::LBRACE);
    setState(190);
    linkBody();
    setState(191);
    match(TestSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LinkBodyContext ------------------------------------------------------------------

TestSystemDeclParser::LinkBodyContext::LinkBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::LabelDeclContext* TestSystemDeclParser::LinkBodyContext::labelDecl() {
  return getRuleContext<TestSystemDeclParser::LabelDeclContext>(0);
}

TestSystemDeclParser::LinkBodyContext* TestSystemDeclParser::LinkBodyContext::linkBody() {
  return getRuleContext<TestSystemDeclParser::LinkBodyContext>(0);
}

TestSystemDeclParser::TargetDeclContext* TestSystemDeclParser::LinkBodyContext::targetDecl() {
  return getRuleContext<TestSystemDeclParser::TargetDeclContext>(0);
}

TestSystemDeclParser::SourceDeclContext* TestSystemDeclParser::LinkBodyContext::sourceDecl() {
  return getRuleContext<TestSystemDeclParser::SourceDeclContext>(0);
}


size_t TestSystemDeclParser::LinkBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleLinkBody;
}

void TestSystemDeclParser::LinkBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLinkBody(this);
}

void TestSystemDeclParser::LinkBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLinkBody(this);
}

TestSystemDeclParser::LinkBodyContext* TestSystemDeclParser::linkBody() {
  LinkBodyContext *_localctx = _tracker.createInstance<LinkBodyContext>(_ctx, getState());
  enterRule(_localctx, 18, TestSystemDeclParser::RuleLinkBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::LabelID: {
        enterOuterAlt(_localctx, 1);
        setState(193);
        labelDecl();
        setState(194);
        linkBody();
        break;
      }

      case TestSystemDeclParser::TargetID: {
        enterOuterAlt(_localctx, 2);
        setState(196);
        targetDecl();
        setState(197);
        linkBody();
        break;
      }

      case TestSystemDeclParser::SourceID: {
        enterOuterAlt(_localctx, 3);
        setState(199);
        sourceDecl();
        setState(200);
        linkBody();
        break;
      }

      case TestSystemDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 4);

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

//----------------- LabelDeclContext ------------------------------------------------------------------

TestSystemDeclParser::LabelDeclContext::LabelDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::LabelDeclContext::LabelID() {
  return getToken(TestSystemDeclParser::LabelID, 0);
}

tree::TerminalNode* TestSystemDeclParser::LabelDeclContext::COLON() {
  return getToken(TestSystemDeclParser::COLON, 0);
}

tree::TerminalNode* TestSystemDeclParser::LabelDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* TestSystemDeclParser::LabelDeclContext::STRING() {
  return getToken(TestSystemDeclParser::STRING, 0);
}


size_t TestSystemDeclParser::LabelDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleLabelDecl;
}

void TestSystemDeclParser::LabelDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabelDecl(this);
}

void TestSystemDeclParser::LabelDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabelDecl(this);
}

TestSystemDeclParser::LabelDeclContext* TestSystemDeclParser::labelDecl() {
  LabelDeclContext *_localctx = _tracker.createInstance<LabelDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, TestSystemDeclParser::RuleLabelDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(TestSystemDeclParser::LabelID);
    setState(206);
    match(TestSystemDeclParser::COLON);
    setState(207);
    dynamic_cast<LabelDeclContext *>(_localctx)->label = match(TestSystemDeclParser::STRING);
    setState(208);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetDeclContext ------------------------------------------------------------------

TestSystemDeclParser::TargetDeclContext::TargetDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::TargetDeclContext::TargetID() {
  return getToken(TestSystemDeclParser::TargetID, 0);
}

tree::TerminalNode* TestSystemDeclParser::TargetDeclContext::COLON() {
  return getToken(TestSystemDeclParser::COLON, 0);
}

tree::TerminalNode* TestSystemDeclParser::TargetDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

TestSystemDeclParser::IdPathContext* TestSystemDeclParser::TargetDeclContext::idPath() {
  return getRuleContext<TestSystemDeclParser::IdPathContext>(0);
}


size_t TestSystemDeclParser::TargetDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTargetDecl;
}

void TestSystemDeclParser::TargetDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTargetDecl(this);
}

void TestSystemDeclParser::TargetDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTargetDecl(this);
}

TestSystemDeclParser::TargetDeclContext* TestSystemDeclParser::targetDecl() {
  TargetDeclContext *_localctx = _tracker.createInstance<TargetDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, TestSystemDeclParser::RuleTargetDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(TestSystemDeclParser::TargetID);
    setState(211);
    match(TestSystemDeclParser::COLON);
    setState(212);
    dynamic_cast<TargetDeclContext *>(_localctx)->target = idPath();
    setState(213);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceDeclContext ------------------------------------------------------------------

TestSystemDeclParser::SourceDeclContext::SourceDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::SourceDeclContext::SourceID() {
  return getToken(TestSystemDeclParser::SourceID, 0);
}

tree::TerminalNode* TestSystemDeclParser::SourceDeclContext::COLON() {
  return getToken(TestSystemDeclParser::COLON, 0);
}

tree::TerminalNode* TestSystemDeclParser::SourceDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

TestSystemDeclParser::IdPathContext* TestSystemDeclParser::SourceDeclContext::idPath() {
  return getRuleContext<TestSystemDeclParser::IdPathContext>(0);
}


size_t TestSystemDeclParser::SourceDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSourceDecl;
}

void TestSystemDeclParser::SourceDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourceDecl(this);
}

void TestSystemDeclParser::SourceDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourceDecl(this);
}

TestSystemDeclParser::SourceDeclContext* TestSystemDeclParser::sourceDecl() {
  SourceDeclContext *_localctx = _tracker.createInstance<SourceDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, TestSystemDeclParser::RuleSourceDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(TestSystemDeclParser::SourceID);
    setState(216);
    match(TestSystemDeclParser::COLON);
    setState(217);
    dynamic_cast<SourceDeclContext *>(_localctx)->source = idPath();
    setState(218);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextIDContext ------------------------------------------------------------------

TestSystemDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::ID() {
  return getToken(TestSystemDeclParser::ID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::NameID() {
  return getToken(TestSystemDeclParser::NameID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::LabelID() {
  return getToken(TestSystemDeclParser::LabelID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::EnabledID() {
  return getToken(TestSystemDeclParser::EnabledID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::TypeID() {
  return getToken(TestSystemDeclParser::TypeID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::MessageTrigger() {
  return getToken(TestSystemDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::TriggerID() {
  return getToken(TestSystemDeclParser::TriggerID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::AttributeID() {
  return getToken(TestSystemDeclParser::AttributeID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::SignalID() {
  return getToken(TestSystemDeclParser::SignalID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::PortID() {
  return getToken(TestSystemDeclParser::PortID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::ImportID() {
  return getToken(TestSystemDeclParser::ImportID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::FromID() {
  return getToken(TestSystemDeclParser::FromID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::ToID() {
  return getToken(TestSystemDeclParser::ToID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::SendID() {
  return getToken(TestSystemDeclParser::SendID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::AsID() {
  return getToken(TestSystemDeclParser::AsID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::TestComponentID() {
  return getToken(TestSystemDeclParser::TestComponentID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::TestSystemID() {
  return getToken(TestSystemDeclParser::TestSystemID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::LinkID() {
  return getToken(TestSystemDeclParser::LinkID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::TargetID() {
  return getToken(TestSystemDeclParser::TargetID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ContextIDContext::SourceID() {
  return getToken(TestSystemDeclParser::SourceID, 0);
}


size_t TestSystemDeclParser::ContextIDContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleContextID;
}

void TestSystemDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void TestSystemDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 26, TestSystemDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        match(TestSystemDeclParser::ID);
        break;
      }

      case TestSystemDeclParser::NameID: {
        enterOuterAlt(_localctx, 2);
        setState(221);
        match(TestSystemDeclParser::NameID);
        break;
      }

      case TestSystemDeclParser::LabelID: {
        enterOuterAlt(_localctx, 3);
        setState(222);
        match(TestSystemDeclParser::LabelID);
        break;
      }

      case TestSystemDeclParser::EnabledID: {
        enterOuterAlt(_localctx, 4);
        setState(223);
        match(TestSystemDeclParser::EnabledID);
        break;
      }

      case TestSystemDeclParser::TypeID: {
        enterOuterAlt(_localctx, 5);
        setState(224);
        match(TestSystemDeclParser::TypeID);
        break;
      }

      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger: {
        enterOuterAlt(_localctx, 6);
        setState(225);
        _la = _input->LA(1);
        if (!(_la == TestSystemDeclParser::TriggerID

        || _la == TestSystemDeclParser::MessageTrigger)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case TestSystemDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 7);
        setState(226);
        match(TestSystemDeclParser::AttributeID);
        break;
      }

      case TestSystemDeclParser::SignalID: {
        enterOuterAlt(_localctx, 8);
        setState(227);
        match(TestSystemDeclParser::SignalID);
        break;
      }

      case TestSystemDeclParser::PortID: {
        enterOuterAlt(_localctx, 9);
        setState(228);
        match(TestSystemDeclParser::PortID);
        break;
      }

      case TestSystemDeclParser::ImportID: {
        enterOuterAlt(_localctx, 10);
        setState(229);
        match(TestSystemDeclParser::ImportID);
        break;
      }

      case TestSystemDeclParser::FromID: {
        enterOuterAlt(_localctx, 11);
        setState(230);
        match(TestSystemDeclParser::FromID);
        break;
      }

      case TestSystemDeclParser::ToID: {
        enterOuterAlt(_localctx, 12);
        setState(231);
        match(TestSystemDeclParser::ToID);
        break;
      }

      case TestSystemDeclParser::SendID: {
        enterOuterAlt(_localctx, 13);
        setState(232);
        match(TestSystemDeclParser::SendID);
        break;
      }

      case TestSystemDeclParser::AsID: {
        enterOuterAlt(_localctx, 14);
        setState(233);
        match(TestSystemDeclParser::AsID);
        break;
      }

      case TestSystemDeclParser::TestComponentID: {
        enterOuterAlt(_localctx, 15);
        setState(234);
        match(TestSystemDeclParser::TestComponentID);
        break;
      }

      case TestSystemDeclParser::TestSystemID: {
        enterOuterAlt(_localctx, 16);
        setState(235);
        match(TestSystemDeclParser::TestSystemID);
        break;
      }

      case TestSystemDeclParser::LinkID: {
        enterOuterAlt(_localctx, 17);
        setState(236);
        match(TestSystemDeclParser::LinkID);
        break;
      }

      case TestSystemDeclParser::TargetID: {
        enterOuterAlt(_localctx, 18);
        setState(237);
        match(TestSystemDeclParser::TargetID);
        break;
      }

      case TestSystemDeclParser::SourceID: {
        enterOuterAlt(_localctx, 19);
        setState(238);
        match(TestSystemDeclParser::SourceID);
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

TestSystemDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestSystemDeclParser::ContextIDContext *> TestSystemDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<TestSystemDeclParser::ContextIDContext>();
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(TestSystemDeclParser::DOT);
}

tree::TerminalNode* TestSystemDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(TestSystemDeclParser::DOT, i);
}


size_t TestSystemDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleComponentIdPath;
}

void TestSystemDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void TestSystemDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

TestSystemDeclParser::ComponentIdPathContext* TestSystemDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 28, TestSystemDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    contextID();
    setState(246);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestSystemDeclParser::DOT) {
      setState(242);
      match(TestSystemDeclParser::DOT);
      setState(243);
      contextID();
      setState(248);
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

TestSystemDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestSystemDeclParser::ContextIDContext *> TestSystemDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<TestSystemDeclParser::ContextIDContext>();
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::SignalIdPathContext::DOT() {
  return getTokens(TestSystemDeclParser::DOT);
}

tree::TerminalNode* TestSystemDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(TestSystemDeclParser::DOT, i);
}


size_t TestSystemDeclParser::SignalIdPathContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSignalIdPath;
}

void TestSystemDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void TestSystemDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

TestSystemDeclParser::SignalIdPathContext* TestSystemDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 30, TestSystemDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    contextID();
    setState(254);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestSystemDeclParser::DOT) {
      setState(250);
      match(TestSystemDeclParser::DOT);
      setState(251);
      contextID();
      setState(256);
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

TestSystemDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::AttributeNameContext* TestSystemDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<TestSystemDeclParser::AttributeNameContext>(0);
}

std::vector<TestSystemDeclParser::ContextIDContext *> TestSystemDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<TestSystemDeclParser::ContextIDContext>();
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(TestSystemDeclParser::DOT);
}

tree::TerminalNode* TestSystemDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(TestSystemDeclParser::DOT, i);
}


size_t TestSystemDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleAttributeIdPath;
}

void TestSystemDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void TestSystemDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

TestSystemDeclParser::AttributeIdPathContext* TestSystemDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 32, TestSystemDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(257);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(258);
      contextID();
      setState(263);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TestSystemDeclParser::DOT) {
        setState(259);
        match(TestSystemDeclParser::DOT);
        setState(260);
        contextID();
        setState(265);
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

TestSystemDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::SignalIdPathContext* TestSystemDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<TestSystemDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::SignalSendContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

TestSystemDeclParser::FunctionCallBodyContext* TestSystemDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<TestSystemDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::SignalSendContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}


size_t TestSystemDeclParser::SignalSendContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSignalSend;
}

void TestSystemDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void TestSystemDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

TestSystemDeclParser::SignalSendContext* TestSystemDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 34, TestSystemDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    signalIdPath();
    setState(269);
    match(TestSystemDeclParser::LPAREN);
    setState(270);
    functionCallBody();
    setState(271);
    match(TestSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

TestSystemDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestSystemDeclParser::TypeDefDeclContext *> TestSystemDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<TestSystemDeclParser::TypeDefDeclContext>();
}

TestSystemDeclParser::TypeDefDeclContext* TestSystemDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<TestSystemDeclParser::TypeDefDeclContext>(i);
}

std::vector<TestSystemDeclParser::AttributeDeclContext *> TestSystemDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<TestSystemDeclParser::AttributeDeclContext>();
}

TestSystemDeclParser::AttributeDeclContext* TestSystemDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<TestSystemDeclParser::AttributeDeclContext>(i);
}

std::vector<TestSystemDeclParser::SignalDeclContext *> TestSystemDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<TestSystemDeclParser::SignalDeclContext>();
}

TestSystemDeclParser::SignalDeclContext* TestSystemDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<TestSystemDeclParser::SignalDeclContext>(i);
}


size_t TestSystemDeclParser::CommonDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleCommonDecl;
}

void TestSystemDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void TestSystemDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

TestSystemDeclParser::CommonDeclContext* TestSystemDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, TestSystemDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestSystemDeclParser::TypeID)
      | (1ULL << TestSystemDeclParser::AttributeID)
      | (1ULL << TestSystemDeclParser::SignalID))) != 0)) {
      setState(276);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TestSystemDeclParser::TypeID: {
          setState(273);
          typeDefDecl();
          break;
        }

        case TestSystemDeclParser::AttributeID: {
          setState(274);
          attributeDecl();
          break;
        }

        case TestSystemDeclParser::SignalID: {
          setState(275);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(280);
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

TestSystemDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::ImportPathBodyContext* TestSystemDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<TestSystemDeclParser::ImportPathBodyContext>(0);
}

TestSystemDeclParser::ImportPathDeclContext* TestSystemDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<TestSystemDeclParser::ImportPathDeclContext>(0);
}


size_t TestSystemDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleImportPathDecl;
}

void TestSystemDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void TestSystemDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

TestSystemDeclParser::ImportPathDeclContext* TestSystemDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 38, TestSystemDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::ImportID: {
        enterOuterAlt(_localctx, 1);
        setState(281);
        importPathBody();
        setState(282);
        importPathDecl();
        break;
      }

      case TestSystemDeclParser::TestSystemID: {
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

TestSystemDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(TestSystemDeclParser::ImportID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(TestSystemDeclParser::LESSTHAN, 0);
}

TestSystemDeclParser::ImportFileBodyContext* TestSystemDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<TestSystemDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(TestSystemDeclParser::GREATERTHAN, 0);
}

TestSystemDeclParser::ImportAsContext* TestSystemDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<TestSystemDeclParser::ImportAsContext>(0);
}


size_t TestSystemDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleImportPathBody;
}

void TestSystemDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void TestSystemDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

TestSystemDeclParser::ImportPathBodyContext* TestSystemDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 40, TestSystemDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(TestSystemDeclParser::ImportID);
    setState(288);
    match(TestSystemDeclParser::LESSTHAN);
    setState(289);
    importFileBody();
    setState(290);
    match(TestSystemDeclParser::GREATERTHAN);
    setState(291);
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

TestSystemDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestSystemDeclParser::ContextIDContext *> TestSystemDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<TestSystemDeclParser::ContextIDContext>();
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TestSystemDeclParser::ImportFileBodyContext::DOT() {
  return getToken(TestSystemDeclParser::DOT, 0);
}

tree::TerminalNode* TestSystemDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(TestSystemDeclParser::RANGE, 0);
}

tree::TerminalNode* TestSystemDeclParser::ImportFileBodyContext::DIV() {
  return getToken(TestSystemDeclParser::DIV, 0);
}

TestSystemDeclParser::ImportFileBodyContext* TestSystemDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<TestSystemDeclParser::ImportFileBodyContext>(0);
}


size_t TestSystemDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleImportFileBody;
}

void TestSystemDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void TestSystemDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

TestSystemDeclParser::ImportFileBodyContext* TestSystemDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 42, TestSystemDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(293);
      contextID();
      setState(294);
      match(TestSystemDeclParser::DOT);
      setState(295);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(297);
      match(TestSystemDeclParser::RANGE);
      setState(298);
      match(TestSystemDeclParser::DIV);
      setState(299);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(300);
      contextID();
      setState(301);
      match(TestSystemDeclParser::DIV);
      setState(302);
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

TestSystemDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ImportAsContext::AsID() {
  return getToken(TestSystemDeclParser::AsID, 0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::ImportAsContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}


size_t TestSystemDeclParser::ImportAsContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleImportAs;
}

void TestSystemDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void TestSystemDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

TestSystemDeclParser::ImportAsContext* TestSystemDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 44, TestSystemDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(309);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(306);
        match(TestSystemDeclParser::AsID);
        setState(307);
        contextID();
        break;
      }

      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::ImportID: {
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

TestSystemDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(TestSystemDeclParser::TypeID, 0);
}

TestSystemDeclParser::TypeDeclContext* TestSystemDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<TestSystemDeclParser::TypeDeclContext>(0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}


size_t TestSystemDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTypeDefDecl;
}

void TestSystemDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void TestSystemDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

TestSystemDeclParser::TypeDefDeclContext* TestSystemDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 46, TestSystemDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    match(TestSystemDeclParser::TypeID);
    setState(312);
    typeDecl();
    setState(313);
    contextID();
    setState(314);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

TestSystemDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::IntTypeDeclContext* TestSystemDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<TestSystemDeclParser::IntTypeDeclContext>(0);
}

TestSystemDeclParser::RealTypeDeclContext* TestSystemDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<TestSystemDeclParser::RealTypeDeclContext>(0);
}

TestSystemDeclParser::EnumTypeDeclContext* TestSystemDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<TestSystemDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::TypeDeclContext::BoolID() {
  return getToken(TestSystemDeclParser::BoolID, 0);
}

tree::TerminalNode* TestSystemDeclParser::TypeDeclContext::StringID() {
  return getToken(TestSystemDeclParser::StringID, 0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}


size_t TestSystemDeclParser::TypeDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTypeDecl;
}

void TestSystemDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void TestSystemDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

TestSystemDeclParser::TypeDeclContext* TestSystemDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 48, TestSystemDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(316);
        intTypeDecl();
        break;
      }

      case TestSystemDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(317);
        realTypeDecl();
        break;
      }

      case TestSystemDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(318);
        enumTypeDecl();
        break;
      }

      case TestSystemDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(319);
        match(TestSystemDeclParser::BoolID);
        break;
      }

      case TestSystemDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(320);
        match(TestSystemDeclParser::StringID);
        break;
      }

      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(321);
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

TestSystemDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::IntTypeDeclContext::IntID() {
  return getToken(TestSystemDeclParser::IntID, 0);
}

tree::TerminalNode* TestSystemDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::IntTypeDeclContext::INT() {
  return getTokens(TestSystemDeclParser::INT);
}

tree::TerminalNode* TestSystemDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(TestSystemDeclParser::INT, i);
}

tree::TerminalNode* TestSystemDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(TestSystemDeclParser::RANGE, 0);
}

tree::TerminalNode* TestSystemDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}


size_t TestSystemDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleIntTypeDecl;
}

void TestSystemDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void TestSystemDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

TestSystemDeclParser::IntTypeDeclContext* TestSystemDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 50, TestSystemDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(TestSystemDeclParser::IntID);
    setState(331);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::LPAREN: {
        setState(325);
        match(TestSystemDeclParser::LPAREN);
        setState(326);
        match(TestSystemDeclParser::INT);
        setState(327);
        match(TestSystemDeclParser::RANGE);
        setState(328);
        match(TestSystemDeclParser::INT);
        setState(329);
        match(TestSystemDeclParser::RPAREN);
        break;
      }

      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::ID: {
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

TestSystemDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::RealTypeDeclContext::RealID() {
  return getToken(TestSystemDeclParser::RealID, 0);
}

tree::TerminalNode* TestSystemDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(TestSystemDeclParser::REAL);
}

tree::TerminalNode* TestSystemDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(TestSystemDeclParser::REAL, i);
}

tree::TerminalNode* TestSystemDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(TestSystemDeclParser::RANGE, 0);
}

tree::TerminalNode* TestSystemDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}


size_t TestSystemDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleRealTypeDecl;
}

void TestSystemDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void TestSystemDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

TestSystemDeclParser::RealTypeDeclContext* TestSystemDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, TestSystemDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    match(TestSystemDeclParser::RealID);
    setState(340);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::LPAREN: {
        setState(334);
        match(TestSystemDeclParser::LPAREN);
        setState(335);
        match(TestSystemDeclParser::REAL);
        setState(336);
        match(TestSystemDeclParser::RANGE);
        setState(337);
        match(TestSystemDeclParser::REAL);
        setState(338);
        match(TestSystemDeclParser::RPAREN);
        break;
      }

      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::ID: {
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

TestSystemDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(TestSystemDeclParser::EnumID, 0);
}

tree::TerminalNode* TestSystemDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

std::vector<TestSystemDeclParser::ContextIDContext *> TestSystemDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<TestSystemDeclParser::ContextIDContext>();
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TestSystemDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(TestSystemDeclParser::COMMA);
}

tree::TerminalNode* TestSystemDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(TestSystemDeclParser::COMMA, i);
}


size_t TestSystemDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleEnumTypeDecl;
}

void TestSystemDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void TestSystemDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

TestSystemDeclParser::EnumTypeDeclContext* TestSystemDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 54, TestSystemDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(TestSystemDeclParser::EnumID);
    setState(343);
    match(TestSystemDeclParser::LPAREN);
    setState(344);
    contextID();
    setState(349);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestSystemDeclParser::COMMA) {
      setState(345);
      match(TestSystemDeclParser::COMMA);
      setState(346);
      contextID();
      setState(351);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(352);
    match(TestSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

TestSystemDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(TestSystemDeclParser::AttributeID, 0);
}

TestSystemDeclParser::TypeDeclContext* TestSystemDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<TestSystemDeclParser::TypeDeclContext>(0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::AttributeDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* TestSystemDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(TestSystemDeclParser::ASSIGN, 0);
}

TestSystemDeclParser::LiteralValueContext* TestSystemDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<TestSystemDeclParser::LiteralValueContext>(0);
}


size_t TestSystemDeclParser::AttributeDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleAttributeDecl;
}

void TestSystemDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void TestSystemDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

TestSystemDeclParser::AttributeDeclContext* TestSystemDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 56, TestSystemDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(354);
    match(TestSystemDeclParser::AttributeID);
    setState(355);
    typeDecl();
    setState(356);
    contextID();
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TestSystemDeclParser::ASSIGN) {
      setState(357);
      match(TestSystemDeclParser::ASSIGN);
      setState(358);
      literalValue();
    }
    setState(361);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

TestSystemDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::LiteralValueContext::INT() {
  return getToken(TestSystemDeclParser::INT, 0);
}

tree::TerminalNode* TestSystemDeclParser::LiteralValueContext::REAL() {
  return getToken(TestSystemDeclParser::REAL, 0);
}

tree::TerminalNode* TestSystemDeclParser::LiteralValueContext::STRING() {
  return getToken(TestSystemDeclParser::STRING, 0);
}

tree::TerminalNode* TestSystemDeclParser::LiteralValueContext::TrueID() {
  return getToken(TestSystemDeclParser::TrueID, 0);
}

tree::TerminalNode* TestSystemDeclParser::LiteralValueContext::FalseID() {
  return getToken(TestSystemDeclParser::FalseID, 0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}


size_t TestSystemDeclParser::LiteralValueContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleLiteralValue;
}

void TestSystemDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void TestSystemDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

TestSystemDeclParser::LiteralValueContext* TestSystemDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 58, TestSystemDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(369);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(363);
        match(TestSystemDeclParser::INT);
        break;
      }

      case TestSystemDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(364);
        match(TestSystemDeclParser::REAL);
        break;
      }

      case TestSystemDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(365);
        match(TestSystemDeclParser::STRING);
        break;
      }

      case TestSystemDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(366);
        match(TestSystemDeclParser::TrueID);
        break;
      }

      case TestSystemDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(367);
        match(TestSystemDeclParser::FalseID);
        break;
      }

      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(368);
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

TestSystemDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::TriggerDeclContext* TestSystemDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<TestSystemDeclParser::TriggerDeclContext>(0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}


size_t TestSystemDeclParser::SignalParamNameContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSignalParamName;
}

void TestSystemDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void TestSystemDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

TestSystemDeclParser::SignalParamNameContext* TestSystemDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 60, TestSystemDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    triggerDecl();
    setState(372);
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

TestSystemDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}

TestSystemDeclParser::ThisDeclContext* TestSystemDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<TestSystemDeclParser::ThisDeclContext>(0);
}


size_t TestSystemDeclParser::AttributeNameContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleAttributeName;
}

void TestSystemDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void TestSystemDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

TestSystemDeclParser::AttributeNameContext* TestSystemDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 62, TestSystemDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::ThisID: {
        setState(374);
        thisDecl();
        break;
      }

      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(378);
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

TestSystemDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ToPortNameContext::ToID() {
  return getToken(TestSystemDeclParser::ToID, 0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}


size_t TestSystemDeclParser::ToPortNameContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleToPortName;
}

void TestSystemDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void TestSystemDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

TestSystemDeclParser::ToPortNameContext* TestSystemDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 64, TestSystemDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(TestSystemDeclParser::ToID);
    setState(381);
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

TestSystemDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::AttributeNameContext* TestSystemDeclParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<TestSystemDeclParser::AttributeNameContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(TestSystemDeclParser::ASSIGN, 0);
}

TestSystemDeclParser::ExpressionContext* TestSystemDeclParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<TestSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}


size_t TestSystemDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleAttributeAssignStatement;
}

void TestSystemDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void TestSystemDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

TestSystemDeclParser::AttributeAssignStatementContext* TestSystemDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 66, TestSystemDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    attributeName();
    setState(384);
    match(TestSystemDeclParser::ASSIGN);
    setState(385);
    expression();
    setState(386);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

TestSystemDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::TypeDeclContext* TestSystemDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<TestSystemDeclParser::TypeDeclContext>(0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* TestSystemDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(TestSystemDeclParser::ASSIGN, 0);
}

TestSystemDeclParser::ExpressionContext* TestSystemDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<TestSystemDeclParser::ExpressionContext>(0);
}


size_t TestSystemDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleLocalAssignStatement;
}

void TestSystemDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void TestSystemDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

TestSystemDeclParser::LocalAssignStatementContext* TestSystemDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, TestSystemDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    typeDecl();
    setState(389);
    contextID();
    setState(393);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::ASSIGN: {
        setState(390);
        match(TestSystemDeclParser::ASSIGN);
        setState(391);
        expression();
        break;
      }

      case TestSystemDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(395);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

TestSystemDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::SendToStatementContext::SendID() {
  return getToken(TestSystemDeclParser::SendID, 0);
}

TestSystemDeclParser::SignalSendContext* TestSystemDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<TestSystemDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::SendToStatementContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

TestSystemDeclParser::ToPortNameContext* TestSystemDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<TestSystemDeclParser::ToPortNameContext>(0);
}


size_t TestSystemDeclParser::SendToStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSendToStatement;
}

void TestSystemDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void TestSystemDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

TestSystemDeclParser::SendToStatementContext* TestSystemDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 70, TestSystemDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(TestSystemDeclParser::SendID);
    setState(398);
    signalSend();
    setState(401);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::ToID: {
        setState(399);
        toPortName();
        break;
      }

      case TestSystemDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(403);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

TestSystemDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::AttributeAssignStatementContext* TestSystemDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<TestSystemDeclParser::AttributeAssignStatementContext>(0);
}

TestSystemDeclParser::SendToStatementContext* TestSystemDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<TestSystemDeclParser::SendToStatementContext>(0);
}


size_t TestSystemDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSingleAssignment;
}

void TestSystemDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void TestSystemDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

TestSystemDeclParser::SingleAssignmentContext* TestSystemDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 72, TestSystemDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(407);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(405);
      attributeAssignStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(406);
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

TestSystemDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(TestSystemDeclParser::LBRACE, 0);
}

tree::TerminalNode* TestSystemDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(TestSystemDeclParser::RBRACE, 0);
}

std::vector<TestSystemDeclParser::SingleAssignmentContext *> TestSystemDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<TestSystemDeclParser::SingleAssignmentContext>();
}

TestSystemDeclParser::SingleAssignmentContext* TestSystemDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<TestSystemDeclParser::SingleAssignmentContext>(i);
}


size_t TestSystemDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleMultiAssignment;
}

void TestSystemDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void TestSystemDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

TestSystemDeclParser::MultiAssignmentContext* TestSystemDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 74, TestSystemDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(TestSystemDeclParser::LBRACE);
    setState(413);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestSystemDeclParser::TestComponentID)
      | (1ULL << TestSystemDeclParser::TestSystemID)
      | (1ULL << TestSystemDeclParser::LinkID)
      | (1ULL << TestSystemDeclParser::TargetID)
      | (1ULL << TestSystemDeclParser::SourceID)
      | (1ULL << TestSystemDeclParser::NameID)
      | (1ULL << TestSystemDeclParser::LabelID)
      | (1ULL << TestSystemDeclParser::EnabledID)
      | (1ULL << TestSystemDeclParser::TypeID)
      | (1ULL << TestSystemDeclParser::TriggerID)
      | (1ULL << TestSystemDeclParser::MessageTrigger)
      | (1ULL << TestSystemDeclParser::ThisID)
      | (1ULL << TestSystemDeclParser::AttributeID)
      | (1ULL << TestSystemDeclParser::SignalID)
      | (1ULL << TestSystemDeclParser::PortID)
      | (1ULL << TestSystemDeclParser::ImportID)
      | (1ULL << TestSystemDeclParser::FromID)
      | (1ULL << TestSystemDeclParser::ToID)
      | (1ULL << TestSystemDeclParser::SendID)
      | (1ULL << TestSystemDeclParser::AsID)
      | (1ULL << TestSystemDeclParser::ID))) != 0)) {
      setState(410);
      singleAssignment();
      setState(415);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(416);
    match(TestSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

TestSystemDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::SignalDeclContext::SignalID() {
  return getToken(TestSystemDeclParser::SignalID, 0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::SignalDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

tree::TerminalNode* TestSystemDeclParser::SignalDeclContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

tree::TerminalNode* TestSystemDeclParser::SignalDeclContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}

std::vector<TestSystemDeclParser::ParamDeclContext *> TestSystemDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<TestSystemDeclParser::ParamDeclContext>();
}

TestSystemDeclParser::ParamDeclContext* TestSystemDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<TestSystemDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::SignalDeclContext::COMMA() {
  return getTokens(TestSystemDeclParser::COMMA);
}

tree::TerminalNode* TestSystemDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(TestSystemDeclParser::COMMA, i);
}


size_t TestSystemDeclParser::SignalDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSignalDecl;
}

void TestSystemDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void TestSystemDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

TestSystemDeclParser::SignalDeclContext* TestSystemDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 76, TestSystemDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(TestSystemDeclParser::SignalID);
    setState(419);
    contextID();
    setState(434);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::LPAREN: {
        setState(420);
        match(TestSystemDeclParser::LPAREN);
        setState(430);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestSystemDeclParser::TestComponentID:
          case TestSystemDeclParser::TestSystemID:
          case TestSystemDeclParser::LinkID:
          case TestSystemDeclParser::TargetID:
          case TestSystemDeclParser::SourceID:
          case TestSystemDeclParser::NameID:
          case TestSystemDeclParser::LabelID:
          case TestSystemDeclParser::EnabledID:
          case TestSystemDeclParser::TypeID:
          case TestSystemDeclParser::IntID:
          case TestSystemDeclParser::RealID:
          case TestSystemDeclParser::BoolID:
          case TestSystemDeclParser::StringID:
          case TestSystemDeclParser::TriggerID:
          case TestSystemDeclParser::MessageTrigger:
          case TestSystemDeclParser::EnumID:
          case TestSystemDeclParser::AttributeID:
          case TestSystemDeclParser::SignalID:
          case TestSystemDeclParser::PortID:
          case TestSystemDeclParser::ImportID:
          case TestSystemDeclParser::FromID:
          case TestSystemDeclParser::ToID:
          case TestSystemDeclParser::SendID:
          case TestSystemDeclParser::AsID:
          case TestSystemDeclParser::ID: {
            setState(421);
            paramDecl();
            setState(426);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TestSystemDeclParser::COMMA) {
              setState(422);
              match(TestSystemDeclParser::COMMA);
              setState(423);
              paramDecl();
              setState(428);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case TestSystemDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(432);
        match(TestSystemDeclParser::RPAREN);
        break;
      }

      case TestSystemDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(436);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

TestSystemDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::TypeDeclContext* TestSystemDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<TestSystemDeclParser::TypeDeclContext>(0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}


size_t TestSystemDeclParser::ParamDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleParamDecl;
}

void TestSystemDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void TestSystemDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

TestSystemDeclParser::ParamDeclContext* TestSystemDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 78, TestSystemDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    typeDecl();
    setState(439);
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

TestSystemDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(TestSystemDeclParser::FunctionID, 0);
}

TestSystemDeclParser::TypeDeclContext* TestSystemDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<TestSystemDeclParser::TypeDeclContext>(0);
}

TestSystemDeclParser::IdPathContext* TestSystemDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<TestSystemDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

tree::TerminalNode* TestSystemDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}

TestSystemDeclParser::NestedStatementBodyContext* TestSystemDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<TestSystemDeclParser::NestedStatementBodyContext>(0);
}

TestSystemDeclParser::FunctionParametersContext* TestSystemDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<TestSystemDeclParser::FunctionParametersContext>(0);
}


size_t TestSystemDeclParser::FunctionDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleFunctionDecl;
}

void TestSystemDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void TestSystemDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

TestSystemDeclParser::FunctionDeclContext* TestSystemDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 80, TestSystemDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(441);
    match(TestSystemDeclParser::FunctionID);
    setState(442);
    typeDecl();
    setState(443);
    idPath();
    setState(444);
    match(TestSystemDeclParser::LPAREN);
    setState(447);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::IntID:
      case TestSystemDeclParser::RealID:
      case TestSystemDeclParser::BoolID:
      case TestSystemDeclParser::StringID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::EnumID:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::ID: {
        setState(445);
        functionParameters();
        break;
      }

      case TestSystemDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(449);
    match(TestSystemDeclParser::RPAREN);
    setState(450);
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

TestSystemDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestSystemDeclParser::ParamDeclContext *> TestSystemDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<TestSystemDeclParser::ParamDeclContext>();
}

TestSystemDeclParser::ParamDeclContext* TestSystemDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<TestSystemDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(TestSystemDeclParser::COMMA);
}

tree::TerminalNode* TestSystemDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(TestSystemDeclParser::COMMA, i);
}


size_t TestSystemDeclParser::FunctionParametersContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleFunctionParameters;
}

void TestSystemDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void TestSystemDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

TestSystemDeclParser::FunctionParametersContext* TestSystemDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 82, TestSystemDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    paramDecl();
    setState(457);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestSystemDeclParser::COMMA) {
      setState(453);
      match(TestSystemDeclParser::COMMA);
      setState(454);
      paramDecl();
      setState(459);
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

TestSystemDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::IdPathContext* TestSystemDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<TestSystemDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::FunctionCallContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

TestSystemDeclParser::FunctionCallBodyContext* TestSystemDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<TestSystemDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::FunctionCallContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}


size_t TestSystemDeclParser::FunctionCallContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleFunctionCall;
}

void TestSystemDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void TestSystemDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

TestSystemDeclParser::FunctionCallContext* TestSystemDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 84, TestSystemDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    idPath();
    setState(461);
    match(TestSystemDeclParser::LPAREN);
    setState(462);
    functionCallBody();
    setState(463);
    match(TestSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

TestSystemDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::FunctionCallBodyOptionalContext* TestSystemDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<TestSystemDeclParser::FunctionCallBodyOptionalContext>(0);
}

TestSystemDeclParser::LiteralValueContext* TestSystemDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<TestSystemDeclParser::LiteralValueContext>(0);
}

TestSystemDeclParser::SignalParamNameContext* TestSystemDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<TestSystemDeclParser::SignalParamNameContext>(0);
}

TestSystemDeclParser::AttributeNameContext* TestSystemDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<TestSystemDeclParser::AttributeNameContext>(0);
}

TestSystemDeclParser::FunctionCallContext* TestSystemDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<TestSystemDeclParser::FunctionCallContext>(0);
}


size_t TestSystemDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleFunctionCallBody;
}

void TestSystemDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void TestSystemDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

TestSystemDeclParser::FunctionCallBodyContext* TestSystemDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 86, TestSystemDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(470);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(465);
      literalValue();
      break;
    }

    case 2: {
      setState(466);
      signalParamName();
      break;
    }

    case 3: {
      setState(467);
      attributeName();
      break;
    }

    case 4: {
      setState(468);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(472);
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

TestSystemDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(TestSystemDeclParser::COMMA, 0);
}

TestSystemDeclParser::FunctionCallBodyContext* TestSystemDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<TestSystemDeclParser::FunctionCallBodyContext>(0);
}


size_t TestSystemDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleFunctionCallBodyOptional;
}

void TestSystemDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void TestSystemDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

TestSystemDeclParser::FunctionCallBodyOptionalContext* TestSystemDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 88, TestSystemDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(477);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(474);
        match(TestSystemDeclParser::COMMA);
        setState(475);
        functionCallBody();
        break;
      }

      case TestSystemDeclParser::RPAREN: {
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

TestSystemDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::TriggerDeclContext::DOT() {
  return getToken(TestSystemDeclParser::DOT, 0);
}

tree::TerminalNode* TestSystemDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(TestSystemDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* TestSystemDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(TestSystemDeclParser::TriggerID, 0);
}


size_t TestSystemDeclParser::TriggerDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleTriggerDecl;
}

void TestSystemDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void TestSystemDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

TestSystemDeclParser::TriggerDeclContext* TestSystemDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 90, TestSystemDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    _la = _input->LA(1);
    if (!(_la == TestSystemDeclParser::TriggerID

    || _la == TestSystemDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(480);
    match(TestSystemDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

TestSystemDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ThisDeclContext::ThisID() {
  return getToken(TestSystemDeclParser::ThisID, 0);
}

tree::TerminalNode* TestSystemDeclParser::ThisDeclContext::DOT() {
  return getToken(TestSystemDeclParser::DOT, 0);
}


size_t TestSystemDeclParser::ThisDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleThisDecl;
}

void TestSystemDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void TestSystemDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

TestSystemDeclParser::ThisDeclContext* TestSystemDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 92, TestSystemDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    match(TestSystemDeclParser::ThisID);
    setState(483);
    match(TestSystemDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

TestSystemDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::PortDeclContext::PortID() {
  return getToken(TestSystemDeclParser::PortID, 0);
}

std::vector<TestSystemDeclParser::ContextIDContext *> TestSystemDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<TestSystemDeclParser::ContextIDContext>();
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TestSystemDeclParser::PortDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::PortDeclContext::COMMA() {
  return getTokens(TestSystemDeclParser::COMMA);
}

tree::TerminalNode* TestSystemDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(TestSystemDeclParser::COMMA, i);
}


size_t TestSystemDeclParser::PortDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RulePortDecl;
}

void TestSystemDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void TestSystemDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

TestSystemDeclParser::PortDeclContext* TestSystemDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 94, TestSystemDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    match(TestSystemDeclParser::PortID);
    setState(486);
    contextID();
    setState(491);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestSystemDeclParser::COMMA) {
      setState(487);
      match(TestSystemDeclParser::COMMA);
      setState(488);
      contextID();
      setState(493);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(494);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

TestSystemDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::NameDeclContext::NameID() {
  return getToken(TestSystemDeclParser::NameID, 0);
}

tree::TerminalNode* TestSystemDeclParser::NameDeclContext::COLON() {
  return getToken(TestSystemDeclParser::COLON, 0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::NameDeclContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::NameDeclContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}


size_t TestSystemDeclParser::NameDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleNameDecl;
}

void TestSystemDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void TestSystemDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

TestSystemDeclParser::NameDeclContext* TestSystemDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 96, TestSystemDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    match(TestSystemDeclParser::NameID);
    setState(497);
    match(TestSystemDeclParser::COLON);
    setState(498);
    contextID();
    setState(499);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

TestSystemDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestSystemDeclParser::ContextIDContext *> TestSystemDeclParser::IdPathContext::contextID() {
  return getRuleContexts<TestSystemDeclParser::ContextIDContext>();
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::IdPathContext::DOT() {
  return getTokens(TestSystemDeclParser::DOT);
}

tree::TerminalNode* TestSystemDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(TestSystemDeclParser::DOT, i);
}


size_t TestSystemDeclParser::IdPathContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleIdPath;
}

void TestSystemDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void TestSystemDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

TestSystemDeclParser::IdPathContext* TestSystemDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 98, TestSystemDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    contextID();
    setState(506);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestSystemDeclParser::DOT) {
      setState(502);
      match(TestSystemDeclParser::DOT);
      setState(503);
      contextID();
      setState(508);
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

TestSystemDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::StatementBodyContext* TestSystemDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<TestSystemDeclParser::StatementBodyContext>(0);
}

TestSystemDeclParser::NestedStatementBodyContext* TestSystemDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<TestSystemDeclParser::NestedStatementBodyContext>(0);
}


size_t TestSystemDeclParser::StatementDeclContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleStatementDecl;
}

void TestSystemDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void TestSystemDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

TestSystemDeclParser::StatementDeclContext* TestSystemDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 100, TestSystemDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(511);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::IntID:
      case TestSystemDeclParser::RealID:
      case TestSystemDeclParser::BoolID:
      case TestSystemDeclParser::StringID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::ThisID:
      case TestSystemDeclParser::ReturnID:
      case TestSystemDeclParser::EnumID:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::SwitchID:
      case TestSystemDeclParser::IfID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::BREAK:
      case TestSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(509);
        statementBody();
        break;
      }

      case TestSystemDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(510);
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

TestSystemDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::FunctionCallStatementContext* TestSystemDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<TestSystemDeclParser::FunctionCallStatementContext>(0);
}

TestSystemDeclParser::AttributeAssignStatementContext* TestSystemDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<TestSystemDeclParser::AttributeAssignStatementContext>(0);
}

TestSystemDeclParser::SwitchStatementContext* TestSystemDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<TestSystemDeclParser::SwitchStatementContext>(0);
}

TestSystemDeclParser::ConditionalStatementContext* TestSystemDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<TestSystemDeclParser::ConditionalStatementContext>(0);
}

TestSystemDeclParser::LocalAssignStatementContext* TestSystemDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<TestSystemDeclParser::LocalAssignStatementContext>(0);
}

TestSystemDeclParser::SendToStatementContext* TestSystemDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<TestSystemDeclParser::SendToStatementContext>(0);
}

TestSystemDeclParser::BreakStatementContext* TestSystemDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<TestSystemDeclParser::BreakStatementContext>(0);
}

TestSystemDeclParser::ReturnStatementContext* TestSystemDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<TestSystemDeclParser::ReturnStatementContext>(0);
}


size_t TestSystemDeclParser::StatementBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleStatementBody;
}

void TestSystemDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void TestSystemDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

TestSystemDeclParser::StatementBodyContext* TestSystemDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 102, TestSystemDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(521);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(513);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(514);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(515);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(516);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(517);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(518);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(519);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(520);
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

TestSystemDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::FunctionCallContext* TestSystemDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<TestSystemDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}


size_t TestSystemDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleFunctionCallStatement;
}

void TestSystemDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void TestSystemDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

TestSystemDeclParser::FunctionCallStatementContext* TestSystemDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 104, TestSystemDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(523);
    functionCall();
    setState(524);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

TestSystemDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(TestSystemDeclParser::LBRACE, 0);
}

tree::TerminalNode* TestSystemDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(TestSystemDeclParser::RBRACE, 0);
}

std::vector<TestSystemDeclParser::StatementBodyContext *> TestSystemDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<TestSystemDeclParser::StatementBodyContext>();
}

TestSystemDeclParser::StatementBodyContext* TestSystemDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<TestSystemDeclParser::StatementBodyContext>(i);
}


size_t TestSystemDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleNestedStatementBody;
}

void TestSystemDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void TestSystemDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

TestSystemDeclParser::NestedStatementBodyContext* TestSystemDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 106, TestSystemDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    match(TestSystemDeclParser::LBRACE);
    setState(530);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestSystemDeclParser::TestComponentID)
      | (1ULL << TestSystemDeclParser::TestSystemID)
      | (1ULL << TestSystemDeclParser::LinkID)
      | (1ULL << TestSystemDeclParser::TargetID)
      | (1ULL << TestSystemDeclParser::SourceID)
      | (1ULL << TestSystemDeclParser::NameID)
      | (1ULL << TestSystemDeclParser::LabelID)
      | (1ULL << TestSystemDeclParser::EnabledID)
      | (1ULL << TestSystemDeclParser::TypeID)
      | (1ULL << TestSystemDeclParser::IntID)
      | (1ULL << TestSystemDeclParser::RealID)
      | (1ULL << TestSystemDeclParser::BoolID)
      | (1ULL << TestSystemDeclParser::StringID)
      | (1ULL << TestSystemDeclParser::TriggerID)
      | (1ULL << TestSystemDeclParser::MessageTrigger)
      | (1ULL << TestSystemDeclParser::ThisID)
      | (1ULL << TestSystemDeclParser::ReturnID)
      | (1ULL << TestSystemDeclParser::EnumID)
      | (1ULL << TestSystemDeclParser::AttributeID)
      | (1ULL << TestSystemDeclParser::SignalID)
      | (1ULL << TestSystemDeclParser::PortID)
      | (1ULL << TestSystemDeclParser::ImportID)
      | (1ULL << TestSystemDeclParser::FromID)
      | (1ULL << TestSystemDeclParser::ToID)
      | (1ULL << TestSystemDeclParser::SendID)
      | (1ULL << TestSystemDeclParser::SwitchID)
      | (1ULL << TestSystemDeclParser::IfID)
      | (1ULL << TestSystemDeclParser::AsID)
      | (1ULL << TestSystemDeclParser::BREAK)
      | (1ULL << TestSystemDeclParser::ID))) != 0)) {
      setState(527);
      statementBody();
      setState(532);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(533);
    match(TestSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

TestSystemDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(TestSystemDeclParser::ReturnID, 0);
}

TestSystemDeclParser::OperationContext* TestSystemDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<TestSystemDeclParser::OperationContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::ReturnStatementContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}


size_t TestSystemDeclParser::ReturnStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleReturnStatement;
}

void TestSystemDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void TestSystemDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

TestSystemDeclParser::ReturnStatementContext* TestSystemDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 108, TestSystemDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(535);
    match(TestSystemDeclParser::ReturnID);
    setState(536);
    operation();
    setState(537);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

TestSystemDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::BreakStatementContext::BREAK() {
  return getToken(TestSystemDeclParser::BREAK, 0);
}

tree::TerminalNode* TestSystemDeclParser::BreakStatementContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}


size_t TestSystemDeclParser::BreakStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleBreakStatement;
}

void TestSystemDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void TestSystemDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

TestSystemDeclParser::BreakStatementContext* TestSystemDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, TestSystemDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(539);
    match(TestSystemDeclParser::BREAK);
    setState(540);
    match(TestSystemDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

TestSystemDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::AtomContext* TestSystemDeclParser::OperationContext::atom() {
  return getRuleContext<TestSystemDeclParser::AtomContext>(0);
}

TestSystemDeclParser::OperationOptionalContext* TestSystemDeclParser::OperationContext::operationOptional() {
  return getRuleContext<TestSystemDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::OperationContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

TestSystemDeclParser::OperationContext* TestSystemDeclParser::OperationContext::operation() {
  return getRuleContext<TestSystemDeclParser::OperationContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::OperationContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}

tree::TerminalNode* TestSystemDeclParser::OperationContext::MINUS() {
  return getToken(TestSystemDeclParser::MINUS, 0);
}

tree::TerminalNode* TestSystemDeclParser::OperationContext::NotIdSymbol() {
  return getToken(TestSystemDeclParser::NotIdSymbol, 0);
}


size_t TestSystemDeclParser::OperationContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleOperation;
}

void TestSystemDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void TestSystemDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

TestSystemDeclParser::OperationContext* TestSystemDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 112, TestSystemDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(553);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::ThisID:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::TrueID:
      case TestSystemDeclParser::FalseID:
      case TestSystemDeclParser::INT:
      case TestSystemDeclParser::REAL:
      case TestSystemDeclParser::STRING:
      case TestSystemDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(542);
        atom();
        setState(543);
        operationOptional();
        break;
      }

      case TestSystemDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(545);
        match(TestSystemDeclParser::LPAREN);
        setState(546);
        operation();
        setState(547);
        match(TestSystemDeclParser::RPAREN);
        break;
      }

      case TestSystemDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(549);
        match(TestSystemDeclParser::MINUS);
        setState(550);
        operation();
        break;
      }

      case TestSystemDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(551);
        match(TestSystemDeclParser::NotIdSymbol);
        setState(552);
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

TestSystemDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::OperationContext* TestSystemDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<TestSystemDeclParser::OperationContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::OperationOptionalContext::MULT() {
  return getToken(TestSystemDeclParser::MULT, 0);
}

tree::TerminalNode* TestSystemDeclParser::OperationOptionalContext::DIV() {
  return getToken(TestSystemDeclParser::DIV, 0);
}

tree::TerminalNode* TestSystemDeclParser::OperationOptionalContext::PLUS() {
  return getToken(TestSystemDeclParser::PLUS, 0);
}

tree::TerminalNode* TestSystemDeclParser::OperationOptionalContext::MINUS() {
  return getToken(TestSystemDeclParser::MINUS, 0);
}


size_t TestSystemDeclParser::OperationOptionalContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleOperationOptional;
}

void TestSystemDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void TestSystemDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

TestSystemDeclParser::OperationOptionalContext* TestSystemDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 114, TestSystemDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(558);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::PLUS:
      case TestSystemDeclParser::MINUS:
      case TestSystemDeclParser::MULT:
      case TestSystemDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(555);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (TestSystemDeclParser::PLUS - 72))
          | (1ULL << (TestSystemDeclParser::MINUS - 72))
          | (1ULL << (TestSystemDeclParser::MULT - 72))
          | (1ULL << (TestSystemDeclParser::DIV - 72)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(556);
        operation();
        break;
      }

      case TestSystemDeclParser::NotIdSymbol:
      case TestSystemDeclParser::AndIdSymbol:
      case TestSystemDeclParser::OrIdSymbol:
      case TestSystemDeclParser::NotIdWord:
      case TestSystemDeclParser::AndIdWord:
      case TestSystemDeclParser::OrIdWord:
      case TestSystemDeclParser::ASSIGN:
      case TestSystemDeclParser::RPAREN:
      case TestSystemDeclParser::LESSTHAN:
      case TestSystemDeclParser::GREATERTHAN:
      case TestSystemDeclParser::SEMI: {
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

TestSystemDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ExpressionContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

TestSystemDeclParser::ExpressionContext* TestSystemDeclParser::ExpressionContext::expression() {
  return getRuleContext<TestSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}

TestSystemDeclParser::ExpressionOptionalContext* TestSystemDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<TestSystemDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(TestSystemDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionContext::NotIdWord() {
  return getToken(TestSystemDeclParser::NotIdWord, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionContext::MINUS() {
  return getToken(TestSystemDeclParser::MINUS, 0);
}

TestSystemDeclParser::OperationContext* TestSystemDeclParser::ExpressionContext::operation() {
  return getRuleContext<TestSystemDeclParser::OperationContext>(0);
}


size_t TestSystemDeclParser::ExpressionContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleExpression;
}

void TestSystemDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void TestSystemDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

TestSystemDeclParser::ExpressionContext* TestSystemDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 116, TestSystemDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(574);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(560);
      match(TestSystemDeclParser::LPAREN);
      setState(561);
      expression();
      setState(562);
      match(TestSystemDeclParser::RPAREN);
      setState(563);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(565);
      match(TestSystemDeclParser::NotIdSymbol);
      setState(566);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(567);
      match(TestSystemDeclParser::NotIdWord);
      setState(568);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(569);
      match(TestSystemDeclParser::MINUS);
      setState(570);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(571);
      operation();
      setState(572);
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

TestSystemDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::ExpressionContext* TestSystemDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<TestSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(TestSystemDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(TestSystemDeclParser::OrIdWord, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(TestSystemDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(TestSystemDeclParser::AndIdWord, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(TestSystemDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> TestSystemDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(TestSystemDeclParser::ASSIGN);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(TestSystemDeclParser::ASSIGN, i);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(TestSystemDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(TestSystemDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* TestSystemDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(TestSystemDeclParser::GREATERTHAN, 0);
}


size_t TestSystemDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleExpressionOptional;
}

void TestSystemDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void TestSystemDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

TestSystemDeclParser::ExpressionOptionalContext* TestSystemDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 118, TestSystemDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(599);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::NotIdSymbol:
      case TestSystemDeclParser::AndIdSymbol:
      case TestSystemDeclParser::OrIdSymbol:
      case TestSystemDeclParser::NotIdWord:
      case TestSystemDeclParser::AndIdWord:
      case TestSystemDeclParser::OrIdWord:
      case TestSystemDeclParser::ASSIGN:
      case TestSystemDeclParser::LESSTHAN:
      case TestSystemDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(595);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestSystemDeclParser::OrIdSymbol: {
            setState(576);
            match(TestSystemDeclParser::OrIdSymbol);
            break;
          }

          case TestSystemDeclParser::OrIdWord: {
            setState(577);
            match(TestSystemDeclParser::OrIdWord);
            break;
          }

          case TestSystemDeclParser::AndIdSymbol: {
            setState(578);
            match(TestSystemDeclParser::AndIdSymbol);
            break;
          }

          case TestSystemDeclParser::AndIdWord: {
            setState(579);
            match(TestSystemDeclParser::AndIdWord);
            break;
          }

          case TestSystemDeclParser::ASSIGN: {
            setState(580);
            match(TestSystemDeclParser::ASSIGN);
            setState(581);
            match(TestSystemDeclParser::ASSIGN);
            break;
          }

          case TestSystemDeclParser::NotIdSymbol: {
            setState(582);
            match(TestSystemDeclParser::NotIdSymbol);
            setState(583);
            match(TestSystemDeclParser::ASSIGN);
            break;
          }

          case TestSystemDeclParser::NotIdWord: {
            setState(584);
            match(TestSystemDeclParser::NotIdWord);
            break;
          }

          case TestSystemDeclParser::LESSTHAN: {
            setState(585);
            match(TestSystemDeclParser::LESSTHAN);
            setState(588);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TestSystemDeclParser::ASSIGN: {
                setState(586);
                match(TestSystemDeclParser::ASSIGN);
                break;
              }

              case TestSystemDeclParser::TestComponentID:
              case TestSystemDeclParser::TestSystemID:
              case TestSystemDeclParser::LinkID:
              case TestSystemDeclParser::TargetID:
              case TestSystemDeclParser::SourceID:
              case TestSystemDeclParser::NameID:
              case TestSystemDeclParser::LabelID:
              case TestSystemDeclParser::EnabledID:
              case TestSystemDeclParser::TypeID:
              case TestSystemDeclParser::TriggerID:
              case TestSystemDeclParser::MessageTrigger:
              case TestSystemDeclParser::ThisID:
              case TestSystemDeclParser::AttributeID:
              case TestSystemDeclParser::SignalID:
              case TestSystemDeclParser::PortID:
              case TestSystemDeclParser::ImportID:
              case TestSystemDeclParser::FromID:
              case TestSystemDeclParser::ToID:
              case TestSystemDeclParser::SendID:
              case TestSystemDeclParser::AsID:
              case TestSystemDeclParser::NotIdSymbol:
              case TestSystemDeclParser::NotIdWord:
              case TestSystemDeclParser::TrueID:
              case TestSystemDeclParser::FalseID:
              case TestSystemDeclParser::INT:
              case TestSystemDeclParser::REAL:
              case TestSystemDeclParser::STRING:
              case TestSystemDeclParser::ID:
              case TestSystemDeclParser::LPAREN:
              case TestSystemDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case TestSystemDeclParser::GREATERTHAN: {
            setState(590);
            match(TestSystemDeclParser::GREATERTHAN);
            setState(593);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TestSystemDeclParser::ASSIGN: {
                setState(591);
                match(TestSystemDeclParser::ASSIGN);
                break;
              }

              case TestSystemDeclParser::TestComponentID:
              case TestSystemDeclParser::TestSystemID:
              case TestSystemDeclParser::LinkID:
              case TestSystemDeclParser::TargetID:
              case TestSystemDeclParser::SourceID:
              case TestSystemDeclParser::NameID:
              case TestSystemDeclParser::LabelID:
              case TestSystemDeclParser::EnabledID:
              case TestSystemDeclParser::TypeID:
              case TestSystemDeclParser::TriggerID:
              case TestSystemDeclParser::MessageTrigger:
              case TestSystemDeclParser::ThisID:
              case TestSystemDeclParser::AttributeID:
              case TestSystemDeclParser::SignalID:
              case TestSystemDeclParser::PortID:
              case TestSystemDeclParser::ImportID:
              case TestSystemDeclParser::FromID:
              case TestSystemDeclParser::ToID:
              case TestSystemDeclParser::SendID:
              case TestSystemDeclParser::AsID:
              case TestSystemDeclParser::NotIdSymbol:
              case TestSystemDeclParser::NotIdWord:
              case TestSystemDeclParser::TrueID:
              case TestSystemDeclParser::FalseID:
              case TestSystemDeclParser::INT:
              case TestSystemDeclParser::REAL:
              case TestSystemDeclParser::STRING:
              case TestSystemDeclParser::ID:
              case TestSystemDeclParser::LPAREN:
              case TestSystemDeclParser::MINUS: {
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
        setState(597);
        expression();
        break;
      }

      case TestSystemDeclParser::RPAREN:
      case TestSystemDeclParser::SEMI: {
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

TestSystemDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::IfStatementContext* TestSystemDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<TestSystemDeclParser::IfStatementContext>(0);
}

TestSystemDeclParser::ElseStatementContext* TestSystemDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<TestSystemDeclParser::ElseStatementContext>(0);
}


size_t TestSystemDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleConditionalStatement;
}

void TestSystemDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void TestSystemDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

TestSystemDeclParser::ConditionalStatementContext* TestSystemDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 120, TestSystemDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    ifStatement();
    setState(604);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(602);
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

TestSystemDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::IfStatementContext::IfID() {
  return getToken(TestSystemDeclParser::IfID, 0);
}

TestSystemDeclParser::IfEuTContext* TestSystemDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<TestSystemDeclParser::IfEuTContext>(0);
}

TestSystemDeclParser::StatementDeclContext* TestSystemDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<TestSystemDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::IfStatementContext::SEMI() {
  return getToken(TestSystemDeclParser::SEMI, 0);
}


size_t TestSystemDeclParser::IfStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleIfStatement;
}

void TestSystemDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void TestSystemDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

TestSystemDeclParser::IfStatementContext* TestSystemDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 122, TestSystemDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(606);
    match(TestSystemDeclParser::IfID);
    setState(607);
    ifEuT();
    setState(610);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::IntID:
      case TestSystemDeclParser::RealID:
      case TestSystemDeclParser::BoolID:
      case TestSystemDeclParser::StringID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::ThisID:
      case TestSystemDeclParser::ReturnID:
      case TestSystemDeclParser::EnumID:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::SwitchID:
      case TestSystemDeclParser::IfID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::BREAK:
      case TestSystemDeclParser::ID:
      case TestSystemDeclParser::LBRACE: {
        setState(608);
        statementDecl();
        break;
      }

      case TestSystemDeclParser::SEMI: {
        setState(609);
        match(TestSystemDeclParser::SEMI);
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

TestSystemDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::IfEuTContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

TestSystemDeclParser::ExpressionContext* TestSystemDeclParser::IfEuTContext::expression() {
  return getRuleContext<TestSystemDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::IfEuTContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}


size_t TestSystemDeclParser::IfEuTContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleIfEuT;
}

void TestSystemDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void TestSystemDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

TestSystemDeclParser::IfEuTContext* TestSystemDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 124, TestSystemDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    match(TestSystemDeclParser::LPAREN);
    setState(613);
    expression();
    setState(614);
    match(TestSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

TestSystemDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::ElseStatementContext::ElseID() {
  return getToken(TestSystemDeclParser::ElseID, 0);
}

TestSystemDeclParser::StatementDeclContext* TestSystemDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<TestSystemDeclParser::StatementDeclContext>(0);
}


size_t TestSystemDeclParser::ElseStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleElseStatement;
}

void TestSystemDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void TestSystemDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

TestSystemDeclParser::ElseStatementContext* TestSystemDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, TestSystemDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(616);
    match(TestSystemDeclParser::ElseID);
    setState(617);
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

TestSystemDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(TestSystemDeclParser::SwitchID, 0);
}

TestSystemDeclParser::SwitchPuTContext* TestSystemDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<TestSystemDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(TestSystemDeclParser::LBRACE, 0);
}

tree::TerminalNode* TestSystemDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(TestSystemDeclParser::RBRACE, 0);
}

TestSystemDeclParser::DefaultStatementContext* TestSystemDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<TestSystemDeclParser::DefaultStatementContext>(0);
}

std::vector<TestSystemDeclParser::CaseStatementContext *> TestSystemDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<TestSystemDeclParser::CaseStatementContext>();
}

TestSystemDeclParser::CaseStatementContext* TestSystemDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<TestSystemDeclParser::CaseStatementContext>(i);
}


size_t TestSystemDeclParser::SwitchStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSwitchStatement;
}

void TestSystemDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void TestSystemDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

TestSystemDeclParser::SwitchStatementContext* TestSystemDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 128, TestSystemDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    match(TestSystemDeclParser::SwitchID);
    setState(620);
    switchPuT();
    setState(621);
    match(TestSystemDeclParser::LBRACE);
    setState(625);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestSystemDeclParser::CaseID) {
      setState(622);
      caseStatement();
      setState(627);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(630);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::DefaultID: {
        setState(628);
        defaultStatement();
        break;
      }

      case TestSystemDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(632);
    match(TestSystemDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

TestSystemDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(TestSystemDeclParser::LPAREN, 0);
}

TestSystemDeclParser::ContextIDContext* TestSystemDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<TestSystemDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(TestSystemDeclParser::RPAREN, 0);
}


size_t TestSystemDeclParser::SwitchPuTContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleSwitchPuT;
}

void TestSystemDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void TestSystemDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

TestSystemDeclParser::SwitchPuTContext* TestSystemDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 130, TestSystemDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    match(TestSystemDeclParser::LPAREN);
    setState(635);
    contextID();
    setState(636);
    match(TestSystemDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

TestSystemDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::CaseStatementContext::CaseID() {
  return getToken(TestSystemDeclParser::CaseID, 0);
}

TestSystemDeclParser::LiteralValueContext* TestSystemDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<TestSystemDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* TestSystemDeclParser::CaseStatementContext::COLON() {
  return getToken(TestSystemDeclParser::COLON, 0);
}

TestSystemDeclParser::NestedStatementBodyContext* TestSystemDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<TestSystemDeclParser::NestedStatementBodyContext>(0);
}

std::vector<TestSystemDeclParser::StatementBodyContext *> TestSystemDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<TestSystemDeclParser::StatementBodyContext>();
}

TestSystemDeclParser::StatementBodyContext* TestSystemDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<TestSystemDeclParser::StatementBodyContext>(i);
}


size_t TestSystemDeclParser::CaseStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleCaseStatement;
}

void TestSystemDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void TestSystemDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

TestSystemDeclParser::CaseStatementContext* TestSystemDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 132, TestSystemDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(638);
    match(TestSystemDeclParser::CaseID);
    setState(639);
    literalValue();
    setState(640);
    match(TestSystemDeclParser::COLON);
    setState(648);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::LBRACE: {
        setState(641);
        nestedStatementBody();
        break;
      }

      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::IntID:
      case TestSystemDeclParser::RealID:
      case TestSystemDeclParser::BoolID:
      case TestSystemDeclParser::StringID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::ThisID:
      case TestSystemDeclParser::ReturnID:
      case TestSystemDeclParser::EnumID:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::SwitchID:
      case TestSystemDeclParser::CaseID:
      case TestSystemDeclParser::DefaultID:
      case TestSystemDeclParser::IfID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::BREAK:
      case TestSystemDeclParser::ID:
      case TestSystemDeclParser::RBRACE: {
        setState(645);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TestSystemDeclParser::TestComponentID)
          | (1ULL << TestSystemDeclParser::TestSystemID)
          | (1ULL << TestSystemDeclParser::LinkID)
          | (1ULL << TestSystemDeclParser::TargetID)
          | (1ULL << TestSystemDeclParser::SourceID)
          | (1ULL << TestSystemDeclParser::NameID)
          | (1ULL << TestSystemDeclParser::LabelID)
          | (1ULL << TestSystemDeclParser::EnabledID)
          | (1ULL << TestSystemDeclParser::TypeID)
          | (1ULL << TestSystemDeclParser::IntID)
          | (1ULL << TestSystemDeclParser::RealID)
          | (1ULL << TestSystemDeclParser::BoolID)
          | (1ULL << TestSystemDeclParser::StringID)
          | (1ULL << TestSystemDeclParser::TriggerID)
          | (1ULL << TestSystemDeclParser::MessageTrigger)
          | (1ULL << TestSystemDeclParser::ThisID)
          | (1ULL << TestSystemDeclParser::ReturnID)
          | (1ULL << TestSystemDeclParser::EnumID)
          | (1ULL << TestSystemDeclParser::AttributeID)
          | (1ULL << TestSystemDeclParser::SignalID)
          | (1ULL << TestSystemDeclParser::PortID)
          | (1ULL << TestSystemDeclParser::ImportID)
          | (1ULL << TestSystemDeclParser::FromID)
          | (1ULL << TestSystemDeclParser::ToID)
          | (1ULL << TestSystemDeclParser::SendID)
          | (1ULL << TestSystemDeclParser::SwitchID)
          | (1ULL << TestSystemDeclParser::IfID)
          | (1ULL << TestSystemDeclParser::AsID)
          | (1ULL << TestSystemDeclParser::BREAK)
          | (1ULL << TestSystemDeclParser::ID))) != 0)) {
          setState(642);
          statementBody();
          setState(647);
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

TestSystemDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestSystemDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(TestSystemDeclParser::DefaultID, 0);
}

tree::TerminalNode* TestSystemDeclParser::DefaultStatementContext::COLON() {
  return getToken(TestSystemDeclParser::COLON, 0);
}

TestSystemDeclParser::NestedStatementBodyContext* TestSystemDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<TestSystemDeclParser::NestedStatementBodyContext>(0);
}

std::vector<TestSystemDeclParser::StatementBodyContext *> TestSystemDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<TestSystemDeclParser::StatementBodyContext>();
}

TestSystemDeclParser::StatementBodyContext* TestSystemDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<TestSystemDeclParser::StatementBodyContext>(i);
}


size_t TestSystemDeclParser::DefaultStatementContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleDefaultStatement;
}

void TestSystemDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void TestSystemDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

TestSystemDeclParser::DefaultStatementContext* TestSystemDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 134, TestSystemDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(650);
    match(TestSystemDeclParser::DefaultID);
    setState(651);
    match(TestSystemDeclParser::COLON);
    setState(659);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestSystemDeclParser::LBRACE: {
        setState(652);
        nestedStatementBody();
        break;
      }

      case TestSystemDeclParser::TestComponentID:
      case TestSystemDeclParser::TestSystemID:
      case TestSystemDeclParser::LinkID:
      case TestSystemDeclParser::TargetID:
      case TestSystemDeclParser::SourceID:
      case TestSystemDeclParser::NameID:
      case TestSystemDeclParser::LabelID:
      case TestSystemDeclParser::EnabledID:
      case TestSystemDeclParser::TypeID:
      case TestSystemDeclParser::IntID:
      case TestSystemDeclParser::RealID:
      case TestSystemDeclParser::BoolID:
      case TestSystemDeclParser::StringID:
      case TestSystemDeclParser::TriggerID:
      case TestSystemDeclParser::MessageTrigger:
      case TestSystemDeclParser::ThisID:
      case TestSystemDeclParser::ReturnID:
      case TestSystemDeclParser::EnumID:
      case TestSystemDeclParser::AttributeID:
      case TestSystemDeclParser::SignalID:
      case TestSystemDeclParser::PortID:
      case TestSystemDeclParser::ImportID:
      case TestSystemDeclParser::FromID:
      case TestSystemDeclParser::ToID:
      case TestSystemDeclParser::SendID:
      case TestSystemDeclParser::SwitchID:
      case TestSystemDeclParser::IfID:
      case TestSystemDeclParser::AsID:
      case TestSystemDeclParser::BREAK:
      case TestSystemDeclParser::ID:
      case TestSystemDeclParser::RBRACE: {
        setState(656);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TestSystemDeclParser::TestComponentID)
          | (1ULL << TestSystemDeclParser::TestSystemID)
          | (1ULL << TestSystemDeclParser::LinkID)
          | (1ULL << TestSystemDeclParser::TargetID)
          | (1ULL << TestSystemDeclParser::SourceID)
          | (1ULL << TestSystemDeclParser::NameID)
          | (1ULL << TestSystemDeclParser::LabelID)
          | (1ULL << TestSystemDeclParser::EnabledID)
          | (1ULL << TestSystemDeclParser::TypeID)
          | (1ULL << TestSystemDeclParser::IntID)
          | (1ULL << TestSystemDeclParser::RealID)
          | (1ULL << TestSystemDeclParser::BoolID)
          | (1ULL << TestSystemDeclParser::StringID)
          | (1ULL << TestSystemDeclParser::TriggerID)
          | (1ULL << TestSystemDeclParser::MessageTrigger)
          | (1ULL << TestSystemDeclParser::ThisID)
          | (1ULL << TestSystemDeclParser::ReturnID)
          | (1ULL << TestSystemDeclParser::EnumID)
          | (1ULL << TestSystemDeclParser::AttributeID)
          | (1ULL << TestSystemDeclParser::SignalID)
          | (1ULL << TestSystemDeclParser::PortID)
          | (1ULL << TestSystemDeclParser::ImportID)
          | (1ULL << TestSystemDeclParser::FromID)
          | (1ULL << TestSystemDeclParser::ToID)
          | (1ULL << TestSystemDeclParser::SendID)
          | (1ULL << TestSystemDeclParser::SwitchID)
          | (1ULL << TestSystemDeclParser::IfID)
          | (1ULL << TestSystemDeclParser::AsID)
          | (1ULL << TestSystemDeclParser::BREAK)
          | (1ULL << TestSystemDeclParser::ID))) != 0)) {
          setState(653);
          statementBody();
          setState(658);
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

TestSystemDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestSystemDeclParser::SignalParamNameContext* TestSystemDeclParser::AtomContext::signalParamName() {
  return getRuleContext<TestSystemDeclParser::SignalParamNameContext>(0);
}

TestSystemDeclParser::AttributeNameContext* TestSystemDeclParser::AtomContext::attributeName() {
  return getRuleContext<TestSystemDeclParser::AttributeNameContext>(0);
}

TestSystemDeclParser::FunctionCallContext* TestSystemDeclParser::AtomContext::functionCall() {
  return getRuleContext<TestSystemDeclParser::FunctionCallContext>(0);
}

TestSystemDeclParser::LiteralValueContext* TestSystemDeclParser::AtomContext::literalValue() {
  return getRuleContext<TestSystemDeclParser::LiteralValueContext>(0);
}


size_t TestSystemDeclParser::AtomContext::getRuleIndex() const {
  return TestSystemDeclParser::RuleAtom;
}

void TestSystemDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void TestSystemDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestSystemDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

TestSystemDeclParser::AtomContext* TestSystemDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 136, TestSystemDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(665);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(661);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(662);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(663);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(664);
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
std::vector<dfa::DFA> TestSystemDeclParser::_decisionToDFA;
atn::PredictionContextCache TestSystemDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TestSystemDeclParser::_atn;
std::vector<uint16_t> TestSystemDeclParser::_serializedATN;

std::vector<std::string> TestSystemDeclParser::_ruleNames = {
  "testSystemDecl", "testSystemBody", "testSystemBodyOptional", "testCompDecl", 
  "testCompBody", "enabledDecl", "testCompBodyOtional", "linkDecls", "linkDecl", 
  "linkBody", "labelDecl", "targetDecl", "sourceDecl", "contextID", "componentIdPath", 
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

std::vector<std::string> TestSystemDeclParser::_literalNames = {
  "", "'TestComponent'", "'TestSystem'", "'Link'", "'target'", "'source'", 
  "", "'name'", "'label'", "'enabled'", "'Type'", "'int'", "'real'", "'bool'", 
  "'string'", "'trigger'", "'msg'", "'this'", "'return'", "'SignalTransition'", 
  "'TimeoutTransition'", "'enum'", "'Declaration'", "'description'", "'Attribute'", 
  "'Signal'", "'Port'", "'import'", "'from'", "'to'", "'send'", "'Function'", 
  "'switch'", "'case'", "'default'", "'if'", "'else'", "'as'", "'@'", "'!'", 
  "'&&'", "'||'", "'not'", "'and'", "'or'", "'true'", "'false'", "'break'", 
  "'='", "'<->'", "'->'", "'<-'", "'..'", "", "", "", "", "", "", "'('", 
  "')'", "'{'", "'}'", "'['", "']'", "'<'", "'>'", "':'", "';'", "','", 
  "'_'", "'.'", "'+'", "'-'", "'*'", "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> TestSystemDeclParser::_symbolicNames = {
  "", "TestComponentID", "TestSystemID", "LinkID", "TargetID", "SourceID", 
  "IGNORE_NEWLINE", "NameID", "LabelID", "EnabledID", "TypeID", "IntID", 
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

dfa::Vocabulary TestSystemDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TestSystemDeclParser::_tokenNames;

TestSystemDeclParser::Initializer::Initializer() {
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
    0x3, 0x52, 0x29e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x46, 0x9, 0x46, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x9e, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xb7, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0xbd, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xce, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xf2, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xf7, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xfa, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0xff, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x102, 
    0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x108, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x10b, 0xb, 0x12, 0x5, 0x12, 0x10d, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x117, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0x11a, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0x120, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0x133, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
    0x138, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 
    0x1a, 0x145, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x14e, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 
    0x1c, 0x157, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x7, 0x1d, 0x15e, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x161, 
    0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x16a, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 
    0x1f, 0x174, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x5, 0x21, 0x17b, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x18c, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x5, 0x25, 0x194, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x5, 0x26, 0x19a, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 
    0x19e, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x1a1, 0xb, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x7, 0x28, 0x1ab, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x1ae, 0xb, 
    0x28, 0x3, 0x28, 0x5, 0x28, 0x1b1, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x5, 0x28, 0x1b5, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x5, 0x2a, 0x1c2, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x1ca, 0xa, 0x2b, 0xc, 0x2b, 
    0xe, 0x2b, 0x1cd, 0xb, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
    0x2d, 0x1d9, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x1e0, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x7, 0x31, 0x1ec, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x1ef, 0xb, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 0x33, 0x1fb, 0xa, 0x33, 
    0xc, 0x33, 0xe, 0x33, 0x1fe, 0xb, 0x33, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 
    0x202, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x20c, 0xa, 0x35, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x213, 0xa, 0x37, 
    0xc, 0x37, 0xe, 0x37, 0x216, 0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
    0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x22c, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x231, 0xa, 0x3b, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x5, 0x3c, 0x241, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x24f, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x5, 0x3d, 0x254, 0xa, 0x3d, 0x5, 0x3d, 0x256, 0xa, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x25a, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x25f, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x5, 0x3f, 0x265, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x7, 0x42, 0x272, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 
    0x275, 0xb, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x279, 0xa, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 
    0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x286, 
    0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x289, 0xb, 0x44, 0x5, 0x44, 0x28b, 
    0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x291, 
    0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x294, 0xb, 0x45, 0x5, 0x45, 0x296, 
    0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x29c, 
    0xa, 0x46, 0x3, 0x46, 0x2, 0x2, 0x47, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 
    0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
    0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
    0x86, 0x88, 0x8a, 0x2, 0x5, 0x3, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x11, 0x12, 
    0x3, 0x2, 0x4a, 0x4d, 0x2, 0x2c4, 0x2, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x6, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa7, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x10, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x14, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x22, 0x10c, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x26, 0x118, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x121, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x132, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x137, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x139, 0x3, 0x2, 0x2, 0x2, 0x32, 0x144, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x36, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x38, 0x158, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x164, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x173, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x175, 0x3, 0x2, 0x2, 0x2, 0x40, 0x17a, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x44, 0x181, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x186, 0x3, 0x2, 0x2, 0x2, 0x48, 0x18f, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x199, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x1a4, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1bb, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1ce, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1df, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1e4, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1f2, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x66, 0x201, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x20b, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x210, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x219, 0x3, 0x2, 0x2, 0x2, 0x70, 0x21d, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x74, 0x230, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x240, 0x3, 0x2, 0x2, 0x2, 0x78, 0x259, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x260, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x266, 0x3, 0x2, 0x2, 0x2, 0x80, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x26d, 0x3, 0x2, 0x2, 0x2, 0x84, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x86, 0x280, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x29b, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x28, 0x15, 0x2, 0x8d, 0x8e, 0x7, 0x4, 
    0x2, 0x2, 0x8e, 0x8f, 0x7, 0x3f, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x4, 0x3, 
    0x2, 0x90, 0x91, 0x7, 0x40, 0x2, 0x2, 0x91, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x92, 0x93, 0x5, 0x62, 0x32, 0x2, 0x93, 0x94, 0x5, 0x6, 0x4, 0x2, 0x94, 
    0x95, 0x5, 0x10, 0x9, 0x2, 0x95, 0x5, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 
    0x5, 0x3a, 0x1e, 0x2, 0x97, 0x98, 0x5, 0x6, 0x4, 0x2, 0x98, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x8, 0x5, 0x2, 0x9a, 0x9b, 0x5, 0x6, 
    0x4, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x96, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0xa0, 0x7, 0x3, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x3f, 0x2, 0x2, 0xa1, 0xa2, 
    0x5, 0xa, 0x6, 0x2, 0xa2, 0xa3, 0x7, 0x40, 0x2, 0x2, 0xa3, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x62, 0x32, 0x2, 0xa5, 0xa6, 0x5, 0xe, 
    0x8, 0x2, 0xa6, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0xb, 0x2, 
    0x2, 0xa8, 0xa9, 0x7, 0x45, 0x2, 0x2, 0xa9, 0xaa, 0x9, 0x2, 0x2, 0x2, 
    0xaa, 0xab, 0x7, 0x46, 0x2, 0x2, 0xab, 0xd, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xad, 0x5, 0x3a, 0x1e, 0x2, 0xad, 0xae, 0x5, 0xe, 0x8, 0x2, 0xae, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x60, 0x31, 0x2, 0xb0, 0xb1, 0x5, 
    0xe, 0x8, 0x2, 0xb1, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x5, 0xc, 
    0x7, 0x2, 0xb3, 0xb4, 0x5, 0xe, 0x8, 0x2, 0xb4, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb6, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 
    0x5, 0x12, 0xa, 0x2, 0xb9, 0xba, 0x5, 0x10, 0x9, 0x2, 0xba, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbf, 0x7, 0x5, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x3f, 0x2, 0x2, 
    0xc0, 0xc1, 0x5, 0x14, 0xb, 0x2, 0xc1, 0xc2, 0x7, 0x40, 0x2, 0x2, 0xc2, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x16, 0xc, 0x2, 0xc4, 0xc5, 
    0x5, 0x14, 0xb, 0x2, 0xc5, 0xce, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x5, 
    0x18, 0xd, 0x2, 0xc7, 0xc8, 0x5, 0x14, 0xb, 0x2, 0xc8, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xca, 0x5, 0x1a, 0xe, 0x2, 0xca, 0xcb, 0x5, 0x14, 0xb, 
    0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xc9, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0xa, 0x2, 0x2, 0xd0, 0xd1, 0x7, 
    0x45, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x39, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x46, 
    0x2, 0x2, 0xd3, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x6, 0x2, 
    0x2, 0xd5, 0xd6, 0x7, 0x45, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x64, 0x33, 0x2, 
    0xd7, 0xd8, 0x7, 0x46, 0x2, 0x2, 0xd8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xda, 0x7, 0x7, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x45, 0x2, 0x2, 0xdb, 0xdc, 
    0x5, 0x64, 0x33, 0x2, 0xdc, 0xdd, 0x7, 0x46, 0x2, 0x2, 0xdd, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xf2, 0x7, 0x3a, 0x2, 0x2, 0xdf, 0xf2, 0x7, 0x9, 
    0x2, 0x2, 0xe0, 0xf2, 0x7, 0xa, 0x2, 0x2, 0xe1, 0xf2, 0x7, 0xb, 0x2, 
    0x2, 0xe2, 0xf2, 0x7, 0xc, 0x2, 0x2, 0xe3, 0xf2, 0x9, 0x3, 0x2, 0x2, 
    0xe4, 0xf2, 0x7, 0x1a, 0x2, 0x2, 0xe5, 0xf2, 0x7, 0x1b, 0x2, 0x2, 0xe6, 
    0xf2, 0x7, 0x1c, 0x2, 0x2, 0xe7, 0xf2, 0x7, 0x1d, 0x2, 0x2, 0xe8, 0xf2, 
    0x7, 0x1e, 0x2, 0x2, 0xe9, 0xf2, 0x7, 0x1f, 0x2, 0x2, 0xea, 0xf2, 0x7, 
    0x20, 0x2, 0x2, 0xeb, 0xf2, 0x7, 0x27, 0x2, 0x2, 0xec, 0xf2, 0x7, 0x3, 
    0x2, 0x2, 0xed, 0xf2, 0x7, 0x4, 0x2, 0x2, 0xee, 0xf2, 0x7, 0x5, 0x2, 
    0x2, 0xef, 0xf2, 0x7, 0x6, 0x2, 0x2, 0xf0, 0xf2, 0x7, 0x7, 0x2, 0x2, 
    0xf1, 0xde, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xea, 0x3, 0x2, 0x2, 0x2, 
    0xf1, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xf3, 0xf8, 0x5, 0x1c, 0xf, 0x2, 0xf4, 0xf5, 0x7, 0x49, 
    0x2, 0x2, 0xf5, 0xf7, 0x5, 0x1c, 0xf, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x100, 0x5, 0x1c, 0xf, 0x2, 0xfc, 0xfd, 
    0x7, 0x49, 0x2, 0x2, 0xfd, 0xff, 0x5, 0x1c, 0xf, 0x2, 0xfe, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0xff, 0x102, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 
    0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x103, 0x10d, 0x5, 0x40, 0x21, 
    0x2, 0x104, 0x109, 0x5, 0x1c, 0xf, 0x2, 0x105, 0x106, 0x7, 0x49, 0x2, 
    0x2, 0x106, 0x108, 0x5, 0x1c, 0xf, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x108, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x104, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x10e, 0x10f, 0x5, 0x20, 0x11, 0x2, 0x10f, 0x110, 0x7, 0x3d, 0x2, 0x2, 
    0x110, 0x111, 0x5, 0x58, 0x2d, 0x2, 0x111, 0x112, 0x7, 0x3e, 0x2, 0x2, 
    0x112, 0x25, 0x3, 0x2, 0x2, 0x2, 0x113, 0x117, 0x5, 0x30, 0x19, 0x2, 
    0x114, 0x117, 0x5, 0x3a, 0x1e, 0x2, 0x115, 0x117, 0x5, 0x4e, 0x28, 0x2, 
    0x116, 0x113, 0x3, 0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 
    0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 
    0x119, 0x27, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x11c, 0x5, 0x2a, 0x16, 0x2, 0x11c, 0x11d, 0x5, 0x28, 0x15, 0x2, 0x11d, 
    0x120, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x11b, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0x1d, 0x2, 0x2, 0x122, 
    0x123, 0x7, 0x43, 0x2, 0x2, 0x123, 0x124, 0x5, 0x2c, 0x17, 0x2, 0x124, 
    0x125, 0x7, 0x44, 0x2, 0x2, 0x125, 0x126, 0x5, 0x2e, 0x18, 0x2, 0x126, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x5, 0x1c, 0xf, 0x2, 0x128, 
    0x129, 0x7, 0x49, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x1c, 0xf, 0x2, 0x12a, 
    0x133, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x7, 0x36, 0x2, 0x2, 0x12c, 
    0x12d, 0x7, 0x4d, 0x2, 0x2, 0x12d, 0x133, 0x5, 0x2c, 0x17, 0x2, 0x12e, 
    0x12f, 0x5, 0x1c, 0xf, 0x2, 0x12f, 0x130, 0x7, 0x4d, 0x2, 0x2, 0x130, 
    0x131, 0x5, 0x2c, 0x17, 0x2, 0x131, 0x133, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x127, 0x3, 0x2, 0x2, 0x2, 0x132, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x12e, 0x3, 0x2, 0x2, 0x2, 0x133, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 
    0x7, 0x27, 0x2, 0x2, 0x135, 0x138, 0x5, 0x1c, 0xf, 0x2, 0x136, 0x138, 
    0x3, 0x2, 0x2, 0x2, 0x137, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x136, 
    0x3, 0x2, 0x2, 0x2, 0x138, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x7, 
    0xc, 0x2, 0x2, 0x13a, 0x13b, 0x5, 0x32, 0x1a, 0x2, 0x13b, 0x13c, 0x5, 
    0x1c, 0xf, 0x2, 0x13c, 0x13d, 0x7, 0x46, 0x2, 0x2, 0x13d, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x13e, 0x145, 0x5, 0x34, 0x1b, 0x2, 0x13f, 0x145, 0x5, 
    0x36, 0x1c, 0x2, 0x140, 0x145, 0x5, 0x38, 0x1d, 0x2, 0x141, 0x145, 0x7, 
    0xf, 0x2, 0x2, 0x142, 0x145, 0x7, 0x10, 0x2, 0x2, 0x143, 0x145, 0x5, 
    0x1c, 0xf, 0x2, 0x144, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x144, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x144, 0x140, 0x3, 0x2, 0x2, 0x2, 0x144, 0x141, 0x3, 
    0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x33, 0x3, 0x2, 0x2, 0x2, 0x146, 0x14d, 0x7, 0xd, 
    0x2, 0x2, 0x147, 0x148, 0x7, 0x3d, 0x2, 0x2, 0x148, 0x149, 0x7, 0x37, 
    0x2, 0x2, 0x149, 0x14a, 0x7, 0x36, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x37, 
    0x2, 0x2, 0x14b, 0x14e, 0x7, 0x3e, 0x2, 0x2, 0x14c, 0x14e, 0x3, 0x2, 
    0x2, 0x2, 0x14d, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x35, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x156, 0x7, 0xe, 0x2, 
    0x2, 0x150, 0x151, 0x7, 0x3d, 0x2, 0x2, 0x151, 0x152, 0x7, 0x38, 0x2, 
    0x2, 0x152, 0x153, 0x7, 0x36, 0x2, 0x2, 0x153, 0x154, 0x7, 0x38, 0x2, 
    0x2, 0x154, 0x157, 0x7, 0x3e, 0x2, 0x2, 0x155, 0x157, 0x3, 0x2, 0x2, 
    0x2, 0x156, 0x150, 0x3, 0x2, 0x2, 0x2, 0x156, 0x155, 0x3, 0x2, 0x2, 
    0x2, 0x157, 0x37, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x7, 0x17, 0x2, 
    0x2, 0x159, 0x15a, 0x7, 0x3d, 0x2, 0x2, 0x15a, 0x15f, 0x5, 0x1c, 0xf, 
    0x2, 0x15b, 0x15c, 0x7, 0x47, 0x2, 0x2, 0x15c, 0x15e, 0x5, 0x1c, 0xf, 
    0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x161, 0x3, 0x2, 0x2, 
    0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x162, 0x3, 0x2, 0x2, 0x2, 0x161, 0x15f, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x163, 0x7, 0x3e, 0x2, 0x2, 0x163, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x164, 0x165, 0x7, 0x1a, 0x2, 0x2, 0x165, 0x166, 0x5, 0x32, 0x1a, 
    0x2, 0x166, 0x169, 0x5, 0x1c, 0xf, 0x2, 0x167, 0x168, 0x7, 0x32, 0x2, 
    0x2, 0x168, 0x16a, 0x5, 0x3c, 0x1f, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x3, 0x2, 0x2, 
    0x2, 0x16b, 0x16c, 0x7, 0x46, 0x2, 0x2, 0x16c, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x16d, 0x174, 0x7, 0x37, 0x2, 0x2, 0x16e, 0x174, 0x7, 0x38, 0x2, 
    0x2, 0x16f, 0x174, 0x7, 0x39, 0x2, 0x2, 0x170, 0x174, 0x7, 0x2f, 0x2, 
    0x2, 0x171, 0x174, 0x7, 0x30, 0x2, 0x2, 0x172, 0x174, 0x5, 0x1c, 0xf, 
    0x2, 0x173, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x173, 0x16e, 0x3, 0x2, 0x2, 
    0x2, 0x173, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x173, 0x170, 0x3, 0x2, 0x2, 
    0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x172, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x5, 0x5c, 0x2f, 
    0x2, 0x176, 0x177, 0x5, 0x1c, 0xf, 0x2, 0x177, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x178, 0x17b, 0x5, 0x5e, 0x30, 0x2, 0x179, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 
    0x2, 0x17b, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x5, 0x1c, 0xf, 
    0x2, 0x17d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x1f, 0x2, 
    0x2, 0x17f, 0x180, 0x5, 0x1c, 0xf, 0x2, 0x180, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x181, 0x182, 0x5, 0x40, 0x21, 0x2, 0x182, 0x183, 0x7, 0x32, 0x2, 
    0x2, 0x183, 0x184, 0x5, 0x76, 0x3c, 0x2, 0x184, 0x185, 0x7, 0x46, 0x2, 
    0x2, 0x185, 0x45, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x5, 0x32, 0x1a, 
    0x2, 0x187, 0x18b, 0x5, 0x1c, 0xf, 0x2, 0x188, 0x189, 0x7, 0x32, 0x2, 
    0x2, 0x189, 0x18c, 0x5, 0x76, 0x3c, 0x2, 0x18a, 0x18c, 0x3, 0x2, 0x2, 
    0x2, 0x18b, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x7, 0x46, 0x2, 
    0x2, 0x18e, 0x47, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x20, 0x2, 
    0x2, 0x190, 0x193, 0x5, 0x24, 0x13, 0x2, 0x191, 0x194, 0x5, 0x42, 0x22, 
    0x2, 0x192, 0x194, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 0x2, 
    0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x195, 0x196, 0x7, 0x46, 0x2, 0x2, 0x196, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x19a, 0x5, 0x44, 0x23, 0x2, 0x198, 0x19a, 0x5, 0x48, 0x25, 
    0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x198, 0x3, 0x2, 0x2, 
    0x2, 0x19a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19f, 0x7, 0x3f, 0x2, 
    0x2, 0x19c, 0x19e, 0x5, 0x4a, 0x26, 0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 
    0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a2, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x40, 0x2, 
    0x2, 0x1a3, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x1b, 0x2, 
    0x2, 0x1a5, 0x1b4, 0x5, 0x1c, 0xf, 0x2, 0x1a6, 0x1b0, 0x7, 0x3d, 0x2, 
    0x2, 0x1a7, 0x1ac, 0x5, 0x50, 0x29, 0x2, 0x1a8, 0x1a9, 0x7, 0x47, 0x2, 
    0x2, 0x1a9, 0x1ab, 0x5, 0x50, 0x29, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 
    0x2, 0x1ab, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x1b0, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1af, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b5, 0x7, 0x3e, 0x2, 
    0x2, 0x1b3, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x1b4, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1b7, 0x7, 0x46, 0x2, 0x2, 0x1b7, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x1b8, 0x1b9, 0x5, 0x32, 0x1a, 0x2, 0x1b9, 0x1ba, 0x5, 0x1c, 0xf, 
    0x2, 0x1ba, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x21, 0x2, 
    0x2, 0x1bc, 0x1bd, 0x5, 0x32, 0x1a, 0x2, 0x1bd, 0x1be, 0x5, 0x64, 0x33, 
    0x2, 0x1be, 0x1c1, 0x7, 0x3d, 0x2, 0x2, 0x1bf, 0x1c2, 0x5, 0x54, 0x2b, 
    0x2, 0x1c0, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 
    0x2, 0x1c1, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c3, 0x1c4, 0x7, 0x3e, 0x2, 0x2, 0x1c4, 0x1c5, 0x5, 0x6c, 0x37, 
    0x2, 0x1c5, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1cb, 0x5, 0x50, 0x29, 
    0x2, 0x1c7, 0x1c8, 0x7, 0x47, 0x2, 0x2, 0x1c8, 0x1ca, 0x5, 0x50, 0x29, 
    0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cd, 0x3, 0x2, 0x2, 
    0x2, 0x1cb, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x3, 0x2, 0x2, 
    0x2, 0x1cc, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cb, 0x3, 0x2, 0x2, 0x2, 
    0x1ce, 0x1cf, 0x5, 0x64, 0x33, 0x2, 0x1cf, 0x1d0, 0x7, 0x3d, 0x2, 0x2, 
    0x1d0, 0x1d1, 0x5, 0x58, 0x2d, 0x2, 0x1d1, 0x1d2, 0x7, 0x3e, 0x2, 0x2, 
    0x1d2, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d9, 0x5, 0x3c, 0x1f, 0x2, 
    0x1d4, 0x1d9, 0x5, 0x3e, 0x20, 0x2, 0x1d5, 0x1d9, 0x5, 0x40, 0x21, 0x2, 
    0x1d6, 0x1d9, 0x5, 0x56, 0x2c, 0x2, 0x1d7, 0x1d9, 0x3, 0x2, 0x2, 0x2, 
    0x1d8, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
    0x1d8, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d6, 0x3, 0x2, 0x2, 0x2, 
    0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x1db, 0x5, 0x5a, 0x2e, 0x2, 0x1db, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x1dc, 0x1dd, 0x7, 0x47, 0x2, 0x2, 0x1dd, 0x1e0, 0x5, 0x58, 0x2d, 0x2, 
    0x1de, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1dc, 0x3, 0x2, 0x2, 0x2, 
    0x1df, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
    0x1e2, 0x9, 0x3, 0x2, 0x2, 0x1e2, 0x1e3, 0x7, 0x49, 0x2, 0x2, 0x1e3, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x7, 0x13, 0x2, 0x2, 0x1e5, 
    0x1e6, 0x7, 0x49, 0x2, 0x2, 0x1e6, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1e7, 
    0x1e8, 0x7, 0x1c, 0x2, 0x2, 0x1e8, 0x1ed, 0x5, 0x1c, 0xf, 0x2, 0x1e9, 
    0x1ea, 0x7, 0x47, 0x2, 0x2, 0x1ea, 0x1ec, 0x5, 0x1c, 0xf, 0x2, 0x1eb, 
    0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ed, 
    0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
    0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
    0x1f1, 0x7, 0x46, 0x2, 0x2, 0x1f1, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
    0x1f3, 0x7, 0x9, 0x2, 0x2, 0x1f3, 0x1f4, 0x7, 0x45, 0x2, 0x2, 0x1f4, 
    0x1f5, 0x5, 0x1c, 0xf, 0x2, 0x1f5, 0x1f6, 0x7, 0x46, 0x2, 0x2, 0x1f6, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1fc, 0x5, 0x1c, 0xf, 0x2, 0x1f8, 
    0x1f9, 0x7, 0x49, 0x2, 0x2, 0x1f9, 0x1fb, 0x5, 0x1c, 0xf, 0x2, 0x1fa, 
    0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fc, 
    0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fd, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x202, 
    0x5, 0x68, 0x35, 0x2, 0x200, 0x202, 0x5, 0x6c, 0x37, 0x2, 0x201, 0x1ff, 
    0x3, 0x2, 0x2, 0x2, 0x201, 0x200, 0x3, 0x2, 0x2, 0x2, 0x202, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x203, 0x20c, 0x5, 0x6a, 0x36, 0x2, 0x204, 0x20c, 0x5, 
    0x44, 0x23, 0x2, 0x205, 0x20c, 0x5, 0x82, 0x42, 0x2, 0x206, 0x20c, 0x5, 
    0x7a, 0x3e, 0x2, 0x207, 0x20c, 0x5, 0x46, 0x24, 0x2, 0x208, 0x20c, 0x5, 
    0x48, 0x25, 0x2, 0x209, 0x20c, 0x5, 0x70, 0x39, 0x2, 0x20a, 0x20c, 0x5, 
    0x6e, 0x38, 0x2, 0x20b, 0x203, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x204, 0x3, 
    0x2, 0x2, 0x2, 0x20b, 0x205, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x206, 0x3, 
    0x2, 0x2, 0x2, 0x20b, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x208, 0x3, 
    0x2, 0x2, 0x2, 0x20b, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20a, 0x3, 
    0x2, 0x2, 0x2, 0x20c, 0x69, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x5, 0x56, 
    0x2c, 0x2, 0x20e, 0x20f, 0x7, 0x46, 0x2, 0x2, 0x20f, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x210, 0x214, 0x7, 0x3f, 0x2, 0x2, 0x211, 0x213, 0x5, 0x68, 
    0x35, 0x2, 0x212, 0x211, 0x3, 0x2, 0x2, 0x2, 0x213, 0x216, 0x3, 0x2, 
    0x2, 0x2, 0x214, 0x212, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x3, 0x2, 
    0x2, 0x2, 0x215, 0x217, 0x3, 0x2, 0x2, 0x2, 0x216, 0x214, 0x3, 0x2, 
    0x2, 0x2, 0x217, 0x218, 0x7, 0x40, 0x2, 0x2, 0x218, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x219, 0x21a, 0x7, 0x14, 0x2, 0x2, 0x21a, 0x21b, 0x5, 0x72, 
    0x3a, 0x2, 0x21b, 0x21c, 0x7, 0x46, 0x2, 0x2, 0x21c, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x21d, 0x21e, 0x7, 0x31, 0x2, 0x2, 0x21e, 0x21f, 0x7, 0x46, 
    0x2, 0x2, 0x21f, 0x71, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x5, 0x8a, 
    0x46, 0x2, 0x221, 0x222, 0x5, 0x74, 0x3b, 0x2, 0x222, 0x22c, 0x3, 0x2, 
    0x2, 0x2, 0x223, 0x224, 0x7, 0x3d, 0x2, 0x2, 0x224, 0x225, 0x5, 0x72, 
    0x3a, 0x2, 0x225, 0x226, 0x7, 0x3e, 0x2, 0x2, 0x226, 0x22c, 0x3, 0x2, 
    0x2, 0x2, 0x227, 0x228, 0x7, 0x4b, 0x2, 0x2, 0x228, 0x22c, 0x5, 0x72, 
    0x3a, 0x2, 0x229, 0x22a, 0x7, 0x29, 0x2, 0x2, 0x22a, 0x22c, 0x5, 0x72, 
    0x3a, 0x2, 0x22b, 0x220, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x223, 0x3, 0x2, 
    0x2, 0x2, 0x22b, 0x227, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 
    0x2, 0x2, 0x22c, 0x73, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x9, 0x4, 0x2, 
    0x2, 0x22e, 0x231, 0x5, 0x72, 0x3a, 0x2, 0x22f, 0x231, 0x3, 0x2, 0x2, 
    0x2, 0x230, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22f, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x75, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x7, 0x3d, 0x2, 
    0x2, 0x233, 0x234, 0x5, 0x76, 0x3c, 0x2, 0x234, 0x235, 0x7, 0x3e, 0x2, 
    0x2, 0x235, 0x236, 0x5, 0x78, 0x3d, 0x2, 0x236, 0x241, 0x3, 0x2, 0x2, 
    0x2, 0x237, 0x238, 0x7, 0x29, 0x2, 0x2, 0x238, 0x241, 0x5, 0x76, 0x3c, 
    0x2, 0x239, 0x23a, 0x7, 0x2c, 0x2, 0x2, 0x23a, 0x241, 0x5, 0x76, 0x3c, 
    0x2, 0x23b, 0x23c, 0x7, 0x4b, 0x2, 0x2, 0x23c, 0x241, 0x5, 0x76, 0x3c, 
    0x2, 0x23d, 0x23e, 0x5, 0x72, 0x3a, 0x2, 0x23e, 0x23f, 0x5, 0x78, 0x3d, 
    0x2, 0x23f, 0x241, 0x3, 0x2, 0x2, 0x2, 0x240, 0x232, 0x3, 0x2, 0x2, 
    0x2, 0x240, 0x237, 0x3, 0x2, 0x2, 0x2, 0x240, 0x239, 0x3, 0x2, 0x2, 
    0x2, 0x240, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x240, 0x23d, 0x3, 0x2, 0x2, 
    0x2, 0x241, 0x77, 0x3, 0x2, 0x2, 0x2, 0x242, 0x256, 0x7, 0x2b, 0x2, 
    0x2, 0x243, 0x256, 0x7, 0x2e, 0x2, 0x2, 0x244, 0x256, 0x7, 0x2a, 0x2, 
    0x2, 0x245, 0x256, 0x7, 0x2d, 0x2, 0x2, 0x246, 0x247, 0x7, 0x32, 0x2, 
    0x2, 0x247, 0x256, 0x7, 0x32, 0x2, 0x2, 0x248, 0x249, 0x7, 0x29, 0x2, 
    0x2, 0x249, 0x256, 0x7, 0x32, 0x2, 0x2, 0x24a, 0x256, 0x7, 0x2c, 0x2, 
    0x2, 0x24b, 0x24e, 0x7, 0x43, 0x2, 0x2, 0x24c, 0x24f, 0x7, 0x32, 0x2, 
    0x2, 0x24d, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24c, 0x3, 0x2, 0x2, 
    0x2, 0x24e, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x250, 0x253, 0x7, 0x44, 0x2, 0x2, 0x251, 0x254, 0x7, 0x32, 0x2, 
    0x2, 0x252, 0x254, 0x3, 0x2, 0x2, 0x2, 0x253, 0x251, 0x3, 0x2, 0x2, 
    0x2, 0x253, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x242, 0x3, 0x2, 0x2, 0x2, 0x255, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x244, 0x3, 0x2, 0x2, 0x2, 0x255, 0x245, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x246, 0x3, 0x2, 0x2, 0x2, 0x255, 0x248, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x255, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x250, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x3, 0x2, 0x2, 
    0x2, 0x257, 0x25a, 0x5, 0x76, 0x3c, 0x2, 0x258, 0x25a, 0x3, 0x2, 0x2, 
    0x2, 0x259, 0x255, 0x3, 0x2, 0x2, 0x2, 0x259, 0x258, 0x3, 0x2, 0x2, 
    0x2, 0x25a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25e, 0x5, 0x7c, 0x3f, 
    0x2, 0x25c, 0x25f, 0x5, 0x80, 0x41, 0x2, 0x25d, 0x25f, 0x3, 0x2, 0x2, 
    0x2, 0x25e, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25d, 0x3, 0x2, 0x2, 
    0x2, 0x25f, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0x7, 0x25, 0x2, 
    0x2, 0x261, 0x264, 0x5, 0x7e, 0x40, 0x2, 0x262, 0x265, 0x5, 0x66, 0x34, 
    0x2, 0x263, 0x265, 0x7, 0x46, 0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 
    0x2, 0x264, 0x263, 0x3, 0x2, 0x2, 0x2, 0x265, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x266, 0x267, 0x7, 0x3d, 0x2, 0x2, 0x267, 0x268, 0x5, 0x76, 0x3c, 0x2, 
    0x268, 0x269, 0x7, 0x3e, 0x2, 0x2, 0x269, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x26a, 0x26b, 0x7, 0x26, 0x2, 0x2, 0x26b, 0x26c, 0x5, 0x66, 0x34, 0x2, 
    0x26c, 0x81, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x7, 0x22, 0x2, 0x2, 
    0x26e, 0x26f, 0x5, 0x84, 0x43, 0x2, 0x26f, 0x273, 0x7, 0x3f, 0x2, 0x2, 
    0x270, 0x272, 0x5, 0x86, 0x44, 0x2, 0x271, 0x270, 0x3, 0x2, 0x2, 0x2, 
    0x272, 0x275, 0x3, 0x2, 0x2, 0x2, 0x273, 0x271, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x274, 0x3, 0x2, 0x2, 0x2, 0x274, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x275, 0x273, 0x3, 0x2, 0x2, 0x2, 0x276, 0x279, 0x5, 0x88, 0x45, 0x2, 
    0x277, 0x279, 0x3, 0x2, 0x2, 0x2, 0x278, 0x276, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x277, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x3, 0x2, 0x2, 0x2, 
    0x27a, 0x27b, 0x7, 0x40, 0x2, 0x2, 0x27b, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0x27c, 0x27d, 0x7, 0x3d, 0x2, 0x2, 0x27d, 0x27e, 0x5, 0x1c, 0xf, 0x2, 
    0x27e, 0x27f, 0x7, 0x3e, 0x2, 0x2, 0x27f, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x280, 0x281, 0x7, 0x23, 0x2, 0x2, 0x281, 0x282, 0x5, 0x3c, 0x1f, 0x2, 
    0x282, 0x28a, 0x7, 0x45, 0x2, 0x2, 0x283, 0x28b, 0x5, 0x6c, 0x37, 0x2, 
    0x284, 0x286, 0x5, 0x68, 0x35, 0x2, 0x285, 0x284, 0x3, 0x2, 0x2, 0x2, 
    0x286, 0x289, 0x3, 0x2, 0x2, 0x2, 0x287, 0x285, 0x3, 0x2, 0x2, 0x2, 
    0x287, 0x288, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28b, 0x3, 0x2, 0x2, 0x2, 
    0x289, 0x287, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x283, 0x3, 0x2, 0x2, 0x2, 
    0x28a, 0x287, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x87, 0x3, 0x2, 0x2, 0x2, 0x28c, 
    0x28d, 0x7, 0x24, 0x2, 0x2, 0x28d, 0x295, 0x7, 0x45, 0x2, 0x2, 0x28e, 
    0x296, 0x5, 0x6c, 0x37, 0x2, 0x28f, 0x291, 0x5, 0x68, 0x35, 0x2, 0x290, 
    0x28f, 0x3, 0x2, 0x2, 0x2, 0x291, 0x294, 0x3, 0x2, 0x2, 0x2, 0x292, 
    0x290, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 
    0x296, 0x3, 0x2, 0x2, 0x2, 0x294, 0x292, 0x3, 0x2, 0x2, 0x2, 0x295, 
    0x28e, 0x3, 0x2, 0x2, 0x2, 0x295, 0x292, 0x3, 0x2, 0x2, 0x2, 0x296, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x297, 0x29c, 0x5, 0x3e, 0x20, 0x2, 0x298, 
    0x29c, 0x5, 0x40, 0x21, 0x2, 0x299, 0x29c, 0x5, 0x56, 0x2c, 0x2, 0x29a, 
    0x29c, 0x5, 0x3c, 0x1f, 0x2, 0x29b, 0x297, 0x3, 0x2, 0x2, 0x2, 0x29b, 
    0x298, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29b, 
    0x29a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x37, 0x9d, 
    0xb6, 0xbc, 0xcd, 0xf1, 0xf8, 0x100, 0x109, 0x10c, 0x116, 0x118, 0x11f, 
    0x132, 0x137, 0x144, 0x14d, 0x156, 0x15f, 0x169, 0x173, 0x17a, 0x18b, 
    0x193, 0x199, 0x19f, 0x1ac, 0x1b0, 0x1b4, 0x1c1, 0x1cb, 0x1d8, 0x1df, 
    0x1ed, 0x1fc, 0x201, 0x20b, 0x214, 0x22b, 0x230, 0x240, 0x24e, 0x253, 
    0x255, 0x259, 0x25e, 0x264, 0x273, 0x278, 0x287, 0x28a, 0x292, 0x295, 
    0x29b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TestSystemDeclParser::Initializer TestSystemDeclParser::_init;
