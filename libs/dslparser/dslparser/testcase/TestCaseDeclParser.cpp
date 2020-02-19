
// Generated from C:/Users/s_phs.DESKTOP-9GA53KK/Documents/mobata/libs/dslparser/dslparser/grammars/TestCaseDecl.g4 by ANTLR 4.7


#include "TestCaseDeclListener.h"

#include "TestCaseDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

TestCaseDeclParser::TestCaseDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TestCaseDeclParser::~TestCaseDeclParser() {
  delete _interpreter;
}

std::string TestCaseDeclParser::getGrammarFileName() const {
  return "TestCaseDecl.g4";
}

const std::vector<std::string>& TestCaseDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TestCaseDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- TestCaseDeclContext ------------------------------------------------------------------

TestCaseDeclParser::TestCaseDeclContext::TestCaseDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::ImportPathDeclContext* TestCaseDeclParser::TestCaseDeclContext::importPathDecl() {
  return getRuleContext<TestCaseDeclParser::ImportPathDeclContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::TestCaseDeclContext::TestCaseID() {
  return getToken(TestCaseDeclParser::TestCaseID, 0);
}

tree::TerminalNode* TestCaseDeclParser::TestCaseDeclContext::LBRACE() {
  return getToken(TestCaseDeclParser::LBRACE, 0);
}

TestCaseDeclParser::TestCaseBodyContext* TestCaseDeclParser::TestCaseDeclContext::testCaseBody() {
  return getRuleContext<TestCaseDeclParser::TestCaseBodyContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::TestCaseDeclContext::RBRACE() {
  return getToken(TestCaseDeclParser::RBRACE, 0);
}


size_t TestCaseDeclParser::TestCaseDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleTestCaseDecl;
}

void TestCaseDeclParser::TestCaseDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestCaseDecl(this);
}

void TestCaseDeclParser::TestCaseDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestCaseDecl(this);
}

TestCaseDeclParser::TestCaseDeclContext* TestCaseDeclParser::testCaseDecl() {
  TestCaseDeclContext *_localctx = _tracker.createInstance<TestCaseDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, TestCaseDeclParser::RuleTestCaseDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    importPathDecl();
    setState(149);
    match(TestCaseDeclParser::TestCaseID);
    setState(150);
    match(TestCaseDeclParser::LBRACE);
    setState(151);
    testCaseBody();
    setState(152);
    match(TestCaseDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TestCaseBodyContext ------------------------------------------------------------------

TestCaseDeclParser::TestCaseBodyContext::TestCaseBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::TestCaseBodyContext::DeclarationID() {
  return getToken(TestCaseDeclParser::DeclarationID, 0);
}

tree::TerminalNode* TestCaseDeclParser::TestCaseBodyContext::LBRACE() {
  return getToken(TestCaseDeclParser::LBRACE, 0);
}

TestCaseDeclParser::DeclarationsContext* TestCaseDeclParser::TestCaseBodyContext::declarations() {
  return getRuleContext<TestCaseDeclParser::DeclarationsContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::TestCaseBodyContext::RBRACE() {
  return getToken(TestCaseDeclParser::RBRACE, 0);
}

TestCaseDeclParser::StepsContext* TestCaseDeclParser::TestCaseBodyContext::steps() {
  return getRuleContext<TestCaseDeclParser::StepsContext>(0);
}


size_t TestCaseDeclParser::TestCaseBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleTestCaseBody;
}

void TestCaseDeclParser::TestCaseBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestCaseBody(this);
}

void TestCaseDeclParser::TestCaseBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestCaseBody(this);
}

TestCaseDeclParser::TestCaseBodyContext* TestCaseDeclParser::testCaseBody() {
  TestCaseBodyContext *_localctx = _tracker.createInstance<TestCaseBodyContext>(_ctx, getState());
  enterRule(_localctx, 2, TestCaseDeclParser::RuleTestCaseBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(TestCaseDeclParser::DeclarationID);
    setState(155);
    match(TestCaseDeclParser::LBRACE);
    setState(156);
    declarations();
    setState(157);
    match(TestCaseDeclParser::RBRACE);
    setState(158);
    steps();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

TestCaseDeclParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::AttributeDeclContext* TestCaseDeclParser::DeclarationsContext::attributeDecl() {
  return getRuleContext<TestCaseDeclParser::AttributeDeclContext>(0);
}

TestCaseDeclParser::DeclarationsContext* TestCaseDeclParser::DeclarationsContext::declarations() {
  return getRuleContext<TestCaseDeclParser::DeclarationsContext>(0);
}

TestCaseDeclParser::NameDeclContext* TestCaseDeclParser::DeclarationsContext::nameDecl() {
  return getRuleContext<TestCaseDeclParser::NameDeclContext>(0);
}

TestCaseDeclParser::UuidDeclContext* TestCaseDeclParser::DeclarationsContext::uuidDecl() {
  return getRuleContext<TestCaseDeclParser::UuidDeclContext>(0);
}

TestCaseDeclParser::EnabledDeclContext* TestCaseDeclParser::DeclarationsContext::enabledDecl() {
  return getRuleContext<TestCaseDeclParser::EnabledDeclContext>(0);
}

TestCaseDeclParser::SignalDeclContext* TestCaseDeclParser::DeclarationsContext::signalDecl() {
  return getRuleContext<TestCaseDeclParser::SignalDeclContext>(0);
}

TestCaseDeclParser::CheckDeclContext* TestCaseDeclParser::DeclarationsContext::checkDecl() {
  return getRuleContext<TestCaseDeclParser::CheckDeclContext>(0);
}

TestCaseDeclParser::AliasDefContext* TestCaseDeclParser::DeclarationsContext::aliasDef() {
  return getRuleContext<TestCaseDeclParser::AliasDefContext>(0);
}


size_t TestCaseDeclParser::DeclarationsContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleDeclarations;
}

void TestCaseDeclParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void TestCaseDeclParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

TestCaseDeclParser::DeclarationsContext* TestCaseDeclParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, TestCaseDeclParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        attributeDecl();
        setState(161);
        declarations();
        break;
      }

      case TestCaseDeclParser::NameID: {
        enterOuterAlt(_localctx, 2);
        setState(163);
        nameDecl();
        setState(164);
        declarations();
        break;
      }

      case TestCaseDeclParser::UuidID: {
        enterOuterAlt(_localctx, 3);
        setState(166);
        uuidDecl();
        setState(167);
        declarations();
        break;
      }

      case TestCaseDeclParser::EnabledID: {
        enterOuterAlt(_localctx, 4);
        setState(169);
        enabledDecl();
        setState(170);
        declarations();
        break;
      }

      case TestCaseDeclParser::SignalID: {
        enterOuterAlt(_localctx, 5);
        setState(172);
        signalDecl();
        setState(173);
        declarations();
        break;
      }

      case TestCaseDeclParser::CheckID: {
        enterOuterAlt(_localctx, 6);
        setState(175);
        checkDecl();
        setState(176);
        declarations();
        break;
      }

      case TestCaseDeclParser::ComponentID: {
        enterOuterAlt(_localctx, 7);
        setState(178);
        aliasDef();
        setState(179);
        declarations();
        break;
      }

      case TestCaseDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 8);

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

//----------------- AliasDefContext ------------------------------------------------------------------

TestCaseDeclParser::AliasDefContext::AliasDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::AliasDefContext::ComponentID() {
  return getToken(TestCaseDeclParser::ComponentID, 0);
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::AliasDefContext::idPath() {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::AliasDefContext::AsID() {
  return getToken(TestCaseDeclParser::AsID, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::AliasDefContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::AliasDefContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::AliasDefContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAliasDef;
}

void TestCaseDeclParser::AliasDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasDef(this);
}

void TestCaseDeclParser::AliasDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasDef(this);
}

TestCaseDeclParser::AliasDefContext* TestCaseDeclParser::aliasDef() {
  AliasDefContext *_localctx = _tracker.createInstance<AliasDefContext>(_ctx, getState());
  enterRule(_localctx, 6, TestCaseDeclParser::RuleAliasDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(TestCaseDeclParser::ComponentID);
    setState(185);
    idPath();
    setState(186);
    match(TestCaseDeclParser::AsID);
    setState(187);
    contextID();
    setState(188);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepsContext ------------------------------------------------------------------

TestCaseDeclParser::StepsContext::StepsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::TimerDeclContext* TestCaseDeclParser::StepsContext::timerDecl() {
  return getRuleContext<TestCaseDeclParser::TimerDeclContext>(0);
}

TestCaseDeclParser::StepsContext* TestCaseDeclParser::StepsContext::steps() {
  return getRuleContext<TestCaseDeclParser::StepsContext>(0);
}

TestCaseDeclParser::MessageDeclContext* TestCaseDeclParser::StepsContext::messageDecl() {
  return getRuleContext<TestCaseDeclParser::MessageDeclContext>(0);
}

TestCaseDeclParser::CheckDeclContext* TestCaseDeclParser::StepsContext::checkDecl() {
  return getRuleContext<TestCaseDeclParser::CheckDeclContext>(0);
}

TestCaseDeclParser::AltDeclContext* TestCaseDeclParser::StepsContext::altDecl() {
  return getRuleContext<TestCaseDeclParser::AltDeclContext>(0);
}

TestCaseDeclParser::IdStatementContext* TestCaseDeclParser::StepsContext::idStatement() {
  return getRuleContext<TestCaseDeclParser::IdStatementContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::StepsContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::StepsContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSteps;
}

void TestCaseDeclParser::StepsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSteps(this);
}

void TestCaseDeclParser::StepsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSteps(this);
}

TestCaseDeclParser::StepsContext* TestCaseDeclParser::steps() {
  StepsContext *_localctx = _tracker.createInstance<StepsContext>(_ctx, getState());
  enterRule(_localctx, 8, TestCaseDeclParser::RuleSteps);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimerID: {
        enterOuterAlt(_localctx, 1);
        setState(190);
        timerDecl();
        setState(191);
        steps();
        break;
      }

      case TestCaseDeclParser::MessageID: {
        enterOuterAlt(_localctx, 2);
        setState(193);
        messageDecl();
        setState(194);
        steps();
        break;
      }

      case TestCaseDeclParser::CheckID: {
        enterOuterAlt(_localctx, 3);
        setState(196);
        checkDecl();
        setState(197);
        steps();
        break;
      }

      case TestCaseDeclParser::AltID: {
        enterOuterAlt(_localctx, 4);
        setState(199);
        altDecl();
        setState(200);
        steps();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::ThisID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 5);
        setState(202);
        idStatement();
        setState(203);
        match(TestCaseDeclParser::SEMI);
        setState(204);
        steps();
        break;
      }

      case TestCaseDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 6);

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

//----------------- IdStatementContext ------------------------------------------------------------------

TestCaseDeclParser::IdStatementContext::IdStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::ThisDeclContext* TestCaseDeclParser::IdStatementContext::thisDecl() {
  return getRuleContext<TestCaseDeclParser::ThisDeclContext>(0);
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::IdStatementContext::idPath() {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(0);
}

TestCaseDeclParser::AssignmentDefContext* TestCaseDeclParser::IdStatementContext::assignmentDef() {
  return getRuleContext<TestCaseDeclParser::AssignmentDefContext>(0);
}


size_t TestCaseDeclParser::IdStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleIdStatement;
}

void TestCaseDeclParser::IdStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdStatement(this);
}

void TestCaseDeclParser::IdStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdStatement(this);
}

TestCaseDeclParser::IdStatementContext* TestCaseDeclParser::idStatement() {
  IdStatementContext *_localctx = _tracker.createInstance<IdStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, TestCaseDeclParser::RuleIdStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ThisID: {
        enterOuterAlt(_localctx, 1);
        setState(209);
        thisDecl();
        setState(210);
        idPath();
        setState(213);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::ASSIGN: {
            setState(211);
            assignmentDef();
            break;
          }

          case TestCaseDeclParser::SEMI: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(215);
        idPath();
        setState(218);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::ASSIGN: {
            setState(216);
            assignmentDef();
            break;
          }

          case TestCaseDeclParser::SEMI: {
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
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentDefContext ------------------------------------------------------------------

TestCaseDeclParser::AssignmentDefContext::AssignmentDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::AssignmentDefContext::ASSIGN() {
  return getToken(TestCaseDeclParser::ASSIGN, 0);
}

tree::TerminalNode* TestCaseDeclParser::AssignmentDefContext::REAL() {
  return getToken(TestCaseDeclParser::REAL, 0);
}

tree::TerminalNode* TestCaseDeclParser::AssignmentDefContext::STRING() {
  return getToken(TestCaseDeclParser::STRING, 0);
}

tree::TerminalNode* TestCaseDeclParser::AssignmentDefContext::INT() {
  return getToken(TestCaseDeclParser::INT, 0);
}

tree::TerminalNode* TestCaseDeclParser::AssignmentDefContext::TrueID() {
  return getToken(TestCaseDeclParser::TrueID, 0);
}

tree::TerminalNode* TestCaseDeclParser::AssignmentDefContext::FalseID() {
  return getToken(TestCaseDeclParser::FalseID, 0);
}


size_t TestCaseDeclParser::AssignmentDefContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAssignmentDef;
}

void TestCaseDeclParser::AssignmentDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentDef(this);
}

void TestCaseDeclParser::AssignmentDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentDef(this);
}

TestCaseDeclParser::AssignmentDefContext* TestCaseDeclParser::assignmentDef() {
  AssignmentDefContext *_localctx = _tracker.createInstance<AssignmentDefContext>(_ctx, getState());
  enterRule(_localctx, 12, TestCaseDeclParser::RuleAssignmentDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(TestCaseDeclParser::ASSIGN);
    setState(223);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TrueID)
      | (1ULL << TestCaseDeclParser::FalseID)
      | (1ULL << TestCaseDeclParser::INT)
      | (1ULL << TestCaseDeclParser::REAL)
      | (1ULL << TestCaseDeclParser::STRING))) != 0))) {
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

//----------------- MessageDeclContext ------------------------------------------------------------------

TestCaseDeclParser::MessageDeclContext::MessageDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::MessageDeclContext::MessageID() {
  return getToken(TestCaseDeclParser::MessageID, 0);
}

tree::TerminalNode* TestCaseDeclParser::MessageDeclContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

std::vector<TestCaseDeclParser::IdPathContext *> TestCaseDeclParser::MessageDeclContext::idPath() {
  return getRuleContexts<TestCaseDeclParser::IdPathContext>();
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::MessageDeclContext::idPath(size_t i) {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(i);
}

tree::TerminalNode* TestCaseDeclParser::MessageDeclContext::RightArrow() {
  return getToken(TestCaseDeclParser::RightArrow, 0);
}

tree::TerminalNode* TestCaseDeclParser::MessageDeclContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}

tree::TerminalNode* TestCaseDeclParser::MessageDeclContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

TestCaseDeclParser::FunctionCallContext* TestCaseDeclParser::MessageDeclContext::functionCall() {
  return getRuleContext<TestCaseDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::MessageDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::MessageDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleMessageDecl;
}

void TestCaseDeclParser::MessageDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageDecl(this);
}

void TestCaseDeclParser::MessageDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageDecl(this);
}

