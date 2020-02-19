import QtQuick 2.12

Rectangle {
    objectName: "msc_region"
    property string label: ""
    property int prefWidth: text.contentWidth
    property int prefHeight: text.contentHeight
    property color textcolor: "black"
    color: "transparent"
    Text{
        id:text
        width: parent.width
        height: parent.height
        color: parent.textcolor
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: label;
    }
}
