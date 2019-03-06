
// Generated from C:/Users/j05kraus/Private/SWDevelop/mobata_oss_dev/libs/dslparser/dslparser/grammars/Spenat.g4 by ANTLR 4.7.2


#include "SpenatListener.h"

#include "SpenatParser.h"


using namespace antlrcpp;
using namespace antlr4;

SpenatParser::SpenatParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SpenatParser::~SpenatParser() {
  delete _interpreter;
}

std::string SpenatParser::getGrammarFileName() const {
  return "Spenat.g4";
}

const std::vector<std::string>& SpenatParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SpenatParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SpenatDeclContext ------------------------------------------------------------------

SpenatParser::SpenatDeclContext::SpenatDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::SpenatDeclContext::SpenatID() {
  return getToken(SpenatParser::SpenatID, 0);
}

tree::TerminalNode* SpenatParser::SpenatDeclContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

SpenatParser::SpenatBodyContext* SpenatParser::SpenatDeclContext::spenatBody() {
  return getRuleContext<SpenatParser::SpenatBodyContext>(0);
}

tree::TerminalNode* SpenatParser::SpenatDeclContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}


size_t SpenatParser::SpenatDeclContext::getRuleIndex() const {
  return SpenatParser::RuleSpenatDecl;
}

void SpenatParser::SpenatDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpenatDecl(this);
}

void SpenatParser::SpenatDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpenatDecl(this);
}

SpenatParser::SpenatDeclContext* SpenatParser::spenatDecl() {
  SpenatDeclContext *_localctx = _tracker.createInstance<SpenatDeclContext>(_ctx, getState());
  enterRule(_localctx, 0, SpenatParser::RuleSpenatDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    match(SpenatParser::SpenatID);
    setState(153);
    match(SpenatParser::LBRACE);
    setState(154);
    spenatBody();
    setState(155);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpenatBodyContext ------------------------------------------------------------------

SpenatParser::SpenatBodyContext::SpenatBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::NameDeclContext* SpenatParser::SpenatBodyContext::nameDecl() {
  return getRuleContext<SpenatParser::NameDeclContext>(0);
}

SpenatParser::SpenatBodyOptionalContext* SpenatParser::SpenatBodyContext::spenatBodyOptional() {
  return getRuleContext<SpenatParser::SpenatBodyOptionalContext>(0);
}


size_t SpenatParser::SpenatBodyContext::getRuleIndex() const {
  return SpenatParser::RuleSpenatBody;
}

void SpenatParser::SpenatBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpenatBody(this);
}

void SpenatParser::SpenatBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpenatBody(this);
}

SpenatParser::SpenatBodyContext* SpenatParser::spenatBody() {
  SpenatBodyContext *_localctx = _tracker.createInstance<SpenatBodyContext>(_ctx, getState());
  enterRule(_localctx, 2, SpenatParser::RuleSpenatBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    nameDecl();
    setState(158);
    spenatBodyOptional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpenatBodyOptionalContext ------------------------------------------------------------------

SpenatParser::SpenatBodyOptionalContext::SpenatBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::TypeDefDeclContext* SpenatParser::SpenatBodyOptionalContext::typeDefDecl() {
  return getRuleContext<SpenatParser::TypeDefDeclContext>(0);
}

SpenatParser::SpenatBodyOptionalContext* SpenatParser::SpenatBodyOptionalContext::spenatBodyOptional() {
  return getRuleContext<SpenatParser::SpenatBodyOptionalContext>(0);
}

SpenatParser::AttributeDeclContext* SpenatParser::SpenatBodyOptionalContext::attributeDecl() {
  return getRuleContext<SpenatParser::AttributeDeclContext>(0);
}

SpenatParser::SignalDeclContext* SpenatParser::SpenatBodyOptionalContext::signalDecl() {
  return getRuleContext<SpenatParser::SignalDeclContext>(0);
}

SpenatParser::FunctionDeclContext* SpenatParser::SpenatBodyOptionalContext::functionDecl() {
  return getRuleContext<SpenatParser::FunctionDeclContext>(0);
}

SpenatParser::PortDeclContext* SpenatParser::SpenatBodyOptionalContext::portDecl() {
  return getRuleContext<SpenatParser::PortDeclContext>(0);
}

SpenatParser::PlaceDeclContext* SpenatParser::SpenatBodyOptionalContext::placeDecl() {
  return getRuleContext<SpenatParser::PlaceDeclContext>(0);
}

SpenatParser::TransitionDeclContext* SpenatParser::SpenatBodyOptionalContext::transitionDecl() {
  return getRuleContext<SpenatParser::TransitionDeclContext>(0);
}


size_t SpenatParser::SpenatBodyOptionalContext::getRuleIndex() const {
  return SpenatParser::RuleSpenatBodyOptional;
}

void SpenatParser::SpenatBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpenatBodyOptional(this);
}

void SpenatParser::SpenatBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpenatBodyOptional(this);
}

SpenatParser::SpenatBodyOptionalContext* SpenatParser::spenatBodyOptional() {
  SpenatBodyOptionalContext *_localctx = _tracker.createInstance<SpenatBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 4, SpenatParser::RuleSpenatBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::TypeID: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        typeDefDecl();
        setState(161);
        spenatBodyOptional();
        break;
      }

      case SpenatParser::AttributeID: {
        enterOuterAlt(_localctx, 2);
        setState(163);
        attributeDecl();
        setState(164);
        spenatBodyOptional();
        break;
      }

      case SpenatParser::SignalID: {
        enterOuterAlt(_localctx, 3);
        setState(166);
        signalDecl();
        setState(167);
        spenatBodyOptional();
        break;
      }

      case SpenatParser::FunctionID: {
        enterOuterAlt(_localctx, 4);
        setState(169);
        functionDecl();
        setState(170);
        spenatBodyOptional();
        break;
      }

      case SpenatParser::PortID: {
        enterOuterAlt(_localctx, 5);
        setState(172);
        portDecl();
        setState(173);
        spenatBodyOptional();
        break;
      }

      case SpenatParser::PlaceID: {
        enterOuterAlt(_localctx, 6);
        setState(175);
        placeDecl();
        setState(176);
        spenatBodyOptional();
        break;
      }

      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID: {
        enterOuterAlt(_localctx, 7);
        setState(178);
        transitionDecl();
        setState(179);
        spenatBodyOptional();
        break;
      }

      case SpenatParser::RBRACE: {
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

//----------------- PlaceDeclContext ------------------------------------------------------------------

SpenatParser::PlaceDeclContext::PlaceDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::PlaceDeclContext::PlaceID() {
  return getToken(SpenatParser::PlaceID, 0);
}

tree::TerminalNode* SpenatParser::PlaceDeclContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

SpenatParser::PlaceBodyContext* SpenatParser::PlaceDeclContext::placeBody() {
  return getRuleContext<SpenatParser::PlaceBodyContext>(0);
}

tree::TerminalNode* SpenatParser::PlaceDeclContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}


size_t SpenatParser::PlaceDeclContext::getRuleIndex() const {
  return SpenatParser::RulePlaceDecl;
}

void SpenatParser::PlaceDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlaceDecl(this);
}

void SpenatParser::PlaceDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlaceDecl(this);
}

SpenatParser::PlaceDeclContext* SpenatParser::placeDecl() {
  PlaceDeclContext *_localctx = _tracker.createInstance<PlaceDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, SpenatParser::RulePlaceDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(SpenatParser::PlaceID);
    setState(185);
    match(SpenatParser::LBRACE);
    setState(186);
    placeBody();
    setState(187);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PlaceBodyContext ------------------------------------------------------------------

SpenatParser::PlaceBodyContext::PlaceBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::NameDeclContext* SpenatParser::PlaceBodyContext::nameDecl() {
  return getRuleContext<SpenatParser::NameDeclContext>(0);
}

SpenatParser::InitialDeclContext* SpenatParser::PlaceBodyContext::initialDecl() {
  return getRuleContext<SpenatParser::InitialDeclContext>(0);
}


size_t SpenatParser::PlaceBodyContext::getRuleIndex() const {
  return SpenatParser::RulePlaceBody;
}

void SpenatParser::PlaceBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlaceBody(this);
}

void SpenatParser::PlaceBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlaceBody(this);
}

SpenatParser::PlaceBodyContext* SpenatParser::placeBody() {
  PlaceBodyContext *_localctx = _tracker.createInstance<PlaceBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, SpenatParser::RulePlaceBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    nameDecl();
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::InitialID: {
        setState(190);
        initialDecl();
        break;
      }

      case SpenatParser::RBRACE: {
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

//----------------- GuardDeclContext ------------------------------------------------------------------

SpenatParser::GuardDeclContext::GuardDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::GuardDeclContext::GuardID() {
  return getToken(SpenatParser::GuardID, 0);
}

tree::TerminalNode* SpenatParser::GuardDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

SpenatParser::ExpressionContext* SpenatParser::GuardDeclContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}

tree::TerminalNode* SpenatParser::GuardDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

SpenatParser::MultiExpressionContext* SpenatParser::GuardDeclContext::multiExpression() {
  return getRuleContext<SpenatParser::MultiExpressionContext>(0);
}


size_t SpenatParser::GuardDeclContext::getRuleIndex() const {
  return SpenatParser::RuleGuardDecl;
}

void SpenatParser::GuardDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGuardDecl(this);
}

void SpenatParser::GuardDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGuardDecl(this);
}

SpenatParser::GuardDeclContext* SpenatParser::guardDecl() {
  GuardDeclContext *_localctx = _tracker.createInstance<GuardDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, SpenatParser::RuleGuardDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(SpenatParser::GuardID);
    setState(195);
    match(SpenatParser::COLON);
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::NotIdSymbol:
      case SpenatParser::NotIdWord:
      case SpenatParser::TrueID:
      case SpenatParser::FalseID:
      case SpenatParser::INT:
      case SpenatParser::REAL:
      case SpenatParser::STRING:
      case SpenatParser::ID:
      case SpenatParser::LPAREN:
      case SpenatParser::MINUS: {
        setState(196);
        expression();
        setState(197);
        match(SpenatParser::SEMI);
        break;
      }

      case SpenatParser::LBRACE: {
        setState(199);
        multiExpression();
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

//----------------- MultiExpressionContext ------------------------------------------------------------------

SpenatParser::MultiExpressionContext::MultiExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::MultiExpressionContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

SpenatParser::ExpressionContext* SpenatParser::MultiExpressionContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}

tree::TerminalNode* SpenatParser::MultiExpressionContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}


size_t SpenatParser::MultiExpressionContext::getRuleIndex() const {
  return SpenatParser::RuleMultiExpression;
}

void SpenatParser::MultiExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiExpression(this);
}

void SpenatParser::MultiExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiExpression(this);
}

SpenatParser::MultiExpressionContext* SpenatParser::multiExpression() {
  MultiExpressionContext *_localctx = _tracker.createInstance<MultiExpressionContext>(_ctx, getState());
  enterRule(_localctx, 12, SpenatParser::RuleMultiExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(SpenatParser::LBRACE);
    setState(203);
    expression();
    setState(204);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiExpressionOptionalContext ------------------------------------------------------------------

SpenatParser::MultiExpressionOptionalContext::MultiExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::ExpressionContext* SpenatParser::MultiExpressionOptionalContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}


size_t SpenatParser::MultiExpressionOptionalContext::getRuleIndex() const {
  return SpenatParser::RuleMultiExpressionOptional;
}

void SpenatParser::MultiExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiExpressionOptional(this);
}

void SpenatParser::MultiExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiExpressionOptional(this);
}

SpenatParser::MultiExpressionOptionalContext* SpenatParser::multiExpressionOptional() {
  MultiExpressionOptionalContext *_localctx = _tracker.createInstance<MultiExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 14, SpenatParser::RuleMultiExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::NotIdSymbol:
      case SpenatParser::NotIdWord:
      case SpenatParser::TrueID:
      case SpenatParser::FalseID:
      case SpenatParser::INT:
      case SpenatParser::REAL:
      case SpenatParser::STRING:
      case SpenatParser::ID:
      case SpenatParser::LPAREN:
      case SpenatParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(206);
        expression();
        break;
      }

      case SpenatParser::EOF: {
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

//----------------- ActionDeclContext ------------------------------------------------------------------

SpenatParser::ActionDeclContext::ActionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ActionDeclContext::ActionID() {
  return getToken(SpenatParser::ActionID, 0);
}

tree::TerminalNode* SpenatParser::ActionDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

SpenatParser::SingleAssignmentContext* SpenatParser::ActionDeclContext::singleAssignment() {
  return getRuleContext<SpenatParser::SingleAssignmentContext>(0);
}

SpenatParser::MultiAssignmentContext* SpenatParser::ActionDeclContext::multiAssignment() {
  return getRuleContext<SpenatParser::MultiAssignmentContext>(0);
}


size_t SpenatParser::ActionDeclContext::getRuleIndex() const {
  return SpenatParser::RuleActionDecl;
}

void SpenatParser::ActionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterActionDecl(this);
}

void SpenatParser::ActionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitActionDecl(this);
}

SpenatParser::ActionDeclContext* SpenatParser::actionDecl() {
  ActionDeclContext *_localctx = _tracker.createInstance<ActionDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, SpenatParser::RuleActionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(SpenatParser::ActionID);
    setState(211);
    match(SpenatParser::COLON);
    setState(214);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::ID: {
        setState(212);
        singleAssignment();
        break;
      }

      case SpenatParser::LBRACE: {
        setState(213);
        multiAssignment();
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

//----------------- TransitionDeclContext ------------------------------------------------------------------

SpenatParser::TransitionDeclContext::TransitionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::SignalTransitionDeclContext* SpenatParser::TransitionDeclContext::signalTransitionDecl() {
  return getRuleContext<SpenatParser::SignalTransitionDeclContext>(0);
}

SpenatParser::TimeoutTransitionDeclContext* SpenatParser::TransitionDeclContext::timeoutTransitionDecl() {
  return getRuleContext<SpenatParser::TimeoutTransitionDeclContext>(0);
}


size_t SpenatParser::TransitionDeclContext::getRuleIndex() const {
  return SpenatParser::RuleTransitionDecl;
}

void SpenatParser::TransitionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransitionDecl(this);
}

void SpenatParser::TransitionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransitionDecl(this);
}

SpenatParser::TransitionDeclContext* SpenatParser::transitionDecl() {
  TransitionDeclContext *_localctx = _tracker.createInstance<TransitionDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, SpenatParser::RuleTransitionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::SignalTransitionID: {
        enterOuterAlt(_localctx, 1);
        setState(216);
        signalTransitionDecl();
        break;
      }

      case SpenatParser::TimeoutTransitionID: {
        enterOuterAlt(_localctx, 2);
        setState(217);
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

SpenatParser::SignalTransitionDeclContext::SignalTransitionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::SignalTransitionDeclContext::SignalTransitionID() {
  return getToken(SpenatParser::SignalTransitionID, 0);
}

tree::TerminalNode* SpenatParser::SignalTransitionDeclContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

SpenatParser::SignalTransitionBodyContext* SpenatParser::SignalTransitionDeclContext::signalTransitionBody() {
  return getRuleContext<SpenatParser::SignalTransitionBodyContext>(0);
}

tree::TerminalNode* SpenatParser::SignalTransitionDeclContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}


size_t SpenatParser::SignalTransitionDeclContext::getRuleIndex() const {
  return SpenatParser::RuleSignalTransitionDecl;
}

void SpenatParser::SignalTransitionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalTransitionDecl(this);
}

void SpenatParser::SignalTransitionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalTransitionDecl(this);
}

SpenatParser::SignalTransitionDeclContext* SpenatParser::signalTransitionDecl() {
  SignalTransitionDeclContext *_localctx = _tracker.createInstance<SignalTransitionDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, SpenatParser::RuleSignalTransitionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(SpenatParser::SignalTransitionID);
    setState(221);
    match(SpenatParser::LBRACE);
    setState(222);
    signalTransitionBody();
    setState(223);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalTransitionBodyContext ------------------------------------------------------------------

SpenatParser::SignalTransitionBodyContext::SignalTransitionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::NameDeclContext* SpenatParser::SignalTransitionBodyContext::nameDecl() {
  return getRuleContext<SpenatParser::NameDeclContext>(0);
}

SpenatParser::RefSignalDeclContext* SpenatParser::SignalTransitionBodyContext::refSignalDecl() {
  return getRuleContext<SpenatParser::RefSignalDeclContext>(0);
}

SpenatParser::RefPortDeclContext* SpenatParser::SignalTransitionBodyContext::refPortDecl() {
  return getRuleContext<SpenatParser::RefPortDeclContext>(0);
}

SpenatParser::GuardDeclContext* SpenatParser::SignalTransitionBodyContext::guardDecl() {
  return getRuleContext<SpenatParser::GuardDeclContext>(0);
}

SpenatParser::ActionDeclContext* SpenatParser::SignalTransitionBodyContext::actionDecl() {
  return getRuleContext<SpenatParser::ActionDeclContext>(0);
}

SpenatParser::PreDeclContext* SpenatParser::SignalTransitionBodyContext::preDecl() {
  return getRuleContext<SpenatParser::PreDeclContext>(0);
}

SpenatParser::PostDeclContext* SpenatParser::SignalTransitionBodyContext::postDecl() {
  return getRuleContext<SpenatParser::PostDeclContext>(0);
}


size_t SpenatParser::SignalTransitionBodyContext::getRuleIndex() const {
  return SpenatParser::RuleSignalTransitionBody;
}

void SpenatParser::SignalTransitionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalTransitionBody(this);
}

void SpenatParser::SignalTransitionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalTransitionBody(this);
}

