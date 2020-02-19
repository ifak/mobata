
// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/TrafficSimDecl.g4 by ANTLR 4.7.2


#include "TrafficSimDeclListener.h"

#include "TrafficSimDeclParser.h"


using namespace antlrcpp;
using namespace antlr4;

TrafficSimDeclParser::TrafficSimDeclParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TrafficSimDeclParser::~TrafficSimDeclParser() {
  delete _interpreter;
}

std::string TrafficSimDeclParser::getGrammarFileName() const {
  return "TrafficSimDecl.g4";
}

const std::vector<std::string>& TrafficSimDeclParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TrafficSimDeclParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

TrafficSimDeclParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::StartContext::Start() {
  return getToken(TrafficSimDeclParser::Start, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StartContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StartContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StartContext::INT() {
  return getToken(TrafficSimDeclParser::INT, 0);
}


size_t TrafficSimDeclParser::StartContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStart;
}

void TrafficSimDeclParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void TrafficSimDeclParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

TrafficSimDeclParser::StartContext* TrafficSimDeclParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, TrafficSimDeclParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(TrafficSimDeclParser::Start);
    setState(189);
    match(TrafficSimDeclParser::COLON);
    setState(190);
    dynamic_cast<StartContext *>(_localctx)->startNumber = match(TrafficSimDeclParser::INT);
    setState(191);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartArmContext ------------------------------------------------------------------

TrafficSimDeclParser::StartArmContext::StartArmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::StartArmContext::StartArm() {
  return getToken(TrafficSimDeclParser::StartArm, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StartArmContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StartArmContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StartArmContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}


size_t TrafficSimDeclParser::StartArmContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStartArm;
}

void TrafficSimDeclParser::StartArmContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartArm(this);
}

void TrafficSimDeclParser::StartArmContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartArm(this);
}

TrafficSimDeclParser::StartArmContext* TrafficSimDeclParser::startArm() {
  StartArmContext *_localctx = _tracker.createInstance<StartArmContext>(_ctx, getState());
  enterRule(_localctx, 2, TrafficSimDeclParser::RuleStartArm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(TrafficSimDeclParser::StartArm);
    setState(194);
    match(TrafficSimDeclParser::COLON);
    setState(195);
    dynamic_cast<StartArmContext *>(_localctx)->n = match(TrafficSimDeclParser::STRING);
    setState(196);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndContext ------------------------------------------------------------------

TrafficSimDeclParser::EndContext::EndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::EndContext::End() {
  return getToken(TrafficSimDeclParser::End, 0);
}

tree::TerminalNode* TrafficSimDeclParser::EndContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::EndContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::EndContext::INT() {
  return getToken(TrafficSimDeclParser::INT, 0);
}


size_t TrafficSimDeclParser::EndContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleEnd;
}

void TrafficSimDeclParser::EndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnd(this);
}

void TrafficSimDeclParser::EndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnd(this);
}

TrafficSimDeclParser::EndContext* TrafficSimDeclParser::end() {
  EndContext *_localctx = _tracker.createInstance<EndContext>(_ctx, getState());
  enterRule(_localctx, 4, TrafficSimDeclParser::RuleEnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(TrafficSimDeclParser::End);
    setState(199);
    match(TrafficSimDeclParser::COLON);
    setState(200);
    dynamic_cast<EndContext *>(_localctx)->endNumber = match(TrafficSimDeclParser::INT);
    setState(201);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepContext ------------------------------------------------------------------

TrafficSimDeclParser::StepContext::StepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::StepContext::Step() {
  return getToken(TrafficSimDeclParser::Step, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StepContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::StepBodyContext* TrafficSimDeclParser::StepContext::stepBody() {
  return getRuleContext<TrafficSimDeclParser::StepBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::StepContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::StepContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStep;
}

void TrafficSimDeclParser::StepContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStep(this);
}

void TrafficSimDeclParser::StepContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStep(this);
}

TrafficSimDeclParser::StepContext* TrafficSimDeclParser::step() {
  StepContext *_localctx = _tracker.createInstance<StepContext>(_ctx, getState());
  enterRule(_localctx, 6, TrafficSimDeclParser::RuleStep);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(TrafficSimDeclParser::Step);
    setState(204);
    match(TrafficSimDeclParser::LBRACE);
    setState(205);
    stepBody();
    setState(206);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::StepBodyContext::StepBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::StartContext* TrafficSimDeclParser::StepBodyContext::start() {
  return getRuleContext<TrafficSimDeclParser::StartContext>(0);
}

TrafficSimDeclParser::StepBodyContext* TrafficSimDeclParser::StepBodyContext::stepBody() {
  return getRuleContext<TrafficSimDeclParser::StepBodyContext>(0);
}

TrafficSimDeclParser::VehicleMovementContext* TrafficSimDeclParser::StepBodyContext::vehicleMovement() {
  return getRuleContext<TrafficSimDeclParser::VehicleMovementContext>(0);
}

TrafficSimDeclParser::EndContext* TrafficSimDeclParser::StepBodyContext::end() {
  return getRuleContext<TrafficSimDeclParser::EndContext>(0);
}


size_t TrafficSimDeclParser::StepBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStepBody;
}

void TrafficSimDeclParser::StepBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepBody(this);
}

void TrafficSimDeclParser::StepBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepBody(this);
}

