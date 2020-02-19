import QtQuick 2.12
import QNode 1.0

QmlNode {
    objectName: "node"
    id: node
    z: 0
    skale: {if(parent){parent.skale}else{1}}
    MouseArea{
        anchors.fill: parent
        objectName: "thisMouseArea"
        id: mousearea
        onClicked:{
            nodeClicked(node.uuid)
        }
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: node.repaint()
    }
}