SpenatParser::SignalTransitionBodyContext* SpenatParser::signalTransitionBody() {
  SignalTransitionBodyContext *_localctx = _tracker.createInstance<SignalTransitionBodyContext>(_ctx, getState());
  enterRule(_localctx, 22, SpenatParser::RuleSignalTransitionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    nameDecl();
    setState(230);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::RefSignalID: {
        setState(226);
        refSignalDecl();
        setState(227);
        refPortDecl();
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::GuardID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(234);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::GuardID: {
        setState(232);
        guardDecl();
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(238);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID: {
        setState(236);
        actionDecl();
        break;
      }

      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(242);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::PreID: {
        setState(240);
        preDecl();
        break;
      }

      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(246);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::PostID: {
        setState(244);
        postDecl();
        break;
      }

      case SpenatParser::RBRACE: {
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

//----------------- TimeoutTransitionDeclContext ------------------------------------------------------------------

SpenatParser::TimeoutTransitionDeclContext::TimeoutTransitionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::TimeoutTransitionDeclContext::TimeoutTransitionID() {
  return getToken(SpenatParser::TimeoutTransitionID, 0);
}

tree::TerminalNode* SpenatParser::TimeoutTransitionDeclContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

SpenatParser::TimeoutTransitionBodyContext* SpenatParser::TimeoutTransitionDeclContext::timeoutTransitionBody() {
  return getRuleContext<SpenatParser::TimeoutTransitionBodyContext>(0);
}

tree::TerminalNode* SpenatParser::TimeoutTransitionDeclContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}


size_t SpenatParser::TimeoutTransitionDeclContext::getRuleIndex() const {
  return SpenatParser::RuleTimeoutTransitionDecl;
}

void SpenatParser::TimeoutTransitionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeoutTransitionDecl(this);
}

void SpenatParser::TimeoutTransitionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeoutTransitionDecl(this);
}

SpenatParser::TimeoutTransitionDeclContext* SpenatParser::timeoutTransitionDecl() {
  TimeoutTransitionDeclContext *_localctx = _tracker.createInstance<TimeoutTransitionDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, SpenatParser::RuleTimeoutTransitionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(SpenatParser::TimeoutTransitionID);
    setState(249);
    match(SpenatParser::LBRACE);
    setState(250);
    timeoutTransitionBody();
    setState(251);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeoutTransitionBodyContext ------------------------------------------------------------------

SpenatParser::TimeoutTransitionBodyContext::TimeoutTransitionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::NameDeclContext* SpenatParser::TimeoutTransitionBodyContext::nameDecl() {
  return getRuleContext<SpenatParser::NameDeclContext>(0);
}

SpenatParser::TimeoutDeclContext* SpenatParser::TimeoutTransitionBodyContext::timeoutDecl() {
  return getRuleContext<SpenatParser::TimeoutDeclContext>(0);
}

SpenatParser::GuardDeclContext* SpenatParser::TimeoutTransitionBodyContext::guardDecl() {
  return getRuleContext<SpenatParser::GuardDeclContext>(0);
}

SpenatParser::ActionDeclContext* SpenatParser::TimeoutTransitionBodyContext::actionDecl() {
  return getRuleContext<SpenatParser::ActionDeclContext>(0);
}

SpenatParser::PreDeclContext* SpenatParser::TimeoutTransitionBodyContext::preDecl() {
  return getRuleContext<SpenatParser::PreDeclContext>(0);
}

SpenatParser::PostDeclContext* SpenatParser::TimeoutTransitionBodyContext::postDecl() {
  return getRuleContext<SpenatParser::PostDeclContext>(0);
}


size_t SpenatParser::TimeoutTransitionBodyContext::getRuleIndex() const {
  return SpenatParser::RuleTimeoutTransitionBody;
}

void SpenatParser::TimeoutTransitionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeoutTransitionBody(this);
}

void SpenatParser::TimeoutTransitionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeoutTransitionBody(this);
}

SpenatParser::TimeoutTransitionBodyContext* SpenatParser::timeoutTransitionBody() {
  TimeoutTransitionBodyContext *_localctx = _tracker.createInstance<TimeoutTransitionBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, SpenatParser::RuleTimeoutTransitionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    nameDecl();
    setState(256);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ValueID: {
        setState(254);
        timeoutDecl();
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::GuardID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::GuardID: {
        setState(258);
        guardDecl();
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID: {
        setState(262);
        actionDecl();
        break;
      }

      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(268);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::PreID: {
        setState(266);
        preDecl();
        break;
      }

      case SpenatParser::PostID:
      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(272);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::PostID: {
        setState(270);
        postDecl();
        break;
      }

      case SpenatParser::RBRACE: {
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

//----------------- RefSignalDeclContext ------------------------------------------------------------------

SpenatParser::RefSignalDeclContext::RefSignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::RefSignalDeclContext::RefSignalID() {
  return getToken(SpenatParser::RefSignalID, 0);
}

tree::TerminalNode* SpenatParser::RefSignalDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

SpenatParser::ContextIDContext* SpenatParser::RefSignalDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::RefSignalDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::RefSignalDeclContext::getRuleIndex() const {
  return SpenatParser::RuleRefSignalDecl;
}

void SpenatParser::RefSignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRefSignalDecl(this);
}

void SpenatParser::RefSignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRefSignalDecl(this);
}

SpenatParser::RefSignalDeclContext* SpenatParser::refSignalDecl() {
  RefSignalDeclContext *_localctx = _tracker.createInstance<RefSignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, SpenatParser::RuleRefSignalDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(SpenatParser::RefSignalID);
    setState(275);
    match(SpenatParser::COLON);
    setState(276);
    contextID();
    setState(277);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RefPortDeclContext ------------------------------------------------------------------

SpenatParser::RefPortDeclContext::RefPortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::RefPortDeclContext::RefPortID() {
  return getToken(SpenatParser::RefPortID, 0);
}

tree::TerminalNode* SpenatParser::RefPortDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

SpenatParser::ContextIDContext* SpenatParser::RefPortDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::RefPortDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::RefPortDeclContext::getRuleIndex() const {
  return SpenatParser::RuleRefPortDecl;
}

void SpenatParser::RefPortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRefPortDecl(this);
}

void SpenatParser::RefPortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRefPortDecl(this);
}

SpenatParser::RefPortDeclContext* SpenatParser::refPortDecl() {
  RefPortDeclContext *_localctx = _tracker.createInstance<RefPortDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, SpenatParser::RuleRefPortDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(SpenatParser::RefPortID);
    setState(280);
    match(SpenatParser::COLON);
    setState(281);
    contextID();
    setState(282);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreDeclContext ------------------------------------------------------------------

SpenatParser::PreDeclContext::PreDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::PreDeclContext::PreID() {
  return getToken(SpenatParser::PreID, 0);
}

tree::TerminalNode* SpenatParser::PreDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::PreDeclContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::PreDeclContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

tree::TerminalNode* SpenatParser::PreDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> SpenatParser::PreDeclContext::COMMA() {
  return getTokens(SpenatParser::COMMA);
}

tree::TerminalNode* SpenatParser::PreDeclContext::COMMA(size_t i) {
  return getToken(SpenatParser::COMMA, i);
}


size_t SpenatParser::PreDeclContext::getRuleIndex() const {
  return SpenatParser::RulePreDecl;
}

void SpenatParser::PreDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreDecl(this);
}

void SpenatParser::PreDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreDecl(this);
}

SpenatParser::PreDeclContext* SpenatParser::preDecl() {
  PreDeclContext *_localctx = _tracker.createInstance<PreDeclContext>(_ctx, getState());
  enterRule(_localctx, 32, SpenatParser::RulePreDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(SpenatParser::PreID);
    setState(285);
    match(SpenatParser::COLON);
    setState(286);
    contextID();
    setState(291);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::COMMA) {
      setState(287);
      match(SpenatParser::COMMA);
      setState(288);
      contextID();
      setState(293);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(294);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostDeclContext ------------------------------------------------------------------

SpenatParser::PostDeclContext::PostDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::PostDeclContext::PostID() {
  return getToken(SpenatParser::PostID, 0);
}

tree::TerminalNode* SpenatParser::PostDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::PostDeclContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::PostDeclContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

tree::TerminalNode* SpenatParser::PostDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> SpenatParser::PostDeclContext::COMMA() {
  return getTokens(SpenatParser::COMMA);
}

tree::TerminalNode* SpenatParser::PostDeclContext::COMMA(size_t i) {
  return getToken(SpenatParser::COMMA, i);
}


size_t SpenatParser::PostDeclContext::getRuleIndex() const {
  return SpenatParser::RulePostDecl;
}

void SpenatParser::PostDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostDecl(this);
}

void SpenatParser::PostDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostDecl(this);
}

SpenatParser::PostDeclContext* SpenatParser::postDecl() {
  PostDeclContext *_localctx = _tracker.createInstance<PostDeclContext>(_ctx, getState());
  enterRule(_localctx, 34, SpenatParser::RulePostDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(SpenatParser::PostID);
    setState(297);
    match(SpenatParser::COLON);
    setState(298);
    contextID();
    setState(303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::COMMA) {
      setState(299);
      match(SpenatParser::COMMA);
      setState(300);
      contextID();
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(306);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeoutDeclContext ------------------------------------------------------------------

SpenatParser::TimeoutDeclContext::TimeoutDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::TimeoutDeclContext::ValueID() {
  return getToken(SpenatParser::ValueID, 0);
}

tree::TerminalNode* SpenatParser::TimeoutDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

tree::TerminalNode* SpenatParser::TimeoutDeclContext::REAL() {
  return getToken(SpenatParser::REAL, 0);
}

tree::TerminalNode* SpenatParser::TimeoutDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::TimeoutDeclContext::getRuleIndex() const {
  return SpenatParser::RuleTimeoutDecl;
}

void SpenatParser::TimeoutDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeoutDecl(this);
}

void SpenatParser::TimeoutDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeoutDecl(this);
}

SpenatParser::TimeoutDeclContext* SpenatParser::timeoutDecl() {
  TimeoutDeclContext *_localctx = _tracker.createInstance<TimeoutDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, SpenatParser::RuleTimeoutDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    match(SpenatParser::ValueID);
    setState(309);
    match(SpenatParser::COLON);
    setState(310);
    match(SpenatParser::REAL);
    setState(311);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitialDeclContext ------------------------------------------------------------------

SpenatParser::InitialDeclContext::InitialDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::InitialDeclContext::InitialID() {
  return getToken(SpenatParser::InitialID, 0);
}

tree::TerminalNode* SpenatParser::InitialDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

tree::TerminalNode* SpenatParser::InitialDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

tree::TerminalNode* SpenatParser::InitialDeclContext::TrueID() {
  return getToken(SpenatParser::TrueID, 0);
}

tree::TerminalNode* SpenatParser::InitialDeclContext::FalseID() {
  return getToken(SpenatParser::FalseID, 0);
}


size_t SpenatParser::InitialDeclContext::getRuleIndex() const {
  return SpenatParser::RuleInitialDecl;
}

void SpenatParser::InitialDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitialDecl(this);
}

void SpenatParser::InitialDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitialDecl(this);
}

SpenatParser::InitialDeclContext* SpenatParser::initialDecl() {
  InitialDeclContext *_localctx = _tracker.createInstance<InitialDeclContext>(_ctx, getState());
  enterRule(_localctx, 38, SpenatParser::RuleInitialDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    match(SpenatParser::InitialID);
    setState(314);
    match(SpenatParser::COLON);
    setState(315);
    _la = _input->LA(1);
    if (!(_la == SpenatParser::TrueID

    || _la == SpenatParser::FalseID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(316);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

SpenatParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::ContextIDContext* SpenatParser::FunctionCallContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::FunctionCallContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

SpenatParser::FunctionCallBodyContext* SpenatParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<SpenatParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* SpenatParser::FunctionCallContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}


size_t SpenatParser::FunctionCallContext::getRuleIndex() const {
  return SpenatParser::RuleFunctionCall;
}

void SpenatParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void SpenatParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

SpenatParser::FunctionCallContext* SpenatParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 40, SpenatParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    contextID();
    setState(319);
    match(SpenatParser::LPAREN);
    setState(320);
    functionCallBody();
    setState(321);
    match(SpenatParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextIDContext ------------------------------------------------------------------

SpenatParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ContextIDContext::ID() {
  return getToken(SpenatParser::ID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::NameID() {
  return getToken(SpenatParser::NameID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::LabelID() {
  return getToken(SpenatParser::LabelID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::EnabledID() {
  return getToken(SpenatParser::EnabledID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::TypeID() {
  return getToken(SpenatParser::TypeID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::MessageTrigger() {
  return getToken(SpenatParser::MessageTrigger, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::TriggerID() {
  return getToken(SpenatParser::TriggerID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::AttributeID() {
  return getToken(SpenatParser::AttributeID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::FunctionID() {
  return getToken(SpenatParser::FunctionID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::SignalID() {
  return getToken(SpenatParser::SignalID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::PortID() {
  return getToken(SpenatParser::PortID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::ImportID() {
  return getToken(SpenatParser::ImportID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::FromID() {
  return getToken(SpenatParser::FromID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::ToID() {
  return getToken(SpenatParser::ToID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::SendID() {
  return getToken(SpenatParser::SendID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::AsID() {
  return getToken(SpenatParser::AsID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::ActionID() {
  return getToken(SpenatParser::ActionID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::SpenatID() {
  return getToken(SpenatParser::SpenatID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::PlaceID() {
  return getToken(SpenatParser::PlaceID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::SignalTransitionID() {
  return getToken(SpenatParser::SignalTransitionID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::TimeoutTransitionID() {
  return getToken(SpenatParser::TimeoutTransitionID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::RefSignalID() {
  return getToken(SpenatParser::RefSignalID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::RefPortID() {
  return getToken(SpenatParser::RefPortID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::ValueID() {
  return getToken(SpenatParser::ValueID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::GuardID() {
  return getToken(SpenatParser::GuardID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::InitialID() {
  return getToken(SpenatParser::InitialID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::PreID() {
  return getToken(SpenatParser::PreID, 0);
}

tree::TerminalNode* SpenatParser::ContextIDContext::PostID() {
  return getToken(SpenatParser::PostID, 0);
}


size_t SpenatParser::ContextIDContext::getRuleIndex() const {
  return SpenatParser::RuleContextID;
}

void SpenatParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void SpenatParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

SpenatParser::ContextIDContext* SpenatParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 42, SpenatParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(350);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(323);
        match(SpenatParser::ID);
        break;
      }

      case SpenatParser::NameID: {
        enterOuterAlt(_localctx, 2);
        setState(324);
        match(SpenatParser::NameID);
        break;
      }

      case SpenatParser::LabelID: {
        enterOuterAlt(_localctx, 3);
        setState(325);
        match(SpenatParser::LabelID);
        break;
      }

      case SpenatParser::EnabledID: {
        enterOuterAlt(_localctx, 4);
        setState(326);
        match(SpenatParser::EnabledID);
        break;
      }

      case SpenatParser::TypeID: {
        enterOuterAlt(_localctx, 5);
        setState(327);
        match(SpenatParser::TypeID);
        break;
      }

      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger: {
        enterOuterAlt(_localctx, 6);
        setState(328);
        _la = _input->LA(1);
        if (!(_la == SpenatParser::TriggerID

        || _la == SpenatParser::MessageTrigger)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case SpenatParser::AttributeID: {
        enterOuterAlt(_localctx, 7);
        setState(329);
        match(SpenatParser::AttributeID);
        break;
      }

      case SpenatParser::FunctionID: {
        enterOuterAlt(_localctx, 8);
        setState(330);
        match(SpenatParser::FunctionID);
        break;
      }

      case SpenatParser::SignalID: {
        enterOuterAlt(_localctx, 9);
        setState(331);
        match(SpenatParser::SignalID);
        break;
      }

      case SpenatParser::PortID: {
        enterOuterAlt(_localctx, 10);
        setState(332);
        match(SpenatParser::PortID);
        break;
      }

      case SpenatParser::ImportID: {
        enterOuterAlt(_localctx, 11);
        setState(333);
        match(SpenatParser::ImportID);
        break;
      }

      case SpenatParser::FromID: {
        enterOuterAlt(_localctx, 12);
        setState(334);
        match(SpenatParser::FromID);
        break;
      }

      case SpenatParser::ToID: {
        enterOuterAlt(_localctx, 13);
        setState(335);
        match(SpenatParser::ToID);
        break;
      }

      case SpenatParser::SendID: {
        enterOuterAlt(_localctx, 14);
        setState(336);
        match(SpenatParser::SendID);
        break;
      }

      case SpenatParser::AsID: {
        enterOuterAlt(_localctx, 15);
        setState(337);
        match(SpenatParser::AsID);
        break;
      }

      case SpenatParser::ActionID: {
        enterOuterAlt(_localctx, 16);
        setState(338);
        match(SpenatParser::ActionID);
        break;
      }

      case SpenatParser::SpenatID: {
        enterOuterAlt(_localctx, 17);
        setState(339);
        match(SpenatParser::SpenatID);
        break;
      }

      case SpenatParser::PlaceID: {
        enterOuterAlt(_localctx, 18);
        setState(340);
        match(SpenatParser::PlaceID);
        break;
      }

      case SpenatParser::SignalTransitionID: {
        enterOuterAlt(_localctx, 19);
        setState(341);
        match(SpenatParser::SignalTransitionID);
        break;
      }

      case SpenatParser::TimeoutTransitionID: {
        enterOuterAlt(_localctx, 20);
        setState(342);
        match(SpenatParser::TimeoutTransitionID);
        break;
      }

      case SpenatParser::RefSignalID: {
        enterOuterAlt(_localctx, 21);
        setState(343);
        match(SpenatParser::RefSignalID);
        break;
      }

      case SpenatParser::RefPortID: {
        enterOuterAlt(_localctx, 22);
        setState(344);
        match(SpenatParser::RefPortID);
        break;
      }

      case SpenatParser::ValueID: {
        enterOuterAlt(_localctx, 23);
        setState(345);
        match(SpenatParser::ValueID);
        break;
      }

      case SpenatParser::GuardID: {
        enterOuterAlt(_localctx, 24);
        setState(346);
        match(SpenatParser::GuardID);
        break;
      }

      case SpenatParser::InitialID: {
        enterOuterAlt(_localctx, 25);
        setState(347);
        match(SpenatParser::InitialID);
        break;
      }

      case SpenatParser::PreID: {
        enterOuterAlt(_localctx, 26);
        setState(348);
        match(SpenatParser::PreID);
        break;
      }

      case SpenatParser::PostID: {
        enterOuterAlt(_localctx, 27);
        setState(349);
        match(SpenatParser::PostID);
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

SpenatParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SpenatParser::ComponentIdPathContext::DOT() {
  return getTokens(SpenatParser::DOT);
}

tree::TerminalNode* SpenatParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(SpenatParser::DOT, i);
}


size_t SpenatParser::ComponentIdPathContext::getRuleIndex() const {
  return SpenatParser::RuleComponentIdPath;
}

void SpenatParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void SpenatParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

SpenatParser::ComponentIdPathContext* SpenatParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 44, SpenatParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    contextID();
    setState(357);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::DOT) {
      setState(353);
      match(SpenatParser::DOT);
      setState(354);
      contextID();
      setState(359);
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

SpenatParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::SignalIdPathContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SpenatParser::SignalIdPathContext::DOT() {
  return getTokens(SpenatParser::DOT);
}

tree::TerminalNode* SpenatParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(SpenatParser::DOT, i);
}


size_t SpenatParser::SignalIdPathContext::getRuleIndex() const {
  return SpenatParser::RuleSignalIdPath;
}

void SpenatParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void SpenatParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

SpenatParser::SignalIdPathContext* SpenatParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 46, SpenatParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    contextID();
    setState(365);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::DOT) {
      setState(361);
      match(SpenatParser::DOT);
      setState(362);
      contextID();
      setState(367);
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

SpenatParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::AttributeNameContext* SpenatParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<SpenatParser::AttributeNameContext>(0);
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SpenatParser::AttributeIdPathContext::DOT() {
  return getTokens(SpenatParser::DOT);
}

tree::TerminalNode* SpenatParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(SpenatParser::DOT, i);
}


size_t SpenatParser::AttributeIdPathContext::getRuleIndex() const {
  return SpenatParser::RuleAttributeIdPath;
}

void SpenatParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void SpenatParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

SpenatParser::AttributeIdPathContext* SpenatParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 48, SpenatParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(368);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(369);
      contextID();
      setState(374);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SpenatParser::DOT) {
        setState(370);
        match(SpenatParser::DOT);
        setState(371);
        contextID();
        setState(376);
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

SpenatParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::SignalIdPathContext* SpenatParser::SignalSendContext::signalIdPath() {
  return getRuleContext<SpenatParser::SignalIdPathContext>(0);
}

tree::TerminalNode* SpenatParser::SignalSendContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

SpenatParser::FunctionCallBodyContext* SpenatParser::SignalSendContext::functionCallBody() {
  return getRuleContext<SpenatParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* SpenatParser::SignalSendContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}


size_t SpenatParser::SignalSendContext::getRuleIndex() const {
  return SpenatParser::RuleSignalSend;
}

void SpenatParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void SpenatParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

SpenatParser::SignalSendContext* SpenatParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 50, SpenatParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    signalIdPath();
    setState(380);
    match(SpenatParser::LPAREN);
    setState(381);
    functionCallBody();
    setState(382);
    match(SpenatParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

SpenatParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SpenatParser::TypeDefDeclContext *> SpenatParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<SpenatParser::TypeDefDeclContext>();
}

SpenatParser::TypeDefDeclContext* SpenatParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<SpenatParser::TypeDefDeclContext>(i);
}

std::vector<SpenatParser::AttributeDeclContext *> SpenatParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<SpenatParser::AttributeDeclContext>();
}

SpenatParser::AttributeDeclContext* SpenatParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<SpenatParser::AttributeDeclContext>(i);
}

std::vector<SpenatParser::SignalDeclContext *> SpenatParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<SpenatParser::SignalDeclContext>();
}

SpenatParser::SignalDeclContext* SpenatParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<SpenatParser::SignalDeclContext>(i);
}


size_t SpenatParser::CommonDeclContext::getRuleIndex() const {
  return SpenatParser::RuleCommonDecl;
}

void SpenatParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void SpenatParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

SpenatParser::CommonDeclContext* SpenatParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, SpenatParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SpenatParser::TypeID)
      | (1ULL << SpenatParser::AttributeID)
      | (1ULL << SpenatParser::SignalID))) != 0)) {
      setState(387);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SpenatParser::TypeID: {
          setState(384);
          typeDefDecl();
          break;
        }

        case SpenatParser::AttributeID: {
          setState(385);
          attributeDecl();
          break;
        }

        case SpenatParser::SignalID: {
          setState(386);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(391);
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

SpenatParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::ImportPathBodyContext* SpenatParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<SpenatParser::ImportPathBodyContext>(0);
}

SpenatParser::ImportPathDeclContext* SpenatParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<SpenatParser::ImportPathDeclContext>(0);
}


size_t SpenatParser::ImportPathDeclContext::getRuleIndex() const {
  return SpenatParser::RuleImportPathDecl;
}

void SpenatParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void SpenatParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

SpenatParser::ImportPathDeclContext* SpenatParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 54, SpenatParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(396);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(392);
      importPathBody();
      setState(393);
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

SpenatParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ImportPathBodyContext::ImportID() {
  return getToken(SpenatParser::ImportID, 0);
}

tree::TerminalNode* SpenatParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(SpenatParser::LESSTHAN, 0);
}

SpenatParser::ImportFileBodyContext* SpenatParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<SpenatParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* SpenatParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(SpenatParser::GREATERTHAN, 0);
}

SpenatParser::ImportAsContext* SpenatParser::ImportPathBodyContext::importAs() {
  return getRuleContext<SpenatParser::ImportAsContext>(0);
}


size_t SpenatParser::ImportPathBodyContext::getRuleIndex() const {
  return SpenatParser::RuleImportPathBody;
}

void SpenatParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void SpenatParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

SpenatParser::ImportPathBodyContext* SpenatParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 56, SpenatParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    match(SpenatParser::ImportID);
    setState(399);
    match(SpenatParser::LESSTHAN);
    setState(400);
    importFileBody();
    setState(401);
    match(SpenatParser::GREATERTHAN);
    setState(402);
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

SpenatParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

tree::TerminalNode* SpenatParser::ImportFileBodyContext::DOT() {
  return getToken(SpenatParser::DOT, 0);
}

tree::TerminalNode* SpenatParser::ImportFileBodyContext::RANGE() {
  return getToken(SpenatParser::RANGE, 0);
}

tree::TerminalNode* SpenatParser::ImportFileBodyContext::DIV() {
  return getToken(SpenatParser::DIV, 0);
}

SpenatParser::ImportFileBodyContext* SpenatParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<SpenatParser::ImportFileBodyContext>(0);
}


size_t SpenatParser::ImportFileBodyContext::getRuleIndex() const {
  return SpenatParser::RuleImportFileBody;
}

void SpenatParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void SpenatParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

SpenatParser::ImportFileBodyContext* SpenatParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 58, SpenatParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(415);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(404);
      contextID();
      setState(405);
      match(SpenatParser::DOT);
      setState(406);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(408);
      match(SpenatParser::RANGE);
      setState(409);
      match(SpenatParser::DIV);
      setState(410);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(411);
      contextID();
      setState(412);
      match(SpenatParser::DIV);
      setState(413);
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

SpenatParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ImportAsContext::AsID() {
  return getToken(SpenatParser::AsID, 0);
}

SpenatParser::ContextIDContext* SpenatParser::ImportAsContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}


size_t SpenatParser::ImportAsContext::getRuleIndex() const {
  return SpenatParser::RuleImportAs;
}

void SpenatParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void SpenatParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

SpenatParser::ImportAsContext* SpenatParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 60, SpenatParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(420);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(417);
        match(SpenatParser::AsID);
        setState(418);
        contextID();
        break;
      }

      case SpenatParser::ImportID: {
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

SpenatParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::TypeDefDeclContext::TypeID() {
  return getToken(SpenatParser::TypeID, 0);
}

SpenatParser::TypeDeclContext* SpenatParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<SpenatParser::TypeDeclContext>(0);
}

SpenatParser::ContextIDContext* SpenatParser::TypeDefDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::TypeDefDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::TypeDefDeclContext::getRuleIndex() const {
  return SpenatParser::RuleTypeDefDecl;
}

void SpenatParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void SpenatParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

SpenatParser::TypeDefDeclContext* SpenatParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 62, SpenatParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(422);
    match(SpenatParser::TypeID);
    setState(423);
    typeDecl();
    setState(424);
    contextID();
    setState(425);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

SpenatParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::IntTypeDeclContext* SpenatParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<SpenatParser::IntTypeDeclContext>(0);
}

SpenatParser::RealTypeDeclContext* SpenatParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<SpenatParser::RealTypeDeclContext>(0);
}

SpenatParser::EnumTypeDeclContext* SpenatParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<SpenatParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* SpenatParser::TypeDeclContext::BoolID() {
  return getToken(SpenatParser::BoolID, 0);
}

tree::TerminalNode* SpenatParser::TypeDeclContext::StringID() {
  return getToken(SpenatParser::StringID, 0);
}

SpenatParser::ContextIDContext* SpenatParser::TypeDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}


size_t SpenatParser::TypeDeclContext::getRuleIndex() const {
  return SpenatParser::RuleTypeDecl;
}

void SpenatParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void SpenatParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

SpenatParser::TypeDeclContext* SpenatParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 64, SpenatParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(433);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(427);
        intTypeDecl();
        break;
      }

      case SpenatParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(428);
        realTypeDecl();
        break;
      }

      case SpenatParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(429);
        enumTypeDecl();
        break;
      }

      case SpenatParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(430);
        match(SpenatParser::BoolID);
        break;
      }

      case SpenatParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(431);
        match(SpenatParser::StringID);
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(432);
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

SpenatParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::IntTypeDeclContext::IntID() {
  return getToken(SpenatParser::IntID, 0);
}

tree::TerminalNode* SpenatParser::IntTypeDeclContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> SpenatParser::IntTypeDeclContext::INT() {
  return getTokens(SpenatParser::INT);
}

tree::TerminalNode* SpenatParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(SpenatParser::INT, i);
}

tree::TerminalNode* SpenatParser::IntTypeDeclContext::RANGE() {
  return getToken(SpenatParser::RANGE, 0);
}

tree::TerminalNode* SpenatParser::IntTypeDeclContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}


size_t SpenatParser::IntTypeDeclContext::getRuleIndex() const {
  return SpenatParser::RuleIntTypeDecl;
}

void SpenatParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void SpenatParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

SpenatParser::IntTypeDeclContext* SpenatParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, SpenatParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    match(SpenatParser::IntID);
    setState(442);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::LPAREN: {
        setState(436);
        match(SpenatParser::LPAREN);
        setState(437);
        match(SpenatParser::INT);
        setState(438);
        match(SpenatParser::RANGE);
        setState(439);
        match(SpenatParser::INT);
        setState(440);
        match(SpenatParser::RPAREN);
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::ID: {
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

SpenatParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::RealTypeDeclContext::RealID() {
  return getToken(SpenatParser::RealID, 0);
}

tree::TerminalNode* SpenatParser::RealTypeDeclContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> SpenatParser::RealTypeDeclContext::REAL() {
  return getTokens(SpenatParser::REAL);
}

tree::TerminalNode* SpenatParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(SpenatParser::REAL, i);
}

tree::TerminalNode* SpenatParser::RealTypeDeclContext::RANGE() {
  return getToken(SpenatParser::RANGE, 0);
}

tree::TerminalNode* SpenatParser::RealTypeDeclContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}


size_t SpenatParser::RealTypeDeclContext::getRuleIndex() const {
  return SpenatParser::RuleRealTypeDecl;
}

void SpenatParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void SpenatParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

SpenatParser::RealTypeDeclContext* SpenatParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 68, SpenatParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    match(SpenatParser::RealID);
    setState(451);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::LPAREN: {
        setState(445);
        match(SpenatParser::LPAREN);
        setState(446);
        match(SpenatParser::REAL);
        setState(447);
        match(SpenatParser::RANGE);
        setState(448);
        match(SpenatParser::REAL);
        setState(449);
        match(SpenatParser::RPAREN);
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::ID: {
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

SpenatParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::EnumTypeDeclContext::EnumID() {
  return getToken(SpenatParser::EnumID, 0);
}

tree::TerminalNode* SpenatParser::EnumTypeDeclContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

tree::TerminalNode* SpenatParser::EnumTypeDeclContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> SpenatParser::EnumTypeDeclContext::COMMA() {
  return getTokens(SpenatParser::COMMA);
}

tree::TerminalNode* SpenatParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(SpenatParser::COMMA, i);
}


size_t SpenatParser::EnumTypeDeclContext::getRuleIndex() const {
  return SpenatParser::RuleEnumTypeDecl;
}

void SpenatParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void SpenatParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

SpenatParser::EnumTypeDeclContext* SpenatParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 70, SpenatParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(453);
    match(SpenatParser::EnumID);
    setState(454);
    match(SpenatParser::LPAREN);
    setState(455);
    contextID();
    setState(460);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::COMMA) {
      setState(456);
      match(SpenatParser::COMMA);
      setState(457);
      contextID();
      setState(462);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(463);
    match(SpenatParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

SpenatParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::AttributeDeclContext::AttributeID() {
  return getToken(SpenatParser::AttributeID, 0);
}

SpenatParser::TypeDeclContext* SpenatParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<SpenatParser::TypeDeclContext>(0);
}

SpenatParser::ContextIDContext* SpenatParser::AttributeDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::AttributeDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

tree::TerminalNode* SpenatParser::AttributeDeclContext::ASSIGN() {
  return getToken(SpenatParser::ASSIGN, 0);
}

SpenatParser::LiteralValueContext* SpenatParser::AttributeDeclContext::literalValue() {
  return getRuleContext<SpenatParser::LiteralValueContext>(0);
}


size_t SpenatParser::AttributeDeclContext::getRuleIndex() const {
  return SpenatParser::RuleAttributeDecl;
}

void SpenatParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void SpenatParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

SpenatParser::AttributeDeclContext* SpenatParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 72, SpenatParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(465);
    match(SpenatParser::AttributeID);
    setState(466);
    typeDecl();
    setState(467);
    contextID();
    setState(470);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SpenatParser::ASSIGN) {
      setState(468);
      match(SpenatParser::ASSIGN);
      setState(469);
      literalValue();
    }
    setState(472);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

SpenatParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::LiteralValueContext::INT() {
  return getToken(SpenatParser::INT, 0);
}

tree::TerminalNode* SpenatParser::LiteralValueContext::REAL() {
  return getToken(SpenatParser::REAL, 0);
}

tree::TerminalNode* SpenatParser::LiteralValueContext::STRING() {
  return getToken(SpenatParser::STRING, 0);
}

tree::TerminalNode* SpenatParser::LiteralValueContext::TrueID() {
  return getToken(SpenatParser::TrueID, 0);
}

tree::TerminalNode* SpenatParser::LiteralValueContext::FalseID() {
  return getToken(SpenatParser::FalseID, 0);
}

SpenatParser::ContextIDContext* SpenatParser::LiteralValueContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}


size_t SpenatParser::LiteralValueContext::getRuleIndex() const {
  return SpenatParser::RuleLiteralValue;
}

void SpenatParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void SpenatParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

SpenatParser::LiteralValueContext* SpenatParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 74, SpenatParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(480);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(474);
        match(SpenatParser::INT);
        break;
      }

      case SpenatParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(475);
        match(SpenatParser::REAL);
        break;
      }

      case SpenatParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(476);
        match(SpenatParser::STRING);
        break;
      }

      case SpenatParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(477);
        match(SpenatParser::TrueID);
        break;
      }

      case SpenatParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(478);
        match(SpenatParser::FalseID);
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(479);
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

SpenatParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::TriggerDeclContext* SpenatParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<SpenatParser::TriggerDeclContext>(0);
}

SpenatParser::ContextIDContext* SpenatParser::SignalParamNameContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}


size_t SpenatParser::SignalParamNameContext::getRuleIndex() const {
  return SpenatParser::RuleSignalParamName;
}

void SpenatParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void SpenatParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

SpenatParser::SignalParamNameContext* SpenatParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 76, SpenatParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    triggerDecl();
    setState(483);
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

SpenatParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::ContextIDContext* SpenatParser::AttributeNameContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

SpenatParser::ThisDeclContext* SpenatParser::AttributeNameContext::thisDecl() {
  return getRuleContext<SpenatParser::ThisDeclContext>(0);
}


size_t SpenatParser::AttributeNameContext::getRuleIndex() const {
  return SpenatParser::RuleAttributeName;
}

void SpenatParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void SpenatParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

SpenatParser::AttributeNameContext* SpenatParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 78, SpenatParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ThisID: {
        setState(485);
        thisDecl();
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(489);
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

SpenatParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ToPortNameContext::ToID() {
  return getToken(SpenatParser::ToID, 0);
}

SpenatParser::ContextIDContext* SpenatParser::ToPortNameContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}


size_t SpenatParser::ToPortNameContext::getRuleIndex() const {
  return SpenatParser::RuleToPortName;
}

void SpenatParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void SpenatParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

SpenatParser::ToPortNameContext* SpenatParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 80, SpenatParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    match(SpenatParser::ToID);
    setState(492);
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

SpenatParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::AttributeNameContext* SpenatParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<SpenatParser::AttributeNameContext>(0);
}

tree::TerminalNode* SpenatParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(SpenatParser::ASSIGN, 0);
}

SpenatParser::ExpressionContext* SpenatParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}

tree::TerminalNode* SpenatParser::AttributeAssignStatementContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::AttributeAssignStatementContext::getRuleIndex() const {
  return SpenatParser::RuleAttributeAssignStatement;
}

void SpenatParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void SpenatParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

SpenatParser::AttributeAssignStatementContext* SpenatParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, SpenatParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(494);
    attributeName();
    setState(495);
    match(SpenatParser::ASSIGN);
    setState(496);
    expression();
    setState(497);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

SpenatParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::TypeDeclContext* SpenatParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<SpenatParser::TypeDeclContext>(0);
}

SpenatParser::ContextIDContext* SpenatParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::LocalAssignStatementContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

tree::TerminalNode* SpenatParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(SpenatParser::ASSIGN, 0);
}

SpenatParser::ExpressionContext* SpenatParser::LocalAssignStatementContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}


size_t SpenatParser::LocalAssignStatementContext::getRuleIndex() const {
  return SpenatParser::RuleLocalAssignStatement;
}

void SpenatParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void SpenatParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

SpenatParser::LocalAssignStatementContext* SpenatParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, SpenatParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    typeDecl();
    setState(500);
    contextID();
    setState(504);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ASSIGN: {
        setState(501);
        match(SpenatParser::ASSIGN);
        setState(502);
        expression();
        break;
      }

      case SpenatParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(506);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

SpenatParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::SendToStatementContext::SendID() {
  return getToken(SpenatParser::SendID, 0);
}

SpenatParser::SignalSendContext* SpenatParser::SendToStatementContext::signalSend() {
  return getRuleContext<SpenatParser::SignalSendContext>(0);
}

tree::TerminalNode* SpenatParser::SendToStatementContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

SpenatParser::ToPortNameContext* SpenatParser::SendToStatementContext::toPortName() {
  return getRuleContext<SpenatParser::ToPortNameContext>(0);
}


size_t SpenatParser::SendToStatementContext::getRuleIndex() const {
  return SpenatParser::RuleSendToStatement;
}

void SpenatParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void SpenatParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

SpenatParser::SendToStatementContext* SpenatParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 86, SpenatParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(508);
    match(SpenatParser::SendID);
    setState(509);
    signalSend();
    setState(512);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ToID: {
        setState(510);
        toPortName();
        break;
      }

      case SpenatParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(514);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

SpenatParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::AttributeAssignStatementContext* SpenatParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<SpenatParser::AttributeAssignStatementContext>(0);
}

SpenatParser::SendToStatementContext* SpenatParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<SpenatParser::SendToStatementContext>(0);
}


size_t SpenatParser::SingleAssignmentContext::getRuleIndex() const {
  return SpenatParser::RuleSingleAssignment;
}

void SpenatParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void SpenatParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

SpenatParser::SingleAssignmentContext* SpenatParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 88, SpenatParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(518);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(516);
      attributeAssignStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(517);
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

SpenatParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::MultiAssignmentContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

tree::TerminalNode* SpenatParser::MultiAssignmentContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}

std::vector<SpenatParser::SingleAssignmentContext *> SpenatParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<SpenatParser::SingleAssignmentContext>();
}

SpenatParser::SingleAssignmentContext* SpenatParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<SpenatParser::SingleAssignmentContext>(i);
}


size_t SpenatParser::MultiAssignmentContext::getRuleIndex() const {
  return SpenatParser::RuleMultiAssignment;
}

void SpenatParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void SpenatParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

SpenatParser::MultiAssignmentContext* SpenatParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 90, SpenatParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    match(SpenatParser::LBRACE);
    setState(524);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SpenatParser::ActionID)
      | (1ULL << SpenatParser::SpenatID)
      | (1ULL << SpenatParser::PlaceID)
      | (1ULL << SpenatParser::RefSignalID)
      | (1ULL << SpenatParser::RefPortID)
      | (1ULL << SpenatParser::ValueID)
      | (1ULL << SpenatParser::GuardID)
      | (1ULL << SpenatParser::InitialID)
      | (1ULL << SpenatParser::PreID)
      | (1ULL << SpenatParser::PostID)
      | (1ULL << SpenatParser::NameID)
      | (1ULL << SpenatParser::LabelID)
      | (1ULL << SpenatParser::EnabledID)
      | (1ULL << SpenatParser::TypeID)
      | (1ULL << SpenatParser::TriggerID)
      | (1ULL << SpenatParser::MessageTrigger)
      | (1ULL << SpenatParser::ThisID)
      | (1ULL << SpenatParser::SignalTransitionID)
      | (1ULL << SpenatParser::TimeoutTransitionID)
      | (1ULL << SpenatParser::AttributeID)
      | (1ULL << SpenatParser::SignalID)
      | (1ULL << SpenatParser::PortID)
      | (1ULL << SpenatParser::ImportID)
      | (1ULL << SpenatParser::FromID)
      | (1ULL << SpenatParser::ToID)
      | (1ULL << SpenatParser::SendID)
      | (1ULL << SpenatParser::FunctionID)
      | (1ULL << SpenatParser::AsID)
      | (1ULL << SpenatParser::ID))) != 0)) {
      setState(521);
      singleAssignment();
      setState(526);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(527);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

SpenatParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::SignalDeclContext::SignalID() {
  return getToken(SpenatParser::SignalID, 0);
}

SpenatParser::ContextIDContext* SpenatParser::SignalDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::SignalDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

tree::TerminalNode* SpenatParser::SignalDeclContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

tree::TerminalNode* SpenatParser::SignalDeclContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}

std::vector<SpenatParser::ParamDeclContext *> SpenatParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<SpenatParser::ParamDeclContext>();
}

SpenatParser::ParamDeclContext* SpenatParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<SpenatParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> SpenatParser::SignalDeclContext::COMMA() {
  return getTokens(SpenatParser::COMMA);
}

tree::TerminalNode* SpenatParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(SpenatParser::COMMA, i);
}


size_t SpenatParser::SignalDeclContext::getRuleIndex() const {
  return SpenatParser::RuleSignalDecl;
}

void SpenatParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void SpenatParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

SpenatParser::SignalDeclContext* SpenatParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 92, SpenatParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    match(SpenatParser::SignalID);
    setState(530);
    contextID();
    setState(545);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::LPAREN: {
        setState(531);
        match(SpenatParser::LPAREN);
        setState(541);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SpenatParser::ActionID:
          case SpenatParser::SpenatID:
          case SpenatParser::PlaceID:
          case SpenatParser::RefSignalID:
          case SpenatParser::RefPortID:
          case SpenatParser::ValueID:
          case SpenatParser::GuardID:
          case SpenatParser::InitialID:
          case SpenatParser::PreID:
          case SpenatParser::PostID:
          case SpenatParser::NameID:
          case SpenatParser::LabelID:
          case SpenatParser::EnabledID:
          case SpenatParser::TypeID:
          case SpenatParser::IntID:
          case SpenatParser::RealID:
          case SpenatParser::BoolID:
          case SpenatParser::StringID:
          case SpenatParser::TriggerID:
          case SpenatParser::MessageTrigger:
          case SpenatParser::SignalTransitionID:
          case SpenatParser::TimeoutTransitionID:
          case SpenatParser::EnumID:
          case SpenatParser::AttributeID:
          case SpenatParser::SignalID:
          case SpenatParser::PortID:
          case SpenatParser::ImportID:
          case SpenatParser::FromID:
          case SpenatParser::ToID:
          case SpenatParser::SendID:
          case SpenatParser::FunctionID:
          case SpenatParser::AsID:
          case SpenatParser::ID: {
            setState(532);
            paramDecl();
            setState(537);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == SpenatParser::COMMA) {
              setState(533);
              match(SpenatParser::COMMA);
              setState(534);
              paramDecl();
              setState(539);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case SpenatParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(543);
        match(SpenatParser::RPAREN);
        break;
      }

      case SpenatParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(547);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

SpenatParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::TypeDeclContext* SpenatParser::ParamDeclContext::typeDecl() {
  return getRuleContext<SpenatParser::TypeDeclContext>(0);
}

SpenatParser::ContextIDContext* SpenatParser::ParamDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}


size_t SpenatParser::ParamDeclContext::getRuleIndex() const {
  return SpenatParser::RuleParamDecl;
}

void SpenatParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void SpenatParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

SpenatParser::ParamDeclContext* SpenatParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 94, SpenatParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(549);
    typeDecl();
    setState(550);
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

SpenatParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::FunctionDeclContext::FunctionID() {
  return getToken(SpenatParser::FunctionID, 0);
}

SpenatParser::TypeDeclContext* SpenatParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<SpenatParser::TypeDeclContext>(0);
}

SpenatParser::IdPathContext* SpenatParser::FunctionDeclContext::idPath() {
  return getRuleContext<SpenatParser::IdPathContext>(0);
}

tree::TerminalNode* SpenatParser::FunctionDeclContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

tree::TerminalNode* SpenatParser::FunctionDeclContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}

SpenatParser::NestedStatementBodyContext* SpenatParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<SpenatParser::NestedStatementBodyContext>(0);
}

SpenatParser::FunctionParametersContext* SpenatParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<SpenatParser::FunctionParametersContext>(0);
}


size_t SpenatParser::FunctionDeclContext::getRuleIndex() const {
  return SpenatParser::RuleFunctionDecl;
}

void SpenatParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void SpenatParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

SpenatParser::FunctionDeclContext* SpenatParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 96, SpenatParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(552);
    match(SpenatParser::FunctionID);
    setState(553);
    typeDecl();
    setState(554);
    idPath();
    setState(555);
    match(SpenatParser::LPAREN);
    setState(558);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::IntID:
      case SpenatParser::RealID:
      case SpenatParser::BoolID:
      case SpenatParser::StringID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::EnumID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::ID: {
        setState(556);
        functionParameters();
        break;
      }

      case SpenatParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(560);
    match(SpenatParser::RPAREN);
    setState(561);
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

SpenatParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SpenatParser::ParamDeclContext *> SpenatParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<SpenatParser::ParamDeclContext>();
}

SpenatParser::ParamDeclContext* SpenatParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<SpenatParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> SpenatParser::FunctionParametersContext::COMMA() {
  return getTokens(SpenatParser::COMMA);
}

tree::TerminalNode* SpenatParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(SpenatParser::COMMA, i);
}


size_t SpenatParser::FunctionParametersContext::getRuleIndex() const {
  return SpenatParser::RuleFunctionParameters;
}

void SpenatParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void SpenatParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

SpenatParser::FunctionParametersContext* SpenatParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 98, SpenatParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(563);
    paramDecl();
    setState(568);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::COMMA) {
      setState(564);
      match(SpenatParser::COMMA);
      setState(565);
      paramDecl();
      setState(570);
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

SpenatParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::FunctionCallBodyOptionalContext* SpenatParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<SpenatParser::FunctionCallBodyOptionalContext>(0);
}

