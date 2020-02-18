
// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/Isrdl.g4 by ANTLR 4.7.2


#include "IsrdlListener.h"

#include "IsrdlParser.h"


using namespace antlrcpp;
using namespace antlr4;

IsrdlParser::IsrdlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

IsrdlParser::~IsrdlParser() {
  delete _interpreter;
}

std::string IsrdlParser::getGrammarFileName() const {
  return "Isrdl.g4";
}

const std::vector<std::string>& IsrdlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& IsrdlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SecRequirementContext ------------------------------------------------------------------

IsrdlParser::SecRequirementContext::SecRequirementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::SecRequirementContext::SecurityRequirementID() {
  return getToken(IsrdlParser::SecurityRequirementID, 0);
}

tree::TerminalNode* IsrdlParser::SecRequirementContext::LBRACE() {
  return getToken(IsrdlParser::LBRACE, 0);
}

IsrdlParser::NameDeclContext* IsrdlParser::SecRequirementContext::nameDecl() {
  return getRuleContext<IsrdlParser::NameDeclContext>(0);
}

IsrdlParser::AttackImpactDeclContext* IsrdlParser::SecRequirementContext::attackImpactDecl() {
  return getRuleContext<IsrdlParser::AttackImpactDeclContext>(0);
}

tree::TerminalNode* IsrdlParser::SecRequirementContext::RBRACE() {
  return getToken(IsrdlParser::RBRACE, 0);
}

IsrdlParser::AttackDescriptionDeclContext* IsrdlParser::SecRequirementContext::attackDescriptionDecl() {
  return getRuleContext<IsrdlParser::AttackDescriptionDeclContext>(0);
}


size_t IsrdlParser::SecRequirementContext::getRuleIndex() const {
  return IsrdlParser::RuleSecRequirement;
}

void IsrdlParser::SecRequirementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecRequirement(this);
}

void IsrdlParser::SecRequirementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecRequirement(this);
}

IsrdlParser::SecRequirementContext* IsrdlParser::secRequirement() {
  SecRequirementContext *_localctx = _tracker.createInstance<SecRequirementContext>(_ctx, getState());
  enterRule(_localctx, 0, IsrdlParser::RuleSecRequirement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(IsrdlParser::SecurityRequirementID);
    setState(137);
    match(IsrdlParser::LBRACE);
    setState(138);
    nameDecl();
    setState(141);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::AttackDescriptionID: {
        setState(139);
        attackDescriptionDecl();
        break;
      }

      case IsrdlParser::ImpactID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(143);
    attackImpactDecl();
    setState(144);
    match(IsrdlParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttackDescriptionDeclContext ------------------------------------------------------------------

IsrdlParser::AttackDescriptionDeclContext::AttackDescriptionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::AttackDescriptionDeclContext::AttackDescriptionID() {
  return getToken(IsrdlParser::AttackDescriptionID, 0);
}

tree::TerminalNode* IsrdlParser::AttackDescriptionDeclContext::LBRACE() {
  return getToken(IsrdlParser::LBRACE, 0);
}

tree::TerminalNode* IsrdlParser::AttackDescriptionDeclContext::RBRACE() {
  return getToken(IsrdlParser::RBRACE, 0);
}

IsrdlParser::AttackVectorDeclContext* IsrdlParser::AttackDescriptionDeclContext::attackVectorDecl() {
  return getRuleContext<IsrdlParser::AttackVectorDeclContext>(0);
}

IsrdlParser::AttackPrivilegesContext* IsrdlParser::AttackDescriptionDeclContext::attackPrivileges() {
  return getRuleContext<IsrdlParser::AttackPrivilegesContext>(0);
}


size_t IsrdlParser::AttackDescriptionDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleAttackDescriptionDecl;
}

void IsrdlParser::AttackDescriptionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttackDescriptionDecl(this);
}

void IsrdlParser::AttackDescriptionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttackDescriptionDecl(this);
}

IsrdlParser::AttackDescriptionDeclContext* IsrdlParser::attackDescriptionDecl() {
  AttackDescriptionDeclContext *_localctx = _tracker.createInstance<AttackDescriptionDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, IsrdlParser::RuleAttackDescriptionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(IsrdlParser::AttackDescriptionID);
    setState(147);
    match(IsrdlParser::LBRACE);
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::SourceID: {
        setState(148);
        attackVectorDecl();
        break;
      }

      case IsrdlParser::PrivilegesID:
      case IsrdlParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::PrivilegesID: {
        setState(152);
        attackPrivileges();
        break;
      }

      case IsrdlParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(156);
    match(IsrdlParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttackImpactDeclContext ------------------------------------------------------------------

IsrdlParser::AttackImpactDeclContext::AttackImpactDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::AttackImpactDeclContext::ImpactID() {
  return getToken(IsrdlParser::ImpactID, 0);
}

tree::TerminalNode* IsrdlParser::AttackImpactDeclContext::LBRACE() {
  return getToken(IsrdlParser::LBRACE, 0);
}

tree::TerminalNode* IsrdlParser::AttackImpactDeclContext::RBRACE() {
  return getToken(IsrdlParser::RBRACE, 0);
}

IsrdlParser::ConfidentialityThreatDeclContext* IsrdlParser::AttackImpactDeclContext::confidentialityThreatDecl() {
  return getRuleContext<IsrdlParser::ConfidentialityThreatDeclContext>(0);
}

IsrdlParser::IntegrityThreatDeclContext* IsrdlParser::AttackImpactDeclContext::integrityThreatDecl() {
  return getRuleContext<IsrdlParser::IntegrityThreatDeclContext>(0);
}

IsrdlParser::AvailabilityThreatDeclContext* IsrdlParser::AttackImpactDeclContext::availabilityThreatDecl() {
  return getRuleContext<IsrdlParser::AvailabilityThreatDeclContext>(0);
}


size_t IsrdlParser::AttackImpactDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleAttackImpactDecl;
}

void IsrdlParser::AttackImpactDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttackImpactDecl(this);
}

void IsrdlParser::AttackImpactDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttackImpactDecl(this);
}

IsrdlParser::AttackImpactDeclContext* IsrdlParser::attackImpactDecl() {
  AttackImpactDeclContext *_localctx = _tracker.createInstance<AttackImpactDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, IsrdlParser::RuleAttackImpactDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(IsrdlParser::ImpactID);
    setState(159);
    match(IsrdlParser::LBRACE);
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::ConfidentialityThreatID: {
        setState(160);
        confidentialityThreatDecl();
        break;
      }

      case IsrdlParser::IntegrityThreatID:
      case IsrdlParser::TimeoutID:
      case IsrdlParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(166);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::IntegrityThreatID: {
        setState(164);
        integrityThreatDecl();
        break;
      }

      case IsrdlParser::TimeoutID:
      case IsrdlParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::TimeoutID: {
        setState(168);
        availabilityThreatDecl();
        break;
      }

      case IsrdlParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(172);
    match(IsrdlParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttackVectorDeclContext ------------------------------------------------------------------

IsrdlParser::AttackVectorDeclContext::AttackVectorDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::AttackVectorDeclContext::SourceID() {
  return getToken(IsrdlParser::SourceID, 0);
}

tree::TerminalNode* IsrdlParser::AttackVectorDeclContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

IsrdlParser::AttackVectorEnumContext* IsrdlParser::AttackVectorDeclContext::attackVectorEnum() {
  return getRuleContext<IsrdlParser::AttackVectorEnumContext>(0);
}

tree::TerminalNode* IsrdlParser::AttackVectorDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::AttackVectorDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleAttackVectorDecl;
}

void IsrdlParser::AttackVectorDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttackVectorDecl(this);
}

void IsrdlParser::AttackVectorDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttackVectorDecl(this);
}

IsrdlParser::AttackVectorDeclContext* IsrdlParser::attackVectorDecl() {
  AttackVectorDeclContext *_localctx = _tracker.createInstance<AttackVectorDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, IsrdlParser::RuleAttackVectorDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(IsrdlParser::SourceID);
    setState(175);
    match(IsrdlParser::COLON);
    setState(176);
    attackVectorEnum();
    setState(177);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttackVectorEnumContext ------------------------------------------------------------------

IsrdlParser::AttackVectorEnumContext::AttackVectorEnumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::AttackVectorEnumContext::PhysicalID() {
  return getToken(IsrdlParser::PhysicalID, 0);
}

tree::TerminalNode* IsrdlParser::AttackVectorEnumContext::LocalID() {
  return getToken(IsrdlParser::LocalID, 0);
}

tree::TerminalNode* IsrdlParser::AttackVectorEnumContext::InternetID() {
  return getToken(IsrdlParser::InternetID, 0);
}


size_t IsrdlParser::AttackVectorEnumContext::getRuleIndex() const {
  return IsrdlParser::RuleAttackVectorEnum;
}

void IsrdlParser::AttackVectorEnumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttackVectorEnum(this);
}

void IsrdlParser::AttackVectorEnumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttackVectorEnum(this);
}

IsrdlParser::AttackVectorEnumContext* IsrdlParser::attackVectorEnum() {
  AttackVectorEnumContext *_localctx = _tracker.createInstance<AttackVectorEnumContext>(_ctx, getState());
  enterRule(_localctx, 8, IsrdlParser::RuleAttackVectorEnum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IsrdlParser::PhysicalID)
      | (1ULL << IsrdlParser::LocalID)
      | (1ULL << IsrdlParser::InternetID))) != 0))) {
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

//----------------- AttackPrivilegesContext ------------------------------------------------------------------

IsrdlParser::AttackPrivilegesContext::AttackPrivilegesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::AttackPrivilegesContext::PrivilegesID() {
  return getToken(IsrdlParser::PrivilegesID, 0);
}

tree::TerminalNode* IsrdlParser::AttackPrivilegesContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

IsrdlParser::PrivilegesEnumContext* IsrdlParser::AttackPrivilegesContext::privilegesEnum() {
  return getRuleContext<IsrdlParser::PrivilegesEnumContext>(0);
}

tree::TerminalNode* IsrdlParser::AttackPrivilegesContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::AttackPrivilegesContext::getRuleIndex() const {
  return IsrdlParser::RuleAttackPrivileges;
}

void IsrdlParser::AttackPrivilegesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttackPrivileges(this);
}

void IsrdlParser::AttackPrivilegesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttackPrivileges(this);
}

IsrdlParser::AttackPrivilegesContext* IsrdlParser::attackPrivileges() {
  AttackPrivilegesContext *_localctx = _tracker.createInstance<AttackPrivilegesContext>(_ctx, getState());
  enterRule(_localctx, 10, IsrdlParser::RuleAttackPrivileges);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(IsrdlParser::PrivilegesID);
    setState(182);
    match(IsrdlParser::COLON);
    setState(183);
    privilegesEnum();
    setState(184);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrivilegesEnumContext ------------------------------------------------------------------

IsrdlParser::PrivilegesEnumContext::PrivilegesEnumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::PrivilegesEnumContext::AdministratorID() {
  return getToken(IsrdlParser::AdministratorID, 0);
}

tree::TerminalNode* IsrdlParser::PrivilegesEnumContext::InstallAllowedID() {
  return getToken(IsrdlParser::InstallAllowedID, 0);
}

tree::TerminalNode* IsrdlParser::PrivilegesEnumContext::UnInstallAllowedID() {
  return getToken(IsrdlParser::UnInstallAllowedID, 0);
}

tree::TerminalNode* IsrdlParser::PrivilegesEnumContext::SaveAllowedID() {
  return getToken(IsrdlParser::SaveAllowedID, 0);
}

tree::TerminalNode* IsrdlParser::PrivilegesEnumContext::EditAllowedID() {
  return getToken(IsrdlParser::EditAllowedID, 0);
}

tree::TerminalNode* IsrdlParser::PrivilegesEnumContext::NoneID() {
  return getToken(IsrdlParser::NoneID, 0);
}

tree::TerminalNode* IsrdlParser::PrivilegesEnumContext::COMMA() {
  return getToken(IsrdlParser::COMMA, 0);
}

IsrdlParser::PrivilegesEnumContext* IsrdlParser::PrivilegesEnumContext::privilegesEnum() {
  return getRuleContext<IsrdlParser::PrivilegesEnumContext>(0);
}


size_t IsrdlParser::PrivilegesEnumContext::getRuleIndex() const {
  return IsrdlParser::RulePrivilegesEnum;
}

void IsrdlParser::PrivilegesEnumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrivilegesEnum(this);
}

void IsrdlParser::PrivilegesEnumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrivilegesEnum(this);
}

IsrdlParser::PrivilegesEnumContext* IsrdlParser::privilegesEnum() {
  PrivilegesEnumContext *_localctx = _tracker.createInstance<PrivilegesEnumContext>(_ctx, getState());
  enterRule(_localctx, 12, IsrdlParser::RulePrivilegesEnum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IsrdlParser::AdministratorID)
      | (1ULL << IsrdlParser::InstallAllowedID)
      | (1ULL << IsrdlParser::UnInstallAllowedID)
      | (1ULL << IsrdlParser::SaveAllowedID)
      | (1ULL << IsrdlParser::EditAllowedID)
      | (1ULL << IsrdlParser::NoneID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(190);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::COMMA: {
        setState(187);
        match(IsrdlParser::COMMA);
        setState(188);
        privilegesEnum();
        break;
      }

      case IsrdlParser::SEMI: {
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

//----------------- ConfidentialityThreatDeclContext ------------------------------------------------------------------

IsrdlParser::ConfidentialityThreatDeclContext::ConfidentialityThreatDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ConfidentialityThreatDeclContext::ConfidentialityThreatID() {
  return getToken(IsrdlParser::ConfidentialityThreatID, 0);
}

tree::TerminalNode* IsrdlParser::ConfidentialityThreatDeclContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

IsrdlParser::ConfidentialityEnumContext* IsrdlParser::ConfidentialityThreatDeclContext::confidentialityEnum() {
  return getRuleContext<IsrdlParser::ConfidentialityEnumContext>(0);
}

tree::TerminalNode* IsrdlParser::ConfidentialityThreatDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::ConfidentialityThreatDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleConfidentialityThreatDecl;
}

void IsrdlParser::ConfidentialityThreatDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfidentialityThreatDecl(this);
}

void IsrdlParser::ConfidentialityThreatDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfidentialityThreatDecl(this);
}

IsrdlParser::ConfidentialityThreatDeclContext* IsrdlParser::confidentialityThreatDecl() {
  ConfidentialityThreatDeclContext *_localctx = _tracker.createInstance<ConfidentialityThreatDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, IsrdlParser::RuleConfidentialityThreatDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(IsrdlParser::ConfidentialityThreatID);
    setState(193);
    match(IsrdlParser::COLON);
    setState(194);
    confidentialityEnum();
    setState(195);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfidentialityEnumContext ------------------------------------------------------------------

IsrdlParser::ConfidentialityEnumContext::ConfidentialityEnumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ConfidentialityEnumContext::BrokenID() {
  return getToken(IsrdlParser::BrokenID, 0);
}

tree::TerminalNode* IsrdlParser::ConfidentialityEnumContext::IntactID() {
  return getToken(IsrdlParser::IntactID, 0);
}


size_t IsrdlParser::ConfidentialityEnumContext::getRuleIndex() const {
  return IsrdlParser::RuleConfidentialityEnum;
}

void IsrdlParser::ConfidentialityEnumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfidentialityEnum(this);
}

void IsrdlParser::ConfidentialityEnumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfidentialityEnum(this);
}

