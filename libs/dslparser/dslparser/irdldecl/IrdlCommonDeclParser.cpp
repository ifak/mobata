
// Generated from /home/sebastian/Documents/Git/MbtCreator/3rd/mobata/libs/dslparser/dslparser/grammars/IrdlCommonDecl.g4 by ANTLR 4.7


#include "IrdlCommonDeclListener.h"

#include "IrdlCommonDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

IrdlCommonDeclParser::IrdlCommonDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

IrdlCommonDeclParser::~IrdlCommonDeclParser() {
  delete _interpreter;
}

std::string IrdlCommonDeclParser::getGrammarFileName() const {
  return "IrdlCommonDecl.g4";
}

const std::vector<std::string>& IrdlCommonDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& IrdlCommonDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- IrdlCommonDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::IrdlCommonDeclContext::IrdlCommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::TypeDefDeclContext *> IrdlCommonDeclParser::IrdlCommonDeclContext::typeDefDecl() {
  return getRuleContexts<IrdlCommonDeclParser::TypeDefDeclContext>();
}

IrdlCommonDeclParser::TypeDefDeclContext* IrdlCommonDeclParser::IrdlCommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::TypeDefDeclContext>(i);
}

std::vector<IrdlCommonDeclParser::AttributeDeclContext *> IrdlCommonDeclParser::IrdlCommonDeclContext::attributeDecl() {
  return getRuleContexts<IrdlCommonDeclParser::AttributeDeclContext>();
}

IrdlCommonDeclParser::AttributeDeclContext* IrdlCommonDeclParser::IrdlCommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::AttributeDeclContext>(i);
}

std::vector<IrdlCommonDeclParser::SignalDeclContext *> IrdlCommonDeclParser::IrdlCommonDeclContext::signalDecl() {
  return getRuleContexts<IrdlCommonDeclParser::SignalDeclContext>();
}

IrdlCommonDeclParser::SignalDeclContext* IrdlCommonDeclParser::IrdlCommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::SignalDeclContext>(i);
}

std::vector<IrdlCommonDeclParser::ActorDeclContext *> IrdlCommonDeclParser::IrdlCommonDeclContext::actorDecl() {
  return getRuleContexts<IrdlCommonDeclParser::ActorDeclContext>();
}

IrdlCommonDeclParser::ActorDeclContext* IrdlCommonDeclParser::IrdlCommonDeclContext::actorDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ActorDeclContext>(i);
}

std::vector<IrdlCommonDeclParser::ComponentDeclContext *> IrdlCommonDeclParser::IrdlCommonDeclContext::componentDecl() {
  return getRuleContexts<IrdlCommonDeclParser::ComponentDeclContext>();
}

IrdlCommonDeclParser::ComponentDeclContext* IrdlCommonDeclParser::IrdlCommonDeclContext::componentDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ComponentDeclContext>(i);
}


size_t IrdlCommonDeclParser::IrdlCommonDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleIrdlCommonDecl;
}

void IrdlCommonDeclParser::IrdlCommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIrdlCommonDecl(this);
}

void IrdlCommonDeclParser::IrdlCommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIrdlCommonDecl(this);
}

IrdlCommonDeclParser::IrdlCommonDeclContext* IrdlCommonDeclParser::irdlCommonDecl() {
  IrdlCommonDeclContext *_localctx = _tracker.createInstance<IrdlCommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, IrdlCommonDeclParser::RuleIrdlCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IrdlCommonDeclParser::ComponentID)
      | (1ULL << IrdlCommonDeclParser::ActorID)
      | (1ULL << IrdlCommonDeclParser::TypeID)
      | (1ULL << IrdlCommonDeclParser::AttributeID)
      | (1ULL << IrdlCommonDeclParser::SignalID))) != 0)) {
      setState(173);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case IrdlCommonDeclParser::TypeID: {
          setState(168);
          typeDefDecl();
          break;
        }

        case IrdlCommonDeclParser::AttributeID: {
          setState(169);
          attributeDecl();
          break;
        }

        case IrdlCommonDeclParser::SignalID: {
          setState(170);
          signalDecl();
          break;
        }

        case IrdlCommonDeclParser::ActorID: {
          setState(171);
          actorDecl();
          break;
        }

        case IrdlCommonDeclParser::ComponentID: {
          setState(172);
          componentDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(177);
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

//----------------- TimerNameIDContext ------------------------------------------------------------------

IrdlCommonDeclParser::TimerNameIDContext::TimerNameIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::TimerNameIDContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}


size_t IrdlCommonDeclParser::TimerNameIDContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleTimerNameID;
}

void IrdlCommonDeclParser::TimerNameIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimerNameID(this);
}

void IrdlCommonDeclParser::TimerNameIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimerNameID(this);
}

IrdlCommonDeclParser::TimerNameIDContext* IrdlCommonDeclParser::timerNameID() {
  TimerNameIDContext *_localctx = _tracker.createInstance<TimerNameIDContext>(_ctx, getState());
  enterRule(_localctx, 2, IrdlCommonDeclParser::RuleTimerNameID);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
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

IrdlCommonDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::AttributeIdPathContext *> IrdlCommonDeclParser::AttributeAssignStatementContext::attributeIdPath() {
  return getRuleContexts<IrdlCommonDeclParser::AttributeIdPathContext>();
}

IrdlCommonDeclParser::AttributeIdPathContext* IrdlCommonDeclParser::AttributeAssignStatementContext::attributeIdPath(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::AttributeIdPathContext>(i);
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(IrdlCommonDeclParser::ASSIGN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

IrdlCommonDeclParser::LiteralValueContext* IrdlCommonDeclParser::AttributeAssignStatementContext::literalValue() {
  return getRuleContext<IrdlCommonDeclParser::LiteralValueContext>(0);
}

IrdlCommonDeclParser::SignalParamNameContext* IrdlCommonDeclParser::AttributeAssignStatementContext::signalParamName() {
  return getRuleContext<IrdlCommonDeclParser::SignalParamNameContext>(0);
}


size_t IrdlCommonDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAttributeAssignStatement;
}

void IrdlCommonDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void IrdlCommonDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

IrdlCommonDeclParser::AttributeAssignStatementContext* IrdlCommonDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, IrdlCommonDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    attributeIdPath();
    setState(181);
    match(IrdlCommonDeclParser::ASSIGN);
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(182);
      literalValue();
      break;
    }

    case 2: {
      setState(183);
      signalParamName();
      break;
    }

    case 3: {
      setState(184);
      attributeIdPath();
      break;
    }

    }
    setState(187);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

IrdlCommonDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::LiteralValueContext* IrdlCommonDeclParser::AtomContext::literalValue() {
  return getRuleContext<IrdlCommonDeclParser::LiteralValueContext>(0);
}