SpenatParser::LiteralValueContext* SpenatParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<SpenatParser::LiteralValueContext>(0);
}

SpenatParser::SignalParamNameContext* SpenatParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<SpenatParser::SignalParamNameContext>(0);
}

SpenatParser::AttributeNameContext* SpenatParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<SpenatParser::AttributeNameContext>(0);
}

SpenatParser::FunctionCallContext* SpenatParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<SpenatParser::FunctionCallContext>(0);
}


size_t SpenatParser::FunctionCallBodyContext::getRuleIndex() const {
  return SpenatParser::RuleFunctionCallBody;
}

void SpenatParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void SpenatParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

SpenatParser::FunctionCallBodyContext* SpenatParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 100, SpenatParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(576);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(571);
      literalValue();
      break;
    }

    case 2: {
      setState(572);
      signalParamName();
      break;
    }

    case 3: {
      setState(573);
      attributeName();
      break;
    }

    case 4: {
      setState(574);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(578);
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

SpenatParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(SpenatParser::COMMA, 0);
}

SpenatParser::FunctionCallBodyContext* SpenatParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<SpenatParser::FunctionCallBodyContext>(0);
}


size_t SpenatParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return SpenatParser::RuleFunctionCallBodyOptional;
}

void SpenatParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void SpenatParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