IsrdlParser::ConfidentialityEnumContext* IsrdlParser::confidentialityEnum() {
  ConfidentialityEnumContext *_localctx = _tracker.createInstance<ConfidentialityEnumContext>(_ctx, getState());
  enterRule(_localctx, 16, IsrdlParser::RuleConfidentialityEnum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    _la = _input->LA(1);
    if (!(_la == IsrdlParser::BrokenID

    || _la == IsrdlParser::IntactID)) {
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

//----------------- IntegrityThreatDeclContext ------------------------------------------------------------------

IsrdlParser::IntegrityThreatDeclContext::IntegrityThreatDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::IntegrityThreatDeclContext::IntegrityThreatID() {
  return getToken(IsrdlParser::IntegrityThreatID, 0);
}

tree::TerminalNode* IsrdlParser::IntegrityThreatDeclContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

IsrdlParser::IntegrityEnumContext* IsrdlParser::IntegrityThreatDeclContext::integrityEnum() {
  return getRuleContext<IsrdlParser::IntegrityEnumContext>(0);
}

tree::TerminalNode* IsrdlParser::IntegrityThreatDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::IntegrityThreatDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleIntegrityThreatDecl;
}

void IsrdlParser::IntegrityThreatDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegrityThreatDecl(this);
}

void IsrdlParser::IntegrityThreatDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegrityThreatDecl(this);
}

IsrdlParser::IntegrityThreatDeclContext* IsrdlParser::integrityThreatDecl() {
  IntegrityThreatDeclContext *_localctx = _tracker.createInstance<IntegrityThreatDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, IsrdlParser::RuleIntegrityThreatDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(IsrdlParser::IntegrityThreatID);
    setState(200);
    match(IsrdlParser::COLON);
    setState(201);
    integrityEnum();
    setState(202);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegrityEnumContext ------------------------------------------------------------------

IsrdlParser::IntegrityEnumContext::IntegrityEnumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::IntegrityEnumContext::NoDamageID() {
  return getToken(IsrdlParser::NoDamageID, 0);
}

tree::TerminalNode* IsrdlParser::IntegrityEnumContext::AffectedID() {
  return getToken(IsrdlParser::AffectedID, 0);
}


size_t IsrdlParser::IntegrityEnumContext::getRuleIndex() const {
  return IsrdlParser::RuleIntegrityEnum;
}

void IsrdlParser::IntegrityEnumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegrityEnum(this);
}

void IsrdlParser::IntegrityEnumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegrityEnum(this);
}

IsrdlParser::IntegrityEnumContext* IsrdlParser::integrityEnum() {
  IntegrityEnumContext *_localctx = _tracker.createInstance<IntegrityEnumContext>(_ctx, getState());
  enterRule(_localctx, 20, IsrdlParser::RuleIntegrityEnum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    _la = _input->LA(1);
    if (!(_la == IsrdlParser::NoDamageID

    || _la == IsrdlParser::AffectedID)) {
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

//----------------- AvailabilityThreatDeclContext ------------------------------------------------------------------

IsrdlParser::AvailabilityThreatDeclContext::AvailabilityThreatDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::AvailabilityThreatDeclContext::TimeoutID() {
  return getToken(IsrdlParser::TimeoutID, 0);
}

tree::TerminalNode* IsrdlParser::AvailabilityThreatDeclContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

tree::TerminalNode* IsrdlParser::AvailabilityThreatDeclContext::INT() {
  return getToken(IsrdlParser::INT, 0);
}

tree::TerminalNode* IsrdlParser::AvailabilityThreatDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}

tree::TerminalNode* IsrdlParser::AvailabilityThreatDeclContext::MSekID() {
  return getToken(IsrdlParser::MSekID, 0);
}

tree::TerminalNode* IsrdlParser::AvailabilityThreatDeclContext::SekID() {
  return getToken(IsrdlParser::SekID, 0);
}


size_t IsrdlParser::AvailabilityThreatDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleAvailabilityThreatDecl;
}

void IsrdlParser::AvailabilityThreatDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAvailabilityThreatDecl(this);
}

void IsrdlParser::AvailabilityThreatDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAvailabilityThreatDecl(this);
}

IsrdlParser::AvailabilityThreatDeclContext* IsrdlParser::availabilityThreatDecl() {
  AvailabilityThreatDeclContext *_localctx = _tracker.createInstance<AvailabilityThreatDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, IsrdlParser::RuleAvailabilityThreatDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(IsrdlParser::TimeoutID);
    setState(207);
    match(IsrdlParser::COLON);
    setState(208);
    match(IsrdlParser::INT);
    setState(209);
    _la = _input->LA(1);
    if (!(_la == IsrdlParser::MSekID

    || _la == IsrdlParser::SekID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(210);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

IsrdlParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::NameDeclContext::NameID() {
  return getToken(IsrdlParser::NameID, 0);
}

tree::TerminalNode* IsrdlParser::NameDeclContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

tree::TerminalNode* IsrdlParser::NameDeclContext::ID() {
  return getToken(IsrdlParser::ID, 0);
}

tree::TerminalNode* IsrdlParser::NameDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::NameDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleNameDecl;
}

void IsrdlParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void IsrdlParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

IsrdlParser::NameDeclContext* IsrdlParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, IsrdlParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(IsrdlParser::NameID);
    setState(213);
    match(IsrdlParser::COLON);
    setState(214);
    match(IsrdlParser::ID);
    setState(215);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentIdPathContext ------------------------------------------------------------------

IsrdlParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IsrdlParser::ContextIDContext *> IsrdlParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<IsrdlParser::ContextIDContext>();
}

IsrdlParser::ContextIDContext* IsrdlParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<IsrdlParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IsrdlParser::ComponentIdPathContext::DOT() {
  return getTokens(IsrdlParser::DOT);
}

tree::TerminalNode* IsrdlParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(IsrdlParser::DOT, i);
}


size_t IsrdlParser::ComponentIdPathContext::getRuleIndex() const {
  return IsrdlParser::RuleComponentIdPath;
}

void IsrdlParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void IsrdlParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

IsrdlParser::ComponentIdPathContext* IsrdlParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 26, IsrdlParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    contextID();
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IsrdlParser::DOT) {
      setState(218);
      match(IsrdlParser::DOT);
      setState(219);
      contextID();
      setState(224);
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

IsrdlParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IsrdlParser::ContextIDContext *> IsrdlParser::SignalIdPathContext::contextID() {
  return getRuleContexts<IsrdlParser::ContextIDContext>();
}

IsrdlParser::ContextIDContext* IsrdlParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<IsrdlParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IsrdlParser::SignalIdPathContext::DOT() {
  return getTokens(IsrdlParser::DOT);
}

tree::TerminalNode* IsrdlParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(IsrdlParser::DOT, i);
}


size_t IsrdlParser::SignalIdPathContext::getRuleIndex() const {
  return IsrdlParser::RuleSignalIdPath;
}

void IsrdlParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void IsrdlParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

IsrdlParser::SignalIdPathContext* IsrdlParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 28, IsrdlParser::RuleSignalIdPath);
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
    while (_la == IsrdlParser::DOT) {
      setState(226);
      match(IsrdlParser::DOT);
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

//----------------- AttributeIdPathContext ------------------------------------------------------------------

IsrdlParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::AttributeNameContext* IsrdlParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<IsrdlParser::AttributeNameContext>(0);
}

std::vector<IsrdlParser::ContextIDContext *> IsrdlParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<IsrdlParser::ContextIDContext>();
}

IsrdlParser::ContextIDContext* IsrdlParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<IsrdlParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IsrdlParser::AttributeIdPathContext::DOT() {
  return getTokens(IsrdlParser::DOT);
}

tree::TerminalNode* IsrdlParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(IsrdlParser::DOT, i);
}


size_t IsrdlParser::AttributeIdPathContext::getRuleIndex() const {
  return IsrdlParser::RuleAttributeIdPath;
}

void IsrdlParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void IsrdlParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

IsrdlParser::AttributeIdPathContext* IsrdlParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 30, IsrdlParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(233);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(234);
      contextID();
      setState(239);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == IsrdlParser::DOT) {
        setState(235);
        match(IsrdlParser::DOT);
        setState(236);
        contextID();
        setState(241);
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

IsrdlParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::SignalIdPathContext* IsrdlParser::SignalSendContext::signalIdPath() {
  return getRuleContext<IsrdlParser::SignalIdPathContext>(0);
}

tree::TerminalNode* IsrdlParser::SignalSendContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

IsrdlParser::FunctionCallBodyContext* IsrdlParser::SignalSendContext::functionCallBody() {
  return getRuleContext<IsrdlParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* IsrdlParser::SignalSendContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}


size_t IsrdlParser::SignalSendContext::getRuleIndex() const {
  return IsrdlParser::RuleSignalSend;
}

void IsrdlParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void IsrdlParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

IsrdlParser::SignalSendContext* IsrdlParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 32, IsrdlParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    signalIdPath();
    setState(245);
    match(IsrdlParser::LPAREN);
    setState(246);
    functionCallBody();
    setState(247);
    match(IsrdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

IsrdlParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IsrdlParser::TypeDefDeclContext *> IsrdlParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<IsrdlParser::TypeDefDeclContext>();
}

IsrdlParser::TypeDefDeclContext* IsrdlParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<IsrdlParser::TypeDefDeclContext>(i);
}

std::vector<IsrdlParser::AttributeDeclContext *> IsrdlParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<IsrdlParser::AttributeDeclContext>();
}

IsrdlParser::AttributeDeclContext* IsrdlParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<IsrdlParser::AttributeDeclContext>(i);
}

std::vector<IsrdlParser::SignalDeclContext *> IsrdlParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<IsrdlParser::SignalDeclContext>();
}

IsrdlParser::SignalDeclContext* IsrdlParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<IsrdlParser::SignalDeclContext>(i);
}


size_t IsrdlParser::CommonDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleCommonDecl;
}

void IsrdlParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void IsrdlParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

IsrdlParser::CommonDeclContext* IsrdlParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 34, IsrdlParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IsrdlParser::TypeID)
      | (1ULL << IsrdlParser::AttributeID)
      | (1ULL << IsrdlParser::SignalID))) != 0)) {
      setState(252);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case IsrdlParser::TypeID: {
          setState(249);
          typeDefDecl();
          break;
        }

        case IsrdlParser::AttributeID: {
          setState(250);
          attributeDecl();
          break;
        }

        case IsrdlParser::SignalID: {
          setState(251);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
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

//----------------- ImportPathDeclContext ------------------------------------------------------------------

IsrdlParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::ImportPathBodyContext* IsrdlParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<IsrdlParser::ImportPathBodyContext>(0);
}

IsrdlParser::ImportPathDeclContext* IsrdlParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<IsrdlParser::ImportPathDeclContext>(0);
}


size_t IsrdlParser::ImportPathDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleImportPathDecl;
}

void IsrdlParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void IsrdlParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

IsrdlParser::ImportPathDeclContext* IsrdlParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, IsrdlParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(261);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(257);
      importPathBody();
      setState(258);
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

IsrdlParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ImportPathBodyContext::ImportID() {
  return getToken(IsrdlParser::ImportID, 0);
}

tree::TerminalNode* IsrdlParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(IsrdlParser::LESSTHAN, 0);
}

IsrdlParser::ImportFileBodyContext* IsrdlParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<IsrdlParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* IsrdlParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(IsrdlParser::GREATERTHAN, 0);
}

IsrdlParser::ImportAsContext* IsrdlParser::ImportPathBodyContext::importAs() {
  return getRuleContext<IsrdlParser::ImportAsContext>(0);
}


size_t IsrdlParser::ImportPathBodyContext::getRuleIndex() const {
  return IsrdlParser::RuleImportPathBody;
}

void IsrdlParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void IsrdlParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

IsrdlParser::ImportPathBodyContext* IsrdlParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 38, IsrdlParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(IsrdlParser::ImportID);
    setState(264);
    match(IsrdlParser::LESSTHAN);
    setState(265);
    importFileBody();
    setState(266);
    match(IsrdlParser::GREATERTHAN);
    setState(267);
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

IsrdlParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IsrdlParser::ContextIDContext *> IsrdlParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<IsrdlParser::ContextIDContext>();
}

IsrdlParser::ContextIDContext* IsrdlParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<IsrdlParser::ContextIDContext>(i);
}

tree::TerminalNode* IsrdlParser::ImportFileBodyContext::DOT() {
  return getToken(IsrdlParser::DOT, 0);
}

tree::TerminalNode* IsrdlParser::ImportFileBodyContext::RANGE() {
  return getToken(IsrdlParser::RANGE, 0);
}

tree::TerminalNode* IsrdlParser::ImportFileBodyContext::DIV() {
  return getToken(IsrdlParser::DIV, 0);
}

IsrdlParser::ImportFileBodyContext* IsrdlParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<IsrdlParser::ImportFileBodyContext>(0);
}


size_t IsrdlParser::ImportFileBodyContext::getRuleIndex() const {
  return IsrdlParser::RuleImportFileBody;
}

void IsrdlParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void IsrdlParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

IsrdlParser::ImportFileBodyContext* IsrdlParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 40, IsrdlParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(280);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(269);
      contextID();
      setState(270);
      match(IsrdlParser::DOT);
      setState(271);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(273);
      match(IsrdlParser::RANGE);
      setState(274);
      match(IsrdlParser::DIV);
      setState(275);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(276);
      contextID();
      setState(277);
      match(IsrdlParser::DIV);
      setState(278);
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

IsrdlParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ImportAsContext::AsID() {
  return getToken(IsrdlParser::AsID, 0);
}

IsrdlParser::ContextIDContext* IsrdlParser::ImportAsContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}


size_t IsrdlParser::ImportAsContext::getRuleIndex() const {
  return IsrdlParser::RuleImportAs;
}

void IsrdlParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void IsrdlParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

IsrdlParser::ImportAsContext* IsrdlParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 42, IsrdlParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(282);
        match(IsrdlParser::AsID);
        setState(283);
        contextID();
        break;
      }

      case IsrdlParser::ImportID: {
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

IsrdlParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::TypeDefDeclContext::TypeID() {
  return getToken(IsrdlParser::TypeID, 0);
}

IsrdlParser::TypeDeclContext* IsrdlParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<IsrdlParser::TypeDeclContext>(0);
}

IsrdlParser::ContextIDContext* IsrdlParser::TypeDefDeclContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}

tree::TerminalNode* IsrdlParser::TypeDefDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::TypeDefDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleTypeDefDecl;
}

void IsrdlParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void IsrdlParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

IsrdlParser::TypeDefDeclContext* IsrdlParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 44, IsrdlParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(IsrdlParser::TypeID);
    setState(288);
    typeDecl();
    setState(289);
    contextID();
    setState(290);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

IsrdlParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::IntTypeDeclContext* IsrdlParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<IsrdlParser::IntTypeDeclContext>(0);
}

IsrdlParser::RealTypeDeclContext* IsrdlParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<IsrdlParser::RealTypeDeclContext>(0);
}

IsrdlParser::EnumTypeDeclContext* IsrdlParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<IsrdlParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* IsrdlParser::TypeDeclContext::BoolID() {
  return getToken(IsrdlParser::BoolID, 0);
}

tree::TerminalNode* IsrdlParser::TypeDeclContext::StringID() {
  return getToken(IsrdlParser::StringID, 0);
}

IsrdlParser::ContextIDContext* IsrdlParser::TypeDeclContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}


size_t IsrdlParser::TypeDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleTypeDecl;
}

void IsrdlParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void IsrdlParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

IsrdlParser::TypeDeclContext* IsrdlParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 46, IsrdlParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(298);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(292);
        intTypeDecl();
        break;
      }

      case IsrdlParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(293);
        realTypeDecl();
        break;
      }

      case IsrdlParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(294);
        enumTypeDecl();
        break;
      }

      case IsrdlParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(295);
        match(IsrdlParser::BoolID);
        break;
      }

      case IsrdlParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(296);
        match(IsrdlParser::StringID);
        break;
      }

      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(297);
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

IsrdlParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::IntTypeDeclContext::IntID() {
  return getToken(IsrdlParser::IntID, 0);
}

tree::TerminalNode* IsrdlParser::IntTypeDeclContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> IsrdlParser::IntTypeDeclContext::INT() {
  return getTokens(IsrdlParser::INT);
}

tree::TerminalNode* IsrdlParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(IsrdlParser::INT, i);
}

tree::TerminalNode* IsrdlParser::IntTypeDeclContext::RANGE() {
  return getToken(IsrdlParser::RANGE, 0);
}

tree::TerminalNode* IsrdlParser::IntTypeDeclContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}


size_t IsrdlParser::IntTypeDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleIntTypeDecl;
}

void IsrdlParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void IsrdlParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

IsrdlParser::IntTypeDeclContext* IsrdlParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 48, IsrdlParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    match(IsrdlParser::IntID);
    setState(307);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::LPAREN: {
        setState(301);
        match(IsrdlParser::LPAREN);
        setState(302);
        match(IsrdlParser::INT);
        setState(303);
        match(IsrdlParser::RANGE);
        setState(304);
        match(IsrdlParser::INT);
        setState(305);
        match(IsrdlParser::RPAREN);
        break;
      }

      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::ID: {
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

IsrdlParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::RealTypeDeclContext::RealID() {
  return getToken(IsrdlParser::RealID, 0);
}

tree::TerminalNode* IsrdlParser::RealTypeDeclContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> IsrdlParser::RealTypeDeclContext::REAL() {
  return getTokens(IsrdlParser::REAL);
}

tree::TerminalNode* IsrdlParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(IsrdlParser::REAL, i);
}

tree::TerminalNode* IsrdlParser::RealTypeDeclContext::RANGE() {
  return getToken(IsrdlParser::RANGE, 0);
}

tree::TerminalNode* IsrdlParser::RealTypeDeclContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}


size_t IsrdlParser::RealTypeDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleRealTypeDecl;
}

void IsrdlParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void IsrdlParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

IsrdlParser::RealTypeDeclContext* IsrdlParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 50, IsrdlParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(IsrdlParser::RealID);
    setState(316);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::LPAREN: {
        setState(310);
        match(IsrdlParser::LPAREN);
        setState(311);
        match(IsrdlParser::REAL);
        setState(312);
        match(IsrdlParser::RANGE);
        setState(313);
        match(IsrdlParser::REAL);
        setState(314);
        match(IsrdlParser::RPAREN);
        break;
      }

      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::ID: {
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

IsrdlParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::EnumTypeDeclContext::EnumID() {
  return getToken(IsrdlParser::EnumID, 0);
}

tree::TerminalNode* IsrdlParser::EnumTypeDeclContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

std::vector<IsrdlParser::ContextIDContext *> IsrdlParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<IsrdlParser::ContextIDContext>();
}

IsrdlParser::ContextIDContext* IsrdlParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<IsrdlParser::ContextIDContext>(i);
}

tree::TerminalNode* IsrdlParser::EnumTypeDeclContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> IsrdlParser::EnumTypeDeclContext::COMMA() {
  return getTokens(IsrdlParser::COMMA);
}

tree::TerminalNode* IsrdlParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(IsrdlParser::COMMA, i);
}


size_t IsrdlParser::EnumTypeDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleEnumTypeDecl;
}

void IsrdlParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void IsrdlParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

IsrdlParser::EnumTypeDeclContext* IsrdlParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, IsrdlParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    match(IsrdlParser::EnumID);
    setState(319);
    match(IsrdlParser::LPAREN);
    setState(320);
    contextID();
    setState(325);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IsrdlParser::COMMA) {
      setState(321);
      match(IsrdlParser::COMMA);
      setState(322);
      contextID();
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(328);
    match(IsrdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

IsrdlParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::AttributeDeclContext::AttributeID() {
  return getToken(IsrdlParser::AttributeID, 0);
}

IsrdlParser::TypeDeclContext* IsrdlParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<IsrdlParser::TypeDeclContext>(0);
}

IsrdlParser::ContextIDContext* IsrdlParser::AttributeDeclContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}

tree::TerminalNode* IsrdlParser::AttributeDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}

tree::TerminalNode* IsrdlParser::AttributeDeclContext::ASSIGN() {
  return getToken(IsrdlParser::ASSIGN, 0);
}

IsrdlParser::LiteralValueContext* IsrdlParser::AttributeDeclContext::literalValue() {
  return getRuleContext<IsrdlParser::LiteralValueContext>(0);
}


size_t IsrdlParser::AttributeDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleAttributeDecl;
}

void IsrdlParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void IsrdlParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

IsrdlParser::AttributeDeclContext* IsrdlParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 54, IsrdlParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(IsrdlParser::AttributeID);
    setState(331);
    typeDecl();
    setState(332);
    contextID();
    setState(335);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == IsrdlParser::ASSIGN) {
      setState(333);
      match(IsrdlParser::ASSIGN);
      setState(334);
      literalValue();
    }
    setState(337);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

IsrdlParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::LiteralValueContext::INT() {
  return getToken(IsrdlParser::INT, 0);
}

tree::TerminalNode* IsrdlParser::LiteralValueContext::REAL() {
  return getToken(IsrdlParser::REAL, 0);
}

tree::TerminalNode* IsrdlParser::LiteralValueContext::STRING() {
  return getToken(IsrdlParser::STRING, 0);
}

tree::TerminalNode* IsrdlParser::LiteralValueContext::TrueID() {
  return getToken(IsrdlParser::TrueID, 0);
}

tree::TerminalNode* IsrdlParser::LiteralValueContext::FalseID() {
  return getToken(IsrdlParser::FalseID, 0);
}

IsrdlParser::ContextIDContext* IsrdlParser::LiteralValueContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}


size_t IsrdlParser::LiteralValueContext::getRuleIndex() const {
  return IsrdlParser::RuleLiteralValue;
}

void IsrdlParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void IsrdlParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

IsrdlParser::LiteralValueContext* IsrdlParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 56, IsrdlParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(339);
        match(IsrdlParser::INT);
        break;
      }

      case IsrdlParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(340);
        match(IsrdlParser::REAL);
        break;
      }

      case IsrdlParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(341);
        match(IsrdlParser::STRING);
        break;
      }

      case IsrdlParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(342);
        match(IsrdlParser::TrueID);
        break;
      }

      case IsrdlParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(343);
        match(IsrdlParser::FalseID);
        break;
      }

      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(344);
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

IsrdlParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::TriggerDeclContext* IsrdlParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<IsrdlParser::TriggerDeclContext>(0);
}

IsrdlParser::ContextIDContext* IsrdlParser::SignalParamNameContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}


size_t IsrdlParser::SignalParamNameContext::getRuleIndex() const {
  return IsrdlParser::RuleSignalParamName;
}

void IsrdlParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void IsrdlParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

IsrdlParser::SignalParamNameContext* IsrdlParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 58, IsrdlParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    triggerDecl();
    setState(348);
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

IsrdlParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::ContextIDContext* IsrdlParser::AttributeNameContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}

IsrdlParser::ThisDeclContext* IsrdlParser::AttributeNameContext::thisDecl() {
  return getRuleContext<IsrdlParser::ThisDeclContext>(0);
}


size_t IsrdlParser::AttributeNameContext::getRuleIndex() const {
  return IsrdlParser::RuleAttributeName;
}

void IsrdlParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void IsrdlParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

IsrdlParser::AttributeNameContext* IsrdlParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 60, IsrdlParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::ThisID: {
        setState(350);
        thisDecl();
        break;
      }

      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(354);
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

IsrdlParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ToPortNameContext::ToID() {
  return getToken(IsrdlParser::ToID, 0);
}

IsrdlParser::ContextIDContext* IsrdlParser::ToPortNameContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}


size_t IsrdlParser::ToPortNameContext::getRuleIndex() const {
  return IsrdlParser::RuleToPortName;
}

void IsrdlParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void IsrdlParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

IsrdlParser::ToPortNameContext* IsrdlParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 62, IsrdlParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(IsrdlParser::ToID);
    setState(357);
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

IsrdlParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::AttributeNameContext* IsrdlParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<IsrdlParser::AttributeNameContext>(0);
}

tree::TerminalNode* IsrdlParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(IsrdlParser::ASSIGN, 0);
}

IsrdlParser::ExpressionContext* IsrdlParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<IsrdlParser::ExpressionContext>(0);
}

tree::TerminalNode* IsrdlParser::AttributeAssignStatementContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::AttributeAssignStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleAttributeAssignStatement;
}

void IsrdlParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void IsrdlParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

IsrdlParser::AttributeAssignStatementContext* IsrdlParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, IsrdlParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    attributeName();
    setState(360);
    match(IsrdlParser::ASSIGN);
    setState(361);
    expression();
    setState(362);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

IsrdlParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::TypeDeclContext* IsrdlParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<IsrdlParser::TypeDeclContext>(0);
}

IsrdlParser::ContextIDContext* IsrdlParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}

tree::TerminalNode* IsrdlParser::LocalAssignStatementContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}

tree::TerminalNode* IsrdlParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(IsrdlParser::ASSIGN, 0);
}

IsrdlParser::ExpressionContext* IsrdlParser::LocalAssignStatementContext::expression() {
  return getRuleContext<IsrdlParser::ExpressionContext>(0);
}


size_t IsrdlParser::LocalAssignStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleLocalAssignStatement;
}

void IsrdlParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void IsrdlParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

IsrdlParser::LocalAssignStatementContext* IsrdlParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 66, IsrdlParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    typeDecl();
    setState(365);
    contextID();
    setState(369);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::ASSIGN: {
        setState(366);
        match(IsrdlParser::ASSIGN);
        setState(367);
        expression();
        break;
      }

      case IsrdlParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(371);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

IsrdlParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::SendToStatementContext::SendID() {
  return getToken(IsrdlParser::SendID, 0);
}

IsrdlParser::SignalSendContext* IsrdlParser::SendToStatementContext::signalSend() {
  return getRuleContext<IsrdlParser::SignalSendContext>(0);
}

tree::TerminalNode* IsrdlParser::SendToStatementContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}

IsrdlParser::ToPortNameContext* IsrdlParser::SendToStatementContext::toPortName() {
  return getRuleContext<IsrdlParser::ToPortNameContext>(0);
}


size_t IsrdlParser::SendToStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleSendToStatement;
}

void IsrdlParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void IsrdlParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

IsrdlParser::SendToStatementContext* IsrdlParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, IsrdlParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(IsrdlParser::SendID);
    setState(374);
    signalSend();
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::ToID: {
        setState(375);
        toPortName();
        break;
      }

      case IsrdlParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(379);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

IsrdlParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::AttributeAssignStatementContext* IsrdlParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<IsrdlParser::AttributeAssignStatementContext>(0);
}

IsrdlParser::SendToStatementContext* IsrdlParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<IsrdlParser::SendToStatementContext>(0);
}


size_t IsrdlParser::SingleAssignmentContext::getRuleIndex() const {
  return IsrdlParser::RuleSingleAssignment;
}

void IsrdlParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void IsrdlParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

IsrdlParser::SingleAssignmentContext* IsrdlParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 70, IsrdlParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(383);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::ThisID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(381);
        attributeAssignStatement();
        break;
      }

      case IsrdlParser::SendID: {
        enterOuterAlt(_localctx, 2);
        setState(382);
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

IsrdlParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::MultiAssignmentContext::LBRACE() {
  return getToken(IsrdlParser::LBRACE, 0);
}

tree::TerminalNode* IsrdlParser::MultiAssignmentContext::RBRACE() {
  return getToken(IsrdlParser::RBRACE, 0);
}

std::vector<IsrdlParser::SingleAssignmentContext *> IsrdlParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<IsrdlParser::SingleAssignmentContext>();
}

IsrdlParser::SingleAssignmentContext* IsrdlParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<IsrdlParser::SingleAssignmentContext>(i);
}


size_t IsrdlParser::MultiAssignmentContext::getRuleIndex() const {
  return IsrdlParser::RuleMultiAssignment;
}

void IsrdlParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void IsrdlParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

IsrdlParser::MultiAssignmentContext* IsrdlParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 72, IsrdlParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    match(IsrdlParser::LBRACE);
    setState(389);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 33) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 33)) & ((1ULL << (IsrdlParser::NameID - 33))
      | (1ULL << (IsrdlParser::LabelID - 33))
      | (1ULL << (IsrdlParser::EnabledID - 33))
      | (1ULL << (IsrdlParser::TypeID - 33))
      | (1ULL << (IsrdlParser::ThisID - 33))
      | (1ULL << (IsrdlParser::AttributeID - 33))
      | (1ULL << (IsrdlParser::SignalID - 33))
      | (1ULL << (IsrdlParser::PortID - 33))
      | (1ULL << (IsrdlParser::ImportID - 33))
      | (1ULL << (IsrdlParser::FromID - 33))
      | (1ULL << (IsrdlParser::ToID - 33))
      | (1ULL << (IsrdlParser::SendID - 33))
      | (1ULL << (IsrdlParser::AsID - 33))
      | (1ULL << (IsrdlParser::ID - 33)))) != 0)) {
      setState(386);
      singleAssignment();
      setState(391);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(392);
    match(IsrdlParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

IsrdlParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::SignalDeclContext::SignalID() {
  return getToken(IsrdlParser::SignalID, 0);
}

IsrdlParser::ContextIDContext* IsrdlParser::SignalDeclContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}

tree::TerminalNode* IsrdlParser::SignalDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}

tree::TerminalNode* IsrdlParser::SignalDeclContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

tree::TerminalNode* IsrdlParser::SignalDeclContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}

std::vector<IsrdlParser::ParamDeclContext *> IsrdlParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<IsrdlParser::ParamDeclContext>();
}

IsrdlParser::ParamDeclContext* IsrdlParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<IsrdlParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> IsrdlParser::SignalDeclContext::COMMA() {
  return getTokens(IsrdlParser::COMMA);
}

tree::TerminalNode* IsrdlParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(IsrdlParser::COMMA, i);
}


size_t IsrdlParser::SignalDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleSignalDecl;
}

void IsrdlParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void IsrdlParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

IsrdlParser::SignalDeclContext* IsrdlParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 74, IsrdlParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    match(IsrdlParser::SignalID);
    setState(395);
    contextID();
    setState(410);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::LPAREN: {
        setState(396);
        match(IsrdlParser::LPAREN);
        setState(406);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case IsrdlParser::NameID:
          case IsrdlParser::LabelID:
          case IsrdlParser::EnabledID:
          case IsrdlParser::TypeID:
          case IsrdlParser::IntID:
          case IsrdlParser::RealID:
          case IsrdlParser::BoolID:
          case IsrdlParser::StringID:
          case IsrdlParser::EnumID:
          case IsrdlParser::AttributeID:
          case IsrdlParser::SignalID:
          case IsrdlParser::PortID:
          case IsrdlParser::ImportID:
          case IsrdlParser::FromID:
          case IsrdlParser::ToID:
          case IsrdlParser::AsID:
          case IsrdlParser::ID: {
            setState(397);
            paramDecl();
            setState(402);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == IsrdlParser::COMMA) {
              setState(398);
              match(IsrdlParser::COMMA);
              setState(399);
              paramDecl();
              setState(404);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case IsrdlParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(408);
        match(IsrdlParser::RPAREN);
        break;
      }

      case IsrdlParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(412);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

IsrdlParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::TypeDeclContext* IsrdlParser::ParamDeclContext::typeDecl() {
  return getRuleContext<IsrdlParser::TypeDeclContext>(0);
}

IsrdlParser::ContextIDContext* IsrdlParser::ParamDeclContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}


