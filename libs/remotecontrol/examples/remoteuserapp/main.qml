import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.VirtualKeyboard 2.1

ApplicationWindow {
  visible: true
  width: 800
  height: 600
  title: qsTr("Remote User App")
  id: root

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex

    RemoteUserPage {
    }

    SettingsPage {
    }
  }

  footer: TabBar {
    id: tabBar
    currentIndex: swipeView.currentIndex
    TabButton {
      text: qsTr("Remote User")
    }
    TabButton {
      text: qsTr("Settings")
    }
  }

  InputPanel {
    id: inputPanel
    z: 99
    x: 0
    y: root.height
    width: root.width
    active: false

    states: State {
      name: "visible"
      when: inputPanel.active
      PropertyChanges {
        target: inputPanel
        y: root.height - inputPanel.height
      }
    }
    transitions: Transition {
      from: ""
      to: "visible"
      reversible: true
      ParallelAnimation {
        NumberAnimation {
          properties: "y"
          duration: 250
          easing.type: Easing.InOutQuad
        }
      }
    }
  }
}