SpenatParser::FunctionCallBodyOptionalContext* SpenatParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 102, SpenatParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(583);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(580);
        match(SpenatParser::COMMA);
        setState(581);
        functionCallBody();
        break;
      }

      case SpenatParser::RPAREN: {
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

SpenatParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::TriggerDeclContext::DOT() {
  return getToken(SpenatParser::DOT, 0);
}

tree::TerminalNode* SpenatParser::TriggerDeclContext::MessageTrigger() {
  return getToken(SpenatParser::MessageTrigger, 0);
}

tree::TerminalNode* SpenatParser::TriggerDeclContext::TriggerID() {
  return getToken(SpenatParser::TriggerID, 0);
}


size_t SpenatParser::TriggerDeclContext::getRuleIndex() const {
  return SpenatParser::RuleTriggerDecl;
}

void SpenatParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void SpenatParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

SpenatParser::TriggerDeclContext* SpenatParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 104, SpenatParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    _la = _input->LA(1);
    if (!(_la == SpenatParser::TriggerID

    || _la == SpenatParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(586);
    match(SpenatParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

SpenatParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ThisDeclContext::ThisID() {
  return getToken(SpenatParser::ThisID, 0);
}

tree::TerminalNode* SpenatParser::ThisDeclContext::DOT() {
  return getToken(SpenatParser::DOT, 0);
}


size_t SpenatParser::ThisDeclContext::getRuleIndex() const {
  return SpenatParser::RuleThisDecl;
}

void SpenatParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void SpenatParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

SpenatParser::ThisDeclContext* SpenatParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 106, SpenatParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(588);
    match(SpenatParser::ThisID);
    setState(589);
    match(SpenatParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

SpenatParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::PortDeclContext::PortID() {
  return getToken(SpenatParser::PortID, 0);
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::PortDeclContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

tree::TerminalNode* SpenatParser::PortDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> SpenatParser::PortDeclContext::COMMA() {
  return getTokens(SpenatParser::COMMA);
}

tree::TerminalNode* SpenatParser::PortDeclContext::COMMA(size_t i) {
  return getToken(SpenatParser::COMMA, i);
}


size_t SpenatParser::PortDeclContext::getRuleIndex() const {
  return SpenatParser::RulePortDecl;
}

void SpenatParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void SpenatParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

SpenatParser::PortDeclContext* SpenatParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 108, SpenatParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(591);
    match(SpenatParser::PortID);
    setState(592);
    contextID();
    setState(597);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::COMMA) {
      setState(593);
      match(SpenatParser::COMMA);
      setState(594);
      contextID();
      setState(599);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(600);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

SpenatParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::NameDeclContext::NameID() {
  return getToken(SpenatParser::NameID, 0);
}

tree::TerminalNode* SpenatParser::NameDeclContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

SpenatParser::ContextIDContext* SpenatParser::NameDeclContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::NameDeclContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::NameDeclContext::getRuleIndex() const {
  return SpenatParser::RuleNameDecl;
}

void SpenatParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void SpenatParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

SpenatParser::NameDeclContext* SpenatParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 110, SpenatParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    match(SpenatParser::NameID);
    setState(603);
    match(SpenatParser::COLON);
    setState(604);
    contextID();
    setState(605);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

SpenatParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SpenatParser::ContextIDContext *> SpenatParser::IdPathContext::contextID() {
  return getRuleContexts<SpenatParser::ContextIDContext>();
}

SpenatParser::ContextIDContext* SpenatParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<SpenatParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> SpenatParser::IdPathContext::DOT() {
  return getTokens(SpenatParser::DOT);
}

tree::TerminalNode* SpenatParser::IdPathContext::DOT(size_t i) {
  return getToken(SpenatParser::DOT, i);
}


size_t SpenatParser::IdPathContext::getRuleIndex() const {
  return SpenatParser::RuleIdPath;
}

void SpenatParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void SpenatParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

SpenatParser::IdPathContext* SpenatParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 112, SpenatParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    contextID();
    setState(612);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::DOT) {
      setState(608);
      match(SpenatParser::DOT);
      setState(609);
      contextID();
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

//----------------- StatementDeclContext ------------------------------------------------------------------

SpenatParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::StatementBodyContext* SpenatParser::StatementDeclContext::statementBody() {
  return getRuleContext<SpenatParser::StatementBodyContext>(0);
}

SpenatParser::NestedStatementBodyContext* SpenatParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<SpenatParser::NestedStatementBodyContext>(0);
}


size_t SpenatParser::StatementDeclContext::getRuleIndex() const {
  return SpenatParser::RuleStatementDecl;
}

void SpenatParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void SpenatParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

SpenatParser::StatementDeclContext* SpenatParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 114, SpenatParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(617);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::IntID:
      case SpenatParser::RealID:
      case SpenatParser::BoolID:
      case SpenatParser::StringID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::ReturnID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::EnumID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::SwitchID:
      case SpenatParser::IfID:
      case SpenatParser::AsID:
      case SpenatParser::BREAK:
      case SpenatParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(615);
        statementBody();
        break;
      }

      case SpenatParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(616);
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

SpenatParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::FunctionCallStatementContext* SpenatParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<SpenatParser::FunctionCallStatementContext>(0);
}

SpenatParser::AttributeAssignStatementContext* SpenatParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<SpenatParser::AttributeAssignStatementContext>(0);
}

SpenatParser::SwitchStatementContext* SpenatParser::StatementBodyContext::switchStatement() {
  return getRuleContext<SpenatParser::SwitchStatementContext>(0);
}

SpenatParser::ConditionalStatementContext* SpenatParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<SpenatParser::ConditionalStatementContext>(0);
}

SpenatParser::LocalAssignStatementContext* SpenatParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<SpenatParser::LocalAssignStatementContext>(0);
}

SpenatParser::SendToStatementContext* SpenatParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<SpenatParser::SendToStatementContext>(0);
}

SpenatParser::BreakStatementContext* SpenatParser::StatementBodyContext::breakStatement() {
  return getRuleContext<SpenatParser::BreakStatementContext>(0);
}

SpenatParser::ReturnStatementContext* SpenatParser::StatementBodyContext::returnStatement() {
  return getRuleContext<SpenatParser::ReturnStatementContext>(0);
}


size_t SpenatParser::StatementBodyContext::getRuleIndex() const {
  return SpenatParser::RuleStatementBody;
}

void SpenatParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void SpenatParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

SpenatParser::StatementBodyContext* SpenatParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 116, SpenatParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(627);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(619);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(620);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(621);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(622);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(623);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(624);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(625);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(626);
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

SpenatParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::FunctionCallContext* SpenatParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<SpenatParser::FunctionCallContext>(0);
}

tree::TerminalNode* SpenatParser::FunctionCallStatementContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::FunctionCallStatementContext::getRuleIndex() const {
  return SpenatParser::RuleFunctionCallStatement;
}

void SpenatParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void SpenatParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

SpenatParser::FunctionCallStatementContext* SpenatParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, SpenatParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(629);
    functionCall();
    setState(630);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

SpenatParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::NestedStatementBodyContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

tree::TerminalNode* SpenatParser::NestedStatementBodyContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}