size_t IsrdlParser::ParamDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleParamDecl;
}

void IsrdlParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void IsrdlParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

IsrdlParser::ParamDeclContext* IsrdlParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 76, IsrdlParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    typeDecl();
    setState(415);
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

IsrdlParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::FunctionDeclContext::FunctionID() {
  return getToken(IsrdlParser::FunctionID, 0);
}

IsrdlParser::TypeDeclContext* IsrdlParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<IsrdlParser::TypeDeclContext>(0);
}

IsrdlParser::IdPathContext* IsrdlParser::FunctionDeclContext::idPath() {
  return getRuleContext<IsrdlParser::IdPathContext>(0);
}

tree::TerminalNode* IsrdlParser::FunctionDeclContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

tree::TerminalNode* IsrdlParser::FunctionDeclContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}

IsrdlParser::NestedStatementBodyContext* IsrdlParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<IsrdlParser::NestedStatementBodyContext>(0);
}

IsrdlParser::FunctionParametersContext* IsrdlParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<IsrdlParser::FunctionParametersContext>(0);
}


size_t IsrdlParser::FunctionDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleFunctionDecl;
}

void IsrdlParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void IsrdlParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

IsrdlParser::FunctionDeclContext* IsrdlParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 78, IsrdlParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(417);
    match(IsrdlParser::FunctionID);
    setState(418);
    typeDecl();
    setState(419);
    idPath();
    setState(420);
    match(IsrdlParser::LPAREN);
    setState(423);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::IntID:
      case IsrdlParser::RealID:
      case IsrdlParser::BoolID:
      case IsrdlParser::StringID:
      case IsrdlParser::EnumID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::ID: {
        setState(421);
        functionParameters();
        break;
      }

      case IsrdlParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(425);
    match(IsrdlParser::RPAREN);
    setState(426);
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

IsrdlParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IsrdlParser::ParamDeclContext *> IsrdlParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<IsrdlParser::ParamDeclContext>();
}

IsrdlParser::ParamDeclContext* IsrdlParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<IsrdlParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> IsrdlParser::FunctionParametersContext::COMMA() {
  return getTokens(IsrdlParser::COMMA);
}

tree::TerminalNode* IsrdlParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(IsrdlParser::COMMA, i);
}


size_t IsrdlParser::FunctionParametersContext::getRuleIndex() const {
  return IsrdlParser::RuleFunctionParameters;
}

void IsrdlParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void IsrdlParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

IsrdlParser::FunctionParametersContext* IsrdlParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 80, IsrdlParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    paramDecl();
    setState(433);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IsrdlParser::COMMA) {
      setState(429);
      match(IsrdlParser::COMMA);
      setState(430);
      paramDecl();
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

//----------------- FunctionCallContext ------------------------------------------------------------------

IsrdlParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::IdPathContext* IsrdlParser::FunctionCallContext::idPath() {
  return getRuleContext<IsrdlParser::IdPathContext>(0);
}

tree::TerminalNode* IsrdlParser::FunctionCallContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

IsrdlParser::FunctionCallBodyContext* IsrdlParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<IsrdlParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* IsrdlParser::FunctionCallContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}


size_t IsrdlParser::FunctionCallContext::getRuleIndex() const {
  return IsrdlParser::RuleFunctionCall;
}

void IsrdlParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void IsrdlParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

IsrdlParser::FunctionCallContext* IsrdlParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 82, IsrdlParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    idPath();
    setState(437);
    match(IsrdlParser::LPAREN);
    setState(438);
    functionCallBody();
    setState(439);
    match(IsrdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

IsrdlParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::FunctionCallBodyOptionalContext* IsrdlParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<IsrdlParser::FunctionCallBodyOptionalContext>(0);
}

IsrdlParser::LiteralValueContext* IsrdlParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<IsrdlParser::LiteralValueContext>(0);
}

IsrdlParser::SignalParamNameContext* IsrdlParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<IsrdlParser::SignalParamNameContext>(0);
}

IsrdlParser::AttributeNameContext* IsrdlParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<IsrdlParser::AttributeNameContext>(0);
}

IsrdlParser::FunctionCallContext* IsrdlParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<IsrdlParser::FunctionCallContext>(0);
}


size_t IsrdlParser::FunctionCallBodyContext::getRuleIndex() const {
  return IsrdlParser::RuleFunctionCallBody;
}

void IsrdlParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void IsrdlParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

IsrdlParser::FunctionCallBodyContext* IsrdlParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 84, IsrdlParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(441);
      literalValue();
      break;
    }

    case 2: {
      setState(442);
      signalParamName();
      break;
    }

    case 3: {
      setState(443);
      attributeName();
      break;
    }

    case 4: {
      setState(444);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(448);
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

IsrdlParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(IsrdlParser::COMMA, 0);
}

IsrdlParser::FunctionCallBodyContext* IsrdlParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<IsrdlParser::FunctionCallBodyContext>(0);
}


size_t IsrdlParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return IsrdlParser::RuleFunctionCallBodyOptional;
}

void IsrdlParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void IsrdlParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

