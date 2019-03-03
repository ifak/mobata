/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "dslparser_types.hpp"

#undef emit
#undef SIGNAL

#include "common/CommonLexer.h"
#include "spenat/SpenatLexer.h"
#include "statemachine/StateMachineLexer.h"
#include "sut/SutDeclLexer.h"
#include "testsystem/TestSystemDeclLexer.h"
#include "testcase/TestCaseDeclLexer.h"
#include "irdl/IrdlLexer.h"
#include "irdl/IrdlParser.h"
#include "simsystem/SimSystemDeclLexer.h"

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

} // namespace dslparser