TestCaseDeclParser::MessageDeclContext* TestCaseDeclParser::messageDecl() {
  MessageDeclContext *_localctx = _tracker.createInstance<MessageDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, TestCaseDeclParser::RuleMessageDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(TestCaseDeclParser::MessageID);
    setState(226);
    match(TestCaseDeclParser::LPAREN);
    setState(227);
    idPath();
    setState(228);
    match(TestCaseDeclParser::RightArrow);
    setState(229);
    idPath();
    setState(230);
    match(TestCaseDeclParser::RPAREN);
    setState(231);
    match(TestCaseDeclParser::COLON);
    setState(232);
    functionCall();
    setState(233);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckDeclContext ------------------------------------------------------------------

TestCaseDeclParser::CheckDeclContext::CheckDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclContext::CheckID() {
  return getToken(TestCaseDeclParser::CheckID, 0);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

std::vector<TestCaseDeclParser::IdPathContext *> TestCaseDeclParser::CheckDeclContext::idPath() {
  return getRuleContexts<TestCaseDeclParser::IdPathContext>();
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::CheckDeclContext::idPath(size_t i) {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(i);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclContext::RightArrow() {
  return getToken(TestCaseDeclParser::RightArrow, 0);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

TestCaseDeclParser::FunctionCall2Context* TestCaseDeclParser::CheckDeclContext::functionCall2() {
  return getRuleContext<TestCaseDeclParser::FunctionCall2Context>(0);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::CheckDeclContext::COMMA() {
  return getTokens(TestCaseDeclParser::COMMA);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclContext::COMMA(size_t i) {
  return getToken(TestCaseDeclParser::COMMA, i);
}

TestCaseDeclParser::TimeOutDeclContext* TestCaseDeclParser::CheckDeclContext::timeOutDecl() {
  return getRuleContext<TestCaseDeclParser::TimeOutDeclContext>(0);
}

TestCaseDeclParser::AccuracyDeclContext* TestCaseDeclParser::CheckDeclContext::accuracyDecl() {
  return getRuleContext<TestCaseDeclParser::AccuracyDeclContext>(0);
}


size_t TestCaseDeclParser::CheckDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleCheckDecl;
}

void TestCaseDeclParser::CheckDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckDecl(this);
}

void TestCaseDeclParser::CheckDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckDecl(this);
}

TestCaseDeclParser::CheckDeclContext* TestCaseDeclParser::checkDecl() {
  CheckDeclContext *_localctx = _tracker.createInstance<CheckDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, TestCaseDeclParser::RuleCheckDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(TestCaseDeclParser::CheckID);
    setState(236);
    match(TestCaseDeclParser::LPAREN);
    setState(237);
    idPath();
    setState(238);
    match(TestCaseDeclParser::RightArrow);
    setState(239);
    idPath();
    setState(240);
    match(TestCaseDeclParser::RPAREN);
    setState(241);
    match(TestCaseDeclParser::COLON);
    setState(242);
    functionCall2();
    setState(258);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(243);
      match(TestCaseDeclParser::COMMA);
      setState(244);
      timeOutDecl();
      setState(248);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TestCaseDeclParser::COMMA: {
          setState(245);
          match(TestCaseDeclParser::COMMA);
          setState(246);
          accuracyDecl();
          break;
        }

        case TestCaseDeclParser::SEMI: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 2: {
      setState(250);
      match(TestCaseDeclParser::COMMA);
      setState(251);
      accuracyDecl();
      setState(255);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TestCaseDeclParser::COMMA: {
          setState(252);
          match(TestCaseDeclParser::COMMA);
          setState(253);
          timeOutDecl();
          break;
        }

        case TestCaseDeclParser::SEMI: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 3: {
      break;
    }

    }
    setState(260);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimerDeclContext ------------------------------------------------------------------

TestCaseDeclParser::TimerDeclContext::TimerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::TimerID() {
  return getToken(TestCaseDeclParser::TimerID, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::AtID() {
  return getToken(TestCaseDeclParser::AtID, 0);
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::TimerDeclContext::idPath() {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::TimerDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::ASSIGN() {
  return getToken(TestCaseDeclParser::ASSIGN, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::REAL() {
  return getToken(TestCaseDeclParser::REAL, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::INT() {
  return getToken(TestCaseDeclParser::INT, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::MilliSekID() {
  return getToken(TestCaseDeclParser::MilliSekID, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimerDeclContext::SekID() {
  return getToken(TestCaseDeclParser::SekID, 0);
}


size_t TestCaseDeclParser::TimerDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleTimerDecl;
}

void TestCaseDeclParser::TimerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimerDecl(this);
}

void TestCaseDeclParser::TimerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimerDecl(this);
}

TestCaseDeclParser::TimerDeclContext* TestCaseDeclParser::timerDecl() {
  TimerDeclContext *_localctx = _tracker.createInstance<TimerDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, TestCaseDeclParser::RuleTimerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(TestCaseDeclParser::TimerID);
    setState(263);
    match(TestCaseDeclParser::AtID);
    setState(264);
    idPath();
    setState(265);
    contextID();
    setState(266);
    match(TestCaseDeclParser::ASSIGN);
    setState(267);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::INT

    || _la == TestCaseDeclParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(268);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::MilliSekID

    || _la == TestCaseDeclParser::SekID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(269);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeOutDeclContext ------------------------------------------------------------------

TestCaseDeclParser::TimeOutDeclContext::TimeOutDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::TimeOutDeclContext::TimeOutID() {
  return getToken(TestCaseDeclParser::TimeOutID, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimeOutDeclContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimeOutDeclContext::REAL() {
  return getToken(TestCaseDeclParser::REAL, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimeOutDeclContext::INT() {
  return getToken(TestCaseDeclParser::INT, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimeOutDeclContext::MilliSekID() {
  return getToken(TestCaseDeclParser::MilliSekID, 0);
}

tree::TerminalNode* TestCaseDeclParser::TimeOutDeclContext::SekID() {
  return getToken(TestCaseDeclParser::SekID, 0);
}


size_t TestCaseDeclParser::TimeOutDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleTimeOutDecl;
}

void TestCaseDeclParser::TimeOutDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeOutDecl(this);
}

void TestCaseDeclParser::TimeOutDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeOutDecl(this);
}

TestCaseDeclParser::TimeOutDeclContext* TestCaseDeclParser::timeOutDecl() {
  TimeOutDeclContext *_localctx = _tracker.createInstance<TimeOutDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, TestCaseDeclParser::RuleTimeOutDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(TestCaseDeclParser::TimeOutID);
    setState(272);
    match(TestCaseDeclParser::COLON);
    setState(273);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::INT

    || _la == TestCaseDeclParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(274);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::MilliSekID

    || _la == TestCaseDeclParser::SekID)) {
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

//----------------- AccuracyDeclContext ------------------------------------------------------------------

TestCaseDeclParser::AccuracyDeclContext::AccuracyDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::AccuracyDeclContext::AccuracyID() {
  return getToken(TestCaseDeclParser::AccuracyID, 0);
}

tree::TerminalNode* TestCaseDeclParser::AccuracyDeclContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

tree::TerminalNode* TestCaseDeclParser::AccuracyDeclContext::REAL() {
  return getToken(TestCaseDeclParser::REAL, 0);
}

tree::TerminalNode* TestCaseDeclParser::AccuracyDeclContext::INT() {
  return getToken(TestCaseDeclParser::INT, 0);
}


size_t TestCaseDeclParser::AccuracyDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAccuracyDecl;
}

void TestCaseDeclParser::AccuracyDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccuracyDecl(this);
}

void TestCaseDeclParser::AccuracyDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccuracyDecl(this);
}

TestCaseDeclParser::AccuracyDeclContext* TestCaseDeclParser::accuracyDecl() {
  AccuracyDeclContext *_localctx = _tracker.createInstance<AccuracyDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, TestCaseDeclParser::RuleAccuracyDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    match(TestCaseDeclParser::AccuracyID);
    setState(277);
    match(TestCaseDeclParser::COLON);
    setState(278);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::INT

    || _la == TestCaseDeclParser::REAL)) {
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

//----------------- AltDeclContext ------------------------------------------------------------------

TestCaseDeclParser::AltDeclContext::AltDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::AltDeclContext::AltID() {
  return getToken(TestCaseDeclParser::AltID, 0);
}

tree::TerminalNode* TestCaseDeclParser::AltDeclContext::LBRACE() {
  return getToken(TestCaseDeclParser::LBRACE, 0);
}

TestCaseDeclParser::AltBodyOptionalContext* TestCaseDeclParser::AltDeclContext::altBodyOptional() {
  return getRuleContext<TestCaseDeclParser::AltBodyOptionalContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::AltDeclContext::RBRACE() {
  return getToken(TestCaseDeclParser::RBRACE, 0);
}


size_t TestCaseDeclParser::AltDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAltDecl;
}

void TestCaseDeclParser::AltDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltDecl(this);
}

void TestCaseDeclParser::AltDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltDecl(this);
}

TestCaseDeclParser::AltDeclContext* TestCaseDeclParser::altDecl() {
  AltDeclContext *_localctx = _tracker.createInstance<AltDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, TestCaseDeclParser::RuleAltDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(TestCaseDeclParser::AltID);
    setState(281);
    match(TestCaseDeclParser::LBRACE);
    setState(282);
    altBodyOptional();
    setState(283);
    match(TestCaseDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AltBodyContext ------------------------------------------------------------------

TestCaseDeclParser::AltBodyContext::AltBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::AltBodyContext::LBRACKET() {
  return getToken(TestCaseDeclParser::LBRACKET, 0);
}

tree::TerminalNode* TestCaseDeclParser::AltBodyContext::RBRACKET() {
  return getToken(TestCaseDeclParser::RBRACKET, 0);
}

tree::TerminalNode* TestCaseDeclParser::AltBodyContext::LBRACE() {
  return getToken(TestCaseDeclParser::LBRACE, 0);
}

TestCaseDeclParser::StepsContext* TestCaseDeclParser::AltBodyContext::steps() {
  return getRuleContext<TestCaseDeclParser::StepsContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::AltBodyContext::RBRACE() {
  return getToken(TestCaseDeclParser::RBRACE, 0);
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::AltBodyContext::expression() {
  return getRuleContext<TestCaseDeclParser::ExpressionContext>(0);
}

TestCaseDeclParser::CheckDeclContext* TestCaseDeclParser::AltBodyContext::checkDecl() {
  return getRuleContext<TestCaseDeclParser::CheckDeclContext>(0);
}


size_t TestCaseDeclParser::AltBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAltBody;
}

void TestCaseDeclParser::AltBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltBody(this);
}

void TestCaseDeclParser::AltBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltBody(this);
}

TestCaseDeclParser::AltBodyContext* TestCaseDeclParser::altBody() {
  AltBodyContext *_localctx = _tracker.createInstance<AltBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, TestCaseDeclParser::RuleAltBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    match(TestCaseDeclParser::LBRACKET);
    setState(288);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::ThisID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::NotIdSymbol:
      case TestCaseDeclParser::NotIdWord:
      case TestCaseDeclParser::TrueID:
      case TestCaseDeclParser::FalseID:
      case TestCaseDeclParser::INT:
      case TestCaseDeclParser::REAL:
      case TestCaseDeclParser::STRING:
      case TestCaseDeclParser::ID:
      case TestCaseDeclParser::LPAREN:
      case TestCaseDeclParser::MINUS: {
        setState(286);
        expression();
        break;
      }

      case TestCaseDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(290);
    match(TestCaseDeclParser::RBRACKET);
    setState(291);
    match(TestCaseDeclParser::LBRACE);
    setState(294);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(292);
      checkDecl();
      break;
    }

    case 2: {
      break;
    }

    }
    setState(296);
    steps();
    setState(297);
    match(TestCaseDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AltBodyOptionalContext ------------------------------------------------------------------

TestCaseDeclParser::AltBodyOptionalContext::AltBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::AltBodyContext* TestCaseDeclParser::AltBodyOptionalContext::altBody() {
  return getRuleContext<TestCaseDeclParser::AltBodyContext>(0);
}

TestCaseDeclParser::AltBodyOptionalContext* TestCaseDeclParser::AltBodyOptionalContext::altBodyOptional() {
  return getRuleContext<TestCaseDeclParser::AltBodyOptionalContext>(0);
}


size_t TestCaseDeclParser::AltBodyOptionalContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAltBodyOptional;
}

void TestCaseDeclParser::AltBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltBodyOptional(this);
}

void TestCaseDeclParser::AltBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltBodyOptional(this);
}

TestCaseDeclParser::AltBodyOptionalContext* TestCaseDeclParser::altBodyOptional() {
  AltBodyOptionalContext *_localctx = _tracker.createInstance<AltBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 28, TestCaseDeclParser::RuleAltBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(299);
        altBody();
        setState(300);
        altBodyOptional();
        break;
      }

      case TestCaseDeclParser::RBRACE: {
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

//----------------- UuidDeclContext ------------------------------------------------------------------

TestCaseDeclParser::UuidDeclContext::UuidDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::UuidDeclContext::UuidID() {
  return getToken(TestCaseDeclParser::UuidID, 0);
}

tree::TerminalNode* TestCaseDeclParser::UuidDeclContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

tree::TerminalNode* TestCaseDeclParser::UuidDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

tree::TerminalNode* TestCaseDeclParser::UuidDeclContext::STRING() {
  return getToken(TestCaseDeclParser::STRING, 0);
}


size_t TestCaseDeclParser::UuidDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleUuidDecl;
}

void TestCaseDeclParser::UuidDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUuidDecl(this);
}

void TestCaseDeclParser::UuidDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUuidDecl(this);
}

TestCaseDeclParser::UuidDeclContext* TestCaseDeclParser::uuidDecl() {
  UuidDeclContext *_localctx = _tracker.createInstance<UuidDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, TestCaseDeclParser::RuleUuidDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    match(TestCaseDeclParser::UuidID);
    setState(306);
    match(TestCaseDeclParser::COLON);
    setState(307);
    dynamic_cast<UuidDeclContext *>(_localctx)->val = match(TestCaseDeclParser::STRING);
    setState(308);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnabledDeclContext ------------------------------------------------------------------

TestCaseDeclParser::EnabledDeclContext::EnabledDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::EnabledDeclContext::EnabledID() {
  return getToken(TestCaseDeclParser::EnabledID, 0);
}

tree::TerminalNode* TestCaseDeclParser::EnabledDeclContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

tree::TerminalNode* TestCaseDeclParser::EnabledDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

tree::TerminalNode* TestCaseDeclParser::EnabledDeclContext::TrueID() {
  return getToken(TestCaseDeclParser::TrueID, 0);
}

tree::TerminalNode* TestCaseDeclParser::EnabledDeclContext::FalseID() {
  return getToken(TestCaseDeclParser::FalseID, 0);
}


size_t TestCaseDeclParser::EnabledDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleEnabledDecl;
}

void TestCaseDeclParser::EnabledDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnabledDecl(this);
}

void TestCaseDeclParser::EnabledDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnabledDecl(this);
}

TestCaseDeclParser::EnabledDeclContext* TestCaseDeclParser::enabledDecl() {
  EnabledDeclContext *_localctx = _tracker.createInstance<EnabledDeclContext>(_ctx, getState());
  enterRule(_localctx, 32, TestCaseDeclParser::RuleEnabledDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(TestCaseDeclParser::EnabledID);
    setState(311);
    match(TestCaseDeclParser::COLON);
    setState(312);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::TrueID

    || _la == TestCaseDeclParser::FalseID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(313);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextIDContext ------------------------------------------------------------------

TestCaseDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::ID() {
  return getToken(TestCaseDeclParser::ID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::NameID() {
  return getToken(TestCaseDeclParser::NameID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::UuidID() {
  return getToken(TestCaseDeclParser::UuidID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::LabelID() {
  return getToken(TestCaseDeclParser::LabelID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::EnabledID() {
  return getToken(TestCaseDeclParser::EnabledID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::TypeID() {
  return getToken(TestCaseDeclParser::TypeID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::MessageTrigger() {
  return getToken(TestCaseDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::TriggerID() {
  return getToken(TestCaseDeclParser::TriggerID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::AttributeID() {
  return getToken(TestCaseDeclParser::AttributeID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::SignalID() {
  return getToken(TestCaseDeclParser::SignalID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::PortID() {
  return getToken(TestCaseDeclParser::PortID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::ImportID() {
  return getToken(TestCaseDeclParser::ImportID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::FromID() {
  return getToken(TestCaseDeclParser::FromID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::ToID() {
  return getToken(TestCaseDeclParser::ToID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::SendID() {
  return getToken(TestCaseDeclParser::SendID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::AsID() {
  return getToken(TestCaseDeclParser::AsID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::TimeOutID() {
  return getToken(TestCaseDeclParser::TimeOutID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::ComponentID() {
  return getToken(TestCaseDeclParser::ComponentID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ContextIDContext::DeclarationID() {
  return getToken(TestCaseDeclParser::DeclarationID, 0);
}


size_t TestCaseDeclParser::ContextIDContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleContextID;
}

void TestCaseDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void TestCaseDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 34, TestCaseDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(333);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(315);
        match(TestCaseDeclParser::ID);
        break;
      }

      case TestCaseDeclParser::NameID: {
        enterOuterAlt(_localctx, 2);
        setState(316);
        match(TestCaseDeclParser::NameID);
        break;
      }

      case TestCaseDeclParser::UuidID: {
        enterOuterAlt(_localctx, 3);
        setState(317);
        match(TestCaseDeclParser::UuidID);
        break;
      }

      case TestCaseDeclParser::LabelID: {
        enterOuterAlt(_localctx, 4);
        setState(318);
        match(TestCaseDeclParser::LabelID);
        break;
      }

      case TestCaseDeclParser::EnabledID: {
        enterOuterAlt(_localctx, 5);
        setState(319);
        match(TestCaseDeclParser::EnabledID);
        break;
      }

      case TestCaseDeclParser::TypeID: {
        enterOuterAlt(_localctx, 6);
        setState(320);
        match(TestCaseDeclParser::TypeID);
        break;
      }

      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger: {
        enterOuterAlt(_localctx, 7);
        setState(321);
        _la = _input->LA(1);
        if (!(_la == TestCaseDeclParser::TriggerID

        || _la == TestCaseDeclParser::MessageTrigger)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case TestCaseDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 8);
        setState(322);
        match(TestCaseDeclParser::AttributeID);
        break;
      }

      case TestCaseDeclParser::SignalID: {
        enterOuterAlt(_localctx, 9);
        setState(323);
        match(TestCaseDeclParser::SignalID);
        break;
      }

      case TestCaseDeclParser::PortID: {
        enterOuterAlt(_localctx, 10);
        setState(324);
        match(TestCaseDeclParser::PortID);
        break;
      }

      case TestCaseDeclParser::ImportID: {
        enterOuterAlt(_localctx, 11);
        setState(325);
        match(TestCaseDeclParser::ImportID);
        break;
      }

      case TestCaseDeclParser::FromID: {
        enterOuterAlt(_localctx, 12);
        setState(326);
        match(TestCaseDeclParser::FromID);
        break;
      }

      case TestCaseDeclParser::ToID: {
        enterOuterAlt(_localctx, 13);
        setState(327);
        match(TestCaseDeclParser::ToID);
        break;
      }

      case TestCaseDeclParser::SendID: {
        enterOuterAlt(_localctx, 14);
        setState(328);
        match(TestCaseDeclParser::SendID);
        break;
      }

      case TestCaseDeclParser::AsID: {
        enterOuterAlt(_localctx, 15);
        setState(329);
        match(TestCaseDeclParser::AsID);
        break;
      }

      case TestCaseDeclParser::TimeOutID: {
        enterOuterAlt(_localctx, 16);
        setState(330);
        match(TestCaseDeclParser::TimeOutID);
        break;
      }

      case TestCaseDeclParser::ComponentID: {
        enterOuterAlt(_localctx, 17);
        setState(331);
        match(TestCaseDeclParser::ComponentID);
        break;
      }

      case TestCaseDeclParser::DeclarationID: {
        enterOuterAlt(_localctx, 18);
        setState(332);
        match(TestCaseDeclParser::DeclarationID);
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

//----------------- FunctionCallContext ------------------------------------------------------------------

TestCaseDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::FunctionCallContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

TestCaseDeclParser::FunctionCallBodyContext* TestCaseDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<TestCaseDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::FunctionCallContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}


size_t TestCaseDeclParser::FunctionCallContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleFunctionCall;
}

void TestCaseDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void TestCaseDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

TestCaseDeclParser::FunctionCallContext* TestCaseDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 36, TestCaseDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    idPath();
    setState(336);
    match(TestCaseDeclParser::LPAREN);
    setState(337);
    functionCallBody();
    setState(338);
    match(TestCaseDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCall2Context ------------------------------------------------------------------

TestCaseDeclParser::FunctionCall2Context::FunctionCall2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::FunctionCall2Context::idPath() {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::FunctionCall2Context::LBRACKET() {
  return getToken(TestCaseDeclParser::LBRACKET, 0);
}

TestCaseDeclParser::FunctionCallBodyContext* TestCaseDeclParser::FunctionCall2Context::functionCallBody() {
  return getRuleContext<TestCaseDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::FunctionCall2Context::RBRACKET() {
  return getToken(TestCaseDeclParser::RBRACKET, 0);
}


size_t TestCaseDeclParser::FunctionCall2Context::getRuleIndex() const {
  return TestCaseDeclParser::RuleFunctionCall2;
}

void TestCaseDeclParser::FunctionCall2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall2(this);
}

void TestCaseDeclParser::FunctionCall2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall2(this);
}

TestCaseDeclParser::FunctionCall2Context* TestCaseDeclParser::functionCall2() {
  FunctionCall2Context *_localctx = _tracker.createInstance<FunctionCall2Context>(_ctx, getState());
  enterRule(_localctx, 38, TestCaseDeclParser::RuleFunctionCall2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    idPath();
    setState(341);
    match(TestCaseDeclParser::LBRACKET);
    setState(342);
    functionCallBody();
    setState(343);
    match(TestCaseDeclParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentIdPathContext ------------------------------------------------------------------

TestCaseDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestCaseDeclParser::ContextIDContext *> TestCaseDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<TestCaseDeclParser::ContextIDContext>();
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(TestCaseDeclParser::DOT);
}

tree::TerminalNode* TestCaseDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(TestCaseDeclParser::DOT, i);
}


size_t TestCaseDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleComponentIdPath;
}

void TestCaseDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void TestCaseDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

TestCaseDeclParser::ComponentIdPathContext* TestCaseDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 40, TestCaseDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    contextID();
    setState(350);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::DOT) {
      setState(346);
      match(TestCaseDeclParser::DOT);
      setState(347);
      contextID();
      setState(352);
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

TestCaseDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestCaseDeclParser::ContextIDContext *> TestCaseDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<TestCaseDeclParser::ContextIDContext>();
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::SignalIdPathContext::DOT() {
  return getTokens(TestCaseDeclParser::DOT);
}

tree::TerminalNode* TestCaseDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(TestCaseDeclParser::DOT, i);
}


size_t TestCaseDeclParser::SignalIdPathContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSignalIdPath;
}

void TestCaseDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void TestCaseDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

TestCaseDeclParser::SignalIdPathContext* TestCaseDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 42, TestCaseDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    contextID();
    setState(358);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::DOT) {
      setState(354);
      match(TestCaseDeclParser::DOT);
      setState(355);
      contextID();
      setState(360);
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

TestCaseDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::AttributeNameContext* TestCaseDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<TestCaseDeclParser::AttributeNameContext>(0);
}

std::vector<TestCaseDeclParser::ContextIDContext *> TestCaseDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<TestCaseDeclParser::ContextIDContext>();
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(TestCaseDeclParser::DOT);
}

tree::TerminalNode* TestCaseDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(TestCaseDeclParser::DOT, i);
}


size_t TestCaseDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAttributeIdPath;
}

void TestCaseDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void TestCaseDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

TestCaseDeclParser::AttributeIdPathContext* TestCaseDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 44, TestCaseDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(370);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(361);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(362);
      contextID();
      setState(367);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TestCaseDeclParser::DOT) {
        setState(363);
        match(TestCaseDeclParser::DOT);
        setState(364);
        contextID();
        setState(369);
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

TestCaseDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::SignalIdPathContext* TestCaseDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<TestCaseDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::SignalSendContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

TestCaseDeclParser::FunctionCallBodyContext* TestCaseDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<TestCaseDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::SignalSendContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}


size_t TestCaseDeclParser::SignalSendContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSignalSend;
}

void TestCaseDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void TestCaseDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

TestCaseDeclParser::SignalSendContext* TestCaseDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 46, TestCaseDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    signalIdPath();
    setState(373);
    match(TestCaseDeclParser::LPAREN);
    setState(374);
    functionCallBody();
    setState(375);
    match(TestCaseDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

TestCaseDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestCaseDeclParser::TypeDefDeclContext *> TestCaseDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<TestCaseDeclParser::TypeDefDeclContext>();
}

TestCaseDeclParser::TypeDefDeclContext* TestCaseDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<TestCaseDeclParser::TypeDefDeclContext>(i);
}

std::vector<TestCaseDeclParser::AttributeDeclContext *> TestCaseDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<TestCaseDeclParser::AttributeDeclContext>();
}

TestCaseDeclParser::AttributeDeclContext* TestCaseDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<TestCaseDeclParser::AttributeDeclContext>(i);
}

std::vector<TestCaseDeclParser::SignalDeclContext *> TestCaseDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<TestCaseDeclParser::SignalDeclContext>();
}

TestCaseDeclParser::SignalDeclContext* TestCaseDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<TestCaseDeclParser::SignalDeclContext>(i);
}


size_t TestCaseDeclParser::CommonDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleCommonDecl;
}

void TestCaseDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void TestCaseDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

TestCaseDeclParser::CommonDeclContext* TestCaseDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 48, TestCaseDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TypeID)
      | (1ULL << TestCaseDeclParser::AttributeID)
      | (1ULL << TestCaseDeclParser::SignalID))) != 0)) {
      setState(380);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TestCaseDeclParser::TypeID: {
          setState(377);
          typeDefDecl();
          break;
        }

        case TestCaseDeclParser::AttributeID: {
          setState(378);
          attributeDecl();
          break;
        }

        case TestCaseDeclParser::SignalID: {
          setState(379);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(384);
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

TestCaseDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::ImportPathBodyContext* TestCaseDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<TestCaseDeclParser::ImportPathBodyContext>(0);
}

TestCaseDeclParser::ImportPathDeclContext* TestCaseDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<TestCaseDeclParser::ImportPathDeclContext>(0);
}


size_t TestCaseDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleImportPathDecl;
}

void TestCaseDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void TestCaseDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

TestCaseDeclParser::ImportPathDeclContext* TestCaseDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 50, TestCaseDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(389);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ImportID: {
        enterOuterAlt(_localctx, 1);
        setState(385);
        importPathBody();
        setState(386);
        importPathDecl();
        break;
      }

      case TestCaseDeclParser::TestCaseID: {
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

TestCaseDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(TestCaseDeclParser::ImportID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(TestCaseDeclParser::LESSTHAN, 0);
}

TestCaseDeclParser::ImportFileBodyContext* TestCaseDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<TestCaseDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(TestCaseDeclParser::GREATERTHAN, 0);
}

TestCaseDeclParser::ImportAsContext* TestCaseDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<TestCaseDeclParser::ImportAsContext>(0);
}


size_t TestCaseDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleImportPathBody;
}

void TestCaseDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void TestCaseDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

TestCaseDeclParser::ImportPathBodyContext* TestCaseDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 52, TestCaseDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    match(TestCaseDeclParser::ImportID);
    setState(392);
    match(TestCaseDeclParser::LESSTHAN);
    setState(393);
    importFileBody();
    setState(394);
    match(TestCaseDeclParser::GREATERTHAN);
    setState(395);
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

TestCaseDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestCaseDeclParser::ContextIDContext *> TestCaseDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<TestCaseDeclParser::ContextIDContext>();
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TestCaseDeclParser::ImportFileBodyContext::DOT() {
  return getToken(TestCaseDeclParser::DOT, 0);
}

tree::TerminalNode* TestCaseDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(TestCaseDeclParser::RANGE, 0);
}

tree::TerminalNode* TestCaseDeclParser::ImportFileBodyContext::DIV() {
  return getToken(TestCaseDeclParser::DIV, 0);
}

TestCaseDeclParser::ImportFileBodyContext* TestCaseDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<TestCaseDeclParser::ImportFileBodyContext>(0);
}


size_t TestCaseDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleImportFileBody;
}

void TestCaseDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void TestCaseDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

TestCaseDeclParser::ImportFileBodyContext* TestCaseDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 54, TestCaseDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(408);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(397);
      contextID();
      setState(398);
      match(TestCaseDeclParser::DOT);
      setState(399);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(401);
      match(TestCaseDeclParser::RANGE);
      setState(402);
      match(TestCaseDeclParser::DIV);
      setState(403);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(404);
      contextID();
      setState(405);
      match(TestCaseDeclParser::DIV);
      setState(406);
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

TestCaseDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ImportAsContext::AsID() {
  return getToken(TestCaseDeclParser::AsID, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::ImportAsContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}


size_t TestCaseDeclParser::ImportAsContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleImportAs;
}

void TestCaseDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void TestCaseDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

TestCaseDeclParser::ImportAsContext* TestCaseDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 56, TestCaseDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(413);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(410);
        match(TestCaseDeclParser::AsID);
        setState(411);
        contextID();
        break;
      }

      case TestCaseDeclParser::TestCaseID:
      case TestCaseDeclParser::ImportID: {
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

TestCaseDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(TestCaseDeclParser::TypeID, 0);
}

TestCaseDeclParser::TypeDeclContext* TestCaseDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<TestCaseDeclParser::TypeDeclContext>(0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleTypeDefDecl;
}

void TestCaseDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void TestCaseDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

TestCaseDeclParser::TypeDefDeclContext* TestCaseDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 58, TestCaseDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    match(TestCaseDeclParser::TypeID);
    setState(416);
    typeDecl();
    setState(417);
    contextID();
    setState(418);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

TestCaseDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::IntTypeDeclContext* TestCaseDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<TestCaseDeclParser::IntTypeDeclContext>(0);
}

TestCaseDeclParser::RealTypeDeclContext* TestCaseDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<TestCaseDeclParser::RealTypeDeclContext>(0);
}

TestCaseDeclParser::EnumTypeDeclContext* TestCaseDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<TestCaseDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::TypeDeclContext::BoolID() {
  return getToken(TestCaseDeclParser::BoolID, 0);
}

tree::TerminalNode* TestCaseDeclParser::TypeDeclContext::StringID() {
  return getToken(TestCaseDeclParser::StringID, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}


size_t TestCaseDeclParser::TypeDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleTypeDecl;
}

void TestCaseDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void TestCaseDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

TestCaseDeclParser::TypeDeclContext* TestCaseDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 60, TestCaseDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(426);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(420);
        intTypeDecl();
        break;
      }

      case TestCaseDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(421);
        realTypeDecl();
        break;
      }

      case TestCaseDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(422);
        enumTypeDecl();
        break;
      }

      case TestCaseDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(423);
        match(TestCaseDeclParser::BoolID);
        break;
      }

      case TestCaseDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(424);
        match(TestCaseDeclParser::StringID);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(425);
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

TestCaseDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::IntTypeDeclContext::IntID() {
  return getToken(TestCaseDeclParser::IntID, 0);
}

tree::TerminalNode* TestCaseDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::IntTypeDeclContext::INT() {
  return getTokens(TestCaseDeclParser::INT);
}

tree::TerminalNode* TestCaseDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(TestCaseDeclParser::INT, i);
}

tree::TerminalNode* TestCaseDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(TestCaseDeclParser::RANGE, 0);
}

tree::TerminalNode* TestCaseDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}


size_t TestCaseDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleIntTypeDecl;
}

void TestCaseDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void TestCaseDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

TestCaseDeclParser::IntTypeDeclContext* TestCaseDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 62, TestCaseDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(TestCaseDeclParser::IntID);
    setState(435);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LPAREN: {
        setState(429);
        match(TestCaseDeclParser::LPAREN);
        setState(430);
        match(TestCaseDeclParser::INT);
        setState(431);
        match(TestCaseDeclParser::RANGE);
        setState(432);
        match(TestCaseDeclParser::INT);
        setState(433);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
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

TestCaseDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::RealTypeDeclContext::RealID() {
  return getToken(TestCaseDeclParser::RealID, 0);
}

tree::TerminalNode* TestCaseDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(TestCaseDeclParser::REAL);
}

tree::TerminalNode* TestCaseDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(TestCaseDeclParser::REAL, i);
}

tree::TerminalNode* TestCaseDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(TestCaseDeclParser::RANGE, 0);
}

tree::TerminalNode* TestCaseDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}


size_t TestCaseDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleRealTypeDecl;
}

void TestCaseDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void TestCaseDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

TestCaseDeclParser::RealTypeDeclContext* TestCaseDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 64, TestCaseDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(TestCaseDeclParser::RealID);
    setState(444);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LPAREN: {
        setState(438);
        match(TestCaseDeclParser::LPAREN);
        setState(439);
        match(TestCaseDeclParser::REAL);
        setState(440);
        match(TestCaseDeclParser::RANGE);
        setState(441);
        match(TestCaseDeclParser::REAL);
        setState(442);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
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

TestCaseDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(TestCaseDeclParser::EnumID, 0);
}

tree::TerminalNode* TestCaseDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

std::vector<TestCaseDeclParser::ContextIDContext *> TestCaseDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<TestCaseDeclParser::ContextIDContext>();
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TestCaseDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(TestCaseDeclParser::COMMA);
}

tree::TerminalNode* TestCaseDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(TestCaseDeclParser::COMMA, i);
}


size_t TestCaseDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleEnumTypeDecl;
}

void TestCaseDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void TestCaseDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

TestCaseDeclParser::EnumTypeDeclContext* TestCaseDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, TestCaseDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    match(TestCaseDeclParser::EnumID);
    setState(447);
    match(TestCaseDeclParser::LPAREN);
    setState(448);
    contextID();
    setState(453);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::COMMA) {
      setState(449);
      match(TestCaseDeclParser::COMMA);
      setState(450);
      contextID();
      setState(455);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(456);
    match(TestCaseDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

TestCaseDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(TestCaseDeclParser::AttributeID, 0);
}

TestCaseDeclParser::TypeDeclContext* TestCaseDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<TestCaseDeclParser::TypeDeclContext>(0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::AttributeDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

tree::TerminalNode* TestCaseDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(TestCaseDeclParser::ASSIGN, 0);
}

TestCaseDeclParser::LiteralValueContext* TestCaseDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<TestCaseDeclParser::LiteralValueContext>(0);
}


size_t TestCaseDeclParser::AttributeDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAttributeDecl;
}

void TestCaseDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void TestCaseDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

TestCaseDeclParser::AttributeDeclContext* TestCaseDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 68, TestCaseDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    match(TestCaseDeclParser::AttributeID);
    setState(459);
    typeDecl();
    setState(460);
    contextID();
    setState(463);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TestCaseDeclParser::ASSIGN) {
      setState(461);
      match(TestCaseDeclParser::ASSIGN);
      setState(462);
      literalValue();
    }
    setState(465);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

TestCaseDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::LiteralValueContext::INT() {
  return getToken(TestCaseDeclParser::INT, 0);
}

tree::TerminalNode* TestCaseDeclParser::LiteralValueContext::REAL() {
  return getToken(TestCaseDeclParser::REAL, 0);
}

tree::TerminalNode* TestCaseDeclParser::LiteralValueContext::STRING() {
  return getToken(TestCaseDeclParser::STRING, 0);
}

tree::TerminalNode* TestCaseDeclParser::LiteralValueContext::TrueID() {
  return getToken(TestCaseDeclParser::TrueID, 0);
}

tree::TerminalNode* TestCaseDeclParser::LiteralValueContext::FalseID() {
  return getToken(TestCaseDeclParser::FalseID, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}


size_t TestCaseDeclParser::LiteralValueContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleLiteralValue;
}

void TestCaseDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void TestCaseDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

TestCaseDeclParser::LiteralValueContext* TestCaseDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 70, TestCaseDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(473);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(467);
        match(TestCaseDeclParser::INT);
        break;
      }

      case TestCaseDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(468);
        match(TestCaseDeclParser::REAL);
        break;
      }

      case TestCaseDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(469);
        match(TestCaseDeclParser::STRING);
        break;
      }

      case TestCaseDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(470);
        match(TestCaseDeclParser::TrueID);
        break;
      }

      case TestCaseDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(471);
        match(TestCaseDeclParser::FalseID);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(472);
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

TestCaseDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::TriggerDeclContext* TestCaseDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<TestCaseDeclParser::TriggerDeclContext>(0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}


size_t TestCaseDeclParser::SignalParamNameContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSignalParamName;
}

void TestCaseDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void TestCaseDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

TestCaseDeclParser::SignalParamNameContext* TestCaseDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 72, TestCaseDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    triggerDecl();
    setState(476);
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

TestCaseDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

TestCaseDeclParser::ThisDeclContext* TestCaseDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<TestCaseDeclParser::ThisDeclContext>(0);
}


size_t TestCaseDeclParser::AttributeNameContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAttributeName;
}

void TestCaseDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void TestCaseDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

TestCaseDeclParser::AttributeNameContext* TestCaseDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 74, TestCaseDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ThisID: {
        setState(478);
        thisDecl();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(482);
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

TestCaseDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ToPortNameContext::ToID() {
  return getToken(TestCaseDeclParser::ToID, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}


size_t TestCaseDeclParser::ToPortNameContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleToPortName;
}

void TestCaseDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void TestCaseDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

TestCaseDeclParser::ToPortNameContext* TestCaseDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 76, TestCaseDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(TestCaseDeclParser::ToID);
    setState(485);
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

TestCaseDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::AttributeNameContext* TestCaseDeclParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<TestCaseDeclParser::AttributeNameContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(TestCaseDeclParser::ASSIGN, 0);
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<TestCaseDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAttributeAssignStatement;
}

void TestCaseDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void TestCaseDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

