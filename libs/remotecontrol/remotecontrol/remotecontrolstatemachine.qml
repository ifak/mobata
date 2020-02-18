import QtQml 2.2
import QtQml.StateMachine 1.0

StateMachine {
  id: remoteControlStateMachine
  initialState: initState
  running: true

  property bool resetRequest: false;
  signal stoppedStateFinished();

  State {
    id: initState

    onEntered:{
      intern.setCurrentState("InitState");
      console.log("InitState entered.");
    }

    SignalTransition {
      targetState: idleState
      signal: pRemote.remoteControlOpen
      guard: {
        pControl.remoteControlOpen();
        return true;
      }
    }
  }

  State {
    id: idleState

    onEntered:{
      resetRequest=false;
      intern.setCurrentState("IdleState");
      console.log("IdleState entered.");
    }

    SignalTransition {
      targetState: workingState
      signal: intern.remoteSetup
      guard:{
        intern.setupControl(setupArgs);
        return true;
      }
    }

    SignalTransition {
      targetState: resettingState
      signal: intern.remoteReset
      guard:{
        intern.resetControl();
        console.log("remoteReset from IdleState -> ResettingState executed.");
        return true;
      }
    }

    SignalTransition{
      targetState: initState
      signal: intern.remoteRemoteControlClose
      guard: {
        intern.controlRemoteControlClose();
        return true;
      }
    }
  }

  State{
    id: workingState
    initialState: setuppingState

    State {
      id: setuppingState
      initialState: setupControlRequState

      onEntered: console.log("setupping state entered.")

      SignalTransition{
        targetState: resettingState
        signal: intern.remoteReset
        guard:{
          intern.resetControl();
          return true;
        }
      }

      State{
        id: setupControlRequState
        onEntered:{
          intern.setCurrentState("SetupControlRequState");
          intern.startControlSetupedTimer();
          console.log("SetupControlRequState state entered.")
        }

        SignalTransition{
          targetState: setuppingFinalState
          signal: intern.controlSetuped
          guard:{
            if(value===false)
              return false;

            intern.setupedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: setupErrorState
          signal: pControl.controlSetuped
          guard:{
            if(value===true)
              return false;

            intern.setupedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: setupErrorState
          signal: intern.controlSetupedTimeout
          guard:{
            intern.setupedRemote(false, "no controlSetuped event occured!");
            return true;
          }
        }
      }

      State{
        id: setupErrorState
        onEntered:{
          intern.setCurrentState("SetupErrorState");
          console.log("SetupErrorState state entered.")
        }
      }

      FinalState{
        id: setuppingFinalState
        onEntered:{
          intern.setCurrentState("SetuppingFinalState");
          console.log("SetuppingFinalState state entered.")
        }
      }

      SignalTransition{
        targetState: setupedState
        signal: setuppingState.finished
      }
    }

    State {
      id: setupedState
      onEntered: {
        intern.setCurrentState("SetupedState");
        console.log("SetupedState entered.");
      }

      SignalTransition
      {
        targetState: startingState
        signal: intern.remoteStart
        guard:{
          intern.startControl();
          return true;
        }
      }

      SignalTransition{
        targetState: resettingState
        signal: intern.remoteReset
        guard:{
          intern.resetControl();
          return true;
        }
      }
    }

    State {
      id: startingState
      initialState: startControlRequState

      onEntered: console.log("starting state entered.")

      SignalTransition{
        targetState: stoppingState
        signal: intern.remoteReset
        guard:{
          intern.stopControl();
          resetRequest=true;
          return true;
        }
      }

      State{
        id: startControlRequState
        onEntered:{
          intern.setCurrentState("StartControlRequState");
          intern.startControlStartedTimer();
          console.log("StartControlRequState state entered.")
        }

        SignalTransition{
          targetState: startingFinalState
          signal: intern.controlStarted
          guard:{
            if(value===false)
              return false;

            intern.startedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: startErrorState
          signal: pControl.controlStarted
          guard:{
            if(value===true)
              return false;

            intern.startedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: startErrorState
          signal: intern.controlStartedTimeout
          guard:{
            intern.startedRemote(false, "no controlStarted event occured!");
            return true;
          }
        }
      }

      State{
        id: startErrorState
        onEntered:{
          intern.setCurrentState("StartErrorState");
          console.log("StartErrorState state entered.")
        }
      }

      FinalState{
        id: startingFinalState
        onEntered:{
          intern.setCurrentState("StartingFinalState");
          console.log("StartingFinalState state entered.")
        }
      }

      SignalTransition{
        targetState: runningState
        signal: startingState.finished
      }
    }

    State {
      id: runningState
      onEntered: {
        intern.setCurrentState("RunningState");
        console.log("RunningState entered.");
      }

      SignalTransition
      {
        targetState: stoppingState
        signal: intern.remoteStop
        guard:{
          intern.stopControl();
          return true;
        }
      }

      SignalTransition
      {
        targetState: stoppingState
        signal: intern.remoteReset
        guard:{
          intern.stopControl();
          resetRequest=true;
          return true;
        }
      }
    }

    State {
      id: stoppingState
      initialState: stopControlRequState

      onEntered: console.log("stopping state entered.")

      State{
        id: stopControlRequState
        onEntered:{
          intern.setCurrentState("StopControlRequState");
          intern.startControlStoppedTimer();
          console.log("StopControlRequState state entered.")
        }

        SignalTransition{
          targetState: stoppingFinalState
          signal: intern.controlStopped
          guard:{
            if(value===false)
              return false;

            intern.stoppedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: stopErrorState
          signal: pControl.controlStopped
          guard:{
            if(value===true)
              return false;

            intern.stoppedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: stopErrorState
          signal: intern.controlStoppedTimeout
          guard:{
            intern.stoppedRemote(false, "no controlStopped event occured!");
            return true;
          }
        }
      }

      State{
        id: stopErrorState
        onEntered:{
          intern.setCurrentState("StopErrorState");
          console.log("StopErrorState state entered.")
        }
      }

      FinalState{
        id: stoppingFinalState
        onEntered:{
          intern.setCurrentState("StoppingFinalState");
          console.log("StoppingFinalState state entered.")
        }
      }

      SignalTransition{
        targetState: stoppedState
        signal: stoppingState.finished
      }
    }

    State {
      id: stoppedState
      onEntered: {
        intern.setCurrentState("StoppedState");
        stoppedStateFinished();
        console.log("StoppedState entered.");
      }

      SignalTransition
      {
        targetState: resettingState
        signal: intern.remoteReset
        guard:{
          intern.resetControl();
          return true;
        }
      }

      SignalTransition
      {
        targetState: resettingState
        signal: stoppedStateFinished
        guard:{
          if (resetRequest==false)
            return false;

          intern.resetControl();
          return true;
        }
      }
    }

    State {
      id: resettingState
      initialState: resetControlRequState

      onEntered: console.log("resetting state entered.")

      State{
        id: resetControlRequState
        onEntered:{
          intern.setCurrentState("ResetControlRequState");
          intern.startControlResettedTimer();
          console.log("ResetControlRequState state entered.")
        }

        SignalTransition{
          targetState: resettingFinalState
          signal: intern.controlResetted
          guard:{
            if(value===false)
              return false;

            intern.resettedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: resetErrorState
          signal: pControl.controlResetted
          guard:{
            if(value===true)
              return false;

            intern.resettedRemote(value, message);
            return true;
          }
        }

        SignalTransition{
          targetState: resetErrorState
          signal: intern.controlResettedTimeout
          guard:{
            intern.resettedRemote(false, "no controlResetted event occured!");
            return true;
          }
        }
      }

      State{
        id: resetErrorState
        onEntered:{
          intern.setCurrentState("ResetErrorState");
          console.log("ResetErrorState state entered.")
        }SignalTransition{
          targetState: idleState
          signal: workingState.finished
        }
      }

      FinalState{
        id: resettingFinalState
        onEntered:{
          intern.setCurrentState("ResettingFinalState");
          console.log("ResettingFinalState state entered.")
        }
      }

      SignalTransition{
        targetState: workingFinalState
        signal: resettingState.finished
      }
    }

    FinalState{
      id: workingFinalState
      onEntered:{
        intern.setCurrentState("WorkingFinalState");
        console.log("WorkingFinalState state entered.")
      }
    }

    SignalTransition{
      targetState: idleState
      signal: workingState.finished
    }

    SignalTransition{
      targetState: idleState
      signal: intern.controlFinished
      guard:{
        intern.finishedRemote(value,message);
        return true;
      }
    }

    SignalTransition{
      targetState: initState
      signal: intern.remoteRemoteControlClose
      guard: {
        intern.stopControl();
        intern.resetControl();
        intern.controlRemoteControlClose();
        return true;
      }
    }
  }
}