IsrdlParser::FunctionCallBodyOptionalContext* IsrdlParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 86, IsrdlParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(453);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(450);
        match(IsrdlParser::COMMA);
        setState(451);
        functionCallBody();
        break;
      }

      case IsrdlParser::RPAREN: {
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

IsrdlParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ContextIDContext::ID() {
  return getToken(IsrdlParser::ID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::NameID() {
  return getToken(IsrdlParser::NameID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::LabelID() {
  return getToken(IsrdlParser::LabelID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::EnabledID() {
  return getToken(IsrdlParser::EnabledID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::TypeID() {
  return getToken(IsrdlParser::TypeID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::AttributeID() {
  return getToken(IsrdlParser::AttributeID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::SignalID() {
  return getToken(IsrdlParser::SignalID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::PortID() {
  return getToken(IsrdlParser::PortID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::ImportID() {
  return getToken(IsrdlParser::ImportID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::FromID() {
  return getToken(IsrdlParser::FromID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::ToID() {
  return getToken(IsrdlParser::ToID, 0);
}

tree::TerminalNode* IsrdlParser::ContextIDContext::AsID() {
  return getToken(IsrdlParser::AsID, 0);
}


size_t IsrdlParser::ContextIDContext::getRuleIndex() const {
  return IsrdlParser::RuleContextID;
}

void IsrdlParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void IsrdlParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

IsrdlParser::ContextIDContext* IsrdlParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 88, IsrdlParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    _la = _input->LA(1);
    if (!(((((_la - 33) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 33)) & ((1ULL << (IsrdlParser::NameID - 33))
      | (1ULL << (IsrdlParser::LabelID - 33))
      | (1ULL << (IsrdlParser::EnabledID - 33))
      | (1ULL << (IsrdlParser::TypeID - 33))
      | (1ULL << (IsrdlParser::AttributeID - 33))
      | (1ULL << (IsrdlParser::SignalID - 33))
      | (1ULL << (IsrdlParser::PortID - 33))
      | (1ULL << (IsrdlParser::ImportID - 33))
      | (1ULL << (IsrdlParser::FromID - 33))
      | (1ULL << (IsrdlParser::ToID - 33))
      | (1ULL << (IsrdlParser::AsID - 33))
      | (1ULL << (IsrdlParser::ID - 33)))) != 0))) {
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

IsrdlParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::TriggerDeclContext::DOT() {
  return getToken(IsrdlParser::DOT, 0);
}

tree::TerminalNode* IsrdlParser::TriggerDeclContext::MessageTrigger() {
  return getToken(IsrdlParser::MessageTrigger, 0);
}

tree::TerminalNode* IsrdlParser::TriggerDeclContext::TriggerID() {
  return getToken(IsrdlParser::TriggerID, 0);
}


size_t IsrdlParser::TriggerDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleTriggerDecl;
}

void IsrdlParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void IsrdlParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

IsrdlParser::TriggerDeclContext* IsrdlParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 90, IsrdlParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    _la = _input->LA(1);
    if (!(_la == IsrdlParser::TriggerID

    || _la == IsrdlParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(458);
    match(IsrdlParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

IsrdlParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ThisDeclContext::ThisID() {
  return getToken(IsrdlParser::ThisID, 0);
}

tree::TerminalNode* IsrdlParser::ThisDeclContext::DOT() {
  return getToken(IsrdlParser::DOT, 0);
}


size_t IsrdlParser::ThisDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleThisDecl;
}

void IsrdlParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void IsrdlParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

IsrdlParser::ThisDeclContext* IsrdlParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 92, IsrdlParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    match(IsrdlParser::ThisID);
    setState(461);
    match(IsrdlParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

IsrdlParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::PortDeclContext::PortID() {
  return getToken(IsrdlParser::PortID, 0);
}

std::vector<IsrdlParser::ContextIDContext *> IsrdlParser::PortDeclContext::contextID() {
  return getRuleContexts<IsrdlParser::ContextIDContext>();
}

IsrdlParser::ContextIDContext* IsrdlParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<IsrdlParser::ContextIDContext>(i);
}

tree::TerminalNode* IsrdlParser::PortDeclContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> IsrdlParser::PortDeclContext::COMMA() {
  return getTokens(IsrdlParser::COMMA);
}

tree::TerminalNode* IsrdlParser::PortDeclContext::COMMA(size_t i) {
  return getToken(IsrdlParser::COMMA, i);
}


size_t IsrdlParser::PortDeclContext::getRuleIndex() const {
  return IsrdlParser::RulePortDecl;
}

void IsrdlParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void IsrdlParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

IsrdlParser::PortDeclContext* IsrdlParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 94, IsrdlParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(463);
    match(IsrdlParser::PortID);
    setState(464);
    contextID();
    setState(469);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IsrdlParser::COMMA) {
      setState(465);
      match(IsrdlParser::COMMA);
      setState(466);
      contextID();
      setState(471);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(472);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

IsrdlParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IsrdlParser::ContextIDContext *> IsrdlParser::IdPathContext::contextID() {
  return getRuleContexts<IsrdlParser::ContextIDContext>();
}

IsrdlParser::ContextIDContext* IsrdlParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<IsrdlParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> IsrdlParser::IdPathContext::DOT() {
  return getTokens(IsrdlParser::DOT);
}

tree::TerminalNode* IsrdlParser::IdPathContext::DOT(size_t i) {
  return getToken(IsrdlParser::DOT, i);
}


size_t IsrdlParser::IdPathContext::getRuleIndex() const {
  return IsrdlParser::RuleIdPath;
}

void IsrdlParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void IsrdlParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

IsrdlParser::IdPathContext* IsrdlParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 96, IsrdlParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(474);
    contextID();
    setState(479);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IsrdlParser::DOT) {
      setState(475);
      match(IsrdlParser::DOT);
      setState(476);
      contextID();
      setState(481);
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

IsrdlParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::StatementBodyContext* IsrdlParser::StatementDeclContext::statementBody() {
  return getRuleContext<IsrdlParser::StatementBodyContext>(0);
}

IsrdlParser::NestedStatementBodyContext* IsrdlParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<IsrdlParser::NestedStatementBodyContext>(0);
}


size_t IsrdlParser::StatementDeclContext::getRuleIndex() const {
  return IsrdlParser::RuleStatementDecl;
}

void IsrdlParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void IsrdlParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

IsrdlParser::StatementDeclContext* IsrdlParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 98, IsrdlParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(484);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::IntID:
      case IsrdlParser::RealID:
      case IsrdlParser::BoolID:
      case IsrdlParser::StringID:
      case IsrdlParser::ThisID:
      case IsrdlParser::ReturnID:
      case IsrdlParser::EnumID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::SendID:
      case IsrdlParser::SwitchID:
      case IsrdlParser::IfID:
      case IsrdlParser::AsID:
      case IsrdlParser::BREAK:
      case IsrdlParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(482);
        statementBody();
        break;
      }

      case IsrdlParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(483);
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

IsrdlParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::FunctionCallStatementContext* IsrdlParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<IsrdlParser::FunctionCallStatementContext>(0);
}

IsrdlParser::AttributeAssignStatementContext* IsrdlParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<IsrdlParser::AttributeAssignStatementContext>(0);
}

IsrdlParser::SwitchStatementContext* IsrdlParser::StatementBodyContext::switchStatement() {
  return getRuleContext<IsrdlParser::SwitchStatementContext>(0);
}

IsrdlParser::ConditionalStatementContext* IsrdlParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<IsrdlParser::ConditionalStatementContext>(0);
}

IsrdlParser::LocalAssignStatementContext* IsrdlParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<IsrdlParser::LocalAssignStatementContext>(0);
}

IsrdlParser::SendToStatementContext* IsrdlParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<IsrdlParser::SendToStatementContext>(0);
}

IsrdlParser::BreakStatementContext* IsrdlParser::StatementBodyContext::breakStatement() {
  return getRuleContext<IsrdlParser::BreakStatementContext>(0);
}

IsrdlParser::ReturnStatementContext* IsrdlParser::StatementBodyContext::returnStatement() {
  return getRuleContext<IsrdlParser::ReturnStatementContext>(0);
}


size_t IsrdlParser::StatementBodyContext::getRuleIndex() const {
  return IsrdlParser::RuleStatementBody;
}

void IsrdlParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void IsrdlParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

IsrdlParser::StatementBodyContext* IsrdlParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 100, IsrdlParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(494);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(486);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(487);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(488);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(489);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(490);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(491);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(492);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(493);
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

IsrdlParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::FunctionCallContext* IsrdlParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<IsrdlParser::FunctionCallContext>(0);
}

tree::TerminalNode* IsrdlParser::FunctionCallStatementContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::FunctionCallStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleFunctionCallStatement;
}

void IsrdlParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void IsrdlParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

IsrdlParser::FunctionCallStatementContext* IsrdlParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 102, IsrdlParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    functionCall();
    setState(497);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

IsrdlParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::NestedStatementBodyContext::LBRACE() {
  return getToken(IsrdlParser::LBRACE, 0);
}

tree::TerminalNode* IsrdlParser::NestedStatementBodyContext::RBRACE() {
  return getToken(IsrdlParser::RBRACE, 0);
}

std::vector<IsrdlParser::StatementBodyContext *> IsrdlParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<IsrdlParser::StatementBodyContext>();
}

IsrdlParser::StatementBodyContext* IsrdlParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<IsrdlParser::StatementBodyContext>(i);
}


size_t IsrdlParser::NestedStatementBodyContext::getRuleIndex() const {
  return IsrdlParser::RuleNestedStatementBody;
}

void IsrdlParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void IsrdlParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

IsrdlParser::NestedStatementBodyContext* IsrdlParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 104, IsrdlParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    match(IsrdlParser::LBRACE);
    setState(503);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 33) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 33)) & ((1ULL << (IsrdlParser::NameID - 33))
      | (1ULL << (IsrdlParser::LabelID - 33))
      | (1ULL << (IsrdlParser::EnabledID - 33))
      | (1ULL << (IsrdlParser::TypeID - 33))
      | (1ULL << (IsrdlParser::IntID - 33))
      | (1ULL << (IsrdlParser::RealID - 33))
      | (1ULL << (IsrdlParser::BoolID - 33))
      | (1ULL << (IsrdlParser::StringID - 33))
      | (1ULL << (IsrdlParser::ThisID - 33))
      | (1ULL << (IsrdlParser::ReturnID - 33))
      | (1ULL << (IsrdlParser::EnumID - 33))
      | (1ULL << (IsrdlParser::AttributeID - 33))
      | (1ULL << (IsrdlParser::SignalID - 33))
      | (1ULL << (IsrdlParser::PortID - 33))
      | (1ULL << (IsrdlParser::ImportID - 33))
      | (1ULL << (IsrdlParser::FromID - 33))
      | (1ULL << (IsrdlParser::ToID - 33))
      | (1ULL << (IsrdlParser::SendID - 33))
      | (1ULL << (IsrdlParser::SwitchID - 33))
      | (1ULL << (IsrdlParser::IfID - 33))
      | (1ULL << (IsrdlParser::AsID - 33))
      | (1ULL << (IsrdlParser::BREAK - 33))
      | (1ULL << (IsrdlParser::ID - 33)))) != 0)) {
      setState(500);
      statementBody();
      setState(505);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(506);
    match(IsrdlParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

IsrdlParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ReturnStatementContext::ReturnID() {
  return getToken(IsrdlParser::ReturnID, 0);
}

IsrdlParser::OperationContext* IsrdlParser::ReturnStatementContext::operation() {
  return getRuleContext<IsrdlParser::OperationContext>(0);
}

tree::TerminalNode* IsrdlParser::ReturnStatementContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::ReturnStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleReturnStatement;
}

void IsrdlParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void IsrdlParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

IsrdlParser::ReturnStatementContext* IsrdlParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 106, IsrdlParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(508);
    match(IsrdlParser::ReturnID);
    setState(509);
    operation();
    setState(510);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

IsrdlParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::BreakStatementContext::BREAK() {
  return getToken(IsrdlParser::BREAK, 0);
}

tree::TerminalNode* IsrdlParser::BreakStatementContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::BreakStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleBreakStatement;
}

void IsrdlParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void IsrdlParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

IsrdlParser::BreakStatementContext* IsrdlParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 108, IsrdlParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    match(IsrdlParser::BREAK);
    setState(513);
    match(IsrdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

IsrdlParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::AtomContext* IsrdlParser::OperationContext::atom() {
  return getRuleContext<IsrdlParser::AtomContext>(0);
}

IsrdlParser::OperationOptionalContext* IsrdlParser::OperationContext::operationOptional() {
  return getRuleContext<IsrdlParser::OperationOptionalContext>(0);
}

tree::TerminalNode* IsrdlParser::OperationContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

IsrdlParser::OperationContext* IsrdlParser::OperationContext::operation() {
  return getRuleContext<IsrdlParser::OperationContext>(0);
}

tree::TerminalNode* IsrdlParser::OperationContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}

tree::TerminalNode* IsrdlParser::OperationContext::MINUS() {
  return getToken(IsrdlParser::MINUS, 0);
}

tree::TerminalNode* IsrdlParser::OperationContext::NotIdSymbol() {
  return getToken(IsrdlParser::NotIdSymbol, 0);
}


size_t IsrdlParser::OperationContext::getRuleIndex() const {
  return IsrdlParser::RuleOperation;
}

void IsrdlParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void IsrdlParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

IsrdlParser::OperationContext* IsrdlParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 110, IsrdlParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(526);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::INT:
      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::TriggerID:
      case IsrdlParser::MessageTrigger:
      case IsrdlParser::ThisID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::AsID:
      case IsrdlParser::TrueID:
      case IsrdlParser::FalseID:
      case IsrdlParser::REAL:
      case IsrdlParser::STRING:
      case IsrdlParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(515);
        atom();
        setState(516);
        operationOptional();
        break;
      }

      case IsrdlParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(518);
        match(IsrdlParser::LPAREN);
        setState(519);
        operation();
        setState(520);
        match(IsrdlParser::RPAREN);
        break;
      }

      case IsrdlParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(522);
        match(IsrdlParser::MINUS);
        setState(523);
        operation();
        break;
      }

      case IsrdlParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(524);
        match(IsrdlParser::NotIdSymbol);
        setState(525);
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

IsrdlParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::OperationContext* IsrdlParser::OperationOptionalContext::operation() {
  return getRuleContext<IsrdlParser::OperationContext>(0);
}

tree::TerminalNode* IsrdlParser::OperationOptionalContext::MULT() {
  return getToken(IsrdlParser::MULT, 0);
}

tree::TerminalNode* IsrdlParser::OperationOptionalContext::DIV() {
  return getToken(IsrdlParser::DIV, 0);
}

tree::TerminalNode* IsrdlParser::OperationOptionalContext::PLUS() {
  return getToken(IsrdlParser::PLUS, 0);
}

tree::TerminalNode* IsrdlParser::OperationOptionalContext::MINUS() {
  return getToken(IsrdlParser::MINUS, 0);
}


size_t IsrdlParser::OperationOptionalContext::getRuleIndex() const {
  return IsrdlParser::RuleOperationOptional;
}

void IsrdlParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void IsrdlParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

IsrdlParser::OperationOptionalContext* IsrdlParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 112, IsrdlParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(531);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::MINUS:
      case IsrdlParser::PLUS:
      case IsrdlParser::MULT:
      case IsrdlParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(528);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 31) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 31)) & ((1ULL << (IsrdlParser::MINUS - 31))
          | (1ULL << (IsrdlParser::PLUS - 31))
          | (1ULL << (IsrdlParser::MULT - 31))
          | (1ULL << (IsrdlParser::DIV - 31)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(529);
        operation();
        break;
      }

      case IsrdlParser::SEMI:
      case IsrdlParser::NotIdSymbol:
      case IsrdlParser::AndIdSymbol:
      case IsrdlParser::OrIdSymbol:
      case IsrdlParser::NotIdWord:
      case IsrdlParser::AndIdWord:
      case IsrdlParser::OrIdWord:
      case IsrdlParser::ASSIGN:
      case IsrdlParser::RPAREN:
      case IsrdlParser::LESSTHAN:
      case IsrdlParser::GREATERTHAN: {
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

IsrdlParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ExpressionContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

IsrdlParser::ExpressionContext* IsrdlParser::ExpressionContext::expression() {
  return getRuleContext<IsrdlParser::ExpressionContext>(0);
}

tree::TerminalNode* IsrdlParser::ExpressionContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}

IsrdlParser::ExpressionOptionalContext* IsrdlParser::ExpressionContext::expressionOptional() {
  return getRuleContext<IsrdlParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* IsrdlParser::ExpressionContext::NotIdSymbol() {
  return getToken(IsrdlParser::NotIdSymbol, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionContext::NotIdWord() {
  return getToken(IsrdlParser::NotIdWord, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionContext::MINUS() {
  return getToken(IsrdlParser::MINUS, 0);
}

IsrdlParser::OperationContext* IsrdlParser::ExpressionContext::operation() {
  return getRuleContext<IsrdlParser::OperationContext>(0);
}


size_t IsrdlParser::ExpressionContext::getRuleIndex() const {
  return IsrdlParser::RuleExpression;
}

void IsrdlParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void IsrdlParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

IsrdlParser::ExpressionContext* IsrdlParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 114, IsrdlParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(547);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(533);
      match(IsrdlParser::LPAREN);
      setState(534);
      expression();
      setState(535);
      match(IsrdlParser::RPAREN);
      setState(536);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(538);
      match(IsrdlParser::NotIdSymbol);
      setState(539);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(540);
      match(IsrdlParser::NotIdWord);
      setState(541);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(542);
      match(IsrdlParser::MINUS);
      setState(543);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(544);
      operation();
      setState(545);
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

IsrdlParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::ExpressionContext* IsrdlParser::ExpressionOptionalContext::expression() {
  return getRuleContext<IsrdlParser::ExpressionContext>(0);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(IsrdlParser::OrIdSymbol, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(IsrdlParser::OrIdWord, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(IsrdlParser::AndIdSymbol, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(IsrdlParser::AndIdWord, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(IsrdlParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> IsrdlParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(IsrdlParser::ASSIGN);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(IsrdlParser::ASSIGN, i);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(IsrdlParser::NotIdSymbol, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(IsrdlParser::LESSTHAN, 0);
}

tree::TerminalNode* IsrdlParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(IsrdlParser::GREATERTHAN, 0);
}


size_t IsrdlParser::ExpressionOptionalContext::getRuleIndex() const {
  return IsrdlParser::RuleExpressionOptional;
}

void IsrdlParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void IsrdlParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

IsrdlParser::ExpressionOptionalContext* IsrdlParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 116, IsrdlParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(572);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::NotIdSymbol:
      case IsrdlParser::AndIdSymbol:
      case IsrdlParser::OrIdSymbol:
      case IsrdlParser::NotIdWord:
      case IsrdlParser::AndIdWord:
      case IsrdlParser::OrIdWord:
      case IsrdlParser::ASSIGN:
      case IsrdlParser::LESSTHAN:
      case IsrdlParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(568);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case IsrdlParser::OrIdSymbol: {
            setState(549);
            match(IsrdlParser::OrIdSymbol);
            break;
          }

          case IsrdlParser::OrIdWord: {
            setState(550);
            match(IsrdlParser::OrIdWord);
            break;
          }

          case IsrdlParser::AndIdSymbol: {
            setState(551);
            match(IsrdlParser::AndIdSymbol);
            break;
          }

          case IsrdlParser::AndIdWord: {
            setState(552);
            match(IsrdlParser::AndIdWord);
            break;
          }

          case IsrdlParser::ASSIGN: {
            setState(553);
            match(IsrdlParser::ASSIGN);
            setState(554);
            match(IsrdlParser::ASSIGN);
            break;
          }

          case IsrdlParser::NotIdSymbol: {
            setState(555);
            match(IsrdlParser::NotIdSymbol);
            setState(556);
            match(IsrdlParser::ASSIGN);
            break;
          }

          case IsrdlParser::NotIdWord: {
            setState(557);
            match(IsrdlParser::NotIdWord);
            break;
          }

          case IsrdlParser::LESSTHAN: {
            setState(558);
            match(IsrdlParser::LESSTHAN);
            setState(561);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case IsrdlParser::ASSIGN: {
                setState(559);
                match(IsrdlParser::ASSIGN);
                break;
              }

              case IsrdlParser::INT:
              case IsrdlParser::MINUS:
              case IsrdlParser::NameID:
              case IsrdlParser::LabelID:
              case IsrdlParser::EnabledID:
              case IsrdlParser::TypeID:
              case IsrdlParser::TriggerID:
              case IsrdlParser::MessageTrigger:
              case IsrdlParser::ThisID:
              case IsrdlParser::AttributeID:
              case IsrdlParser::SignalID:
              case IsrdlParser::PortID:
              case IsrdlParser::ImportID:
              case IsrdlParser::FromID:
              case IsrdlParser::ToID:
              case IsrdlParser::AsID:
              case IsrdlParser::NotIdSymbol:
              case IsrdlParser::NotIdWord:
              case IsrdlParser::TrueID:
              case IsrdlParser::FalseID:
              case IsrdlParser::REAL:
              case IsrdlParser::STRING:
              case IsrdlParser::ID:
              case IsrdlParser::LPAREN: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case IsrdlParser::GREATERTHAN: {
            setState(563);
            match(IsrdlParser::GREATERTHAN);
            setState(566);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case IsrdlParser::ASSIGN: {
                setState(564);
                match(IsrdlParser::ASSIGN);
                break;
              }

              case IsrdlParser::INT:
              case IsrdlParser::MINUS:
              case IsrdlParser::NameID:
              case IsrdlParser::LabelID:
              case IsrdlParser::EnabledID:
              case IsrdlParser::TypeID:
              case IsrdlParser::TriggerID:
              case IsrdlParser::MessageTrigger:
              case IsrdlParser::ThisID:
              case IsrdlParser::AttributeID:
              case IsrdlParser::SignalID:
              case IsrdlParser::PortID:
              case IsrdlParser::ImportID:
              case IsrdlParser::FromID:
              case IsrdlParser::ToID:
              case IsrdlParser::AsID:
              case IsrdlParser::NotIdSymbol:
              case IsrdlParser::NotIdWord:
              case IsrdlParser::TrueID:
              case IsrdlParser::FalseID:
              case IsrdlParser::REAL:
              case IsrdlParser::STRING:
              case IsrdlParser::ID:
              case IsrdlParser::LPAREN: {
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
        setState(570);
        expression();
        break;
      }

      case IsrdlParser::SEMI:
      case IsrdlParser::RPAREN: {
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

IsrdlParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::IfStatementContext* IsrdlParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<IsrdlParser::IfStatementContext>(0);
}

IsrdlParser::ElseStatementContext* IsrdlParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<IsrdlParser::ElseStatementContext>(0);
}


size_t IsrdlParser::ConditionalStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleConditionalStatement;
}

void IsrdlParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void IsrdlParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

IsrdlParser::ConditionalStatementContext* IsrdlParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, IsrdlParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(574);
    ifStatement();
    setState(577);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(575);
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

IsrdlParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::IfStatementContext::IfID() {
  return getToken(IsrdlParser::IfID, 0);
}

IsrdlParser::IfEuTContext* IsrdlParser::IfStatementContext::ifEuT() {
  return getRuleContext<IsrdlParser::IfEuTContext>(0);
}

IsrdlParser::StatementDeclContext* IsrdlParser::IfStatementContext::statementDecl() {
  return getRuleContext<IsrdlParser::StatementDeclContext>(0);
}

tree::TerminalNode* IsrdlParser::IfStatementContext::SEMI() {
  return getToken(IsrdlParser::SEMI, 0);
}


size_t IsrdlParser::IfStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleIfStatement;
}

void IsrdlParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void IsrdlParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

IsrdlParser::IfStatementContext* IsrdlParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 120, IsrdlParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    match(IsrdlParser::IfID);
    setState(580);
    ifEuT();
    setState(583);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::LBRACE:
      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::IntID:
      case IsrdlParser::RealID:
      case IsrdlParser::BoolID:
      case IsrdlParser::StringID:
      case IsrdlParser::ThisID:
      case IsrdlParser::ReturnID:
      case IsrdlParser::EnumID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::SendID:
      case IsrdlParser::SwitchID:
      case IsrdlParser::IfID:
      case IsrdlParser::AsID:
      case IsrdlParser::BREAK:
      case IsrdlParser::ID: {
        setState(581);
        statementDecl();
        break;
      }

      case IsrdlParser::SEMI: {
        setState(582);
        match(IsrdlParser::SEMI);
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

IsrdlParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::IfEuTContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

IsrdlParser::ExpressionContext* IsrdlParser::IfEuTContext::expression() {
  return getRuleContext<IsrdlParser::ExpressionContext>(0);
}

tree::TerminalNode* IsrdlParser::IfEuTContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}


size_t IsrdlParser::IfEuTContext::getRuleIndex() const {
  return IsrdlParser::RuleIfEuT;
}

void IsrdlParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void IsrdlParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

IsrdlParser::IfEuTContext* IsrdlParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 122, IsrdlParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    match(IsrdlParser::LPAREN);
    setState(586);
    expression();
    setState(587);
    match(IsrdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

IsrdlParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::ElseStatementContext::ElseID() {
  return getToken(IsrdlParser::ElseID, 0);
}

IsrdlParser::StatementDeclContext* IsrdlParser::ElseStatementContext::statementDecl() {
  return getRuleContext<IsrdlParser::StatementDeclContext>(0);
}


size_t IsrdlParser::ElseStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleElseStatement;
}

void IsrdlParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void IsrdlParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

IsrdlParser::ElseStatementContext* IsrdlParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 124, IsrdlParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(IsrdlParser::ElseID);
    setState(590);
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

IsrdlParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::SwitchStatementContext::SwitchID() {
  return getToken(IsrdlParser::SwitchID, 0);
}

IsrdlParser::SwitchPuTContext* IsrdlParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<IsrdlParser::SwitchPuTContext>(0);
}

tree::TerminalNode* IsrdlParser::SwitchStatementContext::LBRACE() {
  return getToken(IsrdlParser::LBRACE, 0);
}

tree::TerminalNode* IsrdlParser::SwitchStatementContext::RBRACE() {
  return getToken(IsrdlParser::RBRACE, 0);
}

IsrdlParser::DefaultStatementContext* IsrdlParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<IsrdlParser::DefaultStatementContext>(0);
}

std::vector<IsrdlParser::CaseStatementContext *> IsrdlParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<IsrdlParser::CaseStatementContext>();
}

IsrdlParser::CaseStatementContext* IsrdlParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<IsrdlParser::CaseStatementContext>(i);
}


size_t IsrdlParser::SwitchStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleSwitchStatement;
}

void IsrdlParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void IsrdlParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

IsrdlParser::SwitchStatementContext* IsrdlParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, IsrdlParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(592);
    match(IsrdlParser::SwitchID);
    setState(593);
    switchPuT();
    setState(594);
    match(IsrdlParser::LBRACE);
    setState(598);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IsrdlParser::CaseID) {
      setState(595);
      caseStatement();
      setState(600);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(603);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::DefaultID: {
        setState(601);
        defaultStatement();
        break;
      }

      case IsrdlParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(605);
    match(IsrdlParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

IsrdlParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::SwitchPuTContext::LPAREN() {
  return getToken(IsrdlParser::LPAREN, 0);
}

IsrdlParser::ContextIDContext* IsrdlParser::SwitchPuTContext::contextID() {
  return getRuleContext<IsrdlParser::ContextIDContext>(0);
}

tree::TerminalNode* IsrdlParser::SwitchPuTContext::RPAREN() {
  return getToken(IsrdlParser::RPAREN, 0);
}


size_t IsrdlParser::SwitchPuTContext::getRuleIndex() const {
  return IsrdlParser::RuleSwitchPuT;
}

void IsrdlParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void IsrdlParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

IsrdlParser::SwitchPuTContext* IsrdlParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 128, IsrdlParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    match(IsrdlParser::LPAREN);
    setState(608);
    contextID();
    setState(609);
    match(IsrdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

IsrdlParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::CaseStatementContext::CaseID() {
  return getToken(IsrdlParser::CaseID, 0);
}

IsrdlParser::LiteralValueContext* IsrdlParser::CaseStatementContext::literalValue() {
  return getRuleContext<IsrdlParser::LiteralValueContext>(0);
}

tree::TerminalNode* IsrdlParser::CaseStatementContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

IsrdlParser::NestedStatementBodyContext* IsrdlParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<IsrdlParser::NestedStatementBodyContext>(0);
}

std::vector<IsrdlParser::StatementBodyContext *> IsrdlParser::CaseStatementContext::statementBody() {
  return getRuleContexts<IsrdlParser::StatementBodyContext>();
}

IsrdlParser::StatementBodyContext* IsrdlParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<IsrdlParser::StatementBodyContext>(i);
}


size_t IsrdlParser::CaseStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleCaseStatement;
}

void IsrdlParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void IsrdlParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

IsrdlParser::CaseStatementContext* IsrdlParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 130, IsrdlParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(611);
    match(IsrdlParser::CaseID);
    setState(612);
    literalValue();
    setState(613);
    match(IsrdlParser::COLON);
    setState(621);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::LBRACE: {
        setState(614);
        nestedStatementBody();
        break;
      }

      case IsrdlParser::RBRACE:
      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::IntID:
      case IsrdlParser::RealID:
      case IsrdlParser::BoolID:
      case IsrdlParser::StringID:
      case IsrdlParser::ThisID:
      case IsrdlParser::ReturnID:
      case IsrdlParser::EnumID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::SendID:
      case IsrdlParser::SwitchID:
      case IsrdlParser::CaseID:
      case IsrdlParser::DefaultID:
      case IsrdlParser::IfID:
      case IsrdlParser::AsID:
      case IsrdlParser::BREAK:
      case IsrdlParser::ID: {
        setState(618);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 33) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 33)) & ((1ULL << (IsrdlParser::NameID - 33))
          | (1ULL << (IsrdlParser::LabelID - 33))
          | (1ULL << (IsrdlParser::EnabledID - 33))
          | (1ULL << (IsrdlParser::TypeID - 33))
          | (1ULL << (IsrdlParser::IntID - 33))
          | (1ULL << (IsrdlParser::RealID - 33))
          | (1ULL << (IsrdlParser::BoolID - 33))
          | (1ULL << (IsrdlParser::StringID - 33))
          | (1ULL << (IsrdlParser::ThisID - 33))
          | (1ULL << (IsrdlParser::ReturnID - 33))
          | (1ULL << (IsrdlParser::EnumID - 33))
          | (1ULL << (IsrdlParser::AttributeID - 33))
          | (1ULL << (IsrdlParser::SignalID - 33))
          | (1ULL << (IsrdlParser::PortID - 33))
          | (1ULL << (IsrdlParser::ImportID - 33))
          | (1ULL << (IsrdlParser::FromID - 33))
          | (1ULL << (IsrdlParser::ToID - 33))
          | (1ULL << (IsrdlParser::SendID - 33))
          | (1ULL << (IsrdlParser::SwitchID - 33))
          | (1ULL << (IsrdlParser::IfID - 33))
          | (1ULL << (IsrdlParser::AsID - 33))
          | (1ULL << (IsrdlParser::BREAK - 33))
          | (1ULL << (IsrdlParser::ID - 33)))) != 0)) {
          setState(615);
          statementBody();
          setState(620);
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

IsrdlParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IsrdlParser::DefaultStatementContext::DefaultID() {
  return getToken(IsrdlParser::DefaultID, 0);
}

tree::TerminalNode* IsrdlParser::DefaultStatementContext::COLON() {
  return getToken(IsrdlParser::COLON, 0);
}

IsrdlParser::NestedStatementBodyContext* IsrdlParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<IsrdlParser::NestedStatementBodyContext>(0);
}

