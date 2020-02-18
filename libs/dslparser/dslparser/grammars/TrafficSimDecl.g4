grammar TrafficSimDecl;
import CommonDecl;

/*Created in project Ur:ban*/

start: Start COLON startNumber=INT SEMI;
startArm: StartArm COLON n=STRING SEMI;
end: End COLON endNumber=INT SEMI;

step: Step LBRACE stepBody  RBRACE;
stepBody: (start stepBody| vehicleMovement stepBody| end stepBody|);

intersection: Intersection LBRACE intersectionBody RBRACE;
intersectionBody :
        (
        edge intersectionBody |
        sensor intersectionBody |
        object intersectionBody |
        NameID COLON n=ID SEMI intersectionBody |
        Label COLON l=STRING SEMI intersectionBody |
        HasTrafficLight COLON hasTrafficLight=(TrueID | FalseID) SEMI intersectionBody |
        Accident COLON accident=REAL SEMI intersectionBody |
        NeighboringTrafficLights trafficLights SEMI intersectionBody |
        )
        ;

trafficLights: COLON LBRACKET (trafficLight trafficLightsBody | ) RBRACKET;
trafficLightsBody: COMMA trafficLight trafficLightsBody |;

trafficSimulation: TRAFFICSIMULATION LBRACE trafficSimulationBodyP1 trafficSimulationBodyP2 RBRACE;
trafficSimulationBodyP1: intersection trafficSimulationBodyP1 |;
trafficSimulationBodyP2: step trafficSimulationBodyP2 |;

vehicleMovement: VehicleMovement LBRACE vehicleMovementBody RBRACE;
vehicleMovementBody:
     (
     startArm vehicleMovementBody|
     VehiclePerHour COLON vehiclePerHour=REAL SEMI vehicleMovementBody|
     vehicleDistributionName vehicleMovementBody|
     )
     ;

vehicleDistributionName: VehicleDistribution COLON vehDist=STRING SEMI;

vehicleDistribution: LVehicleDistribution LBRACE vehicleDistributionBody RBRACE;
vehicleDistributionBody:
        (
        NameID COLON n=ID SEMI vehicleDistributionBody|
        Bicycle COLON bicycle=REAL SEMI vehicleDistributionBody|
        Bus COLON bus=REAL SEMI vehicleDistributionBody|
        Moped COLON moped=REAL SEMI vehicleDistributionBody|
        Motorcycle COLON motorcyc=REAL SEMI vehicleDistributionBody|
        Car COLON car=REAL SEMI vehicleDistributionBody|
        Emergency COLON emerg=REAL SEMI vehicleDistributionBody|
        Truck COLON truck=REAL SEMI vehicleDistributionBody|
        )
        ;

sensor: Sensor LBRACE sensorBody RBRACE;
sensorBody:
     (
     NameID COLON n=ID SEMI sensorBody|
     TypeID COLON t=STRING SEMI sensorBody|
     Measured Arm COLON mArm=STRING SEMI sensorBody|
     Measured Lane COLON mLane=STRING SEMI sensorBody|
     Message COLON mes=STRING SEMI sensorBody|
     )
     ;

lanes: Lanes COLON streetlanes=STRING;

outerCon: OuterConnection COLON outer=STRING;
stringlist: COLON LBRACKET (STRING stringlistBody |) RBRACKET;
stringlistBody: COMMA STRING stringlistBody |;
innerCon: InnerConnections stringlist;
states: States stringlist;

edge: Arm LBRACE edgeBody RBRACE;
edgeBody:
        (
        NameID COLON n=ID SEMI edgeBody|
        outerCon SEMI edgeBody|
        innerCon SEMI edgeBody|
        lanes SEMI edgeBody|
        states SEMI edgeBody|
        )
        ;

phase: Phase LBRACE phaseBody RBRACE;
phaseBody:
        (
        Duration COLON dur=INT SEMI phaseBody|
        MinDur COLON minDur=INT SEMI phaseBody|
        MaxDur COLON maxDur=INT SEMI phaseBody|
        NameID COLON name=STRING SEMI phaseBody|
        edge phaseBody|
        Factor COLON factor=REAL SEMI phaseBody|
        )
        ;

transitions: COLON LBRACKET (transition transitionsBody|) RBRACKET;
transitionsBody: COMMA transition transitionsBody |;

transition: Transition LBRACE transitionBody RBRACE;
transitionBody:
        (TransitionPhases phases SEMI transitionBody |
        Trigger stringlist SEMI transitionBody |
        Start Phase startPhase=phase SEMI transitionBody |
        End Phase endPhase=phase SEMI transitionBody |
        )
        ;

phases: COLON LBRACKET (phase phasesBody|) RBRACKET;
phasesBody: COMMA phase phasesBody |;

trafficLight: TrafficLight LBRACE trafficLightBody RBRACE;
trafficLightBody:
        (Transitions transitions SEMI trafficLightBody|
        NameID COLON name=ID SEMI trafficLightBody|
        TypeID COLON type=STRING SEMI trafficLightBody|
        Duration COLON dur=INT SEMI trafficLightBody|
        Turns COLON turns=INT SEMI trafficLightBody|
        Phases phases SEMI trafficLightBody|
        )
        ;

object: trafficLight | vehicleDistribution; 

TRAFFICSIMULATION: 'TrafficSimulation';
Sensor: 'Sensor';
Intersection: 'Intersection';
Step: 'Step';
Arm: 'Arm';
HasTrafficLight: 'hasTrafficLight';
Accident: 'accident';
NeighboringTrafficLights: 'neighboringTrafficLights';
TrafficLight: 'TrafficLight';
Turns: 'turns';
Lanes: 'lanes';
States: 'states';
InnerConnections: 'innerConnections';
OuterConnection: 'outerConnection';
Duration: 'duration';
MinDur: 'minDur';
MaxDur: 'maxDur';
Factor: 'factor';
Measured: 'measured';
Lane: 'Lane';
Message: 'message';
VehicleMovement: 'VehicleMovement';
Phase: 'Phase';
Phases: 'phases';
TransitionPhases: 'transitionPhases';
Transition: 'Transition';
Transitions: 'transitions';
Trigger: 'trigger';
VehiclePerHour: 'vehiclePerHour';
VehicleDistribution: 'vehicleDistribution';
LVehicleDistribution: 'VehicleDistribution';
Label: 'label';

Bicycle: 'bicycle';
Bus: 'bus';
Moped: 'moped';
Motorcycle: 'motorcycle';
Car: 'car';
Emergency: 'emergency';
Truck: 'truck';

Start: 'start';
StartArm: 'startArm';
End: 'end';