std::vector<SpenatParser::StatementBodyContext *> SpenatParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<SpenatParser::StatementBodyContext>();
}

SpenatParser::StatementBodyContext* SpenatParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<SpenatParser::StatementBodyContext>(i);
}


size_t SpenatParser::NestedStatementBodyContext::getRuleIndex() const {
  return SpenatParser::RuleNestedStatementBody;
}

void SpenatParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void SpenatParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

SpenatParser::NestedStatementBodyContext* SpenatParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 120, SpenatParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(632);
    match(SpenatParser::LBRACE);
    setState(636);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SpenatParser::ActionID)
      | (1ULL << SpenatParser::SpenatID)
      | (1ULL << SpenatParser::PlaceID)
      | (1ULL << SpenatParser::RefSignalID)
      | (1ULL << SpenatParser::RefPortID)
      | (1ULL << SpenatParser::ValueID)
      | (1ULL << SpenatParser::GuardID)
      | (1ULL << SpenatParser::InitialID)
      | (1ULL << SpenatParser::PreID)
      | (1ULL << SpenatParser::PostID)
      | (1ULL << SpenatParser::NameID)
      | (1ULL << SpenatParser::LabelID)
      | (1ULL << SpenatParser::EnabledID)
      | (1ULL << SpenatParser::TypeID)
      | (1ULL << SpenatParser::IntID)
      | (1ULL << SpenatParser::RealID)
      | (1ULL << SpenatParser::BoolID)
      | (1ULL << SpenatParser::StringID)
      | (1ULL << SpenatParser::TriggerID)
      | (1ULL << SpenatParser::MessageTrigger)
      | (1ULL << SpenatParser::ThisID)
      | (1ULL << SpenatParser::ReturnID)
      | (1ULL << SpenatParser::SignalTransitionID)
      | (1ULL << SpenatParser::TimeoutTransitionID)
      | (1ULL << SpenatParser::EnumID)
      | (1ULL << SpenatParser::AttributeID)
      | (1ULL << SpenatParser::SignalID)
      | (1ULL << SpenatParser::PortID)
      | (1ULL << SpenatParser::ImportID)
      | (1ULL << SpenatParser::FromID)
      | (1ULL << SpenatParser::ToID)
      | (1ULL << SpenatParser::SendID)
      | (1ULL << SpenatParser::FunctionID)
      | (1ULL << SpenatParser::SwitchID)
      | (1ULL << SpenatParser::IfID)
      | (1ULL << SpenatParser::AsID)
      | (1ULL << SpenatParser::BREAK)
      | (1ULL << SpenatParser::ID))) != 0)) {
      setState(633);
      statementBody();
      setState(638);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(639);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

SpenatParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ReturnStatementContext::ReturnID() {
  return getToken(SpenatParser::ReturnID, 0);
}

SpenatParser::OperationContext* SpenatParser::ReturnStatementContext::operation() {
  return getRuleContext<SpenatParser::OperationContext>(0);
}

tree::TerminalNode* SpenatParser::ReturnStatementContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::ReturnStatementContext::getRuleIndex() const {
  return SpenatParser::RuleReturnStatement;
}

void SpenatParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void SpenatParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

SpenatParser::ReturnStatementContext* SpenatParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 122, SpenatParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(641);
    match(SpenatParser::ReturnID);
    setState(642);
    operation();
    setState(643);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

SpenatParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::BreakStatementContext::BREAK() {
  return getToken(SpenatParser::BREAK, 0);
}

tree::TerminalNode* SpenatParser::BreakStatementContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::BreakStatementContext::getRuleIndex() const {
  return SpenatParser::RuleBreakStatement;
}

void SpenatParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void SpenatParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

SpenatParser::BreakStatementContext* SpenatParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 124, SpenatParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(645);
    match(SpenatParser::BREAK);
    setState(646);
    match(SpenatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

SpenatParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::AtomContext* SpenatParser::OperationContext::atom() {
  return getRuleContext<SpenatParser::AtomContext>(0);
}

SpenatParser::OperationOptionalContext* SpenatParser::OperationContext::operationOptional() {
  return getRuleContext<SpenatParser::OperationOptionalContext>(0);
}

tree::TerminalNode* SpenatParser::OperationContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

SpenatParser::OperationContext* SpenatParser::OperationContext::operation() {
  return getRuleContext<SpenatParser::OperationContext>(0);
}

tree::TerminalNode* SpenatParser::OperationContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}

tree::TerminalNode* SpenatParser::OperationContext::MINUS() {
  return getToken(SpenatParser::MINUS, 0);
}

tree::TerminalNode* SpenatParser::OperationContext::NotIdSymbol() {
  return getToken(SpenatParser::NotIdSymbol, 0);
}


size_t SpenatParser::OperationContext::getRuleIndex() const {
  return SpenatParser::RuleOperation;
}

void SpenatParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void SpenatParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

SpenatParser::OperationContext* SpenatParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 126, SpenatParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(659);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::AsID:
      case SpenatParser::TrueID:
      case SpenatParser::FalseID:
      case SpenatParser::INT:
      case SpenatParser::REAL:
      case SpenatParser::STRING:
      case SpenatParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(648);
        atom();
        setState(649);
        operationOptional();
        break;
      }

      case SpenatParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(651);
        match(SpenatParser::LPAREN);
        setState(652);
        operation();
        setState(653);
        match(SpenatParser::RPAREN);
        break;
      }

      case SpenatParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(655);
        match(SpenatParser::MINUS);
        setState(656);
        operation();
        break;
      }

      case SpenatParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(657);
        match(SpenatParser::NotIdSymbol);
        setState(658);
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

SpenatParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::OperationContext* SpenatParser::OperationOptionalContext::operation() {
  return getRuleContext<SpenatParser::OperationContext>(0);
}

tree::TerminalNode* SpenatParser::OperationOptionalContext::MULT() {
  return getToken(SpenatParser::MULT, 0);
}

tree::TerminalNode* SpenatParser::OperationOptionalContext::DIV() {
  return getToken(SpenatParser::DIV, 0);
}

tree::TerminalNode* SpenatParser::OperationOptionalContext::PLUS() {
  return getToken(SpenatParser::PLUS, 0);
}

tree::TerminalNode* SpenatParser::OperationOptionalContext::MINUS() {
  return getToken(SpenatParser::MINUS, 0);
}


size_t SpenatParser::OperationOptionalContext::getRuleIndex() const {
  return SpenatParser::RuleOperationOptional;
}

void SpenatParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void SpenatParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

SpenatParser::OperationOptionalContext* SpenatParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 128, SpenatParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(664);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::PLUS:
      case SpenatParser::MINUS:
      case SpenatParser::MULT:
      case SpenatParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(661);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 77) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 77)) & ((1ULL << (SpenatParser::PLUS - 77))
          | (1ULL << (SpenatParser::MINUS - 77))
          | (1ULL << (SpenatParser::MULT - 77))
          | (1ULL << (SpenatParser::DIV - 77)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(662);
        operation();
        break;
      }

      case SpenatParser::EOF:
      case SpenatParser::NotIdSymbol:
      case SpenatParser::AndIdSymbol:
      case SpenatParser::OrIdSymbol:
      case SpenatParser::NotIdWord:
      case SpenatParser::AndIdWord:
      case SpenatParser::OrIdWord:
      case SpenatParser::ASSIGN:
      case SpenatParser::RPAREN:
      case SpenatParser::RBRACE:
      case SpenatParser::LESSTHAN:
      case SpenatParser::GREATERTHAN:
      case SpenatParser::SEMI: {
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

SpenatParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ExpressionContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

SpenatParser::ExpressionContext* SpenatParser::ExpressionContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}

tree::TerminalNode* SpenatParser::ExpressionContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}

SpenatParser::ExpressionOptionalContext* SpenatParser::ExpressionContext::expressionOptional() {
  return getRuleContext<SpenatParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* SpenatParser::ExpressionContext::NotIdSymbol() {
  return getToken(SpenatParser::NotIdSymbol, 0);
}

tree::TerminalNode* SpenatParser::ExpressionContext::NotIdWord() {
  return getToken(SpenatParser::NotIdWord, 0);
}

tree::TerminalNode* SpenatParser::ExpressionContext::MINUS() {
  return getToken(SpenatParser::MINUS, 0);
}

SpenatParser::OperationContext* SpenatParser::ExpressionContext::operation() {
  return getRuleContext<SpenatParser::OperationContext>(0);
}


size_t SpenatParser::ExpressionContext::getRuleIndex() const {
  return SpenatParser::RuleExpression;
}

void SpenatParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SpenatParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

SpenatParser::ExpressionContext* SpenatParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 130, SpenatParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(680);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(666);
      match(SpenatParser::LPAREN);
      setState(667);
      expression();
      setState(668);
      match(SpenatParser::RPAREN);
      setState(669);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(671);
      match(SpenatParser::NotIdSymbol);
      setState(672);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(673);
      match(SpenatParser::NotIdWord);
      setState(674);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(675);
      match(SpenatParser::MINUS);
      setState(676);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(677);
      operation();
      setState(678);
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

SpenatParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::ExpressionContext* SpenatParser::ExpressionOptionalContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(SpenatParser::OrIdSymbol, 0);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(SpenatParser::OrIdWord, 0);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(SpenatParser::AndIdSymbol, 0);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(SpenatParser::AndIdWord, 0);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(SpenatParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> SpenatParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(SpenatParser::ASSIGN);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(SpenatParser::ASSIGN, i);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(SpenatParser::NotIdSymbol, 0);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(SpenatParser::LESSTHAN, 0);
}

tree::TerminalNode* SpenatParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(SpenatParser::GREATERTHAN, 0);
}


size_t SpenatParser::ExpressionOptionalContext::getRuleIndex() const {
  return SpenatParser::RuleExpressionOptional;
}

void SpenatParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void SpenatParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

SpenatParser::ExpressionOptionalContext* SpenatParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 132, SpenatParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(705);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::NotIdSymbol:
      case SpenatParser::AndIdSymbol:
      case SpenatParser::OrIdSymbol:
      case SpenatParser::NotIdWord:
      case SpenatParser::AndIdWord:
      case SpenatParser::OrIdWord:
      case SpenatParser::ASSIGN:
      case SpenatParser::LESSTHAN:
      case SpenatParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(701);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SpenatParser::OrIdSymbol: {
            setState(682);
            match(SpenatParser::OrIdSymbol);
            break;
          }

          case SpenatParser::OrIdWord: {
            setState(683);
            match(SpenatParser::OrIdWord);
            break;
          }

          case SpenatParser::AndIdSymbol: {
            setState(684);
            match(SpenatParser::AndIdSymbol);
            break;
          }

          case SpenatParser::AndIdWord: {
            setState(685);
            match(SpenatParser::AndIdWord);
            break;
          }

          case SpenatParser::ASSIGN: {
            setState(686);
            match(SpenatParser::ASSIGN);
            setState(687);
            match(SpenatParser::ASSIGN);
            break;
          }

          case SpenatParser::NotIdSymbol: {
            setState(688);
            match(SpenatParser::NotIdSymbol);
            setState(689);
            match(SpenatParser::ASSIGN);
            break;
          }

          case SpenatParser::NotIdWord: {
            setState(690);
            match(SpenatParser::NotIdWord);
            break;
          }

          case SpenatParser::LESSTHAN: {
            setState(691);
            match(SpenatParser::LESSTHAN);
            setState(694);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case SpenatParser::ASSIGN: {
                setState(692);
                match(SpenatParser::ASSIGN);
                break;
              }

              case SpenatParser::ActionID:
              case SpenatParser::SpenatID:
              case SpenatParser::PlaceID:
              case SpenatParser::RefSignalID:
              case SpenatParser::RefPortID:
              case SpenatParser::ValueID:
              case SpenatParser::GuardID:
              case SpenatParser::InitialID:
              case SpenatParser::PreID:
              case SpenatParser::PostID:
              case SpenatParser::NameID:
              case SpenatParser::LabelID:
              case SpenatParser::EnabledID:
              case SpenatParser::TypeID:
              case SpenatParser::TriggerID:
              case SpenatParser::MessageTrigger:
              case SpenatParser::ThisID:
              case SpenatParser::SignalTransitionID:
              case SpenatParser::TimeoutTransitionID:
              case SpenatParser::AttributeID:
              case SpenatParser::SignalID:
              case SpenatParser::PortID:
              case SpenatParser::ImportID:
              case SpenatParser::FromID:
              case SpenatParser::ToID:
              case SpenatParser::SendID:
              case SpenatParser::FunctionID:
              case SpenatParser::AsID:
              case SpenatParser::NotIdSymbol:
              case SpenatParser::NotIdWord:
              case SpenatParser::TrueID:
              case SpenatParser::FalseID:
              case SpenatParser::INT:
              case SpenatParser::REAL:
              case SpenatParser::STRING:
              case SpenatParser::ID:
              case SpenatParser::LPAREN:
              case SpenatParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case SpenatParser::GREATERTHAN: {
            setState(696);
            match(SpenatParser::GREATERTHAN);
            setState(699);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case SpenatParser::ASSIGN: {
                setState(697);
                match(SpenatParser::ASSIGN);
                break;
              }

              case SpenatParser::ActionID:
              case SpenatParser::SpenatID:
              case SpenatParser::PlaceID:
              case SpenatParser::RefSignalID:
              case SpenatParser::RefPortID:
              case SpenatParser::ValueID:
              case SpenatParser::GuardID:
              case SpenatParser::InitialID:
              case SpenatParser::PreID:
              case SpenatParser::PostID:
              case SpenatParser::NameID:
              case SpenatParser::LabelID:
              case SpenatParser::EnabledID:
              case SpenatParser::TypeID:
              case SpenatParser::TriggerID:
              case SpenatParser::MessageTrigger:
              case SpenatParser::ThisID:
              case SpenatParser::SignalTransitionID:
              case SpenatParser::TimeoutTransitionID:
              case SpenatParser::AttributeID:
              case SpenatParser::SignalID:
              case SpenatParser::PortID:
              case SpenatParser::ImportID:
              case SpenatParser::FromID:
              case SpenatParser::ToID:
              case SpenatParser::SendID:
              case SpenatParser::FunctionID:
              case SpenatParser::AsID:
              case SpenatParser::NotIdSymbol:
              case SpenatParser::NotIdWord:
              case SpenatParser::TrueID:
              case SpenatParser::FalseID:
              case SpenatParser::INT:
              case SpenatParser::REAL:
              case SpenatParser::STRING:
              case SpenatParser::ID:
              case SpenatParser::LPAREN:
              case SpenatParser::MINUS: {
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
        setState(703);
        expression();
        break;
      }

      case SpenatParser::EOF:
      case SpenatParser::RPAREN:
      case SpenatParser::RBRACE:
      case SpenatParser::SEMI: {
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

SpenatParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::IfStatementContext* SpenatParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<SpenatParser::IfStatementContext>(0);
}

SpenatParser::ElseStatementContext* SpenatParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<SpenatParser::ElseStatementContext>(0);
}


size_t SpenatParser::ConditionalStatementContext::getRuleIndex() const {
  return SpenatParser::RuleConditionalStatement;
}

void SpenatParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void SpenatParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

SpenatParser::ConditionalStatementContext* SpenatParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 134, SpenatParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    ifStatement();
    setState(710);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      setState(708);
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

SpenatParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::IfStatementContext::IfID() {
  return getToken(SpenatParser::IfID, 0);
}

SpenatParser::IfEuTContext* SpenatParser::IfStatementContext::ifEuT() {
  return getRuleContext<SpenatParser::IfEuTContext>(0);
}

SpenatParser::StatementDeclContext* SpenatParser::IfStatementContext::statementDecl() {
  return getRuleContext<SpenatParser::StatementDeclContext>(0);
}

tree::TerminalNode* SpenatParser::IfStatementContext::SEMI() {
  return getToken(SpenatParser::SEMI, 0);
}


size_t SpenatParser::IfStatementContext::getRuleIndex() const {
  return SpenatParser::RuleIfStatement;
}

void SpenatParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void SpenatParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

SpenatParser::IfStatementContext* SpenatParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, SpenatParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(712);
    match(SpenatParser::IfID);
    setState(713);
    ifEuT();
    setState(716);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::IntID:
      case SpenatParser::RealID:
      case SpenatParser::BoolID:
      case SpenatParser::StringID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::ReturnID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::EnumID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::SwitchID:
      case SpenatParser::IfID:
      case SpenatParser::AsID:
      case SpenatParser::BREAK:
      case SpenatParser::ID:
      case SpenatParser::LBRACE: {
        setState(714);
        statementDecl();
        break;
      }

      case SpenatParser::SEMI: {
        setState(715);
        match(SpenatParser::SEMI);
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

SpenatParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::IfEuTContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

SpenatParser::ExpressionContext* SpenatParser::IfEuTContext::expression() {
  return getRuleContext<SpenatParser::ExpressionContext>(0);
}

tree::TerminalNode* SpenatParser::IfEuTContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}


size_t SpenatParser::IfEuTContext::getRuleIndex() const {
  return SpenatParser::RuleIfEuT;
}

void SpenatParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void SpenatParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

SpenatParser::IfEuTContext* SpenatParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 138, SpenatParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(718);
    match(SpenatParser::LPAREN);
    setState(719);
    expression();
    setState(720);
    match(SpenatParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

SpenatParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::ElseStatementContext::ElseID() {
  return getToken(SpenatParser::ElseID, 0);
}

SpenatParser::StatementDeclContext* SpenatParser::ElseStatementContext::statementDecl() {
  return getRuleContext<SpenatParser::StatementDeclContext>(0);
}


size_t SpenatParser::ElseStatementContext::getRuleIndex() const {
  return SpenatParser::RuleElseStatement;
}

void SpenatParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void SpenatParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

SpenatParser::ElseStatementContext* SpenatParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 140, SpenatParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(722);
    match(SpenatParser::ElseID);
    setState(723);
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

SpenatParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::SwitchStatementContext::SwitchID() {
  return getToken(SpenatParser::SwitchID, 0);
}

SpenatParser::SwitchPuTContext* SpenatParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<SpenatParser::SwitchPuTContext>(0);
}

tree::TerminalNode* SpenatParser::SwitchStatementContext::LBRACE() {
  return getToken(SpenatParser::LBRACE, 0);
}

tree::TerminalNode* SpenatParser::SwitchStatementContext::RBRACE() {
  return getToken(SpenatParser::RBRACE, 0);
}

SpenatParser::DefaultStatementContext* SpenatParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<SpenatParser::DefaultStatementContext>(0);
}

