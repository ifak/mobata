import QtQuick 2.12

Rectangle {
    objectName: "msc__statement"
    width: 1
    height: 1
    radius: 20
    property color textcolor: "black"
    property string uuid: ""
    property string label: ""
    property int prefWidth: text.contentWidth*1.7
    property int prefHeight: text.contentHeight*1.7
    property color borderColor: "transparent"

    border.color: borderColor
    border.width: 2

    color: "lightblue"
    Text{
        id:text
        color: parent.textcolor
        text: label;
        width: parent.width
        height: parent.height
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
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
