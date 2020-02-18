import QtQuick 2.12
import QEdge 1.0

QmlEdge{
    id:edge
    objectName: "edge"
    width:2000
    height:2000
    z:4000
    skale: {if(parent){parent.skale}else{1}}
    Text{
        text: label
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignTop
        font.pixelSize: textSize*edge.skale
        font.family: textFamily
        color: textColor
        clip: true
        x:labelPos.x
        y:labelPos.y
        MouseArea{
            anchors.fill: parent
            drag.target: parent
        }
    }
    MouseArea{
        x:0
        y:0
//        width: 10
//        height: 10
        anchors.fill: parent
        objectName: "thisMouseArea"
        id: mousearea
        propagateComposedEvents: true
        onClicked:{
            if(edge.containsPos(mouseX, mouseY) == true){
                edgeClicked(edge.uuid)
                mouse.accepted = true
            }else{
                mouse.accepted = false
            }
        }
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: edge.update()
    }
}
