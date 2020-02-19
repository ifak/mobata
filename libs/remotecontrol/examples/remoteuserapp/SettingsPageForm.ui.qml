import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0

Item {
  id: settingsPageForm
  width: 600
  height: 400
  property alias localPortTextField: localPortTextField
  property alias localIpTextField: localIpTextField
  property alias applyButton: applyButton
  property alias remoteIpTextField: remoteIpTextField
  property alias remotePortTextField: remotePortTextField

  ColumnLayout {
    id: columnLayout
    width: 600
    anchors.fill: parent


    GroupBox {
      id: remoteGroupBox
      width: 200
      height: 200
      padding: 25
      spacing: 5
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
      title: qsTr("remote")

      GridLayout {
        id: remoteGridLayout
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent
        rows: 1
        columns: 2

        Label {
          id: remoteIpLabel
          text: qsTr("Remote IP:")
          font.pointSize: 8
        }

        Label {
          id: remotePortLabel
          text: qsTr("Remote Port:")
          font.pointSize: 8
        }

        TextField {
          id: remoteIpTextField
          text: qsTr("localhost")
          Layout.fillWidth: true
          font.pointSize: 9
        }

        TextField {
          id: remotePortTextField
          width: 80
          text: qsTr("10000")
          Layout.preferredHeight: 40
          Layout.preferredWidth: 80
          font.pointSize: 9
        }
      }
    }
    GroupBox {
      id: localGroupBox
      width: 200
      height: 200
      padding: 25
      spacing: 5
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
      title: qsTr("local")

      GridLayout {
        id: localGridLayout
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent
        rows: 1
        columns: 2

        Label {
          id: localIpLabel
          text: qsTr("Local IP:")
          font.pointSize: 8
        }

        Label {
          id: localPortLabel
          text: qsTr("Local Port:")
          font.pointSize: 8
        }

        TextField {
          id: localIpTextField
          text: "localhost"
          Layout.fillWidth: true
          font.pointSize: 9
        }

        TextField {
          id: localPortTextField
          width: 80
          text: qsTr("10100")
          Layout.preferredHeight: 40
          Layout.preferredWidth: 80
          font.pointSize: 9
        }
      }
    }
    Button {
      id: applyButton
      width: 80
      text: qsTr("Apply")
      Layout.columnSpan: 2
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    }
  }





}
