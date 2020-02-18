import QtQuick 2.12

Rectangle {
    id: timer
    objectName: "msc__timer"
    width: 1
    height: 1
    radius: 20
    property color textcolor: "black"
    property string uuid: ""
    property string label: ""
    property color borderColor: "transparent"

    border.color: timer.borderColor
    border.width: 2

    color: "lightgreen"
    Text{
        id:text
        color: timer.textcolor
        text: timer.label;
        width: timer.width
        height: timer.height
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    property int prefWidth: text.contentWidth * 1.7
    property int prefHeight: text.contentHeight * 1.7
    signal clickedObject(string quuid)
    MouseArea{
        id: mouse
        z:100
        anchors.fill: parent
        objectName: "thisMouseArea"
        onClicked: {
            clickedObject(parent.uuid)
        }
    }
}
