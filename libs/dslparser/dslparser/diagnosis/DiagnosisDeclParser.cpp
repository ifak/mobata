
// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/DiagnosisDecl.g4 by ANTLR 4.7.2


#include "DiagnosisDeclListener.h"

#include "DiagnosisDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

DiagnosisDeclParser::DiagnosisDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DiagnosisDeclParser::~DiagnosisDeclParser() {
  delete _interpreter;
}

std::string DiagnosisDeclParser::getGrammarFileName() const {
  return "DiagnosisDecl.g4";
}

const std::vector<std::string>& DiagnosisDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DiagnosisDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- DiagnosisDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::DiagnosisDeclContext::DiagnosisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::ImportPathDeclContext* DiagnosisDeclParser::DiagnosisDeclContext::importPathDecl() {
  return getRuleContext<DiagnosisDeclParser::ImportPathDeclContext>(0);
}

DiagnosisDeclParser::RulesDeclContext* DiagnosisDeclParser::DiagnosisDeclContext::rulesDecl() {
  return getRuleContext<DiagnosisDeclParser::RulesDeclContext>(0);
}


size_t DiagnosisDeclParser::DiagnosisDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDiagnosisDecl;
}

void DiagnosisDeclParser::DiagnosisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiagnosisDecl(this);
}

void DiagnosisDeclParser::DiagnosisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiagnosisDecl(this);
}

DiagnosisDeclParser::DiagnosisDeclContext* DiagnosisDeclParser::diagnosisDecl() {
  DiagnosisDeclContext *_localctx = _tracker.createInstance<DiagnosisDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, DiagnosisDeclParser::RuleDiagnosisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    importPathDecl();
    setState(163);
    rulesDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RulesDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::RulesDeclContext::RulesDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::RuleDeclContext* DiagnosisDeclParser::RulesDeclContext::ruleDecl() {
  return getRuleContext<DiagnosisDeclParser::RuleDeclContext>(0);
}

DiagnosisDeclParser::RulesDeclContext* DiagnosisDeclParser::RulesDeclContext::rulesDecl() {
  return getRuleContext<DiagnosisDeclParser::RulesDeclContext>(0);
}


size_t DiagnosisDeclParser::RulesDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleRulesDecl;
}

void DiagnosisDeclParser::RulesDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRulesDecl(this);
}

void DiagnosisDeclParser::RulesDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRulesDecl(this);
}

