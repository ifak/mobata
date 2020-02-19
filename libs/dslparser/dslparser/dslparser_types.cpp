#include "dslparser_types.hpp"

#undef emit
#undef SIGNAL

#include "common/CommonLexer.h"
#include "spenat/SpenatLexer.h"
#include "statemachine/StateMachineLexer.h"
#include "sut/SutDeclLexer.h"
#include "testsystem/TestSystemDeclLexer.h"
#include "testcase/TestCaseDeclLexer.h"
#include "diagnosis/DiagnosisDeclLexer.h"
#include "isrdl/IsrdlLexer.h"
#include "irdl/IrdlLexer.h"
#include "irdl/IrdlParser.h"
#include "trafficsim/TrafficSimDeclLexer.h"
#include "simsystem/SimSystemDeclLexer.h"

#include <mobata/memory_leak_start.hpp>

namespace dslparser {

int requirementTokenType(int antlrTokenType) {
    int tokenType = commonTokenType<IrdlLexer>(antlrTokenType);
    if(tokenType!=UnknownTokenType)
        return tokenType;

    switch (antlrTokenType)
    {
    case IrdlLexer::RequirementID:
        tokenType = Requirement;
        break;
    case IrdlLexer::ImportID:
        tokenType = Import;
        break;
    case IrdlLexer::DeclarationID:
        tokenType = Declaration;
        break;
    case IrdlLexer::UseID:
        tokenType = Use;
        break;
    case IrdlLexer::DescriptionID:
        tokenType = Description;
        break;
    case IrdlLexer::ComponentID:
        tokenType = Component;
        break;
    case IrdlLexer::ActorID:
        tokenType = Actor;
        break;
    case IrdlLexer::StateID:
        tokenType = State;
        break;
    case IrdlLexer::AtID:
        tokenType = At;
        break;
    case IrdlLexer::AllID:
        tokenType = All;
        break;
    case IrdlLexer::MessageID:
        tokenType = Message;
        break;
    case IrdlLexer::CheckID:
        tokenType = Check;
        break;
    case IrdlLexer::TimerID:
        tokenType = Timer;
        break;
    case IrdlLexer::SignalID:
        tokenType = Signal;
        break;
    case IrdlLexer::AltID:
        tokenType = Alt;
        break;
    case IrdlLexer::DurationID:
        tokenType = Duration;
        break;
    case IrdlLexer::MilliSekID:
        tokenType = MSek;
        break;
    case IrdlLexer::SekID:
        tokenType = Sek;
        break;
    case IrdlLexer::AttributeID:
        tokenType = Attribute;
        break;
    case IrdlLexer::TypeID:
        tokenType = Type;
        break;
    default:
        break;
    }

    return tokenType;
}

int spenatTokenType(int antlrTokenType)
{
    int tokenType = commonTokenType<SpenatLexer>(antlrTokenType);
    if(tokenType!=UnknownTokenType)
        return tokenType;

    switch (antlrTokenType)
    {
    case SpenatLexer::SpenatID:
        tokenType = Spenat;
        break;
    case SpenatLexer::PlaceID:
        tokenType = Place;
        break;
    case SpenatLexer::GuardID:
        tokenType = Guard;
        break;
    case SpenatLexer::ActionID:
        tokenType = Action;
        break;
    case SpenatLexer::SignalTransitionID:
        tokenType = SignalTransition;
        break;
    case SpenatLexer::TimeoutTransitionID:
        tokenType = TimeoutTransition;
        break;
    case SpenatLexer::RefSignalID:
        tokenType = RefSignal;
        break;
    case SpenatLexer::RefPortID:
        tokenType = RefPort;
        break;
    case SpenatLexer::ValueID:
        tokenType = Value;
        break;
    case SpenatLexer::InitialID:
        tokenType = Initial;
        break;
    case SpenatLexer::PreID:
        tokenType = Pre;
        break;
    case SpenatLexer::PostID:
        tokenType = Post;
        break;
    default:
        break;
    }

    return tokenType;
}

int stateMachineTokenType(int antlrTokenType)
{
    int tokenType = commonTokenType<StateMachineLexer>(antlrTokenType);
    if(tokenType!=UnknownTokenType)
        return tokenType;

    switch (antlrTokenType)
    {
    case StateMachineLexer::StateMachineID:
        tokenType = StateMachine;
        break;
    case StateMachineLexer::GuardID:
        tokenType = Guard;
        break;
    case StateMachineLexer::ActionID:
        tokenType = Action;
        break;
    case StateMachineLexer::SignalTransitionID:
        tokenType = SignalTransition;
        break;
    case StateMachineLexer::TimeoutTransitionID:
        tokenType = TimeoutTransition;
        break;
    case StateMachineLexer::RefSignalID:
        tokenType = RefSignal;
        break;
    case StateMachineLexer::RefPortID:
        tokenType = RefPort;
        break;
    case StateMachineLexer::ValueID:
        tokenType = Value;
        break;
    case StateMachineLexer::InitStateID:
        tokenType = InitState;
        break;
    case StateMachineLexer::SimpleStateID:
        tokenType = SimpleState;
        break;
    case StateMachineLexer::CompositeStateID:
        tokenType = CompositeState;
        break;
    case StateMachineLexer::JunctionStateID:
        tokenType = JunctionState;
        break;
    case StateMachineLexer::ConcurrentStateID:
        tokenType = ConcurrentState;
        break;
    case StateMachineLexer::FinalStateID:
        tokenType = FinalState;
        break;
    case StateMachineLexer::SourceStateID:
        tokenType = Source;
        break;
    case StateMachineLexer::TargetStateID:
        tokenType = Target;
        break;
    case StateMachineLexer::EntryActionID:
        tokenType = EntryAction;
        break;
    case StateMachineLexer::ExitActionID:
        tokenType = ExitAction;
        break;
    case StateMachineLexer::RegionID:
        tokenType = StateRegion;
        break;
    default:
        break;
    }

    return tokenType;
}

int sutTokenType(int antlrTokenType)
{
    int tokenType = commonTokenType<SutDeclLexer>(antlrTokenType);
    if(tokenType!=UnknownTokenType)
        return tokenType;

    switch (antlrTokenType)
    {
    case SutDeclLexer::SutID:
        tokenType = Sut;
        break;
    case SutDeclLexer::SutComponentID:
        tokenType = SutComponent;
        break;
    default:
        break;
    }
    return tokenType;
}

int simSystemTokenType(int antlrTokenType){
  int tokenType = commonTokenType<SimSystemDeclLexer>(antlrTokenType);
  if(tokenType!=UnknownTokenType)
      return tokenType;

  switch (antlrTokenType)
  {
  case SimSystemDeclLexer::ActorID:
      tokenType = SimSystemActor;
      break;
  case SimSystemDeclLexer::SimSystemID:
      tokenType = SimSystem;
      break;
  case SimSystemDeclLexer::ConnectionID:
      tokenType = Connection;
      break;
  case SimSystemDeclLexer::ConfigID:
      tokenType = Config;
      break;
  case SimSystemDeclLexer::StartSequenceID:
      tokenType = StartSequence;
      break;
  case SimSystemDeclLexer::StartupID:
      tokenType = Startup;
      break;
  case SimSystemDeclLexer::MessageID:
      tokenType = Message;
      break;
  default:
      break;
  }
  return tokenType;
}

int testSystemTokenType(int antlrTokenType)
{
    int tokenType = commonTokenType<TestSystemDeclLexer>(antlrTokenType);
    if(tokenType!=UnknownTokenType)
        return tokenType;

    switch (antlrTokenType)
    {
    case TestSystemDeclLexer::TestSystemID:
        tokenType = TestSystem;
        break;
    case TestSystemDeclLexer::TestComponentID:
        tokenType = TestComponent;
        break;
    case TestSystemDeclLexer::LinkID:
        tokenType = Link;
        break;
    case TestSystemDeclLexer::SourceID:
        tokenType = Attribute;
        break;
    case TestSystemDeclLexer::TargetID:
        tokenType = Attribute;
        break;
    default:
        break;
    }
    return tokenType;
}

int testCaseTokenType(int antlrTokenType)
{
    int tokenType = commonTokenType<TestCaseDeclLexer>(antlrTokenType);
    if(tokenType!=UnknownTokenType)
      return tokenType;

    switch (antlrTokenType)
    {
      case TestCaseDeclLexer::TestCaseID:
        tokenType = TestCase;
        break;
      case TestCaseDeclLexer::ComponentID:
        tokenType = Component;
        break;
      case TestCaseDeclLexer::MessageID:
        tokenType = Message;
        break;
      case TestCaseDeclLexer::DeclarationID:
        tokenType = Declaration;
        break;
      case TestCaseDeclLexer::TimeOutID:
        tokenType = Timeout;
        break;
      case TestCaseDeclLexer::AccuracyID:
        tokenType = Accuracy;
        break;
      case TestCaseDeclLexer::CheckID:
        tokenType = Check;
        break;
      case TestCaseDeclLexer::AltID:
        tokenType = Alt;
        break;
      case TestCaseDeclLexer::TimerID:
        tokenType = Timer;
        break;
      default:
        break;
    }
    return tokenType;
}

int diagnosisTokenType(int antlrTokenType)
{
    int tokenType = commonTokenType<DiagnosisDeclLexer>(antlrTokenType);
    if(tokenType!=UnknownTokenType)
        return tokenType;

    switch (antlrTokenType)
    {
    case DiagnosisDeclLexer::DiagnosisID:
        tokenType = Diagnosis;
        break;
    case DiagnosisDeclLexer::ComponentID:
        tokenType = Component;
        break;
    case DiagnosisDeclLexer::UseID:
        tokenType = Use;
        break;
    case DiagnosisDeclLexer::MessageID:
        tokenType = Message;
        break;
    case DiagnosisDeclLexer::DeclarationID:
        tokenType = Declaration;
        break;
    case DiagnosisDeclLexer::ComponentsID:
        tokenType = Components;
        break;
    case DiagnosisDeclLexer::RuleID:
        tokenType = Rule;
        break;
    case DiagnosisDeclLexer::BaseTypeID:
        tokenType = BaseType;
        break;
    case DiagnosisDeclLexer::ParallelSequenceID:
        tokenType = ParallelSequence;
        break;
    case DiagnosisDeclLexer::ConditionID:
        tokenType = Condition;
        break;
    case DiagnosisDeclLexer::CheckID:
        tokenType = Check;
        break;
    case DiagnosisDeclLexer::ParallelID:
        tokenType = Parallel;
        break;
    case DiagnosisDeclLexer::LoopID:
        tokenType = Loop;
        break;
    case DiagnosisDeclLexer::SequenceID:
        tokenType = Sequence;
        break;
    case DiagnosisDeclLexer::DescriptionID:
        tokenType = Description;
        break;
    case DiagnosisDeclLexer::SignalsID:
        tokenType = Signals;
        break;
    default:
        break;
    }
    return tokenType;
}

int trafficsimTokenType(int antlrTokenType)
{
    int tokenType = UnknownTrafficSimTokenType;

    switch (antlrTokenType)
    {
    case TrafficSimDeclLexer::TRAFFICSIMULATION:
        tokenType = TrafficSimID;
        break;
    case TrafficSimDeclLexer::Sensor:
        tokenType = TrafficSimID;
        break;
    case TrafficSimDeclLexer::Intersection:
        tokenType = TrafficSimID;
        break;
    case TrafficSimDeclLexer::Step:
        tokenType = TrafficSimID;
        break;
    case TrafficSimDeclLexer::Arm:
        tokenType = TrafficSimID;
        break;
    case TrafficSimDeclLexer::HasTrafficLight:
        tokenType = TrafficSimID;
        break;
    case TrafficSimDeclLexer::Accident:
        tokenType = Accident;
        break;
    case TrafficSimDeclLexer::NeighboringTrafficLights:
        tokenType = NeighboringTrafficLights;
        break;
    case TrafficSimDeclLexer::TrafficLight:
        tokenType = TrafficLight;
        break;
    case TrafficSimDeclLexer::Turns:
        tokenType = Turns;
        break;
    case TrafficSimDeclLexer::Lanes:
        tokenType = Lanes;
        break;
    case TrafficSimDeclLexer::States:
        tokenType = States;
        break;
    case TrafficSimDeclLexer::InnerConnections:
        tokenType = InnerConnections;
        break;
    case TrafficSimDeclLexer::OuterConnection:
        tokenType = OuterConnection;
        break;
    case TrafficSimDeclLexer::Duration:
        tokenType = Duration;
        break;
    case TrafficSimDeclLexer::MinDur:
        tokenType = MinDur;
        break;
    case TrafficSimDeclLexer::MaxDur:
        tokenType = MaxDur;
        break;
    case TrafficSimDeclLexer::Factor:
        tokenType = Factor;
        break;
    case TrafficSimDeclLexer::Measured:
        tokenType = Measured;
        break;
    case TrafficSimDeclLexer::Lane:
        tokenType = Lane;
        break;
    case TrafficSimDeclLexer::Message:
        tokenType = TrafficSimID;
        break;
    case TrafficSimDeclLexer::VehicleMovement:
        tokenType = VehicleMovement;
        break;
    case TrafficSimDeclLexer::Phase:
        tokenType = Phase;
        break;
    case TrafficSimDeclLexer::Phases:
        tokenType = Phases;
        break;
    case TrafficSimDeclLexer::TransitionPhases:
        tokenType = TransitionPhases;
        break;
    case TrafficSimDeclLexer::Transition:
        tokenType = Transition;
        break;
    case TrafficSimDeclLexer::Transitions:
        tokenType = Transitions;
        break;
    case TrafficSimDeclLexer::Trigger:
        tokenType = Trigger;
        break;
    case TrafficSimDeclLexer::VehiclePerHour:
        tokenType = VehiclePerHour;
        break;
    case TrafficSimDeclLexer::VehicleDistribution:
        tokenType = VehicleDistribution;
        break;
    case TrafficSimDeclLexer::LVehicleDistribution:
        tokenType = LVehicleDistribution;
        break;
    case TrafficSimDeclLexer::Label:
        tokenType = Label;
        break;
    case TrafficSimDeclLexer::Bicycle:
        tokenType = Bicycle;
        break;
    case TrafficSimDeclLexer::Bus:
        tokenType = Bus;
        break;
    case TrafficSimDeclLexer::Moped:
        tokenType = Moped;
        break;
    case TrafficSimDeclLexer::Motorcycle:
        tokenType = Motorcycle;
        break;
    case TrafficSimDeclLexer::Car:
        tokenType = Car;
        break;
    case TrafficSimDeclLexer::Emergency:
        tokenType = Emergency;
        break;
    case TrafficSimDeclLexer::Truck:
        tokenType = Truck;
        break;
    case TrafficSimDeclLexer::Start:
        tokenType = Start;
        break;
    case TrafficSimDeclLexer::StartArm:
        tokenType = StartArm;
        break;
    case TrafficSimDeclLexer::End:
        tokenType = End;
        break;
    case TrafficSimDeclLexer::TypeID:
        tokenType = Type;
        break;
    case TrafficSimDeclLexer::NameID:
        tokenType = Name;
        break;
    case TrafficSimDeclLexer::ImportID:
        tokenType = Import;
        break;
    case TrafficSimDeclLexer::AsID:
        tokenType = As;
        break;
    case TrafficSimDeclLexer::SignalID:
        tokenType = Signal;
        break;
    case TrafficSimDeclLexer::PortID:
        tokenType = Port;
        break;
    case TrafficSimDeclLexer::AttributeID:
        tokenType = Attribute;
        break;
    case TrafficSimDeclLexer::TriggerID:
        tokenType = Trigger;
        break;
    case TrafficSimDeclLexer::ThisID:
        tokenType = This;
        break;
    case TrafficSimDeclLexer::LPAREN:
        tokenType = LeftParen;
        break;
    case TrafficSimDeclLexer::RPAREN:
        tokenType = RightParen;
        break;
    case TrafficSimDeclLexer::LBRACE:
        tokenType = LeftBrace;
        break;
    case TrafficSimDeclLexer::RBRACE:
        tokenType = RightBrace;
        break;
    case TrafficSimDeclLexer::LBRACKET:
        tokenType = LeftBracket;
        break;
    case TrafficSimDeclLexer::RBRACKET:
        tokenType = RightBracket;
        break;
    case TrafficSimDeclLexer::COLON:
        tokenType = Colon;
        break;
    case TrafficSimDeclLexer::SEMI:
        tokenType = Semi;
        break;
    case TrafficSimDeclLexer::COMMA:
        tokenType = Comma;
        break;
    case TrafficSimDeclLexer::DOT:
        tokenType = Dot;
        break;
    case TrafficSimDeclLexer::RANGE:
        tokenType = Range;
        break;
    case TrafficSimDeclLexer::PLUS:
        tokenType = Plus;
        break;
    case TrafficSimDeclLexer::MINUS:
        tokenType = Minus;
        break;
    case TrafficSimDeclLexer::MULT:
        tokenType = Mult;
        break;
    case TrafficSimDeclLexer::DIV:
        tokenType = Div;
        break;
    case TrafficSimDeclLexer::NotIdWord:
        tokenType = Not;
        break;
    case TrafficSimDeclLexer::AndIdWord:
        tokenType = And;
        break;
    case TrafficSimDeclLexer::OrIdWord:
        tokenType = Or;
        break;
    case TrafficSimDeclLexer::NotIdSymbol:
        tokenType = Not;
        break;
    case TrafficSimDeclLexer::AndIdSymbol:
        tokenType = And;
        break;
    case TrafficSimDeclLexer::OrIdSymbol:
        tokenType = Or;
        break;
    case TrafficSimDeclLexer::TrueID:
        tokenType = True;
        break;
    case TrafficSimDeclLexer::FalseID:
        tokenType = False;
        break;
    case TrafficSimDeclLexer::INT:
        tokenType = Int;
        break;
    case TrafficSimDeclLexer::REAL:
        tokenType = Real;
        break;
    case TrafficSimDeclLexer::STRING:
        tokenType = String;
        break;
    case TrafficSimDeclLexer::ID:
        tokenType = Identifier;
        break;
    case TrafficSimDeclLexer::LINE_COMMENT:
        tokenType = LineComment;
        break;
    case TrafficSimDeclLexer::COMMENT:
        tokenType = MultiLineComment;
        break;
    case TrafficSimDeclLexer::NEWLINE:
        tokenType = NewLine;
        break;
    case TrafficSimDeclLexer::BoolID:
        tokenType = Type;
        break;
    case TrafficSimDeclLexer::EnumID:
        tokenType = Type;
        break;
    case TrafficSimDeclLexer::RealID:
        tokenType = Type;
        break;
    case TrafficSimDeclLexer::StringID:
        tokenType = Type;
        break;
    case TrafficSimDeclLexer::IntID:
        tokenType = Type;
        break;
    case TrafficSimDeclLexer::WS:
        tokenType = WhiteSpace;
        break;
    default:
        break;
    }
    return tokenType;
}

int isrdlTokenType(int antlrTokenType)
{
  int tokenType = commonTokenType<IsrdlLexer>(antlrTokenType);
  if(tokenType!=UnknownTokenType)
      return tokenType;

  switch (antlrTokenType)
  {
  case IsrdlLexer::TimeoutID:
      tokenType = Timeout;
      break;
  case IsrdlLexer::MSekID:
      tokenType = MSek;
      break;
  case IsrdlLexer::SekID:
      tokenType = Sek;
      break;
  case IsrdlLexer::NoDamageID:
      tokenType = IntegrityEnum;
      break;
  case IsrdlLexer::AffectedID:
      tokenType = IntegrityEnum;
      break;
  case IsrdlLexer::IntegrityThreatID:
      tokenType = IntegrityThreat;
      break;
  case IsrdlLexer::BrokenID:
      tokenType = ConfidentialityEnum;
      break;
  case IsrdlLexer::IntactID:
      tokenType = ConfidentialityEnum;
      break;
  case IsrdlLexer::ConfidentialityThreatID:
      tokenType = ConfidentialityThreat;
      break;
  case IsrdlLexer::AdministratorID:
      tokenType = PrivilegesEnum;
      break;
  case IsrdlLexer::InstallAllowedID:
      tokenType = PrivilegesEnum;
      break;
  case IsrdlLexer::UnInstallAllowedID:
      tokenType = PrivilegesEnum;
      break;
  case IsrdlLexer::SaveAllowedID:
      tokenType = PrivilegesEnum;
      break;
  case IsrdlLexer::EditAllowedID:
      tokenType = PrivilegesEnum;
      break;
  case IsrdlLexer::NoneID:
      tokenType = PrivilegesEnum;
      break;
  case IsrdlLexer::PrivilegesID:
      tokenType = Privileges;
      break;
  case IsrdlLexer::SourceID:
      tokenType = Source;
      break;
  case IsrdlLexer::InternetID:
      tokenType = AttackVectorEnum;
      break;
  case IsrdlLexer::LocalID:
      tokenType = AttackVectorEnum;
      break;
  case IsrdlLexer::PhysicalID:
      tokenType = AttackVectorEnum;
      break;
  case IsrdlLexer::ImpactID:
      tokenType = Impact;
      break;
  case IsrdlLexer::SecurityRequirementID:
      tokenType = SecurityRequirement;
      break;
  case IsrdlLexer::AttackDescriptionID:
      tokenType = Description;
      break;
  }
  return tokenType;
}

} // namespace dslparser