TrafficSimDeclParser::StepBodyContext* TrafficSimDeclParser::stepBody() {
  StepBodyContext *_localctx = _tracker.createInstance<StepBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, TrafficSimDeclParser::RuleStepBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Start: {
        setState(208);
        start();
        setState(209);
        stepBody();
        break;
      }

      case TrafficSimDeclParser::VehicleMovement: {
        setState(211);
        vehicleMovement();
        setState(212);
        stepBody();
        break;
      }

      case TrafficSimDeclParser::End: {
        setState(214);
        end();
        setState(215);
        stepBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- IntersectionContext ------------------------------------------------------------------

TrafficSimDeclParser::IntersectionContext::IntersectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionContext::Intersection() {
  return getToken(TrafficSimDeclParser::Intersection, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::IntersectionBodyContext* TrafficSimDeclParser::IntersectionContext::intersectionBody() {
  return getRuleContext<TrafficSimDeclParser::IntersectionBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::IntersectionContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleIntersection;
}

void TrafficSimDeclParser::IntersectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntersection(this);
}

void TrafficSimDeclParser::IntersectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntersection(this);
}

TrafficSimDeclParser::IntersectionContext* TrafficSimDeclParser::intersection() {
  IntersectionContext *_localctx = _tracker.createInstance<IntersectionContext>(_ctx, getState());
  enterRule(_localctx, 10, TrafficSimDeclParser::RuleIntersection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(TrafficSimDeclParser::Intersection);
    setState(221);
    match(TrafficSimDeclParser::LBRACE);
    setState(222);
    intersectionBody();
    setState(223);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntersectionBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::IntersectionBodyContext::IntersectionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::EdgeContext* TrafficSimDeclParser::IntersectionBodyContext::edge() {
  return getRuleContext<TrafficSimDeclParser::EdgeContext>(0);
}

TrafficSimDeclParser::IntersectionBodyContext* TrafficSimDeclParser::IntersectionBodyContext::intersectionBody() {
  return getRuleContext<TrafficSimDeclParser::IntersectionBodyContext>(0);
}

TrafficSimDeclParser::SensorContext* TrafficSimDeclParser::IntersectionBodyContext::sensor() {
  return getRuleContext<TrafficSimDeclParser::SensorContext>(0);
}

TrafficSimDeclParser::ObjectContext* TrafficSimDeclParser::IntersectionBodyContext::object() {
  return getRuleContext<TrafficSimDeclParser::ObjectContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::Label() {
  return getToken(TrafficSimDeclParser::Label, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::HasTrafficLight() {
  return getToken(TrafficSimDeclParser::HasTrafficLight, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::Accident() {
  return getToken(TrafficSimDeclParser::Accident, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::NeighboringTrafficLights() {
  return getToken(TrafficSimDeclParser::NeighboringTrafficLights, 0);
}

TrafficSimDeclParser::TrafficLightsContext* TrafficSimDeclParser::IntersectionBodyContext::trafficLights() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightsContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::ID() {
  return getToken(TrafficSimDeclParser::ID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::REAL() {
  return getToken(TrafficSimDeclParser::REAL, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::TrueID() {
  return getToken(TrafficSimDeclParser::TrueID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntersectionBodyContext::FalseID() {
  return getToken(TrafficSimDeclParser::FalseID, 0);
}


size_t TrafficSimDeclParser::IntersectionBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleIntersectionBody;
}

void TrafficSimDeclParser::IntersectionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntersectionBody(this);
}

void TrafficSimDeclParser::IntersectionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntersectionBody(this);
}

TrafficSimDeclParser::IntersectionBodyContext* TrafficSimDeclParser::intersectionBody() {
  IntersectionBodyContext *_localctx = _tracker.createInstance<IntersectionBodyContext>(_ctx, getState());
  enterRule(_localctx, 12, TrafficSimDeclParser::RuleIntersectionBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Arm: {
        setState(225);
        edge();
        setState(226);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::Sensor: {
        setState(228);
        sensor();
        setState(229);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::TrafficLight:
      case TrafficSimDeclParser::LVehicleDistribution: {
        setState(231);
        object();
        setState(232);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::NameID: {
        setState(234);
        match(TrafficSimDeclParser::NameID);
        setState(235);
        match(TrafficSimDeclParser::COLON);
        setState(236);
        dynamic_cast<IntersectionBodyContext *>(_localctx)->n = match(TrafficSimDeclParser::ID);
        setState(237);
        match(TrafficSimDeclParser::SEMI);
        setState(238);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::Label: {
        setState(239);
        match(TrafficSimDeclParser::Label);
        setState(240);
        match(TrafficSimDeclParser::COLON);
        setState(241);
        dynamic_cast<IntersectionBodyContext *>(_localctx)->l = match(TrafficSimDeclParser::STRING);
        setState(242);
        match(TrafficSimDeclParser::SEMI);
        setState(243);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::HasTrafficLight: {
        setState(244);
        match(TrafficSimDeclParser::HasTrafficLight);
        setState(245);
        match(TrafficSimDeclParser::COLON);
        setState(246);
        dynamic_cast<IntersectionBodyContext *>(_localctx)->hasTrafficLight = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == TrafficSimDeclParser::TrueID

        || _la == TrafficSimDeclParser::FalseID)) {
          dynamic_cast<IntersectionBodyContext *>(_localctx)->hasTrafficLight = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(247);
        match(TrafficSimDeclParser::SEMI);
        setState(248);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::Accident: {
        setState(249);
        match(TrafficSimDeclParser::Accident);
        setState(250);
        match(TrafficSimDeclParser::COLON);
        setState(251);
        dynamic_cast<IntersectionBodyContext *>(_localctx)->accident = match(TrafficSimDeclParser::REAL);
        setState(252);
        match(TrafficSimDeclParser::SEMI);
        setState(253);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::NeighboringTrafficLights: {
        setState(254);
        match(TrafficSimDeclParser::NeighboringTrafficLights);
        setState(255);
        trafficLights();
        setState(256);
        match(TrafficSimDeclParser::SEMI);
        setState(257);
        intersectionBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- TrafficLightsContext ------------------------------------------------------------------

TrafficSimDeclParser::TrafficLightsContext::TrafficLightsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightsContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightsContext::LBRACKET() {
  return getToken(TrafficSimDeclParser::LBRACKET, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightsContext::RBRACKET() {
  return getToken(TrafficSimDeclParser::RBRACKET, 0);
}

TrafficSimDeclParser::TrafficLightContext* TrafficSimDeclParser::TrafficLightsContext::trafficLight() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightContext>(0);
}

TrafficSimDeclParser::TrafficLightsBodyContext* TrafficSimDeclParser::TrafficLightsContext::trafficLightsBody() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightsBodyContext>(0);
}


size_t TrafficSimDeclParser::TrafficLightsContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTrafficLights;
}

void TrafficSimDeclParser::TrafficLightsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrafficLights(this);
}

void TrafficSimDeclParser::TrafficLightsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrafficLights(this);
}

TrafficSimDeclParser::TrafficLightsContext* TrafficSimDeclParser::trafficLights() {
  TrafficLightsContext *_localctx = _tracker.createInstance<TrafficLightsContext>(_ctx, getState());
  enterRule(_localctx, 14, TrafficSimDeclParser::RuleTrafficLights);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(TrafficSimDeclParser::COLON);
    setState(263);
    match(TrafficSimDeclParser::LBRACKET);
    setState(268);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::TrafficLight: {
        setState(264);
        trafficLight();
        setState(265);
        trafficLightsBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(270);
    match(TrafficSimDeclParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TrafficLightsBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::TrafficLightsBodyContext::TrafficLightsBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightsBodyContext::COMMA() {
  return getToken(TrafficSimDeclParser::COMMA, 0);
}

TrafficSimDeclParser::TrafficLightContext* TrafficSimDeclParser::TrafficLightsBodyContext::trafficLight() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightContext>(0);
}

TrafficSimDeclParser::TrafficLightsBodyContext* TrafficSimDeclParser::TrafficLightsBodyContext::trafficLightsBody() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightsBodyContext>(0);
}


size_t TrafficSimDeclParser::TrafficLightsBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTrafficLightsBody;
}

void TrafficSimDeclParser::TrafficLightsBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrafficLightsBody(this);
}

void TrafficSimDeclParser::TrafficLightsBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrafficLightsBody(this);
}

TrafficSimDeclParser::TrafficLightsBodyContext* TrafficSimDeclParser::trafficLightsBody() {
  TrafficLightsBodyContext *_localctx = _tracker.createInstance<TrafficLightsBodyContext>(_ctx, getState());
  enterRule(_localctx, 16, TrafficSimDeclParser::RuleTrafficLightsBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(272);
        match(TrafficSimDeclParser::COMMA);
        setState(273);
        trafficLight();
        setState(274);
        trafficLightsBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
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

//----------------- TrafficSimulationContext ------------------------------------------------------------------

TrafficSimDeclParser::TrafficSimulationContext::TrafficSimulationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TrafficSimulationContext::TRAFFICSIMULATION() {
  return getToken(TrafficSimDeclParser::TRAFFICSIMULATION, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficSimulationContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::TrafficSimulationBodyP1Context* TrafficSimDeclParser::TrafficSimulationContext::trafficSimulationBodyP1() {
  return getRuleContext<TrafficSimDeclParser::TrafficSimulationBodyP1Context>(0);
}

TrafficSimDeclParser::TrafficSimulationBodyP2Context* TrafficSimDeclParser::TrafficSimulationContext::trafficSimulationBodyP2() {
  return getRuleContext<TrafficSimDeclParser::TrafficSimulationBodyP2Context>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficSimulationContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::TrafficSimulationContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTrafficSimulation;
}

void TrafficSimDeclParser::TrafficSimulationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrafficSimulation(this);
}

void TrafficSimDeclParser::TrafficSimulationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrafficSimulation(this);
}

TrafficSimDeclParser::TrafficSimulationContext* TrafficSimDeclParser::trafficSimulation() {
  TrafficSimulationContext *_localctx = _tracker.createInstance<TrafficSimulationContext>(_ctx, getState());
  enterRule(_localctx, 18, TrafficSimDeclParser::RuleTrafficSimulation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(TrafficSimDeclParser::TRAFFICSIMULATION);
    setState(280);
    match(TrafficSimDeclParser::LBRACE);
    setState(281);
    trafficSimulationBodyP1();
    setState(282);
    trafficSimulationBodyP2();
    setState(283);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TrafficSimulationBodyP1Context ------------------------------------------------------------------

TrafficSimDeclParser::TrafficSimulationBodyP1Context::TrafficSimulationBodyP1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::IntersectionContext* TrafficSimDeclParser::TrafficSimulationBodyP1Context::intersection() {
  return getRuleContext<TrafficSimDeclParser::IntersectionContext>(0);
}

TrafficSimDeclParser::TrafficSimulationBodyP1Context* TrafficSimDeclParser::TrafficSimulationBodyP1Context::trafficSimulationBodyP1() {
  return getRuleContext<TrafficSimDeclParser::TrafficSimulationBodyP1Context>(0);
}


size_t TrafficSimDeclParser::TrafficSimulationBodyP1Context::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTrafficSimulationBodyP1;
}

void TrafficSimDeclParser::TrafficSimulationBodyP1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrafficSimulationBodyP1(this);
}

void TrafficSimDeclParser::TrafficSimulationBodyP1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrafficSimulationBodyP1(this);
}

TrafficSimDeclParser::TrafficSimulationBodyP1Context* TrafficSimDeclParser::trafficSimulationBodyP1() {
  TrafficSimulationBodyP1Context *_localctx = _tracker.createInstance<TrafficSimulationBodyP1Context>(_ctx, getState());
  enterRule(_localctx, 20, TrafficSimDeclParser::RuleTrafficSimulationBodyP1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(289);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Intersection: {
        enterOuterAlt(_localctx, 1);
        setState(285);
        intersection();
        setState(286);
        trafficSimulationBodyP1();
        break;
      }

      case TrafficSimDeclParser::Step:
      case TrafficSimDeclParser::RBRACE: {
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

//----------------- TrafficSimulationBodyP2Context ------------------------------------------------------------------

TrafficSimDeclParser::TrafficSimulationBodyP2Context::TrafficSimulationBodyP2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::StepContext* TrafficSimDeclParser::TrafficSimulationBodyP2Context::step() {
  return getRuleContext<TrafficSimDeclParser::StepContext>(0);
}

TrafficSimDeclParser::TrafficSimulationBodyP2Context* TrafficSimDeclParser::TrafficSimulationBodyP2Context::trafficSimulationBodyP2() {
  return getRuleContext<TrafficSimDeclParser::TrafficSimulationBodyP2Context>(0);
}


size_t TrafficSimDeclParser::TrafficSimulationBodyP2Context::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTrafficSimulationBodyP2;
}

void TrafficSimDeclParser::TrafficSimulationBodyP2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrafficSimulationBodyP2(this);
}

void TrafficSimDeclParser::TrafficSimulationBodyP2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrafficSimulationBodyP2(this);
}

TrafficSimDeclParser::TrafficSimulationBodyP2Context* TrafficSimDeclParser::trafficSimulationBodyP2() {
  TrafficSimulationBodyP2Context *_localctx = _tracker.createInstance<TrafficSimulationBodyP2Context>(_ctx, getState());
  enterRule(_localctx, 22, TrafficSimDeclParser::RuleTrafficSimulationBodyP2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Step: {
        enterOuterAlt(_localctx, 1);
        setState(291);
        step();
        setState(292);
        trafficSimulationBodyP2();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- VehicleMovementContext ------------------------------------------------------------------

TrafficSimDeclParser::VehicleMovementContext::VehicleMovementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::VehicleMovementContext::VehicleMovement() {
  return getToken(TrafficSimDeclParser::VehicleMovement, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleMovementContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::VehicleMovementBodyContext* TrafficSimDeclParser::VehicleMovementContext::vehicleMovementBody() {
  return getRuleContext<TrafficSimDeclParser::VehicleMovementBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleMovementContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::VehicleMovementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleVehicleMovement;
}

void TrafficSimDeclParser::VehicleMovementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVehicleMovement(this);
}

void TrafficSimDeclParser::VehicleMovementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVehicleMovement(this);
}

TrafficSimDeclParser::VehicleMovementContext* TrafficSimDeclParser::vehicleMovement() {
  VehicleMovementContext *_localctx = _tracker.createInstance<VehicleMovementContext>(_ctx, getState());
  enterRule(_localctx, 24, TrafficSimDeclParser::RuleVehicleMovement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(TrafficSimDeclParser::VehicleMovement);
    setState(298);
    match(TrafficSimDeclParser::LBRACE);
    setState(299);
    vehicleMovementBody();
    setState(300);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VehicleMovementBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::VehicleMovementBodyContext::VehicleMovementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::StartArmContext* TrafficSimDeclParser::VehicleMovementBodyContext::startArm() {
  return getRuleContext<TrafficSimDeclParser::StartArmContext>(0);
}

TrafficSimDeclParser::VehicleMovementBodyContext* TrafficSimDeclParser::VehicleMovementBodyContext::vehicleMovementBody() {
  return getRuleContext<TrafficSimDeclParser::VehicleMovementBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleMovementBodyContext::VehiclePerHour() {
  return getToken(TrafficSimDeclParser::VehiclePerHour, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleMovementBodyContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleMovementBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::VehicleDistributionNameContext* TrafficSimDeclParser::VehicleMovementBodyContext::vehicleDistributionName() {
  return getRuleContext<TrafficSimDeclParser::VehicleDistributionNameContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleMovementBodyContext::REAL() {
  return getToken(TrafficSimDeclParser::REAL, 0);
}


size_t TrafficSimDeclParser::VehicleMovementBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleVehicleMovementBody;
}

void TrafficSimDeclParser::VehicleMovementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVehicleMovementBody(this);
}

void TrafficSimDeclParser::VehicleMovementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVehicleMovementBody(this);
}

TrafficSimDeclParser::VehicleMovementBodyContext* TrafficSimDeclParser::vehicleMovementBody() {
  VehicleMovementBodyContext *_localctx = _tracker.createInstance<VehicleMovementBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, TrafficSimDeclParser::RuleVehicleMovementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::StartArm: {
        setState(302);
        startArm();
        setState(303);
        vehicleMovementBody();
        break;
      }

      case TrafficSimDeclParser::VehiclePerHour: {
        setState(305);
        match(TrafficSimDeclParser::VehiclePerHour);
        setState(306);
        match(TrafficSimDeclParser::COLON);
        setState(307);
        dynamic_cast<VehicleMovementBodyContext *>(_localctx)->vehiclePerHour = match(TrafficSimDeclParser::REAL);
        setState(308);
        match(TrafficSimDeclParser::SEMI);
        setState(309);
        vehicleMovementBody();
        break;
      }

      case TrafficSimDeclParser::VehicleDistribution: {
        setState(310);
        vehicleDistributionName();
        setState(311);
        vehicleMovementBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- VehicleDistributionNameContext ------------------------------------------------------------------

TrafficSimDeclParser::VehicleDistributionNameContext::VehicleDistributionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionNameContext::VehicleDistribution() {
  return getToken(TrafficSimDeclParser::VehicleDistribution, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionNameContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionNameContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionNameContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}


size_t TrafficSimDeclParser::VehicleDistributionNameContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleVehicleDistributionName;
}

void TrafficSimDeclParser::VehicleDistributionNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVehicleDistributionName(this);
}

void TrafficSimDeclParser::VehicleDistributionNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVehicleDistributionName(this);
}

TrafficSimDeclParser::VehicleDistributionNameContext* TrafficSimDeclParser::vehicleDistributionName() {
  VehicleDistributionNameContext *_localctx = _tracker.createInstance<VehicleDistributionNameContext>(_ctx, getState());
  enterRule(_localctx, 28, TrafficSimDeclParser::RuleVehicleDistributionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(TrafficSimDeclParser::VehicleDistribution);
    setState(317);
    match(TrafficSimDeclParser::COLON);
    setState(318);
    dynamic_cast<VehicleDistributionNameContext *>(_localctx)->vehDist = match(TrafficSimDeclParser::STRING);
    setState(319);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VehicleDistributionContext ------------------------------------------------------------------

TrafficSimDeclParser::VehicleDistributionContext::VehicleDistributionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionContext::LVehicleDistribution() {
  return getToken(TrafficSimDeclParser::LVehicleDistribution, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::VehicleDistributionBodyContext* TrafficSimDeclParser::VehicleDistributionContext::vehicleDistributionBody() {
  return getRuleContext<TrafficSimDeclParser::VehicleDistributionBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::VehicleDistributionContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleVehicleDistribution;
}

void TrafficSimDeclParser::VehicleDistributionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVehicleDistribution(this);
}

void TrafficSimDeclParser::VehicleDistributionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVehicleDistribution(this);
}

TrafficSimDeclParser::VehicleDistributionContext* TrafficSimDeclParser::vehicleDistribution() {
  VehicleDistributionContext *_localctx = _tracker.createInstance<VehicleDistributionContext>(_ctx, getState());
  enterRule(_localctx, 30, TrafficSimDeclParser::RuleVehicleDistribution);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(TrafficSimDeclParser::LVehicleDistribution);
    setState(322);
    match(TrafficSimDeclParser::LBRACE);
    setState(323);
    vehicleDistributionBody();
    setState(324);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VehicleDistributionBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::VehicleDistributionBodyContext::VehicleDistributionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::VehicleDistributionBodyContext* TrafficSimDeclParser::VehicleDistributionBodyContext::vehicleDistributionBody() {
  return getRuleContext<TrafficSimDeclParser::VehicleDistributionBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::Bicycle() {
  return getToken(TrafficSimDeclParser::Bicycle, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::Bus() {
  return getToken(TrafficSimDeclParser::Bus, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::Moped() {
  return getToken(TrafficSimDeclParser::Moped, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::Motorcycle() {
  return getToken(TrafficSimDeclParser::Motorcycle, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::Car() {
  return getToken(TrafficSimDeclParser::Car, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::Emergency() {
  return getToken(TrafficSimDeclParser::Emergency, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::Truck() {
  return getToken(TrafficSimDeclParser::Truck, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::ID() {
  return getToken(TrafficSimDeclParser::ID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::VehicleDistributionBodyContext::REAL() {
  return getToken(TrafficSimDeclParser::REAL, 0);
}


size_t TrafficSimDeclParser::VehicleDistributionBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleVehicleDistributionBody;
}

void TrafficSimDeclParser::VehicleDistributionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVehicleDistributionBody(this);
}

void TrafficSimDeclParser::VehicleDistributionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVehicleDistributionBody(this);
}

TrafficSimDeclParser::VehicleDistributionBodyContext* TrafficSimDeclParser::vehicleDistributionBody() {
  VehicleDistributionBodyContext *_localctx = _tracker.createInstance<VehicleDistributionBodyContext>(_ctx, getState());
  enterRule(_localctx, 32, TrafficSimDeclParser::RuleVehicleDistributionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NameID: {
        setState(326);
        match(TrafficSimDeclParser::NameID);
        setState(327);
        match(TrafficSimDeclParser::COLON);
        setState(328);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->n = match(TrafficSimDeclParser::ID);
        setState(329);
        match(TrafficSimDeclParser::SEMI);
        setState(330);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::Bicycle: {
        setState(331);
        match(TrafficSimDeclParser::Bicycle);
        setState(332);
        match(TrafficSimDeclParser::COLON);
        setState(333);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->bicycle = match(TrafficSimDeclParser::REAL);
        setState(334);
        match(TrafficSimDeclParser::SEMI);
        setState(335);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::Bus: {
        setState(336);
        match(TrafficSimDeclParser::Bus);
        setState(337);
        match(TrafficSimDeclParser::COLON);
        setState(338);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->bus = match(TrafficSimDeclParser::REAL);
        setState(339);
        match(TrafficSimDeclParser::SEMI);
        setState(340);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::Moped: {
        setState(341);
        match(TrafficSimDeclParser::Moped);
        setState(342);
        match(TrafficSimDeclParser::COLON);
        setState(343);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->moped = match(TrafficSimDeclParser::REAL);
        setState(344);
        match(TrafficSimDeclParser::SEMI);
        setState(345);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::Motorcycle: {
        setState(346);
        match(TrafficSimDeclParser::Motorcycle);
        setState(347);
        match(TrafficSimDeclParser::COLON);
        setState(348);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->motorcyc = match(TrafficSimDeclParser::REAL);
        setState(349);
        match(TrafficSimDeclParser::SEMI);
        setState(350);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::Car: {
        setState(351);
        match(TrafficSimDeclParser::Car);
        setState(352);
        match(TrafficSimDeclParser::COLON);
        setState(353);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->car = match(TrafficSimDeclParser::REAL);
        setState(354);
        match(TrafficSimDeclParser::SEMI);
        setState(355);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::Emergency: {
        setState(356);
        match(TrafficSimDeclParser::Emergency);
        setState(357);
        match(TrafficSimDeclParser::COLON);
        setState(358);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->emerg = match(TrafficSimDeclParser::REAL);
        setState(359);
        match(TrafficSimDeclParser::SEMI);
        setState(360);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::Truck: {
        setState(361);
        match(TrafficSimDeclParser::Truck);
        setState(362);
        match(TrafficSimDeclParser::COLON);
        setState(363);
        dynamic_cast<VehicleDistributionBodyContext *>(_localctx)->truck = match(TrafficSimDeclParser::REAL);
        setState(364);
        match(TrafficSimDeclParser::SEMI);
        setState(365);
        vehicleDistributionBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- SensorContext ------------------------------------------------------------------

TrafficSimDeclParser::SensorContext::SensorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::SensorContext::Sensor() {
  return getToken(TrafficSimDeclParser::Sensor, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::SensorBodyContext* TrafficSimDeclParser::SensorContext::sensorBody() {
  return getRuleContext<TrafficSimDeclParser::SensorBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::SensorContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSensor;
}

void TrafficSimDeclParser::SensorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSensor(this);
}

void TrafficSimDeclParser::SensorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSensor(this);
}

TrafficSimDeclParser::SensorContext* TrafficSimDeclParser::sensor() {
  SensorContext *_localctx = _tracker.createInstance<SensorContext>(_ctx, getState());
  enterRule(_localctx, 34, TrafficSimDeclParser::RuleSensor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(TrafficSimDeclParser::Sensor);
    setState(370);
    match(TrafficSimDeclParser::LBRACE);
    setState(371);
    sensorBody();
    setState(372);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SensorBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::SensorBodyContext::SensorBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::SensorBodyContext* TrafficSimDeclParser::SensorBodyContext::sensorBody() {
  return getRuleContext<TrafficSimDeclParser::SensorBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::TypeID() {
  return getToken(TrafficSimDeclParser::TypeID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::Measured() {
  return getToken(TrafficSimDeclParser::Measured, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::Arm() {
  return getToken(TrafficSimDeclParser::Arm, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::Lane() {
  return getToken(TrafficSimDeclParser::Lane, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::Message() {
  return getToken(TrafficSimDeclParser::Message, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::ID() {
  return getToken(TrafficSimDeclParser::ID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SensorBodyContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}


size_t TrafficSimDeclParser::SensorBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSensorBody;
}

void TrafficSimDeclParser::SensorBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSensorBody(this);
}

void TrafficSimDeclParser::SensorBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSensorBody(this);
}

TrafficSimDeclParser::SensorBodyContext* TrafficSimDeclParser::sensorBody() {
  SensorBodyContext *_localctx = _tracker.createInstance<SensorBodyContext>(_ctx, getState());
  enterRule(_localctx, 36, TrafficSimDeclParser::RuleSensorBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(374);
      match(TrafficSimDeclParser::NameID);
      setState(375);
      match(TrafficSimDeclParser::COLON);
      setState(376);
      dynamic_cast<SensorBodyContext *>(_localctx)->n = match(TrafficSimDeclParser::ID);
      setState(377);
      match(TrafficSimDeclParser::SEMI);
      setState(378);
      sensorBody();
      break;
    }

    case 2: {
      setState(379);
      match(TrafficSimDeclParser::TypeID);
      setState(380);
      match(TrafficSimDeclParser::COLON);
      setState(381);
      dynamic_cast<SensorBodyContext *>(_localctx)->t = match(TrafficSimDeclParser::STRING);
      setState(382);
      match(TrafficSimDeclParser::SEMI);
      setState(383);
      sensorBody();
      break;
    }

    case 3: {
      setState(384);
      match(TrafficSimDeclParser::Measured);
      setState(385);
      match(TrafficSimDeclParser::Arm);
      setState(386);
      match(TrafficSimDeclParser::COLON);
      setState(387);
      dynamic_cast<SensorBodyContext *>(_localctx)->mArm = match(TrafficSimDeclParser::STRING);
      setState(388);
      match(TrafficSimDeclParser::SEMI);
      setState(389);
      sensorBody();
      break;
    }

    case 4: {
      setState(390);
      match(TrafficSimDeclParser::Measured);
      setState(391);
      match(TrafficSimDeclParser::Lane);
      setState(392);
      match(TrafficSimDeclParser::COLON);
      setState(393);
      dynamic_cast<SensorBodyContext *>(_localctx)->mLane = match(TrafficSimDeclParser::STRING);
      setState(394);
      match(TrafficSimDeclParser::SEMI);
      setState(395);
      sensorBody();
      break;
    }

    case 5: {
      setState(396);
      match(TrafficSimDeclParser::Message);
      setState(397);
      match(TrafficSimDeclParser::COLON);
      setState(398);
      dynamic_cast<SensorBodyContext *>(_localctx)->mes = match(TrafficSimDeclParser::STRING);
      setState(399);
      match(TrafficSimDeclParser::SEMI);
      setState(400);
      sensorBody();
      break;
    }

    case 6: {
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

//----------------- LanesContext ------------------------------------------------------------------

TrafficSimDeclParser::LanesContext::LanesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::LanesContext::Lanes() {
  return getToken(TrafficSimDeclParser::Lanes, 0);
}

tree::TerminalNode* TrafficSimDeclParser::LanesContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::LanesContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}


size_t TrafficSimDeclParser::LanesContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleLanes;
}

void TrafficSimDeclParser::LanesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLanes(this);
}

void TrafficSimDeclParser::LanesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLanes(this);
}

TrafficSimDeclParser::LanesContext* TrafficSimDeclParser::lanes() {
  LanesContext *_localctx = _tracker.createInstance<LanesContext>(_ctx, getState());
  enterRule(_localctx, 38, TrafficSimDeclParser::RuleLanes);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    match(TrafficSimDeclParser::Lanes);
    setState(405);
    match(TrafficSimDeclParser::COLON);
    setState(406);
    dynamic_cast<LanesContext *>(_localctx)->streetlanes = match(TrafficSimDeclParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OuterConContext ------------------------------------------------------------------

TrafficSimDeclParser::OuterConContext::OuterConContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::OuterConContext::OuterConnection() {
  return getToken(TrafficSimDeclParser::OuterConnection, 0);
}

tree::TerminalNode* TrafficSimDeclParser::OuterConContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::OuterConContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}


size_t TrafficSimDeclParser::OuterConContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleOuterCon;
}

void TrafficSimDeclParser::OuterConContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOuterCon(this);
}

void TrafficSimDeclParser::OuterConContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOuterCon(this);
}

TrafficSimDeclParser::OuterConContext* TrafficSimDeclParser::outerCon() {
  OuterConContext *_localctx = _tracker.createInstance<OuterConContext>(_ctx, getState());
  enterRule(_localctx, 40, TrafficSimDeclParser::RuleOuterCon);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(TrafficSimDeclParser::OuterConnection);
    setState(409);
    match(TrafficSimDeclParser::COLON);
    setState(410);
    dynamic_cast<OuterConContext *>(_localctx)->outer = match(TrafficSimDeclParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringlistContext ------------------------------------------------------------------

TrafficSimDeclParser::StringlistContext::StringlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::StringlistContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StringlistContext::LBRACKET() {
  return getToken(TrafficSimDeclParser::LBRACKET, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StringlistContext::RBRACKET() {
  return getToken(TrafficSimDeclParser::RBRACKET, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StringlistContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}

TrafficSimDeclParser::StringlistBodyContext* TrafficSimDeclParser::StringlistContext::stringlistBody() {
  return getRuleContext<TrafficSimDeclParser::StringlistBodyContext>(0);
}


size_t TrafficSimDeclParser::StringlistContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStringlist;
}

void TrafficSimDeclParser::StringlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringlist(this);
}

void TrafficSimDeclParser::StringlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringlist(this);
}

TrafficSimDeclParser::StringlistContext* TrafficSimDeclParser::stringlist() {
  StringlistContext *_localctx = _tracker.createInstance<StringlistContext>(_ctx, getState());
  enterRule(_localctx, 42, TrafficSimDeclParser::RuleStringlist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(TrafficSimDeclParser::COLON);
    setState(413);
    match(TrafficSimDeclParser::LBRACKET);
    setState(417);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::STRING: {
        setState(414);
        match(TrafficSimDeclParser::STRING);
        setState(415);
        stringlistBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(419);
    match(TrafficSimDeclParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringlistBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::StringlistBodyContext::StringlistBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::StringlistBodyContext::COMMA() {
  return getToken(TrafficSimDeclParser::COMMA, 0);
}

tree::TerminalNode* TrafficSimDeclParser::StringlistBodyContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}

TrafficSimDeclParser::StringlistBodyContext* TrafficSimDeclParser::StringlistBodyContext::stringlistBody() {
  return getRuleContext<TrafficSimDeclParser::StringlistBodyContext>(0);
}


size_t TrafficSimDeclParser::StringlistBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStringlistBody;
}

void TrafficSimDeclParser::StringlistBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringlistBody(this);
}

void TrafficSimDeclParser::StringlistBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringlistBody(this);
}

TrafficSimDeclParser::StringlistBodyContext* TrafficSimDeclParser::stringlistBody() {
  StringlistBodyContext *_localctx = _tracker.createInstance<StringlistBodyContext>(_ctx, getState());
  enterRule(_localctx, 44, TrafficSimDeclParser::RuleStringlistBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(425);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(421);
        match(TrafficSimDeclParser::COMMA);
        setState(422);
        match(TrafficSimDeclParser::STRING);
        setState(423);
        stringlistBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
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

//----------------- InnerConContext ------------------------------------------------------------------

TrafficSimDeclParser::InnerConContext::InnerConContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::InnerConContext::InnerConnections() {
  return getToken(TrafficSimDeclParser::InnerConnections, 0);
}

TrafficSimDeclParser::StringlistContext* TrafficSimDeclParser::InnerConContext::stringlist() {
  return getRuleContext<TrafficSimDeclParser::StringlistContext>(0);
}


size_t TrafficSimDeclParser::InnerConContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleInnerCon;
}

void TrafficSimDeclParser::InnerConContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInnerCon(this);
}

void TrafficSimDeclParser::InnerConContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInnerCon(this);
}

TrafficSimDeclParser::InnerConContext* TrafficSimDeclParser::innerCon() {
  InnerConContext *_localctx = _tracker.createInstance<InnerConContext>(_ctx, getState());
  enterRule(_localctx, 46, TrafficSimDeclParser::RuleInnerCon);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    match(TrafficSimDeclParser::InnerConnections);
    setState(428);
    stringlist();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatesContext ------------------------------------------------------------------

TrafficSimDeclParser::StatesContext::StatesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::StatesContext::States() {
  return getToken(TrafficSimDeclParser::States, 0);
}

TrafficSimDeclParser::StringlistContext* TrafficSimDeclParser::StatesContext::stringlist() {
  return getRuleContext<TrafficSimDeclParser::StringlistContext>(0);
}


size_t TrafficSimDeclParser::StatesContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStates;
}

void TrafficSimDeclParser::StatesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStates(this);
}

void TrafficSimDeclParser::StatesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStates(this);
}

TrafficSimDeclParser::StatesContext* TrafficSimDeclParser::states() {
  StatesContext *_localctx = _tracker.createInstance<StatesContext>(_ctx, getState());
  enterRule(_localctx, 48, TrafficSimDeclParser::RuleStates);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(TrafficSimDeclParser::States);
    setState(431);
    stringlist();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeContext ------------------------------------------------------------------

TrafficSimDeclParser::EdgeContext::EdgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::EdgeContext::Arm() {
  return getToken(TrafficSimDeclParser::Arm, 0);
}

tree::TerminalNode* TrafficSimDeclParser::EdgeContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::EdgeBodyContext* TrafficSimDeclParser::EdgeContext::edgeBody() {
  return getRuleContext<TrafficSimDeclParser::EdgeBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::EdgeContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::EdgeContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleEdge;
}

void TrafficSimDeclParser::EdgeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge(this);
}

void TrafficSimDeclParser::EdgeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge(this);
}

TrafficSimDeclParser::EdgeContext* TrafficSimDeclParser::edge() {
  EdgeContext *_localctx = _tracker.createInstance<EdgeContext>(_ctx, getState());
  enterRule(_localctx, 50, TrafficSimDeclParser::RuleEdge);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(TrafficSimDeclParser::Arm);
    setState(434);
    match(TrafficSimDeclParser::LBRACE);
    setState(435);
    edgeBody();
    setState(436);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::EdgeBodyContext::EdgeBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::EdgeBodyContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::EdgeBodyContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::EdgeBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::EdgeBodyContext* TrafficSimDeclParser::EdgeBodyContext::edgeBody() {
  return getRuleContext<TrafficSimDeclParser::EdgeBodyContext>(0);
}

TrafficSimDeclParser::OuterConContext* TrafficSimDeclParser::EdgeBodyContext::outerCon() {
  return getRuleContext<TrafficSimDeclParser::OuterConContext>(0);
}

TrafficSimDeclParser::InnerConContext* TrafficSimDeclParser::EdgeBodyContext::innerCon() {
  return getRuleContext<TrafficSimDeclParser::InnerConContext>(0);
}

TrafficSimDeclParser::LanesContext* TrafficSimDeclParser::EdgeBodyContext::lanes() {
  return getRuleContext<TrafficSimDeclParser::LanesContext>(0);
}

TrafficSimDeclParser::StatesContext* TrafficSimDeclParser::EdgeBodyContext::states() {
  return getRuleContext<TrafficSimDeclParser::StatesContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::EdgeBodyContext::ID() {
  return getToken(TrafficSimDeclParser::ID, 0);
}


size_t TrafficSimDeclParser::EdgeBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleEdgeBody;
}

void TrafficSimDeclParser::EdgeBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdgeBody(this);
}

void TrafficSimDeclParser::EdgeBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdgeBody(this);
}

TrafficSimDeclParser::EdgeBodyContext* TrafficSimDeclParser::edgeBody() {
  EdgeBodyContext *_localctx = _tracker.createInstance<EdgeBodyContext>(_ctx, getState());
  enterRule(_localctx, 52, TrafficSimDeclParser::RuleEdgeBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NameID: {
        setState(438);
        match(TrafficSimDeclParser::NameID);
        setState(439);
        match(TrafficSimDeclParser::COLON);
        setState(440);
        dynamic_cast<EdgeBodyContext *>(_localctx)->n = match(TrafficSimDeclParser::ID);
        setState(441);
        match(TrafficSimDeclParser::SEMI);
        setState(442);
        edgeBody();
        break;
      }

      case TrafficSimDeclParser::OuterConnection: {
        setState(443);
        outerCon();
        setState(444);
        match(TrafficSimDeclParser::SEMI);
        setState(445);
        edgeBody();
        break;
      }

      case TrafficSimDeclParser::InnerConnections: {
        setState(447);
        innerCon();
        setState(448);
        match(TrafficSimDeclParser::SEMI);
        setState(449);
        edgeBody();
        break;
      }

      case TrafficSimDeclParser::Lanes: {
        setState(451);
        lanes();
        setState(452);
        match(TrafficSimDeclParser::SEMI);
        setState(453);
        edgeBody();
        break;
      }

      case TrafficSimDeclParser::States: {
        setState(455);
        states();
        setState(456);
        match(TrafficSimDeclParser::SEMI);
        setState(457);
        edgeBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- PhaseContext ------------------------------------------------------------------

TrafficSimDeclParser::PhaseContext::PhaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::PhaseContext::Phase() {
  return getToken(TrafficSimDeclParser::Phase, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::PhaseBodyContext* TrafficSimDeclParser::PhaseContext::phaseBody() {
  return getRuleContext<TrafficSimDeclParser::PhaseBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::PhaseContext::getRuleIndex() const {
  return TrafficSimDeclParser::RulePhase;
}

void TrafficSimDeclParser::PhaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhase(this);
}

void TrafficSimDeclParser::PhaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhase(this);
}

TrafficSimDeclParser::PhaseContext* TrafficSimDeclParser::phase() {
  PhaseContext *_localctx = _tracker.createInstance<PhaseContext>(_ctx, getState());
  enterRule(_localctx, 54, TrafficSimDeclParser::RulePhase);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    match(TrafficSimDeclParser::Phase);
    setState(463);
    match(TrafficSimDeclParser::LBRACE);
    setState(464);
    phaseBody();
    setState(465);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PhaseBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::PhaseBodyContext::PhaseBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::Duration() {
  return getToken(TrafficSimDeclParser::Duration, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::PhaseBodyContext* TrafficSimDeclParser::PhaseBodyContext::phaseBody() {
  return getRuleContext<TrafficSimDeclParser::PhaseBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::MinDur() {
  return getToken(TrafficSimDeclParser::MinDur, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::MaxDur() {
  return getToken(TrafficSimDeclParser::MaxDur, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

TrafficSimDeclParser::EdgeContext* TrafficSimDeclParser::PhaseBodyContext::edge() {
  return getRuleContext<TrafficSimDeclParser::EdgeContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::Factor() {
  return getToken(TrafficSimDeclParser::Factor, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::INT() {
  return getToken(TrafficSimDeclParser::INT, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhaseBodyContext::REAL() {
  return getToken(TrafficSimDeclParser::REAL, 0);
}


size_t TrafficSimDeclParser::PhaseBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RulePhaseBody;
}

void TrafficSimDeclParser::PhaseBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhaseBody(this);
}

void TrafficSimDeclParser::PhaseBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhaseBody(this);
}

TrafficSimDeclParser::PhaseBodyContext* TrafficSimDeclParser::phaseBody() {
  PhaseBodyContext *_localctx = _tracker.createInstance<PhaseBodyContext>(_ctx, getState());
  enterRule(_localctx, 56, TrafficSimDeclParser::RulePhaseBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Duration: {
        setState(467);
        match(TrafficSimDeclParser::Duration);
        setState(468);
        match(TrafficSimDeclParser::COLON);
        setState(469);
        dynamic_cast<PhaseBodyContext *>(_localctx)->dur = match(TrafficSimDeclParser::INT);
        setState(470);
        match(TrafficSimDeclParser::SEMI);
        setState(471);
        phaseBody();
        break;
      }

      case TrafficSimDeclParser::MinDur: {
        setState(472);
        match(TrafficSimDeclParser::MinDur);
        setState(473);
        match(TrafficSimDeclParser::COLON);
        setState(474);
        dynamic_cast<PhaseBodyContext *>(_localctx)->minDur = match(TrafficSimDeclParser::INT);
        setState(475);
        match(TrafficSimDeclParser::SEMI);
        setState(476);
        phaseBody();
        break;
      }

      case TrafficSimDeclParser::MaxDur: {
        setState(477);
        match(TrafficSimDeclParser::MaxDur);
        setState(478);
        match(TrafficSimDeclParser::COLON);
        setState(479);
        dynamic_cast<PhaseBodyContext *>(_localctx)->maxDur = match(TrafficSimDeclParser::INT);
        setState(480);
        match(TrafficSimDeclParser::SEMI);
        setState(481);
        phaseBody();
        break;
      }

      case TrafficSimDeclParser::NameID: {
        setState(482);
        match(TrafficSimDeclParser::NameID);
        setState(483);
        match(TrafficSimDeclParser::COLON);
        setState(484);
        dynamic_cast<PhaseBodyContext *>(_localctx)->name = match(TrafficSimDeclParser::STRING);
        setState(485);
        match(TrafficSimDeclParser::SEMI);
        setState(486);
        phaseBody();
        break;
      }

      case TrafficSimDeclParser::Arm: {
        setState(487);
        edge();
        setState(488);
        phaseBody();
        break;
      }

      case TrafficSimDeclParser::Factor: {
        setState(490);
        match(TrafficSimDeclParser::Factor);
        setState(491);
        match(TrafficSimDeclParser::COLON);
        setState(492);
        dynamic_cast<PhaseBodyContext *>(_localctx)->factor = match(TrafficSimDeclParser::REAL);
        setState(493);
        match(TrafficSimDeclParser::SEMI);
        setState(494);
        phaseBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- TransitionsContext ------------------------------------------------------------------

TrafficSimDeclParser::TransitionsContext::TransitionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TransitionsContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionsContext::LBRACKET() {
  return getToken(TrafficSimDeclParser::LBRACKET, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionsContext::RBRACKET() {
  return getToken(TrafficSimDeclParser::RBRACKET, 0);
}

TrafficSimDeclParser::TransitionContext* TrafficSimDeclParser::TransitionsContext::transition() {
  return getRuleContext<TrafficSimDeclParser::TransitionContext>(0);
}

TrafficSimDeclParser::TransitionsBodyContext* TrafficSimDeclParser::TransitionsContext::transitionsBody() {
  return getRuleContext<TrafficSimDeclParser::TransitionsBodyContext>(0);
}


size_t TrafficSimDeclParser::TransitionsContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTransitions;
}

void TrafficSimDeclParser::TransitionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransitions(this);
}

void TrafficSimDeclParser::TransitionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransitions(this);
}

TrafficSimDeclParser::TransitionsContext* TrafficSimDeclParser::transitions() {
  TransitionsContext *_localctx = _tracker.createInstance<TransitionsContext>(_ctx, getState());
  enterRule(_localctx, 58, TrafficSimDeclParser::RuleTransitions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(498);
    match(TrafficSimDeclParser::COLON);
    setState(499);
    match(TrafficSimDeclParser::LBRACKET);
    setState(504);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Transition: {
        setState(500);
        transition();
        setState(501);
        transitionsBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(506);
    match(TrafficSimDeclParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransitionsBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::TransitionsBodyContext::TransitionsBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TransitionsBodyContext::COMMA() {
  return getToken(TrafficSimDeclParser::COMMA, 0);
}

TrafficSimDeclParser::TransitionContext* TrafficSimDeclParser::TransitionsBodyContext::transition() {
  return getRuleContext<TrafficSimDeclParser::TransitionContext>(0);
}

TrafficSimDeclParser::TransitionsBodyContext* TrafficSimDeclParser::TransitionsBodyContext::transitionsBody() {
  return getRuleContext<TrafficSimDeclParser::TransitionsBodyContext>(0);
}


size_t TrafficSimDeclParser::TransitionsBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTransitionsBody;
}

void TrafficSimDeclParser::TransitionsBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransitionsBody(this);
}

void TrafficSimDeclParser::TransitionsBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransitionsBody(this);
}

TrafficSimDeclParser::TransitionsBodyContext* TrafficSimDeclParser::transitionsBody() {
  TransitionsBodyContext *_localctx = _tracker.createInstance<TransitionsBodyContext>(_ctx, getState());
  enterRule(_localctx, 60, TrafficSimDeclParser::RuleTransitionsBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(513);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(508);
        match(TrafficSimDeclParser::COMMA);
        setState(509);
        transition();
        setState(510);
        transitionsBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
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

//----------------- TransitionContext ------------------------------------------------------------------

TrafficSimDeclParser::TransitionContext::TransitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TransitionContext::Transition() {
  return getToken(TrafficSimDeclParser::Transition, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::TransitionBodyContext* TrafficSimDeclParser::TransitionContext::transitionBody() {
  return getRuleContext<TrafficSimDeclParser::TransitionBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::TransitionContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTransition;
}

void TrafficSimDeclParser::TransitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransition(this);
}

void TrafficSimDeclParser::TransitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransition(this);
}

TrafficSimDeclParser::TransitionContext* TrafficSimDeclParser::transition() {
  TransitionContext *_localctx = _tracker.createInstance<TransitionContext>(_ctx, getState());
  enterRule(_localctx, 62, TrafficSimDeclParser::RuleTransition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    match(TrafficSimDeclParser::Transition);
    setState(516);
    match(TrafficSimDeclParser::LBRACE);
    setState(517);
    transitionBody();
    setState(518);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransitionBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::TransitionBodyContext::TransitionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TransitionBodyContext::TransitionPhases() {
  return getToken(TrafficSimDeclParser::TransitionPhases, 0);
}

TrafficSimDeclParser::PhasesContext* TrafficSimDeclParser::TransitionBodyContext::phases() {
  return getRuleContext<TrafficSimDeclParser::PhasesContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::TransitionBodyContext* TrafficSimDeclParser::TransitionBodyContext::transitionBody() {
  return getRuleContext<TrafficSimDeclParser::TransitionBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionBodyContext::Trigger() {
  return getToken(TrafficSimDeclParser::Trigger, 0);
}

TrafficSimDeclParser::StringlistContext* TrafficSimDeclParser::TransitionBodyContext::stringlist() {
  return getRuleContext<TrafficSimDeclParser::StringlistContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionBodyContext::Start() {
  return getToken(TrafficSimDeclParser::Start, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionBodyContext::Phase() {
  return getToken(TrafficSimDeclParser::Phase, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TransitionBodyContext::End() {
  return getToken(TrafficSimDeclParser::End, 0);
}

TrafficSimDeclParser::PhaseContext* TrafficSimDeclParser::TransitionBodyContext::phase() {
  return getRuleContext<TrafficSimDeclParser::PhaseContext>(0);
}


size_t TrafficSimDeclParser::TransitionBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTransitionBody;
}

void TrafficSimDeclParser::TransitionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransitionBody(this);
}

void TrafficSimDeclParser::TransitionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransitionBody(this);
}

TrafficSimDeclParser::TransitionBodyContext* TrafficSimDeclParser::transitionBody() {
  TransitionBodyContext *_localctx = _tracker.createInstance<TransitionBodyContext>(_ctx, getState());
  enterRule(_localctx, 64, TrafficSimDeclParser::RuleTransitionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(543);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::TransitionPhases: {
        setState(520);
        match(TrafficSimDeclParser::TransitionPhases);
        setState(521);
        phases();
        setState(522);
        match(TrafficSimDeclParser::SEMI);
        setState(523);
        transitionBody();
        break;
      }

      case TrafficSimDeclParser::Trigger: {
        setState(525);
        match(TrafficSimDeclParser::Trigger);
        setState(526);
        stringlist();
        setState(527);
        match(TrafficSimDeclParser::SEMI);
        setState(528);
        transitionBody();
        break;
      }

      case TrafficSimDeclParser::Start: {
        setState(530);
        match(TrafficSimDeclParser::Start);
        setState(531);
        match(TrafficSimDeclParser::Phase);
        setState(532);
        dynamic_cast<TransitionBodyContext *>(_localctx)->startPhase = phase();
        setState(533);
        match(TrafficSimDeclParser::SEMI);
        setState(534);
        transitionBody();
        break;
      }

      case TrafficSimDeclParser::End: {
        setState(536);
        match(TrafficSimDeclParser::End);
        setState(537);
        match(TrafficSimDeclParser::Phase);
        setState(538);
        dynamic_cast<TransitionBodyContext *>(_localctx)->endPhase = phase();
        setState(539);
        match(TrafficSimDeclParser::SEMI);
        setState(540);
        transitionBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- PhasesContext ------------------------------------------------------------------

TrafficSimDeclParser::PhasesContext::PhasesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::PhasesContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhasesContext::LBRACKET() {
  return getToken(TrafficSimDeclParser::LBRACKET, 0);
}

tree::TerminalNode* TrafficSimDeclParser::PhasesContext::RBRACKET() {
  return getToken(TrafficSimDeclParser::RBRACKET, 0);
}

TrafficSimDeclParser::PhaseContext* TrafficSimDeclParser::PhasesContext::phase() {
  return getRuleContext<TrafficSimDeclParser::PhaseContext>(0);
}

TrafficSimDeclParser::PhasesBodyContext* TrafficSimDeclParser::PhasesContext::phasesBody() {
  return getRuleContext<TrafficSimDeclParser::PhasesBodyContext>(0);
}


size_t TrafficSimDeclParser::PhasesContext::getRuleIndex() const {
  return TrafficSimDeclParser::RulePhases;
}

void TrafficSimDeclParser::PhasesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhases(this);
}

void TrafficSimDeclParser::PhasesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhases(this);
}

TrafficSimDeclParser::PhasesContext* TrafficSimDeclParser::phases() {
  PhasesContext *_localctx = _tracker.createInstance<PhasesContext>(_ctx, getState());
  enterRule(_localctx, 66, TrafficSimDeclParser::RulePhases);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(545);
    match(TrafficSimDeclParser::COLON);
    setState(546);
    match(TrafficSimDeclParser::LBRACKET);
    setState(551);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Phase: {
        setState(547);
        phase();
        setState(548);
        phasesBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(553);
    match(TrafficSimDeclParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PhasesBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::PhasesBodyContext::PhasesBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::PhasesBodyContext::COMMA() {
  return getToken(TrafficSimDeclParser::COMMA, 0);
}

TrafficSimDeclParser::PhaseContext* TrafficSimDeclParser::PhasesBodyContext::phase() {
  return getRuleContext<TrafficSimDeclParser::PhaseContext>(0);
}

TrafficSimDeclParser::PhasesBodyContext* TrafficSimDeclParser::PhasesBodyContext::phasesBody() {
  return getRuleContext<TrafficSimDeclParser::PhasesBodyContext>(0);
}


size_t TrafficSimDeclParser::PhasesBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RulePhasesBody;
}

void TrafficSimDeclParser::PhasesBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhasesBody(this);
}

void TrafficSimDeclParser::PhasesBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhasesBody(this);
}

TrafficSimDeclParser::PhasesBodyContext* TrafficSimDeclParser::phasesBody() {
  PhasesBodyContext *_localctx = _tracker.createInstance<PhasesBodyContext>(_ctx, getState());
  enterRule(_localctx, 68, TrafficSimDeclParser::RulePhasesBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(560);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(555);
        match(TrafficSimDeclParser::COMMA);
        setState(556);
        phase();
        setState(557);
        phasesBody();
        break;
      }

      case TrafficSimDeclParser::RBRACKET: {
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

//----------------- TrafficLightContext ------------------------------------------------------------------

TrafficSimDeclParser::TrafficLightContext::TrafficLightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightContext::TrafficLight() {
  return getToken(TrafficSimDeclParser::TrafficLight, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

TrafficSimDeclParser::TrafficLightBodyContext* TrafficSimDeclParser::TrafficLightContext::trafficLightBody() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}


size_t TrafficSimDeclParser::TrafficLightContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTrafficLight;
}

void TrafficSimDeclParser::TrafficLightContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrafficLight(this);
}

void TrafficSimDeclParser::TrafficLightContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrafficLight(this);
}

TrafficSimDeclParser::TrafficLightContext* TrafficSimDeclParser::trafficLight() {
  TrafficLightContext *_localctx = _tracker.createInstance<TrafficLightContext>(_ctx, getState());
  enterRule(_localctx, 70, TrafficSimDeclParser::RuleTrafficLight);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(562);
    match(TrafficSimDeclParser::TrafficLight);
    setState(563);
    match(TrafficSimDeclParser::LBRACE);
    setState(564);
    trafficLightBody();
    setState(565);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TrafficLightBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::TrafficLightBodyContext::TrafficLightBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::Transitions() {
  return getToken(TrafficSimDeclParser::Transitions, 0);
}

TrafficSimDeclParser::TransitionsContext* TrafficSimDeclParser::TrafficLightBodyContext::transitions() {
  return getRuleContext<TrafficSimDeclParser::TransitionsContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::TrafficLightBodyContext* TrafficSimDeclParser::TrafficLightBodyContext::trafficLightBody() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::TypeID() {
  return getToken(TrafficSimDeclParser::TypeID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::Duration() {
  return getToken(TrafficSimDeclParser::Duration, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::Turns() {
  return getToken(TrafficSimDeclParser::Turns, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::Phases() {
  return getToken(TrafficSimDeclParser::Phases, 0);
}

TrafficSimDeclParser::PhasesContext* TrafficSimDeclParser::TrafficLightBodyContext::phases() {
  return getRuleContext<TrafficSimDeclParser::PhasesContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::ID() {
  return getToken(TrafficSimDeclParser::ID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TrafficLightBodyContext::INT() {
  return getToken(TrafficSimDeclParser::INT, 0);
}


size_t TrafficSimDeclParser::TrafficLightBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTrafficLightBody;
}

void TrafficSimDeclParser::TrafficLightBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrafficLightBody(this);
}

void TrafficSimDeclParser::TrafficLightBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrafficLightBody(this);
}

TrafficSimDeclParser::TrafficLightBodyContext* TrafficSimDeclParser::trafficLightBody() {
  TrafficLightBodyContext *_localctx = _tracker.createInstance<TrafficLightBodyContext>(_ctx, getState());
  enterRule(_localctx, 72, TrafficSimDeclParser::RuleTrafficLightBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(598);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::Transitions: {
        setState(567);
        match(TrafficSimDeclParser::Transitions);
        setState(568);
        transitions();
        setState(569);
        match(TrafficSimDeclParser::SEMI);
        setState(570);
        trafficLightBody();
        break;
      }

      case TrafficSimDeclParser::NameID: {
        setState(572);
        match(TrafficSimDeclParser::NameID);
        setState(573);
        match(TrafficSimDeclParser::COLON);
        setState(574);
        dynamic_cast<TrafficLightBodyContext *>(_localctx)->name = match(TrafficSimDeclParser::ID);
        setState(575);
        match(TrafficSimDeclParser::SEMI);
        setState(576);
        trafficLightBody();
        break;
      }

      case TrafficSimDeclParser::TypeID: {
        setState(577);
        match(TrafficSimDeclParser::TypeID);
        setState(578);
        match(TrafficSimDeclParser::COLON);
        setState(579);
        dynamic_cast<TrafficLightBodyContext *>(_localctx)->type = match(TrafficSimDeclParser::STRING);
        setState(580);
        match(TrafficSimDeclParser::SEMI);
        setState(581);
        trafficLightBody();
        break;
      }

      case TrafficSimDeclParser::Duration: {
        setState(582);
        match(TrafficSimDeclParser::Duration);
        setState(583);
        match(TrafficSimDeclParser::COLON);
        setState(584);
        dynamic_cast<TrafficLightBodyContext *>(_localctx)->dur = match(TrafficSimDeclParser::INT);
        setState(585);
        match(TrafficSimDeclParser::SEMI);
        setState(586);
        trafficLightBody();
        break;
      }

      case TrafficSimDeclParser::Turns: {
        setState(587);
        match(TrafficSimDeclParser::Turns);
        setState(588);
        match(TrafficSimDeclParser::COLON);
        setState(589);
        dynamic_cast<TrafficLightBodyContext *>(_localctx)->turns = match(TrafficSimDeclParser::INT);
        setState(590);
        match(TrafficSimDeclParser::SEMI);
        setState(591);
        trafficLightBody();
        break;
      }

      case TrafficSimDeclParser::Phases: {
        setState(592);
        match(TrafficSimDeclParser::Phases);
        setState(593);
        phases();
        setState(594);
        match(TrafficSimDeclParser::SEMI);
        setState(595);
        trafficLightBody();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
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

//----------------- ObjectContext ------------------------------------------------------------------

TrafficSimDeclParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::TrafficLightContext* TrafficSimDeclParser::ObjectContext::trafficLight() {
  return getRuleContext<TrafficSimDeclParser::TrafficLightContext>(0);
}

TrafficSimDeclParser::VehicleDistributionContext* TrafficSimDeclParser::ObjectContext::vehicleDistribution() {
  return getRuleContext<TrafficSimDeclParser::VehicleDistributionContext>(0);
}


size_t TrafficSimDeclParser::ObjectContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleObject;
}

void TrafficSimDeclParser::ObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject(this);
}

void TrafficSimDeclParser::ObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject(this);
}

TrafficSimDeclParser::ObjectContext* TrafficSimDeclParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 74, TrafficSimDeclParser::RuleObject);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(602);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::TrafficLight: {
        enterOuterAlt(_localctx, 1);
        setState(600);
        trafficLight();
        break;
      }

      case TrafficSimDeclParser::LVehicleDistribution: {
        enterOuterAlt(_localctx, 2);
        setState(601);
        vehicleDistribution();
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

TrafficSimDeclParser::ComponentIdPathContext::ComponentIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TrafficSimDeclParser::ContextIDContext *> TrafficSimDeclParser::ComponentIdPathContext::contextID() {
  return getRuleContexts<TrafficSimDeclParser::ContextIDContext>();
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::ComponentIdPathContext::contextID(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::ComponentIdPathContext::DOT() {
  return getTokens(TrafficSimDeclParser::DOT);
}

tree::TerminalNode* TrafficSimDeclParser::ComponentIdPathContext::DOT(size_t i) {
  return getToken(TrafficSimDeclParser::DOT, i);
}


size_t TrafficSimDeclParser::ComponentIdPathContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleComponentIdPath;
}

void TrafficSimDeclParser::ComponentIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentIdPath(this);
}

void TrafficSimDeclParser::ComponentIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentIdPath(this);
}

TrafficSimDeclParser::ComponentIdPathContext* TrafficSimDeclParser::componentIdPath() {
  ComponentIdPathContext *_localctx = _tracker.createInstance<ComponentIdPathContext>(_ctx, getState());
  enterRule(_localctx, 76, TrafficSimDeclParser::RuleComponentIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    contextID();
    setState(609);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TrafficSimDeclParser::DOT) {
      setState(605);
      match(TrafficSimDeclParser::DOT);
      setState(606);
      contextID();
      setState(611);
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

TrafficSimDeclParser::SignalIdPathContext::SignalIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TrafficSimDeclParser::ContextIDContext *> TrafficSimDeclParser::SignalIdPathContext::contextID() {
  return getRuleContexts<TrafficSimDeclParser::ContextIDContext>();
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::SignalIdPathContext::contextID(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::SignalIdPathContext::DOT() {
  return getTokens(TrafficSimDeclParser::DOT);
}

tree::TerminalNode* TrafficSimDeclParser::SignalIdPathContext::DOT(size_t i) {
  return getToken(TrafficSimDeclParser::DOT, i);
}


size_t TrafficSimDeclParser::SignalIdPathContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSignalIdPath;
}

void TrafficSimDeclParser::SignalIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalIdPath(this);
}

void TrafficSimDeclParser::SignalIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalIdPath(this);
}

TrafficSimDeclParser::SignalIdPathContext* TrafficSimDeclParser::signalIdPath() {
  SignalIdPathContext *_localctx = _tracker.createInstance<SignalIdPathContext>(_ctx, getState());
  enterRule(_localctx, 78, TrafficSimDeclParser::RuleSignalIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    contextID();
    setState(617);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TrafficSimDeclParser::DOT) {
      setState(613);
      match(TrafficSimDeclParser::DOT);
      setState(614);
      contextID();
      setState(619);
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

TrafficSimDeclParser::AttributeIdPathContext::AttributeIdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::AttributeNameContext* TrafficSimDeclParser::AttributeIdPathContext::attributeName() {
  return getRuleContext<TrafficSimDeclParser::AttributeNameContext>(0);
}

std::vector<TrafficSimDeclParser::ContextIDContext *> TrafficSimDeclParser::AttributeIdPathContext::contextID() {
  return getRuleContexts<TrafficSimDeclParser::ContextIDContext>();
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::AttributeIdPathContext::contextID(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::AttributeIdPathContext::DOT() {
  return getTokens(TrafficSimDeclParser::DOT);
}

tree::TerminalNode* TrafficSimDeclParser::AttributeIdPathContext::DOT(size_t i) {
  return getToken(TrafficSimDeclParser::DOT, i);
}


size_t TrafficSimDeclParser::AttributeIdPathContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleAttributeIdPath;
}

void TrafficSimDeclParser::AttributeIdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeIdPath(this);
}

void TrafficSimDeclParser::AttributeIdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeIdPath(this);
}

TrafficSimDeclParser::AttributeIdPathContext* TrafficSimDeclParser::attributeIdPath() {
  AttributeIdPathContext *_localctx = _tracker.createInstance<AttributeIdPathContext>(_ctx, getState());
  enterRule(_localctx, 80, TrafficSimDeclParser::RuleAttributeIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(620);
      attributeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(621);
      contextID();
      setState(626);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TrafficSimDeclParser::DOT) {
        setState(622);
        match(TrafficSimDeclParser::DOT);
        setState(623);
        contextID();
        setState(628);
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

TrafficSimDeclParser::SignalSendContext::SignalSendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::SignalIdPathContext* TrafficSimDeclParser::SignalSendContext::signalIdPath() {
  return getRuleContext<TrafficSimDeclParser::SignalIdPathContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SignalSendContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

TrafficSimDeclParser::FunctionCallBodyContext* TrafficSimDeclParser::SignalSendContext::functionCallBody() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SignalSendContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}


size_t TrafficSimDeclParser::SignalSendContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSignalSend;
}

void TrafficSimDeclParser::SignalSendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalSend(this);
}

void TrafficSimDeclParser::SignalSendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalSend(this);
}

TrafficSimDeclParser::SignalSendContext* TrafficSimDeclParser::signalSend() {
  SignalSendContext *_localctx = _tracker.createInstance<SignalSendContext>(_ctx, getState());
  enterRule(_localctx, 82, TrafficSimDeclParser::RuleSignalSend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    signalIdPath();
    setState(632);
    match(TrafficSimDeclParser::LPAREN);
    setState(633);
    functionCallBody();
    setState(634);
    match(TrafficSimDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::CommonDeclContext::CommonDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TrafficSimDeclParser::TypeDefDeclContext *> TrafficSimDeclParser::CommonDeclContext::typeDefDecl() {
  return getRuleContexts<TrafficSimDeclParser::TypeDefDeclContext>();
}

TrafficSimDeclParser::TypeDefDeclContext* TrafficSimDeclParser::CommonDeclContext::typeDefDecl(size_t i) {
  return getRuleContext<TrafficSimDeclParser::TypeDefDeclContext>(i);
}

std::vector<TrafficSimDeclParser::AttributeDeclContext *> TrafficSimDeclParser::CommonDeclContext::attributeDecl() {
  return getRuleContexts<TrafficSimDeclParser::AttributeDeclContext>();
}

TrafficSimDeclParser::AttributeDeclContext* TrafficSimDeclParser::CommonDeclContext::attributeDecl(size_t i) {
  return getRuleContext<TrafficSimDeclParser::AttributeDeclContext>(i);
}

std::vector<TrafficSimDeclParser::SignalDeclContext *> TrafficSimDeclParser::CommonDeclContext::signalDecl() {
  return getRuleContexts<TrafficSimDeclParser::SignalDeclContext>();
}

TrafficSimDeclParser::SignalDeclContext* TrafficSimDeclParser::CommonDeclContext::signalDecl(size_t i) {
  return getRuleContext<TrafficSimDeclParser::SignalDeclContext>(i);
}


size_t TrafficSimDeclParser::CommonDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleCommonDecl;
}

void TrafficSimDeclParser::CommonDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonDecl(this);
}

void TrafficSimDeclParser::CommonDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonDecl(this);
}

TrafficSimDeclParser::CommonDeclContext* TrafficSimDeclParser::commonDecl() {
  CommonDeclContext *_localctx = _tracker.createInstance<CommonDeclContext>(_ctx, getState());
  enterRule(_localctx, 84, TrafficSimDeclParser::RuleCommonDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(641);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TrafficSimDeclParser::TypeID)
      | (1ULL << TrafficSimDeclParser::AttributeID)
      | (1ULL << TrafficSimDeclParser::SignalID))) != 0)) {
      setState(639);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TrafficSimDeclParser::TypeID: {
          setState(636);
          typeDefDecl();
          break;
        }

        case TrafficSimDeclParser::AttributeID: {
          setState(637);
          attributeDecl();
          break;
        }

        case TrafficSimDeclParser::SignalID: {
          setState(638);
          signalDecl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(643);
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

TrafficSimDeclParser::ImportPathDeclContext::ImportPathDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::ImportPathBodyContext* TrafficSimDeclParser::ImportPathDeclContext::importPathBody() {
  return getRuleContext<TrafficSimDeclParser::ImportPathBodyContext>(0);
}

TrafficSimDeclParser::ImportPathDeclContext* TrafficSimDeclParser::ImportPathDeclContext::importPathDecl() {
  return getRuleContext<TrafficSimDeclParser::ImportPathDeclContext>(0);
}


size_t TrafficSimDeclParser::ImportPathDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleImportPathDecl;
}

void TrafficSimDeclParser::ImportPathDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathDecl(this);
}

void TrafficSimDeclParser::ImportPathDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathDecl(this);
}

TrafficSimDeclParser::ImportPathDeclContext* TrafficSimDeclParser::importPathDecl() {
  ImportPathDeclContext *_localctx = _tracker.createInstance<ImportPathDeclContext>(_ctx, getState());
  enterRule(_localctx, 86, TrafficSimDeclParser::RuleImportPathDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(648);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(644);
      importPathBody();
      setState(645);
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

TrafficSimDeclParser::ImportPathBodyContext::ImportPathBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ImportPathBodyContext::ImportID() {
  return getToken(TrafficSimDeclParser::ImportID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ImportPathBodyContext::LESSTHAN() {
  return getToken(TrafficSimDeclParser::LESSTHAN, 0);
}

TrafficSimDeclParser::ImportFileBodyContext* TrafficSimDeclParser::ImportPathBodyContext::importFileBody() {
  return getRuleContext<TrafficSimDeclParser::ImportFileBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::ImportPathBodyContext::GREATERTHAN() {
  return getToken(TrafficSimDeclParser::GREATERTHAN, 0);
}

TrafficSimDeclParser::ImportAsContext* TrafficSimDeclParser::ImportPathBodyContext::importAs() {
  return getRuleContext<TrafficSimDeclParser::ImportAsContext>(0);
}


size_t TrafficSimDeclParser::ImportPathBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleImportPathBody;
}

void TrafficSimDeclParser::ImportPathBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPathBody(this);
}

void TrafficSimDeclParser::ImportPathBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPathBody(this);
}

TrafficSimDeclParser::ImportPathBodyContext* TrafficSimDeclParser::importPathBody() {
  ImportPathBodyContext *_localctx = _tracker.createInstance<ImportPathBodyContext>(_ctx, getState());
  enterRule(_localctx, 88, TrafficSimDeclParser::RuleImportPathBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(650);
    match(TrafficSimDeclParser::ImportID);
    setState(651);
    match(TrafficSimDeclParser::LESSTHAN);
    setState(652);
    importFileBody();
    setState(653);
    match(TrafficSimDeclParser::GREATERTHAN);
    setState(654);
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

TrafficSimDeclParser::ImportFileBodyContext::ImportFileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TrafficSimDeclParser::ContextIDContext *> TrafficSimDeclParser::ImportFileBodyContext::contextID() {
  return getRuleContexts<TrafficSimDeclParser::ContextIDContext>();
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::ImportFileBodyContext::contextID(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TrafficSimDeclParser::ImportFileBodyContext::DOT() {
  return getToken(TrafficSimDeclParser::DOT, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ImportFileBodyContext::RANGE() {
  return getToken(TrafficSimDeclParser::RANGE, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ImportFileBodyContext::DIV() {
  return getToken(TrafficSimDeclParser::DIV, 0);
}

TrafficSimDeclParser::ImportFileBodyContext* TrafficSimDeclParser::ImportFileBodyContext::importFileBody() {
  return getRuleContext<TrafficSimDeclParser::ImportFileBodyContext>(0);
}


size_t TrafficSimDeclParser::ImportFileBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleImportFileBody;
}

void TrafficSimDeclParser::ImportFileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFileBody(this);
}

void TrafficSimDeclParser::ImportFileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFileBody(this);
}

TrafficSimDeclParser::ImportFileBodyContext* TrafficSimDeclParser::importFileBody() {
  ImportFileBodyContext *_localctx = _tracker.createInstance<ImportFileBodyContext>(_ctx, getState());
  enterRule(_localctx, 90, TrafficSimDeclParser::RuleImportFileBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(667);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(656);
      contextID();
      setState(657);
      match(TrafficSimDeclParser::DOT);
      setState(658);
      contextID();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(660);
      match(TrafficSimDeclParser::RANGE);
      setState(661);
      match(TrafficSimDeclParser::DIV);
      setState(662);
      importFileBody();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(663);
      contextID();
      setState(664);
      match(TrafficSimDeclParser::DIV);
      setState(665);
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

TrafficSimDeclParser::ImportAsContext::ImportAsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ImportAsContext::AsID() {
  return getToken(TrafficSimDeclParser::AsID, 0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::ImportAsContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}


size_t TrafficSimDeclParser::ImportAsContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleImportAs;
}

void TrafficSimDeclParser::ImportAsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportAs(this);
}

void TrafficSimDeclParser::ImportAsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportAs(this);
}

TrafficSimDeclParser::ImportAsContext* TrafficSimDeclParser::importAs() {
  ImportAsContext *_localctx = _tracker.createInstance<ImportAsContext>(_ctx, getState());
  enterRule(_localctx, 92, TrafficSimDeclParser::RuleImportAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(672);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::AsID: {
        enterOuterAlt(_localctx, 1);
        setState(669);
        match(TrafficSimDeclParser::AsID);
        setState(670);
        contextID();
        break;
      }

      case TrafficSimDeclParser::ImportID: {
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

TrafficSimDeclParser::TypeDefDeclContext::TypeDefDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TypeDefDeclContext::TypeID() {
  return getToken(TrafficSimDeclParser::TypeID, 0);
}

TrafficSimDeclParser::TypeDeclContext* TrafficSimDeclParser::TypeDefDeclContext::typeDecl() {
  return getRuleContext<TrafficSimDeclParser::TypeDeclContext>(0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::TypeDefDeclContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TypeDefDeclContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}


size_t TrafficSimDeclParser::TypeDefDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTypeDefDecl;
}

void TrafficSimDeclParser::TypeDefDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDefDecl(this);
}

void TrafficSimDeclParser::TypeDefDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDefDecl(this);
}

TrafficSimDeclParser::TypeDefDeclContext* TrafficSimDeclParser::typeDefDecl() {
  TypeDefDeclContext *_localctx = _tracker.createInstance<TypeDefDeclContext>(_ctx, getState());
  enterRule(_localctx, 94, TrafficSimDeclParser::RuleTypeDefDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    match(TrafficSimDeclParser::TypeID);
    setState(675);
    typeDecl();
    setState(676);
    contextID();
    setState(677);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::IntTypeDeclContext* TrafficSimDeclParser::TypeDeclContext::intTypeDecl() {
  return getRuleContext<TrafficSimDeclParser::IntTypeDeclContext>(0);
}

TrafficSimDeclParser::RealTypeDeclContext* TrafficSimDeclParser::TypeDeclContext::realTypeDecl() {
  return getRuleContext<TrafficSimDeclParser::RealTypeDeclContext>(0);
}

TrafficSimDeclParser::EnumTypeDeclContext* TrafficSimDeclParser::TypeDeclContext::enumTypeDecl() {
  return getRuleContext<TrafficSimDeclParser::EnumTypeDeclContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::TypeDeclContext::BoolID() {
  return getToken(TrafficSimDeclParser::BoolID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TypeDeclContext::StringID() {
  return getToken(TrafficSimDeclParser::StringID, 0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::TypeDeclContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}


size_t TrafficSimDeclParser::TypeDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTypeDecl;
}

void TrafficSimDeclParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void TrafficSimDeclParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

TrafficSimDeclParser::TypeDeclContext* TrafficSimDeclParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 96, TrafficSimDeclParser::RuleTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(685);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::IntID: {
        enterOuterAlt(_localctx, 1);
        setState(679);
        intTypeDecl();
        break;
      }

      case TrafficSimDeclParser::RealID: {
        enterOuterAlt(_localctx, 2);
        setState(680);
        realTypeDecl();
        break;
      }

      case TrafficSimDeclParser::EnumID: {
        enterOuterAlt(_localctx, 3);
        setState(681);
        enumTypeDecl();
        break;
      }

      case TrafficSimDeclParser::BoolID: {
        enterOuterAlt(_localctx, 4);
        setState(682);
        match(TrafficSimDeclParser::BoolID);
        break;
      }

      case TrafficSimDeclParser::StringID: {
        enterOuterAlt(_localctx, 5);
        setState(683);
        match(TrafficSimDeclParser::StringID);
        break;
      }

      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(684);
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

TrafficSimDeclParser::IntTypeDeclContext::IntTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::IntTypeDeclContext::IntID() {
  return getToken(TrafficSimDeclParser::IntID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntTypeDeclContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::IntTypeDeclContext::INT() {
  return getTokens(TrafficSimDeclParser::INT);
}

tree::TerminalNode* TrafficSimDeclParser::IntTypeDeclContext::INT(size_t i) {
  return getToken(TrafficSimDeclParser::INT, i);
}

tree::TerminalNode* TrafficSimDeclParser::IntTypeDeclContext::RANGE() {
  return getToken(TrafficSimDeclParser::RANGE, 0);
}

tree::TerminalNode* TrafficSimDeclParser::IntTypeDeclContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}


size_t TrafficSimDeclParser::IntTypeDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleIntTypeDecl;
}

void TrafficSimDeclParser::IntTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntTypeDecl(this);
}

void TrafficSimDeclParser::IntTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntTypeDecl(this);
}

TrafficSimDeclParser::IntTypeDeclContext* TrafficSimDeclParser::intTypeDecl() {
  IntTypeDeclContext *_localctx = _tracker.createInstance<IntTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 98, TrafficSimDeclParser::RuleIntTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(687);
    match(TrafficSimDeclParser::IntID);
    setState(694);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::LPAREN: {
        setState(688);
        match(TrafficSimDeclParser::LPAREN);
        setState(689);
        match(TrafficSimDeclParser::INT);
        setState(690);
        match(TrafficSimDeclParser::RANGE);
        setState(691);
        match(TrafficSimDeclParser::INT);
        setState(692);
        match(TrafficSimDeclParser::RPAREN);
        break;
      }

      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::ID: {
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

TrafficSimDeclParser::RealTypeDeclContext::RealTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::RealTypeDeclContext::RealID() {
  return getToken(TrafficSimDeclParser::RealID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::RealTypeDeclContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::RealTypeDeclContext::REAL() {
  return getTokens(TrafficSimDeclParser::REAL);
}

tree::TerminalNode* TrafficSimDeclParser::RealTypeDeclContext::REAL(size_t i) {
  return getToken(TrafficSimDeclParser::REAL, i);
}

tree::TerminalNode* TrafficSimDeclParser::RealTypeDeclContext::RANGE() {
  return getToken(TrafficSimDeclParser::RANGE, 0);
}

tree::TerminalNode* TrafficSimDeclParser::RealTypeDeclContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}


size_t TrafficSimDeclParser::RealTypeDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleRealTypeDecl;
}

void TrafficSimDeclParser::RealTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealTypeDecl(this);
}

void TrafficSimDeclParser::RealTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealTypeDecl(this);
}

TrafficSimDeclParser::RealTypeDeclContext* TrafficSimDeclParser::realTypeDecl() {
  RealTypeDeclContext *_localctx = _tracker.createInstance<RealTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 100, TrafficSimDeclParser::RuleRealTypeDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(696);
    match(TrafficSimDeclParser::RealID);
    setState(703);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::LPAREN: {
        setState(697);
        match(TrafficSimDeclParser::LPAREN);
        setState(698);
        match(TrafficSimDeclParser::REAL);
        setState(699);
        match(TrafficSimDeclParser::RANGE);
        setState(700);
        match(TrafficSimDeclParser::REAL);
        setState(701);
        match(TrafficSimDeclParser::RPAREN);
        break;
      }

      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::ID: {
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

TrafficSimDeclParser::EnumTypeDeclContext::EnumTypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::EnumTypeDeclContext::EnumID() {
  return getToken(TrafficSimDeclParser::EnumID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::EnumTypeDeclContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

std::vector<TrafficSimDeclParser::ContextIDContext *> TrafficSimDeclParser::EnumTypeDeclContext::contextID() {
  return getRuleContexts<TrafficSimDeclParser::ContextIDContext>();
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::EnumTypeDeclContext::contextID(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TrafficSimDeclParser::EnumTypeDeclContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::EnumTypeDeclContext::COMMA() {
  return getTokens(TrafficSimDeclParser::COMMA);
}

tree::TerminalNode* TrafficSimDeclParser::EnumTypeDeclContext::COMMA(size_t i) {
  return getToken(TrafficSimDeclParser::COMMA, i);
}


size_t TrafficSimDeclParser::EnumTypeDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleEnumTypeDecl;
}

void TrafficSimDeclParser::EnumTypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumTypeDecl(this);
}

void TrafficSimDeclParser::EnumTypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumTypeDecl(this);
}

TrafficSimDeclParser::EnumTypeDeclContext* TrafficSimDeclParser::enumTypeDecl() {
  EnumTypeDeclContext *_localctx = _tracker.createInstance<EnumTypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 102, TrafficSimDeclParser::RuleEnumTypeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(705);
    match(TrafficSimDeclParser::EnumID);
    setState(706);
    match(TrafficSimDeclParser::LPAREN);
    setState(707);
    contextID();
    setState(712);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TrafficSimDeclParser::COMMA) {
      setState(708);
      match(TrafficSimDeclParser::COMMA);
      setState(709);
      contextID();
      setState(714);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(715);
    match(TrafficSimDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::AttributeDeclContext::AttributeID() {
  return getToken(TrafficSimDeclParser::AttributeID, 0);
}

TrafficSimDeclParser::TypeDeclContext* TrafficSimDeclParser::AttributeDeclContext::typeDecl() {
  return getRuleContext<TrafficSimDeclParser::TypeDeclContext>(0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::AttributeDeclContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::AttributeDeclContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::AttributeDeclContext::ASSIGN() {
  return getToken(TrafficSimDeclParser::ASSIGN, 0);
}

TrafficSimDeclParser::LiteralValueContext* TrafficSimDeclParser::AttributeDeclContext::literalValue() {
  return getRuleContext<TrafficSimDeclParser::LiteralValueContext>(0);
}


size_t TrafficSimDeclParser::AttributeDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleAttributeDecl;
}

void TrafficSimDeclParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void TrafficSimDeclParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}

TrafficSimDeclParser::AttributeDeclContext* TrafficSimDeclParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 104, TrafficSimDeclParser::RuleAttributeDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    match(TrafficSimDeclParser::AttributeID);
    setState(718);
    typeDecl();
    setState(719);
    contextID();
    setState(722);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TrafficSimDeclParser::ASSIGN) {
      setState(720);
      match(TrafficSimDeclParser::ASSIGN);
      setState(721);
      literalValue();
    }
    setState(724);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

TrafficSimDeclParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::LiteralValueContext::INT() {
  return getToken(TrafficSimDeclParser::INT, 0);
}

tree::TerminalNode* TrafficSimDeclParser::LiteralValueContext::REAL() {
  return getToken(TrafficSimDeclParser::REAL, 0);
}

tree::TerminalNode* TrafficSimDeclParser::LiteralValueContext::STRING() {
  return getToken(TrafficSimDeclParser::STRING, 0);
}

tree::TerminalNode* TrafficSimDeclParser::LiteralValueContext::TrueID() {
  return getToken(TrafficSimDeclParser::TrueID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::LiteralValueContext::FalseID() {
  return getToken(TrafficSimDeclParser::FalseID, 0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::LiteralValueContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}


size_t TrafficSimDeclParser::LiteralValueContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleLiteralValue;
}

void TrafficSimDeclParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void TrafficSimDeclParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

TrafficSimDeclParser::LiteralValueContext* TrafficSimDeclParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 106, TrafficSimDeclParser::RuleLiteralValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(732);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(726);
        match(TrafficSimDeclParser::INT);
        break;
      }

      case TrafficSimDeclParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(727);
        match(TrafficSimDeclParser::REAL);
        break;
      }

      case TrafficSimDeclParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(728);
        match(TrafficSimDeclParser::STRING);
        break;
      }

      case TrafficSimDeclParser::TrueID: {
        enterOuterAlt(_localctx, 4);
        setState(729);
        match(TrafficSimDeclParser::TrueID);
        break;
      }

      case TrafficSimDeclParser::FalseID: {
        enterOuterAlt(_localctx, 5);
        setState(730);
        match(TrafficSimDeclParser::FalseID);
        break;
      }

      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(731);
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

TrafficSimDeclParser::SignalParamNameContext::SignalParamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::TriggerDeclContext* TrafficSimDeclParser::SignalParamNameContext::triggerDecl() {
  return getRuleContext<TrafficSimDeclParser::TriggerDeclContext>(0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::SignalParamNameContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}


size_t TrafficSimDeclParser::SignalParamNameContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSignalParamName;
}

void TrafficSimDeclParser::SignalParamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalParamName(this);
}

void TrafficSimDeclParser::SignalParamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalParamName(this);
}

TrafficSimDeclParser::SignalParamNameContext* TrafficSimDeclParser::signalParamName() {
  SignalParamNameContext *_localctx = _tracker.createInstance<SignalParamNameContext>(_ctx, getState());
  enterRule(_localctx, 108, TrafficSimDeclParser::RuleSignalParamName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(734);
    triggerDecl();
    setState(735);
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

TrafficSimDeclParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::AttributeNameContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}

TrafficSimDeclParser::ThisDeclContext* TrafficSimDeclParser::AttributeNameContext::thisDecl() {
  return getRuleContext<TrafficSimDeclParser::ThisDeclContext>(0);
}


size_t TrafficSimDeclParser::AttributeNameContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleAttributeName;
}

void TrafficSimDeclParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void TrafficSimDeclParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}

TrafficSimDeclParser::AttributeNameContext* TrafficSimDeclParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 110, TrafficSimDeclParser::RuleAttributeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(739);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::ThisID: {
        setState(737);
        thisDecl();
        break;
      }

      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::ID: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(741);
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

TrafficSimDeclParser::ToPortNameContext::ToPortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ToPortNameContext::ToID() {
  return getToken(TrafficSimDeclParser::ToID, 0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::ToPortNameContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}


size_t TrafficSimDeclParser::ToPortNameContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleToPortName;
}

void TrafficSimDeclParser::ToPortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToPortName(this);
}

void TrafficSimDeclParser::ToPortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToPortName(this);
}

TrafficSimDeclParser::ToPortNameContext* TrafficSimDeclParser::toPortName() {
  ToPortNameContext *_localctx = _tracker.createInstance<ToPortNameContext>(_ctx, getState());
  enterRule(_localctx, 112, TrafficSimDeclParser::RuleToPortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(743);
    match(TrafficSimDeclParser::ToID);
    setState(744);
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

TrafficSimDeclParser::AttributeAssignStatementContext::AttributeAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::AttributeNameContext* TrafficSimDeclParser::AttributeAssignStatementContext::attributeName() {
  return getRuleContext<TrafficSimDeclParser::AttributeNameContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::AttributeAssignStatementContext::ASSIGN() {
  return getToken(TrafficSimDeclParser::ASSIGN, 0);
}

TrafficSimDeclParser::ExpressionContext* TrafficSimDeclParser::AttributeAssignStatementContext::expression() {
  return getRuleContext<TrafficSimDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::AttributeAssignStatementContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}


size_t TrafficSimDeclParser::AttributeAssignStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleAttributeAssignStatement;
}

void TrafficSimDeclParser::AttributeAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignStatement(this);
}

void TrafficSimDeclParser::AttributeAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignStatement(this);
}

TrafficSimDeclParser::AttributeAssignStatementContext* TrafficSimDeclParser::attributeAssignStatement() {
  AttributeAssignStatementContext *_localctx = _tracker.createInstance<AttributeAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, TrafficSimDeclParser::RuleAttributeAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(746);
    attributeName();
    setState(747);
    match(TrafficSimDeclParser::ASSIGN);
    setState(748);
    expression();
    setState(749);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalAssignStatementContext ------------------------------------------------------------------

TrafficSimDeclParser::LocalAssignStatementContext::LocalAssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::TypeDeclContext* TrafficSimDeclParser::LocalAssignStatementContext::typeDecl() {
  return getRuleContext<TrafficSimDeclParser::TypeDeclContext>(0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::LocalAssignStatementContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::LocalAssignStatementContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::LocalAssignStatementContext::ASSIGN() {
  return getToken(TrafficSimDeclParser::ASSIGN, 0);
}

TrafficSimDeclParser::ExpressionContext* TrafficSimDeclParser::LocalAssignStatementContext::expression() {
  return getRuleContext<TrafficSimDeclParser::ExpressionContext>(0);
}


size_t TrafficSimDeclParser::LocalAssignStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleLocalAssignStatement;
}

void TrafficSimDeclParser::LocalAssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalAssignStatement(this);
}

void TrafficSimDeclParser::LocalAssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalAssignStatement(this);
}

TrafficSimDeclParser::LocalAssignStatementContext* TrafficSimDeclParser::localAssignStatement() {
  LocalAssignStatementContext *_localctx = _tracker.createInstance<LocalAssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 116, TrafficSimDeclParser::RuleLocalAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(751);
    typeDecl();
    setState(752);
    contextID();
    setState(756);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::ASSIGN: {
        setState(753);
        match(TrafficSimDeclParser::ASSIGN);
        setState(754);
        expression();
        break;
      }

      case TrafficSimDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(758);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendToStatementContext ------------------------------------------------------------------

TrafficSimDeclParser::SendToStatementContext::SendToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::SendToStatementContext::SendID() {
  return getToken(TrafficSimDeclParser::SendID, 0);
}

TrafficSimDeclParser::SignalSendContext* TrafficSimDeclParser::SendToStatementContext::signalSend() {
  return getRuleContext<TrafficSimDeclParser::SignalSendContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SendToStatementContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

TrafficSimDeclParser::ToPortNameContext* TrafficSimDeclParser::SendToStatementContext::toPortName() {
  return getRuleContext<TrafficSimDeclParser::ToPortNameContext>(0);
}


size_t TrafficSimDeclParser::SendToStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSendToStatement;
}

void TrafficSimDeclParser::SendToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendToStatement(this);
}

void TrafficSimDeclParser::SendToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendToStatement(this);
}

TrafficSimDeclParser::SendToStatementContext* TrafficSimDeclParser::sendToStatement() {
  SendToStatementContext *_localctx = _tracker.createInstance<SendToStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, TrafficSimDeclParser::RuleSendToStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(760);
    match(TrafficSimDeclParser::SendID);
    setState(761);
    signalSend();
    setState(764);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::ToID: {
        setState(762);
        toPortName();
        break;
      }

      case TrafficSimDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(766);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleAssignmentContext ------------------------------------------------------------------

TrafficSimDeclParser::SingleAssignmentContext::SingleAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::AttributeAssignStatementContext* TrafficSimDeclParser::SingleAssignmentContext::attributeAssignStatement() {
  return getRuleContext<TrafficSimDeclParser::AttributeAssignStatementContext>(0);
}

TrafficSimDeclParser::SendToStatementContext* TrafficSimDeclParser::SingleAssignmentContext::sendToStatement() {
  return getRuleContext<TrafficSimDeclParser::SendToStatementContext>(0);
}


size_t TrafficSimDeclParser::SingleAssignmentContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSingleAssignment;
}

void TrafficSimDeclParser::SingleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleAssignment(this);
}

void TrafficSimDeclParser::SingleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleAssignment(this);
}

TrafficSimDeclParser::SingleAssignmentContext* TrafficSimDeclParser::singleAssignment() {
  SingleAssignmentContext *_localctx = _tracker.createInstance<SingleAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 120, TrafficSimDeclParser::RuleSingleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(770);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::ThisID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(768);
        attributeAssignStatement();
        break;
      }

      case TrafficSimDeclParser::SendID: {
        enterOuterAlt(_localctx, 2);
        setState(769);
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

TrafficSimDeclParser::MultiAssignmentContext::MultiAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::MultiAssignmentContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

tree::TerminalNode* TrafficSimDeclParser::MultiAssignmentContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}

std::vector<TrafficSimDeclParser::SingleAssignmentContext *> TrafficSimDeclParser::MultiAssignmentContext::singleAssignment() {
  return getRuleContexts<TrafficSimDeclParser::SingleAssignmentContext>();
}

TrafficSimDeclParser::SingleAssignmentContext* TrafficSimDeclParser::MultiAssignmentContext::singleAssignment(size_t i) {
  return getRuleContext<TrafficSimDeclParser::SingleAssignmentContext>(i);
}


size_t TrafficSimDeclParser::MultiAssignmentContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleMultiAssignment;
}

void TrafficSimDeclParser::MultiAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiAssignment(this);
}

void TrafficSimDeclParser::MultiAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiAssignment(this);
}

TrafficSimDeclParser::MultiAssignmentContext* TrafficSimDeclParser::multiAssignment() {
  MultiAssignmentContext *_localctx = _tracker.createInstance<MultiAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 122, TrafficSimDeclParser::RuleMultiAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(772);
    match(TrafficSimDeclParser::LBRACE);
    setState(776);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 44) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 44)) & ((1ULL << (TrafficSimDeclParser::NameID - 44))
      | (1ULL << (TrafficSimDeclParser::LabelID - 44))
      | (1ULL << (TrafficSimDeclParser::EnabledID - 44))
      | (1ULL << (TrafficSimDeclParser::TypeID - 44))
      | (1ULL << (TrafficSimDeclParser::ThisID - 44))
      | (1ULL << (TrafficSimDeclParser::AttributeID - 44))
      | (1ULL << (TrafficSimDeclParser::SignalID - 44))
      | (1ULL << (TrafficSimDeclParser::PortID - 44))
      | (1ULL << (TrafficSimDeclParser::ImportID - 44))
      | (1ULL << (TrafficSimDeclParser::FromID - 44))
      | (1ULL << (TrafficSimDeclParser::ToID - 44))
      | (1ULL << (TrafficSimDeclParser::SendID - 44))
      | (1ULL << (TrafficSimDeclParser::AsID - 44))
      | (1ULL << (TrafficSimDeclParser::ID - 44)))) != 0)) {
      setState(773);
      singleAssignment();
      setState(778);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(779);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignalDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::SignalDeclContext::SignalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::SignalDeclContext::SignalID() {
  return getToken(TrafficSimDeclParser::SignalID, 0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::SignalDeclContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SignalDeclContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SignalDeclContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SignalDeclContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}

std::vector<TrafficSimDeclParser::ParamDeclContext *> TrafficSimDeclParser::SignalDeclContext::paramDecl() {
  return getRuleContexts<TrafficSimDeclParser::ParamDeclContext>();
}

TrafficSimDeclParser::ParamDeclContext* TrafficSimDeclParser::SignalDeclContext::paramDecl(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::SignalDeclContext::COMMA() {
  return getTokens(TrafficSimDeclParser::COMMA);
}

tree::TerminalNode* TrafficSimDeclParser::SignalDeclContext::COMMA(size_t i) {
  return getToken(TrafficSimDeclParser::COMMA, i);
}


size_t TrafficSimDeclParser::SignalDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSignalDecl;
}

void TrafficSimDeclParser::SignalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignalDecl(this);
}

void TrafficSimDeclParser::SignalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignalDecl(this);
}

TrafficSimDeclParser::SignalDeclContext* TrafficSimDeclParser::signalDecl() {
  SignalDeclContext *_localctx = _tracker.createInstance<SignalDeclContext>(_ctx, getState());
  enterRule(_localctx, 124, TrafficSimDeclParser::RuleSignalDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(781);
    match(TrafficSimDeclParser::SignalID);
    setState(782);
    contextID();
    setState(797);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::LPAREN: {
        setState(783);
        match(TrafficSimDeclParser::LPAREN);
        setState(793);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TrafficSimDeclParser::NameID:
          case TrafficSimDeclParser::LabelID:
          case TrafficSimDeclParser::EnabledID:
          case TrafficSimDeclParser::TypeID:
          case TrafficSimDeclParser::IntID:
          case TrafficSimDeclParser::RealID:
          case TrafficSimDeclParser::BoolID:
          case TrafficSimDeclParser::StringID:
          case TrafficSimDeclParser::EnumID:
          case TrafficSimDeclParser::AttributeID:
          case TrafficSimDeclParser::SignalID:
          case TrafficSimDeclParser::PortID:
          case TrafficSimDeclParser::ImportID:
          case TrafficSimDeclParser::FromID:
          case TrafficSimDeclParser::ToID:
          case TrafficSimDeclParser::AsID:
          case TrafficSimDeclParser::ID: {
            setState(784);
            paramDecl();
            setState(789);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TrafficSimDeclParser::COMMA) {
              setState(785);
              match(TrafficSimDeclParser::COMMA);
              setState(786);
              paramDecl();
              setState(791);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case TrafficSimDeclParser::RPAREN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(795);
        match(TrafficSimDeclParser::RPAREN);
        break;
      }

      case TrafficSimDeclParser::SEMI: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(799);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::ParamDeclContext::ParamDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::TypeDeclContext* TrafficSimDeclParser::ParamDeclContext::typeDecl() {
  return getRuleContext<TrafficSimDeclParser::TypeDeclContext>(0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::ParamDeclContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}


size_t TrafficSimDeclParser::ParamDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleParamDecl;
}

void TrafficSimDeclParser::ParamDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamDecl(this);
}

void TrafficSimDeclParser::ParamDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamDecl(this);
}

TrafficSimDeclParser::ParamDeclContext* TrafficSimDeclParser::paramDecl() {
  ParamDeclContext *_localctx = _tracker.createInstance<ParamDeclContext>(_ctx, getState());
  enterRule(_localctx, 126, TrafficSimDeclParser::RuleParamDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(801);
    typeDecl();
    setState(802);
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

TrafficSimDeclParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::FunctionDeclContext::FunctionID() {
  return getToken(TrafficSimDeclParser::FunctionID, 0);
}

TrafficSimDeclParser::TypeDeclContext* TrafficSimDeclParser::FunctionDeclContext::typeDecl() {
  return getRuleContext<TrafficSimDeclParser::TypeDeclContext>(0);
}

TrafficSimDeclParser::IdPathContext* TrafficSimDeclParser::FunctionDeclContext::idPath() {
  return getRuleContext<TrafficSimDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::FunctionDeclContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

tree::TerminalNode* TrafficSimDeclParser::FunctionDeclContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}

TrafficSimDeclParser::NestedStatementBodyContext* TrafficSimDeclParser::FunctionDeclContext::nestedStatementBody() {
  return getRuleContext<TrafficSimDeclParser::NestedStatementBodyContext>(0);
}

TrafficSimDeclParser::FunctionParametersContext* TrafficSimDeclParser::FunctionDeclContext::functionParameters() {
  return getRuleContext<TrafficSimDeclParser::FunctionParametersContext>(0);
}


size_t TrafficSimDeclParser::FunctionDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleFunctionDecl;
}

void TrafficSimDeclParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void TrafficSimDeclParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

TrafficSimDeclParser::FunctionDeclContext* TrafficSimDeclParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 128, TrafficSimDeclParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(804);
    match(TrafficSimDeclParser::FunctionID);
    setState(805);
    typeDecl();
    setState(806);
    idPath();
    setState(807);
    match(TrafficSimDeclParser::LPAREN);
    setState(810);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::IntID:
      case TrafficSimDeclParser::RealID:
      case TrafficSimDeclParser::BoolID:
      case TrafficSimDeclParser::StringID:
      case TrafficSimDeclParser::EnumID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::ID: {
        setState(808);
        functionParameters();
        break;
      }

      case TrafficSimDeclParser::RPAREN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(812);
    match(TrafficSimDeclParser::RPAREN);
    setState(813);
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

TrafficSimDeclParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TrafficSimDeclParser::ParamDeclContext *> TrafficSimDeclParser::FunctionParametersContext::paramDecl() {
  return getRuleContexts<TrafficSimDeclParser::ParamDeclContext>();
}

TrafficSimDeclParser::ParamDeclContext* TrafficSimDeclParser::FunctionParametersContext::paramDecl(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ParamDeclContext>(i);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::FunctionParametersContext::COMMA() {
  return getTokens(TrafficSimDeclParser::COMMA);
}

tree::TerminalNode* TrafficSimDeclParser::FunctionParametersContext::COMMA(size_t i) {
  return getToken(TrafficSimDeclParser::COMMA, i);
}


size_t TrafficSimDeclParser::FunctionParametersContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleFunctionParameters;
}

void TrafficSimDeclParser::FunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameters(this);
}

void TrafficSimDeclParser::FunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameters(this);
}

TrafficSimDeclParser::FunctionParametersContext* TrafficSimDeclParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 130, TrafficSimDeclParser::RuleFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(815);
    paramDecl();
    setState(820);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TrafficSimDeclParser::COMMA) {
      setState(816);
      match(TrafficSimDeclParser::COMMA);
      setState(817);
      paramDecl();
      setState(822);
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

TrafficSimDeclParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::IdPathContext* TrafficSimDeclParser::FunctionCallContext::idPath() {
  return getRuleContext<TrafficSimDeclParser::IdPathContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::FunctionCallContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

TrafficSimDeclParser::FunctionCallBodyContext* TrafficSimDeclParser::FunctionCallContext::functionCallBody() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallBodyContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::FunctionCallContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}


size_t TrafficSimDeclParser::FunctionCallContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleFunctionCall;
}

void TrafficSimDeclParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void TrafficSimDeclParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

TrafficSimDeclParser::FunctionCallContext* TrafficSimDeclParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 132, TrafficSimDeclParser::RuleFunctionCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(823);
    idPath();
    setState(824);
    match(TrafficSimDeclParser::LPAREN);
    setState(825);
    functionCallBody();
    setState(826);
    match(TrafficSimDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::FunctionCallBodyContext::FunctionCallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::FunctionCallBodyOptionalContext* TrafficSimDeclParser::FunctionCallBodyContext::functionCallBodyOptional() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallBodyOptionalContext>(0);
}

TrafficSimDeclParser::LiteralValueContext* TrafficSimDeclParser::FunctionCallBodyContext::literalValue() {
  return getRuleContext<TrafficSimDeclParser::LiteralValueContext>(0);
}

TrafficSimDeclParser::SignalParamNameContext* TrafficSimDeclParser::FunctionCallBodyContext::signalParamName() {
  return getRuleContext<TrafficSimDeclParser::SignalParamNameContext>(0);
}

TrafficSimDeclParser::AttributeNameContext* TrafficSimDeclParser::FunctionCallBodyContext::attributeName() {
  return getRuleContext<TrafficSimDeclParser::AttributeNameContext>(0);
}

TrafficSimDeclParser::FunctionCallContext* TrafficSimDeclParser::FunctionCallBodyContext::functionCall() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallContext>(0);
}


size_t TrafficSimDeclParser::FunctionCallBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleFunctionCallBody;
}

void TrafficSimDeclParser::FunctionCallBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBody(this);
}

void TrafficSimDeclParser::FunctionCallBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBody(this);
}

TrafficSimDeclParser::FunctionCallBodyContext* TrafficSimDeclParser::functionCallBody() {
  FunctionCallBodyContext *_localctx = _tracker.createInstance<FunctionCallBodyContext>(_ctx, getState());
  enterRule(_localctx, 134, TrafficSimDeclParser::RuleFunctionCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(833);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      setState(828);
      literalValue();
      break;
    }

    case 2: {
      setState(829);
      signalParamName();
      break;
    }

    case 3: {
      setState(830);
      attributeName();
      break;
    }

    case 4: {
      setState(831);
      functionCall();
      break;
    }

    case 5: {
      break;
    }

    }
    setState(835);
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

TrafficSimDeclParser::FunctionCallBodyOptionalContext::FunctionCallBodyOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::FunctionCallBodyOptionalContext::COMMA() {
  return getToken(TrafficSimDeclParser::COMMA, 0);
}

TrafficSimDeclParser::FunctionCallBodyContext* TrafficSimDeclParser::FunctionCallBodyOptionalContext::functionCallBody() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallBodyContext>(0);
}


size_t TrafficSimDeclParser::FunctionCallBodyOptionalContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleFunctionCallBodyOptional;
}

void TrafficSimDeclParser::FunctionCallBodyOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallBodyOptional(this);
}

void TrafficSimDeclParser::FunctionCallBodyOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallBodyOptional(this);
}

TrafficSimDeclParser::FunctionCallBodyOptionalContext* TrafficSimDeclParser::functionCallBodyOptional() {
  FunctionCallBodyOptionalContext *_localctx = _tracker.createInstance<FunctionCallBodyOptionalContext>(_ctx, getState());
  enterRule(_localctx, 136, TrafficSimDeclParser::RuleFunctionCallBodyOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(840);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(837);
        match(TrafficSimDeclParser::COMMA);
        setState(838);
        functionCallBody();
        break;
      }

      case TrafficSimDeclParser::RPAREN: {
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

TrafficSimDeclParser::ContextIDContext::ContextIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::ID() {
  return getToken(TrafficSimDeclParser::ID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::LabelID() {
  return getToken(TrafficSimDeclParser::LabelID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::EnabledID() {
  return getToken(TrafficSimDeclParser::EnabledID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::TypeID() {
  return getToken(TrafficSimDeclParser::TypeID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::AttributeID() {
  return getToken(TrafficSimDeclParser::AttributeID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::SignalID() {
  return getToken(TrafficSimDeclParser::SignalID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::PortID() {
  return getToken(TrafficSimDeclParser::PortID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::ImportID() {
  return getToken(TrafficSimDeclParser::ImportID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::FromID() {
  return getToken(TrafficSimDeclParser::FromID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::ToID() {
  return getToken(TrafficSimDeclParser::ToID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ContextIDContext::AsID() {
  return getToken(TrafficSimDeclParser::AsID, 0);
}


size_t TrafficSimDeclParser::ContextIDContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleContextID;
}

void TrafficSimDeclParser::ContextIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContextID(this);
}

void TrafficSimDeclParser::ContextIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContextID(this);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::contextID() {
  ContextIDContext *_localctx = _tracker.createInstance<ContextIDContext>(_ctx, getState());
  enterRule(_localctx, 138, TrafficSimDeclParser::RuleContextID);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(842);
    _la = _input->LA(1);
    if (!(((((_la - 44) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 44)) & ((1ULL << (TrafficSimDeclParser::NameID - 44))
      | (1ULL << (TrafficSimDeclParser::LabelID - 44))
      | (1ULL << (TrafficSimDeclParser::EnabledID - 44))
      | (1ULL << (TrafficSimDeclParser::TypeID - 44))
      | (1ULL << (TrafficSimDeclParser::AttributeID - 44))
      | (1ULL << (TrafficSimDeclParser::SignalID - 44))
      | (1ULL << (TrafficSimDeclParser::PortID - 44))
      | (1ULL << (TrafficSimDeclParser::ImportID - 44))
      | (1ULL << (TrafficSimDeclParser::FromID - 44))
      | (1ULL << (TrafficSimDeclParser::ToID - 44))
      | (1ULL << (TrafficSimDeclParser::AsID - 44))
      | (1ULL << (TrafficSimDeclParser::ID - 44)))) != 0))) {
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

TrafficSimDeclParser::TriggerDeclContext::TriggerDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::TriggerDeclContext::DOT() {
  return getToken(TrafficSimDeclParser::DOT, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TriggerDeclContext::MessageTrigger() {
  return getToken(TrafficSimDeclParser::MessageTrigger, 0);
}

tree::TerminalNode* TrafficSimDeclParser::TriggerDeclContext::TriggerID() {
  return getToken(TrafficSimDeclParser::TriggerID, 0);
}


size_t TrafficSimDeclParser::TriggerDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleTriggerDecl;
}

void TrafficSimDeclParser::TriggerDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerDecl(this);
}

void TrafficSimDeclParser::TriggerDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerDecl(this);
}

TrafficSimDeclParser::TriggerDeclContext* TrafficSimDeclParser::triggerDecl() {
  TriggerDeclContext *_localctx = _tracker.createInstance<TriggerDeclContext>(_ctx, getState());
  enterRule(_localctx, 140, TrafficSimDeclParser::RuleTriggerDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(844);
    _la = _input->LA(1);
    if (!(_la == TrafficSimDeclParser::TriggerID

    || _la == TrafficSimDeclParser::MessageTrigger)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(845);
    match(TrafficSimDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThisDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::ThisDeclContext::ThisDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ThisDeclContext::ThisID() {
  return getToken(TrafficSimDeclParser::ThisID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ThisDeclContext::DOT() {
  return getToken(TrafficSimDeclParser::DOT, 0);
}


size_t TrafficSimDeclParser::ThisDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleThisDecl;
}

void TrafficSimDeclParser::ThisDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisDecl(this);
}

void TrafficSimDeclParser::ThisDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisDecl(this);
}

TrafficSimDeclParser::ThisDeclContext* TrafficSimDeclParser::thisDecl() {
  ThisDeclContext *_localctx = _tracker.createInstance<ThisDeclContext>(_ctx, getState());
  enterRule(_localctx, 142, TrafficSimDeclParser::RuleThisDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(847);
    match(TrafficSimDeclParser::ThisID);
    setState(848);
    match(TrafficSimDeclParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::PortDeclContext::PortDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::PortDeclContext::PortID() {
  return getToken(TrafficSimDeclParser::PortID, 0);
}

std::vector<TrafficSimDeclParser::ContextIDContext *> TrafficSimDeclParser::PortDeclContext::contextID() {
  return getRuleContexts<TrafficSimDeclParser::ContextIDContext>();
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::PortDeclContext::contextID(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(i);
}

tree::TerminalNode* TrafficSimDeclParser::PortDeclContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::PortDeclContext::COMMA() {
  return getTokens(TrafficSimDeclParser::COMMA);
}

tree::TerminalNode* TrafficSimDeclParser::PortDeclContext::COMMA(size_t i) {
  return getToken(TrafficSimDeclParser::COMMA, i);
}


size_t TrafficSimDeclParser::PortDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RulePortDecl;
}

void TrafficSimDeclParser::PortDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDecl(this);
}

void TrafficSimDeclParser::PortDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDecl(this);
}

TrafficSimDeclParser::PortDeclContext* TrafficSimDeclParser::portDecl() {
  PortDeclContext *_localctx = _tracker.createInstance<PortDeclContext>(_ctx, getState());
  enterRule(_localctx, 144, TrafficSimDeclParser::RulePortDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(850);
    match(TrafficSimDeclParser::PortID);
    setState(851);
    contextID();
    setState(856);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TrafficSimDeclParser::COMMA) {
      setState(852);
      match(TrafficSimDeclParser::COMMA);
      setState(853);
      contextID();
      setState(858);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(859);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclContext ------------------------------------------------------------------

TrafficSimDeclParser::NameDeclContext::NameDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::NameDeclContext::NameID() {
  return getToken(TrafficSimDeclParser::NameID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::NameDeclContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::NameDeclContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::NameDeclContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}


size_t TrafficSimDeclParser::NameDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleNameDecl;
}

void TrafficSimDeclParser::NameDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNameDecl(this);
}

void TrafficSimDeclParser::NameDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNameDecl(this);
}

TrafficSimDeclParser::NameDeclContext* TrafficSimDeclParser::nameDecl() {
  NameDeclContext *_localctx = _tracker.createInstance<NameDeclContext>(_ctx, getState());
  enterRule(_localctx, 146, TrafficSimDeclParser::RuleNameDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(861);
    match(TrafficSimDeclParser::NameID);
    setState(862);
    match(TrafficSimDeclParser::COLON);
    setState(863);
    contextID();
    setState(864);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdPathContext ------------------------------------------------------------------

TrafficSimDeclParser::IdPathContext::IdPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TrafficSimDeclParser::ContextIDContext *> TrafficSimDeclParser::IdPathContext::contextID() {
  return getRuleContexts<TrafficSimDeclParser::ContextIDContext>();
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::IdPathContext::contextID(size_t i) {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(i);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::IdPathContext::DOT() {
  return getTokens(TrafficSimDeclParser::DOT);
}

tree::TerminalNode* TrafficSimDeclParser::IdPathContext::DOT(size_t i) {
  return getToken(TrafficSimDeclParser::DOT, i);
}


size_t TrafficSimDeclParser::IdPathContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleIdPath;
}

void TrafficSimDeclParser::IdPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdPath(this);
}

void TrafficSimDeclParser::IdPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdPath(this);
}

TrafficSimDeclParser::IdPathContext* TrafficSimDeclParser::idPath() {
  IdPathContext *_localctx = _tracker.createInstance<IdPathContext>(_ctx, getState());
  enterRule(_localctx, 148, TrafficSimDeclParser::RuleIdPath);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(866);
    contextID();
    setState(871);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TrafficSimDeclParser::DOT) {
      setState(867);
      match(TrafficSimDeclParser::DOT);
      setState(868);
      contextID();
      setState(873);
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

TrafficSimDeclParser::StatementDeclContext::StatementDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::StatementBodyContext* TrafficSimDeclParser::StatementDeclContext::statementBody() {
  return getRuleContext<TrafficSimDeclParser::StatementBodyContext>(0);
}

TrafficSimDeclParser::NestedStatementBodyContext* TrafficSimDeclParser::StatementDeclContext::nestedStatementBody() {
  return getRuleContext<TrafficSimDeclParser::NestedStatementBodyContext>(0);
}


size_t TrafficSimDeclParser::StatementDeclContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStatementDecl;
}

void TrafficSimDeclParser::StatementDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDecl(this);
}

void TrafficSimDeclParser::StatementDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDecl(this);
}

TrafficSimDeclParser::StatementDeclContext* TrafficSimDeclParser::statementDecl() {
  StatementDeclContext *_localctx = _tracker.createInstance<StatementDeclContext>(_ctx, getState());
  enterRule(_localctx, 150, TrafficSimDeclParser::RuleStatementDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(876);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::IntID:
      case TrafficSimDeclParser::RealID:
      case TrafficSimDeclParser::BoolID:
      case TrafficSimDeclParser::StringID:
      case TrafficSimDeclParser::ThisID:
      case TrafficSimDeclParser::ReturnID:
      case TrafficSimDeclParser::EnumID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::SendID:
      case TrafficSimDeclParser::SwitchID:
      case TrafficSimDeclParser::IfID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::BREAK:
      case TrafficSimDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(874);
        statementBody();
        break;
      }

      case TrafficSimDeclParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(875);
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

TrafficSimDeclParser::StatementBodyContext::StatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::FunctionCallStatementContext* TrafficSimDeclParser::StatementBodyContext::functionCallStatement() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallStatementContext>(0);
}

TrafficSimDeclParser::AttributeAssignStatementContext* TrafficSimDeclParser::StatementBodyContext::attributeAssignStatement() {
  return getRuleContext<TrafficSimDeclParser::AttributeAssignStatementContext>(0);
}

TrafficSimDeclParser::SwitchStatementContext* TrafficSimDeclParser::StatementBodyContext::switchStatement() {
  return getRuleContext<TrafficSimDeclParser::SwitchStatementContext>(0);
}

TrafficSimDeclParser::ConditionalStatementContext* TrafficSimDeclParser::StatementBodyContext::conditionalStatement() {
  return getRuleContext<TrafficSimDeclParser::ConditionalStatementContext>(0);
}

TrafficSimDeclParser::LocalAssignStatementContext* TrafficSimDeclParser::StatementBodyContext::localAssignStatement() {
  return getRuleContext<TrafficSimDeclParser::LocalAssignStatementContext>(0);
}

TrafficSimDeclParser::SendToStatementContext* TrafficSimDeclParser::StatementBodyContext::sendToStatement() {
  return getRuleContext<TrafficSimDeclParser::SendToStatementContext>(0);
}

TrafficSimDeclParser::BreakStatementContext* TrafficSimDeclParser::StatementBodyContext::breakStatement() {
  return getRuleContext<TrafficSimDeclParser::BreakStatementContext>(0);
}

TrafficSimDeclParser::ReturnStatementContext* TrafficSimDeclParser::StatementBodyContext::returnStatement() {
  return getRuleContext<TrafficSimDeclParser::ReturnStatementContext>(0);
}


size_t TrafficSimDeclParser::StatementBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleStatementBody;
}

void TrafficSimDeclParser::StatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBody(this);
}

void TrafficSimDeclParser::StatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBody(this);
}

TrafficSimDeclParser::StatementBodyContext* TrafficSimDeclParser::statementBody() {
  StatementBodyContext *_localctx = _tracker.createInstance<StatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 152, TrafficSimDeclParser::RuleStatementBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(886);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(878);
      functionCallStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(879);
      attributeAssignStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(880);
      switchStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(881);
      conditionalStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(882);
      localAssignStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(883);
      sendToStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(884);
      breakStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(885);
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

TrafficSimDeclParser::FunctionCallStatementContext::FunctionCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::FunctionCallContext* TrafficSimDeclParser::FunctionCallStatementContext::functionCall() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::FunctionCallStatementContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}


size_t TrafficSimDeclParser::FunctionCallStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleFunctionCallStatement;
}

void TrafficSimDeclParser::FunctionCallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallStatement(this);
}

void TrafficSimDeclParser::FunctionCallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallStatement(this);
}

TrafficSimDeclParser::FunctionCallStatementContext* TrafficSimDeclParser::functionCallStatement() {
  FunctionCallStatementContext *_localctx = _tracker.createInstance<FunctionCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, TrafficSimDeclParser::RuleFunctionCallStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(888);
    functionCall();
    setState(889);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedStatementBodyContext ------------------------------------------------------------------

TrafficSimDeclParser::NestedStatementBodyContext::NestedStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::NestedStatementBodyContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

tree::TerminalNode* TrafficSimDeclParser::NestedStatementBodyContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}

std::vector<TrafficSimDeclParser::StatementBodyContext *> TrafficSimDeclParser::NestedStatementBodyContext::statementBody() {
  return getRuleContexts<TrafficSimDeclParser::StatementBodyContext>();
}

TrafficSimDeclParser::StatementBodyContext* TrafficSimDeclParser::NestedStatementBodyContext::statementBody(size_t i) {
  return getRuleContext<TrafficSimDeclParser::StatementBodyContext>(i);
}


size_t TrafficSimDeclParser::NestedStatementBodyContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleNestedStatementBody;
}

void TrafficSimDeclParser::NestedStatementBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedStatementBody(this);
}

void TrafficSimDeclParser::NestedStatementBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedStatementBody(this);
}

TrafficSimDeclParser::NestedStatementBodyContext* TrafficSimDeclParser::nestedStatementBody() {
  NestedStatementBodyContext *_localctx = _tracker.createInstance<NestedStatementBodyContext>(_ctx, getState());
  enterRule(_localctx, 156, TrafficSimDeclParser::RuleNestedStatementBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(891);
    match(TrafficSimDeclParser::LBRACE);
    setState(895);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 44) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 44)) & ((1ULL << (TrafficSimDeclParser::NameID - 44))
      | (1ULL << (TrafficSimDeclParser::LabelID - 44))
      | (1ULL << (TrafficSimDeclParser::EnabledID - 44))
      | (1ULL << (TrafficSimDeclParser::TypeID - 44))
      | (1ULL << (TrafficSimDeclParser::IntID - 44))
      | (1ULL << (TrafficSimDeclParser::RealID - 44))
      | (1ULL << (TrafficSimDeclParser::BoolID - 44))
      | (1ULL << (TrafficSimDeclParser::StringID - 44))
      | (1ULL << (TrafficSimDeclParser::ThisID - 44))
      | (1ULL << (TrafficSimDeclParser::ReturnID - 44))
      | (1ULL << (TrafficSimDeclParser::EnumID - 44))
      | (1ULL << (TrafficSimDeclParser::AttributeID - 44))
      | (1ULL << (TrafficSimDeclParser::SignalID - 44))
      | (1ULL << (TrafficSimDeclParser::PortID - 44))
      | (1ULL << (TrafficSimDeclParser::ImportID - 44))
      | (1ULL << (TrafficSimDeclParser::FromID - 44))
      | (1ULL << (TrafficSimDeclParser::ToID - 44))
      | (1ULL << (TrafficSimDeclParser::SendID - 44))
      | (1ULL << (TrafficSimDeclParser::SwitchID - 44))
      | (1ULL << (TrafficSimDeclParser::IfID - 44))
      | (1ULL << (TrafficSimDeclParser::AsID - 44))
      | (1ULL << (TrafficSimDeclParser::BREAK - 44))
      | (1ULL << (TrafficSimDeclParser::ID - 44)))) != 0)) {
      setState(892);
      statementBody();
      setState(897);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(898);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

TrafficSimDeclParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ReturnStatementContext::ReturnID() {
  return getToken(TrafficSimDeclParser::ReturnID, 0);
}

TrafficSimDeclParser::OperationContext* TrafficSimDeclParser::ReturnStatementContext::operation() {
  return getRuleContext<TrafficSimDeclParser::OperationContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::ReturnStatementContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}


size_t TrafficSimDeclParser::ReturnStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleReturnStatement;
}

void TrafficSimDeclParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void TrafficSimDeclParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

TrafficSimDeclParser::ReturnStatementContext* TrafficSimDeclParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 158, TrafficSimDeclParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(900);
    match(TrafficSimDeclParser::ReturnID);
    setState(901);
    operation();
    setState(902);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

TrafficSimDeclParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::BreakStatementContext::BREAK() {
  return getToken(TrafficSimDeclParser::BREAK, 0);
}

tree::TerminalNode* TrafficSimDeclParser::BreakStatementContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}


size_t TrafficSimDeclParser::BreakStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleBreakStatement;
}

void TrafficSimDeclParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void TrafficSimDeclParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}

TrafficSimDeclParser::BreakStatementContext* TrafficSimDeclParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 160, TrafficSimDeclParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(904);
    match(TrafficSimDeclParser::BREAK);
    setState(905);
    match(TrafficSimDeclParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

TrafficSimDeclParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::AtomContext* TrafficSimDeclParser::OperationContext::atom() {
  return getRuleContext<TrafficSimDeclParser::AtomContext>(0);
}

TrafficSimDeclParser::OperationOptionalContext* TrafficSimDeclParser::OperationContext::operationOptional() {
  return getRuleContext<TrafficSimDeclParser::OperationOptionalContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

TrafficSimDeclParser::OperationContext* TrafficSimDeclParser::OperationContext::operation() {
  return getRuleContext<TrafficSimDeclParser::OperationContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationContext::MINUS() {
  return getToken(TrafficSimDeclParser::MINUS, 0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationContext::NotIdSymbol() {
  return getToken(TrafficSimDeclParser::NotIdSymbol, 0);
}


size_t TrafficSimDeclParser::OperationContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleOperation;
}

void TrafficSimDeclParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void TrafficSimDeclParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}

TrafficSimDeclParser::OperationContext* TrafficSimDeclParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 162, TrafficSimDeclParser::RuleOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(918);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::TriggerID:
      case TrafficSimDeclParser::MessageTrigger:
      case TrafficSimDeclParser::ThisID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::TrueID:
      case TrafficSimDeclParser::FalseID:
      case TrafficSimDeclParser::INT:
      case TrafficSimDeclParser::REAL:
      case TrafficSimDeclParser::STRING:
      case TrafficSimDeclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(907);
        atom();
        setState(908);
        operationOptional();
        break;
      }

      case TrafficSimDeclParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(910);
        match(TrafficSimDeclParser::LPAREN);
        setState(911);
        operation();
        setState(912);
        match(TrafficSimDeclParser::RPAREN);
        break;
      }

      case TrafficSimDeclParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(914);
        match(TrafficSimDeclParser::MINUS);
        setState(915);
        operation();
        break;
      }

      case TrafficSimDeclParser::NotIdSymbol: {
        enterOuterAlt(_localctx, 4);
        setState(916);
        match(TrafficSimDeclParser::NotIdSymbol);
        setState(917);
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

TrafficSimDeclParser::OperationOptionalContext::OperationOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::OperationContext* TrafficSimDeclParser::OperationOptionalContext::operation() {
  return getRuleContext<TrafficSimDeclParser::OperationContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationOptionalContext::MULT() {
  return getToken(TrafficSimDeclParser::MULT, 0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationOptionalContext::DIV() {
  return getToken(TrafficSimDeclParser::DIV, 0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationOptionalContext::PLUS() {
  return getToken(TrafficSimDeclParser::PLUS, 0);
}

tree::TerminalNode* TrafficSimDeclParser::OperationOptionalContext::MINUS() {
  return getToken(TrafficSimDeclParser::MINUS, 0);
}


size_t TrafficSimDeclParser::OperationOptionalContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleOperationOptional;
}

void TrafficSimDeclParser::OperationOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOptional(this);
}

void TrafficSimDeclParser::OperationOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOptional(this);
}

TrafficSimDeclParser::OperationOptionalContext* TrafficSimDeclParser::operationOptional() {
  OperationOptionalContext *_localctx = _tracker.createInstance<OperationOptionalContext>(_ctx, getState());
  enterRule(_localctx, 164, TrafficSimDeclParser::RuleOperationOptional);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(923);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::PLUS:
      case TrafficSimDeclParser::MINUS:
      case TrafficSimDeclParser::MULT:
      case TrafficSimDeclParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(920);
        dynamic_cast<OperationOptionalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 109) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 109)) & ((1ULL << (TrafficSimDeclParser::PLUS - 109))
          | (1ULL << (TrafficSimDeclParser::MINUS - 109))
          | (1ULL << (TrafficSimDeclParser::MULT - 109))
          | (1ULL << (TrafficSimDeclParser::DIV - 109)))) != 0))) {
          dynamic_cast<OperationOptionalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(921);
        operation();
        break;
      }

      case TrafficSimDeclParser::NotIdSymbol:
      case TrafficSimDeclParser::AndIdSymbol:
      case TrafficSimDeclParser::OrIdSymbol:
      case TrafficSimDeclParser::NotIdWord:
      case TrafficSimDeclParser::AndIdWord:
      case TrafficSimDeclParser::OrIdWord:
      case TrafficSimDeclParser::ASSIGN:
      case TrafficSimDeclParser::RPAREN:
      case TrafficSimDeclParser::LESSTHAN:
      case TrafficSimDeclParser::GREATERTHAN:
      case TrafficSimDeclParser::SEMI: {
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

TrafficSimDeclParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

TrafficSimDeclParser::ExpressionContext* TrafficSimDeclParser::ExpressionContext::expression() {
  return getRuleContext<TrafficSimDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}

TrafficSimDeclParser::ExpressionOptionalContext* TrafficSimDeclParser::ExpressionContext::expressionOptional() {
  return getRuleContext<TrafficSimDeclParser::ExpressionOptionalContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionContext::NotIdSymbol() {
  return getToken(TrafficSimDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionContext::NotIdWord() {
  return getToken(TrafficSimDeclParser::NotIdWord, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionContext::MINUS() {
  return getToken(TrafficSimDeclParser::MINUS, 0);
}

TrafficSimDeclParser::OperationContext* TrafficSimDeclParser::ExpressionContext::operation() {
  return getRuleContext<TrafficSimDeclParser::OperationContext>(0);
}


size_t TrafficSimDeclParser::ExpressionContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleExpression;
}

void TrafficSimDeclParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void TrafficSimDeclParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

TrafficSimDeclParser::ExpressionContext* TrafficSimDeclParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 166, TrafficSimDeclParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(939);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(925);
      match(TrafficSimDeclParser::LPAREN);
      setState(926);
      expression();
      setState(927);
      match(TrafficSimDeclParser::RPAREN);
      setState(928);
      expressionOptional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(930);
      match(TrafficSimDeclParser::NotIdSymbol);
      setState(931);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(932);
      match(TrafficSimDeclParser::NotIdWord);
      setState(933);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(934);
      match(TrafficSimDeclParser::MINUS);
      setState(935);
      expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(936);
      operation();
      setState(937);
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

TrafficSimDeclParser::ExpressionOptionalContext::ExpressionOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::ExpressionContext* TrafficSimDeclParser::ExpressionOptionalContext::expression() {
  return getRuleContext<TrafficSimDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::OrIdSymbol() {
  return getToken(TrafficSimDeclParser::OrIdSymbol, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::OrIdWord() {
  return getToken(TrafficSimDeclParser::OrIdWord, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::AndIdSymbol() {
  return getToken(TrafficSimDeclParser::AndIdSymbol, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::AndIdWord() {
  return getToken(TrafficSimDeclParser::AndIdWord, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::NotIdWord() {
  return getToken(TrafficSimDeclParser::NotIdWord, 0);
}

std::vector<tree::TerminalNode *> TrafficSimDeclParser::ExpressionOptionalContext::ASSIGN() {
  return getTokens(TrafficSimDeclParser::ASSIGN);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::ASSIGN(size_t i) {
  return getToken(TrafficSimDeclParser::ASSIGN, i);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::NotIdSymbol() {
  return getToken(TrafficSimDeclParser::NotIdSymbol, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::LESSTHAN() {
  return getToken(TrafficSimDeclParser::LESSTHAN, 0);
}

tree::TerminalNode* TrafficSimDeclParser::ExpressionOptionalContext::GREATERTHAN() {
  return getToken(TrafficSimDeclParser::GREATERTHAN, 0);
}


size_t TrafficSimDeclParser::ExpressionOptionalContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleExpressionOptional;
}

void TrafficSimDeclParser::ExpressionOptionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionOptional(this);
}

void TrafficSimDeclParser::ExpressionOptionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionOptional(this);
}

TrafficSimDeclParser::ExpressionOptionalContext* TrafficSimDeclParser::expressionOptional() {
  ExpressionOptionalContext *_localctx = _tracker.createInstance<ExpressionOptionalContext>(_ctx, getState());
  enterRule(_localctx, 168, TrafficSimDeclParser::RuleExpressionOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(964);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NotIdSymbol:
      case TrafficSimDeclParser::AndIdSymbol:
      case TrafficSimDeclParser::OrIdSymbol:
      case TrafficSimDeclParser::NotIdWord:
      case TrafficSimDeclParser::AndIdWord:
      case TrafficSimDeclParser::OrIdWord:
      case TrafficSimDeclParser::ASSIGN:
      case TrafficSimDeclParser::LESSTHAN:
      case TrafficSimDeclParser::GREATERTHAN: {
        enterOuterAlt(_localctx, 1);
        setState(960);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TrafficSimDeclParser::OrIdSymbol: {
            setState(941);
            match(TrafficSimDeclParser::OrIdSymbol);
            break;
          }

          case TrafficSimDeclParser::OrIdWord: {
            setState(942);
            match(TrafficSimDeclParser::OrIdWord);
            break;
          }

          case TrafficSimDeclParser::AndIdSymbol: {
            setState(943);
            match(TrafficSimDeclParser::AndIdSymbol);
            break;
          }

          case TrafficSimDeclParser::AndIdWord: {
            setState(944);
            match(TrafficSimDeclParser::AndIdWord);
            break;
          }

          case TrafficSimDeclParser::ASSIGN: {
            setState(945);
            match(TrafficSimDeclParser::ASSIGN);
            setState(946);
            match(TrafficSimDeclParser::ASSIGN);
            break;
          }

          case TrafficSimDeclParser::NotIdSymbol: {
            setState(947);
            match(TrafficSimDeclParser::NotIdSymbol);
            setState(948);
            match(TrafficSimDeclParser::ASSIGN);
            break;
          }

          case TrafficSimDeclParser::NotIdWord: {
            setState(949);
            match(TrafficSimDeclParser::NotIdWord);
            break;
          }

          case TrafficSimDeclParser::LESSTHAN: {
            setState(950);
            match(TrafficSimDeclParser::LESSTHAN);
            setState(953);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TrafficSimDeclParser::ASSIGN: {
                setState(951);
                match(TrafficSimDeclParser::ASSIGN);
                break;
              }

              case TrafficSimDeclParser::NameID:
              case TrafficSimDeclParser::LabelID:
              case TrafficSimDeclParser::EnabledID:
              case TrafficSimDeclParser::TypeID:
              case TrafficSimDeclParser::TriggerID:
              case TrafficSimDeclParser::MessageTrigger:
              case TrafficSimDeclParser::ThisID:
              case TrafficSimDeclParser::AttributeID:
              case TrafficSimDeclParser::SignalID:
              case TrafficSimDeclParser::PortID:
              case TrafficSimDeclParser::ImportID:
              case TrafficSimDeclParser::FromID:
              case TrafficSimDeclParser::ToID:
              case TrafficSimDeclParser::AsID:
              case TrafficSimDeclParser::NotIdSymbol:
              case TrafficSimDeclParser::NotIdWord:
              case TrafficSimDeclParser::TrueID:
              case TrafficSimDeclParser::FalseID:
              case TrafficSimDeclParser::INT:
              case TrafficSimDeclParser::REAL:
              case TrafficSimDeclParser::STRING:
              case TrafficSimDeclParser::ID:
              case TrafficSimDeclParser::LPAREN:
              case TrafficSimDeclParser::MINUS: {
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case TrafficSimDeclParser::GREATERTHAN: {
            setState(955);
            match(TrafficSimDeclParser::GREATERTHAN);
            setState(958);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case TrafficSimDeclParser::ASSIGN: {
                setState(956);
                match(TrafficSimDeclParser::ASSIGN);
                break;
              }

              case TrafficSimDeclParser::NameID:
              case TrafficSimDeclParser::LabelID:
              case TrafficSimDeclParser::EnabledID:
              case TrafficSimDeclParser::TypeID:
              case TrafficSimDeclParser::TriggerID:
              case TrafficSimDeclParser::MessageTrigger:
              case TrafficSimDeclParser::ThisID:
              case TrafficSimDeclParser::AttributeID:
              case TrafficSimDeclParser::SignalID:
              case TrafficSimDeclParser::PortID:
              case TrafficSimDeclParser::ImportID:
              case TrafficSimDeclParser::FromID:
              case TrafficSimDeclParser::ToID:
              case TrafficSimDeclParser::AsID:
              case TrafficSimDeclParser::NotIdSymbol:
              case TrafficSimDeclParser::NotIdWord:
              case TrafficSimDeclParser::TrueID:
              case TrafficSimDeclParser::FalseID:
              case TrafficSimDeclParser::INT:
              case TrafficSimDeclParser::REAL:
              case TrafficSimDeclParser::STRING:
              case TrafficSimDeclParser::ID:
              case TrafficSimDeclParser::LPAREN:
              case TrafficSimDeclParser::MINUS: {
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
        setState(962);
        expression();
        break;
      }

      case TrafficSimDeclParser::RPAREN:
      case TrafficSimDeclParser::SEMI: {
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

TrafficSimDeclParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::IfStatementContext* TrafficSimDeclParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<TrafficSimDeclParser::IfStatementContext>(0);
}

TrafficSimDeclParser::ElseStatementContext* TrafficSimDeclParser::ConditionalStatementContext::elseStatement() {
  return getRuleContext<TrafficSimDeclParser::ElseStatementContext>(0);
}


size_t TrafficSimDeclParser::ConditionalStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleConditionalStatement;
}

void TrafficSimDeclParser::ConditionalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalStatement(this);
}

void TrafficSimDeclParser::ConditionalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalStatement(this);
}

TrafficSimDeclParser::ConditionalStatementContext* TrafficSimDeclParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 170, TrafficSimDeclParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(966);
    ifStatement();
    setState(969);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      setState(967);
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

TrafficSimDeclParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::IfStatementContext::IfID() {
  return getToken(TrafficSimDeclParser::IfID, 0);
}

TrafficSimDeclParser::IfEuTContext* TrafficSimDeclParser::IfStatementContext::ifEuT() {
  return getRuleContext<TrafficSimDeclParser::IfEuTContext>(0);
}

TrafficSimDeclParser::StatementDeclContext* TrafficSimDeclParser::IfStatementContext::statementDecl() {
  return getRuleContext<TrafficSimDeclParser::StatementDeclContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::IfStatementContext::SEMI() {
  return getToken(TrafficSimDeclParser::SEMI, 0);
}


size_t TrafficSimDeclParser::IfStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleIfStatement;
}

void TrafficSimDeclParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void TrafficSimDeclParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

TrafficSimDeclParser::IfStatementContext* TrafficSimDeclParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 172, TrafficSimDeclParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(971);
    match(TrafficSimDeclParser::IfID);
    setState(972);
    ifEuT();
    setState(975);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::IntID:
      case TrafficSimDeclParser::RealID:
      case TrafficSimDeclParser::BoolID:
      case TrafficSimDeclParser::StringID:
      case TrafficSimDeclParser::ThisID:
      case TrafficSimDeclParser::ReturnID:
      case TrafficSimDeclParser::EnumID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::SendID:
      case TrafficSimDeclParser::SwitchID:
      case TrafficSimDeclParser::IfID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::BREAK:
      case TrafficSimDeclParser::ID:
      case TrafficSimDeclParser::LBRACE: {
        setState(973);
        statementDecl();
        break;
      }

      case TrafficSimDeclParser::SEMI: {
        setState(974);
        match(TrafficSimDeclParser::SEMI);
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

TrafficSimDeclParser::IfEuTContext::IfEuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::IfEuTContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

TrafficSimDeclParser::ExpressionContext* TrafficSimDeclParser::IfEuTContext::expression() {
  return getRuleContext<TrafficSimDeclParser::ExpressionContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::IfEuTContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}


size_t TrafficSimDeclParser::IfEuTContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleIfEuT;
}

void TrafficSimDeclParser::IfEuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfEuT(this);
}

void TrafficSimDeclParser::IfEuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfEuT(this);
}

TrafficSimDeclParser::IfEuTContext* TrafficSimDeclParser::ifEuT() {
  IfEuTContext *_localctx = _tracker.createInstance<IfEuTContext>(_ctx, getState());
  enterRule(_localctx, 174, TrafficSimDeclParser::RuleIfEuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(977);
    match(TrafficSimDeclParser::LPAREN);
    setState(978);
    expression();
    setState(979);
    match(TrafficSimDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

TrafficSimDeclParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::ElseStatementContext::ElseID() {
  return getToken(TrafficSimDeclParser::ElseID, 0);
}

TrafficSimDeclParser::StatementDeclContext* TrafficSimDeclParser::ElseStatementContext::statementDecl() {
  return getRuleContext<TrafficSimDeclParser::StatementDeclContext>(0);
}


size_t TrafficSimDeclParser::ElseStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleElseStatement;
}

void TrafficSimDeclParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void TrafficSimDeclParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

TrafficSimDeclParser::ElseStatementContext* TrafficSimDeclParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 176, TrafficSimDeclParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(981);
    match(TrafficSimDeclParser::ElseID);
    setState(982);
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

TrafficSimDeclParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::SwitchStatementContext::SwitchID() {
  return getToken(TrafficSimDeclParser::SwitchID, 0);
}

TrafficSimDeclParser::SwitchPuTContext* TrafficSimDeclParser::SwitchStatementContext::switchPuT() {
  return getRuleContext<TrafficSimDeclParser::SwitchPuTContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SwitchStatementContext::LBRACE() {
  return getToken(TrafficSimDeclParser::LBRACE, 0);
}

tree::TerminalNode* TrafficSimDeclParser::SwitchStatementContext::RBRACE() {
  return getToken(TrafficSimDeclParser::RBRACE, 0);
}

TrafficSimDeclParser::DefaultStatementContext* TrafficSimDeclParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<TrafficSimDeclParser::DefaultStatementContext>(0);
}

std::vector<TrafficSimDeclParser::CaseStatementContext *> TrafficSimDeclParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<TrafficSimDeclParser::CaseStatementContext>();
}

TrafficSimDeclParser::CaseStatementContext* TrafficSimDeclParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<TrafficSimDeclParser::CaseStatementContext>(i);
}


size_t TrafficSimDeclParser::SwitchStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSwitchStatement;
}

void TrafficSimDeclParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void TrafficSimDeclParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}

TrafficSimDeclParser::SwitchStatementContext* TrafficSimDeclParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 178, TrafficSimDeclParser::RuleSwitchStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(984);
    match(TrafficSimDeclParser::SwitchID);
    setState(985);
    switchPuT();
    setState(986);
    match(TrafficSimDeclParser::LBRACE);
    setState(990);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TrafficSimDeclParser::CaseID) {
      setState(987);
      caseStatement();
      setState(992);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(995);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::DefaultID: {
        setState(993);
        defaultStatement();
        break;
      }

      case TrafficSimDeclParser::RBRACE: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(997);
    match(TrafficSimDeclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchPuTContext ------------------------------------------------------------------

TrafficSimDeclParser::SwitchPuTContext::SwitchPuTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::SwitchPuTContext::LPAREN() {
  return getToken(TrafficSimDeclParser::LPAREN, 0);
}

TrafficSimDeclParser::ContextIDContext* TrafficSimDeclParser::SwitchPuTContext::contextID() {
  return getRuleContext<TrafficSimDeclParser::ContextIDContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::SwitchPuTContext::RPAREN() {
  return getToken(TrafficSimDeclParser::RPAREN, 0);
}


size_t TrafficSimDeclParser::SwitchPuTContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleSwitchPuT;
}

void TrafficSimDeclParser::SwitchPuTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchPuT(this);
}

void TrafficSimDeclParser::SwitchPuTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchPuT(this);
}

TrafficSimDeclParser::SwitchPuTContext* TrafficSimDeclParser::switchPuT() {
  SwitchPuTContext *_localctx = _tracker.createInstance<SwitchPuTContext>(_ctx, getState());
  enterRule(_localctx, 180, TrafficSimDeclParser::RuleSwitchPuT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(999);
    match(TrafficSimDeclParser::LPAREN);
    setState(1000);
    contextID();
    setState(1001);
    match(TrafficSimDeclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

TrafficSimDeclParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::CaseStatementContext::CaseID() {
  return getToken(TrafficSimDeclParser::CaseID, 0);
}

TrafficSimDeclParser::LiteralValueContext* TrafficSimDeclParser::CaseStatementContext::literalValue() {
  return getRuleContext<TrafficSimDeclParser::LiteralValueContext>(0);
}

tree::TerminalNode* TrafficSimDeclParser::CaseStatementContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

TrafficSimDeclParser::NestedStatementBodyContext* TrafficSimDeclParser::CaseStatementContext::nestedStatementBody() {
  return getRuleContext<TrafficSimDeclParser::NestedStatementBodyContext>(0);
}

std::vector<TrafficSimDeclParser::StatementBodyContext *> TrafficSimDeclParser::CaseStatementContext::statementBody() {
  return getRuleContexts<TrafficSimDeclParser::StatementBodyContext>();
}

TrafficSimDeclParser::StatementBodyContext* TrafficSimDeclParser::CaseStatementContext::statementBody(size_t i) {
  return getRuleContext<TrafficSimDeclParser::StatementBodyContext>(i);
}


size_t TrafficSimDeclParser::CaseStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleCaseStatement;
}

void TrafficSimDeclParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void TrafficSimDeclParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}

TrafficSimDeclParser::CaseStatementContext* TrafficSimDeclParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 182, TrafficSimDeclParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1003);
    match(TrafficSimDeclParser::CaseID);
    setState(1004);
    literalValue();
    setState(1005);
    match(TrafficSimDeclParser::COLON);
    setState(1013);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::LBRACE: {
        setState(1006);
        nestedStatementBody();
        break;
      }

      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::IntID:
      case TrafficSimDeclParser::RealID:
      case TrafficSimDeclParser::BoolID:
      case TrafficSimDeclParser::StringID:
      case TrafficSimDeclParser::ThisID:
      case TrafficSimDeclParser::ReturnID:
      case TrafficSimDeclParser::EnumID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::SendID:
      case TrafficSimDeclParser::SwitchID:
      case TrafficSimDeclParser::CaseID:
      case TrafficSimDeclParser::DefaultID:
      case TrafficSimDeclParser::IfID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::BREAK:
      case TrafficSimDeclParser::ID:
      case TrafficSimDeclParser::RBRACE: {
        setState(1010);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 44) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 44)) & ((1ULL << (TrafficSimDeclParser::NameID - 44))
          | (1ULL << (TrafficSimDeclParser::LabelID - 44))
          | (1ULL << (TrafficSimDeclParser::EnabledID - 44))
          | (1ULL << (TrafficSimDeclParser::TypeID - 44))
          | (1ULL << (TrafficSimDeclParser::IntID - 44))
          | (1ULL << (TrafficSimDeclParser::RealID - 44))
          | (1ULL << (TrafficSimDeclParser::BoolID - 44))
          | (1ULL << (TrafficSimDeclParser::StringID - 44))
          | (1ULL << (TrafficSimDeclParser::ThisID - 44))
          | (1ULL << (TrafficSimDeclParser::ReturnID - 44))
          | (1ULL << (TrafficSimDeclParser::EnumID - 44))
          | (1ULL << (TrafficSimDeclParser::AttributeID - 44))
          | (1ULL << (TrafficSimDeclParser::SignalID - 44))
          | (1ULL << (TrafficSimDeclParser::PortID - 44))
          | (1ULL << (TrafficSimDeclParser::ImportID - 44))
          | (1ULL << (TrafficSimDeclParser::FromID - 44))
          | (1ULL << (TrafficSimDeclParser::ToID - 44))
          | (1ULL << (TrafficSimDeclParser::SendID - 44))
          | (1ULL << (TrafficSimDeclParser::SwitchID - 44))
          | (1ULL << (TrafficSimDeclParser::IfID - 44))
          | (1ULL << (TrafficSimDeclParser::AsID - 44))
          | (1ULL << (TrafficSimDeclParser::BREAK - 44))
          | (1ULL << (TrafficSimDeclParser::ID - 44)))) != 0)) {
          setState(1007);
          statementBody();
          setState(1012);
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

TrafficSimDeclParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TrafficSimDeclParser::DefaultStatementContext::DefaultID() {
  return getToken(TrafficSimDeclParser::DefaultID, 0);
}

tree::TerminalNode* TrafficSimDeclParser::DefaultStatementContext::COLON() {
  return getToken(TrafficSimDeclParser::COLON, 0);
}

TrafficSimDeclParser::NestedStatementBodyContext* TrafficSimDeclParser::DefaultStatementContext::nestedStatementBody() {
  return getRuleContext<TrafficSimDeclParser::NestedStatementBodyContext>(0);
}

std::vector<TrafficSimDeclParser::StatementBodyContext *> TrafficSimDeclParser::DefaultStatementContext::statementBody() {
  return getRuleContexts<TrafficSimDeclParser::StatementBodyContext>();
}

TrafficSimDeclParser::StatementBodyContext* TrafficSimDeclParser::DefaultStatementContext::statementBody(size_t i) {
  return getRuleContext<TrafficSimDeclParser::StatementBodyContext>(i);
}


size_t TrafficSimDeclParser::DefaultStatementContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleDefaultStatement;
}

void TrafficSimDeclParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void TrafficSimDeclParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}

TrafficSimDeclParser::DefaultStatementContext* TrafficSimDeclParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 184, TrafficSimDeclParser::RuleDefaultStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1015);
    match(TrafficSimDeclParser::DefaultID);
    setState(1016);
    match(TrafficSimDeclParser::COLON);
    setState(1024);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TrafficSimDeclParser::LBRACE: {
        setState(1017);
        nestedStatementBody();
        break;
      }

      case TrafficSimDeclParser::NameID:
      case TrafficSimDeclParser::LabelID:
      case TrafficSimDeclParser::EnabledID:
      case TrafficSimDeclParser::TypeID:
      case TrafficSimDeclParser::IntID:
      case TrafficSimDeclParser::RealID:
      case TrafficSimDeclParser::BoolID:
      case TrafficSimDeclParser::StringID:
      case TrafficSimDeclParser::ThisID:
      case TrafficSimDeclParser::ReturnID:
      case TrafficSimDeclParser::EnumID:
      case TrafficSimDeclParser::AttributeID:
      case TrafficSimDeclParser::SignalID:
      case TrafficSimDeclParser::PortID:
      case TrafficSimDeclParser::ImportID:
      case TrafficSimDeclParser::FromID:
      case TrafficSimDeclParser::ToID:
      case TrafficSimDeclParser::SendID:
      case TrafficSimDeclParser::SwitchID:
      case TrafficSimDeclParser::IfID:
      case TrafficSimDeclParser::AsID:
      case TrafficSimDeclParser::BREAK:
      case TrafficSimDeclParser::ID:
      case TrafficSimDeclParser::RBRACE: {
        setState(1021);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 44) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 44)) & ((1ULL << (TrafficSimDeclParser::NameID - 44))
          | (1ULL << (TrafficSimDeclParser::LabelID - 44))
          | (1ULL << (TrafficSimDeclParser::EnabledID - 44))
          | (1ULL << (TrafficSimDeclParser::TypeID - 44))
          | (1ULL << (TrafficSimDeclParser::IntID - 44))
          | (1ULL << (TrafficSimDeclParser::RealID - 44))
          | (1ULL << (TrafficSimDeclParser::BoolID - 44))
          | (1ULL << (TrafficSimDeclParser::StringID - 44))
          | (1ULL << (TrafficSimDeclParser::ThisID - 44))
          | (1ULL << (TrafficSimDeclParser::ReturnID - 44))
          | (1ULL << (TrafficSimDeclParser::EnumID - 44))
          | (1ULL << (TrafficSimDeclParser::AttributeID - 44))
          | (1ULL << (TrafficSimDeclParser::SignalID - 44))
          | (1ULL << (TrafficSimDeclParser::PortID - 44))
          | (1ULL << (TrafficSimDeclParser::ImportID - 44))
          | (1ULL << (TrafficSimDeclParser::FromID - 44))
          | (1ULL << (TrafficSimDeclParser::ToID - 44))
          | (1ULL << (TrafficSimDeclParser::SendID - 44))
          | (1ULL << (TrafficSimDeclParser::SwitchID - 44))
          | (1ULL << (TrafficSimDeclParser::IfID - 44))
          | (1ULL << (TrafficSimDeclParser::AsID - 44))
          | (1ULL << (TrafficSimDeclParser::BREAK - 44))
          | (1ULL << (TrafficSimDeclParser::ID - 44)))) != 0)) {
          setState(1018);
          statementBody();
          setState(1023);
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

TrafficSimDeclParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TrafficSimDeclParser::SignalParamNameContext* TrafficSimDeclParser::AtomContext::signalParamName() {
  return getRuleContext<TrafficSimDeclParser::SignalParamNameContext>(0);
}

TrafficSimDeclParser::AttributeNameContext* TrafficSimDeclParser::AtomContext::attributeName() {
  return getRuleContext<TrafficSimDeclParser::AttributeNameContext>(0);
}

TrafficSimDeclParser::FunctionCallContext* TrafficSimDeclParser::AtomContext::functionCall() {
  return getRuleContext<TrafficSimDeclParser::FunctionCallContext>(0);
}

TrafficSimDeclParser::LiteralValueContext* TrafficSimDeclParser::AtomContext::literalValue() {
  return getRuleContext<TrafficSimDeclParser::LiteralValueContext>(0);
}


size_t TrafficSimDeclParser::AtomContext::getRuleIndex() const {
  return TrafficSimDeclParser::RuleAtom;
}

void TrafficSimDeclParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void TrafficSimDeclParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TrafficSimDeclListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

TrafficSimDeclParser::AtomContext* TrafficSimDeclParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 186, TrafficSimDeclParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1030);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1026);
      signalParamName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1027);
      attributeName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1028);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1029);
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
std::vector<dfa::DFA> TrafficSimDeclParser::_decisionToDFA;
atn::PredictionContextCache TrafficSimDeclParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TrafficSimDeclParser::_atn;
std::vector<uint16_t> TrafficSimDeclParser::_serializedATN;

std::vector<std::string> TrafficSimDeclParser::_ruleNames = {
  "start", "startArm", "end", "step", "stepBody", "intersection", "intersectionBody", 
  "trafficLights", "trafficLightsBody", "trafficSimulation", "trafficSimulationBodyP1", 
  "trafficSimulationBodyP2", "vehicleMovement", "vehicleMovementBody", "vehicleDistributionName", 
  "vehicleDistribution", "vehicleDistributionBody", "sensor", "sensorBody", 
  "lanes", "outerCon", "stringlist", "stringlistBody", "innerCon", "states", 
  "edge", "edgeBody", "phase", "phaseBody", "transitions", "transitionsBody", 
  "transition", "transitionBody", "phases", "phasesBody", "trafficLight", 
  "trafficLightBody", "object", "componentIdPath", "signalIdPath", "attributeIdPath", 
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

std::vector<std::string> TrafficSimDeclParser::_literalNames = {
  "", "'TrafficSimulation'", "'Sensor'", "'Intersection'", "'Step'", "'Arm'", 
  "'hasTrafficLight'", "'accident'", "'neighboringTrafficLights'", "'TrafficLight'", 
  "'turns'", "'lanes'", "'states'", "'innerConnections'", "'outerConnection'", 
  "'duration'", "'minDur'", "'maxDur'", "'factor'", "'measured'", "'Lane'", 
  "'message'", "'VehicleMovement'", "'Phase'", "'phases'", "'transitionPhases'", 
  "'Transition'", "'transitions'", "", "'vehiclePerHour'", "'vehicleDistribution'", 
  "'VehicleDistribution'", "", "'bicycle'", "'bus'", "'moped'", "'motorcycle'", 
  "'car'", "'emergency'", "'truck'", "'start'", "'startArm'", "'end'", "", 
  "'name'", "", "'enabled'", "'Type'", "'int'", "'real'", "'bool'", "'string'", 
  "", "'msg'", "'this'", "'return'", "'SignalTransition'", "'TimeoutTransition'", 
  "'enum'", "'Declaration'", "'description'", "'Attribute'", "'Signal'", 
  "'Port'", "'import'", "'from'", "'to'", "'send'", "'Function'", "'switch'", 
  "'case'", "'default'", "'if'", "'else'", "'as'", "'@'", "'!'", "'&&'", 
  "'||'", "'not'", "'and'", "'or'", "'true'", "'false'", "'break'", "'='", 
  "'<->'", "'->'", "'<-'", "'..'", "", "", "", "", "", "", "'('", "')'", 
  "'{'", "'}'", "'['", "']'", "'<'", "'>'", "':'", "';'", "','", "'_'", 
  "'.'", "'+'", "'-'", "'*'", "'/'", "'|'", "'&'", "'const'"
};

std::vector<std::string> TrafficSimDeclParser::_symbolicNames = {
  "", "TRAFFICSIMULATION", "Sensor", "Intersection", "Step", "Arm", "HasTrafficLight", 
  "Accident", "NeighboringTrafficLights", "TrafficLight", "Turns", "Lanes", 
  "States", "InnerConnections", "OuterConnection", "Duration", "MinDur", 
  "MaxDur", "Factor", "Measured", "Lane", "Message", "VehicleMovement", 
  "Phase", "Phases", "TransitionPhases", "Transition", "Transitions", "Trigger", 
  "VehiclePerHour", "VehicleDistribution", "LVehicleDistribution", "Label", 
  "Bicycle", "Bus", "Moped", "Motorcycle", "Car", "Emergency", "Truck", 
  "Start", "StartArm", "End", "IGNORE_NEWLINE", "NameID", "LabelID", "EnabledID", 
  "TypeID", "IntID", "RealID", "BoolID", "StringID", "TriggerID", "MessageTrigger", 
  "ThisID", "ReturnID", "SignalTransitionID", "TimeoutTransitionID", "EnumID", 
  "DeclarationID", "DescriptionID", "AttributeID", "SignalID", "PortID", 
  "ImportID", "FromID", "ToID", "SendID", "FunctionID", "SwitchID", "CaseID", 
  "DefaultID", "IfID", "ElseID", "AsID", "AtID", "NotIdSymbol", "AndIdSymbol", 
  "OrIdSymbol", "NotIdWord", "AndIdWord", "OrIdWord", "TrueID", "FalseID", 
  "BREAK", "ASSIGN", "DoubleArrow", "RightArrow", "LeftArrow", "RANGE", 
  "INT", "REAL", "STRING", "ID", "LINE_COMMENT", "COMMENT", "LPAREN", "RPAREN", 
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LESSTHAN", "GREATERTHAN", 
  "COLON", "SEMI", "COMMA", "UNDER", "DOT", "PLUS", "MINUS", "MULT", "DIV", 
  "PIPE", "REF", "CONST", "NEWLINE", "WS"
};

dfa::Vocabulary TrafficSimDeclParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TrafficSimDeclParser::_tokenNames;

TrafficSimDeclParser::Initializer::Initializer() {
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
    0x3, 0x77, 0x40b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0xdd, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x107, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x10f, 0xa, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x118, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x124, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x12a, 0xa, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x13d, 0xa, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x172, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0x195, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1a4, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 
    0x18, 0x1ac, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1cf, 0xa, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x5, 0x1e, 0x1f3, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1fb, 0xa, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 
    0x20, 0x204, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x222, 
    0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x5, 0x23, 0x22a, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x233, 0xa, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x259, 0xa, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x25d, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x7, 0x28, 0x262, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x265, 
    0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x26a, 0xa, 0x29, 
    0xc, 0x29, 0xe, 0x29, 0x26d, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x7, 0x2a, 0x273, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x276, 
    0xb, 0x2a, 0x5, 0x2a, 0x278, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x282, 
    0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x285, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x28b, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x29e, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x5, 0x30, 0x2a3, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x5, 0x32, 0x2b0, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x2b9, 
    0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x34, 0x3, 0x34, 0x5, 0x34, 0x2c2, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x2c9, 0xa, 0x35, 0xc, 0x35, 
    0xe, 0x35, 0x2cc, 0xb, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x2d5, 0xa, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x5, 0x37, 0x2df, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x2e6, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x5, 0x3c, 0x2f7, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x2ff, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x305, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 
    0x7, 0x3f, 0x309, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x30c, 0xb, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x7, 0x40, 0x316, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 
    0x319, 0xb, 0x40, 0x3, 0x40, 0x5, 0x40, 0x31c, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x5, 0x40, 0x320, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x5, 0x42, 0x32d, 0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x335, 0xa, 0x43, 
    0xc, 0x43, 0xe, 0x43, 0x338, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
    0x45, 0x5, 0x45, 0x344, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x34b, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x359, 0xa, 0x4a, 
    0xc, 0x4a, 0xe, 0x4a, 0x35c, 0xb, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
    0x4c, 0x7, 0x4c, 0x368, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x36b, 0xb, 
    0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x36f, 0xa, 0x4d, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4e, 0x5, 0x4e, 0x379, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x50, 0x3, 0x50, 0x7, 0x50, 0x380, 0xa, 0x50, 0xc, 0x50, 0xe, 0x50, 
    0x383, 0xb, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 
    0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 
    0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x399, 0xa, 0x53, 0x3, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x5, 0x54, 0x39e, 0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x3ae, 
    0xa, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 
    0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 
    0x5, 0x56, 0x3bc, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 
    0x3c1, 0xa, 0x56, 0x5, 0x56, 0x3c3, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 
    0x5, 0x56, 0x3c7, 0xa, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 
    0x3cc, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 
    0x3d2, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 
    0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x7, 
    0x5b, 0x3df, 0xa, 0x5b, 0xc, 0x5b, 0xe, 0x5b, 0x3e2, 0xb, 0x5b, 0x3, 
    0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x3e6, 0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
    0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 
    0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x7, 0x5d, 0x3f3, 0xa, 0x5d, 0xc, 0x5d, 
    0xe, 0x5d, 0x3f6, 0xb, 0x5d, 0x5, 0x5d, 0x3f8, 0xa, 0x5d, 0x3, 0x5e, 
    0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x3fe, 0xa, 0x5e, 0xc, 0x5e, 
    0xe, 0x5e, 0x401, 0xb, 0x5e, 0x5, 0x5e, 0x403, 0xa, 0x5e, 0x3, 0x5f, 
    0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x409, 0xa, 0x5f, 0x3, 0x5f, 
    0x2, 0x2, 0x60, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
    0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
    0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 
    0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 
    0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 
    0x2, 0x6, 0x3, 0x2, 0x54, 0x55, 0x6, 0x2, 0x2e, 0x31, 0x3f, 0x44, 0x4c, 
    0x4c, 0x5f, 0x5f, 0x3, 0x2, 0x36, 0x37, 0x3, 0x2, 0x6f, 0x72, 0x2, 0x438, 
    0x2, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x4, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x6, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xa, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x10, 0x108, 0x3, 0x2, 0x2, 0x2, 0x12, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x119, 0x3, 0x2, 0x2, 0x2, 0x16, 0x123, 0x3, 0x2, 0x2, 0x2, 0x18, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x1e, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x171, 0x3, 0x2, 0x2, 0x2, 0x24, 0x173, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x194, 0x3, 0x2, 0x2, 0x2, 0x28, 0x196, 0x3, 0x2, 0x2, 
    0x2, 0x2a, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x19e, 0x3, 0x2, 0x2, 0x2, 
    0x2e, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1ce, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1f2, 0x3, 
    0x2, 0x2, 0x2, 0x3c, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x203, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x205, 0x3, 0x2, 0x2, 0x2, 0x42, 0x221, 0x3, 0x2, 0x2, 
    0x2, 0x44, 0x223, 0x3, 0x2, 0x2, 0x2, 0x46, 0x232, 0x3, 0x2, 0x2, 0x2, 
    0x48, 0x234, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x258, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x25c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x266, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x277, 0x3, 0x2, 0x2, 0x2, 0x54, 0x279, 0x3, 
    0x2, 0x2, 0x2, 0x56, 0x283, 0x3, 0x2, 0x2, 0x2, 0x58, 0x28a, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x29d, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x60, 0x2a4, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x66, 
    0x2ba, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x2cf, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x2e0, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x72, 0x2e9, 0x3, 0x2, 
    0x2, 0x2, 0x74, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x76, 0x2f1, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x304, 0x3, 0x2, 0x2, 0x2, 
    0x7c, 0x306, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x323, 0x3, 0x2, 0x2, 0x2, 0x82, 0x326, 0x3, 0x2, 0x2, 0x2, 0x84, 0x331, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x339, 0x3, 0x2, 0x2, 0x2, 0x88, 0x343, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x34c, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x351, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x354, 0x3, 0x2, 0x2, 0x2, 0x94, 0x35f, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x364, 0x3, 0x2, 0x2, 0x2, 0x98, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x9a, 
    0x378, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x37d, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0x386, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x38a, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0x398, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x39d, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x3c6, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0xae, 0x3cd, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0x3da, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x3ed, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x408, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x2a, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x6a, 
    0x2, 0x2, 0xc0, 0xc1, 0x7, 0x5c, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x6b, 0x2, 
    0x2, 0xc2, 0x3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x2b, 0x2, 0x2, 
    0xc4, 0xc5, 0x7, 0x6a, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x5e, 0x2, 0x2, 0xc6, 
    0xc7, 0x7, 0x6b, 0x2, 0x2, 0xc7, 0x5, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 
    0x7, 0x2c, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x6a, 0x2, 0x2, 0xca, 0xcb, 0x7, 
    0x5c, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x6b, 0x2, 0x2, 0xcc, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xce, 0x7, 0x6, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x64, 0x2, 
    0x2, 0xcf, 0xd0, 0x5, 0xa, 0x6, 0x2, 0xd0, 0xd1, 0x7, 0x65, 0x2, 0x2, 
    0xd1, 0x9, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x5, 0x2, 0x2, 0x2, 0xd3, 
    0xd4, 0x5, 0xa, 0x6, 0x2, 0xd4, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 
    0x5, 0x1a, 0xe, 0x2, 0xd6, 0xd7, 0x5, 0xa, 0x6, 0x2, 0xd7, 0xdd, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x6, 0x4, 0x2, 0xd9, 0xda, 0x5, 0xa, 
    0x6, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdc, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x5, 0x2, 0x2, 0xdf, 0xe0, 
    0x7, 0x64, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0xe, 0x8, 0x2, 0xe1, 0xe2, 0x7, 
    0x65, 0x2, 0x2, 0xe2, 0xd, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x34, 
    0x1b, 0x2, 0xe4, 0xe5, 0x5, 0xe, 0x8, 0x2, 0xe5, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe7, 0x5, 0x24, 0x13, 0x2, 0xe7, 0xe8, 0x5, 0xe, 0x8, 0x2, 
    0xe8, 0x107, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x4c, 0x27, 0x2, 0xea, 
    0xeb, 0x5, 0xe, 0x8, 0x2, 0xeb, 0x107, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 
    0x7, 0x2e, 0x2, 0x2, 0xed, 0xee, 0x7, 0x6a, 0x2, 0x2, 0xee, 0xef, 0x7, 
    0x5f, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x6b, 0x2, 0x2, 0xf0, 0x107, 0x5, 0xe, 
    0x8, 0x2, 0xf1, 0xf2, 0x7, 0x22, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0x6a, 0x2, 
    0x2, 0xf3, 0xf4, 0x7, 0x5e, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x6b, 0x2, 0x2, 
    0xf5, 0x107, 0x5, 0xe, 0x8, 0x2, 0xf6, 0xf7, 0x7, 0x8, 0x2, 0x2, 0xf7, 
    0xf8, 0x7, 0x6a, 0x2, 0x2, 0xf8, 0xf9, 0x9, 0x2, 0x2, 0x2, 0xf9, 0xfa, 
    0x7, 0x6b, 0x2, 0x2, 0xfa, 0x107, 0x5, 0xe, 0x8, 0x2, 0xfb, 0xfc, 0x7, 
    0x9, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x6a, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x5d, 
    0x2, 0x2, 0xfe, 0xff, 0x7, 0x6b, 0x2, 0x2, 0xff, 0x107, 0x5, 0xe, 0x8, 
    0x2, 0x100, 0x101, 0x7, 0xa, 0x2, 0x2, 0x101, 0x102, 0x5, 0x10, 0x9, 
    0x2, 0x102, 0x103, 0x7, 0x6b, 0x2, 0x2, 0x103, 0x104, 0x5, 0xe, 0x8, 
    0x2, 0x104, 0x107, 0x3, 0x2, 0x2, 0x2, 0x105, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x106, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0x106, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x106, 0xec, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0x106, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x106, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x100, 0x3, 0x2, 0x2, 0x2, 0x106, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0xf, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x7, 
    0x6a, 0x2, 0x2, 0x109, 0x10e, 0x7, 0x66, 0x2, 0x2, 0x10a, 0x10b, 0x5, 
    0x48, 0x25, 0x2, 0x10b, 0x10c, 0x5, 0x12, 0xa, 0x2, 0x10c, 0x10f, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10a, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x111, 0x7, 0x67, 0x2, 0x2, 0x111, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x6c, 0x2, 0x2, 0x113, 0x114, 0x5, 
    0x48, 0x25, 0x2, 0x114, 0x115, 0x5, 0x12, 0xa, 0x2, 0x115, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x116, 0x118, 0x3, 0x2, 0x2, 0x2, 0x117, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x11a, 0x7, 0x3, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x64, 
    0x2, 0x2, 0x11b, 0x11c, 0x5, 0x16, 0xc, 0x2, 0x11c, 0x11d, 0x5, 0x18, 
    0xd, 0x2, 0x11d, 0x11e, 0x7, 0x65, 0x2, 0x2, 0x11e, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x11f, 0x120, 0x5, 0xc, 0x7, 0x2, 0x120, 0x121, 0x5, 0x16, 
    0xc, 0x2, 0x121, 0x124, 0x3, 0x2, 0x2, 0x2, 0x122, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x123, 0x122, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x17, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x5, 0x8, 0x5, 
    0x2, 0x126, 0x127, 0x5, 0x18, 0xd, 0x2, 0x127, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x128, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x129, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x12c, 0x7, 0x18, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x64, 0x2, 0x2, 
    0x12d, 0x12e, 0x5, 0x1c, 0xf, 0x2, 0x12e, 0x12f, 0x7, 0x65, 0x2, 0x2, 
    0x12f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x5, 0x4, 0x3, 0x2, 0x131, 
    0x132, 0x5, 0x1c, 0xf, 0x2, 0x132, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x134, 0x7, 0x1f, 0x2, 0x2, 0x134, 0x135, 0x7, 0x6a, 0x2, 0x2, 0x135, 
    0x136, 0x7, 0x5d, 0x2, 0x2, 0x136, 0x137, 0x7, 0x6b, 0x2, 0x2, 0x137, 
    0x13d, 0x5, 0x1c, 0xf, 0x2, 0x138, 0x139, 0x5, 0x1e, 0x10, 0x2, 0x139, 
    0x13a, 0x5, 0x1c, 0xf, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 
    0x13d, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x130, 0x3, 0x2, 0x2, 0x2, 0x13c, 
    0x133, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13c, 
    0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 
    0x7, 0x20, 0x2, 0x2, 0x13f, 0x140, 0x7, 0x6a, 0x2, 0x2, 0x140, 0x141, 
    0x7, 0x5e, 0x2, 0x2, 0x141, 0x142, 0x7, 0x6b, 0x2, 0x2, 0x142, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x21, 0x2, 0x2, 0x144, 0x145, 
    0x7, 0x64, 0x2, 0x2, 0x145, 0x146, 0x5, 0x22, 0x12, 0x2, 0x146, 0x147, 
    0x7, 0x65, 0x2, 0x2, 0x147, 0x21, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 
    0x7, 0x2e, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x6a, 0x2, 0x2, 0x14a, 0x14b, 
    0x7, 0x5f, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x6b, 0x2, 0x2, 0x14c, 0x172, 
    0x5, 0x22, 0x12, 0x2, 0x14d, 0x14e, 0x7, 0x23, 0x2, 0x2, 0x14e, 0x14f, 
    0x7, 0x6a, 0x2, 0x2, 0x14f, 0x150, 0x7, 0x5d, 0x2, 0x2, 0x150, 0x151, 
    0x7, 0x6b, 0x2, 0x2, 0x151, 0x172, 0x5, 0x22, 0x12, 0x2, 0x152, 0x153, 
    0x7, 0x24, 0x2, 0x2, 0x153, 0x154, 0x7, 0x6a, 0x2, 0x2, 0x154, 0x155, 
    0x7, 0x5d, 0x2, 0x2, 0x155, 0x156, 0x7, 0x6b, 0x2, 0x2, 0x156, 0x172, 
    0x5, 0x22, 0x12, 0x2, 0x157, 0x158, 0x7, 0x25, 0x2, 0x2, 0x158, 0x159, 
    0x7, 0x6a, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x5d, 0x2, 0x2, 0x15a, 0x15b, 
    0x7, 0x6b, 0x2, 0x2, 0x15b, 0x172, 0x5, 0x22, 0x12, 0x2, 0x15c, 0x15d, 
    0x7, 0x26, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x6a, 0x2, 0x2, 0x15e, 0x15f, 
    0x7, 0x5d, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x6b, 0x2, 0x2, 0x160, 0x172, 
    0x5, 0x22, 0x12, 0x2, 0x161, 0x162, 0x7, 0x27, 0x2, 0x2, 0x162, 0x163, 
    0x7, 0x6a, 0x2, 0x2, 0x163, 0x164, 0x7, 0x5d, 0x2, 0x2, 0x164, 0x165, 
    0x7, 0x6b, 0x2, 0x2, 0x165, 0x172, 0x5, 0x22, 0x12, 0x2, 0x166, 0x167, 
    0x7, 0x28, 0x2, 0x2, 0x167, 0x168, 0x7, 0x6a, 0x2, 0x2, 0x168, 0x169, 
    0x7, 0x5d, 0x2, 0x2, 0x169, 0x16a, 0x7, 0x6b, 0x2, 0x2, 0x16a, 0x172, 
    0x5, 0x22, 0x12, 0x2, 0x16b, 0x16c, 0x7, 0x29, 0x2, 0x2, 0x16c, 0x16d, 
    0x7, 0x6a, 0x2, 0x2, 0x16d, 0x16e, 0x7, 0x5d, 0x2, 0x2, 0x16e, 0x16f, 
    0x7, 0x6b, 0x2, 0x2, 0x16f, 0x172, 0x5, 0x22, 0x12, 0x2, 0x170, 0x172, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x148, 0x3, 0x2, 0x2, 0x2, 0x171, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x152, 0x3, 0x2, 0x2, 0x2, 0x171, 0x157, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x171, 0x161, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x166, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16b, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x173, 0x174, 0x7, 0x4, 0x2, 0x2, 0x174, 0x175, 0x7, 
    0x64, 0x2, 0x2, 0x175, 0x176, 0x5, 0x26, 0x14, 0x2, 0x176, 0x177, 0x7, 
    0x65, 0x2, 0x2, 0x177, 0x25, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x7, 
    0x2e, 0x2, 0x2, 0x179, 0x17a, 0x7, 0x6a, 0x2, 0x2, 0x17a, 0x17b, 0x7, 
    0x5f, 0x2, 0x2, 0x17b, 0x17c, 0x7, 0x6b, 0x2, 0x2, 0x17c, 0x195, 0x5, 
    0x26, 0x14, 0x2, 0x17d, 0x17e, 0x7, 0x31, 0x2, 0x2, 0x17e, 0x17f, 0x7, 
    0x6a, 0x2, 0x2, 0x17f, 0x180, 0x7, 0x5e, 0x2, 0x2, 0x180, 0x181, 0x7, 
    0x6b, 0x2, 0x2, 0x181, 0x195, 0x5, 0x26, 0x14, 0x2, 0x182, 0x183, 0x7, 
    0x15, 0x2, 0x2, 0x183, 0x184, 0x7, 0x7, 0x2, 0x2, 0x184, 0x185, 0x7, 
    0x6a, 0x2, 0x2, 0x185, 0x186, 0x7, 0x5e, 0x2, 0x2, 0x186, 0x187, 0x7, 
    0x6b, 0x2, 0x2, 0x187, 0x195, 0x5, 0x26, 0x14, 0x2, 0x188, 0x189, 0x7, 
    0x15, 0x2, 0x2, 0x189, 0x18a, 0x7, 0x16, 0x2, 0x2, 0x18a, 0x18b, 0x7, 
    0x6a, 0x2, 0x2, 0x18b, 0x18c, 0x7, 0x5e, 0x2, 0x2, 0x18c, 0x18d, 0x7, 
    0x6b, 0x2, 0x2, 0x18d, 0x195, 0x5, 0x26, 0x14, 0x2, 0x18e, 0x18f, 0x7, 
    0x17, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x6a, 0x2, 0x2, 0x190, 0x191, 0x7, 
    0x5e, 0x2, 0x2, 0x191, 0x192, 0x7, 0x6b, 0x2, 0x2, 0x192, 0x195, 0x5, 
    0x26, 0x14, 0x2, 0x193, 0x195, 0x3, 0x2, 0x2, 0x2, 0x194, 0x178, 0x3, 
    0x2, 0x2, 0x2, 0x194, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x194, 0x182, 0x3, 
    0x2, 0x2, 0x2, 0x194, 0x188, 0x3, 0x2, 0x2, 0x2, 0x194, 0x18e, 0x3, 
    0x2, 0x2, 0x2, 0x194, 0x193, 0x3, 0x2, 0x2, 0x2, 0x195, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x197, 0x7, 0xd, 0x2, 0x2, 0x197, 0x198, 0x7, 0x6a, 
    0x2, 0x2, 0x198, 0x199, 0x7, 0x5e, 0x2, 0x2, 0x199, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x19a, 0x19b, 0x7, 0x10, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x6a, 
    0x2, 0x2, 0x19c, 0x19d, 0x7, 0x5e, 0x2, 0x2, 0x19d, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x19f, 0x7, 0x6a, 0x2, 0x2, 0x19f, 0x1a3, 0x7, 0x66, 
    0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0x5e, 0x2, 0x2, 0x1a1, 0x1a4, 0x5, 0x2e, 
    0x18, 0x2, 0x1a2, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a0, 0x3, 0x2, 
    0x2, 0x2, 0x1a3, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x3, 0x2, 
    0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x67, 0x2, 0x2, 0x1a6, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x6c, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x5e, 
    0x2, 0x2, 0x1a9, 0x1ac, 0x5, 0x2e, 0x18, 0x2, 0x1aa, 0x1ac, 0x3, 0x2, 
    0x2, 0x2, 0x1ab, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1aa, 0x3, 0x2, 
    0x2, 0x2, 0x1ac, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0xf, 0x2, 
    0x2, 0x1ae, 0x1af, 0x5, 0x2c, 0x17, 0x2, 0x1af, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x1b0, 0x1b1, 0x7, 0xe, 0x2, 0x2, 0x1b1, 0x1b2, 0x5, 0x2c, 0x17, 
    0x2, 0x1b2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x7, 0x7, 0x2, 0x2, 
    0x1b4, 0x1b5, 0x7, 0x64, 0x2, 0x2, 0x1b5, 0x1b6, 0x5, 0x36, 0x1c, 0x2, 
    0x1b6, 0x1b7, 0x7, 0x65, 0x2, 0x2, 0x1b7, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x1b8, 0x1b9, 0x7, 0x2e, 0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x6a, 0x2, 0x2, 
    0x1ba, 0x1bb, 0x7, 0x5f, 0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x6b, 0x2, 0x2, 
    0x1bc, 0x1cf, 0x5, 0x36, 0x1c, 0x2, 0x1bd, 0x1be, 0x5, 0x2a, 0x16, 0x2, 
    0x1be, 0x1bf, 0x7, 0x6b, 0x2, 0x2, 0x1bf, 0x1c0, 0x5, 0x36, 0x1c, 0x2, 
    0x1c0, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x5, 0x30, 0x19, 0x2, 
    0x1c2, 0x1c3, 0x7, 0x6b, 0x2, 0x2, 0x1c3, 0x1c4, 0x5, 0x36, 0x1c, 0x2, 
    0x1c4, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x5, 0x28, 0x15, 0x2, 
    0x1c6, 0x1c7, 0x7, 0x6b, 0x2, 0x2, 0x1c7, 0x1c8, 0x5, 0x36, 0x1c, 0x2, 
    0x1c8, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x5, 0x32, 0x1a, 0x2, 
    0x1ca, 0x1cb, 0x7, 0x6b, 0x2, 0x2, 0x1cb, 0x1cc, 0x5, 0x36, 0x1c, 0x2, 
    0x1cc, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cf, 0x3, 0x2, 0x2, 0x2, 
    0x1ce, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x1ce, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1c5, 0x3, 0x2, 0x2, 0x2, 
    0x1ce, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cd, 0x3, 0x2, 0x2, 0x2, 
    0x1cf, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x7, 0x19, 0x2, 0x2, 
    0x1d1, 0x1d2, 0x7, 0x64, 0x2, 0x2, 0x1d2, 0x1d3, 0x5, 0x3a, 0x1e, 0x2, 
    0x1d3, 0x1d4, 0x7, 0x65, 0x2, 0x2, 0x1d4, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x1d5, 0x1d6, 0x7, 0x11, 0x2, 0x2, 0x1d6, 0x1d7, 0x7, 0x6a, 0x2, 0x2, 
    0x1d7, 0x1d8, 0x7, 0x5c, 0x2, 0x2, 0x1d8, 0x1d9, 0x7, 0x6b, 0x2, 0x2, 
    0x1d9, 0x1f3, 0x5, 0x3a, 0x1e, 0x2, 0x1da, 0x1db, 0x7, 0x12, 0x2, 0x2, 
    0x1db, 0x1dc, 0x7, 0x6a, 0x2, 0x2, 0x1dc, 0x1dd, 0x7, 0x5c, 0x2, 0x2, 
    0x1dd, 0x1de, 0x7, 0x6b, 0x2, 0x2, 0x1de, 0x1f3, 0x5, 0x3a, 0x1e, 0x2, 
    0x1df, 0x1e0, 0x7, 0x13, 0x2, 0x2, 0x1e0, 0x1e1, 0x7, 0x6a, 0x2, 0x2, 
    0x1e1, 0x1e2, 0x7, 0x5c, 0x2, 0x2, 0x1e2, 0x1e3, 0x7, 0x6b, 0x2, 0x2, 
    0x1e3, 0x1f3, 0x5, 0x3a, 0x1e, 0x2, 0x1e4, 0x1e5, 0x7, 0x2e, 0x2, 0x2, 
    0x1e5, 0x1e6, 0x7, 0x6a, 0x2, 0x2, 0x1e6, 0x1e7, 0x7, 0x5e, 0x2, 0x2, 
    0x1e7, 0x1e8, 0x7, 0x6b, 0x2, 0x2, 0x1e8, 0x1f3, 0x5, 0x3a, 0x1e, 0x2, 
    0x1e9, 0x1ea, 0x5, 0x34, 0x1b, 0x2, 0x1ea, 0x1eb, 0x5, 0x3a, 0x1e, 0x2, 
    0x1eb, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0x14, 0x2, 0x2, 
    0x1ed, 0x1ee, 0x7, 0x6a, 0x2, 0x2, 0x1ee, 0x1ef, 0x7, 0x5d, 0x2, 0x2, 
    0x1ef, 0x1f0, 0x7, 0x6b, 0x2, 0x2, 0x1f0, 0x1f3, 0x5, 0x3a, 0x1e, 0x2, 
    0x1f1, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1df, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1e9, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1f3, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x7, 0x6a, 0x2, 0x2, 
    0x1f5, 0x1fa, 0x7, 0x66, 0x2, 0x2, 0x1f6, 0x1f7, 0x5, 0x40, 0x21, 0x2, 
    0x1f7, 0x1f8, 0x5, 0x3e, 0x20, 0x2, 0x1f8, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1f9, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1f6, 0x3, 0x2, 0x2, 0x2, 
    0x1fa, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 
    0x1fc, 0x1fd, 0x7, 0x67, 0x2, 0x2, 0x1fd, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x1fe, 0x1ff, 0x7, 0x6c, 0x2, 0x2, 0x1ff, 0x200, 0x5, 0x40, 0x21, 0x2, 
    0x200, 0x201, 0x5, 0x3e, 0x20, 0x2, 0x201, 0x204, 0x3, 0x2, 0x2, 0x2, 
    0x202, 0x204, 0x3, 0x2, 0x2, 0x2, 0x203, 0x1fe, 0x3, 0x2, 0x2, 0x2, 
    0x203, 0x202, 0x3, 0x2, 0x2, 0x2, 0x204, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x205, 
    0x206, 0x7, 0x1c, 0x2, 0x2, 0x206, 0x207, 0x7, 0x64, 0x2, 0x2, 0x207, 
    0x208, 0x5, 0x42, 0x22, 0x2, 0x208, 0x209, 0x7, 0x65, 0x2, 0x2, 0x209, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x7, 0x1b, 0x2, 0x2, 0x20b, 
    0x20c, 0x5, 0x44, 0x23, 0x2, 0x20c, 0x20d, 0x7, 0x6b, 0x2, 0x2, 0x20d, 
    0x20e, 0x5, 0x42, 0x22, 0x2, 0x20e, 0x222, 0x3, 0x2, 0x2, 0x2, 0x20f, 
    0x210, 0x7, 0x1e, 0x2, 0x2, 0x210, 0x211, 0x5, 0x2c, 0x17, 0x2, 0x211, 
    0x212, 0x7, 0x6b, 0x2, 0x2, 0x212, 0x213, 0x5, 0x42, 0x22, 0x2, 0x213, 
    0x222, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x7, 0x2a, 0x2, 0x2, 0x215, 
    0x216, 0x7, 0x19, 0x2, 0x2, 0x216, 0x217, 0x5, 0x38, 0x1d, 0x2, 0x217, 
    0x218, 0x7, 0x6b, 0x2, 0x2, 0x218, 0x219, 0x5, 0x42, 0x22, 0x2, 0x219, 
    0x222, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 0x7, 0x2c, 0x2, 0x2, 0x21b, 
    0x21c, 0x7, 0x19, 0x2, 0x2, 0x21c, 0x21d, 0x5, 0x38, 0x1d, 0x2, 0x21d, 
    0x21e, 0x7, 0x6b, 0x2, 0x2, 0x21e, 0x21f, 0x5, 0x42, 0x22, 0x2, 0x21f, 
    0x222, 0x3, 0x2, 0x2, 0x2, 0x220, 0x222, 0x3, 0x2, 0x2, 0x2, 0x221, 
    0x20a, 0x3, 0x2, 0x2, 0x2, 0x221, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x221, 
    0x214, 0x3, 0x2, 0x2, 0x2, 0x221, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x221, 
    0x220, 0x3, 0x2, 0x2, 0x2, 0x222, 0x43, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 
    0x7, 0x6a, 0x2, 0x2, 0x224, 0x229, 0x7, 0x66, 0x2, 0x2, 0x225, 0x226, 
    0x5, 0x38, 0x1d, 0x2, 0x226, 0x227, 0x5, 0x46, 0x24, 0x2, 0x227, 0x22a, 
    0x3, 0x2, 0x2, 0x2, 0x228, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x229, 0x225, 
    0x3, 0x2, 0x2, 0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 
    0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x7, 0x67, 0x2, 0x2, 0x22c, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x7, 0x6c, 0x2, 0x2, 0x22e, 0x22f, 
    0x5, 0x38, 0x1d, 0x2, 0x22f, 0x230, 0x5, 0x46, 0x24, 0x2, 0x230, 0x233, 
    0x3, 0x2, 0x2, 0x2, 0x231, 0x233, 0x3, 0x2, 0x2, 0x2, 0x232, 0x22d, 
    0x3, 0x2, 0x2, 0x2, 0x232, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x234, 0x235, 0x7, 0xb, 0x2, 0x2, 0x235, 0x236, 0x7, 
    0x64, 0x2, 0x2, 0x236, 0x237, 0x5, 0x4a, 0x26, 0x2, 0x237, 0x238, 0x7, 
    0x65, 0x2, 0x2, 0x238, 0x49, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x7, 
    0x1d, 0x2, 0x2, 0x23a, 0x23b, 0x5, 0x3c, 0x1f, 0x2, 0x23b, 0x23c, 0x7, 
    0x6b, 0x2, 0x2, 0x23c, 0x23d, 0x5, 0x4a, 0x26, 0x2, 0x23d, 0x259, 0x3, 
    0x2, 0x2, 0x2, 0x23e, 0x23f, 0x7, 0x2e, 0x2, 0x2, 0x23f, 0x240, 0x7, 
    0x6a, 0x2, 0x2, 0x240, 0x241, 0x7, 0x5f, 0x2, 0x2, 0x241, 0x242, 0x7, 
    0x6b, 0x2, 0x2, 0x242, 0x259, 0x5, 0x4a, 0x26, 0x2, 0x243, 0x244, 0x7, 
    0x31, 0x2, 0x2, 0x244, 0x245, 0x7, 0x6a, 0x2, 0x2, 0x245, 0x246, 0x7, 
    0x5e, 0x2, 0x2, 0x246, 0x247, 0x7, 0x6b, 0x2, 0x2, 0x247, 0x259, 0x5, 
    0x4a, 0x26, 0x2, 0x248, 0x249, 0x7, 0x11, 0x2, 0x2, 0x249, 0x24a, 0x7, 
    0x6a, 0x2, 0x2, 0x24a, 0x24b, 0x7, 0x5c, 0x2, 0x2, 0x24b, 0x24c, 0x7, 
    0x6b, 0x2, 0x2, 0x24c, 0x259, 0x5, 0x4a, 0x26, 0x2, 0x24d, 0x24e, 0x7, 
    0xc, 0x2, 0x2, 0x24e, 0x24f, 0x7, 0x6a, 0x2, 0x2, 0x24f, 0x250, 0x7, 
    0x5c, 0x2, 0x2, 0x250, 0x251, 0x7, 0x6b, 0x2, 0x2, 0x251, 0x259, 0x5, 
    0x4a, 0x26, 0x2, 0x252, 0x253, 0x7, 0x1a, 0x2, 0x2, 0x253, 0x254, 0x5, 
    0x44, 0x23, 0x2, 0x254, 0x255, 0x7, 0x6b, 0x2, 0x2, 0x255, 0x256, 0x5, 
    0x4a, 0x26, 0x2, 0x256, 0x259, 0x3, 0x2, 0x2, 0x2, 0x257, 0x259, 0x3, 
    0x2, 0x2, 0x2, 0x258, 0x239, 0x3, 0x2, 0x2, 0x2, 0x258, 0x23e, 0x3, 
    0x2, 0x2, 0x2, 0x258, 0x243, 0x3, 0x2, 0x2, 0x2, 0x258, 0x248, 0x3, 
    0x2, 0x2, 0x2, 0x258, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x258, 0x252, 0x3, 
    0x2, 0x2, 0x2, 0x258, 0x257, 0x3, 0x2, 0x2, 0x2, 0x259, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x25a, 0x25d, 0x5, 0x48, 0x25, 0x2, 0x25b, 0x25d, 0x5, 0x20, 
    0x11, 0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25b, 0x3, 0x2, 
    0x2, 0x2, 0x25d, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x263, 0x5, 0x8c, 
    0x47, 0x2, 0x25f, 0x260, 0x7, 0x6e, 0x2, 0x2, 0x260, 0x262, 0x5, 0x8c, 
    0x47, 0x2, 0x261, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x262, 0x265, 0x3, 0x2, 
    0x2, 0x2, 0x263, 0x261, 0x3, 0x2, 0x2, 0x2, 0x263, 0x264, 0x3, 0x2, 
    0x2, 0x2, 0x264, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x265, 0x263, 0x3, 0x2, 0x2, 
    0x2, 0x266, 0x26b, 0x5, 0x8c, 0x47, 0x2, 0x267, 0x268, 0x7, 0x6e, 0x2, 
    0x2, 0x268, 0x26a, 0x5, 0x8c, 0x47, 0x2, 0x269, 0x267, 0x3, 0x2, 0x2, 
    0x2, 0x26a, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 
    0x2, 0x26b, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x278, 0x5, 0x70, 0x39, 0x2, 
    0x26f, 0x274, 0x5, 0x8c, 0x47, 0x2, 0x270, 0x271, 0x7, 0x6e, 0x2, 0x2, 
    0x271, 0x273, 0x5, 0x8c, 0x47, 0x2, 0x272, 0x270, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x276, 0x3, 0x2, 0x2, 0x2, 0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 
    0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x276, 0x274, 0x3, 0x2, 0x2, 0x2, 0x277, 0x26e, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x278, 0x53, 0x3, 0x2, 0x2, 0x2, 0x279, 
    0x27a, 0x5, 0x50, 0x29, 0x2, 0x27a, 0x27b, 0x7, 0x62, 0x2, 0x2, 0x27b, 
    0x27c, 0x5, 0x88, 0x45, 0x2, 0x27c, 0x27d, 0x7, 0x63, 0x2, 0x2, 0x27d, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x282, 0x5, 0x60, 0x31, 0x2, 0x27f, 
    0x282, 0x5, 0x6a, 0x36, 0x2, 0x280, 0x282, 0x5, 0x7e, 0x40, 0x2, 0x281, 
    0x27e, 0x3, 0x2, 0x2, 0x2, 0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x281, 
    0x280, 0x3, 0x2, 0x2, 0x2, 0x282, 0x285, 0x3, 0x2, 0x2, 0x2, 0x283, 
    0x281, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x3, 0x2, 0x2, 0x2, 0x284, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x285, 0x283, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 
    0x5, 0x5a, 0x2e, 0x2, 0x287, 0x288, 0x5, 0x58, 0x2d, 0x2, 0x288, 0x28b, 
    0x3, 0x2, 0x2, 0x2, 0x289, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x286, 
    0x3, 0x2, 0x2, 0x2, 0x28a, 0x289, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x28c, 0x28d, 0x7, 0x42, 0x2, 0x2, 0x28d, 0x28e, 0x7, 
    0x68, 0x2, 0x2, 0x28e, 0x28f, 0x5, 0x5c, 0x2f, 0x2, 0x28f, 0x290, 0x7, 
    0x69, 0x2, 0x2, 0x290, 0x291, 0x5, 0x5e, 0x30, 0x2, 0x291, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x292, 0x293, 0x5, 0x8c, 0x47, 0x2, 0x293, 0x294, 0x7, 
    0x6e, 0x2, 0x2, 0x294, 0x295, 0x5, 0x8c, 0x47, 0x2, 0x295, 0x29e, 0x3, 
    0x2, 0x2, 0x2, 0x296, 0x297, 0x7, 0x5b, 0x2, 0x2, 0x297, 0x298, 0x7, 
    0x72, 0x2, 0x2, 0x298, 0x29e, 0x5, 0x5c, 0x2f, 0x2, 0x299, 0x29a, 0x5, 
    0x8c, 0x47, 0x2, 0x29a, 0x29b, 0x7, 0x72, 0x2, 0x2, 0x29b, 0x29c, 0x5, 
    0x5c, 0x2f, 0x2, 0x29c, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x292, 0x3, 
    0x2, 0x2, 0x2, 0x29d, 0x296, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x299, 0x3, 
    0x2, 0x2, 0x2, 0x29e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x7, 0x4c, 
    0x2, 0x2, 0x2a0, 0x2a3, 0x5, 0x8c, 0x47, 0x2, 0x2a1, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x2a2, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a1, 0x3, 0x2, 
    0x2, 0x2, 0x2a3, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 0x31, 
    0x2, 0x2, 0x2a5, 0x2a6, 0x5, 0x62, 0x32, 0x2, 0x2a6, 0x2a7, 0x5, 0x8c, 
    0x47, 0x2, 0x2a7, 0x2a8, 0x7, 0x6b, 0x2, 0x2, 0x2a8, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x2a9, 0x2b0, 0x5, 0x64, 0x33, 0x2, 0x2aa, 0x2b0, 0x5, 0x66, 
    0x34, 0x2, 0x2ab, 0x2b0, 0x5, 0x68, 0x35, 0x2, 0x2ac, 0x2b0, 0x7, 0x34, 
    0x2, 0x2, 0x2ad, 0x2b0, 0x7, 0x35, 0x2, 0x2, 0x2ae, 0x2b0, 0x5, 0x8c, 
    0x47, 0x2, 0x2af, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2aa, 0x3, 0x2, 
    0x2, 0x2, 0x2af, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2ac, 0x3, 0x2, 
    0x2, 0x2, 0x2af, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2ae, 0x3, 0x2, 
    0x2, 0x2, 0x2b0, 0x63, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b8, 0x7, 0x32, 
    0x2, 0x2, 0x2b2, 0x2b3, 0x7, 0x62, 0x2, 0x2, 0x2b3, 0x2b4, 0x7, 0x5c, 
    0x2, 0x2, 0x2b4, 0x2b5, 0x7, 0x5b, 0x2, 0x2, 0x2b5, 0x2b6, 0x7, 0x5c, 
    0x2, 0x2, 0x2b6, 0x2b9, 0x7, 0x63, 0x2, 0x2, 0x2b7, 0x2b9, 0x3, 0x2, 
    0x2, 0x2, 0x2b8, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b7, 0x3, 0x2, 
    0x2, 0x2, 0x2b9, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2c1, 0x7, 0x33, 
    0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x62, 0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x5d, 
    0x2, 0x2, 0x2bd, 0x2be, 0x7, 0x5b, 0x2, 0x2, 0x2be, 0x2bf, 0x7, 0x5d, 
    0x2, 0x2, 0x2bf, 0x2c2, 0x7, 0x63, 0x2, 0x2, 0x2c0, 0x2c2, 0x3, 0x2, 
    0x2, 0x2, 0x2c1, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c0, 0x3, 0x2, 
    0x2, 0x2, 0x2c2, 0x67, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x7, 0x3c, 
    0x2, 0x2, 0x2c4, 0x2c5, 0x7, 0x62, 0x2, 0x2, 0x2c5, 0x2ca, 0x5, 0x8c, 
    0x47, 0x2, 0x2c6, 0x2c7, 0x7, 0x6c, 0x2, 0x2, 0x2c7, 0x2c9, 0x5, 0x8c, 
    0x47, 0x2, 0x2c8, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2cc, 0x3, 0x2, 
    0x2, 0x2, 0x2ca, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 0x3, 0x2, 
    0x2, 0x2, 0x2cb, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2ca, 0x3, 0x2, 
    0x2, 0x2, 0x2cd, 0x2ce, 0x7, 0x63, 0x2, 0x2, 0x2ce, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x2cf, 0x2d0, 0x7, 0x3f, 0x2, 0x2, 0x2d0, 0x2d1, 0x5, 0x62, 
    0x32, 0x2, 0x2d1, 0x2d4, 0x5, 0x8c, 0x47, 0x2, 0x2d2, 0x2d3, 0x7, 0x57, 
    0x2, 0x2, 0x2d3, 0x2d5, 0x5, 0x6c, 0x37, 0x2, 0x2d4, 0x2d2, 0x3, 0x2, 
    0x2, 0x2, 0x2d4, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x3, 0x2, 
    0x2, 0x2, 0x2d6, 0x2d7, 0x7, 0x6b, 0x2, 0x2, 0x2d7, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x2d8, 0x2df, 0x7, 0x5c, 0x2, 0x2, 0x2d9, 0x2df, 0x7, 0x5d, 
    0x2, 0x2, 0x2da, 0x2df, 0x7, 0x5e, 0x2, 0x2, 0x2db, 0x2df, 0x7, 0x54, 
    0x2, 0x2, 0x2dc, 0x2df, 0x7, 0x55, 0x2, 0x2, 0x2dd, 0x2df, 0x5, 0x8c, 
    0x47, 0x2, 0x2de, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2d9, 0x3, 0x2, 
    0x2, 0x2, 0x2de, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2db, 0x3, 0x2, 
    0x2, 0x2, 0x2de, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2dd, 0x3, 0x2, 
    0x2, 0x2, 0x2df, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 0x5, 0x8e, 
    0x48, 0x2, 0x2e1, 0x2e2, 0x5, 0x8c, 0x47, 0x2, 0x2e2, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x2e3, 0x2e6, 0x5, 0x90, 0x49, 0x2, 0x2e4, 0x2e6, 0x3, 0x2, 
    0x2, 0x2, 0x2e5, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e4, 0x3, 0x2, 
    0x2, 0x2, 0x2e6, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 0x5, 0x8c, 
    0x47, 0x2, 0x2e8, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ea, 0x7, 0x44, 
    0x2, 0x2, 0x2ea, 0x2eb, 0x5, 0x8c, 0x47, 0x2, 0x2eb, 0x73, 0x3, 0x2, 
    0x2, 0x2, 0x2ec, 0x2ed, 0x5, 0x70, 0x39, 0x2, 0x2ed, 0x2ee, 0x7, 0x57, 
    0x2, 0x2, 0x2ee, 0x2ef, 0x5, 0xa8, 0x55, 0x2, 0x2ef, 0x2f0, 0x7, 0x6b, 
    0x2, 0x2, 0x2f0, 0x75, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x5, 0x62, 
    0x32, 0x2, 0x2f2, 0x2f6, 0x5, 0x8c, 0x47, 0x2, 0x2f3, 0x2f4, 0x7, 0x57, 
    0x2, 0x2, 0x2f4, 0x2f7, 0x5, 0xa8, 0x55, 0x2, 0x2f5, 0x2f7, 0x3, 0x2, 
    0x2, 0x2, 0x2f6, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f5, 0x3, 0x2, 
    0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x7, 0x6b, 
    0x2, 0x2, 0x2f9, 0x77, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0x45, 
    0x2, 0x2, 0x2fb, 0x2fe, 0x5, 0x54, 0x2b, 0x2, 0x2fc, 0x2ff, 0x5, 0x72, 
    0x3a, 0x2, 0x2fd, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fc, 0x3, 0x2, 
    0x2, 0x2, 0x2fe, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 0x3, 0x2, 
    0x2, 0x2, 0x300, 0x301, 0x7, 0x6b, 0x2, 0x2, 0x301, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x302, 0x305, 0x5, 0x74, 0x3b, 0x2, 0x303, 0x305, 0x5, 0x78, 
    0x3d, 0x2, 0x304, 0x302, 0x3, 0x2, 0x2, 0x2, 0x304, 0x303, 0x3, 0x2, 
    0x2, 0x2, 0x305, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x306, 0x30a, 0x7, 0x64, 
    0x2, 0x2, 0x307, 0x309, 0x5, 0x7a, 0x3e, 0x2, 0x308, 0x307, 0x3, 0x2, 
    0x2, 0x2, 0x309, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x308, 0x3, 0x2, 
    0x2, 0x2, 0x30a, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30d, 0x3, 0x2, 
    0x2, 0x2, 0x30c, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30e, 0x7, 0x65, 
    0x2, 0x2, 0x30e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x310, 0x7, 0x40, 
    0x2, 0x2, 0x310, 0x31f, 0x5, 0x8c, 0x47, 0x2, 0x311, 0x31b, 0x7, 0x62, 
    0x2, 0x2, 0x312, 0x317, 0x5, 0x80, 0x41, 0x2, 0x313, 0x314, 0x7, 0x6c, 
    0x2, 0x2, 0x314, 0x316, 0x5, 0x80, 0x41, 0x2, 0x315, 0x313, 0x3, 0x2, 
    0x2, 0x2, 0x316, 0x319, 0x3, 0x2, 0x2, 0x2, 0x317, 0x315, 0x3, 0x2, 
    0x2, 0x2, 0x317, 0x318, 0x3, 0x2, 0x2, 0x2, 0x318, 0x31c, 0x3, 0x2, 
    0x2, 0x2, 0x319, 0x317, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31c, 0x3, 0x2, 
    0x2, 0x2, 0x31b, 0x312, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31a, 0x3, 0x2, 
    0x2, 0x2, 0x31c, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x320, 0x7, 0x63, 
    0x2, 0x2, 0x31e, 0x320, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x311, 0x3, 0x2, 
    0x2, 0x2, 0x31f, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x320, 0x321, 0x3, 0x2, 
    0x2, 0x2, 0x321, 0x322, 0x7, 0x6b, 0x2, 0x2, 0x322, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x323, 0x324, 0x5, 0x62, 0x32, 0x2, 0x324, 0x325, 0x5, 0x8c, 
    0x47, 0x2, 0x325, 0x81, 0x3, 0x2, 0x2, 0x2, 0x326, 0x327, 0x7, 0x46, 
    0x2, 0x2, 0x327, 0x328, 0x5, 0x62, 0x32, 0x2, 0x328, 0x329, 0x5, 0x96, 
    0x4c, 0x2, 0x329, 0x32c, 0x7, 0x62, 0x2, 0x2, 0x32a, 0x32d, 0x5, 0x84, 
    0x43, 0x2, 0x32b, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32a, 0x3, 0x2, 
    0x2, 0x2, 0x32c, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x32e, 0x3, 0x2, 
    0x2, 0x2, 0x32e, 0x32f, 0x7, 0x63, 0x2, 0x2, 0x32f, 0x330, 0x5, 0x9e, 
    0x50, 0x2, 0x330, 0x83, 0x3, 0x2, 0x2, 0x2, 0x331, 0x336, 0x5, 0x80, 
    0x41, 0x2, 0x332, 0x333, 0x7, 0x6c, 0x2, 0x2, 0x333, 0x335, 0x5, 0x80, 
    0x41, 0x2, 0x334, 0x332, 0x3, 0x2, 0x2, 0x2, 0x335, 0x338, 0x3, 0x2, 
    0x2, 0x2, 0x336, 0x334, 0x3, 0x2, 0x2, 0x2, 0x336, 0x337, 0x3, 0x2, 
    0x2, 0x2, 0x337, 0x85, 0x3, 0x2, 0x2, 0x2, 0x338, 0x336, 0x3, 0x2, 0x2, 
    0x2, 0x339, 0x33a, 0x5, 0x96, 0x4c, 0x2, 0x33a, 0x33b, 0x7, 0x62, 0x2, 
    0x2, 0x33b, 0x33c, 0x5, 0x88, 0x45, 0x2, 0x33c, 0x33d, 0x7, 0x63, 0x2, 
    0x2, 0x33d, 0x87, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x344, 0x5, 0x6c, 0x37, 
    0x2, 0x33f, 0x344, 0x5, 0x6e, 0x38, 0x2, 0x340, 0x344, 0x5, 0x70, 0x39, 
    0x2, 0x341, 0x344, 0x5, 0x86, 0x44, 0x2, 0x342, 0x344, 0x3, 0x2, 0x2, 
    0x2, 0x343, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x343, 0x33f, 0x3, 0x2, 0x2, 
    0x2, 0x343, 0x340, 0x3, 0x2, 0x2, 0x2, 0x343, 0x341, 0x3, 0x2, 0x2, 
    0x2, 0x343, 0x342, 0x3, 0x2, 0x2, 0x2, 0x344, 0x345, 0x3, 0x2, 0x2, 
    0x2, 0x345, 0x346, 0x5, 0x8a, 0x46, 0x2, 0x346, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x347, 0x348, 0x7, 0x6c, 0x2, 0x2, 0x348, 0x34b, 0x5, 0x88, 0x45, 
    0x2, 0x349, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x347, 0x3, 0x2, 0x2, 
    0x2, 0x34a, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x34c, 0x34d, 0x9, 0x3, 0x2, 0x2, 0x34d, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x34e, 
    0x34f, 0x9, 0x4, 0x2, 0x2, 0x34f, 0x350, 0x7, 0x6e, 0x2, 0x2, 0x350, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 0x7, 0x38, 0x2, 0x2, 0x352, 
    0x353, 0x7, 0x6e, 0x2, 0x2, 0x353, 0x91, 0x3, 0x2, 0x2, 0x2, 0x354, 
    0x355, 0x7, 0x41, 0x2, 0x2, 0x355, 0x35a, 0x5, 0x8c, 0x47, 0x2, 0x356, 
    0x357, 0x7, 0x6c, 0x2, 0x2, 0x357, 0x359, 0x5, 0x8c, 0x47, 0x2, 0x358, 
    0x356, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35a, 
    0x358, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35b, 
    0x35d, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35d, 
    0x35e, 0x7, 0x6b, 0x2, 0x2, 0x35e, 0x93, 0x3, 0x2, 0x2, 0x2, 0x35f, 
    0x360, 0x7, 0x2e, 0x2, 0x2, 0x360, 0x361, 0x7, 0x6a, 0x2, 0x2, 0x361, 
    0x362, 0x5, 0x8c, 0x47, 0x2, 0x362, 0x363, 0x7, 0x6b, 0x2, 0x2, 0x363, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x364, 0x369, 0x5, 0x8c, 0x47, 0x2, 0x365, 
    0x366, 0x7, 0x6e, 0x2, 0x2, 0x366, 0x368, 0x5, 0x8c, 0x47, 0x2, 0x367, 
    0x365, 0x3, 0x2, 0x2, 0x2, 0x368, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x369, 
    0x367, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36a, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36f, 
    0x5, 0x9a, 0x4e, 0x2, 0x36d, 0x36f, 0x5, 0x9e, 0x50, 0x2, 0x36e, 0x36c, 
    0x3, 0x2, 0x2, 0x2, 0x36e, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x370, 0x379, 0x5, 0x9c, 0x4f, 0x2, 0x371, 0x379, 0x5, 
    0x74, 0x3b, 0x2, 0x372, 0x379, 0x5, 0xb4, 0x5b, 0x2, 0x373, 0x379, 0x5, 
    0xac, 0x57, 0x2, 0x374, 0x379, 0x5, 0x76, 0x3c, 0x2, 0x375, 0x379, 0x5, 
    0x78, 0x3d, 0x2, 0x376, 0x379, 0x5, 0xa2, 0x52, 0x2, 0x377, 0x379, 0x5, 
    0xa0, 0x51, 0x2, 0x378, 0x370, 0x3, 0x2, 0x2, 0x2, 0x378, 0x371, 0x3, 
    0x2, 0x2, 0x2, 0x378, 0x372, 0x3, 0x2, 0x2, 0x2, 0x378, 0x373, 0x3, 
    0x2, 0x2, 0x2, 0x378, 0x374, 0x3, 0x2, 0x2, 0x2, 0x378, 0x375, 0x3, 
    0x2, 0x2, 0x2, 0x378, 0x376, 0x3, 0x2, 0x2, 0x2, 0x378, 0x377, 0x3, 
    0x2, 0x2, 0x2, 0x379, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 0x5, 0x86, 
    0x44, 0x2, 0x37b, 0x37c, 0x7, 0x6b, 0x2, 0x2, 0x37c, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x381, 0x7, 0x64, 0x2, 0x2, 0x37e, 0x380, 0x5, 0x9a, 
    0x4e, 0x2, 0x37f, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x380, 0x383, 0x3, 0x2, 
    0x2, 0x2, 0x381, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x381, 0x382, 0x3, 0x2, 
    0x2, 0x2, 0x382, 0x384, 0x3, 0x2, 0x2, 0x2, 0x383, 0x381, 0x3, 0x2, 
    0x2, 0x2, 0x384, 0x385, 0x7, 0x65, 0x2, 0x2, 0x385, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x386, 0x387, 0x7, 0x39, 0x2, 0x2, 0x387, 0x388, 0x5, 0xa4, 
    0x53, 0x2, 0x388, 0x389, 0x7, 0x6b, 0x2, 0x2, 0x389, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0x38a, 0x38b, 0x7, 0x56, 0x2, 0x2, 0x38b, 0x38c, 0x7, 0x6b, 
    0x2, 0x2, 0x38c, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x5, 0xbc, 
    0x5f, 0x2, 0x38e, 0x38f, 0x5, 0xa6, 0x54, 0x2, 0x38f, 0x399, 0x3, 0x2, 
    0x2, 0x2, 0x390, 0x391, 0x7, 0x62, 0x2, 0x2, 0x391, 0x392, 0x5, 0xa4, 
    0x53, 0x2, 0x392, 0x393, 0x7, 0x63, 0x2, 0x2, 0x393, 0x399, 0x3, 0x2, 
    0x2, 0x2, 0x394, 0x395, 0x7, 0x70, 0x2, 0x2, 0x395, 0x399, 0x5, 0xa4, 
    0x53, 0x2, 0x396, 0x397, 0x7, 0x4e, 0x2, 0x2, 0x397, 0x399, 0x5, 0xa4, 
    0x53, 0x2, 0x398, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x398, 0x390, 0x3, 0x2, 
    0x2, 0x2, 0x398, 0x394, 0x3, 0x2, 0x2, 0x2, 0x398, 0x396, 0x3, 0x2, 
    0x2, 0x2, 0x399, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x39b, 0x9, 0x5, 0x2, 
    0x2, 0x39b, 0x39e, 0x5, 0xa4, 0x53, 0x2, 0x39c, 0x39e, 0x3, 0x2, 0x2, 
    0x2, 0x39d, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39c, 0x3, 0x2, 0x2, 
    0x2, 0x39e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 0x7, 0x62, 0x2, 
    0x2, 0x3a0, 0x3a1, 0x5, 0xa8, 0x55, 0x2, 0x3a1, 0x3a2, 0x7, 0x63, 0x2, 
    0x2, 0x3a2, 0x3a3, 0x5, 0xaa, 0x56, 0x2, 0x3a3, 0x3ae, 0x3, 0x2, 0x2, 
    0x2, 0x3a4, 0x3a5, 0x7, 0x4e, 0x2, 0x2, 0x3a5, 0x3ae, 0x5, 0xa8, 0x55, 
    0x2, 0x3a6, 0x3a7, 0x7, 0x51, 0x2, 0x2, 0x3a7, 0x3ae, 0x5, 0xa8, 0x55, 
    0x2, 0x3a8, 0x3a9, 0x7, 0x70, 0x2, 0x2, 0x3a9, 0x3ae, 0x5, 0xa8, 0x55, 
    0x2, 0x3aa, 0x3ab, 0x5, 0xa4, 0x53, 0x2, 0x3ab, 0x3ac, 0x5, 0xaa, 0x56, 
    0x2, 0x3ac, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x39f, 0x3, 0x2, 0x2, 
    0x2, 0x3ad, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3a6, 0x3, 0x2, 0x2, 
    0x2, 0x3ad, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3aa, 0x3, 0x2, 0x2, 
    0x2, 0x3ae, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3c3, 0x7, 0x50, 0x2, 
    0x2, 0x3b0, 0x3c3, 0x7, 0x53, 0x2, 0x2, 0x3b1, 0x3c3, 0x7, 0x4f, 0x2, 
    0x2, 0x3b2, 0x3c3, 0x7, 0x52, 0x2, 0x2, 0x3b3, 0x3b4, 0x7, 0x57, 0x2, 
    0x2, 0x3b4, 0x3c3, 0x7, 0x57, 0x2, 0x2, 0x3b5, 0x3b6, 0x7, 0x4e, 0x2, 
    0x2, 0x3b6, 0x3c3, 0x7, 0x57, 0x2, 0x2, 0x3b7, 0x3c3, 0x7, 0x51, 0x2, 
    0x2, 0x3b8, 0x3bb, 0x7, 0x68, 0x2, 0x2, 0x3b9, 0x3bc, 0x7, 0x57, 0x2, 
    0x2, 0x3ba, 0x3bc, 0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3b9, 0x3, 0x2, 0x2, 
    0x2, 0x3bb, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3c3, 0x3, 0x2, 0x2, 
    0x2, 0x3bd, 0x3c0, 0x7, 0x69, 0x2, 0x2, 0x3be, 0x3c1, 0x7, 0x57, 0x2, 
    0x2, 0x3bf, 0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3be, 0x3, 0x2, 0x2, 
    0x2, 0x3c0, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3c3, 0x3, 0x2, 0x2, 
    0x2, 0x3c2, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3b0, 0x3, 0x2, 0x2, 
    0x2, 0x3c2, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3b2, 0x3, 0x2, 0x2, 
    0x2, 0x3c2, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3b5, 0x3, 0x2, 0x2, 
    0x2, 0x3c2, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3b8, 0x3, 0x2, 0x2, 
    0x2, 0x3c2, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c4, 0x3, 0x2, 0x2, 
    0x2, 0x3c4, 0x3c7, 0x5, 0xa8, 0x55, 0x2, 0x3c5, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c5, 0x3, 0x2, 0x2, 
    0x2, 0x3c7, 0xab, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3cb, 0x5, 0xae, 0x58, 
    0x2, 0x3c9, 0x3cc, 0x5, 0xb2, 0x5a, 0x2, 0x3ca, 0x3cc, 0x3, 0x2, 0x2, 
    0x2, 0x3cb, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3cb, 0x3ca, 0x3, 0x2, 0x2, 
    0x2, 0x3cc, 0xad, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3ce, 0x7, 0x4a, 0x2, 
    0x2, 0x3ce, 0x3d1, 0x5, 0xb0, 0x59, 0x2, 0x3cf, 0x3d2, 0x5, 0x98, 0x4d, 
    0x2, 0x3d0, 0x3d2, 0x7, 0x6b, 0x2, 0x2, 0x3d1, 0x3cf, 0x3, 0x2, 0x2, 
    0x2, 0x3d1, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0x3d3, 0x3d4, 0x7, 0x62, 0x2, 0x2, 0x3d4, 0x3d5, 0x5, 0xa8, 0x55, 0x2, 
    0x3d5, 0x3d6, 0x7, 0x63, 0x2, 0x2, 0x3d6, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0x3d7, 0x3d8, 0x7, 0x4b, 0x2, 0x2, 0x3d8, 0x3d9, 0x5, 0x98, 0x4d, 0x2, 
    0x3d9, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3db, 0x7, 0x47, 0x2, 0x2, 
    0x3db, 0x3dc, 0x5, 0xb6, 0x5c, 0x2, 0x3dc, 0x3e0, 0x7, 0x64, 0x2, 0x2, 
    0x3dd, 0x3df, 0x5, 0xb8, 0x5d, 0x2, 0x3de, 0x3dd, 0x3, 0x2, 0x2, 0x2, 
    0x3df, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3de, 0x3, 0x2, 0x2, 0x2, 
    0x3e0, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e5, 0x3, 0x2, 0x2, 0x2, 
    0x3e2, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e6, 0x5, 0xba, 0x5e, 0x2, 
    0x3e4, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e3, 0x3, 0x2, 0x2, 0x2, 
    0x3e5, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e7, 0x3, 0x2, 0x2, 0x2, 
    0x3e7, 0x3e8, 0x7, 0x65, 0x2, 0x2, 0x3e8, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0x3e9, 0x3ea, 0x7, 0x62, 0x2, 0x2, 0x3ea, 0x3eb, 0x5, 0x8c, 0x47, 0x2, 
    0x3eb, 0x3ec, 0x7, 0x63, 0x2, 0x2, 0x3ec, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0x3ed, 0x3ee, 0x7, 0x48, 0x2, 0x2, 0x3ee, 0x3ef, 0x5, 0x6c, 0x37, 0x2, 
    0x3ef, 0x3f7, 0x7, 0x6a, 0x2, 0x2, 0x3f0, 0x3f8, 0x5, 0x9e, 0x50, 0x2, 
    0x3f1, 0x3f3, 0x5, 0x9a, 0x4e, 0x2, 0x3f2, 0x3f1, 0x3, 0x2, 0x2, 0x2, 
    0x3f3, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f2, 0x3, 0x2, 0x2, 0x2, 
    0x3f4, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f8, 0x3, 0x2, 0x2, 0x2, 
    0x3f6, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f0, 0x3, 0x2, 0x2, 0x2, 
    0x3f7, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x3f9, 
    0x3fa, 0x7, 0x49, 0x2, 0x2, 0x3fa, 0x402, 0x7, 0x6a, 0x2, 0x2, 0x3fb, 
    0x403, 0x5, 0x9e, 0x50, 0x2, 0x3fc, 0x3fe, 0x5, 0x9a, 0x4e, 0x2, 0x3fd, 
    0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x401, 0x3, 0x2, 0x2, 0x2, 0x3ff, 
    0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x400, 0x3, 0x2, 0x2, 0x2, 0x400, 
    0x403, 0x3, 0x2, 0x2, 0x2, 0x401, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x402, 
    0x3fb, 0x3, 0x2, 0x2, 0x2, 0x402, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x403, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0x404, 0x409, 0x5, 0x6e, 0x38, 0x2, 0x405, 
    0x409, 0x5, 0x70, 0x39, 0x2, 0x406, 0x409, 0x5, 0x86, 0x44, 0x2, 0x407, 
    0x409, 0x5, 0x6c, 0x37, 0x2, 0x408, 0x404, 0x3, 0x2, 0x2, 0x2, 0x408, 
    0x405, 0x3, 0x2, 0x2, 0x2, 0x408, 0x406, 0x3, 0x2, 0x2, 0x2, 0x408, 
    0x407, 0x3, 0x2, 0x2, 0x2, 0x409, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x46, 0xdc, 
    0x106, 0x10e, 0x117, 0x123, 0x129, 0x13c, 0x171, 0x194, 0x1a3, 0x1ab, 
    0x1ce, 0x1f2, 0x1fa, 0x203, 0x221, 0x229, 0x232, 0x258, 0x25c, 0x263, 
    0x26b, 0x274, 0x277, 0x281, 0x283, 0x28a, 0x29d, 0x2a2, 0x2af, 0x2b8, 
    0x2c1, 0x2ca, 0x2d4, 0x2de, 0x2e5, 0x2f6, 0x2fe, 0x304, 0x30a, 0x317, 
    0x31b, 0x31f, 0x32c, 0x336, 0x343, 0x34a, 0x35a, 0x369, 0x36e, 0x378, 
    0x381, 0x398, 0x39d, 0x3ad, 0x3bb, 0x3c0, 0x3c2, 0x3c6, 0x3cb, 0x3d1, 
    0x3e0, 0x3e5, 0x3f4, 0x3f7, 0x3ff, 0x402, 0x408, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TrafficSimDeclParser::Initializer TrafficSimDeclParser::_init;