DiagnosisDeclParser::RulesDeclContext* DiagnosisDeclParser::rulesDecl() {
  RulesDeclContext *_localctx = _tracker.createInstance<RulesDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, DiagnosisDeclParser::RuleRulesDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::RuleID: {
        enterOuterAlt(_localctx, 1);
        setState(165);
        ruleDecl();
        setState(166);
        rulesDecl();
        break;
      }

      case DiagnosisDeclParser::EOF: {
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

//----------------- RuleDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::RuleDeclContext::RuleDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::RuleDeclContext::RuleID() {
  return getToken(DiagnosisDeclParser::RuleID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::RuleDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::RuleBodyContext* DiagnosisDeclParser::RuleDeclContext::ruleBody() {
  return getRuleContext<DiagnosisDeclParser::RuleBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::RuleDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::RuleDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleRuleDecl;
}

void DiagnosisDeclParser::RuleDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleDecl(this);
}

void DiagnosisDeclParser::RuleDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleDecl(this);
}

DiagnosisDeclParser::RuleDeclContext* DiagnosisDeclParser::ruleDecl() {
  RuleDeclContext *_localctx = _tracker.createInstance<RuleDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, DiagnosisDeclParser::RuleRuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(DiagnosisDeclParser::RuleID);
    setState(172);
    match(DiagnosisDeclParser::LBRACE);
    setState(173);
    ruleBody();
    setState(174);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::RuleBodyContext::RuleBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::NameDeclContext* DiagnosisDeclParser::RuleBodyContext::nameDecl() {
  return getRuleContext<DiagnosisDeclParser::NameDeclContext>(0);
}

DiagnosisDeclParser::DescriptionDeclContext* DiagnosisDeclParser::RuleBodyContext::descriptionDecl() {
  return getRuleContext<DiagnosisDeclParser::DescriptionDeclContext>(0);
}

DiagnosisDeclParser::EnabledDeclContext* DiagnosisDeclParser::RuleBodyContext::enabledDecl() {
  return getRuleContext<DiagnosisDeclParser::EnabledDeclContext>(0);
}

DiagnosisDeclParser::SequenceDeclContext* DiagnosisDeclParser::RuleBodyContext::sequenceDecl() {
  return getRuleContext<DiagnosisDeclParser::SequenceDeclContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::RuleBodyContext::DeclarationID() {
  return getToken(DiagnosisDeclParser::DeclarationID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::RuleBodyContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::DeclarationsContext* DiagnosisDeclParser::RuleBodyContext::declarations() {
  return getRuleContext<DiagnosisDeclParser::DeclarationsContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::RuleBodyContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::RuleBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleRuleBody;
}

void DiagnosisDeclParser::RuleBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleBody(this);
}

void DiagnosisDeclParser::RuleBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleBody(this);
}

DiagnosisDeclParser::RuleBodyContext* DiagnosisDeclParser::ruleBody() {
  RuleBodyContext *_localctx = _tracker.createInstance<RuleBodyContext>(_ctx, getState());
  enterRule(_localctx, 6, DiagnosisDeclParser::RuleRuleBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    nameDecl();
    setState(177);
    descriptionDecl();
    setState(178);
    enabledDecl();
    setState(185);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::DeclarationID: {
        setState(179);
        match(DiagnosisDeclParser::DeclarationID);
        setState(180);
        match(DiagnosisDeclParser::LBRACE);
        setState(181);
        declarations();
        setState(182);
        match(DiagnosisDeclParser::RBRACE);
        break;
      }

      case DiagnosisDeclParser::SequenceID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(187);
    sequenceDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescriptionDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::DescriptionDeclContext::DescriptionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::DescriptionDeclContext::DescriptionID() {
  return getToken(DiagnosisDeclParser::DescriptionID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::DescriptionDeclContext::COLON() {
  return getToken(DiagnosisDeclParser::COLON, 0);
}

tree::TerminalNode* DiagnosisDeclParser::DescriptionDeclContext::STRING() {
  return getToken(DiagnosisDeclParser::STRING, 0);
}

tree::TerminalNode* DiagnosisDeclParser::DescriptionDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::DescriptionDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDescriptionDecl;
}

void DiagnosisDeclParser::DescriptionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescriptionDecl(this);
}

void DiagnosisDeclParser::DescriptionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescriptionDecl(this);
}

DiagnosisDeclParser::DescriptionDeclContext* DiagnosisDeclParser::descriptionDecl() {
  DescriptionDeclContext *_localctx = _tracker.createInstance<DescriptionDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, DiagnosisDeclParser::RuleDescriptionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(DiagnosisDeclParser::DescriptionID);
    setState(190);
    match(DiagnosisDeclParser::COLON);
    setState(191);
    match(DiagnosisDeclParser::STRING);
    setState(192);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

DiagnosisDeclParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::AttributeDeclContext* DiagnosisDeclParser::DeclarationsContext::attributeDecl() {
  return getRuleContext<DiagnosisDeclParser::AttributeDeclContext>(0);
}

DiagnosisDeclParser::DeclarationsContext* DiagnosisDeclParser::DeclarationsContext::declarations() {
  return getRuleContext<DiagnosisDeclParser::DeclarationsContext>(0);
}

DiagnosisDeclParser::DiagnosisSignalDeclContext* DiagnosisDeclParser::DeclarationsContext::diagnosisSignalDecl() {
  return getRuleContext<DiagnosisDeclParser::DiagnosisSignalDeclContext>(0);
}

DiagnosisDeclParser::AliasDefContext* DiagnosisDeclParser::DeclarationsContext::aliasDef() {
  return getRuleContext<DiagnosisDeclParser::AliasDefContext>(0);
}

DiagnosisDeclParser::ComponentDeclContext* DiagnosisDeclParser::DeclarationsContext::componentDecl() {
  return getRuleContext<DiagnosisDeclParser::ComponentDeclContext>(0);
}


size_t DiagnosisDeclParser::DeclarationsContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDeclarations;
}

void DiagnosisDeclParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void DiagnosisDeclParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

DiagnosisDeclParser::DeclarationsContext* DiagnosisDeclParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 10, DiagnosisDeclParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        attributeDecl();
        setState(195);
        declarations();
        break;
      }

      case DiagnosisDeclParser::SignalID: {
        enterOuterAlt(_localctx, 2);
        setState(197);
        diagnosisSignalDecl();
        setState(198);
        declarations();
        break;
      }

      case DiagnosisDeclParser::UseID: {
        enterOuterAlt(_localctx, 3);
        setState(200);
        aliasDef();
        setState(201);
        declarations();
        break;
      }

      case DiagnosisDeclParser::ComponentID: {
        enterOuterAlt(_localctx, 4);
        setState(203);
        componentDecl();
        setState(204);
        declarations();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
        enterOuterAlt(_localctx, 5);

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

//----------------- ComponentsDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::ComponentsDeclContext::ComponentsDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ComponentsDeclContext::ComponentsID() {
  return getToken(DiagnosisDeclParser::ComponentsID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ComponentsDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::ComponentsBodyContext* DiagnosisDeclParser::ComponentsDeclContext::componentsBody() {
  return getRuleContext<DiagnosisDeclParser::ComponentsBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ComponentsDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::ComponentsDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleComponentsDecl;
}

void DiagnosisDeclParser::ComponentsDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentsDecl(this);
}

void DiagnosisDeclParser::ComponentsDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentsDecl(this);
}

DiagnosisDeclParser::ComponentsDeclContext* DiagnosisDeclParser::componentsDecl() {
  ComponentsDeclContext *_localctx = _tracker.createInstance<ComponentsDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, DiagnosisDeclParser::RuleComponentsDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(DiagnosisDeclParser::ComponentsID);
    setState(210);
    match(DiagnosisDeclParser::LBRACE);
    setState(211);
    componentsBody();
    setState(212);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentsBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::ComponentsBodyContext::ComponentsBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::ComponentDeclContext* DiagnosisDeclParser::ComponentsBodyContext::componentDecl() {
  return getRuleContext<DiagnosisDeclParser::ComponentDeclContext>(0);
}

DiagnosisDeclParser::ComponentsBodyContext* DiagnosisDeclParser::ComponentsBodyContext::componentsBody() {
  return getRuleContext<DiagnosisDeclParser::ComponentsBodyContext>(0);
}


size_t DiagnosisDeclParser::ComponentsBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleComponentsBody;
}

void DiagnosisDeclParser::ComponentsBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentsBody(this);
}

void DiagnosisDeclParser::ComponentsBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentsBody(this);
}

DiagnosisDeclParser::ComponentsBodyContext* DiagnosisDeclParser::componentsBody() {
  ComponentsBodyContext *_localctx = _tracker.createInstance<ComponentsBodyContext>(_ctx, getState());
  enterRule(_localctx, 14, DiagnosisDeclParser::RuleComponentsBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::ComponentID: {
        enterOuterAlt(_localctx, 1);
        setState(214);
        componentDecl();
        setState(215);
        componentsBody();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
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

//----------------- ComponentDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::ComponentDeclContext::ComponentDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ComponentDeclContext::ComponentID() {
  return getToken(DiagnosisDeclParser::ComponentID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ComponentDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::NameDeclContext* DiagnosisDeclParser::ComponentDeclContext::nameDecl() {
  return getRuleContext<DiagnosisDeclParser::NameDeclContext>(0);
}

DiagnosisDeclParser::ComponentBodyContext* DiagnosisDeclParser::ComponentDeclContext::componentBody() {
  return getRuleContext<DiagnosisDeclParser::ComponentBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ComponentDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::ComponentDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleComponentDecl;
}

void DiagnosisDeclParser::ComponentDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentDecl(this);
}

void DiagnosisDeclParser::ComponentDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentDecl(this);
}

DiagnosisDeclParser::ComponentDeclContext* DiagnosisDeclParser::componentDecl() {
  ComponentDeclContext *_localctx = _tracker.createInstance<ComponentDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, DiagnosisDeclParser::RuleComponentDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(DiagnosisDeclParser::ComponentID);
    setState(221);
    match(DiagnosisDeclParser::LBRACE);
    setState(222);
    nameDecl();
    setState(223);
    componentBody();
    setState(224);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::ComponentBodyContext::ComponentBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::AliasDefContext* DiagnosisDeclParser::ComponentBodyContext::aliasDef() {
  return getRuleContext<DiagnosisDeclParser::AliasDefContext>(0);
}

DiagnosisDeclParser::ComponentBodyContext* DiagnosisDeclParser::ComponentBodyContext::componentBody() {
  return getRuleContext<DiagnosisDeclParser::ComponentBodyContext>(0);
}

DiagnosisDeclParser::BaseTypeDeclContext* DiagnosisDeclParser::ComponentBodyContext::baseTypeDecl() {
  return getRuleContext<DiagnosisDeclParser::BaseTypeDeclContext>(0);
}

DiagnosisDeclParser::CheckDeclContext* DiagnosisDeclParser::ComponentBodyContext::checkDecl() {
  return getRuleContext<DiagnosisDeclParser::CheckDeclContext>(0);
}


size_t DiagnosisDeclParser::ComponentBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleComponentBody;
}

void DiagnosisDeclParser::ComponentBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentBody(this);
}

void DiagnosisDeclParser::ComponentBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentBody(this);
}

DiagnosisDeclParser::ComponentBodyContext* DiagnosisDeclParser::componentBody() {
  ComponentBodyContext *_localctx = _tracker.createInstance<ComponentBodyContext>(_ctx, getState());
  enterRule(_localctx, 18, DiagnosisDeclParser::RuleComponentBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::UseID: {
        enterOuterAlt(_localctx, 1);
        setState(226);
        aliasDef();
        setState(227);
        componentBody();
        break;
      }

      case DiagnosisDeclParser::BaseTypeID: {
        enterOuterAlt(_localctx, 2);
        setState(229);
        baseTypeDecl();
        setState(230);
        componentBody();
        break;
      }

      case DiagnosisDeclParser::ConditionID:
      case DiagnosisDeclParser::CheckID: {
        enterOuterAlt(_localctx, 3);
        setState(232);
        checkDecl();
        setState(233);
        componentBody();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
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

//----------------- DiagnosisSignalsDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::DiagnosisSignalsDeclContext::DiagnosisSignalsDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::DiagnosisSignalsDeclContext::SignalsID() {
  return getToken(DiagnosisDeclParser::SignalsID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::DiagnosisSignalsDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::DiagnosisSignalsBodyContext* DiagnosisDeclParser::DiagnosisSignalsDeclContext::diagnosisSignalsBody() {
  return getRuleContext<DiagnosisDeclParser::DiagnosisSignalsBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::DiagnosisSignalsDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::DiagnosisSignalsDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDiagnosisSignalsDecl;
}

void DiagnosisDeclParser::DiagnosisSignalsDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiagnosisSignalsDecl(this);
}

void DiagnosisDeclParser::DiagnosisSignalsDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiagnosisSignalsDecl(this);
}

DiagnosisDeclParser::DiagnosisSignalsDeclContext* DiagnosisDeclParser::diagnosisSignalsDecl() {
  DiagnosisSignalsDeclContext *_localctx = _tracker.createInstance<DiagnosisSignalsDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, DiagnosisDeclParser::RuleDiagnosisSignalsDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(DiagnosisDeclParser::SignalsID);
    setState(239);
    match(DiagnosisDeclParser::LBRACE);
    setState(240);
    diagnosisSignalsBody();
    setState(241);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiagnosisSignalsBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::DiagnosisSignalsBodyContext::DiagnosisSignalsBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::DiagnosisSignalDeclContext* DiagnosisDeclParser::DiagnosisSignalsBodyContext::diagnosisSignalDecl() {
  return getRuleContext<DiagnosisDeclParser::DiagnosisSignalDeclContext>(0);
}

DiagnosisDeclParser::DiagnosisSignalsBodyContext* DiagnosisDeclParser::DiagnosisSignalsBodyContext::diagnosisSignalsBody() {
  return getRuleContext<DiagnosisDeclParser::DiagnosisSignalsBodyContext>(0);
}


size_t DiagnosisDeclParser::DiagnosisSignalsBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDiagnosisSignalsBody;
}

void DiagnosisDeclParser::DiagnosisSignalsBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiagnosisSignalsBody(this);
}

void DiagnosisDeclParser::DiagnosisSignalsBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiagnosisSignalsBody(this);
}

DiagnosisDeclParser::DiagnosisSignalsBodyContext* DiagnosisDeclParser::diagnosisSignalsBody() {
  DiagnosisSignalsBodyContext *_localctx = _tracker.createInstance<DiagnosisSignalsBodyContext>(_ctx, getState());
  enterRule(_localctx, 22, DiagnosisDeclParser::RuleDiagnosisSignalsBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(247);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::SignalID: {
        enterOuterAlt(_localctx, 1);
        setState(243);
        diagnosisSignalDecl();
        setState(244);
        diagnosisSignalsBody();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
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

//----------------- DiagnosisSignalDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::DiagnosisSignalDeclContext::DiagnosisSignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::DiagnosisSignalDeclContext::SignalID() {
  return getToken(DiagnosisDeclParser::SignalID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::DiagnosisSignalDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::NameDeclContext* DiagnosisDeclParser::DiagnosisSignalDeclContext::nameDecl() {
  return getRuleContext<DiagnosisDeclParser::NameDeclContext>(0);
}

DiagnosisDeclParser::DiagnosisSignalBodyContext* DiagnosisDeclParser::DiagnosisSignalDeclContext::diagnosisSignalBody() {
  return getRuleContext<DiagnosisDeclParser::DiagnosisSignalBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::DiagnosisSignalDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::DiagnosisSignalDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDiagnosisSignalDecl;
}

void DiagnosisDeclParser::DiagnosisSignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiagnosisSignalDecl(this);
}

void DiagnosisDeclParser::DiagnosisSignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiagnosisSignalDecl(this);
}

DiagnosisDeclParser::DiagnosisSignalDeclContext* DiagnosisDeclParser::diagnosisSignalDecl() {
  DiagnosisSignalDeclContext *_localctx = _tracker.createInstance<DiagnosisSignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, DiagnosisDeclParser::RuleDiagnosisSignalDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(DiagnosisDeclParser::SignalID);
    setState(250);
    match(DiagnosisDeclParser::LBRACE);
    setState(251);
    nameDecl();
    setState(252);
    diagnosisSignalBody();
    setState(253);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiagnosisSignalBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::DiagnosisSignalBodyContext::DiagnosisSignalBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::AliasDefContext* DiagnosisDeclParser::DiagnosisSignalBodyContext::aliasDef() {
  return getRuleContext<DiagnosisDeclParser::AliasDefContext>(0);
}

DiagnosisDeclParser::DiagnosisSignalBodyContext* DiagnosisDeclParser::DiagnosisSignalBodyContext::diagnosisSignalBody() {
  return getRuleContext<DiagnosisDeclParser::DiagnosisSignalBodyContext>(0);
}

DiagnosisDeclParser::BaseTypeDeclContext* DiagnosisDeclParser::DiagnosisSignalBodyContext::baseTypeDecl() {
  return getRuleContext<DiagnosisDeclParser::BaseTypeDeclContext>(0);
}

DiagnosisDeclParser::CheckDeclContext* DiagnosisDeclParser::DiagnosisSignalBodyContext::checkDecl() {
  return getRuleContext<DiagnosisDeclParser::CheckDeclContext>(0);
}


size_t DiagnosisDeclParser::DiagnosisSignalBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDiagnosisSignalBody;
}

void DiagnosisDeclParser::DiagnosisSignalBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiagnosisSignalBody(this);
}

void DiagnosisDeclParser::DiagnosisSignalBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiagnosisSignalBody(this);
}

DiagnosisDeclParser::DiagnosisSignalBodyContext* DiagnosisDeclParser::diagnosisSignalBody() {
  DiagnosisSignalBodyContext *_localctx = _tracker.createInstance<DiagnosisSignalBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, DiagnosisDeclParser::RuleDiagnosisSignalBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::UseID: {
        enterOuterAlt(_localctx, 1);
        setState(255);
        aliasDef();
        setState(256);
        diagnosisSignalBody();
        break;
      }

      case DiagnosisDeclParser::BaseTypeID: {
        enterOuterAlt(_localctx, 2);
        setState(258);
        baseTypeDecl();
        setState(259);
        diagnosisSignalBody();
        break;
      }

      case DiagnosisDeclParser::ConditionID:
      case DiagnosisDeclParser::CheckID: {
        enterOuterAlt(_localctx, 3);
        setState(261);
        checkDecl();
        setState(262);
        diagnosisSignalBody();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
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

//----------------- BaseTypeDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::BaseTypeDeclContext::BaseTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::BaseTypeDeclContext::BaseTypeID() {
  return getToken(DiagnosisDeclParser::BaseTypeID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::BaseTypeDeclContext::COLON() {
  return getToken(DiagnosisDeclParser::COLON, 0);
}

DiagnosisDeclParser::IdPathContext* DiagnosisDeclParser::BaseTypeDeclContext::idPath() {
  return getRuleContext<DiagnosisDeclParser::IdPathContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::BaseTypeDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::BaseTypeDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleBaseTypeDecl;
}

void DiagnosisDeclParser::BaseTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaseTypeDecl(this);
}

void DiagnosisDeclParser::BaseTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaseTypeDecl(this);
}

DiagnosisDeclParser::BaseTypeDeclContext* DiagnosisDeclParser::baseTypeDecl() {
  BaseTypeDeclContext *_localctx = _tracker.createInstance<BaseTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, DiagnosisDeclParser::RuleBaseTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(DiagnosisDeclParser::BaseTypeID);
    setState(268);
    match(DiagnosisDeclParser::COLON);
    setState(269);
    idPath();
    setState(270);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::CheckDeclContext::CheckDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::CheckDeclContext::ConditionID() {
  return getToken(DiagnosisDeclParser::ConditionID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::CheckDeclContext::COLON() {
  return getToken(DiagnosisDeclParser::COLON, 0);
}

tree::TerminalNode* DiagnosisDeclParser::CheckDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::CheckDeclContext::expression() {
  return getRuleContext<DiagnosisDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::CheckDeclContext::CheckID() {
  return getToken(DiagnosisDeclParser::CheckID, 0);
}


size_t DiagnosisDeclParser::CheckDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleCheckDecl;
}

void DiagnosisDeclParser::CheckDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckDecl(this);
}

void DiagnosisDeclParser::CheckDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckDecl(this);
}

DiagnosisDeclParser::CheckDeclContext* DiagnosisDeclParser::checkDecl() {
  CheckDeclContext *_localctx = _tracker.createInstance<CheckDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, DiagnosisDeclParser::RuleCheckDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::ConditionID: {
        enterOuterAlt(_localctx, 1);
        setState(272);
        match(DiagnosisDeclParser::ConditionID);
        setState(273);
        match(DiagnosisDeclParser::COLON);
        setState(274);
        dynamic_cast<CheckDeclContext *>(_localctx)->necExp = expression();
        setState(275);
        match(DiagnosisDeclParser::SEMI);
        break;
      }

      case DiagnosisDeclParser::CheckID: {
        enterOuterAlt(_localctx, 2);
        setState(277);
        match(DiagnosisDeclParser::CheckID);
        setState(278);
        match(DiagnosisDeclParser::COLON);
        setState(279);
        dynamic_cast<CheckDeclContext *>(_localctx)->suffExp = expression();
        setState(280);
        match(DiagnosisDeclParser::SEMI);
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

DiagnosisDeclParser::AliasDefContext::AliasDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::AliasDefContext::UseID() {
  return getToken(DiagnosisDeclParser::UseID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AliasDefContext::AsID() {
  return getToken(DiagnosisDeclParser::AsID, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::AliasDefContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::AliasDefContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

DiagnosisDeclParser::IdPathContext* DiagnosisDeclParser::AliasDefContext::idPath() {
  return getRuleContext<DiagnosisDeclParser::IdPathContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::AliasDefContext::INT() {
  return getToken(DiagnosisDeclParser::INT, 0);
}


size_t DiagnosisDeclParser::AliasDefContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleAliasDef;
}

void DiagnosisDeclParser::AliasDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasDef(this);
}

void DiagnosisDeclParser::AliasDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasDef(this);
}

DiagnosisDeclParser::AliasDefContext* DiagnosisDeclParser::aliasDef() {
  AliasDefContext *_localctx = _tracker.createInstance<AliasDefContext>(_ctx, getState());
  enterRule(_localctx, 32, DiagnosisDeclParser::RuleAliasDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(DiagnosisDeclParser::UseID);
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
        setState(285);
        idPath();
        break;
      }

      case DiagnosisDeclParser::INT: {
        setState(286);
        match(DiagnosisDeclParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(289);
    match(DiagnosisDeclParser::AsID);
    setState(290);
    contextID();
    setState(291);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequenceDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::SequenceDeclContext::SequenceDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::SequenceDeclContext::SequenceID() {
  return getToken(DiagnosisDeclParser::SequenceID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::SequenceDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::SequenceBodyContext* DiagnosisDeclParser::SequenceDeclContext::sequenceBody() {
  return getRuleContext<DiagnosisDeclParser::SequenceBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::SequenceDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::SequenceDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSequenceDecl;
}

void DiagnosisDeclParser::SequenceDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequenceDecl(this);
}

void DiagnosisDeclParser::SequenceDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequenceDecl(this);
}

DiagnosisDeclParser::SequenceDeclContext* DiagnosisDeclParser::sequenceDecl() {
  SequenceDeclContext *_localctx = _tracker.createInstance<SequenceDeclContext>(_ctx, getState());
  enterRule(_localctx, 34, DiagnosisDeclParser::RuleSequenceDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    match(DiagnosisDeclParser::SequenceID);
    setState(294);
    match(DiagnosisDeclParser::LBRACE);
    setState(295);
    sequenceBody();
    setState(296);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequenceBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::SequenceBodyContext::SequenceBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::MessageDeclContext* DiagnosisDeclParser::SequenceBodyContext::messageDecl() {
  return getRuleContext<DiagnosisDeclParser::MessageDeclContext>(0);
}

DiagnosisDeclParser::SequenceBodyContext* DiagnosisDeclParser::SequenceBodyContext::sequenceBody() {
  return getRuleContext<DiagnosisDeclParser::SequenceBodyContext>(0);
}

DiagnosisDeclParser::LoopDeclContext* DiagnosisDeclParser::SequenceBodyContext::loopDecl() {
  return getRuleContext<DiagnosisDeclParser::LoopDeclContext>(0);
}

DiagnosisDeclParser::ParallelDeclContext* DiagnosisDeclParser::SequenceBodyContext::parallelDecl() {
  return getRuleContext<DiagnosisDeclParser::ParallelDeclContext>(0);
}


size_t DiagnosisDeclParser::SequenceBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSequenceBody;
}

void DiagnosisDeclParser::SequenceBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequenceBody(this);
}

void DiagnosisDeclParser::SequenceBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequenceBody(this);
}

DiagnosisDeclParser::SequenceBodyContext* DiagnosisDeclParser::sequenceBody() {
  SequenceBodyContext *_localctx = _tracker.createInstance<SequenceBodyContext>(_ctx, getState());
  enterRule(_localctx, 36, DiagnosisDeclParser::RuleSequenceBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::MessageID: {
        enterOuterAlt(_localctx, 1);
        setState(298);
        messageDecl();
        setState(299);
        sequenceBody();
        break;
      }

      case DiagnosisDeclParser::LoopID: {
        enterOuterAlt(_localctx, 2);
        setState(301);
        loopDecl();
        setState(302);
        sequenceBody();
        break;
      }

      case DiagnosisDeclParser::ParallelID: {
        enterOuterAlt(_localctx, 3);
        setState(304);
        parallelDecl();
        setState(305);
        sequenceBody();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
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

//----------------- MessageDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::MessageDeclContext::MessageDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::MessageDeclContext::MessageID() {
  return getToken(DiagnosisDeclParser::MessageID, 0);
}

DiagnosisDeclParser::IdPathContext* DiagnosisDeclParser::MessageDeclContext::idPath() {
  return getRuleContext<DiagnosisDeclParser::IdPathContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::MessageDeclContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::MessageDeclContext::expression() {
  return getRuleContext<DiagnosisDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::MessageDeclContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}

tree::TerminalNode* DiagnosisDeclParser::MessageDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::MessageDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleMessageDecl;
}

void DiagnosisDeclParser::MessageDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageDecl(this);
}

void DiagnosisDeclParser::MessageDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageDecl(this);
}

DiagnosisDeclParser::MessageDeclContext* DiagnosisDeclParser::messageDecl() {
  MessageDeclContext *_localctx = _tracker.createInstance<MessageDeclContext>(_ctx, getState());
  enterRule(_localctx, 38, DiagnosisDeclParser::RuleMessageDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(DiagnosisDeclParser::MessageID);
    setState(311);
    idPath();
    setState(312);
    match(DiagnosisDeclParser::LPAREN);
    setState(313);
    expression();
    setState(314);
    match(DiagnosisDeclParser::RPAREN);
    setState(315);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

DiagnosisDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::ExpressionContext::expression() {
  return getRuleContext<DiagnosisDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}

DiagnosisDeclParser::ExpressionOptionalContext* DiagnosisDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<DiagnosisDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(DiagnosisDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionContext::NotIdWord() {
  return getToken(DiagnosisDeclParser::NotIdWord, 0);
}

DiagnosisDeclParser::AtomContext* DiagnosisDeclParser::ExpressionContext::atom() {
  return getRuleContext<DiagnosisDeclParser::AtomContext>(0);
}


size_t DiagnosisDeclParser::ExpressionContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleExpression;
}

void DiagnosisDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void DiagnosisDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, DiagnosisDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(317);
        match(DiagnosisDeclParser::LPAREN);
        setState(318);
        expression();
        setState(319);
        match(DiagnosisDeclParser::RPAREN);
        setState(320);
        expressionOptional();
        break;
      }

      case DiagnosisDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 2);
        setState(322);
        match(DiagnosisDeclParser::NotIdSymbol);
        setState(323);
        expression();
        break;
      }

      case DiagnosisDeclParser::NotIdWord: {
        enterOuterAlt(_localctx, 3);
        setState(324);
        match(DiagnosisDeclParser::NotIdWord);
        setState(325);
        expression();
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::TrueID:
      case DiagnosisDeclParser::FalseID:
      case DiagnosisDeclParser::INT:
      case DiagnosisDeclParser::REAL:
      case DiagnosisDeclParser::STRING:
      case DiagnosisDeclParser::ID: {
        enterOuterAlt(_localctx, 4);
        setState(326);
        atom();
        setState(327);
        expressionOptional();
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

//----------------- ExpressionOptionalContext ------------------------------------------------------------------

DiagnosisDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<DiagnosisDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(DiagnosisDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(DiagnosisDeclParser::OrIdWord, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(DiagnosisDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(DiagnosisDeclParser::AndIdWord, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(DiagnosisDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(DiagnosisDeclParser::ASSIGN);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(DiagnosisDeclParser::ASSIGN, i);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(DiagnosisDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(DiagnosisDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(DiagnosisDeclParser::GREATERTHAN, 0);
}


size_t DiagnosisDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleExpressionOptional;
}

void DiagnosisDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void DiagnosisDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

DiagnosisDeclParser::ExpressionOptionalContext* DiagnosisDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 42, DiagnosisDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(354);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::NotIdSymbol:
      case DiagnosisDeclParser::AndIdSymbol:
      case DiagnosisDeclParser::OrIdSymbol:
      case DiagnosisDeclParser::NotIdWord:
      case DiagnosisDeclParser::AndIdWord:
      case DiagnosisDeclParser::OrIdWord:
      case DiagnosisDeclParser::ASSIGN:
      case DiagnosisDeclParser::LESSTHAN:
      case DiagnosisDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(350);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case DiagnosisDeclParser::OrIdSymbol: {
            setState(331);
            match(DiagnosisDeclParser::OrIdSymbol);
            break;
          }

          case DiagnosisDeclParser::OrIdWord: {
            setState(332);
            match(DiagnosisDeclParser::OrIdWord);
            break;
          }

          case DiagnosisDeclParser::AndIdSymbol: {
            setState(333);
            match(DiagnosisDeclParser::AndIdSymbol);
            break;
          }

          case DiagnosisDeclParser::AndIdWord: {
            setState(334);
            match(DiagnosisDeclParser::AndIdWord);
            break;
          }

          case DiagnosisDeclParser::ASSIGN: {
            setState(335);
            match(DiagnosisDeclParser::ASSIGN);
            setState(336);
            match(DiagnosisDeclParser::ASSIGN);
            break;
          }

          case DiagnosisDeclParser::NotIdSymbol: {
            setState(337);
            match(DiagnosisDeclParser::NotIdSymbol);
            setState(338);
            match(DiagnosisDeclParser::ASSIGN);
            break;
          }

          case DiagnosisDeclParser::NotIdWord: {
            setState(339);
            match(DiagnosisDeclParser::NotIdWord);
            break;
          }

          case DiagnosisDeclParser::LESSTHAN: {
            setState(340);
            match(DiagnosisDeclParser::LESSTHAN);
            setState(343);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case DiagnosisDeclParser::ASSIGN: {
                setState(341);
                match(DiagnosisDeclParser::ASSIGN);
                break;
              }

              case DiagnosisDeclParser::NameID:
              case DiagnosisDeclParser::LabelID:
              case DiagnosisDeclParser::EnabledID:
              case DiagnosisDeclParser::TypeID:
              case DiagnosisDeclParser::AttributeID:
              case DiagnosisDeclParser::SignalID:
              case DiagnosisDeclParser::PortID:
              case DiagnosisDeclParser::ImportID:
              case DiagnosisDeclParser::FromID:
              case DiagnosisDeclParser::ToID:
              case DiagnosisDeclParser::AsID:
              case DiagnosisDeclParser::NotIdSymbol:
              case DiagnosisDeclParser::NotIdWord:
              case DiagnosisDeclParser::TrueID:
              case DiagnosisDeclParser::FalseID:
              case DiagnosisDeclParser::INT:
              case DiagnosisDeclParser::REAL:
              case DiagnosisDeclParser::STRING:
              case DiagnosisDeclParser::ID:
              case DiagnosisDeclParser::LPAREN: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case DiagnosisDeclParser::GREATERTHAN: {
            setState(345);
            match(DiagnosisDeclParser::GREATERTHAN);
            setState(348);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case DiagnosisDeclParser::ASSIGN: {
                setState(346);
                match(DiagnosisDeclParser::ASSIGN);
                break;
              }

              case DiagnosisDeclParser::NameID:
              case DiagnosisDeclParser::LabelID:
              case DiagnosisDeclParser::EnabledID:
              case DiagnosisDeclParser::TypeID:
              case DiagnosisDeclParser::AttributeID:
              case DiagnosisDeclParser::SignalID:
              case DiagnosisDeclParser::PortID:
              case DiagnosisDeclParser::ImportID:
              case DiagnosisDeclParser::FromID:
              case DiagnosisDeclParser::ToID:
              case DiagnosisDeclParser::AsID:
              case DiagnosisDeclParser::NotIdSymbol:
              case DiagnosisDeclParser::NotIdWord:
              case DiagnosisDeclParser::TrueID:
              case DiagnosisDeclParser::FalseID:
              case DiagnosisDeclParser::INT:
              case DiagnosisDeclParser::REAL:
              case DiagnosisDeclParser::STRING:
              case DiagnosisDeclParser::ID:
              case DiagnosisDeclParser::LPAREN: {
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
        setState(352);
        expression();
        break;
      }

      case DiagnosisDeclParser::RPAREN:
      case DiagnosisDeclParser::SEMI: {
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

//----------------- AtomContext ------------------------------------------------------------------

DiagnosisDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::IdPathContext* DiagnosisDeclParser::AtomContext::idPath() {
  return getRuleContext<DiagnosisDeclParser::IdPathContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::REAL() {
  return getToken(DiagnosisDeclParser::REAL, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::STRING() {
  return getToken(DiagnosisDeclParser::STRING, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::INT() {
  return getToken(DiagnosisDeclParser::INT, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::TrueID() {
  return getToken(DiagnosisDeclParser::TrueID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::FalseID() {
  return getToken(DiagnosisDeclParser::FalseID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::FromID() {
  return getToken(DiagnosisDeclParser::FromID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AtomContext::ToID() {
  return getToken(DiagnosisDeclParser::ToID, 0);
}


size_t DiagnosisDeclParser::AtomContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleAtom;
}

void DiagnosisDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void DiagnosisDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

DiagnosisDeclParser::AtomContext* DiagnosisDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 44, DiagnosisDeclParser::RuleAtom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(356);
      idPath();
      setState(360);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DiagnosisDeclParser::LPAREN: {
          setState(357);
          match(DiagnosisDeclParser::LPAREN);
          setState(358);
          match(DiagnosisDeclParser::RPAREN);
          break;
        }

        case DiagnosisDeclParser::NotIdSymbol:
        case DiagnosisDeclParser::AndIdSymbol:
        case DiagnosisDeclParser::OrIdSymbol:
        case DiagnosisDeclParser::NotIdWord:
        case DiagnosisDeclParser::AndIdWord:
        case DiagnosisDeclParser::OrIdWord:
        case DiagnosisDeclParser::ASSIGN:
        case DiagnosisDeclParser::RPAREN:
        case DiagnosisDeclParser::LESSTHAN:
        case DiagnosisDeclParser::GREATERTHAN:
        case DiagnosisDeclParser::SEMI:
        case DiagnosisDeclParser::PLUS:
        case DiagnosisDeclParser::MINUS:
        case DiagnosisDeclParser::MULT:
        case DiagnosisDeclParser::DIV: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(362);
      _la = _input->LA(1);
      if (!(((((_la - 54) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 54)) & ((1ULL << (DiagnosisDeclParser::TrueID - 54))
        | (1ULL << (DiagnosisDeclParser::FalseID - 54))
        | (1ULL << (DiagnosisDeclParser::INT - 54))
        | (1ULL << (DiagnosisDeclParser::REAL - 54))
        | (1ULL << (DiagnosisDeclParser::STRING - 54)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(363);
      match(DiagnosisDeclParser::FromID);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(364);
      match(DiagnosisDeclParser::ToID);
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

//----------------- LoopDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::LoopDeclContext::LoopDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::LoopDeclContext::LoopID() {
  return getToken(DiagnosisDeclParser::LoopID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LoopDeclContext::LBRACKET() {
  return getToken(DiagnosisDeclParser::LBRACKET, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LoopDeclContext::INT() {
  return getToken(DiagnosisDeclParser::INT, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LoopDeclContext::RBRACKET() {
  return getToken(DiagnosisDeclParser::RBRACKET, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LoopDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::SequenceBodyContext* DiagnosisDeclParser::LoopDeclContext::sequenceBody() {
  return getRuleContext<DiagnosisDeclParser::SequenceBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::LoopDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::LoopDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleLoopDecl;
}

void DiagnosisDeclParser::LoopDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopDecl(this);
}

void DiagnosisDeclParser::LoopDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopDecl(this);
}

DiagnosisDeclParser::LoopDeclContext* DiagnosisDeclParser::loopDecl() {
  LoopDeclContext *_localctx = _tracker.createInstance<LoopDeclContext>(_ctx, getState());
  enterRule(_localctx, 46, DiagnosisDeclParser::RuleLoopDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(DiagnosisDeclParser::LoopID);
    setState(368);
    match(DiagnosisDeclParser::LBRACKET);
    setState(369);
    match(DiagnosisDeclParser::INT);
    setState(370);
    match(DiagnosisDeclParser::RBRACKET);
    setState(371);
    match(DiagnosisDeclParser::LBRACE);
    setState(372);
    sequenceBody();
    setState(373);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParallelDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::ParallelDeclContext::ParallelDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ParallelDeclContext::ParallelID() {
  return getToken(DiagnosisDeclParser::ParallelID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ParallelDeclContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::ParallelBodysContext* DiagnosisDeclParser::ParallelDeclContext::parallelBodys() {
  return getRuleContext<DiagnosisDeclParser::ParallelBodysContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ParallelDeclContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::ParallelDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleParallelDecl;
}

void DiagnosisDeclParser::ParallelDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParallelDecl(this);
}

void DiagnosisDeclParser::ParallelDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParallelDecl(this);
}

DiagnosisDeclParser::ParallelDeclContext* DiagnosisDeclParser::parallelDecl() {
  ParallelDeclContext *_localctx = _tracker.createInstance<ParallelDeclContext>(_ctx, getState());
  enterRule(_localctx, 48, DiagnosisDeclParser::RuleParallelDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
    match(DiagnosisDeclParser::ParallelID);
    setState(376);
    match(DiagnosisDeclParser::LBRACE);
    setState(377);
    parallelBodys();
    setState(378);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParallelBodysContext ------------------------------------------------------------------

DiagnosisDeclParser::ParallelBodysContext::ParallelBodysContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::ParallelBodyContext* DiagnosisDeclParser::ParallelBodysContext::parallelBody() {
  return getRuleContext<DiagnosisDeclParser::ParallelBodyContext>(0);
}

DiagnosisDeclParser::ParallelBodysContext* DiagnosisDeclParser::ParallelBodysContext::parallelBodys() {
  return getRuleContext<DiagnosisDeclParser::ParallelBodysContext>(0);
}


size_t DiagnosisDeclParser::ParallelBodysContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleParallelBodys;
}

void DiagnosisDeclParser::ParallelBodysContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParallelBodys(this);
}

void DiagnosisDeclParser::ParallelBodysContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParallelBodys(this);
}

DiagnosisDeclParser::ParallelBodysContext* DiagnosisDeclParser::parallelBodys() {
  ParallelBodysContext *_localctx = _tracker.createInstance<ParallelBodysContext>(_ctx, getState());
  enterRule(_localctx, 50, DiagnosisDeclParser::RuleParallelBodys);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::ParallelSequenceID: {
        enterOuterAlt(_localctx, 1);
        setState(380);
        parallelBody();
        setState(381);
        parallelBodys();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
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

//----------------- ParallelBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::ParallelBodyContext::ParallelBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ParallelBodyContext::ParallelSequenceID() {
  return getToken(DiagnosisDeclParser::ParallelSequenceID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ParallelBodyContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

DiagnosisDeclParser::SequenceBodyContext* DiagnosisDeclParser::ParallelBodyContext::sequenceBody() {
  return getRuleContext<DiagnosisDeclParser::SequenceBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ParallelBodyContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}


size_t DiagnosisDeclParser::ParallelBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleParallelBody;
}

void DiagnosisDeclParser::ParallelBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParallelBody(this);
}

void DiagnosisDeclParser::ParallelBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParallelBody(this);
}

DiagnosisDeclParser::ParallelBodyContext* DiagnosisDeclParser::parallelBody() {
  ParallelBodyContext *_localctx = _tracker.createInstance<ParallelBodyContext>(_ctx, getState());
  enterRule(_localctx, 52, DiagnosisDeclParser::RuleParallelBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(DiagnosisDeclParser::ParallelSequenceID);
    setState(387);
    match(DiagnosisDeclParser::LBRACE);
    setState(388);
    sequenceBody();
    setState(389);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnabledDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::EnabledDeclContext::EnabledDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::EnabledDeclContext::EnabledID() {
  return getToken(DiagnosisDeclParser::EnabledID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::EnabledDeclContext::COLON() {
  return getToken(DiagnosisDeclParser::COLON, 0);
}

tree::TerminalNode* DiagnosisDeclParser::EnabledDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

tree::TerminalNode* DiagnosisDeclParser::EnabledDeclContext::TrueID() {
  return getToken(DiagnosisDeclParser::TrueID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::EnabledDeclContext::FalseID() {
  return getToken(DiagnosisDeclParser::FalseID, 0);
}


size_t DiagnosisDeclParser::EnabledDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleEnabledDecl;
}

void DiagnosisDeclParser::EnabledDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnabledDecl(this);
}

void DiagnosisDeclParser::EnabledDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnabledDecl(this);
}

DiagnosisDeclParser::EnabledDeclContext* DiagnosisDeclParser::enabledDecl() {
  EnabledDeclContext *_localctx = _tracker.createInstance<EnabledDeclContext>(_ctx, getState());
  enterRule(_localctx, 54, DiagnosisDeclParser::RuleEnabledDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    match(DiagnosisDeclParser::EnabledID);
    setState(392);
    match(DiagnosisDeclParser::COLON);
    setState(393);
    _la = _input->LA(1);
    if (!(_la == DiagnosisDeclParser::TrueID

    || _la == DiagnosisDeclParser::FalseID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(394);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentIdPathContext ------------------------------------------------------------------

DiagnosisDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DiagnosisDeclParser::ContextIDContext *> DiagnosisDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<DiagnosisDeclParser::ContextIDContext>();
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(DiagnosisDeclParser::DOT);
}

tree::TerminalNode* DiagnosisDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(DiagnosisDeclParser::DOT, i);
}


size_t DiagnosisDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleComponentIdPath;
}

void DiagnosisDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void DiagnosisDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

DiagnosisDeclParser::ComponentIdPathContext* DiagnosisDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 56, DiagnosisDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    contextID();
    setState(401);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DiagnosisDeclParser::DOT) {
      setState(397);
      match(DiagnosisDeclParser::DOT);
      setState(398);
      contextID();
      setState(403);
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

DiagnosisDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DiagnosisDeclParser::ContextIDContext *> DiagnosisDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<DiagnosisDeclParser::ContextIDContext>();
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::SignalIdPathContext::DOT() {
  return getTokens(DiagnosisDeclParser::DOT);
}

tree::TerminalNode* DiagnosisDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(DiagnosisDeclParser::DOT, i);
}


size_t DiagnosisDeclParser::SignalIdPathContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSignalIdPath;
}

void DiagnosisDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void DiagnosisDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

DiagnosisDeclParser::SignalIdPathContext* DiagnosisDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 58, DiagnosisDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    contextID();
    setState(409);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DiagnosisDeclParser::DOT) {
      setState(405);
      match(DiagnosisDeclParser::DOT);
      setState(406);
      contextID();
      setState(411);
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

DiagnosisDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::AttributeNameContext* DiagnosisDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<DiagnosisDeclParser::AttributeNameContext>(0);
}

std::vector<DiagnosisDeclParser::ContextIDContext *> DiagnosisDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<DiagnosisDeclParser::ContextIDContext>();
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(DiagnosisDeclParser::DOT);
}

tree::TerminalNode* DiagnosisDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(DiagnosisDeclParser::DOT, i);
}


size_t DiagnosisDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleAttributeIdPath;
}

void DiagnosisDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void DiagnosisDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

DiagnosisDeclParser::AttributeIdPathContext* DiagnosisDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 60, DiagnosisDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(421);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(412);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(413);
      contextID();
      setState(418);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DiagnosisDeclParser::DOT) {
        setState(414);
        match(DiagnosisDeclParser::DOT);
        setState(415);
        contextID();
        setState(420);
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

DiagnosisDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::SignalIdPathContext* DiagnosisDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<DiagnosisDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::SignalSendContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

DiagnosisDeclParser::FunctionCallBodyContext* DiagnosisDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<DiagnosisDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::SignalSendContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}


size_t DiagnosisDeclParser::SignalSendContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSignalSend;
}

void DiagnosisDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void DiagnosisDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

DiagnosisDeclParser::SignalSendContext* DiagnosisDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 62, DiagnosisDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(423);
    signalIdPath();
    setState(424);
    match(DiagnosisDeclParser::LPAREN);
    setState(425);
    functionCallBody();
    setState(426);
    match(DiagnosisDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DiagnosisDeclParser::TypeDefDeclContext *> DiagnosisDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<DiagnosisDeclParser::TypeDefDeclContext>();
}

DiagnosisDeclParser::TypeDefDeclContext* DiagnosisDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<DiagnosisDeclParser::TypeDefDeclContext>(i);
}

std::vector<DiagnosisDeclParser::AttributeDeclContext *> DiagnosisDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<DiagnosisDeclParser::AttributeDeclContext>();
}

DiagnosisDeclParser::AttributeDeclContext* DiagnosisDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<DiagnosisDeclParser::AttributeDeclContext>(i);
}

std::vector<DiagnosisDeclParser::SignalDeclContext *> DiagnosisDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<DiagnosisDeclParser::SignalDeclContext>();
}

DiagnosisDeclParser::SignalDeclContext* DiagnosisDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<DiagnosisDeclParser::SignalDeclContext>(i);
}


size_t DiagnosisDeclParser::CommonDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleCommonDecl;
}

void DiagnosisDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void DiagnosisDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

DiagnosisDeclParser::CommonDeclContext* DiagnosisDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 64, DiagnosisDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DiagnosisDeclParser::TypeID)
      | (1ULL << DiagnosisDeclParser::AttributeID)
      | (1ULL << DiagnosisDeclParser::SignalID))) != 0)) {
      setState(431);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DiagnosisDeclParser::TypeID: {
          setState(428);
          typeDefDecl();
          break;
        }

        case DiagnosisDeclParser::AttributeID: {
          setState(429);
          attributeDecl();
          break;
        }

        case DiagnosisDeclParser::SignalID: {
          setState(430);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(435);
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

DiagnosisDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::ImportPathBodyContext* DiagnosisDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<DiagnosisDeclParser::ImportPathBodyContext>(0);
}

DiagnosisDeclParser::ImportPathDeclContext* DiagnosisDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<DiagnosisDeclParser::ImportPathDeclContext>(0);
}


size_t DiagnosisDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleImportPathDecl;
}

void DiagnosisDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void DiagnosisDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

DiagnosisDeclParser::ImportPathDeclContext* DiagnosisDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, DiagnosisDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(440);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::ImportID: {
        enterOuterAlt(_localctx, 1);
        setState(436);
        importPathBody();
        setState(437);
        importPathDecl();
        break;
      }

      case DiagnosisDeclParser::EOF:
      case DiagnosisDeclParser::RuleID: {
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

DiagnosisDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(DiagnosisDeclParser::ImportID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(DiagnosisDeclParser::LESSTHAN, 0);
}

DiagnosisDeclParser::ImportFileBodyContext* DiagnosisDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<DiagnosisDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(DiagnosisDeclParser::GREATERTHAN, 0);
}

DiagnosisDeclParser::ImportAsContext* DiagnosisDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<DiagnosisDeclParser::ImportAsContext>(0);
}


size_t DiagnosisDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleImportPathBody;
}

void DiagnosisDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void DiagnosisDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

DiagnosisDeclParser::ImportPathBodyContext* DiagnosisDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 68, DiagnosisDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(442);
    match(DiagnosisDeclParser::ImportID);
    setState(443);
    match(DiagnosisDeclParser::LESSTHAN);
    setState(444);
    importFileBody();
    setState(445);
    match(DiagnosisDeclParser::GREATERTHAN);
    setState(446);
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

DiagnosisDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DiagnosisDeclParser::ContextIDContext *> DiagnosisDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<DiagnosisDeclParser::ContextIDContext>();
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* DiagnosisDeclParser::ImportFileBodyContext::DOT() {
  return getToken(DiagnosisDeclParser::DOT, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(DiagnosisDeclParser::RANGE, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ImportFileBodyContext::DIV() {
  return getToken(DiagnosisDeclParser::DIV, 0);
}

DiagnosisDeclParser::ImportFileBodyContext* DiagnosisDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<DiagnosisDeclParser::ImportFileBodyContext>(0);
}


size_t DiagnosisDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleImportFileBody;
}

void DiagnosisDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void DiagnosisDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

DiagnosisDeclParser::ImportFileBodyContext* DiagnosisDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 70, DiagnosisDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(459);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(448);
      contextID();
      setState(449);
      match(DiagnosisDeclParser::DOT);
      setState(450);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(452);
      match(DiagnosisDeclParser::RANGE);
      setState(453);
      match(DiagnosisDeclParser::DIV);
      setState(454);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(455);
      contextID();
      setState(456);
      match(DiagnosisDeclParser::DIV);
      setState(457);
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

DiagnosisDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ImportAsContext::AsID() {
  return getToken(DiagnosisDeclParser::AsID, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::ImportAsContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}


size_t DiagnosisDeclParser::ImportAsContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleImportAs;
}

void DiagnosisDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void DiagnosisDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

DiagnosisDeclParser::ImportAsContext* DiagnosisDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 72, DiagnosisDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(464);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(461);
        match(DiagnosisDeclParser::AsID);
        setState(462);
        contextID();
        break;
      }

      case DiagnosisDeclParser::EOF:
      case DiagnosisDeclParser::RuleID:
      case DiagnosisDeclParser::ImportID: {
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

DiagnosisDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(DiagnosisDeclParser::TypeID, 0);
}

DiagnosisDeclParser::TypeDeclContext* DiagnosisDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<DiagnosisDeclParser::TypeDeclContext>(0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleTypeDefDecl;
}

void DiagnosisDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void DiagnosisDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

DiagnosisDeclParser::TypeDefDeclContext* DiagnosisDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 74, DiagnosisDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    match(DiagnosisDeclParser::TypeID);
    setState(467);
    typeDecl();
    setState(468);
    contextID();
    setState(469);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::IntTypeDeclContext* DiagnosisDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<DiagnosisDeclParser::IntTypeDeclContext>(0);
}

DiagnosisDeclParser::RealTypeDeclContext* DiagnosisDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<DiagnosisDeclParser::RealTypeDeclContext>(0);
}

DiagnosisDeclParser::EnumTypeDeclContext* DiagnosisDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<DiagnosisDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::TypeDeclContext::BoolID() {
  return getToken(DiagnosisDeclParser::BoolID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::TypeDeclContext::StringID() {
  return getToken(DiagnosisDeclParser::StringID, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}


size_t DiagnosisDeclParser::TypeDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleTypeDecl;
}

void DiagnosisDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void DiagnosisDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

DiagnosisDeclParser::TypeDeclContext* DiagnosisDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 76, DiagnosisDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(477);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(471);
        intTypeDecl();
        break;
      }

      case DiagnosisDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(472);
        realTypeDecl();
        break;
      }

      case DiagnosisDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(473);
        enumTypeDecl();
        break;
      }

      case DiagnosisDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(474);
        match(DiagnosisDeclParser::BoolID);
        break;
      }

      case DiagnosisDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(475);
        match(DiagnosisDeclParser::StringID);
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(476);
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

DiagnosisDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::IntTypeDeclContext::IntID() {
  return getToken(DiagnosisDeclParser::IntID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::IntTypeDeclContext::INT() {
  return getTokens(DiagnosisDeclParser::INT);
}

tree::TerminalNode* DiagnosisDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(DiagnosisDeclParser::INT, i);
}

tree::TerminalNode* DiagnosisDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(DiagnosisDeclParser::RANGE, 0);
}

tree::TerminalNode* DiagnosisDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}


size_t DiagnosisDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleIntTypeDecl;
}

void DiagnosisDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void DiagnosisDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

DiagnosisDeclParser::IntTypeDeclContext* DiagnosisDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 78, DiagnosisDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(DiagnosisDeclParser::IntID);
    setState(486);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::LPAREN: {
        setState(480);
        match(DiagnosisDeclParser::LPAREN);
        setState(481);
        match(DiagnosisDeclParser::INT);
        setState(482);
        match(DiagnosisDeclParser::RANGE);
        setState(483);
        match(DiagnosisDeclParser::INT);
        setState(484);
        match(DiagnosisDeclParser::RPAREN);
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
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

DiagnosisDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::RealTypeDeclContext::RealID() {
  return getToken(DiagnosisDeclParser::RealID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(DiagnosisDeclParser::REAL);
}

tree::TerminalNode* DiagnosisDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(DiagnosisDeclParser::REAL, i);
}

tree::TerminalNode* DiagnosisDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(DiagnosisDeclParser::RANGE, 0);
}

tree::TerminalNode* DiagnosisDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}


size_t DiagnosisDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleRealTypeDecl;
}

void DiagnosisDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void DiagnosisDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

DiagnosisDeclParser::RealTypeDeclContext* DiagnosisDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 80, DiagnosisDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    match(DiagnosisDeclParser::RealID);
    setState(495);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::LPAREN: {
        setState(489);
        match(DiagnosisDeclParser::LPAREN);
        setState(490);
        match(DiagnosisDeclParser::REAL);
        setState(491);
        match(DiagnosisDeclParser::RANGE);
        setState(492);
        match(DiagnosisDeclParser::REAL);
        setState(493);
        match(DiagnosisDeclParser::RPAREN);
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
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

DiagnosisDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(DiagnosisDeclParser::EnumID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

std::vector<DiagnosisDeclParser::ContextIDContext *> DiagnosisDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<DiagnosisDeclParser::ContextIDContext>();
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* DiagnosisDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(DiagnosisDeclParser::COMMA);
}

tree::TerminalNode* DiagnosisDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(DiagnosisDeclParser::COMMA, i);
}


size_t DiagnosisDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleEnumTypeDecl;
}

void DiagnosisDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void DiagnosisDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

DiagnosisDeclParser::EnumTypeDeclContext* DiagnosisDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 82, DiagnosisDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
    match(DiagnosisDeclParser::EnumID);
    setState(498);
    match(DiagnosisDeclParser::LPAREN);
    setState(499);
    contextID();
    setState(504);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DiagnosisDeclParser::COMMA) {
      setState(500);
      match(DiagnosisDeclParser::COMMA);
      setState(501);
      contextID();
      setState(506);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(507);
    match(DiagnosisDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(DiagnosisDeclParser::AttributeID, 0);
}

DiagnosisDeclParser::TypeDeclContext* DiagnosisDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<DiagnosisDeclParser::TypeDeclContext>(0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::AttributeDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

tree::TerminalNode* DiagnosisDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(DiagnosisDeclParser::ASSIGN, 0);
}

DiagnosisDeclParser::LiteralValueContext* DiagnosisDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<DiagnosisDeclParser::LiteralValueContext>(0);
}


size_t DiagnosisDeclParser::AttributeDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleAttributeDecl;
}

void DiagnosisDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void DiagnosisDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

DiagnosisDeclParser::AttributeDeclContext* DiagnosisDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 84, DiagnosisDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    match(DiagnosisDeclParser::AttributeID);
    setState(510);
    typeDecl();
    setState(511);
    contextID();
    setState(514);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DiagnosisDeclParser::ASSIGN) {
      setState(512);
      match(DiagnosisDeclParser::ASSIGN);
      setState(513);
      literalValue();
    }
    setState(516);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

DiagnosisDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::LiteralValueContext::INT() {
  return getToken(DiagnosisDeclParser::INT, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LiteralValueContext::REAL() {
  return getToken(DiagnosisDeclParser::REAL, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LiteralValueContext::STRING() {
  return getToken(DiagnosisDeclParser::STRING, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LiteralValueContext::TrueID() {
  return getToken(DiagnosisDeclParser::TrueID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LiteralValueContext::FalseID() {
  return getToken(DiagnosisDeclParser::FalseID, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}


size_t DiagnosisDeclParser::LiteralValueContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleLiteralValue;
}

void DiagnosisDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void DiagnosisDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

DiagnosisDeclParser::LiteralValueContext* DiagnosisDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 86, DiagnosisDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(524);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(518);
        match(DiagnosisDeclParser::INT);
        break;
      }

      case DiagnosisDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(519);
        match(DiagnosisDeclParser::REAL);
        break;
      }

      case DiagnosisDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(520);
        match(DiagnosisDeclParser::STRING);
        break;
      }

      case DiagnosisDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(521);
        match(DiagnosisDeclParser::TrueID);
        break;
      }

      case DiagnosisDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(522);
        match(DiagnosisDeclParser::FalseID);
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(523);
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

DiagnosisDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::TriggerDeclContext* DiagnosisDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<DiagnosisDeclParser::TriggerDeclContext>(0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}


size_t DiagnosisDeclParser::SignalParamNameContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSignalParamName;
}

void DiagnosisDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void DiagnosisDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

DiagnosisDeclParser::SignalParamNameContext* DiagnosisDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 88, DiagnosisDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    triggerDecl();
    setState(527);
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

DiagnosisDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

DiagnosisDeclParser::ThisDeclContext* DiagnosisDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<DiagnosisDeclParser::ThisDeclContext>(0);
}


size_t DiagnosisDeclParser::AttributeNameContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleAttributeName;
}

void DiagnosisDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void DiagnosisDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

DiagnosisDeclParser::AttributeNameContext* DiagnosisDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 90, DiagnosisDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(531);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::ThisID: {
        setState(529);
        thisDecl();
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(533);
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

DiagnosisDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ToPortNameContext::ToID() {
  return getToken(DiagnosisDeclParser::ToID, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}


size_t DiagnosisDeclParser::ToPortNameContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleToPortName;
}

void DiagnosisDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void DiagnosisDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

DiagnosisDeclParser::ToPortNameContext* DiagnosisDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 92, DiagnosisDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(535);
    match(DiagnosisDeclParser::ToID);
    setState(536);
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

DiagnosisDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::AttributeNameContext* DiagnosisDeclParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<DiagnosisDeclParser::AttributeNameContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(DiagnosisDeclParser::ASSIGN, 0);
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<DiagnosisDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleAttributeAssignStatement;
}

void DiagnosisDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void DiagnosisDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

DiagnosisDeclParser::AttributeAssignStatementContext* DiagnosisDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, DiagnosisDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    attributeName();
    setState(539);
    match(DiagnosisDeclParser::ASSIGN);
    setState(540);
    expression();
    setState(541);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

DiagnosisDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::TypeDeclContext* DiagnosisDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<DiagnosisDeclParser::TypeDeclContext>(0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

tree::TerminalNode* DiagnosisDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(DiagnosisDeclParser::ASSIGN, 0);
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<DiagnosisDeclParser::ExpressionContext>(0);
}


size_t DiagnosisDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleLocalAssignStatement;
}

void DiagnosisDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void DiagnosisDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

DiagnosisDeclParser::LocalAssignStatementContext* DiagnosisDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, DiagnosisDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(543);
    typeDecl();
    setState(544);
    contextID();
    setState(548);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::ASSIGN: {
        setState(545);
        match(DiagnosisDeclParser::ASSIGN);
        setState(546);
        expression();
        break;
      }

      case DiagnosisDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(550);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

DiagnosisDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::SendToStatementContext::SendID() {
  return getToken(DiagnosisDeclParser::SendID, 0);
}

DiagnosisDeclParser::SignalSendContext* DiagnosisDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<DiagnosisDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::SendToStatementContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

DiagnosisDeclParser::ToPortNameContext* DiagnosisDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<DiagnosisDeclParser::ToPortNameContext>(0);
}


size_t DiagnosisDeclParser::SendToStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSendToStatement;
}

void DiagnosisDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void DiagnosisDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

DiagnosisDeclParser::SendToStatementContext* DiagnosisDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, DiagnosisDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(552);
    match(DiagnosisDeclParser::SendID);
    setState(553);
    signalSend();
    setState(556);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::ToID: {
        setState(554);
        toPortName();
        break;
      }

      case DiagnosisDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(558);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

DiagnosisDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::AttributeAssignStatementContext* DiagnosisDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<DiagnosisDeclParser::AttributeAssignStatementContext>(0);
}

DiagnosisDeclParser::SendToStatementContext* DiagnosisDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<DiagnosisDeclParser::SendToStatementContext>(0);
}


size_t DiagnosisDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSingleAssignment;
}

void DiagnosisDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void DiagnosisDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

DiagnosisDeclParser::SingleAssignmentContext* DiagnosisDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 100, DiagnosisDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(562);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::ThisID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(560);
        attributeAssignStatement();
        break;
      }

      case DiagnosisDeclParser::SendID: {
        enterOuterAlt(_localctx, 2);
        setState(561);
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

DiagnosisDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

tree::TerminalNode* DiagnosisDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}

std::vector<DiagnosisDeclParser::SingleAssignmentContext *> DiagnosisDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<DiagnosisDeclParser::SingleAssignmentContext>();
}

DiagnosisDeclParser::SingleAssignmentContext* DiagnosisDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<DiagnosisDeclParser::SingleAssignmentContext>(i);
}


size_t DiagnosisDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleMultiAssignment;
}

void DiagnosisDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void DiagnosisDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

DiagnosisDeclParser::MultiAssignmentContext* DiagnosisDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 102, DiagnosisDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    match(DiagnosisDeclParser::LBRACE);
    setState(568);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 17) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 17)) & ((1ULL << (DiagnosisDeclParser::NameID - 17))
      | (1ULL << (DiagnosisDeclParser::LabelID - 17))
      | (1ULL << (DiagnosisDeclParser::EnabledID - 17))
      | (1ULL << (DiagnosisDeclParser::TypeID - 17))
      | (1ULL << (DiagnosisDeclParser::ThisID - 17))
      | (1ULL << (DiagnosisDeclParser::AttributeID - 17))
      | (1ULL << (DiagnosisDeclParser::SignalID - 17))
      | (1ULL << (DiagnosisDeclParser::PortID - 17))
      | (1ULL << (DiagnosisDeclParser::ImportID - 17))
      | (1ULL << (DiagnosisDeclParser::FromID - 17))
      | (1ULL << (DiagnosisDeclParser::ToID - 17))
      | (1ULL << (DiagnosisDeclParser::SendID - 17))
      | (1ULL << (DiagnosisDeclParser::AsID - 17))
      | (1ULL << (DiagnosisDeclParser::ID - 17)))) != 0)) {
      setState(565);
      singleAssignment();
      setState(570);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(571);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::SignalDeclContext::SignalID() {
  return getToken(DiagnosisDeclParser::SignalID, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::SignalDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

tree::TerminalNode* DiagnosisDeclParser::SignalDeclContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

tree::TerminalNode* DiagnosisDeclParser::SignalDeclContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}

std::vector<DiagnosisDeclParser::ParamDeclContext *> DiagnosisDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<DiagnosisDeclParser::ParamDeclContext>();
}

DiagnosisDeclParser::ParamDeclContext* DiagnosisDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::SignalDeclContext::COMMA() {
  return getTokens(DiagnosisDeclParser::COMMA);
}

tree::TerminalNode* DiagnosisDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(DiagnosisDeclParser::COMMA, i);
}