std::vector<SpenatParser::CaseStatementContext *> SpenatParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<SpenatParser::CaseStatementContext>();
}

SpenatParser::CaseStatementContext* SpenatParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<SpenatParser::CaseStatementContext>(i);
}


size_t SpenatParser::SwitchStatementContext::getRuleIndex() const {
  return SpenatParser::RuleSwitchStatement;
}

void SpenatParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void SpenatParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

SpenatParser::SwitchStatementContext* SpenatParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 142, SpenatParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
    match(SpenatParser::SwitchID);
    setState(726);
    switchPuT();
    setState(727);
    match(SpenatParser::LBRACE);
    setState(731);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SpenatParser::CaseID) {
      setState(728);
      caseStatement();
      setState(733);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(736);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::DefaultID: {
        setState(734);
        defaultStatement();
        break;
      }

      case SpenatParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(738);
    match(SpenatParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

SpenatParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::SwitchPuTContext::LPAREN() {
  return getToken(SpenatParser::LPAREN, 0);
}

SpenatParser::ContextIDContext* SpenatParser::SwitchPuTContext::contextID() {
  return getRuleContext<SpenatParser::ContextIDContext>(0);
}

tree::TerminalNode* SpenatParser::SwitchPuTContext::RPAREN() {
  return getToken(SpenatParser::RPAREN, 0);
}


size_t SpenatParser::SwitchPuTContext::getRuleIndex() const {
  return SpenatParser::RuleSwitchPuT;
}

void SpenatParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void SpenatParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

SpenatParser::SwitchPuTContext* SpenatParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 144, SpenatParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(740);
    match(SpenatParser::LPAREN);
    setState(741);
    contextID();
    setState(742);
    match(SpenatParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

SpenatParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::CaseStatementContext::CaseID() {
  return getToken(SpenatParser::CaseID, 0);
}

SpenatParser::LiteralValueContext* SpenatParser::CaseStatementContext::literalValue() {
  return getRuleContext<SpenatParser::LiteralValueContext>(0);
}

tree::TerminalNode* SpenatParser::CaseStatementContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

SpenatParser::NestedStatementBodyContext* SpenatParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<SpenatParser::NestedStatementBodyContext>(0);
}

std::vector<SpenatParser::StatementBodyContext *> SpenatParser::CaseStatementContext::statementBody() {
  return getRuleContexts<SpenatParser::StatementBodyContext>();
}

SpenatParser::StatementBodyContext* SpenatParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<SpenatParser::StatementBodyContext>(i);
}


size_t SpenatParser::CaseStatementContext::getRuleIndex() const {
  return SpenatParser::RuleCaseStatement;
}

void SpenatParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void SpenatParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

SpenatParser::CaseStatementContext* SpenatParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 146, SpenatParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(744);
    match(SpenatParser::CaseID);
    setState(745);
    literalValue();
    setState(746);
    match(SpenatParser::COLON);
    setState(754);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::LBRACE: {
        setState(747);
        nestedStatementBody();
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::IntID:
      case SpenatParser::RealID:
      case SpenatParser::BoolID:
      case SpenatParser::StringID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::ReturnID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::EnumID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::SwitchID:
      case SpenatParser::CaseID:
      case SpenatParser::DefaultID:
      case SpenatParser::IfID:
      case SpenatParser::AsID:
      case SpenatParser::BREAK:
      case SpenatParser::ID:
      case SpenatParser::RBRACE: {
        setState(751);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SpenatParser::ActionID)
          | (1ULL << SpenatParser::SpenatID)
          | (1ULL << SpenatParser::PlaceID)
          | (1ULL << SpenatParser::RefSignalID)
          | (1ULL << SpenatParser::RefPortID)
          | (1ULL << SpenatParser::ValueID)
          | (1ULL << SpenatParser::GuardID)
          | (1ULL << SpenatParser::InitialID)
          | (1ULL << SpenatParser::PreID)
          | (1ULL << SpenatParser::PostID)
          | (1ULL << SpenatParser::NameID)
          | (1ULL << SpenatParser::LabelID)
          | (1ULL << SpenatParser::EnabledID)
          | (1ULL << SpenatParser::TypeID)
          | (1ULL << SpenatParser::IntID)
          | (1ULL << SpenatParser::RealID)
          | (1ULL << SpenatParser::BoolID)
          | (1ULL << SpenatParser::StringID)
          | (1ULL << SpenatParser::TriggerID)
          | (1ULL << SpenatParser::MessageTrigger)
          | (1ULL << SpenatParser::ThisID)
          | (1ULL << SpenatParser::ReturnID)
          | (1ULL << SpenatParser::SignalTransitionID)
          | (1ULL << SpenatParser::TimeoutTransitionID)
          | (1ULL << SpenatParser::EnumID)
          | (1ULL << SpenatParser::AttributeID)
          | (1ULL << SpenatParser::SignalID)
          | (1ULL << SpenatParser::PortID)
          | (1ULL << SpenatParser::ImportID)
          | (1ULL << SpenatParser::FromID)
          | (1ULL << SpenatParser::ToID)
          | (1ULL << SpenatParser::SendID)
          | (1ULL << SpenatParser::FunctionID)
          | (1ULL << SpenatParser::SwitchID)
          | (1ULL << SpenatParser::IfID)
          | (1ULL << SpenatParser::AsID)
          | (1ULL << SpenatParser::BREAK)
          | (1ULL << SpenatParser::ID))) != 0)) {
          setState(748);
          statementBody();
          setState(753);
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

SpenatParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SpenatParser::DefaultStatementContext::DefaultID() {
  return getToken(SpenatParser::DefaultID, 0);
}

tree::TerminalNode* SpenatParser::DefaultStatementContext::COLON() {
  return getToken(SpenatParser::COLON, 0);
}

SpenatParser::NestedStatementBodyContext* SpenatParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<SpenatParser::NestedStatementBodyContext>(0);
}

std::vector<SpenatParser::StatementBodyContext *> SpenatParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<SpenatParser::StatementBodyContext>();
}

SpenatParser::StatementBodyContext* SpenatParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<SpenatParser::StatementBodyContext>(i);
}


size_t SpenatParser::DefaultStatementContext::getRuleIndex() const {
  return SpenatParser::RuleDefaultStatement;
}

void SpenatParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void SpenatParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