std::vector<IsrdlParser::StatementBodyContext *> IsrdlParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<IsrdlParser::StatementBodyContext>();
}

IsrdlParser::StatementBodyContext* IsrdlParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<IsrdlParser::StatementBodyContext>(i);
}


size_t IsrdlParser::DefaultStatementContext::getRuleIndex() const {
  return IsrdlParser::RuleDefaultStatement;
}

void IsrdlParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void IsrdlParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

IsrdlParser::DefaultStatementContext* IsrdlParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 132, IsrdlParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(623);
    match(IsrdlParser::DefaultID);
    setState(624);
    match(IsrdlParser::COLON);
    setState(632);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IsrdlParser::LBRACE: {
        setState(625);
        nestedStatementBody();
        break;
      }

      case IsrdlParser::RBRACE:
      case IsrdlParser::NameID:
      case IsrdlParser::LabelID:
      case IsrdlParser::EnabledID:
      case IsrdlParser::TypeID:
      case IsrdlParser::IntID:
      case IsrdlParser::RealID:
      case IsrdlParser::BoolID:
      case IsrdlParser::StringID:
      case IsrdlParser::ThisID:
      case IsrdlParser::ReturnID:
      case IsrdlParser::EnumID:
      case IsrdlParser::AttributeID:
      case IsrdlParser::SignalID:
      case IsrdlParser::PortID:
      case IsrdlParser::ImportID:
      case IsrdlParser::FromID:
      case IsrdlParser::ToID:
      case IsrdlParser::SendID:
      case IsrdlParser::SwitchID:
      case IsrdlParser::IfID:
      case IsrdlParser::AsID:
      case IsrdlParser::BREAK:
      case IsrdlParser::ID: {
        setState(629);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 33) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 33)) & ((1ULL << (IsrdlParser::NameID - 33))
          | (1ULL << (IsrdlParser::LabelID - 33))
          | (1ULL << (IsrdlParser::EnabledID - 33))
          | (1ULL << (IsrdlParser::TypeID - 33))
          | (1ULL << (IsrdlParser::IntID - 33))
          | (1ULL << (IsrdlParser::RealID - 33))
          | (1ULL << (IsrdlParser::BoolID - 33))
          | (1ULL << (IsrdlParser::StringID - 33))
          | (1ULL << (IsrdlParser::ThisID - 33))
          | (1ULL << (IsrdlParser::ReturnID - 33))
          | (1ULL << (IsrdlParser::EnumID - 33))
          | (1ULL << (IsrdlParser::AttributeID - 33))
          | (1ULL << (IsrdlParser::SignalID - 33))
          | (1ULL << (IsrdlParser::PortID - 33))
          | (1ULL << (IsrdlParser::ImportID - 33))
          | (1ULL << (IsrdlParser::FromID - 33))
          | (1ULL << (IsrdlParser::ToID - 33))
          | (1ULL << (IsrdlParser::SendID - 33))
          | (1ULL << (IsrdlParser::SwitchID - 33))
          | (1ULL << (IsrdlParser::IfID - 33))
          | (1ULL << (IsrdlParser::AsID - 33))
          | (1ULL << (IsrdlParser::BREAK - 33))
          | (1ULL << (IsrdlParser::ID - 33)))) != 0)) {
          setState(626);
          statementBody();
          setState(631);
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

IsrdlParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IsrdlParser::SignalParamNameContext* IsrdlParser::AtomContext::signalParamName() {
  return getRuleContext<IsrdlParser::SignalParamNameContext>(0);
}

IsrdlParser::AttributeNameContext* IsrdlParser::AtomContext::attributeName() {
  return getRuleContext<IsrdlParser::AttributeNameContext>(0);
}

IsrdlParser::FunctionCallContext* IsrdlParser::AtomContext::functionCall() {
  return getRuleContext<IsrdlParser::FunctionCallContext>(0);
}

IsrdlParser::LiteralValueContext* IsrdlParser::AtomContext::literalValue() {
  return getRuleContext<IsrdlParser::LiteralValueContext>(0);
}


size_t IsrdlParser::AtomContext::getRuleIndex() const {
  return IsrdlParser::RuleAtom;
}

void IsrdlParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void IsrdlParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IsrdlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

IsrdlParser::AtomContext* IsrdlParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 134, IsrdlParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(638);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(634);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(635);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(636);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(637);
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
std::vector<dfa::DFA> IsrdlParser::_decisionToDFA;
atn::PredictionContextCache IsrdlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN IsrdlParser::_atn;
std::vector<uint16_t> IsrdlParser::_serializedATN;

std::vector<std::string> IsrdlParser::_ruleNames = {
  "secRequirement", "attackDescriptionDecl", "attackImpactDecl", "attackVectorDecl", 
  "attackVectorEnum", "attackPrivileges", "privilegesEnum", "confidentialityThreatDecl", 
  "confidentialityEnum", "integrityThreatDecl", "integrityEnum", "availabilityThreatDecl", 
  "nameDecl", "componentIdPath", "signalIdPath", "attributeIdPath", "signalSend", 
  "commonDecl", "importPathDecl", "importPathBody", "importFileBody", "importAs", 
  "typeDefDecl", "typeDecl", "intTypeDecl", "realTypeDecl", "enumTypeDecl", 
  "attributeDecl", "literalValue", "signalParamName", "attributeName", "toPortName", 
  "attributeAssignStatement", "localAssignStatement", "sendToStatement", 
  "singleAssignment", "multiAssignment", "signalDecl", "paramDecl", "functionDecl", 
  "functionParameters", "functionCall", "functionCallBody", "functionCallBodyOptional", 
  "contextID", "triggerDecl", "thisDecl", "portDecl", "idPath", "statementDecl", 
  "statementBody", "functionCallStatement", "nestedStatementBody", "returnStatement", 
  "breakStatement", "operation", "operationOptional", "expression", "expressionOptional", 
  "conditionalStatement", "ifStatement", "ifEuT", "elseStatement", "switchStatement", 
  "switchPuT", "caseStatement", "defaultStatement", "atom"
};

std::vector<std::string> IsrdlParser::_literalNames = {
  "", "'NoDamage'", "'Affected'", "'integrity'", "'Broken'", "'Intact'", 
  "'confidentiality'", "'Admin'", "'Install'", "'UnInstall'", "'Save'", 
  "'Edit'", "'None'", "'privileges'", "'ImpactThreat'", "'AttackDescription'", 
  "'SecurityRequirement'", "'source'", "'Physical'", "'Local'", "'Internet'", 
  "'timeout'", "'ms'", "'s'", "", "'{'", "'}'", "':'", "';'", "','", "'_'", 
  "'-'", "", "'name'", "'label'", "'enabled'", "'Type'", "'int'", "'real'", 
  "'bool'", "'string'", "'trigger'", "'msg'", "'this'", "'return'", "'SignalTransition'", 
  "'TimeoutTransition'", "'enum'", "'Declaration'", "'description'", "'Attribute'", 
  "'Signal'", "'Port'", "'import'", "'from'", "'to'", "'send'", "'Function'", 
  "'switch'", "'case'", "'default'", "'if'", "'else'", "'as'", "'@'", "'!'", 
  "'&&'", "'||'", "'not'", "'and'", "'or'", "'true'", "'false'", "'break'", 
  "'='", "'<->'", "'->'", "'<-'", "'..'", "", "", "", "", "", "'('", "')'", 
  "'['", "']'", "'<'", "'>'", "'.'", "'+'", "'*'", "'/'", "'|'", "'&'", 
  "'const'"
};

std::vector<std::string> IsrdlParser::_symbolicNames = {
  "", "NoDamageID", "AffectedID", "IntegrityThreatID", "BrokenID", "IntactID", 
  "ConfidentialityThreatID", "AdministratorID", "InstallAllowedID", "UnInstallAllowedID", 
  "SaveAllowedID", "EditAllowedID", "NoneID", "PrivilegesID", "ImpactID", 
  "AttackDescriptionID", "SecurityRequirementID", "SourceID", "PhysicalID", 
  "LocalID", "InternetID", "TimeoutID", "MSekID", "SekID", "INT", "LBRACE", 
  "RBRACE", "COLON", "SEMI", "COMMA", "UNDER", "MINUS", "IGNORE_NEWLINE", 
  "NameID", "LabelID", "EnabledID", "TypeID", "IntID", "RealID", "BoolID", 
  "StringID", "TriggerID", "MessageTrigger", "ThisID", "ReturnID", "SignalTransitionID", 
  "TimeoutTransitionID", "EnumID", "DeclarationID", "DescriptionID", "AttributeID", 
  "SignalID", "PortID", "ImportID", "FromID", "ToID", "SendID", "FunctionID", 
  "SwitchID", "CaseID", "DefaultID", "IfID", "ElseID", "AsID", "AtID", "NotIdSymbol", 
  "AndIdSymbol", "OrIdSymbol", "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", 
  "FalseID", "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", "LeftArrow", 
  "RANGE", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", "LPAREN", 
  "RPAREN", "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", "DOT", "PLUS", 
  "MULT", "DIV", "PIPE", "REF", "CONST", "NEWLINE", "WS"
};

dfa::Vocabulary IsrdlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> IsrdlParser::_tokenNames;

IsrdlParser::Initializer::Initializer() {
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
    0x3, 0x64, 0x283, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x90, 0xa, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x99, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x9d, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0xa5, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa9, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0xad, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0xc1, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xdf, 0xa, 0xf, 0xc, 0xf, 0xe, 
    0xf, 0xe2, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xe7, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xea, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xf0, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 
    0xf3, 0xb, 0x11, 0x5, 0x11, 0xf5, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
    0xff, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x102, 0xb, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x108, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x11b, 0xa, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x120, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x12d, 0xa, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 
    0x1a, 0x136, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x13f, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x146, 0xa, 0x1c, 
    0xc, 0x1c, 0xe, 0x1c, 0x149, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x152, 0xa, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x15c, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x163, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x174, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x17c, 0xa, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x182, 0xa, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x7, 0x26, 0x186, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x189, 
    0xb, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x193, 0xa, 0x27, 0xc, 0x27, 
    0xe, 0x27, 0x196, 0xb, 0x27, 0x3, 0x27, 0x5, 0x27, 0x199, 0xa, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x19d, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1aa, 0xa, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x1b2, 
    0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x1b5, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1c1, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x1c8, 0xa, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x1d6, 
    0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x1d9, 0xb, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x1e0, 0xa, 0x32, 0xc, 0x32, 
    0xe, 0x32, 0x1e3, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x1e7, 
    0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x1f1, 0xa, 0x34, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x1f8, 0xa, 0x36, 
    0xc, 0x36, 0xe, 0x36, 0x1fb, 0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x211, 0xa, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x216, 0xa, 0x3a, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x5, 0x3b, 0x226, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x234, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x239, 0xa, 0x3c, 0x5, 0x3c, 0x23b, 0xa, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x23f, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x5, 0x3d, 0x244, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x24a, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x7, 0x41, 0x257, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 
    0x25a, 0xb, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x25e, 0xa, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x26b, 
    0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x26e, 0xb, 0x43, 0x5, 0x43, 0x270, 
    0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x276, 
    0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x279, 0xb, 0x44, 0x5, 0x44, 0x27b, 
    0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x281, 
    0xa, 0x45, 0x3, 0x45, 0x2, 0x2, 0x46, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 
    0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
    0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
    0x86, 0x88, 0x2, 0xa, 0x3, 0x2, 0x14, 0x16, 0x3, 0x2, 0x9, 0xe, 0x3, 
    0x2, 0x6, 0x7, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x18, 0x19, 0x6, 0x2, 0x23, 
    0x26, 0x34, 0x39, 0x41, 0x41, 0x53, 0x53, 0x3, 0x2, 0x2b, 0x2c, 0x4, 
    0x2, 0x21, 0x21, 0x5d, 0x5f, 0x2, 0x296, 0x2, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x94, 0x3, 0x2, 0x2, 0x2, 0x6, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x8, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xc, 0xb7, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x10, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xce, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x22, 0xf6, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x100, 0x3, 0x2, 0x2, 0x2, 0x26, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x109, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x32, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x36, 0x140, 0x3, 0x2, 0x2, 0x2, 0x38, 0x14c, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x15d, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x162, 0x3, 0x2, 0x2, 0x2, 0x40, 0x166, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x169, 0x3, 0x2, 0x2, 0x2, 0x44, 0x16e, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x177, 0x3, 0x2, 0x2, 0x2, 0x48, 0x181, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x183, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x1a0, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1ae, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1c0, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1c9, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1ce, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1dc, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1fe, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x202, 0x3, 0x2, 0x2, 0x2, 0x70, 0x210, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x215, 0x3, 0x2, 0x2, 0x2, 0x74, 0x225, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x78, 0x240, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x245, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x24b, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x80, 0x252, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x261, 0x3, 0x2, 0x2, 0x2, 0x84, 0x265, 0x3, 0x2, 0x2, 0x2, 0x86, 0x271, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x280, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 
    0x12, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x1b, 0x2, 0x2, 0x8c, 0x8f, 0x5, 0x1a, 
    0xe, 0x2, 0x8d, 0x90, 0x5, 0x4, 0x3, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8e, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x6, 0x4, 0x2, 0x92, 
    0x93, 0x7, 0x1c, 0x2, 0x2, 0x93, 0x3, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 
    0x7, 0x11, 0x2, 0x2, 0x95, 0x98, 0x7, 0x1b, 0x2, 0x2, 0x96, 0x99, 0x5, 
    0x8, 0x5, 0x2, 0x97, 0x99, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x9d, 0x5, 0xc, 0x7, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x1c, 0x2, 0x2, 0x9f, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x10, 0x2, 0x2, 0xa1, 0xa4, 0x7, 
    0x1b, 0x2, 0x2, 0xa2, 0xa5, 0x5, 0x10, 0x9, 0x2, 0xa3, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa9, 0x5, 0x14, 0xb, 0x2, 
    0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 
    0x5, 0x18, 0xd, 0x2, 0xab, 0xad, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x7, 0x1c, 0x2, 0x2, 0xaf, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xb1, 0x7, 0x13, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x1d, 0x2, 0x2, 
    0xb2, 0xb3, 0x5, 0xa, 0x6, 0x2, 0xb3, 0xb4, 0x7, 0x1e, 0x2, 0x2, 0xb4, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x9, 0x2, 0x2, 0x2, 0xb6, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0xf, 0x2, 0x2, 0xb8, 0xb9, 0x7, 
    0x1d, 0x2, 0x2, 0xb9, 0xba, 0x5, 0xe, 0x8, 0x2, 0xba, 0xbb, 0x7, 0x1e, 
    0x2, 0x2, 0xbb, 0xd, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xc0, 0x9, 0x3, 0x2, 
    0x2, 0xbd, 0xbe, 0x7, 0x1f, 0x2, 0x2, 0xbe, 0xc1, 0x5, 0xe, 0x8, 0x2, 
    0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 
    0x7, 0x8, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x1d, 0x2, 0x2, 0xc4, 0xc5, 0x5, 
    0x12, 0xa, 0x2, 0xc5, 0xc6, 0x7, 0x1e, 0x2, 0x2, 0xc6, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0xc8, 0x9, 0x4, 0x2, 0x2, 0xc8, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xca, 0x7, 0x5, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x1d, 0x2, 0x2, 
    0xcb, 0xcc, 0x5, 0x16, 0xc, 0x2, 0xcc, 0xcd, 0x7, 0x1e, 0x2, 0x2, 0xcd, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x9, 0x5, 0x2, 0x2, 0xcf, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x17, 0x2, 0x2, 0xd1, 0xd2, 0x7, 
    0x1d, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x1a, 0x2, 0x2, 0xd3, 0xd4, 0x9, 0x6, 
    0x2, 0x2, 0xd4, 0xd5, 0x7, 0x1e, 0x2, 0x2, 0xd5, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd7, 0x7, 0x23, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x1d, 0x2, 0x2, 
    0xd8, 0xd9, 0x7, 0x53, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x1e, 0x2, 0x2, 0xda, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xe0, 0x5, 0x5a, 0x2e, 0x2, 0xdc, 0xdd, 
    0x7, 0x5c, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x5a, 0x2e, 0x2, 0xde, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe8, 0x5, 0x5a, 0x2e, 0x2, 
    0xe4, 0xe5, 0x7, 0x5c, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x5a, 0x2e, 0x2, 0xe6, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xf5, 0x5, 0x3e, 
    0x20, 0x2, 0xec, 0xf1, 0x5, 0x5a, 0x2e, 0x2, 0xed, 0xee, 0x7, 0x5c, 
    0x2, 0x2, 0xee, 0xf0, 0x5, 0x5a, 0x2e, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 
    0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xf5, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x5, 
    0x1e, 0x10, 0x2, 0xf7, 0xf8, 0x7, 0x56, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x56, 
    0x2c, 0x2, 0xf9, 0xfa, 0x7, 0x57, 0x2, 0x2, 0xfa, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xfb, 0xff, 0x5, 0x2e, 0x18, 0x2, 0xfc, 0xff, 0x5, 0x38, 0x1d, 
    0x2, 0xfd, 0xff, 0x5, 0x4c, 0x27, 0x2, 0xfe, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0x102, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0x25, 0x3, 0x2, 0x2, 0x2, 0x102, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x104, 0x5, 0x28, 0x15, 0x2, 0x104, 0x105, 0x5, 
    0x26, 0x14, 0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 0x2, 0x106, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x103, 0x3, 0x2, 0x2, 0x2, 0x107, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x27, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x37, 
    0x2, 0x2, 0x10a, 0x10b, 0x7, 0x5a, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x2a, 
    0x16, 0x2, 0x10c, 0x10d, 0x7, 0x5b, 0x2, 0x2, 0x10d, 0x10e, 0x5, 0x2c, 
    0x17, 0x2, 0x10e, 0x29, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x5, 0x5a, 
    0x2e, 0x2, 0x110, 0x111, 0x7, 0x5c, 0x2, 0x2, 0x111, 0x112, 0x5, 0x5a, 
    0x2e, 0x2, 0x112, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x7, 0x50, 
    0x2, 0x2, 0x114, 0x115, 0x7, 0x5f, 0x2, 0x2, 0x115, 0x11b, 0x5, 0x2a, 
    0x16, 0x2, 0x116, 0x117, 0x5, 0x5a, 0x2e, 0x2, 0x117, 0x118, 0x7, 0x5f, 
    0x2, 0x2, 0x118, 0x119, 0x5, 0x2a, 0x16, 0x2, 0x119, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x116, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11d, 0x7, 0x41, 0x2, 0x2, 0x11d, 0x120, 0x5, 0x5a, 0x2e, 
    0x2, 0x11e, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x122, 0x7, 0x26, 0x2, 0x2, 0x122, 0x123, 0x5, 0x30, 0x19, 0x2, 
    0x123, 0x124, 0x5, 0x5a, 0x2e, 0x2, 0x124, 0x125, 0x7, 0x1e, 0x2, 0x2, 
    0x125, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x126, 0x12d, 0x5, 0x32, 0x1a, 0x2, 
    0x127, 0x12d, 0x5, 0x34, 0x1b, 0x2, 0x128, 0x12d, 0x5, 0x36, 0x1c, 0x2, 
    0x129, 0x12d, 0x7, 0x29, 0x2, 0x2, 0x12a, 0x12d, 0x7, 0x2a, 0x2, 0x2, 
    0x12b, 0x12d, 0x5, 0x5a, 0x2e, 0x2, 0x12c, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x128, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x31, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x135, 0x7, 0x27, 0x2, 0x2, 0x12f, 0x130, 0x7, 0x56, 0x2, 0x2, 0x130, 
    0x131, 0x7, 0x1a, 0x2, 0x2, 0x131, 0x132, 0x7, 0x50, 0x2, 0x2, 0x132, 
    0x133, 0x7, 0x1a, 0x2, 0x2, 0x133, 0x136, 0x7, 0x57, 0x2, 0x2, 0x134, 
    0x136, 0x3, 0x2, 0x2, 0x2, 0x135, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x135, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 0x33, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13e, 
    0x7, 0x28, 0x2, 0x2, 0x138, 0x139, 0x7, 0x56, 0x2, 0x2, 0x139, 0x13a, 
    0x7, 0x51, 0x2, 0x2, 0x13a, 0x13b, 0x7, 0x50, 0x2, 0x2, 0x13b, 0x13c, 
    0x7, 0x51, 0x2, 0x2, 0x13c, 0x13f, 0x7, 0x57, 0x2, 0x2, 0x13d, 0x13f, 
    0x3, 0x2, 0x2, 0x2, 0x13e, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13d, 
    0x3, 0x2, 0x2, 0x2, 0x13f, 0x35, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x7, 
    0x31, 0x2, 0x2, 0x141, 0x142, 0x7, 0x56, 0x2, 0x2, 0x142, 0x147, 0x5, 
    0x5a, 0x2e, 0x2, 0x143, 0x144, 0x7, 0x1f, 0x2, 0x2, 0x144, 0x146, 0x5, 
    0x5a, 0x2e, 0x2, 0x145, 0x143, 0x3, 0x2, 0x2, 0x2, 0x146, 0x149, 0x3, 
    0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x3, 
    0x2, 0x2, 0x2, 0x148, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 0x3, 
    0x2, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x57, 0x2, 0x2, 0x14b, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x34, 0x2, 0x2, 0x14d, 0x14e, 0x5, 
    0x30, 0x19, 0x2, 0x14e, 0x151, 0x5, 0x5a, 0x2e, 0x2, 0x14f, 0x150, 0x7, 
    0x4c, 0x2, 0x2, 0x150, 0x152, 0x5, 0x3a, 0x1e, 0x2, 0x151, 0x14f, 0x3, 
    0x2, 0x2, 0x2, 0x151, 0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 
    0x2, 0x2, 0x2, 0x153, 0x154, 0x7, 0x1e, 0x2, 0x2, 0x154, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x15c, 0x7, 0x1a, 0x2, 0x2, 0x156, 0x15c, 0x7, 
    0x51, 0x2, 0x2, 0x157, 0x15c, 0x7, 0x52, 0x2, 0x2, 0x158, 0x15c, 0x7, 
    0x49, 0x2, 0x2, 0x159, 0x15c, 0x7, 0x4a, 0x2, 0x2, 0x15a, 0x15c, 0x5, 
    0x5a, 0x2e, 0x2, 0x15b, 0x155, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x156, 0x3, 
    0x2, 0x2, 0x2, 0x15b, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x158, 0x3, 
    0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15a, 0x3, 
    0x2, 0x2, 0x2, 0x15c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x5c, 
    0x2f, 0x2, 0x15e, 0x15f, 0x5, 0x5a, 0x2e, 0x2, 0x15f, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x163, 0x5, 0x5e, 0x30, 0x2, 0x161, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x5, 0x5a, 
    0x2e, 0x2, 0x165, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x7, 0x39, 
    0x2, 0x2, 0x167, 0x168, 0x5, 0x5a, 0x2e, 0x2, 0x168, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x169, 0x16a, 0x5, 0x3e, 0x20, 0x2, 0x16a, 0x16b, 0x7, 0x4c, 
    0x2, 0x2, 0x16b, 0x16c, 0x5, 0x74, 0x3b, 0x2, 0x16c, 0x16d, 0x7, 0x1e, 
    0x2, 0x2, 0x16d, 0x43, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x5, 0x30, 
    0x19, 0x2, 0x16f, 0x173, 0x5, 0x5a, 0x2e, 0x2, 0x170, 0x171, 0x7, 0x4c, 
    0x2, 0x2, 0x171, 0x174, 0x5, 0x74, 0x3b, 0x2, 0x172, 0x174, 0x3, 0x2, 
    0x2, 0x2, 0x173, 0x170, 0x3, 0x2, 0x2, 0x2, 0x173, 0x172, 0x3, 0x2, 
    0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x7, 0x1e, 
    0x2, 0x2, 0x176, 0x45, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x7, 0x3a, 
    0x2, 0x2, 0x178, 0x17b, 0x5, 0x22, 0x12, 0x2, 0x179, 0x17c, 0x5, 0x40, 
    0x21, 0x2, 0x17a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x17e, 0x7, 0x1e, 0x2, 0x2, 0x17e, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x17f, 0x182, 0x5, 0x42, 0x22, 0x2, 0x180, 0x182, 0x5, 0x46, 
    0x24, 0x2, 0x181, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x181, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x49, 0x3, 0x2, 0x2, 0x2, 0x183, 0x187, 0x7, 0x1b, 
    0x2, 0x2, 0x184, 0x186, 0x5, 0x48, 0x25, 0x2, 0x185, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x186, 0x189, 0x3, 0x2, 0x2, 0x2, 0x187, 0x185, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x1c, 
    0x2, 0x2, 0x18b, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x35, 
    0x2, 0x2, 0x18d, 0x19c, 0x5, 0x5a, 0x2e, 0x2, 0x18e, 0x198, 0x7, 0x56, 
    0x2, 0x2, 0x18f, 0x194, 0x5, 0x4e, 0x28, 0x2, 0x190, 0x191, 0x7, 0x1f, 
    0x2, 0x2, 0x191, 0x193, 0x5, 0x4e, 0x28, 0x2, 0x192, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x193, 0x196, 0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x199, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x199, 0x3, 0x2, 
    0x2, 0x2, 0x198, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x198, 0x197, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19d, 0x7, 0x57, 
    0x2, 0x2, 0x19b, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x18e, 0x3, 0x2, 
    0x2, 0x2, 0x19c, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x19f, 0x7, 0x1e, 0x2, 0x2, 0x19f, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x1a0, 0x1a1, 0x5, 0x30, 0x19, 0x2, 0x1a1, 0x1a2, 0x5, 0x5a, 
    0x2e, 0x2, 0x1a2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x3b, 
    0x2, 0x2, 0x1a4, 0x1a5, 0x5, 0x30, 0x19, 0x2, 0x1a5, 0x1a6, 0x5, 0x62, 
    0x32, 0x2, 0x1a6, 0x1a9, 0x7, 0x56, 0x2, 0x2, 0x1a7, 0x1aa, 0x5, 0x52, 
    0x2a, 0x2, 0x1a8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 
    0x2, 0x2, 0x1a9, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 
    0x2, 0x2, 0x1ab, 0x1ac, 0x7, 0x57, 0x2, 0x2, 0x1ac, 0x1ad, 0x5, 0x6a, 
    0x36, 0x2, 0x1ad, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b3, 0x5, 0x4e, 
    0x28, 0x2, 0x1af, 0x1b0, 0x7, 0x1f, 0x2, 0x2, 0x1b0, 0x1b2, 0x5, 0x4e, 
    0x28, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b5, 0x3, 0x2, 
    0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x3, 0x2, 
    0x2, 0x2, 0x1b4, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1b7, 0x5, 0x62, 0x32, 0x2, 0x1b7, 0x1b8, 0x7, 0x56, 0x2, 
    0x2, 0x1b8, 0x1b9, 0x5, 0x56, 0x2c, 0x2, 0x1b9, 0x1ba, 0x7, 0x57, 0x2, 
    0x2, 0x1ba, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1c1, 0x5, 0x3a, 0x1e, 
    0x2, 0x1bc, 0x1c1, 0x5, 0x3c, 0x1f, 0x2, 0x1bd, 0x1c1, 0x5, 0x3e, 0x20, 
    0x2, 0x1be, 0x1c1, 0x5, 0x54, 0x2b, 0x2, 0x1bf, 0x1c1, 0x3, 0x2, 0x2, 
    0x2, 0x1c0, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1c0, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 
    0x2, 0x1c0, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 
    0x2, 0x1c2, 0x1c3, 0x5, 0x58, 0x2d, 0x2, 0x1c3, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x1c4, 0x1c5, 0x7, 0x1f, 0x2, 0x2, 0x1c5, 0x1c8, 0x5, 0x56, 0x2c, 
    0x2, 0x1c6, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c4, 0x3, 0x2, 0x2, 
    0x2, 0x1c7, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x1c9, 0x1ca, 0x9, 0x7, 0x2, 0x2, 0x1ca, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
    0x1cc, 0x9, 0x8, 0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0x5c, 0x2, 0x2, 0x1cd, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x7, 0x2d, 0x2, 0x2, 0x1cf, 
    0x1d0, 0x7, 0x5c, 0x2, 0x2, 0x1d0, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
    0x1d2, 0x7, 0x36, 0x2, 0x2, 0x1d2, 0x1d7, 0x5, 0x5a, 0x2e, 0x2, 0x1d3, 
    0x1d4, 0x7, 0x1f, 0x2, 0x2, 0x1d4, 0x1d6, 0x5, 0x5a, 0x2e, 0x2, 0x1d5, 
    0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
    0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 
    0x1da, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1da, 
    0x1db, 0x7, 0x1e, 0x2, 0x2, 0x1db, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
    0x1e1, 0x5, 0x5a, 0x2e, 0x2, 0x1dd, 0x1de, 0x7, 0x5c, 0x2, 0x2, 0x1de, 
    0x1e0, 0x5, 0x5a, 0x2e, 0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
    0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e1, 
    0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e7, 0x5, 0x66, 0x34, 0x2, 0x1e5, 0x1e7, 
    0x5, 0x6a, 0x36, 0x2, 0x1e6, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e5, 
    0x3, 0x2, 0x2, 0x2, 0x1e7, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1f1, 0x5, 
    0x68, 0x35, 0x2, 0x1e9, 0x1f1, 0x5, 0x42, 0x22, 0x2, 0x1ea, 0x1f1, 0x5, 
    0x80, 0x41, 0x2, 0x1eb, 0x1f1, 0x5, 0x78, 0x3d, 0x2, 0x1ec, 0x1f1, 0x5, 
    0x44, 0x23, 0x2, 0x1ed, 0x1f1, 0x5, 0x46, 0x24, 0x2, 0x1ee, 0x1f1, 0x5, 
    0x6e, 0x38, 0x2, 0x1ef, 0x1f1, 0x5, 0x6c, 0x37, 0x2, 0x1f0, 0x1e8, 0x3, 
    0x2, 0x2, 0x2, 0x1f0, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ea, 0x3, 
    0x2, 0x2, 0x2, 0x1f0, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ec, 0x3, 
    0x2, 0x2, 0x2, 0x1f0, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ee, 0x3, 
    0x2, 0x2, 0x2, 0x1f0, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x1f2, 0x1f3, 0x5, 0x54, 0x2b, 0x2, 0x1f3, 0x1f4, 0x7, 0x1e, 
    0x2, 0x2, 0x1f4, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f9, 0x7, 0x1b, 
    0x2, 0x2, 0x1f6, 0x1f8, 0x5, 0x66, 0x34, 0x2, 0x1f7, 0x1f6, 0x3, 0x2, 
    0x2, 0x2, 0x1f8, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f7, 0x3, 0x2, 
    0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fc, 0x3, 0x2, 
    0x2, 0x2, 0x1fb, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x7, 0x1c, 
    0x2, 0x2, 0x1fd, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x7, 0x2e, 
    0x2, 0x2, 0x1ff, 0x200, 0x5, 0x70, 0x39, 0x2, 0x200, 0x201, 0x7, 0x1e, 
    0x2, 0x2, 0x201, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x7, 0x4b, 
    0x2, 0x2, 0x203, 0x204, 0x7, 0x1e, 0x2, 0x2, 0x204, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x205, 0x206, 0x5, 0x88, 0x45, 0x2, 0x206, 0x207, 0x5, 0x72, 
    0x3a, 0x2, 0x207, 0x211, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 0x7, 0x56, 
    0x2, 0x2, 0x209, 0x20a, 0x5, 0x70, 0x39, 0x2, 0x20a, 0x20b, 0x7, 0x57, 
    0x2, 0x2, 0x20b, 0x211, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x7, 0x21, 
    0x2, 0x2, 0x20d, 0x211, 0x5, 0x70, 0x39, 0x2, 0x20e, 0x20f, 0x7, 0x43, 
    0x2, 0x2, 0x20f, 0x211, 0x5, 0x70, 0x39, 0x2, 0x210, 0x205, 0x3, 0x2, 
    0x2, 0x2, 0x210, 0x208, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20c, 0x3, 0x2, 
    0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x211, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x212, 0x213, 0x9, 0x9, 0x2, 0x2, 0x213, 0x216, 0x5, 0x70, 0x39, 
    0x2, 0x214, 0x216, 0x3, 0x2, 0x2, 0x2, 0x215, 0x212, 0x3, 0x2, 0x2, 
    0x2, 0x215, 0x214, 0x3, 0x2, 0x2, 0x2, 0x216, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x218, 0x7, 0x56, 0x2, 0x2, 0x218, 0x219, 0x5, 0x74, 0x3b, 0x2, 
    0x219, 0x21a, 0x7, 0x57, 0x2, 0x2, 0x21a, 0x21b, 0x5, 0x76, 0x3c, 0x2, 
    0x21b, 0x226, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 0x7, 0x43, 0x2, 0x2, 
    0x21d, 0x226, 0x5, 0x74, 0x3b, 0x2, 0x21e, 0x21f, 0x7, 0x46, 0x2, 0x2, 
    0x21f, 0x226, 0x5, 0x74, 0x3b, 0x2, 0x220, 0x221, 0x7, 0x21, 0x2, 0x2, 
    0x221, 0x226, 0x5, 0x74, 0x3b, 0x2, 0x222, 0x223, 0x5, 0x70, 0x39, 0x2, 
    0x223, 0x224, 0x5, 0x76, 0x3c, 0x2, 0x224, 0x226, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x217, 0x3, 0x2, 0x2, 0x2, 0x225, 0x21c, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x225, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x222, 0x3, 0x2, 0x2, 0x2, 0x226, 0x75, 0x3, 0x2, 0x2, 0x2, 0x227, 
    0x23b, 0x7, 0x45, 0x2, 0x2, 0x228, 0x23b, 0x7, 0x48, 0x2, 0x2, 0x229, 
    0x23b, 0x7, 0x44, 0x2, 0x2, 0x22a, 0x23b, 0x7, 0x47, 0x2, 0x2, 0x22b, 
    0x22c, 0x7, 0x4c, 0x2, 0x2, 0x22c, 0x23b, 0x7, 0x4c, 0x2, 0x2, 0x22d, 
    0x22e, 0x7, 0x43, 0x2, 0x2, 0x22e, 0x23b, 0x7, 0x4c, 0x2, 0x2, 0x22f, 
    0x23b, 0x7, 0x46, 0x2, 0x2, 0x230, 0x233, 0x7, 0x5a, 0x2, 0x2, 0x231, 
    0x234, 0x7, 0x4c, 0x2, 0x2, 0x232, 0x234, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x232, 0x3, 0x2, 0x2, 0x2, 0x234, 
    0x23b, 0x3, 0x2, 0x2, 0x2, 0x235, 0x238, 0x7, 0x5b, 0x2, 0x2, 0x236, 
    0x239, 0x7, 0x4c, 0x2, 0x2, 0x237, 0x239, 0x3, 0x2, 0x2, 0x2, 0x238, 
    0x236, 0x3, 0x2, 0x2, 0x2, 0x238, 0x237, 0x3, 0x2, 0x2, 0x2, 0x239, 
    0x23b, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x227, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x228, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x229, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x22a, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x22d, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x230, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x235, 0x3, 0x2, 0x2, 0x2, 0x23b, 
    0x23c, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23f, 0x5, 0x74, 0x3b, 0x2, 0x23d, 
    0x23f, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23e, 
    0x23d, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x77, 0x3, 0x2, 0x2, 0x2, 0x240, 0x243, 
    0x5, 0x7a, 0x3e, 0x2, 0x241, 0x244, 0x5, 0x7e, 0x40, 0x2, 0x242, 0x244, 
    0x3, 0x2, 0x2, 0x2, 0x243, 0x241, 0x3, 0x2, 0x2, 0x2, 0x243, 0x242, 
    0x3, 0x2, 0x2, 0x2, 0x244, 0x79, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0x7, 
    0x3f, 0x2, 0x2, 0x246, 0x249, 0x5, 0x7c, 0x3f, 0x2, 0x247, 0x24a, 0x5, 
    0x64, 0x33, 0x2, 0x248, 0x24a, 0x7, 0x1e, 0x2, 0x2, 0x249, 0x247, 0x3, 
    0x2, 0x2, 0x2, 0x249, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x24b, 0x24c, 0x7, 0x56, 0x2, 0x2, 0x24c, 0x24d, 0x5, 0x74, 
    0x3b, 0x2, 0x24d, 0x24e, 0x7, 0x57, 0x2, 0x2, 0x24e, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x24f, 0x250, 0x7, 0x40, 0x2, 0x2, 0x250, 0x251, 0x5, 0x64, 
    0x33, 0x2, 0x251, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x252, 0x253, 0x7, 0x3c, 
    0x2, 0x2, 0x253, 0x254, 0x5, 0x82, 0x42, 0x2, 0x254, 0x258, 0x7, 0x1b, 
    0x2, 0x2, 0x255, 0x257, 0x5, 0x84, 0x43, 0x2, 0x256, 0x255, 0x3, 0x2, 
    0x2, 0x2, 0x257, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x258, 0x256, 0x3, 0x2, 
    0x2, 0x2, 0x258, 0x259, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25d, 0x3, 0x2, 
    0x2, 0x2, 0x25a, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25e, 0x5, 0x86, 
    0x44, 0x2, 0x25c, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25b, 0x3, 0x2, 
    0x2, 0x2, 0x25d, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x3, 0x2, 
    0x2, 0x2, 0x25f, 0x260, 0x7, 0x1c, 0x2, 0x2, 0x260, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x261, 0x262, 0x7, 0x56, 0x2, 0x2, 0x262, 0x263, 0x5, 0x5a, 
    0x2e, 0x2, 0x263, 0x264, 0x7, 0x57, 0x2, 0x2, 0x264, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x265, 0x266, 0x7, 0x3d, 0x2, 0x2, 0x266, 0x267, 0x5, 0x3a, 
    0x1e, 0x2, 0x267, 0x26f, 0x7, 0x1d, 0x2, 0x2, 0x268, 0x270, 0x5, 0x6a, 
    0x36, 0x2, 0x269, 0x26b, 0x5, 0x66, 0x34, 0x2, 0x26a, 0x269, 0x3, 0x2, 
    0x2, 0x2, 0x26b, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26a, 0x3, 0x2, 
    0x2, 0x2, 0x26c, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x270, 0x3, 0x2, 
    0x2, 0x2, 0x26e, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x268, 0x3, 0x2, 
    0x2, 0x2, 0x26f, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x270, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x271, 0x272, 0x7, 0x3e, 0x2, 0x2, 0x272, 0x27a, 0x7, 0x1d, 0x2, 
    0x2, 0x273, 0x27b, 0x5, 0x6a, 0x36, 0x2, 0x274, 0x276, 0x5, 0x66, 0x34, 
    0x2, 0x275, 0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x279, 0x3, 0x2, 0x2, 
    0x2, 0x277, 0x275, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 
    0x2, 0x278, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x279, 0x277, 0x3, 0x2, 0x2, 
    0x2, 0x27a, 0x273, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x277, 0x3, 0x2, 0x2, 
    0x2, 0x27b, 0x87, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x281, 0x5, 0x3c, 0x1f, 
    0x2, 0x27d, 0x281, 0x5, 0x3e, 0x20, 0x2, 0x27e, 0x281, 0x5, 0x54, 0x2b, 
    0x2, 0x27f, 0x281, 0x5, 0x3a, 0x1e, 0x2, 0x280, 0x27c, 0x3, 0x2, 0x2, 
    0x2, 0x280, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x280, 0x27e, 0x3, 0x2, 0x2, 
    0x2, 0x280, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x281, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x8f, 0x98, 0x9c, 0xa4, 0xa8, 0xac, 0xc0, 0xe0, 0xe8, 0xf1, 0xf4, 
    0xfe, 0x100, 0x107, 0x11a, 0x11f, 0x12c, 0x135, 0x13e, 0x147, 0x151, 
    0x15b, 0x162, 0x173, 0x17b, 0x181, 0x187, 0x194, 0x198, 0x19c, 0x1a9, 
    0x1b3, 0x1c0, 0x1c7, 0x1d7, 0x1e1, 0x1e6, 0x1f0, 0x1f9, 0x210, 0x215, 
    0x225, 0x233, 0x238, 0x23a, 0x23e, 0x243, 0x249, 0x258, 0x25d, 0x26c, 
    0x26f, 0x277, 0x27a, 0x280, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

IsrdlParser::Initializer IsrdlParser::_init;