size_t DiagnosisDeclParser::SignalDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSignalDecl;
}

void DiagnosisDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void DiagnosisDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

DiagnosisDeclParser::SignalDeclContext* DiagnosisDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 104, DiagnosisDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    match(DiagnosisDeclParser::SignalID);
    setState(574);
    contextID();
    setState(589);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::LPAREN: {
        setState(575);
        match(DiagnosisDeclParser::LPAREN);
        setState(585);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case DiagnosisDeclParser::NameID:
          case DiagnosisDeclParser::LabelID:
          case DiagnosisDeclParser::EnabledID:
          case DiagnosisDeclParser::TypeID:
          case DiagnosisDeclParser::IntID:
          case DiagnosisDeclParser::RealID:
          case DiagnosisDeclParser::BoolID:
          case DiagnosisDeclParser::StringID:
          case DiagnosisDeclParser::EnumID:
          case DiagnosisDeclParser::AttributeID:
          case DiagnosisDeclParser::SignalID:
          case DiagnosisDeclParser::PortID:
          case DiagnosisDeclParser::ImportID:
          case DiagnosisDeclParser::FromID:
          case DiagnosisDeclParser::ToID:
          case DiagnosisDeclParser::AsID:
          case DiagnosisDeclParser::ID: {
            setState(576);
            paramDecl();
            setState(581);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == DiagnosisDeclParser::COMMA) {
              setState(577);
              match(DiagnosisDeclParser::COMMA);
              setState(578);
              paramDecl();
              setState(583);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case DiagnosisDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(587);
        match(DiagnosisDeclParser::RPAREN);
        break;
      }

      case DiagnosisDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(591);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::TypeDeclContext* DiagnosisDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<DiagnosisDeclParser::TypeDeclContext>(0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}


size_t DiagnosisDeclParser::ParamDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleParamDecl;
}

void DiagnosisDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void DiagnosisDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

DiagnosisDeclParser::ParamDeclContext* DiagnosisDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 106, DiagnosisDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    typeDecl();
    setState(594);
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

DiagnosisDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(DiagnosisDeclParser::FunctionID, 0);
}

DiagnosisDeclParser::TypeDeclContext* DiagnosisDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<DiagnosisDeclParser::TypeDeclContext>(0);
}

DiagnosisDeclParser::IdPathContext* DiagnosisDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<DiagnosisDeclParser::IdPathContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

tree::TerminalNode* DiagnosisDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}

DiagnosisDeclParser::NestedStatementBodyContext* DiagnosisDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<DiagnosisDeclParser::NestedStatementBodyContext>(0);
}

DiagnosisDeclParser::FunctionParametersContext* DiagnosisDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<DiagnosisDeclParser::FunctionParametersContext>(0);
}


size_t DiagnosisDeclParser::FunctionDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleFunctionDecl;
}

void DiagnosisDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void DiagnosisDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

DiagnosisDeclParser::FunctionDeclContext* DiagnosisDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 108, DiagnosisDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(596);
    match(DiagnosisDeclParser::FunctionID);
    setState(597);
    typeDecl();
    setState(598);
    idPath();
    setState(599);
    match(DiagnosisDeclParser::LPAREN);
    setState(602);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::IntID:
      case DiagnosisDeclParser::RealID:
      case DiagnosisDeclParser::BoolID:
      case DiagnosisDeclParser::StringID:
      case DiagnosisDeclParser::EnumID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::ID: {
        setState(600);
        functionParameters();
        break;
      }

      case DiagnosisDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(604);
    match(DiagnosisDeclParser::RPAREN);
    setState(605);
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

DiagnosisDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DiagnosisDeclParser::ParamDeclContext *> DiagnosisDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<DiagnosisDeclParser::ParamDeclContext>();
}

DiagnosisDeclParser::ParamDeclContext* DiagnosisDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(DiagnosisDeclParser::COMMA);
}

tree::TerminalNode* DiagnosisDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(DiagnosisDeclParser::COMMA, i);
}


size_t DiagnosisDeclParser::FunctionParametersContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleFunctionParameters;
}

void DiagnosisDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void DiagnosisDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

DiagnosisDeclParser::FunctionParametersContext* DiagnosisDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 110, DiagnosisDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    paramDecl();
    setState(612);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DiagnosisDeclParser::COMMA) {
      setState(608);
      match(DiagnosisDeclParser::COMMA);
      setState(609);
      paramDecl();
      setState(614);
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

DiagnosisDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::IdPathContext* DiagnosisDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<DiagnosisDeclParser::IdPathContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::FunctionCallContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

DiagnosisDeclParser::FunctionCallBodyContext* DiagnosisDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<DiagnosisDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::FunctionCallContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}


size_t DiagnosisDeclParser::FunctionCallContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleFunctionCall;
}

void DiagnosisDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void DiagnosisDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

DiagnosisDeclParser::FunctionCallContext* DiagnosisDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 112, DiagnosisDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(615);
    idPath();
    setState(616);
    match(DiagnosisDeclParser::LPAREN);
    setState(617);
    functionCallBody();
    setState(618);
    match(DiagnosisDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::FunctionCallBodyOptionalContext* DiagnosisDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<DiagnosisDeclParser::FunctionCallBodyOptionalContext>(0);
}

DiagnosisDeclParser::LiteralValueContext* DiagnosisDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<DiagnosisDeclParser::LiteralValueContext>(0);
}

DiagnosisDeclParser::SignalParamNameContext* DiagnosisDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<DiagnosisDeclParser::SignalParamNameContext>(0);
}

DiagnosisDeclParser::AttributeNameContext* DiagnosisDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<DiagnosisDeclParser::AttributeNameContext>(0);
}

DiagnosisDeclParser::FunctionCallContext* DiagnosisDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<DiagnosisDeclParser::FunctionCallContext>(0);
}


size_t DiagnosisDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleFunctionCallBody;
}

void DiagnosisDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void DiagnosisDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

