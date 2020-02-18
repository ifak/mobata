import QtQuick 2.12

Rectangle{
    objectName: "msc_message"
    width: 1
    height: 1
    property string label: ""
    property color textcolor: "black"
    property int prefWidth: text.contentWidth
    property int prefHeight: text.contentHeight
    color: "transparent"
    border.color: "transparent"
    Text{
        id:text
        width: parent.width
        height: parent.height
        wrapMode: Text.WordWrap
        text: parent.label;
        color: parent.textcolor
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
}
