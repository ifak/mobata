
// Generated from C:/Users/j05kraus/Private/SWDevelop/mbtcreator/3rd/jkra_mobata_oss/libs/dslparser/dslparser/grammars/TestCaseDecl.g4 by ANTLR 4.7.2


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
    setState(144);
    importPathDecl();
    setState(145);
    match(TestCaseDeclParser::TestCaseID);
    setState(146);
    match(TestCaseDeclParser::LBRACE);
    setState(147);
    testCaseBody();
    setState(148);
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
    setState(150);
    match(TestCaseDeclParser::DeclarationID);
    setState(151);
    match(TestCaseDeclParser::LBRACE);
    setState(152);
    declarations();
    setState(153);
    match(TestCaseDeclParser::RBRACE);
    setState(154);
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
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(156);
        attributeDecl();
        setState(157);
        declarations();
        break;
      }

      case TestCaseDeclParser::NameID: {
        enterOuterAlt(_localctx, 2);
        setState(159);
        nameDecl();
        setState(160);
        declarations();
        break;
      }

      case TestCaseDeclParser::EnabledID: {
        enterOuterAlt(_localctx, 3);
        setState(162);
        enabledDecl();
        setState(163);
        declarations();
        break;
      }

      case TestCaseDeclParser::SignalID: {
        enterOuterAlt(_localctx, 4);
        setState(165);
        signalDecl();
        setState(166);
        declarations();
        break;
      }

      case TestCaseDeclParser::CheckID: {
        enterOuterAlt(_localctx, 5);
        setState(168);
        checkDecl();
        setState(169);
        declarations();
        break;
      }

      case TestCaseDeclParser::ComponentID: {
        enterOuterAlt(_localctx, 6);
        setState(171);
        aliasDef();
        setState(172);
        declarations();
        break;
      }

      case TestCaseDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 7);

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
    setState(177);
    match(TestCaseDeclParser::ComponentID);
    setState(178);
    idPath();
    setState(179);
    match(TestCaseDeclParser::AsID);
    setState(180);
    contextID();
    setState(181);
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
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimerID: {
        enterOuterAlt(_localctx, 1);
        setState(183);
        timerDecl();
        setState(184);
        steps();
        break;
      }

      case TestCaseDeclParser::MessageID: {
        enterOuterAlt(_localctx, 2);
        setState(186);
        messageDecl();
        setState(187);
        steps();
        break;
      }

      case TestCaseDeclParser::CheckID: {
        enterOuterAlt(_localctx, 3);
        setState(189);
        checkDecl();
        setState(190);
        steps();
        break;
      }

      case TestCaseDeclParser::AltID: {
        enterOuterAlt(_localctx, 4);
        setState(192);
        altDecl();
        setState(193);
        steps();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
        setState(195);
        idStatement();
        setState(196);
        match(TestCaseDeclParser::SEMI);
        setState(197);
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
    setState(213);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ThisID: {
        enterOuterAlt(_localctx, 1);
        setState(202);
        thisDecl();
        setState(203);
        idPath();
        setState(206);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::ASSIGN: {
            setState(204);
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
        setState(208);
        idPath();
        setState(211);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::ASSIGN: {
            setState(209);
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
    setState(215);
    match(TestCaseDeclParser::ASSIGN);
    setState(216);
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
    setState(218);
    match(TestCaseDeclParser::MessageID);
    setState(219);
    match(TestCaseDeclParser::LPAREN);
    setState(220);
    idPath();
    setState(221);
    match(TestCaseDeclParser::RightArrow);
    setState(222);
    idPath();
    setState(223);
    match(TestCaseDeclParser::RPAREN);
    setState(224);
    match(TestCaseDeclParser::COLON);
    setState(225);
    functionCall();
    setState(226);
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

TestCaseDeclParser::ContextIDContext* TestCaseDeclParser::CheckDeclContext::contextID() {
  return getRuleContext<TestCaseDeclParser::ContextIDContext>(0);
}

TestCaseDeclParser::CheckDeclBodyContext* TestCaseDeclParser::CheckDeclContext::checkDeclBody() {
  return getRuleContext<TestCaseDeclParser::CheckDeclBodyContext>(0);
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
    setState(228);
    match(TestCaseDeclParser::CheckID);
    setState(229);
    match(TestCaseDeclParser::LPAREN);
    setState(230);
    idPath();
    setState(231);
    match(TestCaseDeclParser::RightArrow);
    setState(232);
    idPath();
    setState(233);
    match(TestCaseDeclParser::RPAREN);
    setState(234);
    match(TestCaseDeclParser::COLON);
    setState(235);
    contextID();
    setState(236);
    checkDeclBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckDeclBodyContext ------------------------------------------------------------------

TestCaseDeclParser::CheckDeclBodyContext::CheckDeclBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclBodyContext::LBRACKET() {
  return getToken(TestCaseDeclParser::LBRACKET, 0);
}

TestCaseDeclParser::ExpressionContext* TestCaseDeclParser::CheckDeclBodyContext::expression() {
  return getRuleContext<TestCaseDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclBodyContext::RBRACKET() {
  return getToken(TestCaseDeclParser::RBRACKET, 0);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclBodyContext::COMMA() {
  return getToken(TestCaseDeclParser::COMMA, 0);
}

TestCaseDeclParser::TimeOutDeclContext* TestCaseDeclParser::CheckDeclBodyContext::timeOutDecl() {
  return getRuleContext<TestCaseDeclParser::TimeOutDeclContext>(0);
}

tree::TerminalNode* TestCaseDeclParser::CheckDeclBodyContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
}


size_t TestCaseDeclParser::CheckDeclBodyContext::getRuleIndex() const {
  return TestCaseDeclParser::RuleCheckDeclBody;
}

void TestCaseDeclParser::CheckDeclBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckDeclBody(this);
}

void TestCaseDeclParser::CheckDeclBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TestCaseDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckDeclBody(this);
}

TestCaseDeclParser::CheckDeclBodyContext* TestCaseDeclParser::checkDeclBody() {
  CheckDeclBodyContext *_localctx = _tracker.createInstance<CheckDeclBodyContext>(_ctx, getState());
  enterRule(_localctx, 18, TestCaseDeclParser::RuleCheckDeclBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(TestCaseDeclParser::LBRACKET);
    setState(239);
    expression();
    setState(240);
    match(TestCaseDeclParser::RBRACKET);
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::COMMA: {
        setState(241);
        match(TestCaseDeclParser::COMMA);
        setState(242);
        timeOutDecl();
        break;
      }

      case TestCaseDeclParser::SEMI: {
        setState(243);
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
  enterRule(_localctx, 20, TestCaseDeclParser::RuleTimerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(TestCaseDeclParser::TimerID);
    setState(247);
    match(TestCaseDeclParser::AtID);
    setState(248);
    idPath();
    setState(249);
    contextID();
    setState(250);
    match(TestCaseDeclParser::ASSIGN);
    setState(251);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::INT

    || _la == TestCaseDeclParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(252);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::MilliSekID

    || _la == TestCaseDeclParser::SekID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(253);
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

tree::TerminalNode* TestCaseDeclParser::TimeOutDeclContext::SEMI() {
  return getToken(TestCaseDeclParser::SEMI, 0);
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
  enterRule(_localctx, 22, TestCaseDeclParser::RuleTimeOutDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(TestCaseDeclParser::TimeOutID);
    setState(256);
    match(TestCaseDeclParser::COLON);
    setState(257);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::INT

    || _la == TestCaseDeclParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(258);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::MilliSekID

    || _la == TestCaseDeclParser::SekID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(259);
    match(TestCaseDeclParser::SEMI);
   
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
    setState(261);
    match(TestCaseDeclParser::AltID);
    setState(262);
    match(TestCaseDeclParser::LBRACE);
    setState(263);
    altBodyOptional();
    setState(264);
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
    setState(266);
    match(TestCaseDeclParser::LBRACKET);
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
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
        setState(267);
        expression();
        break;
      }

      case TestCaseDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(271);
    match(TestCaseDeclParser::RBRACKET);
    setState(272);
    match(TestCaseDeclParser::LBRACE);
    setState(275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(273);
      checkDecl();
      break;
    }

    case 2: {
      break;
    }

    }
    setState(277);
    steps();
    setState(278);
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
    setState(284);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(280);
        altBody();
        setState(281);
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
  enterRule(_localctx, 30, TestCaseDeclParser::RuleEnabledDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(TestCaseDeclParser::EnabledID);
    setState(287);
    match(TestCaseDeclParser::COLON);
    setState(288);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::TrueID

    || _la == TestCaseDeclParser::FalseID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(289);
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
  enterRule(_localctx, 32, TestCaseDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(291);
        match(TestCaseDeclParser::ID);
        break;
      }

      case TestCaseDeclParser::NameID: {
        enterOuterAlt(_localctx, 2);
        setState(292);
        match(TestCaseDeclParser::NameID);
        break;
      }

      case TestCaseDeclParser::LabelID: {
        enterOuterAlt(_localctx, 3);
        setState(293);
        match(TestCaseDeclParser::LabelID);
        break;
      }

      case TestCaseDeclParser::EnabledID: {
        enterOuterAlt(_localctx, 4);
        setState(294);
        match(TestCaseDeclParser::EnabledID);
        break;
      }

      case TestCaseDeclParser::TypeID: {
        enterOuterAlt(_localctx, 5);
        setState(295);
        match(TestCaseDeclParser::TypeID);
        break;
      }

      case TestCaseDeclParser::TriggerID:
      case TestCaseDeclParser::MessageTrigger: {
        enterOuterAlt(_localctx, 6);
        setState(296);
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
        enterOuterAlt(_localctx, 7);
        setState(297);
        match(TestCaseDeclParser::AttributeID);
        break;
      }

      case TestCaseDeclParser::SignalID: {
        enterOuterAlt(_localctx, 8);
        setState(298);
        match(TestCaseDeclParser::SignalID);
        break;
      }

      case TestCaseDeclParser::PortID: {
        enterOuterAlt(_localctx, 9);
        setState(299);
        match(TestCaseDeclParser::PortID);
        break;
      }

      case TestCaseDeclParser::ImportID: {
        enterOuterAlt(_localctx, 10);
        setState(300);
        match(TestCaseDeclParser::ImportID);
        break;
      }

      case TestCaseDeclParser::FromID: {
        enterOuterAlt(_localctx, 11);
        setState(301);
        match(TestCaseDeclParser::FromID);
        break;
      }

      case TestCaseDeclParser::ToID: {
        enterOuterAlt(_localctx, 12);
        setState(302);
        match(TestCaseDeclParser::ToID);
        break;
      }

      case TestCaseDeclParser::SendID: {
        enterOuterAlt(_localctx, 13);
        setState(303);
        match(TestCaseDeclParser::SendID);
        break;
      }

      case TestCaseDeclParser::AsID: {
        enterOuterAlt(_localctx, 14);
        setState(304);
        match(TestCaseDeclParser::AsID);
        break;
      }

      case TestCaseDeclParser::TimeOutID: {
        enterOuterAlt(_localctx, 15);
        setState(305);
        match(TestCaseDeclParser::TimeOutID);
        break;
      }

      case TestCaseDeclParser::ComponentID: {
        enterOuterAlt(_localctx, 16);
        setState(306);
        match(TestCaseDeclParser::ComponentID);
        break;
      }

      case TestCaseDeclParser::DeclarationID: {
        enterOuterAlt(_localctx, 17);
        setState(307);
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
  enterRule(_localctx, 34, TestCaseDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    idPath();
    setState(311);
    match(TestCaseDeclParser::LPAREN);
    setState(312);
    functionCallBody();
    setState(313);
    match(TestCaseDeclParser::RPAREN);
   
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
  enterRule(_localctx, 36, TestCaseDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    contextID();
    setState(320);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::DOT) {
      setState(316);
      match(TestCaseDeclParser::DOT);
      setState(317);
      contextID();
      setState(322);
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
  enterRule(_localctx, 38, TestCaseDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    contextID();
    setState(328);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::DOT) {
      setState(324);
      match(TestCaseDeclParser::DOT);
      setState(325);
      contextID();
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
  enterRule(_localctx, 40, TestCaseDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(340);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(331);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(332);
      contextID();
      setState(337);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TestCaseDeclParser::DOT) {
        setState(333);
        match(TestCaseDeclParser::DOT);
        setState(334);
        contextID();
        setState(339);
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
  enterRule(_localctx, 42, TestCaseDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    signalIdPath();
    setState(343);
    match(TestCaseDeclParser::LPAREN);
    setState(344);
    functionCallBody();
    setState(345);
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
  enterRule(_localctx, 44, TestCaseDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TypeID)
      | (1ULL << TestCaseDeclParser::AttributeID)
      | (1ULL << TestCaseDeclParser::SignalID))) != 0)) {
      setState(350);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TestCaseDeclParser::TypeID: {
          setState(347);
          typeDefDecl();
          break;
        }

        case TestCaseDeclParser::AttributeID: {
          setState(348);
          attributeDecl();
          break;
        }

        case TestCaseDeclParser::SignalID: {
          setState(349);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(354);
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
  enterRule(_localctx, 46, TestCaseDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(359);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ImportID: {
        enterOuterAlt(_localctx, 1);
        setState(355);
        importPathBody();
        setState(356);
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
  enterRule(_localctx, 48, TestCaseDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(TestCaseDeclParser::ImportID);
    setState(362);
    match(TestCaseDeclParser::LESSTHAN);
    setState(363);
    importFileBody();
    setState(364);
    match(TestCaseDeclParser::GREATERTHAN);
    setState(365);
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
  enterRule(_localctx, 50, TestCaseDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(378);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(367);
      contextID();
      setState(368);
      match(TestCaseDeclParser::DOT);
      setState(369);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(371);
      match(TestCaseDeclParser::RANGE);
      setState(372);
      match(TestCaseDeclParser::DIV);
      setState(373);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(374);
      contextID();
      setState(375);
      match(TestCaseDeclParser::DIV);
      setState(376);
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
  enterRule(_localctx, 52, TestCaseDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(383);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(380);
        match(TestCaseDeclParser::AsID);
        setState(381);
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
  enterRule(_localctx, 54, TestCaseDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    match(TestCaseDeclParser::TypeID);
    setState(386);
    typeDecl();
    setState(387);
    contextID();
    setState(388);
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
  enterRule(_localctx, 56, TestCaseDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(396);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(390);
        intTypeDecl();
        break;
      }

      case TestCaseDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(391);
        realTypeDecl();
        break;
      }

      case TestCaseDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(392);
        enumTypeDecl();
        break;
      }

      case TestCaseDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(393);
        match(TestCaseDeclParser::BoolID);
        break;
      }

      case TestCaseDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(394);
        match(TestCaseDeclParser::StringID);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
        setState(395);
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
  enterRule(_localctx, 58, TestCaseDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    match(TestCaseDeclParser::IntID);
    setState(405);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LPAREN: {
        setState(399);
        match(TestCaseDeclParser::LPAREN);
        setState(400);
        match(TestCaseDeclParser::INT);
        setState(401);
        match(TestCaseDeclParser::RANGE);
        setState(402);
        match(TestCaseDeclParser::INT);
        setState(403);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
  enterRule(_localctx, 60, TestCaseDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(TestCaseDeclParser::RealID);
    setState(414);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LPAREN: {
        setState(408);
        match(TestCaseDeclParser::LPAREN);
        setState(409);
        match(TestCaseDeclParser::REAL);
        setState(410);
        match(TestCaseDeclParser::RANGE);
        setState(411);
        match(TestCaseDeclParser::REAL);
        setState(412);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
  enterRule(_localctx, 62, TestCaseDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(TestCaseDeclParser::EnumID);
    setState(417);
    match(TestCaseDeclParser::LPAREN);
    setState(418);
    contextID();
    setState(423);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::COMMA) {
      setState(419);
      match(TestCaseDeclParser::COMMA);
      setState(420);
      contextID();
      setState(425);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(426);
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
  enterRule(_localctx, 64, TestCaseDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(TestCaseDeclParser::AttributeID);
    setState(429);
    typeDecl();
    setState(430);
    contextID();
    setState(433);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TestCaseDeclParser::ASSIGN) {
      setState(431);
      match(TestCaseDeclParser::ASSIGN);
      setState(432);
      literalValue();
    }
    setState(435);
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
  enterRule(_localctx, 66, TestCaseDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(443);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(437);
        match(TestCaseDeclParser::INT);
        break;
      }

      case TestCaseDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(438);
        match(TestCaseDeclParser::REAL);
        break;
      }

      case TestCaseDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(439);
        match(TestCaseDeclParser::STRING);
        break;
      }

      case TestCaseDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(440);
        match(TestCaseDeclParser::TrueID);
        break;
      }

      case TestCaseDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(441);
        match(TestCaseDeclParser::FalseID);
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
        setState(442);
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
  enterRule(_localctx, 68, TestCaseDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    triggerDecl();
    setState(446);
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
  enterRule(_localctx, 70, TestCaseDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(450);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ThisID: {
        setState(448);
        thisDecl();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
    setState(452);
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
  enterRule(_localctx, 72, TestCaseDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    match(TestCaseDeclParser::ToID);
    setState(455);
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
  enterRule(_localctx, 74, TestCaseDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    attributeName();
    setState(458);
    match(TestCaseDeclParser::ASSIGN);
    setState(459);
    expression();
    setState(460);
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
  enterRule(_localctx, 76, TestCaseDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    typeDecl();
    setState(463);
    contextID();
    setState(467);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ASSIGN: {
        setState(464);
        match(TestCaseDeclParser::ASSIGN);
        setState(465);
        expression();
        break;
      }

      case TestCaseDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(469);
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
  enterRule(_localctx, 78, TestCaseDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(471);
    match(TestCaseDeclParser::SendID);
    setState(472);
    signalSend();
    setState(475);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::ToID: {
        setState(473);
        toPortName();
        break;
      }

      case TestCaseDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(477);
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
  enterRule(_localctx, 80, TestCaseDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(481);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(479);
      attributeAssignStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(480);
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
  enterRule(_localctx, 82, TestCaseDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(483);
    match(TestCaseDeclParser::LBRACE);
    setState(487);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
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
      setState(484);
      singleAssignment();
      setState(489);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(490);
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
  enterRule(_localctx, 84, TestCaseDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(492);
    match(TestCaseDeclParser::SignalID);
    setState(493);
    contextID();
    setState(508);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LPAREN: {
        setState(494);
        match(TestCaseDeclParser::LPAREN);
        setState(504);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::TimeOutID:
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
            setState(495);
            paramDecl();
            setState(500);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TestCaseDeclParser::COMMA) {
              setState(496);
              match(TestCaseDeclParser::COMMA);
              setState(497);
              paramDecl();
              setState(502);
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
        setState(506);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(510);
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
  enterRule(_localctx, 86, TestCaseDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    typeDecl();
    setState(513);
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
  enterRule(_localctx, 88, TestCaseDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    match(TestCaseDeclParser::FunctionID);
    setState(516);
    typeDecl();
    setState(517);
    idPath();
    setState(518);
    match(TestCaseDeclParser::LPAREN);
    setState(521);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
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
        setState(519);
        functionParameters();
        break;
      }

      case TestCaseDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(523);
    match(TestCaseDeclParser::RPAREN);
    setState(524);
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
  enterRule(_localctx, 90, TestCaseDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    paramDecl();
    setState(531);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::COMMA) {
      setState(527);
      match(TestCaseDeclParser::COMMA);
      setState(528);
      paramDecl();
      setState(533);
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
  enterRule(_localctx, 92, TestCaseDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(539);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(534);
      literalValue();
      break;
    }

    case 2: {
      setState(535);
      signalParamName();
      break;
    }

    case 3: {
      setState(536);
      attributeName();
      break;
    }

    case 4: {
      setState(537);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(541);
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
  enterRule(_localctx, 94, TestCaseDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(546);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(543);
        match(TestCaseDeclParser::COMMA);
        setState(544);
        functionCallBody();
        break;
      }

      case TestCaseDeclParser::RPAREN: {
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
  enterRule(_localctx, 96, TestCaseDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(548);
    _la = _input->LA(1);
    if (!(_la == TestCaseDeclParser::TriggerID

    || _la == TestCaseDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(549);
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
  enterRule(_localctx, 98, TestCaseDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(551);
    match(TestCaseDeclParser::ThisID);
    setState(552);
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
  enterRule(_localctx, 100, TestCaseDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    match(TestCaseDeclParser::PortID);
    setState(555);
    contextID();
    setState(560);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::COMMA) {
      setState(556);
      match(TestCaseDeclParser::COMMA);
      setState(557);
      contextID();
      setState(562);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(563);
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
  enterRule(_localctx, 102, TestCaseDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    match(TestCaseDeclParser::NameID);
    setState(566);
    match(TestCaseDeclParser::COLON);
    setState(567);
    contextID();
    setState(568);
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
  enterRule(_localctx, 104, TestCaseDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    contextID();
    setState(575);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::DOT) {
      setState(571);
      match(TestCaseDeclParser::DOT);
      setState(572);
      contextID();
      setState(577);
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
  enterRule(_localctx, 106, TestCaseDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(580);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
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
        setState(578);
        statementBody();
        break;
      }

      case TestCaseDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(579);
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
  enterRule(_localctx, 108, TestCaseDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(590);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(582);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(583);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(584);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(585);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(586);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(587);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(588);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(589);
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
  enterRule(_localctx, 110, TestCaseDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(592);
    functionCall();
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
  enterRule(_localctx, 112, TestCaseDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
    match(TestCaseDeclParser::LBRACE);
    setState(599);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
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
      setState(596);
      statementBody();
      setState(601);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(602);
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
  enterRule(_localctx, 114, TestCaseDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    match(TestCaseDeclParser::ReturnID);
    setState(605);
    operation();
    setState(606);
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
  enterRule(_localctx, 116, TestCaseDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(608);
    match(TestCaseDeclParser::BREAK);
    setState(609);
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
  enterRule(_localctx, 118, TestCaseDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(622);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
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
        setState(611);
        atom();
        setState(612);
        operationOptional();
        break;
      }

      case TestCaseDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(614);
        match(TestCaseDeclParser::LPAREN);
        setState(615);
        operation();
        setState(616);
        match(TestCaseDeclParser::RPAREN);
        break;
      }

      case TestCaseDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(618);
        match(TestCaseDeclParser::MINUS);
        setState(619);
        operation();
        break;
      }

      case TestCaseDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(620);
        match(TestCaseDeclParser::NotIdSymbol);
        setState(621);
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
  enterRule(_localctx, 120, TestCaseDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(627);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::PLUS:
      case TestCaseDeclParser::MINUS:
      case TestCaseDeclParser::MULT:
      case TestCaseDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(624);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 76) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 76)) & ((1ULL << (TestCaseDeclParser::PLUS - 76))
          | (1ULL << (TestCaseDeclParser::MINUS - 76))
          | (1ULL << (TestCaseDeclParser::MULT - 76))
          | (1ULL << (TestCaseDeclParser::DIV - 76)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(625);
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
  enterRule(_localctx, 122, TestCaseDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(643);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(629);
      match(TestCaseDeclParser::LPAREN);
      setState(630);
      expression();
      setState(631);
      match(TestCaseDeclParser::RPAREN);
      setState(632);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(634);
      match(TestCaseDeclParser::NotIdSymbol);
      setState(635);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(636);
      match(TestCaseDeclParser::NotIdWord);
      setState(637);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(638);
      match(TestCaseDeclParser::MINUS);
      setState(639);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(640);
      operation();
      setState(641);
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
  enterRule(_localctx, 124, TestCaseDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(668);
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
        setState(664);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TestCaseDeclParser::OrIdSymbol: {
            setState(645);
            match(TestCaseDeclParser::OrIdSymbol);
            break;
          }

          case TestCaseDeclParser::OrIdWord: {
            setState(646);
            match(TestCaseDeclParser::OrIdWord);
            break;
          }

          case TestCaseDeclParser::AndIdSymbol: {
            setState(647);
            match(TestCaseDeclParser::AndIdSymbol);
            break;
          }

          case TestCaseDeclParser::AndIdWord: {
            setState(648);
            match(TestCaseDeclParser::AndIdWord);
            break;
          }

          case TestCaseDeclParser::ASSIGN: {
            setState(649);
            match(TestCaseDeclParser::ASSIGN);
            setState(650);
            match(TestCaseDeclParser::ASSIGN);
            break;
          }

          case TestCaseDeclParser::NotIdSymbol: {
            setState(651);
            match(TestCaseDeclParser::NotIdSymbol);
            setState(652);
            match(TestCaseDeclParser::ASSIGN);
            break;
          }

          case TestCaseDeclParser::NotIdWord: {
            setState(653);
            match(TestCaseDeclParser::NotIdWord);
            break;
          }

          case TestCaseDeclParser::LESSTHAN: {
            setState(654);
            match(TestCaseDeclParser::LESSTHAN);
            setState(657);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TestCaseDeclParser::ASSIGN: {
                setState(655);
                match(TestCaseDeclParser::ASSIGN);
                break;
              }

              case TestCaseDeclParser::TimeOutID:
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
            setState(659);
            match(TestCaseDeclParser::GREATERTHAN);
            setState(662);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TestCaseDeclParser::ASSIGN: {
                setState(660);
                match(TestCaseDeclParser::ASSIGN);
                break;
              }

              case TestCaseDeclParser::TimeOutID:
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
        setState(666);
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
  enterRule(_localctx, 126, TestCaseDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(670);
    ifStatement();
    setState(673);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(671);
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
  enterRule(_localctx, 128, TestCaseDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(675);
    match(TestCaseDeclParser::IfID);
    setState(676);
    ifEuT();
    setState(679);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::TimeOutID:
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
        setState(677);
        statementDecl();
        break;
      }

      case TestCaseDeclParser::SEMI: {
        setState(678);
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
  enterRule(_localctx, 130, TestCaseDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(681);
    match(TestCaseDeclParser::LPAREN);
    setState(682);
    expression();
    setState(683);
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
  enterRule(_localctx, 132, TestCaseDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(685);
    match(TestCaseDeclParser::ElseID);
    setState(686);
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
  enterRule(_localctx, 134, TestCaseDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(688);
    match(TestCaseDeclParser::SwitchID);
    setState(689);
    switchPuT();
    setState(690);
    match(TestCaseDeclParser::LBRACE);
    setState(694);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TestCaseDeclParser::CaseID) {
      setState(691);
      caseStatement();
      setState(696);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(699);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::DefaultID: {
        setState(697);
        defaultStatement();
        break;
      }

      case TestCaseDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(701);
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
  enterRule(_localctx, 136, TestCaseDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    match(TestCaseDeclParser::LPAREN);
    setState(704);
    contextID();
    setState(705);
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
  enterRule(_localctx, 138, TestCaseDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    match(TestCaseDeclParser::CaseID);
    setState(708);
    literalValue();
    setState(709);
    match(TestCaseDeclParser::COLON);
    setState(717);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LBRACE: {
        setState(710);
        nestedStatementBody();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
        setState(714);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
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
          setState(711);
          statementBody();
          setState(716);
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
  enterRule(_localctx, 140, TestCaseDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(719);
    match(TestCaseDeclParser::DefaultID);
    setState(720);
    match(TestCaseDeclParser::COLON);
    setState(728);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TestCaseDeclParser::LBRACE: {
        setState(721);
        nestedStatementBody();
        break;
      }

      case TestCaseDeclParser::TimeOutID:
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
        setState(725);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TestCaseDeclParser::TimeOutID)
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
          setState(722);
          statementBody();
          setState(727);
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
  enterRule(_localctx, 142, TestCaseDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(734);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(730);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(731);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(732);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(733);
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
  "assignmentDef", "messageDecl", "checkDecl", "checkDeclBody", "timerDecl", 
  "timeOutDecl", "altDecl", "altBody", "altBodyOptional", "enabledDecl", 
  "contextID", "functionCall", "componentIdPath", "signalIdPath", "attributeIdPath", 
  "signalSend", "commonDecl", "importPathDecl", "importPathBody", "importFileBody", 
  "importAs", "typeDefDecl", "typeDecl", "intTypeDecl", "realTypeDecl", 
  "enumTypeDecl", "attributeDecl", "literalValue", "signalParamName", "attributeName", 
  "toPortName", "attributeAssignStatement", "localAssignStatement", "sendToStatement", 
  "singleAssignment", "multiAssignment", "signalDecl", "paramDecl", "functionDecl", 
  "functionParameters", "functionCallBody", "functionCallBodyOptional", 
  "triggerDecl", "thisDecl", "portDecl", "nameDecl", "idPath", "statementDecl", 
  "statementBody", "functionCallStatement", "nestedStatementBody", "returnStatement", 
  "breakStatement", "operation", "operationOptional", "expression", "expressionOptional", 
  "conditionalStatement", "ifStatement", "ifEuT", "elseStatement", "switchStatement", 
  "switchPuT", "caseStatement", "defaultStatement", "atom"
};

std::vector<std::string> TestCaseDeclParser::_literalNames = {
  "", "'Message'", "'timeout'", "'Check'", "'Alt'", "'Timer'", "'Component'", 
  "'Declaration'", "'TestCase'", "'ms'", "'s'", "", "'name'", "'label'", 
  "'enabled'", "'Type'", "'int'", "'real'", "'bool'", "'string'", "'trigger'", 
  "'msg'", "'this'", "'return'", "'SignalTransition'", "'TimeoutTransition'", 
  "'enum'", "'description'", "'Attribute'", "'Signal'", "'Port'", "'import'", 
  "'from'", "'to'", "'send'", "'Function'", "'switch'", "'case'", "'default'", 
  "'if'", "'else'", "'as'", "'@'", "'!'", "'&&'", "'||'", "'not'", "'and'", 
  "'or'", "'true'", "'false'", "'break'", "'='", "'<->'", "'->'", "'<-'", 
  "'..'", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "'<'", "'>'", "':'", "';'", "','", "'_'", "'.'", "'+'", "'-'", "'*'", 
  "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> TestCaseDeclParser::_symbolicNames = {
  "", "MessageID", "TimeOutID", "CheckID", "AltID", "TimerID", "ComponentID", 
  "DeclarationID", "TestCaseID", "MilliSekID", "SekID", "IGNORE_NEWLINE", 
  "NameID", "LabelID", "EnabledID", "TypeID", "IntID", "RealID", "BoolID", 
  "StringID", "TriggerID", "MessageTrigger", "ThisID", "ReturnID", "SignalTransitionID", 
  "TimeoutTransitionID", "EnumID", "DescriptionID", "AttributeID", "SignalID", 
  "PortID", "ImportID", "FromID", "ToID", "SendID", "FunctionID", "SwitchID", 
  "CaseID", "DefaultID", "IfID", "ElseID", "AsID", "AtID", "NotIdSymbol", 
  "AndIdSymbol", "OrIdSymbol", "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", 
  "FalseID", "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", "LeftArrow", 
  "RANGE", "INT", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", "LPAREN", 
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", 
  "COLON", "SEMI", "COMMA", "UNDER", "DOT", "PLUS", "MINUS", "MULT", "DIV", 
  "PIPE", "REF", "CONST", "NEWLINE", "WS"
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
    0x3, 0x56, 0x2e3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb2, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0xcb, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0xd1, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0xd6, 0xa, 0x7, 0x5, 0x7, 0xd8, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xf7, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x110, 0xa, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x116, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x11f, 
    0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x137, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x7, 0x14, 0x141, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0x144, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x149, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x14c, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x152, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
    0x155, 0xb, 0x16, 0x5, 0x16, 0x157, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 
    0x18, 0x161, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x164, 0xb, 0x18, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x16a, 0xa, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x17d, 0xa, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x182, 0xa, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x18f, 0xa, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x5, 0x1f, 0x198, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1a1, 0xa, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x1a8, 
    0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x1ab, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x1b4, 
    0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1be, 0xa, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1c5, 0xa, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1d6, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1de, 0xa, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1e4, 0xa, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x1e8, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
    0x1eb, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x1f5, 0xa, 0x2c, 0xc, 0x2c, 
    0xe, 0x2c, 0x1f8, 0xb, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1fb, 0xa, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1ff, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x20c, 0xa, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x214, 
    0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x217, 0xb, 0x2f, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x21e, 0xa, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x225, 0xa, 0x31, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x231, 0xa, 0x34, 
    0xc, 0x34, 0xe, 0x34, 0x234, 0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x36, 0x7, 0x36, 0x240, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x243, 0xb, 
    0x36, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x247, 0xa, 0x37, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x5, 0x38, 0x251, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x258, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 
    0x25b, 0xb, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x271, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x276, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
    0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x286, 
    0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x294, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x299, 0xa, 0x40, 0x5, 0x40, 0x29b, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x29f, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 
    0x2a4, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 
    0x2aa, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 
    0x45, 0x2b7, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x2ba, 0xb, 0x45, 0x3, 
    0x45, 0x3, 0x45, 0x5, 0x45, 0x2be, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 
    0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x2cb, 0xa, 0x47, 0xc, 0x47, 
    0xe, 0x47, 0x2ce, 0xb, 0x47, 0x5, 0x47, 0x2d0, 0xa, 0x47, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 0x2d6, 0xa, 0x48, 0xc, 0x48, 
    0xe, 0x48, 0x2d9, 0xb, 0x48, 0x5, 0x48, 0x2db, 0xa, 0x48, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x2e1, 0xa, 0x49, 0x3, 0x49, 
    0x2, 0x2, 0x4a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
    0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
    0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 
    0x8e, 0x90, 0x2, 0x8, 0x4, 0x2, 0x33, 0x34, 0x3b, 0x3d, 0x3, 0x2, 0x3b, 
    0x3c, 0x3, 0x2, 0xb, 0xc, 0x3, 0x2, 0x33, 0x34, 0x3, 0x2, 0x16, 0x17, 
    0x3, 0x2, 0x4e, 0x51, 0x2, 0x30d, 0x2, 0x92, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x6, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x8, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd7, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x10, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x14, 0xf0, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x18, 0x101, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x120, 0x3, 0x2, 0x2, 0x2, 0x22, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x138, 0x3, 0x2, 0x2, 0x2, 0x26, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x145, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x158, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x169, 0x3, 0x2, 0x2, 0x2, 0x32, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x17c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x181, 0x3, 0x2, 0x2, 0x2, 0x38, 0x183, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x199, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1a2, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1bd, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1c4, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x1d0, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1e3, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1ee, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x202, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x205, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x210, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x21d, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x224, 0x3, 0x2, 0x2, 0x2, 0x62, 0x226, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x229, 0x3, 0x2, 0x2, 0x2, 0x66, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x237, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x246, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x250, 0x3, 0x2, 0x2, 0x2, 0x70, 0x252, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x255, 0x3, 0x2, 0x2, 0x2, 0x74, 0x25e, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x262, 0x3, 0x2, 0x2, 0x2, 0x78, 0x270, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x275, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x285, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x2a5, 0x3, 0x2, 0x2, 0x2, 0x84, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x86, 0x2af, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2c1, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x2d1, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x5, 0x30, 0x19, 
    0x2, 0x93, 0x94, 0x7, 0xa, 0x2, 0x2, 0x94, 0x95, 0x7, 0x43, 0x2, 0x2, 
    0x95, 0x96, 0x5, 0x4, 0x3, 0x2, 0x96, 0x97, 0x7, 0x44, 0x2, 0x2, 0x97, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x9, 0x2, 0x2, 0x99, 0x9a, 
    0x7, 0x43, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x6, 0x4, 0x2, 0x9b, 0x9c, 0x7, 
    0x44, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0xa, 0x6, 0x2, 0x9d, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x9f, 0x5, 0x42, 0x22, 0x2, 0x9f, 0xa0, 0x5, 0x6, 0x4, 
    0x2, 0xa0, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x68, 0x35, 0x2, 
    0xa2, 0xa3, 0x5, 0x6, 0x4, 0x2, 0xa3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa5, 0x5, 0x20, 0x11, 0x2, 0xa5, 0xa6, 0x5, 0x6, 0x4, 0x2, 0xa6, 0xb2, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x56, 0x2c, 0x2, 0xa8, 0xa9, 0x5, 
    0x6, 0x4, 0x2, 0xa9, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x12, 
    0xa, 0x2, 0xab, 0xac, 0x5, 0x6, 0x4, 0x2, 0xac, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xae, 0x5, 0x8, 0x5, 0x2, 0xae, 0xaf, 0x5, 0x6, 0x4, 0x2, 
    0xaf, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb1, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xb1, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0x7, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x8, 0x2, 
    0x2, 0xb4, 0xb5, 0x5, 0x6a, 0x36, 0x2, 0xb5, 0xb6, 0x7, 0x2b, 0x2, 0x2, 
    0xb6, 0xb7, 0x5, 0x22, 0x12, 0x2, 0xb7, 0xb8, 0x7, 0x4a, 0x2, 0x2, 0xb8, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x16, 0xc, 0x2, 0xba, 0xbb, 
    0x5, 0xa, 0x6, 0x2, 0xbb, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x5, 
    0x10, 0x9, 0x2, 0xbd, 0xbe, 0x5, 0xa, 0x6, 0x2, 0xbe, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xc0, 0x5, 0x12, 0xa, 0x2, 0xc0, 0xc1, 0x5, 0xa, 0x6, 
    0x2, 0xc1, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x5, 0x1a, 0xe, 0x2, 
    0xc3, 0xc4, 0x5, 0xa, 0x6, 0x2, 0xc4, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xc6, 0x5, 0xc, 0x7, 0x2, 0xc6, 0xc7, 0x7, 0x4a, 0x2, 0x2, 0xc7, 0xc8, 
    0x5, 0xa, 0x6, 0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xca, 0xbc, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xb, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x64, 0x33, 0x2, 0xcd, 
    0xd0, 0x5, 0x6a, 0x36, 0x2, 0xce, 0xd1, 0x5, 0xe, 0x8, 0x2, 0xcf, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd5, 0x5, 0x6a, 
    0x36, 0x2, 0xd3, 0xd6, 0x5, 0xe, 0x8, 0x2, 0xd4, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 
    0x7, 0x36, 0x2, 0x2, 0xda, 0xdb, 0x9, 0x2, 0x2, 0x2, 0xdb, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x3, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x41, 
    0x2, 0x2, 0xde, 0xdf, 0x5, 0x6a, 0x36, 0x2, 0xdf, 0xe0, 0x7, 0x38, 0x2, 
    0x2, 0xe0, 0xe1, 0x5, 0x6a, 0x36, 0x2, 0xe1, 0xe2, 0x7, 0x42, 0x2, 0x2, 
    0xe2, 0xe3, 0x7, 0x49, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x24, 0x13, 0x2, 0xe4, 
    0xe5, 0x7, 0x4a, 0x2, 0x2, 0xe5, 0x11, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 
    0x7, 0x5, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x41, 0x2, 0x2, 0xe8, 0xe9, 0x5, 
    0x6a, 0x36, 0x2, 0xe9, 0xea, 0x7, 0x38, 0x2, 0x2, 0xea, 0xeb, 0x5, 0x6a, 
    0x36, 0x2, 0xeb, 0xec, 0x7, 0x42, 0x2, 0x2, 0xec, 0xed, 0x7, 0x49, 0x2, 
    0x2, 0xed, 0xee, 0x5, 0x22, 0x12, 0x2, 0xee, 0xef, 0x5, 0x14, 0xb, 0x2, 
    0xef, 0x13, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x45, 0x2, 0x2, 0xf1, 
    0xf2, 0x5, 0x7c, 0x3f, 0x2, 0xf2, 0xf6, 0x7, 0x46, 0x2, 0x2, 0xf3, 0xf4, 
    0x7, 0x4b, 0x2, 0x2, 0xf4, 0xf7, 0x5, 0x18, 0xd, 0x2, 0xf5, 0xf7, 0x7, 
    0x4a, 0x2, 0x2, 0xf6, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x7, 0x2, 
    0x2, 0xf9, 0xfa, 0x7, 0x2c, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x6a, 0x36, 0x2, 
    0xfb, 0xfc, 0x5, 0x22, 0x12, 0x2, 0xfc, 0xfd, 0x7, 0x36, 0x2, 0x2, 0xfd, 
    0xfe, 0x9, 0x3, 0x2, 0x2, 0xfe, 0xff, 0x9, 0x4, 0x2, 0x2, 0xff, 0x100, 
    0x7, 0x4a, 0x2, 0x2, 0x100, 0x17, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 
    0x7, 0x4, 0x2, 0x2, 0x102, 0x103, 0x7, 0x49, 0x2, 0x2, 0x103, 0x104, 
    0x9, 0x3, 0x2, 0x2, 0x104, 0x105, 0x9, 0x4, 0x2, 0x2, 0x105, 0x106, 
    0x7, 0x4a, 0x2, 0x2, 0x106, 0x19, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 
    0x7, 0x6, 0x2, 0x2, 0x108, 0x109, 0x7, 0x43, 0x2, 0x2, 0x109, 0x10a, 
    0x5, 0x1e, 0x10, 0x2, 0x10a, 0x10b, 0x7, 0x44, 0x2, 0x2, 0x10b, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x7, 0x45, 0x2, 0x2, 0x10d, 0x110, 
    0x5, 0x7c, 0x3f, 0x2, 0x10e, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x46, 0x2, 0x2, 0x112, 0x115, 
    0x7, 0x43, 0x2, 0x2, 0x113, 0x116, 0x5, 0x12, 0xa, 0x2, 0x114, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 
    0x5, 0xa, 0x6, 0x2, 0x118, 0x119, 0x7, 0x44, 0x2, 0x2, 0x119, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x5, 0x1c, 0xf, 0x2, 0x11b, 0x11c, 
    0x5, 0x1e, 0x10, 0x2, 0x11c, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11f, 
    0x3, 0x2, 0x2, 0x2, 0x11e, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11d, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x7, 
    0x10, 0x2, 0x2, 0x121, 0x122, 0x7, 0x49, 0x2, 0x2, 0x122, 0x123, 0x9, 
    0x5, 0x2, 0x2, 0x123, 0x124, 0x7, 0x4a, 0x2, 0x2, 0x124, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x125, 0x137, 0x7, 0x3e, 0x2, 0x2, 0x126, 0x137, 0x7, 
    0xe, 0x2, 0x2, 0x127, 0x137, 0x7, 0xf, 0x2, 0x2, 0x128, 0x137, 0x7, 
    0x10, 0x2, 0x2, 0x129, 0x137, 0x7, 0x11, 0x2, 0x2, 0x12a, 0x137, 0x9, 
    0x6, 0x2, 0x2, 0x12b, 0x137, 0x7, 0x1e, 0x2, 0x2, 0x12c, 0x137, 0x7, 
    0x1f, 0x2, 0x2, 0x12d, 0x137, 0x7, 0x20, 0x2, 0x2, 0x12e, 0x137, 0x7, 
    0x21, 0x2, 0x2, 0x12f, 0x137, 0x7, 0x22, 0x2, 0x2, 0x130, 0x137, 0x7, 
    0x23, 0x2, 0x2, 0x131, 0x137, 0x7, 0x24, 0x2, 0x2, 0x132, 0x137, 0x7, 
    0x2b, 0x2, 0x2, 0x133, 0x137, 0x7, 0x4, 0x2, 0x2, 0x134, 0x137, 0x7, 
    0x8, 0x2, 0x2, 0x135, 0x137, 0x7, 0x9, 0x2, 0x2, 0x136, 0x125, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x126, 0x3, 0x2, 0x2, 0x2, 0x136, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x128, 0x3, 0x2, 0x2, 0x2, 0x136, 0x129, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x136, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x136, 0x12d, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x136, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x130, 0x3, 0x2, 0x2, 0x2, 0x136, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x132, 0x3, 0x2, 0x2, 0x2, 0x136, 0x133, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 0x135, 0x3, 
    0x2, 0x2, 0x2, 0x137, 0x23, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x5, 0x6a, 
    0x36, 0x2, 0x139, 0x13a, 0x7, 0x41, 0x2, 0x2, 0x13a, 0x13b, 0x5, 0x5e, 
    0x30, 0x2, 0x13b, 0x13c, 0x7, 0x42, 0x2, 0x2, 0x13c, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x142, 0x5, 0x22, 0x12, 0x2, 0x13e, 0x13f, 0x7, 0x4d, 
    0x2, 0x2, 0x13f, 0x141, 0x5, 0x22, 0x12, 0x2, 0x140, 0x13e, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x144, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 
    0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x14a, 0x5, 0x22, 0x12, 
    0x2, 0x146, 0x147, 0x7, 0x4d, 0x2, 0x2, 0x147, 0x149, 0x5, 0x22, 0x12, 
    0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 
    0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x157, 0x5, 0x48, 0x25, 0x2, 0x14e, 0x153, 0x5, 0x22, 0x12, 0x2, 
    0x14f, 0x150, 0x7, 0x4d, 0x2, 0x2, 0x150, 0x152, 0x5, 0x22, 0x12, 0x2, 
    0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 
    0x153, 0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 
    0x154, 0x157, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 
    0x156, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x156, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x157, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x5, 0x28, 0x15, 0x2, 
    0x159, 0x15a, 0x7, 0x41, 0x2, 0x2, 0x15a, 0x15b, 0x5, 0x5e, 0x30, 0x2, 
    0x15b, 0x15c, 0x7, 0x42, 0x2, 0x2, 0x15c, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x15d, 0x161, 0x5, 0x38, 0x1d, 0x2, 0x15e, 0x161, 0x5, 0x42, 0x22, 0x2, 
    0x15f, 0x161, 0x5, 0x56, 0x2c, 0x2, 0x160, 0x15d, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15f, 0x3, 0x2, 0x2, 0x2, 
    0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 0x163, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x164, 
    0x162, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x5, 0x32, 0x1a, 0x2, 0x166, 
    0x167, 0x5, 0x30, 0x19, 0x2, 0x167, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x168, 
    0x16a, 0x3, 0x2, 0x2, 0x2, 0x169, 0x165, 0x3, 0x2, 0x2, 0x2, 0x169, 
    0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 
    0x7, 0x21, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x47, 0x2, 0x2, 0x16d, 0x16e, 
    0x5, 0x34, 0x1b, 0x2, 0x16e, 0x16f, 0x7, 0x48, 0x2, 0x2, 0x16f, 0x170, 
    0x5, 0x36, 0x1c, 0x2, 0x170, 0x33, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 
    0x5, 0x22, 0x12, 0x2, 0x172, 0x173, 0x7, 0x4d, 0x2, 0x2, 0x173, 0x174, 
    0x5, 0x22, 0x12, 0x2, 0x174, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 
    0x7, 0x3a, 0x2, 0x2, 0x176, 0x177, 0x7, 0x51, 0x2, 0x2, 0x177, 0x17d, 
    0x5, 0x34, 0x1b, 0x2, 0x178, 0x179, 0x5, 0x22, 0x12, 0x2, 0x179, 0x17a, 
    0x7, 0x51, 0x2, 0x2, 0x17a, 0x17b, 0x5, 0x34, 0x1b, 0x2, 0x17b, 0x17d, 
    0x3, 0x2, 0x2, 0x2, 0x17c, 0x171, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x175, 
    0x3, 0x2, 0x2, 0x2, 0x17c, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x2b, 0x2, 0x2, 0x17f, 0x182, 0x5, 
    0x22, 0x12, 0x2, 0x180, 0x182, 0x3, 0x2, 0x2, 0x2, 0x181, 0x17e, 0x3, 
    0x2, 0x2, 0x2, 0x181, 0x180, 0x3, 0x2, 0x2, 0x2, 0x182, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x184, 0x7, 0x11, 0x2, 0x2, 0x184, 0x185, 0x5, 0x3a, 
    0x1e, 0x2, 0x185, 0x186, 0x5, 0x22, 0x12, 0x2, 0x186, 0x187, 0x7, 0x4a, 
    0x2, 0x2, 0x187, 0x39, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18f, 0x5, 0x3c, 
    0x1f, 0x2, 0x189, 0x18f, 0x5, 0x3e, 0x20, 0x2, 0x18a, 0x18f, 0x5, 0x40, 
    0x21, 0x2, 0x18b, 0x18f, 0x7, 0x14, 0x2, 0x2, 0x18c, 0x18f, 0x7, 0x15, 
    0x2, 0x2, 0x18d, 0x18f, 0x5, 0x22, 0x12, 0x2, 0x18e, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x18e, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x18e, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 
    0x2, 0x2, 0x18e, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x190, 0x197, 0x7, 0x12, 0x2, 0x2, 0x191, 0x192, 0x7, 0x41, 0x2, 
    0x2, 0x192, 0x193, 0x7, 0x3b, 0x2, 0x2, 0x193, 0x194, 0x7, 0x3a, 0x2, 
    0x2, 0x194, 0x195, 0x7, 0x3b, 0x2, 0x2, 0x195, 0x198, 0x7, 0x42, 0x2, 
    0x2, 0x196, 0x198, 0x3, 0x2, 0x2, 0x2, 0x197, 0x191, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x199, 0x1a0, 0x7, 0x13, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x41, 0x2, 0x2, 
    0x19b, 0x19c, 0x7, 0x3c, 0x2, 0x2, 0x19c, 0x19d, 0x7, 0x3a, 0x2, 0x2, 
    0x19d, 0x19e, 0x7, 0x3c, 0x2, 0x2, 0x19e, 0x1a1, 0x7, 0x42, 0x2, 0x2, 
    0x19f, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19a, 0x3, 0x2, 0x2, 0x2, 
    0x1a0, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
    0x1a3, 0x7, 0x1c, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x41, 0x2, 0x2, 0x1a4, 
    0x1a9, 0x5, 0x22, 0x12, 0x2, 0x1a5, 0x1a6, 0x7, 0x4b, 0x2, 0x2, 0x1a6, 
    0x1a8, 0x5, 0x22, 0x12, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a8, 
    0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
    0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ab, 
    0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x42, 0x2, 0x2, 0x1ad, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x1e, 0x2, 0x2, 0x1af, 
    0x1b0, 0x5, 0x3a, 0x1e, 0x2, 0x1b0, 0x1b3, 0x5, 0x22, 0x12, 0x2, 0x1b1, 
    0x1b2, 0x7, 0x36, 0x2, 0x2, 0x1b2, 0x1b4, 0x5, 0x44, 0x23, 0x2, 0x1b3, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 
    0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x7, 0x4a, 0x2, 0x2, 0x1b6, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1be, 0x7, 0x3b, 0x2, 0x2, 0x1b8, 
    0x1be, 0x7, 0x3c, 0x2, 0x2, 0x1b9, 0x1be, 0x7, 0x3d, 0x2, 0x2, 0x1ba, 
    0x1be, 0x7, 0x33, 0x2, 0x2, 0x1bb, 0x1be, 0x7, 0x34, 0x2, 0x2, 0x1bc, 
    0x1be, 0x5, 0x22, 0x12, 0x2, 0x1bd, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
    0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
    0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
    0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 
    0x5, 0x62, 0x32, 0x2, 0x1c0, 0x1c1, 0x5, 0x22, 0x12, 0x2, 0x1c1, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c5, 0x5, 0x64, 0x33, 0x2, 0x1c3, 0x1c5, 
    0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c3, 
    0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 
    0x5, 0x22, 0x12, 0x2, 0x1c7, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 
    0x7, 0x23, 0x2, 0x2, 0x1c9, 0x1ca, 0x5, 0x22, 0x12, 0x2, 0x1ca, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x5, 0x48, 0x25, 0x2, 0x1cc, 0x1cd, 
    0x7, 0x36, 0x2, 0x2, 0x1cd, 0x1ce, 0x5, 0x7c, 0x3f, 0x2, 0x1ce, 0x1cf, 
    0x7, 0x4a, 0x2, 0x2, 0x1cf, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 
    0x5, 0x3a, 0x1e, 0x2, 0x1d1, 0x1d5, 0x5, 0x22, 0x12, 0x2, 0x1d2, 0x1d3, 
    0x7, 0x36, 0x2, 0x2, 0x1d3, 0x1d6, 0x5, 0x7c, 0x3f, 0x2, 0x1d4, 0x1d6, 
    0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d4, 
    0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 
    0x7, 0x4a, 0x2, 0x2, 0x1d8, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 
    0x7, 0x24, 0x2, 0x2, 0x1da, 0x1dd, 0x5, 0x2c, 0x17, 0x2, 0x1db, 0x1de, 
    0x5, 0x4a, 0x26, 0x2, 0x1dc, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 
    0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 
    0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x7, 0x4a, 0x2, 0x2, 0x1e0, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e4, 0x5, 0x4c, 0x27, 0x2, 0x1e2, 0x1e4, 
    0x5, 0x50, 0x29, 0x2, 0x1e3, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e2, 
    0x3, 0x2, 0x2, 0x2, 0x1e4, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e9, 0x7, 
    0x43, 0x2, 0x2, 0x1e6, 0x1e8, 0x5, 0x52, 0x2a, 0x2, 0x1e7, 0x1e6, 0x3, 
    0x2, 0x2, 0x2, 0x1e8, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1e7, 0x3, 
    0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ec, 0x3, 
    0x2, 0x2, 0x2, 0x1eb, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 
    0x44, 0x2, 0x2, 0x1ed, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x7, 
    0x1f, 0x2, 0x2, 0x1ef, 0x1fe, 0x5, 0x22, 0x12, 0x2, 0x1f0, 0x1fa, 0x7, 
    0x41, 0x2, 0x2, 0x1f1, 0x1f6, 0x5, 0x58, 0x2d, 0x2, 0x1f2, 0x1f3, 0x7, 
    0x4b, 0x2, 0x2, 0x1f3, 0x1f5, 0x5, 0x58, 0x2d, 0x2, 0x1f4, 0x1f2, 0x3, 
    0x2, 0x2, 0x2, 0x1f5, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f4, 0x3, 
    0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1fb, 0x3, 
    0x2, 0x2, 0x2, 0x1f8, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fb, 0x3, 
    0x2, 0x2, 0x2, 0x1fa, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1f9, 0x3, 
    0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1ff, 0x7, 
    0x42, 0x2, 0x2, 0x1fd, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1f0, 0x3, 
    0x2, 0x2, 0x2, 0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x3, 
    0x2, 0x2, 0x2, 0x200, 0x201, 0x7, 0x4a, 0x2, 0x2, 0x201, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x202, 0x203, 0x5, 0x3a, 0x1e, 0x2, 0x203, 0x204, 0x5, 
    0x22, 0x12, 0x2, 0x204, 0x59, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x7, 
    0x25, 0x2, 0x2, 0x206, 0x207, 0x5, 0x3a, 0x1e, 0x2, 0x207, 0x208, 0x5, 
    0x6a, 0x36, 0x2, 0x208, 0x20b, 0x7, 0x41, 0x2, 0x2, 0x209, 0x20c, 0x5, 
    0x5c, 0x2f, 0x2, 0x20a, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x209, 0x3, 
    0x2, 0x2, 0x2, 0x20b, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 
    0x2, 0x2, 0x2, 0x20d, 0x20e, 0x7, 0x42, 0x2, 0x2, 0x20e, 0x20f, 0x5, 
    0x72, 0x3a, 0x2, 0x20f, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x210, 0x215, 0x5, 
    0x58, 0x2d, 0x2, 0x211, 0x212, 0x7, 0x4b, 0x2, 0x2, 0x212, 0x214, 0x5, 
    0x58, 0x2d, 0x2, 0x213, 0x211, 0x3, 0x2, 0x2, 0x2, 0x214, 0x217, 0x3, 
    0x2, 0x2, 0x2, 0x215, 0x213, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x3, 
    0x2, 0x2, 0x2, 0x216, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x217, 0x215, 0x3, 0x2, 
    0x2, 0x2, 0x218, 0x21e, 0x5, 0x44, 0x23, 0x2, 0x219, 0x21e, 0x5, 0x46, 
    0x24, 0x2, 0x21a, 0x21e, 0x5, 0x48, 0x25, 0x2, 0x21b, 0x21e, 0x5, 0x24, 
    0x13, 0x2, 0x21c, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x218, 0x3, 0x2, 
    0x2, 0x2, 0x21d, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21a, 0x3, 0x2, 
    0x2, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21c, 0x3, 0x2, 
    0x2, 0x2, 0x21e, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 0x5, 0x60, 
    0x31, 0x2, 0x220, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x221, 0x222, 0x7, 0x4b, 
    0x2, 0x2, 0x222, 0x225, 0x5, 0x5e, 0x30, 0x2, 0x223, 0x225, 0x3, 0x2, 
    0x2, 0x2, 0x224, 0x221, 0x3, 0x2, 0x2, 0x2, 0x224, 0x223, 0x3, 0x2, 
    0x2, 0x2, 0x225, 0x61, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x9, 0x6, 0x2, 
    0x2, 0x227, 0x228, 0x7, 0x4d, 0x2, 0x2, 0x228, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x229, 0x22a, 0x7, 0x18, 0x2, 0x2, 0x22a, 0x22b, 0x7, 0x4d, 0x2, 
    0x2, 0x22b, 0x65, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x7, 0x20, 0x2, 
    0x2, 0x22d, 0x232, 0x5, 0x22, 0x12, 0x2, 0x22e, 0x22f, 0x7, 0x4b, 0x2, 
    0x2, 0x22f, 0x231, 0x5, 0x22, 0x12, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x234, 0x3, 0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 0x2, 0x2, 
    0x2, 0x232, 0x233, 0x3, 0x2, 0x2, 0x2, 0x233, 0x235, 0x3, 0x2, 0x2, 
    0x2, 0x234, 0x232, 0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 0x7, 0x4a, 0x2, 
    0x2, 0x236, 0x67, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x7, 0xe, 0x2, 0x2, 
    0x238, 0x239, 0x7, 0x49, 0x2, 0x2, 0x239, 0x23a, 0x5, 0x22, 0x12, 0x2, 
    0x23a, 0x23b, 0x7, 0x4a, 0x2, 0x2, 0x23b, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x23c, 0x241, 0x5, 0x22, 0x12, 0x2, 0x23d, 0x23e, 0x7, 0x4d, 0x2, 0x2, 
    0x23e, 0x240, 0x5, 0x22, 0x12, 0x2, 0x23f, 0x23d, 0x3, 0x2, 0x2, 0x2, 
    0x240, 0x243, 0x3, 0x2, 0x2, 0x2, 0x241, 0x23f, 0x3, 0x2, 0x2, 0x2, 
    0x241, 0x242, 0x3, 0x2, 0x2, 0x2, 0x242, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x243, 
    0x241, 0x3, 0x2, 0x2, 0x2, 0x244, 0x247, 0x5, 0x6e, 0x38, 0x2, 0x245, 
    0x247, 0x5, 0x72, 0x3a, 0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x246, 
    0x245, 0x3, 0x2, 0x2, 0x2, 0x247, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x248, 0x251, 
    0x5, 0x70, 0x39, 0x2, 0x249, 0x251, 0x5, 0x4c, 0x27, 0x2, 0x24a, 0x251, 
    0x5, 0x88, 0x45, 0x2, 0x24b, 0x251, 0x5, 0x80, 0x41, 0x2, 0x24c, 0x251, 
    0x5, 0x4e, 0x28, 0x2, 0x24d, 0x251, 0x5, 0x50, 0x29, 0x2, 0x24e, 0x251, 
    0x5, 0x76, 0x3c, 0x2, 0x24f, 0x251, 0x5, 0x74, 0x3b, 0x2, 0x250, 0x248, 
    0x3, 0x2, 0x2, 0x2, 0x250, 0x249, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24a, 
    0x3, 0x2, 0x2, 0x2, 0x250, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24c, 
    0x3, 0x2, 0x2, 0x2, 0x250, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 
    0x3, 0x2, 0x2, 0x2, 0x250, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x251, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x252, 0x253, 0x5, 0x24, 0x13, 0x2, 0x253, 0x254, 0x7, 
    0x4a, 0x2, 0x2, 0x254, 0x71, 0x3, 0x2, 0x2, 0x2, 0x255, 0x259, 0x7, 
    0x43, 0x2, 0x2, 0x256, 0x258, 0x5, 0x6e, 0x38, 0x2, 0x257, 0x256, 0x3, 
    0x2, 0x2, 0x2, 0x258, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x259, 0x257, 0x3, 
    0x2, 0x2, 0x2, 0x259, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25c, 0x3, 
    0x2, 0x2, 0x2, 0x25b, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x7, 
    0x44, 0x2, 0x2, 0x25d, 0x73, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x7, 
    0x19, 0x2, 0x2, 0x25f, 0x260, 0x5, 0x78, 0x3d, 0x2, 0x260, 0x261, 0x7, 
    0x4a, 0x2, 0x2, 0x261, 0x75, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x7, 
    0x35, 0x2, 0x2, 0x263, 0x264, 0x7, 0x4a, 0x2, 0x2, 0x264, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x265, 0x266, 0x5, 0x90, 0x49, 0x2, 0x266, 0x267, 0x5, 
    0x7a, 0x3e, 0x2, 0x267, 0x271, 0x3, 0x2, 0x2, 0x2, 0x268, 0x269, 0x7, 
    0x41, 0x2, 0x2, 0x269, 0x26a, 0x5, 0x78, 0x3d, 0x2, 0x26a, 0x26b, 0x7, 
    0x42, 0x2, 0x2, 0x26b, 0x271, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26d, 0x7, 
    0x4f, 0x2, 0x2, 0x26d, 0x271, 0x5, 0x78, 0x3d, 0x2, 0x26e, 0x26f, 0x7, 
    0x2d, 0x2, 0x2, 0x26f, 0x271, 0x5, 0x78, 0x3d, 0x2, 0x270, 0x265, 0x3, 
    0x2, 0x2, 0x2, 0x270, 0x268, 0x3, 0x2, 0x2, 0x2, 0x270, 0x26c, 0x3, 
    0x2, 0x2, 0x2, 0x270, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x271, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x272, 0x273, 0x9, 0x7, 0x2, 0x2, 0x273, 0x276, 0x5, 0x78, 
    0x3d, 0x2, 0x274, 0x276, 0x3, 0x2, 0x2, 0x2, 0x275, 0x272, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x277, 0x278, 0x7, 0x41, 0x2, 0x2, 0x278, 0x279, 0x5, 0x7c, 0x3f, 
    0x2, 0x279, 0x27a, 0x7, 0x42, 0x2, 0x2, 0x27a, 0x27b, 0x5, 0x7e, 0x40, 
    0x2, 0x27b, 0x286, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x7, 0x2d, 0x2, 
    0x2, 0x27d, 0x286, 0x5, 0x7c, 0x3f, 0x2, 0x27e, 0x27f, 0x7, 0x30, 0x2, 
    0x2, 0x27f, 0x286, 0x5, 0x7c, 0x3f, 0x2, 0x280, 0x281, 0x7, 0x4f, 0x2, 
    0x2, 0x281, 0x286, 0x5, 0x7c, 0x3f, 0x2, 0x282, 0x283, 0x5, 0x78, 0x3d, 
    0x2, 0x283, 0x284, 0x5, 0x7e, 0x40, 0x2, 0x284, 0x286, 0x3, 0x2, 0x2, 
    0x2, 0x285, 0x277, 0x3, 0x2, 0x2, 0x2, 0x285, 0x27c, 0x3, 0x2, 0x2, 
    0x2, 0x285, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x285, 0x280, 0x3, 0x2, 0x2, 
    0x2, 0x285, 0x282, 0x3, 0x2, 0x2, 0x2, 0x286, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x287, 0x29b, 0x7, 0x2f, 0x2, 0x2, 0x288, 0x29b, 0x7, 0x32, 0x2, 0x2, 
    0x289, 0x29b, 0x7, 0x2e, 0x2, 0x2, 0x28a, 0x29b, 0x7, 0x31, 0x2, 0x2, 
    0x28b, 0x28c, 0x7, 0x36, 0x2, 0x2, 0x28c, 0x29b, 0x7, 0x36, 0x2, 0x2, 
    0x28d, 0x28e, 0x7, 0x2d, 0x2, 0x2, 0x28e, 0x29b, 0x7, 0x36, 0x2, 0x2, 
    0x28f, 0x29b, 0x7, 0x30, 0x2, 0x2, 0x290, 0x293, 0x7, 0x47, 0x2, 0x2, 
    0x291, 0x294, 0x7, 0x36, 0x2, 0x2, 0x292, 0x294, 0x3, 0x2, 0x2, 0x2, 
    0x293, 0x291, 0x3, 0x2, 0x2, 0x2, 0x293, 0x292, 0x3, 0x2, 0x2, 0x2, 
    0x294, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x295, 0x298, 0x7, 0x48, 0x2, 0x2, 
    0x296, 0x299, 0x7, 0x36, 0x2, 0x2, 0x297, 0x299, 0x3, 0x2, 0x2, 0x2, 
    0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 0x298, 0x297, 0x3, 0x2, 0x2, 0x2, 
    0x299, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x287, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x288, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x289, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x28b, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x28f, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x290, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x295, 0x3, 0x2, 0x2, 0x2, 
    0x29b, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29f, 0x5, 0x7c, 0x3f, 0x2, 
    0x29d, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29a, 0x3, 0x2, 0x2, 0x2, 
    0x29e, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
    0x2a3, 0x5, 0x82, 0x42, 0x2, 0x2a1, 0x2a4, 0x5, 0x86, 0x44, 0x2, 0x2a2, 
    0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a3, 
    0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x81, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a6, 
    0x7, 0x29, 0x2, 0x2, 0x2a6, 0x2a9, 0x5, 0x84, 0x43, 0x2, 0x2a7, 0x2aa, 
    0x5, 0x6c, 0x37, 0x2, 0x2a8, 0x2aa, 0x7, 0x4a, 0x2, 0x2, 0x2a9, 0x2a7, 
    0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x2ab, 0x2ac, 0x7, 0x41, 0x2, 0x2, 0x2ac, 0x2ad, 0x5, 
    0x7c, 0x3f, 0x2, 0x2ad, 0x2ae, 0x7, 0x42, 0x2, 0x2, 0x2ae, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x7, 0x2a, 0x2, 0x2, 0x2b0, 0x2b1, 0x5, 
    0x6c, 0x37, 0x2, 0x2b1, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x7, 
    0x26, 0x2, 0x2, 0x2b3, 0x2b4, 0x5, 0x8a, 0x46, 0x2, 0x2b4, 0x2b8, 0x7, 
    0x43, 0x2, 0x2, 0x2b5, 0x2b7, 0x5, 0x8c, 0x47, 0x2, 0x2b6, 0x2b5, 0x3, 
    0x2, 0x2, 0x2, 0x2b7, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b6, 0x3, 
    0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2bd, 0x3, 
    0x2, 0x2, 0x2, 0x2ba, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2be, 0x5, 
    0x8e, 0x48, 0x2, 0x2bc, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2bb, 0x3, 
    0x2, 0x2, 0x2, 0x2bd, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x3, 
    0x2, 0x2, 0x2, 0x2bf, 0x2c0, 0x7, 0x44, 0x2, 0x2, 0x2c0, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x7, 0x41, 0x2, 0x2, 0x2c2, 0x2c3, 0x5, 
    0x22, 0x12, 0x2, 0x2c3, 0x2c4, 0x7, 0x42, 0x2, 0x2, 0x2c4, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x27, 0x2, 0x2, 0x2c6, 0x2c7, 0x5, 
    0x44, 0x23, 0x2, 0x2c7, 0x2cf, 0x7, 0x49, 0x2, 0x2, 0x2c8, 0x2d0, 0x5, 
    0x72, 0x3a, 0x2, 0x2c9, 0x2cb, 0x5, 0x6e, 0x38, 0x2, 0x2ca, 0x2c9, 0x3, 
    0x2, 0x2, 0x2, 0x2cb, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2ca, 0x3, 
    0x2, 0x2, 0x2, 0x2cc, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2d0, 0x3, 
    0x2, 0x2, 0x2, 0x2ce, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2c8, 0x3, 
    0x2, 0x2, 0x2, 0x2cf, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x2d1, 0x2d2, 0x7, 0x28, 0x2, 0x2, 0x2d2, 0x2da, 0x7, 0x49, 
    0x2, 0x2, 0x2d3, 0x2db, 0x5, 0x72, 0x3a, 0x2, 0x2d4, 0x2d6, 0x5, 0x6e, 
    0x38, 0x2, 0x2d5, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d9, 0x3, 0x2, 
    0x2, 0x2, 0x2d7, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x3, 0x2, 
    0x2, 0x2, 0x2d8, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 
    0x2, 0x2, 0x2da, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d7, 0x3, 0x2, 
    0x2, 0x2, 0x2db, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2e1, 0x5, 0x46, 
    0x24, 0x2, 0x2dd, 0x2e1, 0x5, 0x48, 0x25, 0x2, 0x2de, 0x2e1, 0x5, 0x24, 
    0x13, 0x2, 0x2df, 0x2e1, 0x5, 0x44, 0x23, 0x2, 0x2e0, 0x2dc, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0xb1, 0xca, 0xd0, 0xd5, 0xd7, 0xf6, 0x10f, 0x115, 0x11e, 
    0x136, 0x142, 0x14a, 0x153, 0x156, 0x160, 0x162, 0x169, 0x17c, 0x181, 
    0x18e, 0x197, 0x1a0, 0x1a9, 0x1b3, 0x1bd, 0x1c4, 0x1d5, 0x1dd, 0x1e3, 
    0x1e9, 0x1f6, 0x1fa, 0x1fe, 0x20b, 0x215, 0x21d, 0x224, 0x232, 0x241, 
    0x246, 0x250, 0x259, 0x270, 0x275, 0x285, 0x293, 0x298, 0x29a, 0x29e, 
    0x2a3, 0x2a9, 0x2b8, 0x2bd, 0x2cc, 0x2cf, 0x2d7, 0x2da, 0x2e0, 
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