TestCaseDeclParser::AttributeAssignStatementContext* TestCaseDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 78, TestCaseDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    attributeName();
    setState(488);
    match(TestCaseDeclParser::ASSIGN);
    setState(489);
    expression();
    setState(490);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

TestCaseDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::TypeDeclContext* TestCaseDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<TestCaseDeclParser::TypeDeclContext>(0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

tree::TerminalNode* TestCaseDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(TestCaseDeclParser::ASSIGN, 0);
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<TestCaseDeclParser::ExpressionContext>(0);
}


size_t TestCaseDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleLocalAssignStatement;
}

void TestCaseDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void TestCaseDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

TestCaseDeclParser::LocalAssignStatementContext* TestCaseDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, TestCaseDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(492);
    typeDecl();
    setState(493);
    contextID();
    setState(497);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ASSIGN: {
        setState(494);
        match(TestCaseDeclParser::ASSIGN);
        setState(495);
        expression();
        break;
      }

      case TestCaseDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(499);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

TestCaseDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::SendToStatementContext::SendID() {
  return getToken(TestCaseDeclParser::SendID, 0);
}

TestCaseDeclParser::SignalSendContext* TestCaseDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<TestCaseDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::SendToStatementContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

TestCaseDeclParser::ToPortNameContext* TestCaseDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<TestCaseDeclParser::ToPortNameContext>(0);
}


size_t TestCaseDeclParser::SendToStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSendToStatement;
}

void TestCaseDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void TestCaseDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

TestCaseDeclParser::SendToStatementContext* TestCaseDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, TestCaseDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    match(TestCaseDeclParser::SendID);
    setState(502);
    signalSend();
    setState(505);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ToID: {
        setState(503);
        toPortName();
        break;
      }

      case TestCaseDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(507);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

TestCaseDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::AttributeAssignStatementContext* TestCaseDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<TestCaseDeclParser::AttributeAssignStatementContext>(0);
}

TestCaseDeclParser::SendToStatementContext* TestCaseDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<TestCaseDeclParser::SendToStatementContext>(0);
}


size_t TestCaseDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSingleAssignment;
}

void TestCaseDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void TestCaseDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

TestCaseDeclParser::SingleAssignmentContext* TestCaseDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 84, TestCaseDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(511);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(509);
      attributeAssignStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(510);
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

TestCaseDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(TestCaseDeclParser::LBRACE, 0);
}

tree::TerminalNode* TestCaseDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(TestCaseDeclParser::RBRACE, 0);
}

std::vector<TestCaseDeclParser::SingleAssignmentContext *> TestCaseDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<TestCaseDeclParser::SingleAssignmentContext>();
}

TestCaseDeclParser::SingleAssignmentContext* TestCaseDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<TestCaseDeclParser::SingleAssignmentContext>(i);
}


size_t TestCaseDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleMultiAssignment;
}

void TestCaseDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void TestCaseDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

TestCaseDeclParser::MultiAssignmentContext* TestCaseDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 86, TestCaseDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    match(TestCaseDeclParser::LBRACE);
    setState(517);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
      | (1ULL << TestCaseDeclParser::UuidID)
      | (1ULL << TestCaseDeclParser::ComponentID)
      | (1ULL << TestCaseDeclParser::DeclarationID)
      | (1ULL << TestCaseDeclParser::NameID)
      | (1ULL << TestCaseDeclParser::LabelID)
      | (1ULL << TestCaseDeclParser::EnabledID)
      | (1ULL << TestCaseDeclParser::TypeID)
      | (1ULL << TestCaseDeclParser::TriggerID)
      | (1ULL << TestCaseDeclParser::MessageTrigger)
      | (1ULL << TestCaseDeclParser::ThisID)
      | (1ULL << TestCaseDeclParser::AttributeID)
      | (1ULL << TestCaseDeclParser::SignalID)
      | (1ULL << TestCaseDeclParser::PortID)
      | (1ULL << TestCaseDeclParser::ImportID)
      | (1ULL << TestCaseDeclParser::FromID)
      | (1ULL << TestCaseDeclParser::ToID)
      | (1ULL << TestCaseDeclParser::SendID)
      | (1ULL << TestCaseDeclParser::AsID)
      | (1ULL << TestCaseDeclParser::ID))) != 0)) {
      setState(514);
      singleAssignment();
      setState(519);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(520);
    match(TestCaseDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

TestCaseDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::SignalDeclContext::SignalID() {
  return getToken(TestCaseDeclParser::SignalID, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::SignalDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

tree::TerminalNode* TestCaseDeclParser::SignalDeclContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

tree::TerminalNode* TestCaseDeclParser::SignalDeclContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}

std::vector<TestCaseDeclParser::ParamDeclContext *> TestCaseDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<TestCaseDeclParser::ParamDeclContext>();
}

TestCaseDeclParser::ParamDeclContext* TestCaseDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<TestCaseDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::SignalDeclContext::COMMA() {
  return getTokens(TestCaseDeclParser::COMMA);
}

tree::TerminalNode* TestCaseDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(TestCaseDeclParser::COMMA, i);
}


size_t TestCaseDeclParser::SignalDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSignalDecl;
}

void TestCaseDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void TestCaseDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

TestCaseDeclParser::SignalDeclContext* TestCaseDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 88, TestCaseDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    match(TestCaseDeclParser::SignalID);
    setState(523);
    contextID();
    setState(538);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LPAREN: {
        setState(524);
        match(TestCaseDeclParser::LPAREN);
        setState(534);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::TimeOutID:
          case TestCaseDeclParser::UuidID:
          case TestCaseDeclParser::ComponentID:
          case TestCaseDeclParser::DeclarationID:
          case TestCaseDeclParser::NameID:
          case TestCaseDeclParser::LabelID:
          case TestCaseDeclParser::EnabledID:
          case TestCaseDeclParser::TypeID:
          case TestCaseDeclParser::IntID:
          case TestCaseDeclParser::RealID:
          case TestCaseDeclParser::BoolID:
          case TestCaseDeclParser::StringID:
          case TestCaseDeclParser::TriggerID:
          case TestCaseDeclParser::MessageTrigger:
          case TestCaseDeclParser::EnumID:
          case TestCaseDeclParser::AttributeID:
          case TestCaseDeclParser::SignalID:
          case TestCaseDeclParser::PortID:
          case TestCaseDeclParser::ImportID:
          case TestCaseDeclParser::FromID:
          case TestCaseDeclParser::ToID:
          case TestCaseDeclParser::SendID:
          case TestCaseDeclParser::AsID:
          case TestCaseDeclParser::ID: {
            setState(525);
            paramDecl();
            setState(530);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TestCaseDeclParser::COMMA) {
              setState(526);
              match(TestCaseDeclParser::COMMA);
              setState(527);
              paramDecl();
              setState(532);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case TestCaseDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(536);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(540);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

TestCaseDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::TypeDeclContext* TestCaseDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<TestCaseDeclParser::TypeDeclContext>(0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}


size_t TestCaseDeclParser::ParamDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleParamDecl;
}

void TestCaseDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void TestCaseDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

TestCaseDeclParser::ParamDeclContext* TestCaseDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 90, TestCaseDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    typeDecl();
    setState(543);
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

TestCaseDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(TestCaseDeclParser::FunctionID, 0);
}

TestCaseDeclParser::TypeDeclContext* TestCaseDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<TestCaseDeclParser::TypeDeclContext>(0);
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<TestCaseDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

tree::TerminalNode* TestCaseDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}

TestCaseDeclParser::NestedStatementBodyContext* TestCaseDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<TestCaseDeclParser::NestedStatementBodyContext>(0);
}

TestCaseDeclParser::FunctionParametersContext* TestCaseDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<TestCaseDeclParser::FunctionParametersContext>(0);
}


size_t TestCaseDeclParser::FunctionDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleFunctionDecl;
}

void TestCaseDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void TestCaseDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

TestCaseDeclParser::FunctionDeclContext* TestCaseDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 92, TestCaseDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(545);
    match(TestCaseDeclParser::FunctionID);
    setState(546);
    typeDecl();
    setState(547);
    idPath();
    setState(548);
    match(TestCaseDeclParser::LPAREN);
    setState(551);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::IntID:
      case TestCaseDeclParser::RealID:
      case TestCaseDeclParser::BoolID:
      case TestCaseDeclParser::StringID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::EnumID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::ID: {
        setState(549);
        functionParameters();
        break;
      }

      case TestCaseDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(553);
    match(TestCaseDeclParser::RPAREN);
    setState(554);
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

TestCaseDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestCaseDeclParser::ParamDeclContext *> TestCaseDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<TestCaseDeclParser::ParamDeclContext>();
}

TestCaseDeclParser::ParamDeclContext* TestCaseDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<TestCaseDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(TestCaseDeclParser::COMMA);
}

tree::TerminalNode* TestCaseDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(TestCaseDeclParser::COMMA, i);
}


size_t TestCaseDeclParser::FunctionParametersContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleFunctionParameters;
}

void TestCaseDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void TestCaseDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

TestCaseDeclParser::FunctionParametersContext* TestCaseDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 94, TestCaseDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(556);
    paramDecl();
    setState(561);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::COMMA) {
      setState(557);
      match(TestCaseDeclParser::COMMA);
      setState(558);
      paramDecl();
      setState(563);
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

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

TestCaseDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::FunctionCallBodyOptionalContext* TestCaseDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<TestCaseDeclParser::FunctionCallBodyOptionalContext>(0);
}

TestCaseDeclParser::LiteralValueContext* TestCaseDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<TestCaseDeclParser::LiteralValueContext>(0);
}

TestCaseDeclParser::SignalParamNameContext* TestCaseDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<TestCaseDeclParser::SignalParamNameContext>(0);
}

TestCaseDeclParser::AttributeNameContext* TestCaseDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<TestCaseDeclParser::AttributeNameContext>(0);
}

TestCaseDeclParser::FunctionCallContext* TestCaseDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<TestCaseDeclParser::FunctionCallContext>(0);
}


size_t TestCaseDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleFunctionCallBody;
}

void TestCaseDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void TestCaseDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

TestCaseDeclParser::FunctionCallBodyContext* TestCaseDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 96, TestCaseDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(564);
      literalValue();
      break;
    }

    case 2: {
      setState(565);
      signalParamName();
      break;
    }

    case 3: {
      setState(566);
      attributeName();
      break;
    }

    case 4: {
      setState(567);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(571);
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

TestCaseDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(TestCaseDeclParser::COMMA, 0);
}

TestCaseDeclParser::FunctionCallBodyContext* TestCaseDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<TestCaseDeclParser::FunctionCallBodyContext>(0);
}


size_t TestCaseDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleFunctionCallBodyOptional;
}

void TestCaseDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void TestCaseDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

TestCaseDeclParser::FunctionCallBodyOptionalContext* TestCaseDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 98, TestCaseDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(576);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(573);
        match(TestCaseDeclParser::COMMA);
        setState(574);
        functionCallBody();
        break;
      }

      case TestCaseDeclParser::RPAREN:
      case TestCaseDeclParser::RBRACKET: {
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

TestCaseDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::TriggerDeclContext::DOT() {
  return getToken(TestCaseDeclParser::DOT, 0);
}

tree::TerminalNode* TestCaseDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(TestCaseDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* TestCaseDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(TestCaseDeclParser::TriggerID, 0);
}


size_t TestCaseDeclParser::TriggerDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleTriggerDecl;
}

void TestCaseDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void TestCaseDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

TestCaseDeclParser::TriggerDeclContext* TestCaseDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 100, TestCaseDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(578);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::TriggerID

    || _la == TestCaseDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(579);
    match(TestCaseDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

TestCaseDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ThisDeclContext::ThisID() {
  return getToken(TestCaseDeclParser::ThisID, 0);
}

tree::TerminalNode* TestCaseDeclParser::ThisDeclContext::DOT() {
  return getToken(TestCaseDeclParser::DOT, 0);
}


size_t TestCaseDeclParser::ThisDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleThisDecl;
}

void TestCaseDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void TestCaseDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

TestCaseDeclParser::ThisDeclContext* TestCaseDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 102, TestCaseDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    match(TestCaseDeclParser::ThisID);
    setState(582);
    match(TestCaseDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

TestCaseDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::PortDeclContext::PortID() {
  return getToken(TestCaseDeclParser::PortID, 0);
}

std::vector<TestCaseDeclParser::ContextIDContext *> TestCaseDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<TestCaseDeclParser::ContextIDContext>();
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TestCaseDeclParser::PortDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::PortDeclContext::COMMA() {
  return getTokens(TestCaseDeclParser::COMMA);
}

tree::TerminalNode* TestCaseDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(TestCaseDeclParser::COMMA, i);
}


size_t TestCaseDeclParser::PortDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RulePortDecl;
}

void TestCaseDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void TestCaseDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

TestCaseDeclParser::PortDeclContext* TestCaseDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 104, TestCaseDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(584);
    match(TestCaseDeclParser::PortID);
    setState(585);
    contextID();
    setState(590);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::COMMA) {
      setState(586);
      match(TestCaseDeclParser::COMMA);
      setState(587);
      contextID();
      setState(592);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(593);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

TestCaseDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::NameDeclContext::NameID() {
  return getToken(TestCaseDeclParser::NameID, 0);
}

tree::TerminalNode* TestCaseDeclParser::NameDeclContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::NameDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::NameDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::NameDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleNameDecl;
}

void TestCaseDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void TestCaseDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

TestCaseDeclParser::NameDeclContext* TestCaseDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 106, TestCaseDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
    match(TestCaseDeclParser::NameID);
    setState(596);
    match(TestCaseDeclParser::COLON);
    setState(597);
    contextID();
    setState(598);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

TestCaseDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TestCaseDeclParser::ContextIDContext *> TestCaseDeclParser::IdPathContext::contextID() {
  return getRuleContexts<TestCaseDeclParser::ContextIDContext>();
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::IdPathContext::DOT() {
  return getTokens(TestCaseDeclParser::DOT);
}

tree::TerminalNode* TestCaseDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(TestCaseDeclParser::DOT, i);
}


size_t TestCaseDeclParser::IdPathContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleIdPath;
}

void TestCaseDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void TestCaseDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

TestCaseDeclParser::IdPathContext* TestCaseDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 108, TestCaseDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(600);
    contextID();
    setState(605);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::DOT) {
      setState(601);
      match(TestCaseDeclParser::DOT);
      setState(602);
      contextID();
      setState(607);
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

TestCaseDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::StatementBodyContext* TestCaseDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<TestCaseDeclParser::StatementBodyContext>(0);
}

TestCaseDeclParser::NestedStatementBodyContext* TestCaseDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<TestCaseDeclParser::NestedStatementBodyContext>(0);
}


size_t TestCaseDeclParser::StatementDeclContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleStatementDecl;
}

void TestCaseDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void TestCaseDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

TestCaseDeclParser::StatementDeclContext* TestCaseDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 110, TestCaseDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(610);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::IntID:
      case TestCaseDeclParser::RealID:
      case TestCaseDeclParser::BoolID:
      case TestCaseDeclParser::StringID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::ThisID:
      case TestCaseDeclParser::ReturnID:
      case TestCaseDeclParser::EnumID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::SwitchID:
      case TestCaseDeclParser::IfID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::BREAK:
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(608);
        statementBody();
        break;
      }

      case TestCaseDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(609);
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

TestCaseDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::FunctionCallStatementContext* TestCaseDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<TestCaseDeclParser::FunctionCallStatementContext>(0);
}

TestCaseDeclParser::AttributeAssignStatementContext* TestCaseDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<TestCaseDeclParser::AttributeAssignStatementContext>(0);
}

TestCaseDeclParser::SwitchStatementContext* TestCaseDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<TestCaseDeclParser::SwitchStatementContext>(0);
}

TestCaseDeclParser::ConditionalStatementContext* TestCaseDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<TestCaseDeclParser::ConditionalStatementContext>(0);
}

TestCaseDeclParser::LocalAssignStatementContext* TestCaseDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<TestCaseDeclParser::LocalAssignStatementContext>(0);
}

TestCaseDeclParser::SendToStatementContext* TestCaseDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<TestCaseDeclParser::SendToStatementContext>(0);
}

TestCaseDeclParser::BreakStatementContext* TestCaseDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<TestCaseDeclParser::BreakStatementContext>(0);
}

TestCaseDeclParser::ReturnStatementContext* TestCaseDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<TestCaseDeclParser::ReturnStatementContext>(0);
}


size_t TestCaseDeclParser::StatementBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleStatementBody;
}

void TestCaseDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void TestCaseDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

TestCaseDeclParser::StatementBodyContext* TestCaseDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 112, TestCaseDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(620);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(612);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(613);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(614);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(615);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(616);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(617);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(618);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(619);
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

TestCaseDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::FunctionCallContext* TestCaseDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<TestCaseDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleFunctionCallStatement;
}

void TestCaseDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void TestCaseDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

TestCaseDeclParser::FunctionCallStatementContext* TestCaseDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, TestCaseDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(622);
    functionCall();
    setState(623);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

TestCaseDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(TestCaseDeclParser::LBRACE, 0);
}

tree::TerminalNode* TestCaseDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(TestCaseDeclParser::RBRACE, 0);
}

std::vector<TestCaseDeclParser::StatementBodyContext *> TestCaseDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<TestCaseDeclParser::StatementBodyContext>();
}

TestCaseDeclParser::StatementBodyContext* TestCaseDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<TestCaseDeclParser::StatementBodyContext>(i);
}


size_t TestCaseDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleNestedStatementBody;
}

void TestCaseDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void TestCaseDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

