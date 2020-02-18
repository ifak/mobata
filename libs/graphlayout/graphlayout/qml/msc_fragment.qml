import QtQuick 2.12

Rectangle {
    objectName: "msc_fragment"
    property string label: ""
    property int prefWidth: text.contentWidth
    property int prefHeight: text.contentHeight
    property color textcolor: "black"
    color: "transparent"
    Text{
        id:text
        width: parent.width
        height: parent.height
        wrapMode: Text.WordWrap
        color: parent.textcolor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: label;
    }
}
