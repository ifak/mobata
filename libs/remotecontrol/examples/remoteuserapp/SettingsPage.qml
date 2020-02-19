import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

SettingsPageForm {
  id: settingsPage

  Connections
  {
    target: localIpTextField
    onPressed:{
      console.log("availableIpPopup executed()!");
      availableIpModel.clear();
      var availableIpAddresses = app.availableIPs();
      for (var index in availableIpAddresses)
        availableIpModel.append({"ipAddress": availableIpAddresses[index]});

      if(ipPopup.currentIndex==-1
          && availableIpModel.count >0)
          ipPopup.currentIndex=0;

      ipPopup.open();
    }
  }

  Connections{
    target: applyButton
    onClicked:{
      var result = app.setRemoteAddress(remoteIpTextField.text);
      if(!result)
      {
        errorMessageDialog.text=("error for setting remote address '"
                                 +remoteIpTextField.text+"'!");
        errorMessageDialog.open();
      }

      result = app.setRemotePort(remotePortTextField.text);
      if(!result)
      {
        errorMessageDialog.text=("error for setting remote port '"
                                 +remotePortTextField.text+"'!");
        errorMessageDialog.open();
      }
      result = app.setLocalAddress(localIpTextField.text);
      if(!result)
      {
        errorMessageDialog.text=("error for setting local address '"
                                 +localIpTextField.text+"'!");
        errorMessageDialog.open();
      }
      result = app.setLocalPort(localPortTextField.text);
      if(!result)
      {
        errorMessageDialog.text=("error for setting local port '"
                                 +localPortTextField.text+"'!");
        errorMessageDialog.open();
      }
    }
  }

  MessageDialog{
    id: errorMessageDialog
    title: "error"
    icon: StandardIcon.Critical
    standardButtons: StandardButton.Ok
  }

  ListModel
  {
    id: availableIpModel

    ListElement { ipAddress: "localhost"}
  }

  Popup{
    id: ipPopup
    width: 2*localIpTextField.width
    height: 1.5*localIpTextField.height
    x: (settingsPage.width - ipPopup.width)/2
    y: (settingsPage.height - ipPopup.height)/2
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    property int currentIndex: -1

    ComboBox{
      id: ipComboBox
      model: availableIpModel
      anchors.fill: parent
      currentIndex: ipPopup.currentIndex
    }

    onOpened: {
      ipComboBox.currentIndex=ipPopup.currentIndex
    }

    onClosed: {
      localIpTextField.text=ipComboBox.currentText
      ipPopup.currentIndex=ipComboBox.currentIndex
    }

    onCurrentIndexChanged: {
      ipComboBox.currentIndex=ipPopup.currentIndex
    }
  }
}