DiagnosisDeclParser::FunctionCallBodyContext* DiagnosisDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 114, DiagnosisDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(620);
      literalValue();
      break;
    }

    case 2: {
      setState(621);
      signalParamName();
      break;
    }

    case 3: {
      setState(622);
      attributeName();
      break;
    }

    case 4: {
      setState(623);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(627);
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

DiagnosisDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(DiagnosisDeclParser::COMMA, 0);
}

DiagnosisDeclParser::FunctionCallBodyContext* DiagnosisDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<DiagnosisDeclParser::FunctionCallBodyContext>(0);
}


size_t DiagnosisDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleFunctionCallBodyOptional;
}

void DiagnosisDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void DiagnosisDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

DiagnosisDeclParser::FunctionCallBodyOptionalContext* DiagnosisDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 116, DiagnosisDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(632);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(629);
        match(DiagnosisDeclParser::COMMA);
        setState(630);
        functionCallBody();
        break;
      }

      case DiagnosisDeclParser::RPAREN: {
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

DiagnosisDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::ID() {
  return getToken(DiagnosisDeclParser::ID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::NameID() {
  return getToken(DiagnosisDeclParser::NameID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::LabelID() {
  return getToken(DiagnosisDeclParser::LabelID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::EnabledID() {
  return getToken(DiagnosisDeclParser::EnabledID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::TypeID() {
  return getToken(DiagnosisDeclParser::TypeID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::AttributeID() {
  return getToken(DiagnosisDeclParser::AttributeID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::SignalID() {
  return getToken(DiagnosisDeclParser::SignalID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::PortID() {
  return getToken(DiagnosisDeclParser::PortID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::ImportID() {
  return getToken(DiagnosisDeclParser::ImportID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::FromID() {
  return getToken(DiagnosisDeclParser::FromID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::ToID() {
  return getToken(DiagnosisDeclParser::ToID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ContextIDContext::AsID() {
  return getToken(DiagnosisDeclParser::AsID, 0);
}


size_t DiagnosisDeclParser::ContextIDContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleContextID;
}

void DiagnosisDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void DiagnosisDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 118, DiagnosisDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    _la = _input->LA(1);
    if (!(((((_la - 17) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 17)) & ((1ULL << (DiagnosisDeclParser::NameID - 17))
      | (1ULL << (DiagnosisDeclParser::LabelID - 17))
      | (1ULL << (DiagnosisDeclParser::EnabledID - 17))
      | (1ULL << (DiagnosisDeclParser::TypeID - 17))
      | (1ULL << (DiagnosisDeclParser::AttributeID - 17))
      | (1ULL << (DiagnosisDeclParser::SignalID - 17))
      | (1ULL << (DiagnosisDeclParser::PortID - 17))
      | (1ULL << (DiagnosisDeclParser::ImportID - 17))
      | (1ULL << (DiagnosisDeclParser::FromID - 17))
      | (1ULL << (DiagnosisDeclParser::ToID - 17))
      | (1ULL << (DiagnosisDeclParser::AsID - 17))
      | (1ULL << (DiagnosisDeclParser::ID - 17)))) != 0))) {
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

DiagnosisDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::TriggerDeclContext::DOT() {
  return getToken(DiagnosisDeclParser::DOT, 0);
}

tree::TerminalNode* DiagnosisDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(DiagnosisDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* DiagnosisDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(DiagnosisDeclParser::TriggerID, 0);
}


size_t DiagnosisDeclParser::TriggerDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleTriggerDecl;
}

void DiagnosisDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void DiagnosisDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

DiagnosisDeclParser::TriggerDeclContext* DiagnosisDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 120, DiagnosisDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(636);
    _la = _input->LA(1);
    if (!(_la == DiagnosisDeclParser::TriggerID

    || _la == DiagnosisDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(637);
    match(DiagnosisDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ThisDeclContext::ThisID() {
  return getToken(DiagnosisDeclParser::ThisID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::ThisDeclContext::DOT() {
  return getToken(DiagnosisDeclParser::DOT, 0);
}


size_t DiagnosisDeclParser::ThisDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleThisDecl;
}

void DiagnosisDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void DiagnosisDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

DiagnosisDeclParser::ThisDeclContext* DiagnosisDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 122, DiagnosisDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(639);
    match(DiagnosisDeclParser::ThisID);
    setState(640);
    match(DiagnosisDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::PortDeclContext::PortID() {
  return getToken(DiagnosisDeclParser::PortID, 0);
}

std::vector<DiagnosisDeclParser::ContextIDContext *> DiagnosisDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<DiagnosisDeclParser::ContextIDContext>();
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* DiagnosisDeclParser::PortDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::PortDeclContext::COMMA() {
  return getTokens(DiagnosisDeclParser::COMMA);
}

tree::TerminalNode* DiagnosisDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(DiagnosisDeclParser::COMMA, i);
}


size_t DiagnosisDeclParser::PortDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RulePortDecl;
}

void DiagnosisDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void DiagnosisDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

DiagnosisDeclParser::PortDeclContext* DiagnosisDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 124, DiagnosisDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(642);
    match(DiagnosisDeclParser::PortID);
    setState(643);
    contextID();
    setState(648);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DiagnosisDeclParser::COMMA) {
      setState(644);
      match(DiagnosisDeclParser::COMMA);
      setState(645);
      contextID();
      setState(650);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(651);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

DiagnosisDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::NameDeclContext::NameID() {
  return getToken(DiagnosisDeclParser::NameID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::NameDeclContext::COLON() {
  return getToken(DiagnosisDeclParser::COLON, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::NameDeclContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::NameDeclContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::NameDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleNameDecl;
}

void DiagnosisDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void DiagnosisDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

DiagnosisDeclParser::NameDeclContext* DiagnosisDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 126, DiagnosisDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    match(DiagnosisDeclParser::NameID);
    setState(654);
    match(DiagnosisDeclParser::COLON);
    setState(655);
    contextID();
    setState(656);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

DiagnosisDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DiagnosisDeclParser::ContextIDContext *> DiagnosisDeclParser::IdPathContext::contextID() {
  return getRuleContexts<DiagnosisDeclParser::ContextIDContext>();
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> DiagnosisDeclParser::IdPathContext::DOT() {
  return getTokens(DiagnosisDeclParser::DOT);
}

tree::TerminalNode* DiagnosisDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(DiagnosisDeclParser::DOT, i);
}


size_t DiagnosisDeclParser::IdPathContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleIdPath;
}

void DiagnosisDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void DiagnosisDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

DiagnosisDeclParser::IdPathContext* DiagnosisDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 128, DiagnosisDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(658);
    contextID();
    setState(663);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DiagnosisDeclParser::DOT) {
      setState(659);
      match(DiagnosisDeclParser::DOT);
      setState(660);
      contextID();
      setState(665);
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

DiagnosisDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::StatementBodyContext* DiagnosisDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<DiagnosisDeclParser::StatementBodyContext>(0);
}

DiagnosisDeclParser::NestedStatementBodyContext* DiagnosisDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<DiagnosisDeclParser::NestedStatementBodyContext>(0);
}


size_t DiagnosisDeclParser::StatementDeclContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleStatementDecl;
}

void DiagnosisDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void DiagnosisDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

DiagnosisDeclParser::StatementDeclContext* DiagnosisDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 130, DiagnosisDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(668);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::IntID:
      case DiagnosisDeclParser::RealID:
      case DiagnosisDeclParser::BoolID:
      case DiagnosisDeclParser::StringID:
      case DiagnosisDeclParser::ThisID:
      case DiagnosisDeclParser::ReturnID:
      case DiagnosisDeclParser::EnumID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::SendID:
      case DiagnosisDeclParser::SwitchID:
      case DiagnosisDeclParser::IfID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::BREAK:
      case DiagnosisDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(666);
        statementBody();
        break;
      }

      case DiagnosisDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(667);
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

DiagnosisDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::FunctionCallStatementContext* DiagnosisDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<DiagnosisDeclParser::FunctionCallStatementContext>(0);
}

DiagnosisDeclParser::AttributeAssignStatementContext* DiagnosisDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<DiagnosisDeclParser::AttributeAssignStatementContext>(0);
}

DiagnosisDeclParser::SwitchStatementContext* DiagnosisDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<DiagnosisDeclParser::SwitchStatementContext>(0);
}

DiagnosisDeclParser::ConditionalStatementContext* DiagnosisDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<DiagnosisDeclParser::ConditionalStatementContext>(0);
}

DiagnosisDeclParser::LocalAssignStatementContext* DiagnosisDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<DiagnosisDeclParser::LocalAssignStatementContext>(0);
}

DiagnosisDeclParser::SendToStatementContext* DiagnosisDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<DiagnosisDeclParser::SendToStatementContext>(0);
}

DiagnosisDeclParser::BreakStatementContext* DiagnosisDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<DiagnosisDeclParser::BreakStatementContext>(0);
}

DiagnosisDeclParser::ReturnStatementContext* DiagnosisDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<DiagnosisDeclParser::ReturnStatementContext>(0);
}


size_t DiagnosisDeclParser::StatementBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleStatementBody;
}

void DiagnosisDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void DiagnosisDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

DiagnosisDeclParser::StatementBodyContext* DiagnosisDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 132, DiagnosisDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(678);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(670);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(671);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(672);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(673);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(674);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(675);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(676);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(677);
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

DiagnosisDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::FunctionCallContext* DiagnosisDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<DiagnosisDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleFunctionCallStatement;
}

void DiagnosisDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void DiagnosisDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

DiagnosisDeclParser::FunctionCallStatementContext* DiagnosisDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 134, DiagnosisDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(680);
    functionCall();
    setState(681);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

DiagnosisDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

tree::TerminalNode* DiagnosisDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}

std::vector<DiagnosisDeclParser::StatementBodyContext *> DiagnosisDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<DiagnosisDeclParser::StatementBodyContext>();
}

DiagnosisDeclParser::StatementBodyContext* DiagnosisDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<DiagnosisDeclParser::StatementBodyContext>(i);
}


size_t DiagnosisDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleNestedStatementBody;
}

void DiagnosisDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void DiagnosisDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

DiagnosisDeclParser::NestedStatementBodyContext* DiagnosisDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 136, DiagnosisDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(683);
    match(DiagnosisDeclParser::LBRACE);
    setState(687);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 17) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 17)) & ((1ULL << (DiagnosisDeclParser::NameID - 17))
      | (1ULL << (DiagnosisDeclParser::LabelID - 17))
      | (1ULL << (DiagnosisDeclParser::EnabledID - 17))
      | (1ULL << (DiagnosisDeclParser::TypeID - 17))
      | (1ULL << (DiagnosisDeclParser::IntID - 17))
      | (1ULL << (DiagnosisDeclParser::RealID - 17))
      | (1ULL << (DiagnosisDeclParser::BoolID - 17))
      | (1ULL << (DiagnosisDeclParser::StringID - 17))
      | (1ULL << (DiagnosisDeclParser::ThisID - 17))
      | (1ULL << (DiagnosisDeclParser::ReturnID - 17))
      | (1ULL << (DiagnosisDeclParser::EnumID - 17))
      | (1ULL << (DiagnosisDeclParser::AttributeID - 17))
      | (1ULL << (DiagnosisDeclParser::SignalID - 17))
      | (1ULL << (DiagnosisDeclParser::PortID - 17))
      | (1ULL << (DiagnosisDeclParser::ImportID - 17))
      | (1ULL << (DiagnosisDeclParser::FromID - 17))
      | (1ULL << (DiagnosisDeclParser::ToID - 17))
      | (1ULL << (DiagnosisDeclParser::SendID - 17))
      | (1ULL << (DiagnosisDeclParser::SwitchID - 17))
      | (1ULL << (DiagnosisDeclParser::IfID - 17))
      | (1ULL << (DiagnosisDeclParser::AsID - 17))
      | (1ULL << (DiagnosisDeclParser::BREAK - 17))
      | (1ULL << (DiagnosisDeclParser::ID - 17)))) != 0)) {
      setState(684);
      statementBody();
      setState(689);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(690);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

DiagnosisDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(DiagnosisDeclParser::ReturnID, 0);
}

DiagnosisDeclParser::OperationContext* DiagnosisDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<DiagnosisDeclParser::OperationContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::ReturnStatementContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::ReturnStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleReturnStatement;
}

void DiagnosisDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void DiagnosisDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

DiagnosisDeclParser::ReturnStatementContext* DiagnosisDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, DiagnosisDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(692);
    match(DiagnosisDeclParser::ReturnID);
    setState(693);
    operation();
    setState(694);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

DiagnosisDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::BreakStatementContext::BREAK() {
  return getToken(DiagnosisDeclParser::BREAK, 0);
}

tree::TerminalNode* DiagnosisDeclParser::BreakStatementContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::BreakStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleBreakStatement;
}

void DiagnosisDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void DiagnosisDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

DiagnosisDeclParser::BreakStatementContext* DiagnosisDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 140, DiagnosisDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(696);
    match(DiagnosisDeclParser::BREAK);
    setState(697);
    match(DiagnosisDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

DiagnosisDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::AtomContext* DiagnosisDeclParser::OperationContext::atom() {
  return getRuleContext<DiagnosisDeclParser::AtomContext>(0);
}

DiagnosisDeclParser::OperationOptionalContext* DiagnosisDeclParser::OperationContext::operationOptional() {
  return getRuleContext<DiagnosisDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

DiagnosisDeclParser::OperationContext* DiagnosisDeclParser::OperationContext::operation() {
  return getRuleContext<DiagnosisDeclParser::OperationContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationContext::MINUS() {
  return getToken(DiagnosisDeclParser::MINUS, 0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationContext::NotIdSymbol() {
  return getToken(DiagnosisDeclParser::NotIdSymbol, 0);
}


size_t DiagnosisDeclParser::OperationContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleOperation;
}

void DiagnosisDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void DiagnosisDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

DiagnosisDeclParser::OperationContext* DiagnosisDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 142, DiagnosisDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(710);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::TrueID:
      case DiagnosisDeclParser::FalseID:
      case DiagnosisDeclParser::INT:
      case DiagnosisDeclParser::REAL:
      case DiagnosisDeclParser::STRING:
      case DiagnosisDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(699);
        atom();
        setState(700);
        operationOptional();
        break;
      }

      case DiagnosisDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(702);
        match(DiagnosisDeclParser::LPAREN);
        setState(703);
        operation();
        setState(704);
        match(DiagnosisDeclParser::RPAREN);
        break;
      }

      case DiagnosisDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(706);
        match(DiagnosisDeclParser::MINUS);
        setState(707);
        operation();
        break;
      }

      case DiagnosisDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(708);
        match(DiagnosisDeclParser::NotIdSymbol);
        setState(709);
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

DiagnosisDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::OperationContext* DiagnosisDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<DiagnosisDeclParser::OperationContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationOptionalContext::MULT() {
  return getToken(DiagnosisDeclParser::MULT, 0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationOptionalContext::DIV() {
  return getToken(DiagnosisDeclParser::DIV, 0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationOptionalContext::PLUS() {
  return getToken(DiagnosisDeclParser::PLUS, 0);
}

tree::TerminalNode* DiagnosisDeclParser::OperationOptionalContext::MINUS() {
  return getToken(DiagnosisDeclParser::MINUS, 0);
}


size_t DiagnosisDeclParser::OperationOptionalContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleOperationOptional;
}

void DiagnosisDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void DiagnosisDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

DiagnosisDeclParser::OperationOptionalContext* DiagnosisDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 144, DiagnosisDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(715);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::PLUS:
      case DiagnosisDeclParser::MINUS:
      case DiagnosisDeclParser::MULT:
      case DiagnosisDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(712);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 81) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 81)) & ((1ULL << (DiagnosisDeclParser::PLUS - 81))
          | (1ULL << (DiagnosisDeclParser::MINUS - 81))
          | (1ULL << (DiagnosisDeclParser::MULT - 81))
          | (1ULL << (DiagnosisDeclParser::DIV - 81)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(713);
        operation();
        break;
      }

      case DiagnosisDeclParser::RPAREN:
      case DiagnosisDeclParser::SEMI: {
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

DiagnosisDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DiagnosisDeclParser::IfStatementContext* DiagnosisDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<DiagnosisDeclParser::IfStatementContext>(0);
}

DiagnosisDeclParser::ElseStatementContext* DiagnosisDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<DiagnosisDeclParser::ElseStatementContext>(0);
}


size_t DiagnosisDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleConditionalStatement;
}

void DiagnosisDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void DiagnosisDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

DiagnosisDeclParser::ConditionalStatementContext* DiagnosisDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 146, DiagnosisDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    ifStatement();
    setState(720);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      setState(718);
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

DiagnosisDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::IfStatementContext::IfID() {
  return getToken(DiagnosisDeclParser::IfID, 0);
}

DiagnosisDeclParser::IfEuTContext* DiagnosisDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<DiagnosisDeclParser::IfEuTContext>(0);
}

DiagnosisDeclParser::StatementDeclContext* DiagnosisDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<DiagnosisDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::IfStatementContext::SEMI() {
  return getToken(DiagnosisDeclParser::SEMI, 0);
}


size_t DiagnosisDeclParser::IfStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleIfStatement;
}

void DiagnosisDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void DiagnosisDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

DiagnosisDeclParser::IfStatementContext* DiagnosisDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 148, DiagnosisDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(722);
    match(DiagnosisDeclParser::IfID);
    setState(723);
    ifEuT();
    setState(726);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::IntID:
      case DiagnosisDeclParser::RealID:
      case DiagnosisDeclParser::BoolID:
      case DiagnosisDeclParser::StringID:
      case DiagnosisDeclParser::ThisID:
      case DiagnosisDeclParser::ReturnID:
      case DiagnosisDeclParser::EnumID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::SendID:
      case DiagnosisDeclParser::SwitchID:
      case DiagnosisDeclParser::IfID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::BREAK:
      case DiagnosisDeclParser::ID:
      case DiagnosisDeclParser::LBRACE: {
        setState(724);
        statementDecl();
        break;
      }

      case DiagnosisDeclParser::SEMI: {
        setState(725);
        match(DiagnosisDeclParser::SEMI);
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

DiagnosisDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::IfEuTContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

DiagnosisDeclParser::ExpressionContext* DiagnosisDeclParser::IfEuTContext::expression() {
  return getRuleContext<DiagnosisDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::IfEuTContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}


size_t DiagnosisDeclParser::IfEuTContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleIfEuT;
}

void DiagnosisDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void DiagnosisDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

DiagnosisDeclParser::IfEuTContext* DiagnosisDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 150, DiagnosisDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(728);
    match(DiagnosisDeclParser::LPAREN);
    setState(729);
    expression();
    setState(730);
    match(DiagnosisDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

DiagnosisDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::ElseStatementContext::ElseID() {
  return getToken(DiagnosisDeclParser::ElseID, 0);
}

DiagnosisDeclParser::StatementDeclContext* DiagnosisDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<DiagnosisDeclParser::StatementDeclContext>(0);
}


size_t DiagnosisDeclParser::ElseStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleElseStatement;
}

void DiagnosisDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void DiagnosisDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

DiagnosisDeclParser::ElseStatementContext* DiagnosisDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 152, DiagnosisDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(732);
    match(DiagnosisDeclParser::ElseID);
    setState(733);
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

DiagnosisDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(DiagnosisDeclParser::SwitchID, 0);
}

DiagnosisDeclParser::SwitchPuTContext* DiagnosisDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<DiagnosisDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(DiagnosisDeclParser::LBRACE, 0);
}

tree::TerminalNode* DiagnosisDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(DiagnosisDeclParser::RBRACE, 0);
}

DiagnosisDeclParser::DefaultStatementContext* DiagnosisDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<DiagnosisDeclParser::DefaultStatementContext>(0);
}

std::vector<DiagnosisDeclParser::CaseStatementContext *> DiagnosisDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<DiagnosisDeclParser::CaseStatementContext>();
}

DiagnosisDeclParser::CaseStatementContext* DiagnosisDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<DiagnosisDeclParser::CaseStatementContext>(i);
}


size_t DiagnosisDeclParser::SwitchStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSwitchStatement;
}

void DiagnosisDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void DiagnosisDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

DiagnosisDeclParser::SwitchStatementContext* DiagnosisDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, DiagnosisDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(735);
    match(DiagnosisDeclParser::SwitchID);
    setState(736);
    switchPuT();
    setState(737);
    match(DiagnosisDeclParser::LBRACE);
    setState(741);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DiagnosisDeclParser::CaseID) {
      setState(738);
      caseStatement();
      setState(743);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(746);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::DefaultID: {
        setState(744);
        defaultStatement();
        break;
      }

      case DiagnosisDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(748);
    match(DiagnosisDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

DiagnosisDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(DiagnosisDeclParser::LPAREN, 0);
}

DiagnosisDeclParser::ContextIDContext* DiagnosisDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<DiagnosisDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(DiagnosisDeclParser::RPAREN, 0);
}


size_t DiagnosisDeclParser::SwitchPuTContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleSwitchPuT;
}

void DiagnosisDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void DiagnosisDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

DiagnosisDeclParser::SwitchPuTContext* DiagnosisDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 156, DiagnosisDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(750);
    match(DiagnosisDeclParser::LPAREN);
    setState(751);
    contextID();
    setState(752);
    match(DiagnosisDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

DiagnosisDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::CaseStatementContext::CaseID() {
  return getToken(DiagnosisDeclParser::CaseID, 0);
}

DiagnosisDeclParser::LiteralValueContext* DiagnosisDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<DiagnosisDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* DiagnosisDeclParser::CaseStatementContext::COLON() {
  return getToken(DiagnosisDeclParser::COLON, 0);
}

DiagnosisDeclParser::NestedStatementBodyContext* DiagnosisDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<DiagnosisDeclParser::NestedStatementBodyContext>(0);
}

std::vector<DiagnosisDeclParser::StatementBodyContext *> DiagnosisDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<DiagnosisDeclParser::StatementBodyContext>();
}

DiagnosisDeclParser::StatementBodyContext* DiagnosisDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<DiagnosisDeclParser::StatementBodyContext>(i);
}


size_t DiagnosisDeclParser::CaseStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleCaseStatement;
}

void DiagnosisDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void DiagnosisDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

DiagnosisDeclParser::CaseStatementContext* DiagnosisDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 158, DiagnosisDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(754);
    match(DiagnosisDeclParser::CaseID);
    setState(755);
    literalValue();
    setState(756);
    match(DiagnosisDeclParser::COLON);
    setState(764);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::LBRACE: {
        setState(757);
        nestedStatementBody();
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::IntID:
      case DiagnosisDeclParser::RealID:
      case DiagnosisDeclParser::BoolID:
      case DiagnosisDeclParser::StringID:
      case DiagnosisDeclParser::ThisID:
      case DiagnosisDeclParser::ReturnID:
      case DiagnosisDeclParser::EnumID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::SendID:
      case DiagnosisDeclParser::SwitchID:
      case DiagnosisDeclParser::CaseID:
      case DiagnosisDeclParser::DefaultID:
      case DiagnosisDeclParser::IfID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::BREAK:
      case DiagnosisDeclParser::ID:
      case DiagnosisDeclParser::RBRACE: {
        setState(761);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 17) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 17)) & ((1ULL << (DiagnosisDeclParser::NameID - 17))
          | (1ULL << (DiagnosisDeclParser::LabelID - 17))
          | (1ULL << (DiagnosisDeclParser::EnabledID - 17))
          | (1ULL << (DiagnosisDeclParser::TypeID - 17))
          | (1ULL << (DiagnosisDeclParser::IntID - 17))
          | (1ULL << (DiagnosisDeclParser::RealID - 17))
          | (1ULL << (DiagnosisDeclParser::BoolID - 17))
          | (1ULL << (DiagnosisDeclParser::StringID - 17))
          | (1ULL << (DiagnosisDeclParser::ThisID - 17))
          | (1ULL << (DiagnosisDeclParser::ReturnID - 17))
          | (1ULL << (DiagnosisDeclParser::EnumID - 17))
          | (1ULL << (DiagnosisDeclParser::AttributeID - 17))
          | (1ULL << (DiagnosisDeclParser::SignalID - 17))
          | (1ULL << (DiagnosisDeclParser::PortID - 17))
          | (1ULL << (DiagnosisDeclParser::ImportID - 17))
          | (1ULL << (DiagnosisDeclParser::FromID - 17))
          | (1ULL << (DiagnosisDeclParser::ToID - 17))
          | (1ULL << (DiagnosisDeclParser::SendID - 17))
          | (1ULL << (DiagnosisDeclParser::SwitchID - 17))
          | (1ULL << (DiagnosisDeclParser::IfID - 17))
          | (1ULL << (DiagnosisDeclParser::AsID - 17))
          | (1ULL << (DiagnosisDeclParser::BREAK - 17))
          | (1ULL << (DiagnosisDeclParser::ID - 17)))) != 0)) {
          setState(758);
          statementBody();
          setState(763);
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

DiagnosisDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DiagnosisDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(DiagnosisDeclParser::DefaultID, 0);
}

tree::TerminalNode* DiagnosisDeclParser::DefaultStatementContext::COLON() {
  return getToken(DiagnosisDeclParser::COLON, 0);
}

DiagnosisDeclParser::NestedStatementBodyContext* DiagnosisDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<DiagnosisDeclParser::NestedStatementBodyContext>(0);
}

std::vector<DiagnosisDeclParser::StatementBodyContext *> DiagnosisDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<DiagnosisDeclParser::StatementBodyContext>();
}

DiagnosisDeclParser::StatementBodyContext* DiagnosisDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<DiagnosisDeclParser::StatementBodyContext>(i);
}


size_t DiagnosisDeclParser::DefaultStatementContext::getRuleIndex() const {
  return DiagnosisDeclParser::RuleDefaultStatement;
}

void DiagnosisDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void DiagnosisDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DiagnosisDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