SpenatParser::DefaultStatementContext* SpenatParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 148, SpenatParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(756);
    match(SpenatParser::DefaultID);
    setState(757);
    match(SpenatParser::COLON);
    setState(765);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SpenatParser::LBRACE: {
        setState(758);
        nestedStatementBody();
        break;
      }

      case SpenatParser::ActionID:
      case SpenatParser::SpenatID:
      case SpenatParser::PlaceID:
      case SpenatParser::RefSignalID:
      case SpenatParser::RefPortID:
      case SpenatParser::ValueID:
      case SpenatParser::GuardID:
      case SpenatParser::InitialID:
      case SpenatParser::PreID:
      case SpenatParser::PostID:
      case SpenatParser::NameID:
      case SpenatParser::LabelID:
      case SpenatParser::EnabledID:
      case SpenatParser::TypeID:
      case SpenatParser::IntID:
      case SpenatParser::RealID:
      case SpenatParser::BoolID:
      case SpenatParser::StringID:
      case SpenatParser::TriggerID:
      case SpenatParser::MessageTrigger:
      case SpenatParser::ThisID:
      case SpenatParser::ReturnID:
      case SpenatParser::SignalTransitionID:
      case SpenatParser::TimeoutTransitionID:
      case SpenatParser::EnumID:
      case SpenatParser::AttributeID:
      case SpenatParser::SignalID:
      case SpenatParser::PortID:
      case SpenatParser::ImportID:
      case SpenatParser::FromID:
      case SpenatParser::ToID:
      case SpenatParser::SendID:
      case SpenatParser::FunctionID:
      case SpenatParser::SwitchID:
      case SpenatParser::IfID:
      case SpenatParser::AsID:
      case SpenatParser::BREAK:
      case SpenatParser::ID:
      case SpenatParser::RBRACE: {
        setState(762);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SpenatParser::ActionID)
          | (1ULL << SpenatParser::SpenatID)
          | (1ULL << SpenatParser::PlaceID)
          | (1ULL << SpenatParser::RefSignalID)
          | (1ULL << SpenatParser::RefPortID)
          | (1ULL << SpenatParser::ValueID)
          | (1ULL << SpenatParser::GuardID)
          | (1ULL << SpenatParser::InitialID)
          | (1ULL << SpenatParser::PreID)
          | (1ULL << SpenatParser::PostID)
          | (1ULL << SpenatParser::NameID)
          | (1ULL << SpenatParser::LabelID)
          | (1ULL << SpenatParser::EnabledID)
          | (1ULL << SpenatParser::TypeID)
          | (1ULL << SpenatParser::IntID)
          | (1ULL << SpenatParser::RealID)
          | (1ULL << SpenatParser::BoolID)
          | (1ULL << SpenatParser::StringID)
          | (1ULL << SpenatParser::TriggerID)
          | (1ULL << SpenatParser::MessageTrigger)
          | (1ULL << SpenatParser::ThisID)
          | (1ULL << SpenatParser::ReturnID)
          | (1ULL << SpenatParser::SignalTransitionID)
          | (1ULL << SpenatParser::TimeoutTransitionID)
          | (1ULL << SpenatParser::EnumID)
          | (1ULL << SpenatParser::AttributeID)
          | (1ULL << SpenatParser::SignalID)
          | (1ULL << SpenatParser::PortID)
          | (1ULL << SpenatParser::ImportID)
          | (1ULL << SpenatParser::FromID)
          | (1ULL << SpenatParser::ToID)
          | (1ULL << SpenatParser::SendID)
          | (1ULL << SpenatParser::FunctionID)
          | (1ULL << SpenatParser::SwitchID)
          | (1ULL << SpenatParser::IfID)
          | (1ULL << SpenatParser::AsID)
          | (1ULL << SpenatParser::BREAK)
          | (1ULL << SpenatParser::ID))) != 0)) {
          setState(759);
          statementBody();
          setState(764);
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

SpenatParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SpenatParser::SignalParamNameContext* SpenatParser::AtomContext::signalParamName() {
  return getRuleContext<SpenatParser::SignalParamNameContext>(0);
}

SpenatParser::AttributeNameContext* SpenatParser::AtomContext::attributeName() {
  return getRuleContext<SpenatParser::AttributeNameContext>(0);
}

SpenatParser::FunctionCallContext* SpenatParser::AtomContext::functionCall() {
  return getRuleContext<SpenatParser::FunctionCallContext>(0);
}

SpenatParser::LiteralValueContext* SpenatParser::AtomContext::literalValue() {
  return getRuleContext<SpenatParser::LiteralValueContext>(0);
}


size_t SpenatParser::AtomContext::getRuleIndex() const {
  return SpenatParser::RuleAtom;
}

void SpenatParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void SpenatParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SpenatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

SpenatParser::AtomContext* SpenatParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 150, SpenatParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(771);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(767);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(768);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(769);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(770);
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
std::vector<dfa::DFA> SpenatParser::_decisionToDFA;
atn::PredictionContextCache SpenatParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SpenatParser::_atn;
std::vector<uint16_t> SpenatParser::_serializedATN;

std::vector<std::string> SpenatParser::_ruleNames = {
  "spenatDecl", "spenatBody", "spenatBodyOptional", "placeDecl", "placeBody", 
  "guardDecl", "multiExpression", "multiExpressionOptional", "actionDecl", 
  "transitionDecl", "signalTransitionDecl", "signalTransitionBody", "timeoutTransitionDecl", 
  "timeoutTransitionBody", "refSignalDecl", "refPortDecl", "preDecl", "postDecl", 
  "timeoutDecl", "initialDecl", "functionCall", "contextID", "componentIdPath", 
  "signalIdPath", "attributeIdPath", "signalSend", "commonDecl", "importPathDecl", 
  "importPathBody", "importFileBody", "importAs", "typeDefDecl", "typeDecl", 
  "intTypeDecl", "realTypeDecl", "enumTypeDecl", "attributeDecl", "literalValue", 
  "signalParamName", "attributeName", "toPortName", "attributeAssignStatement", 
  "localAssignStatement", "sendToStatement", "singleAssignment", "multiAssignment", 
  "signalDecl", "paramDecl", "functionDecl", "functionParameters", "functionCallBody", 
  "functionCallBodyOptional", "triggerDecl", "thisDecl", "portDecl", "nameDecl", 
  "idPath", "statementDecl", "statementBody", "functionCallStatement", "nestedStatementBody", 
  "returnStatement", "breakStatement", "operation", "operationOptional", 
  "expression", "expressionOptional", "conditionalStatement", "ifStatement", 
  "ifEuT", "elseStatement", "switchStatement", "switchPuT", "caseStatement", 
  "defaultStatement", "atom"
};

std::vector<std::string> SpenatParser::_literalNames = {
  "", "'action'", "'Spenat'", "'Place'", "'signal'", "'port'", "'value'", 
  "'guard'", "'initial'", "'pre'", "'post'", "", "'name'", "'label'", "'enabled'", 
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

std::vector<std::string> SpenatParser::_symbolicNames = {
  "", "ActionID", "SpenatID", "PlaceID", "RefSignalID", "RefPortID", "ValueID", 
  "GuardID", "InitialID", "PreID", "PostID", "IGNORE_NEWLINE", "NameID", 
  "LabelID", "EnabledID", "TypeID", "IntID", "RealID", "BoolID", "StringID", 
  "TriggerID", "MessageTrigger", "ThisID", "ReturnID", "SignalTransitionID", 
  "TimeoutTransitionID", "EnumID", "DeclarationID", "DescriptionID", "AttributeID", 
  "SignalID", "PortID", "ImportID", "FromID", "ToID", "SendID", "FunctionID", 
  "SwitchID", "CaseID", "DefaultID", "IfID", "ElseID", "AsID", "AtID", "NotIdSymbol", 
  "AndIdSymbol", "OrIdSymbol", "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", 
  "FalseID", "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", "LeftArrow", 
  "RANGE", "INT", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", "LPAREN", 
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", 
  "COLON", "SEMI", "COMMA", "UNDER", "DOT", "PLUS", "MINUS", "MULT", "DIV", 
  "PIPE", "REF", "CONST", "NEWLINE", "WS"
};

dfa::Vocabulary SpenatParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SpenatParser::_tokenNames;

SpenatParser::Initializer::Initializer() {
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
    0x3, 0x57, 0x308, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb9, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0xc3, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xcb, 0xa, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xd3, 0xa, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd9, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xdd, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0xe9, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xed, 0xa, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xf1, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0xf5, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xf9, 0xa, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x103, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x107, 
    0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x10b, 0xa, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x10f, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x113, 
    0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x124, 0xa, 0x12, 0xc, 0x12, 
    0xe, 0x12, 0x127, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x130, 0xa, 0x13, 0xc, 0x13, 
    0xe, 0x13, 0x133, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x161, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x7, 0x18, 0x166, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x169, 0xb, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x16e, 0xa, 0x19, 0xc, 0x19, 
    0xe, 0x19, 0x171, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x7, 0x1a, 0x177, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x17a, 0xb, 0x1a, 
    0x5, 0x1a, 0x17c, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x186, 0xa, 0x1c, 
    0xc, 0x1c, 0xe, 0x1c, 0x189, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x5, 0x1d, 0x18f, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x5, 0x1f, 0x1a2, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x5, 0x20, 0x1a7, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x5, 0x22, 0x1b4, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1bd, 0xa, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x5, 0x24, 0x1c6, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x1cd, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x1d0, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1d9, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
    0x27, 0x1e3, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 
    0x3, 0x29, 0x5, 0x29, 0x1ea, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x1fb, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x203, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x209, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 
    0x20d, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x210, 0xb, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x7, 0x30, 0x21a, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x21d, 0xb, 
    0x30, 0x3, 0x30, 0x5, 0x30, 0x220, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x5, 0x30, 0x224, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x5, 0x32, 0x231, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 0x33, 0x239, 0xa, 0x33, 0xc, 0x33, 
    0xe, 0x33, 0x23c, 0xb, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x5, 0x34, 0x243, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x24a, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x3, 0x38, 0x7, 0x38, 0x256, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 
    0x259, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x265, 
    0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x268, 0xb, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
    0x5, 0x3b, 0x26c, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x276, 0xa, 0x3c, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x27d, 
    0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x280, 0xb, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x296, 
    0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x29b, 0xa, 0x42, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 
    0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x5, 0x43, 0x2ab, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
    0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x2b9, 0xa, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x2be, 0xa, 0x44, 0x5, 0x44, 0x2c0, 
    0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x2c4, 0xa, 0x44, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x2c9, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x2cf, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x3, 0x49, 0x7, 0x49, 0x2dc, 0xa, 0x49, 0xc, 0x49, 
    0xe, 0x49, 0x2df, 0xb, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x2e3, 
    0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
    0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 
    0x2f0, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x2f3, 0xb, 0x4b, 0x5, 0x4b, 
    0x2f5, 0xa, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 
    0x2fb, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x2fe, 0xb, 0x4c, 0x5, 0x4c, 
    0x300, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 
    0x306, 0xa, 0x4d, 0x3, 0x4d, 0x2, 0x2, 0x4e, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
    0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 
    0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 
    0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 
    0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x2, 
    0x5, 0x3, 0x2, 0x34, 0x35, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x4f, 0x52, 
    0x2, 0x33e, 0x2, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xc, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xe, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x16, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xff, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x114, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x119, 0x3, 0x2, 0x2, 0x2, 0x22, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x12a, 0x3, 0x2, 0x2, 0x2, 0x26, 0x136, 0x3, 0x2, 0x2, 0x2, 0x28, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x140, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x160, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x162, 0x3, 0x2, 0x2, 0x2, 0x30, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x17d, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x187, 0x3, 0x2, 0x2, 0x2, 0x38, 0x18e, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x190, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x1a6, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1b3, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1be, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1d3, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1e4, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1ed, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x1fe, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x208, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x20a, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x213, 0x3, 0x2, 0x2, 0x2, 0x60, 0x227, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x64, 0x235, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x242, 0x3, 0x2, 0x2, 0x2, 0x68, 0x249, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x24e, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x251, 0x3, 0x2, 0x2, 0x2, 0x70, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x261, 0x3, 0x2, 0x2, 0x2, 0x74, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x76, 0x275, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x277, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x27a, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x283, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x287, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x295, 0x3, 0x2, 0x2, 0x2, 0x82, 0x29a, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x86, 0x2c3, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x2d0, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2d7, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2ea, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x98, 0x305, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x9b, 0x7, 0x4, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x44, 0x2, 
    0x2, 0x9c, 0x9d, 0x5, 0x4, 0x3, 0x2, 0x9d, 0x9e, 0x7, 0x45, 0x2, 0x2, 
    0x9e, 0x3, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x5, 0x70, 0x39, 0x2, 0xa0, 
    0xa1, 0x5, 0x6, 0x4, 0x2, 0xa1, 0x5, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 
    0x5, 0x40, 0x21, 0x2, 0xa3, 0xa4, 0x5, 0x6, 0x4, 0x2, 0xa4, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x4a, 0x26, 0x2, 0xa6, 0xa7, 0x5, 0x6, 
    0x4, 0x2, 0xa7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x5e, 0x30, 
    0x2, 0xa9, 0xaa, 0x5, 0x6, 0x4, 0x2, 0xaa, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0x5, 0x62, 0x32, 0x2, 0xac, 0xad, 0x5, 0x6, 0x4, 0x2, 0xad, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x6e, 0x38, 0x2, 0xaf, 0xb0, 
    0x5, 0x6, 0x4, 0x2, 0xb0, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x5, 
    0x8, 0x5, 0x2, 0xb2, 0xb3, 0x5, 0x6, 0x4, 0x2, 0xb3, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0xb5, 0x5, 0x14, 0xb, 0x2, 0xb5, 0xb6, 0x5, 0x6, 0x4, 
    0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xbb, 0x7, 0x5, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x44, 0x2, 
    0x2, 0xbc, 0xbd, 0x5, 0xa, 0x6, 0x2, 0xbd, 0xbe, 0x7, 0x45, 0x2, 0x2, 
    0xbe, 0x9, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc2, 0x5, 0x70, 0x39, 0x2, 0xc0, 
    0xc3, 0x5, 0x28, 0x15, 0x2, 0xc1, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x9, 0x2, 0x2, 0xc5, 0xca, 0x7, 0x4a, 
    0x2, 0x2, 0xc6, 0xc7, 0x5, 0x84, 0x43, 0x2, 0xc7, 0xc8, 0x7, 0x4b, 0x2, 
    0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0xe, 0x8, 0x2, 
    0xca, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x44, 0x2, 0x2, 0xcd, 0xce, 
    0x5, 0x84, 0x43, 0x2, 0xce, 0xcf, 0x7, 0x45, 0x2, 0x2, 0xcf, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd3, 0x5, 0x84, 0x43, 0x2, 0xd1, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0x11, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x3, 0x2, 0x2, 
    0xd5, 0xd8, 0x7, 0x4a, 0x2, 0x2, 0xd6, 0xd9, 0x5, 0x5a, 0x2e, 0x2, 0xd7, 
    0xd9, 0x5, 0x5c, 0x2f, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd9, 0x13, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x5, 
    0x16, 0xc, 0x2, 0xdb, 0xdd, 0x5, 0x1a, 0xe, 0x2, 0xdc, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xdf, 0x7, 0x1a, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x44, 0x2, 0x2, 
    0xe0, 0xe1, 0x5, 0x18, 0xd, 0x2, 0xe1, 0xe2, 0x7, 0x45, 0x2, 0x2, 0xe2, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe8, 0x5, 0x70, 0x39, 0x2, 0xe4, 0xe5, 
    0x5, 0x1e, 0x10, 0x2, 0xe5, 0xe6, 0x5, 0x20, 0x11, 0x2, 0xe6, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xed, 0x5, 0xc, 0x7, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x5, 0x12, 0xa, 0x2, 0xef, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x5, 
    0x22, 0x12, 0x2, 0xf3, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xf6, 0xf9, 0x5, 0x24, 0x13, 0x2, 0xf7, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x1b, 0x2, 0x2, 0xfb, 0xfc, 
    0x7, 0x44, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0x1c, 0xf, 0x2, 0xfd, 0xfe, 0x7, 
    0x45, 0x2, 0x2, 0xfe, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 0x5, 0x70, 
    0x39, 0x2, 0x100, 0x103, 0x5, 0x26, 0x14, 0x2, 0x101, 0x103, 0x3, 0x2, 
    0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x106, 0x3, 0x2, 0x2, 0x2, 0x104, 0x107, 0x5, 0xc, 
    0x7, 0x2, 0x105, 0x107, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x10b, 0x5, 0x12, 0xa, 0x2, 0x109, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x109, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x5, 0x22, 
    0x12, 0x2, 0x10d, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x10e, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x113, 0x5, 0x24, 0x13, 0x2, 0x111, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x6, 0x2, 
    0x2, 0x115, 0x116, 0x7, 0x4a, 0x2, 0x2, 0x116, 0x117, 0x5, 0x2c, 0x17, 
    0x2, 0x117, 0x118, 0x7, 0x4b, 0x2, 0x2, 0x118, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x11a, 0x7, 0x7, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x4a, 0x2, 
    0x2, 0x11b, 0x11c, 0x5, 0x2c, 0x17, 0x2, 0x11c, 0x11d, 0x7, 0x4b, 0x2, 
    0x2, 0x11d, 0x21, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x7, 0xb, 0x2, 0x2, 
    0x11f, 0x120, 0x7, 0x4a, 0x2, 0x2, 0x120, 0x125, 0x5, 0x2c, 0x17, 0x2, 
    0x121, 0x122, 0x7, 0x4c, 0x2, 0x2, 0x122, 0x124, 0x5, 0x2c, 0x17, 0x2, 
    0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x126, 0x128, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x129, 0x7, 0x4b, 0x2, 0x2, 0x129, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x12b, 0x7, 0xc, 0x2, 0x2, 0x12b, 0x12c, 0x7, 0x4a, 0x2, 0x2, 
    0x12c, 0x131, 0x5, 0x2c, 0x17, 0x2, 0x12d, 0x12e, 0x7, 0x4c, 0x2, 0x2, 
    0x12e, 0x130, 0x5, 0x2c, 0x17, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 
    0x130, 0x133, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x134, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 0x4b, 0x2, 0x2, 
    0x135, 0x25, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x8, 0x2, 0x2, 0x137, 
    0x138, 0x7, 0x4a, 0x2, 0x2, 0x138, 0x139, 0x7, 0x3d, 0x2, 0x2, 0x139, 
    0x13a, 0x7, 0x4b, 0x2, 0x2, 0x13a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x13b, 
    0x13c, 0x7, 0xa, 0x2, 0x2, 0x13c, 0x13d, 0x7, 0x4a, 0x2, 0x2, 0x13d, 
    0x13e, 0x9, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x4b, 0x2, 0x2, 0x13f, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x5, 0x2c, 0x17, 0x2, 0x141, 
    0x142, 0x7, 0x42, 0x2, 0x2, 0x142, 0x143, 0x5, 0x66, 0x34, 0x2, 0x143, 
    0x144, 0x7, 0x43, 0x2, 0x2, 0x144, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x161, 0x7, 0x3f, 0x2, 0x2, 0x146, 0x161, 0x7, 0xe, 0x2, 0x2, 0x147, 
    0x161, 0x7, 0xf, 0x2, 0x2, 0x148, 0x161, 0x7, 0x10, 0x2, 0x2, 0x149, 
    0x161, 0x7, 0x11, 0x2, 0x2, 0x14a, 0x161, 0x9, 0x3, 0x2, 0x2, 0x14b, 
    0x161, 0x7, 0x1f, 0x2, 0x2, 0x14c, 0x161, 0x7, 0x26, 0x2, 0x2, 0x14d, 
    0x161, 0x7, 0x20, 0x2, 0x2, 0x14e, 0x161, 0x7, 0x21, 0x2, 0x2, 0x14f, 
    0x161, 0x7, 0x22, 0x2, 0x2, 0x150, 0x161, 0x7, 0x23, 0x2, 0x2, 0x151, 
    0x161, 0x7, 0x24, 0x2, 0x2, 0x152, 0x161, 0x7, 0x25, 0x2, 0x2, 0x153, 
    0x161, 0x7, 0x2c, 0x2, 0x2, 0x154, 0x161, 0x7, 0x3, 0x2, 0x2, 0x155, 
    0x161, 0x7, 0x4, 0x2, 0x2, 0x156, 0x161, 0x7, 0x5, 0x2, 0x2, 0x157, 
    0x161, 0x7, 0x1a, 0x2, 0x2, 0x158, 0x161, 0x7, 0x1b, 0x2, 0x2, 0x159, 
    0x161, 0x7, 0x6, 0x2, 0x2, 0x15a, 0x161, 0x7, 0x7, 0x2, 0x2, 0x15b, 
    0x161, 0x7, 0x8, 0x2, 0x2, 0x15c, 0x161, 0x7, 0x9, 0x2, 0x2, 0x15d, 
    0x161, 0x7, 0xa, 0x2, 0x2, 0x15e, 0x161, 0x7, 0xb, 0x2, 0x2, 0x15f, 
    0x161, 0x7, 0xc, 0x2, 0x2, 0x160, 0x145, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x160, 0x147, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x148, 0x3, 0x2, 0x2, 0x2, 0x160, 0x149, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x14a, 0x3, 0x2, 0x2, 0x2, 0x160, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x14c, 0x3, 0x2, 0x2, 0x2, 0x160, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x150, 0x3, 0x2, 0x2, 0x2, 0x160, 0x151, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x152, 0x3, 0x2, 0x2, 0x2, 0x160, 0x153, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x154, 0x3, 0x2, 0x2, 0x2, 0x160, 0x155, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x156, 0x3, 0x2, 0x2, 0x2, 0x160, 0x157, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x158, 0x3, 0x2, 0x2, 0x2, 0x160, 0x159, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x15a, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x15c, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x162, 0x167, 0x5, 0x2c, 0x17, 0x2, 0x163, 
    0x164, 0x7, 0x4e, 0x2, 0x2, 0x164, 0x166, 0x5, 0x2c, 0x17, 0x2, 0x165, 
    0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 0x169, 0x3, 0x2, 0x2, 0x2, 0x167, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 0x2, 0x2, 0x2, 0x168, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16f, 
    0x5, 0x2c, 0x17, 0x2, 0x16b, 0x16c, 0x7, 0x4e, 0x2, 0x2, 0x16c, 0x16e, 
    0x5, 0x2c, 0x17, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 
    0x3, 0x2, 0x2, 0x2, 0x170, 0x31, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16f, 0x3, 
    0x2, 0x2, 0x2, 0x172, 0x17c, 0x5, 0x50, 0x29, 0x2, 0x173, 0x178, 0x5, 
    0x2c, 0x17, 0x2, 0x174, 0x175, 0x7, 0x4e, 0x2, 0x2, 0x175, 0x177, 0x5, 
    0x2c, 0x17, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x3, 
    0x2, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 
    0x2, 0x2, 0x2, 0x179, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 
    0x2, 0x2, 0x2, 0x17b, 0x172, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x173, 0x3, 
    0x2, 0x2, 0x2, 0x17c, 0x33, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x5, 0x30, 
    0x19, 0x2, 0x17e, 0x17f, 0x7, 0x42, 0x2, 0x2, 0x17f, 0x180, 0x5, 0x66, 
    0x34, 0x2, 0x180, 0x181, 0x7, 0x43, 0x2, 0x2, 0x181, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x186, 0x5, 0x40, 0x21, 0x2, 0x183, 0x186, 0x5, 0x4a, 
    0x26, 0x2, 0x184, 0x186, 0x5, 0x5e, 0x30, 0x2, 0x185, 0x182, 0x3, 0x2, 
    0x2, 0x2, 0x185, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x186, 0x189, 0x3, 0x2, 0x2, 0x2, 0x187, 0x185, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x5, 0x3a, 0x1e, 
    0x2, 0x18b, 0x18c, 0x5, 0x38, 0x1d, 0x2, 0x18c, 0x18f, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x18e, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x190, 0x191, 0x7, 0x22, 0x2, 0x2, 0x191, 0x192, 0x7, 0x48, 0x2, 0x2, 
    0x192, 0x193, 0x5, 0x3c, 0x1f, 0x2, 0x193, 0x194, 0x7, 0x49, 0x2, 0x2, 
    0x194, 0x195, 0x5, 0x3e, 0x20, 0x2, 0x195, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x196, 0x197, 0x5, 0x2c, 0x17, 0x2, 0x197, 0x198, 0x7, 0x4e, 0x2, 0x2, 
    0x198, 0x199, 0x5, 0x2c, 0x17, 0x2, 0x199, 0x1a2, 0x3, 0x2, 0x2, 0x2, 
    0x19a, 0x19b, 0x7, 0x3b, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x52, 0x2, 0x2, 
    0x19c, 0x1a2, 0x5, 0x3c, 0x1f, 0x2, 0x19d, 0x19e, 0x5, 0x2c, 0x17, 0x2, 
    0x19e, 0x19f, 0x7, 0x52, 0x2, 0x2, 0x19f, 0x1a0, 0x5, 0x3c, 0x1f, 0x2, 
    0x1a0, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x196, 0x3, 0x2, 0x2, 0x2, 
    0x1a1, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x19d, 0x3, 0x2, 0x2, 0x2, 
    0x1a2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x2c, 0x2, 0x2, 
    0x1a4, 0x1a7, 0x5, 0x2c, 0x17, 0x2, 0x1a5, 0x1a7, 0x3, 0x2, 0x2, 0x2, 
    0x1a6, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x1a7, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x11, 0x2, 0x2, 
    0x1a9, 0x1aa, 0x5, 0x42, 0x22, 0x2, 0x1aa, 0x1ab, 0x5, 0x2c, 0x17, 0x2, 
    0x1ab, 0x1ac, 0x7, 0x4b, 0x2, 0x2, 0x1ac, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x1ad, 0x1b4, 0x5, 0x44, 0x23, 0x2, 0x1ae, 0x1b4, 0x5, 0x46, 0x24, 0x2, 
    0x1af, 0x1b4, 0x5, 0x48, 0x25, 0x2, 0x1b0, 0x1b4, 0x7, 0x14, 0x2, 0x2, 
    0x1b1, 0x1b4, 0x7, 0x15, 0x2, 0x2, 0x1b2, 0x1b4, 0x5, 0x2c, 0x17, 0x2, 
    0x1b3, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
    0x1b3, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b0, 0x3, 0x2, 0x2, 0x2, 
    0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b2, 0x3, 0x2, 0x2, 0x2, 
    0x1b4, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1bc, 0x7, 0x12, 0x2, 0x2, 
    0x1b6, 0x1b7, 0x7, 0x42, 0x2, 0x2, 0x1b7, 0x1b8, 0x7, 0x3c, 0x2, 0x2, 
    0x1b8, 0x1b9, 0x7, 0x3b, 0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x3c, 0x2, 0x2, 
    0x1ba, 0x1bd, 0x7, 0x43, 0x2, 0x2, 0x1bb, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x1bc, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
    0x1bd, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c5, 0x7, 0x13, 0x2, 0x2, 
    0x1bf, 0x1c0, 0x7, 0x42, 0x2, 0x2, 0x1c0, 0x1c1, 0x7, 0x3d, 0x2, 0x2, 
    0x1c1, 0x1c2, 0x7, 0x3b, 0x2, 0x2, 0x1c2, 0x1c3, 0x7, 0x3d, 0x2, 0x2, 
    0x1c3, 0x1c6, 0x7, 0x43, 0x2, 0x2, 0x1c4, 0x1c6, 0x3, 0x2, 0x2, 0x2, 
    0x1c5, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c4, 0x3, 0x2, 0x2, 0x2, 
    0x1c6, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x1c, 0x2, 0x2, 
    0x1c8, 0x1c9, 0x7, 0x42, 0x2, 0x2, 0x1c9, 0x1ce, 0x5, 0x2c, 0x17, 0x2, 
    0x1ca, 0x1cb, 0x7, 0x4c, 0x2, 0x2, 0x1cb, 0x1cd, 0x5, 0x2c, 0x17, 0x2, 
    0x1cc, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1d0, 0x3, 0x2, 0x2, 0x2, 
    0x1ce, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x3, 0x2, 0x2, 0x2, 
    0x1cf, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 
    0x1d1, 0x1d2, 0x7, 0x43, 0x2, 0x2, 0x1d2, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x1d4, 0x7, 0x1f, 0x2, 0x2, 0x1d4, 0x1d5, 0x5, 0x42, 0x22, 0x2, 
    0x1d5, 0x1d8, 0x5, 0x2c, 0x17, 0x2, 0x1d6, 0x1d7, 0x7, 0x37, 0x2, 0x2, 
    0x1d7, 0x1d9, 0x5, 0x4c, 0x27, 0x2, 0x1d8, 0x1d6, 0x3, 0x2, 0x2, 0x2, 
    0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x1db, 0x7, 0x4b, 0x2, 0x2, 0x1db, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x1dc, 0x1e3, 0x7, 0x3c, 0x2, 0x2, 0x1dd, 0x1e3, 0x7, 0x3d, 0x2, 0x2, 
    0x1de, 0x1e3, 0x7, 0x3e, 0x2, 0x2, 0x1df, 0x1e3, 0x7, 0x34, 0x2, 0x2, 
    0x1e0, 0x1e3, 0x7, 0x35, 0x2, 0x2, 0x1e1, 0x1e3, 0x5, 0x2c, 0x17, 0x2, 
    0x1e2, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1dd, 0x3, 0x2, 0x2, 0x2, 
    0x1e2, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1df, 0x3, 0x2, 0x2, 0x2, 
    0x1e2, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x1e3, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x5, 0x6a, 0x36, 0x2, 
    0x1e5, 0x1e6, 0x5, 0x2c, 0x17, 0x2, 0x1e6, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x1e7, 0x1ea, 0x5, 0x6c, 0x37, 0x2, 0x1e8, 0x1ea, 0x3, 0x2, 0x2, 0x2, 
    0x1e9, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1e8, 0x3, 0x2, 0x2, 0x2, 
    0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x2c, 0x17, 0x2, 
    0x1ec, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x24, 0x2, 0x2, 
    0x1ee, 0x1ef, 0x5, 0x2c, 0x17, 0x2, 0x1ef, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x1f0, 0x1f1, 0x5, 0x50, 0x29, 0x2, 0x1f1, 0x1f2, 0x7, 0x37, 0x2, 0x2, 
    0x1f2, 0x1f3, 0x5, 0x84, 0x43, 0x2, 0x1f3, 0x1f4, 0x7, 0x4b, 0x2, 0x2, 
    0x1f4, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x42, 0x22, 0x2, 
    0x1f6, 0x1fa, 0x5, 0x2c, 0x17, 0x2, 0x1f7, 0x1f8, 0x7, 0x37, 0x2, 0x2, 
    0x1f8, 0x1fb, 0x5, 0x84, 0x43, 0x2, 0x1f9, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fa, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x7, 0x4b, 0x2, 0x2, 
    0x1fd, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x7, 0x25, 0x2, 0x2, 
    0x1ff, 0x202, 0x5, 0x34, 0x1b, 0x2, 0x200, 0x203, 0x5, 0x52, 0x2a, 0x2, 
    0x201, 0x203, 0x3, 0x2, 0x2, 0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 
    0x202, 0x201, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x3, 0x2, 0x2, 0x2, 
    0x204, 0x205, 0x7, 0x4b, 0x2, 0x2, 0x205, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x206, 0x209, 0x5, 0x54, 0x2b, 0x2, 0x207, 0x209, 0x5, 0x58, 0x2d, 0x2, 
    0x208, 0x206, 0x3, 0x2, 0x2, 0x2, 0x208, 0x207, 0x3, 0x2, 0x2, 0x2, 
    0x209, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20e, 0x7, 0x44, 0x2, 0x2, 
    0x20b, 0x20d, 0x5, 0x5a, 0x2e, 0x2, 0x20c, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x20d, 0x210, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 
    0x20e, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x211, 0x3, 0x2, 0x2, 0x2, 
    0x210, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 0x7, 0x45, 0x2, 0x2, 
    0x212, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x7, 0x20, 0x2, 0x2, 
    0x214, 0x223, 0x5, 0x2c, 0x17, 0x2, 0x215, 0x21f, 0x7, 0x42, 0x2, 0x2, 
    0x216, 0x21b, 0x5, 0x60, 0x31, 0x2, 0x217, 0x218, 0x7, 0x4c, 0x2, 0x2, 
    0x218, 0x21a, 0x5, 0x60, 0x31, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 
    0x21b, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x21f, 0x216, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x21e, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x221, 0x3, 0x2, 0x2, 0x2, 0x221, 0x224, 0x7, 0x43, 0x2, 0x2, 
    0x222, 0x224, 0x3, 0x2, 0x2, 0x2, 0x223, 0x215, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x226, 0x7, 0x4b, 0x2, 0x2, 0x226, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x227, 0x228, 0x5, 0x42, 0x22, 0x2, 0x228, 0x229, 0x5, 0x2c, 0x17, 0x2, 
    0x229, 0x61, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x7, 0x26, 0x2, 0x2, 
    0x22b, 0x22c, 0x5, 0x42, 0x22, 0x2, 0x22c, 0x22d, 0x5, 0x72, 0x3a, 0x2, 
    0x22d, 0x230, 0x7, 0x42, 0x2, 0x2, 0x22e, 0x231, 0x5, 0x64, 0x33, 0x2, 
    0x22f, 0x231, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 
    0x230, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x3, 0x2, 0x2, 0x2, 
    0x232, 0x233, 0x7, 0x43, 0x2, 0x2, 0x233, 0x234, 0x5, 0x7a, 0x3e, 0x2, 
    0x234, 0x63, 0x3, 0x2, 0x2, 0x2, 0x235, 0x23a, 0x5, 0x60, 0x31, 0x2, 
    0x236, 0x237, 0x7, 0x4c, 0x2, 0x2, 0x237, 0x239, 0x5, 0x60, 0x31, 0x2, 
    0x238, 0x236, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23c, 0x3, 0x2, 0x2, 0x2, 
    0x23a, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x65, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23d, 
    0x243, 0x5, 0x4c, 0x27, 0x2, 0x23e, 0x243, 0x5, 0x4e, 0x28, 0x2, 0x23f, 
    0x243, 0x5, 0x50, 0x29, 0x2, 0x240, 0x243, 0x5, 0x2a, 0x16, 0x2, 0x241, 
    0x243, 0x3, 0x2, 0x2, 0x2, 0x242, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x242, 
    0x23e, 0x3, 0x2, 0x2, 0x2, 0x242, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x242, 
    0x240, 0x3, 0x2, 0x2, 0x2, 0x242, 0x241, 0x3, 0x2, 0x2, 0x2, 0x243, 
    0x244, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x5, 0x68, 0x35, 0x2, 0x245, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 0x7, 0x4c, 0x2, 0x2, 0x247, 
    0x24a, 0x5, 0x66, 0x34, 0x2, 0x248, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x249, 
    0x246, 0x3, 0x2, 0x2, 0x2, 0x249, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x9, 0x3, 0x2, 0x2, 0x24c, 0x24d, 
    0x7, 0x4e, 0x2, 0x2, 0x24d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 
    0x7, 0x18, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x4e, 0x2, 0x2, 0x250, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x7, 0x21, 0x2, 0x2, 0x252, 0x257, 
    0x5, 0x2c, 0x17, 0x2, 0x253, 0x254, 0x7, 0x4c, 0x2, 0x2, 0x254, 0x256, 
    0x5, 0x2c, 0x17, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x256, 0x259, 
    0x3, 0x2, 0x2, 0x2, 0x257, 0x255, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 
    0x3, 0x2, 0x2, 0x2, 0x258, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x259, 0x257, 
    0x3, 0x2, 0x2, 0x2, 0x25a, 0x25b, 0x7, 0x4b, 0x2, 0x2, 0x25b, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x7, 0xe, 0x2, 0x2, 0x25d, 0x25e, 
    0x7, 0x4a, 0x2, 0x2, 0x25e, 0x25f, 0x5, 0x2c, 0x17, 0x2, 0x25f, 0x260, 
    0x7, 0x4b, 0x2, 0x2, 0x260, 0x71, 0x3, 0x2, 0x2, 0x2, 0x261, 0x266, 
    0x5, 0x2c, 0x17, 0x2, 0x262, 0x263, 0x7, 0x4e, 0x2, 0x2, 0x263, 0x265, 
    0x5, 0x2c, 0x17, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 0x265, 0x268, 
    0x3, 0x2, 0x2, 0x2, 0x266, 0x264, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 
    0x3, 0x2, 0x2, 0x2, 0x267, 0x73, 0x3, 0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 
    0x2, 0x2, 0x2, 0x269, 0x26c, 0x5, 0x76, 0x3c, 0x2, 0x26a, 0x26c, 0x5, 
    0x7a, 0x3e, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26a, 0x3, 
    0x2, 0x2, 0x2, 0x26c, 0x75, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x276, 0x5, 0x78, 
    0x3d, 0x2, 0x26e, 0x276, 0x5, 0x54, 0x2b, 0x2, 0x26f, 0x276, 0x5, 0x90, 
    0x49, 0x2, 0x270, 0x276, 0x5, 0x88, 0x45, 0x2, 0x271, 0x276, 0x5, 0x56, 
    0x2c, 0x2, 0x272, 0x276, 0x5, 0x58, 0x2d, 0x2, 0x273, 0x276, 0x5, 0x7e, 
    0x40, 0x2, 0x274, 0x276, 0x5, 0x7c, 0x3f, 0x2, 0x275, 0x26d, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x275, 0x26f, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x270, 0x3, 0x2, 0x2, 0x2, 0x275, 0x271, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x272, 0x3, 0x2, 0x2, 0x2, 0x275, 0x273, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x277, 0x278, 0x5, 0x2a, 0x16, 0x2, 0x278, 0x279, 0x7, 0x4b, 0x2, 
    0x2, 0x279, 0x79, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27e, 0x7, 0x44, 0x2, 
    0x2, 0x27b, 0x27d, 0x5, 0x76, 0x3c, 0x2, 0x27c, 0x27b, 0x3, 0x2, 0x2, 
    0x2, 0x27d, 0x280, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27c, 0x3, 0x2, 0x2, 
    0x2, 0x27e, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x281, 0x3, 0x2, 0x2, 
    0x2, 0x280, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x7, 0x45, 0x2, 
    0x2, 0x282, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x7, 0x19, 0x2, 
    0x2, 0x284, 0x285, 0x5, 0x80, 0x41, 0x2, 0x285, 0x286, 0x7, 0x4b, 0x2, 
    0x2, 0x286, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x287, 0x288, 0x7, 0x36, 0x2, 
    0x2, 0x288, 0x289, 0x7, 0x4b, 0x2, 0x2, 0x289, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x28a, 0x28b, 0x5, 0x98, 0x4d, 0x2, 0x28b, 0x28c, 0x5, 0x82, 0x42, 
    0x2, 0x28c, 0x296, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x7, 0x42, 0x2, 
    0x2, 0x28e, 0x28f, 0x5, 0x80, 0x41, 0x2, 0x28f, 0x290, 0x7, 0x43, 0x2, 
    0x2, 0x290, 0x296, 0x3, 0x2, 0x2, 0x2, 0x291, 0x292, 0x7, 0x50, 0x2, 
    0x2, 0x292, 0x296, 0x5, 0x80, 0x41, 0x2, 0x293, 0x294, 0x7, 0x2e, 0x2, 
    0x2, 0x294, 0x296, 0x5, 0x80, 0x41, 0x2, 0x295, 0x28a, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x295, 0x291, 0x3, 0x2, 0x2, 
    0x2, 0x295, 0x293, 0x3, 0x2, 0x2, 0x2, 0x296, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x297, 0x298, 0x9, 0x4, 0x2, 0x2, 0x298, 0x29b, 0x5, 0x80, 0x41, 0x2, 
    0x299, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x297, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x83, 0x3, 0x2, 0x2, 0x2, 0x29c, 
    0x29d, 0x7, 0x42, 0x2, 0x2, 0x29d, 0x29e, 0x5, 0x84, 0x43, 0x2, 0x29e, 
    0x29f, 0x7, 0x43, 0x2, 0x2, 0x29f, 0x2a0, 0x5, 0x86, 0x44, 0x2, 0x2a0, 
    0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x7, 0x2e, 0x2, 0x2, 0x2a2, 
    0x2ab, 0x5, 0x84, 0x43, 0x2, 0x2a3, 0x2a4, 0x7, 0x31, 0x2, 0x2, 0x2a4, 
    0x2ab, 0x5, 0x84, 0x43, 0x2, 0x2a5, 0x2a6, 0x7, 0x50, 0x2, 0x2, 0x2a6, 
    0x2ab, 0x5, 0x84, 0x43, 0x2, 0x2a7, 0x2a8, 0x5, 0x80, 0x41, 0x2, 0x2a8, 
    0x2a9, 0x5, 0x86, 0x44, 0x2, 0x2a9, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x29c, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2c0, 
    0x7, 0x30, 0x2, 0x2, 0x2ad, 0x2c0, 0x7, 0x33, 0x2, 0x2, 0x2ae, 0x2c0, 
    0x7, 0x2f, 0x2, 0x2, 0x2af, 0x2c0, 0x7, 0x32, 0x2, 0x2, 0x2b0, 0x2b1, 
    0x7, 0x37, 0x2, 0x2, 0x2b1, 0x2c0, 0x7, 0x37, 0x2, 0x2, 0x2b2, 0x2b3, 
    0x7, 0x2e, 0x2, 0x2, 0x2b3, 0x2c0, 0x7, 0x37, 0x2, 0x2, 0x2b4, 0x2c0, 
    0x7, 0x31, 0x2, 0x2, 0x2b5, 0x2b8, 0x7, 0x48, 0x2, 0x2, 0x2b6, 0x2b9, 
    0x7, 0x37, 0x2, 0x2, 0x2b7, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b6, 
    0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2c0, 
    0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bd, 0x7, 0x49, 0x2, 0x2, 0x2bb, 0x2be, 
    0x7, 0x37, 0x2, 0x2, 0x2bc, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2bb, 
    0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2c0, 
    0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2ad, 
    0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2af, 
    0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2b2, 
    0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2b5, 
    0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 
    0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c4, 0x5, 0x84, 0x43, 0x2, 0x2c2, 0x2c4, 
    0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c2, 
    0x3, 0x2, 0x2, 0x2, 0x2c4, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c8, 0x5, 
    0x8a, 0x46, 0x2, 0x2c6, 0x2c9, 0x5, 0x8e, 0x48, 0x2, 0x2c7, 0x2c9, 0x3, 
    0x2, 0x2, 0x2, 0x2c8, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c7, 0x3, 
    0x2, 0x2, 0x2, 0x2c9, 0x89, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 0x7, 0x2a, 
    0x2, 0x2, 0x2cb, 0x2ce, 0x5, 0x8c, 0x47, 0x2, 0x2cc, 0x2cf, 0x5, 0x74, 
    0x3b, 0x2, 0x2cd, 0x2cf, 0x7, 0x4b, 0x2, 0x2, 0x2ce, 0x2cc, 0x3, 0x2, 
    0x2, 0x2, 0x2ce, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x2d0, 0x2d1, 0x7, 0x42, 0x2, 0x2, 0x2d1, 0x2d2, 0x5, 0x84, 0x43, 
    0x2, 0x2d2, 0x2d3, 0x7, 0x43, 0x2, 0x2, 0x2d3, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x2d4, 0x2d5, 0x7, 0x2b, 0x2, 0x2, 0x2d5, 0x2d6, 0x5, 0x74, 0x3b, 
    0x2, 0x2d6, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x7, 0x27, 0x2, 
    0x2, 0x2d8, 0x2d9, 0x5, 0x92, 0x4a, 0x2, 0x2d9, 0x2dd, 0x7, 0x44, 0x2, 
    0x2, 0x2da, 0x2dc, 0x5, 0x94, 0x4b, 0x2, 0x2db, 0x2da, 0x3, 0x2, 0x2, 
    0x2, 0x2dc, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2db, 0x3, 0x2, 0x2, 
    0x2, 0x2dd, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2e2, 0x3, 0x2, 0x2, 
    0x2, 0x2df, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e3, 0x5, 0x96, 0x4c, 
    0x2, 0x2e1, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e0, 0x3, 0x2, 0x2, 
    0x2, 0x2e2, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x3, 0x2, 0x2, 
    0x2, 0x2e4, 0x2e5, 0x7, 0x45, 0x2, 0x2, 0x2e5, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x2e6, 0x2e7, 0x7, 0x42, 0x2, 0x2, 0x2e7, 0x2e8, 0x5, 0x2c, 0x17, 
    0x2, 0x2e8, 0x2e9, 0x7, 0x43, 0x2, 0x2, 0x2e9, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x2ea, 0x2eb, 0x7, 0x28, 0x2, 0x2, 0x2eb, 0x2ec, 0x5, 0x4c, 0x27, 
    0x2, 0x2ec, 0x2f4, 0x7, 0x4a, 0x2, 0x2, 0x2ed, 0x2f5, 0x5, 0x7a, 0x3e, 
    0x2, 0x2ee, 0x2f0, 0x5, 0x76, 0x3c, 0x2, 0x2ef, 0x2ee, 0x3, 0x2, 0x2, 
    0x2, 0x2f0, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2ef, 0x3, 0x2, 0x2, 
    0x2, 0x2f1, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f5, 0x3, 0x2, 0x2, 
    0x2, 0x2f3, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2ed, 0x3, 0x2, 0x2, 
    0x2, 0x2f4, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x2f6, 0x2f7, 0x7, 0x29, 0x2, 0x2, 0x2f7, 0x2ff, 0x7, 0x4a, 0x2, 0x2, 
    0x2f8, 0x300, 0x5, 0x7a, 0x3e, 0x2, 0x2f9, 0x2fb, 0x5, 0x76, 0x3c, 0x2, 
    0x2fa, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fe, 0x3, 0x2, 0x2, 0x2, 
    0x2fc, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x3, 0x2, 0x2, 0x2, 
    0x2fd, 0x300, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fc, 0x3, 0x2, 0x2, 0x2, 
    0x2ff, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x2fc, 0x3, 0x2, 0x2, 0x2, 
    0x300, 0x97, 0x3, 0x2, 0x2, 0x2, 0x301, 0x306, 0x5, 0x4e, 0x28, 0x2, 
    0x302, 0x306, 0x5, 0x50, 0x29, 0x2, 0x303, 0x306, 0x5, 0x2a, 0x16, 0x2, 
    0x304, 0x306, 0x5, 0x4c, 0x27, 0x2, 0x305, 0x301, 0x3, 0x2, 0x2, 0x2, 
    0x305, 0x302, 0x3, 0x2, 0x2, 0x2, 0x305, 0x303, 0x3, 0x2, 0x2, 0x2, 
    0x305, 0x304, 0x3, 0x2, 0x2, 0x2, 0x306, 0x99, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0xb8, 0xc2, 0xca, 0xd2, 0xd8, 0xdc, 0xe8, 0xec, 0xf0, 0xf4, 0xf8, 0x102, 
    0x106, 0x10a, 0x10e, 0x112, 0x125, 0x131, 0x160, 0x167, 0x16f, 0x178, 
    0x17b, 0x185, 0x187, 0x18e, 0x1a1, 0x1a6, 0x1b3, 0x1bc, 0x1c5, 0x1ce, 
    0x1d8, 0x1e2, 0x1e9, 0x1fa, 0x202, 0x208, 0x20e, 0x21b, 0x21f, 0x223, 
    0x230, 0x23a, 0x242, 0x249, 0x257, 0x266, 0x26b, 0x275, 0x27e, 0x295, 
    0x29a, 0x2aa, 0x2b8, 0x2bd, 0x2bf, 0x2c3, 0x2c8, 0x2ce, 0x2dd, 0x2e2, 
    0x2f1, 0x2f4, 0x2fc, 0x2ff, 0x305, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SpenatParser::Initializer SpenatParser::_init;
