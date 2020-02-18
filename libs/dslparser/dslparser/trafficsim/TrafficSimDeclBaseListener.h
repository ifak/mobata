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

// Generated from C:/Users/mre/Documents/Repositories/tfvs/mbtcreator/3rd/mobata/libs/dslparser/dslparser/grammars/TrafficSimDecl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "TrafficSimDeclListener.h"


/**
 * This class provides an empty implementation of TrafficSimDeclListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TrafficSimDeclBaseListener : public TrafficSimDeclListener {
public:

  virtual void enterStart(TrafficSimDeclParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(TrafficSimDeclParser::StartContext * /*ctx*/) override { }

  virtual void enterStartArm(TrafficSimDeclParser::StartArmContext * /*ctx*/) override { }
  virtual void exitStartArm(TrafficSimDeclParser::StartArmContext * /*ctx*/) override { }

  virtual void enterEnd(TrafficSimDeclParser::EndContext * /*ctx*/) override { }
  virtual void exitEnd(TrafficSimDeclParser::EndContext * /*ctx*/) override { }

  virtual void enterStep(TrafficSimDeclParser::StepContext * /*ctx*/) override { }
  virtual void exitStep(TrafficSimDeclParser::StepContext * /*ctx*/) override { }

  virtual void enterStepBody(TrafficSimDeclParser::StepBodyContext * /*ctx*/) override { }
  virtual void exitStepBody(TrafficSimDeclParser::StepBodyContext * /*ctx*/) override { }

  virtual void enterIntersection(TrafficSimDeclParser::IntersectionContext * /*ctx*/) override { }
  virtual void exitIntersection(TrafficSimDeclParser::IntersectionContext * /*ctx*/) override { }

  virtual void enterIntersectionBody(TrafficSimDeclParser::IntersectionBodyContext * /*ctx*/) override { }
  virtual void exitIntersectionBody(TrafficSimDeclParser::IntersectionBodyContext * /*ctx*/) override { }

  virtual void enterTrafficLights(TrafficSimDeclParser::TrafficLightsContext * /*ctx*/) override { }
  virtual void exitTrafficLights(TrafficSimDeclParser::TrafficLightsContext * /*ctx*/) override { }

  virtual void enterTrafficLightsBody(TrafficSimDeclParser::TrafficLightsBodyContext * /*ctx*/) override { }
  virtual void exitTrafficLightsBody(TrafficSimDeclParser::TrafficLightsBodyContext * /*ctx*/) override { }

  virtual void enterTrafficSimulation(TrafficSimDeclParser::TrafficSimulationContext * /*ctx*/) override { }
  virtual void exitTrafficSimulation(TrafficSimDeclParser::TrafficSimulationContext * /*ctx*/) override { }

  virtual void enterTrafficSimulationBodyP1(TrafficSimDeclParser::TrafficSimulationBodyP1Context * /*ctx*/) override { }
  virtual void exitTrafficSimulationBodyP1(TrafficSimDeclParser::TrafficSimulationBodyP1Context * /*ctx*/) override { }

  virtual void enterTrafficSimulationBodyP2(TrafficSimDeclParser::TrafficSimulationBodyP2Context * /*ctx*/) override { }
  virtual void exitTrafficSimulationBodyP2(TrafficSimDeclParser::TrafficSimulationBodyP2Context * /*ctx*/) override { }

  virtual void enterVehicleMovement(TrafficSimDeclParser::VehicleMovementContext * /*ctx*/) override { }
  virtual void exitVehicleMovement(TrafficSimDeclParser::VehicleMovementContext * /*ctx*/) override { }

  virtual void enterVehicleMovementBody(TrafficSimDeclParser::VehicleMovementBodyContext * /*ctx*/) override { }
  virtual void exitVehicleMovementBody(TrafficSimDeclParser::VehicleMovementBodyContext * /*ctx*/) override { }

  virtual void enterVehicleDistributionName(TrafficSimDeclParser::VehicleDistributionNameContext * /*ctx*/) override { }
  virtual void exitVehicleDistributionName(TrafficSimDeclParser::VehicleDistributionNameContext * /*ctx*/) override { }

  virtual void enterVehicleDistribution(TrafficSimDeclParser::VehicleDistributionContext * /*ctx*/) override { }
  virtual void exitVehicleDistribution(TrafficSimDeclParser::VehicleDistributionContext * /*ctx*/) override { }

  virtual void enterVehicleDistributionBody(TrafficSimDeclParser::VehicleDistributionBodyContext * /*ctx*/) override { }
  virtual void exitVehicleDistributionBody(TrafficSimDeclParser::VehicleDistributionBodyContext * /*ctx*/) override { }

  virtual void enterSensor(TrafficSimDeclParser::SensorContext * /*ctx*/) override { }
  virtual void exitSensor(TrafficSimDeclParser::SensorContext * /*ctx*/) override { }

  virtual void enterSensorBody(TrafficSimDeclParser::SensorBodyContext * /*ctx*/) override { }
  virtual void exitSensorBody(TrafficSimDeclParser::SensorBodyContext * /*ctx*/) override { }

  virtual void enterLanes(TrafficSimDeclParser::LanesContext * /*ctx*/) override { }
  virtual void exitLanes(TrafficSimDeclParser::LanesContext * /*ctx*/) override { }

  virtual void enterOuterCon(TrafficSimDeclParser::OuterConContext * /*ctx*/) override { }
  virtual void exitOuterCon(TrafficSimDeclParser::OuterConContext * /*ctx*/) override { }

  virtual void enterStringlist(TrafficSimDeclParser::StringlistContext * /*ctx*/) override { }
  virtual void exitStringlist(TrafficSimDeclParser::StringlistContext * /*ctx*/) override { }

  virtual void enterStringlistBody(TrafficSimDeclParser::StringlistBodyContext * /*ctx*/) override { }
  virtual void exitStringlistBody(TrafficSimDeclParser::StringlistBodyContext * /*ctx*/) override { }

  virtual void enterInnerCon(TrafficSimDeclParser::InnerConContext * /*ctx*/) override { }
  virtual void exitInnerCon(TrafficSimDeclParser::InnerConContext * /*ctx*/) override { }

  virtual void enterStates(TrafficSimDeclParser::StatesContext * /*ctx*/) override { }
  virtual void exitStates(TrafficSimDeclParser::StatesContext * /*ctx*/) override { }

  virtual void enterEdge(TrafficSimDeclParser::EdgeContext * /*ctx*/) override { }
  virtual void exitEdge(TrafficSimDeclParser::EdgeContext * /*ctx*/) override { }

  virtual void enterEdgeBody(TrafficSimDeclParser::EdgeBodyContext * /*ctx*/) override { }
  virtual void exitEdgeBody(TrafficSimDeclParser::EdgeBodyContext * /*ctx*/) override { }

  virtual void enterPhase(TrafficSimDeclParser::PhaseContext * /*ctx*/) override { }
  virtual void exitPhase(TrafficSimDeclParser::PhaseContext * /*ctx*/) override { }

  virtual void enterPhaseBody(TrafficSimDeclParser::PhaseBodyContext * /*ctx*/) override { }
  virtual void exitPhaseBody(TrafficSimDeclParser::PhaseBodyContext * /*ctx*/) override { }

  virtual void enterTransitions(TrafficSimDeclParser::TransitionsContext * /*ctx*/) override { }
  virtual void exitTransitions(TrafficSimDeclParser::TransitionsContext * /*ctx*/) override { }

  virtual void enterTransitionsBody(TrafficSimDeclParser::TransitionsBodyContext * /*ctx*/) override { }
  virtual void exitTransitionsBody(TrafficSimDeclParser::TransitionsBodyContext * /*ctx*/) override { }

  virtual void enterTransition(TrafficSimDeclParser::TransitionContext * /*ctx*/) override { }
  virtual void exitTransition(TrafficSimDeclParser::TransitionContext * /*ctx*/) override { }

  virtual void enterTransitionBody(TrafficSimDeclParser::TransitionBodyContext * /*ctx*/) override { }
  virtual void exitTransitionBody(TrafficSimDeclParser::TransitionBodyContext * /*ctx*/) override { }

  virtual void enterPhases(TrafficSimDeclParser::PhasesContext * /*ctx*/) override { }
  virtual void exitPhases(TrafficSimDeclParser::PhasesContext * /*ctx*/) override { }

  virtual void enterPhasesBody(TrafficSimDeclParser::PhasesBodyContext * /*ctx*/) override { }
  virtual void exitPhasesBody(TrafficSimDeclParser::PhasesBodyContext * /*ctx*/) override { }

  virtual void enterTrafficLight(TrafficSimDeclParser::TrafficLightContext * /*ctx*/) override { }
  virtual void exitTrafficLight(TrafficSimDeclParser::TrafficLightContext * /*ctx*/) override { }

  virtual void enterTrafficLightBody(TrafficSimDeclParser::TrafficLightBodyContext * /*ctx*/) override { }
  virtual void exitTrafficLightBody(TrafficSimDeclParser::TrafficLightBodyContext * /*ctx*/) override { }

  virtual void enterObject(TrafficSimDeclParser::ObjectContext * /*ctx*/) override { }
  virtual void exitObject(TrafficSimDeclParser::ObjectContext * /*ctx*/) override { }

  virtual void enterComponentIdPath(TrafficSimDeclParser::ComponentIdPathContext * /*ctx*/) override { }
  virtual void exitComponentIdPath(TrafficSimDeclParser::ComponentIdPathContext * /*ctx*/) override { }

  virtual void enterSignalIdPath(TrafficSimDeclParser::SignalIdPathContext * /*ctx*/) override { }
  virtual void exitSignalIdPath(TrafficSimDeclParser::SignalIdPathContext * /*ctx*/) override { }

  virtual void enterAttributeIdPath(TrafficSimDeclParser::AttributeIdPathContext * /*ctx*/) override { }
  virtual void exitAttributeIdPath(TrafficSimDeclParser::AttributeIdPathContext * /*ctx*/) override { }

  virtual void enterSignalSend(TrafficSimDeclParser::SignalSendContext * /*ctx*/) override { }
  virtual void exitSignalSend(TrafficSimDeclParser::SignalSendContext * /*ctx*/) override { }

  virtual void enterCommonDecl(TrafficSimDeclParser::CommonDeclContext * /*ctx*/) override { }
  virtual void exitCommonDecl(TrafficSimDeclParser::CommonDeclContext * /*ctx*/) override { }

  virtual void enterImportPathDecl(TrafficSimDeclParser::ImportPathDeclContext * /*ctx*/) override { }
  virtual void exitImportPathDecl(TrafficSimDeclParser::ImportPathDeclContext * /*ctx*/) override { }

  virtual void enterImportPathBody(TrafficSimDeclParser::ImportPathBodyContext * /*ctx*/) override { }
  virtual void exitImportPathBody(TrafficSimDeclParser::ImportPathBodyContext * /*ctx*/) override { }

  virtual void enterImportFileBody(TrafficSimDeclParser::ImportFileBodyContext * /*ctx*/) override { }
  virtual void exitImportFileBody(TrafficSimDeclParser::ImportFileBodyContext * /*ctx*/) override { }

  virtual void enterImportAs(TrafficSimDeclParser::ImportAsContext * /*ctx*/) override { }
  virtual void exitImportAs(TrafficSimDeclParser::ImportAsContext * /*ctx*/) override { }

  virtual void enterTypeDefDecl(TrafficSimDeclParser::TypeDefDeclContext * /*ctx*/) override { }
  virtual void exitTypeDefDecl(TrafficSimDeclParser::TypeDefDeclContext * /*ctx*/) override { }

  virtual void enterTypeDecl(TrafficSimDeclParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(TrafficSimDeclParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterIntTypeDecl(TrafficSimDeclParser::IntTypeDeclContext * /*ctx*/) override { }
  virtual void exitIntTypeDecl(TrafficSimDeclParser::IntTypeDeclContext * /*ctx*/) override { }

  virtual void enterRealTypeDecl(TrafficSimDeclParser::RealTypeDeclContext * /*ctx*/) override { }
  virtual void exitRealTypeDecl(TrafficSimDeclParser::RealTypeDeclContext * /*ctx*/) override { }

  virtual void enterEnumTypeDecl(TrafficSimDeclParser::EnumTypeDeclContext * /*ctx*/) override { }
  virtual void exitEnumTypeDecl(TrafficSimDeclParser::EnumTypeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(TrafficSimDeclParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(TrafficSimDeclParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterLiteralValue(TrafficSimDeclParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(TrafficSimDeclParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterSignalParamName(TrafficSimDeclParser::SignalParamNameContext * /*ctx*/) override { }
  virtual void exitSignalParamName(TrafficSimDeclParser::SignalParamNameContext * /*ctx*/) override { }

  virtual void enterAttributeName(TrafficSimDeclParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(TrafficSimDeclParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterToPortName(TrafficSimDeclParser::ToPortNameContext * /*ctx*/) override { }
  virtual void exitToPortName(TrafficSimDeclParser::ToPortNameContext * /*ctx*/) override { }

  virtual void enterAttributeAssignStatement(TrafficSimDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }
  virtual void exitAttributeAssignStatement(TrafficSimDeclParser::AttributeAssignStatementContext * /*ctx*/) override { }

  virtual void enterLocalAssignStatement(TrafficSimDeclParser::LocalAssignStatementContext * /*ctx*/) override { }
  virtual void exitLocalAssignStatement(TrafficSimDeclParser::LocalAssignStatementContext * /*ctx*/) override { }

  virtual void enterSendToStatement(TrafficSimDeclParser::SendToStatementContext * /*ctx*/) override { }
  virtual void exitSendToStatement(TrafficSimDeclParser::SendToStatementContext * /*ctx*/) override { }

  virtual void enterSingleAssignment(TrafficSimDeclParser::SingleAssignmentContext * /*ctx*/) override { }
  virtual void exitSingleAssignment(TrafficSimDeclParser::SingleAssignmentContext * /*ctx*/) override { }

  virtual void enterMultiAssignment(TrafficSimDeclParser::MultiAssignmentContext * /*ctx*/) override { }
  virtual void exitMultiAssignment(TrafficSimDeclParser::MultiAssignmentContext * /*ctx*/) override { }

  virtual void enterSignalDecl(TrafficSimDeclParser::SignalDeclContext * /*ctx*/) override { }
  virtual void exitSignalDecl(TrafficSimDeclParser::SignalDeclContext * /*ctx*/) override { }

  virtual void enterParamDecl(TrafficSimDeclParser::ParamDeclContext * /*ctx*/) override { }
  virtual void exitParamDecl(TrafficSimDeclParser::ParamDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(TrafficSimDeclParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(TrafficSimDeclParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionParameters(TrafficSimDeclParser::FunctionParametersContext * /*ctx*/) override { }
  virtual void exitFunctionParameters(TrafficSimDeclParser::FunctionParametersContext * /*ctx*/) override { }

  virtual void enterFunctionCall(TrafficSimDeclParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(TrafficSimDeclParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallBody(TrafficSimDeclParser::FunctionCallBodyContext * /*ctx*/) override { }
  virtual void exitFunctionCallBody(TrafficSimDeclParser::FunctionCallBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallBodyOptional(TrafficSimDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }
  virtual void exitFunctionCallBodyOptional(TrafficSimDeclParser::FunctionCallBodyOptionalContext * /*ctx*/) override { }

  virtual void enterContextID(TrafficSimDeclParser::ContextIDContext * /*ctx*/) override { }
  virtual void exitContextID(TrafficSimDeclParser::ContextIDContext * /*ctx*/) override { }

  virtual void enterTriggerDecl(TrafficSimDeclParser::TriggerDeclContext * /*ctx*/) override { }
  virtual void exitTriggerDecl(TrafficSimDeclParser::TriggerDeclContext * /*ctx*/) override { }

  virtual void enterThisDecl(TrafficSimDeclParser::ThisDeclContext * /*ctx*/) override { }
  virtual void exitThisDecl(TrafficSimDeclParser::ThisDeclContext * /*ctx*/) override { }

  virtual void enterPortDecl(TrafficSimDeclParser::PortDeclContext * /*ctx*/) override { }
  virtual void exitPortDecl(TrafficSimDeclParser::PortDeclContext * /*ctx*/) override { }

  virtual void enterNameDecl(TrafficSimDeclParser::NameDeclContext * /*ctx*/) override { }
  virtual void exitNameDecl(TrafficSimDeclParser::NameDeclContext * /*ctx*/) override { }

  virtual void enterIdPath(TrafficSimDeclParser::IdPathContext * /*ctx*/) override { }
  virtual void exitIdPath(TrafficSimDeclParser::IdPathContext * /*ctx*/) override { }

  virtual void enterStatementDecl(TrafficSimDeclParser::StatementDeclContext * /*ctx*/) override { }
  virtual void exitStatementDecl(TrafficSimDeclParser::StatementDeclContext * /*ctx*/) override { }

  virtual void enterStatementBody(TrafficSimDeclParser::StatementBodyContext * /*ctx*/) override { }
  virtual void exitStatementBody(TrafficSimDeclParser::StatementBodyContext * /*ctx*/) override { }

  virtual void enterFunctionCallStatement(TrafficSimDeclParser::FunctionCallStatementContext * /*ctx*/) override { }
  virtual void exitFunctionCallStatement(TrafficSimDeclParser::FunctionCallStatementContext * /*ctx*/) override { }

  virtual void enterNestedStatementBody(TrafficSimDeclParser::NestedStatementBodyContext * /*ctx*/) override { }
  virtual void exitNestedStatementBody(TrafficSimDeclParser::NestedStatementBodyContext * /*ctx*/) override { }

  virtual void enterReturnStatement(TrafficSimDeclParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(TrafficSimDeclParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(TrafficSimDeclParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(TrafficSimDeclParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterOperation(TrafficSimDeclParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(TrafficSimDeclParser::OperationContext * /*ctx*/) override { }

  virtual void enterOperationOptional(TrafficSimDeclParser::OperationOptionalContext * /*ctx*/) override { }
  virtual void exitOperationOptional(TrafficSimDeclParser::OperationOptionalContext * /*ctx*/) override { }

  virtual void enterExpression(TrafficSimDeclParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(TrafficSimDeclParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionOptional(TrafficSimDeclParser::ExpressionOptionalContext * /*ctx*/) override { }
  virtual void exitExpressionOptional(TrafficSimDeclParser::ExpressionOptionalContext * /*ctx*/) override { }

  virtual void enterConditionalStatement(TrafficSimDeclParser::ConditionalStatementContext * /*ctx*/) override { }
  virtual void exitConditionalStatement(TrafficSimDeclParser::ConditionalStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(TrafficSimDeclParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(TrafficSimDeclParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfEuT(TrafficSimDeclParser::IfEuTContext * /*ctx*/) override { }
  virtual void exitIfEuT(TrafficSimDeclParser::IfEuTContext * /*ctx*/) override { }

  virtual void enterElseStatement(TrafficSimDeclParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(TrafficSimDeclParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(TrafficSimDeclParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(TrafficSimDeclParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterSwitchPuT(TrafficSimDeclParser::SwitchPuTContext * /*ctx*/) override { }
  virtual void exitSwitchPuT(TrafficSimDeclParser::SwitchPuTContext * /*ctx*/) override { }

  virtual void enterCaseStatement(TrafficSimDeclParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(TrafficSimDeclParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(TrafficSimDeclParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(TrafficSimDeclParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterAtom(TrafficSimDeclParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(TrafficSimDeclParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

