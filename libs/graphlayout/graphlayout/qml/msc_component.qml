import QtQuick 2.12

Rectangle {
    objectName: "msc__component"
    id: rect
    property int curve: 10
    property int span: 1
    property int column:-1
    property string label: ""
    property string uuid: ""
    property color textcolor: "black"
    property color compcolor: "yellow"
    property color borderColor: "transparent"
    width: 10
    height: 10
    radius:rect.curve
    color: rect.compcolor
    border.color: rect.borderColor
    border.width: 2
    Text{
        id:text
        color: rect.textcolor
        width: rect.width
        height: rect.height
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: rect.label;
    }
    property int prefWidth: text.contentWidth*1.7
    property int prefHeight: {
        if(text.contentHeight > 6){
            return text.contentHeight * 1.7
        }else{
            return 20
        }
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