TestCaseDeclParser::NestedStatementBodyContext* TestCaseDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 116, TestCaseDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    match(TestCaseDeclParser::LBRACE);
    setState(629);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
      | (1ULL << TestCaseDeclParser::UuidID)
      | (1ULL << TestCaseDeclParser::ComponentID)
      | (1ULL << TestCaseDeclParser::DeclarationID)
      | (1ULL << TestCaseDeclParser::NameID)
      | (1ULL << TestCaseDeclParser::LabelID)
      | (1ULL << TestCaseDeclParser::EnabledID)
      | (1ULL << TestCaseDeclParser::TypeID)
      | (1ULL << TestCaseDeclParser::IntID)
      | (1ULL << TestCaseDeclParser::RealID)
      | (1ULL << TestCaseDeclParser::BoolID)
      | (1ULL << TestCaseDeclParser::StringID)
      | (1ULL << TestCaseDeclParser::TriggerID)
      | (1ULL << TestCaseDeclParser::MessageTrigger)
      | (1ULL << TestCaseDeclParser::ThisID)
      | (1ULL << TestCaseDeclParser::ReturnID)
      | (1ULL << TestCaseDeclParser::EnumID)
      | (1ULL << TestCaseDeclParser::AttributeID)
      | (1ULL << TestCaseDeclParser::SignalID)
      | (1ULL << TestCaseDeclParser::PortID)
      | (1ULL << TestCaseDeclParser::ImportID)
      | (1ULL << TestCaseDeclParser::FromID)
      | (1ULL << TestCaseDeclParser::ToID)
      | (1ULL << TestCaseDeclParser::SendID)
      | (1ULL << TestCaseDeclParser::SwitchID)
      | (1ULL << TestCaseDeclParser::IfID)
      | (1ULL << TestCaseDeclParser::AsID)
      | (1ULL << TestCaseDeclParser::BREAK)
      | (1ULL << TestCaseDeclParser::ID))) != 0)) {
      setState(626);
      statementBody();
      setState(631);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(632);
    match(TestCaseDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

TestCaseDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(TestCaseDeclParser::ReturnID, 0);
}

TestCaseDeclParser::OperationContext* TestCaseDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<TestCaseDeclParser::OperationContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::ReturnStatementContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::ReturnStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleReturnStatement;
}

void TestCaseDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void TestCaseDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

TestCaseDeclParser::ReturnStatementContext* TestCaseDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, TestCaseDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    match(TestCaseDeclParser::ReturnID);
    setState(635);
    operation();
    setState(636);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

TestCaseDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::BreakStatementContext::BREAK() {
  return getToken(TestCaseDeclParser::BREAK, 0);
}

tree::TerminalNode* TestCaseDeclParser::BreakStatementContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::BreakStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleBreakStatement;
}

void TestCaseDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void TestCaseDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

TestCaseDeclParser::BreakStatementContext* TestCaseDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 120, TestCaseDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(638);
    match(TestCaseDeclParser::BREAK);
    setState(639);
    match(TestCaseDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

TestCaseDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::AtomContext* TestCaseDeclParser::OperationContext::atom() {
  return getRuleContext<TestCaseDeclParser::AtomContext>(0);
}

TestCaseDeclParser::OperationOptionalContext* TestCaseDeclParser::OperationContext::operationOptional() {
  return getRuleContext<TestCaseDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::OperationContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

TestCaseDeclParser::OperationContext* TestCaseDeclParser::OperationContext::operation() {
  return getRuleContext<TestCaseDeclParser::OperationContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::OperationContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}

tree::TerminalNode* TestCaseDeclParser::OperationContext::MINUS() {
  return getToken(TestCaseDeclParser::MINUS, 0);
}

tree::TerminalNode* TestCaseDeclParser::OperationContext::NotIdSymbol() {
  return getToken(TestCaseDeclParser::NotIdSymbol, 0);
}


size_t TestCaseDeclParser::OperationContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleOperation;
}

void TestCaseDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void TestCaseDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

TestCaseDeclParser::OperationContext* TestCaseDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 122, TestCaseDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(652);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::ThisID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::TrueID:
      case TestCaseDeclParser::FalseID:
      case TestCaseDeclParser::INT:
      case TestCaseDeclParser::REAL:
      case TestCaseDeclParser::STRING:
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(641);
        atom();
        setState(642);
        operationOptional();
        break;
      }

      case TestCaseDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(644);
        match(TestCaseDeclParser::LPAREN);
        setState(645);
        operation();
        setState(646);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(648);
        match(TestCaseDeclParser::MINUS);
        setState(649);
        operation();
        break;
      }

      case TestCaseDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(650);
        match(TestCaseDeclParser::NotIdSymbol);
        setState(651);
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

TestCaseDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::OperationContext* TestCaseDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<TestCaseDeclParser::OperationContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::OperationOptionalContext::MULT() {
  return getToken(TestCaseDeclParser::MULT, 0);
}

tree::TerminalNode* TestCaseDeclParser::OperationOptionalContext::DIV() {
  return getToken(TestCaseDeclParser::DIV, 0);
}

tree::TerminalNode* TestCaseDeclParser::OperationOptionalContext::PLUS() {
  return getToken(TestCaseDeclParser::PLUS, 0);
}

tree::TerminalNode* TestCaseDeclParser::OperationOptionalContext::MINUS() {
  return getToken(TestCaseDeclParser::MINUS, 0);
}


size_t TestCaseDeclParser::OperationOptionalContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleOperationOptional;
}

void TestCaseDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void TestCaseDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

TestCaseDeclParser::OperationOptionalContext* TestCaseDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 124, TestCaseDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(657);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::PLUS:
      case TestCaseDeclParser::MINUS:
      case TestCaseDeclParser::MULT:
      case TestCaseDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(654);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 78) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 78)) & ((1ULL << (TestCaseDeclParser::PLUS - 78))
          | (1ULL << (TestCaseDeclParser::MINUS - 78))
          | (1ULL << (TestCaseDeclParser::MULT - 78))
          | (1ULL << (TestCaseDeclParser::DIV - 78)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(655);
        operation();
        break;
      }

      case TestCaseDeclParser::NotIdSymbol:
      case TestCaseDeclParser::AndIdSymbol:
      case TestCaseDeclParser::OrIdSymbol:
      case TestCaseDeclParser::NotIdWord:
      case TestCaseDeclParser::AndIdWord:
      case TestCaseDeclParser::OrIdWord:
      case TestCaseDeclParser::ASSIGN:
      case TestCaseDeclParser::RPAREN:
      case TestCaseDeclParser::RBRACKET:
      case TestCaseDeclParser::LESSTHAN:
      case TestCaseDeclParser::GREATERTHAN:
      case TestCaseDeclParser::SEMI: {
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

TestCaseDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ExpressionContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::ExpressionContext::expression() {
  return getRuleContext<TestCaseDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}

TestCaseDeclParser::ExpressionOptionalContext* TestCaseDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<TestCaseDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(TestCaseDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionContext::NotIdWord() {
  return getToken(TestCaseDeclParser::NotIdWord, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionContext::MINUS() {
  return getToken(TestCaseDeclParser::MINUS, 0);
}

TestCaseDeclParser::OperationContext* TestCaseDeclParser::ExpressionContext::operation() {
  return getRuleContext<TestCaseDeclParser::OperationContext>(0);
}


size_t TestCaseDeclParser::ExpressionContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleExpression;
}

void TestCaseDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void TestCaseDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 126, TestCaseDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(673);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(659);
      match(TestCaseDeclParser::LPAREN);
      setState(660);
      expression();
      setState(661);
      match(TestCaseDeclParser::RPAREN);
      setState(662);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(664);
      match(TestCaseDeclParser::NotIdSymbol);
      setState(665);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(666);
      match(TestCaseDeclParser::NotIdWord);
      setState(667);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(668);
      match(TestCaseDeclParser::MINUS);
      setState(669);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(670);
      operation();
      setState(671);
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

TestCaseDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<TestCaseDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(TestCaseDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(TestCaseDeclParser::OrIdWord, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(TestCaseDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(TestCaseDeclParser::AndIdWord, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(TestCaseDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> TestCaseDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(TestCaseDeclParser::ASSIGN);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(TestCaseDeclParser::ASSIGN, i);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(TestCaseDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(TestCaseDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* TestCaseDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(TestCaseDeclParser::GREATERTHAN, 0);
}


size_t TestCaseDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleExpressionOptional;
}

void TestCaseDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void TestCaseDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

TestCaseDeclParser::ExpressionOptionalContext* TestCaseDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 128, TestCaseDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(698);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::NotIdSymbol:
      case TestCaseDeclParser::AndIdSymbol:
      case TestCaseDeclParser::OrIdSymbol:
      case TestCaseDeclParser::NotIdWord:
      case TestCaseDeclParser::AndIdWord:
      case TestCaseDeclParser::OrIdWord:
      case TestCaseDeclParser::ASSIGN:
      case TestCaseDeclParser::LESSTHAN:
      case TestCaseDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(694);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::OrIdSymbol: {
            setState(675);
            match(TestCaseDeclParser::OrIdSymbol);
            break;
          }

          case TestCaseDeclParser::OrIdWord: {
            setState(676);
            match(TestCaseDeclParser::OrIdWord);
            break;
          }

          case TestCaseDeclParser::AndIdSymbol: {
            setState(677);
            match(TestCaseDeclParser::AndIdSymbol);
            break;
          }

          case TestCaseDeclParser::AndIdWord: {
            setState(678);
            match(TestCaseDeclParser::AndIdWord);
            break;
          }

          case TestCaseDeclParser::ASSIGN: {
            setState(679);
            match(TestCaseDeclParser::ASSIGN);
            setState(680);
            match(TestCaseDeclParser::ASSIGN);
            break;
          }

          case TestCaseDeclParser::NotIdSymbol: {
            setState(681);
            match(TestCaseDeclParser::NotIdSymbol);
            setState(682);
            match(TestCaseDeclParser::ASSIGN);
            break;
          }

          case TestCaseDeclParser::NotIdWord: {
            setState(683);
            match(TestCaseDeclParser::NotIdWord);
            break;
          }

          case TestCaseDeclParser::LESSTHAN: {
            setState(684);
            match(TestCaseDeclParser::LESSTHAN);
            setState(687);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TestCaseDeclParser::ASSIGN: {
                setState(685);
                match(TestCaseDeclParser::ASSIGN);
                break;
              }

              case TestCaseDeclParser::TimeOutID:
              case TestCaseDeclParser::UuidID:
              case TestCaseDeclParser::ComponentID:
              case TestCaseDeclParser::DeclarationID:
              case TestCaseDeclParser::NameID:
              case TestCaseDeclParser::LabelID:
              case TestCaseDeclParser::EnabledID:
              case TestCaseDeclParser::TypeID:
              case TestCaseDeclParser::TriggerID:
              case TestCaseDeclParser::MessageTrigger:
              case TestCaseDeclParser::ThisID:
              case TestCaseDeclParser::AttributeID:
              case TestCaseDeclParser::SignalID:
              case TestCaseDeclParser::PortID:
              case TestCaseDeclParser::ImportID:
              case TestCaseDeclParser::FromID:
              case TestCaseDeclParser::ToID:
              case TestCaseDeclParser::SendID:
              case TestCaseDeclParser::AsID:
              case TestCaseDeclParser::NotIdSymbol:
              case TestCaseDeclParser::NotIdWord:
              case TestCaseDeclParser::TrueID:
              case TestCaseDeclParser::FalseID:
              case TestCaseDeclParser::INT:
              case TestCaseDeclParser::REAL:
              case TestCaseDeclParser::STRING:
              case TestCaseDeclParser::ID:
              case TestCaseDeclParser::LPAREN:
              case TestCaseDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case TestCaseDeclParser::GREATERTHAN: {
            setState(689);
            match(TestCaseDeclParser::GREATERTHAN);
            setState(692);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TestCaseDeclParser::ASSIGN: {
                setState(690);
                match(TestCaseDeclParser::ASSIGN);
                break;
              }

              case TestCaseDeclParser::TimeOutID:
              case TestCaseDeclParser::UuidID:
              case TestCaseDeclParser::ComponentID:
              case TestCaseDeclParser::DeclarationID:
              case TestCaseDeclParser::NameID:
              case TestCaseDeclParser::LabelID:
              case TestCaseDeclParser::EnabledID:
              case TestCaseDeclParser::TypeID:
              case TestCaseDeclParser::TriggerID:
              case TestCaseDeclParser::MessageTrigger:
              case TestCaseDeclParser::ThisID:
              case TestCaseDeclParser::AttributeID:
              case TestCaseDeclParser::SignalID:
              case TestCaseDeclParser::PortID:
              case TestCaseDeclParser::ImportID:
              case TestCaseDeclParser::FromID:
              case TestCaseDeclParser::ToID:
              case TestCaseDeclParser::SendID:
              case TestCaseDeclParser::AsID:
              case TestCaseDeclParser::NotIdSymbol:
              case TestCaseDeclParser::NotIdWord:
              case TestCaseDeclParser::TrueID:
              case TestCaseDeclParser::FalseID:
              case TestCaseDeclParser::INT:
              case TestCaseDeclParser::REAL:
              case TestCaseDeclParser::STRING:
              case TestCaseDeclParser::ID:
              case TestCaseDeclParser::LPAREN:
              case TestCaseDeclParser::MINUS: {
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
        setState(696);
        expression();
        break;
      }

      case TestCaseDeclParser::RPAREN:
      case TestCaseDeclParser::RBRACKET:
      case TestCaseDeclParser::SEMI: {
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

TestCaseDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::IfStatementContext* TestCaseDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<TestCaseDeclParser::IfStatementContext>(0);
}

TestCaseDeclParser::ElseStatementContext* TestCaseDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<TestCaseDeclParser::ElseStatementContext>(0);
}


size_t TestCaseDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleConditionalStatement;
}

void TestCaseDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void TestCaseDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

TestCaseDeclParser::ConditionalStatementContext* TestCaseDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 130, TestCaseDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    ifStatement();
    setState(703);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(701);
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

TestCaseDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::IfStatementContext::IfID() {
  return getToken(TestCaseDeclParser::IfID, 0);
}

TestCaseDeclParser::IfEuTContext* TestCaseDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<TestCaseDeclParser::IfEuTContext>(0);
}

TestCaseDeclParser::StatementDeclContext* TestCaseDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<TestCaseDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::IfStatementContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::IfStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleIfStatement;
}

void TestCaseDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void TestCaseDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

TestCaseDeclParser::IfStatementContext* TestCaseDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 132, TestCaseDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(705);
    match(TestCaseDeclParser::IfID);
    setState(706);
    ifEuT();
    setState(709);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::IntID:
      case TestCaseDeclParser::RealID:
      case TestCaseDeclParser::BoolID:
      case TestCaseDeclParser::StringID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::ThisID:
      case TestCaseDeclParser::ReturnID:
      case TestCaseDeclParser::EnumID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::SwitchID:
      case TestCaseDeclParser::IfID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::BREAK:
      case TestCaseDeclParser::ID:
      case TestCaseDeclParser::LBRACE: {
        setState(707);
        statementDecl();
        break;
      }

      case TestCaseDeclParser::SEMI: {
        setState(708);
        match(TestCaseDeclParser::SEMI);
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

TestCaseDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::IfEuTContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::IfEuTContext::expression() {
  return getRuleContext<TestCaseDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::IfEuTContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}


size_t TestCaseDeclParser::IfEuTContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleIfEuT;
}

void TestCaseDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void TestCaseDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

TestCaseDeclParser::IfEuTContext* TestCaseDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 134, TestCaseDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(711);
    match(TestCaseDeclParser::LPAREN);
    setState(712);
    expression();
    setState(713);
    match(TestCaseDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

TestCaseDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::ElseStatementContext::ElseID() {
  return getToken(TestCaseDeclParser::ElseID, 0);
}

TestCaseDeclParser::StatementDeclContext* TestCaseDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<TestCaseDeclParser::StatementDeclContext>(0);
}


size_t TestCaseDeclParser::ElseStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleElseStatement;
}

void TestCaseDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void TestCaseDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

TestCaseDeclParser::ElseStatementContext* TestCaseDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, TestCaseDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(715);
    match(TestCaseDeclParser::ElseID);
    setState(716);
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

TestCaseDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(TestCaseDeclParser::SwitchID, 0);
}

TestCaseDeclParser::SwitchPuTContext* TestCaseDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<TestCaseDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(TestCaseDeclParser::LBRACE, 0);
}

tree::TerminalNode* TestCaseDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(TestCaseDeclParser::RBRACE, 0);
}

TestCaseDeclParser::DefaultStatementContext* TestCaseDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<TestCaseDeclParser::DefaultStatementContext>(0);
}

std::vector<TestCaseDeclParser::CaseStatementContext *> TestCaseDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<TestCaseDeclParser::CaseStatementContext>();
}

TestCaseDeclParser::CaseStatementContext* TestCaseDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<TestCaseDeclParser::CaseStatementContext>(i);
}


size_t TestCaseDeclParser::SwitchStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSwitchStatement;
}

void TestCaseDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void TestCaseDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

TestCaseDeclParser::SwitchStatementContext* TestCaseDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, TestCaseDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(718);
    match(TestCaseDeclParser::SwitchID);
    setState(719);
    switchPuT();
    setState(720);
    match(TestCaseDeclParser::LBRACE);
    setState(724);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::CaseID) {
      setState(721);
      caseStatement();
      setState(726);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(729);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::DefaultID: {
        setState(727);
        defaultStatement();
        break;
      }

      case TestCaseDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(731);
    match(TestCaseDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

TestCaseDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(TestCaseDeclParser::LPAREN, 0);
}

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(TestCaseDeclParser::RPAREN, 0);
}


size_t TestCaseDeclParser::SwitchPuTContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleSwitchPuT;
}

void TestCaseDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void TestCaseDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

TestCaseDeclParser::SwitchPuTContext* TestCaseDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 140, TestCaseDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(733);
    match(TestCaseDeclParser::LPAREN);
    setState(734);
    contextID();
    setState(735);
    match(TestCaseDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

TestCaseDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::CaseStatementContext::CaseID() {
  return getToken(TestCaseDeclParser::CaseID, 0);
}

TestCaseDeclParser::LiteralValueContext* TestCaseDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<TestCaseDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::CaseStatementContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

TestCaseDeclParser::NestedStatementBodyContext* TestCaseDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<TestCaseDeclParser::NestedStatementBodyContext>(0);
}