IrdlCommonDeclParser::SignalParamNameContext* IrdlCommonDeclParser::AtomContext::signalParamName() {
  return getRuleContext<IrdlCommonDeclParser::SignalParamNameContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::AtomContext::ThisID() {
  return getToken(IrdlCommonDeclParser::ThisID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AtomContext::DOT() {
  return getToken(IrdlCommonDeclParser::DOT, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::AtomContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

IrdlCommonDeclParser::AttributeIdPathContext* IrdlCommonDeclParser::AtomContext::attributeIdPath() {
  return getRuleContext<IrdlCommonDeclParser::AttributeIdPathContext>(0);
}

IrdlCommonDeclParser::TimerNameIDContext* IrdlCommonDeclParser::AtomContext::timerNameID() {
  return getRuleContext<IrdlCommonDeclParser::TimerNameIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::AtomContext::TimeOutID() {
  return getToken(IrdlCommonDeclParser::TimeOutID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AtomContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AtomContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}


size_t IrdlCommonDeclParser::AtomContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAtom;
}

void IrdlCommonDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void IrdlCommonDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

IrdlCommonDeclParser::AtomContext* IrdlCommonDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 6, IrdlCommonDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(189);
      literalValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(190);
      signalParamName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(191);
      match(IrdlCommonDeclParser::ThisID);
      setState(192);
      match(IrdlCommonDeclParser::DOT);
      setState(193);
      contextID();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(194);
      attributeIdPath();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(195);
      timerNameID();
      setState(196);
      match(IrdlCommonDeclParser::DOT);
      setState(197);
      match(IrdlCommonDeclParser::TimeOutID);
      setState(198);
      match(IrdlCommonDeclParser::LPAREN);
      setState(199);
      match(IrdlCommonDeclParser::RPAREN);
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

//----------------- IrdlDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::IrdlDeclContext::IrdlDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::ImportPathDeclContext* IrdlCommonDeclParser::IrdlDeclContext::importPathDecl() {
  return getRuleContext<IrdlCommonDeclParser::ImportPathDeclContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::IrdlDeclContext::RequirementID() {
  return getToken(IrdlCommonDeclParser::RequirementID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::IrdlDeclContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

IrdlCommonDeclParser::RequirementBodyContext* IrdlCommonDeclParser::IrdlDeclContext::requirementBody() {
  return getRuleContext<IrdlCommonDeclParser::RequirementBodyContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::IrdlDeclContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}


size_t IrdlCommonDeclParser::IrdlDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleIrdlDecl;
}

void IrdlCommonDeclParser::IrdlDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIrdlDecl(this);
}

void IrdlCommonDeclParser::IrdlDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIrdlDecl(this);
}

IrdlCommonDeclParser::IrdlDeclContext* IrdlCommonDeclParser::irdlDecl() {
  IrdlDeclContext *_localctx = _tracker.createInstance<IrdlDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, IrdlCommonDeclParser::RuleIrdlDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    importPathDecl();
    setState(204);
    match(IrdlCommonDeclParser::RequirementID);
    setState(205);
    match(IrdlCommonDeclParser::LBRACE);
    setState(206);
    requirementBody();
    setState(207);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RequirementBodyContext ------------------------------------------------------------------

IrdlCommonDeclParser::RequirementBodyContext::RequirementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::SequenceDeclContext* IrdlCommonDeclParser::RequirementBodyContext::sequenceDecl() {
  return getRuleContext<IrdlCommonDeclParser::SequenceDeclContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::RequirementBodyContext::DeclarationID() {
  return getToken(IrdlCommonDeclParser::DeclarationID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::RequirementBodyContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

IrdlCommonDeclParser::NameDeclContext* IrdlCommonDeclParser::RequirementBodyContext::nameDecl() {
  return getRuleContext<IrdlCommonDeclParser::NameDeclContext>(0);
}

IrdlCommonDeclParser::DeclarationsContext* IrdlCommonDeclParser::RequirementBodyContext::declarations() {
  return getRuleContext<IrdlCommonDeclParser::DeclarationsContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::RequirementBodyContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}


size_t IrdlCommonDeclParser::RequirementBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleRequirementBody;
}

void IrdlCommonDeclParser::RequirementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRequirementBody(this);
}

void IrdlCommonDeclParser::RequirementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRequirementBody(this);
}

IrdlCommonDeclParser::RequirementBodyContext* IrdlCommonDeclParser::requirementBody() {
  RequirementBodyContext *_localctx = _tracker.createInstance<RequirementBodyContext>(_ctx, getState());
  enterRule(_localctx, 10, IrdlCommonDeclParser::RuleRequirementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(IrdlCommonDeclParser::DeclarationID);
    setState(210);
    match(IrdlCommonDeclParser::LBRACE);
    setState(211);
    nameDecl();
    setState(212);
    declarations();
    setState(213);
    match(IrdlCommonDeclParser::RBRACE);
    setState(215);
    sequenceDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasDefContext ------------------------------------------------------------------

IrdlCommonDeclParser::AliasDefContext::AliasDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::AliasDefContext::UseID() {
  return getToken(IrdlCommonDeclParser::UseID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AliasDefContext::AsID() {
  return getToken(IrdlCommonDeclParser::AsID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::AliasDefContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::AliasDefContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

IrdlCommonDeclParser::ComponentIdPathContext* IrdlCommonDeclParser::AliasDefContext::componentIdPath() {
  return getRuleContext<IrdlCommonDeclParser::ComponentIdPathContext>(0);
}


size_t IrdlCommonDeclParser::AliasDefContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAliasDef;
}

void IrdlCommonDeclParser::AliasDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasDef(this);
}

void IrdlCommonDeclParser::AliasDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasDef(this);
}

IrdlCommonDeclParser::AliasDefContext* IrdlCommonDeclParser::aliasDef() {
  AliasDefContext *_localctx = _tracker.createInstance<AliasDefContext>(_ctx, getState());
  enterRule(_localctx, 12, IrdlCommonDeclParser::RuleAliasDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(IrdlCommonDeclParser::UseID);

    setState(218);
    componentIdPath();
    setState(219);
    match(IrdlCommonDeclParser::AsID);
    setState(220);
    contextID();
    setState(221);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

IrdlCommonDeclParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::AttributeDeclContext* IrdlCommonDeclParser::DeclarationsContext::attributeDecl() {
  return getRuleContext<IrdlCommonDeclParser::AttributeDeclContext>(0);
}

IrdlCommonDeclParser::DeclarationsContext* IrdlCommonDeclParser::DeclarationsContext::declarations() {
  return getRuleContext<IrdlCommonDeclParser::DeclarationsContext>(0);
}

IrdlCommonDeclParser::TypeDefDeclContext* IrdlCommonDeclParser::DeclarationsContext::typeDefDecl() {
  return getRuleContext<IrdlCommonDeclParser::TypeDefDeclContext>(0);
}

IrdlCommonDeclParser::SignalDeclContext* IrdlCommonDeclParser::DeclarationsContext::signalDecl() {
  return getRuleContext<IrdlCommonDeclParser::SignalDeclContext>(0);
}

IrdlCommonDeclParser::AliasDefContext* IrdlCommonDeclParser::DeclarationsContext::aliasDef() {
  return getRuleContext<IrdlCommonDeclParser::AliasDefContext>(0);
}

IrdlCommonDeclParser::ComponentDeclContext* IrdlCommonDeclParser::DeclarationsContext::componentDecl() {
  return getRuleContext<IrdlCommonDeclParser::ComponentDeclContext>(0);
}

IrdlCommonDeclParser::ActorDeclContext* IrdlCommonDeclParser::DeclarationsContext::actorDecl() {
  return getRuleContext<IrdlCommonDeclParser::ActorDeclContext>(0);
}

IrdlCommonDeclParser::DescriptionDeclContext* IrdlCommonDeclParser::DeclarationsContext::descriptionDecl() {
  return getRuleContext<IrdlCommonDeclParser::DescriptionDeclContext>(0);
}


size_t IrdlCommonDeclParser::DeclarationsContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleDeclarations;
}

void IrdlCommonDeclParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void IrdlCommonDeclParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

IrdlCommonDeclParser::DeclarationsContext* IrdlCommonDeclParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 14, IrdlCommonDeclParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::AttributeID: {
        enterOuterAlt(_localctx, 1);
        setState(223);
        attributeDecl();
        setState(224);
        declarations();
        break;
      }

      case IrdlCommonDeclParser::TypeID: {
        enterOuterAlt(_localctx, 2);
        setState(226);
        typeDefDecl();
        setState(227);
        declarations();
        break;
      }

      case IrdlCommonDeclParser::SignalID: {
        enterOuterAlt(_localctx, 3);
        setState(229);
        signalDecl();
        setState(230);
        declarations();
        break;
      }

      case IrdlCommonDeclParser::UseID: {
        enterOuterAlt(_localctx, 4);
        setState(232);
        aliasDef();
        setState(233);
        declarations();
        break;
      }

      case IrdlCommonDeclParser::ComponentID: {
        enterOuterAlt(_localctx, 5);
        setState(235);
        componentDecl();
        setState(236);
        declarations();
        break;
      }

      case IrdlCommonDeclParser::ActorID: {
        enterOuterAlt(_localctx, 6);
        setState(238);
        actorDecl();
        setState(239);
        declarations();
        break;
      }

      case IrdlCommonDeclParser::DescriptionID: {
        enterOuterAlt(_localctx, 7);
        setState(241);
        descriptionDecl();
        setState(242);
        declarations();
        break;
      }

      case IrdlCommonDeclParser::RBRACE: {
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

//----------------- ComponentDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::ComponentDeclContext::ComponentDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ComponentDeclContext::ComponentID() {
  return getToken(IrdlCommonDeclParser::ComponentID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ComponentDeclContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

IrdlCommonDeclParser::ComponentBodyContext* IrdlCommonDeclParser::ComponentDeclContext::componentBody() {
  return getRuleContext<IrdlCommonDeclParser::ComponentBodyContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::ComponentDeclContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}


size_t IrdlCommonDeclParser::ComponentDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleComponentDecl;
}

void IrdlCommonDeclParser::ComponentDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentDecl(this);
}

void IrdlCommonDeclParser::ComponentDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentDecl(this);
}

IrdlCommonDeclParser::ComponentDeclContext* IrdlCommonDeclParser::componentDecl() {
  ComponentDeclContext *_localctx = _tracker.createInstance<ComponentDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, IrdlCommonDeclParser::RuleComponentDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(IrdlCommonDeclParser::ComponentID);
    setState(248);
    match(IrdlCommonDeclParser::LBRACE);
    setState(249);
    componentBody();
    setState(250);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentBodyContext ------------------------------------------------------------------

IrdlCommonDeclParser::ComponentBodyContext::ComponentBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::NameDeclContext* IrdlCommonDeclParser::ComponentBodyContext::nameDecl() {
  return getRuleContext<IrdlCommonDeclParser::NameDeclContext>(0);
}

IrdlCommonDeclParser::CommonDeclContext* IrdlCommonDeclParser::ComponentBodyContext::commonDecl() {
  return getRuleContext<IrdlCommonDeclParser::CommonDeclContext>(0);
}

IrdlCommonDeclParser::DescriptionDeclContext* IrdlCommonDeclParser::ComponentBodyContext::descriptionDecl() {
  return getRuleContext<IrdlCommonDeclParser::DescriptionDeclContext>(0);
}

std::vector<IrdlCommonDeclParser::PortDeclContext *> IrdlCommonDeclParser::ComponentBodyContext::portDecl() {
  return getRuleContexts<IrdlCommonDeclParser::PortDeclContext>();
}

IrdlCommonDeclParser::PortDeclContext* IrdlCommonDeclParser::ComponentBodyContext::portDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::PortDeclContext>(i);
}


size_t IrdlCommonDeclParser::ComponentBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleComponentBody;
}

void IrdlCommonDeclParser::ComponentBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentBody(this);
}

void IrdlCommonDeclParser::ComponentBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentBody(this);
}

IrdlCommonDeclParser::ComponentBodyContext* IrdlCommonDeclParser::componentBody() {
  ComponentBodyContext *_localctx = _tracker.createInstance<ComponentBodyContext>(_ctx, getState());
  enterRule(_localctx, 18, IrdlCommonDeclParser::RuleComponentBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    nameDecl();
    setState(255);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID: {
        setState(253);
        descriptionDecl();
        break;
      }

      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::PortID:
      case IrdlCommonDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(257);
    commonDecl();
    setState(261);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::PortID) {
      setState(258);
      portDecl();
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

//----------------- ActorDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::ActorDeclContext::ActorDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ActorDeclContext::ActorID() {
  return getToken(IrdlCommonDeclParser::ActorID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ActorDeclContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

IrdlCommonDeclParser::ActorBodyContext* IrdlCommonDeclParser::ActorDeclContext::actorBody() {
  return getRuleContext<IrdlCommonDeclParser::ActorBodyContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::ActorDeclContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}


size_t IrdlCommonDeclParser::ActorDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleActorDecl;
}

void IrdlCommonDeclParser::ActorDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActorDecl(this);
}

void IrdlCommonDeclParser::ActorDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActorDecl(this);
}

IrdlCommonDeclParser::ActorDeclContext* IrdlCommonDeclParser::actorDecl() {
  ActorDeclContext *_localctx = _tracker.createInstance<ActorDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, IrdlCommonDeclParser::RuleActorDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(IrdlCommonDeclParser::ActorID);
    setState(265);
    match(IrdlCommonDeclParser::LBRACE);
    setState(266);
    actorBody();
    setState(267);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActorBodyContext ------------------------------------------------------------------

IrdlCommonDeclParser::ActorBodyContext::ActorBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::NameDeclContext* IrdlCommonDeclParser::ActorBodyContext::nameDecl() {
  return getRuleContext<IrdlCommonDeclParser::NameDeclContext>(0);
}

IrdlCommonDeclParser::CommonDeclContext* IrdlCommonDeclParser::ActorBodyContext::commonDecl() {
  return getRuleContext<IrdlCommonDeclParser::CommonDeclContext>(0);
}

IrdlCommonDeclParser::DescriptionDeclContext* IrdlCommonDeclParser::ActorBodyContext::descriptionDecl() {
  return getRuleContext<IrdlCommonDeclParser::DescriptionDeclContext>(0);
}

std::vector<IrdlCommonDeclParser::PortDeclContext *> IrdlCommonDeclParser::ActorBodyContext::portDecl() {
  return getRuleContexts<IrdlCommonDeclParser::PortDeclContext>();
}

IrdlCommonDeclParser::PortDeclContext* IrdlCommonDeclParser::ActorBodyContext::portDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::PortDeclContext>(i);
}


size_t IrdlCommonDeclParser::ActorBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleActorBody;
}

void IrdlCommonDeclParser::ActorBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActorBody(this);
}

void IrdlCommonDeclParser::ActorBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActorBody(this);
}

IrdlCommonDeclParser::ActorBodyContext* IrdlCommonDeclParser::actorBody() {
  ActorBodyContext *_localctx = _tracker.createInstance<ActorBodyContext>(_ctx, getState());
  enterRule(_localctx, 22, IrdlCommonDeclParser::RuleActorBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    nameDecl();
    setState(272);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID: {
        setState(270);
        descriptionDecl();
        break;
      }

      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::PortID:
      case IrdlCommonDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(274);
    commonDecl();
    setState(278);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::PortID) {
      setState(275);
      portDecl();
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

//----------------- DescriptionDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::DescriptionDeclContext::DescriptionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::DescriptionDeclContext::DescriptionID() {
  return getToken(IrdlCommonDeclParser::DescriptionID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DescriptionDeclContext::COLON() {
  return getToken(IrdlCommonDeclParser::COLON, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DescriptionDeclContext::STRING() {
  return getToken(IrdlCommonDeclParser::STRING, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DescriptionDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::DescriptionDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleDescriptionDecl;
}

void IrdlCommonDeclParser::DescriptionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescriptionDecl(this);
}

void IrdlCommonDeclParser::DescriptionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescriptionDecl(this);
}

IrdlCommonDeclParser::DescriptionDeclContext* IrdlCommonDeclParser::descriptionDecl() {
  DescriptionDeclContext *_localctx = _tracker.createInstance<DescriptionDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, IrdlCommonDeclParser::RuleDescriptionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(IrdlCommonDeclParser::DescriptionID);
    setState(282);
    match(IrdlCommonDeclParser::COLON);
    setState(283);
    match(IrdlCommonDeclParser::STRING);
    setState(284);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequenceDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::SequenceDeclContext::SequenceDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::StateDeclContext* IrdlCommonDeclParser::SequenceDeclContext::stateDecl() {
  return getRuleContext<IrdlCommonDeclParser::StateDeclContext>(0);
}

IrdlCommonDeclParser::SequenceDeclContext* IrdlCommonDeclParser::SequenceDeclContext::sequenceDecl() {
  return getRuleContext<IrdlCommonDeclParser::SequenceDeclContext>(0);
}

IrdlCommonDeclParser::MessageDeclContext* IrdlCommonDeclParser::SequenceDeclContext::messageDecl() {
  return getRuleContext<IrdlCommonDeclParser::MessageDeclContext>(0);
}

IrdlCommonDeclParser::CheckDeclContext* IrdlCommonDeclParser::SequenceDeclContext::checkDecl() {
  return getRuleContext<IrdlCommonDeclParser::CheckDeclContext>(0);
}

IrdlCommonDeclParser::AltDeclContext* IrdlCommonDeclParser::SequenceDeclContext::altDecl() {
  return getRuleContext<IrdlCommonDeclParser::AltDeclContext>(0);
}

IrdlCommonDeclParser::TimerDeclContext* IrdlCommonDeclParser::SequenceDeclContext::timerDecl() {
  return getRuleContext<IrdlCommonDeclParser::TimerDeclContext>(0);
}

IrdlCommonDeclParser::DurationDeclContext* IrdlCommonDeclParser::SequenceDeclContext::durationDecl() {
  return getRuleContext<IrdlCommonDeclParser::DurationDeclContext>(0);
}

IrdlCommonDeclParser::AttributeAssignStatementContext* IrdlCommonDeclParser::SequenceDeclContext::attributeAssignStatement() {
  return getRuleContext<IrdlCommonDeclParser::AttributeAssignStatementContext>(0);
}


size_t IrdlCommonDeclParser::SequenceDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSequenceDecl;
}

void IrdlCommonDeclParser::SequenceDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequenceDecl(this);
}

void IrdlCommonDeclParser::SequenceDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequenceDecl(this);
}

IrdlCommonDeclParser::SequenceDeclContext* IrdlCommonDeclParser::sequenceDecl() {
  SequenceDeclContext *_localctx = _tracker.createInstance<SequenceDeclContext>(_ctx, getState());
  enterRule(_localctx, 26, IrdlCommonDeclParser::RuleSequenceDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::StateID: {
        enterOuterAlt(_localctx, 1);
        setState(286);
        stateDecl();
        setState(287);
        sequenceDecl();
        break;
      }

      case IrdlCommonDeclParser::MessageID: {
        enterOuterAlt(_localctx, 2);
        setState(289);
        messageDecl();
        setState(290);
        sequenceDecl();
        break;
      }

      case IrdlCommonDeclParser::CheckID: {
        enterOuterAlt(_localctx, 3);
        setState(292);
        checkDecl();
        setState(293);
        sequenceDecl();
        break;
      }

      case IrdlCommonDeclParser::AltID: {
        enterOuterAlt(_localctx, 4);
        setState(295);
        altDecl();
        setState(296);
        sequenceDecl();
        break;
      }

      case IrdlCommonDeclParser::TimerID: {
        enterOuterAlt(_localctx, 5);
        setState(298);
        timerDecl();
        setState(299);
        sequenceDecl();
        break;
      }

      case IrdlCommonDeclParser::DurationID: {
        enterOuterAlt(_localctx, 6);
        setState(301);
        durationDecl();
        setState(302);
        sequenceDecl();
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
        enterOuterAlt(_localctx, 7);
        setState(304);
        attributeAssignStatement();
        setState(305);
        sequenceDecl();
        break;
      }

      case IrdlCommonDeclParser::RBRACE: {
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

//----------------- StateDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::StateDeclContext::StateDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::StateDeclContext::StateID() {
  return getToken(IrdlCommonDeclParser::StateID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::StateDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::StateDeclContext::AtID() {
  return getToken(IrdlCommonDeclParser::AtID, 0);
}

IrdlCommonDeclParser::LifelineListContext* IrdlCommonDeclParser::StateDeclContext::lifelineList() {
  return getRuleContext<IrdlCommonDeclParser::LifelineListContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::StateDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::StateDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleStateDecl;
}

void IrdlCommonDeclParser::StateDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStateDecl(this);
}

void IrdlCommonDeclParser::StateDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStateDecl(this);
}

IrdlCommonDeclParser::StateDeclContext* IrdlCommonDeclParser::stateDecl() {
  StateDeclContext *_localctx = _tracker.createInstance<StateDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, IrdlCommonDeclParser::RuleStateDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(IrdlCommonDeclParser::StateID);
    setState(311);
    contextID();
    setState(312);
    match(IrdlCommonDeclParser::AtID);
    setState(313);
    lifelineList();
    setState(314);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LifelineListContext ------------------------------------------------------------------

IrdlCommonDeclParser::LifelineListContext::LifelineListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::LifelineListContext::AllID() {
  return getToken(IrdlCommonDeclParser::AllID, 0);
}

IrdlCommonDeclParser::ComponentIdPathContext* IrdlCommonDeclParser::LifelineListContext::componentIdPath() {
  return getRuleContext<IrdlCommonDeclParser::ComponentIdPathContext>(0);
}

IrdlCommonDeclParser::LifelineListOptionalContext* IrdlCommonDeclParser::LifelineListContext::lifelineListOptional() {
  return getRuleContext<IrdlCommonDeclParser::LifelineListOptionalContext>(0);
}


size_t IrdlCommonDeclParser::LifelineListContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleLifelineList;
}

void IrdlCommonDeclParser::LifelineListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLifelineList(this);
}

void IrdlCommonDeclParser::LifelineListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLifelineList(this);
}

IrdlCommonDeclParser::LifelineListContext* IrdlCommonDeclParser::lifelineList() {
  LifelineListContext *_localctx = _tracker.createInstance<LifelineListContext>(_ctx, getState());
  enterRule(_localctx, 30, IrdlCommonDeclParser::RuleLifelineList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::AllID: {
        enterOuterAlt(_localctx, 1);
        setState(316);
        match(IrdlCommonDeclParser::AllID);
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(317);
        componentIdPath();
        setState(318);
        lifelineListOptional();
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

//----------------- LifelineListOptionalContext ------------------------------------------------------------------

IrdlCommonDeclParser::LifelineListOptionalContext::LifelineListOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::LifelineListOptionalContext::COMMA() {
  return getToken(IrdlCommonDeclParser::COMMA, 0);
}

IrdlCommonDeclParser::LifelineListContext* IrdlCommonDeclParser::LifelineListOptionalContext::lifelineList() {
  return getRuleContext<IrdlCommonDeclParser::LifelineListContext>(0);
}


size_t IrdlCommonDeclParser::LifelineListOptionalContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleLifelineListOptional;
}

void IrdlCommonDeclParser::LifelineListOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLifelineListOptional(this);
}

void IrdlCommonDeclParser::LifelineListOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLifelineListOptional(this);
}

IrdlCommonDeclParser::LifelineListOptionalContext* IrdlCommonDeclParser::lifelineListOptional() {
  LifelineListOptionalContext *_localctx = _tracker.createInstance<LifelineListOptionalContext>(_ctx, getState());
  enterRule(_localctx, 32, IrdlCommonDeclParser::RuleLifelineListOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(322);
        match(IrdlCommonDeclParser::COMMA);
        setState(323);
        lifelineList();
        break;
      }

      case IrdlCommonDeclParser::SEMI: {
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

//----------------- MessageSignalContext ------------------------------------------------------------------

IrdlCommonDeclParser::MessageSignalContext::MessageSignalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::SignalIdPathContext* IrdlCommonDeclParser::MessageSignalContext::signalIdPath() {
  return getRuleContext<IrdlCommonDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageSignalContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageSignalContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

IrdlCommonDeclParser::MessageSignalBodyContext* IrdlCommonDeclParser::MessageSignalContext::messageSignalBody() {
  return getRuleContext<IrdlCommonDeclParser::MessageSignalBodyContext>(0);
}


size_t IrdlCommonDeclParser::MessageSignalContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleMessageSignal;
}

void IrdlCommonDeclParser::MessageSignalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageSignal(this);
}

void IrdlCommonDeclParser::MessageSignalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageSignal(this);
}

IrdlCommonDeclParser::MessageSignalContext* IrdlCommonDeclParser::messageSignal() {
  MessageSignalContext *_localctx = _tracker.createInstance<MessageSignalContext>(_ctx, getState());
  enterRule(_localctx, 34, IrdlCommonDeclParser::RuleMessageSignal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    signalIdPath();
    setState(328);
    match(IrdlCommonDeclParser::LPAREN);
    setState(331);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::TriggerID:
      case IrdlCommonDeclParser::MessageTrigger:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::TrueID:
      case IrdlCommonDeclParser::FalseID:
      case IrdlCommonDeclParser::INT:
      case IrdlCommonDeclParser::REAL:
      case IrdlCommonDeclParser::STRING:
      case IrdlCommonDeclParser::ID:
      case IrdlCommonDeclParser::MULT: {
        setState(329);
        messageSignalBody();
        break;
      }

      case IrdlCommonDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(333);
    match(IrdlCommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MessageSignalBodyContext ------------------------------------------------------------------

IrdlCommonDeclParser::MessageSignalBodyContext::MessageSignalBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::MessageSignalBodyOptionalContext* IrdlCommonDeclParser::MessageSignalBodyContext::messageSignalBodyOptional() {
  return getRuleContext<IrdlCommonDeclParser::MessageSignalBodyOptionalContext>(0);
}

IrdlCommonDeclParser::LiteralValueContext* IrdlCommonDeclParser::MessageSignalBodyContext::literalValue() {
  return getRuleContext<IrdlCommonDeclParser::LiteralValueContext>(0);
}

IrdlCommonDeclParser::SignalParamNameContext* IrdlCommonDeclParser::MessageSignalBodyContext::signalParamName() {
  return getRuleContext<IrdlCommonDeclParser::SignalParamNameContext>(0);
}

IrdlCommonDeclParser::AttributeIdPathContext* IrdlCommonDeclParser::MessageSignalBodyContext::attributeIdPath() {
  return getRuleContext<IrdlCommonDeclParser::AttributeIdPathContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageSignalBodyContext::MULT() {
  return getToken(IrdlCommonDeclParser::MULT, 0);
}


size_t IrdlCommonDeclParser::MessageSignalBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleMessageSignalBody;
}

void IrdlCommonDeclParser::MessageSignalBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageSignalBody(this);
}

void IrdlCommonDeclParser::MessageSignalBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageSignalBody(this);
}

IrdlCommonDeclParser::MessageSignalBodyContext* IrdlCommonDeclParser::messageSignalBody() {
  MessageSignalBodyContext *_localctx = _tracker.createInstance<MessageSignalBodyContext>(_ctx, getState());
  enterRule(_localctx, 36, IrdlCommonDeclParser::RuleMessageSignalBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(335);
      literalValue();
      break;
    }

    case 2: {
      setState(336);
      signalParamName();
      break;
    }

    case 3: {
      setState(337);
      attributeIdPath();
      break;
    }

    case 4: {
      setState(338);
      match(IrdlCommonDeclParser::MULT);
      break;
    }

    }
    setState(341);
    messageSignalBodyOptional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MessageSignalBodyOptionalContext ------------------------------------------------------------------

IrdlCommonDeclParser::MessageSignalBodyOptionalContext::MessageSignalBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::MessageSignalBodyOptionalContext::COMMA() {
  return getToken(IrdlCommonDeclParser::COMMA, 0);
}

IrdlCommonDeclParser::MessageSignalBodyContext* IrdlCommonDeclParser::MessageSignalBodyOptionalContext::messageSignalBody() {
  return getRuleContext<IrdlCommonDeclParser::MessageSignalBodyContext>(0);
}


size_t IrdlCommonDeclParser::MessageSignalBodyOptionalContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleMessageSignalBodyOptional;
}

void IrdlCommonDeclParser::MessageSignalBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageSignalBodyOptional(this);
}

void IrdlCommonDeclParser::MessageSignalBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageSignalBodyOptional(this);
}

IrdlCommonDeclParser::MessageSignalBodyOptionalContext* IrdlCommonDeclParser::messageSignalBodyOptional() {
  MessageSignalBodyOptionalContext *_localctx = _tracker.createInstance<MessageSignalBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 38, IrdlCommonDeclParser::RuleMessageSignalBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(343);
        match(IrdlCommonDeclParser::COMMA);
        setState(344);
        messageSignalBody();
        break;
      }

      case IrdlCommonDeclParser::RPAREN: {
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

IrdlCommonDeclParser::MessageDeclContext::MessageDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::MessageDeclContext::MessageID() {
  return getToken(IrdlCommonDeclParser::MessageID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

std::vector<IrdlCommonDeclParser::ComponentIdPathContext *> IrdlCommonDeclParser::MessageDeclContext::componentIdPath() {
  return getRuleContexts<IrdlCommonDeclParser::ComponentIdPathContext>();
}

IrdlCommonDeclParser::ComponentIdPathContext* IrdlCommonDeclParser::MessageDeclContext::componentIdPath(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ComponentIdPathContext>(i);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageDeclContext::RightArrow() {
  return getToken(IrdlCommonDeclParser::RightArrow, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageDeclContext::COLON() {
  return getToken(IrdlCommonDeclParser::COLON, 0);
}

IrdlCommonDeclParser::MessageSignalContext* IrdlCommonDeclParser::MessageDeclContext::messageSignal() {
  return getRuleContext<IrdlCommonDeclParser::MessageSignalContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::MessageDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::MessageDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleMessageDecl;
}

void IrdlCommonDeclParser::MessageDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessageDecl(this);
}

void IrdlCommonDeclParser::MessageDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessageDecl(this);
}

IrdlCommonDeclParser::MessageDeclContext* IrdlCommonDeclParser::messageDecl() {
  MessageDeclContext *_localctx = _tracker.createInstance<MessageDeclContext>(_ctx, getState());
  enterRule(_localctx, 40, IrdlCommonDeclParser::RuleMessageDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(IrdlCommonDeclParser::MessageID);
    setState(349);
    match(IrdlCommonDeclParser::LPAREN);
    setState(350);
    componentIdPath();
    setState(351);
    match(IrdlCommonDeclParser::RightArrow);
    setState(352);
    componentIdPath();
    setState(353);
    match(IrdlCommonDeclParser::RPAREN);
    setState(354);
    match(IrdlCommonDeclParser::COLON);
    setState(355);
    messageSignal();
    setState(356);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::CheckDeclContext::CheckDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclContext::CheckID() {
  return getToken(IrdlCommonDeclParser::CheckID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

std::vector<IrdlCommonDeclParser::ComponentIdPathContext *> IrdlCommonDeclParser::CheckDeclContext::componentIdPath() {
  return getRuleContexts<IrdlCommonDeclParser::ComponentIdPathContext>();
}

IrdlCommonDeclParser::ComponentIdPathContext* IrdlCommonDeclParser::CheckDeclContext::componentIdPath(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ComponentIdPathContext>(i);
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclContext::RightArrow() {
  return getToken(IrdlCommonDeclParser::RightArrow, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclContext::COLON() {
  return getToken(IrdlCommonDeclParser::COLON, 0);
}

IrdlCommonDeclParser::CheckDeclBodyContext* IrdlCommonDeclParser::CheckDeclContext::checkDeclBody() {
  return getRuleContext<IrdlCommonDeclParser::CheckDeclBodyContext>(0);
}

IrdlCommonDeclParser::SignalIdPathContext* IrdlCommonDeclParser::CheckDeclContext::signalIdPath() {
  return getRuleContext<IrdlCommonDeclParser::SignalIdPathContext>(0);
}


size_t IrdlCommonDeclParser::CheckDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleCheckDecl;
}

void IrdlCommonDeclParser::CheckDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckDecl(this);
}

void IrdlCommonDeclParser::CheckDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckDecl(this);
}

IrdlCommonDeclParser::CheckDeclContext* IrdlCommonDeclParser::checkDecl() {
  CheckDeclContext *_localctx = _tracker.createInstance<CheckDeclContext>(_ctx, getState());
  enterRule(_localctx, 42, IrdlCommonDeclParser::RuleCheckDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    match(IrdlCommonDeclParser::CheckID);
    setState(359);
    match(IrdlCommonDeclParser::LPAREN);
    setState(360);
    componentIdPath();
    setState(361);
    match(IrdlCommonDeclParser::RightArrow);
    setState(362);
    componentIdPath();
    setState(363);
    match(IrdlCommonDeclParser::RPAREN);
    setState(364);
    match(IrdlCommonDeclParser::COLON);

    setState(365);
    signalIdPath();
    setState(366);
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

IrdlCommonDeclParser::CheckDeclBodyContext::CheckDeclBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclBodyContext::LBRACKET() {
  return getToken(IrdlCommonDeclParser::LBRACKET, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclBodyContext::RBRACKET() {
  return getToken(IrdlCommonDeclParser::RBRACKET, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclBodyContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

IrdlCommonDeclParser::ExpressionContext* IrdlCommonDeclParser::CheckDeclBodyContext::expression() {
  return getRuleContext<IrdlCommonDeclParser::ExpressionContext>(0);
}

IrdlCommonDeclParser::AttributeAssignContext* IrdlCommonDeclParser::CheckDeclBodyContext::attributeAssign() {
  return getRuleContext<IrdlCommonDeclParser::AttributeAssignContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::CheckDeclBodyContext::COMMA() {
  return getToken(IrdlCommonDeclParser::COMMA, 0);
}

IrdlCommonDeclParser::TimeOutDeclContext* IrdlCommonDeclParser::CheckDeclBodyContext::timeOutDecl() {
  return getRuleContext<IrdlCommonDeclParser::TimeOutDeclContext>(0);
}


size_t IrdlCommonDeclParser::CheckDeclBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleCheckDeclBody;
}

void IrdlCommonDeclParser::CheckDeclBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckDeclBody(this);
}

void IrdlCommonDeclParser::CheckDeclBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckDeclBody(this);
}

IrdlCommonDeclParser::CheckDeclBodyContext* IrdlCommonDeclParser::checkDeclBody() {
  CheckDeclBodyContext *_localctx = _tracker.createInstance<CheckDeclBodyContext>(_ctx, getState());
  enterRule(_localctx, 44, IrdlCommonDeclParser::RuleCheckDeclBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(IrdlCommonDeclParser::LBRACKET);
    setState(371);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::TriggerID:
      case IrdlCommonDeclParser::MessageTrigger:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::NotIdSymbol:
      case IrdlCommonDeclParser::NotIdWord:
      case IrdlCommonDeclParser::TrueID:
      case IrdlCommonDeclParser::FalseID:
      case IrdlCommonDeclParser::INT:
      case IrdlCommonDeclParser::REAL:
      case IrdlCommonDeclParser::STRING:
      case IrdlCommonDeclParser::ID:
      case IrdlCommonDeclParser::LPAREN:
      case IrdlCommonDeclParser::MINUS: {
        setState(369);
        expression();
        break;
      }

      case IrdlCommonDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(373);
    match(IrdlCommonDeclParser::RBRACKET);
    setState(376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(374);
      attributeAssign();
      break;
    }

    case 2: {
      break;
    }

    }
    setState(381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::COMMA: {
        setState(378);
        match(IrdlCommonDeclParser::COMMA);
        setState(379);
        timeOutDecl();
        break;
      }

      case IrdlCommonDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(383);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimerDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::TimerDeclContext::TimerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::TimerID() {
  return getToken(IrdlCommonDeclParser::TimerID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::AtID() {
  return getToken(IrdlCommonDeclParser::AtID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::TimerDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::ASSIGN() {
  return getToken(IrdlCommonDeclParser::ASSIGN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::REAL() {
  return getToken(IrdlCommonDeclParser::REAL, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::INT() {
  return getToken(IrdlCommonDeclParser::INT, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::MilliSekID() {
  return getToken(IrdlCommonDeclParser::MilliSekID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimerDeclContext::SekID() {
  return getToken(IrdlCommonDeclParser::SekID, 0);
}

IrdlCommonDeclParser::ComponentIdPathContext* IrdlCommonDeclParser::TimerDeclContext::componentIdPath() {
  return getRuleContext<IrdlCommonDeclParser::ComponentIdPathContext>(0);
}


size_t IrdlCommonDeclParser::TimerDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleTimerDecl;
}

void IrdlCommonDeclParser::TimerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimerDecl(this);
}

void IrdlCommonDeclParser::TimerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimerDecl(this);
}

IrdlCommonDeclParser::TimerDeclContext* IrdlCommonDeclParser::timerDecl() {
  TimerDeclContext *_localctx = _tracker.createInstance<TimerDeclContext>(_ctx, getState());
  enterRule(_localctx, 46, IrdlCommonDeclParser::RuleTimerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    match(IrdlCommonDeclParser::TimerID);
    setState(386);
    match(IrdlCommonDeclParser::AtID);

    setState(387);
    componentIdPath();
    setState(388);
    contextID();
    setState(389);
    match(IrdlCommonDeclParser::ASSIGN);
    setState(390);
    _la = _input->LA(1);
    if (!(_la == IrdlCommonDeclParser::INT

    || _la == IrdlCommonDeclParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(391);
    _la = _input->LA(1);
    if (!(_la == IrdlCommonDeclParser::MilliSekID

    || _la == IrdlCommonDeclParser::SekID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(392);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeAssignContext ------------------------------------------------------------------

IrdlCommonDeclParser::AttributeAssignContext::AttributeAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeAssignContext::COMMA() {
  return getToken(IrdlCommonDeclParser::COMMA, 0);
}

IrdlCommonDeclParser::AttributeIdPathContext* IrdlCommonDeclParser::AttributeAssignContext::attributeIdPath() {
  return getRuleContext<IrdlCommonDeclParser::AttributeIdPathContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeAssignContext::ASSIGN() {
  return getToken(IrdlCommonDeclParser::ASSIGN, 0);
}

IrdlCommonDeclParser::SignalParamNameContext* IrdlCommonDeclParser::AttributeAssignContext::signalParamName() {
  return getRuleContext<IrdlCommonDeclParser::SignalParamNameContext>(0);
}

IrdlCommonDeclParser::AttributeAssignContext* IrdlCommonDeclParser::AttributeAssignContext::attributeAssign() {
  return getRuleContext<IrdlCommonDeclParser::AttributeAssignContext>(0);
}


size_t IrdlCommonDeclParser::AttributeAssignContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAttributeAssign;
}

void IrdlCommonDeclParser::AttributeAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssign(this);
}

void IrdlCommonDeclParser::AttributeAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssign(this);
}

IrdlCommonDeclParser::AttributeAssignContext* IrdlCommonDeclParser::attributeAssign() {
  AttributeAssignContext *_localctx = _tracker.createInstance<AttributeAssignContext>(_ctx, getState());
  enterRule(_localctx, 48, IrdlCommonDeclParser::RuleAttributeAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    match(IrdlCommonDeclParser::COMMA);
    setState(395);
    attributeIdPath();
    setState(396);
    match(IrdlCommonDeclParser::ASSIGN);
    setState(397);
    signalParamName();
    setState(400);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(398);
      attributeAssign();
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

//----------------- TimeOutDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::TimeOutDeclContext::TimeOutDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::TimeOutDeclContext::TimeOutID() {
  return getToken(IrdlCommonDeclParser::TimeOutID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimeOutDeclContext::COLON() {
  return getToken(IrdlCommonDeclParser::COLON, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimeOutDeclContext::REAL() {
  return getToken(IrdlCommonDeclParser::REAL, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimeOutDeclContext::INT() {
  return getToken(IrdlCommonDeclParser::INT, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimeOutDeclContext::MilliSekID() {
  return getToken(IrdlCommonDeclParser::MilliSekID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TimeOutDeclContext::SekID() {
  return getToken(IrdlCommonDeclParser::SekID, 0);
}


size_t IrdlCommonDeclParser::TimeOutDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleTimeOutDecl;
}

void IrdlCommonDeclParser::TimeOutDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeOutDecl(this);
}

void IrdlCommonDeclParser::TimeOutDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeOutDecl(this);
}

IrdlCommonDeclParser::TimeOutDeclContext* IrdlCommonDeclParser::timeOutDecl() {
  TimeOutDeclContext *_localctx = _tracker.createInstance<TimeOutDeclContext>(_ctx, getState());
  enterRule(_localctx, 50, IrdlCommonDeclParser::RuleTimeOutDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    match(IrdlCommonDeclParser::TimeOutID);
    setState(403);
    match(IrdlCommonDeclParser::COLON);
    setState(404);
    _la = _input->LA(1);
    if (!(_la == IrdlCommonDeclParser::INT

    || _la == IrdlCommonDeclParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(405);
    _la = _input->LA(1);
    if (!(_la == IrdlCommonDeclParser::MilliSekID

    || _la == IrdlCommonDeclParser::SekID)) {
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

IrdlCommonDeclParser::AltDeclContext::AltDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::AltDeclContext::AltID() {
  return getToken(IrdlCommonDeclParser::AltID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AltDeclContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

IrdlCommonDeclParser::AltBodyOptionalContext* IrdlCommonDeclParser::AltDeclContext::altBodyOptional() {
  return getRuleContext<IrdlCommonDeclParser::AltBodyOptionalContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::AltDeclContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}


size_t IrdlCommonDeclParser::AltDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAltDecl;
}

void IrdlCommonDeclParser::AltDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltDecl(this);
}

void IrdlCommonDeclParser::AltDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltDecl(this);
}

IrdlCommonDeclParser::AltDeclContext* IrdlCommonDeclParser::altDecl() {
  AltDeclContext *_localctx = _tracker.createInstance<AltDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, IrdlCommonDeclParser::RuleAltDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(IrdlCommonDeclParser::AltID);
    setState(408);
    match(IrdlCommonDeclParser::LBRACE);
    setState(409);
    altBodyOptional();
    setState(410);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AltBodyContext ------------------------------------------------------------------

IrdlCommonDeclParser::AltBodyContext::AltBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::AltBodyContext::LBRACKET() {
  return getToken(IrdlCommonDeclParser::LBRACKET, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AltBodyContext::RBRACKET() {
  return getToken(IrdlCommonDeclParser::RBRACKET, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AltBodyContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

IrdlCommonDeclParser::SequenceDeclContext* IrdlCommonDeclParser::AltBodyContext::sequenceDecl() {
  return getRuleContext<IrdlCommonDeclParser::SequenceDeclContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::AltBodyContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}

IrdlCommonDeclParser::ExpressionContext* IrdlCommonDeclParser::AltBodyContext::expression() {
  return getRuleContext<IrdlCommonDeclParser::ExpressionContext>(0);
}


size_t IrdlCommonDeclParser::AltBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAltBody;
}

void IrdlCommonDeclParser::AltBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltBody(this);
}

void IrdlCommonDeclParser::AltBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltBody(this);
}

IrdlCommonDeclParser::AltBodyContext* IrdlCommonDeclParser::altBody() {
  AltBodyContext *_localctx = _tracker.createInstance<AltBodyContext>(_ctx, getState());
  enterRule(_localctx, 54, IrdlCommonDeclParser::RuleAltBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(IrdlCommonDeclParser::LBRACKET);
    setState(415);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::TriggerID:
      case IrdlCommonDeclParser::MessageTrigger:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::NotIdSymbol:
      case IrdlCommonDeclParser::NotIdWord:
      case IrdlCommonDeclParser::TrueID:
      case IrdlCommonDeclParser::FalseID:
      case IrdlCommonDeclParser::INT:
      case IrdlCommonDeclParser::REAL:
      case IrdlCommonDeclParser::STRING:
      case IrdlCommonDeclParser::ID:
      case IrdlCommonDeclParser::LPAREN:
      case IrdlCommonDeclParser::MINUS: {
        setState(413);
        expression();
        break;
      }

      case IrdlCommonDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(417);
    match(IrdlCommonDeclParser::RBRACKET);
    setState(418);
    match(IrdlCommonDeclParser::LBRACE);
    setState(419);
    sequenceDecl();
    setState(420);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AltBodyOptionalContext ------------------------------------------------------------------

IrdlCommonDeclParser::AltBodyOptionalContext::AltBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::AltBodyContext* IrdlCommonDeclParser::AltBodyOptionalContext::altBody() {
  return getRuleContext<IrdlCommonDeclParser::AltBodyContext>(0);
}

IrdlCommonDeclParser::AltBodyOptionalContext* IrdlCommonDeclParser::AltBodyOptionalContext::altBodyOptional() {
  return getRuleContext<IrdlCommonDeclParser::AltBodyOptionalContext>(0);
}


size_t IrdlCommonDeclParser::AltBodyOptionalContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAltBodyOptional;
}

void IrdlCommonDeclParser::AltBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltBodyOptional(this);
}

void IrdlCommonDeclParser::AltBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltBodyOptional(this);
}

IrdlCommonDeclParser::AltBodyOptionalContext* IrdlCommonDeclParser::altBodyOptional() {
  AltBodyOptionalContext *_localctx = _tracker.createInstance<AltBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 56, IrdlCommonDeclParser::RuleAltBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(426);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::LBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(422);
        altBody();
        setState(423);
        altBodyOptional();
        break;
      }

      case IrdlCommonDeclParser::RBRACE: {
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

//----------------- DurationDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::DurationDeclContext::DurationDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::DurationID() {
  return getToken(IrdlCommonDeclParser::DurationID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

IrdlCommonDeclParser::SequenceDeclContext* IrdlCommonDeclParser::DurationDeclContext::sequenceDecl() {
  return getRuleContext<IrdlCommonDeclParser::SequenceDeclContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::REAL() {
  return getToken(IrdlCommonDeclParser::REAL, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::INT() {
  return getToken(IrdlCommonDeclParser::INT, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::MilliSekID() {
  return getToken(IrdlCommonDeclParser::MilliSekID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DurationDeclContext::SekID() {
  return getToken(IrdlCommonDeclParser::SekID, 0);
}


size_t IrdlCommonDeclParser::DurationDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleDurationDecl;
}

void IrdlCommonDeclParser::DurationDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDurationDecl(this);
}

void IrdlCommonDeclParser::DurationDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDurationDecl(this);
}

IrdlCommonDeclParser::DurationDeclContext* IrdlCommonDeclParser::durationDecl() {
  DurationDeclContext *_localctx = _tracker.createInstance<DurationDeclContext>(_ctx, getState());
  enterRule(_localctx, 58, IrdlCommonDeclParser::RuleDurationDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(IrdlCommonDeclParser::DurationID);
    setState(429);
    match(IrdlCommonDeclParser::LPAREN);
    setState(430);
    _la = _input->LA(1);
    if (!(_la == IrdlCommonDeclParser::INT

    || _la == IrdlCommonDeclParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(431);
    _la = _input->LA(1);
    if (!(_la == IrdlCommonDeclParser::MilliSekID

    || _la == IrdlCommonDeclParser::SekID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(432);
    match(IrdlCommonDeclParser::RPAREN);
    setState(433);
    match(IrdlCommonDeclParser::LBRACE);
    setState(434);
    sequenceDecl();
    setState(435);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextIDContext ------------------------------------------------------------------

IrdlCommonDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::ID() {
  return getToken(IrdlCommonDeclParser::ID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::NameID() {
  return getToken(IrdlCommonDeclParser::NameID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::LabelID() {
  return getToken(IrdlCommonDeclParser::LabelID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::EnabledID() {
  return getToken(IrdlCommonDeclParser::EnabledID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::TypeID() {
  return getToken(IrdlCommonDeclParser::TypeID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::AttributeID() {
  return getToken(IrdlCommonDeclParser::AttributeID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::SignalID() {
  return getToken(IrdlCommonDeclParser::SignalID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::ImportID() {
  return getToken(IrdlCommonDeclParser::ImportID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::FromID() {
  return getToken(IrdlCommonDeclParser::FromID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::ToID() {
  return getToken(IrdlCommonDeclParser::ToID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::SendID() {
  return getToken(IrdlCommonDeclParser::SendID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::DescriptionID() {
  return getToken(IrdlCommonDeclParser::DescriptionID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::ComponentID() {
  return getToken(IrdlCommonDeclParser::ComponentID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::AtID() {
  return getToken(IrdlCommonDeclParser::AtID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::TimeOutID() {
  return getToken(IrdlCommonDeclParser::TimeOutID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::MilliSekID() {
  return getToken(IrdlCommonDeclParser::MilliSekID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ContextIDContext::SekID() {
  return getToken(IrdlCommonDeclParser::SekID, 0);
}


size_t IrdlCommonDeclParser::ContextIDContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleContextID;
}

void IrdlCommonDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void IrdlCommonDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 60, IrdlCommonDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    _la = _input->LA(1);
    if (!(((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (IrdlCommonDeclParser::DescriptionID - 3))
      | (1ULL << (IrdlCommonDeclParser::ComponentID - 3))
      | (1ULL << (IrdlCommonDeclParser::AtID - 3))
      | (1ULL << (IrdlCommonDeclParser::TimeOutID - 3))
      | (1ULL << (IrdlCommonDeclParser::MilliSekID - 3))
      | (1ULL << (IrdlCommonDeclParser::SekID - 3))
      | (1ULL << (IrdlCommonDeclParser::NameID - 3))
      | (1ULL << (IrdlCommonDeclParser::LabelID - 3))
      | (1ULL << (IrdlCommonDeclParser::EnabledID - 3))
      | (1ULL << (IrdlCommonDeclParser::TypeID - 3))
      | (1ULL << (IrdlCommonDeclParser::AttributeID - 3))
      | (1ULL << (IrdlCommonDeclParser::SignalID - 3))
      | (1ULL << (IrdlCommonDeclParser::ImportID - 3))
      | (1ULL << (IrdlCommonDeclParser::FromID - 3))
      | (1ULL << (IrdlCommonDeclParser::ToID - 3))
      | (1ULL << (IrdlCommonDeclParser::SendID - 3))
      | (1ULL << (IrdlCommonDeclParser::ID - 3)))) != 0))) {
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

IrdlCommonDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::ContextIDContext *> IrdlCommonDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<IrdlCommonDeclParser::ContextIDContext>();
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(IrdlCommonDeclParser::DOT);
}

tree::TerminalNode* IrdlCommonDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(IrdlCommonDeclParser::DOT, i);
}


size_t IrdlCommonDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleComponentIdPath;
}

void IrdlCommonDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void IrdlCommonDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

IrdlCommonDeclParser::ComponentIdPathContext* IrdlCommonDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 62, IrdlCommonDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(439);
    contextID();
    setState(444);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::DOT) {
      setState(440);
      match(IrdlCommonDeclParser::DOT);
      setState(441);
      contextID();
      setState(446);
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

IrdlCommonDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::ContextIDContext *> IrdlCommonDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<IrdlCommonDeclParser::ContextIDContext>();
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::SignalIdPathContext::DOT() {
  return getTokens(IrdlCommonDeclParser::DOT);
}

tree::TerminalNode* IrdlCommonDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(IrdlCommonDeclParser::DOT, i);
}


size_t IrdlCommonDeclParser::SignalIdPathContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSignalIdPath;
}

void IrdlCommonDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void IrdlCommonDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

IrdlCommonDeclParser::SignalIdPathContext* IrdlCommonDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 64, IrdlCommonDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(447);
    contextID();
    setState(452);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::DOT) {
      setState(448);
      match(IrdlCommonDeclParser::DOT);
      setState(449);
      contextID();
      setState(454);
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

IrdlCommonDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::AttributeNameContext* IrdlCommonDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<IrdlCommonDeclParser::AttributeNameContext>(0);
}

std::vector<IrdlCommonDeclParser::ContextIDContext *> IrdlCommonDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<IrdlCommonDeclParser::ContextIDContext>();
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(IrdlCommonDeclParser::DOT);
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(IrdlCommonDeclParser::DOT, i);
}


size_t IrdlCommonDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAttributeIdPath;
}

void IrdlCommonDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void IrdlCommonDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

IrdlCommonDeclParser::AttributeIdPathContext* IrdlCommonDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 66, IrdlCommonDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(464);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(455);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(456);
      contextID();
      setState(461);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == IrdlCommonDeclParser::DOT) {
        setState(457);
        match(IrdlCommonDeclParser::DOT);
        setState(458);
        contextID();
        setState(463);
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

IrdlCommonDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::SignalIdPathContext* IrdlCommonDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<IrdlCommonDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::SignalSendContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

IrdlCommonDeclParser::FunctionCallBodyContext* IrdlCommonDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<IrdlCommonDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::SignalSendContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}


size_t IrdlCommonDeclParser::SignalSendContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSignalSend;
}

void IrdlCommonDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void IrdlCommonDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

IrdlCommonDeclParser::SignalSendContext* IrdlCommonDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 68, IrdlCommonDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    signalIdPath();
    setState(467);
    match(IrdlCommonDeclParser::LPAREN);
    setState(468);
    functionCallBody();
    setState(469);
    match(IrdlCommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::TypeDefDeclContext *> IrdlCommonDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<IrdlCommonDeclParser::TypeDefDeclContext>();
}

IrdlCommonDeclParser::TypeDefDeclContext* IrdlCommonDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::TypeDefDeclContext>(i);
}

std::vector<IrdlCommonDeclParser::AttributeDeclContext *> IrdlCommonDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<IrdlCommonDeclParser::AttributeDeclContext>();
}

IrdlCommonDeclParser::AttributeDeclContext* IrdlCommonDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::AttributeDeclContext>(i);
}

std::vector<IrdlCommonDeclParser::SignalDeclContext *> IrdlCommonDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<IrdlCommonDeclParser::SignalDeclContext>();
}

IrdlCommonDeclParser::SignalDeclContext* IrdlCommonDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::SignalDeclContext>(i);
}


size_t IrdlCommonDeclParser::CommonDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleCommonDecl;
}

void IrdlCommonDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void IrdlCommonDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

IrdlCommonDeclParser::CommonDeclContext* IrdlCommonDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 70, IrdlCommonDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(476);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IrdlCommonDeclParser::TypeID)
      | (1ULL << IrdlCommonDeclParser::AttributeID)
      | (1ULL << IrdlCommonDeclParser::SignalID))) != 0)) {
      setState(474);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case IrdlCommonDeclParser::TypeID: {
          setState(471);
          typeDefDecl();
          break;
        }

        case IrdlCommonDeclParser::AttributeID: {
          setState(472);
          attributeDecl();
          break;
        }

        case IrdlCommonDeclParser::SignalID: {
          setState(473);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(478);
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

IrdlCommonDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::ImportPathBodyContext* IrdlCommonDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<IrdlCommonDeclParser::ImportPathBodyContext>(0);
}

IrdlCommonDeclParser::ImportPathDeclContext* IrdlCommonDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<IrdlCommonDeclParser::ImportPathDeclContext>(0);
}


size_t IrdlCommonDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleImportPathDecl;
}

void IrdlCommonDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void IrdlCommonDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

IrdlCommonDeclParser::ImportPathDeclContext* IrdlCommonDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 72, IrdlCommonDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(483);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::ImportID: {
        enterOuterAlt(_localctx, 1);
        setState(479);
        importPathBody();
        setState(480);
        importPathDecl();
        break;
      }

      case IrdlCommonDeclParser::RequirementID: {
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

IrdlCommonDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(IrdlCommonDeclParser::ImportID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(IrdlCommonDeclParser::LESSTHAN, 0);
}

IrdlCommonDeclParser::ImportFileBodyContext* IrdlCommonDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<IrdlCommonDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(IrdlCommonDeclParser::GREATERTHAN, 0);
}

IrdlCommonDeclParser::ImportAsContext* IrdlCommonDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<IrdlCommonDeclParser::ImportAsContext>(0);
}


size_t IrdlCommonDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleImportPathBody;
}

void IrdlCommonDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void IrdlCommonDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

IrdlCommonDeclParser::ImportPathBodyContext* IrdlCommonDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 74, IrdlCommonDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    match(IrdlCommonDeclParser::ImportID);
    setState(486);
    match(IrdlCommonDeclParser::LESSTHAN);
    setState(487);
    importFileBody();
    setState(488);
    match(IrdlCommonDeclParser::GREATERTHAN);
    setState(489);
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

IrdlCommonDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::ContextIDContext *> IrdlCommonDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<IrdlCommonDeclParser::ContextIDContext>();
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* IrdlCommonDeclParser::ImportFileBodyContext::DOT() {
  return getToken(IrdlCommonDeclParser::DOT, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(IrdlCommonDeclParser::RANGE, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ImportFileBodyContext::DIV() {
  return getToken(IrdlCommonDeclParser::DIV, 0);
}

IrdlCommonDeclParser::ImportFileBodyContext* IrdlCommonDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<IrdlCommonDeclParser::ImportFileBodyContext>(0);
}


size_t IrdlCommonDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleImportFileBody;
}

void IrdlCommonDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void IrdlCommonDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

IrdlCommonDeclParser::ImportFileBodyContext* IrdlCommonDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 76, IrdlCommonDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(502);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(491);
      contextID();
      setState(492);
      match(IrdlCommonDeclParser::DOT);
      setState(493);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(495);
      match(IrdlCommonDeclParser::RANGE);
      setState(496);
      match(IrdlCommonDeclParser::DIV);
      setState(497);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(498);
      contextID();
      setState(499);
      match(IrdlCommonDeclParser::DIV);
      setState(500);
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

IrdlCommonDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ImportAsContext::AsID() {
  return getToken(IrdlCommonDeclParser::AsID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::ImportAsContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}


size_t IrdlCommonDeclParser::ImportAsContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleImportAs;
}

void IrdlCommonDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void IrdlCommonDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

IrdlCommonDeclParser::ImportAsContext* IrdlCommonDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 78, IrdlCommonDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(507);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(504);
        match(IrdlCommonDeclParser::AsID);
        setState(505);
        contextID();
        break;
      }

      case IrdlCommonDeclParser::RequirementID:
      case IrdlCommonDeclParser::ImportID: {
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

IrdlCommonDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(IrdlCommonDeclParser::TypeID, 0);
}

IrdlCommonDeclParser::TypeDeclContext* IrdlCommonDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<IrdlCommonDeclParser::TypeDeclContext>(0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleTypeDefDecl;
}

void IrdlCommonDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void IrdlCommonDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

IrdlCommonDeclParser::TypeDefDeclContext* IrdlCommonDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 80, IrdlCommonDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    match(IrdlCommonDeclParser::TypeID);
    setState(510);
    typeDecl();
    setState(511);
    contextID();
    setState(512);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::IntTypeDeclContext* IrdlCommonDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<IrdlCommonDeclParser::IntTypeDeclContext>(0);
}

IrdlCommonDeclParser::RealTypeDeclContext* IrdlCommonDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<IrdlCommonDeclParser::RealTypeDeclContext>(0);
}

IrdlCommonDeclParser::EnumTypeDeclContext* IrdlCommonDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<IrdlCommonDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::TypeDeclContext::BoolID() {
  return getToken(IrdlCommonDeclParser::BoolID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TypeDeclContext::StringID() {
  return getToken(IrdlCommonDeclParser::StringID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}


size_t IrdlCommonDeclParser::TypeDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleTypeDecl;
}

void IrdlCommonDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void IrdlCommonDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

IrdlCommonDeclParser::TypeDeclContext* IrdlCommonDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 82, IrdlCommonDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(520);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(514);
        intTypeDecl();
        break;
      }

      case IrdlCommonDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(515);
        realTypeDecl();
        break;
      }

      case IrdlCommonDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(516);
        enumTypeDecl();
        break;
      }

      case IrdlCommonDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(517);
        match(IrdlCommonDeclParser::BoolID);
        break;
      }

      case IrdlCommonDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(518);
        match(IrdlCommonDeclParser::StringID);
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(519);
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

IrdlCommonDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::IntTypeDeclContext::IntID() {
  return getToken(IrdlCommonDeclParser::IntID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::IntTypeDeclContext::INT() {
  return getTokens(IrdlCommonDeclParser::INT);
}

tree::TerminalNode* IrdlCommonDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(IrdlCommonDeclParser::INT, i);
}

tree::TerminalNode* IrdlCommonDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(IrdlCommonDeclParser::RANGE, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}


size_t IrdlCommonDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleIntTypeDecl;
}

void IrdlCommonDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void IrdlCommonDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

IrdlCommonDeclParser::IntTypeDeclContext* IrdlCommonDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 84, IrdlCommonDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    match(IrdlCommonDeclParser::IntID);
    setState(529);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::LPAREN: {
        setState(523);
        match(IrdlCommonDeclParser::LPAREN);
        setState(524);
        match(IrdlCommonDeclParser::INT);
        setState(525);
        match(IrdlCommonDeclParser::RANGE);
        setState(526);
        match(IrdlCommonDeclParser::INT);
        setState(527);
        match(IrdlCommonDeclParser::RPAREN);
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
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

IrdlCommonDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::RealTypeDeclContext::RealID() {
  return getToken(IrdlCommonDeclParser::RealID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(IrdlCommonDeclParser::REAL);
}

tree::TerminalNode* IrdlCommonDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(IrdlCommonDeclParser::REAL, i);
}

tree::TerminalNode* IrdlCommonDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(IrdlCommonDeclParser::RANGE, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}


size_t IrdlCommonDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleRealTypeDecl;
}

void IrdlCommonDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void IrdlCommonDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

IrdlCommonDeclParser::RealTypeDeclContext* IrdlCommonDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 86, IrdlCommonDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(531);
    match(IrdlCommonDeclParser::RealID);
    setState(538);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::LPAREN: {
        setState(532);
        match(IrdlCommonDeclParser::LPAREN);
        setState(533);
        match(IrdlCommonDeclParser::REAL);
        setState(534);
        match(IrdlCommonDeclParser::RANGE);
        setState(535);
        match(IrdlCommonDeclParser::REAL);
        setState(536);
        match(IrdlCommonDeclParser::RPAREN);
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
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

IrdlCommonDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(IrdlCommonDeclParser::EnumID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

std::vector<IrdlCommonDeclParser::ContextIDContext *> IrdlCommonDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<IrdlCommonDeclParser::ContextIDContext>();
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* IrdlCommonDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(IrdlCommonDeclParser::COMMA);
}

tree::TerminalNode* IrdlCommonDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(IrdlCommonDeclParser::COMMA, i);
}


size_t IrdlCommonDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleEnumTypeDecl;
}

void IrdlCommonDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void IrdlCommonDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

IrdlCommonDeclParser::EnumTypeDeclContext* IrdlCommonDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 88, IrdlCommonDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(540);
    match(IrdlCommonDeclParser::EnumID);
    setState(541);
    match(IrdlCommonDeclParser::LPAREN);
    setState(542);
    contextID();
    setState(547);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::COMMA) {
      setState(543);
      match(IrdlCommonDeclParser::COMMA);
      setState(544);
      contextID();
      setState(549);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(550);
    match(IrdlCommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(IrdlCommonDeclParser::AttributeID, 0);
}

IrdlCommonDeclParser::TypeDeclContext* IrdlCommonDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<IrdlCommonDeclParser::TypeDeclContext>(0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(IrdlCommonDeclParser::ASSIGN, 0);
}

IrdlCommonDeclParser::LiteralValueContext* IrdlCommonDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<IrdlCommonDeclParser::LiteralValueContext>(0);
}


size_t IrdlCommonDeclParser::AttributeDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAttributeDecl;
}

void IrdlCommonDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void IrdlCommonDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

IrdlCommonDeclParser::AttributeDeclContext* IrdlCommonDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 90, IrdlCommonDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(552);
    match(IrdlCommonDeclParser::AttributeID);
    setState(553);
    typeDecl();
    setState(554);
    contextID();
    setState(557);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == IrdlCommonDeclParser::ASSIGN) {
      setState(555);
      match(IrdlCommonDeclParser::ASSIGN);
      setState(556);
      literalValue();
    }
    setState(559);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

IrdlCommonDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::LiteralValueContext::INT() {
  return getToken(IrdlCommonDeclParser::INT, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::LiteralValueContext::REAL() {
  return getToken(IrdlCommonDeclParser::REAL, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::LiteralValueContext::STRING() {
  return getToken(IrdlCommonDeclParser::STRING, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::LiteralValueContext::TrueID() {
  return getToken(IrdlCommonDeclParser::TrueID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::LiteralValueContext::FalseID() {
  return getToken(IrdlCommonDeclParser::FalseID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}


size_t IrdlCommonDeclParser::LiteralValueContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleLiteralValue;
}

void IrdlCommonDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void IrdlCommonDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

IrdlCommonDeclParser::LiteralValueContext* IrdlCommonDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 92, IrdlCommonDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(567);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(561);
        match(IrdlCommonDeclParser::INT);
        break;
      }

      case IrdlCommonDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(562);
        match(IrdlCommonDeclParser::REAL);
        break;
      }

      case IrdlCommonDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(563);
        match(IrdlCommonDeclParser::STRING);
        break;
      }

      case IrdlCommonDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(564);
        match(IrdlCommonDeclParser::TrueID);
        break;
      }

      case IrdlCommonDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(565);
        match(IrdlCommonDeclParser::FalseID);
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(566);
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

IrdlCommonDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::TriggerDeclContext* IrdlCommonDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<IrdlCommonDeclParser::TriggerDeclContext>(0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}


size_t IrdlCommonDeclParser::SignalParamNameContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSignalParamName;
}

void IrdlCommonDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void IrdlCommonDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

IrdlCommonDeclParser::SignalParamNameContext* IrdlCommonDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 94, IrdlCommonDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    triggerDecl();
    setState(570);
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

IrdlCommonDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

IrdlCommonDeclParser::ThisDeclContext* IrdlCommonDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<IrdlCommonDeclParser::ThisDeclContext>(0);
}


size_t IrdlCommonDeclParser::AttributeNameContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleAttributeName;
}

void IrdlCommonDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void IrdlCommonDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

IrdlCommonDeclParser::AttributeNameContext* IrdlCommonDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 96, IrdlCommonDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(574);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::ThisID: {
        setState(572);
        thisDecl();
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(576);
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

IrdlCommonDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ToPortNameContext::ToID() {
  return getToken(IrdlCommonDeclParser::ToID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}


size_t IrdlCommonDeclParser::ToPortNameContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleToPortName;
}

void IrdlCommonDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void IrdlCommonDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

IrdlCommonDeclParser::ToPortNameContext* IrdlCommonDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 98, IrdlCommonDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(578);
    match(IrdlCommonDeclParser::ToID);
    setState(579);
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

IrdlCommonDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::TypeDeclContext* IrdlCommonDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<IrdlCommonDeclParser::TypeDeclContext>(0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(IrdlCommonDeclParser::ASSIGN, 0);
}

IrdlCommonDeclParser::ExpressionContext* IrdlCommonDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<IrdlCommonDeclParser::ExpressionContext>(0);
}


size_t IrdlCommonDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleLocalAssignStatement;
}

void IrdlCommonDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void IrdlCommonDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

IrdlCommonDeclParser::LocalAssignStatementContext* IrdlCommonDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 100, IrdlCommonDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    typeDecl();
    setState(582);
    contextID();
    setState(586);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::ASSIGN: {
        setState(583);
        match(IrdlCommonDeclParser::ASSIGN);
        setState(584);
        expression();
        break;
      }

      case IrdlCommonDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(588);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

IrdlCommonDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::SendToStatementContext::SendID() {
  return getToken(IrdlCommonDeclParser::SendID, 0);
}

IrdlCommonDeclParser::SignalSendContext* IrdlCommonDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<IrdlCommonDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::SendToStatementContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

IrdlCommonDeclParser::ToPortNameContext* IrdlCommonDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<IrdlCommonDeclParser::ToPortNameContext>(0);
}


size_t IrdlCommonDeclParser::SendToStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSendToStatement;
}

void IrdlCommonDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void IrdlCommonDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

IrdlCommonDeclParser::SendToStatementContext* IrdlCommonDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 102, IrdlCommonDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(590);
    match(IrdlCommonDeclParser::SendID);
    setState(591);
    signalSend();
    setState(594);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::ToID: {
        setState(592);
        toPortName();
        break;
      }

      case IrdlCommonDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(596);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

IrdlCommonDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::AttributeAssignStatementContext* IrdlCommonDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<IrdlCommonDeclParser::AttributeAssignStatementContext>(0);
}

IrdlCommonDeclParser::SendToStatementContext* IrdlCommonDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<IrdlCommonDeclParser::SendToStatementContext>(0);
}


size_t IrdlCommonDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSingleAssignment;
}

void IrdlCommonDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void IrdlCommonDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

IrdlCommonDeclParser::SingleAssignmentContext* IrdlCommonDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 104, IrdlCommonDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(600);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(598);
      attributeAssignStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(599);
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

IrdlCommonDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}

std::vector<IrdlCommonDeclParser::SingleAssignmentContext *> IrdlCommonDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<IrdlCommonDeclParser::SingleAssignmentContext>();
}

IrdlCommonDeclParser::SingleAssignmentContext* IrdlCommonDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::SingleAssignmentContext>(i);
}


size_t IrdlCommonDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleMultiAssignment;
}

void IrdlCommonDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void IrdlCommonDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

IrdlCommonDeclParser::MultiAssignmentContext* IrdlCommonDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 106, IrdlCommonDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    match(IrdlCommonDeclParser::LBRACE);
    setState(606);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (IrdlCommonDeclParser::DescriptionID - 3))
      | (1ULL << (IrdlCommonDeclParser::ComponentID - 3))
      | (1ULL << (IrdlCommonDeclParser::AtID - 3))
      | (1ULL << (IrdlCommonDeclParser::TimeOutID - 3))
      | (1ULL << (IrdlCommonDeclParser::MilliSekID - 3))
      | (1ULL << (IrdlCommonDeclParser::SekID - 3))
      | (1ULL << (IrdlCommonDeclParser::NameID - 3))
      | (1ULL << (IrdlCommonDeclParser::LabelID - 3))
      | (1ULL << (IrdlCommonDeclParser::EnabledID - 3))
      | (1ULL << (IrdlCommonDeclParser::TypeID - 3))
      | (1ULL << (IrdlCommonDeclParser::ThisID - 3))
      | (1ULL << (IrdlCommonDeclParser::AttributeID - 3))
      | (1ULL << (IrdlCommonDeclParser::SignalID - 3))
      | (1ULL << (IrdlCommonDeclParser::ImportID - 3))
      | (1ULL << (IrdlCommonDeclParser::FromID - 3))
      | (1ULL << (IrdlCommonDeclParser::ToID - 3))
      | (1ULL << (IrdlCommonDeclParser::SendID - 3))
      | (1ULL << (IrdlCommonDeclParser::ID - 3)))) != 0)) {
      setState(603);
      singleAssignment();
      setState(608);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(609);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::SignalDeclContext::SignalID() {
  return getToken(IrdlCommonDeclParser::SignalID, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::SignalDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::SignalDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::SignalDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

std::vector<IrdlCommonDeclParser::ParamDeclContext *> IrdlCommonDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<IrdlCommonDeclParser::ParamDeclContext>();
}

IrdlCommonDeclParser::ParamDeclContext* IrdlCommonDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::SignalDeclContext::COMMA() {
  return getTokens(IrdlCommonDeclParser::COMMA);
}

tree::TerminalNode* IrdlCommonDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(IrdlCommonDeclParser::COMMA, i);
}


size_t IrdlCommonDeclParser::SignalDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSignalDecl;
}

void IrdlCommonDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void IrdlCommonDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

IrdlCommonDeclParser::SignalDeclContext* IrdlCommonDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 108, IrdlCommonDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(611);
    match(IrdlCommonDeclParser::SignalID);
    setState(612);
    contextID();
    setState(627);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::LPAREN: {
        setState(613);
        match(IrdlCommonDeclParser::LPAREN);
        setState(623);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case IrdlCommonDeclParser::DescriptionID:
          case IrdlCommonDeclParser::ComponentID:
          case IrdlCommonDeclParser::AtID:
          case IrdlCommonDeclParser::TimeOutID:
          case IrdlCommonDeclParser::MilliSekID:
          case IrdlCommonDeclParser::SekID:
          case IrdlCommonDeclParser::NameID:
          case IrdlCommonDeclParser::LabelID:
          case IrdlCommonDeclParser::EnabledID:
          case IrdlCommonDeclParser::TypeID:
          case IrdlCommonDeclParser::IntID:
          case IrdlCommonDeclParser::RealID:
          case IrdlCommonDeclParser::BoolID:
          case IrdlCommonDeclParser::StringID:
          case IrdlCommonDeclParser::EnumID:
          case IrdlCommonDeclParser::AttributeID:
          case IrdlCommonDeclParser::SignalID:
          case IrdlCommonDeclParser::ImportID:
          case IrdlCommonDeclParser::FromID:
          case IrdlCommonDeclParser::ToID:
          case IrdlCommonDeclParser::SendID:
          case IrdlCommonDeclParser::ID: {
            setState(614);
            paramDecl();
            setState(619);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == IrdlCommonDeclParser::COMMA) {
              setState(615);
              match(IrdlCommonDeclParser::COMMA);
              setState(616);
              paramDecl();
              setState(621);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case IrdlCommonDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(625);
        match(IrdlCommonDeclParser::RPAREN);
        break;
      }

      case IrdlCommonDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(629);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::TypeDeclContext* IrdlCommonDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<IrdlCommonDeclParser::TypeDeclContext>(0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}


size_t IrdlCommonDeclParser::ParamDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleParamDecl;
}

void IrdlCommonDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void IrdlCommonDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

IrdlCommonDeclParser::ParamDeclContext* IrdlCommonDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 110, IrdlCommonDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    typeDecl();
    setState(632);
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

IrdlCommonDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(IrdlCommonDeclParser::FunctionID, 0);
}

IrdlCommonDeclParser::TypeDeclContext* IrdlCommonDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<IrdlCommonDeclParser::TypeDeclContext>(0);
}

IrdlCommonDeclParser::IdPathContext* IrdlCommonDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<IrdlCommonDeclParser::IdPathContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

IrdlCommonDeclParser::NestedStatementBodyContext* IrdlCommonDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<IrdlCommonDeclParser::NestedStatementBodyContext>(0);
}

IrdlCommonDeclParser::FunctionParametersContext* IrdlCommonDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<IrdlCommonDeclParser::FunctionParametersContext>(0);
}


size_t IrdlCommonDeclParser::FunctionDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleFunctionDecl;
}

void IrdlCommonDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void IrdlCommonDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

IrdlCommonDeclParser::FunctionDeclContext* IrdlCommonDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 112, IrdlCommonDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    match(IrdlCommonDeclParser::FunctionID);
    setState(635);
    typeDecl();
    setState(636);
    idPath();
    setState(637);
    match(IrdlCommonDeclParser::LPAREN);
    setState(640);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::IntID:
      case IrdlCommonDeclParser::RealID:
      case IrdlCommonDeclParser::BoolID:
      case IrdlCommonDeclParser::StringID:
      case IrdlCommonDeclParser::EnumID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::ID: {
        setState(638);
        functionParameters();
        break;
      }

      case IrdlCommonDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(642);
    match(IrdlCommonDeclParser::RPAREN);
    setState(643);
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

IrdlCommonDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::ParamDeclContext *> IrdlCommonDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<IrdlCommonDeclParser::ParamDeclContext>();
}

IrdlCommonDeclParser::ParamDeclContext* IrdlCommonDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(IrdlCommonDeclParser::COMMA);
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(IrdlCommonDeclParser::COMMA, i);
}


size_t IrdlCommonDeclParser::FunctionParametersContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleFunctionParameters;
}

void IrdlCommonDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void IrdlCommonDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

IrdlCommonDeclParser::FunctionParametersContext* IrdlCommonDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 114, IrdlCommonDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(645);
    paramDecl();
    setState(650);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::COMMA) {
      setState(646);
      match(IrdlCommonDeclParser::COMMA);
      setState(647);
      paramDecl();
      setState(652);
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

IrdlCommonDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::IdPathContext* IrdlCommonDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<IrdlCommonDeclParser::IdPathContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionCallContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

IrdlCommonDeclParser::FunctionCallBodyContext* IrdlCommonDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<IrdlCommonDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionCallContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}


size_t IrdlCommonDeclParser::FunctionCallContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleFunctionCall;
}

void IrdlCommonDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void IrdlCommonDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

IrdlCommonDeclParser::FunctionCallContext* IrdlCommonDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 116, IrdlCommonDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    idPath();
    setState(654);
    match(IrdlCommonDeclParser::LPAREN);
    setState(655);
    functionCallBody();
    setState(656);
    match(IrdlCommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

IrdlCommonDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::FunctionCallBodyOptionalContext* IrdlCommonDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<IrdlCommonDeclParser::FunctionCallBodyOptionalContext>(0);
}

IrdlCommonDeclParser::LiteralValueContext* IrdlCommonDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<IrdlCommonDeclParser::LiteralValueContext>(0);
}

IrdlCommonDeclParser::SignalParamNameContext* IrdlCommonDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<IrdlCommonDeclParser::SignalParamNameContext>(0);
}

IrdlCommonDeclParser::AttributeNameContext* IrdlCommonDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<IrdlCommonDeclParser::AttributeNameContext>(0);
}

IrdlCommonDeclParser::FunctionCallContext* IrdlCommonDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<IrdlCommonDeclParser::FunctionCallContext>(0);
}


size_t IrdlCommonDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleFunctionCallBody;
}

void IrdlCommonDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void IrdlCommonDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

IrdlCommonDeclParser::FunctionCallBodyContext* IrdlCommonDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 118, IrdlCommonDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(663);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(658);
      literalValue();
      break;
    }

    case 2: {
      setState(659);
      signalParamName();
      break;
    }

    case 3: {
      setState(660);
      attributeName();
      break;
    }

    case 4: {
      setState(661);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(665);
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

IrdlCommonDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(IrdlCommonDeclParser::COMMA, 0);
}

IrdlCommonDeclParser::FunctionCallBodyContext* IrdlCommonDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<IrdlCommonDeclParser::FunctionCallBodyContext>(0);
}


size_t IrdlCommonDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleFunctionCallBodyOptional;
}

void IrdlCommonDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void IrdlCommonDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

IrdlCommonDeclParser::FunctionCallBodyOptionalContext* IrdlCommonDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 120, IrdlCommonDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(670);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(667);
        match(IrdlCommonDeclParser::COMMA);
        setState(668);
        functionCallBody();
        break;
      }

      case IrdlCommonDeclParser::RPAREN: {
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

IrdlCommonDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::TriggerDeclContext::DOT() {
  return getToken(IrdlCommonDeclParser::DOT, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(IrdlCommonDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(IrdlCommonDeclParser::TriggerID, 0);
}


size_t IrdlCommonDeclParser::TriggerDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleTriggerDecl;
}

void IrdlCommonDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void IrdlCommonDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

IrdlCommonDeclParser::TriggerDeclContext* IrdlCommonDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 122, IrdlCommonDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(672);
    _la = _input->LA(1);
    if (!(_la == IrdlCommonDeclParser::TriggerID

    || _la == IrdlCommonDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(673);
    match(IrdlCommonDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ThisDeclContext::ThisID() {
  return getToken(IrdlCommonDeclParser::ThisID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ThisDeclContext::DOT() {
  return getToken(IrdlCommonDeclParser::DOT, 0);
}


size_t IrdlCommonDeclParser::ThisDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleThisDecl;
}

void IrdlCommonDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void IrdlCommonDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

IrdlCommonDeclParser::ThisDeclContext* IrdlCommonDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 124, IrdlCommonDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(675);
    match(IrdlCommonDeclParser::ThisID);
    setState(676);
    match(IrdlCommonDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::PortDeclContext::PortID() {
  return getToken(IrdlCommonDeclParser::PortID, 0);
}

std::vector<IrdlCommonDeclParser::ContextIDContext *> IrdlCommonDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<IrdlCommonDeclParser::ContextIDContext>();
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* IrdlCommonDeclParser::PortDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::PortDeclContext::COMMA() {
  return getTokens(IrdlCommonDeclParser::COMMA);
}

tree::TerminalNode* IrdlCommonDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(IrdlCommonDeclParser::COMMA, i);
}


size_t IrdlCommonDeclParser::PortDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RulePortDecl;
}

void IrdlCommonDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void IrdlCommonDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

IrdlCommonDeclParser::PortDeclContext* IrdlCommonDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 126, IrdlCommonDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(678);
    match(IrdlCommonDeclParser::PortID);
    setState(679);
    contextID();
    setState(684);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::COMMA) {
      setState(680);
      match(IrdlCommonDeclParser::COMMA);
      setState(681);
      contextID();
      setState(686);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(687);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

IrdlCommonDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::NameDeclContext::NameID() {
  return getToken(IrdlCommonDeclParser::NameID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::NameDeclContext::COLON() {
  return getToken(IrdlCommonDeclParser::COLON, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::NameDeclContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::NameDeclContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::NameDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleNameDecl;
}

void IrdlCommonDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void IrdlCommonDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

IrdlCommonDeclParser::NameDeclContext* IrdlCommonDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 128, IrdlCommonDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(689);
    match(IrdlCommonDeclParser::NameID);
    setState(690);
    match(IrdlCommonDeclParser::COLON);
    setState(691);
    contextID();
    setState(692);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

IrdlCommonDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IrdlCommonDeclParser::ContextIDContext *> IrdlCommonDeclParser::IdPathContext::contextID() {
  return getRuleContexts<IrdlCommonDeclParser::ContextIDContext>();
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::IdPathContext::DOT() {
  return getTokens(IrdlCommonDeclParser::DOT);
}

tree::TerminalNode* IrdlCommonDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(IrdlCommonDeclParser::DOT, i);
}


size_t IrdlCommonDeclParser::IdPathContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleIdPath;
}

void IrdlCommonDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void IrdlCommonDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

IrdlCommonDeclParser::IdPathContext* IrdlCommonDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 130, IrdlCommonDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(694);
    contextID();
    setState(699);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::DOT) {
      setState(695);
      match(IrdlCommonDeclParser::DOT);
      setState(696);
      contextID();
      setState(701);
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

IrdlCommonDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::StatementBodyContext* IrdlCommonDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<IrdlCommonDeclParser::StatementBodyContext>(0);
}

IrdlCommonDeclParser::NestedStatementBodyContext* IrdlCommonDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<IrdlCommonDeclParser::NestedStatementBodyContext>(0);
}


size_t IrdlCommonDeclParser::StatementDeclContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleStatementDecl;
}

void IrdlCommonDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void IrdlCommonDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

IrdlCommonDeclParser::StatementDeclContext* IrdlCommonDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 132, IrdlCommonDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(704);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::IntID:
      case IrdlCommonDeclParser::RealID:
      case IrdlCommonDeclParser::BoolID:
      case IrdlCommonDeclParser::StringID:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::ReturnID:
      case IrdlCommonDeclParser::EnumID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::SwitchID:
      case IrdlCommonDeclParser::IfID:
      case IrdlCommonDeclParser::BREAK:
      case IrdlCommonDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(702);
        statementBody();
        break;
      }

      case IrdlCommonDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(703);
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

IrdlCommonDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::FunctionCallStatementContext* IrdlCommonDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<IrdlCommonDeclParser::FunctionCallStatementContext>(0);
}

IrdlCommonDeclParser::AttributeAssignStatementContext* IrdlCommonDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<IrdlCommonDeclParser::AttributeAssignStatementContext>(0);
}

IrdlCommonDeclParser::SwitchStatementContext* IrdlCommonDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<IrdlCommonDeclParser::SwitchStatementContext>(0);
}

IrdlCommonDeclParser::ConditionalStatementContext* IrdlCommonDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<IrdlCommonDeclParser::ConditionalStatementContext>(0);
}

IrdlCommonDeclParser::LocalAssignStatementContext* IrdlCommonDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<IrdlCommonDeclParser::LocalAssignStatementContext>(0);
}

IrdlCommonDeclParser::SendToStatementContext* IrdlCommonDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<IrdlCommonDeclParser::SendToStatementContext>(0);
}

IrdlCommonDeclParser::BreakStatementContext* IrdlCommonDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<IrdlCommonDeclParser::BreakStatementContext>(0);
}

IrdlCommonDeclParser::ReturnStatementContext* IrdlCommonDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<IrdlCommonDeclParser::ReturnStatementContext>(0);
}


size_t IrdlCommonDeclParser::StatementBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleStatementBody;
}

void IrdlCommonDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void IrdlCommonDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

IrdlCommonDeclParser::StatementBodyContext* IrdlCommonDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 134, IrdlCommonDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(714);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(706);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(707);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(708);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(709);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(710);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(711);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(712);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(713);
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

IrdlCommonDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::FunctionCallContext* IrdlCommonDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<IrdlCommonDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleFunctionCallStatement;
}

void IrdlCommonDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void IrdlCommonDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

IrdlCommonDeclParser::FunctionCallStatementContext* IrdlCommonDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, IrdlCommonDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(716);
    functionCall();
    setState(717);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

IrdlCommonDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}

std::vector<IrdlCommonDeclParser::StatementBodyContext *> IrdlCommonDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<IrdlCommonDeclParser::StatementBodyContext>();
}

IrdlCommonDeclParser::StatementBodyContext* IrdlCommonDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::StatementBodyContext>(i);
}


size_t IrdlCommonDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleNestedStatementBody;
}

void IrdlCommonDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void IrdlCommonDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

IrdlCommonDeclParser::NestedStatementBodyContext* IrdlCommonDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 138, IrdlCommonDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(719);
    match(IrdlCommonDeclParser::LBRACE);
    setState(723);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (IrdlCommonDeclParser::DescriptionID - 3))
      | (1ULL << (IrdlCommonDeclParser::ComponentID - 3))
      | (1ULL << (IrdlCommonDeclParser::AtID - 3))
      | (1ULL << (IrdlCommonDeclParser::TimeOutID - 3))
      | (1ULL << (IrdlCommonDeclParser::MilliSekID - 3))
      | (1ULL << (IrdlCommonDeclParser::SekID - 3))
      | (1ULL << (IrdlCommonDeclParser::NameID - 3))
      | (1ULL << (IrdlCommonDeclParser::LabelID - 3))
      | (1ULL << (IrdlCommonDeclParser::EnabledID - 3))
      | (1ULL << (IrdlCommonDeclParser::TypeID - 3))
      | (1ULL << (IrdlCommonDeclParser::IntID - 3))
      | (1ULL << (IrdlCommonDeclParser::RealID - 3))
      | (1ULL << (IrdlCommonDeclParser::BoolID - 3))
      | (1ULL << (IrdlCommonDeclParser::StringID - 3))
      | (1ULL << (IrdlCommonDeclParser::ThisID - 3))
      | (1ULL << (IrdlCommonDeclParser::ReturnID - 3))
      | (1ULL << (IrdlCommonDeclParser::EnumID - 3))
      | (1ULL << (IrdlCommonDeclParser::AttributeID - 3))
      | (1ULL << (IrdlCommonDeclParser::SignalID - 3))
      | (1ULL << (IrdlCommonDeclParser::ImportID - 3))
      | (1ULL << (IrdlCommonDeclParser::FromID - 3))
      | (1ULL << (IrdlCommonDeclParser::ToID - 3))
      | (1ULL << (IrdlCommonDeclParser::SendID - 3))
      | (1ULL << (IrdlCommonDeclParser::SwitchID - 3))
      | (1ULL << (IrdlCommonDeclParser::IfID - 3))
      | (1ULL << (IrdlCommonDeclParser::BREAK - 3))
      | (1ULL << (IrdlCommonDeclParser::ID - 3)))) != 0)) {
      setState(720);
      statementBody();
      setState(725);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(726);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

IrdlCommonDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(IrdlCommonDeclParser::ReturnID, 0);
}

IrdlCommonDeclParser::OperationContext* IrdlCommonDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<IrdlCommonDeclParser::OperationContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::ReturnStatementContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::ReturnStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleReturnStatement;
}

void IrdlCommonDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void IrdlCommonDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

IrdlCommonDeclParser::ReturnStatementContext* IrdlCommonDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 140, IrdlCommonDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(728);
    match(IrdlCommonDeclParser::ReturnID);
    setState(729);
    operation();
    setState(730);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

IrdlCommonDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::BreakStatementContext::BREAK() {
  return getToken(IrdlCommonDeclParser::BREAK, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::BreakStatementContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::BreakStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleBreakStatement;
}

void IrdlCommonDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void IrdlCommonDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

IrdlCommonDeclParser::BreakStatementContext* IrdlCommonDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 142, IrdlCommonDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(732);
    match(IrdlCommonDeclParser::BREAK);
    setState(733);
    match(IrdlCommonDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

IrdlCommonDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::AtomContext* IrdlCommonDeclParser::OperationContext::atom() {
  return getRuleContext<IrdlCommonDeclParser::AtomContext>(0);
}

IrdlCommonDeclParser::OperationOptionalContext* IrdlCommonDeclParser::OperationContext::operationOptional() {
  return getRuleContext<IrdlCommonDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

IrdlCommonDeclParser::OperationContext* IrdlCommonDeclParser::OperationContext::operation() {
  return getRuleContext<IrdlCommonDeclParser::OperationContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationContext::MINUS() {
  return getToken(IrdlCommonDeclParser::MINUS, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationContext::NotIdSymbol() {
  return getToken(IrdlCommonDeclParser::NotIdSymbol, 0);
}


size_t IrdlCommonDeclParser::OperationContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleOperation;
}

void IrdlCommonDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void IrdlCommonDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

IrdlCommonDeclParser::OperationContext* IrdlCommonDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 144, IrdlCommonDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(746);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::TriggerID:
      case IrdlCommonDeclParser::MessageTrigger:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::TrueID:
      case IrdlCommonDeclParser::FalseID:
      case IrdlCommonDeclParser::INT:
      case IrdlCommonDeclParser::REAL:
      case IrdlCommonDeclParser::STRING:
      case IrdlCommonDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(735);
        atom();
        setState(736);
        operationOptional();
        break;
      }

      case IrdlCommonDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(738);
        match(IrdlCommonDeclParser::LPAREN);
        setState(739);
        operation();
        setState(740);
        match(IrdlCommonDeclParser::RPAREN);
        break;
      }

      case IrdlCommonDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(742);
        match(IrdlCommonDeclParser::MINUS);
        setState(743);
        operation();
        break;
      }

      case IrdlCommonDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(744);
        match(IrdlCommonDeclParser::NotIdSymbol);
        setState(745);
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

IrdlCommonDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::OperationContext* IrdlCommonDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<IrdlCommonDeclParser::OperationContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationOptionalContext::MULT() {
  return getToken(IrdlCommonDeclParser::MULT, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationOptionalContext::DIV() {
  return getToken(IrdlCommonDeclParser::DIV, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationOptionalContext::PLUS() {
  return getToken(IrdlCommonDeclParser::PLUS, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::OperationOptionalContext::MINUS() {
  return getToken(IrdlCommonDeclParser::MINUS, 0);
}


size_t IrdlCommonDeclParser::OperationOptionalContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleOperationOptional;
}

void IrdlCommonDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void IrdlCommonDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

IrdlCommonDeclParser::OperationOptionalContext* IrdlCommonDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 146, IrdlCommonDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(751);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::PLUS:
      case IrdlCommonDeclParser::MINUS:
      case IrdlCommonDeclParser::MULT:
      case IrdlCommonDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(748);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 81) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 81)) & ((1ULL << (IrdlCommonDeclParser::PLUS - 81))
          | (1ULL << (IrdlCommonDeclParser::MINUS - 81))
          | (1ULL << (IrdlCommonDeclParser::MULT - 81))
          | (1ULL << (IrdlCommonDeclParser::DIV - 81)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(749);
        operation();
        break;
      }

      case IrdlCommonDeclParser::NotIdSymbol:
      case IrdlCommonDeclParser::AndIdSymbol:
      case IrdlCommonDeclParser::OrIdSymbol:
      case IrdlCommonDeclParser::NotIdWord:
      case IrdlCommonDeclParser::AndIdWord:
      case IrdlCommonDeclParser::OrIdWord:
      case IrdlCommonDeclParser::ASSIGN:
      case IrdlCommonDeclParser::RPAREN:
      case IrdlCommonDeclParser::RBRACKET:
      case IrdlCommonDeclParser::LESSTHAN:
      case IrdlCommonDeclParser::GREATERTHAN:
      case IrdlCommonDeclParser::SEMI: {
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

IrdlCommonDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

IrdlCommonDeclParser::ExpressionContext* IrdlCommonDeclParser::ExpressionContext::expression() {
  return getRuleContext<IrdlCommonDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}

IrdlCommonDeclParser::ExpressionOptionalContext* IrdlCommonDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<IrdlCommonDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(IrdlCommonDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionContext::NotIdWord() {
  return getToken(IrdlCommonDeclParser::NotIdWord, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionContext::MINUS() {
  return getToken(IrdlCommonDeclParser::MINUS, 0);
}

IrdlCommonDeclParser::OperationContext* IrdlCommonDeclParser::ExpressionContext::operation() {
  return getRuleContext<IrdlCommonDeclParser::OperationContext>(0);
}


size_t IrdlCommonDeclParser::ExpressionContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleExpression;
}

void IrdlCommonDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void IrdlCommonDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

IrdlCommonDeclParser::ExpressionContext* IrdlCommonDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 148, IrdlCommonDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(767);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(753);
      match(IrdlCommonDeclParser::LPAREN);
      setState(754);
      expression();
      setState(755);
      match(IrdlCommonDeclParser::RPAREN);
      setState(756);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(758);
      match(IrdlCommonDeclParser::NotIdSymbol);
      setState(759);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(760);
      match(IrdlCommonDeclParser::NotIdWord);
      setState(761);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(762);
      match(IrdlCommonDeclParser::MINUS);
      setState(763);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(764);
      operation();
      setState(765);
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

IrdlCommonDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::ExpressionContext* IrdlCommonDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<IrdlCommonDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(IrdlCommonDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(IrdlCommonDeclParser::OrIdWord, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(IrdlCommonDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(IrdlCommonDeclParser::AndIdWord, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(IrdlCommonDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> IrdlCommonDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(IrdlCommonDeclParser::ASSIGN);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(IrdlCommonDeclParser::ASSIGN, i);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(IrdlCommonDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(IrdlCommonDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(IrdlCommonDeclParser::GREATERTHAN, 0);
}


size_t IrdlCommonDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleExpressionOptional;
}

void IrdlCommonDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void IrdlCommonDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

IrdlCommonDeclParser::ExpressionOptionalContext* IrdlCommonDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 150, IrdlCommonDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(792);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::NotIdSymbol:
      case IrdlCommonDeclParser::AndIdSymbol:
      case IrdlCommonDeclParser::OrIdSymbol:
      case IrdlCommonDeclParser::NotIdWord:
      case IrdlCommonDeclParser::AndIdWord:
      case IrdlCommonDeclParser::OrIdWord:
      case IrdlCommonDeclParser::ASSIGN:
      case IrdlCommonDeclParser::LESSTHAN:
      case IrdlCommonDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(788);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case IrdlCommonDeclParser::OrIdSymbol: {
            setState(769);
            match(IrdlCommonDeclParser::OrIdSymbol);
            break;
          }

          case IrdlCommonDeclParser::OrIdWord: {
            setState(770);
            match(IrdlCommonDeclParser::OrIdWord);
            break;
          }

          case IrdlCommonDeclParser::AndIdSymbol: {
            setState(771);
            match(IrdlCommonDeclParser::AndIdSymbol);
            break;
          }

          case IrdlCommonDeclParser::AndIdWord: {
            setState(772);
            match(IrdlCommonDeclParser::AndIdWord);
            break;
          }

          case IrdlCommonDeclParser::ASSIGN: {
            setState(773);
            match(IrdlCommonDeclParser::ASSIGN);
            setState(774);
            match(IrdlCommonDeclParser::ASSIGN);
            break;
          }

          case IrdlCommonDeclParser::NotIdSymbol: {
            setState(775);
            match(IrdlCommonDeclParser::NotIdSymbol);
            setState(776);
            match(IrdlCommonDeclParser::ASSIGN);
            break;
          }

          case IrdlCommonDeclParser::NotIdWord: {
            setState(777);
            match(IrdlCommonDeclParser::NotIdWord);
            break;
          }

          case IrdlCommonDeclParser::LESSTHAN: {
            setState(778);
            match(IrdlCommonDeclParser::LESSTHAN);
            setState(781);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case IrdlCommonDeclParser::ASSIGN: {
                setState(779);
                match(IrdlCommonDeclParser::ASSIGN);
                break;
              }

              case IrdlCommonDeclParser::DescriptionID:
              case IrdlCommonDeclParser::ComponentID:
              case IrdlCommonDeclParser::AtID:
              case IrdlCommonDeclParser::TimeOutID:
              case IrdlCommonDeclParser::MilliSekID:
              case IrdlCommonDeclParser::SekID:
              case IrdlCommonDeclParser::NameID:
              case IrdlCommonDeclParser::LabelID:
              case IrdlCommonDeclParser::EnabledID:
              case IrdlCommonDeclParser::TypeID:
              case IrdlCommonDeclParser::TriggerID:
              case IrdlCommonDeclParser::MessageTrigger:
              case IrdlCommonDeclParser::ThisID:
              case IrdlCommonDeclParser::AttributeID:
              case IrdlCommonDeclParser::SignalID:
              case IrdlCommonDeclParser::ImportID:
              case IrdlCommonDeclParser::FromID:
              case IrdlCommonDeclParser::ToID:
              case IrdlCommonDeclParser::SendID:
              case IrdlCommonDeclParser::NotIdSymbol:
              case IrdlCommonDeclParser::NotIdWord:
              case IrdlCommonDeclParser::TrueID:
              case IrdlCommonDeclParser::FalseID:
              case IrdlCommonDeclParser::INT:
              case IrdlCommonDeclParser::REAL:
              case IrdlCommonDeclParser::STRING:
              case IrdlCommonDeclParser::ID:
              case IrdlCommonDeclParser::LPAREN:
              case IrdlCommonDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case IrdlCommonDeclParser::GREATERTHAN: {
            setState(783);
            match(IrdlCommonDeclParser::GREATERTHAN);
            setState(786);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case IrdlCommonDeclParser::ASSIGN: {
                setState(784);
                match(IrdlCommonDeclParser::ASSIGN);
                break;
              }

              case IrdlCommonDeclParser::DescriptionID:
              case IrdlCommonDeclParser::ComponentID:
              case IrdlCommonDeclParser::AtID:
              case IrdlCommonDeclParser::TimeOutID:
              case IrdlCommonDeclParser::MilliSekID:
              case IrdlCommonDeclParser::SekID:
              case IrdlCommonDeclParser::NameID:
              case IrdlCommonDeclParser::LabelID:
              case IrdlCommonDeclParser::EnabledID:
              case IrdlCommonDeclParser::TypeID:
              case IrdlCommonDeclParser::TriggerID:
              case IrdlCommonDeclParser::MessageTrigger:
              case IrdlCommonDeclParser::ThisID:
              case IrdlCommonDeclParser::AttributeID:
              case IrdlCommonDeclParser::SignalID:
              case IrdlCommonDeclParser::ImportID:
              case IrdlCommonDeclParser::FromID:
              case IrdlCommonDeclParser::ToID:
              case IrdlCommonDeclParser::SendID:
              case IrdlCommonDeclParser::NotIdSymbol:
              case IrdlCommonDeclParser::NotIdWord:
              case IrdlCommonDeclParser::TrueID:
              case IrdlCommonDeclParser::FalseID:
              case IrdlCommonDeclParser::INT:
              case IrdlCommonDeclParser::REAL:
              case IrdlCommonDeclParser::STRING:
              case IrdlCommonDeclParser::ID:
              case IrdlCommonDeclParser::LPAREN:
              case IrdlCommonDeclParser::MINUS: {
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
        setState(790);
        expression();
        break;
      }

      case IrdlCommonDeclParser::RPAREN:
      case IrdlCommonDeclParser::RBRACKET:
      case IrdlCommonDeclParser::SEMI: {
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

IrdlCommonDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IrdlCommonDeclParser::IfStatementContext* IrdlCommonDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<IrdlCommonDeclParser::IfStatementContext>(0);
}

IrdlCommonDeclParser::ElseStatementContext* IrdlCommonDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<IrdlCommonDeclParser::ElseStatementContext>(0);
}


size_t IrdlCommonDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleConditionalStatement;
}

void IrdlCommonDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void IrdlCommonDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

IrdlCommonDeclParser::ConditionalStatementContext* IrdlCommonDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 152, IrdlCommonDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(794);
    ifStatement();
    setState(797);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      setState(795);
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

IrdlCommonDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::IfStatementContext::IfID() {
  return getToken(IrdlCommonDeclParser::IfID, 0);
}

IrdlCommonDeclParser::IfEuTContext* IrdlCommonDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<IrdlCommonDeclParser::IfEuTContext>(0);
}

IrdlCommonDeclParser::StatementDeclContext* IrdlCommonDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<IrdlCommonDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::IfStatementContext::SEMI() {
  return getToken(IrdlCommonDeclParser::SEMI, 0);
}


size_t IrdlCommonDeclParser::IfStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleIfStatement;
}

void IrdlCommonDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void IrdlCommonDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

IrdlCommonDeclParser::IfStatementContext* IrdlCommonDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, IrdlCommonDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(799);
    match(IrdlCommonDeclParser::IfID);
    setState(800);
    ifEuT();
    setState(803);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::IntID:
      case IrdlCommonDeclParser::RealID:
      case IrdlCommonDeclParser::BoolID:
      case IrdlCommonDeclParser::StringID:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::ReturnID:
      case IrdlCommonDeclParser::EnumID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::SwitchID:
      case IrdlCommonDeclParser::IfID:
      case IrdlCommonDeclParser::BREAK:
      case IrdlCommonDeclParser::ID:
      case IrdlCommonDeclParser::LBRACE: {
        setState(801);
        statementDecl();
        break;
      }

      case IrdlCommonDeclParser::SEMI: {
        setState(802);
        match(IrdlCommonDeclParser::SEMI);
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

IrdlCommonDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::IfEuTContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

IrdlCommonDeclParser::ExpressionContext* IrdlCommonDeclParser::IfEuTContext::expression() {
  return getRuleContext<IrdlCommonDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::IfEuTContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}


size_t IrdlCommonDeclParser::IfEuTContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleIfEuT;
}

void IrdlCommonDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void IrdlCommonDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

IrdlCommonDeclParser::IfEuTContext* IrdlCommonDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 156, IrdlCommonDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(805);
    match(IrdlCommonDeclParser::LPAREN);
    setState(806);
    expression();
    setState(807);
    match(IrdlCommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

IrdlCommonDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::ElseStatementContext::ElseID() {
  return getToken(IrdlCommonDeclParser::ElseID, 0);
}

IrdlCommonDeclParser::StatementDeclContext* IrdlCommonDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<IrdlCommonDeclParser::StatementDeclContext>(0);
}


size_t IrdlCommonDeclParser::ElseStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleElseStatement;
}

void IrdlCommonDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void IrdlCommonDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

IrdlCommonDeclParser::ElseStatementContext* IrdlCommonDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 158, IrdlCommonDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(809);
    match(IrdlCommonDeclParser::ElseID);
    setState(810);
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

IrdlCommonDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(IrdlCommonDeclParser::SwitchID, 0);
}

IrdlCommonDeclParser::SwitchPuTContext* IrdlCommonDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<IrdlCommonDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(IrdlCommonDeclParser::LBRACE, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(IrdlCommonDeclParser::RBRACE, 0);
}

IrdlCommonDeclParser::DefaultStatementContext* IrdlCommonDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<IrdlCommonDeclParser::DefaultStatementContext>(0);
}

std::vector<IrdlCommonDeclParser::CaseStatementContext *> IrdlCommonDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<IrdlCommonDeclParser::CaseStatementContext>();
}

IrdlCommonDeclParser::CaseStatementContext* IrdlCommonDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::CaseStatementContext>(i);
}


size_t IrdlCommonDeclParser::SwitchStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSwitchStatement;
}

void IrdlCommonDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void IrdlCommonDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

IrdlCommonDeclParser::SwitchStatementContext* IrdlCommonDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 160, IrdlCommonDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(812);
    match(IrdlCommonDeclParser::SwitchID);
    setState(813);
    switchPuT();
    setState(814);
    match(IrdlCommonDeclParser::LBRACE);
    setState(818);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IrdlCommonDeclParser::CaseID) {
      setState(815);
      caseStatement();
      setState(820);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(823);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::DefaultID: {
        setState(821);
        defaultStatement();
        break;
      }

      case IrdlCommonDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(825);
    match(IrdlCommonDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

IrdlCommonDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(IrdlCommonDeclParser::LPAREN, 0);
}

IrdlCommonDeclParser::ContextIDContext* IrdlCommonDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<IrdlCommonDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(IrdlCommonDeclParser::RPAREN, 0);
}


size_t IrdlCommonDeclParser::SwitchPuTContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleSwitchPuT;
}

void IrdlCommonDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void IrdlCommonDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

IrdlCommonDeclParser::SwitchPuTContext* IrdlCommonDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 162, IrdlCommonDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(827);
    match(IrdlCommonDeclParser::LPAREN);
    setState(828);
    contextID();
    setState(829);
    match(IrdlCommonDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

IrdlCommonDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::CaseStatementContext::CaseID() {
  return getToken(IrdlCommonDeclParser::CaseID, 0);
}

IrdlCommonDeclParser::LiteralValueContext* IrdlCommonDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<IrdlCommonDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* IrdlCommonDeclParser::CaseStatementContext::COLON() {
  return getToken(IrdlCommonDeclParser::COLON, 0);
}

IrdlCommonDeclParser::NestedStatementBodyContext* IrdlCommonDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<IrdlCommonDeclParser::NestedStatementBodyContext>(0);
}

std::vector<IrdlCommonDeclParser::StatementBodyContext *> IrdlCommonDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<IrdlCommonDeclParser::StatementBodyContext>();
}

IrdlCommonDeclParser::StatementBodyContext* IrdlCommonDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::StatementBodyContext>(i);
}


size_t IrdlCommonDeclParser::CaseStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleCaseStatement;
}

void IrdlCommonDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void IrdlCommonDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

IrdlCommonDeclParser::CaseStatementContext* IrdlCommonDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 164, IrdlCommonDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(831);
    match(IrdlCommonDeclParser::CaseID);
    setState(832);
    literalValue();
    setState(833);
    match(IrdlCommonDeclParser::COLON);
    setState(841);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::LBRACE: {
        setState(834);
        nestedStatementBody();
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::IntID:
      case IrdlCommonDeclParser::RealID:
      case IrdlCommonDeclParser::BoolID:
      case IrdlCommonDeclParser::StringID:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::ReturnID:
      case IrdlCommonDeclParser::EnumID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::SwitchID:
      case IrdlCommonDeclParser::CaseID:
      case IrdlCommonDeclParser::DefaultID:
      case IrdlCommonDeclParser::IfID:
      case IrdlCommonDeclParser::BREAK:
      case IrdlCommonDeclParser::ID:
      case IrdlCommonDeclParser::RBRACE: {
        setState(838);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 3) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 3)) & ((1ULL << (IrdlCommonDeclParser::DescriptionID - 3))
          | (1ULL << (IrdlCommonDeclParser::ComponentID - 3))
          | (1ULL << (IrdlCommonDeclParser::AtID - 3))
          | (1ULL << (IrdlCommonDeclParser::TimeOutID - 3))
          | (1ULL << (IrdlCommonDeclParser::MilliSekID - 3))
          | (1ULL << (IrdlCommonDeclParser::SekID - 3))
          | (1ULL << (IrdlCommonDeclParser::NameID - 3))
          | (1ULL << (IrdlCommonDeclParser::LabelID - 3))
          | (1ULL << (IrdlCommonDeclParser::EnabledID - 3))
          | (1ULL << (IrdlCommonDeclParser::TypeID - 3))
          | (1ULL << (IrdlCommonDeclParser::IntID - 3))
          | (1ULL << (IrdlCommonDeclParser::RealID - 3))
          | (1ULL << (IrdlCommonDeclParser::BoolID - 3))
          | (1ULL << (IrdlCommonDeclParser::StringID - 3))
          | (1ULL << (IrdlCommonDeclParser::ThisID - 3))
          | (1ULL << (IrdlCommonDeclParser::ReturnID - 3))
          | (1ULL << (IrdlCommonDeclParser::EnumID - 3))
          | (1ULL << (IrdlCommonDeclParser::AttributeID - 3))
          | (1ULL << (IrdlCommonDeclParser::SignalID - 3))
          | (1ULL << (IrdlCommonDeclParser::ImportID - 3))
          | (1ULL << (IrdlCommonDeclParser::FromID - 3))
          | (1ULL << (IrdlCommonDeclParser::ToID - 3))
          | (1ULL << (IrdlCommonDeclParser::SendID - 3))
          | (1ULL << (IrdlCommonDeclParser::SwitchID - 3))
          | (1ULL << (IrdlCommonDeclParser::IfID - 3))
          | (1ULL << (IrdlCommonDeclParser::BREAK - 3))
          | (1ULL << (IrdlCommonDeclParser::ID - 3)))) != 0)) {
          setState(835);
          statementBody();
          setState(840);
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

IrdlCommonDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IrdlCommonDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(IrdlCommonDeclParser::DefaultID, 0);
}

