import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
  property alias messagesTextEdit: messagesTextEdit
  property alias remoteStatusButton: remoteStatusButton
  property alias openButton: openButton
  ColumnLayout {
    anchors.fill: parent
    spacing: 25

    RowLayout {
      spacing: 50
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

      GroupBox {
        id: remoteSignalsBox
        enabled: true
        Layout.preferredHeight: 301
        Layout.preferredWidth: 259
        title: qsTr("Remote Signals")

        ColumnLayout {
          anchors.fill: parent

          Button {
            id: openButton
            text: qsTr("Open")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
          }

          Button {
            id: setupButton
            text: qsTr("Setup")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
          }


          RowLayout {
            spacing: 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Button {
              id: startButton
              text: qsTr("Start")
            }

            Button {
              id: stopButton
              text: qsTr("Stop")
            }
          }


          Button {
            id: resetButton
            text: qsTr("Reset")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
          }

          Button {
              id: closeButton
              text: qsTr("Close")
              Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
          }

        }
      }

      GroupBox {
        id: remoteStatusBox
        Layout.preferredHeight: 200
        Layout.preferredWidth: 200
        title: qsTr("Remote Status")

        Button {
          id: remoteStatusButton
          text: qsTr("No Status yet ...")
          font.bold: true
          anchors.fill: parent
        }
      }
    }

    GroupBox {
      id: messagesBox
      enabled: true
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
      Layout.preferredHeight: 144
      Layout.preferredWidth: 534
      title: qsTr("Messages")


      RowLayout {
        anchors.fill: parent

        TextEdit {
          id: messagesTextEdit
          text: qsTr("")
          Layout.fillHeight: true
          Layout.fillWidth: true
          readOnly: true
          font.pixelSize: 12
          wrapMode: TextEdit.WordWrap
        }

        ClearMessagesButton {
          id: clearMessagesButton
          highlighted: true
        }
      }
    }
  }

  Connections {
    target: setupButton
    onClicked: app.setup()
  }

  Connections {
    target: app
    onError: messagesTextEdit.append(errorMessage)
  }

  Connections {
    target: startButton
    onClicked: app.start()
  }

  Connections {
    target: stopButton
    onClicked: app.stop()
  }

  Connections {
    target: resetButton
    onClicked: app.reset()
  }

  Connections {
    target: clearMessagesButton
    onClicked: messagesTextEdit.clear()
  }

  Connections {
    target: openButton
    onClicked: app.open()
  }

  Connections {
    target: remoteStatusButton
    onClicked: app.statusRequest()
  }

  Connections {
      target: closeButton
      onClicked: app.close()
  }
}