std::vector<TestCaseDeclParser::StatementBodyContext *> TestCaseDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<TestCaseDeclParser::StatementBodyContext>();
}

TestCaseDeclParser::StatementBodyContext* TestCaseDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<TestCaseDeclParser::StatementBodyContext>(i);
}


size_t TestCaseDeclParser::CaseStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleCaseStatement;
}

void TestCaseDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void TestCaseDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

TestCaseDeclParser::CaseStatementContext* TestCaseDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 142, TestCaseDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(737);
    match(TestCaseDeclParser::CaseID);
    setState(738);
    literalValue();
    setState(739);
    match(TestCaseDeclParser::COLON);
    setState(747);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LBRACE: {
        setState(740);
        nestedStatementBody();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::IntID:
      case TestCaseDeclParser::RealID:
      case TestCaseDeclParser::BoolID:
      case TestCaseDeclParser::StringID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::ThisID:
      case TestCaseDeclParser::ReturnID:
      case TestCaseDeclParser::EnumID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::SwitchID:
      case TestCaseDeclParser::CaseID:
      case TestCaseDeclParser::DefaultID:
      case TestCaseDeclParser::IfID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::BREAK:
      case TestCaseDeclParser::ID:
      case TestCaseDeclParser::RBRACE: {
        setState(744);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
          | (1ULL << TestCaseDeclParser::UuidID)
          | (1ULL << TestCaseDeclParser::ComponentID)
          | (1ULL << TestCaseDeclParser::DeclarationID)
          | (1ULL << TestCaseDeclParser::NameID)
          | (1ULL << TestCaseDeclParser::LabelID)
          | (1ULL << TestCaseDeclParser::EnabledID)
          | (1ULL << TestCaseDeclParser::TypeID)
          | (1ULL << TestCaseDeclParser::IntID)
          | (1ULL << TestCaseDeclParser::RealID)
          | (1ULL << TestCaseDeclParser::BoolID)
          | (1ULL << TestCaseDeclParser::StringID)
          | (1ULL << TestCaseDeclParser::TriggerID)
          | (1ULL << TestCaseDeclParser::MessageTrigger)
          | (1ULL << TestCaseDeclParser::ThisID)
          | (1ULL << TestCaseDeclParser::ReturnID)
          | (1ULL << TestCaseDeclParser::EnumID)
          | (1ULL << TestCaseDeclParser::AttributeID)
          | (1ULL << TestCaseDeclParser::SignalID)
          | (1ULL << TestCaseDeclParser::PortID)
          | (1ULL << TestCaseDeclParser::ImportID)
          | (1ULL << TestCaseDeclParser::FromID)
          | (1ULL << TestCaseDeclParser::ToID)
          | (1ULL << TestCaseDeclParser::SendID)
          | (1ULL << TestCaseDeclParser::SwitchID)
          | (1ULL << TestCaseDeclParser::IfID)
          | (1ULL << TestCaseDeclParser::AsID)
          | (1ULL << TestCaseDeclParser::BREAK)
          | (1ULL << TestCaseDeclParser::ID))) != 0)) {
          setState(741);
          statementBody();
          setState(746);
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

TestCaseDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(TestCaseDeclParser::DefaultID, 0);
}

tree::TerminalNode* TestCaseDeclParser::DefaultStatementContext::COLON() {
  return getToken(TestCaseDeclParser::COLON, 0);
}

TestCaseDeclParser::NestedStatementBodyContext* TestCaseDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<TestCaseDeclParser::NestedStatementBodyContext>(0);
}

std::vector<TestCaseDeclParser::StatementBodyContext *> TestCaseDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<TestCaseDeclParser::StatementBodyContext>();
}

TestCaseDeclParser::StatementBodyContext* TestCaseDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<TestCaseDeclParser::StatementBodyContext>(i);
}


size_t TestCaseDeclParser::DefaultStatementContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleDefaultStatement;
}

void TestCaseDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void TestCaseDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

TestCaseDeclParser::DefaultStatementContext* TestCaseDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 144, TestCaseDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(749);
    match(TestCaseDeclParser::DefaultID);
    setState(750);
    match(TestCaseDeclParser::COLON);
    setState(758);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LBRACE: {
        setState(751);
        nestedStatementBody();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
      case TestCaseDeclParser::UuidID:
      case TestCaseDeclParser::ComponentID:
      case TestCaseDeclParser::DeclarationID:
      case TestCaseDeclParser::NameID:
      case TestCaseDeclParser::LabelID:
      case TestCaseDeclParser::EnabledID:
      case TestCaseDeclParser::TypeID:
      case TestCaseDeclParser::IntID:
      case TestCaseDeclParser::RealID:
      case TestCaseDeclParser::BoolID:
      case TestCaseDeclParser::StringID:
      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger:
      case TestCaseDeclParser::ThisID:
      case TestCaseDeclParser::ReturnID:
      case TestCaseDeclParser::EnumID:
      case TestCaseDeclParser::AttributeID:
      case TestCaseDeclParser::SignalID:
      case TestCaseDeclParser::PortID:
      case TestCaseDeclParser::ImportID:
      case TestCaseDeclParser::FromID:
      case TestCaseDeclParser::ToID:
      case TestCaseDeclParser::SendID:
      case TestCaseDeclParser::SwitchID:
      case TestCaseDeclParser::IfID:
      case TestCaseDeclParser::AsID:
      case TestCaseDeclParser::BREAK:
      case TestCaseDeclParser::ID:
      case TestCaseDeclParser::RBRACE: {
        setState(755);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
          | (1ULL << TestCaseDeclParser::UuidID)
          | (1ULL << TestCaseDeclParser::ComponentID)
          | (1ULL << TestCaseDeclParser::DeclarationID)
          | (1ULL << TestCaseDeclParser::NameID)
          | (1ULL << TestCaseDeclParser::LabelID)
          | (1ULL << TestCaseDeclParser::EnabledID)
          | (1ULL << TestCaseDeclParser::TypeID)
          | (1ULL << TestCaseDeclParser::IntID)
          | (1ULL << TestCaseDeclParser::RealID)
          | (1ULL << TestCaseDeclParser::BoolID)
          | (1ULL << TestCaseDeclParser::StringID)
          | (1ULL << TestCaseDeclParser::TriggerID)
          | (1ULL << TestCaseDeclParser::MessageTrigger)
          | (1ULL << TestCaseDeclParser::ThisID)
          | (1ULL << TestCaseDeclParser::ReturnID)
          | (1ULL << TestCaseDeclParser::EnumID)
          | (1ULL << TestCaseDeclParser::AttributeID)
          | (1ULL << TestCaseDeclParser::SignalID)
          | (1ULL << TestCaseDeclParser::PortID)
          | (1ULL << TestCaseDeclParser::ImportID)
          | (1ULL << TestCaseDeclParser::FromID)
          | (1ULL << TestCaseDeclParser::ToID)
          | (1ULL << TestCaseDeclParser::SendID)
          | (1ULL << TestCaseDeclParser::SwitchID)
          | (1ULL << TestCaseDeclParser::IfID)
          | (1ULL << TestCaseDeclParser::AsID)
          | (1ULL << TestCaseDeclParser::BREAK)
          | (1ULL << TestCaseDeclParser::ID))) != 0)) {
          setState(752);
          statementBody();
          setState(757);
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

TestCaseDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TestCaseDeclParser::SignalParamNameContext* TestCaseDeclParser::AtomContext::signalParamName() {
  return getRuleContext<TestCaseDeclParser::SignalParamNameContext>(0);
}

TestCaseDeclParser::AttributeNameContext* TestCaseDeclParser::AtomContext::attributeName() {
  return getRuleContext<TestCaseDeclParser::AttributeNameContext>(0);
}

TestCaseDeclParser::FunctionCallContext* TestCaseDeclParser::AtomContext::functionCall() {
  return getRuleContext<TestCaseDeclParser::FunctionCallContext>(0);
}

TestCaseDeclParser::LiteralValueContext* TestCaseDeclParser::AtomContext::literalValue() {
  return getRuleContext<TestCaseDeclParser::LiteralValueContext>(0);
}


size_t TestCaseDeclParser::AtomContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleAtom;
}

void TestCaseDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void TestCaseDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

TestCaseDeclParser::AtomContext* TestCaseDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 146, TestCaseDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(764);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(760);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(761);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(762);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(763);
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
std::vector<dfa::DFA> TestCaseDeclParser::_decisionToDFA;
atn::PredictionContextCache TestCaseDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TestCaseDeclParser::_atn;
std::vector<uint16_t> TestCaseDeclParser::_serializedATN;

std::vector<std::string> TestCaseDeclParser::_ruleNames = {
  "testCaseDecl", "testCaseBody", "declarations", "aliasDef", "steps", "idStatement", 
  "assignmentDef", "messageDecl", "checkDecl", "timerDecl", "timeOutDecl", 
  "accuracyDecl", "altDecl", "altBody", "altBodyOptional", "uuidDecl", "enabledDecl", 
  "contextID", "functionCall", "functionCall2", "componentIdPath", "signalIdPath", 
  "attributeIdPath", "signalSend", "commonDecl", "importPathDecl", "importPathBody", 
  "importFileBody", "importAs", "typeDefDecl", "typeDecl", "intTypeDecl", 
  "realTypeDecl", "enumTypeDecl", "attributeDecl", "literalValue", "signalParamName", 
  "attributeName", "toPortName", "attributeAssignStatement", "localAssignStatement", 
  "sendToStatement", "singleAssignment", "multiAssignment", "signalDecl", 
  "paramDecl", "functionDecl", "functionParameters", "functionCallBody", 
  "functionCallBodyOptional", "triggerDecl", "thisDecl", "portDecl", "nameDecl", 
  "idPath", "statementDecl", "statementBody", "functionCallStatement", "nestedStatementBody", 
  "returnStatement", "breakStatement", "operation", "operationOptional", 
  "expression", "expressionOptional", "conditionalStatement", "ifStatement", 
  "ifEuT", "elseStatement", "switchStatement", "switchPuT", "caseStatement", 
  "defaultStatement", "atom"
};