DiagnosisDeclParser::DefaultStatementContext* DiagnosisDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 160, DiagnosisDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(766);
    match(DiagnosisDeclParser::DefaultID);
    setState(767);
    match(DiagnosisDeclParser::COLON);
    setState(775);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiagnosisDeclParser::LBRACE: {
        setState(768);
        nestedStatementBody();
        break;
      }

      case DiagnosisDeclParser::NameID:
      case DiagnosisDeclParser::LabelID:
      case DiagnosisDeclParser::EnabledID:
      case DiagnosisDeclParser::TypeID:
      case DiagnosisDeclParser::IntID:
      case DiagnosisDeclParser::RealID:
      case DiagnosisDeclParser::BoolID:
      case DiagnosisDeclParser::StringID:
      case DiagnosisDeclParser::ThisID:
      case DiagnosisDeclParser::ReturnID:
      case DiagnosisDeclParser::EnumID:
      case DiagnosisDeclParser::AttributeID:
      case DiagnosisDeclParser::SignalID:
      case DiagnosisDeclParser::PortID:
      case DiagnosisDeclParser::ImportID:
      case DiagnosisDeclParser::FromID:
      case DiagnosisDeclParser::ToID:
      case DiagnosisDeclParser::SendID:
      case DiagnosisDeclParser::SwitchID:
      case DiagnosisDeclParser::IfID:
      case DiagnosisDeclParser::AsID:
      case DiagnosisDeclParser::BREAK:
      case DiagnosisDeclParser::ID:
      case DiagnosisDeclParser::RBRACE: {
        setState(772);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 17) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 17)) & ((1ULL << (DiagnosisDeclParser::NameID - 17))
          | (1ULL << (DiagnosisDeclParser::LabelID - 17))
          | (1ULL << (DiagnosisDeclParser::EnabledID - 17))
          | (1ULL << (DiagnosisDeclParser::TypeID - 17))
          | (1ULL << (DiagnosisDeclParser::IntID - 17))
          | (1ULL << (DiagnosisDeclParser::RealID - 17))
          | (1ULL << (DiagnosisDeclParser::BoolID - 17))
          | (1ULL << (DiagnosisDeclParser::StringID - 17))
          | (1ULL << (DiagnosisDeclParser::ThisID - 17))
          | (1ULL << (DiagnosisDeclParser::ReturnID - 17))
          | (1ULL << (DiagnosisDeclParser::EnumID - 17))
          | (1ULL << (DiagnosisDeclParser::AttributeID - 17))
          | (1ULL << (DiagnosisDeclParser::SignalID - 17))
          | (1ULL << (DiagnosisDeclParser::PortID - 17))
          | (1ULL << (DiagnosisDeclParser::ImportID - 17))
          | (1ULL << (DiagnosisDeclParser::FromID - 17))
          | (1ULL << (DiagnosisDeclParser::ToID - 17))
          | (1ULL << (DiagnosisDeclParser::SendID - 17))
          | (1ULL << (DiagnosisDeclParser::SwitchID - 17))
          | (1ULL << (DiagnosisDeclParser::IfID - 17))
          | (1ULL << (DiagnosisDeclParser::AsID - 17))
          | (1ULL << (DiagnosisDeclParser::BREAK - 17))
          | (1ULL << (DiagnosisDeclParser::ID - 17)))) != 0)) {
          setState(769);
          statementBody();
          setState(774);
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

// Static vars and initialization.
std::vector<dfa::DFA> DiagnosisDeclParser::_decisionToDFA;
atn::PredictionContextCache DiagnosisDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DiagnosisDeclParser::_atn;
std::vector<uint16_t> DiagnosisDeclParser::_serializedATN;

std::vector<std::string> DiagnosisDeclParser::_ruleNames = {
  "diagnosisDecl", "rulesDecl", "ruleDecl", "ruleBody", "descriptionDecl", 
  "declarations", "componentsDecl", "componentsBody", "componentDecl", "componentBody", 
  "diagnosisSignalsDecl", "diagnosisSignalsBody", "diagnosisSignalDecl", 
  "diagnosisSignalBody", "baseTypeDecl", "checkDecl", "aliasDef", "sequenceDecl", 
  "sequenceBody", "messageDecl", "expression", "expressionOptional", "atom", 
  "loopDecl", "parallelDecl", "parallelBodys", "parallelBody", "enabledDecl", 
  "componentIdPath", "signalIdPath", "attributeIdPath", "signalSend", "commonDecl", 
  "importPathDecl", "importPathBody", "importFileBody", "importAs", "typeDefDecl", 
  "typeDecl", "intTypeDecl", "realTypeDecl", "enumTypeDecl", "attributeDecl", 
  "literalValue", "signalParamName", "attributeName", "toPortName", "attributeAssignStatement", 
  "localAssignStatement", "sendToStatement", "singleAssignment", "multiAssignment", 
  "signalDecl", "paramDecl", "functionDecl", "functionParameters", "functionCall", 
  "functionCallBody", "functionCallBodyOptional", "contextID", "triggerDecl", 
  "thisDecl", "portDecl", "nameDecl", "idPath", "statementDecl", "statementBody", 
  "functionCallStatement", "nestedStatementBody", "returnStatement", "breakStatement", 
  "operation", "operationOptional", "conditionalStatement", "ifStatement", 
  "ifEuT", "elseStatement", "switchStatement", "switchPuT", "caseStatement", 
  "defaultStatement"
};

std::vector<std::string> DiagnosisDeclParser::_literalNames = {
  "", "'Components'", "'Rule'", "'Component'", "'basetype'", "'ParallelSequence'", 
  "'Signals'", "'Parallel'", "'Loop'", "'Sequence'", "'description'", "'Message'", 
  "'use'", "'Condition'", "'Check'", "'Diagnosis'", "", "'name'", "'label'", 
  "'enabled'", "'Type'", "'int'", "'real'", "'bool'", "'string'", "'trigger'", 
  "'msg'", "'this'", "'return'", "'SignalTransition'", "'TimeoutTransition'", 
  "'enum'", "'Declaration'", "'Attribute'", "'Signal'", "'Port'", "'import'", 
  "'from'", "'to'", "'send'", "'Function'", "'switch'", "'case'", "'default'", 
  "'if'", "'else'", "'as'", "'@'", "'!'", "'&&'", "'||'", "'not'", "'and'", 
  "'or'", "'true'", "'false'", "'break'", "'='", "'<->'", "'->'", "'<-'", 
  "'..'", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "'<'", "'>'", "':'", "';'", "','", "'_'", "'.'", "'+'", "'-'", "'*'", 
  "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> DiagnosisDeclParser::_symbolicNames = {
  "", "ComponentsID", "RuleID", "ComponentID", "BaseTypeID", "ParallelSequenceID", 
  "SignalsID", "ParallelID", "LoopID", "SequenceID", "DescriptionID", "MessageID", 
  "UseID", "ConditionID", "CheckID", "DiagnosisID", "IGNORE_NEWLINE", "NameID", 
  "LabelID", "EnabledID", "TypeID", "IntID", "RealID", "BoolID", "StringID", 
  "TriggerID", "MessageTrigger", "ThisID", "ReturnID", "SignalTransitionID", 
  "TimeoutTransitionID", "EnumID", "DeclarationID", "AttributeID", "SignalID", 
  "PortID", "ImportID", "FromID", "ToID", "SendID", "FunctionID", "SwitchID", 
  "CaseID", "DefaultID", "IfID", "ElseID", "AsID", "AtID", "NotIdSymbol", 
  "AndIdSymbol", "OrIdSymbol", "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", 
  "FalseID", "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", "LeftArrow", 
  "RANGE", "INT", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", "LPAREN", 
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", 
  "COLON", "SEMI", "COMMA", "UNDER", "DOT", "PLUS", "MINUS", "MULT", "DIV", 
  "PIPE", "REF", "CONST", "NEWLINE", "WS"
};

dfa::Vocabulary DiagnosisDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DiagnosisDeclParser::_tokenNames;

DiagnosisDeclParser::Initializer::Initializer() {
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
    0x3, 0x5b, 0x30c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0xac, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xbc, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xd2, 0xa, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0xdd, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xef, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xfa, 0xa, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x10c, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x11d, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x122, 0xa, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0x137, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x14c, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x15a, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x15f, 0xa, 0x17, 0x5, 0x17, 
    0x161, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x165, 0xa, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x16b, 0xa, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x170, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x183, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 
    0x192, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x195, 0xb, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x19a, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
    0x19d, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 
    0x1a3, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x1a6, 0xb, 0x20, 0x5, 0x20, 
    0x1a8, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x1b2, 0xa, 0x22, 0xc, 0x22, 
    0xe, 0x22, 0x1b5, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x5, 0x23, 0x1bb, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x5, 0x25, 0x1ce, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 
    0x1d3, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 
    0x28, 0x1e0, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1e9, 0xa, 0x29, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 
    0x2a, 0x1f2, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x7, 0x2b, 0x1f9, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x1fc, 
    0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x205, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
    0x2d, 0x20f, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x5, 0x2f, 0x216, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 
    0x227, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x5, 0x33, 0x22f, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x5, 0x34, 0x235, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 
    0x239, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x23c, 0xb, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x36, 0x7, 0x36, 0x246, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x249, 0xb, 
    0x36, 0x3, 0x36, 0x5, 0x36, 0x24c, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x250, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x5, 0x38, 0x25d, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x265, 0xa, 0x39, 0xc, 0x39, 
    0xe, 0x39, 0x268, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 
    0x3b, 0x274, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x27b, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x289, 0xa, 0x40, 0xc, 0x40, 
    0xe, 0x40, 0x28c, 0xb, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 
    0x42, 0x298, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x29b, 0xb, 0x42, 0x3, 
    0x43, 0x3, 0x43, 0x5, 0x43, 0x29f, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 
    0x44, 0x2a9, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 
    0x3, 0x46, 0x7, 0x46, 0x2b0, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x2b3, 
    0xb, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 
    0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x5, 0x49, 0x2c9, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x5, 0x4a, 0x2ce, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 
    0x5, 0x4b, 0x2d3, 0xa, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x5, 0x4c, 0x2d9, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x7, 0x4f, 0x2e6, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x2e9, 0xb, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x2ed, 0xa, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 
    0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x2fa, 0xa, 0x51, 
    0xc, 0x51, 0xe, 0x51, 0x2fd, 0xb, 0x51, 0x5, 0x51, 0x2ff, 0xa, 0x51, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x7, 0x52, 0x305, 0xa, 0x52, 
    0xc, 0x52, 0xe, 0x52, 0x308, 0xb, 0x52, 0x5, 0x52, 0x30a, 0xa, 0x52, 
    0x3, 0x52, 0x2, 0x2, 0x53, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
    0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 
    0xa2, 0x2, 0x7, 0x4, 0x2, 0x38, 0x39, 0x40, 0x42, 0x3, 0x2, 0x38, 0x39, 
    0x6, 0x2, 0x13, 0x16, 0x23, 0x28, 0x30, 0x30, 0x43, 0x43, 0x3, 0x2, 
    0x1b, 0x1c, 0x3, 0x2, 0x53, 0x56, 0x2, 0x31f, 0x2, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0xab, 0x3, 0x2, 0x2, 0x2, 0x6, 0xad, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0xa, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x10, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xde, 0x3, 0x2, 0x2, 0x2, 0x14, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf9, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x24, 0x127, 0x3, 0x2, 0x2, 0x2, 0x26, 0x136, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x138, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x14b, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x164, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x16f, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x171, 0x3, 0x2, 0x2, 0x2, 0x32, 0x179, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x182, 0x3, 0x2, 0x2, 0x2, 0x36, 0x184, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x189, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x196, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1a9, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1ba, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1cd, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1d4, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x1ff, 0x3, 0x2, 0x2, 0x2, 0x58, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x210, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x215, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x219, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x62, 0x221, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x66, 0x234, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x236, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x23f, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x253, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x256, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x261, 0x3, 0x2, 0x2, 0x2, 0x72, 0x269, 0x3, 0x2, 0x2, 0x2, 0x74, 0x273, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x78, 0x27c, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x281, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x284, 0x3, 0x2, 0x2, 0x2, 0x80, 0x28f, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x294, 0x3, 0x2, 0x2, 0x2, 0x84, 0x29e, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x88, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x2ad, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x2ba, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x92, 0x2cd, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2d4, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x2de, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x2f0, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x300, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa5, 0x5, 0x44, 0x23, 0x2, 0xa5, 0xa6, 0x5, 0x4, 0x3, 0x2, 0xa6, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x6, 0x4, 0x2, 0xa8, 0xa9, 0x5, 
    0x4, 0x3, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0x5, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x4, 0x2, 0x2, 
    0xae, 0xaf, 0x7, 0x48, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x8, 0x5, 0x2, 0xb0, 
    0xb1, 0x7, 0x49, 0x2, 0x2, 0xb1, 0x7, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 
    0x5, 0x80, 0x41, 0x2, 0xb3, 0xb4, 0x5, 0xa, 0x6, 0x2, 0xb4, 0xbb, 0x5, 
    0x38, 0x1d, 0x2, 0xb5, 0xb6, 0x7, 0x22, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x48, 
    0x2, 0x2, 0xb7, 0xb8, 0x5, 0xc, 0x7, 0x2, 0xb8, 0xb9, 0x7, 0x49, 0x2, 
    0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x24, 0x13, 0x2, 0xbe, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0xc, 0x2, 0x2, 0xc0, 0xc1, 0x7, 
    0x4e, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x42, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x4f, 
    0x2, 0x2, 0xc3, 0xb, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x56, 0x2c, 
    0x2, 0xc5, 0xc6, 0x5, 0xc, 0x7, 0x2, 0xc6, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc8, 0x5, 0x1a, 0xe, 0x2, 0xc8, 0xc9, 0x5, 0xc, 0x7, 0x2, 0xc9, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x22, 0x12, 0x2, 0xcb, 0xcc, 
    0x5, 0xc, 0x7, 0x2, 0xcc, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 
    0x12, 0xa, 0x2, 0xce, 0xcf, 0x5, 0xc, 0x7, 0x2, 0xcf, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xd1, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xca, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x3, 0x2, 0x2, 0xd4, 0xd5, 
    0x7, 0x48, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x10, 0x9, 0x2, 0xd6, 0xd7, 0x7, 
    0x49, 0x2, 0x2, 0xd7, 0xf, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x12, 
    0xa, 0x2, 0xd9, 0xda, 0x5, 0x10, 0x9, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0x11, 0x3, 0x2, 0x2, 0x2, 0xde, 
    0xdf, 0x7, 0x5, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x48, 0x2, 0x2, 0xe0, 0xe1, 
    0x5, 0x80, 0x41, 0x2, 0xe1, 0xe2, 0x5, 0x14, 0xb, 0x2, 0xe2, 0xe3, 0x7, 
    0x49, 0x2, 0x2, 0xe3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x22, 
    0x12, 0x2, 0xe5, 0xe6, 0x5, 0x14, 0xb, 0x2, 0xe6, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xe7, 0xe8, 0x5, 0x1e, 0x10, 0x2, 0xe8, 0xe9, 0x5, 0x14, 0xb, 0x2, 
    0xe9, 0xef, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x5, 0x20, 0x11, 0x2, 0xeb, 
    0xec, 0x5, 0x14, 0xb, 0x2, 0xec, 0xef, 0x3, 0x2, 0x2, 0x2, 0xed, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xee, 0xe7, 0x3, 
    0x2, 0x2, 0x2, 0xee, 0xea, 0x3, 0x2, 0x2, 0x2, 0xee, 0xed, 0x3, 0x2, 
    0x2, 0x2, 0xef, 0x15, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x8, 0x2, 
    0x2, 0xf1, 0xf2, 0x7, 0x48, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x18, 0xd, 0x2, 
    0xf3, 0xf4, 0x7, 0x49, 0x2, 0x2, 0xf4, 0x17, 0x3, 0x2, 0x2, 0x2, 0xf5, 
    0xf6, 0x5, 0x1a, 0xe, 0x2, 0xf6, 0xf7, 0x5, 0x18, 0xd, 0x2, 0xf7, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0xf8, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xf5, 0x3, 
    0x2, 0x2, 0x2, 0xf9, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0xfb, 0xfc, 0x7, 0x24, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x48, 0x2, 
    0x2, 0xfd, 0xfe, 0x5, 0x80, 0x41, 0x2, 0xfe, 0xff, 0x5, 0x1c, 0xf, 0x2, 
    0xff, 0x100, 0x7, 0x49, 0x2, 0x2, 0x100, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x102, 0x5, 0x22, 0x12, 0x2, 0x102, 0x103, 0x5, 0x1c, 0xf, 0x2, 0x103, 
    0x10c, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x5, 0x1e, 0x10, 0x2, 0x105, 
    0x106, 0x5, 0x1c, 0xf, 0x2, 0x106, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x107, 
    0x108, 0x5, 0x20, 0x11, 0x2, 0x108, 0x109, 0x5, 0x1c, 0xf, 0x2, 0x109, 
    0x10c, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x104, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x6, 0x2, 0x2, 0x10e, 0x10f, 
    0x7, 0x4e, 0x2, 0x2, 0x10f, 0x110, 0x5, 0x82, 0x42, 0x2, 0x110, 0x111, 
    0x7, 0x4f, 0x2, 0x2, 0x111, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 
    0x7, 0xf, 0x2, 0x2, 0x113, 0x114, 0x7, 0x4e, 0x2, 0x2, 0x114, 0x115, 
    0x5, 0x2a, 0x16, 0x2, 0x115, 0x116, 0x7, 0x4f, 0x2, 0x2, 0x116, 0x11d, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0x10, 0x2, 0x2, 0x118, 0x119, 
    0x7, 0x4e, 0x2, 0x2, 0x119, 0x11a, 0x5, 0x2a, 0x16, 0x2, 0x11a, 0x11b, 
    0x7, 0x4f, 0x2, 0x2, 0x11b, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x11c, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x11e, 0x121, 0x7, 0xe, 0x2, 0x2, 0x11f, 0x122, 0x5, 
    0x82, 0x42, 0x2, 0x120, 0x122, 0x7, 0x40, 0x2, 0x2, 0x121, 0x11f, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x30, 0x2, 0x2, 0x124, 0x125, 0x5, 
    0x78, 0x3d, 0x2, 0x125, 0x126, 0x7, 0x4f, 0x2, 0x2, 0x126, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x128, 0x7, 0xb, 0x2, 0x2, 0x128, 0x129, 0x7, 
    0x48, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x26, 0x14, 0x2, 0x12a, 0x12b, 0x7, 
    0x49, 0x2, 0x2, 0x12b, 0x25, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x5, 
    0x28, 0x15, 0x2, 0x12d, 0x12e, 0x5, 0x26, 0x14, 0x2, 0x12e, 0x137, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x30, 0x19, 0x2, 0x130, 0x131, 0x5, 
    0x26, 0x14, 0x2, 0x131, 0x137, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x5, 
    0x32, 0x1a, 0x2, 0x133, 0x134, 0x5, 0x26, 0x14, 0x2, 0x134, 0x137, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x137, 0x3, 0x2, 0x2, 0x2, 0x136, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x136, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x135, 0x3, 0x2, 0x2, 0x2, 0x137, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x138, 0x139, 0x7, 0xd, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x82, 
    0x42, 0x2, 0x13a, 0x13b, 0x7, 0x46, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0x2a, 
    0x16, 0x2, 0x13c, 0x13d, 0x7, 0x47, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x4f, 
    0x2, 0x2, 0x13e, 0x29, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x7, 0x46, 
    0x2, 0x2, 0x140, 0x141, 0x5, 0x2a, 0x16, 0x2, 0x141, 0x142, 0x7, 0x47, 
    0x2, 0x2, 0x142, 0x143, 0x5, 0x2c, 0x17, 0x2, 0x143, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x145, 0x7, 0x32, 0x2, 0x2, 0x145, 0x14c, 0x5, 0x2a, 
    0x16, 0x2, 0x146, 0x147, 0x7, 0x35, 0x2, 0x2, 0x147, 0x14c, 0x5, 0x2a, 
    0x16, 0x2, 0x148, 0x149, 0x5, 0x2e, 0x18, 0x2, 0x149, 0x14a, 0x5, 0x2c, 
    0x17, 0x2, 0x14a, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x13f, 0x3, 0x2, 
    0x2, 0x2, 0x14b, 0x144, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x14b, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x161, 0x7, 0x34, 0x2, 0x2, 0x14e, 0x161, 0x7, 0x37, 0x2, 
    0x2, 0x14f, 0x161, 0x7, 0x33, 0x2, 0x2, 0x150, 0x161, 0x7, 0x36, 0x2, 
    0x2, 0x151, 0x152, 0x7, 0x3b, 0x2, 0x2, 0x152, 0x161, 0x7, 0x3b, 0x2, 
    0x2, 0x153, 0x154, 0x7, 0x32, 0x2, 0x2, 0x154, 0x161, 0x7, 0x3b, 0x2, 
    0x2, 0x155, 0x161, 0x7, 0x35, 0x2, 0x2, 0x156, 0x159, 0x7, 0x4c, 0x2, 
    0x2, 0x157, 0x15a, 0x7, 0x3b, 0x2, 0x2, 0x158, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x158, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x161, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15e, 0x7, 0x4d, 0x2, 
    0x2, 0x15c, 0x15f, 0x7, 0x3b, 0x2, 0x2, 0x15d, 0x15f, 0x3, 0x2, 0x2, 
    0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x15f, 0x161, 0x3, 0x2, 0x2, 0x2, 0x160, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x14f, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x150, 0x3, 0x2, 0x2, 0x2, 0x160, 0x151, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x153, 0x3, 0x2, 0x2, 0x2, 0x160, 0x155, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x156, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15b, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 0x2, 0x162, 0x165, 0x5, 0x2a, 0x16, 
    0x2, 0x163, 0x165, 0x3, 0x2, 0x2, 0x2, 0x164, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x164, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x166, 0x16a, 0x5, 0x82, 0x42, 0x2, 0x167, 0x168, 0x7, 0x46, 0x2, 0x2, 
    0x168, 0x16b, 0x7, 0x47, 0x2, 0x2, 0x169, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x16a, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x169, 0x3, 0x2, 0x2, 0x2, 
    0x16b, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x170, 0x9, 0x2, 0x2, 0x2, 
    0x16d, 0x170, 0x7, 0x27, 0x2, 0x2, 0x16e, 0x170, 0x7, 0x28, 0x2, 0x2, 
    0x16f, 0x166, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16e, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x7, 0xa, 0x2, 0x2, 0x172, 
    0x173, 0x7, 0x4a, 0x2, 0x2, 0x173, 0x174, 0x7, 0x40, 0x2, 0x2, 0x174, 
    0x175, 0x7, 0x4b, 0x2, 0x2, 0x175, 0x176, 0x7, 0x48, 0x2, 0x2, 0x176, 
    0x177, 0x5, 0x26, 0x14, 0x2, 0x177, 0x178, 0x7, 0x49, 0x2, 0x2, 0x178, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x7, 0x9, 0x2, 0x2, 0x17a, 0x17b, 
    0x7, 0x48, 0x2, 0x2, 0x17b, 0x17c, 0x5, 0x34, 0x1b, 0x2, 0x17c, 0x17d, 
    0x7, 0x49, 0x2, 0x2, 0x17d, 0x33, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 
    0x5, 0x36, 0x1c, 0x2, 0x17f, 0x180, 0x5, 0x34, 0x1b, 0x2, 0x180, 0x183, 
    0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 0x3, 0x2, 0x2, 0x2, 0x182, 0x17e, 
    0x3, 0x2, 0x2, 0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x183, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x184, 0x185, 0x7, 0x7, 0x2, 0x2, 0x185, 0x186, 0x7, 
    0x48, 0x2, 0x2, 0x186, 0x187, 0x5, 0x26, 0x14, 0x2, 0x187, 0x188, 0x7, 
    0x49, 0x2, 0x2, 0x188, 0x37, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x7, 
    0x15, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x4e, 0x2, 0x2, 0x18b, 0x18c, 0x9, 
    0x3, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x4f, 0x2, 0x2, 0x18d, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x193, 0x5, 0x78, 0x3d, 0x2, 0x18f, 0x190, 0x7, 
    0x52, 0x2, 0x2, 0x190, 0x192, 0x5, 0x78, 0x3d, 0x2, 0x191, 0x18f, 0x3, 
    0x2, 0x2, 0x2, 0x192, 0x195, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 
    0x2, 0x2, 0x2, 0x193, 0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x195, 0x193, 0x3, 0x2, 0x2, 0x2, 0x196, 0x19b, 0x5, 0x78, 
    0x3d, 0x2, 0x197, 0x198, 0x7, 0x52, 0x2, 0x2, 0x198, 0x19a, 0x5, 0x78, 
    0x3d, 0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19d, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 
    0x2, 0x2, 0x19c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x1a8, 0x5, 0x5c, 0x2f, 0x2, 0x19f, 0x1a4, 0x5, 0x78, 0x3d, 
    0x2, 0x1a0, 0x1a1, 0x7, 0x52, 0x2, 0x2, 0x1a1, 0x1a3, 0x5, 0x78, 0x3d, 
    0x2, 0x1a2, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x1a4, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x3, 0x2, 0x2, 
    0x2, 0x1a5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 
    0x2, 0x1a7, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x5, 0x3c, 0x1f, 
    0x2, 0x1aa, 0x1ab, 0x7, 0x46, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 0x74, 0x3b, 
    0x2, 0x1ac, 0x1ad, 0x7, 0x47, 0x2, 0x2, 0x1ad, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1b2, 0x5, 0x4c, 0x27, 0x2, 0x1af, 0x1b2, 0x5, 0x56, 0x2c, 
    0x2, 0x1b0, 0x1b2, 0x5, 0x6a, 0x36, 0x2, 0x1b1, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b0, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x1b5, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x46, 0x24, 0x2, 
    0x1b7, 0x1b8, 0x5, 0x44, 0x23, 0x2, 0x1b8, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1b6, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1bc, 
    0x1bd, 0x7, 0x26, 0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x4c, 0x2, 0x2, 0x1be, 
    0x1bf, 0x5, 0x48, 0x25, 0x2, 0x1bf, 0x1c0, 0x7, 0x4d, 0x2, 0x2, 0x1c0, 
    0x1c1, 0x5, 0x4a, 0x26, 0x2, 0x1c1, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1c2, 
    0x1c3, 0x5, 0x78, 0x3d, 0x2, 0x1c3, 0x1c4, 0x7, 0x52, 0x2, 0x2, 0x1c4, 
    0x1c5, 0x5, 0x78, 0x3d, 0x2, 0x1c5, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
    0x1c7, 0x7, 0x3f, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x56, 0x2, 0x2, 0x1c8, 
    0x1ce, 0x5, 0x48, 0x25, 0x2, 0x1c9, 0x1ca, 0x5, 0x78, 0x3d, 0x2, 0x1ca, 
    0x1cb, 0x7, 0x56, 0x2, 0x2, 0x1cb, 0x1cc, 0x5, 0x48, 0x25, 0x2, 0x1cc, 
    0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
    0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x7, 0x30, 0x2, 0x2, 0x1d0, 
    0x1d3, 0x5, 0x78, 0x3d, 0x2, 0x1d1, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d2, 
    0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x7, 0x16, 0x2, 0x2, 0x1d5, 
    0x1d6, 0x5, 0x4e, 0x28, 0x2, 0x1d6, 0x1d7, 0x5, 0x78, 0x3d, 0x2, 0x1d7, 
    0x1d8, 0x7, 0x4f, 0x2, 0x2, 0x1d8, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
    0x1e0, 0x5, 0x50, 0x29, 0x2, 0x1da, 0x1e0, 0x5, 0x52, 0x2a, 0x2, 0x1db, 
    0x1e0, 0x5, 0x54, 0x2b, 0x2, 0x1dc, 0x1e0, 0x7, 0x19, 0x2, 0x2, 0x1dd, 
    0x1e0, 0x7, 0x1a, 0x2, 0x2, 0x1de, 0x1e0, 0x5, 0x78, 0x3d, 0x2, 0x1df, 
    0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1df, 
    0x1db, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1df, 
    0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e8, 0x7, 0x17, 0x2, 0x2, 0x1e2, 
    0x1e3, 0x7, 0x46, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x40, 0x2, 0x2, 0x1e4, 
    0x1e5, 0x7, 0x3f, 0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0x40, 0x2, 0x2, 0x1e6, 
    0x1e9, 0x7, 0x47, 0x2, 0x2, 0x1e7, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e8, 
    0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1f1, 0x7, 0x18, 0x2, 0x2, 0x1eb, 
    0x1ec, 0x7, 0x46, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0x41, 0x2, 0x2, 0x1ed, 
    0x1ee, 0x7, 0x3f, 0x2, 0x2, 0x1ee, 0x1ef, 0x7, 0x41, 0x2, 0x2, 0x1ef, 
    0x1f2, 0x7, 0x47, 0x2, 0x2, 0x1f0, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
    0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x7, 0x21, 0x2, 0x2, 0x1f4, 
    0x1f5, 0x7, 0x46, 0x2, 0x2, 0x1f5, 0x1fa, 0x5, 0x78, 0x3d, 0x2, 0x1f6, 
    0x1f7, 0x7, 0x50, 0x2, 0x2, 0x1f7, 0x1f9, 0x5, 0x78, 0x3d, 0x2, 0x1f8, 
    0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
    0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 
    0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fd, 
    0x1fe, 0x7, 0x47, 0x2, 0x2, 0x1fe, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
    0x200, 0x7, 0x23, 0x2, 0x2, 0x200, 0x201, 0x5, 0x4e, 0x28, 0x2, 0x201, 
    0x204, 0x5, 0x78, 0x3d, 0x2, 0x202, 0x203, 0x7, 0x3b, 0x2, 0x2, 0x203, 
    0x205, 0x5, 0x58, 0x2d, 0x2, 0x204, 0x202, 0x3, 0x2, 0x2, 0x2, 0x204, 
    0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
    0x207, 0x7, 0x4f, 0x2, 0x2, 0x207, 0x57, 0x3, 0x2, 0x2, 0x2, 0x208, 
    0x20f, 0x7, 0x40, 0x2, 0x2, 0x209, 0x20f, 0x7, 0x41, 0x2, 0x2, 0x20a, 
    0x20f, 0x7, 0x42, 0x2, 0x2, 0x20b, 0x20f, 0x7, 0x38, 0x2, 0x2, 0x20c, 
    0x20f, 0x7, 0x39, 0x2, 0x2, 0x20d, 0x20f, 0x5, 0x78, 0x3d, 0x2, 0x20e, 
    0x208, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20e, 
    0x20a, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20e, 
    0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20f, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x5, 0x7a, 0x3e, 0x2, 0x211, 
    0x212, 0x5, 0x78, 0x3d, 0x2, 0x212, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x213, 
    0x216, 0x5, 0x7c, 0x3f, 0x2, 0x214, 0x216, 0x3, 0x2, 0x2, 0x2, 0x215, 
    0x213, 0x3, 0x2, 0x2, 0x2, 0x215, 0x214, 0x3, 0x2, 0x2, 0x2, 0x216, 
    0x217, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x5, 0x78, 0x3d, 0x2, 0x218, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x7, 0x28, 0x2, 0x2, 0x21a, 
    0x21b, 0x5, 0x78, 0x3d, 0x2, 0x21b, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x21c, 
    0x21d, 0x5, 0x5c, 0x2f, 0x2, 0x21d, 0x21e, 0x7, 0x3b, 0x2, 0x2, 0x21e, 
    0x21f, 0x5, 0x2a, 0x16, 0x2, 0x21f, 0x220, 0x7, 0x4f, 0x2, 0x2, 0x220, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x221, 0x222, 0x5, 0x4e, 0x28, 0x2, 0x222, 
    0x226, 0x5, 0x78, 0x3d, 0x2, 0x223, 0x224, 0x7, 0x3b, 0x2, 0x2, 0x224, 
    0x227, 0x5, 0x2a, 0x16, 0x2, 0x225, 0x227, 0x3, 0x2, 0x2, 0x2, 0x226, 
    0x223, 0x3, 0x2, 0x2, 0x2, 0x226, 0x225, 0x3, 0x2, 0x2, 0x2, 0x227, 
    0x228, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x7, 0x4f, 0x2, 0x2, 0x229, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x7, 0x29, 0x2, 0x2, 0x22b, 
    0x22e, 0x5, 0x40, 0x21, 0x2, 0x22c, 0x22f, 0x5, 0x5e, 0x30, 0x2, 0x22d, 
    0x22f, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22e, 
    0x22d, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x231, 0x7, 0x4f, 0x2, 0x2, 0x231, 0x65, 0x3, 0x2, 0x2, 0x2, 0x232, 
    0x235, 0x5, 0x60, 0x31, 0x2, 0x233, 0x235, 0x5, 0x64, 0x33, 0x2, 0x234, 
    0x232, 0x3, 0x2, 0x2, 0x2, 0x234, 0x233, 0x3, 0x2, 0x2, 0x2, 0x235, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x236, 0x23a, 0x7, 0x48, 0x2, 0x2, 0x237, 
    0x239, 0x5, 0x66, 0x34, 0x2, 0x238, 0x237, 0x3, 0x2, 0x2, 0x2, 0x239, 
    0x23c, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x23b, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23c, 
    0x23a, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x7, 0x49, 0x2, 0x2, 0x23e, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x24, 0x2, 0x2, 0x240, 
    0x24f, 0x5, 0x78, 0x3d, 0x2, 0x241, 0x24b, 0x7, 0x46, 0x2, 0x2, 0x242, 
    0x247, 0x5, 0x6c, 0x37, 0x2, 0x243, 0x244, 0x7, 0x50, 0x2, 0x2, 0x244, 
    0x246, 0x5, 0x6c, 0x37, 0x2, 0x245, 0x243, 0x3, 0x2, 0x2, 0x2, 0x246, 
    0x249, 0x3, 0x2, 0x2, 0x2, 0x247, 0x245, 0x3, 0x2, 0x2, 0x2, 0x247, 
    0x248, 0x3, 0x2, 0x2, 0x2, 0x248, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x249, 
    0x247, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24b, 
    0x242, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24c, 
    0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x250, 0x7, 0x47, 0x2, 0x2, 0x24e, 
    0x250, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x241, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x24e, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 
    0x252, 0x7, 0x4f, 0x2, 0x2, 0x252, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x253, 
    0x254, 0x5, 0x4e, 0x28, 0x2, 0x254, 0x255, 0x5, 0x78, 0x3d, 0x2, 0x255, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x7, 0x2a, 0x2, 0x2, 0x257, 
    0x258, 0x5, 0x4e, 0x28, 0x2, 0x258, 0x259, 0x5, 0x82, 0x42, 0x2, 0x259, 
    0x25c, 0x7, 0x46, 0x2, 0x2, 0x25a, 0x25d, 0x5, 0x70, 0x39, 0x2, 0x25b, 
    0x25d, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25c, 
    0x25b, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25e, 
    0x25f, 0x7, 0x47, 0x2, 0x2, 0x25f, 0x260, 0x5, 0x8a, 0x46, 0x2, 0x260, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x261, 0x266, 0x5, 0x6c, 0x37, 0x2, 0x262, 
    0x263, 0x7, 0x50, 0x2, 0x2, 0x263, 0x265, 0x5, 0x6c, 0x37, 0x2, 0x264, 
    0x262, 0x3, 0x2, 0x2, 0x2, 0x265, 0x268, 0x3, 0x2, 0x2, 0x2, 0x266, 
    0x264, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 0x3, 0x2, 0x2, 0x2, 0x267, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 
    0x5, 0x82, 0x42, 0x2, 0x26a, 0x26b, 0x7, 0x46, 0x2, 0x2, 0x26b, 0x26c, 
    0x5, 0x74, 0x3b, 0x2, 0x26c, 0x26d, 0x7, 0x47, 0x2, 0x2, 0x26d, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x26e, 0x274, 0x5, 0x58, 0x2d, 0x2, 0x26f, 0x274, 
    0x5, 0x5a, 0x2e, 0x2, 0x270, 0x274, 0x5, 0x5c, 0x2f, 0x2, 0x271, 0x274, 
    0x5, 0x72, 0x3a, 0x2, 0x272, 0x274, 0x3, 0x2, 0x2, 0x2, 0x273, 0x26e, 
    0x3, 0x2, 0x2, 0x2, 0x273, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x273, 0x270, 
    0x3, 0x2, 0x2, 0x2, 0x273, 0x271, 0x3, 0x2, 0x2, 0x2, 0x273, 0x272, 
    0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 
    0x5, 0x76, 0x3c, 0x2, 0x276, 0x75, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 
    0x7, 0x50, 0x2, 0x2, 0x278, 0x27b, 0x5, 0x74, 0x3b, 0x2, 0x279, 0x27b, 
    0x3, 0x2, 0x2, 0x2, 0x27a, 0x277, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x279, 
    0x3, 0x2, 0x2, 0x2, 0x27b, 0x77, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x9, 
    0x4, 0x2, 0x2, 0x27d, 0x79, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x9, 0x5, 
    0x2, 0x2, 0x27f, 0x280, 0x7, 0x52, 0x2, 0x2, 0x280, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x281, 0x282, 0x7, 0x1d, 0x2, 0x2, 0x282, 0x283, 0x7, 0x52, 
    0x2, 0x2, 0x283, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x7, 0x25, 
    0x2, 0x2, 0x285, 0x28a, 0x5, 0x78, 0x3d, 0x2, 0x286, 0x287, 0x7, 0x50, 
    0x2, 0x2, 0x287, 0x289, 0x5, 0x78, 0x3d, 0x2, 0x288, 0x286, 0x3, 0x2, 
    0x2, 0x2, 0x289, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x288, 0x3, 0x2, 
    0x2, 0x2, 0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28d, 0x3, 0x2, 
    0x2, 0x2, 0x28c, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x7, 0x4f, 
    0x2, 0x2, 0x28e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x7, 0x13, 
    0x2, 0x2, 0x290, 0x291, 0x7, 0x4e, 0x2, 0x2, 0x291, 0x292, 0x5, 0x78, 
    0x3d, 0x2, 0x292, 0x293, 0x7, 0x4f, 0x2, 0x2, 0x293, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x294, 0x299, 0x5, 0x78, 0x3d, 0x2, 0x295, 0x296, 0x7, 0x52, 
    0x2, 0x2, 0x296, 0x298, 0x5, 0x78, 0x3d, 0x2, 0x297, 0x295, 0x3, 0x2, 
    0x2, 0x2, 0x298, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x299, 0x297, 0x3, 0x2, 
    0x2, 0x2, 0x299, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x29b, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29f, 0x5, 0x86, 0x44, 
    0x2, 0x29d, 0x29f, 0x5, 0x8a, 0x46, 0x2, 0x29e, 0x29c, 0x3, 0x2, 0x2, 
    0x2, 0x29e, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x2a0, 0x2a9, 0x5, 0x88, 0x45, 0x2, 0x2a1, 0x2a9, 0x5, 0x60, 0x31, 0x2, 
    0x2a2, 0x2a9, 0x5, 0x9c, 0x4f, 0x2, 0x2a3, 0x2a9, 0x5, 0x94, 0x4b, 0x2, 
    0x2a4, 0x2a9, 0x5, 0x62, 0x32, 0x2, 0x2a5, 0x2a9, 0x5, 0x64, 0x33, 0x2, 
    0x2a6, 0x2a9, 0x5, 0x8e, 0x48, 0x2, 0x2a7, 0x2a9, 0x5, 0x8c, 0x47, 0x2, 
    0x2a8, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a1, 0x3, 0x2, 0x2, 0x2, 
    0x2a8, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a3, 0x3, 0x2, 0x2, 0x2, 
    0x2a8, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a5, 0x3, 0x2, 0x2, 0x2, 
    0x2a8, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a7, 0x3, 0x2, 0x2, 0x2, 
    0x2a9, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 0x5, 0x72, 0x3a, 0x2, 
    0x2ab, 0x2ac, 0x7, 0x4f, 0x2, 0x2, 0x2ac, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x2ad, 0x2b1, 0x7, 0x48, 0x2, 0x2, 0x2ae, 0x2b0, 0x5, 0x86, 0x44, 0x2, 
    0x2af, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b3, 0x3, 0x2, 0x2, 0x2, 
    0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x3, 0x2, 0x2, 0x2, 
    0x2b2, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b1, 0x3, 0x2, 0x2, 0x2, 
    0x2b4, 0x2b5, 0x7, 0x49, 0x2, 0x2, 0x2b5, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x2b6, 0x2b7, 0x7, 0x1e, 0x2, 0x2, 0x2b7, 0x2b8, 0x5, 0x90, 0x49, 0x2, 
    0x2b8, 0x2b9, 0x7, 0x4f, 0x2, 0x2, 0x2b9, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x2ba, 0x2bb, 0x7, 0x3a, 0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x4f, 0x2, 0x2, 
    0x2bc, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x5, 0x2e, 0x18, 0x2, 
    0x2be, 0x2bf, 0x5, 0x92, 0x4a, 0x2, 0x2bf, 0x2c9, 0x3, 0x2, 0x2, 0x2, 
    0x2c0, 0x2c1, 0x7, 0x46, 0x2, 0x2, 0x2c1, 0x2c2, 0x5, 0x90, 0x49, 0x2, 
    0x2c2, 0x2c3, 0x7, 0x47, 0x2, 0x2, 0x2c3, 0x2c9, 0x3, 0x2, 0x2, 0x2, 
    0x2c4, 0x2c5, 0x7, 0x54, 0x2, 0x2, 0x2c5, 0x2c9, 0x5, 0x90, 0x49, 0x2, 
    0x2c6, 0x2c7, 0x7, 0x32, 0x2, 0x2, 0x2c7, 0x2c9, 0x5, 0x90, 0x49, 0x2, 
    0x2c8, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c0, 0x3, 0x2, 0x2, 0x2, 
    0x2c8, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c6, 0x3, 0x2, 0x2, 0x2, 
    0x2c9, 0x91, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 0x9, 0x6, 0x2, 0x2, 0x2cb, 
    0x2ce, 0x5, 0x90, 0x49, 0x2, 0x2cc, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2cd, 
    0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2ce, 
    0x93, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d2, 0x5, 0x96, 0x4c, 0x2, 0x2d0, 
    0x2d3, 0x5, 0x9a, 0x4e, 0x2, 0x2d1, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d2, 
    0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d3, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d5, 0x7, 0x2e, 0x2, 0x2, 0x2d5, 
    0x2d8, 0x5, 0x98, 0x4d, 0x2, 0x2d6, 0x2d9, 0x5, 0x84, 0x43, 0x2, 0x2d7, 
    0x2d9, 0x7, 0x4f, 0x2, 0x2, 0x2d8, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d8, 
    0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x97, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 
    0x7, 0x46, 0x2, 0x2, 0x2db, 0x2dc, 0x5, 0x2a, 0x16, 0x2, 0x2dc, 0x2dd, 
    0x7, 0x47, 0x2, 0x2, 0x2dd, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 
    0x7, 0x2f, 0x2, 0x2, 0x2df, 0x2e0, 0x5, 0x84, 0x43, 0x2, 0x2e0, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x2b, 0x2, 0x2, 0x2e2, 0x2e3, 
    0x5, 0x9e, 0x50, 0x2, 0x2e3, 0x2e7, 0x7, 0x48, 0x2, 0x2, 0x2e4, 0x2e6, 
    0x5, 0xa0, 0x51, 0x2, 0x2e5, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e9, 
    0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 
    0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e7, 
    0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2ed, 0x5, 0xa2, 0x52, 0x2, 0x2eb, 0x2ed, 
    0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2eb, 
    0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 
    0x7, 0x49, 0x2, 0x2, 0x2ef, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 
    0x7, 0x46, 0x2, 0x2, 0x2f1, 0x2f2, 0x5, 0x78, 0x3d, 0x2, 0x2f2, 0x2f3, 
    0x7, 0x47, 0x2, 0x2, 0x2f3, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f5, 
    0x7, 0x2c, 0x2, 0x2, 0x2f5, 0x2f6, 0x5, 0x58, 0x2d, 0x2, 0x2f6, 0x2fe, 
    0x7, 0x4e, 0x2, 0x2, 0x2f7, 0x2ff, 0x5, 0x8a, 0x46, 0x2, 0x2f8, 0x2fa, 
    0x5, 0x86, 0x44, 0x2, 0x2f9, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fd, 
    0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 
    0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fb, 
    0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fb, 
    0x3, 0x2, 0x2, 0x2, 0x2ff, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x7, 
    0x2d, 0x2, 0x2, 0x301, 0x309, 0x7, 0x4e, 0x2, 0x2, 0x302, 0x30a, 0x5, 
    0x8a, 0x46, 0x2, 0x303, 0x305, 0x5, 0x86, 0x44, 0x2, 0x304, 0x303, 0x3, 
    0x2, 0x2, 0x2, 0x305, 0x308, 0x3, 0x2, 0x2, 0x2, 0x306, 0x304, 0x3, 
    0x2, 0x2, 0x2, 0x306, 0x307, 0x3, 0x2, 0x2, 0x2, 0x307, 0x30a, 0x3, 
    0x2, 0x2, 0x2, 0x308, 0x306, 0x3, 0x2, 0x2, 0x2, 0x309, 0x302, 0x3, 
    0x2, 0x2, 0x2, 0x309, 0x306, 0x3, 0x2, 0x2, 0x2, 0x30a, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0xab, 0xbb, 0xd1, 0xdc, 0xee, 0xf9, 0x10b, 0x11c, 0x121, 
    0x136, 0x14b, 0x159, 0x15e, 0x160, 0x164, 0x16a, 0x16f, 0x182, 0x193, 
    0x19b, 0x1a4, 0x1a7, 0x1b1, 0x1b3, 0x1ba, 0x1cd, 0x1d2, 0x1df, 0x1e8, 
    0x1f1, 0x1fa, 0x204, 0x20e, 0x215, 0x226, 0x22e, 0x234, 0x23a, 0x247, 
    0x24b, 0x24f, 0x25c, 0x266, 0x273, 0x27a, 0x28a, 0x299, 0x29e, 0x2a8, 
    0x2b1, 0x2c8, 0x2cd, 0x2d2, 0x2d8, 0x2e7, 0x2ec, 0x2fb, 0x2fe, 0x306, 
    0x309, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DiagnosisDeclParser::Initializer DiagnosisDeclParser::_init;
