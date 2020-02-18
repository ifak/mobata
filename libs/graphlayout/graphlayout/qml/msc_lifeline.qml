import QtQuick 2.12
Canvas {
    property var par
    id: lifeline
    objectName: "msc_lifeline"
    property color color
    property string compUuid
    anchors.top: {if(par){par.top}}
    anchors.bottom: {if(par){par.bottom}}
    width: 10
    clip: true
    z: -20
    onPaint: {
        var ctx = getContext("2d")
        ctx.lineWidth=2
        ctx.fillStyle = color
        ctx.strokeStyle = color
        ctx.clearRect(0,0,width, height)
        ctx.beginPath()
        ctx.moveTo(width/2, 10)
        ctx.lineTo(width/2, height)
        ctx.closePath()
        ctx.stroke()
    }
    onParentChanged:{
        par = parent;
    }
    onXChanged: requestPaint();
    function updateX(pos){
        lifeline.x = pos-5;
        height = parent.height;
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: parent.requestPaint()
    }
}