std::vector<std::string> TestCaseDeclParser::_literalNames = {
  "", "'Message'", "'timeout'", "'Check'", "'uuid'", "'Alt'", "'Timer'", 
  "'accuracy'", "'Component'", "'Declaration'", "'TestCase'", "'ms'", "'s'", 
  "", "'name'", "'label'", "'enabled'", "'Type'", "'int'", "'real'", "'bool'", 
  "'string'", "'trigger'", "'msg'", "'this'", "'return'", "'SignalTransition'", 
  "'TimeoutTransition'", "'enum'", "'description'", "'Attribute'", "'Signal'", 
  "'Port'", "'import'", "'from'", "'to'", "'send'", "'Function'", "'switch'", 
  "'case'", "'default'", "'if'", "'else'", "'as'", "'@'", "'!'", "'&&'", 
  "'||'", "'not'", "'and'", "'or'", "'true'", "'false'", "'break'", "'='", 
  "'<->'", "'->'", "'<-'", "'..'", "", "", "", "", "", "", "'('", "')'", 
  "'{'", "'}'", "'['", "']'", "'<'", "'>'", "':'", "';'", "','", "'_'", 
  "'.'", "'+'", "'-'", "'*'", "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> TestCaseDeclParser::_symbolicNames = {
  "", "MessageID", "TimeOutID", "CheckID", "UuidID", "AltID", "TimerID", 
  "AccuracyID", "ComponentID", "DeclarationID", "TestCaseID", "MilliSekID", 
  "SekID", "IGNORE_NEWLINE", "NameID", "LabelID", "EnabledID", "TypeID", 
  "IntID", "RealID", "BoolID", "StringID", "TriggerID", "MessageTrigger", 
  "ThisID", "ReturnID", "SignalTransitionID", "TimeoutTransitionID", "EnumID", 
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

dfa::Vocabulary TestCaseDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TestCaseDeclParser::_tokenNames;

TestCaseDeclParser::Initializer::Initializer() {
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
    0x3, 0x58, 0x301, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb9, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xd2, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0xd8, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0xdd, 0xa, 0x7, 0x5, 0x7, 0xdf, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xfb, 0xa, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x102, 0xa, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0x105, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x123, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x129, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x132, 0xa, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x150, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 
    0x15f, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x162, 0xb, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x167, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 
    0x16a, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 
    0x170, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x173, 0xb, 0x18, 0x5, 0x18, 
    0x175, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x17f, 0xa, 0x1a, 0xc, 0x1a, 
    0xe, 0x1a, 0x182, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x188, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x5, 0x1d, 0x19b, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
    0x1a0, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 
    0x20, 0x1ad, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x1b6, 0xa, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
    0x22, 0x1bf, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x7, 0x23, 0x1c6, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x1c9, 
    0xb, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x5, 0x24, 0x1d2, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 
    0x25, 0x1dc, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x5, 0x27, 0x1e3, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 
    0x1f4, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x5, 0x2b, 0x1fc, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 
    0x3, 0x2c, 0x5, 0x2c, 0x202, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 
    0x206, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x209, 0xb, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x7, 0x2e, 0x213, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x216, 0xb, 
    0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x219, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x5, 0x2e, 0x21d, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x5, 0x30, 0x22a, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x232, 0xa, 0x31, 0xc, 0x31, 
    0xe, 0x31, 0x235, 0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x5, 0x32, 0x23c, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x243, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x36, 0x3, 0x36, 0x7, 0x36, 0x24f, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 
    0x252, 0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x25e, 
    0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x261, 0xb, 0x38, 0x3, 0x39, 0x3, 0x39, 
    0x5, 0x39, 0x265, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x26f, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x276, 
    0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x279, 0xb, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 
    0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x28f, 
    0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x294, 0xa, 0x40, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x5, 0x41, 0x2a4, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x2b2, 0xa, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x2b7, 0xa, 0x42, 0x5, 0x42, 0x2b9, 
    0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x2bd, 0xa, 0x42, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x2c2, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x2c8, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 
    0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x2d5, 0xa, 0x47, 0xc, 0x47, 
    0xe, 0x47, 0x2d8, 0xb, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x2dc, 
    0xa, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x7, 0x49, 
    0x2e9, 0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 0x2ec, 0xb, 0x49, 0x5, 0x49, 
    0x2ee, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 
    0x2f4, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x2f7, 0xb, 0x4a, 0x5, 0x4a, 
    0x2f9, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 
    0x2ff, 0xa, 0x4b, 0x3, 0x4b, 0x2, 0x2, 0x4c, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
    0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 
    0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 
    0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 
    0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x2, 0x8, 0x4, 
    0x2, 0x35, 0x36, 0x3d, 0x3f, 0x3, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0xd, 0xe, 
    0x3, 0x2, 0x35, 0x36, 0x3, 0x2, 0x18, 0x19, 0x3, 0x2, 0x50, 0x53, 0x2, 
    0x32e, 0x2, 0x96, 0x3, 0x2, 0x2, 0x2, 0x4, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xa, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe, 0xe0, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x12, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x108, 0x3, 0x2, 0x2, 0x2, 0x16, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x116, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x131, 0x3, 0x2, 0x2, 0x2, 0x20, 0x133, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x138, 0x3, 0x2, 0x2, 0x2, 0x24, 0x14f, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x151, 0x3, 0x2, 0x2, 0x2, 0x28, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x174, 0x3, 0x2, 0x2, 0x2, 0x30, 0x176, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x180, 0x3, 0x2, 0x2, 0x2, 0x34, 0x187, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x189, 0x3, 0x2, 0x2, 0x2, 0x38, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x19f, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1ac, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1b7, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1cc, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1dd, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x1e9, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1f7, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x201, 0x3, 0x2, 0x2, 0x2, 0x58, 0x203, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x220, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x223, 0x3, 0x2, 0x2, 0x2, 0x60, 0x22e, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x64, 0x242, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x244, 0x3, 0x2, 0x2, 0x2, 0x68, 0x247, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x24a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x255, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x25a, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x264, 0x3, 0x2, 0x2, 0x2, 0x72, 0x26e, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x270, 0x3, 0x2, 0x2, 0x2, 0x76, 0x273, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x280, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x293, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x82, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x2be, 0x3, 0x2, 0x2, 0x2, 0x86, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x88, 0x2c9, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x2d0, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2e3, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2fe, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x97, 0x5, 0x34, 0x1b, 0x2, 0x97, 0x98, 0x7, 0xc, 0x2, 0x2, 
    0x98, 0x99, 0x7, 0x45, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x4, 0x3, 0x2, 0x9a, 
    0x9b, 0x7, 0x46, 0x2, 0x2, 0x9b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 
    0x7, 0xb, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x45, 0x2, 0x2, 0x9e, 0x9f, 0x5, 
    0x6, 0x4, 0x2, 0x9f, 0xa0, 0x7, 0x46, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0xa, 
    0x6, 0x2, 0xa1, 0x5, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x5, 0x46, 0x24, 
    0x2, 0xa3, 0xa4, 0x5, 0x6, 0x4, 0x2, 0xa4, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa6, 0x5, 0x6c, 0x37, 0x2, 0xa6, 0xa7, 0x5, 0x6, 0x4, 0x2, 0xa7, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x20, 0x11, 0x2, 0xa9, 0xaa, 
    0x5, 0x6, 0x4, 0x2, 0xaa, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 
    0x22, 0x12, 0x2, 0xac, 0xad, 0x5, 0x6, 0x4, 0x2, 0xad, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x5, 0x5a, 0x2e, 0x2, 0xaf, 0xb0, 0x5, 0x6, 0x4, 
    0x2, 0xb0, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x12, 0xa, 0x2, 
    0xb2, 0xb3, 0x5, 0x6, 0x4, 0x2, 0xb3, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb5, 0x5, 0x8, 0x5, 0x2, 0xb5, 0xb6, 0x5, 0x6, 0x4, 0x2, 0xb6, 0xb9, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0x7, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xbb, 0x7, 0xa, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x6e, 0x38, 0x2, 0xbc, 0xbd, 
    0x7, 0x2d, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x24, 0x13, 0x2, 0xbe, 0xbf, 0x7, 
    0x4c, 0x2, 0x2, 0xbf, 0x9, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x14, 
    0xb, 0x2, 0xc1, 0xc2, 0x5, 0xa, 0x6, 0x2, 0xc2, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc4, 0x5, 0x10, 0x9, 0x2, 0xc4, 0xc5, 0x5, 0xa, 0x6, 0x2, 
    0xc5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x12, 0xa, 0x2, 0xc7, 
    0xc8, 0x5, 0xa, 0x6, 0x2, 0xc8, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 
    0x5, 0x1a, 0xe, 0x2, 0xca, 0xcb, 0x5, 0xa, 0x6, 0x2, 0xcb, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0xc, 0x7, 0x2, 0xcd, 0xce, 0x7, 0x4c, 
    0x2, 0x2, 0xce, 0xcf, 0x5, 0xa, 0x6, 0x2, 0xcf, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xc9, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 
    0x68, 0x35, 0x2, 0xd4, 0xd7, 0x5, 0x6e, 0x38, 0x2, 0xd5, 0xd8, 0x5, 
    0xe, 0x8, 0x2, 0xd6, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdf, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xdc, 0x5, 0x6e, 0x38, 0x2, 0xda, 0xdd, 0x5, 0xe, 0x8, 0x2, 
    0xdb, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xd3, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x38, 0x2, 0x2, 0xe1, 0xe2, 0x9, 0x2, 
    0x2, 0x2, 0xe2, 0xf, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x3, 0x2, 
    0x2, 0xe4, 0xe5, 0x7, 0x43, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x6e, 0x38, 0x2, 
    0xe6, 0xe7, 0x7, 0x3a, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x6e, 0x38, 0x2, 0xe8, 
    0xe9, 0x7, 0x44, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x4b, 0x2, 0x2, 0xea, 0xeb, 
    0x5, 0x26, 0x14, 0x2, 0xeb, 0xec, 0x7, 0x4c, 0x2, 0x2, 0xec, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 0x5, 0x2, 0x2, 0xee, 0xef, 0x7, 0x43, 
    0x2, 0x2, 0xef, 0xf0, 0x5, 0x6e, 0x38, 0x2, 0xf0, 0xf1, 0x7, 0x3a, 0x2, 
    0x2, 0xf1, 0xf2, 0x5, 0x6e, 0x38, 0x2, 0xf2, 0xf3, 0x7, 0x44, 0x2, 0x2, 
    0xf3, 0xf4, 0x7, 0x4b, 0x2, 0x2, 0xf4, 0x104, 0x5, 0x28, 0x15, 0x2, 
    0xf5, 0xf6, 0x7, 0x4d, 0x2, 0x2, 0xf6, 0xfa, 0x5, 0x16, 0xc, 0x2, 0xf7, 
    0xf8, 0x7, 0x4d, 0x2, 0x2, 0xf8, 0xfb, 0x5, 0x18, 0xd, 0x2, 0xf9, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0x105, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x4d, 
    0x2, 0x2, 0xfd, 0x101, 0x5, 0x18, 0xd, 0x2, 0xfe, 0xff, 0x7, 0x4d, 0x2, 
    0x2, 0xff, 0x102, 0x5, 0x16, 0xc, 0x2, 0x100, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x105, 0x3, 0x2, 0x2, 0x2, 0x103, 0x105, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x104, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0x107, 0x7, 0x4c, 0x2, 0x2, 0x107, 0x13, 0x3, 0x2, 0x2, 0x2, 0x108, 
    0x109, 0x7, 0x8, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x2e, 0x2, 0x2, 0x10a, 
    0x10b, 0x5, 0x6e, 0x38, 0x2, 0x10b, 0x10c, 0x5, 0x24, 0x13, 0x2, 0x10c, 
    0x10d, 0x7, 0x38, 0x2, 0x2, 0x10d, 0x10e, 0x9, 0x3, 0x2, 0x2, 0x10e, 
    0x10f, 0x9, 0x4, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x4c, 0x2, 0x2, 0x110, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x4, 0x2, 0x2, 0x112, 0x113, 
    0x7, 0x4b, 0x2, 0x2, 0x113, 0x114, 0x9, 0x3, 0x2, 0x2, 0x114, 0x115, 
    0x9, 0x4, 0x2, 0x2, 0x115, 0x17, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x7, 
    0x9, 0x2, 0x2, 0x117, 0x118, 0x7, 0x4b, 0x2, 0x2, 0x118, 0x119, 0x9, 
    0x3, 0x2, 0x2, 0x119, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x7, 
    0x2, 0x2, 0x11b, 0x11c, 0x7, 0x45, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x1e, 
    0x10, 0x2, 0x11d, 0x11e, 0x7, 0x46, 0x2, 0x2, 0x11e, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x11f, 0x122, 0x7, 0x47, 0x2, 0x2, 0x120, 0x123, 0x5, 0x80, 
    0x41, 0x2, 0x121, 0x123, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 
    0x2, 0x2, 0x122, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x125, 0x7, 0x48, 0x2, 0x2, 0x125, 0x128, 0x7, 0x45, 
    0x2, 0x2, 0x126, 0x129, 0x5, 0x12, 0xa, 0x2, 0x127, 0x129, 0x3, 0x2, 
    0x2, 0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x128, 0x127, 0x3, 0x2, 
    0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x5, 0xa, 
    0x6, 0x2, 0x12b, 0x12c, 0x7, 0x46, 0x2, 0x2, 0x12c, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x12d, 0x12e, 0x5, 0x1c, 0xf, 0x2, 0x12e, 0x12f, 0x5, 0x1e, 
    0x10, 0x2, 0x12f, 0x132, 0x3, 0x2, 0x2, 0x2, 0x130, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x131, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x131, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x7, 0x6, 0x2, 
    0x2, 0x134, 0x135, 0x7, 0x4b, 0x2, 0x2, 0x135, 0x136, 0x7, 0x3f, 0x2, 
    0x2, 0x136, 0x137, 0x7, 0x4c, 0x2, 0x2, 0x137, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x138, 0x139, 0x7, 0x12, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x4b, 0x2, 
    0x2, 0x13a, 0x13b, 0x9, 0x5, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x4c, 0x2, 
    0x2, 0x13c, 0x23, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x150, 0x7, 0x40, 0x2, 
    0x2, 0x13e, 0x150, 0x7, 0x10, 0x2, 0x2, 0x13f, 0x150, 0x7, 0x6, 0x2, 
    0x2, 0x140, 0x150, 0x7, 0x11, 0x2, 0x2, 0x141, 0x150, 0x7, 0x12, 0x2, 
    0x2, 0x142, 0x150, 0x7, 0x13, 0x2, 0x2, 0x143, 0x150, 0x9, 0x6, 0x2, 
    0x2, 0x144, 0x150, 0x7, 0x20, 0x2, 0x2, 0x145, 0x150, 0x7, 0x21, 0x2, 
    0x2, 0x146, 0x150, 0x7, 0x22, 0x2, 0x2, 0x147, 0x150, 0x7, 0x23, 0x2, 
    0x2, 0x148, 0x150, 0x7, 0x24, 0x2, 0x2, 0x149, 0x150, 0x7, 0x25, 0x2, 
    0x2, 0x14a, 0x150, 0x7, 0x26, 0x2, 0x2, 0x14b, 0x150, 0x7, 0x2d, 0x2, 
    0x2, 0x14c, 0x150, 0x7, 0x4, 0x2, 0x2, 0x14d, 0x150, 0x7, 0xa, 0x2, 
    0x2, 0x14e, 0x150, 0x7, 0xb, 0x2, 0x2, 0x14f, 0x13d, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x13f, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x141, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x142, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x143, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x144, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x146, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x147, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x149, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x150, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x151, 0x152, 0x5, 0x6e, 0x38, 0x2, 0x152, 0x153, 0x7, 0x43, 0x2, 0x2, 
    0x153, 0x154, 0x5, 0x62, 0x32, 0x2, 0x154, 0x155, 0x7, 0x44, 0x2, 0x2, 
    0x155, 0x27, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x5, 0x6e, 0x38, 0x2, 
    0x157, 0x158, 0x7, 0x47, 0x2, 0x2, 0x158, 0x159, 0x5, 0x62, 0x32, 0x2, 
    0x159, 0x15a, 0x7, 0x48, 0x2, 0x2, 0x15a, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x15b, 0x160, 0x5, 0x24, 0x13, 0x2, 0x15c, 0x15d, 0x7, 0x4f, 0x2, 0x2, 
    0x15d, 0x15f, 0x5, 0x24, 0x13, 0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 
    0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x162, 
    0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x168, 0x5, 0x24, 0x13, 0x2, 0x164, 
    0x165, 0x7, 0x4f, 0x2, 0x2, 0x165, 0x167, 0x5, 0x24, 0x13, 0x2, 0x166, 
    0x164, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x168, 
    0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x175, 
    0x5, 0x4c, 0x27, 0x2, 0x16c, 0x171, 0x5, 0x24, 0x13, 0x2, 0x16d, 0x16e, 
    0x7, 0x4f, 0x2, 0x2, 0x16e, 0x170, 0x5, 0x24, 0x13, 0x2, 0x16f, 0x16d, 
    0x3, 0x2, 0x2, 0x2, 0x170, 0x173, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16f, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x3, 0x2, 0x2, 0x2, 0x172, 0x175, 
    0x3, 0x2, 0x2, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x174, 0x16b, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x175, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x176, 0x177, 0x5, 0x2c, 0x17, 0x2, 0x177, 0x178, 0x7, 
    0x43, 0x2, 0x2, 0x178, 0x179, 0x5, 0x62, 0x32, 0x2, 0x179, 0x17a, 0x7, 
    0x44, 0x2, 0x2, 0x17a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17f, 0x5, 
    0x3c, 0x1f, 0x2, 0x17c, 0x17f, 0x5, 0x46, 0x24, 0x2, 0x17d, 0x17f, 0x5, 
    0x5a, 0x2e, 0x2, 0x17e, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 
    0x2, 0x2, 0x2, 0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x182, 0x3, 
    0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x3, 
    0x2, 0x2, 0x2, 0x181, 0x33, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x184, 0x5, 0x36, 0x1c, 0x2, 0x184, 0x185, 0x5, 0x34, 
    0x1b, 0x2, 0x185, 0x188, 0x3, 0x2, 0x2, 0x2, 0x186, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x183, 0x3, 0x2, 0x2, 0x2, 0x187, 0x186, 0x3, 0x2, 
    0x2, 0x2, 0x188, 0x35, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x7, 0x23, 
    0x2, 0x2, 0x18a, 0x18b, 0x7, 0x49, 0x2, 0x2, 0x18b, 0x18c, 0x5, 0x38, 
    0x1d, 0x2, 0x18c, 0x18d, 0x7, 0x4a, 0x2, 0x2, 0x18d, 0x18e, 0x5, 0x3a, 
    0x1e, 0x2, 0x18e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x5, 0x24, 
    0x13, 0x2, 0x190, 0x191, 0x7, 0x4f, 0x2, 0x2, 0x191, 0x192, 0x5, 0x24, 
    0x13, 0x2, 0x192, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x7, 0x3c, 
    0x2, 0x2, 0x194, 0x195, 0x7, 0x53, 0x2, 0x2, 0x195, 0x19b, 0x5, 0x38, 
    0x1d, 0x2, 0x196, 0x197, 0x5, 0x24, 0x13, 0x2, 0x197, 0x198, 0x7, 0x53, 
    0x2, 0x2, 0x198, 0x199, 0x5, 0x38, 0x1d, 0x2, 0x199, 0x19b, 0x3, 0x2, 
    0x2, 0x2, 0x19a, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x19a, 0x196, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x19d, 0x7, 0x2d, 0x2, 0x2, 0x19d, 0x1a0, 0x5, 0x24, 0x13, 
    0x2, 0x19e, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x19c, 0x3, 0x2, 0x2, 
    0x2, 0x19f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x1a1, 0x1a2, 0x7, 0x13, 0x2, 0x2, 0x1a2, 0x1a3, 0x5, 0x3e, 0x20, 0x2, 
    0x1a3, 0x1a4, 0x5, 0x24, 0x13, 0x2, 0x1a4, 0x1a5, 0x7, 0x4c, 0x2, 0x2, 
    0x1a5, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1ad, 0x5, 0x40, 0x21, 0x2, 
    0x1a7, 0x1ad, 0x5, 0x42, 0x22, 0x2, 0x1a8, 0x1ad, 0x5, 0x44, 0x23, 0x2, 
    0x1a9, 0x1ad, 0x7, 0x16, 0x2, 0x2, 0x1aa, 0x1ad, 0x7, 0x17, 0x2, 0x2, 
    0x1ab, 0x1ad, 0x5, 0x24, 0x13, 0x2, 0x1ac, 0x1a6, 0x3, 0x2, 0x2, 0x2, 
    0x1ac, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1a8, 0x3, 0x2, 0x2, 0x2, 
    0x1ac, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x1ac, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1b5, 0x7, 0x14, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x43, 0x2, 0x2, 0x1b0, 
    0x1b1, 0x7, 0x3d, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x3c, 0x2, 0x2, 0x1b2, 
    0x1b3, 0x7, 0x3d, 0x2, 0x2, 0x1b3, 0x1b6, 0x7, 0x44, 0x2, 0x2, 0x1b4, 
    0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
    0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1be, 
    0x7, 0x15, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x43, 0x2, 0x2, 0x1b9, 0x1ba, 
    0x7, 0x3e, 0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0x3c, 0x2, 0x2, 0x1bb, 0x1bc, 
    0x7, 0x3e, 0x2, 0x2, 0x1bc, 0x1bf, 0x7, 0x44, 0x2, 0x2, 0x1bd, 0x1bf, 
    0x3, 0x2, 0x2, 0x2, 0x1be, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bd, 
    0x3, 0x2, 0x2, 0x2, 0x1bf, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x7, 
    0x1e, 0x2, 0x2, 0x1c1, 0x1c2, 0x7, 0x43, 0x2, 0x2, 0x1c2, 0x1c7, 0x5, 
    0x24, 0x13, 0x2, 0x1c3, 0x1c4, 0x7, 0x4d, 0x2, 0x2, 0x1c4, 0x1c6, 0x5, 
    0x24, 0x13, 0x2, 0x1c5, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 
    0x2, 0x2, 0x2, 0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 
    0x2, 0x2, 0x2, 0x1c8, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 
    0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x7, 0x44, 0x2, 0x2, 0x1cb, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0x20, 0x2, 0x2, 0x1cd, 0x1ce, 0x5, 
    0x3e, 0x20, 0x2, 0x1ce, 0x1d1, 0x5, 0x24, 0x13, 0x2, 0x1cf, 0x1d0, 0x7, 
    0x38, 0x2, 0x2, 0x1d0, 0x1d2, 0x5, 0x48, 0x25, 0x2, 0x1d1, 0x1cf, 0x3, 
    0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x3, 
    0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x7, 0x4c, 0x2, 0x2, 0x1d4, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x1d5, 0x1dc, 0x7, 0x3d, 0x2, 0x2, 0x1d6, 0x1dc, 0x7, 
    0x3e, 0x2, 0x2, 0x1d7, 0x1dc, 0x7, 0x3f, 0x2, 0x2, 0x1d8, 0x1dc, 0x7, 
    0x35, 0x2, 0x2, 0x1d9, 0x1dc, 0x7, 0x36, 0x2, 0x2, 0x1da, 0x1dc, 0x5, 
    0x24, 0x13, 0x2, 0x1db, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d6, 0x3, 
    0x2, 0x2, 0x2, 0x1db, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d8, 0x3, 
    0x2, 0x2, 0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1da, 0x3, 
    0x2, 0x2, 0x2, 0x1dc, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x5, 0x66, 
    0x34, 0x2, 0x1de, 0x1df, 0x5, 0x24, 0x13, 0x2, 0x1df, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x1e0, 0x1e3, 0x5, 0x68, 0x35, 0x2, 0x1e1, 0x1e3, 0x3, 0x2, 
    0x2, 0x2, 0x1e2, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e1, 0x3, 0x2, 
    0x2, 0x2, 0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x5, 0x24, 
    0x13, 0x2, 0x1e5, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x7, 0x25, 
    0x2, 0x2, 0x1e7, 0x1e8, 0x5, 0x24, 0x13, 0x2, 0x1e8, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x1e9, 0x1ea, 0x5, 0x4c, 0x27, 0x2, 0x1ea, 0x1eb, 0x7, 0x38, 
    0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x80, 0x41, 0x2, 0x1ec, 0x1ed, 0x7, 0x4c, 
    0x2, 0x2, 0x1ed, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x5, 0x3e, 
    0x20, 0x2, 0x1ef, 0x1f3, 0x5, 0x24, 0x13, 0x2, 0x1f0, 0x1f1, 0x7, 0x38, 
    0x2, 0x2, 0x1f1, 0x1f4, 0x5, 0x80, 0x41, 0x2, 0x1f2, 0x1f4, 0x3, 0x2, 
    0x2, 0x2, 0x1f3, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f2, 0x3, 0x2, 
    0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x7, 0x4c, 
    0x2, 0x2, 0x1f6, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x26, 
    0x2, 0x2, 0x1f8, 0x1fb, 0x5, 0x30, 0x19, 0x2, 0x1f9, 0x1fc, 0x5, 0x4e, 
    0x28, 0x2, 0x1fa, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1f9, 0x3, 0x2, 
    0x2, 0x2, 0x1fb, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x3, 0x2, 
    0x2, 0x2, 0x1fd, 0x1fe, 0x7, 0x4c, 0x2, 0x2, 0x1fe, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x1ff, 0x202, 0x5, 0x50, 0x29, 0x2, 0x200, 0x202, 0x5, 0x54, 
    0x2b, 0x2, 0x201, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x201, 0x200, 0x3, 0x2, 
    0x2, 0x2, 0x202, 0x57, 0x3, 0x2, 0x2, 0x2, 0x203, 0x207, 0x7, 0x45, 
    0x2, 0x2, 0x204, 0x206, 0x5, 0x56, 0x2c, 0x2, 0x205, 0x204, 0x3, 0x2, 
    0x2, 0x2, 0x206, 0x209, 0x3, 0x2, 0x2, 0x2, 0x207, 0x205, 0x3, 0x2, 
    0x2, 0x2, 0x207, 0x208, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20a, 0x3, 0x2, 
    0x2, 0x2, 0x209, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x7, 0x46, 
    0x2, 0x2, 0x20b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x7, 0x21, 
    0x2, 0x2, 0x20d, 0x21c, 0x5, 0x24, 0x13, 0x2, 0x20e, 0x218, 0x7, 0x43, 
    0x2, 0x2, 0x20f, 0x214, 0x5, 0x5c, 0x2f, 0x2, 0x210, 0x211, 0x7, 0x4d, 
    0x2, 0x2, 0x211, 0x213, 0x5, 0x5c, 0x2f, 0x2, 0x212, 0x210, 0x3, 0x2, 
    0x2, 0x2, 0x213, 0x216, 0x3, 0x2, 0x2, 0x2, 0x214, 0x212, 0x3, 0x2, 
    0x2, 0x2, 0x214, 0x215, 0x3, 0x2, 0x2, 0x2, 0x215, 0x219, 0x3, 0x2, 
    0x2, 0x2, 0x216, 0x214, 0x3, 0x2, 0x2, 0x2, 0x217, 0x219, 0x3, 0x2, 
    0x2, 0x2, 0x218, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x218, 0x217, 0x3, 0x2, 
    0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21d, 0x7, 0x44, 
    0x2, 0x2, 0x21b, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x20e, 0x3, 0x2, 
    0x2, 0x2, 0x21c, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 0x3, 0x2, 
    0x2, 0x2, 0x21e, 0x21f, 0x7, 0x4c, 0x2, 0x2, 0x21f, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x220, 0x221, 0x5, 0x3e, 0x20, 0x2, 0x221, 0x222, 0x5, 0x24, 
    0x13, 0x2, 0x222, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x7, 0x27, 
    0x2, 0x2, 0x224, 0x225, 0x5, 0x3e, 0x20, 0x2, 0x225, 0x226, 0x5, 0x6e, 
    0x38, 0x2, 0x226, 0x229, 0x7, 0x43, 0x2, 0x2, 0x227, 0x22a, 0x5, 0x60, 
    0x31, 0x2, 0x228, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x229, 0x227, 0x3, 0x2, 
    0x2, 0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x3, 0x2, 
    0x2, 0x2, 0x22b, 0x22c, 0x7, 0x44, 0x2, 0x2, 0x22c, 0x22d, 0x5, 0x76, 
    0x3c, 0x2, 0x22d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x233, 0x5, 0x5c, 
    0x2f, 0x2, 0x22f, 0x230, 0x7, 0x4d, 0x2, 0x2, 0x230, 0x232, 0x5, 0x5c, 
    0x2f, 0x2, 0x231, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x232, 0x235, 0x3, 0x2, 
    0x2, 0x2, 0x233, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 
    0x2, 0x2, 0x234, 0x61, 0x3, 0x2, 0x2, 0x2, 0x235, 0x233, 0x3, 0x2, 0x2, 
    0x2, 0x236, 0x23c, 0x5, 0x48, 0x25, 0x2, 0x237, 0x23c, 0x5, 0x4a, 0x26, 
    0x2, 0x238, 0x23c, 0x5, 0x4c, 0x27, 0x2, 0x239, 0x23c, 0x5, 0x26, 0x14, 
    0x2, 0x23a, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x236, 0x3, 0x2, 0x2, 
    0x2, 0x23b, 0x237, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x238, 0x3, 0x2, 0x2, 
    0x2, 0x23b, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23a, 0x3, 0x2, 0x2, 
    0x2, 0x23c, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x5, 0x64, 0x33, 
    0x2, 0x23e, 0x63, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x4d, 0x2, 
    0x2, 0x240, 0x243, 0x5, 0x62, 0x32, 0x2, 0x241, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x242, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x242, 0x241, 0x3, 0x2, 0x2, 
    0x2, 0x243, 0x65, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x9, 0x6, 0x2, 0x2, 
    0x245, 0x246, 0x7, 0x4f, 0x2, 0x2, 0x246, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x247, 0x248, 0x7, 0x1a, 0x2, 0x2, 0x248, 0x249, 0x7, 0x4f, 0x2, 0x2, 
    0x249, 0x69, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24b, 0x7, 0x22, 0x2, 0x2, 
    0x24b, 0x250, 0x5, 0x24, 0x13, 0x2, 0x24c, 0x24d, 0x7, 0x4d, 0x2, 0x2, 
    0x24d, 0x24f, 0x5, 0x24, 0x13, 0x2, 0x24e, 0x24c, 0x3, 0x2, 0x2, 0x2, 
    0x24f, 0x252, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 0x2, 0x2, 0x2, 
    0x250, 0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 0x253, 0x3, 0x2, 0x2, 0x2, 
    0x252, 0x250, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 0x4c, 0x2, 0x2, 
    0x254, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x7, 0x10, 0x2, 0x2, 
    0x256, 0x257, 0x7, 0x4b, 0x2, 0x2, 0x257, 0x258, 0x5, 0x24, 0x13, 0x2, 
    0x258, 0x259, 0x7, 0x4c, 0x2, 0x2, 0x259, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x25a, 0x25f, 0x5, 0x24, 0x13, 0x2, 0x25b, 0x25c, 0x7, 0x4f, 0x2, 0x2, 
    0x25c, 0x25e, 0x5, 0x24, 0x13, 0x2, 0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x261, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x25d, 0x3, 0x2, 0x2, 0x2, 
    0x25f, 0x260, 0x3, 0x2, 0x2, 0x2, 0x260, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x261, 
    0x25f, 0x3, 0x2, 0x2, 0x2, 0x262, 0x265, 0x5, 0x72, 0x3a, 0x2, 0x263, 
    0x265, 0x5, 0x76, 0x3c, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 0x264, 
    0x263, 0x3, 0x2, 0x2, 0x2, 0x265, 0x71, 0x3, 0x2, 0x2, 0x2, 0x266, 0x26f, 
    0x5, 0x74, 0x3b, 0x2, 0x267, 0x26f, 0x5, 0x50, 0x29, 0x2, 0x268, 0x26f, 
    0x5, 0x8c, 0x47, 0x2, 0x269, 0x26f, 0x5, 0x84, 0x43, 0x2, 0x26a, 0x26f, 
    0x5, 0x52, 0x2a, 0x2, 0x26b, 0x26f, 0x5, 0x54, 0x2b, 0x2, 0x26c, 0x26f, 
    0x5, 0x7a, 0x3e, 0x2, 0x26d, 0x26f, 0x5, 0x78, 0x3d, 0x2, 0x26e, 0x266, 
    0x3, 0x2, 0x2, 0x2, 0x26e, 0x267, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x268, 
    0x3, 0x2, 0x2, 0x2, 0x26e, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26a, 
    0x3, 0x2, 0x2, 0x2, 0x26e, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26c, 
    0x3, 0x2, 0x2, 0x2, 0x26e, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x270, 0x271, 0x5, 0x26, 0x14, 0x2, 0x271, 0x272, 0x7, 
    0x4c, 0x2, 0x2, 0x272, 0x75, 0x3, 0x2, 0x2, 0x2, 0x273, 0x277, 0x7, 
    0x45, 0x2, 0x2, 0x274, 0x276, 0x5, 0x72, 0x3a, 0x2, 0x275, 0x274, 0x3, 
    0x2, 0x2, 0x2, 0x276, 0x279, 0x3, 0x2, 0x2, 0x2, 0x277, 0x275, 0x3, 
    0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 0x278, 0x27a, 0x3, 
    0x2, 0x2, 0x2, 0x279, 0x277, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 0x7, 
    0x46, 0x2, 0x2, 0x27b, 0x77, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x7, 
    0x1b, 0x2, 0x2, 0x27d, 0x27e, 0x5, 0x7c, 0x3f, 0x2, 0x27e, 0x27f, 0x7, 
    0x4c, 0x2, 0x2, 0x27f, 0x79, 0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 0x7, 
    0x37, 0x2, 0x2, 0x281, 0x282, 0x7, 0x4c, 0x2, 0x2, 0x282, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x283, 0x284, 0x5, 0x94, 0x4b, 0x2, 0x284, 0x285, 0x5, 
    0x7e, 0x40, 0x2, 0x285, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x7, 
    0x43, 0x2, 0x2, 0x287, 0x288, 0x5, 0x7c, 0x3f, 0x2, 0x288, 0x289, 0x7, 
    0x44, 0x2, 0x2, 0x289, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 0x7, 
    0x51, 0x2, 0x2, 0x28b, 0x28f, 0x5, 0x7c, 0x3f, 0x2, 0x28c, 0x28d, 0x7, 
    0x2f, 0x2, 0x2, 0x28d, 0x28f, 0x5, 0x7c, 0x3f, 0x2, 0x28e, 0x283, 0x3, 
    0x2, 0x2, 0x2, 0x28e, 0x286, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28a, 0x3, 
    0x2, 0x2, 0x2, 0x28e, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x290, 0x291, 0x9, 0x7, 0x2, 0x2, 0x291, 0x294, 0x5, 0x7c, 
    0x3f, 0x2, 0x292, 0x294, 0x3, 0x2, 0x2, 0x2, 0x293, 0x290, 0x3, 0x2, 
    0x2, 0x2, 0x293, 0x292, 0x3, 0x2, 0x2, 0x2, 0x294, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x296, 0x7, 0x43, 0x2, 0x2, 0x296, 0x297, 0x5, 0x80, 0x41, 
    0x2, 0x297, 0x298, 0x7, 0x44, 0x2, 0x2, 0x298, 0x299, 0x5, 0x82, 0x42, 
    0x2, 0x299, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x2f, 0x2, 
    0x2, 0x29b, 0x2a4, 0x5, 0x80, 0x41, 0x2, 0x29c, 0x29d, 0x7, 0x32, 0x2, 
    0x2, 0x29d, 0x2a4, 0x5, 0x80, 0x41, 0x2, 0x29e, 0x29f, 0x7, 0x51, 0x2, 
    0x2, 0x29f, 0x2a4, 0x5, 0x80, 0x41, 0x2, 0x2a0, 0x2a1, 0x5, 0x7c, 0x3f, 
    0x2, 0x2a1, 0x2a2, 0x5, 0x82, 0x42, 0x2, 0x2a2, 0x2a4, 0x3, 0x2, 0x2, 
    0x2, 0x2a3, 0x295, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x29a, 0x3, 0x2, 0x2, 
    0x2, 0x2a3, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x29e, 0x3, 0x2, 0x2, 
    0x2, 0x2a3, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x2a5, 0x2b9, 0x7, 0x31, 0x2, 0x2, 0x2a6, 0x2b9, 0x7, 0x34, 0x2, 0x2, 
    0x2a7, 0x2b9, 0x7, 0x30, 0x2, 0x2, 0x2a8, 0x2b9, 0x7, 0x33, 0x2, 0x2, 
    0x2a9, 0x2aa, 0x7, 0x38, 0x2, 0x2, 0x2aa, 0x2b9, 0x7, 0x38, 0x2, 0x2, 
    0x2ab, 0x2ac, 0x7, 0x2f, 0x2, 0x2, 0x2ac, 0x2b9, 0x7, 0x38, 0x2, 0x2, 
    0x2ad, 0x2b9, 0x7, 0x32, 0x2, 0x2, 0x2ae, 0x2b1, 0x7, 0x49, 0x2, 0x2, 
    0x2af, 0x2b2, 0x7, 0x38, 0x2, 0x2, 0x2b0, 0x2b2, 0x3, 0x2, 0x2, 0x2, 
    0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b0, 0x3, 0x2, 0x2, 0x2, 
    0x2b2, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b6, 0x7, 0x4a, 0x2, 0x2, 
    0x2b4, 0x2b7, 0x7, 0x38, 0x2, 0x2, 0x2b5, 0x2b7, 0x3, 0x2, 0x2, 0x2, 
    0x2b6, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b5, 0x3, 0x2, 0x2, 0x2, 
    0x2b7, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2a5, 0x3, 0x2, 0x2, 0x2, 
    0x2b8, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2a7, 0x3, 0x2, 0x2, 0x2, 
    0x2b8, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2a9, 0x3, 0x2, 0x2, 0x2, 
    0x2b8, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2ad, 0x3, 0x2, 0x2, 0x2, 
    0x2b8, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b3, 0x3, 0x2, 0x2, 0x2, 
    0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bd, 0x5, 0x80, 0x41, 0x2, 
    0x2bb, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2b8, 0x3, 0x2, 0x2, 0x2, 
    0x2bc, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x83, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2c1, 0x5, 0x86, 0x44, 0x2, 0x2bf, 0x2c2, 0x5, 0x8a, 0x46, 0x2, 0x2c0, 
    0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2c1, 
    0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 
    0x7, 0x2b, 0x2, 0x2, 0x2c4, 0x2c7, 0x5, 0x88, 0x45, 0x2, 0x2c5, 0x2c8, 
    0x5, 0x70, 0x39, 0x2, 0x2c6, 0x2c8, 0x7, 0x4c, 0x2, 0x2, 0x2c7, 0x2c5, 
    0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0x43, 0x2, 0x2, 0x2ca, 0x2cb, 0x5, 
    0x80, 0x41, 0x2, 0x2cb, 0x2cc, 0x7, 0x44, 0x2, 0x2, 0x2cc, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x7, 0x2c, 0x2, 0x2, 0x2ce, 0x2cf, 0x5, 
    0x70, 0x39, 0x2, 0x2cf, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x7, 
    0x28, 0x2, 0x2, 0x2d1, 0x2d2, 0x5, 0x8e, 0x48, 0x2, 0x2d2, 0x2d6, 0x7, 
    0x45, 0x2, 0x2, 0x2d3, 0x2d5, 0x5, 0x90, 0x49, 0x2, 0x2d4, 0x2d3, 0x3, 
    0x2, 0x2, 0x2, 0x2d5, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d4, 0x3, 
    0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2db, 0x3, 
    0x2, 0x2, 0x2, 0x2d8, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2dc, 0x5, 
    0x92, 0x4a, 0x2, 0x2da, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2d9, 0x3, 
    0x2, 0x2, 0x2, 0x2db, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0x3, 
    0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x7, 0x46, 0x2, 0x2, 0x2de, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 0x43, 0x2, 0x2, 0x2e0, 0x2e1, 0x5, 
    0x24, 0x13, 0x2, 0x2e1, 0x2e2, 0x7, 0x44, 0x2, 0x2, 0x2e2, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0x29, 0x2, 0x2, 0x2e4, 0x2e5, 0x5, 
    0x48, 0x25, 0x2, 0x2e5, 0x2ed, 0x7, 0x4b, 0x2, 0x2, 0x2e6, 0x2ee, 0x5, 
    0x76, 0x3c, 0x2, 0x2e7, 0x2e9, 0x5, 0x72, 0x3a, 0x2, 0x2e8, 0x2e7, 0x3, 
    0x2, 0x2, 0x2, 0x2e9, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2e8, 0x3, 
    0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ee, 0x3, 
    0x2, 0x2, 0x2, 0x2ec, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2e6, 0x3, 
    0x2, 0x2, 0x2, 0x2ed, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x2ef, 0x2f0, 0x7, 0x2a, 0x2, 0x2, 0x2f0, 0x2f8, 0x7, 0x4b, 
    0x2, 0x2, 0x2f1, 0x2f9, 0x5, 0x76, 0x3c, 0x2, 0x2f2, 0x2f4, 0x5, 0x72, 
    0x3a, 0x2, 0x2f3, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f7, 0x3, 0x2, 
    0x2, 0x2, 0x2f5, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f6, 0x3, 0x2, 
    0x2, 0x2, 0x2f6, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f5, 0x3, 0x2, 
    0x2, 0x2, 0x2f8, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f5, 0x3, 0x2, 
    0x2, 0x2, 0x2f9, 0x93, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2ff, 0x5, 0x4a, 
    0x26, 0x2, 0x2fb, 0x2ff, 0x5, 0x4c, 0x27, 0x2, 0x2fc, 0x2ff, 0x5, 0x26, 
    0x14, 0x2, 0x2fd, 0x2ff, 0x5, 0x48, 0x25, 0x2, 0x2fe, 0x2fa, 0x3, 0x2, 
    0x2, 0x2, 0x2fe, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fc, 0x3, 0x2, 
    0x2, 0x2, 0x2fe, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0xb8, 0xd1, 0xd7, 0xdc, 0xde, 0xfa, 0x101, 0x104, 0x122, 
    0x128, 0x131, 0x14f, 0x160, 0x168, 0x171, 0x174, 0x17e, 0x180, 0x187, 
    0x19a, 0x19f, 0x1ac, 0x1b5, 0x1be, 0x1c7, 0x1d1, 0x1db, 0x1e2, 0x1f3, 
    0x1fb, 0x201, 0x207, 0x214, 0x218, 0x21c, 0x229, 0x233, 0x23b, 0x242, 
    0x250, 0x25f, 0x264, 0x26e, 0x277, 0x28e, 0x293, 0x2a3, 0x2b1, 0x2b6, 
    0x2b8, 0x2bc, 0x2c1, 0x2c7, 0x2d6, 0x2db, 0x2ea, 0x2ed, 0x2f5, 0x2f8, 
    0x2fe, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TestCaseDeclParser::Initializer TestCaseDeclParser::_init;