tree::TerminalNode* IrdlCommonDeclParser::DefaultStatementContext::COLON() {
  return getToken(IrdlCommonDeclParser::COLON, 0);
}

IrdlCommonDeclParser::NestedStatementBodyContext* IrdlCommonDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<IrdlCommonDeclParser::NestedStatementBodyContext>(0);
}

std::vector<IrdlCommonDeclParser::StatementBodyContext *> IrdlCommonDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<IrdlCommonDeclParser::StatementBodyContext>();
}

IrdlCommonDeclParser::StatementBodyContext* IrdlCommonDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<IrdlCommonDeclParser::StatementBodyContext>(i);
}


size_t IrdlCommonDeclParser::DefaultStatementContext::getRuleIndex() const {
  return IrdlCommonDeclParser::RuleDefaultStatement;
}

void IrdlCommonDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void IrdlCommonDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IrdlCommonDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

IrdlCommonDeclParser::DefaultStatementContext* IrdlCommonDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 166, IrdlCommonDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(843);
    match(IrdlCommonDeclParser::DefaultID);
    setState(844);
    match(IrdlCommonDeclParser::COLON);
    setState(852);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IrdlCommonDeclParser::LBRACE: {
        setState(845);
        nestedStatementBody();
        break;
      }

      case IrdlCommonDeclParser::DescriptionID:
      case IrdlCommonDeclParser::ComponentID:
      case IrdlCommonDeclParser::AtID:
      case IrdlCommonDeclParser::TimeOutID:
      case IrdlCommonDeclParser::MilliSekID:
      case IrdlCommonDeclParser::SekID:
      case IrdlCommonDeclParser::NameID:
      case IrdlCommonDeclParser::LabelID:
      case IrdlCommonDeclParser::EnabledID:
      case IrdlCommonDeclParser::TypeID:
      case IrdlCommonDeclParser::IntID:
      case IrdlCommonDeclParser::RealID:
      case IrdlCommonDeclParser::BoolID:
      case IrdlCommonDeclParser::StringID:
      case IrdlCommonDeclParser::ThisID:
      case IrdlCommonDeclParser::ReturnID:
      case IrdlCommonDeclParser::EnumID:
      case IrdlCommonDeclParser::AttributeID:
      case IrdlCommonDeclParser::SignalID:
      case IrdlCommonDeclParser::ImportID:
      case IrdlCommonDeclParser::FromID:
      case IrdlCommonDeclParser::ToID:
      case IrdlCommonDeclParser::SendID:
      case IrdlCommonDeclParser::SwitchID:
      case IrdlCommonDeclParser::IfID:
      case IrdlCommonDeclParser::BREAK:
      case IrdlCommonDeclParser::ID:
      case IrdlCommonDeclParser::RBRACE: {
        setState(849);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 3) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 3)) & ((1ULL << (IrdlCommonDeclParser::DescriptionID - 3))
          | (1ULL << (IrdlCommonDeclParser::ComponentID - 3))
          | (1ULL << (IrdlCommonDeclParser::AtID - 3))
          | (1ULL << (IrdlCommonDeclParser::TimeOutID - 3))
          | (1ULL << (IrdlCommonDeclParser::MilliSekID - 3))
          | (1ULL << (IrdlCommonDeclParser::SekID - 3))
          | (1ULL << (IrdlCommonDeclParser::NameID - 3))
          | (1ULL << (IrdlCommonDeclParser::LabelID - 3))
          | (1ULL << (IrdlCommonDeclParser::EnabledID - 3))
          | (1ULL << (IrdlCommonDeclParser::TypeID - 3))
          | (1ULL << (IrdlCommonDeclParser::IntID - 3))
          | (1ULL << (IrdlCommonDeclParser::RealID - 3))
          | (1ULL << (IrdlCommonDeclParser::BoolID - 3))
          | (1ULL << (IrdlCommonDeclParser::StringID - 3))
          | (1ULL << (IrdlCommonDeclParser::ThisID - 3))
          | (1ULL << (IrdlCommonDeclParser::ReturnID - 3))
          | (1ULL << (IrdlCommonDeclParser::EnumID - 3))
          | (1ULL << (IrdlCommonDeclParser::AttributeID - 3))
          | (1ULL << (IrdlCommonDeclParser::SignalID - 3))
          | (1ULL << (IrdlCommonDeclParser::ImportID - 3))
          | (1ULL << (IrdlCommonDeclParser::FromID - 3))
          | (1ULL << (IrdlCommonDeclParser::ToID - 3))
          | (1ULL << (IrdlCommonDeclParser::SendID - 3))
          | (1ULL << (IrdlCommonDeclParser::SwitchID - 3))
          | (1ULL << (IrdlCommonDeclParser::IfID - 3))
          | (1ULL << (IrdlCommonDeclParser::BREAK - 3))
          | (1ULL << (IrdlCommonDeclParser::ID - 3)))) != 0)) {
          setState(846);
          statementBody();
          setState(851);
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
std::vector<dfa::DFA> IrdlCommonDeclParser::_decisionToDFA;
atn::PredictionContextCache IrdlCommonDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN IrdlCommonDeclParser::_atn;
std::vector<uint16_t> IrdlCommonDeclParser::_serializedATN;

std::vector<std::string> IrdlCommonDeclParser::_ruleNames = {
  "irdlCommonDecl", "timerNameID", "attributeAssignStatement", "atom", "irdlDecl", 
  "requirementBody", "aliasDef", "declarations", "componentDecl", "componentBody", 
  "actorDecl", "actorBody", "descriptionDecl", "sequenceDecl", "stateDecl", 
  "lifelineList", "lifelineListOptional", "messageSignal", "messageSignalBody", 
  "messageSignalBodyOptional", "messageDecl", "checkDecl", "checkDeclBody", 
  "timerDecl", "attributeAssign", "timeOutDecl", "altDecl", "altBody", "altBodyOptional", 
  "durationDecl", "contextID", "componentIdPath", "signalIdPath", "attributeIdPath", 
  "signalSend", "commonDecl", "importPathDecl", "importPathBody", "importFileBody", 
  "importAs", "typeDefDecl", "typeDecl", "intTypeDecl", "realTypeDecl", 
  "enumTypeDecl", "attributeDecl", "literalValue", "signalParamName", "attributeName", 
  "toPortName", "localAssignStatement", "sendToStatement", "singleAssignment", 
  "multiAssignment", "signalDecl", "paramDecl", "functionDecl", "functionParameters", 
  "functionCall", "functionCallBody", "functionCallBodyOptional", "triggerDecl", 
  "thisDecl", "portDecl", "nameDecl", "idPath", "statementDecl", "statementBody", 
  "functionCallStatement", "nestedStatementBody", "returnStatement", "breakStatement", 
  "operation", "operationOptional", "expression", "expressionOptional", 
  "conditionalStatement", "ifStatement", "ifEuT", "elseStatement", "switchStatement", 
  "switchPuT", "caseStatement", "defaultStatement"
};

std::vector<std::string> IrdlCommonDeclParser::_literalNames = {
  "", "'use'", "'Requirement'", "'description'", "'Component'", "'Actor'", 
  "'State'", "'at'", "'all'", "", "", "'Timer'", "'timeout'", "'Alt'", "'Duration'", 
  "'ms'", "'s'", "", "'name'", "'label'", "'enabled'", "'Type'", "'int'", 
  "'real'", "'bool'", "'string'", "'trigger'", "'msg'", "'this'", "'return'", 
  "'SignalTransition'", "'TimeoutTransition'", "'enum'", "'Declaration'", 
  "'Attribute'", "'Signal'", "'Port'", "'import'", "'from'", "'to'", "'send'", 
  "'Function'", "'switch'", "'case'", "'default'", "'if'", "'else'", "'as'", 
  "'!'", "'&&'", "'||'", "'not'", "'and'", "'or'", "'true'", "'false'", 
  "'break'", "'='", "'<->'", "'->'", "'<-'", "'..'", "", "", "", "", "", 
  "", "'('", "')'", "'{'", "'}'", "'['", "']'", "'<'", "'>'", "':'", "';'", 
  "','", "'_'", "'.'", "'+'", "'-'", "'*'", "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> IrdlCommonDeclParser::_symbolicNames = {
  "", "UseID", "RequirementID", "DescriptionID", "ComponentID", "ActorID", 
  "StateID", "AtID", "AllID", "MessageID", "CheckID", "TimerID", "TimeOutID", 
  "AltID", "DurationID", "MilliSekID", "SekID", "IGNORE_NEWLINE", "NameID", 
  "LabelID", "EnabledID", "TypeID", "IntID", "RealID", "BoolID", "StringID", 
  "TriggerID", "MessageTrigger", "ThisID", "ReturnID", "SignalTransitionID", 
  "TimeoutTransitionID", "EnumID", "DeclarationID", "AttributeID", "SignalID", 
  "PortID", "ImportID", "FromID", "ToID", "SendID", "FunctionID", "SwitchID", 
  "CaseID", "DefaultID", "IfID", "ElseID", "AsID", "NotIdSymbol", "AndIdSymbol", 
  "OrIdSymbol", "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", "FalseID", 
  "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", "LeftArrow", "RANGE", 
  "INT", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", "LPAREN", "RPAREN", 
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", 
  "COLON", "SEMI", "COMMA", "UNDER", "DOT", "PLUS", "MINUS", "MULT", "DIV", 
  "PIPE", "REF", "CONST", "NEWLINE", "WS"
};

dfa::Vocabulary IrdlCommonDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> IrdlCommonDeclParser::_tokenNames;

IrdlCommonDeclParser::Initializer::Initializer() {
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
    0x3, 0x5b, 0x359, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xb0, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0xb3, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xbc, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xcc, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0xf8, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x102, 0xa, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x106, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x109, 
    0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x113, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0x117, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x11a, 0xb, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x137, 0xa, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x143, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x148, 0xa, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x14e, 0xa, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x156, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 
    0x15, 0x15d, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 
    0x18, 0x176, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
    0x17b, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x180, 
    0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x193, 
    0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x5, 0x1d, 0x1a2, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
    0x1e, 0x1ad, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x1bd, 0xa, 0x21, 
    0xc, 0x21, 0xe, 0x21, 0x1c0, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x7, 0x22, 0x1c5, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x1c8, 0xb, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x1ce, 0xa, 0x23, 
    0xc, 0x23, 0xe, 0x23, 0x1d1, 0xb, 0x23, 0x5, 0x23, 0x1d3, 0xa, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x7, 0x25, 0x1dd, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x1e0, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 
    0x1e6, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x1f9, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1fe, 
    0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 
    0x20b, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x214, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x21d, 
    0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 
    0x2e, 0x224, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x227, 0xb, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x230, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x23a, 0xa, 0x30, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x241, 
    0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x24d, 
    0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x35, 0x5, 0x35, 0x255, 0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 
    0x3, 0x36, 0x5, 0x36, 0x25b, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 
    0x25f, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x262, 0xb, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x7, 0x38, 0x26c, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x26f, 0xb, 
    0x38, 0x3, 0x38, 0x5, 0x38, 0x272, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x276, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x5, 0x3a, 0x283, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x28b, 0xa, 0x3b, 0xc, 0x3b, 
    0xe, 0x3b, 0x28e, 0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 
    0x3d, 0x29a, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x2a1, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x7, 0x41, 0x2ad, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x2b0, 0xb, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x2bc, 0xa, 0x43, 
    0xc, 0x43, 0xe, 0x43, 0x2bf, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 
    0x2c3, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x2cd, 0xa, 0x45, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x2d4, 0xa, 0x47, 
    0xc, 0x47, 0xe, 0x47, 0x2d7, 0xb, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x2ed, 0xa, 0x4a, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x2f2, 0xa, 0x4b, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
    0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x5, 0x4c, 0x302, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 
    0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x310, 0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
    0x3, 0x4d, 0x5, 0x4d, 0x315, 0xa, 0x4d, 0x5, 0x4d, 0x317, 0xa, 0x4d, 
    0x3, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x31b, 0xa, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x5, 0x4e, 0x320, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x5, 0x4f, 0x326, 0xa, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 
    0x52, 0x3, 0x52, 0x7, 0x52, 0x333, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 
    0x336, 0xb, 0x52, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x33a, 0xa, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 
    0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x7, 0x54, 0x347, 
    0xa, 0x54, 0xc, 0x54, 0xe, 0x54, 0x34a, 0xb, 0x54, 0x5, 0x54, 0x34c, 
    0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x352, 
    0xa, 0x55, 0xc, 0x55, 0xe, 0x55, 0x355, 0xb, 0x55, 0x5, 0x55, 0x357, 
    0xa, 0x55, 0x3, 0x55, 0x2, 0x2, 0x56, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 
    0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
    0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
    0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 
    0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0x2, 0x7, 0x3, 0x2, 0x40, 0x41, 
    0x3, 0x2, 0x11, 0x12, 0xa, 0x2, 0x5, 0x6, 0x9, 0x9, 0xe, 0xe, 0x11, 
    0x12, 0x14, 0x17, 0x24, 0x25, 0x27, 0x2a, 0x43, 0x43, 0x3, 0x2, 0x1c, 
    0x1d, 0x3, 0x2, 0x53, 0x56, 0x2, 0x37c, 0x2, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x6, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x8, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x10, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x14, 0xfe, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x18, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x11b, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x136, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x138, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x142, 0x3, 0x2, 0x2, 0x2, 0x22, 0x147, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x149, 0x3, 0x2, 0x2, 0x2, 0x26, 0x155, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x15e, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x168, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x172, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x183, 0x3, 0x2, 0x2, 0x2, 0x32, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x194, 0x3, 0x2, 0x2, 0x2, 0x36, 0x199, 0x3, 0x2, 0x2, 0x2, 0x38, 0x19e, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1ae, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1b9, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1d2, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1de, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x1f8, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1ff, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x56, 0x20c, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x215, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x21e, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x239, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x62, 0x240, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x244, 0x3, 0x2, 0x2, 0x2, 0x66, 0x247, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x250, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x25c, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x265, 0x3, 0x2, 0x2, 0x2, 0x70, 0x279, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x74, 0x287, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x78, 0x299, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x2a2, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x80, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x2b3, 0x3, 0x2, 0x2, 0x2, 0x84, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x86, 0x2c2, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2ce, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x2da, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x92, 0x2ec, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x96, 0x301, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x321, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x327, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x32b, 
    0x3, 0x2, 0x2, 0x2, 0xa2, 0x32e, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x33d, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0x341, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x34d, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xb0, 0x5, 0x52, 0x2a, 0x2, 0xab, 0xb0, 0x5, 0x5c, 0x2f, 
    0x2, 0xac, 0xb0, 0x5, 0x6e, 0x38, 0x2, 0xad, 0xb0, 0x5, 0x16, 0xc, 0x2, 
    0xae, 0xb0, 0x5, 0x12, 0xa, 0x2, 0xaf, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0x3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xb5, 0x5, 0x3e, 0x20, 0x2, 0xb5, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb7, 0x5, 0x44, 0x23, 0x2, 0xb7, 0xbb, 0x7, 0x3b, 0x2, 0x2, 0xb8, 
    0xbc, 0x5, 0x5e, 0x30, 0x2, 0xb9, 0xbc, 0x5, 0x60, 0x31, 0x2, 0xba, 
    0xbc, 0x5, 0x44, 0x23, 0x2, 0xbb, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb9, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x4f, 0x2, 0x2, 0xbe, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xcc, 0x5, 0x5e, 0x30, 0x2, 0xc0, 0xcc, 0x5, 0x60, 0x31, 
    0x2, 0xc1, 0xc2, 0x7, 0x1e, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x52, 0x2, 0x2, 
    0xc3, 0xcc, 0x5, 0x3e, 0x20, 0x2, 0xc4, 0xcc, 0x5, 0x44, 0x23, 0x2, 
    0xc5, 0xc6, 0x5, 0x4, 0x3, 0x2, 0xc6, 0xc7, 0x7, 0x52, 0x2, 0x2, 0xc7, 
    0xc8, 0x7, 0xe, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x46, 0x2, 0x2, 0xc9, 0xca, 
    0x7, 0x47, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xbf, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc5, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0x9, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x4a, 0x26, 0x2, 
    0xce, 0xcf, 0x7, 0x4, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x48, 0x2, 0x2, 0xd0, 
    0xd1, 0x5, 0xc, 0x7, 0x2, 0xd1, 0xd2, 0x7, 0x49, 0x2, 0x2, 0xd2, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x23, 0x2, 0x2, 0xd4, 0xd5, 0x7, 
    0x48, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x82, 0x42, 0x2, 0xd6, 0xd7, 0x5, 0x10, 
    0x9, 0x2, 0xd7, 0xd8, 0x7, 0x49, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xda, 0x5, 0x1c, 0xf, 0x2, 0xda, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xdb, 0xdc, 0x7, 0x3, 0x2, 0x2, 0xdc, 0xdd, 0x5, 0x40, 0x21, 0x2, 0xdd, 
    0xde, 0x7, 0x31, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x3e, 0x20, 0x2, 0xdf, 0xe0, 
    0x7, 0x4f, 0x2, 0x2, 0xe0, 0xf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x5, 
    0x5c, 0x2f, 0x2, 0xe2, 0xe3, 0x5, 0x10, 0x9, 0x2, 0xe3, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe5, 0x5, 0x52, 0x2a, 0x2, 0xe5, 0xe6, 0x5, 0x10, 0x9, 
    0x2, 0xe6, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x6e, 0x38, 0x2, 
    0xe8, 0xe9, 0x5, 0x10, 0x9, 0x2, 0xe9, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0xeb, 0x5, 0xe, 0x8, 0x2, 0xeb, 0xec, 0x5, 0x10, 0x9, 0x2, 0xec, 0xf8, 
    0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x5, 0x12, 0xa, 0x2, 0xee, 0xef, 0x5, 
    0x10, 0x9, 0x2, 0xef, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x16, 
    0xc, 0x2, 0xf1, 0xf2, 0x5, 0x10, 0x9, 0x2, 0xf2, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf4, 0x5, 0x1a, 0xe, 0x2, 0xf4, 0xf5, 0x5, 0x10, 0x9, 0x2, 
    0xf5, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xe7, 
    0x3, 0x2, 0x2, 0x2, 0xf7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xf7, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf3, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xfa, 0x7, 0x6, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x48, 0x2, 0x2, 
    0xfb, 0xfc, 0x5, 0x14, 0xb, 0x2, 0xfc, 0xfd, 0x7, 0x49, 0x2, 0x2, 0xfd, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x101, 0x5, 0x82, 0x42, 0x2, 0xff, 0x102, 
    0x5, 0x1a, 0xe, 0x2, 0x100, 0x102, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0x107, 0x5, 0x48, 0x25, 0x2, 0x104, 0x106, 
    0x5, 0x80, 0x41, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x106, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x15, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x7, 0x2, 0x2, 0x10b, 0x10c, 0x7, 
    0x48, 0x2, 0x2, 0x10c, 0x10d, 0x5, 0x18, 0xd, 0x2, 0x10d, 0x10e, 0x7, 
    0x49, 0x2, 0x2, 0x10e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x5, 
    0x82, 0x42, 0x2, 0x110, 0x113, 0x5, 0x1a, 0xe, 0x2, 0x111, 0x113, 0x3, 
    0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x118, 0x5, 
    0x48, 0x25, 0x2, 0x115, 0x117, 0x5, 0x80, 0x41, 0x2, 0x116, 0x115, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 
    0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x5, 
    0x2, 0x2, 0x11c, 0x11d, 0x7, 0x4e, 0x2, 0x2, 0x11d, 0x11e, 0x7, 0x42, 
    0x2, 0x2, 0x11e, 0x11f, 0x7, 0x4f, 0x2, 0x2, 0x11f, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x121, 0x5, 0x1e, 0x10, 0x2, 0x121, 0x122, 0x5, 0x1c, 
    0xf, 0x2, 0x122, 0x137, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x5, 0x2a, 
    0x16, 0x2, 0x124, 0x125, 0x5, 0x1c, 0xf, 0x2, 0x125, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x126, 0x127, 0x5, 0x2c, 0x17, 0x2, 0x127, 0x128, 0x5, 0x1c, 
    0xf, 0x2, 0x128, 0x137, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x36, 
    0x1c, 0x2, 0x12a, 0x12b, 0x5, 0x1c, 0xf, 0x2, 0x12b, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x12d, 0x5, 0x30, 0x19, 0x2, 0x12d, 0x12e, 0x5, 0x1c, 
    0xf, 0x2, 0x12e, 0x137, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x3c, 
    0x1f, 0x2, 0x130, 0x131, 0x5, 0x1c, 0xf, 0x2, 0x131, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x133, 0x5, 0x6, 0x4, 0x2, 0x133, 0x134, 0x5, 0x1c, 
    0xf, 0x2, 0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x120, 0x3, 0x2, 0x2, 0x2, 0x136, 0x123, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x126, 0x3, 0x2, 0x2, 0x2, 0x136, 0x129, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x136, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x132, 0x3, 0x2, 0x2, 0x2, 0x136, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x7, 0x8, 0x2, 
    0x2, 0x139, 0x13a, 0x5, 0x3e, 0x20, 0x2, 0x13a, 0x13b, 0x7, 0x9, 0x2, 
    0x2, 0x13b, 0x13c, 0x5, 0x20, 0x11, 0x2, 0x13c, 0x13d, 0x7, 0x4f, 0x2, 
    0x2, 0x13d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x143, 0x7, 0xa, 0x2, 0x2, 
    0x13f, 0x140, 0x5, 0x40, 0x21, 0x2, 0x140, 0x141, 0x5, 0x22, 0x12, 0x2, 
    0x141, 0x143, 0x3, 0x2, 0x2, 0x2, 0x142, 0x13e, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x143, 0x21, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x145, 0x7, 0x50, 0x2, 0x2, 0x145, 0x148, 0x5, 0x20, 0x11, 0x2, 0x146, 
    0x148, 0x3, 0x2, 0x2, 0x2, 0x147, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x23, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 
    0x5, 0x42, 0x22, 0x2, 0x14a, 0x14d, 0x7, 0x46, 0x2, 0x2, 0x14b, 0x14e, 
    0x5, 0x26, 0x14, 0x2, 0x14c, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 
    0x3, 0x2, 0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 
    0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x7, 0x47, 0x2, 0x2, 0x150, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x151, 0x156, 0x5, 0x5e, 0x30, 0x2, 0x152, 0x156, 
    0x5, 0x60, 0x31, 0x2, 0x153, 0x156, 0x5, 0x44, 0x23, 0x2, 0x154, 0x156, 
    0x7, 0x55, 0x2, 0x2, 0x155, 0x151, 0x3, 0x2, 0x2, 0x2, 0x155, 0x152, 
    0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x154, 
    0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 
    0x5, 0x28, 0x15, 0x2, 0x158, 0x27, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 
    0x7, 0x50, 0x2, 0x2, 0x15a, 0x15d, 0x5, 0x26, 0x14, 0x2, 0x15b, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x15d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x7, 
    0xb, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x46, 0x2, 0x2, 0x160, 0x161, 0x5, 
    0x40, 0x21, 0x2, 0x161, 0x162, 0x7, 0x3d, 0x2, 0x2, 0x162, 0x163, 0x5, 
    0x40, 0x21, 0x2, 0x163, 0x164, 0x7, 0x47, 0x2, 0x2, 0x164, 0x165, 0x7, 
    0x4e, 0x2, 0x2, 0x165, 0x166, 0x5, 0x24, 0x13, 0x2, 0x166, 0x167, 0x7, 
    0x4f, 0x2, 0x2, 0x167, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x7, 
    0xc, 0x2, 0x2, 0x169, 0x16a, 0x7, 0x46, 0x2, 0x2, 0x16a, 0x16b, 0x5, 
    0x40, 0x21, 0x2, 0x16b, 0x16c, 0x7, 0x3d, 0x2, 0x2, 0x16c, 0x16d, 0x5, 
    0x40, 0x21, 0x2, 0x16d, 0x16e, 0x7, 0x47, 0x2, 0x2, 0x16e, 0x16f, 0x7, 
    0x4e, 0x2, 0x2, 0x16f, 0x170, 0x5, 0x42, 0x22, 0x2, 0x170, 0x171, 0x5, 
    0x2e, 0x18, 0x2, 0x171, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x172, 0x175, 0x7, 
    0x4a, 0x2, 0x2, 0x173, 0x176, 0x5, 0x96, 0x4c, 0x2, 0x174, 0x176, 0x3, 
    0x2, 0x2, 0x2, 0x175, 0x173, 0x3, 0x2, 0x2, 0x2, 0x175, 0x174, 0x3, 
    0x2, 0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x7, 
    0x4b, 0x2, 0x2, 0x178, 0x17b, 0x5, 0x32, 0x1a, 0x2, 0x179, 0x17b, 0x3, 
    0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x179, 0x3, 
    0x2, 0x2, 0x2, 0x17b, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x7, 
    0x50, 0x2, 0x2, 0x17d, 0x180, 0x5, 0x34, 0x1b, 0x2, 0x17e, 0x180, 0x3, 
    0x2, 0x2, 0x2, 0x17f, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17e, 0x3, 
    0x2, 0x2, 0x2, 0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x7, 
    0x4f, 0x2, 0x2, 0x182, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x7, 
    0xd, 0x2, 0x2, 0x184, 0x185, 0x7, 0x9, 0x2, 0x2, 0x185, 0x186, 0x5, 
    0x40, 0x21, 0x2, 0x186, 0x187, 0x5, 0x3e, 0x20, 0x2, 0x187, 0x188, 0x7, 
    0x3b, 0x2, 0x2, 0x188, 0x189, 0x9, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x9, 
    0x3, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x4f, 0x2, 0x2, 0x18b, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x50, 0x2, 0x2, 0x18d, 0x18e, 0x5, 
    0x44, 0x23, 0x2, 0x18e, 0x18f, 0x7, 0x3b, 0x2, 0x2, 0x18f, 0x192, 0x5, 
    0x60, 0x31, 0x2, 0x190, 0x193, 0x5, 0x32, 0x1a, 0x2, 0x191, 0x193, 0x3, 
    0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x192, 0x191, 0x3, 
    0x2, 0x2, 0x2, 0x193, 0x33, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x7, 0xe, 
    0x2, 0x2, 0x195, 0x196, 0x7, 0x4e, 0x2, 0x2, 0x196, 0x197, 0x9, 0x2, 
    0x2, 0x2, 0x197, 0x198, 0x9, 0x3, 0x2, 0x2, 0x198, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x199, 0x19a, 0x7, 0xf, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x48, 0x2, 
    0x2, 0x19b, 0x19c, 0x5, 0x3a, 0x1e, 0x2, 0x19c, 0x19d, 0x7, 0x49, 0x2, 
    0x2, 0x19d, 0x37, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a1, 0x7, 0x4a, 0x2, 
    0x2, 0x19f, 0x1a2, 0x5, 0x96, 0x4c, 0x2, 0x1a0, 0x1a2, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x4b, 0x2, 
    0x2, 0x1a4, 0x1a5, 0x7, 0x48, 0x2, 0x2, 0x1a5, 0x1a6, 0x5, 0x1c, 0xf, 
    0x2, 0x1a6, 0x1a7, 0x7, 0x49, 0x2, 0x2, 0x1a7, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x1a9, 0x5, 0x38, 0x1d, 0x2, 0x1a9, 0x1aa, 0x5, 0x3a, 0x1e, 
    0x2, 0x1aa, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ab, 0x3, 0x2, 0x2, 
    0x2, 0x1ad, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x10, 0x2, 
    0x2, 0x1af, 0x1b0, 0x7, 0x46, 0x2, 0x2, 0x1b0, 0x1b1, 0x9, 0x2, 0x2, 
    0x2, 0x1b1, 0x1b2, 0x9, 0x3, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x47, 0x2, 
    0x2, 0x1b3, 0x1b4, 0x7, 0x48, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x1c, 0xf, 
    0x2, 0x1b5, 0x1b6, 0x7, 0x49, 0x2, 0x2, 0x1b6, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b8, 0x9, 0x4, 0x2, 0x2, 0x1b8, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x1be, 0x5, 0x3e, 0x20, 0x2, 0x1ba, 0x1bb, 0x7, 0x52, 0x2, 0x2, 
    0x1bb, 0x1bd, 0x5, 0x3e, 0x20, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1bd, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 0x2, 0x2, 
    0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1c0, 
    0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c6, 0x5, 0x3e, 0x20, 0x2, 0x1c2, 
    0x1c3, 0x7, 0x52, 0x2, 0x2, 0x1c3, 0x1c5, 0x5, 0x3e, 0x20, 0x2, 0x1c4, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
    0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1d3, 
    0x5, 0x62, 0x32, 0x2, 0x1ca, 0x1cf, 0x5, 0x3e, 0x20, 0x2, 0x1cb, 0x1cc, 
    0x7, 0x52, 0x2, 0x2, 0x1cc, 0x1ce, 0x5, 0x3e, 0x20, 0x2, 0x1cd, 0x1cb, 
    0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cd, 
    0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d3, 
    0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1c9, 
    0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x5, 0x42, 0x22, 0x2, 0x1d5, 0x1d6, 0x7, 
    0x46, 0x2, 0x2, 0x1d6, 0x1d7, 0x5, 0x78, 0x3d, 0x2, 0x1d7, 0x1d8, 0x7, 
    0x47, 0x2, 0x2, 0x1d8, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1dd, 0x5, 
    0x52, 0x2a, 0x2, 0x1da, 0x1dd, 0x5, 0x5c, 0x2f, 0x2, 0x1db, 0x1dd, 0x5, 
    0x6e, 0x38, 0x2, 0x1dc, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1da, 0x3, 
    0x2, 0x2, 0x2, 0x1dc, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1e0, 0x3, 
    0x2, 0x2, 0x2, 0x1de, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x3, 
    0x2, 0x2, 0x2, 0x1df, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 
    0x2, 0x2, 0x1e1, 0x1e2, 0x5, 0x4c, 0x27, 0x2, 0x1e2, 0x1e3, 0x5, 0x4a, 
    0x26, 0x2, 0x1e3, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e6, 0x3, 0x2, 
    0x2, 0x2, 0x1e5, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e4, 0x3, 0x2, 
    0x2, 0x2, 0x1e6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x7, 0x27, 
    0x2, 0x2, 0x1e8, 0x1e9, 0x7, 0x4c, 0x2, 0x2, 0x1e9, 0x1ea, 0x5, 0x4e, 
    0x28, 0x2, 0x1ea, 0x1eb, 0x7, 0x4d, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x50, 
    0x29, 0x2, 0x1ec, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x5, 0x3e, 
    0x20, 0x2, 0x1ee, 0x1ef, 0x7, 0x52, 0x2, 0x2, 0x1ef, 0x1f0, 0x5, 0x3e, 
    0x20, 0x2, 0x1f0, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x3f, 
    0x2, 0x2, 0x1f2, 0x1f3, 0x7, 0x56, 0x2, 0x2, 0x1f3, 0x1f9, 0x5, 0x4e, 
    0x28, 0x2, 0x1f4, 0x1f5, 0x5, 0x3e, 0x20, 0x2, 0x1f5, 0x1f6, 0x7, 0x56, 
    0x2, 0x2, 0x1f6, 0x1f7, 0x5, 0x4e, 0x28, 0x2, 0x1f7, 0x1f9, 0x3, 0x2, 
    0x2, 0x2, 0x1f8, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f1, 0x3, 0x2, 
    0x2, 0x2, 0x1f8, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x1fa, 0x1fb, 0x7, 0x31, 0x2, 0x2, 0x1fb, 0x1fe, 0x5, 0x3e, 0x20, 
    0x2, 0x1fc, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fa, 0x3, 0x2, 0x2, 
    0x2, 0x1fd, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x1ff, 0x200, 0x7, 0x17, 0x2, 0x2, 0x200, 0x201, 0x5, 0x54, 0x2b, 0x2, 
    0x201, 0x202, 0x5, 0x3e, 0x20, 0x2, 0x202, 0x203, 0x7, 0x4f, 0x2, 0x2, 
    0x203, 0x53, 0x3, 0x2, 0x2, 0x2, 0x204, 0x20b, 0x5, 0x56, 0x2c, 0x2, 
    0x205, 0x20b, 0x5, 0x58, 0x2d, 0x2, 0x206, 0x20b, 0x5, 0x5a, 0x2e, 0x2, 
    0x207, 0x20b, 0x7, 0x1a, 0x2, 0x2, 0x208, 0x20b, 0x7, 0x1b, 0x2, 0x2, 
    0x209, 0x20b, 0x5, 0x3e, 0x20, 0x2, 0x20a, 0x204, 0x3, 0x2, 0x2, 0x2, 
    0x20a, 0x205, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x206, 0x3, 0x2, 0x2, 0x2, 
    0x20a, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x208, 0x3, 0x2, 0x2, 0x2, 
    0x20a, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x55, 0x3, 0x2, 0x2, 0x2, 0x20c, 
    0x213, 0x7, 0x18, 0x2, 0x2, 0x20d, 0x20e, 0x7, 0x46, 0x2, 0x2, 0x20e, 
    0x20f, 0x7, 0x40, 0x2, 0x2, 0x20f, 0x210, 0x7, 0x3f, 0x2, 0x2, 0x210, 
    0x211, 0x7, 0x40, 0x2, 0x2, 0x211, 0x214, 0x7, 0x47, 0x2, 0x2, 0x212, 
    0x214, 0x3, 0x2, 0x2, 0x2, 0x213, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x213, 
    0x212, 0x3, 0x2, 0x2, 0x2, 0x214, 0x57, 0x3, 0x2, 0x2, 0x2, 0x215, 0x21c, 
    0x7, 0x19, 0x2, 0x2, 0x216, 0x217, 0x7, 0x46, 0x2, 0x2, 0x217, 0x218, 
    0x7, 0x41, 0x2, 0x2, 0x218, 0x219, 0x7, 0x3f, 0x2, 0x2, 0x219, 0x21a, 
    0x7, 0x41, 0x2, 0x2, 0x21a, 0x21d, 0x7, 0x47, 0x2, 0x2, 0x21b, 0x21d, 
    0x3, 0x2, 0x2, 0x2, 0x21c, 0x216, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21b, 
    0x3, 0x2, 0x2, 0x2, 0x21d, 0x59, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x7, 
    0x22, 0x2, 0x2, 0x21f, 0x220, 0x7, 0x46, 0x2, 0x2, 0x220, 0x225, 0x5, 
    0x3e, 0x20, 0x2, 0x221, 0x222, 0x7, 0x50, 0x2, 0x2, 0x222, 0x224, 0x5, 
    0x3e, 0x20, 0x2, 0x223, 0x221, 0x3, 0x2, 0x2, 0x2, 0x224, 0x227, 0x3, 
    0x2, 0x2, 0x2, 0x225, 0x223, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x3, 
    0x2, 0x2, 0x2, 0x226, 0x228, 0x3, 0x2, 0x2, 0x2, 0x227, 0x225, 0x3, 
    0x2, 0x2, 0x2, 0x228, 0x229, 0x7, 0x47, 0x2, 0x2, 0x229, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x22a, 0x22b, 0x7, 0x24, 0x2, 0x2, 0x22b, 0x22c, 0x5, 
    0x54, 0x2b, 0x2, 0x22c, 0x22f, 0x5, 0x3e, 0x20, 0x2, 0x22d, 0x22e, 0x7, 
    0x3b, 0x2, 0x2, 0x22e, 0x230, 0x5, 0x5e, 0x30, 0x2, 0x22f, 0x22d, 0x3, 
    0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 0x3, 
    0x2, 0x2, 0x2, 0x231, 0x232, 0x7, 0x4f, 0x2, 0x2, 0x232, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x233, 0x23a, 0x7, 0x40, 0x2, 0x2, 0x234, 0x23a, 0x7, 
    0x41, 0x2, 0x2, 0x235, 0x23a, 0x7, 0x42, 0x2, 0x2, 0x236, 0x23a, 0x7, 
    0x38, 0x2, 0x2, 0x237, 0x23a, 0x7, 0x39, 0x2, 0x2, 0x238, 0x23a, 0x5, 
    0x3e, 0x20, 0x2, 0x239, 0x233, 0x3, 0x2, 0x2, 0x2, 0x239, 0x234, 0x3, 
    0x2, 0x2, 0x2, 0x239, 0x235, 0x3, 0x2, 0x2, 0x2, 0x239, 0x236, 0x3, 
    0x2, 0x2, 0x2, 0x239, 0x237, 0x3, 0x2, 0x2, 0x2, 0x239, 0x238, 0x3, 
    0x2, 0x2, 0x2, 0x23a, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x5, 0x7c, 
    0x3f, 0x2, 0x23c, 0x23d, 0x5, 0x3e, 0x20, 0x2, 0x23d, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x23e, 0x241, 0x5, 0x7e, 0x40, 0x2, 0x23f, 0x241, 0x3, 0x2, 
    0x2, 0x2, 0x240, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x240, 0x23f, 0x3, 0x2, 
    0x2, 0x2, 0x241, 0x242, 0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x5, 0x3e, 
    0x20, 0x2, 0x243, 0x63, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x7, 0x29, 
    0x2, 0x2, 0x245, 0x246, 0x5, 0x3e, 0x20, 0x2, 0x246, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x247, 0x248, 0x5, 0x54, 0x2b, 0x2, 0x248, 0x24c, 0x5, 0x3e, 
    0x20, 0x2, 0x249, 0x24a, 0x7, 0x3b, 0x2, 0x2, 0x24a, 0x24d, 0x5, 0x96, 
    0x4c, 0x2, 0x24b, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x249, 0x3, 0x2, 
    0x2, 0x2, 0x24c, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x3, 0x2, 
    0x2, 0x2, 0x24e, 0x24f, 0x7, 0x4f, 0x2, 0x2, 0x24f, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x250, 0x251, 0x7, 0x2a, 0x2, 0x2, 0x251, 0x254, 0x5, 0x46, 
    0x24, 0x2, 0x252, 0x255, 0x5, 0x64, 0x33, 0x2, 0x253, 0x255, 0x3, 0x2, 
    0x2, 0x2, 0x254, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x253, 0x3, 0x2, 
    0x2, 0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x7, 0x4f, 
    0x2, 0x2, 0x257, 0x69, 0x3, 0x2, 0x2, 0x2, 0x258, 0x25b, 0x5, 0x6, 0x4, 
    0x2, 0x259, 0x25b, 0x5, 0x68, 0x35, 0x2, 0x25a, 0x258, 0x3, 0x2, 0x2, 
    0x2, 0x25a, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x25c, 0x260, 0x7, 0x48, 0x2, 0x2, 0x25d, 0x25f, 0x5, 0x6a, 0x36, 0x2, 
    0x25e, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x262, 0x3, 0x2, 0x2, 0x2, 
    0x260, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0x3, 0x2, 0x2, 0x2, 
    0x261, 0x263, 0x3, 0x2, 0x2, 0x2, 0x262, 0x260, 0x3, 0x2, 0x2, 0x2, 
    0x263, 0x264, 0x7, 0x49, 0x2, 0x2, 0x264, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x265, 0x266, 0x7, 0x25, 0x2, 0x2, 0x266, 0x275, 0x5, 0x3e, 0x20, 0x2, 
    0x267, 0x271, 0x7, 0x46, 0x2, 0x2, 0x268, 0x26d, 0x5, 0x70, 0x39, 0x2, 
    0x269, 0x26a, 0x7, 0x50, 0x2, 0x2, 0x26a, 0x26c, 0x5, 0x70, 0x39, 0x2, 
    0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26f, 0x3, 0x2, 0x2, 0x2, 
    0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 
    0x26e, 0x272, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x26d, 0x3, 0x2, 0x2, 0x2, 
    0x270, 0x272, 0x3, 0x2, 0x2, 0x2, 0x271, 0x268, 0x3, 0x2, 0x2, 0x2, 
    0x271, 0x270, 0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x276, 0x7, 0x47, 0x2, 0x2, 0x274, 0x276, 0x3, 0x2, 0x2, 0x2, 
    0x275, 0x267, 0x3, 0x2, 0x2, 0x2, 0x275, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x276, 0x277, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x7, 0x4f, 0x2, 0x2, 
    0x278, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x5, 0x54, 0x2b, 0x2, 
    0x27a, 0x27b, 0x5, 0x3e, 0x20, 0x2, 0x27b, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x27c, 0x27d, 0x7, 0x2b, 0x2, 0x2, 0x27d, 0x27e, 0x5, 0x54, 0x2b, 0x2, 
    0x27e, 0x27f, 0x5, 0x84, 0x43, 0x2, 0x27f, 0x282, 0x7, 0x46, 0x2, 0x2, 
    0x280, 0x283, 0x5, 0x74, 0x3b, 0x2, 0x281, 0x283, 0x3, 0x2, 0x2, 0x2, 
    0x282, 0x280, 0x3, 0x2, 0x2, 0x2, 0x282, 0x281, 0x3, 0x2, 0x2, 0x2, 
    0x283, 0x284, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x7, 0x47, 0x2, 0x2, 
    0x285, 0x286, 0x5, 0x8c, 0x47, 0x2, 0x286, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x287, 0x28c, 0x5, 0x70, 0x39, 0x2, 0x288, 0x289, 0x7, 0x50, 0x2, 0x2, 
    0x289, 0x28b, 0x5, 0x70, 0x39, 0x2, 0x28a, 0x288, 0x3, 0x2, 0x2, 0x2, 
    0x28b, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28a, 0x3, 0x2, 0x2, 0x2, 
    0x28c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x75, 0x3, 0x2, 0x2, 0x2, 0x28e, 
    0x28c, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x5, 0x84, 0x43, 0x2, 0x290, 
    0x291, 0x7, 0x46, 0x2, 0x2, 0x291, 0x292, 0x5, 0x78, 0x3d, 0x2, 0x292, 
    0x293, 0x7, 0x47, 0x2, 0x2, 0x293, 0x77, 0x3, 0x2, 0x2, 0x2, 0x294, 
    0x29a, 0x5, 0x5e, 0x30, 0x2, 0x295, 0x29a, 0x5, 0x60, 0x31, 0x2, 0x296, 
    0x29a, 0x5, 0x62, 0x32, 0x2, 0x297, 0x29a, 0x5, 0x76, 0x3c, 0x2, 0x298, 
    0x29a, 0x3, 0x2, 0x2, 0x2, 0x299, 0x294, 0x3, 0x2, 0x2, 0x2, 0x299, 
    0x295, 0x3, 0x2, 0x2, 0x2, 0x299, 0x296, 0x3, 0x2, 0x2, 0x2, 0x299, 
    0x297, 0x3, 0x2, 0x2, 0x2, 0x299, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29a, 
    0x29b, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29c, 0x5, 0x7a, 0x3e, 0x2, 0x29c, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x7, 0x50, 0x2, 0x2, 0x29e, 
    0x2a1, 0x5, 0x78, 0x3d, 0x2, 0x29f, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
    0x29d, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a1, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x9, 0x5, 0x2, 0x2, 0x2a3, 0x2a4, 
    0x7, 0x52, 0x2, 0x2, 0x2a4, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a6, 
    0x7, 0x1e, 0x2, 0x2, 0x2a6, 0x2a7, 0x7, 0x52, 0x2, 0x2, 0x2a7, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a9, 0x7, 0x26, 0x2, 0x2, 0x2a9, 0x2ae, 
    0x5, 0x3e, 0x20, 0x2, 0x2aa, 0x2ab, 0x7, 0x50, 0x2, 0x2, 0x2ab, 0x2ad, 
    0x5, 0x3e, 0x20, 0x2, 0x2ac, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2b0, 
    0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 
    0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ae, 
    0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x7, 0x4f, 0x2, 0x2, 0x2b2, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b4, 0x7, 0x14, 0x2, 0x2, 0x2b4, 0x2b5, 
    0x7, 0x4e, 0x2, 0x2, 0x2b5, 0x2b6, 0x5, 0x3e, 0x20, 0x2, 0x2b6, 0x2b7, 
    0x7, 0x4f, 0x2, 0x2, 0x2b7, 0x83, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2bd, 
    0x5, 0x3e, 0x20, 0x2, 0x2b9, 0x2ba, 0x7, 0x52, 0x2, 0x2, 0x2ba, 0x2bc, 
    0x5, 0x3e, 0x20, 0x2, 0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bf, 
    0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 
    0x3, 0x2, 0x2, 0x2, 0x2be, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2bd, 0x3, 
    0x2, 0x2, 0x2, 0x2c0, 0x2c3, 0x5, 0x88, 0x45, 0x2, 0x2c1, 0x2c3, 0x5, 
    0x8c, 0x47, 0x2, 0x2c2, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c1, 0x3, 
    0x2, 0x2, 0x2, 0x2c3, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2cd, 0x5, 0x8a, 
    0x46, 0x2, 0x2c5, 0x2cd, 0x5, 0x6, 0x4, 0x2, 0x2c6, 0x2cd, 0x5, 0xa2, 
    0x52, 0x2, 0x2c7, 0x2cd, 0x5, 0x9a, 0x4e, 0x2, 0x2c8, 0x2cd, 0x5, 0x66, 
    0x34, 0x2, 0x2c9, 0x2cd, 0x5, 0x68, 0x35, 0x2, 0x2ca, 0x2cd, 0x5, 0x90, 
    0x49, 0x2, 0x2cb, 0x2cd, 0x5, 0x8e, 0x48, 0x2, 0x2cc, 0x2c4, 0x3, 0x2, 
    0x2, 0x2, 0x2cc, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2c6, 0x3, 0x2, 
    0x2, 0x2, 0x2cc, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2c8, 0x3, 0x2, 
    0x2, 0x2, 0x2cc, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2ca, 0x3, 0x2, 
    0x2, 0x2, 0x2cc, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x2ce, 0x2cf, 0x5, 0x76, 0x3c, 0x2, 0x2cf, 0x2d0, 0x7, 0x4f, 0x2, 
    0x2, 0x2d0, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d5, 0x7, 0x48, 0x2, 
    0x2, 0x2d2, 0x2d4, 0x5, 0x88, 0x45, 0x2, 0x2d3, 0x2d2, 0x3, 0x2, 0x2, 
    0x2, 0x2d4, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d3, 0x3, 0x2, 0x2, 
    0x2, 0x2d5, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d8, 0x3, 0x2, 0x2, 
    0x2, 0x2d7, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d9, 0x7, 0x49, 0x2, 
    0x2, 0x2d9, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x7, 0x1f, 0x2, 
    0x2, 0x2db, 0x2dc, 0x5, 0x92, 0x4a, 0x2, 0x2dc, 0x2dd, 0x7, 0x4f, 0x2, 
    0x2, 0x2dd, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x7, 0x3a, 0x2, 
    0x2, 0x2df, 0x2e0, 0x7, 0x4f, 0x2, 0x2, 0x2e0, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x2e1, 0x2e2, 0x5, 0x8, 0x5, 0x2, 0x2e2, 0x2e3, 0x5, 0x94, 0x4b, 
    0x2, 0x2e3, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0x7, 0x46, 0x2, 
    0x2, 0x2e5, 0x2e6, 0x5, 0x92, 0x4a, 0x2, 0x2e6, 0x2e7, 0x7, 0x47, 0x2, 
    0x2, 0x2e7, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 0x7, 0x54, 0x2, 
    0x2, 0x2e9, 0x2ed, 0x5, 0x92, 0x4a, 0x2, 0x2ea, 0x2eb, 0x7, 0x32, 0x2, 
    0x2, 0x2eb, 0x2ed, 0x5, 0x92, 0x4a, 0x2, 0x2ec, 0x2e1, 0x3, 0x2, 0x2, 
    0x2, 0x2ec, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2e8, 0x3, 0x2, 0x2, 
    0x2, 0x2ec, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x2ee, 0x2ef, 0x9, 0x6, 0x2, 0x2, 0x2ef, 0x2f2, 0x5, 0x92, 0x4a, 0x2, 
    0x2f0, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2ee, 0x3, 0x2, 0x2, 0x2, 
    0x2f1, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x95, 0x3, 0x2, 0x2, 0x2, 0x2f3, 
    0x2f4, 0x7, 0x46, 0x2, 0x2, 0x2f4, 0x2f5, 0x5, 0x96, 0x4c, 0x2, 0x2f5, 
    0x2f6, 0x7, 0x47, 0x2, 0x2, 0x2f6, 0x2f7, 0x5, 0x98, 0x4d, 0x2, 0x2f7, 
    0x302, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x7, 0x32, 0x2, 0x2, 0x2f9, 
    0x302, 0x5, 0x96, 0x4c, 0x2, 0x2fa, 0x2fb, 0x7, 0x35, 0x2, 0x2, 0x2fb, 
    0x302, 0x5, 0x96, 0x4c, 0x2, 0x2fc, 0x2fd, 0x7, 0x54, 0x2, 0x2, 0x2fd, 
    0x302, 0x5, 0x96, 0x4c, 0x2, 0x2fe, 0x2ff, 0x5, 0x92, 0x4a, 0x2, 0x2ff, 
    0x300, 0x5, 0x98, 0x4d, 0x2, 0x300, 0x302, 0x3, 0x2, 0x2, 0x2, 0x301, 
    0x2f3, 0x3, 0x2, 0x2, 0x2, 0x301, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x301, 
    0x2fa, 0x3, 0x2, 0x2, 0x2, 0x301, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x301, 
    0x2fe, 0x3, 0x2, 0x2, 0x2, 0x302, 0x97, 0x3, 0x2, 0x2, 0x2, 0x303, 0x317, 
    0x7, 0x34, 0x2, 0x2, 0x304, 0x317, 0x7, 0x37, 0x2, 0x2, 0x305, 0x317, 
    0x7, 0x33, 0x2, 0x2, 0x306, 0x317, 0x7, 0x36, 0x2, 0x2, 0x307, 0x308, 
    0x7, 0x3b, 0x2, 0x2, 0x308, 0x317, 0x7, 0x3b, 0x2, 0x2, 0x309, 0x30a, 
    0x7, 0x32, 0x2, 0x2, 0x30a, 0x317, 0x7, 0x3b, 0x2, 0x2, 0x30b, 0x317, 
    0x7, 0x35, 0x2, 0x2, 0x30c, 0x30f, 0x7, 0x4c, 0x2, 0x2, 0x30d, 0x310, 
    0x7, 0x3b, 0x2, 0x2, 0x30e, 0x310, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x30d, 
    0x3, 0x2, 0x2, 0x2, 0x30f, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x310, 0x317, 
    0x3, 0x2, 0x2, 0x2, 0x311, 0x314, 0x7, 0x4d, 0x2, 0x2, 0x312, 0x315, 
    0x7, 0x3b, 0x2, 0x2, 0x313, 0x315, 0x3, 0x2, 0x2, 0x2, 0x314, 0x312, 
    0x3, 0x2, 0x2, 0x2, 0x314, 0x313, 0x3, 0x2, 0x2, 0x2, 0x315, 0x317, 
    0x3, 0x2, 0x2, 0x2, 0x316, 0x303, 0x3, 0x2, 0x2, 0x2, 0x316, 0x304, 
    0x3, 0x2, 0x2, 0x2, 0x316, 0x305, 0x3, 0x2, 0x2, 0x2, 0x316, 0x306, 
    0x3, 0x2, 0x2, 0x2, 0x316, 0x307, 0x3, 0x2, 0x2, 0x2, 0x316, 0x309, 
    0x3, 0x2, 0x2, 0x2, 0x316, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x316, 0x30c, 
    0x3, 0x2, 0x2, 0x2, 0x316, 0x311, 0x3, 0x2, 0x2, 0x2, 0x317, 0x318, 
    0x3, 0x2, 0x2, 0x2, 0x318, 0x31b, 0x5, 0x96, 0x4c, 0x2, 0x319, 0x31b, 
    0x3, 0x2, 0x2, 0x2, 0x31a, 0x316, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x319, 
    0x3, 0x2, 0x2, 0x2, 0x31b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31f, 0x5, 
    0x9c, 0x4f, 0x2, 0x31d, 0x320, 0x5, 0xa0, 0x51, 0x2, 0x31e, 0x320, 0x3, 
    0x2, 0x2, 0x2, 0x31f, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x31e, 0x3, 
    0x2, 0x2, 0x2, 0x320, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x7, 0x2f, 
    0x2, 0x2, 0x322, 0x325, 0x5, 0x9e, 0x50, 0x2, 0x323, 0x326, 0x5, 0x86, 
    0x44, 0x2, 0x324, 0x326, 0x7, 0x4f, 0x2, 0x2, 0x325, 0x323, 0x3, 0x2, 
    0x2, 0x2, 0x325, 0x324, 0x3, 0x2, 0x2, 0x2, 0x326, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x327, 0x328, 0x7, 0x46, 0x2, 0x2, 0x328, 0x329, 0x5, 0x96, 0x4c, 
    0x2, 0x329, 0x32a, 0x7, 0x47, 0x2, 0x2, 0x32a, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0x32b, 0x32c, 0x7, 0x30, 0x2, 0x2, 0x32c, 0x32d, 0x5, 0x86, 0x44, 
    0x2, 0x32d, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 0x7, 0x2c, 0x2, 
    0x2, 0x32f, 0x330, 0x5, 0xa4, 0x53, 0x2, 0x330, 0x334, 0x7, 0x48, 0x2, 
    0x2, 0x331, 0x333, 0x5, 0xa6, 0x54, 0x2, 0x332, 0x331, 0x3, 0x2, 0x2, 
    0x2, 0x333, 0x336, 0x3, 0x2, 0x2, 0x2, 0x334, 0x332, 0x3, 0x2, 0x2, 
    0x2, 0x334, 0x335, 0x3, 0x2, 0x2, 0x2, 0x335, 0x339, 0x3, 0x2, 0x2, 
    0x2, 0x336, 0x334, 0x3, 0x2, 0x2, 0x2, 0x337, 0x33a, 0x5, 0xa8, 0x55, 
    0x2, 0x338, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x339, 0x337, 0x3, 0x2, 0x2, 
    0x2, 0x339, 0x338, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33b, 0x3, 0x2, 0x2, 
    0x2, 0x33b, 0x33c, 0x7, 0x49, 0x2, 0x2, 0x33c, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0x33d, 0x33e, 0x7, 0x46, 0x2, 0x2, 0x33e, 0x33f, 0x5, 0x3e, 0x20, 
    0x2, 0x33f, 0x340, 0x7, 0x47, 0x2, 0x2, 0x340, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x341, 0x342, 0x7, 0x2d, 0x2, 0x2, 0x342, 0x343, 0x5, 0x5e, 0x30, 
    0x2, 0x343, 0x34b, 0x7, 0x4e, 0x2, 0x2, 0x344, 0x34c, 0x5, 0x8c, 0x47, 
    0x2, 0x345, 0x347, 0x5, 0x88, 0x45, 0x2, 0x346, 0x345, 0x3, 0x2, 0x2, 
    0x2, 0x347, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x348, 0x346, 0x3, 0x2, 0x2, 
    0x2, 0x348, 0x349, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34c, 0x3, 0x2, 0x2, 
    0x2, 0x34a, 0x348, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x344, 0x3, 0x2, 0x2, 
    0x2, 0x34b, 0x348, 0x3, 0x2, 0x2, 0x2, 0x34c, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x34d, 0x34e, 0x7, 0x2e, 0x2, 0x2, 0x34e, 0x356, 0x7, 0x4e, 0x2, 0x2, 
    0x34f, 0x357, 0x5, 0x8c, 0x47, 0x2, 0x350, 0x352, 0x5, 0x88, 0x45, 0x2, 
    0x351, 0x350, 0x3, 0x2, 0x2, 0x2, 0x352, 0x355, 0x3, 0x2, 0x2, 0x2, 
    0x353, 0x351, 0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 0x3, 0x2, 0x2, 0x2, 
    0x354, 0x357, 0x3, 0x2, 0x2, 0x2, 0x355, 0x353, 0x3, 0x2, 0x2, 0x2, 
    0x356, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x356, 0x353, 0x3, 0x2, 0x2, 0x2, 
    0x357, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x46, 0xaf, 0xb1, 0xbb, 0xcb, 0xf7, 
    0x101, 0x107, 0x112, 0x118, 0x136, 0x142, 0x147, 0x14d, 0x155, 0x15c, 
    0x175, 0x17a, 0x17f, 0x192, 0x1a1, 0x1ac, 0x1be, 0x1c6, 0x1cf, 0x1d2, 
    0x1dc, 0x1de, 0x1e5, 0x1f8, 0x1fd, 0x20a, 0x213, 0x21c, 0x225, 0x22f, 
    0x239, 0x240, 0x24c, 0x254, 0x25a, 0x260, 0x26d, 0x271, 0x275, 0x282, 
    0x28c, 0x299, 0x2a0, 0x2ae, 0x2bd, 0x2c2, 0x2cc, 0x2d5, 0x2ec, 0x2f1, 
    0x301, 0x30f, 0x314, 0x316, 0x31a, 0x31f, 0x325, 0x334, 0x339, 0x348, 
    0x34b, 0x353, 0x356, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

IrdlCommonDeclParser::Initializer IrdlCommonDeclParser::_init;
