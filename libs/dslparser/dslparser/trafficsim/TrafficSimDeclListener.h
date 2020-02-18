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
#include "TrafficSimDeclParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TrafficSimDeclParser.
 */
class  TrafficSimDeclListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(TrafficSimDeclParser::StartContext *ctx) = 0;
  virtual void exitStart(TrafficSimDeclParser::StartContext *ctx) = 0;

  virtual void enterStartArm(TrafficSimDeclParser::StartArmContext *ctx) = 0;
  virtual void exitStartArm(TrafficSimDeclParser::StartArmContext *ctx) = 0;

  virtual void enterEnd(TrafficSimDeclParser::EndContext *ctx) = 0;
  virtual void exitEnd(TrafficSimDeclParser::EndContext *ctx) = 0;

  virtual void enterStep(TrafficSimDeclParser::StepContext *ctx) = 0;
  virtual void exitStep(TrafficSimDeclParser::StepContext *ctx) = 0;

  virtual void enterStepBody(TrafficSimDeclParser::StepBodyContext *ctx) = 0;
  virtual void exitStepBody(TrafficSimDeclParser::StepBodyContext *ctx) = 0;

  virtual void enterIntersection(TrafficSimDeclParser::IntersectionContext *ctx) = 0;
  virtual void exitIntersection(TrafficSimDeclParser::IntersectionContext *ctx) = 0;

  virtual void enterIntersectionBody(TrafficSimDeclParser::IntersectionBodyContext *ctx) = 0;
  virtual void exitIntersectionBody(TrafficSimDeclParser::IntersectionBodyContext *ctx) = 0;

  virtual void enterTrafficLights(TrafficSimDeclParser::TrafficLightsContext *ctx) = 0;
  virtual void exitTrafficLights(TrafficSimDeclParser::TrafficLightsContext *ctx) = 0;

  virtual void enterTrafficLightsBody(TrafficSimDeclParser::TrafficLightsBodyContext *ctx) = 0;
  virtual void exitTrafficLightsBody(TrafficSimDeclParser::TrafficLightsBodyContext *ctx) = 0;

  virtual void enterTrafficSimulation(TrafficSimDeclParser::TrafficSimulationContext *ctx) = 0;
  virtual void exitTrafficSimulation(TrafficSimDeclParser::TrafficSimulationContext *ctx) = 0;

  virtual void enterTrafficSimulationBodyP1(TrafficSimDeclParser::TrafficSimulationBodyP1Context *ctx) = 0;
  virtual void exitTrafficSimulationBodyP1(TrafficSimDeclParser::TrafficSimulationBodyP1Context *ctx) = 0;

  virtual void enterTrafficSimulationBodyP2(TrafficSimDeclParser::TrafficSimulationBodyP2Context *ctx) = 0;
  virtual void exitTrafficSimulationBodyP2(TrafficSimDeclParser::TrafficSimulationBodyP2Context *ctx) = 0;

  virtual void enterVehicleMovement(TrafficSimDeclParser::VehicleMovementContext *ctx) = 0;
  virtual void exitVehicleMovement(TrafficSimDeclParser::VehicleMovementContext *ctx) = 0;

  virtual void enterVehicleMovementBody(TrafficSimDeclParser::VehicleMovementBodyContext *ctx) = 0;
  virtual void exitVehicleMovementBody(TrafficSimDeclParser::VehicleMovementBodyContext *ctx) = 0;

  virtual void enterVehicleDistributionName(TrafficSimDeclParser::VehicleDistributionNameContext *ctx) = 0;
  virtual void exitVehicleDistributionName(TrafficSimDeclParser::VehicleDistributionNameContext *ctx) = 0;

  virtual void enterVehicleDistribution(TrafficSimDeclParser::VehicleDistributionContext *ctx) = 0;
  virtual void exitVehicleDistribution(TrafficSimDeclParser::VehicleDistributionContext *ctx) = 0;

  virtual void enterVehicleDistributionBody(TrafficSimDeclParser::VehicleDistributionBodyContext *ctx) = 0;
  virtual void exitVehicleDistributionBody(TrafficSimDeclParser::VehicleDistributionBodyContext *ctx) = 0;

  virtual void enterSensor(TrafficSimDeclParser::SensorContext *ctx) = 0;
  virtual void exitSensor(TrafficSimDeclParser::SensorContext *ctx) = 0;

  virtual void enterSensorBody(TrafficSimDeclParser::SensorBodyContext *ctx) = 0;
  virtual void exitSensorBody(TrafficSimDeclParser::SensorBodyContext *ctx) = 0;

  virtual void enterLanes(TrafficSimDeclParser::LanesContext *ctx) = 0;
  virtual void exitLanes(TrafficSimDeclParser::LanesContext *ctx) = 0;

  virtual void enterOuterCon(TrafficSimDeclParser::OuterConContext *ctx) = 0;
  virtual void exitOuterCon(TrafficSimDeclParser::OuterConContext *ctx) = 0;

  virtual void enterStringlist(TrafficSimDeclParser::StringlistContext *ctx) = 0;
  virtual void exitStringlist(TrafficSimDeclParser::StringlistContext *ctx) = 0;

  virtual void enterStringlistBody(TrafficSimDeclParser::StringlistBodyContext *ctx) = 0;
  virtual void exitStringlistBody(TrafficSimDeclParser::StringlistBodyContext *ctx) = 0;

  virtual void enterInnerCon(TrafficSimDeclParser::InnerConContext *ctx) = 0;
  virtual void exitInnerCon(TrafficSimDeclParser::InnerConContext *ctx) = 0;

  virtual void enterStates(TrafficSimDeclParser::StatesContext *ctx) = 0;
  virtual void exitStates(TrafficSimDeclParser::StatesContext *ctx) = 0;

  virtual void enterEdge(TrafficSimDeclParser::EdgeContext *ctx) = 0;
  virtual void exitEdge(TrafficSimDeclParser::EdgeContext *ctx) = 0;

  virtual void enterEdgeBody(TrafficSimDeclParser::EdgeBodyContext *ctx) = 0;
  virtual void exitEdgeBody(TrafficSimDeclParser::EdgeBodyContext *ctx) = 0;

  virtual void enterPhase(TrafficSimDeclParser::PhaseContext *ctx) = 0;
  virtual void exitPhase(TrafficSimDeclParser::PhaseContext *ctx) = 0;

  virtual void enterPhaseBody(TrafficSimDeclParser::PhaseBodyContext *ctx) = 0;
  virtual void exitPhaseBody(TrafficSimDeclParser::PhaseBodyContext *ctx) = 0;

  virtual void enterTransitions(TrafficSimDeclParser::TransitionsContext *ctx) = 0;
  virtual void exitTransitions(TrafficSimDeclParser::TransitionsContext *ctx) = 0;

  virtual void enterTransitionsBody(TrafficSimDeclParser::TransitionsBodyContext *ctx) = 0;
  virtual void exitTransitionsBody(TrafficSimDeclParser::TransitionsBodyContext *ctx) = 0;

  virtual void enterTransition(TrafficSimDeclParser::TransitionContext *ctx) = 0;
  virtual void exitTransition(TrafficSimDeclParser::TransitionContext *ctx) = 0;

  virtual void enterTransitionBody(TrafficSimDeclParser::TransitionBodyContext *ctx) = 0;
  virtual void exitTransitionBody(TrafficSimDeclParser::TransitionBodyContext *ctx) = 0;

  virtual void enterPhases(TrafficSimDeclParser::PhasesContext *ctx) = 0;
  virtual void exitPhases(TrafficSimDeclParser::PhasesContext *ctx) = 0;

  virtual void enterPhasesBody(TrafficSimDeclParser::PhasesBodyContext *ctx) = 0;
  virtual void exitPhasesBody(TrafficSimDeclParser::PhasesBodyContext *ctx) = 0;

  virtual void enterTrafficLight(TrafficSimDeclParser::TrafficLightContext *ctx) = 0;
  virtual void exitTrafficLight(TrafficSimDeclParser::TrafficLightContext *ctx) = 0;

  virtual void enterTrafficLightBody(TrafficSimDeclParser::TrafficLightBodyContext *ctx) = 0;
  virtual void exitTrafficLightBody(TrafficSimDeclParser::TrafficLightBodyContext *ctx) = 0;

  virtual void enterObject(TrafficSimDeclParser::ObjectContext *ctx) = 0;
  virtual void exitObject(TrafficSimDeclParser::ObjectContext *ctx) = 0;

  virtual void enterComponentIdPath(TrafficSimDeclParser::ComponentIdPathContext *ctx) = 0;
  virtual void exitComponentIdPath(TrafficSimDeclParser::ComponentIdPathContext *ctx) = 0;

  virtual void enterSignalIdPath(TrafficSimDeclParser::SignalIdPathContext *ctx) = 0;
  virtual void exitSignalIdPath(TrafficSimDeclParser::SignalIdPathContext *ctx) = 0;

  virtual void enterAttributeIdPath(TrafficSimDeclParser::AttributeIdPathContext *ctx) = 0;
  virtual void exitAttributeIdPath(TrafficSimDeclParser::AttributeIdPathContext *ctx) = 0;

  virtual void enterSignalSend(TrafficSimDeclParser::SignalSendContext *ctx) = 0;
  virtual void exitSignalSend(TrafficSimDeclParser::SignalSendContext *ctx) = 0;

  virtual void enterCommonDecl(TrafficSimDeclParser::CommonDeclContext *ctx) = 0;
  virtual void exitCommonDecl(TrafficSimDeclParser::CommonDeclContext *ctx) = 0;

  virtual void enterImportPathDecl(TrafficSimDeclParser::ImportPathDeclContext *ctx) = 0;
  virtual void exitImportPathDecl(TrafficSimDeclParser::ImportPathDeclContext *ctx) = 0;

  virtual void enterImportPathBody(TrafficSimDeclParser::ImportPathBodyContext *ctx) = 0;
  virtual void exitImportPathBody(TrafficSimDeclParser::ImportPathBodyContext *ctx) = 0;

  virtual void enterImportFileBody(TrafficSimDeclParser::ImportFileBodyContext *ctx) = 0;
  virtual void exitImportFileBody(TrafficSimDeclParser::ImportFileBodyContext *ctx) = 0;

  virtual void enterImportAs(TrafficSimDeclParser::ImportAsContext *ctx) = 0;
  virtual void exitImportAs(TrafficSimDeclParser::ImportAsContext *ctx) = 0;

  virtual void enterTypeDefDecl(TrafficSimDeclParser::TypeDefDeclContext *ctx) = 0;
  virtual void exitTypeDefDecl(TrafficSimDeclParser::TypeDefDeclContext *ctx) = 0;

  virtual void enterTypeDecl(TrafficSimDeclParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(TrafficSimDeclParser::TypeDeclContext *ctx) = 0;

  virtual void enterIntTypeDecl(TrafficSimDeclParser::IntTypeDeclContext *ctx) = 0;
  virtual void exitIntTypeDecl(TrafficSimDeclParser::IntTypeDeclContext *ctx) = 0;

  virtual void enterRealTypeDecl(TrafficSimDeclParser::RealTypeDeclContext *ctx) = 0;
  virtual void exitRealTypeDecl(TrafficSimDeclParser::RealTypeDeclContext *ctx) = 0;

  virtual void enterEnumTypeDecl(TrafficSimDeclParser::EnumTypeDeclContext *ctx) = 0;
  virtual void exitEnumTypeDecl(TrafficSimDeclParser::EnumTypeDeclContext *ctx) = 0;

  virtual void enterAttributeDecl(TrafficSimDeclParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(TrafficSimDeclParser::AttributeDeclContext *ctx) = 0;

  virtual void enterLiteralValue(TrafficSimDeclParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(TrafficSimDeclParser::LiteralValueContext *ctx) = 0;

  virtual void enterSignalParamName(TrafficSimDeclParser::SignalParamNameContext *ctx) = 0;
  virtual void exitSignalParamName(TrafficSimDeclParser::SignalParamNameContext *ctx) = 0;

  virtual void enterAttributeName(TrafficSimDeclParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(TrafficSimDeclParser::AttributeNameContext *ctx) = 0;

  virtual void enterToPortName(TrafficSimDeclParser::ToPortNameContext *ctx) = 0;
  virtual void exitToPortName(TrafficSimDeclParser::ToPortNameContext *ctx) = 0;

  virtual void enterAttributeAssignStatement(TrafficSimDeclParser::AttributeAssignStatementContext *ctx) = 0;
  virtual void exitAttributeAssignStatement(TrafficSimDeclParser::AttributeAssignStatementContext *ctx) = 0;

  virtual void enterLocalAssignStatement(TrafficSimDeclParser::LocalAssignStatementContext *ctx) = 0;
  virtual void exitLocalAssignStatement(TrafficSimDeclParser::LocalAssignStatementContext *ctx) = 0;

  virtual void enterSendToStatement(TrafficSimDeclParser::SendToStatementContext *ctx) = 0;
  virtual void exitSendToStatement(TrafficSimDeclParser::SendToStatementContext *ctx) = 0;

  virtual void enterSingleAssignment(TrafficSimDeclParser::SingleAssignmentContext *ctx) = 0;
  virtual void exitSingleAssignment(TrafficSimDeclParser::SingleAssignmentContext *ctx) = 0;

  virtual void enterMultiAssignment(TrafficSimDeclParser::MultiAssignmentContext *ctx) = 0;
  virtual void exitMultiAssignment(TrafficSimDeclParser::MultiAssignmentContext *ctx) = 0;

  virtual void enterSignalDecl(TrafficSimDeclParser::SignalDeclContext *ctx) = 0;
  virtual void exitSignalDecl(TrafficSimDeclParser::SignalDeclContext *ctx) = 0;

  virtual void enterParamDecl(TrafficSimDeclParser::ParamDeclContext *ctx) = 0;
  virtual void exitParamDecl(TrafficSimDeclParser::ParamDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(TrafficSimDeclParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(TrafficSimDeclParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionParameters(TrafficSimDeclParser::FunctionParametersContext *ctx) = 0;
  virtual void exitFunctionParameters(TrafficSimDeclParser::FunctionParametersContext *ctx) = 0;

  virtual void enterFunctionCall(TrafficSimDeclParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(TrafficSimDeclParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallBody(TrafficSimDeclParser::FunctionCallBodyContext *ctx) = 0;
  virtual void exitFunctionCallBody(TrafficSimDeclParser::FunctionCallBodyContext *ctx) = 0;

  virtual void enterFunctionCallBodyOptional(TrafficSimDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;
  virtual void exitFunctionCallBodyOptional(TrafficSimDeclParser::FunctionCallBodyOptionalContext *ctx) = 0;

  virtual void enterContextID(TrafficSimDeclParser::ContextIDContext *ctx) = 0;
  virtual void exitContextID(TrafficSimDeclParser::ContextIDContext *ctx) = 0;

  virtual void enterTriggerDecl(TrafficSimDeclParser::TriggerDeclContext *ctx) = 0;
  virtual void exitTriggerDecl(TrafficSimDeclParser::TriggerDeclContext *ctx) = 0;

  virtual void enterThisDecl(TrafficSimDeclParser::ThisDeclContext *ctx) = 0;
  virtual void exitThisDecl(TrafficSimDeclParser::ThisDeclContext *ctx) = 0;

  virtual void enterPortDecl(TrafficSimDeclParser::PortDeclContext *ctx) = 0;
  virtual void exitPortDecl(TrafficSimDeclParser::PortDeclContext *ctx) = 0;

  virtual void enterNameDecl(TrafficSimDeclParser::NameDeclContext *ctx) = 0;
  virtual void exitNameDecl(TrafficSimDeclParser::NameDeclContext *ctx) = 0;

  virtual void enterIdPath(TrafficSimDeclParser::IdPathContext *ctx) = 0;
  virtual void exitIdPath(TrafficSimDeclParser::IdPathContext *ctx) = 0;

  virtual void enterStatementDecl(TrafficSimDeclParser::StatementDeclContext *ctx) = 0;
  virtual void exitStatementDecl(TrafficSimDeclParser::StatementDeclContext *ctx) = 0;

  virtual void enterStatementBody(TrafficSimDeclParser::StatementBodyContext *ctx) = 0;
  virtual void exitStatementBody(TrafficSimDeclParser::StatementBodyContext *ctx) = 0;

  virtual void enterFunctionCallStatement(TrafficSimDeclParser::FunctionCallStatementContext *ctx) = 0;
  virtual void exitFunctionCallStatement(TrafficSimDeclParser::FunctionCallStatementContext *ctx) = 0;

  virtual void enterNestedStatementBody(TrafficSimDeclParser::NestedStatementBodyContext *ctx) = 0;
  virtual void exitNestedStatementBody(TrafficSimDeclParser::NestedStatementBodyContext *ctx) = 0;

  virtual void enterReturnStatement(TrafficSimDeclParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(TrafficSimDeclParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBreakStatement(TrafficSimDeclParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(TrafficSimDeclParser::BreakStatementContext *ctx) = 0;

  virtual void enterOperation(TrafficSimDeclParser::OperationContext *ctx) = 0;
  virtual void exitOperation(TrafficSimDeclParser::OperationContext *ctx) = 0;

  virtual void enterOperationOptional(TrafficSimDeclParser::OperationOptionalContext *ctx) = 0;
  virtual void exitOperationOptional(TrafficSimDeclParser::OperationOptionalContext *ctx) = 0;

  virtual void enterExpression(TrafficSimDeclParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(TrafficSimDeclParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionOptional(TrafficSimDeclParser::ExpressionOptionalContext *ctx) = 0;
  virtual void exitExpressionOptional(TrafficSimDeclParser::ExpressionOptionalContext *ctx) = 0;

  virtual void enterConditionalStatement(TrafficSimDeclParser::ConditionalStatementContext *ctx) = 0;
  virtual void exitConditionalStatement(TrafficSimDeclParser::ConditionalStatementContext *ctx) = 0;

  virtual void enterIfStatement(TrafficSimDeclParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(TrafficSimDeclParser::IfStatementContext *ctx) = 0;

  virtual void enterIfEuT(TrafficSimDeclParser::IfEuTContext *ctx) = 0;
  virtual void exitIfEuT(TrafficSimDeclParser::IfEuTContext *ctx) = 0;

  virtual void enterElseStatement(TrafficSimDeclParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(TrafficSimDeclParser::ElseStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(TrafficSimDeclParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(TrafficSimDeclParser::SwitchStatementContext *ctx) = 0;

  virtual void enterSwitchPuT(TrafficSimDeclParser::SwitchPuTContext *ctx) = 0;
  virtual void exitSwitchPuT(TrafficSimDeclParser::SwitchPuTContext *ctx) = 0;

  virtual void enterCaseStatement(TrafficSimDeclParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(TrafficSimDeclParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(TrafficSimDeclParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(TrafficSimDeclParser::DefaultStatementContext *ctx) = 0;

  virtual void enterAtom(TrafficSimDeclParser::AtomContext *ctx) = 0;
  virtual void exitAtom(TrafficSimDeclParser::AtomContext *ctx) = 0;


};

