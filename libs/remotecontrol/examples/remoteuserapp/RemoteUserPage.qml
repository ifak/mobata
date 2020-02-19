import QtQuick 2.7

RemoteUserPageForm {
  Connections{
    target: app
    onSetuped:{
      messagesTextEdit.append("setuped message received!")
      if(value)
        remoteStatusButton.text="SetupedState";
      messagesTextEdit.append("value: "+value+" messages: "+messages)
    }
    onStarted:{
      messagesTextEdit.append("started message received!")
      if(value)
        remoteStatusButton.text="RunningState";
      messagesTextEdit.append("value: "+value+" messages: "+messages)
    }
    onStopped:{
      messagesTextEdit.append("stopped message received!")
      if(value)
        remoteStatusButton.text="StoppedState";
      messagesTextEdit.append("value: "+value+" messages: "+messages)
    }
    onResetted:{
      messagesTextEdit.append("resetted message received!")
      if(value)
        remoteStatusButton.text="IdleState";
      messagesTextEdit.append("value: "+value+" messages: "+messages)
    }
    onStatus: {
      messagesTextEdit.append("status message received!")
      remoteStatusButton.text=state;
      messagesTextEdit.append("state: "+state+" messages: "+messages)
    }
  }
}
