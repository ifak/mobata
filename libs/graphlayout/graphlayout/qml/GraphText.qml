import QtQuick 2.12
Text{
    objectName: "text"
    property string uuid
    property real textSize:12
    property string textFamiliy: "serif"
    property color textColor
    property color highlightColor
    property real parentPosX
    property real parentPosY
    property real labelPosX:0
    property real labelPosY:0

    property real skale: {if(parent){parent.skale}else{1}}

    clip: true
    font.pixelSize: textSize
    font.family: textFamiliy
    color: textColor
    x: (parentPosX - contentWidth/2) * skale
    y: (parentPosY - contentHeight/2) * skale
    z: 2000
    function highlight(ok){
        console.log(ok)
        if(Boolean(ok) == true){
            color = highlightColor;
        }else{
            color = textColor;
        }
    }
    MouseArea{
        objectName: "labelMouseArea"
        anchors.fill: parent
        drag.target: parent
    }
}
